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

#ifndef SEMA42_IP_TRUSTEDFUNCTIONS_H
#define SEMA42_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Sema42_Ip_TrustedFunctions.h
*
*   @addtogroup Sema42_Ip Sema42 IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Sema42_Ip_Types.h"
#include "Sema42_Ip_Cfg_Defines.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               5
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sema42_Ip_Types.h header file are of the same vendor */
#if (RM_SEMA42_IP_TYPES_VENDOR_ID != RM_SEMA42_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Sema42_Ip_TrustedFunctions.h and Sema42_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sema42_Ip_Types.h header file are of the same Autosar version */
#if ((RM_SEMA42_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sema42_Ip_TrustedFunctions.h and Sema42_Ip_Types.h are different"
#endif
/* Check if current file and Sema42_Ip_Types.h header file are of the same Software version */
#if ((RM_SEMA42_IP_TYPES_SW_MAJOR_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_SW_MINOR_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (RM_SEMA42_IP_TYPES_SW_PATCH_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sema42_Ip_TrustedFunctions.h and Sema42_Ip_Types.h are different"
#endif

/* Check if current file and Sema42_Ip_Cfg_Defines.h header file are of the same vendor */
#if (RM_SEMA42_IP_CFG_DEFINES_VENDOR_ID != RM_SEMA42_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Sema42_Ip_TrustedFunctions.h and Pflash_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Sema42_Ip_Cfg_Defines.h header file are of the same Autosar version */
#if ((RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sema42_Ip_TrustedFunctions.h and Sema42_Ip_Cfg_Defines.h are different"
#endif
/* Check if current file and Sema42_Ip_Cfg_Defines.h header file are of the same Software version */
#if ((RM_SEMA42_IP_CFG_DEFINES_SW_MAJOR_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (RM_SEMA42_IP_CFG_DEFINES_SW_MINOR_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (RM_SEMA42_IP_CFG_DEFINES_SW_PATCH_VERSION != RM_SEMA42_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sema42_Ip_TrustedFunctions.h and Sema42_Ip_Cfg_Defines.h are different"
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
#ifdef SEMA42_IP_SUPPORT
#if (SEMA42_IP_SUPPORT == STD_ON)

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief         Initializes the Sema42 instance by resetting all gates
 *
 * @details       This function is non-reentrant
 *
 * @param[in]     u32Instance:      Instance number
 * @return        void
 *
 * @api
 *
 * @pre
 */
extern void Sema42_Ip_Init_Privileged(const uint32 u32Instance);

/**
 * @brief         Lock a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 * @param[in]     u8GateIndex:      Index of the selected gate
 * @param[in]     u8DomainId:       Current Domain of the core. If the XRDC is not supported the domain id is the core ID - @ref Sys_GetCoreId()
 *
 * @return        uint8
 * @retval        Status of Semaphore instance
 * @api
 *
 * @pre
 *
 */
extern uint8 Sema42_Ip_LockGate_Privileged(const uint32 u32Instance,
                                           const uint8 u8GateIndex,
                                           uint8 u8DomainId);

/**
 * @brief         Unlock a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 * @param[in]     u8GateIndex:      Index of the selected gate
 *
 * @return        uint8
 * @retval        Status of Semaphore instance
 * @api
 *
 * @pre
 *
 */
extern uint8 Sema42_Ip_UnlockGate_Privileged(const uint32 u32Instance,
                                             const uint8 u8GateIndex);

/**
 * @brief         Reset a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 * @param[in]     u8GateIndex:      Index of the selected gate
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
extern void Sema42_Ip_ResetGate_Privileged(const uint32 u32Instance,
                                           const uint8 u8GateIndex);

/**
 * @brief         Get the current owner of a semaphore
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 * @param[in]     u8GateIndex:      Index of the selected gate
 * @return        uint8
 * @retval        Index of the semaphore owner, or SEMA42_IP_UNLOCKED_GATE if the gate is not locked.
 *
 * @api
 *
 * @pre
 *
 */
extern uint8 Sema42_Ip_GetGateLocker_Privileged(const uint32 u32Instance,
                                                const uint8 u8GateIndex);

/**
 * @brief         Check if the current state of the reset gate state machine is idle.
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 *
 * @return        uint8
 * @retval        Status of Semaphore instance
 * @api
 *
 * @pre
 *
 */
extern uint8 Sema42_Ip_IsResetGateStateIdle_Privileged(const uint32 u32Instance);

/**
 * @brief         Get the bus master which initiated the most recent write operation
 *                on the reset register.
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance: instance number
 * @return        uint8
 * @retval        Id of the domain which requested the most recent reset
 * @api
 *
 * @pre
 *
 */
extern uint8 Sema42_Ip_GetResetGateBusMaster_Privileged(const uint32 u32Instance);

/**
 * @brief         Get the index of the gate targetted by the most recent reset attempt.
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance: instance number
 * @return        uint8
 * @retval        Index of the gate targeted for reset
 * @api
 *
 * @pre
 *
 */
extern uint8 Sema42_Ip_GetResetGateIndex_Privileged(const uint32 u32Instance);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* (SEMA42_IP_SUPPORT == STD_ON) */
#endif /* ifdef SEMA42_IP_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SEMA42_IP_TRUSTEDFUNCTIONS_H */
