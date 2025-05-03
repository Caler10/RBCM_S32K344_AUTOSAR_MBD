/* Copyright 2013 The MathWorks, Inc. */

#ifndef _LIBMWIMFILTER_H_
#define _LIBMWIMFILTER_H_


#ifndef LIBMWIMFILTER_API
#    define LIBMWIMFILTER_API
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
EXTERN_C LIBMWIMFILTER_API void imfilter_boolean(
            const boolean_T *inBuf, 
            boolean_T       *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         nconnDims,
            const real64_T  *connDims,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);



/* uint8_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_uint8(
            const uint8_T   *inBuf, 
            uint8_T         *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/* int8_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_int8(
            const int8_T    *inBuf, 
            int8_T          *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/* uint16_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_uint16(
            const uint16_T  *inBuf, 
            uint16_T        *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/* int16_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_int16(
            const int16_T   *inBuf, 
            int16_T         *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/* uint32_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_uint32(
            const uint32_T  *inBuf, 
            uint32_T        *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/* int32_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_int32(
            const int32_T   *inBuf, 
            int32_T         *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/* real32_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_real32(
            const real32_T  *inBuf, 
            real32_T        *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

/*  real64_T */
EXTERN_C LIBMWIMFILTER_API void imfilter_real64(
            const real64_T  *inBuf, 
            real64_T        *outBuf,
            real64_T         numOutDims,
            const real64_T  *outSize,
            real64_T         numPadDims,
            const real64_T  *padSize,
            const real64_T  *nonZeroKernel,
            real64_T         numKernElem,
            const boolean_T *conn,
            real64_T         numConnDims,
            const real64_T  *connSize,
            const real64_T  *start,
            real64_T         numStartElem,
            boolean_T        sameSize,
            boolean_T        convMode);

#endif
