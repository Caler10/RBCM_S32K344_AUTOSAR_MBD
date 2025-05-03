/* Copyright 2014-2017 The MathWorks, Inc. */

#ifndef _LIBMWBOXFILTER_H_
#define _LIBMWBOXFILTER_H_


#ifndef LIBMWBOXFILTER_API
#    define LIBMWBOXFILTER_API
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


/* uint8_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_uint8(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            uint8_T*    outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/* int8_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_int8(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            int8_T*     outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/* uint16_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_uint16(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            uint16_T*   outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/* int16_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_int16(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            int16_T*    outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/* uint32_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_uint32(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            uint32_T*   outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/* int32_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_int32(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            int32_T*    outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/* real32_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_real32(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            real32_T*   outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

/*  real64_T */
EXTERN_C LIBMWBOXFILTER_API void boxfilter_real64(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            real64_T*   outBuf,
      const real64_T*   outDims,
      const real64_T    nPlanes);

#endif
