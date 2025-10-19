/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_MCL_IP_CFG_H_
#define EMIOS_MCL_IP_CFG_H_
/**
*   @file Emios_Mcl_Ip_Cfg.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details 
*
*   @addtogroup MCL_DRIVER MCL Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Include all variants header files. */
#include "Emios_Mcl_Ip_MBDT_PBcfg.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_CFG_VENDOR_ID                       43
#define EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION                5
#define EMIOS_MCL_IP_CFG_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_CFG_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Emios_Mcl_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (EMIOS_MCL_IP_CFG_VENDOR_ID != EMIOS_MCL_IP_MBDT_PBCFG_VENDOR_ID)
    #error "Emios_Mcl_Ip_Cfg.h and Emios_Mcl_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Emios_Mcl_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg.h and Emios_Mcl_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION != EMIOS_MCL_IP_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_SW_MINOR_VERSION != EMIOS_MCL_IP_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_SW_PATCH_VERSION != EMIOS_MCL_IP_MBDT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Emios_Mcl_Ip_Cfg.h and Emios_Mcl_Ip_MBDT_PBcfg.h are different"
#endif
    
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Enable/Disable EMIOS support from MCL. */
#define EMIOS_IP_IS_AVAILABLE                      STD_ON

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

#endif /* EMIOS_MCL_IP_CFG_H_ */

