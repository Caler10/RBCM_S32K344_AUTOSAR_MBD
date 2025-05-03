/* Copyright 2014 The MathWorks, Inc. */
#ifndef _INTLUTTBB_H_
#define _INTLUTTBB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWINTLUTTBB_API
#    define LIBMWINTLUTTBB_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWINTLUTTBB_API void intlut_tbb_uint8(const uint8_T *A, const real64_T *dimsA, const real64_T numDimsA,
                                                  const uint8_T *LUT, const real64_T numLUT, 
                                                  uint8_T *B);

EXTERN_C LIBMWINTLUTTBB_API void intlut_tbb_uint16(const uint16_T *A, const real64_T *dimsA, const real64_T numDimsA,
                                                   const uint16_T *LUT, const real64_T numLUT, 
                                                   uint16_T *B);


EXTERN_C LIBMWINTLUTTBB_API void intlut_tbb_int16(const int16_T *A, const real64_T *dimsA, const real64_T numDimsA,
                                                  const int16_T *LUT, const real64_T numLUT, 
                                                  int16_T *B);


#endif /* _INTLUTTBB_H_ */
