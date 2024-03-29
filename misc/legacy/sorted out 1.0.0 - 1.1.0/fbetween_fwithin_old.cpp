#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector BWCpp(const NumericVector& x, int ng = 0, const IntegerVector& g = 0,
                    const SEXP& gs = R_NilValue, const SEXP& w = R_NilValue,
                    bool narm = true, bool option = false, bool B = false) {
  int l = x.size();
  NumericVector out = no_init_vector(l);
  
  if (Rf_isNull(w)) { // No weights !!
    if (ng == 0) {
      if(!B && option) stop("For this return option a grouping vector needs to be supplied");
      if(narm) {
        int j = l-1, n = 1; // 1 because for-loop starts from 2
        // long double sum = x[j];
        double sum = x[j];
        while(std::isnan(sum) && j!=0) sum = x[--j];
        if(j != 0) for(int i = j; i--; ) {
          if(std::isnan(x[i])) continue;
          sum += x[i]; // Fastest ??
          ++n;
        }
        sum = sum/n;
        if(B) {
          if(option) std::fill(out.begin(), out.end(), sum); // (double)sum // fastest ?? -> yes !!
          else {
            for(int i = 0; i != l; ++i) {
              if(std::isnan(x[i])) out[i] = x[i];
              else out[i] = sum; // double conversion -> nope, slower !!
            }
          }
        } else {
          out = x - sum; // conversion to double not necessary !!
        }
      } else {
        // long double sum = 0;
        double sum = 0;
        for(int i = 0; i != l; ++i) {
          if(std::isnan(x[i])) {
            sum = x[i];
            break;
          } else {
            sum += x[i];
          }
        }
        sum = sum/l;
        if(B) {
          std::fill(out.begin(), out.end(), sum); // (double)sum) // fastes ??
        } else {
          out = x - sum; // conversion to double not necessary !!
        }
      }
    } else { // with groups
      if(g.size() != l) stop("length(g) must match nrow(X)");
      if(narm) {
        NumericVector sum(ng, NA_REAL); // Other way ??
        IntegerVector n(ng, 1); // could also do no_init_vector and then add n[g[i]-1] = 1 in fir if condition... -> Nope, that is slower !!!
        for(int i = l; i--; ) {
          if(!std::isnan(x[i])) { // faster way to code this ??? -> Not Bad at all -> index for g[i]-1?? -> Nope, no noticeable improvement !!
            if(std::isnan(sum[g[i]-1])) sum[g[i]-1] = x[i];
            else {
              sum[g[i]-1] += x[i];
              ++n[g[i]-1];
            }
          }
        }
        if(B) {
          for(int i = ng; i--; ) sum[i] /= n[i];
          if(option) {
            for(int i = 0; i != l; ++i) out[i] = sum[g[i]-1];
          } else {
            for(int i = 0; i != l; ++i) {
              if(std::isnan(x[i])) out[i] = x[i];
              else out[i] = sum[g[i]-1];
            }
          }
        } else {
          if(!option) {
            for(int i = ng; i--; ) sum[i] /= n[i]; // faster using two loops? or combine ? -> two loos (this solution) is a lot faster !!!!!!!
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1]; // best loop ?? -> just as fast as the other one !!
          } else {
            int on = 0;
            double osum = 0;
            for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
              if(std::isnan(sum[i])) continue; // solves the issue !!
              osum += sum[i];
              on += n[i];
              sum[i] /= n[i]; // fastest ??
            }
            osum = osum/on;
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1] + osum;
          }
        }
      } else {
        NumericVector sum(ng); //  // good?? -> yes, but not initializing is numerically unstable..
        IntegerVector gsv = no_init_vector(ng); // NULL; // gives compile warning !!
        int ngs = 0;
        if(Rf_isNull(gs)) {
          // gsv = IntegerVector(ng);
          std::fill(gsv.begin(), gsv.end(), 0);
          for(int i = 0; i != l; ++i) {
            if(std::isnan(x[i])) {
              if(!std::isnan(sum[g[i]-1])) {
                sum[g[i]-1] = x[i];
                ++ngs;
                if(ngs == ng) break;
              }
            } else {
              sum[g[i]-1] += x[i];
              ++gsv[g[i]-1];
            }
          }
        } else {
          gsv = gs;
          if(gsv.size() != ng) stop("Vector of group-sizes must match number of groups");
          for(int i = 0; i != l; ++i) {
            if(std::isnan(x[i])) {
              if(!std::isnan(sum[g[i]-1])) {
                sum[g[i]-1] = x[i];
                ++ngs;
                if(ngs == ng) break;
              }
            } else {
              sum[g[i]-1] += x[i];
            }
          }
        }
        if(B) {
          for(int i = ng; i--; ) sum[i] /= gsv[i];
          for(int i = 0; i != l; ++i) out[i] = sum[g[i]-1];
        } else {
          if(!option) {
            for(int i = ng; i--; ) sum[i] /= gsv[i];
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1];
          } else {
            int on = 0;
            double osum = 0;
            for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
              if(std::isnan(sum[i])) continue; // solves the issue !!
              osum += sum[i];
              on += gsv[i];
              sum[i] /= gsv[i]; // fastest ??
            }
            osum = osum/on;
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1] + osum;
          }
        }
      }
    }
  } else { // With weights
    NumericVector wg = w; // wg(w) Identical speed
    if(l != wg.size()) stop("length(w) must match length(x)");
    if (ng == 0) {
      if(!B && option) stop("For this return option a grouping vector needs to be supplied");
      if(narm) {
        int j = l-1; // 1 because for-loop starts from 2
        while((std::isnan(x[j]) || std::isnan(wg[j])) && j!=0) --j; // This does not make a difference in performance but is more parsimonious.
        // long double sum = x[j]*wg[j], sumw = wg[j];
        double sum = x[j]*wg[j], sumw = wg[j];
        if(j != 0) for(int i = j; i--; ) {
          if(std::isnan(x[i]) || std::isnan(wg[i])) continue;
          sum += x[i]*wg[i]; // Fastest ??
          sumw += wg[i];
        }
        sum = sum/sumw;
        if(B) {
          if(option) std::fill(out.begin(), out.end(), sum); // (double)sum // fastes ??
          else {
            for(int i = 0; i != l; ++i) {
              if(std::isnan(x[i])) out[i] = x[i];
              else out[i] = sum; // double conversion ??
            }
          }
        } else {
          out = x - sum; // conversion to double not necessary !!
        }
      } else {
        // long double sum = 0, sumw = 0;
        double sum = 0, sumw = 0;
        for(int i = 0; i != l; ++i) {
          if(std::isnan(x[i]) || std::isnan(wg[i])) { // good, check both ?? -> yes!!
            sum = x[i]+wg[i];
            break;
          } else {
            sum += x[i]*wg[i];
            sumw += wg[i];
          }
        }
        sum = sum/sumw;
        if(B) {
          std::fill(out.begin(), out.end(), sum); // (double)sum// fastes ??
        } else {
          out = x - sum; // conversion to double not necessary !!
        }
      }
    } else { // with groups
      if(g.size() != l) stop("length(g) must match nrow(X)");
      if(narm) {
        NumericVector sum(ng, NA_REAL); // Other way ?? -> Nope, this is as good as it gets !!
        NumericVector sumw = no_init_vector(ng); // what if only NA ?? -> Works !! for some reason no problem !!, and faster !!
        for(int i = l; i--; ) {
          if(std::isnan(x[i]) || std::isnan(wg[i])) continue; // faster way to code this ??? -> Not Bad at all -> index for g[i]-1?? -> Nope, no noticeable improvement !!
          if(std::isnan(sum[g[i]-1])) {
            sum[g[i]-1] = x[i]*wg[i];
            sumw[g[i]-1] = wg[i];
          } else {
            sum[g[i]-1] += x[i]*wg[i];
            sumw[g[i]-1] += wg[i];
          }
        }
        if(B) {
          sum = sum/sumw;
          if(option) {
            for(int i = 0; i != l; ++i) out[i] = sum[g[i]-1];
          } else {
            for(int i = 0; i != l; ++i) {
              if(std::isnan(x[i])) out[i] = x[i];
              else out[i] = sum[g[i]-1];
            }
          }
        } else {
          if(!option) {
            sum = sum/sumw;
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1];
          } else {
            double osum = 0, osumw = 0;
            for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
              if(std::isnan(sum[i])) continue; // solves the issue !!
              osum += sum[i];
              osumw += sumw[i];
              sum[i] /= sumw[i]; // fastest ??
            }
            osum = osum/osumw;
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1] + osum;
          }
        }
      } else {
        NumericVector sum(ng); // good?? -> yes !! //  = no_init_vector// Not initializing numerically unstable !!
        NumericVector sumw(ng); // Necessary !!
        int ngs = 0;
        for(int i = 0; i != l; ++i) {
          if(std::isnan(x[i]) || std::isnan(wg[i])) {
            if(!std::isnan(sum[g[i]-1])) {
              sum[g[i]-1] = sumw[g[i]-1] = x[i]+wg[i]; // or NA_REAL ?? -> Nope, good !!
              ++ngs;
              if(ngs == ng) break;
            }
          } else {
            sum[g[i]-1] += x[i]*wg[i];
            sumw[g[i]-1] += wg[i];
          }
        }
        if(B) {
          sum = sum/sumw;
          for(int i = 0; i != l; ++i) out[i] = sum[g[i]-1];
        } else {
          if(!option) {
            sum = sum/sumw;
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1];
          } else {
            double osum = 0, osumw = 0;
            for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
              if(std::isnan(sum[i])) continue; // solves the issue !!
              osum += sum[i];
              osumw += sumw[i];
              sum[i] /= sumw[i]; // fastest ??
            }
            osum = osum/osumw;
            for(int i = 0; i != l; ++i) out[i] = x[i] - sum[g[i]-1] + osum;
          }
        }
      }
    }
  }
  DUPLICATE_ATTRIB(out, x);
  return out;
}



