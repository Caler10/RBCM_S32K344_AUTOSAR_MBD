/* Copyright 1990-2021 The MathWorks, Inc. */

/**
 * @file: simstruc_implement.h
 *
 * @brief Required ssAPIs for simstruc.h and s-function demo examples, but not documented.
 *
 */

#ifndef __SIMSTRUC__IMPLEMENT
#define __SIMSTRUC__IMPLEMENT

#include "sl_common_types_def.h"
#include "simstruc_compcond.h"

#define _ssSafelyCallConstGenericFcnStart(S) \
       (((S)->mdlInfo->genericFcn==NULL) ? 0 : ((*((_ConstGenericFcn)(S)->mdlInfo->genericFcn))
#define _ssSafelyCallGenericFcnEnd ))

#define _ssSafelyCallGenericFcnStart(S) \
       (((S)->mdlInfo->genericFcn==NULL) ? 0 : ((*(S)->mdlInfo->genericFcn)
#define _ssSafelyCallGenericFcnEnd ))


#if !SS_SFCN_LEVEL_1

#define _ssGetNumInputPorts(S) \
    ((ssGetSfcnUsesNumPorts(S) == 1) ? ((S)->sizes.in.numInputPorts) : 0) /*(int_T) */

#define _ssSetNumInputPorts(S, nInputPorts) (S)->sizes.in.numInputPorts = (nInputPorts)

#define _ssGetNumOutputPorts(S) \
    ((ssGetSfcnUsesNumPorts(S) == 1) ? ((S)->sizes.out.numOutputPorts) : 0) /*(int_T) */


#define _ssSetNumOutputPorts(S, nOutputPorts) (S)->sizes.out.numOutputPorts = (nOutputPorts)

#endif


#if defined(USE_64BIT_FIELDS)
#define _ssSetCurrentOutputPortDimensions(S, pIdx, dIdx, val) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(pIdx)].portVarDims[(dIdx)] = (val)
#elif defined(USE_32BIT_FIELDS)
#define _ssSetCurrentOutputPortDimensions(S, pIdx, dIdx, val) \
    (S)->blkInfo.blkInfo2->portInfo2->outputs[(pIdx)].portVarDims[(dIdx)] = (val)
#endif

struct _ssVarDimsIdxVal_tag {
    int dIdx;
    int dVal;
#if defined(USE_64BIT_FIELDS) || defined(USE_32BIT_AND_64BIT_FIELDS)
    SLSize dValSLSize;
#endif
};

#define _ssGetSFcnParam(S, index) (S)->sfcnParams.dlgParams[index] /*   (mxArray *)   */

#define _ssSetNumRunTimeParams(S, num) (S)->sfcnParams.numRtp.numRtp = (num)


#define _ssSetRunTimeParamInfo(S, idx, p) (S)->sfcnParams.rtp[idx] = (p)

/* DWork - This is the number of the data type work vector of your S-function.
 *   The root SimStruct contains the total number of data type work vectors
 *   used within the model.
 */
#if defined(USE_64BIT_FIELDS)
#define _ssSetNumDWork(S, nDWork) ((S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numDWork = (nDWork))
#elif defined(USE_32BIT_FIELDS)
#define _ssSetNumDWork(S, nDWork) ((S)->sizes.numDWork = (nDWork))
#endif


#define ssIsTIDInStInfo(S, tid)                                                             \
    (((tid) >= 0) &&                                                                        \
     ((tid) < ((S)->parent ? ssGetNumSampleTimes((S)->parent) : ssGetNumSampleTimes(S))) && \
     (ssGetSampleTimeTaskID(S, tid) < ssGetNumRootSampleTimes(S)))

#define ssGetSampleHitPtr(S) (S)->mdlInfo->sampleHits /*   (int_T *) */


#if SS_SL_INTERNAL
#define ssGetSampleTimeTaskID(S, sti) (S)->stInfo.sampleTimeTaskIDs[sti] /*   (int_T)       */
#elif TID_EQUALS_SAMPLE_TIME_INDEX
#define ssGetSampleTimeTaskID(S, sti) (sti) /*   (int_T)       */
#else
#define ssGetSampleTimeTaskID(S, sti) (S)->stInfo.sampleTimeTaskIDs[sti] /*   (int_T)       */
#endif

#if defined(USE_64BIT_FIELDS)
#define ssGetRegOutputPortDimensionInfoFcn(S) \
    ((S)->blkInfo.blkInfo2->mdlInfoSLSize->regOutputPortDimsInfo)
#elif defined(USE_32BIT_FIELDS)
#define ssGetRegOutputPortDimensionInfoFcn(S) ((S)->mdlInfo->regOutputPortDimsInfo)
#endif


/* InputPortFrameData -  For each input port or your S-function block, this
 *   is whether or not the incoming signal is frame data, where (-1=either,
 *   0=no, 1=yes).
 */

#define ssSetInputPortFrameData(S, port, val) \
    (S)->portInfo.inputs[(port)].attributes.frameData = CONV_INT2BITS(val)

/* OutputPortFrameData - For each input port or your S-function block, this
 *   is whether or not the outgoing signal is frame data, where (-1=either,
 *   0=no, 1=yes).
 */

#define ssSetOutputPortFrameData(S, port, val) \
    (S)->portInfo.outputs[(port)].attributes.frameData = CONV_INT2BITS(val)

/* Check if the model has any zero crossing states */
#define ssMdlHasZcStates(S) \
    ((S)->root->blkInfo.blkInfo2->blkInfoSLSize->sizes.numNonsampledZCs != 0)


#if SS_SFCN_FOR_SIM

#ifdef __cplusplus
extern "C" {
#endif

extern int_T ssWriteRTWNameValuePair(SimStruct* S,
                                     int_T type,
                                     const char_T* name,
                                     const void* value,
                                     ...);

extern int_T _ssSetInputPortMatrixDimensions(SimStruct* S, int_T port, int_T m, int_T n);
extern int_T _ssSetOutputPortMatrixDimensions(SimStruct* S, int_T port, int_T m, int_T n);
extern int_T _ssSetInputPortVectorDimension(SimStruct* S, int_T port, int_T m);
extern int_T _ssSetOutputPortVectorDimension(SimStruct* S, int_T port, int_T m);
extern int_T ssIsRunTimeParamTunable(SimStruct* S, const int_T rtPIdx);
extern double ssGetSFuncBlockHandle(SimStruct* S);
extern int_T _ssGetCallSystemNumFcnCallDestinations(SimStruct* S, int_T elemIdx);
extern boolean_T ssGetParameterTuningCompliance(SimStruct* S);

#if defined(SFCN64)
extern SLSize _ssGetCurrentInputPortWidth(SimStruct* S, int_T pIdx);
extern SLSize _ssGetCurrentOutputPortWidth(SimStruct* S, int_T pIdx);
#else
extern int_T _ssGetCurrentInputPortWidth(SimStruct* S, int_T pIdx);
extern int_T _ssGetCurrentOutputPortWidth(SimStruct* S, int_T pIdx);
#endif
#ifdef __cplusplus
}
#endif

#endif



typedef struct _ssRTPRegInfoWithType_tag {
    int dlgIdx;
    int rtIdx;
    const char* name;
    int dtId;
} ssRTPRegInfoWithType;


#if !SS_SFCN_LEVEL_1

#if defined(USE_64BIT_FIELDS)
#define ssGetRegInputPortDimensionInfoFcn(S) \
    ((S)->blkInfo.blkInfo2->mdlInfoSLSize->regInputPortDimsInfo)
#elif defined(USE_32BIT_FIELDS)
#define ssGetRegInputPortDimensionInfoFcn(S) ((S)->mdlInfo->regInputPortDimsInfo)
#endif

#endif


/*
 * ssSetCallSystemOutput -
 *   S-functions should use this in mdlInitializeSampleTimes to specify
 *   which output port elements of the first output port are connected
 *   to function-call subsystems. The S-function can then execute
 *   the function-call subsystems via ssCallSystemWithTID
 */
#define ssGetCallSystemOutputPtr(S) (S)->callSys.outputs /* (int_T*)    */
#define _ssSetCallSystemOutputPtr(S, ptr) (S)->callSys.outputs = (ptr)
#if !SS_SFCN
#define ssSetCallSystemOutputPtr(S, ptr) _ssSetCallSystemOutputPtr(S, ptr)
#else
#define ssSetCallSystemOutputPtr(S, ptr) ssSetCallSystemOutputPtr_cannot_be_used_in_SFunctions
#endif

#define ssGetCallSystemOutput(S, element) (S)->callSys.outputs[element] /* (int_T)     */



/* ================== APIs for zero crossing =================================*/

typedef struct {
    int_T _regionIdx;
    int_T _regionElIdx;
    boolean_T _result;
} _ssRegionElementIdxInfo;

#ifdef __cplusplus
extern "C" {
#endif

extern boolean_T ssGetIsZeroCrossControlDisabled(SimStruct* S);
extern void ssSetIsInputPortUsedForContZcSignal(SimStruct* S, int_T pIdx, boolean_T value);
extern void ssSetZcSignalIsZcElementDisc(SimStruct* S,
                                         int_T zcsIdx,
                                         int_T zcsElIdx,
                                         boolean_T value);
extern void ssSetZcSignalName(SimStruct* S, int_T zcsIdx, char* name);
extern void ssSetZcSignalWidth(SimStruct* S, int_T zcsIdx, int_T width);
extern void ssSetZcSignalZcEventType(SimStruct* S, int_T zcsIdx, slZcEventType zcEventType);
extern void ssSetZcSignalType(SimStruct* S, int_T zcsIdx, slZcSignalType zcSignalType);
extern void ssSetZcSignalZcTol(SimStruct* S, int_T zcsIdx, double zcTol);
extern void ssSetZcSignalNeedsEventNotification(SimStruct* S,
                                                int_T zcsIdx,
                                                boolean_T needsEventNotification);

extern int_T ssCreateAndAddZcSignalInfo(SimStruct* S);
extern int_T ssCloneAndAddZcSignalInfo(SimStruct* S, int_T zcsIdx);
extern int_T ssGetNumZcSignals(SimStruct* S);

extern double* ssGetZcSignalVector(SimStruct* S, int_T zcsIdx);
extern const char* ssGetZcSignalName(SimStruct* S, int_T zcsIdx);
extern int_T ssGetZcSignalWidth(SimStruct* S, int_T zcsIdx);
extern slZcEventType ssGetZcSignalZcEventType(SimStruct* S, int_T zcsIdx);
extern slZcEventType* ssGetZcSignalZcEvents(SimStruct* S, int_T zcsIdx);
extern slZcSignalType ssGetZcSignalType(SimStruct* S, int_T zcsIdx);
extern double ssGetZcSignalZcTol(SimStruct* S, int_T zcsIdx);
extern boolean_T ssGetZcSignalNeedsEventNotification(SimStruct* S,

                                                     int_T zcsIdx);
extern boolean_T ssGetZcSignalIsZcElementDisc(SimStruct* S, int_T zcsIdx, int_T zcsElIdx);

extern boolean_T ssGetIsInputPortElementContinuous(SimStruct* S, int_T pIdx, int_T eIdx);
#ifdef __cplusplus
}
#endif



#define ssGetNumRootSampleTimes(S) ssGetNumSampleTimes((S)->root)



#if SS_SIM
#define dtaGetDataTypeSize(dta, blockPath, id)                                            \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_SIZE)                   \
                   : INVALID_DTYPE_SIZE)
#else
#define dtaGetDataTypeSize(dta, blockPath, id) dtaGetDataTypeSize_cannot_be_used_in_RTW
#endif



/*
 * The following macro, ssSetTimeOfNextVarHit, will not work in non-inlined
 * S-functions in rapid accelerator or rsim. When using this advanced
 * and undocumented feature, TLC will be required in order to support
 * Rapid Accelerator simulation mode or Simulink Coder code generation
 * (rsim target).
 */

#define _ssSetVarNextHitTime(S, i, value) (S)->mdlInfo->varNextHitTimesList[(i)] = (value)
#define _ssGetVarNextHitTime(S, i) ((real_T)((S)->mdlInfo->varNextHitTimesList[(i)]))



#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#if defined(RTW_GENERATED_S_FUNCTION)
#define ssSetTimeOfNextVarHit(S, sti, tNext)                                            \
    {                                                                                   \
        _ssSetVarNextHitTime((S)->root, (int)(ssGetOffsetTime((S)->root, sti)), tNext); \
        ssSetTNext(S, tNext);                                                           \
    }

#define ssGetTimeOfNextVarHit(S, sti) \
    _ssGetVarNextHitTime((S)->root, (int)(ssGetOffsetTime((S)->root, sti)))

#else
#define ssSetTimeOfNextVarHit(S, sti, tNext)                                                     \
    {                                                                                            \
        _ssSetVarNextHitTime(                                                                    \
            (S)->root, (int)(ssGetOffsetTime((S)->root, ssGetSampleTimeTaskID(S, sti))), tNext); \
        ssSetTNext(S, tNext);                                                                    \
    }

#define ssGetTimeOfNextVarHit(S, sti) \
    _ssGetVarNextHitTime((S)->root,   \
                         (int)(ssGetOffsetTime((S)->root, ssGetSampleTimeTaskID(S, sti))))

#endif
#endif


#if SS_MULTITASKING || SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssGetPerTaskSampleHitsPtr(S) (S)->mdlInfo->perTaskSampleHits /*   (int_T *) */
#endif


#if !SS_SFCN_LEVEL_1
#if SS_SIM

typedef struct _ssRegisterTypeFromNameType_tag {
    const char* name;
    int* dataTypeId;
} ssRegisterTypeFromNameType;

#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif
extern real_T* _ssGetAbsTol(SimStruct* S);
extern void _ssSetStateAbsTol(SimStruct* S, const int_T idx, const real_T val);

#ifdef __cplusplus
}
#endif



#ifndef _DIMSDEPENDINFO_T
#define _DIMSDEPENDINFO_T

/* Set the current dimension of output port outIdx based on the dims dependent rule ruleIdx */
typedef void (*SetOutputDimsFcn)(SimStruct* S, int outIdx, int* inps, int numInps);
/*
 * RTWCG function of setting the current dimension of output port outIdx based
 * on the dims dependent rule ruleIdx
 */
typedef void (*SetOutputDimsRTWCGFcn)(SimStruct* S, void* rtwBlk, int oIdx, int* inps, int nInputs);

typedef struct {
    int* inputs;                       /* index to inputs whose dims affect the output dims*/
    int numInputs;                     /* number of inputs affect the output dims */
    SetOutputDimsFcn setOutputDimsFcn; /* function to update the output dims
                                          based on the dims of inputs*/
    SetOutputDimsRTWCGFcn setOutputDimsRTWCGFcn;
    /* RTWCG function to update output dims
       based on the dims of inputs */
} DimsDependInfo_T;

#endif



typedef void (*mdlSetInputPortDimensionsModeFcn)(SimStruct* S,
                                                 int_T portIdx,
                                                 DimensionsMode_T dimsMode);



/* ssSetSFcnParamTunable - This should be used by S-function blocks
 *   to specify when a parameter is tunable or not tunable.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetSFcnParamNotTunable(S, index) \
    (S)->sfcnParams.dlgAttribs[index] = ((S)->sfcnParams.dlgAttribs[index] | SFCNPARAM_NOT_TUNABLE)
#else                                      /* RT or NRT */
#define ssSetSFcnParamNotTunable(S, index) /* do nothing */
#endif


#define ssSetInputPortSignalWhenNeeded(S, port, val) \
    (S)->portInfo.inputs[(port)].attributes.cinId = (val)



#if SS_SIM
#define ssComputeInput(S, pIdx) \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_COMPUTE_INPUT, pIdx, NULL) _ssSafelyCallGenericFcnEnd
#else
#define ssComputeInput(S, pIdx) ssComputeInput_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define dtaSetErrorString(dta, string) ((dta) != NULL ? (dta)->errorString = (string) : 0)
#else
#define dtaSetErrorString(dta, string) dtaSetErrorString_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define dtaSetConvertBetweenFcn(dta, blockPath, id, fcn)                                         \
    ((dta) != NULL ? (dta)->setConvertBetweenFcn((dta)->dataTypeTable, (blockPath), (id), (fcn)) \
                   : 0)
#else
#define dtaSetConvertBetweenFcn(dta, blockPath, id, fcn) \
    dtaSetConvertBetweenFcn_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define dtaSetIsPositiveFcn(dta, blockPath, id, fcn)                                         \
    ((dta) != NULL ? (dta)->setGenericDTAUnaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                    (fcn), GEN_DTA_UNARY_FCN_IS_POSITIVE)    \
                   : 0)
#else
#define dtaSetIsPositiveFcn(dta, blockPath, id, fcn) dtaSetIsPositiveFcn_cannot_be_used_in_RTW
#endif



#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#ifdef ssGetOwnerBlock
#define ssSetInputPortBusMode(S, pIdx, value)                                            \
    {                                                                                    \
        if (ssGetOwnerBlock(S) != NULL) {                                                \
            BusMode_T val = value;                                                       \
            _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_INPUT_BUS_MODE, pIdx, &val) \
                _ssSafelyCallGenericFcnEnd;                                              \
        }                                                                                \
    }

