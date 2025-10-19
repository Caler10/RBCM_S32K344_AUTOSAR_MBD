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
*   @file    Etpu_Pwm_Ip_MBDT_PBcfg.c
*
*   @addtogroup etpu_pwm_ip Etpu Pwm
*   @{
*/

#ifdef __cplusplus
extern "C"
{
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
#define ETPU_PWM_IP_MBDT_PB_CFG_VENDOR_ID_C                       43
#define ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define ETPU_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION_C                5
#define ETPU_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION_C                0
#define ETPU_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Etpu_Pwm_Ip_Types.h file are of the same vendor */
#if (ETPU_PWM_IP_MBDT_PB_CFG_VENDOR_ID_C != ETPU_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Etpu_Pwm_MBDT_PBcfg.c and Etpu_Pwm_Ip_Types.h are different."
#endif

/* Check if source file and Etpu_Pwm_Ip_Types.h file are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION_C != ETPU_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Etpu_Pwm_MBDT_PBcfg.c and Etpu_Pwm_Ip_Types.h are different."
#endif

/* Check if source file and Etpu_Pwm_Ip_Types.h file are of the same Software version */
#if ((ETPU_PWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION_C != ETPU_PWM_IP_TYPES_SW_MAJOR_VERSION)  || \
     (ETPU_PWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION_C != ETPU_PWM_IP_TYPES_SW_MINOR_VERSION)  || \
     (ETPU_PWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION_C != ETPU_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Etpu_Pwm_MBDT_PBcfg.c and Etpu_Pwm_Ip_Types.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @brief  Prototypes of Etpu channels User Notifications */
extern void Pwm_Ipw_EtpuNotification(uint8 Channel);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
