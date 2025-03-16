/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/
/*==================================================================================================
*   @file    startup_cm7.s
*   @version 4.0.0
*
*   @brief   AUTOSAR Platform - Startup file for ARM.
*   @details Startup file for ARM.
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup BUILD_ENV
*   @{
*
==================================================================================================*/

#ifdef MULTIPLE_IMAGE
    #define RAM_DATA_INIT_ON_ALL_CORES
    /* If this is a secodary core, it shall wait for the MSCM clock to be initialized */
    #if defined(CORE1)||defined(CORE2)||defined(CORE3)
        #define NO_MSCM_CLOCK_INIT
    #endif
#endif

#define MAIN_CORE 0
#define CORE_M7_0 0
#define CORE_M7_1 1
#define CORE_M7_2 2
#define CORE_M7_3 3

#define MCME_CTL_KEY                0x402DC000
#define MCME_PRTN1_PUPD             0x402DC304
#define MCME_PRTN1_STAT             0x402DC308
#define MCME_PRTN1_COFB0_CLKEN      0x402DC330
#define MCME_PRTN1_COFB0_STAT       0x402DC310
#define MCRGM_DES                   0x4028C000

#define MCME_MSCM_REQ               (1 << 24)
#define MCRGM_DES_F_POR             (1)
#define MCME_KEY                    0x5AF0
#define MCME_INV_KEY                0xA50F

#define CM7_ITCMCR                  0xE000EF90
#define CM7_DTCMCR                  0xE000EF94

#define SBAF_BOOT_MARKER            (0x5AA55AA5)
#define CM7_0_ENABLE_SHIFT          (0)
#define CM7_1_ENABLE_SHIFT          (1)
#define CM7_2_ENABLE_SHIFT          (2)

#define CM7_0_ENABLE                (1)

#ifndef CM7_1_ENABLE
    #define CM7_1_ENABLE            (0)
#endif
#ifndef CM7_2_ENABLE
    #define CM7_2_ENABLE            (0)
#endif
#define CM7_0_VTOR_ADDR             (__CORE0_VTOR)
#define CM7_1_VTOR_ADDR             (__CORE1_VTOR)
#define CM7_2_VTOR_ADDR             (__CORE2_VTOR)
#define XRDC_CONFIG_ADDR            (0)
#define LF_CONFIG_ADDR              (0)

    .syntax unified
    .arch armv7-m
/* Table for copying and zeroing */
/* Copy table:
  - Table entries count
    - entry one ram start
    - entry one rom start
    - entry one rom end
    ...
    - entry n ram start
    - entry n rom start
    - entry n rom end
  Zero Table:
    - Table entries count
      - entry one ram start
      - entry one ram end
*/
.section ".init_table", "a"
  .long 6
  .long __RAM_CACHEABLE_START
  .long __ROM_CACHEABLE_START
  .long __ROM_CACHEABLE_END
  .long __RAM_NO_CACHEABLE_START
  .long __ROM_NO_CACHEABLE_START
  .long __ROM_NO_CACHEABLE_END
  .long __RAM_SHAREABLE_START
  .long __ROM_SHAREABLE_START
  .long __ROM_SHAREABLE_END
  .long __RAM_INTERRUPT_START
  .long __INIT_INTERRUPT_START
  .long __INIT_INTERRUPT_END
  .long __RAM_ITCM_START
  .long __ROM_ITCM_START
  .long __ROM_ITCM_END
  .long __RAM_DTCM_DATA_START
  .long __ROM_DTCM_DATA_START
  .long __ROM_DTCM_END
.section ".zero_table", "a"
  .long 3
  .long __BSS_SRAM_SH_START
  .long __BSS_SRAM_SH_END
  .long __BSS_SRAM_NC_START
  .long __BSS_SRAM_NC_END
  .long __BSS_SRAM_START
  .long __BSS_SRAM_END

.globl RESET_CATCH_CORE
.globl _core_loop
.section ".core_loop","ax"
.thumb

_core_loop:
    nop
    nop
    nop
    nop
    b _core_loop

