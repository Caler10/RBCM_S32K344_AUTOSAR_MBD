/*
 * PUBLISHED header for C slccrt, the runtime library for SLCC C file
 *
 * Copyright 2019 The MathWorks, Inc.
 *
 */

#ifndef slccrt_h
#define slccrt_h

#if defined(_MSC_VER)
# pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# pragma once
#endif

/*
 * Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#endif /*EXTERN_C*/

#ifndef LIBSLCCRT_API
#define LIBSLCCRT_API
#endif

EXTERN_C LIBSLCCRT_API void slccrtCallOutOfProcessFcn(const char* ccChecksum, 
                                                      const char* fcnName,
                                                      const char* fcnDisplayName,
                                                      int32_T argNum, 
                                                      int32_T* scopeIds,
                                                      int32_T* dims,
                                                      int32_T* elemSizes,
                                                      void** dataPtrs,
                                                      const char* processInfoID);

EXTERN_C LIBSLCCRT_API bool slccrtIsLibAllowToDebug(const char* ccChecksum);

#endif /* slccrt_h */
