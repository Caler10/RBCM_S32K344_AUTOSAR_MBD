/* Copyright 2013 The MathWorks, Inc. */
#ifndef _IMLINCOMB_H_
#define _IMLINCOMB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWIMLINCOMB_API
#    define LIBMWIMLINCOMB_API
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_real64(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_real32(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_int32(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_uint32(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_int16(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_uint16(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_int8(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_uint8(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

EXTERN_C LIBMWIMLINCOMB_API void imlincomb_boolean(
        const real64_T  *fScalars,
        real64_T         fNumScalars,
        void            *output_image,
        int8_T           outputClass,
        real64_T         fNumElements,
        real64_T         fNumImages,
        ...);

#endif /* _IMLINCOMB_H_ */
