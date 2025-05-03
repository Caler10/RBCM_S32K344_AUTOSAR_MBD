/* Copyright 2013 The MathWorks, inc. */
#ifndef _MORPHOP_NONFLAT_TBB_H_
#define _MORPHOP_NONFLAT_TBB_H_

#ifndef LIBMWMORPHOP_NONFLAT_TBB_API
#    define LIBMWMORPHOP_NONFLAT_TBB_API
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
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_boolean_tbb(const boolean_T* const in,
                                const real64_T*  const inDims,
                                const real64_T         inNumDims,
                                const boolean_T* const nhood,
                                const real64_T*  const nhoodDims,
                                const real64_T         nhoodNumDims,
                                const real64_T*  const heights,
                                      boolean_T*       out);

/* uint8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_uint8_tbb(const uint8_T*   const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    uint8_T*         out);

/* uint16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_uint16_tbb(const uint16_T*  const in,
                               const real64_T*  const inDims,
                               const real64_T         inNumDims,
                               const boolean_T* const nhood,
                               const real64_T*  const nhoodDims,
                               const real64_T         nhoodNumDims,
                               const real64_T*  const heights,
                                     uint16_T*        out);

/* uint32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_uint32_tbb(const uint32_T*  const in,
                               const real64_T*  const inDims,
                               const real64_T         inNumDims,
                               const boolean_T* const nhood,
                               const real64_T*  const nhoodDims,
                               const real64_T         nhoodNumDims,
                               const real64_T*  const heights,
                                     uint32_T*        out);

/* int8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_int8_tbb(const int8_T*    const in,
                             const real64_T*  const inDims,
                             const real64_T         inNumDims,
                             const boolean_T* const nhood,
                             const real64_T*  const nhoodDims,
                             const real64_T         nhoodNumDims,
                             const real64_T*  const heights,
                                   int8_T*          out);

/* int16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_int16_tbb(const int16_T*   const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    int16_T*         out);


/* int32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_int32_tbb(const int32_T*   const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    int32_T*         out);


/* real32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_real32_tbb(const real32_T*  const in,
                               const real64_T*  const inDims,
                               const real64_T         inNumDims,
                               const boolean_T* const nhood,
                               const real64_T*  const nhoodDims,
                               const real64_T         nhoodNumDims,
                               const real64_T*  const heights,
                                     real32_T*        out);


/* real64_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void dilate_nonflat_real64_tbb(const real64_T*  const in,
                               const real64_T*  const inDims,
                               const real64_T         inNumDims,
                               const boolean_T* const nhood,
                               const real64_T*  const nhoodDims,
                               const real64_T         nhoodNumDims,
                               const real64_T*  const heights,
                                     real64_T*        out);




/* boolean_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_boolean_tbb(const boolean_T* const in,
                               const real64_T*  const inDims,
                               const real64_T         inNumDims,
                               const boolean_T* const nhood,
                               const real64_T*  const nhoodDims,
                               const real64_T         nhoodNumDims,
                               const real64_T*  const heights,
                                     boolean_T*       out);

/* uint8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_uint8_tbb(const uint8_T*   const in,
                             const real64_T*  const inDims,
                             const real64_T         inNumDims,
                             const boolean_T* const nhood,
                             const real64_T*  const nhoodDims,
                             const real64_T         nhoodNumDims,
                             const real64_T*  const heights,
                                   uint8_T*         out);

/* uint16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_uint16_tbb(const uint16_T*  const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    uint16_T*        out);

/* uint32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_uint32_tbb(const uint32_T*  const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    uint32_T*        out);

/* int8_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_int8_tbb(const int8_T*    const in,
                            const real64_T*  const inDims,
                            const real64_T         inNumDims,
                            const boolean_T* const nhood,
                            const real64_T*  const nhoodDims,
                            const real64_T         nhoodNumDims,
                            const real64_T*  const heights,
                                  int8_T*          out);

/* int16_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_int16_tbb(const int16_T*   const in,
                             const real64_T*  const inDims,
                             const real64_T         inNumDims,
                             const boolean_T* const nhood,
                             const real64_T*  const nhoodDims,
                             const real64_T         nhoodNumDims,
                             const real64_T*  const heights,
                                   int16_T*         out);


/* int32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_int32_tbb(const int32_T*   const in,
                             const real64_T*  const inDims,
                             const real64_T         inNumDims,
                             const boolean_T* const nhood,
                             const real64_T*  const nhoodDims,
                             const real64_T         nhoodNumDims,
                             const real64_T*  const heights,
                                   int32_T*         out);


/* real32_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_real32_tbb(const real32_T*  const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    real32_T*        out);


/* real64_T */
EXTERN_C LIBMWMORPHOP_NONFLAT_TBB_API
void erode_nonflat_real64_tbb(const real64_T*  const in,
                              const real64_T*  const inDims,
                              const real64_T         inNumDims,
                              const boolean_T* const nhood,
                              const real64_T*  const nhoodDims,
                              const real64_T         nhoodNumDims,
                              const real64_T*  const heights,
                                    real64_T*        out);
#endif
