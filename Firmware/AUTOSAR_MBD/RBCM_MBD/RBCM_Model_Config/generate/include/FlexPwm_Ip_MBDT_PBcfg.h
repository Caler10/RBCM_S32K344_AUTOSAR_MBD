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

#ifndef FLEXPWM_IP_MBDT_PBCFG_H
#define FLEXPWM_IP_MBDT_PBCFG_H

/**
*   @file       FlexPwm_Ip_MBDT_PBcfg.h
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
#include "FlexPwm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_MBDT_PB_CFG_VENDOR_ID                       43
#define FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define FLEXPWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION                5
#define FLEXPWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION                0
#define FLEXPWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and FlexPwm_Ip_Types header file are of the same vendor */
#if (FLEXPWM_IP_MBDT_PB_CFG_VENDOR_ID != FLEXPWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_MBDT_PBcfg.h and FlexPwm_Ip_Types.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_MBDT_PBcfg.h and FlexPwm_Ip_Types.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same software version */
#if ((FLEXPWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION != FLEXPWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION != FLEXPWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_MBDT_PBcfg.h and FlexPwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef FLEXPWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FLEXPWM_IP_PRECOMPILE_SUPPORT */

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP_MBDT_PBCFG_H */

