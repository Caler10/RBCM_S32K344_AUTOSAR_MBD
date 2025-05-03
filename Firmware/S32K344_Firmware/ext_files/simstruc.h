/* Copyright 1990-2021 The MathWorks, Inc. */

/**
 * @file: simstruc.h
 *
 * @brief S-function Authoring APIs
 *
 * Abstract:
 *      Data structures and access methods for S-functions.
 *
 *      A Simulink model is an S-function.  The SimStruct contains all entry
 *      points within the S-function (e.g. mdlOutputs) as well any data
 *      associated with the S-function.
 *
 *      This file contains details of SimStruct (Simulink data structure)
 *      which is used to store attributes of the model such as pointers to
 *      storage vectors.
 *
 *      Multiple SimStructs are, in general, used by a model. These SimStruct's
 *      are arranged as a "tree". The "root" SimStruct is used by
 *      the Simulink model. There is one child SimStruct for each S-function
 *      block with in the model.
 *
 *      The SimStruct can be used in three environments:
 *        o With MATLAB/Simulink (MATLAB_MEX_FILE)
 *        o With Real-Time Workshop in non-real-time (NRT)
 *        o With Real-Time Workshop in real-time (RT)
 *
 * Defines:
 *      One of the following must be defined.
 *        MATLAB_MEX_FILE    - Must be defined when compiling as a MEX file,
 *                             otherwise must not be defined.
 *        NRT                - Define if creating non-real-time executable
 *        RT                 - Define if creating real-time executable.
 *
 *        See ENVIRONMENT MACROS section below for more info.
 *
 *      Defines which must be declared by the Real-Time Workshop
 *      generated model source.
 *        Simulink_NAME="name"
 *        NSAMPLE_TIMES=n
 *
 *      Defines for use with the Real-Time Workshop (these are configured
 *	by the template makefile, do not add directly to make command):
 *        MULTITASKING       - Optional (use MT for a synonym).
 *        NUMST=n            - Number of sample times in the root SimStruct.
 *        TID01EQ=1 or 0     - Optional. Only define to 1 if sample time task
 *                             id's 0 and 1 have equal rates.
 * =============================================================================
 */

#ifdef __clang__
#pragma clang diagnostic push
#if defined(__has_warning)
#if __has_warning("-Wreserved-id-macro")
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#endif
#endif

#ifndef __SIMSTRUC__
#define __SIMSTRUC__

#include "simstruc_compcond.h"
#include "simstruc_types.h"
#include "simstruc_def.h"
#include "simstruc_debug.h"

/** @defgroup IOPorts Input and Output Ports
 *  @{
 */
/*======================================*
 * Input and Output Ports *
 *======================================*/

/** @ingroup IOPorts
 */

/** @defgroup SignalSpec Signal Specification
 **
 *  @{
 */

/** Signal Specification **/

#if !SS_SFCN_LEVEL_1

/**
 * @brief ssGetNumInputPorts(S)
 *
 * Get the number of input ports that an S-function block has
 * @param  S           SimStruct pointer
 * @return an int_T value indicating the number of input ports
 */
#if !SS_SL_INTERNAL
#define ssGetNumInputPorts(S) (S)->sizes.in.numInputPorts /*(int_T)*/
#endif

/**
 * @brief ssSetNumInputPorts(S, nInputPorts)
 *
 * Specify the number of input ports an S-function block has
 * @param  S           SimStruct pointer
 * @param  nInputPorts number of S-function input port
 * @return the Boolean value true if successful. Otherwise, returns false
 */
#if SS_SFCN_FOR_SIM
#define ssSetNumInputPorts(S, nInputPorts) \
    (*(S)->portInfo.regNumInputPortsFcn)((S)->portInfo.regNumInputPortsFcnArg, nInputPorts)

#elif SS_SFCN_FOR_RTW
/* RTW S-function block */
#define ssSetNumInputPorts(S, nInputPorts) ((_ssSetNumInputPorts(S, nInputPorts)) >= 0)
#elif SS_SL_INTERNAL || SS_RTW_INTERNAL
/* Simulink or RTW model/run-time interface code */
#define ssSetNumInputPorts(S, nInputPorts) ((_ssSetNumInputPorts(S, nInputPorts)) >= 0)
#endif

/**
 * @brief ssGetNumOutputPorts(S)
 *
 * Get the number of output ports that an S-function block has
 * @param  S           SimStruct pointer
 * @return an int_T value indicating the number of output ports
 */
#if !SS_SL_INTERNAL
#define ssGetNumOutputPorts(S) (S)->sizes.out.numOutputPorts /*(int_T)*/
#endif

/**
 * @brief ssSetNumOutputPorts(S, nOutputPorts)
 *
 * Specify the number of output ports an S-function block has
 * @param  S           SimStruct pointer
 * @param  nOutputPorts number of S-function input port
 * @return the Boolean value true if successful. Otherwise, returns false
 */
#if SS_SFCN_FOR_SIM
#define ssSetNumOutputPorts(S, nOutputPorts) \
    (*(S)->portInfo.regNumOutputPortsFcn)((S)->portInfo.regNumOutputPortsFcnArg, nOutputPorts)
#elif SS_SFCN_FOR_RTW
/* RTW S-function block */
#define ssSetNumOutputPorts(S, nOutputPorts) ((_ssSetNumOutputPorts(S, nOutputPorts)) >= 0)
#elif SS_SL_INTERNAL || SS_RTW_INTERNAL
/* Simulink or RTW model/run-time interface code */
#define ssSetNumOutputPorts(S, nOutputPorts) ((_ssSetNumOutputPorts(S, nOutputPorts)) >= 0)
#endif

/**
 * @brief ssGetInputPortDataType
 *
 * Get the data type ID of an input port
 * @param  S     SimStruct pointer
 * @param  port  input port index
 * @return the data type ID for the input port
 */
#define ssGetInputPortDataType(S, port) \
    (S)->portInfo.inputs[(port)].dataTypeId /*     (DTypeId)   */

/**
 * @brief ssSetInputPortDataType
 *
 * Set the data type ID of an input port
 * @param  S     SimStruct pointer
 * @param  port  input port index
 * @param  id    ID of the data type accepted by the input port
 * @return the data type ID specified by id. Returns -1 if id is DYNAMICALLY_TYPED
 */
#define ssSetInputPortDataType(S, port, dTypeId) \
    ((S)->portInfo.inputs[(port)].dataTypeId = (dTypeId))


/**
 * @brief ssGetInputPortComplexSignal
 *
 * Determine whether an input port accepts complex signals
 * @param S    SimStruct pointer
 * @param port input port index
 * @return COMPLEX_YES (1) if port accepts complex signals, COMPLEX_NO (0) if port does
 * not accept complex signals, and COMPLEX_INHERITED (-1) if port inherits its numeric
 * type from the port to which it is connected
 */
#define ssGetInputPortComplexSignal(S, port) \
    (S)->portInfo.inputs[(port)].complexSignal /*   (CSignal_T)    */

/**
 * @brief ssSetInputPortComplexSignal
 *
 * Determine whether an input port accepts complex signals
 * @param S    SimStruct pointer
 * @param port input port index
 * @param csig  Numeric type of the signals accepted by port. Valid values are COMPLEX_NO
 * (real signal), COMPLEX_YES (complex signal), and COMPLEX_INHERITED (numeric type
 * inherited from driving block).
 * @return 1 (COMPLEX_YES), 0 (COMPLEX_NO), or -1 (COMPLEX_INHERITED) depending on
 * the value specified by csig.
 */
#define ssSetInputPortComplexSignal(S, port, csig) \
    (S)->portInfo.inputs[(port)].complexSignal = (csig)

/**
 * @brief ssGetOutputPortComplexSignal
 *
 * Get the numeric type (complex or real) of an output port
 * @param S    SimStruct pointer
 * @param port Index of an output port.
 * @return COMPLEX_YES (1) if port accepts complex signals, COMPLEX_NO (0) if port does
 * not accept complex signals, and COMPLEX_INHERITED (-1) if port inherits its numeric
 * type from the port to which it is connected
 */
#define ssGetOutputPortComplexSignal(S, port) \
    (S)->portInfo.outputs[(port)].complexSignal /* (CSignal_T)  */

/**
 * @brief ssSetInputPortComplexSignal
 *
 * Set the numeric type (real or complex) of an output port
 * @param S    SimStruct pointer
 * @param port Output port index
 * @param csig  Numeric type of the signals accepted by port. Valid values are COMPLEX_NO
 * (real signal), COMPLEX_YES (complex signal), and COMPLEX_INHERITED (numeric type
 * inherited from driving block).
 * @return 1 (COMPLEX_YES), 0 (COMPLEX_NO), or -1 (COMPLEX_INHERITED) depending on
 * the value specified by csig.
 */
#define ssSetOutputPortComplexSignal(S, port, val) \
    (S)->portInfo.outputs[(port)].complexSignal = (val)


/**
 * @brief ssGetInputPortUnit
 *
 * Get unit of input port
 * @param  S     SimStruct pointer
 * @param  port  input port index
 * @return The unit ID of the input port specified by port. This ID is returned
 * from thes sRegisterUnitFromExpr method. Returns DYNAMICALLY_TYPED if the input
 * port inherits its unit.
 */
#define ssGetInputPortUnit(S, port) \
    (S)->blkInfo.blkInfo2->portInfo2->inputUnits[(port)].unitId /*   (UnitId)    */

/**
 * @brief ssSetInputPortUnit
 *
 * Specify unit for input port
 * @param  S     SimStruct pointer
 * @param  port  input port index
 * @param  id    ID of the unit accepted by port. This ID is returned from the
 * ssRegisterUnitFromExpr method
 * @return The unit ID specified by id. Returns -1 if id is DYNAMICALLY_TYPED
 */
#define ssSetInputPortUnit(S, port, val) \
    (S)->blkInfo.blkInfo2->portInfo2->inputUnits[(port)].unitId = (val)

#endif /* !SS_SFCN_LEVEL_1 */

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetInputPortDirectFeedThrough
 *
 * Specify the direct feedthrough status of a block's ports
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose direct feedthrough property is being set.
 * @param    dirFeed       Direct feedthrough status of the block specified by port.
 */
#if !SS_DEBUG_FOR_SIM
#define ssSetInputPortDirectFeedThrough(S, port, dirFeed) \
    (S)->portInfo.inputs[(port)].directFeedThrough = (dirFeed)
#endif
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortDirectFeedThrough
 *
 * Determine whether a port has direct feedthrough
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose direct feedthrough property is being set.
 * @return   The int_T value 1 if the input port specified by the index port has direct feedthrough.
 * Otherwise, returns 0.
 */
#define ssGetInputPortDirectFeedThrough(S, port) \
    (S)->portInfo.inputs[(port)].directFeedThrough /*   (int_T)       */
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortOffsetTime
 *
 * Get the offset time of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose direct feedthrough property is required.
 * @return   A real_T value indicating the offset time of the input port specified by the index
 * inputPortIdx.
 */
#define ssGetInputPortOffsetTime(S, port) \
    ((S)->portInfo.inputs[(port)].offsetTime) /* (real_T)      */

/**
 * @brief ssSetInputPortOffsetTime
 *
 * Specify the offset time of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose direct feedthrough property is being set.
 * @param    val           Offset time.
 * @return   The real_T value of the offset time passed into the macro.
 */
#define ssSetInputPortOffsetTime(S, port, val) \
    (S)->portInfo.inputs[(port)].offsetTime = (val) /* (real_T)      */
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortRequiredContiguous
 *
 * Determine whether the signal elements entering a port must be contiguous
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port.
 * @return   An int_T (1 or 0) or boolean_T (true or false) value indicating
 * if the signal elements entering a port must be contiguous.
 */
#define ssGetInputPortRequiredContiguous(S, port) \
    ((S)->portInfo.inputs[(port)].attributes.contiguity != 0)


/**
 * @brief ssSetInputPortRequiredContiguous
 *
 * Specify that the signal elements entering a port must be contiguous
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port.
 * @param    val           True(1) if signal elements must be contiguous.
 */
#define ssSetInputPortRequiredContiguous(S, port, val) \
    (S)->portInfo.inputs[(port)].attributes.contiguity = ((val) != 0)

#endif

/**
 * @brief ssRegisterUnitFromExpr
 *
 * Register unit from unit expression
 * @param    S             SimStruct representing an S-Function block.
 * @param    expr          Function pointer corresponding to the unit expression for the unit being
 * registered.
 * @param    id            An integer whose value is the numeric unit type identifier after the
 * call to ssRegisterUnitFromExpr.
 */
#if !SS_SFCN_LEVEL_1
#if SS_SIM
typedef struct _ssRegisterUnitFromExprType_tag {
    const char* unitExpr;
    int* unitId;
} ssRegisterUnitFromExprType;
#define ssRegisterUnitFromExpr(S, expr, id)                                    \
    {                                                                          \
        ssRegisterUnitFromExprType _slRegisterUnitFromExprInfo;                \
        _slRegisterUnitFromExprInfo.unitExpr = (expr);                         \
        _slRegisterUnitFromExprInfo.unitId = (id);                             \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REGISTER_UNIT_FROM_EXPR, 0, \
                                        (void*)&_slRegisterUnitFromExprInfo)   \
            _ssSafelyCallGenericFcnEnd;                                        \
    }
#else
#define ssRegisterUnitFromExpr(S, name, id)
#endif
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetOutputPortSampleTime
 *
 * Specify the sample time of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port whose sample time is being set.
 * @param    val           Sample time of the output port.
 * @return   The real_T value of the sample time passed into the macro.
 */
#define ssSetOutputPortSampleTime(S, port, val) \
    (S)->portInfo.outputs[(port)].sampleTime = (val) /* (real_T)      */

/**
 * @brief ssGetOutputPortOffsetTime
 *
 * Get the offset time of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port whose offset time is being set.
 * @return   A real_T value indicating the offset time of the output port specified by the index
 * outputPortIdx.
 */
#define ssGetOutputPortOffsetTime(S, port) \
    ((S)->portInfo.outputs[(port)].offsetTime) /* (real_T)      */

/**
 * @brief ssSetOutputPortOffsetTime
 *
 * Specify the offset time of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port whose offset time is being set.
 * @param    val           Offset time of the output port.
 * @return   The real_T value of the offset time passed into the macro.
 */
#define ssSetOutputPortOffsetTime(S, port, val) \
    (S)->portInfo.outputs[(port)].offsetTime = (val) /* (real_T)      */
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortFrameData
 *
 * Determine whether a port accepts signal frames
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port.
 * @return   A value of type Frame_T, indicating if the input port specified by the index
 * port accepts signal frames.
 */
#define ssGetInputPortFrameData(S, port) \
    CONV_BITS2INT((S)->portInfo.inputs[(port)].attributes.frameData)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortFrameData
 *
 * Determine whether a port outputs signal frames
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @return   A value of type Frame_T, indicating if the output port specified by the index port
 * produces signal frames.
 */
#define ssGetOutputPortFrameData(S, port) \
    CONV_BITS2INT((S)->portInfo.outputs[(port)].attributes.frameData)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortUnit
 *
 * Get unit of output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @return   The unit ID of the output port specified by port.
 * Returns DYNAMICALLY_TYPED if the output port inherits its unit.
 */
#define ssGetOutputPortUnit(S, port) \
    (S)->blkInfo.blkInfo2->portInfo2->outputUnits[(port)].unitId /*   (UnitId)    */

/**
 * @brief ssSetOutputPortUnit
 *
 * Specify unit of output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @param   val           ID of the unit accepted by port. This ID is returned from
 * the ssRegisterUnitFromExpr method.
 * @return   The unit ID specified by id. Returns -1 if id is DYNAMICALLY_TYPED.
 */
#define ssSetOutputPortUnit(S, port, val) \
    (S)->blkInfo.blkInfo2->portInfo2->outputUnits[(port)].unitId = (val)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssAllowSignalsWithMoreThan2D
 *
 * Enable S-function to work with multidimensional signals
 * @param    S             SimStruct representing an S-Function block.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssAllowSignalsWithMoreThan2D(S)                                              \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ALLOW_MORE_THAN_2D_SIGS, 1, NULL) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssAllowSignalsWithMoreThan2D(S)
#endif
#endif

/**
 * @brief ssSetOneBasedIndexInputPort
 *
 * Specify that an input port expects one-based indices
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Input port of the S-function
 */
#if SS_SFCN && SS_SIM
#define ssSetOneBasedIndexInputPort(S, pIdx)                                      \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ONE_BASED_IN_PORT, pIdx, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif

/**
 * @brief ssSetOneBasedIndexOutputPort
 *
 * Specify that an output port expects one-based indices
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port of the S-function
 */
#if SS_SFCN && SS_SIM
#define ssSetOneBasedIndexOutputPort(S, pIdx)                                      \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ONE_BASED_OUT_PORT, pIdx, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif

/**
 * @brief ssSetZeroBasedIndexInputPort
 *
 * Specify that an input port expects zero-based indices
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Input port of the S-function
 */
#if SS_SFCN && SS_SIM
#define ssSetZeroBasedIndexInputPort(S, pIdx)                                      \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ZERO_BASED_IN_PORT, pIdx, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif

/**
 * @brief ssSetZeroBasedIndexOutputPort
 *
 * Specify that an output port expects zero-based indices
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port of the S-function
 */
#if SS_SFCN && SS_SIM
#define ssSetZeroBasedIndexOutputPort(S, pIdx)                                      \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_ZERO_BASED_OUT_PORT, pIdx, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif


#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetInputPortIsContinuousQuantity
 *
 * Specify that an input port expects co-simulation signals that represents continuous quantities
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Input port of the S-function.
 * @param    val           Int or boolean value (0 or 1) that indicates if this port expects
 * a co-simulation signal, which is a discrete-time signal that represents a continuous quantity.
 */
#define ssSetInputPortIsContinuousQuantity(S, port, val) \
    (S)->blkInfo.blkInfo2->portInfo2->inputCoSimAttribute[(port)].isContinuousQuantity = (val)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortIsContinuousQuantity
 *
 * Determine whether an input port expects co-simulation signals that represents continuous
 * quantities
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Input port of the S-function.
 * @return   Int or boolean value (0 or 1) that indicates if this port expects
 * a co-simulation signal, which is a discrete-time signal that represents a continuous quantity.
 */
#define ssGetInputPortIsContinuousQuantity(S, port) \
    ((S)->blkInfo.blkInfo2->portInfo2->inputCoSimAttribute[(port)].isContinuousQuantity == 1U)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetOutputPortIsContinuousQuantity
 *
 * Specify that an output port generates co-simulation signals that represents continuous quantities
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port of the S-function.
 * @param    val           Int or boolean value (0 or 1) that indicates if this port generates
 * a co-simulation signal, which is a discrete-time signal that represents a continuous quantity.
 */
#define ssSetOutputPortIsContinuousQuantity(S, port, val) \
    (S)->blkInfo.blkInfo2->portInfo2->outputCoSimAttribute[(port)].isContinuousQuantity = (val)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortIsContinuousQuantity
 *
 * Determine whether an output port generates co-simulation signals that represents continuous
 * quantities
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port of the S-function.
 * @return   Int or boolean value (0 or 1) that indicates if this port generates
 * a co-simulation signal, which is a discrete-time signal that represents a continuous quantity.
 */
#define ssGetOutputPortIsContinuousQuantity(S, port) \
    ((S)->blkInfo.blkInfo2->portInfo2->outputCoSimAttribute[(port)].isContinuousQuantity == 1U)
#endif

/** @} */ /* end of SignalSpec */

/** @ingroup IOPorts
 */

/** @defgroup SignalDims Signal Dimensions
 **
 *  @{
 */

/** Signal Dimensions **/


#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetInputPortDimensionInfo
 *
 * Specify information about the dimensionality of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port.
 * @param    val           Structure of type DimsInfo_T that specifies the dimensionality of
 * the signals accepted by port.
 * @return   1 if successful; otherwise, 0.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetInputPortDimensionInfo(S, port, val)               \
    (((ssGetRegInputPortDimensionInfoFcn(S)) != NULL)           \
         ? (ssGetRegInputPortDimensionInfoFcn(S))(S, port, val) \
         : (1))
#else /* RTW S-function block */
#define ssSetInputPortDimensionInfo(S, port, val) (1)
#endif
#endif

/**
 * @brief ssSetInputPortDimensionsMode
 *
 * Set the dimensions mode of the input port indexed by pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Index of an input port.
 * @param    value         Enum value corresponding to the ports dimensions mode.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetInputPortDimensionsMode(S, pIdx, value)                                  \
    {                                                                                 \
        DimensionsMode_T val = value;                                                 \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_INPUT_DIMS_MODE, pIdx, &val) \
            _ssSafelyCallGenericFcnEnd;                                               \
    }
#else
#define ssSetInputPortDimensionsMode(S, pIdx, value)
#endif

/**
 * @brief ssSetInputPortDimsSameAsOutputPortDims
 *
 * Set the dimensions of output port outIdx to be equal to the dimensions of input port inpIdx.
 * This method is called from mdlSetWorkWidths
 * @param    S             SimStruct representing an S-Function block.
 * @param    inpIdx        Index of an input port.
 * @param    outIdx        Output port index.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetInputPortDimsSameAsOutputPortDims(S, inpIdx, outIdx)                            \
    {                                                                                        \
        int val = outIdx;                                                                    \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_INPUT_DIMS_SAMEAS_OUTPUT, (inpIdx), \
                                        (&val)) _ssSafelyCallGenericFcnEnd;                  \
    }
#else
#define ssSetInputPortDimsSameAsOutputPortDims(S, inpIdx, outIdx)
#endif


#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetInputPortMatrixDimensions
 *
 * Specify dimension information for an input port that accepts matrix signalsl.
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port
 * @param    val1          Row dimension of matrix signals accepted by port or DYNAMICALLY_SIZED.
 * @param    val2          Column dimension of matrix signals accepted by port or DYNAMICALLY_SIZED.
 */
