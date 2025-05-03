/* Copyright 2013 The MathWorks, Inc. */
#ifndef _BWPACKCTBB_H_
#define _BWPACKCTBB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWBWPACKCTBB_API
#    define LIBMWBWPACKCTBB_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWBWPACKCTBB_API void bwPackingtbb(const boolean_T *BW,
                                               const real64_T *inSize,
                                               uint32_T *outputBuffer,
                                               const real64_T *outSize,
                                               const boolean_T isColumnMajor);

#endif /* _BWPACKCTBB_H_ */
