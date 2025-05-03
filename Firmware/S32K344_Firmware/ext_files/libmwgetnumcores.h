/* Copyright 2012-2013 The MathWorks, Inc. */
#ifndef _GETNUMCORES_H_
#define _GETNUMCORES_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWGETNUMCORES_API
#    define LIBMWGETNUMCORES_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWGETNUMCORES_API void getnumcores(
        real64_T *proc);

#endif /* _GETNUMCORES_H_ */
