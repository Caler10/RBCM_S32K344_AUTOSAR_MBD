/*
 * File: RBCM_Model.h
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

#ifndef RTW_HEADER_RBCM_Model_h_
#define RTW_HEADER_RBCM_Model_h_
#ifndef RBCM_Model_COMMON_INCLUDES_
#define RBCM_Model_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Pwm.h"
#include "Adc.h"
#include "string.h"
#include "CDD_Uart.h"
#include "freemaster.h"
#include "sys_init.h"
#include "freemaster_s32k3xx_lpuart.h"
#include "Lpuart_Uart_Ip_HwAccess.h"
#include "mbdt_lpuart.h"
#endif                                 /* RBCM_Model_COMMON_INCLUDES_ */

#include "RBCM_Model_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "can_message.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S16>/Chart2' */
typedef struct {
  uint8_T is_active_c7_RBCM_Model;     /* '<S16>/Chart2' */
  uint8_T is_c7_RBCM_Model;            /* '<S16>/Chart2' */
} DW_Chart2_RBCM_Model_T;

/* Block states (default storage) for system '<S2>/数据转存单元1' */
typedef struct {
  uint8_T Y1;                          /* '<S2>/数据转存单元1' */
  uint8_T Y2;                          /* '<S2>/数据转存单元1' */
} DW_u_RBCM_Model_T;

/* Block states (default storage) for system '<S2>/数据转存单元11' */
typedef struct {
  uint16_T Y1;                         /* '<S2>/数据转存单元11' */
  uint16_T Y2;                         /* '<S2>/数据转存单元11' */
} DW_u1_RBCM_Model_T;

/* Block states (default storage) for system '<S2>/触发器1' */
typedef struct {
  real_T i;                            /* '<S2>/触发器1' */
  real_T output;                       /* '<S2>/触发器1' */
} DW_u_RBCM_Model_l_T;

/* Block states (default storage) for system '<S2>/触发器10' */
typedef struct {
  real_T i;                            /* '<S2>/触发器10' */
  real_T output;                       /* '<S2>/触发器10' */
} DW_u0_RBCM_Model_T;

/* Block states (default storage) for system '<S2>/诊断数据转存单元1' */
typedef struct {
  uint16_T Y1;                         /* '<S2>/诊断数据转存单元1' */
  uint16_T Y2;                         /* '<S2>/诊断数据转存单元1' */
  uint16_T Y3;                         /* '<S2>/诊断数据转存单元1' */
  uint16_T Y4;                         /* '<S2>/诊断数据转存单元1' */
} DW_u_RBCM_Model_b_T;

/* Block states (default storage) for system '<S2>/错误码转存单元1' */
typedef struct {
  uint8_T Y1;                          /* '<S2>/错误码转存单元1' */
  uint8_T Y2;                          /* '<S2>/错误码转存单元1' */
  uint8_T Y3;                          /* '<S2>/错误码转存单元1' */
  uint8_T Y4;                          /* '<S2>/错误码转存单元1' */
} DW_u_RBCM_Model_lj_T;

