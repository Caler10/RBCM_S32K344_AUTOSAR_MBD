/*
 * PUBLISHED header for C cgxeooprt, the OOP runtime library for CGXE C file
 *
 * Copyright 2020 The MathWorks, Inc.
 *
 */

#ifndef cgxeooprt_h
#define cgxeooprt_h

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

#endif

#ifndef LIBCGXEOOPRT_API
#define LIBCGXEOOPRT_API
#endif

#if defined(BUILDING_LIBMWCGXEOOPRT) || defined(DLL_IMPORT_SYM)
/* internal use */
# include "simstruct/simstruc.h"
#else
/* external use */
# include "simstruc.h"
#endif

/*
 * MATLAB INTERNAL USE ONLY :: Call Out-Of-Process Runtime Function
 */
EXTERN_C LIBCGXEOOPRT_API void cgxertCallSLCCOutOfProcessFcn(SimStruct* S,
                                                             int sysIdx,
                                                             int blkIdx,
                                                             const char* ccChecksum,
                                                             const char* fcnName,
                                                             const char* fcnDisplayName,
                                                             int32_T argNum,
                                                             int32_T* scopeIds,
                                                             int32_T* dims,
                                                             int32_T* elemSizes,
                                                             void** dataPtrs);



#endif /* cgxeooprt_h */
