/* Copyright 2013 The MathWorks, Inc. */
#ifndef _GRAYTO16_H_
#define _GRAYTO16_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWGRAYTO16_API
#    define LIBMWGRAYTO16_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWGRAYTO16_API void grayto16_double(
	const real64_T* inpIm,
	uint16_T* outIm,
	const real64_T numIm);

EXTERN_C LIBMWGRAYTO16_API void grayto16_single(
	const real32_T* inpIm,
	uint16_T* outIm,
	const real64_T numIm);

EXTERN_C LIBMWGRAYTO16_API void grayto16_uint8(
	const uint8_T* inpIm,
	uint16_T* outIm,
	const real64_T numIm);


#endif /* _GRAYTO16_H_ */
