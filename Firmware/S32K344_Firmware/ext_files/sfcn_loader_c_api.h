/* \file sfcn_loader_c_api.h */
/* The C API for dynamic mex s-function loading and mex file management */

/* Copyright 2017-2021 The MathWorks, Inc. */

#ifndef SFCN_LOADER_C_API_H
#define SFCN_LOADER_C_API_H

#ifndef DLL_EXPORT_SYM
#ifdef SL_INTERNAL
#include "package.h"
#else
#define DLL_EXPORT_SYM
#endif
#endif

#ifdef __cplusplus
#define SL_SFCN_LOADER_EXPORT_EXTERN_C extern "C" DLL_EXPORT_SYM
#include <cstdarg>
#else
#define SL_SFCN_LOADER_EXPORT_EXTERN_C extern DLL_EXPORT_SYM
#include <stdarg.h>
#endif

#ifdef BUILDING_LIBMWSL_SFCN_LOADER
#include "simstruct/simstruc.h"
#else
#include "simstruc.h"
#endif

#include "matrix.h"



/*******************************************************************************/
/* for calling mexFunction */
typedef struct MexArgs_T {
    int nlhs;
    mxArray** plhs;
    int nrhs;
    const mxArray** prhs;
} MexArgs;


/*******************************************************************************/
/* s-function parameter information */
typedef struct ParameterInfo_T {
    bool isString;
} ParameterInfo;


/*******************************************************************************/
/* ports */
typedef int_T (*SetRegNumPortsFcn)(void*, int_T);

typedef struct PortInfoFcns_T {
    SetRegNumPortsFcn setRegNumInputPorts;
    SetRegNumPortsFcn setRegNumOutputPorts;
} PortInfoFcns;


/*******************************************************************************/
/* data type access */

typedef DTypeId (*DTARegisterDataTypeFcn)(void* v, const char_T* c1, const char_T* c2);

typedef int_T (*DTAGetNumDataTypesFcn)(void* v);

typedef DTypeId (*DTAGetDataTypeIdFcn)(void* v, const char_T* c);

typedef int_T (*DTAGetGenericDTAIntPropFcn)(void* v,
                                            const char_T* c,
                                            DTypeId d,
                                            GenDTAIntPropType g);

typedef int_T (
    *DTASetGenericDTAIntPropFcn)(void*, const char_T*, DTypeId, int_T, GenDTAIntPropType);

typedef const void* (*DTAGetGenericDTAVoidPropFcn)(void* v,
                                                   const char_T* c1,
                                                   DTypeId d,
                                                   GenDTAVoidPropType g);

typedef int_T (*DTASetGenericDTAVoidPropFcn)(void* v1,
                                             const char_T* c1,
                                             DTypeId d,
                                             const void* v2,
                                             GenDTAVoidPropType g);

typedef GenericDTAUnaryFcn (*DTAGetGenericDTAUnaryFcnGWFcn)(void* v,
                                                            const char_T* c1,
                                                            DTypeId d,
                                                            GenDTAUnaryFcnType g);

typedef int_T (*DTASetGenericDTAUnaryFcnGWFcn)(void* v,
                                               const char_T* c1,
                                               DTypeId d,
                                               GenericDTAUnaryFcn f,
                                               GenDTAUnaryFcnType g);

typedef GenericDTABinaryFcn (*DTAGetGenericDTABinaryFcnGWFcn)(void* v,
                                                              const char_T* c1,
                                                              DTypeId d,
                                                              GenDTABinaryFcnType g);

typedef int_T (*DTASetGenericDTABinaryFcnGWFcn)(void* v,
                                                const char_T* c1,
                                                DTypeId d,
                                                GenericDTABinaryFcn f,
                                                GenDTABinaryFcnType g);

typedef ConvertBetweenFcn (*DTAGetConvertBetweenFcnFcn)(void* v, const char_T* c1, DTypeId d);

typedef int_T (*DTASetConvertBetweenFcnFcn)(void* v,
                                            const char_T* c1,
                                            DTypeId d,
                                            ConvertBetweenFcn f);

typedef int_T (*DTAGetGenericDTADiagnosticFcn)(void* v,
                                               const char_T* c1,
                                               GenDTADiagnosticType g,
                                               BDErrorValue* b);

typedef void* (*DTARegisterDataTypeWithCheckFcn)(void* v,
                                                 const char_T* c1,
                                                 const char_T* c2,
                                                 DTypeId* d);

typedef int_T (*DTAGetGenericDTAIntElemPropFcn)(void* v,
                                                const char_T* c1,
                                                DTypeId d,
                                                int_T i,
                                                GenDTAIntElemPropType g);

