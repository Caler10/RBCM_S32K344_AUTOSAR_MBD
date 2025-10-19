/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   Copyright 2020 - 2024 NXP
*   
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_IP_HW_ACCESS_H
#define FLEXIO_IP_HW_ACCESS_H

/**
*   @file    Flexio_Ip_hw_access.h
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Low level header of Mcl driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup FLEXIO_IP_DRIVER FLEXIO IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Mcl_Ip_Cfg_DeviceRegisters.h"
#include "Flexio_Mcl_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_IP_HW_ACCESS_VENDOR_ID                      43
#define FLEXIO_IP_HW_ACCESS_MODULE_ID                      255
#define FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_IP_HW_ACCESS_SW_MAJOR_VERSION               5
#define FLEXIO_IP_HW_ACCESS_SW_MINOR_VERSION               0
#define FLEXIO_IP_HW_ACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Flexio_Mcl_Ip_HwAccess.h file and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same vendor */
#if (FLEXIO_IP_HW_ACCESS_VENDOR_ID != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Flexio_Mcl_Ip_HwAccess.h and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.h file and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Autosar version */
#if ((FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_HwAccess.h and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.h file and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Software version */
#if ((FLEXIO_IP_HW_ACCESS_SW_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_SW_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_SW_PATCH_VERSION != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_HwAccess.h and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.h file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same vendor */
#if (FLEXIO_IP_HW_ACCESS_VENDOR_ID != FLEXIO_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "Flexio_Mcl_Ip_HwAccess.h and Flexio_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.h file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_HwAccess.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.h file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((FLEXIO_IP_HW_ACCESS_SW_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_SW_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (FLEXIO_IP_HW_ACCESS_SW_PATCH_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_HwAccess.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/* Shift clock polarity options   */
typedef enum
{
    FLEXIO_TIMER_POLARITY_POSEDGE = 0x00U,     /*!< Shift on positive edge of Shift clock */
    FLEXIO_TIMER_POLARITY_NEGEDGE = 0x01U,     /*!< Shift on negative edge of Shift clock */
} Flexio_Mcl_Ip_TimerPolarityType;


/* Pin polarity options   */
typedef enum
{
    FLEXIO_PIN_POLARITY_HIGH = 0x00U,          /*!< Pin is active high */
    FLEXIO_PIN_POLARITY_LOW  = 0x01U,          /*!< Pin is active low  */
} Flexio_Mcl_Ip_PinPolarityType;

/* Pin configuration options   */
typedef enum
{
    FLEXIO_PIN_CONFIG_DISABLED     = 0x00U,    /*!< Shifter pin output disabled */
    FLEXIO_PIN_CONFIG_OPEN_DRAIN   = 0x01U,    /*!< Shifter pin open drain or bidirectional output enable */
    FLEXIO_PIN_CONFIG_BIDIR_OUTPUT = 0x02U,    /*!< Shifter pin bidirectional output data */
    FLEXIO_PIN_CONFIG_OUTPUT       = 0x03U,    /*!< Shifter pin output */
} Flexio_Mcl_Ip_PinConfigType;

/* Shifter mode options   */
typedef enum
{
    FLEXIO_SHIFTER_MODE_DISABLED          = 0x00U,
    FLEXIO_SHIFTER_MODE_RECEIVE           = 0x01U,
    FLEXIO_SHIFTER_MODE_TRANSMIT          = 0x02U,
    FLEXIO_SHIFTER_MODE_MATCH_STORE       = 0x04U,
    FLEXIO_SHIFTER_MODE_MATCH_CONTINUOUS  = 0x05U,
} Flexio_Mcl_Ip_ShifterModeType;

/* Shifter input source options   */
typedef enum
{
    FLEXIO_SHIFTER_SOURCE_PIN        = 0x00U,
    FLEXIO_SHIFTER_SOURCE_SHIFTER    = 0x01U,
} Flexio_Mcl_Ip_ShifterSourceType;

/* Read/Write mode for shifter buffer   */
typedef enum
{
    FLEXIO_SHIFTER_RW_MODE_NORMAL    = 0x00U,
    FLEXIO_SHIFTER_RW_MODE_BIT_SWAP  = 0x01U,
} Flexio_Mcl_Ip_ShifterBufferModeType;

