/* Copyright 2013 The MathWorks, Inc. */
#ifndef _UINT16TOINT16_H_
#define _UINT16TOINT16_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWUINT16TOINT16_API
#    define LIBMWUINT16TOINT16_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWUINT16TOINT16_API void uint16toint16_uint16(
        const uint16_T    *pr,
        int16_T         *qr,
        const real64_T    numElements);

#endif /* _UINT16TOINT16_H_ */
