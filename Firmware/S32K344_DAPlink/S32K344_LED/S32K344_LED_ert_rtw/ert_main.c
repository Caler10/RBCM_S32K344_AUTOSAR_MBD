/* 
 * File: ert_main.c 
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
  
 S32K344_LED_step(); 
  
 /* Get model outputs here */ 
 OverrunFlag--; 
 } 
  
 volatile boolean_T stopRequested; 
 volatile boolean_T runModel; 
 int main(int argc, char **argv) 
 { 
 float modelBaseRate = 1.0; 
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
 rtmSetErrorStatus(S32K344_LED_M, 0); 
 S32K344_LED_initialize(); 
 s32k3_trigger_config(modelBaseRate); 
 runModel = rtmGetErrorStatus(S32K344_LED_M) == (NULL); 
 while (runModel) { 
 FMSTR_Poll(); 
 stopRequested = !(rtmGetErrorStatus(S32K344_LED_M) == (NULL)); 
 runModel = !(stopRequested); 
 } 
  
 /* Terminate model */ 
 S32K344_LED_terminate(); 
 return 0; 
 } 
  
 /* 
 * File trailer for generated code. 
 * 
 * [EOF] 
 */ 
