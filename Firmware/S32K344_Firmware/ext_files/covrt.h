/*
 * PUBLISHED header for covrt, the runtime library for Code Coverage
 *
 * Copyright 1984-2023 The MathWorks, Inc.
 *
 */

#ifndef covrt_h
#define covrt_h

#if defined(_MSC_VER)
#pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
#pragma once
#endif

/*
 * Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#endif

#ifndef LIBCOVRT_API
#define LIBCOVRT_API
#endif

#include <setjmp.h>
#include <stdio.h>
#include "matrix.h"


/*
 * MATLAB INTERNAL USE ONLY :: Instance specific runtime data.
 */
typedef struct covrtInstanceData covrtInstanceData;

/*
 * MATLAB INTERNAL USE ONLY :: Instance type
 */
typedef struct covrtInstance {
    covrtInstanceData* data;
} covrtInstance;

/* one instance per mex */
extern covrtInstance gCoverageLoggingInstance;


typedef struct CovrtStateflowData CovrtStateflowData;

typedef struct CovrtStateflowInstance {
    CovrtStateflowData* data;
    double              instanceHandle;
    bool                isCoverageOn;
    bool                isAccelCreated;
} CovrtStateflowInstance;

typedef int CovrtBlockId;
#define COVRT_INVALID_BLOCK_ID -1

/*
 * MATLAB INTERNAL USE ONLY :: Enable/Disable Coverage Logging during mex execution
 */
EXTERN_C LIBCOVRT_API void covrtEnableCoverageLogging(bool enable);


/*
 * MATLAB INTERNAL USE ONLY :: Enabled/Disable use of cv.mex
 */
EXTERN_C LIBCOVRT_API void covrtUseCV(bool useCV);

/*
 * MATLAB INTERNAL USE ONLY :: reset flag
 */
EXTERN_C LIBCOVRT_API void covrtResetUpdateFlag();


/*
 * MATLAB INTERNAL USE ONLY :: Allocate instance data
 */
EXTERN_C LIBCOVRT_API void covrtAllocateInstanceData(covrtInstance* instance);

/*
 * MATLAB INTERNAL USE ONLY :: Free instance data
 */
EXTERN_C LIBCOVRT_API void covrtFreeInstanceData(covrtInstance* instance);

/*
 * MATLAB INTERNAL USE ONLY :: Free instance data
 */
EXTERN_C LIBCOVRT_API mxArray* covrtSerializeInstanceData(covrtInstance* instance);


/*
 * MATLAB INTERNAL USE ONLY :: Coverage engine script initalization callback
 */
EXTERN_C LIBCOVRT_API void covrtScriptStart(covrtInstance* instance,
                                            unsigned int   cvId);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize Script
 */
EXTERN_C LIBCOVRT_API void covrtScriptInit(covrtInstance* instance,
                                           const char*    path,
                                           unsigned int   cvId,
                                           unsigned int   fcnCnt,
                                           unsigned int   basicBlockCnt,
                                           unsigned int   ifCnt,
                                           unsigned int   testobjectiveCnt,
                                           unsigned int   saturationCnt,
                                           unsigned int   switchCnt,
                                           unsigned int   forCnt,
                                           unsigned int   whileCnt,
                                           unsigned int   condCnt,
                                           unsigned int   mcdcCnt);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize Function
 */
EXTERN_C LIBCOVRT_API void covrtFcnInit(covrtInstance* instance,
                                        unsigned int   cvId,
                                        unsigned int   fcnIdx,
                                        const char*    name,
                                        int            charStart,
                                        int            charExprEnd,
                                        int            charEnd);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize Basic Block
 */
EXTERN_C LIBCOVRT_API void covrtBasicBlockInit(covrtInstance* instance,
                                               unsigned int   cvId,
                                               unsigned int   fcnIdx,
                                               int            charStart,
                                               int            charExprEnd,
                                               int            charEnd);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize If
 */
EXTERN_C LIBCOVRT_API void covrtIfInit(covrtInstance* instance,
                                       unsigned int   cvId,
                                       unsigned int   ifIdx,
                                       int            charStart,
                                       int            charExprEnd,
                                       int            charElseStart,
                                       int            charEnd);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize Mcdc
 */
EXTERN_C LIBCOVRT_API void covrtMcdcInit(covrtInstance* instance,
                                         unsigned int   cvId,
                                         unsigned int   mcdcIdx,
                                         int            charStart,
                                         int            charEnd,
                                         int            condCnt,
                                         int            firstCondIdx,
                                         const int*     condStart,
                                         const int*     condEnd,
                                         int            postFixLength,
                                         const int*     postFixExprs);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize Switch
 */
