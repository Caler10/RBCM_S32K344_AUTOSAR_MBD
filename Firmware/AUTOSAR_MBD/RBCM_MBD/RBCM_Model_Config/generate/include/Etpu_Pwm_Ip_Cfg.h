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

#ifndef ETPU_PWM_IP_CFG_H
#define ETPU_PWM_IP_CFG_H

/**
*   @file       Etpu_Pwm_Ip_Cfg.h
*
*   @addtogroup etpu_pwm_ip Etpu Pwm IPL
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

/* Include all variants header files. */
#include "Etpu_Pwm_Ip_MBDT_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETPU_PWM_IP_CFG_VENDOR_ID                    43
#define ETPU_PWM_IP_CFG_MODULE_ID                    121
#define ETPU_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define ETPU_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define ETPU_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define ETPU_PWM_IP_CFG_SW_MAJOR_VERSION             5
#define ETPU_PWM_IP_CFG_SW_MINOR_VERSION             0
#define ETPU_PWM_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((ETPU_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ETPU_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Etpu_Pwm_Ip_Cfg.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Etpu_Pwm_Ip_MBDT_PBcfg.h header file are of the same vendor */
#if (ETPU_PWM_IP_CFG_VENDOR_ID != ETPU_PWM_IP_MBDT_PB_CFG_VENDOR_ID)
#error "Vendor IDs of Etpu_Pwm_Ip_Cfg.h and Etpu_Pwm_Ip_MBDT_PBcfg.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_MBDT_PBcfg.h header file are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION  != ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR version numbers of Etpu_Pwm_Ip_Cfg.h and Etpu_Pwm_Ip_MBDT_Pbcfg.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_MBDT_PBcfg.h header file are of the same software version */
#if ((ETPU_PWM_IP_CFG_SW_MAJOR_VERSION != ETPU_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_CFG_SW_MINOR_VERSION != ETPU_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_CFG_SW_PATCH_VERSION != ETPU_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION))
#error "Software version numbers of Eptu_Pwm_Ip_Cfg.h and Etpu_Pwm_Ip_MBDT_Pbcfg.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define ETPU_PWM_IP_ENGINE_COUNT        (2U)
#define ETPU_PWM_IP_CHANNEL_COUNT       (32U)

#define ETPU_PWM_IP_DATA_RAM_START      (0)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* @brief Define if global variables need to be placed in non-cache area or not */
#define ETPU_PWM_IP_NO_CACHE_NEEDED     (STD_OFF)

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

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETPU_PWM_IP_CFG_H */
