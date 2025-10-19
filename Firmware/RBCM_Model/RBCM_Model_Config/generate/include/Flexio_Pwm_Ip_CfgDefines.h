/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm eTpu
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

#ifndef FLEXIO_PWM_IP_CFGDEFINES_H
#define FLEXIO_PWM_IP_CFGDEFINES_H

/**
*   @file Flexio_Pwm_Ip_CfgDefines.h
*
*   @addtogroup flexio_pwm_ip FlexIO Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_CFGDEFINES_VENDOR_ID                    43
#define FLEXIO_PWM_IP_CFGDEFINES_MODULE_ID                    121
#define FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION             5
#define FLEXIO_PWM_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Flexio_Pwm_Ip_CfgDefines.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief      Flexio Timer has 8bit pwm low mode */
#define FLEXIO_PWM_IP_HAS_LOW_MODE              (STD_ON)

/** @brief      Flexio Timer has prescaler */
#define FLEXIO_PWM_IP_HAS_PRESCALER             (STD_ON)

/** @brief      Flexio pin override value  */
#define FLEXIO_PWM_IP_HAS_PIN_OVERRIDE          (STD_ON)

/* Defines for use with MCL Flexio common part */

/**
* @brief        Macro to indicate that PWM driver can support call IP layer directly or must be using HLD (Autosar mode).
* @note         In current implementation, this macro is defined equal to STD_ON if EB tresos
*               tool is used, because EB tresos only supports Autosar mode.
*               If CT tool is used, this mean PWM driver can support call IP layer directly or
*               using HLD layer, so this macro can be equal to STD_ON/STD_OFF
*/
#define FLEXIO_PWM_IP_AUTOSAR_MODE_IS_USED                (STD_ON)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_CFGDEFINES_H */

