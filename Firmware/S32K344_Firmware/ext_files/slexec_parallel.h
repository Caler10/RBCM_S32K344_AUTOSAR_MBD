#ifndef SLEXEC_PARALLEL_H
#define SLEXEC_PARALLEL_H

/* Copyright 2008-2020 The MathWorks, Inc. */

/**
 * @file slexec_parallel.h
 *
 * This header is the exported interface to the simulink/execution/parallel. 
 * It is used by the Rapid Accelerator targets.
 *
 *
 */


#include "tmwtypes.h"

#ifdef BUILDING_LIBMWSLEXEC_PARALLEL
  /* being included from inside slexec_parallel module */
  #include "package.h"
  #define SLEXEC_PARALLEL_PUBLISHED_C extern "C" DLL_EXPORT_SYM
#else
  /* being included from outside, such as raccel code */
  #if defined(__cplusplus)
    /* Needed for non-inlined C++ S-functions */
    #define SLEXEC_PARALLEL_PUBLISHED_C extern "C"
  #else 
    #define SLEXEC_PARALLEL_PUBLISHED_C extern
  #endif
#endif

typedef void (*ParallelForTaskFunction)(int);

typedef enum {
    PARALLEL_EXECUTION_AUTO = -1,
    PARALLEL_EXECUTION_OFF = 0,
    PARALLEL_EXECUTION_ON = 1
} ParallelExecutionMode;

typedef struct ParallelExecutionOptions_tag {
    int numberOfNodes;
    ParallelExecutionMode parallelExecutionMode;
    int numberOfThreads;
    int numberOfStepsToAnalyze;
    boolean_T enableTiming;
    boolean_T dumpProfilingInfo;
    const char* timingOutputFilename;
    const char* nodeExecutionModesFilename;
} ParallelExecutionOptions;


SLEXEC_PARALLEL_PUBLISHED_C void initialize_parallel_execution(
    ParallelExecutionOptions options);

SLEXEC_PARALLEL_PUBLISHED_C void analyze_parallel_execution(void);

SLEXEC_PARALLEL_PUBLISHED_C void parallel_for(
    int loopSize, 
    ParallelForTaskFunction taskFunction, 
    int execMode,
    const char_T* taskFuncName);

#endif

/* LocalWords:  raccel
 */
