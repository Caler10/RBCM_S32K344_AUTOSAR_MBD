/* Copyright 2013-2014 The MathWorks, Inc. */
#ifndef _GRAYTO8_H_
#define _GRAYTO8_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWGRAYTO8_API
#    define LIBMWGRAYTO8_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWGRAYTO8_API void grayto8_real64(
	const real64_T* inpIm,
	uint8_T* outIm,
	const real64_T numIm);

EXTERN_C LIBMWGRAYTO8_API void grayto8_real32(
	const real32_T* inpIm,
	uint8_T* outIm,
	const real64_T numIm);

EXTERN_C LIBMWGRAYTO8_API void grayto8_uint16(
	const uint16_T* inpIm,
	uint8_T* outIm,
	const real64_T numIm);


#endif /* _GRAYTO8_H_ */
