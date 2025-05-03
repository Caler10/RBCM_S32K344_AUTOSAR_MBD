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

/**
*   @file    Cache_Ip.c
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
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cache_Ip.h"
#include "Cache_Ip_Devassert.h"
#include "SchM_Mcl.h"

#if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE)
#include "Cache_Ip_HwAcc_ArmCoreRx.h"
#endif /* #if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE) */

#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
#include "Cache_Ip_HwAcc_ArmCoreMx.h"
#endif /* #if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) */

#if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
#include "Cache_Ip_HwAcc_Lmem.h"
#endif /* #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CACHE_IP_VENDOR_ID_C                       43
#define CACHE_IP_AR_RELEASE_MAJOR_VERSION_C        4
#define CACHE_IP_AR_RELEASE_MINOR_VERSION_C        7
#define CACHE_IP_AR_RELEASE_REVISION_VERSION_C     0
#define CACHE_IP_SW_MAJOR_VERSION_C                5
#define CACHE_IP_SW_MINOR_VERSION_C                0
#define CACHE_IP_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Cache_Ip.c file and Cache_Ip.h file are of the same vendor */
#if (CACHE_IP_VENDOR_ID_C != CACHE_IP_VENDOR_ID)
    #error "Cache_Ip.c and Cache_Ip.h have different vendor ids"
#endif

