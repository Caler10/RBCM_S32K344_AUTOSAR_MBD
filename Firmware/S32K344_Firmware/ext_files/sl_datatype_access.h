/* Copyright 2009-2021 The MathWorks, Inc. */
#ifndef __SL_DATATYPE_ACCESS__
#define __SL_DATATYPE_ACCESS__

#ifndef _DATA_TYPE_ACCESS
#define _DATA_TYPE_ACCESS
/*
 * Use incomplete type for function prototypes within DataTypeAccess itself
 */
typedef struct _slDataTypeAccess_tag slDataTypeAccess;
typedef struct _slDataTypeAccess64_tag slDataTypeAccess64;
#endif

#include "sl_types_def.h"    /* DTypeId */
#include "sl_report_types.h" /*BDErrorValue*/

#define INVALID_DTYPE_ID (-10)
#define INVALID_DTYPE_SIZE (-1)
#define INVALID_DTYPE_SIGNED (-1)
#define INVALID_NUM_DTYPES (-1)


typedef enum {
    GEN_DTA_INT_PROP_SIZE,
    GEN_DTA_INT_PROP_STORAGE_ID,
    GEN_DTA_INT_PROP_ID_ALIASED_THRU_TO,
    GEN_DTA_INT_PROP_PROPERTIES_SIZE,
    GEN_DTA_INT_PROP_ID_ALIASED_TO,
    GEN_DTA_INT_PROP_NUM_ELEMENTS,
    GEN_DTA_INT_PROP_IS_BUS,
    GEN_DTA_INT_PROP_IS_ENUMTYPE,
    GEN_DTA_INT_PROP_ENUMTYPE_NUMSTRINGS,
    GEN_DTA_INT_PROP_ENUMTYPE_INDEX_OF_DEFAULT,
    GEN_DTA_INT_PROP_ENUMTYPE_ADD_TYPENAME_AS_PREFIX,
    GEN_DTA_INT_PROP_IS_BUS_WITH_VARDIMS_ELEMENT,
    GEN_DTA_INT_PROP_VARDIMS_SIZE,
    GEN_DTA_INT_PROP_CONTAINED_DATA_DATA_TYPE_ID,
    GEN_DTA_INT_PROP_CONTAINED_DATA_NUM_DIMS
} GenDTAIntPropType;

typedef enum {
    GEN_DTA_INT_PROP_ELEMENT_DATA_TYPE,
    GEN_DTA_INT_PROP_ELEMENT_SIGNAL_TYPE,
    GEN_DTA_INT_PROP_ELEMENT_NUM_DIMENSIONS,
    GEN_DTA_INT_PROP_ELEMENT_OFFSET,
    GEN_DTA_INT_PROP_ENUMTYPE_INDEX_FROM_VALUE,
    GEN_DTA_INT_PROP_ENUMTYPE_VALUE_FROM_INDEX,
    GEN_DTA_INT_PROP_ELEMENT_DIMENSIONS_MODE,
    GEN_DTA_INT_PROP_ELEMENT_VARDIMS_OFFSET,
    GEN_DTA_INT_PROP_ELEMENT_UNIT_ID
} GenDTAIntElemPropType;

typedef enum {
    GEN_DTA_VOID_PROP_NAME,
    GEN_DTA_VOID_PROP_ZERO,
    GEN_DTA_VOID_PROP_PROPERTIES,
    GEN_DTA_VOID_PROP_OBJECT,
    GEN_DTA_VOID_PROP_CGTYPE
} GenDTAVoidPropType;

typedef enum {
    GEN_DTA_VOID_PROP_ELEMENT_NAME,
    GEN_DTA_VOID_PROP_ELEMENT_DIMENSIONS,
    GEN_DTA_VOID_PROP_ENUMTYPE_STRING_FROM_VALUE,
    GEN_DTA_VOID_PROP_ENUMTYPE_STRING_FROM_INDEX,
    GEN_DTA_VOID_PROP_ELEMENT_DIMENSIONS_64
} GenDTAVoidElemPropType;

typedef enum {
    GEN_DTA_REAL_PROP_ELEMENT_MIN,
    GEN_DTA_REAL_PROP_ELEMENT_MAX
} GenDTARealElemPropType;

typedef enum { GEN_DTA_UNARY_FCN_IS_POSITIVE, GEN_DTA_UNARY_FCN_IS_NEGATIVE } GenDTAUnaryFcnType;

typedef enum {
    GEN_DTA_BINARY_FCN_GREATER_THAN,
    GEN_DTA_BINARY_FCN_GREATER_EQUAL
} GenDTABinaryFcnType;

