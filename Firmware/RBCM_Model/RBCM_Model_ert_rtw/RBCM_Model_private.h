/*
 * File: RBCM_Model_private.h
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

#ifndef RBCM_Model_private_h_
#define RBCM_Model_private_h_
#include "rtwtypes.h"
#include "RBCM_Model.h"
#include "RBCM_Model_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#include "Adc.h"

extern Adc_ValueGroupType* Adc0Group_1_ResultBufferPtr;
extern int Adc0Group_1_ResultBufferLength;

#include "Adc.h"

extern Adc_ValueGroupType* Adc1Group_1_ResultBufferPtr;
extern int Adc1Group_1_ResultBufferLength;

#include "Adc.h"

extern Adc_ValueGroupType* Adc2Group_1_ResultBufferPtr;
extern int Adc2Group_1_ResultBufferLength;
extern real_T rt_roundd_snf(real_T u);
extern void RBCM_Model_Chart2_Init(boolean_T *rty_A);
extern void RBCM_Model_Chart2_Reset(boolean_T *rty_A, DW_Chart2_RBCM_Model_T
  *localDW);
extern void RBCM_Model_Chart2(boolean_T *rty_A, DW_Chart2_RBCM_Model_T *localDW);
extern void RBCM_Model_u(uint8_T rtu_index, uint8_T rtu_u, uint8_T *rty_y1,
  uint8_T *rty_y2, DW_u_RBCM_Model_T *localDW);
extern void RBCM_Model_u1(uint8_T rtu_index, uint16_T rtu_u, uint16_T *rty_y1,
  uint16_T *rty_y2, DW_u1_RBCM_Model_T *localDW);
extern void RBCM_Model_u_a_Init(uint16_T *rty_1, P_u_RBCM_Model_e_T *localP);
extern void RBCM_Model_u_o(uint8_T rtu_counter, uint8_T rtu_u2, uint8_T *rty_y,
  uint16_T *rty_1, const uint16_T rtd_lHsd_Diagnose_AdcBuffer[5],
  DW_u_RBCM_Model_l_T *localDW, P_u_RBCM_Model_e_T *localP);
extern void RBCM_Model_u0_Init(uint16_T *rty_1, P_u0_RBCM_Model_T *localP);
extern void RBCM_Model_u0(uint8_T rtu_counter, uint8_T rtu_u2, uint8_T *rty_y,
  uint16_T *rty_1, const uint16_T rtd_hHsd_Diagnose_AdcBuffer[6],
  DW_u0_RBCM_Model_T *localDW, P_u0_RBCM_Model_T *localP);
extern void RBCM_Model_u_k(uint8_T rtu_index, uint16_T rtu_u, uint16_T *rty_y1,
  uint16_T *rty_y2, uint16_T *rty_y3, uint16_T *rty_y4, DW_u_RBCM_Model_b_T
  *localDW);
extern void RBCM_Model_u_g(uint8_T rtu_index, uint8_T rtu_u, uint8_T *rty_y1,
  uint8_T *rty_y2, uint8_T *rty_y3, uint8_T *rty_y4, DW_u_RBCM_Model_lj_T
  *localDW);
extern void RBCM_Model_Subsystem6_Init(void);
extern void RBCM_Model_Subsystem6(void);
extern void RBCM_Model_u_p_Init(void);
extern void RBCM_Model_u_o_Reset(void);
extern void RBCM_Model_u_k4(void);

#endif                                 /* RBCM_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
