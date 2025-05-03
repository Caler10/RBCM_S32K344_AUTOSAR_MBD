/* Copyright 1990-2023 The MathWorks, Inc. */

/**
 * @file: simstruc_def.h
 *
 * @brief SimStruct structure definitions
 *
 */

#ifndef __SIMSTRUC__DEF
#define __SIMSTRUC__DEF

#include "simstruc_types.h"
#include "simstruc_internal_types.h"

/*===============================*
 * Defines for S-function blocks *
 *===============================*/

/*
 * DYNAMICALLY_SIZED - Specify for sizes entries that inherit their values
 * from the block that drives them.
 * SIMSTRUCT_VERSION - An integer which is the sizeof the SimStruct times
 * 10000 plus the version times 100. When updating version numbers within the
 * Matlab image, increment both level 1 and level 2 S-functions. Level 1
 * version cannot be in range 220 to 229.  This was the level 2 version in
 * Simulink 2.20 (R10)
 *
 * DYNAMIC_DIMENSION - Specify for input/output port dimension entries that
 * the port inherits its dimension from the block that drives it.
 */

#define ALWAYS_NEEDED (0)
#define CONDITIONALLY_NEEDED (1)
#define NEVER_NEEDED (2)

#define ALWAYS_REFRESHED (0)
#define CONDITIONALLY_REFRESHED (1)
#define NEVER_REFRESHED (2)

#define SIMSTRUCT_VERSION_LEVEL1 (sizeof(SimStruct) * 10000 + 214)
#define SIMSTRUCT_VERSION_LEVEL2 (sizeof(SimStruct) * 10000 + 229)

#include "sl_common_types_def.h"

#if SS_SL_INTERNAL
#if defined(RSIM_WITH_SL_SOLVER)
#define DISABLED_VARIABLE_NEXT_TIME rtMinusInf
#else
#define DISABLED_VARIABLE_NEXT_TIME (utGetMinusInf())
#endif
#endif

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssSetSimulinkVersionGeneratedIn(S, ver)                                            \
    {                                                                                      \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_SIMULINK_VERSION_GENERATED_IN, 0, \
                                        (void*)(ver)) _ssSafelyCallGenericFcnEnd;          \
    }

#else
#define ssSetSimulinkVersionGeneratedIn(S, ver)
#endif

/*
 * Task ID's ordering
 *      Continuous task
 *      Continuous but fixed in minor step task
 *      Discrete task 1
 *         ...
 *      Discrete task N
 *      Variable sample time task(s), offset is instance number.
 *
 * If continuous task is present then it's task ID is 0, otherwise the
 * first discrete task ID will be 0 if it is present, etc.
 * All blocks with varying sample times have same sample task period of -2,
 * and the offset is the instance number.
 *
 * The triggered blocks are not in the sample time table and have a task ID
 * of -1.
 */

#define CONSTANT_TID (-2)
#define GENERIC_ASYNC_TID (-3)
#define COMPOSITE_TID (-4)
#define PARAMETER_TUNING_TID (-5)

/*==========================================================================*
 * PropagationPassType - used to distinguish for pass initialization
 * If you add or update PropagationPassType, update simulink/sl_types_compile.hpp too
 *==========================================================================*/
#ifndef _PROPAGATIONPASSTYPE
#define _PROPAGATIONPASSTYPE
typedef enum {
    DIMENSION_PROPAGATION,
    TYPE_PROPAGATION,
    COMPLEX_PROPAGATION,
    UNIT_PROPAGATION
} PropagationPassType;
#endif

/*===============================================*
 * General defines used only by the macros below *
 *===============================================*/


/*
 * Conversion routines for frame data storage
 */
#define NEG1_2BITS '\x03'
#define CONV_BITS2INT(val) \
    ((((val)&2U) != 0U) ? FRAME_INHERITED : (((val)&1U) != 0U) ? FRAME_YES : FRAME_NO)
#define CONV_INT2BITS(val) (((val) == FRAME_INHERITED) ? (NEG1_2BITS) : ((val)&1U))

/*
 * Conversion routines for dimensions mode storage
 */
#define CONV_BITS2DIMSMODE(val)                \
    ((((val)&2U) != 0)    ? INHERIT_DIMS_MODE  \
     : (((val)&1U) != 0U) ? VARIABLE_DIMS_MODE \
                          : FIXED_DIMS_MODE)
#define CONV_DIMSMODE2BITS(val) (((val) == INHERIT_DIMS_MODE) ? (NEG1_2BITS) : ((val)&1U))

/*
 * Conversion routines for bus mode storage
 */
#define CONV_BITS2BUSMODE(val) \
    ((((val)&2U) != 0) ? SL_INHERIT_BUS_MODE : (((val)&1U) != 0U) ? SL_BUS_MODE : SL_NON_BUS_MODE)
#define CONV_BUSMODE2BITS(val) (((val) == SL_INHERIT_BUS_MODE) ? (NEG1_2BITS) : ((val)&1U))

/*=================================================================*
 * Defines used by Simulink.c when calling the S-function routines *
 *=================================================================*/
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define SS_CALL_MDL_INITIALIZE_SAMPLE_TIMES 101
#define SS_CALL_MDL_INITIALIZE_CONDITIONS 102
#define SS_CALL_MDL_GET_TIME_OF_NEXT_VAR_HIT 103
#define SS_CALL_MDL_OUTPUTS 104
#define SS_CALL_MDL_UPDATE 105
#define SS_CALL_MDL_DERIVATIVES 106
#define SS_CALL_MDL_TERMINATE 107
#define SS_CALL_MDL_ZERO_CROSSINGS 108
#define SS_CALL_MDL_GET_INPUT_PORT_WIDTH 109
#define SS_CALL_MDL_GET_OUTPUT_PORT_WIDTH 110
#define SS_CALL_MDL_SET_WORK_WIDTHS 111
#define SS_CALL_MDL_CHECK_PARAMETERS 112
#define SS_CALL_MDL_SET_INPUT_PORT_DATA_TYPE 113
#define SS_CALL_MDL_SET_OUTPUT_PORT_DATA_TYPE 114
#define SS_CALL_MDL_SET_INPUT_PORT_WIDTH 115
#define SS_CALL_MDL_SET_OUTPUT_PORT_WIDTH 116
#define SS_CALL_MDL_START 117
#define SS_CALL_MDL_PROCESS_PARAMETERS 118
#define SS_CALL_MDL_RTW 119
#define SS_CALL_MDL_SET_INPUT_PORT_COMPLEX_SIGNAL 120
#define SS_CALL_MDL_SET_OUTPUT_PORT_COMPLEX_SIGNAL 121
#define SS_CALL_MDL_SET_INPUT_PORT_SAMPLE_TIME 122
#define SS_CALL_MDL_SET_OUTPUT_PORT_SAMPLE_TIME 123
#define SS_CALL_RTW_GENERATED_ENABLE 124
#define SS_CALL_RTW_GENERATED_DISABLE 125
#define SS_CALL_MDL_SET_INPUT_PORT_DIMENSION_INFO 126
#define SS_CALL_MDL_SET_OUTPUT_PORT_DIMENSION_INFO 127
#define SS_CALL_MDL_SET_INPUT_PORT_FRAME_DATA 128
#define SS_CALL_MDL_PROJECTION 129
#define SS_CALL_MDL_JACOBIAN 130
#define SS_CALL_MDL_SET_DEFAULT_PORT_DIMENSION_INFO 131
#define SS_CALL_MDL_SET_DEFAULT_PORT_DATA_TYPES 132
#define SS_CALL_MDL_SET_DEFAULT_PORT_COMPLEX_SIGNALS 133
#define SS_CALL_MDL_EXT_MODE_EXEC 134
#define SS_CALL_MDL_RTWCG 135
#define SS_CALL_MDL_MASSMATRIX 136
#define SS_CALL_MDL_FORCINGFUNCTION 137
/*       UNUSED                                      138 */
#define SS_CALL_MDL_ENABLE 139
#define SS_CALL_MDL_DISABLE 140
#define SS_CALL_MDL_SIM_STATUS_CHANGE 141
#define SS_CALL_MDL_INITIALIZE_PROPAGATION_PASS 142
#define SS_CALL_MDL_CONSTRAINTS 143
#define SS_CALL_MDL_GET_SIM_STATE 144
#define SS_CALL_MDL_SET_SIM_STATE 145
#define SS_CALL_MDL_INIT_SYSTEM_MATRICES 146
#define SS_CALL_MDL_FINALIZE_ALL_DIMS 147
#define SS_CALL_MDL_JACOBIANIRJC 148
#define SS_CALL_MDL_SET_INPUT_PORT_SYMBOLIC_DIMENSIONS 149
#define SS_CALL_MDL_SET_OUTPUT_PORT_SYMBOLIC_DIMENSIONS 150
#define SS_CALL_MDL_SETUP_RUNTIME_RESOURCES 151
#define SS_CALL_MDL_CLEANUP_RUNTIME_RESOURCES 152
#define SS_CALL_MDL_PRE_INITIALIZE 153
#define SS_CALL_MDL_COPY_RTP_DATA 154
#endif


/*==================================*
 * Structures with in the SimStruct *
 *==================================*/

typedef struct ssSparseMatrixInfo_tag {
    int_T mRows; /* number of rows   */
    int_T nCols; /* number of cols   */
    int_T nzMax; /* size of *pr, *ir */
    int_T* Ir;   /* row indices      */
    int_T* Jc;   /* column offsets   */
    real_T* Pr;  /* nonzero entries  */
} ssSparseMatrixInfo;


/* For Backward compatibility with R12Lcs */
#define SS_UNORIENTED_OR_COL_VECT SS_1_D_OR_COL_VECT
#define SS_UNORIENTED_OR_ROW_VECT SS_1_D_OR_ROW_VECT
#define SS_UNORIENTED_ROW_OR_COL_VECT SS_1_D_ROW_OR_COL_VECT
#define SS_UNORIENTED_VECT SS_1_D_VECT

/*
 * _ssSizes - valid in all SimStruct's. There is one sizes for a level-1
 * S-function and another sizes for a level 2 S-function.
 */

struct _ssSizes {
    int_T numContStates; /* number of continuous states                    */
    int_T numDiscStates; /* number of discrete states                      */
    union {
        int_T numOutputPorts; /* number of output ports for S-functions         */
        int_T numY;           /* Length of the external output vector for models
                                 i.e. the sum of the widths of the outports.
                                 For level 1 S-functions, this is the output
                                 port width.                                    */
    } out;
    union {
        int_T numInputPorts; /* number of input ports for S-functions          */
        int_T numU;          /* Length of the external input vector for models
                                i.e. the sum of the widths of the inports.
                                For level 1 S-functions, this is the input
                                port width.                                    */
    } in;
    int_T mexApiInt1; /* reserved for use by Simulink mex api         */

    int_T sysDirFeedThrough; /* Not used by s-functions - only for root models */


    int_T numSampleTimes; /* # of different sample times and/or time offsets*/
    int_T numSFcnParams;  /* number of external matrices passed in          */

    /* -------- Work vectors ------------------------ */
    int_T numIWork; /* size of integer work vector                    */
    int_T numRWork; /* size of real_T precision work vector           */
    int_T numPWork; /* size of pointer work vector                    */

    /* -------- Block counts ------------------------ */
    int_T numBlocks;     /* number of Blocks in the model                  */
    int_T numSFunctions; /* number of S-Functions                          */

    /* -------- Model bookkeeping ------------------- */
    int_T numBlockIO;      /* number of block outputs                        */
    int_T numBlockParams;  /* number of block parameters                     */
    uint32_T checksums[4]; /* Checksums  of model                            */

    /* -------- Version ----------------------------- */
    int32_T simStructVer; /* SimStruct version                              */

    /* -------- Zero Crossings ---------------------- */
    int_T numNonsampledZCs; /* number of non-sampled zero crossings            */
    int_T reservedInt;

    /* -------- Modes ------------------------------- */
    int_T numModes; /* number of modes                                */

    /* -------- Configuration options --------------- */
    uint32_T options; /* General options                                */


    /* -------- Vector Sizes In Bytes  -------------- */

    int_T sizeofY; /* Sizeof of external input, Y, in bytes          */
    int_T sizeofU; /* Sizeof of external input, U, in bytes          */
    int_T reservedInt2;

    int_T reservedInt3;

    int_T numDWork; /* size of data type work vectors                 */
    int_T reservedInt4;
    int_T RTWGeneratedSFcn; /* Flag which is set for rtw generated s-function */
                            /* Remove once all dstates are changed to dworks  */
                            /* ------------- Reserved ------------------------*/
    struct {
        unsigned int hasMdlDimensionsFcn : 1; /* uses width or dimension method*/
        unsigned int usesNumPorts : 1;        /* used for distinguishing between
                                                 union fields in. and out. */
        unsigned int vectMode : 4;            /* used in set dimension methods */
        unsigned int blockReduction : 1;      /* used to request blk reduction */
        unsigned int treatAsAtomic : 1;       /* used to treat block as atomic
                                                 subsystem */
        unsigned int rtwcg : 1;               /* supports CGIR */
        unsigned int needAbsoluteTime : 1;
        unsigned int explicitFCSSCtrl : 1; /* used for explicit fcncall orig */

        unsigned int modelRefTsInhSupLevel : 2; /* used for determining if a model
                                                 * can inherit a sample time when it
                                                 * is used as a block*/
        unsigned int needElapseTime : 1;
        unsigned int hasSubFunctions : 1;
        unsigned int callsOutputInInit : 1;
        /* mdlProjection may be present, but we may not want to call it */
        unsigned int disableMdlProjection : 1;

        unsigned int modelRefNormalModeSupport : 2;
        unsigned int simStateCompliance : 4;
        unsigned int simStateVisibility : 1;
        /* Use JacobianFcn in places of SlvrJacobianFcn */
        unsigned int disableMdlSlvrJacobian : 1;

        /* Used to check if rapid accelerator is active */
        unsigned int isRapidAcceleratorActive : 1;
        unsigned int isConcurrentTasks : 1;

        unsigned int usesCustomCodeFcns : 1;
        unsigned int crlReplacementEnabled : 1;

        unsigned int vmSimulationsCompliance : 3;

