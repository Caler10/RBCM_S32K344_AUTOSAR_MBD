/*
 * Copyright 1994-2002 The MathWorks, Inc.
 *
 * File: rtmcmacros.h     
 *
 * Abstract:
 * API glue for calling rt_OneStep.  These macros are used to create
 * a structure with the elements in the rtModel structure that are 
 * required to be passed to rt_OneStep.
 */

#ifndef _RTW_HEADER_rtmcmacros_h_
# define _RTW_HEADER_rtmcmacros_h_

/* Real-time Model Common Data Structure */
typedef struct {
  const char            **errorStatus;
  RTWLogInfo            **rtwLogInfo;
  RTWExtModeInfo        **extModeInfo;
  RTWRTModelMethodsInfo *modelMethodsInfo;
  RTWSolverInfo         **solverInfo;
  int_T                  *numSampTimes;
  time_T                **t;
  void                  **timingData;
  SimTimeStep            *simTimeStep;
  int_T                 **sampleHits;
  int_T                 **perTaskSampleHitsPtr;
  boolean_T              *stopRequested;
  time_T                **sampleTimes;
  int_T                 **sampleTimeTaskIDPtr;
} rtModelCommon;

#define rtmcsetCommon(MC, M)                                  \
    MC.errorStatus         = &rtmGetErrorStatus(M);           \
    MC.rtwLogInfo          = &rtmGetRTWLogInfo(M);            \
    MC.extModeInfo         = &rtmGetRTWExtModeInfo(M);        \
    MC.modelMethodsInfo     = &rtmGetRTWRTModelMethodsInfo(M); \
    MC.solverInfo           = &rtmGetRTWSolverInfo(M);         \
    MC.numSampTimes         = &rtmGetNumSampleTimes(M);        \
    MC.t                    = &rtmGetTPtr(M);                  \
    MC.timingData           = &rtmGetTimingData(M);            \
    MC.simTimeStep          = &rtmGetSimTimeStep(M);           \
    MC.sampleHits           = &rtmGetSampleHitPtr(M);          \
    MC.perTaskSampleHitsPtr = &rtmGetPerTaskSampleHitsPtr(M);  \
    MC.stopRequested        = &rtmGetStopRequested(M);         \
    MC.sampleTimes          = &rtmGetSampleTimePtr(M);         \
    MC.sampleTimeTaskIDPtr  = &rtmGetSampleTimeTaskIDPtr(M);

# define rtmcGetErrorStatus(rtmc)   (*rtmc->errorStatus)
# define rtmcGetRTWLogInfo(rtmc)   (*rtmc->rtwLogInfo)
# define rtmcGetRTWExtModeInfo(rtmc) (*rtmc->extModeInfo)
# define rtmcGetRTWRTModelMethodsInfo(rtmc) (*rtmc->modelMethodsInfo)
# define rtmcGetRTWSolverInfo(rtmc) (*rtmc->solverInfo)
# define rtmcGetNumSampleTimes(rtmc) (*rtmc->numSampTimes)
# define rtmcGetTPtr(rtmc) (*rtmc->t)
# define rtmcGetTimingData(rtmc) (*rtmc->timingData)
# define rtmcGetSimTimeStep(rtmc) (*rtmc->simTimeStep)
# define rtmcGetSampleHitPtr(rtmc) (*rtmc->sampleHits)
# define rtmcGetPerTaskSampleHitsPtr(rtmc) (*rtmc->perTaskSampleHitsPtr)
# define rtmcGetStopRequested(rtmc) (*rtmc->stopRequested)
# define rtmcGetSampleTimePtr(rtmc) (*rtmc->sampleTimes)
# define rtmcGetSampleTimeTaskIDPtr(rtmc) (*rtmc->sampleTimeTaskIDPtr)

# define rtmcGetSampleTime(rtmc,sti) (*rtmc->sampleTimes[sti])

#define rtmcGetTaskTime(rtmc,sti) \
    rtmcGetTPtr(rtmc)[rtmcGetSampleTimeTaskIDPtr(rtmc)[sti]]

/* Only used in SINGLETASKING section of main routine */
#define rtmcIsSampleHit(rtmc,sti,unused) \
    ((rtmcGetSimTimeStep(rtmc) == MAJOR_TIME_STEP) && \
      rtmcGetSampleHitPtr(rtmc)[rtmcGetSampleTimeTaskIDPtr(rtmc)[sti]])

#endif                                  /* _RTW_HEADER_rtmcmacros_h_ */

/* [EOF] rtmcmacros.h */
