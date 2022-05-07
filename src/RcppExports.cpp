// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// BWCpp
NumericVector BWCpp(const NumericVector& x, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, double theta, double set_mean, bool B, bool fill);
RcppExport SEXP _collapse_BWCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP thetaSEXP, SEXP set_meanSEXP, SEXP BSEXP, SEXP fillSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< double >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< double >::type set_mean(set_meanSEXP);
    Rcpp::traits::input_parameter< bool >::type B(BSEXP);
    Rcpp::traits::input_parameter< bool >::type fill(fillSEXP);
    rcpp_result_gen = Rcpp::wrap(BWCpp(x, ng, g, gs, w, narm, theta, set_mean, B, fill));
    return rcpp_result_gen;
END_RCPP
}
// BWmCpp
NumericMatrix BWmCpp(const NumericMatrix& x, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, double theta, double set_mean, bool B, bool fill);
RcppExport SEXP _collapse_BWmCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP thetaSEXP, SEXP set_meanSEXP, SEXP BSEXP, SEXP fillSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< double >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< double >::type set_mean(set_meanSEXP);
    Rcpp::traits::input_parameter< bool >::type B(BSEXP);
    Rcpp::traits::input_parameter< bool >::type fill(fillSEXP);
    rcpp_result_gen = Rcpp::wrap(BWmCpp(x, ng, g, gs, w, narm, theta, set_mean, B, fill));
    return rcpp_result_gen;
END_RCPP
}
// BWlCpp
List BWlCpp(const List& x, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, double theta, double set_mean, bool B, bool fill);
RcppExport SEXP _collapse_BWlCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP thetaSEXP, SEXP set_meanSEXP, SEXP BSEXP, SEXP fillSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< double >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< double >::type set_mean(set_meanSEXP);
    Rcpp::traits::input_parameter< bool >::type B(BSEXP);
    Rcpp::traits::input_parameter< bool >::type fill(fillSEXP);
    rcpp_result_gen = Rcpp::wrap(BWlCpp(x, ng, g, gs, w, narm, theta, set_mean, B, fill));
    return rcpp_result_gen;
