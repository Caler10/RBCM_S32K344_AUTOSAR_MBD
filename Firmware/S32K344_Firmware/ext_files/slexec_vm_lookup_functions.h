#ifndef SLEXEC_VM_LOOKUP_FUNCTIONS_H
#define SLEXEC_VM_LOOKUP_FUNCTIONS_H
/**
 * @file slexec_vm_lookup_functions.h
 *
 * This header is the exported C interface of the Simulink lookup functions
 * for use in VM applications.
 * 
 */

/* Copyright 2015 The MathWorks, Inc. */

#include "tmwtypes.h"

#ifndef INTERP
# define INTERP(x,x1,x2,y1,y2)         ( (y1)+(((y2) - (y1))/((x2) - (x1)))*((x)-(x1)) )
#endif

#ifndef ZEROTECHNIQUE
#define ZEROTECHNIQUE

typedef enum {
  NORMAL_INTERP,
  AVERAGE_VALUE,
  MIDDLE_VALUE
} ZeroTechnique;

#endif

#ifdef BUILDING_SLEXEC_SIMBRIDGE
 /* being included from inside slexec_simbridge module */
  #include "package.h"
  #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern "C" DLL_EXPORT_SYM
#else
 /* being included from outside, such as raccel code */
  #if defined(__cplusplus)
 /* Needed for non-inlined C++ S-functions */
    #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern "C"
  #else 
    #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern
  #endif
#endif

SLEXEC_SIMBRIDGE_PUBLISHED_C real_T rt_Lookup(
    const real_T *x, int_T xlen, real_T u, const real_T *y);

SLEXEC_SIMBRIDGE_PUBLISHED_C real32_T rt_Lookup32(
    const real32_T *x, int_T xlen, real32_T u, const real32_T *y);

SLEXEC_SIMBRIDGE_PUBLISHED_C real_T rt_Lookup2D_Normal(
    const real_T *xVals, const int_T numX,
    const real_T *yVals, const int_T numY,
    const real_T *zVals,
    const real_T x, const real_T y);

SLEXEC_SIMBRIDGE_PUBLISHED_C real32_T rt_Lookup2D32_Normal(
    const real32_T *xVals, const int_T numX,
    const real32_T *yVals, const int_T numY,
    const real32_T *zVals,
    const real32_T x, const real32_T y);

SLEXEC_SIMBRIDGE_PUBLISHED_C real_T rt_Lookup2D_General(
    const real_T *rowVals, const int_T numRowVals,
    const real_T *colVals, const int_T numColVals,
    const real_T *outputValues,
    const real_T uX, const real_T uY,
    const int_T colZeroIdx,
    const ZeroTechnique colZeroTechnique,
    const real_T *outputAtRowZero);

SLEXEC_SIMBRIDGE_PUBLISHED_C real32_T rt_Lookup2D32_General(
    const real32_T *rowVals, const int_T numRowVals,
    const real32_T *colVals, const int_T numColVals,
    const real32_T *outputValues,
    const real32_T uX, const real32_T uY,
    const int_T colZeroIdx,
    const ZeroTechnique colZeroTechnique,
    const real32_T *outputAtRowZero);

#endif