.section ".boot_header","ax"
  .long SBAF_BOOT_MARKER /* IVT marker */
  .long (CM7_0_ENABLE << CM7_0_ENABLE_SHIFT) | (CM7_1_ENABLE << CM7_1_ENABLE_SHIFT) | (CM7_2_ENABLE << CM7_2_ENABLE_SHIFT) /* Boot configuration word */
  .long 0 /* Reserved */
  .long CM7_0_VTOR_ADDR /* CM7_0 Start address */
  .long 0 /* Reserved */
  .long CM7_1_VTOR_ADDR /* CM7_1 Start address */
  .long 0 /* Reserved */
  .long CM7_2_VTOR_ADDR /* CM7_2 Start address */
  .long 0 /* Reserved */
  .long XRDC_CONFIG_ADDR /* XRDC configuration pointer */
  .long LF_CONFIG_ADDR /* Lifecycle configuration pointer */
  .long 0 /* Reserved */

.globl VTABLE
.section ".startup","ax"
.thumb
/************************************************************************/
/* Autosar startup code (See MCU Specification):                        */
/*                                                                      */
/*   Before the MCU driver can be initialized, a basic initialization   */
/*   of the MCU has to be executed. This MCU specific initialization is */
/*   typically executed in a start-up code. The start-up code of the    */
/*   MCU shall be executed after power up and any kind of micro-        */
/*   controller reset. It shall perform very basic and microcontroller  */
/*   specific start-up initialization and shall be kept short, because  */
/*   the MCU clock and PLL is not yet initialized. The start-up code    */
/*   shall cover MCU specific initialization, which is not part of      */
/*   other MCU services or other MCAL drivers. The following steps      */
/*   summarizes basic functionality which shall be included in the      */
/*   start-up code. They are listed for guidance, because some          */
/*   functionality might not be supported. No code will be found in     */
/*   case.                                                              */
/************************************************************************/
.set VTOR_REG, 0xE000ED08
.thumb
.thumb_func
.globl Reset_Handler
.globl _start
_start:
Reset_Handler:
/*****************************************************/
/* Skip normal entry point as nothing is initialized */
/*****************************************************/
/* Disable System Interrupts */
 cpsid i
 /* Initialize GPRs */
 mov   r0, #0
 mov   r1, #0
 mov   r2, #0
 mov   r3, #0
 mov   r4, #0
 mov   r5, #0
 mov   r6, #0
 mov   r7, #0

/************************************************************************/
/* Delay trap for debugger attachs before touching any peripherals      */
/* This is workaround for debugger cannot handle halt process properly, */
/* User can safely disable this delay trap using -DDISABLE_DEBUGGER_TRAP*/
/************************************************************************/
#ifndef DISABLE_DEBUGGER_TRAP
    mov r0, #100
DELAY_LOOP:
    subs r0, #1
    cmp r0,#0
    bgt DELAY_LOOP
#endif

/******************************************************************************/
/*                      MSCM initialization process                           */
/* Only Master core can initialize clock for MSCM module in multicore testing */
/******************************************************************************/
#ifndef NO_MSCM_CLOCK_INIT
InitMSCMClock:
  /* If the MSCM clock is enabled, skip this sequence */
  ldr r0, =MCME_PRTN1_COFB0_STAT
  ldr r1, [r0]
  ldr r2, =MCME_MSCM_REQ
  and r1, r1, r2
  cmp r1, 0
  bne EndInitMSCMClock

  /* Step1: Enable clock in PRTN1 */
  ldr r0, =MCME_PRTN1_COFB0_CLKEN
  ldr r1, [r0]
  ldr r2, =MCME_MSCM_REQ
  orr r1, r2
  str r1, [r0]

  /* Step2: Set PUPD field */
  ldr r0, =MCME_PRTN1_PUPD
  ldr r1, [r0]
  ldr r2, =1
  orr r1, r2
  str r1, [r0]

  /* Step3: Trigger update by writing valid key */
  ldr r0, =MCME_CTL_KEY
  ldr r1, =MCME_KEY
  str r1, [r0]
  ldr r1, =MCME_INV_KEY
  str r1, [r0]

  /* Step4: Wait for process to complete */
  WaitForInitProcess:
  ldr r0, =MCME_PRTN1_PUPD
  ldr r1, [r0]
  ldr r2, =1
  and r1, r1, r2
  cmp r1, 1
  beq WaitForInitProcess
#endif

  /* Step5: Check if the MSCM clock is enabled */
#ifndef SIM_TYPE_VDK
WaitForClock:
  ldr r0, =MCME_PRTN1_COFB0_STAT
  ldr r1, [r0]
  ldr r2, =MCME_MSCM_REQ
  and r1, r1, r2
  cmp r1, 0
  beq WaitForClock