#if SS_SFCN_FOR_SIM
#if defined(USE_64BIT_FIELDS)
#define ssSetInputPortMatrixDimensions(S, port, val1, val2) \
    (_ssSetInputPortMatrixDimensionsSLSize(S, port, val1, val2))
#elif defined(USE_32BIT_FIELDS)
#define ssSetInputPortMatrixDimensions(S, port, val1, val2) \
    (_ssSetInputPortMatrixDimensions(S, port, val1, val2))
#endif
#else /* RTW S-function block */
#define ssSetInputPortMatrixDimensions(S, port, val1, val2) (1)
#endif
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetInputPortVectorDimension
 *
 * Specify dimension information for an input port that accepts vector signals
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port
 * @param    val           Width of the vector or DYNAMICALLY_SIZED.
 */
#if SS_SFCN_FOR_SIM
#if defined(USE_64BIT_FIELDS)
#define ssSetInputPortVectorDimension(S, port, val) \
    (_ssSetInputPortVectorDimensionSLSize(S, port, val))
#elif defined(USE_32BIT_FIELDS)
#define ssSetInputPortVectorDimension(S, port, val) (_ssSetInputPortVectorDimension(S, port, val))
#endif
#else /* RTW S-function block */
#define ssSetInputPortVectorDimension(S, port, val) (1)
#endif
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortWidth
 *
 * Get the width of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the port whose width is required
 * @return   An int_T value indicating the number of elements in the input signal.
 * If the number of elements is unknown, returns DYNAMICALLY_SIZED.
 */


#if defined(USE_64BIT_FIELDS)
#define ssGetInputPortWidth(S, port) (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].width
#elif defined(USE_32BIT_FIELDS)
#define ssGetInputPortWidth(S, port) (S)->portInfo.inputs[(port)].width
#endif

/**
 * @brief ssSetInputPortWidth
 *
 * Specify the width of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the port whose width is being set.
 * @param    width         Width of the input port.
 */

#if defined(USE_64BIT_FIELDS)
#define ssSetInputPortWidth(S, port, val) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].width = (val)
#elif defined(USE_32BIT_FIELDS)
#define ssSetInputPortWidth(S, port, val) (S)->portInfo.inputs[(port)].width = (val)
#endif

#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssPruneNDMatrixSingletonDims
 *
 * Prune trailing singleton dimensions
 * @param    S             SimStruct representing an S-Function block.
 * @param    dimsInfo      Structure of type DimsInfo_T that specifies the dimensionality of the
 * signals accepted by port.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssPruneNDMatrixSingletonDims(S, dimInfo)                                      \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_PRUN_TRAILING_DIMS, 0, (void*)dimInfo) \
        _ssSafelyCallGenericFcnEnd
#else
#define ssPruneNDMatrixSingletonDims(S, dimInfo)
#endif
#endif

/**
 * @brief ssSetCurrentOutputPortDimensions
 *
 * Set the current size corresponding to dimension dIdx of the output signal at port pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port index being set.
 * @param    dIdx          Index of dimension being set.
 * @param    val           Current size value to set for dimension dIdx.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#if defined(USE_32BIT_FIELDS)
#define ssSetCurrentOutputPortDimensions(S, pIdx, _dIdx, _val)                             \
    {                                                                                      \
        struct _ssVarDimsIdxVal_tag dIdxVal;                                               \
        dIdxVal.dIdx = _dIdx;                                                              \
        dIdxVal.dVal = _val;                                                               \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_CURR_OUTPUT_DIMS, pIdx, &dIdxVal) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
#elif defined(USE_64BIT_FIELDS)
#define ssSetCurrentOutputPortDimensions(S, pIdx, _dIdx, _val)                             \
    {                                                                                      \
        struct _ssVarDimsIdxVal_tag dIdxVal;                                               \
        dIdxVal.dIdx = _dIdx;                                                              \
        dIdxVal.dValSLSize = _val;                                                         \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_CURR_OUTPUT_DIMS, pIdx, &dIdxVal) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
#endif
#else
#define ssSetCurrentOutputPortDimensions(S, pIdx, dIdx, val) \
    _ssSetCurrentOutputPortDimensions(S, pIdx, dIdx, val)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetOutputPortDimensionInfo
 *
 * Specify information about the dimensionality of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port
 * @param    val           Structure of type DimsInfo_T that specifies the dimensionality of the
 * signals emitted by port.
 * @return   1 if successful; otherwise, 0.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetOutputPortDimensionInfo(S, port, val)               \
    (((ssGetRegOutputPortDimensionInfoFcn(S)) != NULL)           \
         ? (ssGetRegOutputPortDimensionInfoFcn(S))(S, port, val) \
         : (1))
#else /* RTW S-function block */
#define ssSetOutputPortDimensionInfo(S, port, val) (1)
#endif
#endif

/**
 * @brief ssSetOutputPortDimensionsMode
 *
 * Set the dimensions mode of the output port indexed by pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port index being polled.
 * @param    value         Enum value corresponding to the ports dimensions mode.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetOutputPortDimensionsMode(S, pIdx, value)                                  \
    {                                                                                  \
        DimensionsMode_T val = value;                                                  \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_OUTPUT_DIMS_MODE, pIdx, &val) \
            _ssSafelyCallGenericFcnEnd;                                                \
    }
#else
#define ssSetOutputPortDimensionsMode(S, pIdx, value)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetOutputPortMatrixDimensions
 *
 * Specify dimension information for an output port that emits matrix signals
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @param    val1          Row dimension of matrix signals emitted by port or DYNAMICALLY_SIZED.
 * @param    val2          Column dimension of matrix signals emitted by port or DYNAMICALLY_SIZED.
 * @return   1 if successful; otherwise, 0.
 */
#if SS_SFCN_FOR_SIM
#if defined(USE_64BIT_FIELDS)
#define ssSetOutputPortMatrixDimensions(S, port, val1, val2) \
    (_ssSetOutputPortMatrixDimensionsSLSize(S, port, val1, val2))
#elif defined(USE_32BIT_FIELDS)
#define ssSetOutputPortMatrixDimensions(S, port, val1, val2) \
    (_ssSetOutputPortMatrixDimensions(S, port, val1, val2))
#endif
#else /* RTW S-function block */
#define ssSetOutputPortMatrixDimensions(S, port, val1, val2) (1)
#endif
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetOutputPortVectorDimension
 *
 * Specify dimension information for an output port that emits vector signals
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @param    val           Width of the vector or DYNAMICALLY_SIZED.
 * @return   1 if successful; otherwise, 0.
 */
#if SS_SFCN_FOR_SIM
#if defined(USE_64BIT_FIELDS)
#define ssSetOutputPortVectorDimension(S, port, val) \
    (_ssSetOutputPortVectorDimensionSLSize(S, port, val))
#elif defined(USE_32BIT_FIELDS)
#define ssSetOutputPortVectorDimension(S, port, val) (_ssSetOutputPortVectorDimension(S, port, val))
#endif
#else /* RTW S-function block */
#define ssSetOutputPortVectorDimension(S, port, val) (1)
#endif
#endif

/**
 * @brief ssGetOutputPortWidth
 *
 * Get the width of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @return   An int_T value indicating the width of the output port specified by the index port.
 */

#if defined(USE_64BIT_FIELDS)
#define ssGetOutputPortWidth(S, port) (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].width
#elif defined(USE_32BIT_FIELDS)
#define ssGetOutputPortWidth(S, port) (S)->portInfo.outputs[(port)].width /*   (int_T)       */
#endif
/**
 * @brief ssSetOutputPortWidth
 *
 * Specify the width of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port whose width is being set.
 * @param    val           Width of an output port
 */

#if defined(USE_64BIT_FIELDS)
#define ssSetOutputPortWidth(S, port, val) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].width = (val)
#elif defined(USE_32BIT_FIELDS)
#define ssSetOutputPortWidth(S, port, val) (S)->portInfo.outputs[(port)].width = (val)
#endif

/**
 * @brief ssAddOutputDimsDependencyRule
 *
 * Register a method to handle current dimensions update.
 * @param    S             SimStruct representing an S-Function block.
 * @param    outIdx        Output port index
 * @param    ruleInfo      Structure containing the dimensions propagation method information.
 */
#if SS_SFCN_FOR_SIM
#define ssAddOutputDimsDependencyRule(S, outIdx, ruleInfo)                                       \
    {                                                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ADD_DIMS_DEPEND_RULE, (outIdx), (ruleInfo)) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }
#else
#define ssAddOutputDimsDependencyRule(S, outIdx, ruleInfo)
#endif

/**
 * @brief ssAddVariableSizeSignalsRuntimeChecker
 *
 * Register a method to check the current input dimensions
 * @param    S             SimStruct representing an S-Function block.
 * @param    checker_type  Enum value corresponding to the checker type.
 */
#if SS_SFCN && SS_SIM
#define ssAddVariableSizeSignalsRuntimeChecker(S, checker_type)                                   \
    {                                                                                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ADD_VARDIMS_RUNTIME_CHECKER, (checker_type), \
                                        NULL) _ssSafelyCallGenericFcnEnd;                         \
    }
#endif

/**
 * @brief ssRegMdlSetInputPortDimensionsModeFcn
 *
 * Register the method to handle dimensions mode propagation for each input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    fcn           Function pointer corresponding to the function being registered.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssRegMdlSetInputPortDimensionsModeFcn(S, fcn)                                       \
    {                                                                                       \
        mdlSetInputPortDimensionsModeFcn _mdlDimsModeFcn = fcn;                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_REG_SET_INPUT_DIMS_MODE_MTH, 0,        \
                                        (void*)_mdlDimsModeFcn) _ssSafelyCallGenericFcnEnd; \
    }
#else
#define ssRegMdlSetInputPortDimensionsModeFcn(S, fcn)
#endif

/**
 * @brief ssSetDWorkRequireResetForSignalSize
 *
 * Set the block flag for resetting the index Dwork size upon subsystem reset.
 * @param    S             SimStruct representing an S-Function block.
 * @param    index         Dwork index.
 * @param    n             Enum value corresponding to the signal size compute type.
 */
#define ssSetDWorkRequireResetForSignalSize(S, index, n) \
    (S)->work.dWorkAux[index].flags.ensureResetForSizeVary = (unsigned int)(n)


/**
 * @brief ssSetSignalSizesComputeType
 *
 * Set the type of ouput dependency on the input signal
 * @param    S             SimStruct representing an S-Function block.
 * @param    type          Enum value corresponding to the signal size compute type.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetSignalSizesComputeType(S, type)                                                   \
    {                                                                                          \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_COMP_VARSIZE_COMPUTE_TYPE, (type), 0) \
            _ssSafelyCallGenericFcnEnd;                                                        \
    }
#else
#define ssSetSignalSizesComputeType(S, type)
#endif


/**
 * @brief ssSetVectorMode
 *
 * Specify the vector mode that an S-function supports
 * @param    S             SimStruct representing an S-Function block.
 * @param    n             Vector mode
 */
#define ssSetVectorMode(S, n) (S)->sizes.flags.vectMode = (n)


/**
 * @brief ssGetCurrentInputPortDimensions
 *
 * Get the current size of dimension dIdx of input port pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Input port index being polled.
 * @param    dIdx          Index of dimension being polled.
 * @return   An int_T value indicating the size of dimension dIdx.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetCurrentInputPortDimensions(S, pIdx, dIdx) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(pIdx)].portVarDims[(dIdx)]
#elif defined(USE_32BIT_FIELDS)
#define ssGetCurrentInputPortDimensions(S, pIdx, dIdx) \
    (S)->blkInfo.blkInfo2->portInfo2->inputs[(pIdx)].portVarDims[(dIdx)]
#endif


/**
 * @brief ssGetCurrentInputPortWidth
 *
 * Get the total width (total number of elements) of the signal at input port pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    portIdx          Input port index being polled.
 * @return   An int_T value indicating the current width of the signal at input port portIdx.
 */
#define ssGetCurrentInputPortWidth(S, portIdx) _ssGetCurrentInputPortWidth(S, portIdx)


#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortDimensions
 *
 * Get the dimensions of the signal accepted by an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port
 * @return   A pointer (int_T *) to an array of integers. The array contains elements with the
 * value DYNAMICALLY_SIZED (-1) when the size of a dimension is unknown.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetInputPortDimensions(S, port) (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims
#elif defined(USE_32BIT_FIELDS)
#define ssGetInputPortDimensions(S, port) ((S)->portInfo.inputs[(port)].dims)
#endif

#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortDimensionSize
 *
 * Get the size of one dimension of the signal entering an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port.
 * @param    dIdx          Index of the dimension.
 * @return   An int_T value indicating the size of dimension, dIdx, at the input port specified by
 * port. Returns 1 if the dIdx is greater than or equal to the number of input port dimensions.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetInputPortDimensionSize(S, port, dIdx)                           \
    ((dIdx) < ssGetInputPortNumDimensions((S), (port))                       \
         ? (S)->blkInfo.blkInfo2->blkInfoSLSize->inputs[(port)].dims[(dIdx)] \
         : 1)
#elif defined(USE_32BIT_FIELDS)
#define ssGetInputPortDimensionSize(S, port, dIdx)                                                 \
    ((dIdx) < ssGetInputPortNumDimensions((S), (port)) ? (S)->portInfo.inputs[(port)].dims[(dIdx)] \
                                                       : 1)
#endif

#endif

/**
 * @brief ssGetInputPortDimensionsMode
 *
 * Get the dimensions mode of the input port indexed by pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Input port index being polled.
 * @return   A DimensionsMode_T value indicating the current dimensions mode.
 * Possible values are INHERIT_DIMS_MODE FIXED_DIMS_MODE and VARIABLE_DIMS_MODE.
 */
#if SS_SIM
#define ssGetInputPortDimensionsMode(S, pIdx) \
    CONV_BITS2DIMSMODE((S)->portInfo.inputs[(pIdx)].attributes.dimensionsMode)
#else
#define ssGetInputPortDimensionsMode(S, pIdx) ssGetInputPortDimensionsMode_cannot_be_used_in_RTW
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortNumDimensions
 *
 * Get the dimensions mode of the signals accepted by an input port.
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port.
 * @return   A positive integer indicating the number of dimensions of the input port specified by
 * the index port, or DYNAMICALLY_SIZED, if the number of dimensions is unknown.
 */
#define ssGetInputPortNumDimensions(S, port)            \
    ((S)->portInfo.inputs[(port)].numDims) /*   (int_T) \
                                            */
#endif


/**
 * @brief ssGetCurrentOutputPortDimensions
 *
 * Get the current size of dimension dIdx of the signal at output port pIdx.
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port index being polled.
 * @param    dIdx          Index of dimension being polled.
 * @return   An int_T value indicating the size of dimension dIdx
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetCurrentOutputPortDimensions(S, pIdx, dIdx) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(pIdx)].portVarDims[(dIdx)]
#elif defined(USE_32BIT_FIELDS)
#define ssGetCurrentOutputPortDimensions(S, pIdx, dIdx) \
    (S)->blkInfo.blkInfo2->portInfo2->outputs[(pIdx)].portVarDims[(dIdx)]
#endif

/**
 * @brief ssGetCurrentOutputPortDimensionsAndRecordIndex
 *
 * Get the current size of dimension dIdx of the signal at output port pIdx and record this port
 * index.
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output port index being polled.
 * @param    dIdx          Index of dimension being polled.
 * @return   An int_T value indicating the size of dimension dIdx
 */
#define ssGetCurrentOutputPortDimensionsAndRecordIndex(S, pIdx, dIdx)                            \
    *((_ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_ADD_OUTPUT_VARDIMS_PORT_INDEX, (pIdx), NULL) \
           _ssSafelyCallGenericFcnEnd)                                                           \
          ? &(ssGetCurrentOutputPortDimensions(S, pIdx, dIdx))                                   \
          : &(ssGetCurrentOutputPortDimensions(S, pIdx, dIdx)))

/**
 * @brief ssGetCurrentOutputPortWidth
 *
 * Get the total (total number of elements) of the signal at output port pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    portIdx          Output port index being polled.
 * @return   An int_T value indicating the current width of the signal at output port portIdx.
 */
#define ssGetCurrentOutputPortWidth(S, portIdx) _ssGetCurrentOutputPortWidth(S, portIdx)


#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortDimensions
 *
 * Get the dimensions of the signal leaving an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port
 * @return   A pointer (int_T *) to an array of integers. The array contains elements with the value
 * DYNAMICALLY_SIZED (-1) when the size of a dimension is unknown.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetOutputPortDimensions(S, port) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims
#elif defined(USE_32BIT_FIELDS)
#define ssGetOutputPortDimensions(S, port) ((S)->portInfo.outputs[(port)].dims)
#endif

/**
 * @brief ssGetOutputPortDimensionSize
 *
 * Get the size of one dimension of the signal leaving an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port.
 * @param    dIdx          Index of the dimension.
 * @return   An int_T value indicating the size of dimension, dIdx, at the output port specified by
 * port. Returns 1 if the dIdx is greater than or equal to the number of output port dimensions.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetOutputPortDimensionSize(S, port, dIdx)                           \
    ((dIdx) < ssGetOutputPortNumDimensions((S), (port))                       \
         ? (S)->blkInfo.blkInfo2->blkInfoSLSize->outputs[(port)].dims[(dIdx)] \
         : 1)
#elif defined(USE_32BIT_FIELDS)
#define ssGetOutputPortDimensionSize(S, port, dIdx)     \
    ((dIdx) < ssGetOutputPortNumDimensions((S), (port)) \
         ? (S)->portInfo.outputs[(port)].dims[(dIdx)]   \
         : 1)
#endif

#endif
/**
 * @brief ssGetOutputPortDimensionsMode
 *
 * Get the dimensions mode of the output port indexed by pIdx
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Output Port index being polled.
 * @return   A DimensionsMode_T value indicating the current dimensions mode. Possible values are
 * INHERIT_DIMS_MODE FIXED_DIMS_MODE and VARIABLE_DIMS_MODE.
 */
#if SS_SIM
#define ssGetOutputPortDimensionsMode(S, pIdx) \
    CONV_BITS2DIMSMODE((S)->portInfo.outputs[(pIdx)].attributes.dimensionsMode)
#else
#define ssGetOutputPortDimensionsMode(S, pIdx) ssGetOutputPortDimensionsMode_cannot_be_used_in_RTW
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortNumDimensions
 *
 * Get the number of dimensions of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port
 * @return   A positive integer indicating the number of dimensions of the output port specified
 * by the index port, or DYNAMICALLY_SIZED, if the number of dimensions is unknown.
 */
#define ssGetOutputPortNumDimensions(S, port) \
    ((S)->portInfo.outputs[(port)].numDims) /*   (int_T) */
#endif

/** @} */ /* end of SignalDims */

/** @defgroup SignalAccess Signal Access
 **
 *  @{
 */

/** Signal Access **/


#if !SS_SFCN_LEVEL_1
#if !SS_DEBUG_FOR_SIM
/**
 * @brief ssGetInputPortBufferDstPort
 *
 * Determine the output port that is sharing this input port's buffer
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port on S
 * @return   The int_T index of the output port that reuses the memory buffer of the input port
 * indicated by the index inputPortIdx. If none of the S-function's output ports reuse this input
 * port buffer, returns INVALID_PORT_IDX (-1).
 */
#define ssGetInputPortBufferDstPort(S, port) \
    ((S)->portInfo.inputs[(port)].bufferDstPort) /* (int_T) */
#endif                                           /* !SS_DEBUG_FOR_SIM */
#endif                                           /* !SS_SFCN_LEVEL_1 */

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortConnected
 *
 * Determine whether a port is connected to a nonvirtual block
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Port whose connected status is needed.
 * @return   Either an int_T (1 or 0) or boolean_T (true or false) value indicating if the
 * input port specified by the index port is connected to a nonvirtual block.
 */
#define ssGetInputPortConnected(S, port) (S)->portInfo.inputs[(port)].connected /* (int_T) */
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortOptimOpts
 *
 * Get the reusability setting of the memory allocated to the input port of an S-function
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port of S.
 * @return   One of the followings: SS_NOT_REUSABLE_AND_GLOBAL,SS_REUSABLE_AND_LOCAL,
 * SS_REUSABLE_AND_GLOBAL, SS_NOT_REUSABLE_AND_LOCAL
 */
#define ssGetInputPortOptimOpts(S, port) ((S)->portInfo.inputs[(port)].attributes.optimOpts)

/**
 * @brief ssSetInputPortOptimOpts
 *
 * Specify reusability of the memory allocated to the input port of an S-function
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port of S.
 * @param    val           One of the followings: SS_NOT_REUSABLE_AND_GLOBAL,SS_REUSABLE_AND_LOCAL,
 * SS_REUSABLE_AND_GLOBAL, SS_NOT_REUSABLE_AND_LOCAL
 */
