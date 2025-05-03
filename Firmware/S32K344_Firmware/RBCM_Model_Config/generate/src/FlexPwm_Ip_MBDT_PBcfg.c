
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

/**
*   @file       FlexPwm_Ip_MBDT_PBcfg.c
*
*   @addtogroup flexpwm_ip FlexPwm Pwm IPL
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
#include "FlexPwm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXPWM_IP_MBDT_PB_CFG_VENDOR_ID_C                       43
#define FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define FLEXPWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION_C                5
#define FLEXPWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION_C                0
#define FLEXPWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FlexPwm_Ip_Cfg.h file are of the same vendor */
#if (FLEXPWM_IP_MBDT_PB_CFG_VENDOR_ID_C != FLEXPWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_MBDT_PBcfg.c and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Cfg.h file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_MBDT_PBcfg.c and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Cfg.h file are of the same Software version */
#if ((FLEXPWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION_C != FLEXPWM_IP_CFG_SW_MAJOR_VERSION)  || \
     (FLEXPWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION_C != FLEXPWM_IP_CFG_SW_MINOR_VERSION)  || \
     (FLEXPWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION_C != FLEXPWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_MBDT_PBcfg.c and FlexPwm_Ip_Cfg.h are different."
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifndef FLEXPWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FLEXPWM_IP_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

