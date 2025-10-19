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
#ifndef CACHE_IP_HWACC_ARMCOREMX_H_
#define CACHE_IP_HWACC_ARMCOREMX_H_

/**
*   @file    Cache_Ip_HwAcc_ArmCoreMx.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Cache Ip driver header file.
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
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cache_Ip.h"
#include "Cache_Ip_Devassert.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID                       43
#define CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION        4
#define CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION        7
#define CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION     0
#define CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION                5
#define CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION                0
#define CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Cache_Ip.h file are of the same vendor */
#if (CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID != CACHE_IP_VENDOR_ID)
    #error "Cache_Ip_HwAcc_ArmCoreMx.h and Cache_Ip.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip.h file are of the same Autosar version */
#if ((CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION != CACHE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION != CACHE_IP_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION != CACHE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_HwAcc_ArmCoreMx.h and Cache_Ip.h are different"
#endif

/* Check if header file and Cache_Ip.h file are of the same Software version */
#if ((CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION != CACHE_IP_SW_MAJOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION != CACHE_IP_SW_MINOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION != CACHE_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_HwAcc_ArmCoreMx.h and Cache_Ip.h are different"
#endif

/* Check if header file and Cache_Ip_Devassert.h file are of the same vendor */
#if (CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID != CACHE_IP_DEVASSERT_VENDOR_ID)
    #error "Cache_Ip_HwAcc_ArmCoreMx.h and Cache_Ip_Devassert.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip_Devassert.h file are of the same Autosar version */
#if ((CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION != CACHE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION != CACHE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION != CACHE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip_HwAcc_ArmCoreMx.h and Cache_Ip_Devassert.h are different"
#endif

/* Check if header file and Cache_Ip_Devassert.h file are of the same Software version */
#if ((CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION != CACHE_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION != CACHE_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION != CACHE_IP_DEVASSERT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip_HwAcc_ArmCoreMx.h and Cache_Ip_Devassert.h are different"
#endif


#if (STD_ON == CACHE_IP_IS_AVAILABLE)

#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
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
void hwAcc_ArmCoreMx_InstructionCacheInvalidate(void);
void hwAcc_ArmCoreMx_DataCacheInvalidate(void);
void hwAcc_ArmCoreMx_InstructionCacheClean(const boolean enInvalidate);
void hwAcc_ArmCoreMx_DataCacheClean(const boolean enInvalidate);
void hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr(const uint32 addr, const uint32 length);
void hwAcc_ArmCoreMx_DataCacheInvalidateByAddr(const uint32 addr, const uint32 length);
void hwAcc_ArmCoreMx_InstructionCacheCleanByAddr(const boolean enInvalidate, const uint32 addr, const uint32 length);
void hwAcc_ArmCoreMx_DataCacheCleanByAddr(const boolean enInvalidate, const uint32 addr, const uint32 length);
void hwAcc_ArmCoreMx_InstructionCacheEnable(void);
void hwAcc_ArmCoreMx_DataCacheEnable(void);
void hwAcc_ArmCoreMx_InstructionCacheDisable(void);
void hwAcc_ArmCoreMx_DataCacheDisable(void);


#endif /* #if (CACHE_IP_ARMCOREMX_IS_AVAILABLE == STD_ON) */

#endif /* #if (CACHE_IP_IS_AVAILABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef CACHE_IP_HWACC_ARMCOREMX_H_ */