#define ssSetOutputPortBusMode(S, pIdx, value)                                            \
    {                                                                                     \
        if (ssGetOwnerBlock(S) != NULL) {                                                 \
            BusMode_T val = value;                                                        \
            _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_OUTPUT_BUS_MODE, pIdx, &val) \
                _ssSafelyCallGenericFcnEnd;                                               \
        }                                                                                 \
    }
#else
#define ssSetInputPortBusMode(S, pIdx, value)
#define ssSetOutputPortBusMode(S, pIdx, value)
#endif
#else
#define ssSetInputPortBusMode(S, pIdx, value)
#define ssSetOutputPortBusMode(S, pIdx, value)
#endif


#if SS_SIM
#define dtaGetDataTypeElementOffset(dta, blockPath, id, eIdx)                                 \
    ((dta) != NULL ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), \
                                                     (eIdx), GEN_DTA_INT_PROP_ELEMENT_OFFSET) \
                   : -1)
#else
#define dtaGetDataTypeElementOffset(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementOffset_cannot_be_used_in_RTW
#endif



#define ssGetTNextWasAdjusted(S, sti) ((S)->mdlInfo->tNextWasAdjusted[sti]) /* (boolean_T) */


/* InputPortAcceptExprInRTW - Specify that the input port signal can be
 * an expression in RTW.  This allows the block to fold an upstream
 * calculation into its own.
 */
