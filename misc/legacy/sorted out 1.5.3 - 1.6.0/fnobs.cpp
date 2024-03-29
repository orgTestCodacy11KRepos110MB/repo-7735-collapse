// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
using namespace Rcpp;

SEXP sym_label = Rf_install("label");

template <int RTYPE>
IntegerVector fnobsCppImpl(Vector<RTYPE> x, int ng, IntegerVector g) {

  int l = x.size();

  if (ng == 0) {
      int n = 0;
      if(RTYPE == REALSXP) {
        for(int i = 0; i != l; ++i) if(x[i] == x[i]) ++n; // This loop is faster
      } else {
        for(int i = 0; i != l; ++i) if(x[i] != Vector<RTYPE>::get_na()) ++n;
      }
     return Rf_ScalarInteger(n);
  } else { // with groups
    if(g.size() != l) stop("length(g) must match nrow(X)");
    IntegerVector n(ng);
      if(RTYPE == REALSXP) {
        for(int i = 0; i != l; ++i) if(x[i] == x[i]) ++n[g[i]-1];
      } else {
        for(int i = 0; i != l; ++i) if(x[i] != Vector<RTYPE>::get_na()) ++n[g[i]-1];
      }
    if(!Rf_isObject(x)) {
      Rf_copyMostAttrib(x, n); // SHALLOW_DUPLICATE_ATTRIB(n, x);
    } else {
      Rf_setAttrib(n, sym_label, Rf_getAttrib(x, sym_label));
    }
    return n;
  }
}

template <>
IntegerVector fnobsCppImpl(Vector<CPLXSXP> x, int ng, IntegerVector) {
  stop("Not supported SEXP type!");
}

template <>
IntegerVector fnobsCppImpl(Vector<VECSXP> x, int ng, IntegerVector) {
  stop("Not supported SEXP type!");
}

template <>
IntegerVector fnobsCppImpl(Vector<RAWSXP> x, int ng, IntegerVector) {
  stop("Not supported SEXP type!");
}

template <>
IntegerVector fnobsCppImpl(Vector<EXPRSXP> x, int ng, IntegerVector) {
  stop("Not supported SEXP type!");
}

// [[Rcpp::export]]
IntegerVector fnobsCpp(const SEXP& x, int ng = 0, const IntegerVector& g = 0){
  RCPP_RETURN_VECTOR(fnobsCppImpl, x, ng, g);
}




template <int RTYPE>
SEXP fnobsmCppImpl(Matrix<RTYPE> x, int ng, IntegerVector g, bool drop) {
  int l = x.nrow(), col = x.ncol();

  if(ng == 0) { // Fastest loops ? Is perhaps an iterator better suited? or a STD algorithm to count ?
    IntegerVector nobs = no_init_vector(col);
    if(RTYPE == REALSXP) {
      for(int j = col; j--; ) { // fastest loop?
        MatrixColumn<RTYPE> column = x( _ , j);
        int ni = 0; // fastest way?
        for(int i = 0; i != l; ++i) if(column[i] == column[i]) ++ni;
        nobs[j] = ni;
      }
    } else {
      for(int j = col; j--; ) {
        MatrixColumn<RTYPE> column = x( _ , j);
        int ni = 0;
        for(int i = 0; i != l; ++i) if(column[i] != Vector<RTYPE>::get_na()) ++ni;
        nobs[j] = ni;
      }
    }
    if(drop) Rf_setAttrib(nobs, R_NamesSymbol, colnames(x));
    else {
      Rf_dimgets(nobs, Dimension(1, col));
      colnames(nobs) = colnames(x);
      if(!Rf_isObject(x)) Rf_copyMostAttrib(x, nobs);
    }
    return nobs;
  } else { // with groups
    if(g.size() != l) stop("length(g) must match nrow(X)");
    IntegerMatrix nobs(ng, col); // init best solution ?
    if(RTYPE == REALSXP) {
      for(int j = col; j--; ) {
        MatrixColumn<RTYPE> column = x( _ , j);
        IntegerMatrix::Column nj = nobs( _ , j);
        for(int i = 0; i != l; ++i) if(column[i] == column[i]) ++nj[g[i]-1];
      }
    } else {
      for(int j = col; j--; ) {
        MatrixColumn<RTYPE> column = x( _ , j);
        IntegerMatrix::Column nj = nobs( _ , j);
        for(int i = 0; i != l; ++i) if(column[i] != Vector<RTYPE>::get_na()) ++nj[g[i]-1];
      }
    }
    colnames(nobs) = colnames(x);
    if(!Rf_isObject(x)) Rf_copyMostAttrib(x, nobs);
    return nobs;
  }
}

template <>
SEXP fnobsmCppImpl(Matrix<CPLXSXP> x, int ng, IntegerVector g, bool drop) {
  stop("Not supported SEXP type!");
}

