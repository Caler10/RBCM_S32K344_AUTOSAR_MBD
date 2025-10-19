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

#ifndef MSCM_IP_H
#define MSCM_IP_H

/**
*   @file Mscm_Ip.h
*
*   @addtogroup Mscm_Ip Mscm IPV Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mscm_Ip_Cfg.h"

#ifdef MSCM_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_VENDOR_ID                      43
#define RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION       4
#define RM_MSCM_IP_AR_RELEASE_MINOR_VERSION       7
#define RM_MSCM_IP_AR_RELEASE_REVISION_VERSION    0
#define RM_MSCM_IP_SW_MAJOR_VERSION               5
#define RM_MSCM_IP_SW_MINOR_VERSION               0
#define RM_MSCM_IP_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mscm_Ip_Cfg.h */
#if (RM_MSCM_IP_VENDOR_ID != RM_MSCM_IP_CFG_VENDOR_ID)
    #error "Mscm_Ip.h and Mscm_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip.h and Mscm_Ip_Cfg.h are different"
#endif
#if ((RM_MSCM_IP_SW_MAJOR_VERSION != RM_MSCM_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_SW_MINOR_VERSION != RM_MSCM_IP_CFG_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_SW_PATCH_VERSION != RM_MSCM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip.h and Mscm_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#if defined(__cplusplus)
extern "C" {
#endif


#ifdef RM_IP_ENABLE_MSCM
#if (RM_IP_ENABLE_MSCM == STD_ON)

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/**
* @brief   Export Mscm configurations.
*/
MSCM_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief       Initializes the configured Mscm.
 *
 * @details
 *
 * @param[in]   pMscmConfig: pointer to mscm configuration
 *
 * @return void
 *
 */
void Mscm_Ip_Init(const Mscm_Ip_ConfigType *pMscmConfig);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"
#endif /* if (RM_IP_ENABLE_MSCM == STD_ON) */
#endif /* ifdef RM_IP_ENABLE_MSCM */

#if defined(__cplusplus)
}
#endif

#endif /* MSCM_IP_H */

/** @} */
