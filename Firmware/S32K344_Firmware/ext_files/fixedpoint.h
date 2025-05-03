#include "fixpoint_spec.h"
/* Copyright 1994-2022 The MathWorks, Inc.
 */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef fix_published_intro_h
#define fix_published_intro_h

/* Abstract:
 *
 * The primary motivation of this header file is to allow customers to
 * write C language S-functions that support fixed-point data types.  However,
 * the API in this header extends beyond fixed-point and includes support for
 * standard floating point and integer data types.
 *
 * This header contains definitions and prototypes for use in creating
 * Simulink S-functions that can process a wide variety of data types.
 * These data types include the Simulink builtin data types,
 *     double        single
 *     uint8         int8
 *     uint16        int16
 *     uint32        int32
 * all the MathWorks defined fixed-point data types such as
 *     sfix16_En15
 *     ufix32_En16
 *     ufix128
 *     sfix37_S3_B5
 * and the versions of data types obtained when Data Type Override is set
 * to Scaled Doubles such as
 *     flts16
 *     flts16_En15
 *     fltu32_S3_B5
 *
 * This header file contains functions and definitions that allow S-functions
 * to determine which of these data types an input port or output port is
 * using.  The S-function can also specify which of these data types should
 * be used for an input, output, DWork state, or Runtime Parameter.  The
 * information required to properly read to and write from different variables
 * of each data type is given.
 */

/* Note on License Design:
 *
 * The following comments are simply an attempt to clarify the License Design
 * so that authors can write better S-functions.
 * As of
 *      Release 13
 *      Simulink 5.0
 *      Fixed-Point Blockset 4.0
 * all the blocks from Fixed-Point Blockset were merged into Simulink.  All
 * the blocks are installed even if a user does not have a Fixed-Point License.
 * Simulink customers can use all the blocks with any builtin data types that a
 * block supports.  If all the blocks in a model are only using builtin data
 * types and the Min-Max-Overflow Logging Mode is set to Force Off, then a
 * Fixed-Point License is NOT required.  If any block in a model is "actively"
 * using a non-builtin fixed-point data type or is actively logging Min-Max and/or
 * Overflow information, then a Fixed-Point License will be required for the
 * remainder of that Matlab session.
 *   Even if blocks in a model are configured to have fixed-point signals and/or
 * configured to log Min-Max-Overflow information, then simply loading, viewing,
 * editing, or saving a model should not trigger active use.  Actions such as
 * Update Diagram, Simulation, and Code Generation from such a model are active
 * use and would cause a Fixed-Point License to be checked out.
 *   S-functions written using the API in this header file should be able to
 * follow this license design.  For example, suppose an S-function is written
 * so that it can handle any builtin or fixed-point data type.  Suppose in a
 * particular model, this S-function is processing just builtin data types such
 * as double, single, uint8, or int32.  That use case would not trigger a
 * Fixed-Point License to be checked out.  Suppose in a different model,
 * the S-function was processing non-builtin fixed-point data types.  That use,
 * like any other use of fixed-point data types, would cause a Fixed-Point
 * License to be checked out.
 *   The key pitfall S-function authors must guard against is registering
 * a fixed-point data type when a model is simply being loaded or viewed.  In
 * Simulink jargon, loading or opening a model or sub-system is a
 * "Sizes Call Only."  The Simulink S-function API provides a way to detect a
 * "Sizes Call Only", so by careful programming, an S-function author can avoid
 * Fixed-Point License problems when a user is simply loading or viewing a model.
 */

