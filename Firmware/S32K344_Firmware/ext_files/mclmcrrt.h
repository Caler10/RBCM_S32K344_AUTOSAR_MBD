/*
 * @(#)mclmcrrt.h
 *
 *				apiproxy.published
 *				libmat_proxy.cpp
 *				libmwmclbase_proxy.cpp
 *				libmwmclmcr_proxy.cpp
 *				libmx_proxy.cpp
 */

#if defined(_MSC_VER)
# pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# pragma once
#endif

#ifndef mclmcrrt_h
#define mclmcrrt_h


/*
 * Copyright 1984-2021 The MathWorks, Inc.
 */



/* Copyright 2003-2006 The MathWorks, Inc. */

/* Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C extern
#endif

#endif



#ifdef __LCC__
/* Must undefine EXTERN_C here (and redefine it later) because LCC's version
 * of windows.h has its own definition of EXTERN_C.
 */
#undef EXTERN_C
#endif

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __LCC__
#undef EXTERN_C
#define EXTERN_C extern
#endif

#ifndef _WIN32
typedef const struct _GUID *REFCLSID, *REFGUID;
typedef long HRESULT;
#endif



#  if defined( linux ) || defined( __linux ) || defined( __linux__ )
/* stdint.h must be included before sys/types.h or loadlibrary will fail.
 * Because matrix.h includes stdlib.h, which includes sys/types.h, stdint.h
 * must be included before any include of matrix.h (On Linux systems.)
 */
#include <stdint.h> 
#endif

/*#ifdef matrix_h
#error "mclmcrrt.h must be included before matrix.h. (Since mclmcrrt.h includes matrix.h, additional inclusion is redundant.)"
#endif */
#include "matrix.h"

#undef mclmcrInitialize2
#define mclmcrInitialize2 mclmcrInitialize2_proxy


#undef mclmcrInitialize
#define mclmcrInitialize mclmcrInitialize_proxy


#undef mclInitializeApplication
#if !defined(TARGET_API_VERSION) || TARGET_API_VERSION >= 800
#define mclInitializeApplication mclInitializeApplication_800_proxy
#else
#define mclInitializeApplication mclInitializeApplication_730_proxy
#endif   /* !defined(TARGET_API_VERSION) || TARGET_API_VERSION >= 800 */


#undef mclDisplayStartMessage
#define mclDisplayStartMessage mclDisplayStartMessage_proxy


typedef void * MCREventHandlerArg;
typedef void (*MCREventHandlerFcn)(MCREventHandlerArg);
typedef enum
{   MCRStartEvent,
    MCRCompleteEvent
} mcrInitializationEventType;
typedef void * MCREventData;

EXTERN_C void mclDisplayStartMessage_proxy(mcrInitializationEventType eventType,MCREventHandlerFcn fcn,MCREventHandlerArg arg,MCREventData eventData);


#undef mclGetComponentInfo
#define mclGetComponentInfo mclGetComponentInfo_proxy
EXTERN_C HRESULT mclGetComponentInfo_proxy(const char* lpszComponent, 
                                                      int nMajorRev, 
                                                      int nMinorRev, int nInfo, 
                                                      int nType, 
                                                      void** info);


#undef mclGetLIBIDInfo
#define mclGetLIBIDInfo mclGetLIBIDInfo_proxy
EXTERN_C HRESULT mclGetLIBIDInfo_proxy(const char* lpszLIBID, 
                                                  int nMajorRev, int nMinorRev, 
                                                  int nInfo, void** info);


#undef mclRegisterServer
#define mclRegisterServer mclRegisterServer_proxy
EXTERN_C HRESULT mclRegisterServer_proxy(const char* szModuleName,     
                                                    REFCLSID clsid,               
                                                    REFGUID libid,                
                                                    unsigned short wMajorRev,     
                                                    unsigned short wMinorRev,     
                                                    const char* szFriendlyName,   
                                                    const char* szVerIndProgID,   
                                                    const char* szProgID,         
                                                    const char* szThreadingModel);


#undef mclGUIDFromString
#define mclGUIDFromString mclGUIDFromString_proxy
EXTERN_C int mclGUIDFromString_proxy(const char* lpszGUID, struct _GUID* pguid);


#undef mclUnRegisterMatLabCOMComponent
#define mclUnRegisterMatLabCOMComponent mclUnRegisterMatLabCOMComponent_proxy
EXTERN_C HRESULT mclUnRegisterMatLabCOMComponent_proxy(REFCLSID clsid,            
                                       const char* szVerIndProgID, 
                                       const char* szProgID);


#undef mclRegisterMatLabXLComponent
#define mclRegisterMatLabXLComponent mclRegisterMatLabXLComponent_proxy
EXTERN_C HRESULT mclRegisterMatLabXLComponent_proxy(const char* szModuleName,    
                                    REFCLSID clsid,               
                                    REFGUID libid,                
                                    unsigned short wMajorRev,     
                                    unsigned short wMinorRev,     
                                    const char* szFriendlyName,   
                                    const char* szVerIndProgID,   
                                    const char* szProgID);


#undef mclGUIDtochar
#define mclGUIDtochar mclGUIDtochar_proxy
EXTERN_C void mclGUIDtochar_proxy(REFGUID guid, char* szGUID, int length);


#undef mclUnregisterServer
#define mclUnregisterServer mclUnregisterServer_proxy
EXTERN_C HRESULT mclUnregisterServer_proxy(REFCLSID clsid,             
                           const char* szVerIndProgID, 
                           const char* szProgID);


#undef mclCLSIDtochar
#define mclCLSIDtochar mclCLSIDtochar_proxy
EXTERN_C void mclCLSIDtochar_proxy(REFCLSID clsid, char* szCLSID, int length);


#undef mclFreeComponentInfo
#define mclFreeComponentInfo mclFreeComponentInfo_proxy
EXTERN_C void mclFreeComponentInfo_proxy(void** info);


#undef mclUnRegisterMatLabXLComponent
#define mclUnRegisterMatLabXLComponent mclUnRegisterMatLabXLComponent_proxy
EXTERN_C HRESULT mclUnRegisterMatLabXLComponent_proxy(REFCLSID clsid,             
                                      const char* szVerIndProgID, 
                                      const char* szProgID);


#undef mclRegisterMatLabCOMComponent
#define mclRegisterMatLabCOMComponent mclRegisterMatLabCOMComponent_proxy
EXTERN_C HRESULT mclRegisterMatLabCOMComponent_proxy(const char* szModuleName,     
                                     REFCLSID clsid,               
                                     REFGUID libid,                
                                     unsigned short wMajorRev,     
                                     unsigned short wMinorRev,     
                                     const char* szFriendlyName,   
                                     const char* szVerIndProgID,   
                                     const char* szProgID);

#ifndef MW_CALL_CONV
#  ifdef _WIN32 
#      define MW_CALL_CONV __cdecl
#  else
#      define MW_CALL_CONV 
#  endif
#endif

#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matOpen
#define matOpen matOpen_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matClose
#define matClose matClose_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetErrno
#define matGetErrno matGetErrno_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetFp
#define matGetFp matGetFp_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matPutVariable
#define matPutVariable matPutVariable_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matPutVariableAsGlobal
#define matPutVariableAsGlobal matPutVariableAsGlobal_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetVariable
#define matGetVariable matGetVariable_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetNextVariable
#define matGetNextVariable matGetNextVariable_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetNextVariableInfo
#define matGetNextVariableInfo matGetNextVariableInfo_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetVariableInfo
#define matGetVariableInfo matGetVariableInfo_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matDeleteVariable
#define matDeleteVariable matDeleteVariable_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef matGetDir
#define matGetDir matGetDir_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matOpen_800
#define matOpen_800 matOpen_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matClose_800
#define matClose_800 matClose_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetErrno_800
#define matGetErrno_800 matGetErrno_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetFp_800
#define matGetFp_800 matGetFp_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matPutVariable_800
#define matPutVariable_800 matPutVariable_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matPutVariableAsGlobal_800
#define matPutVariableAsGlobal_800 matPutVariableAsGlobal_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetVariable_800
#define matGetVariable_800 matGetVariable_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetNextVariable_800
#define matGetNextVariable_800 matGetNextVariable_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetNextVariableInfo_800
#define matGetNextVariableInfo_800 matGetNextVariableInfo_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetVariableInfo_800
#define matGetVariableInfo_800 matGetVariableInfo_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matDeleteVariable_800
#define matDeleteVariable_800 matDeleteVariable_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef matGetDir_800
#define matGetDir_800 matGetDir_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */




/*#ifdef mat_h
#error "mclmcrrt.h must be included before mat.h. (Since mclmcrrt.h includes mat.h, additional inclusion is redundant.)"
#endif */
#define LIBMWMAT_API_EXTERN_C EXTERN_C
#include "mat.h"

/* Proxies for functions in mat.h */

