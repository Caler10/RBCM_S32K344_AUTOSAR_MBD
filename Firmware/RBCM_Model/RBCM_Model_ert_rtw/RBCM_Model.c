/*
 * File: RBCM_Model.c
 *
 * Code generated for Simulink model 'RBCM_Model'.
 *
 * Model version                   : 1.82
 * Simulink Coder version          : 24.2 (R2024b) 21-Jun-2024
 * MBDT for S32K3 Series Version  :  Version 1.6.0 (R2021a-R2024b) 27-Jan-2025
 * C/C++ source code generated on  : Mon Sep  1 13:57:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RBCM_Model.h"
#include "rtwtypes.h"
#include "RBCM_Model_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S13>/Chart2' */
#define RBCM_Model_IN_A                ((uint8_T)1U)
#define RBCM_Model_IN_A1               ((uint8_T)2U)
#define RBCM_Model_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)

/* Block signals (default storage) */
B_RBCM_Model_T RBCM_Model_B;

/* Block states (default storage) */
DW_RBCM_Model_T RBCM_Model_DW;

/* Real-time model */
static RT_MODEL_RBCM_Model_T RBCM_Model_M_;
RT_MODEL_RBCM_Model_T *const RBCM_Model_M = &RBCM_Model_M_;
static void rate_scheduler(void);
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

void CanIf_RxIndication (const Can_HwType* Mailbox, const PduInfoType*
  PduInfoPtr)
{

#ifdef FMSTR_TX_HWOBJ

  uint8_t fmstrResult = 0u;
  fmstrResult = FMSTR_CanIsr(Mailbox->Hoh, Mailbox->CanId, PduInfoPtr->SduLength,
    PduInfoPtr->SduDataPtr, 0u);
  if (fmstrResult) {
    return;
  }

#endif

  uint8_t i, length;
  RBCM_Model_B.Hardware_Interrupt_Handler4_o2 = Mailbox->ControllerId;
  RBCM_Model_B.Hardware_Interrupt_Handler4_o3 = Mailbox->Hoh;
  RBCM_Model_B.ID = Mailbox->CanId;
  length = PduInfoPtr->SduLength;
  if (length > 8) {
    length = 8;
  }

  for (i = 0; i < length; i++) {
    (&RBCM_Model_B.Data[0])[i] = PduInfoPtr->SduDataPtr[i];
  }

  RBCM_Model_B.Length = PduInfoPtr->SduLength;
  RBCM_Model_u_k4();
}

void Adc_Adc0Group1Notification (void)
{
  /* Output and update for function-call system: '<Root>/Subsystem1' */

  /* S-Function (s32k3_adc): '<S7>/Adc1' */
  {
    Adc_ValueGroupType* ptrToSamplePtr = NULL;
    RBCM_Model_B.Adc1_o1_l = Adc_GetStreamLastPointer(Adc0Group_1,
      &ptrToSamplePtr);
    if (RBCM_Model_B.Adc1_o1_l > 0) {
      int length = Adc0Group_1_ResultBufferLength;
      if (length > 6) {
        length = 6;
      }

      memcpy((void *) &RBCM_Model_B.Adc1_o3_l[0], (void *)
             Adc0Group_1_ResultBufferPtr, length * sizeof(Adc_ValueGroupType));
      RBCM_Model_B.Adc1_o2_cp = ptrToSamplePtr - Adc0Group_1_ResultBufferPtr + 1;
    } else {
      RBCM_Model_B.Adc1_o2_cp = 0;
    }
  }

  /* DataStoreWrite: '<S7>/Data Store Write1' */
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[1] = RBCM_Model_B.Adc1_o3_l[3];
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[3] = RBCM_Model_B.Adc1_o3_l[4];
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[4] = RBCM_Model_B.Adc1_o3_l[5];

  /* DataStoreWrite: '<S7>/Data Store Write2' */
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[0] = RBCM_Model_B.Adc1_o3_l[0];
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[1] = RBCM_Model_B.Adc1_o3_l[1];
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[4] = RBCM_Model_B.Adc1_o3_l[2];
}

void Adc_Adc1Group1Notification (void)
{
  /* Output and update for function-call system: '<Root>/Subsystem11' */

  /* S-Function (s32k3_adc): '<S9>/Adc1' */
  {
    Adc_ValueGroupType* ptrToSamplePtr = NULL;
    RBCM_Model_B.Adc1_o1_i = Adc_GetStreamLastPointer(Adc1Group_1,
      &ptrToSamplePtr);
    if (RBCM_Model_B.Adc1_o1_i > 0) {
      int length = Adc1Group_1_ResultBufferLength;
      if (length > 3) {
        length = 3;
      }

      memcpy((void *) &RBCM_Model_B.Adc1_o3_a[0], (void *)
             Adc1Group_1_ResultBufferPtr, length * sizeof(Adc_ValueGroupType));
      RBCM_Model_B.Adc1_o2_c = ptrToSamplePtr - Adc1Group_1_ResultBufferPtr + 1;
    } else {
      RBCM_Model_B.Adc1_o2_c = 0;
    }
  }

  /* DataStoreWrite: '<S9>/Data Store Write' */
  RBCM_Model_DW.Temp_AdcBuffer = RBCM_Model_B.Adc1_o3_a[0];

  /* DataStoreWrite: '<S9>/Data Store Write1' */
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[5] = RBCM_Model_B.Adc1_o3_a[2];

  /* DataStoreWrite: '<S9>/Data Store Write2' */
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[3] = RBCM_Model_B.Adc1_o3_a[1];
}

