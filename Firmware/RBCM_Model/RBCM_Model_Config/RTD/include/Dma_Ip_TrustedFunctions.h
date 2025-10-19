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
/* Prevention from multiple including the same header */
#ifndef DMA_IP_TRUSTEDFUNCTIONS_H
#define DMA_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Dma_Ip_TrustedFunctions.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver source file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Cfg_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                5
#define DMA_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define DMA_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_TrustedFunctions.h file and Dma_Ip_Cfg_Defines file are of the same Software version */
#if (DMA_IP_TRUSTEDFUNCTIONS_VENDOR_ID != DMA_IP_CFG_DEFINES_VENDOR_ID)
    #error "Dma_Ip_TrustedFunctions.h and Dma_Ip_Cfg_Defines have different vendor ids"
#endif


/* Check if Dma_Ip_TrustedFunctions.h file and Dma_Ip_Cfg_Defines file are of the same Autosar version */
#if ((DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_TrustedFunctions.h and Dma_Ip_Cfg_Defines are different"
#endif

/* Check if Dma_Ip_TrustedFunctions.h file and Dma_Ip_Cfg_Defines file are of the same Software version */
#if ((DMA_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (DMA_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != DMA_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (DMA_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != DMA_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_TrustedFunctions.h and Dma_Ip_Cfg_Defines are different"
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

#if (STD_ON == DMA_IP_IS_AVAILABLE)

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == DMA_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
#if (STD_ON == DMA_IP_REG_PROT_AVAILABLE)

#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/**
 * @brief        Allow access to registers in user modes
 *
 * @param[in]    address         Specifies the memory segment start address.
 * @return       None
 *
 */
extern void Mcl_Dma_SetUserAccessAllowed(uint32 address);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* DMA_IP_REG_PROT_AVAILABLE */
#endif /* (STD_ON == DMA_IP_USER_MODE_SUPPORT_IS_AVAILABLE) */
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

#endif /* STD_ON == DMA_IP_IS_AVAILABLE */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_IP_TRUSTEDFUNCTIONS_H */


/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