#define ssSetInputPortOptimOpts(S, port, val) \
    ((S)->portInfo.inputs[(port)].attributes.optimOpts = (val))
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetInputPortOverWritable
 *
 * Determine whether an input port can be overwritten
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port whose overwritability is required.
 * @return   An int_T (1 or 0) or boolean_T (true or false) value indicating if the input port
 * specified by the index port can be overwritten.
 */
#define ssGetInputPortOverWritable(S, port) \
    ((S)->portInfo.inputs[(port)].attributes.overWritable == 1U)

/**
 * @brief ssSetInputPortOverWritable
 *
 * Specify whether one of an S-function's input ports can be overwritten by one of its output ports
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an input port whose overwritability is being set.
 * @param    val           Value specifying whether port is overwritable.
 */
#define ssSetInputPortOverWritable(S, port, val) \
    ((S)->portInfo.inputs[(port)].attributes.overWritable = (val) ? 1U : 0U)
#endif

#if !SS_SFCN_LEVEL_1
#if !SS_DEBUG_FOR_SIM
/**
 * @brief ssGetInputPortSignal
 *
 * Get the address of a contiguous signal entering an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    ip            Index of the port whose address is required.
 * @return   A pointer (void *) to the input port specified by the index ip.
 */
#define ssGetInputPortSignal(S, ip) ((S)->portInfo.inputs[(ip)].signal.vect) /* (const void *) */

/**
 * @brief ssGetInputPortRealSignal
 *
 * Get the address of a real, contiguous signal entering an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    ip            Index of the port whose address is required.
 * @return   A pointer (real_T *) to a real signal on the input port specified by the index ip.
 */
#define ssGetInputPortRealSignal(S, ip) ((const real_T*)ssGetInputPortSignal(S, ip))

/**
 * @brief ssGetInputPortSignalPtrs
 *
 * Get pointers to an input port's signal elements
 * @param    S             SimStruct representing an S-Function block.
 * @param    ip            Index of the input port
 * @return   Pointer to an array of signal element pointers for the specified input port ip.
 */
#define ssGetInputPortSignalPtrs(S, ip) \
    ((S)->portInfo.inputs[(ip)].signal.ptrs) /* (InputPtrsType) */

/**
 * @brief ssGetInputPortRealSignalPtrs
 *
 * Get pointers to signals of type double connected to an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    ip            Index of the input port
 * @return   Pointers to the elements of a signal of type double connected to the input port
 * specified by the index ip.
 */
#define ssGetInputPortRealSignalPtrs(S, ip) ((InputRealPtrsType)ssGetInputPortSignalPtrs(S, ip))
#endif /* __SS_DEBUG_FOR_SIM__ */
#endif /*__!SS_SFCN_LEVEL_1_*/

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortConnected
 *
 * Determine whether an output port is connected to a nonvirtual block
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Port whose connection status is needed.
 * @return   An int_T (1 or 0) or boolean_T (true or false) value indicating if this output port
 * signal is connected to a nonvirtual block.
 */
#define ssGetOutputPortConnected(S, port) (S)->portInfo.outputs[(port)].connected /* (int_T) */
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortBeingMerged
 *
 * Determine whether an output port of this block is connected to a Merge block
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port
 * @return   An int_T (1 or 0) or boolean_T (true or false) value indicating if this output port
 * signal is being merged with other signals.
 */
#define ssGetOutputPortBeingMerged(S, port) \
    ((S)->portInfo.outputs[(port)].attributes.cToMergeBlk == 1U)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortOptimOpts
 *
 * Get the reusability setting of the memory allocated to the output port of an S-function
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port
 * @return   One of the following values: SS_NOT_REUSABLE_AND_GLOBAL,SS_REUSABLE_AND_LOCAL,
 * SS_REUSABLE_AND_GLOBAL, SS_NOT_REUSABLE_AND_LOCAL
 */
#define ssGetOutputPortOptimOpts(S, port) ((S)->portInfo.outputs[(port)].attributes.optimOpts)

/**
 * @brief ssSetOutputPortOptimOpts
 *
 * Specify reusability of the memory allocated to the output port of an S-function
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port
 * @param    val           Permissible values: SS_NOT_REUSABLE_AND_GLOBAL,SS_REUSABLE_AND_LOCAL,
 * SS_REUSABLE_AND_GLOBAL, SS_NOT_REUSABLE_AND_LOCAL
 */
#define ssSetOutputPortOptimOpts(S, port, val) \
    ((S)->portInfo.outputs[(port)].attributes.optimOpts = (val))

#endif
#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetOutputPortRealSignal
 *
 * Get a pointer to an output signal of type double (real_T)
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port
 * @return   A contiguous real_T vector of length equal to the width of the output port.
 */
#define ssGetOutputPortRealSignal(S, port) \
    ((real_T*)(S)->portInfo.outputs[(port)].signalVect) /* (real_T*)       */
#endif

/**
 * @brief ssSetOutputPortOverwritesInputPort
 *
 * Specify whether an output port can share its memory buffer with an input port.
 * @param    S             SimStruct representing an S-Function block.
 * @param    pIdx          Index of the output port.
 * @return   val           Index of the input port.
 */
#if SS_SFCN && SS_SIM
#define ssSetOutputPortOverwritesInputPort(S, pIdx, val)                                     \
    {                                                                                        \
        int inpIdx = val;                                                                    \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_OUTPUT_OVERWRITE_INPUT_IDX, (pIdx), \
                                        (&inpIdx)) _ssSafelyCallGenericFcnEnd;               \
    }
#endif

/** @} */ /* end of SignalAccess */

/** @} */ /* end of InputOutputPorts */


/** @defgroup SampleTime Sample Time
 *  @{
 */
/*======================================*
 * Sample Time *
 *======================================*/

/**
 * @brief ssGetSampleTime
 *
 * Get one of an S-function's sample times
 * @param    S             SimStruct representing an S-Function block.
 * @param    sti           Index of the sample time to be returned.
 * @return   A time_T value indicating the sample time associated with the index sti.
 */
#define ssGetSampleTime(S, sti) (S)->stInfo.sampleTimes[sti] /*   (time_T)      */

/**
 * @brief ssSetSampleTime
 *
 * Set the period of a sample time
 * @param    S             SimStruct representing an S-Function block.
 * @param    sti           Index of the sample time to be set.
 * @param    t             Period of the sample time specified by sti.
 * @return   The time_T sample time value specified by period.
 */
#define ssSetSampleTime(S, sti, t) (S)->stInfo.sampleTimes[sti] = (t)


/**
 * @brief ssGetInputPortSampleTime
 *
 * Get the sample time of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose sample time is required.
 * @return   The real_T value of the sample time of the input port specified by the index port.
 */
#define ssGetInputPortSampleTime(S, port) \
    ((S)->portInfo.inputs[(port)].sampleTime) /* (real_T)      */

/**
 * @brief ssSetInputPortSampleTime
 *
 * Specify the sample time of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose sample time is being set.
 * @param    val           Sample period
 * @return   The real_T value of the sample time passed into the macro.
 */
#define ssSetInputPortSampleTime(S, port, val) \
    (S)->portInfo.inputs[(port)].sampleTime = (val) /* (real_T)      */



/**
 * @brief ssGetNumSampleTimes
 *
 * Get the number of sample times that a block has
 * @param    S             SimStruct representing an S-Function block.
 * @return   An int_T value indicating the total number of port-based and block-based sample times.
 * Returns -1 if the block has unspecified port-based sample times.
 */
#define ssGetNumSampleTimes(S) (S)->sizes.numSampleTimes /*   (int_T)       */

/**
 * @brief ssSetNumSampleTimes
 *
 * Specify the number of sample times that a block has
 * @param    S             SimStruct representing an S-Function block.
 * @param    nSampleTimes  Number of sample times that S has.
 * @return   The number of sample times specified by nSampleTimes, or -1 if PORT_BASED_SAMPLE_TIMES.
 */
#define ssSetNumSampleTimes(S, nSampleTimes) (S)->sizes.numSampleTimes = (nSampleTimes)


/**
 * @brief ssGetOffsetTime
 *
 * Get one of an S-function's sample time offsets.
 * @param    S             SimStruct representing an S-Function block.
 * @param    sti           Index of the sample time whose offset is to be set.
 * @return   A time_T value indicating the sample time offset.
 */
#define ssGetOffsetTime(S, sti) (S)->stInfo.offsetTimes[sti] /*   (time_T)      */

/**
 * @brief ssSetOffsetTime
 *
 * Set the offset time of a block
 * @param    S             SimStruct representing an S-Function block.
 * @param    sti           Index of the sample time whose offset is to be set.
 * @param    offset        Offset of the sample time specified by sti.
 * @return   The time_T offset value specified by offset.
 */
#define ssSetOffsetTime(S, sti, t) (S)->stInfo.offsetTimes[sti] = (t)

/**
 * @brief ssGetTNext
 *
 * Get the time of the next sample hit
 * @param    S             SimStruct representing an S-Function block.
 * @return   A value of type time_T.
 */
#define ssGetTNext(S) (S)->stInfo.tNext /*   (time_T)      */

/**
 * @brief ssSetTNext
 *
 * Set the time of the next sample hit
 * @param    S             SimStruct representing an S-Function block.
 * @param    tnext         Time of the next sample hit.
 */
#define ssSetTNext(S, tnext) (S)->stInfo.tNext = (tnext)

/**
 * @brief ssGetInputPortSampleTimeIndex
 *
 * Get the sample time index of an input port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the input port whose sample time index is to be returned.
 */
#define ssGetInputPortSampleTimeIndex(S, port) \
    (S)->portInfo.inputs[(port)].sampleTimeIndex /* (int_T)       */

/**
 * @brief ssGetOutputPortSampleTime
 *
 * Get the sample time of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port
 * @return   A real_T value indicating the sample time of the output port specified by the index
 * port.
 */
#define ssGetOutputPortSampleTime(S, port) \
    ((S)->portInfo.outputs[(port)].sampleTime) /* (real_T)      */

/**
 * @brief ssGetOutputPortSampleTimeIndex
 *
 * Get the sample time index of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of the output port
 * @return   An int_T value indicating the sample time index for the output port specified by the
 * index outputPortIdx. Returns CONSTANT_TID (-2) for constant (inf) sample times.
 */
#define ssGetOutputPortSampleTimeIndex(S, port) \
    (S)->portInfo.outputs[(port)].sampleTimeIndex /* (int_T)       */



/**
 * @brief ssGetPortBasedSampleTimeBlockIsTriggered
 *
 * Determine whether a block that uses port-based sample times resides in a triggered subsystem
 * @param    S             SimStruct representing an S-Function block.
 * @return   The Boolean value true if S uses port-based sample times and resides in a triggered
 * subsystem. Otherwise, returns false.
 */
#define ssGetPortBasedSampleTimeBlockIsTriggered(S) \
    ((S)->stInfo.sampleTimes[0] == INHERITED_SAMPLE_TIME)

/**
 * @brief ssSetDeepCopyCompliant
 *
 * Set compliant to data types with deep copy
 * @param    S             SimStruct representing an S-Function block.
 * @param    dtype         Logical value indicating whether to allow a datatype with deepcopy
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssSetDeepCopyCompliant(S, flag)                                            \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_DEEPCOPY_COMPLIANT, flag, NULL) \
        _ssSafelyCallGenericFcnEnd
#else

#define ssSetDeepCopyCompliant(S, flag)

#endif


/**
 * @brief ssSetParameterTuningCompliance
 *
 * Specify sample time behavior and tunability for S-function blocks with port-based sample times
 * @param    S             SimStruct representing an S-Function block.
 * @param    flag          Logical value indicating whether to allow a sample time of Inf for
 * ports in the S-function.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

#define ssSetParameterTuningCompliance(S, flag)                                       \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_PRM_TUNING_COMPLIANCE, flag, NULL) \
        _ssSafelyCallGenericFcnEnd
#else

#define ssSetParameterTuningCompliance(S, flag)

#endif


/**
 * @brief ssGetParameterTuningCompliance
 *
 * Get the sample time behavior and tunability for S-function blocks with port-based sample times
 * @param    S             SimStruct representing an S-Function block.
 */
#if SS_SFCN_FOR_SIM
#ifdef __cplusplus
extern "C" {
#endif
extern boolean_T ssGetParameterTuningCompliance(SimStruct* S);
#ifdef __cplusplus
}
#endif
#endif


/**
 * @brief ssIsContinuousTask
 *
 * Determine whether a task is continuous
 * @param    S             SimStruct representing an S-Function block.
 * @param    tid           Task ID
 * @return   The Boolean value true when the simulation is executing the continuous task. Otherwise,
 * returns false.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#if defined(RSIM_WITH_SOLVER_MULTITASKING) && RSIM_WITH_SOLVER_MULTITASKING
#if SS_TID01EQ_EQUAL_ONE
#define ssIsContinuousTask(S, tid) ((tid) <= 1)
#else
#define ssIsContinuousTask(S, tid) ((tid) == 0)
#endif
#else
/*
 * During simulation, tid passed to S-functions is always 0 even in
 * multitasking mode
 */
#define ssIsContinuousTask(S, tid) (((tid) == 0) && (S)->mdlInfo->sampleHits[0])
#endif
#elif SS_TID01EQ_EQUAL_ONE
#define ssIsContinuousTask(S, tid) ((tid) <= 1)
#else
#define ssIsContinuousTask(S, tid) ((tid) == 0)
#endif

/**
 * @brief ssIsSampleHit
 *
 * Determine whether the sample time is hit
 * @param    S             SimStruct representing an S-Function block.
 * @param    sti           Index of the sample time
 * @param    tid           Task ID
 * @return   The Boolean value true when the simulation is executing in the task represented
 * by task ID tid. Otherwise, returns false.
 */
#if SS_MULTITASKING || (defined(RSIM_WITH_SOLVER_MULTITASKING) && RSIM_WITH_SOLVER_MULTITASKING)

#define ssIsSampleHit(S, sti, tid) \
    (!ssIsTIDInStInfo(S, sti) || (ssGetSampleTimeTaskID(S, sti) == (tid)))

#else

#define ssIsSampleHit(S, sti, tid) \
    (((tid) != CONSTANT_TID) &&    \
     (!ssIsTIDInStInfo(S, sti) ||  \
      (ssIsMajorTimeStep(S) && (ssGetSampleHitPtr(S))[ssGetSampleTimeTaskID(S, sti)])))

#endif


/**
 * @brief ssIsSpecialSampleHit
 *
 * Determine whether the sample time is hit
 * @param    S             SimStruct representing an S-Function block.
 * @param    my_sti        Index of the sample time
 * @param    promoted_sti  Index of the sample time
 * @param    tid           Task ID
 * @return   The Boolean value true if a sample hit has occurred at sti1 and a sample hit has
 * also occurred at sti2 in the same time step. Otherwise, returns false.
 */
#if SS_MULTITASKING || SS_SL_INTERNAL || SS_SFCN_FOR_SIM
/*
 * The ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid) macro will be
 * "true" if the block is executing in a major time step in context of a
 * promoted sample time (promoted_sti) and we have a sample hit in the
 * original task (my_sti) which translates to:
 *    1) tid == tid_for(promoted_sti). It is required that this macro be
 *       invoked with in a ssIsSampleHit(S,promoted_sti,tid) to guarantee this
 *       case.
 *    2) Must be major time step.
 *    3) my_sti (the block's sti) has a sample hit at the current point in
 *       time.
 * Valid usage in an S-function would be:
 *	if (ssIsSampleHit(S, promoted_sti)) {
 *        if (ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid)) {
 *        }
 *      }
 * providing promoted_sti is not the continuous task. If promoted_sti is
 * the continuous task, then the following must be used:
 *	if (ssIsContinuousTask(S, promoted_sti)) {
 *        if (ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid)) {
 *        }
 *      }
 *
 * Note, failure to wrap ssIsSpecialSampleHit() within ssIsSampleHit() or
 * ssIsContinuousTask will result in unexpected behavior.
 */
#define ssIsSampleHitInTask(S, my_sti, tid) \
    (ssGetPerTaskSampleHitsPtr(             \
        S))[ssGetSampleTimeTaskID(S, my_sti) + ((tid) * (ssGetNumRootSampleTimes(S)))]

#define ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid) \
    (ssIsMajorTimeStep(S) && ssIsSampleHitInTask(S, my_sti, ssGetSampleTimeTaskID(S, promoted_sti)))
#else
#define ssIsSpecialSampleHit(S, my_sti, promoted_sti, tid) ssIsSampleHit(S, my_sti, tid)
#endif

/**
 * @brief ssSampleAndOffsetAreTriggered
 *
 * Determine whether a sample time and offset value pair indicate a triggered sample time
 * @param    st            The sample time.
 * @param    ot            The offset time.
 * @return   The Boolean value true if both st and ot are equal to INHERITED_SAMPLE_TIME. Otherwise,
 * returns false.
 */
#define ssSampleAndOffsetAreTriggered(st, ot) \
    ((st == INHERITED_SAMPLE_TIME) && (ot == INHERITED_SAMPLE_TIME))

/**
 * @brief ssSampleAndOffsetAreTriggeredOrAsync
 *
 * Determine whether a sample time and offset value pair indicate a triggered or asynchronous sample
 * time
 * @param    st            The sample time.
 * @param    ot            The offset time.
 * @return   The Boolean value true if st is equal to INHERITED_SAMPLE_TIME (-1) and ot is either
 * INHERITED_SAMPLE_TIME (-1) or any other negative integer.
 */
#define ssSampleAndOffsetAreTriggeredOrAsync(st, ot) \
    ((st == INHERITED_SAMPLE_TIME) && (ot <= INHERITED_SAMPLE_TIME))

/**
 * @brief ssSetControllableSampleTime
 *
 * Register controllable sample time in a block
 * @param    S          SimStruct representing an S-Function block
 * @param    sti        Index of the contollable sample time in the block.
 * @param    base       Sample time resolution of the block. This is the smallest time step that the
 * block can take Events of the block can be set to occur at integral multiples of resolution.
 *
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetControllableSampleTime(S, sti, base)                                                \
    {                                                                                            \
        real_T tmp = base;                                                                       \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_CONTROLLABLE_SAMPLE_TIME, (int)sti, &tmp) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }
#else
#define ssSetControllableSampleTime(S, sti, base)
#endif


/** @} */ /* end of SampleTime */

/** @defgroup DataType Data Type
 *  @{
 */

/*======================================*
 * Data Type *
 *======================================*/

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssRegisterDataType
 *
 * Register a custom data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    name          Name of the custom data type.
 * @return   The DTypeId associated with the registered data type.
 *  Otherwise, reports an error and returns INVALID_DTYPE_ID.
 */
#if SS_SIM
#define ssRegisterDataType(S, name)                                       \
    (((S)->regDataType.registerFcn != NULL)                               \
         ? (*(S)->regDataType.registerFcn)((S)->regDataType.arg1, (name)) \
         : (INVALID_DTYPE_ID))
#else
#define ssRegisterDataType(S, name) ssRegisterDataType_cannot_be_used_in_RTW
#endif

/**
 * @brief ssSetDataTypeSize
 *
 * Set the size of a custom data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    id            ID of the data type.
 * @param    size          Size of the custom data type in bytes
 * @return   1 (true) if successful. Otherwise, returns 0 (false).
 */
#if SS_SIM
#define ssSetDataTypeSize(S, id, size)                                         \
    (((S)->regDataType.setSizeFcn != NULL)                                     \
         ? (*(S)->regDataType.setSizeFcn)((S)->regDataType.arg1, (id), (size)) \
         : (0))
#else
#define ssSetDataTypeSize(S, id, size) ssSetDataTypeSize_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetDataTypeSize
 *
 * Get the size of a custom data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    id            ID of the data type.
 * @return   An int_T value indicating the size of the data type specified by id, if id is valid and
 * the data type's size has been set. Otherwise, returns INVALID_DTYPE_SIZE and reports an error.
 */
#if SS_SIM
#define ssGetDataTypeSize(S, id)                                       \
    (((S)->regDataType.getSizeFcn != NULL)                             \
         ? (*(S)->regDataType.getSizeFcn)((S)->regDataType.arg1, (id)) \
         : (INVALID_DTYPE_SIZE))
#else
#define ssGetDataTypeSize(S, id) ssGetDataTypeSize_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetNumDataTypes
 *
 * Get number of data types registered for this simulation, including build-in types
 * @param    S             SimStruct representing an S-Function block.
 * @return   An int_T value indicating the number of registered data types.
 */
#if SS_SIM
#define ssGetNumDataTypes(S) (dtaGetNumDataTypes(ssGetDataTypeAccess(S)))
#else
#define ssGetNumDataTypes(S) ssGetNumDataTypes_cannot_be_used_in_RTW
#endif

/**
 * @brief ssSetDataTypeZero
 *
 * Set the zero representation of a data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    id            ID of the data type.
 * @param    zero          Zero representation of the data type specified by id.
 * @return   1 (true) if successful. Otherwise, returns 0 (false) and reports an error.
 */
#if SS_SIM
#define ssSetDataTypeZero(S, id, zero)                                         \
    (((S)->regDataType.setZeroFcn != NULL)                                     \
         ? (*(S)->regDataType.setZeroFcn)((S)->regDataType.arg1, (id), (zero)) \
         : (0))
