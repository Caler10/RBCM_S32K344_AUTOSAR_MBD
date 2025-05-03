/*
 * PUBLISHED header for emlrt, the runtime library for MATLAB Coder
 *
 * Copyright 1984-2022 The MathWorks, Inc.
 *
 */
#ifndef emlrt_h
#define emlrt_h

#if defined(_MSC_VER) || defined(__GNUC__)
#pragma once
#endif

/*
 * Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef LIBEMLRT_API
#define LIBEMLRT_API
#endif

#if defined(BUILDING_LIBEMLRT)
#include "emlrt_extern_include_begin.hpp"
#endif
#include "matrix.h"
#if defined(BUILDING_LIBEMLRT)
#include "emlrt_extern_include_end.hpp"
#endif

#include <setjmp.h>
#include <stdio.h>
#include <stdarg.h>

/* Incomplete typedef for mxGPUArray */
#ifndef MX_GPUARRAY_DEFINED
#ifdef __cplusplus
class mxGPUArray;
#else
typedef struct mxGPUArray_tag mxGPUArray;
#endif
/*lint -esym(1923,MX_GPUARRAY_DEFINED) // MACRO input cannot be converted to const variable in C*/
#define MX_GPUARRAY_DEFINED 1.0
#endif


/*
 * MATLAB INTERNAL USE ONLY :: MEX Version
 */
#define EMLRT_VERSION_R2023B 0x2023B
#define EMLRT_VERSION_INFO EMLRT_VERSION_R2023B

/*
 * MATLAB INTERNAL USE ONLY :: Thread local context type
 */
typedef void* emlrtCTX;
typedef const void* emlrtConstCTX;

/*
 * MATLAB INTERNAL USE ONLY :: MEX error function
 */
