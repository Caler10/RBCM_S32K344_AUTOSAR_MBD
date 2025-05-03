#ifdef SUPPORTS_PRAGMA_ONCE
# pragma once
#endif
#ifndef sl_sigstream_rtw_h
#define sl_sigstream_rtw_h
/*
 *
 * Copyright 2008-2019 The MathWorks, Inc.
 *
 * This header is the interface to the sigstream module. It is used by the
 * RTW-RSim and Rapid Accelerator targets.
 *
 * 
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

extern void rtwOSigstreamManagerSaveDatasetsToMatFile(
    void *pOpaqueOSigstreamManager,
    const char *fileName
    );

extern void rtwISigstreamManagerSetDestinationBase(
    void *pOpaqueISigstreamManager,
    const size_t destinationId,
    void *pDestinationBase
    );

extern void* rtwISigstreamManagerCreateInstance(void);

extern void rtwISigstreamManagerDestroyInstance(void *pOpaqueISigstreamManager);

extern void rtwISigstreamManagerGetDatasetInputFromMatFile(
    void *pOpaqueISigstreamManager,
    const char *fileName,
    char errmsg[],
    const int maxErrorBufferSize,
    int errorXmlMode
    );

extern void rtwISigstreamManagerAddAperiodicPartitionHitTimes(
    void* pOpaqueISigstreamManager,
    void* unconstrainedPartitionHitTimes,
    char const* const* unconstrainedPartitionNames,
    unsigned int numAperiodicPartitions,
    char errmsg[]);

extern void rtwISigstreamManagerGetInputIsInDatasetFormat(
    void *pOpaqueISigstreamManager,
    bool *outInputIsInDatasetFormat
    );

extern void rtwISigstreamManagerHasAperiodicPartitionHitTimes(
    void *pOpaqueISigstreamManager,
    bool *outHasAperiodicPartitionHitTimes
    );
    
extern bool rtwISigstreamManagerIsPeriodicFcnCall(
    void *pOpaqueISigstreamManager,
    const size_t destinationId
    );

/* return false if there is an error, otherwise return true */
extern int rtwISigstreamManagerAperiodicPartitionDestinationIdx(
    void* pOpaqueISigstreamManager,
    const char* partitionName);


/* return false if there is an error, otherwise return true */
extern bool rtwISigstreamManagerInjectDataAperiodicPartitions(
    void* pOpaqueISigstreamManager,
    const int destinationId,
    const double time,
    int errorXMLMode,
    const char* partitionName,
    char errMsg[],
    const int maxErrorBufferSize);

/* return false if there is an error, otherwise return true */
extern bool rtwISigstreamManagerInjectDataMultiRate(
    void *pOpaqueISigstreamManager,
    const size_t destinationId,
    const double time,
    int errorXMLMode,
    const char *block,
    const char *var,
    int *sampleHitPtr,
    char errmsg[],
    const int maxErrorBufferSize
    );

/* return false if there is an error, otherwise return true */
extern bool rtwISigstreamManagerInjectDataSingleRate(
    void *pOpaqueISigstreamManager,
    const double time,
    int errorXMLMode,
    const char *block,
    const char *var,
    char errmsg[],
    const int maxErrorBufferSize
    );

/* get the data time that is after time (time) for destination with id (destinationId) */
extern double rtwISigstreamManagerNextTimeForDestination(void* pOpaqueISigstreamManager,
                                                         const int destinationId,
                                                         const double time);

/* get the data time that is after time (time) accross all destinations */
extern double rtwISigstreamManagerNextTime(void* pOpaqueISigstreamManager, const double time);

/* get the next data time for external inputs that is after time (time) */
extern double rtwISigstreamManagerNextTimeForTriggeringExternalInputs(
    void* pOpaqueISigstreamManager,
    const double time);

/* get the next hit time for aperiodic partitions that is after time (time) */
extern double rtwISigstreamManagerNextTimeForAperiodicPartitions(void* pOpaqueISigstreamManager,
                                                                 const double time);

/* return false if there is an error, otherwise return true */
extern bool rtwOSigstreamManagerCreateInstance(
    const char *settingsFileName,
    void * r2,
    void **outpOSigstreamManager,
    char errmsg[],
    const int maxErrorBufferSize
    );

extern void rtwOSigstreamManagerDestroyInstance(void *pOpaqueOSigstreamManager);

extern void rtwLoggingIntervalCreateInstance(void **outpLoggingInterval);
extern void rtwLoggingIntervalDestroyInstance(void *pOpaqueLoggingInterval);
extern bool rtwLoggingIntervalConstructIntervalTree(
    void *pOpaqueLoggingInterval, 
    void *pOpaqueIntervals);

extern bool rtwTimeInLoggingInterval(void *pOpaqueLoggingInterval, 
                                     const time_T time);


#ifdef __cplusplus
}
#endif

#endif /* sl_sigstream_rtw_h */

/* LocalWords:  RSim
 */
