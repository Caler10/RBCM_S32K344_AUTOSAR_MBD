#if defined(_MSC_VER) || __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3)
#pragma once
#endif

#ifndef mwstringutil_published_h
#define mwstringutil_published_h

/* Copyright 2003-2017 The MathWorks, Inc. */

/* Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifdef __cplusplus
#include <cstdarg>
#else
#include <stdarg.h>
#endif

#include "tmwtypes.h"
#include "matrix.h"

EXTERN_C void suAsciiToStr(void* outstr, const uint8_T* in, int32_T n);
EXTERN_C void suStrToAscii(uint8_T* out, int32_T n, const void* instr);

EXTERN_C int32_T suStrcmp(const void* str1, const void* str2);
EXTERN_C int32_T suStrcmpi(const void* str1, const void* str2);
EXTERN_C int32_T suStrncmp(const void* str1, const void* str2, int32_T n);
EXTERN_C int32_T suStrncmpi(const void* str1, const void* str2, int32_T n);
EXTERN_C int32_T suCStrcmp(const void* str, const char* cstr);

EXTERN_C int32_T suStrlen(const void* instr);
EXTERN_C int32_T suStrfind(const void* text, const void* pattern);
EXTERN_C void suSubstr(void* outstr, const void* instr, int32_T pos, int32_T len);
EXTERN_C void suSubstrToEnd(void* outstr, const void* instr, int32_T pos);
EXTERN_C void suStrcat(void* outstr, int32_T n, ...);

EXTERN_C void suNumericToString_bool(void* outstr, bool x);
EXTERN_C void suNumericToString_int8(void* outstr, int8_T x);
EXTERN_C void suNumericToString_int16(void* outstr, int16_T x);
EXTERN_C void suNumericToString_int32(void* outstr, int32_T x);
EXTERN_C void suNumericToString_int64(void* outstr, int64_T x);
EXTERN_C void suNumericToString_uint8(void* outstr, uint8_T x);
EXTERN_C void suNumericToString_uint16(void* outstr, uint16_T x);
EXTERN_C void suNumericToString_uint32(void* outstr, uint32_T x);
EXTERN_C void suNumericToString_uint64(void* outstr, uint64_T x);
EXTERN_C void suNumericToString_float(void* outstr, float x);
EXTERN_C void suNumericToString_double(void* outstr, double x);

EXTERN_C void suNumericToString_cint8(void* outstr, int8_T xr, int8_T xi);
EXTERN_C void suNumericToString_cint16(void* outstr, int16_T xr, int16_T xi);
EXTERN_C void suNumericToString_cint32(void* outstr, int32_T xr, int32_T xi);
EXTERN_C void suNumericToString_cint64(void* outstr, int64_T xr, int64_T xi);
EXTERN_C void suNumericToString_cuint8(void* outstr, uint8_T xr, uint8_T xi);
EXTERN_C void suNumericToString_cuint16(void* outstr, uint16_T xr, uint16_T xi);
EXTERN_C void suNumericToString_cuint32(void* outstr, uint32_T xr, uint32_T xi);
EXTERN_C void suNumericToString_cuint64(void* outstr, uint64_T xr, uint64_T xi);
EXTERN_C void suNumericToString_cfloat(void* outstr, float xr, float xi);
EXTERN_C void suNumericToString_cdouble(void* outstr, double xr, double xi);

EXTERN_C void suFromCStr(void* outstr, const char* incstr);
EXTERN_C char* suToCStr(const void* instr);
EXTERN_C void suFreeCStr(char* str);

EXTERN_C void suSprintf_int8(void* outstr, const void* format, int8_T x);
EXTERN_C void suSprintf_int16(void* outstr, const void* format, int16_T x);
EXTERN_C void suSprintf_int32(void* outstr, const void* format, int32_T x);
EXTERN_C void suSprintf_int64(void* outstr, const void* format, int64_T x);
EXTERN_C void suSprintf_uint8(void* outstr, const void* format, uint8_T x);
EXTERN_C void suSprintf_uint16(void* outstr, const void* format, uint16_T x);
EXTERN_C void suSprintf_uint32(void* outstr, const void* format, uint32_T x);
EXTERN_C void suSprintf_uint64(void* outstr, const void* format, uint64_T x);
EXTERN_C void suSprintf_float(void* outstr, const void* format, float x);
EXTERN_C void suSprintf_double(void* outstr, const void* format, double x);
EXTERN_C void suSprintf_str(void* outstr, const void* format, const void* x);

EXTERN_C int32_T suSscanf(const void* outstr, const void* format, ...);

EXTERN_C void suResizeToOtherSizeAndZero(void* str, const void* str_other);
EXTERN_C void suResizeToOtherSizePlusOne(void* str, const void* str_other);
EXTERN_C void* suPointerToBuffer(void* str);
EXTERN_C void suClipStrAtFirstNull(void* str);

EXTERN_C void* suAddStackString(const char* initial);
EXTERN_C int32_T suStringStackSize(void);
EXTERN_C void suSetStringStackSize(int32_T);
EXTERN_C void* suMoveReturnedStringToTopOfCallerStack(void* str, int32_T size);
EXTERN_C void suMoveReturnedStringsToTopOfCallerStack(int32_T size, int32_T n, ...);

EXTERN_C void suMoveString(void* dst_str, void* src_str);
EXTERN_C void suCopyString(void* dst_str, const void* src_str);
EXTERN_C void suTruncate(void* str, int32_T size);


EXTERN_C void suInitializeSILStringOutput(void* dst);
EXTERN_C void suWriteSILStringInput(char* sil_in, int32_T size, const void* src);
EXTERN_C void suWriteSILStringOutput(void* dst, const char* sil_out, int32_T size);

EXTERN_C void suInitializeString(void* dst, const char* initial);
EXTERN_C void suInitializeStringFromMx(void* dst, const mxArray* initial);

EXTERN_C int32_T suCount(const void* str1, const void* str2);
EXTERN_C int32_T suCountI(const void* str1, const void* str2);
EXTERN_C int32_T suContains(const void* str1, const void* str2);
EXTERN_C int32_T suContainsI(const void* str1, const void* str2);
EXTERN_C int32_T suStartsWith(const void* str1, const void* str2);
EXTERN_C int32_T suStartsWithI(const void* str1, const void* str2);
EXTERN_C int32_T suEndsWith(const void* str1, const void* str2);
EXTERN_C int32_T suEndsWithI(const void* str1, const void* str2);
EXTERN_C void suStripBoth(void* outstr, const void* str, char ch);
EXTERN_C void suStripLeft(void* outstr, const void* str, char ch);
EXTERN_C void suStripRight(void* outstr, const void* str, char ch);
EXTERN_C void suReplace(void* outstr, void* str1, void* str2, void* str3);
EXTERN_C void suReplaceBetweenIdxInclusive(void* outstr,
                                           const void* str,
                                           int32_T left,
                                           int32_T right,
                                           const void* newStr);
EXTERN_C void suReplaceBetweenIdxExclusive(void* outstr,
                                           const void* str,
                                           int32_T left,
                                           int32_T right,
                                           const void* newStr);
EXTERN_C void suReplaceBetweenSubstrExclusive(void* outstr,
                                              const void* str,
                                              const void* startStr,
                                              const void* endStr,
                                              const void* newStr);
EXTERN_C void suReplaceBetweenSubstrInclusive(void* outstr,
                                              const void* str,
                                              const void* startStr,
                                              const void* endStr,
                                              const void* newStr);


#endif /* mwstringutil_published_h */
