/*
 * Copyright 1994-2014 The MathWorks, Inc.
 *
 * File: mdl_info.h     
 *
 * Abstract:
 *   Model tuning information.  Use the provided structure access methods
 *   whenever possible.
 *
 *   For details about these structures see MATLAB/rtw/c/src/pt_readme.txt
 *   and the Real-Time Workshop User's guide.
 */

#ifndef __MDL_INFO__
#define __MDL_INFO__

#include <pt_info.h>
#include <bio_sig.h>

typedef struct ModelMappingInfo_tag {
  /* block signal monitoring */
  struct {
    BlockIOSignals const *blockIOSignals;    /* Block signals map             */
    uint_T               numBlockIOSignals;  /* Num signals in map            */
  } Signals;

  /* parameter tuning */
  struct {
    BlockTuning const    *blockTuning;       /* Block parameters map          */
    VariableTuning const *variableTuning;    /* Variable parameters map       */
    void * const         *parametersMap;     /* Parameter index map           */
    uint_T const         *dimensionsMap;     /* Dimensions index map          */
    uint_T                numBlockTuning;    /* Num block parameters in map   */
    uint_T                numVariableTuning; /* Num variable parameter in map */
  } Parameters;
} ModelMappingInfo;

#define mmiGetBlockIOSignals(MMI)    (MMI)->Signals.blockIOSignals
#define mmiGetNumBlockIOSignals(MMI) (MMI)->Signals.numBlockIOSignals

#define mmiGetBlockTuning(MMI)       (MMI)->Parameters.blockTuning
#define mmiGetVariableTuning(MMI)    (MMI)->Parameters.variableTuning
#define mmiGetParametersMap(MMI)     (MMI)->Parameters.parametersMap
#define mmiGetDimensionsMap(MMI)     (MMI)->Parameters.dimensionsMap
#define mmiGetNumBlockParams(MMI)    (MMI)->Parameters.numBlockTuning
#define mmiGetNumVariableParams(MMI) (MMI)->Parameters.numVariableTuning

#define mmiGetBlockTuningBlockName(MMI,i)  (MMI)->Parameters.blockTuning[i].blockName
#define mmiGetBlockTuningParamName(MMI,i)  (MMI)->Parameters.blockTuning[i].paramName
#define mmiGetBlockTuningParamInfo(MMI,i)  (&((MMI)->Parameters.blockTuning[i].ptRec))

#define mmiGetVariableTuningVarName(MMI,i) (MMI)->Parameters.variableTuning[i].varName
#define mmiGetVariableTuningVarInfo(MMI,i) (&((MMI)->Parameters.variableTuning[i].ptRec))

#endif  /* __MDL_INFO__ */