template <>
SEXP fnobsmCppImpl(Matrix<VECSXP> x, int ng, IntegerVector g, bool drop) {
  stop("Not supported SEXP type!");
}

template <>
SEXP fnobsmCppImpl(Matrix<RAWSXP> x, int ng, IntegerVector g, bool drop) {
  stop("Not supported SEXP type!");
}

template <>
SEXP fnobsmCppImpl(Matrix<EXPRSXP> x, int ng, IntegerVector g, bool drop) {
  stop("Not supported SEXP type!");
}

// [[Rcpp::export]]
SEXP fnobsmCpp(const SEXP& x, int ng = 0, const IntegerVector& g = 0, bool drop = true){
  RCPP_RETURN_MATRIX(fnobsmCppImpl, x, ng, g, drop);
}



// [[Rcpp::export]]
SEXP fnobslCpp(const List& x, int ng = 0, const IntegerVector& g = 0, bool drop = true) {
  int l = x.size();

  if(ng == 0) {
    IntegerVector nobs = no_init_vector(l);
    for(int j = l; j--; ) { // fastest loop ?
      // for(int j = 0; j != l; ++j) { Not sure, could be faster
      int ni = 0;
      switch(TYPEOF(x[j])) { // Faster than using iterator ? // https://gallery.rcpp.org/articles/rcpp-wrap-and-recurse/
      case REALSXP: {
        NumericVector column = x[j];
        int k = column.size();
        for(int i = 0; i != k; ++i) if(!std::isnan(column[i])) ++ni;
        // for(int i = 0; i != column.size(); ++i) if(!std::isnan(column[i])) ++ni; // Note: Column size function called repeatedly is very slow
        break;
      }
      case INTSXP: {
        IntegerVector column = x[j];
        int k = column.size();
        for(int i = 0; i != k; ++i) if(column[i] != NA_INTEGER) ++ni;
        break;
      }
      case STRSXP: {
        CharacterVector column = x[j];
        int k = column.size();
        for(int i = 0; i != k; ++i) if(column[i] != NA_STRING) ++ni;
        break;
      }
      case LGLSXP: {
        LogicalVector column = x[j];
        int k = column.size();
        for(int i = 0; i != k; ++i) if(column[i] != NA_LOGICAL) ++ni;
        break;
      }
      default: {
        stop("incompatible SEXP encountered;");
        break;
      }
      }
      nobs[j] = ni;
    }
    if(drop) {
      Rf_setAttrib(nobs, R_NamesSymbol, Rf_getAttrib(x, R_NamesSymbol));
      return nobs;
    } else {
      List out(l);
      for(int j = l; j--; ) {
        out[j] = nobs[j];
        if(!Rf_isObject(x[j])) {
          SHALLOW_DUPLICATE_ATTRIB(out[j], x[j]);
        } else {
          Rf_setAttrib(out[j], sym_label, Rf_getAttrib(x[j], sym_label));
        }
      }
      DUPLICATE_ATTRIB(out, x);
      Rf_setAttrib(out, R_RowNamesSymbol, Rf_ScalarInteger(1));
      return out;
    }
  } else { // With groups
    int gss = g.size();
    List nobs(l);
    for(int j = l; j--; ) { // fastest loop ?
      IntegerVector ni(ng);
      switch(TYPEOF(x[j])) {
      case REALSXP: {
        NumericVector column = x[j];
        if(column.size() != gss) stop("length(g) must match nrow(X)");
        for(int i = 0; i != gss; ++i) if(!std::isnan(column[i])) ++ni[g[i]-1];
        break;
      }
      case INTSXP: {
        IntegerVector column = x[j];
        if(column.size() != gss) stop("length(g) must match nrow(X)");
        for(int i = 0; i != gss; ++i) if(column[i] != NA_INTEGER) ++ni[g[i]-1];
        break;
      }
      case STRSXP: {
        CharacterVector column = x[j];
        if(column.size() != gss) stop("length(g) must match nrow(X)");
        for(int i = 0; i != gss; ++i) if(column[i] != NA_STRING) ++ni[g[i]-1];
        break;
      }
      case LGLSXP: {
        LogicalVector column = x[j];
        if(column.size() != gss) stop("length(g) must match nrow(X)");
        for(int i = 0; i != gss; ++i) if(column[i] != NA_LOGICAL) ++ni[g[i]-1];
        break;
      }
      default: {
        stop("incompatible SEXP encountered;");
        break;
      }
      }
      if(!Rf_isObject(x[j])) {
        SHALLOW_DUPLICATE_ATTRIB(ni, x[j]);
      } else {
        Rf_setAttrib(ni, sym_label, Rf_getAttrib(x[j], sym_label));
      }
      nobs[j] = ni;
    }
    DUPLICATE_ATTRIB(nobs, x);
    Rf_setAttrib(nobs, R_RowNamesSymbol, IntegerVector::create(NA_INTEGER, -ng));
    return nobs;
  }
}
