/* Copyright 2013 The MathWorks, Inc. */

#ifndef _BWDISTEDT_
#define _BWDISTEDT_


#ifndef LIBMWBWDISTEDT_API
#    define LIBMWBWDISTEDT_API
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

EXTERN_C LIBMWBWDISTEDT_API
void bwdistEDT_boolean(const boolean_T* bw,         /** Pointer to bw image */
		       const real64_T* input_size,  /** Pointer to bw image size */
		       const real64_T num_dims,     /** Number of dimensions in image */
		       real32_T* d);                /** Output - distance to nearest non-zero pixel */


#endif