#endif
#ifndef NO_MSCM_CLOCK_INIT
EndInitMSCMClock:
#endif
/*******************************************************************/
/* NXP Guidance  - Init registers to avoid lock-step issues        */
/* N/A                                                             */
/*******************************************************************/

/*******************************************************************/
/* NXP Guidance  - MMU Initialization for CPU                      */
/*  TLB0 - PbridgeB                                                */
/*  TLB1 - Internal Flash                                          */
/*  TLB2 - External SRAM                                           */
/*  TLB3 - Internal SRAM                                           */
/*  TLB4 - PbridgeA                                                */
/*******************************************************************/
/******************************************************************/
/* Autosar Guidance   - The start-up code shall ensure that the   */
/* MCU internal watchdog shall not be serviced until the watchdog */
/* is initialized from the MCAL watchdog driver. This can be      */
/* done for example by increasing the watchdog service time.      */
/*                                                                */
/******************************************************************/

#ifdef MULTIPLE_CORE
/*GetCoreID*/
ldr  r0, =0x40260004
ldr  r1,[r0]

ldr  r0, =MAIN_CORE
cmp  r1,r0
bne  SetVTOR
#endif

/* Disable wdg0 */
ldr  r0, =0x40270010
ldr  r1, =0xC520
str  r1, [r0]
ldr  r1, =0xD928
str  r1, [r0]
ldr  r0, =0x40270000
ldr  r1, =0xFF000040
str  r1, [r0]

/******************************************************************/
/* Autosar Guidance - The start-up code shall initialize the      */
/* base addresses for interrupt and trap vector tables. These base*/
/* addresses are provided as configuration parameters or          */
/* linker/locator setting.                                        */
/******************************************************************/
SetVTOR:
/* Set VTOR to default vector table */
ldr  r0, =VTOR_REG
ldr  r1, =__INIT_INTERRUPT_START
str  r1,[r0]

/******************************************************************/
/* Autosar Guidance  - The start-up code shall initialize the     */
/* interrupt stack pointer, if an interrupt stack is              */
/* supported by the MCU. The interrupt stack pointer base address */
/* and the stack size are provided as configuration parameter or  */
/* linker/locator setting.                                        */
/*                                                                */
/******************************************************************/
/* Enable DTCM and Disable RETEN bit */
LDR r1, =CM7_DTCMCR
LDR r0, [r1]
bic r0, r0, #0x4
orr r0, r0, #0x1
str r0, [r1]
/* Enable ITCM and Disable RETEN bit */
LDR r1, =CM7_ITCMCR
LDR r0, [r1]
bic r0, r0, #0x4
orr r0, r0, #0x1
str r0, [r1]

#if defined(MULTIPLE_CORE) && !defined(MULTIPLE_IMAGE)
/*GetCoreID*/
ldr r0, =0x40260004
ldr r1,[r0]

ldr r0, =MAIN_CORE
cmp r1,r0
bne DTCM_Init
#endif

/******************************************************************/
/* Autosar Guidance   - If the MCU supports context save          */
/* operation, the start-up code shall initialize the memory which */
/* is used for context save operation. The maximum amount of      */
/* consecutive context save operations is provided as             */
/* configuration parameter or linker/locator setting.             */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance    - The start-up code shall initialize a     */
/* minimum amount of RAM in order to allow proper execution of    */
/* the MCU driver services and the caller of these services.      */
/******************************************************************/
RamInit:
    /* Initialize SRAM ECC */
    ldr  r0, =__RAM_INIT
    cmp  r0, 0
    /* Skip if __RAM_INIT is not set */
    beq SRAM_LOOP_END

    ldr r0, =MCRGM_DES
    ldr r1, [r0]
    ldr r2, =MCRGM_DES_F_POR
    and r1, r1, r2
    cmp r1, 0
    beq NO_INIT_STANDBY_REGION

    ldr r2, =__INT_SRAM_START
    ldr r3, =__INT_SRAM_END
    b   ZERO_64B_RAM

NO_INIT_STANDBY_REGION:
#ifdef EXTEND_LOWRAM_DERIVATIVES
    #if defined(S32K310)||defined(S32K311)||defined(S32M276)||defined(S32M274)
    ldr r2, =__BSS_SRAM_NC_START
    #else
    ldr r2, =__BSS_SRAM_START
    #endif
