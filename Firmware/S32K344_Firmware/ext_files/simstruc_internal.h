/* Copyright 1990-2023 The MathWorks, Inc. */

/**
 * @file: simstruc_internal.h
 *
 * @brief SimStruct access methods for internal use (subject to changes in
 * future releases), and should not be used for authoring S-functions
 *
 */

#ifndef __SIMSTRUC__INTERNAL
#define __SIMSTRUC__INTERNAL

#include "simstruc_compcond.h"
#include "simstruc_implement.h"
#include "simstruc_internal_types.h"

/*======================================*
 * SimStruct Get and Set Access methods *
 *======================================*/

/*-------------------------------- S->modelName -----------------------------*/

/*
 * ModelName - This is the name of the S-function. When the SimStruct
 *   is being used with the Real-Time Workshop, then the "root" SimStruct
 *   model name corresponds to the name of the Simulink model.
 */

#define _ssSetModelName(S, name) (S)->modelName = (name)
#if !SS_SFCN
#define ssSetModelName(S, name) _ssSetModelName(S, name)
#else
#define ssSetModelName(S, name) ssSetModelName_cannot_be_used_in_SFunctions
#endif

/*-------------------------------- S->path ----------------------------------*/
/*
 * Path - This is the full path to the S-function. When the SimStruct
 *   is being used with the Real-Time Workshop, then the "root" SimStruct
 *   path corresponds to the name of the Simulink model.
 */

#define _ssSetPath(S, pathPtr) (S)->path = (pathPtr)
#if !SS_SFCN
#define ssSetPath(S, pathPtr) _ssSetPath(S, pathPtr)
#else
#define ssSetPath(S, pathPtr) ssSetPath_cannot_be_used_in_SFunctions
#endif

/*-------------------------------- S->parent --------------------------------*/
/*
 * ParentSS - There is one SimStruct for each S-function in your model.
 *   There is also a SimStruct for the model itself. The SimStruct's are
 *   arranged as a tree with the model SimStruct as the root. The ParentSS
 *   field is used to get at the model SimStruct. User written S-functions
 *   should not use the ssSetParentSS macro directly.
 */

#define _ssGetParentSS(S) (S)->parent
#define _ssSetParentSS(S, parentSS) (S)->parent = (parentSS)
#if !SS_SFCN
#define ssSetParentSS(S, parentSS) _ssSetParentSS(S, parentSS)
#else
#define ssSetParentSS(S, parentSS) ssSetParentSS_cannot_be_used_in_SFunctions
#endif

/*-------------------------------- S->root ----------------------------------*/
/*
 * RootSS - This is the "root" SimStruct corresponding to the Simulink
 *   model. DO NOT use this macro in S-Functions.
 */

#define _ssGetRootSS(S) (S)->root
#define _ssSetRootSS(S, rootSS) (S)->root = (rootSS)
#if !SS_SFCN
#define ssSetRootSS(S, rootSS) _ssSetRootSS(S, rootSS)
#else
#define ssSetRootSS(S, rootSS) ssSetRootSS_cannot_be_used_in_SFunctions
#endif

/*----------------------- S->blkInfo.blkInfo2->sfcnBitness -------------------*/
/*
 * This is the bitness of the owning S-Function. It is used to determine the
 * allocation/destruction of fields with corresponding 32-bit and 64-bit
 * equivalents.
 */

#define _ssSetSFcnBitness(S, bitness) (S)->blkInfo.blkInfo2->sfcnBitness = (bitness)
#if !SS_SFCN
#define ssSetSFcnBitness(S, bitness) _ssSetSFcnBitness(S, bitness)
#else
#define ssSetSFcnBitness(S, rootSS) ssSetSFcnBitness_cannot_be_used_in_SFunctions
#endif
#define ssGetSFcnBitness(S) (S)->blkInfo.blkInfo2->sfcnBitness

/*-------------------------------- S->errorStatus ---------------------------*/

/* ErrorStatus - For improved performance and error handling, your S-function
 *   should do:
 *      ssSetErrorStatus(S, "error message");
 *      return;
 *   as opposed to calling mexErrMsgTxt.
 *
 *   Be careful when using ssSetErrorStatus in your S-function. Sometimes you
 *   may wish to use sprintf to format the message. In this case, you
 *   need to allocate memory for the message as opposed to using the stack.
 *   macros _ss[SG]et_slErrMsg and _ssIsErrorStatusAslErrMsg
 *   are intended for internal use only
 */



#define _ssGetErrorStatus(S) \
    ((S)->root->mdlInfo->mdlFlags.errorStatusIsMsg == 1U ? NULL : (S)->root->errorStatus.str)
#define _ssGetLocalErrorStatus(S)                       \
    ((S)->blkInfo.sfcnFlags.localErrorStatusIsMsg == 1U \
         ? NULL                                         \
         : S->blkInfo.blkInfo2->localErrorStatus.str)
#define _ssGet_slErrMsg(S) \
    ((S)->root->mdlInfo->mdlFlags.errorStatusIsMsg == 0U ? NULL : (S)->root->errorStatus.msg)
#define _ssGet_slLocalErrMsg(S)                         \
    ((S)->blkInfo.sfcnFlags.localErrorStatusIsMsg == 0U \
         ? NULL                                         \
         : S->blkInfo.blkInfo2->localErrorStatus.msg)
#define _ssSet_slErrMsg(S, msg_arg)                         \
    {                                                       \
        (S)->root->mdlInfo->mdlFlags.errorStatusIsMsg = 1U; \
        (S)->root->errorStatus.msg = (msg_arg);             \
    }
#define _ssSet_slLocalErrMsg(S, msg_arg)                       \
    {                                                          \
        (S)->blkInfo.sfcnFlags.localErrorStatusIsMsg = 1U;     \
        S->blkInfo.blkInfo2->localErrorStatus.msg = (msg_arg); \
    }
#define _ssIsErrorStatusAslErrMsg(S) ((S)->root->mdlInfo->mdlFlags.errorStatusIsMsg == 1U)
#define _ssIsLocalErrorStatusAslErrMsg(S) ((S)->blkInfo.sfcnFlags.localErrorStatusIsMsg == 1U)

#define _ssReportDiagnosticAsWarning(S, diag)                                           \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REPORT_DIAGNOSTIC_AS_WARNING, 0, diag) \
        _ssSafelyCallGenericFcnEnd

#define _ssReportDiagnosticAsInfo(S, diag)                                           \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REPORT_DIAGNOSTIC_AS_INFO, 0, diag) \
        _ssSafelyCallGenericFcnEnd

#define _ssDiscardDiagnostic(S, diag)                                         \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_DISCARD_DIAGNOSTIC, 0, diag) \
        _ssSafelyCallGenericFcnEnd

#define _ssLongJmp(S, buffer) \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LONGJMP, 0, buffer) _ssSafelyCallGenericFcnEnd

#define SS_ERROR_STATUS_BUFFER_SIZE 1024

#define _ssCopyErrorStatusToBuffer(S, string, size)                   \
    {                                                                 \
        (void)memcpy((S)->root->mdlInfo->errorStatusBuffer, (string), \
                     ((size) > SS_ERROR_STATUS_BUFFER_SIZE - 1)       \
                         ? (SS_ERROR_STATUS_BUFFER_SIZE - 1)          \
                         : (size));                                   \
        ssSetErrorStatus(S, (S)->root->mdlInfo->errorStatusBuffer);   \
    }

#define _ssCopyLocalErrorStatusToBuffer(S, string, size)                         \
    {                                                                            \
        (void)memcpy((S)->blkInfo.blkInfo2->localErrorStatusBuffer, (string),    \
                     ((size) > SS_ERROR_STATUS_BUFFER_SIZE - 1)                  \
                         ? (SS_ERROR_STATUS_BUFFER_SIZE - 1)                     \
                         : (size));                                              \
        ssSetLocalErrorStatus(S, (S)->blkInfo.blkInfo2->localErrorStatusBuffer); \
    }

/*-------------------------------- S->sizes ---------------------------------*/

/* SizesPtr - This is an integer pointer of length SIZES_LENGTH. The
 *   fields in the sizes pointers are defined in the _ssSizes structure
 *   (above).
 */
#define ssGetSizesPtr(S) ((int_T*)&(S)->sizes) /*   (int_T *)     */


/* NumTotalStates - This is the number of continuous plus discrete states
 *   within your S-function. The root SimStruct contains the number of
 *   continuous plus discrete states within the model itself (including all
 *   blocks and S-functions).
 */
#if SS_SFCN_LEVEL_1 || !SS_SFCN
#define ssGetNumTotalStates(S) (ssGetNumContStates(S) + ssGetNumDiscStates(S)) /*   (int_T) */
#endif


/* NumOutputPorts - This is the number of the output ports of your
 * S-function block.
 */
#if !SS_SFCN_LEVEL_1

#define ssSetPortInfoForOutputs(S, ptr) (S)->portInfo.outputs = (ptr)
#define ssGetPortInfoForOutputs(S) (S)->portInfo.outputs
#endif


/* NumInputPorts - This is the number of the input ports of your
 * S-function block.
 */
#if !SS_SFCN_LEVEL_1


#define ssSetPortInfoForInputs(S, ptr) (S)->portInfo.inputs = (ptr)
#define ssGetPortInfoForInputs(S) (S)->portInfo.inputs
#endif

/* AsInt macros should only be used in code allocating and initializing 32-bit
   S-Functions. Currently, this includes simulink engine and sim targets */
#define ssGetNumContStatesAsInt(S) (S)->sizes.numContStates
#define ssSetNumContStatesAsInt(S, nContStates) ((S)->sizes.numContStates = (nContStates))
#define ssGetNumDiscStatesAsInt(S) (S)->sizes.numDiscStates
#define ssSetNumDiscStatesAsInt(S, nDiscStates) ((S)->sizes.numDiscStates = (nDiscStates))
#define ssSetNumNonsampledZCsAsInt(S, nNonsampledZCs) \
    ((S)->sizes.numNonsampledZCs = (nNonsampledZCs))
#define ssSetNumRWorkAsInt(S, nRWork) ((S)->sizes.numRWork = (nRWork))
#define ssSetNumIWorkAsInt(S, nIWork) ((S)->sizes.numIWork = (nIWork))
#define ssSetNumPWorkAsInt(S, nPWork) ((S)->sizes.numPWork = (nPWork))
#define ssSetNumDWorkAsInt(S, nDWork) ((S)->sizes.numDWork = (nDWork))
#define ssSetNumModesAsInt(S, n) ((S)->sizes.numModes = (n))
#define ssSetNumYAsInt(S, ny) ((S)->sizes.out.numY = (ny))
#define ssSetNumUAsInt(S, nu) ((S)->sizes.in.numU = (nu))

/* CAUTION: this is a temporary macro used for the 64-bit S-Function project.
   Do not use this macro. */
#define ssSetNumContStatesSLSize(S, nContStates) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numContStates = (nContStates))

/* This is needed for codegen in file odesup.h */
#define ssGetNumContStatesPtr(S) &((S)->sizes.numContStates)

#define _ssGetSize64ofY(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofY
#define _ssGetSize64ofU(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofU

#if SS_SL_INTERNAL || SS_RTW_INTERNAL || SS_GENERATED_S_FUNCTION
#if defined(USE_64BIT_FIELDS)
/* NumY, SizeofY - This is the length of the root output
 * vector, Y, which is the sum of all the widths of the root outport blocks.
 */
#define ssGetNumY(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numY
#define ssSetNumY(S, ny) ((S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numY = (ny))

#define ssGetSizeofY(S) _ssGetSize64ofY(S)
#define ssSetSizeofY(S, nbytes) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofY = (nbytes)

/* NumU, SizeofU - This is the length of the root input
 * vector, U, which is the sum of all the widths of the root inport blocks.
 */
#define ssGetNumU(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numU
#define ssSetNumU(S, nu) ((S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numU = (nu))

#define ssGetSizeofU(S) _ssGetSize64ofU(S)
#define ssSetSizeofU(S, nbytes) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofU = (nbytes)
#elif defined(USE_32BIT_FIELDS)

/* NumY, SizeofY - This is the length of the root output
 * vector, Y, which is the sum of all the widths of the root outport blocks.
 */
#define ssGetNumY(S) (S)->sizes.out.numY /*   (int_T)       */
#define ssSetNumY(S, ny) (S)->sizes.out.numY = (ny)

#define ssGetSizeofY(S) (S)->sizes.sizeofY /*   (int_T)       */
#define ssSetSizeofY(S, nbytes) (S)->sizes.sizeofY = (nbytes)

/* NumU, SizeofU - This is the length of the root input
 * vector, U, which is the sum of all the widths of the root inport blocks.
 */
#define ssGetNumU(S) (S)->sizes.in.numU /*   (int_T)       */
#define ssSetNumU(S, nu) (S)->sizes.in.numU = (nu)

#define ssGetSizeofU(S) (S)->sizes.sizeofU /*   (int_T)       */
#define ssSetSizeofU(S, nbytes) (S)->sizes.sizeofU = (nbytes)
#endif
#endif

#if SS_SL_INTERNAL || SS_RTW_INTERNAL || SS_GENERATED_S_FUNCTION
#define ssHasParamTable(S, result)                                             \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_HAS_PARAM_TABLE, 0, (result)) \
        _ssSafelyCallGenericFcnEnd

#define ssGetSizeofParams(S, result)                                              \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_SIZE_OF_PARAMS, 0, (result)) \
        _ssSafelyCallGenericFcnEnd
#endif

#if SS_RTW_INTERNAL
/* for backwards compatibility with RTW run-time interface */
#define ssGetNumInputs(S) ssGetNumU(S)
#define ssSetNumInputs(S, nInputs) ssSetNumU(S, nInputs)
#define ssGetNumOutputs(S) ssGetNumY(S)
#define ssSetNumOutputs(S, nOutputs) ssSetNumY(S, nOutputs)
#endif


#if SS_SFCN_LEVEL_1 || SS_GENERATED_S_FUNCTION
/* NumOutputs - This is the size of the output port of your S-function.
 */
#define ssGetNumOutputs(S) (S)->sizes.out.numY /*   (int_T)       */
#define ssSetNumOutputs(S, nOutputs) (S)->sizes.out.numY = (nOutputs)

/* NumInputs - This is the size of the input port of your S-function.
 */
#define ssGetNumInputs(S) (S)->sizes.in.numU /*   (int_T)       */
#define ssSetNumInputs(S, nInputs) (S)->sizes.in.numU = (nInputs)

#elif SS_SFCN_NORMAL

#define ssGetNumOutputs(S) ssGetNumOutputs_cannot_be_used_in_level2_SFunctions
#define ssSetNumOutputs(S) ssGetNumOutputs_cannot_be_used_in_level2_SFunctions
#define ssGetNumInputs(S) ssGetNumInputs_cannot_be_used_in_level2_SFunctions
#define ssSetNumInputs(S) ssSetNumInputs_cannot_be_used_in_level2_SFunctions

#else

#define ssGetNumOutputsLevel1(S) (S)->sizes.out.numY /*   (int_T)       */
#define ssSetNumOutputsLevel1(S, nOutputs) (S)->sizes.out.numY = (nOutputs)

#define ssGetNumInputsLevel1(S) (S)->sizes.in.numU /*   (int_T)       */
#define ssSetNumInputsLevel1(S, nInputs) (S)->sizes.in.numU = (nInputs)

#endif

#define ssGetMexApiInt1(S) (S)->sizes.mexApiInt1 /*   (int_T)       */
#define ssSetMexApiInt1(S, val) (S)->sizes.mexApiInt1 = (val)

#if !SS_SFCN_NORMAL
/* DirectFeedThrough - Does your Level 1 S-function use ssGetU (i.e. u
 *   argument)in mdlOutputs?  For the root SimStruct, this field indicates
 *   whether or not the external input vector is used when executing the
 *   Output function (i.e. MdlOutputs) for the model.
 */
#define ssIsDirectFeedThrough(S) (S)->sizes.sysDirFeedThrough /*   (int_T)       */
#define ssSetDirectFeedThrough(S, dirFeed) (S)->sizes.sysDirFeedThrough = (dirFeed)

#else
#define ssIsDirectFeedThrough(S) ssIsDirectFeedThrough_cannot_be_used_in_level2_SFunctions
#define ssSetDirectFeedThrough(S, dirFeed) \
    ssSetDirectFeedThrough_cannot_be_used_in_level2_SFunctions
#endif

/* NumBlockIO - Number of elements in the model-wide Block IO vector. Only
 *   valid for the root SimStruct. S-function blocks should not use this
 *   field (i.e. set it to 0).
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumBlockIO(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numBlockIO
#define ssSetNumBlockIO(S, nBlockIO) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numBlockIO = (nBlockIO)
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumBlockIO(S) (S)->sizes.numBlockIO /*   (int_T)       */
#define ssSetNumBlockIO(S, nBlockIO) (S)->sizes.numBlockIO = (nBlockIO)
#endif

/* NumBlockParams - Number of parameter elements in the model-wide parameter
 *   vector. Only valid for the root SimStruct. S-function blocks should not
 *   use this field (i.e. set it to 0).
 */
#define ssGetNumBlockParams(S) (S)->sizes.numBlockParams /*   (int_T)       */
#define ssSetNumBlockParams(S, nBlockParams) (S)->sizes.numBlockParams = (nBlockParams)

/* Checksum fields - The checksum fields are primarily used by the root
 *   SimStruct to maintain consistency between Simulink external mode and
 *   the code generated from the Real-Time Workshop. In general, user
 *   written S-function should not use this field.
 */
#define ssGetChecksums(S) (S)->sizes.checksums

#define ssSetChecksumVal(S, idx, val) (S)->sizes.checksums[idx] = (val)
#define ssGetChecksumVal(S, idx) (S)->sizes.checksums[idx]

#define ssGetChecksum0(S) (S)->sizes.checksums[0] /*   (uint32_T)    */
#define ssSetChecksum0(S, val) (S)->sizes.checksums[0] = (val)

#define ssGetChecksum1(S) (S)->sizes.checksums[1] /*   (uint32_T)    */
#define ssSetChecksum1(S, val) (S)->sizes.checksums[1] = (val)

#define ssGetChecksum2(S) (S)->sizes.checksums[2] /*   (uint32_T)    */
#define ssSetChecksum2(S, val) (S)->sizes.checksums[2] = (val)

#define ssGetChecksum3(S) (S)->sizes.checksums[3] /*   (uint32_T)    */
#define ssSetChecksum3(S, val) (S)->sizes.checksums[3] = (val)

/* NumSFunctions - This field is used by the root SimStruct to keep track
 *   of the number of child SimStruct's corresponding to S-function blocks.
 *   This field should not be used by S-function blocks (i.e. should be 0).
 */
#define ssGetNumSFunctions(S) (S)->sizes.numSFunctions /*   (int_T)       */
#define ssSetNumSFunctions(S, nSFunctions) (S)->sizes.numSFunctions = (nSFunctions)

/* NumBlocks - This field is used by the root SimStruct to keep track of
 *   the number of non-virtual blocks within the model. This field should
 *   not be used by S-function blocks (i.e. should be 0).
 */
#define ssGetNumBlocks(S) (S)->sizes.numBlocks /*   (int_T)       */
#define ssSetNumBlocks(S, nBlocks) (S)->sizes.numBlocks = (nBlocks)

/* Version - This field should not be used by S-function blocks directly.
 *   The the simulink.c include file at the bottom of your S-function block
 *   uses this field. It is also used by root SimStruct for versioning.
 */
#define ssGetVersion(S) (S)->sizes.simStructVer /*   (int_T)       */
#define ssSetVersion(S, ver) (S)->sizes.simStructVer = SS_STATIC_CAST(int32_T, ver)

#define ssGetSFcnLevel(S) \
    ((S)->sizes.simStructVer == SS_STATIC_CAST(int32_T, SIMSTRUCT_VERSION_LEVEL2) ? 2 : 1)

/* NumZCEvents - This is the number of zero crossing events within your model.
 *   This field is not for use by S-functions (i.e. should be 0).
 */
#define ssGetNumZCEvents(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numZCEvents
#define ssSetNumZCEvents(S, nZCEvents) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numZCEvents = (nZCEvents)


/* SizeofBlockIO - This is the size of the block I/O vector in bytes.
 *  These should not be used by S-functions (accelerated models need to
 *  set the size though).
 */
#define ssGetSizeofBlockIO(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofBlockIO
#define ssSetSizeofBlockIO(S, n) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofBlockIO = (n)


/* SizeofGlobalBlockIO - This is the size of the global block I/O
 * vector in bytes. This is the size of rtB in the generated code.
 *  These should not be used by S-functions (accelerated models need to
 *  set the size though).
 */
#define ssGetSizeofGlobalBlockIO(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofGlobalBlockIO /*   (int_T)       */
#define ssSetSizeofGlobalBlockIO(S, n) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofGlobalBlockIO = (n)


/* SizeofDWork - This is the size of the data type work vector in bytes.
 *  These should not be used by S-functions (accelerated models need to
 *  set the size though).
 */
#define ssGetSizeofDWork(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofDWork /*   (int_T)       */
#define ssSetSizeofDWork(S, n) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.sizeofDWork = (n)

/* RTWGeneratedSFcn - This is the flag which is set for rtw generated
 * s-function.  Can be removed once all dstates are changed to dworks
 */
#define ssGetRTWGeneratedSFcn(S) (S)->sizes.RTWGeneratedSFcn /*   (int_T)       */
#define ssSetRTWGeneratedSFcn(S, n) (S)->sizes.RTWGeneratedSFcn = (n)

/* HasMdlDimensionsFcn - This is the flag which is set if the block
 * has mdlSetInput(output)PortDimensions function. Not for use by S-functions.
 */
#define ssGetSfcnHasMdlDimensionsFcn(S) \
    (S)->sizes.flags.hasMdlDimensionsFcn /*   (unsigned int_T: 1) */
#define _ssSetSfcnHasMdlDimensionsFcn(S, n) (S)->sizes.flags.hasMdlDimensionsFcn = (n)

/* usesNumPorts - This flag is set by ssSetNumInputPorts and
 * ssSetNumOutputPorts when S is used in Simulink.
 * Not for use by S-functions.
 */
#define ssGetSfcnUsesNumPorts(S) (S)->sizes.flags.usesNumPorts /*   (unsigned int_T: 1) */
#define _ssSetSfcnUsesNumPorts(S, n) (S)->sizes.flags.usesNumPorts = (n)

/* VectMode - This flag is used in Simulink set port dimension methods.
 * See ssVectorMode typedef for valid settings.
 */
#define ssGetVectorMode(S) (S)->sizes.flags.vectMode /*   (unsigned int_T: 4) */

/*
 * ss(Set|Get)TreatAsAtomic - This macro is NOT to be used by
 *                            custom S-Functions.
 */
#define ssGetTreatAsAtomic(S) (S)->sizes.flags.treatAsAtomic /*   (unsigned int_T: 1) */
#define ssSetTreatAsAtomic(S, n) (S)->sizes.flags.treatAsAtomic = (n)
/*
 * ss(Set|Get)HasSubFunctions - This macro is NOT to be used by
 *                              custom S-Functions.
 */
#define ssGetHasSubFunctions(S) (S)->sizes.flags.hasSubFunctions /*   (unsigned int_T: 1) */
#define ssSetHasSubFunctions(S, n) (S)->sizes.flags.hasSubFunctions = (n)

/*
 * ss(Set|Get)CallsOutputInInitFcn - This macro is NOT to be used by
 *                                    custom S-Functions.
 */
#define ssGetCallsOutputInInitFcn(S)                            \
    (S)->sizes.flags.callsOutputInInit /*   (unsigned int_T: 1) \
                                        */
#define ssSetCallsOutputInInitFcn(S, n) (S)->sizes.flags.callsOutputInInit = (n)

/* RTWCG - Block supports CGIR code generation for RTW (instead of TLC).
 */
#define ssGetRTWCG(S) (S)->sizes.flags.rtwcg /*   (unsigned int_T: 1) */
#define ssSetRTWCG(S, n)                                \
    {                                                   \
        (S)->sizes.flags.rtwcg = (n);                   \
        (S)->blkInfo.sfcnFlags.sRowMajorOptIn = 0U;     \
        (S)->blkInfo.sfcnFlags.sReuseAcrossModels = 0U; \
    }

/*
 * mdlProjection may be present but S-Fcn may not want to call it
 */
#define ssSetDisableMdlProjection(S, boolVal) \
    ((S)->sizes.flags.disableMdlProjection = (boolVal) ? 1U : 0U)

#define ssIsMdlProjectionDisabled(S) ((S)->sizes.flags.disableMdlProjection == 1U)

/*
 * mdlSlvrJacobian may be present but S-Fcn may want to call default
   method
 */
#define ssSetDisableMdlSlvrJacobian(S, boolVal) \
    ((S)->sizes.flags.disableMdlSlvrJacobian = (boolVal) ? 1U : 0U)

#define ssIsMdlSlvrJacobianDisabled(S) ((S)->sizes.flags.disableMdlSlvrJacobian == 1U)

/*
 * Query to see if rapid accelerator is active
 * Note that rapid accelerator simulation can have
 * simulation mode != rapid hence we need this query
 */
#define ssSetIsRapidAcceleratorActive(S, boolVal) \
    ((!(S)->parent) ? ((S)->sizes.flags.isRapidAcceleratorActive = (boolVal) ? 1U : 0U) : 0)

/*
 * Query to see if the simstruc is in VM Simulations
 * boolean_T
 */
#define ssGetIsVmSimulationCompile(S)                                                             \
    ((((S)->mdlInfo->genericFcn == NULL)                                                          \
          ? 0                                                                                     \
          : ((*(S)->mdlInfo->genericFcn)((S), GEN_FCN_VM_SIMULATION_COMPILE, 0, (void*)NULL))) == \
     1)
/*
 * Query about the VM Simulations compliance
 */
/*  val is of type (unsigned int: 3) */
#define ssSetVmSimulationsCompliance(S, val) ((S)->sizes.flags.vmSimulationsCompliance = (val))

/*  returns (unsigned int: 3) */
#define ssGetVmSimulationsCompliance(S) ((S)->sizes.flags.vmSimulationsCompliance)



#define ssGetModelReferenceNormalModeSupport(S) \
    SS_STATIC_CAST(ssModelReferenceNormalModeSupport, (S)->sizes.flags.modelRefNormalModeSupport)


/* Method to register that an S-function uses the LibSystemOutputCustomCode
 * or LibSystemUpdateCustomCode methods in TLC either directly or indirectly
 */
#define ssGetUsingTLCCustomCodeFunctions(S) (S)->sizes.flags.usesCustomCodeFcns
#define ssSetUsingTLCCustomCodeFunctions(S, val) (S)->sizes.flags.usesCustomCodeFcns = (val)

/* Method to register that an S-function block can participate in
 * CRL based block replacement
 */
#define ssGetCrlReplacementEnabled(S) (S)->sizes.flags.crlReplacementEnabled
#define ssSetCrlReplacementEnabled(S, val) (S)->sizes.flags.crlReplacementEnabled = (val)



/* ------------------------------- S->portInfo ------------------------------*/

/* BEGIN long level 1 exclusion */
#if !SS_SFCN_LEVEL_1

#if SS_SL_INTERNAL || SS_GENERATED_S_FUNCTION
#define ssSetRegInputPortDimensionInfoFcn(S, fcn) \
    (S)->blkInfo.blkInfo2->mdlInfoSLSize->regInputPortDimsInfo = (fcn)

#define ssSetRegOutputPortDimensionInfoFcn(S, fcn) \
    (S)->blkInfo.blkInfo2->mdlInfoSLSize->regOutputPortDimsInfo = (fcn)
#define ssSetRegInputPortDimensionInfoFcnInt(S, fcn) (S)->mdlInfo->regInputPortDimsInfo = (fcn)

#define ssSetRegOutputPortDimensionInfoFcnInt(S, fcn) (S)->mdlInfo->regOutputPortDimsInfo = (fcn)
#endif



/************************************************************
 * Input Port Width/Number of Dimensions/Dimensions Methods *
 ************************************************************/
/* Number of Dimensions */

#ifdef _MSC_VER
#pragma warning(push)
// warning C4127: conditional expression is constant
#pragma warning(disable : 4127)
#endif

#if defined(USE_64BIT_FIELDS)
#if defined(SL_INTERNAL) || defined(IS_RSIM) || defined(IS_RAPID_ACCEL)
#define _ssSetInputPortNumDimensions(S, port, val)                                             \
    {                                                                                          \
        (S)->portInfo.inputs[(port)].numDims = (val);                                          \
        if (val == 1) {                                                                        \
            if ((S)->portInfo.inputs != NULL) {                                                \
                (S)->portInfo.inputs[(port)].dims = &((S)->portInfo.inputs[(port)].width);     \
            }                                                                                  \
            if (ssGetBlkInfo2Ptr(S) != NULL && (S)->blkInfo.blkInfo2->blkInfoSLSize != NULL) { \
                (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims =                    \
                    &((S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].width);             \
            }                                                                                  \
        }                                                                                      \
    }
#else
#define _ssSetInputPortNumDimensions(S, port, val)                             \
    {                                                                          \
        (S)->portInfo.inputs[(port)].numDims = (val);                          \
        if (val == 1) {                                                        \
            (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims =        \
                &((S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].width); \
        }                                                                      \
    }
#endif
#elif defined(USE_32BIT_FIELDS)
#define _ssSetInputPortNumDimensions(S, port, val)                                     \
    {                                                                                  \
        (S)->portInfo.inputs[(port)].numDims = (val);                                  \
        if (val == 1) {                                                                \
            (S)->portInfo.inputs[(port)].dims = &((S)->portInfo.inputs[(port)].width); \
        }                                                                              \
    }
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

/*
 *Input dimensions ptr
 */
/* AsInt and SLSize macros should only be used in code allocating and initializing 32-bit
   and 64-bit S-Functions. Currently, this includes simulink engine and sim targets */
/* varDims */
#define ssGetCurrentInputPortDimensionsAsInt(S, pIdx, dIdx) \
    (S)->blkInfo.blkInfo2->portInfo2->inputs[(pIdx)].portVarDims[(dIdx)]
#define ssGetInputPortDimensionsAsInt(S, port) ((S)->portInfo.inputs[(port)].dims)
#define ssGetInputPortDimensionsSLSize(S, port) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims

/* Do not make a copy. S-function port dimension = Ptr. */
#define _ssSetInputPortDimensionsPtr(S, port, ptr) \
    { (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims = (ptr); }
#define _ssSetInputPortDimensionsPtrAsInt(S, port, ptr) \
    { (S)->portInfo.inputs[(port)].dims = (ptr); }

/*
 * Copy 'd' to S-function port dimensions. It is assumed that
 * port has enough storage/memory to store the dimensions.
 */
#define _ssCopyInputPortDimensions(S, port, d)                                           \
    {                                                                                    \
        int nn = ssGetInputPortNumDimensions(S, port);                                   \
        if (nn >= 1) {                                                                   \
            (void)memcpy(((S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims), d, \
                         nn * sizeof(SLSize));                                           \
        }                                                                                \
    }
#define _ssCopyInputPortDimensionsAsInt(S, port, d)                                   \
    {                                                                                 \
        int nn = ssGetInputPortNumDimensions(S, port);                                \
        if (nn >= 1) {                                                                \
            (void)memcpy(((S)->portInfo.inputs[(port)].dims), d, nn * sizeof(int_T)); \
        }                                                                             \
    }

/* AsInt macros should only be used in code allocating and initializing 32-bit
   S-Functions. Currently, this includes simulink engine and sim targets */
#define ssSetInputPortWidthAsInt(S, port, val) ((S)->portInfo.inputs[(port)].width = (val))

/*
 * Set flag that specifies if an S-function can handle
 * Big Long signal
 * ssAllowSignalsHandleBigLong(S) is deprecated.
 * Please use ssFxpSetU32BitRegionCompliant defined in fixedpoint.h instead
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssAllowSignalsHandleBigLong(S)                                           \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_SIGS_ALLOW_BIG_LONG, 1, NULL) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssAllowSignalsHandleBigLong(S)
#endif

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetSupportDataTypeBeyond32BitsInRTW(S, val)                                           \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_SUPPORT_DATATYPE_BEYOND_32_BITS_IN_RTW, val, \
                                    NULL) _ssSafelyCallGenericFcnEnd
#else
#define ssSetSupportDataTypeBeyond32BitsInRTW(S, val)
#endif


/***************************
 * END of width/dimensions *
 ***************************/
#define ssGetInputPortSignalWhenNeeded(S, port) ((S)->portInfo.inputs[(port)].attributes.cinId)

#define ssGetOutputPortSignalWhenRefreshed(S, port) ((S)->portInfo.outputs[(port)].attributes.cecId)
#define ssSetOutputPortSignalWhenRefreshed(S, port, val) \
    (S)->portInfo.outputs[(port)].attributes.cecId = (val)

/* InputDimsConstraint - For each input port of your S-function block, this is the
 *   dataflow dims constraint. If unspecified, then the default type is
 * "SS_DIMS_CONSTRAINT_UNSPECIFIED" and the default size is 1.
 */
#define ssGetInputPortDimsConstraintType(S, port) \
    (S)->blkInfo.blkInfo2->portInfo2->inputDimsConstraint[(port)].type
#define ssGetInputPortDimsConstraintSize(S, port) \
    (S)->blkInfo.blkInfo2->portInfo2->inputDimsConstraint[(port)].size
#define ssSetInputPortDimsConstraint(S, port, t, sz)                          \
    (S)->blkInfo.blkInfo2->portInfo2->inputDimsConstraint[(port)].type = (t); \
    (S)->blkInfo.blkInfo2->portInfo2->inputDimsConstraint[(port)].size = (sz)

/* InputPortSignalPtrs - This is the pointers to the signal vector for each
 *    input port. This is the default method for accessing the S-Function's
 *    input signals. It is a *bad* error to use this macro if the S-Function
 *    specifies ssSetInputPortRequiredContiguous as true. In that case, use
 *    ssGetInputPortSignal().
 *
 *    The following code demonstrates the use of ssGetInputPortSignalPtrs() :
 *
 *       nInputPorts = ssGetNumInputPorts(S);
 *       for (i = 0; i < nInputPorts; i++) {
 *         InputPtrsType u  = ssGetInputPortSignalPtrs(S,i);
 *         int_T         nu = ssGetInputPortWidth(S,i);
 *         for (j = 0; j < nu; j++) {
 *           UseInputInSomeFunction(*u[i]);
 *         }
 *       }
 *
 *    If you know that the input's are always real_T's signals, then the
 *    ssGetInputPortSignalPtrs line in the above code snippet would be:
 *
 *         InputRealPtrsType u = ssGetInputPortRealSignalPtrs(S,i);
 *
 */

#define _ssSetInputPortSignalPtrs(S, ip, ptr) (S)->portInfo.inputs[(ip)].signal.ptrs = (ptr)
#if !SS_SFCN
#define ssSetInputPortSignalPtrs(S, ip, ptr) _ssSetInputPortSignalPtrs(S, ip, ptr)
#else
#define ssSetInputPortSignalPtrs(S, ip, ptr) ssSetInputPortSignalPtrs_cannot_be_used_in_SFunctions
#endif


/* InputPortSignal: This macro returns the address of the signal on the
 *    specified input port of the S-Function. In order to use this macro for
 *    accessing the input port signal you need to set the attribute
 *    ssSetInputPortRequiredContiguous to true. If not, this macro returns an
 *    invalid pointer.
 *
 *    The following code demonstrates the use of ssGetInputPortSignal() :
 *
 *       nInputPorts = ssGetNumInputPorts(S);
 *       for (i = 0; i < nInputPorts; i++) {
 *           int_T nu = ssGetInputPortWidth(S,i);
 *
 *           if ( ssGetInputPortRequiredContiguous(S,i) ) {
 *
 *               const void *u = ssGetInputPortSignal(S,i);
 *               UseInputVectorInSomeFunction(u, nu);
 *
 *           } else {
 *
 *               InputPtrsType u  = ssGetInputPortSignalPtrs(S,i);
 *               for (j = 0; j < nu; j++) {
 *                   UseInputInSomeFunction(*u[j]);
 *               }
 *           }
 *       }
 *
 *    If you know that the input's are always real_T's signals, then the
 *    ssGetInputPortSignal line in the above code snippet would be:
 *
 *         const real_T *u = ssGetInputPortRealSignal(S,i);
 *
 */

#define _ssSetInputPortSignal(S, ip, ptr) (S)->portInfo.inputs[(ip)].signal.vect = (ptr)
#if !SS_SFCN
#define ssSetInputPortSignal(S, ip, ptr) _ssSetInputPortSignal(S, ip, ptr)
#else
#define ssSetInputPortSignal(S, ip, ptr) ssSetInputPortSignal_cannot_be_used_in_SFunctions
#endif


/* InputPortConnected - Is the input connected to a non-virtual block (i.e.
 *   are there signals entering the S-function block)?
 */

#define _ssSetInputPortConnected(S, port, val) (S)->portInfo.inputs[(port)].connected = (val)
#if !SS_SFCN
#define ssSetInputPortConnected(S, port, val) _ssSetInputPortConnected(S, port, val)
#else
#define ssSetInputPortConnected(S, port, val) ssSetInputPortConnected_cannot_be_used_in_SFunctions
#endif



#if defined(RTW_GENERATED_S_FUNCTION) || SS_SL_INTERNAL
/* InputPortIsNotDerivPort - Specify that the input port signal is not
 * used in mdlDerivative function.  By default this will be false for all input
 * ports when the blocks has continuous states.  This setting is used
 * to determine what noncontinuous signals to track during simulation.
 */
#define ssGetInputPortIsNotDerivPort(S, port) \
    ((S)->portInfo.inputs[(port)].attributes.nonDerivPort == 1U)
#define ssSetInputPortIsNotDerivPort(S, port, val) \
    ((S)->portInfo.inputs[(port)].attributes.nonDerivPort = (val) ? 1U : 0U)
#endif


/*
 * This macro is obsolete, please use ssS(G)etInputPortOptimOpts
 *
 *  InputPortReusable - If this is set to false (which is the default value),
 *  then the memory allocated to the signals driving this input port are both
 *  globally visible and persistent. However, if this is set to true then this
 *  signal may be reused by other block outputs (and hence its value will not
 *  be persistent). For finer control use ssSetInputPortOptimOpts
 *
 */
#if SS_SFCN_NORMAL
#define ssGetInputPortReusable(S, port) \
    ((S)->portInfo.inputs[(port)].attributes.optimOpts != SS_NOT_REUSABLE_AND_GLOBAL)

#if SS_SFCN_FOR_SIM && !SS_NDEBUG
#ifdef __cplusplus
extern "C" {
#endif
extern void _ssSetInputPortReusableFcn(SimStruct* S, int port, int val);
#ifdef __cplusplus
}
#endif
#define ssSetInputPortReusable(S, port, val) _ssSetInputPortReusableFcn(S, port, val)
#else
#define ssSetInputPortReusable(S, port, val)             \
    ((S)->portInfo.inputs[(port)].attributes.optimOpts = \
         (val) ? SS_REUSABLE_AND_LOCAL : SS_NOT_REUSABLE_AND_GLOBAL)
#endif

#endif


/* InputPortOptimizeInIR - This macro allows S-Functions that use the code
 * generation intermediate representation (CGIR) to generate code, to enable
 * optimizations on for the input port that would otherwise be disabled by
 * default. For example, the macro should be used if a S-Function set its
 * input port conservatively as global, because it is accessed in both the
 * output and the update function. It is possible for CGIR to safely optimize
 * the port signal if output and update get combined.
 */
#define ssGetInputPortOptimizeInIR(S, port) ((S)->portInfo.inputs[(port)].attributes.optimizeInIR)
#define ssSetInputPortOptimizeInIR(S, port, val) \
    ((S)->portInfo.inputs[(port)].attributes.optimizeInIR = (val))


/* InputPortBufferDstPort - If an input port and some output port on an
 *   S-Function are *not* test points, and in addition,  if this input port is
 *   over-writable, then one of the "untest-pointed" output ports of this
 *   S-Function might reuse the same buffer as the input port! If this happens,
 *   then after compilation, the following macro returns the index of the
 *   output port that reuses the specified input port's buffer. If none of the
 *   S-Function's output ports reuse this input port buffer, then this macro
 *   returns INVALID_PORT_IDX ( = -1).
 */

#define _ssSetInputPortBufferDstPort(S, port, val) \
    (S)->portInfo.inputs[(port)].bufferDstPort = (val)
#if !SS_SFCN
#define ssSetInputPortBufferDstPort(S, port, val) _ssSetInputPortBufferDstPort(S, port, val)
#else
#define ssSetInputPortBufferDstPort(S, port, val) \
    ssSetInputPortBufferDstPort_cannot_be_used_in_SFunctions
#endif


#define _ssSetInputPortSampleTimeIndex(S, port, idx) \
    (S)->portInfo.inputs[(port)].sampleTimeIndex = (idx) /* (int_T)   */
#if !SS_SFCN
#define ssSetInputPortSampleTimeIndex(S, port, idx) _ssSetInputPortSampleTimeIndex(S, port, idx)
#else
#define ssSetInputPortSampleTimeIndex(S, port, idx) \
    ssSetInputPortSampleTimeIndex_cannot_be_used_in_SFunctions
#endif



#if SS_SFCN && SS_SIM
/* ssSetInputPortAccessedByAddress - This macro should be invoked
 * in the mdlInitializeSizes function if the s-function block requires that,
 * in the generated code, the signal coming into the specified port is
 * always addressable.
 */
#define ssSetInputPortAccessedByAddress(S, portIdx)                                      \
    {                                                                                    \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_INPUT_PORT_ACCESSED_BY_ADDRESS, \
                                        (portIdx), NULL) _ssSafelyCallGenericFcnEnd;     \
    }
#endif



/***********************************
 * Output Port Number of Dimensions *
 ***********************************/

#ifdef _MSC_VER
#pragma warning(push)
// warning C4127: conditional expression is constant
#pragma warning(disable : 4127)
#endif

#if defined(USE_64BIT_FIELDS)
#if defined(SL_INTERNAL) || defined(IS_RSIM) || defined(IS_RAPID_ACCEL)
#define _ssSetOutputPortNumDimensions(S, port, val)                                            \
    {                                                                                          \
        (S)->portInfo.outputs[(port)].numDims = (val);                                         \
        if (val == 1) {                                                                        \
            if ((S)->portInfo.outputs != NULL) {                                               \
                (S)->portInfo.outputs[(port)].dims = &((S)->portInfo.outputs[(port)].width);   \
            }                                                                                  \
            if (ssGetBlkInfo2Ptr(S) != NULL && (S)->blkInfo.blkInfo2->blkInfoSLSize != NULL) { \
                (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims =                   \
                    &((S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].width);            \
            }                                                                                  \
        }                                                                                      \
    }
#else
#define _ssSetOutputPortNumDimensions(S, port, val)                             \
    {                                                                           \
        (S)->portInfo.outputs[(port)].numDims = (val);                          \
        if (val == 1) {                                                         \
            (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims =        \
                &((S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].width); \
        }                                                                       \
    }
#endif
#elif defined(USE_32BIT_FIELDS)
#define _ssSetOutputPortNumDimensions(S, port, val)                                      \
    {                                                                                    \
        (S)->portInfo.outputs[(port)].numDims = (val);                                   \
        if (val == 1) {                                                                  \
            (S)->portInfo.outputs[(port)].dims = &((S)->portInfo.outputs[(port)].width); \
        }                                                                                \
    }
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

/*************************
 * Output Port Dimensions *
 *************************/
/* AsInt and SLSize macros should only be used in code allocating and initializing 32-bit
   and 64-bit S-Functions. Currently, this includes simulink engine and sim targets */
/* varDims */
#define ssGetCurrentOutputPortDimensionsAsInt(S, pIdx, dIdx) \
    (S)->blkInfo.blkInfo2->portInfo2->outputs[(pIdx)].portVarDims[(dIdx)]
#define _ssSetCurrentOutputPortDimensionsAsInt(S, pIdx, dIdx, val) \
    (S)->blkInfo.blkInfo2->portInfo2->outputs[(pIdx)].portVarDims[(dIdx)] = (val)
#define ssSetCurrentOutputPortDimensionsAsInt(S, pIdx, _dIdx, _val)                        \
    {                                                                                      \
        struct _ssVarDimsIdxVal_tag dIdxVal;                                               \
        dIdxVal.dIdx = _dIdx;                                                              \
        dIdxVal.dVal = _val;                                                               \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_CURR_OUTPUT_DIMS, pIdx, &dIdxVal) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
#define ssGetOutputPortDimensionsAsInt(S, port) ((S)->portInfo.outputs[(port)].dims)
#define ssGetOutputPortDimensionsSLSize(S, port) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims

/* Do not make a copy. S-function port dimension = Ptr. */
#define _ssSetOutputPortDimensionsPtr(S, port, ptr) \
    { (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims = (ptr); }
#define _ssSetOutputPortDimensionsPtrAsInt(S, port, ptr) \
    { (S)->portInfo.outputs[(port)].dims = (ptr); }

/*
 * Copy 'd' to S-function port dimensions. It is assumed that
 * port has enough storage/memory to store the dimensions.
 */
#define _ssCopyOutputPortDimensions(S, port, d)                                           \
    {                                                                                     \
        int nn = ssGetOutputPortNumDimensions(S, port);                                   \
        if (nn >= 1) {                                                                    \
            (void)memcpy(((S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims), d, \
                         nn * sizeof(SLSize));                                            \
        }                                                                                 \
    }
#define _ssCopyOutputPortDimensionsAsInt(S, port, d)                                   \
    {                                                                                  \
        int nn = ssGetOutputPortNumDimensions(S, port);                                \
        if (nn >= 1) {                                                                 \
            (void)memcpy(((S)->portInfo.outputs[(port)].dims), d, nn * sizeof(int_T)); \
        }                                                                              \
    }

/* AsInt macros should only be used in code allocating and initializing 32-bit
   S-Functions. Currently, this includes simulink engine and sim targets */
#define ssGetOutputPortWidthAsInt(S, port) (S)->portInfo.outputs[(port)].width
#define ssSetOutputPortWidthAsInt(S, port, val) ((S)->portInfo.outputs[(port)].width = (val))

/*
 * This macro is obsolete, please use ssS(G)etOutputPortOptimOpts
 *
 * OutputPortReusable - If this is set to false (which is the default value),
 *  then the memory allocated to this output port is both globally visible,
 *  and persistent. However, if you set this to true in the mdlInitializeSizes
 *  function then the memory allocated for this signal may be reused by other
 *  block outputs (hence its value will not be persistent).
 *  For finer control use ssSetOutputPortOptimOpts
 */
#if SS_SFCN_NORMAL
#define ssGetOutputPortReusable(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.optimOpts != SS_NOT_REUSABLE_AND_GLOBAL)

#if SS_SFCN_FOR_SIM && !SS_NDEBUG
#ifdef __cplusplus
extern "C" {
#endif
extern void _ssSetOutputPortReusableFcn(SimStruct* S, int port, int val);
#ifdef __cplusplus
}
#endif
#define ssSetOutputPortReusable(S, port, val) _ssSetOutputPortReusableFcn(S, port, val)
#else
#define ssSetOutputPortReusable(S, port, val)             \
    ((S)->portInfo.outputs[(port)].attributes.optimOpts = \
         (val) ? SS_REUSABLE_AND_LOCAL : SS_NOT_REUSABLE_AND_GLOBAL)
#endif

#endif

/* OutputPortOptimizeInIR - This macro allows S-Functions that use the code
 * generation intermediate representation (CGIR) to generate code, to enable
 * optimizations on for the output port that would otherwise be disabled by
 * default. For example, the macro should be used if a S-Function set its
 * output port conservatively as global, because it is accessed in both the
 * output and the update function. It is possible for CGIR to safely optimize
 * the port signal if output and update get combined.
 */
#define ssGetOutputPortOptimizeInIR(S, port) ((S)->portInfo.outputs[(port)].attributes.optimizeInIR)
#define ssSetOutputPortOptimizeInIR(S, port, val) \
    ((S)->portInfo.outputs[(port)].attributes.optimizeInIR = (val))


/* OutputPortBeingMerged - If this output port signal of the S-Function is
 * being merged with other signals (this happens if the S-Function block
 * output port is directly or via connection type blocks is connected to a
 * Merge block), then the macro below will return "true". This macro will
 * return the correct answer in and after the S-Function's mdlSetWorkWidths()
 * method.
 */

#define _ssSetOutputPortBeingMerged(S, port, val) \
    (S)->portInfo.outputs[(port)].attributes.cToMergeBlk = (val) ? 1U : 0U
#if !SS_SFCN
#define ssSetOutputPortBeingMerged(S, port, val) _ssSetOutputPortBeingMerged(S, port, val)
#else
#define ssSetOutputPortBeingMerged(S, port, val) \
    ssSetOutputPortBeingMerged_cannot_be_used_in_SFunctions
#endif

/* OutputPortConstOutputExprInRTW - Specify that the output signal is a constant
 * expression in RTW (versus a statement).  This allows a downstream block
 * to fold the expression into its calculation no matter how many destinations
 * the block has.  Note that Simulink may not honor this setting, in which case
 * the block must produce a statement.
 */
#define ssGetOutputPortConstOutputExprInRTW(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.constOutputExprInRTW == 1U)
#define ssSetOutputPortConstOutputExprInRTW(S, port, val)                            \
    ((S)->portInfo.outputs[(port)].attributes.constOutputExprInRTW =                 \
         (val) ? ((S)->portInfo.outputs[(port)].attributes.trivialOutputExprInRTW =  \
                      (S)->portInfo.outputs[(port)].attributes.outputExprInRTW = 1U) \
               : 0U)


/* OutputPortTrivialOutputExprInRTW - Specify that the output signal is a trivial
 * expression in RTW (versus a statement).  This allows a downstream block
 * to fold the expression into its calculation no matter how many destinations
 * the block has.  Note that Simulink may not honor this setting, in which case
 * the block must produce a statement.
 */
#define ssGetOutputPortTrivialOutputExprInRTW(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.trivialOutputExprInRTW == 1U)
#define ssSetOutputPortTrivialOutputExprInRTW(S, port, val)                      \
    ((S)->portInfo.outputs[(port)].attributes.trivialOutputExprInRTW =           \
         (val) ? ((S)->portInfo.outputs[(port)].attributes.outputExprInRTW = 1U) \
               : ((S)->portInfo.outputs[(port)].attributes.constOutputExprInRTW = 0U))



#if defined(RTW_GENERATED_S_FUNCTION) || SS_SL_INTERNAL
/* OutputPortIsNonContinuous - Specify that the output port signal is
 * noncontinuous (i.e. has a discontinuity even if the sample time is
 * continuous).  This setting is used to determine what noncontinuous
 * signals to track during simulation.  It is false by default.
 */
#define ssGetOutputPortIsNonContinuous(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.nonContPort)
#define ssSetOutputPortIsNonContinuous(S, port, val) \
    ((S)->portInfo.outputs[(port)].attributes.nonContPort = (val) ? 1U : 0U)

/*
 * Specify that the output port is being driven by a block
 * with modes but no zero-crossings.  We need this for model
 * reference to determine if DerivCacheNeedsReset is true.
 */
#define ssGetOutputPortIsFedByBlockWithModesNoZCs(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.fedByBlockWithModesNoZCs)
#define ssSetOutputPortIsFedByBlockWithModesNoZCs(S, port, val) \
    ((S)->portInfo.outputs[(port)].attributes.fedByBlockWithModesNoZCs = (val) ? 1U : 0U)
#endif



typedef enum {
    SS_DATA_DESC_OUTPUT,
    SS_DATA_DESC_INPUT,
    SS_DATA_DESC_RTP,
    SS_DATA_DESC_DWORK
} SSDataDescType;

#define ssRegisterDataMinMaxPrmIndices(S, dataDescType, dataIdx, prmMinIdx, prmMaxIdx)             \
    {                                                                                              \
        int _moreArgs[3] = {(int)(dataDescType), (prmMinIdx), (prmMaxIdx)};                        \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REGISTER_DATA_MIN_MAX_PRM_INDICES, (dataIdx), \
                                        _moreArgs) _ssSafelyCallGenericFcnEnd;                     \
    }

/*
 * Register dialog parameters indexed as prmMinIdx and prmMaxIdx as design
 * minimum and maximum for the output port of index portIdx.
 */
#define ssRegisterOutputPortMinMaxPrmIndices(S, portIdx, prmMinIdx, prmMaxIdx) \
    ssRegisterDataMinMaxPrmIndices((S), SS_DATA_DESC_OUTPUT, (portIdx), (prmMinIdx), (prmMaxIdx))


/*
 * Set the output port min/max values.  This is used by Stateflow and other S-Functions
 * in which min/max values are not Parameters with indices.  In case of Stateflow,
 * the min/max values are data properties.
 * This API and ssRegisterOutputPortMinMaxPrmIndices() are mutually exclusive!
 */
typedef struct outputPortMinMaxStruct_t {
    int dataDescType;
    double designMin;
    double designMax;
} outputPortMinMaxStruct;

#define ssSetOutputPortMinMaxValues(S, portIdx, minValue, maxValue)                          \
    {                                                                                        \
        outputPortMinMaxStruct _moreArgs = {(int)(SS_DATA_DESC_OUTPUT), minValue, maxValue}; \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_DATA_MIN_MAX_VALUES, (portIdx),     \
                                        (void*)&_moreArgs) _ssSafelyCallGenericFcnEnd;       \
    }

/* OutputDimsConstraint - For each output port of your S-function block, this is the
 *   dataflow dims constraint. If unspecified, then the default type is
 * "SS_DIMS_CONSTRAINT_UNSPECIFIED" and the default size is 1.
 */
#define ssGetOutputPortDimsConstraintType(S, port) \
    (S)->blkInfo.blkInfo2->portInfo2->outputDimsConstraint[(port)].type
#define ssGetOutputPortDimsConstraintSize(S, port) \
    (S)->blkInfo.blkInfo2->portInfo2->outputDimsConstraint[(port)].size
#define ssSetOutputPortDimsConstraint(S, port, t, sz)                          \
    (S)->blkInfo.blkInfo2->portInfo2->outputDimsConstraint[(port)].type = (t); \
    (S)->blkInfo.blkInfo2->portInfo2->outputDimsConstraint[(port)].size = (sz)

/* OutputPortSignal - This is the pointers to the signal vector for each
 *   output port.  For example to write to all outputs with int16_T data
 *   type:
 *       nOutputPorts = ssGetNumOutputPorts(S);
 *       for (i = 0; i < nOutputPorts; i++) {
 *         int16_T  *y = (int16_T *)ssGetOutputPortSignal(S,i);
 *         int_T ny    = ssGetOutputPortWidth(S,i);
 *         for (j = 0; j < ny; j++) {
 *           SomeFunctionToFillInOutput(y[j]);
 *         }
 *       }
 *   If you know that the output is always a real_T, then the
 *   ssGetOutputPortSignal line would be:
 *       real_T *y  = ssGetOutputPortRealSignal(S,i);
 */

#define _ssSetOutputPortSignal(S, port, vect) (S)->portInfo.outputs[(port)].signalVect = (vect)
#if !SS_SFCN
#define ssSetOutputPortSignal(S, port, vect) _ssSetOutputPortSignal(S, port, vect)
#else
#define ssSetOutputPortSignal(S, port, vect) ssSetOutputPortSignal_cannot_be_used_in_SFunctions
#endif

/* OutputPortConnected - Is the output connected to a non-virtual block (i.e.
 *   are the signals leaving the S-function block driving other blocks)?
 */

#define _ssSetOutputPortConnected(S, port, val) (S)->portInfo.outputs[(port)].connected = (val)
#if !SS_SFCN
#define ssSetOutputPortConnected(S, port, val) _ssSetOutputPortConnected(S, port, val)
#else
#define ssSetOutputPortConnected(S, port, val) ssSetOutputPortConnected_cannot_be_used_in_SFunctions
#endif

/* OutputPortSampleTime/OutputPortOffsetTime - The sample and offset time of
 *   the output port. This should only be used when PORT_BASED_SAMPLE_TIMES
 *   have been specified for ssSetNumSampleTimes in mdlInitializeSizes.
 * OutputPortSampleTimeIndex - index of the sample time for the port to
 *   be used in mdlOutputs, mdlUpdate when checking for sample hits.
 */



#define _ssSetOutputPortSampleTimeIndex(S, port, idx) \
    (S)->portInfo.outputs[(port)].sampleTimeIndex = (idx) /* (int_T)   */
#if !SS_SFCN
#define ssSetOutputPortSampleTimeIndex(S, port, idx) _ssSetOutputPortSampleTimeIndex(S, port, idx)
#else
#define ssSetOutputPortSampleTimeIndex(S, port, idx) \
    ssSetOutputPortSampleTimeIndex_cannot_be_used_in_SFunctions
#endif

/*
 * Routines to allow the S-function to map a block IC parameter to
 * its output port.
 */
#define ssGetOutputPortInitialOutputParamIdx(S, port) \
    ((S)->portInfo.outputs[(port)].icPrmIdxPlus1 - 1)
#define ssSetOutputPortInitialOutputParamIdx(S, port, val) \
    (S)->portInfo.outputs[(port)].icPrmIdxPlus1 = ((int_T)val + 1)

/*
 * Routines to setup the fcn and arg which allow the S-function to register
 * the input/output port properties.
 */
#define ssSetRegNumInputPortsFcn(S, fcn) (S)->portInfo.regNumInputPortsFcn = fcn
#define ssSetRegNumInputPortsFcnArg(S, arg) (S)->portInfo.regNumInputPortsFcnArg = arg
#define ssSetRegNumOutputPortsFcn(S, fcn) (S)->portInfo.regNumOutputPortsFcn = fcn
#define ssSetRegNumOutputPortsFcnArg(S, arg) (S)->portInfo.regNumOutputPortsFcnArg = arg
#endif
/* END long level 1 exclusion */



#define ssGetRTModel(S) (S)->sizes.rtModel
#define ssSetRTModel(S, rtm) (S)->sizes.rtModel = ((void*)(rtm))

/*-------------------------------- S->sfcnParams ---------------------------*/

/* Macros for manipulating dialog parameters */


#define _ssSetSFcnParamsCount(S, n) (S)->sfcnParams.dlgNum = (n)
#if !SS_SFCN
#define ssSetSFcnParamsCount(S, n) _ssSetSFcnParamsCount(S, n)
#else
#define ssSetSFcnParamsCount(S, n) ssSetSFcnParamsCount_cannot_be_used_in_SFunctions
#endif


/* SFcnParams - This is a list of MyArray pointers corresponding to the
 *   S-function parameters supplied to your S-function. This is not
 *   used by the root SimStruct.
 */
#define _ssGetSFcnParamsPtr(S) (S)->sfcnParams.dlgParams /*   (mxArray **)  */
/* GCC 4.X issues warning when using conventional C-style cast in C++ code */
#ifdef __cplusplus
#define ssGetSFcnParamsPtr(S) \
    (const_cast<const mxArray* const*>(_ssGetSFcnParamsPtr(S))) /* (const mxArray *const *) */
#else
#define ssGetSFcnParamsPtr(S) \
    ((const mxArray* const*)_ssGetSFcnParamsPtr(S)) /* (const mxArray *const *) */
#endif
#define _ssSetSFcnParamsPtr(S, ptr) (S)->sfcnParams.dlgParams = (ptr)
#if !SS_SFCN
#define ssSetSFcnParamsPtr(S, ptr) _ssSetSFcnParamsPtr(S, ptr)
#else
#define ssSetSFcnParamsPtr(S, ptr) ssSetSFcnParamsPtr_cannot_be_used_in_SFunctions
#endif

/* Use ssGetSFcnParam(S,index) to access S-function parameters from within
 * S-functions. The index starts at 0, which corresponds to the (index+1)'th
 * parameter.
 */


#define _ssSetSFcnParam(S, index, mat) (S)->sfcnParams.dlgParams[index] = (mat)
#if !SS_SFCN
#define ssSetSFcnParam(S, index, mat) _ssSetSFcnParam(S, index, mat)
#else
#define ssSetSFcnParam(S, index, mat) ssSetSFcnParam_cannot_be_used_in_SFunctions
#endif



#define ssGetSFcnParamTunable(S, index) ((S)->sfcnParams.dlgAttribs[index] & SFCNPARAM_TUNABLE)

#define ssGetSFcnParamSimOnlyTunable(S, index) \
    ((S)->sfcnParams.dlgAttribs[index] & SFCNPARAM_SIMONLY_TUNABLE)

#if SS_SL_INTERNAL || (SS_SIM && SS_GENERATED_S_FUNCTION)
#define ssGetSFcnParamsNotTunable(S, index) \
    ((S)->sfcnParams.dlgAttribs[index] & SFCNPARAM_NOT_TUNABLE)

#define ssGetSFcnParamAttribsPtr(S) (S)->sfcnParams.dlgAttribs
#define ssSetSFcnParamAttribsPtr(S, ptr) (S)->sfcnParams.dlgAttribs = (ptr)
#endif


/* Macros for checking values entered for S-Function parameters */
#define _ssCacheSFcnParamValueAttribs(pName, dtId, nDims, dimsPtr, cplx) \
    ssParamRec locPI;                                                    \
    locPI.name = pName;                                                  \
    locPI.nDimensions = nDims;                                           \
    locPI.dimensions = dimsPtr;                                          \
    locPI.complexSignal = cplx;                                          \
    locPI.dataTypeId = dtId;                                             \
    locPI.data = NULL;                                                   \
    locPI.dataAttributes = NULL;                                         \
    locPI.nDlgParamIndices = 0;                                          \
    locPI.dlgParamIndices = NULL;                                        \
    locPI.transformed = RTPARAM_NOT_TRANSFORMED;                         \
    locPI.outputAsMatrix = false;

#define ssCheckSFcnParamValueAttribs(S, pIdx, pName, dtId, nDims, dimsPtr, cplx)                  \
    {                                                                                             \
        _ssCacheSFcnParamValueAttribs(                                                            \
            pName, dtId, nDims, dimsPtr,                                                          \
            cplx) if (!_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_CHECK_SFCN_PARAM_VALUE_ATTRIBS, \
                                                       pIdx, &locPI)                              \
                          _ssSafelyCallGenericFcnEnd) return;                                     \
    }


/* ======================================================================
 *  Macros for manipulating run-time parameters.
 * ======================================================================
 * The most commonly used macros are:
 * - ssSetNumRunTimeParams
 *   ==> To set the number of run-time parameters (before registering run-time parameters)
 *
 * - ssRegAllTunableParamsAsRunTimeParams
 *   ==> To register all tunable SFcnParams as run-time parameters (in mdlSetWorkWidths)
 * - ssRegDlgParamAsRunTimeParam
 *   ==> To register specific SFcnParam as a run-time parameter (in mdlSetWorkWidths)
 *       This macro will perform data type conversion if necessary
 *
 * - ssUpdateAllTunableParamsAsRunTimeParams
 * - ssUpdateDlgParamAsRunTimeParam
 *   ==> To update values of run-time parameters during simulation (in mdlProcessParameters)
 */



#if SS_SFCN
#if !SS_RTW
#define ssSetConstRunTimeParamInfo(S, idx, p)                                           \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REG_CONST_RUN_TIME_PARAM, idx, (void*)p) \
        _ssSafelyCallGenericFcnEnd
#endif
#endif

#if SS_SFCN && SS_SIM
#define ssSetStateflowIsInlinable(S, p) \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SF_INLINABLE, p, NULL) _ssSafelyCallGenericFcnEnd
#endif

#if SS_SFCN && SS_SIM
#define ssSetOutputFcnCalledMultiple(S, p)                                              \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_OUTPUT_FCN_CALLED_MULTIPLE, p, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif

#if SS_SFCN && SS_SIM
#define ssSetNotMultipleInlinable(S, p)                                              \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_NOT_MULTIPLE_INLINEABLE, p, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif

typedef struct _ssRTPFromDataInfoWithConv_tag {
    void* data;
    int nDataDims;            /* data dimension number       */
    int* dataDims;            /* data dimensions             */
    DTypeId dataTypeId;       /* CANNOT be DYNAMICALLY_TYPED */
    CSignal_T dataComplexity; /* CANNOT be COMPLEX_INHERITED */
    boolean_T dataIsConst;    /* constant run-time prm?      */
    int numParams;            /* number dlg prms, could be 0 */
    int* paramIndices;        /* dlg prms, could be NULL     */
    int rtpIndex;             /* run-time prm index          */
    const char* rtpName;      /* run-time prm name           */
    DTypeId rtpDataTypeId;    /* user-specified rtp datatype */
    CSignal_T rtpComplexity;  /* user-specified rtp complex  */
} ssRTPFromDataInfoWithConv;

typedef struct _ssRTPDataInfo_tag {
    void* data;               /* data pointer                */
    DTypeId dataTypeId;       /* CANNOT be DYNAMICALLY_TYPED */
    CSignal_T dataComplexity; /* CANNOT be COMPLEX_INHERITED */
} ssRTPDataInfo;


typedef struct _ssRTPRegInfoWithTypeComp_tag {
    int dlgIdx;
    int rtIdx;
    const char* name;
    int dtId;
    CSignal_T complexity;
} ssRTPRegInfoWithTypeComp;



typedef struct _ssTimerInfo_tag {
    double clockTickStepSize;
    int_T clockTickDtype;
    slTimeSource timeSource;
} ssTimerInfo;

#if SS_SFCN && SS_SIM

#define ssRegDlgParamAsRunTimeParamFull(S, dlgIdxArg, rtIdxArg, nameArg, dtIdArg, compArg) \
    {                                                                                      \
        ssRTPRegInfoWithTypeComp _slConvTypeAndRegParamInfo;                               \
        _slConvTypeAndRegParamInfo.dlgIdx = (dlgIdxArg);                                   \
        _slConvTypeAndRegParamInfo.rtIdx = (rtIdxArg);                                     \
        _slConvTypeAndRegParamInfo.name = (nameArg);                                       \
        _slConvTypeAndRegParamInfo.dtId = (dtIdArg);                                       \
        _slConvTypeAndRegParamInfo.complexity = (compArg);                                 \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_FULL_REG_AND_CNV_RUN_TIME_PARAM, 0,     \
                                        (void*)&_slConvTypeAndRegParamInfo)                \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }



/*
 * Register dialog parameters indexed as rtpMinIdx and rtpMaxIdx as design
 * minimum and maximum for the run-time parameter of index rtpIdx.
 */
#define ssRegisterRunTimeParamMinMaxPrmIndices(S, rtpIdx, rtpMinIdx, rtpMaxIdx) \
    ssRegisterDataMinMaxPrmIndices((S), SS_DATA_DESC_RTP, (rtpIdx), (rtpMinIdx), (rtpMaxIdx))



#define ssCreateRunTimeParamFromData(S, _data, _nDataDims, _dataDims, _dataTypeId,             \
                                     _dataComplexity, _dataIsConst, _numParams, _paramIndices, \
                                     _RTPIndex, _RTPName, _RTPDataTypeId, _RTPComplexity)      \
    {                                                                                          \
        ssRTPFromDataInfoWithConv _slConvInfoRTPFromData;                                      \
        _slConvInfoRTPFromData.data = (_data);                                                 \
        _slConvInfoRTPFromData.nDataDims = (_nDataDims);                                       \
        _slConvInfoRTPFromData.dataDims = (_dataDims);                                         \
        _slConvInfoRTPFromData.dataTypeId = (_dataTypeId);                                     \
        _slConvInfoRTPFromData.dataComplexity = (_dataComplexity);                             \
        _slConvInfoRTPFromData.dataIsConst = (_dataIsConst);                                   \
        _slConvInfoRTPFromData.numParams = (_numParams);                                       \
        _slConvInfoRTPFromData.paramIndices = (_paramIndices);                                 \
        _slConvInfoRTPFromData.rtpIndex = (_RTPIndex);                                         \
        _slConvInfoRTPFromData.rtpName = (_RTPName);                                           \
        _slConvInfoRTPFromData.rtpDataTypeId = (_RTPDataTypeId);                               \
        _slConvInfoRTPFromData.rtpComplexity = (_RTPComplexity);                               \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_CREATE_RUN_TIME_PARAM_FROM_DATA, 0,         \
                                        (void*)&_slConvInfoRTPFromData)                        \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }

#define ssUpdateRunTimeParamFromData(S, _rtIdxArg, _data, _dataTypeId, _dataComplexity)          \
    {                                                                                            \
        ssRTPDataInfo _slRTPDataInfo;                                                            \
        _slRTPDataInfo.data = (_data);                                                           \
        _slRTPDataInfo.dataTypeId = (_dataTypeId);                                               \
        _slRTPDataInfo.dataComplexity = (_dataComplexity);                                       \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_UPDATE_RUN_TIME_PARAM_FROM_DATA, (_rtIdxArg), \
                                        (void*)&_slRTPDataInfo) _ssSafelyCallGenericFcnEnd;      \
    }



/*
 * Internal use only.
 *
 * Indicate that the given run-time parameter needs to be accessed in
 * the generated code by address. Unaddressable expression
 * will be collapsed. This macro can only be used for run-time parameters that
 * has an one-on-one mapping with a dialog parameter.
 * This macro should only be called at the beginning of mdlStart.
 */
#define ssSetRunTimeParamAccessedByAddress(S, rtpIdx)                                              \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_RUN_TIME_PARAM_ACCESSED_BY_ADDRESS, (rtpIdx), \
                                    NULL) _ssSafelyCallGenericFcnEnd

/* Result is an int * */
#define _ssIsRunTimeParamTunable(S, rtPIdx, result)                                      \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_IS_RTPARAM_TUNABLE, (rtPIdx), (result)) \
        _ssSafelyCallGenericFcnEnd

/* Result is a double * */
#define _ssGetSFuncBlockHandle(S, result)                                       \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_BLOCK_HANDLE, 0, (result)) \
        _ssSafelyCallGenericFcnEnd

#define ssSetSFInitOutput(S, val)                                                 \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_SF_INIT_OUTPUT, (val), NULL) \
        _ssSafelyCallGenericFcnEnd

#endif

#if SS_SIM
#define ssSetRequiredStackSize(S, val)                                                 \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_REQUIRED_STACK_SIZE, (val), NULL) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssSetRequiredStackSize(S, val) ssSetRequiredStackSize_cannot_be_used_in_RTW
#endif

#if SS_SL_INTERNAL || SS_RTW_INTERNAL
#define ssGetRunTimeParamsPtr(S) (S)->sfcnParams.rtp
#define ssSetRunTimeParamsPtr(S, ptr) (S)->sfcnParams.rtp = (ptr)
#endif


#if SS_SIM
#define ssComputeOutput(S, pIdx)                                           \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_COMPUTE_OUTPUT, pIdx, NULL) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssComputeOutput(S, pIdx) ssComputeOutput_cannot_be_used_in_RTW
#endif

/* Result is a pointer to boolean_T */
#if SS_SIM
#define ssGetDestFCSSEnabled(S, pIdx, result)                                   \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_DEST_FCSS_ENABLED, pIdx, result) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssGetDestFCSSEnabled(S, dataPtr) ssGetDestFCSSEnabled_cannot_be_used_in_RTW
#endif

#if SS_SFCN
#define ssSetAsyncTimerAttributes(S, _clockTickStepSize)                                  \
    {                                                                                     \
        ssTimerInfo _slTimerInfo;                                                         \
        _slTimerInfo.clockTickStepSize = (_clockTickStepSize);                            \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ASYNC_TIMER_ATTRIBUTES, 0,         \
                                        (void*)&_slTimerInfo) _ssSafelyCallGenericFcnEnd; \
    }
#define ssSetAsyncTimerResolutionEl(S, _clockTickStepSize, el)                            \
    {                                                                                     \
        ssTimerInfo _slTimerInfo;                                                         \
        _slTimerInfo.clockTickStepSize = (_clockTickStepSize);                            \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ASYNC_TIMER_RESOLUTION_EL, el,     \
                                        (void*)&_slTimerInfo) _ssSafelyCallGenericFcnEnd; \
    }


#define ssSetAsyncTimerDataType(S, _clockTickDataType)                                    \
    {                                                                                     \
        ssTimerInfo _slTimerInfo;                                                         \
        _slTimerInfo.clockTickDtype = (_clockTickDataType);                               \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ASYNC_TIMER_DATA_TYPE, 0,          \
                                        (void*)&_slTimerInfo) _ssSafelyCallGenericFcnEnd; \
    }
#define ssSetAsyncTimerDataTypeEl(S, _clockTickDataType, el)                              \
    {                                                                                     \
        ssTimerInfo _slTimerInfo;                                                         \
        _slTimerInfo.clockTickDtype = (_clockTickDataType);                               \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ASYNC_TIMER_DATA_TYPE_EL, el,      \
                                        (void*)&_slTimerInfo) _ssSafelyCallGenericFcnEnd; \
    }


#define ssSetTimeSourceEl(S, _timeSource, el)                                                    \
    {                                                                                            \
        ssTimerInfo _slTimerInfo;                                                                \
        _slTimerInfo.timeSource = (_timeSource);                                                 \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_TIME_SOURCE_EL, el, (void*)&_slTimerInfo) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }
#endif

#if SS_SFCN && SS_SIM
#define ssGetTimeResolution(S, sti, dataPtr)                                               \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_TIME_RESOLUTION, sti, (double*)dataPtr) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssGetTimeResolution(S, sti, dataPtr) ssGetTimeResolution_cannot_be_used_in_RTW
#endif

#if SS_SFCN
#define ssSetAsyncTaskPriorities(S, width, str)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ASYNC_TASK_PRIORITIES, width, str) \
        _ssSafelyCallGenericFcnEnd
#define ssSetAsyncTaskPrioritiesEl(S, _priority, el)                                    \
    {                                                                                   \
        int priority = _priority;                                                       \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ASYNC_TASK_PRIORITIES_EL, el,    \
                                        (void*)&(priority)) _ssSafelyCallGenericFcnEnd; \
    }
#endif

#if SS_SIM
#define ssSetEnableFcnIsTrivial(S, trivial)                                              \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ENABLE_FCN_IS_TRIVIAL, (trivial), NULL) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssSetEnableFcnIsTrivial(S, trivial) ssSetEnableFcnIsTrivial_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDisableFcnIsTrivial(S, trivial)                                              \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_DISABLE_FCN_IS_TRIVIAL, (trivial), NULL) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssSetDisableFcnIsTrivial(S, trivial) ssSetDisableFcnIsTrivial_cannot_be_used_in_RTW
#endif



/*
 * Set/Get flag that specifies that an S-function's
 * mdlUpdate is empty
 */
#if (SS_SL_INTERNAL || SS_SFCN_FOR_SIM) && defined(ssGetOwnerBlock)
#define ssMdlUpdateIsEmpty(S, value)                                                   \
    {                                                                                  \
        if (ssGetOwnerBlock(S) != NULL) {                                              \
            boolean_T val = value;                                                     \
            _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_MDL_UPDATE_IS_EMPTY, 0, &val) \
                _ssSafelyCallGenericFcnEnd;                                            \
        }                                                                              \
    }
#else
#define ssMdlUpdateIsEmpty(S, value)
#endif

/*
 * Register a custom message for not supporting multiple instances.
 * Input msg is a pointer to a char array string.
 */
#if (SS_SL_INTERNAL || SS_SFCN_FOR_SIM)
#define ssRegisterMsgForNotSupportingMultiExecInst(S, msg)                                        \
    {                                                                                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_MULTI_INS_NO_SUPPORT_MESSAGE, 0, (void*)msg) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }
#else
#define ssRegisterMsgForNotSupportingMultiExecInst(S, _msg)
#endif

/*
 * Set/Get flag that specifies if an S-function supports
 * multiple execution instances
 */
#if defined(RTW_GENERATED_S_FUNCTION)
#if SS_SFCN_FOR_SIM && defined(ssGetOwnerBlock)
#define ssHasStateInsideForEachSS(S, value)                                                    \
    {                                                                                          \
        if (ssGetOwnerBlock(S) != NULL) {                                                      \
            boolean_T val = value;                                                             \
            _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_MODELREF_STATE_INSIDE_FOREACH, 0, \
                                            &val) _ssSafelyCallGenericFcnEnd;                  \
        }                                                                                      \
    }
#else
#define ssHasStateInsideForEachSS(S, value)
#endif
#endif

#if (SS_SL_INTERNAL || SS_SFCN_FOR_SIM)
#define ssSetWarnForFrameUpgrade(S) ((S)->mdlInfo->mdlFlags.frameUpgradeWarn = 1U)
#define _ssGetWarnForFrameUpgrade(S) ((S)->mdlInfo->mdlFlags.frameUpgradeWarn == 1U)
#endif

/*======================================================================*
 * BUS support for S-Functions
 *======================================================================*/
/*
 * Also, APIS for bus support via bus expansion. In this case,
 * the s-function block is expanded under the hood into an individual
 * s-function for each signal in the bus and then the outputs re-bused
 * to output a bus.
 *
 * Need to set_param(gcb, 'EnableBusSupport', 'on') for the S-Function block
 *
 * 1) ssSetBusPropagationSupported(S, true)
 *    This indicates that bus expansion is desired.
 *
 * 2) ssSetBusSourcePort(S, portNumber)
 *    This indicates that the bus coming into port number (0-based) of the
 *    block will supply the structure of the outgoing bus. This bus is also
 *    used for getting signal names, signal propagation etc. It is the
 *    defining bus for this block.
 *    Example: Say for the switch block, this would be set to 0.
 *
 * 3) ssSetBusInputPorts(S, int number, int* numbers)
 *    This indicates the ports of the blocks that accept buses. The bus
 *    expansion routine then checks to verify that the incoming buses at these
 *    inports are identical in terms of signal names and compiled attributes
 *    for successful expansion.
 *    Example: For the switch block this is [0 2], so "number" is set to 2
 *             and "numbers" is an array of ints of length 2 with values
 *             numbers[0] = 0; numbers[1] = 2;
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssSetBusPropagationSupported(S, value)                                     \
    {                                                                              \
        boolean_T tmp = value;                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BUS_PROPAGATION, 0, &tmp) \
            _ssSafelyCallGenericFcnEnd;                                            \
    }

#define ssSetBusSourcePort(S, port)                                                \
    {                                                                              \
        int tmp = port;                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BUS_SOURCE_PORT, 0, &tmp) \
            _ssSafelyCallGenericFcnEnd;                                            \
    }

#define ssSetBusInputPorts(S, numInports, value)                                     \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BUS_INPORTS, numInports, value) \
        _ssSafelyCallGenericFcnEnd

#else

#define ssSetBusPropagationSupported(S, value) ssSetBusPropagationSupported_cannot_be_used_in_RTW

#define ssSetBusSourcePort(S, value) ssSetBusSourcePort_cannot_be_used_in_RTW

#define ssSetBusInputPorts(S, numInports, value) ssSetBusInputPorts_cannot_be_used_in_RTW



#endif
/*
 * APIS for bus support via bus objects. In this case, the s-function outputs
 * a bus as defined by a bus object (which can be a parameter). The output
 * function should implement the bus output consistent with the bus object.
 *
 * Need to set_param(gcb, 'EnableBusSupport', 'on') for the S-Function block
 *
 * 1)  ssSetBusOutputObjectName(S, int_T portNumber, char* busName)
 *     This specifies the bus object that defines the bus coming out of the
 *     s-function block at output number (0-based) of the block.
 *
 * 2)  ssSetBusInputAsStruct(S, int_T portNumber, boolean_T val)
 *     This specifies if the input bus as specified by the bus object should
 *     be converted to non-virtual if necessary. By setting it to true, an auto-
 *     conversion block is inserted behind the scenes to convert a virtual
 *     bus input to a non-virtual bus
 *
 * 3)  ssSetBusOutputAsStruct(S, int_T portNumber, boolean_T val)
 *     This specifies if the output bus as specified by the bus object should
 *     emerge as a structure (non-virtual) or a virtual bus. By setting it to false,
 *     a Signal Conversion block is automatically inserted behind the scenes to
 *     output a virtual bus.
 *
 *     --------------------------------------------------------------------------
 *     The next set of macros can be used to obtain information for a specific element
 *     of a bus object given the data type index of the bus object and the appropriate
 *     bus element index within the bus object. The data type index of the bus object
 *     is the index returned by Simulink when the bus object was registered in
 *     mdlInitializeSizes() (using ssRegisterTypeFromParameter() for example)
 *     --------------------------------------------------------------------------
 *
 * 4)  ssGetNumBusElements(S, int_T busTypeID)
 *     Get the number of bus elements in the specified bus object. The bus data type
 *     is passed in as the second argument.
 *
 * 5)  ssGetBusElementOffset(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the offset in bytes (int_T) from the start of the bus data type to
 *     the specified bus element. The bus data type is passed in as the second
 *     argument and the bus element index (zero based index) is passed in as the
 *     third argument.
 *
 * 6)  ssGetBusElementDataType(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the data type index (int_T) for the specified bus element. The bus data
 *     type is passed in as the second argument and the bus element index (zero based
 *     index) is passed in as the third argument.
 *
 * 7)  ssGetBusElementComplexSignal(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the complexity (CSignal_T) of the specified bus element. The bus
 *     data type is passed in as the second argument and the bus element index (zero
 *     based index) is passed in as the third argument.
 *
 * 8)  ssGetBusElementNumDimensions(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the number of signal dimensions (int_T) for the specified bus element.
 *     The bus data type is passed in as the second argument and the bus element index
 *     (zero based index) is passed in as the third argument.
 *
 * 9)  ssGetBusElementDimensions(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the dimensions (const int_T*) for the specified bus element. Use in combination
 *     with ssGetBusElementNumDimensions() above to iterate over the integer array
 *     returned by this macro. The bus data type is passed in as the second argument
 *     and the bus element index (zero based index) is passed in as the third argument.
 *
 * 10) ssGetBusElementDimensionsMode(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the dimensions mode (DimensionsMode_T) for the specified bus element.
 *     The bus data type is passed in as the second argument and the bus element index
 *     (zero based index) is passed in as the third argument.
 *
 * 11) ssGetBusElementName(S, int_T busTypeId, int_T elemIdx)
 *     Get the name (const char*) of the specified bus element. The bus data type is passed
 *     in as the second argument and the bus element index (zero based index) is
 *     passed in as the third argument.
 *
 * 12) ssIsDataTypeABus(S, int_T typeID)
 *     Determine if the data type ID passed in is a bus signal. An int_T value is
 *     returned (1 for bus, 0 for non-bus, and -1 when error occurs).
 *
 * 13) ssGetBusElementMin(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the minimum (real_T) for the specified bus element.
 *     The bus data type is passed in as the second argument and the bus element index
 *     (zero based index) is passed in as the third argument.
 *
 * 14) ssGetBusElementMax(S, int_T busTypeID, int_T elemIdx)
 *     Obtain the maximum (real_T) for the specified bus element.
 *     The bus data type is passed in as the second argument and the bus element index
 *     (zero based index) is passed in as the third argument.
 */


#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
/* Use of ssSetBusObjectName is not recommended. Please use ssSetBusOutputObjectName instead. */
#define ssSetBusObjectName(S, pIdx, name) (ssSetBusOutputObjectName((S), (pIdx), (name)))

#define ssGetBusElementDimensionsMode(S, busTypeID, elemIdx)                                \
    (dtaGetDataTypeElementDimensionsMode(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), \
                                         (elemIdx)))

#define ssGetBusElementMin(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementMin(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))

#define ssGetBusElementMax(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementMax(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))

#define ssGetBusElementUnitId(S, busTypeId, elemIdx) \
    (dtaGetDataTypeElementUnitId(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))

#else

#define ssSetBusObjectName(S, pIdx, name)

#define ssGetBusElementDimensionsMode(S, busTypeID, elemIdx) \
    ssGetBusElementDimensionsMode_cannot_be_used_in_RTW

#define ssGetBusElementMin(S, busTypeID, elemIdx) ssGetBusElementMin_cannot_be_used_in_RTW

#define ssGetBusElementMax(S, busTypeID, elemIdx) ssGetBusElementMax_cannot_be_used_in_RTW

#endif

/*
 * NOTE:
 *     The following bus mode related macros are currently not used
 */
typedef void (*mdlSetInputPortBusModeFcn)(SimStruct* S, int_T portIdx, BusMode_T dimsMode);

#define ssRegMdlSetInputPortBusModeFcn(S, fcn)                                             \
    {                                                                                      \
        mdlSetInputPortBusModeFcn _mdlBusModeFcn = fcn;                                    \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REG_SET_INPUT_BUS_MODE_MTH, 0,        \
                                        (void*)_mdlBusModeFcn) _ssSafelyCallGenericFcnEnd; \
    }

#define ssGetInputPortBusMode(S, pIdx) \
    CONV_BITS2BUSMODE((S)->portInfo.inputs[(pIdx)].attributes.busMode)

#define ssGetOutputPortBusMode(S, pIdx) \
    CONV_BITS2BUSMODE((S)->portInfo.outputs[(pIdx)].attributes.busMode)



/* ============================================================================
 * API to specify that output port is discrete valued
 * ============================================================================*/
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssSetOutputPortDiscreteValuedOutput(S, pIdx, value)                                        \
    {                                                                                              \
        boolean_T tmp = value;                                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_OUTPUT_PORT_DISCRETE_VALUED_OUTPUT, pIdx, \
                                        &tmp) _ssSafelyCallGenericFcnEnd;                          \
    }

#else
#define ssSetOutputPortDiscreteValuedOutput(S, pIdx, value)
#endif


/* ============================================================================
 * API to identify output ports that can serve as IC source.
 * ==========================================================================*/

#if defined(RTW_GENERATED_S_FUNCTION) || SS_SL_INTERNAL || defined(SS_XPC_SFCN) || SS_SFCN
typedef struct _ssICAttribs_tag {
    boolean_T computeInStart;
    boolean_T computeInFirstInitialize;
    boolean_T computeInDisable;
} _ssICAttribs;
#define ssSetOutputPortICAttributes(S, pIdx, value1, value2, value3)                       \
    {                                                                                      \
        _ssICAttribs val = {value1, value2, value3};                                       \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_OUTPUT_IC_ATTRIBUTES, pIdx, &val) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
#endif

/* ============================================================================
 * API to declare model reference block that can be placed inside state enabled
 * subsystem.
 * ==========================================================================*/
/*
 * Set flag that specifies if an S-function is strictly updating its states in
 * mdlUpdate.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetStatesModifiedOnlyInUpdate(S, value)                                                 \
    {                                                                                             \
        boolean_T val = value;                                                                    \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_STATES_MODIFIED_ONLY_IN_UPDATE, 0, &val) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }
#else
#define ssSetStatesModifiedOnlyInUpdate(S, value)
#endif

/*
 * Set flag that specifies if an S-function is supporting synchronous semantics
 * besides classic semantics
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetStateSemanticsClassicAndSynchronous(S, value)                                         \
    {                                                                                              \
        boolean_T val = value;                                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_STATE_EXECUTION_SEMANTICS_SYNCHRONOUS, 0, \
                                        &val) _ssSafelyCallGenericFcnEnd;                          \
    }
#else
#define ssSetStateSemanticsClassicAndSynchronous(S, value)
#endif

/* ============================================================================
 * Symbolic dimensions APIs
 * ===========================================================================*/
#if (SS_SL_INTERNAL || SS_SFCN_FOR_SIM)

typedef struct _ssSymbolicDimStringOp {
    const char_T* expr;
    SymbDimsId returnValue;
} ssSymbolicDimStringOp;

typedef struct _ssSymbolicDimMATLABExprOp {
    const char_T* fMATLABExpr;
    const DimsInfo_AsInt* fDimsInfo;
    SymbDimsId returnValue;
} ssSymbolicDimMatlabExprOp;

typedef struct _ssSymbolicDimNDOp {
    const SymbDimsId* dims;
    size_t numDims;
    SymbDimsId returnValue;
} ssSymbolicDimNDOp;

/* For SFcnGeneric call to registerSymbolicMExpr  */
#define MATLABEXPR 1

#endif

#if (SS_SFCN_FOR_SIM)
#ifdef __cplusplus
extern "C" {
#endif
#endif

/*
 * This function is used to specify that an S-function does or doesn't support
 * symbolic dimension (default false).
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetSymbolicDimsSupport(SimStruct* S, const boolean_T val);
#define ssSetSymbolicDimsSupport(S, _setting) _ssSetSymbolicDimsSupport(S, _setting)
#else
#define ssSetSymbolicDimsSupport(S, _setting)
#endif

/*
 * This function is used to create a symbolic dimensions id (SymbDimsId) from
 * a expression. Notice that the expression string must form a valid syntax
 * in C.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsExpr(SimStruct* S, const char_T* aExpr);
#define ssRegisterSymbolicDimsExpr(S, aExpr) _ssRegisterSymbolicDimsExpr(S, aExpr)
#else
#define ssRegisterSymbolicDimsExpr(S, aExpr)
#endif

/*
 *    This function registers a MATLAB expression string (aMATLABExpr) as a
 *    symbolic dimension and returns its symbolic dimensions id.
 *    Notice that aMATLABExpr should form a valid syntax in MATLAB.
 *    The dimensions parameter (aDimsInfo) allow the client to trim tailing ones,
 *    by defining the number of dimension, that should be converted to symbolic
 *    dimensions. The dimension value of aDimsInfo will be used for elements of
 *    aExpr that are not valid symbolic dimensions.
 *    _ssRegisterSymbolicDimsMATLABExpr returns SL_NOSYMBDIMS if all elements
 *    of aExpr are not symbolic expressions.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsMATLABExpr(SimStruct* S,
                                                    const char_T* aMATLABExpr,
                                                    const DimsInfo_AsInt* aDimsInfo);
#define ssRegisterSymbolicDimsMATLABExpr(S, aMATLABExpr, aDimsInfo) \
    _ssRegisterSymbolicDimsMATLABExpr(S, aMATLABExpr, aDimsInfo)
#else
#define ssRegisterSymbolicDimsMATLABExpr(S, aMATLABExpr, aDimsInfo)
#endif


/*
 * This function is used to create n-dimensional symbolic dimensions id
 * (SymbDimsId) from a vector of symbolic dimension ids.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDims(SimStruct* S,
                                          const SymbDimsId* aDimsVec,
                                          const size_t aNumDims);
#define ssRegisterSymbolicDims(S, aDimsVec, aNumDims) _ssRegisterSymbolicDims(S, aDimsVec, aNumDims)
#else
#define ssRegisterSymbolicDims(S, aDimsVec, aNumDims)
#endif

/*
 * This function is used to create a symbolic dimensions id (SymbDimsId) from
 * a identifier string.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsString(SimStruct* S, const char_T* aString);
#define ssRegisterSymbolicDimsString(S, aString) _ssRegisterSymbolicDimsString(S, aString)
#else
#define ssRegisterSymbolicDimsString(S, aString)
#endif

/*
 * This function is used to create a symbolic dimensions id (SymbDimsId) from
 * a integer value.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsIntValue(SimStruct* S, const int_T aIntValue);
#define ssRegisterSymbolicDimsIntValue(S, aIntValue) _ssRegisterSymbolicDimsIntValue(S, aIntValue)
#else
#define ssRegisterSymbolicDimsIntValue(S, aIntValue)
#endif

/*
 * This function is used to add equal relation between two symbolic dimensions
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssRegisterSymbolicEqualRelation(SimStruct* S,
                                             const SymbDimsId aLHS,
                                             const SymbDimsId aRHS);
#define ssRegisterSymbolicEqualRelation(S, aLHS, aRHS) \
    _ssRegisterSymbolicEqualRelation(S, aLHS, aRHS)
#else
#define ssRegisterSymbolicEqualRelation(S, aLHS, aRHS)
#endif

/*
 * This function is used to add equal relation between a symbolic dimension
 * and integer value
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssRegisterSymbolicEqualValue(SimStruct* S, const SymbDimsId aLHS, const int_T aValue);
#define ssRegisterSymbolicEqualValue(S, aLHS, aValue) _ssRegisterSymbolicEqualValue(S, aLHS, aValue)
#else
#define ssRegisterSymbolicEqualValue(S, aLHS, aValue)
#endif

/*
 * Create a new symbolic dimension by merging an existing one
 * and desired dimension, for handling "leading 1" issue
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssAmendLeadingSymbolicDims(SimStruct* S,
                                              const int_T numDims,
                                              const SymbDimsId aDimsId);
#define ssAmendLeadingSymbolicDims(S, numDims, aDimsId) \
    _ssAmendLeadingSymbolicDims(S, numDims, aDimsId)
#else
#define ssAmendLeadingSymbolicDims(S, numDims, aDimsId)
#endif

/*
 * Create a new symbolic dimension by merging an existing one
 * and desired dimension, for handling "trailing 1" issue
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssAmendTrailingSymbolicDims(SimStruct* S,
                                               const int_T numDims,
                                               const SymbDimsId aDimsId);
#define ssAmendTrailingSymbolicDims(S, numDims, aDimsId) \
    _ssAmendTrailingSymbolicDims(S, numDims, aDimsId)
#else
#define ssAmendTrailingSymbolicDims(S, numDims, aDimsId)
#endif

/*
 * This function is used to add two symbolic dimensions
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsPlus(SimStruct* S,
                                              const SymbDimsId aLHS,
                                              const SymbDimsId aRHS);
#define ssRegisterSymbolicDimsPlus(S, aLHS, aRHS) _ssRegisterSymbolicDimsPlus(S, aLHS, aRHS)
#else
#define ssRegisterSymbolicDimsPlus(S, aLHS, aRHS)
#endif

/*
 * This function is used to subtract two symbolic dimensions
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsMinus(SimStruct* S,
                                               const SymbDimsId aLHS,
                                               const SymbDimsId aRHS);
#define ssRegisterSymbolicDimsMinus(S, aLHS, aRHS) _ssRegisterSymbolicDimsMinus(S, aLHS, aRHS)
#else
#define ssRegisterSymbolicDimsMinus(S, aLHS, aRHS)
#endif

/*
 * This function is used to multiply two symbolic dimensions
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsMultiply(SimStruct* S,
                                                  const SymbDimsId aLHS,
                                                  const SymbDimsId aRHS);
#define ssRegisterSymbolicDimsMultiply(S, aLHS, aRHS) _ssRegisterSymbolicDimsMultiply(S, aLHS, aRHS)
#else
#define ssRegisterSymbolicDimsMultiply(S, aLHS, aRHS)
#endif

/*
 * This function is used to divide two symbolic dimensions
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssRegisterSymbolicDimsDivide(SimStruct* S,
                                                const SymbDimsId aLHS,
                                                const SymbDimsId aRHS);
#define ssRegisterSymbolicDimsDivide(S, aLHS, aRHS) _ssRegisterSymbolicDimsDivide(S, aLHS, aRHS)
#else
#define ssRegisterSymbolicDimsDivide(S, aLHS, aRHS)
#endif

/*
 * This function returns the number of dimensions for a given symbolic
 * dimensions id (SymbDimsId);
 */
#if (SS_SFCN_FOR_SIM)
extern size_t _ssGetNumSymbolicDims(SimStruct* S, const SymbDimsId aSymbDimsId);
#define ssGetNumSymbolicDims(S, aSymbDimsId) _ssGetNumSymbolicDims(S, aSymbDimsId)
#else
#define ssGetNumSymbolicDims(S, aSymbDimsId)
#endif

/*
 * This function returns the number of dimensions for a given symbolic
 * dimensions id (SymbDimsId);
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssGetSymbolicDim(SimStruct* S,
                                    const SymbDimsId aSymbDimsId,
                                    const int_T aDimsIdx);
#define ssGetSymbolicDim(S, aSymbDimsId, aDimsIdx) _ssGetSymbolicDim(S, aSymbDimsId, aDimsIdx)
#else
#define ssGetSymbolicDim(S, aSymbDimsId, aDimsIdx)
#endif

/*
 * This function sets the pre compiled symbolic dimensions id (SymbDimsId)
 * of a given input port index.
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetInputPortSymbolicDimsId(SimStruct* S,
                                          const int_T aPortIdx,
                                          const SymbDimsId aSymbDimsId);
#define ssSetInputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId) \
    _ssSetInputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#else
#define ssSetInputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#endif

/*
 * This function returns the compiled symbolic dimensions id (SymbDimsId)
 * for given input port index.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssGetCompInputPortSymbolicDimsId(SimStruct* S, const int_T aPortIdx);
#define ssGetCompInputPortSymbolicDimsId(S, aPortIdx) _ssGetCompInputPortSymbolicDimsId(S, aPortIdx)
#else
#define ssGetCompInputPortSymbolicDimsId(S, aPortIdx)
#endif

/*
 * This function sets the compiled symbolic dimensions id (SymbDimsId)
 * of a given input port index.
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetCompInputPortSymbolicDimsId(SimStruct* S,
                                              const int_T aPortIdx,
                                              const SymbDimsId aSymbDimsId);
#define ssSetCompInputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId) \
    _ssSetCompInputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#else
#define ssSetCompInputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#endif

/*
 * This function sets the pre compiled symbolic dimensions id (SymbDimsId)
 * of a given output port index.
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetOutputPortSymbolicDimsId(SimStruct* S,
                                           const int_T aPortIdx,
                                           const SymbDimsId aSymbDimsId);
#define ssSetOutputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId) \
    _ssSetOutputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#else
#define ssSetOutputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#endif

/*
 * This function returns the compiled symbolic dimensions id (SymbDimsId)
 * for a given output port index.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssGetCompOutputPortSymbolicDimsId(SimStruct* S, const int_T aPortIdx);
#define ssGetCompOutputPortSymbolicDimsId(S, aPortIdx) \
    _ssGetCompOutputPortSymbolicDimsId(S, aPortIdx)
#else
#define ssGetCompOutputPortSymbolicDimsId(S, aPortIdx)
#endif

/*
 * This function sets the compiled symbolic dimensions id (SymbDimsId) of
 * a given output port index.
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetCompOutputPortSymbolicDimsId(SimStruct* S,
                                               const int_T aPortIdx,
                                               const SymbDimsId aSymbDimsId);
#define ssSetCompOutputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId) \
    _ssSetCompOutputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#else
#define ssSetCompOutputPortSymbolicDimsId(S, aPortIdx, aSymbDimsId)
#endif

/*
 * This function sets the symbolic dimensions id (SymbDimsId)
 * of a given dwork index.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssGetDWorkSymbolicDimsId(SimStruct* S, const int_T aDWorkIdx);
#define ssGetDWorkSymbolicDimsId(S, aDWorkIdx) _ssGetDWorkSymbolicDimsId(S, aDWorkIdx)
#else
#define ssGetDWorkSymbolicDimsId(S, aDWorkIdx)
#endif

/*
 * This function sets the symbolic dimensions id (SymbDimsId)
 * of a given dwork index.
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetDWorkSymbolicDimsId(SimStruct* S,
                                      const int_T aDWorkIdx,
                                      const SymbDimsId aSymbDimsId);
#define ssSetDWorkSymbolicDimsId(S, aDWorkIdx, aSymbDimsId) \
    _ssSetDWorkSymbolicDimsId(S, aDWorkIdx, aSymbDimsId)
#else
#define ssSetDWorkSymbolicDimsId(S, aDWorkIdx, aSymbDimsId)
#endif

/*
 * This function gets the compiled symbolic dimensions id (SymbDimsId)
 * of a given dwork index.
 */
#if (SS_SFCN_FOR_SIM)
extern SymbDimsId _ssGetCompDWorkSymbolicDimsId(SimStruct* S, const int_T aDWorkIdx);
#define ssGetCompDWorkSymbolicDimsId(S, aDWorkIdx) _ssGetCompDWorkSymbolicDimsId(S, aDWorkIdx)
#else
#define ssGetCompDWorkSymbolicDimsId(S, aDWorkIdx)
#endif

/*
 * This function sets the compiled symbolic dimensions id (SymbDimsId)
 * of a given dwork index.
 */
#if (SS_SFCN_FOR_SIM)
extern void _ssSetCompDWorkSymbolicDimsId(SimStruct* S,
                                          const int_T aPortIdx,
                                          const SymbDimsId aSymbDimsId);
#define ssSetCompDWorkSymbolicDimsId(S, aDWorkIdx, aSymbDimsId) \
    _ssSetCompDWorkSymbolicDimsId(S, aDWorkIdx, aSymbDimsId)
#else
#define ssSetCompDWorkSymbolicDimsId(S, aDWorkIdx, aSymbDimsId)
#endif

#if (SS_SFCN_FOR_SIM)
#ifdef __cplusplus
}
#endif
#endif

/* ============================================================================
 * Variable dimensions APIs
 * ==========================================================================*/


#define ssGetDWorkRequireResetForSignalSize(S, index) \
    (SS_VariableSizeStateResetType)((S)->work.dWorkAux[(index)].flags.ensureResetForSizeVary)



typedef void (*SetOutputDimsRuleFcn)(SimStruct* S, int outIdx, int ruleIdx);

typedef struct {
    int numRules;
    int* numInpsRule;
    int* inpIndices;
    SetOutputDimsRuleFcn setOutputDimsRuleFcn;
} MdlRefOutDimsInfo_T;

typedef void (*MdlRefFinalizeDimsFcn)(SimStruct* S);

typedef struct {
    MdlRefFinalizeDimsFcn finalizeDimsFcn;
} MdlRefFinalizeDimsInfo_T;

typedef struct {
    int _sysIdx;
    int _blkIdx;
    int _outIdx;
    int _ruleIdx;
} VarDimsAccelSetDims_T;

typedef struct {
    int _sysIdx;
    int _blkIdx;
    int _portIdx;
    int _tid;
    int _function;
} ModelBlockFcnCallInput_T;

typedef struct {
    const char* name;
    const uint32_T** elements;
} DataTypeChecksumInfo_T;

#if SS_SFCN && SS_SIM

#define ssRegMdlRefSetOutputDimsMethods(S, outIdx, ruleInfo)                                       \
    {                                                                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REG_MODELREF_SET_DIMS_DEPEND_RULES, (outIdx), \
                                        (ruleInfo)) _ssSafelyCallGenericFcnEnd;                    \
    }

#define ssRegMdlRefFinalizeDimsMethod(S, finalizeDimsFcnPtr)                                   \
    {                                                                                          \
        MdlRefFinalizeDimsInfo_T info;                                                         \
        info.finalizeDimsFcn = finalizeDimsFcnPtr;                                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REG_MODELREF_FINALIZE_DIMS_MTH, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }


#define ssCallAccelSetDims(S, sysIdx, blkIdx, outIdx, ruleIdx)                                  \
    {                                                                                           \
        VarDimsAccelSetDims_T accelSetDimsInfo;                                                 \
        accelSetDimsInfo._sysIdx = sysIdx;                                                      \
        accelSetDimsInfo._blkIdx = blkIdx;                                                      \
        accelSetDimsInfo._outIdx = outIdx;                                                      \
        accelSetDimsInfo._ruleIdx = ruleIdx;                                                    \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ACCEL_CALL_SET_DIMS, 0, &accelSetDimsInfo) \
            _ssSafelyCallGenericFcnEnd;                                                         \
    }


#define ssCallAccelModelBlockFcnCallInput(S, sysIdx, blkIdx, portIdx, tid, function)             \
    {                                                                                            \
        ModelBlockFcnCallInput_T accelModelBlockFcnCallInfo;                                     \
        accelModelBlockFcnCallInfo._sysIdx = sysIdx;                                             \
        accelModelBlockFcnCallInfo._blkIdx = blkIdx;                                             \
        accelModelBlockFcnCallInfo._portIdx = portIdx;                                           \
        accelModelBlockFcnCallInfo._tid = tid;                                                   \
        accelModelBlockFcnCallInfo._function = function;                                         \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ACCEL_CALL_MODEL_FCNCALL_INPUT, 0,          \
                                        &accelModelBlockFcnCallInfo) _ssSafelyCallGenericFcnEnd; \
    }

#define ssCallAccelCopyCacheForIISBasedOnDescSysList(S, sysIdx, fromCache)                   \
    {                                                                                        \
        _ssSafelyCallGenericFcnStart(S)(                                                     \
            (S), GEN_FCN_ACCEL_COPY_STATE_CACHE_FOR_IIS_IN_DESC_SYS_LIST, sysIdx, fromCache) \
            _ssSafelyCallGenericFcnEnd;                                                      \
    }

#define ssCallAccelCopyCacheForIISBasedOnCGSysList(S, sysIdx, fromCache)                   \
    {                                                                                      \
        _ssSafelyCallGenericFcnStart(S)(                                                   \
            (S), GEN_FCN_ACCEL_COPY_STATE_CACHE_FOR_IIS_IN_CG_SYS_LIST, sysIdx, fromCache) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }

#define ssCallGetDataTypeChecksum(S, dtName, els)                                           \
    {                                                                                       \
        DataTypeChecksumInfo_T chksumInfo;                                                  \
        chksumInfo.name = dtName;                                                           \
        chksumInfo.elements = els;                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATATYPE_CHECKSUM, 0, &chksumInfo) \
            _ssSafelyCallGenericFcnEnd;                                                     \
    }

#define ssCheckStructParamChecksum(S, index, chksum)                                      \
    {                                                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_CHECK_STRUCTPARAM_CHECKSUM, (index), \
                                        (chksum)) _ssSafelyCallGenericFcnEnd;             \
    }

#define ssCallSetRegAutosarClientBlock(S, isClientBlock)                                      \
    {                                                                                         \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REG_AUTOSAR_CLIENT_BLOCK, isClientBlock, \
                                        NULL) _ssSafelyCallGenericFcnEnd;                     \
    }

#define ssCallGetNumVariantConditions(S, conditionIndex, result)                                 \
    {                                                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_NUM_VARIANT_CONDITIONS, conditionIndex, \
                                        result) _ssSafelyCallGenericFcnEnd;                      \
    }

#endif

#define _ssGetBlkInfo2STInfo2Ptr(S) (S)->blkInfo.blkInfo2->stInfo2

#define _ssSetBlkInfo2STInfo2Ptr(S, ptr) (S)->blkInfo.blkInfo2->stInfo2 = (ptr)

#define _ssGetBlkInfo2PortInfo2Ptr(S) (S)->blkInfo.blkInfo2->portInfo2

#define _ssSetBlkInfo2PortInfo2Ptr(S, ptr) (S)->blkInfo.blkInfo2->portInfo2 = (ptr)

#define _ssSetPortInfo2ForInputs(S, ptr) (S)->blkInfo.blkInfo2->portInfo2->inputs = (ptr)

#define _ssGetPortInfo2ForInputs(S) (S)->blkInfo.blkInfo2->portInfo2->inputs

#define _ssSetPortInfo2ForOutputs(S, ptr) (S)->blkInfo.blkInfo2->portInfo2->outputs = (ptr)

#define _ssGetPortInfo2ForOutputs(S) (S)->blkInfo.blkInfo2->portInfo2->outputs

#define _ssSetPortInfo2ForInputUnits(S, ptr) (S)->blkInfo.blkInfo2->portInfo2->inputUnits = (ptr)

#define _ssGetPortInfo2ForInputUnits(S) (S)->blkInfo.blkInfo2->portInfo2->inputUnits

#define _ssSetPortInfo2ForOutputUnits(S, ptr) (S)->blkInfo.blkInfo2->portInfo2->outputUnits = (ptr)

#define _ssGetPortInfo2ForOutputUnits(S) (S)->blkInfo.blkInfo2->portInfo2->outputUnits

#define _ssSetPortInfo2ForInputDimsConstraint(S, ptr) \
    (S)->blkInfo.blkInfo2->portInfo2->inputDimsConstraint = (ptr)

#define _ssGetPortInfo2ForInputDimsConstraint(S) \
    (S)->blkInfo.blkInfo2->portInfo2->inputDimsConstraint

#define _ssSetPortInfo2ForOutputDimsConstraint(S, ptr) \
    (S)->blkInfo.blkInfo2->portInfo2->outputDimsConstraint = (ptr)

#define _ssGetPortInfo2ForOutputDimsConstraint(S) \
    (S)->blkInfo.blkInfo2->portInfo2->outputDimsConstraint

#define _ssSetPortInfo2ForInputCoSimAttribute(S, ptr) \
    (S)->blkInfo.blkInfo2->portInfo2->inputCoSimAttribute = (ptr)

#define _ssSetPortInfo2ForOutputCoSimAttribute(S, ptr) \
    (S)->blkInfo.blkInfo2->portInfo2->outputCoSimAttribute = (ptr)

#define _ssGetPortInfo2ForInputCoSimAttribute(S) \
    (S)->blkInfo.blkInfo2->portInfo2->inputCoSimAttribute

#define _ssGetPortInfo2ForOutputCoSimAttribute(S) \
    (S)->blkInfo.blkInfo2->portInfo2->outputCoSimAttribute

#if defined(USE_64BIT_FIELDS)
#define _ssSetInputPortVariableDimsPtr(S, pIdx, uDims) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(pIdx)].portVarDims = (uDims)
#elif defined(USE_32BIT_FIELDS)
#define _ssSetInputPortVariableDimsPtr(S, pIdx, uDims) \
    (S)->blkInfo.blkInfo2->portInfo2->inputs[(pIdx)].portVarDims = (uDims)
#endif

#if defined(USE_64BIT_FIELDS)
#define _ssSetOutputPortVariableDimsPtr(S, pIdx, yDims) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(pIdx)].portVarDims = (yDims)
#elif defined(USE_32BIT_FIELDS)
#define _ssSetOutputPortVariableDimsPtr(S, pIdx, yDims) \
    (S)->blkInfo.blkInfo2->portInfo2->outputs[(pIdx)].portVarDims = (yDims)
#elif defined(SL_INTERNAL) || defined(IS_RSIM) || defined(IS_RAPID_ACCEL)
#define _ssSetOutputPortVariableDimsPtr(S, pIdx, yDims) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(pIdx)].portVarDims = (yDims)
#endif

/* AsInt macros should only be used in code allocating and initializing 32-bit
   S-Functions. Currently, this includes simulink engine and sim targets */
#define _ssSetInputPortVariableDimsPtrAsInt(S, pIdx, uDims) \
    (S)->blkInfo.blkInfo2->portInfo2->inputs[(pIdx)].portVarDims = (uDims)
#define _ssSetOutputPortVariableDimsPtrAsInt(S, pIdx, yDims) \
    (S)->blkInfo.blkInfo2->portInfo2->outputs[(pIdx)].portVarDims = (yDims)

#if !SS_SFCN

#define _ssSetBlockIOVarDims(S, ptr) (S)->mdlInfo->blockIOVarDims = (ptr)

#define _ssGetBlockIOVarDims(S) (S)->mdlInfo->blockIOVarDims
#endif


/*============================================================================*/

/*
 * Data Store API
 *
 * This API is for internal MathWorks use only and is not intended for use
 * by user written S-functions. Accessing Data Stores is not
 * yet supported for user written S-functions. This API WILL change in
 * a future release.
 */

#if SS_SFCN && SS_SIM
#define ssSetNumDataStores(S, numDataStores)                                                     \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REGISTER_NUM_DATA_STORE, (numDataStores), NULL) \
        _ssSafelyCallGenericFcnEnd
#endif


typedef enum { SS_READER_ONLY, SS_WRITER_ONLY, SS_READER_AND_WRITER } SS_ReaderOrWriter;

typedef struct {
    const char* name;
    SS_ReaderOrWriter readerOrWriter;
    boolean_T elementAccess;
    boolean_T expectGlobal;
    boolean_T* success;
} SFcnDataStoreNameInfo;

#if SS_SFCN && SS_SIM
#define ssRegisterGlobalDataStoreFromName(S, dsmIdx, dsmName, dsmReadOrWrite, dsmElemAccess, \
                                          dsmSuccess)                                        \
    {                                                                                        \
        SFcnDataStoreNameInfo locPI;                                                         \
        locPI.name = dsmName;                                                                \
        locPI.readerOrWriter = dsmReadOrWrite;                                               \
        locPI.elementAccess = dsmElemAccess;                                                 \
        locPI.expectGlobal = true;                                                           \
        locPI.success = dsmSuccess;                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REGISTER_DATA_STORE_FROM_NAME, dsmIdx,  \
                                        &locPI) _ssSafelyCallGenericFcnEnd;                  \
    }
#endif

#if SS_SFCN && SS_SIM
#define ssRegisterDataStoreFromName(S, dsmIdx, dsmName, dsmReadOrWrite, dsmElemAccess, dsmSuccess) \
    {                                                                                              \
        SFcnDataStoreNameInfo locPI;                                                               \
        locPI.name = dsmName;                                                                      \
        locPI.readerOrWriter = dsmReadOrWrite;                                                     \
        locPI.elementAccess = dsmElemAccess;                                                       \
        locPI.expectGlobal = false;                                                                \
        locPI.success = dsmSuccess;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REGISTER_DATA_STORE_FROM_NAME, dsmIdx,        \
                                        &locPI) _ssSafelyCallGenericFcnEnd;                        \
    }
#endif

/* The dsmInfo in ssGetDataStoreInfo is of type SFcnDataStoreInfo */
typedef struct {
    double sample_time;
    double offset_time;
    int dataTypeId;
    int numDims;
    int* dims;
    int complex;
} SFcnDataStoreInfo;
#if SS_SFCN && SS_SIM
#define ssGetDataStoreInfo(S, dsmIdx, dsmInfo)                                         \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATA_STORE_INFO, dsmIdx, dsmInfo) \
        _ssSafelyCallGenericFcnEnd
#endif

typedef struct {
    const char* bpath;
    void* addr;
} SFcnDataStoreBPathAddr;
/* Structure for passing data store info into Simulink */

#if SS_SFCN && SS_SIM
/* Note that the dsmBPath must be persistent and constant
 * i.e. inside Simulink the pointer is cached, we do not make a deep copy
 */
#define ssReadFromDataStoreWithPath(S, dsmIdx, dsmBPath, dataAddr)                         \
    {                                                                                      \
        SFcnDataStoreBPathAddr locPI;                                                      \
        locPI.bpath = dsmBPath;                                                            \
        locPI.addr = dataAddr;                                                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_READ_FROM_DATA_STORE, dsmIdx, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
#define ssReadFromDataStore(S, dsmIdx, dataAddr) \
    ssReadFromDataStoreWithPath(S, dsmIdx, NULL, dataAddr)
#endif

typedef struct {
    const char* bpath;
    const void* addr;
} SFcnDataStoreBPathConstAddr;

#if SS_SFCN && SS_SIM
/* Note that the dsmBPath must be persistent and constant
 * i.e. inside Simulink the pointer is cached, we do not make a deep copy
 */
#define ssWriteToDataStoreWithPath(S, dsmIdx, dsmBPath, dataAddr)                         \
    {                                                                                     \
        SFcnDataStoreBPathConstAddr locPI;                                                \
        locPI.bpath = dsmBPath;                                                           \
        locPI.addr = dataAddr;                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_WRITE_TO_DATA_STORE, dsmIdx, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                                   \
    }
#define ssWriteToDataStore(S, dsmIdx, dataAddr) \
    ssWriteToDataStoreWithPath(S, dsmIdx, NULL, dataAddr)
#endif


#if SS_SFCN && SS_SIM

/* Update Data Store Memory logs after writing data.
 */
#define ssUpdateDataStoreLog(S, dsmIdx)                                                   \
    {                                                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_DATA_STORE_LOG_UPDATE, dsmIdx, NULL) \
            _ssSafelyCallGenericFcnEnd;                                                   \
    }

#endif

/* Remember: storage is column major order if accessing element of a matrix */
typedef struct {
    const char* bpath;
    void* addr;
    int elem;
} SFcnDataStoreBPathAddrElem;

#if SS_SFCN && SS_SIM
/* Note that the dsmBPath must be persistent and constant
 * i.e. inside Simulink the pointer is cached, we do not make a deep copy
 */
#define ssReadFromDataStoreElementWithPath(S, dsmIdx, dsmBPath, dataAddr, dsmElem)              \
    {                                                                                           \
        SFcnDataStoreBPathAddrElem locPI;                                                       \
        locPI.bpath = dsmBPath;                                                                 \
        locPI.addr = dataAddr;                                                                  \
        locPI.elem = dsmElem;                                                                   \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_READ_FROM_DATA_STORE_ELEM, dsmIdx, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                                         \
    }
#define ssReadFromDataStoreElement(S, dsmIdx, dataAddr, dsmElem) \
    ssReadFromDataStoreElementWithPath(S, dsmIdx, NULL, dataAddr, dsmElem)
#endif

typedef struct {
    const char* bpath;
    const void* addr;
    int elem;
} SFcnDataStoreBPathConstAddrElem;

#if SS_SFCN && SS_SIM
/* Note that the dsmBPath must be persistent and constant
 * i.e. inside Simulink the pointer is cached, we do not make a deep copy
 */
#define ssWriteToDataStoreElementWithPath(S, dsmIdx, dsmBPath, dataAddr, dsmElem)              \
    {                                                                                          \
        SFcnDataStoreBPathConstAddrElem locPI;                                                 \
        locPI.bpath = dsmBPath;                                                                \
        locPI.addr = dataAddr;                                                                 \
        locPI.elem = dsmElem;                                                                  \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_WRITE_TO_DATA_STORE_ELEM, dsmIdx, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }
#define ssWriteToDataStoreElement(S, dsmIdx, dataAddr, dsmElem) \
    ssWriteToDataStoreElementWithPath(S, dsmIdx, NULL, dataAddr, dsmElem)
#endif


typedef struct {
    const char* name;
    char* dataTypeName;
    boolean_T expectGlobal;
    const char* sharedLocalDSMInfo;
    int* idx;
    void** addr;
} SFcnDataStoreNameAddrIdx;

#if SS_SFCN && SS_SIM
#define ssGetSFcnDataStoreNameAddrIdx(S, dsmName, dsmAddr, dsmIdx)                   \
    {                                                                                \
        SFcnDataStoreNameAddrIdx locPI;                                              \
        locPI.name = dsmName;                                                        \
        locPI.dataTypeName = NULL;                                                   \
        locPI.expectGlobal = false;                                                  \
        locPI.sharedLocalDSMInfo = "";                                               \
        locPI.idx = dsmIdx;                                                          \
        locPI.addr = dsmAddr;                                                        \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATA_STORE_ADDR, 0, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                              \
    }
#endif

#if SS_SFCN && SS_SIM
#define ssGetSFcnGlobalDataStoreNameAddrIdx(S, dsmName, dsmDTName, dsmAddr, dsmIdx, dsmInfo) \
    {                                                                                        \
        SFcnDataStoreNameAddrIdx locPI;                                                      \
        locPI.name = dsmName;                                                                \
        locPI.dataTypeName = dsmDTName;                                                      \
        locPI.expectGlobal = true;                                                           \
        locPI.sharedLocalDSMInfo = dsmInfo;                                                  \
        locPI.idx = dsmIdx;                                                                  \
        locPI.addr = dsmAddr;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATA_STORE_ADDR, 0, &locPI)         \
            _ssSafelyCallGenericFcnEnd;                                                      \
    }
#endif

/* Region-wise memory access API */
typedef enum {
    MEM_REGION_SELECT_ALL = 0,
    MEM_REGION_STARTIDX_INCR_ENDIDX,
    MEM_REGION_VECTOR,
    MEM_REGION_VECTOR_FLATIDX,
    MEM_REGION_DYNAMIC_IDX
} SFcnMemRegionIndexMode_T;

typedef struct {
    SFcnMemRegionIndexMode_T indexMode;
    int numIndices;
    int* indices;
} SFcnSubMemRegionIndexInfo;

typedef struct {
    int busElementIdx;
    int numDims;
    SFcnSubMemRegionIndexInfo* subMemRegionIndexInfos;
} SFcnSubMemRegionInfo;

typedef struct {
    int numSubMemRegions;
    SFcnSubMemRegionInfo* subMemRegionInfos;
    /* Following fields for Simulink use only */
    boolean_T cacheSlMemRootRegion;
    void* slMemRootRegion;
    char* memRegionExpr;
    boolean_T reserved;
} SFcnMemRegionInfo;

typedef struct {
    const char* bpath;
    void* addr;
    SFcnMemRegionInfo* regionDescriptor;
} SFcnDataStoreMemRegionArg;

typedef struct {
    const char* bpath;
    const void* addr;
    SFcnMemRegionInfo* regionDescriptor;
} SFcnDataStoreMemRegionConstArg;

typedef struct {
    int busElemIdx;
    int numFlatElems;
    int* flatElemIndices;
    SFcnMemRegionInfo* regionDescriptor;
} SFcnDataStoreFlatSubMemRegionArg;

typedef struct {
    const char* bpath;
    int startOffset;
    int endOffset;
    boolean_T doRead; /* true: updates diagnostics for read operations,
                         false: updates diagnostics for write operations */
} SFcnDataStoreUpdateMemRegionArg;

/* APIs to create/destroy region descriptors */
#if SS_SFCN && SS_SIM
#define ssMemRegionCreateDescriptor(S, numSubMemRegions, memRegionDescriptor)                   \
    {                                                                                           \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_CREATE_MEM_REGION_DESC, numSubMemRegions,  \
                                        (void*)memRegionDescriptor) _ssSafelyCallGenericFcnEnd; \
    }

#define ssMemRegionSetFlatSubElement(S, memRegionDescriptor, subRegionIdx, busElementIdx,        \
                                     numFlatIdx, flatIdxs)                                       \
    {                                                                                            \
        SFcnDataStoreFlatSubMemRegionArg locPI;                                                  \
        locPI.regionDescriptor = memRegionDescriptor;                                            \
        locPI.busElemIdx = busElementIdx;                                                        \
        locPI.numFlatElems = numFlatIdx;                                                         \
        locPI.flatElemIndices = flatIdxs;                                                        \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_FLAT_MEM_SUB_REGION_DESC, subRegionIdx, \
                                        &locPI) _ssSafelyCallGenericFcnEnd;                      \
    }

#define ssMemRegionDestroyDescriptor(S, memRegionDescriptor)                                    \
    {                                                                                           \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_DESTROY_MEM_REGION_DESC, 0,                \
                                        (void*)memRegionDescriptor) _ssSafelyCallGenericFcnEnd; \
    }
#endif

/* APIs to perform region-wise read/write */
#if SS_SFCN && SS_SIM
#define ssReadFromDataStoreRegionWithPath(S, dsmIdx, dsmBPath, dataAddr, dsmRegionDescriptor)     \
    {                                                                                             \
        SFcnDataStoreMemRegionArg locPI;                                                          \
        locPI.bpath = dsmBPath;                                                                   \
        locPI.addr = dataAddr;                                                                    \
        locPI.regionDescriptor = dsmRegionDescriptor;                                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_READ_FROM_DATA_STORE_REGION, dsmIdx, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }
#define ssReadFromDataStoreRegion(S, dsmIdx, dataAddr, dsmRegionDescriptor) \
    ssReadFromDataStoreRegionWithPath(S, dsmIdx, NULL, dataAddr, dsmRegionDescriptor)
#endif

#if SS_SFCN && SS_SIM
#define ssWriteToDataStoreRegionWithPath(S, dsmIdx, dsmBPath, dataAddr, dsmRegionDescriptor)     \
    {                                                                                            \
        SFcnDataStoreMemRegionConstArg locPI;                                                    \
        locPI.bpath = dsmBPath;                                                                  \
        locPI.addr = dataAddr;                                                                   \
        locPI.regionDescriptor = dsmRegionDescriptor;                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_WRITE_TO_DATA_STORE_REGION, dsmIdx, &locPI) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }
#define ssWriteToDataStoreRegion(S, dsmIdx, dataAddr, dsmRegionDescriptor) \
    ssWriteToDataStoreRegionWithPath(S, dsmIdx, NULL, dataAddr, dsmRegionDescriptor)
#endif

/* API to notify Simulink of region-wise read/write */
#if SS_SFCN && SS_SIM
#define ssUpdateDataStoreRegionDiagnostics(S, dsmIdx, dsmBPath, startOffset, endOffset, doRead) \
    {                                                                                           \
        SFcnDataStoreUpdateMemRegionArg locPI;                                                  \
        locPI.bpath = dsmBPath;                                                                 \
        locPI.startOffset = startOffset;                                                        \
        locPI.endOffset = endOffset;                                                            \
        locPI.doRead = doRead;                                                                  \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_UPDATE_DATA_STORE_DIAGNOSTICS, dsmIdx,     \
                                        &locPI) _ssSafelyCallGenericFcnEnd;                     \
    }
#endif

/* API to detect if read/write diagnostics are ON on a given data store memory */
#if SS_SFCN && SS_SIM
#define ssGetDataStoreRWDiagnosticsStatus(S, dsmIdx, dsmDiagStatus)                             \
    {                                                                                           \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATA_STORE_DIAGNOSTICS_STATUS, dsmIdx, \
                                        dsmDiagStatus) _ssSafelyCallGenericFcnEnd;              \
    }
#endif

/* end  Data Store API (internal Simulink use only) */
/*============================================================================*/

#if SS_SFCN && SS_SIM
#define ssGetRegSubmodelsMdlinfo(S, result)                                                \
    {                                                                                      \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_REG_SUBMODELS_MDLINFO, 0, result) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
#endif


/* ================================================================= */

typedef enum { MDLREF_UNKNOWN = 0, MDLREF_ACCEL_SIM, MDLREF_NORMAL_SIM, MDLREF_RTW } ssMdlRefType;

#if SS_SFCN && SS_SIM
#ifdef ssGetOwnerBlock
#define ssGetModelReferenceType(S, val)                                         \
    {                                                                           \
        *(val) = MDLREF_UNKNOWN;                                                \
        if (!((ssGetOwnerBlock(S) == NULL) && ((S)->parent != NULL))) {         \
            _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_MDLREF_TYPE, 0, val) \
                _ssSafelyCallGenericFcnEnd;                                     \
        }                                                                       \
    }
#endif
#else
#define ssGetModelReferenceType(S, val) ssGetModelReferenceType_cannot_be_used_in_RTW
#endif


/* =======================================
 * Model reference definitions and macros.
 * =======================================*/

/* Structure for mdl info from reference models */
typedef struct {
    const char* id;          /* identifier associated with info */
    MdlInfoType infoType;    /* info type                       */
    boolean_T extra_bool;    /* boolean value for arbitrary use */
    int_T extra_int;         /* int value for arbitrary use     */
    const void* extra_voidp; /* pointer for arbitrary use       */
} RegMdlInfo;

/* Structure for set of mdl info from reference models */
typedef struct {
    char* modelName;       /* model name                      */
    RegMdlInfo* modelInfo; /* info                            */
    int numModelInfo;      /* number of records               */
} ModelRefMdlInfoSet;

/* Structure for referenced models info. mrBlk  is NULL when this structure
 * is registered by model reference accelerated target.
 */
typedef struct {
    char* name;
    char* path;
    boolean_T isSingleInst;
} MdlRefChildMdlRec;

/* Only used in MODELREF S-functions */
typedef enum {
    SS_OK_TO_MERGE_AUTO = 0, /* default */
    SS_OK_TO_MERGE,
    SS_NOT_OK_TO_MERGE,
    SS_OK_TO_MERGE_CONDITIONAL
} ssOkToMergeFlag;

#define ssGetOutputPortOkToMerge(S, port) \
    ((ssOkToMergeFlag)((S)->portInfo.outputs[(port)].attributes.okToMerge))

#if !SS_SFCN_LEVEL_1
#if SS_SIM
#define _ssMdlInfoInit(name, infoTypeUsed, b, i, vp) \
    RegMdlInfo locPI;                                \
    locPI.id = name;                                 \
    locPI.infoType = infoTypeUsed;                   \
    locPI.extra_bool = b;                            \
    locPI.extra_int = i;                             \
    locPI.extra_voidp = vp;

#define ssRegMdlInfo(S, id, infoType, b, i, vp)                                            \
    {                                                                                      \
        _ssMdlInfoInit(id, infoType, b, i, vp) if (!_ssSafelyCallGenericFcnStart(S)(       \
                                                       S, GEN_FCN_REG_MDL_INFO, 0, &locPI) \
                                                       _ssSafelyCallGenericFcnEnd) return; \
    }
#else
#define ssRegMdlInfo(S, id, infoType, b, i, vp)
#endif
#endif

typedef enum {
    SS_MDLREF_FUND_SAMPLETYPE_INFO_STR = 0,
    SS_MDLREF_FUND_SAMPLETYPE_INFO_VAL
} _ssMdlRefFundamentalSampleTimeInfoType;


#if SS_SFCN && SS_SIM

#define ssSetOutputPortOkToMerge(S, port, val) \
    (S)->portInfo.outputs[(port)].attributes.okToMerge = (ssOkToMergeFlag)(val)

#define ssRegMdlRefDWorkType(S, type)                                          \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REG_MDLREF_DWORK_TYPE, 0, type) \
        _ssSafelyCallGenericFcnEnd


/* Names of the ToFile's for a submodel*/
#define ssSetModelRefToFiles(S, num, str)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_MODELREF_TO_FILES, num, str) \
        _ssSafelyCallGenericFcnEnd

#define ssFileLoggingManagerAddElement(S, ptr)                                           \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_FILE_LOGGING_MANAGER_ADD_ELEMENT, 0, ptr) \
        _ssSafelyCallGenericFcnEnd

#define ssFileLoggingManagerRemoveElement(S, ptr)                                           \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_FILE_LOGGING_MANAGER_REMOVE_ELEMENT, 0, ptr) \
        _ssSafelyCallGenericFcnEnd

/* Names of the FromFile's for a submodel*/
#define ssSetModelRefFromFiles(S, num, str)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_MODELREF_FROM_FILES, num, str) \
        _ssSafelyCallGenericFcnEnd

#define ssSetModelMappingInfoPtr(S, ptr)                                     \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_MODELMAPPINGINFO, 0, ptr) \
        _ssSafelyCallGenericFcnEnd

#define _ssMdlInfoSetInit(name, info, num) \
    ModelRefMdlInfoSet locPI;              \
    locPI.modelName = (name);              \
    locPI.modelInfo = (info);              \
    locPI.numModelInfo = (num);

#define ssRegModelRefMdlInfo(S, name, info, num)                                              \
    {                                                                                         \
        _ssMdlInfoSetInit((name), (info), (num)) if (!_ssSafelyCallGenericFcnStart(S)(        \
                                                         S, GEN_FCN_REG_MODELREF_MDL_INFO, 0, \
                                                         &locPI)                              \
                                                         _ssSafelyCallGenericFcnEnd) return;  \
    }

#define ssGetModelRefModelArgData(S, pIdx, dataPtr)                                         \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_MODELREF_INTFPARAM_MODEL_ARG_DATA, pIdx, \
                                    (void*)dataPtr) _ssSafelyCallGenericFcnEnd

#define ssGetModelRefBlockArgData(S, pIdx, dataPtr)                                         \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_MODELREF_INTFPARAM_BLOCK_ARG_DATA, pIdx, \
                                    (void*)dataPtr) _ssSafelyCallGenericFcnEnd

#define ssGetModelRefGlobalParamData(S, pIdx, dataPtr)                                   \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_MODELREF_INTFPARAM_GLOBAL_DATA, pIdx, \
                                    (void*)dataPtr) _ssSafelyCallGenericFcnEnd

#endif

#define ssGetModelReferenceSampleTimeInheritanceRule(S) (S)->sizes.flags.modelRefTsInhSupLevel



#define ssGetSimStateCompliance(S) ((ssSimStateCompliance)((S)->sizes.flags.simStateCompliance))

#define ssGetOperatingPointCompliance(S) \
    ((ssOperatingPointCompliance)((S)->sizes.flags.simStateCompliance))

#define ssGetSimStateVisibility(S) ((S)->sizes.flags.simStateVisibility)

#define ssSetSimStateCompliance(S, set) (S)->sizes.flags.simStateCompliance = (set)

#define ssSetSimStateVisibility(S, vis) (S)->sizes.flags.simStateVisibility = (vis)

/*-------------------------------- S->states --------------------------------*/

/* U - This is the input to your S-function providing you have not specified
 *   the SS_OPTION_USING_ssGetUPtrs. For the root SimStruct this
 *   is the external input vector.
 */
#if SS_SFCN_LEVEL_1 && SS_SIM && !SS_NDEBUG
extern void* _ssGetUFcn(const SimStruct* S);
#define _ssGetU(S) ((real_T*)_ssGetUFcn(S))
#else
#define _ssGetU(S) ((real_T*)(S)->states.U.vect) /* (const real_T *) */
#endif

#if !SS_SFCN_NORMAL
#define ssGetU(S) _ssGetU(S)
#define _ssSetU(S, u) (S)->states.U.vect = (u)
#endif
#if !SS_SFCN
#define ssSetU(S, u) _ssSetU(S, u)
#else
#define ssSetU(S, u) ssSetU_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN
#define ssGetExternalU(S) ((S)->states.U.vect)
#endif

#define ssGetUByIndex(S, portIndex, pReturnValue)                                         \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_ACCEL_MDLREF_VM_GET_U_BY_INDEX, portIndex, \
                                    pReturnValue) _ssSafelyCallGenericFcnEnd;


#define ssGetYByIndex(S, portIndex, pReturnValue)                                         \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_ACCEL_MDLREF_VM_GET_Y_BY_INDEX, portIndex, \
                                    pReturnValue) _ssSafelyCallGenericFcnEnd;

#define ssSlMrAccelRunBlockSystemInitialize(S, sysIdx, blkIdxPtr)                            \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_ACCEL_MDLREF_BLOCK_SYSTEM_INITIALIZE, sysIdx, \
                                    blkIdxPtr) _ssSafelyCallGenericFcnEnd;

#define ssSlMrAccelRunBlockSystemReset(S, sysIdx, blkIdxPtr)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_ACCEL_MDLREF_BLOCK_SYSTEM_RESET, sysIdx, blkIdxPtr) \
        _ssSafelyCallGenericFcnEnd;

typedef struct {
    int_T sysIdx;
    int_T blkIdx;
    char_T** path;
} BlockPathInfo;

#define _ssGetBlockPath(S, inSysIdx, inBlkIdx, inPath)                       \
    {                                                                        \
        BlockPathInfo info;                                                  \
        info.sysIdx = (inSysIdx);                                            \
        info.blkIdx = (inBlkIdx);                                            \
        info.path = (inPath);                                                \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_BLOCK_PATH, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                      \
    }

#define _ssGetGlobalDataTransferIndices(S, indices)                                              \
    {                                                                                            \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_GLOBAL_DATA_TRANSFER_INDICES, 0, indices) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }

#define _ssDataTransferRead(S, dtIdx, data)                                         \
    {                                                                               \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_DATA_TRANSFER_READ, dtIdx, data) \
            _ssSafelyCallGenericFcnEnd;                                             \
    }

#define _ssDataTransferWrite(S, dtIdx, data)                                         \
    {                                                                                \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_DATA_TRANSFER_WRITE, dtIdx, data) \
            _ssSafelyCallGenericFcnEnd;                                              \
    }

#define _ssDataTransferInitBuffers(S, dtIdx, data)                                          \
    {                                                                                       \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_DATA_TRANSFER_INIT_BUFFERS, dtIdx, data) \
            _ssSafelyCallGenericFcnEnd;                                                     \
    }

typedef struct {
    int _sysIdx;
    int _blkIdx;
    int _function;
} PrePostRunBlock_T;

#define ssCallAccelPreBlock(S, sysIdx, blkIdx, function)                               \
    {                                                                                  \
        PrePostRunBlock_T prePostInfo;                                                 \
        prePostInfo._sysIdx = sysIdx;                                                  \
        prePostInfo._blkIdx = blkIdx;                                                  \
        prePostInfo._function = function;                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ACCEL_PRE_BLOCK, 0, &prePostInfo) \
            _ssSafelyCallGenericFcnEnd;                                                \
    }

#define ssCallAccelPostBlock(S, sysIdx, blkIdx, function)                               \
    {                                                                                   \
        PrePostRunBlock_T prePostInfo;                                                  \
        prePostInfo._sysIdx = sysIdx;                                                   \
        prePostInfo._blkIdx = blkIdx;                                                   \
        prePostInfo._function = function;                                               \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ACCEL_POST_BLOCK, 0, &prePostInfo) \
            _ssSafelyCallGenericFcnEnd;                                                 \
    }

/* UPtrs - This returns an array of input pointers (UPtrsType) to your
 *   S-function block. This should only be used when using the
 *   SS_OPTION_USING_ssGetUPtrs (level 1 S-functions only).
 */
#if !SS_SFCN_NORMAL
#define ssGetUPtrs(S) (S)->states.U.uPtrs /* (UPtrsType)      */
#define _ssSetUPtrs(S, uptrs) (S)->states.U.uPtrs = (uptrs)
#endif
#if !SS_SFCN
#define ssSetUPtrs(S, uptrs) _ssSetUPtrs(S, uptrs)
#else
#define ssSetUPtrs(S, uptrs) ssSetUPtrs_cannot_be_used_in_SFunctions
#endif


/* Y - This is the output vector for your S-function block. For the root
 *   SimStruct, this is the external output vector. The length of this
 *   vector is ssGetNumOutputs.
 */
#define _ssGetY(S) (SS_STATIC_CAST(real_T*, (S)->states.Y)) /*   (real_T *)    */

#if !SS_SFCN_NORMAL
#define ssGetY(S) _ssGetY(S)
#define _ssSetY(S, y) (S)->states.Y = (SS_STATIC_CAST(void*, y))
#endif
#if !SS_SFCN
#define ssSetY(S, y) _ssSetY(S, y)
#else
#define ssSetY(S, y) ssSetY_cannot_be_used_in_SFunctions
#endif


#if !SS_SFCN
#define ssGetExternalY(S) (S)->states.Y
#endif



#if SS_SFCN_LEVEL_1
/* X - This is the state vector for your S-function block. The length of
 *  vector is ssGetNumTotalStates. The first part of the vector
 *  is for the continuous state elements consisting of ssGetNumContStates
 *  and the second part of the vector is the discrete state elements
 *  consisting of ssGetNumDiscStates. For the root model, SimStruct, this
 *  contains the states of all blocks with in the model.
 */
#define ssGetX(S) (S)->states.contStates /*   (real_T *)    */
#define _ssSetX(S, x) (S)->states.contStates = (x)

#else

/*
 * ContStates - continuous state vector for your S-function. There is
 *   no guarantee that if you have both continuous and discrete states
 *   that they will be contiguous
 */
#define _ssSetContStates(S, contX) (S)->states.contStates = (contX)
#if !SS_SFCN
#define ssGetX(S) ssGetContStates(S)
#define ssSetContStates(S, contX) _ssSetContStates(S, contX)
#else
#define ssSetContStates(S, x) ssSetContStates_cannot_be_used_in_SFunctions
#endif

#define _ssSetDiscStates(S, discX) (S)->states.discStates = (discX)
#if !SS_SFCN
#define ssSetDiscStates(S, discX) _ssSetDiscStates(S, discX)
#else
#define ssSetDiscStates(S, x) ssSetDiscStates_cannot_be_used_in_SFunctions
#endif

#endif


/*
 * By default Simulink monitors continuous state changes within S-function and
 * issues warning for changes which are not notified to ODE/DAE solver via
 * ssSetSolverNeedsReset. Continuous states changes without solver resets are
 * unsafe and may be ignored in future releases. This check can be skipped for
 * efficiency if S-function is written correctly to reset the solver for all
 * state changes by using ssSetSkipContStatesConsistencyCheck(S,1)
 */


#define ssGetSkipContStatesConsistencyCheck(S) (S)->states.flags.skipContStatesConsistencyCheck

/* dX - This is the continuous state derivative vector for your S-function
 *  block. The length of this vector is ssGetNumContStates. This pointer
 *  changes as the solver evaluates different integration stages to compute
 *  the integral. For the root model SimStruct, this contains the derivatives
 *  for all continuous states of all blocks with in the model.
 */

#define _ssSetdX(S, dx) (S)->states.dX = (dx)
#if !SS_SFCN
#define ssSetdX(S, dx) _ssSetdX(S, dx)
#else
#define ssSetdX(S, dx) ssSetdX_cannot_be_used_in_SFunctions
#endif


/* slvrJacobian */
/* mdlSlvrJacobian was removed for R2012b) */
/* slvrJacobian - This struct contains the slvrJacobian matrix for your S-function
 *   block.  The size of this matrix is (nxc + ny) x (nxc + nu).
 *   All of the storage involved will be allocated automatically, provided
 *   that nzmax is set to the correct value (or a number larger than the
 *   correct value).  Setting nzmax == -1 will construct a full matrix.  It
 *   is then your responsibility to fill in correct values for *pr, *ir, *jc.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetSlvrJacobianNzMax(S) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.numSlvrJacobianNzmax)
#define ssSetSlvrJacobianNzMax(S, n) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.numSlvrJacobianNzmax = (n))

#define ssGetSlvrJacobianHeader(S) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix)
#if !SS_SFCN
#define ssSetSlvrJacobianHeader(S, p) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix = (p))
#else
#define ssSetSlvrJacobianHeader(S, p) ssSetSlvrJacobianHeader_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianIr(S) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->Ir)
#if !SS_SFCN
#define ssSetSlvrJacobianIr(S, ir) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->Ir = (ir))
#else
#define ssSetSlvrJacobianIr(S, ir) ssSetSlvrJacobianIr_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianJc(S) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->Jc)
#if !SS_SFCN
#define ssSetSlvrJacobianJc(S, jc) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->Jc = (jc))
#else
#define ssSetSlvrJacobianJc(S, jc) ssSetSlvrJacobianJc_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianM(S) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->mRows)
#if !SS_SFCN
#define ssSetSlvrJacobianM(S, m) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->mRows = (m))
#else
#define ssSetSlvrJacobianM(S, m) ssSetSlvrJacobianM_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianN(S) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->nCols)
#if !SS_SFCN
#define ssSetSlvrJacobianN(S, n) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.slvrJacobianMatrix->nCols = (n))
#else
#define ssSetSlvrJacobianN(S, n) ssSetSlvrJacobianN_cannot_be_used_in_SFunctions
#endif
#elif defined(USE_32BIT_FIELDS)
#define ssGetSlvrJacobianNzMax(S) ((S)->states.modelMethods2->modelMethods3->numSlvrJacobianNzmax)
#define ssSetSlvrJacobianNzMax(S, n) \
    ((S)->states.modelMethods2->modelMethods3->numSlvrJacobianNzmax = (n))

#define ssGetSlvrJacobianHeader(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix)
#if !SS_SFCN
#define ssSetSlvrJacobianHeader(S, p) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix = (p))
#else
#define ssSetSlvrJacobianHeader(S, p) ssSetSlvrJacobianHeader_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianIr(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Ir)
#if !SS_SFCN
#define ssSetSlvrJacobianIr(S, ir) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Ir = (ir))
#else
#define ssSetSlvrJacobianIr(S, ir) ssSetSlvrJacobianIr_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianJc(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Jc)
#if !SS_SFCN
#define ssSetSlvrJacobianJc(S, jc) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Jc = (jc))
#else
#define ssSetSlvrJacobianJc(S, jc) ssSetSlvrJacobianJc_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianM(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->mRows)
#if !SS_SFCN
#define ssSetSlvrJacobianM(S, m) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->mRows)
#else
#define ssSetSlvrJacobianM(S, m) ssSetSlvrJacobianM_cannot_be_used_in_SFunctions
#endif

#define ssGetSlvrJacobianN(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->nCols)
#if !SS_SFCN
#define ssSetSlvrJacobianN(S, n) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->nCols = (n))
#else
#define ssSetSlvrJacobianN(S, n) ssSetSlvrJacobianN_cannot_be_used_in_SFunctions
#endif
#endif

#define ssGetSlvrJacobianPr(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Pr)
#define _ssSetSlvrJacobianPr(S, pr) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Pr = (pr))

#if !SS_SFCN
#define ssSetSlvrJacobianPr(S, pr) _ssSetSlvrJacobianPr(S, pr)
#else
#define ssSetSlvrJacobianPr(S, pr) ssSetSlvrJacobian_cannot_be_used_in_SFunctions
#endif

/* Int and AsInt APIs should exclusively be used to setup and destruction of Int versions of there
   Jacobian header, Ir, and Jc for 32-bit S-Functions and root SimStruct. For all other use cases,
   use the non-int versions of these macros defined above. */
#if defined(SL_INTERNAL)
#define ssGetSlvrJacobianHeaderInt(S) ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix)
#define ssSetSlvrJacobianHeaderInt(S, p) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix = (p))

#define ssGetSlvrJacobianIrAsInt(S) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Ir)
#define ssSetSlvrJacobianIrAsInt(S, ir) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Ir = (ir))
#define ssGetSlvrJacobianJcAsInt(S) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Jc)
#define ssSetSlvrJacobianJcAsInt(S, jc) \
    ((S)->states.modelMethods2->modelMethods3->slvrJacobianMatrix->Jc = (jc))
#endif

/* Jacobian - This struct contains the Jacobian matrix for your S-function
 *   block.  The size of this matrix is (nxc + nxd + ny) x (nxc + ndx + nu).
 *   All of the storage involved will be allocated automatically, provided
 *   that nzmax is set to the correct value (or a number larger than the
 *   correct value).  Setting nzmax == -1 will construct a full matrix.  It
 *   is then your responsibility to fill in correct values for *pr, *ir, *jc.
 *   The values for *ir and *jc should be initialized in function mdlJacobianIrJc.
 */

#if defined(USE_64BIT_FIELDS)
#define ssGetJacobianNzMax(S) ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.numJacobianNzMax)
#define ssSetJacobianNzMax(S, n) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.numJacobianNzMax = (n))

#define ssGetJacobianHeader(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian /* (SparseHeader *) */
#if !SS_SFCN
#define ssSetJacobianHeader(S, p) (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian = (p)
#else
#define ssSetJacobianHeader(S, p) ssSetJacobianHeader_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianIr(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->Ir /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianIr(S, ir) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->Ir = (ir)
#else
#define ssSetJacobianIr(S, ir) ssSetJacobianIr_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianJc(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->Jc /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianJc(S, jc) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->Jc = (jc)
#else
#define ssSetJacobianJc(S, jc) ssSetJacobianJc_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianM(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->mRows /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianM(S, m) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->mRows = (m)
#else
#define ssSetJacobianM(S, m) ssSetJacobianM_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianN(S) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->nCols /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianN(S, n) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->jacobianInfo.jacobian->nCols = (n)
#else
#define ssSetJacobianN(S, n) ssSetJacobianN_cannot_be_used_in_SFunctions
#endif
#elif defined(USE_32BIT_FIELDS)
#define ssGetJacobianNzMax(S) ((S)->sizes.numJacobianNzMax)
#define ssSetJacobianNzMax(S, n) ((S)->sizes.numJacobianNzMax = (n))

#define ssGetJacobianHeader(S) (S)->states.jacobian /* (SparseHeader *) */
#if !SS_SFCN
#define ssSetJacobianHeader(S, p) (S)->states.jacobian = (p)
#else
#define ssSetJacobianHeader(S, p) ssSetJacobianHeader_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianIr(S) (S)->states.jacobian->Ir /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianIr(S, ir) (S)->states.jacobian->Ir = (ir)
#else
#define ssSetJacobianIr(S, ir) ssSetJacobianIr_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianJc(S) (S)->states.jacobian->Jc /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianJc(S, jc) (S)->states.jacobian->Jc = (jc)
#else
#define ssSetJacobianJc(S, jc) ssSetJacobianJc_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianM(S) (S)->states.jacobian->mRows /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianM(S, m) (S)->states.jacobian->mRows = (m)
#else
#define ssSetJacobianM(S, m) ssSetJacobianM_cannot_be_used_in_SFunctions
#endif

#define ssGetJacobianN(S) (S)->states.jacobian->nCols /*   (int_T *)    */
#if !SS_SFCN
#define ssSetJacobianN(S, n) (S)->states.jacobian->nCols = (n)
#else
#define ssSetJacobianN(S, n) ssSetJacobianN_cannot_be_used_in_SFunctions
#endif
#endif

#define ssGetJacobianPr(S) (S)->states.jacobian->Pr /*   (real_T *)    */
#define _ssSetJacobianPr(S, pr) (S)->states.jacobian->Pr = (pr)
#if !SS_SFCN
#define ssSetJacobianPr(S, pr) _ssSetJacobianPr(S, pr)
#else
#define ssSetJacobianPr(S, pr) ssSetJacobian_cannot_be_used_in_SFunctions
#endif

/* Int and AsInt APIs should exclusively be used to setup and destruction of Int versions of there
   Jacobian header, Ir, and Jc for 32-bit S-Functions and root SimStruct. For all other use cases,
   use the non-int versions of these macros defined above. */
#if defined(SL_INTERNAL)
#define ssGetJacobianNzMaxAsInt(S) ((S)->sizes.numJacobianNzMax)
#define ssGetJacobianHeaderInt(S) (S)->states.jacobian
#define ssSetJacobianHeaderInt(S, p) (S)->states.jacobian = (p)
#define ssGetJacobianJcAsInt(S) (S)->states.jacobian->Jc
#define ssSetJacobianJcAsInt(S, jc) (S)->states.jacobian->Jc = (jc)
#define ssGetJacobianIrAsInt(S) (S)->states.jacobian->Ir
#define ssSetJacobianIrAsInt(S, ir) (S)->states.jacobian->Ir = (ir)
#endif

typedef enum {
    SS_JACOBIAN_NOT_SUPPORTED = 0,
    SS_JACOBIAN_EXACT,
    SS_JACOBIAN_CUSTOMIZED
} SFcnJacobianType;

#define _ssSetJacobianTypeAndMsg(S, type, msg)                                     \
    {                                                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_JACOBIAN_FLAG, type, msg) \
            _ssSafelyCallGenericFcnEnd;                                            \
    }

#define ssSetJacobianTypeAndMsg(S, type, msg) _ssSetJacobianTypeAndMsg(S, type, msg)
#define ssSetJacobianType(S, type) _ssSetJacobianTypeAndMsg(S, type, NULL)

#define ssCallDefaultJacobianMethod(S)                                               \
    {                                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_CALL_DEFAULT_JACOBIAN, 0, NULL) \
            _ssSafelyCallGenericFcnEnd;                                              \
    }

#define ssConfigDefaultJacobian(S)                                                     \
    {                                                                                  \
        ssSetJacobianNzMax(S, -1);                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_CONFIG_DEFAULT_JACOBIAN, 0, NULL) \
            _ssSafelyCallGenericFcnEnd;                                                \
    }


/* SupportRunTimeModelAPI - Runtime model API refers to the model function with
'outputs', 'derivs' and 'update' command. If the S-function block writes to
any persistent memory during mdlOutputs function, e.g., either dWork or a
persistent variable, it is likely that these block may need to set this
flag to false.

Similarly, if the S-function block writes to any persistent memory other than dX
in the mdlDerivatives, or if the S-function block writes to any persistent memory
other than the discrete states in mdlUpdate, it is likely that this flag needs
to be set to false.

The default value for the flag is true.
 */
#define ssSetSupportRunTimeModelAPI(S, arg)                                                    \
    {                                                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_SUPPORT_RUNTIME_MODEL_API, arg, NULL) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }
/* MassMatrix - This struct contains the MassMatrix for your S-function
 *   block.  The size of this matrix is nx x nx.
 *   All of the storage involved will be allocated automatically, provided
 *   that nzmax is set to the correct value (or a number larger than the
 *   correct value).
 */

#define ssGetMassMatrixType(S) \
    (S)->states.modelMethods2->modelMethods3->massMatrix.type /*   (ssMatrixType)  */
#define ssSetMassMatrixType(S, t) (S)->states.modelMethods2->modelMethods3->massMatrix.type = (t)

#define ssGetMassMatrixPr(S) \
    (S)->states.modelMethods2->modelMethods3->massMatrix.info.Pr /*   (real_T *)    */
#define _ssSetMassMatrixPr(S, pr) \
    (S)->states.modelMethods2->modelMethods3->massMatrix.info.Pr = (pr)
#if !SS_SFCN
#define ssSetMassMatrixPr(S, pr) _ssSetMassMatrixPr(S, pr)
#else
#define ssSetMassMatrixPr(S, pr) ssSetMassMatrix_cannot_be_used_in_SFunctions
#endif

#if defined(USE_32BIT_FIELDS) || (defined(IS_RSIM) || defined(IS_RAPID_ACCEL))
#define ssGetMassMatrixNzMax(S) (S)->states.modelMethods2->modelMethods3->massMatrix.info.nzMax
#define ssSetMassMatrixNzMax(S, n) \
    (S)->states.modelMethods2->modelMethods3->massMatrix.info.nzMax = (n)

#define ssGetMassMatrixIr(S) (S)->states.modelMethods2->modelMethods3->massMatrix.info.Ir

#define ssGetMassMatrixJc(S) (S)->states.modelMethods2->modelMethods3->massMatrix.info.Jc
#elif defined(USE_64BIT_FIELDS)
#define ssGetMassMatrixNzMax(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->massMatrix.nzMax
#define ssSetMassMatrixNzMax(S, n) (S)->blkInfo.blkInfo2->blkInfoSLSize->massMatrix.nzMax = (n)

#define ssGetMassMatrixIr(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->massMatrix.Ir

#define ssGetMassMatrixJc(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->massMatrix.Jc
#endif

/* AsInt macros only be used by Simulink Engine code */

#define ssGetMassMatrixIrAsInt(S) (S)->states.modelMethods2->modelMethods3->massMatrix.info.Ir
#define ssGetMassMatrixJcAsInt(S) (S)->states.modelMethods2->modelMethods3->massMatrix.info.Jc
#define ssSetMassMatrixIrAsInt(S, ir) \
    (S)->states.modelMethods2->modelMethods3->massMatrix.info.Ir = (ir)
#define ssSetMassMatrixJcAsInt(S, jc) \
    (S)->states.modelMethods2->modelMethods3->massMatrix.info.Jc = (jc)
#define ssGetMassMatrixNzMaxAsInt(S) (S)->states.modelMethods2->modelMethods3->massMatrix.info.nzMax

/* There are two versions of this setter version, one to set Ir and Jc pointers to a 64-bit
   S-Function SimStruct and the other (AsInt) to set the pointers to a 32-bit S-Function
   SimStruct. Bitness can be queried using ssGetSFcnBitness(S)*/
#if !SS_SFCN
/* For now, rapid accel and rsim target will only use 32-bit setters */
#if defined(IS_RSIM) || defined(IS_RAPID_ACCEL)
#define ssSetMassMatrixIr(S, ir) (S)->states.modelMethods2->modelMethods3->massMatrix.info.Ir = (ir)
#define ssSetMassMatrixJc(S, jc) (S)->states.modelMethods2->modelMethods3->massMatrix.info.Jc = (jc)
#else
#define ssSetMassMatrixIr(S, ir) (S)->blkInfo.blkInfo2->blkInfoSLSize->massMatrix.Ir = (ir)
#define ssSetMassMatrixJc(S, jc) (S)->blkInfo.blkInfo2->blkInfoSLSize->massMatrix.Jc = (jc)
#endif
#else
#define ssSetMassMatrixIr(S, ir) ssSetMassMatrixIr_cannot_be_used_in_SFunctions
#define ssSetMassMatrixJc(S, jc) ssSetMassMatrixJc_cannot_be_used_in_SFunctions
#endif


/* Constraints - This struct contains the Constraints info
 *   for your S-function block.
 */
#define _ssGetConstraintsInfo(S) \
    (S)->states.modelMethods2->constraintsInfo /* (_ssConstraintsInfo *) */
#if !SS_SFCN
#define ssGetConstraintsInfo(S) _ssGetConstraintsInfo(S)
#else
#define ssGetConstraintsInfo(S) ssGetConstraintsInfo_cannot_be_used_in_SFunctions
#endif

#define _ssSetConstraintsInfo(S, p) (S)->states.modelMethods2->constraintsInfo = (p)
#if !SS_SFCN
#define ssSetConstraintsInfo(S, p) _ssSetConstraintsInfo(S, p)
#else
#define ssSetConstraintsInfo(S, p) ssSetConstraintsInfo_cannot_be_used_in_SFunctions
#endif

#define _ssSetConstraints(S, p) (S)->states.modelMethods2->constraintsInfo->constraints = (p)
#if !SS_SFCN
#define ssSetConstraints(S, p) _ssSetConstraints(S, p)
#else
#define ssSetConstraints(S, p) ssSetConstraints_cannot_be_used_in_SFunctions
#endif

/* These are only used in command line model API, they do nothing in the generated code */
/* The constraintInfo data structure is not created/present in generated code           */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetNumConstraints(S, n) (S)->states.modelMethods2->constraintsInfo->numConstraints = (n)
#define ssGetNumConstraints(S) \
    (S)->states.modelMethods2->constraintsInfo->numConstraints /*  (int_T)     */
#define ssGetConstraints(S) \
    (S)->states.modelMethods2->constraintsInfo->constraints /*  (real_T *)  */
#else                                                       /* RT or NRT */
#define ssSetNumConstraints(S, n)                           /* do nothing */
#define ssGetNumConstraints(S) -1                           /* silently return invalid value */
#define ssGetConstraints(S) NULL                            /* silently return invalid value */
#endif


/* ContStateDisabled - This vector is of length ssGetNumContStates and
 *   is a boolean vector indicating whether or not the states in your
 *   S-function block should be integrated. Generally this should not
 *   be modified by your S-function. It will automatically be set and
 *   cleared when your block is within an enabled subsystem during
 *   disables and enables of the subsystem block. For the root model
 *   SimStruct, this contains the boolean values for all continuous states
 *   with in the model.
 */
#define ssGetContStateDisabled(S) (S)->states.contStateDisabled /* (boolean_T *) */
#define _ssSetContStateDisabled(S, ptr) (S)->states.contStateDisabled = (ptr)
#if !SS_SFCN
#define ssSetContStateDisabled(S, ptr) _ssSetContStateDisabled(S, ptr)
#else
#define ssSetContStateDisabled(S, ptr) ssSetContStateDisabled_cannot_be_used_in_SFunctions
#endif

/*  Auxiliary state related information
 *
 */

#define _ssSetStatesInfo2(S, ptr) ((S)->states.statesInfo2) = (ptr)
#if (SS_GENERATED_S_FUNCTION || SS_SL_INTERNAL || SS_RTW_INTERNAL)
#define ssSetStatesInfo2(S, ptr) _ssSetStatesInfo2(S, ptr)
#define ssGetStatesInfo2(S) ((S)->states.statesInfo2)
#endif

/* PrevZCSigState - This vector is of length ssGetNumZCEvents. It is
 *   provided for the root model SimStruct. S-function must specify
 *   NumZCEvents as 0.
 */
#define _ssGetPrevZCSigState(S) ((S)->states.statesInfo2)->prevZCSigState /* (int_T *)       */
#if !SS_SFCN
#define ssGetPrevZCSigState(S) _ssGetPrevZCSigState(S)
#else
#define ssGetPrevZCSigState(S) ssGetPrevZCSigState_cannot_be_used_in_SFunctions
#endif
#define _ssSetPrevZCSigState(S, ptr) ((S)->states.statesInfo2)->prevZCSigState = (ptr)
#if !SS_SFCN
#define ssSetPrevZCSigState(S, ptr) _ssSetPrevZCSigState(S, ptr)
#else
#define ssSetPrevZCSigState(S, ptr) ssSetPrevZCSigState_cannot_be_used_in_SFunctions
#endif

/* NonsampledZCs - This is vector is of length ssGetNumNonsampledZCs and
 *  is the vector for the nonsampled zero crossings in your S-function.
 *  The mdlZeroCrossings method is used to fill in the nonsampled
 *  zero crossings. For the root SimStruct, this vector contains all
 *  nonsampled zero crossings in the model.
 */

#define _ssSetNonsampledZCs(S, ptr) (S)->states.nonsampledZCs = (ptr)
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssSetNonsampledZCs(S, ptr) _ssSetNonsampledZCs(S, ptr)
#else
#define ssSetNonsampledZCs(S, ptr) ssSetNonsampledZCs_cannot_be_used_in_SFunctions
#endif

/* NonsampledZCDirs - This is the zero crossing direction for the nonsampled
 *  zero crossings. It is of length ssGetNumNonsampledZCs. The default
 *  is ANY_ZERO_CROSSING.
 */
#define ssGetNonsampledZCDirs(S) (S)->states.nonsampledZCDirs /* (ZCDirection*)  */
#define _ssSetNonsampledZCDirs(S, ptr) (S)->states.nonsampledZCDirs = (ptr)
#if !SS_SFCN
#define ssSetNonsampledZCDirs(S, ptr) _ssSetNonsampledZCDirs(S, ptr)
#else
#define ssSetNonsampledZCDirs(S, ptr) ssSetNonsampledZCDirs_cannot_be_used_in_SFunctions
#endif

#define ssSetModelMethods2(S, ptr) (S)->states.modelMethods2 = (ptr)
#define ssGetModelMethods2(S) (S)->states.modelMethods2

#define ssSetModelMethods3(S, ptr) ((S)->states.modelMethods2)->modelMethods3 = (ptr)
#define ssGetModelMethods3(S) ((S)->states.modelMethods2)->modelMethods3

#define ssSetModelMethods4(S, ptr) ((S)->states.modelMethods2)->modelMethods4 = (ptr)
#define ssGetModelMethods4(S) ((S)->states.modelMethods2)->modelMethods4


/* External Mode Function */

/**
 * @brief ssSetExternalModeFcn
 *
 * Specify the external mode function for an S-function
 * @param  S      SimStruct representing an S-function block or a Simulink model.
 * @param  fcn    External mode function.
 */
#if SS_SFCN_FOR_SIM
#define ssSetExternalModeFcn(S, fcn) (S)->states.modelMethods2->extModeLogFcn = (fcn)
#endif

/**
 * @brief ssCallExternalModeFcn
 *
 * Invoke the external model function for an S-function
 * @param  S     SimStruct pointer
 * @param  meth  External mode method
 * @return An error character vector on failure, and NULL if successful.
 */
#if SS_SL_INTERNAL
#define ssCallExternalModeFcn(S, meth)                          \
    ((S)->states.modelMethods2->extModeLogFcn != NULL)          \
        ? (S)->states.modelMethods2->extModeLogFcn((S), (meth)) \
        : NULL
#endif


/*
 * Jacobian perturbation bounds
 */
#define _ssSetJacobianPerturbationBounds(S, ptr) (S)->states.statesInfo2->jacPerturbBounds = (ptr)
#define ssGetJacobianPerturbationBounds(S) (S)->states.statesInfo2->jacPerturbBounds

#if (SS_GENERATED_S_FUNCTION || SS_SL_INTERNAL || SS_RTW_INTERNAL)
#define ssSetJacobianPerturbationBounds(S, ptr) _ssSetJacobianPerturbationBounds(S, ptr)
#define ssGetJacobianPerturbationBounds(S) (S)->states.statesInfo2->jacPerturbBounds
#endif


/*
 * JacobianPerturbationBoundMinVec
 */
#define ssGetJacobianPerturbationBoundsMinVec(S) (S)->states.statesInfo2->jacPerturbBounds->min
#define _ssSetJacobianPerturbationBoundsMinVec(S, ptr) \
    (S)->states.statesInfo2->jacPerturbBounds->min = (ptr)
#if !SS_SFCN
#define ssSetJacobianPerturbationBoundsMinVec(S, ptr) _ssSetJacobianPerturbationBoundsMinVec(S, ptr)
#else
#define ssSetJacobianPerturbationBoundsMinVec(S, ptr) \
    ssSetJacobianPerturbationBoundsMinVec_cannot_be_used_in_SFunctions
#endif

/*
 * JacobianPerturbationBoundMaxVec
 *
 */
#define ssGetJacobianPerturbationBoundsMaxVec(S) (S)->states.statesInfo2->jacPerturbBounds->max
#define _ssSetJacobianPerturbationBoundsMaxVec(S, ptr) \
    (S)->states.statesInfo2->jacPerturbBounds->max = (ptr)
#if !SS_SFCN
#define ssSetJacobianPerturbationBoundsMaxVec(S, ptr) _ssSetJacobianPerturbationBoundsMaxVec(S, ptr)
#else
#define ssSetJacobianPerturbationBoundsMaxVec(S, ptr) \
    ssSetJacobianPerturbationBoundsMaxVec_cannot_be_used_in_SFunctions
#endif


#define _ssSetPeriodicStatesInfo(S, ptr) (S)->states.statesInfo2->periodicStatesInfo = (ptr)
#if (SS_GENERATED_S_FUNCTION || SS_SL_INTERNAL || SS_RTW_INTERNAL)
#define ssSetPeriodicStatesInfo(S, ptr) _ssSetPeriodicStatesInfo(S, ptr)
#define ssGetPeriodicStatesInfo(S) (S)->states.statesInfo2->periodicStatesInfo
#endif

/*
 * globalContStateIndex
 * This is the global continuous state index within the model.
 */
#define ssGetGlobalContStateIndex(S) \
    (S)->states.statesInfo2->periodicStatesInfo->globalContStateIndex /* int_T */
#define ssSetGlobalContStateIndex(S, num) \
    (S)->states.statesInfo2->periodicStatesInfo->globalContStateIndex = (num)

/*
 * numPeriodicContStates
 * This is the number of periodic continuous states within
 * your S-function. The root SimStruct contains the number of periodic continuous
 * states within the model itself (including all blocks and S-functions).
 */
#define ssGetNumPeriodicContStates(S) \
    (S)->states.statesInfo2->periodicStatesInfo->numPeriodicContStates /* int_T */
#define ssSetNumPeriodicContStates(S, num) \
    (S)->states.statesInfo2->periodicStatesInfo->numPeriodicContStates = (num)

/*
 * periodicContStateIndices
 * Periodic continuous state indices for your S-function.
 */
#define ssGetPeriodicContStateIndices(S) \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateIndices /* int_T* */
#if !SS_SFCN
#define ssSetPeriodicContStateIndices(S, ptr) \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateIndices = (ptr)
#else
#define ssSetPeriodicContStateIndices(S, ptr) \
    ssSetPeriodicContStateIndices_cannot_be_used_in_SFunctions
#endif

#define ssGetPeriodicContStateRanges(S) \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateRanges /* real_T* */
#if !SS_SFCN
#define ssSetPeriodicContStateRanges(S, ptr) \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateRanges = (ptr)
#else
#define ssSetPeriodicContStateRanges(S, ptr) \
    ssSetPeriodicContStateRanges_cannot_be_used_in_SFunctions
#endif

/*
 * periodicContState
 * Periodic continuous state vector for your S-function.
 */
#define ssSetPeriodicContState(S, idx, cont, lval, rval)                                       \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateIndices[(idx)] =             \
        (S)->states.statesInfo2->periodicStatesInfo->globalContStateIndex + (cont),            \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateRanges[(idx) << 1] = (lval), \
    (S)->states.statesInfo2->periodicStatesInfo->periodicContStateRanges[((idx) << 1) + 1] =   \
        (rval)

/*-------------------------------- S->work ----------------------------------*/


/* IWork - This is the integer work vector of length ssGetNumIWork for your
 *   S-function. For the root SimStruct, this is the integer work vector
 *   for all blocks in the model.
 */

#define _ssSetIWork(S, iwork) (S)->work.iWork = (iwork)
#if !SS_SFCN
#define ssSetIWork(S, iwork) _ssSetIWork(S, iwork)
#else
#define ssSetIWork(S, iwork) ssSetIWork_cannot_be_used_in_SFunctions
#endif



/* RWork - This is the real work vector of length ssGetNumRWork for your
 *   S-function. For the root SimStruct, this is the real work vector
 *   for all blocks in the model.
 */
#define _ssSetRWork(S, rwork) (S)->work.rWork = (rwork)
#if !SS_SFCN
#define ssSetRWork(S, rwork) _ssSetRWork(S, rwork)
#else
#define ssSetRWork(S, rwork) ssSetRWork_cannot_be_used_in_SFunctions
#endif



/* PWork - This is the pointer work vector of length ssGetNumPWork for your
 *   S-function. For the root SimStruct, this is the pointer work vector
 *   for all blocks in the model.
 */

#define _ssSetPWork(S, pwork) (S)->work.pWork = (pwork)
#if !SS_SFCN
#define ssSetPWork(S, pwork) _ssSetPWork(S, pwork)
#else
#define ssSetPWork(S, pwork) ssSetPWork_cannot_be_used_in_SFunctions
#endif



/*
 * DWork - This is the data type work vector of length ssGetNumDWork for the
 *         S-Function. User written S-Functions should not access this array
 *         directly, they should use the macros (see below) to get/set the
 *         specific fields of the dWork structure.
 */
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetSFcnDWork(S) ((S)->work.dWork.sfcn) /* (_ssDWorkRecord *) */
#define ssSetSFcnDWork(S, dwork) (S)->work.dWork.sfcn = (dwork)
#define ssGetSFcnDWorkAux(S) ((S)->work.dWorkAux) /* (_ssDWorkAuxRecord *) */
#define ssSetSFcnDWorkAux(S, dworkAux) (S)->work.dWorkAux = (dworkAux)
#endif

/*
 * Get the DWork data array
 */

#define _ssSetDWork(S, index, addr) (S)->work.dWork.sfcn[index].array = (addr)
#if !SS_SFCN
#define ssSetDWork(S, index, dwork) _ssSetDWork(S, index, dwork)
#else
#define ssSetDWork(S, index, dwork) ssSetDWork_cannot_be_used_in_SFunctions
#endif

/* AsInt macros should only be used in code allocating and initializing 32-bit
   S-Functions. Currently, this includes simulink engine and sim targets */
#define ssSetDWorkWidthAsInt(S, index, val) ((S)->work.dWork.sfcn[index].width = (val))

/*
 * Set the dimensions vector in the S-Function Simulink block
 * for the DWork at the given index.
 * Inputs: Simstruct *S, int aDWorkIndex, int aDimsVector[]
 *
 * Where aDimsVector's first element is the number of elements.
 */
#define ssSetDWorkDimensions(S, aDWorkIndex, aDimsVector)                                          \
    {                                                                                              \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_DWORK_DIMENSIONS, aDWorkIndex, aDimsVector) \
            _ssSafelyCallGenericFcnEnd;                                                            \
    }

/*
 * Register dialog parameters indexed as prmMinIdx and prmMaxIdx as design
 * minimum and maximum for the DWork of index dworkIdx.
 */
#define ssRegisterDWorkMinMaxPrmIndices(S, dworkIdx, prmMinIdx, prmMaxIdx) \
    ssRegisterDataMinMaxPrmIndices((S), SS_DATA_DESC_DWORK, (dworkIdx), (prmMinIdx), (prmMaxIdx))

/*
 * Specify when the DWork minimum and maximum range checking should be
 * performed.
 */
typedef enum {
    DWORK_MIN_MAX_CHECKING_USER_INITIATED = 0x0,
    DWORK_MIN_MAX_CHECKING_OUTPUT_ONLY = 0x1,
    DWORK_MIN_MAX_CHECKING_UPDATE_ONLY = 0x2,
    DWORK_MIN_MAX_CHECKING_OUTPUT_AND_UPDATE = 0x3
} DWorkMinMaxCheckpoint;
#define ssGetDWorkMinMaxCheckpoint(S, dworkIdx) \
    ((S)->work.dWorkAux[(dworkIdx)].flags.minMaxCheckpoint)
#define ssSetDWorkMinMaxCheckpoint(S, dworkIdx, checkpoint) \
    (S)->work.dWorkAux[(dworkIdx)].flags.minMaxCheckpoint = (checkpoint)

/*
 * Perform explicit range checking of the DWork against the associated
 * design minimum and maximum
 */
#define ssCheckDWorkRange(S, dworkIdx)                                                  \
    {                                                                                   \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_CHECK_DWORK_RANGE, (dworkIdx), NULL) \
            _ssSafelyCallGenericFcnEnd;                                                 \
    }



/* DWorkOptimizeInIR - This macro allows S-Functions that use the code
 * generation intermediate representation (CGIR) to generate code, to enable
 * optimizations that would otherwise be disabled by default. For example,
 * the macro should be used if a S-Function set its DWork conservatively as
 * global, because it is accessed in both the
 * output and the update function. It is possible for CGIR to safely optimize
 * the DWork if output and update get combined.
 */
#define ssGetDWorkOptimizeInIR(S, index) ((S)->work.dWorkAux[(index)].flags.optimizeInIR)
#define ssSetDWorkOptimizeInIR(S, index, val) (S)->work.dWorkAux[(index)].flags.optimizeInIR = val

/*
 * G(S)et the DWork "disable bounds checking" attribute.
 *
 *   Currently not supported.
 */
#define ssGetDWorkDisableBoundsChecking(S, index) (0)

/*
 * G(S)et the DWork "upload dwork in extmode" attribute.
 */
#define ssGetDWorkExtModeUpload(S, index) \
    (S)->work.dWorkAux[index].flags.ExtModeUpload /* (unsigned int_T: 1) */
#define ssSetDWorkExtModeUpload(S, index, n) \
    (S)->work.dWorkAux[index].flags.ExtModeUpload = (n) /* (unsigned int_T: 1) */

/*
 * G(S)et the DWork "upload dwork in extmode" attribute.
 */
#define ssGetDWorkExtModeUpload(S, index) \
    (S)->work.dWorkAux[index].flags.ExtModeUpload /* (unsigned int_T: 1) */
#define ssSetDWorkExtModeUpload(S, index, n) \
    (S)->work.dWorkAux[index].flags.ExtModeUpload = (n) /* (unsigned int_T: 1) */



/*
 * Routines to allow the S-function to map a block IC parameter to its dwork.
 */
#define ssGetDWorkInitialConditionParamIdx(S, index) ((S)->work.dWorkAux[(index)].icPrmIdxPlus1 - 1)
#define ssSetDWorkInitialConditionParamIdx(S, index, val) \
    (S)->work.dWorkAux[index].icPrmIdxPlus1 = ((int_T)val + 1)

/*
 * Routines to allow the S-function to map a dwork to a bit-field
 */
#define ssGetDWorkBitFieldWidth(S, index) ((S)->work.dWorkAux[(index)].bitFieldWidth)
#define ssSetDWorkBitFieldWidth(S, index, val) \
    (S)->work.dWorkAux[index].bitFieldWidth = ((int_T)val)

/*
 * RootDWork - For use by Simulink/RTW. User written S-Functions should not use
 *             this macro.
 *
 */
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetRootDWork(S) ((S)->work.dWork.root)
#define ssSetRootDWork(S, val) (S)->work.dWork.root = (val)
#endif



/* ModeVector - This is the mode vector of length ssGetNumModes for your
 *   S-function. For the root SimStruct, this is the mode vector
 *   for all blocks in the model.
 */

#define _ssSetModeVector(S, vect) (S)->work.modeVector = (vect)
#if !SS_SFCN
#define ssSetModeVector(S, vect) _ssSetModeVector(S, vect)
#else
#define ssSetModeVector(S, vect) ssSetModeVector_cannot_be_used_in_SFunctions
#endif



/* LocalMdlInfo - Internal use only
 * This is a void pointer to the owning block diagram.
 */
#define _ssSetLocalMdlInfo(S, locMdlInfo) (S)->work.localMdlInfo = (locMdlInfo)
#define _ssGetLocalMdlInfo(S) (S)->work.localMdlInfo /*   (_ssLocalMdlInfo*)    */

#if !SS_SFCN
#define ssSetLocalMdlInfo(S, locMdlInfo) _ssSetLocalMdlInfo(S, locMdlInfo)
#else
#define ssSetLocalMdlInfo(S, locMdlInfo) ssSetLocalMdlInfo_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetLocalMdlInfo(S) _ssGetLocalMdlInfo(S)
#else
#define ssGetLocalMdlInfo(S) ssGetLocalMdlInfo_cannot_be_used_in_SFunctions
#endif

/* OwnerBd - Internal use only
 * This is a void pointer to the owning block diagram.
 */
#define _ssSetOwnerBd(S, bd) (S)->work.localMdlInfo->ownerBd = ((void*)bd)
#define _ssGetOwnerBd(S) (S)->work.localMdlInfo->ownerBd /*   (void*)    */

#if !SS_SFCN
#define ssSetOwnerBd(S, bd) _ssSetOwnerBd(S, bd)
#else
#define ssSetOwnerBd(S, bd) ssSetOwnerBd_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetOwnerBd(S) _ssGetOwnerBd(S)
#else
#define ssGetOwnerBd(S) ssGetOwnerBd_cannot_be_used_in_SFunctions
#endif

/* CompBd - Internal use only
 * This is a void pointer to the owning compiled block diagram.
 */
#define _ssSetOwnerCbd(S, cbd) (S)->work.localMdlInfo->ownerCbd = ((void*)cbd)
#define _ssGetOwnerCbd(S) \
    ((S)->parent ? (S)->parent->work.localMdlInfo->ownerCbd : (S)->work.localMdlInfo->ownerCbd)

#if !SS_SFCN
#define ssSetOwnerCbd(S, cbd) _ssSetOwnerCbd(S, cbd)
#else
#define ssSetOwnerCbd(S, cbd) ssSetOwnerCbd_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetOwnerCbd(S) _ssGetOwnerCbd(S)
#else
#define ssGetOwnerCbd(S) ssGetOwnerCbd_cannot_be_used_in_SFunctions
#endif


/* ExecBd - Internal use only
* This is a void pointer to the owning Exec block diagram. Since there can be
   multiple ExecBds corresponding to one SimStruct, it will be swapped appropriately.
*/
#define _ssSetOwnerEbd(S, ebd) (S)->work.localMdlInfo->ownerEbd = ((void*)ebd)
#define _ssGetOwnerEbd(S) \
    ((S)->parent ? (S)->parent->work.localMdlInfo->ownerEbd : (S)->work.localMdlInfo->ownerEbd)

#if !SS_SFCN
#define ssSetOwnerEbd(S, ebd) _ssSetOwnerEbd(S, ebd)
#else
#define ssSetOwnerEbd(S, cbd) ssSetOwnerEbd_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetOwnerEbd(S) _ssGetOwnerEbd(S)
#else
#define ssGetOwnerEbd(S) ssGetOwnerEbd_cannot_be_used_in_SFunctions
#endif

/* ExecSimStructManager - Internal use only
 * This is a void pointer to the ExecSimStructManager. This
 * manager class is used to store exec SimStruct related information
 */
#define _ssSetExecSimStructMgr(S, mgr) (S)->work.localMdlInfo->execSimStructMgr = ((void*)mgr)
#define _ssGetExecSimStructMgr(S) (S)->work.localMdlInfo->execSimStructMgr

#if !SS_SFCN
#define ssSetExecSimStructMgr(S, mgr) _ssSetExecSimStructMgr(S, mgr)
#else
#define ssSetExecSimStructMgr(S, ebd) ssSetExecSimStructMgr_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetExecSimStructMgr(S) _ssGetExecSimStructMgr(S)
#else
#define ssGetExecSimStructMgr(S) ssGetExecSimStructMgr_cannot_be_used_in_SFunctions
#endif

/* Model RTP - Internal use only
 * This is a void pointer to the RTP of a model.
 */
#define _ssSetModelRtp(S, ptr) (S)->work.localMdlInfo->rtp = (ptr)
#define _ssGetModelRtp(S) (S)->work.localMdlInfo->rtp /*   (real_T*)    */
#if !SS_SFCN
#define ssSetModelRtp(S, ptr) _ssSetModelRtp(S, ptr)
#else
#define ssSetModelRtp(S, ptr) ssSetModelRtp_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetModelRtp(S) _ssGetModelRtp(S)
#else
#define ssGetModelRtp(S) ssGetModelRtp_cannot_be_used_in_SFunctions
#endif

/* Model BlockIO - Internal use only
 * This is a void pointer to the BlockIO of a model.
 */
#define _ssSetModelBlockIO(S, ptr) (S)->work.localMdlInfo->blockIO = ((void*)(ptr))
#define _ssGetModelBlockIO(S) ((void*)((S)->work.localMdlInfo->blockIO)) /*   (void*)    */
#if !SS_SFCN
#define ssSetModelBlockIO(S, ptr) _ssSetModelBlockIO(S, ptr)
#define ssGetModelBlockIO(S) _ssGetModelBlockIO(S)
#else
#define ssSetModelBlockIO(S, ptr) ssSetModelBlockIO_cannot_be_used_in_SFunctions
#define ssGetModelBlockIO(S) ssGetModelBlockIO_cannot_be_used_in_SFunctions
#endif

/*  - Internal use only
 * This is a uint_T pointer to the NumRuntimeEvents of a model.
 */
#define _ssSetNumRuntimeEventsPtr(S, ptr) (S)->work.localMdlInfo->numRuntimeEvents = (ptr)
#define _ssGetNumRuntimeEventsPtr(S) (S)->work.localMdlInfo->numRuntimeEvents /*   (uint_T*)    */
#if !SS_SFCN
#define ssSetNumRuntimeEventsPtr(S, ptr) _ssSetNumRuntimeEventsPtr(S, ptr)
#else
#define ssSetNumRuntimeEventsPtr(S, ptr) ssSet_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetNumRuntimeEventsPtr(S) _ssGetNumRuntimeEventsPtr(S)
#else
#define ssGetNumRuntimeEventsPtr(S) ssGet_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is uint_T value of the NumRuntimeEvents of a model.
 */
#define _ssSetNumRuntimeEvents(S, num) *(S)->work.localMdlInfo->numRuntimeEvents = (num)
#define _ssGetNumRuntimeEvents(S) *(S)->work.localMdlInfo->numRuntimeEvents /*   (uint_T)    */
#if !SS_SFCN
#define ssSetNumRuntimeEvents(S, num) _ssSetNumRuntimeEvents(S, num)
#else
#define ssSetNumRuntimeEvents(S, num) ssSetNumRuntimeEvents_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetNumRuntimeEvents(S) _ssGetNumRuntimeEvents(S)
#else
#define ssGetNumRuntimeEvents(S) ssGetNumRuntimeEvents_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is a uint_T pointer to the GlobalRuntimeEventIndices of a model.
 */
#define _ssSetGlobalRuntimeEventIndices(S, ptr) \
    (S)->work.localMdlInfo->globalRuntimeEventIndices = (ptr)
#define _ssGetGlobalRuntimeEventIndices(S) \
    (S)->work.localMdlInfo->globalRuntimeEventIndices /*   (uint_T*)    */
#if !SS_SFCN
#define ssSetGlobalRuntimeEventIndices(S, ptr) _ssSetGlobalRuntimeEventIndices(S, ptr)
#else
#define ssSetGlobalRuntimeEventIndices(S, ptr) \
    ssSetGlobalRuntimeEventIndices_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetGlobalRuntimeEventIndices(S) _ssGetGlobalRuntimeEventIndices(S)
#else
#define ssGetGlobalRuntimeEventIndices(S) \
    ssGetGlobalRuntimeEventIndices_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is a uint_T GlobalRuntimeEventIndex corresponding to localIndex of a model.
 */
#define _ssSetGlobalRuntimeEventIndex(S, localIndex, globalIndex)                        \
    if ((S)->work.localMdlInfo != NULL) {                                                \
        (S)->work.localMdlInfo->globalRuntimeEventIndices[(localIndex)] = (globalIndex); \
    }
#define _ssGetGlobalRuntimeEventIndex(S, localIndex)                       \
    ((S)->work.localMdlInfo != NULL                                        \
         ? (S)->work.localMdlInfo->globalRuntimeEventIndices[(localIndex)] \
         : (localIndex)) /*   (uint_T)    */
#if !SS_SFCN
#define ssSetGlobalRuntimeEventIndex(S, localIndex, globalIndex) \
    _ssSetGlobalRuntimeEventIndex(S, localIndex, globalIndex)
#else
#define ssSetGlobalRuntimeEventIndex(S, localIndex, globalIndex) \
    ssSetGlobalRuntimeEventIndex_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetGlobalRuntimeEventIndex(S, localIndex) _ssGetGlobalRuntimeEventIndex(S, localIndex)
#else
#define ssGetGlobalRuntimeEventIndex(S, localIndex) \
    ssGetGlobalRuntimeEventIndex_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is a uint_T pointer to the NumTimers of a model.
 */
#define _ssSetNumTimersPtr(S, ptr) (S)->work.localMdlInfo->numTimers = (ptr)
#define _ssGetNumTimersPtr(S) (S)->work.localMdlInfo->numTimers /*   (uint_T*)    */
#if !SS_SFCN
#define ssSetNumTimersPtr(S, ptr) _ssSetNumTimersPtr(S, ptr)
#else
#define ssSetNumTimersPtr(S, ptr) ssSet_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetNumTimersPtr(S) _ssGetNumTimersPtr(S)
#else
#define ssGetNumTimersPtr(S) ssGet_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is uint_T value of the NumTimers of a model.
 */
#define _ssSetNumTimers(S, num) *(S)->work.localMdlInfo->numTimers = (num)
#define _ssGetNumTimers(S) *(S)->work.localMdlInfo->numTimers /*   (uint_T)    */
#if !SS_SFCN
#define ssSetNumTimers(S, num) _ssSetNumTimers(S, num)
#else
#define ssSetNumTimers(S, num) ssSetNumTimers_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetNumTimers(S) _ssGetNumTimers(S)
#else
#define ssGetNumTimers(S) ssGetNumTimers_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is a uint_T pointer to the GlobalTimerIndices of a model.
 */
#define _ssSetGlobalTimerIndices(S, ptr) (S)->work.localMdlInfo->globalTimerIndices = (ptr)
#define _ssGetGlobalTimerIndices(S) (S)->work.localMdlInfo->globalTimerIndices /*   (uint_T*) */
#if !SS_SFCN
#define ssSetGlobalTimerIndices(S, ptr) _ssSetGlobalTimerIndices(S, ptr)
#else
#define ssSetGlobalTimerIndices(S, ptr) ssSetGlobalTimerIndices_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetGlobalTimerIndices(S) _ssGetGlobalTimerIndices(S)
#else
#define ssGetGlobalTimerIndices(S) ssGetGlobalTimerIndices_cannot_be_used_in_SFunctions
#endif


/*  - Internal use only
 * This is a uint_T GlobalTimerIndex corresponding to localIndex of a model.
 */
#define _ssSetGlobalTimerIndex(S, localIndex, globalIndex)                        \
    if ((S)->work.localMdlInfo != NULL) {                                         \
        (S)->work.localMdlInfo->globalTimerIndices[(localIndex)] = (globalIndex); \
    }
#define _ssGetGlobalTimerIndex(S, localIndex)                                                  \
    ((S)->work.localMdlInfo != NULL ? (S)->work.localMdlInfo->globalTimerIndices[(localIndex)] \
                                    : (localIndex)) /*   (uint_T)    */
#if !SS_SFCN
#define ssSetGlobalTimerIndex(S, localIndex, globalIndex) \
    _ssSetGlobalTimerIndex(S, localIndex, globalIndex)
#else
#define ssSetGlobalTimerIndex(S, localIndex, globalIndex) \
    ssSetGlobalTimerIndex_cannot_be_used_in_SFunctions
#endif
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetGlobalTimerIndex(S, localIndex) _ssGetGlobalTimerIndex(S, localIndex)
#else
#define ssGetGlobalTimerIndex(S, localIndex) ssGetGlobalTimerIndex_cannot_be_used_in_SFunctions
#endif


/* Model BlockIOVarDims - Internal use only
 * This is a void pointer to the BlockIOVarDims of a model.
 *
 * No one uses this.
 *
 * It is noted here as the corresponding BlockIOVarDims field still exits
 * in _ssMdlInfo
 */

/*-------------------------------- S->blkInfo -------------------------------*/

/* InputConnected - True/false are any inputs to the S-function connected
 *   to non-virtual blocks?
 */
#if SS_SFCN_LEVEL_1 || SS_SL_INTERNAL
#define ssGetInputConnected(S) (S)->blkInfo.inputConnected /* (int_T)      */
#define _ssSetInputConnected(S, setting) (S)->blkInfo.inputConnected = (setting)
#else
#define ssGetInputConnected(S) ssGetInputConnected_cannot_be_used_in_Level2_SFunctions
#endif

#if !SS_SFCN
#define ssSetInputConnected(S, setting) _ssSetInputConnected(S, setting)
#else
#define ssSetInputConnected(S, setting) ssSetInputConnected_cannot_be_used_in_SFunctions
#endif


/* OutputConnected - True/false are any outputs of the S-function connected
 *   to non-virtual blocks?
 */
#define ssGetOutputConnected(S) (S)->blkInfo.outputConnected /* (int_T)      */
#define _ssSetOutputConnected(S, setting) (S)->blkInfo.outputConnected = (setting)
#if !SS_SFCN
#define ssSetOutputConnected(S, setting) _ssSetOutputConnected(S, setting)
#else
#define ssSetOutputConnected(S, setting) ssSetOutputConnected_cannot_be_used_in_SFunctions
#endif



/*----------------------------------------------------------------------------*/


#define ssSetBlkInfo2Ptr(S, ptr) (S)->blkInfo.blkInfo2 = (ptr)
#define ssGetBlkInfo2Ptr(S) (S)->blkInfo.blkInfo2
#define ssSetBlkInfoSLSizePtr(S, ptr) (S)->blkInfo.blkInfo2->blkInfoSLSize = (ptr)
#define ssGetBlkInfoSLSizePtr(S, ptr) (S)->blkInfo.blkInfo2->blkInfoSLSize
#define ssSetRTWSfcnInfo(S, ptr) ((S)->blkInfo.blkInfo2)->rtwSfcnInfo = ((void*)ptr)
#define ssGetRTWSfcnInfo(S) ((S)->blkInfo.blkInfo2)->rtwSfcnInfo

/* Impulse Response Length - Integer impulse response length of a
 * block. Currently, it is used only in the dataflow domain.
 */

/**
 * @brief  ssSetImpulseResponseLength
 *
 * Call this in mdlInitializeSizes or mdlSetWorkWidths callback to set the
 * impulse response length during pre-compile or post-propagation stage,
 * respectively.
 *
 * Specify impulse response length of the block.
 * @param    S             SimStruct representing an S-Function block.
 * @param    val           An int_T value specifying the impulse response length of S-Function block
 * S.
 */
#define ssSetImpulseResponseLength(S, val) ((S)->blkInfo.blkInfo2)->impulseResponseLength = (val)

/**
 * @brief  ssGetImpulseResponseLength
 *
 * Get impulse response length of the block.
 * @param    S             SimStruct representing an S-Function block.
 * @return   An int_T value indicating the impulse response length of the S-Function block S.
 */
#define ssGetImpulseResponseLength(S) ((S)->blkInfo.blkInfo2)->impulseResponseLength /* (int_T) */

/*-------------------------------- S->mdlInfo -------------------------------*/
#define ssGetMdlInfoPtr(S) (S)->mdlInfo /* (struct _ssMdlInfo *) */
#define _ssSetMdlInfoPtr(S, ptr) (S)->mdlInfo = (ptr)
#if !SS_SFCN
#define ssSetMdlInfoPtr(S, ptr) _ssSetMdlInfoPtr(S, ptr)
#else
#define ssSetMdlInfoPtr(S, ptr) ssSetMdlInfoPtr_cannot_be_used_in_SFunctions
#endif


#define _ssSetSimMode(S, mode) (S)->mdlInfo->simMode = (mode)
#if !SS_SFCN
#define ssSetSimMode(S, mode) _ssSetSimMode(S, mode)
#else
#define ssSetSimMode(S, mode) ssSetSimMode_cannot_be_used_in_SFunctions
#endif



#define ssGetRTWCGSupport(S, result)                                               \
    {                                                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_RTWCG_SUPPORT, 0, result) \
            _ssSafelyCallGenericFcnEnd;                                            \
    }

#define ssSetStateAttr(S, pMxa)                                               \
    {                                                                         \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_STATE_ATTR, 0, pMxa) \
            _ssSafelyCallGenericFcnEnd;                                       \
    }

#define ssGetStateAttr(S, ppMxa)                                               \
    {                                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_STATE_ATTR, 0, ppMxa) \
            _ssSafelyCallGenericFcnEnd;                                        \
    }



#if !SS_SFCN && SS_SIM
#define ssSetRTWGenMode(S, mode) (S)->mdlInfo->rtwgenMode = (mode)
#define ssGetRTWGenMode(S) ((S)->mdlInfo->rtwgenMode)
#endif


#define ssGetTPtr(S) (S)->mdlInfo->t /*   (time_T *)    */
#define _ssSetTPtr(S, t_ptr) (S)->mdlInfo->t = (t_ptr)

#if !SS_SFCN
#define ssSetTPtr(S, t_ptr) _ssSetTPtr(S, t_ptr)
#else
#define ssSetTPtr(S, t_ptr) ssSetTPtr_cannot_be_used_in_SFunctions
#endif


#define _ssSetT(S, time) (S)->mdlInfo->t[0] = (time)

#if !SS_SFCN
#define ssSetT(S, time) _ssSetT(S, time)
#else
#define ssSetT(S, time) ssSetT_cannot_be_used_in_SFunctions
#endif


#define _ssSetTaskTime(S, sti, time) (S)->mdlInfo->t[sti] = (time)

#if !SS_SFCN
#define ssSetTaskTime(S, sti, time) _ssSetTaskTime(S, sti, time)
#else
#define ssSetTaskTime(S, sti, time) ssSetTaskTime_cannot_be_used_in_SFunctions
#endif

#define _ssSetSampleHit(S, sti, v) (S)->mdlInfo->sampleHits[sti] = (v)
#define _ssSetSampleHitPtr(S, ptr) (S)->mdlInfo->sampleHits = (ptr)

#if !SS_SFCN
#define ssSetSampleHitPtr(S, ptr) _ssSetSampleHitPtr(S, ptr)
#else
#define ssSetSampleHitPtr(S, ptr) ssSetSampleHitPtr_cannot_be_used_in_SFunctions
#endif


#define _ssSetTStart(S, tstart) (S)->mdlInfo->tStart = (tstart)
#if !SS_SFCN
#define ssSetTStart(S, tstart) _ssSetTStart(S, tstart)
#else
#define ssSetTStart(S, tstart) ssSetTStart_cannot_be_used_in_SFunctions
#endif


#define _ssSetTFinal(S, tfinal) (S)->mdlInfo->tFinal = (tfinal)
#if !SS_SFCN
#define ssSetTFinal(S, tfinal) _ssSetTFinal(S, tfinal)
#else
#define ssSetTFinal(S, tfinal) ssSetTFinal_cannot_be_used_in_SFunctions
#endif

/* TimeOfLastOutput - This is reserved for use by RTW and Simulink. However,
 *   S-function can look at this within their continuous task. It is
 *   the time of the last output for the model - not the s-function
 *   itself.
 */
#define ssGetTimeOfLastOutput(S) (S)->mdlInfo->timeOfLastOutput /*   (time_T)      */
#define _ssSetTimeOfLastOutput(S, tlast) (S)->mdlInfo->timeOfLastOutput = (tlast)
#if !SS_SFCN
#define ssSetTimeOfLastOutput(S, tlast) _ssSetTimeOfLastOutput(S, tlast)
#else
#define ssSetTimeOfLastOutput(S, tlast) ssSetTimeOfLastOutput_cannot_be_used_in_SFunctions
#endif

#define _ssGetTimingData(S) (S)->mdlInfo->timingData /*   (void *)      */
#if !SS_SFCN
#define ssGetTimingData(S) _ssGetTimingData(S)
#else
#define ssGetTimingData(S) ssGetTimingData_cannot_be_used_in_SFunctions
#endif
#define _ssSetTimingData(S, d) (S)->mdlInfo->timingData = (d)
#if !SS_SFCN
#define ssSetTimingData(S, d) _ssSetTimingData(S, d)
#else
#define ssSetTimingData(S, d) ssSetTimingData_cannot_be_used_in_SFunctions
#endif

/*
 * TimingBridge is introduced in R14. This provides access to the timing
 * information which is stored in different data structures in Simulink
 * and the various RTW code formats.
 */
#define ssGetTimingBridge(S) ((S)->mdlInfo->timingBridge)
#if !SS_SFCN
#define ssSetTimingBridge(S, d) (S)->mdlInfo->timingBridge = (d)
#else
#define ssSetTimingBridge(S, d) ssSetTimingBridge_cannot_be_used_in_SFunctions
#endif


#define ssGetClockTick(S, sti) \
    (*((S)->mdlInfo->timingBridge->clockTick[ssGetSampleTimeTaskID(S, sti)]))

#define ssGetClockTickH(S, sti) \
    (*((S)->mdlInfo->timingBridge->clockTickH[ssGetSampleTimeTaskID(S, sti)]))


#define ssGetSimTimeStep(S) (S)->mdlInfo->simTimeStep /*  (SimTimeStep)  */
#define _ssSetSimTimeStep(S, stepType) (S)->mdlInfo->simTimeStep = (stepType)
#if !SS_SFCN
#define ssSetSimTimeStep(S, stepType) _ssSetSimTimeStep(S, stepType)
#else
#define ssSetSimTimeStep(S, stepType) ssSetSimTimeStep_cannot_be_used_in_SFunctions
#endif


#define ssGetLogOutput(S) (S)->mdlInfo->logOutput /*    (int_T)  */
#define _ssSetLogOutput(S, setting) (S)->mdlInfo->logOutput = setting
#if !SS_SFCN
#define ssSetLogOutput(S, setting) _ssSetLogOutput(S, setting)
#else
#define ssSetLogOutput(S, setting) ssSetLogOutput_cannot_be_used_in_SFunctions
#endif

#define _ssGetOutputTimes(S) (S)->mdlInfo->outputTimes /*   (time_T*)     */
#if !SS_SFCN
#define ssGetOutputTimes(S) _ssGetOutputTimes(S)
#else
#define ssGetOutputTimes(S) ssGetOutputTimes_cannot_be_used_in_SFunctions
#endif
#define _ssSetOutputTimes(S, ptr) (S)->mdlInfo->outputTimes = (ptr)
#if !SS_SFCN
#define ssSetOutputTimes(S, ptr) _ssSetOutputTimes(S, ptr)
#else
#define ssSetOutputTimes(S, ptr) ssSetOutputTimes_cannot_be_used_in_SFunctions
#endif

#define _ssGetNextOutputTime(S) \
    (S)->mdlInfo->outputTimes[(S)->mdlInfo->outputTimesIndex] /*   (time_T)      */
#if !SS_SFCN
#define ssGetNextOutputTime(S) _ssGetNextOutputTime(S)
#else
#define ssGetNextOutputTime(S) ssGetNextOutputTime_cannot_be_used_in_SFunctions
#endif

#define _ssGetOutputTimesIndex(S) (S)->mdlInfo->outputTimesIndex /*   (int_T)       */
#if !SS_SFCN
#define ssGetOutputTimesIndex(S) _ssGetOutputTimesIndex(S)
#else
#define ssGetOutputTimesIndex(S) ssGetOutputTimesIndex_cannot_be_used_in_SFunctions
#endif
#define _ssSetOutputTimesIndex(S, index) (S)->mdlInfo->outputTimesIndex = (index)
#if !SS_SFCN
#define ssSetOutputTimesIndex(S, index) _ssSetOutputTimesIndex(S, index)
#else
#define ssSetOutputTimesIndex(S, index) ssSetOutputTimesIndex_cannot_be_used_in_SFunctions
#endif

#define _ssGetNumOutputTimes(S) (S)->mdlInfo->numOutputTimes /*   (int_T)       */
#if !SS_SFCN
#define ssGetNumOutputTimes(S) _ssGetNumOutputTimes(S)
#else
#define ssGetNumOutputTimes(S) ssGetNumOutputTimes_cannot_be_used_in_SFunctions
#endif
#define _ssSetNumOutputTimes(S, n) (S)->mdlInfo->numOutputTimes = (n)
#if !SS_SFCN
#define ssSetNumOutputTimes(S, n) _ssSetNumOutputTimes(S, n)
#else
#define ssSetNumOutputTimes(S, n) ssSetNumOutputTimes_cannot_be_used_in_SFunctions
#endif

#define _ssGetOutputTimesOnly(S) (S)->mdlInfo->outputTimesOnly /*   (int_T)   */
#if !SS_SFCN
#define ssGetOutputTimesOnly(S) _ssGetOutputTimesOnly(S)
#else
#define ssGetOutputTimesOnly(S) ssGetOutputTimesOnly_cannot_be_used_in_SFunctions
#endif
#define _ssSetOutputTimesOnly(S, setting) (S)->mdlInfo->outputTimesOnly = (setting)
#if !SS_SFCN
#define ssSetOutputTimesOnly(S, setting) _ssSetOutputTimesOnly(S, setting)
#else
#define ssSetOutputTimesOnly(S, setting) ssSetOutputTimesOnly_cannot_be_used_in_SFunctions
#endif

#define _ssGetNeedOutputAtTPlusTol(S) (S)->mdlInfo->obsoletedNeedOutputAtTPlusTol /*   (int_T) */
#if !SS_SFCN
#define ssGetNeedOutputAtTPlusTol(S) _ssGetNeedOutputAtTPlusTol(S)
#else
#define ssGetNeedOutputAtTPlusTol(S) ssGetNeedOutputAtTPlusTol_cannot_be_used_in_SFunctions
#endif


#define _ssSetSolverName(S, name) (S)->mdlInfo->solverName = (name)
#if !SS_SFCN
#define ssSetSolverName(S, name) _ssSetSolverName(S, name)
#else
#define ssSetSolverName(S, name) ssSetSolverName_cannot_be_used_in_SFunctions
#endif


#define _ssSetVariableStepSolver(S, s) (S)->mdlInfo->variableStepSolver = (s)
#if !SS_SFCN
#define ssSetVariableStepSolver(S, s) _ssSetVariableStepSolver(S, s)
#else
#define ssSetVariableStepSolver(S, s) ssSetVariableStepSolver_cannot_be_used_in_SFunctions
#endif

#define _ssGetSolverData(S) (S)->mdlInfo->solverData /*   (void *)      */
#if !SS_SFCN
#define ssGetSolverData(S) _ssGetSolverData(S)
#else
#define ssGetSolverData(S) ssGetSolverData_cannot_be_used_in_SFunctions
#endif
#define _ssSetSolverData(S, solverDataPtr) (S)->mdlInfo->solverData = (solverDataPtr)
#if !SS_SFCN
#define ssSetSolverData(S, solverDataPtr) _ssSetSolverData(S, solverDataPtr)
#else
#define ssSetSolverData(S, solverDataPtr) ssSetSolverData_cannot_be_used_in_SFunctions
#endif

#define ssGetSolverStopTime(S) (S)->mdlInfo->solverStopTime /*   (time_T)      */
#define _ssSetSolverStopTime(S, stoptime) (S)->mdlInfo->solverStopTime = (stoptime)
#if !SS_SFCN
#define ssSetSolverStopTime(S, stoptime) _ssSetSolverStopTime(S, stoptime)
#else
#define ssSetSolverStopTime(S, stoptime) ssSetSolverStopTime_cannot_be_used_in_SFunctions
#endif

#define ssGetStepSize(S) (S)->mdlInfo->stepSize /*   (time_T)      */
#define _ssSetStepSize(S, size) (S)->mdlInfo->stepSize = (size)
#if !SS_SFCN
#define ssSetStepSize(S, size) _ssSetStepSize(S, size)
#else
#define ssSetStepSize(S, size) ssSetStepSize_cannot_be_used_in_SFunctions
#endif

#define ssGetSolverNeedsReset(S) (S)->mdlInfo->solverNeedsReset /*  (int_T)    */
#define ssSetSolverNeedsResetWithReason(S, resetReason) \
    (S)->mdlInfo->solverNeedsReset = ((S)->mdlInfo->solverNeedsReset | resetReason)
#define _ssClearSolverNeedsReset(S) (S)->mdlInfo->solverNeedsReset = ((int_T)0)

#if !SS_SFCN
#define ssClearSolverNeedsReset(S) _ssClearSolverNeedsReset(S)
#else
#define ssClearSolverNeedsReset(S) ssClearSolverNeedsReset_cannot_be_used_in_SFunctions
#endif

#define ssIsSolverRequestingReset(S) ((S)->mdlInfo->mdlFlags.solverRequestingReset == 1U)
#define _ssSetSolverRequestingReset(S, boolVal) \
    (S)->mdlInfo->mdlFlags.solverRequestingReset = ((boolVal) ? 1U : 0U)
#if !SS_SFCN
#define ssSetSolverRequestingReset(S, boolVal) _ssSetSolverRequestingReset(S, boolVal)
#else
#define ssSetSolverRequestingReset(S, boolVal) \
    ssSetSolverRequestingReset_cannot_be_used_in_SFunctions
#endif

#define ssIsSolverCheckingCIC(S) ((S)->mdlInfo->mdlFlags.solverCheckingCIC == 1U)
#define _ssSetSolverCheckingCIC(S, boolVal) \
    (S)->mdlInfo->mdlFlags.solverCheckingCIC = ((boolVal) ? 1U : 0U)
#if !SS_SFCN
#define ssSetSolverCheckingCIC(S, boolVal) _ssSetSolverCheckingCIC(S, boolVal)
#else
#define ssSetSolverCheckingCIC(S, boolVal) ssSetSolverCheckingCIC_cannot_be_used_in_SFunctions
#endif


#define ssGetZCCacheNeedsReset(S) (S)->mdlInfo->mdlFlags.zcCacheNeedsReset /*  (uint_T)    */
#define ssSetZCCacheNeedsReset(S, setting) (S)->mdlInfo->mdlFlags.zcCacheNeedsReset = (setting)

#define ssGetDerivCacheNeedsReset(S) (S)->mdlInfo->mdlFlags.derivCacheNeedsReset /*  (uint_T) */
#define ssSetDerivCacheNeedsReset(S, setting) \
    (S)->mdlInfo->mdlFlags.derivCacheNeedsReset = (setting)

#define _ssGetForceSfcnExceptionHandling(S) \
    ((S)->mdlInfo->mdlFlags.forceSfcnExceptionHandling == 1U)
#define _ssSetForceSfcnExceptionHandling(S, boolVal) \
    (S)->mdlInfo->mdlFlags.forceSfcnExceptionHandling = ((boolVal) ? 1U : 0U)

#define ssIsComputingJacobian(S) ((S)->mdlInfo->mdlFlags.computingJacobian == 1U)
#define _ssSetComputingJacobian(S, boolVal) \
    (S)->mdlInfo->mdlFlags.computingJacobian = ((boolVal) ? 1U : 0U)

#define ssGetEvaluatingF0ForJacobian(S) (S)->mdlInfo->mdlFlags.f0EvaluationForJacobian
#define _ssSetEvaluatingF0ForJacobian(S, val) (S)->mdlInfo->mdlFlags.f0EvaluationForJacobian = val
#define _ssClearEvaluatingF0ForJacobian(S) (S)->mdlInfo->mdlFlags.f0EvaluationForJacobian = 0

#if (!SS_SFCN || defined(RTW_GENERATED_S_FUNCTION))
#define ssGetIsZCEvaluationForRefine(S) ((S)->mdlInfo->mdlFlags.zcEvalForRefine == 1U)
#define _ssSetIsZCEvaluationForRefine(S, val) (S)->mdlInfo->mdlFlags.zcEvalForRefine = val
#define _ssClearIsZCEvaluationForRefine(S) (S)->mdlInfo->mdlFlags.zcEvalForRefine = 0U
#endif

#define ssIsSolverComputingJacobian(S) ssIsComputingJacobian(S)

#if !SS_SFCN
#define ssSetComputingJacobian(S, boolVal) _ssSetComputingJacobian(S, boolVal)
#else
#define ssSetComputingJacobian(S, boolVal) ssSetComputingJacobian_cannot_be_used_in_SFunctions
#endif

#define ssIsSparseSlvrJacobian(S) ((S)->mdlInfo->mdlFlags.sparseSlvrJacobian == 1U)
#define _ssSetSparseSlvrJacobian(S, boolVal) \
    (S)->mdlInfo->mdlFlags.sparseSlvrJacobian = ((boolVal) ? 1U : 0U)
#if !SS_SFCN
#define ssSetSparseSlvrJacobian(S, boolVal) _ssSetSparseSlvrJacobian(S, boolVal)
#else
#define ssSetSparseSlvrJacobian(S, boolVal) ssSetSparseSlvrJacobian_cannot_be_used_in_SFunctions
#endif

#define ssIsOutputMethodComputed(S) ((S)->mdlInfo->mdlFlags.outputMethodComputed == 1U)
#define _ssSetOutputMethodComputed(S, boolVal) \
    (S)->mdlInfo->mdlFlags.outputMethodComputed = ((boolVal) ? 1U : 0U)
#define ssIsSolverOutputMethodComputed(S) ssIsOutputMethodComputed(S)

#if !SS_SFCN
#define ssSetOutputMethodComputed(S, boolVal) _ssSetOutputMethodComputed(S, boolVal)
#else
#define ssSetOutputMethodComputed(S, boolVal) ssSetOutputMethodComputed_cannot_be_used_in_SFunctions
#endif


#define ssGetInlineParameters(S) ((S)->mdlInfo->mdlFlags.inlineParameters == 1U)
#define _ssSetInlineParameters(S, boolVal) \
    (S)->mdlInfo->mdlFlags.inlineParameters = ((boolVal) ? 1U : 0U)

#define ssGetDoingParameterInit(S) ((S)->mdlInfo->mdlFlags.doingParameterInit == 1U)
#define ssSetDoingParameterInit(S, boolVal) \
    (S)->mdlInfo->mdlFlags.doingParameterInit = ((boolVal) ? 1U : 0U)

#if !SS_SFCN
#define ssSetInlineParameters(S, boolVal) _ssSetInlineParameters(S, boolVal)
#else
#define ssSetInlineParameters(S, boolVal) ssSetInlineParameters_cannot_be_used_in_SFunctions
#endif

/*
 * Only needed for accelerator mode simulation.
 */
#define ssSetReinitializeEventBeingProcessed(S, reinitId)                                 \
    {                                                                                     \
                                                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_MODEL_WIDE_EVENT_BEING_PROCESSED, 0, \
                                        reinitId) _ssSafelyCallGenericFcnEnd;             \
    }

/* solver assert check to be used by accelerator only */
#define _ssGetSolverAssertCheck(S) ((S)->mdlInfo->mdlFlags.solverAssertCheck == 1U)
#define _ssSetSolverAssertCheck(S, boolVal) \
    (S)->mdlInfo->mdlFlags.solverAssertCheck = ((boolVal) ? 1U : 0U)

#define ssGetBlkStateChange(S) (S)->mdlInfo->mdlFlags.blkStateChange /*  (uint_T)    */
#define ssSetBlkStateChange(S) (S)->mdlInfo->mdlFlags.blkStateChange = 1U
#define ssClearBlkStateChange(S) (S)->mdlInfo->mdlFlags.blkStateChange = 0U

#define ssSetIsMinorTimeStepWithModeChange(S) \
    (S)->mdlInfo->solverInfo->isMinorTimeStepWithModeChange = 1U
#define ssClearIsMinorTimeStepWithModeChange(S) \
    (S)->mdlInfo->solverInfo->isMinorTimeStepWithModeChange = 0U


#define ssGetContTimeOutputInconsistentWithStateAtMajorStep(S) \
    (S)->mdlInfo->mdlFlags.cTimeOutputInconsistentWithStateAtMajorStep

#if (!SS_SFCN || defined(RTW_GENERATED_S_FUNCTION))
#define ssClearContTimeOutputInconsistentWithStateAtMajorStep(S) \
    (S)->mdlInfo->mdlFlags.cTimeOutputInconsistentWithStateAtMajorStep = 0U
#endif

#define ssGetBlockStateForSolverChangedAtMajorStep(S) \
    (S)->mdlInfo->mdlFlags.blockStateForSolverChangedAtMajorStep

#if (!SS_SFCN || defined(RTW_GENERATED_S_FUNCTION))
#define ssClearBlockStateForSolverChangedAtMajorStep(S) \
    (S)->mdlInfo->mdlFlags.blockStateForSolverChangedAtMajorStep = 0U
#endif

#define ssGetSolverRefineFactor(S) (S)->mdlInfo->solverRefineFactor /*   (int_T)       */
#define _ssSetSolverRefineFactor(S, fact) (S)->mdlInfo->solverRefineFactor = (fact)
#if !SS_SFCN
#define ssSetSolverRefineFactor(S, fact) _ssSetSolverRefineFactor(S, fact)
#else
#define ssSetSolverRefineFactor(S, fact) ssSetSolverRefineFactor_cannot_be_used_in_SFunctions
#endif

#define ssGetSolverRelTol(S) (S)->mdlInfo->solverRelTol /*   (real_T)      */
#define _ssSetSolverRelTol(S, rtol) (S)->mdlInfo->solverRelTol = (rtol)
#if !SS_SFCN
#define ssSetSolverRelTol(S, rtol) _ssSetSolverRelTol(S, rtol)
#else
#define ssSetSolverRelTol(S, rtol) ssSetSolverRelTol_cannot_be_used_in_SFunctions
#endif

#define ssGetSolverMaxOrder(S) (S)->mdlInfo->solverMaxOrder /*   (int_T)       */
#define _ssSetSolverMaxOrder(S, maxOrder) (S)->mdlInfo->solverMaxOrder = (maxOrder)
#if !SS_SFCN
#define ssSetSolverMaxOrder(S, maxOrder) _ssSetSolverMaxOrder(S, maxOrder)
#else
#define ssSetSolverMaxOrder(S, maxOrder) ssSetSolverMaxOrder_cannot_be_used_in_SFunctions
#endif

#define ssGetSolverExtrapolationOrder(S) \
    (S)->mdlInfo->solverExtrapolationOrder /*    (int_T)       */
#define _ssSetSolverExtrapolationOrder(S, extrapOrder) \
    (S)->mdlInfo->solverExtrapolationOrder = (extrapOrder)
#if !SS_SFCN
#define ssSetSolverExtrapolationOrder(S, extrapOrder) _ssSetSolverExtrapolationOrder(S, extrapOrder)
#else
#define ssSetSolverExtrapolationOrder(S, extrapOrder) \
    ssSetSolverExtrapolationOrder_cannot_be_used_in_SFunctions
#endif

#define ssGetSolverNumberNewtonIterations(S) \
    (S)->mdlInfo->solverNumberNewtonIterations /*    (int_T)   */
#define _ssSetSolverNumberNewtonIterations(S, numIter) \
    (S)->mdlInfo->solverNumberNewtonIterations = (numIter)
#if !SS_SFCN
#define ssSetSolverNumberNewtonIterations(S, numIter) _ssSetSolverNumberNewtonIterations(S, numIter)
#else
#define ssSetSolverNumberNewtonIterations(S, numIter) \
    ssSetSolverNumberNewtonIterations_cannot_be_used_in_SFunctions
#endif

#define ssGetMaxZcBracketingIterations(S) \
    (S)->mdlInfo->solverInfo->maxZcBracketingIterations /*    (int_T)   */
#define _ssSetMaxZcBracketingIterations(S, numZc) \
    (S)->mdlInfo->solverInfo->maxZcBracketingIterations = (numZc)
#if !SS_SFCN
#define ssSetMaxZcBracketingIterations(S, numZc) _ssSetMaxZcBracketingIterations(S, numZc)
#else
#define ssSetMaxZcBracketingIterations(S, numIter) \
    ssSetMaxZcBracketingIterations_cannot_be_used_in_SFunctions
#endif


#define ssGetMaxZcPerStep(S) (S)->mdlInfo->solverInfo->maxZcPerStep /*    (int_T)   */
#define _ssSetMaxZcPerStep(S, numZc) (S)->mdlInfo->solverInfo->maxZcPerStep = (numZc)
#if !SS_SFCN
#define ssSetMaxZcPerStep(S, numZc) _ssSetMaxZcPerStep(S, numZc)
#else
#define ssSetMaxZcPerStep(S, numIter) ssSetMaxZcPerStep_cannot_be_used_in_SFunctions
#endif



#define _ssSetSolverMode(S, mode) (S)->mdlInfo->solverMode = (mode)

#if !SS_SFCN
#define ssSetSolverMode(S, mode) _ssSetSolverMode(S, mode)
#else
#define ssSetSolverMode(S, mode) ssSetSolverMode_cannot_be_used_in_SFunctions
#endif


#define ssGetMaxStepSize(S) (S)->mdlInfo->maxStepSize /*   (time_T)      */
#define _ssSetMaxStepSize(S, size) (S)->mdlInfo->maxStepSize = (size)
#if !SS_SFCN
#define ssSetMaxStepSize(S, size) _ssSetMaxStepSize(S, size)
#else
#define ssSetMaxStepSize(S, size) ssSetMaxStepSize_cannot_be_used_in_SFunctions
#endif

#define ssGetMinStepSize(S) (S)->mdlInfo->minStepSize /*   (time_T)      */
#define _ssSetMinStepSize(S, size) (S)->mdlInfo->minStepSize = (size)
#if !SS_SFCN
#define ssSetMinStepSize(S, size) _ssSetMinStepSize(S, size)
#else
#define ssSetMinStepSize(S, size) ssSetMinStepSize_cannot_be_used_in_SFunctions
#endif

#define ssGetMinStepViolatedError(S) ((S)->mdlInfo->mdlFlags.minStepViolatedError == 1U)
#define _ssSetMinStepViolatedError(S, val) \
    (S)->mdlInfo->mdlFlags.minStepViolatedError = (val) ? 1U : 0U;

#if !SS_SFCN
#define ssSetMinStepViolatedError(S, val) _ssSetMinStepViolatedError(S, val)
#else
#define ssSetMinStepViolatedError(S, val) ssSetMinStepViolatedError_cannot_be_used_in_SFunctions
#endif

#define ssGetConsecutiveZCsError(S) (ssGetSolverConsecutiveZCsError(S) == 2)
#define _ssSetConsecutiveZCsError(S, val) ssSetSolverConsecutiveZCsError(S, val + 1)
#if !SS_SFCN
#define ssSetConsecutiveZCsError(S, val) _ssSetConsecutiveZCsError(S, val)
#else
#define ssSetConsecutiveZCsError(S, val) ssSetConsecutiveZCsError_cannot_be_used_in_SFunctions
#endif

#define ssGetMaxNumMinSteps(S) (S)->mdlInfo->maxNumMinSteps /*   (in_T)        */
#define _ssSetMaxNumMinSteps(S, num) (S)->mdlInfo->maxNumMinSteps = (num)
#if !SS_SFCN
#define ssSetMaxNumMinSteps(S, num) _ssSetMaxNumMinSteps(S, num)
#else
#define ssSetMaxNumMinSteps(S, min) ssSetMaxNumMinSteps_cannot_be_used_in_SFunctions
#endif



#define _ssSetFixedStepSize(S, size) (S)->mdlInfo->fixedStepSize = (size)
#if !SS_SFCN
#define ssSetFixedStepSize(S, size) _ssSetFixedStepSize(S, size)
#else
#define ssSetFixedStepSize(S, size) ssSetFixedStepSize_cannot_be_used_in_SFunctions
#endif

#if SS_MULTITASKING || SS_SL_INTERNAL || SS_SFCN_FOR_SIM



#define _ssSetPerTaskSampleHitsPtr(S, hitsMatrix) (S)->mdlInfo->perTaskSampleHits = (hitsMatrix)

#if !SS_SFCN
#define ssSetPerTaskSampleHitsPtr(S, hitsMatrix) _ssSetPerTaskSampleHitsPtr(S, hitsMatrix)
#else
#define ssSetPerTaskSampleHitsPtr(S, hitsMatrix) \
    ssSetPerTaskSampleHitsPtr_cannot_be_used_in_SFunctions
#endif

#endif

#define ssGetSolverIsAtLeftPostOfContZcEvent(S) \
    ((S)->mdlInfo->solverInfo->isAtLeftPostOfContZcEvent == 1U)

#define ssGetSolverIsAtRightPostOfContZcEvent(S) \
    ((S)->mdlInfo->solverInfo->isAtRightPostOfContZcEvent == 1U)

#if !SS_SFCN || SS_GENERATED_S_FUNCTION

#define ssSetSolverInfo(S, ptr) (S)->mdlInfo->solverInfo = (ptr)
#define ssGetSolverInfo(S) ((S)->mdlInfo->solverInfo)

#define ssSetSolverZcSignalVector(S, ptr) ssGetSolverInfo(S)->zcSignalVector = (ptr)
#define ssGetSolverZcSignalVector(S) (ssGetSolverInfo(S)->zcSignalVector)

#define ssSetSolverZcEventsVector(S, ptr) ssGetSolverInfo(S)->zcEventsVector = (ptr)
#define ssGetSolverZcEventsVector(S) (ssGetSolverInfo(S)->zcEventsVector)

#define _ssGetSolverZcEventsVector(S) ssGetSolverZcEventsVector(S)
#define _ssSetSolverZcEventsVector(S, ptr) ssSetSolverZcEventsVector(S, ptr)


#define ssSetSolverZcSignalAttrib(S, ptr) ssGetSolverInfo(S)->zcSignalAttrib = (ptr)
#define ssGetSolverZcSignalAttrib(S) (ssGetSolverInfo(S)->zcSignalAttrib)

#define ssSetSolverZcSignalVectorLength(S, n) ssGetSolverInfo(S)->zcSignalVectorLength = (n)
#define ssGetSolverZcSignalVectorLength(S) (ssGetSolverInfo(S)->zcSignalVectorLength)

#define ssSetSolverFoundContZcEvents(S, val) ssGetSolverInfo(S)->foundContZcEvents = (val)
#define ssGetSolverFoundContZcEvents(S) (ssGetSolverInfo(S)->foundContZcEvents)

#define ssSetSolverIsAtLeftPostOfContZcEvent(S, val) \
    ssGetSolverInfo(S)->isAtLeftPostOfContZcEvent = (val)

#define ssSetSolverIsAtRightPostOfContZcEvent(S, val) \
    ssGetSolverInfo(S)->isAtRightPostOfContZcEvent = (val)

#define ssSetSolverZcPrevStateVector(S, val) ssSetPrevZCSigState(S, val)
#define ssGetSolverZcPrevStateVector(S) ssGetPrevZCSigState(S)

#define _ssGetSolverZcPrevStateVector(S) _ssGetPrevZCSigState(S)
#define _ssSetSolverZcPrevStateVector(S, ptr) _ssSetPrevZCSigState(S, ptr)

#define ssSetSolverAdaptiveZcDetection(S, val) ssGetSolverInfo(S)->adaptiveZcDetection = (val)
#define ssGetSolverAdaptiveZcDetection(S) (ssGetSolverInfo(S)->adaptiveZcDetection)

#define ssSetSolverNumZcSignals(S, n) ssGetSolverInfo(S)->numZcSignals = (n)
#define ssGetSolverNumZcSignals(S) (ssGetSolverInfo(S)->numZcSignals)

#define ssSetSolverStateProjection(S, val) ssGetSolverInfo(S)->stateProjection = (val)
#define ssGetSolverStateProjection(S) (ssGetSolverInfo(S)->stateProjection)

#define ssSetSolverMassMatrixType(S, val) ssGetSolverInfo(S)->massMatrixType = (val)
#define ssGetSolverMassMatrixType(S) (ssGetSolverInfo(S)->massMatrixType)

#define ssSetSolverMassMatrixNzMax(S, val) ssGetSolverInfo(S)->massMatrixNzMax = (val)
#define ssGetSolverMassMatrixNzMax(S) (ssGetSolverInfo(S)->massMatrixNzMax)

#define ssSetSolverMassMatrixIr(S, val) ssGetSolverInfo(S)->massMatrixIr = (val)
#define ssGetSolverMassMatrixIr(S) (ssGetSolverInfo(S)->massMatrixIr)

#define ssSetSolverMassMatrixJc(S, val) ssGetSolverInfo(S)->massMatrixJc = (val)
#define ssGetSolverMassMatrixJc(S) (ssGetSolverInfo(S)->massMatrixJc)

#define ssSetSolverMassMatrixPr(S, val) ssGetSolverInfo(S)->massMatrixPr = (val)
#define ssGetSolverMassMatrixPr(S) (ssGetSolverInfo(S)->massMatrixPr)

#define ssSetSolverConsistencyChecking(S, val) ssGetSolverInfo(S)->consistencyChecking = (val)
#define ssGetSolverConsistencyChecking(S) (ssGetSolverInfo(S)->consistencyChecking)

#define ssSetSolverRobustResetMethod(S, val) ssGetSolverInfo(S)->robustResetMethod = (val)
#define ssGetSolverRobustResetMethod(S) (ssGetSolverInfo(S)->robustResetMethod)

#define _ssSetSolverUpdateJacobianAtReset(S, val) ssGetSolverInfo(S)->updateJacobianAtReset = (val)
#define ssSetSolverUpdateJacobianAtReset(S) \
    _ssSetSolverUpdateJacobianAtReset(S, (boolean_T)(1)) /* sticky */
#define ssGetSolverUpdateJacobianAtReset(S) \
    (ssGetSolverInfo(S)->updateJacobianAtReset) /* boolean_T */

#define ssSetSolverZcThreshold(S, val) ssGetSolverInfo(S)->zcThreshold = (val)
#define ssGetSolverZcThreshold(S) ssGetSolverInfo(S)->zcThreshold

#define ssSetSolverConsecutiveZCsStepRelTol(S, val) \
    ssGetSolverInfo(S)->solverConsecutiveZCsStepRelTol = (val)
#define ssGetSolverConsecutiveZCsStepRelTol(S) ssGetSolverInfo(S)->solverConsecutiveZCsStepRelTol

#define ssSetSolverMaxConsecutiveZCs(S, val) ssGetSolverInfo(S)->solverMaxConsecutiveZCs = (val)
#define ssGetSolverMaxConsecutiveZCs(S) ssGetSolverInfo(S)->solverMaxConsecutiveZCs

#define ssSetSolverMaxConsecutiveMinStep(S, val) \
    ssGetSolverInfo(S)->solverMaxConsecutiveMinStep = (val)
#define ssGetSolverMaxConsecutiveMinStep(S) ssGetSolverInfo(S)->solverMaxConsecutiveMinStep

#define ssSetSolverShapePreserveControl(S, val) \
    ssGetSolverInfo(S)->solverShapePreserveControl = (val)
#define ssGetSolverShapePreserveControl(S) ssGetSolverInfo(S)->solverShapePreserveControl

#define ssSetSolverJacobianMethodControl(S, val) \
    ssGetSolverInfo(S)->solverJacobianMethodControl = (val)
#define ssGetSolverJacobianMethodControl(S) ssGetSolverInfo(S)->solverJacobianMethodControl

#define ssGetSolverConsecutiveZCsError(S) ssGetSolverInfo(S)->consecutiveZCsError
#define ssSetSolverConsecutiveZCsError(S, val) ssGetSolverInfo(S)->consecutiveZCsError = (val)

#define ssGetSolverMaskedZcDiagnostic(S) ssGetSolverInfo(S)->maskedZcDiagnostic
#define ssSetSolverMaskedZcDiagnostic(S, val) ssGetSolverInfo(S)->maskedZcDiagnostic = (val)

#define ssGetSolverIgnoredZcDiagnostic(S) ssGetSolverInfo(S)->ignoredZcDiagnostic
#define ssSetSolverIgnoredZcDiagnostic(S, val) ssGetSolverInfo(S)->ignoredZcDiagnostic = (val)


/* Support old name RTWSolverInfo */

#define ssGetRTWSolverInfo(S) ssGetSolverInfo(S)
#define ssSetRTWSolverInfo(S, ptr) ssSetSolverInfo(S, ptr)

#endif

#if !SS_SFCN
/*
 * The following logging macros are for use by the Real-Time Workshop and
 * should not be used by S-functions.
 */
#define ssSetRTWLogInfo(S, ptr) (S)->mdlInfo->rtwLogInfo = (ptr) /* (RTWLogInfo *)  */

#define ssGetRTWLogInfo(S) (S)->mdlInfo->rtwLogInfo /* (RTWLogInfo *)  */

/* Maintained for xPC */
#define ssGetLogT(S) rtliGetLogT((S)->mdlInfo->rtwLogInfo)
#define ssGetLogX(S) rtliGetLogX((S)->mdlInfo->rtwLogInfo)
#define ssGetLogY(S) rtliGetLogY((S)->mdlInfo->rtwLogInfo)

#endif /* !SS_SFCN */


#if !SS_SFCN
/*
 * The following external mode macros are for use by the Real-Time Workshop and
 * should not be used by S-functions.
 */
#define ssSetRTWExtModeInfo(S, ptr) (S)->mdlInfo->extModeInfo = (ptr)

#define ssGetRTWExtModeInfo(S) (S)->mdlInfo->extModeInfo

#endif /* !SS_SFCN */


/* BlockIO vector - used by the Real-Time Workshop and Simulink. This
 *  is starting address of the block input/output vector. All non-virtual
 *  output ports have a slot into which they write their output.
 *
 *  User written S-functions should not access this field.
 */
#define _ssGetBlockIO(S) ((real_T*)((S)->mdlInfo->blockIO)) /*  (real_T *)       */
#if !SS_SFCN
#define ssGetBlockIO(S) _ssGetBlockIO(S)
#else
#define ssGetBlockIO(S) ssGetBlockIO_cannot_be_used_in_SFunctions
#endif
#define _ssSetBlockIO(S, io) (S)->mdlInfo->blockIO = ((void*)(io))
#if !SS_SFCN
#define ssSetBlockIO(S, io) _ssSetBlockIO(S, io)
#else
#define ssSetBlockIO(S, io) ssSetBlockIO_cannot_be_used_in_SFunctions
#endif

/* ReservedForXPC
 *
 *  User written S-functions should not access this field.
 */
#define _ssGetReservedForXPC(S) ((S)->mdlInfo->reservedForXPC)
#if !SS_SFCN
#define ssGetReservedForXPC(S) _ssGetReservedForXPC(S)
#else
#define ssGetReservedForXPC(S) ssGetReservedForXPC_cannot_be_used_in_SFunctions
#endif

#define _ssSetReservedForXPC(S, rxpc) (S)->mdlInfo->reservedForXPC = ((void*)(rxpc))
#if !SS_SFCN
#define ssSetReservedForXPC(S, rxpc) _ssSetReservedForXPC(S, rxpc)
#else
#define ssSetReservedForXPC(S, rxpc) ssSetReservedForXPC_cannot_be_used_in_SFunctions
#endif

/* ConstBlockIO vector - used by the Real-Time Workshop.
 *
 *  User written S-functions should not access this field.
 */
#define _ssGetConstBlockIO(S) ((const void*)((S)->sizes.constBlockIO)) /* (const void *) */
#if !SS_SFCN
#define ssGetConstBlockIO(S) _ssGetConstBlockIO(S)
#else
#define ssGetConstBlockIO(S) ssGetConstBlockIO_cannot_be_used_in_SFunctions
#endif
#define _ssSetConstBlockIO(S, io) (S)->sizes.constBlockIO = ((const void*)(io))
#if !SS_SFCN
#define ssSetConstBlockIO(S, io) _ssSetConstBlockIO(S, io)
#else
#define ssSetConstBlockIO(S, io) ssSetConstBlockIO_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || defined(RTW_GENERATED_S_FUNCTION)
#define ssGetTimeOfNextSampleHitPtr(S) (S)->mdlInfo->timeOfNextSampleHit
#endif

#if !SS_SFCN
#define ssSetTimeOfNextSampleHitPtr(S, ptr) (S)->mdlInfo->timeOfNextSampleHit = (ptr)
#endif

/* varNextHitTimesList vector - used by Simulink.
 *
 *  User written S-functions should not access this field.
 */

#if !SS_SFCN
#define ssGetVarNextHitTime(S, i) _ssGetVarNextHitTime(S, i)
#else
#define ssGetVarNextHitTime(S, i) ssGetVarNextHitTime_cannot_be_used_in_SFunctions
#endif


#if !SS_SFCN
#define ssSetVarNextHitTime(S, i, value) _ssSetVarNextHitTime(S, i, value)
#else
#define ssSetVarNextHitTime(S, i, value) ssSetVarNextHitTime_cannot_be_used_in_SFunctions
#endif

#define ssGetVarNextHitTimesListPtr(S) (S)->mdlInfo->varNextHitTimesList /* (real_T *) */

#define _ssSetVarNextHitTimesListPtr(S, listPtr) \
    (S)->mdlInfo->varNextHitTimesList = ((real_T*)(listPtr))

#if !SS_SFCN
#define ssSetVarNextHitTimesListPtr(S, listPtr) _ssSetVarNextHitTimesListPtr(S, listPtr)
#else
#define ssSetVarNextHitTimesListPtr(S, listPtr) \
    ssSetVarNextHitTimesListPtr_cannot_be_used_in_SFunctions
#endif

/* tNextWasAdjusted vector - used by Simulink.
 *
 *  User written S-functions should not access this field.
 */

#define ssGetTNextWasAdjusted(S, sti) ((S)->mdlInfo->tNextWasAdjusted[sti]) /* (boolean_T) */
#if !SS_SFCN
#define _ssSetTNextWasAdjusted(S, sti, val) (S)->mdlInfo->tNextWasAdjusted[sti] = (val)
#define ssSetTNextWasAdjustedPtr(S, ptr) (S)->mdlInfo->tNextWasAdjusted = (ptr)
#endif

#define _ssGetDefaultParam(S) (S)->mdlInfo->defaultParam /*   (real_T *)    */
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetDefaultParam(S) _ssGetDefaultParam(S)
#else
#define ssGetDefaultParam(S) ssGetDefaultParam_cannot_be_used_in_SFunctions
#endif

/*
 * ssSetDefaultParam - Used by the Real-Time Workshop. This contains
 * a pointer to all the model's parameters.
 */

#define _ssSetDefaultParam(S, paramVector) (S)->mdlInfo->defaultParam = (paramVector)
#if !SS_SFCN
#define ssSetDefaultParam(S, paramVector) _ssSetDefaultParam(S, paramVector)
#else
#define ssSetDefaultParam(S, paramVector) ssSetDefaultParam_cannot_be_used_in_SFunctions
#endif

#define _ssGetDefaultParamValue(S, paramIdx) \
    (S)->mdlInfo->defaultParam[paramIdx] /*   (real_T)      */
#if !SS_SFCN
#define ssGetDefaultParamValue(S, paramIdx) _ssGetDefaultParamValue(S, paramIdx)
#else
#define ssGetDefaultParamValue(S, paramIdx) ssGetDefaultParamValue_cannot_be_used_in_SFunctions
#endif
#define _ssSetDefaultParamValue(S, paramIdx, paramValue) \
    (S)->mdlInfo->defaultParam[paramIdx] = (paramValue)
#if !SS_SFCN
#define ssSetDefaultParamValue(S, paramIdx, paramValue) \
    _ssSetDefaultParamValue(S, paramIdx, paramValue)
#else
#define ssSetDefaultParamValue(S, paramIdx, paramValue) \
    ssSetDefaultParamValue_cannot_be_used_in_SFunctions
#endif

/*
 * ssSetModelMappingInfo - Used by the Real-Time Workshop. This contains
 * a pointer to all the model's mapping information which is used by
 * external applications to "probe" the models, parameter, block I/O, etc
 * vectors.
 */

#define _ssSetModelMappingInfo(S, mapInfo) (S)->mdlInfo->mappingInfo = (void*)(mapInfo)
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssSetModelMappingInfo(S, mapInfo) _ssSetModelMappingInfo(S, mapInfo)
#else
#define ssSetModelMappingInfo(S, paramVector) ssSetModelMappingInfo_cannot_be_used_in_SFunctions
#endif

#define _ssGetModelMappingInfo(S) (S)->mdlInfo->mappingInfo /*   (void*)    */
#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetModelMappingInfo(S) _ssGetModelMappingInfo(S)
#else
#define ssGetModelMappingInfo(S) ssGetModelMappingInfo_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetContextSysRanBCPtr(S, ptr)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_CONTEXT_SYS_PTR, 0, (ptr)) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssGetContextSysRanBCPtr(S) ssGetContextSysRanBCPtr_cannot_be_used_in_SFunctions
#endif

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetContextSysTid(S, tid) \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_CONTEXT_TID, 0, (tid)) _ssSafelyCallGenericFcnEnd
#else
#define ssGetContextSysTid(S) ssGetContextSysTid_cannot_be_used_in_SFunctions
#endif

#define ssCallAccelRunBlock(S, sysIdx, blkIdx, function) \
    (*(S)->mdlInfo->accelRunBlock)(S, sysIdx, blkIdx, function);

#define _ssSetAccelRunBlockFcn(S, fcn) (S)->mdlInfo->accelRunBlock = (fcn)
#define _ssSetBdRefPtr(S, ptr) (S)->mdlInfo->bdRefPtr = ((void*)ptr)
#define _ssGetBdRefPtr(S) (S)->mdlInfo->bdRefPtr /*   (void*)    */

#if !SS_SFCN
#define ssSetAccelRunBlockFcn(S, fcn) _ssSetAccelRunBlockFcn(S, fcn)
#define ssSetBdRefPtr(S, ptr) _ssSetBdRefPtr(S, ptr)
#define ssGetBdRefPtr(S) _ssGetBdRefPtr(S)
#else
#define ssSetAccelRunBlockFcn(S, fcn) ssSetAccelRunBlockFcn_cannot_be_used_in_SFunctions
#define ssSetBdRefPtr(S, ptr) ssSetBdRefPtr_cannot_be_used_in_SFunctions
#define ssGetBdRefPtr(S) ssGetBdRefPtr_cannot_be_used_in_SFunctions
#endif

#if SS_SL_INTERNAL
#define ssSetWriteRTWStrFcn(S, fcn) (S)->mdlInfo->writeRTWStrFcn = (fcn)
#define ssSetWriteRTWNameValuePairFcn(S, fcn) \
    (S)->blkInfo.blkInfo2->mdlInfoSLSize->writeRTWNameValuePairFcn = (fcn)
#define ssSetWriteRTWNameValuePairFcnInt(S, fcn) (S)->mdlInfo->writeRTWNameValuePairFcn = (fcn)
#define ssSetWriteRTWParameterFcn(S, fcn) \
    (S)->blkInfo.blkInfo2->mdlInfoSLSize->writeRTWParameterFcn = (fcn)
#define ssSetWriteRTWParameterFcnInt(S, fcn) (S)->mdlInfo->writeRTWParameterFcn = (fcn)
#define ssSetWriteRTWFcnArg(S, fcnarg) (S)->mdlInfo->writeRTWFcnArg = (fcnarg)
#define ssSetGenericFcn(S, fcn) (S)->mdlInfo->genericFcn = (fcn)
#endif

/* ===--------------------------------------------------------------------=== */
/*              SLCG string context access functions                          */
/* ===--------------------------------------------------------------------=== */
#if (SS_SFCN_FOR_SIM)
#ifdef __cplusplus
extern "C" {
#endif
#endif
#if (SS_SFCN_FOR_SIM)
extern int_T _ssCreateSLCGStringBuffer(SimStruct* S);
#define ssCreateSLCGStringBuffer(S) _ssCreateSLCGStringBuffer(S)
#else
#define ssCreateSLCGStringBuffer(S)
#endif
#if (SS_SFCN_FOR_SIM)
extern void _ssAddToSLCGStringBuffer(SimStruct* S, int_T aStringBufferIdx, char* aString);
#define ssAddToSLCGStringBuffer(S, aStringBufferIdx, aString) \
    _ssAddToSLCGStringBuffer(S, aStringBufferIdx, aString)
#else
#define ssAddToSLCGStringBuffer(S, aStringBufferIdx, aString)
#endif
#if (SS_SFCN_FOR_SIM)
#ifdef __cplusplus
}
#endif
#endif
/* ===--------------------------------------------------------------------=== */
/*              End of SLCG string context access functions                   */
/* ===--------------------------------------------------------------------=== */

/*
 * Signal Access.
 */
#if SS_SL_INTERNAL
#define ssSetSignalAccess(S, ptr) (S)->mdlInfo->signalAccess = (ptr)

#define ssGetSignalAccess(S) ((S)->mdlInfo->signalAccess)

#define ssSetSelectedSignalsFcn(S, fcn) (S)->mdlInfo->signalAccess->SelectedSignals = (fcn)

#define ssSetSigListCreateFcn(S, fcn) (S)->mdlInfo->signalAccess->SigListCreate = (fcn)

#define ssSetSigListDestroyFcn(S, fcn) (S)->mdlInfo->signalAccess->SigListDestroy = (fcn)

#define ssSetSigListUnavailSigAlertFcn(S, fcn) \
    (S)->mdlInfo->signalAccess->SigListUnavailSigAlert = (fcn)

#define ssSetGenericDestroyFcn(S, fcn) (S)->mdlInfo->signalAccess->utFree = (fcn)

#define ssSetGetPortNameFcn(S, fcn) (S)->mdlInfo->signalAccess->GetPortName = (fcn)

#define ssSetUnselectSigFcn(S, fcn) (S)->mdlInfo->signalAccess->UnselectSig = (fcn)

#define ssSetSigListGetNumRegionsFcn(S, fcn) \
    (S)->mdlInfo->signalAccess->SigListGetNumRegions = (fcn)

#define ssSetSigListGetFirstRegFcn(S, fcn) (S)->mdlInfo->signalAccess->SigListGetFirstReg = (fcn)

#define ssSetSigListGetNumElementsFcn(S, fcn) \
    (S)->mdlInfo->signalAccess->SigListGetNumElements = (fcn)

#define ssSetSigListGetIfTieWrapFcn(S, fcn) (S)->mdlInfo->signalAccess->SigListGetIfTieWrap = (fcn)
#endif

/*
 * Data type Access.
 */
#if !SS_SFCN_LEVEL_1

#if SS_SL_INTERNAL
#define ssSetDataTypeAccess(S, dta) (S)->mdlInfo->dataTypeAccess = (dta)

#define dtaGetDataTypeTable(dta) ((dta)->dataTypeTable)
#define dtaSetDataTypeTable(dta, table) (dta)->dataTypeTable = (table)

#define dtaGetRegisterDataTypeFcn(dta) ((dta)->registerFcn)
#define dtaSetRegisterDataTypeFcn(dta, fcn) (dta)->registerFcn = (fcn)

#define dtaGetRegisterDataTypeFcnWithCheck(dta) ((dta)->registerFcnWithCheck)
#define dtaSetRegisterDataTypeFcnWithCheck(dta, fcn) (dta)->registerFcnWithCheck = (fcn)

#define dtaGetNumDataTypesFcn(dta) ((dta)->getNumDataTypesFcn)
#define dtaSetGetNumDataTypesFcn(dta, fcn) (dta)->getNumDataTypesFcn = (fcn)

#define dtaGetDataTypeIdFcn(dta) ((dta)->getIdFcn)
#define dtaSetGetDataTypeIdFcn(dta, fcn) (dta)->getIdFcn = (fcn)

#define dtaGetGetGenericDTAIntProp(dta) ((dta)->getGenericDTAIntProp)
#define dtaSetGetGenericDTAIntProp(dta, fcn) (dta)->getGenericDTAIntProp = (fcn)
#define dtaGetSetGenericDTAIntProp(dta) ((dta)->setGenericDTAIntProp)
#define dtaSetSetGenericDTAIntProp(dta, fcn) (dta)->setGenericDTAIntProp = (fcn)

#define dtaGetGetGenericDTAIntElemProp(dta) ((dta)->getGenericDTAIntElemProp)
#define dtaSetGetGenericDTAIntElemProp(dta, fcn) (dta)->getGenericDTAIntElemProp = (fcn)
#define dtaGetSetGenericDTAIntElemProp(dta) ((dta)->setGenericDTAIntElemProp)
#define dtaSetSetGenericDTAIntElemProp(dta, fcn) (dta)->setGenericDTAIntElemProp = (fcn)

#define dtaGetGetGenericDTARealElemProp(dta) ((dta)->getGenericDTARealElemProp)
#define dtaSetGetGenericDTARealElemProp(dta, fcn) (dta)->getGenericDTARealElemProp = (fcn)
#define dtaGetSetGenericDTARealElemProp(dta) ((dta)->setGenericDTARealElemProp)
#define dtaSetSetGenericDTARealElemProp(dta, fcn) (dta)->setGenericDTARealElemProp = (fcn)

#define dtaGetGetGenericDTAVoidProp(dta) ((dta)->getGenericDTAVoidProp)
#define dtaSetGetGenericDTAVoidProp(dta, fcn) (dta)->getGenericDTAVoidProp = (fcn)
#define dtaGetSetGenericDTAVoidProp(dta) ((dta)->setGenericDTAVoidProp)
#define dtaSetSetGenericDTAVoidProp(dta, fcn) (dta)->setGenericDTAVoidProp = (fcn)

#define dtaGetGetGenericDTAVoidElemProp(dta) ((dta)->getGenericDTAVoidElemProp)
#define dtaSetGetGenericDTAVoidElemProp(dta, fcn) (dta)->getGenericDTAVoidElemProp = (fcn)
#define dtaGetSetGenericDTAVoidElemProp(dta) ((dta)->setGenericDTAVoidElemProp)
#define dtaSetSetGenericDTAVoidElemProp(dta, fcn) (dta)->setGenericDTAVoidElemProp = (fcn)

#define dtaGetGetConvertBetweenFcn(dta) ((dta)->getConvertBetweenFcn)
#define dtaSetGetConvertBetweenFcn(dta, fcn) (dta)->getConvertBetweenFcn = (fcn)
#define dtaGetSetConvertBetweenFcn(dta) ((dta)->setConvertBetweenFcn)
#define dtaSetSetConvertBetweenFcn(dta, fcn) (dta)->setConvertBetweenFcn = (fcn)

#define dtaGetGetConstructFcn(dta) ((dta)->getConstructFcn)
#define dtaSetGetConstructFcn(dta, fcn) (dta)->getConstructFcn = (fcn)
#define dtaGetSetConstructFcn(dta) ((dta)->setConstructFcn)
#define dtaSetSetConstructFcn(dta, fcn) (dta)->setConstructFcn = (fcn)

#define dtaGetGetDestructFcn(dta) ((dta)->getDestructFcn)
#define dtaSetGetDestructFcn(dta, fcn) (dta)->getDestructFcn = (fcn)
#define dtaGetSetDestructFcn(dta) ((dta)->setDestructFcn)
#define dtaSetSetDestructFcn(dta, fcn) (dta)->setDestructFcn = (fcn)

#define dtaGetGetDeepCopyFcn(dta) ((dta)->getDeepCopyFcn)
#define dtaSetGetDeepCopyFcn(dta, fcn) (dta)->getDeepCopyFcn = (fcn)
#define dtaGetSetDeepCopyFcn(dta) ((dta)->setDeepCopyFcn)
#define dtaSetSetDeepCopyFcn(dta, fcn) (dta)->setDeepCopyFcn = (fcn)

#define dtaGetGetSizeOfFcn(dta) ((dta)->getSizeOfFcn)
#define dtaSetGetSizeOfFcn(dta, fcn) (dta)->getSizeOfFcn = (fcn)
#define dtaGetSetSizeOfFcn(dta) ((dta)->setSizeOfFcn)
#define dtaSetSetSizeOfFcn(dta, fcn) (dta)->setSizeOfFcn = (fcn)

#define dtaGetGetContainedDataFcn(dta) ((dta)->getContainedDataFcn)
#define dtaSetGetContainedDataFcn(dta, fcn) (dta)->getContainedDataFcn = (fcn)
#define dtaGetSetContainedDataFcn(dta) ((dta)->setContainedDataFcn)
#define dtaSetSetContainedDataFcn(dta, fcn) (dta)->setContainedDataFcn = (fcn)

#define dtaGetGetContainedDataDimsFcn(dta) ((dta)->getContainedDataDimsFcn)
#define dtaSetGetContainedDataDimsFcn(dta, fcn) (dta)->getContainedDataDimsFcn = (fcn)
#define dtaGetSetContainedDataDimsFcn(dta) ((dta)->setContainedDataDimsFcn)
#define dtaSetSetContainedDataDimsFcn(dta, fcn) (dta)->setContainedDataDimsFcn = (fcn)

#define dtaGetGetDataConstructFcn(dta) ((dta)->getDataConstructFcn)
#define dtaSetGetDataConstructFcn(dta, fcn) (dta)->getDataConstructFcn = (fcn)
#define dtaGetSetDataConstructFcn(dta) ((dta)->setDataConstructFcn)
#define dtaSetSetDataConstructFcn(dta, fcn) (dta)->setDataConstructFcn = (fcn)

#define dtaGetGetSerializeFcn(dta) ((dta)->getSerializeFcn)
#define dtaSetGetSerializeFcn(dta, fcn) (dta)->getSerializeFcn = (fcn)
#define dtaGetSetSerializeFcn(dta) ((dta)->setSerializeFcn)
#define dtaSetSetSerializeFcn(dta, fcn) (dta)->setSerializeFcn = (fcn)

#define dtaGetGetDeserializeFcn(dta) ((dta)->getDeserializeFcn)
#define dtaSetGetDeserializeFcn(dta, fcn) (dta)->getDeserializeFcn = (fcn)
#define dtaGetSetDeserializeFcn(dta) ((dta)->setDeserializeFcn)
#define dtaSetSetDeserializeFcn(dta, fcn) (dta)->setDeserializeFcn = (fcn)

#define dtaGetGetSerializeSizeFcn(dta) ((dta)->getSerializeSizeFcn)
#define dtaSetGetSerializeSizeFcn(dta, fcn) (dta)->getSerializeSizeFcn = (fcn)
#define dtaGetSetSerializeSizeFcn(dta) ((dta)->setSerializeSizeFcn)
#define dtaSetSetSerializeSizeFcn(dta, fcn) (dta)->setSerializeSizeFcn = (fcn)

#define dtaGetGetGenericDTAUnaryFcnGW(dta) ((dta)->getGenericDTAUnaryFcnGW)
#define dtaSetGetGenericDTAUnaryFcnGW(dta, fcn) (dta)->getGenericDTAUnaryFcnGW = (fcn)
#define dtaGetSetGenericDTAUnaryFcnGW(dta) ((dta)->setGenericDTAUnaryFcnGW)
#define dtaSetSetGenericDTAUnaryFcnGW(dta, fcn) (dta)->setGenericDTAUnaryFcnGW = (fcn)

#define dtaGetGetGenericDTABinaryFcnGW(dta) ((dta)->getGenericDTABinaryFcnGW)
#define dtaSetGetGenericDTABinaryFcnGW(dta, fcn) (dta)->getGenericDTABinaryFcnGW = (fcn)
#define dtaGetSetGenericDTABinaryFcnGW(dta) ((dta)->setGenericDTABinaryFcnGW)
#define dtaSetSetGenericDTABinaryFcnGW(dta, fcn) (dta)->setGenericDTABinaryFcnGW = (fcn)

#define dtaSetGetDTADiagnostic(dta, fcn) (dta)->getGenericDTADiagnostic = (fcn)

#endif

/* Fixed-Point license manager access*/

#if SS_SIM
#define ssSetFixedPointLicenseAccess(S, idx, d)                            \
    _ssSafelyCallGenericFcnStart(S)(S, GENFCNFIXPT_LICENSE, idx, (void*)d) \
        _ssSafelyCallGenericFcnEnd
#endif



#endif

typedef struct {
    void* data;
    int_T dtId;
    int8_T* result;
} DataQueryInfo;

#define _ssIsPositiveDataValue(S, inData, inDtId, inResult)                          \
    {                                                                                \
        DataQueryInfo info;                                                          \
        info.data = (inData);                                                        \
        info.dtId = (inDtId);                                                        \
        info.result = (inResult);                                                    \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_IS_POSITIVE_DATA_VALUE, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                              \
    }

#define _ssSignDataValue(S, inData, inDtId, inResult)                         \
    {                                                                         \
        DataQueryInfo info;                                                   \
        info.data = (inData);                                                 \
        info.dtId = (inDtId);                                                 \
        info.result = (inResult);                                             \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SIGN_DATA_VALUE, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                       \
    }

/*
 * User-defined datatypes
 */

#if !SS_SFCN_LEVEL_1
#if SS_SIM
#define ssRegisterTypeFromExpr(S, n, id)                                       \
    {                                                                          \
        ssRegisterTypeFromNameType _slRegisterTypeFromNameInfo;                \
        _slRegisterTypeFromNameInfo.name = (n);                                \
        _slRegisterTypeFromNameInfo.dataTypeId = (id);                         \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REGISTER_TYPE_FROM_EXPR, 0, \
                                        (void*)&_slRegisterTypeFromNameInfo)   \
            _ssSafelyCallGenericFcnEnd;                                        \
    }
#define ssRegisterTypeFromExprNoError(S, n, id)                                         \
    {                                                                                   \
        ssRegisterTypeFromNameType _slRegisterTypeFromNameInfo;                         \
        _slRegisterTypeFromNameInfo.name = (n);                                         \
        _slRegisterTypeFromNameInfo.dataTypeId = (id);                                  \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REGISTER_TYPE_FROM_EXPR_NO_ERROR, 0, \
                                        (void*)&_slRegisterTypeFromNameInfo)            \
            _ssSafelyCallGenericFcnEnd;                                                 \
    }


#else
#define ssRegisterTypeFromExpr(S, name, id)
#define ssRegisterTypeFromExprNoError(S, name, id)


#endif

#endif



/*
 * mexApiInt2/MexApiReal1/MexApiReal2
 * used by the mex api (simulink.c)
 */
#define ssGetMexApiInt2(S) (S)->mdlInfo->mexApiInt2 /*   (int_T)       */
#define ssSetMexApiInt2(S, val) (S)->mdlInfo->mexApiInt2 = (val)
#define ssGetMexApiSLSize2(S) (S)->blkInfo.blkInfo2->mdlInfoSLSize->mexApiSLSize2;
#define ssSetMexApiSLSize2(S, val) (S)->blkInfo.blkInfo2->mdlInfoSLSize->mexApiSLSize2 = (val);

#define ssGetMexApiReal1(S) (S)->mdlInfo->mexApiReal1              /*   (real_T)      */
#define ssSetMexApiReal1(S, val) (S)->mdlInfo->mexApiReal1 = (val) /*   (real_T)      */

#define ssGetMexApiReal2(S) (S)->mdlInfo->mexApiReal2              /*   (real_T)      */
#define ssSetMexApiReal2(S, val) (S)->mdlInfo->mexApiReal2 = (val) /*   (real_T)      */

#define ssGetMexApiVoidPtr1(S) (S)->mdlInfo->mexApiVoidPtr1 /*   (void *)      */
#define ssSetMexApiVoidPtr1(S, val) (S)->mdlInfo->mexApiVoidPtr1 = SS_STATIC_CAST(void*, val)

/*
 * Set data alignment
 */
#define ssSetDataAlignment(S, num)                                            \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_DATA_ALIGNMENT, num, NULL) \
        _ssSafelyCallGenericFcnEnd

/*---------------------------- get system level setting ---------------------*/

#include "sl_prodhwdevicetype.h"

/* Get whether net slope corrections can use division
 */
#define ssGetNetSlopeViaDivision(S, result)                                             \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_NET_SLOPE_VIA_DIVISION, 0, result) \
        _ssSafelyCallGenericFcnEnd

/* Get whether use strict single or double upcasting when necessary
 */
#define ssGetSupportStrictSingle(S, result)                                    \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_STRICT_SINGLE, 0, result) \
        _ssSafelyCallGenericFcnEnd

/*================================================*
 * Running simulation type                        *
 *================================================*/

#define ssGetSimType(S, result)                                                 \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_SIMULATIONTYPE, 0, result) \
        _ssSafelyCallGenericFcnEnd

#define ssGetIsInteractiveSim(S, result)                                          \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_ISINTERACTIVESIM, 0, result) \
        _ssSafelyCallGenericFcnEnd

/* get the double override setting of current system
 */
#define ssGetDataTypeOverride(S, result)                                          \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATATYPEOVERRIDE, 0, result) \
        _ssSafelyCallGenericFcnEnd

/* get the datatype override applies to setting of current system
 */
#define ssGetDataTypeOverrideAppliesTo(S, result)                                          \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_DATATYPEOVERRIDEAPPLIESTO, 0, result) \
        _ssSafelyCallGenericFcnEnd


/* The term Doubles-Override is outdated and misleading.
 * Instead, the terms Data-Type-Override and Scaled-Doubles should be used
 * as appropriate.
 * The follow definition is provided for backwards compatibility
 */
#define ssGetDblOverride(S, result) (ssGetDataTypeOverride((S), (result)))

#define ssGetMinMaxOverflowLogging(S, result)                              \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_MINMAXLOG, 0, result) \
        _ssSafelyCallGenericFcnEnd

#define ssGetMinMaxOverflowArchiveMode(S, result)                              \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_MINMAXARCHIVE, 0, result) \
        _ssSafelyCallGenericFcnEnd

#define ssGetProdHWDeviceInfo(S, result)                                          \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_PRODHWDEVICEINFO, 0, result) \
        _ssSafelyCallGenericFcnEnd

/*---------------------------- S->callSys  ----------------------------------*/

#define _ssSetSFcnExportsFunctionCalls(S)                                                    \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_EXPORTS_FUNCTION_CALLS, 0, (void*)NULL) \
        _ssSafelyCallGenericFcnEnd

#define ssSetAcceptsFcnCallInputs(S)                                                         \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_ACCEPTS_FCNCALL_INPUTS, 0, (void*)NULL) \
        _ssSafelyCallGenericFcnEnd

/*
 * ssExportOutputFcn,
 * ssExportEnableFcn,
 * ssExportDisableFcn -
 *   S-functions which export function calls use this in
 *   mdlInitializeSizes to specify the custom user functions
 *   which are exported to Simulink by means of the input ports
 *   of the S-function.
 */
#if defined(SS_SFCN) && defined(S_FUNCTION_EXPORTS_FUNCTION_CALLS)

#define ssExportOutputFcn(S, pIdx, oFcn)                                              \
    {                                                                                 \
        SysOutputFcn _oFcn = (SysOutputFcn)oFcn;                                      \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_EXPORTED_OUTPUT_FCN, (pIdx), \
                                        (void*)&_oFcn) _ssSafelyCallGenericFcnEnd;    \
    }

#define ssExportEnableFcn(S, pIdx, oFcn)                                              \
    {                                                                                 \
        SysOutputFcn _oFcn = (SysOutputFcn)oFcn;                                      \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_EXPORTED_ENABLE_FCN, (pIdx), \
                                        (void*)&_oFcn) _ssSafelyCallGenericFcnEnd;    \
    }

#define ssExportDisableFcn(S, pIdx, oFcn)                                              \
    {                                                                                  \
        SysOutputFcn _oFcn = (SysOutputFcn)oFcn;                                       \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_EXPORTED_DISABLE_FCN, (pIdx), \
                                        (void*)&_oFcn) _ssSafelyCallGenericFcnEnd;     \
    }

#define ssInportIsLatched(S, pIdx)                                                 \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_INPORT_LATCHED, (pIdx), NULL) \
        _ssSafelyCallGenericFcnEnd

#endif



/*
 * ssGetCallSystemNumFcnCallDestinations:
 *   Return number of fcn-call destinations called by S-function's
 *   first output port and elemIdx-th element
 */
/* GenericFcn implementation */
#define ssGetNumFcnCallDestinations(S, elemIdx, result)                                   \
    {                                                                                     \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_NUM_FCNCALL_DEST, elemIdx, result) \
            _ssSafelyCallGenericFcnEnd;                                                   \
    }



/*
 * ssCallSystem -
 *  Provided for backwards compatibility. Here, tid is hardcoded is 0.
 */
#define ssCallSystem(S, element) ssCallSystemWithTid(S, element, 0)

#define _ssSetCallSystemOutputArg1List(S, list) (S)->callSys.args1 = (list)

#define _ssSetCallSystemOutputArg2List(S, list) (S)->callSys.args2 = (list)

#define _ssSetCallSystemOutputFcnList(S, list) (S)->callSys.fcns = (list)

#if SS_SL_INTERNAL || SS_RTW || SS_GENERATED_S_FUNCTION
/*
 * The following cannot be used in S-functions
 */
#define ssGetCallSystemOutputArg1List(S) (S)->callSys.args1 /* (void**)        */
#define ssSetCallSystemOutputArg1List(S, list) _ssSetCallSystemOutputArg1List(S, list)

#define ssGetCallSystemOutputArg2List(S) (S)->callSys.args2 /* (int_T*)        */
#define ssSetCallSystemOutputArg2List(S, list) _ssSetCallSystemOutputArg2List(S, list)

#define ssGetCallSystemOutputFcnList(S) (S)->callSys.fcns /* (SysOutputFcn*) */
#define ssSetCallSystemOutputFcnList(S, list) _ssSetCallSystemOutputFcnList(S, list)
#else
#define ssSetCallSystemOutputArg1List(S, list) \
    ssSetCallSystemOutputArg1List_cannot_be_used_in_SFunctions
#define ssSetCallSystemOutputArg2List(S, list) \
    ssSetCallSystemOutputArg2List_cannot_be_used_in_SFunctions
#define ssSetCallSystemOutputFcnList(S, list) \
    ssSetCallSystemOutputFcnList_cannot_be_used_in_SFunctions
#endif


#define ssGetBlkSupportConcurrentTasks(S, result)                                         \
    {                                                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_BLK_SUPPORT_CONCURRENT_TASKS, 0, \
                                        (result)) _ssSafelyCallGenericFcnEnd;             \
    }

#define ssSetBlkSupportConcurrentTasks(S, value)                                                  \
    {                                                                                             \
        int_T val = value;                                                                        \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BLK_SUPPORT_CONCURRENT_TASKS, 0, (&val)) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }
#if SS_SIM
#define ssGetConcurrentTasks(S) ((S)->sizes.flags.isConcurrentTasks == 1U)

#define ssSetConcurrentTasks(S, boolVal) ((S)->sizes.flags.isConcurrentTasks = (boolVal) ? 1U : 0U)
#else
#define ssGetConcurrentTasks(S) ssGetConcurrentTasks_cannot_be_used_in_RTW

#define ssSetConcurrentTasks(S) ssSetConcurrentTasks_cannot_be_used_in_RTW

#endif

/*---------------------------- S->regDataType  ------------------------------*/

#if !SS_SFCN
/*
 * The following cannot be used in S-functions
 */
#define ssGetDataTypeFcnsArg1(S) (S)->regDataType.arg1 /* (void*)        */
#define ssSetDataTypeFcnsArg1(S, ptr1) (S)->regDataType.arg1 = ((void*)(ptr1))

#define ssGetRegisterDataTypeFcn(S) (S)->regDataType.registerFcn /* (RegisterDataType) */
#define ssSetRegisterDataTypeFcn(S, val) (S)->regDataType.registerFcn = (val)

#define ssGetDataTypeSizeFcn(S) (S)->regDataType.getSizeFcn /* (GetDataTypeSize) */
#define ssSetGetDataTypeSizeFcn(S, val) (S)->regDataType.getSizeFcn = (val)

#define ssGetSetDataTypeSizeFcn(S) (S)->regDataType.setSizeFcn /* (SetDataTypeSize) */
#define ssSetDataTypeSizeFcn(S, val) (S)->regDataType.setSizeFcn = (val)

#define ssGetDataTypeZeroFcn(S) (S)->regDataType.getZeroFcn /* (GetDataTypeZero) */
#define ssSetGetDataTypeZeroFcn(S, val) (S)->regDataType.getZeroFcn = (val)

#define ssGetSetDataTypeZeroFcn(S) (S)->regDataType.setZeroFcn /* (SetDataTypeZero) */
#define ssSetDataTypeZeroFcn(S, val) (S)->regDataType.setZeroFcn = (val)

#define ssGetDataTypeNameFcn(S) (S)->regDataType.getNameFcn /* (GetDataTypeName) */
#define ssSetGetDataTypeNameFcn(S, val) (S)->regDataType.getNameFcn = (val)

#define ssGetDataTypeIdFcn(S) (S)->regDataType.getIdFcn /* (GetDataTypeId) */
#define ssSetGetDataTypeIdFcn(S, val) (S)->regDataType.getIdFcn = (val)

/*ssGetSetNumDWorkFcn*/
#if defined(USE_64BIT_FIELDS)
#define ssGetSetNumDWorkFcn(S) ((S)->blkInfo.blkInfo2->blkInfoSLSize->regDataType.setNumDWorkFcn)
#elif defined(USE_32BIT_FIELDS)
#define ssGetSetNumDWorkFcn(S) ((S)->regDataType.setNumDWorkFcn) /* (SetNumDWork)     */
#endif

/* Int version for use by Simulink engine only */
#define ssGetSetNumDWorkFcnInt(S) ((S)->regDataType.setNumDWorkFcn) /* (SetNumDWork)     */
/*end ssGetSetNumDWorkFcn*/

/*ssSetNumDWorkFcn*/
#if defined(USE_64BIT_FIELDS)
#define ssSetNumDWorkFcn(S, val) \
    ((S)->blkInfo.blkInfo2->blkInfoSLSize->regDataType.setNumDWorkFcn = (val))
#define ssSetNumDWorkFcnInt(S, val) ((S)->regDataType.setNumDWorkFcn = (val))
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumDWorkFcn(S, val) ((S)->regDataType.setNumDWorkFcn = (val))
#endif
/*end ssSetNumDWorkFcn*/

#define ssStrictBooleanCheckEnabledFcn(S) \
    (S)->states.modelMethods2->strictBooleanCheckEnabledFcn /* (StrictBooleanCheckEnabledFcn) */
#define ssSetStrictBooleanCheckEnabledFcn(S, val) \
    (S)->states.modelMethods2->strictBooleanCheckEnabledFcn = (val)

#define ssSetConvertBuiltInDTypeFcn(S, fcn) (S)->states.modelMethods2->ConvertBuiltInDType = (fcn)

#endif

#if !SS_SFCN_LEVEL_1

#if SS_SIM
#define ssGetDataTypeProperties(S, id) \
    (dtaGetDataTypeProperties(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDataTypeProperties(S, id) ssGetDataTypeProperties_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDataTypeProperties(S, id, properties) \
    dtaSetDataTypeProperties(ssGetDataTypeAccess(S), (S)->path, (id), (properties))
#else
#define ssSetDataTypeProperties(S, id, properties) ssSetDataTypeProperties_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDataTypePropertiesSize(S, id) \
    (dtaGetDataTypePropertiesSize(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDataTypePropertiesSize(S, id) ssGetDataTypePropertiesSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDataTypePropertiesSize(S, id, size) \
    dtaSetDataTypePropertiesSize(ssGetDataTypeAccess(S), (S)->path, (id), (size))
#else
#define ssSetDataTypePropertiesSize(S, id, size) ssSetDataTypePropertiesSize_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssStrictBooleanCheckEnabled(S)                                                       \
    (((S)->states.modelMethods2->strictBooleanCheckEnabledFcn != NULL)                       \
         ? (*(S)->states.modelMethods2->strictBooleanCheckEnabledFcn)((S)->regDataType.arg1) \
         : (false))
#else
#define ssStrictBooleanCheckEnabled(S) ssStrictBooleanCheckEnabled_cannot_be_used_in_RTW
#endif

/*  ssCallConvertBuiltInDType
 *  Options:
 *      satOnIntOverFlow:
 *          If true, saturate.  If false, the conversion is undefined when
 *          values are out of range (platform dependent conversion).
 *      doDiff:
 *          If true, compare original values and converted values and return
 *          true if they are different (e.g., value was saturated, etc).  If
 *          doDiff is false, this function always returns true.
 */
#if SS_SIM
#define ssCallConvertBuiltInDType(S, nVals, satOnIntOverFlow, doDiff, dt1, v1, dt2, v2)           \
    (S)->states.modelMethods2->ConvertBuiltInDType(nVals, satOnIntOverFlow, doDiff, dt1, v1, dt2, \
                                                   v2)
#else
#define ssCallConvertBuiltInDType(S, nVals, satOnIntOverFlow, doDiff, dt1, v1, dt2, v2) \
    ssCallConvertBuiltInDType_cannot_be_used_in_RTW
#endif



#if SS_SIM
#define ssGetDataTypeStorageId(S, id) \
    (dtaGetDataTypeStorageId(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDataTypeStorageId(S, id) ssGetDataTypeStorageId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDataTypeStorageId(S, id, storageId) \
    dtaSetDataTypeStorageId(ssGetDataTypeAccess(S), (S)->path, (id), (storageId))
#else
#define ssSetDataTypeStorageId(S, id, storageId) ssSetDataTypeStorageId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDataTypeIdAliasedTo(S, id) \
    (dtaGetDataTypeIdAliasedTo(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDataTypeIdAliasedTo(S, id) ssGetDataTypeIdAliasedTo_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDataTypeIdAliasedTo(S, id, idAliasedTo) \
    dtaSetDataTypeIdAliasedTo(ssGetDataTypeAccess(S), (S)->path, (id), (idAliasedTo))
#else
#define ssSetDataTypeIdAliasedTo(S, id, idAliasedTo) ssSetDataTypeIdAliasedTo_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetConvertBetweenFcn(S, id) \
    (dtaGetConvertBetweenFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetConvertBetweenFcn(S, id) ssGetConvertBetweenFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetConvertBetweenFcn(S, id, fcn) \
    dtaSetConvertBetweenFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetConvertBetweenFcn(S, id, fcn) ssSetConvertBetweenFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallConvertBetweenForSrcId(S, dstId, srcId, numEls, u, options, y)                \
    (ssGetConvertBetweenFcn((S), (srcId)) != NULL                                           \
         ? ssGetConvertBetweenFcn((S), (srcId))(ssGetDataTypeAccess(S), (S)->path, (dstId), \
                                                (srcId), (numEls), (u), (options), (y))     \
         : 0)
#else
#define ssCallConvertBetweenForSrcId(S, dstId, srcId, numEls, u, options, y) \
    ssCallConvertBetweenForSrcId_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallConvertBetweenForDstId(S, dstId, srcId, numEls, u, options, y)                \
    (ssGetConvertBetweenFcn((S), (dstId)) != NULL                                           \
         ? ssGetConvertBetweenFcn((S), (dstId))(ssGetDataTypeAccess(S), (S)->path, (dstId), \
                                                (srcId), (numEls), (u), (options), (y))     \
         : 0)
#else
#define ssCallConvertBetweenForDstId(S, dstId, srcId, numEls, u, options, y) \
    ssCallConvertBetweenForDstId_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssGetConstructFcn(S, id) (dtaGetConstructFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetConstructFcn(S, id) ssGetConstructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetConstructFcn(S, id, fcn) \
    dtaSetConstructFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetConstructFcn(S, id, fcn) ssSetConstructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallConstruct(S, id, u)                                                     \
    (ssGetConstructFcn((S), (id)) != NULL                                             \
         ? ssGetConstructFcn((S), (id))(ssGetDataTypeAccess(S), (S)->path, (id), (u)) \
         : 0)
#else
#define ssCallConstruct(S, id, u) ssCallConstruct_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDestructFcn(S, id) (dtaGetDestructFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDestructFcn(S, id) ssGetDestructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDestructFcn(S, id, fcn) \
    dtaSetDestructFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetDestructFcn(S, id, fcn) ssSetDestructFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallDestruct(S, id, u)                                                     \
    (ssGetDestructFcn((S), (id)) != NULL                                             \
         ? ssGetDestructFcn((S), (id))(ssGetDataTypeAccess(S), (S)->path, (id), (u)) \
         : 0)
#else
#define ssCallDestruct(S, id, u) ssCallDestruct_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDeepCopyFcn(S, id) (dtaGetDeepCopyFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDeepCopyFcn(S, id) ssGetDeepCopyFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDeepCopyFcn(S, id, fcn) \
    dtaSetDeepCopyFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetDeepCopyFcn(S, id, fcn) ssSetDeepCopyFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallDeepCopy(S, id, y, u)                                                          \
    (ssGetDeepCopyFcn((S), (srcId)) != NULL                                                  \
         ? ssGetDeepCopyFcn((S), (srcId))(ssGetDataTypeAccess(S), (S)->path, (id), (y), (u)) \
         : 0)
#else
#define ssCallDeepCopy(S, id, y, u) ssCallDeepCopy_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetIsPositiveFcn(S, id) (dtaGetIsPositiveFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetIsPositiveFcn(S, id) ssGetIsPositiveFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetIsPositiveFcn(S, id, fcn) \
    dtaSetIsPositiveFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetIsPositiveFcn(S, id, fcn) ssSetIsPositiveFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallIsPositive(S, id, numEls, u, options, y)                                           \
    (ssGetIsPositiveFcn((S), (id)) != NULL                                                       \
         ? ssGetIsPositiveFcn((S), (id))(ssGetDataTypeAccess(S), (S)->path, (id), (numEls), (u), \
                                         (options), (y))                                         \
         : 0)
#else
#define ssCallIsPositive(S, id, numEls, u, options, y) ssCallIsPositive_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssGetIsNegativeFcn(S, id) (dtaGetIsNegativeFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetIsNegativeFcn(S, id) ssGetIsNegativeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetIsNegativeFcn(S, id, fcn) \
    dtaSetIsNegativeFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetIsNegativeFcn(S, id, fcn) ssSetIsNegativeFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallIsNegative(S, id, numEls, u, options, y)                                           \
    (ssGetIsNegativeFcn((S), (id)) != NULL                                                       \
         ? ssGetIsNegativeFcn((S), (id))(ssGetDataTypeAccess(S), (S)->path, (id), (numEls), (u), \
                                         (options), (y))                                         \
         : 0)
#else
#define ssCallIsNegative(S, id, numEls, u, options, y) ssCallIsNegative_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssGetGreaterThanFcn(S, id) (dtaGetGreaterThanFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetGreaterThanFcn(S, id) ssGetGreaterThanFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetGreaterThanFcn(S, id, fcn) \
    dtaSetGreaterThanFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetGreaterThanFcn(S, id, fcn) ssSetGreaterThanFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallGreaterThan(S, id, numEls, u1, u2, options, y)                                       \
    (ssGetGreaterThanFcn((S), (id)) != NULL                                                        \
         ? ssGetGreaterThanFcn((S), (id))(ssGetDataTypeAccess(S), (S)->path, (id), (numEls), (u1), \
                                          (u2), (options), (y))                                    \
         : 0)
#else
#define ssCallGreaterThan(S, id, numEls, u1, u2, options, y) ssCallGreaterThan_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssGetGreaterEqualFcn(S, id) (dtaGetGreaterEqualFcn(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetGreaterEqualFcn(S, id) ssGetGreaterEqualFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetGreaterEqualFcn(S, id, fcn) \
    dtaSetGreaterEqualFcn(ssGetDataTypeAccess(S), (S)->path, (id), (fcn))
#else
#define ssSetGreaterEqualFcn(S, id, fcn) ssSetGreaterEqualFcn_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssCallGreaterEqual(S, id, numEls, u1, u2, options, y)                                 \
    (ssGetGreaterEqualFcn((S), (id)) != NULL                                                  \
         ? ssGetGreaterEqualFcn((S), (id))(ssGetDataTypeAccess(S), (S)->path, (id), (numEls), \
                                           (u1), (u2), (options), (y))                        \
         : 0)
#else
#define ssCallGreaterEqual(S, id, numEls, u1, u2, options, y) \
    ssCallGreaterEqual_cannot_be_used_in_RTW
#endif

#endif /* NOT level 1 S-function */

/*-------------------------------- S->stInfo --------------------------------*/
#define ssGetSampleTimePtr(S) (S)->stInfo.sampleTimes /*   (time_T *)    */
#define ssSetSampleTimePtr(S, ptr) (S)->stInfo.sampleTimes = (ptr)
#define ssGetOffsetTimePtr(S) (S)->stInfo.offsetTimes /*   (time_T *)    */
#define ssSetOffsetTimePtr(S, ptr) (S)->stInfo.offsetTimes = (ptr)



/*-------------------- For Variable Sample Time Unique ID -------------------*/
#if defined(RTW_GENERATED_S_FUNCTION)
#define ssSetVariableSampleTimeUID(S, sti, val)                                        \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_VARIABLE_SAMPLE_TIME_UID, sti, val) \
        _ssSafelyCallGenericFcnEnd
#endif

/* Only the S-Functions need to call the ssSupportVarTsInMdlRef*/
#if (SS_SL_INTERNAL || SS_SFCN_FOR_SIM) && defined(ssGetOwnerBlock)
#define ssSupportVarTsInMdlRef(S, flag)                                                     \
    {                                                                                       \
        if (ssGetOwnerBlock(S) != NULL) {                                                   \
            boolean_T val = flag;                                                           \
            _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_VARTS_MDLREF_SUPPORT, val, NULL) \
                _ssSafelyCallGenericFcnEnd;                                                 \
        }                                                                                   \
    }
#else
#define ssSupportVarTsInMdlRef(S, flag)
#endif


/*
 * These APIs are used during compilation, and they are no-op during runtime.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssSetDisallowContinuous(S, flag)                                            \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_DISALLOW_CONTINUOUS, flag, NULL) \
        _ssSafelyCallGenericFcnEnd

#define ssSetDisallowControllableSampleTime(S, flag)                                   \
    {                                                                                  \
        boolean_T tmp = flag;                                                          \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_DISALLOW_CONTROLLABLE, 0, &tmp) \
            _ssSafelyCallGenericFcnEnd;                                                \
    }

#define ssSetControllableSampleTimeUID(S, sti, uid)                                             \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_CONTROLLABLE_SAMPLE_TIME_UID, (int)sti, uid) \
        _ssSafelyCallGenericFcnEnd;

#else



#define ssSetDisallowContinuous(S, flag)

#define ssSetDisallowControllableSampleTime(S, flag)

#define ssSetControllableSampleTimeUID(S, sti, uid)

#endif

#if defined(RTW_GENERATED_S_FUNCTION)
#define ssSetInputPortControllableSampleTime(S, portIdx, base)                          \
    {                                                                                   \
        real_T tmp = base;                                                              \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_INPUT_CONTROLLABLE_SAMPLE_TIME,  \
                                        (int)portIdx, &tmp) _ssSafelyCallGenericFcnEnd; \
    }

#define ssSetInputPortControllableSampleTimeUID(S, portIdx, uid)                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_INPUT_CONTROLLABLE_SAMPLE_TIME_UID, \
                                    (int)portIdx, uid) _ssSafelyCallGenericFcnEnd


#define ssSetOutputPortControllableSampleTime(S, portIdx, base)                         \
    {                                                                                   \
        real_T tmp = base;                                                              \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_OUTPUT_CONTROLLABLE_SAMPLE_TIME, \
                                        (int)portIdx, &tmp) _ssSafelyCallGenericFcnEnd; \
    }


#define ssSetOutputPortControllableSampleTimeUID(S, portIdx, uid)                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_OUTPUT_CONTROLLABLE_SAMPLE_TIME_UID, \
                                    (int)portIdx, uid) _ssSafelyCallGenericFcnEnd

#else

#define ssSetInputPortControllableSampleTime(S, portIdx, base)

#define ssSetInputPortControllableSampleTimeUID(S, portIdx, uid)

#define ssSetOutputPortControllableSampleTime(S, portIdx, base)

#define ssSetOutputPortControllableSampleTimeUID(S, portIdx, uid)

#endif



#define _ssSetSampleTimeTaskIDPtr(S, tids) (S)->stInfo.sampleTimeTaskIDs = (tids)


#if !SS_SFCN || SS_GENERATED_S_FUNCTION || defined(USE_RTMODEL)
/*
 * The following are not for use in S-functions
 */
#define ssGetTNextTid(S) (S)->stInfo.tNextTid /*   (int_T)   */
#define ssSetTNextTid(S, setting) (S)->stInfo.tNextTid = (setting)
#define ssGetSampleTimeTaskIDPtr(S) (S)->stInfo.sampleTimeTaskIDs /*   (int_T *)     */
#define ssSetSampleTimeTaskIDPtr(S, tids) _ssSetSampleTimeTaskIDPtr(S, tids)
#else
#define ssSetSampleTimeTaskIDPtr(S, tids) ssSetSampleTimeTaskIDPtr_cannot_be_used_in_SFunctions
#endif

#define _ssSetSampleTimeTaskID(S, sti, tid) (S)->stInfo.sampleTimeTaskIDs[sti] = (tid)
#if !SS_SFCN
#define ssSetSampleTimeTaskID(S, sti, tid) _ssSetSampleTimeTaskID(S, sti, tid)
#else
#define ssSetSampleTimeTaskID(S, sti, tid) ssSetSampleTimeTaskID_cannot_be_used_in_SFunctions
#endif

/*--------------------------- S->modelMethods.sFcn --------------------------*/
/*
 * Macros are used to call an S-function block methods. These should not
 * be used by an S-function directly.
 */
#define ssSetmdlInitializeSizes(S, initSizes) \
    (S)->modelMethods.sFcn.mdlInitializeSizes = (initSizes)
#define sfcnInitializeSizes(S) (*(S)->modelMethods.sFcn.mdlInitializeSizes)(S)
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssGetmdlInitializePropagationPass(S) \
    ((S)->states.modelMethods2)->mdlInitializePropagationPass
#define ssSetmdlInitializePropagationPass(S, mdlInitializePropagationPass) \
    {                                                                      \
        ((S)->states.modelMethods2)->mdlInitializePropagationPass =        \
            (mdlInitializePropagationPass);                                \
        _ssSetSfcnHasMdlDimensionsFcn(S, 1);                               \
    }
#define sfcnInitializePropagationPass(S, passType) \
    (*((S)->states.modelMethods2)->mdlInitializePropagationPass)(S, passType)


#define ssGetmdlGetInputPortWidthLevel1(S) (S)->modelMethods.sFcn.mdlGetInputPortWidthLevel1
#define ssSetmdlGetInputPortWidthLevel1(S, getInputPortWidth) \
    (S)->modelMethods.sFcn.mdlGetInputPortWidthLevel1 = (getInputPortWidth)
#define sfcnGetInputPortWidthLevel1(S, outputPortWidth) \
    (*(S)->modelMethods.sFcn.mdlGetInputPortWidthLevel1)(S, outputPortWidth)

#define ssGetmdlGetOutputPortWidthLevel1(S) (S)->modelMethods.sFcn.mdlGetOutputPortWidthLevel1
#define ssSetmdlGetOutputPortWidthLevel1(S, getOutputPortWidth) \
    (S)->modelMethods.sFcn.mdlGetOutputPortWidthLevel1 = (getOutputPortWidth)
#define sfcnGetOutputPortWidthLevel1(S, inputPortWidth) \
    (*(S)->modelMethods.sFcn.mdlGetOutputPortWidthLevel1)(S, inputPortWidth)


#if defined(SS_SFCN)
#if defined(USE_64BIT_FIELDS)
#define ssGetmdlSetInputPortWidth(S)   \
    ((ssGetSfcnHasMdlDimensionsFcn(S)) \
         ? NULL                        \
         : ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortWidth))
#define ssSetmdlSetInputPortWidth(S, setInputPortWidth)                                        \
    {                                                                                          \
        (S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortWidth = \
            (setInputPortWidth);                                                               \
        _ssSetSfcnHasMdlDimensionsFcn(S, 0);                                                   \
    }
#elif defined(USE_32BIT_FIELDS)
#define ssGetmdlSetInputPortWidth(S)   \
    ((ssGetSfcnHasMdlDimensionsFcn(S)) \
         ? NULL                        \
         : ((S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortWidth))
#define ssSetmdlSetInputPortWidth(S, setInputPortWidth)                         \
    {                                                                           \
        (S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortWidth = \
            (setInputPortWidth);                                                \
        _ssSetSfcnHasMdlDimensionsFcn(S, 0);                                    \
    }
#endif
#endif

#define ssGetSfcnHasMdlInputWidthFcn(S)                                                    \
    ((ssGetSFcnBitness(S) == SS_32BIT)                                                     \
         ? ((S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortWidth != NULL) \
         : ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions                \
                .mdlSetInputPortWidth != NULL))

/* There are two versions of this setter version, one for 32-bit width and one for
   64-bit width. Which version to call should be determined by bitness of the S-Function
   owning the SimStruct. Bitness can be queried using ssGetSFcnBitness(S) */
#define sfcnSetInputPortWidth(S, portIdx, width)                                             \
    (*(S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortWidth)( \
        S, portIdx, width)
#define sfcnSetInputPortWidthAsInt(S, portIdx, width) \
    (*(S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortWidth)(S, portIdx, width)

#if defined(SS_SFCN)
#if defined(USE_64BIT_FIELDS)
#define ssGetmdlSetOutputPortWidth(S)                                          \
    ((ssGetSfcnHasMdlDimensionsFcn(S)) ? NULL                                  \
                                       : ((S)->blkInfo.blkInfo2->mdlInfoSLSize \
                                              ->mdlSetOutputPortDimensions.mdlSetOutputPortWidth))
#define ssSetmdlSetOutputPortWidth(S, setOutputPortWidth)                                        \
    {                                                                                            \
        (S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions.mdlSetOutputPortWidth = \
            (setOutputPortWidth);                                                                \
        _ssSetSfcnHasMdlDimensionsFcn(S, 0);                                                     \
    }
#elif defined(USE_32BIT_FIELDS)
#define ssGetmdlSetOutputPortWidth(S)  \
    ((ssGetSfcnHasMdlDimensionsFcn(S)) \
         ? NULL                        \
         : ((S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortWidth))
#define ssSetmdlSetOutputPortWidth(S, setOutputPortWidth)                         \
    {                                                                             \
        (S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortWidth = \
            (setOutputPortWidth);                                                 \
        _ssSetSfcnHasMdlDimensionsFcn(S, 0);                                      \
    }
#endif
#endif

#define ssGetSfcnHasMdlOutputWidthFcn(S)                                                     \
    ((ssGetSFcnBitness(S) == SS_32BIT)                                                       \
         ? ((S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortWidth != NULL) \
         : ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions                 \
                .mdlSetOutputPortWidth != NULL))

/* There are two versions of this setter version, one for 32-bit width and one for
   64-bit width. Which version to call should be determined by bitness of the S-Function
   owning the SimStruct. Bitness can be queried using ssGetSFcnBitness(S) */
#define sfcnSetOutputPortWidth(S, portIdx, width)                                              \
    (*(S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions.mdlSetOutputPortWidth)( \
        S, portIdx, width)
#define sfcnSetOutputPortWidthAsInt(S, portIdx, width) \
    (*(S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortWidth)(S, portIdx, width)

#if defined(SS_SFCN)
#if defined(USE_64BIT_FIELDS)
#define ssGetmdlSetInputPortDimensions(S)                                                        \
    ((ssGetSfcnHasMdlDimensionsFcn(S))                                                           \
         ? ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortDims) \
         : NULL)
#define ssSetmdlSetInputPortDimensions(S, setInputPortDimensions)                             \
    {                                                                                         \
        (S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortDims = \
            (setInputPortDimensions);                                                         \
        _ssSetSfcnHasMdlDimensionsFcn(S, 1);                                                  \
    }
#elif defined(USE_32BIT_FIELDS)
#define ssGetmdlSetInputPortDimensions(S)                                         \
    ((ssGetSfcnHasMdlDimensionsFcn(S))                                            \
         ? ((S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortDims) \
         : NULL)
#define ssSetmdlSetInputPortDimensions(S, setInputPortDimensions)              \
    {                                                                          \
        (S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortDims = \
            (setInputPortDimensions);                                          \
        _ssSetSfcnHasMdlDimensionsFcn(S, 1);                                   \
    }
#endif
#endif

#define ssGetSfcnHasMdlInputDimensionsFcn(S)                                                       \
    ((ssGetSFcnBitness(S) == SS_32BIT)                                                             \
         ? ((S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortDims != NULL)          \
         : ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortDims != \
            NULL))

/* There are two versions of this setter version, one for 32-bit dimsInfo and one for
   64-bit dimsInfo. Which version to call should be determined by bitness of the S-Function
   owning the SimStruct. Bitness can be queried using ssGetSFcnBitness(S) */
#define sfcnSetInputPortDimensionInfo(S, portIdx, dimsInfo)                                 \
    (*(S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetInputPortDimensions.mdlSetInputPortDims)( \
        S, portIdx, dimsInfo)
#define sfcnSetInputPortDimensionInfoAsInt(S, portIdx, dimsInfo) \
    (*(S)->modelMethods.sFcn.mdlSetInputPortDimensions.mdlSetInputPortDims)(S, portIdx, dimsInfo)

#if defined(SS_SFCN)
#if defined(USE_64BIT_FIELDS)
#define ssGetmdlSetOutputPortDimensions(S)                                                         \
    ((ssGetSfcnHasMdlDimensionsFcn(S))                                                             \
         ? ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions.mdlSetOutputPortDims) \
         : NULL)
#define ssSetmdlSetOutputPortDimensions(S, setOutputPortDimensions)                             \
    {                                                                                           \
        (S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions.mdlSetOutputPortDims = \
            (setOutputPortDimensions);                                                          \
        _ssSetSfcnHasMdlDimensionsFcn(S, 1);                                                    \
    }
#elif defined(USE_32BIT_FIELDS)
#define ssGetmdlSetOutputPortDimensions(S)                                          \
    ((ssGetSfcnHasMdlDimensionsFcn(S))                                              \
         ? ((S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortDims) \
         : NULL)
#define ssSetmdlSetOutputPortDimensions(S, setOutputPortDimensions)              \
    {                                                                            \
        (S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortDims = \
            (setOutputPortDimensions);                                           \
        _ssSetSfcnHasMdlDimensionsFcn(S, 1);                                     \
    }
#endif
#endif

#define ssGetSfcnHasMdlOutputDimensionsFcn(S)                                               \
    ((ssGetSFcnBitness(S) == SS_32BIT)                                                      \
         ? ((S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortDims != NULL) \
         : ((S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions                \
                .mdlSetOutputPortDims != NULL))

/* There are two versions of this setter version, one for 32-bit dimsInfo and one for
   64-bit dimsInfo. Which version to call should be determined by bitness of the S-Function
   owning the SimStruct. Bitness can be queried using ssGetSFcnBitness(S) */
#define sfcnSetOutputPortDimensionInfo(S, portIdx, dimsInfo)                                  \
    (*(S)->blkInfo.blkInfo2->mdlInfoSLSize->mdlSetOutputPortDimensions.mdlSetOutputPortDims)( \
        S, portIdx, dimsInfo)
#define sfcnSetOutputPortDimensionInfoAsInt(S, portIdx, dimsInfo) \
    (*(S)->modelMethods.sFcn.mdlSetOutputPortDimensions.mdlSetOutputPortDims)(S, portIdx, dimsInfo)

#define ssGetmdlSetDefaultPortDimensions(S) ((S)->states.modelMethods2)->mdlSetDefaultPortDimensions
#define ssSetmdlSetDefaultPortDimensions(S, setDefaultPortDimensions) \
    ((S)->states.modelMethods2)->mdlSetDefaultPortDimensions = setDefaultPortDimensions
#define sfcnSetDefaultPortDimensionInfo(S) \
    (*((S)->states.modelMethods2)->mdlSetDefaultPortDimensions)(S)

#define ssGetmdlSetInputPortSymbolicDimensions(S) \
    (ssGetModelMethods4(S)->mdlSetInputPortSymbolicDimensions)
#define ssSetmdlSetInputPortSymbolicDimensions(S, setInputPortSymbolicDimensions) \
    ssGetModelMethods4(S)->mdlSetInputPortSymbolicDimensions = setInputPortSymbolicDimensions
#define sfcnSetInputPortSymbolicDimensions(S, aPortIdx, aSymbDimsId) \
    ssGetmdlSetInputPortSymbolicDimensions(S)(S, aPortIdx, aSymbDimsId)

#define ssGetmdlSetOutputPortSymbolicDimensions(S) \
    (ssGetModelMethods4(S)->mdlSetOutputPortSymbolicDimensions)
#define ssSetmdlSetOutputPortSymbolicDimensions(S, setOutputPortSymbolicDimensions) \
    ssGetModelMethods4(S)->mdlSetOutputPortSymbolicDimensions = setOutputPortSymbolicDimensions
#define sfcnSetOutputPortSymbolicDimensions(S, aPortIdx, aSymbDimsId) \
    ssGetmdlSetOutputPortSymbolicDimensions(S)(S, aPortIdx, aSymbDimsId)

#define ssGetmdlSetInputPortDataType(S) (S)->modelMethods.sFcn.mdlSetInputPortDataType
#define ssSetmdlSetInputPortDataType(S, setInputPortDataType) \
    (S)->modelMethods.sFcn.mdlSetInputPortDataType = (setInputPortDataType)
#define sfcnSetInputPortDataType(S, portIdx, inputPortDataType) \
    (*(S)->modelMethods.sFcn.mdlSetInputPortDataType)(S, portIdx, inputPortDataType)

#define ssGetmdlSetOutputPortDataType(S) (S)->modelMethods.sFcn.mdlSetOutputPortDataType
#define ssSetmdlSetOutputPortDataType(S, setOutputPortDataType) \
    (S)->modelMethods.sFcn.mdlSetOutputPortDataType = (setOutputPortDataType)
#define sfcnSetOutputPortDataType(S, portIdx, outputPortDataType) \
    (*(S)->modelMethods.sFcn.mdlSetOutputPortDataType)(S, portIdx, outputPortDataType)

#define ssGetmdlSetDefaultPortDataTypes(S) ((S)->states.modelMethods2)->mdlSetDefaultPortDataTypes
#define ssSetmdlSetDefaultPortDataTypes(S, setDefaultPortDataTypes) \
    ((S)->states.modelMethods2)->mdlSetDefaultPortDataTypes = setDefaultPortDataTypes
#define sfcnSetDefaultPortDataTypes(S) (*((S)->states.modelMethods2)->mdlSetDefaultPortDataTypes)(S)

#define ssGetmdlSetInputPortComplexSignal(S) \
    (S)->modelMethods.sFcn.fcnInEnable.mdlSetInputPortComplexSignal
#define ssSetmdlSetInputPortComplexSignal(S, setInputPortComplexSignal) \
    (S)->modelMethods.sFcn.fcnInEnable.mdlSetInputPortComplexSignal = (setInputPortComplexSignal)
#define sfcnSetInputPortComplexSignal(S, portIdx, val) \
    (*(S)->modelMethods.sFcn.fcnInEnable.mdlSetInputPortComplexSignal)(S, portIdx, val)

#define ssGetmdlSetOutputPortComplexSignal(S) \
    (S)->modelMethods.sFcn.fcnOutDisable.mdlSetOutputPortComplexSignal
#define ssSetmdlSetOutputPortComplexSignal(S, setOutputPortComplexSignal) \
    (S)->modelMethods.sFcn.fcnOutDisable.mdlSetOutputPortComplexSignal =  \
        (setOutputPortComplexSignal)
#define sfcnSetOutputPortComplexSignal(S, portIdx, val) \
    (*(S)->modelMethods.sFcn.fcnOutDisable.mdlSetOutputPortComplexSignal)(S, portIdx, val)

#define ssGetmdlSetDefaultPortComplexSignals(S) \
    ((S)->states.modelMethods2)->mdlSetDefaultPortComplexSignals
#define ssSetmdlSetDefaultPortComplexSignals(S, setDefaultPortComplexSignals) \
    ((S)->states.modelMethods2)->mdlSetDefaultPortComplexSignals = setDefaultPortComplexSignals
#define sfcnSetDefaultPortComplexSignals(S) \
    (*((S)->states.modelMethods2)->mdlSetDefaultPortComplexSignals)(S)

#define ssGetmdlSetInputPortFrameData(S) ((S)->states.modelMethods2)->mdlSetInputPortFrameData
#define ssSetmdlSetInputPortFrameData(S, setInputPortFrameData) \
    ((S)->states.modelMethods2)->mdlSetInputPortFrameData = (setInputPortFrameData)
#define sfcnSetInputPortFrameData(S, portIdx, frameData) \
    (*((S)->states.modelMethods2)->mdlSetInputPortFrameData)(S, portIdx, frameData)

#endif

#define _ssGetRTWGeneratedEnable(S) (S)->modelMethods.sFcn.fcnInEnable.mdlEnable
#define _ssSetRTWGeneratedEnable(S, setEnable) \
    (S)->modelMethods.sFcn.fcnInEnable.mdlEnable = (setEnable)
#define _sfcnRTWGeneratedEnable(S) (*(S)->modelMethods.sFcn.fcnInEnable.mdlEnable)(S)

#define _ssGetRTWGeneratedDisable(S) (S)->modelMethods.sFcn.fcnOutDisable.mdlDisable
#define _ssSetRTWGeneratedDisable(S, setDisable) \
    (S)->modelMethods.sFcn.fcnOutDisable.mdlDisable = (setDisable)
#define _sfcnRTWGeneratedDisable(S) (*(S)->modelMethods.sFcn.fcnOutDisable.mdlDisable)(S)

#if !SS_SFCN || SS_GENERATED_S_FUNCTION
#define ssGetRTWGeneratedEnable(S) _ssGetRTWGeneratedEnable(S)
#define ssSetRTWGeneratedEnable(S, setEnable) _ssSetRTWGeneratedEnable(S, setEnable)
#define sfcnRTWGeneratedEnable(S) _sfcnRTWGeneratedEnable(S)

#define ssGetRTWGeneratedDisable(S) _ssGetRTWGeneratedDisable(S)
#define ssSetRTWGeneratedDisable(S, setDisable) _ssSetRTWGeneratedDisable(S, setDisable)
#define sfcnRTWGeneratedDisable(S) _sfcnRTWGeneratedDisable(S)

#else
/* User S-Functions */
#define ssGetRTWGeneratedEnable(S) ssGetRTWGeneratedEnable_cannot_be_used_in_SFunctions
#define ssSetRTWGeneratedEnable(S, setEnable) ssGetRTWGeneratedEnable_cannot_be_used_in_SFunctions
#define sfcnRTWGeneratedEnable(S) sfcnRTWGeneratedEnable_cannot_be_used_in_SFunctions

#define ssGetRTWGeneratedDisable(S) ssGetRTWGeneratedDisable_cannot_be_used_in_SFunctions
#define ssSetRTWGeneratedDisable(S, setDisable) \
    ssSetRTWGeneratedDisable_cannot_be_used_in_SFunctions
#define sfcnRTWGeneratedDisable(S) sfcnRTWGeneratedDisable_cannot_be_used_in_SFunctions
#endif

#define ssSetmdlInitializeSampleTimes(S, initSampleTimes) \
    (S)->modelMethods.sFcn.mdlInitializeSampleTimes = (initSampleTimes)
#define sfcnInitializeSampleTimes(S) (*(S)->modelMethods.sFcn.mdlInitializeSampleTimes)(S)

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssGetmdlSetInputPortSampleTime(S) (S)->modelMethods.sFcn.mdlSetInputPortSampleTime
#define ssSetmdlSetInputPortSampleTime(S, fcn) \
    (S)->modelMethods.sFcn.mdlSetInputPortSampleTime = (fcn)
#define sfcnSetInputPortSampleTime(S, portIdx, sampleTime, offsetTime) \
    (*(S)->modelMethods.sFcn.mdlSetInputPortSampleTime)(S, portIdx, sampleTime, offsetTime)

#define ssGetmdlSetOutputPortSampleTime(S) (S)->modelMethods.sFcn.mdlSetOutputPortSampleTime
#define ssSetmdlSetOutputPortSampleTime(S, fcn) \
    (S)->modelMethods.sFcn.mdlSetOutputPortSampleTime = (fcn)
#define sfcnSetOutputPortSampleTime(S, portIdx, sampleTime, offsetTime) \
    (*(S)->modelMethods.sFcn.mdlSetOutputPortSampleTime)(S, portIdx, sampleTime, offsetTime)

#define ssGetmdlSetWorkWidths(S) (S)->modelMethods.sFcn.mdlSetWorkWidths
#define ssSetmdlSetWorkWidths(S, setWorkWidths) \
    (S)->modelMethods.sFcn.mdlSetWorkWidths = (setWorkWidths)
#define sfcnSetWorkWidths(S) (*(S)->modelMethods.sFcn.mdlSetWorkWidths)(S)

#define ssGetmdlRTW(S) (S)->modelMethods.sFcn.mdlRTW
#define ssSetmdlRTW(S, rtw) (S)->modelMethods.sFcn.mdlRTW = (rtw)
#define sfcnRTW(S) (*(S)->modelMethods.sFcn.mdlRTW)(S)
#endif

#define ssGetmdlEnable(S) ((S)->states.modelMethods2)->mdlEnable
#define ssSetmdlEnable(S, enab) ((S)->states.modelMethods2)->mdlEnable = (enab)
#define sfcnEnable(S)                                                                       \
    ((S)->states.modelMethods2)->mdlEnable ? (*((S)->states.modelMethods2)->mdlEnable)((S)) \
                                           : (void)(S);

#define ssGetmdlDisable(S) ((S)->states.modelMethods2)->mdlDisable
#define ssSetmdlDisable(S, disab) ((S)->states.modelMethods2)->mdlDisable = (disab)
#define sfcnDisable(S)                                                                        \
    ((S)->states.modelMethods2)->mdlDisable ? (*((S)->states.modelMethods2)->mdlDisable)((S)) \
                                            : (void)(S);

#define ssSetmdlInitializeConditions(S, initConds) \
    (S)->modelMethods.sFcn.mdlInitializeConditions.level2 = (initConds)
#define ssGetmdlInitializeConditions(S) (S)->modelMethods.sFcn.mdlInitializeConditions.level2

#define sfcnInitializeConditions(S) (*(S)->modelMethods.sFcn.mdlInitializeConditions.level2)(S)

#define ssSetmdlInitializeConditionsLevel1(S, initConds) \
    (S)->modelMethods.sFcn.mdlInitializeConditions.level1 = (initConds)
#define sfcnInitializeConditionsLevel1(x0, S) \
    (*(S)->modelMethods.sFcn.mdlInitializeConditions.level1)(x0, S)

#define ssGetmdlStart(S) (S)->modelMethods.sFcn.mdlStart
#define ssSetmdlStart(S, start) (S)->modelMethods.sFcn.mdlStart = (start)
#define sfcnStart(S) (*(S)->modelMethods.sFcn.mdlStart)(S)

#define ssGetmdlDataTransferRead(S) ((S)->states.modelMethods2->modelMethods4->mdlDataTransferRead)
#define ssSetmdlDataTransferRead(S, function) \
    ((S)->states.modelMethods2->modelMethods4->mdlDataTransferRead = (function))
#define sfcnDataTransferRead(S, dtIdx, data) \
    ((*(S)->states.modelMethods2->modelMethods4->mdlDataTransferRead)(S, dtIdx, data))

#define ssGetmdlDataTransferWrite(S) \
    ((S)->states.modelMethods2->modelMethods4->mdlDataTransferWrite)
#define ssSetmdlDataTransferWrite(S, function) \
    ((S)->states.modelMethods2->modelMethods4->mdlDataTransferWrite = (function))
#define sfcnDataTransferWrite(S, dtIdx, data) \
    ((*(S)->states.modelMethods2->modelMethods4->mdlDataTransferWrite)(S, dtIdx, data))

#define ssGetmdlDataTransferInitBuffers(S) \
    ((S)->states.modelMethods2->modelMethods4->mdlDataTransferInitBuffers)
#define ssSetmdlDataTransferInitBuffers(S, function) \
    ((S)->states.modelMethods2->modelMethods4->mdlDataTransferInitBuffers = (function))
#define sfcnDataTransferInitBuffers(S, dtIdx, data) \
    ((*(S)->states.modelMethods2->modelMethods4->mdlDataTransferInitBuffers)(S, dtIdx, data))


#define ssGetmdlSetupRuntimeResources(S) \
    ((S)->states.modelMethods2->modelMethods4->mdlSetupRuntimeResources)
#define ssSetmdlSetupRuntimeResources(S, function) \
    ((S)->states.modelMethods2->modelMethods4->mdlSetupRuntimeResources = (function))
#define sfcnSetupRuntimeResources(S) \
    ((*(S)->states.modelMethods2->modelMethods4->mdlSetupRuntimeResources)(S))

#define ssGetmdlCleanupRuntimeResources(S) \
    ((S)->states.modelMethods2->modelMethods4->mdlCleanupRuntimeResources)
#define ssSetmdlCleanupRuntimeResources(S, function) \
    ((S)->states.modelMethods2->modelMethods4->mdlCleanupRuntimeResources = (function))
#define sfcnCleanupRuntimeResources(S) \
    ((*(S)->states.modelMethods2->modelMethods4->mdlCleanupRuntimeResources)(S))

#define ssSetOKtoCallStartTerminateOnSimRestart(S) \
    (S)->blkInfo.sfcnFlags.okToCallStartTerminateOnSimRestart = 1

#define ssGetOKtoCallStartTerminateOnSimRestart(S) \
    (S)->blkInfo.sfcnFlags.okToCallStartTerminateOnSimRestart

#define ssSetmdlInitSystemMatrices(S, initSystemMatrices) \
    ((S)->states.modelMethods2->modelMethods3)->mdlInitSystemMatrices = (initSystemMatrices)
#define ssGetmdlInitSystemMatrices(S) \
    ((S)->states.modelMethods2->modelMethods3)->mdlInitSystemMatrices
#define sfcnInitSystemMatrices(S) \
    (*(((S)->states.modelMethods2)->modelMethods3)->mdlInitSystemMatrices)(S)

#define ssGetmdlJacobianIrJc(S) ((S)->states.modelMethods2->modelMethods3)->mdlJacobianIrJc
#define ssSetmdlJacobianIrJc(S, JacobianIrJc) \
    ((S)->states.modelMethods2->modelMethods3)->mdlJacobianIrJc = (JacobianIrJc)
#define sfcnJacobianIrJc(S) (*(((S)->states.modelMethods2)->modelMethods3)->mdlJacobianIrJc)(S)

#define ssGetmdlPreInitialize(S) (S)->states.modelMethods2->modelMethods4->mdlPreInitialize
#define ssSetmdlPreInitialize(S, preinit) \
    (S)->states.modelMethods2->modelMethods4->mdlPreInitialize = (preinit)
#define sfcnPreInitialize(S) ((*(S)->states.modelMethods2->modelMethods4->mdlPreInitialize)(S))

#define ssGetmdlCopyRTPData(S) (S)->states.modelMethods2->modelMethods4->mdlCopyRTPData
#define ssSetmdlCopyRTPData(S, copyRTPData) \
    (S)->states.modelMethods2->modelMethods4->mdlCopyRTPData = (copyRTPData)
#define sfcnCopyRTPData(S, param, rtpData) \
    ((*(S)->states.modelMethods2->modelMethods4->mdlCopyRTPData)(S, param, rtpData))

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssGetmdlCheckParameters(S) (S)->modelMethods.sFcn.mdlCheckParameters
#define ssSetmdlCheckParameters(S, checkParameters) \
    (S)->modelMethods.sFcn.mdlCheckParameters = (checkParameters)
#define sfcnCheckParameters(S) (*(S)->modelMethods.sFcn.mdlCheckParameters)(S)

#define ssGetmdlProcessParameters(S) (S)->modelMethods.sFcn.mdlProcessParameters
#define ssSetmdlProcessParameters(S, fcnptr) (S)->modelMethods.sFcn.mdlProcessParameters = (fcnptr)
#define sfcnProcessParameters(S) (*(S)->modelMethods.sFcn.mdlProcessParameters)(S)
#endif

#define ssGetmdlExtModeExec(S) ((S)->states.modelMethods2)->mdlExtModeExec
#define ssSetmdlExtModeExec(S, extModeExec) \
    ((S)->states.modelMethods2)->mdlExtModeExec = (extModeExec)
#define sfcnExtModeExec(S) (*((S)->states.modelMethods2)->mdlExtModeExec)(S)

#if !SS_RT || defined(RSIM_WITH_SL_SOLVER)
#define ssSetmdlGetTimeOfNextVarHit(S, getTimeOfNextVarHit) \
    (S)->modelMethods.sFcn.mdlGetTimeOfNextVarHit = (getTimeOfNextVarHit)
#define sfcnGetTimeOfNextVarHit(S) (*(S)->modelMethods.sFcn.mdlGetTimeOfNextVarHit)(S)
#endif

#define sfcnOutputs(S, tid) (*(S)->modelMethods.sFcn.mdlOutputs.level2)(S, tid)

#define ssSetmdlOutputsLevel1(S, outputs) (S)->modelMethods.sFcn.mdlOutputs.level1 = (outputs)
#define sfcnOutputsLevel1(y, x, u, S, tid) \
    (*(S)->modelMethods.sFcn.mdlOutputs.level1)(y, x, u, S, tid)

#define ssSetmdlUpdate(S, update) (S)->modelMethods.sFcn.mdlUpdate.level2 = (update)
#define ssGetmdlUpdate(S) (S)->modelMethods.sFcn.mdlUpdate.level2
#define sfcnUpdate(S, tid) (*(S)->modelMethods.sFcn.mdlUpdate.level2)(S, tid)

#define ssSetmdlUpdateLevel1(S, update) (S)->modelMethods.sFcn.mdlUpdate.level1 = (update)
#define sfcnUpdateLevel1(x, u, S, tid) (*(S)->modelMethods.sFcn.mdlUpdate.level1)(x, u, S, tid)

#define ssSetmdlDerivatives(S, derivs) (S)->modelMethods.sFcn.mdlDerivatives.level2 = (derivs)
#define ssGetmdlDerivatives(S) (S)->modelMethods.sFcn.mdlDerivatives.level2
#define sfcnDerivatives(S) (*(S)->modelMethods.sFcn.mdlDerivatives.level2)(S)

#define ssSetmdlDerivativesLevel1(S, derivs) (S)->modelMethods.sFcn.mdlDerivatives.level1 = (derivs)
#define sfcnDerivativesLevel1(dx, x, u, S, tid) \
    (*(S)->modelMethods.sFcn.mdlDerivatives.level1)(dx, x, u, S, tid)

#if !SS_RT
#define ssSetmdlZeroCrossings(S, zeroCrossings) \
    (S)->modelMethods.sFcn.mdlZeroCrossings = (zeroCrossings)
#define sfcnZeroCrossings(S) (*(S)->modelMethods.sFcn.mdlZeroCrossings)(S)
#endif

#define ssSetmdlTerminate(S, terminate) (S)->modelMethods.sFcn.mdlTerminate = (terminate)
#define sfcnTerminate(S) (*(S)->modelMethods.sFcn.mdlTerminate)(S)

#define ssSetmdlGetOperatingPoint(S, fcn) \
    (S)->states.modelMethods2->modelMethods4->mdlGetOperatingPoint = (fcn)
#define sfcnSetGetOperatingPoint(S) \
    (*(S)->states.modelMethods2->modelMethods4->mdlGetOperatingPoint)(S)
#define ssSetmdlProjection(S, projection) ((S)->states.modelMethods2)->mdlProjection = (projection)
#define ssGetmdlProjection(S) ((S)->states.modelMethods2)->mdlProjection
#define sfcnProjection(S) (*((S)->states.modelMethods2)->mdlProjection)(S)

#define ssSetmdlSetOperatingPoint(S, fcn) \
    (S)->states.modelMethods2->modelMethods4->mdlSetOperatingPoint = (fcn)
#define sfcnSetOperatingPoint(S, op) \
    (*(S)->states.modelMethods2->modelMethods4->mdlSetOperatingPoint)(S, op)


#define ssSetmdlMassMatrix(S, massMatrixFcn) \
    ((S)->states.modelMethods2)->mdlMassMatrix = (massMatrixFcn)
#define ssGetmdlMassMatrix(S) ((S)->states.modelMethods2)->mdlMassMatrix
#define sfcnMassMatrix(S) (*((S)->states.modelMethods2)->mdlMassMatrix)(S)

#define ssSetmdlForcingFunction(S, forcingFunction) \
    ((S)->states.modelMethods2)->mdlForcingFunction = (forcingFunction)
#define ssGetmdlForcingFunction(S) ((S)->states.modelMethods2)->mdlForcingFunction
#define sfcnForcingFunction(S) (*((S)->states.modelMethods2)->mdlForcingFunction)(S)

#define ssSetmdlConstraints(S, constraintsFcn) \
    (((S)->states.modelMethods2)->constraintsInfo)->mdlConstraints = (constraintsFcn)
#define ssGetmdlConstraints(S) (((S)->states.modelMethods2)->constraintsInfo)->mdlConstraints
#define sfcnConstraints(S) (*((S)->states.modelMethods2)->constraintsInfo->mdlConstraints)(S)

#define ssSetmdlRTWCG(S, rtwcg) ((S)->states.modelMethods2)->mdlRTWCG = (rtwcg)
#define ssGetmdlRTWCG(S) ((S)->states.modelMethods2)->mdlRTWCG
#define sfcnRTWCG(S, iObj) (*((S)->states.modelMethods2)->mdlRTWCG)((S), (iObj))

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetmdlJacobian(S, jacobian) ((S)->states.modelMethods2)->mdlJacobian = (jacobian)
#define ssGetmdlJacobian(S) ((S)->states.modelMethods2)->mdlJacobian
#define sfcnJacobian(S) (*((S)->states.modelMethods2)->mdlJacobian)(S)

#define ssSetmdlSimStatusChange(S, simStatusChange) \
    ((S)->states.modelMethods2)->mdlSimStatusChange = (simStatusChange)
#define ssGetmdlSimStatusChange(S) ((S)->states.modelMethods2)->mdlSimStatusChange
#define sfcnSimStatusChange(S, simStatusChange) \
    (*((S)->states.modelMethods2)->mdlSimStatusChange)(S, (simStatusChange))

#endif


#if SS_SL_INTERNAL

typedef void (*voidFcnIntType)(int);
typedef void (*voidFcnVoidType)(void);
typedef void (*voidFcnVoidStarType)(void*, void*);
typedef void (*voidFcnVoidStarIntType)(void*, void*, boolean_T);

#ifdef __cplusplus
#define incompatibleFunctionCast(ToType, FunctionPtr) \
    (reinterpret_cast<ToType>(reinterpret_cast<size_t>(FunctionPtr)))
#else
#define incompatibleFunctionCast(ToType, FunctionPtr) (ToType)(FunctionPtr)
#endif

#define ssSetModelOutputs(S, fcn) \
    (S)->modelMethods.sFcn.mdlOutputs.level2 = incompatibleFunctionCast(mdlOutputsFcn, fcn)

#define ssRunModelOutputs(S, tid) \
    (*(incompatibleFunctionCast(voidFcnIntType, (S)->modelMethods.sFcn.mdlOutputs.level2)))(tid)

#define ssSetModelUpdate(S, fcn) \
    (S)->modelMethods.sFcn.mdlUpdate.level2 = incompatibleFunctionCast(mdlUpdateFcn, fcn)

#define ssRunModelUpdate(S, tid) \
    (*(incompatibleFunctionCast(voidFcnIntType, (S)->modelMethods.sFcn.mdlUpdate.level2)))(tid)

#define ssSetModelLogData(S, fcn) (S)->mdlInfo->rtwLogInfo->mdlLogData = (voidFcnVoidStarType)(fcn)
#define ssRunModelLogData(S, tp) \
    (*((S)->mdlInfo->rtwLogInfo->mdlLogData))((S)->mdlInfo->rtwLogInfo, tp)

#define ssSetModelLogDataIfInInterval(S, fcn) \
    (S)->mdlInfo->rtwLogInfo->mdlLogDataIfInInterval = (voidFcnVoidStarIntType)(fcn)
#define ssRunModelLogDataIfInInterval(S, tp, isInInterval)                              \
    (*((S)->mdlInfo->rtwLogInfo->mdlLogDataIfInInterval))((S)->mdlInfo->rtwLogInfo, tp, \
                                                          isInInterval)

#define ssSetModelDerivatives(S, fcn) \
    (S)->modelMethods.sFcn.mdlDerivatives.level2 = (mdlDerivativesFcn)(fcn)
#define ssRunModelDerivatives(S) \
    (*((voidFcnVoidType)((S)->modelMethods.sFcn.mdlDerivatives.level2)))()


#define ssSetModelProjection(S, fcn) \
    (S)->states.modelMethods2->mdlProjection = (mdlProjectionFcn)(fcn)
#define ssRunModelProjection(S) (*((voidFcnVoidType)((S)->states.modelMethods2->mdlProjection)))()


#define ssSetModelForcingFunction(S, fcn) \
    (S)->states.modelMethods2->mdlForcingFunction = (mdlForcingFunctionFcn)(fcn)
#define ssRunModelForcingFunction(S) \
    (*((voidFcnVoidType)((S)->states.modelMethods2->mdlForcingFunction)))()


#define ssSetModelMassMatrix(S, fcn) \
    (S)->states.modelMethods2->mdlMassMatrix = (mdlMassMatrixFcn)(fcn)
#define ssRunModelMassMatrix(S) (*((voidFcnVoidType)((S)->states.modelMethods2->mdlMassMatrix)))()

#define ssSetModelInitSystemMatrices(S, fcn)                            \
    ((S)->states.modelMethods2->modelMethods3)->mdlInitSystemMatrices = \
        (mdlInitSystemMatricesFcn)(fcn)
#define ssRunModelInitSystemMatrices(S) \
    (*((voidFcnVoidType)(((S)->states.modelMethods2)->mdlInitSystemMatrices)))()

#define ssSetModelRTWCG(S, fcn) (S)->states.modelMethods2->mdlRTWCG = (mdlRTWCGFcn)(fcn)
#define ssRunModelRTWCG(S, iObj) (*((voidFcnVoidType)((S)->states.modelMethods2->mdlRTWCG)))((iObj))


#define ssSetModelZeroCrossings(S, fcn) \
    (S)->modelMethods.sFcn.mdlZeroCrossings = (mdlZeroCrossingsFcn)(fcn)
#define ssRunModelZeroCrossings(S) (*((voidFcnVoidType)((S)->modelMethods.sFcn.mdlZeroCrossings)))()


#define ssGetNumNonContDerivSigInfos(S) ((S)->mdlInfo->numNonContDerivSigInfos)
#define ssSetNumNonContDerivSigInfos(S, n) (S)->mdlInfo->numNonContDerivSigInfos = (n)


#define ssGetNonContDerivSigInfos(S) ((S)->mdlInfo->nonContDerivSigInfos)
#define ssSetNonContDerivSigInfos(S, p) (S)->mdlInfo->nonContDerivSigInfos = (p)

#endif

/*-------------------------------- S->sFunctions ----------------------------*/

#define _ssGetSFunctions(S) (S)->sFunctions /* (SimStruct **)    */
#define _ssSetSFunctions(S, SFunPtr) (S)->sFunctions = (SFunPtr)
#if !SS_SFCN
#define ssSetSFunctions(S, SFunPtr) _ssSetSFunctions(S, SFunPtr)
#else
#define ssSetSFunctions(S, SFunPtr) ssSetSFunctions_cannot_be_used_in_SFunctions
#endif

#define ssGetSFunction(S, sfun) ((S)->sFunctions[sfun]) /* (SimStruct *)     */
#define _ssSetSFunction(S, sfunid, simStruc) (S)->sFunctions[sfunid] = (simStruc)
#if !SS_SFCN
#define ssSetSFunction(S, sfunid, simStruc) _ssSetSFunction(S, sfunid, simStruc)
#else
#define ssSetSFunction(S, sfunid, simStruc) ssSetSFunction_cannot_be_used_in_SFunctions
#endif

/*==============================*
 * Miscellaneous access methods *
 *==============================*/


/*------------------------- ssIsContinuousTask ------------------------------*/


#define ssIsAsyncTID(S, sti) (ssGetSampleTimeTaskID(S, sti) >= ssGetNumRootSampleTimes(S))



/*------------------------- ssSetSampleHitInTask ----------------------------*/
#if SS_MULTITASKING || SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define _ssSetSampleHitInTask(S, task_j, task_i, hit) \
    (S)->mdlInfo->perTaskSampleHits[(task_j) + ((task_i) * (ssGetNumSampleTimes(S)))] = (hit)
#if !SS_SFCN
#define ssSetSampleHitInTask(S, task_j, task_i, hit) _ssSetSampleHitInTask(S, task_j, task_i, hit)
#else
#define ssSetSampleHitInTask(S, task_j, task_i, hit) \
    ssSetSampleHitInTask_cannot_be_used_in_SFunctions
#endif
#endif

/*----------------------- ssIsSpecialSampleHit ------------------------------*/



/* --------------set/get methods for firstInitCondCalled-------------------- */
#define _ssSetFirstInitCondCalled(S, val) ((S)->root->mdlInfo->mdlFlags).firstInitCondCalled = (val)

#if !SS_SFCN
#define ssSetFirstInitCondCalled(S) _ssSetFirstInitCondCalled(S, 1U)
#define ssClearFirstInitCondCalled(S) _ssSetFirstInitCondCalled(S, 0U)
#else
#define ssSetFirstInitCondCalled(S) ssSetFirstInitCondCalled_cannot_be_used_in_SFunctions
#define ssClearFirstInitCondCalled(S) ssClearFirstInitCondCalled_cannot_be_used_in_SFunctions
#endif



/*----------------------- rowMajor ------------------------------*/

#define ssGetArrayLayoutForCodeGen(S) \
    ((S)->blkInfo.sfcnFlags.sCodeGenArrayLayout) /* SSArrayLayout */

#define ssSetSupportedForRowMajorCodeGen(S, val) (S)->blkInfo.sfcnFlags.sRowMajorOptIn = val
#define ssGetSupportedForRowMajorCodeGen(S) ((S)->blkInfo.sfcnFlags.sRowMajorOptIn)

/* Get/Set for Model Param 'RowMajorDimensionSupport */
#define ssIsModelRowMajor(S) ((S)->root->mdlInfo->mdlFlags.isRowMajor)

/*----------------------- representation ------------------------*/
/* This determines how an s-function is used in accelerated simulations (i.e.,
 * whether the s-function is inlined or whether its binary is used etc.)
 */
#define ssGetSFcnRepresentation(S, result)                                                 \
    {                                                                                      \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_SFCN_REPRESENTATION, 0, (result)) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }

#define ssSetSFcnRepresentation(S, val)                                               \
    {                                                                                 \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_SFCN_REPRESENTATION, val, 0) \
            _ssSafelyCallGenericFcnEnd;                                               \
    }

/*----------------------- Reuse Across Models---------------------*/

#define ssSetSupportedForCodeReuseAcrossModels(S, val) \
    (S)->blkInfo.sfcnFlags.sReuseAcrossModels = val
#define ssGetSupportedForCodeReuseAcrossModels(S) ((S)->blkInfo.sfcnFlags.sReuseAcrossModels)

#define ssSetSupportsMultipleExecInstancesForModelRefNormalMode(S, boolVal)        \
    ((S)->blkInfo.sfcnFlags.ssSupportsMultipleExecInstancesForModelRefNormalMode = \
         (boolVal) ? 1U : 0U)
#define ssIsMultipleExecInstancesForModelRefNormalModeSupported(S) \
    ((S)->blkInfo.sfcnFlags.ssSupportsMultipleExecInstancesForModelRefNormalMode == 1U)

#define ssSetUserDataInvariantPostCompile(S, boolVal) \
    ((S)->blkInfo.sfcnFlags.ssUserDataInvariantPostCompile = (boolVal) ? 1U : 0U)
#define ssIsUserDataInvariantPostCompile(S) \
    ((S)->blkInfo.sfcnFlags.ssUserDataInvariantPostCompile == 1U)

#define ssSetCombineCompExecUserData(S, boolVal) \
    ((S)->blkInfo.sfcnFlags.ssCombineCompExecUserData = (boolVal) ? 1U : 0U)
#define ssIsCombineCompExecUserData(S) ((S)->blkInfo.sfcnFlags.ssCombineCompExecUserData == 1U)

/*===========================================================================*
 * The following are for backward compatibility for user written S-functions *
 *===========================================================================*/

#if SS_SFCN_LEVEL_1

#define SS_OPTION_NOT_USING_mexErrMsgTxt SS_OPTION_EXCEPTION_FREE_CODE

#define ssGetChecksum(S) ssGetChecksum0(S)
#define ssSetChecksum(S, val) ssSetChecksum0(S, val)

#define ssGetParamChecksum(S) ssGetChecksum3(S)


/* Macros from Simulink 1.3, Simulink 2.0 */

#define ssGetStatus(S) ssGetErrorStatus(S)
#define ssSetStatus(S, msg) ssSetErrorStatus(S, msg)

#define ssGetSizes(S) ssGetSizesPtr(S)


#define ssGetNumScopes(S) (0.0 /*no-op*/)
#define ssSetNumScopes(S, nScopes) /*do nothing*/

#define ssGetIntgStopTime(S) ssGetSolverStopTime(S)
#define ssSetIntgStopTime(S, stoptime) ssSetSolverStopTime(S, stoptime)

#define ssSetMinorTimeStep(S, b) \
     ssSetSimTimeStep(S,((b)? MINOR_TIME_STEP, MAJOR_TIME_STEP))

#define ssGetPresentTimeEvent(S, sti) ssGetTaskTime(S, sti)
#define ssSetPresentTimeEvent(rootS, sti, t) ssSetTaskTime(rootS, sti, t)

#define ssGetSampleHitEventPtr(S) ssGetSampleHitPtr(S)
#define ssSetSampleHitEventPtr(S, ptr) ssSetSampleHitPtr(S, ptr)

#define ssSetSampleHitEvent(S, sti, hit) ssSetSampleHit(S, sti, hit)

#define ssGetSampleTimeEventPtr(S) ssGetSampleTimePtr(S)
#define ssSetSampleTimeEventPtr(S, ptr) ssSetSampleTimePtr(S, ptr)

#define ssGetSampleTimeEvent(S, sti) ssGetSampleTime(S, sti)
#define ssSetSampleTimeEvent(S, sti, t) ssSetSampleTime(S, sti, t)

#define ssGetOffsetTimeEventPtr(S) ssGetOffsetTimePtr(S)
#define ssSetOffsetTimeEventPtr(S, ptr) ssSetOffsetTimePtr(S, ptr)

#define ssGetOffsetTimeEvent(S, sti) ssGetOffsetTime(S, sti)
#define ssSetOffsetTimeEvent(S, sti, t) ssSetOffsetTime(S, sti, t)

#define ssIsSampleHitEvent(S, sti, tid) ssIsSampleHit(S, sti, tid)

#define ssSetSampleHitEventInTask(rootS, task_j, task_i, hit) \
    ssSetSampleHitInTask(rootS, task_j, task_i, hit)

#define ssIsSpecialSampleHitEvent(S, my_sti, promoted_sti, tid) \
    ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid)


#define ssGetNumInputArgs(S) ssGetNumSFcnParams(S)
#define ssSetNumInputArgs(S, numInputArgs) ssSetNumSFcnParams(S, numInputArgs)

#define ssGetNumArgs(S) ssGetSFcnParamsCount(S)
#define ssSetNumArgs(S, numArgs) ssSetSFcnParamsCount(S, numArgs)

#define ssGetArgPtr(S) ssGetSFcnParamsPtr(S)
#define ssSetArgPtr(S, args) ssSetSFcnParamsPtr(S, args)

#define ssGetArg(S, argNum) ssGetSFcnParam(S, argNum)
#define ssSetArg(S, argIdx, argMat) ssSetSFcnParam(S, argIdx, argMat)

#endif


/*===========================================================================*
 * Dataset Format Logging                                                    *
 *===========================================================================*/

typedef struct {
    void* mmi;
    int_T numRefModelPath;
    const char_T** refModelPath;
    const char_T* name;
    boolean_T forObserver;
    void** ppRet;
} SFcnLoggerCreateDatasetDescriptInfo;

typedef struct {
    int_T hierInfoIdx;
    void** ppRet;
} SFcnLoggerCreateValuesDescriptInfo;

typedef struct {
    void** ppDatasetDesc;
    const char_T* className;
    const char_T* name;
    const char_T* bpath;
    const char_T* chartPath;
    int_T portIdx;
    int_T max_points;
    int_T decimation_val;
    void** ppValDesc;
    void** ppRet;
    const char_T* prop_name;
} SFcnLoggerAddElementDescriptInfo;

typedef struct {
    void** ppDatasetDesc;
    void** ppElementDesc;
    const char_T* name;
    int_T nDims;
    const int_T* dims;
    DTypeId dataType;
    boolean_T complexity;
    SSLoggerInterpMethod interp;
} SFcnLoggerAddTimeseriesDescInfo;

typedef struct {
    void** ppDatasetDesc;
    void** ppRetElementArray;
    const char_T* busName;
    unsigned int* sfOffsets;
    unsigned int sfOffsetsSize;
} SFcnLoggerCreateDatasetFromDescptInfo;

typedef struct {
    const char* propName;
    mxArray* propVal;
    void* pElement;
} SFcnLoggerAddElementPropInfo;

typedef struct {
    void* pwork;
    real_T inputTime;
    const char* inputData;
} SFcnLoggerUpdateLogVarInfo;

#if SS_SFCN && SS_SIM

/** Determine if S-Function Signal Logging is Supported **/
#define ssLoggerSupportsDatasetSignalLogging(S, pFlag)                                         \
    {                                                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_SUPPORTS_SIGNAL_LOGGING, 0, pFlag) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }

/** CREATION STEP 1:  Create a dataset description **/
#define ssLoggerCreateDatasetDescription(S, datasetName, ppSetDesc) \
    _ssLoggerCreateDatasetDescriptWithMMI(S, NULL, 0, NULL, datasetName, ppSetDesc)

#define ssLoggerGetSignalLoggingDatasetDescription(S, ppSetDesc) \
    _ssLoggerCreateDatasetDescriptWithMMI(S, NULL, 0, NULL, NULL, ppSetDesc)

/** For sil/pil logging (start) - Use refPath to specify relative path inside the component **/
#define ssLoggerCreateMdlRefDatasetDescription(S, nRefModelPath, refPath, datasetName, ppSetDesc) \
    _ssLoggerCreateDatasetDescriptWithMMI(S, NULL, nRefModelPath, refPath, datasetName, ppSetDesc)

#define ssLoggerGetMdlRefSignalLoggingDatasetDescription(S, nRefModelPath, refPath, ppSetDesc) \
    _ssLoggerCreateDatasetDescriptWithMMI(S, NULL, nRefModelPath, refPath, NULL, ppSetDesc)

#define ssObserverGetMdlRefObserverDatasetDescription(S, nRefModelPath, refPath, ppSetDesc) \
    _ssCreateObserverDatasetDescriptWithMMI(S, NULL, nRefModelPath, refPath, ppSetDesc)

/** For sil/pil logging (end) **/

#define _ssLoggerCreateDatasetDescriptWithMMI(S, modelMappingInfo, nRefModelPath, refPath,     \
                                              datasetName, ppSetDesc)                          \
    {                                                                                          \
        SFcnLoggerCreateDatasetDescriptInfo info;                                              \
        info.mmi = modelMappingInfo;                                                           \
        info.numRefModelPath = nRefModelPath;                                                  \
        info.refModelPath = refPath;                                                           \
        info.name = datasetName;                                                               \
        info.forObserver = false;                                                              \
        info.ppRet = ppSetDesc;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_CREATE_DATASET_DESCRIPT, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }


/** CREATION STEP 2 (optional):  Create values description (i.e. bus) **/
#define ssLoggerCreateBusValuesDescription(S, busHierInfoIdx, ppValuesDesc)                  \
    {                                                                                        \
        SFcnLoggerCreateValuesDescriptInfo info;                                             \
        info.hierInfoIdx = busHierInfoIdx;                                                   \
        info.ppRet = ppValuesDesc;                                                           \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_CREATE_VALUES_DESCIPT, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                                      \
    }


/** CREATION STEP 3:  Add element descriptions to dataset description **/
#define ssLoggerAddSignalDescription(S, ppSetDesc, elementName, propName, blockPath, portIndex, \
                                     maxPoints, decimation, ppElementDesc)                      \
    {                                                                                           \
        SFcnLoggerAddElementDescriptInfo info;                                                  \
        info.ppDatasetDesc = ppSetDesc;                                                         \
        info.className = NULL;                                                                  \
        info.name = elementName;                                                                \
        info.bpath = blockPath;                                                                 \
        info.chartPath = NULL;                                                                  \
        info.portIdx = portIndex;                                                               \
        info.max_points = maxPoints;                                                            \
        info.decimation_val = decimation;                                                       \
        info.ppValDesc = NULL;                                                                  \
        info.ppRet = ppElementDesc;                                                             \
        info.prop_name = propName;                                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_ELEMENT_DESCRIPT, 0, &info)     \
            _ssSafelyCallGenericFcnEnd;                                                         \
    }


#define ssLoggerAddGenericElementDescription(S, ppSetDesc, elementClassName, elementName,     \
                                             blockPath, maxPoints, decimation, ppElementDesc) \
    {                                                                                         \
        SFcnLoggerAddElementDescriptInfo info;                                                \
        info.ppDatasetDesc = ppSetDesc;                                                       \
        info.className = elementClassName;                                                    \
        info.name = elementName;                                                              \
        info.bpath = blockPath;                                                               \
        info.chartPath = NULL;                                                                \
        info.portIdx = -1;                                                                    \
        info.max_points = maxPoints;                                                          \
        info.decimation_val = decimation;                                                     \
        info.ppValDesc = NULL;                                                                \
        info.ppRet = ppElementDesc;                                                           \
        info.prop_name = NULL;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_ELEMENT_DESCRIPT, 0, &info)   \
            _ssSafelyCallGenericFcnEnd;                                                       \
    }

#define ssLoggerAddSignalDescriptionWithValuesDescription(S, ppSetDesc, elementName, propName,    \
                                                          blockPath, portIndex, maxPoints,        \
                                                          decimation, ppValueDesc, ppElementDesc) \
    {                                                                                             \
        SFcnLoggerAddElementDescriptInfo info;                                                    \
        info.ppDatasetDesc = ppSetDesc;                                                           \
        info.className = NULL;                                                                    \
        info.name = elementName;                                                                  \
        info.bpath = blockPath;                                                                   \
        info.chartPath = NULL;                                                                    \
        info.portIdx = portIndex;                                                                 \
        info.max_points = maxPoints;                                                              \
        info.decimation_val = decimation;                                                         \
        info.ppValDesc = ppValueDesc;                                                             \
        info.ppRet = ppElementDesc;                                                               \
        info.prop_name = propName;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_ELEMENT_DESCRIPT, 0, &info)       \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }

#define ssLoggerAddGenericElementDescriptionWithValuesDescription(                              \
    S, ppSetDesc, elementClassName, elementName, blockPath, maxPoints, decimation, ppValueDesc, \
    ppElementDesc)                                                                              \
    {                                                                                           \
        SFcnLoggerAddElementDescriptInfo info;                                                  \
        info.ppDatasetDesc = ppSetDesc;                                                         \
        info.className = elementClassName;                                                      \
        info.name = elementName;                                                                \
        info.bpath = blockPath;                                                                 \
        info.chartPath = NULL;                                                                  \
        info.portIdx = -1;                                                                      \
        info.max_points = maxPoints;                                                            \
        info.decimation_val = decimation;                                                       \
        info.ppValDesc = ppValueDesc;                                                           \
        info.ppRet = ppElementDesc;                                                             \
        info.prop_name = NULL;                                                                  \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_ELEMENT_DESCRIPT, 0, &info)     \
            _ssSafelyCallGenericFcnEnd;                                                         \
    }

#define ssLoggerAddStateflowElementDescription(S, ppSetDesc, elementClassName, elementName, \
                                               blockPath, chartElementPath, ppValueDesc,    \
                                               ppElementDesc)                               \
    {                                                                                       \
        SFcnLoggerAddElementDescriptInfo info;                                              \
        info.ppDatasetDesc = ppSetDesc;                                                     \
        info.className = elementClassName;                                                  \
        info.name = elementName;                                                            \
        info.bpath = blockPath;                                                             \
        info.chartPath = chartElementPath;                                                  \
        info.portIdx = -1;                                                                  \
        info.max_points = 0;                                                                \
        info.decimation_val = 0;                                                            \
        info.ppValDesc = ppValueDesc;                                                       \
        info.ppRet = ppElementDesc;                                                         \
        info.prop_name = NULL;                                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_ELEMENT_DESCRIPT, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                                     \
    }

/** CREATION STEP 4:  Add timeseries description to a dataset element description **/
#define ssLoggerAddTimeseriesDescriptionWithInterpolation(                                     \
    S, ppSetDesc, ppElementDescript, timeseriesName, signalNdims, signalDims, signalDataType,  \
    signalComplexity, interpMethod)                                                            \
    {                                                                                          \
        SFcnLoggerAddTimeseriesDescInfo info;                                                  \
        info.ppDatasetDesc = ppSetDesc;                                                        \
        info.ppElementDesc = ppElementDescript;                                                \
        info.name = timeseriesName;                                                            \
        info.nDims = signalNdims;                                                              \
        info.dims = signalDims;                                                                \
        info.dataType = signalDataType;                                                        \
        info.complexity = signalComplexity;                                                    \
        info.interp = interpMethod;                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_TIMESERIES_DESCRIPT, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }

#define ssLoggerAddTimeseriesDescription(S, ppSetDesc, ppElementDescript, timeseriesName,         \
                                         signalNdims, signalDims, signalDataType,                 \
                                         signalComplexity)                                        \
    ssLoggerAddTimeseriesDescriptionWithInterpolation(                                            \
        S, ppSetDesc, ppElementDescript, timeseriesName, signalNdims, signalDims, signalDataType, \
        signalComplexity, SS_LINEAR_INTERPOLATION);

/* CREATION STEP 4:  Construct variable from description */
#define ssLoggerCreateElementFromDescription(S, ppSetDesc, elementPtrArray)                  \
    {                                                                                        \
        SFcnLoggerCreateDatasetFromDescptInfo info;                                          \
        info.ppDatasetDesc = ppSetDesc;                                                      \
        info.ppRetElementArray = elementPtrArray;                                            \
        info.busName = NULL;                                                                 \
        info.sfOffsets = NULL;                                                               \
        info.sfOffsetsSize = 0;                                                              \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_CREATE_DATASET_FROM_DESCRIPT, 0, \
                                        &info) _ssSafelyCallGenericFcnEnd;                   \
    }

#define ssLoggerCreateElementFromDescriptionForBus(S, ppSetDesc, busObjName, elementPtrArray, \
                                                   offsetArray, offsetArraySize)              \
    {                                                                                         \
        SFcnLoggerCreateDatasetFromDescptInfo info;                                           \
        info.ppDatasetDesc = ppSetDesc;                                                       \
        info.ppRetElementArray = elementPtrArray;                                             \
        info.busName = busObjName;                                                            \
        info.sfOffsets = offsetArray;                                                         \
        info.sfOffsetsSize = offsetArraySize;                                                 \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_CREATE_DATASET_FROM_DESCRIPT, 0,  \
                                        &info) _ssSafelyCallGenericFcnEnd;                    \
    }

/** CREATION STEP 5 (optional):  Add additional properties to generic element **/
#define ssLoggerAddElementProperty(S, elementPtr, propertyName, propertyVal)            \
    {                                                                                   \
        SFcnLoggerAddElementPropInfo info;                                              \
        info.propName = propertyName;                                                   \
        info.propVal = propertyVal;                                                     \
        info.pElement = elementPtr;                                                     \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_ADD_ELEMENT_PROP, 0, &info) \
            _ssSafelyCallGenericFcnEnd;                                                 \
    }

/** UPDATE **/
#define ssLoggerUpdateTimeseries(S, elementPtr, timeseriesIdx, timeVal, dataPtr)                 \
    {                                                                                            \
        SFcnLoggerUpdateLogVarInfo info;                                                         \
        info.pwork = elementPtr;                                                                 \
        info.inputTime = timeVal;                                                                \
        info.inputData = dataPtr;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_LOGGER_UPDATE_LOGVAR, timeseriesIdx, &info) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }

/**
 *   Implementation of Simulink String S-Function API
 */

#if !SS_SFCN_LEVEL_1

/* Return default buffer size (Bytes) for dynamic (unbounded) string data type. */
#if SS_SIM
#define ssGetDynamicStringDefaultBufferSize(S)                                                   \
    ((size_t)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_STRING_DEFAULT_BUFFER_SIZE, 0, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicStringDefaultBufferSize(S) \
    ssGetDynamicStringDefaultBufferSize_cannot_be_used_in_RTW
#endif

/* Return buffer size (Bytes) for a string data type - N+1 for 'stringtype(N)' or model config
 * setting for 'string'. */
#if SS_SIM
#define ssGetStringDataTypeBufferSize(S, dataTypeId)                                             \
    ((size_t)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_STRING_TYPE_BUFFER_SIZE, dataTypeId, \
                                             NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetStringDataTypeBufferSize(S, dataTypeId) \
    ssGetStringDataTypeBufferSize_cannot_be_used_in_RTW
#endif

/* Return diagnostic setting in model config set for string truncation - Error/Warning/None. */
#if SS_SIM
#define ssGetStringTruncationDiagnosticSetting(S)                                                  \
    ((BDErrorValue)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_STRING_TRUNCATION_DIAGNOSTIC, 0, \
                                                   NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetStringTruncationDiagnosticSetting(S) \
    ssGetStringDataTypeBufferSize_cannot_be_used_in_RTW
#endif

/* Return target language standard */
#if SS_SIM
#define ssGetTargetLangStandard(S)                                                        \
    (_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_STRING_TARGET_LANG_STANDARD, 0, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetTargetLangStandard(S) ssGetTargetLangStandard_cannot_be_used_in_RTW
#endif

/* Needed to pass the information that "we should use cpp string class" to stateflow string. */
#if SS_SIM
#define ssGetUseCppClass(S)                                                              \
    ((bool)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_STRING_USE_CPP_CLASS, 0, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetUseCppClass(S) ssGetUseCppClass_cannot_be_used_in_RTW
#endif

/* Opt-in string support on input port - call after EvalDlgPrms stage */
#if SS_SIM
#define ssSetInputSupportStringDataType(S, portIdx, support)                                     \
    {                                                                                            \
        bool s = support;                                                                        \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_INPUT_SUPPORT_STRING, portIdx, (void*)&s) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }
#else
#define ssSetInputSupportStringDataType(S, portIdx, support) \
    ssSetInputSupportStringDataType_cannot_be_used_in_RTW
#endif

/* Opt-in string support on output port - call after EvalDlgPrms stage  */
#if SS_SIM
#define ssSetOutputSupportStringDataType(S, portIdx, support)                                     \
    {                                                                                             \
        bool s = support;                                                                         \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_OUTPUT_SUPPORT_STRING, portIdx, (void*)&s) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }
#else
#define ssSetOutputSupportStringDataType(S, portIdx, support) \
    ssSetOutputSupportStringDataType_cannot_be_used_in_RTW
#endif

#endif

/**
 *   Implementation of Simulink Half precision S-Function APIs
 *   For internal usage only. The APIs should not be published and accessed by customers
 */

#if !SS_SFCN_LEVEL_1
/* Set whether the specified input port support half precision data type */
#if SS_SIM
#define ssSetInputSupportHalfPrecisionDataType(S, portIdx, support)                          \
    {                                                                                        \
        bool s = support;                                                                    \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_INPUT_SUPPORT_HALFPRECISION, portIdx, \
                                        (void*)&s) _ssSafelyCallGenericFcnEnd;               \
    }
#else
#define ssSetInputSupportHalfPrecisionDataType(S, portIdx, support) \
    ssSetInputSupportHalfPrecisionDataType_cannot_be_used_in_RTW
#endif

/* Set whether the specified output port support half precision data type */
#if SS_SIM
#define ssSetOutputSupportHalfPrecisionDataType(S, portIdx, support)                          \
    {                                                                                         \
        bool s = support;                                                                     \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_OUTPUT_SUPPORT_HALFPRECISION, portIdx, \
                                        (void*)&s) _ssSafelyCallGenericFcnEnd;                \
    }
#else
#define ssSetOutputSupportHalfPrecisionDataType(S, portIdx, support) \
    ssSetOutputSupportHalfPrecisionDataType_cannot_be_used_in_RTW
#endif

#endif


/**
 *   Implementation of Simulink Pointer S-Function API
 */

#define ssIsPointerDataType(S, dataTypeId)                                                    \
    ((bool)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_IS_POINTER_DATA_TYPE, dataTypeId, NULL) \
         _ssSafelyCallGenericFcnEnd)

#define ssGetPointerContainedDataType(S, dataTypeId)                                      \
    ((DTypeId)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_POINTER_CONTAINED_DATA_TYPE, \
                                              dataTypeId, NULL) _ssSafelyCallGenericFcnEnd)

#define ssGetPointerContainedDataComplexity(S, dataTypeId)                  \
    ((ssComplexity)_ssSafelyCallGenericFcnStart(S)(                         \
        S, GEN_FCN_GET_POINTER_CONTAINED_DATA_COMPLEXITY, dataTypeId, NULL) \
         _ssSafelyCallGenericFcnEnd)

#ifdef __cplusplus
extern "C" {
#endif
extern void* _ssGetPointerContainedData(SimStruct* S, DTypeId dTypeId, void* dataArg);
extern size_t _ssGetPointerContainedDataWidth(SimStruct* S, DTypeId dTypeId, void* dataArg);
#ifdef __cplusplus
}
#endif

#define ssGetPointerContainedData(S, dTypeId, dataArg) \
    _ssGetPointerContainedData(S, dTypeId, dataArg)

#define ssGetPointerContainedDataWidth(S, dTypeId, dataArg) \
    _ssGetPointerContainedDataWidth(S, dTypeId, dataArg)

#define ssAddFullBlockPathToStructuralCheckSumForInvariantInput(S, dataTypeId)                \
    ((void)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_BLOCK_PATH_TO_CHECKSUM, dataTypeId, \
                                           NULL) _ssSafelyCallGenericFcnEnd)

#endif

#define ssIsDimensionUnbounded(dim) ((dim) == (INT_MIN + 10))

/*
 * API specific to Simulink solver that needs to be accessed in
 * Rapid accelerator and RSIM
 */


/** @defgroup Dynamic Array
 *  @{
 */

#if !SS_SFCN_LEVEL_1

#ifndef SS_INT32_INF_DIM
#define SS_INT32_INF_DIM (INT_MIN + 10)
#endif

typedef struct DynamicArrayRec_t {
    size_t numDims;
    size_t width;
    void* data;
    const void* constData;
    void* retData;
    size_t* dims;
    const size_t* constDims;
    DTypeId dataTypeId;
} DynamicArrayRec;

typedef struct RegisterDynamicArrayDataTypeRec_t {
    DTypeId dataTypeId;
    DTypeId retDataTypeId;
    int_T* dataDims;
    int_T dataNumDims;
    boolean_T dataIsComplex;
} RegisterDynamicArrayDataTypeRec;

#ifdef __cplusplus
extern "C" {
#endif
extern DTypeId _ssRegisterDynamicArrayDataTypeFcn(SimStruct* S,
                                                  DTypeId containedDataTypeId,
                                                  int_T containedDataNumDims,
                                                  int_T* containedDataDims,
                                                  boolean_T containedDataIsComplex);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssRegisterDynamicArrayDataType(S, containedDataTypeId, containedDataNumDims, \
                                       containedDataDims, containedDataIsComplex)    \
    _ssRegisterDynamicArrayDataTypeFcn(S, containedDataTypeId, containedDataNumDims, \
                                       containedDataDims, containedDataIsComplex)
#else
#define ssRegisterDynamicArrayDataType(S, containedDataTypeId, containedDataNumDims, \
                                       containedDataDims, containedDataIsComplex)    \
    ssRegisterDynamicArrayDataType_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssCreateDynamicArrayForDt(S, dataTypeId, buffer)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_CREATE_DYNAMIC_ARRAY_FOR_DATA_TYPE, dataTypeId, \
                                    buffer) _ssSafelyCallGenericFcnEnd;
#else
#define ssCreateDynamicArrayForDt(S, dataTypeId, buffer) \
    ssCreateDynamicArrayForDt_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssDestroyDynamicArrayForDt(S, dataTypeId, buffer)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_DESTROY_DYNAMIC_ARRAY_FOR_DATA_TYPE, dataTypeId, \
                                    buffer) _ssSafelyCallGenericFcnEnd;
#else
#define ssDestroyDynamicArrayForDt(S, dataTypeId, buffer) \
    ssDestroyDynamicArrayForDt_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssIsDynamicArrayDataType(S, dataTypeId)                                               \
    ((bool)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_IS_DYNAMIC_ARRAY_DATA_TYPE, dataTypeId, \
                                           NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssIsDynamicArrayDataType(S, dataTypeId) ssIsDynamicArrayDataType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayContainedDataType(S, dataTypeId)                                          \
    (_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_TYPE, dataTypeId, \
                                     NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayContainedDataType(S, dataTypeId) \
    ssGetDynamicArrayContainedDataType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayContainedDataNumDimensions(S, dataTypeId)                                 \
    ((size_t)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_NUM_DIMS, \
                                             dataTypeId, NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayContainedDataNumDimensions(S, dataTypeId) \
    ssGetDynamicArrayContainedDataNumDimensions_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayContainedDataComplexity(S, dataTypeId)                   \
    ((ssComplexity)_ssSafelyCallGenericFcnStart(S)(                               \
        S, GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_COMPLEXITY, dataTypeId, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayContainedDataComplexity(S, dataTypeId) \
    ssGetDynamicArrayContainedDataComplexity_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayContainedDataDimensions(S, dtId, dimsArg)                             \
    {                                                                                          \
        DynamicArrayRec slDynamicArrayRec;                                                     \
        slDynamicArrayRec.numDims = 0;                                                         \
        slDynamicArrayRec.width = 0;                                                           \
        slDynamicArrayRec.data = NULL;                                                         \
        slDynamicArrayRec.constData = NULL;                                                    \
        slDynamicArrayRec.retData = NULL;                                                      \
        slDynamicArrayRec.dims = (dimsArg);                                                    \
        slDynamicArrayRec.constDims = NULL;                                                    \
        slDynamicArrayRec.dataTypeId = (dtId);                                                 \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_DIMS, 0,   \
                                        (void*)&slDynamicArrayRec) _ssSafelyCallGenericFcnEnd; \
    }
#else
#define ssGetDynamicArrayContainedDataDimensions \
    ssGetDynamicArrayContainedDataDimensions_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssGetDynamicArrayContainedDataWidth(S, dataTypeId)                                      \
    ((size_t)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_WIDTH, \
                                             dataTypeId, NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayContainedDataWidth \
    ssGetDynamicArrayContainedDataWidth_cannot_be_used_in_RTW
#endif


#if SS_SIM
#define ssGetDynamicArrayContainedDataCurrentDimensions(S, dtId, dataArg, dimsArg)                \
    {                                                                                             \
        DynamicArrayRec slDynamicArrayRec;                                                        \
        slDynamicArrayRec.numDims = 0;                                                            \
        slDynamicArrayRec.width = 0;                                                              \
        slDynamicArrayRec.data = NULL;                                                            \
        slDynamicArrayRec.constData = (dataArg);                                                  \
        slDynamicArrayRec.retData = NULL;                                                         \
        slDynamicArrayRec.dims = (dimsArg);                                                       \
        slDynamicArrayRec.constDims = NULL;                                                       \
        slDynamicArrayRec.dataTypeId = (dtId);                                                    \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_CONTAINED_DATA_CURRENT_DIMS, \
                                        0, (void*)&slDynamicArrayRec) _ssSafelyCallGenericFcnEnd; \
    }
#else
#define ssGetDynamicArrayContainedDataCurrentDimensions \
    ssGetDynamicArrayContainedDataCurrentDimensions_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDynamicArrayContainedDataCurrentDimensions(S, dtId, dataArg, numDimsArg, dimsArg)    \
    {                                                                                             \
        DynamicArrayRec slDynamicArrayRec;                                                        \
        slDynamicArrayRec.numDims = (numDimsArg);                                                 \
        slDynamicArrayRec.width = 0;                                                              \
        slDynamicArrayRec.data = (dataArg);                                                       \
        slDynamicArrayRec.constData = NULL;                                                       \
        slDynamicArrayRec.retData = NULL;                                                         \
        slDynamicArrayRec.dims = NULL;                                                            \
        slDynamicArrayRec.constDims = (dimsArg);                                                  \
        slDynamicArrayRec.dataTypeId = (dtId);                                                    \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_DYNAMIC_ARRAY_CONTAINED_DATA_CURRENT_DIMS, \
                                        0, (void*)&slDynamicArrayRec) _ssSafelyCallGenericFcnEnd; \
    }
#else
#define ssSetDynamicArrayContainedDataCurrentDimensions \
    ssSetDynamicArrayContainedDataCurrentDimensions_cannot_be_used_in_RTW
#endif



#ifdef __cplusplus
extern "C" {
#endif
extern size_t _ssGetDynamicArrayContainedDataCurrentWidthFcn(SimStruct* S,
                                                             DTypeId dtId,
                                                             void* data);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetDynamicArrayContainedDataCurrentWidth(S, dtId, data) \
    _ssGetDynamicArrayContainedDataCurrentWidthFcn(S, dtId, data)
#else
#define ssGetDynamicArrayContainedDataCurrentWidth \
    ssGetDynamicArrayContainedDataCurrentWidth_cannot_be_used_in_RTW
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern void* _ssGetDynamicArrayContainedDataFcn(SimStruct* S, DTypeId dtId, void* data);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetDynamicArrayContainedData(S, dtId, data) \
    _ssGetDynamicArrayContainedDataFcn(S, dtId, data)
#else
#define ssGetDynamicArrayContainedData ssGetDynamicArrayContainedData_cannot_be_used_in_RTW
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern const void* _ssGetInputPortDynamicArrayDataFcn(SimStruct* S, int portIdx);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetInputPortDynamicArrayData(S, portIdx) _ssGetInputPortDynamicArrayDataFcn(S, portIdx)
#else
#define ssGetInputPortDynamicArrayData ssGetInputPortDynamicArrayData_cannot_be_used_in_RTW
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void* _ssGetOutputPortDynamicArrayDataFcn(SimStruct* S, int portIdx);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetOutputPortDynamicArrayData(S, portIdx) _ssGetOutputPortDynamicArrayDataFcn(S, portIdx)
#else
#define ssGetOutputPortDynamicArrayData ssGetOutputPortDynamicArrayData_cannot_be_used_in_RTW
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern const void* _ssGetInputPortDynamicArrayContainedDataFcn(SimStruct* S, int portIdx);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetInputPortDynamicArrayContainedData(S, portIdx) \
    _ssGetInputPortDynamicArrayContainedDataFcn(S, portIdx)
#else
#define ssGetInputPortDynamicArrayContainedData \
    ssGetInputPortDynamicArrayContainedData_cannot_be_used_in_RTW
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern void* _ssGetOutputPortDynamicArrayContainedDataFcn(SimStruct* S, int portIdx);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetOutputPortDynamicArrayContainedData(S, portIdx) \
    _ssGetOutputPortDynamicArrayContainedDataFcn(S, portIdx)
#else
#define ssGetOutputPortDynamicArrayContainedData \
    ssGetOutputPortDynamicArrayContainedData_cannot_be_used_in_RTW
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void* _ssGetDynamicArrayDWorkContainedDataFcn(SimStruct* S, int idx);
#ifdef __cplusplus
}
#endif

#if SS_SIM
#define ssGetDynamicArrayDWorkContainedData(S, idx) _ssGetDynamicArrayDWorkContainedDataFcn(S, idx)
#else
#define ssGetDynamicArrayDWorkContainedData \
    ssGetDynamicArrayDWorkContainedData_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayDWorkContainedDataWidth(S, idx)                                           \
    ((int)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_WIDTH, \
                                          idx, NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayDWorkContainedDataWidth(S, udx) \
    ssGetDynamicArrayDWorkContainedDataWidth_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayDWorkContainedDataComplexSignal(S, idx)                 \
    ((ssComplexity)_ssSafelyCallGenericFcnStart(S)(                              \
        S, GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_COMPLEXITY, idx, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayDWorkContainedDataComplexSignal(S, udx) \
    ssGetDynamicArrayDWorkContainedDataComplexSignal_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayDWorkContainedDataType(S, idx)                                           \
    (_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_TYPE, idx, \
                                     NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayDWorkContainedDataType(S, idx) \
    ssGetDynamicArrayDWorkContainedDataType_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssGetDynamicArrayDWorkContainedDataCurrentDimensions(S, idx, dims)         \
    (_ssSafelyCallGenericFcnStart(S)(                                              \
        S, GEN_FCN_GET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_CURRENT_DIMS, idx, dims) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetDynamicArrayDWorkContainedDataCurrentDimensions(S, idx, dims) \
    ssGetDynamicArrayDWorkContainedDataCurrentDimensions_cannot_be_used_in_RTW
#endif

#if SS_SIM
#define ssSetDynamicArrayDWorkContainedDataCurrentDimensions(S, idx, dims)         \
    (_ssSafelyCallGenericFcnStart(S)(                                              \
        S, GEN_FCN_SET_DYNAMIC_ARRAY_DWORK_CONTAINED_DATA_CURRENT_DIMS, idx, dims) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssSetDynamicArrayDWorkContainedDataCurrentDimensions(S, idx, dims) \
    ssSetDynamicArrayDWorkContainedDataCurrentDimensions_cannot_be_used_in_RTW
#endif

#endif /* !SS_SFCN_LEVEL_1 */

/** @} */ /* end of Dynamic Array */


#include "simulink_solver_api.h"

/*
 * Include rtModel definitions if in RTW and using rtModel
 */
#ifdef USE_RTMODEL
#include "sfcn_bridge.h"
#endif

#endif /* __SIMSTRUC__INTERNAL */

/* EOF: simstruc_internal.h */

/* LocalWords:  SimStruct's NRT NSAMPLE NUMST sfunc sfunctions RSIM sfunction Fxp getters DAE meth
 * LocalWords:  elif ID's EXTLOGTASK ONESHOT ir Lcs dworks dstates fcncall DWork Vec Bds odesup
 * LocalWords:  SlvrJacobianFcn extmode DTypeId SIGSET sigmapdef th th'signal NOSYMBDIMS MExpr
 * LocalWords:  tid's zc intg conds nd resolveCBK vals sti iwork rwork pwork stringtype
 * LocalWords:  nzMax compat SG et AslErrMsg RWork IWork PWork SFunctions untest
 * LocalWords:  versioning NonsampledZCs SlvrJacobian FCSSCtrl fixedpoint CSignal
 * LocalWords:  OptimOpts reusability ny OR'd mxCalloc vxlib ASYNC cycan VxWorks
 * LocalWords:  Async ZOH TRIGSS dlg prms rtp datatype async APIS ints ABus dsm
 * LocalWords:  BPath mrBlk MODELREF submodel modelref UPtrs slvr nxc jc nxd ndx
 * LocalWords:  nx Prev Nonsampled ZCs nonsampled Dirs DState CStates Optim Asl
 * LocalWords:  SINGLETASKING XPC call's DType DerivPort Deriv slexec ssbridge
 * LocalWords:  upcasting rsim sil pil simbridge Symb Wreserved
 */