/* Block signals (default storage) */
typedef struct {
  char_T cv[1024];
  char_T rtb_ComposeString2_m[256];
  char_T rtb_ComposeString3_c[256];
  char_T rtb_StringConcatenate2_k[256];
  char_T rtb_ComposeString5_c[256];
  char_T rtb_ComposeString6_b[256];
  char_T rtb_ComposeString7_p[256];
  char_T rtb_ComposeString8_c[256];
  char_T rtb_StringConcatenate3_f[256];
  char_T rtb_ComposeString9_g[256];
  char_T rtb_ComposeString10_g[256];
  char_T rtb_ComposeString11_m[256];
  char_T rtb_ComposeString12_n[256];
  char_T rtb_StringConcatenate4_p[256];
  char_T rtb_ComposeString13_l[256];
  char_T rtb_ComposeString14_j[256];
  char_T rtb_ComposeString15_d[256];
  char_T rtb_StringConcatenate5_g[256];
  char_T rtb_StringConcatenate_l[256];
  Bus_Hsd_Diagnose_Values BusHsdDiagnoseValues;/* '<S2>/BusHsdDiagnoseValues' */
  Bus_Hsd_Drive_Commands HsdDriveCommands;/* '<S13>/HsdDriveCommands' */
  Bus_Hsd_Drive_Commands HsdDriveCommandsInit;/* '<Root>/HsdDriveCommand Struct1' */
  Bus_Hsd_Drive_Commands HsdDriveCommandsCAN;/* '<S106>/HsdDriveCommandsCAN' */
  Bus_Hsd_Diagnose_Results BusHsdDiagnoseResults;/* '<S2>/BusHsdDiagnoseResults' */
  Bus_CAN_RX_MESSAG Delay;             /* '<Root>/Delay' */
  CAN_MESSAGE_BUS CANPack;             /* '<S22>/CAN Pack' */
  CAN_MESSAGE_BUS CANPack_h;           /* '<S21>/CAN Pack' */
  CAN_MESSAGE_BUS CANPack_c;           /* '<S20>/CAN Pack' */
  Bus_Vehicle_Data VehicleData;        /* '<S106>/VehicleData' */
  char_T output[256];                  /* '<Root>/4G通信控制状态机1' */
  real_T Switch;                       /* '<S20>/Switch' */
  Bus_Vbats_Data Bus_Vbats_Data_j;
  Bus_Vbats_Data VbatsData;            /* '<S15>/VbatsData' */
  uint32_T Hardware_Interrupt_Handler4_o2;
                                      /* '<Root>/Hardware_Interrupt_Handler4' */
  uint32_T Hardware_Interrupt_Handler4_o3;
                                      /* '<Root>/Hardware_Interrupt_Handler4' */
  uint32_T ID;                        /* '<Root>/Hardware_Interrupt_Handler4' */
  uint32_T Length;                    /* '<Root>/Hardware_Interrupt_Handler4' */
  uint32_T u;                          /* '<Root>/Hardware_Interrupt_Handler' */
  uint32_T Adc;                        /* '<S8>/Adc' */
  uint32_T Adc2;                       /* '<S8>/Adc2' */
  uint32_T Adc4;                       /* '<S8>/Adc4' */
  uint16_T DataStoreRead[6];           /* '<S8>/Data Store Read' */
  uint16_T DataStoreRead1[3];          /* '<S8>/Data Store Read1' */
  uint16_T DataStoreRead2[5];          /* '<S8>/Data Store Read2' */
  uint16_T Adc1_o1;                    /* '<S12>/Adc1' */
  uint16_T Adc1_o2;                    /* '<S12>/Adc1' */
  uint16_T Adc1_o3[5];                 /* '<S12>/Adc1' */
  uint16_T Adc1_o1_i;                  /* '<S11>/Adc1' */
  uint16_T Adc1_o2_c;                  /* '<S11>/Adc1' */
  uint16_T Adc1_o3_a[3];               /* '<S11>/Adc1' */
  uint16_T Adc1_o1_l;                  /* '<S9>/Adc1' */
  uint16_T Adc1_o2_cp;                 /* '<S9>/Adc1' */
  uint16_T Adc1_o3_l[6];               /* '<S9>/Adc1' */
  uint16_T DataTypeConversion1;        /* '<S33>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_a;      /* '<S32>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_d;      /* '<S31>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_b;      /* '<S30>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_m;      /* '<S29>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_m3;     /* '<S28>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_a4;     /* '<S27>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_du;     /* '<S26>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_l;      /* '<S25>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_g;      /* '<S24>/Data Type Conversion1' */
  uint16_T DataTypeConversion1_o;      /* '<S23>/Data Type Conversion1' */
  uint16_T DataTypeConversion4;        /* '<S17>/Data Type Conversion4' */
  uint8_T Data[8];                    /* '<Root>/Hardware_Interrupt_Handler4' */
  uint8_T Hardware_Interrupt_Handler_o2;/* '<Root>/Hardware_Interrupt_Handler' */
  uint8_T Uart;                        /* '<S14>/Uart' */
  uint8_T Uart1_o1[41];                /* '<Root>/Uart1' */
  uint8_T Uart1_o2;                    /* '<Root>/Uart1' */
  uint8_T y[1026];                     /* '<S14>/Add '\r\n'2' */
  uint8_T Can;                         /* '<S8>/Can' */
  uint8_T OutportBufferForDrsDriveCommand;/* '<S18>/Subsystem3' */
  uint8_T CANUnpack_o1;                /* '<S106>/CAN Unpack' */
  uint8_T CANUnpack_o2;                /* '<S106>/CAN Unpack' */
  uint8_T CANUnpack_o3;                /* '<S106>/CAN Unpack' */
  uint8_T CANUnpack_o4;                /* '<S106>/CAN Unpack' */
  uint8_T CANUnpack_o5;                /* '<S106>/CAN Unpack' */
  uint8_T CANUnpack_o6;                /* '<S106>/CAN Unpack' */
  uint8_T CANUnpack_o7;                /* '<S106>/CAN Unpack' */
  uint8_T BitwiseAND2;                 /* '<S40>/Bitwise AND2' */
  uint8_T ShiftArithmetic1;            /* '<S40>/Shift Arithmetic1' */
  uint8_T BitwiseAND2_h;               /* '<S41>/Bitwise AND2' */
  uint8_T ShiftArithmetic1_c;          /* '<S41>/Shift Arithmetic1' */
  uint8_T BitwiseAND2_a;               /* '<S42>/Bitwise AND2' */
  uint8_T ShiftArithmetic1_b;          /* '<S42>/Shift Arithmetic1' */
  uint8_T BitwiseAND2_d;               /* '<S43>/Bitwise AND2' */
  uint8_T ShiftArithmetic1_n;          /* '<S43>/Shift Arithmetic1' */
  uint8_T BitwiseAND2_ht;              /* '<S44>/Bitwise AND2' */
  uint8_T ShiftArithmetic1_d;          /* '<S44>/Shift Arithmetic1' */
  uint8_T y_h;                         /* '<S2>/触发器9' */
  uint8_T y_c;                         /* '<S2>/触发器8' */
  uint8_T y_l;                         /* '<S2>/触发器7' */
  uint8_T y_k;                         /* '<S2>/触发器11' */
  uint8_T y_l0;                        /* '<S2>/触发器10' */
  uint8_T Can_k;                       /* '<S22>/Can' */
  uint8_T Can_l;                       /* '<S21>/Can' */
  uint8_T Can_c;                       /* '<S20>/Can' */
  uint8_T Dio1;                        /* '<S19>/Dio1' */
  uint8_T DataStoreRead_o1;            /* '<S16>/Data Store Read' */
  uint8_T DataStoreRead_o2;            /* '<S16>/Data Store Read' */
  uint8_T DataStoreRead_o3;            /* '<S16>/Data Store Read' */
} B_RBCM_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Bus_CAN_RX_MESSAG Delay_DSTATE;      /* '<Root>/Delay' */
  char_T TmpRTBAt4G1Inport3_Buffer[256];/* synthesized block */
  Bus_Vbats_Data Bus_Vbats_Data_Buffer;/* synthesized block */
  char_T B[256];                       /* '<Root>/4G通信控制状态机1' */
  char_T C[256];                       /* '<Root>/4G通信控制状态机1' */
  char_T D[256];                       /* '<Root>/4G通信控制状态机1' */
  char_T A[256];                       /* '<Root>/4G通信控制状态机1' */
  int_T CANUnpack_ModeSignalID;        /* '<S106>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S106>/CAN Unpack' */
  int_T CANPack_ModeSignalID;          /* '<S22>/CAN Pack' */
  int_T CANPack_ModeSignalID_f;        /* '<S21>/CAN Pack' */
  int_T CANPack_ModeSignalID_j;        /* '<S20>/CAN Pack' */
  uint16_T Temp_AdcBuffer;             /* '<Root>/Data Store Memory2' */
  uint16_T Bats_Monitor_AdcBuffer[2];  /* '<Root>/Data Store Memory4' */
  uint16_T hHsd_Diagnose_AdcBuffer[6]; /* '<Root>/Data Store Memory5' */
  uint16_T lHsd_Diagnose_AdcBuffer[5]; /* '<Root>/Data Store Memory6' */
  uint8_T RGBLED0state[3];             /* '<Root>/RGBLED0state' */
  uint8_T counter;                     /* '<Root>/4G通信控制状态机1' */
  uint8_T is_c72_RBCM_Model;           /* '<Root>/4G通信控制状态机1' */
  DW_Chart2_RBCM_Model_T sf_Chart1_o;  /* '<S18>/Chart1' */
  DW_u_RBCM_Model_lj_T sf_4_c;         /* '<S2>/错误码转存单元4' */
  DW_u_RBCM_Model_lj_T sf_3_b;         /* '<S2>/错误码转存单元3' */
  DW_u_RBCM_Model_lj_T sf_2_o;         /* '<S2>/错误码转存单元2' */
  DW_u_RBCM_Model_lj_T sf_10_o;        /* '<S2>/错误码转存单元10' */
  DW_u_RBCM_Model_lj_T sf_1_g;         /* '<S2>/错误码转存单元1' */
  DW_u_RBCM_Model_b_T sf_5_d;          /* '<S2>/诊断数据转存单元5' */
  DW_u_RBCM_Model_b_T sf_4_k;          /* '<S2>/诊断数据转存单元4' */
  DW_u_RBCM_Model_b_T sf_3_k;          /* '<S2>/诊断数据转存单元3' */
  DW_u_RBCM_Model_b_T sf_2_p;          /* '<S2>/诊断数据转存单元2' */
  DW_u_RBCM_Model_b_T sf_1_k;          /* '<S2>/诊断数据转存单元1' */
  DW_u0_RBCM_Model_T sf_9_a;           /* '<S2>/触发器9' */
  DW_u0_RBCM_Model_T sf_8_j;           /* '<S2>/触发器8' */
  DW_u0_RBCM_Model_T sf_7_p;           /* '<S2>/触发器7' */
  DW_u0_RBCM_Model_T sf_6_o;           /* '<S2>/触发器6' */
  DW_u_RBCM_Model_l_T sf_5_c;          /* '<S2>/触发器5' */
  DW_u_RBCM_Model_l_T sf_4_a;          /* '<S2>/触发器4' */
  DW_u_RBCM_Model_l_T sf_3_c;          /* '<S2>/触发器3' */
  DW_u_RBCM_Model_l_T sf_2_l;          /* '<S2>/触发器2' */
  DW_u0_RBCM_Model_T sf_11_a;          /* '<S2>/触发器11' */
  DW_u0_RBCM_Model_T sf_10_a;          /* '<S2>/触发器10' */
  DW_u_RBCM_Model_l_T sf_1_o;          /* '<S2>/触发器1' */
  DW_u1_RBCM_Model_T sf_9;             /* '<S2>/数据转存单元9' */
  DW_u_RBCM_Model_T sf_8;              /* '<S2>/数据转存单元8' */
  DW_u1_RBCM_Model_T sf_7;             /* '<S2>/数据转存单元7' */
  DW_u_RBCM_Model_T sf_6;              /* '<S2>/数据转存单元6' */
  DW_u1_RBCM_Model_T sf_5;             /* '<S2>/数据转存单元5' */
  DW_u_RBCM_Model_T sf_4;              /* '<S2>/数据转存单元4' */
  DW_u1_RBCM_Model_T sf_3;             /* '<S2>/数据转存单元3' */
  DW_u_RBCM_Model_T sf_2;              /* '<S2>/数据转存单元2' */
  DW_u1_RBCM_Model_T sf_12;            /* '<S2>/数据转存单元12' */
  DW_u1_RBCM_Model_T sf_11;            /* '<S2>/数据转存单元11' */
  DW_u_RBCM_Model_T sf_10;             /* '<S2>/数据转存单元10' */
  DW_u_RBCM_Model_T sf_1;              /* '<S2>/数据转存单元1' */
  DW_Chart2_RBCM_Model_T sf_Chart1;    /* '<S20>/Chart1' */
  DW_Chart2_RBCM_Model_T sf_Chart2;    /* '<S16>/Chart2' */
} DW_RBCM_Model_T;

