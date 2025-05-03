/*
 * File: RBCM_Model.c
 *
 * Code generated for Simulink model 'RBCM_Model'.
 *
 * Model version                   : 1.76
 * Simulink Coder version          : 23.2 (R2023b) 01-Aug-2023
 * MBDT for S32K3 Series Version  :  Version 1.6.0 (R2021a-R2024b) 27-Jan-2025
 * C/C++ source code generated on  : Tue Apr 22 22:30:56 2025
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
#include <stdio.h>
#include <string.h>

/* Named constants for Chart: '<S16>/Chart2' */
#define RBCM_Model_IN_A                ((uint8_T)1U)
#define RBCM_Model_IN_A1               ((uint8_T)2U)
#define RBCM_Model_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)

/* Named constants for Chart: '<Root>/4G通信控制状态机1' */
#define RBCM_Model_IN_first            ((uint8_T)1U)
#define RBCM_Model_IN_fourth           ((uint8_T)2U)
#define RBCM_Model_IN_init             ((uint8_T)3U)
#define RBCM_Model_IN_msgsend          ((uint8_T)4U)
#define RBCM_Model_IN_second           ((uint8_T)5U)
#define RBCM_Model_IN_third            ((uint8_T)6U)

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

void MBDT_Uart_Callback (uint8 Channel, Uart_EventType Event)
{
  RBCM_Model_B.Hardware_Interrupt_Handler_o2 = Channel;
  RBCM_Model_B.u = Event;
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

  /* S-Function (s32k3_adc): '<S9>/Adc1' */
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

  /* DataStoreWrite: '<S9>/Data Store Write1' */
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[1] = RBCM_Model_B.Adc1_o3_l[3];
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[3] = RBCM_Model_B.Adc1_o3_l[4];
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[4] = RBCM_Model_B.Adc1_o3_l[5];

  /* DataStoreWrite: '<S9>/Data Store Write2' */
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[0] = RBCM_Model_B.Adc1_o3_l[0];
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[1] = RBCM_Model_B.Adc1_o3_l[1];
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[4] = RBCM_Model_B.Adc1_o3_l[2];
}

void Adc_Adc1Group1Notification (void)
{
  /* Output and update for function-call system: '<Root>/Subsystem11' */

  /* S-Function (s32k3_adc): '<S11>/Adc1' */
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

  /* DataStoreWrite: '<S11>/Data Store Write' */
  RBCM_Model_DW.Temp_AdcBuffer = RBCM_Model_B.Adc1_o3_a[0];

  /* DataStoreWrite: '<S11>/Data Store Write1' */
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[5] = RBCM_Model_B.Adc1_o3_a[2];

  /* DataStoreWrite: '<S11>/Data Store Write2' */
  RBCM_Model_DW.lHsd_Diagnose_AdcBuffer[3] = RBCM_Model_B.Adc1_o3_a[1];
}

