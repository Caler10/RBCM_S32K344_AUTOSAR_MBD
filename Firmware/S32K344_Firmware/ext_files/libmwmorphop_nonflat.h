/* Copyright 2013 The MathWorks, inc. */
#ifndef _MORPHOP_NONFLAT_H_
#define _MORPHOP_NONFLAT_H_

#ifndef LIBMWMORPHOP_NONFLAT_API
#    define LIBMWMORPHOP_NONFLAT_API
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


/* boolean_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_boolean(const boolean_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        boolean_T* out);

/* uint8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_uint8(const uint8_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        uint8_T* out);

/* uint16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_uint16(const uint16_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        uint16_T* out);

/* uint32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_uint32(const uint32_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        uint32_T* out);

/* int8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_int8(const int8_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        int8_T* out);

/* int16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_int16(const int16_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        int16_T* out);

/* int32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_int32(const int32_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        int32_T* out);

/* real32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_real32(const real32_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        real32_T* out);

/* real64_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void dilate_nonflat_real64(const real64_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        real64_T* out);



/* boolean_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_boolean(const boolean_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        boolean_T* out);

/* uint8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_uint8(const uint8_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        uint8_T* out);

/* uint16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_uint16(const uint16_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        uint16_T* out);

/* uint32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_uint32(const uint32_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        uint32_T* out);

/* int8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_int8(const int8_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        int8_T* out);

/* int16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_int16(const int16_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        int16_T* out);

/* int32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_int32(const int32_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        int32_T* out);

/* real32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_real32(const real32_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        real32_T* out);

/* real64_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_API
void erode_nonflat_real64(const real64_T* const in, const real64_T* inDims, const real64_T inNumDims,
                        const boolean_T* nhood, const real64_T* nhoodDims, const real64_T nhoodNumDims,
                        const real64_T* heights,
                        real64_T* out);

#endif
