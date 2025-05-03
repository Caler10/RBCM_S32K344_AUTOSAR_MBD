/* Copyright 2012 The MathWorks, Inc. */

#ifndef _IMRECONSTRUCT_
#define _IMRECONSTRUCT_


#ifndef LIBMWIMRECONSTRUCT_API
#    define LIBMWIMRECONSTRUCT_API
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

/* boolean */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_boolean(
    boolean_T*       marker,
    const boolean_T* mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* uint8_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_uint8(
    uint8_T*         marker,
    const uint8_T*   mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* int8_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_int8(
    int8_T*          marker,
    const int8_T*    mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* uint16_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_uint16(
    uint16_T*        marker,
    const uint16_T*  mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* int16_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_int16(
    int16_T*         marker,
    const int16_T*   mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* uint32_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_uint32(
    uint32_T*        marker,
    const uint32_T*  mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* int32_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_int32(
    int32_T*         marker,
    const int32_T*   mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/* single */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_real32(
    real32_T*        marker,
    const real32_T*  mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

/*  real64_T */
EXTERN_C LIBMWIMRECONSTRUCT_API void imreconstruct_real64(
    real64_T*        marker,
    const real64_T*  mask,
    const real64_T   nimdims,
    const real64_T*  imSize,
    const boolean_T* conn,
    const real64_T   nconndims,
    const real64_T*  connSize);

#endif