#else
#define ssSetDataTypeZero(S, id, zero) ssSetDataTypeZero_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetDataTypeZero
 *
 * Get the zero representation of a data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    id            ID of the data type.
 * @return   A pointer (void *) to the zero representation of the data type specified by id,
 * if id is valid and the data type's size has been set. Otherwise, returns NULL and reports an
 * error.
 */
#if SS_SIM
#define ssGetDataTypeZero(S, id)                                       \
    (((S)->regDataType.getZeroFcn != NULL)                             \
         ? (*(S)->regDataType.getZeroFcn)((S)->regDataType.arg1, (id)) \
         : (NULL))
#else
#define ssGetDataTypeZero(S, id) ssGetDataTypeZero_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetDataTypeId
 *
 * Get the ID of a data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    name          Name of a data type
 * @return   The ID of the custom data type specified by name if name is a registered type name.
 * Otherwise, returns INVALID_DTYPE_ID and reports an error.
 */
#if SS_SIM
#define ssGetDataTypeId(S, name)                                       \
    (((S)->regDataType.getIdFcn != NULL)                               \
         ? (*(S)->regDataType.getIdFcn)((S)->regDataType.arg1, (name)) \
         : (INVALID_DTYPE_ID))
#else
#define ssGetDataTypeId(S, name) ssGetDataTypeId_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetDataTypeName
 *
 * Get the name of a data type
 * @param    S             SimStruct representing an S-Function block.
 * @param    id            ID of a data type.
 * @return   The name of the data type specified by id, if id is valid.
 * Otherwise, returns NULL and reports an error.
 */
#if SS_SIM
#define ssGetDataTypeName(S, id)                                       \
    (((S)->regDataType.getNameFcn != NULL)                             \
         ? (*(S)->regDataType.getNameFcn)((S)->regDataType.arg1, (id)) \
         : (NULL))
#else
#define ssGetDataTypeName(S, id) ssGetDataTypeName_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetDataTypeIdAliasedThruTo
 *
 * Get the base data type associated with a data type alias
 * @param    S             SimStruct representing an S-Function block.
 * @param    id            ID of the data type alias
 * @return   The base data type ID associated with the data type alias specified by id.
 * Otherwise, returns NULL and reports an error.
 */
#if SS_SIM
#define ssGetDataTypeIdAliasedThruTo(S, id) \
    (dtaGetDataTypeIdAliasedThruTo(ssGetDataTypeAccess(S), (S)->path, (id)))
#else
#define ssGetDataTypeIdAliasedThruTo(S, id) ssGetDataTypeIdAliasedThruTo_cannot_be_used_in_RTW
#endif

#endif /* !SS_SFCN_LEVEL_1 */


/**
 * @brief ssGetOutputPortDataType
 *
 * Get the data type of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port
 * @return   The data type ID of the output port specified by the index port.
 * Returns DYNAMICALLY_TYPED if the output port inherits its data type.
 */
#define ssGetOutputPortDataType(S, port) \
    (S)->portInfo.outputs[(port)].dataTypeId /* (DTypeId)     */

/**
 * @brief ssSetOutputPortDataType
 *
 * Set the data type of an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port
 * @param    dTypeId       ID of the data type accepted by port.
 * @return   The data type ID specified by id. Returns -1 if id is DYNAMICALLY_TYPED.
 */
#define ssSetOutputPortDataType(S, port, dTypeId) \
    ((S)->portInfo.outputs[(port)].dataTypeId = (dTypeId))

/**
 * @brief ssGetOutputPortSignal
 *
 * Get the vector of signal elements emitted by an output port
 * @param    S             SimStruct representing an S-Function block.
 * @param    port          Index of an output port
 * @return   A pointer (void *) to the vector of signal elements output at the port specified by the
 * index port.
 */
#define ssGetOutputPortSignal(S, port) \
    (S)->portInfo.outputs[(port)].signalVect /* (void *)        */

/**
 * @brief ssGetSFcnParamDataType
 *
 * Get the data type of a parameter for an S-Function block
 * @param    S             SimStruct representing an S-Function block.
 * @param    index         Index of the target parameter.
 * @param    result        ID of the parameter data type.
 */
#define ssGetSFcnParamDataType(S, index, result)                                          \
    {                                                                                     \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_PARAM_DATATYPE, (index), (result)) \
            _ssSafelyCallGenericFcnEnd;                                                   \
    }

/** @} */ /* end of DataType */

/** @defgroup SimulinkString Simulink String
 *  @{
 */

/*======================================*
 * Simulink String *
 *======================================*/

#if !SS_SFCN_LEVEL_1

/**
 * @brief ssRegisterStringDataType
 *
 * Register string data type
 * @param    S               SimStruct representing an S-Function block.
 * @param    maxStringLength Maximum length of string.
 * @return   The DTypeId associated with the registered data type.
 *  Otherwise, reports an error and returns INVALID_DTYPE_ID.
 */
#if SS_SIM
#define ssRegisterStringDataType(S, maxStringLength)                                            \
    (_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REGISTER_STRING_TYPE, (int_T)(maxStringLength), \
                                     NULL) _ssSafelyCallGenericFcnEnd)
#else
#define ssRegisterStringDataType(S, maxStringLength) ssRegisterStringDataType_cannot_be_used_in_RTW
#endif

/**
 * @brief ssIsStringDataType
 *
 * Determine if data type is string
 * @param    S         SimStruct representing an S-Function block.
 * @param    ID        ID of data type.
 * @return   The Boolean value true if the data type is a string. Otherwise, returns false.
 */
#if SS_SIM
#define ssIsStringDataType(S, ID)                                               \
    ((bool)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_IS_STRING_TYPE, ID, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssIsStringDataType(S, ID) ssIsStringDataType_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetStringDataTypeMaxLength
 *
 * Get maximum length of string data type
 * @param    S         SimStruct representing an S-Function block.
 * @param    ID        ID of data type.
 * @return   A value of type size_T, indicating the maximum length of the string.
 *  Or 0, if the string has no maximum length.
 */
#if SS_SIM
#define ssGetStringDataTypeMaxLength(S, ID)                                                   \
    ((size_t)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_STRING_TYPE_MAX_LENGTH, ID, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetStringDataTypeMaxLength(S, ID) ssGetStringDataTypeMaxLength_cannot_be_used_in_RTW
#endif

/**
 * @brief _ssReadInputStringFcn
 *
 * Read C string from input port (implementation of ssReadInputString)
 * @param    S         SimStruct representing an S-Function block.
 * @param    portIdx   Input port from which to read string.
 * @return   Null-terminated C string read from input port.
 */
#ifdef __cplusplus
extern "C" {
#endif
extern const char_T* _ssReadInputStringFcn(SimStruct* S, int portIdx);
#ifdef __cplusplus
}
#endif

/**
 * @brief ssReadInputString
 *
 * Read C string from input port
 * @param    S         SimStruct representing an S-Function block.
 * @param    portIdx   Input port from which to read string.
 * @return   Null-terminated C string read from input port.
 */
#if SS_SIM
#define ssReadInputString(S, portIdx) _ssReadInputStringFcn(S, portIdx)
#else
#define ssReadInputString(S, ID) ssReadInputString_cannot_be_used_in_RTW
#endif

/**
 * @brief ssGetInputStringLength
 *
 * Get length of string from input port
 * @param    S         SimStruct representing an S-Function block.
 * @param    portIdx   Input port from which to read string.
 * @return   A value of type size_T indicating the length of the input string.
 */
#if SS_SIM
#define ssGetInputStringLength(S, portIdx)                                                      \
    ((size_t)_ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_INPUT_STRING_LENGTH, portIdx, NULL) \
         _ssSafelyCallGenericFcnEnd)
#else
#define ssGetInputStringLength(S, ID) ssGetInputStringLength_cannot_be_used_in_RTW
#endif

/**
 * @brief ssWriteOutputString
 *
 * Write C string to output port
 * @param    S         SimStruct representing an S-Function block.
 * @param    portIdx   Port to which to write string.
 * @param    str       String to write to output port.
 */
#if SS_SIM
#define ssWriteOutputString(S, portIdx, str)                                                \
    {                                                                                       \
        const char_T* s = str;                                                              \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_WRITE_STRING_OUTPUT, portIdx, (void*)&s) \
            _ssSafelyCallGenericFcnEnd;                                                     \
    }
#else
#define ssWriteOutputString(S, ID) ssWriteOutputString_cannot_be_used_in_RTW
#endif

#endif /* !SS_SFCN_LEVEL_1 */

/** @} */ /* end of SimulinkString */

/** @defgroup BlockDialogParam  Block Dialog Parameters
 *  @{
 */

/*======================================*
 * Block Dialog Parameters *
 *======================================*/

/**
 * @brief ssGetDTypeIdFromMxArray
 *
 * Get the data type of an S-function parameter
 * @param    m         MATLAB array representing the parameter
 * @return   The data type ID of an S-function parameter represented by a MATLAB array.
 * Returns INVALID_DTYPE_ID if the MATLAB data type does not map to any built-in Simulink data type
 * ID.
 */
#if SS_SFCN_FOR_SIM
#ifdef __cplusplus
extern "C" {
#endif
extern DTypeId ssGetDTypeIdFromMxArray(const mxArray* m);

#ifdef __cplusplus
}
#endif
#endif


/**
 * @brief ssGetNumSFcnParams
 *
 * Get the number of parameters that an S-Function block expects
 * @param    S        SimStruct representing an S-Function block.
 * @return   An int_T value indicating the number of expected S-function parameters
 */
#define ssGetNumSFcnParams(S) (S)->sizes.numSFcnParams /*   (int_T)       */

/**
 * @brief ssSetNumSFcnParams
 *
 * Specify the number of parameters that an S-Function block has
 * @param    S             SimStruct representing an S-Function block.
 * @param    nSFcnParams   Number of parameters that S has.
 * @return   The number of parameters specified in nSFcnParams.
 */
#define ssSetNumSFcnParams(S, nSFcnParams) (S)->sizes.numSFcnParams = (nSFcnParams)

/**
 * @brief ssGetSFcnParam
 *
 * Get a parameter of an S-Function block
 * @param    S             SimStruct representing an S-Function block.
 * @param    index         Index of the parameter to be returned
 * @return   A pointer (const mxArray *) to the value of the S-function parameter specified by
 * index.
 */
#define ssGetSFcnParam(S, index)                                                     \
    (SS_STATIC_CAST(const mxArray*, _ssGetSFcnParam(S, index))) /* (const mxArray *) \
                                                                 */


/**
 * @brief ssGetSFcnParamsCount
 *
 * Get the number of block dialog parameters that an S-Function block has
 * @param    S             SimStruct representing an S-Function block.
 * @return   An int_T value
 */
#define ssGetSFcnParamsCount(S) (S)->sfcnParams.dlgNum /*   (int_T)       */



/**
 * @brief ssSetSFcnParamTunable
 *
 * Make a block parameter tunable
 * @param    S             SimStruct representing an S-Function block.
 * @param    index         Index of the parameter
 * @param    val           Valid values are SS_PRM_TUNABLE (true / tunable),
 * SS_PRM_NOT_TUNABLE (false / not tunable), or SS_PRM_SIM_ONLY_TUNABLE (tunable only during
 * simulation).
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#define ssSetSFcnParamTunable(S, index, val)                                                      \
    (S)->sfcnParams.dlgAttribs[index] =                                                           \
        (((ssParamTunability)val) == SS_PRM_TUNABLE)                                              \
            ? (((S)->sfcnParams.dlgAttribs[index] & SFCNPARAM_CLEAR_TUNABLE) | SFCNPARAM_TUNABLE) \
            : ((((ssParamTunability)val) == SS_PRM_SIM_ONLY_TUNABLE)                              \
                   ? (((S)->sfcnParams.dlgAttribs[index] & SFCNPARAM_CLEAR_TUNABLE) |             \
                      SFCNPARAM_SIMONLY_TUNABLE)                                                  \
                   : (((S)->sfcnParams.dlgAttribs[index] & SFCNPARAM_CLEAR_TUNABLE) |             \
                      SFCNPARAM_NOT_TUNABLE))
#else                                            /* RT or NRT */
#define ssSetSFcnParamTunable(S, index, boolval) /* do nothing */
#endif

/** @} */ /* end of BlockDialogParam */

/** @defgroup FcnCallSubsystem  Function-Call Subsystems
 *  @{
 */

/*======================================*
 * Function-Call Subsystems *
 *======================================*/

#if SS_RT
#ifdef __cplusplus
extern "C" {
#endif
extern int_T rt_CallSys(SimStruct* S, int_T element, int_T tid);
#ifdef __cplusplus
}
#endif
#define ssCallSystemWithTid(S, element, tid) \
    (((S)->callSys.fcns[(element)] != NULL) ? rt_CallSys((S), (element), (tid)) : 1)
#ifdef __cplusplus
extern "C" {
#endif
extern int_T rt_EnableSys(SimStruct* S, int_T element, int_T tid);
#ifdef __cplusplus
}
#endif
#define ssEnableSystemWithTid(S, element, tid)                                 \
    (((S)->callSys.fcns[ssGetOutputPortWidth((S), 0) + (element)] != NULL ||   \
      (S)->callSys.fcns[2 * ssGetOutputPortWidth((S), 0) + (element)] != NULL) \
         ? rt_EnableSys((S), (element), (tid))                                 \
         : 1)
#ifdef __cplusplus
extern "C" {
#endif
extern int_T rt_DisableSys(SimStruct* S, int_T element, int_T tid);
#ifdef __cplusplus
}
#endif

#define ssDisableSystemWithTid(S, element, tid)                                \
    (((S)->callSys.fcns[3 * ssGetOutputPortWidth((S), 0) + (element)] != NULL) \
         ? rt_DisableSys((S), (element), (tid))                                \
         : 1)
#else /* #if SS_RT */
/**
 * @brief ssCallSystemWithTid
 *
 * Call the update and outputs methods of a function-call subsystem
 * @param    S         SimStruct representing an S-Function block.
 * @param    element   Index of the output port element corresponding to the function-call
 * subsystem.
 * @param    tid       Task ID.
 */
#define ssCallSystemWithTid(S, element, tid)                                            \
    (((S)->callSys.fcns[(element)] != NULL)                                             \
         ? ((*(S)->callSys.fcns[(element)])((S)->callSys.args1[(element)],              \
                                            (S)->callSys.args2[(element)], (tid))       \
                ? ((ssGetErrorStatus(S) == NULL) && (ssGetLocalErrorStatus(S) == NULL)) \
                : (0))                                                                  \
         : (1))

#if defined(RSIM_WITH_SL_SOLVER)
#define ssEnableSystemWithTid(S, element, tid)                                           \
    ((((S)->callSys.fcns[ssGetOutputPortWidth((S), 0) + (element)] != NULL)              \
          ? ((*(S)->callSys.fcns[ssGetOutputPortWidth((S), 0) + (element)])(             \
                 (S)->callSys.args1[(element)], (S)->callSys.args2[(element)], (tid))    \
                 ? ((ssGetErrorStatus(S) == NULL) && (ssGetLocalErrorStatus(S) == NULL)) \
                 : (0))                                                                  \
          : (1)) &                                                                       \
     (((S)->callSys.fcns[2 * ssGetOutputPortWidth((S), 0) + (element)] != NULL)          \
          ? ((*(S)->callSys.fcns[2 * ssGetOutputPortWidth((S), 0) + (element)])(         \
                 (S)->callSys.args1[(element)], (S)->callSys.args2[(element)], (tid))    \
                 ? ((ssGetErrorStatus(S) == NULL) && (ssGetLocalErrorStatus(S) == NULL)) \
                 : (0))                                                                  \
          : (1)))

#define ssDisableSystemWithTid(S, element, tid)                                         \
    (((S)->callSys.fcns[3 * ssGetOutputPortWidth((S), 0) + (element)] != NULL)          \
         ? ((*(S)->callSys.fcns[3 * ssGetOutputPortWidth((S), 0) + (element)])(         \
                (S)->callSys.args1[(element)], (S)->callSys.args2[(element)], (tid))    \
                ? ((ssGetErrorStatus(S) == NULL) && (ssGetLocalErrorStatus(S) == NULL)) \
                : (0))                                                                  \
         : (1))
#else /* #if defined(RSIM_WITH_SL_SOLVER) */

/**
 * @brief ssEnableSystemWithTid
 *
 * Enable a function-call subsystem connected to this S-function
 * @param    S         SimStruct representing an S-Function block.
 * @param    element   Index of the output port element corresponding to the function-call
 * subsystem.
 * @param    tid       Task ID.
 */
#define ssEnableSystemWithTid(S, element, tid)                                          \
    (((S)->callSys.fcns[ssGetOutputPortWidth((S), 0) + (element)] != NULL)              \
         ? ((*(S)->callSys.fcns[ssGetOutputPortWidth((S), 0) + (element)])(             \
                (S)->callSys.args1[(element)], (S)->callSys.args2[(element)], (tid))    \
                ? ((ssGetErrorStatus(S) == NULL) && (ssGetLocalErrorStatus(S) == NULL)) \
                : (0))                                                                  \
         : (1))

/**
 * @brief ssDisableSystemWithTid
 *
 * Disable a function-call subsystem connected to this S-function block
 * @param    S         SimStruct representing an S-Function block.
 * @param    element   Index of the output port element corresponding to the function-call
 * subsystem.
 * @param    tid       Task ID.
 */
#define ssDisableSystemWithTid(S, element, tid)                                         \
    (((S)->callSys.fcns[2 * ssGetOutputPortWidth((S), 0) + (element)] != NULL)          \
         ? ((*(S)->callSys.fcns[2 * ssGetOutputPortWidth((S), 0) + (element)])(         \
                (S)->callSys.args1[(element)], (S)->callSys.args2[(element)], (tid))    \
                ? ((ssGetErrorStatus(S) == NULL) && (ssGetLocalErrorStatus(S) == NULL)) \
                : (0))                                                                  \
         : (1))
#endif /* #if defined(RSIM_WITH_SL_SOLVER) */
#endif /* #if SS_RT */


/**
 * @brief ssGetCallSystemNumFcnCallDestinations
 *
 * Get the number of function-call destinations.
 * @param    S         SimStruct representing an S-Function block.
 * @param    elemIdx   The zero-based element index that is output on the first output port
 * @return   int_T
 */
#define ssGetCallSystemNumFcnCallDestinations(S, elemIdx) \
    _ssGetCallSystemNumFcnCallDestinations(S, elemIdx)


/**
 * @brief ssGetExplicitFCSSCtrl
 *
 * Determine whether this S-function explicitly enables and disables the function-call subsystems
 * that it invokes
 * @param    S         SimStruct representing an S-Function block.
 * @return   The uint_T 1 if S explicitly enables or disables the function-control subsystem that it
 * invokes. Otherwise, returns 0.
 */
#define ssGetExplicitFCSSCtrl(S) (S)->sizes.flags.explicitFCSSCtrl /*   (unsigned int_T: 1) */

/**
 * @brief ssSetExplicitFCSSCtrl
 *
 * Specify whether this S-function explicitly enables and disables the function-call subsystem that
 * it calls
 * @param    S         SimStruct representing an S-Function block.
 * @param    n         1 if this S-function explicitly enables and disables the function-call
 * subsystems it enables
 */
#define ssSetExplicitFCSSCtrl(S, n) (S)->sizes.flags.explicitFCSSCtrl = (n)

/** @} */ /* end of FcnCallSubsystem */

/** @defgroup ModelReference  Model Reference
 *  @{
 */

/*======================================*
 * Model Reference *
 *======================================*/
/**
 * @brief ssRTWGenIsModelReferenceRTWTarget
 *
 * Determine if the model reference Simulink Coder target is generating
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the model reference Simulink Coder target is building.
 * Returns false if the model reference simulation target is building.
 */
#if SS_SIM
#define ssRTWGenIsModelReferenceRTWTarget(S) \
    (ssGetSimMode(S) == SS_SIMMODE_RTWGEN && \
     ((S)->mdlInfo->rtwgenMode == SS_RTWGEN_MODELREFERENCE_RTW_TARGET))
#else
#define ssRTWGenIsModelReferenceRTWTarget(S) (false)
#endif

/**
 * @brief ssRTWGenIsModelReferenceSimTarget
 *
 * Determine if the model reference simulation target is generating
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the model reference Simulation target is building. Returns
 * false if the model reference Simulink Coder target is building.
 */
#if SS_SIM
#define ssRTWGenIsModelReferenceSimTarget(S) \
    (ssGetSimMode(S) == SS_SIMMODE_RTWGEN && \
     ((S)->mdlInfo->rtwgenMode == SS_RTWGEN_MODELREFERENCE_SIM_TARGET))
#else
#define ssRTWGenIsModelReferenceSimTarget(S) (false)
#endif



/**
 * @brief ssSetModelReferenceNormalModeSupport
 *
 * Specify if S-function can be used in referenced model simulating in normal mode
 * @param    S    SimStruct representing an S-Function block.
 * @param    n    Flag for normal mode simulation support when the S-Function block is used in a
 * referenced model.
 */
#define ssSetModelReferenceNormalModeSupport(S, n) (S)->sizes.flags.modelRefNormalModeSupport = (n)

