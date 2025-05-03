/* Copyright 2013 The MathWorks, inc. */
#ifndef _MORPHOP_BINARY_H_
#define _MORPHOP_BINARY_H_

#ifndef LIBMWMORPHOP_BINARY_API
#    define LIBMWMORPHOP_BINARY_API
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

EXTERN_C LIBMWMORPHOP_BINARY_API
void dilate_binary(const boolean_T* in,   const real64_T* const inDims,   const real64_T inNumDims,
                   const boolean_T* nhood, const real64_T* const nhoodDims, const real64_T nhoodNumDims,
                         boolean_T* out);

EXTERN_C LIBMWMORPHOP_BINARY_API
void dilate_binary_twod(const boolean_T* const in, const real64_T* const inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* const nhoodDims, const real64_T nhoodNumDims,
                              boolean_T* out);

EXTERN_C LIBMWMORPHOP_BINARY_API
void dilate_binary_ones33(const boolean_T* const in, const real64_T* const inDims, const real64_T inNumDims,
                          const boolean_T* nhood, const real64_T* const nhoodDims, const real64_T nhoodNumDims,
                                boolean_T* out);

EXTERN_C LIBMWMORPHOP_BINARY_API
void erode_binary(const boolean_T* in,   const real64_T* const inDims,   const real64_T inNumDims,
                  const boolean_T* nhood, const real64_T* const nhoodDims, const real64_T nhoodNumDims,
                        boolean_T* out);

EXTERN_C LIBMWMORPHOP_BINARY_API
void erode_binary_twod(const boolean_T* const in, const real64_T* const inDims, const real64_T inNumDims,
                       const boolean_T* nhood, const real64_T* const nhoodDims, const real64_T nhoodNumDims,
                             boolean_T* out);

EXTERN_C LIBMWMORPHOP_BINARY_API
void erode_binary_ones33(const boolean_T* const in, const real64_T* const inDims, const real64_T inNumDims,
                         const boolean_T* nhood, const real64_T* const nhoodDims, const real64_T nhoodNumDims,
                               boolean_T* out);

#endif