/* Parameters for system: '<S2>/触发器1' */
struct P_u_RBCM_Model_e_T_ {
  real32_T Magnification_Gain;         /* Computed Parameter: Magnification_Gain
                                        * Referenced by: '<S23>/Magnification'
                                        */
  uint16_T u1_Y0;                      /* Computed Parameter: u1_Y0
                                        * Referenced by: '<S23>/u1'
                                        */
  uint16_T ADCresolution_Value;        /* Expression: 0b111111111111
                                        * Referenced by: '<S23>/ADC resolution'
                                        */
  uint16_T Ris_Value;                  /* Computed Parameter: Ris_Value
                                        * Referenced by: '<S23>/Ris'
                                        */
  uint8_T Vref_Value;                  /* Computed Parameter: Vref_Value
                                        * Referenced by: '<S23>/Vref'
                                        */
};

/* Parameters for system: '<S2>/触发器10' */
struct P_u0_RBCM_Model_T_ {
  real32_T Magnification_Gain;         /* Computed Parameter: Magnification_Gain
                                        * Referenced by: '<S24>/Magnification'
                                        */
  uint16_T u_Y0;                       /* Computed Parameter: u_Y0
                                        * Referenced by: '<S24>/u'
                                        */
  uint16_T ADCresolution_Value;        /* Expression: 0b111111111111
                                        * Referenced by: '<S24>/ADC resolution'
                                        */
  uint16_T Ris_Value;                  /* Computed Parameter: Ris_Value
                                        * Referenced by: '<S24>/Ris'
                                        */
  uint8_T Vref_Value;                  /* Computed Parameter: Vref_Value
                                        * Referenced by: '<S24>/Vref'
                                        */
};

