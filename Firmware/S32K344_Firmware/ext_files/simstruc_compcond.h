/* Copyright 1990-2017 The MathWorks, Inc. */

/**
 * @file: simstruc_compcond.h
 *
 * @brief Defines controlling conditional compilation
 *
 */

#ifndef __SIMSTRUC_COMPCOND__
#define __SIMSTRUC_COMPCOND__

/*===========================================================================*
 * BEGIN SECTION
 * LIST OF KEY DEFINES CONTROLLING CONDITIONAL COMPILATION
 *
 * Simstruc properties such as definitions, access methods, etc.
 * are conditionally compiled depending on "who" is using the simstruc
 * and in what mode.
 *
 * This section list all the key #define macros controlling the inclusion/
 * exclusion of features, definitions, etc.
 *
 * Typically, this section only assigns a default value (such as false).
 * The final value is adjusted in a subsequent section.
 *===========================================================================*/

/*=======================================================*
 * MODE: SINGLE-TASKING OR MULTI-TASKING
 */
#define SS_MULTITASKING (0)

/*=======================================================*
 * MODE: SIMULATION OR GENERATED CODE
 *
 * The following #defines determine whether the simstruc is used in "normal"
 * Simulink simulation or in Real Time Workshop generated code.
 *
 * This is designed to be a mutually exclusive set.
 * One and only one should be defined to be true.
 */
#define SS_SIM (0)
#define SS_RTW (0)

/*=======================================================*
 * MODE: WHO IS USING THE SIMSTRUC
 *
 * The following #defines determine "who" is using the simstruc.
 *
 * This is designed to be a mutually exclusive set.
 * One and only one should be defined to be true.
 */
#define SS_SFCN_LEVEL_1 (0)
#define SS_SFCN_NORMAL (0)
#define SS_GENERATED_S_FUNCTION (0)
#define SS_SL_INTERNAL (0)
#define SS_RTW_INTERNAL (0)
#define SS_SHARED_MODULE (0)

/*=======================================================*
 * MODE: GENERATED CODE IS REAL-TIME OR NON-REAL-TIME
 *
 * Both can be false, but both can't be true
 */
#define SS_RT (0)
#define SS_NRT (0)

/*=======================================================*
 * MODE: ENFORCE NDEBUG
 */
#define SS_NDEBUG (0)

/*=======================================================*
 * MODE: ENVIRONMENT HAS STANDARD IO AVAILABLE
 */
#define SS_HAVESTDIO (0)

/*=======================================================*
 * MODE: TID_EQUALS_SAMPLE_TIME_INDEX -
 *     The model will function correctly if this define is false, however if
 *     this define is true the model's performance may be increased depending
 *     upon whether or not the model has fast to slow rate transitions.
 */
#define TID_EQUALS_SAMPLE_TIME_INDEX (0)

/*=======================================================*
 * MODE: TID01EQ == 1
 */
#define SS_TID01EQ_EQUAL_ONE (0)

/*===========================================================================*
 * END SECTION
 * LIST OF KEY DEFINES CONTROLLING CONDITIONAL COMPILATION
 *===========================================================================*/

#ifndef _SIMSTRUCT
#define _SIMSTRUCT
/*
 * Use incomplete type for function prototypes within SimStruct itself
 */
typedef struct SimStruct_tag SimStruct;
#endif

/*=================*
 * Nested includes *
 *=================*/
#include <limits.h>
#include <string.h>
#include "simstruc_types.h"
#include "solver_zc.h"

#include "stdio.h"

/*===========================================================================*
 * BEGIN SECTION
 * DETERMINE FINAL VALUES OF KEY DEFINES CONTROLLING CONDITIONAL COMPILATION
 *===========================================================================*/

/*====================================*
 * Model reference sim target is an RTW generated
 * S-Function (from the point view of Simstruct).
 */
#if defined(MDL_REF_SIM_TGT)

#undef MATLAB_MEX_FILE
#define MATLAB_MEX_FILE (1)

#undef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION (1)

#endif