EXTERN_C LIBCOVRT_API void covrtSwitchInit(covrtInstance* instance,
                                           unsigned int   cvId,
                                           unsigned int   switchIdx,
                                           int            charStart,
                                           int            charExprEnd,
                                           int            charEnd,
                                           unsigned int   caseCnt,
                                           const int*     caseStart,
                                           const int*     caseExprEnd);



/*
 * MATLAB INTERNAL USE ONLY :: Initialize For
 */
EXTERN_C LIBCOVRT_API void covrtForInit(covrtInstance* instance,
                                        unsigned int   cvId,
                                        unsigned int   forIdx,
                                        int            charStart,
                                        int            charExprEnd,
                                        int            charEnd);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize While
 */
EXTERN_C LIBCOVRT_API void covrtWhileInit(covrtInstance* instance,
                                          unsigned int   cvId,
                                          unsigned int   whileIdx,
                                          int            charStart,
                                          int            charExprEnd,
                                          int            charEnd);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize MCDC
 */
EXTERN_C LIBCOVRT_API void covrtMCDCInit(covrtInstance* instance,
                                         unsigned int   cvId,
                                         unsigned int   mcdcIdx,
                                         int            charStart,
                                         int            charEnd,
                                         unsigned int   condCnt,
                                         unsigned int   firstCondIdx,
                                         const int*     condStart,
                                         const int*     condEnd,
                                         unsigned int   pfxLength,
                                         const int*     pfixExpr);

/*
 * MATLAB INTERNAL USE ONLY :: Log Function
 */
EXTERN_C LIBCOVRT_API void covrtLogFcn(covrtInstance* instance,
                                       uint32_T       covId,
                                       uint32_T       fcnId);

/*
 * MATLAB INTERNAL USE ONLY :: Log Basic Block
 */
EXTERN_C LIBCOVRT_API void covrtLogBasicBlock(covrtInstance* instance,
                                              uint32_T       covId,
                                              uint32_T       basicBlockId);

/*
 * MATLAB INTERNAL USE ONLY :: Log If
 */
EXTERN_C LIBCOVRT_API int32_T covrtLogIf(covrtInstance* instance,
                                         uint32_T       covId,
                                         uint32_T       fcnId,
                                         int32_T        ifId,
                                         int32_T        condition);

/*
 * MATLAB INTERNAL USE ONLY :: Log Cond
 */
EXTERN_C LIBCOVRT_API int32_T covrtLogCond(covrtInstance* instance,
                                           uint32_T       covId,
                                           uint32_T       fcnId,
                                           int32_T        condId,
                                           int32_T        condition);

/*
 * MATLAB INTERNAL USE ONLY :: Log If
 */
EXTERN_C LIBCOVRT_API void covrtLogFor(covrtInstance* instance,
                                       uint32_T       covId,
                                       uint32_T       fcnId,
                                       int32_T        forId,
                                       int32_T        entryOrExit);

/*
 * MATLAB INTERNAL USE ONLY :: Log While
 */
EXTERN_C LIBCOVRT_API int32_T covrtLogWhile(covrtInstance* instance,
                                            uint32_T       covId,
                                            uint32_T       fcnId,
                                            int32_T        whileId,
                                            int32_T        condition);

/*
 * MATLAB INTERNAL USE ONLY :: Log Switch
 */
EXTERN_C LIBCOVRT_API void covrtLogSwitch(covrtInstance* instance,
                                          uint32_T       covId,
                                          uint32_T       fcnId,
                                          int32_T        switchId,
                                          int32_T        caseId);

/*
 * MATLAB INTERNAL USE ONLY :: Log If
 */
EXTERN_C LIBCOVRT_API int32_T covrtLogMcdc(covrtInstance* instance,
                                           uint32_T       covId,
                                           uint32_T       fcnId,
                                           int32_T        mcdcId,
                                           int32_T        condition);

/*
 * MATLAB INTERNAL USE ONLY :: Log decision in block
 */
EXTERN_C LIBCOVRT_API int32_T covrtLogBlockDec(covrtInstance* instance,
                                               uint32_T       covId,
                                               int32_T        decId,
                                               int32_T        eleIdx,
                                               int32_T        decVal);

/*
 * MATLAB INTERNAL USE ONLY :: Simulink block coverage
 */

