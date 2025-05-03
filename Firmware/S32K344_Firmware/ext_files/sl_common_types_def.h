/* Copyright 2010-2021 The MathWorks, Inc. */
#ifndef __SL_COMMON_TYPES_DEF_H__
#define __SL_COMMON_TYPES_DEF_H__

#include "sl_types_def.h"
#include "sl_fixpt.h"
#include "sl_datatype_access.h"
#include "rtw_storage.h"

#define DYNAMICALLY_SIZED (-1)
#define DYNAMICALLY_TYPED (-1)

#define OVERWRITE_INPUT_ANY (-2)
#define OVERWRITE_INPUT_NONE (-1)

#define INVALID_PORT_IDX (-1)

typedef enum { COMPLEX_INHERITED = -1, COMPLEX_NO, COMPLEX_YES } ssComplexity;

/*
 * Frame enum
 */
typedef enum { FRAME_INHERITED = -1, FRAME_NO, FRAME_YES } Frame_T;

/*
 * ssSetNumSampleTimes(S,PORT_BASED_SAMPLE_TIMES) - Indicates that the sample
 * times are assigned on a per port basis.
 */
#if !SS_SFCN_LEVEL_1
#define PORT_BASED_SAMPLE_TIMES -1
#endif

#ifndef _DIMENSION_MODE_T
#define _DIMENSION_MODE_T

/*
 * Dimensions mode
 * S-function ports can have the following three dimensions modes:
 * 1) INHERIT_DIMS_MODE
 *    - Dimensions mode depends on settings of the connected ports;
 *    - Ports cannot have INHERIT_DIMS_MODE after model compile;
 * 2) FIXED_DIMS_MODE
 *    - Signal dimensions are fixed during simulation;
 * 3) VARIABLE_DIMS_MODE
 *    - Signal dimensions are allowed to change during simulation.
 */
typedef enum { INHERIT_DIMS_MODE = -1, FIXED_DIMS_MODE, VARIABLE_DIMS_MODE } DimensionsMode_T;

#endif

typedef enum {
    SS_VARIABLE_SIZE_FROM_INPUT_SIZE = 0,      /* Output sizes only depend on input sizes */
    SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE /* Output sizes depend on input values     */
} SS_VariableSizeComputeType;

typedef enum {
    SS_VARIABLE_SIZE_STATE_NO_NEED_RESET = 0,
    SS_VARIABLE_SIZE_REQUIRE_STATE_RESET
} SS_VariableSizeStateResetType;

typedef enum { SS_PRM_NOT_TUNABLE = 0, SS_PRM_TUNABLE, SS_PRM_SIM_ONLY_TUNABLE } ssParamTunability;

#define SS_NOT_REUSABLE_AND_GLOBAL 0U /* default */
#define SS_REUSABLE_AND_LOCAL 1U
#define SS_REUSABLE_AND_GLOBAL 2U
#define SS_NOT_REUSABLE_AND_LOCAL 3U


/* For mdlRTW ssWriteRTWParamSettings macro */
#define SSWRITE_VALUE_STR 0
#define SSWRITE_VALUE_QSTR 1
#define SSWRITE_VALUE_VECT_STR 2
#define SSWRITE_VALUE_NUM 3
#define SSWRITE_VALUE_VECT 4
#define SSWRITE_VALUE_2DMAT 5
#define SSWRITE_VALUE_DTYPE_NUM 6
#define SSWRITE_VALUE_DTYPE_VECT 7
#define SSWRITE_VALUE_DTYPE_2DMAT 8
#define SSWRITE_VALUE_DTYPE_ML_VECT 9
#define SSWRITE_VALUE_DTYPE_ML_2DMAT 10
#define SSWRITE_VALUE_LIST_STR 11

#define DTINFO(id, complexSignal) ((complexSignal) ? ((id) | 0x10000) : (id))

/*
 *  Operating point used to be called SimState. For backward compatibility, the SimState flags are
 * preserved.
 */
typedef enum {
    SIM_STATE_COMPLIANCE_INVALID = -1,
    SIM_STATE_COMPLIANCE_UNKNOWN = 0,
    USE_DEFAULT_SIM_STATE,
    HAS_NO_SIM_STATE,
    USE_CUSTOM_SIM_STATE,
    DISALLOW_SIM_STATE

} ssSimStateCompliance;