// [[Rcpp::export]]
NumericMatrix BWmCpp(const NumericMatrix& x, int ng = 0, const IntegerVector& g = 0,
                     const SEXP& gs = R_NilValue, const SEXP& w = R_NilValue,
                     bool narm = true, bool option = false, bool B = false) {
  int l = x.nrow(), col = x.ncol();
  NumericMatrix out = no_init_matrix(l, col);
  
  if (Rf_isNull(w)) { // No weights !!
    if(ng == 0) {
      if(!B && option) stop("For this return option a grouping vector needs to be supplied");
      if(narm) {
        for(int j = col; j--; ) { // Instead Am(j,_) you can use Am.row(j).
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          int k = l-1, nj = 1;
          // long double sumj = column[k];
          double sumj = column[k];
          while(std::isnan(sumj) && k!=0) sumj = column[--k];
          if(k != 0) for(int i = k; i--; ) {
            if(std::isnan(column[i])) continue;
            sumj += column[i];
            ++nj;
          }
          sumj = sumj/nj;
          if(B) {
            if(option) std::fill(outj.begin(), outj.end(), sumj); // (double)sumj
            else {
              for(int i = 0; i != l; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumj;
              }
            }
          } else {
            outj = column - sumj;
          }
        }
      } else {
        for(int j = col; j--; ) {
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          // long double sumj = 0;
          double sumj = 0;
          for(int i = 0; i != l; ++i) {
            if(std::isnan(column[i])) {
              sumj = column[i];
              break;
            } else {
              sumj += column[i];
            }
          }
          sumj = sumj/l;
          if(B) {
            std::fill(outj.begin(), outj.end(), sumj); // (double)sumj
          } else {
            outj = column - sumj;
          }
        }
      }
    } else { // with groups
      if(g.size() != l) stop("length(g) must match nrow(X)");
      if(narm) {
        for(int j = col; j--; ) {
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          std::vector<double> sumj(ng, NA_REAL); // faster than NumericVector ??
          std::vector<int> nj(ng);  // int nj[ng]; // use vector also ??
          for(int i = l; i--; ) {
            if(!std::isnan(column[i])) {
              if(std::isnan(sumj[g[i]-1])) {
                sumj[g[i]-1] = column[i];
                nj[g[i]-1] = 1;
              } else {
                sumj[g[i]-1] += column[i];
                ++nj[g[i]-1];
              }
            }
          }
          if(B) {
            for(int i = ng; i--; ) sumj[i] /= nj[i];
            if(option) {
              for(int i = 0; i != l; ++i) outj[i] = sumj[g[i]-1];
            } else {
              for(int i = 0; i != l; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumj[g[i]-1];
              }
            }
          } else {
            if(!option) {
              for(int i = ng; i--; ) sumj[i] /= nj[i];
              for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1];
            } else {
              int on = 0;
              double osum = 0;
              for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                if(std::isnan(sumj[i])) continue; // solves the issue !!
                osum += sumj[i];
                on += nj[i];
                sumj[i] /= nj[i];
              }
              osum = osum/on;
              for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
            }
          }
        }
      } else {
        if(Rf_isNull(gs)) {
          // int gsv[ng], memsize = sizeof(int)*ng;
          for(int j = col; j--; ) {
            NumericMatrix::ConstColumn column = x( _ , j);
            NumericMatrix::Column outj = out( _ , j);
            std::vector<double> sumj(ng); // better than array or NumericVector ??
            std::vector<int> gsv(ng);
            // memset(gsv, 0, memsize);
            int ngs = 0;
            for(int i = 0; i != l; ++i) {
              if(std::isnan(column[i])) {
                if(!std::isnan(sumj[g[i]-1])) {
                  sumj[g[i]-1] = column[i];
                  ++ngs;
                  if(ngs == ng) break;
                }
              } else {
                sumj[g[i]-1] += column[i];
                ++gsv[g[i]-1];
              }
            }
            if(B) {
              for(int i = ng; i--; ) sumj[i] /= gsv[i];
              for(int i = 0; i != l; ++i) outj[i] = sumj[g[i]-1];
            } else {
              if(!option) {
                for(int i = ng; i--; ) sumj[i] /= gsv[i];
                for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1];
              } else {
                int on = 0;
                double osum = 0;
                for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                  if(std::isnan(sumj[i])) continue; // solves the issue !!
                  osum += sumj[i];
                  on += gsv[i];
                  sumj[i] /= gsv[i];
                }
                osum = osum/on;
                for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
              }
            }
          }
        } else {
          IntegerVector gsv = gs;
          if(gsv.size() != ng) stop("Vector of group-sizes must match number of groups");
          for(int j = col; j--; ) {
            NumericMatrix::ConstColumn column = x( _ , j);
            NumericMatrix::Column outj = out( _ , j);
            std::vector<double> sumj(ng);
            int ngs = 0;
            for(int i = 0; i != l; ++i) {
              if(std::isnan(column[i])) {
                if(!std::isnan(sumj[g[i]-1])) {
                  sumj[g[i]-1] = column[i];
                  ++ngs;
                  if(ngs == ng) break;
                }
              } else {
                sumj[g[i]-1] += column[i];
              }
            }
            if(B) {
              for(int i = ng; i--; ) sumj[i] /= gsv[i];
              for(int i = 0; i != l; ++i) outj[i] = sumj[g[i]-1];
            } else {
              if(!option) {
                for(int i = ng; i--; ) sumj[i] /= gsv[i];
                for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1];
              } else {
                int on = 0;
                double osum = 0;
                for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                  if(std::isnan(sumj[i])) continue; // solves the issue !!
                  osum += sumj[i];
                  on += gsv[i];
                  sumj[i] /= gsv[i];
                }
                osum = osum/on;
                for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
              }
            }
          }
        }
      }
    }
  } else { // With weights
    NumericVector wg = w;
    if(l != wg.size()) stop("length(w) must match nrow(X)");
    if(ng == 0) {
      if(!B && option) stop("For this return option a grouping vector needs to be supplied");
      if(narm) {
        for(int j = col; j--; ) { // Instead Am(j,_) you can use Am.row(j).
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          int k = l-1;
          while((std::isnan(column[k]) || std::isnan(wg[k])) && k!=0) --k;
          // long double sumj = column[k]*wg[k], sumwj = wg[k];
          double sumj = column[k]*wg[k], sumwj = wg[k];
          if(k != 0) for(int i = k; i--; ) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) continue;
            sumj += column[i]*wg[i];
            sumwj += wg[i];
          }
          sumj = sumj/sumwj;
          if(B) {
            if(option) std::fill(outj.begin(), outj.end(), sumj); //  (double)sumj
            else {
              for(int i = 0; i != l; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumj;
              }
            }
          } else {
            outj = column - sumj;
          }
        }
      } else {
        for(int j = col; j--; ) {
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          // long double sumj = 0, sumwj = 0;
          double sumj = 0, sumwj = 0;
          for(int i = 0; i != l; ++i) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) {
              sumj = column[i]+wg[i];
              break;
            } else {
              sumj += column[i]*wg[i];
              sumwj += wg[i];
            }
          }
          sumj = sumj/sumwj;
          if(B) {
            std::fill(outj.begin(), outj.end(), sumj); // (double)sumj
          } else {
            outj = column - sumj;
          }
        }
      }
    } else { // with groups
      if(g.size() != l) stop("length(g) must match nrow(X)");
      if(narm) {
        for(int j = col; j--; ) {
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          std::vector<double> sumj(ng, NA_REAL), sumwj(ng); // best ??
          // double sumwj[ng]; // also make std::vector ??
          for(int i = l; i--; ) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) continue;
            if(std::isnan(sumj[g[i]-1])) {
              sumj[g[i]-1] = column[i]*wg[i];
              sumwj[g[i]-1] = wg[i];
            } else {
              sumj[g[i]-1] += column[i]*wg[i];
              sumwj[g[i]-1] += wg[i];
            }
          }
          if(B) {
            for(int i = ng; i--; ) sumj[i] /= sumwj[i];
            if(option) {
              for(int i = 0; i != l; ++i) outj[i] = sumj[g[i]-1];
            } else {
              for(int i = 0; i != l; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumj[g[i]-1];
              }
            }
          } else {
            if(!option) {
              for(int i = ng; i--; ) sumj[i] /= sumwj[i];
              for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1];
            } else {
              double osum = 0, osumw = 0;
              for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                if(std::isnan(sumj[i])) continue; // solves the issue !!
                osum += sumj[i];
                osumw += sumwj[i];
                sumj[i] /= sumwj[i];
              }
              osum = osum/osumw;
              for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
            }
          }
        }
      } else {
        // double sumj[ng], sumwj[ng];
        // int memsize = sizeof(double)*ng;
        for(int j = col; j--; ) {
          NumericMatrix::ConstColumn column = x( _ , j);
          NumericMatrix::Column outj = out( _ , j);
          // memset(sumj, 0, memsize);
          // memset(sumwj, 0, memsize);
          std::vector<double> sumj(ng), sumwj(ng);
          int ngs = 0;
          for(int i = 0; i != l; ++i) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) {
              if(!std::isnan(sumj[g[i]-1])) {
                sumj[g[i]-1] = sumwj[g[i]-1] = column[i]+wg[i]; // or NA_REAL ?? -> Nope, good !!
                ++ngs;
                if(ngs == ng) break;
              }
            } else {
              sumj[g[i]-1] += column[i]*wg[i];
              sumwj[g[i]-1] += wg[i];
            }
          }
          if(B) {
            for(int i = ng; i--; ) sumj[i] /= sumwj[i];
            for(int i = 0; i != l; ++i) outj[i] = sumj[g[i]-1];
          } else {
            if(!option) {
              for(int i = ng; i--; ) sumj[i] /= sumwj[i];
              for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1];
            } else {
              double osum = 0, osumw = 0;
              for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                if(std::isnan(sumj[i])) continue; // solves the issue !!
                osum += sumj[i];
                osumw += sumwj[i];
                sumj[i] /= sumwj[i];
              }
              osum = osum/osumw;
              for(int i = 0; i != l; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
            }
          }
        }
      }
    }
  }
  DUPLICATE_ATTRIB(out, x);
  return out;
}



