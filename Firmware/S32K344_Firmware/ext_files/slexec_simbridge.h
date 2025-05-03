#ifndef SLEXEC_SIMBRIDGE_H
#define SLEXEC_SIMBRIDGE_H
/**
 * @file slexec_simbridge.h
 *
 * This header is the exported C interface to the simulink execution engine
 * (slexec_simbridge) for API that does not involved simstruct. It is used by
 * the Rapid Accelerator targets. This header can be included from any header
 * (see slexec_simstruct_bridge.h for simstruct related API)
 *
 * 
 */

/* Copyright 2014 The MathWorks, Inc. */

#include "tmwtypes.h"

/*******************************************************************************
 * Section A.1. Symbol visibility
 *******************************************************************************/

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

/********************************************************************************
 * Section A.2. External mode hooks
 *******************************************************************************/

#ifndef _RTWEXTMODEINFO
  #define _RTWEXTMODEINFO
    typedef struct _RTWExtModeInfo_tag RTWExtModeInfo;
#endif

typedef struct ssBridgeExtModeCallbacks_tag {
    void (*checkInit)(int_T);
    void (*waitForStartPkt)(RTWExtModeInfo *,int_T,boolean_T*);
    void (*oneStepFcn)(RTWExtModeInfo*, int, boolean_T*);
    void (*uploadCheckTriggerFcn)(int_T);
    void (*uploadFcn)(int_T, time_T);
    void (*checkEndTriggerFcn)(void);
    void (*pauseIfNeeded)(RTWExtModeInfo*, int, boolean_T*);
    void (*shutDown)(int);

    struct ssBridgeTargetConnectivityCallbacks_tag {
        void (*TgtConnPreStep)(int_T);
        void (*TgtConnPostStep)(int_T);
    } targetConnectivityCallbacks_;

} ssBridgeExtModeCallbacks_T;

/* Time Accessor for simulink execution based simulation (raccel/rsim) */
SLEXEC_SIMBRIDGE_PUBLISHED_C time_T rteiGetT(RTWExtModeInfo* ei);

#define rteiSetTPtr(E,p) /* no-op */

#endif /* ifdef SLEXEC_SSBRIDGE_H */
