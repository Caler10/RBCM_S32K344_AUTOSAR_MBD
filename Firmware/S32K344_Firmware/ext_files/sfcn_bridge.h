/*
 * Copyright 1994-2021 The MathWorks, Inc.
 *
 * File: sfcn_bridge.h     
 *
 * Abstract:
 *   This file helps support a bridge between non-inlined S-functions
 *   and the rtModel. When we did not have the notion of an rtModel,
 *   non-inlined S-functions obtained model data by directly accessing
 *   the model's SimStruct. With the introduction of the rtModel, 
 *   this direct access is no longer possible. Therefore, we need to 
 *   redefine some of the macros inside simstruc.h to instead access
 *   fields of the rtModel. 
 */

#ifndef __SFCN_BRIDGE_H__
#define __SFCN_BRIDGE_H__

/* Logical definitions */
#if (!defined(__cplusplus))
#  ifndef false
#   define false                       (0U)
#  endif
#  ifndef true
#   define true                        (1U)
#  endif
#endif

typedef struct {
    const char_T  **errorStatusPtr;
    
    int           *numRootSampTimesPtr;
    
    time_T        **tPtrPtr;
    time_T        *tStartPtr;
    time_T        *tFinalPtr;
    time_T        *tOfLastOutputPtr;
    time_T        *stepSizePtr;
    boolean_T     *stopRequestedPtr;
    boolean_T     *derivCacheNeedsResetPtr;
    boolean_T     *zcCacheNeedsResetPtr;
    boolean_T     *CTOutputIncnstWithStatePtr;

    int_T         **sampleHitsPtr;
    int_T         **perTaskSampleHitsPtr;

    SS_SimMode    *simModePtr;
    
    RTWSolverInfo **siPtr;
} RTWSfcnInfo;

/* Get a type-cast sfcn info from the SimStruct */
#define _RTSS(S) ((RTWSfcnInfo *) ssGetRTWSfcnInfo(S))

/* Set/Get fields of the sfcn info */
#define rtssSetErrorStatusPtr(sfi,p) (sfi)->errorStatusPtr = (p)

#define rtssSetNumRootSampTimesPtr(sfi,p) (sfi)->numRootSampTimesPtr = (p)

#define rtssSetTPtrPtr(sfi,p)        (sfi)->tPtrPtr = (p)
#define rtssSetTStartPtr(sfi,p)      (sfi)->tStartPtr = (p)
#define rtssSetTFinalPtr(sfi,p)      (sfi)->tFinalPtr = (p)
#define rtssSetTimeOfLastOutputPtr(sfi,p) (sfi)->tOfLastOutputPtr = (p)
#define rtssSetStepSizePtr(sfi,p)    (sfi)->stepSizePtr = (p)
#define rtssSetStopRequestedPtr(sfi,p) (sfi)->stopRequestedPtr = (p)
#define rtssSetDerivCacheNeedsResetPtr(sfi,p) \
     (sfi)->derivCacheNeedsResetPtr = (p)
#define rtssSetZCCacheNeedsResetPtr(sfi,p) \
     (sfi)->zcCacheNeedsResetPtr = (p)
#define rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfi,p) \
     (sfi)->CTOutputIncnstWithStatePtr = (p)
#define rtssSetSampleHitsPtr(sfi,p) (sfi)->sampleHitsPtr = (p)
#define rtssSetPerTaskSampleHitsPtr(sfi,p) (sfi)->perTaskSampleHitsPtr = (p)

#define rtssSetSimModePtr(sfi,p)      (sfi)->simModePtr = (p)

#define rtssSetSolverInfoPtr(sfi,p)  (sfi)->siPtr = (p)

/* Error status defines */
#undef ssSetErrorStatus
#define ssSetErrorStatus(S,e) *(_RTSS(S)->errorStatusPtr) = (e)

#undef ssGetErrorStatus
#define ssGetErrorStatus(S)   *(_RTSS(S)->errorStatusPtr)

#undef ssGetNumRootSampleTimes
#define ssGetNumRootSampleTimes(S) *(_RTSS(S)->numRootSampTimesPtr)

/* Timing defines */
#undef ssGetTPtr
#define ssGetTPtr(S) (_RTSS(S)->tPtrPtr[0])

#undef ssGetT
#define ssGetT(S) *(_RTSS(S)->tPtrPtr[0])

#undef ssGetTStart
#define ssGetTStart(S) *(_RTSS(S)->tStartPtr)

#undef ssGetTFinal
#define ssGetTFinal(S) *(_RTSS(S)->tFinalPtr)

#undef ssGetTimeOfLastOutput
#define ssGetTimeOfLastOutput(S) *(_RTSS(S)->tOfLastOutputPtr)

