/* Copyright 2014-2015 The MathWorks, Inc. */

#ifndef _LIBMWBOXFILTER3_H_
#define _LIBMWBOXFILTER3_H_


#ifndef LIBMWBOXFILTER3_API
#    define LIBMWBOXFILTER3_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>


/* uint8_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_uint8(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            uint8_T*    outBuf,
      const real64_T*   outDims);

/* int8_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_int8(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            int8_T*     outBuf,
      const real64_T*   outDims);

/* uint16_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_uint16(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            uint16_T*   outBuf,
      const real64_T*   outDims);

/* int16_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_int16(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            int16_T*    outBuf,
      const real64_T*   outDims);

/* uint32_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_uint32(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            uint32_T*   outBuf,
      const real64_T*   outDims);

/* int32_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_int32(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            int32_T*    outBuf,
      const real64_T*   outDims);

/* real32_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_real32(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            real32_T*   outBuf,
      const real64_T*   outDims);

/*  real64_T */
EXTERN_C LIBMWBOXFILTER3_API void boxfilter3_real64(
      const real64_T*   intImageBuf,
      const real64_T*   intImageDims,  
      const real64_T*   kernelDims,
      const real64_T    kernelWeight,
      const real64_T*   pre,
            real64_T*   outBuf,
      const real64_T*   outDims);

#endif
