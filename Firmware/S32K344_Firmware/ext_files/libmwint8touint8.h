/* Copyright 2013 The MathWorks, Inc. */
#ifndef _INT8TOUINT8_H_
#define _INT8TOUINT8_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWINT8TOUINT8_API
#    define LIBMWINT8TOUINT8_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWINT8TOUINT8_API void int8touint8_fun(
        const int8_T   *pr,
        uint8_T        *qr,
        const real64_T  numElements);

#endif /* _INT8TOUINT8_H_ */