/*
 * Enumerations to specify the S-function's compliance level with the
 * Operating Point save/restore feature
 */
typedef enum {
    OPERATING_POINT_COMPLIANCE_INVALID = (int)SIM_STATE_COMPLIANCE_INVALID,
    OPERATING_POINT_COMPLIANCE_UNKNOWN = (int)SIM_STATE_COMPLIANCE_UNKNOWN,
    USE_DEFAULT_OPERATING_POINT = (int)USE_DEFAULT_SIM_STATE,
    USE_EMPTY_OPERATING_POINT = (int)HAS_NO_SIM_STATE,
    USE_CUSTOM_OPERATING_POINT = (int)USE_CUSTOM_SIM_STATE,
    DISALLOW_OPERATING_POINT = (int)DISALLOW_SIM_STATE
} ssOperatingPointCompliance;

typedef enum {
    SIMULATION_ROLLBACK_UNINITIALIZED = 0U,
    SIMULATION_ROLLBACK_COMPLIANT = 1U,
    SIMULATION_ROLLBACK_NONCOMPLIANT_NEUTRAL = 2U,
    SIMULATION_ROLLBACK_NONCOMPLIANT_FATAL = 3U
} SimulationRollbackCompliance;

typedef enum {
    SIMULATION_FASTRESTART_UNINITIALIZED = 0U,
    SIMULATION_FASTRESTART_COMPLIANT = 1U,
    SIMULATION_FASTRESTART_NONCOMPLIANT_NEUTRAL = 2U,
    SIMULATION_FASTRESTART_NONCOMPLIANT_FATAL = 3U
} SimulationFastRestartCompliance;

typedef enum {
    VM_SIMULATIONS_COMPLIANT = 0U,
    VM_SIMULATIONS_NONCOMPLIANT_NEUTRAL = 1U,
    VM_SIMULATIONS_NONCOMPLIANT_FATAL = 2U
} VmSimulationsCompliance;

/*
 * Enumerations to specify the S-Function's compliance level of
 * runtime method thread safety.
 */
typedef enum {
    RUNTIME_THREAD_SAFETY_COMPLIANCE_UNKNOWN = 0,
    RUNTIME_THREAD_SAFETY_COMPLIANCE_FALSE,
    RUNTIME_THREAD_SAFETY_COMPLIANCE_TRUE
} RuntimeThreadSafetyCompliance;

typedef enum {
    SAMPLE_TIME_SUPPORT_UNKNOWN = 0,
    USE_DEFAULT_FOR_DISCRETE_INHERITANCE,
    DISALLOW_SAMPLE_TIME_INHERITANCE
} ModelRefTsInhRule;

/*
 * ss(Set|Get)ModelReferenceNormalModeSupport
 *
 * If this s-function has a mdlProcessParameters and mdlStart function,
 * and is used in a model referenced in normal mode, Simulink will error
 * out by default.  If your mdlProcessParameters function is safe to call
 * before mdlStart, set it to  MDL_START_AND_MDL_PROCESS_PARAMS_OK
 */
typedef enum {
    DEFAULT_SUPPORT_FOR_NORMAL_MODE = 0,
    MDL_START_AND_MDL_PROCESS_PARAMS_OK = 1,
    TUNABLE_PARAMS_NOT_USED_IN_MDL_START = 2
} ssModelReferenceNormalModeSupport;

/* Used by macro ssAddVariableSizeSignalsRuntimeChecker */
typedef enum { INPUTS_DIMS_MATCH = 0, INPUTS_DISALLOW_EMPTY_SIGNAL } RuntimeCheckerType_T;

#ifndef _SS_PARAM_REC
#define _SS_PARAM_REC
/*
 * Typedef for the enumeration that keeps track of the "transformed"
 * status of run-time parameters.
 */
typedef enum {

    /*
     * Your run-time parameter is not transformed if nDialogParamIndices is
     * one and there was no alteration of the dialog parameter
     */
    RTPARAM_NOT_TRANSFORMED = 0,

    /*
     * Your run-time parameter is transformed if nDialogParamIndices > 1 or
     * there was an alteration of the dialog parameter value or data type.
     */
    RTPARAM_TRANSFORMED = 1,

    /*
     * Your run-time parameter can be marked as 'make transformed tunable'
     * if nDialogParamIndices is one and you altered the dialog parameter
     * value or data  type. If the parameter field contains a single
     * tunable variable, say 'k', then the transformed data type, etc.
     * version of k will be used in the generated code. All references to
     * tunable parameters that have been transformed must be done so in
     * the same fashion, otherwise an error will  be generated.
     */
    RTPARAM_MAKE_TRANSFORMED_TUNABLE = 2
} TransformedFlag;

