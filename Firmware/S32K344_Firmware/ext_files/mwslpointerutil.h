#if defined(_MSC_VER) || __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3)
#pragma once
#endif

#ifndef mwslpointerutil_published_h
#define mwslpointerutil_published_h

/* Copyright 2020-2021 The MathWorks, Inc. */

/* Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C
#define EXTERN_C extern
#endif

// ParamTuningAppSvc can be compiled with either tmwtypes or rtwtypes
#ifdef IS_RAPID_ACCEL
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C void storeArrayInPointerPool(void* dst, const void* src, int32_T numBytes);

#endif /* mwslpointerutil_published_h */
