

# For foundational changes to this code see fsum.R
# Note: matrix method needs memory equal to size of the object, while data.frame method does not need any memory ?!

fndistinct <- function(x, ...) UseMethod("fndistinct") # , x

fndistinct.default <- function(x, g = NULL, TRA = NULL, na.rm = TRUE, use.g.names = TRUE, nthreads = 1L, ...) {
  if(is.matrix(x) && !inherits(x, "matrix")) return(fndistinct.matrix(x, g, TRA, na.rm, use.g.names, nthreads = nthreads, ...))
  if(is.null(TRA)) {
    if(!missing(...)) unused_arg_action(match.call(), ...)
    if(is.null(g)) return(.Call(Cpp_fndistinct,x,0L,0L,NULL,na.rm,nthreads))
    if(is.atomic(g)) {
      if(use.g.names) {
        if(!is.nmfactor(g)) g <- qF(g, na.exclude = FALSE)
        lev <- attr(g, "levels")
        return(`names<-`(.Call(Cpp_fndistinct,x,length(lev),g,NULL,na.rm,nthreads), lev))
      }
      if(is.nmfactor(g)) return(.Call(Cpp_fndistinct,x,fnlevels(g),g,NULL,na.rm,nthreads))
      g <- qG(g, na.exclude = FALSE)
      return(.Call(Cpp_fndistinct,x,attr(g,"N.groups"),g,NULL,na.rm,nthreads))
    }
    if(!is_GRP(g)) g <- GRP.default(g, return.groups = use.g.names, call = FALSE)
    if(use.g.names) return(`names<-`(.Call(Cpp_fndistinct,x,g[[1L]],g[[2L]],g[[3L]],na.rm,nthreads), GRPnames(g)))
    return(.Call(Cpp_fndistinct,x,g[[1L]],g[[2L]],g[[3L]],na.rm,nthreads))
  }
  if(is.null(g)) return(TRAC(x,.Call(Cpp_fndistinct,x,0L,0L,NULL,na.rm,nthreads),0L,TRA, ...))
  g <- G_guo(g)
  TRAC(x,.Call(Cpp_fndistinct,x,g[[1L]],g[[2L]],g[[3L]],na.rm,nthreads),g[[2L]],TRA, ...)
}

fndistinct.matrix <- function(x, g = NULL, TRA = NULL, na.rm = TRUE, use.g.names = TRUE, drop = TRUE, nthreads = 1L, ...) {
  if(is.null(TRA)) {
    if(!missing(...)) unused_arg_action(match.call(), ...)
    if(is.null(g)) return(.Call(Cpp_fndistinctm,x,0L,0L,NULL,na.rm,drop,nthreads))
    if(is.atomic(g)) {
      if(use.g.names) {
        if(!is.nmfactor(g)) g <- qF(g, na.exclude = FALSE)
        lev <- attr(g, "levels")
        return(`dimnames<-`(.Call(Cpp_fndistinctm,x,length(lev),g,NULL,na.rm,FALSE,nthreads), list(lev, dimnames(x)[[2L]])))
      }
      if(is.nmfactor(g)) return(.Call(Cpp_fndistinctm,x,fnlevels(g),g,NULL,na.rm,FALSE,nthreads))
      g <- qG(g, na.exclude = FALSE)
      return(.Call(Cpp_fndistinctm,x,attr(g,"N.groups"),g,NULL,na.rm,FALSE,nthreads))
    }
    if(!is_GRP(g)) g <- GRP.default(g, return.groups = use.g.names, call = FALSE)
    if(use.g.names) return(`dimnames<-`(.Call(Cpp_fndistinctm,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads), list(GRPnames(g), dimnames(x)[[2L]])))
    return(.Call(Cpp_fndistinctm,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads))
  }
  if(is.null(g)) return(TRAmC(x,.Call(Cpp_fndistinctm,x,0L,0L,NULL,na.rm,TRUE,nthreads),0L,TRA, ...))
  g <- G_guo(g)
  TRAmC(x,.Call(Cpp_fndistinctm,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads),g[[2L]],TRA, ...)
}