typedef int_T (*DTASetGenericDTAIntElemPropFcn)(void* v,
                                                const char_T* c1,
                                                DTypeId d,
                                                int_T i,
                                                int_T j,
                                                GenDTAIntElemPropType g);

typedef const void* (*DTAGetGenericDTAVoidElemPropFcn)(void* v,
                                                       const char_T* c1,
                                                       DTypeId d,
                                                       int_T i,
                                                       GenDTAVoidElemPropType g);

typedef int_T (*DTASetGenericDTAVoidElemPropFcn)(void* v1,
                                                 const char_T* c1,
                                                 DTypeId d,
                                                 int_T i,
                                                 const void* v2,
                                                 GenDTAVoidElemPropType g);

typedef real_T (*DTAGetGenericDTARealElemPropFcn)(void* v,
                                                  const char_T* c1,
                                                  DTypeId d,
                                                  int_T i,
                                                  GenDTARealElemPropType g);

typedef int_T (*DTASetGenericDTARealElemPropFcn)(void* v,
                                                 const char_T* c1,
                                                 DTypeId d,
                                                 int_T i,
                                                 int_T j,
                                                 GenDTARealElemPropType g);

typedef struct DataTypeAccessFcns_T {
    DTARegisterDataTypeFcn registerDataType;
    DTAGetNumDataTypesFcn getNumDataTypes;
    DTAGetDataTypeIdFcn getDataTypeId;
    DTAGetGenericDTAIntPropFcn getGenericDTAIntProp;
    DTASetGenericDTAIntPropFcn setGenericDTAIntProp;
    DTAGetGenericDTAVoidPropFcn getGenericDTAVoidProp;
    DTASetGenericDTAVoidPropFcn setGenericDTAVoidProp;
    DTAGetGenericDTAUnaryFcnGWFcn getGenericDTAUnaryFcnGW;
    DTASetGenericDTAUnaryFcnGWFcn setGenericDTAUnaryFcnGW;
    DTAGetGenericDTABinaryFcnGWFcn getGenericDTABinaryFcnGW;
    DTASetGenericDTABinaryFcnGWFcn setGenericDTABinaryFcnGW;
    DTAGetConvertBetweenFcnFcn getConvertBetweenFcn;
    DTASetConvertBetweenFcnFcn setConvertBetweenFcn;
    DTAGetGenericDTADiagnosticFcn getGenericDTADiagnostic;
    DTARegisterDataTypeWithCheckFcn registerDataTypeWithCheck;
    DTAGetGenericDTAIntElemPropFcn getGenericDTAIntElemProp;
    DTASetGenericDTAIntElemPropFcn setGenericDTAIntElemProp;
    DTAGetGenericDTAVoidElemPropFcn getGenericDTAVoidElemProp;
    DTASetGenericDTAVoidElemPropFcn setGenericDTAVoidElemProp;
    DTAGetGenericDTARealElemPropFcn getGenericDTARealElemProp;
    DTASetGenericDTARealElemPropFcn setGenericDTARealElemProp;
} DataTypeAccessFcns;


/*******************************************************************************/
/* generic function */
typedef int_T (*GenericFcn)(SimStruct*, GenFcnType, int_T, void*);


/*******************************************************************************/
/* register data type */

typedef DTypeId (*RDTRegisterFcnFcn)(void* v, const char* c);

typedef int_T (*RDTSetDataTypeSizeFcn)(void* v, DTypeId d, int_T i);

typedef int_T (*RDTGetDataTypeSizeFcn)(void* v, DTypeId d);

typedef int_T (*RDTSetDataTypeZeroFcn)(void* v1, DTypeId d, void* v2);

typedef const void* (*RDTGetDataTypeZeroFcn)(void* v, DTypeId d);

typedef const char_T* (*RDTGetDataTypeNameFcn)(void* v, DTypeId d);

typedef DTypeId (*RDTGetDataTypeIdFcn)(void* v, const char_T* c);

typedef int_T (*RDTSetNumDWorkFcnFcn)(SimStruct* s, int_T i);

typedef struct RegisterDataTypeFcns_T {
    RDTRegisterFcnFcn registerFcn;
    RDTSetDataTypeSizeFcn setDataTypeSize;
    RDTGetDataTypeSizeFcn getDataTypeSize;
    RDTSetDataTypeZeroFcn setDataTypeZero;
    RDTGetDataTypeZeroFcn getDataTypeZero;
    RDTGetDataTypeNameFcn getDataTypeName;
    RDTGetDataTypeIdFcn getDataTypeId;
    RDTSetNumDWorkFcnFcn setNumDWorkFcn;
} RegisterDataTypeFcns;


