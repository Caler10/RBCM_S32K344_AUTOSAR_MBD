/* Copyright 2013 The MathWorks, Inc. */
#ifndef _INT32TOUINT32_H_
#define _INT32TOUINT32_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWINT32TOUINT32_API
#    define LIBMWINT32TOUINT32_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWINT32TOUINT32_API void int32touint32_fun(
        const int32_T    *pr,
        uint32_T         *qr,
        const real64_T    numElements);

#endif /* _INT32TOUINT32_H_ */
