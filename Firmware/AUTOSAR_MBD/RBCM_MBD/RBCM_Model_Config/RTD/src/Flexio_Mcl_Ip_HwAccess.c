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

/**
*   @file    Flexio_Mcl_Ip_HwAccess.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Flexio Common driver source file.
*   @details
*
*   @addtogroup FLEXIO_IP_DRIVER FLEXIO IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Mcl_Ip_HwAccess.h"
#include "SchM_Mcl.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_HWACCESS_VENDOR_ID_C                      43
#define FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_MCL_IP_HWACCESS_SW_MAJOR_VERSION_C               5
#define FLEXIO_MCL_IP_HWACCESS_SW_MINOR_VERSION_C               0
#define FLEXIO_MCL_IP_HWACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Flexio_Mcl_Ip_HwAccess.c file and Flexio_Mcl_Ip_HwAccess.h file are of the same vendor */
#if (FLEXIO_MCL_IP_HWACCESS_VENDOR_ID_C != FLEXIO_IP_HW_ACCESS_VENDOR_ID)
    #error "Flexio_Mcl_Ip_HwAccess.c and Flexio_Mcl_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.c file and Flexio_Mcl_Ip_HwAccess.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_HwAccess.c and Flexio_Mcl_Ip_HwAccess.h are different"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.c file and Flexio_Mcl_Ip_HwAccess.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_HWACCESS_SW_MAJOR_VERSION_C != FLEXIO_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_SW_MINOR_VERSION_C != FLEXIO_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_SW_PATCH_VERSION_C != FLEXIO_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_HwAccess.c and Flexio_Mcl_Ip_HwAccess.h are different"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.c file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same vendor */
#if (FLEXIO_MCL_IP_HWACCESS_VENDOR_ID_C != FLEXIO_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "Flexio_Mcl_Ip_HwAccess.c and Flexio_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.c file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_HwAccess.c and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if Flexio_Mcl_Ip_HwAccess.c file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_HWACCESS_SW_MAJOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_SW_MINOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_SW_PATCH_VERSION_C != FLEXIO_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_HwAccess.c and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Flexio_Mcl_Ip_HwAccess.c file and SchM_Mcl header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C != SCHM_MCL_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C != SCHM_MCL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_HwAccess.c and SchM_Mcl.h are different"
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/*
 * Calling this function with enable parameter set to TRUE resets all internal
 * master logic and registers, except the FlexIO Control Register. The reset state
 * persists until this function is called with enable parameter set to false.
 */
 void Flexio_Mcl_Ip_SetSoftwareReset(FLEXIO_Type *baseAddr, boolean enable)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_39();
    uint32 RegValue = (uint32)baseAddr->CTRL;

    RegValue &= (~((uint32)FLEXIO_CTRL_SWRST_MASK));
    RegValue |= FLEXIO_CTRL_SWRST((enable ? 1U : 0U));
    baseAddr->CTRL = (uint32)RegValue;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_39();
}


/*
 * This function enables or disables Debug Enable module.
 */
 void Flexio_Mcl_Ip_SetDebugEnable(FLEXIO_Type *baseAddr, boolean enable)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_40();
    uint32 RegValue = (uint32)baseAddr->CTRL;

    RegValue &= (~((uint32)FLEXIO_CTRL_DBGE_MASK));
    RegValue |= FLEXIO_CTRL_DBGE((enable ? 1U : 0U));
    baseAddr->CTRL = (uint32)RegValue;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_40();
}

/*
 * This function enables or disables the FlexIO module.
 */
 void Flexio_Mcl_Ip_SetEnable(FLEXIO_Type *baseAddr, boolean enable)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_41();
    uint32 RegValue = (uint32)baseAddr->CTRL;

    RegValue &= (~((uint32)FLEXIO_CTRL_FLEXEN_MASK));
    RegValue |= FLEXIO_CTRL_FLEXEN((enable ? 1U : 0U));
    baseAddr->CTRL = (uint32)RegValue;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_41();
}


/*
 * This function returns the value of the status flag for the specified shifter.
 * The meaning of the status flag depends on the current mode.
 *  - Transmit mode: shifter buffer is empty and ready to accept more data
 *  - Receive mode: shifter buffer is full and received data can be read from it
 *  - Match Store mode: match occurred between shifter buffer and shifter
 *  - Match Continuous mode: current match result between shifter buffer and shifter
 */
 boolean Flexio_Mcl_Ip_GetShifterStatus(const FLEXIO_Type *baseAddr, uint8 shifter)
{
    return ((((baseAddr->SHIFTSTAT >> shifter) & 1U) != 0U) ? TRUE : FALSE);
}


/*
 * This function returns the value of the status flags for all shifters. Each bit in
 * the returned value specifies the status for one shifter, starting with
 * shifter 0 from least significant bit.
 * The meaning of the status flag depends on the current mode.
 *  - Transmit mode: shifter buffer is empty and ready to accept more data
 *  - Receive mode: shifter buffer is full and received data can be read from it
 *  - Match Store mode: match occurred between shifter buffer and shifter
 *  - Match Continuous mode: current match result between shifter buffer and shifter
 */
 uint32 Flexio_Mcl_Ip_GetAllShifterStatus(const FLEXIO_Type *baseAddr)
{
    return baseAddr->SHIFTSTAT;
}

