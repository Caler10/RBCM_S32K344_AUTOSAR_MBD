/* Copyright 2018 The MathWorks, Inc. */

#ifndef _IMTERP2D_
#define _IMTERP2D_


#ifndef LIBMWIMTERP2D_API
#    define LIBMWIMTERP2D_API
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

/*
    real32_T query points
*/

/* boolean */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_boolean(
    const boolean_T*       image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const boolean_T*   extrapValues,
     boolean_T* output);

/* uint8_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_uint8(
    const uint8_T*         image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const uint8_T*   extrapValues,
     uint8_T*   output);

/* int8_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_int8(
    const int8_T*          image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const int8_T*   extrapValues,
     int8_T*    output);

/* uint16_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_uint16(
    const uint16_T*        image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const uint16_T*   extrapValues,
     uint16_T*  output);

/* int16_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_int16(
    const int16_T*         image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const int16_T*   extrapValues,
     int16_T*   output);

/* uint32_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_uint32(
    const uint32_T*        image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const uint32_T*   extrapValues,
     uint32_T*  output);

/* int32_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_int32(
    const int32_T*         image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const int32_T*   extrapValues,
     int32_T*   output);

/* single */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_real32(
    const real32_T*        image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const real32_T*   extrapValues,
     real32_T*  output);

/*  real64_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d32f_real64(
    const real64_T*        image,
    const real64_T*  imSize,
    const real32_T*   Xq,
    const real32_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const real64_T*   extrapValues,
     real64_T*  output);

/*
    real64_T query points
*/

/* boolean */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_boolean(
    const boolean_T*       image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const boolean_T*   extrapValues,
     boolean_T* output);

/* uint8_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_uint8(
    const uint8_T*         image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const uint8_T*   extrapValues,
     uint8_T*   output);

/* int8_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_int8(
    const int8_T*          image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const int8_T*   extrapValues,
     int8_T*    output);

/* uint16_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_uint16(
    const uint16_T*        image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const uint16_T*   extrapValues,
     uint16_T*  output);

/* int16_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_int16(
    const int16_T*         image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const int16_T*   extrapValues,
     int16_T*   output);

/* uint32_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_uint32(
    const uint32_T*        image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const uint32_T*   extrapValues,
     uint32_T*  output);

/* int32_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_int32(
    const int32_T*         image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const int32_T*   extrapValues,
     int32_T*   output);

/* single */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_real32(
    const real32_T*        image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const real32_T*   extrapValues,
     real32_T*  output);

/*  real64_T */
EXTERN_C LIBMWIMTERP2D_API void imterp2d64f_real64(
    const real64_T*        image,
    const real64_T*  imSize,
    const real64_T*   Xq,
    const real64_T*   Yq,
    const real64_T*  outSize,
    const real64_T method,
    const boolean_T  doScalarExtrap,
    const real64_T*   extrapValues,
     real64_T*  output);

#endif
