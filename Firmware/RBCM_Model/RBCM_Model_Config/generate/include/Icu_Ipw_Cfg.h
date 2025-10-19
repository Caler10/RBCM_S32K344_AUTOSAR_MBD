/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef ICU_IPW_CFG_H
#define ICU_IPW_CFG_H

/**
 *   @file Icu_Ipw_Cfg.h
 *   @version 5.0.0
 *
 *   @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
 *   @details Contains the configuration data of the ICU driver
 *   @internal
 *   @addtogroup icu_ipw
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
#include "Icu_Ipw_MBDT_PBcfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_CFG_VENDOR_ID                       43
#define ICU_IPW_CFG_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_CFG_AR_RELEASE_MINOR_VERSION        7
#define ICU_IPW_CFG_AR_RELEASE_REVISION_VERSION     0
#define ICU_IPW_CFG_SW_MAJOR_VERSION                5
#define ICU_IPW_CFG_SW_MINOR_VERSION                0
#define ICU_IPW_CFG_SW_PATCH_VERSION                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU configuration header file are of the same vendor */
#if (ICU_IPW_CFG_VENDOR_ID != ICU_IPW_MBDT_PBCFG_VENDOR_ID)
    #error "Icu_Ipw_Cfg.h and Icu_Ipw_MBDT_PBcfg.h have different vendor IDs"
#endif
/* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((ICU_IPW_CFG_AR_RELEASE_MAJOR_VERSION != ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_CFG_AR_RELEASE_MINOR_VERSION != ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_CFG_AR_RELEASE_REVISION_VERSION != ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Cfg.h and Icu_Ipw_MBDT_PBcfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
#if ((ICU_IPW_CFG_SW_MAJOR_VERSION != ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (ICU_IPW_CFG_SW_MINOR_VERSION != ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (ICU_IPW_CFG_SW_PATCH_VERSION != ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Cfg.h and Icu_Ipw_MBDT_PBcfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ICU_IPW_CFG_H */

