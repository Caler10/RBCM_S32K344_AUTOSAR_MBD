/* Copyright 2019 The Mathworks, Inc.*/

/* \file i18n_c_api.h */

/* This file provide C interface for calling i18n level functionalities 
 * like i18n initialization and what not */

#ifndef i18n_c_api_h
#define i18n_c_api_h

#include "tmwtypes.h"

#ifdef BUILDING_LIBMWI18N
  #include "package.h"
  #define LIBMWI18N_C_API extern "C" DLL_EXPORT_SYM
#else
  #if defined(__cplusplus)
    #define LIBMWI18N_C_API extern "C"
  #else 
    #define LIBMWI18N_C_API extern
  #endif
#endif

/* Initialize i18n services API for apps with C codebase */

LIBMWI18N_C_API void i18n_init(void);

#endif