        /* each bit field has to be no more than 16 bits!  (some targets, for ex,
           TI 2000, do not support more than 16 bits per single field */
    } flags;

    int_T numJacobianNzMax; /* number of nonzero elements in sparse Jacobian  */

    void* rtModel;            /* rtModel pointer */
    const void* constBlockIO; /* Pointer to invariant signals */

    /*
     * The funky statements below were necessitated because we originally
     * had 5 reserved integer fields. In order to get a (void *) field
     * we need one int on certain platforms and two on others. To
     * overcome this, we have the definition below.
     *
     * Note that there is only ONE remaining reserved int (for alpha
     * anyway, there are 3 on other platforms i.e. the ones where
     * sizeof(int) = sizeof(void*) )
     *
     * In order to use it, there will need to be added some appropriate
     * pre-processor definitions to keep from attempting to instantiate
     * an array of length 0.
     *
     * The problem is that on alpha sizeof(void *) = 64 and
     * sizeof(int) = 32 so we have:
     *   4 - 2*sizeof(void *)/sizeof(int) = 4 - 2*64/32 = 0
     */
    int reservedForFuture[5 - 2 * sizeof(void*) / sizeof(int)];
};

#define SIZES_LENGTH (sizeof(struct _ssSizes) / sizeof(int_T))

/*
 * _ssPortInfo (S->portInfo), this is only used by level 2 S-functions.
 *
 */

typedef const void* const* InputPtrsType;

typedef const real_T* const* InputRealPtrsType;
typedef const real32_T* const* InputReal32PtrsType;
typedef const int8_T* const* InputInt8PtrsType;
typedef const uint8_T* const* InputUInt8PtrsType;
typedef const int16_T* const* InputInt16PtrsType;
typedef const uint16_T* const* InputUInt16PtrsType;
typedef const int32_T* const* InputInt32PtrsType;
typedef const uint32_T* const* InputUInt32PtrsType;
typedef const boolean_T* const* InputBooleanPtrsType;

typedef void* OutputVectType;

#define GET_DATA_TYPE(dt) ((dt)&0xFFFF)
#define GET_COMPLEX_SIGNAL(dt) (((dt)&0x10000) != 0)


/*
 * Auxiliary DWork structure for S-Functions, one for each dwork.
 */
struct _ssDWorkAuxRecord {
    char_T* rtwIdentifier;
    int_T rtwStorageClass;
    char_T* rtwTypeQualifier;
    struct {
        unsigned int DisableBoundsChecking : 1; /* disable bounds check    */
        unsigned int ExtModeUpload : 1;         /* upload dwork in extmode */
        unsigned int rtwIdMustResolveToSignalObject : 2;
        /* identifier must resolve to signal object
         * 0U: Try resolve (implicit signal resolution)
         * 1U: Must resolve
         * 2U: Must not resolve */
        unsigned int rtwIdDoneResolve : 1;       /* done resolving identifier */
        unsigned int ensureResetForSizeVary : 1; /* ensure reset for size change */
        unsigned int minMaxCheckpoint : 2;       /* remainder are reserved    */
        unsigned int optimizeInIR : 1;           /* convert to local if correct */
        unsigned int reserved7 : 7;              /* remainder are reserved    */
        unsigned int reserved16 : 16;            /* remainder are reserved  */
    } flags;
    int_T icPrmIdxPlus1; /* block IC parameter (if
                          * there is) mapped to this
                          * dwork; 0 for none
                          */
    int_T bitFieldWidth;
    SLSize widthSLSize;

    void* resolvedSignalObject;
    void* unusedPtrs[3];
};

/* Registration returns 1 for success and 0 for failure */
typedef int_T (*_ssRegNumInputPortsFcn)(void* arg1, int_T nInputPorts);
typedef int_T (*_ssRegNumOutputPortsFcn)(void* arg1, int_T nOutputPorts);

typedef int_T (*_ssSetInputPortDimensionInfoFcn)(SimStruct* arg1,
                                                 int_T port,
                                                 const DimsInfo_AsInt* dimsInfo);
typedef int_T (*_ssSetOutputPortDimensionInfoFcn)(SimStruct* arg1,
                                                  int_T port,
                                                  const DimsInfo_AsInt* dimsInfo);
typedef int_T (*_ssSetInputPortDimensionInfoFcnSLSize)(SimStruct* arg1,
                                                       int_T port,
                                                       const DimsInfo_AsSLSize* dimsInfo);
typedef int_T (*_ssSetOutputPortDimensionInfoFcnSLSize)(SimStruct* arg1,
                                                        int_T port,
                                                        const DimsInfo_AsSLSize* dimsInfo);


struct _ssPortInputs {
    int_T width;             /* Number of elements in input
                                port                          */
    int_T directFeedThrough; /* Direct feedthrough for input
                                port                          */
    DTypeId dataTypeId;      /* Data type of input port.      */
    CSignal_T complexSignal; /* Complex signal (-1=either,
                                0=no, or 1=yes)?              */
    union {
        const void* vect;
        InputPtrsType ptrs;
    } signal; /* Inputs for level 2 S-functions */

    int_T connected; /* Are there signals entering
                        the input port of the Sfcn?   */
    struct {
        unsigned int overWritable : 1;
        unsigned int optimOpts : 2;
        unsigned int frameData : 2;
        unsigned int contiguity : 1;
        unsigned int acceptExprInRTW : 1;
        unsigned int cinId : 2;
        unsigned int nonDerivPort : 1;
        unsigned int dimensionsMode : 2;
        unsigned int busMode : 2;
        unsigned int optimizeInIR : 1;
        unsigned int reserved1 : 1;
        unsigned int reserved16 : 16;
    } attributes;

    real_T sampleTime; /* Sample and offset time when   */
    real_T offsetTime; /* block specifies port based ts */
    int_T* dims;       /* port dimensions               */
    int_T bufferDstPort;

    int_T sampleTimeIndex; /* Sample time index when using
                              port based sample times       */
    int_T numDims;         /* port number of dimensions     */
};

struct _ssPortOutputs {
    int_T width;             /* Number of elements in output
                                port                          */
    DTypeId dataTypeId;      /* Data type of outputs          */
    CSignal_T complexSignal; /* Complex signal (-1=either,
                                0=no, or 1=yes)?              */
    void* signalVect;        /* Output signal                 */
    int_T connected;         /* Are the signals leaving the
                                Sfcn driving other blocks?    */
    struct {
        unsigned int optimOpts : 2;
        unsigned int frameData : 2;
        unsigned int cToMergeBlk : 1;
        unsigned int constOutputExprInRTW : 1;
        unsigned int outputExprInRTW : 1;
        unsigned int trivialOutputExprInRTW : 1;
        unsigned int okToMerge : 2;
        unsigned int cecId : 2;
        unsigned int nonContPort : 1;
        unsigned int dimensionsMode : 2;
        unsigned int fedByBlockWithModesNoZCs : 1;
        unsigned int busMode : 2;
        unsigned int optimizeInIR : 1;
        unsigned int reserved13 : 13;
    } attributes;

    real_T sampleTime;     /* Sample and offset time when   */
    real_T offsetTime;     /* block specifies port based ts */
    int_T* dims;           /* port dimensions               */
    int_T sampleTimeIndex; /* Sample time index when using
                              port based sample times       */
    int_T icPrmIdxPlus1;   /* block IC parameter (if
                            * there is) mapped to this
                            * port; 0 for none
                            */
    int_T numDims;         /* port number of dimensions     */
};

struct _ssPortInfo {

    _ssRegNumInputPortsFcn regNumInputPortsFcn;
    void* regNumInputPortsFcnArg;
    _ssRegNumOutputPortsFcn regNumOutputPortsFcn;
    void* regNumOutputPortsFcnArg;

    struct _ssPortInputs* inputs;   /* Info for each input port of blk  */
    struct _ssPortOutputs* outputs; /* Info for each output port of blk */
};



typedef struct ssContextMemoryInfo_tag {
    void* base;
    size_t size;
} ssContextMemoryInfo;

/* Masks for determining the parameter attributes (see ssSfcnParams struct). */
#define SFCNPARAM_NOT_TUNABLE (1U << 0x0)
#define SFCNPARAM_TUNABLE (1U << 0x1)
#define SFCNPARAM_SIMONLY_TUNABLE (1U << 0x2)
#define SFCNPARAM_CLEAR_TUNABLE \
    (~(SFCNPARAM_NOT_TUNABLE | SFCNPARAM_TUNABLE | SFCNPARAM_SIMONLY_TUNABLE))

struct _ssSFcnParams {
    int_T dlgNum;        /* Number of S-function parameters passed in   */
    mxArray** dlgParams; /* The S-function parameters                   */
    uint_T* dlgAttribs;  /* Disable parameter changes during simulation?*/

    /* union preserves the memory map of the Simstruc; the size of an integer
     * is always less than or equal to that of a pointer
     */
    union {
        int_T numRtp;
        void* placeholder;
    } numRtp;
    ssParamRec** rtp;
};


struct _ssWork {
    int_T* iWork;      /* integer work vector             */
    real_T* rWork;     /* real work vector                */
    void** pWork;      /* pointer work vector             */
    int_T* modeVector; /* mode work vector                */
    void* userData;    /* User/application specific data  */

    union {
        struct _ssDWorkRecord* sfcn;
        void* root;
    } dWork; /* data type work vector            */

    struct _ssDWorkAuxRecord* dWorkAux;
    struct _ssLocalMdlInfo* localMdlInfo;
};


/*
 * Input port variable dimensions information.
 */
struct _ssInPortVarDims {
    const int* portVarDims;
    void* reserved[8];
};

/*
 * Output port variable dimensions information.
 */
struct _ssOutPortVarDims {
    int* portVarDims;
    void* reserved[8];
};

/*
 * Input port unit ID
 */
struct _ssInPortUnit {
    UnitId unitId;
};

/*
 * Output port unit ID
 */
struct _ssOutPortUnit {
    UnitId unitId;
};

typedef enum {
    SS_DIMS_CONSTRAINT_UNSPECIFIED = 0, /* Default - no block implementation */
    SS_DIMS_CONSTRAINT_NONE,            /* No constraint */
    SS_DIMS_CONSTRAINT_MULTIPLE,        /* Dims size must be a multiple of a specified value */
    SS_DIMS_CONSTRAINT_EXPLICIT,        /* Dims size must be an explicitly specified value */
    SS_DIMS_CONSTRAINT_IMMUTABLE, /* Port dims[0] cannot be cascaded - block is not vectorizable */
    SS_DIMS_CONSTRAINT_MULTIPORTEQUALSIZE /* Dims[0] size is equal on all inports and outport */
} SS_DimsConstraintType;

/*
 * Input port dataflow dims constraint info
 */
struct _ssInPortDimsConstraint {
    SS_DimsConstraintType type;
    uint_T size;
};

/*
 * Output port dataflow dims constraint info
 */
struct _ssOutPortDimsConstraint {
    SS_DimsConstraintType type;
    uint_T size;
};

/*
 * Input port cosim signal attributes
 */
struct _ssInPortCoSimAttribute {
    boolean_T isContinuousQuantity;
};

/*
 * Output port cosim signal attributes
 */
struct _ssOutPortCoSimAttribute {
    boolean_T isContinuousQuantity;
};

/*
 * The _ssPortInfo2 structure is used by S-function blocks to store port
 * variable dimensions information
 */
struct _ssPortInfo2 {
    struct _ssInPortVarDims* inputs;
    struct _ssOutPortVarDims* outputs;
    struct _ssInPortUnit* inputUnits;
    struct _ssOutPortUnit* outputUnits;
    struct _ssInPortDimsConstraint* inputDimsConstraint;
    struct _ssOutPortDimsConstraint* outputDimsConstraint;
    struct _ssInPortCoSimAttribute* inputCoSimAttribute;
    struct _ssOutPortCoSimAttribute* outputCoSimAttribute;
    void* reserved[2];
};

struct _ssSTInfo2 {
    size_t* ctrlRateInstanceIndex;
    boolean_T* isControlledByThisBlock;
    size_t nRateIndices;
    void* reserved[10];
};

/* Enum for Majority of S-Functions */
typedef enum {
    SS_UNSET = 0,
    SS_COLUMN_MAJOR = 1,
    SS_ROW_MAJOR = 2,
    SS_ALL = 3,
    SS_COLUMN_AUTO = 4,
    SS_ROW_AUTO = 5
} SSArrayLayout;

struct _ssPortInputsSLSize {
    SLSize width;
    SLSize* dims;
    const SLSize* portVarDims;
};
struct _ssPortOutputsSLSize {
    SLSize width;
    SLSize* dims;
    SLSize* portVarDims;
};
struct _ssSizesSLSize {
    SLSize numContStates;
    SLSize numDiscStates;
    SLSize numNonsampledZCs;
    SLSize numModes;
    SLSize numIWork;
    SLSize numRWork;
    SLSize numPWork;
    SLSize numDWork;
    SLSize numY;
    SLSize numU;
    SLSize sizeofY;
    SLSize sizeofU;
    SLSize numBlockIO;
    SLSize numZCEvents;
    SLSize sizeofBlockIO;
    SLSize sizeofGlobalBlockIO;
    SLSize sizeofDWork; /* Size of data type work vector. Depends on
                           dwork data types, complex signals, and
                           num dworks.                                    */
};

typedef int_T (*SetNumDWorkSLSize)(SimStruct*, SLSize);
struct _ssRegDataTypeSLSize {
    SetNumDWorkSLSize setNumDWorkFcn;
};

struct _ssJacobianInfoSLSize {
    SLSize numSlvrJacobianNzmax;
    SLSize numJacobianNzMax;
    SparseHeader_AsSLSize* slvrJacobianMatrix;
    SparseHeader_AsSLSize* jacobian;
};

struct _ssMassMatrixInfoSLSize {
    SLSize nzMax;
    SLSize* Ir;
    SLSize* Jc;
};

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
typedef int_T (*_WriteRTWNameValuePairFcnSLSize)(void* writeRTWFcnArg,
                                                 int_T type,
                                                 const char_T* name,
                                                 const void* value,
                                                 DTypeId dataTypeId,
                                                 SLSize nRows,
                                                 SLSize nCols);

