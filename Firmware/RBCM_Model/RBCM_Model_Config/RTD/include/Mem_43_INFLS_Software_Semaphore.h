/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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

#ifndef MEM_43_INFLS_SOFTWARE_SEMAPHORE_H
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_H

/**
*   @file Mem_43_INFLS_Software_Semaphore.h
*
*   @addtogroup MEM_43_INFLS
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "StandardTypes.h"
#include "Mem_43_INFLS_Cfg.h"

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_VENDOR_ID                       43
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION        4
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION        7
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION     0
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION                5
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION                0
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_INFLS configuration header file are of the same vendor */
#if (MEM_43_INFLS_SOFTWARE_SEMAPHORE_VENDOR_ID != MEM_43_INFLS_VENDOR_ID_CFG)
    #error "Mem_43_INFLS_Cfg.h and Mem_43_INFLS_Software_Semaphore.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS configuration header file are of the same Autosar version */
#if ((MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Cfg.h and Mem_43_INFLS_Software_Semaphore.h are different"
#endif

/* Check if current file and Mem_43_INFLS configuration header file are of the same software version */
#if ((MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION != MEM_43_INFLS_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION != MEM_43_INFLS_SW_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION != MEM_43_INFLS_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Cfg.h and Mem_43_INFLS_Software_Semaphore.h are different"
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define MEM_43_INFLS_SOFTWARE_SEMA4_UNLOCKED_VALUE  0U
#define MEM_43_INFLS_SOFTWARE_SEMA4_LOCKED_VALUE    1U

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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if (STD_ON == MEM_43_INFLS_USING_SW_SEMAPHORE)

/**
 * @brief        The function request lock the sema4 channel.
 *
 * @details      Request lock function - request lock sema4 channel for current core on the mem hardware resource.
 *
 * @param[in]    None.
 *
 * @return       Std_ReturnType
 *                  - E_OK                   : Lock sema4 successfully.
 *                  - E_NOT_OK               : Lock sema4 fail.
 *
 * @pre          None.
 *
 * @api
 */
Std_ReturnType         Mem_43_INFLS_Software_Semaphore_RequestLock(void);
/**
 * @brief        The function request unlock the sema4 channel.
 *
 * @details      Request unlock function - request unlock sema4 channel for current core on the mem hardware resource.
 *
 * @param[in]    None.
 *
 * @return       Std_ReturnType
 *                  - E_OK                   : UnLock sema4 successfully.
 *                  - E_NOT_OK               : UnLock sema4 fail.
 *
 *
 * @pre          None.
 *
 * @api
 */
Std_ReturnType         Mem_43_INFLS_Software_Semaphore_ReleaseLock(void);

#ifdef __cplusplus
}
#endif

#endif  /*#if (STD_ON == MEM_43_INFLS_USING_SW_SEMAPHORE) */

/** @} */

#endif /* MEM_43_INFLS_H */
