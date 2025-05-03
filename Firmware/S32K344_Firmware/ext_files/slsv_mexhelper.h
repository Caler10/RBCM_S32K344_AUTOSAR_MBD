/* Copyright 2014-2022 The MathWorks, Inc. */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef SLSV_MEXHELPER
#define SLSV_MEXHELPER

#ifndef DLL_EXPORT_SYM
#ifdef SL_INTERNAL
#include "package.h"
#else
#define DLL_EXPORT_SYM
#endif
#endif

#ifdef __cplusplus
#define SL_SERVICES_EXPORT_EXTERN_C extern "C" DLL_EXPORT_SYM
#else
#define SL_SERVICES_EXPORT_EXTERN_C extern DLL_EXPORT_SYM
#endif

#include "matrix.h"

/* ////////////////////////////////////////////////////////////////////////
 * This code is used to override calls to the mex api made from dynamically
 * loaded s-functions in rapid-accelerator (see g1472731). */

typedef bool (*RAccelMexIsLocked)(void);

typedef int (*RAccelMexPutVar)(const char*, const char*, const mxArray*);

typedef const mxArray* (*RAccelMexGetVarPtr)(const char*, const char*);

typedef mxArray* (*RAccelMexGetVar)(const char*, const char*);

typedef void (*RAccelMexLock)(void);

typedef void (*RAccelMexUnlock)(void);

typedef const char* (*RAccelMexFunctionName)(void);

typedef int (*RAccelMexEvalString)(const char*);

typedef mxArray* (*RAccelMexEvalStringWithTrap)(const char*);

typedef int (*RAccelMexSet)(double, const char*, mxArray*);

typedef const mxArray* (*RAccelMexGet)(double, const char*);

typedef int (*RAccelMexCallMatlab)(int, mxArray* plhs[], int, mxArray* prhs[], const char*, bool);

typedef mxArray* (
    *RAccelMexCallMatlabWithTrap)(int, mxArray* plhs[], int, mxArray* prhs[], const char*);

typedef mxArray* (*RAccelMexCreateSimpleFunctionHandle)(mxFunctionPtr f);

typedef int (*RAccelMexAtExit)(void (*exitFcn)(void));

typedef bool (*RAccelMexSetMexTrapFlag)();

typedef struct RAccelMexCallbacks_T {
    RAccelMexIsLocked isLocked_;
    RAccelMexPutVar putVar_;
    RAccelMexGetVarPtr getVarPtr_;
    RAccelMexGetVar getVar_;
    RAccelMexLock lock_;
    RAccelMexUnlock unlock_;
    RAccelMexFunctionName functionName_;
    RAccelMexEvalString evalString_;
    RAccelMexEvalStringWithTrap evalStringWithTrap_;
    RAccelMexSet set_;
    RAccelMexGet get_;
    RAccelMexCallMatlab mexCallMatlab_;
    RAccelMexCallMatlabWithTrap mexCallMatlabWithTrap_;
    RAccelMexCreateSimpleFunctionHandle createSimpleFunctionHandle_;
    RAccelMexAtExit atExit_;
    RAccelMexSetMexTrapFlag setMexTrapFlag_;
} RAccelMexCallbacks;

SL_SERVICES_EXPORT_EXTERN_C void rapidAccelSetMexCallbacks(RAccelMexCallbacks cb);

#endif /* SLSV_MEXHELPER */
