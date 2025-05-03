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
#ifndef CACHE_IP_DRIVER_H_
#define CACHE_IP_DRIVER_H_

/**
*   @file    Cache_Ip.h
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
#include "Cache_Ip_Cfg_Defines.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CACHE_IP_VENDOR_ID                       43
#define CACHE_IP_AR_RELEASE_MAJOR_VERSION        4
#define CACHE_IP_AR_RELEASE_MINOR_VERSION        7
#define CACHE_IP_AR_RELEASE_REVISION_VERSION     0
#define CACHE_IP_SW_MAJOR_VERSION                5
#define CACHE_IP_SW_MINOR_VERSION                0
#define CACHE_IP_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same vendor */
#if (CACHE_IP_VENDOR_ID != CACHE_IP_CFG_DEFINES_VENDOR_ID)
    #error "Cache_Ip.h and Cache_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CACHE_IP_AR_RELEASE_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_MINOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CACHE_IP_AR_RELEASE_REVISION_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Cache_Ip.h and Cache_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CACHE_IP_SW_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CACHE_IP_SW_MINOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CACHE_IP_SW_PATCH_VERSION != CACHE_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Cache_Ip.h and Cache_Ip_Cfg_Defines.h are different"
#endif

#if (STD_ON == CACHE_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief This type contains the Cache Ip types.
 * @details The cache types specifies what type of cache shall be used when calling the interface.
 *          The CACHE_IP_LMEM select LMEM caches.
 *          The CACHE_IP_CORE select CORE caches.
 *
 * */
typedef enum{
    CACHE_IP_LMEM         = 0U,
    CACHE_IP_CORE         = 1U,
}Cache_Ip_Type;

/**
 * @brief This type contains the Cache Ip Bus types.
 * @details The cache bus types specifies what type of cache shall be used when calling the interface.
 *          The CACHE_IP_PC_BUS selects Processor Code (PC) bus (used with Cache Lmem).
 *          The CACHE_IP_PS_BUS selects Processor System (PS) bus (used with Cache Lmem).
 *          The CACHE_IP_ALL_BUS selects PC and PS bus (used with Cache Lmem).
 *          The CACHE_IP_INSTRUCTION selects instruction cache (used with Cache Core).
 *          The CACHE_IP_DATA selects data cache (used with Cache Core).
 *
 * */
typedef enum{
    CACHE_IP_PC_BUS         = 0U,
    CACHE_IP_PS_BUS         = 1U,
    CACHE_IP_ALL_BUS        = 2U,
    CACHE_IP_INSTRUCTION    = 3U,
    CACHE_IP_DATA           = 4U,
}Cache_Ip_BusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/**
 * @brief This function enables the Cache Ip Driver.
 * @details This service is a reentrant function that shall enable the Cache Ip driver.
 *
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 *
 * @return   E_OK is returned if the enable action finished correctly.
 *           E_NOT_OK is returned if the enable action finished incorrectly.
 *
 * @implements Cache_Ip_Enable_Activity
 * */
Std_ReturnType Cache_Ip_Enable(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType);


/**
 * @brief This function disables the Cache Ip Driver.
 * @details This service is a reentrant function that shall disables the Cache Ip driver.
 *
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 *
 * @return   E_OK is returned if the disable action finished correctly.
 *           E_NOT_OK is returned if the disable action finished incorrectly.
 *
 * @implements Cache_Ip_Disable_Activity
 * */
 Std_ReturnType Cache_Ip_Disable(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType);


/**
 * @brief This function Invalidates the Cache Ip Driver.
 * @details This service is a reentrant function that shall Invalidates the Cache Ip driver.
 *          The Invalidate operation applies for the entire selected Cache Type.
 *
 *          A cache invalidate operation ensures that updates made visible by observers that access memory at
 *          the point to which the invalidate is defined are made visible to an observer that controls the cache.
 *          This might result in the loss of updates to the locations affected by the invalidate operation that have
 *          been written by observers that access the cache. If the address of an entry on which the invalidate
 *          operates does not have a Normal Cacheable attribute, or if the cache is disabled, then an invalidate
 *          operation also ensures that this address is not present in the cache.
 *
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 *
 * @return   E_OK is returned if the invalidation finished correctly.
 *           E_NOT_OK is returned if the invalidation finished incorrectly.
 *
 * @implements Cache_Ip_Invalidate_Activity
 * */