/* Simulink supports fixed-point data types with any number of bits from
 *    1 to FXP_MAX_BITS for unsigned numbers and
 *    2 to FXP_MAX_BITS for signed numbers.
 * The API in this header file treats pure integers just like
 * any other fixed-point numbers.  Pure integers just happen
 * to have trivial scaling.  The 6 standard Simulink integer
 * types uint8, int8, uint16, int16, uint32, and int32 are not
 * exceptions.  They are treated like fixed-point numbers
 * that happened to have trivial scaling and happened to have
 * 8, 16, or 32 bits.  The same API applies.
 *   Simulink builtin integers are special only in that they do
 * not trigger the need for a Fixed-Point License.
 *
 * The number of bits used to represent a signal in simulation
 * may be more than the number specified.  In this case, the
 * signals will be emulated inside various sized containers
 * according to the following rules.  For 32 or fewer bits, the
 * rules are simple.  For 32 or fewer bits, the container is a
 * scalar integer type directly understood by the compiler.  The
 * case of using a scalar integer type is classified as single-word.
 * The three cases with 32 or fewer bits are shown by a table.
 *
 *   Specified Bits       Container Bits   Container typedef
 *    1 to  8              8               int8_T  or uint8_T
 *    9 to 16             16               int16_T or uint16_T
 *   17 to 32             32               int32_T or uint32_T
 *
 * For 33 or more bits, the rules are more complicated and can
 * depend on the model, the Matlab Host, the current target
 * for code generation, and the version of Simulink Fixed Point
 * being used.  Signals with 33 or more bits will either be stored
 * using a single-word
 * container with more than 32 bits or will be stored using a
 * multi-word representation.
 *
 * All multi-word representations will follow a general form.
 *
 * typedef struct {
 *     SOME_UNSIGNED_CHUNK_TYPE chunks[ NUM_CHUNKS_FOR_M_BITS ];
 * } (u)intM_T
 *
 * The chunk at index zero will hold the least significant bits, and
 * the highest index will hold the most significant bits.
 *
 * Whether single-word or multi-word is used can depend on
 * the model, the Matlab Host, the current
 * target for code generation, and the version of Simulink Fixed Point.
 * The specific type used for SOME_UNSIGNED_CHUNK_TYPE can also vary depending
 * on the model, the Matlab Host, the current target for code generation,
 * and the version of Simulink Fixed Point.
 *
 * To be portable, sfunctions that are intended to support fixed-point
 * signals with more than 32 bits must react to container variations
 * at runtime.  The most general way to do this is to use the interfaces
 * for getting and setting "bit-regions" provided by this header.
 * To support use of code optimized to a specific additional APIs
 * are provided that can query the current properties of a data type.
 * However, sfunction authors need to be aware the properties of a data
 * type can vary depending on
 * the model, the Matlab Host, the current
 * target for code generation, and the version of Simulink Fixed Point.
 * A robustly written sfunction will need to check the properties at runtime
 * at least once after update diagram has started.  The most portable sfunctions
 * will be written so that they can use an optimized case if possible or
 * switch to general bit-region case if necessary.  At the very least,
 * a robust sfunction will need to gracefully set an error if does not
 * have a case that supports the current memory layout.  Keep in mind that
 * supporting every specific case for the current release of Simulink Fixed Point
 * does not guarantee that every specific case in a future release will be
 * covered.  For this reason, it is best to have bit-region case or at
 * the very least gracefully error if needed.
 *
 * For signed numbers, the bit encoding format is always
 * two's complement.
 *
 * When the specified number of bits is less than the size of
 * the container, the desired bits are always stored in the
 * least significant part of the container.  Any "unused" bits
 * are in the most significant part of the container.
 *
 * For both single word case and multiword cases, any unused bits
 * must be set to a sign extension.  If the data type is
 * an unsigned number, then obviously, the number is always
 * nonnegative so the (implicit) sign bit is zero.  For unsigned
 * data types, all unused bits must always be cleared to zero.
 *    If the data type is a signed number, then the sign bit is
 * one for strictly negative numbers and zero otherwise.  If
 * the stored integer is negative, then all unused bits must be
 * set to one.  If the stored integer is positive, then all
 * unused bits must be cleared to zero.
 *
 * Simulink also supports two builtin floating point data types.
 * These are the standard floating point singles and doubles.
 *
 * Simulink also supports a data type category that is a hybrid
 * between floating-point and fixed-point.  This category is
 * called ScaledDouble.  ScaledDouble cases occur when
 * an individual block is configured to have a fixed-point
 * output, but the system it lives in has its Data Type Override
 * setting for a system is set to Scaled Doubles.  The
 * resulting data type has the scaling the fixed-point
 * specification, but stores its output using floating
 * point doubles.  Storing in a double means that overflow
 * and precision issues are almost always eliminated. Removing the
 * range and precision issues is very useful for benchmarking, testing,
 * and debugging.
 *   ScaledDouble data types contain information
 * signedness and number of bits of what their non-overrided data
 * types would have been.  This is useful for information for other
 * portions of the model that are not being debugged with Data Type
 * Override.
 */

#endif /* fix_published_intro_h */
/* Copyright 1994-2022 The MathWorks, Inc.
 */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef fxplimits_h
#define fxplimits_h

#define FXP_MAX_BITS 128

#endif /* fxplimits_h */
/* Copyright 1994-2022 The MathWorks, Inc.
 */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef fxpsimulinkscalingintro_h
#define fxpsimulinkscalingintro_h

/* Simulink Scaling
 *
 * Simulink data types support scaling.  The Fixed-Point User's Guide
 * presents the following general formula.
 *
 *    V = S * Q + B
 *
 * where
 *
 *    V is the Real World Value in the engineering units of choice
 *    Q is the called the Stored Integer Value.  It is the raw value
 *      stored in the digital hardware.  Despite the name Q can use
 *      an integer or a floating point format.
 *    S is the Slope.  For clarity, this is also called the Total-Slope
 *    B is the Bias
 *
 * The Total-Slope is often decomposed into two parts.
 *
 *    S = F * 2^E
 *
 * where
 *
 *   1. <= F < 2.0
 *
 *    F is the Fractional Slope
 *    E is the Fixed Exponent, E is always an integer.
 *
 * If
 *    B == 0.0
 * and
 *    F == 1.0
 * then
 * there is a clean binary point interpretation.
 *
 *    Fraction Length = -1 * Fixed Exponent
 *
 * For example, if
 *    S == 0.125
 *    B == 0.0
 * then
 *    F == 1.0
 *    E == -3
 * so
 *    Fraction Length = 3
 * therefore, this data type has 3 bits to the right of the
 * binary point.
 *
 * The concept of scaling is most useful for fixed-point cases, but
 * it does generalize to all the scalar numeric data types.  For
 * floating point doubles and singles and for pure integers,
 * the scaling is trivial
 *    B == 0
 *    S == 1
 *    F == 1
 *    E == 0
 *    Fraction Length == 0
 * The access methods to get scaling information can be used
 * for all the data types, they just return trivial values
 * when the scaling is trivial.
 */

#endif /* fxpsimulinkscalingintro_h */
/* Copyright 2011-2102 The MathWorks, Inc.
 */
#ifndef SL_TYPES_FXPMODEOVERFLOW_HPP
#define SL_TYPES_FXPMODEOVERFLOW_HPP

