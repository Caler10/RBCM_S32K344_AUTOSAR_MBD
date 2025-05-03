/* Copyright 2010-2021 The MathWorks, Inc. */
/*
 * simulink_solver_api.h
 * API specific to Simulink Solver that needs to be accessed in
 * Rapid accelerator and Rsim
 * ** This file needs to be compilable standalone with standard Raccel/Rsim
 *    compile flags. Any code that calls into Simulink Engine should NOT be
 *    added here.
 * ** Do NOT add additional macros in this file before consulting
 *    Simulink Execution/Solvers Group
 */

#ifndef SIMULINK_SOLVER_API
#define SIMULINK_SOLVER_API

#include "simstruc.h"

/*
 * Continuous state absolute tolerance handling
 */


/*
 * To configure absolute tolerances for S-functions:
 * See documentation for ssSetStateAbsTol
 */



/*
 * ssGetAbsTol (LEGACY MACRO) :  DO NOT USE IN NEW S-FUNCTIONS
 * This macros modifies internal control flags for absolute tolerances
 * and therefore, assumes that you intend to modify all elements
 * of the absolute tolerance vector.
 * Use the following alternatives:
 * 1. If you want to set the abstol, use : ssSetStateAbsTol
 * 2. If you want read-only-access to an abstol elemt, use : ssGetStateAbsTol
 */

#define ssGetAbsTol(S) _ssGetAbsTol(S)

#define ssGetAbsTolVector(S) (const real_T*)(((S)->states.statesInfo2)->absTol)

#define ssGetAbsTolControlVector(S) \
    (const uint8_T*)(((S)->states.statesInfo2)->absTolControl) /*(*uint8_T) */


#if (SS_SL_INTERNAL || SS_GENERATED_S_FUNCTION || SS_RTW_INTERNAL)

#undef ssGetAbsTolVector
#define ssGetAbsTolVector(S) ((S)->states.statesInfo2)->absTol /*   (*real_T)     */
#define ssSetAbsTolVector(S, atol) ((S)->states.statesInfo2)->absTol = (atol)

#undef ssGetAbsTolControlVector
#define ssGetAbsTolControlVector(S) ((S)->states.statesInfo2)->absTolControl /*(*uint8_T) */
#define ssSetAbsTolControlVector(S, atol) ((S)->states.statesInfo2)->absTolControl = (atol)

#define ssGetStateAbsTolControl(S, idx) ((S)->states.statesInfo2)->(S)->absTolControl[idx]

/* Only Set macros to allow Simulink Engine and generated code to set these
 * pointers on mdlInfo for use with legacy code.
 * No one should access/get these pointers for any reason whatsoever in new code.
 */
#define ssSetAbsTolOffset_Obsolete(S, offset) (S)->blkInfo.absTolOffset_Obsolete = (offset)

#define ssSetSolverAbsTol_Obsolete(S, atol) (S)->mdlInfo->solverAbsTol_Obsolete = (atol)
#define ssSetSolverAbsTolControl_Obsolete(S, atol) \
    (S)->mdlInfo->solverAbsTolControl_Obsolete = (atol)

#endif


#endif