/* Trigger polarity   */
typedef enum
{
    FLEXIO_TRIGGER_POLARITY_HIGH = 0x00U,          /*!< Trigger is active high */
    FLEXIO_TRIGGER_POLARITY_LOW  = 0x01U,          /*!< Trigger is active low  */
} Flexio_Mcl_Ip_TriggerPolarityType;

/* Trigger sources   */
typedef enum
{
    FLEXIO_TRIGGER_SOURCE_EXTERNAL  = 0x00U,  /*!< External trigger selected */
    FLEXIO_TRIGGER_SOURCE_INTERNAL  = 0x01U,  /*!< Internal trigger selected */
} Flexio_Mcl_Ip_TriggerSourceType;

/* Timer mode options   */
typedef enum
{
    FLEXIO_TIMER_MODE_DISABLED                  = 0x00U,  /*!< Timer Disabled. */
    FLEXIO_TIMER_MODE_8BIT_BAUD                 = 0x01U,  /*!< Dual 8-bit counters baud/bit mode. */
    FLEXIO_TIMER_MODE_8BIT_PWM                  = 0x02U,  /*!< Dual 8-bit counters PWM mode. */
    FLEXIO_TIMER_MODE_16BIT                     = 0x03U,  /*!< Single 16-bit counter mode. */
    FLEXIO_TIMER_MODE_16BIT_DIS                 = 0x04U,  /*!< Single 16-bit counter disable mode. */
    FLEXIO_TIMER_MODE_8BIT_DUAL                 = 0x05U,  /*!< Dual 8-bit counters word mode. */
    FLEXIO_TIMER_MODE_8BIT_DUAL_PWM             = 0x06U,  /*!< Dual 8-bit counters PWM low mode. */
    FLEXIO_TIMER_16BIT_INPUT_CAPTURE_MODE       = 0x07U,  /*!< Single 16-bit input capture mode. */
} Flexio_Mcl_Ip_TimerModeType;

/* Timer initial output options   */
typedef enum
{
    FLEXIO_TIMER_INITOUT_ONE          = 0x00U,  /*!< Timer output is logic one when enabled, unaffected by timer reset. */
    FLEXIO_TIMER_INITOUT_ZERO         = 0x01U,  /*!< Timer output is logic zero when enabled, unaffected by timer reset. */
    FLEXIO_TIMER_INITOUT_ONE_RESET    = 0x02U,  /*!< Timer output is logic one when enabled and on timer reset. */
    FLEXIO_TIMER_INITOUT_ZERO_RESET   = 0x03U,  /*!< Timer output is logic zero when enabled and on timer reset. */
} Flexio_Mcl_Ip_TimerOutputType;

/* Timer decrement options   */
typedef enum
{
    FLEXIO_TIMER_DECREMENT_CLK_SHIFT_TMR      = 0x00U,  /*!< Decrement counter on FlexIO clock, Shift clock equals Timer output. */
    FLEXIO_TIMER_DECREMENT_TRG_SHIFT_TMR      = 0x01U,  /*!< Decrement counter on Trigger input (both edges), Shift clock equals Timer output. */
    FLEXIO_TIMER_DECREMENT_PIN_SHIFT_PIN      = 0x02U,  /*!< Decrement counter on Pin input (both edges), Shift clock equals Pin input. */
    FLEXIO_TIMER_DECREMENT_TRG_SHIFT_TRG      = 0x03U,  /*!< Decrement counter on Trigger input (both edges), Shift clock equals Trigger input. */
} Flexio_Mcl_Ip_TimerDecrementType;

/* Timer reset options   */
typedef enum
{
    FLEXIO_TIMER_RESET_NEVER                  = 0x00U,  /*!< Timer never reset. */
    FLEXIO_TIMER_RESET_PIN_OUT                = 0x02U,  /*!< Timer reset on Timer Pin equal to Timer Output. */
    FLEXIO_TIMER_RESET_TRG_OUT                = 0x03U,  /*!< Timer reset on Timer Trigger equal to Timer Output. */
    FLEXIO_TIMER_RESET_PIN_RISING             = 0x04U,  /*!< Timer reset on Timer Pin rising edge. */
    FLEXIO_TIMER_RESET_TRG_RISING             = 0x06U,  /*!< Timer reset on Trigger rising edge. */
    FLEXIO_TIMER_RESET_TRG_BOTH               = 0x07U,  /*!< Timer reset on Trigger rising or falling edge. */
} Flexio_Mcl_Ip_TimerResetType;

