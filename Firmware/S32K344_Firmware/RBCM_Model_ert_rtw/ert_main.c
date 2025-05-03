/* 
 * File: ert_main.c 
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
 #include "MW_target_hardware_resources.h" 
  
 volatile int IsrOverrun = 0; 
 static boolean_T OverrunFlag = 0; 
 void rt_OneStep(void) 
 { 
 /* Check for overrun. Protect OverrunFlag against preemption */ 
 if (OverrunFlag++) { 
 IsrOverrun = 1; 
 OverrunFlag--; 
 return; 
 } 
  
 RBCM_Model_step(); 
  
 /* Get model outputs here */ 
 OverrunFlag--; 
 } 
  
 volatile boolean_T stopRequested; 
 volatile boolean_T runModel; 
 int main(int argc, char **argv) 
 { 
 float modelBaseRate = 0.01; 
 float systemClock = 160; 
  
 /* Initialize variables */ 
 stopRequested = false; 
 runModel = false; 
 (void)argc; 
 (void)argv; 
 (void)systemClock; 
  
 /* Board init */ 
 board_init(); 
 ; 
 rtmSetErrorStatus(RBCM_Model_M, 0); 
 RBCM_Model_initialize(); 
 s32k3_trigger_config(modelBaseRate); 
 runModel = rtmGetErrorStatus(RBCM_Model_M) == (NULL); 
 while (runModel) { 
 FMSTR_Poll(); 
 stopRequested = !(rtmGetErrorStatus(RBCM_Model_M) == (NULL)); 
 runModel = !(stopRequested); 
 } 
  
 /* Terminate model */ 
 RBCM_Model_terminate(); 
 return 0; 
 } 
  
 /* 
 * File trailer for generated code. 
 * 
 * [EOF] 
 */ 
