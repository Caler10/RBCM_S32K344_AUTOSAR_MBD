#ifndef SLEXEC_EXECUTIONINFO_H
#define SLEXEC_EXECUTIONINFO_H
/**
 * @file slexec_executioninfo.h
 *
 * This header contains execution related parameters
 * which are used in rapid accelerator target.
 *
 */

/* Copyright 2019-2023 The MathWorks, Inc. */

#include "slexec_parallel.h"
#include <setjmp.h>
#include "slexec_simbridge.h"

/* Guard against early inclusions */
#ifndef _SIMSTRUCT
#error "This file should be included from simstruc.h"
#endif

typedef struct {
    void   *ur;                /* columns of inputs: real part        */
    void   *ui;                /* columns of inputs: imag part        */   
    double *time;              /* time vector of each row             */           
    int_T   nTimePoints;        
    int     uDataType;          
    int     rtComplex; 
    int*     currTimeIdx;       /* for interpolation */
    bool    isPeriodicFcnCall; /* Should the TU table be interpreted as a
                                * periodic function call specification */
} rtInportTUtable;

/* File Name Pairs for To File, From File blocks */
typedef struct {
    const char *inputString;
    char       *oldName;
    const char *newName;
    int_T      remapped; /* Used to verify that name was remapped */
} FNamePair;

/*
 * Information associated with either a non-struct data type (in which
 * case rVals and iVals hold the values of all parameters of that data-
 * type) or information associated with a struct-param leaf.
 */
typedef struct {
    /* data attributes */
    int dataType;
    bool complex;
    int dtTransIdx;
    size_t elSize;
    size_t capiIdx;

    /* data */
    size_t nEls;
    void* rVals;
    void* iVals;
    void* vals;

    /* model parameter? */
    bool modelParam;

    /*
     * is ParamInfo associated with a non-struct data-type,
     * or with a struct-param leaf?
     */
    bool structLeaf;

    /* is this parameter of type string? */
    bool isString;
    /* string data */
    mxArray* strVals;

    /* is this parameter of type pointer? */
    bool isPointer;

    /* memory address of the parameter (for struct-param leaves only) */
    void* prmAddr;
} ParamInfo;

typedef struct {
    int errFlag;
    double checksum[4]; /* model checksum */

    /*
     * nTrans is the number of datatypes in the RTP
     * paramInfo will point to array of size nNonStructDataTypes+
     * nStructLeaves (there is one ParamInfo structure for each leaf
     * of every parameter).
     */
    size_t nTrans;
    size_t nNonStructDataTypes;
    size_t nStructLeaves;
    ParamInfo* paramInfo;
} PrmStructData;

