/* Copyright 2013-2019 The MathWorks, Inc. */

#ifndef _BWDISTEDTFT_TBB_
#define _BWDISTEDTFT_TBB_


#ifndef LIBMWBWDISTEDTFT_TBB_API
#    define LIBMWBWDISTEDTFT_TBB_API
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

/* uint32_T */
EXTERN_C LIBMWBWDISTEDTFT_TBB_API
void bwdistEDTFT32_tbb_boolean(const boolean_T* bw,     /** Pointer to bw image */
                           const real64_T* input_size,  /** Pointer to bw image size */
                           const real64_T num_dims,     /** Number of dimensions in image */
                           real32_T* d,                 /** Output - distance to nearest non-zero pixel */
                           uint32_T* labels);           /** Output - label, feature transform (linear index to nearest non-zero pixel). Pass NULL to skip this computation. */

#endif
