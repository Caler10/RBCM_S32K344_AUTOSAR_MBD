/* Copyright 2013 The MathWorks, Inc. */

#ifndef _CANNYTHRESHOLDING_TBB_H_
#define _CANNYTHRESHOLDING_TBB_H_


#ifndef LIBMWCANNYTHRESHOLDING_TBB_API
#    define LIBMWCANNYTHRESHOLDING_TBB_API
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

/* 
 * API Description
 * ---------------
 *
 * pDx          -   Pointer to input image filtered by derivative of 
 *                  Gaussian along x.
 * pDy          -   Pointer to input image filtered by derivative of 
 *                  Gaussian along y.
 * pMag         -   Pointer to gradient magnitude image.
 * pSize        -   Pointer to 2 element array containing size of input 
 *                  image. This represents the size of Dx, Dy, Mag and E.
 * lowThresh    -   Low threshold to be used to identify weak edges.
 * pE           -   Pointer to output edge map. All elements in the image 
 *                  buffer are expected to be initialized to 0 (false).
 * 
 */


/*real32*/
EXTERN_C LIBMWCANNYTHRESHOLDING_TBB_API void cannythresholding_real32_tbb(
    const	real32_T	*	pDx,
	const	real32_T	*	pDy,
	const	real32_T	*	pMag,
    const   real64_T    *   pSize,
	const	real64_T		lowThresh,
            boolean_T	*	pE);

/*real64*/
EXTERN_C LIBMWCANNYTHRESHOLDING_TBB_API void cannythresholding_real64_tbb(
    const	real64_T	*	pDx,
	const	real64_T	*	pDy,
	const	real64_T	*	pMag,
    const   real64_T    *   pSize,    
	const	real64_T		lowThresh,
            boolean_T	*	pE);

#endif