#undef ssGetStepSize
#define ssGetStepSize(S) *(_RTSS(S)->stepSizePtr)

#undef ssSetStopRequested
#define ssSetStopRequested(S,v) *(_RTSS(S)->stopRequestedPtr) = (v)

#undef ssGetStopRequested
#define ssGetStopRequested(S) *(_RTSS(S)->stopRequestedPtr)

#undef ssSetDerivCacheNeedsReset
#define ssSetDerivCacheNeedsReset(S,v) \
     *(_RTSS(S)->derivCacheNeedsResetPtr) = (v)

#undef ssGetDerivCacheNeedsReset
#define ssGetDerivCacheNeedsReset(S) \
     *(_RTSS(S)->derivCacheNeedsResetPtr)

#undef ssSetZCCacheNeedsReset
#define ssSetZCCacheNeedsReset(S,v) \
     *(_RTSS(S)->zcCacheNeedsResetPtr) = (v)

#undef ssGetZCCacheNeedsReset
#define ssGetZCCacheNeedsReset(S) \
     *(_RTSS(S)->zcCacheNeedsResetPtr)

#undef ssSetContTimeOutputInconsistentWithStateAtMajorStep
#define ssSetContTimeOutputInconsistentWithStateAtMajorStep(S) *(_RTSS(S)->CTOutputIncnstWithStatePtr) = true

#undef ssGetContTimeOutputInconsistentWithStateAtMajorStep
#define ssGetContTimeOutputInconsistentWithStateAtMajorStep(S) *(_RTSS(S)->CTOutputIncnstWithStatePtr)

#undef ssSetBlkStateChange
#define ssSetBlkStateChange(S) *(_RTSS(S)->CTOutputIncnstWithStatePtr) = true

#undef ssGetBlkStateChange
#define ssGetBlkStateChange(S) *(_RTSS(S)->CTOutputIncnstWithStatePtr)

#undef ssGetSampleHitPtr
#define ssGetSampleHitPtr(S) *(_RTSS(S)->sampleHitsPtr)

#undef ssGetPerTaskSampleHitsPtr
#define ssGetPerTaskSampleHitsPtr(S) *(_RTSS(S)->perTaskSampleHitsPtr)
           
#undef ssGetSimMode
#define ssGetSimMode(S) *(_RTSS(S)->simModePtr)

/* Solver-related defines */
#undef ssGetSolverName
#define ssGetSolverName(S) \
   rtsiGetSolverName(*(_RTSS(S)->siPtr))

#undef ssIsVariableStepSolver
#define ssIsVariableStepSolver(S) \
   rtsiIsVariableStepSolver(*(_RTSS(S)->siPtr))

#undef ssSetSolverNeedsReset
#define ssSetSolverNeedsReset(S) \
   rtsiSetSolverNeedsReset(*(_RTSS(S)->siPtr), true)

#undef ssGetSolverNeedsReset
#define ssGetSolverNeedsReset(S) \
   rtsiGetSolverNeedsReset(*(_RTSS(S)->siPtr))

#undef ssSetBlockStateForSolverChangedAtMajorStep
#define ssSetBlockStateForSolverChangedAtMajorStep(S) \
   rtsiSetBlockStateForSolverChangedAtMajorStep(*(_RTSS(S)->siPtr), true)

#undef ssGetBlockStateForSolverChangedAtMajorStep
#define ssGetBlockStateForSolverChangedAtMajorStep(S) \
   rtsiGetBlockStateForSolverChangedAtMajorStep(*(_RTSS(S)->siPtr))

#undef ssGetSolverMode
#define ssGetSolverMode(S) \
   rtsiGetSolverMode(*(_RTSS(S)->siPtr))

#undef ssGetSolverMode
#define ssGetSolverMode(S) \
   rtsiGetSolverMode(*(_RTSS(S)->siPtr))

#undef ssGetSolverStopTime
#define ssGetSolverStopTime(S) \
   rtsiGetSolverStopTime(*(_RTSS(S)->siPtr))

#undef ssGetMinStepSize
#define ssGetMinStepSize(S) \
   rtsiGetMinStepSize(*(_RTSS(S)->siPtr))

#undef ssGetMaxStepSize
#define ssGetMaxStepSize(S) \
   rtsiGetMaxStepSize(*(_RTSS(S)->siPtr))

#undef ssGetSolverMaxConsecutiveMinStep
#define ssGetSolverMaxConsecutiveMinStep(S) \
   rtsiGetSolverMaxConsecutiveMinStep(*(_RTSS(S)->siPtr))

#undef ssGetFixedStepSize
#define ssGetFixedStepSize(S) \
   rtsiGetFixedStepSize(*(_RTSS(S)->siPtr))

