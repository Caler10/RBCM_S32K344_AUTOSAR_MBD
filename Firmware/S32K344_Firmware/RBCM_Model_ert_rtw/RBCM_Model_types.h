/*
 * File: RBCM_Model_types.h
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

#ifndef RTW_HEADER_RBCM_Model_types_h_
#define RTW_HEADER_RBCM_Model_types_h_
#include "Dio_Cfg.h"
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Bus_CAN_RX_MESSAG_
#define DEFINED_TYPEDEF_FOR_Bus_CAN_RX_MESSAG_

typedef struct {
  uint8_T Extended;
  uint32_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} Bus_CAN_RX_MESSAG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Bus_Hsd_Diagnose_Values_
#define DEFINED_TYPEDEF_FOR_Bus_Hsd_Diagnose_Values_

typedef struct {
  uint16_T DevicePwr_12v_lHsd1ch1;
  uint16_T BspdPwr_lHsd1ch2;
  uint16_T LoggerPwr_lHsd1ch3;
  uint16_T TempSensorPwr_lHsd1ch4;
  uint16_T DevicePwr_12v_lHsd2ch1;
  uint16_T VcuPwr_lHsd2ch2;
  uint16_T Fireon_Pwr_lHsd2ch3;
  uint16_T DsbdPwr_lHsd2ch4;
  uint16_T DrsPwr_8v_lHsd3ch1;
  uint16_T DevicePwr_lHsd3ch2;
  uint16_T BuzzerPwr_lHsd3ch3;
  uint16_T TaillightPwr_lHsd3ch4;
  uint16_T DevicePwr_5v_lHsd4ch1;
  uint16_T AccuUbr_lHsd4ch2;
  uint16_T AccuPwr_lHsd4ch3;
  uint16_T BduPwr_lHsd4ch4;
  uint16_T DevicePwr_5v_lHsd5ch1;
  uint16_T McuUbr_lHsd5ch2;
  uint16_T EnergeMeterPwr_lHsd5ch3;
  uint16_T TsalrPwr_lHsd5ch4;
  uint16_T ILPwr_hHsd1ch1;
  uint16_T DevicePwr_hHsd1ch2;
  uint16_T VcuUbr_hHsd2ch1;
  uint16_T Device_hHsd2ch2;
  uint16_T PumpPwr_hHsd3ch1;
  uint16_T AccuFanPwr_hHsd3ch2;
  uint16_T PumpFan1_hHsd4ch1;
  uint16_T PumpFan2_hHsd4ch2;
  uint16_T DevicePwr_hHsd5ch1;
  uint16_T DevicePwr_hHsd5ch2;
  uint16_T DevicePwr_hHsd6ch1;
  uint16_T DevicePwr_hHsd6ch2;
} Bus_Hsd_Diagnose_Values;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Bus_Hsd_Diagnose_Results_
#define DEFINED_TYPEDEF_FOR_Bus_Hsd_Diagnose_Results_

typedef struct {
  uint8_T DevicePwr_12v_lHsd1ch1;
  uint8_T BspdPwr_lHsd1ch2;
  uint8_T LoggerPwr_lHsd1ch3;
  uint8_T TempSensorPwr_lHsd1ch4;
  uint8_T DevicePwr_12v_lHsd2ch1;
  uint8_T VcuPwr_lHsd2ch2;
  uint8_T Fireon_Pwr_lHsd2ch3;
  uint8_T DsbdPwr_lHsd2ch4;
  uint8_T DrsPwr_8v_lHsd3ch1;
  uint8_T DevicePwr_lHsd3ch2;
  uint8_T BuzzerPwr_lHsd3ch3;
  uint8_T TaillightPwr_lHsd3ch4;
  uint8_T DevicePwr_5v_lHsd4ch1;
  uint8_T AccuUbr_lHsd4ch2;
  uint8_T AccuPwr_lHsd4ch3;
  uint8_T BduPwr_lHsd4ch4;
  uint8_T DevicePwr_5v_lHsd5ch1;
  uint8_T McuUbr_lHsd5ch2;
  uint8_T EnergeMeterPwr_lHsd5ch3;
  uint8_T TsalrPwr_lHsd5ch4;
  uint8_T ILPwr_hHsd1ch1;
  uint8_T DevicePwr_hHsd1ch2;
  uint8_T VcuUbr_hHsd2ch1;
  uint8_T Device_hHsd2ch2;
  uint8_T PumpPwr_hHsd3ch1;
  uint8_T AccuFanPwr_hHsd3ch2;
  uint8_T PumpFan1_hHsd4ch1;
  uint8_T PumpFan2_hHsd4ch2;
  uint8_T DevicePwr_hHsd5ch1;
  uint8_T DevicePwr_hHsd5ch2;
  uint8_T DevicePwr_hHsd6ch1;
  uint8_T DevicePwr_hHsd6ch2;
} Bus_Hsd_Diagnose_Results;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Bus_Hsd_Drive_Commands_
#define DEFINED_TYPEDEF_FOR_Bus_Hsd_Drive_Commands_

typedef struct {
  uint8_T DevicePwr_12v_lHsd1ch1;
  uint8_T BspdPwr_lHsd1ch2;
  uint8_T LoggerPwr_lHsd1ch3;
  uint8_T TempSensorPwr_lHsd1ch4;
  uint8_T DevicePwr_12v_lHsd2ch1;
  uint8_T VcuPwr_lHsd2ch2;
  uint8_T Fireon_Pwr_lHsd2ch3;
  uint8_T DsbdPwr_lHsd2ch4;
  uint8_T DrsPwr_8v_lHsd3ch1;
  uint8_T DevicePwr_lHsd3ch2;
  uint8_T BuzzerPwr_lHsd3ch3;
  uint8_T TaillightPwr_lHsd3ch4;
  uint8_T DevicePwr_5v_lHsd4ch1;
  uint8_T AccuUbr_lHsd4ch2;
  uint8_T AccuPwr_lHsd4ch3;
  uint8_T BduPwr_lHsd4ch4;
  uint8_T DevicePwr_5v_lHsd5ch1;
  uint8_T McuUbr_lHsd5ch2;
  uint8_T EnergeMeterPwr_lHsd5ch3;
  uint8_T TsalrPwr_lHsd5ch4;
  uint8_T ILPwr_hHsd1ch1;
  uint8_T DevicePwr_hHsd1ch2;
  uint8_T VcuUbr_hHsd2ch1;
  uint8_T Device_hHsd2ch2;
  uint8_T PumpPwr_hHsd3ch1;
  uint8_T AccuFanPwr_hHsd3ch2;
  uint8_T PumpFan1_hHsd4ch1;
  uint8_T PumpFan2_hHsd4ch2;
  uint8_T DevicePwr_hHsd5ch1;
  uint8_T DevicePwr_hHsd5ch2;
  uint8_T DevicePwr_hHsd6ch1;
  uint8_T DevicePwr_hHsd6ch2;
} Bus_Hsd_Drive_Commands;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Bus_Vbats_Data_
#define DEFINED_TYPEDEF_FOR_Bus_Vbats_Data_

typedef struct {
  uint16_T LvBatsV;
  uint16_T LvBatsI;
  uint16_T LvBatTemp1;
  uint16_T LvBatTemp2;
} Bus_Vbats_Data;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Bus_Vehicle_Data_
#define DEFINED_TYPEDEF_FOR_Bus_Vehicle_Data_

typedef struct {
  uint8_T ActButtonState;
  uint8_T ReadyButtonState;
  uint8_T McuReadyState;
  uint8_T DriveReadyState;
  uint16_T AccuV;
  uint16_T AccuI;
  uint16_T AccuTcmax;
  uint16_T AccudVmax;
  uint16_T McuT;
  uint16_T MotorRpm;
  uint16_T MotorTorque;
  uint16_T MotorTemp;
} Bus_Vehicle_Data;

#endif

/* Parameters for system: '<S2>/´¥·¢Æ÷1' */
typedef struct P_u_RBCM_Model_e_T_ P_u_RBCM_Model_e_T;

/* Parameters for system: '<S2>/´¥·¢Æ÷10' */
typedef struct P_u0_RBCM_Model_T_ P_u0_RBCM_Model_T;

/* Parameters (default storage) */
typedef struct P_RBCM_Model_T_ P_RBCM_Model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_RBCM_Model_T RT_MODEL_RBCM_Model_T;

#endif                                 /* RTW_HEADER_RBCM_Model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
