/* Copyright 2012-2014 The MathWorks, Inc. */

#ifndef _IPPRECONSTRUCT_
#define _IPPRECONSTRUCT_

#ifndef LIBMWIPPRECONSTRUCT_API
#    define LIBMWIPPRECONSTRUCT_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWIPPRECONSTRUCT_API void ippreconstruct_uint8(
    uint8_T*        marker,
    const uint8_T*  mask,
    const real64_T* imSize,
    const real64_T  modeFlag);

EXTERN_C LIBMWIPPRECONSTRUCT_API void ippreconstruct_uint16(
    uint16_T*       marker,
    const uint16_T* mask,
    const real64_T* imSize,
    const real64_T  modeFlag);

EXTERN_C LIBMWIPPRECONSTRUCT_API void ippreconstruct_real32(
    real32_T*       marker,
    const real32_T* mask,
    const real64_T* imSize,
    const real64_T  modeFlag);

EXTERN_C LIBMWIPPRECONSTRUCT_API void ippreconstruct_real64(
    real64_T*       marker,
    const real64_T* mask,
    const real64_T* imSize,
    const real64_T  modeFlag);

#endif
