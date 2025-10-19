/*
 * File: RBCM_Model_data.c
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

/* Block parameters (default storage) */
P_RBCM_Model_T RBCM_Model_P = {
  /* Mask Parameter: BitwiseAND2_BitMask
   * Referenced by: '<S37>/Bitwise AND2'
   */
  1U,

  /* Mask Parameter: BitwiseAND3_BitMask
   * Referenced by: '<S37>/Bitwise AND3'
   */
  2U,

  /* Mask Parameter: BitwiseAND2_BitMask_f
   * Referenced by: '<S38>/Bitwise AND2'
   */
  1U,

  /* Mask Parameter: BitwiseAND3_BitMask_k
   * Referenced by: '<S38>/Bitwise AND3'
   */
  2U,

  /* Mask Parameter: BitwiseAND2_BitMask_i
   * Referenced by: '<S39>/Bitwise AND2'
   */
  1U,

  /* Mask Parameter: BitwiseAND3_BitMask_kw
   * Referenced by: '<S39>/Bitwise AND3'
   */
  2U,

  /* Mask Parameter: BitwiseAND2_BitMask_l
   * Referenced by: '<S40>/Bitwise AND2'
   */
  1U,

  /* Mask Parameter: BitwiseAND3_BitMask_n
   * Referenced by: '<S40>/Bitwise AND3'
   */
  2U,

  /* Mask Parameter: BitwiseAND2_BitMask_h
   * Referenced by: '<S41>/Bitwise AND2'
   */
  1U,

  /* Mask Parameter: BitwiseAND3_BitMask_b
   * Referenced by: '<S41>/Bitwise AND3'
   */
  2U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S1>/Out1'
   */
  {
    0U,                                /* DevicePwr_12v_lHsd1ch1 */
    0U,                                /* BspdPwr_lHsd1ch2 */
    0U,                                /* LoggerPwr_lHsd1ch3 */
    0U,                                /* TempSensorPwr_lHsd1ch4 */
    0U,                                /* DevicePwr_12v_lHsd2ch1 */
    0U,                                /* VcuPwr_lHsd2ch2 */
    0U,                                /* Fireon_Pwr_lHsd2ch3 */
    0U,                                /* DsbdPwr_lHsd2ch4 */
    0U,                                /* DrsPwr_8v_lHsd3ch1 */
    0U,                                /* DevicePwr_lHsd3ch2 */
    0U,                                /* BuzzerPwr_lHsd3ch3 */
    0U,                                /* TaillightPwr_lHsd3ch4 */
    0U,                                /* DevicePwr_5v_lHsd4ch1 */
    0U,                                /* AccuUbr_lHsd4ch2 */
    0U,                                /* AccuPwr_lHsd4ch3 */
    0U,                                /* BduPwr_lHsd4ch4 */
    0U,                                /* DevicePwr_5v_lHsd5ch1 */
    0U,                                /* McuUbr_lHsd5ch2 */
    0U,                                /* EnergeMeterPwr_lHsd5ch3 */
    0U,                                /* TsalrPwr_lHsd5ch4 */
    0U,                                /* ILPwr_hHsd1ch1 */
    0U,                                /* DevicePwr_hHsd1ch2 */
    0U,                                /* VcuUbr_hHsd2ch1 */
    0U,                                /* Device_hHsd2ch2 */
    0U,                                /* PumpPwr_hHsd3ch1 */
    0U,                                /* AccuFanPwr_hHsd3ch2 */
    0U,                                /* PumpFan1_hHsd4ch1 */
    0U,                                /* PumpFan2_hHsd4ch2 */
    0U,                                /* DevicePwr_hHsd5ch1 */
    0U,                                /* DevicePwr_hHsd5ch2 */
    0U,                                /* DevicePwr_hHsd6ch1 */
    0U                                 /* DevicePwr_hHsd6ch2 */
  },

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  {
    0U,                                /* Extended */
    0U,                                /* Length */
    0U,                                /* Remote */
    0U,                                /* Error */
    0U,                                /* ID */
    0.0,                               /* Timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    /* Data */
  },

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S1>/Out2'
   */
  {
    0U,                                /* DevicePwr_12v_lHsd1ch1 */
    0U,                                /* BspdPwr_lHsd1ch2 */
    0U,                                /* LoggerPwr_lHsd1ch3 */
    0U,                                /* TempSensorPwr_lHsd1ch4 */
    0U,                                /* DevicePwr_12v_lHsd2ch1 */
    0U,                                /* VcuPwr_lHsd2ch2 */
    0U,                                /* Fireon_Pwr_lHsd2ch3 */
    0U,                                /* DsbdPwr_lHsd2ch4 */
    0U,                                /* DrsPwr_8v_lHsd3ch1 */
    0U,                                /* DevicePwr_lHsd3ch2 */
    0U,                                /* BuzzerPwr_lHsd3ch3 */
    0U,                                /* TaillightPwr_lHsd3ch4 */
    0U,                                /* DevicePwr_5v_lHsd4ch1 */
    0U,                                /* AccuUbr_lHsd4ch2 */
    0U,                                /* AccuPwr_lHsd4ch3 */
    0U,                                /* BduPwr_lHsd4ch4 */
    0U,                                /* DevicePwr_5v_lHsd5ch1 */
    0U,                                /* McuUbr_lHsd5ch2 */
    0U,                                /* EnergeMeterPwr_lHsd5ch3 */
    0U,                                /* TsalrPwr_lHsd5ch4 */
    0U,                                /* ILPwr_hHsd1ch1 */
    0U,                                /* DevicePwr_hHsd1ch2 */
    0U,                                /* VcuUbr_hHsd2ch1 */
    0U,                                /* Device_hHsd2ch2 */
    0U,                                /* PumpPwr_hHsd3ch1 */
    0U,                                /* AccuFanPwr_hHsd3ch2 */
    0U,                                /* PumpFan1_hHsd4ch1 */
    0U,                                /* PumpFan2_hHsd4ch2 */
    0U,                                /* DevicePwr_hHsd5ch1 */
    0U,                                /* DevicePwr_hHsd5ch2 */
    0U,                                /* DevicePwr_hHsd6ch1 */
    0U                                 /* DevicePwr_hHsd6ch2 */
  },

  /* Computed Parameter: HsdDriveCommands_Y0
   * Referenced by: '<S15>/HsdDriveCommands'
   */
  {
    0U,                                /* DevicePwr_12v_lHsd1ch1 */
    0U,                                /* BspdPwr_lHsd1ch2 */
    0U,                                /* LoggerPwr_lHsd1ch3 */
    0U,                                /* TempSensorPwr_lHsd1ch4 */
    0U,                                /* DevicePwr_12v_lHsd2ch1 */
    0U,                                /* VcuPwr_lHsd2ch2 */
    0U,                                /* Fireon_Pwr_lHsd2ch3 */
    0U,                                /* DsbdPwr_lHsd2ch4 */
    0U,                                /* DrsPwr_8v_lHsd3ch1 */
    0U,                                /* DevicePwr_lHsd3ch2 */
    0U,                                /* BuzzerPwr_lHsd3ch3 */
    0U,                                /* TaillightPwr_lHsd3ch4 */
    0U,                                /* DevicePwr_5v_lHsd4ch1 */
    0U,                                /* AccuUbr_lHsd4ch2 */
    0U,                                /* AccuPwr_lHsd4ch3 */
    0U,                                /* BduPwr_lHsd4ch4 */
    0U,                                /* DevicePwr_5v_lHsd5ch1 */
    0U,                                /* McuUbr_lHsd5ch2 */
    0U,                                /* EnergeMeterPwr_lHsd5ch3 */
    0U,                                /* TsalrPwr_lHsd5ch4 */
    0U,                                /* ILPwr_hHsd1ch1 */
    0U,                                /* DevicePwr_hHsd1ch2 */
    0U,                                /* VcuUbr_hHsd2ch1 */
    0U,                                /* Device_hHsd2ch2 */
    0U,                                /* PumpPwr_hHsd3ch1 */
    0U,                                /* AccuFanPwr_hHsd3ch2 */
    0U,                                /* PumpFan1_hHsd4ch1 */
    0U,                                /* PumpFan2_hHsd4ch2 */
    0U,                                /* DevicePwr_hHsd5ch1 */
    0U,                                /* DevicePwr_hHsd5ch2 */
    0U,                                /* DevicePwr_hHsd6ch1 */
    0U                                 /* DevicePwr_hHsd6ch2 */
  },

  /* Computed Parameter: Out2_Y0_c
   * Referenced by: '<S12>/Out2'
   */
  {
    0U,                                /* LvBatsV */
    0U,                                /* LvBatsI */
    0U,                                /* LvBatTemp1 */
    0U                                 /* LvBatTemp2 */
  },

  /* Expression: 1
   * Referenced by: '<S17>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant2'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Step2'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: funcParams
   * Referenced by: '<Root>/Hardware_Interrupt_Handler4'
   */
  { 0, 0, 5, 7, 1, 7, 1, 7, 1, 3, -1, 7, 1 },

  /* Expression: funcParams
   * Referenced by: '<Root>/Hardware_Interrupt_Handler1'
   */
  { 0, 0, 0 },

  /* Expression: funcParams
   * Referenced by: '<Root>/Hardware_Interrupt_Handler2'
   */
  { 0, 0, 0 },

  /* Expression: funcParams
   * Referenced by: '<Root>/Hardware_Interrupt_Handler5'
   */
  { 0, 0, 0 },

  /* Computed Parameter: Magnification_Gain
   * Referenced by: '<S12>/Magnification'
   */
  5.0F,

  /* Computed Parameter: Magnification1_Gain
   * Referenced by: '<S12>/Magnification1'
   */
  5.0F,

  /* Expression: funcParams
   * Referenced by: '<S13>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S13>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S13>/Dio2'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S13>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S103>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S103>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S104>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S16>/Dio1'
   */
  { 0U, 0U },

  /* Expression: funcParams
   * Referenced by: '<S17>/Can'
   */
  6U,

  /* Expression: funcParams
   * Referenced by: '<S18>/Can'
   */
  6U,

  /* Expression: funcParams
   * Referenced by: '<S19>/Can'
   */
  6U,

  /* Expression: funcParam
   * Referenced by: '<S14>/Pwm'
   */
  { 2U, 5U, 5U },

  /* Expression: funcParams
   * Referenced by: '<S37>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S37>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S36>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S32>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S38>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S38>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S39>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S39>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S40>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S40>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S41>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S41>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S34>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S33>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S35>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S86>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S87>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S87>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S88>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S88>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S89>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParam
   * Referenced by: '<S89>/Pwm'
   */
  { 2U, 5U, 5U },

  /* Expression: funcParams
   * Referenced by: '<S90>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S90>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S91>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S91>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S92>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S92>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S92>/Dio2'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S92>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S93>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S93>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S93>/Dio4'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S93>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S94>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S94>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S94>/Dio2'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S94>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S95>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S95>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S95>/Dio2'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S95>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S96>/Dio'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S96>/Dio1'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S96>/Dio2'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S96>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParam
   * Referenced by: '<S7>/Adc1'
   */
  11U,

  /* Expression: funcParam
   * Referenced by: '<S9>/Adc1'
   */
  11U,

  /* Expression: funcParam
   * Referenced by: '<S10>/Adc1'
   */
  11U,

  /* Expression: funcParam
   * Referenced by: '<S6>/Adc'
   */
  12U,

  /* Expression: funcParam
   * Referenced by: '<S6>/Adc2'
   */
  12U,

  /* Expression: funcParam
   * Referenced by: '<S6>/Adc4'
   */
  12U,

  /* Expression: funcParams
   * Referenced by: '<S6>/Can'
   */
  3U,

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio10'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio11'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio12'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio13'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio14'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio15'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio3'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio4'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio5'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio6'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio7'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio8'
   */
  { 1U, 1U },

  /* Expression: funcParams
   * Referenced by: '<S6>/Dio9'
   */
  { 1U, 1U },

  /* Expression: funcParam
   * Referenced by: '<S6>/Adc1'
   */
  7U,

  /* Expression: funcParam
   * Referenced by: '<S6>/Adc3'
   */
  7U,

  /* Expression: funcParam
   * Referenced by: '<S6>/Adc5'
   */
  7U,

  /* Expression: funcParams
   * Referenced by: '<S6>/Can1'
   */
  4U,

  /* Expression: funcParams
   * Referenced by: '<S6>/Can2'
   */
  0U,

  /* Expression: BitMask
   * Referenced by: '<Root>/Bitwise AND'
   */
  536870911U,

  /* Computed Parameter: Constant1_Value_o
   * Referenced by: '<Root>/Constant1'
   */
  41U,

  /* Expression: funcParams
   * Referenced by: '<Root>/Uart1'
   */
  { 3U, 0U },

  /* Expression: funcParam
   * Referenced by: '<Root>/Adc1'
   */
  2U,

  /* Expression: funcParam
   * Referenced by: '<Root>/Adc2'
   */
  2U,

  /* Expression: funcParam
   * Referenced by: '<Root>/Adc3'
   */
  2U,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  0U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S42>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S44>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S43>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S45>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_b
   * Referenced by: '<S46>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S47>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S48>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S49>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S50>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_lr
   * Referenced by: '<S51>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<S52>/Gain'
   */
  51200U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S17>/Constant4'
   */
  0U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S18>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S19>/Constant'
   */
  0U,

  /* Computed Parameter: RbcmCoreData_Y0
   * Referenced by: '<S12>/RbcmCoreData'
   */
  0U,

  /* Expression: 0b111111111111
   * Referenced by: '<S12>/ADC resolution'
   */
  4095U,

  /* Expression: 0b111111111111
   * Referenced by: '<S12>/ADC resolution1'
   */
  4095U,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S12>/Constant'
   */
  1U,

  /* Computed Parameter: Constant1_Value_d
   * Referenced by: '<S12>/Constant1'
   */
  1U,

  /* Computed Parameter: DataStoreMemory2_InitialValue
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0U,

  /* Computed Parameter: DataStoreMemory4_InitialValue
   * Referenced by: '<Root>/Data Store Memory4'
   */
  { 0U, 0U },

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: DataStoreMemory6_InitialValue
   * Referenced by: '<Root>/Data Store Memory6'
   */
  { 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: DataStoreMemory7_InitialValue
   * Referenced by: '<Root>/Data Store Memory7'
   */
  { 0U, 0U, 0U },

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  { 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S103>/Constant'
   */
  1U,

  /* Computed Parameter: Constant1_Value_n
   * Referenced by: '<S103>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant_Value_bb
   * Referenced by: '<S104>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S17>/Constant'
   */
  1U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S17>/Switch'
   */
  50U,

  /* Computed Parameter: Constant2_Value_i
   * Referenced by: '<S18>/Constant2'
   */
  1U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S18>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant2_Value_ig
   * Referenced by: '<S19>/Constant2'
   */
  1U,

  /* Computed Parameter: Constant3_Value_n
   * Referenced by: '<S19>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant2_Value_o
   * Referenced by: '<S42>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_f
   * Referenced by: '<S42>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_m
   * Referenced by: '<S42>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S42>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_p
   * Referenced by: '<S43>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_c
   * Referenced by: '<S43>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_f
   * Referenced by: '<S43>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S43>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_k
   * Referenced by: '<S44>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_a
   * Referenced by: '<S44>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_n
   * Referenced by: '<S44>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S44>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_c
   * Referenced by: '<S45>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_k
   * Referenced by: '<S45>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_o
   * Referenced by: '<S45>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S45>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_m
   * Referenced by: '<S46>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_ca
   * Referenced by: '<S46>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_a
   * Referenced by: '<S46>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S46>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_py
   * Referenced by: '<S47>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_ax
   * Referenced by: '<S47>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_l
   * Referenced by: '<S47>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S47>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_kb
   * Referenced by: '<S48>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_aq
   * Referenced by: '<S48>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_nh
   * Referenced by: '<S48>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S48>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_ct
   * Referenced by: '<S49>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_f2
   * Referenced by: '<S49>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_c
   * Referenced by: '<S49>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S49>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_d
   * Referenced by: '<S50>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_b
   * Referenced by: '<S50>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_ce
   * Referenced by: '<S50>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S50>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_ke
   * Referenced by: '<S51>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_kf
   * Referenced by: '<S51>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_l4
   * Referenced by: '<S51>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S51>/Constant'
   */
  255U,

  /* Computed Parameter: Constant2_Value_a
   * Referenced by: '<S52>/Constant2'
   */
  0U,

  /* Computed Parameter: Constant3_Value_e
   * Referenced by: '<S52>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value_mp
   * Referenced by: '<S52>/Constant4'
   */
  2U,

  /* Expression: 0xff
   * Referenced by: '<S52>/Constant'
   */
  255U,

  /* Computed Parameter: u_Value
   * Referenced by: '<S1>/预分频值1'
   */
  2U,

  /* Computed Parameter: u_Value_i
   * Referenced by: '<S1>/输出通道数1'
   */
  4U,

  /* Computed Parameter: u0_Value
   * Referenced by: '<S1>/预分频值10'
   */
  2U,

  /* Computed Parameter: u0_Value_a
   * Referenced by: '<S1>/输出通道数10'
   */
  4U,

  /* Computed Parameter: u1_Value
   * Referenced by: '<S1>/预分频值11'
   */
  2U,

  /* Computed Parameter: u1_Value_n
   * Referenced by: '<S1>/输出通道数11'
   */
  4U,

  /* Computed Parameter: u_Value_n
   * Referenced by: '<S1>/预分频值2'
   */
  2U,

  /* Computed Parameter: u_Value_k
   * Referenced by: '<S1>/输出通道数2'
   */
  4U,

  /* Computed Parameter: u_Value_a
   * Referenced by: '<S1>/预分频值3'
   */
  2U,

  /* Computed Parameter: u_Value_p
   * Referenced by: '<S1>/输出通道数3'
   */
  4U,

  /* Computed Parameter: u_Value_j
   * Referenced by: '<S1>/预分频值4'
   */
  2U,

  /* Computed Parameter: u_Value_m
   * Referenced by: '<S1>/输出通道数4'
   */
  4U,

  /* Computed Parameter: u_Value_l
   * Referenced by: '<S1>/预分频值5'
   */
  2U,

  /* Computed Parameter: u_Value_o
   * Referenced by: '<S1>/输出通道数5'
   */
  4U,

  /* Computed Parameter: u_Value_iv
   * Referenced by: '<S1>/预分频值6'
   */
  2U,

  /* Computed Parameter: u_Value_g
   * Referenced by: '<S1>/输出通道数6'
   */
  4U,

  /* Computed Parameter: u_Value_gq
   * Referenced by: '<S1>/预分频值7'
   */
  2U,

  /* Computed Parameter: u_Value_lh
   * Referenced by: '<S1>/输出通道数7'
   */
  4U,

  /* Computed Parameter: u_Value_h
   * Referenced by: '<S1>/预分频值8'
   */
  2U,

  /* Computed Parameter: u_Value_ku
   * Referenced by: '<S1>/输出通道数8'
   */
  4U,

  /* Computed Parameter: u_Value_al
   * Referenced by: '<S1>/预分频值9'
   */
  2U,

  /* Computed Parameter: u_Value_k3
   * Referenced by: '<S1>/输出通道数9'
   */
  4U,

  /* Computed Parameter: Vref_Value
   * Referenced by: '<S12>/Vref'
   */
  5U,

  /* Computed Parameter: Vref1_Value
   * Referenced by: '<S12>/Vref1'
   */
  5U,

  /* Computed Parameter: Constant12_Value
   * Referenced by: '<S102>/Constant12'
   */
  1U,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S6>/Constant10'
   */
  1U,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S6>/Constant11'
   */
  1U,

  /* Computed Parameter: Constant12_Value_c
   * Referenced by: '<S6>/Constant12'
   */
  1U,

  /* Computed Parameter: Constant13_Value
   * Referenced by: '<S6>/Constant13'
   */
  1U,

  /* Computed Parameter: Constant14_Value
   * Referenced by: '<S6>/Constant14'
   */
  1U,

  /* Computed Parameter: Constant15_Value
   * Referenced by: '<S6>/Constant15'
   */
  1U,

  /* Computed Parameter: Constant3_Value_d
   * Referenced by: '<S6>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant4_Value_p
   * Referenced by: '<S6>/Constant4'
   */
  1U,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S6>/Constant5'
   */
  1U,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<S6>/Constant6'
   */
  1U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S6>/Constant7'
   */
  1U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S6>/Constant8'
   */
  1U,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S6>/Constant9'
   */
  1U,

  /* Computed Parameter: Constant4_Value_b
   * Referenced by: '<Root>/Constant4'
   */
  1U,

  /* Computed Parameter: Constant6_Value_e
   * Referenced by: '<Root>/Constant6'
   */
  0U,

  /* Computed Parameter: Constant13_Value_d
   * Referenced by: '<Root>/Constant13'
   */
  0U,

  /* Computed Parameter: RGBLED0state_InitialValue
   * Referenced by: '<Root>/RGBLED0state'
   */
  { 0U, 0U, 0U },

  /* Start of '<S1>/触发器9' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S30>/Magnification'
     */
    1450.0F,

    /* Computed Parameter: u_Y0
     * Referenced by: '<S30>/u'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S30>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S30>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S30>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器9' */

  /* Start of '<S1>/触发器8' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S29>/Magnification'
     */
    1450.0F,

    /* Computed Parameter: u_Y0
     * Referenced by: '<S29>/u'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S29>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S29>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S29>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器8' */

  /* Start of '<S1>/触发器7' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S28>/Magnification'
     */
    1450.0F,

    /* Computed Parameter: u_Y0
     * Referenced by: '<S28>/u'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S28>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S28>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S28>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器7' */

  /* Start of '<S1>/触发器6' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S27>/Magnification'
     */
    1450.0F,

    /* Computed Parameter: u_Y0
     * Referenced by: '<S27>/u'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S27>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S27>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S27>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器6' */

  /* Start of '<S1>/触发器5' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S26>/Magnification'
     */
    300.0F,

    /* Computed Parameter: u1_Y0
     * Referenced by: '<S26>/u1'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S26>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S26>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S26>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器5' */

  /* Start of '<S1>/触发器4' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S25>/Magnification'
     */
    300.0F,

    /* Computed Parameter: u1_Y0
     * Referenced by: '<S25>/u1'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S25>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S25>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S25>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器4' */

  /* Start of '<S1>/触发器3' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S24>/Magnification'
     */
    300.0F,

    /* Computed Parameter: u1_Y0
     * Referenced by: '<S24>/u1'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S24>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S24>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S24>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器3' */

  /* Start of '<S1>/触发器2' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S23>/Magnification'
     */
    300.0F,

    /* Computed Parameter: u1_Y0
     * Referenced by: '<S23>/u1'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S23>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S23>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S23>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器2' */

  /* Start of '<S1>/触发器11' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S22>/Magnification'
     */
    1450.0F,

    /* Computed Parameter: u_Y0
     * Referenced by: '<S22>/u'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S22>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S22>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S22>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器11' */

  /* Start of '<S1>/触发器10' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S21>/Magnification'
     */
    1450.0F,

    /* Computed Parameter: u_Y0
     * Referenced by: '<S21>/u'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S21>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S21>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S21>/Vref'
     */
    5U
  }
  ,

  /* End of '<S1>/触发器10' */

  /* Start of '<S1>/触发器1' */
  {
    /* Computed Parameter: Magnification_Gain
     * Referenced by: '<S20>/Magnification'
     */
    300.0F,

    /* Computed Parameter: u1_Y0
     * Referenced by: '<S20>/u1'
     */
    0U,

    /* Expression: 0b111111111111
     * Referenced by: '<S20>/ADC resolution'
     */
    4095U,

    /* Computed Parameter: Ris_Value
     * Referenced by: '<S20>/Ris'
     */
    650U,

    /* Computed Parameter: Vref_Value
     * Referenced by: '<S20>/Vref'
     */
    5U
  }
  /* End of '<S1>/触发器1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