/* The enums specify the overflow handling modes supported by most fixed-point
 * math functions.
 */
typedef enum fxpModeOverflow_tag {
    FXP_OVERFLOW_WRAP = 0, /* must be zero */
    FXP_OVERFLOW_SATURATE

} fxpModeOverflow;

#endif /* SL_TYPES_FXPMODEOVERFLOW_HPP */
/* Copyright 2011-2012 The MathWorks, Inc.
 */
#ifndef SL_TYPES_FXPMODEROUNDING_HPP
#define SL_TYPES_FXPMODEROUNDING_HPP

/* The enums specify the rounding modes supported by most fixed-point
 * math functions.
 */
typedef enum fxpModeRounding_tag {
    FXP_ROUND_ZERO = 0, /* must be zero */
    FXP_ROUND_NEAR,
    FXP_ROUND_CEIL,
    FXP_ROUND_FLOOR,
    FXP_ROUND_SIMPLEST,
    FXP_ROUND_NEAR_ML, /* Round -x.5 to -(x+1) not -x so as to match MATLAB. */
    FXP_ROUND_CONVERGENT
} fxpModeRounding;

#define FXP_ROUND_METHOD_COUNT ((FXP_ROUND_CONVERGENT) + 1)

#endif /* SL_TYPES_FXPMODEROUNDING_HPP */
/* Copyright 1994-2022 The MathWorks, Inc.
 */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef fix_published_fxpOverflowLogs_h
#define fix_published_fxpOverflowLogs_h

/* Overflow logging structure
 *
 * Some fixed-point math functions accept a pointer to this structure.
 * These functions will initialize each of the event counts to zero.  Then
 * the functions will carryout the requested math operations.  Each
 * time an event is detect during the math operation the appropriate
 * count will be incremented.  The increment operations makes sure
 * the count does not overflow to zero; it will saturate to the upper limit.
 *
 * For example, suppose a fixed-point conversion function is called. Suppose,
 * one overflow occurred during the conversion.  After the function return,
 * the memory pointed to be overflow logging structure pointer would indicate
 * one overflow, zero saturations, and zero divide-by-zeros.
 */
typedef struct fxpOverflowLogs_tag {
    int OverflowOccurred;
    int SaturationOccurred;
    int DivisionByZeroOccurred;

} fxpOverflowLogs;

#endif /* fix_published_fxpOverflowLogs_h */
/* Copyright 1994-2022 The MathWorks, Inc.
 *
 *
 */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef fix_published_sfun_api_h
#define fix_published_sfun_api_h

#if (defined(COMPILE_FOR_SEA))
/* Expose the System object simstruc.h (via simstruc.hpp) */
#include "systemobject_sfun/simstruc.hpp"
#else
#if (defined(BUILDING_LIBFIXEDPOINT) || defined(DLL_IMPORT_SYM))
/* internal use: include internal copy of simstruc.h */
#include "simstruct/simstruc.h"
#else
/* Expose the simstruc.h */
#include "simstruc.h"
#endif
#endif


/* Function: ssRegisterDataTypeInteger =============================================================
 *
 * This function fully registers any integer data type with Simulink and
 * returns a Data Type Id. Supported types are
 *    Unsigned with wordlength 1 up to 128
 *    Signed   with wordlength 2 up to 128
 *
 * This function is available for any Simulink install, even if
 * Fixed-Point Designer is not installed.
 * If the registered wordlength of the integer is 8, 16, 32, or 64,
 * then a Simulink license is sufficient.
 * For any of the other 124 possible wordlengths,
 * a Fixed-Point Designer license is required.
 *
 *
 * Unlike the standard Simulink function, ssRegisterDataType, additional
 * registration steps do not need to be taken
 * and should not be taken.  The returned Data Type Id can be used to specify
 * the data types of input ports, output ports, RunTimeParameters, and DWork
 * states.  The Data Type Id can also be used with all the standard
 * data type access methods in simstruc.h such as ssGetDataTypeSize.
 *
 * The input arguments are
 *    isSigned              TRUE if signed, FALSE if unsigned
 *    wordLength            total number of bits including any sign bit
 *    obeyDataTypeOverride  if FALSE ignore system's setting for Data Type Override
 *                          if TRUE obey Data Type Override setting, depending
 *                          on Data Type Override, resulting data type could be
 *                          True Double, True Single, Scaled Double, or the
 *                          requested fixed point type.
 *
 * Cautions:
 *
 * 1) If the registered data type is not one of the builtin data types, then
 * a Fixed-Point License will be checked out.  To prevent, a Fixed-Point
 * License from being checked out when a user simply opens or views a model,
 * calls to registration should be protected with
 *    if ( ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY )
 *       ssRegisterDataType ...
 *
 * 2) In general, there is no fixed relationship between the Data Type Id value
 * and the input arguments.  Simulink hands out data type Ids on a first come,
 * first served basis, so small changes to a model can cause a different data
 * type id value to be returned.  Always use functions to get data type
 * attributes from the data type id; never directly rely on the data type
 * id value.
 */
FIXPOINT_EXPORT_EXTERN_C DTypeId ssRegisterDataTypeInteger(SimStruct* S,
                                                           int isSigned,
                                                           int wordLength,
                                                           int obeyDataTypeOverride);