/*====================================*
 * Determine => MODE: SINGLE-TASKING OR MULTI-TASKING
 *
 * This must come after the inclusion of simstruc_types.h
 */
#if defined(MULTITASKING)
#undef SS_MULTITASKING
#define SS_MULTITASKING (1)
#endif

/*====================================*
 * Determine => MODE: SIMULATION OR GENERATED CODE
 */
#if defined(MATLAB_MEX_FILE) || defined(SL_INTERNAL) || defined(FIPXT_SHARED_MODULE)
#undef SS_SIM
#define SS_SIM (1)
#else
#undef SS_RTW
#define SS_RTW (1)
#endif

/*====================================*
 * Determine => MODE: WHO IS USING THE SIMSTRUC
 */
#if !defined(S_FUNCTION_LEVEL)
#if defined(S_FUNCTION_NAME)
#define S_FUNCTION_LEVEL 1 /* Backwards compatibility old S-functions */
#else
#define S_FUNCTION_LEVEL 2
#endif
#endif

#if S_FUNCTION_LEVEL != 1 && S_FUNCTION_LEVEL != 2
#error Invalid S_FUNCTION_LEVEL
#endif

#if defined(RTW_GENERATED_S_FUNCTION)
/*
 * Used by RTW Generated S Function, ex  s-fcn target.
 * This flag is independent of how the
 * s-function is built (i.e., it is a #define in the code, not a build
 * flag).  It is true when building the s-function for use with simulink and
 * when building the s-function for use with RTW.
 */
#undef SS_GENERATED_S_FUNCTION
#define SS_GENERATED_S_FUNCTION (1)

#elif S_FUNCTION_LEVEL == 1
/*
 * Used with any LEVEL 1 s-function (user written) including:
 *  o build for use with a normal simulation (via mex command)
 *  o build for use with rtw (grt)
 */
#undef SS_SFCN_LEVEL_1
#define SS_SFCN_LEVEL_1 (1)

#elif defined(S_FUNCTION_NAME)
/*
 * Used with any s-function (user written) including:
 *  o build for use with a normal simulation (via mex command)
 *  o build for use with rtw (grt)
 */
#undef SS_SFCN_NORMAL
#define SS_SFCN_NORMAL (1)

#elif defined(SL_INTERNAL) || defined(RSIM_WITH_SL_SOLVER)
/*
 * Used internally by Simulink (simulink.dll).
 */
#undef SS_SL_INTERNAL
#define SS_SL_INTERNAL (1)

#elif defined(RT) || defined(NRT)
/*
 * Used in "root" model of generated code, but not in
 * non-inlined, s-functions being compiled for use with the
 * generated code (i.e., rt_main and model.c have access, but
 * sfunc.c does not).
 */
#undef SS_RTW_INTERNAL
#define SS_RTW_INTERNAL (1)

#elif defined(FIPXT_SHARED_MODULE)
/*
 * Used in shared module (such as a dll) that needs to be able to
 * use some feature of the simstruc.
 */
/*
 * Currently, shared module will be treated as if they are
 * normal sfunctions.
 *
# undef  SS_SHARED_MODULE
# define SS_SHARED_MODULE  (1)
*/
#undef SS_SFCN_NORMAL
#define SS_SFCN_NORMAL (1)

#elif defined(MATLAB_MEX_FILE)
/*  Used in mex function that is NOT an S-Function mex
 */
/*
 * Currently, plain mex functions will be treated as if they are
 * normal sfunctions.
 *
# undef  SS_MEX
# define SS_MEX  (1)
*/
#undef SS_SFCN_NORMAL
#define SS_SFCN_NORMAL (1)

#else
#error Unrecognized use.
#endif

/*=======================================================*
 * Determine => MODE: GENERATED CODE IS REAL-TIME OR NON-REAL-TIME
 */
#if defined(RT)
#undef SS_RT
#define SS_RT (1)
#endif
#if defined(NRT)
#undef SS_NRT
#define SS_NRT (1)
#endif