/* Parameters (default storage) */
struct P_RBCM_Model_T_ {
  uint8_T BitwiseAND2_BitMask;         /* Mask Parameter: BitwiseAND2_BitMask
                                        * Referenced by: '<S40>/Bitwise AND2'
                                        */
  uint8_T BitwiseAND3_BitMask;         /* Mask Parameter: BitwiseAND3_BitMask
                                        * Referenced by: '<S40>/Bitwise AND3'
                                        */
  uint8_T BitwiseAND2_BitMask_f;       /* Mask Parameter: BitwiseAND2_BitMask_f
                                        * Referenced by: '<S41>/Bitwise AND2'
                                        */
  uint8_T BitwiseAND3_BitMask_k;       /* Mask Parameter: BitwiseAND3_BitMask_k
                                        * Referenced by: '<S41>/Bitwise AND3'
                                        */
  uint8_T BitwiseAND2_BitMask_i;       /* Mask Parameter: BitwiseAND2_BitMask_i
                                        * Referenced by: '<S42>/Bitwise AND2'
                                        */
  uint8_T BitwiseAND3_BitMask_kw;      /* Mask Parameter: BitwiseAND3_BitMask_kw
                                        * Referenced by: '<S42>/Bitwise AND3'
                                        */
  uint8_T BitwiseAND2_BitMask_l;       /* Mask Parameter: BitwiseAND2_BitMask_l
                                        * Referenced by: '<S43>/Bitwise AND2'
                                        */
  uint8_T BitwiseAND3_BitMask_n;       /* Mask Parameter: BitwiseAND3_BitMask_n
                                        * Referenced by: '<S43>/Bitwise AND3'
                                        */
  uint8_T BitwiseAND2_BitMask_h;       /* Mask Parameter: BitwiseAND2_BitMask_h
                                        * Referenced by: '<S44>/Bitwise AND2'
                                        */
  uint8_T BitwiseAND3_BitMask_b;       /* Mask Parameter: BitwiseAND3_BitMask_b
                                        * Referenced by: '<S44>/Bitwise AND3'
                                        */
  Bus_Hsd_Diagnose_Values Out1_Y0;     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  Bus_CAN_RX_MESSAG Delay_InitialCondition;
                                   /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  Bus_Hsd_Diagnose_Results Out2_Y0;    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S2>/Out2'
                                        */
  Bus_Hsd_Drive_Commands HsdDriveCommands_Y0;
                                      /* Computed Parameter: HsdDriveCommands_Y0
                                       * Referenced by: '<S18>/HsdDriveCommands'
                                       */
  Bus_Vbats_Data Out2_Y0_c;            /* Computed Parameter: Out2_Y0_c
                                        * Referenced by: '<S15>/Out2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Step2_Time;                   /* Expression: 3
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  char_T StringConstant_String[256];   /* Expression: "{"
                                        * Referenced by: '<S5>/String Constant'
                                        */
  char_T StringConstant1_String[256];  /* Expression: "}"
                                        * Referenced by: '<S5>/String Constant1'
                                        */
  int32_T Hardware_Interrupt_Handler4_P1[13];/* Expression: funcParams
                                              * Referenced by: '<Root>/Hardware_Interrupt_Handler4'
                                              */
  int32_T Hardware_Interrupt_Handler_P1[7];/* Expression: funcParams
                                            * Referenced by: '<Root>/Hardware_Interrupt_Handler'
                                            */
  int32_T Hardware_Interrupt_Handler1_P1[3];/* Expression: funcParams
                                             * Referenced by: '<Root>/Hardware_Interrupt_Handler1'
                                             */
  int32_T Hardware_Interrupt_Handler2_P1[3];/* Expression: funcParams
                                             * Referenced by: '<Root>/Hardware_Interrupt_Handler2'
                                             */
  int32_T Hardware_Interrupt_Handler5_P1[3];/* Expression: funcParams
                                             * Referenced by: '<Root>/Hardware_Interrupt_Handler5'
                                             */
  real32_T Magnification_Gain;         /* Computed Parameter: Magnification_Gain
                                        * Referenced by: '<S15>/Magnification'
                                        */
  real32_T Magnification1_Gain;       /* Computed Parameter: Magnification1_Gain
                                       * Referenced by: '<S15>/Magnification1'
                                       */
  uint32_T Dio_P1[2];                  /* Expression: funcParams
                                        * Referenced by: '<S16>/Dio'
                                        */
  uint32_T Dio1_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S16>/Dio1'
                                        */
  uint32_T Dio2_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S16>/Dio2'
                                        */
  uint32_T Dio3_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S16>/Dio3'
                                        */
  uint32_T Dio_P1_d[2];                /* Expression: funcParams
                                        * Referenced by: '<S107>/Dio'
                                        */
  uint32_T Dio1_P1_o[2];               /* Expression: funcParams
                                        * Referenced by: '<S107>/Dio1'
                                        */
  uint32_T Dio_P1_k[2];                /* Expression: funcParams
                                        * Referenced by: '<S108>/Dio'
                                        */
  uint32_T Dio1_P1_oz[2];              /* Expression: funcParams
                                        * Referenced by: '<S19>/Dio1'
                                        */
  uint32_T Can_P1;                     /* Expression: funcParams
                                        * Referenced by: '<S20>/Can'
                                        */
  uint32_T Can_P1_m;                   /* Expression: funcParams
                                        * Referenced by: '<S21>/Can'
                                        */
  uint32_T Can_P1_f;                   /* Expression: funcParams
                                        * Referenced by: '<S22>/Can'
                                        */
  uint32_T Pwm_P1[3];                  /* Expression: funcParam
                                        * Referenced by: '<S17>/Pwm'
                                        */
  uint32_T Dio_P1_n[2];                /* Expression: funcParams
                                        * Referenced by: '<S35>/Dio'
                                        */
  uint32_T Dio_P1_dk[2];               /* Expression: funcParams
                                        * Referenced by: '<S36>/Dio'
                                        */
  uint32_T Dio_P1_o[2];                /* Expression: funcParams
                                        * Referenced by: '<S37>/Dio'
                                        */
  uint32_T Dio_P1_h[2];                /* Expression: funcParams
                                        * Referenced by: '<S38>/Dio'
                                        */
  uint32_T Dio_P1_oe[2];               /* Expression: funcParams
                                        * Referenced by: '<S39>/Dio'
                                        */
  uint32_T Dio_P1_c[2];                /* Expression: funcParams
                                        * Referenced by: '<S40>/Dio'
                                        */
  uint32_T Dio1_P1_h[2];               /* Expression: funcParams
                                        * Referenced by: '<S40>/Dio1'
                                        */
  uint32_T Dio_P1_i[2];                /* Expression: funcParams
                                        * Referenced by: '<S41>/Dio'
                                        */
  uint32_T Dio1_P1_l[2];               /* Expression: funcParams
                                        * Referenced by: '<S41>/Dio1'
                                        */
  uint32_T Dio_P1_op[2];               /* Expression: funcParams
                                        * Referenced by: '<S42>/Dio'
                                        */
  uint32_T Dio1_P1_lk[2];              /* Expression: funcParams
                                        * Referenced by: '<S42>/Dio1'
                                        */
  uint32_T Dio_P1_dl[2];               /* Expression: funcParams
                                        * Referenced by: '<S43>/Dio'
                                        */
  uint32_T Dio1_P1_f[2];               /* Expression: funcParams
                                        * Referenced by: '<S43>/Dio1'
                                        */
  uint32_T Dio_P1_l[2];                /* Expression: funcParams
                                        * Referenced by: '<S44>/Dio'
                                        */
  uint32_T Dio1_P1_k[2];               /* Expression: funcParams
                                        * Referenced by: '<S44>/Dio1'
                                        */
  uint32_T Dio1_P1_g[2];               /* Expression: funcParams
                                        * Referenced by: '<S89>/Dio1'
                                        */
  uint32_T Dio_P1_p[2];                /* Expression: funcParams
                                        * Referenced by: '<S90>/Dio'
                                        */
  uint32_T Dio1_P1_m[2];               /* Expression: funcParams
                                        * Referenced by: '<S90>/Dio1'
                                        */
  uint32_T Dio_P1_e[2];                /* Expression: funcParams
                                        * Referenced by: '<S91>/Dio'
                                        */
  uint32_T Dio1_P1_j[2];               /* Expression: funcParams
                                        * Referenced by: '<S91>/Dio1'
                                        */
  uint32_T Dio_P1_kb[2];               /* Expression: funcParams
                                        * Referenced by: '<S92>/Dio'
                                        */
  uint32_T Dio1_P1_j3[2];              /* Expression: funcParams
                                        * Referenced by: '<S92>/Dio1'
                                        */
  uint32_T Dio_P1_j[2];                /* Expression: funcParams
                                        * Referenced by: '<S93>/Dio'
                                        */
  uint32_T Dio1_P1_p[2];               /* Expression: funcParams
                                        * Referenced by: '<S93>/Dio1'
                                        */
  uint32_T Dio_P1_or[2];               /* Expression: funcParams
                                        * Referenced by: '<S94>/Dio'
                                        */
  uint32_T Dio1_P1_jj[2];              /* Expression: funcParams
                                        * Referenced by: '<S94>/Dio1'
                                        */
  uint32_T Dio_P1_g[2];                /* Expression: funcParams
                                        * Referenced by: '<S95>/Dio'
                                        */
  uint32_T Dio1_P1_p4[2];              /* Expression: funcParams
                                        * Referenced by: '<S95>/Dio1'
                                        */
  uint32_T Dio2_P1_c[2];               /* Expression: funcParams
                                        * Referenced by: '<S95>/Dio2'
                                        */
  uint32_T Dio3_P1_a[2];               /* Expression: funcParams
                                        * Referenced by: '<S95>/Dio3'
                                        */
  uint32_T Dio_P1_iq[2];               /* Expression: funcParams
                                        * Referenced by: '<S96>/Dio'
                                        */
  uint32_T Dio1_P1_h0[2];              /* Expression: funcParams
                                        * Referenced by: '<S96>/Dio1'
                                        */
  uint32_T Dio4_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S96>/Dio4'
                                        */
  uint32_T Dio3_P1_o[2];               /* Expression: funcParams
                                        * Referenced by: '<S96>/Dio3'
                                        */
  uint32_T Dio_P1_dv[2];               /* Expression: funcParams
                                        * Referenced by: '<S97>/Dio'
                                        */
  uint32_T Dio1_P1_ko[2];              /* Expression: funcParams
                                        * Referenced by: '<S97>/Dio1'
                                        */
  uint32_T Dio2_P1_h[2];               /* Expression: funcParams
                                        * Referenced by: '<S97>/Dio2'
                                        */
  uint32_T Dio3_P1_i[2];               /* Expression: funcParams
                                        * Referenced by: '<S97>/Dio3'
                                        */
  uint32_T Dio_P1_e3[2];               /* Expression: funcParams
                                        * Referenced by: '<S98>/Dio'
                                        */
  uint32_T Dio1_P1_ga[2];              /* Expression: funcParams
                                        * Referenced by: '<S98>/Dio1'
                                        */
  uint32_T Dio2_P1_e[2];               /* Expression: funcParams
                                        * Referenced by: '<S98>/Dio2'
                                        */
  uint32_T Dio3_P1_az[2];              /* Expression: funcParams
                                        * Referenced by: '<S98>/Dio3'
                                        */
  uint32_T Dio_P1_ll[2];               /* Expression: funcParams
                                        * Referenced by: '<S99>/Dio'
                                        */
  uint32_T Dio1_P1_gc[2];              /* Expression: funcParams
                                        * Referenced by: '<S99>/Dio1'
                                        */
  uint32_T Dio2_P1_l[2];               /* Expression: funcParams
                                        * Referenced by: '<S99>/Dio2'
                                        */
  uint32_T Dio3_P1_j[2];               /* Expression: funcParams
                                        * Referenced by: '<S99>/Dio3'
                                        */
  uint32_T Adc1_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S9>/Adc1'
                                        */
  uint32_T Adc1_P1_c;                  /* Expression: funcParam
                                        * Referenced by: '<S11>/Adc1'
                                        */
  uint32_T Adc1_P1_m;                  /* Expression: funcParam
                                        * Referenced by: '<S12>/Adc1'
                                        */
  uint32_T Adc_P1;                     /* Expression: funcParam
                                        * Referenced by: '<S8>/Adc'
                                        */
  uint32_T Adc2_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S8>/Adc2'
                                        */
  uint32_T Adc4_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S8>/Adc4'
                                        */
  uint32_T Can_P1_h;                   /* Expression: funcParams
                                        * Referenced by: '<S8>/Can'
                                        */
  uint32_T Dio11_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio11'
                                        */
  uint32_T Dio12_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio12'
                                        */
  uint32_T Dio13_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio13'
                                        */
  uint32_T Dio14_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio14'
                                        */
  uint32_T Dio15_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio15'
                                        */
  uint32_T Dio3_P1_h[2];               /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio3'
                                        */
  uint32_T Dio4_P1_c[2];               /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio4'
                                        */
  uint32_T Dio5_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio5'
                                        */
  uint32_T Dio6_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio6'
                                        */
  uint32_T Dio7_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio7'
                                        */
  uint32_T Dio8_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio8'
                                        */
  uint32_T Dio9_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S8>/Dio9'
                                        */
  uint32_T Adc1_P1_i;                  /* Expression: funcParam
                                        * Referenced by: '<S8>/Adc1'
                                        */
  uint32_T Adc3_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S8>/Adc3'
                                        */
  uint32_T Adc5_P1;                    /* Expression: funcParam
                                        * Referenced by: '<S8>/Adc5'
                                        */
  uint32_T Can1_P1;                    /* Expression: funcParams
                                        * Referenced by: '<S8>/Can1'
                                        */
  uint32_T Can2_P1;                    /* Expression: funcParams
                                        * Referenced by: '<S8>/Can2'
                                        */
  uint32_T Uart_P1[2];                 /* Expression: funcParams
                                        * Referenced by: '<S14>/Uart'
                                        */
  uint32_T BitwiseAND_BitMask;         /* Expression: BitMask
                                        * Referenced by: '<Root>/Bitwise AND'
                                        */
  uint32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint32_T Uart1_P1[2];                /* Expression: funcParams
                                        * Referenced by: '<Root>/Uart1'
                                        */
  uint32_T Adc1_P1_b;                  /* Expression: funcParam
                                        * Referenced by: '<Root>/Adc1'
                                        */
  uint32_T Adc2_P1_h;                  /* Expression: funcParam
                                        * Referenced by: '<Root>/Adc2'
                                        */
  uint32_T Adc3_P1_o;                  /* Expression: funcParam
                                        * Referenced by: '<Root>/Adc3'
                                        */
  uint32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S45>/Gain'
                                        */
  uint16_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S48>/Gain'
                                        */
  uint16_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S49>/Gain'
                                        */
  uint16_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S50>/Gain'
                                        */
  uint16_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S51>/Gain'
                                        */
  uint16_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S46>/Gain'
                                        */
  uint16_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S52>/Gain'
                                        */
  uint16_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S53>/Gain'
                                        */
  uint16_T Gain_Gain_lr;               /* Computed Parameter: Gain_Gain_lr
                                        * Referenced by: '<S54>/Gain'
                                        */
  uint16_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S55>/Gain'
                                        */
  uint16_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S47>/Gain'
                                        */
  uint16_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S20>/Constant4'
                                        */
  uint16_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S21>/Constant'
                                        */
  uint16_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint16_T RbcmCoreData_Y0;            /* Computed Parameter: RbcmCoreData_Y0
                                        * Referenced by: '<S15>/RbcmCoreData'
                                        */
  uint16_T ADCresolution_Value;        /* Expression: 0b111111111111
                                        * Referenced by: '<S15>/ADC resolution'
                                        */
  uint16_T ADCresolution1_Value;       /* Expression: 0b111111111111
                                        * Referenced by: '<S15>/ADC resolution1'
                                        */
  uint16_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S15>/Constant'
                                        */
  uint16_T Constant1_Value_d;          /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S15>/Constant1'
                                        */
  uint16_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S106>/Constant10'
                                        */
  uint16_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S106>/Constant11'
                                        */
  uint16_T Constant4_Value_h;          /* Computed Parameter: Constant4_Value_h
                                        * Referenced by: '<S106>/Constant4'
                                        */
  uint16_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S106>/Constant5'
                                        */
  uint16_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S106>/Constant6'
                                        */
  uint16_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S106>/Constant7'
                                        */
  uint16_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S106>/Constant8'
                                        */
  uint16_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S106>/Constant9'
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
  uint8_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S107>/Constant'
                                        */
  uint8_T Constant1_Value_n;           /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S107>/Constant1'
                                        */
  uint8_T Constant_Value_bb;           /* Computed Parameter: Constant_Value_bb
                                        * Referenced by: '<S108>/Constant'
                                        */
  uint8_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S20>/Constant'
                                        */
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S20>/Switch'
                                        */
  uint8_T Constant2_Value_i;           /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S21>/Constant2'
                                        */
  uint8_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S21>/Constant3'
                                        */
  uint8_T Constant2_Value_ig;          /* Computed Parameter: Constant2_Value_ig
                                        * Referenced by: '<S22>/Constant2'
                                        */
  uint8_T Constant3_Value_n;           /* Computed Parameter: Constant3_Value_n
                                        * Referenced by: '<S22>/Constant3'
                                        */
  uint8_T Constant2_Value_o;           /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S45>/Constant2'
                                        */
  uint8_T Constant3_Value_f;           /* Computed Parameter: Constant3_Value_f
                                        * Referenced by: '<S45>/Constant3'
                                        */
  uint8_T Constant4_Value_m;           /* Computed Parameter: Constant4_Value_m
                                        * Referenced by: '<S45>/Constant4'
                                        */
  uint8_T Constant_Value_k;            /* Expression: 0xff
                                        * Referenced by: '<S45>/Constant'
                                        */
  uint8_T Constant2_Value_p;           /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S46>/Constant2'
                                        */
  uint8_T Constant3_Value_c;           /* Computed Parameter: Constant3_Value_c
                                        * Referenced by: '<S46>/Constant3'
                                        */
  uint8_T Constant4_Value_f;           /* Computed Parameter: Constant4_Value_f
                                        * Referenced by: '<S46>/Constant4'
                                        */
  uint8_T Constant_Value_c;            /* Expression: 0xff
                                        * Referenced by: '<S46>/Constant'
                                        */
  uint8_T Constant2_Value_k;           /* Computed Parameter: Constant2_Value_k
                                        * Referenced by: '<S47>/Constant2'
                                        */
  uint8_T Constant3_Value_a;           /* Computed Parameter: Constant3_Value_a
                                        * Referenced by: '<S47>/Constant3'
                                        */
  uint8_T Constant4_Value_n;           /* Computed Parameter: Constant4_Value_n
                                        * Referenced by: '<S47>/Constant4'
                                        */
  uint8_T Constant_Value_c3;           /* Expression: 0xff
                                        * Referenced by: '<S47>/Constant'
                                        */
  uint8_T Constant2_Value_c;           /* Computed Parameter: Constant2_Value_c
                                        * Referenced by: '<S48>/Constant2'
                                        */
  uint8_T Constant3_Value_k;           /* Computed Parameter: Constant3_Value_k
                                        * Referenced by: '<S48>/Constant3'
                                        */
  uint8_T Constant4_Value_o;           /* Computed Parameter: Constant4_Value_o
                                        * Referenced by: '<S48>/Constant4'
                                        */
  uint8_T Constant_Value_ku;           /* Expression: 0xff
                                        * Referenced by: '<S48>/Constant'
                                        */
  uint8_T Constant2_Value_m;           /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S49>/Constant2'
                                        */
  uint8_T Constant3_Value_ca;          /* Computed Parameter: Constant3_Value_ca
                                        * Referenced by: '<S49>/Constant3'
                                        */
  uint8_T Constant4_Value_a;           /* Computed Parameter: Constant4_Value_a
                                        * Referenced by: '<S49>/Constant4'
                                        */
  uint8_T Constant_Value_j0;           /* Expression: 0xff
                                        * Referenced by: '<S49>/Constant'
                                        */
  uint8_T Constant2_Value_py;          /* Computed Parameter: Constant2_Value_py
                                        * Referenced by: '<S50>/Constant2'
                                        */
  uint8_T Constant3_Value_ax;          /* Computed Parameter: Constant3_Value_ax
                                        * Referenced by: '<S50>/Constant3'
                                        */
  uint8_T Constant4_Value_l;           /* Computed Parameter: Constant4_Value_l
                                        * Referenced by: '<S50>/Constant4'
                                        */
  uint8_T Constant_Value_p;            /* Expression: 0xff
                                        * Referenced by: '<S50>/Constant'
                                        */
  uint8_T Constant2_Value_kb;          /* Computed Parameter: Constant2_Value_kb
                                        * Referenced by: '<S51>/Constant2'
                                        */
  uint8_T Constant3_Value_aq;          /* Computed Parameter: Constant3_Value_aq
                                        * Referenced by: '<S51>/Constant3'
                                        */
  uint8_T Constant4_Value_nh;          /* Computed Parameter: Constant4_Value_nh
                                        * Referenced by: '<S51>/Constant4'
                                        */
  uint8_T Constant_Value_m;            /* Expression: 0xff
                                        * Referenced by: '<S51>/Constant'
                                        */
  uint8_T Constant2_Value_ct;          /* Computed Parameter: Constant2_Value_ct
                                        * Referenced by: '<S52>/Constant2'
                                        */
  uint8_T Constant3_Value_f2;          /* Computed Parameter: Constant3_Value_f2
                                        * Referenced by: '<S52>/Constant3'
                                        */
  uint8_T Constant4_Value_c;           /* Computed Parameter: Constant4_Value_c
                                        * Referenced by: '<S52>/Constant4'
                                        */
  uint8_T Constant_Value_op;           /* Expression: 0xff
                                        * Referenced by: '<S52>/Constant'
                                        */
  uint8_T Constant2_Value_d;           /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S53>/Constant2'
                                        */
  uint8_T Constant3_Value_b;           /* Computed Parameter: Constant3_Value_b
                                        * Referenced by: '<S53>/Constant3'
                                        */
  uint8_T Constant4_Value_ce;          /* Computed Parameter: Constant4_Value_ce
                                        * Referenced by: '<S53>/Constant4'
                                        */
  uint8_T Constant_Value_a;            /* Expression: 0xff
                                        * Referenced by: '<S53>/Constant'
                                        */
  uint8_T Constant2_Value_ke;          /* Computed Parameter: Constant2_Value_ke
                                        * Referenced by: '<S54>/Constant2'
                                        */
  uint8_T Constant3_Value_kf;          /* Computed Parameter: Constant3_Value_kf
                                        * Referenced by: '<S54>/Constant3'
                                        */
  uint8_T Constant4_Value_l4;          /* Computed Parameter: Constant4_Value_l4
                                        * Referenced by: '<S54>/Constant4'
                                        */
  uint8_T Constant_Value_g;            /* Expression: 0xff
                                        * Referenced by: '<S54>/Constant'
                                        */
  uint8_T Constant2_Value_a;           /* Computed Parameter: Constant2_Value_a
                                        * Referenced by: '<S55>/Constant2'
                                        */
  uint8_T Constant3_Value_e;           /* Computed Parameter: Constant3_Value_e
                                        * Referenced by: '<S55>/Constant3'
                                        */
  uint8_T Constant4_Value_mp;          /* Computed Parameter: Constant4_Value_mp
                                        * Referenced by: '<S55>/Constant4'
                                        */
  uint8_T Constant_Value_i;            /* Expression: 0xff
                                        * Referenced by: '<S55>/Constant'
                                        */
  uint8_T u_Value;                     /* Computed Parameter: u_Value
                                        * Referenced by: '<S2>/预分频值1'
                                        */
  uint8_T u_Value_i;                   /* Computed Parameter: u_Value_i
                                        * Referenced by: '<S2>/输出通道数1'
                                        */
  uint8_T u_Value_n;                   /* Computed Parameter: u_Value_n
                                        * Referenced by: '<S2>/预分频值2'
                                        */
  uint8_T u_Value_k;                   /* Computed Parameter: u_Value_k
                                        * Referenced by: '<S2>/输出通道数2'
                                        */
  uint8_T u_Value_a;                   /* Computed Parameter: u_Value_a
                                        * Referenced by: '<S2>/预分频值3'
                                        */
  uint8_T u_Value_p;                   /* Computed Parameter: u_Value_p
                                        * Referenced by: '<S2>/输出通道数3'
                                        */
  uint8_T u_Value_j;                   /* Computed Parameter: u_Value_j
                                        * Referenced by: '<S2>/预分频值4'
                                        */
  uint8_T u_Value_m;                   /* Computed Parameter: u_Value_m
                                        * Referenced by: '<S2>/输出通道数4'
                                        */
  uint8_T u_Value_l;                   /* Computed Parameter: u_Value_l
                                        * Referenced by: '<S2>/预分频值5'
                                        */
  uint8_T u_Value_o;                   /* Computed Parameter: u_Value_o
                                        * Referenced by: '<S2>/输出通道数5'
                                        */
  uint8_T u0_Value;                    /* Computed Parameter: u0_Value
                                        * Referenced by: '<S2>/预分频值10'
                                        */
  uint8_T u0_Value_a;                  /* Computed Parameter: u0_Value_a
                                        * Referenced by: '<S2>/输出通道数10'
                                        */
  uint8_T u1_Value;                    /* Computed Parameter: u1_Value
                                        * Referenced by: '<S2>/预分频值11'
                                        */
  uint8_T u1_Value_n;                  /* Computed Parameter: u1_Value_n
                                        * Referenced by: '<S2>/输出通道数11'
                                        */
  uint8_T u_Value_iv;                  /* Computed Parameter: u_Value_iv
                                        * Referenced by: '<S2>/预分频值6'
                                        */
  uint8_T u_Value_g;                   /* Computed Parameter: u_Value_g
                                        * Referenced by: '<S2>/输出通道数6'
                                        */
  uint8_T u_Value_gq;                  /* Computed Parameter: u_Value_gq
                                        * Referenced by: '<S2>/预分频值7'
                                        */
  uint8_T u_Value_lh;                  /* Computed Parameter: u_Value_lh
                                        * Referenced by: '<S2>/输出通道数7'
                                        */
  uint8_T u_Value_h;                   /* Computed Parameter: u_Value_h
                                        * Referenced by: '<S2>/预分频值8'
                                        */
  uint8_T u_Value_ku;                  /* Computed Parameter: u_Value_ku
                                        * Referenced by: '<S2>/输出通道数8'
                                        */
  uint8_T u_Value_al;                  /* Computed Parameter: u_Value_al
                                        * Referenced by: '<S2>/预分频值9'
                                        */
  uint8_T u_Value_k3;                  /* Computed Parameter: u_Value_k3
                                        * Referenced by: '<S2>/输出通道数9'
                                        */
  uint8_T Vref_Value;                  /* Computed Parameter: Vref_Value
                                        * Referenced by: '<S15>/Vref'
                                        */
  uint8_T Vref1_Value;                 /* Computed Parameter: Vref1_Value
                                        * Referenced by: '<S15>/Vref1'
                                        */
  uint8_T Constant12_Value;            /* Computed Parameter: Constant12_Value
                                        * Referenced by: '<S106>/Constant12'
                                        */
  uint8_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S106>/Constant'
                                        */
  uint8_T Constant1_Value_dz;          /* Computed Parameter: Constant1_Value_dz
                                        * Referenced by: '<S106>/Constant1'
                                        */
  uint8_T Constant2_Value_dx;          /* Computed Parameter: Constant2_Value_dx
                                        * Referenced by: '<S106>/Constant2'
                                        */
  uint8_T Constant3_Value_ct;          /* Computed Parameter: Constant3_Value_ct
                                        * Referenced by: '<S106>/Constant3'
                                        */
  uint8_T Constant11_Value_b;          /* Computed Parameter: Constant11_Value_b
                                        * Referenced by: '<S8>/Constant11'
                                        */
  uint8_T Constant12_Value_c;          /* Computed Parameter: Constant12_Value_c
                                        * Referenced by: '<S8>/Constant12'
                                        */
  uint8_T Constant13_Value;            /* Computed Parameter: Constant13_Value
                                        * Referenced by: '<S8>/Constant13'
                                        */
  uint8_T Constant14_Value;            /* Computed Parameter: Constant14_Value
                                        * Referenced by: '<S8>/Constant14'
                                        */
  uint8_T Constant15_Value;            /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S8>/Constant15'
                                        */
  uint8_T Constant3_Value_d;           /* Computed Parameter: Constant3_Value_d
                                        * Referenced by: '<S8>/Constant3'
                                        */
  uint8_T Constant4_Value_p;           /* Computed Parameter: Constant4_Value_p
                                        * Referenced by: '<S8>/Constant4'
                                        */
  uint8_T Constant5_Value_l;           /* Computed Parameter: Constant5_Value_l
                                        * Referenced by: '<S8>/Constant5'
                                        */
  uint8_T Constant6_Value_b;           /* Computed Parameter: Constant6_Value_b
                                        * Referenced by: '<S8>/Constant6'
                                        */
  uint8_T Constant7_Value_i;           /* Computed Parameter: Constant7_Value_i
                                        * Referenced by: '<S8>/Constant7'
                                        */
  uint8_T Constant8_Value_a;           /* Computed Parameter: Constant8_Value_a
                                        * Referenced by: '<S8>/Constant8'
                                        */
  uint8_T Constant9_Value_c;           /* Computed Parameter: Constant9_Value_c
                                        * Referenced by: '<S8>/Constant9'
                                        */
  uint8_T Constant2_Value_ds;          /* Computed Parameter: Constant2_Value_ds
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint8_T Constant4_Value_b;           /* Computed Parameter: Constant4_Value_b
                                        * Referenced by: '<Root>/Constant4'
                                        */
  uint8_T Constant6_Value_e;           /* Computed Parameter: Constant6_Value_e
                                        * Referenced by: '<Root>/Constant6'
                                        */
  uint8_T Constant13_Value_d;          /* Computed Parameter: Constant13_Value_d
                                        * Referenced by: '<Root>/Constant13'
                                        */
  uint8_T RGBLED0state_InitialValue[3];
                                /* Computed Parameter: RGBLED0state_InitialValue
                                 * Referenced by: '<Root>/RGBLED0state'
                                 */
  P_u0_RBCM_Model_T sf_9_a;            /* '<S2>/触发器9' */
  P_u0_RBCM_Model_T sf_8_j;            /* '<S2>/触发器8' */
  P_u0_RBCM_Model_T sf_7_p;            /* '<S2>/触发器7' */
  P_u0_RBCM_Model_T sf_6_o;            /* '<S2>/触发器6' */
  P_u_RBCM_Model_e_T sf_5_c;           /* '<S2>/触发器5' */
  P_u_RBCM_Model_e_T sf_4_a;           /* '<S2>/触发器4' */
  P_u_RBCM_Model_e_T sf_3_c;           /* '<S2>/触发器3' */
  P_u_RBCM_Model_e_T sf_2_l;           /* '<S2>/触发器2' */
  P_u0_RBCM_Model_T sf_11_a;           /* '<S2>/触发器11' */
  P_u0_RBCM_Model_T sf_10_a;           /* '<S2>/触发器10' */
  P_u_RBCM_Model_e_T sf_1_o;           /* '<S2>/触发器1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_RBCM_Model_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

extern CAN_DATATYPE CAN_DATATYPE_GROUND;

/* Block parameters (default storage) */
extern P_RBCM_Model_T RBCM_Model_P;

/* Block signals (default storage) */
extern B_RBCM_Model_T RBCM_Model_B;

/* Block states (default storage) */
extern DW_RBCM_Model_T RBCM_Model_DW;

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
 * Block '<S23>/Product2' : Unused code path elimination
 * Block '<S23>/Subtract' : Unused code path elimination
 * Block '<S23>/Vbat' : Unused code path elimination
 * Block '<S23>/compensate' : Unused code path elimination
 * Block '<S24>/Product2' : Unused code path elimination
 * Block '<S24>/Subtract' : Unused code path elimination
 * Block '<S24>/Vbat' : Unused code path elimination
 * Block '<S24>/compensate' : Unused code path elimination
 * Block '<S25>/Product2' : Unused code path elimination
 * Block '<S25>/Subtract' : Unused code path elimination
 * Block '<S25>/Vbat' : Unused code path elimination
 * Block '<S25>/compensate' : Unused code path elimination
 * Block '<S26>/Product2' : Unused code path elimination
 * Block '<S26>/Subtract' : Unused code path elimination
 * Block '<S26>/Vbat' : Unused code path elimination
 * Block '<S26>/compensate' : Unused code path elimination
 * Block '<S27>/Product2' : Unused code path elimination
 * Block '<S27>/Subtract' : Unused code path elimination
 * Block '<S27>/Vbat' : Unused code path elimination
 * Block '<S27>/compensate' : Unused code path elimination
 * Block '<S28>/Product2' : Unused code path elimination
 * Block '<S28>/Subtract' : Unused code path elimination
 * Block '<S28>/Vbat' : Unused code path elimination
 * Block '<S28>/compensate' : Unused code path elimination
 * Block '<S29>/Product2' : Unused code path elimination
 * Block '<S29>/Subtract' : Unused code path elimination
 * Block '<S29>/Vbat' : Unused code path elimination
 * Block '<S29>/compensate' : Unused code path elimination
 * Block '<S30>/Product2' : Unused code path elimination
 * Block '<S30>/Subtract' : Unused code path elimination
 * Block '<S30>/Vbat' : Unused code path elimination
 * Block '<S30>/compensate' : Unused code path elimination
 * Block '<S31>/Product2' : Unused code path elimination
 * Block '<S31>/Subtract' : Unused code path elimination
 * Block '<S31>/Vbat' : Unused code path elimination
 * Block '<S31>/compensate' : Unused code path elimination
 * Block '<S32>/Product2' : Unused code path elimination
 * Block '<S32>/Subtract' : Unused code path elimination
 * Block '<S32>/Vbat' : Unused code path elimination
 * Block '<S32>/compensate' : Unused code path elimination
 * Block '<S33>/Product2' : Unused code path elimination
 * Block '<S33>/Subtract' : Unused code path elimination
 * Block '<S33>/Vbat' : Unused code path elimination
 * Block '<S33>/compensate' : Unused code path elimination
 * Block '<S34>/Data Type Conversion4' : Unused code path elimination
 * Block '<S3>/Data Type Conversion19' : Unused code path elimination
 * Block '<S8>/Constant10' : Unused code path elimination
 * Block '<S15>/ADC resolution2' : Unused code path elimination
 * Block '<S15>/Data Type Conversion2' : Unused code path elimination
 * Block '<S15>/Magnification2' : Unused code path elimination
 * Block '<S15>/Product4' : Unused code path elimination
 * Block '<S15>/Product5' : Unused code path elimination
 * Block '<S15>/Vref2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S37>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S40>/Shift Arithmetic2' : Eliminated trivial shift
 * Block '<S41>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S41>/Shift Arithmetic2' : Eliminated trivial shift
 * Block '<S42>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S42>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S42>/Shift Arithmetic2' : Eliminated trivial shift
 * Block '<S43>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S43>/Shift Arithmetic2' : Eliminated trivial shift
 * Block '<S44>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S44>/Shift Arithmetic2' : Eliminated trivial shift
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion14' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion15' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion16' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion18' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion21' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion22' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion23' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion24' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion25' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion26' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion27' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion28' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion29' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion30' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion31' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'RBCM_Model/4G通信控制状态机1'
 * '<S2>'   : 'RBCM_Model/HSD诊断分析子系统'
 * '<S3>'   : 'RBCM_Model/HSD驱动子系统'
 * '<S4>'   : 'RBCM_Model/HsdDriveCommand Struct1'
 * '<S5>'   : 'RBCM_Model/Json编码器'
 * '<S6>'   : 'RBCM_Model/MATLAB Function'
 * '<S7>'   : 'RBCM_Model/MATLAB Function1'
 * '<S8>'   : 'RBCM_Model/Subsystem'
 * '<S9>'   : 'RBCM_Model/Subsystem1'
 * '<S10>'  : 'RBCM_Model/Subsystem10'
 * '<S11>'  : 'RBCM_Model/Subsystem11'
 * '<S12>'  : 'RBCM_Model/Subsystem12'
 * '<S13>'  : 'RBCM_Model/Subsystem13'
 * '<S14>'  : 'RBCM_Model/Subsystem2'
 * '<S15>'  : 'RBCM_Model/Subsystem6'
 * '<S16>'  : 'RBCM_Model/Subsystem7'
 * '<S17>'  : 'RBCM_Model/Subsystem8'
 * '<S18>'  : 'RBCM_Model/指令报文解码器'
 * '<S19>'  : 'RBCM_Model/无线调试模式管理子系统'
 * '<S20>'  : 'RBCM_Model/核心状态信息发送'
 * '<S21>'  : 'RBCM_Model/错误码数据发送(未)'
 * '<S22>'  : 'RBCM_Model/错误码数据发送(未)1'
 * '<S23>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元1'
 * '<S24>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元10'
 * '<S25>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元11'
 * '<S26>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元2'
 * '<S27>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元3'
 * '<S28>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元4'
 * '<S29>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元5'
 * '<S30>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元6'
 * '<S31>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元7'
 * '<S32>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元8'
 * '<S33>'  : 'RBCM_Model/HSD诊断分析子系统/ADC采集与处理单元9'
 * '<S34>'  : 'RBCM_Model/HSD诊断分析子系统/HSDh片选执行单元1'
 * '<S35>'  : 'RBCM_Model/HSD诊断分析子系统/HSDh片选执行单元11'
 * '<S36>'  : 'RBCM_Model/HSD诊断分析子系统/HSDh片选执行单元2'
 * '<S37>'  : 'RBCM_Model/HSD诊断分析子系统/HSDh片选执行单元3'
 * '<S38>'  : 'RBCM_Model/HSD诊断分析子系统/HSDh片选执行单元4'
 * '<S39>'  : 'RBCM_Model/HSD诊断分析子系统/HSDh片选执行单元5'
 * '<S40>'  : 'RBCM_Model/HSD诊断分析子系统/HSDl片选执行单元1'
 * '<S41>'  : 'RBCM_Model/HSD诊断分析子系统/HSDl片选执行单元2'
 * '<S42>'  : 'RBCM_Model/HSD诊断分析子系统/HSDl片选执行单元3'
 * '<S43>'  : 'RBCM_Model/HSD诊断分析子系统/HSDl片选执行单元4'
 * '<S44>'  : 'RBCM_Model/HSD诊断分析子系统/HSDl片选执行单元5'
 * '<S45>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem'
 * '<S46>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem1'
 * '<S47>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem10'
 * '<S48>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem2'
 * '<S49>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem3'
 * '<S50>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem4'
 * '<S51>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem5'
 * '<S52>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem6'
 * '<S53>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem7'
 * '<S54>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem8'
 * '<S55>'  : 'RBCM_Model/HSD诊断分析子系统/Subsystem9'
 * '<S56>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元1'
 * '<S57>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元10'
 * '<S58>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元11'
 * '<S59>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元12'
 * '<S60>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元2'
 * '<S61>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元3'
 * '<S62>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元4'
 * '<S63>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元5'
 * '<S64>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元6'
 * '<S65>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元7'
 * '<S66>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元8'
 * '<S67>'  : 'RBCM_Model/HSD诊断分析子系统/数据转存单元9'
 * '<S68>'  : 'RBCM_Model/HSD诊断分析子系统/触发器1'
 * '<S69>'  : 'RBCM_Model/HSD诊断分析子系统/触发器10'
 * '<S70>'  : 'RBCM_Model/HSD诊断分析子系统/触发器11'
 * '<S71>'  : 'RBCM_Model/HSD诊断分析子系统/触发器2'
 * '<S72>'  : 'RBCM_Model/HSD诊断分析子系统/触发器3'
 * '<S73>'  : 'RBCM_Model/HSD诊断分析子系统/触发器4'
 * '<S74>'  : 'RBCM_Model/HSD诊断分析子系统/触发器5'
 * '<S75>'  : 'RBCM_Model/HSD诊断分析子系统/触发器6'
 * '<S76>'  : 'RBCM_Model/HSD诊断分析子系统/触发器7'
 * '<S77>'  : 'RBCM_Model/HSD诊断分析子系统/触发器8'
 * '<S78>'  : 'RBCM_Model/HSD诊断分析子系统/触发器9'
 * '<S79>'  : 'RBCM_Model/HSD诊断分析子系统/诊断数据转存单元1'
 * '<S80>'  : 'RBCM_Model/HSD诊断分析子系统/诊断数据转存单元2'
 * '<S81>'  : 'RBCM_Model/HSD诊断分析子系统/诊断数据转存单元3'
 * '<S82>'  : 'RBCM_Model/HSD诊断分析子系统/诊断数据转存单元4'
 * '<S83>'  : 'RBCM_Model/HSD诊断分析子系统/诊断数据转存单元5'
 * '<S84>'  : 'RBCM_Model/HSD诊断分析子系统/错误码转存单元1'
 * '<S85>'  : 'RBCM_Model/HSD诊断分析子系统/错误码转存单元10'
 * '<S86>'  : 'RBCM_Model/HSD诊断分析子系统/错误码转存单元2'
 * '<S87>'  : 'RBCM_Model/HSD诊断分析子系统/错误码转存单元3'
 * '<S88>'  : 'RBCM_Model/HSD诊断分析子系统/错误码转存单元4'
 * '<S89>'  : 'RBCM_Model/HSD驱动子系统/HSDh输出控制单元1'
 * '<S90>'  : 'RBCM_Model/HSD驱动子系统/HSDh输出控制单元2'
 * '<S91>'  : 'RBCM_Model/HSD驱动子系统/HSDh输出控制单元3'
 * '<S92>'  : 'RBCM_Model/HSD驱动子系统/HSDh输出控制单元4'
 * '<S93>'  : 'RBCM_Model/HSD驱动子系统/HSDh输出控制单元5'
 * '<S94>'  : 'RBCM_Model/HSD驱动子系统/HSDh输出控制单元6'
 * '<S95>'  : 'RBCM_Model/HSD驱动子系统/HSDl输出控制单元1'
 * '<S96>'  : 'RBCM_Model/HSD驱动子系统/HSDl输出控制单元2'
 * '<S97>'  : 'RBCM_Model/HSD驱动子系统/HSDl输出控制单元3'
 * '<S98>'  : 'RBCM_Model/HSD驱动子系统/HSDl输出控制单元4'
 * '<S99>'  : 'RBCM_Model/HSD驱动子系统/HSDl输出控制单元5'
 * '<S100>' : 'RBCM_Model/Subsystem13/Subsystem'
 * '<S101>' : 'RBCM_Model/Subsystem13/Subsystem13'
 * '<S102>' : 'RBCM_Model/Subsystem13/Subsystem/HsdDriveCommand Struct1'
 * '<S103>' : 'RBCM_Model/Subsystem2/Add '\r\n'2'
 * '<S104>' : 'RBCM_Model/Subsystem7/Chart2'
 * '<S105>' : 'RBCM_Model/指令报文解码器/Chart1'
 * '<S106>' : 'RBCM_Model/指令报文解码器/Subsystem3'
 * '<S107>' : 'RBCM_Model/无线调试模式管理子系统/Subsystem'
 * '<S108>' : 'RBCM_Model/无线调试模式管理子系统/Subsystem1'
 * '<S109>' : 'RBCM_Model/核心状态信息发送/Chart1'
 */
#endif                                 /* RTW_HEADER_RBCM_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
