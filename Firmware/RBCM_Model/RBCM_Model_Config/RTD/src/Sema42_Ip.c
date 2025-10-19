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

/**
*   @file Sema42_Ip.c
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
#include "Sema42_Ip.h"

#ifdef SEMA42_IP_DEV_ERROR_DETECT
#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_SEMA42_IP_VENDOR_ID_C                      43
#define RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RM_SEMA42_IP_SW_MAJOR_VERSION_C               5
#define RM_SEMA42_IP_SW_MINOR_VERSION_C               0
#define RM_SEMA42_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Sema42_Ip.h */
#if (RM_SEMA42_IP_VENDOR_ID_C != RM_SEMA42_IP_VENDOR_ID)
    #error "Sema42_Ip.c and Sema42_Ip.h have different vendor ids"
#endif
#if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION_C    !=  RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION_C    !=  RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION_C !=  RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Sema42_Ip.c and Sema42_Ip.h are different"
#endif
#if ((RM_SEMA42_IP_SW_MAJOR_VERSION_C !=  RM_SEMA42_IP_SW_MAJOR_VERSION) || \
     (RM_SEMA42_IP_SW_MINOR_VERSION_C !=  RM_SEMA42_IP_SW_MINOR_VERSION) || \
     (RM_SEMA42_IP_SW_PATCH_VERSION_C !=  RM_SEMA42_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sema42_Ip.c and Sema42_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    #ifdef SEMA42_IP_DEV_ERROR_DETECT
    #if(SEMA42_IP_DEV_ERROR_DETECT == STD_ON)

        /* Check if the files Sema42_Ip.c and Devassert.h are of the same version */
        #if ((RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AUTOSAR Version Numbers of Sema42_Ip.c and Devassert.h are different"
        #endif
    #endif
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                       LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#ifdef SEMA42_IP_SUPPORT
#if (SEMA42_IP_SUPPORT == STD_ON)

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
LOCAL_INLINE void Sema42_Ip_ResetAllGates(SEMA42_Type * const base);

void Sema42_Ip_Init_Privileged(const uint32 u32Instance);

uint8 Sema42_Ip_LockGate_Privileged(const uint32 u32Instance,
                                    const uint8 u8GateIndex,
                                    uint8 u8DomainId);

uint8 Sema42_Ip_UnlockGate_Privileged(const uint32 u32Instance,
                                      const uint8 u8GateIndex);

void Sema42_Ip_ResetGate_Privileged(const uint32 u32Instance,
                                    const uint8 u8GateIndex);

uint8 Sema42_Ip_GetGateLocker_Privileged(const uint32 u32Instance,
                                         const uint8 u8GateIndex);

uint8 Sema42_Ip_IsResetGateStateIdle_Privileged(const uint32 u32Instance);

uint8 Sema42_Ip_GetResetGateBusMaster_Privileged(const uint32 u32Instance);

uint8 Sema42_Ip_GetResetGateIndex_Privileged(const uint32 u32Instance);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_CONST_32
#include "Rm_MemMap.h"

/* Table of base addresses for SEMA42 instances. */
static SEMA42_Type * const Sema42_Ip_Base[SEMA42_IP_INSTANCE_COUNT] = SEMA42_IP_ARRAY_BASE_PTRS;

#define RM_STOP_SEC_CONST_32
#include "Rm_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
/**
 * @brief         Reset all gates of Sema42 Instance
 *
 * @details
 *
 * @param[in]
 * @return
 *
 * @api
 *
 * @pre
 */
LOCAL_INLINE void Sema42_Ip_ResetAllGates(SEMA42_Type * const base)
{
    base->RSTGT.W = ((uint16) SEMA42_W_RSTGDP(SEMA42_IP_RSTGT_FIRST_WRITE_SEQUENCE));
    base->RSTGT.W = (uint16) ((uint16) SEMA42_W_RSTGDP(SEMA42_IP_RSTGT_SECOND_WRITE_SEQUENCE) |
                              ((uint16) SEMA42_W_RSTGTN(SEMA42_IP_RESET_GATE_ALL)));
}

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
void Sema42_Ip_Init_Privileged(const uint32 u32Instance)
{
    SEMA42_Type *base;
#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < SEMA42_IP_INSTANCE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];
    /* Reset all gates */
    Sema42_Ip_ResetAllGates(base);
}

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
uint8 Sema42_Ip_LockGate_Privileged(const uint32 u32Instance,
                                    const uint8 u8GateIndex,
                                    uint8 u8DomainId)
{
    SEMA42_Type *base;
    uint8 gateStatus;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < (uint8)SEMA42_IP_INSTANCE_COUNT);
    DevAssert(u8GateIndex < SEMA42_GATE_COUNT);
    DevAssert(u8DomainId < SEMA42_IP_DOMAIN_ID_NUMBER);
#endif

    base = Sema42_Ip_Base[u32Instance];

    gateStatus = (base->GATE[SEMA42_IP_GATE_OFFSET(u8GateIndex)] & SEMA42_GATE_GTFSM_MASK) >> SEMA42_GATE_GTFSM_SHIFT;
    if (gateStatus == SEMA42_IP_UNLOCKED_GATE_VALUE)
    {
        /* Try to lock the gate */
        base->GATE[SEMA42_IP_GATE_OFFSET(u8GateIndex)] = (uint8)SEMA42_GATE_GTFSM(SEMA42_IP_GATE_LOCK(u8DomainId));
        gateStatus = (base->GATE[SEMA42_IP_GATE_OFFSET(u8GateIndex)] & SEMA42_GATE_GTFSM_MASK) >> SEMA42_GATE_GTFSM_SHIFT;
    }

    return gateStatus;
}

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
uint8 Sema42_Ip_UnlockGate_Privileged(const uint32 u32Instance,
                                      const uint8 u8GateIndex)
{
    SEMA42_Type *base;
    uint8 gateStatus;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < SEMA42_IP_INSTANCE_COUNT);
    DevAssert(u8GateIndex < SEMA42_GATE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];

    /* Try to unlock the gate */
    base->GATE[SEMA42_IP_GATE_OFFSET(u8GateIndex)] = (uint8)SEMA42_GATE_GTFSM(SEMA42_IP_UNLOCKED_GATE_VALUE);

    gateStatus = (base->GATE[SEMA42_IP_GATE_OFFSET(u8GateIndex)] & SEMA42_GATE_GTFSM_MASK) >> (uint8)SEMA42_GATE_GTFSM_SHIFT;

    return gateStatus;
}