#else
    ldr r2, =__BSS_SRAM_START
#endif
    ldr r3, =__INT_SRAM_END

ZERO_64B_RAM:
    cmp r2, r3
    bge SRAM_LOOP_END

    movs    r0, 0
    movs    r1, 0
SRAM_LOOP:
    strd    r0, r1, [r2], #8
    cmp     r2, r3
    blt     SRAM_LOOP
SRAM_LOOP_END:

DTCM_Init:
    /* Initialize DTCM ECC */
    ldr  r0, =__DTCM_INIT
    cmp  r0, 0
    /* Skip if __DTCM_INIT is not set */
    beq DTCM_LOOP_END

    ldr r2, =__INT_DTCM_START
    ldr r3, =__INT_DTCM_END

    cmp r2, r3
    bge DTCM_LOOP_END

    movs    r0, 0
    movs    r1, 0
DTCM_LOOP:
    strd    r0, r1, [r2], #8
    cmp     r2, r3
    blt     DTCM_LOOP
DTCM_LOOP_END:

ITCM_Init:
    /* Initialize ITCM ECC */
    ldr  r0, =__ITCM_INIT
    cmp  r0, 0
    /* Skip if __TCM_INIT is not set */
    beq ITCM_LOOP_END

    ldr r2, =__INT_ITCM_START
    ldr r3, =__INT_ITCM_END

    cmp r2, r3
    bge ITCM_LOOP_END

    movs    r0, 0
    movs    r1, 0
ITCM_LOOP:
    strd    r0, r1, [r2], #8
    cmp     r2, r3
    blt     ITCM_LOOP
ITCM_LOOP_END:

DebuggerHeldCoreLoop:
    ldr  r0, =RESET_CATCH_CORE
    ldr  r0, [r0]
    ldr  r1, =0x5A5A5A5A
    cmp  r0, r1
    beq  DebuggerHeldCoreLoop

/******************************************************************/
/* Autosar Guidance   - The start-up code shall initialize the    */
/* user stack pointer. The user stack pointer base address and    */
/* the stack size are provided as configuration parameter or      */
/* linker/locator setting.                                        */
/******************************************************************/
/* set up stack; r13 SP*/
    ldr  r0, =__Stack_dtcm_start
    msr MSP, r0

#if defined(MULTIPLE_CORE) && !defined(MULTIPLE_IMAGE)
    ldr  r0, =0x40260004
    ldr  r1,[r0]
    ldr  r0, =MAIN_CORE
    cmp  r1,r0
    bne  _DATA_INIT

#if (CM7_1_ENABLE == 0)
EnableCore1:
    ldr  r0, =0x402DC168
    ldr  r1, [r0]
    ldr  r2, =1
    and  r1, r1, r2
    cmp  r1, 0
    bne  EndEnableCore1

    ldr  r0, =0x402DC16C     /* MC_ME.PRTN0_CORE1_ADDR */
    ldr  r1, =__INIT_INTERRUPT_START
    str  r1, [r0]

    ldr  r0, =0x402DC160     /* MC_ME.PRTN0_CORE1_PCONF */
    ldr  r1, =1
    str  r1, [r0]

    ldr  r0, =0x402DC164     /* MC_ME.PRTN0_CORE1_PUPD */
    str  r1, [r0]

    ldr  r0, =0x402DC000     /* MC_ME.MC_ME_CTL_KEY */
    ldr  r1, =MCME_KEY
    str  r1, [r0]

    ldr  r1, =MCME_INV_KEY
    str  r1, [r0]

WaitForCore1Clock:
    ldr  r0, =0x402DC168
    ldr  r1, [r0]
    ldr  r2, =1
    and  r1, r1, r2
    cmp  r1, 0
    beq  WaitForCore1Clock
EndEnableCore1:
#endif

#if (CM7_2_ENABLE == 0)
EnableCore2:
    ldr  r0, =0x402DC1C8
    ldr  r1, [r0]
    ldr  r2, =1
    and  r1, r1, r2
    cmp  r1, 0
    bne  EndEnableCore2

    ldr  r0, =0x402DC1CC     /* MC_ME.PRTN0_CORE2_ADDR */
    ldr  r1, =__INIT_INTERRUPT_START
    str  r1, [r0]

    ldr  r0, =0x402DC1C0     /* MC_ME.PRTN0_CORE2_PCONF */
    ldr  r1, =1
    str  r1, [r0]

    ldr  r0, =0x402DC1C4     /* MC_ME.PRTN0_CORE2_PUPD */
    str  r1, [r0]

    ldr  r0, =0x402DC000     /* MC_ME.MC_ME_CTL_KEY */
    ldr  r1, =MCME_KEY
    str  r1, [r0]

    ldr  r1, =MCME_INV_KEY
    str  r1, [r0]