/* Function: ssRegisterDataTypeFxpBinaryPoint ======================================================
 *
 * This function fully registers a fixed-point data type with Simulink and
 * returns a Data Type Id.  Unlike the standard Simulink function,
 * ssRegisterDataType, additional registration steps do not need to be taken
 * and should not be taken.  The returned Data Type Id can be used to specify
 * the data types of input ports, output ports, RunTimeParameters, and DWork
 * states.  The Data Type Id can also be used with all the standard
 * data type access methods in simstruc.h such as ssGetDataTypeSize.
 *
 * The input arguments are
 *    isSigned              TRUE if signed, FALSE if unsigned
 *    wordLength            total number of bits including any sign bit
 *    fractionLength        number of bit to right of binary point
 *    obeyDataTypeOverride  if FALSE ignore system's setting for Data Type Override
 *                          if TRUE obey Data Type Override setting, depending
 *                          on Data Type Override, resulting data type could be
 *                          True Double, True Single, Scaled Double, or the
 *                          requested fixed point type.
 *
 * Cautions:
 *
 * 1) If the registered data type is not one of the builtin data types, then
 * a Fixed-Point License will be checked out.  To prevent, a Fixed-Point
 * License from being checked out when a user simply opens or views a model,
 * calls to registration should be protected with
 *    if ( ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY )
 *       ssRegisterDataType ...
 *
 * 2) There is no fixed relationship between the Data Type Id value and
 * the input arguments.  Simulink hands out data type Ids on a first come, first
 * served basis, so small changes to a model can cause a different data
 * type id value to be returned.  Always uses functions to get data type
 * attributes from the data type id; never directly rely on the data type
 * id value.
 */
FIXPOINT_EXPORT_EXTERN_C DTypeId ssRegisterDataTypeFxpBinaryPoint(SimStruct* S,
                                                                  int isSigned,
                                                                  int wordLength,
                                                                  int fractionLength,
                                                                  int obeyDataTypeOverride);



/* Function: ssRegisterDataTypeFxpSlopeBias ========================================================
 *
 * This function fully registers a fixed-point data type with Simulink and
 * returns a Data Type Id.  Unlike the standard Simulink function,
 * ssRegisterDataType, additional registration steps do not need to be taken
 * and should not be taken.  The returned Data Type Id can be used to specify
 * the data types of input ports, output ports, RunTimeParameters, and DWork
 * states.  The Data Type Id can also be used with all the standard
 * data type access methods in simstruc.h such as ssGetDataTypeSize.
 *
 * The input arguments are
 *    isSigned              TRUE if signed, FALSE if unsigned
 *    wordLength            total number of bits including any sign bit
 *    totalSlope            total slope
 *    bias                  bias
 *    obeyDataTypeOverride  if FALSE ignore system's setting for Data Type Override
 *                          if TRUE obey Data Type Override setting, depending
 *                          on Data Type Override, resulting data type could be
 *                          True Double, True Single, Scaled Double, or the
 *                          requested fixed point type.
 *
 * Cautions:
 *
 * 1) If the registered data type is not one of the builtin data types, then
 * a Fixed-Point License will be checked out.  To prevent, a Fixed-Point
 * License from being checked out when a user simply opens or views a model,
 * calls to registration should be protected with
 *    if ( ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY )
 *       ssRegisterDataType ...
 *
 * 2) There is no fixed relationship between the Data Type Id value and
 * the input arguments.  Simulink hands out data type Ids on a first come, first
 * served basis, so small changes to a model can cause a different data
 * type id value to be returned.  Always uses functions to get data type
 * attributes from the data type id; never directly rely on the data type
 * id value.
 */
FIXPOINT_EXPORT_EXTERN_C DTypeId ssRegisterDataTypeFxpSlopeBias(SimStruct* S,
                                                                int isSigned,
                                                                int wordLength,
                                                                double totalSlope,
                                                                double bias,
                                                                int obeyDataTypeOverride);



/* Function: ssRegisterDataTypeFxpFSlopeFixExpBias =================================================
 *
 * This function fully registers a fixed-point data type with Simulink and
 * returns a Data Type Id.  Unlike the standard Simulink function,
 * ssRegisterDataType, additional registration steps do not need to be taken
 * and should not be taken.  The returned Data Type Id can be used to specify
 * the data types of input ports, output ports, RunTimeParameters, and DWork
 * states.  The Data Type Id can also be used with all the standard
 * data type access methods in simstruc.h such as ssGetDataTypeSize.
 *
 * The input arguments are
 *    isSigned              TRUE if signed, FALSE if unsigned
 *    wordLength            total number of bits including any sign bit
 *    fractionalSlope       fractional slope
 *    fixedExponent         fixed exponent
 *    bias                  bias
 *    obeyDataTypeOverride  if FALSE ignore system's setting for Data Type Override
 *                          if TRUE obey Data Type Override setting, depending
 *                          on Data Type Override, resulting data type could be
 *                          True Double, True Single, Scaled Double, or the
 *                          requested fixed point type.
 *
 * Cautions:
 *
 * 1) If the registered data type is not one of the builtin data types, then
 * a Fixed-Point License will be checked out.  To prevent, a Fixed-Point
 * License from being checked out when a user simply opens or views a model,
 * calls to registration should be protected with
 *    if ( ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY )
 *       ssRegisterDataType ...
 *
 * 2) There is no fixed relationship between the Data Type Id value and
 * the input arguments.  Simulink hands out data type Ids on a first come, first
 * served basis, so small changes to a model can cause a different data
 * type id value to be returned.  Always uses functions to get data type
 * attributes from the data type id; never directly rely on the data type
 * id value.
 */