/*=======================================================*
 * Determine => MODE: ENFORCE NDEBUG
 */
#if defined(NDEBUG) /* sbcheck: ok(NDEBUG) */
#undef SS_NDEBUG
#define SS_NDEBUG (1)
#endif

/*=======================================================*
 * Determine => MODE: ENVIRONMENT HAS STANDARD IO AVAILABLE
 */
#if defined(HAVESTDIO)
#undef SS_HAVESTDIO
#define SS_HAVESTDIO (1)
#endif

/*=======================================================*
 * Determine => MODE: TID_EQUALS_SAMPLE_TIME_INDEX -
 */
#if SS_SL_INTERNAL
#undef TID_EQUALS_SAMPLE_TIME_INDEX
#define TID_EQUALS_SAMPLE_TIME_INDEX (1)
#else
#if defined(NUMST) && defined(NSAMPLE_TIMES)
#if NUMST < NSAMPLE_TIMES
#error NUMST specified incorrectly
#elif NUMST == NSAMPLE_TIMES
#undef TID_EQUALS_SAMPLE_TIME_INDEX
#define TID_EQUALS_SAMPLE_TIME_INDEX (1)
#endif
#endif
#endif

/*=======================================================*
 * Determine => MODE: TID01EQ == 1
 */
#if defined(TID01EQ)
#if TID01EQ == 1
#undef SS_TID01EQ_EQUAL_ONE
#define SS_TID01EQ_EQUAL_ONE (1)
#endif
#endif

/*=======================================================*
 * Determine => MODE: ACCESS 32-BIT OR 64-BIT OR BOTH SIMSTRUCT FIELDS
 */
#if defined(SFCN64) ||                                                        \
    ((defined(SL_INTERNAL) || defined(IS_RSIM) || defined(IS_RAPID_ACCEL)) && \
     !(defined(RTW_GENERATED_S_FUNCTION) || defined(MATLAB_MEX_FILE) || defined(S_FUNCTION_NAME)))
#define USE_64BIT_FIELDS
#else
#define USE_32BIT_FIELDS
#endif

/*===========================================================================*
 * END SECTION
 * DETERMINE FINAL VALUES OF KEY DEFINES CONTROLLING CONDITIONAL COMPILATION
 *===========================================================================*/


/*===========================================================================*
 * BEGIN SECTION
 * CHECK PROPER USAGE
 *
 * Issue errors if incompatible modes have been selected
 *===========================================================================*/

#if (defined(RT) + defined(NRT) + defined(MATLAB_MEX_FILE) + defined(SL_INTERNAL) + \
         defined(FIPXT_SHARED_MODULE) !=                                            \
     1)
#error Must define one of RT, NRT, MATLAB_MEX_FILE, SL_INTERNAL, or FIPXT_SHARED_MODULE
#if defined(RT)
#error defined(RT)
#endif
#if defined(NRT)
#error defined(NRT)
#endif
#if defined(MATLAB_MEX_FILE)
#error defined(MATLAB_MEX_FILE)
#endif
#if defined(SL_INTERNAL)
#error defined(SL_INTERNAL)
#endif
#if defined(FIPXT_SHARED_MODULE)
#error defined(FIPXT_SHARED_MODULE)
#endif
#endif

#if (defined(NRT) && SS_MULTITASKING)
#error NRT does not support MULTITASKING
#endif

#if (SS_SIM && SS_MULTITASKING)
#error MATLAB/Simulink does not support MULTITASKING
#endif

#if (defined(USE_32BIT_FIELDS) + defined(USE_64BIT_FIELDS)) != 1
#error Must define one of USE_32BIT_FIELDS or USE_64BIT_FIELDS
#if defined(USE_32BIT_FIELDS)
#error defined(USE_32BIT_FIELDS)
#endif
#if defined(USE_64BIT_FIELDS)
#error defined(USE_64BIT_FIELDS)
#endif
#endif

/*===========================================================================*
 * END SECTION
 * CHECK PROPER USAGE
 *
 * Issue errors if incompatible modes have been selected
 *===========================================================================*/


