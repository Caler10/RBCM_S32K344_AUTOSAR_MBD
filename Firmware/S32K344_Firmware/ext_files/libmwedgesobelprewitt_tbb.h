/* Copyright 2016 The MathWorks, Inc. */

#ifndef _EDGESOBELPREWITT_TBB_H_
#define _EDGESOBELPREWITT_TBB_H_


#ifndef LIBMWEDGESOBELPREWITT_TBB_API
#    define LIBMWEDGESOBELPREWITT_TBB_API
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

/*real32*/
EXTERN_C LIBMWEDGESOBELPREWITT_TBB_API void edgesobelprewitt_real32_tbb(
    const   real32_T          *    pImage,
    const   real64_T          *    srcSize,
    const   boolean_T              isSobel,
    const   real64_T               kx,
    const   real64_T               ky,        
            real32_T          *    pGradientX,
            real32_T          *    pGradientY,
            real32_T          *    pMagnitude);

/*real64*/
EXTERN_C LIBMWEDGESOBELPREWITT_TBB_API void edgesobelprewitt_real64_tbb(
    const   real64_T          *    pImage,
    const   real64_T          *    srcSize,
	const   boolean_T              isSobel,
    const   real64_T               kx,
    const   real64_T               ky,        
            real64_T          *    pGradientX,
            real64_T          *    pGradientY,
            real64_T          *    pMagnitude);
/*bool*/
EXTERN_C LIBMWEDGESOBELPREWITT_TBB_API void edgesobelprewitt_boolean_tbb(
	const   boolean_T         *    pImage,
    const   real64_T          *    srcSize,
	const   boolean_T              isSobel,
    const   real64_T               kx,
    const   real64_T               ky,        
            real32_T          *    pGradientX,
            real32_T          *    pGradientY,
            real32_T          *    pMagnitude);
/*uint8*/
EXTERN_C LIBMWEDGESOBELPREWITT_TBB_API void edgesobelprewitt_uint8_tbb(
    const   uint8_T           *    pImage,
    const   real64_T          *    srcSize,
	const   boolean_T              isSobel,
    const   real64_T               kx,
    const   real64_T               ky,        
            real32_T          *    pGradientX,
            real32_T          *    pGradientY,
            real32_T          *    pMagnitude);
/*uint16*/
EXTERN_C LIBMWEDGESOBELPREWITT_TBB_API void edgesobelprewitt_uint16_tbb(
    const   uint16_T          *    pImage,
    const   real64_T          *    srcSize,
	const   boolean_T              isSobel,
    const   real64_T               kx,
    const   real64_T               ky,        
            real32_T          *    pGradientX,
            real32_T          *    pGradientY,
            real32_T          *    pMagnitude);
/*int16*/
EXTERN_C LIBMWEDGESOBELPREWITT_TBB_API void edgesobelprewitt_int16_tbb(
    const   int16_T           *    pImage,
    const   real64_T          *    srcSize,
	const   boolean_T              isSobel,
    const   real64_T               kx,
    const   real64_T               ky,        
            real32_T          *    pGradientX,
            real32_T          *    pGradientY,
            real32_T          *    pMagnitude);

#endif