FIXPOINT_EXPORT_EXTERN_C DTypeId ssRegisterDataTypeFxpFSlopeFixExpBias(SimStruct* S,
                                                                       int isSigned,
                                                                       int wordLength,
                                                                       double fractionalSlope,
                                                                       int fixedExponent,
                                                                       double bias,
                                                                       int obeyDataTypeOverride);



/* Function: ssRegisterDataTypeFxpScaledDouble =====================================================
 *
 * This function fully registers a fixed-point data type with Simulink and
 * returns a Data Type Id.  Unlike the standard Simulink function,
 * ssRegisterDataType, additional registration steps do not need to be taken
 * and should not be taken.  The returned Data Type Id can be used to specify
 * the data types of input ports, output ports, RunTimeParameters, and DWork
 * states.  The Data Type Id can also be used with all the standard
 * data type access methods in simstruc.h such as ssGetDataTypeSize.
 *
 * The input arguments are
 *    isSigned              TRUE if signed, FALSE if unsigned
 *    wordLength            total number of bits including any sign bit
 *    fractionalSlope       fractional slope
 *    fixedExponent         fixed exponent
 *    bias                  bias
 *    obeyDataTypeOverride  if FALSE ignore system's setting for Data Type Override
 *                          if TRUE obey Data Type Override setting, depending
 *                          on Data Type Override, resulting data type could be
 *                          True Double, True Single, Scaled Double, or the
 *                          requested fixed point type.
 *
 * Cautions:
 *
 * 1) If the registered data type is not one of the builtin data types, then
 * a Fixed-Point License will be checked out.  To prevent, a Fixed-Point
 * License from being checked out when a user simply opens or views a model,
 * calls to registration should be protected with
 *    if ( ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY )
 *       ssRegisterDataType ...
 *
 * 2) There is no fixed relationship between the Data Type Id value and
 * the input arguments.  Simulink hands out data type Ids on a first come, first
 * served basis, so small changes to a model can cause a different data
 * type id value to be returned.  Always uses functions to get data type
 * attributes from the data type id; never directly rely on the data type
 * id value.
 */
FIXPOINT_EXPORT_EXTERN_C DTypeId ssRegisterDataTypeFxpScaledDouble(SimStruct* S,
                                                                   int isSigned,
                                                                   int wordLength,
                                                                   double fractionalSlope,
                                                                   int fixedExponent,
                                                                   double bias,
                                                                   int obeyDataTypeOverride);


/* Function: ssRegisterDataTypeHalfPrecision =======================================================
 *
 * This function fully registers a Half precision data type with Simulink and
 * returns a Data Type Id.  Unlike the standard Simulink function,
 * ssRegisterDataType, additional registration steps do not need to be taken
 * and should not be taken.  The returned Data Type Id can be used to specify
 * the data types of input ports, output ports, RunTimeParameters, and DWork
 * states.  The Data Type Id can also be used with all the standard
 * data type access methods in simstruc.h such as ssGetDataTypeSize.
 *
 * The supported half precision (binary16) floating-point format is specified
 * in IEEE 754 standard with following format:
 * . Sign bit: 1 bit
 * . Exponent width: 5 bits
 * . Significand precision 11 bits (10 explicitly stored)
 *
 *  sign  exponent:5bits    fraction:10bits
 * | b15 | b14... ... b10 | b9 ... ... b0   |
 *
 * The input arguments are
 *    obeyDataTypeOverride  if FALSE ignore system's setting for Data Type Override
 *                          if TRUE obey Data Type Override setting, depending
 *                          on Data Type Override, resulting data type could be
 *                          True Double, True Single, Scaled Double, or the
 *                          requested fixed point type.
 *
 * Cautions:
 *
 * 1) When registering Half precision data type, a Fixed-point Designer
 * License will be checked out. To prevent a Fixed-Point Designer License
 * from being checked out when a user simply opens or views a model,
 * calls to registration should be protected with
 *    if ( ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY )
 *       ssRegisterDataType ...
 *
 * 2) There is no fixed relationship between the Data Type Id value and
 * the input arguments.  Simulink hands out data type Ids on a first come, first
 * served basis, so small changes to a model can cause a different data
 * type id value to be returned.  It is recommended to always use functions to
 * get data type attributes from the data type id; never directly rely on
 * the data type id value.
 */
FIXPOINT_EXPORT_EXTERN_C DTypeId ssRegisterDataTypeHalfPrecision(SimStruct* S,
                                                                 int obeyDataTypeOverride);