EXTERN_C LIBCOVRT_API void covrtSimulinkSessionInit(void* sessionInterface);
EXTERN_C LIBCOVRT_API void covrtSimulinkSessionCleanup();
EXTERN_C LIBCOVRT_API void covrtSimulinkSetTopModelInterface(void* cvTopModelInterface);
EXTERN_C LIBCOVRT_API void covrtSimulinkRegisterBlock(double blockHandle);
EXTERN_C LIBCOVRT_API bool covrtIsBlockRegistered(double blockHandle);

EXTERN_C LIBCOVRT_API void covrtMarkSkipInitCovRecording(const char* model);
EXTERN_C LIBCOVRT_API void covrtMarkModelInitialized(const char* model);
EXTERN_C LIBCOVRT_API bool covrtIsModelInitialized(const char* model);
EXTERN_C LIBCOVRT_API void covrtMarkModelStarted(const char* model);
EXTERN_C LIBCOVRT_API bool covrtIsModelStarted(const char* model);
EXTERN_C LIBCOVRT_API void covrtMarkModelTerminated(const char* model);
EXTERN_C LIBCOVRT_API bool covrtIsModelTerminated(const char* model);

EXTERN_C LIBCOVRT_API void covrtSimulinkBlockCovInit(const char* model, int blockSysIdx, int blockIdx, const char* blockSID, bool updateAtStart);
EXTERN_C LIBCOVRT_API void covrtSimulinkDecCovInit(const char* model, int blockSysIdx, int blockIdx, const char* blockPath, int64_T vecSize, int64_T numOutcomes, uint32_T outcomeOffset, const char* decDescr, const char* outcomeStrId, const char* customText, bool hasVariableOutcomes, int64_T offset, bool useModifiedComplexityVal, bool collapseVector, const char** outcomeStrs, uint32_T outcomeStrSize, const char** descrVec, uint32_T descrVecSize);
EXTERN_C LIBCOVRT_API void covrtSimulinkDecInterlacedCovInit(const char* model, int blockSysIdx, int blockIdx, const char* blockSID, int64_T vecSize, int64_T numOutcomes, uint32_T outcomeOffset, const char* decDescr, const char* outcomeStrId, const char* customText, bool hasVariableOutcomes, int64_T offset, bool useModifiedComplexityVal, bool collapseVector, const char** outcomeStrs, uint32_T outcomeStrSize, const char** descrVec, uint32_T descrVecSize, const char** decisionInterlacedDescr, const char** customInterlacedTxt);
EXTERN_C LIBCOVRT_API void covrtSimulinkCondCovInit(const char* model, int blockSysIdx, int blockIdx, const char* blockPath, int64_T numOfConditions, const char* conditionDescr, uint32_T numOfMcdcs, const char* mcdcDescr, bool isCascMCDC, uint32_T maxDescrParams, bool hasVariableSize, int mcdcExprType, const char** descrVec, const int64_T* descrIdxVec, uint32_T descrVecSize, const char** opDesc, uint32_T opDescSize);
EXTERN_C LIBCOVRT_API void covrtSimulinkBlockInitCovRecording(const char* model, const char** blockPathsVec, const uint32_T blockPathsVecSize);
EXTERN_C LIBCOVRT_API void covrtSimulinkBlockCovRecord(const char* model, int blockSysIdx, int blockIdx);
EXTERN_C LIBCOVRT_API void covrtSimulinkDecCovRecord(const char* model, int blockSysIdx, int blockIdx, int checkExprVal, int64_T vecId, bool isOutcomesListPresent, int outcomeIdx);
EXTERN_C LIBCOVRT_API void covrtSimulinkDecInterlacedCovRecord(const char* model, int blockSysIdx, int blockIdx, bool outcomeVal, int interlacedIdx, int64_T vecId);
EXTERN_C LIBCOVRT_API void covrtSimulinkCondCovRecord(const char* model, int blockSysIdx, int blockIdx, bool outcomeVal, int condOffset, int64_T vecId);
EXTERN_C LIBCOVRT_API void covrtSimulinkMCDCInpCovRecord(const char* model, int blockSysIdx, int blockIdx, bool outcomeVal, int condOffset, int64_T vecId);
EXTERN_C LIBCOVRT_API void covrtSimulinkMCDCOutCovRecord(const char* model, int blockSysIdx, int blockIdx, bool outcomeVal);