#define ssGetInputPortAcceptExprInRTW(S, port) \
    ((S)->portInfo.inputs[(port)].attributes.acceptExprInRTW == 1U)
#define ssSetInputPortAcceptExprInRTW(S, port, val) \
    ((S)->portInfo.inputs[(port)].attributes.acceptExprInRTW = (val) ? 1U : 0U)

/* OutputPortOutputExprInRTW - Specify that the output signal is an expression
 * in RTW (versus a statement).  This allows a downstream block to fold
 * the expression into its calculation.  Note that Simulink may not honor
 * this setting, in which case the block must produce a statement.
 */
#define ssGetOutputPortOutputExprInRTW(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.outputExprInRTW == 1U)
#define ssSetOutputPortOutputExprInRTW(S, port, val)                                \
    ((S)->portInfo.outputs[(port)].attributes.outputExprInRTW =                     \
         (val) ? 1U                                                                 \
               : ((S)->portInfo.outputs[(port)].attributes.trivialOutputExprInRTW = \
                      (S)->portInfo.outputs[(port)].attributes.constOutputExprInRTW = 0U))

#define ssSetmdlOutputs(S, outputs) (S)->modelMethods.sFcn.mdlOutputs.level2 = (outputs)

#if SS_SIM
#define dtaGetDataTypeIdAliasedThruTo(dta, blockPath, id)                                 \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_ID_ALIASED_THRU_TO)     \
                   : INVALID_DTYPE_ID)