/*
 * This function clears the status flag for the specified shifter. This is possible in
 * all modes except Match Continuous mode.
 */
 void Flexio_Mcl_Ip_ClearShifterStatus(FLEXIO_Type *baseAddr, uint8 shifter)
{
    baseAddr->SHIFTSTAT = 1UL << shifter;
}


/*
 * This function returns the value of the error status flag for the specified shifter.
 * The meaning of the error status flag depends on the current mode.
 *  - Transmit mode: shifter buffer was not written before it was transferred in the shifter (buffer overrun)
 *  - Receive mode: shifter buffer was not read before new data was transferred from the shifter (buffer underrun)
 *  - Match Store mode: match event occurred before the previous match data was read from shifter buffer (buffer overrun)
 *  - Match Continuous mode: match occurred between shifter buffer and shifter
 */
 boolean Flexio_Mcl_Ip_GetShifterErrorStatus(const FLEXIO_Type *baseAddr, uint8 shifter)
{
    return ((((baseAddr->SHIFTERR >> shifter) & 1U) != 0U) ? TRUE : FALSE);
}


/*
 * This function returns the value of the error status flags for all shifters. Each bit in
 * the returned value specifies the error status for one shifter, starting with
 * shifter 0 from least significant bit.
 * The meaning of the error status flag depends on the current mode.
 *  - Transmit mode: shifter buffer was not written before it was transferred in the shifter (buffer overrun)
 *  - Receive mode: shifter buffer was not read before new data was transferred from the shifter (buffer underrun)
 *  - Match Store mode: match event occurred before the previous match data was read from shifter buffer (buffer overrun)
 *  - Match Continuous mode: match occurred between shifter buffer and shifter
 */
 uint32 Flexio_Mcl_Ip_GetAllShifterErrorStatus(const FLEXIO_Type *baseAddr)
{
    return baseAddr->SHIFTERR;
}


/*
 * This function clears the error status flag for the specified shifter.
 */
 void Flexio_Mcl_Ip_ClearShifterErrorStatus(FLEXIO_Type *baseAddr, uint8 shifter)
{
    baseAddr->SHIFTERR = 1UL << shifter;
}


/*
 * This function returns the value of the status flag for the specified timer.
 * The meaning of the status flag depends on the current mode.
 *  - 8-bit counter mode: the timer status flag is set when the upper 8-bit counter equals zero
 * and decrements. This also causes the counter to reload with the value in the compare register.
 *  - 8-bit PWM mode: the upper 8-bit counter equals zero and decrements. This also causes the
 * counter to reload with the value in the compare register.
 *  - 16-bit counter mode: the 16-bit counter equals zero and decrements. This also causes the
 * counter to reload with the value in the compare register.
 */
 boolean Flexio_Mcl_Ip_GetTimerStatus(const FLEXIO_Type *baseAddr, uint8 timer)
{
    return ((((baseAddr->TIMSTAT >> timer) & 1U) != 0U) ? TRUE : FALSE);
}

 boolean Flexio_Mcl_Ip_GetTimerInterruptEnable(const FLEXIO_Type *baseAddr, uint8 timer)
{
    /* Get TIMIEN bit value */
    return ((((baseAddr->TIMIEN >> timer) & 1U) != 0U) ? TRUE : FALSE);
}
/*
 * This function returns the value of the status flags for all timers. Each bit in
 * the returned value specifies the status for one timer, starting with
 * timer 0 from least significant bit.
 * The meaning of the status flag depends on the current mode.
 *  - 8-bit counter mode: the timer status flag is set when the upper 8-bit counter equals zero
 * and decrements. This also causes the counter to reload with the value in the compare register.
 *  - 8-bit PWM mode: the upper 8-bit counter equals zero and decrements. This also causes the
 * counter to reload with the value in the compare register.
 *  - 16-bit counter mode: the 16-bit counter equals zero and decrements. This also causes the
 * counter to reload with the value in the compare register.
 */
 uint32 Flexio_Mcl_Ip_GetAllTimerStatus(const FLEXIO_Type *baseAddr)
{
    return baseAddr->TIMSTAT;
}


/*
 * This function clears the status flag for the specified timer.
 */
 void Flexio_Mcl_Ip_ClearTimerStatus(FLEXIO_Type *baseAddr, uint8 timer)
{
    baseAddr->TIMSTAT = 1UL << timer;
}

/*
 * Returns the state of the interrupt for all shifters. Each bit in
 * the returned value specifies the interrupt state for one shifter, starting with
 * shifter 0 from least significant bit.
 */
 uint32 Flexio_Mcl_Ip_GetAllShifterInterrupt(const FLEXIO_Type *baseAddr)
{
    return baseAddr->SHIFTSIEN;
}


/*
 * Returns the state of the error interrupt for all shifters. Each bit in
 * the returned value specifies the interrupt state for one shifter, starting with
 * shifter 0 from least significant bit.
 */
 uint32 Flexio_Mcl_Ip_GetAllShifterErrorInterrupt(const FLEXIO_Type *baseAddr)
{
    return baseAddr->SHIFTEIEN;
}