/**
 * @brief         Reset a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance         Instance number
 * @param[in]     u8GateIndex         Index of the selected gate
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
void Sema42_Ip_ResetGate_Privileged(const uint32 u32Instance,
                                    const uint8 u8GateIndex)
{
    SEMA42_Type *base;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < (uint8)SEMA42_IP_INSTANCE_COUNT);
    DevAssert(u8GateIndex < SEMA42_GATE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];

    /* Write the reset sequence */
    base->RSTGT.W = (SEMA42_W_RSTGDP(SEMA42_IP_RSTGT_FIRST_WRITE_SEQUENCE) | SEMA42_W_RSTGTN(u8GateIndex));
    base->RSTGT.W = (SEMA42_W_RSTGDP(SEMA42_IP_RSTGT_SECOND_WRITE_SEQUENCE) | SEMA42_W_RSTGTN(u8GateIndex));
}

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
uint8 Sema42_Ip_GetGateLocker_Privileged(const uint32 u32Instance,
                                         const uint8 u8GateIndex)
{
    const SEMA42_Type *base;
    volatile uint8 DomainLocker;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < (uint8)SEMA42_IP_INSTANCE_COUNT);
    DevAssert(u8GateIndex < SEMA42_GATE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];
    MCAL_FAULT_INJECTION_POINT(T_SEMA42_INJ_1);
    DomainLocker = (uint8)((base->GATE[SEMA42_IP_GATE_OFFSET(u8GateIndex)] & SEMA42_GATE_GTFSM_MASK) >> SEMA42_GATE_GTFSM_SHIFT);

#if (SEMA42_IP_DOMAIN_ID_NUMBER < FOUR_BIT_MAX_VALUE)
    if (DomainLocker > SEMA42_IP_DOMAIN_ID_NUMBER)
    {
        /*Invalid value, return unknow domain*/
        DomainLocker = (uint8)SEMA42_IP_UNKNOWN_DOMAINID;
    }
    else
#endif
    {
        if (DomainLocker != (uint8)SEMA42_IP_UNLOCKED_GATE_VALUE)
        {
            /* If the gate is locked, the domain is GTFSM - 1 */
            DomainLocker -= (uint8)1U;
        }
        else
        {
            DomainLocker = (uint8)SEMA42_IP_UNLOCKED_GATE;
        }
    }

    return DomainLocker;
}

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
uint8 Sema42_Ip_IsResetGateStateIdle_Privileged(const uint32 u32Instance)
{
    volatile uint8 gateStatus;
    const SEMA42_Type *base;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < SEMA42_IP_INSTANCE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];

    MCAL_FAULT_INJECTION_POINT(T_SEMA42_INJ_2);

    gateStatus = (uint8)((base->RSTGT.R & SEMA42_R_RSTGSM_MASK) >> SEMA42_R_RSTGSM_SHIFT);

    return gateStatus;
}

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
uint8 Sema42_Ip_GetResetGateBusMaster_Privileged(const uint32 u32Instance)
{
    const SEMA42_Type *base;
    volatile uint8 DomainNumber;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < (uint8)SEMA42_IP_INSTANCE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];

    MCAL_FAULT_INJECTION_POINT(T_SEMA42_INJ_3);

    /*Get domain number from the register*/
    DomainNumber = (uint8)((base->RSTGT.R & SEMA42_R_RSTGMS_MASK) >> SEMA42_R_RSTGMS_SHIFT);