/**
 * @brief ssSetModelReferenceSampleTimeDefaultInheritance
 *
 * Specify that a referenced model containing this S-function can inherit its sample time from its
 * parent model
 * @param    S    SimStruct representing an S-Function block.
 */
#define ssSetModelReferenceSampleTimeDefaultInheritance(S) \
    (S)->sizes.flags.modelRefTsInhSupLevel = USE_DEFAULT_FOR_DISCRETE_INHERITANCE

/**
 * @brief ssSetModelReferenceSampleTimeDisallowInheritance
 *
 * Specify that the use of this S-function in a referenced model prevents the referenced model from
 * inheriting its sample time from its parent model
 * @param    S    SimStruct representing an S-Function block.
 */
#define ssSetModelReferenceSampleTimeDisallowInheritance(S) \
    (S)->sizes.flags.modelRefTsInhSupLevel = DISALLOW_SAMPLE_TIME_INHERITANCE

/**
 * @brief ssSetModelReferenceSampleTimeInheritanceRule
 *
 * Specify whether use of this S-function in a referenced model prevents the referenced model
 * from inheriting its sample time from its parent model
 * @param    S    SimStruct representing an S-Function block.
 * @param    n    Rule for allowing referenced models containing this S-function to inherit
 * their sample times from the parent model.
 */
#define ssSetModelReferenceSampleTimeInheritanceRule(S, n) \
    (S)->sizes.flags.modelRefTsInhSupLevel = (n)


/** @} */ /* end of ModelReference */

/** @defgroup Buses  Buses
 *  @{
 */

/*======================================*
 * Buses *
 *======================================*/

#if SS_SIM
#define ssGetDataTypeAccess(S) ((S)->mdlInfo->dataTypeAccess)
#else
#define ssGetDataTypeAccess(S) ssGetDataTypeAccess_cannot_be_used_in_RTW
#endif

#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
/**
 * @brief ssGetBusElementComplexSignal
 *
 * Get the signal complexity for a bus element
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @param    elemIdx     The zero-based bus element index
 * @return   CSignal_T
 */
#define ssGetBusElementComplexSignal(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementSignalType(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))

/**
 * @brief ssGetBusElementDataType
 *
 * Get the data type identifier for a bus element
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @param    elemIdx     The zero-based bus element index
 * @return   int_T
 */
#define ssGetBusElementDataType(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementDataType(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))

/**
 * @brief ssGetBusElementDimensions
 *
 * Get the dimensions of a bus element
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @param    elemIdx     The zero-based bus element index
 * @return   const int_T*
 */
#define ssGetBusElementDimensions(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementDimensions(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))


/**
 * @brief ssGetBusElementName
 *
 * Get the name of a bus element
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @param    elemIdx     The zero-based bus element index
 * @return   const char*
 */
#define ssGetBusElementName(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementName(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))

/**
 * @brief ssGetBusElementNumDimensions
 *
 * Get the number of dimensions for a bus element
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @param    elemIdx     The zero-based bus element index
 * @return   int_T
 */
#define ssGetBusElementNumDimensions(S, busTypeID, elemIdx)                                \
    (dtaGetDataTypeElementNumDimensions(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), \
                                        (elemIdx)))

/**
 * @brief ssGetBusElementOffset
 *
 * Get the offset from the start of the bus data type to a bus element
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @param    elemIdx     The zero-based bus element index
 * @return   int_T
 */
#define ssGetBusElementOffset(S, busTypeID, elemIdx) \
    (dtaGetDataTypeElementOffset(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID), (elemIdx)))


/**
 * @brief ssGetNumBusElements
 *
 * Get the number of elements in a bus signal
 * @param    S           SimStruct representing an S-Function block.
 * @param    busTypeID   The bus data type identifier that represents the bus signal
 * @return   int_T
 */
#define ssGetNumBusElements(S, busTypeID) \
    (dtaGetDataTypeNumElements(ssGetDataTypeAccess(S), ssGetPath(S), (busTypeID)))


/**
 * @brief ssGetSFcnParamName
 *
 * Get the value of a block parameter for an S-function block
 * @param    S           SimStruct representing an S-Function block.
 * @param    pIdx        The zero-based index into the S-function parameters
 * @param    result      Value of the parameter specified in the block dialog box
 */
#define ssGetSFcnParamName(S, pIdx, result)                                      \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_PARAM_NAME, pIdx, (result)) \
        _ssSafelyCallGenericFcnEnd


/**
 * @brief ssIsDataTypeABus
 *
 * Determine whether a data type identifier represents a bus signal
 * @param    S           SimStruct representing an S-Function block.
 * @param    typeID      The data type identifier that represents a signal
 * @return   int_T       1 for bus, 0 for non-bus, and -1 when error occurs
 */
#define ssIsDataTypeABus(S, typeID) \
    (dtaGetDataTypeIsBus(ssGetDataTypeAccess(S), ssGetPath(S), typeID))

/**
 * @brief ssSetBusInputAsStruct
 *
 * Specify whether to convert the input bus signal for an S-function from virtual to nonvirtual
 * @param    S           SimStruct representing an S-Function block.
 * @param    pIdx        The zero-based index of the input port of the S-function block
 * @param    value       True, if the input signal is a virtual bus and should be converted to a
 * nonvirtual bus; false otherwise
 */
#define ssSetBusInputAsStruct(S, pIdx, value)                                             \
    {                                                                                     \
        boolean_T tmp = value;                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BUS_INPUT_AS_STRUCT, pIdx, &tmp) \
            _ssSafelyCallGenericFcnEnd;                                                   \
    }
/**
 * @brief ssSetBusOutputAsStruct
 *
 * Specify whether the output bus signal from an S-function must be virtual or nonvirtual
 * @param    S           SimStruct representing an S-Function block.
 * @param    pIdx        The zero-based index of the output port of the S-function block
 * @param    value       True, if the output signal is a nonvirtual bus and should be converted to a
 * virtual bus; false otherwise
 */
#define ssSetBusOutputAsStruct(S, pIdx, value)                                             \
    {                                                                                      \
        boolean_T tmp = value;                                                             \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BUS_OUTPUT_AS_STRUCT, pIdx, &tmp) \
            _ssSafelyCallGenericFcnEnd;                                                    \
    }
/**
 * @brief ssSetBusOutputObjectName
 *
 * Specify the name of the bus object that defines the structure and type of the output bus signal
 * @param    S           SimStruct representing an S-Function block
 * @param    pIdx        The zero-based index of the output port of the S-function block
 * @param    name        The name of the bus object
 */
#define ssSetBusOutputObjectName(S, pIdx, name)                                          \
    _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SET_BUS_OUTPUT_OBJECT_NAME, pIdx, name) \
        _ssSafelyCallGenericFcnEnd

#else

#define ssGetBusElementComplexSignal(S, busTypeID, elemIdx) \
    ssGetBusElementComplexSignal_cannot_be_used_in_RTW

#define ssGetBusElementDataType(S, busTypeID, elemIdx) ssGetBusElementDataType_cannot_be_used_in_RTW

#define ssGetBusElementDimensions(S, busTypeID, elemIdx) \
    ssGetBusElementDimensions_cannot_be_used_in_RTW

#define ssGetBusElementName(S, busTypeID, elemIdx) ssGetBusElementName_cannot_be_used_in_RTW

#define ssGetBusElementNumDimensions(S, busTypeID, elemIdx) \
    ssGetBusElementNumDimensions_cannot_be_used_in_RTW

#define ssGetBusElementOffset(S, busTypeID, elemIdx) ssGetBusElementOffset_cannot_be_used_in_RTW

#define ssGetNumBusElements(S, busTypeID) ssGetNumBusElements_cannot_be_used_in_RTW

#define ssGetSFcnParamName(S, pIdx, result)

#define ssIsDataTypeABus(S, typeID) ssIsDataTypeABus_cannot_be_used_in_RTW

#define ssSetBusInputAsStruct(S, pIdx, value)

#define ssSetBusOutputAsStruct(S, pIdx, value)

#define ssSetBusOutputObjectName(S, pIdx, name)

#endif


/**
 * @brief ssSetCallSystemOutput
 *
 * Specify that an output port is issuing a function call.
 * @param    S           SimStruct representing an S-Function block.
 * @param    element     Index of the element of the first output port that is issuing a function
 * call.
 */
#define ssSetCallSystemOutput(S, element) (S)->callSys.outputs[element] = ((int_T)1)



#if !SS_SFCN_LEVEL_1
#if SS_SIM
/**
 * @brief ssRegisterTypeFromParameter
 *
 * Register a data type that a parameter in the Simulink data type table specifies
 * @param    S           SimStruct representing an S-Function block.
 * @param    idx         The zero-based index of the S-function parameter that specifies the bus
 * object name
 * @return   id          A pointer to an int_T that contains the Simulink ID of the newly registered
 * data type
 */
#define ssRegisterTypeFromParameter(S, idx, id)                                               \
    {                                                                                         \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REGISTER_TYPE_FROM_PARAMETER, (idx), (id)) \
            _ssSafelyCallGenericFcnEnd;                                                       \
    }
/**
 * @brief ssRegisterTypeFromParameter
 *
 * Register a custom data type from a Simulink.AliasType, Simulink.NumericType, or Simulink.Bus
 * object.
 * @param    S           SimStruct representing an S-Function block.
 * @param    n           Name of the Simulink object to assign to the custom data type.
 * @return   id          An integer whose value is the numeric data type identifier after the call
 * to ssRegisterTypeFromNamedObject
 */
#define ssRegisterTypeFromNamedObject(S, n, id)                                        \
    {                                                                                  \
        ssRegisterTypeFromNameType _slRegisterTypeFromNameInfo;                        \
        _slRegisterTypeFromNameInfo.name = (n);                                        \
        _slRegisterTypeFromNameInfo.dataTypeId = (id);                                 \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REGISTER_TYPE_FROM_NAMED_OBJECT, 0, \
                                        (void*)&_slRegisterTypeFromNameInfo)           \
            _ssSafelyCallGenericFcnEnd;                                                \
    }

#else
#define ssRegisterTypeFromParameter(S, idx, id)
#define ssRegisterTypeFromNamedObject(S, name, id)
#endif
#endif

/** @} */ /* end of Buses */

/** @defgroup SimulationInformation  Simulation Information
 *  @{
 */

/*======================================*
 * Simulation Information *
 *======================================*/

/**
 * @brief ssSetStateAbsTol
 *
 * Set the absolute tolerance used by a variable-step solver for a specific S-function continuous
 * state.
 * @param    S           SimStruct representing an S-Function block.
 * @param    idx         An index representing an S-function continuous state.
 * @param    val         The value of the absolute tolerance.
 */
#define ssSetStateAbsTol(S, idx, val) _ssSetStateAbsTol(S, idx, val)

/**
 * @brief ssGetStateAbsTol
 *
 * Get the absolute tolerance used by the variable-step solver for a specified state
 * @param    S           SimStruct representing an S-Function block.
 * @param    idx         An index representing an S-function continuous state.
 */
#define ssGetStateAbsTol(S, idx) (const real_T)(((S)->states.statesInfo2)->absTol[idx])

/**
 * @brief ssGetBlockReduction
 *
 * Determine whether a block has requrested block reduction before the simulation has begun
 * and whether it has actually been reduced after the simulation loop has begun
 * @param    S           SimStruct representing an S-Function block.
 */
#define ssGetBlockReduction(S) (S)->sizes.flags.blockReduction /*   (unsigned int_T: 1) */

/**
 * @brief ssSetBlockReduction
 *
 * Request that the Simulink engine attempt to reduce a block
 * @param    S           SimStruct representing an S-Function block.
 * @param    n           If not zero, the Simulink engine should attempt to reduce this block.
 */
#define ssSetBlockReduction(S, n) (S)->sizes.flags.blockReduction = (n)

/**
 * @brief ssSetOperatingPointCompliance
 *
 * Specify the behavior of a Simulink S-function when saving and restoring the operating point of a
 * model containing the given S-function
 * @param    S           SimStruct representing an S-function block.
 * @param    set         Define how to treat an S-function simulation state when saving and
 * restoring the model operating point.
 */
#define ssSetOperatingPointCompliance(S, set) (S)->sizes.flags.simStateCompliance = (set)

/**
 * @brief ssSetOperatingPointVisibility
 *
 * Specify whether to make the S-function's simulation state visible in the operating point of the
 * model.
 * @param    S           SimStruct representing an S-Function block.
 * @param    vis         Option to specify the visibility of the S-function simulation state.
 * The default is false; the simulation state is hidden.
 */
#define ssSetOperatingPointVisibility(S, vis) (S)->sizes.flags.simStateVisibility = (vis)

/**
 * @brief ssGetGetOperatingPointFcn
 *
 * Get the mdlGetOperatingPoint function pointer from simstruct
 * model.
 * @param    S           SimStruct representing an S-Function block.
 */
#define ssGetGetOperatingPointFcn(S) (S)->states.modelMethods2->modelMethods4->mdlGetOperatingPoint

/**
 * @brief ssGetSetOperatingPointFcn
 *
 * Get the mdlSetOperatingPoint function pointer from simstruct
 * model.
 * @param    S           SimStruct representing an S-Function block.
 */
#define ssGetSetOperatingPointFcn(S) (S)->states.modelMethods2->modelMethods4->mdlSetOperatingPoint

/**
 * @brief ssSetSkipContStatesConsistencyCheck
 *
 * Ask Simulink engine to reset solver
 * @param    S           SimStruct representing an S-Function block.
 * @param    val         Boolean value (boolean_T) telling Simulink to skip the continuous state
 * consistency check.
 */
#define ssSetSkipContStatesConsistencyCheck(S, val) \
    ((S)->states.flags.skipContStatesConsistencyCheck = ((val) ? 1U : 0U))

/**
 * @brief ssGetSimStatus
 *
 * Get the current simulation status of an S-function block
 * @param    S           SimStruct representing an S-Function block.
 * @param    result      SS_SimStatus object that returns the current simulation status.
 */
#define ssGetSimStatus(S, result)                                               \
    {                                                                           \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_GET_SIM_STATUS, 0, result) \
            _ssSafelyCallGenericFcnEnd;                                         \
    }

/**
 * @brief ssIsExternalSim
 *
 * Determine if the model is running in the external mode
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the model is running in external mode.
 * Returns false otherwise. Note: if ssGetSimMode returns "external", the result is identical to
 * that of ssIsExternalSim.
 */
#if SS_SIM
#define ssIsExternalSim(S) \
    (ssGetSimMode(S) == SS_SIMMODE_EXTERNAL && ((S)->mdlInfo->rtwgenMode == SS_RTWGEN_RTW_CODE))
#else
#define ssIsExternalSim(S) (false)
#endif


/**
 * @brief ssRTWGenIsAccelerator
 *
 * Determine if the model is running in Accelerator mode.
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the model has compiled or is compiling for Accelerator mode
 * simulation. Returns false otherwise.
 */
#if SS_SIM
#define ssRTWGenIsAccelerator(S) \
    (ssGetSimMode(S) == SS_SIMMODE_RTWGEN && ((S)->mdlInfo->rtwgenMode == SS_RTWGEN_ACCELERATOR))
#else
#define ssRTWGenIsAccelerator(S) (false)
#endif


/**
 * @brief ssIsRapidAcceleratorActive
 *
 * Determine whether the model is running in Rapid Accelerator mode.
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the model is being built or simulated in the Rapid
 * Accelerator mode. Returns false otherwise.
 */
#define ssIsRapidAcceleratorActive(S)                                   \
    ((!(S)->parent) ? ((S)->sizes.flags.isRapidAcceleratorActive == 1U) \
                    : (((S)->parent)->sizes.flags.isRapidAcceleratorActive == 1U))

/**
 * @brief ssGetT
 *
 * Get the current simulation time
 * @param  S       SimStruct representing an S-Function block.
 * @return A value of type time_T indicating the current simulation time.
 */
#define ssGetT(S) (S)->mdlInfo->t[0] /*   (time_T)      */

/**
 * @brief ssGetTStart
 *
 * Get the simulation start time
 * @param  S       SimStruct representing an S-Function block.
 * @return A value of type time_T.
 */
#define ssGetTStart(S) (S)->mdlInfo->tStart /*   (time_T)      */

/**
 * @brief ssGetTFinal
 *
 * Get the simulation stop time
 * @param  S       SimStruct representing an S-Function block.
 * @return A value of type time_T.
 */
#define ssGetTFinal(S) (S)->mdlInfo->tFinal /*   (time_T)      */


/**
 * @brief ssGetStopRequested
 *
 * Get the value of the simulation stop requested flag
 * @param    S           SimStruct representing an S-Function block or a Simulink model.
 * @return   The int_T value of the simulation stop requested flag.
 */
#define ssGetStopRequested(S) (S)->mdlInfo->stopRequested /*   (int_T)   */
/**
 * @brief ssSetStopRequested
 *
 * Set the simulation stop requested flag
 * @param    S           SimStruct representing an S-Function block or a Simulink model
 * @param    val         Boolean value (int_T) specifying whether stopping the simulation has been
 * requested (1) or not (0).
 */
#if SS_SFCN && SS_SFCN_FOR_SIM
#define ssSetStopRequested(S, val)                                                        \
    {                                                                                     \
        boolean_T val2 = (val);                                                           \
        _ssSafelyCallConstGenericFcnStart(S)((((const SimStruct*)(S))),                   \
                                             GEN_FCN_SET_STOP_REQUESTED_SFUN, 0, &(val2)) \
            _ssSafelyCallGenericFcnEnd;                                                   \
        (S)->mdlInfo->stopRequested = (val);                                              \
    }
#else
#define ssSetStopRequested(S, val) (S)->mdlInfo->stopRequested = (val)
#endif

/**
 * @brief ssGetSimMode
 *
 * Get the simulation mode of an S-Function block
 * @param    S           SimStruct representing an S-Function block or a Simulink model
 * @return   An enumerated value of type SS_SimMode
 */
#define ssGetSimMode(S) (S)->mdlInfo->simMode /* (SS_SimMode)    */

/**
 * @brief ssGetSolverName
 *
 * Get the name of the solver being used to solve the S-function
 * @param    S           SimStruct representing an S-Function block or a Simulink model
 * @return   A pointer (char_T *) to the name of the solver being used.
 */
#define ssGetSolverName(S) (S)->mdlInfo->solverName /*   (char_T *)    */


/**
 * @brief ssIsVariableStepSolver
 *
 * Determine if a variable-step solver is being used to solve the S-function
 * @param    S           SimStruct representing an S-Function block or a Simulink model
 * @return   The Boolean value true if the solver being used to solve S is a variable-step solver.
 * Otherwise, returns false.
 */
#define ssIsVariableStepSolver(S) (S)->mdlInfo->variableStepSolver /*   (int_T *)  */


/**
 * @brief ssSetSolverNeedsReset
 *
 * Ask Simulink engine to reset solver
 * @param    S           SimStruct representing an S-Function block or a Simulink model.
 */
#define ssSetSolverNeedsReset(S) (S)->mdlInfo->solverNeedsReset = ((int_T)1)


/**
 * @brief ssSetContTimeOutputInconsistentWithStateAtMajorStep
 *
 * Notify Simulink that the block's continuous outputs have become inconsistent since the last call
 * to mdlOutputs (even though time and inputs many have not changed). This call will force Simulink
 * to re-evaluate this block's continuous outputs at the beginning of the next integration step.
 *
 * @param    S           SimStruct representing an S-Function block or a Simulink model.
 */
#define ssSetContTimeOutputInconsistentWithStateAtMajorStep(S) \
    (S)->mdlInfo->mdlFlags.cTimeOutputInconsistentWithStateAtMajorStep = 1U


/**
 * @brief ssSetContTimeOutputInconsistentWithStateAtMajorStep
 *
 * Notify Simulink that the block's continuous states have changed at the current major time
 * step. This call will force Simulink to reset solver data based on cached values of the continuous
 * states at the beginning of the next integration step.
 *
 * @param    S           SimStruct representing an S-Function block or a Simulink model.
 */
#define ssSetBlockStateForSolverChangedAtMajorStep(S) \
    (S)->mdlInfo->mdlFlags.blockStateForSolverChangedAtMajorStep = 1U


/**
 * @brief ssGetSolverMode
 *
 * Get solver mode
 * @param    S           SimStruct representing an S-Function block or a Simulink model.
 */
#define ssGetSolverMode(S) (S)->mdlInfo->solverMode /*   (SolverMode)   */


/**
 * @brief ssGetFixedStepSize
 *
 * Get the fixed step size of the model containing the S-function.
 * @param    S           SimStruct representing an S-Function block.
 */
#define ssGetFixedStepSize(S) (S)->mdlInfo->fixedStepSize /*   (time_T)      */

/**
 * @brief ssIsFirstInitCond
 *
 * Determine whether the simulation time is equal to the start time.
 * @param    S             SimStruct representing an S-Function block.
 * @return   The Boolean value true if the current simulation time is equal to the simulation start
 * time. Otherwise, returns false.
 */
#define ssIsFirstInitCond(S) (!(((S)->root->mdlInfo->mdlFlags).firstInitCondCalled))

#if !defined(ENABLE_SLEXEC_SSBRIDGE)

#define ssGetGlobalInitialStatesAvailable(S) 0

#endif

/**
 * @brief ssIsMinorTimeStep
 *
 * Determine whether the simulation is in a minor step
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the simulation is in a minor time step. Otherwise, returns
 * false.
 */
