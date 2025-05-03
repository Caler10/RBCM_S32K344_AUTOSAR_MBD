/* Copyright 2013-2017 The MathWorks, Inc. */
#ifndef _IPPGEOTRANS_H_
#define _IPPGEOTRANS_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWIPPGEOTRANS_API
#    define LIBMWIPPGEOTRANS_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWIPPGEOTRANS_API void ippgeotransCaller_real32(real32_T *pDst, real64_T *dstSizeDouble, const real64_T ndims,
                                                     const real32_T *pSrc,  real64_T *srcSize, const real64_T numelSrc,
                                                     const real64_T *tformPtr,  int8_T interpMethodEnum, const real64_T *fillVal,
                                                     const boolean_T isColumnMajor);

EXTERN_C LIBMWIPPGEOTRANS_API void ippgeotransCaller_real64(real64_T *pDst, real64_T *dstSizeDouble, const real64_T ndims,
                                                     const real64_T *pSrc,  real64_T *srcSize, const real64_T numelSrc,
                                                     const real64_T *tformPtr,  int8_T interpMethodEnum, const real64_T *fillVal,
                                                     const boolean_T isColumnMajor);

EXTERN_C LIBMWIPPGEOTRANS_API void ippgeotransCaller_uint8(uint8_T *pDst, real64_T *dstSizeDouble, const real64_T ndims,
                                                     const uint8_T *pSrc,  real64_T *srcSize, const real64_T numelSrc,
                                                     const real64_T *tformPtr,  int8_T interpMethodEnum, const real64_T *fillVal,
                                                     const boolean_T isColumnMajor);

EXTERN_C LIBMWIPPGEOTRANS_API void ippgeotransCaller_uint16(uint16_T *pDst, real64_T *dstSizeDouble, const real64_T ndims,
                                                     const uint16_T *pSrc,  real64_T *srcSize, const real64_T numelSrc,
                                                     const real64_T *tformPtr,  int8_T interpMethodEnum, const real64_T *fillVal,
                                                     const boolean_T isColumnMajor);

#endif /* _IPPGEOTRANS_H_ */
