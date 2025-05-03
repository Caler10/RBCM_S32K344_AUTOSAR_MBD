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

#ifndef MEM_43_INFLS_H
#define MEM_43_INFLS_H

/**
 * @file       Mem_43_INFLS.h
 *
 * @defgroup   MEM_43_INFLS MEM_43_INFLS Driver
 * @implements Mem_43_INFLS.h_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_INFLS_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_VENDOR_ID                      43
#define MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_INFLS_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_INFLS_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_INFLS_SW_MAJOR_VERSION               5
#define MEM_43_INFLS_SW_MINOR_VERSION               0
#define MEM_43_INFLS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mem_43_INFLS_Cfg.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID != MEM_43_INFLS_VENDOR_ID_CFG)
    #error "Mem_43_INFLS.h and Mem_43_INFLS_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Cfg.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS.h and Mem_43_INFLS_Cfg.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Cfg.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION != MEM_43_INFLS_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_SW_MINOR_VERSION != MEM_43_INFLS_SW_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_SW_PATCH_VERSION != MEM_43_INFLS_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_INFLS.h and Mem_43_INFLS_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*When multicore type3 is enabled on MemAcc, global variables must be allocated to share memory section */
#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_INFLS_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_INFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_INFLS_MemMap.h"

/* Pointer to current mem internal flash module configuration set */
extern const Mem_43_INFLS_ConfigType            *Mem_43_INFLS_pConfigPtr;


#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_INFLS_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_INFLS_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes Mem_43_INFLS module.
 */
void Mem_43_INFLS_Init(const Mem_43_INFLS_ConfigType* ConfigPtr);


/**
 * @brief        The function de-initializes the Mem_43_INFLS module.
 */
void Mem_43_INFLS_DeInit(void);


/**
 * @brief        Return the version information of the Mem module.
 */
void Mem_43_INFLS_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr);


/**
 * @brief        Returns the result of the most recent job.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_GetJobResult(Mem_43_INFLS_InstanceIdType InstanceId);

/**
 * @brief        Suspends active memory operation using hardware mechanism.
 */
Std_ReturnType Mem_43_INFLS_Suspend(Mem_43_INFLS_InstanceIdType InstanceId);

/**
 * @brief        Resumes suspended memory operation using hardware mechanism.
 */
Std_ReturnType Mem_43_INFLS_Resume(Mem_43_INFLS_InstanceIdType InstanceId);

/**
 * @brief        Propagates an ECC error to the memory upper layers
 */
void Mem_43_INFLS_PropagateError(Mem_43_INFLS_InstanceIdType InstanceId);


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Reads from flash memory.
 */
Std_ReturnType Mem_43_INFLS_Read(Mem_43_INFLS_InstanceIdType    InstanceId,
                                 Mem_43_INFLS_AddressType       SourceAddress,
                                 Mem_43_INFLS_DataType          *DestinationDataPtr,
                                 Mem_43_INFLS_LengthType        Length
                                );

/**
 * @brief            Writes to flash memory.
 */
Std_ReturnType Mem_43_INFLS_Write(Mem_43_INFLS_InstanceIdType     InstanceId,
                                  Mem_43_INFLS_AddressType        TargetAddress,
                                  const Mem_43_INFLS_DataType     *SourceDataPtr,
                                  Mem_43_INFLS_LengthType         Length
                                 );


/**
 * @brief            Erase one or more complete flash sectors.
 */
Std_ReturnType Mem_43_INFLS_Erase(Mem_43_INFLS_InstanceIdType    InstanceId,
                                  Mem_43_INFLS_AddressType       TargetAddress,
                                  Mem_43_INFLS_LengthType        Length
                                 );


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 */
Std_ReturnType Mem_43_INFLS_BlankCheck(Mem_43_INFLS_InstanceIdType    InstanceId,
                                       Mem_43_INFLS_AddressType       TargetAddress,
                                       Mem_43_INFLS_LengthType        Length
                                      );


/**
 * @brief            Trigger a hardware specific service.
 */
Std_ReturnType Mem_43_INFLS_HwSpecificService(Mem_43_INFLS_InstanceIdType     instanceId,
                                              Mem_43_INFLS_HwServiceIdType    hwServiceId,
                                              Mem_43_INFLS_DataType         * dataPtr,
                                              Mem_43_INFLS_LengthType       * lengthPtr
                                             );
/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 */
void Mem_43_INFLS_MainFunction(void);


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_INFLS_H */
