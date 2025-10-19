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

#ifndef RM_IPW_MBDT_PBCFG_H
#define RM_IPW_MBDT_PBCFG_H

/**
*   @file CDD_Rm_Ipw_PBcfg.h
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
#include "Xrdc_Ip.h"
#include "Pflash_Ip.h"
#include "Axbs_Ip.h"
#include "Virt_Wrapper_Ip.h"
#include "Xbic_Ip.h"
#include "Dma_Mux_Ip.h"
#include "Mscm_Ip.h"
#include "Sema42_Ip.h"
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_PBCFG_MBDT_VENDOR_ID                     43
#define RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION      4
#define RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION      7
#define RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION   0
#define RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION              5
#define RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION              0
#define RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION              0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xrdc_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_XRDC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Xrdc_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Xrdc_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_XRDC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_XRDC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_XRDC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Xrdc_Ip.h are different"
#endif

/* Checks against Pflash_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_PFLASH_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Pflash_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_PFLASH_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_PFLASH_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_PFLASH_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Pflash_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_PFLASH_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_PFLASH_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_PFLASH_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Pflash_Ip.h are different"
#endif

/* Checks against Axbs_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_AXBS_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Axbs_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Axbs_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_AXBS_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_AXBS_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_AXBS_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Axbs_Ip.h are different"
#endif

/* Checks against Virt_Wrapper_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_VIRT_WRAPPER_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Virt_Wrapper_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Virt_Wrapper_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Virt_Wrapper_Ip.h are different"
#endif

/* Checks against Xbic_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_XBIC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Xbic_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Xbic_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_XBIC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_XBIC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_XBIC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Xbic_Ip.h are different"
#endif

/* Checks against Dma_Mux_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_DMA_MUX_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Dma_Mux_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Dma_Mux_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_DMA_MUX_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_DMA_MUX_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_DMA_MUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Dma_Mux_Ip.h are different"
#endif

/* Checks against Mscm_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_MSCM_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Mscm_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Mscm_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_MSCM_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_MSCM_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_MSCM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Mscm_Ip.h are different"
#endif

/* Checks against Sema42_Ip.h */
#if (RM_IPW_PBCFG_MBDT_VENDOR_ID != RM_SEMA42_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_MBDT_PBcfg.h and Sema42_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_MBDT_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Sema42_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_MBDT_SW_MAJOR_VERSION != RM_SEMA42_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_MINOR_VERSION != RM_SEMA42_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_MBDT_SW_PATCH_VERSION != RM_SEMA42_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_MBDT_PBcfg.h and Sema42_Ip.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define RM_IPW_CONFIG_MBDT_PB \
    extern const Rm_Ipw_ConfigType Rm_Ipw_Config_MBDT;

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

#endif /* RM_IPW_MBDT_PBCFG_H */