typedef int_T (*_WriteRTWParameterFcnSLSize)(void* writeRTWFcnArg,
                                             int_T type,
                                             const char_T* name,
                                             const char_T* str,
                                             const void* value,
                                             DTypeId dataTypeId,
                                             SLSize nRows,
                                             SLSize nCols);
#endif
typedef void (*mdlSetInputPortWidthFcnSLSize)(SimStruct* S, int_T portIdx, SLSize width);
typedef void (*mdlSetOutputPortWidthFcnSLSize)(SimStruct* S, int_T portIdx, SLSize width);
typedef void (*mdlSetInputPortDimensionsFcnSLSize)(SimStruct* S,
                                                   int_T portIdx,
                                                   const DimsInfo_AsSLSize* dimsInfo);

typedef void (*mdlSetOutputPortDimensionsFcnSLSize)(SimStruct* S,
                                                    int_T portIdx,
                                                    const DimsInfo_AsSLSize* dimsInfo);

struct _ssMdlInfoSLSize {
    _ssSetInputPortDimensionInfoFcnSLSize regInputPortDimsInfo;
    _ssSetOutputPortDimensionInfoFcnSLSize regOutputPortDimsInfo;
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
    _WriteRTWNameValuePairFcnSLSize writeRTWNameValuePairFcn;
    _WriteRTWParameterFcnSLSize writeRTWParameterFcn;
#endif
    union {
        mdlSetInputPortWidthFcnSLSize mdlSetInputPortWidth;
        mdlSetInputPortDimensionsFcnSLSize mdlSetInputPortDims;
    } mdlSetInputPortDimensions;

    union {
        mdlSetOutputPortWidthFcnSLSize mdlSetOutputPortWidth;
        mdlSetOutputPortDimensionsFcnSLSize mdlSetOutputPortDims;
    } mdlSetOutputPortDimensions;

    SLSize mexApiSLSize2;
};

struct _ssBlkInfoSLSize {
    struct _ssPortInputsSLSize* inputs;
    struct _ssPortOutputsSLSize* outputs;
    struct _ssSizesSLSize sizes;
    struct _ssRegDataTypeSLSize regDataType;
    struct _ssJacobianInfoSLSize jacobianInfo;
    struct _ssMassMatrixInfoSLSize massMatrix;
};

/*
 * Enum for dictating how an s-function should
 * be used in accelerated simulations
 */
typedef enum {
    SS_SFCNREP_AUTO = 0,
    SS_SFCNREP_BINARY,
    SS_SFCNREP_TLC,
    SS_SFCNREP_CCODE
} SSRepresentation;

typedef enum { SS_32BIT = 0, SS_64BIT = 1 } SSBitness;

/*
 * The _ssBlkInfo structure can be used by S-function blocks to determine
 * status about the model in which they reside.
 */
struct _ssBlkInfo2 {
    void* rtwSfcnInfo; /* Used only in RTW by the S-function     */
    void* unused;
    struct _ssPortInfo2* portInfo2;
    struct _ssSTInfo2* stInfo2;
    char_T* localErrorStatusBuffer; /* local error status string buffer */
    union {
        const char_T* str;
        void* msg;
    } localErrorStatus;

    struct _ssBlkInfoSLSize* blkInfoSLSize;
    struct _ssMdlInfoSLSize* mdlInfoSLSize;
    void* reservedPtrs[9];

    int_T impulseResponseLength;
    int_T reserved[14];
    int_T sfcnBitness;
};

struct _ssBlkInfo {
    int_T inputConnected;         /* Is input connected to a non-virtual block? */
    int_T outputConnected;        /* Is output connected to a non-virtual block?*/
    const char_T* placementGroup; /* Name of group to place block in. Only
                                     applies to sources and sinks. Blocks with
                                     same group name will appear adjacent in
                                     the sorted list.                          */

    void* block; /* The owner SLBlock * of the s-function     */

    struct _ssBlkInfo2* blkInfo2; /* More block info                           */

    int_T absTolOffset_Obsolete; /* Offset from the root SimStruct absTol     */

    struct {
        /* bit field for flags which are only relevant to s-functions */

        /* each bit field has to be no more than 16 bits!  (some targets, for ex,
           TI 2000, do not support more than 16 bits per single field */

        uint_T okToCallStartTerminateOnSimRestart : 1;
        uint_T sCodeGenArrayLayout : 3;
        uint_T sRowMajorOptIn : 1;
        uint_T runtimeThreadSafetyCompliance : 4;
        uint_T localErrorStatusIsMsg : 1; /* 1 SimStruct_tag errorStatus is void*,
                                           * otherwise is const char*  */
        uint_T sReuseAcrossModels : 1;
        uint_T ssSupportsMultipleExecInstancesForModelRefNormalMode : 1;
        uint_T ssUserDataInvariantPostCompile : 1;
        uint_T ssCombineCompExecUserData : 1;
        uint_T reserved1 : 2;
        uint_T reserved2 : 16;
    } sfcnFlags;
};

/*==================================================================*
 * Mode of simulation - single vs multi-tasking. Note, variable       *
 * step solvers ignore this property and are always single-tasking   *
 *==================================================================*/
