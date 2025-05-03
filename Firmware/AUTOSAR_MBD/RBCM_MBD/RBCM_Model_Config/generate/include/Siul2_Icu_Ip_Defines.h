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

#ifndef SIUL2_ICU_IP_DEFINES_H
#define SIUL2_ICU_IP_DEFINES_H

/**
 *   @file       Siul2_Icu_Ip_Defines.h
 *   @version    5.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup siul2_icu_ip SIUL2 IPL
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

#include "S32K344_SIUL2.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_DEFINES_VENDOR_ID                      43
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION       4
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION       7
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION    0
#define SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION               5
#define SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION               0
#define SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define SIUL2_ICU_IP_USED                      (STD_ON)

#if (STD_ON == SIUL2_ICU_IP_USED)

/* Redefines the address table of the Siul2 instance. */
#define SIUL2_ICU_IP_BASE_PTRS                  IP_SIUL2_BASE_PTRS

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define SIUL2_ICU_IP_DEV_ERROR_DETECT           (STD_ON)

/** @brief The number of Siul2 instances available on platform */
#define SIUL2_ICU_IP_NUM_OF_INSTANCES           (1U)

/** @brief The number of channels available on each instance */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS            (32U)

/** @brief The number of Siul2 channels are used in configuration */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS_USED       ((uint8)1U)

/** @brief Adds or removes all services related to the de-initialization functionality. */
#define SIUL2_ICU_IP_DEINIT_API                 (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define SIUL2_ICU_IP_SET_MODE_API               (STD_ON)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define SIUL2_ICU_IP_DUAL_CLOCK_MODE_API        (STD_OFF)

/** @brief Add or remove all functions related to input state. */
#define SIUL2_ICU_IP_GET_INPUT_STATE_API        (STD_ON)

/** @brief Define if global variables need to be placed in non-cache area or not */
#define SIUL2_ICU_IP_NO_CACHE_USED              (STD_OFF)

/** @brief Add or remove VirtWrapper support */
#define SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT        (STD_OFF)

/** @brief Support for User mode. If this parameter has been configured to STD_ON, the Siul2 driver
 *         code can be executed from both supervisor and user mode. */
#define SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#define SIUL2_ICU_IP_INITIAL_INDEX_OF_CHANNELS \
    { \
        {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U} \
    }

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_DEFINES_H */