EXTERN_C LIBCOVRT_API void covrtModelInit(const char* modelName);
EXTERN_C LIBCOVRT_API void covrtModelStart(const char* modelName);
EXTERN_C LIBCOVRT_API void covrtModelFastRestart(const char* modelName);
EXTERN_C LIBCOVRT_API void covrtModelTerm(const char* modelName);
EXTERN_C LIBCOVRT_API void covrtModelTermAll();

/*
 * MATLAB INTERNAL USE ONLY :: Stateflow coverage instance
 */

EXTERN_C LIBCOVRT_API
    CovrtStateflowInstance*
    covrtAllocateStateflowInstance(
        CovrtStateflowInstance* instance,
        const char*             chartPath);

EXTERN_C LIBCOVRT_API
    CovrtStateflowInstance*
    covrtDeleteStateflowInstance(CovrtStateflowInstance* instance);

EXTERN_C LIBCOVRT_API void covrtCreateStateflowInstanceData(CovrtStateflowInstance* instance,
                                                            unsigned int            stateCount,
                                                            unsigned int            eventCount,
                                                            unsigned int            transCount,
                                                            unsigned int            dataCount);

EXTERN_C LIBCOVRT_API void covrtSetInstanceCvIds(
    double       instanceHandle,
    unsigned int cvChartId,
    double*      cvStateIds,
    size_t       stateCnt,
    double*      cvTransIds,
    size_t       transCnt);

EXTERN_C LIBCOVRT_API void covrtSetEmlScriptCvIds(double  instanceHandle,
                                                  double* numToCvIdMap,
                                                  size_t  size);

EXTERN_C LIBCOVRT_API void covrtDeleteStateflowInstanceData(CovrtStateflowInstance* instance);


EXTERN_C LIBCOVRT_API void covrtRelationalopInitFcn(
    CovrtStateflowInstance* instance,
    unsigned int            transitionNumber,
    unsigned int            relopCnt,
    const int*              txtStartIdx,
    const int*              txtEndIdx,
    const int*              relationalEps,
    const int*              relationalOp);

EXTERN_C LIBCOVRT_API void covrtSaturationInitFcn(
    CovrtStateflowInstance* instance,
    unsigned int            objectType,
    unsigned int            transitionNumber,
    unsigned int            satCnt,
    const unsigned int*     txtStartIdx,
    const unsigned int*     txtEndIdx);

EXTERN_C LIBCOVRT_API void covrtTestobjectiveInitFcn(CovrtStateflowInstance* instance,
                                                     unsigned int            objectType,
                                                     unsigned int            objectNumber,
                                                     unsigned int            testobjectiveCnt,
                                                     const unsigned int*     txtStartIdx,
                                                     const unsigned int*     txtEndIdx);


EXTERN_C LIBCOVRT_API void covrtTransInitFcn(CovrtStateflowInstance* instance,
                                             unsigned int            transitionNumber,
                                             int                     predicateCnt,
                                             const unsigned int*     txtStartIdx,
                                             const unsigned int*     txtEndIdx,
                                             unsigned int            postFixPredicateTreeCount,
                                             const int*              postFixPredicateTree);

EXTERN_C LIBCOVRT_API void covrtStateInitFcn(CovrtStateflowInstance* instance,
                                             unsigned int            stateNumber,
                                             unsigned int            numChild,
                                             bool                    hasDuringSwitch,
                                             bool                    hasExitSwitch,
                                             bool                    hasHistSwitch,
                                             unsigned int            onDecCnt,
                                             const unsigned int*     decStartInd,
                                             const unsigned int*     decEndInd);

EXTERN_C LIBCOVRT_API void covrtChartInitFcn(CovrtStateflowInstance* instance,
                                             unsigned int            numChild,
                                             bool                    hasDuringSwitch,
                                             bool                    hasExitSwitch,
                                             bool                    hasHistSwitch);

EXTERN_C LIBCOVRT_API void covrtAssignmentInitFcn(CovrtStateflowInstance* instance,
                                                  unsigned int            objectType,
                                                  unsigned int            objectNumber,
                                                  unsigned int            numAssignments,
                                                  const int*              assignmentKeys,
                                                  const unsigned int*     assignTxtStartIdx,
                                                  const unsigned int*     assignTxtEndIdx,
                                                  unsigned int            numTotalConditions,
                                                  const int*              conditionKeys,
                                                  const unsigned int*     condTxtStartIdx,
                                                  const unsigned int*     condTxtEndIdx,
                                                  unsigned int            postFixPredicateTreeConcatCount,
                                                  const int*              postFixPredicateTreeConcat,
                                                  const unsigned int*     condTextIdxOffsets,
                                                  const unsigned int*     pptIdxOffsets);