void Adc_Adc2Group1Notification (void)
{
  /* Output and update for function-call system: '<Root>/Subsystem12' */

  /* S-Function (s32k3_adc): '<S12>/Adc1' */
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

  /* DataStoreWrite: '<S12>/Data Store Write' */
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[0] = RBCM_Model_B.Adc1_o3[1];
  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer[2] = RBCM_Model_B.Adc1_o3[2];

  /* DataStoreWrite: '<S12>/Data Store Write1' */
  RBCM_Model_DW.Bats_Monitor_AdcBuffer[0] = RBCM_Model_B.Adc1_o3[3];
  RBCM_Model_DW.Bats_Monitor_AdcBuffer[1] = RBCM_Model_B.Adc1_o3[4];

  /* DataStoreWrite: '<S12>/Data Store Write2' */
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
 *    '<S16>/Chart2'
 *    '<S20>/Chart1'
 *    '<S18>/Chart1'
 */
void RBCM_Model_Chart2_Init(boolean_T *rty_A)
{
  *rty_A = false;
}

/*
 * System reset for atomic system:
 *    '<S16>/Chart2'
 *    '<S20>/Chart1'
 *    '<S18>/Chart1'
 */
void RBCM_Model_Chart2_Reset(boolean_T *rty_A, DW_Chart2_RBCM_Model_T *localDW)
{
  localDW->is_active_c7_RBCM_Model = 0U;
  localDW->is_c7_RBCM_Model = RBCM_Model_IN_NO_ACTIVE_CHILD;
  *rty_A = false;
}

/*
 * Output and update for atomic system:
 *    '<S16>/Chart2'
 *    '<S20>/Chart1'
 *    '<S18>/Chart1'
 */
void RBCM_Model_Chart2(boolean_T *rty_A, DW_Chart2_RBCM_Model_T *localDW)
{
  /* Chart: '<S16>/Chart2' */
  if (localDW->is_active_c7_RBCM_Model == 0U) {
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

  /* End of Chart: '<S16>/Chart2' */
}

/*
 * Output and update for atomic system:
 *    '<S2>/数据转存单元1'
 *    '<S2>/数据转存单元10'
 *    '<S2>/数据转存单元2'
 *    '<S2>/数据转存单元4'
 *    '<S2>/数据转存单元6'
 *    '<S2>/数据转存单元8'
 */
void RBCM_Model_u(uint8_T rtu_index, uint8_T rtu_u, uint8_T *rty_y1, uint8_T
                  *rty_y2, DW_u_RBCM_Model_T *localDW)
{
  switch (rtu_index) {
   case 0:
    localDW->Y1 = rtu_u;
    break;

   case 1:
    localDW->Y2 = rtu_u;
    break;
  }

  *rty_y1 = localDW->Y1;
  *rty_y2 = localDW->Y2;
}

/*
 * Output and update for atomic system:
 *    '<S2>/数据转存单元11'
 *    '<S2>/数据转存单元12'
 *    '<S2>/数据转存单元3'
 *    '<S2>/数据转存单元5'
 *    '<S2>/数据转存单元7'
 *    '<S2>/数据转存单元9'
 */
void RBCM_Model_u1(uint8_T rtu_index, uint16_T rtu_u, uint16_T *rty_y1, uint16_T
                   *rty_y2, DW_u1_RBCM_Model_T *localDW)
{
  switch (rtu_index) {
   case 0:
    localDW->Y1 = rtu_u;
    break;

   case 1:
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
 *    '<S2>/触发器1'
 *    '<S2>/触发器2'
 *    '<S2>/触发器3'
 *    '<S2>/触发器4'
 *    '<S2>/触发器5'
 */
void RBCM_Model_u_a_Init(uint16_T *rty_1, P_u_RBCM_Model_e_T *localP)
{
  /* SystemInitialize for Function Call SubSystem: '<S2>/ADC采集与处理单元1' */
  /* SystemInitialize for Outport: '<S23>/u1' */
  *rty_1 = localP->u1_Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/ADC采集与处理单元1' */
}

/*
 * Output and update for atomic system:
 *    '<S2>/触发器1'
 *    '<S2>/触发器2'
 *    '<S2>/触发器3'
 *    '<S2>/触发器4'
 *    '<S2>/触发器5'
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

    /* Outputs for Function Call SubSystem: '<S2>/ADC采集与处理单元1' */
    /* DataTypeConversion: '<S23>/Data Type Conversion1' incorporates:
     *  Constant: '<S23>/ADC resolution'
     *  Constant: '<S23>/Ris'
     *  Constant: '<S23>/Vref'
     *  DataStoreRead: '<S23>/Data Store Read'
     *  DataTypeConversion: '<S23>/Data Type Conversion'
     *  Gain: '<S23>/Magnification'
     *  Product: '<S23>/Divide'
     *  Product: '<S23>/Product'
     *  Product: '<S23>/Product1'
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

    /* End of DataTypeConversion: '<S23>/Data Type Conversion1' */
    /* End of Outputs for SubSystem: '<S2>/ADC采集与处理单元1' */
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
 *    '<S2>/触发器10'
 *    '<S2>/触发器11'
 *    '<S2>/触发器6'
 *    '<S2>/触发器7'
 *    '<S2>/触发器8'
 *    '<S2>/触发器9'
 */
void RBCM_Model_u0_Init(uint16_T *rty_1, P_u0_RBCM_Model_T *localP)
{
  /* SystemInitialize for Function Call SubSystem: '<S2>/ADC采集与处理单元10' */
  /* SystemInitialize for Outport: '<S24>/u' */
  *rty_1 = localP->u_Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/ADC采集与处理单元10' */
}

/*
 * Output and update for atomic system:
 *    '<S2>/触发器10'
 *    '<S2>/触发器11'
 *    '<S2>/触发器6'
 *    '<S2>/触发器7'
 *    '<S2>/触发器8'
 *    '<S2>/触发器9'
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

    /* Outputs for Function Call SubSystem: '<S2>/ADC采集与处理单元10' */
    /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
     *  Constant: '<S24>/ADC resolution'
     *  Constant: '<S24>/Ris'
     *  Constant: '<S24>/Vref'
     *  DataStoreRead: '<S24>/Data Store Read'
     *  DataTypeConversion: '<S24>/Data Type Conversion'
     *  Gain: '<S24>/Magnification'
     *  Product: '<S24>/Divide'
     *  Product: '<S24>/Product'
     *  Product: '<S24>/Product1'
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

    /* End of DataTypeConversion: '<S24>/Data Type Conversion1' */
    /* End of Outputs for SubSystem: '<S2>/ADC采集与处理单元10' */
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
 *    '<S2>/诊断数据转存单元1'
 *    '<S2>/诊断数据转存单元2'
 *    '<S2>/诊断数据转存单元3'
 *    '<S2>/诊断数据转存单元4'
 *    '<S2>/诊断数据转存单元5'
 */
void RBCM_Model_u_k(uint8_T rtu_index, uint16_T rtu_u, uint16_T *rty_y1,
                    uint16_T *rty_y2, uint16_T *rty_y3, uint16_T *rty_y4,
                    DW_u_RBCM_Model_b_T *localDW)
{
  switch (rtu_index) {
   case 0:
    localDW->Y1 = rtu_u;
    break;

   case 1:
    localDW->Y2 = rtu_u;
    break;

   case 2:
    localDW->Y3 = rtu_u;
    break;

   case 3:
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
 *    '<S2>/错误码转存单元1'
 *    '<S2>/错误码转存单元10'
 *    '<S2>/错误码转存单元2'
 *    '<S2>/错误码转存单元3'
 *    '<S2>/错误码转存单元4'
 */
void RBCM_Model_u_g(uint8_T rtu_index, uint8_T rtu_u, uint8_T *rty_y1, uint8_T
                    *rty_y2, uint8_T *rty_y3, uint8_T *rty_y4,
                    DW_u_RBCM_Model_lj_T *localDW)
{
  switch (rtu_index) {
   case 0:
    localDW->Y1 = rtu_u;
    break;

   case 1:
    localDW->Y2 = rtu_u;
    break;

   case 2:
    localDW->Y3 = rtu_u;
    break;

   case 3:
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
  /* SystemInitialize for BusCreator: '<S15>/VbatsData' incorporates:
   *  Outport: '<S15>/Out2'
   */
  RBCM_Model_B.VbatsData = RBCM_Model_P.Out2_Y0_c;
}

/* Output and update for function-call system: '<Root>/Subsystem6' */
void RBCM_Model_Subsystem6(void)
{
  real32_T tmp;

  /* Gain: '<S15>/Magnification' incorporates:
   *  Constant: '<S15>/ADC resolution'
   *  Constant: '<S15>/Vref'
   *  DataStoreRead: '<S15>/Data Store Read'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   */
  tmp = floorf((real32_T)RBCM_Model_DW.Bats_Monitor_AdcBuffer[0] * (real32_T)
               RBCM_Model_P.ADCresolution_Value * (real32_T)
               RBCM_Model_P.Vref_Value * RBCM_Model_P.Magnification_Gain);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  /* BusCreator: '<S15>/VbatsData' incorporates:
   *  Gain: '<S15>/Magnification'
   */
  RBCM_Model_B.VbatsData.LvBatsV = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* Gain: '<S15>/Magnification1' incorporates:
   *  Constant: '<S15>/ADC resolution1'
   *  Constant: '<S15>/Vref1'
   *  DataStoreRead: '<S15>/Data Store Read'
   *  DataTypeConversion: '<S15>/Data Type Conversion1'
   *  Product: '<S15>/Product2'
   *  Product: '<S15>/Product3'
   */
  tmp = floorf((real32_T)RBCM_Model_DW.Bats_Monitor_AdcBuffer[1] * (real32_T)
               RBCM_Model_P.ADCresolution1_Value * (real32_T)
               RBCM_Model_P.Vref1_Value * RBCM_Model_P.Magnification1_Gain);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  /* BusCreator: '<S15>/VbatsData' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  Gain: '<S15>/Magnification1'
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

  /* Start for S-Function (scanunpack): '<S106>/CAN Unpack' */

  /*-----------S-Function Block: <S106>/CAN Unpack -----------------*/

  /* SystemInitialize for Chart: '<S18>/Chart1' */
  RBCM_Model_Chart2_Init(&rtb_A);

  /* SystemInitialize for SignalConversion generated from: '<S18>/DrsDriveCommand' incorporates:
   *  Constant: '<S106>/Constant12'
   */
  RBCM_Model_B.OutportBufferForDrsDriveCommand = RBCM_Model_P.Constant12_Value;

  /* SystemInitialize for BusCreator: '<S106>/VehicleData' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S106>/Constant1'
   *  Constant: '<S106>/Constant10'
   *  Constant: '<S106>/Constant11'
   *  Constant: '<S106>/Constant2'
   *  Constant: '<S106>/Constant3'
   *  Constant: '<S106>/Constant4'
   *  Constant: '<S106>/Constant5'
   *  Constant: '<S106>/Constant6'
   *  Constant: '<S106>/Constant7'
   *  Constant: '<S106>/Constant8'
   *  Constant: '<S106>/Constant9'
   */
  RBCM_Model_B.VehicleData.ActButtonState = RBCM_Model_P.Constant_Value_d;
  RBCM_Model_B.VehicleData.ReadyButtonState = RBCM_Model_P.Constant1_Value_dz;
  RBCM_Model_B.VehicleData.McuReadyState = RBCM_Model_P.Constant2_Value_dx;
  RBCM_Model_B.VehicleData.DriveReadyState = RBCM_Model_P.Constant3_Value_ct;
  RBCM_Model_B.VehicleData.AccuV = RBCM_Model_P.Constant4_Value_h;
  RBCM_Model_B.VehicleData.AccuI = RBCM_Model_P.Constant5_Value;
  RBCM_Model_B.VehicleData.AccuTcmax = RBCM_Model_P.Constant6_Value;
  RBCM_Model_B.VehicleData.AccudVmax = RBCM_Model_P.Constant7_Value;
  RBCM_Model_B.VehicleData.McuT = RBCM_Model_P.Constant8_Value;
  RBCM_Model_B.VehicleData.MotorRpm = RBCM_Model_P.Constant9_Value;
  RBCM_Model_B.VehicleData.MotorTorque = RBCM_Model_P.Constant10_Value;
  RBCM_Model_B.VehicleData.MotorTemp = RBCM_Model_P.Constant11_Value;

  /* SystemInitialize for BusAssignment: '<S106>/HsdDriveCommandsCAN' incorporates:
   *  Outport: '<S18>/HsdDriveCommands'
   */
  RBCM_Model_B.HsdDriveCommandsCAN = RBCM_Model_P.HsdDriveCommands_Y0;
}

/* System reset for function-call system: '<Root>/指令报文解码器' */
void RBCM_Model_u_o_Reset(void)
{
  boolean_T rtb_A;

  /* SystemReset for Chart: '<S18>/Chart1' */
  RBCM_Model_Chart2_Reset(&rtb_A, &RBCM_Model_DW.sf_Chart1_o);
}

/* Output and update for function-call system: '<Root>/指令报文解码器' */
void RBCM_Model_u_k4(void)
{
  boolean_T rtb_A;

  /* Chart: '<S18>/Chart1' */
  RBCM_Model_Chart2(&rtb_A, &RBCM_Model_DW.sf_Chart1_o);

  /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion13'
   */
  RBCM_Model_DW.RGBLED0state[1] = rtb_A;

  /* SignalConversion generated from: '<S18>/DrsDriveCommand' incorporates:
   *  Constant: '<S106>/Constant12'
   */
  RBCM_Model_B.OutportBufferForDrsDriveCommand = RBCM_Model_P.Constant12_Value;

  /* S-Function (scanunpack): '<S106>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<S106>/CAN Unpack' */
    if ((8 == RBCM_Model_B.Delay.Length) && (RBCM_Model_B.Delay.ID !=
         INVALID_CAN_ID) ) {
      if ((514 == RBCM_Model_B.Delay.ID) && (1U == RBCM_Model_B.Delay.Extended) )
      {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 4
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
                    (RBCM_Model_B.Delay.Data[0]) & (uint8_T)(0x30U)) >> 4);
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
           *  startBit                = 6
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
                    (RBCM_Model_B.Delay.Data[0]) & (uint8_T)(0xC0U)) >> 6);
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
              RBCM_Model_B.CANUnpack_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
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
              RBCM_Model_B.CANUnpack_o7 = result;
            }
          }
        }
      }
    }
  }

  /* BusAssignment: '<S106>/HsdDriveCommandsCAN' */
  RBCM_Model_B.HsdDriveCommandsCAN = RBCM_Model_B.HsdDriveCommandsInit;

  /* BusAssignment: '<S106>/HsdDriveCommandsCAN' */
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

  /* BusCreator: '<S106>/VehicleData' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S106>/Constant1'
   *  Constant: '<S106>/Constant10'
   *  Constant: '<S106>/Constant11'
   *  Constant: '<S106>/Constant2'
   *  Constant: '<S106>/Constant3'
   *  Constant: '<S106>/Constant4'
   *  Constant: '<S106>/Constant5'
   *  Constant: '<S106>/Constant6'
   *  Constant: '<S106>/Constant7'
   *  Constant: '<S106>/Constant8'
   *  Constant: '<S106>/Constant9'
   */
  RBCM_Model_B.VehicleData.ActButtonState = RBCM_Model_P.Constant_Value_d;
  RBCM_Model_B.VehicleData.ReadyButtonState = RBCM_Model_P.Constant1_Value_dz;
  RBCM_Model_B.VehicleData.McuReadyState = RBCM_Model_P.Constant2_Value_dx;
  RBCM_Model_B.VehicleData.DriveReadyState = RBCM_Model_P.Constant3_Value_ct;
  RBCM_Model_B.VehicleData.AccuV = RBCM_Model_P.Constant4_Value_h;
  RBCM_Model_B.VehicleData.AccuI = RBCM_Model_P.Constant5_Value;
  RBCM_Model_B.VehicleData.AccuTcmax = RBCM_Model_P.Constant6_Value;
  RBCM_Model_B.VehicleData.AccudVmax = RBCM_Model_P.Constant7_Value;
  RBCM_Model_B.VehicleData.McuT = RBCM_Model_P.Constant8_Value;
  RBCM_Model_B.VehicleData.MotorRpm = RBCM_Model_P.Constant9_Value;
  RBCM_Model_B.VehicleData.MotorTorque = RBCM_Model_P.Constant10_Value;
  RBCM_Model_B.VehicleData.MotorTemp = RBCM_Model_P.Constant11_Value;
}

