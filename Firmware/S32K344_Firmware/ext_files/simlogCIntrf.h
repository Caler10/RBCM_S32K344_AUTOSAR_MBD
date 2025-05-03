/* Copyright 2016-2017 The MathWorks, Inc. */
#ifndef simlogCIntrf_h
#define simlogCIntrf_h

#ifdef __cplusplus
#define SIMLOG_API_EXTERN_C extern "C"
#else
#define SIMLOG_API_EXTERN_C
#endif

#ifdef SL_INTERNAL

#include "version.h"

#if defined(BUILDING_LIBMWCODER_SIMLOG)
#define SIMLOG_API DLL_EXPORT_SYM
#define SIMLOG_API_C SIMLOG_API_EXTERN_C DLL_EXPORT_SYM
#else
#define SIMLOG_API DLL_IMPORT_SYM
#define SIMLOG_API_C SIMLOG_API_EXTERN_C DLL_IMPORT_SYM
#endif

#else

#define SIMLOG_API
#define SIMLOG_API_C SIMLOG_API_EXTERN_C

#endif

#if defined(_MSC_VER) && (_MSC_VER < 1910)
typedef unsigned int uint32_t;
#elif defined(__LCC__)
typedef unsigned int uint32_t;
#else
#include <stdint.h>
#endif

SIMLOG_API_C void observerLogInitialize(int aSimLogIOChannelKey);

SIMLOG_API_C void observerLogInit(void);

SIMLOG_API_C void observerLogReadPIC(int* PICVal);

SIMLOG_API_C void observerLogWritePIC(int PICVal);

SIMLOG_API_C void observerLogCleanup(void);

SIMLOG_API_C void observerLog(int key, void* value, int size);

SIMLOG_API_C void modifierInit(int numMods, void* modSpec);

SIMLOG_API_C void getQuantizationParams(int key,
                                        int* wl,
                                        int* sign,
                                        int* fl,
                                        int* rounding,
                                        int* wrapsat,
                                        int* active);

SIMLOG_API_C void modifierCleanup(void);

#endif /* simlogCIntrf_h */