WaitForCore2Clock:
    ldr  r0, =0x402DC188
    ldr  r1, [r0]
    ldr  r2, =1
    and  r1, r1, r2
    cmp  r1, 0
    beq  WaitForCore2Clock
EndEnableCore2:
#endif
#endif
/************************/
/* Erase ".bss Section" */
/************************/
_DATA_INIT:
#ifndef RAM_DATA_INIT_ON_ALL_CORES
    /* If this is the primary core, initialize data and bss */
    ldr  r0, =0x40260004
    ldr  r1,[r0]

    ldr  r0, =MAIN_CORE
    cmp  r1,r0
    beq  _INIT_DATA_BSS
    bl   init_data_bss_core2
    b    SET_VTOR_TCM
#endif

_INIT_DATA_BSS:
  bl init_data_bss

SET_VTOR_TCM:
/* Set VTOR to default vector table */
ldr  r0, =VTOR_REG
ldr  r1, =__RAM_INTERRUPT_START
str  r1,[r0]

/***************************************************************/
/* FPU need to enable prior to data-initialization process,in  */
/* case optimization level set to O3 compiler can utilize SIMD */
/* instruction which required involvement of FPU co-processor  */
/***************************************************************/
  bl   Enable_FPU

/******************************************************************/
/* Autosar Guidance   - If the MCU supports cache memory for data */
/* and/or code, it shall be initialized and enabled in the        */
/* start-up code.                                                 */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance   - The start-up code shall initialize MCU    */
/* specific features of internal memory like memory protection.   */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance   - If external memory is used, the memory    */
/* shall be initialized in the start-up code. The start-up code   */
/* shall be prepared to support different memory configurations   */
/* depending on code location. Different configuration options    */
/* shall be taken into account for code execution from            */
/* external/internal memory.                                      */
/* N/A - external memory is not used                              */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance   - The settings of the different memories    */
/* shall be provided to the start-up code as configuration        */
/* parameters.                                                    */
/* N/A - all memories are already configured                      */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance    - In the start-up code a default           */
/* initialization of the MCU clock system shall be performed      */
/* including global clock prescalers.                             */
/******************************************************************/
__SYSTEM_INIT:
  bl SystemInit

/******************************************************************/
/* Autosar Guidance   - The start-up code shall ensure that the   */
/* MCU internal watchdog shall not be serviced until the watchdog */
/* is initialized from the MCAL watchdog driver. This can be      */
/* done for example by increasing the watchdog service time.      */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance    - The start-up code shall enable           */
/* protection mechanisms for special function registers(SFRs),    */
/* if supported by the MCU.                                       */
/* N/A - will be handled by Autosar OS                            */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance    - The start-up code shall initialize all   */
/* necessary write once registers or registers common to several  */
/* drivers where one write, rather than repeated writes, to the   */
/* register is required or highly desirable.                      */
/******************************************************************/

/*********************************/
/* Set the small ro data pointer */
/*********************************/


/*********************************/
/* Set the small rw data pointer */
/*********************************/

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
_MAIN:
  cpsie i
  bl startup_go_to_user_mode
  bl main

/******************************************************************/
/* Init runtime check data space                                  */
/******************************************************************/
.globl MCAL_LTB_TRACE_OFF
 MCAL_LTB_TRACE_OFF:
    nop

#ifdef CCOV_ENABLE
    /* code coverage is requested */
    bl ccov_main
#endif

    /*BKPT #1 - removed to avoid debug fault being escalated to hardfault when debugger is not attached or on VDK*/ /* last instruction for the debugger to dump results data */
.globl _end_of_eunit_test
_end_of_eunit_test:
    b .

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
.globl startup_getControlRegisterValue
startup_getControlRegisterValue:
mrs r0, CONTROL
bx r14

.globl startup_getAipsRegisterValue
startup_getAipsRegisterValue:
mrs r0, IPSR
bx r14
#endif

.align 4
.ltorg