typedef enum {
    GEN_FCN_SET_NUM_RUN_TIME_PARAMS,
    GEN_FCN_REG_RUN_TIME_PARAM,
    GEN_FCN_UPDATE_RUN_TIME_PARAM,
    GEN_FCN_REG_ALL_TUNE_PRM_AS_RTP,
    GEN_FCN_UPDATE_ALL_TUNE_PRM_AS_RTP,
    GEN_FCN_UNUSED_91,
    GEN_FCN_UNUSED_92,
    GEN_FCN_UNUSED_93,
    GEN_FCN_UNUSED_94,
    GEN_FCN_UNUSED_95,
    GEN_FCN_UNUSED_96,
    GEN_FCN_UNUSED_97,
    GEN_FCN_UNUSED_98,
    GEN_FCN_UNUSED_99,
    GEN_FCN_UNUSED_100,
    GEN_FCN_UNUSED_101,
    GEN_FCN_UNUSED_102,
    GEN_FCN_UNUSED_103,
    GEN_FCN_UNUSED_104,
    GENFCNFIXPT_LICENSE,
    GEN_FCN_IS_RTPARAM_TUNABLE,
    GEN_FCN_GET_BLOCK_HANDLE,
    GEN_FCN_REGISTER_DATA_STORE_FROM_NAME,
    GEN_FCN_READ_FROM_DATA_STORE,
    GEN_FCN_WRITE_TO_DATA_STORE,
    GEN_FCN_REGISTER_NUM_DATA_STORE,
    GEN_FCN_COMPUTE_INPUT,
    GEN_FCN_GET_DATATYPEOVERRIDE,
    GEN_FCN_GET_MINMAXLOG,
    GEN_FCN_GET_MINMAXARCHIVE,
    GEN_FCN_REG_CONST_RUN_TIME_PARAM,
    GEN_FCN_SF_INLINABLE,
    GEN_FCN_REG_AND_CNV_RUN_TIME_PARAM,
    GEN_FCN_UPDATE_AND_CNV_RUN_TIME_PARAM,
    GEN_FCN_SET_ZERO_BASED_IN_PORT,
    GEN_FCN_SET_ZERO_BASED_OUT_PORT,
    GEN_FCN_SET_ONE_BASED_IN_PORT,
    GEN_FCN_SET_ONE_BASED_OUT_PORT,
    GEN_FCN_SET_SFCN_REPRESENTATION,
    GEN_FCN_GET_SFCN_REPRESENTATION,
    GEN_FCN_REGISTER_TYPE_FROM_NAMED_OBJECT,
    GEN_FCN_REGISTER_TYPE_FROM_PARAMETER,
    GEN_FCN_CREATE_SLCG_STRING_BUFFER,
    GEN_FCN_ADD_TO_SLCG_STRING_BUFFER,
    GEN_FCN_GET_STRING_DEFAULT_BUFFER_SIZE,
    GEN_FCN_GET_STRING_TYPE_BUFFER_SIZE,
    GEN_FCN_CREATE_RUN_TIME_PARAM_FROM_DATA,
    GEN_FCN_UPDATE_RUN_TIME_PARAM_FROM_DATA,
    GEN_FCN_FULL_REG_AND_CNV_RUN_TIME_PARAM,
    GEN_FCN_GET_STRING_TRUNCATION_DIAGNOSTIC,
    GEN_FCN_GET_STRING_TARGET_LANG_STANDARD,
    GEN_FCN_GET_MODELREF_INTFPARAM_MODEL_ARG_DATA,
    GEN_FCN_SET_DATA_ALIGNMENT,
    GEN_FCN_SET_ASYNC_TIMER_ATTRIBUTES,
    GEN_FCN_SET_ASYNC_TASK_PRIORITIES,
    GEN_FCN_SET_INPUT_SUPPORT_STRING,
    GEN_FCN_SET_OUTPUT_SUPPORT_STRING,
    GEN_FCN_GET_MODELREF_INTFPARAM_GLOBAL_DATA,
    GEN_FCN_GET_ELAPSE_TIME,
    GEN_FCN_GET_ELAPSE_TIME_COUNTER_DTYPE,
    GEN_FCN_GET_ELAPSE_TIME_COUNTER,
    GEN_FCN_GET_ELAPSE_TIME_RESOLUTION,
    GEN_FCN_COMPUTE_OUTPUT,
    GEN_FCN_SET_OUTPUT_OVERWRITE_INPUT_IDX,
    GEN_FCN_SET_MODELMAPPINGINFO,
    GEN_FCN_SET_SF_INIT_OUTPUT,
    GEN_FCN_GET_PRODHWDEVICEINFO,
    GEN_FCN_IS_POINTER_DATA_TYPE,
    GEN_FCN_GET_POINTER_CONTAINED_DATA_TYPE,
    GEN_FCN_GET_POINTER_CONTAINED_DATA_COMPLEXITY,
    GEN_FCN_GET_POINTER_CONTAINED_DATA,
    GEN_FCN_GET_POINTER_CONTAINED_DATA_WIDTH,
    GEN_FCN_REG_MODELREF_MDL_INFO,
    GEN_FCN_SET_MODELREF_TO_FILES,
    GEN_FCN_SET_MODELREF_FROM_FILES,
    GEN_FCN_GET_STRING_USE_CPP_CLASS,
    GEN_FCN_SET_BUS_PROPAGATION,
    GEN_FCN_SET_BUS_SOURCE_PORT,
    GEN_FCN_SET_BUS_INPORTS,
    GEN_FCN_GET_PARAM_NAME,
    GEN_FCN_SET_BUS_OUTPUT_OBJECT_NAME,
    GEN_FCN_SET_BUS_OUTPUT_AS_STRUCT,
    GEN_FCN_SET_BLOCK_PATH_TO_CHECKSUM,
    GEN_FCN_COMPUTE_STATEFLOW_SYMBOL_NAME,
    GEN_FCN_UNUSED_38,
    GEN_FCN_REG_MDL_INFO,
    GEN_FCN_SET_BUS_INPUT_AS_STRUCT,
    GEN_FCN_UNUSED_17,
    GEN_FCN_SET_TIME_SOURCE,
    GEN_FCN_SET_INPUT_SUPPORT_HALFPRECISION,
    GEN_FCN_SET_OUTPUT_SUPPORT_HALFPRECISION,
    GEN_FCN_UNUSED_29,
    GEN_FCN_ENABLE_FCN_IS_TRIVIAL,
    GEN_FCN_DISABLE_FCN_IS_TRIVIAL,
    GEN_FCN_SET_ASYNC_TIMER_DATA_TYPE,
    GEN_FCN_GET_CONTEXT_SYS_PTR,
    GEN_FCN_GET_CONTEXT_TID,
    GEN_FCN_SET_OUTPUT_FCN_CALLED_MULTIPLE,
    GEN_FCN_SET_NOT_MULTIPLE_INLINEABLE,
    GEN_FCN_GET_DATA_STORE_ADDR,
    GEN_FCN_REGISTER_TYPE_FROM_EXPR,
    GEN_FCN_REGISTER_TYPE_FROM_EXPR_NO_ERROR,
    GEN_FCN_GET_ZCSIGNAL_ZCEVENTS,
    GEN_FCN_REG_MODELREF_NONCONTSIGS,
    GEN_FCN_UNUSED_27,
    GEN_FCN_SET_INPUT_PORT_ACCESSED_BY_ADDRESS,
    GEN_FCN_SET_INPUT_DIMS_MODE,
    GEN_FCN_SET_OUTPUT_DIMS_MODE,
    GEN_FCN_REG_SET_INPUT_DIMS_MODE_MTH,
    GEN_FCN_READ_FROM_DATA_STORE_ELEM,
    GEN_FCN_WRITE_TO_DATA_STORE_ELEM,
    GEN_FCN_GET_DATA_STORE_INFO,
    GEN_FCN_UNUSED_19,
    GEN_FCN_UNUSED_28,
    GEN_FCN_UNUSED_60,
    GEN_FCN_SET_INPUT_DIMS_SAMEAS_OUTPUT,
    GEN_FCN_CHECK_SFCN_PARAM_VALUE_ATTRIBS,
    GEN_FCN_SET_EXPORTS_FUNCTION_CALLS,
    GEN_FCN_SET_EXPORTED_OUTPUT_FCN,
    GEN_FCN_SET_EXPORTED_ENABLE_FCN,
    GEN_FCN_SET_EXPORTED_DISABLE_FCN,
    GEN_FCN_SET_INPORT_LATCHED,
    GEN_FCN_SET_ALLOW_MORE_THAN_2D_SIGS,
    GEN_FCN_DEST_FCSS_ENABLED,
    GEN_FCN_SET_CURR_OUTPUT_DIMS,
    GEN_FCN_GET_SIM_STATUS,
    GEN_FCN_UNUSED_52,
    GEN_FCN_SET_STATE_ATTR,
    GEN_FCN_GET_STATE_ATTR,
    GEN_FCN_SET_INPUT_BUS_MODE,
    GEN_FCN_SET_OUTPUT_BUS_MODE,
    GEN_FCN_REG_SET_INPUT_BUS_MODE_MTH,
    GEN_FCN_REG_MDLREF_DWORK_TYPE,
    GEN_FCN_PRUN_TRAILING_DIMS,
    GEN_FCN_SET_SIGS_ALLOW_BIG_LONG,
    GEN_FCN_GET_MDLREF_TYPE,
    GEN_FCN_UNUSED_43,
    GEN_FCN_UNUSED_44,
    GEN_FCN_UNUSED_45,
    GEN_FCN_UNUSED_46,
    GEN_FCN_SET_JACOBIAN_FLAG,
    GEN_FCN_SET_OUTPUT_PORT_DISCRETE_VALUED_OUTPUT,
    GEN_FCN_SET_OUTPUT_IC_ATTRIBUTES,
    GEN_FCN_UNUSED_39,
    GEN_FCN_SET_SUPPORT_RUNTIME_MODEL_API,
    GEN_FCN_SET_SUPPORT_DATATYPE_BEYOND_32_BITS_IN_RTW,
    GEN_FCN_SET_FXPU32_BITREGION_COMPLIANT,
    GEN_FCN_GET_FXPU32_BITREGION_COMPLIANT,
    GEN_FCN_SET_COMP_VARSIZE_COMPUTE_TYPE,
    GEN_FCN_ADD_DIMS_DEPEND_RULE,
    GEN_FCN_GET_TIME_RESOLUTION,
    GEN_FCN_GET_RTWCG_SUPPORT,
    GEN_FCN_SET_ARRAYSCOPE_TO_LOCAL,
    GEN_FCN_ADD_VARDIMS_RUNTIME_CHECKER,
    GEN_FCN_SET_ASYNC_TASK_PRIORITIES_EL,
    GEN_FCN_SET_ASYNC_TIMER_RESOLUTION_EL,
    GEN_FCN_SET_ASYNC_TIMER_DATA_TYPE_EL,
    GEN_FCN_SET_TIME_SOURCE_EL,
    GEN_FCN_UNUSED_51,
    GEN_FCN_REG_MODELREF_SET_DIMS_DEPEND_RULES,
    GEN_FCN_REG_MODELREF_FINALIZE_DIMS_MTH,
    GEN_FCN_REGISTER_DATA_MIN_MAX_PRM_INDICES,
    GEN_FCN_CHECK_DWORK_RANGE,
    GEN_FCN_ACCEL_CALL_SET_DIMS,
    GEN_FCN_GET_STATEFLOW_SUBCHART_SIMSTRUCT,
    GEN_FCN_GET_STATEFLOW_SUBCHART_SYS_INST_INDICES,
    GEN_FCN_GET_DATATYPE_CHECKSUM,
    GEN_FCN_UNUSED_84,
    GEN_FCN_UNUSED_85,
    GEN_FCN_CHECK_STRUCTPARAM_CHECKSUM,
    GEN_FCN_GET_PARAM_DATATYPE,
    GEN_FCN_GET_SIMULATIONTYPE,
    GEN_FCN_GET_NET_SLOPE_VIA_DIVISION,
    GEN_FCN_UNUSED_87,
    GEN_FCN_UNUSED_36,
    GEN_FCN_GET_IS_INPORT_ELEMENT_CONTINUOUS,
    GEN_FCN_SET_IS_INPORT_USEDFOR_CONT_ZC,
    GEN_FCN_CREATE_AND_ADD_ZCSIGNAL_INFO,
    GEN_FCN_SET_ZCSIGNAL_NAME,
    GEN_FCN_GET_ZCSIGNAL_NAME,
    GEN_FCN_SET_ZCSIGNAL_WIDTH,
    GEN_FCN_GET_ZCSIGNAL_WIDTH,
    GEN_FCN_SET_ZCSIGNAL_ZCEVENT_TYPE,
    GEN_FCN_GET_ZCSIGNAL_ZCEVENT_TYPE,
    GEN_FCN_SET_ZCSIGNAL_TYPE,
    GEN_FCN_GET_ZCSIGNAL_TYPE,
    GEN_FCN_SET_ZCSIGNAL_ZCTOL,
    GEN_FCN_GET_ZCSIGNAL_ZCTOL,
    GEN_FCN_SET_ZCSIGNAL_NEEDS_EVENT_NOTIFICATION,
    GEN_FCN_GET_ZCSIGNAL_NEEDS_EVENT_NOTIFICATION,
    GEN_FCN_GET_NUM_ZCSIGNALS,
    GEN_FCN_GET_ZCSIGNAL_VECTOR,
    GEN_FCN_SET_ZCSIGNAL_ISZCELEMEMT_DISC,
    GEN_FCN_GET_ZCSIGNAL_ISZCELEMEMT_DISC,
    GEN_FCN_CLONE_AND_ADD_ZCSIGNAL_INFO,
    GEN_FCN_DATA_STORE_LOG_UPDATE,
    GEN_FCN_SET_STATES_MODIFIED_ONLY_IN_UPDATE,
    GEN_FCN_SUP_MULTI_EXEC_INSTANCES,
    GEN_FCN_REQUEST_IIS_NUM_ITER_DWORK,
    GEN_FCN_GET_STATEFLOW_RTWCONTEXT,
    GEN_FCN_GET_NUM_FCNCALL_DEST,
    GEN_FCN_UNUSED_86,
    GEN_FCN_UNUSED_53,
    GEN_FCN_SET_REQUIRED_STACK_SIZE,
    GEN_FCN_ACCEL_COPY_STATE_CACHE_FOR_IIS_IN_DESC_SYS_LIST,
    GEN_FCN_REG_AUTOSAR_CLIENT_BLOCK,
    GEN_FCN_UNUSED_61,
    GEN_FCN_SET_MODELREF_STATE_INSIDE_FOREACH,
    GEN_FCN_CALL_DEFAULT_JACOBIAN,
    GEN_FCN_CONFIG_DEFAULT_JACOBIAN,
    GEN_FCN_SET_DATA_MIN_MAX_VALUES,
    GEN_FCN_LOGGER_CREATE_DATASET_DESCRIPT,
    GEN_FCN_LOGGER_ADD_ELEMENT_DESCRIPT,
    GEN_FCN_LOGGER_ADD_TIMESERIES_DESCRIPT,
    GEN_FCN_LOGGER_CREATE_DATASET_FROM_DESCRIPT,
    GEN_FCN_LOGGER_ADD_ELEMENT_PROP,
    GEN_FCN_LOGGER_UPDATE_LOGVAR,
    GEN_FCN_ACCEL_COPY_STATE_CACHE_FOR_IIS_IN_CG_SYS_LIST,
    GEN_FCN_GET_DATATYPEOVERRIDEAPPLIESTO,
    GEN_FCN_READ_FROM_DATA_STORE_REGION,
    GEN_FCN_WRITE_TO_DATA_STORE_REGION,
    GEN_FCN_UPDATE_DATA_STORE_DIAGNOSTICS,
    GEN_FCN_GET_DATA_STORE_DIAGNOSTICS_STATUS,
    GEN_FCN_CREATE_MEM_REGION_DESC,
    GEN_FCN_SET_FLAT_MEM_SUB_REGION_DESC,
    GEN_FCN_DESTROY_MEM_REGION_DESC,
    GEN_FCN_GET_ZC_CONTROL_DISABLED,
    GEN_FCN_LOGGER_CREATE_VALUES_DESCIPT,
    GEN_FCN_LOGGER_SUPPORTS_SIGNAL_LOGGING,
    GEN_FCN_SET_ACCEPTS_FCNCALL_INPUTS,
    GEN_FCN_REGISTER_STRING_TYPE,
    GEN_FCN_IS_STRING_TYPE,
    GEN_FCN_GET_STRING_TYPE_MAX_LENGTH,
    GEN_FCN_READ_STRING_INPUT,
    GEN_FCN_GET_INPUT_STRING_LENGTH,
    GEN_FCN_WRITE_STRING_OUTPUT,
    GEN_FCN_REGISTER_DYNAMIC_ARRAY_DATA_TYPE,
    GEN_FCN_IS_DYNAMIC_ARRAY_DATA_TYPE,
    GEN_FCN_MODEL_WIDE_EVENT_BEING_PROCESSED,
    GEN_FCN_GET_REG_SUBMODELS_MDLINFO,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_TYPE,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_NUM_DIMS,
    GEN_FCN_GET_BLK_SUPPORT_CONCURRENT_TASKS,
    GEN_FCN_SET_BLK_SUPPORT_CONCURRENT_TASKS,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_COMPLEXITY,
    GEN_FCN_ACCEL_CALL_MODEL_FCNCALL_INPUT,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_DIMS,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_WIDTH,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_CURRENT_DIMS,
    GEN_FCN_SET_DYNAMIC_ARRAY_CONTAINED_DATA_CURRENT_DIMS,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_CURRENT_WIDTH,
    GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA,
    GEN_FCN_GET_INPUT_DYNAMIC_ARRAY_DATA,
    GEN_FCN_SET_INPUT_PORT_IS_MESSAGE,
    GEN_FCN_SET_OUTPUT_PORT_IS_MESSAGE,
    GEN_FCN_SEND_MESSAGE,
    GEN_FCN_RECEIVE_MESSAGE,
    GEN_FCN_CHK_MESSAGE_INPUT,
    GEN_FCN_NO_MESSAGE_ON_INPUTS,
    GEN_FCN_CHK_MESSAGE_OUTPUT,
    GEN_FCN_GET_OUTPUT_DYNAMIC_ARRAY_DATA,
    GEN_FCN_GET_INPUT_DYNAMIC_ARRAY_CONTAINED_DATA,
    GEN_FCN_GET_SIZE_OF_PARAMS,
    GEN_FCN_GET_OUTPUT_DYNAMIC_ARRAY_CONTAINED_DATA,
    GEN_FCN_HAS_PARAM_TABLE,
    GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_WIDTH,
    GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_COMPLEXITY,
    GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_TYPE,
    GEN_FCN_MULTI_INS_NO_SUPPORT_MESSAGE,
    GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_CURRENT_DIMS,
    GEN_FCN_GET_STRICT_SINGLE,
    GEN_FCN_SET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_CURRENT_DIMS,
    GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA,
    GEN_FCN_CREATE_DYNAMIC_ARRAY_FOR_DATA_TYPE,
    GEN_FCN_DESTROY_DYNAMIC_ARRAY_FOR_DATA_TYPE,
    GEN_FCN_UNUSED_68,
    GEN_FCN_UNUSED_67,
    GEN_FCN_UNUSED_14,
    GEN_FCN_UNUSED_15,
    GEN_FCN_SET_VARIABLE_SAMPLE_TIME_UID,
    GEN_FCN_SET_VARTS_MDLREF_SUPPORT,
    GEN_FCN_UNUSED_88,
    GEN_FCN_FILE_LOGGING_MANAGER_ADD_ELEMENT,
    GEN_FCN_FILE_LOGGING_MANAGER_REMOVE_ELEMENT,
    GEN_FCN_UNUSED_41,
    GEN_FCN_UNUSED_1,
    GEN_FCN_UNUSED_2,
    GEN_FCN_UNUSED_3,
    GEN_FCN_UNUSED_4,
    GEN_FCN_UNUSED_5,
    GEN_FCN_UNUSED_6,
    GEN_FCN_UNUSED_7,
    GEN_FCN_UNUSED_8,
    GEN_FCN_UNUSED_9,
    GEN_FCN_UNUSED_35,
    GEN_FCN_UNUSED_62,
    GEN_FCN_GET_DWORK_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_DWORK_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_RUN_TIME_PARAM_ACCESSED_BY_ADDRESS,
    GEN_FCN_SET_SIMULINK_VERSION_GENERATED_IN,
    GEN_FCN_MDL_UPDATE_IS_EMPTY,
    GEN_FCN_SET_STATE_EXECUTION_SEMANTICS_SYNCHRONOUS,
    GEN_FCN_SET_SYMBOLIC_DIMS_SUPPORT,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_EXPR,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_STRING,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_INT_VALUE,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_PLUS,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_MINUS,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_MULTIPLY,
    GEN_FCN_REGISTER_SYMBOLIC_DIMS_DIVIDE,
    GEN_FCN_GET_NUM_SYMBOLIC_DIMS,
    GEN_FCN_GET_SYMBOLIC_DIM,
    GEN_FCN_SET_INPUT_PORT_SYMBOLIC_DIMS_ID,
    GEN_FCN_UNUSED_89,
    GEN_FCN_GET_COMP_INPUT_PORT_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_COMP_INPUT_PORT_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_OUTPUT_PORT_SYMBOLIC_DIMS_ID,
    GEN_FCN_UNUSED_90,
    GEN_FCN_GET_COMP_OUTPUT_PORT_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_COMP_OUTPUT_PORT_SYMBOLIC_DIMS_ID,
    GEN_FCN_GET_COMP_DWORK_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_COMP_DWORK_SYMBOLIC_DIMS_ID,
    GEN_FCN_SET_PRM_TUNING_COMPLIANCE,
    GEN_FCN_GET_PRM_TUNING_COMPLIANCE,
    GEN_FCN_GET_ISINTERACTIVESIM,
    GEN_FCN_UNUSED_83,
    GEN_FCN_REGISTER_UNIT_FROM_EXPR,
    GEN_FCN_ACCEL_MDLREF_VM_GET_U_BY_INDEX,
    GEN_FCN_ACCEL_MDLREF_VM_GET_Y_BY_INDEX,
    GEN_FCN_ACCEL_MDLREF_BLOCK_SYSTEM_INITIALIZE,
    GEN_FCN_ACCEL_MDLREF_BLOCK_SYSTEM_RESET,
    GEN_FCN_SET_STOP_REQUESTED,
    GEN_FCN_SET_STOP_REQUESTED_SFUN,
    GEN_FCN_UNUSED_PARAMS3,
    GEN_FCN_UNUSED_PARAMS4,
    GEN_FCN_GET_MODELREF_INTFPARAM_BLOCK_ARG_DATA,
    GEN_FCN_VM_SIMULATION_COMPILE,
    GEN_FCN_SET_DISALLOW_CONTINUOUS,
    GEN_FCN_GET_BLOCK_PATH,
    GEN_FCN_REPORT_DIAGNOSTIC_AS_WARNING,
    GEN_FCN_IS_POSITIVE_DATA_VALUE,
    GEN_FCN_SIGN_DATA_VALUE,
    GEN_FCN_GET_GLOBAL_DATA_TRANSFER_INDICES,
    GEN_FCN_DATA_TRANSFER_READ,
    GEN_FCN_DATA_TRANSFER_WRITE,
    GEN_FCN_DATA_TRANSFER_INIT_BUFFERS,
    GEN_FCN_QUERY_SIMULINK_FUNCTION,
    GEN_FCN_DECLARE_SIMULINK_FUNCTION,
    GEN_FCN_DECLARE_SIMULINK_FUNCTION_CALLER,
    GEN_FCN_CALL_SIMULINK_FUNCTION,
    GEN_FCN_SIMULINK_FUNCTION_ARGUMENT,
    GEN_FCN_SET_DISALLOW_CONTROLLABLE,
    GEN_FCN_SET_CONTROLLABLE_SAMPLE_TIME,
    GEN_FCN_SET_CONTROLLABLE_SAMPLE_TIME_UID,
    GEN_FCN_SET_INPUT_CONTROLLABLE_SAMPLE_TIME,
    GEN_FCN_SET_INPUT_CONTROLLABLE_SAMPLE_TIME_UID,
    GEN_FCN_SET_OUTPUT_CONTROLLABLE_SAMPLE_TIME,
    GEN_FCN_SET_OUTPUT_CONTROLLABLE_SAMPLE_TIME_UID,
    GEN_FCN_ACCEL_PRE_BLOCK,
    GEN_FCN_ACCEL_POST_BLOCK,
    GEN_FCN_SET_DWORK_DIMENSIONS,
    GEN_FCN_CHK_MODELREF_SFUN_HAS_MODEL_BLOCK,
    GEN_FCN_DISCARD_DIAGNOSTIC,
    GEN_FCN_LONGJMP,
    GEN_FCN_SET_DEEPCOPY_COMPLIANT,
    GEN_FCN_ADD_OUTPUT_VARDIMS_PORT_INDEX,
    GEN_FCN_REPORT_DIAGNOSTIC_AS_INFO,
    GEN_FCN_REGISTER_SYMBOLIC_EQUAL_RELATION,
    GEN_FCN_REGISTER_SYMBOLIC_EQUAL_VALUE,
    GEN_FCN_AMEND_LEADING_SYMBOLIC_DIMS,
    GEN_FCN_AMEND_TRAILING_SYMBOLIC_DIMS,
    NUM_GEN_FCNS
} GenFcnType;

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
/* following return 1 on success and 0 on failure */
typedef int_T (*_WriteRTWStrFcn)(void* writeRTWFcnArg, const char_T* str);