#define ssIsMinorTimeStep(S) ((S)->mdlInfo->simTimeStep == MINOR_TIME_STEP) /*  (int_T)    */


/**
 * @brief ssIsMajorTimeStep
 *
 * Determine whether the simulation is in a major step
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the simulation is in a major time step. Otherwise, returns
 * false.
 */
#define ssIsMajorTimeStep(S) ((S)->mdlInfo->simTimeStep == MAJOR_TIME_STEP) /*  (int_T)    */

/**
 * @brief ssIsModeUpdateTimeStep
 *
 * Determine whether the simulation is in a mode update time step
 * @param    S           SimStruct representing an S-Function block.
 * @return   The Boolean value true if the simulation is in a mode update time step. Otherwise,
 * returns false.
 */

#define ssIsModeUpdateTimeStep(S) \
    ((S)->mdlInfo->simTimeStep == MAJOR_TIME_STEP || ssIsMinorTimeStepWithModeChange(S))


/**
 * @brief ssSetNeedAbsoluteTime
 *
 * Register whether the block requires absolute time
 * @param    S          SimStruct representing an S-Function block
 * @param    n          Boolean flag indicating whether the block must use absolute time
 *
 */
#define ssSetNeedAbsoluteTime(S, n) (S)->sizes.flags.needAbsoluteTime = (n)

/**
 * @brief ssGetNeedAbsoluteTime
 *
 * Determine whether the block requires absolute time
 * @param    S          SimStruct representing an S-Function block
 * @return   The Boolean value true if the block uses absolute time
 *
 */
#define ssGetNeedAbsoluteTime(S) (S)->sizes.flags.needAbsoluteTime

/**
 * @brief ssSetNeedElapseTime
 *
 * Register whether the block requires elapse time
 * @param    S          SimStruct representing an S-Function block
 * @param    n          Boolean flag indicating whether the block must use elapse time
 *
 */
#define ssSetNeedElapseTime(S, n) (S)->sizes.flags.needElapseTime = (n)

/**
 * @brief ssGetNeedElapseTime
 *
 * Determine whether the block requires elapse time
 * @param    S          SimStruct representing an S-Function block
 * @return   The Boolean value true if the block uses elapse time
 *
 */
#define ssGetNeedElapseTime(S) (S)->sizes.flags.needElapseTime

/**
 * @brief ssGetElapseTime
 *
 * Get the elapse time for the block
 * @param    S          SimStruct representing an S-Function block
 * @param    dataPtr    Pointer to the elapse time data
 *
 */
#define ssGetElapseTime(S, dataPtr)                                                  \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_ELAPSE_TIME, 0, (double*)dataPtr) \
        _ssSafelyCallGenericFcnEnd

/**
 * @brief ssGetElapseTimeCounter
 *
 * Get the elapse time counter for the block
 * @param    S          SimStruct representing an S-Function block
 * @param    dataPtr    Pointer to the elapse time counter data
 *
 */
#define ssGetElapseTimeCounter(S, dataPtr)                                                \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_ELAPSE_TIME_COUNTER, 0, (int*)dataPtr) \
        _ssSafelyCallGenericFcnEnd

/**
 * @brief ssGetElapseTimeCounterDtype
 *
 * Get the data type of elapse time counter for the block
 * @param    S          SimStruct representing an S-Function block
 * @param    dataPtr    Pointer to the data type of elapse time counter
 *
 */
#define ssGetElapseTimeCounterDtype(S, dataPtr)                                                 \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_ELAPSE_TIME_COUNTER_DTYPE, 0, (int*)dataPtr) \
        _ssSafelyCallGenericFcnEnd

/**
 * @brief ssGetElapseTimeResolution
 *
 * Get the resolution of elapse time for the block
 * @param    S          SimStruct representing an S-Function block
 * @param    dataPtr    Pointer to the elapse time resolution
 *
 */
#define ssGetElapseTimeResolution(S, dataPtr)                                                   \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_GET_ELAPSE_TIME_RESOLUTION, 0, (double*)dataPtr) \
        _ssSafelyCallGenericFcnEnd

/**
 * @brief ssSetTimeSource
 *
 * Register time source for an asynchronous task
 * @param    S             SimStruct representing an S-Function block.
 * @param    timeSource    Source of time used by the asynchronous task created by the block
 * for the asynchronous task the S-function registers
 *    SS_TIMESOURCE_BASERATE
 *    SS_TIMESOURCE_SELF
 *    SS_TIMESOURCE_CALLER
 *    SS_TIMESOURCE_SELF_INTERNAL
 */
#if SS_SFCN

#define ssSetTimeSource(S, timeSource)                                            \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_TIME_SOURCE, timeSource, NULL) \
        _ssSafelyCallGenericFcnEnd

#endif


/**
 * @brief ssGetTaskTime
 *
 * Get the current time for the current task.
 * @param    S           SimStruct representing an S-Function block.
 * @param    sti         Index of the sample time corresponding to the task for which the current
 * time is to be returned.
 * @return   A value of type time_T.
 */
#define ssGetTaskTime(S, sti) \
    (S)->mdlInfo->t[ssIsTIDInStInfo(S, sti) ? ssGetSampleTimeTaskID(S, sti) : 0] /*  (time_T)   */


/** @} */ /* end of SimulationInformation */

/** @defgroup RunTimeParams  Run-Time Parameters
 *  @{
 */

/*======================================*
 * Run-Time Parameters *
 *======================================*/

/**
 * @brief ssGetNumRunTimeParams
 *
 * Get the number of run-time parameters created by this S-function
 * @param  S           SimStruct representing an S-Function block.
 * @return An int_T value indicating the number of run-time parameters.
 */
#define ssGetNumRunTimeParams(S) (S)->sfcnParams.numRtp.numRtp

/**
 * @brief ssGetRunTimeParamInfo
 *
 * Get the attributes of a run-time parameter
 * @param  S           SimStruct representing an S-Function block.
 * @param  idx         Index of a run-time parameter.
 * @return A pointer to the ssParamRec describing the attributes of the run-time parameter specified
 * by the index param.
 */
#define ssGetRunTimeParamInfo(S, idx) (S)->sfcnParams.rtp[idx]


/**
 * @brief ssRegAllTunableParamsAsRunTimeParams
 *
 * Register all tunable parameters as run-time parameters
 * @param  S           SimStruct representing an S-Function block.
 * @param  ms          Array of names for the run-time parameters.
 */
#define ssRegAllTunableParamsAsRunTimeParams(S, nms)                                   \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REG_ALL_TUNE_PRM_AS_RTP, 0, (void*)nms) \
        _ssSafelyCallGenericFcnEnd



/**
 * @brief ssRegDlgParamAsRunTimeParam
 *
 * Register a dialog parameter as a run-time parameter
 * @param    S           SimStruct representing an S-Function block.
 * @param    dlgIdxArg   Index of the dialog parameter.
 * @param    rtIdxArg    Index of the run-time parameter.
 * @param    nameArg     Name of the run-time parameter.
 * @dtIdArg  dtIdArg     Value of type DTypeId that specifies the data type of the run-time
 * parameter.
 */
#if SS_SFCN && SS_SIM
#define ssRegDlgParamAsRunTimeParam(S, dlgIdxArg, rtIdxArg, nameArg, dtIdArg)     \
    {                                                                             \
        ssRTPRegInfoWithType _slConvTypeAndRegParamInfo;                          \
        _slConvTypeAndRegParamInfo.dlgIdx = (dlgIdxArg);                          \
        _slConvTypeAndRegParamInfo.rtIdx = (rtIdxArg);                            \
        _slConvTypeAndRegParamInfo.name = (nameArg);                              \
        _slConvTypeAndRegParamInfo.dtId = (dtIdArg);                              \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REG_AND_CNV_RUN_TIME_PARAM, 0, \
                                        (void*)&_slConvTypeAndRegParamInfo)       \
            _ssSafelyCallGenericFcnEnd;                                           \
    }
#endif



/**
 * @brief ssSetNumRunTimeParams
 *
 * Specify the number of run-time parameters created by this S-function
 * @param    S           SimStruct representing an S-Function block.
 * @param    num         Number of run-time parameters.
 */
#if SS_SFCN
#if SS_RTW
#define ssSetNumRunTimeParams(S, num) _ssSetNumRunTimeParams(S, num)
#else
#define ssSetNumRunTimeParams(S, num)                                              \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_SET_NUM_RUN_TIME_PARAMS, num, NULL) \
        _ssSafelyCallGenericFcnEnd
#endif
#endif


/**
 * @brief ssSetRunTimeParamInfo
 *
 * Specify the attributes of a run-time parameter
 * @param    S           SimStruct representing an S-Function block.
 * @param    idx         Index of a run-time parameter
 * @param    p           ssParamRec structure containing the attributes of the run-time parameter.
 */
#if SS_SFCN
#if SS_RTW
#define ssSetRunTimeParamInfo(S, idx, p) _ssSetRunTimeParamInfo(S, idx, p)
#else
#define ssSetRunTimeParamInfo(S, idx, p)                                          \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_REG_RUN_TIME_PARAM, idx, (void*)p) \
        _ssSafelyCallGenericFcnEnd
#endif
#endif


#if SS_SFCN && SS_SIM
/**
 * @brief ssUpdateAllTunableParamsAsRunTimeParams
 *
 * Update the values of run-time parameters to be the same as those of the corresponding tunable
 * dialog parameters.
 * @param    S           SimStruct representing an S-Function block.
 */
#define ssUpdateAllTunableParamsAsRunTimeParams(S)                                  \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_UPDATE_ALL_TUNE_PRM_AS_RTP, 0, NULL) \
        _ssSafelyCallGenericFcnEnd



/**
 * @brief ssUpdateDlgParamAsRunTimeParam
 *
 * Update a run-time parameter that corresponds to a dialog parameter.
 * @param    S           SimStruct representing an S-Function block.
 * @param    rtIdxArg    Index of the run-time parameter.
 */
#define ssUpdateDlgParamAsRunTimeParam(S, rtIdxArg)                                           \
    {                                                                                         \
        _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_UPDATE_AND_CNV_RUN_TIME_PARAM, (rtIdxArg), \
                                        NULL) _ssSafelyCallGenericFcnEnd;                     \
    }


/**
 * @brief ssUpdateRunTimeParamData
 *
 * Update the value of a run-time parameter
 * @param    S           SimStruct representing an S-Function block.
 * @param    idx         Index of the run-time parameter.
 * @param    d           New value of the parameter.
 */
#define ssUpdateRunTimeParamData(S, idx, d) ((S)->sfcnParams.rtp[idx])->data = (d)

/**
 * @brief ssUpdateRunTimeParamInfo
 *
 * Update the attributes of a run-time parameter
 * @param    S           SimStruct representing an S-Function block.
 * @param    idx         Index of the run-time parameter.
 * @param    p           Attributes of the run-time parameter.
 */
#define ssUpdateRunTimeParamInfo(S, idx, p)                                          \
    _ssSafelyCallGenericFcnStart(S)(S, GEN_FCN_UPDATE_RUN_TIME_PARAM, idx, (void*)p) \
        _ssSafelyCallGenericFcnEnd

#endif /* __SS_SFCN && SS_SIM__ */

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssSetRuntimeThreadSafetyCompliance
 *
 * Specify that the S-function is run-time thread-safe.
 * @param    S             SimStruct representing an S-Function block.
 * @param    val           One of the following enumerated values that indicates if the
 * S-function is run-time thread-safe or not or unknown:
 *     RUNTIME_THREAD_SAFETY_COMPLIANCE_TRUE
 *     RUNTIME_THREAD_SAFETY_COMPLIANCE_FALSE
 *     RUNTIME_THREAD_SAFETY_COMPLIANCE_UNKNOWN
 */
#define ssSetRuntimeThreadSafetyCompliance(S, val) \
    (S)->blkInfo.sfcnFlags.runtimeThreadSafetyCompliance = (val)
#endif

#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetRuntimeThreadSafetyCompliance
 *
 * Determine whether the S-function is run-time thread-safe.
 * @return   One of the following enumerated values that indicates if the
 * S-function is run-time thread-safe or not or unknown:
 *     RUNTIME_THREAD_SAFETY_COMPLIANCE_TRUE
 *     RUNTIME_THREAD_SAFETY_COMPLIANCE_FALSE
 *     RUNTIME_THREAD_SAFETY_COMPLIANCE_UNKNOWN
 */
#define ssGetRuntimeThreadSafetyCompliance(S) \
    ((RuntimeThreadSafetyCompliance)((S)->blkInfo.sfcnFlags.runtimeThreadSafetyCompliance))
#endif

/** @} */ /* end of RunTimeParams */

/** @defgroup StateWorkVector  State and Work Vector
 *  @{
 */

/*======================================*
 * State and Work Vector *
 *======================================*/
/**
 * @brief ssSetNumDWork
 *
 * Specify the number of data type work vectors used by a block
 * @param  S         SimStruct representing an S-Function block.
 * @param  num       Number of data type work vectors.
 * @return The Boolean value true if nDWork is zero or a positive integer; otherwise, false.
 */
#if !SS_SFCN_LEVEL_1
#if SS_SFCN_FOR_SIM
#if defined(USE_64BIT_FIELDS)
#define ssSetNumDWork(S, num)                                                            \
    (((S)->blkInfo.blkInfo2->blkInfoSLSize->regDataType.setNumDWorkFcn != NULL)          \
         ? (*(S)->blkInfo.blkInfo2->blkInfoSLSize->regDataType.setNumDWorkFcn)((S), num) \
         : (0))
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumDWork(S, num) \
    (((S)->regDataType.setNumDWorkFcn != NULL) ? (*(S)->regDataType.setNumDWorkFcn)((S), num) : (0))
#endif
#else
#define ssSetNumDWork(S, num) ((_ssSetNumDWork(S, num)) >= -1)
#endif
#endif /* NOT level 1 S-function */

/**
 * @brief ssGetNumDWork
 *
 * Get the number of data type work vectors used by a block
 * @param  S         SimStruct representing an S-Function block.
 * @return An int_T value indicating the number of DWork vectors in this S-function.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumDWork(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numDWork
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumDWork(S) (S)->sizes.numDWork
#endif

/**
 * @brief ssGetDWorkComplexSignal
 *
 * Determine whether the elements of a data type work vector are real or complex numbers
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return COMPLEX_YES (1) if the specified vector contains complex numbers; otherwise, COMPLEX_NO
 * (0).
 */
#define ssGetDWorkComplexSignal(S, index) \
    ((S)->work.dWork.sfcn[(index)].complexSignal) /* (CSignal_T) */

/**
 * @brief ssSetDWorkComplexSignal
 *
 * Specify whether the elements of a data type work vector are real or complex
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val       Numeric type, either COMPLEX_YES or COMPLEX_NO.
 * @return 1 (COMPLEX_YES), 0 (COMPLEX_NO), or -1 (COMPLEX_INHERITED) depending on the value
 * specified by csig.
 */
#define ssSetDWorkComplexSignal(S, index, val) (S)->work.dWork.sfcn[index].complexSignal = (val)

/**
 * @brief ssGetDWorkDataType
 *
 * Get the data type of a data type work vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return The data type ID of the DWork vector specified by the index vector if the data type is
 * valid. Otherwise, returns INVALID_DTYPE_ID.
 */
#define ssGetDWorkDataType(S, index) ((S)->work.dWork.sfcn[(index)].dataTypeId) /* (DTypeId) */

/**
 * @brief ssSetDWorkDataType
 *
 * Specify the data type of a data type work vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val       ID of a data type.
 * @return The data type ID specified by dtID. Returns -1 if dtID is DYNAMICALLY_TYPED.
 */
#define ssSetDWorkDataType(S, index, val) (S)->work.dWork.sfcn[index].dataTypeId = (val)

/**
 * @brief ssGetDWorkName
 *
 * Get the name of a data type work vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return A pointer (char_T *) to the character vector representing the name of the DWork vector
 * specified by the index vector.
 */
#define ssGetDWorkName(S, index) ((S)->work.dWork.sfcn[(index)].name) /* (char_T *) */

/**
 * @brief ssSetDWorkName
 *
 * Specify the name of a data type work vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val       Name of a work vector.
 * @return The name of the DWork vector entered in name.
 */
#define ssSetDWorkName(S, index, val) (S)->work.dWork.sfcn[index].name = val


/**
 * @brief ssGetDWorkUsageType
 *
 * Determine how DWork vector is used in S-function
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return One of the enumerated types defined for ssDWorkUsageType in simstruc_types.h.
 */
#define ssGetDWorkUsageType(S, index) (S)->work.dWork.sfcn[(index)].usedAs

/**
 * @brief ssSetDWorkUsageType
 *
 * Specify how DWork vector is used in S-function
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  type      Usage type of the DWork vector.
 * @return The usage type entered in type
 */
#define ssSetDWorkUsageType(S, index, val) (S)->work.dWork.sfcn[(index)].usedAs = val


/**
 * @brief ssGetDWorkUsedAsDState
 *
 * Determine whether a data type work vector is used as a discrete state vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return The int_T value 1 (SS_DWORK_USED_AS_DSTATE) if this vector is used to store a block's
 * discrete states. Otherwise, returns 0 (SS_DWORK_USED_AS_DWORK)..
 */
#define ssGetDWorkUsedAsDState(S, index) \
    ((S)->work.dWork.sfcn[(index)].usedAs == SS_DWORK_USED_AS_DSTATE)

/**
 * @brief ssSetDWorkUsedAsDState
 *
 * Specify that a data type work vector is used as a discrete state vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val       How this vector is used. A value of 1 indicates that the work vector is to be
 * used to store the block's discrete states (SS_DWORK_USED_AS_DSTATE), a value of 0 indicates that
 * the work vector is to be used as a work vector (SS_DWORK_USED_AS_DWORK).
 * @return 0 if usage is SS_DWORK_USED_AS_DWORK (0), otherwise returns 1.
 */
#define ssSetDWorkUsedAsDState(S, index, val) \
    (S)->work.dWork.sfcn[(index)].usedAs =    \
        ((val) ? SS_DWORK_USED_AS_DSTATE : ((S)->work.dWork.sfcn[(index)].usedAs))



/**
 * @brief ssGetDWorkWidth
 *
 * Get the size of a data type work vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return The int_T number of elements in the DWork vector specified by the index vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetDWorkWidth(S, index) ((S)->work.dWorkAux[(index)].widthSLSize)
#elif defined(USE_32BIT_FIELDS)
#define ssGetDWorkWidth(S, index) ((S)->work.dWork.sfcn[(index)].width)
#endif

/**
 * @brief ssSetDWorkWidth
 *
 * Specify the width of a data type work vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val       Number of elements in the work vector.
 * @return The number of elements passed in through width.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetDWorkWidth(S, index, val) (S)->work.dWorkAux[(index)].widthSLSize = (val)
#elif defined(USE_32BIT_FIELDS)
#define ssSetDWorkWidth(S, index, val) (S)->work.dWork.sfcn[index].width = (val)
#endif

/**
 * @brief ssGetDWork
 *
 * Get a DWork vector
 * @param  S         SimStruct representing an S-Function block.
 * @param  index     Index of a data type work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return A pointer (void *) to the DWork vector specified by the index vector.
 */
#define ssGetDWork(S, index) ((S)->work.dWork.sfcn[(index)].array) /*   (void *)  */

/**
 * @brief ssGetdX
 *
 * Get the derivatives of a blocks's continuous states
 * @param  S         SimStruct representing an S-Function block or Simulink model.
 * @return A pointer (real_T *) to an array containing the derivatives of the continuous states of
 * S, which can be a block or the model. Returns NULL if there are no continuous states.
 */
#define ssGetdX(S) (S)->states.dX /*   (real_T *)    */


#if !SS_SFCN_LEVEL_1
/**
 * @brief ssGetContStates
 *
 * Get a block's continuous states
 * @param  S               SimStruct representing an S-Function block.
 * @return A pointer (real_T *) to the continuous state vector as an array of length
 * ssGetNumContStates(S). Returns NULL if the S-function does not have any continuous states.
 */
#define ssGetContStates(S) (S)->states.contStates /*   (real_T *)    */
/**
 * @brief ssGetDiscStates
 *
 * Get a block's discrete states
 * @param  S               SimStruct representing an S-Function block.
 * @return A pointer (real_T *) to the discrete state vector as an array of length
 * ssGetNumDiscStates(S). Returns NULL if the S-function does not have any discrete states.
 */
#define ssGetDiscStates(S) ((S)->states.discStates) /*   (real_T *)    */

/**
 * @brief ssGetRealDiscStates
 *
 * Get a block's discrete state vector
 * @param  S               SimStruct representing an S-Function block.
 * @return The discrete state vector as an array of real_T elements of length ssGetNumDiscStates(S).
 */
#define ssGetRealDiscStates(S) ssGetDiscStates(S) /*   (real_T *)    */

#endif