// [[Rcpp::export]]
List BWlCpp(const List& x, int ng = 0, const IntegerVector& g = 0,
            const SEXP& gs = R_NilValue, const SEXP& w = R_NilValue,
            bool narm = true, bool option = false, bool B = false) {
  
  int l = x.size();
  List out(l);
  
  if (Rf_isNull(w)) { // No weights !!
    if (ng == 0) {
      if(!B && option) stop("For this return option a grouping vector needs to be supplied");
      if(narm) {
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          int row = column.size();
          int k = row-1, ni = 1;
          // long double sumi = column[k];
          double sumi = column[k];
          while(std::isnan(sumi) && k!=0) sumi = column[--k];
          if(k != 0) for(int i = k; i--; ) {
            if(std::isnan(column[i])) continue;
            sumi += column[i];
            ++ni;
          }
          sumi = sumi/ni;
          if(B) {
            if(option) out[j] = rep(sumi, row); // rep((double)sumi, row); // good ??
            else {
              NumericVector outj = no_init_vector(row);
              for(int i = 0; i != row; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumi;
              }
              out[j] = outj;
            }
          } else {
            out[j] = column - sumi;
          }
          SHALLOW_DUPLICATE_ATTRIB(out[j], column); // good ??
        }
      } else {
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          // long double sumi = 0;
          double sumi = 0;
          int row = column.size();
          for(int i = 0; i != row; ++i) {
            if(std::isnan(column[i])) {
              sumi = column[i];
              break;
            } else {
              sumi += column[i];
            }
          }
          sumi = sumi/row;
          if(B) {
            out[j] = rep(sumi, row); // rep((double)sumi, row);
          } else {
            out[j] = column - sumi;
          }
          SHALLOW_DUPLICATE_ATTRIB(out[j], column);
        }
      }
    } else { // With groups !!
      int gss = g.size();
      if(narm) {
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          int row = column.size();
          if(gss != row) stop("length(g) must match nrow(X)");
          std::vector<double> sumj(ng, NA_REAL);
          std::vector<int>  nj(ng, 1);
          for(int i = row; i--; ) {
            if(!std::isnan(column[i])) {
              if(std::isnan(sumj[g[i]-1])) sumj[g[i]-1] = column[i];
              else {
                sumj[g[i]-1] += column[i];
                ++nj[g[i]-1];
              }
            }
          }
          NumericVector outj = no_init_vector(row);
          if(B) {
            for(int i = ng; i--; ) sumj[i] /= nj[i];
            if(option) {
              for(int i = 0; i != row; ++i) outj[i] = sumj[g[i]-1];
            } else {
              for(int i = 0; i != row; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumj[g[i]-1];
              }
            }
          } else {
            if(!option) {
              for(int i = ng; i--; ) sumj[i] /= nj[i];
              for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1];
            } else {
              int on = 0;
              double osum = 0;
              for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                if(std::isnan(sumj[i])) continue; // solves the issue !!
                osum += sumj[i];
                on += nj[i];
                sumj[i] /= nj[i];
              }
              osum = osum/on;
              for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
            }
          }
          SHALLOW_DUPLICATE_ATTRIB(outj, column);
          out[j] = outj;
        }
      } else {
        if(Rf_isNull(gs)) {
          // int gsv[ng], memsize = sizeof(int)*ng;
          for(int j = l; j--; ) {
            NumericVector column = x[j];
            int row = column.size();
            if(gss != row) stop("length(g) must match nrow(X)");
            std::vector<double> sumj(ng);
            // memset(gsv, 0, memsize);
            std::vector<int> gsv(ng);
            int ngs = 0;
            for(int i = 0; i != row; ++i) {
              if(std::isnan(column[i])) {
                if(!std::isnan(sumj[g[i]-1])) {
                  sumj[g[i]-1] = column[i];
                  ++ngs;
                  if(ngs == ng) break;
                }
              } else {
                sumj[g[i]-1] += column[i];
                ++gsv[g[i]-1];
              }
            }
            NumericVector outj = no_init_vector(row);
            if(B) {
              for(int i = ng; i--; ) sumj[i] /= gsv[i];
              for(int i = 0; i != row; ++i) outj[i] = sumj[g[i]-1];
            } else {
              if(!option) {
                for(int i = ng; i--; ) sumj[i] /= gsv[i];
                for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1];
              } else {
                int on = 0;
                double osum = 0;
                for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                  if(std::isnan(sumj[i])) continue; // solves the issue !!
                  osum += sumj[i];
                  on += gsv[i];
                  sumj[i] /= gsv[i];
                }
                osum = osum/on;
                for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
              }
            }
            SHALLOW_DUPLICATE_ATTRIB(outj, column);
            out[j] = outj;
          }
        } else {
          IntegerVector gsv = gs;
          if(gsv.size() != ng) stop("Vector of group-sizes must match number of groups");
          for(int j = l; j--; ) {
            NumericVector column = x[j];
            int row = column.size();
            if(gss != row) stop("length(g) must match nrow(X)");
            NumericVector sumj(ng); //  = no_init_vector //  Not initializing seems to be numerically unstable !!!!
            int ngs = 0;
            for(int i = 0; i != row; ++i) {
              if(std::isnan(column[i])) {
                if(!std::isnan(sumj[g[i]-1])) {
                  sumj[g[i]-1] = column[i];
                  ++ngs;
                  if(ngs == ng) break;
                }
              } else {
                sumj[g[i]-1] += column[i];
              }
            }
            NumericVector outj = no_init_vector(row);
            if(B) {
              for(int i = ng; i--; ) sumj[i] /= gsv[i];
              for(int i = 0; i != row; ++i) outj[i] = sumj[g[i]-1];
            } else {
              if(!option) {
                for(int i = ng; i--; ) sumj[i] /= gsv[i];
                for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1];
              } else {
                int on = 0;
                double osum = 0;
                for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                  if(std::isnan(sumj[i])) continue; // solves the issue !!
                  osum += sumj[i];
                  on += gsv[i];
                  sumj[i] /= gsv[i];
                }
                osum = osum/on;
                for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
              }
            }
            SHALLOW_DUPLICATE_ATTRIB(outj, column);
            out[j] = outj;
          }
        }
      }
    }
  } else { // With weights
    NumericVector wg = w;
    int wgs = wg.size();
    if (ng == 0) {
      if(narm) {
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          int row = column.size();
          if(row != wgs) stop("length(w) must match nrow(X)");
          int k = row-1;
          while((std::isnan(column[k]) || std::isnan(wg[k])) && k!=0) --k;
          // long double sumi = column[k]*wg[k], sumwi = wg[k];
          double sumi = column[k]*wg[k], sumwi = wg[k];
          if(k != 0) for(int i = k; i--; ) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) continue;
            sumi += column[i]*wg[i];
            sumwi += wg[i];
          }
          sumi = sumi/sumwi;
          if(B) {
            if(option) out[j] = rep(sumi, row); // rep((double)sumi, row);
            else {
              NumericVector outj = no_init_vector(row);
              for(int i = 0; i != row; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumi;
              }
              out[j] = outj;
            }
          } else {
            out[j] = column - sumi;
          }
          SHALLOW_DUPLICATE_ATTRIB(out[j], column); // good like this ??
        }
      } else {
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          int row = column.size();
          if(row != wgs) stop("length(w) must match nrow(X)");
          // long double sumi = 0, sumwi = 0;
          double sumi = 0, sumwi = 0;
          for(int i = 0; i != row; ++i) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) {
              sumi = column[i]+wg[i];
              break;
            } else {
              sumi += column[i]*wg[i];
              sumwi += wg[i];
            }
          }
          sumi = sumi/sumwi;
          if(B) {
            out[j] = rep(sumi, row); // rep((double)sumi, row);
          } else {
            out[j] = column - sumi;
          }
          SHALLOW_DUPLICATE_ATTRIB(out[j], column);
        }
      }
    } else { // With groups !!
      int gss = g.size();
      if(wgs != gss) stop("length(w) must match length(g)");
      if(narm) {
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          int row = column.size();
          if(gss != row) stop("length(g) must match nrow(X)");
          std::vector<double> sumj(ng, NA_REAL), sumwj(ng);
          // double sumwj[ng];
          for(int i = row; i--; ) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) continue;
            if(std::isnan(sumj[g[i]-1])) {
              sumj[g[i]-1] = column[i]*wg[i];
              sumwj[g[i]-1] = wg[i];
            } else {
              sumj[g[i]-1] += column[i]*wg[i];
              sumwj[g[i]-1] += wg[i];
            }
          }
          NumericVector outj = no_init_vector(row);
          if(B) {
            for(int i = ng; i--; ) sumj[i] /= sumwj[i];
            if(option) {
              for(int i = 0; i != row; ++i) outj[i] = sumj[g[i]-1];
            } else {
              for(int i = 0; i != row; ++i) {
                if(std::isnan(column[i])) outj[i] = column[i];
                else outj[i] = sumj[g[i]-1];
              }
            }
          } else {
            if(!option) {
              for(int i = ng; i--; ) sumj[i] /= sumwj[i];
              for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1];
            } else {
              double osum = 0, osumw = 0;
              for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                if(std::isnan(sumj[i])) continue; // solves the issue !!
                osum += sumj[i];
                osumw += sumwj[i];
                sumj[i] /= sumwj[i];
              }
              osum = osum/osumw;
              for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
            }
          }
          SHALLOW_DUPLICATE_ATTRIB(outj, column);
          out[j] = outj;
        }
      } else {
        // double sumj[ng], sumwj[ng];
        // int memsize = sizeof(double)*ng;
        for(int j = l; j--; ) {
          NumericVector column = x[j];
          int row = column.size();
          if(gss != row) stop("length(g) must match nrow(X)");
          // memset(sumj, 0, memsize);
          // memset(sumwj, 0, memsize);
          std::vector<double> sumj(ng), sumwj(ng);
          int ngs = 0;
          for(int i = 0; i != row; ++i) {
            if(std::isnan(column[i]) || std::isnan(wg[i])) {
              if(!std::isnan(sumj[g[i]-1])) {
                sumj[g[i]-1] = sumwj[g[i]-1] = column[i]+wg[i]; // or NA_REAL ?? -> Nope, good !!
                ++ngs;
                if(ngs == ng) break;
              }
            } else {
              sumj[g[i]-1] += column[i]*wg[i];
              sumwj[g[i]-1] += wg[i];
            }
          }
          NumericVector outj = no_init_vector(row);
          if(B) {
            for(int i = ng; i--; ) sumj[i] /= sumwj[i];
            for(int i = 0; i != row; ++i) outj[i] = sumj[g[i]-1];
          } else {
            if(!option) {
              for(int i = ng; i--; ) sumj[i] /= sumwj[i];
              for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1];
            } else {
              double osum = 0, osumw = 0;
              for(int i = ng; i--; ) { // Problem: if one sum remained NA, osum becomes NA !!!
                if(std::isnan(sumj[i])) continue; // solves the issue !!
                osum += sumj[i];
                osumw += sumwj[i];
                sumj[i] /= sumwj[i];
              }
              osum = osum/osumw;
              for(int i = 0; i != row; ++i) outj[i] = column[i] - sumj[g[i]-1] + osum;
            }
          }
          SHALLOW_DUPLICATE_ATTRIB(outj, column);
          out[j] = outj;
        }
      }
    }
  }
  DUPLICATE_ATTRIB(out, x);
  return out;
}
