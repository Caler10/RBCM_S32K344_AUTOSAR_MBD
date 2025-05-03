/* Copyright 2013-2014 The MathWorks, inc. */
#ifndef _BWLOOKUP_TBB_H_
#define _BWLOOKUP_TBB_H_

#ifndef LIBMWBWLOOKUP_TBB_API
#    define LIBMWBWLOOKUP_TBB_API
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
 * inNumDims should be 2
 * lutLength should be 16 or 512
 */

/* boolean_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_boolean(const boolean_T* const in,
        const real64_T*  const inDims,
        const real64_T         inNumDims,
        const boolean_T* const lut,
        const real64_T         lutLength,
        boolean_T*             out);
/* uint8_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_uint8(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const uint8_T* const   lut,
        const real64_T         lutLength,
        uint8_T*             out);
/* uint16_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_uint16(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const uint16_T* const  lut,
        const real64_T         lutLength,
        uint16_T*             out);
/* uint32_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_uint32(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const uint32_T* const  lut,
        const real64_T         lutLength,
        uint32_T*             out);
/* int8_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_int8(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const int8_T* const    lut,
        const real64_T         lutLength,
        int8_T*             out);
/* int16_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_int16(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const int16_T* const   lut,
        const real64_T         lutLength,
        int16_T*             out);
/* int32_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_int32(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const int32_T* const   lut,
        const real64_T         lutLength,
        int32_T*             out);
/* real32_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_real32(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const real32_T* const  lut,
        const real64_T         lutLength,
        real32_T*             out);
/* real64_T */
EXTERN_C LIBMWBWLOOKUP_TBB_API
void bwlookup_tbb_real64(const boolean_T* const in,
        const real64_T* const  inDims,
        const real64_T         inNumDims,
        const real64_T* const  lut,
        const real64_T         lutLength,
        real64_T*             out);

#endif