fndistinct.data.frame <- function(x, g = NULL, TRA = NULL, na.rm = TRUE, use.g.names = TRUE, drop = TRUE, nthreads = 1L, ...) {
  if(is.null(TRA)) {
    if(!missing(...)) unused_arg_action(match.call(), ...)
    if(is.null(g)) return(.Call(Cpp_fndistinctl,x,0L,0L,NULL,na.rm,drop,nthreads))
    if(is.atomic(g)) {
      if(use.g.names && !inherits(x, "data.table")) {
        if(!is.nmfactor(g)) g <- qF(g, na.exclude = FALSE)
        lev <- attr(g, "levels")
        return(setRnDF(.Call(Cpp_fndistinctl,x,length(lev),g,NULL,na.rm,FALSE,nthreads), lev))
      }
      if(is.nmfactor(g)) return(.Call(Cpp_fndistinctl,x,fnlevels(g),g,NULL,na.rm,FALSE,nthreads))
      g <- qG(g, na.exclude = FALSE)
      return(.Call(Cpp_fndistinctl,x,attr(g,"N.groups"),g,NULL,na.rm,FALSE,nthreads))
    }
    if(!is_GRP(g)) g <- GRP.default(g, return.groups = use.g.names, call = FALSE)
    if(use.g.names && !inherits(x, "data.table") && length(groups <- GRPnames(g)))
      return(setRnDF(.Call(Cpp_fndistinctl,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads), groups))
    return(.Call(Cpp_fndistinctl,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads))
  }
  if(is.null(g)) return(TRAlC(x,.Call(Cpp_fndistinctl,x,0L,0L,NULL,na.rm,TRUE,nthreads),0L,TRA, ...))
  g <- G_guo(g)
  TRAlC(x,.Call(Cpp_fndistinctl,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads),g[[2L]],TRA, ...)
}

fndistinct.list <- function(x, ...) fndistinct.data.frame(x, ...)

fndistinct.grouped_df <- function(x, TRA = NULL, na.rm = TRUE, use.g.names = FALSE, keep.group_vars = TRUE, nthreads = 1L, ...) {
  g <- GRP.grouped_df(x, call = FALSE)
  nam <- attr(x, "names")
  gn <- which(nam %in% g[[5L]])
  nTRAl <- is.null(TRA)
  gl <- length(gn) > 0L
  if(gl || nTRAl) {
    ax <- attributes(x)
    attributes(x) <- NULL
    if(nTRAl) {
      if(!missing(...)) unused_arg_action(match.call(), ...)
      ax[["groups"]] <- NULL
      ax[["class"]] <- fsetdiff(ax[["class"]], c("GRP_df", "grouped_df"))
      ax[["row.names"]] <- if(use.g.names) GRPnames(g) else .set_row_names(g[[1L]])
      if(gl) {
        if(keep.group_vars) {
          ax[["names"]] <- c(g[[5L]], nam[-gn])
          return(setAttributes(c(g[[4L]],.Call(Cpp_fndistinctl,x[-gn],g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads)), ax))
        }
        ax[["names"]] <- nam[-gn]
        return(setAttributes(.Call(Cpp_fndistinctl,x[-gn],g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads), ax))
      } else if(keep.group_vars) {
        ax[["names"]] <- c(g[[5L]], nam)
        return(setAttributes(c(g[[4L]],.Call(Cpp_fndistinctl,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads)), ax))
      } else return(setAttributes(.Call(Cpp_fndistinctl,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads), ax))
    } else if(keep.group_vars) {
      ax[["names"]] <- c(nam[gn], nam[-gn])
      return(setAttributes(c(x[gn],TRAlC(x[-gn],.Call(Cpp_fndistinctl,x[-gn],g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads),g[[2L]],TRA, ...)), ax))
    }
    ax[["names"]] <- nam[-gn]
    return(setAttributes(TRAlC(x[-gn],.Call(Cpp_fndistinctl,x[-gn],g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads),g[[2L]],TRA, ...), ax))
  } else return(TRAlC(x,.Call(Cpp_fndistinctl,x,g[[1L]],g[[2L]],g[[3L]],na.rm,FALSE,nthreads),g[[2L]],TRA, ...))
}


fNdistinct <- function(x, ...) {
  message("Note that 'fNdistinct' was renamed to 'fndistinct'. The S3 generic will not be removed anytime soon, but please use updated function names in new code, see help('collapse-renamed')")
  UseMethod("fndistinct")
}
fNdistinct.default <- function(x, ...) {
  .Deprecated(msg = "This method belongs to a renamed function and will be removed end of 2022, see help('collapse-renamed')")
  fndistinct.default(x, ...)
}
fNdistinct.matrix <- function(x, ...) {
  .Deprecated(msg = "This method belongs to a renamed function and will be removed end of 2022, see help('collapse-renamed')")
  fndistinct.matrix(x, ...)
}
fNdistinct.data.frame <- function(x, ...) {
  .Deprecated(msg = "This method belongs to a renamed function and will be removed end of 2022, see help('collapse-renamed')")
  fndistinct.data.frame(x, ...)
}