EXTERN_C LIBCOVRT_API unsigned int covrtTestobjectiveUpdateFcn(CovrtStateflowInstance* instance,
                                                               unsigned int            objectType,
                                                               unsigned int            objectNumber,
                                                               unsigned int            objectIndex,
                                                               int                     retValue);

EXTERN_C LIBCOVRT_API bool covrtAssignmentUpdateFcn(CovrtStateflowInstance* instance,
                                                    unsigned int            objectType,
                                                    unsigned int            objectNumber,
                                                    unsigned int            objectIndex,
                                                    unsigned int            retValue);


EXTERN_C LIBCOVRT_API unsigned int covrtRelationalopUpdateFcn(CovrtStateflowInstance* instance,
                                                              unsigned int            objectType,
                                                              unsigned int            objectNumber,
                                                              unsigned int            objectIndex,
                                                              double                  lhsVal,
                                                              double                  rhsVal,
                                                              int                     relationalopEps,
                                                              unsigned int            op,
                                                              int                     retValue);

EXTERN_C LIBCOVRT_API bool covrtSaturationUpdateFcn(CovrtStateflowInstance* instance,
                                                    unsigned int            objectType,
                                                    unsigned int            objectNumber,
                                                    unsigned int            satIdx,
                                                    unsigned int            isNeg,
                                                    int                     val);

EXTERN_C LIBCOVRT_API void covrtSaturationUpdateAccumFcn(CovrtStateflowInstance* instance,
                                                         unsigned int            objectType,
                                                         unsigned int            objectNumber,
                                                         unsigned int            satIdx,
                                                         unsigned int            accumMode);

EXTERN_C LIBCOVRT_API bool covrtDecUpdateFcn(CovrtStateflowInstance* instance,
                                             unsigned int            objectType,
                                             unsigned int            objectNumber,
                                             unsigned int            objectIndex,
                                             unsigned int            retValue);

EXTERN_C LIBCOVRT_API bool covrtTransitionDecUpdateFcn(CovrtStateflowInstance* instance,
                                                       unsigned int            objectType,
                                                       unsigned int            objectNumber,
                                                       unsigned int            objectIndex,
                                                       bool                    retValue);

EXTERN_C LIBCOVRT_API unsigned int covrtBasicBlockUpdateFcn(CovrtStateflowInstance* instance,
                                                            unsigned int            objectType,
                                                            unsigned int            objectNumber,
                                                            unsigned int            objectIndex);

EXTERN_C LIBCOVRT_API bool covrtCondUpdateFcn(CovrtStateflowInstance* instance,
                                              unsigned int            objectType,
                                              unsigned int            objectNumber,
                                              unsigned int            objectIndex,
                                              bool                    retValue);

EXTERN_C LIBCOVRT_API unsigned int covrtSigUpdateFcn(CovrtStateflowInstance* instance,
                                                     unsigned int            dataNumber,
                                                     double                  equivValue);
/*
 * MATLAB INTERNAL USE ONLY :: EML coverage instance
 */