Std_ReturnType Cache_Ip_Invalidate(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType);


/**
 * @brief This function Clean the Cache Ip Driver.
 * @details This service is a reentrant function that shall Clean the Cache Ip driver.
 *          The Clean operation applies for the entire selected Cache Type.
 *
 *          A cache clean operation ensures that updates made by an observer that controls the cache are made
 *          visible to other observers that can access memory at the point to which the operation is performed.
 *          Once the Clean has completed, the new memory values are guaranteed to be visible to the point to
 *          which the operation is performed, for example to the point of unification. The cleaning of a cache
 *          entry from a cache can overwrite memory that has been written by another observer only if the entry
 *          contains a location that has been written to by an observer in the shareability domain of that memory
 *          location.
 *
 *          A cache clean and invalidate operation behaves as the execution of a clean operation followed
 *          immediately by an invalidate operation. Both operations are performed to the same location.
 *
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 * @param[in]  enInvalidate      Specifies to execute operation Clean&Invalidate.
 *
 * @return   E_OK is returned if the cleaning finished correctly.
 *           E_NOT_OK is returned if the cleaning finished incorrectly.
 *
 * @implements Cache_Ip_Clean_Activity
 * */
Std_ReturnType Cache_Ip_Clean(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const boolean EnInvalidate);



/**
 * @brief This function Invalidates By Address the Cache Ip Driver.
 * @details This service is a reentrant function that shall Invalidates By Address the Cache Ip driver.
 *          The Invalidate By Address operation applies for the memory segment specified by the
 *          start Address and Length. The operation Invalidates only multiple of Cache Line Size, thus the
 *          specified memory segment shall be aligned and multiple of the Cache Line Size.
 *
 *          A cache invalidate operation ensures that updates made visible by observers that access memory at
 *          the point to which the invalidate is defined are made visible to an observer that controls the cache.
 *          This might result in the loss of updates to the locations affected by the invalidate operation that have
 *          been written by observers that access the cache. If the address of an entry on which the invalidate
 *          operates does not have a Normal Cacheable attribute, or if the cache is disabled, then an invalidate
 *          operation also ensures that this address is not present in the cache.
 *
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 * @param[in]  Addr              Specifies the memory segment start address.
 * @param[in]  Length            Specifies the memory segment length.
 *
 * @return   E_OK is returned if the invalidation finished correctly.
 *           E_NOT_OK is returned if the invalidation finished incorrectly.
 *
 * @implements Cache_Ip_InvalidateByAddr_Activity
 * */
Std_ReturnType Cache_Ip_InvalidateByAddr(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const uint32 Addr, const uint32 Length);


/**
 * @brief This function Clean By Address the Cache Ip Driver.
 * @details This service is a reentrant function that shall Clean By Address the Cache Ip driver.
 *          The Clean By Address operation applies for the memory segment specified by the
 *          start Address and Length. The operation Cleans only multiple of Cache Line Size, thus the
 *          specified memory segment shall be aligned and multiple of the Cache Line Size.
 *
 *          A cache clean operation ensures that updates made by an observer that controls the cache are made
 *          visible to other observers that can access memory at the point to which the operation is performed.
 *          Once the Clean has completed, the new memory values are guaranteed to be visible to the point to
 *          which the operation is performed, for example to the point of unification. The cleaning of a cache
 *          entry from a cache can overwrite memory that has been written by another observer only if the entry
 *          contains a location that has been written to by an observer in the shareability domain of that memory
 *          location.
 *
 *          A cache clean and invalidate operation behaves as the execution of a clean operation followed
 *          immediately by an invalidate operation. Both operations are performed to the same location.
 *
 * @param[in]  CacheType         Specifies the cache type.
 * @param[in]  BusType           Specifies the bus type.
 * @param[in]  enInvalidate      Specifies to execute operation Clean&Invalidate.
 * @param[in]  Addr              Specifies the memory segment start address.
 * @param[in]  Length            Specifies the memory segment length.
 *
 * @return   E_OK is returned if the cleaning finished correctly.
 *           E_NOT_OK is returned if the cleaning finished incorrectly.
 *
 * @implements Cache_Ip_CleanByAddr_Activity
 * */
Std_ReturnType Cache_Ip_CleanByAddr(const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const boolean EnInvalidate, const uint32 Addr, const uint32 Length);

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == CACHE_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif


/** @} */

#endif  /* #ifndef CACHE_IP_DRIVER_H_ */
