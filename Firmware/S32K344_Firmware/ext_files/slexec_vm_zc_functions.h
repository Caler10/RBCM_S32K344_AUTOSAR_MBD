#ifndef SLEXEC_VM_ZC_FUNCTIONS_H
#define SLEXEC_VM_ZC_FUNCTIONS_H
/**
 * @file slexec_vm_zc_functions.h
 *
 * This header is the exported C interface of the Simulink ZC functions
 * for use in VM applications.
 * 
 */

/* Copyright 2015-2023 The MathWorks, Inc. */
#include "simstruc_types.h"
#include "solver_zc.h"

#ifdef BUILDING_SLEXEC_SIMBRIDGE
 /* being included from inside slexec_simbridge module */
  #include "package.h"
  #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern "C" DLL_EXPORT_SYM
#else
 /* being included from outside, such as raccel code */
  #if defined(__cplusplus)
 /* Needed for non-inlined C++ S-functions */
    #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern "C"
  #else 
    #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern
  #endif
#endif

SLEXEC_SIMBRIDGE_PUBLISHED_C ZCEventType rt_ZCFcn(
    ZCDirection zcDir, uint8_T* prevZc, double currValue);
SLEXEC_SIMBRIDGE_PUBLISHED_C ZCEventType rt_I32ZCFcn(
    ZCDirection zcDir, uint8_T* prevZc, int32_T currValue);

SLEXEC_SIMBRIDGE_PUBLISHED_C ZCEventType rt_ZCFcnRefine(
    slZcEventType zcsDir, uint8_T* prevZc, double currValue);
#endif
