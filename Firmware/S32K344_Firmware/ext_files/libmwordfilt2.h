/* Copyright 2013 The MathWorks, Inc. */
#ifndef _ORDFILT2_H_
#define _ORDFILT2_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWORDFILT2_API
#    define LIBMWORDFILT2_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWORDFILT2_API void ordfilt2_boolean(const boolean_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                                 const int32_T *offsets, const real64_T numOffsets, 
                                                 const real64_T* const domainSize, const real64_T order, 
                                                 boolean_T* B, const real64_T* const outputSize,
                                                 const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_real64(const real64_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                                const int32_T *offsets, const real64_T numOffsets, 
                                                const real64_T* const domainSize, const real64_T order, 
                                                real64_T* B, const real64_T* const outputSize,
                                                const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_offsets(const real64_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                                 const int32_T *offsets, const real64_T numOffsets, 
                                                 const real64_T* const domainSize, const real64_T order, const real64_T* add,
                                                 real64_T* B, const real64_T* const outputSize);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_real32(const real32_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                                const int32_T *offsets, const real64_T numOffsets, 
                                                const real64_T* const domainSize, const real64_T order, 
                                                real32_T* B, const real64_T* const outputSize,
                                                const boolean_T columnMajor);
      
EXTERN_C LIBMWORDFILT2_API void ordfilt2_int8(const int8_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                              const int32_T *offsets, const real64_T numOffsets, 
                                              const real64_T* const domainSize, const real64_T order, 
                                              int8_T* B, const real64_T* const outputSize,
                                              const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_uint8(const uint8_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                               const int32_T *offsets, const real64_T numOffsets, 
                                               const real64_T* const domainSize, const real64_T order, 
                                               uint8_T* B, const real64_T* const outputSize,
                                               const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_int16(const int16_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                               const int32_T *offsets, const real64_T numOffsets, 
                                               const real64_T* const domainSize, const real64_T order, 
                                               int16_T* B, const real64_T* const outputSize,
                                               const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_uint16(const uint16_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                                const int32_T *offsets, const real64_T numOffsets, 
                                                const real64_T* const domainSize, const real64_T order,  
                                                uint16_T* B, const real64_T* const outputSize,
                                                const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_int32(const int32_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                               const int32_T *offsets, const real64_T numOffsets, 
                                               const real64_T* const domainSize, const real64_T order,  
                                               int32_T* B, const real64_T* const outputSize,
                                               const boolean_T columnMajor);

EXTERN_C LIBMWORDFILT2_API void ordfilt2_uint32(const uint32_T* A, const real64_T Ma, const real64_T* const startIdx, 
                                                const int32_T *offsets, const real64_T numOffsets, 
                                                const real64_T* const domainSize, const real64_T order,  
                                                uint32_T* B, const real64_T* const outputSize,
                                                const boolean_T columnMajor);


#endif /* _ORDFILT2_H_ */