typedef int_T (*_WriteRTWNameValuePairFcn)(void* writeRTWFcnArg,
                                           int_T type,
                                           const char_T* name,
                                           const void* value,
                                           DTypeId dataTypeId,
                                           int_T nRows,
                                           int_T nCols);

typedef int_T (*_WriteRTWParameterFcn)(void* writeRTWFcnArg,
                                       int_T type,
                                       const char_T* name,
                                       const char_T* str,
                                       const void* value,
                                       DTypeId dataTypeId,
                                       int_T nRows,
                                       int_T nCols);

typedef void (*_AccelRunBlockFcn)(SimStruct* S, int sysidx, int blkidx, int enumFunction);

typedef int_T (*_GenericFcn)(SimStruct* S, GenFcnType type, int_T arg1, void* arg2);
typedef int_T (*_ConstGenericFcn)(const SimStruct* S, GenFcnType type, int_T arg1, void* arg2);
#endif

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
/*
 * The following return error string on failure, NULL on success.
 * See <matlabroot>/simulink/src/barplot.c for an example of using
 * these functions.
 */

/*
 * Returns an array of output port pointers corresponding to the selected
 * signals in the window that the s-function block resides (i.e., the signals
 * whose lines have selection handles).  There are two options that can
 * be passed to this function (sigSetOpt):
 *    SIGSET_GRAPH: return only the selected signals in the window in
 *                  which the s-function resides.
 *    SIGSET_GRAPH_N_CHILDREN: return selected signals in the window in
 *                             which the s-function resides and all
 *                             children windows.
 */
typedef const char* (*SelectedSignalsFcn)(const void* voidBlock,
                                          const int sigSetOpt,
                                          void*** voidOutPortObjs, /* the ports           */
                                          int* outnPortObjs);      /* the number of ports */

/*
 * Given an array of output ports, create a signal list so that the signal
 * data may be accessed (also see sigmapdef.h).  Return an error string on
 * failure or NULL on success.
 */
typedef const char* (*SigListCreateFcn)(const void* voidBlock,
                                        const int nPorts,
                                        void** voidPortObjs,
                                        const unsigned int excludeFlags,
                                        void** voidOutSigList);

/*
 * Destroy a signal list.
 */
typedef void (*SigListDestroyFcn)(void* voidSigList);

/*
 * Access into Simulink memory manager's free function.  Used to destroy
 * objects that were created by calling into Simulink (e.g., ssCall..).  This
 * function is accessed via the ssCallGenericDestroyFcn macro.
 */
typedef void (*utFreeFcn)(void* ptr);

/*
 * Given a pointer to a port, return it's name (signal label).
 */
typedef const char* (*GetPortNameFcn)(void* voidPortObj);

/*
 * Given a signal list, detect and alert users to any signals that
 * are not available for viewing.
 */
typedef void (*SigListUnavailSigAlertFcn)(void* voidSigList);

/*
 * Given a port, unselect it's line.
 */
typedef void (*UnselectSigFcn)(void* voidPortObj);

/*
 * Given a SigList return ....
 */

/* number of regions comprising the 'listIdx-th' signal in the list */
typedef int (*SigListGetNumRegionsFcn)(void* voidSigList, int idx);

/* a pointer to the first region of the 'listIdx-th'signal in the list */
typedef void* (*SigListGetFirstRegFcn)(void* voidSigList, int idx);

/* the total num of elements comprising the 'listIdx-th' signal in the list */
typedef int (*SigListGetNumElementsFcn)(void* voidSigList, int idx);

/* true if the signal is a tie wrap (see sigmapdef.h) */
typedef int (*SigListGetIfTieWrapFcn)(void* voidSigList, int idx);

typedef struct _SignalAccess_tag {
    SelectedSignalsFcn SelectedSignals;
    SigListCreateFcn SigListCreate;
    SigListDestroyFcn SigListDestroy;
    SigListUnavailSigAlertFcn SigListUnavailSigAlert;

    SigListGetNumRegionsFcn SigListGetNumRegions;
    SigListGetFirstRegFcn SigListGetFirstReg;
    SigListGetNumElementsFcn SigListGetNumElements;
    SigListGetIfTieWrapFcn SigListGetIfTieWrap;

    utFreeFcn utFree;

    GetPortNameFcn GetPortName;
    UnselectSigFcn UnselectSig;
} SignalAccess;
#endif

/*
 * Call into the s-functions external mode fcn - if it exists.  Returns
 * error string on failure, NULL on success.
 */
typedef const char* (*SFunExtModeFcn)(SimStruct* S, const ExtModeLogBlockMeth);

/*
 * Non-continuous (sample time != 0) signals driving derivative ports
 * (e.g. integrand input port of an integrator block) need to be tracked
 * in order to determine when to reset variable step solvers.
 */
typedef struct {
    int sizeInBytes;
    char* pCurrVal;
    char* pPrevVal;
} ssNonContDerivSigInfo;

#if defined(RTW_GENERATED_S_FUNCTION) || SS_SL_INTERNAL
typedef struct ssNonContDerivSigFeedingOutports_tag {
    int sizeInBytes;
    char* currVal;
    struct ssNonContDerivSigFeedingOutports_tag* next;
} ssNonContDerivSigFeedingOutports;
#endif

/*
 * The _ssMdlInfo structure is "valid" in the root SimStruct only.  All child
 * SimStruct's point to the root SimStruct mdlInfo field.  Care must be taken
 * to use the correct mapping of tid's when accessing some of mdlInfo fields
 * (e.g. t, sample hits, sample times, etc). from child SimStruct's (use macros
 * below).
 */

struct _ssMdlInfo {
    SS_SimMode simMode; /* This field indicates
                           whether or not we are running a simulation
                           or generating the model.rtw file */

    time_T* t; /* The current time for each task. This is
                  of dimension sizes.numSampleTimes         */

    int_T* sampleHits; /* sample hits - does tid have a hit?  This is
                          of dimension sizes.numSampleTimes         */

    time_T tStart;           /* Model execution start time                 */
    time_T tFinal;           /* Final model execution stop time            */
    time_T timeOfLastOutput; /* Time of last model "output"                */

    time_T minStepSize; /* variable step-size is always >= minStepSize */

    void* timingData; /* Data used by execution or simulation engine*/

    SimTimeStep simTimeStep; /* Simulation time step "mode"                */

    int_T stopRequested; /* True if a "stop" has been requested        */
    int_T logOutput;     /* Log output?                                */

    time_T* outputTimes;     /* Times at which to log data                 */
    uint_T outputTimesIndex; /* Where we are in the OutputTimes vector     */
    uint_T numOutputTimes;   /* Length of OutputTimes                      */
    int_T outputTimesOnly;   /* Save [t,x,y] & continuous blocks at
                                specified times only?                      */

    int_T obsoletedNeedOutputAtTPlusTol;

    const char_T* solverName; /* Name of solver/integration algorithm       */
    int_T variableStepSolver; /* true=variable or false=fixed step solver */
    void* solverData;         /* Work area for solver                       */
    time_T solverStopTime;    /* Solver stop time                           */
    time_T stepSize;          /* The integration step size                  */
    int_T solverNeedsReset;   /* Do we need to reset the integrator?        */
    struct {
        unsigned int zcCacheNeedsReset : 1;    /* recompute zc value left?     */
        unsigned int derivCacheNeedsReset : 1; /* recompute derivatives?       */
        unsigned int blkStateChange : 1;       /* did blk state change?        */
        unsigned int cTimeOutputInconsistentWithStateAtMajorStep : 1;
        /* block output is inconsistent
         * with state at major output*/
        unsigned int forceSfcnExceptionHandling : 1; /* add exception handling *
                                                      *for all S-function calls*/
        unsigned int inlineParameters : 1;           /* is inline parameters selected
                                                      * for the model?       */
        unsigned int solverAssertCheck : 1;          /* true if consistency checking
                                                        is enabled and active        */
        unsigned int minStepViolatedError : 1;       /* what to do if the solver step
                                                      * size is less than the min step
                                                      * size: 0 => warn 1 => error */
        unsigned int blockStateForSolverChangedAtMajorStep : 1;
        /* block state has changed at
         * major step*/
        unsigned int reserved1 : 1;             /* unused mdlInfo flag          */
        unsigned int computingJacobian : 1;     /* 1 when computing Jacobian    */
                                                /* for use in ODE solver        */
        unsigned int solverCheckingCIC : 1;     /* 1 -- ODE solver checks if it */
                                                /* has consistent initial conds */
                                                /*  |M*xdot - f| is 'small'     */
        unsigned int errorStatusIsMsg : 1;      /* 1 SimStruct_tag errorStatus is
                                                 * void*,
                                                 * otherwise is const char*    */
        unsigned int timeTweakWarn : 1;         /* whether to warn when time is tweaked*/
        unsigned int solverRequestingReset : 1; /* e.g, step ended at discontinuity */
        unsigned int firstInitCondCalled : 1;   /* initCond Has been called at least once  */
        unsigned int sparseSlvrJacobian : 1;
        unsigned int frameUpgradeWarn : 1;
        unsigned int outputMethodComputed : 1;
        unsigned int doingParameterInit : 1;
        unsigned int f0EvaluationForJacobian : 2; /* Solver is computing f(x0) or
                                                    M(x0) for purposes of J(x0) computation*/
        unsigned int isRowMajor : 1;              /* true if row major parameter
                                                    is set on the model*/
        unsigned int zcEvalForRefine : 1;         /* if zc function is being evaluated on
                                                     refine */
        unsigned int reserved8 : 8;               /* remainder are reserved      */
    } mdlFlags;
    int_T maxNumMinSteps;          /* Max number of steps taken at minimum       */
    int_T solverRefineFactor;      /* state & output refinement factor      */
    real_T solverRelTol;           /* Integration relative tolerance             */
    real_T* solverAbsTol_Obsolete; /* OBSOLETE: abs tol for each continuous state */

    time_T maxStepSize;   /* variable StepSize is always <= MaxStepSize */
    int_T solverMaxOrder; /* Maximum order for ode15s                   */
    time_T fixedStepSize; /* Step size for fixed-step integrators       */

    int_T numNonContDerivSigInfos;
    ssNonContDerivSigInfo* nonContDerivSigInfos;
    uint8_T* solverAbsTolControl_Obsolete; /* Solver abs tol control
                                            * Obsoleted */
    rtTimingBridge* timingBridge;

    RTWLogInfo* rtwLogInfo;   /* Logging data structure for RTW         */
    ssSolverInfo* solverInfo; /* Solver information */

    char_T* errorStatusBuffer; /* errStatus string buffer */

    _slexecBlkRTSGateway blkRTSGateway;
    void* mexApiVoidPtr1; /* reserved for use by Simulink mex api */

    int_T solverExtrapolationOrder;     /* Extrapolation order for ODE14x          */
    int_T solverNumberNewtonIterations; /* Number of iterations for ODE14x     */

    /*
     * External mode object
     */
    RTWExtModeInfo* extModeInfo;

    /* Base addresses of Block Outputs vector for the whole model   */

    void* blockIO; /* block inputs/outputs                   */

    int* blockIOVarDims; /* block I/O variable dims */

    /* Parameter vectors for use with Real-Time Workshop */

    real_T* defaultParam;    /* Default parameter vector.                   */
                             /* Note: DefaultParam points to global storage;
                              *  common to all instances of this model.
                              *  Used only by Accelerator to point to model
                              *  wide info.
                              */
    const void* mappingInfo; /* Used by RTW for providing external access
                                to the parameters, block I/O, etc vectors   */


#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
    /*
     * Function pointers used in mdlRTW which write fields in the model.rtw file.
     */
    _WriteRTWStrFcn writeRTWStrFcn;
    _WriteRTWNameValuePairFcn writeRTWNameValuePairFcn;
    _WriteRTWParameterFcn writeRTWParameterFcn;