#else
#define dtaGetDataTypeIdAliasedThruTo(dta, blockPath, id) \
    dtaGetDataTypeIdAliasedThruTo_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define dtaGetErrorString(dta) ((dta) != NULL ? (dta)->errorString : NULL)
#else
#define dtaGetErrorString(dta) dtaGetErrorString_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define dtaRegisterDataTypeWithCheck(dta, blockPath, name, idptr)                                  \
    ((dta) != NULL ? (dta)->registerFcnWithCheck((dta)->dataTypeTable, (blockPath), (name), idptr) \
                   : NULL)
#else
#define dtaRegisterDataTypeWithCheck(dta, blockPath, name, idptr) \
    dtaRegisterDataType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaRegisterDataType(dta, blockPath, name)                                  \
    ((dta) != NULL ? (dta)->registerFcn((dta)->dataTypeTable, (blockPath), (name)) \
                   : INVALID_DTYPE_ID)
#else
#define dtaRegisterDataType(dta, blockPath, name) dtaRegisterDataType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetNumDataTypes(dta) \
    ((dta) != NULL ? (dta)->getNumDataTypesFcn((dta)->dataTypeTable) : INVALID_NUM_DTYPES)
#else
#define dtaGetNumDataTypes(dta) dtaGetNumDataTypes_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeId(dta, name) \
    ((dta) != NULL ? (dta)->getIdFcn((dta)->dataTypeTable, (name)) : INVALID_DTYPE_ID)
#else
#define dtaGetDataTypeId(dta, name) dtaGetDataTypeId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeName(dta, blockPath, id)                                             \
    ((dta) != NULL ? (dta)->getGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id), \
                                                  GEN_DTA_VOID_PROP_NAME)                  \
                   : NULL)
#else
#define dtaGetDataTypeName(dta, blockPath, id) dtaGetDataTypeName_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define dtaSetDataTypeSize(dta, blockPath, id, size)                                              \
    ((dta) != NULL ? (dta)->setGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), (size), \
                                                 GEN_DTA_INT_PROP_SIZE)                           \
                   : 0)
#else
#define dtaSetDataTypeSize(dta, blockPath, id, size) dtaSetDataTypeSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeStorageId(dta, blockPath, id)                                       \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_STORAGE_ID)             \
                   : INVALID_DTYPE_ID)
#else
#define dtaGetDataTypeStorageId(dta, blockPath, id) dtaGetDataTypeStorageId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDataTypeStorageId(dta, blockPath, id, storageId)                             \
    ((dta) != NULL ? (dta)->setGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id),  \
                                                 (storageId), GEN_DTA_INT_PROP_STORAGE_ID) \
                   : 0)
#else
#define dtaSetDataTypeStorageId(dta, blockPath, id, storageId) \
    dtaSetDataTypeStorageId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeIdAliasedTo(dta, blockPath, id)                                     \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_ID_ALIASED_TO)          \
                   : INVALID_DTYPE_ID)
#else
#define dtaGetDataTypeIdAliasedTo(dta, blockPath, id) \
    dtaGetDataTypeIdAliasedTo_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDataTypeIdAliasedTo(dta, blockPath, id, idAliasedTo)                              \
    ((dta) != NULL ? (dta)->setGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id),       \
                                                 (idAliasedTo), GEN_DTA_INT_PROP_ID_ALIASED_TO) \
                   : 0)
#else
#define dtaSetDataTypeIdAliasedTo(dta, blockPath, id, idAliasedTo) \
    dtaSetDataTypeIdAliasedTo_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define dtaGetDataTypeZero(dta, blockPath, id)                                             \
    ((dta) != NULL ? (dta)->getGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id), \
                                                  GEN_DTA_VOID_PROP_ZERO)                  \
                   : NULL)
#else
#define dtaGetDataTypeZero(dta, blockPath, id) dtaGetDataTypeZero_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDataTypeZero(dta, blockPath, id, zero)                                               \
    ((dta) != NULL ? (dta)->setGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id), (zero), \
                                                  GEN_DTA_VOID_PROP_ZERO)                          \
                   : 0)
#else
#define dtaSetDataTypeZero(dta, blockPath, id, zero) dtaSetDataTypeZero_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeProperties(dta, blockPath, id)                                       \
    ((dta) != NULL ? (dta)->getGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id), \
                                                  GEN_DTA_VOID_PROP_PROPERTIES)            \
                   : NULL)
#else
#define dtaGetDataTypeProperties(dta, blockPath, id) dtaGetDataTypeProperties_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDataTypeProperties(dta, blockPath, id, properties)                              \
    ((dta) != NULL ? (dta)->setGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id),    \
                                                  (properties), GEN_DTA_VOID_PROP_PROPERTIES) \
                   : 0)
#else
#define dtaSetDataTypeProperties(dta, blockPath, id, properties) \
    dtaSetDataTypeProperties_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeObject(dta, blockPath, id)                                           \
    ((dta) != NULL ? (dta)->getGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id), \
                                                  GEN_DTA_VOID_PROP_OBJECT)                \
                   : NULL)
#else
#define dtaGetDataTypeObject(dta, blockPath, id) dtaGetDataTypeObject_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeCGType(dta, blockPath, id)                                           \
    ((dta) != NULL ? (dta)->getGenericDTAVoidProp((dta)->dataTypeTable, (blockPath), (id), \
                                                  GEN_DTA_VOID_PROP_CGTYPE)                \
                   : NULL)
#else
#define dtaGetDataTypeCGType(dta, blockPath, id) dtaGetDataTypeCGType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypePropertiesSize(dta, blockPath, id)                                  \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_PROPERTIES_SIZE)        \
                   : INVALID_DTYPE_SIZE)
#else
#define dtaGetDataTypePropertiesSize(dta, blockPath, id) \
    dtaGetDataTypePropertiesSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDataTypePropertiesSize(dta, blockPath, id, size)                                    \
    ((dta) != NULL ? (dta)->setGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), (size), \
                                                 GEN_DTA_INT_PROP_PROPERTIES_SIZE)                \
                   : 0)
