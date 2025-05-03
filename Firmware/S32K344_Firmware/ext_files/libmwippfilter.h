/* Copyright 2013-2017 The MathWorks, Inc. */

#ifndef _LIBMWIPPFILTER_H_
#define _LIBMWIPPFILTER_H_

#ifndef LIBMWIPPFILTER_API
#    define LIBMWIPPFILTER_API
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

typedef enum BorderType {ZeroPad, Replicate, InMemory} BorderType;

EXTERN_C LIBMWIPPFILTER_API void ippfilter_uint8(
        const uint8_T  *inBuf, 
        uint8_T        *outBuf, 
        const real64_T *outSize, 
        real64_T        numPadDims,
        const real64_T *padSize, 
        const real64_T *kernel, 
        const real64_T *kernelSize, 
        boolean_T       convMode);

EXTERN_C LIBMWIPPFILTER_API void ippfilter_uint16(
        const uint16_T *inBuf, 
        uint16_T       *outBuf, 
        const real64_T *outSize, 
        const real64_T  numPadDims, 
        const real64_T *padSize,
        const real64_T *kernel, 
        const real64_T *kernelSize, 
        boolean_T       convMode);

EXTERN_C LIBMWIPPFILTER_API void ippfilter_int16(
        const int16_T  *inBuf, 
        int16_T        *outBuf, 
        const real64_T *outSize, 
        const real64_T  numPadDims, 
        const real64_T *padSize,
        const real64_T *kernel, 
        const real64_T *kernelSize, 
        boolean_T       convMode);

EXTERN_C LIBMWIPPFILTER_API void ippfilter_real32(
        const real32_T *inBuf, 
        real32_T       *outBuf, 
        const real64_T *outSize, 
        const real64_T  numPadDims, 
        const real64_T *padSize,
        const real64_T *kernel, 
        const real64_T *kernelSize, 
        boolean_T       convMode);

EXTERN_C LIBMWIPPFILTER_API void ippfilter_real64(
        const real64_T *inBuf, 
        real64_T       *outBuf, 
        const real64_T *outSize, 
        real64_T        numPadDims, 
        const real64_T *padSize,  
        const real64_T *kernel, 
        const real64_T *kernelSize, 
        boolean_T       convMode);

EXTERN_C LIBMWIPPFILTER_API void ippfilter_bordertype_uint8(
        const uint8_T  *inBuf,
        uint8_T        *outBuf,
        const real64_T *outSize,
        real64_T        numPadDims,
        const real64_T *padSize,
        const real64_T *kernel,
        const real64_T *kernelSize,
        boolean_T       convMode,
        BorderType      borderType);

EXTERN_C LIBMWIPPFILTER_API void ippfilter_bordertype_real32(
        const real32_T *inBuf,
        real32_T       *outBuf,
        const real64_T *outSize,
        real64_T        numPadDims,
        const real64_T *padSize,
        const real64_T *kernel,
        const real64_T *kernelSize,
        boolean_T       convMode,
        BorderType      borderType);



#endif