    void* writeRTWFcnArg;

    _AccelRunBlockFcn accelRunBlock;
    void* bdRefPtr;

    _GenericFcn genericFcn;

    void* reservedForFutureMLFcns[1];
    void* reservedForFutureMLArgs[4];
#endif

    int_T mexApiInt2;          /* for use by Simulink mex api */
    char_T reservedString[32]; /* IMPORTANT:
                                  Keep it fixed at 32 characters
                                  as it is needed for backward
                                  compatibility */


    _ssSetInputPortDimensionInfoFcn regInputPortDimsInfo;
    _ssSetOutputPortDimensionInfoFcn regOutputPortDimsInfo;

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
    SignalAccess* signalAccess;
    slDataTypeAccess* dataTypeAccess;
    void* pathsToModelBlock; /* for internal use by Simulink */
    void* reservedForFutureVoid[1];
#endif

    void* reservedForXPC;

#if SS_MULTITASKING || SS_SL_INTERNAL || SS_SFCN_FOR_SIM
    int_T* perTaskSampleHits; /* Matrix of dimension number of sample times
                                 by number of sample times giving sample
                                 hits as viewed in each task. Used by
                                 ssIsSpecialSampleHit within MEX files. */
#endif

    SolverMode solverMode; /* Simulation solver mode */
    RTWGenMode rtwgenMode;
    void* opModelData; /* C 20210921 G2352059 ABR - Operating Point support object */

    real_T mexApiReal1; /* reserved for use by Simulink mex api */
    real_T mexApiReal2; /* reserved for use by Simulink mex api */

    real_T* timeOfNextSampleHit;
    real_T* varNextHitTimesList;
    boolean_T* tNextWasAdjusted;
    void* executionInfo;


}; /* end struct _ssMdlInfo */

struct _ssLocalMdlInfo {
    void* ownerBd;
    real_T* rtp;
    void* blockIO;
    int* blockIOVarDims;
    void* ownerEbd;
    void* ownerCbd;
    uint_T* numRuntimeEvents;
    uint_T* globalRuntimeEventIndices;
    void* execSimStructMgr;
    void* simStruct;
    uint_T* numTimers;
    uint_T* globalTimerIndices;
    void* reserved[20];
};

/* returns 1 on success and 0 on failure */
typedef ssFcnCallErr_T (*SysOutputFcn)(void*, int_T, int_T);

#ifdef __cplusplus
#define SS_STATIC_CAST(T, E) static_cast<T>(E)
#else
#define SS_STATIC_CAST(T, E) (T)(E)
#endif

#define SS_FCNCALL_NO_ERR SS_STATIC_CAST(ssFcnCallErr_T, 1)
#define SS_FCNCALL_ERR SS_STATIC_CAST(ssFcnCallErr_T, 0)

struct _ssCallSys {
    int_T* outputs;     /* Which output elements call a system    */
    void** args1;       /* 1st Argument(s) for system output fcn  */
    int_T* args2;       /* 2nd Argument(s) for system output fcn  */
    SysOutputFcn* fcns; /* System output functions                */
};


/*------------------------ (S)->states.modelMethods2->resolveCBK ------------*/

/* callback function support type        *
 * returns 1 on success and 0 on failure */
typedef int_T (*_ResolveVarFcn)(const SimStruct* S, const char*, mxArray**);

/* callback structure */
struct _ssResolveCBK {
    _ResolveVarFcn Resolver; /* Resolver function                */
    void* _slBlock;          /* Block context for resolver fcn   */
};


/* callback access methods */
#define ssGetResolveMLVarCallbackStruct(S) ((ssGetModelMethods2(S))->resolveCBK)
#define ssSetResolveMLVarCallbackFcn(S, val) (ssGetResolveMLVarCallbackStruct(S)).Resolver = (val)
#define ssSetResolveMLVarCallbackContext(S, val) \
    (ssGetResolveMLVarCallbackStruct(S))._slBlock = (val)
#define ssResolveMLVarWithCallback(S, Var, mat)                          \
    (((ssGetResolveMLVarCallbackStruct(S)).Resolver != NULL)             \
         ? (*(ssGetResolveMLVarCallbackStruct(S)).Resolver)(S, Var, mat) \
         : (1))

/*---------------------------------------------------------------------------*/

typedef DTypeId (*OldRegisterDataType)(void*, const char_T*);
typedef int_T (*SetDataTypeSize)(void*, DTypeId, int_T);
typedef int_T (*GetDataTypeSize)(void*, DTypeId);
typedef int_T (*SetDataTypeZero)(void*, DTypeId, void*);
typedef const void* (*GetDataTypeZero)(void*, DTypeId);
typedef const char_T* (*GetDataTypeName)(void*, DTypeId);
typedef int_T (*SetNumDWork)(SimStruct*, int_T);


struct _ssRegDataType {
    void* arg1;                      /* 1st Argument for Register Data Type  */
    OldRegisterDataType registerFcn; /* Register Data Type Function          */
    SetDataTypeSize setSizeFcn;      /* Set Data Type Size Function          */
    GetDataTypeSize getSizeFcn;      /* Get Data Type Size Function          */

    SetDataTypeZero setZeroFcn; /* Set Data Type Zero representation    */
    GetDataTypeZero getZeroFcn; /* Get Data Type Zero representation    */

    GetDataTypeName getNameFcn; /* Get Data Type Name Function          */
    GetDataTypeId getIdFcn;     /* Get Data Type Id   Function          */

    SetNumDWork setNumDWorkFcn; /* Set num data type work vector        */
};

/* Access the model's boolean data type enabled flag */
typedef boolean_T (*StrictBooleanCheckEnabled)(void*);

/*
 * Access to Simulink's data type conversion function.
 */
typedef boolean_T (*ConvertBuiltInDTypeFcn)(
    int nVals,                  /* num vals to convert (*2 if complex)       */
    boolean_T satOnIntOverFlow, /* sat on overflow?                          */
    boolean_T doDiff,           /* check for loss of info during conversion? */
    const int dt1,              /* original data type                        */
    const void* v1,             /* vals to convert                           */
    const int dt2,              /* destination data type                     */
    void* v2);                  /* out: the converted values                 */


struct _ssStInfo {
    time_T* sampleTimes;      /* Sampling periods in seconds               */
    time_T* offsetTimes;      /* Task delay for discrete systems
                                 (0 <= OffsetTime < SampleTime)            */
    time_T tNext;             /* Time of next hit for M,MEX S-functions    */
    int_T tNextTid;           /* For M,MEX S-fcns, negative if not present */
    int_T* sampleTimeTaskIDs; /* Maps local sample time index to the
                                 root SimStruct task ID (root sti)         */
};



/*
 * Level 2 S-function methods:
 *
 * [mdlInitializePropagationPassFcn] - Optional routine. Perform any
 *                                 necessary initialization before the
 *                                 specified propagation pass begins.
 *=> mdlInitializeSizes         -  Initialize SimStruct sizes array
 *   [mdlSetInputPortWidth]     -  Optional routine. Check and set input and
 *                                 optionally other port widths.  Can
 *                                 only be in a C MEX S-function.
 *   [mdlSetOutputPortWidth]    -  Optional routine. Check and set output
 *                                 and optionally other port widths. Can
 *                                 only be in a C MEX S-function.
 *   [mdlSetInputPortFrameData] -  Optional routine. Check and set input and
 *                                 optionally other frame data.  Can
 *                                 only be in a C MEX S-function.
 *=> mdlInitializeSampleTimes   -  Initialize sample times.
 *   [mdlSetWorkWidths]         -  Optional routine. Set the state, iwork,
 *                                 rwork, pwork, etc sizes. Can only be in a
 *                                 C MEX S-function.
 *
 *   [mdlRTW]                   -  Optional routine.  Only called when
 *                                 generating code to add information to the
 *                                 model.rtw file which is used by the
 *                                 Real-Time Workshop.
 *
 *   <<End mdl function calls when generating code by the Real-Time Workshop>>
 *
 *   [mdlInitializeConditions]  -  Initialize model parameters (usually
 *                                 states). Will not be called if your
 *                                 S-function does not have an initialize
 *                                 conditions routine.
 *   [mdlStart]                 -  Optional routine. Perform actions such
 *                                 as allocating memory and attaching to pwork
 *                                 elements.  Can only be in a C MEX
 *                                 S-function.
 *   [mdlCheckParameters]       -  Optional routine. Will be called at
 *                                 any time during the simulation loop when
 *                                 parameters change. Can only be used in a
 *                                 C MEX S-function.
 *   [mdlExtModeExec]           -  Optional routine. Will be called during
 *                                 external mode simulation loop to run the
 *                                 C Mex S-function block.
 *   SimulationLoop:
 *        [mdlProcessParameters]   -  Optional routine. Called during
 *                                    simulation after parameters have been
 *                                    changed and verified to be okay by
 *                                    mdlCheckParameters. The processing is
 *                                    done at the "top" of the simulation loop
 *                                    when it is safe to process the changed
 *                                    parameters. Can only be used in a C MEX
 *                                    S-function.
 *        [mdlGetTimeOfNextVarHit] -  Optional routine. If your S-function
 *                                    has a variable step sample time, then
 *                                    this routine will be called.
 *        [mdlInitializeConditions] -  Optional routine. Only called if your
 *                                    S-function resides in an enabled
 *                                    subsystem configured to reset states,
 *                                    and the subsystem has just enabled.
 *     => mdlOutputs               -  Major output call (usually updates
 *                                    output signals).
 *        [mdlUpdate]              -  Update the discrete states, etc.
 *        [mdlDerivatives]         -  Compute the derivatives.
 *   EndLoop
 *   mdlTerminate               -  End of model housekeeping - free memory,
 *                                 etc.
 */

typedef void (*mdlInitializeSizesFcn)(SimStruct* S);

typedef void (*mdlInitializePropagationPassFcn)(SimStruct* S, PropagationPassType passType);

typedef void (*mdlSetInputPortWidthFcn)(SimStruct* S, int_T portIdx, int_T width);
typedef void (*mdlSetOutputPortWidthFcn)(SimStruct* S, int_T portIdx, int_T width);

typedef int_T (*mdlGetInputPortWidthLevel1Fcn)(SimStruct* S, int_T outputWidth);
typedef int_T (*mdlGetOutputPortWidthLevel1Fcn)(SimStruct* S, int_T inputWidth);

typedef void (*mdlSetInputPortDimensionsFcn)(SimStruct* S,
                                             int_T portIdx,
                                             const DimsInfo_AsInt* dimsInfo);

typedef void (*mdlSetOutputPortDimensionsFcn)(SimStruct* S,
                                              int_T portIdx,
                                              const DimsInfo_AsInt* dimsInfo);

typedef void (*mdlSetDefaultPortDimensionsFcn)(SimStruct* S);

typedef void (*mdlSetInputPortSymbolicDimensionsFcn)(SimStruct* S,
                                                     int_T portIdx,
                                                     SymbDimsId symbDimsId);

typedef void (*mdlSetOutputPortSymbolicDimensionsFcn)(SimStruct* S,
                                                      int_T portIdx,
                                                      SymbDimsId symbDimsId);

typedef void (*mdlSetInputPortDataTypeFcn)(SimStruct* S, int_T portIdx, DTypeId inputPortDataType);
typedef void (*mdlSetOutputPortDataTypeFcn)(SimStruct* S,
                                            int_T portIdx,
                                            DTypeId outputPortDataType);
typedef void (*mdlSetDefaultPortDataTypesFcn)(SimStruct* S);

typedef void (*mdlSetInputPortComplexSignalFcn)(SimStruct* S,
                                                int_T portIdx,
                                                CSignal_T iPortComplexSignal);
typedef void (*mdlSetOutputPortComplexSignalFcn)(SimStruct* S,
                                                 int_T portIdx,
                                                 CSignal_T oPortComplexSignal);
typedef void (*mdlSetDefaultPortComplexSignalsFcn)(SimStruct* S);

typedef void (*mdlSetInputPortFrameDataFcn)(SimStruct* S, int_T portIdx, Frame_T iPortFrameData);

typedef void (*RTWGeneratedEnableFcn)(SimStruct* S);
typedef void (*RTWGeneratedDisableFcn)(SimStruct* S);

typedef void (*mdlEnableFcn)(SimStruct* S);
typedef void (*mdlDisableFcn)(SimStruct* S);

typedef void (*mdlInitializeSampleTimesFcn)(SimStruct* S);

typedef void (*mdlSetInputPortSampleTimeFcn)(SimStruct* S,
                                             int portIdx,
                                             real_T sampleTime,
                                             real_T offsetTime);
typedef void (*mdlSetOutputPortSampleTimeFcn)(SimStruct* S,
                                              int portIdx,
                                              real_T sampleTime,
                                              real_T offsetTime);
typedef void (*mdlSetWorkWidthsFcn)(SimStruct* S);
typedef void (*mdlRTWFcn)(SimStruct* S);

typedef void (*mdlInitializeConditionsFcn)(SimStruct* S);
typedef void (*mdlInitializeConditionsLevel1Fcn)(real_T* x0, SimStruct* S);

typedef void (*mdlStartFcn)(SimStruct* S);

typedef void (*mdlSetupRuntimeResourcesFcn)(SimStruct* S);
typedef void (*mdlCleanupRuntimeResourcesFcn)(SimStruct* S);

typedef void (*mdlDataTransferReadFcn)(SimStruct* S, uint32_T dtIdx, void* data);

typedef void (*mdlDataTransferWriteFcn)(SimStruct* S, uint32_T dtIdx, void* data);

typedef void (*mdlDataTransferInitBuffersFcn)(SimStruct* S, uint32_T dtIdx, void* data);


typedef void (*mdlInitSystemMatricesFcn)(SimStruct* S);

typedef void (*mdlCheckParametersFcn)(SimStruct* S);
typedef void (*mdlProcessParametersFcn)(SimStruct* S);

