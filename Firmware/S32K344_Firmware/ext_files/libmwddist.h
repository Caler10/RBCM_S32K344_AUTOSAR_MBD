/* Copyright 2013 The MathWorks, Inc. */

#ifndef _DDIST_
#define _DDIST_


#ifndef LIBMWDDIST_API
#    define LIBMWDDIST_API
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
EXTERN_C LIBMWDDIST_API
void ddist32_boolean(const boolean_T* bw,        /** Pointer to bw image */
		     const real64_T* input_size, /** Pointer to bw image size */
		     const real64_T num_dims,    /** Number of dimensions in image */
		     const boolean_T* conn,      /** Pointer to binary connectivity array */
		     const real64_T* conn_size,  /** Pointer to connectivity size */
		     const real64_T conn_dims,   /** connectivity dimensions */
		     const real64_T* inweights,  /** Pointer to weights. Same size as conn */
		     real32_T* d,                /** Output - distance to nearest non-zero pixel */
		     uint32_T* labels);          /** Output - label, feature transform (linear index to nearest non-zero pixel). Pass NULL to skip this computation. */


#endif