END_RCPP
}
// fbstatsCpp
SEXP fbstatsCpp(const NumericVector& x, bool ext, int ng, const IntegerVector& g, int npg, const IntegerVector& pg, const SEXP& w, bool stable_algo, bool array, bool setn, const SEXP& gn);
RcppExport SEXP _collapse_fbstatsCpp(SEXP xSEXP, SEXP extSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP npgSEXP, SEXP pgSEXP, SEXP wSEXP, SEXP stable_algoSEXP, SEXP arraySEXP, SEXP setnSEXP, SEXP gnSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type ext(extSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< int >::type npg(npgSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type pg(pgSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type stable_algo(stable_algoSEXP);
    Rcpp::traits::input_parameter< bool >::type array(arraySEXP);
    Rcpp::traits::input_parameter< bool >::type setn(setnSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gn(gnSEXP);
    rcpp_result_gen = Rcpp::wrap(fbstatsCpp(x, ext, ng, g, npg, pg, w, stable_algo, array, setn, gn));
    return rcpp_result_gen;
END_RCPP
}
// fbstatsmCpp
SEXP fbstatsmCpp(const NumericMatrix& x, bool ext, int ng, const IntegerVector& g, int npg, const IntegerVector& pg, const SEXP& w, bool stable_algo, bool array, const SEXP& gn);
RcppExport SEXP _collapse_fbstatsmCpp(SEXP xSEXP, SEXP extSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP npgSEXP, SEXP pgSEXP, SEXP wSEXP, SEXP stable_algoSEXP, SEXP arraySEXP, SEXP gnSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type ext(extSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< int >::type npg(npgSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type pg(pgSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type stable_algo(stable_algoSEXP);
    Rcpp::traits::input_parameter< bool >::type array(arraySEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gn(gnSEXP);
    rcpp_result_gen = Rcpp::wrap(fbstatsmCpp(x, ext, ng, g, npg, pg, w, stable_algo, array, gn));
    return rcpp_result_gen;
END_RCPP
}
// fbstatslCpp
SEXP fbstatslCpp(const List& x, bool ext, int ng, const IntegerVector& g, int npg, const IntegerVector& pg, const SEXP& w, bool stable_algo, bool array, const SEXP& gn);
RcppExport SEXP _collapse_fbstatslCpp(SEXP xSEXP, SEXP extSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP npgSEXP, SEXP pgSEXP, SEXP wSEXP, SEXP stable_algoSEXP, SEXP arraySEXP, SEXP gnSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type ext(extSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< int >::type npg(npgSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type pg(pgSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type stable_algo(stable_algoSEXP);
    Rcpp::traits::input_parameter< bool >::type array(arraySEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gn(gnSEXP);
    rcpp_result_gen = Rcpp::wrap(fbstatslCpp(x, ext, ng, g, npg, pg, w, stable_algo, array, gn));
    return rcpp_result_gen;
END_RCPP
}
// fdiffgrowthCpp
NumericVector fdiffgrowthCpp(const NumericVector& x, const IntegerVector& n, const IntegerVector& diff, double fill, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& t, int ret, double rho, bool names, double power);
RcppExport SEXP _collapse_fdiffgrowthCpp(SEXP xSEXP, SEXP nSEXP, SEXP diffSEXP, SEXP fillSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP tSEXP, SEXP retSEXP, SEXP rhoSEXP, SEXP namesSEXP, SEXP powerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type diff(diffSEXP);
    Rcpp::traits::input_parameter< double >::type fill(fillSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type t(tSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    Rcpp::traits::input_parameter< double >::type rho(rhoSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    Rcpp::traits::input_parameter< double >::type power(powerSEXP);
    rcpp_result_gen = Rcpp::wrap(fdiffgrowthCpp(x, n, diff, fill, ng, g, gs, t, ret, rho, names, power));
    return rcpp_result_gen;
END_RCPP
}
// fdiffgrowthmCpp
NumericMatrix fdiffgrowthmCpp(const NumericMatrix& x, const IntegerVector& n, const IntegerVector& diff, double fill, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& t, int ret, double rho, bool names, double power);
RcppExport SEXP _collapse_fdiffgrowthmCpp(SEXP xSEXP, SEXP nSEXP, SEXP diffSEXP, SEXP fillSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP tSEXP, SEXP retSEXP, SEXP rhoSEXP, SEXP namesSEXP, SEXP powerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type diff(diffSEXP);
    Rcpp::traits::input_parameter< double >::type fill(fillSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type t(tSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    Rcpp::traits::input_parameter< double >::type rho(rhoSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    Rcpp::traits::input_parameter< double >::type power(powerSEXP);
    rcpp_result_gen = Rcpp::wrap(fdiffgrowthmCpp(x, n, diff, fill, ng, g, gs, t, ret, rho, names, power));
    return rcpp_result_gen;
END_RCPP
}
// fdiffgrowthlCpp
List fdiffgrowthlCpp(const List& x, const IntegerVector& n, const IntegerVector& diff, double fill, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& t, int ret, double rho, bool names, double power);
RcppExport SEXP _collapse_fdiffgrowthlCpp(SEXP xSEXP, SEXP nSEXP, SEXP diffSEXP, SEXP fillSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP tSEXP, SEXP retSEXP, SEXP rhoSEXP, SEXP namesSEXP, SEXP powerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type diff(diffSEXP);
    Rcpp::traits::input_parameter< double >::type fill(fillSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type t(tSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    Rcpp::traits::input_parameter< double >::type rho(rhoSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    Rcpp::traits::input_parameter< double >::type power(powerSEXP);
    rcpp_result_gen = Rcpp::wrap(fdiffgrowthlCpp(x, n, diff, fill, ng, g, gs, t, ret, rho, names, power));
    return rcpp_result_gen;
END_RCPP
}
// flagleadCpp
SEXP flagleadCpp(SEXP x, IntegerVector n, SEXP fill, int ng, IntegerVector g, SEXP t, bool names);
RcppExport SEXP _collapse_flagleadCpp(SEXP xSEXP, SEXP nSEXP, SEXP fillSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP tSEXP, SEXP namesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type n(nSEXP);
    Rcpp::traits::input_parameter< SEXP >::type fill(fillSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type g(gSEXP);
    Rcpp::traits::input_parameter< SEXP >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    rcpp_result_gen = Rcpp::wrap(flagleadCpp(x, n, fill, ng, g, t, names));
    return rcpp_result_gen;
END_RCPP
}
// flagleadmCpp
SEXP flagleadmCpp(SEXP x, IntegerVector n, SEXP fill, int ng, IntegerVector g, SEXP t, bool names);
RcppExport SEXP _collapse_flagleadmCpp(SEXP xSEXP, SEXP nSEXP, SEXP fillSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP tSEXP, SEXP namesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type n(nSEXP);
    Rcpp::traits::input_parameter< SEXP >::type fill(fillSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type g(gSEXP);
    Rcpp::traits::input_parameter< SEXP >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    rcpp_result_gen = Rcpp::wrap(flagleadmCpp(x, n, fill, ng, g, t, names));
    return rcpp_result_gen;
END_RCPP
}
// flagleadlCpp
List flagleadlCpp(const List& x, const IntegerVector& n, const SEXP& fill, int ng, const IntegerVector& g, const SEXP& t, bool names);
RcppExport SEXP _collapse_flagleadlCpp(SEXP xSEXP, SEXP nSEXP, SEXP fillSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP tSEXP, SEXP namesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type n(nSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type fill(fillSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    rcpp_result_gen = Rcpp::wrap(flagleadlCpp(x, n, fill, ng, g, t, names));
    return rcpp_result_gen;
END_RCPP
}
// fnthCpp
NumericVector fnthCpp(const NumericVector& x, double Q, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, int ret, int nthreads);
RcppExport SEXP _collapse_fnthCpp(SEXP xSEXP, SEXP QSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP retSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type Q(QSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(fnthCpp(x, Q, ng, g, gs, w, narm, ret, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// fnthmCpp
SEXP fnthmCpp(const NumericMatrix& x, double Q, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, bool drop, int ret, int nthreads);
RcppExport SEXP _collapse_fnthmCpp(SEXP xSEXP, SEXP QSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP dropSEXP, SEXP retSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type Q(QSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< bool >::type drop(dropSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(fnthmCpp(x, Q, ng, g, gs, w, narm, drop, ret, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// fnthlCpp
SEXP fnthlCpp(const List& x, double Q, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, bool drop, int ret, int nthreads);
RcppExport SEXP _collapse_fnthlCpp(SEXP xSEXP, SEXP QSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP dropSEXP, SEXP retSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type Q(QSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< bool >::type drop(dropSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(fnthlCpp(x, Q, ng, g, gs, w, narm, drop, ret, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// fscaleCpp
NumericVector fscaleCpp(const NumericVector& x, int ng, const IntegerVector& g, const SEXP& w, bool narm, double set_mean, double set_sd);
RcppExport SEXP _collapse_fscaleCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP set_meanSEXP, SEXP set_sdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< double >::type set_mean(set_meanSEXP);
    Rcpp::traits::input_parameter< double >::type set_sd(set_sdSEXP);
    rcpp_result_gen = Rcpp::wrap(fscaleCpp(x, ng, g, w, narm, set_mean, set_sd));
    return rcpp_result_gen;
END_RCPP
}
// fscalemCpp
NumericMatrix fscalemCpp(const NumericMatrix& x, int ng, const IntegerVector& g, const SEXP& w, bool narm, double set_mean, double set_sd);
RcppExport SEXP _collapse_fscalemCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP set_meanSEXP, SEXP set_sdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< double >::type set_mean(set_meanSEXP);
    Rcpp::traits::input_parameter< double >::type set_sd(set_sdSEXP);
    rcpp_result_gen = Rcpp::wrap(fscalemCpp(x, ng, g, w, narm, set_mean, set_sd));
    return rcpp_result_gen;
END_RCPP
}
// fscalelCpp
List fscalelCpp(const List& x, int ng, const IntegerVector& g, const SEXP& w, bool narm, double set_mean, double set_sd);
RcppExport SEXP _collapse_fscalelCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP set_meanSEXP, SEXP set_sdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< double >::type set_mean(set_meanSEXP);
    Rcpp::traits::input_parameter< double >::type set_sd(set_sdSEXP);
    rcpp_result_gen = Rcpp::wrap(fscalelCpp(x, ng, g, w, narm, set_mean, set_sd));
    return rcpp_result_gen;
END_RCPP
}
// fvarsdCpp
NumericVector fvarsdCpp(const NumericVector& x, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, bool stable_algo, bool sd);
RcppExport SEXP _collapse_fvarsdCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP stable_algoSEXP, SEXP sdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< bool >::type stable_algo(stable_algoSEXP);
    Rcpp::traits::input_parameter< bool >::type sd(sdSEXP);
    rcpp_result_gen = Rcpp::wrap(fvarsdCpp(x, ng, g, gs, w, narm, stable_algo, sd));
    return rcpp_result_gen;
END_RCPP
}
// fvarsdmCpp
SEXP fvarsdmCpp(const NumericMatrix& x, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, bool stable_algo, bool sd, bool drop);
RcppExport SEXP _collapse_fvarsdmCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP stable_algoSEXP, SEXP sdSEXP, SEXP dropSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< bool >::type stable_algo(stable_algoSEXP);
    Rcpp::traits::input_parameter< bool >::type sd(sdSEXP);
    Rcpp::traits::input_parameter< bool >::type drop(dropSEXP);
    rcpp_result_gen = Rcpp::wrap(fvarsdmCpp(x, ng, g, gs, w, narm, stable_algo, sd, drop));
    return rcpp_result_gen;
END_RCPP
}
// fvarsdlCpp
SEXP fvarsdlCpp(const List& x, int ng, const IntegerVector& g, const SEXP& gs, const SEXP& w, bool narm, bool stable_algo, bool sd, bool drop);
RcppExport SEXP _collapse_fvarsdlCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP gsSEXP, SEXP wSEXP, SEXP narmSEXP, SEXP stable_algoSEXP, SEXP sdSEXP, SEXP dropSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type gs(gsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type w(wSEXP);
    Rcpp::traits::input_parameter< bool >::type narm(narmSEXP);
    Rcpp::traits::input_parameter< bool >::type stable_algo(stable_algoSEXP);
    Rcpp::traits::input_parameter< bool >::type sd(sdSEXP);
    Rcpp::traits::input_parameter< bool >::type drop(dropSEXP);
    rcpp_result_gen = Rcpp::wrap(fvarsdlCpp(x, ng, g, gs, w, narm, stable_algo, sd, drop));
    return rcpp_result_gen;
END_RCPP
}
// mrtl
SEXP mrtl(const SEXP& X, bool names, int ret);
RcppExport SEXP _collapse_mrtl(SEXP XSEXP, SEXP namesSEXP, SEXP retSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type X(XSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    rcpp_result_gen = Rcpp::wrap(mrtl(X, names, ret));
    return rcpp_result_gen;
END_RCPP
}
// mctl
SEXP mctl(const SEXP& X, bool names, int ret);
RcppExport SEXP _collapse_mctl(SEXP XSEXP, SEXP namesSEXP, SEXP retSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type X(XSEXP);
    Rcpp::traits::input_parameter< bool >::type names(namesSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    rcpp_result_gen = Rcpp::wrap(mctl(X, names, ret));
    return rcpp_result_gen;
END_RCPP
}
// psmatCpp
SEXP psmatCpp(const SEXP& x, const IntegerVector& g, const SEXP& t, bool transpose);
RcppExport SEXP _collapse_psmatCpp(SEXP xSEXP, SEXP gSEXP, SEXP tSEXP, SEXP transposeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type t(tSEXP);
    Rcpp::traits::input_parameter< bool >::type transpose(transposeSEXP);
    rcpp_result_gen = Rcpp::wrap(psmatCpp(x, g, t, transpose));
    return rcpp_result_gen;
END_RCPP
}
// pwnobsmCpp
IntegerMatrix pwnobsmCpp(SEXP x);
RcppExport SEXP _collapse_pwnobsmCpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(pwnobsmCpp(x));
    return rcpp_result_gen;
END_RCPP
}
// qFCpp
SEXP qFCpp(SEXP x, bool ordered, bool na_exclude, bool keep_attr, int ret);
RcppExport SEXP _collapse_qFCpp(SEXP xSEXP, SEXP orderedSEXP, SEXP na_excludeSEXP, SEXP keep_attrSEXP, SEXP retSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type ordered(orderedSEXP);
    Rcpp::traits::input_parameter< bool >::type na_exclude(na_excludeSEXP);
    Rcpp::traits::input_parameter< bool >::type keep_attr(keep_attrSEXP);
    Rcpp::traits::input_parameter< int >::type ret(retSEXP);
    rcpp_result_gen = Rcpp::wrap(qFCpp(x, ordered, na_exclude, keep_attr, ret));
    return rcpp_result_gen;
END_RCPP
}
// funiqueCpp
SEXP funiqueCpp(SEXP x, bool sort);
RcppExport SEXP _collapse_funiqueCpp(SEXP xSEXP, SEXP sortSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type sort(sortSEXP);
    rcpp_result_gen = Rcpp::wrap(funiqueCpp(x, sort));
    return rcpp_result_gen;
END_RCPP
}
// fdroplevelsCpp
IntegerVector fdroplevelsCpp(const IntegerVector& x, bool check_NA);
RcppExport SEXP _collapse_fdroplevelsCpp(SEXP xSEXP, SEXP check_NASEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type check_NA(check_NASEXP);
    rcpp_result_gen = Rcpp::wrap(fdroplevelsCpp(x, check_NA));
    return rcpp_result_gen;
END_RCPP
}
// seqid
IntegerVector seqid(const IntegerVector& x, const SEXP& o, int del, int start, bool na_skip, bool skip_seq, bool check_o);
RcppExport SEXP _collapse_seqid(SEXP xSEXP, SEXP oSEXP, SEXP delSEXP, SEXP startSEXP, SEXP na_skipSEXP, SEXP skip_seqSEXP, SEXP check_oSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type o(oSEXP);
    Rcpp::traits::input_parameter< int >::type del(delSEXP);
    Rcpp::traits::input_parameter< int >::type start(startSEXP);
    Rcpp::traits::input_parameter< bool >::type na_skip(na_skipSEXP);
    Rcpp::traits::input_parameter< bool >::type skip_seq(skip_seqSEXP);
    Rcpp::traits::input_parameter< bool >::type check_o(check_oSEXP);
    rcpp_result_gen = Rcpp::wrap(seqid(x, o, del, start, na_skip, skip_seq, check_o));
    return rcpp_result_gen;
END_RCPP
}
// groupid
IntegerVector groupid(const SEXP& x, const SEXP& o, int start, bool na_skip, bool check_o);
RcppExport SEXP _collapse_groupid(SEXP xSEXP, SEXP oSEXP, SEXP startSEXP, SEXP na_skipSEXP, SEXP check_oSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type o(oSEXP);
    Rcpp::traits::input_parameter< int >::type start(startSEXP);
    Rcpp::traits::input_parameter< bool >::type na_skip(na_skipSEXP);
    Rcpp::traits::input_parameter< bool >::type check_o(check_oSEXP);
    rcpp_result_gen = Rcpp::wrap(groupid(x, o, start, na_skip, check_o));
    return rcpp_result_gen;
END_RCPP
}
// varyingCpp
LogicalVector varyingCpp(const SEXP& x, int ng, const IntegerVector& g, bool any_group);
RcppExport SEXP _collapse_varyingCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP any_groupSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< bool >::type any_group(any_groupSEXP);
    rcpp_result_gen = Rcpp::wrap(varyingCpp(x, ng, g, any_group));
    return rcpp_result_gen;
END_RCPP
}
// varyingmCpp
SEXP varyingmCpp(const SEXP& x, int ng, const IntegerVector& g, bool any_group, bool drop);
RcppExport SEXP _collapse_varyingmCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP any_groupSEXP, SEXP dropSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< bool >::type any_group(any_groupSEXP);
    Rcpp::traits::input_parameter< bool >::type drop(dropSEXP);
    rcpp_result_gen = Rcpp::wrap(varyingmCpp(x, ng, g, any_group, drop));
    return rcpp_result_gen;
END_RCPP
}
// varyinglCpp
SEXP varyinglCpp(const List& x, int ng, const IntegerVector& g, bool any_group, bool drop);
RcppExport SEXP _collapse_varyinglCpp(SEXP xSEXP, SEXP ngSEXP, SEXP gSEXP, SEXP any_groupSEXP, SEXP dropSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type ng(ngSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type g(gSEXP);
    Rcpp::traits::input_parameter< bool >::type any_group(any_groupSEXP);
    Rcpp::traits::input_parameter< bool >::type drop(dropSEXP);
    rcpp_result_gen = Rcpp::wrap(varyinglCpp(x, ng, g, any_group, drop));
    return rcpp_result_gen;
END_RCPP
}
