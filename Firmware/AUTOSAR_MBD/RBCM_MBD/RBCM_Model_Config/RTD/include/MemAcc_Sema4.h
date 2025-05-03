/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : none
*   Dependencies         : MemAcc
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

#ifndef MEMACC_SEMA4_H
#define MEMACC_SEMA4_H

/**
*   @file MemAcc_Sema4.h
*
*   @addtogroup MEMACC
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


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_SEMA4_VENDOR_ID                      43
#define MEMACC_SEMA4_AR_RELEASE_MAJOR_VERSION       4
#define MEMACC_SEMA4_AR_RELEASE_MINOR_VERSION       7
#define MEMACC_SEMA4_AR_RELEASE_REVISION_VERSION    0
#define MEMACC_SEMA4_SW_MAJOR_VERSION               5
#define MEMACC_SEMA4_SW_MINOR_VERSION               0
#define MEMACC_SEMA4_SW_PATCH_VERSION               0

#if (STD_ON == MEMACC_MULTICORE_TYPE_1_ENABLED)
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
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
#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
#define MEMACC_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "MemAcc_MemMap.h"

/* Pointer to current memacc module configuration set */
extern const MemAcc_ConfigType            *MemAcc_pConfigPtr;

#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
#define MEMACC_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "MemAcc_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @brief        The function request lock the sema4 channel.
 *
 * @details      Request lock function - request lock sema4 channel for current core on the mem hardware resource.
 *
 * @param[in]    MemHwResource    Mem resource index.
 *
 * @return       Std_ReturnType
 *                  - E_OK                   : Lock sema4 successfully.
 *                  - E_NOT_OK               : Lock sema4 fail.
 *
 * @pre          None.
 *
 * @api
 */
Std_ReturnType         MemAcc_Sema4_RequestLock(uint8 MemHwResource);
/**
 * @brief        The function request unlock the sema4 channel.
 *
 * @details      Request unlock function - request unlock sema4 channel for current core on the mem hardware resource.
 *
 * @param[in]    MemHwResource    Mem resource index.
 *
 * @return       None.
 *
 *
 * @pre          None.
 *
 * @api
 */
void                   MemAcc_Sema4_ReleaseLock(uint8 MemHwResource);

/**
 * @brief        The function request lock the sema4 channel when initilizing the driver.
 *
 * @details      Request lock function - request lock sema4 channel for current core on all mem hardware resource.
 *
 * @param[in]    MemHwResource    Mem resource index.
 *
 * @return       Std_ReturnType
 *                  - E_OK                   : Lock sema4 successfully.
 *                  - E_NOT_OK               : Lock sema4 fail.
 *
 * @pre          None.
 *
 * @api
 */
Std_ReturnType         MemAcc_Sema4_InitLock(void);

/**
 * @brief        The function request lock the sema4 channel when initilizing the driver.
 *
 * @details      Request unlock function - request unlock sema4 channel for current core on all mem hardware resource.
 *
 * @param[in]    MemHwResource    Mem resource index.
 *
 * @return       None.
 *
 *
 * @pre          None.
 *
 * @api
 */
void                   MemAcc_Sema4_InitUnLock(void);

#ifdef __cplusplus
}
#endif

#endif  /*#if (STD_ON == MEMACC_MULTICORE_TYPE_1_ENABLED) */

/** @} */

#endif /* MEMACC_H */