#if (SEMA42_IP_DOMAIN_ID_NUMBER < FOUR_BIT_MAX_VALUE)
    /*Check domain invalidation*/
    if (DomainNumber >= SEMA42_IP_DOMAIN_ID_NUMBER)
    {
        /*Invalid value, return unknow domainID*/
        DomainNumber = (uint8)SEMA42_IP_UNKNOWN_DOMAINID;
    }
#endif

    return DomainNumber;
}

/**
 * @brief         Get the index of the gate targetted by the most recent reset attempt.
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance: instance number
 * @return        uint8
 * @retval        index of the gate targeted for reset
 * @api
 *
 * @pre
 *
 */
uint8 Sema42_Ip_GetResetGateIndex_Privileged(const uint32 u32Instance)
{
    const SEMA42_Type *base;
    volatile uint8 ResetGate;

#if (SEMA42_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u32Instance < (uint8)SEMA42_IP_INSTANCE_COUNT);
#endif

    base = Sema42_Ip_Base[u32Instance];

    MCAL_FAULT_INJECTION_POINT(T_SEMA42_INJ_4);

    ResetGate = (uint8)((base->RSTGT.R & SEMA42_R_RSTGTN_MASK) >> SEMA42_R_RSTGTN_SHIFT);

    if (ResetGate >= SEMA42_IP_RESET_GATE_ALL)
    {
        ResetGate = (uint8)SEMA42_IP_RESET_GATE_ALL;
    }
    else if (ResetGate >= SEMA42_GATE_COUNT)
    {
        ResetGate = SEMA42_IP_UNKNOWN_GATE;
    }
    else
    {
        /*Do nothing, Reseted gate is valid and single*/
    }

    return ResetGate;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the Sema42 instance by resetting all gates
 *
 * @details       This function is non-reentrant
 *
 * @param[in]     u32Instance   Instance number
 * @return        void
 *
 * @api
 *
 * @pre
 */
void Sema42_Ip_Init(const uint32 u32Instance)
{
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Sema42_Ip_Init_Privileged, u32Instance);
#else
    Sema42_Ip_Init_Privileged(u32Instance);
#endif
}

/**
 * @brief         Lock a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance         Instance number
 * @param[in]     u8GateIndex         Index of the selected gate
 * @param[in]     u8DomainId          Current Domain of the core. If the XRDC is not supported the domain id is the core ID - @ref Sys_GetCoreId()
 *
 * @return        Sema42_Ip_StatusType
 * @retval        SEMA42_IP_SUCCESS   If the gate was locked successfully
 * @retval        SEMA42_IP_ERROR     If the gate is locked by another master
 *
 * @api
 *
 * @pre
 *
 */
Sema42_Ip_StatusType Sema42_Ip_LockGate(const uint32 u32Instance,
                                        const uint8 u8GateIndex,
                                        uint8 u8DomainId)
{
    Sema42_Ip_StatusType stat;
    uint32 gateStatus;
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    gateStatus = OsIf_Trusted_Call_Return3param(Sema42_Ip_LockGate_Privileged, u32Instance, u8GateIndex, u8DomainId);
#else
    gateStatus = Sema42_Ip_LockGate_Privileged(u32Instance, u8GateIndex, u8DomainId);
#endif
    /* Check if the gate is locked by another master, or if it is still unlocked */
    if (((gateStatus != SEMA42_IP_UNLOCKED_GATE_VALUE) && (gateStatus != SEMA42_IP_GATE_LOCK(u8DomainId))) || (gateStatus == SEMA42_IP_UNLOCKED_GATE_VALUE))
    {
        stat = (Sema42_Ip_StatusType)SEMA42_IP_ERROR;
    }
    else
    {
        stat = (Sema42_Ip_StatusType)SEMA42_IP_SUCCESS;
    }

    return stat;
}

/**
 * @brief         Unlock a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance         Instance number
 * @param[in]     u8GateIndex         Index of the selected gate
 *
 * @return        Sema42_Ip_StatusType
 * @retval        SEMA42_IP_SUCCESS   If the gate was unlocked successfully
 * @retval        SEMA42_IP_ERROR     If the gate is unlocked by another master
 * @api
 *
 * @pre
 *
 */
