/*
 * File: RBCM_Model.c
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

#include "RBCM_Model.h"
#include "rtwtypes.h"
#include "RBCM_Model_private.h"

/* Block signals (default storage) */
B_RBCM_Model_T RBCM_Model_B;

/* Real-time model */
static RT_MODEL_RBCM_Model_T RBCM_Model_M_;
RT_MODEL_RBCM_Model_T *const RBCM_Model_M = &RBCM_Model_M_;
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
void RBCM_Model_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void RBCM_Model_initialize(void)
{
  {
    int32_T i;

    /* Start for S-Function (s32k3_fm_config): '<Root>/FreeMASTER Config' */
    init_freemaster_lpuart();
    FMSTR_Init();

    /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
    for (i = 0; i < 6; i++) {
      /* DataStoreRead: '<S1>/Data Store Read' incorporates:
       *  DataStoreMemory: '<Root>/Data Store Memory1'
       */
      RBCM_Model_B.DataStoreRead[i] =
        RBCM_Model_P.DataStoreMemory1_InitialValue[i];
    }

    /* S-Function (s32k3_adc): '<S1>/Adc' */
    RBCM_Model_B.Adc = Adc_SetupResultBuffer(Adc0Group_1,
      &RBCM_Model_B.DataStoreRead[0]);
    Adc0Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead[0];
    Adc0Group_1_ResultBufferLength = 6;

    /* DataStoreRead: '<S1>/Data Store Read1' incorporates:
     *  DataStoreMemory: '<Root>/Data Store Memory7'
     */
    RBCM_Model_B.DataStoreRead1[0] = RBCM_Model_P.DataStoreMemory7_InitialValue
      [0];
    RBCM_Model_B.DataStoreRead1[1] = RBCM_Model_P.DataStoreMemory7_InitialValue
      [1];
    RBCM_Model_B.DataStoreRead1[2] = RBCM_Model_P.DataStoreMemory7_InitialValue
      [2];

    /* S-Function (s32k3_adc): '<S1>/Adc2' */
    RBCM_Model_B.Adc2 = Adc_SetupResultBuffer(Adc1Group_1,
      &RBCM_Model_B.DataStoreRead1[0]);
    Adc1Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead1[0];
    Adc1Group_1_ResultBufferLength = 3;
    for (i = 0; i < 5; i++) {
      /* DataStoreRead: '<S1>/Data Store Read2' incorporates:
       *  DataStoreMemory: '<Root>/Data Store Memory8'
       */
      RBCM_Model_B.DataStoreRead2[i] =
        RBCM_Model_P.DataStoreMemory8_InitialValue[i];
    }

    /* S-Function (s32k3_adc): '<S1>/Adc4' */
    RBCM_Model_B.Adc4 = Adc_SetupResultBuffer(Adc2Group_1,
      &RBCM_Model_B.DataStoreRead2[0]);
    Adc2Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead2[0];
    Adc2Group_1_ResultBufferLength = 5;

    /* S-Function (s32k3_can): '<S1>/Can' */
    RBCM_Model_B.Can = Can_43_FLEXCAN_SetControllerMode
      (Can_43_FLEXCANConf_CanController_CanController_0, CAN_CS_STARTED);

    /* S-Function (s32k3_dio): '<S1>/Dio11' incorporates:
     *  Constant: '<S1>/Constant11'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant11_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio12' incorporates:
     *  Constant: '<S1>/Constant12'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant12_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio13' incorporates:
     *  Constant: '<S1>/Constant13'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant13_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio14' incorporates:
     *  Constant: '<S1>/Constant14'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant14_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio15' incorporates:
     *  Constant: '<S1>/Constant15'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant15_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio3' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant3_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio4' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant4_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio5' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant5_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio6' incorporates:
     *  Constant: '<S1>/Constant6'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant6_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio7' incorporates:
     *  Constant: '<S1>/Constant7'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant7_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio8' incorporates:
     *  Constant: '<S1>/Constant8'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant8_Value);

    /* S-Function (s32k3_dio): '<S1>/Dio9' incorporates:
     *  Constant: '<S1>/Constant9'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant9_Value);

    /* S-Function (s32k3_adc): '<S1>/Adc1' */
    Adc_EnableGroupNotification(Adc0Group_1);

    /* S-Function (s32k3_adc): '<S1>/Adc3' */
    Adc_EnableGroupNotification(Adc1Group_1);

    /* S-Function (s32k3_adc): '<S1>/Adc5' */
    Adc_EnableGroupNotification(Adc2Group_1);

    /* S-Function (s32k3_can): '<S1>/Can1' */
    Can_43_FLEXCAN_DisableControllerInterrupts
      (Can_43_FLEXCANConf_CanController_CanController_0);

    /* S-Function (s32k3_can): '<S1>/Can2' */
    Can_43_FLEXCAN_EnableControllerInterrupts
      (Can_43_FLEXCANConf_CanController_CanController_0);

    /* End of Outputs for SubSystem: '<Root>/Subsystem' */
  }
}

/* Model terminate function */
void RBCM_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
