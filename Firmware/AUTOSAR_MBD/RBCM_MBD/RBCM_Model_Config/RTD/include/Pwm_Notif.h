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

#ifndef PWM_NOTIF_H
#define PWM_NOTIF_H

/**
*   @file       Pwm_Notif.h
*
*   @addtogroup pwm_driver Pwm Driver
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
#include "Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_NOTIF_VENDOR_ID                       43
#define PWM_NOTIF_MODULE_ID                       121
#define PWM_NOTIF_AR_RELEASE_MAJOR_VERSION        4
#define PWM_NOTIF_AR_RELEASE_MINOR_VERSION        7
#define PWM_NOTIF_AR_RELEASE_REVISION_VERSION     0
#define PWM_NOTIF_SW_MAJOR_VERSION                5
#define PWM_NOTIF_SW_MINOR_VERSION                0
#define PWM_NOTIF_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Pwm header file are of the same vendor */
#if (PWM_NOTIF_VENDOR_ID != PWM_VENDOR_ID)
    #error "Vendor IDs Pwm_Notif.h and Pwm.h are different."
#endif

/* Check if header file and Pwm header file are of the same AUTOSAR version */
#if ((PWM_NOTIF_AR_RELEASE_MAJOR_VERSION    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_NOTIF_AR_RELEASE_MINOR_VERSION    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_NOTIF_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Notif.h and Pwm.h are different."
#endif

/* Check if header file and Pwm_Notif header file are of the same software version */
#if ((PWM_NOTIF_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
     (PWM_NOTIF_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
     (PWM_NOTIF_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Notif.h and Pwm.h are different."
#endif

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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
void Pwm_Notification(uint8 Channel);
#endif /* PWM_NOTIFICATION_SUPPORTED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_NOTIF_H */
