#ifndef RTSPLNTYPES_H
#define RTSPLNTYPES_H

/* 
 * File: rtsplntypes.h
 * 
 * Abstract: 
 *
 *   Typedefs for spline lookup table algorithms.
 *
 *   Copyright 1994-2007 The MathWorks, Inc.
 *
 *
 */

#include "rtwtypes.h"

/***************************************************************
 *                n-D Table Work Data Structures               *
 ***************************************************************/

typedef struct rt_LUTnWork_tag 
{
    const uint32_T *m_dimSizes;
    void           *m_tableData;
    void           **m_bpDataSet;
    uint32_T       *m_bpIndex;
    void           *m_bpLambda;
    const uint32_T *m_maxIndex;
} rt_LUTnWork;

typedef struct rt_LUTSplineWork_tag 
{
    rt_LUTnWork    *m_TWork;
    void           *m_yyA;
    void           *m_yyB;
    void           *m_yy2;
    void           *m_up;
    void           *m_y2;
    const uint32_T *m_numYWorkElts;
    uint8_T        *m_reCalc; 
    void           *m_preBp0AndTable;
} rt_LUTSplineWork;

#endif  /* RTSPLNTYPES_H */