typedef struct ssParamRec_tag {

    /*
     * The parameter characteristics
     */
    const char* name; /* Name of the parameter. This must point
                       * to persistent memory. Do not set to a local
                       * variable (static char name[32] or strings
                       * "name" are okay)
                       */
#ifdef SYSTEM_OBJECTS_DEF
    char* mName;
#endif
    int_T nDimensions; /* Number of dimensions for this parameter     */

#if defined(SFCN64)
    void* unusedPtr;
#else
    int_T* dimensions; /* Array giving the dimension (sizes) of
                        * the parameter                                */
#endif

#ifdef SYSTEM_OBJECTS_DEF
    int_T numTotalElements;
#endif
    DTypeId dataTypeId;      /* For built-in data types, see BuiltInDTypeId
                              * in simstruc_types.h                         */
    boolean_T complexSignal; /* FALSE or TRUE                               */

    /*
     * The data pointer.  This is the data values for the run-time parameter.
     * Simulink needs this when creating the model.rtw file. Complex Simulink
     * signals are store interleaved. Likewise complex run-time parameters
     * must be stored interleaved.
     *
     * Note that mxArrays store the real and complex parts of complex
     * matrices as two separate contiguous pieces of data instead of
     * interleaving the real and complex parts.  */

    void* data;

    /*
     * The data attributes pointer is a persistent storage location where the
     * user can store additional information describing the data and then
     * recover this information later (potentially in a different function).
     */
    const void* dataAttributes;

    /*
     * Run-time parameters to dialog parameter map.
     *
     * For proper interaction with 'tunable parameter variables' that
     * are set via the "Tunable Parameters Dialog", Simulink requires
     * information about how the run-time parameters are derived.
     *
     * It is an implicit assumption that all run-time parameters are derived
     * from the dialog parameters, i.e., ssGetSFcnParam(S,i).  Thus each
     * run-time parameter is derived from a subset of the dialog parameters:
     *    run-time_parameter = some_function(subset of dialog parameters).
     * In the simplest case,
     *    run-time_parameter = a specific dialog parameter
     *
     * The following information specifies which dialog parameters are
     * used in deriving a specific run-time parameter. For the simplest case,
     * we have
     *     nDialogParamIndices = 1;
     *     dialogParamIndices  = k;
     *     transformed         = false;
     * This case is important to identify because this will allow for
     * efficient and correct code generation of run-time parameters when they
     * map directly back to tunable parameter variables specified in
     * the 'Tunable Parameters Dialog'.
     */

    int_T nDlgParamIndices;
    int_T* dlgParamIndices;      /* Array of length nDialogParamIndices
                                  * indicating the dialog parameters that
                                  * are used in deriving the run-time
                                  * parameter */
    TransformedFlag transformed; /* Transformed status */
    boolean_T outputAsMatrix;    /* Write out parameter as a vector (false)
                                  * [default] or a matrix (true)
                                  */
#if defined(SFCN64)
    int_T* dimensions;
#elif defined(SL_INTERNAL)
    int_T* dimensions64;
#else
    void* unusedPtr;
#endif

} ssParamRec;
#endif

#ifdef SYSTEM_OBJECTS_DEF

#define DYNAMIC_DIMENSION getDefaultDimensionInfo()

#else

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#ifdef __cplusplus
extern "C" {
#endif
extern const DimsInfo_T* DYNAMIC_DIMENSION;
#ifdef __cplusplus
}
#endif
#else
#define DYNAMIC_DIMENSION NULL
#endif

#endif

/*
 * Used to determine the indexing type of a port
 */
typedef enum { INDEX_BASE0, INDEX_BASE1, NONINDEX } slIdxPortType;

/*
 * NUM_MAT_DIMS
 */
#ifndef NUM_MAT_DIMS
#define NUM_MAT_DIMS (2)
#endif

/*
 * Enumeration values used in dimension propagation algorithms
 */
