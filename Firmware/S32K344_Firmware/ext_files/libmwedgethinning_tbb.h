/* Copyright 2013-2017 The MathWorks, Inc. */

#ifndef _EDGETHINNING_TBB_H_
#define _EDGETHINNING_TBB_H_


#ifndef LIBMWEDGETHINNING_TBB_API
#    define LIBMWEDGETHINNING_TBB_API
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
EXTERN_C LIBMWEDGETHINNING_TBB_API void edgethinning_real32_tbb(
	const	real32_T	*	pB,
	const	real32_T	*	pBx,
	const	real32_T	*	pBy,
	const	real64_T		kx,
	const	real64_T		ky,
	const 	int8_T 		* 	offset,
	const	real64_T		eps,
	const	real64_T		cutoff,
	       	boolean_T	*	dst,
	const	real64_T	*	dstSize);

/*real64*/
EXTERN_C LIBMWEDGETHINNING_TBB_API void edgethinning_real64_tbb(
	const	real64_T	*	pB,
	const	real64_T	*	pBx,
	const	real64_T	*	pBy,
	const	real64_T		kx,
	const	real64_T		ky,
	const 	int8_T 		* 	offset,
	const	real64_T		eps,
	const	real64_T		cutoff,
       		boolean_T	*	dst,
	const	real64_T	*	dstSize);

#endif
