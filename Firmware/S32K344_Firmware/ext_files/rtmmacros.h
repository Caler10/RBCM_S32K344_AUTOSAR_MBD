/*
 * Copyright 1994-2021 The MathWorks, Inc.
 *
 * File: rtmmacros.h     
 *
 * Abstract:
 * All our real-time simulation wrappers are setup to handle rtModel
 * objects. For targets that still use the SimStruct, this file 
 * provides a mapping from the rtModel to the SimStruct. When all targets
 * use the rtModel, this file can be eliminated.
 */

#ifndef _RTW_HEADER_rtmmacros_h_
# define _RTW_HEADER_rtmmacros_h_

#define rtmGetBlkStateChange            ssGetBlkStateChange
#define rtmSetBlkStateChange            ssSetBlkStateChange
#define rtmGetChecksum0                 ssGetChecksum0
#define rtmSetChecksum0                 ssSetChecksum0
#define rtmGetChecksum1                 ssGetChecksum1
#define rtmSetChecksum1                 ssSetChecksum1
#define rtmGetChecksum2                 ssGetChecksum2
#define rtmSetChecksum2                 ssSetChecksum2
#define rtmGetChecksum3                 ssGetChecksum3
#define rtmSetChecksum3                 ssSetChecksum3
#define rtmGetNumSampleTimes            ssGetNumSampleTimes
#define rtmGetNumContStates             ssGetNumContStates
#define rtmGetContStates                ssGetContStates
#define rtmSetContStates                ssSetContStates
#define rtmIsContinuousTask             ssIsContinuousTask
#define rtmGetDerivCacheNeedsReset      ssGetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset      ssSetDerivCacheNeedsReset
#define rtmGetDiscStates                ssGetDiscStates
#define rtmSetDiscStates                ssSetDiscStates
#define rtmGetErrorStatus               ssGetErrorStatus
#define rtmSetErrorStatus               ssSetErrorStatus
#define rtmGetFixedStepSize             ssGetFixedStepSize
#define rtmSetFixedStepSize             ssSetFixedStepSize
#define rtmGetRTWLogInfo                ssGetRTWLogInfo
#define rtmSetRTWLogInfo                ssSetRTWLogInfo
#define rtmGetRTWExtModeInfo            ssGetRTWExtModeInfo
#define rtmSetRTWExtModeInfo            ssSetRTWExtModeInfo
#define rtmGetMaxNumMinSteps            ssGetMaxNumMinSteps
#define rtmSetMaxNumMinSteps            ssSetMaxNumMinSteps
#define rtmGetMaxStepSize               ssGetMaxStepSize
#define rtmSetMaxStepSize               ssSetMaxStepSize
#define rtmGetMinStepSize               ssGetMinStepSize
#define rtmSetMinStepSize               ssSetMinStepSize
#define rtmGetSolverMaxConsecutiveMinStep   ssGetSolverMaxConsecutiveMinStep
#define rtmSetSolverMaxConsecutiveMinStep   ssSetSolverMaxConsecutiveMinStep
#define rtmGetSolverZcThreshold         ssGetSolverZcThreshold
#define rtmSetSolverZcThreshold         ssSetSolverZcThreshold
#define rtmGetSolverConsecutiveZCsError     ssGetSolverConsecutiveZCsError
#define rtmSetSolverConsecutiveZCsError     ssSetSolverConsecutiveZCsError
#define rtmGetSolverShapePreserveControl   ssGetSolverShapePreserveControl
#define rtmSetSolverShapePreserveControl   ssSetSolverShapePreserveControl
#define rtmGetModelMappingInfo          ssGetModelMappingInfo
#define rtmSetModelMappingInfo          ssSetModelMappingInfo
#define rtmGetOffsetTimePtr             ssGetOffsetTimePtr
#define rtmSetOffsetTimePtr             ssSetOffsetTimePtr
#define rtmGetPerTaskSampleHitsPtr      ssGetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr      ssSetPerTaskSampleHitsPtr
#define rtmIsSampleHit                  ssIsSampleHit
#define rtmSetSampleHitInTask           ssSetSampleHitInTask
#define rtmGetSampleHitPtr              ssGetSampleHitPtr
#define rtmSetSampleHitPtr              ssSetSampleHitPtr
#define rtmGetSampleTime                ssGetSampleTime
#define rtmSetSampleTime                ssSetSampleTime
#define rtmGetSampleTimePtr             ssGetSampleTimePtr
#define rtmSetSampleTimePtr             ssSetSampleTimePtr
#define rtmGetSampleTimeTaskIDPtr       ssGetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr       ssSetSampleTimeTaskIDPtr
#define rtmGetSimMode                   ssGetSimMode
#define rtmSetSimMode                   ssSetSimMode
#define rtmGetSimTimeStep               ssGetSimTimeStep
#define rtmSetSimTimeStep               ssSetSimTimeStep
#define rtmGetSolverAbsTol              ssGetSolverAbsTol
#define rtmSetSolverAbsTol              ssSetSolverAbsTol
#define rtmGetSolverData                ssGetSolverData
#define rtmSetSolverData                ssSetSolverData
#define rtmGetSolverMaxOrder            ssGetSolverMaxOrder
#define rtmSetSolverMaxOrder            ssSetSolverMaxOrder
#define rtmGetSolverConsecutiveZCsStepRelTol   ssGetSolverConsecutiveZCsStepRelTol
#define rtmSetSolverConsecutiveZCsStepRelTol   ssSetSolverConsecutiveZCsStepRelTol
#define rtmGetSolverMaxConsecutiveZCs   ssGetSolverMaxConsecutiveZCs
#define rtmSetSolverMaxConsecutiveZCs   ssSetSolverMaxConsecutiveZCs
#define rtmGetSolverExtrapolationOrder  ssGetSolverExtrapolationOrder
#define rtmSetSolverExtrapolationOrder  ssSetSolverExtrapolationOrder
#define rtmGetSolverNumberNewtonIterations   ssGetSolverNumberNewtonIterations
#define rtmSetSolverNumberNewtonIterations   ssSetSolverNumberNewtonIterations
#define rtmGetSolverMode                ssGetSolverMode
#define rtmSetSolverMode                ssSetSolverMode
#define rtmGetSolverName                ssGetSolverName
#define rtmSetSolverName                ssSetSolverName
#define rtmGetSolverNeedsReset          ssGetSolverNeedsReset
#define rtmSetSolverNeedsReset          ssSetSolverNeedsReset
#define rtmGetSolverRefineFactor        ssGetSolverRefineFactor
#define rtmSetSolverRefineFactor        ssSetSolverRefineFactor
#define rtmGetSolverRelTol              ssGetSolverRelTol
#define rtmSetSolverRelTol              ssSetSolverRelTol
#define rtmGetSolverStopTime            ssGetSolverStopTime
#define rtmSetSolverStopTime            ssSetSolverStopTime
#define rtmGetSolverRobustResetMethod   ssGetSolverRobustResetMethod
#define rtmSetSolverRobustResetMethod   ssSetSolverRobustResetMethod
#define rtmIsSpecialSampleHit           ssIsSpecialSampleHit
#define rtmGetStepSize                  ssGetStepSize
#define rtmSetStepSize                  ssSetStepSize
#define rtmGetStopRequested             ssGetStopRequested
#define rtmSetStopRequested             ssSetStopRequested
#define rtmGetT                         ssGetT
#define rtmSetT                         ssSetT
#define rtmGetTFinal                    ssGetTFinal
#define rtmSetTFinal                    ssSetTFinal
#define rtmGetTPtr                      ssGetTPtr
#define rtmSetTPtr                      ssSetTPtr
#define rtmGetTStart                    ssGetTStart
#define rtmSetTStart                    ssSetTStart
#define rtmGetTaskTime                  ssGetTaskTime
#define rtmSetTaskTime                  ssSetTaskTime
#define rtmGetTimeOfLastOutput          ssGetTimeOfLastOutput
#define rtmSetTimeOfLastOutput          ssSetTimeOfLastOutput
#define rtmGetTimingData                ssGetTimingData
#define rtmSetTimingData                ssSetTimingData
#define rtmGetU                         ssGetU
#define rtmSetU                         ssSetU
#define rtmGetVariableStepSolver        ssGetVariableStepSolver
#define rtmSetVariableStepSolver        ssSetVariableStepSolver
#define rtmGetY                         ssGetY
#define rtmSetY                         ssSetY
#define rtmGetZCCacheNeedsReset         ssGetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset         ssSetZCCacheNeedsReset
#define rtmGetdX                        ssGetdX
#define rtmSetdX                        ssSetdX
#define rtmOutputs                      sfcnOutputs
#define rtmTerminate                    sfcnTerminate
#define rtmInitializeSampleTimes        sfcnInitializeSampleTimes
#define rtmInitializeSizes              sfcnInitializeSizes
#define rtmUpdate                       sfcnUpdate
#define rtmDerivatives                  sfcnDerivatives
#define rtmStart                        sfcnStart
#endif                                  /* _RTW_HEADER_rtmmacros_h_ */

/* [EOF] rtmmacros.h */
