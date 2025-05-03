/* Copyright 2013 The MathWorks, inc. */
#ifndef _LIBMWMORPHOP_FLAT_TBB_HPP_
#define _LIBMWMORPHOP_FLAT_TBB_HPP_

#ifndef LIBMWMORPHOP_FLAT_TBB_API
#    define LIBMWMORPHOP_FLAT_TBB_API
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

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_boolean_tbb(
                         const boolean_T* const in,
                         const real64_T*    const inDims,
                         const real64_T           inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*    const nhoodDims,
                         const real64_T           nhoodNumDims,
                               boolean_T*       out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_boolean_tbb(
                         const boolean_T* const in,
                         const real64_T*    const inDims,
                         const real64_T           inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*    const nhoodDims,
                         const real64_T           nhoodNumDims,
                         boolean_T*       out);


/* uint8_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_uint8_tbb(
                         const uint8_T*   const in,
                         const real64_T*    const inDims,
                         const real64_T           inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*    const nhoodDims,
                         const real64_T           nhoodNumDims,
                         uint8_T*         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_uint8_tbb(
                         const uint8_T*   const in,
                         const real64_T*    const inDims,
                         const real64_T           inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*    const nhoodDims,
                         const real64_T           nhoodNumDims,
                         uint8_T*         out);


/* uint16_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_uint16_tbb(
                         const uint16_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               uint16_T*         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_uint16_tbb(
                         const uint16_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               uint16_T*         out);



/* uint32_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_uint32_tbb(
                         const uint32_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               uint32_T*         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_uint32_tbb(
                         const uint32_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               uint32_T*         out);



/* int8_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_int8_tbb(
                         const int8_T*    const in,
                         const real64_T*    const inDims,
                         const real64_T           inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*    const nhoodDims,
                         const real64_T           nhoodNumDims,
                               int8_T*         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_int8_tbb(
                         const int8_T*    const in,
                         const real64_T*    const inDims,
                         const real64_T           inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*    const nhoodDims,
                         const real64_T           nhoodNumDims,
                               int8_T*         out);



/* int16_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_int16_tbb(
                         const int16_T *   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               int16_T *         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_int16_tbb(
                         const int16_T *   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               int16_T *         out);



/* int32_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_int32_tbb(
                         const int32_T *   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               int32_T *         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_int32_tbb(
                         const int32_T *   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               int32_T *         out);



/* real32_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_real32_tbb(
                         const real32_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               real32_T*         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_real32_tbb(
                         const real32_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               real32_T*         out);



/* real64_T */

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void dilate_flat_real64_tbb(
                         const real64_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               real64_T*         out);

EXTERN_C LIBMWMORPHOP_FLAT_TBB_API
void erode_flat_real64_tbb(
                         const real64_T*   const in,
                         const real64_T*     const inDims,
                         const real64_T            inNumDims,
                         const boolean_T*  const nhood,
                         const real64_T*     const nhoodDims,
                         const real64_T            nhoodNumDims,
                               real64_T*         out);




#endif
