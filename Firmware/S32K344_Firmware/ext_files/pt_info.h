/*
 * Copyright 1994-2014 The MathWorks, Inc.
 *
 * File: pt_info.h     
 *
 * Abstract:
 *   Parameter tuning information.  For details about these structures
 *   see MATLAB/rtw/c/src/pt_readme.txt.
 */

#ifndef __PT_INFO__
#define __PT_INFO__

#include "rtwtypes.h"

typedef enum {
    rt_SCALAR,
    rt_VECTOR,
    rt_MATRIX_ROW_MAJOR,
    rt_MATRIX_COL_MAJOR,
    rt_MATRIX_COL_MAJOR_ND
} ParamClass;

typedef enum {
    rt_SL_PARAM,
    rt_SF_PARAM,
    rt_SHARED_PARAM
} ParamSource;

typedef struct ParameterTuning_tag {
    ParamClass  paramClass;   /* Class of parameter               */
    int_T       nRows;        /* Number of rows                   */
    int_T       nCols;        /* Number of columns                */
    int_T       nDims;        /* Number of dimensions             */
    int_T       dimsOffset;   /* Offset into dimensions vector    */
    ParamSource source;       /* Source of parameter              */
    uint_T      dataType;     /* data type enumeration            */
    uint_T      numInstances; /* Number of parameter instances    */
    int_T       mapOffset;    /* Offset into map vector           */
} ParameterTuning;

typedef struct BlockTuning_tag {
    const char_T      *blockName;   /* Block name                       */
    const char_T      *paramName;   /* Parameter name                   */
    ParameterTuning    ptRec;       /* Parameter tuning record          */
} BlockTuning;

typedef struct VariableTuning_tag {
    const char_T *varName;    /* Variable name                    */
    ParameterTuning ptRec;    /* Parameter tuning record          */
} VariableTuning;

#define ptinfoGetClass(pt)            (pt)->paramClass
#define ptinfoGetNumRows(pt)          (pt)->nRows
#define ptinfoGetNumCols(pt)          (pt)->nCols
#define ptinfoGetNumDimensions(pt)    (pt)->nDims
#define ptinfoGetSource(pt)           (pt)->source
#define ptinfoGetDataTypeEnum(pt)     (pt)->dataType
#define ptinfoGetNumInstances(pt)     (pt)->numInstances
#define ptinfoGetParametersOffset(pt) (pt)->mapOffset
#define ptinfoGetDimensionsOffset(pt) (pt)->dimsOffset

#endif  /* __PT_INFO__ */