/* Information required to initialize/run Execution Engine */
typedef struct ssExecutionInfo_tag {
    /* Root Simstruct */
    SimStruct* simstruct_;

    struct Comm {
        int simServicePID_;
        const char* channelNameColonBufferSize_;
    } comm_; 

    struct SimulationOptions {
        const char* programActiveToken_;
        const char* errorFile_;
        const char* parameterFileName_; /* simulation option parameter file name */
        const char* simMetadataFilePath_;
        const char* inportFileName_;
        const char* errorStatus_;
        const char* matLoggingFilename_;
        const char* matSigstreamLoggingFilename_;
        const char* matSigLogSelectorFilename_;
        const char* simDataRepoFilename_;
        const char* toFileSuffix_;
        const char* paramFilename_;
        const char* liveConnectionsFilename_;
        const char* timeLimit_;           /* time out for executable */
        int parameterArrayIndex_; /* simulation options array index */
        int enableSLExecSSBridgeFeatureValue_;
        int* matFileFormat_;
        int_T numRootInportBlks_;
        boolean_T liveStreaming_;
        boolean_T runningInParallel_;
    } simulationOptions_;

    struct ModelMethods {
        /* model start */
        void (*start)(void);
        /* parameter update function */
        void (*outputsParameterSampleTime)(int);
        /* model terminate */
        void (*terminate)(void);
    } modelMethods_;

    struct RuntimeCallbacks {
        /* external mode call backs */
        ssBridgeExtModeCallbacks_T* externalModeCallbacks_;
        /* logging function */
        void (*loggingFunction)(SimStruct*);
        void (*partialSimOutputFunction)(const char_T*, RTWLogInfo*, boolean_T, boolean_T);
        void (*setupMMIStateLog)(SimStruct*);
        const char* (*startDataLoggingWithStartTime)(
            RTWLogInfo*, const real_T, const real_T, const real_T, const char_T**);
        const char* (*rapidReadInportsAndAperiodicHitTimes)(SimStruct*, const char*, int*);
        const char* (*rapidCheckRemappings)(void);
        void (*sdiBindObserversAndStartStreamingEngine)(const char*);
        double (*nextAperiodicPartitionHitTime)(SimStruct*, double);
        void (*updateParamsFcn)(const SimStruct*);

    } runtimeCallbacks_;

    struct RootIODataMethods {
        void* (*getRootInput)(int /*idx*/);  /* idxth root input buffer */
        void* (*getRootOutput)(int /*idx*/); /* idxth root output buffer */
        int (*getNumRootInputs)(void);
        int (*getNumRootOutputs)(void);
        int (*getRootInputSize)(int);
        int (*getRootOutputSize)(int);
        int (*getRootInputDatatypeSSId)(int idx);
        uint_T const* (*getRootInputDimArray)(int idx);
        int (*getRootInputNumDims)(int idx);
        int (*getRootOutputDatatypeSSId)(int idx);
        uint_T const* (*getRootOutputDimArray)(int idx);
        int (*getRootOutputNumDims)(int idx);
		int (*getRootOutputDataIsComplex)(int idx);
		int (*getRootInputDataIsComplex)(int idx);
        int (*getRootInputPortNumber)(int idx);
        int (*getRootOutputPortNumber)(int idx);
    } rootIODataMethods_;

    struct RuntimeFlags {
        boolean_T* parameterPacketReceived_;
        boolean_T startPacketReceived_;
        const char* sFcnInfoFileName;
        boolean_T simulationTimedOut_;
    } runtimeFlags_;

    struct RuntimeObjects {
        jmp_buf* longJumpBuffer_;
        void* iSigstreamManager_;
    } runtimeObjects_;

    struct ParallelExecution {
        boolean_T enabled_;
        int_T simulatorType_;
        ParallelExecutionOptions options_;
    } parallelExecution_;
    
    struct DeployedExecution {
        boolean_T runningDeployed_;
    } deployedExecution_;

    struct ExecutionOptions {
        boolean_T loadInitialState_;
        void* aperiodicPartitionHitTimes_;
        boolean_T hasTriggeringExternalInputs_;
    } executionOptions_;

    const char* reval_;

    struct Services {
        void* executionServices_;
    } services_;

#ifdef _MSC_VER
    #pragma warning( disable : 4324 ) // disable warning (level 4) to suppress "structure was padded due to alignment specifier" warning message */
#endif
    struct GblObjects {
        rtInportTUtable *inportTUtables;
        FNamePair* toFNamepair;
        FNamePair* frFNamepair;
        jmp_buf rapidAccelJmpBuf;
        char* matSigstreamLoggingFilename;
        char* matSigLogSelectorFilename;
        char* simDataRepoIndex;
        char *inportFileName;
        int_T numToFiles;
        int_T numFrFiles;
        int_T numFrWksBlocks;
        int_T numRootInportBlks;
        int_T numModelInputs;
        int_T* inportDataTypeIdx;
        int_T* inportDims;
        int_T* inportComplex;
        int_T* inportInterpoFlag;
        int_T* inportContinuous;
        int_T  parameterTuningTid;
        const void* mmi;
        PrmStructData paramStruct;
    } gblObjects_;

#ifdef _MSC_VER
    #pragma warning( default : 4324 ) // enable W4 level warnings
#endif
    
} ssExecutionInfo;

/* Get ExecutionInfo from simstruct */
#define ssGetExecutionInfo(S) ((ssExecutionInfo*)((S)->mdlInfo->executionInfo))

/* Set ExecutionInfo on simstruct */
#define ssSetExecutionInfo(S, exInfo) (S)->mdlInfo->executionInfo = (void*)(exInfo); \
(exInfo)->simstruct_ = (S)

/* This macro is used to get the status whether InitialState is set from outside */
#define ssGetGlobalInitialStatesAvailable(S) ssGetExecutionInfo(S)->executionOptions_.loadInitialState_

/* This macro is used to get the aperiodic partition hit times */
#define ssGetExecOptionAperiodicPartitionHitTimes(S) ssGetExecutionInfo(S)->executionOptions_.aperiodicPartitionHitTimes_

#endif

/* LocalWords:  executioninfo idxth
 */
