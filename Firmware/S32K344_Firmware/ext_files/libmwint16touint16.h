/* Copyright 2013 The MathWorks, Inc. */
#ifndef _INT16TOUINT16_H_
#define _INT16TOUINT16_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWINT16TOUINT16_API
#    define LIBMWINT16TOUINT16_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWINT16TOUINT16_API void int16touint16_fun(
        const int16_T    *pr,
        uint16_T         *qr,
        const real64_T    numElements);

#endif /* _INT16TOUINT16_H_ */