/* Function: ssGetDataTypeIsFxpFltApiCompat ========================================================
 *
 * Giving a registered Data Type Id as input, determine if it is
 * supported by the API for user written fixed-point and floating-point
 * s-functions.  Support covers all the standard Simulink numeric types
 * double, single, uint8, ..., int32.  It also includes all the Fixed-Point
 * data types, including ScaledDouble versions.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsFxpFltApiCompat(SimStruct* S, DTypeId dataTypeId);


typedef enum fxpStorageContainerCategory_tag {
    FXP_STORAGE_UNKNOWN = 0,
    FXP_STORAGE_DOUBLE,
    FXP_STORAGE_SINGLE,
    FXP_STORAGE_UINT8,
    FXP_STORAGE_INT8,
    FXP_STORAGE_UINT16,
    FXP_STORAGE_INT16,
    FXP_STORAGE_UINT32,
    FXP_STORAGE_INT32,
    FXP_STORAGE_CHUNKARRAY,
    FXP_STORAGE_SCALEDDOUBLE,
    FXP_STORAGE_OTHER_SINGLE_WORD,
    FXP_STORAGE_MULTIWORD,
    FXP_STORAGE_HALFPRECISION
} fxpStorageContainerCategory;


/* Function: ssGetDataTypeStorageContainCat ========================================================
 *
 * Giving a registered Data Type Id as input, determine the Storage Container
 * Category used to represent Input Signals, Output Signals, Run Time
 * Parameters, DWorks, etc. during Simulink Simulations.
 *   Descriptions of the Storage Containers and the definitions of
 * the output fxpStorageContainerCategory are given earlier in this header
 * file.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C fxpStorageContainerCategory
ssGetDataTypeStorageContainCat(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeStorageContainSize =======================================================
 *
 * Giving a registered Data Type Id as input, determine the Storage Container
 * Size used to represent Input Signals, Output Signals, Run Time
 * Parameters, DWorks, etc. during Simulink Simulations.  This is the size
 * that the sizeof() function would return.  This is the appropriate size
 * measurement to pass to functions like memcpy().
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 *
 * This functions gives the same answer as the standard function
 * ssGetDataTypeSize.  This alternate version is only provide to reinforce
 * the distinction between specified word length and container size.  For
 * example, sfix24_En10 is specified to have 24 bits, but it actually is
 * stored in a larger container during Simulink Simulations.  The size of
 * the larger container is returned by this function.  This is the proper
 * value to use for memcpy, malloc, etc.
 */
