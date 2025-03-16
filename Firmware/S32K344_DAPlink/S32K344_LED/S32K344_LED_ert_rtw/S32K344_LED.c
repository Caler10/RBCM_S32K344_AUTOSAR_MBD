/*
 * File: S32K344_LED.c
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

#include "S32K344_LED.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S2>/Chart1' */
#define S32K344_LED_IN_A               ((uint8_T)1U)
#define S32K344_LED_IN_A1              ((uint8_T)2U)

/* Block states (default storage) */
DW_S32K344_LED_T S32K344_LED_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_S32K344_LED_T S32K344_LED_PrevZCX;

/* Real-time model */
static RT_MODEL_S32K344_LED_T S32K344_LED_M_;
RT_MODEL_S32K344_LED_T *const S32K344_LED_M = &S32K344_LED_M_;
static void init_freemaster_lpuart(void)
{
  LPUART_Type * const uart_base = Lpuart_apBases[6];
  Lpuart_Uart_Ip_Hw_Init(uart_base);
  LPUART_Uart_SetBaudRate(6, 115200U);

  /* Set 8 bit counts per char */
  Lpuart_Uart_Ip_SetBitCountPerChar(uart_base, LPUART_UART_IP_8_BITS_PER_CHAR,
    FALSE);

  /* Set no parity mode */
  Lpuart_Uart_Ip_SetParityMode(uart_base, LPUART_UART_IP_PARITY_DISABLED);

  /* One stop bit */
  Lpuart_Uart_Ip_SetStopBitCount(uart_base, LPUART_UART_IP_ONE_STOP_BIT);
  sys_disableIsrSource(Lpuart_RxTxIrqId[6]);
  sys_registerIsrHandler(Lpuart_RxTxIrqId[6], (uint32) &FMSTR_SerialIsr);
  sys_enableIsrSource(Lpuart_RxTxIrqId[6], 5U);
}

/* Model step function */
void S32K344_LED_step(void)
{
  real_T tmp;
  ZCEventType zcEvent;

  /* S-Function (fcgen): '<Root>/1000ms3' incorporates:
   *  SubSystem: '<Root>/Subsystem7'
   */
  /* Chart: '<S2>/Chart1' */
  if (S32K344_LED_DW.is_active_c33_S32K344_LED == 0U) {
    S32K344_LED_DW.is_active_c33_S32K344_LED = 1U;
    S32K344_LED_DW.is_c33_S32K344_LED = S32K344_LED_IN_A;
  } else if (S32K344_LED_DW.is_c33_S32K344_LED == S32K344_LED_IN_A) {
    S32K344_LED_DW.is_c33_S32K344_LED = S32K344_LED_IN_A1;
  } else {
    /* case IN_A1: */
    S32K344_LED_DW.is_c33_S32K344_LED = S32K344_LED_IN_A;
  }

  /* End of Chart: '<S2>/Chart1' */
  /* End of Outputs for S-Function (fcgen): '<Root>/1000ms3' */

  /* Step: '<Root>/Step' */
  if (((S32K344_LED_M->Timing.clockTick0) * 1.0) < S32K344_LED_P.Step_Time) {
    tmp = S32K344_LED_P.Step_Y0;
  } else {
    tmp = S32K344_LED_P.Step_YFinal;
  }

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &S32K344_LED_PrevZCX.Subsystem_Trig_ZCE,
                     (tmp));

  /* End of Step: '<Root>/Step' */
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (s32k3_dio): '<S1>/Dio' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Dio_WriteChannel(DioConf_DioChannel_PTC30, S32K344_LED_P.Constant_Value);
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  S32K344_LED_M->Timing.clockTick0++;
}

/* Model initialize function */
void S32K344_LED_initialize(void)
{
  /* Start for S-Function (s32k3_fm_config): '<Root>/FreeMASTER Config' */
  init_freemaster_lpuart();
  FMSTR_Init();
  S32K344_LED_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void S32K344_LED_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