typedef enum ssVectorMode_tag {
    SS_UNKNOWN_MODE,
    SS_1_D_OR_COL_VECT,
    SS_1_D_OR_ROW_VECT,
    SS_1_D_ROW_OR_COL_VECT,
    SS_1_D_VECT,
    SS_COL_VECT,
    SS_ROW_VECT
} ssVectorMode;

/** Bus Mode (Currently not used)
 * S-function ports can have the following three bus modes:
 * 1) SL_INHERIT_BUS_MODE
 *    - Bus mode depends on the settings of the ports driving this port
 *    - Ports cannot have this setting after model compile
 * 2) SL_NON_BUS_MODE
 *    - This port cannot accept a bus signal
 * 3) SL_BUS_MODE
 *    - This port can accept a bus signal
 */
#ifndef _BUS_MODE_T
#define _BUS_MODE_T
typedef enum { SL_INHERIT_BUS_MODE = -1, SL_NON_BUS_MODE, SL_BUS_MODE } BusMode_T;
#endif

/*
 * Specify the capabilities to handle data types with
 * various word lengths. By default, it is assumed that
 * S-Function blocks are not implemented with necessary
 * RTW support for word lengths beyond 32 bits. If a block
 * has implemented necessary support for longer word
 * lengths, then two different levels of support can be
 * declared. One option is support up to the size of long
 * on the current code generation target. The second
 * option is no limitation which means the block is designed
 * to handle MultiWord situations.
 *
 * If limitations are declared and code generation is
 * attempted, then Simulink will automatically check
 * if any of the following items,  input ports, output
 * ports, run-time parameters or DWorks have data types
 * with word lengths beyond the limit. If the limit is
 * exceeded, Simulink will issue an error message.
 */
typedef enum {
    RTW_SUPPORT_BEYOND_32_BITS_NO = 0U, /* S-Function default */
    RTW_SUPPORT_BEYOND_32_BITS_FULLY = 1U,
    RTW_SUPPORT_BEYOND_32_BITS_UP_TO_TARGET_LONG = 2U
} SupportDataTypeBeyond32BitsInRTWFlag;

/*
 * Enumeration of work vector origin flag values.
 */
typedef enum {
    SS_DWORK_ORIGINATED_AS_DWORK = 0, /* default */
    SS_DWORK_ORIGINATED_AS_MODE,
    SS_DWORK_ORIGINATED_AS_RWORK,
    SS_DWORK_ORIGINATED_AS_IWORK,
    SS_DWORK_ORIGINATED_AS_PWORK,
    SS_DWORK_ORIGINATED_AS_DSTATE,
    SS_DWORK_ORIGINATED_AS_MASS_MATRIX_OFFSET,
    SS_NUM_DWORK_ORIGIN_TYPES
} ssDWorkOriginType;

/*
 * Enumeration of data transfer signals for the exported function diagram
 * (a.k.a. scheduling diagram)
 *
 * For such a data transfer signal:
 * -- FORWARD_DATA_TRANSFER: sources of the signal are scheduled before its
 *    destinations.
 * -- REVERSE_DATA_TRANSFER: sources of the signal are scheduled after its
 *    destinations.
 * -- HYBRID_DATA_TRANSFER:  mixed case, some of sources of the signal are
 *    scheduled before, while others are scheduled after the destinations of
 *    the data transfer signal.
 */
typedef enum {
    NOT_A_DATA_TRANSFER,
    FORWARD_DATA_TRANSFER,
    REVERSE_DATA_TRANSFER,
    HYBRID_DATA_TRANSFER
} DataTransferSignalType;

#ifndef _UNIT_ID
#define _UNIT_ID
/*
 * Unit ID as registered in the model Unit Table - this is a unique ID assigned to
 * each unit expression.
 */
typedef int_T UnitId;
#endif /* _UNIT_ID */

#ifndef _PRE_DEFINED_UNIT_IDS
#define _PRE_DEFINED_UNIT_IDS
/*
 * Definition of Simulink builtin unit IDs
 */
enum { INVALID_UNIT_ID = -10, SL_UNITS_MIXED = -2, SL_UNITS_INHERIT = -1, SL_UNSPECIFIED = 0 };
#endif /* _PRE_DEFINED_UNIT_IDS */


#endif

/* LocalWords:  DType
 */
