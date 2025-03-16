/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm
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
==================================================================================================*/
#ifndef FLEXPWM_IP_CFGDEFINES_H
#define FLEXPWM_IP_CFGDEFINES_H

/**
*   @file       FlexPwm_Ip_CfgDefines.h
*
*   @addtogroup flexpwm_ip FlexPwm IPL
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
/* Standard Types */
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_CFGDEFINES_VENDOR_ID                    43
#define FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXPWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXPWM_IP_CFGDEFINES_SW_MAJOR_VERSION             4
#define FLEXPWM_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define FLEXPWM_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of FlexPwm_Ip_CfgDefines.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief        Switch to enable the notifications feature */
#define  FLEXPWM_IP_FAULT_CHANNELS_NO          (uint8)(1U)

/** @brief        Switch to enable the notifications feature in autosar mode or not */
#define  FLEXPWM_IP_NOTIFICATION_SUPPORT_HLD   (STD_ON)

/** @brief        This used to check when FlexPwm is available on this derivative */
#define  FLEXPWM_IP_AVAILABLE                  (STD_OFF)

/**
* @brief        Macro to indicate that PWM driver can support call IP layer directly or must be using HLD (Autosar mode).
* @note         In current implementation, this macro is defined equal to STD_ON if EB tresos
*               tool is used, because EB tresos only supports Autosar mode.
*               If CT tool is used, this mean PWM driver can support call IP layer directly or
*               using HLD layer, so this macro can be equal to STD_ON/STD_OFF
*/
#define PWM_FLEXPWM_AUTOSAR_MODE_IS_USED                (STD_ON)
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP_CFGDEFINES_H */


