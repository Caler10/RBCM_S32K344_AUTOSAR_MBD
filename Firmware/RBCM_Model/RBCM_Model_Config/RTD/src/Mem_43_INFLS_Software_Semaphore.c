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

/**
*   @file Mem_43_INFLS_Software_Semaphore.c
*
*   @addtogroup Mem_43_INFLS Driver
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
#include "Mem_43_INFLS_Software_Semaphore.h"
#if (STD_ON == MEM_43_INFLS_USING_SW_SEMAPHORE)
#include "Osif_Software_Semaphore.h"
#endif
#if (STD_ON == MEM_43_INFLS_USE_XRDC_CONFIG)
#include "CDD_Rm.h"
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_VENDOR_ID_C                       43
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION_C        4
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION_C        7
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION_C     0
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION_C                5
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION_C                0
#define MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_INFLS Software Semaphore header file are of the same vendor */
#if (MEM_43_INFLS_SOFTWARE_SEMAPHORE_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID_CFG_DEFINES)
    #error "Mem_43_INFLS_Software_Semaphore.c and Mem_43_INFLS_Software_Semaphore.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS Software Semaphore header file are of the same Autosar version */
#if ((MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Software_Semaphore.c and Mem_43_INFLS_Software_Semaphore.h are different"
#endif
/* Check if current file and Mem_43_INFLS Software Semaphore header file are of the same software version */
#if ((MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION_C != MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION_C != MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION_C != MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Software_Semaphore.c and Mem_43_INFLS_Software_Semaphore.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (STD_ON == MEM_43_INFLS_USING_SW_SEMAPHORE)

/* Checks against Osif_Software_Semaphore.h */
#if (MEM_43_INFLS_SOFTWARE_SEMAPHORE_VENDOR_ID_C != OSIF_SOFTWARE_SEMAPHORE_VENDOR_ID_H)
    #error "Mem_43_INFLS_Software_Semaphore.c and Osif_Software_Semaphore.h have different vendor ids"
#endif
#if ((MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION_C    != OSIF_SOFTWARE_SEMAPHORE_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION_C    != OSIF_SOFTWARE_SEMAPHORE_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION_C != OSIF_SOFTWARE_SEMAPHORE_AR_RELEASE_REVISION_VERSION_H))
    #error "AUTOSAR Version Numbers of Mem_43_INFLS_Software_Semaphore.c and Osif_Software_Semaphore.h are different"
#endif
#if ((MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION_C != OSIF_SOFTWARE_SEMAPHORE_SW_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION_C != OSIF_SOFTWARE_SEMAPHORE_SW_MINOR_VERSION_H) || \
     (MEM_43_INFLS_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION_C != OSIF_SOFTWARE_SEMAPHORE_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Software_Semaphore.c and Osif_Software_Semaphore.h are different"
#endif

#endif
#endif
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/* Get the current DomainID. */
#if (STD_ON == MEM_43_INFLS_USE_XRDC_CONFIG)

#define MEM_43_INFLS_DOMAINID          (Rm_XrdcGetDomainID(0U))

#else

#define MEM_43_INFLS_DOMAINID          (0U)

#endif
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

#if (STD_ON == MEM_43_INFLS_USING_SW_SEMAPHORE)

#define MEM_43_INFLS_START_SEC_VAR_INIT_32
#include "Mem_43_INFLS_MemMap.h"

static uint32 *Mem_43_INFLS_Software_Semaphore_Gate = MEM_43_INFLS_SOFTWARE_SEMAPHOREGATE;

#define MEM_43_INFLS_STOP_SEC_VAR_INIT_32
#include "Mem_43_INFLS_MemMap.h"

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
#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

/**
 * @brief
 * @details
 *
 * @param[in]        void
 *
 * @return           Fls_Software_Sema4_RequestLock
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

Std_ReturnType Mem_43_INFLS_Software_Semaphore_RequestLock(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint8 DomainID = MEM_43_INFLS_DOMAINID;

    if (*Mem_43_INFLS_Software_Semaphore_Gate == OSIF_SOFTWARE_SEMAPHORE_UNLOCKED_VALUE)
    {
        if (TRUE != Osif_Software_Semaphore_Lock(Mem_43_INFLS_Software_Semaphore_Gate, (DomainID + 1U)))
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
    }

    return RetVal;
}

/* Cleanup function, called: at the end of the job(successful or erroneous) and in canceled jobs, to clean all sema4s acquired by this core.*/
Std_ReturnType Mem_43_INFLS_Software_Semaphore_ReleaseLock(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint8 DomainID = MEM_43_INFLS_DOMAINID;

    /* If the SEMA4 is not NULL, try to clear it. */
    if (Mem_43_INFLS_Software_Semaphore_Gate != NULL_PTR)
    {
        if (TRUE != Osif_Software_Semaphore_Unlock(Mem_43_INFLS_Software_Semaphore_Gate, (DomainID + 1U)))
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
    }

    return RetVal;
}

#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

#endif /* #if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)*/

#ifdef __cplusplus
}
#endif

/** @} */
