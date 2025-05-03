/* cg_sfun.h 
 *  
 * Entry point for user-written S-Functions when compiled for
 * use with the Simulink C-Code Generator.  This file should
 * be conditionally included at the bottom of any user-written
 * S-Function so as to enable the static functions within it
 * to be registered at startup.  Also, the macro S_FUNCTION_NAME
 * should be declared within the S-Function to specify the
 * entry point name--that is the name by which the S-Function
 * is to be known to the outside world.
 *
 * Copyright 1994-2005 The MathWorks, Inc.
 */

#ifdef __cplusplus
extern "C"
#endif

void S_FUNCTION_NAME(SimStruct *S)
{
#if S_FUNCTION_LEVEL == 1
  /* level 1 */
  ssSetmdlInitializeSizes(S, mdlInitializeSizes);
  ssSetmdlInitializeSampleTimes(S, mdlInitializeSampleTimes); 
  ssSetmdlInitializeConditionsLevel1(S, mdlInitializeConditions);
  ssSetmdlOutputsLevel1(S, mdlOutputs); 
  ssSetmdlUpdateLevel1(S, mdlUpdate); 
  ssSetmdlDerivativesLevel1(S, mdlDerivatives);
  ssSetmdlTerminate(S, mdlTerminate);
#else
  /* user level 2 */

  ssSetmdlInitializeSizes(S, mdlInitializeSizes);
  ssSetmdlInitializeSampleTimes(S, mdlInitializeSampleTimes); 

# if defined(MDL_INITIALIZE_CONDITIONS)
    ssSetmdlInitializeConditions(S, mdlInitializeConditions);
# endif
# if defined(MDL_START)
    ssSetmdlStart(S, mdlStart);
# endif

# if defined(MDL_SETUP_RUNTIME_RESOURCES)
    ssSetmdlSetupRuntimeResources(S, mdlSetupRuntimeResources);
# endif

# if defined(RTW_GENERATED_ENABLE)
    ssSetRTWGeneratedEnable(S, mdlEnable);
# endif

# if defined(RTW_GENERATED_DISABLE)
    ssSetRTWGeneratedDisable(S, mdlDisable);
# endif

# if defined(MDL_ENABLE)
    ssSetmdlEnable(S, mdlEnable);
# endif

# if defined(MDL_DISABLE)
    ssSetmdlDisable(S, mdlDisable);
# endif

  ssSetmdlOutputs(S, mdlOutputs); 
# if defined(MDL_GET_TIME_OF_NEXT_VAR_HIT)
    ssSetmdlGetTimeOfNextVarHit(S, mdlGetTimeOfNextVarHit); 
# endif
# if defined(MDL_UPDATE)
    ssSetmdlUpdate(S, mdlUpdate); 
# endif
# if defined(MDL_DERIVATIVES)
    ssSetmdlDerivatives(S, mdlDerivatives);
# endif

# if defined(MDL_PROJECTION)
    ssSetmdlProjection(S, mdlProjection);
# endif

# if defined(MDL_FORCINGFUNCTION)
    ssSetmdlForcingFunction(S, mdlForcingFunction);
# endif

# if defined(MDL_MASSMATRIX)
    ssSetmdlMassMatrix(S, mdlMassMatrix);
# endif

# if defined(MDL_RTWCG)
    ssSetmdlRTWCG(S, mdlRTWCG);
# endif

# if defined(MDL_ZERO_CROSSINGS) && (defined(MATLAB_MEX_FILE) || defined(NRT))
    ssSetmdlZeroCrossings(S, mdlZeroCrossings);
# endif

# if defined(MDL_CLEANUP_RUNTIME_RESOURCES)
    ssSetmdlCleanupRuntimeResources(S, mdlCleanupRuntimeResources);
# endif

  ssSetmdlTerminate(S, mdlTerminate);
#endif
}
