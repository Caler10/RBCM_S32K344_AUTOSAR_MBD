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

#ifndef ETPU_PWM_IP_MBDT_PBCFG_H
#define ETPU_PWM_IP_MBDT_PBCFG_H
/**
*   @file       Etpu_Pwm_Ip_MBDT_PBcfg.h
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
#include "Etpu_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETPU_PWM_IP_MBDT_PB_CFG_VENDOR_ID                       43
#define ETPU_PWM_IP_MBDT_PB_CFG_MODULE_ID                       121
#define ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define ETPU_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION                5
#define ETPU_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION                0
#define ETPU_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Etpu_Pwm_Ip_Types header file are of the same vendor */
#if (ETPU_PWM_IP_MBDT_PB_CFG_VENDOR_ID != ETPU_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Etpu_Pwm_Ip_MBDT_PBcfg.h and Etpu_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Types header file are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION != ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION != ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION != ETPU_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Etpu_Pwm_Ip_MBDT_PBcfg.h and Etpu_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Types header file are of the same software version */
#if ((ETPU_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION != ETPU_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION != ETPU_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION != ETPU_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Etpu_Pwm_Ip_MBDT_PBcfg.h and Etpu_Pwm_Ip_Types.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETPU_PWM_IP_MBDT_PBCFG_H */