/**
 * @brief ssGetNumContStates
 *
 * Get the number of continuous states that a block has
 * @param  S         SimStruct representing an S-Function block or Simulink model.
 * @return An int_T value indicating the number of continuous states.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumContStates(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numContStates
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumContStates(S) (S)->sizes.numContStates
#endif

/**
 * @brief ssSetNumContStates
 *
 * Specify the number of continuous states that a block has
 * @param  S            SimStruct representing an S-Function block.
 * @param  nContStates  Number of continuous states to be set for the block represented by S.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumContStates(S, nContStates) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numContStates = (nContStates)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumContStates(S, nContStates) (S)->sizes.numContStates = (nContStates)
#endif

/**
 * @brief ssGetNumDiscStates
 *
 * Get the number of discrete states that a block has
 * @param  S            SimStruct representing an S-Function block or a Simulink model.
 * @return  An int_T value indicating the number of discrete states.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumDiscStates(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numDiscStates
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumDiscStates(S) (S)->sizes.numDiscStates
#endif

/**
 * @brief ssSetNumDiscStates
 *
 * Specify the number of discrete states that a block has
 * @param  S            SimStruct representing an S-Function block.
 * @param  nContStates  Number of continuous states to be set for the block represented by S.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumDiscStates(S, nDiscStates) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numDiscStates = (nDiscStates)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumDiscStates(S, nDiscStates) (S)->sizes.numDiscStates = (nDiscStates)
#endif

/**
 * @brief ssGetNumNonsampledZCs
 *
 * Get the size of the zero-crossing vector
 * @param  S            SimStruct representing an S-Function block.
 * @return  An int_T value indicating the size of the zero-crossing vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumNonsampledZCs(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numNonsampledZCs
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumNonsampledZCs(S) (S)->sizes.numNonsampledZCs
#endif

/**
 * @brief ssSetNumNonsampledZCs
 *
 * Specify the number of states for which a block detects zero crossings that occur between sample
 * points
 * @param  S               SimStruct representing an S-Function block.
 * @param  nNonsampledZCs  Number of nonsampled zero crossings that a block detects.
 * @return The number of modes specified by nNonsampledZCs, or -1 if DYNAMICALLY_SIZED.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumNonsampledZCs(S, nNonsampledZCs) \
    (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numNonsampledZCs = (nNonsampledZCs)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumNonsampledZCs(S, nNonsampledZCs) (S)->sizes.numNonsampledZCs = (nNonsampledZCs)
#endif

/**
 * @brief ssGetNonsampledZCs
 *
 * Get the zero-crossing signal values
 * @param  S               SimStruct representing an S-Function block.
 * @return A pointer (real_T *) to the zero-crossing signal values.
 */
#define ssGetNonsampledZCs(S) (S)->states.nonsampledZCs /*   (real_T *)    */


/**
 * @brief ssGetNumRWork
 *
 * Get the size of a block's floating-point work vector
 * @param  S               SimStruct representing an S-Function block.
 * @return An int_T value indicating the size of the RWork vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumRWork(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numRWork
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumRWork(S) (S)->sizes.numRWork
#endif

/**
 * @brief ssSetNumRWork
 *
 * Specify the size of a block's floating-point work vector
 * @param  S               SimStruct representing an S-Function block.
 * @param  nRwork          Number of elements in the floating-point work vector.
 * @return The number of elements specified by nRWork, or -1 if DYNAMICALLY_SIZED.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumRWork(S, nRWork) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numRWork = (nRWork)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumRWork(S, nRWork) (S)->sizes.numRWork = (nRWork)
#endif

/**
 * @brief ssGetRWork
 *
 * Get a block's floating-point work vector
 * @param  S               SimStruct representing an S-Function block.
 * @return A pointer (real_T *) to the RWork vector.
 */
#define ssGetRWork(S) (S)->work.rWork /*   (real_T *)    */



#if !SS_DEBUG_FOR_SIM
/**
 * @brief ssGetRWorkValue
 *
 * Get an element of a block's floating-point work vector
 * @param  S               SimStruct representing an S-Function block.
 * @param  rworkIdx        Index of the element returned by this function.
 * @return The real_T value stored in the RWork vector element specified by the index idx.
 */
#define ssGetRWorkValue(S, rworkIdx) (S)->work.rWork[rworkIdx] /*   (real_T)      */


/**
 * @brief ssSetRWorkValue
 *
 * Set an element of a block's floating-point work vector
 * @param  S               SimStruct representing an S-Function block.
 * @param  rworkIdx        Index of the element to be set.
 * @param  value           New value of element.
 * @return The real_T value passed into the macro.
 */
#define ssSetRWorkValue(S, rworkIdx, rworkValue) (S)->work.rWork[rworkIdx] = (rworkValue)

#endif


/**
 * @brief ssGetNumIWork
 *
 * Get the size of a block's integer work vector.
 * @param  S               SimStruct representing an S-Function block.
 * @return An int_T value indicating the size of the IWork vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumIWork(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numIWork
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumIWork(S) (S)->sizes.numIWork
#endif

/**
 * @brief ssSetNumIWork
 *
 * Specify the size of a block's integer work vector
 * @param  S               SimStruct representing an S-Function block.
 * @param  nIWork          Number of elements in the integer work vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumIWork(S, nIWork) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numIWork = (nIWork)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumIWork(S, nIWork) (S)->sizes.numIWork = (nIWork)
#endif

/**
 * @brief ssGetIWork
 *
 * Get a block's integer work vector.
 * @param  S               SimStruct representing an S-Function block.
 * @return A pointer (int_T *) to the integer work vector for this S-function.
 */
#define ssGetIWork(S) (S)->work.iWork /*   (int_T *)     */



#if !SS_DEBUG_FOR_SIM
/**
 * @brief ssGetIWorkValue
 *
 * Get an element of a block's integer work vector.
 * @param  S         SimStruct representing an S-Function block.
 * @param  iworkIdx  Index of the element returned by this function.
 * @return The int_T value stored in the idx element of the integer work vector for this S-function.
 * Returns NULL if no value was assigned into the idx element of the IWork vector.
 */
#define ssGetIWorkValue(S, iworkIdx) (S)->work.iWork[iworkIdx] /*   (int_T)       */

/**
 * @brief ssSetIWorkValue
 *
 * Set an element of a block's integer work vector.
 * @param  S           SimStruct representing an S-Function block.
 * @param  iworkIdx    Index of the element to be set.
 * @param  iworkValue  New value of element.
 * @return The int_T value passed into the macro.
 */
#define ssSetIWorkValue(S, iworkIdx, iworkValue) (S)->work.iWork[iworkIdx] = (iworkValue)

#endif


/**
 * @brief ssGetNumPWork
 *
 * Get the size of a block's pointer work vector.
 * @param  S               SimStruct representing an S-Function block.
 * @return A int_T value indicating the size of the PWork vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumPWork(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numPWork
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumPWork(S) (S)->sizes.numPWork
#endif

/**
 * @brief ssSetNumPWork
 *
 * Specify the size of a block's pointer work vector.
 * @param  S           SimStruct representing an S-Function block.
 * @param  nPWork      Number of elements to be allocated to the pointer work vector of the block
 * represented by S.
 * @return The number of elements specified by nPWork, or -1 if DYNAMICALLY_SIZED.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumPWork(S, nPWork) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numPWork = (nPWork)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumPWork(S, nPWork) (S)->sizes.numPWork = (nPWork)
#endif

/**
 * @brief ssGetPWork
 *
 * Get a block's pointer work vector.
 * @param  S           SimStruct representing an S-Function block.
 * @return A pointer to the PWork vector.
 */
#define ssGetPWork(S) (S)->work.pWork /*   (void **)     */


#if !SS_DEBUG_FOR_SIM

/**
 * @brief ssGetPWorkValue
 *
 * Get a pointer from a block's pointer work vector
 * @param  S           SimStruct representing an S-Function block.
 * @param  pworkIdx    Index of the pointer returned by this function.
 * @return The (void *) element of the PWork vector at the index pworkIdx.
 */
#define ssGetPWorkValue(S, pworkIdx) (S)->work.pWork[pworkIdx] /*   (void *)      */

/**
 * @brief ssSetPWorkValue
 *
 * Set an element of a block's pointer work vector
 * @param  S           SimStruct representing an S-Function block.
 * @param  pworkIdx    Index of the element to be set.
 * @param  pworkValue  New pointer element.
 * @return The pointer passed into the macro.
 */
#define ssSetPWorkValue(S, pworkIdx, pworkValue) (S)->work.pWork[pworkIdx] = (pworkValue)


#endif

/**
 * @brief ssGetNumModes
 *
 * Get the size of the mode vector
 * @param  S           SimStruct representing an S-Function block.
 * @return An int_T value indicating the size of the mode work vector.
 */
#if defined(USE_64BIT_FIELDS)
#define ssGetNumModes(S) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numModes
#elif defined(USE_32BIT_FIELDS)
#define ssGetNumModes(S) (S)->sizes.numModes /*   (int_T)       */
#endif

/**
 * @brief ssSetNumModes
 *
 * Specify the size of the block's mode vector
 * @param  S       SimStruct representing an S-Function block.
 * @param  n       Size of the mode vector for the block represented by S. Valid values are 0, a
 * positive integer, or DYNAMICALLY_SIZED.
 * @return The number of modes specified by n, or -1 if DYNAMICALLY_SIZED.
 */
#if defined(USE_64BIT_FIELDS)
#define ssSetNumModes(S, n) (S)->blkInfo.blkInfo2->blkInfoSLSize->sizes.numModes = (n)
#elif defined(USE_32BIT_FIELDS)
#define ssSetNumModes(S, n) (S)->sizes.numModes = (n)
#endif

/**
 * @brief ssGetModeVector
 *
 * Get the mode vector
 * @param  S           SimStruct representing an S-Function block.
 * @return A pointer (int_T *) to the mode vector.
 */
#define ssGetModeVector(S) (S)->work.modeVector /*   (int_T *)     */

/**
 * @brief ssGetModeVectorValue
 *
 * Get an element of a block's mode vector
 * @param  S           SimStruct representing an S-Function block.
 * @param  idx         Index of a mode vector element.
 * @return An int_T value for the element of the mode vector specified by the index idx.
 * Returns NULL if no value was assigned into the idx element of the mode vector.
 */
#define ssGetModeVectorValue(S, idx) (S)->work.modeVector[idx] /*   (int_T)       */


/**
 * @brief ssSetModeVectorValue
 *
 * Set an element of a block's mode vector
 * @param  S           SimStruct representing an S-Function block.
 * @param  idx         Index of a mode vector element.
 * @param  val         Mode vector value.
 */
#define ssSetModeVectorValue(S, idx, val) (S)->work.modeVector[idx] = (val)

/** @} */ /* end of StateWorkVector */

/** @defgroup CodeGeneration Code Generation
 *  @{
 */

/*======================================*
 * Code Generation *
 *======================================*/
/**
 * @brief ssGetDWorkRTWIdentifier
 *
 * Get the identifier used to declare a DWork vector in code generated from the associated
 * S-function
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return A pointer (char_T *) to the character vector used as the Simulink Coder identifier for
 * the DWork vector specified by the index vector. Returns NULL if no Simulink Coder identifier is
 * specified.
 */
#define ssGetDWorkRTWIdentifier(S, index) \
    ((S)->work.dWorkAux[(index)].rtwIdentifier) /* (char_T *) */

/**
 * @brief ssSetDWorkRTWIdentifier
 *
 * Specify the identifier used to declare a DWork vector in code generated from the associated
 * S-function
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val      DWork vector identifier
 * @return A pointer (char_T *) to the Simulink Coder identifier entered in id.
 */
#define ssSetDWorkRTWIdentifier(S, index, val) (S)->work.dWorkAux[index].rtwIdentifier = val

/**
 * @brief ssGetDWorkRTWIdentifierMustResolveToSignalObject
 *
 * Get a flag indicating if a DWork vector resolves to a Simulink.Signal object
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return A uint_T flag with the value of 0, 1, or 2.
 */
#define ssGetDWorkRTWIdentifierMustResolveToSignalObject(S, index) \
    ((S)->work.dWorkAux[(index)].flags.rtwIdMustResolveToSignalObject)

/**
 * @brief ssSetDWorkRTWIdentifierMustResolveToSignalObject
 *
 * Specify if a DWork vector resolves to a Simulink.Signal object
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  n       Flag to control if the DWork vector resolves to a Simulink.Signal object, either
 * 0, 1, or 2.
 * @return The value for flag if flag is 0, 1, or 2. Otherwise, returns 0.
 */
#define ssSetDWorkRTWIdentifierMustResolveToSignalObject(S, index, n) \
    (S)->work.dWorkAux[index].flags.rtwIdMustResolveToSignalObject = (n)

/**
 * @brief ssGetDWorkRTWStorageClass
 *
 * Get the storage class of a DWork vector in code generated from the associated S-function
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return One of the enumerated types defined for ssRTWStorageType.
 */
#define ssGetDWorkRTWStorageClass(S, index) ((S)->work.dWorkAux[(index)].rtwStorageClass)

/**
 * @brief ssSetDWorkRTWStorageClass
 *
 * Specify the storage class of a DWork vector in code generated from the associated S-function
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val     Storage class of the work vector. Must be one of the values enumerated by
 * ssRTWStorageType.
 * @return The ssRTWStorageType value entered as sc. Invokes an error if sc is not a valid storage
 * class.
 */
#define ssSetDWorkRTWStorageClass(S, index, val) (S)->work.dWorkAux[index].rtwStorageClass = val

/**
 * @brief ssGetDWorkRTWTypeQualifier
 *
 * Get the C type qualifier used to declare a DWork vector in code generated from the associated
 * S-function
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @return A pointer (char_T *) to a character vector indicating the C type qualifier used to
 * declare the DWork vector specified by the index vector. Returns NULL if no type qualifier is
 * specified.
 */
#define ssGetDWorkRTWTypeQualifier(S, index) ((S)->work.dWorkAux[(index)].rtwTypeQualifier)

/**
 * @brief ssSetDWorkRTWTypeQualifier
 *
 * Specify the C type qualifier used to declare a DWork vector in code generated from the associated
 * S-function
 * @param  S       SimStruct representing an S-Function block
 * @param  index   Index of the work vector, where the index is one of 0, 1, 2, ...
 * ssGetNumDWork(S)-1.
 * @param  val     Type qualifier
 * @return The C type qualifier entered in tq.
 */
#define ssSetDWorkRTWTypeQualifier(S, index, val) (S)->work.dWorkAux[index].rtwTypeQualifier = val


/**
 * @brief ssGetPlacementGroup
 *
 * Get the name of the placement group of a block
 * @param  S       SimStruct representing an S-Function block. The block must be either a source
 * block (i.e., a block without input ports) or a sink block (i.e., a block without output ports).
 * @return A pointer (char_T *) to the character vector indicating the name of the S-function
 * placement group.
 */
#define ssGetPlacementGroup(S) (S)->blkInfo.placementGroup

/**
 * @brief ssRTWGenIsCodeGen
 *
 * Identify any code generation that is not used by the Accelerator
 * @param  S       SimStruct representing an S-Function block.
 * @return The Boolean value true if the model is generating code for any purpose other than
 * Accelerator mode simulation. Returns false if the model is not generating code or is generating
 * code for Accelerator mode simulation.
 */
#if SS_SIM
#define ssRTWGenIsCodeGen(S)                                               \
    (ssGetSimMode(S) == SS_SIMMODE_RTWGEN &&                               \
     (((S)->mdlInfo->rtwgenMode == SS_RTWGEN_RTW_CODE) ||                  \
      ((S)->mdlInfo->rtwgenMode == SS_RTWGEN_MODELREFERENCE_SIM_TARGET) || \
      ((S)->mdlInfo->rtwgenMode == SS_RTWGEN_MODELREFERENCE_RTW_TARGET)))
#else
#define ssRTWGenIsCodeGen(S) (false)
#endif

/**
 * @brief ssWriteRTW2dMatParam
 *
 * Write a matrix parameter to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  n       Parameter name.
 * @param  v       Parameter values.
 * @param  dt      DataType of parameter elements.
 * @param  nr      Number of rows in the matrix.
 * @param  nc      Number of columns in the matrix.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#define ssWriteRTW2dMatParam(S, n, v, dt, nr, nc) \
    ssWriteRTWNameValuePair(S, SSWRITE_VALUE_DTYPE_2DMAT, n, v, dt, nr, nc)

#if SS_SFCN_FOR_SIM

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief ssWriteRTWMx2dMatParam
 *
 * Write a matrix parameter in MATLAB format to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  name    Parameter name.
 * @param  rVal    Real elements of the parameter array.
 * @param  iVal    Imaginary elements of the parameter array.
 * @param  dtInfo  Data type of the parameter elements.
 * @param  nRows   Number of rows in the matrix.
 * @param  nCols   Number of columns in the matrix.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#if defined(USE_32BIT_FIELDS)
extern int_T ssWriteRTWMx2dMatParam(SimStruct* S,
                                    const char_T* name,
                                    const void* rVal,
                                    const void* iVal,
                                    int_T dtInfo,
                                    int_T nRows,
                                    int_T nCols);
#else
extern int_T ssWriteRTWMx2dMatParam(SimStruct* S,
                                    const char_T* name,
                                    const void* rVal,
                                    const void* iVal,
                                    int_T dtInfo,
                                    SLSize nRows,
                                    SLSize nCols);
#endif


/**
 * @brief ssWriteRTWMxVectParam
 *
 * Write a vector parameter in MATLAB format to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  name    Parameter name.
 * @param  rVal    Real elements of the parameter array.
 * @param  iVal    Imaginary elements of the parameter array.
 * @param  dtInfo  Data type of the parameter elements.
 * @param  numEL   Number of elements in the vector.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#if defined(USE_32BIT_FIELDS)
extern int_T ssWriteRTWMxVectParam(SimStruct* S,
                                   const char_T* name,
                                   const void* rVal,
                                   const void* iVal,
                                   int_T dtInfo,
                                   int_T numEl);
#else
extern int_T ssWriteRTWMxVectParam(SimStruct* S,
                                   const char_T* name,
                                   const void* rVal,
                                   const void* iVal,
                                   int_T dtInfo,
                                   SLSize numEl);
#endif
/**
 * @brief ssWriteRTWParameters
 *
 * Write tunable parameter information to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  nParams Number of tunable parameters
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
extern int_T ssWriteRTWParameters(SimStruct* S, int_T nParams, ...);

/**
 * @brief ssWriteRTWParamSettings
 *
 * Write values of nontunable parameters to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  nParams Number of parameter settings.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
extern int_T ssWriteRTWParamSettings(SimStruct* S, int_T nParams, ...);


/**
 * @brief ssWriteRTWScalarParam
 *
 * Write a scalar parameter to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  n       Parameter name.
 * @param  v       Parameter value.
 * @param  dt      Integer ID of the type of the parameter value.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#define ssWriteRTWScalarParam(S, n, v, dt) \
    ssWriteRTWNameValuePair(S, SSWRITE_VALUE_DTYPE_NUM, n, v, dt)



/**
 * @brief ssWriteRTWStr
 *
 * Write a character vector to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  str     Character vector.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
extern int_T ssWriteRTWStr(SimStruct* S, const char_T* str);

/**
 * @brief ssWriteRTWStrParam
 *
 * Write a character vector parameter to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  n       Parameter name.
 * @param  v       Parameter value.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#define ssWriteRTWStrParam(S, n, v) ssWriteRTWNameValuePair(S, SSWRITE_VALUE_QSTR, n, v)


/**
 * @brief ssWriteRTWStrVectParam
 *
 * Write a vector of character vector parameters to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  n       Parameter name.
 * @param  v       Parameter value.
 * @param  len     Number of elements in the vector.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#define ssWriteRTWStrVectParam(S, n, v, len) \
    ssWriteRTWNameValuePair(S, SSWRITE_VALUE_VECT_STR, n, v, len)

/**
 * @brief ssWriteRTWVectParam
 *
 * Write a vector parameter to the model.rtw file
 * @param  S       SimStruct representing an S-Function block.
 * @param  n       Parameter name.
 * @param  v       Parameter value.
 * @param  dt      Data type of the parameter elements.
 * @param  len     Number of elements in the vector.
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
#define ssWriteRTWVectParam(S, n, v, dt, len) \
    ssWriteRTWNameValuePair(S, SSWRITE_VALUE_DTYPE_VECT, n, v, dt, len)

/**
 * @brief ssWriteRTWWorkVect
 *
 * Write work vectors to the model.rtw file
 * @param  S         SimStruct representing an S-Function block.
 * @param  vectName  Name of the work vector.
 * @param  nNames    Number of names
 * @return An int_T (1 or 0) or boolean_T (true or false) indicating the success or failure of the
 * function.
 */
extern int_T ssWriteRTWWorkVect(SimStruct* S, const char_T* vectName, int_T nNames, ...);

#ifdef __cplusplus
}
#endif

#endif

/** @} */ /* end of StateWorkVector */

/** @defgroup ErrorHandling Error Handling
 *  @{
 */

/*======================================*
 * Error Handling *
 *======================================*/

/**
 * @brief ssPrintf
 *
 * Print a variable-content message
 * @param msg Must be a ANSI C printf-style character vector with optional variable replacement
 * parameters.
 * @return A positive value indicating the number of bytes transmitted. Returns a negative number
 * indicating an error.
 *
 * @brief ssWarning
 *
 * Display a warning message
 * @param S Simstruct representing an S-Function block or a Simulink model.
 * @param msg Warning message
 */
#if !SS_SL_INTERNAL
#if SS_SFCN_FOR_SIM

#define SS_STDIO_AVAILABLE
#define ssPrintf mexPrintf
extern
#ifdef __cplusplus
    "C"