#else
#define dtaSetDataTypePropertiesSize(dta, blockPath, id, size) \
    dtaSetDataTypePropertiesSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeNumElements(dta, blockPath, id)                                     \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_NUM_ELEMENTS)           \
                   : -1)
#else
#define dtaGetDataTypeNumElements(dta, blockPath, id) \
    dtaGetDataTypeNumElements_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeIsBus(dta, blockPath, id)                                           \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_IS_BUS)                 \
                   : -1)
#else
#define dtaGetDataTypeIsBus(dta, blockPath, id) dtaGetDataTypeIsBus_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeIsBusWithVarDimsElement(dta, blockPath, id)                              \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id),      \
                                                 GEN_DTA_INT_PROP_IS_BUS_WITH_VARDIMS_ELEMENT) \
                   : -1)
#else
#define dtaGetDataTypeIsBusWithVarDimsElement(dta, blockPath, id) \
    dtaGetDataTypeIsBusWithVarDimsElement_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeVarDimsSize(dta, blockPath, id)                                     \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_VARDIMS_SIZE)           \
                   : INVALID_DTYPE_SIZE)
#else
#define dtaGetDataTypeVarDimsSize(dta, blockPath, id) \
    dtaGetDataTypeVarDimsSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementDataType(dta, blockPath, id, eIdx)                                  \
    ((dta) != NULL ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id),    \
                                                     (eIdx), GEN_DTA_INT_PROP_ELEMENT_DATA_TYPE) \
                   : INVALID_DTYPE_ID)
#else
#define dtaGetDataTypeElementDataType(dta, blockPath, id, eIdx)                            \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ELEMENT_DATA_TYPE)              \
         : INVALID_DTYPE_ID)
#endif
#else
#define dtaGetDataTypeElementDataType(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementDataType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementSignalType(dta, blockPath, id, eIdx)                                  \
    ((dta) != NULL ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id),      \
                                                     (eIdx), GEN_DTA_INT_PROP_ELEMENT_SIGNAL_TYPE) \
                   : INVALID_DTYPE_ID)
#else
#define dtaGetDataTypeElementSignalType(dta, blockPath, id, eIdx)                          \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ELEMENT_SIGNAL_TYPE)            \
         : INVALID_DTYPE_ID)
#endif
#else
#define dtaGetDataTypeElementSignalType(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementSignalType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementNumDimensions(dta, blockPath, id, eIdx)                        \
    ((dta) != NULL                                                                          \
         ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_INT_PROP_ELEMENT_NUM_DIMENSIONS)         \
         : -1)
#else
#define dtaGetDataTypeElementNumDimensions(dta, blockPath, id, eIdx)                       \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ELEMENT_NUM_DIMENSIONS)         \
         : -1)
#endif
#else
#define dtaGetDataTypeElementNumDimensions(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementNumDimensions_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementDimensionsMode(dta, blockPath, id, eIdx)                       \
    ((dta) != NULL                                                                          \
         ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_INT_PROP_ELEMENT_DIMENSIONS_MODE)        \
         : -1)
#else
#define dtaGetDataTypeElementDimensionsMode(dta, blockPath, id, eIdx)                      \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ELEMENT_DIMENSIONS_MODE)        \
         : -1)
#endif
#else
#define dtaGetDataTypeElementDimensionsMode(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementDimensionsMode_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementVarDimsOffset(dta, blockPath, id, eIdx)                        \
    ((dta) != NULL                                                                          \
         ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_INT_PROP_ELEMENT_VARDIMS_OFFSET)         \
         : -1)
#else
#define dtaGetDataTypeElementVarDimsOffset(dta, blockPath, id, eIdx)                       \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ELEMENT_VARDIMS_OFFSET)         \
         : -1)
#endif
#else
#define dtaGetDataTypeElementVarDimsOffset(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementVarDimsOffset_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementName(dta, blockPath, id, eIdx)                                        \
    ((dta) != NULL                                                                                 \
         ? ((const char*)(dta)->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), \
                                                          (eIdx), GEN_DTA_VOID_PROP_ELEMENT_NAME)) \
         : "")
#else
#define dtaGetDataTypeElementName(dta, blockPath, id, eIdx)                                  \
    ((dta) != NULL && (dta->access64) != NULL                                                \
         ? ((const char*)(dta->access64)                                                     \
                ->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                            GEN_DTA_VOID_PROP_ELEMENT_NAME))                 \
         : "")
#endif
#else
#define dtaGetDataTypeElementName(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementName_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementDimensions(dta, blockPath, id, eIdx)         \
    ((dta) != NULL ? ((const int_T*)(dta)->getGenericDTAVoidElemProp(     \
                         (dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                         GEN_DTA_VOID_PROP_ELEMENT_DIMENSIONS))           \
                   : NULL)
#else
#define dtaGetDataTypeElementDimensions(dta, blockPath, id, eIdx)                            \
    ((dta) != NULL && (dta->access64) != NULL                                                \
         ? ((const int64_T*)(dta->access64)                                                  \
                ->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                            GEN_DTA_VOID_PROP_ELEMENT_DIMENSIONS_64))        \
         : NULL)
#endif
#else
#define dtaGetDataTypeElementDimensions(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementDimensions_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementMin(dta, blockPath, id, eIdx)                                     \
    ((dta) != NULL ? (dta)->getGenericDTARealElemProp((dta)->dataTypeTable, (blockPath), (id), \
                                                      (eIdx), GEN_DTA_REAL_PROP_ELEMENT_MIN)   \
                   : -(mxGetInf()))
#else
#define dtaGetDataTypeElementMin(dta, blockPath, id, eIdx)                                  \
    ((dta) != NULL && (dta->access64) != NULL                                               \
         ? (dta->access64)                                                                  \
               ->getGenericDTARealElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_REAL_PROP_ELEMENT_MIN)                   \
         : -(mxGetInf()))
#endif
#else
#define dtaGetDataTypeElementMin(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementMin_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementMax(dta, blockPath, id, eIdx)                                     \
    ((dta) != NULL ? (dta)->getGenericDTARealElemProp((dta)->dataTypeTable, (blockPath), (id), \
                                                      (eIdx), GEN_DTA_REAL_PROP_ELEMENT_MAX)   \
                   : mxGetInf())
#else
#define dtaGetDataTypeElementMax(dta, blockPath, id, eIdx)                                  \
    ((dta) != NULL && (dta->access64) != NULL                                               \
         ? (dta->access64)                                                                  \
               ->getGenericDTARealElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_REAL_PROP_ELEMENT_MAX)                   \
         : mxGetInf())
#endif
#else
#define dtaGetDataTypeElementMax(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementMax_cannot_be_used_in_RTW
#endif


