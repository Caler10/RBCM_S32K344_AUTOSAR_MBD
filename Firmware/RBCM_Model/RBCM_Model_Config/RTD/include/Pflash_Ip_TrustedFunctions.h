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

#ifndef PFLASH_IP_TRUSTEDFUNCTIONS_H
#define PFLASH_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Pflash_Ip_TrustedFunctions.h
*
*   @addtogroup Pflash_Ip Pflash IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pflash_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               5
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define RM_PFLASH_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pflash_Ip_Cfg.h header file are of the same vendor */
#if (RM_PFLASH_IP_CFG_VENDOR_ID != RM_PFLASH_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Pflash_Ip_TrustedFunctions.h and Pflash_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Pflash_Ip_Cfg.h header file are of the same Autosar version */
#if ((RM_PFLASH_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_PFLASH_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_PFLASH_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_PFLASH_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (RM_PFLASH_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_PFLASH_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pflash_Ip_TrustedFunctions.h and Pflash_Ip_Cfg.h are different"
#endif
/* Check if current file and Pflash_Ip_Cfg.h header file are of the same Software version */
#if ((RM_PFLASH_IP_CFG_SW_MAJOR_VERSION != RM_PFLASH_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (RM_PFLASH_IP_CFG_SW_MINOR_VERSION != RM_PFLASH_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (RM_PFLASH_IP_CFG_SW_PATCH_VERSION != RM_PFLASH_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pflash_Ip_TrustedFunctions.h and Pflash_Ip_Cfg.h are different"
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

#ifdef RM_IP_ENABLE_PFLASH
#if (RM_IP_ENABLE_PFLASH == STD_ON)

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

#ifdef PFLASH_IP_ENABLE_USER_MODE_SUPPORT
/**
 * @brief         Pflash_Ip_SetUserAccessAllowed
 *
 * @details       This function is Reentrant
 *
 * @param[in]     address: Address to allow
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
extern void Pflash_Ip_SetUserAccessAllowed(uint32 address);

#endif /* PFLASH_IP_ENABLE_USER_MODE_SUPPORT */

/**
 * @brief         Set a master access protection by Pflash
 *
 * @details       This function is Reentrant
 *
 * @param[in]     eMaster: Master access protection field
 * @param[in]     eAccess: Access type
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
extern void Pflash_Ip_SetAccessProtection_Privileged(Pflash_Ip_MasterType eMaster,
                                                     Pflash_Ip_MasterAccessType eAccess);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* (RM_IP_ENABLE_PFLASH == STD_ON) */
#endif /* RM_IP_ENABLE_PFLASH */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PFLASH_IP_TRUSTEDFUNCTIONS_H */
