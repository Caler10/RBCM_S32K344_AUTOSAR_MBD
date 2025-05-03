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
#ifndef SEMA42_IP_H_
#define SEMA42_IP_H_

/**
*   @file Sema42_Ip.h
*
*   @addtogroup Sema42_Ip Sema42 IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Sema42_Ip_Types.h"
#include "Sema42_Ip_DeviceRegisters.h"
#include "Devassert.h"
#include "Mcal.h"

#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_SEMA42_IP_VENDOR_ID                      43
#define RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION       4
#define RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION       7
#define RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION    0
#define RM_SEMA42_IP_SW_MAJOR_VERSION               5
#define RM_SEMA42_IP_SW_MINOR_VERSION               0
#define RM_SEMA42_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Sema42_Ip_DeviceRegisters.h */
#if (RM_SEMA42_IP_VENDOR_ID != RM_SEMA42_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Sema42_Ip.h and Sema42_Ip_DeviceRegisters.h have different vendor ids"
#endif
#if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Sema42_Ip.h and Sema42_Ip_DeviceRegisters.h are different"
#endif
#if ((RM_SEMA42_IP_SW_MAJOR_VERSION != RM_SEMA42_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_SEMA42_IP_SW_MINOR_VERSION != RM_SEMA42_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_SEMA42_IP_SW_PATCH_VERSION != RM_SEMA42_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sema42_Ip.h and Sema42_Ip_DeviceRegisters.h are different"
#endif

/* Checks against Sema42_Ip_Types.h */
#if (RM_SEMA42_IP_VENDOR_ID != RM_SEMA42_IP_TYPES_VENDOR_ID)
    #error "Sema42_Ip.h and Sema42_Ip_Types.h have different vendor ids"
#endif
#if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Sema42_Ip.h and Sema42_Ip_Types.h are different"
#endif
#if ((RM_SEMA42_IP_SW_MAJOR_VERSION != RM_SEMA42_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_SEMA42_IP_SW_MINOR_VERSION != RM_SEMA42_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_SEMA42_IP_SW_PATCH_VERSION != RM_SEMA42_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sema42_Ip.h and Sema42_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Sema42_Ip.h and Devassert.h are of the same version */
    #if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
        (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AUTOSAR Version Numbers of Sema42_Ip.h and Devassert.h are different"
    #endif

    /* Checks against Mcal.h */
    #if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Sema42_Ip.h and Mcal.h are different"
    #endif

    #ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
        /* Checks against OsIf.h */
        #if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of Sema42_Ip.h and OsIf.h are different"
        #endif
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
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
void Sema42_Ip_Init(const uint32 u32Instance);

/**
 * @brief         Lock a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 * @param[in]     u8GateIndex:      Index of the selected gate
 * @param[in]     u8DomainId:       Current Domain of the core. If the XRDC is not supported the domain id is the core ID - @ref Sys_GetCoreId()
 *
 * @return        Sema42_Ip_StatusType
 * @retval        SEMA42_IP_SUCCESS:If the gate was locked successfully
 * @retval        SEMA42_IP_ERROR:  If the gate is locked by another master
 *
 * @api
 *
 * @pre
 *
 */
Sema42_Ip_StatusType Sema42_Ip_LockGate(const uint32 u32Instance,
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
 * @return        Sema42_Ip_StatusType
 * @retval        SEMA42_IP_SUCCESS:If the gate was unlocked successfully
 * @retval        SEMA42_IP_ERROR:  If the gate is unlocked by another master
 * @api
 *
 * @pre
 *
 */
Sema42_Ip_StatusType Sema42_Ip_UnlockGate(const uint32 u32Instance,
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
void Sema42_Ip_ResetGate(const uint32 u32Instance,
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
uint8 Sema42_Ip_GetGateLocker(const uint32 u32Instance,
                              const uint8 u8GateIndex);

/**
 * @brief         Check if the current state of the reset gate state machine is idle.
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance:      Instance number
 *
 * @return        boolean
 * @retval        TRUE:             if the reset gate is idle
 * @retval        FALSE:            if the reset gate is waiting for the second write or if it is actively resseting a gate
 *
 * @api
 *
 * @pre
 *
 */
boolean Sema42_Ip_IsResetGateStateIdle(const uint32 u32Instance);

/**
 * @brief         Get the bus master which initiated the most recent write operation
 *                on the reset register.
 * @details       This function is reentrant
 *
 * @param[in]     u8Instance:       Instance number
 * @return        uint8
 * @retval        Id of the domain which requested the most recent reset
 *
 * @api
 *
 * @pre
 *
 */
uint8 Sema42_Ip_GetResetGateBusMaster(const uint32 u32Instance);

/**
 * @brief         Get the index of the gate targetted by the most recent reset attempt.
 * @details       This function is reentrant
 *
 * @param[in]     u8Instance: instance number
 * @return        uint8 : index of the gate targeted for reset
 * @retval        Index of the gate targeted for reset
 *
 * @api
 *
 * @pre
 *
 */
uint8 Sema42_Ip_GetResetGateIndex(const uint32 u32Instance);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* if (SEMA42_IP_SUPPORT == STD_ON) */
#endif /*SEMA42_IP_SUPPORT ENABLE*/

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* SEMA42_IP_H_ */
