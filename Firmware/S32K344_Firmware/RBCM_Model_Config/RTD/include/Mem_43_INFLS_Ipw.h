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

#ifndef MEM_43_INFLS_IPW_H
#define MEM_43_INFLS_IPW_H

/**
 * @file       Mem_43_INFLS_Ipw.h
 *
 * @addtogroup MEM_43_INFLS Driver
 * implement   Mem_43_INFLS_Ipw.h_Artifact
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
#include "Mem_43_INFLS_Types.h"
#include "OsIf.h"

#if (STD_ON == MEM_43_INFLS_USE_XRDC_CONFIG)
#include "CDD_Rm.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_IPW_VENDOR_ID                       43
#define MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION        4
#define MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION        7
#define MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION     0
#define MEM_43_INFLS_IPW_SW_MAJOR_VERSION                5
#define MEM_43_INFLS_IPW_SW_MINOR_VERSION                0
#define MEM_43_INFLS_IPW_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_INFLS_Types.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID != MEM_43_INFLS_TYPES_VENDOR_ID)
    #error "Mem_43_INFLS_Ipw.h and Mem_43_INFLS_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Types.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION    != MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION    != MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION != MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.h and Mem_43_INFLS_Types.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Types.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION != MEM_43_INFLS_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION != MEM_43_INFLS_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION != MEM_43_INFLS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.h and Mem_43_INFLS_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.h and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/
/* Baremetal Specific */
#if (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)
    #define ARM_FAR_CALL2THUMB_CODE_BIT0_U32 (0x00000001UL)
    /* Macro for Access Code Call. On ARM/Thumb, BLX instruction used by the compiler for calling a function
    pointed to by the pointer requires that LSB bit of the address is set to one if the called fcn is coded in Thumb. */
    #define MEM_43_INFLS_AC_CALL(ptr2fcn, ptr2fcnType) ((ptr2fcnType)(((uint32)(ptr2fcn)) | ARM_FAR_CALL2THUMB_CODE_BIT0_U32))
#else
    #define MEM_43_INFLS_AC_CALL(ptr2fcn, ptr2fcnType) (ptr2fcn)
#endif /* #if (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH) */

/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


/**
 * @brief       Initialize the hardware resources.
 * @details
 *
 * @return      Std_ReturnType
 */
Std_ReturnType Mem_43_INFLS_IPW_Init(void);

/**
 * @brief       IP wrapper erase function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Erase(uint32 InstanceIndex,
                                                  Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                 );


/**
 * @brief       IP wrapper write function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Write(uint32 InstanceIndex,
                                                  Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                 );


/**
 * @brief       IP wrapper read function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Read(uint32 InstanceIndex,
                                                 Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                );


#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
/**
 * @brief       IP wrapper Compare function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Compare(uint32 InstanceIndex,
                                                    Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                   );
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */


/**
 * @brief       IP wrapper blank check function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_BlankCheck(uint32 InstanceIndex,
                                                       Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                      );


/**
 * @brief       Returns synchronously the result of the last job.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobType             Job Erase or Write.
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_GetJobResult(uint32 InstanceIndex,
                                                         Mem_43_INFLS_JobRuntimeInfoType * JobInfo
                                                        );

/**
 * @brief       Cancel an ongoing flash read, write, erase or compare job.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Cancel(uint32 InstanceIndex);


/**
 * @brief Report ECC Error value result for IP Layer.
 */
void Mem_43_INFLS_IPW_ReportEccValueToLayerUnder(void);


#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_ArrayIntegrityCheckResume(uint32 InstanceIndex);
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_ArrayIntegrityCheckSuspend(uint32 InstanceIndex);
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_ArrayIntegrityCheck(uint32 InstanceIndex,
                                                                Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                               );
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_UserMarginReadCheck(uint32 InstanceIndex,
                                                                Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                               );
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_EccLogicCheck
(
    const Mem_43_INFLS_EccLogicCheckDataType *EccCheckData
);

Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_EdcAfterEccLogicCheck
(
    const Mem_43_INFLS_EccLogicCheckDataType *EccCheckData
);

Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_AddressEncodeLogicCheck
(
    const Mem_43_INFLS_AddressEncodeDataType *AddressEncodeData
);
#endif

#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_INFLS_IPW_H */
