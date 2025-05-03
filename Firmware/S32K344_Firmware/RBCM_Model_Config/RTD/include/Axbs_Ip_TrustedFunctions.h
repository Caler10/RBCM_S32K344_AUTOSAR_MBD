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

#ifndef ABXS_IP_TRUSTEDFUNCTIONS_H
#define ABXS_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Axbs_Ip_TrustedFunctions.h
*
*   @addtogroup AXBS_IP AXBS IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
==================================================================================================*/
#include "Axbs_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               5
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define RM_AXBS_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Axbs_Ip_Cfg header file are of the same vendor */
#if (RM_AXBS_IP_CFG_VENDOR_ID != RM_AXBS_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Axbs_Ip_TrustedFunctions.h and Axbs_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and AXBS_Ip_Cfg header file are of the same Autosar version */
#if ((RM_AXBS_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Axbs_Ip_TrustedFunctions.h and Axbs_Ip_Cfg.h are different"
#endif
/* Check if current file and Axbs_Ip_Cfg header file are of the same Software version */
#if ((RM_AXBS_IP_CFG_SW_MAJOR_VERSION != RM_AXBS_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_CFG_SW_MINOR_VERSION != RM_AXBS_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_CFG_SW_PATCH_VERSION != RM_AXBS_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip_TrustedFunctions.h and Axbs_Ip_Cfg.h are different"
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
#ifdef RM_IP_ENABLE_AXBS
#if (RM_IP_ENABLE_AXBS == STD_ON)

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
/**
* @brief        This function write into Crs register.
*
* @param[in]    u32Addr   The Crs register.
* @param[in]    value     The value will be written.
*/
extern void Axbs_Ip_Crs_Write(uint32 u32Addr,
                              uint32 value);

/**
* @brief        This function return the value of Crs register.
*
* @param[in]    u32Addr   The Crs register.
*
* @return       the value of Crs register.
*/
extern uint32 Axbs_Ip_Crs_Read(uint32 u32Addr);

#ifdef RM_CROSSBAR_PRS_READONLY
#if (STD_OFF == RM_CROSSBAR_PRS_READONLY)
/**
* @brief        This function write into Prs register.
*
*/
extern void Axbs_Ip_Prs_Write(uint32 u32Addr,
                              uint32 value);


#endif
#endif

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* (RM_IP_ENABLE_AXBS == STD_ON) */
#endif /* RM_IP_ENABLE_AXBS */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ABXS_IP_TRUSTEDFUNCTIONS_H */