EXTERN_C LIBCOVRT_API unsigned int covrtEmlInitFcn(CovrtStateflowInstance* instance,
                                                   const char*             path,
                                                   unsigned int            objectType,
                                                   unsigned int            objectNumber,
                                                   unsigned int            fcnCnt,
                                                   unsigned int            basicBlockCnt,
                                                   unsigned int            ifCnt,
                                                   unsigned int            testobjectiveCnt,
                                                   unsigned int            saturationCnt,
                                                   unsigned int            switchCnt,
                                                   unsigned int            forCnt,
                                                   unsigned int            whileCnt,
                                                   unsigned int            condCnt,
                                                   unsigned int            mcdcCnt);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlFcnInitFcn(CovrtStateflowInstance* instance,
                                                      unsigned int            objectType,
                                                      unsigned int            objectNumber,
                                                      unsigned int            fcnIdx,
                                                      const char*             name,
                                                      int                     charStart,
                                                      int                     charExprEnd,
                                                      int                     charEnd);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlTestobjectiveInitFcn(CovrtStateflowInstance* instance,
                                                                unsigned int            objectType,
                                                                unsigned int            objectNumber,
                                                                unsigned int            objIdx,
                                                                const char*             name,
                                                                int                     charStart,
                                                                int                     charExprEnd,
                                                                int                     charEnd);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlSaturationInitFcn(CovrtStateflowInstance* instance,
                                                             unsigned int            objectType,
                                                             unsigned int            objectNumber,
                                                             unsigned int            objIdx,
                                                             int                     charStart,
                                                             int                     charExprEnd,
                                                             int                     charEnd);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlIfInitFcn(CovrtStateflowInstance* instance,
                                                     unsigned int            objectType,
                                                     unsigned int            objectNumber,
                                                     unsigned int            ifIdx,
                                                     int                     charStart,
                                                     int                     charExprEnd,
                                                     int                     charElseStart,
                                                     int                     charEnd,
                                                     bool                    isPositiveOnly);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlSwitchInitFcn(CovrtStateflowInstance* instance,
                                                         unsigned int            objectType,
                                                         unsigned int            objectNumber,
                                                         unsigned int            switchIdx,
                                                         int                     charStart,
                                                         int                     charExprEnd,
                                                         int                     charEnd,
                                                         unsigned int            caseCnt,
                                                         const int*              caseStart,
                                                         const int*              caseExprEnd);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlForInitFcn(CovrtStateflowInstance* instance,
                                                      unsigned int            objectType,
                                                      unsigned int            objectNumber,
                                                      unsigned int            forIdx,
                                                      int                     charStart,
                                                      int                     charExprEnd,
                                                      int                     charEnd);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlWhileInitFcn(CovrtStateflowInstance* instance,
                                                        unsigned int            objectType,
                                                        unsigned int            objectNumber,
                                                        unsigned int            whileIdx,
                                                        int                     charStart,
                                                        int                     charExprEnd,
                                                        int                     charEnd);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlMCDCInitFcn(CovrtStateflowInstance* instance,
                                                       unsigned int            objectType,
                                                       unsigned int            objectNumber,
                                                       unsigned int            mcdcIdx,
                                                       int                     charStart,
                                                       int                     charEnd,
                                                       unsigned int            condCnt,
                                                       unsigned int            firstCondIdx,
                                                       const int*              condStart,
                                                       const int*              condEnd,
                                                       unsigned int            pfxLength,
                                                       const int*              pfixExpr,
                                                       bool                    isPositiveOnly);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlRelationalInitFcn(CovrtStateflowInstance* instance,
                                                             unsigned int            objectType,
                                                             unsigned int            objectNumber,
                                                             unsigned int            objIdx,
                                                             int                     charStart,
                                                             int                     charEnd,
                                                             int                     relationalEps,
                                                             unsigned int            relationalOp);
/*
 * MATLAB INTERNAL USE ONLY :: EML coverage eval functions
 */
EXTERN_C LIBCOVRT_API unsigned int covrtEmlFcnEval(CovrtStateflowInstance* instance,
                                                   unsigned int            objectType,
                                                   unsigned int            objectNumber,
                                                   unsigned int            objectIndex);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlTestobjectiveEval(CovrtStateflowInstance* instance,
                                                             unsigned int            objectType,
                                                             unsigned int            objectNumber,
                                                             unsigned int            objectIndex,
                                                             unsigned int            retValue);


EXTERN_C LIBCOVRT_API bool covrtEmlIfEval(CovrtStateflowInstance* instance,
                                          unsigned int            objectType,
                                          unsigned int            objectNumber,
                                          unsigned int            objectIndex,
                                          unsigned int            retValue);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlForEval(CovrtStateflowInstance* instance,
                                                   unsigned int            objectType,
                                                   unsigned int            objectNumber,
                                                   unsigned int            objectIndex,
                                                   unsigned int            retValue);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlWhileEval(CovrtStateflowInstance* instance,
                                                     unsigned int            objectType,
                                                     unsigned int            objectNumber,
                                                     unsigned int            objectIndex,
                                                     unsigned int            retValue);

EXTERN_C LIBCOVRT_API unsigned int covrtEmlSwitchEval(CovrtStateflowInstance* instance,
                                                      unsigned int            objectType,
                                                      unsigned int            objectNumber,
                                                      unsigned int            objectIndex,
                                                      unsigned int            retValue);

EXTERN_C LIBCOVRT_API bool covrtEmlCondEval(CovrtStateflowInstance* instance,
                                            unsigned int            objectType,
                                            unsigned int            objectNumber,
                                            unsigned int            objectIndex,
                                            unsigned int            retValue);

EXTERN_C LIBCOVRT_API bool covrtEmlMcdcEval(CovrtStateflowInstance* instance,
                                            unsigned int            objectType,
                                            unsigned int            objectNumber,
                                            unsigned int            objectIndex,
                                            unsigned int            retValue);


#endif /* covrt_h */