typedef void (*EmlrtErrorFunction)(const char* aIdentifier,
                                   const CHAR16_T* aMessage,
                                   emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Prototypes of OpenMP lock functions.
 */
typedef void (*EmlrtLockeeFunction)(emlrtConstCTX aTLS, void* aData);
typedef void (*EmlrtLockerFunction)(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS, void* aData);
#define emlrtCallLockeeFunction(emlrtLockeeFcnPtr, emlrtLockeeArg0, emlrtLockeeArg1) \
    emlrtLockeeFcnPtr(emlrtLockeeArg0, emlrtLockeeArg1)

/*
 * MATLAB INTERNAL USE ONLY :: Runtime message identifier
 */
typedef struct emlrtMsgIdentifier {
    const char* fIdentifier;
    const struct emlrtMsgIdentifier* fParent;
    boolean_T bParentIsCell;
} emlrtMsgIdentifier;

/*
 * MATLAB INTERNAL USE ONLY :: Runtime stack info
 */
typedef struct emlrtRSInfo {
    int32_T lineNo;
    const char* fcnName;
    const char* pathName;
} emlrtRSInfo;

/*
 * MATLAB INTERNAL USE ONLY :: Runtime call stack
 */
typedef struct emlrtStack {
    emlrtRSInfo* site;
    emlrtCTX tls;
    const struct emlrtStack* prev;
} emlrtStack;

/*
 * MATLAB INTERNAL USE ONLY :: Runtime call stack
 */
typedef struct emlrtCallStack {
    uint32_T fRTStackPointer;
    uint32_T* fRTStackSize;
} emlrtCallStack;

/*
 * MATLAB INTERNAL USE ONLY :: MEX Context
 */
typedef struct emlrtContext {
    boolean_T bFirstTime;
    boolean_T bInitialized;
    uint32_T fVersionInfo;
    EmlrtErrorFunction fErrorFunction;
    const char* fFunctionName;
    struct emlrtCallStack* fRTCallStack;
    boolean_T bDebugMode;
    uint32_T fSigWrd[4];
    void* fSigMem;
} emlrtContext;

/*
 * MATLAB INTERNAL USE ONLY :: External Mode Simulation
 */
typedef struct emlrtExternalSim {
    void* fESim;
    uint8_T* fIOBuffer;
    uint8_T* fIOBufHead;
    size_t fIOBufSize;
} emlrtExternalSim;

/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check parameters
 */
typedef struct emlrtBCInfo {
    int32_T iFirst;
    int32_T iLast;
    int32_T lineNo;
    int32_T colNo;
    const char* aName;
    const char* fName;
    const char* pName;
    int32_T checkKind;
} emlrtBCInfo;


/*
 * MATLAB INTERNAL USE ONLY :: Design range check parameters
 */
typedef struct emlrtDRCInfo {
    int32_T lineNo;
    int32_T colNo;
    const char* fName;
    const char* pName;
} emlrtDRCInfo;

/*
 * MATLAB INTERNAL USE ONLY :: Equality check parameters
 */
typedef struct emlrtECInfo {
    int32_T nDims;
    int32_T lineNo;
    int32_T colNo;
    const char* fName;
    const char* pName;
} emlrtECInfo;

/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check parameters
 */
typedef struct emlrtRTEInfo {
    int32_T lineNo;
    int32_T colNo;
    const char* fName;
    const char* pName;
} emlrtRTEInfo;

typedef emlrtRTEInfo emlrtMCInfo;

/* MATLAB INTERNAL USE ONLY :: Reference to global runtime context */
extern emlrtContext emlrtContextGlobal;

EXTERN_C LIBEMLRT_API mxArray* emlrtAllocateClassEntryPointMx(emlrtCTX aTLS, uint32_T aClassIndex);

EXTERN_C LIBEMLRT_API void* emlrtExtractClassEntryPointInstance(emlrtCTX aTLS,
                                                                uint32_T aClassIndex,
                                                                const mxArray* aClassMx);

EXTERN_C LIBEMLRT_API boolean_T emlrtIsCoderlibClassEntryPoint(emlrtCTX aTLS,
                                                               uint32_T aClassIndex,
                                                               const mxArray* aClassMx);

EXTERN_C LIBEMLRT_API void emlrtClassEntryPointAtExit(emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Dispatch to mexPrintf
 */
EXTERN_C LIBEMLRT_API int32_T emlrtMexVprintf(const char* aFmt, va_list aVargs);

/*
 * MATLAB INTERNAL USE ONLY :: Dispatch to mexPrintf
 */
EXTERN_C LIBEMLRT_API int32_T emlrtMexPrintf(emlrtConstCTX aTLS, const char* aFmt, ...);

/*
 * MATLAB INTERNAL USE ONLY :: Dispatch to snprintf
 */
EXTERN_C LIBEMLRT_API int32_T emlrtMexSnprintf(char* retString, size_t n, const char* aFmt, ...);

/*
 * MATLAB INTERNAL USE ONLY :: Query first-time sentinel
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtFirstTimeR2012b(emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray alias
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtAlias(const mxArray* in);

/*
 * MATLAB INTERNAL USE ONLY :: Create a persistent mxArray alias
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtAliasP(const mxArray* in);

/*
 * MATLAB INTERNAL USE ONLY :: Return a vector of mxArray to MATLAB
 */
EXTERN_C LIBEMLRT_API void emlrtReturnArrays(const int32_T aNlhs,
                                             mxArray* aLHS[],
                                             const mxArray* const aRHS[]);

/*
 * MATLAB INTERNAL USE ONLY :: Protect mxArray from being overwritten if necessary
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtProtectR2012b(const mxArray* pa,
                                                        int32_T,
                                                        boolean_T,
                                                        int32_T reservedNumEl);

/*
 * MATLAB INTERNAL USE ONLY :: License check
 */
EXTERN_C LIBEMLRT_API void emlrtLicenseCheckR2012b(emlrtCTX aTLS,
                                                   const char* aFeatureKey,
                                                   const int32_T b);
/*
 * MATLAB INTERNAL USE ONLY :: License check
 */
EXTERN_C LIBEMLRT_API void emlrtLicenseCheckR2022a(emlrtCTX aTLS,
                                                   const char* aMsgId,
                                                   const char* aFeatureKey,
                                                   const int32_T b);

/*
 * MATLAB INTERNAL USE ONLY :: Verify default fimath
 */
EXTERN_C LIBEMLRT_API void emlrtCheckDefaultFimathR2008b(const mxArray** ctFimath);

/*
 * MATLAB INTERNAL USE ONLY :: Clear mxArray allocation count
 */
EXTERN_C LIBEMLRT_API void emlrtClearAllocCountR2012b(emlrtCTX aTLS,
                                                      boolean_T bM,
                                                      uint32_T iL,
                                                      const char* ctDTO);

/*
 * MATLAB INTERNAL USE ONLY :: Load a specified library
 */
EXTERN_C LIBEMLRT_API int32_T emlrtLoadLibrary(const char* aFullname);

/*
 * MATLAB INTERNAL USE ONLY :: Load a specified MATLAB library
 */
EXTERN_C LIBEMLRT_API int32_T emlrtLoadMATLABLibrary(const char* aFullName);

/*
 * MATLAB INTERNAL USE ONLY :: Assign to an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtAssign(const mxArray** lhs, const mxArray* rhs);

/*
 * MATLAB INTERNAL USE ONLY :: Assign to a persistent mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtAssignP(const mxArray** lhs, const mxArray* rhs);

/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check
 */
EXTERN_C LIBEMLRT_API int32_T emlrtBoundsCheckR2012b(int32_T indexValue,
                                                     emlrtBCInfo* aInfo,
                                                     emlrtCTX aTLS);

#ifdef INT_TYPE_64_IS_SUPPORTED
/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check for int64
 */
EXTERN_C LIBEMLRT_API int64_T emlrtBoundsCheckInt64(const int64_T indexValue,
                                                    const emlrtBCInfo* const aInfo,
                                                    const emlrtCTX aTLS);
#endif

/*
 * MATLAB INTERNAL USE ONLY :: Dynamic array bounds check
 */
EXTERN_C LIBEMLRT_API int32_T emlrtDynamicBoundsCheckR2012b(int32_T indexValue,
                                                            int32_T loBound,
                                                            int32_T hiBound,
                                                            emlrtBCInfo* aInfo,
                                                            emlrtConstCTX aTLS);

#ifdef INT_TYPE_64_IS_SUPPORTED
/*
 * MATLAB INTERNAL USE ONLY :: Dynamic array bounds check for int64
 */
EXTERN_C LIBEMLRT_API int64_T emlrtDynamicBoundsCheckInt64(const int64_T indexValue,
                                                           const int32_T loBound,
                                                           const int32_T hiBound,
                                                           const emlrtBCInfo* const aInfo,
                                                           const emlrtConstCTX aTLS);
#endif

/*
 * MATLAB INTERNAL USE ONLY :: Check that the target value is within the design range.
 */
EXTERN_C LIBEMLRT_API real_T emlrtDesignRangeCheck(real_T targetValue,
                                                   real_T rangeMin,
                                                   real_T rangeMax,
                                                   emlrtDRCInfo* aInfo,
                                                   emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Perform integer multiplication, raise runtime error
 *                             if the operation overflows.
 */
EXTERN_C LIBEMLRT_API size_t emlrtSizeMulR2012b(size_t s1,
                                                size_t s2,
                                                const emlrtRTEInfo* aInfo,
                                                emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray string from a C string
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateStringR2022a(emlrtConstCTX aTLS, const char* in);

/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray string from a single char
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateString1R2022a(emlrtConstCTX aTLS, char c);

/*
 * MATLAB INTERNAL USE ONLY :: Create a struct matrix mxArray
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtCreateStructMatrix(int32_T m,
                                                       int32_T n,
                                                       int32_T nfields,
                                                       const char** field_names);

/*
 * MATLAB INTERNAL USE ONLY :: Create a class instance mxArray
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtCreateClassInstance2022a(emlrtConstCTX, const char* className);

/*
 * MATLAB INTERNAL USE ONLY :: Create a struct matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateStructArray(int32_T ndim,
                                                            const int32_T* pdim,
                                                            int32_T nfields,
                                                            const char** field_names);

/*
 * MATLAB INTERNAL USE ONLY :: Create an enum
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateEnumR2012b(emlrtConstCTX aTLS,
                                                           const char* name,
                                                           const mxArray* data);

/*
 * MATLAB INTERNAL USE ONLY :: Add a field to a struct matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateField(const mxArray* mxStruct, const char* fldName);

/*
 * MATLAB INTERNAL USE ONLY :: Check an input sparse matrix
 */
EXTERN_C LIBEMLRT_API void emlrtCheckSparse(emlrtConstCTX aTLS,
                                            const emlrtMsgIdentifier* aMsgId,
                                            const mxArray* s,
                                            const void* pDims,
                                            const boolean_T* aDynamic,
                                            int32_T aClassId,
                                            int32_T aComplexity);

/*
 * MATLAB INTERNAL USE ONLY :: Polymorphic mex utility functions
 */

EXTERN_C LIBEMLRT_API const char* emlrtGetClassName(const mxArray* pa);

EXTERN_C LIBEMLRT_API boolean_T emlrtCompareString(const char* actual, const char* expected);

EXTERN_C LIBEMLRT_API boolean_T emlrtIsComplex(const mxArray* pa);

EXTERN_C LIBEMLRT_API boolean_T emlrtIsHeterogeneous(const mxArray* pa);

EXTERN_C LIBEMLRT_API int emlrtNumCellElements(const mxArray* pa);

EXTERN_C LIBEMLRT_API mxArray* emlrtGetCellElement(const mxArray* pa, int index);

EXTERN_C LIBEMLRT_API int emlrtGetNumStructFields(const mxArray* pa);

EXTERN_C LIBEMLRT_API const char* emlrtGetStructFieldName(const mxArray* pa, int index);

EXTERN_C LIBEMLRT_API mxArray* emlrtGetStructField(const mxArray* pa, const char* fieldName);

EXTERN_C LIBEMLRT_API boolean_T emlrtIsCompatibleSize(const mxArray* pa,
                                                      const uint32_T* aSizeVec,
                                                      const boolean_T* aVardimVec,
                                                      const uint32_T sizeLength);

EXTERN_C LIBEMLRT_API boolean_T emlrtIsSparse(const mxArray* pa);
EXTERN_C LIBEMLRT_API uint32_T emlrtGetSizeLength(const mxArray* pa);
EXTERN_C LIBEMLRT_API mxArray* emlrtGetClassProperty(const mxArray* pa, const char* propertyName);

EXTERN_C LIBEMLRT_API boolean_T emlrtCompareFiType(const mxArray* aFi,
                                                   const mxArray* fiMathMx,
                                                   const mxArray* ntMx);
EXTERN_C LIBEMLRT_API boolean_T emlrtIsComplexFi(const mxArray* aFi);
EXTERN_C LIBEMLRT_API boolean_T emlrtCompareConstant(const mxArray* aConst,
                                                     const uint32_T* aCheckSum);
/*
 * MATLAB INTERNAL USE ONLY :: Check an input sparse matrix
 */

EXTERN_C LIBEMLRT_API mxArray* emlrtCreateSparse(const void* d,
                                                 const int32_T* colidx,
                                                 const int32_T* rowidx,
                                                 int32_T m,
                                                 int32_T n,
                                                 int32_T maxnz,
                                                 int32_T aClassId,
                                                 int32_T aComplexity);

/*
 * MATLAB INTERNAL USE ONLY :: Add a field to a struct matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtAddField(const mxArray* mxStruct,
                                                   const mxArray* mxField,
                                                   const char* fldName,
                                                   int32_T index);

/*
 * MATLAB INTERNAL USE ONLY :: Set the value from propValues of all properties in propNames of a
 * class instance mxArray.
 */
EXTERN_C LIBEMLRT_API void emlrtSetAllProperties(emlrtConstCTX,
                                                 const mxArray**,
                                                 int32_T index,
                                                 int32_T numberOfProperties,
                                                 const char** propertyNames,
                                                 const char** classNames,
                                                 const mxArray** propertyValues);

/*
 * MATLAB INTERNAL USE ONLY :: Get the value mxArray of all properties of a class instance mxArray.
 */
EXTERN_C LIBEMLRT_API void emlrtGetAllProperties(emlrtConstCTX,
                                                 const mxArray*,
                                                 int32_T index,
                                                 int32_T numberOfProperties,
                                                 const char** propertyNames,
                                                 const char** classNames,
                                                 const mxArray** propertyValues);

/*
 * MATLAB INTERNAL USE ONLY :: Get the redirect target MCOS instance mxArray of a redirect source
 * MCOS instance mxArray.
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtConvertInstanceToRedirectTarget(emlrtConstCTX aTLS,
                                                                          const mxArray* mxCls,
                                                                          int aIndex,
                                                                          const char* className);

/*
 * MATLAB INTERNAL USE ONLY :: Get the redirect source MCOS instance mxArray of a redirect target
 * MCOS instance mxArray.
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtConvertInstanceToRedirectSource(emlrtConstCTX aTLS,
                                                                          const mxArray* mxCls,
                                                                          int aIndex,
                                                                          const char* className);

/*
 * MATLAB INTERNAL USE ONLY :: Get a field from a struct matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtGetFieldR2017b(emlrtConstCTX aTLS,
                                                         const mxArray* mxStruct,
                                                         int32_T aIndex,
                                                         int32_T fldNumber,
                                                         const char* fldName);

/*
 * MATLAB INTERNAL USE ONLY :: Set field value in structure array, given index and field name
 */
EXTERN_C LIBEMLRT_API void emlrtSetField(mxArray* mxStruct,
                                         int32_T aIndex,
                                         const char* fldName,
                                         mxArray* mxValue);

/*
 * MATLAB INTERNAL USE ONLY :: Set field value in structure array, given index and field index
 */
EXTERN_C LIBEMLRT_API void emlrtSetFieldR2017b(const mxArray* mxStruct,
                                               int32_T aIndex,
                                               const char* fldName,
                                               const mxArray* mxValue,
                                               int32_T fldIdx);

/*
 * MATLAB INTERNAL USE ONLY :: Create a cell array
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateCellArrayR2014a(int32_T ndim, const int32_T* pdim);

/*
 * MATLAB INTERNAL USE ONLY :: Create a cell matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateCellMatrix(int32_T m, int32_T n);

/*
 * MATLAB INTERNAL USE ONLY :: Set a cell element
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtSetCell(const mxArray* mxCellArray,
                                                  int32_T aIndex,
                                                  const mxArray* mxCell);

/*
 * MATLAB INTERNAL USE ONLY :: Get a cell element
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtGetCell(emlrtConstCTX aTLS,
                                                  const emlrtMsgIdentifier* aMsgId,
                                                  const mxArray* mxCell,
                                                  int32_T aIndex);

/*
 * MATLAB INTERNAL USE ONLY :: Check if empty
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtIsEmpty(const mxArray* mxCell);

/*
 * MATLAB INTERNAL USE ONLY :: Create a numeric matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateNumericMatrix(int32_T m,
                                                              int32_T n,
                                                              int32_T classID,
                                                              int32_T nComplexFlag);

/*
 * MATLAB INTERNAL USE ONLY :: Create a numeric matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateNumericArray(int32_T ndim,
                                                             const void* pdim,
                                                             int32_T classID,
                                                             int32_T nComplexFlag);

/*
 * MATLAB INTERNAL USE ONLY :: Create a scaled numeric matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateScaledNumericArrayR2008b(int32_T ndim,
                                                                         const void* pdim,
                                                                         int32_T classID,
                                                                         int32_T nComplexFlag,
                                                                         int32_T aScale);

/*
 * MATLAB INTERNAL USE ONLY :: Create a double scalar mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateDoubleScalar(real_T in);

/*
 * MATLAB INTERNAL USE ONLY :: Create a logical matrix mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateLogicalArray(int32_T ndim, const int32_T* dims);

/*
 * MATLAB INTERNAL USE ONLY :: Create a 2-D logical matrix mxArray
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtCreateLogicalMatrix(int32_T aN, int32_T aM);

/*
 * MATLAB INTERNAL USE ONLY :: Create a logical scalar mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateLogicalScalar(boolean_T in);

/*
 * MATLAB INTERNAL USE ONLY :: Create a character array mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateCharArray(int32_T ndim, const int32_T* dims);

/*
 * MATLAB INTERNAL USE ONLY :: Create a FI mxArray from a value mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateFIR2013b(emlrtConstCTX aTLS,
                                                         const mxArray* fimath,
                                                         const mxArray* ntype,
                                                         const char* fitype,
                                                         const mxArray* fival,
                                                         const boolean_T fmIsLocal,
                                                         const boolean_T aForceComplex);

/*
 * MATLAB INTERNAL USE ONLY :: Set the dimensions of an mxArray.
 */
EXTERN_C LIBEMLRT_API int32_T emlrtSetDimensions(mxArray* aMx, const int32_T* dims, int32_T ndims);

/*
 * MATLAB INTERNAL USE ONLY :: Get the intarray from a FI mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtImportFiIntArrayR2008b(const mxArray* aFiMx);

/*
 * MATLAB INTERNAL USE ONLY :: Get the enum int32_T from an MCOS enumeration mxArray.
 */
EXTERN_C LIBEMLRT_API int32_T emlrtGetEnumElementR2009a(const mxArray* aEnum, int32_T aIndex);

/*
 * MATLAB INTERNAL USE ONLY :: Get the enum int32_T from an MCOS enumeration mxArray.
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtGetEnumUnderlyingArrayR2009a(const mxArray* aEnum);

/*
 * MATLAB INTERNAL USE ONLY :: Convert MATLAB mxArray data format to C data format
 */
EXTERN_C LIBEMLRT_API void emlrtMatlabDataToCFormat(const mxArray* inputMx,
                                                    const mxArray* cformatMx);

/*
 * MATLAB INTERNAL USE ONLY :: Convert C data format to MATLAB data format
 */
EXTERN_C LIBEMLRT_API void emlrtMatlabDataFromCFormat(const mxArray* outputMx,
                                                      const mxArray* cformatMx);

/*
 * MATLAB INTERNAL USE ONLY :: Try to coerce mxArray to provided class; return same mxArray if not
 * possible.
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCoerceToClassR2014b(const mxArray* inputMx,
                                                              const char* className);

/*
 * MATLAB INTERNAL USE ONLY :: Destroy an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtDestroyArray(const mxArray** pa);

/*
 * MATLAB INTERNAL USE ONLY :: Destroy an mxArray R2017a
 */
EXTERN_C LIBEMLRT_API void emlrtDestroyArrayR2017a(mxArray* pa);

/*
 * MATLAB INTERNAL USE ONLY :: Destroy a vector of mxArrays
 */
EXTERN_C LIBEMLRT_API void emlrtDestroyArrays(int32_T narrays, const mxArray** parrays);

/*
 * MATLAB INTERNAL USE ONLY :: Free the imaginary part of a matrix if all the imaginary elements are
 * zero
 */
EXTERN_C LIBEMLRT_API void emlrtFreeImagIfZero(const mxArray* pa);

/*
 * MATLAB INTERNAL USE ONLY :: Display an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtDisplayR2012b(const mxArray* pa,
                                              const char* name,
                                              emlrtMCInfo* aLoc,
                                              emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Double check parameters
 */
typedef struct {
    int32_T lineNo;
    int32_T colNo;
    const char* fName;
    const char* pName;
    int32_T checkKind; /* see src/cg_ir/base/Node.hpp::CG_Node_CheckEnum */
} emlrtDCInfo;

/*
 * MATLAB INTERNAL USE ONLY :: Check that d can be safely cast to int.
 */
EXTERN_C LIBEMLRT_API real_T emlrtIntegerCheckR2012b(real_T d,
                                                     emlrtDCInfo* aInfo,
                                                     emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Check that d is not NaN.
 */
EXTERN_C LIBEMLRT_API real_T emlrtNotNanCheckR2012b(real_T d,
                                                    emlrtDCInfo* aInfo,
                                                    emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Check that d >= 0.
 */
EXTERN_C LIBEMLRT_API real_T emlrtNonNegativeCheckR2012b(real_T d,
                                                         emlrtDCInfo* aInfo,
                                                         emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Check that the loop has an integer number of iterations.
 */
EXTERN_C LIBEMLRT_API void emlrtForLoopVectorCheckR2012b(real_T start,
                                                         real_T step,
                                                         real_T end,
                                                         mxClassID classID,
                                                         int32_T n,
                                                         emlrtRTEInfo* aInfo,
                                                         emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Check that the loop range is valid for code generation.
 */
EXTERN_C LIBEMLRT_API void emlrtForLoopVectorCheckR2021a(real_T start,
                                                         real_T step,
                                                         real_T end,
                                                         mxClassID classID,
                                                         int32_T n,
                                                         emlrtRTEInfo* aInfo,
                                                         emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: fetch a global variable
 */
EXTERN_C LIBEMLRT_API void emlrtPutGlobalVariable(const char* name, const mxArray* parray);

/*
 * MATLAB INTERNAL USE ONLY :: fetch a global variable
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtGetGlobalVariable(const char* name);

/*
 * MATLAB INTERNAL USE ONLY :: Call out to MATLAB to report error from MLFB/Stateflow
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtSFCallMATLABReportError(emlrtConstCTX aTLS,
                                                                  emlrtMCInfo* aLoc,
                                                                  int32_T nrhs,
                                                                  const mxArray** prhs);

/*
 * MATLAB INTERNAL USE ONLY :: Extract the C stack from emlrtConstCtx
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtExtractStack(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Call out to MATLAB
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCallMATLABR2012b(emlrtConstCTX aTLS,
                                                           int32_T nlhs,
                                                           const mxArray** plhs,
                                                           int32_T nrhs,
                                                           const mxArray** prhs,
                                                           const char* cmd,
                                                           boolean_T tmp,
                                                           emlrtMCInfo* aLoc);

/*
 * MATLAB INTERNAL USE ONLY :: malloc for MEX
 */
EXTERN_C LIBEMLRT_API void* emlrtMallocMex(size_t aSize);

/*
 * MATLAB INTERNAL USE ONLY :: calloc for MEX
 */
EXTERN_C LIBEMLRT_API void* emlrtCallocMex(size_t aNum, size_t aSize);

/*
 * MATLAB INTERNAL USE ONLY :: free for MEX
 */
EXTERN_C LIBEMLRT_API void emlrtFreeMex(void* aPtr);

/*
 * MATLAB INTERNAL USE ONLY :: malloc for EmxArrays
 */
EXTERN_C LIBEMLRT_API void* emlrtMallocEmxArray(size_t aSize);

/*
 * MATLAB INTERNAL USE ONLY :: free for EmxArrays
 */
EXTERN_C LIBEMLRT_API void emlrtFreeEmxArray(void* aPtr);

/*
 * MATLAB INTERNAL USE ONLY :: Enter a new function within a MEX call.
 */
EXTERN_C LIBEMLRT_API void emlrtHeapReferenceStackEnterFcnR2012b(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Enter a new function within a MEX call.
 */
EXTERN_C LIBEMLRT_API void emlrtHeapReferenceStackEnterFcn(void);

/*
 * MATLAB INTERNAL USE ONLY :: Leave a scope within a MEX call.
 */
EXTERN_C LIBEMLRT_API void emlrtHeapReferenceStackLeaveScope(emlrtConstCTX aTLS,
                                                             int32_T aAllocCount);

/*
 * MATLAB INTERNAL USE ONLY :: Leave a function within a MEX call.
 */
EXTERN_C LIBEMLRT_API void emlrtHeapReferenceStackLeaveFcnR2012b(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Leave a function within a MEX call.
 */
EXTERN_C LIBEMLRT_API void emlrtHeapReferenceStackLeaveFcn(void);


EXTERN_C LIBEMLRT_API void emlrtPushHeapReferenceStackR2021a(emlrtConstCTX aTLS,
                                                             bool aNeedStack,
                                                             void* aHeapReference,
                                                             void* aFreeFcn,
                                                             void* aSimStruct,
                                                             void* aJITInstance,
                                                             void* aStackData);

/*
 * MATLAB INTERNAL USE ONLY :: Push emxArray onto heap reference stack.
 */
EXTERN_C LIBEMLRT_API void emlrtPushHeapReferenceStackEmxArray(emlrtConstCTX aTLS,
                                                               bool aNeedStack,
                                                               void* aHeapReference,
                                                               void* aFreeFcn,
                                                               void* aSimStruct,
                                                               void* aJITInstance,
                                                               void* aStackData);

EXTERN_C LIBEMLRT_API void emlrtRemoveHeapReference(emlrtConstCTX aTLS, void* aHeapReference);

/*
 * MATLAB INTERNAL USE ONLY :: Push a new entry to the heap reference stack.
 */
EXTERN_C LIBEMLRT_API void emlrtSetGlobalSyncFcn(emlrtConstCTX aTLS, void* aSyncFcn);

/*
 * MATLAB INTERNAL USE ONLY :: Push a new entry to the heap reference stack.
 */
EXTERN_C LIBEMLRT_API void emlrtSetGlobalSyncFcnWithSD(emlrtConstCTX aTLS,
                                                       void* aStackData,
                                                       void* aSyncFcn);

/*
 * MATLAB INTERNAL USE ONLY :: Push a new entry to the heap reference stack.
 */
EXTERN_C LIBEMLRT_API void emlrtSetJITGlobalSyncFcn(emlrtConstCTX aTLS,
                                                    void* aJITInstance,
                                                    void* aSyncFcn);

/*
 * MATLAB INTERNAL USE ONLY :: Push a new entry to the heap reference stack.
 */
EXTERN_C LIBEMLRT_API void emlrtSetJITGlobalSyncFcnWithSD(emlrtConstCTX aTLS,
                                                          void* aJITInstance,
                                                          void* aStackData,
                                                          void* aSyncFcn);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize a character mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtInitCharArrayR2013a(emlrtConstCTX aTLS,
                                                    int32_T n,
                                                    const mxArray* a,
                                                    const char* s);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize a logical mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtInitLogicalArray(int32_T n, const mxArray* a, const boolean_T* b);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize an integral array from a multiword type
 */
EXTERN_C LIBEMLRT_API void emlrtInitIntegerArrayFromMultiword(const mxArray* aOut,
                                                              const void* aInData);

/*
 * MATLAB INTERNAL USE ONLY :: Export a numeric mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtExportNumericArrayR2013b(emlrtConstCTX aTLS,
                                                         const mxArray* aOut,
                                                         const void* aInData,
                                                         int32_T aElementSize);

/*
 * MATLAB INTERNAL USE ONLY :: Auto-generated mexFunction
 */
typedef void (*emlrtMexFunction)(int, mxArray*[], int, const mxArray*[]);

/*
 * MATLAB INTERNAL USE ONLY :: Auto-generated entry-point
 */
typedef struct emlrtEntryPoint {
    const char* fName;
    emlrtMexFunction fMethod;
} emlrtEntryPoint;

/*
 * MATLAB INTERNAL USE ONLY :: Lookup an entry point
 */
EXTERN_C LIBEMLRT_API int32_T emlrtGetEntryPointIndexR2016a(emlrtConstCTX aTLS,
                                                            int32_T nrhs,
                                                            const mxArray* prhs[],
                                                            const char* aEntryPointNames[],
                                                            int32_T aNumEntryPoints);

/*
 * MATLAB INTERNAL USE ONLY :: Decode wide character strings in mxArray struct array.
 * The struct array consists of name resolution entries which may contain file paths.
 * If the file path is using UTF-8, then the string is plain 7-bit ASCII but encoded.
 * We need to decode those if necessary. The resulting mxArray strings (for file paths)
 * will be proper UTF-16 strings.
 */
EXTERN_C LIBEMLRT_API void emlrtNameCapturePostProcessR2013b(const mxArray** mxInfo);

/*
 * MATLAB INTERNAL USE ONLY :: Decode string array into mxArray object containing
 * name resolution data.
 */
EXTERN_C LIBEMLRT_API void emlrtNameCaptureMxArrayR2016a(const char* mxInfoEncoded[],
                                                         uint32_T uncompressedSize,
                                                         const mxArray** mxInfo);

/*
 * MATLAB INTERNAL USE ONLY :: Parallel runtime error exception
 */
#ifdef __cplusplus
class EmlrtParallelRunTimeError {
  public:
    EmlrtParallelRunTimeError();
    EmlrtParallelRunTimeError(const EmlrtParallelRunTimeError& e);
    ~EmlrtParallelRunTimeError();
};
#endif

/*
 * MATLAB INTERNAL USE ONLY :: Report if we are in a parallel region
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtIsInParallelRegion(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Enter a parallel region.
 */
EXTERN_C LIBEMLRT_API void emlrtEnterParallelRegion(emlrtConstCTX aTLS,
                                                    boolean_T aInParallelRegion);

/*
 * MATLAB INTERNAL USE ONLY :: Exit a parallel region.
 */
EXTERN_C LIBEMLRT_API void emlrtExitParallelRegion(emlrtConstCTX aTLS, boolean_T aInParallelRegion);

/*
 * MATLAB INTERNAL USE ONLY :: Check if we're running on the MATLAB thread.
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtIsMATLABThread(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Record the occurrence of a parallel warning.
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtSetWarningFlag(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Report a parallel runtime error
 */
EXTERN_C LIBEMLRT_API void emlrtReportParallelRunTimeError(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Ensure active thread is MATLAB
 */
EXTERN_C LIBEMLRT_API void emlrtAssertMATLABThread(emlrtConstCTX aTLS, emlrtMCInfo* aLoc);

/*
 * MATLAB INTERNAL USE ONLY :: Push the current jmp_buf environment
 */
EXTERN_C LIBEMLRT_API void emlrtPushJmpBuf(emlrtConstCTX aTLS, jmp_buf* volatile* aJBEnviron);

/*
 * MATLAB INTERNAL USE ONLY :: Pop the current jmp_buf environment
 */
EXTERN_C LIBEMLRT_API void emlrtPopJmpBuf(emlrtConstCTX aTLS, jmp_buf* volatile* aJBEnviron);

/*
 * MATLAB INTERNAL USE ONLY :: Set the current jmp_buf environment
 */
EXTERN_C LIBEMLRT_API void emlrtSetJmpBuf(emlrtConstCTX aTLS, jmp_buf* aJBEnviron);

/*
 * MATLAB INTERNAL USE ONLY :: Get the current jmp_buf environment
 */
EXTERN_C LIBEMLRT_API jmp_buf* emlrtGetJmpBuf(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Create a shallow copy of an mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrtCreateReference(const mxArray* pa);

/*
 * MATLAB INTERNAL USE ONLY :: Division by zero error
 */
EXTERN_C LIBEMLRT_API void emlrtDivisionByZeroErrorR2012b(const emlrtRTEInfo* aInfo,
                                                          emlrtConstCTX aTLS);

EXTERN_C LIBEMLRT_API void emlrtDivisionByZeroWarningOrError2018b(const emlrtRTEInfo* aInfo,
                                                                  emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Integer overflow error
 */
EXTERN_C LIBEMLRT_API void emlrtIntegerOverflowErrorR2012b(const emlrtRTEInfo* aInfo,
                                                           emlrtConstCTX aTLS);

EXTERN_C LIBEMLRT_API void emlrtIntegerOverflowWarningOrError2018b(const emlrtRTEInfo* aInfo,
                                                                   emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Raise C heap allocation failure
 */
EXTERN_C LIBEMLRT_API void emlrtHeapAllocationErrorR2012b(const emlrtRTEInfo* aInfo,
                                                          emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Error with given message ID and args.
 */
EXTERN_C LIBEMLRT_API void emlrtErrorWithMessageIdR2018a(emlrtConstCTX aTLS,
                                                         const emlrtRTEInfo* aInfo,
                                                         const char* aMsgID,
                                                         const char* aReportID,
                                                         int aArgCount,
                                                         ...);


/*
 * MATLAB INTERNAL USE ONLY :: Error with given message ID and args.
 */
EXTERN_C LIBEMLRT_API void emlrtErrorWithMessageIdR2012b(emlrtConstCTX aTLS,
                                                         const emlrtRTEInfo* aInfo,
                                                         const char* aMsgID,
                                                         int32_T aArgCount,
                                                         ...);

/*
 * MATLAB INTERNAL USE ONLY :: Error with given message ID and args.
 */
EXTERN_C LIBEMLRT_API void emlrtErrMsgIdAndTxt(emlrtCTX aTLS,
                                               const char* aMsgID,
                                               int32_T aArgCount,
                                               ...);

/*
 * MATLAB INTERNAL USE ONLY :: Error with given message ID and explicit message text.
 */
EXTERN_C LIBEMLRT_API void emlrtErrMsgIdAndExplicitTxt(emlrtConstCTX aTLS,
                                                       const emlrtRTEInfo* aInfo,
                                                       const char* aMsgID,
                                                       int32_T aStrlen,
                                                       const char* aMsgTxt);

typedef struct {
    const char* MexFileName;
    const char* TimeStamp;
    const char* buildDir;
    int32_T numFcns;
    int32_T numHistogramBins;
} emlrtLocationLoggingFileInfoType;

typedef struct {
    const char* FunctionName;
    int32_T FunctionID;
    int32_T numInstrPoints;
} emlrtLocationLoggingFunctionInfoType;

typedef struct {
    real_T NumberOfZeros;
    real_T NumberOfPositiveValues;
    real_T NumberOfNegativeValues;
    real_T TotalNumberOfValues;
    real_T SimSum;
    real_T HistogramOfPositiveValues[256];
    real_T HistogramOfNegativeValues[256];
} emlrtLocationLoggingHistogramType;

typedef struct {
    real_T SimMin;
    real_T SimMax;
    int32_T OverflowWraps;
    int32_T Saturations;
    boolean_T IsAlwaysInteger;
    emlrtLocationLoggingHistogramType* HistogramTable;
} emlrtLocationLoggingDataType;

typedef struct {
    int32_T MxInfoID;
    int32_T TextStart;
    int32_T TextLength;
    int16_T Reason;
    boolean_T MoreLocations;
} emlrtLocationLoggingLocationType;

/*
 * MATLAB INTERNAL USE ONLY :: Get LocationLogging Info
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtLocationLoggingPullLog(const char* const MexFileName,
                                                           boolean_T pullCompReportFromMexFunction);

/*
 * MATLAB INTERNAL USE ONLY :: Save LocationLogging Info
 */
EXTERN_C LIBEMLRT_API void emlrtLocationLoggingPushLog(
    const emlrtLocationLoggingFileInfoType* const fileInfo,
    const emlrtLocationLoggingFunctionInfoType* const functionInfoTable,
    const emlrtLocationLoggingDataType* const dataTables,
    const emlrtLocationLoggingLocationType* const locationTables,
    const uint8_T* serializedReport,
    size_t sizeofSerializedReport,
    const int32_T* numFieldsTables,
    const char** fieldNamesTables);

/*
 * MATLAB INTERNAL USE ONLY :: Save LocationLogging Info
 */
EXTERN_C LIBEMLRT_API void emlrtLocationLoggingPushLogR2017a(
    const emlrtLocationLoggingFileInfoType* const fileInfo,
    const emlrtLocationLoggingFunctionInfoType* const functionInfoTable,
    const emlrtLocationLoggingDataType* const dataTables,
    const emlrtLocationLoggingLocationType* const locationTables,
    const int32_T* numFieldsTables,
    const char** fieldNamesTables,
    const char* serializedReport[],
    size_t sizeofSerializedReport);

/*
 * MATLAB INTERNAL USE ONLY :: Clear LocationLogging Info
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtLocationLoggingClearLog(const char* const MexFileName);

/*
 * MATLAB INTERNAL USE ONLY :: List entries in LocationLogging Info
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtLocationLoggingListLogs(void);

/*
 * MATLAB INTERNAL USE ONLY :: Add instrumentation results to FPT Repository
 */
EXTERN_C LIBEMLRT_API void addResultsToFPTRepository(const char* const blkSID);

/*
 * MATLAB INTERNAL USE ONLY :: Initialize a runtime stack
 */
EXTERN_C LIBEMLRT_API void emlrtEnterRtStackR2012b(emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Push to runtime stack
 */
EXTERN_C LIBEMLRT_API void emlrtPushRtStackR2012b(const struct emlrtRSInfo* aRSInfo, emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Pop from runtime stack
 */
EXTERN_C LIBEMLRT_API void emlrtPopRtStackR2012b(const struct emlrtRSInfo* aRSInfo, emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Get the address of the Ctrl-C flag.
 */
EXTERN_C LIBEMLRT_API const volatile char* emlrtGetBreakCheckFlagAddressR2022b(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Check for Ctrl+C (break)
 */
EXTERN_C LIBEMLRT_API void emlrtBreakCheckR2012b(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Issues interrupt signal to MATLAB as if by Ctrl+C
 */
EXTERN_C LIBEMLRT_API void emlrtInterruptMATLAB(void);

/*
 * MATLAB INTERNAL USE ONLY :: Equality check for 1-D sizes
 */
EXTERN_C LIBEMLRT_API void emlrtSizeEqCheck1DR2012b(int32_T dim1,
                                                    int32_T dim2,
                                                    emlrtECInfo* aInfo,
                                                    emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Equality check error for size vectors
 */
EXTERN_C LIBEMLRT_API void emlrtSizeEqCheckNDErrorR2021b(const int32_T* dims1,
                                                         const int32_T* dims2,
                                                         emlrtECInfo* aInfo,
                                                         emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Equality check for size vectors
 */
EXTERN_C LIBEMLRT_API void emlrtSizeEqCheckNDR2012b(const int32_T* dims1,
                                                    const int32_T* dims2,
                                                    emlrtECInfo* aInfo,
                                                    emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: equality check
 */
EXTERN_C LIBEMLRT_API void emlrtDimSizeEqCheckR2012b(int32_T dim1,
                                                     int32_T dim2,
                                                     emlrtECInfo* aInfo,
                                                     emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: greater than or equal to check
 */
EXTERN_C LIBEMLRT_API void emlrtDimSizeGeqCheckR2012b(int32_T dim1,
                                                      int32_T dim2,
                                                      emlrtECInfo* aInfo,
                                                      emlrtConstCTX aTLS);
/*
 * MATLAB INTERNAL USE ONLY :: equality or singleton check
 */
EXTERN_C LIBEMLRT_API void emlrtDimSizeImpxCheckR2021b(int32_T dim1,
                                                       int32_T dim2,
                                                       emlrtECInfo* aInfo,
                                                       emlrtConstCTX aTLS);
/*
 * MATLAB INTERNAL USE ONLY :: Check size compatibility for A(I1,..IN) = B assignment in MATLAB.
 */
EXTERN_C LIBEMLRT_API void emlrtSubAssignSizeCheckR2012b(const int32_T* dims1,
                                                         int32_T nDims1,
                                                         const int32_T* dims2,
                                                         int32_T nDims2,
                                                         emlrtECInfo* aInfo,
                                                         emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Check size compatibility for A(I) = B assignment in MATLAB.
 */
EXTERN_C LIBEMLRT_API void emlrtSubAssignSizeCheck1dR2017a(int32_T dim1,
                                                           int32_T dim2,
                                                           emlrtECInfo* aInfo,
                                                           emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Allocate thread-local storage.
 */
EXTERN_C LIBEMLRT_API void* emlrtAllocTLS(emlrtConstCTX aMaster, int32_T aTeamTID);

/*
 * MATLAB INTERNAL USE ONLY :: Allocate thread local storage for a parallel region.
 */
EXTERN_C LIBEMLRT_API int32_T emlrtAllocRegionTLSs(emlrtCTX aTLS,
                                                   boolean_T aInParallelRegion,
                                                   int32_T aMaxThreads,
                                                   int32_T aNumThreads);

/*
 * MATLAB INTERNAL USE ONLY :: Allocate the root thread-local storage.
 */
EXTERN_C LIBEMLRT_API void emlrtUpdateCTX(emlrtConstCTX emlrtCtx, struct emlrtContext* aContext);


/*
 * MATLAB INTERNAL USE ONLY :: Allocate the root thread-local storage.
 */
EXTERN_C LIBEMLRT_API void emlrtCreateRootTLSR2022a(
    emlrtCTX* aRootTLS,
    struct emlrtContext* aContext,
    EmlrtLockerFunction aLockerFunction,
    int32_T aNumProcs,
    void* aExceptionBridge,
    const char* aCharacterEncoding,
    boolean_T aCharacterEncodingSizeConsistencyEnabled);

/*
 * MATLAB INTERNAL USE ONLY :: Deallocate the root thread-local storage.
 */
EXTERN_C LIBEMLRT_API void emlrtDestroyRootTLS(emlrtCTX* aRootTLS);

EXTERN_C LIBEMLRT_API void emlrtSetIsInDestructor(emlrtCTX aTLS, bool aValue);

EXTERN_C LIBEMLRT_API void emlrtShouldCleanupOnError(emlrtCTX aTLS, bool aValue);

EXTERN_C LIBEMLRT_API void emlrtCleanupOnException(emlrtCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Set Jit Simulation Mode.
 */
EXTERN_C LIBEMLRT_API void emlrtSetSimThruJIT(emlrtCTX aTLS, boolean_T aSimThruJIT);

EXTERN_C LIBEMLRT_API char* emlrtExtractMessageId2015b(emlrtConstCTX aTLS,
                                                       const struct emlrtMsgIdentifier* aMsgId);

/*
 * MATLAB INTERNAL USE ONLY :: Check the class of an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckClass(const char* msgName,
                                           const mxArray* pa,
                                           const char* className);

/*
 * MATLAB INTERNAL USE ONLY :: Check the class of an mxArray pa to be exactly aClassName, otherwise
 * error out using aMsgId and aTLS.
 */
EXTERN_C LIBEMLRT_API void emlrtCheckMcosClass2017a(emlrtConstCTX aTLS,
                                                    const emlrtMsgIdentifier* aMsgId,
                                                    const mxArray* pa,
                                                    const char* aClassName);
/*
 * MATLAB INTERNAL USE ONLY :: Check the contents of two mxArrays to be equal.
 */
EXTERN_C LIBEMLRT_API void emlrtCheckCtMxArray2018b(emlrtConstCTX aTLS,
                                                    const emlrtMsgIdentifier* aMsgId,
                                                    const mxArray* rtArray,
                                                    const mxArray* ctArray);

/*
 * MATLAB INTERNAL USE ONLY :: Check the size, class and complexness of an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckBuiltInR2012b(emlrtConstCTX aTLS,
                                                   const struct emlrtMsgIdentifier* aMsgId,
                                                   const mxArray* pa,
                                                   const char* className,
                                                   boolean_T complex,
                                                   uint32_T nDims,
                                                   const void* pDims);

/*
 * MATLAB INTERNAL USE ONLY :: Check the size, class and complexness of a variable-size mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckVsBuiltInR2012b(emlrtConstCTX aTLS,
                                                     const struct emlrtMsgIdentifier* aMsgId,
                                                     const mxArray* pa,
                                                     const char* className,
                                                     boolean_T complex,
                                                     uint32_T nDims,
                                                     const void* pDims,
                                                     const boolean_T* aDynamic,
                                                     int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a FI mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckFiR2012b(emlrtConstCTX aTLS,
                                              const struct emlrtMsgIdentifier* aMsgId,
                                              const mxArray* aFi,
                                              boolean_T aComplex,
                                              uint32_T aNDims,
                                              const void* aVDims,
                                              const mxArray* aFimath,
                                              const mxArray* aNumericType);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a variable-size FI mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckVsFiR2012b(emlrtConstCTX aTLS,
                                                const struct emlrtMsgIdentifier* aMsgId,
                                                const mxArray* aFi,
                                                boolean_T aComplex,
                                                uint32_T aNDims,
                                                const void* aVDims,
                                                const boolean_T* aDynamic,
                                                const mxArray* aFimath,
                                                const mxArray* aNumericType);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a static-size struct mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckStructR2012b(emlrtConstCTX aTLS,
                                                  const emlrtMsgIdentifier* aMsgId,
                                                  const mxArray* s,
                                                  int32_T nFields,
                                                  const char** fldNames,
                                                  uint32_T nDims,
                                                  const void* pDims);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a variable-size struct mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckVsStructR2012b(emlrtConstCTX aTLS,
                                                    const struct emlrtMsgIdentifier* aMsgId,
                                                    const mxArray* s,
                                                    int32_T nFields,
                                                    const char** fldNames,
                                                    uint32_T nDims,
                                                    const void* pDims,
                                                    const boolean_T* aDynamic,
                                                    int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Check the checksum of an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckArrayChecksumR2018b(emlrtConstCTX,
                                                         mxArray const*,
                                                         boolean_T globalVar,
                                                         int const*,
                                                         const char**,
                                                         uint32_T const*);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a static-size struct mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckEnumR2012b(emlrtConstCTX aTLS,
                                                const char* enumName,
                                                int32_T nEnumElements,
                                                const char** enumNames,
                                                const int32_T* enumValues);

/*
 * MATLAB INTERNAL USE ONLY :: Import a character array.
 */
EXTERN_C LIBEMLRT_API void emlrtImportCharArrayR2015b(emlrtConstCTX aTLS,
                                                      const mxArray* aSrc,
                                                      char_T* aDst,
                                                      int32_T aNumel);

/*
 * MATLAB INTERNAL USE ONLY :: Import a character.
 */
EXTERN_C LIBEMLRT_API void emlrtImportCharR2015b(emlrtConstCTX aTLS,
                                                 const mxArray* aSrc,
                                                 char_T* aDst);

/*
 * MATLAB INTERNAL USE ONLY :: Import an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtImportArrayR2015b(emlrtConstCTX aTLS,
                                                  const mxArray* aIn,
                                                  void* aOutData,
                                                  int32_T aElementSize,
                                                  boolean_T aComplex);

/*
 * MATLAB INTERNAL USE ONLY :: Import an mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtImportArrayR2015b_SameComplex(emlrtConstCTX aTLS,
                                                              const mxArray* aIn,
                                                              void* aOutData,
                                                              int32_T aElementSize);

/*
 * MATLAB INTERNAL USE ONLY :: Import a FI mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtImportVsFiArrayR2023a(emlrtConstCTX aTLS,
                                                      const mxArray* aFiMx,
                                                      const mxArray* aIntMx,
                                                      void* aOutData,
                                                      int32_T aElementSize,
                                                      boolean_T aComplex,
                                                      uint32_T nDimsMax,
                                                      int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Set the actual sizes of a dynamic FI array
 */
EXTERN_C LIBEMLRT_API void emlrtSetVsFiSizes(const mxArray* aFi,
                                             uint32_T nDimsExpected,
                                             int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Get double uniform random values in (0,1)
 */
EXTERN_C LIBEMLRT_API void emlrtRandu(real_T* const aRanduBuffer, const int32_T aNumel);

/*
 * MATLAB INTERNAL USE ONLY :: Get double normal random values
 */
EXTERN_C LIBEMLRT_API void emlrtRandn(real_T* const aRandnBuffer, const int32_T aNumel);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a static-sized cell mxArray
 */
EXTERN_C LIBEMLRT_API void emlrtCheckCell(emlrtConstCTX aTLS,
                                          const emlrtMsgIdentifier* aMsgId,
                                          const mxArray* s,
                                          uint32_T nDims,
                                          const void* pDims,
                                          const boolean_T* aDynamic);

/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a variable-sized cell mxArray
 * and assign the size of the mxArray to aOutSizes
 */
EXTERN_C LIBEMLRT_API void emlrtCheckVsCell(emlrtConstCTX aTLS,
                                            const struct emlrtMsgIdentifier* aMsgId,
                                            const mxArray* s,
                                            uint32_T nDims,
                                            const void* pDims,
                                            const boolean_T* aDynamic,
                                            int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Check a cell mxArray with unassigned base type
 */
EXTERN_C LIBEMLRT_API void emlrtCheckCellWithUnassignedBase(emlrtConstCTX aTLS,
                                                            const struct emlrtMsgIdentifier* aMsgId,
                                                            const mxArray* pa);

/*
 * MATLAB INTERNAL USE ONLY :: Get the library path of a function pointer
 */
EXTERN_C LIBEMLRT_API const char* emlrtGetLibraryPath(const void* pFcn);

/*
 * MATLAB INTERNAL USE ONLY :: emlrt strlen function
 */
EXTERN_C LIBEMLRT_API size_t emlrtStrlen(const char*);

/*
 * MATLAB INTERNAL USE ONLY :: FFTW MEX Wrapper
 */
EXTERN_C LIBEMLRT_API void* emlrtFFTWMalloc(size_t aSize);

EXTERN_C LIBEMLRT_API void emlrtFFTWFree(void* data);

/*
 * MATLAB INTERNAL USE ONLY :: Double 1D complex to complex FFT, this function assumes in and out to
 * be interleaved complex.
 */
EXTERN_C LIBEMLRT_API void emlrtFFTW_1D_C2C(const real_T* in,
                                            real_T* out,
                                            int32_T stride,
                                            int32_T fftLen,
                                            int32_T ldx,
                                            int32_T numFFT,
                                            int32_T direction);

EXTERN_C LIBEMLRT_API void emlrtFFTW_1D_R2C(const real_T* in,
                                            real_T* out,
                                            int32_T stride,
                                            int32_T fftLen,
                                            int32_T ldx,
                                            int32_T numFFT,
                                            int32_T direction);

EXTERN_C LIBEMLRT_API void emlrtFFTW_1D_C2R(const real_T* in,
                                            real_T* out,
                                            int32_T stride,
                                            int32_T fftLen,
                                            int32_T ldx,
                                            int32_T numFFT,
                                            int32_T direction);

/*
 * MATLAB INTERNAL USE ONLY :: Float 1D complex to complex FFT, this function assumes in and out to
 * be interleaved complex.
 */
EXTERN_C LIBEMLRT_API void emlrtFFTWF_1D_C2C(const real32_T* in,
                                             real32_T* out,
                                             int32_T stride,
                                             int32_T fftLen,
                                             int32_T ldx,
                                             int32_T numFFT,
                                             int32_T direction);

EXTERN_C LIBEMLRT_API void emlrtFFTWF_1D_R2C(const real32_T* in,
                                             real32_T* out,
                                             int32_T stride,
                                             int32_T fftLen,
                                             int32_T ldx,
                                             int32_T numFFT,
                                             int32_T direction);

EXTERN_C LIBEMLRT_API void emlrtFFTWF_1D_C2R(const real32_T* in,
                                             real32_T* out,
                                             int32_T stride,
                                             int32_T fftLen,
                                             int32_T ldx,
                                             int32_T numFFT,
                                             int32_T direction);

/*
 * MATLAB INTERNAL USE ONLY :: Setter and getter for FFTW plan method.
 */
EXTERN_C LIBEMLRT_API const char* emlrtFFTWGetPlanMethod(void);

EXTERN_C LIBEMLRT_API void emlrtFFTWSetPlanMethod(const char* method);

/*
 * MATLAB INTERNAL USE ONLY :: Double FFTW plan import/export/delete.
 */
EXTERN_C LIBEMLRT_API char* emlrtFFTWExportDoublePlan(void);

EXTERN_C LIBEMLRT_API void emlrtFFTWImportDoublePlan(const char* aPlanStr);

EXTERN_C LIBEMLRT_API void emlrtFFTWForgetDoublePlan(void);

/*
 * MATLAB INTERNAL USE ONLY :: Double FFTW plan import/export/delete.
 */
EXTERN_C LIBEMLRT_API char* emlrtFFTWExportSinglePlan(void);

EXTERN_C LIBEMLRT_API void emlrtFFTWImportSinglePlan(const char* aPlanStr);

EXTERN_C LIBEMLRT_API void emlrtFFTWForgetSinglePlan(void);

/*
 * MATLAB INTERNAL USE ONLY :: Force FFTW to run with single thread or not.
 */
EXTERN_C LIBEMLRT_API void emlrtFFTWSetNumThreads(int32_T numThreads);

/*
 * MATLAB INTERNAL USE ONLY :: Check LXE profiler status
 */
EXTERN_C LIBEMLRT_API void emlrtCheckProfilerStatus();

#ifndef __cplusplus

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Function Entry
 */
EXTERN_C LIBEMLRT_API void emlrtMEXProfilingFunctionEntry(const char* fcnUniqKey,
                                                          boolean_T isMexOutdated);

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Function Exit
 */
EXTERN_C LIBEMLRT_API void emlrtMEXProfilingFunctionExit(boolean_T isMexOutdated);

#else
// Need a sentinel class to make sure call stack is correct during stack unwinding
struct LIBEMLRT_API emlrtProfilerSentinel {
    emlrtProfilerSentinel();
    ~emlrtProfilerSentinel();

    bool Initialized;
    bool AlreadyExit;

  private:
    emlrtProfilerSentinel& operator=(const emlrtProfilerSentinel&);
    emlrtProfilerSentinel(const emlrtProfilerSentinel&);
};
/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Function Entry
 */
LIBEMLRT_API void emlrtMEXProfilingFunctionEntryCPP(const char* fcnUniqKey,
                                                    boolean_T isMexOutdated,
                                                    emlrtProfilerSentinel* aSentinel);

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Function Exit
 */
LIBEMLRT_API void emlrtMEXProfilingFunctionExitCPP(emlrtProfilerSentinel* aSentinel);

#endif

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Unregister Function
 */
EXTERN_C LIBEMLRT_API void emlrtProfilerUnregisterMEXFcn(const char* fcnUniqKey,
                                                         boolean_T isMexOutdated);

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Register Function
 */
EXTERN_C LIBEMLRT_API void emlrtProfilerRegisterMEXFcn(const char* completeName,
                                                       const char* aPath,
                                                       const char* aFcnName,
                                                       int32_T numLineNos,
                                                       const int32_T* lineNos,
                                                       boolean_T isMexOutdated);

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Profile Statement
 */
EXTERN_C LIBEMLRT_API void emlrtMEXProfilingStatement(uint32_T aPoint, boolean_T isMexOutdated);

/*
 * MATLAB INTERNAL USE ONLY :: MEX Profiling Check MEX File Outdated Function
 */
EXTERN_C LIBEMLRT_API boolean_T emlrtProfilerCheckMEXOutdated(void);

/*
 * MATLAB INTERNAL USE ONLY :: Report a detected CUDA runtime error
 */
EXTERN_C LIBEMLRT_API void emlrtCUDAError(uint32_T errcode,
                                          const char* ename,
                                          const char* emsg,
                                          const emlrtRTEInfo* aInfo,
                                          emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Report a detected OpenCL runtime error
 */
EXTERN_C LIBEMLRT_API void emlrtOpenCLError(int32_T errcode,
                                            const char* ename,
                                            const char* emsg,
                                            const emlrtRTEInfo* aInfo,
                                            emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Report a detected CUDA runtime error as a warning
 * useful for capturing errors within destructors and throwing those as warnings, so that
 * MATLAB does not crash for MEX builds
 */
EXTERN_C LIBEMLRT_API void emlrtCUDAWarning(uint32_T errcode,
                                            const char* ename,
                                            const char* emsg,
                                            const emlrtRTEInfo* aInfo);
/*
 * MATLAB INTERNAL USE ONLY :: Report a detected CUDA runtime error (light API)
 */
EXTERN_C LIBEMLRT_API void emlrtThinCUDAError(uint32_T errcode,
                                              const char* ename,
                                              const char* emsg,
                                              const char* paramname,
                                              emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Wrapper of several mxArray Apis
 */
EXTERN_C LIBEMLRT_API void* emlrtMxCalloc(size_t numEl, size_t elSize);

EXTERN_C LIBEMLRT_API void emlrtMxFree(void* in);

EXTERN_C LIBEMLRT_API mxArray* emlrtMxCreateString(const char* aStr);

EXTERN_C LIBEMLRT_API mxArray* emlrtMxCreateRowVectorUINT8(const uint8_T* aArray, uint32_T aSize);

EXTERN_C LIBEMLRT_API mxArray* emlrtMxCreateDoubleScalar(double v);

EXTERN_C LIBEMLRT_API mxArray* emlrtMxCreateLogicalScalar(bool v);

EXTERN_C LIBEMLRT_API void* emlrtMxGetData(const mxArray* aMxArray);

EXTERN_C LIBEMLRT_API void emlrtMxSetData(mxArray* aMxArray, void* data);

EXTERN_C LIBEMLRT_API real_T* emlrtMxGetPr(const mxArray* aMxArray);

EXTERN_C LIBEMLRT_API boolean_T* emlrtMxGetLogicals(const mxArray* aMxArray);

EXTERN_C LIBEMLRT_API void* emlrtMxGetImagData(const mxArray* aMxArray);

EXTERN_C LIBEMLRT_API double* emlrtMxGetPi(const mxArray* aMxArray);

EXTERN_C LIBEMLRT_API const mxArray* emlrtMexGetVariablePtr(const char* workspace,
                                                            const char* varname);
/*
 * MATLAB INTERNAL USE ONLY :: Initilize mxArray from multiword fixed point
 */
EXTERN_C LIBEMLRT_API void emlrtInitMultiwordFXP(const mxArray* mxArray,
                                                 const void* inData,
                                                 int32_T scaleFactor);

/*
 *  MATLAB INTERNAL USE ONLY :: Get environment variable
 */
EXTERN_C LIBEMLRT_API char* emlrtGetEnv(const char* name);


/*
 *  MATLAB INTERNAL USE ONLY :: Get environment variable
 */
EXTERN_C LIBEMLRT_API int32_T emlrtGetEnvR2022a(const char* aEncoding,
                                                int32_T aSizeConsistencyEnabled,
                                                const char* aName,
                                                char* aValue);

/*
 *  MATLAB INTERNAL USE ONLY :: Set environment variable
 */
EXTERN_C LIBEMLRT_API int32_T emlrtSetEnvR2022a(const char* aEncoding,
                                                int32_T aSizeConsistencyEnabled,
                                                const char* aName,
                                                const char* aValue);

/*
 *  MATLAB INTERNAL USE ONLY :: Character encoding conversion
 */
EXTERN_C LIBEMLRT_API int32_T emlrtEncoding2Encoding(const char* aSrcEncoding,
                                                     const char* aDstEncoding,
                                                     int32_T aSizeConsistencyEnabled,
                                                     int32_T aInputBufferLength,
                                                     const char* aInputBuffer,
                                                     char* aOutputBuffer);


EXTERN_C LIBEMLRT_API void emlrtCaptureInputs(const mxArray** data,
                                              int32_T numInputs,
                                              void* aFcnPtr);

/*
 * MATLAB INTERNAL USE ONLY :: Create a numeric matrix mxGPUArray
 */
EXTERN_C LIBEMLRT_API mxGPUArray* emlrtGPUCreateNumericArray(const char* className,
                                                             boolean_T nComplexFlag,
                                                             int32_T ndim,
                                                             const void* pdim);

/*
 * MATLAB INTERNAL USE ONLY :: Get read only GPU device pointer from mxGpuArray
 */
EXTERN_C LIBEMLRT_API const void* emlrtGPUGetDataReadOnly(const mxGPUArray* inArray);

/*
 * MATLAB INTERNAL USE ONLY :: Get GPU device pointer from mxGpuArray
 */
EXTERN_C LIBEMLRT_API void* emlrtGPUGetData(mxGPUArray* inArray);

/*
 * MATLAB INTERNAL USE ONLY :: Get class name from class id
 */
EXTERN_C LIBEMLRT_API const char* emlrtClassIDToClassName(mxClassID classID);

/*
 * MATLAB INTERNAL USE ONLY :: Marshall input mxArray and return mxGPUArray
 */
EXTERN_C LIBEMLRT_API const mxGPUArray* emlrt_marshallInGPU(emlrtConstCTX aTLS,
                                                            const mxArray* inArray,
                                                            const char* id,
                                                            const char* className,
                                                            boolean_T nComplexFlag,
                                                            int32_T ndim,
                                                            const void* pdim,
                                                            boolean_T marshallByRef);

/*
 * MATLAB INTERNAL USE ONLY :: Marshall input mxArray and return mxGPUArray
 */
EXTERN_C LIBEMLRT_API const mxGPUArray* emlrt_marshallInGPUVardim(emlrtConstCTX aTLS,
                                                                  const mxArray* inArray,
                                                                  const char* id,
                                                                  const char* className,
                                                                  boolean_T nComplexFlag,
                                                                  int32_T ndim,
                                                                  const void* pdim,
                                                                  boolean_T marshallByRef,
                                                                  const boolean_T* aDynamic,
                                                                  int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Marshall output mxGPUArray and return mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrt_marshallOutGPU(const mxGPUArray* inArray);

/*
 * MATLAB INTERNAL USE ONLY :: Marshall output mxGPUArray and return mxArray
 */
EXTERN_C LIBEMLRT_API const mxArray* emlrt_marshallOutGPUVardim(mxGPUArray* const inArray,
                                                                const int32_T aNDims,
                                                                const int32_T* aOutSizes);

/*
 * MATLAB INTERNAL USE ONLY :: Destroy GPUArray
 */
EXTERN_C LIBEMLRT_API void emlrtDestroyGPUArray(const mxGPUArray* inArray);

/*
 * MATLAB INTERNAL USE ONLY :: Deep copy of input to protect it when modified
 */
EXTERN_C LIBEMLRT_API mxArray* emlrtProtectGPUArray(const mxArray* inArray);

/*
 * MATLAB INTERNAL USE ONLY :: Deep copy of mxGPUArray
 */
EXTERN_C LIBEMLRT_API mxGPUArray* emlrtGPUCopyGPUArray(const mxGPUArray* inArray);

/*
 * MATLAB INTERNAL USE ONLY :: Load gpu library
 */
EXTERN_C LIBEMLRT_API void emlrtInitGPU(emlrtConstCTX aTLS);

/*
 * MATLAB INTERNAL USE ONLY :: Exit Time Cleanup
 */
EXTERN_C LIBEMLRT_API void emlrtExitTimeCleanup(struct emlrtContext*);

typedef struct emlrtTimespec {
    double tv_sec;
    double tv_nsec;
} emlrtTimespec;

/*
 * MATLAB INTERNAL USE ONLY :: Get time using monotonic clock
 */
EXTERN_C LIBEMLRT_API int emlrtClockGettimeMonotonic(emlrtTimespec*);

typedef struct emlrtStructTm {
    double tm_nsec;
    double tm_sec;
    double tm_min;
    double tm_hour;
    double tm_mday;
    double tm_mon;
    double tm_year;
    boolean_T tm_isdst;
} emlrtStructTm;

/*
 * MATLAB INTERNAL USE ONLY :: Get wallclock time
 */
EXTERN_C LIBEMLRT_API void emlrtWallclock(emlrtStructTm* aStructTm);

#if defined(_WIN32) || defined(WIN32)
/*
 * MATLAB INTERNAL USE ONLY :: Wrapper for nanosleep
 */
EXTERN_C LIBEMLRT_API int emlrtSleepWin64(uint32_T aMilliSeconds);
#else
/*
 * MATLAB INTERNAL USE ONLY :: Wrapper for nanosleep
 */
EXTERN_C LIBEMLRT_API int emlrtNanosleep(const emlrtTimespec*);
#endif /* defined(_WIN32) || defined(WIN32) */

/*
 * MATLAB INTERNAL USE ONLY :: Sleep for some duration
 */
EXTERN_C LIBEMLRT_API int emlrtSleep(const emlrtTimespec* aEMLRTTimespec);

/*
 * MATLAB INTERNAL USE ONLY :: Pause for user input like pause()
 */
EXTERN_C LIBEMLRT_API void emlrtPauseForInput(void);

EXTERN_C LIBEMLRT_API mxArray* emlrtMxCPUtoGPU(const mxArray* pa);

EXTERN_C LIBEMLRT_API mxArray* emlrtMxGPUtoCPU(const mxArray* pa);

/*
 * MATLAB INTERNAL USE ONLY :: Profiling instrumentation APIs
 */
EXTERN_C LIBEMLRT_API void emlrtProfilingEnterFunction(const char* function,
                                                       uint32_T nBlocks,
                                                       uint32_T staticSize,
                                                       const char* filename,
                                                       uint32_T line);

#ifdef INT_TYPE_64_IS_SUPPORTED
EXTERN_C LIBEMLRT_API void emlrtProfilingNode(uint64_T aSequenceId,
                                              uint64_T aNodeId,
                                              uint64_T aTypeSequenceId,
                                              const char* aSid);

EXTERN_C LIBEMLRT_API void emlrtProfilingNamedNode(uint64_T aSequenceId,
                                                   uint64_T aNodeId,
                                                   uint64_T aTypeSequenceId,
                                                   const char* aSid,
                                                   const char* aName);

EXTERN_C LIBEMLRT_API void emlrtProfilingType(uint64_T aTypeSequenceId,
                                              uint64_T aTypeClassId,
                                              uint64_T aTypeInstanceId,
                                              uint64_T aTypeSize,
                                              const char* aName);

EXTERN_C LIBEMLRT_API void emlrtProfilingDMTypeDimension(uint64_T aTypeSequenceId,
                                                         uint64_T aNodeId,
                                                         uint32_T aDimension,
                                                         uint64_T aElementCount);

#endif

EXTERN_C LIBEMLRT_API void emlrtProfilingExitFunction(void);

EXTERN_C LIBEMLRT_API void emlrtProfilingStart(void);
EXTERN_C LIBEMLRT_API void emlrtProfilingSave(void);
EXTERN_C LIBEMLRT_API void emlrtProfilingFinish(void);
EXTERN_C LIBEMLRT_API void emlrtProfilingClear(void);

/*
 * MATLAB INTERNAL USE ONLY :: mxClassID for half mxArray.
 */

#ifndef mxHALF_CLASS
#define mxHALF_CLASS ((mxClassID)(-2357))
#endif

#endif /* emlrt_h */
