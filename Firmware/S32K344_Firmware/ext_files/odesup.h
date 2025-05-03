/*
 * Copyright 1994-2008 The MathWorks, Inc.
 *
 * File: odesup.h     
 *
 * Abstract:
 *   
 */

#ifndef __ODE_SUP__
#define __ODE_SUP__

#include <math.h>
#include <stddef.h> /* needed for NULL */

#include "tmwtypes.h"

#ifdef RT_MALLOC
# include <stdlib.h>
#endif

#ifdef USE_RTMODEL
# include "simstruc_types.h"
#else
# include "simstruc.h"
#endif

#ifndef RT_MALLOC
# ifndef NCSTATES
#  error "must define NCSTATES"
# endif
#endif

extern const char *RT_MEMORY_ALLOCATION_ERROR;

#ifdef RT_MALLOC
# define DERIVATIVES(si) rtmiDerivatives(*rtsiGetModelMethodsPtr(si))
# define PROJECTION(si)  rtmiProjection(*rtsiGetModelMethodsPtr(si))
# define OUTPUTS(si,tid) rtmiOutputs(*rtsiGetModelMethodsPtr(si),tid)
#else
# define DERIVATIVES(si) MdlDerivatives()
# define OUTPUTS(si,tid) MdlOutputs(tid)
# define PROJECTION(si)  MdlProjection()
  extern void MdlDerivatives(void);
  extern void MdlOutputs(int_T tid);
  extern void MdlProjection(void);
#endif

void rt_ODEStateReduction(real_T* x, int_T* p, int_T n, real_T* r) {
    int_T i, j;

    for (i = 0, j = 0; i < n; ++i, ++j) {
        int_T k = p[i];
        real_T lb = r[j++];
        real_T xk = x[k]-lb;
        real_T rk = r[j]-lb;
        int_T q = (int_T) floor(xk/rk);
        if (q) {
            x[k] = xk-q*rk+lb;
        }
    }
}

#define REDUCTION(si) if (rtsiGetNumPeriodicContStates(si) > 0)                     \
                          rt_ODEStateReduction(rtsiGetContStates(si),               \
                                               rtsiGetPeriodicContStateIndices(si), \
                                               rtsiGetNumPeriodicContStates(si),    \
                                               rtsiGetPeriodicContStateRanges(si))

#ifndef USE_RTMODEL

void rt_ODECreateIntegrationData(RTWSolverInfo *si);
void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);
void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);

void rt_ODECacheDataIntoSolverInfo(SimStruct *S)
{
    RTWSolverInfo *si = ssGetRTWSolverInfo(S);
    
    if (si != NULL) {
        rtsiSetSolverStopTime(si, ssGetSolverStopTime(S));
        rtsiSetSolverName(si, ssGetSolverName(S));
        rtsiSetSolverData(si, ssGetSolverData(S));
    }
}

void rt_ODERetrieveDataFromSolverInfo(SimStruct *S)
{
    RTWSolverInfo *si = ssGetRTWSolverInfo(S);
    
    if (si != NULL) {
        ssSetSolverStopTime(S, rtsiGetSolverStopTime(si));
        ssSetSolverData(S, rtsiGetSolverData(si));
        ssSetSolverName(S, rtsiGetSolverName(si));
    }
}

const char_T *rt_ODECreateSolverInfo(SimStruct *S)
{
    const char_T          *errStatus = NULL;
    RTWSolverInfo         *si        = NULL;
    RTWRTModelMethodsInfo *mmi       = NULL;
    
#ifndef RT_MALLOC
    static RTWSolverInfo _si;
    static RTWRTModelMethodsInfo _mdlMths;

    si  = &_si;
    mmi = &_mdlMths;
#else
    si = (RTWSolverInfo *)malloc(sizeof(RTWSolverInfo));
    if (si == NULL) {
        errStatus = RT_MEMORY_ALLOCATION_ERROR;
        ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);
        goto EXIT_POINT;
    }

    mmi = (RTWRTModelMethodsInfo *)malloc(sizeof(RTWRTModelMethodsInfo));
    if (mmi == NULL) {
        errStatus = RT_MEMORY_ALLOCATION_ERROR;
        ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);
        goto EXIT_POINT;
    }
#endif

    rtsiSetModelMethodsPtr(si, mmi);
    rtsiSetRTModelPtr(si, (void *)S);
    rtmiSetRTModelPtr(*mmi, (void *)S);

    ssSetRTWSolverInfo(S, si);
    
    /* 
     * The fields below need to be copied over at setup
     * and copied back into the SimStruct at the end
     */
    rt_ODECacheDataIntoSolverInfo(S);
    
    /*
     * The fields below only need to be setup. They are
     * pointer fields and updating them will automatically
     * update the owner SimStruct
     */

    /* Copy over a pointer to StepSize */
    rtsiSetStepSizePtr(si, &ssGetStepSize(S));

    /* Copy over a pointer to SimTimeStep */
    rtsiSetSimTimeStepPtr(si, &ssGetSimTimeStep(S));

    /* Copy over a pointer to the time pointer */
    rtsiSetTPtr(si, &ssGetTPtr(S));

    /* Copy over a pointer to the location of the derivs */
    rtsiSetdXPtr(si, &ssGetdX(S));

    /* Copy over a pointer to the location of the cont states */
    rtsiSetContStatesPtr(si, &ssGetContStates(S));

    /* Copy over a pointer to the location of the number of cont states */
    rtsiSetNumContStatesPtr(si, ssGetNumContStatesPtr(S));

    /* Copy over a pointer to the location of the wrapped cont states */
    rtsiSetPeriodicContStateIndicesPtr(si, &ssGetPeriodicContStateIndices(S));
    rtsiSetPeriodicContStateRangesPtr(si, &ssGetPeriodicContStateRanges(S));

    /* Copy over a pointer to the location of the number of wrapped cont states */
    rtsiSetNumPeriodicContStatesPtr(si, &ssGetNumPeriodicContStates(S));

    /* Copy over a pointer to the location of the error status */
    rtsiSetErrorStatusPtr(si, &ssGetErrorStatus(S));

    /* Copy over the order of extrapolation method */
    rtsiSetSolverExtrapolationOrder(si, ssGetSolverExtrapolationOrder(S));

    /* Copy over the number of Newton iterations */
    rtsiSetSolverNumberNewtonIterations(si, ssGetSolverNumberNewtonIterations(S));

#ifdef RT_MALLOC
  EXIT_POINT:
#endif
    return(errStatus);
}

void rt_CreateIntegrationData(SimStruct *S)
{
    if (rt_ODECreateSolverInfo(S) != NULL) {
        return;
    }

    rt_ODECreateIntegrationData(ssGetRTWSolverInfo(S));
    
    rt_ODERetrieveDataFromSolverInfo(S);
}

#ifdef RT_MALLOC
void rt_DestroyIntegrationData(SimStruct *S)
{
    RTWSolverInfo *si = NULL;
    
    rt_ODECacheDataIntoSolverInfo(S);

    si = ssGetRTWSolverInfo(S);
    
    if (si != NULL) {
        rt_ODEDestroyIntegrationData(si);
        free(rtsiGetModelMethodsPtr(si));
        free(si);
        ssSetRTWSolverInfo(S, NULL);
    }
}
#endif

void rt_UpdateContinuousStates(SimStruct *S)
{
    rt_ODECacheDataIntoSolverInfo(S);
    rt_ODEUpdateContinuousStates(ssGetRTWSolverInfo(S));
    rt_ODERetrieveDataFromSolverInfo(S);
}

#endif
#endif /* __ODE_SUP__ */
