/* Copyright 2012-2013 The MathWorks, Inc. */
#ifndef _LIBMWIMREGIONALMAX_H_
#define _LIBMWIMREGIONALMAX_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWIMREGIONALMAX_API
#    define LIBMWIMREGIONALMAX_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

/*boolean_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_boolean(
        const boolean_T* F,
        boolean_T* BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*uint8_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_uint8(
        const uint8_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*int8_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_int8(
        const int8_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*uint16_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_uint16(
        const uint16_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*int16_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_int16(
        const int16_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*uint32_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_uint32(
        const uint32_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*int32_T*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_int32(
        const int32_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*single*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_real32(
        const real32_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

/*double*/
EXTERN_C LIBMWIMREGIONALMAX_API void imregionalmax_real64(
        const real64_T* F,
        boolean_T*   BW,
        const real64_T nimdims,
        const real64_T *imSize,
        const boolean_T* conn,
        const real64_T nconndims,
        const real64_T *connSize);

#endif /* _LIBMWIMREGIONALMAX_H_ */