/*******************************************************************************/
/* mex API */
typedef bool (*MexIsLockedFcn)(void);

typedef int (*MexPutVarFcn)(const char*, const char*, const mxArray*);

typedef const mxArray* (*MexGetVarPtrFcn)(const char*, const char*);

typedef mxArray* (*MexGetVarFcn)(const char*, const char*);

typedef void (*MexLockFcn)(void);

typedef void (*MexUnlockFcn)(void);

typedef const char* (*MexFunctionNameFcn)(void);

typedef int (*MexEvalStringFcn)(const char*);

typedef mxArray* (*MexEvalStringWithTrapFcn)(const char*);

typedef int (*MexSetFcn)(double, const char*, mxArray*);

typedef const mxArray* (*MexGetFcn)(double, const char*);

typedef int (*MexCallMatlabFcn)(int, mxArray* plhs[], int, mxArray* prhs[], const char*, bool);

typedef mxArray* (
    *MexCallMatlabWithTrapFcn)(int, mxArray* plhs[], int, mxArray* prhs[], const char*);

typedef mxArray* (*MexCreateSimpleFunctionHandleFcn)(mxFunctionPtr f);

typedef int (*MexAtExitFcn)(void (*exitFcn)(void));

typedef void (*MexErrMsgIdAndTxtFcn)(const char*, const char*, va_list);

typedef void (*MexErrMsgTxtFcn)(const char*);

typedef void (*MexWarnMsgTxtFcn)(const char*);

typedef void (*MexWarnMsgIdAndTxtFcn)(const char*, const char*, va_list);

typedef bool (*MexSetMexTrapFlagFcn)(void);

typedef struct MexCallbacks_T {
    MexIsLockedFcn isLocked_;
    MexPutVarFcn putVar_;
    MexGetVarPtrFcn getVarPtr_;
    MexGetVarFcn getVar_;
    MexLockFcn lock_;
    MexUnlockFcn unlock_;
    MexFunctionNameFcn functionName_;
    MexEvalStringFcn evalString_;
    MexEvalStringWithTrapFcn evalStringWithTrap_;
    MexSetFcn set_;
    MexGetFcn get_;
    MexCallMatlabFcn mexCallMatlab_;
    MexCallMatlabWithTrapFcn mexCallMatlabWithTrap_;
    MexCreateSimpleFunctionHandleFcn createSimpleFunctionHandle_;
    MexAtExitFcn atExit_;
    MexErrMsgIdAndTxtFcn errMsgIdAndTxt_;
    MexErrMsgTxtFcn errMsgTxt_;
    MexWarnMsgTxtFcn warnMsgTxt_;
    MexWarnMsgIdAndTxtFcn warnMsgIdAndTxt_;
    MexSetMexTrapFlagFcn setMexTrapFlag_;
} MexCallbacks;


/*******************************************************************************/
/* C API */
SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_initialize_for_rapid_accelerator(
    const char** gblErrorStatusPtr,
    const char* const sFcnInfoFileName,
    const MexCallbacks* const mexCallbacks,
    const PortInfoFcns* const portInfoFcns,
    const DataTypeAccessFcns* const dataTypeAccessFcns,
    const GenericFcn* const genericFcn,
    const RegisterDataTypeFcns* const registerDataTypeFcns);

SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_callSFcn(const char* const sFcnName,
                                                        const char* const blockSID,
                                                        SimStruct* simstruct);

SL_SFCN_LOADER_EXPORT_EXTERN_C size_t sfcnLoader_numSFcnBlocks();

SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_interleavedComplexHandler_noTID(
    SimStruct* simstruct,
    void (*sfcnMethodPtr)(SimStruct*));

SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_interleavedComplexHandler_withTID(
    SimStruct* simstruct,
    void (*sfcnMethodPtr)(SimStruct*, int),
    int tid);

SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_setCurrentSFcnBlockSID(const char* const blockSID);

SL_SFCN_LOADER_EXPORT_EXTERN_C const char* sfcnLoader_getCurrentSFcnName();

SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_separateComplexHandler(
    SimStruct* simstruct,
    void (*const sfcnMethod)(SimStruct*));

SL_SFCN_LOADER_EXPORT_EXTERN_C void sfcnLoader_separateComplexHandler_withTID(
    SimStruct* simstruct,
    void (*const sfcnMethod)(SimStruct*, int),
    int tid);
#endif
