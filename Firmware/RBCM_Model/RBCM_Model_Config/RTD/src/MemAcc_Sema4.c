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

/**
*   @file MemAcc_Sema4.c
*
*   @addtogroup MEMACC Driver
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
#include "MemAcc_Types.h"
#include "MemAcc_Sema4.h"
#include "MemAcc_Cfg.h"
#if (STD_ON == MEMACC_MULTICORE_TYPE_1_ENABLED)
#include "CDD_Rm.h"
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_SEMA4_VENDOR_ID_C                      43
#define MEMACC_SEMA4_AR_RELEASE_MAJOR_VERSION_C       4
#define MEMACC_SEMA4_AR_RELEASE_MINOR_VERSION_C       7
#define MEMACC_SEMA4_AR_RELEASE_REVISION_VERSION_C    0
#define MEMACC_SEMA4_SW_MAJOR_VERSION_C               5
#define MEMACC_SEMA4_SW_MINOR_VERSION_C               0
#define MEMACC_SEMA4_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == MEMACC_MULTICORE_TYPE_1_ENABLED)
/* Check if current file and MemAcc_Cfg.h file are of the same vendor */
#if (MEMACC_SEMA4_VENDOR_ID_C != MEMACC_VENDOR_ID_CFG)
    #error "MemAcc_Sema4.h and MemAcc_Cfg.c have different vendor ids"
#endif
/* Check if current file and MemAcc_Cfg.h file are of the same Autosar version */
#if ((MEMACC_SEMA4_AR_RELEASE_MAJOR_VERSION_C    != MEMACC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEMACC_SEMA4_AR_RELEASE_MINOR_VERSION_C    != MEMACC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEMACC_SEMA4_AR_RELEASE_REVISION_VERSION_C != MEMACC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of MemAcc_Sema4.c and MemAcc_Cfg.h are different"
#endif
/* Check if current file and MemAcc_Cfg.h file are of the same software version */
#if ((MEMACC_SEMA4_SW_MAJOR_VERSION_C != MEMACC_SW_MAJOR_VERSION_CFG) || \
     (MEMACC_SEMA4_SW_MINOR_VERSION_C != MEMACC_SW_MINOR_VERSION_CFG) || \
     (MEMACC_SEMA4_SW_PATCH_VERSION_C != MEMACC_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of MemAcc_Sema4.c and MemAcc_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and CDD_Rm.h header file are of the same Autosar version */
#if ((MEMACC_SEMA4_AR_RELEASE_MAJOR_VERSION_C != RM_AR_RELEASE_MAJOR_VERSION) || \
        (MEMACC_SEMA4_AR_RELEASE_MINOR_VERSION_C != RM_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of MemAcc_Sema4.c and CDD_Rm.h are different"
#endif
#endif

#endif  /*(STD_ON == MEMACC_MULTICORE_TYPE_1_ENABLED)*/
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#if (MEMACC_MULTICORE_TYPE_1_ENABLED == STD_ON)
#define MEMACC_START_SEC_VAR_INIT_8
#include "MemAcc_MemMap.h"

static const uint8 Memacc_u8Sema4Gate[MEMACC_MEM_HW_RESOURCE_COUNT] = MEMACC_SEMA4GATE;

#define MEMACC_STOP_SEC_VAR_INIT_8
#include "MemAcc_MemMap.h"

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
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h"

/**
 * @brief
 * @details
 *
 * @param[in]        void
 *
 * @return           MemAcc_Sema4_RequestLock
 * @retval           E_NOT_OK         Error during attempt of getting exclusive access(abnormal sema4 behaviour, incorrect exclusive area implementation, etc)
 * @retval           E_OK       Sema4 taken, exclusive access granted
 *
 *
 * @pre              The module has to be initialized and not busy.
 * @pre              The requested job has to be set.
 * @pre              The requested priority for this job has to be set(Normal, High prio).
 * @post             Status of current job is known: error,timeout -> abort job, pending -> delay job, granted -> start/continue job in hardware.
 *
 *
 *
 */

Std_ReturnType MemAcc_Sema4_RequestLock(uint8 MemHwResource)
{
    uint8 GetGateStatus;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint8 Sema4Gate;

    /* Get the Sema4 Gate for the hardware resource*/
    Sema4Gate = Memacc_u8Sema4Gate[MemHwResource];

    GetGateStatus = Rm_SemaphoreGetStatus(Sema4Gate);

    if (RM_SEMAPHORE_FREE == GetGateStatus)
    {
        RetVal = Rm_SemaphoreLockGate(Sema4Gate);
    }
    else
    {
        /* The other core has the job SEMA4. */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

/* Cleanup function, called: at the end of the job(successful or erroneous) and in canceled jobs, to clean all sema4s acquired by this core.*/
void MemAcc_Sema4_ReleaseLock(uint8 MemHwResource)
{
    uint8 Sema4Gate;
    /* Get the Sema4 Gate for the hardware resource*/
    Sema4Gate = Memacc_u8Sema4Gate[MemHwResource];

    /* If the internal job SEMA4 is held by this core, clear it. */
    if ((uint8)Rm_XrdcGetDomainID(0U) == Rm_SemaphoreGetStatus(Sema4Gate))
    {
        (void)Rm_SemaphoreUnlockGate(Sema4Gate);
    }

}

Std_ReturnType MemAcc_Sema4_InitLock(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint8 index = 0U;

    for (index = 0; index < MEMACC_MEM_HW_RESOURCE_COUNT; index++)
    {
        /* Request the hardware resource in multi core mode */
        RetVal = MemAcc_Sema4_RequestLock(index);

        if (E_NOT_OK == RetVal)
        {
            break;
        }
    }
    return RetVal;
}

/* Release the taken SEMA4s after the hardware initialization */
void MemAcc_Sema4_InitUnLock(void)
{
    uint8 index = 0U;

    for (index = 0; index < MEMACC_MEM_HW_RESOURCE_COUNT; index++)
    {
        /* Release the hardware resource in multi core mode */
        (void)MemAcc_Sema4_ReleaseLock(index);
    }
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h"

#endif /* #if (MEMACC_MULTICORE_TYPE_1_ENABLED == STD_ON)*/

#ifdef __cplusplus
}
#endif

/** @} */
