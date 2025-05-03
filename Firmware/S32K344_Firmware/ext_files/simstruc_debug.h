/* Copyright 1990-2021 The MathWorks, Inc. */

/**
 * @file: simstruc_debug.h
 *
 * @brief SimStruct debug version of access methods, which are active for MEX files built with -g
 * option.
 *
 */

#ifndef __SIMSTRUC__DEBUG
#define __SIMSTRUC__DEBUG

#if SS_DEBUG_FOR_SIM

#ifdef __cplusplus
extern "C" {
#else
extern
#endif
void _ssSetInputPortDirectFeedThroughFcn(const SimStruct* S, int port, int dirFeed);
#ifdef __cplusplus
}
#endif

#define ssSetInputPortDirectFeedThrough(S, port, dirFeed) \
    _ssSetInputPortDirectFeedThroughFcn(S, port, dirFeed)

#ifdef __cplusplus
extern "C" {
#endif
extern void _ssSetRWorkValueFcn(const char* file,
                                int line,
                                SimStruct* S,
                                int rworkIdx,
                                real_T rworkValue);
#ifdef __cplusplus
}
#endif
#define ssSetRWorkValue(S, rworkIdx, rworkValue) \
    _ssSetRWorkValueFcn(__FILE__, __LINE__, S, rworkIdx, rworkValue)

#ifdef __cplusplus
extern "C" {
#endif
extern real_T _ssGetRWorkValueFcn(const char* file, int line, const SimStruct* S, int rworkIdx);
#ifdef __cplusplus
}
#endif
#define ssGetRWorkValue(S, rworkIdx) _ssGetRWorkValueFcn(__FILE__, __LINE__, S, rworkIdx)


#ifdef __cplusplus
extern "C" {
#endif
extern void _ssSetIWorkValueFcn(const char* file,
                                int line,
                                SimStruct* S,
                                int iworkIdx,
                                int_T iworkValue);
#ifdef __cplusplus
}
#endif
#define ssSetIWorkValue(S, iworkIdx, iworkValue) \
    _ssSetIWorkValueFcn(__FILE__, __LINE__, S, iworkIdx, iworkValue)

#ifdef __cplusplus
extern "C" {
#endif
extern int_T _ssGetIWorkValueFcn(const char* file, int line, const SimStruct* S, int iworkIdx);
#ifdef __cplusplus
}
#endif
#define ssGetIWorkValue(S, iworkIdx) _ssGetIWorkValueFcn(__FILE__, __LINE__, S, iworkIdx)


#ifdef __cplusplus
extern "C" {
#endif
extern void _ssSetPWorkValueFcn(const char* file,
                                int line,
                                SimStruct* S,
                                int pworkIdx,
                                void* pworkValue);
#ifdef __cplusplus
}
#endif
#define ssSetPWorkValue(S, pworkIdx, pworkValue) \
    _ssSetPWorkValueFcn(__FILE__, __LINE__, S, pworkIdx, pworkValue)

#ifdef __cplusplus
extern "C" {
#endif
extern void* _ssGetPWorkValueFcn(const char* file, int line, const SimStruct* S, int pworkIdx);
#ifdef __cplusplus
}
#endif
#define ssGetPWorkValue(S, pworkIdx) _ssGetPWorkValueFcn(__FILE__, __LINE__, S, pworkIdx)

#if !SS_SFCN_LEVEL_1
#ifdef __cplusplus
extern "C" {
#endif
extern const void* _ssGetInputPortSignalFcn(const SimStruct* S, int ip);
#ifdef __cplusplus
}
#endif
#define ssGetInputPortSignal(S, ip) _ssGetInputPortSignalFcn(S, ip)
#define ssGetInputPortRealSignal(S, ip) ((const real_T*)_ssGetInputPortSignalFcn(S, ip))



#ifdef __cplusplus
extern "C" {
#endif
extern int_T _ssGetInputPortBufferDstPortFcn(const char* file,
                                             int line,
                                             const SimStruct* S,
                                             int port);
#ifdef __cplusplus
}
#endif
#define ssGetInputPortBufferDstPort(S, port) \
    _ssGetInputPortBufferDstPortFcn(__FILE__, __LINE__, S, port)



#ifdef __cplusplus
extern "C" {
#endif
extern InputPtrsType _ssGetInputPortSignalPtrsFcn(const SimStruct* S, int ip);
#ifdef __cplusplus
}
#endif
#define ssGetInputPortSignalPtrs(S, ip) _ssGetInputPortSignalPtrsFcn(S, ip)
#define ssGetInputPortRealSignalPtrs(S, ip) ((InputRealPtrsType)_ssGetInputPortSignalPtrsFcn(S, ip))
#endif /*__!SS_SFCN_LEVEL_1_*/

#endif


#endif /* __SIMSTRUC__DEBUG */
