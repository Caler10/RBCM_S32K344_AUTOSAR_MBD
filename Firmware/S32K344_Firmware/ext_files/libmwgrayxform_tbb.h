/* Copyright 2014 The MathWorks, Inc. */
#ifndef _GRAYXFORM_TBB_H_
#define _GRAYXFORM_TBB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWGRAYXFORM_TBB_API
#    define LIBMWGRAYXFORM_TBB_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWGRAYXFORM_TBB_API void grayxform_tbb_real64(
        const real64_T *in, 
        const real64_T inNumElems, 
        const real64_T inRows, 
        const real64_T inColsEtc,
        const real64_T *tform, 
        const real64_T tformNumElems,
        real64_T *out);

EXTERN_C LIBMWGRAYXFORM_TBB_API void grayxform_tbb_real32(
        const real32_T *in, 
        const real64_T inNumElems, 
        const real64_T inRows, 
        const real64_T inColsEtc,
        const real64_T *tform, 
        const real64_T tformNumElems,
        real32_T *out);

EXTERN_C LIBMWGRAYXFORM_TBB_API void grayxform_tbb_uint16(
        const uint16_T *in, 
        const real64_T inNumElems, 
        const real64_T inRows, 
        const real64_T inColsEtc,
        const real64_T *tform, 
        const real64_T tformNumElems,
        uint16_T *out);

EXTERN_C LIBMWGRAYXFORM_TBB_API void grayxform_tbb_uint8(
        const uint8_T *in, 
        const real64_T inNumElems, 
        const real64_T inRows, 
        const real64_T inColsEtc,
        const real64_T *tform, 
        const real64_T tformNumElems,
        uint8_T *out);

#endif /* _GRAYXFORM_TBB_H_ */