#if SS_SIM
#if !defined(SFCN64)
#define dtaGetDataTypeElementUnitId(dta, blockPath, id, eIdx)                                  \
    ((dta) != NULL ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id),  \
                                                     (eIdx), GEN_DTA_INT_PROP_ELEMENT_UNIT_ID) \
                   : -1)
#else
#define dtaGetDataTypeElementUnitId(dta, blockPath, id, eIdx)                              \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ELEMENT_UNIT_ID)                \
         : -1)
#endif
#else
#define dtaGetDataTypeElementUnitId(dta, blockPath, id, eIdx) \
    dtaGetDataTypeElementUnitId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataTypeIsEnumType(dta, blockPath, id)                                      \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_IS_ENUMTYPE)            \
                   : -1)
#else
#define dtaGetDataTypeIsEnumType(dta, blockPath, id) dtaGetDataTypeIsEnumType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetEnumTypeNumStrings(dta, blockPath, id)                                      \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_ENUMTYPE_NUMSTRINGS)    \
                   : -1)
#else
#define dtaGetEnumTypeNumStrings(dta, blockPath, id, eIdx) \
    dtaGetEnumTypeNumStrings_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetEnumTypeIndexOfDefault(dta, blockPath, id)                                     \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id),    \
                                                 GEN_DTA_INT_PROP_ENUMTYPE_INDEX_OF_DEFAULT) \
                   : -1)
#else
#define dtaGetEnumTypeIndexOfDefault(dta, blockPath, id) \
    dtaGetEnumTypeIndexOfDefault_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetEnumTypeAddPrefix(dta, blockPath, id)                                                \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id),          \
                                                 GEN_DTA_INT_PROP_ENUMTYPE_ADD_TYPENAME_AS_PREFIX) \
                   : -1)
#else
#define dtaGetEnumTypeAddPrefix(dta, blockPath, id) dtaGetEnumTypeAddPrefix_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetEnumTypeStorageId(dta, blockPath, id)                                       \
    ((dta) != NULL ? (dta)->getGenericDTAIntProp((dta)->dataTypeTable, (blockPath), (id), \
                                                 GEN_DTA_INT_PROP_STORAGE_ID)             \
                   : -1)
#else
#define dtaGetEnumTypeStorageId(dta, blockPath, id) dtaGetEnumTypeStorageId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetEnumTypeIndexFromValue(dta, blockPath, id, eValue)                              \
    ((dta) != NULL                                                                            \
         ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eValue), \
                                           GEN_DTA_INT_PROP_ENUMTYPE_INDEX_FROM_VALUE)        \
         : -1)
#else
#define dtaGetEnumTypeIndexFromValue(dta, blockPath, id, eValue)                             \
    ((dta) != NULL && (dta->access64) != NULL                                                \
         ? (dta->access64)                                                                   \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eValue), \
                                          GEN_DTA_INT_PROP_ENUMTYPE_INDEX_FROM_VALUE)        \
         : -1)
#endif
#else
#define dtaGetEnumTypeIndexFromValue(dta, blockPath, id, eValue) \
    dtaGetEnumTypeIndexFromValue_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetEnumTypeValueFromIndex(dta, blockPath, id, eIdx)                              \
    ((dta) != NULL                                                                          \
         ? (dta)->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_INT_PROP_ENUMTYPE_VALUE_FROM_INDEX)      \
         : -1)
#else
#define dtaGetEnumTypeValueFromIndex(dta, blockPath, id, eIdx)                             \
    ((dta) != NULL && (dta->access64) != NULL                                              \
         ? (dta->access64)                                                                 \
               ->getGenericDTAIntElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                          GEN_DTA_INT_PROP_ENUMTYPE_VALUE_FROM_INDEX)      \
         : -1)
#endif
#else
#define dtaGetEnumTypeValueFromIndex(dta, blockPath, id, eIdx) \
    dtaGetEnumTypeValueFromIndex_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetEnumTypeStringFromValue(dta, blockPath, id, eIdx)                              \
    ((dta) != NULL                                                                           \
         ? (dta)->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                            GEN_DTA_VOID_PROP_ENUMTYPE_STRING_FROM_VALUE)    \
         : NULL)
#else
#define dtaGetEnumTypeStringFromValue(dta, blockPath, id, eIdx)                             \
    ((dta->access) != NULL                                                                  \
         ? (dta->access)                                                                    \
               ->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_VOID_PROP_ENUMTYPE_STRING_FROM_VALUE)    \
         : NULL)
#endif
#else
#define dtaGetEnumTypeStringFromValue(dta, blockPath, id, eIdx) \
    dtaGetEnumTypeStringFromValue_cannot_be_used_in_RTW
#endif

#if SS_SIM
#if !defined(SFCN64)
#define dtaGetEnumTypeStringFromIndex(dta, blockPath, id, eIdx)                              \
    ((dta) != NULL                                                                           \
         ? (dta)->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                            GEN_DTA_VOID_PROP_ENUMTYPE_STRING_FROM_INDEX)    \
         : NULL)
#else
#define dtaGetEnumTypeStringFromIndex(dta, blockPath, id, eIdx)                             \
    ((dta) != NULL && (dta->access64) != NULL                                               \
         ? (dta->access64)                                                                  \
               ->getGenericDTAVoidElemProp((dta)->dataTypeTable, (blockPath), (id), (eIdx), \
                                           GEN_DTA_VOID_PROP_ENUMTYPE_STRING_FROM_INDEX)    \
         : NULL)
#endif
#else
#define dtaGetEnumTypeStringFromIndex(dta, blockPath, id, eIdx) \
    dtaGetEnumTypeStringFromIndex_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetConvertBetweenFcn(dta, blockPath, id) \
    ((dta) != NULL ? (dta)->getConvertBetweenFcn((dta)->dataTypeTable, (blockPath), (id)) : NULL)
#else
#define dtaGetConvertBetweenFcn(dta, blockPath, id) dtaGetConvertBetweenFcn_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define dtaCallConvertBetweenForSrcId(dta, blockPath, dstId, srcId, numEls, u, options, y) \
    (dtaGetConvertBetweenFcn((dta), (blockPath), (srcId)) != NULL                          \
         ? dtaGetConvertBetweenFcn((dta), (blockPath), (srcId))(                           \
               (dta), (blockPath), (dstId), (srcId), (numEls), (u), (options), (y))        \
         : 0)
