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

#ifndef VIRT_WRAPPER_IP_H
#define VIRT_WRAPPER_IP_H

/**
*   @file Virt_Wrapper_Ip.h
*
*   @addtogroup Virt_Wrapper_Ip Virt Wrapper IPV Driver
*   @{
*/

#include "Virt_Wrapper_Ip_Cfg.h"

#ifdef VIRT_WRAPPER_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VIRT_WRAPPER_IP_VENDOR_ID                      43
#define RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION       4
#define RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION       7
#define RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION    0
#define RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION               5
#define RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION               0
#define RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Virt_Wrapper_Ip_Cfg.h */
#if (RM_VIRT_WRAPPER_IP_VENDOR_ID != RM_VIRT_WRAPPER_IP_CFG_VENDOR_ID)
    #error "Virt_Wrapper_Ip.h and Virt_Wrapper_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip.h and Virt_Wrapper_Ip_Cfg.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_CFG_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Virt_Wrapper_Ip.h and Virt_Wrapper_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef VIRT_WRAPPER_IP_ENABLE_USER_MODE_SUPPORT
        /* Checks against OsIf.h */
        #if ((RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip.h and OsIf.h are different"
        #endif
    #endif
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


#ifdef RM_IP_ENABLE_VIRT_WRAPPER
#if (RM_IP_ENABLE_VIRT_WRAPPER == STD_ON)

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/**
* @brief   Export VIRT_WRAPPER configurations.
*/
VIRT_WRAPPER_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
/**
 * @brief       Initialize virtual wrapper driver
 * 
 * @details
 * 
 * @param[in]   pVirt_WrapperConfig: pointer to Virtual wrapper configuration
 * 
 * @return      void
 * 
 */
void Virt_Wrapper_Ip_Init(const Virt_Wrapper_Ip_ConfigType *pVirt_WrapperConfig);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* if (RM_IP_ENABLE_VIRT_WRAPPER == STD_ON) */
#endif /* ifdef RM_IP_ENABLE_VIRT_WRAPPER */

#if defined(__cplusplus)
}
#endif

/** @} */

#endif  /* VIRT_WRAPPER_IP_H */
