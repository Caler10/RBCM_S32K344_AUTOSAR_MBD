/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef WKPU_IP_DEFINES_H
#define WKPU_IP_DEFINES_H

/**
 *   @file    Wkpu_Ip_Defines.h
 *   @version 5.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup wkpu_icu_ip WKPU IPL
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
 *================================================================================================*/
#include "Std_Types.h"

#include "S32K344_WKPU.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define WKPU_IP_DEFINES_VENDOR_ID                    43
#define WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define WKPU_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WKPU_IP_DEFINES_SW_MAJOR_VERSION             5
#define WKPU_IP_DEFINES_SW_MINOR_VERSION             0
#define WKPU_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define WKPU_IP_USED               (STD_OFF)

#if (STD_ON == WKPU_IP_USED)
#define WKPU_IP_NMI_API            (STD_OFF)

#define WKPU_IP_SUPPORT_INTERRUPT_REQUEST
#define WKPU_IP_NUM_OF_CHANNELS               (64U)

/** @brief The number of Wkpu channels are used in configuration */
#define WKPU_IP_NUM_OF_CHANNELS_USED          ((uint8)0U)

#define WKPU_IP_NUM_OF_CHANNELS_IN_ONE_REG    (32U)

/** @brief Switch for enabling Standby wakeup support  on or off */
#define WKPU_IP_STANDBY_WAKEUP_SUPPORT        (STD_OFF)
/** @brief Define if global variables need to be placed in non-cache area or not */
#define WKPU_IP_NO_CACHE_USED                 (STD_OFF)

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* WKPU_IP_DEFINES_H */