#else
#define dtaCallConvertBetweenForSrcId(dta, blockPath, dstId, srcId, numEls, u, options, y) \
    dtaCallConvertBetweenForSrcId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallConvertBetweenForDstId(dta, blockPath, dstId, srcId, numEls, u, options, y) \
    (dtaGetConvertBetweenFcn((dta), (blockPath), (dstId)) != NULL                          \
         ? dtaGetConvertBetweenFcn((dta), (blockPath), (dstId))(                           \
               (dta), (blockPath), (dstId), (srcId), (numEls), (u), (options), (y))        \
         : 0)
#else
#define dtaCallConvertBetweenForDstId(dta, blockPath, dstId, srcId, numEls, u, options, y) \
    dtaCallConvertBetweenForDstId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetConstructFcn(dta, blockPath, id) \
    ((dta) != NULL ? (dta)->getConstructFcn((dta)->dataTypeTable, (blockPath), (id)) : NULL)
#else
#define dtaGetConstructFcn(dta, blockPath, id) dtaGetConstructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetConstructFcn(dta, blockPath, id, fcn) \
    ((dta) != NULL ? (dta)->setConstructFcn((dta)->dataTypeTable, (blockPath), (id), (fcn)) : 0)
#else
#define dtaSetConstructFcn(dta, blockPath, id, fcn) dtaSetConstructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallConstruct(dta, blockPath, id, u)              \
    (dtaGetConstructFcn((dta), (blockPath), (id)) != NULL    \
         ? dtaGetConstructFcn((dta), (blockPath), (id))((u)) \
         : 0)
#else
#define dtaCallConstruct(dta, blockPath, id, u) dtaCallConstruct_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDestructFcn(dta, blockPath, id) \
    ((dta) != NULL ? (dta)->getDestructFcn((dta)->dataTypeTable, (blockPath), (id)) : NULL)
#else
#define dtaGetDestructFcn(dta, blockPath, id) dtaGetDestructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDestructFcn(dta, blockPath, id, fcn) \
    ((dta) != NULL ? (dta)->setDestructFcn((dta)->dataTypeTable, (blockPath), (id), (fcn)) : 0)
#else
#define dtaSetDestructFcn(dta, blockPath, id, fcn) dtaSetDestructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallDestruct(dta, blockPath, id, u)              \
    (dtaGetDestructFcn((dta), (blockPath), (id)) != NULL    \
         ? dtaGetDestructFcn((dta), (blockPath), (id))((u)) \
         : 0)
#else
#define dtaCallDestruct(dta, blockPath, id, u) dtaCallDestruct_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDeepCopyFcn(dta, blockPath, id) \
    ((dta) != NULL ? (dta)->getDeepCopyFcn((dta)->dataTypeTable, (blockPath), (id)) : NULL)
#else
#define dtaGetDeepCopyFcn(dta, blockPath, id) dtaGetDeepCopyFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDeepCopyFcn(dta, blockPath, id, fcn) \
    ((dta) != NULL ? (dta)->setDeepCopyFcn((dta)->dataTypeTable, (blockPath), (id), (fcn)) : 0)
#else
#define dtaSetDeepCopyFcn(dta, blockPath, id, fcn) dtaSetDeepCopyFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallDeepCopy(dta, blockPath, id, y, u)                \
    (dtaGetDeepCopyFcn((dta), (blockPath), (id)) != NULL         \
         ? dtaGetDeepCopyFcn((dta), (blockPath), (id))((y), (u)) \
         : 0)
#else
#define dtaCallDeepCopy(dta, blockPath, id, y, options, u) dtaCallDeepCopy_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetSerializeFcn(dta, id) \
    ((dta) != NULL ? (dta)->getSerializeFcn((dta)->dataTypeTable, (id)) : NULL)
#else
#define dtaGetSerializeFcn(dta, id) dtaGetSerializeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetSerializeFcn(dta, id, fcn) \
    ((dta) != NULL ? (dta)->setSerializeFcn((dta)->dataTypeTable, (id), (fcn)) : 0)
#else
#define dtaSetSerializeFcn(dta, id, fcn) dtaSetSerializeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallSerialize(dta, id, y, u, w, o)                                                      \
    (dtaGetSerializeFcn((dta), (id)) != NULL ? dtaGetSerializeFcn((dta), (id))((y), (u), (w), (o)) \
                                             : 0)
#else
#define dtaCallSerialize(dta, id, y, options, u, w, o) dtaCallSerialize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDeserializeFcn(dta, id) \
    ((dta) != NULL ? (dta)->getDeserializeFcn((dta)->dataTypeTable, (id)) : NULL)
#else
#define dtaGetDeserializeFcn(dta, id) dtaGetDeserializeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetDeserializeFcn(dta, id, fcn) \
    ((dta) != NULL ? (dta)->setDeserializeFcn((dta)->dataTypeTable, (id), (fcn)) : 0)
#else
#define dtaSetDeserializeFcn(dta, id, fcn) dtaSetDeserializeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallDeserialize(dta, id, y, u, w, o)                  \
    (dtaGetDeserializeFcn((dta), (id)) != NULL                   \
         ? dtaGetDeserializeFcn((dta), (id))((y), (u), (w), (o)) \
         : 0)
#else
#define dtaCallDeserialize(dta, id, y, options, u, w, o) dtaCallDeserialize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetSerializeSizeFcn(dta, id) \
    ((dta) != NULL ? (dta)->getSerializeSizeFcn((dta)->dataTypeTable, (id)) : NULL)
#else
#define dtaGetSerializeSizeFcn(dta, id) dtaGetSerializeSizeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetSerializeSizeFcn(dta, id, fcn) \
    ((dta) != NULL ? (dta)->setSerializeSizeFcn((dta)->dataTypeTable, (id), (fcn)) : 0)
#else
#define dtaSetSerializeSizeFcn(dta, id, fcn) dtaSetSerializeSizeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallSerializeSize(dta, id, y, u)                                                      \
    (dtaGetSerializeSizeFcn((dta), (id)) != NULL ? dtaGetSerializeSizeFcn((dta), (id))((y), (u)) \
                                                 : 0)
#else
#define dtaCallSerializeSize(dta, id, y, options, u) dtaCallSerializeSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetIsPositiveFcn(dta, blockPath, id)                                              \
    ((dta) != NULL ? (dta)->getGenericDTAUnaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                    GEN_DTA_UNARY_FCN_IS_POSITIVE)           \
                   : NULL)
#else
#define dtaGetIsPositiveFcn(dta, blockPath, id) dtaGetIsPositiveFcn_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define dtaCallIsPositive(dta, blockPath, id, numEls, u, options, y)                              \
    (dtaGetIsPositiveFcn((dta), (blockPath), (id)) != NULL                                        \
         ? dtaGetIsPositiveFcn((dta), (blockPath), (id))((dta), (blockPath), (id), (numEls), (u), \
                                                         (options), (y))                          \
         : 0)
