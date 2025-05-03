/* Copyright 2013 The MathWorks, Inc. */
#ifndef _IMLINCOMB_TBB_H_
#define _IMLINCOMB_TBB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWIMLINCOMB_TBB_API
#    define LIBMWIMLINCOMB_TBB_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_real64(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_real32(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_int32(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_uint32(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_int16(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_uint16(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_int8(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_uint8(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_TBB_API void imlincomb_tbb_boolean(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

#endif /* _IMLINCOMB_TBB_H_ */
