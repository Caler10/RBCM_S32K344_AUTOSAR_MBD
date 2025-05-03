/* Copyright 2021-2022 The MathWorks, Inc. */
#ifndef _BARCODECORE_
#define _BARCODECORE_

#ifndef LIBMWREADBARCODE_API
#    define LIBMWREADBARCODE_API
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

#include <stdint.h>

EXTERN_C LIBMWREADBARCODE_API
void multiFormatDetectDecode(void* mImgData, const int32_t width,
                             const int32_t height, void* mFormatData,
                             const int nFormats,  const int* formatLengths,
                             const bool robustRowScan,
                             const bool robustPatternScan, void** resultObj,
                             int* locSize, int* msgLen, int* formatLen);

EXTERN_C LIBMWREADBARCODE_API
void initializeOutput(void* msg, void* loc, void* format, void* resultObj);

EXTERN_C LIBMWREADBARCODE_API
void deleteResultPtr(void* ptrObj);

#endif