/*
 * Enable or disable specified shifter error interrupts. The interrupt mask must contain a
 * bit of 1 for each shifter who's error interrupt must be enabled or disabled.
 */
 void Flexio_Mcl_Ip_SetShifterErrorInterrupt(FLEXIO_Type *baseAddr, uint8 interruptMask, boolean enable)
{
    uint32 Tmp;

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_42();
    Tmp = baseAddr->SHIFTEIEN;

    if (enable == TRUE)
    {
        Tmp |= (uint32)interruptMask;
    }
    else
    {
        Tmp &= ~(uint32)interruptMask;
    }
    baseAddr->SHIFTEIEN = Tmp;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_42();
}


/*
 * Enable or disable specified shifter interrupts. The interrupt mask must contain a
 * bit of 1 for each shifter who's interrupt must be enabled or disabled.
 */
 void Flexio_Mcl_Ip_SetShifterInterrupt(FLEXIO_Type *baseAddr, uint8 interruptMask, boolean enable)
{
    uint32 Tmp;

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_43();
    Tmp = baseAddr->SHIFTSIEN;

    if (enable == TRUE)
    {
        Tmp |= (uint32)interruptMask;
    }
    else
    {
        Tmp &= ~(uint32)interruptMask;
    }
    baseAddr->SHIFTSIEN = Tmp;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_43();
}

#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
/*
 * This function returns the content of PINSTAT register
 */
uint32 Flexio_Mcl_Ip_GetAllPinsStatus(const FLEXIO_Type *baseAddr)
{
    return baseAddr->PINSTAT;
}

/*
 * This function returns the content of PINIEN register
 */
uint32 Flexio_Mcl_Ip_GetAllPinsInterrupt(const FLEXIO_Type *baseAddr)
{
    return baseAddr->PINIEN;
}
#endif
/*
 * Enable or disable specified shifter DMA requests. The request mask must contain a
 * bit of 1 for each shifter who's DMA requests must be enabled or disabled.
 */
 void Flexio_Mcl_Ip_SetShifterDMARequest(FLEXIO_Type *baseAddr, uint8 requestMask, boolean enable)
{
    uint32 Tmp;

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_44();
    Tmp = baseAddr->SHIFTSDEN;

    if (enable == TRUE)
    {
        Tmp |= (uint32)requestMask;
    }
    else
    {
        Tmp &= ~(uint32)requestMask;
    }
    baseAddr->SHIFTSDEN = Tmp;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_44();
}

/*
 * Returns the state of the interrupt for all timers. Each bit in
 * the returned value specifies the interrupt state for one timer, starting with
 * timer 0 from least significant bit.
 */
 uint32 Flexio_Mcl_Ip_GetAllTimerInterrupt(const FLEXIO_Type *baseAddr)
{
    return baseAddr->TIMIEN;
}


/*
 * Enable or disable specified timer interrupts. The interrupt mask must contain a
 * bit of 1 for each timer who's interrupt must be enabled or disabled.
 */
 void Flexio_Mcl_Ip_SetTimerInterrupt(FLEXIO_Type *baseAddr, uint8 interruptMask, boolean enable)
{
    uint32 Tmp;

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_45();
    Tmp = baseAddr->TIMIEN;

    if (enable == TRUE)
    {
        Tmp |= (uint32)interruptMask;
    }
    else
    {
        Tmp &= ~(uint32)interruptMask;
    }
    baseAddr->TIMIEN = Tmp;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_45();
}

/*
 * This function initializes all the registers of the FlexIO module to
 * their reset value.
 */
 void Flexio_Mcl_Ip_Init(FLEXIO_Type *baseAddr)
{
    /* Use software reset bit to reset the module */
    Flexio_Mcl_Ip_SetSoftwareReset(baseAddr, TRUE);
    /* Control register is not affected by software reset */
    baseAddr->CTRL = 0x0U;
}

#if (STD_ON == FLEXIO_MCL_IP_TIMERSDEN_IS_AVAILABLE)
/*
 * Enable or disable specified timer DMA requests. The request mask must contain a
 * bit of 1 for each shifter who's DMA requests must be enabled or disabled.
 */
void Flexio_Mcl_Ip_SetTimerDMARequest(FLEXIO_Type *baseAddr, uint8 requestMask, boolean enable)
{
    uint32 Tmp;

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_46();
    Tmp = baseAddr->TIMERSDEN;

    if (enable == TRUE)
    {
        Tmp |= (uint32)requestMask;
    }
    else
    {
        Tmp &= ~(uint32)requestMask;
    }
    baseAddr->TIMERSDEN = Tmp;
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_46();
}
#endif
#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
/*
 * This function clears the pin status flag for the specified pin.
 */
void Flexio_Mcl_Ip_ClearPinStatus(FLEXIO_Type *baseAddr, uint8 pin)
{
    /* Pin Status Register (PINSTAT) has W1C access type */
    baseAddr->PINSTAT = (uint8)(1U << pin);
}
#endif

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