#else
#define dtaCallIsPositive(dta, blockPath, id, numEls, u, options, y) \
    dtaCallIsPositive_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetIsNegativeFcn(dta, blockPath, id)                                              \
    ((dta) != NULL ? (dta)->getGenericDTAUnaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                    GEN_DTA_UNARY_FCN_IS_NEGATIVE)           \
                   : NULL)
#else
#define dtaGetIsNegativeFcn(dta, blockPath, id) dtaGetIsNegativeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetIsNegativeFcn(dta, blockPath, id, fcn)                                         \
    ((dta) != NULL ? (dta)->setGenericDTAUnaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                    (fcn), GEN_DTA_UNARY_FCN_IS_NEGATIVE)    \
                   : 0)
#else
#define dtaSetIsNegativeFcn(dta, blockPath, id, fcn) dtaSetIsNegativeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallIsNegative(dta, blockPath, id, numEls, u, options, y)                              \
    (dtaGetIsNegativeFcn((dta), (blockPath), (id)) != NULL                                        \
         ? dtaGetIsNegativeFcn((dta), (blockPath), (id))((dta), (blockPath), (id), (numEls), (u), \
                                                         (options), (y))                          \
         : 0)
#else
#define dtaCallIsNegative(dta, blockPath, id, numEls, u, options, y) \
    dtaCallIsNegative_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetGreaterThanFcn(dta, blockPath, id)                                              \
    ((dta) != NULL ? (dta)->getGenericDTABinaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                     GEN_DTA_BINARY_FCN_GREATER_THAN)         \
                   : NULL)
#else
#define dtaGetGreaterThanFcn(dta, blockPath, id) dtaGetGreaterThanFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetGreaterThanFcn(dta, blockPath, id, fcn)                                         \
    ((dta) != NULL ? (dta)->setGenericDTABinaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                     (fcn), GEN_DTA_BINARY_FCN_GREATER_THAN)  \
                   : 0)
#else
#define dtaSetGreaterThanFcn(dta, blockPath, id, fcn) dtaSetGreaterThanFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallGreaterThan(dta, blockPath, id, numEls, u1, u2, options, y)                    \
    (dtaGetGreaterThanFcn((dta), (blockPath), (id)) != NULL                                   \
         ? dtaGetGreaterThanFcn((dta), (blockPath), (id))((dta), (blockPath), (id), (numEls), \
                                                          (u1), (u2), (options), (y))         \
         : 0)
#else
#define dtaCallGreaterThan(dta, blockPath, id, numEls, u1, u2, options, y) \
    dtaCallGreaterThan_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetGreaterEqualFcn(dta, blockPath, id)                                             \
    ((dta) != NULL ? (dta)->getGenericDTABinaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                     GEN_DTA_BINARY_FCN_GREATER_EQUAL)        \
                   : NULL)
#else
#define dtaGetGreaterEqualFcn(dta, blockPath, id) dtaGetGreaterEqualFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaSetGreaterEqualFcn(dta, blockPath, id, fcn)                                        \
    ((dta) != NULL ? (dta)->setGenericDTABinaryFcnGW((dta)->dataTypeTable, (blockPath), (id), \
                                                     (fcn), GEN_DTA_BINARY_FCN_GREATER_EQUAL) \
                   : 0)
#else
#define dtaSetGreaterEqualFcn(dta, blockPath, id, fcn) dtaSetGreaterEqualFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaCallGreaterEqual(dta, blockPath, id, numEls, u1, u2, options, y)                    \
    (dtaGetGreaterEqualFcn((dta), (blockPath), (id)) != NULL                                   \
         ? dtaGetGreaterEqualFcn((dta), (blockPath), (id))((dta), (blockPath), (id), (numEls), \
                                                           (u1), (u2), (options), (y))         \
         : 0)
#else
#define dtaCallGreaterEqual(dta, blockPath, id, numEls, u1, u2, options, y) \
    dtaCallGreaterEqual_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataOverflowDiagnostic(dta, blockPath, result)                           \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath), \
                                                    GEN_DTA_DATA_OVERFLOW, (result))   \
                   : 0)
#else
#define dtaGetDataOverflowDiagnostic(dta, blockPath, result) \
    dtaGetDataOverflowDiagnostic_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetDataSaturationDiagnostic(dta, blockPath, result)                         \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath), \
                                                    GEN_DTA_DATA_SATURATION, (result)) \
                   : 0)
#else
#define dtaGetDataSaturationDiagnostic(dta, blockPath, result) \
    dtaGetDataSaturationDiagnostic_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetInt32ToFloatDiagnostic(dta, blockPath, result)                           \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath), \
                                                    GEN_DTA_INT32_TO_FLOAT, (result))  \
                   : 0)
#else
#define dtaGetInt32ToFloatDiagnostic(dta, blockPath, result) \
    dtaGetInt32ToFloatDiagnostic_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetParameterOverflowDiagnostic(dta, blockPath, result)                         \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath),    \
                                                    GEN_DTA_PARAMETER_OVERFLOW, (result)) \
                   : 0)
#else
#define dtaGetParameterOverflowDiagnostic(dta, blockPath, result) \
    dtaGetParameterOverflowDiagnostic_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetParameterUnderflowDiagnostic(dta, blockPath, result)                         \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath),     \
                                                    GEN_DTA_PARAMETER_UNDERFLOW, (result)) \
                   : 0)
#else
#define dtaGetParameterUnderflowDiagnostic(dta, blockPath, result) \
    dtaGetParameterUnderflowDiagnostic_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetParameterPrecisionLossDiagnostic(dta, blockPath, result)                          \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath),          \
                                                    GEN_DTA_PARAMETER_PRECISION_LOSS, (result)) \
                   : 0)
#else
#define dtaGetParameterPrecisionLossDiagnostic(dta, blockPath, result) \
    dtaGetPrecisionLossDiagnostic_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define dtaGetParameterDowncastDiagnostic(dta, blockPath, result)                         \
    ((dta) != NULL ? (dta)->getGenericDTADiagnostic((dta)->dataTypeTable, (blockPath),    \
                                                    GEN_DTA_PARAMETER_DOWNCAST, (result)) \
                   : 0)
#else
#define dtaGetParameterDowncastDiagnostic(dta, blockPath, result) \
    dtaGetParameterDowncastDiagnostic_cannot_be_used_in_RTW
#endif

#define ssIsMinorTimeStepWithModeChange(S) \
    (S)->mdlInfo->solverInfo->isMinorTimeStepWithModeChange /*  (boolean_T)  */


#endif /* __SIMSTRUC__IMPLEMENT */
