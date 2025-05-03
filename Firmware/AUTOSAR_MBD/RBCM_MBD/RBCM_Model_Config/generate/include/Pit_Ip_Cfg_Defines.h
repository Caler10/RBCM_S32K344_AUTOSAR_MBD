/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/


#ifndef PIT_IP_CFG_DEFINES_H
#define PIT_IP_CFG_DEFINES_H

/**
*   @file           Pit_Ip_Cfg_Defines.h
*
*   @addtogroup     pit_ip Pit IPL
*
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
#include "Std_Types.h"
#include "S32K344_PIT.h"

    /*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PIT_IP_DEFINES_VENDOR_ID_CFG                    43
#define PIT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define PIT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     7
#define PIT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define PIT_IP_DEFINES_SW_MAJOR_VERSION_CFG             5
#define PIT_IP_DEFINES_SW_MINOR_VERSION_CFG             0
#define PIT_IP_DEFINES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PIT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PIT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pit_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define PIT_IP_USED (STD_ON) 
#define PIT_IP_RTI_USED (STD_ON) 
/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define PIT_GPT_IP_MODULE_SINGLE_INTERRUPT	(STD_ON)
/*================================================================================================*/
/**
 * @brief   This define is STD_ON when on the same platform there are interrupts for all channels in one ISR,
 *          but also interrupt for each channel separately
 *
 */
#define PIT_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS    (STD_OFF)
#define PIT_IP_RTI_CHANNEL_EXISTS
/**
* @brief This defines
*
*/
#define PIT_IP_PECULIAR_INSTANCES (STD_OFF)
/**
*
* @brief IRQ Defines for each channel used
*/
#define PIT_0_ISR_USED

/**
*
* @brief Module Disable for PIT bit exists on current platform
*/
#define PIT_IP_INSTANCE_GAP_EXISTS (STD_OFF)
#define CRS_FSS_AND_RTU_BASE_ADDR_OF_PIT_REGISTERS_CONCATENATED (STD_OFF)
#define PIT_IP_MDIS_BIT_EXISTS    (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* PIT_IP_CFG_DEFINES_H */