#endif
    void
    ssWarning(SimStruct*, const char* msg);
#elif SS_HAVESTDIO /* for Real-Time Workshop with stdio facilities */
#include <stdio.h>
#define SS_STDIO_AVAILABLE
#define ssPrintf printf
#define ssWarning(S, msg) printf("Warning: block '%s': %s\n", ssGetPath(S), msg)
#else /* for Real-Time Workshop without stdio facilities */
extern int rtPrintfNoOp(const char* fmt, ...);
#undef SS_STDIO_AVAILABLE
#define ssPrintf rtPrintfNoOp
#define ssWarning(S, msg) /* do nothing */
#endif
#endif

/**
 * @brief ssGetErrorStatus
 *
 * Get a character vector that identifies the last error
 * @param  S      SimStruct representing an S-Function block.
 * @return A pointer (char_T *) to a character vector that identifies the last error message.
 */
#define ssGetErrorStatus(S) (S)->root->errorStatus.str /* (const char_T*) */

/**
 * @brief ssSetErrorStatus
 *
 * report an error
 * @param  S       SimStruct representing an S-Function block or a Simulink model
 * @param  string  Error message
 */
#define ssSetErrorStatus(S, string)                         \
    {                                                       \
        (S)->root->mdlInfo->mdlFlags.errorStatusIsMsg = 0U; \
        (S)->root->errorStatus.str = (string);              \
    }

/**
 * @brief ssGetLocalErrorStatus
 *
 * Get a character vector that identifies the last error
 * @param  S      SimStruct representing an S-Function block.
 * @return A pointer (char_T *) to a character vector that identifies the last error message.
 */
#define ssGetLocalErrorStatus(S) S->blkInfo.blkInfo2->localErrorStatus.str /* (const char_T*) */

/**
 * @brief ssSetLocalErrorStatus
 *
 * report an error
 * @param  S       SimStruct representing an S-Function block or a Simulink model
 * @param  string  Error message
 */
#define ssSetLocalErrorStatus(S, string)                          \
    {                                                             \
        (S)->blkInfo.sfcnFlags.localErrorStatusIsMsg = 0U;        \
        if (S->blkInfo.blkInfo2->localErrorStatus.str == NULL ||  \
            (const char_T*)(string) == NULL) {                    \
            S->blkInfo.blkInfo2->localErrorStatus.str = (string); \
        }                                                         \
    }

/** @} */ /* end of ErrorHandling */

/** @defgroup InfoOptions Information and Options
 *  @{
 */

/*======================================*
 * Information and Options *
 *======================================*/


/**
 * @brief ssGetSFunctionName
 *
 * @param  S     SimStruct pointer
 * @return The name of the S-function MEX-file associated with the block if S is a SimStruct for an
 * S-Function block. Otherwise return NULL.
 */
#define ssGetSFunctionName(S) \
    ((S) == (S)->root)) ? NULL : (S)->modelName /* (const char_T*) */


/**
 * @brief ssGetBlockDiagramName
 *
 * @param  S     SimStruct pointer
 * @return The name of the Simulink block diagram.
 */
#define ssGetBlockDiagramName(S) (S)->root->modelName /* (const char_T*) */

/* This macro is being deprecated. DO NOT USE */
#define ssGetModelName(S) (S)->modelName /* (const char_T*) */


/**
 * @brief ssSetOptions
 *
 * Specify S-function options
 * @param  S     SimStruct pointer
 * @param  opts  S-Function Options
 */
#define ssSetOptions(S, opts) (S)->sizes.options = (opts)


/**
 * @brief ssGetPath
 *
 * Get the path of a block
 * @param  S     SimStruct representing an S-function block or a Simulink model.
 * @return A pointer (char_T *) to a character vector containing the path to a block.
 */
#define ssGetPath(S) (S)->path /* (const char_T*) */

/*
 * RootSS - This is the "root" SimStruct corresponding to the Simulink
 *   model. DO NOT use this macro in S-Functions.
 */


#if defined(__GNUC__) || defined(__clang__)
#define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED __declspec(deprecated)
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED
#endif

#ifdef __cplusplus
extern "C" {
#endif
#if !SS_SFCN_NORMAL || defined(IS_RAPID_ACCEL) || defined(IS_RSIM)
#define ssGetRootSS(S) (S)->root
#define ssGetParentSS(S) (S)->parent
#else
DEPRECATED extern SimStruct* ssGetRootSS(SimStruct* S);
DEPRECATED extern SimStruct* ssGetParentSS(SimStruct* S);
#endif
#ifdef __cplusplus
}
#endif

/**
 * @brief ssGetUserData
 *
 * Access the user data
 * @param  S     SimStruct representing an S-function block.
 * @return A pointer (void *) to the S-function's user data
 */
#define ssGetUserData(S) (S)->work.userData /*   (void *)      */


/**
 * @brief ssSetPlacementGroup
 *
 * Specify the name of the placement group of a block
 * @param  S     SimStruct representing an S-Function block. The block must be either a source block
 * (i.e., a block without input ports) or a sink block (i.e., a block without output ports).
 * @param  name    Name of the placement group of the block represented by S.
 */
#define ssSetPlacementGroup(S, name) (S)->blkInfo.placementGroup = (name)

/**
 * @brief ssSetUserData
 *
 * Specify user data
 * @param  S     SimStruct representing an S-Function block.
 * @param  userDataPtr  User data
 */
#define ssSetUserData(S, userDataPtr) (S)->work.userData = (userDataPtr)

/**
 * @brief ssGetOwnerBlock
 *
 * Get the owner block of an S-function block
 * @param  S     SimStruct representing an S-Function block.
 */
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM
#if !SS_SFCN_LEVEL_1
#define ssGetOwnerBlock(S) ((S)->blkInfo.block)
#endif
#if !SS_SFCN
#define ssSetOwnerBlock(S, block) (S)->blkInfo.block = (block)
#else
#define ssSetOwnerBlock(S, block) ssSetOwnerBlock_cannot_be_used_in_SFunctions
#endif
#endif

/**
 * @brief ssSupportsMultipleExecInstances
 *
 * Specify that a For Each Subsystem block supports an S-function operating inside the subsystem.
 * @param  S      SimStruct representing an S-Function block.
 * @param  value  A character vector have a value of either true or false. If true, then the For
 * Each Subsystem will support having an S-function operate inside of it.
 */
#if (SS_SL_INTERNAL || SS_SFCN_FOR_SIM) && defined(ssGetOwnerBlock)
#define ssSupportsMultipleExecInstances(S, value)                                           \
    {                                                                                       \
        if (ssGetOwnerBlock(S) != NULL) {                                                   \
            boolean_T val = value;                                                          \
            _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SUP_MULTI_EXEC_INSTANCES, 0, &val) \
                _ssSafelyCallGenericFcnEnd;                                                 \
        }                                                                                   \
    }
#else
#define ssSupportsMultipleExecInstances(S, value)
#endif

/** @} */ /* end of InfoOptiopns */

/** @defgroup SimulinkFunctionAPI S-Function API for Simulink Functions
 *  @{
 */

/*======================================*
 * Simulink Function API for registering,
 * accessing Simulink Functions *
 *======================================*/

typedef enum { SS_SIMULINK_FUNCTION_QUERY_IS_DECLARED } SSSimulinkFunctionQueryType;

typedef enum { SS_SCOPED_VISIBILITY, SS_GLOBAL_VISIBILITY } SSSimulinkFunctionVisibility;

typedef struct ssFunctionQueryInfo_tag {
    const char* scopedFcnName;
    SSSimulinkFunctionQueryType queryType;
    boolean_T queryResult;
    void* reservedForFuture[4];
} _ssFunctionQueryInfo;

typedef struct ssFunctionExecArguments_tag {
    const char* scopedFcnName;
    int numInArgs;
    _ssFcnCallExecArgInfo* inArgs;
    int numOutArgs;
    _ssFcnCallExecArgInfo* outArgs;
} _ssFunctionExecArguments;

typedef void (*SSSimulinkFunctionPtr)(SimStruct*, int, _ssFcnCallExecArgs*);

typedef struct ssFunctionAttributeInfo_tag {
    const char* fcnPrototype;
    SSSimulinkFunctionVisibility fcnVisibility;
    SSSimulinkFunctionPtr fcnPtr;
    void* reservedForFuture[4];
} _ssFunctionAttributeInfo;

typedef enum {
    SS_SIMULINK_FUNCTION_ARG_DIMS,
    SS_SIMULINK_FUNCTION_ARG_DTYPE,
    SS_SIMULINK_FUNCTION_ARG_CPLX
} SSFunctionArgAttributeType;

typedef struct ssFunctionArgAttributeInfo_tag {
    const char* scopedFcnName;
    const char* argName;
    int argDT;
    int argNumDims;
    size_t* argDims;
    int argCplx;
    SSFunctionArgAttributeType argAttrToSet;
    void* reservedForFuture[4];
} _ssFunctionArgAttributeInfo;

#if SS_SFCN && SS_SIM
/*
 * Note that in ssQuerySimulinkFunction, there is an extra () around the macro
 * definition, and this is to allow returning a boolean result for the query.
 */

/**
 * @brief ssQuerySimulinkFunction
 *
 * @param  S         SimStruct representing an S-Function block
 * @param scopedName Name of function being queried.
 * @param query      Enumeration of type SSSimulinkFunctionQueryType
 * @return           Boolean result of query
 */
#define ssQuerySimulinkFunction(S, scopedName, query)                                           \
    ({                                                                                          \
        _ssFunctionQueryInfo locQueryInfo;                                                      \
        locQueryInfo.scopedFcnName = scopedName;                                                \
        locQueryInfo.queryType = query;                                                         \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_QUERY_SIMULINK_FUNCTION, 0, &locQueryInfo) \
            _ssSafelyCallGenericFcnEnd;                                                         \
        locQueryInfo.queryResult;                                                               \
    })

/**
 * @brief ssDeclareSimulinkFunction
 *
 * Declares either a global or scoped function
 * @param  S     SimStruct representing an S-Function block
 * @param proto  Prototype of function being declared.
 * @param ptr    Pointer to C function
 * @param vis    Visibility of function
 */
#define ssDeclareSimulinkFunction(S, proto, ptr, vis)                                            \
    {                                                                                            \
        _ssFunctionAttributeInfo locAttrInfo;                                                    \
        locAttrInfo.fcnPrototype = proto;                                                        \
        locAttrInfo.fcnVisibility = vis;                                                         \
        locAttrInfo.fcnPtr = ptr;                                                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_DECLARE_SIMULINK_FUNCTION, 0, &locAttrInfo) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }

/**
 * @brief ssDeclareFunctionCaller
 *
 * @param  S     SimStruct representing an S-Function block
 * @param  proto Prototype of function that will be called
 */
#define ssDeclareFunctionCaller(S, proto)                                                        \
    {                                                                                            \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_DECLARE_SIMULINK_FUNCTION_CALLER, 0, proto) \
            _ssSafelyCallGenericFcnEnd;                                                          \
    }

/**
 * @brief ssCallSimulinkFunction
 *
 * @param  S            SimStruct representing an S-Function block
 * @param  scopedName   Scoped name of called function
 * @param  nArgin       Number of input arguments
 * @param  argins       Array of void * pointer to input arguments
 * @param  nArgout      Number of output arguments
 * @param  argouts      Array of void * pointer to output arguments
 */
#define ssCallSimulinkFunction(S, scopedName, nArgin, argins, nArgout, argouts)               \
    {                                                                                         \
        _ssFunctionExecArguments locExecArgs;                                                 \
        locExecArgs.scopedFcnName = scopedName;                                               \
        locExecArgs.numInArgs = nArgin;                                                       \
        locExecArgs.inArgs = argins;                                                          \
        locExecArgs.numOutArgs = nArgout;                                                     \
        locExecArgs.outArgs = argouts;                                                        \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_CALL_SIMULINK_FUNCTION, 0, &locExecArgs) \
            _ssSafelyCallGenericFcnEnd;                                                       \
    }

/**
 * @brief ssGetSimulinkFunctionInput
 *
 * @param args  Pointer to arguments passed to called C function
 * @param idx   Index of input argument
 */
#define ssGetSimulinkFunctionInput(args, idx) ((args)->inArgs[(idx)].dataPtr)

/**
 * @brief ssGetSimulinkFunctionOutput
 *
 * @param args  Pointer to arguments passed to called C function
 * @param idx   Index of output argument
 */
#define ssGetSimulinkFunctionOutput(args, idx) ((args)->outArgs[(idx)].dataPtr)

/**
 * @brief ssSetSimulinkFunctionArgComplexity
 *
 * @param  S          SimStruct representing an S-Function block
 * @param scopedName  Name of function (or scoped name when the function is being called)
 * @param arg         Name of argument
 * @param val         Complexity of argument
 */
#define ssSetSimulinkFunctionArgComplexity(S, scopedName, arg, val)                               \
    {                                                                                             \
        _ssFunctionArgAttributeInfo locAttrInfo;                                                  \
        locAttrInfo.scopedFcnName = scopedName;                                                   \
        locAttrInfo.argName = arg;                                                                \
        locAttrInfo.argCplx = (int)val;                                                           \
        locAttrInfo.argAttrToSet = SS_SIMULINK_FUNCTION_ARG_CPLX;                                 \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SIMULINK_FUNCTION_ARGUMENT, 0, &locAttrInfo) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }

/**
 * @brief ssSetSimulinkFunctionArgDataType
 *
 * @param  S     SimStruct representing an S-Function block
 * @param scopedName  Name of function (or scoped name when the function is being called)
 * @param arg         Name of argument
 * @param val         Data type of argument
 */
#define ssSetSimulinkFunctionArgDataType(S, scopedName, arg, val)                                 \
    {                                                                                             \
        _ssFunctionArgAttributeInfo locAttrInfo;                                                  \
        locAttrInfo.scopedFcnName = scopedName;                                                   \
        locAttrInfo.argName = arg;                                                                \
        locAttrInfo.argDT = (int)val;                                                             \
        locAttrInfo.argAttrToSet = SS_SIMULINK_FUNCTION_ARG_DTYPE;                                \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SIMULINK_FUNCTION_ARGUMENT, 0, &locAttrInfo) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }

/**
 * @brief ssSetSimulinkFunctionArgDimensions
 *
 * @param  S          SimStruct representing an S-Function block
 * @param scopedName  Name of function (or scoped name when the function is being called)
 * @param arg         Name of argument
 * @param nDims       Number of dimensions of argument
 * @param val         Integer array of dimensions.
 */
#define ssSetSimulinkFunctionArgDimensions(S, scopedName, arg, nDims, val)                        \
    {                                                                                             \
        _ssFunctionArgAttributeInfo locAttrInfo;                                                  \
        locAttrInfo.scopedFcnName = scopedName;                                                   \
        locAttrInfo.argName = arg;                                                                \
        locAttrInfo.argNumDims = nDims;                                                           \
        locAttrInfo.argDims = (size_t*)val;                                                       \
        locAttrInfo.argAttrToSet = SS_SIMULINK_FUNCTION_ARG_DIMS;                                 \
        _ssSafelyCallGenericFcnStart(S)((S), GEN_FCN_SIMULINK_FUNCTION_ARGUMENT, 0, &locAttrInfo) \
            _ssSafelyCallGenericFcnEnd;                                                           \
    }
#endif

/**
 * @brief ssSetArrayLayoutForCodeGen
 *
 * @param S         SimStruct representing an S-Function block
 * @param majority  Type of the array layout configuration of the S-Function TLC
 */
#define ssSetArrayLayoutForCodeGen(S, majority) \
    (S)->blkInfo.sfcnFlags.sCodeGenArrayLayout = (majority)

/** @} */ /* end of SFunctionAPI */

/** @defgroup SigRegion Signal Region APIs
 *  @{
 */

/*======================================*
 * Signal Region                        *
 *======================================*/
#if SS_SL_INTERNAL || SS_SFCN_FOR_SIM

/**
 * @brief ssCallSelectedSignalsFcn
 *
 * Get a list of selected output ports in the current graph.  These ports may be used
 * in ssCallSigListCreateFcn to access the data for these ports.
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidBlock        S-Function block (see ssGetOwnerBlock)
 * @param sigSetOpt        SIGSET_GRAPH or SIGSET_GRAPH_N_CHILDREN
 * @param voidOutPortObjs  Array of port objects;  free using ssCallGenericDestroyFcn
 * @param outnPortObjs     Number of ports returned
 */
#define ssCallSelectedSignalsFcn(S, voidBlock, sigSetOpt, voidOutPortObjs, outnPortObjs)     \
    (S)->mdlInfo->signalAccess->SelectedSignals((voidBlock), (sigSetOpt), (voidOutPortObjs), \
                                                (outnPortObjs))

/**
 * @brief ssCallGenericDestroyFcn
 *
 * Free a Free a port list obtained from ssCallSelectedSignalsFcn
 *
 * @param S                SimStruct representing an S-Function block
 * @param ptr              Port list to destroy
 */
#define ssCallGenericDestroyFcn(S, ptr) (S)->mdlInfo->signalAccess->utFree((ptr))

/**
 * @brief ssCallSigListCreateFcn
 *
 * Get the "signal list" for a given set of ports.  This is used to access data for
 * the given signals
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidBlock        S-Function (see ssGetOwnerBlock)
 * @param nPorts           Number of ports in voidPortObjs
 * @param voidPortObjs     Array of port objects from ssCallSelectedSignalsFcn
 * @param excludeFlags     Options of what to exclude
 * @param voidOutSigList   SL_SigList returned; free using ssCallSigListDestroyFcn
 */
#define ssCallSigListCreateFcn(S, voidBlock, nPorts, voidPortObjs, excludeFlags, voidOutSigList) \
    (S)->mdlInfo->signalAccess->SigListCreate((voidBlock), (nPorts), (voidPortObjs),             \
                                              (excludeFlags), (voidOutSigList))

/**
 * @brief ssCallSigListDestroyFcn
 *
 * Free a SL_SigList created from ssCallSigListCreateFcn
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidSigList      SL_SigList to destroy
 */
#define ssCallSigListDestroyFcn(S, voidSigList) \
    (S)->mdlInfo->signalAccess->SigListDestroy((voidSigList))

/**
 * @brief ssCallSigListUnavailSigAlertFcn
 *
 * Report an error if any signals in the signal list are not available
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidSigList      SL_SigList
 */
#define ssCallSigListUnavailSigAlertFcn(S, voidSigList) \
    (S)->mdlInfo->signalAccess->SigListUnavailSigAlert((voidSigList))

/**
 * @brief ssCallUnselectSigFcn
 *
 * Un-select a given port from the signal list
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidPortObj      Port pointer from ssCallSelectedSignalsFcn
 */
#define ssCallUnselectSigFcn(S, voidPortObj) (S)->mdlInfo->signalAccess->UnselectSig((voidPortObj))

/**
 * @brief ssCallGetPortNameFcn
 *
 * Get the name for a given port. Returns a const char *
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidPortObj      Port pointer from ssCallSelectedSignalsFcn
 */
#define ssCallGetPortNameFcn(S, voidPortObj) (S)->mdlInfo->signalAccess->GetPortName((voidPortObj))

/**
 * @brief ssCallSigListGetNumRegionsFcn
 *
 * Get the number of regions in the idx-th element of the signal list.
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidSigList      SL_SigList
 * @param idx              Index within the signal list
 */
#define ssCallSigListGetNumRegionsFcn(S, voidSigList, idx) \
    (S)->mdlInfo->signalAccess->SigListGetNumRegions((voidSigList), (idx))

/**
 * @brief ssCallSigListGetFirstRegFcn
 *
 * Get the first signal region of the idx-th element of the signal list.
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidSigList      SL_SigList
 * @param idx              Index within the signal list
 */
#define ssCallSigListGetFirstRegFcn(S, voidSigList, idx) \
    (S)->mdlInfo->signalAccess->SigListGetFirstReg((voidSigList), (idx))

/**
 * @brief ssCallSigListGetNumElementsFcn
 *
 * Get the total number of elements in the idx-th element of the signal list.
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidSigList      SL_SigList
 * @param idx              Index within the signal list
 */
#define ssCallSigListGetNumElementsFcn(S, voidSigList, idx) \
    (S)->mdlInfo->signalAccess->SigListGetNumElements((voidSigList), (idx))

/**
 * @brief ssCallSigListGetIfTieWrapFcn
 *
 * Return true if the idx-th element of the signal list is a "tie wrap"
 *
 * @param S                SimStruct representing an S-Function block
 * @param voidSigList      SL_SigList
 * @param idx              Index within the signal list
 */
#define ssCallSigListGetIfTieWrapFcn(S, voidSigList, idx) \
    (S)->mdlInfo->signalAccess->SigListGetIfTieWrap((voidSigList), (idx))

#endif
/** @} */ /* end of SigRegion */


#define ssSetSimStruct(S, srcS) (S)->work.localMdlInfo->simStruct = ((void*)(srcS))

#define ssGetSimStruct(S) (S)->work.localMdlInfo->simStruct

#ifndef USE_PUBLISHED_ONLY
#include "simstruc_internal.h"
#else
#include "simstruc_implement.h"
#endif

#endif /* __SIMSTRUC__ */

#ifdef __clang__
#pragma clang diagnostic pop
#endif

/* EOF: simstruc.h */
