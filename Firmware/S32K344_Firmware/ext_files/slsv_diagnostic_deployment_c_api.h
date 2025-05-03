/* Copyright 2019-2022 The MathWorks, Inc. */

#ifndef slsv_diagnostic_deployment_c_api_h
#define slsv_diagnostic_deployment_c_api_h

#include "tmwtypes.h"

#ifdef BUILDING_LIBMWSL_SERVICES
/* being included from inside sl_services module */
#include "package.h"
#define SL_SERVICES_PUBLISHED_C extern "C" DLL_EXPORT_SYM
#else
/* being included from outside, such as raccel code */
#if defined(__cplusplus)
/* Needed for non-inlined C++ S-functions */
#define SL_SERVICES_PUBLISHED_C extern "C"
#else
#define SL_SERVICES_PUBLISHED_C extern
#endif
#endif

#include <limits.h>

#define UNDEFINED_VALUE INT_MIN

SL_SERVICES_PUBLISHED_C int feature_get(const char*);
SL_SERVICES_PUBLISHED_C int feature_set(const char*, int);

SL_SERVICES_PUBLISHED_C int hook_get(const char*);
SL_SERVICES_PUBLISHED_C int hook_set(const char*, int);


#endif /* slsv_diagnostic_deployment_c_api_h */
