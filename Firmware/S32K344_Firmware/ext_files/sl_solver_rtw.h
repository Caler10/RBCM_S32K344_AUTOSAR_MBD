#ifndef sl_solver_rtw_h
#define sl_solver_rtw_h
#ifdef SUPPORTS_PRAGMA_ONCE
# pragma once
#endif
/*
 *
 * Copyright 2008-2013 The MathWorks, Inc.
 *
 * This header is the entrance to the sl_solver_rtw module. It is used by the
 * RTW-RSim and Rapid Accelerator targets.
 *
 */

#if defined(RSIM_WITH_SL_SOLVER)
 /*
  * This header is being included by either the RSim or RapidAccelerator runtime
  * interface (both require C linkage)
  */
# define SL_SOLVER_RTW_EXPORT_EXTERN_C  extern
# include "simstruc.h"

#else
# include "package.h"
# if defined(SL_SOLVER_RTW_INTERNAL)
  /*
   * This header is being included by files inside src/sl_solver_rtw
   */
#  define SL_SOLVER_RTW_EXPORT_EXTERN_C  extern "C" DLL_EXPORT_SYM
# else
  /*
   * This file is being include by other internal modules.
   */
#  define SL_SOLVER_RTW_EXPORT_EXTERN_C  extern "C" DLL_IMPORT_SYM
# endif
# include "simstruct/simstruc.h"
#endif

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimEnableDebugOutput(size_t simStructSize,
                                    size_t ssMdlInfoSize);

SL_SOLVER_RTW_EXPORT_EXTERN_C int  getStiffnessFromJacobian( SimStruct* S, 
                   int nx, 
							     double stiffnessThreshold, 
							     double *solverJac, 
							     bool* isStiff, 
							     double* stiffness); 

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimFinalizeAutoSolverForStiffModelsIfNeeded( SimStruct* S, 
                                            const char* slvrJpatternFileName,
                                            int numStatesForStiffnessChecking,
                                            double stiffnessThreshold,
                                            double configsetInitialStepSize ); 

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimCreateSolverData(SimStruct* S, const char* slvrJpatternFileName);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimSetDecoupledContinuousIntegration(SimStruct* S, const bool decoupledContinuousIntegration);
SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimSetOptimalSolverResetCausedByZc(SimStruct* S, const bool optimalSolverResetCausedByZc);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimDestroySolverData( SimStruct* S );

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimInitializeEngine(SimStruct* S);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimAdvanceSolver(SimStruct* S);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimUpdateDiscreteTaskTimesAndSampleHits(SimStruct* S);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimUpdateSolverStopTimeForFixedStepMultiTaskingSim(SimStruct* S);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimUpdateTimingEngineAndSolverStopTime(SimStruct* S);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimTerminateEngine(SimStruct* S, int verbose);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimDisplayTimingData(SimStruct* S,
                                    size_t simStructSize,
                                    size_t ssMdlInfoSize);

SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimInstallAllHandlers(
    SimStruct* S,
    void (*logDataFcn)(SimStruct* s),
    int        timeLimit );
    
SL_SOLVER_RTW_EXPORT_EXTERN_C void rsimUninstallNonfatalHandlers(void);

SL_SOLVER_RTW_EXPORT_EXTERN_C int isVariableStepSolver(const char* slvrName);

SL_SOLVER_RTW_EXPORT_EXTERN_C int isFixedStepSolver(const char* slvrName);

#endif /* sl_solver_rtw_h */

/* LocalWords:  RSim
 */
