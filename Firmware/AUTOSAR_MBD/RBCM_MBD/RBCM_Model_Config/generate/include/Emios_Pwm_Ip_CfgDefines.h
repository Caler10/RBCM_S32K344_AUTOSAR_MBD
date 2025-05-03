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

#ifndef EMIOS_PWM_IP_CFGDEFINES_H
#define EMIOS_PWM_IP_CFGDEFINES_H

/**
*   @file       EMIOS_Pwm_Ip_CfgDefines.h
*
*   @addtogroup emios_pwm_ip EMIOS Pwm IPL
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
/* Standard Types */
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_CFGDEFINES_VENDOR_ID                    43
#define EMIOS_PWM_IP_CFGDEFINES_MODULE_ID                    121
#define EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION             5
#define EMIOS_PWM_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of EMIOS_Pwm_Ip_CfgDefines.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief        Switch to enable the notifications feature */
#define EMIOS_PWM_IP_NOTIFICATION_SUPPORT             (STD_ON)

/** @brief        Macros to indicate eMIOS channels used. */
#ifndef EMIOS_0_CH_9_USED
    #define EMIOS_0_CH_9_USED
#else
    #error "EMIOS_0_CH_9 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_0_CH_17_USED
    #define EMIOS_0_CH_17_USED
#else
    #error "EMIOS_0_CH_17 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_1_CH_19_USED
    #define EMIOS_1_CH_19_USED
#else
    #error "EMIOS_1_CH_19 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_1_CH_20_USED
    #define EMIOS_1_CH_20_USED
#else
    #error "EMIOS_1_CH_20 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_1_CH_0_USED
    #define EMIOS_1_CH_0_USED
#else
    #error "EMIOS_1_CH_0 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_1_CH_1_USED
    #define EMIOS_1_CH_1_USED
#else
    #error "EMIOS_1_CH_1 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_1_CH_21_USED
    #define EMIOS_1_CH_21_USED
#else
    #error "EMIOS_1_CH_21 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_1_CH_22_USED
    #define EMIOS_1_CH_22_USED
#else
    #error "EMIOS_1_CH_22 channel cannot be used by Pwm. Channel locked by another driver!"
#endif
#ifndef EMIOS_2_CH_7_USED
    #define EMIOS_2_CH_7_USED
#else
    #error "EMIOS_2_CH_7 channel cannot be used by Pwm. Channel locked by another driver!"
#endif

/**
* @brief        Macros used to enable ISR for eMIOS channel
*
*/
#define PWM_EMIOS_0_CH_9_ISR_USED

#ifndef EMIOS_0_CH_9_ISR_USED
    #define EMIOS_0_CH_9_ISR_USED
#endif

#define PWM_EMIOS_0_CH_17_ISR_USED

#ifndef EMIOS_0_CH_17_ISR_USED
    #define EMIOS_0_CH_17_ISR_USED
#endif

#define PWM_EMIOS_1_CH_19_ISR_USED

#ifndef EMIOS_1_CH_19_ISR_USED
    #define EMIOS_1_CH_19_ISR_USED
#endif

#define PWM_EMIOS_1_CH_20_ISR_USED

#ifndef EMIOS_1_CH_20_ISR_USED
    #define EMIOS_1_CH_20_ISR_USED
#endif

#define PWM_EMIOS_1_CH_0_ISR_USED

#ifndef EMIOS_1_CH_0_ISR_USED
    #define EMIOS_1_CH_0_ISR_USED
#endif

#define PWM_EMIOS_1_CH_1_ISR_USED

#ifndef EMIOS_1_CH_1_ISR_USED
    #define EMIOS_1_CH_1_ISR_USED
#endif

#define PWM_EMIOS_1_CH_21_ISR_USED

#ifndef EMIOS_1_CH_21_ISR_USED
    #define EMIOS_1_CH_21_ISR_USED
#endif

#define PWM_EMIOS_1_CH_22_ISR_USED

#ifndef EMIOS_1_CH_22_ISR_USED
    #define EMIOS_1_CH_22_ISR_USED
#endif

#define PWM_EMIOS_2_CH_7_ISR_USED

#ifndef EMIOS_2_CH_7_ISR_USED
    #define EMIOS_2_CH_7_ISR_USED
#endif

/**
* @brief        Macro to indicate that PWM driver can support call IP layer directly or must be using HLD (Autosar mode).
* @note         In current implementation, this macro is defined equal to STD_ON if EB tresos
*               tool is used, because EB tresos only supports Autosar mode.
*               If CT tool is used, this mean PWM driver can support call IP layer directly or
*               using HLD layer, so this macro can be equal to STD_ON/STD_OFF
*/
#define EMIOS_PWM_IP_AUTOSAR_MODE_IS_USED           (STD_ON)
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

#endif /* EMIOS_PWM_IP_CFGDEFINES_H */