#if TARGET_API_VERSION < 800
EXTERN_C
MATFile * matOpen_proxy(const char *a0, const char *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
matError matClose_proxy(MATFile *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
matError matGetErrno_proxy(MATFile *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
FILE * matGetFp_proxy(MATFile *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
matError matPutVariable_proxy(MATFile *a0, const char *a1, 
    const mxArray *a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
matError matPutVariableAsGlobal_proxy(MATFile *a0, const char *a1, 
    const mxArray *a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * matGetVariable_proxy(MATFile *a0, const char *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * matGetNextVariable_proxy(MATFile *a0, const char **a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * matGetNextVariableInfo_proxy(MATFile *a0, const char **a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * matGetVariableInfo_proxy(MATFile *a0, const char *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
matError matDeleteVariable_proxy(MATFile *a0, const char *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
char ** matGetDir_proxy(MATFile *a0, int *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
MATFile * matOpen_800_proxy(const char *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
matError matClose_800_proxy(MATFile *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
matError matGetErrno_800_proxy(MATFile *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
FILE * matGetFp_800_proxy(MATFile *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
matError matPutVariable_800_proxy(MATFile *a0, const char *a1, 
    const mxArray *a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
matError matPutVariableAsGlobal_800_proxy(MATFile *a0, const char *a1, 
    const mxArray *a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * matGetVariable_800_proxy(MATFile *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * matGetNextVariable_800_proxy(MATFile *a0, const char **a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * matGetNextVariableInfo_800_proxy(MATFile *a0, const char **a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * matGetVariableInfo_800_proxy(MATFile *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
matError matDeleteVariable_800_proxy(MATFile *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
char ** matGetDir_800_proxy(MATFile *a0, int *a1);
#endif



#ifndef MW_CALL_CONV
#  ifdef _WIN32 
#      define MW_CALL_CONV __cdecl
#  else
#      define MW_CALL_CONV 
#  endif
#endif

/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclSetLastErrIdAndMsg
#define mclSetLastErrIdAndMsg mclSetLastErrIdAndMsg_proxy



/* Map original name to unique proxy layer name. */
#undef mclGetLastErrorMessage
#define mclGetLastErrorMessage mclGetLastErrorMessage_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetStackTrace
#define mclGetStackTrace mclGetStackTrace_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclFreeStackTrace
#define mclFreeStackTrace mclFreeStackTrace_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetLastExceptionType
#define mclGetLastExceptionType mclGetLastExceptionType_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclAcquireMutex
#define mclAcquireMutex mclAcquireMutex_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclReleaseMutex
#define mclReleaseMutex mclReleaseMutex_proxy



/* Map original name to unique proxy layer name. */
#undef mclIsMCRInitialized
#define mclIsMCRInitialized mclIsMCRInitialized_proxy



/* Map original name to unique proxy layer name. */
#undef mclIsJVMEnabled
#define mclIsJVMEnabled mclIsJVMEnabled_proxy



/* Map original name to unique proxy layer name. */
#undef mclGetLogFileName
#define mclGetLogFileName mclGetLogFileName_proxy



/* Map original name to unique proxy layer name. */
#undef mclIsNoDisplaySet
#define mclIsNoDisplaySet mclIsNoDisplaySet_proxy



/* Map original name to unique proxy layer name. */
#undef mclInitializeApplicationInternal
#define mclInitializeApplicationInternal mclInitializeApplicationInternal_proxy



/* Map original name to unique proxy layer name. */
#undef mclTerminateApplication
#define mclTerminateApplication mclTerminateApplication_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsMcc
#define mclIsMcc mclIsMcc_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef separatePathName
#define separatePathName separatePathName_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclFreeStrArray
#define mclFreeStrArray mclFreeStrArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclFreeArrayList
#define mclFreeArrayList mclFreeArrayList_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateCellArrayFromArrayList
#define mclCreateCellArrayFromArrayList mclCreateCellArrayFromArrayList_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateSharedCopy
#define mclCreateSharedCopy mclCreateSharedCopy_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateEmptyArray
#define mclCreateEmptyArray mclCreateEmptyArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateSimpleFunctionHandle
#define mclCreateSimpleFunctionHandle mclCreateSimpleFunctionHandle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxSerialize
#define mclMxSerialize mclMxSerialize_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxDeserialize
#define mclMxDeserialize mclMxDeserialize_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclSetInterleavedCompatibility
#define mclSetInterleavedCompatibility mclSetInterleavedCompatibility_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsInterleavedCompatibility
#define mclIsInterleavedCompatibility mclIsInterleavedCompatibility_proxy



/* Map original name to unique proxy layer name. */
#undef mclRunMain
#define mclRunMain mclRunMain_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCFRunLoopRun
#define mclCFRunLoopRun mclCFRunLoopRun_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCFRunLoopStop
#define mclCFRunLoopStop mclCFRunLoopStop_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsCFRunLoopReady
#define mclIsCFRunLoopReady mclIsCFRunLoopReady_proxy




/*#ifdef mclbase_h
#error "mclmcrrt.h must be included before mclbase.h. (Since mclmcrrt.h includes mclbase.h, additional inclusion is redundant.)"
#endif */
#define LIBMWMCLBASE_API_EXTERN_C EXTERN_C
#include "mclbase.h"

/* Proxies for functions in mclbase.h */

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclSetLastErrIdAndMsg_proxy(const char *a0, const char *a1);

EXTERN_C
const char * mclGetLastErrorMessage_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetStackTrace_proxy(char ***a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclFreeStackTrace_proxy(char ***a0, int a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetLastExceptionType_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclAcquireMutex_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclReleaseMutex_proxy();

EXTERN_C
bool mclIsMCRInitialized_proxy();

EXTERN_C
bool mclIsJVMEnabled_proxy();

EXTERN_C
const char * mclGetLogFileName_proxy();

EXTERN_C
bool mclIsNoDisplaySet_proxy();

EXTERN_C
bool mclInitializeApplicationInternal_proxy(const char **a0, size_t a1);

EXTERN_C
bool mclTerminateApplication_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsMcc_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void separatePathName_proxy(const char *a0, char *a1, size_t a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclFreeStrArray_proxy(char **a0, size_t a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclFreeArrayList_proxy(int a0, mxArray **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateCellArrayFromArrayList_proxy(int a0, mxArray **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateSharedCopy_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateEmptyArray_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateSimpleFunctionHandle_proxy(mxFunctionPtr a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclMxSerialize_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclMxDeserialize_proxy(const void *a0, size_t a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclSetInterleavedCompatibility_proxy(bool a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsInterleavedCompatibility_proxy();

EXTERN_C
int mclRunMain_proxy(mclMainFcnType a0, int a1, const char **a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclCFRunLoopRun_proxy(bool a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclCFRunLoopStop_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsCFRunLoopReady_proxy();



#ifndef MW_CALL_CONV
#  ifdef _WIN32 
#      define MW_CALL_CONV __cdecl
#  else
#      define MW_CALL_CONV 
#  endif
#endif

/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetStreamFromArraySrc
#define mclGetStreamFromArraySrc mclGetStreamFromArraySrc_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclDestroyStream
#define mclDestroyStream mclDestroyStream_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetEmbeddedCtfStream
#define mclGetEmbeddedCtfStream mclGetEmbeddedCtfStream_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeComponentInstanceNonEmbeddedStandalone
#define mclInitializeComponentInstanceNonEmbeddedStandalone mclInitializeComponentInstanceNonEmbeddedStandalone_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeInstanceWithoutComponent
#define mclInitializeInstanceWithoutComponent mclInitializeInstanceWithoutComponent_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeComponentInstanceCtfFileToCache
#define mclInitializeComponentInstanceCtfFileToCache mclInitializeComponentInstanceCtfFileToCache_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeComponentInstanceEmbedded
#define mclInitializeComponentInstanceEmbedded mclInitializeComponentInstanceEmbedded_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeComponentInstanceWithCallbk
#define mclInitializeComponentInstanceWithCallbk mclInitializeComponentInstanceWithCallbk_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeComponentInstanceFromExtractedComponent
#define mclInitializeComponentInstanceFromExtractedComponent mclInitializeComponentInstanceFromExtractedComponent_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclInitializeComponentInstanceFromExtractedLocation
#define mclInitializeComponentInstanceFromExtractedLocation mclInitializeComponentInstanceFromExtractedLocation_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetDotNetComponentType
#define mclGetDotNetComponentType mclGetDotNetComponentType_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetMCCTargetType
#define mclGetMCCTargetType mclGetMCCTargetType_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef getStandaloneFileName
#define getStandaloneFileName getStandaloneFileName_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclStandaloneGenericMain
#define mclStandaloneGenericMain mclStandaloneGenericMain_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclStandaloneCtfxMain
#define mclStandaloneCtfxMain mclStandaloneCtfxMain_proxy



/* Map original name to unique proxy layer name. */
#undef mclWaitForFiguresToDie
#define mclWaitForFiguresToDie mclWaitForFiguresToDie_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppGetLastError
#define mclcppGetLastError mclcppGetLastError_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppCreateError
#define mclcppCreateError mclcppCreateError_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppSetLastError
#define mclcppSetLastError mclcppSetLastError_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppErrorCheck
#define mclcppErrorCheck mclcppErrorCheck_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppGetLastErrorMessage
#define mclcppGetLastErrorMessage mclcppGetLastErrorMessage_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateCharBuffer
#define mclCreateCharBuffer mclCreateCharBuffer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetEps
#define mclGetEps mclGetEps_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetInf
#define mclGetInf mclGetInf_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetNaN
#define mclGetNaN mclGetNaN_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsFinite
#define mclIsFinite mclIsFinite_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsInf
#define mclIsInf mclIsInf_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsNaN
#define mclIsNaN mclIsNaN_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsIdentical
#define mclIsIdentical mclIsIdentical_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetEmptyArray
#define mclGetEmptyArray mclGetEmptyArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetMatrix
#define mclGetMatrix mclGetMatrix_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetArray
#define mclGetArray mclGetArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetNumericMatrix
#define mclGetNumericMatrix mclGetNumericMatrix_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetNumericArray
#define mclGetNumericArray mclGetNumericArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarDouble
#define mclGetScalarDouble mclGetScalarDouble_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarSingle
#define mclGetScalarSingle mclGetScalarSingle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarInt8
#define mclGetScalarInt8 mclGetScalarInt8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarUint8
#define mclGetScalarUint8 mclGetScalarUint8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarInt16
#define mclGetScalarInt16 mclGetScalarInt16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarUint16
#define mclGetScalarUint16 mclGetScalarUint16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarInt32
#define mclGetScalarInt32 mclGetScalarInt32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarUint32
#define mclGetScalarUint32 mclGetScalarUint32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarInt64
#define mclGetScalarInt64 mclGetScalarInt64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarUint64
#define mclGetScalarUint64 mclGetScalarUint64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetCharMatrix
#define mclGetCharMatrix mclGetCharMatrix_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetCharArray
#define mclGetCharArray mclGetCharArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarChar
#define mclGetScalarChar mclGetScalarChar_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetString
#define mclGetString mclGetString_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetCharMatrixFromStrings
#define mclGetCharMatrixFromStrings mclGetCharMatrixFromStrings_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsMatlabString
#define mclIsMatlabString mclIsMatlabString_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsMissingStringElement
#define mclIsMissingStringElement mclIsMissingStringElement_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateMatlabString
#define mclCreateMatlabString mclCreateMatlabString_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateMatlabStringArray
#define mclCreateMatlabStringArray mclCreateMatlabStringArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringGetElement
#define mclMatlabStringGetElement mclMatlabStringGetElement_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringSetElement
#define mclMatlabStringSetElement mclMatlabStringSetElement_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringGetData
#define mclMatlabStringGetData mclMatlabStringGetData_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringSetData
#define mclMatlabStringSetData mclMatlabStringSetData_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringGetNumberOfDimensions
#define mclMatlabStringGetNumberOfDimensions mclMatlabStringGetNumberOfDimensions_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringGetDimensions
#define mclMatlabStringGetDimensions mclMatlabStringGetDimensions_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMatlabStringGetNumberOfElements
#define mclMatlabStringGetNumberOfElements mclMatlabStringGetNumberOfElements_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetMatlabString
#define mclGetMatlabString mclGetMatlabString_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetMatlabStringArray
#define mclGetMatlabStringArray mclGetMatlabStringArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetLogicalMatrix
#define mclGetLogicalMatrix mclGetLogicalMatrix_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetLogicalArray
#define mclGetLogicalArray mclGetLogicalArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetScalarLogical
#define mclGetScalarLogical mclGetScalarLogical_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetCellMatrix
#define mclGetCellMatrix mclGetCellMatrix_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetCellArray
#define mclGetCellArray mclGetCellArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetStructMatrix
#define mclGetStructMatrix mclGetStructMatrix_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetStructArray
#define mclGetStructArray mclGetStructArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetNumericSparse
#define mclGetNumericSparse mclGetNumericSparse_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetNumericSparseInferRowsCols
#define mclGetNumericSparseInferRowsCols mclGetNumericSparseInferRowsCols_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetLogicalSparse
#define mclGetLogicalSparse mclGetLogicalSparse_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetLogicalSparseInferRowsCols
#define mclGetLogicalSparseInferRowsCols mclGetLogicalSparseInferRowsCols_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclDeserializeArray
#define mclDeserializeArray mclDeserializeArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppGetArrayBuffer
#define mclcppGetArrayBuffer mclcppGetArrayBuffer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppFeval
#define mclcppFeval mclcppFeval_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppArrayToString
#define mclcppArrayToString mclcppArrayToString_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclcppFreeString
#define mclcppFreeString mclcppFreeString_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclmxArray2ArrayHandle
#define mclmxArray2ArrayHandle mclmxArray2ArrayHandle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclArrayHandle2mxArray
#define mclArrayHandle2mxArray mclArrayHandle2mxArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArrayGetIndexArrays
#define mclMXArrayGetIndexArrays mclMXArrayGetIndexArrays_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArrayGet
#define mclMXArrayGet mclMXArrayGet_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArrayGetReal
#define mclMXArrayGetReal mclMXArrayGetReal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArrayGetImag
#define mclMXArrayGetImag mclMXArrayGetImag_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArraySet
#define mclMXArraySet mclMXArraySet_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArraySetReal
#define mclMXArraySetReal mclMXArraySetReal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArraySetImag
#define mclMXArraySetImag mclMXArraySetImag_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMXArraySetLogical
#define mclMXArraySetLogical mclMXArraySetLogical_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefDestroyArray
#define mclMxRefDestroyArray mclMxRefDestroyArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefSerialize
#define mclMxRefSerialize mclMxRefSerialize_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefDeserialize
#define mclMxRefDeserialize mclMxRefDeserialize_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefMvmId
#define mclMxRefMvmId mclMxRefMvmId_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclHashNBytes
#define mclHashNBytes mclHashNBytes_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCalcSingleSubscript
#define mclCalcSingleSubscript mclCalcSingleSubscript_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclCreateCharMatrixFromUTF16Strings
#define mclCreateCharMatrixFromUTF16Strings mclCreateCharMatrixFromUTF16Strings_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mcl2DCharArrayToUTF16Strings
#define mcl2DCharArrayToUTF16Strings mcl2DCharArrayToUTF16Strings_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclWrite
#define mclWrite mclWrite_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclAddCanonicalPathMacro
#define mclAddCanonicalPathMacro mclAddCanonicalPathMacro_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclFevalInternal
#define mclFevalInternal mclFevalInternal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetMaxPathLen
#define mclGetMaxPathLen mclGetMaxPathLen_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclmcrInitializeInternal2
#define mclmcrInitializeInternal2 mclmcrInitializeInternal2_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclmcrInitializeInternal
#define mclmcrInitializeInternal mclmcrInitializeInternal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef deleteWcsStackPointer_hPtr
#define deleteWcsStackPointer_hPtr deleteWcsStackPointer_hPtr_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef initializeWcsStackPointer
#define initializeWcsStackPointer initializeWcsStackPointer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef deleteWcsStackPointer
#define deleteWcsStackPointer deleteWcsStackPointer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef allocWcsStackPointer
#define allocWcsStackPointer allocWcsStackPointer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mwMbstowcs
#define mwMbstowcs mwMbstowcs_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef utf16_to_lcp_n_fcn
#define utf16_to_lcp_n_fcn utf16_to_lcp_n_fcn_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef utf16_strlen_fcn
#define utf16_strlen_fcn utf16_strlen_fcn_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef utf16_strncpy_fcn
#define utf16_strncpy_fcn utf16_strncpy_fcn_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef utf16_strdup_fcn
#define utf16_strdup_fcn utf16_strdup_fcn_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclSetGlobal
#define mclSetGlobal mclSetGlobal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsStandaloneMode
#define mclIsStandaloneMode mclIsStandaloneMode_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclImpersonationFeval
#define mclImpersonationFeval mclImpersonationFeval_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetGlobal
#define mclGetGlobal mclGetGlobal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetID
#define mclGetID mclGetID_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMain
#define mclMain mclMain_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMlfVFevalInternal
#define mclMlfVFevalInternal mclMlfVFevalInternal_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetMCRVersion
#define mclGetMCRVersion mclGetMCRVersion_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetActiveID
#define mclGetActiveID mclGetActiveID_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclGetTempFileName
#define mclGetTempFileName mclGetTempFileName_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclTerminateInstance
#define mclTerminateInstance mclTerminateInstance_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef stopImpersonationOnMCRThread
#define stopImpersonationOnMCRThread stopImpersonationOnMCRThread_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxIsA
#define mclMxIsA mclMxIsA_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxIsRef
#define mclMxIsRef mclMxIsRef_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefIsA
#define mclMxRefIsA mclMxRefIsA_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefGetRefClassName
#define mclMxRefGetRefClassName mclMxRefGetRefClassName_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefGetProperty
#define mclMxRefGetProperty mclMxRefGetProperty_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefSetProperty
#define mclMxRefSetProperty mclMxRefSetProperty_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxReleaseRef
#define mclMxReleaseRef mclMxReleaseRef_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxRefLocalMvm
#define mclMxRefLocalMvm mclMxRefLocalMvm_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclMxDestroyArray
#define mclMxDestroyArray mclMxDestroyArray_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclNonDefaultAppDomainInUse
#define mclNonDefaultAppDomainInUse mclNonDefaultAppDomainInUse_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef mclIsNonDefaultAppDomainInUse
#define mclIsNonDefaultAppDomainInUse mclIsNonDefaultAppDomainInUse_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef ref_count_obj_addref
#define ref_count_obj_addref ref_count_obj_addref_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef ref_count_obj_release
#define ref_count_obj_release ref_count_obj_release_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef char_buffer_size
#define char_buffer_size char_buffer_size_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef char_buffer_get_buffer
#define char_buffer_get_buffer char_buffer_get_buffer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef char_buffer_set_buffer
#define char_buffer_set_buffer char_buffer_set_buffer_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef char_buffer_compare_to
#define char_buffer_compare_to char_buffer_compare_to_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_classID
#define array_ref_classID array_ref_classID_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_deep_copy
#define array_ref_deep_copy array_ref_deep_copy_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_detach
#define array_ref_detach array_ref_detach_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_shared_copy
#define array_ref_shared_copy array_ref_shared_copy_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_serialize
#define array_ref_serialize array_ref_serialize_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_element_size
#define array_ref_element_size array_ref_element_size_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_number_of_elements
#define array_ref_number_of_elements array_ref_number_of_elements_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_number_of_nonzeros
#define array_ref_number_of_nonzeros array_ref_number_of_nonzeros_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_maximum_nonzeros
#define array_ref_maximum_nonzeros array_ref_maximum_nonzeros_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_number_of_dimensions
#define array_ref_number_of_dimensions array_ref_number_of_dimensions_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_dimensions
#define array_ref_get_dimensions array_ref_get_dimensions_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_number_of_fields
#define array_ref_number_of_fields array_ref_number_of_fields_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_field_name
#define array_ref_get_field_name array_ref_get_field_name_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_is_empty
#define array_ref_is_empty array_ref_is_empty_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_is_sparse
#define array_ref_is_sparse array_ref_is_sparse_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_is_numeric
#define array_ref_is_numeric array_ref_is_numeric_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_is_complex
#define array_ref_is_complex array_ref_is_complex_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_is_matlab_string
#define array_ref_is_matlab_string array_ref_is_matlab_string_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_is_missing_string_element
#define array_ref_is_missing_string_element array_ref_is_missing_string_element_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_make_complex
#define array_ref_make_complex array_ref_make_complex_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_equals
#define array_ref_equals array_ref_equals_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_compare_to
#define array_ref_compare_to array_ref_compare_to_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_hash_code
#define array_ref_hash_code array_ref_hash_code_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_to_string
#define array_ref_to_string array_ref_to_string_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_row_index
#define array_ref_row_index array_ref_row_index_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_column_index
#define array_ref_column_index array_ref_column_index_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_int
#define array_ref_get_int array_ref_get_int_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_const_char
#define array_ref_get_const_char array_ref_get_const_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_getV_int
#define array_ref_getV_int array_ref_getV_int_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_getV_const_char
#define array_ref_getV_const_char array_ref_getV_const_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set
#define array_ref_set array_ref_set_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_real
#define array_ref_real array_ref_real_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_imag
#define array_ref_imag array_ref_imag_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxDouble
#define array_ref_get_numeric_mxDouble array_ref_get_numeric_mxDouble_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxSingle
#define array_ref_get_numeric_mxSingle array_ref_get_numeric_mxSingle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxInt8
#define array_ref_get_numeric_mxInt8 array_ref_get_numeric_mxInt8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxUint8
#define array_ref_get_numeric_mxUint8 array_ref_get_numeric_mxUint8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxInt16
#define array_ref_get_numeric_mxInt16 array_ref_get_numeric_mxInt16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxUint16
#define array_ref_get_numeric_mxUint16 array_ref_get_numeric_mxUint16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxInt32
#define array_ref_get_numeric_mxInt32 array_ref_get_numeric_mxInt32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxUint32
#define array_ref_get_numeric_mxUint32 array_ref_get_numeric_mxUint32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxInt64
#define array_ref_get_numeric_mxInt64 array_ref_get_numeric_mxInt64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_numeric_mxUint64
#define array_ref_get_numeric_mxUint64 array_ref_get_numeric_mxUint64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_char
#define array_ref_get_char array_ref_get_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_string_element
#define array_ref_get_string_element array_ref_get_string_element_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_matlab_string
#define array_ref_get_matlab_string array_ref_get_matlab_string_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_get_logical
#define array_ref_get_logical array_ref_get_logical_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxDouble
#define array_ref_set_numeric_mxDouble array_ref_set_numeric_mxDouble_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxSingle
#define array_ref_set_numeric_mxSingle array_ref_set_numeric_mxSingle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxInt8
#define array_ref_set_numeric_mxInt8 array_ref_set_numeric_mxInt8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxUint8
#define array_ref_set_numeric_mxUint8 array_ref_set_numeric_mxUint8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxInt16
#define array_ref_set_numeric_mxInt16 array_ref_set_numeric_mxInt16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxUint16
#define array_ref_set_numeric_mxUint16 array_ref_set_numeric_mxUint16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxInt32
#define array_ref_set_numeric_mxInt32 array_ref_set_numeric_mxInt32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxUint32
#define array_ref_set_numeric_mxUint32 array_ref_set_numeric_mxUint32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxInt64
#define array_ref_set_numeric_mxInt64 array_ref_set_numeric_mxInt64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_numeric_mxUint64
#define array_ref_set_numeric_mxUint64 array_ref_set_numeric_mxUint64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_char
#define array_ref_set_char array_ref_set_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_string_element
#define array_ref_set_string_element array_ref_set_string_element_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_matlab_string
#define array_ref_set_matlab_string array_ref_set_matlab_string_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_ref_set_logical
#define array_ref_set_logical array_ref_set_logical_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_size
#define array_buffer_size array_buffer_size_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_get
#define array_buffer_get array_buffer_get_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_set
#define array_buffer_set array_buffer_set_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_add
#define array_buffer_add array_buffer_add_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_remove
#define array_buffer_remove array_buffer_remove_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_clear
#define array_buffer_clear array_buffer_clear_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_buffer_to_cell
#define array_buffer_to_cell array_buffer_to_cell_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef error_info_get_message
#define error_info_get_message error_info_get_message_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef error_info_get_stack_trace
#define error_info_get_stack_trace error_info_get_stack_trace_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_classID
#define array_handle_classID array_handle_classID_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_deep_copy
#define array_handle_deep_copy array_handle_deep_copy_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_detach
#define array_handle_detach array_handle_detach_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_shared_copy
#define array_handle_shared_copy array_handle_shared_copy_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_serialize
#define array_handle_serialize array_handle_serialize_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_element_size
#define array_handle_element_size array_handle_element_size_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_number_of_elements
#define array_handle_number_of_elements array_handle_number_of_elements_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_number_of_nonzeros
#define array_handle_number_of_nonzeros array_handle_number_of_nonzeros_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_maximum_nonzeros
#define array_handle_maximum_nonzeros array_handle_maximum_nonzeros_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_number_of_dimensions
#define array_handle_number_of_dimensions array_handle_number_of_dimensions_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_dimensions
#define array_handle_get_dimensions array_handle_get_dimensions_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_number_of_fields
#define array_handle_number_of_fields array_handle_number_of_fields_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_field_name
#define array_handle_get_field_name array_handle_get_field_name_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_is_empty
#define array_handle_is_empty array_handle_is_empty_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_is_sparse
#define array_handle_is_sparse array_handle_is_sparse_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_is_numeric
#define array_handle_is_numeric array_handle_is_numeric_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_is_complex
#define array_handle_is_complex array_handle_is_complex_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_make_complex
#define array_handle_make_complex array_handle_make_complex_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_equals
#define array_handle_equals array_handle_equals_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_compare_to
#define array_handle_compare_to array_handle_compare_to_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_hash_code
#define array_handle_hash_code array_handle_hash_code_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_to_string
#define array_handle_to_string array_handle_to_string_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_row_index
#define array_handle_row_index array_handle_row_index_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_column_index
#define array_handle_column_index array_handle_column_index_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_int
#define array_handle_get_int array_handle_get_int_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_const_char
#define array_handle_get_const_char array_handle_get_const_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_getV_int
#define array_handle_getV_int array_handle_getV_int_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_getV_const_char
#define array_handle_getV_const_char array_handle_getV_const_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set
#define array_handle_set array_handle_set_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_real
#define array_handle_real array_handle_real_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_imag
#define array_handle_imag array_handle_imag_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxDouble
#define array_handle_get_numeric_mxDouble array_handle_get_numeric_mxDouble_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxSingle
#define array_handle_get_numeric_mxSingle array_handle_get_numeric_mxSingle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxInt8
#define array_handle_get_numeric_mxInt8 array_handle_get_numeric_mxInt8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxUint8
#define array_handle_get_numeric_mxUint8 array_handle_get_numeric_mxUint8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxInt16
#define array_handle_get_numeric_mxInt16 array_handle_get_numeric_mxInt16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxUint16
#define array_handle_get_numeric_mxUint16 array_handle_get_numeric_mxUint16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxInt32
#define array_handle_get_numeric_mxInt32 array_handle_get_numeric_mxInt32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxUint32
#define array_handle_get_numeric_mxUint32 array_handle_get_numeric_mxUint32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxInt64
#define array_handle_get_numeric_mxInt64 array_handle_get_numeric_mxInt64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_numeric_mxUint64
#define array_handle_get_numeric_mxUint64 array_handle_get_numeric_mxUint64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_char
#define array_handle_get_char array_handle_get_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_get_logical
#define array_handle_get_logical array_handle_get_logical_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxDouble
#define array_handle_set_numeric_mxDouble array_handle_set_numeric_mxDouble_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxSingle
#define array_handle_set_numeric_mxSingle array_handle_set_numeric_mxSingle_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxInt8
#define array_handle_set_numeric_mxInt8 array_handle_set_numeric_mxInt8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxUint8
#define array_handle_set_numeric_mxUint8 array_handle_set_numeric_mxUint8_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxInt16
#define array_handle_set_numeric_mxInt16 array_handle_set_numeric_mxInt16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxUint16
#define array_handle_set_numeric_mxUint16 array_handle_set_numeric_mxUint16_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxInt32
#define array_handle_set_numeric_mxInt32 array_handle_set_numeric_mxInt32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxUint32
#define array_handle_set_numeric_mxUint32 array_handle_set_numeric_mxUint32_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxInt64
#define array_handle_set_numeric_mxInt64 array_handle_set_numeric_mxInt64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_numeric_mxUint64
#define array_handle_set_numeric_mxUint64 array_handle_set_numeric_mxUint64_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_char
#define array_handle_set_char array_handle_set_char_proxy



/**This function is for INTERNAL USE ONLY.**/
/* Map original name to unique proxy layer name. */
#undef array_handle_set_logical
#define array_handle_set_logical array_handle_set_logical_proxy




/*#ifdef mclmcr_h
#error "mclmcrrt.h must be included before mclmcr.h. (Since mclmcrrt.h includes mclmcr.h, additional inclusion is redundant.)"
#endif */
#define LIBMWMCLMCR_API_EXTERN_C EXTERN_C
#include "mclmcr.h"

/* Proxies for functions in mclmcr.h */

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mclCtfStream mclGetStreamFromArraySrc_proxy(char *a0, int a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclDestroyStream_proxy(mclCtfStream a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mclCtfStream mclGetEmbeddedCtfStream_proxy(void *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeComponentInstanceNonEmbeddedStandalone_proxy(
    HMCRINSTANCE *a0, const char *a1, const char *a2, mccTargetType a3, 
    mclOutputHandlerFcn a4, mclOutputHandlerFcn a5, const char *a6);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeInstanceWithoutComponent_proxy(HMCRINSTANCE *a0, 
    const char **a1, size_t a2, mclOutputHandlerFcn a3, 
    mclOutputHandlerFcn a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeComponentInstanceCtfFileToCache_proxy(HMCRINSTANCE *a0, 
    mclOutputHandlerFcn a1, mclOutputHandlerFcn a2, const char *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeComponentInstanceEmbedded_proxy(HMCRINSTANCE *a0, 
    mclOutputHandlerFcn a1, mclOutputHandlerFcn a2, mclCtfStream a3, 
    const char *a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeComponentInstanceWithCallbk_proxy(HMCRINSTANCE *a0, 
    mclOutputHandlerFcn a1, mclOutputHandlerFcn a2, 
    mclReadCtfStreamFcn a3, size_t a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeComponentInstanceFromExtractedComponent_proxy(
    HMCRINSTANCE *a0, mclOutputHandlerFcn a1, mclOutputHandlerFcn a2, 
    const char *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclInitializeComponentInstanceFromExtractedLocation_proxy(
    HMCRINSTANCE *a0, mclOutputHandlerFcn a1, mclOutputHandlerFcn a2, 
    const char *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetDotNetComponentType_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetMCCTargetType_proxy(bool a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
const char * getStandaloneFileName_proxy(const char *a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclStandaloneGenericMain_proxy(size_t a0, const char **a1, 
    const char *a2, bool a3, void *a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclStandaloneCtfxMain_proxy(size_t a0, const char **a1);

EXTERN_C
void mclWaitForFiguresToDie_proxy(HMCRINSTANCE a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclcppGetLastError_proxy(void **a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclcppCreateError_proxy(void **a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclcppSetLastError_proxy(const char *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclcppErrorCheck_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
const char * mclcppGetLastErrorMessage_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclCreateCharBuffer_proxy(void **a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
double mclGetEps_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
double mclGetInf_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
double mclGetNaN_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsFinite_proxy(double a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsInf_proxy(double a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsNaN_proxy(double a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsIdentical_proxy(mxArray *a0, mxArray *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetEmptyArray_proxy(void **a0, mxClassID a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetMatrix_proxy(void **a0, mwSize a1, mwSize a2, mxClassID a3, 
    mxComplexity a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetArray_proxy(void **a0, mwSize a1, const mwSize *a2, 
    mxClassID a3, mxComplexity a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetNumericMatrix_proxy(void **a0, mwSize a1, mwSize a2, 
    mxClassID a3, mxComplexity a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetNumericArray_proxy(void **a0, mwSize a1, const mwSize *a2, 
    mxClassID a3, mxComplexity a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarDouble_proxy(void **a0, mxDouble a1, mxDouble a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarSingle_proxy(void **a0, mxSingle a1, mxSingle a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarInt8_proxy(void **a0, mxInt8 a1, mxInt8 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarUint8_proxy(void **a0, mxUint8 a1, mxUint8 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarInt16_proxy(void **a0, mxInt16 a1, mxInt16 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarUint16_proxy(void **a0, mxUint16 a1, mxUint16 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarInt32_proxy(void **a0, mxInt32 a1, mxInt32 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarUint32_proxy(void **a0, mxUint32 a1, mxUint32 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarInt64_proxy(void **a0, mxInt64 a1, mxInt64 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarUint64_proxy(void **a0, mxUint64 a1, mxUint64 a2, 
    mxComplexity a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetCharMatrix_proxy(void **a0, mwSize a1, mwSize a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetCharArray_proxy(void **a0, mwSize a1, const mwSize *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarChar_proxy(void **a0, mxChar a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetString_proxy(void **a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetCharMatrixFromStrings_proxy(void **a0, mwSize a1, 
    const char **a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsMatlabString_proxy(const mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsMissingStringElement_proxy(const mxArray *a0, mwSize a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateMatlabString_proxy(mwSize a0, const mxChar **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateMatlabStringArray_proxy(mwSize a0, const mwSize *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringGetElement_proxy(const mxArray *a0, mwSize a1, 
    const mxChar **a2, mwSize *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringSetElement_proxy(mxArray *a0, mwSize a1, 
    const mxChar *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringGetData_proxy(const mxArray *a0, const mxChar **a1, 
    mwSize *a2, mwSize *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringSetData_proxy(mxArray *a0, const mxChar **a1, 
    mwSize a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringGetNumberOfDimensions_proxy(const mxArray *a0, 
    mwSize *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringGetDimensions_proxy(const mxArray *a0, 
    const mwSize **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMatlabStringGetNumberOfElements_proxy(const mxArray *a0, 
    mwSize *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetMatlabString_proxy(void **a0, mwSize a1, const mxChar **a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetMatlabStringArray_proxy(void **a0, mwSize a1, const mwSize *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetLogicalMatrix_proxy(void **a0, mwSize a1, mwSize a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetLogicalArray_proxy(void **a0, mwSize a1, const mwSize *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetScalarLogical_proxy(void **a0, mxLogical a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetCellMatrix_proxy(void **a0, mwSize a1, mwSize a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetCellArray_proxy(void **a0, mwSize a1, const mwSize *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetStructMatrix_proxy(void **a0, mwSize a1, mwSize a2, int a3, 
    const char **a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetStructArray_proxy(void **a0, mwSize a1, const mwSize *a2, 
    int a3, const char **a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetNumericSparse_proxy(void **a0, mwSize a1, const mwSize *a2, 
    mwSize a3, const mwSize *a4, mwSize a5, const void *a6, 
    const void *a7, mwSize a8, mwSize a9, mwSize a10, mxClassID a11, 
    mxComplexity a12);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetNumericSparseInferRowsCols_proxy(void **a0, mwSize a1, 
    const mwSize *a2, mwSize a3, const mwSize *a4, mwSize a5, 
    const void *a6, const void *a7, mwSize a8, mxClassID a9, 
    mxComplexity a10);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetLogicalSparse_proxy(void **a0, mwSize a1, const mwIndex *a2, 
    mwSize a3, const mwIndex *a4, mwSize a5, const mxLogical *a6, 
    mwSize a7, mwSize a8, mwSize a9);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetLogicalSparseInferRowsCols_proxy(void **a0, mwSize a1, 
    const mwIndex *a2, mwSize a3, const mwIndex *a4, mwSize a5, 
    const mxLogical *a6, mwSize a7);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclDeserializeArray_proxy(void **a0, void **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclcppGetArrayBuffer_proxy(void **a0, mwSize a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclcppFeval_proxy(HMCRINSTANCE a0, const char *a1, int a2, void **a3, 
    void *a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclcppArrayToString_proxy(mxArray *a0, char **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclcppFreeString_proxy(char *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclmxArray2ArrayHandle_proxy(void **a0, mxArray *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclArrayHandle2mxArray_proxy(mxArray **a0, void *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArrayGetIndexArrays_proxy(mxArray **a0, mxArray **a1, 
    mxArray *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArrayGet_proxy(mxArray **a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArrayGetReal_proxy(mxArray **a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArrayGetImag_proxy(mxArray **a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArraySet_proxy(mxArray *a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArraySetReal_proxy(mxArray *a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArraySetImag_proxy(mxArray *a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMXArraySetLogical_proxy(mxArray *a0, mxArray *a1, mwSize a2, 
    const mwIndex *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclMxRefDestroyArray_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclMxRefSerialize_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclMxRefDeserialize_proxy(const void *a0, size_t a1, size_t a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t mclMxRefMvmId_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t mclHashNBytes_proxy(size_t a0, size_t a1, const char *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwIndex mclCalcSingleSubscript_proxy(const mxArray *a0, mwSize a1, 
    const mwIndex *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclCreateCharMatrixFromUTF16Strings_proxy(mwSize a0, 
    const mxChar **a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mcl2DCharArrayToUTF16Strings_proxy(const mxArray *a0, mxChar **a1, 
    mwSize *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclWrite_proxy(int a0, const void *a1, size_t a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclAddCanonicalPathMacro_proxy(const char *a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclFevalInternal_proxy(HMCRINSTANCE a0, const char *a1, int a2, 
    mxArray **a3, int a4, mxArray **a5);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclGetMaxPathLen_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclmcrInitializeInternal2_proxy(int a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclmcrInitializeInternal_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void deleteWcsStackPointer_hPtr_proxy(pwcsStackPointer a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void initializeWcsStackPointer_proxy(pwcsStackPointer *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void deleteWcsStackPointer_proxy(pwcsStackPointer a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool allocWcsStackPointer_proxy(pwcsStackPointer *a0, int a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mwMbstowcs_proxy(pwcsStackPointer a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void utf16_to_lcp_n_fcn_proxy(char *a0, int32_t *a1, const CHAR16_T *a2, 
    int32_t a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int32_t utf16_strlen_fcn_proxy(const CHAR16_T *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
CHAR16_T * utf16_strncpy_fcn_proxy(CHAR16_T *a0, const CHAR16_T *a1, 
    int32_t a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
CHAR16_T * utf16_strdup_fcn_proxy(const CHAR16_T *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclSetGlobal_proxy(HMCRINSTANCE a0, const char *a1, mxArray *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsStandaloneMode_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclImpersonationFeval_proxy(HMCRINSTANCE a0, const char *a1, int a2, 
    mxArray **a3, int a4, mxArray **a5, void *a6);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclGetGlobal_proxy(HMCRINSTANCE a0, const char *a1, mxArray **a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
long int mclGetID_proxy(HMCRINSTANCE a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int mclMain_proxy(HMCRINSTANCE a0, int a1, const char **a2, 
    const char *a3, int a4);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclMlfVFevalInternal_proxy(HMCRINSTANCE a0, const char *a1, int a2, 
    int a3, int a4, va_list a5);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclGetMCRVersion_proxy(const char **a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t mclGetActiveID_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
char * mclGetTempFileName_proxy(char *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclTerminateInstance_proxy(HMCRINSTANCE *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void stopImpersonationOnMCRThread_proxy(HMCRINSTANCE a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclMxIsA_proxy(HMCRINSTANCE a0, mxArray *a1, const char *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclMxIsRef_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclMxRefIsA_proxy(mxArray *a0, const char *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
const char * mclMxRefGetRefClassName_proxy(const mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclMxRefGetProperty_proxy(const mxArray *a0, mwIndex a1, 
    const char *a2);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclMxRefSetProperty_proxy(mxArray *a0, mwIndex a1, const char *a2, 
    const mxArray *a3);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxArray * mclMxReleaseRef_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
MVMID_t mclMxRefLocalMvm_proxy(mxArray *a0);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclMxDestroyArray_proxy(HMCRINSTANCE a0, mxArray *a1);

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void mclNonDefaultAppDomainInUse_proxy();

/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool mclIsNonDefaultAppDomainInUse_proxy();

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int ref_count_obj_addref_proxy(class ref_count_obj *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int ref_count_obj_release_proxy(class ref_count_obj *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t char_buffer_size_proxy(class char_buffer *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
const char * char_buffer_get_buffer_proxy(class char_buffer *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int char_buffer_set_buffer_proxy(class char_buffer *a0, const char *a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int char_buffer_compare_to_proxy(class char_buffer *a0, 
    class char_buffer *a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxClassID array_ref_classID_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_deep_copy_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void array_ref_detach_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_shared_copy_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_serialize_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t array_ref_element_size_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_ref_number_of_elements_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_ref_number_of_nonzeros_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_ref_maximum_nonzeros_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_ref_number_of_dimensions_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_get_dimensions_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_number_of_fields_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class char_buffer * array_ref_get_field_name_proxy(class array_ref *a0, 
    int a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_is_empty_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_is_sparse_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_is_numeric_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_is_complex_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_is_matlab_string_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_is_missing_string_element_proxy(class array_ref *a0, 
    mwSize a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_make_complex_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_ref_equals_proxy(class array_ref *a0, class array_ref *a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_compare_to_proxy(class array_ref *a0, class array_ref *a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_hash_code_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class char_buffer * array_ref_to_string_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_row_index_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_column_index_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_get_int_proxy(class array_ref *a0, mwSize a1, 
    const mwIndex *a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_get_const_char_proxy(class array_ref *a0, 
    const char *a1, mwSize a2, const mwIndex *a3);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_getV_int_proxy(class array_ref *a0, 
    mwSize a1, va_list a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_getV_const_char_proxy(class array_ref *a0, 
    const char *a1, mwSize a2, va_list a3);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_proxy(class array_ref *a0, class array_ref *a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_real_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_ref_imag_proxy(class array_ref *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxDouble_proxy(class array_ref *a0, 
    mxDouble *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxSingle_proxy(class array_ref *a0, 
    mxSingle *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxInt8_proxy(class array_ref *a0, mxInt8 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxUint8_proxy(class array_ref *a0, mxUint8 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxInt16_proxy(class array_ref *a0, mxInt16 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxUint16_proxy(class array_ref *a0, 
    mxUint16 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxInt32_proxy(class array_ref *a0, mxInt32 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxUint32_proxy(class array_ref *a0, 
    mxUint32 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxInt64_proxy(class array_ref *a0, mxInt64 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_numeric_mxUint64_proxy(class array_ref *a0, 
    mxUint64 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_char_proxy(class array_ref *a0, mxChar *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_string_element_proxy(class array_ref *a0, mwSize a1, 
    const mxChar **a2, mwSize *a3);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_matlab_string_proxy(class array_ref *a0, 
    const mxChar **a1, mwSize *a2, mwSize *a3);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_get_logical_proxy(class array_ref *a0, mxLogical *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxDouble_proxy(class array_ref *a0, 
    const mxDouble *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxSingle_proxy(class array_ref *a0, 
    const mxSingle *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxInt8_proxy(class array_ref *a0, 
    const mxInt8 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxUint8_proxy(class array_ref *a0, 
    const mxUint8 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxInt16_proxy(class array_ref *a0, 
    const mxInt16 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxUint16_proxy(class array_ref *a0, 
    const mxUint16 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxInt32_proxy(class array_ref *a0, 
    const mxInt32 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxUint32_proxy(class array_ref *a0, 
    const mxUint32 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxInt64_proxy(class array_ref *a0, 
    const mxInt64 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_numeric_mxUint64_proxy(class array_ref *a0, 
    const mxUint64 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_char_proxy(class array_ref *a0, const mxChar *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_string_element_proxy(class array_ref *a0, mwSize a1, 
    const mxChar *a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_matlab_string_proxy(class array_ref *a0, 
    const mxChar **a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_ref_set_logical_proxy(class array_ref *a0, const mxLogical *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_buffer_size_proxy(class array_buffer *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_buffer_get_proxy(class array_buffer *a0, 
    mwIndex a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_buffer_set_proxy(class array_buffer *a0, mwIndex a1, 
    class array_ref *a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_buffer_add_proxy(class array_buffer *a0, class array_ref *a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_buffer_remove_proxy(class array_buffer *a0, mwIndex a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_buffer_clear_proxy(class array_buffer *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class array_ref * array_buffer_to_cell_proxy(class array_buffer *a0, 
    mwIndex a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
const char * error_info_get_message_proxy(class error_info *a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t error_info_get_stack_trace_proxy(class error_info *a0, char ***a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mxClassID array_handle_classID_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_deep_copy_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
void array_handle_detach_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_shared_copy_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_serialize_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
size_t array_handle_element_size_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_handle_number_of_elements_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_handle_number_of_nonzeros_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_handle_maximum_nonzeros_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
mwSize array_handle_number_of_dimensions_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_get_dimensions_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_number_of_fields_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class char_buffer * array_handle_get_field_name_proxy(array_handle a0, 
    int a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_handle_is_empty_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_handle_is_sparse_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_handle_is_numeric_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_handle_is_complex_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_make_complex_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
bool array_handle_equals_proxy(array_handle a0, array_handle a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_compare_to_proxy(array_handle a0, array_handle a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_hash_code_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
class char_buffer * array_handle_to_string_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_row_index_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_column_index_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_get_int_proxy(array_handle a0, mwSize a1, 
    const mwIndex *a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_get_const_char_proxy(array_handle a0, 
    const char *a1, mwSize a2, const mwIndex *a3);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_getV_int_proxy(array_handle a0, mwSize a1, 
    va_list a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_getV_const_char_proxy(array_handle a0, 
    const char *a1, mwSize a2, va_list a3);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_proxy(array_handle a0, array_handle a1);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_real_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
array_handle array_handle_imag_proxy(array_handle a0);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxDouble_proxy(array_handle a0, 
    mxDouble *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxSingle_proxy(array_handle a0, 
    mxSingle *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxInt8_proxy(array_handle a0, mxInt8 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxUint8_proxy(array_handle a0, mxUint8 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxInt16_proxy(array_handle a0, mxInt16 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxUint16_proxy(array_handle a0, 
    mxUint16 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxInt32_proxy(array_handle a0, mxInt32 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxUint32_proxy(array_handle a0, 
    mxUint32 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxInt64_proxy(array_handle a0, mxInt64 *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_numeric_mxUint64_proxy(array_handle a0, 
    mxUint64 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_char_proxy(array_handle a0, mxChar *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_get_logical_proxy(array_handle a0, mxLogical *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxDouble_proxy(array_handle a0, 
    const mxDouble *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxSingle_proxy(array_handle a0, 
    const mxSingle *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxInt8_proxy(array_handle a0, 
    const mxInt8 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxUint8_proxy(array_handle a0, 
    const mxUint8 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxInt16_proxy(array_handle a0, 
    const mxInt16 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxUint16_proxy(array_handle a0, 
    const mxUint16 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxInt32_proxy(array_handle a0, 
    const mxInt32 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxUint32_proxy(array_handle a0, 
    const mxUint32 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxInt64_proxy(array_handle a0, 
    const mxInt64 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_numeric_mxUint64_proxy(array_handle a0, 
    const mxUint64 *a1, mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_char_proxy(array_handle a0, const mxChar *a1, 
    mwSize a2);
#endif /* __cplusplus */

#ifdef __cplusplus /* Only available in C++ */
/**This function is for INTERNAL USE ONLY.**/
EXTERN_C
int array_handle_set_logical_proxy(array_handle a0, const mxLogical *a1, 
    mwSize a2);
#endif /* __cplusplus */


#if !defined(MW_BUILD_ARCHIVES)
#ifdef __cplusplus
extern "C"
{
#endif


#undef mclMlfVFeval
#define mclMlfVFeval mclMlfVFeval_proxy


#ifdef __cplusplus
}
#endif
#endif


#ifdef __cplusplus
extern "C"
{
#endif


#if !defined(MW_BUILD_ARCHIVES)
#undef mclFeval
#define mclFeval mclFeval_proxy
#endif


EXTERN_C
bool MW_CALL_CONV mclFeval_proxy(HMCRINSTANCE a0, const char *a1, int a2,
                                 mxArray **a3, int a4, mxArray **a5);



#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C"
{
#endif


#if !defined(MW_BUILD_ARCHIVES)
#undef mclMlfFeval
#define mclMlfFeval mclMlfFeval_proxy
#endif


EXTERN_C
bool MW_CALL_CONV mclMlfFeval_proxy(HMCRINSTANCE a0, const char *a1,
		  	            int a2, int a3, int a4, ...);


#ifdef __cplusplus
}
#endif

#ifndef MW_CALL_CONV
#  ifdef _WIN32 
#      define MW_CALL_CONV __cdecl
#  else
#      define MW_CALL_CONV 
#  endif
#endif

#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfDimensions_700
#define mxGetNumberOfDimensions_700 mxGetNumberOfDimensions_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetDimensions_700
#define mxGetDimensions_700 mxGetDimensions_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetIr_700
#define mxGetIr_700 mxGetIr_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetJc_700
#define mxGetJc_700 mxGetJc_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetNzmax_700
#define mxGetNzmax_700 mxGetNzmax_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetNzmax_700
#define mxSetNzmax_700 mxSetNzmax_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetFieldByNumber_700
#define mxGetFieldByNumber_700 mxGetFieldByNumber_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetCell_700
#define mxGetCell_700 mxGetCell_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetM_700
#define mxSetM_700 mxSetM_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetIr_700
#define mxSetIr_700 mxSetIr_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetJc_700
#define mxSetJc_700 mxSetJc_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCalcSingleSubscript_700
#define mxCalcSingleSubscript_700 mxCalcSingleSubscript_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetCell_700
#define mxSetCell_700 mxSetCell_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetFieldByNumber_700
#define mxSetFieldByNumber_700 mxSetFieldByNumber_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetField_700
#define mxGetField_700 mxGetField_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetField_700
#define mxSetField_700 mxSetField_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateNumericMatrix_700
#define mxCreateNumericMatrix_700 mxCreateNumericMatrix_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetN_700
#define mxSetN_700 mxSetN_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxSetDimensions_700
#define mxSetDimensions_700 mxSetDimensions_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateNumericArray_700
#define mxCreateNumericArray_700 mxCreateNumericArray_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateCharArray_700
#define mxCreateCharArray_700 mxCreateCharArray_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateDoubleMatrix_700
#define mxCreateDoubleMatrix_700 mxCreateDoubleMatrix_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalArray_700
#define mxCreateLogicalArray_700 mxCreateLogicalArray_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalMatrix_700
#define mxCreateLogicalMatrix_700 mxCreateLogicalMatrix_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateSparse_700
#define mxCreateSparse_700 mxCreateSparse_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateSparseLogicalMatrix_700
#define mxCreateSparseLogicalMatrix_700 mxCreateSparseLogicalMatrix_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetNChars_700
#define mxGetNChars_700 mxGetNChars_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxGetString_700
#define mxGetString_700 mxGetString_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateStringFromNChars_700
#define mxCreateStringFromNChars_700 mxCreateStringFromNChars_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateCharMatrixFromStrings_700
#define mxCreateCharMatrixFromStrings_700 mxCreateCharMatrixFromStrings_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateCellMatrix_700
#define mxCreateCellMatrix_700 mxCreateCellMatrix_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateCellArray_700
#define mxCreateCellArray_700 mxCreateCellArray_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateStructMatrix_700
#define mxCreateStructMatrix_700 mxCreateStructMatrix_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if defined(MX_COMPAT_32)
/* Map original name to unique proxy layer name. */
#undef mxCreateStructArray_700
#define mxCreateStructArray_700 mxCreateStructArray_700_proxy
#endif   /* defined(MX_COMPAT_32) */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxMalloc
#define mxMalloc mxMalloc_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCalloc
#define mxCalloc mxCalloc_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxFree
#define mxFree mxFree_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxRealloc
#define mxRealloc mxRealloc_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfDimensions_730
#define mxGetNumberOfDimensions_730 mxGetNumberOfDimensions_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetDimensions_730
#define mxGetDimensions_730 mxGetDimensions_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetM
#define mxGetM mxGetM_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetIr_730
#define mxGetIr_730 mxGetIr_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetJc_730
#define mxGetJc_730 mxGetJc_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetNzmax_730
#define mxGetNzmax_730 mxGetNzmax_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetNzmax_730
#define mxSetNzmax_730 mxSetNzmax_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetFieldNameByNumber
#define mxGetFieldNameByNumber mxGetFieldNameByNumber_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetFieldByNumber_730
#define mxGetFieldByNumber_730 mxGetFieldByNumber_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetCell_730
#define mxGetCell_730 mxGetCell_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetClassID
#define mxGetClassID mxGetClassID_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetData
#define mxGetData mxGetData_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetData
#define mxSetData mxSetData_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsNumeric
#define mxIsNumeric mxIsNumeric_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsCell
#define mxIsCell mxIsCell_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsLogical
#define mxIsLogical mxIsLogical_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsScalar
#define mxIsScalar mxIsScalar_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsChar
#define mxIsChar mxIsChar_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsStruct
#define mxIsStruct mxIsStruct_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsOpaque
#define mxIsOpaque mxIsOpaque_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsFunctionHandle
#define mxIsFunctionHandle mxIsFunctionHandle_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsObject
#define mxIsObject mxIsObject_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetImagData
#define mxGetImagData mxGetImagData_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetImagData
#define mxSetImagData mxSetImagData_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsComplex
#define mxIsComplex mxIsComplex_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsSparse
#define mxIsSparse mxIsSparse_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsDouble
#define mxIsDouble mxIsDouble_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsSingle
#define mxIsSingle mxIsSingle_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt8
#define mxIsInt8 mxIsInt8_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint8
#define mxIsUint8 mxIsUint8_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt16
#define mxIsInt16 mxIsInt16_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint16
#define mxIsUint16 mxIsUint16_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt32
#define mxIsInt32 mxIsInt32_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint32
#define mxIsUint32 mxIsUint32_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt64
#define mxIsInt64 mxIsInt64_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint64
#define mxIsUint64 mxIsUint64_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfElements
#define mxGetNumberOfElements mxGetNumberOfElements_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetPi
#define mxGetPi mxGetPi_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetPi
#define mxSetPi mxSetPi_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetChars
#define mxGetChars mxGetChars_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetUserBits
#define mxGetUserBits mxGetUserBits_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetUserBits
#define mxSetUserBits mxSetUserBits_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetScalar
#define mxGetScalar mxGetScalar_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsFromGlobalWS
#define mxIsFromGlobalWS mxIsFromGlobalWS_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetFromGlobalWS
#define mxSetFromGlobalWS mxSetFromGlobalWS_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetM_730
#define mxSetM_730 mxSetM_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetN
#define mxGetN mxGetN_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsEmpty
#define mxIsEmpty mxIsEmpty_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetFieldNumber
#define mxGetFieldNumber mxGetFieldNumber_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetIr_730
#define mxSetIr_730 mxSetIr_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetJc_730
#define mxSetJc_730 mxSetJc_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetPr
#define mxGetPr mxGetPr_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetPr
#define mxSetPr mxSetPr_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetElementSize
#define mxGetElementSize mxGetElementSize_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCalcSingleSubscript_730
#define mxCalcSingleSubscript_730 mxCalcSingleSubscript_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfFields
#define mxGetNumberOfFields mxGetNumberOfFields_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetCell_730
#define mxSetCell_730 mxSetCell_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetFieldByNumber_730
#define mxSetFieldByNumber_730 mxSetFieldByNumber_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetField_730
#define mxGetField_730 mxGetField_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetField_730
#define mxSetField_730 mxSetField_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsClass
#define mxIsClass mxIsClass_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateNumericMatrix_730
#define mxCreateNumericMatrix_730 mxCreateNumericMatrix_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateUninitNumericMatrix
#define mxCreateUninitNumericMatrix mxCreateUninitNumericMatrix_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateUninitNumericArray
#define mxCreateUninitNumericArray mxCreateUninitNumericArray_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetN_730
#define mxSetN_730 mxSetN_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetDimensions_730
#define mxSetDimensions_730 mxSetDimensions_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxDestroyArray
#define mxDestroyArray mxDestroyArray_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateNumericArray_730
#define mxCreateNumericArray_730 mxCreateNumericArray_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCharArray_730
#define mxCreateCharArray_730 mxCreateCharArray_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateDoubleMatrix_730
#define mxCreateDoubleMatrix_730 mxCreateDoubleMatrix_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetLogicals
#define mxGetLogicals mxGetLogicals_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalArray_730
#define mxCreateLogicalArray_730 mxCreateLogicalArray_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalMatrix_730
#define mxCreateLogicalMatrix_730 mxCreateLogicalMatrix_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalScalar
#define mxCreateLogicalScalar mxCreateLogicalScalar_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsLogicalScalar
#define mxIsLogicalScalar mxIsLogicalScalar_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsLogicalScalarTrue
#define mxIsLogicalScalarTrue mxIsLogicalScalarTrue_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateDoubleScalar
#define mxCreateDoubleScalar mxCreateDoubleScalar_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateSparse_730
#define mxCreateSparse_730 mxCreateSparse_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateSparseLogicalMatrix_730
#define mxCreateSparseLogicalMatrix_730 mxCreateSparseLogicalMatrix_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetNChars_730
#define mxGetNChars_730 mxGetNChars_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetString_730
#define mxGetString_730 mxGetString_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxArrayToString
#define mxArrayToString mxArrayToString_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxArrayToUTF8String
#define mxArrayToUTF8String mxArrayToUTF8String_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateStringFromNChars_730
#define mxCreateStringFromNChars_730 mxCreateStringFromNChars_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateString
#define mxCreateString mxCreateString_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCharMatrixFromStrings_730
#define mxCreateCharMatrixFromStrings_730 mxCreateCharMatrixFromStrings_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCellMatrix_730
#define mxCreateCellMatrix_730 mxCreateCellMatrix_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCellArray_730
#define mxCreateCellArray_730 mxCreateCellArray_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateStructMatrix_730
#define mxCreateStructMatrix_730 mxCreateStructMatrix_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateStructArray_730
#define mxCreateStructArray_730 mxCreateStructArray_730_proxy
#endif   /* !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxDuplicateArray
#define mxDuplicateArray mxDuplicateArray_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxSetClassName
#define mxSetClassName mxSetClassName_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxAddField
#define mxAddField mxAddField_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxRemoveField
#define mxRemoveField mxRemoveField_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetEps
#define mxGetEps mxGetEps_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetInf
#define mxGetInf mxGetInf_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxGetNaN
#define mxGetNaN mxGetNaN_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsFinite
#define mxIsFinite mxIsFinite_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsInf
#define mxIsInf mxIsInf_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxIsNaN
#define mxIsNaN mxIsNaN_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateSharedDataCopy
#define mxCreateSharedDataCopy mxCreateSharedDataCopy_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxCreateUninitDoubleMatrix
#define mxCreateUninitDoubleMatrix mxCreateUninitDoubleMatrix_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxFastZeros
#define mxFastZeros mxFastZeros_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxUnreference
#define mxUnreference mxUnreference_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION < 800
/* Map original name to unique proxy layer name. */
#undef mxUnshareArray
#define mxUnshareArray mxUnshareArray_proxy
#endif   /* TARGET_API_VERSION < 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxMalloc_800
#define mxMalloc_800 mxMalloc_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCalloc_800
#define mxCalloc_800 mxCalloc_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxFree_800
#define mxFree_800 mxFree_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxRealloc_800
#define mxRealloc_800 mxRealloc_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfDimensions_800
#define mxGetNumberOfDimensions_800 mxGetNumberOfDimensions_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetDimensions_800
#define mxGetDimensions_800 mxGetDimensions_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetM_800
#define mxGetM_800 mxGetM_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetIr_800
#define mxGetIr_800 mxGetIr_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetJc_800
#define mxGetJc_800 mxGetJc_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetNzmax_800
#define mxGetNzmax_800 mxGetNzmax_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetNzmax_800
#define mxSetNzmax_800 mxSetNzmax_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetFieldNameByNumber_800
#define mxGetFieldNameByNumber_800 mxGetFieldNameByNumber_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetFieldByNumber_800
#define mxGetFieldByNumber_800 mxGetFieldByNumber_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetCell_800
#define mxGetCell_800 mxGetCell_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetClassID_800
#define mxGetClassID_800 mxGetClassID_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetData_800
#define mxGetData_800 mxGetData_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetData_800
#define mxSetData_800 mxSetData_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsNumeric_800
#define mxIsNumeric_800 mxIsNumeric_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsCell_800
#define mxIsCell_800 mxIsCell_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsLogical_800
#define mxIsLogical_800 mxIsLogical_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsScalar_800
#define mxIsScalar_800 mxIsScalar_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsChar_800
#define mxIsChar_800 mxIsChar_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsStruct_800
#define mxIsStruct_800 mxIsStruct_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsOpaque_800
#define mxIsOpaque_800 mxIsOpaque_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsFunctionHandle_800
#define mxIsFunctionHandle_800 mxIsFunctionHandle_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsObject_800
#define mxIsObject_800 mxIsObject_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsComplex_800
#define mxIsComplex_800 mxIsComplex_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsSparse_800
#define mxIsSparse_800 mxIsSparse_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsDouble_800
#define mxIsDouble_800 mxIsDouble_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsSingle_800
#define mxIsSingle_800 mxIsSingle_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt8_800
#define mxIsInt8_800 mxIsInt8_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint8_800
#define mxIsUint8_800 mxIsUint8_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt16_800
#define mxIsInt16_800 mxIsInt16_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint16_800
#define mxIsUint16_800 mxIsUint16_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt32_800
#define mxIsInt32_800 mxIsInt32_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint32_800
#define mxIsUint32_800 mxIsUint32_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsInt64_800
#define mxIsInt64_800 mxIsInt64_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsUint64_800
#define mxIsUint64_800 mxIsUint64_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfElements_800
#define mxGetNumberOfElements_800 mxGetNumberOfElements_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetChars_800
#define mxGetChars_800 mxGetChars_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetUserBits_800
#define mxGetUserBits_800 mxGetUserBits_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetUserBits_800
#define mxSetUserBits_800 mxSetUserBits_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetScalar_800
#define mxGetScalar_800 mxGetScalar_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsFromGlobalWS_800
#define mxIsFromGlobalWS_800 mxIsFromGlobalWS_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetFromGlobalWS_800
#define mxSetFromGlobalWS_800 mxSetFromGlobalWS_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetM_800
#define mxSetM_800 mxSetM_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetN_800
#define mxGetN_800 mxGetN_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsEmpty_800
#define mxIsEmpty_800 mxIsEmpty_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetFieldNumber_800
#define mxGetFieldNumber_800 mxGetFieldNumber_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetIr_800
#define mxSetIr_800 mxSetIr_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetJc_800
#define mxSetJc_800 mxSetJc_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetPr_800
#define mxGetPr_800 mxGetPr_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetPr_800
#define mxSetPr_800 mxSetPr_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetElementSize_800
#define mxGetElementSize_800 mxGetElementSize_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCalcSingleSubscript_800
#define mxCalcSingleSubscript_800 mxCalcSingleSubscript_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetNumberOfFields_800
#define mxGetNumberOfFields_800 mxGetNumberOfFields_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetCell_800
#define mxSetCell_800 mxSetCell_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetFieldByNumber_800
#define mxSetFieldByNumber_800 mxSetFieldByNumber_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetField_800
#define mxGetField_800 mxGetField_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetField_800
#define mxSetField_800 mxSetField_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsClass_800
#define mxIsClass_800 mxIsClass_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateNumericMatrix_800
#define mxCreateNumericMatrix_800 mxCreateNumericMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateUninitNumericMatrix_800
#define mxCreateUninitNumericMatrix_800 mxCreateUninitNumericMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateUninitNumericArray_800
#define mxCreateUninitNumericArray_800 mxCreateUninitNumericArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetN_800
#define mxSetN_800 mxSetN_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetDimensions_800
#define mxSetDimensions_800 mxSetDimensions_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxDestroyArray_800
#define mxDestroyArray_800 mxDestroyArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateNumericArray_800
#define mxCreateNumericArray_800 mxCreateNumericArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCharArray_800
#define mxCreateCharArray_800 mxCreateCharArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateDoubleMatrix_800
#define mxCreateDoubleMatrix_800 mxCreateDoubleMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetLogicals_800
#define mxGetLogicals_800 mxGetLogicals_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalArray_800
#define mxCreateLogicalArray_800 mxCreateLogicalArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalMatrix_800
#define mxCreateLogicalMatrix_800 mxCreateLogicalMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateLogicalScalar_800
#define mxCreateLogicalScalar_800 mxCreateLogicalScalar_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsLogicalScalar_800
#define mxIsLogicalScalar_800 mxIsLogicalScalar_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsLogicalScalarTrue_800
#define mxIsLogicalScalarTrue_800 mxIsLogicalScalarTrue_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateDoubleScalar_800
#define mxCreateDoubleScalar_800 mxCreateDoubleScalar_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateSparse_800
#define mxCreateSparse_800 mxCreateSparse_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateSparseLogicalMatrix_800
#define mxCreateSparseLogicalMatrix_800 mxCreateSparseLogicalMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetNChars_800
#define mxGetNChars_800 mxGetNChars_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetString_800
#define mxGetString_800 mxGetString_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxArrayToString_800
#define mxArrayToString_800 mxArrayToString_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxArrayToUTF8String_800
#define mxArrayToUTF8String_800 mxArrayToUTF8String_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateStringFromNChars_800
#define mxCreateStringFromNChars_800 mxCreateStringFromNChars_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateString_800
#define mxCreateString_800 mxCreateString_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCharMatrixFromStrings_800
#define mxCreateCharMatrixFromStrings_800 mxCreateCharMatrixFromStrings_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCellMatrix_800
#define mxCreateCellMatrix_800 mxCreateCellMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateCellArray_800
#define mxCreateCellArray_800 mxCreateCellArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateStructMatrix_800
#define mxCreateStructMatrix_800 mxCreateStructMatrix_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxCreateStructArray_800
#define mxCreateStructArray_800 mxCreateStructArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxDuplicateArray_800
#define mxDuplicateArray_800 mxDuplicateArray_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetClassName_800
#define mxSetClassName_800 mxSetClassName_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxAddField_800
#define mxAddField_800 mxAddField_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxRemoveField_800
#define mxRemoveField_800 mxRemoveField_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetEps_800
#define mxGetEps_800 mxGetEps_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetInf_800
#define mxGetInf_800 mxGetInf_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetNaN_800
#define mxGetNaN_800 mxGetNaN_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsFinite_800
#define mxIsFinite_800 mxIsFinite_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsInf_800
#define mxIsInf_800 mxIsInf_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxIsNaN_800
#define mxIsNaN_800 mxIsNaN_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetDoubles_800
#define mxGetDoubles_800 mxGetDoubles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetDoubles_800
#define mxSetDoubles_800 mxSetDoubles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexDoubles_800
#define mxGetComplexDoubles_800 mxGetComplexDoubles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexDoubles_800
#define mxSetComplexDoubles_800 mxSetComplexDoubles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetSingles_800
#define mxGetSingles_800 mxGetSingles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetSingles_800
#define mxSetSingles_800 mxSetSingles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexSingles_800
#define mxGetComplexSingles_800 mxGetComplexSingles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexSingles_800
#define mxSetComplexSingles_800 mxSetComplexSingles_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetInt8s_800
#define mxGetInt8s_800 mxGetInt8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetInt8s_800
#define mxSetInt8s_800 mxSetInt8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexInt8s_800
#define mxGetComplexInt8s_800 mxGetComplexInt8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexInt8s_800
#define mxSetComplexInt8s_800 mxSetComplexInt8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetUint8s_800
#define mxGetUint8s_800 mxGetUint8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetUint8s_800
#define mxSetUint8s_800 mxSetUint8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexUint8s_800
#define mxGetComplexUint8s_800 mxGetComplexUint8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexUint8s_800
#define mxSetComplexUint8s_800 mxSetComplexUint8s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetInt16s_800
#define mxGetInt16s_800 mxGetInt16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetInt16s_800
#define mxSetInt16s_800 mxSetInt16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexInt16s_800
#define mxGetComplexInt16s_800 mxGetComplexInt16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexInt16s_800
#define mxSetComplexInt16s_800 mxSetComplexInt16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetUint16s_800
#define mxGetUint16s_800 mxGetUint16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetUint16s_800
#define mxSetUint16s_800 mxSetUint16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexUint16s_800
#define mxGetComplexUint16s_800 mxGetComplexUint16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexUint16s_800
#define mxSetComplexUint16s_800 mxSetComplexUint16s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetInt32s_800
#define mxGetInt32s_800 mxGetInt32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetInt32s_800
#define mxSetInt32s_800 mxSetInt32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexInt32s_800
#define mxGetComplexInt32s_800 mxGetComplexInt32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexInt32s_800
#define mxSetComplexInt32s_800 mxSetComplexInt32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetUint32s_800
#define mxGetUint32s_800 mxGetUint32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetUint32s_800
#define mxSetUint32s_800 mxSetUint32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexUint32s_800
#define mxGetComplexUint32s_800 mxGetComplexUint32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexUint32s_800
#define mxSetComplexUint32s_800 mxSetComplexUint32s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetInt64s_800
#define mxGetInt64s_800 mxGetInt64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetInt64s_800
#define mxSetInt64s_800 mxSetInt64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexInt64s_800
#define mxGetComplexInt64s_800 mxGetComplexInt64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexInt64s_800
#define mxSetComplexInt64s_800 mxSetComplexInt64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetUint64s_800
#define mxGetUint64s_800 mxGetUint64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetUint64s_800
#define mxSetUint64s_800 mxSetUint64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxGetComplexUint64s_800
#define mxGetComplexUint64s_800 mxGetComplexUint64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxSetComplexUint64s_800
#define mxSetComplexUint64s_800 mxSetComplexUint64s_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxMakeArrayReal_800
#define mxMakeArrayReal_800 mxMakeArrayReal_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */



#if TARGET_API_VERSION >= 800
/* Map original name to unique proxy layer name. */
#undef mxMakeArrayComplex_800
#define mxMakeArrayComplex_800 mxMakeArrayComplex_800_proxy
#endif   /* TARGET_API_VERSION >= 800 */




#define LIBMWMATRIX_API_EXTERN_C EXTERN_C

/* Proxies for functions in matrix.h */

#if defined(MX_COMPAT_32)
EXTERN_C
mwSize mxGetNumberOfDimensions_700_proxy(const mxArray *a0);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
const mwSize * mxGetDimensions_700_proxy(const mxArray *a0);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mwIndex * mxGetIr_700_proxy(const mxArray *a0);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mwIndex * mxGetJc_700_proxy(const mxArray *a0);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mwSize mxGetNzmax_700_proxy(const mxArray *a0);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetNzmax_700_proxy(mxArray *a0, mwSize a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxGetFieldByNumber_700_proxy(const mxArray *a0, mwIndex a1, 
    int a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxGetCell_700_proxy(const mxArray *a0, mwIndex a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetM_700_proxy(mxArray *a0, mwSize a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetIr_700_proxy(mxArray *a0, mwIndex *a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetJc_700_proxy(mxArray *a0, mwIndex *a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mwIndex mxCalcSingleSubscript_700_proxy(const mxArray *a0, mwSize a1, 
    const mwIndex *a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetCell_700_proxy(mxArray *a0, mwIndex a1, mxArray *a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetFieldByNumber_700_proxy(mxArray *a0, mwIndex a1, int a2, 
    mxArray *a3);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxGetField_700_proxy(const mxArray *a0, mwIndex a1, 
    const char *a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetField_700_proxy(mxArray *a0, mwIndex a1, const char *a2, 
    mxArray *a3);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateNumericMatrix_700_proxy(mwSize a0, mwSize a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxSetN_700_proxy(mxArray *a0, mwSize a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
int mxSetDimensions_700_proxy(mxArray *a0, const mwSize *a1, mwSize a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateNumericArray_700_proxy(mwSize a0, const mwSize *a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateCharArray_700_proxy(mwSize a0, const mwSize *a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateDoubleMatrix_700_proxy(mwSize a0, mwSize a1, 
    mxComplexity a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateLogicalArray_700_proxy(mwSize a0, const mwSize *a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateLogicalMatrix_700_proxy(mwSize a0, mwSize a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateSparse_700_proxy(mwSize a0, mwSize a1, mwSize a2, 
    mxComplexity a3);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateSparseLogicalMatrix_700_proxy(mwSize a0, mwSize a1, 
    mwSize a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
void mxGetNChars_700_proxy(const mxArray *a0, char *a1, mwSize a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
int mxGetString_700_proxy(const mxArray *a0, char *a1, mwSize a2);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateStringFromNChars_700_proxy(const char *a0, mwSize a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateCharMatrixFromStrings_700_proxy(mwSize a0, 
    const char **a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateCellMatrix_700_proxy(mwSize a0, mwSize a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateCellArray_700_proxy(mwSize a0, const mwSize *a1);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateStructMatrix_700_proxy(mwSize a0, mwSize a1, int a2, 
    const char **a3);
#endif

#if defined(MX_COMPAT_32)
EXTERN_C
mxArray * mxCreateStructArray_700_proxy(mwSize a0, const mwSize *a1, 
    int a2, const char **a3);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void * mxMalloc_proxy(size_t a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void * mxCalloc_proxy(size_t a0, size_t a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxFree_proxy(void *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void * mxRealloc_proxy(void *a0, size_t a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mwSize mxGetNumberOfDimensions_730_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
const mwSize * mxGetDimensions_730_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
size_t mxGetM_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mwIndex * mxGetIr_730_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mwIndex * mxGetJc_730_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mwSize mxGetNzmax_730_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetNzmax_730_proxy(mxArray *a0, mwSize a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
const char * mxGetFieldNameByNumber_proxy(const mxArray *a0, int a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxGetFieldByNumber_730_proxy(const mxArray *a0, mwIndex a1, 
    int a2);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxGetCell_730_proxy(const mxArray *a0, mwIndex a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxClassID mxGetClassID_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void * mxGetData_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxSetData_proxy(mxArray *a0, void *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsNumeric_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsCell_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsLogical_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsScalar_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsChar_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsStruct_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsOpaque_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsFunctionHandle_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsObject_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void * mxGetImagData_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxSetImagData_proxy(mxArray *a0, void *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsComplex_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsSparse_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsDouble_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsSingle_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsInt8_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsUint8_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsInt16_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsUint16_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsInt32_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsUint32_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsInt64_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsUint64_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
size_t mxGetNumberOfElements_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
double * mxGetPi_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxSetPi_proxy(mxArray *a0, double *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxChar * mxGetChars_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
int mxGetUserBits_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxSetUserBits_proxy(mxArray *a0, int a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
double mxGetScalar_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsFromGlobalWS_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxSetFromGlobalWS_proxy(mxArray *a0, bool a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetM_730_proxy(mxArray *a0, mwSize a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
size_t mxGetN_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsEmpty_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
int mxGetFieldNumber_proxy(const mxArray *a0, const char *a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetIr_730_proxy(mxArray *a0, mwIndex *a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetJc_730_proxy(mxArray *a0, mwIndex *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
double * mxGetPr_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxSetPr_proxy(mxArray *a0, double *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
size_t mxGetElementSize_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mwIndex mxCalcSingleSubscript_730_proxy(const mxArray *a0, mwSize a1, 
    const mwIndex *a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
int mxGetNumberOfFields_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetCell_730_proxy(mxArray *a0, mwIndex a1, mxArray *a2);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetFieldByNumber_730_proxy(mxArray *a0, mwIndex a1, int a2, 
    mxArray *a3);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxGetField_730_proxy(const mxArray *a0, mwIndex a1, 
    const char *a2);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetField_730_proxy(mxArray *a0, mwIndex a1, const char *a2, 
    mxArray *a3);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsClass_proxy(const mxArray *a0, const char *a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateNumericMatrix_730_proxy(mwSize a0, mwSize a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateUninitNumericMatrix_proxy(size_t a0, size_t a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateUninitNumericArray_proxy(size_t a0, size_t *a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxSetN_730_proxy(mxArray *a0, mwSize a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
int mxSetDimensions_730_proxy(mxArray *a0, const mwSize *a1, mwSize a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxDestroyArray_proxy(mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateNumericArray_730_proxy(mwSize a0, const mwSize *a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateCharArray_730_proxy(mwSize a0, const mwSize *a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateDoubleMatrix_730_proxy(mwSize a0, mwSize a1, 
    mxComplexity a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxLogical * mxGetLogicals_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateLogicalArray_730_proxy(mwSize a0, const mwSize *a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateLogicalMatrix_730_proxy(mwSize a0, mwSize a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateLogicalScalar_proxy(bool a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsLogicalScalar_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsLogicalScalarTrue_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateDoubleScalar_proxy(double a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateSparse_730_proxy(mwSize a0, mwSize a1, mwSize a2, 
    mxComplexity a3);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateSparseLogicalMatrix_730_proxy(mwSize a0, mwSize a1, 
    mwSize a2);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
void mxGetNChars_730_proxy(const mxArray *a0, char *a1, mwSize a2);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
int mxGetString_730_proxy(const mxArray *a0, char *a1, mwSize a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
char * mxArrayToString_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
char * mxArrayToUTF8String_proxy(const mxArray *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateStringFromNChars_730_proxy(const char *a0, mwSize a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateString_proxy(const char *a0);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateCharMatrixFromStrings_730_proxy(mwSize a0, 
    const char **a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateCellMatrix_730_proxy(mwSize a0, mwSize a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateCellArray_730_proxy(mwSize a0, const mwSize *a1);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateStructMatrix_730_proxy(mwSize a0, mwSize a1, int a2, 
    const char **a3);
#endif

#if !defined(MX_COMPAT_32) && TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateStructArray_730_proxy(mwSize a0, const mwSize *a1, 
    int a2, const char **a3);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxDuplicateArray_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
int mxSetClassName_proxy(mxArray *a0, const char *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
int mxAddField_proxy(mxArray *a0, const char *a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
void mxRemoveField_proxy(mxArray *a0, int a1);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
double mxGetEps_proxy();
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
double mxGetInf_proxy();
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
double mxGetNaN_proxy();
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsFinite_proxy(double a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsInf_proxy(double a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
bool mxIsNaN_proxy(double a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateSharedDataCopy_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxCreateUninitDoubleMatrix_proxy(int a0, size_t a1, size_t a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxFastZeros_proxy(int a0, int a1, int a2);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
mxArray * mxUnreference_proxy(mxArray *a0);
#endif

#if TARGET_API_VERSION < 800
EXTERN_C
int mxUnshareArray_proxy(mxArray *a0, int a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void * mxMalloc_800_proxy(size_t a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void * mxCalloc_800_proxy(size_t a0, size_t a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxFree_800_proxy(void *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void * mxRealloc_800_proxy(void *a0, size_t a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mwSize mxGetNumberOfDimensions_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
const mwSize * mxGetDimensions_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
size_t mxGetM_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mwIndex * mxGetIr_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mwIndex * mxGetJc_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mwSize mxGetNzmax_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetNzmax_800_proxy(mxArray *a0, mwSize a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
const char * mxGetFieldNameByNumber_800_proxy(const mxArray *a0, int a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxGetFieldByNumber_800_proxy(const mxArray *a0, mwIndex a1, 
    int a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxGetCell_800_proxy(const mxArray *a0, mwIndex a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxClassID mxGetClassID_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void * mxGetData_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetData_800_proxy(mxArray *a0, void *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsNumeric_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsCell_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsLogical_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsScalar_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsChar_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsStruct_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsOpaque_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsFunctionHandle_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsObject_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsComplex_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsSparse_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsDouble_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsSingle_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsInt8_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsUint8_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsInt16_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsUint16_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsInt32_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsUint32_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsInt64_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsUint64_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
size_t mxGetNumberOfElements_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxChar * mxGetChars_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxGetUserBits_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetUserBits_800_proxy(mxArray *a0, int a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
double mxGetScalar_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsFromGlobalWS_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetFromGlobalWS_800_proxy(mxArray *a0, bool a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetM_800_proxy(mxArray *a0, mwSize a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
size_t mxGetN_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsEmpty_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxGetFieldNumber_800_proxy(const mxArray *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetIr_800_proxy(mxArray *a0, mwIndex *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetJc_800_proxy(mxArray *a0, mwIndex *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
double * mxGetPr_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetPr_800_proxy(mxArray *a0, double *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
size_t mxGetElementSize_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mwIndex mxCalcSingleSubscript_800_proxy(const mxArray *a0, mwSize a1, 
    const mwIndex *a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxGetNumberOfFields_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetCell_800_proxy(mxArray *a0, mwIndex a1, mxArray *a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetFieldByNumber_800_proxy(mxArray *a0, mwIndex a1, int a2, 
    mxArray *a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxGetField_800_proxy(const mxArray *a0, mwIndex a1, 
    const char *a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetField_800_proxy(mxArray *a0, mwIndex a1, const char *a2, 
    mxArray *a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsClass_800_proxy(const mxArray *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateNumericMatrix_800_proxy(mwSize a0, mwSize a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateUninitNumericMatrix_800_proxy(size_t a0, size_t a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateUninitNumericArray_800_proxy(size_t a0, size_t *a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxSetN_800_proxy(mxArray *a0, mwSize a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetDimensions_800_proxy(mxArray *a0, const mwSize *a1, mwSize a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxDestroyArray_800_proxy(mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateNumericArray_800_proxy(mwSize a0, const mwSize *a1, 
    mxClassID a2, mxComplexity a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateCharArray_800_proxy(mwSize a0, const mwSize *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateDoubleMatrix_800_proxy(mwSize a0, mwSize a1, 
    mxComplexity a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxLogical * mxGetLogicals_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateLogicalArray_800_proxy(mwSize a0, const mwSize *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateLogicalMatrix_800_proxy(mwSize a0, mwSize a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateLogicalScalar_800_proxy(bool a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsLogicalScalar_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsLogicalScalarTrue_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateDoubleScalar_800_proxy(double a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateSparse_800_proxy(mwSize a0, mwSize a1, mwSize a2, 
    mxComplexity a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateSparseLogicalMatrix_800_proxy(mwSize a0, mwSize a1, 
    mwSize a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxGetNChars_800_proxy(const mxArray *a0, char *a1, mwSize a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxGetString_800_proxy(const mxArray *a0, char *a1, mwSize a2);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
char * mxArrayToString_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
char * mxArrayToUTF8String_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateStringFromNChars_800_proxy(const char *a0, mwSize a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateString_800_proxy(const char *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateCharMatrixFromStrings_800_proxy(mwSize a0, 
    const char **a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateCellMatrix_800_proxy(mwSize a0, mwSize a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateCellArray_800_proxy(mwSize a0, const mwSize *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateStructMatrix_800_proxy(mwSize a0, mwSize a1, int a2, 
    const char **a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxCreateStructArray_800_proxy(mwSize a0, const mwSize *a1, 
    int a2, const char **a3);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxArray * mxDuplicateArray_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetClassName_800_proxy(mxArray *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxAddField_800_proxy(mxArray *a0, const char *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
void mxRemoveField_800_proxy(mxArray *a0, int a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
double mxGetEps_800_proxy();
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
double mxGetInf_800_proxy();
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
double mxGetNaN_800_proxy();
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsFinite_800_proxy(double a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsInf_800_proxy(double a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
bool mxIsNaN_800_proxy(double a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxDouble * mxGetDoubles_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetDoubles_800_proxy(mxArray *a0, mxDouble *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexDouble * mxGetComplexDoubles_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexDoubles_800_proxy(mxArray *a0, mxComplexDouble *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxSingle * mxGetSingles_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetSingles_800_proxy(mxArray *a0, mxSingle *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexSingle * mxGetComplexSingles_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexSingles_800_proxy(mxArray *a0, mxComplexSingle *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxInt8 * mxGetInt8s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetInt8s_800_proxy(mxArray *a0, mxInt8 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexInt8 * mxGetComplexInt8s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexInt8s_800_proxy(mxArray *a0, mxComplexInt8 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxUint8 * mxGetUint8s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetUint8s_800_proxy(mxArray *a0, mxUint8 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexUint8 * mxGetComplexUint8s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexUint8s_800_proxy(mxArray *a0, mxComplexUint8 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxInt16 * mxGetInt16s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetInt16s_800_proxy(mxArray *a0, mxInt16 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexInt16 * mxGetComplexInt16s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexInt16s_800_proxy(mxArray *a0, mxComplexInt16 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxUint16 * mxGetUint16s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetUint16s_800_proxy(mxArray *a0, mxUint16 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexUint16 * mxGetComplexUint16s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexUint16s_800_proxy(mxArray *a0, mxComplexUint16 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxInt32 * mxGetInt32s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetInt32s_800_proxy(mxArray *a0, mxInt32 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexInt32 * mxGetComplexInt32s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexInt32s_800_proxy(mxArray *a0, mxComplexInt32 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxUint32 * mxGetUint32s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetUint32s_800_proxy(mxArray *a0, mxUint32 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexUint32 * mxGetComplexUint32s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexUint32s_800_proxy(mxArray *a0, mxComplexUint32 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxInt64 * mxGetInt64s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetInt64s_800_proxy(mxArray *a0, mxInt64 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexInt64 * mxGetComplexInt64s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexInt64s_800_proxy(mxArray *a0, mxComplexInt64 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxUint64 * mxGetUint64s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetUint64s_800_proxy(mxArray *a0, mxUint64 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
mxComplexUint64 * mxGetComplexUint64s_800_proxy(const mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxSetComplexUint64s_800_proxy(mxArray *a0, mxComplexUint64 *a1);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxMakeArrayReal_800_proxy(mxArray *a0);
#endif

#if TARGET_API_VERSION >= 800
EXTERN_C
int mxMakeArrayComplex_800_proxy(mxArray *a0);
#endif



#ifdef __cplusplus
extern "C"
{
#endif

/* Standard proxy prolog. Undefine any preprocessor definitions associated
 * with the functions we are proxying, so that we can define a new one. We
 * map the user-called name to the new, internal name.
 */
#ifdef mxGetClassName
#undef mxGetClassName
#endif
#define mxGetClassName mxGetClassNameDeployed

#ifdef mxGetProperty
#undef mxGetProperty
#endif
#define mxGetProperty mxGetPropertyDeployed

#ifdef mxSetProperty
#undef mxSetProperty
#endif
#define mxSetProperty mxSetPropertyDeployed


/* Use EXTERN_C on these declarations because they are not seen when building
 * the proxy layer. User client code includes the publish header. Therefore
 * the symbols should be declared appropriately for import rather than export.
 */
#if !defined(MW_BUILD_ARCHIVES)
EXTERN_C
const char * mxGetClassNameDeployed(mxArray const * const data);

EXTERN_C
mxArray *mxGetPropertyDeployed(const mxArray *obj, mwIndex index,
                               const char *propName);

EXTERN_C
void mxSetPropertyDeployed(mxArray *obj, mwIndex index,
                           const char *propName, const mxArray *propValue);

#endif

#ifdef __cplusplus
}
#endif



#endif /* mclmcrrt_h */
