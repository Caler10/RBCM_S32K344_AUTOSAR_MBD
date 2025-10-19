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

/**
*   @file CDD_Rm_PBcfg.c
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rm_Cfg.h"
#include "CDD_Rm.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_PBCFG_MBDT_VENDOR_ID_C                     43
#define RM_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION_C      7
#define RM_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION_C   0
#define RM_PBCFG_MBDT_SW_MAJOR_VERSION_C              5
#define RM_PBCFG_MBDT_SW_MINOR_VERSION_C              0
#define RM_PBCFG_MBDT_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Cfg.h */
#if (RM_PBCFG_MBDT_VENDOR_ID_C != RM_CFG_VENDOR_ID)
    #error "CDD_Rm_MBDT_PBcfg.c and CDD_Rm_Cfg.h have different vendor ids"
#endif
#if ((RM_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION_C    != RM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION_C    != RM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION_C != RM_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_MBDT_PBcfg.c and CDD_Rm_Cfg.h are different"
#endif
#if ((RM_PBCFG_MBDT_SW_MAJOR_VERSION_C != RM_CFG_SW_MAJOR_VERSION) || \
     (RM_PBCFG_MBDT_SW_MINOR_VERSION_C != RM_CFG_SW_MINOR_VERSION) || \
     (RM_PBCFG_MBDT_SW_PATCH_VERSION_C != RM_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_MBDT_PBcfg.c and CDD_Rm_Cfg.h are different"
#endif

/* Checks against CDD_Rm.h */
#if (RM_PBCFG_MBDT_VENDOR_ID_C != RM_VENDOR_ID)
    #error "CDD_Rm_MBDT_PBcfg.c and CDD_Rm.h have different vendor ids"
#endif
#if ((RM_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION_C    != RM_AR_RELEASE_MAJOR_VERSION) || \
     (RM_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION_C    != RM_AR_RELEASE_MINOR_VERSION) || \
     (RM_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION_C != RM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_MBDT_PBcfg.c and CDD_Rm.h are different"
#endif
#if ((RM_PBCFG_MBDT_SW_MAJOR_VERSION_C != RM_SW_MAJOR_VERSION) || \
     (RM_PBCFG_MBDT_SW_MINOR_VERSION_C != RM_SW_MINOR_VERSION) || \
     (RM_PBCFG_MBDT_SW_PATCH_VERSION_C != RM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_MBDT_PBcfg.c and CDD_Rm.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                      LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

/**
* @brief            Rm basic configuration.
* @details          Configuration for Rm.
*
*/
const Rm_ConfigType Rm_Config_MBDT =
{
    &Rm_Ipw_Config_MBDT
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