typedef enum {
    GEN_DTA_DATA_OVERFLOW,
    GEN_DTA_INT32_TO_FLOAT,
    GEN_DTA_PARAMETER_OVERFLOW,
    GEN_DTA_PARAMETER_PRECISION_LOSS,
    GEN_DTA_PARAMETER_DOWNCAST,
    GEN_DTA_PARAMETER_UNDERFLOW,
    GEN_DTA_DATA_SATURATION
} GenDTADiagnosticType;

typedef void* (*RegisterDataTypeWithCheck)(void*, const char_T*, const char_T*, DTypeId*);

typedef DTypeId (*RegisterDataType)(void*, const char_T*, const char_T*);

typedef int_T (*GetNumDataTypes)(void*);

typedef DTypeId (*GetDataTypeId)(void*, const char_T*);

typedef int_T (*GetGenericDTAIntProp)(void*, const char_T*, DTypeId, GenDTAIntPropType);
typedef int_T (*SetGenericDTAIntProp)(void*, const char_T*, DTypeId, int_T, GenDTAIntPropType);
typedef int_T (
    *GetGenericDTAIntElemProp)(void*, const char_T*, DTypeId, int_T, GenDTAIntElemPropType);
typedef int_T (
    *SetGenericDTAIntElemProp)(void*, const char_T*, DTypeId, int_T, int_T, GenDTAIntElemPropType);
typedef real_T (
    *GetGenericDTARealElemProp)(void*, const char_T*, DTypeId, int_T, GenDTARealElemPropType);
typedef int_T (*SetGenericDTARealElemProp)(void*,
                                           const char_T*,
                                           DTypeId,
                                           int_T,
                                           int_T,
                                           GenDTARealElemPropType);

typedef const void* (*GetGenericDTAVoidProp)(void*, const char_T*, DTypeId, GenDTAVoidPropType);
typedef int_T (
    *SetGenericDTAVoidProp)(void*, const char_T*, DTypeId, const void*, GenDTAVoidPropType);
typedef const void* (
    *GetGenericDTAVoidElemProp)(void*, const char_T*, DTypeId, int_T, GenDTAVoidElemPropType);
typedef int_T (*SetGenericDTAVoidElemProp)(void*,
                                           const char_T*,
                                           DTypeId,
                                           int_T,
                                           const void*,
                                           GenDTAVoidElemPropType);

typedef int_T (*ConvertBetweenFcn)(slDataTypeAccess*,
                                   const char_T*,
                                   DTypeId,
                                   DTypeId,
                                   int_T,
                                   const void*,
                                   const void*,
                                   void*);
typedef ConvertBetweenFcn (*GetConvertBetweenFcn)(void*, const char_T*, DTypeId);
typedef int_T (*SetConvertBetweenFcn)(void*, const char_T*, DTypeId, ConvertBetweenFcn);

typedef int_T (*ConstructFcn)(void*, const void*);
typedef ConstructFcn (*GetConstructFcn)(void*, const char_T*, DTypeId);
typedef int_T (*SetConstructFcn)(void*, const char_T*, DTypeId, ConstructFcn);

typedef int_T (*DestructFcn)(void*);
typedef DestructFcn (*GetDestructFcn)(void*, const char_T*, DTypeId);
typedef int_T (*SetDestructFcn)(void*, const char_T*, DTypeId, DestructFcn);

typedef int_T (*DeepCopyFcn)(void*, const void*);
typedef DeepCopyFcn (*GetDeepCopyFcn)(void*, const char_T*, DTypeId);
typedef int_T (*SetDeepCopyFcn)(void*, const char_T*, DTypeId, DeepCopyFcn);

typedef size_t (*SizeOfFcn)(void);
typedef SizeOfFcn (*GetSizeOfFcn)(void*, DTypeId);
typedef int_T (*SetSizeOfFcn)(void*, DTypeId, SizeOfFcn);

typedef void* (*ContainedDataFcn)(void*);
typedef ContainedDataFcn (*GetContainedDataFcn)(void*, DTypeId);
typedef int_T (*SetContainedDataFcn)(void*, DTypeId, ContainedDataFcn);

typedef void (*ContainedDataDimsFcn)(const void*, size_t*);
typedef ContainedDataDimsFcn (*GetContainedDataDimsFcn)(void*, DTypeId);
typedef int_T (*SetContainedDataDimsFcn)(void*, DTypeId, ContainedDataDimsFcn);

typedef void (*UpdateContainedDataDimsFcn)(size_t, const size_t*, size_t, void*);
typedef UpdateContainedDataDimsFcn (*GetUpdateContainedDataDimsFcn)(void*, DTypeId);
typedef int_T (*SetUpdateContainedDataDimsFcn)(void*, DTypeId, UpdateContainedDataDimsFcn);

