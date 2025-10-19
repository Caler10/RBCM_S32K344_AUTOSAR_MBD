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
#ifndef CACHE_IP_TRUSTEDFUNCTIONS_H
#define CACHE_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Cache_Ip_TrustedFunctions.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Cache Ip driver source file.
*   @details
*
*   @addtogroup CACHE_IP_DRIVER CACHE IP Driver
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
#include "Cache_Ip_Cfg_Defines.h"
#if (STD_ON == CACHE_IP_IS_AVAILABLE)
#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
#include "Cache_Ip_HwAcc_ArmCoreMx.h"
#endif /* (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) */
#if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE)
#include "Cache_Ip_HwAcc_ArmCoreRx.h"
#endif /* (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE) */
#if (STD_ON == CACHE_IP_ALL_IS_AVAILABLE)
#include "Cache_Ip_HwAcc_Lmem.h"
#endif /* (STD_ON == CACHE_IP_ALL_IS_AVAILABLE) */
#endif /* (STD_ON == CACHE_IP_IS_AVAILABLE) */
#if (STD_ON == CACHE_IP_ALL_IS_AVAILABLE)
#include "Std_Types.h"
#endif /* STD_ON == CACHE_IP_ALL_IS_AVAILABLE */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CACHE_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define CACHE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                5
#define CACHE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define CACHE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_Cfg_Defines file are of the same Software version */
#if (CACHE_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CACHE_IP_CFG_DEFINES_VENDOR_ID)
    #error "Cache_Ip_TrustedFunctions.h and Cache_Ip_Cfg_Defines have different vendor ids"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_Cfg_Defines file are of the same Autosar version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_Cfg_Defines are different"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_Cfg_Defines file are of the same Software version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CACHE_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_Cfg_Defines are different"
#endif

#if (STD_ON == CACHE_IP_IS_AVAILABLE)
#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_ArmCoreMx file are of the same Software version */
#if (CACHE_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID)
    #error "Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_ArmCoreMx have different vendor ids"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_ArmCoreMx file are of the same Autosar version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_ArmCoreMx are different"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_ArmCoreMx file are of the same Software version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_ArmCoreMx are different"
#endif
#endif /* (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) */

#if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE)
/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_ArmCoreRx file are of the same Software version */
#if (CACHE_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CACHE_IP_HWACC_ARMCORERX_VENDOR_ID)
    #error "Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_ArmCoreRx have different vendor ids"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_ArmCoreRx file are of the same Autosar version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != CACHE_IP_HWACC_ARMCORERX_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != CACHE_IP_HWACC_ARMCORERX_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CACHE_IP_HWACC_ARMCORERX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_ArmCoreRx are different"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_ArmCoreRx file are of the same Software version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CACHE_IP_HWACC_ARMCORERX_SW_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CACHE_IP_HWACC_ARMCORERX_SW_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CACHE_IP_HWACC_ARMCORERX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_ArmCoreRx are different"
#endif
#endif /* (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE) */
#if (STD_ON == CACHE_IP_ALL_IS_AVAILABLE)
/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_Lmem file are of the same Software version */
#if (CACHE_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CACHE_IP_HWACC_LMEM_VENDOR_ID)
    #error "Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_Lmem have different vendor ids"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_Lmem file are of the same Autosar version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != CACHE_IP_HWACC_LMEM_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != CACHE_IP_HWACC_LMEM_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CACHE_IP_HWACC_LMEM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_Lmem are different"
#endif

/* Check if Cache_Ip_TrustedFunctions.h file and Cache_Ip_HwAcc_Lmem file are of the same Software version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CACHE_IP_HWACC_LMEM_SW_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CACHE_IP_HWACC_LMEM_SW_MINOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CACHE_IP_HWACC_LMEM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_TrustedFunctions.h and Cache_Ip_HwAcc_Lmem are different"
#endif
#endif /* (STD_ON == CACHE_IP_ALL_IS_AVAILABLE) */
#endif /* (STD_ON == CACHE_IP_IS_AVAILABLE) */


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

#if (STD_ON == CACHE_IP_ALL_IS_AVAILABLE)

/* Check if header Std_Types file and Cache_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Std_Types.h and Cache_Ip_TrustedFunctions.h are different"
#endif

#endif /* STD_ON == CACHE_IP_ALL_IS_AVAILABLE */

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

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CACHE_IP_TRUSTEDFUNCTIONS_H */


/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