#undef ssGetMaxNumMinSteps
#define ssGetMaxNumMinSteps(S) \
   rtsiGetMaxNumMinSteps(*(_RTSS(S)->siPtr))

#undef ssGetSolverRefineFactor
#define ssGetSolverRefineFactor(S) \
   rtsiGetSolverRefineFactor(*(_RTSS(S)->siPtr))

#undef ssGetSolverRelTol
#define ssGetSolverRelTol(S) \
   rtsiGetSolverRelTol(*(_RTSS(S)->siPtr))

#undef ssGetSolverMaxOrder
#define ssGetSolverMaxOrder(S) \
   rtsiGetSolverMaxOrder(*(_RTSS(S)->siPtr))

#undef ssGetSolverConsecutiveZCsStepRelTol
#define ssGetSolverConsecutiveZCsStepRelTol(S) \
   rtsiGetSolverConsecutiveZCsStepRelTol(*(_RTSS(S)->siPtr))

#undef ssGetSolverZcThreshold
#define ssGetSolverZcThreshold(S) \
   rtsiGetSolverZcThreshold(*(_RTSS(S)->siPtr))

#undef ssGetSolverMaxConsecutiveZCs
#define ssGetSolverMaxConsecutiveZCs(S) \
   rtsiGetSolverMaxConsecutiveZCs(*(_RTSS(S)->siPtr))

#undef ssGetSolverExtrapolationOrder
#define ssGetSolverExtrapolationOrder(S) \
   rtsiGetSolverExtrapolationOrder(*(_RTSS(S)->siPtr))

#undef ssGetSolverNumberNewtonIterations
#define ssGetSolverNumberNewtonIterations(S) \
    rtsiGetSolverNumberNewtonIterations(*(_RTSS(S)->siPtr))

#undef ssIsModeUpdateTimeStep
#define ssIsModeUpdateTimeStep(S)              \
    rtsiIsModeUpdateTimeStep(*(_RTSS(S)->siPtr))

#undef ssGetSimTimeStep
#define ssGetSimTimeStep(S) \
   rtsiGetSimTimeStep(*(_RTSS(S)->siPtr))

#undef ssIsMinorTimeStep
#if NCSTATES > 0
#define ssIsMinorTimeStep(S) \
   (ssGetSimTimeStep(S) == MINOR_TIME_STEP)
#else
#define ssIsMinorTimeStep(S) (0)
#endif

#undef ssIsMajorTimeStep
#if NCSTATES > 0
#define ssIsMajorTimeStep(S) \
     (ssGetSimTimeStep(S) == MAJOR_TIME_STEP)
#else
#define ssIsMajorTimeStep(S) (1)
#endif

#undef ssGetTaskTime
#define ssGetTaskTime(S,sti) \
    (*(_RTSS(S)->tPtrPtr[ssGetSampleTimeTaskID(S,sti)]))

#undef ssIsSampleHit

#if SS_MULTITASKING

#if TID01EQ 
#define ssIsSampleHit(S,sti,tid) \
   ((ssGetSampleTimeTaskID(S,sti) == 1 ? \
     0:ssGetSampleTimeTaskID(S,sti)) == (tid))
#else 
#define ssIsSampleHit(S,sti,tid) \
  (ssGetSampleTimeTaskID(S,sti) == (tid)) 
#endif 

#else

#define ssIsSampleHit(S,sti,tid) \
     (ssIsMajorTimeStep(S) && (tid != CONSTANT_TID) &&\
            ((ssGetSampleHitPtr(S))[ssGetSampleTimeTaskID(S,sti)]))

#endif 

#undef ssIsSampleHitInTask
#undef ssIsSpecialSampleHit

#if SS_MULTITASKING
#define ssIsSampleHitInTask(S, my_sti, tid) \
    (ssGetPerTaskSampleHitsPtr(             \
        S))[ssGetSampleTimeTaskID(S, my_sti) + ((tid) * (ssGetNumRootSampleTimes(S)))]
#define ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid) \
    (ssIsMajorTimeStep(S) && ssIsSampleHitInTask(S, my_sti, ssGetSampleTimeTaskID(S, promoted_sti)))
#else
#define ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid) ssIsSampleHit(S, my_sti, tid)
#endif

#undef  ssIsFirstInitCond
#define ssIsFirstInitCond(S) (ssGetT(S)==ssGetTStart(S))

#undef ssSetFirstInitCondCalled
#define ssSetFirstInitCondCalled(S) 

#undef ssClearFirstInitCondCalled
#define ssClearFirstInitCondCalled(S)

#endif /* __SFCN_BRIDGE_H__ */

/* [EOF] sfcn_bridge.h */



