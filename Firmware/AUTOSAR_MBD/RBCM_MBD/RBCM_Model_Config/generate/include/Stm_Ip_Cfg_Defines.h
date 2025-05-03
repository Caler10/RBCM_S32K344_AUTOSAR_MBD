/*==================================================================================================
* Project :             RTD AUTOSAR 4.7
* Platform :            CORTEXM
* Peripheral :          Stm_Pit_Rtc_Emios
* Dependencies :        none
*
* Autosar Version :     4.7.0
* Autosar Revision :    ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version :          5.0.0
* Build Version :       S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
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

#ifndef STM_IP_CFG_DEFINES_H
#define STM_IP_CFG_DEFINES_H

/**
*   @file           Stm_Ip_Cfg_Defines.h
*
*   @addtogroup     stm_ip Stm IPL
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
#include "S32K344_STM.h"

    /*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_DEFINES_VENDOR_ID_CFG                    43
#define STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     7
#define STM_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define STM_IP_DEFINES_SW_MAJOR_VERSION_CFG             5
#define STM_IP_DEFINES_SW_MINOR_VERSION_CFG             0
#define STM_IP_DEFINES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Stm_Ip_Cfg_Defines.h and Std_Types.h are different"
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
#define STM_IP_USED (STD_OFF) 
/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define STM_GPT_IP_MODULE_SINGLE_INTERRUPT	(STD_ON)
/**
*
* @brief  CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED
*/
#define CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED (STD_OFF)

/**
 * @brief   This define is STD_ON when on the same platform there are interrupts for all channels in one ISR,
 *          but also interrupt for each channel separately
 *
 */
#define STM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS    (STD_OFF)
/**
* @brief    STM_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define STM_IP_SET_CLOCK_MODE     (STD_OFF)
/**
* @{
* @brief IRQ Defines for each channel used
*/

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
#endif  /* STM_IP_CFG_DEFINES_H */

