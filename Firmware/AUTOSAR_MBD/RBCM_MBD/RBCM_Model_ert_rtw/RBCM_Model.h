/*
 * File: RBCM_Model.h
 *
 * Code generated for Simulink model 'RBCM_Model'.
 *
 * Model version                   : 1.79
 * Simulink Coder version          : 23.2 (R2023b) 01-Aug-2023
 * MBDT for S32K3 Series Version  :  Version 1.6.0 (R2021a-R2024b) 27-Jan-2025
 * C/C++ source code generated on  : Tue Jun 17 17:55:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RBCM_Model_h_
#define RTW_HEADER_RBCM_Model_h_
#ifndef RBCM_Model_COMMON_INCLUDES_
#define RBCM_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Adc.h"
#include "string.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "freemaster.h"
#include "sys_init.h"
#include "freemaster_s32k3xx_lpuart.h"
#include "Lpuart_Uart_Ip_HwAccess.h"
#include "mbdt_lpuart.h"
#endif                                 /* RBCM_Model_COMMON_INCLUDES_ */

#include "RBCM_Model_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T Adc;                        /* '<S1>/Adc' */
  uint32_T Adc2;                       /* '<S1>/Adc2' */
  uint32_T Adc4;                       /* '<S1>/Adc4' */
  uint16_T DataStoreRead[6];           /* '<S1>/Data Store Read' */
  uint16_T DataStoreRead1[3];          /* '<S1>/Data Store Read1' */
  uint16_T DataStoreRead2[5];          /* '<S1>/Data Store Read2' */
  uint8_T Can;                         /* '<S1>/Can' */
} B_RBCM_Model_T;

/* Parameters (default storage) */
struct P_RBCM_Model_T_ {
  uint32_T Adc_P1;                     /* Expression: funcParam
                                        * Referenced by: '<S1>/Adc'
                                        */
  uint32_T Adc2_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S1>/Adc2'
                                        */
  uint32_T Adc4_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S1>/Adc4'
                                        */
  uint32_T Can_P1;                     /* Expression: funcParams
                                        * Referenced by: '<S1>/Can'
                                        */
  uint32_T Dio11_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio11'
                                        */
  uint32_T Dio12_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio12'
                                        */
  uint32_T Dio13_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio13'
                                        */
  uint32_T Dio14_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio14'
                                        */
  uint32_T Dio15_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio15'
                                        */
  uint32_T Dio3_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio3'
                                        */
  uint32_T Dio4_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio4'
                                        */
  uint32_T Dio5_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio5'
                                        */
  uint32_T Dio6_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio6'
                                        */
  uint32_T Dio7_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio7'
                                        */
  uint32_T Dio8_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio8'
                                        */
  uint32_T Dio9_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio9'
                                        */
  uint32_T Adc1_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S1>/Adc1'
                                        */
  uint32_T Adc3_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S1>/Adc3'
                                        */
  uint32_T Adc5_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S1>/Adc5'
                                        */
  uint32_T Can1_P1;                    /* Expression: funcParams
                                        * Referenced by: '<S1>/Can1'
                                        */
  uint32_T Can2_P1;                    /* Expression: funcParams
                                        * Referenced by: '<S1>/Can2'
                                        */
  uint32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  uint16_T DataStoreMemory4_InitialValue[2];
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  uint16_T DataStoreMemory5_InitialValue[6];
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  uint16_T DataStoreMemory6_InitialValue[5];
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  uint16_T DataStoreMemory1_InitialValue[6];
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint16_T DataStoreMemory7_InitialValue[3];
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  uint16_T DataStoreMemory8_InitialValue[5];
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  uint8_T Constant11_Value;            /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S1>/Constant11'
                                        */
  uint8_T Constant12_Value;            /* Computed Parameter: Constant12_Value
                                        * Referenced by: '<S1>/Constant12'
                                        */
  uint8_T Constant13_Value;            /* Computed Parameter: Constant13_Value
                                        * Referenced by: '<S1>/Constant13'
                                        */
  uint8_T Constant14_Value;            /* Computed Parameter: Constant14_Value
                                        * Referenced by: '<S1>/Constant14'
                                        */
  uint8_T Constant15_Value;            /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S1>/Constant15'
                                        */
  uint8_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S1>/Constant4'
                                        */
  uint8_T Constant5_Value;             /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S1>/Constant5'
                                        */
  uint8_T Constant6_Value;             /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S1>/Constant6'
                                        */
  uint8_T Constant7_Value;             /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S1>/Constant7'
                                        */
  uint8_T Constant8_Value;             /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S1>/Constant8'
                                        */
  uint8_T Constant9_Value;             /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S1>/Constant9'
                                        */
  uint8_T RGBLED0state_InitialValue[3];
                                /* Computed Parameter: RGBLED0state_InitialValue
                                 * Referenced by: '<Root>/RGBLED0state'
                                 */
};

/* Real-time Model Data Structure */
struct tag_RTM_RBCM_Model_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_RBCM_Model_T RBCM_Model_P;

/* Block signals (default storage) */
extern B_RBCM_Model_T RBCM_Model_B;

/* Model entry point functions */
extern void RBCM_Model_initialize(void);
extern void RBCM_Model_step(void);
extern void RBCM_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RBCM_Model_T *const RBCM_Model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant10' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RBCM_Model'
 * '<S1>'   : 'RBCM_Model/Subsystem'
 */
#endif                                 /* RTW_HEADER_RBCM_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