/*===========================================================================*
 * BEGIN SECTION
 * DETERMINE GROUP DEFINES
 *
 * Group defines are derived from the "KEY DEFINES" listed and determined
 * in previous sections.
 *===========================================================================*/

#if (SS_SFCN_LEVEL_1 || SS_SFCN_NORMAL || SS_GENERATED_S_FUNCTION)
#define SS_SFCN (1)
#else
#define SS_SFCN (0)
#endif


#define SS_SFCN_FOR_SIM (0)
#define SS_SFCN_FOR_RTW (0)
#if SS_SFCN
#if SS_SIM
/*
 * Used for s-functions (user written or s-fcn target) that are being
 * compiled for use with simulink.dll (i.e., for a regular sim).  Includes:
 *      o build for use with normal simulation (via mex command)
 *
 *  but does not include:
 *
 *      o build for use with rtw (grt)
 */
#undef SS_SFCN_FOR_SIM
#define SS_SFCN_FOR_SIM (1)
#else
#undef SS_SFCN_FOR_RTW
#define SS_SFCN_FOR_RTW (1)
#endif
#endif

#define SS_DEBUG_FOR_SIM (SS_SFCN_FOR_SIM && !SS_NDEBUG)

/*===========================================================================*
 * END SECTION
 * DETERMINE GROUP DEFINES
 *
 * Group defines are derived from the "KEY DEFINES" listed and determined
 * in previous sections.
 *===========================================================================*/

/*
 * Include headers for MATLAB API function prototypes (e.g. mxGetPr)
 */
#if SS_SL_INTERNAL
#if defined(RSIM_WITH_SL_SOLVER)
/*
 * Run-time interface for Real-Time Workshop RSIM Full target.
 */
#ifdef IS_RAPID_ACCEL
#include "matrix.h"
#else
#include "rt_matrx.h"
#endif
#else
/*
 * Using within Simulink itself
 */
#include <stdlib.h>
#include <stdarg.h>
#include "matrix.h"
#include "sl_sfcn_st_api.h"
#endif

#elif SS_SFCN_FOR_SIM
/*
 * Used in simulation by sfunction
 */
#include <stdlib.h>
#include <stdarg.h>
#include "mex.h"
#include "sl_sfcn_st_api.h"
#if !defined(S_FUNCTION_NAME)
#define _S_FUNCTION_NAME_NOT_DEFINED_BEFORE_SIMSTRUCT
#endif
#elif SS_SFCN_FOR_RTW
/*
 * Used in RTW by sfunction
 */
#include "rt_matrx.h" /* S-function is being used with Real-Time Workshop */
#elif SS_RTW_INTERNAL
/*
 * Run-time interface for Real-Time Workshop
 */
#if !defined(TYPEDEF_MX_ARRAY)
#define TYPEDEF_MX_ARRAY
typedef real_T mxArray;
#endif
#else
/*
 * Error
 */
#error Unhandled case
#endif

#if defined(ENABLE_SLEXEC_SSBRIDGE)
/*
 * Prototypes of functions exported from slexec_simbridge component
 */
#include "slexec_simstruct_bridge.h"
#endif

#include "slexec_block_runtime_service.h"

/*===========================================================================*
 *===========================================================================*
 *===========================================================================*
 * WARNING: For maintainability:
 *
 * Conditional Compilation below this point should only depend on
 *    KEY DEFINES
 * or
 *    GROUP DEFINES
 * that where determined in the sections above.
 *
 * In particular, #if and #elif should only depend on the KEY DEFINES and/or
 * GROUP DEFINES.
 *
 * All the KEY DEFINES and GROUP DEFINES always have definitions.  Therefore,
 * the preprocessor directives defined(), #ifdef, and #ifndef are not needed
 * below, and their use indicates a likely maintainability problem.  The
 * only exception is the use of #ifndef in the standard technique for guarding
 * against multiple inclusion and multiple definition.
 *===========================================================================*
 *===========================================================================*
 *===========================================================================*/
#endif