typedef void (*mdlExtModeExecFcn)(SimStruct* S);

typedef void (*mdlGetTimeOfNextVarHitFcn)(SimStruct* S);

typedef void (*mdlOutputsFcn)(SimStruct* S, int_T tid);
typedef void (
    *mdlOutputsLevel1Fcn)(real_T* y, const real_T* x, const real_T* u, SimStruct* S, int_T tid);

typedef void (*mdlUpdateFcn)(SimStruct* S, int_T tid);
typedef void (*mdlUpdateLevel1Fcn)(real_T* x, const real_T* u, SimStruct* S, int_T tid);

typedef void (*mdlDerivativesFcn)(SimStruct* S);
typedef void (*mdlDerivativesLevel1Fcn)(real_T* dx,
                                        const real_T* x,
                                        const real_T* u,
                                        SimStruct* S,
                                        int_T tid);

typedef void (*mdlJacobianFcn)(SimStruct* S);
typedef void (*mdlJacobianIrJcFcn)(SimStruct* S);

typedef void (*mdlProjectionFcn)(SimStruct* S);

typedef void RTWCGInterface;

typedef void (*mdlRTWCGFcn)(SimStruct* S, RTWCGInterface* iObj);

typedef void (*mdlZeroCrossingsFcn)(SimStruct* S);

typedef void (*mdlTerminateFcn)(SimStruct* S);

typedef void (*mdlMassMatrixFcn)(SimStruct* S);

struct _ssMassMatrixInfo {
    ssMatrixType type;       /* SS_MATRIX_***, ...                  */
    ssSparseMatrixInfo info; /* Ir,Jc,Pr, etc.                      */
};

typedef void (*mdlForcingFunctionFcn)(SimStruct* S);

typedef void (*mdlConstraintsFcn)(SimStruct* S);

typedef void (*mdlPreInitializeFcn)(SimStruct* S);
typedef void (*mdlCopyRTPDataFcn)(SimStruct* S, int_T param, void** rtpData);
struct _ssConstraintsInfo {
    int_T numConstraints;             /* length of the constraints vector    */
    real_T* constraints;              /* constraints vector                  */
    mdlConstraintsFcn mdlConstraints; /* function evaluating the constraints */
};

typedef mxArray* (*mdlGetOperatingPointFcn)(SimStruct* S);
typedef void (*mdlSetOperatingPointFcn)(SimStruct* S, const mxArray* op);

typedef void (*mdlSimStatusChangeFcn)(SimStruct* S, ssSimStatusChangeType mEvent);

struct _ssSFcnModelMethods {

    mdlInitializeSizesFcn mdlInitializeSizes;

    mdlGetInputPortWidthLevel1Fcn mdlGetInputPortWidthLevel1;
    mdlGetOutputPortWidthLevel1Fcn mdlGetOutputPortWidthLevel1;

    union {
        mdlSetInputPortWidthFcn mdlSetInputPortWidth;
        mdlSetInputPortDimensionsFcn mdlSetInputPortDims;
    } mdlSetInputPortDimensions;

    union {
        mdlSetOutputPortWidthFcn mdlSetOutputPortWidth;
        mdlSetOutputPortDimensionsFcn mdlSetOutputPortDims;
    } mdlSetOutputPortDimensions;


    mdlSetInputPortDataTypeFcn mdlSetInputPortDataType;
    mdlSetOutputPortDataTypeFcn mdlSetOutputPortDataType;

    mdlInitializeSampleTimesFcn mdlInitializeSampleTimes;

    mdlSetInputPortSampleTimeFcn mdlSetInputPortSampleTime;
    mdlSetOutputPortSampleTimeFcn mdlSetOutputPortSampleTime;
    mdlSetWorkWidthsFcn mdlSetWorkWidths;
    mdlRTWFcn mdlRTW;

    union {
        mdlInitializeConditionsFcn level2;
        mdlInitializeConditionsLevel1Fcn level1;
    } mdlInitializeConditions;

    mdlStartFcn mdlStart;

    mdlCheckParametersFcn mdlCheckParameters;
    mdlProcessParametersFcn mdlProcessParameters;

    mdlGetTimeOfNextVarHitFcn mdlGetTimeOfNextVarHit;

    union {
        mdlOutputsFcn level2;
        mdlOutputsLevel1Fcn level1;
    } mdlOutputs;

    union {
        mdlUpdateFcn level2;
        mdlUpdateLevel1Fcn level1;
    } mdlUpdate;

    union {
        mdlDerivativesFcn level2;
        mdlDerivativesLevel1Fcn level1;
    } mdlDerivatives;
    mdlZeroCrossingsFcn mdlZeroCrossings;

    mdlTerminateFcn mdlTerminate;

    union {
        mdlSetInputPortComplexSignalFcn mdlSetInputPortComplexSignal;
        RTWGeneratedEnableFcn mdlEnable;

    } fcnInEnable;

    union {
        mdlSetOutputPortComplexSignalFcn mdlSetOutputPortComplexSignal;
        RTWGeneratedDisableFcn mdlDisable;

    } fcnOutDisable;

}; /* _ssSFcnModelMethods */

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
typedef mxArray* (*mdlGetSimStateFcn)(SimStruct* S);
typedef void (*mdlSetSimStateFcn)(SimStruct* S, const mxArray* in);
#endif

struct _ssSFcnModelMethods4 {
    mdlSetInputPortSymbolicDimensionsFcn mdlSetInputPortSymbolicDimensions;
    mdlSetOutputPortSymbolicDimensionsFcn mdlSetOutputPortSymbolicDimensions;
    mdlSetupRuntimeResourcesFcn mdlSetupRuntimeResources;
    mdlCleanupRuntimeResourcesFcn mdlCleanupRuntimeResources;
    mdlDataTransferReadFcn mdlDataTransferRead;
    mdlDataTransferWriteFcn mdlDataTransferWrite;
    mdlDataTransferInitBuffersFcn mdlDataTransferInitBuffers;
    mdlPreInitializeFcn mdlPreInitialize;
    mdlCopyRTPDataFcn mdlCopyRTPData;
    mdlGetOperatingPointFcn mdlGetOperatingPoint;
    mdlSetOperatingPointFcn mdlSetOperatingPoint;
    void* reservedForFuture[4];
};


struct _ssSFcnModelMethods3 {

    /* Embedding the structure -- massMatrix.type and *
     * massMatrix.info.nzMax must be always available */
    struct _ssMassMatrixInfo massMatrix;
    mdlInitSystemMatricesFcn mdlInitSystemMatrices;

    int_T numSlvrJacobianNzmax;
    SparseHeader_AsInt* slvrJacobianMatrix;
    mdlJacobianIrJcFcn mdlJacobianIrJc;
    void* reservedForFutureUse;
};

struct _ssSFcnModelMethods2 {

    mdlProjectionFcn mdlProjection;

    mdlJacobianFcn mdlJacobian;

    mdlSetInputPortFrameDataFcn mdlSetInputPortFrameData;

    StrictBooleanCheckEnabled strictBooleanCheckEnabledFcn;

    /* Default dimensions, data types, and complex signals functions */
    mdlSetDefaultPortDimensionsFcn mdlSetDefaultPortDimensions;
    mdlSetDefaultPortDataTypesFcn mdlSetDefaultPortDataTypes;
    mdlSetDefaultPortComplexSignalsFcn mdlSetDefaultPortComplexSignals;

    /* Reserved for model methods */
    ConvertBuiltInDTypeFcn ConvertBuiltInDType;

    /* Callback for S-function to resolve a variable from MATLAB workspace *
     *  using hierarchical scoping                                         */
    struct _ssResolveCBK resolveCBK;

    SFunExtModeFcn extModeLogFcn;

    mdlExtModeExecFcn mdlExtModeExec;

    mdlRTWCGFcn mdlRTWCG;

    mdlMassMatrixFcn mdlMassMatrix; /* function evaluating the MassMatrix  */

    struct _ssSFcnModelMethods4* modelMethods4;

    mdlForcingFunctionFcn mdlForcingFunction;

    mdlEnableFcn mdlEnable;
    mdlDisableFcn mdlDisable;
    mdlSimStatusChangeFcn mdlSimStatusChange;

    mdlInitializePropagationPassFcn mdlInitializePropagationPass;

    struct _ssConstraintsInfo* constraintsInfo;

    struct _ssSFcnModelMethods3* modelMethods3;
};

/* AlreadyWarned flag for blocks */
#define ssSetAlreadyWarnedFlag(S) (S)->states.flags.alreadyWarned = 1
#define ssGetAlreadyWarnedFlag(S) (S)->states.flags.alreadyWarned

typedef real_T const* const* UPtrsType;

typedef struct ssPeriodicStatesInfo_T {
    int_T globalContStateIndex;          /*  */
    int_T numPeriodicContStates;         /* Number of periodic continuous states */
    int_T* periodicContStateIndices;     /* */
    real_T* periodicContStateRanges;     /* */
    uint32_T* periodicContStateCounters; /* */
} ssPeriodicStatesInfo;

typedef struct ssJacobianPerturbationBounds_T {
    real_T* min;
    real_T* max;

} ssJacobianPerturbationBounds;

struct _ssStatesInfo2 {
    ZCSigState* prevZCSigState; /* Used for detecting zc events     */
    real_T* absTol;             /* abs tol for each continuous state          */
    uint8_T* absTolControl;
    ssPeriodicStatesInfo* periodicStatesInfo;       /*  */
    ssJacobianPerturbationBounds* jacPerturbBounds; /* Perturbation info */
    void* reservedForFutureUse[4];                  /* Reserved pointers */
};


struct _ssStates {
    union {
        void* vect; /* not const because of SL1.3 compat*/
        UPtrsType uPtrs;
    } U; /* Inputs for level 1 S-functions   */

    void* Y; /* Output for level 1 S-functions   */

    real_T* contStates; /* Continuous state vector          */
    real_T* discStates; /* Discrete state vector            */

    struct {
        unsigned int alreadyWarned : 1;                  /* Flag used by a block to
                                                          * determine if a warning has
                                                          * already been thrown for this
                                                          * block */
        unsigned int skipContStatesConsistencyCheck : 1; /* Should we skip checking for
                                                            continuous state consistency */
        /* prevent lint warnings about bit fields greater than 16 bits */
        unsigned int reserved13 : 13;
        unsigned int reserved16 : 16;
    } flags;

    int_T reserved2;

    real_T* dX;                         /* Derivative vector                */
    boolean_T* contStateDisabled;       /* Entry for each cont state        */
    struct _ssStatesInfo2* statesInfo2; /* Auxiliary information about states  */
    real_T* nonsampledZCs;              /* Non-sampled zero crossing signals */
    ZCDirection* nonsampledZCDirs;      /* Non-sampled zc directions          */

    SparseHeader_AsInt* jacobian; /* struct containing system Jacobian  */
    struct _ssSFcnModelMethods2* modelMethods2;
    int_T reservedSize;
};



/*===========*
 * SimStruct *
 *===========*/

struct SimStruct_tag {

    const char_T* modelName; /* Name of the Simulink model/Sfunc    */

    const char_T* path; /* Full "Simulink path" to this s-fcn  */

    SimStruct* parent; /* Parent SimStruct                    */
    SimStruct* root;   /* Root level SimStruct                */

    union {
        const char_T* str; /* Execution status. Setting to non-NULL
                        during any mdlFunction will stop the
                        simulation and the "status" message
                        will be displayed.                  */
        void* msg;
    } errorStatus;

    struct _ssSizes sizes; /* Sizes (returned when flag==0)      */

    struct _ssPortInfo portInfo; /* Input and output port properties
                                    such as width and direct feedthrough
                                    setting.                            */

    struct _ssSFcnParams sfcnParams; /* S-function parameters passed in
                                        P1,...,Pn                           */

    struct _ssStates states; /* Input, output, state, derivative,
                                etc. vectors                        */

    struct _ssWork work; /* Various work areas (rwork, iwork,
                            pwork, user data, block I/O,
                            block params, etc.)                 */

    struct _ssBlkInfo blkInfo; /* Information about S-function blocks */

    struct _ssMdlInfo* mdlInfo; /* Model-wide info. All children
                                   SimStruct point to root mdlInfo     */

    struct _ssCallSys callSys; /* For use when S-function calls a
                                  "function-call" subsystems          */

    struct _ssRegDataType regDataType; /* For Registering Data type           */

    struct _ssStInfo stInfo; /* Sample time, offset time, etc.      */

    struct {
        struct _ssSFcnModelMethods sFcn; /* For S-functions                    */
    } modelMethods;

    struct SimStruct_tag** sFunctions; /* SimStruct's for S-Functions
                                          referenced via S-Function blocks.
                                          Used only with RT and NRT.          */
};

