#ifndef SLEXEC_VM_SIMSTRUCT_BRIDGE_H
#define SLEXEC_VM_SIMSTRUCT_BRIDGE_H
/**
 * @file slexec_vm_simstruct_bridge.h
 *
 * This header is the exported C interface of the SimStruct and related
 * data structures, for use in VM applications.
 * 
 */

/* Copyright 2015-2020 The MathWorks, Inc. */

#include "tmwtypes.h"

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

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelRunBlock(
    void* S, int_T sysIdx, int_T blkIdx, int_T blkFcn);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelPreBlock(
    void* S, int_T sysIdx, int_T blkIdx, int_T blkFcn);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelPostBlock(
    void* S, int_T sysIdx, int_T blkIdx, int_T blkFcn);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_slmrAccelRunBlockSystemInitialize(
    void* S, int_T sysIdx, int_T blkIdx);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_slmrAccelRunBlockSystemReset(
    void* S, int_T sysIdx, int_T blkIdx);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelModelBlockFcnCallInput(
    void* S, int_T sysIdx, int_T blkIdx, int_T portIdx, int_T tid, int_T blkFcn);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelCopyCacheForIISBasedOnDescSysList(
    void* S, int_T sysIdx, int_T fromCache);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelCopyCacheForIISBasedOnCGSysList(
    void* S, int_T sysIdx, int_T fromCache);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCallAccelSetDims(
    void* S, int_T sysIdx, int_T blkIdx, int_T outIdx, int_T ruleIdx);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetReinitializeEventBeingProcessed(void* S,
                                                                          char_T* reinitId);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetChecksumVal(
    void *S, int_T sysIdx, int_T blkIdx);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssGetBlockPath(
    void* S, int_T sysIdx, int_T blkIdx, char_T** path);

SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetRootDWork(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm__ssGetModelBlockIO(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C const void* vm_ssGetConstBlockIO(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C double* vm_ssGetModelRtp(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetU(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetUByIndex(void* S, int_T index);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetX(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetdX(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetAbsTolVector(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetJacobianPerturbationBoundsMinVec(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetJacobianPerturbationBoundsMaxVec(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetY(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void* vm_ssGetYByIndex(void* S, int_T index);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_dworkSizeCheck(void* S, uint_T sizeofStruct);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_blockIOSizeCheck(void* S, uint_T sizeofStruct);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_USizeCheck(void* S, uint_T sizeofStruct);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_YSizeCheck(void* S, uint_T sizeofStruct);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_paramSizeCheck(void* S, uint_T sizeofStruct);

SLEXEC_SIMBRIDGE_PUBLISHED_C int_T
    vm_ssIsSampleHit(void* S, int_T sti, int_T tid);
SLEXEC_SIMBRIDGE_PUBLISHED_C int_T vm_ssIsContinuousTask(void* S, int_T tid);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssSetSampleHit(void* S, int_T sti,
                                                     int_T v);
SLEXEC_SIMBRIDGE_PUBLISHED_C int vm_ssIsSpecialSampleHit(void* S, int_T my_sti,
                                                         int_T promoted_sti,
                                                         int_T tid);

SLEXEC_SIMBRIDGE_PUBLISHED_C uint32_T vm_ssGetClockTick(void* S, int_T sti);
SLEXEC_SIMBRIDGE_PUBLISHED_C uint32_T vm_ssGetClockTickH(void* S, int_T sti);

SLEXEC_SIMBRIDGE_PUBLISHED_C double* vm_ssGetSolverZcSignalVector(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T* vm_ssGetPrevZCSigState(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C int_T vm_ssIsMajorTimeStep(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C bool vm_ssIsModeUpdateTimeStep(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetStopRequested(void* S, int_T val);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_srClearBC(int8_T* state);
SLEXEC_SIMBRIDGE_PUBLISHED_C void  vm_srUpdateBC(int8_T* state);

SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetT(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetTaskTime(void* S, int_T sti);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssSetTaskTime(void* S, int_T sti,
                                                    double time);
SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetTStart(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetTFinal(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetStepSize(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetTimeOfLastOutput(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C double vm__ssGetVarNextHitTime(void* S,
                                                            int_T varId);
SLEXEC_SIMBRIDGE_PUBLISHED_C double vm_ssGetTimeOfNextVarHit(void* S, int_T sti);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssSetVarNextHitTime(void* S, int_T varId,
                                                          double tNextMin);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetTimeOfNextVarHit(void* S, int_T sti,
                                                           double tNextMin);

SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T
    vm_ssGetTNextWasAdjusted(void* S, int_T varTsId);

SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T* vm_ssGetContStateDisabled(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T vm_ssIsFirstInitCond(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C const char_T* vm_ssGetErrorStatus(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T vm_getHasError(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetErrorStatus(void* S,
                                                      const char_T* str);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssSet_slErrMsg(void* S, void* diag);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssReportDiagnosticAsWarning(void* S,
                                                                  void* diag);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssReportDiagnosticAsInfo(void* S,
                                                               void* diag);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetContTimeOutputInconsistentWithStateAtMajorStep(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetBlockStateForSolverChangedAtMajorStep(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ReadLocalDSMNoIdx(void* S, int_T dsmIdx,
                                                       const char_T* blockPath,
                                                       int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ReadLocalDSMIntIdx(void* S, int_T dsmIdx,
                                                        const char_T* blockPath,
                                                        int_T idx,
                                                        int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_WriteLocalDSMNoIdx(void* S, int_T dsmIdx,
                                                        const char_T* blockPath,
                                                        int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_WriteLocalDSMIntIdx(
    void* S, int_T dsmIdx, const char_T* blockPath, int_T idx, int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ReadGlobalDSMNoIdx(void* S, int_T dsmIdx,
                                                        const char_T* blockPath,
                                                        int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ReadGlobalDSMIntIdx(
    void* S, int_T dsmIdx, const char_T* blockPath, int_T idx, int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_WriteGlobalDSMNoIdx(
    void* S, int_T dsmIdx, const char_T* blockPath, int_T idxWidth);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_WriteGlobalDSMIntIdx(
    void* S, int_T dsmIdx, const char_T* blockPath, int_T idx, int_T idxWidth);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssIsPositiveDataValue(void* S, void* data,
                                                            int_T dtId,
                                                            int8_T* result);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm__ssSignDataValue(void* S, void* data,
                                                      int_T dtId,
                                                      int8_T* result);

SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T vm_ssIsSolverComputingJacobian(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T vm_ssIsSolverRequestingReset(void* S);
SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T vm_ssIsSolverCheckingCIC(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssRaiseEvent(void* S, uint_T runtimeEventIndex);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssRaiseWhenTimerExpiresAfter(
    void* S, uint_T timerIndex, bool isRecurring, double dur, uint_T runtimeEventIndex);
SLEXEC_SIMBRIDGE_PUBLISHED_C void
vm_ssRaiseWhenTimerExpiresAt(void* S, uint_T timerIndex, double t, uint_T runtimeEventIndex);
SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssCancelTimerToRaiseEvent(void* S, uint_T timerIndex);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssDummy();

SLEXEC_SIMBRIDGE_PUBLISHED_C uint8_T vm_ssGetEvaluatingF0ForJacobian(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C bool vm_ssGetIsZCEvaluationForRefine(void* S);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetNumTicksToNextHitForControllableSampleTime(void* S,
                                                                               int_T stIdx,
                                                                               double numTicks);

SLEXEC_SIMBRIDGE_PUBLISHED_C void vm_ssSetDenormalBehavior(int_T flag);

SLEXEC_SIMBRIDGE_PUBLISHED_C bool vm_ssGetGlobalInitialStatesAvailable(void* S);

#endif