Sema42_Ip_StatusType Sema42_Ip_UnlockGate(const uint32 u32Instance,
                                          const uint8 u8GateIndex)
{
    uint32 gateStatus;
    Sema42_Ip_StatusType stat;
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    gateStatus = OsIf_Trusted_Call_Return2param(Sema42_Ip_UnlockGate_Privileged, u32Instance, u8GateIndex);
#else
    gateStatus = Sema42_Ip_UnlockGate_Privileged(u32Instance, u8GateIndex);
#endif
    /* Check if the gate was unlocked, or if it is still locked by another master */
    if (gateStatus != SEMA42_IP_UNLOCKED_GATE_VALUE)
    {
        stat = (Sema42_Ip_StatusType)SEMA42_IP_ERROR;
    }
    else
    {
        stat = (Sema42_Ip_StatusType)SEMA42_IP_SUCCESS;
    }

    return stat;
}

/**
 * @brief         Reset a Semaphore gate
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance         Instance number
 * @param[in]     u8GateIndex         Index of the selected gate
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
void Sema42_Ip_ResetGate(const uint32 u32Instance,
                         const uint8 u8GateIndex)
{
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call2params(Sema42_Ip_ResetGate_Privileged, u32Instance, u8GateIndex);
#else
    Sema42_Ip_ResetGate_Privileged(u32Instance, u8GateIndex);
#endif
}

/**
 * @brief         Get the current owner of a semaphore
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance         Instance number
 * @param[in]     u8GateIndex         Index of the selected gate
 * @return        uint8 - index of the semaphore owner, or SEMA42_IP_UNLOCKED_GATE
 *                        if the gate is not locked.
 * @return       uint8
 * @retval       uint8                index of the semaphore owner, or SEMA42_IP_UNLOCKED_GATE if the gate is not locked.
 *
 * @api
 *
 * @pre
 *
 */
uint8 Sema42_Ip_GetGateLocker(const uint32 u32Instance,
                              const uint8 u8GateIndex)
{
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    return (uint8)OsIf_Trusted_Call_Return2param(Sema42_Ip_GetGateLocker_Privileged, u32Instance, u8GateIndex);
#else
    return Sema42_Ip_GetGateLocker_Privileged(u32Instance, u8GateIndex);
#endif
}

/**
 * @brief         Check if the current state of the reset gate state machine is idle.
 *
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance          Instance number
 *
 * @return        boolean
 * @retval        TRUE                if the reset gate is idle
 * @retval        FALSE               if the reset gate is waiting for the second write or if it is actively resseting a gate
 *
 * @api
 *
 * @pre
 *
 */
boolean Sema42_Ip_IsResetGateStateIdle(const uint32 u32Instance)
{
    uint32 gateStatus;
    boolean result;
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    gateStatus = OsIf_Trusted_Call_Return1param(Sema42_Ip_IsResetGateStateIdle_Privileged, u32Instance);
#else
    gateStatus = Sema42_Ip_IsResetGateStateIdle_Privileged(u32Instance);
#endif
    if (gateStatus != SEMA42_IP_RESET_GATE_IDLE)
    {
        result = FALSE;
    }
    else
    {
        result = TRUE;
    }

    return result;
}

/**
 * @brief         Get the bus master which initiated the most recent write operation
 *                on the reset register.
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance: instance number
 * @return        uint8   - Id of the domain which requested the most recent reset
 *
 * @api
 *
 * @pre
 *
 */
uint8 Sema42_Ip_GetResetGateBusMaster(const uint32 u32Instance)
{
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    return (uint8)OsIf_Trusted_Call_Return1param(Sema42_Ip_GetResetGateBusMaster_Privileged, u32Instance);
#else
    return Sema42_Ip_GetResetGateBusMaster_Privileged(u32Instance);
#endif
}

/**
 * @brief         Get the index of the gate targetted by the most recent reset attempt.
 * @details       This function is reentrant
 *
 * @param[in]     u32Instance: instance number
 * @return        uint8 : index of the gate targeted for reset
 *
 * @api
 *
 * @pre
 *
 */
uint8 Sema42_Ip_GetResetGateIndex(const uint32 u32Instance)
{
#ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
    return (uint8)OsIf_Trusted_Call_Return1param(Sema42_Ip_GetResetGateIndex_Privileged, u32Instance);
#else
    return Sema42_Ip_GetResetGateIndex_Privileged(u32Instance);
#endif
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* if (SEMA42_IP_SUPPORT == STD_ON) */
#endif /* SEMA42_IP_SUPPORT ENABLE */

#ifdef __cplusplus
}
#endif

/** @} */