typedef void (*UpdateContainedDataDimFcn)(size_t, SLSize, void*);
typedef UpdateContainedDataDimFcn (*GetUpdateContainedDataDimFcn)(void*, DTypeId);
typedef int_T (*SetUpdateContainedDataDimFcn)(void*, DTypeId, UpdateContainedDataDimFcn);

typedef const char* (*CoderPropertiesFcn)(const void*);
typedef CoderPropertiesFcn (*GetCoderPropertiesFcn)(void*, DTypeId);
typedef int_T (*SetCoderPropertiesFcn)(void*, DTypeId, CoderPropertiesFcn);

typedef int_T (*DataConstructFcn)(size_t, const size_t*, size_t, const void*, void*);
typedef DataConstructFcn (*GetDataConstructFcn)(void*, DTypeId);
typedef int_T (*SetDataConstructFcn)(void*, DTypeId, DataConstructFcn);


typedef int_T (*SerializeFcn)(void*, const void*, size_t, size_t);
typedef SerializeFcn (*GetSerializeFcn)(void*, DTypeId);
typedef int_T (*SetSerializeFcn)(void*, DTypeId, SerializeFcn);

typedef int_T (*DeserializeFcn)(void*, const void*, size_t, size_t);
typedef DeserializeFcn (*GetDeserializeFcn)(void*, DTypeId);
typedef int_T (*SetDeserializeFcn)(void*, DTypeId, DeserializeFcn);

typedef size_t (*SerializeSizeFcn)(const void*);
typedef SerializeSizeFcn (*GetSerializeSizeFcn)(void*, DTypeId);
typedef int_T (*SetSerializeSizeFcn)(void*, DTypeId, SerializeSizeFcn);

typedef int_T (*GenericDTAUnaryFcn)(slDataTypeAccess*,
                                    const char_T*,
                                    DTypeId,
                                    int_T,
                                    const void*,
                                    const void*,
                                    void*);
typedef GenericDTAUnaryFcn (*GetGenericDTAUnaryFcnGW)(void*,
                                                      const char_T*,
                                                      DTypeId,
                                                      GenDTAUnaryFcnType);
typedef int_T (*SetGenericDTAUnaryFcnGW)(void*,
                                         const char_T*,
                                         DTypeId,
                                         GenericDTAUnaryFcn,
                                         GenDTAUnaryFcnType);
typedef int_T (*GenericDTAUnaryFcnGW)(slDataTypeAccess*,
                                      DTypeId,
                                      int_T,
                                      const void*,
                                      const void*,
                                      void*,
                                      GenDTAUnaryFcnType);


typedef int_T (*GenericDTABinaryFcn)(slDataTypeAccess*,
                                     const char_T*,
                                     DTypeId,
                                     int_T,
                                     const void*,
                                     const void*,
                                     const void*,
                                     void*);
typedef GenericDTABinaryFcn (*GetGenericDTABinaryFcnGW)(void*,
                                                        const char_T*,
                                                        DTypeId,
                                                        GenDTABinaryFcnType);
typedef int_T (*SetGenericDTABinaryFcnGW)(void*,
                                          const char_T*,
                                          DTypeId,
                                          GenericDTABinaryFcn,
                                          GenDTABinaryFcnType);
typedef int_T (*GenericDTABinaryFcnGW)(slDataTypeAccess*,
                                       DTypeId,
                                       int_T,
                                       const void*,
                                       const void*,
                                       const void*,
                                       void*,
                                       GenDTABinaryFcnType);

typedef int_T (*GetGenericDTADiagnostic)(void*, const char_T*, GenDTADiagnosticType, BDErrorValue*);
#ifdef INT64_T
typedef const void* (
    *GetGenericDTAVoidElemProp64)(void*, const char_T*, DTypeId, int64_T, GenDTAVoidElemPropType);
typedef int_T (*SetGenericDTAVoidElemProp64)(void*,
                                             const char_T*,
                                             DTypeId,
                                             int64_T,
                                             const void*,
                                             GenDTAVoidElemPropType);

typedef int_T (
    *GetGenericDTAIntElemProp64)(void*, const char_T*, DTypeId, int64_T, GenDTAIntElemPropType);
typedef int_T (*SetGenericDTAIntElemProp64)(void*,
                                            const char_T*,
                                            DTypeId,
                                            int64_T,
                                            int_T,
                                            GenDTAIntElemPropType);
typedef real_T (
    *GetGenericDTARealElemProp64)(void*, const char_T*, DTypeId, int64_T, GenDTARealElemPropType);
typedef int_T (*SetGenericDTARealElemProp64)(void*,
                                             const char_T*,
                                             DTypeId,
                                             int64_T,
                                             int_T,
                                             GenDTARealElemPropType);
#else
typedef const void* (
    *GetGenericDTAVoidElemProp64)(void*, const char_T*, DTypeId, int_T, GenDTAVoidElemPropType);
typedef int_T (*SetGenericDTAVoidElemProp64)(void*,
                                             const char_T*,
                                             DTypeId,
                                             int_T,
                                             const void*,
                                             GenDTAVoidElemPropType);

typedef int_T (
    *GetGenericDTAIntElemProp64)(void*, const char_T*, DTypeId, int_T, GenDTAIntElemPropType);
typedef int_T (*SetGenericDTAIntElemProp64)(void*,
                                            const char_T*,
                                            DTypeId,
                                            int_T,
                                            int_T,
                                            GenDTAIntElemPropType);
typedef real_T (
    *GetGenericDTARealElemProp64)(void*, const char_T*, DTypeId, int_T, GenDTARealElemPropType);
typedef int_T (*SetGenericDTARealElemProp64)(void*,
                                             const char_T*,
                                             DTypeId,
                                             int_T,
                                             int_T,
                                             GenDTARealElemPropType);
#endif
struct _slDataTypeAccess64_tag {

    GetGenericDTAIntElemProp64 getGenericDTAIntElemProp;
    SetGenericDTAIntElemProp64 setGenericDTAIntElemProp;

    GetGenericDTAVoidElemProp64 getGenericDTAVoidElemProp;
    SetGenericDTAVoidElemProp64 setGenericDTAVoidElemProp;

    GetGenericDTARealElemProp64 getGenericDTARealElemProp;
    SetGenericDTARealElemProp64 setGenericDTARealElemProp;
};

struct _slDataTypeAccess_tag {
    void* dataTypeTable;

    const char_T* errorString;

    RegisterDataType registerFcn;

    GetNumDataTypes getNumDataTypesFcn;

    GetDataTypeId getIdFcn;

    GetGenericDTAIntProp getGenericDTAIntProp;
    SetGenericDTAIntProp setGenericDTAIntProp;

    GetGenericDTAVoidProp getGenericDTAVoidProp;
    SetGenericDTAVoidProp setGenericDTAVoidProp;

    GetGenericDTAUnaryFcnGW getGenericDTAUnaryFcnGW;
    SetGenericDTAUnaryFcnGW setGenericDTAUnaryFcnGW;

    GetGenericDTABinaryFcnGW getGenericDTABinaryFcnGW;
    SetGenericDTABinaryFcnGW setGenericDTABinaryFcnGW;

    GetConvertBetweenFcn getConvertBetweenFcn;
    SetConvertBetweenFcn setConvertBetweenFcn;

    GetGenericDTADiagnostic getGenericDTADiagnostic;

    RegisterDataTypeWithCheck registerFcnWithCheck;

    GetGenericDTAIntElemProp getGenericDTAIntElemProp;
    SetGenericDTAIntElemProp setGenericDTAIntElemProp;

    GetGenericDTAVoidElemProp getGenericDTAVoidElemProp;
    SetGenericDTAVoidElemProp setGenericDTAVoidElemProp;

    GetGenericDTARealElemProp getGenericDTARealElemProp;
    SetGenericDTARealElemProp setGenericDTARealElemProp;

    GetConstructFcn getConstructFcn;
    SetConstructFcn setConstructFcn;

    GetDestructFcn getDestructFcn;
    SetDestructFcn setDestructFcn;

    GetDeepCopyFcn getDeepCopyFcn;
    SetDeepCopyFcn setDeepCopyFcn;

    GetSizeOfFcn getSizeOfFcn;
    SetSizeOfFcn setSizeOfFcn;

    GetContainedDataFcn getContainedDataFcn;
    SetContainedDataFcn setContainedDataFcn;

    GetContainedDataDimsFcn getContainedDataDimsFcn;
    SetContainedDataDimsFcn setContainedDataDimsFcn;

    GetUpdateContainedDataDimsFcn getUpdateContainedDataDimsFcn;
    SetUpdateContainedDataDimsFcn setUpdateContainedDataDimsFcn;

    GetUpdateContainedDataDimFcn getUpdateContainedDataDimFcn;
    SetUpdateContainedDataDimFcn setUpdateContainedDataDimFcn;

    GetCoderPropertiesFcn getCoderPropertiesFcn;
    SetCoderPropertiesFcn setCoderPropertiesFcn;

    GetDataConstructFcn getDataConstructFcn;
    SetDataConstructFcn setDataConstructFcn;

    GetSerializeFcn getSerializeFcn;
    SetSerializeFcn setSerializeFcn;

    GetDeserializeFcn getDeserializeFcn;
    SetDeserializeFcn setDeserializeFcn;

    GetSerializeSizeFcn getSerializeSizeFcn;
    SetSerializeSizeFcn setSerializeSizeFcn;

    struct _slDataTypeAccess64_tag* access64;
};

#endif
