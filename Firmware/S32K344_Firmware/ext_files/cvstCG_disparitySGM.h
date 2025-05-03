/* This file defines the codegen input parameter structure and entry point
 * function. */
/* Copyright 2018-2019 The MathWorks, Inc. */

#ifndef _DISPARITYSGM_C_API_
#define _DISPARITYSGM_C_API_

#ifndef LIBMWDISPARITYSGM_API
#    define LIBMWDISPARITYSGM_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h" /* mwSize is defined here */
#else
#include "rtwtypes.h"
#endif

#ifndef typedef_cvstDisparitySGMStruct_T
#define typedef_cvstDisparitySGMStruct_T

typedef struct {
    int MinDisparity;
    int NumberOfDisparities;
    int UniquenessThreshold;
    int Directions;
    int Penalty1;
    int Penalty2;
} cvstDisparitySGMStruct_T;


#endif /*typedef_cvstDisparitySGMStruct_T: used by matlab coder*/

EXTERN_C LIBMWDISPARITYSGM_API void disparitySGMCompute(
        uint8_T* inImg1, uint8_T* inImg2, uint32_T *left_CT,
        uint32_T *right_CT, int16_T *MC_img, int16_T *minLr0Buf, int16_T *minLr1Buf, int16_T *Lr0Buf,
        int16_T *Lr1Buf, int16_T *_Lr0Buf, int16_T *Lr4Buf, int16_T *dirCost_sum, int nRows, int nCols,
        float* dis, cvstDisparitySGMStruct_T *params);

#endif
