/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
#ifndef SEMA42_IP_DEVICE_REGISTERS_H_
#define SEMA42_IP_DEVICE_REGISTERS_H_

/**
*   @file Sema42_Ip_DeviceRegisters.h
*
*   @addtogroup Sema42_Ip Sema42 IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_SEMA42_IP_DEVICE_REGISTERS_VENDOR_ID                      43
#define RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION       4
#define RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION       7
#define RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION    0
#define RM_SEMA42_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION               5
#define RM_SEMA42_IP_DEVICE_REGISTERS_SW_MINOR_VERSION               0
#define RM_SEMA42_IP_DEVICE_REGISTERS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against Std_Types.h */
#if ((RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Sema42_Ip_DeviceRegisters.h and Std_Types.h are different"
#endif
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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SEMA42_IP_DEVICE_REGISTERS_H_ */