/* Model step function */
void RBCM_Model_step(void)
{
  real_T rtb_Step2;
  int32_T i;
  uint32_T tmp;
  uint16_T rtb_y1;
  uint16_T rtb_y1_c;
  uint16_T rtb_y2;
  uint16_T rtb_y2_d0;
  uint8_T rtb_MultiportSwitch;
  uint8_T rtb_TmpRTBAtInport2;
  uint8_T rtb_y;
  uint8_T rtb_y1_i;
  uint8_T rtb_y2_l;
  uint8_T rtb_y_a;
  uint8_T rtb_y_h;
  uint8_T rtb_y_k;
  boolean_T rtb_A;
  if (RBCM_Model_M->Timing.TaskCounters.TID[1] == 0) {
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
  if (RBCM_Model_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S13>/If' */
    if (rtb_Step2 > 0.0) {
      /* Outputs for IfAction SubSystem: '<S13>/Subsystem13' incorporates:
       *  ActionPort: '<S101>/Action Port'
       */
      /* Merge: '<S13>/HsdDriveCommands' incorporates:
       *  SignalConversion generated from: '<S101>/In1'
       */
      RBCM_Model_B.HsdDriveCommands = RBCM_Model_B.HsdDriveCommandsCAN;

      /* End of Outputs for SubSystem: '<S13>/Subsystem13' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/Subsystem' incorporates:
       *  ActionPort: '<S100>/Action Port'
       */
      /* Merge: '<S13>/HsdDriveCommands' incorporates:
       *  MATLAB Function: '<S100>/HsdDriveCommand Struct1'
       *  SignalConversion generated from: '<S100>/y'
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

      /* End of Outputs for SubSystem: '<S13>/Subsystem' */
    }

    /* End of If: '<S13>/If' */

    /* S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/HSD诊断分析子系统'
     */
    /* S-Function (s32k3_dio): '<S35>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_k);

    /* S-Function (s32k3_dio): '<S36>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_c);

    /* S-Function (s32k3_dio): '<S37>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_l);

    /* S-Function (s32k3_dio): '<S38>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_h);

    /* S-Function (s32k3_dio): '<S39>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.y_l0);

    /* S-Function (s32k3_dio): '<S40>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2);

    /* S-Function (s32k3_dio): '<S40>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1);

    /* MATLAB Function: '<S2>/触发器1' incorporates:
     *  Constant: '<S2>/输出通道数1'
     *  Constant: '<S2>/预分频值1'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value, RBCM_Model_P.u_Value_i, &rtb_y1_i,
                   &RBCM_Model_B.DataTypeConversion1_o,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_1_o,
                   &RBCM_Model_P.sf_1_o);

    /* S-Function (sfix_bitop): '<S40>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2 = (uint8_T)(rtb_y1_i &
      RBCM_Model_P.BitwiseAND2_BitMask);

    /* ArithShift: '<S40>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S40>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1 = (uint8_T)((uint32_T)(rtb_y1_i &
      RBCM_Model_P.BitwiseAND3_BitMask) >> 1);

    /* S-Function (s32k3_dio): '<S41>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2_h);

    /* S-Function (s32k3_dio): '<S41>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_c);

    /* MATLAB Function: '<S2>/触发器2' incorporates:
     *  Constant: '<S2>/输出通道数2'
     *  Constant: '<S2>/预分频值2'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_n, RBCM_Model_P.u_Value_k, &rtb_y2_l,
                   &RBCM_Model_B.DataTypeConversion1_du,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_2_l,
                   &RBCM_Model_P.sf_2_l);

    /* S-Function (sfix_bitop): '<S41>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_h = (uint8_T)(rtb_y2_l &
      RBCM_Model_P.BitwiseAND2_BitMask_f);

    /* ArithShift: '<S41>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S41>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_c = (uint8_T)((uint32_T)(rtb_y2_l &
      RBCM_Model_P.BitwiseAND3_BitMask_k) >> 1);

    /* S-Function (s32k3_dio): '<S42>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2_a);

    /* S-Function (s32k3_dio): '<S42>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_b);

    /* MATLAB Function: '<S2>/触发器3' incorporates:
     *  Constant: '<S2>/输出通道数3'
     *  Constant: '<S2>/预分频值3'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_a, RBCM_Model_P.u_Value_p, &rtb_y_h,
                   &RBCM_Model_B.DataTypeConversion1_a4,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_3_c,
                   &RBCM_Model_P.sf_3_c);

    /* S-Function (sfix_bitop): '<S42>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_a = (uint8_T)(rtb_y_h &
      RBCM_Model_P.BitwiseAND2_BitMask_i);

    /* ArithShift: '<S42>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S42>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_b = (uint8_T)((uint32_T)(rtb_y_h &
      RBCM_Model_P.BitwiseAND3_BitMask_kw) >> 1);

    /* S-Function (s32k3_dio): '<S43>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE, RBCM_Model_B.BitwiseAND2_d);

    /* S-Function (s32k3_dio): '<S43>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_n);

    /* MATLAB Function: '<S2>/触发器4' incorporates:
     *  Constant: '<S2>/输出通道数4'
     *  Constant: '<S2>/预分频值4'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_j, RBCM_Model_P.u_Value_m, &rtb_y_k,
                   &RBCM_Model_B.DataTypeConversion1_m3,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_4_a,
                   &RBCM_Model_P.sf_4_a);

    /* S-Function (sfix_bitop): '<S43>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_d = (uint8_T)(rtb_y_k &
      RBCM_Model_P.BitwiseAND2_BitMask_l);

    /* ArithShift: '<S43>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S43>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_n = (uint8_T)((uint32_T)(rtb_y_k &
      RBCM_Model_P.BitwiseAND3_BitMask_n) >> 1);

    /* S-Function (s32k3_dio): '<S44>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.BitwiseAND2_ht);

    /* S-Function (s32k3_dio): '<S44>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.ShiftArithmetic1_d);

    /* MATLAB Function: '<S2>/触发器5' incorporates:
     *  Constant: '<S2>/输出通道数5'
     *  Constant: '<S2>/预分频值5'
     */
    RBCM_Model_u_o(RBCM_Model_P.u_Value_l, RBCM_Model_P.u_Value_o, &rtb_y_a,
                   &RBCM_Model_B.DataTypeConversion1_m,
                   RBCM_Model_DW.lHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_5_c,
                   &RBCM_Model_P.sf_5_c);

    /* S-Function (sfix_bitop): '<S44>/Bitwise AND2' */
    RBCM_Model_B.BitwiseAND2_ht = (uint8_T)(rtb_y_a &
      RBCM_Model_P.BitwiseAND2_BitMask_h);

    /* ArithShift: '<S44>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S44>/Bitwise AND3'
     */
    RBCM_Model_B.ShiftArithmetic1_d = (uint8_T)((uint32_T)(rtb_y_a &
      RBCM_Model_P.BitwiseAND3_BitMask_b) >> 1);

    /* MATLAB Function: '<S2>/触发器10' incorporates:
     *  Constant: '<S2>/输出通道数10'
     *  Constant: '<S2>/预分频值10'
     */
    RBCM_Model_u0(RBCM_Model_P.u0_Value, RBCM_Model_P.u0_Value_a,
                  &RBCM_Model_B.y_l0, &RBCM_Model_B.DataTypeConversion1_g,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_10_a,
                  &RBCM_Model_P.sf_10_a);

    /* MATLAB Function: '<S2>/触发器11' incorporates:
     *  Constant: '<S2>/输出通道数11'
     *  Constant: '<S2>/预分频值11'
     */
    RBCM_Model_u0(RBCM_Model_P.u1_Value, RBCM_Model_P.u1_Value_n,
                  &RBCM_Model_B.y_k, &RBCM_Model_B.DataTypeConversion1_l,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_11_a,
                  &RBCM_Model_P.sf_11_a);

    /* MATLAB Function: '<S2>/触发器6' incorporates:
     *  Constant: '<S2>/输出通道数6'
     *  Constant: '<S2>/预分频值6'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_iv, RBCM_Model_P.u_Value_g, &rtb_y,
                  &RBCM_Model_B.DataTypeConversion1_b,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_6_o,
                  &RBCM_Model_P.sf_6_o);

    /* MATLAB Function: '<S2>/触发器7' incorporates:
     *  Constant: '<S2>/输出通道数7'
     *  Constant: '<S2>/预分频值7'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_gq, RBCM_Model_P.u_Value_lh,
                  &RBCM_Model_B.y_l, &RBCM_Model_B.DataTypeConversion1_d,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_7_p,
                  &RBCM_Model_P.sf_7_p);

    /* MATLAB Function: '<S2>/触发器8' incorporates:
     *  Constant: '<S2>/输出通道数8'
     *  Constant: '<S2>/预分频值8'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_h, RBCM_Model_P.u_Value_ku,
                  &RBCM_Model_B.y_c, &RBCM_Model_B.DataTypeConversion1_a,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_8_j,
                  &RBCM_Model_P.sf_8_j);

    /* MATLAB Function: '<S2>/触发器9' incorporates:
     *  Constant: '<S2>/输出通道数9'
     *  Constant: '<S2>/预分频值9'
     */
    RBCM_Model_u0(RBCM_Model_P.u_Value_al, RBCM_Model_P.u_Value_k3,
                  &RBCM_Model_B.y_h, &RBCM_Model_B.DataTypeConversion1,
                  RBCM_Model_DW.hHsd_Diagnose_AdcBuffer, &RBCM_Model_DW.sf_9_a,
                  &RBCM_Model_P.sf_9_a);

    /* BusAssignment: '<S2>/Bus Assignment' incorporates:
     *  MATLAB Function: '<S2>/诊断数据转存单元1'
     */
    RBCM_Model_u_k(rtb_y1_i, RBCM_Model_B.DataTypeConversion1_o,
                   &RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseValues.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseValues.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseValues.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_1_k);

    /* BusAssignment: '<S2>/BusHsdDiagnoseValues' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  MATLAB Function: '<Root>/MATLAB Function'
     */
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_12v_lHsd2ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.VcuPwr_lHsd2ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.Fireon_Pwr_lHsd2ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DsbdPwr_lHsd2ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DrsPwr_8v_lHsd3ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_lHsd3ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.BuzzerPwr_lHsd3ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.TaillightPwr_lHsd3ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_5v_lHsd4ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.AccuUbr_lHsd4ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.AccuPwr_lHsd4ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.BduPwr_lHsd4ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_5v_lHsd5ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.McuUbr_lHsd5ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.EnergeMeterPwr_lHsd5ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.TsalrPwr_lHsd5ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.VcuUbr_hHsd2ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.Device_hHsd2ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.PumpPwr_hHsd3ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.AccuFanPwr_hHsd3ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.PumpFan1_hHsd4ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.PumpFan2_hHsd4ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd5ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd5ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd6ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd6ch2 = 0U;

    /* MultiPortSwitch: '<S45>/Multiport Switch' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant2'
     *  Constant: '<S45>/Constant3'
     *  Constant: '<S45>/Constant4'
     *  Gain: '<S45>/Gain'
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

    /* End of MultiPortSwitch: '<S45>/Multiport Switch' */

    /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
     *  MATLAB Function: '<S2>/错误码转存单元10'
     */
    RBCM_Model_u_g(rtb_y1_i, rtb_MultiportSwitch,
                   &RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseResults.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseResults.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseResults.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_10_o);

    /* BusAssignment: '<S2>/BusHsdDiagnoseResults' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment1'
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_12v_lHsd2ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.VcuPwr_lHsd2ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.Fireon_Pwr_lHsd2ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DsbdPwr_lHsd2ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DrsPwr_8v_lHsd3ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_lHsd3ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.BuzzerPwr_lHsd3ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.TaillightPwr_lHsd3ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_5v_lHsd4ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.AccuUbr_lHsd4ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.AccuPwr_lHsd4ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.BduPwr_lHsd4ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_5v_lHsd5ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.McuUbr_lHsd5ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.EnergeMeterPwr_lHsd5ch3 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.TsalrPwr_lHsd5ch4 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.VcuUbr_hHsd2ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.Device_hHsd2ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.PumpPwr_hHsd3ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.AccuFanPwr_hHsd3ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.PumpFan1_hHsd4ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.PumpFan2_hHsd4ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd5ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd5ch2 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd6ch1 = 0U;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd6ch2 = 0U;

    /* BusAssignment: '<S2>/Bus Assignment2' incorporates:
     *  MATLAB Function: '<S2>/诊断数据转存单元2'
     */
    RBCM_Model_u_k(rtb_y2_l, RBCM_Model_B.DataTypeConversion1_du,
                   &RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseValues.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseValues.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseValues.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_2_p);

    /* BusAssignment: '<S2>/Bus Assignment4' incorporates:
     *  MATLAB Function: '<S2>/诊断数据转存单元3'
     */
    RBCM_Model_u_k(rtb_y_h, RBCM_Model_B.DataTypeConversion1_a4,
                   &RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseValues.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseValues.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseValues.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_3_k);

    /* BusAssignment: '<S2>/Bus Assignment6' incorporates:
     *  MATLAB Function: '<S2>/诊断数据转存单元4'
     */
    RBCM_Model_u_k(rtb_y_k, RBCM_Model_B.DataTypeConversion1_m3,
                   &RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseValues.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseValues.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseValues.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_4_k);

    /* MATLAB Function: '<S2>/诊断数据转存单元5' */
    RBCM_Model_u_k(rtb_y_a, RBCM_Model_B.DataTypeConversion1_m, &rtb_y1, &rtb_y2,
                   &rtb_y2_d0, &rtb_y1_c, &RBCM_Model_DW.sf_5_d);

    /* BusAssignment: '<S2>/Bus Assignment8' */
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_12v_lHsd1ch1 = rtb_y1;
    RBCM_Model_B.BusHsdDiagnoseValues.BspdPwr_lHsd1ch2 = rtb_y2;
    RBCM_Model_B.BusHsdDiagnoseValues.LoggerPwr_lHsd1ch3 = rtb_y2_d0;
    RBCM_Model_B.BusHsdDiagnoseValues.TempSensorPwr_lHsd1ch4 = rtb_y1_c;

    /* MATLAB Function: '<S2>/数据转存单元11' */
    RBCM_Model_u1(RBCM_Model_B.y_k, RBCM_Model_B.DataTypeConversion1_l,
                  &rtb_y1_c, &rtb_y2_d0, &RBCM_Model_DW.sf_11);

    /* BusAssignment: '<S2>/Bus Assignment10' */
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = rtb_y1_c;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = rtb_y2_d0;

    /* MultiPortSwitch: '<S48>/Multiport Switch' incorporates:
     *  Constant: '<S48>/Constant'
     *  Constant: '<S48>/Constant2'
     *  Constant: '<S48>/Constant3'
     *  Constant: '<S48>/Constant4'
     *  Gain: '<S48>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_d *
             RBCM_Model_B.DataTypeConversion1_du) >> 9) {
     case 0:
      rtb_y1_i = RBCM_Model_P.Constant2_Value_c;
      break;

     case 5:
      rtb_y1_i = RBCM_Model_P.Constant3_Value_k;
      break;

     case 90:
      rtb_y1_i = RBCM_Model_P.Constant4_Value_o;
      break;

     default:
      rtb_y1_i = RBCM_Model_P.Constant_Value_ku;
      break;
    }

    /* End of MultiPortSwitch: '<S48>/Multiport Switch' */

    /* BusAssignment: '<S2>/Bus Assignment3' incorporates:
     *  MATLAB Function: '<S2>/错误码转存单元1'
     */
    RBCM_Model_u_g(rtb_y2_l, rtb_y1_i,
                   &RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseResults.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseResults.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseResults.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_1_g);

    /* MultiPortSwitch: '<S49>/Multiport Switch' incorporates:
     *  Constant: '<S49>/Constant'
     *  Constant: '<S49>/Constant2'
     *  Constant: '<S49>/Constant3'
     *  Constant: '<S49>/Constant4'
     *  Gain: '<S49>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_b *
             RBCM_Model_B.DataTypeConversion1_a4) >> 9) {
     case 0:
      rtb_y2_l = RBCM_Model_P.Constant2_Value_m;
      break;

     case 5:
      rtb_y2_l = RBCM_Model_P.Constant3_Value_ca;
      break;

     case 90:
      rtb_y2_l = RBCM_Model_P.Constant4_Value_a;
      break;

     default:
      rtb_y2_l = RBCM_Model_P.Constant_Value_j0;
      break;
    }

    /* End of MultiPortSwitch: '<S49>/Multiport Switch' */

    /* BusAssignment: '<S2>/Bus Assignment5' incorporates:
     *  MATLAB Function: '<S2>/错误码转存单元3'
     */
    RBCM_Model_u_g(rtb_y_h, rtb_y2_l,
                   &RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseResults.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseResults.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseResults.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_3_b);

    /* MultiPortSwitch: '<S50>/Multiport Switch' incorporates:
     *  Constant: '<S50>/Constant'
     *  Constant: '<S50>/Constant2'
     *  Constant: '<S50>/Constant3'
     *  Constant: '<S50>/Constant4'
     *  Gain: '<S50>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_c *
             RBCM_Model_B.DataTypeConversion1_m3) >> 9) {
     case 0:
      rtb_y2_l = RBCM_Model_P.Constant2_Value_py;
      break;

     case 5:
      rtb_y2_l = RBCM_Model_P.Constant3_Value_ax;
      break;

     case 90:
      rtb_y2_l = RBCM_Model_P.Constant4_Value_l;
      break;

     default:
      rtb_y2_l = RBCM_Model_P.Constant_Value_p;
      break;
    }

    /* End of MultiPortSwitch: '<S50>/Multiport Switch' */

    /* BusAssignment: '<S2>/Bus Assignment7' incorporates:
     *  MATLAB Function: '<S2>/错误码转存单元2'
     */
    RBCM_Model_u_g(rtb_y_k, rtb_y2_l,
                   &RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_12v_lHsd1ch1,
                   &RBCM_Model_B.BusHsdDiagnoseResults.BspdPwr_lHsd1ch2,
                   &RBCM_Model_B.BusHsdDiagnoseResults.LoggerPwr_lHsd1ch3,
                   &RBCM_Model_B.BusHsdDiagnoseResults.TempSensorPwr_lHsd1ch4,
                   &RBCM_Model_DW.sf_2_o);

    /* MultiPortSwitch: '<S51>/Multiport Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  Constant: '<S51>/Constant2'
     *  Constant: '<S51>/Constant3'
     *  Constant: '<S51>/Constant4'
     *  Gain: '<S51>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_k *
             RBCM_Model_B.DataTypeConversion1_m) >> 9) {
     case 0:
      rtb_y2_l = RBCM_Model_P.Constant2_Value_kb;
      break;

     case 5:
      rtb_y2_l = RBCM_Model_P.Constant3_Value_aq;
      break;

     case 90:
      rtb_y2_l = RBCM_Model_P.Constant4_Value_nh;
      break;

     default:
      rtb_y2_l = RBCM_Model_P.Constant_Value_m;
      break;
    }

    /* End of MultiPortSwitch: '<S51>/Multiport Switch' */

    /* MATLAB Function: '<S2>/错误码转存单元4' */
    RBCM_Model_u_g(rtb_y_a, rtb_y2_l, &rtb_y1_i, &rtb_y_k, &rtb_y_h,
                   &rtb_MultiportSwitch, &RBCM_Model_DW.sf_4_c);

    /* BusAssignment: '<S2>/Bus Assignment9' */
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_12v_lHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.BspdPwr_lHsd1ch2 = rtb_y_k;
    RBCM_Model_B.BusHsdDiagnoseResults.LoggerPwr_lHsd1ch3 = rtb_y_h;
    RBCM_Model_B.BusHsdDiagnoseResults.TempSensorPwr_lHsd1ch4 =
      rtb_MultiportSwitch;

    /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S46>/Constant2'
     *  Constant: '<S46>/Constant3'
     *  Constant: '<S46>/Constant4'
     *  Gain: '<S46>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_l *
             RBCM_Model_B.DataTypeConversion1_l) >> 9) {
     case 0:
      rtb_y_a = RBCM_Model_P.Constant2_Value_p;
      break;

     case 5:
      rtb_y_a = RBCM_Model_P.Constant3_Value_c;
      break;

     case 290:
      rtb_y_a = RBCM_Model_P.Constant4_Value_f;
      break;

     default:
      rtb_y_a = RBCM_Model_P.Constant_Value_c;
      break;
    }

    /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

    /* MATLAB Function: '<S2>/数据转存单元1' */
    RBCM_Model_u(RBCM_Model_B.y_k, rtb_y_a, &rtb_y1_i, &rtb_y2_l,
                 &RBCM_Model_DW.sf_1);

    /* BusAssignment: '<S2>/Bus Assignment11' */
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = rtb_y2_l;

    /* MATLAB Function: '<S2>/数据转存单元3' */
    RBCM_Model_u1(rtb_y, RBCM_Model_B.DataTypeConversion1_b, &rtb_y1_c,
                  &rtb_y2_d0, &RBCM_Model_DW.sf_3);

    /* BusAssignment: '<S2>/Bus Assignment12' */
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = rtb_y1_c;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = rtb_y2_d0;

    /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S52>/Constant2'
     *  Constant: '<S52>/Constant3'
     *  Constant: '<S52>/Constant4'
     *  Gain: '<S52>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_j *
             RBCM_Model_B.DataTypeConversion1_b) >> 9) {
     case 0:
      rtb_y_a = RBCM_Model_P.Constant2_Value_ct;
      break;

     case 5:
      rtb_y_a = RBCM_Model_P.Constant3_Value_f2;
      break;

     case 290:
      rtb_y_a = RBCM_Model_P.Constant4_Value_c;
      break;

     default:
      rtb_y_a = RBCM_Model_P.Constant_Value_op;
      break;
    }

    /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

    /* MATLAB Function: '<S2>/数据转存单元2' */
    RBCM_Model_u(rtb_y, rtb_y_a, &rtb_y1_i, &rtb_y2_l, &RBCM_Model_DW.sf_2);

    /* BusAssignment: '<S2>/Bus Assignment13' */
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = rtb_y2_l;

    /* MATLAB Function: '<S2>/数据转存单元5' */
    RBCM_Model_u1(RBCM_Model_B.y_l, RBCM_Model_B.DataTypeConversion1_d,
                  &rtb_y1_c, &rtb_y2_d0, &RBCM_Model_DW.sf_5);

    /* BusAssignment: '<S2>/Bus Assignment14' */
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = rtb_y1_c;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = rtb_y2_d0;

    /* MultiPortSwitch: '<S53>/Multiport Switch' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S53>/Constant2'
     *  Constant: '<S53>/Constant3'
     *  Constant: '<S53>/Constant4'
     *  Gain: '<S53>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_e *
             RBCM_Model_B.DataTypeConversion1_d) >> 9) {
     case 0:
      rtb_y = RBCM_Model_P.Constant2_Value_d;
      break;

     case 5:
      rtb_y = RBCM_Model_P.Constant3_Value_b;
      break;

     case 290:
      rtb_y = RBCM_Model_P.Constant4_Value_ce;
      break;

     default:
      rtb_y = RBCM_Model_P.Constant_Value_a;
      break;
    }

    /* End of MultiPortSwitch: '<S53>/Multiport Switch' */

    /* MATLAB Function: '<S2>/数据转存单元4' */
    RBCM_Model_u(RBCM_Model_B.y_l, rtb_y, &rtb_y1_i, &rtb_y2_l,
                 &RBCM_Model_DW.sf_4);

    /* BusAssignment: '<S2>/Bus Assignment15' */
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = rtb_y2_l;

    /* MATLAB Function: '<S2>/数据转存单元7' */
    RBCM_Model_u1(RBCM_Model_B.y_c, RBCM_Model_B.DataTypeConversion1_a,
                  &rtb_y1_c, &rtb_y2_d0, &RBCM_Model_DW.sf_7);

    /* BusAssignment: '<S2>/Bus Assignment16' */
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = rtb_y1_c;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = rtb_y2_d0;

    /* MultiPortSwitch: '<S54>/Multiport Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  Constant: '<S54>/Constant2'
     *  Constant: '<S54>/Constant3'
     *  Constant: '<S54>/Constant4'
     *  Gain: '<S54>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_lr *
             RBCM_Model_B.DataTypeConversion1_a) >> 9) {
     case 0:
      rtb_y = RBCM_Model_P.Constant2_Value_ke;
      break;

     case 5:
      rtb_y = RBCM_Model_P.Constant3_Value_kf;
      break;

     case 290:
      rtb_y = RBCM_Model_P.Constant4_Value_l4;
      break;

     default:
      rtb_y = RBCM_Model_P.Constant_Value_g;
      break;
    }

    /* End of MultiPortSwitch: '<S54>/Multiport Switch' */

    /* MATLAB Function: '<S2>/数据转存单元6' */
    RBCM_Model_u(RBCM_Model_B.y_c, rtb_y, &rtb_y1_i, &rtb_y2_l,
                 &RBCM_Model_DW.sf_6);

    /* BusAssignment: '<S2>/Bus Assignment17' */
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = rtb_y2_l;

    /* MATLAB Function: '<S2>/数据转存单元9' */
    RBCM_Model_u1(RBCM_Model_B.y_h, RBCM_Model_B.DataTypeConversion1, &rtb_y1_c,
                  &rtb_y2_d0, &RBCM_Model_DW.sf_9);

    /* BusAssignment: '<S2>/Bus Assignment18' */
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = rtb_y1_c;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = rtb_y2_d0;

    /* MultiPortSwitch: '<S55>/Multiport Switch' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S55>/Constant2'
     *  Constant: '<S55>/Constant3'
     *  Constant: '<S55>/Constant4'
     *  Gain: '<S55>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_n *
             RBCM_Model_B.DataTypeConversion1) >> 9) {
     case 0:
      rtb_y = RBCM_Model_P.Constant2_Value_a;
      break;

     case 5:
      rtb_y = RBCM_Model_P.Constant3_Value_e;
      break;

     case 290:
      rtb_y = RBCM_Model_P.Constant4_Value_mp;
      break;

     default:
      rtb_y = RBCM_Model_P.Constant_Value_i;
      break;
    }

    /* End of MultiPortSwitch: '<S55>/Multiport Switch' */

    /* MATLAB Function: '<S2>/数据转存单元8' */
    RBCM_Model_u(RBCM_Model_B.y_h, rtb_y, &rtb_y1_i, &rtb_y2_l,
                 &RBCM_Model_DW.sf_8);

    /* BusAssignment: '<S2>/Bus Assignment19' */
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = rtb_y2_l;

    /* MultiPortSwitch: '<S47>/Multiport Switch' incorporates:
     *  Constant: '<S47>/Constant'
     *  Constant: '<S47>/Constant2'
     *  Constant: '<S47>/Constant3'
     *  Constant: '<S47>/Constant4'
     *  Gain: '<S47>/Gain'
     */
    switch (((uint32_T)RBCM_Model_P.Gain_Gain_i *
             RBCM_Model_B.DataTypeConversion1_g) >> 9) {
     case 0:
      rtb_y = RBCM_Model_P.Constant2_Value_k;
      break;

     case 5:
      rtb_y = RBCM_Model_P.Constant3_Value_a;
      break;

     case 290:
      rtb_y = RBCM_Model_P.Constant4_Value_n;
      break;

     default:
      rtb_y = RBCM_Model_P.Constant_Value_c3;
      break;
    }

    /* End of MultiPortSwitch: '<S47>/Multiport Switch' */

    /* MATLAB Function: '<S2>/数据转存单元10' */
    RBCM_Model_u(RBCM_Model_B.y_l0, rtb_y, &rtb_y1_i, &rtb_y2_l,
                 &RBCM_Model_DW.sf_10);

    /* BusAssignment: '<S2>/BusHsdDiagnoseResults' */
    RBCM_Model_B.BusHsdDiagnoseResults.ILPwr_hHsd1ch1 = rtb_y1_i;
    RBCM_Model_B.BusHsdDiagnoseResults.DevicePwr_hHsd1ch2 = rtb_y2_l;

    /* MATLAB Function: '<S2>/数据转存单元12' */
    RBCM_Model_u1(RBCM_Model_B.y_l0, RBCM_Model_B.DataTypeConversion1_g,
                  &rtb_y1_c, &rtb_y2_d0, &RBCM_Model_DW.sf_12);

    /* BusAssignment: '<S2>/BusHsdDiagnoseValues' */
    RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1 = rtb_y1_c;
    RBCM_Model_B.BusHsdDiagnoseValues.DevicePwr_hHsd1ch2 = rtb_y2_d0;

    /* S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/HSD驱动子系统'
     */
    /* S-Function (s32k3_dio): '<S89>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd1ch2);

    /* S-Function (s32k3_dio): '<S90>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.VcuUbr_hHsd2ch1);

    /* S-Function (s32k3_dio): '<S90>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.Device_hHsd2ch2);

    /* S-Function (s32k3_dio): '<S91>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.PumpPwr_hHsd3ch1);

    /* S-Function (s32k3_dio): '<S91>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.AccuFanPwr_hHsd3ch2);

    /* S-Function (s32k3_dio): '<S92>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.PumpFan1_hHsd4ch1);

    /* S-Function (s32k3_dio): '<S92>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.PumpFan2_hHsd4ch2);

    /* S-Function (s32k3_dio): '<S93>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd5ch1);

    /* S-Function (s32k3_dio): '<S93>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd5ch2);

    /* S-Function (s32k3_dio): '<S94>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd6ch1);

    /* S-Function (s32k3_dio): '<S94>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_hHsd6ch2);

    /* S-Function (s32k3_dio): '<S95>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_12v_lHsd1ch1);

    /* S-Function (s32k3_dio): '<S95>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.BspdPwr_lHsd1ch2);

    /* S-Function (s32k3_dio): '<S95>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.LoggerPwr_lHsd1ch3);

    /* S-Function (s32k3_dio): '<S95>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.TempSensorPwr_lHsd1ch4);

    /* S-Function (s32k3_dio): '<S96>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_12v_lHsd2ch1);

    /* S-Function (s32k3_dio): '<S96>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.VcuPwr_lHsd2ch2);

    /* S-Function (s32k3_dio): '<S96>/Dio4' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.Fireon_Pwr_lHsd2ch3);

    /* S-Function (s32k3_dio): '<S96>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DsbdPwr_lHsd2ch4);

    /* S-Function (s32k3_dio): '<S97>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DrsPwr_8v_lHsd3ch1);

    /* S-Function (s32k3_dio): '<S97>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_lHsd3ch2);

    /* S-Function (s32k3_dio): '<S97>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.BuzzerPwr_lHsd3ch3);

    /* S-Function (s32k3_dio): '<S97>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.TaillightPwr_lHsd3ch4);

    /* S-Function (s32k3_dio): '<S98>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_5v_lHsd4ch1);

    /* S-Function (s32k3_dio): '<S98>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.AccuUbr_lHsd4ch2);

    /* S-Function (s32k3_dio): '<S98>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.AccuPwr_lHsd4ch3);

    /* S-Function (s32k3_dio): '<S98>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.BduPwr_lHsd4ch4);

    /* S-Function (s32k3_dio): '<S99>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.DevicePwr_5v_lHsd5ch1);

    /* S-Function (s32k3_dio): '<S99>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.McuUbr_lHsd5ch2);

    /* S-Function (s32k3_dio): '<S99>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.EnergeMeterPwr_lHsd5ch3);

    /* S-Function (s32k3_dio): '<S99>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.HsdDriveCommands.TsalrPwr_lHsd5ch4);

    /* S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem6'
     */
    RBCM_Model_Subsystem6();

    /* End of Outputs for S-Function (fcgen): '<Root>/50ms1' */

    /* RateTransition generated from: '<Root>/核心状态信息发送' */
    if (RBCM_Model_M->Timing.TaskCounters.TID[2] == 0) {
      RBCM_Model_DW.Bus_Vbats_Data_Buffer = RBCM_Model_B.VbatsData;
    }
  }

  /* End of RateTransition: '<Root>/RT1' */

  /* RateTransition generated from: '<Root>/核心状态信息发送' */
  if (RBCM_Model_M->Timing.TaskCounters.TID[2] == 0) {
    /* RateTransition generated from: '<Root>/核心状态信息发送' */
    RBCM_Model_B.Bus_Vbats_Data_j = RBCM_Model_DW.Bus_Vbats_Data_Buffer;

    /* RateTransition generated from: '<Root>/核心状态信息发送' */
    rtb_TmpRTBAtInport2 = RBCM_Model_B.OutportBufferForDrsDriveCommand;
  }

  if (RBCM_Model_M->Timing.TaskCounters.TID[1] == 0) {
    /* ComposeString: '<S5>/Compose String2' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     *  RateTransition: '<Root>/RT'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString2_m[0], 256U,
             "\"ActButtonState\":%d,\"ILValue\":%d,", (int32_T)
             RBCM_Model_B.VehicleData.ActButtonState, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.ILPwr_hHsd1ch1);

    /* ComposeString: '<S5>/Compose String3' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion2'
     *  DataTypeConversion: '<S5>/Data Type Conversion3'
     *  DataTypeConversion: '<S5>/Data Type Conversion4'
     *  RateTransition: '<Root>/RT'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString3_c[0], 256U,
             "\"ReadyButtonState\":%d,\"McuReadyState\":%d,\"DriveReadyState\":%d,",
             (int32_T)RBCM_Model_B.VehicleData.ReadyButtonState, (int32_T)
             RBCM_Model_B.VehicleData.McuReadyState, (int32_T)
             RBCM_Model_B.VehicleData.DriveReadyState);

    /* StringConcatenate: '<S5>/String Concatenate2' incorporates:
     *  ComposeString: '<S5>/Compose String2'
     *  ComposeString: '<S5>/Compose String3'
     */
    RBCM_Model_B.rtb_StringConcatenate2_k[0] = '\x00';
    strncat(&RBCM_Model_B.rtb_StringConcatenate2_k[0U],
            &RBCM_Model_B.rtb_ComposeString2_m[0], 255U);
    tmp = strlen(&RBCM_Model_B.rtb_StringConcatenate2_k[0U]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate2_k[tmp],
            &RBCM_Model_B.rtb_ComposeString3_c[0], 255U - tmp);

    /* MinMax: '<S5>/Max' */
    if (RBCM_Model_B.VbatsData.LvBatTemp1 >= RBCM_Model_B.VbatsData.LvBatTemp2)
    {
      rtb_y1 = RBCM_Model_B.VbatsData.LvBatTemp1;
    } else {
      rtb_y1 = RBCM_Model_B.VbatsData.LvBatTemp2;
    }

    /* ComposeString: '<S5>/Compose String4' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion5'
     *  DataTypeConversion: '<S5>/Data Type Conversion6'
     *  DataTypeConversion: '<S5>/Data Type Conversion7'
     *  MinMax: '<S5>/Max'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString2_m[0], 256U,
             "\"LvBatsV\":%d,\"LvBatsI\":%d,\"LvBatsT\":%d,", (int32_T)
             RBCM_Model_B.VbatsData.LvBatsV, (int32_T)
             RBCM_Model_B.VbatsData.LvBatsI, (int32_T)rtb_y1);

    /* ComposeString: '<S5>/Compose String5' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion10'
     *  DataTypeConversion: '<S5>/Data Type Conversion8'
     *  DataTypeConversion: '<S5>/Data Type Conversion9'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString5_c[0], 256U,
             "\"VcuState\":%d,\"BmsState\":%d,\"McuState\":%d,", (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.VcuPwr_lHsd2ch2, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.AccuPwr_lHsd4ch3, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.McuUbr_lHsd5ch2);

    /* ComposeString: '<S5>/Compose String6' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion11'
     *  DataTypeConversion: '<S5>/Data Type Conversion12'
     *  DataTypeConversion: '<S5>/Data Type Conversion13'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString6_b[0], 256U,
             "\"BduState\":%d,\"BspdState\":%d,\"TsalrState\":%d,", (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.BduPwr_lHsd4ch4, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.BspdPwr_lHsd1ch2, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.TsalrPwr_lHsd5ch4);

    /* ComposeString: '<S5>/Compose String7' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion14'
     *  DataTypeConversion: '<S5>/Data Type Conversion15'
     *  Logic: '<S5>/AND1'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString7_p[0], 256U,
             "\"PumpValue\":%d,\"Fan1Value\":%d,\"Fan2Value\":%d,", (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.PumpPwr_hHsd3ch1, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseResults.AccuFanPwr_hHsd3ch2,
             (RBCM_Model_B.BusHsdDiagnoseResults.PumpFan1_hHsd4ch1 != 0) &&
             (RBCM_Model_B.BusHsdDiagnoseResults.PumpFan2_hHsd4ch2 != 0));

    /* ComposeString: '<S5>/Compose String8' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion17'
     *  DataTypeConversion: '<S5>/Data Type Conversion18'
     *  DataTypeConversion: '<S5>/Data Type Conversion19'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString8_c[0], 256U,
             "\"TaillightValue\":%d,\"BuzzerValue\":%d,\"DrsValue\":%d,",
             (int32_T)RBCM_Model_B.BusHsdDiagnoseResults.TaillightPwr_lHsd3ch4,
             (int32_T)RBCM_Model_B.BusHsdDiagnoseResults.BuzzerPwr_lHsd3ch3,
             (int32_T)RBCM_Model_B.BusHsdDiagnoseResults.DrsPwr_8v_lHsd3ch1);

    /* StringConcatenate: '<S5>/String Concatenate3' incorporates:
     *  ComposeString: '<S5>/Compose String5'
     *  ComposeString: '<S5>/Compose String6'
     *  ComposeString: '<S5>/Compose String7'
     *  ComposeString: '<S5>/Compose String8'
     */
    RBCM_Model_B.rtb_StringConcatenate3_f[0] = '\x00';
    strncat(&RBCM_Model_B.rtb_StringConcatenate3_f[0U],
            &RBCM_Model_B.rtb_ComposeString5_c[0], 255U);
    tmp = strlen(&RBCM_Model_B.rtb_StringConcatenate3_f[0U]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate3_f[tmp],
            &RBCM_Model_B.rtb_ComposeString6_b[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate3_f[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate3_f[tmp],
            &RBCM_Model_B.rtb_ComposeString7_p[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate3_f[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate3_f[tmp],
            &RBCM_Model_B.rtb_ComposeString8_c[0], 255U - tmp);

    /* ComposeString: '<S5>/Compose String9' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion20'
     *  DataTypeConversion: '<S5>/Data Type Conversion21'
     *  DataTypeConversion: '<S5>/Data Type Conversion22'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString9_g[0], 256U,
             "\"VcuValue\":%d,\"BmsValue\":%d,\"McuValue\":%d,", (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.VcuPwr_lHsd2ch2, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.AccuPwr_lHsd4ch3, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.McuUbr_lHsd5ch2);

    /* ComposeString: '<S5>/Compose String10' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion23'
     *  DataTypeConversion: '<S5>/Data Type Conversion24'
     *  DataTypeConversion: '<S5>/Data Type Conversion25'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString10_g[0], 256U,
             "\"BduValue\":%d,\"BspdValue\":%d,\"TsalrValue\":%d,", (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.BduPwr_lHsd4ch4, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.BspdPwr_lHsd1ch2, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.TsalrPwr_lHsd5ch4);

    /* ComposeString: '<S5>/Compose String11' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion26'
     *  DataTypeConversion: '<S5>/Data Type Conversion27'
     *  Logic: '<S5>/AND2'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString11_m[0], 256U,
             "\"PumpValue\":%d,\"Fan1Value\":%d,\"Fan2Value\":%d,", (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.PumpPwr_hHsd3ch1, (int32_T)
             RBCM_Model_B.BusHsdDiagnoseValues.AccuFanPwr_hHsd3ch2,
             (RBCM_Model_B.BusHsdDiagnoseValues.PumpFan1_hHsd4ch1 != 0) &&
             (RBCM_Model_B.BusHsdDiagnoseValues.PumpFan2_hHsd4ch2 != 0));

    /* ComposeString: '<S5>/Compose String12' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion29'
     *  DataTypeConversion: '<S5>/Data Type Conversion30'
     *  DataTypeConversion: '<S5>/Data Type Conversion31'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString12_n[0], 256U,
             "\"TaillightValue\":%d,\"BuzzerValue\":%d,\"DrsValue\":%d,",
             (int32_T)RBCM_Model_B.BusHsdDiagnoseValues.TaillightPwr_lHsd3ch4,
             (int32_T)RBCM_Model_B.BusHsdDiagnoseValues.BuzzerPwr_lHsd3ch3,
             (int32_T)RBCM_Model_B.BusHsdDiagnoseValues.DrsPwr_8v_lHsd3ch1);

    /* StringConcatenate: '<S5>/String Concatenate4' incorporates:
     *  ComposeString: '<S5>/Compose String10'
     *  ComposeString: '<S5>/Compose String11'
     *  ComposeString: '<S5>/Compose String12'
     *  ComposeString: '<S5>/Compose String9'
     */
    RBCM_Model_B.rtb_StringConcatenate4_p[0] = '\x00';
    strncat(&RBCM_Model_B.rtb_StringConcatenate4_p[0U],
            &RBCM_Model_B.rtb_ComposeString9_g[0], 255U);
    tmp = strlen(&RBCM_Model_B.rtb_StringConcatenate4_p[0U]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate4_p[tmp],
            &RBCM_Model_B.rtb_ComposeString10_g[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate4_p[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate4_p[tmp],
            &RBCM_Model_B.rtb_ComposeString11_m[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate4_p[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate4_p[tmp],
            &RBCM_Model_B.rtb_ComposeString12_n[0], 255U - tmp);

    /* ComposeString: '<S5>/Compose String13' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion32'
     *  DataTypeConversion: '<S5>/Data Type Conversion33'
     *  DataTypeConversion: '<S5>/Data Type Conversion34'
     *  DataTypeConversion: '<S5>/Data Type Conversion35'
     *  RateTransition: '<Root>/RT'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString13_l[0], 256U,
             "\"AccuV\":%d,\"AccuI\":%d,\"AccuTcmax\":%d,\"AccudVmax\":%d,",
             (int32_T)RBCM_Model_B.VehicleData.AccuV, (int32_T)
             RBCM_Model_B.VehicleData.AccuI, (int32_T)
             RBCM_Model_B.VehicleData.AccuTcmax, (int32_T)
             RBCM_Model_B.VehicleData.AccudVmax);

    /* ComposeString: '<S5>/Compose String14' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion36'
     *  RateTransition: '<Root>/RT'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString14_j[0], 256U, "\"McuT\":%d,",
             (int32_T)RBCM_Model_B.VehicleData.McuT);

    /* ComposeString: '<S5>/Compose String15' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion37'
     *  DataTypeConversion: '<S5>/Data Type Conversion38'
     *  DataTypeConversion: '<S5>/Data Type Conversion39'
     *  RateTransition: '<Root>/RT'
     */
    snprintf(&RBCM_Model_B.rtb_ComposeString15_d[0], 256U,
             "\"MotorRpm\":%d,\"MotorTorque\":%d,\"MotorTemp\":%d", (int32_T)
             RBCM_Model_B.VehicleData.MotorRpm, (int32_T)
             RBCM_Model_B.VehicleData.MotorTorque, (int32_T)
             RBCM_Model_B.VehicleData.MotorTemp);

    /* StringConcatenate: '<S5>/String Concatenate5' incorporates:
     *  ComposeString: '<S5>/Compose String13'
     *  ComposeString: '<S5>/Compose String14'
     *  ComposeString: '<S5>/Compose String15'
     */
    RBCM_Model_B.rtb_StringConcatenate5_g[0] = '\x00';
    strncat(&RBCM_Model_B.rtb_StringConcatenate5_g[0U],
            &RBCM_Model_B.rtb_ComposeString13_l[0], 255U);
    tmp = strlen(&RBCM_Model_B.rtb_StringConcatenate5_g[0U]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate5_g[tmp],
            &RBCM_Model_B.rtb_ComposeString14_j[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate5_g[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate5_g[tmp],
            &RBCM_Model_B.rtb_ComposeString15_d[0], 255U - tmp);

    /* StringConcatenate: '<S5>/String Concatenate' incorporates:
     *  ComposeString: '<S5>/Compose String4'
     *  StringConcatenate: '<S5>/String Concatenate2'
     *  StringConcatenate: '<S5>/String Concatenate3'
     *  StringConcatenate: '<S5>/String Concatenate4'
     *  StringConcatenate: '<S5>/String Concatenate5'
     *  StringConstant: '<S5>/String Constant'
     *  StringConstant: '<S5>/String Constant1'
     */
    RBCM_Model_B.rtb_StringConcatenate_l[0] = '\x00';
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[0U],
            &RBCM_Model_P.StringConstant_String[0], 255U);
    tmp = strlen(&RBCM_Model_B.rtb_StringConcatenate_l[0U]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[tmp],
            &RBCM_Model_B.rtb_StringConcatenate2_k[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate_l[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[tmp],
            &RBCM_Model_B.rtb_ComposeString2_m[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate_l[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[tmp],
            &RBCM_Model_B.rtb_StringConcatenate3_f[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate_l[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[tmp],
            &RBCM_Model_B.rtb_StringConcatenate4_p[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate_l[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[tmp],
            &RBCM_Model_B.rtb_StringConcatenate5_g[0], 255U - tmp);
    tmp += strlen(&RBCM_Model_B.rtb_StringConcatenate_l[tmp]);
    strncat(&RBCM_Model_B.rtb_StringConcatenate_l[tmp],
            &RBCM_Model_P.StringConstant1_String[0], 255U - tmp);

    /* RateTransition generated from: '<Root>/4G通信控制状态机1' incorporates:
     *  StringConcatenate: '<S5>/String Concatenate'
     */
    if (RBCM_Model_M->Timing.TaskCounters.TID[2] == 0) {
      strncpy(&RBCM_Model_DW.TmpRTBAt4G1Inport3_Buffer[0],
              &RBCM_Model_B.rtb_StringConcatenate_l[0], 255U);
      RBCM_Model_DW.TmpRTBAt4G1Inport3_Buffer[255] = '\x00';
    }
  }

  /* RateTransition generated from: '<Root>/4G通信控制状态机1' */
  if (RBCM_Model_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem7'
     */
    /* Chart: '<S16>/Chart2' */
    RBCM_Model_Chart2(&rtb_A, &RBCM_Model_DW.sf_Chart2);

    /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion3'
     */
    RBCM_Model_DW.RGBLED0state[2] = rtb_A;

    /* S-Function (s32k3_dio): '<S16>/Dio' */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_B.DataStoreRead_o1);

    /* S-Function (s32k3_dio): '<S16>/Dio1' */
    Dio_WriteChannel(DioConf_DioChannel_LED0_PTD10,
                     RBCM_Model_B.DataStoreRead_o2);

    /* S-Function (s32k3_dio): '<S16>/Dio2' */
    Dio_WriteChannel(DioConf_DioChannel_LED_PTB14, RBCM_Model_B.DataStoreRead_o3);

    /* S-Function (s32k3_dio): '<S16>/Dio3' */
    Dio_WriteChannel(DioConf_DioChannel_LED0_PTD10,
                     RBCM_Model_B.DataStoreRead_o3);

    /* DataStoreRead: '<S16>/Data Store Read' */
    RBCM_Model_B.DataStoreRead_o1 = RBCM_Model_DW.RGBLED0state[0];

    /* DataStoreRead: '<S16>/Data Store Read' */
    RBCM_Model_B.DataStoreRead_o2 = RBCM_Model_DW.RGBLED0state[1];

    /* DataStoreRead: '<S16>/Data Store Read' */
    RBCM_Model_B.DataStoreRead_o3 = RBCM_Model_DW.RGBLED0state[2];

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/无线调试模式管理子系统'
     */
    /* S-Function (s32k3_dio): '<S19>/Dio1' */
    RBCM_Model_B.Dio1 = Dio_ReadChannel(DioConf_DioChannel_ESP32S3_EN);

    /* If: '<S19>/If' */
    if (RBCM_Model_B.Dio1 == 0) {
      /* Outputs for IfAction SubSystem: '<S19>/Subsystem' incorporates:
       *  ActionPort: '<S107>/Action Port'
       */
      /* S-Function (s32k3_dio): '<S107>/Dio' incorporates:
       *  Constant: '<S107>/Constant'
       */
      Dio_WriteChannel(DioConf_DioChannel_ESP32S3_EN_RESET,
                       RBCM_Model_P.Constant_Value_b);

      /* S-Function (s32k3_dio): '<S107>/Dio1' incorporates:
       *  Constant: '<S107>/Constant1'
       */
      Dio_WriteChannel(DioConf_DioChannel_ESP32S3_EN_SET,
                       RBCM_Model_P.Constant1_Value_n);

      /* End of Outputs for SubSystem: '<S19>/Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S19>/Subsystem1' incorporates:
       *  ActionPort: '<S108>/Action Port'
       */
      /* S-Function (s32k3_dio): '<S108>/Dio' incorporates:
       *  Constant: '<S108>/Constant'
       */
      Dio_WriteChannel(DioConf_DioChannel_ESP32S3_EN_RESET,
                       RBCM_Model_P.Constant_Value_bb);

      /* End of Outputs for SubSystem: '<S19>/Subsystem1' */
    }

    /* End of If: '<S19>/If' */

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  Chart: '<Root>/4G通信控制状态机1'
     */
    /* Chart: '<Root>/4G通信控制状态机1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    switch (RBCM_Model_DW.is_c72_RBCM_Model) {
     case RBCM_Model_IN_first:
      if (RBCM_Model_B.u == 2U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.B[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter = 0U;
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_second;
        if (RBCM_Model_B.u == 0U) {
          strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.B[0], 255U);
          RBCM_Model_B.output[255] = '\x00';
          RBCM_Model_DW.counter++;
        }
      } else if ((RBCM_Model_P.Constant2_Value_ds == 0) ||
                 (RBCM_Model_DW.counter >= 5)) {
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_init;
        RBCM_Model_DW.counter = 0U;
      } else if (RBCM_Model_B.u == 0U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.A[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter++;
      }
      break;

     case RBCM_Model_IN_fourth:
      if (RBCM_Model_B.u == 2U) {
        strncpy(&RBCM_Model_B.output[0],
                &RBCM_Model_DW.TmpRTBAt4G1Inport3_Buffer[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter = 0U;
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_msgsend;
      } else if ((RBCM_Model_P.Constant2_Value_ds == 0) ||
                 (RBCM_Model_DW.counter >= 5)) {
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_init;
        RBCM_Model_DW.counter = 0U;
      } else if (RBCM_Model_B.u == 0U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.D[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter++;
      }
      break;

     case RBCM_Model_IN_init:
      if (RBCM_Model_P.Constant2_Value_ds == 1) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.A[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_first;
        if (RBCM_Model_B.u == 0U) {
          strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.A[0], 255U);
          RBCM_Model_B.output[255] = '\x00';
          RBCM_Model_DW.counter++;
        }
      } else {
        RBCM_Model_DW.counter = 0U;
      }
      break;

     case RBCM_Model_IN_msgsend:
      if ((RBCM_Model_P.Constant2_Value_ds == 0) || (RBCM_Model_DW.counter >= 5))
      {
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_init;
        RBCM_Model_DW.counter = 0U;
      } else {
        strncpy(&RBCM_Model_B.output[0],
                &RBCM_Model_DW.TmpRTBAt4G1Inport3_Buffer[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_msgsend;
      }
      break;

     case RBCM_Model_IN_second:
      if ((RBCM_Model_P.Constant2_Value_ds == 0) || (RBCM_Model_DW.counter >= 5))
      {
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_init;
        RBCM_Model_DW.counter = 0U;
      } else if (RBCM_Model_B.u == 2U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.C[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter = 0U;
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_third;
        if (RBCM_Model_B.u == 0U) {
          strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.C[0], 255U);
          RBCM_Model_B.output[255] = '\x00';
          RBCM_Model_DW.counter++;
        }
      } else if (RBCM_Model_B.u == 0U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.B[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter++;
      }
      break;

     default:
      /* case IN_third: */
      if (RBCM_Model_B.u == 2U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.D[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter = 0U;
        RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_fourth;
        if (RBCM_Model_B.u == 0U) {
          strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.D[0], 255U);
          RBCM_Model_B.output[255] = '\x00';
          RBCM_Model_DW.counter++;
        }
      } else if (RBCM_Model_B.u == 0U) {
        strncpy(&RBCM_Model_B.output[0], &RBCM_Model_DW.C[0], 255U);
        RBCM_Model_B.output[255] = '\x00';
        RBCM_Model_DW.counter++;
      }
      break;
    }

    /* End of Chart: '<Root>/4G通信控制状态机1' */

    /* S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/核心状态信息发送'
     */
    /* Switch: '<S20>/Switch' */
    if (rtb_TmpRTBAtInport2 > RBCM_Model_P.Switch_Threshold) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/Constant1'
       */
      RBCM_Model_B.Switch = RBCM_Model_P.Constant1_Value;
    } else {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/Constant2'
       */
      RBCM_Model_B.Switch = RBCM_Model_P.Constant2_Value;
    }

    /* End of Switch: '<S20>/Switch' */

    /* S-Function (scanpack): '<S20>/CAN Pack' incorporates:
     *  Constant: '<S20>/Constant'
     */
    /* S-Function (scanpack): '<S20>/CAN Pack' */
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

    /* Chart: '<S20>/Chart1' */
    RBCM_Model_Chart2(&rtb_A, &RBCM_Model_DW.sf_Chart1);

    /* DataStoreWrite: '<S20>/Data Store Write1' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     */
    RBCM_Model_DW.RGBLED0state[1] = rtb_A;

    /* S-Function (s32k3_can): '<S20>/Can' incorporates:
     *  Constant: '<S20>/Constant4'
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
    /* S-Function (scanpack): '<S21>/CAN Pack' incorporates:
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/Constant3'
     */
    /* S-Function (scanpack): '<S21>/CAN Pack' */
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

    /* S-Function (s32k3_can): '<S21>/Can' incorporates:
     *  Constant: '<S21>/Constant'
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
    /* S-Function (scanpack): '<S22>/CAN Pack' incorporates:
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    /* S-Function (scanpack): '<S22>/CAN Pack' */
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

    /* S-Function (s32k3_can): '<S22>/Can' incorporates:
     *  Constant: '<S22>/Constant'
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

    /* StringToASCII: '<S14>/String to ASCII' */
    strncpy(&RBCM_Model_B.cv[0], &RBCM_Model_B.output[0], 1024U);

    /* MATLAB Function: '<S14>/Add '\r\n'2' incorporates:
     *  StringToASCII: '<S14>/String to ASCII'
     */
    for (i = 0; i < 1024; i++) {
      RBCM_Model_B.y[i] = (uint8_T)RBCM_Model_B.cv[i];
    }

    RBCM_Model_B.y[1024] = 10U;
    RBCM_Model_B.y[1025] = 13U;

    /* End of MATLAB Function: '<S14>/Add '\r\n'2' */

    /* S-Function (s32k3_uart): '<S14>/Uart' */
    RBCM_Model_B.Uart = Uart_AsyncSend(0, &RBCM_Model_B.y[0], 1026);
  }

  /* S-Function (fcgen): '<Root>/10ms1' incorporates:
   *  SubSystem: '<Root>/Subsystem8'
   */
  /* DataTypeConversion: '<S17>/Data Type Conversion4' */
  RBCM_Model_B.DataTypeConversion4 =
    RBCM_Model_B.OutportBufferForDrsDriveCommand;

  /* S-Function (s32k3_pwm): '<S17>/Pwm' */
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
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

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
    /* SystemInitialize for MATLAB Function: '<S2>/触发器1' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_o,
                        &RBCM_Model_P.sf_1_o);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器2' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_du,
                        &RBCM_Model_P.sf_2_l);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器3' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_a4,
                        &RBCM_Model_P.sf_3_c);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器4' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_m3,
                        &RBCM_Model_P.sf_4_a);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器5' */
    RBCM_Model_u_a_Init(&RBCM_Model_B.DataTypeConversion1_m,
                        &RBCM_Model_P.sf_5_c);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器10' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_g,
                       &RBCM_Model_P.sf_10_a);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器11' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_l,
                       &RBCM_Model_P.sf_11_a);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器6' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_b, &RBCM_Model_P.sf_6_o);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器7' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_d, &RBCM_Model_P.sf_7_p);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器8' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1_a, &RBCM_Model_P.sf_8_j);

    /* SystemInitialize for MATLAB Function: '<S2>/触发器9' */
    RBCM_Model_u0_Init(&RBCM_Model_B.DataTypeConversion1, &RBCM_Model_P.sf_9_a);

    /* SystemInitialize for BusAssignment: '<S2>/BusHsdDiagnoseValues' incorporates:
     *  Outport: '<S2>/Out1'
     */
    RBCM_Model_B.BusHsdDiagnoseValues = RBCM_Model_P.Out1_Y0;

    /* SystemInitialize for BusAssignment: '<S2>/BusHsdDiagnoseResults' incorporates:
     *  Outport: '<S2>/Out2'
     */
    RBCM_Model_B.BusHsdDiagnoseResults = RBCM_Model_P.Out2_Y0;

    /* SystemInitialize for S-Function (fcgen): '<Root>/50ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem6'
     */
    RBCM_Model_Subsystem6_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<Root>/50ms1' */

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/Subsystem7'
     */
    /* SystemInitialize for Chart: '<S16>/Chart2' */
    RBCM_Model_Chart2_Init(&rtb_A);

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  Chart: '<Root>/4G通信控制状态机1'
     */
    /* SystemInitialize for Chart: '<Root>/4G通信控制状态机1' */
    strncpy(&RBCM_Model_DW.B[0],
            "AT+QMTOPEN=0,\"2ac4d9928b.st1.iotda-device.cn-east-3.myhuaweicloud.com\",1883",
            255U);
    RBCM_Model_DW.B[255] = '\x00';
    strncpy(&RBCM_Model_DW.C[0],
            "AT+QMTCONN=0,\"E10_10101010_0_0_2024112708\",\"E10_10101010\",\"70cb096b1e95f2f5f6fa4a703d88b56f5d4bc5062f406b1091639f697a62929d\"",
            255U);
    RBCM_Model_DW.C[255] = '\x00';
    strncpy(&RBCM_Model_DW.D[0], "AT+QMTSUB=0,1,\"wute/car/test\",2", 255U);
    RBCM_Model_DW.D[255] = '\x00';
    strncpy(&RBCM_Model_B.output[0], "", 255U);

    /* End of SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' */
    RBCM_Model_B.output[255] = '\x00';

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  Chart: '<Root>/4G通信控制状态机1'
     */
    /* SystemInitialize for Chart: '<Root>/4G通信控制状态机1' */
    strncpy(&RBCM_Model_DW.A[0], "AT", 255U);
    RBCM_Model_DW.A[255] = '\x00';

    /* Chart: '<Root>/4G通信控制状态机1' */
    /* Chart: '<Root>/4G通信控制状态机1' */
    RBCM_Model_DW.is_c72_RBCM_Model = RBCM_Model_IN_init;

    /* SystemInitialize for Chart: '<S20>/Chart1' */
    RBCM_Model_Chart2_Init(&rtb_A);

    /* SystemInitialize for S-Function (fcgen): '<Root>/1000ms1' incorporates:
     *  SubSystem: '<Root>/错误码数据发送(未)'
     */

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler1' */

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler2' */

    /* End of SystemInitialize for S-Function (s32k3_isr_handler): '<Root>/Hardware_Interrupt_Handler5' */
    /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
    for (i = 0; i < 6; i++) {
      /* DataStoreRead: '<S8>/Data Store Read' */
      RBCM_Model_B.DataStoreRead[i] = Adc0Group1_ResultBuffer[i];
    }

    /* S-Function (s32k3_adc): '<S8>/Adc' */
    RBCM_Model_B.Adc = Adc_SetupResultBuffer(Adc0Group_1,
      &RBCM_Model_B.DataStoreRead[0]);
    Adc0Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead[0];
    Adc0Group_1_ResultBufferLength = 6;

    /* DataStoreRead: '<S8>/Data Store Read1' */
    RBCM_Model_B.DataStoreRead1[0] = Adc1Group1_ResultBuffer_idx_0;
    RBCM_Model_B.DataStoreRead1[1] = Adc1Group1_ResultBuffer_idx_1;
    RBCM_Model_B.DataStoreRead1[2] = Adc1Group1_ResultBuffer_idx_2;

    /* S-Function (s32k3_adc): '<S8>/Adc2' */
    RBCM_Model_B.Adc2 = Adc_SetupResultBuffer(Adc1Group_1,
      &RBCM_Model_B.DataStoreRead1[0]);
    Adc1Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead1[0];
    Adc1Group_1_ResultBufferLength = 3;
    for (i = 0; i < 5; i++) {
      /* DataStoreRead: '<S8>/Data Store Read2' */
      RBCM_Model_B.DataStoreRead2[i] = Adc2Group1_ResultBuffer[i];
    }

    /* S-Function (s32k3_adc): '<S8>/Adc4' */
    RBCM_Model_B.Adc4 = Adc_SetupResultBuffer(Adc2Group_1,
      &RBCM_Model_B.DataStoreRead2[0]);
    Adc2Group_1_ResultBufferPtr = &RBCM_Model_B.DataStoreRead2[0];
    Adc2Group_1_ResultBufferLength = 5;

    /* S-Function (s32k3_can): '<S8>/Can' */
    RBCM_Model_B.Can = Can_43_FLEXCAN_SetControllerMode
      (Can_43_FLEXCANConf_CanController_CanController_0, CAN_CS_STARTED);

    /* S-Function (s32k3_dio): '<S8>/Dio11' incorporates:
     *  Constant: '<S8>/Constant11'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant11_Value_b);

    /* S-Function (s32k3_dio): '<S8>/Dio12' incorporates:
     *  Constant: '<S8>/Constant12'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant12_Value_c);

    /* S-Function (s32k3_dio): '<S8>/Dio13' incorporates:
     *  Constant: '<S8>/Constant13'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant13_Value);

    /* S-Function (s32k3_dio): '<S8>/Dio14' incorporates:
     *  Constant: '<S8>/Constant14'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant14_Value);

    /* S-Function (s32k3_dio): '<S8>/Dio15' incorporates:
     *  Constant: '<S8>/Constant15'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant15_Value);

    /* S-Function (s32k3_dio): '<S8>/Dio3' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant3_Value_d);

    /* S-Function (s32k3_dio): '<S8>/Dio4' incorporates:
     *  Constant: '<S8>/Constant4'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant4_Value_p);

    /* S-Function (s32k3_dio): '<S8>/Dio5' incorporates:
     *  Constant: '<S8>/Constant5'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant5_Value_l);

    /* S-Function (s32k3_dio): '<S8>/Dio6' incorporates:
     *  Constant: '<S8>/Constant6'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant6_Value_b);

    /* S-Function (s32k3_dio): '<S8>/Dio7' incorporates:
     *  Constant: '<S8>/Constant7'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_RED,
                     RBCM_Model_P.Constant7_Value_i);

    /* S-Function (s32k3_dio): '<S8>/Dio8' incorporates:
     *  Constant: '<S8>/Constant8'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_GREEN,
                     RBCM_Model_P.Constant8_Value_a);

    /* S-Function (s32k3_dio): '<S8>/Dio9' incorporates:
     *  Constant: '<S8>/Constant9'
     */
    Dio_WriteChannel(DioConf_DioChannel_RGBLED0_BLUE,
                     RBCM_Model_P.Constant9_Value_c);

    /* S-Function (s32k3_adc): '<S8>/Adc1' */
    Adc_EnableGroupNotification(Adc0Group_1);

    /* S-Function (s32k3_adc): '<S8>/Adc3' */
    Adc_EnableGroupNotification(Adc1Group_1);

    /* S-Function (s32k3_adc): '<S8>/Adc5' */
    Adc_EnableGroupNotification(Adc2Group_1);

    /* S-Function (s32k3_can): '<S8>/Can1' */
    Can_43_FLEXCAN_DisableControllerInterrupts
      (Can_43_FLEXCANConf_CanController_CanController_0);

    /* S-Function (s32k3_can): '<S8>/Can2' */
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