/*
 * Set any S-function options which must be OR'd together.
 * For example:  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE |
 *                              SS_OPTION_DISCRETE_VALUED_OUTPUT);
 *
 * The available options are:
 * SS_OPTION_EXCEPTION_FREE_CODE - if your S-function does not use
 *   mexErrMsgTxt, mxCalloc, or any other routines which can throw an
 *   exception when called, you can set this option for improved
 *   performance.
 *
 * SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE - Similar to
 *   SS_OPTION_EXCEPTION_FREE_CODE except it only applies to the "run-time"
 *   routines: mdlGetTimeOfNextVarHit, mdlOutputs, mdlUpdate, and
 *   mdlDerivatives.
 *
 * SS_OPTION_DISCRETE_VALUED_OUTPUT - This should be specified if your
 *   S-function has a discrete valued outputs.  This is checked when
 *   your S-function is placed within an algebraic loop. If your S-function
 *   has discrete valued outputs, then its outputs will not be assigned
 *   algebraic variables.
 *
 * SS_OPTION_PLACE_ASAP - This is used to specify that your S-function
 *   should be placed as soon as possible. This is typically used by
 *   devices connecting to hardware.
 *
 * SS_OPTION_ALLOW_INPUT_SCALAR_EXPANSION - This is used to specify
 *   that the input to your S-function input ports can be either 1 or
 *   the size specified by the port which is usually referred to as
 *   the block width.
 *
 * SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME - This is used to disable
 *   your S-function block from inheriting a constant sample time.
 *
 * SS_OPTION_ASYNCHRONOUS - This option applies only to S-functions that
 *   have no input ports during code generation and 1 output port.
 *   During simulation, the S-function may have an input port to provide
 *   a condition on which to execute. The output port must be configured to
 *   perform function calls on every element.  If any of these requirements
 *   are not met, the SS_OPTION_ASYNCHRONOUS is ignored.  Use this option
 *   when driving function-call subsystems that will be attached to
 *   asynchronous tasks. Specifying this
 *     1) Informs Simulink that there is no implied data dependency involving
 *        the data sources or destinations of the function-call subsystem called
 *        by the S-function.
 *     2) Causes the function-call subsystem attached to the S-function to be
 *        colored cyan indicating that it does not execute at a periodic rate.
 *     3) Enables additional checks to verify that the model is
 *        constructed correctly:
 *          a) Simulink validates that the appropriate asynchronous rate
 *             transition blocks reside between the (cyan) function-call
 *             subsystem and period tasks exists. You can always directly
 *             read & write from the function-call subsys by using a block
 *             similar to the 'vxlib/Asynchronous Support/Rate Transition'
 *             block that has no computational overhead (look at the Tag value
 *             on the Outport block within the Rate Transition masked
 *             subsystem). Safe task transitions between period and
 *             asynchronous tasks are created by using the
 *             SS_OPTION_ASYNC_RATE_TRANSITION.
 *             See the 'vxlib/Asynchronous Support' library.
 *          b) For data transfers between two asynchronously executed (cycan)
 *             function-call subsystem, Simulink validates that the appropriate
 *             asynchronous task transition blocks exits.
 *             See the 'vxlib/Asynchronous Support' library.
 *
 * SS_OPTION_ASYNCHRONOUS_INTERRUPT - This option is very similar to
 *   SS_OPTION_ASYNCHRONOUS. This option adds the restriction that the
 *   this S-function and the destination function-call subsystem cannot reside
 *   in conditionally executed subsystems. This option should be used when the
 *   destination function-call subsystem is going to be directly attached to an
 *   interrupt. This added restriction is useful to prevent conceptual modeling
 *   errors. Specifically, if an function-call subsystem resides within an
 *   enabled subsystem, you would assume that it will only execute occur when
 *   the enable signal is > 0, but this would not be the behavior if the
 *   function-call subsystem were to be attached to an interrupt. Therefore
 *   this option prevents this possible source of confusion.
 *   Note, during simulation (and not code generation), Simulink allows the
 *   S-function to reside in a conditionally executed subsystem. See the
 *   VxWorks interrupt block for an example - in simulation we use a
 *   triggered subsystem to simulate the interrupt and during code generation
 *   the trigger port is removed.
 *
 *
 * SS_OPTION_ASYNCHRONOUS_CUSTOM - Similar to SS_OPTION_ASYNCHRONOUS, except
 *   items 3a, 3b are removed.
 *
 * SS_OPTION_ASYNC_RATE_TRANSITION - Use this when your s-function converts a
 *   guarantees data integrity when transferring data to/from an
 *   asynchronously executed function-call subsystem. There are two types
 *   of data transfers: periodic to asynchronous task transitions or
 *   asynchronous to asynchronous task transitions. An asynchronously executed
 *   function-call subsystem is a function-call subsystem driven by an
 *   S-function with the SS_OPTION_ASYNCHRONOUS specified.
 *
 *   Within Simulink, two classes of 'asynchronous rate transitions' are
 *   defined:
 *   1) Read-write pairs. In this scenario, two blocks (using a technique
 *      such as double buffering) ensure data integrity in a multitasking
 *      environment. When creating the read-write pair of blocks, the
 *      S-functions for these blocks should set SS_OPTION_ASYNC_RATE_TRANSITION.
 *      Furthermore, the Mask Type for the read block, must include
 *      the string 'read' and the write block must include the string 'write'.
 *      For example, in the VxWorks library, we have the
 *        Asynchronous Rate Transition (Reader)
 *        Asynchronous Rate Transition (Writer)
 *      pairs.
 *   2) A single (protected or unprotected) block such as the
 *      VxWorks, Unprotected Asynchronous Rate Transition block.
 *      To create a single Protected Rate Transition block, you
 *      need to create a block like:
 *        +-------------------+
 *        |     +-------+     |
 *        | O-->| S-fcn |-->O |--->
 *        |     +-------+     |
 *        +-------------------+
 *      where the outport has a Tag value set to AsyncRateTransition
 *      and the S-function provides the code for the protected
 *      transition. Note, this S-function should not set the
 *      SS_OPTION_ASYNC_RATE_TRANSITION.
 *
 *
 * SS_OPTION_RATE_TRANSITION - Use this while your S-function is behaving
 *   as a unit delay or ZOH. This option is only supported for these two
 *   operations. A unit delay operation is identified by the presence
 *   of mdlUpdate and if not present then the operation is ZOH.
 *
 * SS_OPTION_NONSTANDARD_PORT_WIDTHS - If your S-function has mdl
 *   set input/output port routines with dynamically sized ports and the port
 *   widths don't follow the standard rules of scalar expansion or
 *   vector collapsing, then you may need to set this flag for Simulink.
 *   This usually occurs when the output width is not 1 and not equal to the
 *   maximum of the input widths.
 *
 * SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED - Use this when you have
 *   registered multiple sample times (ssSetNumSampleTimes > 1) to
 *   specify the rate at when each input and output port is running at.
 *   The simulation engine needs this information when checking for
 *   illegal rate transitions.
 *
 * SS_OPTION_SFUNCTION_INLINED_FOR_RTW - Set this if you have a .tlc file
 *   for your S-function and do not have a mdlRTW method. Setting option
 *   has no effect if you have a mdlRTW method. This option is like an
 *   assertion. During code generation, if this option is set and
 *   Real-Time Workshop cannot locate the TLC-file for the S-function,
 *   Real-Time Workshop will generate and error. If this option is not present
 *   and Real-Time Workshop locates a TLC-file for the S-function, it will be
 *   used.
 *
 * SS_OPTION_ALLOW_PARTIAL_DIMENSIONS_CALL - Use this if the block can
 *   handle partially known dimensions in the mdlSetInputPortDimensionInfo
 *   or mdlSetOutputPortDimensionInfo methods.  By default, Simulink
 *   calls mdlSetInput(Output)PortDimensionInfo methods, if the
 *   candidate port dimensions are fully known. That is, when the number of
 *   dimensions and dimensions are known. If this flag is set, Simulink may
 *   call mdlSetInput(Output)PortDimensionInfo with partial dimension
 *   information.  As an example, the methods may be called when the port
 *   width is known, but the actual dimensions are unknown.
 *
 *
 * SS_OPTION_ADA_S_FUNCTION - Used to interface with Ada Coded S-functions.
 *   Not relevant for C-Mex S-Functions.
 *
 * SS_OPTION_FORCE_NONINLINED_FCNCALL - Use this flag if the block requires
 *   that all function-call subsystems that it calls should be generated as
 *   procedures instead of possibly being generated as inlined code.
 *
 * SS_OPTION_USE_TLC_WITH_ACCELERATOR -  Use this to force the Accelerator
 *   to use the TLC inlining code for a S-function which will speed up
 *   execution of the S-function.  By default, the Accelerator will use
 *   the mex version of the S-function even though a TLC file for the
 *   S-function exists. This option should not be set for device driver
 *   blocks (A/D) or when there is an incompatibility between running the
 *   mex Start/InitializeConditions functions together with the TLC
 *   Outputs/Update/Derivatives.
 *
 * SS_OPTION_SIM_VIEWING_DEVICE - This s-function is a SimViewingDevice.  As
 *   long as it meets the other requirement for this type of block (no states,
 *   no outputs, etc), it will be considered to be an external mode block
 *   (show up in the external mode gui and no code is generated for it).
 *   During an external mode simulation, this block is run on the host only.
 *
 * SS_OPTION_SIM_INPUT_DEVICE - Mark this s-function as a SimInputDevice.  When
 *   this option is set and this s-function registered an mdlExtModeExec fcn,
 *   then it will be run in external mode.
 *
 * SS_OPTION_CALL_TERMINATE_ON_EXIT - Use this to force a call to mdlTerminate
 *   when (a) the S-function block has finished mdlWorkWidths, or (b) the
 *   S-function block is being destroyed.
 *
 * SS_OPTION_REQ_INPUT_SAMPLE_TIME_MATCH - Use this to option to specify
 *   that the input signal sample time(s) match the sample time assigned
 *   to the block input port. For example:
 *
 *      .-----------.           .---------------------------.
 *      |  src (.1) |---------->|  port based Ts S-fcn with |
 *      `-----------'           |  input Ts = 1             |
 *                              `---------------------------'
 *
 *   will generate an error if this option is set. If the block (or input port)
 *   sample time is inherited, then there will be no error generated.
 *
 * SS_OPTION_NONVOLATILE - Use this option to specify whether this s-function
 *   has side effects.  Set this option to request that Simulink remove
 *   this block if it is not needed (dead code).
 *
 * SS_OPTION_CAN_BE_CALLED_CONDITIONALLY - Use this option if the s-function
 *   can be called conditionally by other blocks.
 *
 * SS_OPTION_ALLOW_PORT_SAMPLE_TIME_IN_TRIGSS - Use this to specify that
 *   your port based sample time S-Function can handle being placed in a
 *   triggered like subsystem (e.g. triggered, function call, for, while).
 *   During sample time propagation use the macro ssSampleAndOffsetAreTriggered
 *   to determine if the sample and offset times correspond to the block
 *   being in a triggered subsystem. If the block is triggered, all port
 *   sample times must be either triggered or constant.
 *
 * SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME - Use this option to specify
 *   that your port-based sample time S-Function can handle constant sample
 *   times. This option is required whether the S-Function is going to
 *   originate the constant sample time or can have one propagated to it.
 *
 * SS_OPTION_WORKS_WITH_CODE_REUSE - Use this option to specify that your
 *   S-Function will work in a system that is being reused in RTW
 *   generated code.  If this option is not set, then the system that
 *   this S-Function lives in will not be reused.
 *
 * SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES - This is used to state whether
 *   or not this block supports alias data types
 *
 * SS_OPTION_NO_INFLUENCE_ON_DEFAULT_MDL_DIMS - When dimensions propagation
 * to converge to a set of dimensions, blocks are queried individually
 * to setup their default dimensions. In the case of the S-function, this is
 * done by calling the mdlSetDefaultPortDimensions function. If the S-function
 * has no clear means of identifying a default set of dimensions, please
 * use this flag to postpone calls to mdlSetDefaultPortDimensions.
 */
#if SS_SFCN_LEVEL_1 || !SS_SFCN
#define SS_OPTION_USING_ssGetUPtrs 0x00000001
#endif

#define SS_OPTION_EXCEPTION_FREE_CODE 0x00000002
#define SS_OPTION_DISCRETE_VALUED_OUTPUT 0x00000004

#if !SS_SFCN_LEVEL_1
#define SS_OPTION_PLACE_ASAP 0x00000008
#define SS_OPTION_ALLOW_INPUT_SCALAR_EXPANSION 0x00000010
#define SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME 0x00000020
#define SS_OPTION_ASYNCHRONOUS 0x00000040
#define SS_OPTION_ASYNC_RATE_TRANSITION 0x00000080
#define SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE 0x00000100
#define SS_OPTION_RATE_TRANSITION 0x00000200
#define SS_OPTION_NONSTANDARD_PORT_WIDTHS 0x00000400
#define SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED 0x00000800
#define SS_OPTION_SFUNCTION_INLINED_FOR_RTW 0x00001000
/* !!! 0x00002000 used below !!! */
#define SS_OPTION_ALLOW_PARTIAL_DIMENSIONS_CALL 0x00004000
#define SS_OPTION_NO_INFLUENCE_ON_DEFAULT_MDL_DIMS 0x00008000
#define SS_OPTION_ADA_S_FUNCTION 0x00010000
#define SS_OPTION_FORCE_NONINLINED_FCNCALL 0x00020000
/* !!! 0x00040000 used below !!! */
#define SS_OPTION_USE_TLC_WITH_ACCELERATOR 0x00080000
#define SS_OPTION_SIM_VIEWING_DEVICE 0x00100000
#define SS_OPTION_CALL_TERMINATE_ON_EXIT 0x00200000
#define SS_OPTION_REQ_INPUT_SAMPLE_TIME_MATCH 0x00400000
#define SS_OPTION_ASYNCHRONOUS_CUSTOM 0x00800000
#define SS_OPTION_NONVOLATILE 0x01000000
#define SS_OPTION_CAN_BE_CALLED_CONDITIONALLY 0x02000000
#define SS_OPTION_ALLOW_PORT_SAMPLE_TIME_IN_TRIGSS 0x04000000
#define SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME 0x08000000
#define SS_OPTION_ASYNCHRONOUS_INTERRUPT 0x10000000
#define SS_OPTION_WORKS_WITH_CODE_REUSE 0x20000000
#define SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES 0x40000000
#define SS_OPTION_SIM_INPUT_DEVICE 0x80000000
#endif

/*
 * SS_OPTION_SUPPORTS_MULTITASKING is a flag for Simulink and is *not* to
 * be used by S-functions.
 */
#define SS_OPTION_SUPPORTS_MULTITASKING 0x00002000

/*
 * SS_OPTION_PROPAGATE_COMPOSITE_SYSTEM is a flag for Simulink and is *not*
 * to be used by S-functions.
 */
#define SS_OPTION_PROPAGATE_COMPOSITE_SYSTEM 0x00040000

#define SS_HAVEOPT(S, opt) ((ssGetOptions(S) & opt) != 0)

#define ssGetOptions(S) (S)->sizes.options /*   (uint_T)      */

#endif /* __SIMSTRUC__DEF */
/* LocalWords:  ID's ir Lcs Struct's dstates fcncall Slvr extmode vectorizable SIGSET sigmapdef th
 * LocalWords:  th'signal tid's zc conds nd CBK vals sti iwork rwork pwork nz compat Sfunc NRT OR'd
 * LocalWords:  vxlib ASYNC cycan Async TRIGSS
 */