FIXPOINT_EXPORT_EXTERN_C size_t ssGetDataTypeStorageContainerSize(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeIsFixedPoint =============================================================
 *
 * Giving a registered Data Type Id as input, determine the if the data
 * type is a fixed-point type.  Pure integers including the standard Simulink
 * integer types uint8, int8, uint16, uint32, and int32 are classified
 * as fixed-point types by this function.  Double, Single, Half and
 * ScaledDouble are NOT classified as fixed-point types.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsFixedPoint(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeIsFloatingPoint ==========================================================
 *
 * Giving a registered Data Type Id as input, determine if the data
 * type is a traditional floating-point type.  Double and Single
 * are traditional floating-point types.  ScaledDouble and Half is NOT classified
 * as traditional floating-point types.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsFloatingPoint(SimStruct* S, DTypeId dataTypeId);

/* Function: ssGetDataTypeIsDoubleSingleOrHalf =====================================================
 *
 * Giving a registered Data Type Id as input, determine if the data
 * type is double, single or half precision type specified by IEEE 754 standard.
 * This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsDoubleSingleOrHalf(SimStruct* S, DTypeId dataTypeId);



/* Function: ssGetDataTypeIsHalfPrecision ==========================================================
 *
 * Giving a registered Data Type Id as input, determine if the data
 * type is a Half precision type, which is specified in IEEE754 standard.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsHalfPrecision(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeFxpWordLength ============================================================
 *
 * Giving a registered Data Type Id as input, determine the word length
 * of the data type.
 *     When the data type is fixed-point (including pure
 * integers), the word length is the total number of bits including
 * any sign bits, any bits in the integer part, and any bits in the
 * fractional bits.
 *     When the data type is ScaledDouble, the
 * word length is the total bits the original data type would have
 * used if override had not occurred.  For example, flts32_En4 would
 * have been sfix32_En4 if Data Type Override was off.  The word length is
 * therefore 32 bits.
 *     When the data type is true floating-point, this function errors
 * out.  Word length for a floating-point data type can mean different
 * things to different users.  For some, word length should only be the
 * physical mantissa bits excluding the hidden lead one.  For others,
 * the hidden leading one should be included.  For still others, the
 * word length should be all the physical bits including sign bit,
 * exponent bits, and mantissa bits, but not the hidden bit.  Rather
 * than mislead some users, this function errors out.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeFxpWordLength(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeFxpContainWordLen ========================================================
 *
 * Giving a registered Data Type Id as input, determine the word length
 * of the storage container.
 *    When the data type is fixed-point (including pure
 * integers), the word length is the total number of bits including
 * any sign bits, any bits in the integer part, and any bits in the
 * fractional bits.
 *   The information provided by this function is not meaning full
 * when the data type is ScaledDouble or true floating point.  For
 * these data types, this function will error out.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeFxpContainWordLen(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeFxpIsSigned ==============================================================
 *
 * Giving a registered Data Type Id as input, return true if the data
 * type is signed, and return false if it is unsigned.
 *    When the data type is fixed-point (including pure
 * integers), the meaning of signed or unsigned is obvious.
 *     When the data type is ScaledDouble, the whether the data type
 * is signed or unsigned is determined by what the original data type would
 * have used if override had not occurred.  For example, flts32_En4 would
 * have been sfix32_En4 if Data Type Override was off.  This uses a signed
 * integer so the return value is true.  Conversely, fltu8_S3 would have
 * used ufix8_S3 which is unsigned, so false would be returned.
 *     When the data type is true floating-point, this function errors
 * out.  Asking whether a floating point number is signed or unsigned causes
 * some confusion, so this is prevented.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeFxpIsSigned(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeIsScalingTrivial =========================================================
 *
 * Giving a registered Data Type Id as input, determine if the scaling
 * is the trivial case of
 *    Slope   S == 1.0
 *    Bias    B == 0.0
 * This is always true for pure integers like int8 and for the true floating
 * point types double and single.  It will also be true for ScaledDouble
 * of pure integers such as flts8.  For binary point scaling, trivial means
 * the binary point is just to the right of the least significant bit.
 * Equivalently, the fraction length is zero.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsScalingTrivial(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeIsScalingPow2 ============================================================
 *
 * Giving a registered Data Type Id as input, determine if the scaling
 * is an exact power of two
 *    Fractional Slope   F == 1.0
 *    Bias               B == 0.0
 * If the scaling is trivial, then the answer is true.  For fixed-point
 * cases, the answer is true if there is a clean binary point interpretation
 * of the scaling.
 *    Many fixed-point algorithms are only designed to handle power of
 * two scaling.  For this algorithms, this function can be called in
 * mdlSetInputPortDataType and mdlSetOutputPortDataType to prevent
 * unsupported data types from being accepted.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsScalingPow2(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeFractionLength ===========================================================
 *
 * Giving a registered Data Type Id as input, determine the fraction
 * length for data types that use power of two scaling.
 *    This function should be called only if ssGetDataTypeIsScalingPow2
 * returns true.  It errors out otherwise.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeFractionLength(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeTotalSlope ===============================================================
 *
 * Giving a registered Data Type Id as input, determine the scalings
 * total slope.
 *    S = F * 2^E
 * where
 *   1. <= F < 2.0
 *   S is the Total Slope
 *   F is the Fractional Slope
 *   E is the Fixed Exponent, E is always an integer
 *
 *     When the data type is ScaledDouble, the slope is determined by
 * what the original data type would  have used if override had not occurred.
 * For example, flts32_En4 would have been sfix32_En4 if Data Type Override was
 * off.  The total slope is 0.0625 = 2^-4.   For fltu16_S7p98, the total
 * slope is 7.98
 *     When the data type has trivial scaling, including floating point
 * double and single, the total slope is the trivial value 1.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C double ssGetDataTypeTotalSlope(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeBias =====================================================================
 *
 * Giving a registered Data Type Id as input, determine the scalings
 * bias.
 *     When the data type is ScaledDouble, the slope is determined by
 * what the original data type would  have used if override had not occurred.
 * For example, flts32_En4 would have been sfix32_En4 if Data Type Override was
 * off.  The bias is simply 0.   For fltu16_S3_Bn55p32, the total
 * slope is -55.32
 *     When the data type has trivial scaling, including floating point
 * double and single, the bias is the trivial value 0.  Likewise, when
 * the data type has power of two scaling, the bias is always the trivial
 * value 0.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C double ssGetDataTypeBias(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeFracSlope ================================================================
 *
 * Giving a registered Data Type Id as input, determine the scalings
 * fractional slope.
 *    S = F * 2^E
 * where
 *   1. <= F < 2.0
 *   S is the Total Slope
 *   F is the Fractional Slope
 *   E is the Fixed Exponent, E is always an integer
 *
 *     When the data type is ScaledDouble, the slope is determined by
 * what the original data type would  have used if override had not occurred.
 * For example, flts32_En4 would have been sfix32_En4 if Data Type Override was
 * off.  This case has power of two scaling, so the fractional slope is the
 * trivial case 1.   For fltu16_S3, the total slope is 3 which is decomposed
 * into Fixed Exponent +1 and Fractional Slope 1.5
 *     When the data type has trivial scaling, including floating point
 * double and single, the total slope is the trivial value 1.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C double ssGetDataTypeFracSlope(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeFixedExponent ============================================================
 *
 * Giving a registered Data Type Id as input, determine the scalings
 * fixed exponent.
 *    S = F * 2^E
 * where
 *   1. <= F < 2.0
 *   S is the Total Slope
 *   F is the Fractional Slope
 *   E is the Fixed Exponent, E is always an integer
 *
 * When the data type a clean binary point interpretation, the Fixed Exponent is
 * simply the negative of the Fraction Length.
 *     When the data type is ScaledDouble, the fixed exponent is determined by
 * what the original data type would  have used if override had not occurred.
 * For example, flts32_En4 would have been sfix32_En4 if Data Type Override was
 * off.  This case has power of two scaling with fraction length +4 and
 * Fixed Exponent -4.   For fltu16_S3, the total slope is 3 which is decomposed
 * into Fixed Exponent +1 and Fractional Slope 1.5
 *     When the data type has trivial scaling, including floating point
 * double and single, the fixed exponent is the trivial value 0.
 *   This function will error out if ssGetDataTypeIsFxpFltApiCompat
 * returns false.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeFixedExponent(SimStruct* S, DTypeId dataTypeId);


/* Function: ssGetDataTypeIsInteger
 *
 * Giving a registered Data Type Id, determine the if the data
 * type is one of 255 integer types supported by Simulink.
 *     Unsigned with wordlength 1 up to 128
 *     Signed   with wordlength 2 up to 128
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsInteger(SimStruct* S, DTypeId dataTypeId);

/* Function: ssGetDataTypeIsSpecifiedInteger
 *
 * Giving a registered Data Type Id, determine
 * if the data type is an integer with the specified
 * signedness and wordlength.
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeIsSpecifiedInteger(SimStruct* S,
                                                             DTypeId dataTypeId,
                                                             int isSigned,
                                                             int wordLength);


FIXPOINT_EXPORT_EXTERN_C void ssFxpConvert(SimStruct* S,

                                           void* pVoidDest,
                                           size_t sizeofDest,
                                           DTypeId dataTypeIdDest,

                                           const void* pVoidSrc,
                                           size_t sizeofSrc,
                                           DTypeId dataTypeIdSrc,

                                           fxpModeRounding roundMode,
                                           fxpModeOverflow overflowMode,

                                           fxpOverflowLogs* pFxpOverflowLogs);



FIXPOINT_EXPORT_EXTERN_C double ssFxpConvertToRealWorldValue(SimStruct* S,
                                                             const void* pVoidSrc,
                                                             size_t sizeofSrc,
                                                             DTypeId dataTypeIdSrc);



FIXPOINT_EXPORT_EXTERN_C void ssFxpConvertFromRealWorldValue(SimStruct* S,

                                                             void* pVoidDest,
                                                             size_t sizeofDest,
                                                             DTypeId dataTypeIdDest,

                                                             double dblRealWorldValue,

                                                             fxpModeRounding roundMode,
                                                             fxpModeOverflow overflowMode,

                                                             fxpOverflowLogs* pFxpOverflowLogs);


/* Function ssGetDataTypeNumberOfChunks
 *
 * Giving a dataTypeId as Input, return the number of chunks the container uses.
 *
 */
FIXPOINT_EXPORT_EXTERN_C int ssGetDataTypeNumberOfChunks(SimStruct* S, DTypeId dataTypeId);


/* Function ssFxpGetU32BitRegion
 *
 * This function accesses a fixed point data and returns the stored integer
 * value for the 32 bit region specified by region index. RegionIndex could
 * be any non-negative values. Emulation bits get padded if the RegionIndex
 * is larger than the data size.
 *
 * The input parameters are
 *       pVoid:   a void point to a memory area.
 *       dataTypeId:  a registered fixed point dataTypeId.
 *       regionIndex: the specified 32 bit region.
 *
 * Caution:
 * This function requires dataTypeId to be a valid fixed point data. Floating
 * point data is not supported.
 */
FIXPOINT_EXPORT_EXTERN_C uint32_T ssFxpGetU32BitRegion(SimStruct* S,

                                                       const void* pVoid,

                                                       DTypeId dataTypeId,

                                                       unsigned int regionIndex);


/* Function ssFxpSetU32BitRegion
 *
 * This function directly sets the 32 bit region specified by region index for
 * a fixed point data. RegionIndex could be any non-negative values, but only
 * physical bits get written. It will error out if regionValue violates sign
 * extension of the fixed point data.
 *
 * The input parameters are
 *       pVoid:   a void point to a fixed point data.
 *       dataTypeId:  a valid fixed point data type id.
 *       regionValue: the value to be written to the 32 bit region.
 *       regionIndex: the specified 32 bit region.
 *
 * Caution:
 * This function requires dataTypeId to be a valid fixed point data. Floating
 * point data is not supported.
 */
FIXPOINT_EXPORT_EXTERN_C void ssFxpSetU32BitRegion(SimStruct* S,

                                                   void* pVoid,

                                                   DTypeId dataTypeId,

                                                   uint32_T regionValue,

                                                   unsigned int regionIndex);


/* Function: ssLogFixptInstrumentation =============================================================
 *    Record information collected during simulation, such as
 *    output maximum, minimum, and counts of any overflows, saturations, or
 *    divisions by zero that occurred.
 */
FIXPOINT_EXPORT_EXTERN_C void ssLogFixptInstrumentation(SimStruct* S,
                                                        DTypeId dataTypeId,
                                                        double minValue,
                                                        double maxValue,
                                                        int countOverflows,
                                                        int countSaturations,
                                                        int countDivisionsByZero,
                                                        char* pStrName);


/* These two functions are obsolete and can be ignored.
 * They no longer have any impact on the memory layout for inputs and outputs.
 * The memory layout introduced in R2008a is always used.
 */
FIXPOINT_EXPORT_EXTERN_C void ssFxpSetU32BitRegionCompliant(SimStruct* S, int value);
FIXPOINT_EXPORT_EXTERN_C void ssFxpGetU32BitRegionCompliant(SimStruct* S, int* result);


#endif /* fix_published_sfun_api_h */
/* Copyright 1994-2022 The MathWorks, Inc.
 */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef fix_published_deprecated_h
#define fix_published_deprecated_h

/* Deprecated items provided only for backwards compatibility */

/* The term Doubles-Override is outdated and misleading.
 * Instead, the terms Data-Type-Override and Scaled-Doubles should be used
 * as appropriate.
 * The follow definition is provided for backwards compatibility
 */
#define FXP_STORAGE_DOUBLESOVERRIDE FXP_STORAGE_SCALEDDOUBLE
#define FXP_DT_FIXPT_DBL_OVER FXP_DT_SCALED_DOUBLE
#define fxpIsDataTypeFixPtDblOver(pFxpDataTypeProp) fxpIsDataTypeScaledDouble(pFxpDataTypeProp)
#define fxpIsDataTypeFloatOrDblOver(pFxpDataTypeProp) \
    (fxpIsDataTypeDoubleOrSclDbl(pFxpDataTypeProp) || fxpIsDataTypeSingle(pFxpDataTypeProp))


#endif /* fix_published_deprecated_h */
