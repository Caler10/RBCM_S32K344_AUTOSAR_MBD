/*
 * File: S32K344_LED.h
 *
 * Code generated for Simulink model 'S32K344_LED'.
 *
 * Model version                   : 1.4
 * Simulink Coder version          : 23.2 (R2023b) 01-Aug-2023
 * MBDT for S32K3xx Series Version :  Version 1.5.0 (R2021a-R2024a) 08-Jun-2024
 * C/C++ source code generated on  : Tue Jan 21 23:00:20 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_S32K344_LED_h_
#define RTW_HEADER_S32K344_LED_h_
#ifndef S32K344_LED_COMMON_INCLUDES_
#define S32K344_LED_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "freemaster.h"
#include "sys_init.h"
#include "freemaster_s32k3xx_lpuart.h"
#include "Lpuart_Uart_Ip_HwAccess.h"
#include "mbdt_lpuart.h"
#endif                                 /* S32K344_LED_COMMON_INCLUDES_ */

#include "S32K344_LED_types.h"
#include "rt_zcfcn.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c33_S32K344_LED;   /* '<S2>/Chart1' */
  uint8_T is_c33_S32K344_LED;          /* '<S2>/Chart1' */
} DW_S32K344_LED_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<Root>/Subsystem' */
} PrevZCX_S32K344_LED_T;

/* Parameters (default storage) */
struct P_S32K344_LED_T_ {
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  uint32_T Dio_P1[2];                  /* Expression: funcParams
                                        * Referenced by: '<S1>/Dio'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_S32K344_LED_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_S32K344_LED_T S32K344_LED_P;

/* Block states (default storage) */
extern DW_S32K344_LED_T S32K344_LED_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_S32K344_LED_T S32K344_LED_PrevZCX;

/* Model entry point functions */
extern void S32K344_LED_initialize(void);
extern void S32K344_LED_step(void);
extern void S32K344_LED_terminate(void);

/* Real-time Model object */
extern RT_MODEL_S32K344_LED_T *const S32K344_LED_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'S32K344_LED'
 * '<S1>'   : 'S32K344_LED/Subsystem'
 * '<S2>'   : 'S32K344_LED/Subsystem7'
 * '<S3>'   : 'S32K344_LED/Subsystem7/Chart1'
 */
#endif                                 /* RTW_HEADER_S32K344_LED_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
