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
#ifndef SEMA42_IP_TYPES_H_
#define SEMA42_IP_TYPES_H_

/**
*   @file Sema42_Ip_Types.h
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
#include "BasicTypes.h"
#include "Sema42_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_SEMA42_IP_TYPES_VENDOR_ID                      43
#define RM_SEMA42_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define RM_SEMA42_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define RM_SEMA42_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define RM_SEMA42_IP_TYPES_SW_MAJOR_VERSION               5
#define RM_SEMA42_IP_TYPES_SW_MINOR_VERSION               0
#define RM_SEMA42_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Sema42_Ip_Cfg_Defines.h */
#if (RM_SEMA42_IP_TYPES_VENDOR_ID != RM_SEMA42_IP_CFG_DEFINES_VENDOR_ID)
    #error "Sema42_Ip_Types.h and Sema42_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_SEMA42_IP_TYPES_AR_RELEASE_MAJOR_VERSION != RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_AR_RELEASE_MINOR_VERSION != RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Sema42_Ip_Types.h and Sema42_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_SEMA42_IP_TYPES_SW_MAJOR_VERSION != RM_SEMA42_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_SW_MINOR_VERSION != RM_SEMA42_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_SW_PATCH_VERSION != RM_SEMA42_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Sema42_Ip_Types.h and Sema42_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define FOUR_BIT_MAX_VALUE    16U
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief          Enumeration listing the possible return codes for Sema42 Ip driver
*/
typedef enum
{
    SEMA42_IP_SUCCESS = 0UL,    /*!< Operation successful */
    SEMA42_IP_ERROR   = 1UL     /*!< Operation resulted in error */
} Sema42_Ip_StatusType;

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

#endif /* SEMA42_IP_TYPES_H_ */
