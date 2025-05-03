/* 
 *
 * Copyright 1994-2022 The MathWorks, Inc.
 *
 * File: rt_logging_mmi.h
 *
 * Abstract:
 */

#ifndef rt_logging_mmi_h
#define rt_logging_mmi_h

#include <stdlib.h>
/* Macro SIMPLIFIED_RTWTYPES_COMPATIBILITY declares compatibility with simplified version of
 * rtwtypes.h */
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "builtin_typeid_types.h"
#ifdef IS_SIM_TARGET
#include "rtw_matlogging_simtarget.h"
#include "rtw_modelmap_simtarget.h"
#else
#include "rtw_matlogging.h"
#include "rtw_modelmap.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

const char_T * rt_FillStateSigInfoFromMMI(RTWLogInfo   *li,
                                          const char_T **errStatus);

void rt_CleanUpForStateLogWithMMI(RTWLogInfo *li);

#ifdef __cplusplus
}
#endif

#endif /*  rt_logging_mmi_h */