void Adc_Adc2Group1Notification (void)
{
  /* Output and update for function-call system: '<Root>/Subsystem12' */

  /* S-Function (s32k3_adc): '<S10>/Adc1' */
  {
    Adc_ValueGroupType* ptrToSamplePtr = NULL;
    RBCM_Model_B.Adc1_o1 = Adc_GetStreamLastPointer(Adc2Group_1, &ptrToSamplePtr);
    if (RBCM_Model_B.Adc1_o1 > 0) {
      int length = Adc2Group_1_ResultBufferLength;
      if (length > 5) {
        length = 5;
      }

      memcpy((void *) &RBCM_Model_B.Adc1_o3[0], (void *)
             Adc2Group_1_ResultBufferPtr, length * sizeof(Adc_ValueGroupType));
      RBCM_Model_B.Adc1_o2 = ptrToSamplePtr - Adc2Group_1_ResultBufferPtr + 1;
    } else {
      RBCM_Model_B.Adc1_o2 = 0;
    }
  }

  /* DataStoreWrite: '<S10>/Data Store Write' */
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[0] = RBCM_Model_B.Adc1_o3[1];
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[2] = RBCM_Model_B.Adc1_o3[2];

  /* DataStoreWrite: '<S10>/Data Store Write1' */
  RBCM_Model_DW.Bats_Monitor_AdcBuffer[0] = RBCM_Model_B.Adc1_o3[3];
  RBCM_Model_DW.Bats_Monitor_AdcBuffer[1] = RBCM_Model_B.Adc1_o3[4];

  /* DataStoreWrite: '<S10>/Data Store Write2' */
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[2] = RBCM_Model_B.Adc1_o3[0];
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (RBCM_Model_M->Timing.TaskCounters.TID[1])++;
  if ((RBCM_Model_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.05s, 0.0s] */
    RBCM_Model_M->Timing.TaskCounters.TID[1] = 0;
  }

  (RBCM_Model_M->Timing.TaskCounters.TID[2])++;
  if ((RBCM_Model_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [1.0s, 0.0s] */
    RBCM_Model_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S13>/Chart2'
 *    '<S17>/Chart1'
 *    '<S15>/Chart1'
 */
void RBCM_Model_Chart2_Init(boolean_T *rty_A)
{
  *rty_A = false;
}

/*
 * System reset for atomic system:
 *    '<S13>/Chart2'
 *    '<S17>/Chart1'
 *    '<S15>/Chart1'
 */
void RBCM_Model_Chart2_Reset(boolean_T *rty_A, DW_Chart2_RBCM_Model_T *localDW)
{
  *rty_A = false;
  localDW->is_active_c7_RBCM_Model = 0U;
  localDW->is_c7_RBCM_Model = RBCM_Model_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S13>/Chart2'
 *    '<S17>/Chart1'
 *    '<S15>/Chart1'
 */
void RBCM_Model_Chart2(boolean_T *rty_A, DW_Chart2_RBCM_Model_T *localDW)
{
  /* Chart: '<S13>/Chart2' */
  if (localDW->is_active_c7_RBCM_Model == 0) {
    localDW->is_active_c7_RBCM_Model = 1U;
    *rty_A = true;
    localDW->is_c7_RBCM_Model = RBCM_Model_IN_A;
  } else if (localDW->is_c7_RBCM_Model == RBCM_Model_IN_A) {
    *rty_A = false;
    localDW->is_c7_RBCM_Model = RBCM_Model_IN_A1;
  } else {
    /* case IN_A1: */
    *rty_A = true;
    localDW->is_c7_RBCM_Model = RBCM_Model_IN_A;
  }

  /* End of Chart: '<S13>/Chart2' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/数据转存单元1'
 *    '<S1>/数据转存单元10'
 *    '<S1>/数据转存单元2'
 *    '<S1>/数据转存单元4'
 *    '<S1>/数据转存单元6'
 *    '<S1>/数据转存单元8'
 */
void RBCM_Model_u(uint8_T rtu_index, uint8_T rtu_u, uint8_T *rty_y1, uint8_T
                  *rty_y2, DW_u_RBCM_Model_T *localDW)
{
  switch (rtu_index) {
   case 0U:
    localDW->Y1 = rtu_u;
    break;

   case 1U:
    localDW->Y2 = rtu_u;
    break;
  }

  *rty_y1 = localDW->Y1;
  *rty_y2 = localDW->Y2;
}

/*
 * Output and update for atomic system:
 *    '<S1>/数据转存单元11'
 *    '<S1>/数据转存单元12'
 *    '<S1>/数据转存单元3'
 *    '<S1>/数据转存单元5'
 *    '<S1>/数据转存单元7'
 *    '<S1>/数据转存单元9'
 */
void RBCM_Model_u1(uint8_T rtu_index, uint16_T rtu_u, uint16_T *rty_y1, uint16_T
                   *rty_y2, DW_u1_RBCM_Model_T *localDW)
{
  switch (rtu_index) {
   case 0U:
    localDW->Y1 = rtu_u;
    break;

   case 1U:
    localDW->Y2 = rtu_u;
    break;
  }

  *rty_y1 = localDW->Y1;
  *rty_y2 = localDW->Y2;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * System initialize for atomic system:
 *    '<S1>/触发器1'
 *    '<S1>/触发器2'
 *    '<S1>/触发器3'
 *    '<S1>/触发器4'
 *    '<S1>/触发器5'
 */
void RBCM_Model_u_a_Init(uint16_T *rty_1, P_u_RBCM_Model_e_T *localP)
{
  /* SystemInitialize for Function Call SubSystem: '<S1>/ADC采集与处理单元1' */
  /* SystemInitialize for Outport: '<S20>/u1' */
  *rty_1 = localP->u1_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/ADC采集与处理单元1' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/触发器1'
 *    '<S1>/触发器2'
 *    '<S1>/触发器3'
 *    '<S1>/触发器4'
 *    '<S1>/触发器5'
 */
void RBCM_Model_u_o(uint8_T rtu_counter, uint8_T rtu_u2, uint8_T *rty_y,
                    uint16_T *rty_1, const uint16_T rtd_lHsd_Diagnose_AdcBuffer
                    [5], DW_u_RBCM_Model_l_T *localDW, P_u_RBCM_Model_e_T
                    *localP)
{
  real_T tmp;
  real32_T tmp_0;
  localDW->i++;
  localDW->output++;
  if (localDW->i >= rtu_counter) {
    if (localDW->output >= rtu_u2) {
      localDW->output = 0.0;
    }

    tmp = rt_roundd_snf(localDW->output);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        *rty_y = (uint8_T)tmp;
      } else {
        *rty_y = 0U;
      }
    } else {
      *rty_y = MAX_uint8_T;
    }

    /* Outputs for Function Call SubSystem: '<S1>/ADC采集与处理单元1' */
    /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
     *  Constant: '<S20>/ADC resolution'
     *  Constant: '<S20>/Ris'
     *  Constant: '<S20>/Vref'
     *  DataStoreRead: '<S20>/Data Store Read'
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     *  Gain: '<S20>/Magnification'
     *  Product: '<S20>/Divide'
     *  Product: '<S20>/Product'
     *  Product: '<S20>/Product1'
     */
    tmp_0 = floorf((real32_T)rtd_lHsd_Diagnose_AdcBuffer[0] * (real32_T)
                   localP->ADCresolution_Value * (real32_T)localP->Vref_Value /
                   (real32_T)localP->Ris_Value * localP->Magnification_Gain);
    if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
      tmp_0 = 0.0F;
    } else {
      tmp_0 = fmodf(tmp_0, 65536.0F);
    }

    *rty_1 = (uint16_T)(tmp_0 < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                        -tmp_0 : (int32_T)(uint16_T)tmp_0);

    /* End of DataTypeConversion: '<S20>/Data Type Conversion1' */
    /* End of Outputs for SubSystem: '<S1>/ADC采集与处理单元1' */
    localDW->i = 0.0;
  } else {
    tmp = rt_roundd_snf(localDW->output);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        *rty_y = (uint8_T)tmp;
      } else {
        *rty_y = 0U;
      }
    } else {
      *rty_y = MAX_uint8_T;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S1>/触发器10'
 *    '<S1>/触发器11'
 *    '<S1>/触发器6'
 *    '<S1>/触发器7'
 *    '<S1>/触发器8'
 *    '<S1>/触发器9'
 */
void RBCM_Model_u0_Init(uint16_T *rty_1, P_u0_RBCM_Model_T *localP)
{
  /* SystemInitialize for Function Call SubSystem: '<S1>/ADC采集与处理单元10' */
  /* SystemInitialize for Outport: '<S21>/u' */
  *rty_1 = localP->u_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/ADC采集与处理单元10' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/触发器10'
 *    '<S1>/触发器11'
 *    '<S1>/触发器6'
 *    '<S1>/触发器7'
 *    '<S1>/触发器8'
 *    '<S1>/触发器9'
 */
void RBCM_Model_u0(uint8_T rtu_counter, uint8_T rtu_u2, uint8_T *rty_y, uint16_T
                   *rty_1, const uint16_T rtd_hHsd_Diagnose_AdcBuffer[6],
                   DW_u0_RBCM_Model_T *localDW, P_u0_RBCM_Model_T *localP)
{
  real_T tmp;
  real32_T tmp_0;
  localDW->i++;
  localDW->output++;
  if (localDW->i >= rtu_counter) {
    if (localDW->output >= rtu_u2) {
      localDW->output = 0.0;
    }

    tmp = rt_roundd_snf(localDW->output);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        *rty_y = (uint8_T)tmp;
      } else {
        *rty_y = 0U;
      }
    } else {
      *rty_y = MAX_uint8_T;
    }

    /* Outputs for Function Call SubSystem: '<S1>/ADC采集与处理单元10' */
    /* DataTypeConversion: '<S21>/Data Type Conversion1' incorporates:
     *  Constant: '<S21>/ADC resolution'
     *  Constant: '<S21>/Ris'
     *  Constant: '<S21>/Vref'
     *  DataStoreRead: '<S21>/Data Store Read'
     *  DataTypeConversion: '<S21>/Data Type Conversion'
     *  Gain: '<S21>/Magnification'
     *  Product: '<S21>/Divide'
     *  Product: '<S21>/Product'
     *  Product: '<S21>/Product1'
     */
    tmp_0 = floorf((real32_T)rtd_hHsd_Diagnose_AdcBuffer[0] * (real32_T)
                   localP->ADCresolution_Value * (real32_T)localP->Vref_Value /
                   (real32_T)localP->Ris_Value * localP->Magnification_Gain);
    if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
      tmp_0 = 0.0F;
    } else {
      tmp_0 = fmodf(tmp_0, 65536.0F);
    }

    *rty_1 = (uint16_T)(tmp_0 < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                        -tmp_0 : (int32_T)(uint16_T)tmp_0);

    /* End of DataTypeConversion: '<S21>/Data Type Conversion1' */
    /* End of Outputs for SubSystem: '<S1>/ADC采集与处理单元10' */
    localDW->i = 0.0;
  } else {
    tmp = rt_roundd_snf(localDW->output);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        *rty_y = (uint8_T)tmp;
      } else {
        *rty_y = 0U;
      }
    } else {
      *rty_y = MAX_uint8_T;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S1>/诊断数据转存单元1'
 *    '<S1>/诊断数据转存单元2'
 *    '<S1>/诊断数据转存单元3'
 *    '<S1>/诊断数据转存单元4'
 *    '<S1>/诊断数据转存单元5'
 */
void RBCM_Model_u_k(uint8_T rtu_index, uint16_T rtu_u, uint16_T *rty_y1,
                    uint16_T *rty_y2, uint16_T *rty_y3, uint16_T *rty_y4,
                    DW_u_RBCM_Model_b_T *localDW)
{
  switch (rtu_index) {
   case 0U:
    localDW->Y1 = rtu_u;
    break;

   case 1U:
    localDW->Y2 = rtu_u;
    break;

   case 2U:
    localDW->Y3 = rtu_u;
    break;

   case 3U:
    localDW->Y4 = rtu_u;
    break;
  }

  *rty_y1 = localDW->Y1;
  *rty_y2 = localDW->Y2;
  *rty_y3 = localDW->Y3;
  *rty_y4 = localDW->Y4;
}

/*
 * Output and update for atomic system:
 *    '<S1>/错误码转存单元1'
 *    '<S1>/错误码转存单元10'
 *    '<S1>/错误码转存单元2'
 *    '<S1>/错误码转存单元3'
 *    '<S1>/错误码转存单元4'
 */
void RBCM_Model_u_g(uint8_T rtu_index, uint8_T rtu_u, uint8_T *rty_y1, uint8_T
                    *rty_y2, uint8_T *rty_y3, uint8_T *rty_y4,
                    DW_u_RBCM_Model_lj_T *localDW)
{
  switch (rtu_index) {
   case 0U:
    localDW->Y1 = rtu_u;
    break;

   case 1U:
    localDW->Y2 = rtu_u;
    break;

   case 2U:
    localDW->Y3 = rtu_u;
    break;

   case 3U:
    localDW->Y4 = rtu_u;
    break;
  }

  *rty_y1 = localDW->Y1;
  *rty_y2 = localDW->Y2;
  *rty_y3 = localDW->Y3;
  *rty_y4 = localDW->Y4;
}

/* System initialize for function-call system: '<Root>/Subsystem6' */
void RBCM_Model_Subsystem6_Init(void)
{
  /* SystemInitialize for BusCreator: '<S12>/VbatsData' incorporates:
   *  Outport: '<S12>/Out2'
   */
  RBCM_Model_B.VbatsData = RBCM_Model_P.Out2_Y0_c;
}

/* Output and update for function-call system: '<Root>/Subsystem6' */
void RBCM_Model_Subsystem6(void)
{
  real32_T tmp;

  /* Gain: '<S12>/Magnification' incorporates:
   *  Constant: '<S12>/ADC resolution'
   *  Constant: '<S12>/Vref'
   *  DataStoreRead: '<S12>/Data Store Read'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   */
  tmp = floorf((real32_T)RBCM_Model_DW.Bats_Monitor_AdcBuffer[0] * (real32_T)
               RBCM_Model_P.ADCresolution_Value * (real32_T)
               RBCM_Model_P.Vref_Value * RBCM_Model_P.Magnification_Gain);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  /* BusCreator: '<S12>/VbatsData' incorporates:
   *  Gain: '<S12>/Magnification'
   */
  RBCM_Model_B.VbatsData.LvBatsV = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Gain: '<S12>/Magnification1' incorporates:
   *  Constant: '<S12>/ADC resolution1'
   *  Constant: '<S12>/Vref1'
   *  DataStoreRead: '<S12>/Data Store Read'
   *  DataTypeConversion: '<S12>/Data Type Conversion1'
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   */
  tmp = floorf((real32_T)RBCM_Model_DW.Bats_Monitor_AdcBuffer[1] * (real32_T)
               RBCM_Model_P.ADCresolution1_Value * (real32_T)
               RBCM_Model_P.Vref1_Value * RBCM_Model_P.Magnification1_Gain);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  /* BusCreator: '<S12>/VbatsData' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   *  Gain: '<S12>/Magnification1'
   */
  RBCM_Model_B.VbatsData.LvBatsI = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  RBCM_Model_B.VbatsData.LvBatTemp1 = RBCM_Model_P.Constant_Value_l;
  RBCM_Model_B.VbatsData.LvBatTemp2 = RBCM_Model_P.Constant1_Value_d;
}

/* System initialize for function-call system: '<Root>/指令报文解码器' */
void RBCM_Model_u_p_Init(void)
{
  boolean_T rtb_A;

  /* Start for S-Function (scanunpack): '<S102>/CAN Unpack' */

  /*-----------S-Function Block: <S102>/CAN Unpack -----------------*/

  /* SystemInitialize for Chart: '<S15>/Chart1' */
  RBCM_Model_Chart2_Init(&rtb_A);

  /* SystemInitialize for SignalConversion generated from: '<S15>/DrsDriveCommand' incorporates:
   *  Constant: '<S102>/Constant12'
   */
  RBCM_Model_B.OutportBufferForDrsDriveCommand = RBCM_Model_P.Constant12_Value;

  /* SystemInitialize for BusAssignment: '<S102>/HsdDriveCommandsCAN' incorporates:
   *  Outport: '<S15>/HsdDriveCommands'
   */
  RBCM_Model_B.HsdDriveCommandsCAN = RBCM_Model_P.HsdDriveCommands_Y0;
}

/* System reset for function-call system: '<Root>/指令报文解码器' */
void RBCM_Model_u_o_Reset(void)
{
  boolean_T rtb_A;

  /* SystemReset for Chart: '<S15>/Chart1' */
  RBCM_Model_Chart2_Reset(&rtb_A, &RBCM_Model_DW.sf_Chart1_o);
}

/* Output and update for function-call system: '<Root>/指令报文解码器' */
void RBCM_Model_u_k4(void)
{
  boolean_T rtb_A;

  /* Chart: '<S15>/Chart1' */
  RBCM_Model_Chart2(&rtb_A, &RBCM_Model_DW.sf_Chart1_o);

  /* DataStoreWrite: '<S15>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion13'
   */
  RBCM_Model_DW.RGBLED0state[1] = rtb_A;

  /* SignalConversion generated from: '<S15>/DrsDriveCommand' incorporates:
   *  Constant: '<S102>/Constant12'
   */
  RBCM_Model_B.OutportBufferForDrsDriveCommand = RBCM_Model_P.Constant12_Value;

  /* S-Function (scanunpack): '<S102>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<S102>/CAN Unpack' */
    if ((8 == RBCM_Model_B.Delay.Length) && (RBCM_Model_B.Delay.ID !=
         INVALID_CAN_ID) ) {
      if ((514 == RBCM_Model_B.Delay.ID) && (1U == RBCM_Model_B.Delay.Extended) )
      {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 2
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (RBCM_Model_B.Delay.Data[0]) & (uint8_T)(0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 0
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (RBCM_Model_B.Delay.Data[0]) & (uint8_T)(0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(RBCM_Model_B.Delay.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 16
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(RBCM_Model_B.Delay.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 24
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(RBCM_Model_B.Delay.Data[3]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(RBCM_Model_B.Delay.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(RBCM_Model_B.Delay.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              RBCM_Model_B.CANUnpack_o7 = result;
            }
          }
        }
      }
    }
  }

  /* BusAssignment: '<S102>/HsdDriveCommandsCAN' */
  RBCM_Model_B.HsdDriveCommandsCAN = RBCM_Model_B.HsdDriveCommandsInit;

  /* BusAssignment: '<S102>/HsdDriveCommandsCAN' */
  RBCM_Model_B.HsdDriveCommandsCAN.BuzzerPwr_lHsd3ch3 =
    RBCM_Model_B.CANUnpack_o1;
  RBCM_Model_B.HsdDriveCommandsCAN.DrsPwr_8v_lHsd3ch1 =
    RBCM_Model_B.CANUnpack_o2;
  RBCM_Model_B.HsdDriveCommandsCAN.AccuFanPwr_hHsd3ch2 =
    RBCM_Model_B.CANUnpack_o3;
  RBCM_Model_B.HsdDriveCommandsCAN.PumpFan1_hHsd4ch1 = RBCM_Model_B.CANUnpack_o4;
  RBCM_Model_B.HsdDriveCommandsCAN.PumpFan2_hHsd4ch2 = RBCM_Model_B.CANUnpack_o5;
  RBCM_Model_B.HsdDriveCommandsCAN.PumpPwr_hHsd3ch1 = RBCM_Model_B.CANUnpack_o6;
  RBCM_Model_B.HsdDriveCommandsCAN.TaillightPwr_lHsd3ch4 =
    RBCM_Model_B.CANUnpack_o7;
}

/* Model step function */
void RBCM_Model_step(void)
{
  real_T rtb_Step2;
  int32_T i;
  uint16_T rtb_y1_dc;
  uint16_T rtb_y2_mh;
  uint16_T rtb_y3_d;
  uint16_T rtb_y4_o;
  uint8_T rtb_MultiportSwitch;
  uint8_T rtb_y1_of;
  uint8_T rtb_y2_if;
  uint8_T rtb_y3_j;
  uint8_T rtb_y4_e;
  uint8_T rtb_y_n;
  boolean_T rtb_A;

  /* RateTransition: '<Root>/RT1' */
  rtb_A = (RBCM_Model_M->Timing.TaskCounters.TID[1] == 0);
  if (rtb_A) {
    /* Step: '<Root>/Step2' */
    if (((RBCM_Model_M->Timing.clockTick1) * 0.05) < RBCM_Model_P.Step2_Time) {
      rtb_Step2 = RBCM_Model_P.Step2_Y0;
    } else {
      rtb_Step2 = RBCM_Model_P.Step2_YFinal;
    }

    /* End of Step: '<Root>/Step2' */
  }

  /* Delay: '<Root>/Delay' */
  RBCM_Model_B.Delay = RBCM_Model_DW.Delay_DSTATE;

  /* MATLAB Function: '<Root>/HsdDriveCommand Struct1' */
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_12v_lHsd1ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.BspdPwr_lHsd1ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.LoggerPwr_lHsd1ch3 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.TempSensorPwr_lHsd1ch4 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_12v_lHsd2ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.VcuPwr_lHsd2ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.Fireon_Pwr_lHsd2ch3 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DsbdPwr_lHsd2ch4 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DrsPwr_8v_lHsd3ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_lHsd3ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.BuzzerPwr_lHsd3ch3 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.TaillightPwr_lHsd3ch4 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_5v_lHsd4ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.AccuUbr_lHsd4ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.AccuPwr_lHsd4ch3 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.BduPwr_lHsd4ch4 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_5v_lHsd5ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.McuUbr_lHsd5ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.EnergeMeterPwr_lHsd5ch3 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.TsalrPwr_lHsd5ch4 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.ILPwr_hHsd1ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_hHsd1ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.VcuUbr_hHsd2ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.Device_hHsd2ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.PumpPwr_hHsd3ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.AccuFanPwr_hHsd3ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.PumpFan1_hHsd4ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.PumpFan2_hHsd4ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_hHsd5ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_hHsd5ch2 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_hHsd6ch1 = 1U;
  RBCM_Model_B.HsdDriveCommandsInit.DevicePwr_hHsd6ch2 = 1U;

  /* End of Outputs for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler4' */

  /* RateTransition: '<Root>/RT1' */
  if (rtb_A) {
    /* If: '<S11>/If' */
    if (rtb_Step2 > 0.0) {
      /* Outputs for IfAction SubSystem: '<S11>/Subsystem13' incorporates:
       *  ActionPort: '<S98>/Action Port'
       */
      /* Merge: '<S11>/HsdDriveCommands' incorporates:
       *  SignalConversion generated from: '<S98>/In1'
       */
      RBCM_Model_B.HsdDriveCommands = RBCM_Model_B.HsdDriveCommandsCAN;

      /* End of Outputs for SubSystem: '<S11>/Subsystem13' */
    } else {
      /* Outputs for IfAction SubSystem: '<S11>/Subsystem' incorporates:
       *  ActionPort: '<S97>/Action Port'
       */
      /* Merge: '<S11>/HsdDriveCommands' incorporates:
       *  MATLAB Function: '<S97>/HsdDriveCommand Struct1'
       *  SignalConversion generated from: '<S97>/y'
       */
      RBCM_Model_B.HsdDriveCommands.DevicePwr_12v_lHsd1ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.BspdPwr_lHsd1ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.LoggerPwr_lHsd1ch3 = 1U;
      RBCM_Model_B.HsdDriveCommands.TempSensorPwr_lHsd1ch4 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_12v_lHsd2ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.VcuPwr_lHsd2ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.Fireon_Pwr_lHsd2ch3 = 1U;
      RBCM_Model_B.HsdDriveCommands.DsbdPwr_lHsd2ch4 = 1U;
      RBCM_Model_B.HsdDriveCommands.DrsPwr_8v_lHsd3ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_lHsd3ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.BuzzerPwr_lHsd3ch3 = 1U;
      RBCM_Model_B.HsdDriveCommands.TaillightPwr_lHsd3ch4 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_5v_lHsd4ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.AccuUbr_lHsd4ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.AccuPwr_lHsd4ch3 = 1U;
      RBCM_Model_B.HsdDriveCommands.BduPwr_lHsd4ch4 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_5v_lHsd5ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.McuUbr_lHsd5ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.EnergeMeterPwr_lHsd5ch3 = 1U;
      RBCM_Model_B.HsdDriveCommands.TsalrPwr_lHsd5ch4 = 1U;
      RBCM_Model_B.HsdDriveCommands.ILPwr_hHsd1ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd1ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.VcuUbr_hHsd2ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.Device_hHsd2ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.PumpPwr_hHsd3ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.AccuFanPwr_hHsd3ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.PumpFan1_hHsd4ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.PumpFan2_hHsd4ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd5ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd5ch2 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd6ch1 = 1U;
      RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd6ch2 = 1U;

      /* End of Outputs for SubSystem: '<S11>/Subsystem' */
    }

    /* End of If: '<S11>/If' */

    /* S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/HSD诊断分析子系统'
     */
    /* S-Function (s32k3_dio): '<S37>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2);

    /* S-Function (s32k3_dio): '<S37>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1);

    /* MATLAB Function: '<S1>/触发器1' incorporates:
     *  Constant: '<S1>/输出通道数1'
     *  Constant: '<S1>/预分频值1'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value, RBCM_Model_P.u_Value_i, &rtb_y_n,
                   &RBCM_Model_B.DataTypeConversion1_o,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_1_o,
                   &RBCM_Model_P.sf_1_o);

    /* S-Function (sfix_bitop): '<S37>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2 = (uint8_T)(rtb_y_n &
      RBCM_Model_P.BitwiseAND2_BitMask);

    /* ArithShift: '<S37>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S37>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1 = (uint8_T)((int32_T)((uint32_T)rtb_y_n &
      RBCM_Model_P.BitwiseAND3_BitMask) >> 1);

    /* MultiPortSwitch: '<S42>/Multiport Switch' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant2'
     *  Constant: '<S42>/Constant3'
     *  Constant: '<S42>/Constant4'
     *  Gain: '<S42>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain *
             RBCM_Model_B.DataTypeConversion1_o) >> 9) {
     case 0:
      rtb_MultiportSwitch = RBCM_Model_P.Constant2_Value_o;
      break;

     case 5:
      rtb_MultiportSwitch = RBCM_Model_P.Constant3_Value_f;
      break;

     case 90:
      rtb_MultiportSwitch = RBCM_Model_P.Constant4_Value_m;
      break;

     default:
      rtb_MultiportSwitch = RBCM_Model_P.Constant_Value_k;
      break;
    }

    /* End of MultiPortSwitch: '<S42>/Multiport Switch' */

    /* MATLAB Function: '<S1>/诊断数据转存单元1' */
    RBCM_Model_u_k(rtb_y_n, RBCM_Model_B.DataTypeConversion1_o, &rtb_y1_dc,
                   &rtb_y2_mh, &rtb_y3_d, &rtb_y4_o, &RBCM_Model_DW.sf_1_k);

    /* MATLAB Function: '<S1>/错误码转存单元10' */
    RBCM_Model_u_g(rtb_y_n, rtb_MultiportSwitch, &rtb_y1_of, &rtb_y2_if,
                   &rtb_y3_j, &rtb_y4_e, &RBCM_Model_DW.sf_10_o);

    /* S-Function (s32k3_dio): '<S36>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_lo);

    /* MATLAB Function: '<S1>/触发器10' incorporates:
     *  Constant: '<S1>/输出通道数10'
     *  Constant: '<S1>/预分频值10'
     */
    RBCM_Model_u0(RBCM_Model_P.u0_Value, RBCM_Model_P.u0_Value_a,
                  &RBCM_Model_B.y_lo, &RBCM_Model_B.DataTypeConversion1_g,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_10_a,
                  &RBCM_Model_P.sf_10_a);

    /* MultiPortSwitch: '<S44>/Multiport Switch' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant2'
     *  Constant: '<S44>/Constant3'
     *  Constant: '<S44>/Constant4'
     *  Gain: '<S44>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_i *
             RBCM_Model_B.DataTypeConversion1_g) >> 9) {
     case 0:
      rtb_y_n = RBCM_Model_P.Constant2_Value_k;
      break;

     case 5:
      rtb_y_n = RBCM_Model_P.Constant3_Value_a;
      break;

     case 290:
      rtb_y_n = RBCM_Model_P.Constant4_Value_n;
      break;

     default:
      rtb_y_n = RBCM_Model_P.Constant_Value_c3;
      break;
    }

    /* End of MultiPortSwitch: '<S44>/Multiport Switch' */

    /* MATLAB Function: '<S1>/数据转存单元10' */
    RBCM_Model_u(RBCM_Model_B.y_lo, rtb_y_n, &rtb_MultiportSwitch, &rtb_y1_of,
                 &RBCM_Model_DW.sf_10);

    /* MATLAB Function: '<S1>/数据转存单元12' */
    RBCM_Model_u1(RBCM_Model_B.y_lo, RBCM_Model_B.DataTypeConversion1_g,
                  &rtb_y1_dc, &rtb_y2_mh, &RBCM_Model_DW.sf_12);

    /* S-Function (s32k3_dio): '<S32>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_i);

    /* MATLAB Function: '<S1>/触发器11' incorporates:
     *  Constant: '<S1>/输出通道数11'
     *  Constant: '<S1>/预分频值11'
     */
    RBCM_Model_u0(RBCM_Model_P.u1_Value, RBCM_Model_P.u1_Value_n,
                  &RBCM_Model_B.y_i, &RBCM_Model_B.DataTypeConversion1_l,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_11_a,
                  &RBCM_Model_P.sf_11_a);

    /* MultiPortSwitch: '<S43>/Multiport Switch' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Constant: '<S43>/Constant4'
     *  Gain: '<S43>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_l *
             RBCM_Model_B.DataTypeConversion1_l) >> 9) {
     case 0:
      rtb_y_n = RBCM_Model_P.Constant2_Value_p;
      break;

     case 5:
      rtb_y_n = RBCM_Model_P.Constant3_Value_c;
      break;

     case 290:
      rtb_y_n = RBCM_Model_P.Constant4_Value_f;
      break;

     default:
      rtb_y_n = RBCM_Model_P.Constant_Value_c;
      break;
    }

    /* End of MultiPortSwitch: '<S43>/Multiport Switch' */

    /* MATLAB Function: '<S1>/数据转存单元1' */
    RBCM_Model_u(RBCM_Model_B.y_i, rtb_y_n, &rtb_MultiportSwitch, &rtb_y1_of,
                 &RBCM_Model_DW.sf_1);

    /* MATLAB Function: '<S1>/数据转存单元11' */
    RBCM_Model_u1(RBCM_Model_B.y_i, RBCM_Model_B.DataTypeConversion1_l,
                  &rtb_y1_dc, &rtb_y2_mh, &RBCM_Model_DW.sf_11);

    /* S-Function (s32k3_dio): '<S38>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2_h);

    /* S-Function (s32k3_dio): '<S38>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_c);

    /* MATLAB Function: '<S1>/触发器2' incorporates:
     *  Constant: '<S1>/输出通道数2'
     *  Constant: '<S1>/预分频值2'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_n, RBCM_Model_P.u_Value_k, &rtb_y_n,
                   &RBCM_Model_B.DataTypeConversion1_du,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_2_l,
                   &RBCM_Model_P.sf_2_l);

    /* S-Function (sfix_bitop): '<S38>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_h = (uint8_T)(rtb_y_n &
      RBCM_Model_P.BitwiseAND2_BitMask_f);

    /* ArithShift: '<S38>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S38>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_c = (uint8_T)((int32_T)((uint32_T)rtb_y_n &
      RBCM_Model_P.BitwiseAND3_BitMask_k) >> 1);

    /* MultiPortSwitch: '<S45>/Multiport Switch' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant2'
     *  Constant: '<S45>/Constant3'
     *  Constant: '<S45>/Constant4'
     *  Gain: '<S45>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_d *
             RBCM_Model_B.DataTypeConversion1_du) >> 9) {
     case 0:
      rtb_MultiportSwitch = RBCM_Model_P.Constant2_Value_c;
      break;

     case 5:
      rtb_MultiportSwitch = RBCM_Model_P.Constant3_Value_k;
      break;

     case 90:
      rtb_MultiportSwitch = RBCM_Model_P.Constant4_Value_o;
      break;

     default:
      rtb_MultiportSwitch = RBCM_Model_P.Constant_Value_ku;
      break;
    }

    /* End of MultiPortSwitch: '<S45>/Multiport Switch' */

    /* MATLAB Function: '<S1>/诊断数据转存单元2' */
    RBCM_Model_u_k(rtb_y_n, RBCM_Model_B.DataTypeConversion1_du, &rtb_y1_dc,
                   &rtb_y2_mh, &rtb_y3_d, &rtb_y4_o, &RBCM_Model_DW.sf_2_p);

    /* MATLAB Function: '<S1>/错误码转存单元1' */
    RBCM_Model_u_g(rtb_y_n, rtb_MultiportSwitch, &rtb_y1_of, &rtb_y2_if,
                   &rtb_y3_j, &rtb_y4_e, &RBCM_Model_DW.sf_1_g);

    /* S-Function (s32k3_dio): '<S39>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2_a);

    /* S-Function (s32k3_dio): '<S39>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_b);

    /* MATLAB Function: '<S1>/触发器3' incorporates:
     *  Constant: '<S1>/输出通道数3'
     *  Constant: '<S1>/预分频值3'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_a, RBCM_Model_P.u_Value_p, &rtb_y_n,
                   &RBCM_Model_B.DataTypeConversion1_a4,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_3_c,
                   &RBCM_Model_P.sf_3_c);

    /* S-Function (sfix_bitop): '<S39>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_a = (uint8_T)(rtb_y_n &
      RBCM_Model_P.BitwiseAND2_BitMask_i);

    /* ArithShift: '<S39>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S39>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_b = (uint8_T)((int32_T)((uint32_T)rtb_y_n &
      RBCM_Model_P.BitwiseAND3_BitMask_kw) >> 1);

    /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S46>/Constant2'
     *  Constant: '<S46>/Constant3'
     *  Constant: '<S46>/Constant4'
     *  Gain: '<S46>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_b *
             RBCM_Model_B.DataTypeConversion1_a4) >> 9) {
     case 0:
      rtb_MultiportSwitch = RBCM_Model_P.Constant2_Value_m;
      break;

     case 5:
      rtb_MultiportSwitch = RBCM_Model_P.Constant3_Value_ca;
      break;

     case 90:
      rtb_MultiportSwitch = RBCM_Model_P.Constant4_Value_a;
      break;

     default:
      rtb_MultiportSwitch = RBCM_Model_P.Constant_Value_j0;
      break;
    }

    /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

    /* MATLAB Function: '<S1>/诊断数据转存单元3' */
    RBCM_Model_u_k(rtb_y_n, RBCM_Model_B.DataTypeConversion1_a4, &rtb_y1_dc,
                   &rtb_y2_mh, &rtb_y3_d, &rtb_y4_o, &RBCM_Model_DW.sf_3_k);

    /* MATLAB Function: '<S1>/错误码转存单元3' */
    RBCM_Model_u_g(rtb_y_n, rtb_MultiportSwitch, &rtb_y1_of, &rtb_y2_if,
                   &rtb_y3_j, &rtb_y4_e, &RBCM_Model_DW.sf_3_b);

    /* S-Function (s32k3_dio): '<S40>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2_d);

    /* S-Function (s32k3_dio): '<S40>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_n);

    /* MATLAB Function: '<S1>/触发器4' incorporates:
     *  Constant: '<S1>/输出通道数4'
     *  Constant: '<S1>/预分频值4'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_j, RBCM_Model_P.u_Value_m, &rtb_y_n,
                   &RBCM_Model_B.DataTypeConversion1_m3,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_4_a,
                   &RBCM_Model_P.sf_4_a);

    /* S-Function (sfix_bitop): '<S40>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_d = (uint8_T)(rtb_y_n &
      RBCM_Model_P.BitwiseAND2_BitMask_l);

    /* ArithShift: '<S40>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S40>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_n = (uint8_T)((int32_T)((uint32_T)rtb_y_n &
      RBCM_Model_P.BitwiseAND3_BitMask_n) >> 1);

    /* MultiPortSwitch: '<S47>/Multiport Switch' incorporates:
     *  Constant: '<S47>/Constant'
     *  Constant: '<S47>/Constant2'
     *  Constant: '<S47>/Constant3'
     *  Constant: '<S47>/Constant4'
     *  Gain: '<S47>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_c *
             RBCM_Model_B.DataTypeConversion1_m3) >> 9) {
     case 0:
      rtb_MultiportSwitch = RBCM_Model_P.Constant2_Value_py;
      break;

     case 5:
      rtb_MultiportSwitch = RBCM_Model_P.Constant3_Value_ax;
      break;

     case 90:
      rtb_MultiportSwitch = RBCM_Model_P.Constant4_Value_l;
      break;

     default:
      rtb_MultiportSwitch = RBCM_Model_P.Constant_Value_p;
      break;
    }

    /* End of MultiPortSwitch: '<S47>/Multiport Switch' */

    /* MATLAB Function: '<S1>/诊断数据转存单元4' */
    RBCM_Model_u_k(rtb_y_n, RBCM_Model_B.DataTypeConversion1_m3, &rtb_y1_dc,
                   &rtb_y2_mh, &rtb_y3_d, &rtb_y4_o, &RBCM_Model_DW.sf_4_k);

    /* MATLAB Function: '<S1>/错误码转存单元2' */
    RBCM_Model_u_g(rtb_y_n, rtb_MultiportSwitch, &rtb_y1_of, &rtb_y2_if,
                   &rtb_y3_j, &rtb_y4_e, &RBCM_Model_DW.sf_2_o);

    /* S-Function (s32k3_dio): '<S41>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.BitwiseAND2_ht);

    /* S-Function (s32k3_dio): '<S41>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_d);

    /* MATLAB Function: '<S1>/触发器5' incorporates:
     *  Constant: '<S1>/输出通道数5'
     *  Constant: '<S1>/预分频值5'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_l, RBCM_Model_P.u_Value_o, &rtb_y_n,
                   &RBCM_Model_B.DataTypeConversion1_m,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_5_c,
                   &RBCM_Model_P.sf_5_c);

    /* S-Function (sfix_bitop): '<S41>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_ht = (uint8_T)(rtb_y_n &
      RBCM_Model_P.BitwiseAND2_BitMask_h);

    /* ArithShift: '<S41>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S41>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_d = (uint8_T)((int32_T)((uint32_T)rtb_y_n &
      RBCM_Model_P.BitwiseAND3_BitMask_b) >> 1);

    /* MultiPortSwitch: '<S48>/Multiport Switch' incorporates:
     *  Constant: '<S48>/Constant'
     *  Constant: '<S48>/Constant2'
     *  Constant: '<S48>/Constant3'
     *  Constant: '<S48>/Constant4'
     *  Gain: '<S48>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_k *
             RBCM_Model_B.DataTypeConversion1_m) >> 9) {
     case 0:
      rtb_MultiportSwitch = RBCM_Model_P.Constant2_Value_kb;
      break;

     case 5:
      rtb_MultiportSwitch = RBCM_Model_P.Constant3_Value_aq;
      break;

     case 90:
      rtb_MultiportSwitch = RBCM_Model_P.Constant4_Value_nh;
      break;

     default:
      rtb_MultiportSwitch = RBCM_Model_P.Constant_Value_m;
      break;
    }

    /* End of MultiPortSwitch: '<S48>/Multiport Switch' */

    /* MATLAB Function: '<S1>/诊断数据转存单元5' */
    RBCM_Model_u_k(rtb_y_n, RBCM_Model_B.DataTypeConversion1_m, &rtb_y1_dc,
                   &rtb_y2_mh, &rtb_y3_d, &rtb_y4_o, &RBCM_Model_DW.sf_5_d);

    /* MATLAB Function: '<S1>/错误码转存单元4' */
    RBCM_Model_u_g(rtb_y_n, rtb_MultiportSwitch, &rtb_y1_of, &rtb_y2_if,
                   &rtb_y3_j, &rtb_y4_e, &RBCM_Model_DW.sf_4_c);

    /* MATLAB Function: '<S1>/触发器6' incorporates:
     *  Constant: '<S1>/输出通道数6'
     *  Constant: '<S1>/预分频值6'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_iv, RBCM_Model_P.u_Value_g, &rtb_y_n,
                  &RBCM_Model_B.DataTypeConversion1_b,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_6_o,
                  &RBCM_Model_P.sf_6_o);

    /* MultiPortSwitch: '<S49>/Multiport Switch' incorporates:
     *  Constant: '<S49>/Constant'
     *  Constant: '<S49>/Constant2'
     *  Constant: '<S49>/Constant3'
     *  Constant: '<S49>/Constant4'
     *  Gain: '<S49>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_j *
             RBCM_Model_B.DataTypeConversion1_b) >> 9) {
     case 0:
      rtb_MultiportSwitch = RBCM_Model_P.Constant2_Value_ct;
      break;

     case 5:
      rtb_MultiportSwitch = RBCM_Model_P.Constant3_Value_f2;
      break;

     case 290:
      rtb_MultiportSwitch = RBCM_Model_P.Constant4_Value_c;
      break;

     default:
      rtb_MultiportSwitch = RBCM_Model_P.Constant_Value_op;
      break;
    }

    /* End of MultiPortSwitch: '<S49>/Multiport Switch' */

    /* MATLAB Function: '<S1>/数据转存单元2' */
    RBCM_Model_u(rtb_y_n, rtb_MultiportSwitch, &rtb_y1_of, &rtb_y2_if,
                 &RBCM_Model_DW.sf_2);

    /* MATLAB Function: '<S1>/数据转存单元3' */
    RBCM_Model_u1(rtb_y_n, RBCM_Model_B.DataTypeConversion1_b, &rtb_y1_dc,
                  &rtb_y2_mh, &RBCM_Model_DW.sf_3);

    /* S-Function (s32k3_dio): '<S34>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_l);

    /* MATLAB Function: '<S1>/触发器7' incorporates:
     *  Constant: '<S1>/输出通道数7'
     *  Constant: '<S1>/预分频值7'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_gq, RBCM_Model_P.u_Value_lh,
                  &RBCM_Model_B.y_l, &RBCM_Model_B.DataTypeConversion1_d,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_7_p,
                  &RBCM_Model_P.sf_7_p);

    /* MultiPortSwitch: '<S50>/Multiport Switch' incorporates:
     *  Constant: '<S50>/Constant'
     *  Constant: '<S50>/Constant2'
     *  Constant: '<S50>/Constant3'
     *  Constant: '<S50>/Constant4'
     *  Gain: '<S50>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_e *
             RBCM_Model_B.DataTypeConversion1_d) >> 9) {
     case 0:
      rtb_y_n = RBCM_Model_P.Constant2_Value_d;
      break;

     case 5:
      rtb_y_n = RBCM_Model_P.Constant3_Value_b;
      break;

     case 290:
      rtb_y_n = RBCM_Model_P.Constant4_Value_ce;
      break;

     default:
      rtb_y_n = RBCM_Model_P.Constant_Value_a;
      break;
    }

    /* End of MultiPortSwitch: '<S50>/Multiport Switch' */

    /* MATLAB Function: '<S1>/数据转存单元4' */
    RBCM_Model_u(RBCM_Model_B.y_l, rtb_y_n, &rtb_MultiportSwitch, &rtb_y1_of,
                 &RBCM_Model_DW.sf_4);

    /* MATLAB Function: '<S1>/数据转存单元5' */
    RBCM_Model_u1(RBCM_Model_B.y_l, RBCM_Model_B.DataTypeConversion1_d,
                  &rtb_y1_dc, &rtb_y2_mh, &RBCM_Model_DW.sf_5);

    /* S-Function (s32k3_dio): '<S33>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_k);

    /* MATLAB Function: '<S1>/触发器8' incorporates:
     *  Constant: '<S1>/输出通道数8'
     *  Constant: '<S1>/预分频值8'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_h, RBCM_Model_P.u_Value_ku,
                  &RBCM_Model_B.y_k, &RBCM_Model_B.DataTypeConversion1_a,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_8_j,
                  &RBCM_Model_P.sf_8_j);

    /* MultiPortSwitch: '<S51>/Multiport Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  Constant: '<S51>/Constant2'
     *  Constant: '<S51>/Constant3'
     *  Constant: '<S51>/Constant4'
     *  Gain: '<S51>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_lr *
             RBCM_Model_B.DataTypeConversion1_a) >> 9) {
     case 0:
      rtb_y_n = RBCM_Model_P.Constant2_Value_ke;
      break;

     case 5:
      rtb_y_n = RBCM_Model_P.Constant3_Value_kf;
      break;

     case 290:
      rtb_y_n = RBCM_Model_P.Constant4_Value_l4;
      break;

     default:
      rtb_y_n = RBCM_Model_P.Constant_Value_g;
      break;
    }

    /* End of MultiPortSwitch: '<S51>/Multiport Switch' */

    /* MATLAB Function: '<S1>/数据转存单元6' */
    RBCM_Model_u(RBCM_Model_B.y_k, rtb_y_n, &rtb_MultiportSwitch, &rtb_y1_of,
                 &RBCM_Model_DW.sf_6);

    /* MATLAB Function: '<S1>/数据转存单元7' */
    RBCM_Model_u1(RBCM_Model_B.y_k, RBCM_Model_B.DataTypeConversion1_a,
                  &rtb_y1_dc, &rtb_y2_mh, &RBCM_Model_DW.sf_7);

    /* S-Function (s32k3_dio): '<S35>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y);

    /* MATLAB Function: '<S1>/触发器9' incorporates:
     *  Constant: '<S1>/输出通道数9'
     *  Constant: '<S1>/预分频值9'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_al, RBCM_Model_P.u_Value_k3,
                  &RBCM_Model_B.y, &RBCM_Model_B.DataTypeConversion1,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_9_a,
                  &RBCM_Model_P.sf_9_a);

    /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S52>/Constant2'
     *  Constant: '<S52>/Constant3'
     *  Constant: '<S52>/Constant4'
     *  Gain: '<S52>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_n *
             RBCM_Model_B.DataTypeConversion1) >> 9) {
     case 0:
      rtb_y_n = RBCM_Model_P.Constant2_Value_a;
      break;

     case 5:
      rtb_y_n = RBCM_Model_P.Constant3_Value_e;
      break;

     case 290:
      rtb_y_n = RBCM_Model_P.Constant4_Value_mp;
      break;

     default:
      rtb_y_n = RBCM_Model_P.Constant_Value_i;
      break;
    }

    /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

    /* MATLAB Function: '<S1>/数据转存单元8' */
    RBCM_Model_u(RBCM_Model_B.y, rtb_y_n, &rtb_MultiportSwitch, &rtb_y1_of,
                 &RBCM_Model_DW.sf_8);

    /* MATLAB Function: '<S1>/数据转存单元9' */
    RBCM_Model_u1(RBCM_Model_B.y, RBCM_Model_B.DataTypeConversion1, &rtb_y1_dc,
                  &rtb_y2_mh, &RBCM_Model_DW.sf_9);

    /* S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/HSD驱动子系统'
     */
    /* S-Function (s32k3_dio): '<S86>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd1ch2);

    /* S-Function (s32k3_dio): '<S87>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.VcuUbr_hHsd2ch1);

    /* S-Function (s32k3_dio): '<S87>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.Device_hHsd2ch2);

    /* S-Function (s32k3_dio): '<S88>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.PumpPwr_hHsd3ch1);

    /* S-Function (s32k3_dio): '<S88>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.AccuFanPwr_hHsd3ch2);

    /* S-Function (s32k3_dio): '<S89>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.PumpFan1_hHsd4ch1);

    /* DataTypeConversion: '<S2>/Data Type Conversion29' */
    RBCM_Model_B.DataTypeConversion29 =
      RBCM_Model_B.HsdDriveCommands.PumpFan2_hHsd4ch2;

    /* S-Function (s32k3_pwm): '<S89>/Pwm' */
    Pwm_SetDutyCycle(PwmChannel_0, RBCM_Model_B.DataTypeConversion29);

    /* S-Function (s32k3_dio): '<S90>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd5ch1);

    /* S-Function (s32k3_dio): '<S90>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd5ch2);

    /* S-Function (s32k3_dio): '<S91>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd6ch1);

    /* S-Function (s32k3_dio): '<S91>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd6ch2);

    /* S-Function (s32k3_dio): '<S92>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_12v_lHsd1ch1);

    /* S-Function (s32k3_dio): '<S92>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.BspdPwr_lHsd1ch2);

    /* S-Function (s32k3_dio): '<S92>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.LoggerPwr_lHsd1ch3);

    /* S-Function (s32k3_dio): '<S92>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.TempSensorPwr_lHsd1ch4);

    /* S-Function (s32k3_dio): '<S93>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_12v_lHsd2ch1);

    /* S-Function (s32k3_dio): '<S93>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.VcuPwr_lHsd2ch2);

    /* S-Function (s32k3_dio): '<S93>/Dio4' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.Fireon_Pwr_lHsd2ch3);

    /* S-Function (s32k3_dio): '<S93>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DsbdPwr_lHsd2ch4);

    /* S-Function (s32k3_dio): '<S94>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DrsPwr_8v_lHsd3ch1);

    /* S-Function (s32k3_dio): '<S94>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_lHsd3ch2);

    /* S-Function (s32k3_dio): '<S94>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.BuzzerPwr_lHsd3ch3);

    /* S-Function (s32k3_dio): '<S94>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.TaillightPwr_lHsd3ch4);

    /* S-Function (s32k3_dio): '<S95>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_5v_lHsd4ch1);

    /* S-Function (s32k3_dio): '<S95>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.AccuUbr_lHsd4ch2);

    /* S-Function (s32k3_dio): '<S95>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.AccuPwr_lHsd4ch3);

    /* S-Function (s32k3_dio): '<S95>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.BduPwr_lHsd4ch4);

    /* S-Function (s32k3_dio): '<S96>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_5v_lHsd5ch1);

    /* S-Function (s32k3_dio): '<S96>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.McuUbr_lHsd5ch2);

    /* S-Function (s32k3_dio): '<S96>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.EnergeMeterPwr_lHsd5ch3);

    /* S-Function (s32k3_dio): '<S96>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.TsalrPwr_lHsd5ch4);

    /* S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem6'
     */
    RBCM_Model_Subsystem6();

    /* End of Outputs for S-Function (fcgen): '<Root>/50ms1' */

    /* RateTransition generated from: '<Root>/Subsystem6' */
    if (RBCM_Model_M->Timing.TaskCounters.TID[2] == 0) {
      RBCM_Model_DW.Bus_Vbats_Data_Buffer = RBCM_Model_B.VbatsData;
    }
  }

  /* RateTransition generated from: '<Root>/Subsystem6' */
  if (RBCM_Model_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition generated from: '<Root>/Subsystem6' */
    RBCM_Model_B.Bus_Vbats_Data_j = RBCM_Model_DW.Bus_Vbats_Data_Buffer;

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem7'
     */
    /* Chart: '<S13>/Chart2' */
    RBCM_Model_Chart2(&rtb_A, &RBCM_Model_DW.sf_Chart2);

    /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion3'
     */
    RBCM_Model_DW.RGBLED0state[2] = rtb_A;

    /* S-Function (s32k3_dio): '<S13>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.DataStoreRead_o1);

    /* S-Function (s32k3_dio): '<S13>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_B.DataStoreRead_o2);

    /* S-Function (s32k3_dio): '<S13>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_LED_PTB14, RBCM_Model_B.DataStoreRead_o3);

    /* S-Function (s32k3_dio): '<S13>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.DataStoreRead_o3);

    /* DataStoreRead: '<S13>/Data Store Read' */
    RBCM_Model_B.DataStoreRead_o1 = RBCM_Model_DW.RGBLED0state[0];

    /* DataStoreRead: '<S13>/Data Store Read' */
    RBCM_Model_B.DataStoreRead_o2 = RBCM_Model_DW.RGBLED0state[1];

    /* DataStoreRead: '<S13>/Data Store Read' */
    RBCM_Model_B.DataStoreRead_o3 = RBCM_Model_DW.RGBLED0state[2];

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/无线调试模式管理子系统'
     */
    /* S-Function (s32k3_dio): '<S16>/Dio1' */
    RBCM_Model_B.Dio1 = Dio_ReadChannel(DioConf_DioChannel_ESP32S3_EN);

    /* If: '<S16>/If' */
    if (RBCM_Model_B.Dio1 == 0) {
      /* Outputs for IfAction SubSystem: '<S16>/Subsystem' incorporates:
       *  ActionPort: '<S103>/Action Port'
       */
      /* S-Function (s32k3_dio): '<S103>/Dio' incorporates:
       *  Constant: '<S103>/Constant'
       */
      Dio_WriteChannel(DioConf_DioChannel_ESP32S3_EN_RESET,
                       RBCM_Model_P.Constant_Value_b);

      /* S-Function (s32k3_dio): '<S103>/Dio1' incorporates:
       *  Constant: '<S103>/Constant1'
       */
      Dio_WriteChannel(DioConf_DioChannel_ESP32S3_EN_SET,
                       RBCM_Model_P.Constant1_Value_n);

      /* End of Outputs for SubSystem: '<S16>/Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S16>/Subsystem1' incorporates:
       *  ActionPort: '<S104>/Action Port'
       */
      /* S-Function (s32k3_dio): '<S104>/Dio' incorporates:
       *  Constant: '<S104>/Constant'
       */
      Dio_WriteChannel(DioConf_DioChannel_ESP32S3_EN_RESET,
                       RBCM_Model_P.Constant_Value_bb);

      /* End of Outputs for SubSystem: '<S16>/Subsystem1' */
    }

    /* End of If: '<S16>/If' */

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/核心状态信息发送'
     */
    /* Switch: '<S17>/Switch' incorporates:
     *  RateTransition generated from: '<Root>/核心状态信息发送'
     */
    if (RBCM_Model_B.OutportBufferForDrsDriveCommand >
        RBCM_Model_P.Switch_Threshold) {
      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S17>/Constant1'
       */
      RBCM_Model_B.Switch = RBCM_Model_P.Constant1_Value;
    } else {
      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S17>/Constant2'
       */
      RBCM_Model_B.Switch = RBCM_Model_P.Constant2_Value;
    }

    /* End of Switch: '<S17>/Switch' */

    /* S-Function (scanpack): '<S17>/CAN Pack' incorporates:
     *  Constant: '<S17>/Constant'
     */
    /* S-Function (scanpack): '<S17>/CAN Pack' */
    RBCM_Model_B.CANPack_c.ID = 252996210U;
    RBCM_Model_B.CANPack_c.Length = 4U;
    RBCM_Model_B.CANPack_c.Extended = 1U;
    RBCM_Model_B.CANPack_c.Remote = 0;
    RBCM_Model_B.CANPack_c.Data[0] = 0;
    RBCM_Model_B.CANPack_c.Data[1] = 0;
    RBCM_Model_B.CANPack_c.Data[2] = 0;
    RBCM_Model_B.CANPack_c.Data[3] = 0;
    RBCM_Model_B.CANPack_c.Data[4] = 0;
    RBCM_Model_B.CANPack_c.Data[5] = 0;
    RBCM_Model_B.CANPack_c.Data[6] = 0;
    RBCM_Model_B.CANPack_c.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_B.Bus_Vbats_Data_j.LvBatsV);

          /* no scaling required */
          packingValue = result;
        }

        {
          int8_T packedValue;
          int32_T scaledValue;
          scaledValue = (int32_T) packingValue;
          if (scaledValue > (int32_T) (127)) {
            packedValue = 127;
          } else if (scaledValue < (int32_T)((-(127)-1))) {
            packedValue = (-(127)-1);
          } else {
            packedValue = (int8_T) (scaledValue);
          }

          {
            uint8_T* tempValuePtr = (uint8_T*)&packedValue;
            uint8_T tempValue = *tempValuePtr;

            {
              RBCM_Model_B.CANPack_c.Data[1] = RBCM_Model_B.CANPack_c.Data[1] |
                (uint8_T)(tempValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 16
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_B.Bus_Vbats_Data_j.LvBatsI);

          /* no scaling required */
          packingValue = result;
        }

        {
          int8_T packedValue;
          int32_T scaledValue;
          scaledValue = (int32_T) packingValue;
          if (scaledValue > (int32_T) (127)) {
            packedValue = 127;
          } else if (scaledValue < (int32_T)((-(127)-1))) {
            packedValue = (-(127)-1);
          } else {
            packedValue = (int8_T) (scaledValue);
          }

          {
            uint8_T* tempValuePtr = (uint8_T*)&packedValue;
            uint8_T tempValue = *tempValuePtr;

            {
              RBCM_Model_B.CANPack_c.Data[2] = RBCM_Model_B.CANPack_c.Data[2] |
                (uint8_T)(tempValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 0
       *  length                  = 2
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_P.Constant_Value_o);

          /* no scaling required */
          packingValue = result;
        }

        {
          int8_T packedValue;
          int32_T scaledValue;
          scaledValue = (int32_T) packingValue;
          if (scaledValue > (int32_T) (1)) {
            packedValue = 1;
          } else if (scaledValue < (int32_T)((-(1)-1))) {
            packedValue = (-(1)-1);
          } else {
            packedValue = (int8_T) (scaledValue);
          }

          {
            uint8_T* tempValuePtr = (uint8_T*)&packedValue;
            uint8_T tempValue = *tempValuePtr;

            {
              RBCM_Model_B.CANPack_c.Data[0] = RBCM_Model_B.CANPack_c.Data[0] |
                (uint8_T)((uint8_T)(tempValue & (uint8_T)0x3U));
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 2
       *  length                  = 2
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real_T outValue = 0;

        {
          real_T result = RBCM_Model_B.Switch;

          /* no scaling required */
          /* round to closest integer value for integer CAN signal */
          outValue = round(result);
        }

        {
          int8_T packedValue;
          int32_T scaledValue;
          if (outValue > 2147483647.0) {
            scaledValue = 2147483647;
          } else if (outValue < -2147483648.0) {
            scaledValue = -2147483647 - 1;
          } else {
            scaledValue = (int32_T) outValue;
          }

          if (scaledValue > (int32_T) (1)) {
            packedValue = 1;
          } else if (scaledValue < (int32_T)((-(1)-1))) {
            packedValue = (-(1)-1);
          } else {
            packedValue = (int8_T) (scaledValue);
          }

          {
            uint8_T* tempValuePtr = (uint8_T*)&packedValue;
            uint8_T tempValue = *tempValuePtr;

            {
              RBCM_Model_B.CANPack_c.Data[0] = RBCM_Model_B.CANPack_c.Data[0] |
                (uint8_T)((uint8_T)((uint8_T)(tempValue & (uint8_T)0x3U) << 2));
            }
          }
        }
      }
    }

    /* Chart: '<S17>/Chart1' */
    RBCM_Model_Chart2(&rtb_A, &RBCM_Model_DW.sf_Chart1);

    /* DataStoreWrite: '<S17>/Data Store Write1' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion'
     */
    RBCM_Model_DW.RGBLED0state[1] = rtb_A;

    /* S-Function (s32k3_can): '<S17>/Can' incorporates:
     *  Constant: '<S17>/Constant4'
     */
    {
      Can_PduType pduInfo;
      pduInfo.id = RBCM_Model_B.CANPack_c.ID;
      pduInfo.swPduHandle = RBCM_Model_P.Constant4_Value;
      pduInfo.length = 8;
      pduInfo.sdu = &RBCM_Model_B.CANPack_c.Data[0];
      RBCM_Model_B.Can_c = Can_43_FLEXCAN_Write
        (Can_43_FLEXCANConf_CanHardwareObject_CanHardwareObject_Can0_Tx_Interrupt,
         &pduInfo);
    }

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/错误码数据发送(未)'
     */
    /* S-Function (scanpack): '<S18>/CAN Pack' incorporates:
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     */
    /* S-Function (scanpack): '<S18>/CAN Pack' */
    RBCM_Model_B.CANPack_h.ID = 252996466U;
    RBCM_Model_B.CANPack_h.Length = 2U;
    RBCM_Model_B.CANPack_h.Extended = 1U;
    RBCM_Model_B.CANPack_h.Remote = 0;
    RBCM_Model_B.CANPack_h.Data[0] = 0;
    RBCM_Model_B.CANPack_h.Data[1] = 0;
    RBCM_Model_B.CANPack_h.Data[2] = 0;
    RBCM_Model_B.CANPack_h.Data[3] = 0;
    RBCM_Model_B.CANPack_h.Data[4] = 0;
    RBCM_Model_B.CANPack_h.Data[5] = 0;
    RBCM_Model_B.CANPack_h.Data[6] = 0;
    RBCM_Model_B.CANPack_h.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_P.Constant2_Value_i);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          packedValue = (uint8_T) (packingValue);

          {
            {
              RBCM_Model_B.CANPack_h.Data[0] = RBCM_Model_B.CANPack_h.Data[0] |
                (uint8_T)(packedValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_P.Constant3_Value);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          packedValue = (uint8_T) (packingValue);

          {
            {
              RBCM_Model_B.CANPack_h.Data[1] = RBCM_Model_B.CANPack_h.Data[1] |
                (uint8_T)(packedValue);
            }
          }
        }
      }
    }

    /* S-Function (s32k3_can): '<S18>/Can' incorporates:
     *  Constant: '<S18>/Constant'
     */
    {
      Can_PduType pduInfo;
      pduInfo.id = RBCM_Model_B.CANPack_h.ID;
      pduInfo.swPduHandle = RBCM_Model_P.Constant_Value_h;
      pduInfo.length = 8;
      pduInfo.sdu = &RBCM_Model_B.CANPack_h.Data[0];
      RBCM_Model_B.Can_l = Can_43_FLEXCAN_Write
        (Can_43_FLEXCANConf_CanHardwareObject_CanHardwareObject_Can0_Tx_Interrupt,
         &pduInfo);
    }

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/错误码数据发送(未)1'
     */
    /* S-Function (scanpack): '<S19>/CAN Pack' incorporates:
     *  Constant: '<S19>/Constant2'
     *  Constant: '<S19>/Constant3'
     */
    /* S-Function (scanpack): '<S19>/CAN Pack' */
    RBCM_Model_B.CANPack.ID = 252996466U;
    RBCM_Model_B.CANPack.Length = 2U;
    RBCM_Model_B.CANPack.Extended = 1U;
    RBCM_Model_B.CANPack.Remote = 0;
    RBCM_Model_B.CANPack.Data[0] = 0;
    RBCM_Model_B.CANPack.Data[1] = 0;
    RBCM_Model_B.CANPack.Data[2] = 0;
    RBCM_Model_B.CANPack.Data[3] = 0;
    RBCM_Model_B.CANPack.Data[4] = 0;
    RBCM_Model_B.CANPack.Data[5] = 0;
    RBCM_Model_B.CANPack.Data[6] = 0;
    RBCM_Model_B.CANPack.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_P.Constant2_Value_ig);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          packedValue = (uint8_T) (packingValue);

          {
            {
              RBCM_Model_B.CANPack.Data[0] = RBCM_Model_B.CANPack.Data[0] |
                (uint8_T)(packedValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (RBCM_Model_P.Constant3_Value_n);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          packedValue = (uint8_T) (packingValue);

          {
            {
              RBCM_Model_B.CANPack.Data[1] = RBCM_Model_B.CANPack.Data[1] |
                (uint8_T)(packedValue);
            }
          }
        }
      }
    }

    /* S-Function (s32k3_can): '<S19>/Can' incorporates:
     *  Constant: '<S19>/Constant'
     */
    {
      Can_PduType pduInfo;
      pduInfo.id = RBCM_Model_B.CANPack.ID;
      pduInfo.swPduHandle = RBCM_Model_P.Constant_Value_j;
      pduInfo.length = 8;
      pduInfo.sdu = &RBCM_Model_B.CANPack.Data[0];
      RBCM_Model_B.Can_k = Can_43_FLEXCAN_Write
        (Can_43_FLEXCANConf_CanHardwareObject_CanHardwareObject_Can0_Tx_Interrupt,
         &pduInfo);
    }

    /* End of Outputs for S-Function (fcgen): '<Root>/1000ms1' */
  }

  /* S-Function (fcgen): '<Root>/10ms1' incorporates:
   *  SubSystem: '<Root>/Subsystem8'
   */
  /* DataTypeConversion: '<S14>/Data Type Conversion4' */
  RBCM_Model_B.DataTypeConversion4 =
    RBCM_Model_B.OutportBufferForDrsDriveCommand;

  /* S-Function (s32k3_pwm): '<S14>/Pwm' */
  Pwm_SetDutyCycle(PwmChannel_0, RBCM_Model_B.DataTypeConversion4);

  /* End of Outputs for S-Function (fcgen): '<Root>/10ms1' */

  /* BusCreator: '<Root>/Bus Creator1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant13'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant6'
   *  Delay: '<Root>/Delay'
   *  S-Function (sfix_bitop): '<Root>/Bitwise AND'
   */
  RBCM_Model_DW.Delay_DSTATE.Extended = RBCM_Model_P.Constant4_Value_b;
  RBCM_Model_DW.Delay_DSTATE.Length = RBCM_Model_B.Length;
  RBCM_Model_DW.Delay_DSTATE.Remote = RBCM_Model_P.Constant6_Value_e;
  RBCM_Model_DW.Delay_DSTATE.Error = RBCM_Model_P.Constant13_Value_d;
  RBCM_Model_DW.Delay_DSTATE.ID = RBCM_Model_B.ID &
    RBCM_Model_P.BitwiseAND_BitMask;
  RBCM_Model_DW.Delay_DSTATE.Timestamp = RBCM_Model_P.Constant_Value;
  for (i = 0; i < 8; i++) {
    RBCM_Model_DW.Delay_DSTATE.Data[i] = RBCM_Model_B.Data[i];
  }

  /* End of BusCreator: '<Root>/Bus Creator1' */

  /* S-Function (s32k3_uart): '<Root>/Uart1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  RBCM_Model_B.Uart1_o2 = Uart_AsyncReceive(0, &RBCM_Model_B.Uart1_o1[0],
    RBCM_Model_P.Constant1_Value_o);

  /* End of Outputs for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler1' */

  /* End of Outputs for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler2' */

  /* End of Outputs for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler5' */

  /* S-Function (s32k3_adc): '<Root>/Adc1' */
  Adc_StartGroupConversion(Adc1Group_1);

  /* S-Function (s32k3_adc): '<Root>/Adc2' */
  Adc_StartGroupConversion(Adc2Group_1);

  /* S-Function (s32k3_adc): '<Root>/Adc3' */
  Adc_StartGroupConversion(Adc0Group_1);
  if (RBCM_Model_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.05, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    RBCM_Model_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void RBCM_Model_initialize(void)
{
  {
    int32_T i;
    uint16_T Adc0Group1_ResultBuffer[6];
    uint16_T Adc2Group1_ResultBuffer[5];
    uint16_T Adc1Group1_ResultBuffer_idx_0;
    uint16_T Adc1Group1_ResultBuffer_idx_1;
    uint16_T Adc1Group1_ResultBuffer_idx_2;
    boolean_T rtb_A;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    RBCM_Model_DW.Temp_AdcBuffer = RBCM_Model_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    RBCM_Model_DW.Bats_Monitor_AdcBuffer[0] =
      RBCM_Model_P.DataStoreMemory4_InitialValue[0];
    RBCM_Model_DW.Bats_Monitor_AdcBuffer[1] =
      RBCM_Model_P.DataStoreMemory4_InitialValue[1];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    for (i = 0; i < 6; i++) {
      RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[i] =
        RBCM_Model_P.DataStoreMemory5_InitialValue[i];
    }

    /* End of Start for DataStoreMemory: '<Root>/Data Store Memory5' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    for (i = 0; i < 5; i++) {
      RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[i] =
        RBCM_Model_P.DataStoreMemory6_InitialValue[i];
    }

    /* End of Start for DataStoreMemory: '<Root>/Data Store Memory6' */

    /* Start for S-Function (s32k3_fm_config): '<Root>/FreeMASTER Config' */
    init_freemaster_lpuart();
    FMSTR_Init();

    /* Start for DataStoreMemory: '<Root>/RGBLED0state' */
    RBCM_Model_DW.RGBLED0state[0] = RBCM_Model_P.RGBLED0state_InitialValue[0];
    RBCM_Model_DW.RGBLED0state[1] = RBCM_Model_P.RGBLED0state_InitialValue[1];
    RBCM_Model_DW.RGBLED0state[2] = RBCM_Model_P.RGBLED0state_InitialValue[2];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    for (i = 0; i < 6; i++) {
      Adc0Group1_ResultBuffer[i] = RBCM_Model_P.DataStoreMemory1_InitialValue[i];
    }

    /* End of Start for DataStoreMemory: '<Root>/Data Store Memory1' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    Adc1Group1_ResultBuffer_idx_0 = RBCM_Model_P.DataStoreMemory7_InitialValue[0];
    Adc1Group1_ResultBuffer_idx_1 = RBCM_Model_P.DataStoreMemory7_InitialValue[1];
    Adc1Group1_ResultBuffer_idx_2 = RBCM_Model_P.DataStoreMemory7_InitialValue[2];

    /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
    for (i = 0; i < 5; i++) {
      Adc2Group1_ResultBuffer[i] = RBCM_Model_P.DataStoreMemory8_InitialValue[i];
    }

    /* End of Start for DataStoreMemory: '<Root>/Data Store Memory8' */

    /* InitializeConditions for Delay: '<Root>/Delay' */
    RBCM_Model_DW.Delay_DSTATE = RBCM_Model_P.Delay_InitialCondition;

    /* SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler4' incorporates:
     *  SubSystem: '<Root>/指令报文解码器'
     */
    RBCM_Model_u_p_Init();

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler4' */

    /* SystemInitialize for S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/HSD诊断分析子系统'
     */
    /* SystemInitialize for MATLAB Function: '<S1>/触发器1' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_o,
                        &RBCM_Model_P.sf_1_o);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器10' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_g,
                       &RBCM_Model_P.sf_10_a);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器11' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_l,
                       &RBCM_Model_P.sf_11_a);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器2' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_du,
                        &RBCM_Model_P.sf_2_l);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器3' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_a4,
                        &RBCM_Model_P.sf_3_c);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器4' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_m3,
                        &RBCM_Model_P.sf_4_a);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器5' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_m,
                        &RBCM_Model_P.sf_5_c);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器6' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_b, &RBCM_Model_P.sf_6_o);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器7' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_d, &RBCM_Model_P.sf_7_p);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器8' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_a, &RBCM_Model_P.sf_8_j);

    /* SystemInitialize for MATLAB Function: '<S1>/触发器9' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1, &RBCM_Model_P.sf_9_a);

    /* SystemInitialize for S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/HSD驱动子系统'
     */
    /* SystemInitialize for S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem6'
     */
    RBCM_Model_Subsystem6_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<Root>/50ms1' */

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem7'
     */
    /* SystemInitialize for Chart: '<S13>/Chart2' */
    RBCM_Model_Chart2_Init(&rtb_A);

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/核心状态信息发送'
     */
    /* SystemInitialize for Chart: '<S17>/Chart1' */
    RBCM_Model_Chart2_Init(&rtb_A);

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/错误码数据发送(未)'
     */

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler1' */

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler2' */

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler5' */
    /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
    for (i = 0; i < 6; i++) {
      /* DataStoreRead: '<S6>/Data Store Read' */
      RBCM_Model_B.DataStoreRead[i] = Adc0Group1_ResultBuffer[i];
    }

    /* S-Function (s32k3_adc): '<S6>/Adc' */
    RBCM_Model_B.Adc = Adc_SetupResultBuffer(Adc0Group_1,
      &RBCM_Model_B.DataStoreRead[0]);
    Adc0Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead[0];
    Adc0Group_1_ResultBufferLength = 6;

    /* DataStoreRead: '<S6>/Data Store Read1' */
    RBCM_Model_B.DataStoreRead1[0] = Adc1Group1_ResultBuffer_idx_0;
    RBCM_Model_B.DataStoreRead1[1] = Adc1Group1_ResultBuffer_idx_1;
    RBCM_Model_B.DataStoreRead1[2] = Adc1Group1_ResultBuffer_idx_2;

    /* S-Function (s32k3_adc): '<S6>/Adc2' */
    RBCM_Model_B.Adc2 = Adc_SetupResultBuffer(Adc1Group_1,
      &RBCM_Model_B.DataStoreRead1[0]);
    Adc1Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead1[0];
    Adc1Group_1_ResultBufferLength = 3;
    for (i = 0; i < 5; i++) {
      /* DataStoreRead: '<S6>/Data Store Read2' */
      RBCM_Model_B.DataStoreRead2[i] = Adc2Group1_ResultBuffer[i];
    }

    /* S-Function (s32k3_adc): '<S6>/Adc4' */
    RBCM_Model_B.Adc4 = Adc_SetupResultBuffer(Adc2Group_1,
      &RBCM_Model_B.DataStoreRead2[0]);
    Adc2Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead2[0];
    Adc2Group_1_ResultBufferLength = 5;

    /* S-Function (s32k3_can): '<S6>/Can' */
    RBCM_Model_B.Can = Can_43_FLEXCAN_SetControllerMode
      (Can_43_FLEXCANConf_CanController_CanController_0, CAN_CS_STARTED);

    /* S-Function (s32k3_dio): '<S6>/Dio10' incorporates:
     *  Constant: '<S6>/Constant10'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant10_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio11' incorporates:
     *  Constant: '<S6>/Constant11'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant11_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio12' incorporates:
     *  Constant: '<S6>/Constant12'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant12_Value_c);

    /* S-Function (s32k3_dio): '<S6>/Dio13' incorporates:
     *  Constant: '<S6>/Constant13'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant13_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio14' incorporates:
     *  Constant: '<S6>/Constant14'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant14_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio15' incorporates:
     *  Constant: '<S6>/Constant15'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant15_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio3' incorporates:
     *  Constant: '<S6>/Constant3'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant3_Value_d);

    /* S-Function (s32k3_dio): '<S6>/Dio4' incorporates:
     *  Constant: '<S6>/Constant4'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant4_Value_p);

    /* S-Function (s32k3_dio): '<S6>/Dio5' incorporates:
     *  Constant: '<S6>/Constant5'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant5_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio6' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant6_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio7' incorporates:
     *  Constant: '<S6>/Constant7'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant7_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio8' incorporates:
     *  Constant: '<S6>/Constant8'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant8_Value);

    /* S-Function (s32k3_dio): '<S6>/Dio9' incorporates:
     *  Constant: '<S6>/Constant9'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant9_Value);

    /* S-Function (s32k3_adc): '<S6>/Adc1' */
    Adc_EnableGroupNotification(Adc0Group_1);

    /* S-Function (s32k3_adc): '<S6>/Adc3' */
    Adc_EnableGroupNotification(Adc1Group_1);

    /* S-Function (s32k3_adc): '<S6>/Adc5' */
    Adc_EnableGroupNotification(Adc2Group_1);

    /* S-Function (s32k3_can): '<S6>/Can1' */
    Can_43_FLEXCAN_DisableControllerInterrupts
      (Can_43_FLEXCANConf_CanController_CanController_0);

    /* S-Function (s32k3_can): '<S6>/Can2' */
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