/* Timer disable options   */
typedef enum
{
    FLEXIO_TIMER_DISABLE_NEVER                = 0x00U,  /*!< Timer never disabled. */
    FLEXIO_TIMER_DISABLE_TIM_DISABLE          = 0x01U,  /*!< Timer disabled on Timer N-1 disable. */
    FLEXIO_TIMER_DISABLE_TIM_CMP              = 0x02U,  /*!< Timer disabled on Timer compare. */
    FLEXIO_TIMER_DISABLE_TIM_CMP_TRG_LOW      = 0x03U,  /*!< Timer disabled on Timer compare and Trigger Low. */
    FLEXIO_TIMER_DISABLE_PIN                  = 0x04U,  /*!< Timer disabled on Pin rising or falling edge. */
    FLEXIO_TIMER_DISABLE_PIN_TRG_HIGH         = 0x05U,  /*!< Timer disabled on Pin rising or falling edge provided Trigger is high. */
    FLEXIO_TIMER_DISABLE_TRG                  = 0x06U,  /*!< Timer disabled on Trigger falling edge. */
} Flexio_Mcl_Ip_TimerDisableType;

/* Timer disable options   */
typedef enum
{
    FLEXIO_TIMER_ENABLE_ALWAYS                  = 0x00U,  /*!< Timer always enabled. */
    FLEXIO_TIMER_ENABLE_TIM_ENABLE              = 0x01U,  /*!< Timer enabled on Timer N-1 enable. */
    FLEXIO_TIMER_ENABLE_TRG_HIGH                = 0x02U,  /*!< Timer enabled on Trigger high. */
    FLEXIO_TIMER_ENABLE_TRG_PIN_HIGH            = 0x03U,  /*!< Timer enabled on Trigger high and Pin high. */
    FLEXIO_TIMER_ENABLE_PIN_POSEDGE             = 0x04U,  /*!< Timer enabled on Pin rising edge. */
    FLEXIO_TIMER_ENABLE_PIN_POSEDGE_TRG_HIGH    = 0x05U,  /*!< Timer enabled on Pin rising edge and Trigger high. */
    FLEXIO_TIMER_ENABLE_TRG_POSEDGE             = 0x06U,  /*!< Timer enabled on Trigger rising edge. */
    FLEXIO_TIMER_ENABLE_TRG_EDGE                = 0x07U,  /*!< Timer enabled on Trigger rising or falling edge. */
} Flexio_Mcl_Ip_TimerEnableType;

/* Timer stop bit options   */
typedef enum
{
    FLEXIO_TIMER_STOP_BIT_DISABLED              = 0x00U,  /*!< Stop bit disabled. */
    FLEXIO_TIMER_STOP_BIT_TIM_CMP               = 0x01U,  /*!< Stop bit is enabled on timer compare. */
    FLEXIO_TIMER_STOP_BIT_TIM_DIS               = 0x02U,  /*!< Stop bit is enabled on timer disable. */
    FLEXIO_TIMER_STOP_BIT_TIM_CMP_DIS           = 0x03U,  /*!< Stop bit is enabled on timer compare and disable. */
} Flexio_Mcl_Ip_TimerStopType;

/* Timer stop bit options - for Transmit, Receive or Match Store modes only   */
typedef enum
{
    FLEXIO_SHIFTER_STOP_BIT_DISABLED            = 0x00U,
    FLEXIO_SHIFTER_STOP_BIT_0                   = 0x02U,
    FLEXIO_SHIFTER_STOP_BIT_1                   = 0x03U,
} Flexio_Mcl_Ip_ShifterStopType;

