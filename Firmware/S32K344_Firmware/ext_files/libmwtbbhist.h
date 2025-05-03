/* Copyright 2013-2014 The MathWorks, Inc. */

#ifndef _LIBMWTBBHIST_H_
#define _LIBMWTBBHIST_H_


#ifndef LIBMWTBBHIST_API
#    define LIBMWTBBHIST_API
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

/* uint8_T*/
EXTERN_C LIBMWTBBHIST_API void tbbhist_uint8(
        const uint8_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint8_T scaled*/
EXTERN_C LIBMWTBBHIST_API void tbbhist_uint8_scaled(
        const uint8_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint16_T */
EXTERN_C LIBMWTBBHIST_API void tbbhist_uint16(
        const uint16_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint16_T scaled */
EXTERN_C LIBMWTBBHIST_API void tbbhist_uint16_scaled(
        const uint16_T *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint32_T scaled */
EXTERN_C LIBMWTBBHIST_API void tbbhist_uint32_scaled(
        const uint32_T *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* real32_T */
EXTERN_C LIBMWTBBHIST_API void tbbhist_real32(
        const real32_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* real32_T scaled */
EXTERN_C LIBMWTBBHIST_API void tbbhist_real32_scaled(
        const real32_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/*  real64_T */
EXTERN_C LIBMWTBBHIST_API void tbbhist_real64(
        const real64_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* real64_T scaled */
EXTERN_C LIBMWTBBHIST_API void tbbhist_real64_scaled(
        const real64_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

#endif