/* Check if Cache_Ip.c file and Cache_Ip.h file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_REVISION_VERSION_C != CACHE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip.c and Cache_Ip.h are different"
#endif

/* Check if Cache_Ip.c file and Cache_Ip.h file are of the same Software version */
#if ((CACHE_IP_SW_MAJOR_VERSION_C != CACHE_IP_SW_MAJOR_VERSION) || \
     (CACHE_IP_SW_MINOR_VERSION_C != CACHE_IP_SW_MINOR_VERSION) || \
     (CACHE_IP_SW_PATCH_VERSION_C != CACHE_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip.c and Cache_Ip.h are different"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_Devassert.h file are of the same vendor */
#if (CACHE_IP_VENDOR_ID_C != CACHE_IP_DEVASSERT_VENDOR_ID)
    #error "Cache_Ip.c and Cache_Ip_Devassert.h have different vendor ids"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_Devassert.h file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_REVISION_VERSION_C != CACHE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip.c and Cache_Ip_Devassert.h are different"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_Devassert.h file are of the same Software version */
#if ((CACHE_IP_SW_MAJOR_VERSION_C != CACHE_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (CACHE_IP_SW_MINOR_VERSION_C != CACHE_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (CACHE_IP_SW_PATCH_VERSION_C != CACHE_IP_DEVASSERT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip.c and Cache_Ip_Devassert.h are different"
#endif

#if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE)
/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_ArmCoreRx.h file are of the same vendor */
#if (CACHE_IP_VENDOR_ID_C != CACHE_IP_HWACC_ARMCORERX_VENDOR_ID)
    #error "Cache_Ip.c and Cache_Ip_HwAcc_ArmCoreRx.h have different vendor ids"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_ArmCoreRx.h file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_HWACC_ARMCORERX_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_HWACC_ARMCORERX_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_REVISION_VERSION_C != CACHE_IP_HWACC_ARMCORERX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip.c and Cache_Ip_HwAcc_ArmCoreRx.h are different"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_ArmCoreRx.h file are of the same Software version */
#if ((CACHE_IP_SW_MAJOR_VERSION_C != CACHE_IP_HWACC_ARMCORERX_SW_MAJOR_VERSION) || \
     (CACHE_IP_SW_MINOR_VERSION_C != CACHE_IP_HWACC_ARMCORERX_SW_MINOR_VERSION) || \
     (CACHE_IP_SW_PATCH_VERSION_C != CACHE_IP_HWACC_ARMCORERX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip.c and Cache_Ip_HwAcc_ArmCoreRx.h are different"
#endif
#endif /* #if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE) */

#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_ArmCoreMx.h file are of the same vendor */
#if (CACHE_IP_VENDOR_ID_C != CACHE_IP_HWACC_ARMCOREMX_VENDOR_ID)
    #error "Cache_Ip.c and Cache_Ip_HwAcc_ArmCoreMx.h have different vendor ids"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_ArmCoreMx.h file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_REVISION_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip.c and Cache_Ip_HwAcc_ArmCoreMx.h are different"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_ArmCoreMx.h file are of the same Software version */
#if ((CACHE_IP_SW_MAJOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_SW_MAJOR_VERSION) || \
     (CACHE_IP_SW_MINOR_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_SW_MINOR_VERSION) || \
     (CACHE_IP_SW_PATCH_VERSION_C != CACHE_IP_HWACC_ARMCOREMX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip.c and Cache_Ip_HwAcc_ArmCoreMx.h are different"
#endif
#endif /* #if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) */

#if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_Lmem.h file are of the same vendor */
#if (CACHE_IP_VENDOR_ID_C != CACHE_IP_HWACC_LMEM_VENDOR_ID)
    #error "Cache_Ip.c and Cache_Ip_HwAcc_Lmem.h have different vendor ids"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_Lmem.h file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_HWACC_LMEM_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_HWACC_LMEM_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_REVISION_VERSION_C != CACHE_IP_HWACC_LMEM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip.c and Cache_Ip_HwAcc_Lmem.h are different"
#endif

/* Check if Cache_Ip.c file and Cache_Ip_HwAcc_Lmem.h file are of the same Software version */
#if ((CACHE_IP_SW_MAJOR_VERSION_C != CACHE_IP_HWACC_LMEM_SW_MAJOR_VERSION) || \
     (CACHE_IP_SW_MINOR_VERSION_C != CACHE_IP_HWACC_LMEM_SW_MINOR_VERSION) || \
     (CACHE_IP_SW_PATCH_VERSION_C != CACHE_IP_HWACC_LMEM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip.c and Cache_Ip_HwAcc_Lmem.h are different"
#endif
#endif /* #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE) */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Cache_Ip.c file and SchM_Mcl header file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_MCL_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_MCL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Cache_Ip.c and SchM_Mcl.h are different"
#endif
#endif

#if (STD_ON == CACHE_IP_IS_AVAILABLE)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
#if (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE))
        #define Cache_Ip_Enable_InstructionCache()        (OsIf_Trusted_Call(hwAcc_ArmCoreMx_InstructionCacheEnable))
        #define Cache_Ip_Enable_DataCache()               (OsIf_Trusted_Call(hwAcc_ArmCoreMx_DataCacheEnable))
        #define Cache_Ip_Disable_InstructionCache()       (OsIf_Trusted_Call(hwAcc_ArmCoreMx_InstructionCacheDisable))
        #define Cache_Ip_Disable_DataCache()              (OsIf_Trusted_Call(hwAcc_ArmCoreMx_DataCacheDisable))
        #define Cache_Ip_Invalidate_InstructionCache()    (OsIf_Trusted_Call(hwAcc_ArmCoreMx_InstructionCacheInvalidate))
        #define Cache_Ip_Invalidate_DataCache()           (OsIf_Trusted_Call(hwAcc_ArmCoreMx_DataCacheInvalidate))
        #define Cache_Ip_Clean_InstructionCache(enInvalidate) \
                (OsIf_Trusted_Call1param(hwAcc_ArmCoreMx_InstructionCacheClean, enInvalidate))
        #define Cache_Ip_Clean_DataCache(enInvalidate)        \
                (OsIf_Trusted_Call1param(hwAcc_ArmCoreMx_DataCacheClean, enInvalidate))
        #define Cache_Ip_Invalidate_InstructionCacheByAddr(addr, length) \
                (OsIf_Trusted_Call2params(hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr, addr, length))
        #define Cache_Ip_Invalidate_DataCacheByAddr(addr, length)        \
                (OsIf_Trusted_Call2params(hwAcc_ArmCoreMx_DataCacheInvalidateByAddr, addr, length))
        #define Cache_Ip_Clean_InstructionCacheByAddr(enInvalidate, addr, length) \
                (OsIf_Trusted_Call3params(hwAcc_ArmCoreMx_InstructionCacheCleanByAddr, enInvalidate, addr, length))
        #define Cache_Ip_Clean_DataCacheByAddr(enInvalidate, addr, length)        \
                (OsIf_Trusted_Call3params(hwAcc_ArmCoreMx_DataCacheCleanByAddr, enInvalidate, addr, length))
    #else
        #define Cache_Ip_Enable_InstructionCache()        (hwAcc_ArmCoreMx_InstructionCacheEnable())
        #define Cache_Ip_Enable_DataCache()               (hwAcc_ArmCoreMx_DataCacheEnable())
        #define Cache_Ip_Disable_InstructionCache()       (hwAcc_ArmCoreMx_InstructionCacheDisable())
        #define Cache_Ip_Disable_DataCache()              (hwAcc_ArmCoreMx_DataCacheDisable())
        #define Cache_Ip_Invalidate_InstructionCache()    (hwAcc_ArmCoreMx_InstructionCacheInvalidate())
        #define Cache_Ip_Invalidate_DataCache()           (hwAcc_ArmCoreMx_DataCacheInvalidate())
        #define Cache_Ip_Clean_InstructionCache(enInvalidate) \
                (hwAcc_ArmCoreMx_InstructionCacheClean(enInvalidate))
        #define Cache_Ip_Clean_DataCache(enInvalidate)        \
                (hwAcc_ArmCoreMx_DataCacheClean(enInvalidate))
        #define Cache_Ip_Invalidate_InstructionCacheByAddr(addr, length) \
                (hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr(addr, length))
        #define Cache_Ip_Invalidate_DataCacheByAddr(addr, length)        \
                (hwAcc_ArmCoreMx_DataCacheInvalidateByAddr(addr, length))
        #define Cache_Ip_Clean_InstructionCacheByAddr(enInvalidate, addr, length) \
                (hwAcc_ArmCoreMx_InstructionCacheCleanByAddr(enInvalidate, addr, length))
        #define Cache_Ip_Clean_DataCacheByAddr(enInvalidate, addr, length)        \
                (hwAcc_ArmCoreMx_DataCacheCleanByAddr(enInvalidate, addr, length))
    #endif /* MCAL_ENABLE_USER_MODE_SUPPORT && STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE */
#endif /* #if (CACHE_IP_ARMCOREMX_IS_AVAILABLE == STD_ON) */

#if (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE)
#if (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE))
        #define Cache_Ip_Enable_InstructionCache()        (OsIf_Trusted_Call(hwAcc_ArmCoreRx_InstructionCacheEnable))
        #define Cache_Ip_Enable_DataCache()               (OsIf_Trusted_Call(hwAcc_ArmCoreRx_DataCacheEnable))
        #define Cache_Ip_Disable_InstructionCache()       (OsIf_Trusted_Call(hwAcc_ArmCoreRx_InstructionCacheDisable))
        #define Cache_Ip_Disable_DataCache()              (OsIf_Trusted_Call(hwAcc_ArmCoreRx_DataCacheDisable))
        #define Cache_Ip_Invalidate_InstructionCache()    (OsIf_Trusted_Call(hwAcc_ArmCoreRx_InstructionCacheInvalidate))
        #define Cache_Ip_Invalidate_DataCache()           (OsIf_Trusted_Call(hwAcc_ArmCoreRx_DataCacheInvalidate))
        #define Cache_Ip_Clean_InstructionCache(enInvalidate) \
                (OsIf_Trusted_Call1param(hwAcc_ArmCoreRx_InstructionCacheClean, enInvalidate))
        #define Cache_Ip_Clean_DataCache(enInvalidate)        \
                (OsIf_Trusted_Call1param(hwAcc_ArmCoreRx_DataCacheClean, enInvalidate))
        #define Cache_Ip_Invalidate_InstructionCacheByAddr(addr, length) \
                (OsIf_Trusted_Call2params(hwAcc_ArmCoreRx_InstructionCacheInvalidateByAddr, addr, length))
        #define Cache_Ip_Invalidate_DataCacheByAddr(addr, length)        \
                (OsIf_Trusted_Call2params(hwAcc_ArmCoreRx_DataCacheInvalidateByAddr, addr, length))
        #define Cache_Ip_Clean_InstructionCacheByAddr(enInvalidate, addr, length) \
                (OsIf_Trusted_Call3params(hwAcc_ArmCoreRx_InstructionCacheCleanByAddr, enInvalidate, addr, length))
        #define Cache_Ip_Clean_DataCacheByAddr(enInvalidate, addr, length)        \
                (OsIf_Trusted_Call3params(hwAcc_ArmCoreRx_DataCacheCleanByAddr, enInvalidate, addr, length))
#else
        #define Cache_Ip_Enable_InstructionCache()        (hwAcc_ArmCoreRx_InstructionCacheEnable())
        #define Cache_Ip_Enable_DataCache()               (hwAcc_ArmCoreRx_DataCacheEnable())
        #define Cache_Ip_Disable_InstructionCache()       (hwAcc_ArmCoreRx_InstructionCacheDisable())
        #define Cache_Ip_Disable_DataCache()              (hwAcc_ArmCoreRx_DataCacheDisable())
        #define Cache_Ip_Invalidate_InstructionCache()    (hwAcc_ArmCoreRx_InstructionCacheInvalidate())
        #define Cache_Ip_Invalidate_DataCache()           (hwAcc_ArmCoreRx_DataCacheInvalidate())
        #define Cache_Ip_Clean_InstructionCache(enInvalidate) \
                (hwAcc_ArmCoreRx_InstructionCacheClean(enInvalidate))
        #define Cache_Ip_Clean_DataCache(enInvalidate)        \
                (hwAcc_ArmCoreRx_DataCacheClean(enInvalidate))
        #define Cache_Ip_Invalidate_InstructionCacheByAddr(addr, length) \
                (hwAcc_ArmCoreRx_InstructionCacheInvalidateByAddr(addr, length))
        #define Cache_Ip_Invalidate_DataCacheByAddr(addr, length)        \
                (hwAcc_ArmCoreRx_DataCacheInvalidateByAddr(addr, length))
        #define Cache_Ip_Clean_InstructionCacheByAddr(enInvalidate, addr, length) \
                (hwAcc_ArmCoreRx_InstructionCacheCleanByAddr(enInvalidate, addr, length))
        #define Cache_Ip_Clean_DataCacheByAddr(enInvalidate, addr, length)        \
                (hwAcc_ArmCoreRx_DataCacheCleanByAddr(enInvalidate, addr, length))
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT && STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE */
#endif /* #if (CACHE_IP_ARMCORERX_IS_AVAILABLE == STD_ON) */


#if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
#if (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE))

            #define Cache_Ip_Enable_AllCache(BusType)                                   (OsIf_Trusted_Call_Return1param(hwAcc_Lmem_Enable, BusType))
            #define Cache_Ip_Disable_AllCache(BusType)                                  (OsIf_Trusted_Call_Return1param(hwAcc_Lmem_Disable, BusType))
            #define Cache_Ip_Invalidate_AllCache(BusType)                               (OsIf_Trusted_Call_Return1param(hwAcc_Lmem_Invalidate, BusType))
            #define Cache_Ip_Clean_AllCache(BusType, enInvalidate)                      (OsIf_Trusted_Call_Return2param(hwAcc_Lmem_Clean, BusType, enInvalidate))
            #define Cache_Ip_Invalidate_AllCacheByAddr(BusType, addr, length)           (OsIf_Trusted_Call_Return3param(hwAcc_Lmem_InvalidateByAddr, BusType, addr, length))
            #define Cache_Ip_Clean_AllCacheByAddr(BusType, enInvalidate, addr, length)  (OsIf_Trusted_Call_Return4param(hwAcc_Lmem_CleanByAddr, BusType, enInvalidate, addr, length))
#else
            #define Cache_Ip_Enable_AllCache(BusType)                                   (hwAcc_Lmem_Enable(BusType))
            #define Cache_Ip_Disable_AllCache(BusType)                                  (hwAcc_Lmem_Disable(BusType))
            #define Cache_Ip_Invalidate_AllCache(BusType)                               (hwAcc_Lmem_Invalidate(BusType))
            #define Cache_Ip_Clean_AllCache(BusType, enInvalidate)                      (hwAcc_Lmem_Clean(BusType, enInvalidate))
            #define Cache_Ip_Invalidate_AllCacheByAddr(BusType, addr, length)           (hwAcc_Lmem_InvalidateByAddr(BusType, addr, length))
            #define Cache_Ip_Clean_AllCacheByAddr(BusType, enInvalidate, addr, length)  (hwAcc_Lmem_CleanByAddr(BusType, enInvalidate, addr, length))
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT && STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE */
#endif /* CACHE_IP_LMEM_IS_AVAILABLE */


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"


/***************************************************************************************************
* @brief        The function enables the specified cache.
*
* @param[in]    CacheType - cache type
* @param[in]    BusType   - Specifies the bus type.
***************************************************************************************************/
Std_ReturnType Cache_Ip_Enable(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType)
{
    Std_ReturnType Status = E_OK;

    /* Enter exclusive area to protect S32_SCB_CCR */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13();
    switch(CacheType)
    {
        #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
        case CACHE_IP_LMEM:{
            #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
                    Status = ((Cache_Ip_Enable_AllCache((uint8)BusType) == 0x00000000U) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
                #else
                    Status = Cache_Ip_Enable_AllCache((uint8)BusType);
                #endif
            #else
                Status = Cache_Ip_Enable_AllCache((uint8)BusType);
            #endif
        break;}
        #endif /* CACHE_IP_LMEM_IS_AVAILABLE */
        #if ((STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) || (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE))
        case CACHE_IP_CORE:{
            if (BusType == CACHE_IP_INSTRUCTION)
            {
                Cache_Ip_Enable_InstructionCache();
            }
            else if (BusType == CACHE_IP_DATA)
            {
                Cache_Ip_Enable_DataCache();
            }
            else
            {
                CACHE_IP_DEV_ASSERT(FALSE);
            }
        break;}
        #endif /* CACHE_IP_ARMCOREMX_IS_AVAILABLE || CACHE_IP_ARMCORERX_IS_AVAILABLE */
        default:{
            CACHE_IP_DEV_ASSERT(FALSE);
        break;}
    }
    /* Exit exclusive area to protect S32_SCB_CCR */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13();

    return Status;
}

/***************************************************************************************************
* @brief        The function disables the specified cache.
*
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
***************************************************************************************************/
Std_ReturnType Cache_Ip_Disable(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType)
{
    Std_ReturnType Status = E_OK;

    /* Enter exclusive area to protect S32_SCB_CCR */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14();
    switch(CacheType)
    {
        #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
        case CACHE_IP_LMEM:{
            #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
                    Status = ((Cache_Ip_Disable_AllCache((uint8)BusType) == 0x00000000U) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
                #else
                    Status = Cache_Ip_Disable_AllCache((uint8)BusType);
                #endif
            #else
                Status = Cache_Ip_Disable_AllCache((uint8)BusType);
            #endif
        break;}
        #endif /* CACHE_IP_LMEM_IS_AVAILABLE */
        #if ((STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) || (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE))
        case CACHE_IP_CORE:{
            if (BusType == CACHE_IP_INSTRUCTION)
            {
                Cache_Ip_Disable_InstructionCache();
            }
            else if (BusType == CACHE_IP_DATA)
            {
                Cache_Ip_Disable_DataCache();
            }
            else
            {
                CACHE_IP_DEV_ASSERT(FALSE);
            }
        break;}
        #endif /* CACHE_IP_ARMCOREMX_IS_AVAILABLE || CACHE_IP_ARMCORERX_IS_AVAILABLE */
        default:{
            CACHE_IP_DEV_ASSERT(FALSE);
        break;}
    }
    /* Exit exclusive area to protect S32_SCB_CCR */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14();

    return Status;
}


/***************************************************************************************************
* @brief        The function invalidates the specified cache.
* @details      The cache is invalidated by using set and way.
*
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
***************************************************************************************************/
Std_ReturnType Cache_Ip_Invalidate(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType)
{
    Std_ReturnType Status = E_OK;
    
    /* Enter exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIALLU */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15();
    switch(CacheType)
    {
        #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
        case CACHE_IP_LMEM:{
            #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
                    Status = ((Cache_Ip_Invalidate_AllCache((uint8)BusType) == 0x00000000U) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
                #else
                    Status = Cache_Ip_Invalidate_AllCache((uint8)BusType);
                #endif
            #else
                Status = Cache_Ip_Invalidate_AllCache((uint8)BusType);
            #endif
        break;}
        #endif /* CACHE_IP_LMEM_IS_AVAILABLE */
        #if ((STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) || (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE))
        case CACHE_IP_CORE:{
            if (BusType == CACHE_IP_INSTRUCTION)
            {
                Cache_Ip_Invalidate_InstructionCache();
            }
            else if (BusType == CACHE_IP_DATA)
            {
                Cache_Ip_Invalidate_DataCache();
            }
            else
            {
                CACHE_IP_DEV_ASSERT(FALSE);
            }
        break;}
        #endif /* CACHE_IP_ARMCOREMX_IS_AVAILABLE || CACHE_IP_ARMCORERX_IS_AVAILABLE */
        default:{
            CACHE_IP_DEV_ASSERT(FALSE);
        break;}
    }
    /* Exit exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIALLU */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15();

    return Status;
}


/***************************************************************************************************
* @brief        The function cleans the specified cache.
* @details      The cache is cleaned by using set and way.
*
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 * @param[in]  enInvalidate      Specifies to execute operation Clean&Invalidate.
****************************************************************************************************/
Std_ReturnType Cache_Ip_Clean(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const boolean EnInvalidate)
{
    Std_ReturnType Status = E_OK;

    /* Enter exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIALLU */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16();
    switch(CacheType)
    {
        #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
        case CACHE_IP_LMEM:{
            #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
                    Status = ((Cache_Ip_Clean_AllCache((uint8)BusType, EnInvalidate) == 0x00000000U) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
                #else
                    Status = Cache_Ip_Clean_AllCache((uint8)BusType, EnInvalidate);
                #endif
            #else
                Status = Cache_Ip_Clean_AllCache(BusType, EnInvalidate);
            #endif
        break;}
        #endif /* CACHE_IP_LMEM_IS_AVAILABLE */
        #if ((STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) || (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE))
        case CACHE_IP_CORE:{
            if (BusType == CACHE_IP_INSTRUCTION)
            {
                Cache_Ip_Clean_InstructionCache(EnInvalidate);
            }
            else if (BusType == CACHE_IP_DATA)
            {
                Cache_Ip_Clean_DataCache(EnInvalidate);
            }
            else
            {
                CACHE_IP_DEV_ASSERT(FALSE);
            }
        break;}
        #endif /* CACHE_IP_ARMCOREMX_IS_AVAILABLE || CACHE_IP_ARMCORERX_IS_AVAILABLE */
        default:{
            CACHE_IP_DEV_ASSERT(FALSE);
        break;}
    }
    /* Exit exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIALLU */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16();

    return Status;
}


/***************************************************************************************************
* @brief        The function invalidates by address the specified cache.
*
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 * @param[in]  Addr              Specifies the memory segment start address.
 * @param[in]  Length            Specifies the memory segment length.
***************************************************************************************************/
Std_ReturnType Cache_Ip_InvalidateByAddr(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const uint32 Addr, const uint32 Length)
{
    Std_ReturnType Status = E_OK;

    /* Enter exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIMVAU */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17();
    switch(CacheType)
    {
        #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
        case CACHE_IP_LMEM:{
            #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
                    Status = ((Cache_Ip_Invalidate_AllCacheByAddr((uint8)BusType, Addr, Length) == 0x00000000U) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
                #else
                    Status = Cache_Ip_Invalidate_AllCacheByAddr((uint8)BusType, Addr, Length);
                #endif
            #else
                Status = Cache_Ip_Invalidate_AllCacheByAddr((uint8)BusType, Addr, Length);
            #endif
        break;}
        #endif /* CACHE_IP_LMEM_IS_AVAILABLE */
        #if ((STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) || (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE))
        case CACHE_IP_CORE:{
            if (BusType == CACHE_IP_INSTRUCTION)
            {
                Cache_Ip_Invalidate_InstructionCacheByAddr(Addr, Length);
            }
            else if (BusType == CACHE_IP_DATA)
            {
                Cache_Ip_Invalidate_DataCacheByAddr(Addr, Length);
            }
            else
            {
                CACHE_IP_DEV_ASSERT(FALSE);
            }
        break;}
        #endif /* CACHE_IP_ARMCOREMX_IS_AVAILABLE || CACHE_IP_ARMCORERX_IS_AVAILABLE */
        default:{
            CACHE_IP_DEV_ASSERT(FALSE);
        break;}
    }
    /* Exit exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIMVAU */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17();
    
    return Status;
}


/***************************************************************************************************
* @brief        The function cleans by address the specified cache.
*
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 * @param[in]  enInvalidate      Specifies to execute operation Clean&Invalidate.
 * @param[in]  Addr              Specifies the memory segment start address.
 * @param[in]  Length            Specifies the memory segment length.
***************************************************************************************************/
Std_ReturnType Cache_Ip_CleanByAddr(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const boolean EnInvalidate, const uint32 Addr, const uint32 Length)
{
    Std_ReturnType Status = E_OK;

    /* Enter exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIMVAU */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18();
    switch(CacheType)
    {
        #if (STD_ON == CACHE_IP_LMEM_IS_AVAILABLE)
        case CACHE_IP_LMEM:{
            #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CACHE_IP_USER_MODE_SUPPORT_IS_AVAILABLE)
                    Status = ((Cache_Ip_Clean_AllCacheByAddr((uint8)BusType, EnInvalidate, Addr, Length) == 0x00000000U) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
                #else
                    Status = Cache_Ip_Clean_AllCacheByAddr((uint8)BusType, EnInvalidate, Addr, Length);
                #endif
            #else
                Status = Cache_Ip_Clean_AllCacheByAddr((uint8)BusType, EnInvalidate, Addr, Length);
            #endif
        break;}
        #endif /* CACHE_IP_LMEM_IS_AVAILABLE */
        #if ((STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE) || (STD_ON == CACHE_IP_ARMCORERX_IS_AVAILABLE))
        case CACHE_IP_CORE:{
            if (BusType == CACHE_IP_INSTRUCTION)
            {
                Cache_Ip_Clean_InstructionCacheByAddr(EnInvalidate, Addr, Length);
            }
            else if (BusType == CACHE_IP_DATA)
            {
                Cache_Ip_Clean_DataCacheByAddr(EnInvalidate, Addr, Length);
            }
            else
            {
                CACHE_IP_DEV_ASSERT(FALSE);
            }
        break;}
        #endif /* CACHE_IP_ARMCOREMX_IS_AVAILABLE || CACHE_IP_ARMCORERX_IS_AVAILABLE */
        default:{
            CACHE_IP_DEV_ASSERT(FALSE);
        break;}
    }
    /* Exit exclusive area to protect S32_SCB_CSSELR, S32_SCB_ICIMVAU */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18();

    return Status;
}

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == CACHE_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */


