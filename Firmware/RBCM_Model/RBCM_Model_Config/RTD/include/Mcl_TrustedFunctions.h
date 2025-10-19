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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MCL_TRUSTEDFUNCTIONS_H
#define MCL_TRUSTEDFUNCTIONS_H

/**
*   @file    MCL_TrustedFunctions.h
*
*   @version    5.0.0
*
*   @brief   AUTOSAR Mcl - Mcl driver header file.
*   @details AUTOSAR specific Mcl driver header file.

*   @addtogroup MCL_DRIVER Mcl Driver
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
#include "Dma_Ip_TrustedFunctions.h"
#include "Cache_Ip_TrustedFunctions.h"
#include "Trgmux_Ip_TrustedFunctions.h"


/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_TRUSTEDFUNCTIONS_VENDOR_ID                     43
#define MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION      4
#define MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION      7
#define MCL_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   0
#define MCL_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION              5
#define MCL_TRUSTEDFUNCTIONS_SW_MINOR_VERSION              0
#define MCL_TRUSTEDFUNCTIONS_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if MCL_TrustedFunctions.h file and Dma_Ip_TrustedFunctions.h file are of the same vendor */
#if (MCL_TRUSTEDFUNCTIONS_VENDOR_ID != DMA_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Mcl_TrustedFunctions.h and Dma_Ip_TrustedFunctions.h have different vendor ids"
#endif

/* Check if MCL_TrustedFunctions.h file and Dma_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MCL_TrustedFunctions.h and Dma_Ip_TrustedFunctions.h are different"
#endif

/* Check if MCL_TrustedFunctions.h file and Dma_Ip_TrustedFunctions.h file are of the same Software version */
#if ((MCL_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != DMA_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != DMA_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != DMA_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MCL_TrustedFunctions.h and Dma_Ip_TrustedFunctions.h are different"
#endif

/* Check if MCL_TrustedFunctions.h file and Cache_Ip_TrustedFunctions.h file are of the same vendor */
#if (MCL_TRUSTEDFUNCTIONS_VENDOR_ID != CACHE_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Mcl_TrustedFunctions.h and Cache_Ip_TrustedFunctions.h have different vendor ids"
#endif

/* Check if MCL_TrustedFunctions.h file and Cache_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MCL_TrustedFunctions.h and Cache_Ip_TrustedFunctions.h are different"
#endif

/* Check if MCL_TrustedFunctions.h file and Cache_Ip_TrustedFunctions.h file are of the same Software version */
#if ((MCL_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CACHE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CACHE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CACHE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MCL_TrustedFunctions.h and Cache_Ip_TrustedFunctions.h are different"
#endif

/* Check if MCL_TrustedFunctions.h file and Trgmux_Ip_TrustedFunctions.h file are of the same vendor */
#if (MCL_TRUSTEDFUNCTIONS_VENDOR_ID != TRGMUX_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Mcl_TrustedFunctions.h and Trgmux_Ip_TrustedFunctions.h have different vendor ids"
#endif

/* Check if MCL_TrustedFunctions.h file and Trgmux_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MCL_TrustedFunctions.h and Trgmux_Ip_TrustedFunctions.h are different"
#endif

/* Check if MCL_TrustedFunctions.h file and Trgmux_Ip_TrustedFunctions.h file are of the same Software version */
#if ((MCL_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (MCL_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != TRGMUX_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MCL_TrustedFunctions.h and Trgmux_Ip_TrustedFunctions.h are different"
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
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* MCL_TRUSTEDFUNCTIONS_H */
