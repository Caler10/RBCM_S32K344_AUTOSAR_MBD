/* Copyright 2013-2019 The MathWorks, Inc. */
#ifndef _LIBMWMORPHOP_IPP_HPP_
#define _LIBMWMORPHOP_IPP_HPP_

#ifndef LIBMWMORPHOP_IPP_API
#    define LIBMWMORPHOP_IPP_API
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


EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_uint8_ipp(const uint8_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      uint8_T* dst);
EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_uint16_ipp(const uint16_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      uint16_T* dst);
EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_int16_ipp(const int16_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      int16_T* dst);
EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_real32_ipp(const real32_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      real32_T* dst);

EXTERN_C LIBMWMORPHOP_IPP_API
void erode_uint8_ipp(const uint8_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      uint8_T* dst);
EXTERN_C LIBMWMORPHOP_IPP_API
void erode_uint16_ipp(const uint16_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      uint16_T* dst);
EXTERN_C LIBMWMORPHOP_IPP_API
void erode_int16_ipp(const int16_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      int16_T* dst);
EXTERN_C LIBMWMORPHOP_IPP_API
void erode_real32_ipp(const real32_T* const src, const real64_T* const inDims,
                      const boolean_T* nhood, const real64_T* const nhoodDims,
                      real32_T* dst);

#endif
