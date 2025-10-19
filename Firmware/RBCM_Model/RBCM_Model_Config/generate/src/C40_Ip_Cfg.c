/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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
 * @file       C40_Ip_Cfg.c
 *
 * @addtogroup C40_IP
 * implement   C40_Ip_Cfg.c_Artifact
 *
 * @{
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
#include "C40_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_VENDOR_ID_CFG_C                          43
#define C40_IP_AR_RELEASE_MAJOR_VERSION_CFG_C           4
#define C40_IP_AR_RELEASE_MINOR_VERSION_CFG_C           7
#define C40_IP_AR_RELEASE_REVISION_VERSION_CFG_C        0
#define C40_IP_SW_MAJOR_VERSION_CFG_C                   5
#define C40_IP_SW_MINOR_VERSION_CFG_C                   0
#define C40_IP_SW_PATCH_VERSION_CFG_C                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and C40_Ip_Cfg.h header file are of the same vendor */
#if (C40_IP_VENDOR_ID_CFG_C != C40_IP_VENDOR_ID_CFG)
    #error "C40_Ip_Cfg.c and C40_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Cfg.h header file are of the same Autosar version */
#if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != C40_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_REVISION_VERSION_CFG_C != C40_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of C40_Ip_Cfg.c and C40_Ip_Cfg.h are different"
#endif
/* Check if current file and C40_Ip_Cfg.h header file are of the same Software version */
#if ((C40_IP_SW_MAJOR_VERSION_CFG_C != C40_IP_SW_MAJOR_VERSION_CFG) || \
     (C40_IP_SW_MINOR_VERSION_CFG_C != C40_IP_SW_MINOR_VERSION_CFG) || \
     (C40_IP_SW_PATCH_VERSION_CFG_C != C40_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of C40_Ip_Cfg.c and C40_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

/* Declaration of Mem notification function (MBDT_Mem_StartFlashAccess_Notification())*/
extern void MBDT_Mem_StartFlashAccess_Notification (void);

/* Declaration of Mem notification function (MBDT_Mem_FinishedFlashAccess_Notification())*/
extern void MBDT_Mem_FinishedFlashAccess_Notification (void);

#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


const C40_Ip_ConfigType C40_Ip_InitCfg =
{
    &MBDT_Mem_StartFlashAccess_Notification,                /* MemStartFlashAccessNotif    */
    &MBDT_Mem_FinishedFlashAccess_Notification              /* MemFinishedFlashAccessNotif */
};


#define MEM_43_INFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