/* Timer start bit options - for Transmit, Receive or Match Store modes only   */
typedef enum
{
    FLEXIO_SHIFTER_START_BIT_DISABLED       = 0x00U,
    FLEXIO_SHIFTER_START_BIT_DISABLED_SH    = 0x01U,
    FLEXIO_SHIFTER_START_BIT_0              = 0x02U,
    FLEXIO_SHIFTER_START_BIT_1              = 0x03U,
} Flexio_Mcl_Ip_ShifterStartType;

/* Timer start bit options   */
typedef enum
{
    FLEXIO_TIMER_START_BIT_DISABLED              = 0x00U,  /*!< Start bit disabled. */
    FLEXIO_TIMER_START_BIT_ENABLED               = 0x01U,  /*!< Start bit enabled. */
} Flexio_Mcl_Ip_TimerStartType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

void Flexio_Mcl_Ip_SetSoftwareReset(FLEXIO_Type *baseAddr, boolean enable);

void Flexio_Mcl_Ip_SetDebugEnable(FLEXIO_Type *baseAddr, boolean enable);

void Flexio_Mcl_Ip_SetEnable(FLEXIO_Type *baseAddr, boolean enable);

boolean Flexio_Mcl_Ip_GetShifterStatus(const FLEXIO_Type *baseAddr, uint8 shifter);

uint32 Flexio_Mcl_Ip_GetAllShifterStatus(const FLEXIO_Type *baseAddr);

void Flexio_Mcl_Ip_ClearShifterStatus(FLEXIO_Type *baseAddr, uint8 shifter);

#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
uint32 Flexio_Mcl_Ip_GetAllPinsStatus(const FLEXIO_Type *baseAddr);
#endif

boolean Flexio_Mcl_Ip_GetShifterErrorStatus(const FLEXIO_Type *baseAddr, uint8 shifter);

uint32 Flexio_Mcl_Ip_GetAllShifterErrorStatus(const FLEXIO_Type *baseAddr);

void Flexio_Mcl_Ip_ClearShifterErrorStatus(FLEXIO_Type *baseAddr, uint8 shifter);

boolean Flexio_Mcl_Ip_GetTimerStatus(const FLEXIO_Type *baseAddr, uint8 timer);

boolean Flexio_Mcl_Ip_GetTimerInterruptEnable(const FLEXIO_Type *baseAddr, uint8 timer);

uint32 Flexio_Mcl_Ip_GetAllTimerStatus(const FLEXIO_Type *baseAddr);

void Flexio_Mcl_Ip_ClearTimerStatus(FLEXIO_Type *baseAddr, uint8 timer);

uint32 Flexio_Mcl_Ip_GetAllShifterInterrupt(const FLEXIO_Type *baseAddr);

uint32 Flexio_Mcl_Ip_GetAllShifterErrorInterrupt(const FLEXIO_Type *baseAddr);

void Flexio_Mcl_Ip_SetShifterErrorInterrupt(FLEXIO_Type *baseAddr, uint8 interruptMask, boolean enable);

void Flexio_Mcl_Ip_SetShifterInterrupt(FLEXIO_Type *baseAddr, uint8 interruptMask, boolean enable);

void Flexio_Mcl_Ip_SetShifterDMARequest(FLEXIO_Type *baseAddr, uint8 requestMask, boolean enable);

uint32 Flexio_Mcl_Ip_GetAllTimerInterrupt(const FLEXIO_Type *baseAddr);

void Flexio_Mcl_Ip_SetTimerInterrupt(FLEXIO_Type *baseAddr, uint8 interruptMask, boolean enable);

#if (STD_ON == FLEXIO_MCL_IP_TIMERSDEN_IS_AVAILABLE)
void Flexio_Mcl_Ip_SetTimerDMARequest(FLEXIO_Type *baseAddr, uint8 requestMask, boolean enable);
#endif

void Flexio_Mcl_Ip_Init(FLEXIO_Type *baseAddr);

#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
void Flexio_Mcl_Ip_ClearPinStatus(FLEXIO_Type *baseAddr, uint8 pin);

uint32 Flexio_Mcl_Ip_GetAllPinsInterrupt(const FLEXIO_Type *baseAddr);
#endif

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_IP_HW_ACCESS_H */
