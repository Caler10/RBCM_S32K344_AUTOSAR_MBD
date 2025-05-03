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
 * @file       Mem_43_INFLS.c
 *
 * @addtogroup MEM_43_INFLS
 * @implements Mem_43_INFLS.c_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_INFLS.h"
#include "Mem_43_INFLS_Ipw.h"

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#include "SchM_Mem_43_INFLS.h"

#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
#include "Mcal.h"
#endif
#if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)
#include "Mem_43_INFLS_Software_Semaphore.h"
#endif
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_VENDOR_ID_C                      43
#define MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C       4
#define MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C       7
#define MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C    0
#define MEM_43_INFLS_SW_MAJOR_VERSION_C               5
#define MEM_43_INFLS_SW_MINOR_VERSION_C               0
#define MEM_43_INFLS_SW_PATCH_VERSION_C               0

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    #if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_INFLS.c and Det.h are different"
    #endif
    #endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */

    /* Check if current file and SchM_Fls header file are of the same Autosar version */
    #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != SCHM_MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != SCHM_MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_INFLS.c and SchM_Mem_43_INFLS.h are different"
    #endif

    #if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
    /* Check if current file  and Mcal.h are of the same version */
        #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
             (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Mem_43_INFLS.c and Mcal.h are different"
        #endif
    #endif
#endif

/* Check if current file and Mem_43_INFLS.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "Mem_43_INFLS.c and Mem_43_INFLS.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS.h are different"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS.h are different"
#endif

/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_C != MEM_43_INFLS_IPW_VENDOR_ID)
    #error "Mem_43_INFLS.c and Mem_43_INFLS_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS_Ipw.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_C != MEM_43_INFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_C != MEM_43_INFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_C != MEM_43_INFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS_Ipw.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_INFLS_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_INFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_INFLS_MemMap.h"

/* Pointer to current mem internal flash module configuration set */
const Mem_43_INFLS_ConfigType              *Mem_43_INFLS_pConfigPtr;

/* Information of the current processing job of each Mem instance */
static Mem_43_INFLS_JobRuntimeInfoType      Mem_43_INFLS_eJobRuntimeInfo[MEM_43_INFLS_MEM_INSTANCE_COUNT];

#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
/* Information of the current processing job of utest config */
static Mem_43_INFLS_UtestRuntimeConfigType  Mem_43_INFLS_eJobUtestRuntimeInfo[MEM_43_INFLS_MEM_UTESTCONFIG_COUNT];
#endif

#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_INFLS_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_INFLS_MemMap.h"

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*! Specifies invalid mem instance index (valid ones will be in range 0 to MEM_43_INFLS_MEM_INSTANCE_COUNT-1) */
#define MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID              MEM_43_INFLS_MEM_INSTANCE_COUNT

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#if (MEM_43_INFLS_CHECK_CFG_CRC == STD_ON)
/**
 * Pointer to current module configuration set
 */
static uint32 Mem_43_INFLS_u32AccCRCremainder;
#endif /* MEM_43_INFLS_CHECK_CFG_CRC */

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS (internal usage)
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

#if (MEM_43_INFLS_CHECK_CFG_CRC == STD_ON)
static void Mem_43_INFLS_AccumulateCRC(uint32 InputData);
static void Mem_43_INFLS_ResetCRC(void);
static uint32 Mem_43_INFLS_FinalizeCRC(void);
static void Mem_43_INFLS_UpdateCRCreminder(Mem_43_INFLS_CrcDataSizeType DataSize);

static Mem_43_INFLS_CrcType Mem_43_INFLS_CalcCfgCRC(void);
#endif /* MEM_43_INFLS_CHECK_CFG_CRC */

/**
 * @brief    Report a development error
 */
static void Mem_43_INFLS_ReportDevError(Mem_43_INFLS_InstanceIdType InstanceId,
                                        uint32 ApiId,
                                        uint32 ErrorId
                                       )
{
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Raise the development error via Det function */
    (void)Det_ReportError(MEM_43_INFLS_MODULE_ID, (uint8)InstanceId, (uint8)ApiId, (uint8)ErrorId);
#endif

    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
}

#if (MEM_43_INFLS_CHECK_CFG_CRC == STD_ON)
/**
 * @brief        Function to handle cumulative CRC calculation over input data.
 *
 * @details      Handles cumulative CRC calculation over input 32-bit data, .
 *
 * @param[in]    inputData ... data to be CRC-ed
 *
 * @return       void
 * @retval       None.
 *
 * @pre          Mem_43_INFLS_ResetCRC() was executed before the first call of
 *               Mem_43_INFLS_AccumulateCRC().
 *
 *
 */
static void Mem_43_INFLS_AccumulateCRC(uint32 InputData)
{
    if (0xFFFFU < InputData)
    {
        /* preparation for accumulation of higher 16 bits of the InputData */
        Mem_43_INFLS_u32AccCRCremainder = (Mem_43_INFLS_u32AccCRCremainder << 16U) | (InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of Mem_43_INFLS_u32AccCRCremainder) */
        Mem_43_INFLS_UpdateCRCreminder(MEM_43_INFLS_CRC_16_BITS);
    }

    if (0xFFU < InputData)
    {
        /* preparation for accumulation of lower 16 bits of the InputData */
        Mem_43_INFLS_u32AccCRCremainder = (Mem_43_INFLS_u32AccCRCremainder << 16U) | (InputData & 0x0000FFFFU);
        /* make 16-bit accumulated result (in lower 16-bits of Mem_43_INFLS_u32AccCRCremainder) */
        Mem_43_INFLS_UpdateCRCreminder(MEM_43_INFLS_CRC_16_BITS);
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the InputData */
        Mem_43_INFLS_u32AccCRCremainder = (Mem_43_INFLS_u32AccCRCremainder << 8U) | InputData;
        /* make 16-bit accumulated result (in lower 16-bits of Mem_43_INFLS_u32AccCRCremainder) */
        Mem_43_INFLS_UpdateCRCreminder(MEM_43_INFLS_CRC_8_BITS);
    }
}


/**
 * @brief        Function to reset CRC calculation.
 *
 * @details      Resets accumulated Mem_43_INFLS_u32AccCRCremainder.
 *
 * @param[in]    void
 *
 * @return       void
 * @retval       None.
 *
 * @pre          None.
 *
 *
 */
static void Mem_43_INFLS_ResetCRC(void)
{
    Mem_43_INFLS_u32AccCRCremainder = 0U;
}

/**
 * @brief        Function to finalize CRC calculation.
 *
 * @details      Finalizes accumulated CRC computation and resturns the final
 *               CRC checksum.
 *
 * @param[in]    void
 *
 * @return       uint32
 * @retval       The final CRC checksum in the lower 16 bits.
 *
 * @pre          Mem_43_INFLS_AccumulateCRC() was executed at least once before
 *               calling Mem_43_INFLS_FinalizeCRC().
 *
 */
static uint32 Mem_43_INFLS_FinalizeCRC(void)
{
    /* add the final 0x0000 to the remainder */
    Mem_43_INFLS_u32AccCRCremainder = (Mem_43_INFLS_u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */
    Mem_43_INFLS_UpdateCRCreminder(MEM_43_INFLS_CRC_16_BITS);

    return Mem_43_INFLS_u32AccCRCremainder;
}

/**
 * @brief        Function to perform CRC calculation over input 32-bit data.
 *
 * @details      Process 32-bit data to 16-bit reminder.
 *
 * @param[in]    accDataPtr ... ptr to data to be processed
 *
 * @return       void
 * @retval       None.
 *
 * @pre          Can be called only from Mem_43_INFLS_AccumulateCRC().
 *
 */

static void Mem_43_INFLS_UpdateCRCreminder(Mem_43_INFLS_CrcDataSizeType DataSize)
{
    uint32 CrcPolynomSft;
    uint32 LeadingOne;
    uint32 AccDataLoc;
    uint32 LeadingOneInitial;

    switch (DataSize)
    {
        case MEM_43_INFLS_CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;

        case MEM_43_INFLS_CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = Mem_43_INFLS_u32AccCRCremainder;

    /* CRC computation */
    for (LeadingOne = LeadingOneInitial; LeadingOne >= 0x00010000U; LeadingOne >>= 1U)
    {
        if (0U != (AccDataLoc & LeadingOne))
        {
            AccDataLoc ^= CrcPolynomSft;
        }
        CrcPolynomSft >>= 1U;
    }

    /* copy back to static variable */
    Mem_43_INFLS_u32AccCRCremainder = AccDataLoc;
}

/**
 * @brief        Calculates CRC over Fls configuration.
 *
 * @details      Calculates CRC over selected items of Fls configuration set
 *               pointed to by ConfigPtr.
 *
 * @param[in]    ConfigPtr        Pointer to flash driver configuration set.
 *
 * @return       uint32
 * @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
 *
 * @pre          Mem_43_INFLS_pConfigPtr must not be properly initialized.
 *
 */
static Mem_43_INFLS_CrcType  Mem_43_INFLS_CalcCfgCRC(void)
{

    uint32 MemInstanceIndex;
    uint32 SectorBatchIndex;

    /* Reset the accumulated CRC value */
    Mem_43_INFLS_ResetCRC();

    /* Iterate through the MemInstances params */
    for (MemInstanceIndex = 0U; MemInstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; MemInstanceIndex++)
    {
        /* CRC - Accumulate InstanceId */
        Mem_43_INFLS_AccumulateCRC((uint32)(Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].InstanceId));
        /* CRC - Accumulate SectorBatchCount */
        Mem_43_INFLS_AccumulateCRC((uint32)(Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatchCount));

        /* CRC - Accumulate SectorBatches */
        for (SectorBatchIndex =0u; SectorBatchIndex < Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatchCount; SectorBatchIndex++)
        {
            /* CRC - Accumulate StartAddress */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].StartAddress);
            /* CRC - Accumulate EndAddress */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].EndAddress);
            /* CRC - Accumulate SectorSize */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].SectorSize);
            /* CRC - Accumulate ReadPageSize */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].ReadPageSize);
            /* CRC - Accumulate WritePageSize */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].WritePageSize);
            /* CRC - Accumulate EraseBurstSize */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].EraseBurstSize);
            /* CRC - Accumulate ReadBurstSize */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].ReadBurstSize);
            /* CRC - Accumulate WriteBurstSize */
            Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatchIndex].WriteBurstSize);
        }
        #if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
        if (Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].UtestConfig != NULL_PTR)
        {
            /* CRC - Accumulate BlockReceiveCheck */
            Mem_43_INFLS_AccumulateCRC((uint32)(Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].UtestConfig->BlockReceiveCheck));
            /* CRC - Accumulate BreakPointsType */
            Mem_43_INFLS_AccumulateCRC((uint32)(Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].UtestConfig->BreakPointsType));
            /* CRC - Accumulate ArrayIntegritySequenceType */
            Mem_43_INFLS_AccumulateCRC((uint32)(Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].UtestConfig->ArrayIntegritySequenceType));
            /* CRC - Accumulate MarginLevelType */
            Mem_43_INFLS_AccumulateCRC((uint32)(Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].UtestConfig->MarginLevelType));
        }
    #endif
            /* CRC - Accumulate MemUnitIndex */
        Mem_43_INFLS_AccumulateCRC((uint32) Mem_43_INFLS_pConfigPtr->MemInstances[MemInstanceIndex].MemUnitIndex);
    }
    return ((Mem_43_INFLS_CrcType)Mem_43_INFLS_FinalizeCRC());
}
#endif /* #if (MEM_43_INFLS_CHECK_CFG_CRC == STD_ON) */

/**
 * @brief        Calculates CRC over Mem_43_INFLS configuration.
 *
 * @details      Calculates CRC over selected items of Fls configuration set
 *               pointed to by ConfigPtr.
 *
 * @param[in]    ConfigPtr        Pointer to flash driver configuration set.
 *
 * @return       uint32
 * @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
 *
 * @pre          Mem_43_INFLS_pConfigPtr must not be properly initialized.
 *
 */

/**
 * @brief    Computes and checks the CRC over configuration set
 */
static Std_ReturnType Mem_43_INFLS_ValidateConfigCRC(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    #if (MEM_43_INFLS_CHECK_CFG_CRC == STD_ON)
    if (Mem_43_INFLS_pConfigPtr->u16ConfigCrc != Mem_43_INFLS_CalcCfgCRC())
    {
        RetVal         = E_NOT_OK;
    }
    #endif

    return RetVal;
}
/**
 * @brief   Avoid CWE violation
 *
 */
static void Mem_43_INFLS_IncreasePtr(const Mem_43_INFLS_SectorBatchType **sectorPtr)
{
    (*sectorPtr)++;
}

/**
 * @brief    Search the list of Mem instances and returns index of instance with matching InstanceId
 */
static uint32 Mem_43_INFLS_GetInstanceIndex(const Mem_43_INFLS_InstanceIdType InstanceId)
{
    uint32 InstanceIndex = 0U;

    /* Loop through all configured memory instances */
    for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
    {
        if (InstanceId == Mem_43_INFLS_pConfigPtr->MemInstances[InstanceIndex].InstanceId)
        {
            /* InstanceId is matched, exit loop */
            break;
        }
    }

    /* The returned value will be INVALID if InstanceId is not matched with any InstanceIndex */
    return InstanceIndex;
}


/**
 * @brief    Search for the sector batch that contains the provided address
 */
static const Mem_43_INFLS_SectorBatchType *Mem_43_INFLS_GetSectorBatch(uint32 InstanceIndex,
                                                                       Mem_43_INFLS_AddressType Address
                                                                      )
{
    const Mem_43_INFLS_MemInstanceType *MemInstance         = &(Mem_43_INFLS_pConfigPtr->MemInstances[InstanceIndex]);
    const Mem_43_INFLS_SectorBatchType *SectorBatch         = MemInstance->SectorBatches;
    Mem_43_INFLS_AddressType           StartAddressOfSector = 0U;
    Mem_43_INFLS_AddressType           EndAddressOfSector   = 0U;
    uint32 Index = 0U;

    /* Loop through all configured sector batches of this memory instance */
    do
    {
        StartAddressOfSector = (Mem_43_INFLS_AddressType)(SectorBatch->StartAddress);
        EndAddressOfSector   = (Mem_43_INFLS_AddressType)(SectorBatch->EndAddress);
        if ((StartAddressOfSector <= Address) && (Address <= EndAddressOfSector))
        {
            /* The address falls within this sector batch */
            break;
        }

        /* Move to the next sector batch */
        Mem_43_INFLS_IncreasePtr(&SectorBatch);
        Index++;
    }
    while (Index < MemInstance->SectorBatchCount);

    /* The returned value will be NULL_PTR if Address does not fall within any sector batch */
    if (Index >= MemInstance->SectorBatchCount)
    {
        SectorBatch = NULL_PTR;
    }

    return SectorBatch;
}

/**
 * @brief    Checks if the provided address and length are in range and aligned to end of the sector.
 */
static uint32 Mem_43_INFLS_CheckSectorAligned(const Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    uint32 SectorSize = JobRequest->SectorBatch->SectorSize;
    Mem_43_INFLS_AddressType StartAddress  = JobRequest->SectorBatch->StartAddress;
    Mem_43_INFLS_AddressType EndAddress    = JobRequest->SectorBatch->EndAddress;
    Mem_43_INFLS_AddressType TargetAddress = JobRequest->Address;
    Mem_43_INFLS_LengthType  Length        = JobRequest->Length;

    if ((0U != ((TargetAddress - StartAddress) % SectorSize)))
    {
        /* Address of job is not in range or not aligned to start of the sector */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if (0U != ((EndAddress - ((TargetAddress + Length) - 1U)) % SectorSize))
    {
        /* Length of job is not aligned to end of the sector */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_INFLS_E_OK;
    }

    return ErrorId;
}


/**
 * @brief    Checks if the provided address and length are in range and aligned to end of the page.
 */
static uint32 Mem_43_INFLS_CheckWritePageAligned(const Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    uint32 WritePageSize = JobRequest->SectorBatch->WritePageSize;
    Mem_43_INFLS_AddressType StartAddress  = JobRequest->SectorBatch->StartAddress;
    Mem_43_INFLS_AddressType TargetAddress = JobRequest->Address;
    Mem_43_INFLS_LengthType  Length        = JobRequest->Length;
    Mem_43_INFLS_LengthType  SectorOffset  = 0U;

    SectorOffset = (TargetAddress + Length) - StartAddress;

    if (0U != (TargetAddress % WritePageSize))
    {
        /* Address of job is not in range or not aligned to start of the page */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if (0U != (SectorOffset % WritePageSize))
    {
        /* Length of job is not aligned to end of the page */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_INFLS_E_OK;
    }

    return ErrorId;
}


/**
 * @brief    Checks if the provided address and length are valid
 */
static uint32 Mem_43_INFLS_ValidateAddressAndLength(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    JobRequest->SectorBatch = Mem_43_INFLS_GetSectorBatch(JobRequest->InstanceIndex, JobRequest->Address);
    if (NULL_PTR == JobRequest->SectorBatch)
    {
        /* Could not find the sector batch, the address is invalid */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ((0U == JobRequest->Length) ||
             ((JobRequest->Address + JobRequest->Length - 1U) > JobRequest->SectorBatch->EndAddress)
            )
    {
        /* The length is invalid */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        switch (JobRequest->JobType)
        {
        case MEM_43_INFLS_JOB_ERASE:
            ErrorId = Mem_43_INFLS_CheckSectorAligned(JobRequest);
            break;
        case MEM_43_INFLS_JOB_WRITE:
            ErrorId = Mem_43_INFLS_CheckWritePageAligned(JobRequest);
            break;

        default:
            /* Both address and length are valid */
            ErrorId = MEM_43_INFLS_E_OK;
            break;
        }
    }

    return ErrorId;
}


/**
 * @brief    Checks if provided InstanceId is consistent with the configuration
 */
static uint32 Mem_43_INFLS_ValidateInstanceId(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

    /* Get the mem index number according to the mem instance id */
    JobRequest->InstanceIndex = Mem_43_INFLS_GetInstanceIndex(JobRequest->InstanceId);

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID == JobRequest->InstanceIndex)
    {
        /* The provided InstanceId is inconsistent with the configuration */
        ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
    }
#endif

    return ErrorId;
}


/**
 * @brief    Checks if the Mem module has been initialized.
 */
static inline uint32 Mem_43_INFLS_ValidateModuleInitialized(void)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (NULL_PTR == Mem_43_INFLS_pConfigPtr)
    {
        /* The Mem module has not been initialized */
        ErrorId = MEM_43_INFLS_E_UNINIT;
    }
#endif

    return ErrorId;
}


/**
 * @brief    Common checks of input parameters for driver APIs.
 */
static uint32 Mem_43_INFLS_ValidateParamJobCommon(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the provided InstanceId is consistent with the configuration */
        ErrorId = Mem_43_INFLS_ValidateInstanceId(JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the address and the length are valid */
        ErrorId = Mem_43_INFLS_ValidateAddressAndLength(JobRequest);
    }

    return ErrorId;
}

/**
 * @brief    Checks if the input argument is a NULL pointer.
 */
static inline uint32 Mem_43_INFLS_ValidateDataPointer(const Mem_43_INFLS_DataType *DataPtr)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

    if (NULL_PTR == DataPtr)
    {
        /* The DataPtr argument is a NULL pointer */
        ErrorId = MEM_43_INFLS_E_PARAM_POINTER;
    }

    return ErrorId;
}


/**
 * @brief    Checks the input parameters for data transfer jobs (read, write)
 */
static uint32 Mem_43_INFLS_ValidateParamJobDataTransfer(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Perform the common checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobCommon(JobRequest);

    /* Perform the specific checking */
    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        ErrorId = Mem_43_INFLS_ValidateDataPointer(JobRequest->DataPtr);
    }

    return ErrorId;
}

/**
 * @brief    Initialize the input parameter for the new job request
 */
static void Mem_43_INFLS_InitJobRequest(Mem_43_INFLS_JobRuntimeInfoType    *JobRequest,
                                        Mem_43_INFLS_InstanceIdType         InstanceId,
                                        Mem_43_INFLS_AddressType            Address,
                                        Mem_43_INFLS_DataType              *DataPtr,
                                        Mem_43_INFLS_LengthType             Length
                                       )
{
    /* Input value */
    JobRequest->InstanceId       = InstanceId;
    JobRequest->HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_INVALID;
    JobRequest->Address          = Address;
    JobRequest->DataPtr          = DataPtr;
    JobRequest->Length           = Length;
    /* Default value */
    JobRequest->InstanceIndex    = MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID;
    JobRequest->SectorBatch      = NULL_PTR;
#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
    JobRequest->UtestConfigIndex = 0U;
    JobRequest->UtestRuntime     = NULL_PTR;
#endif /* (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON) */

    /* Prepare for a new job */
    JobRequest->JobFlags         = MEM_43_INFLS_JOB_FLAG_STARTED;
    JobRequest->JobResult        = MEM_43_INFLS_JOB_PENDING;
#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
    JobRequest->PartitionId      = OsIf_GetUserId();
#endif
}
#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
/**
 * @brief    Get utest config
 */
static const Mem_43_INFLS_UtestConfigType *Mem_43_INFLS_GetUtestConfig(uint32 InstanceIndex)
{
    const Mem_43_INFLS_MemInstanceType *MemInstance         = &(Mem_43_INFLS_pConfigPtr->MemInstances[InstanceIndex]);
    const Mem_43_INFLS_UtestConfigType *UtestConfig         = MemInstance->UtestConfig;

    return UtestConfig;
}
/**
 * @brief    Checks the input parameters for data transfer jobs for utest mode
 */
static uint32 Mem_43_INFLS_ValidateParamJobDataTransferForUtestMode(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Perform the common checking */
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the provided InstanceId is consistent with the configuration */
        ErrorId = Mem_43_INFLS_ValidateInstanceId(JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the address and the length are valid */
        JobRequest->UtestRuntime->UtestConfig = Mem_43_INFLS_GetUtestConfig(JobRequest->InstanceIndex);
        if (NULL_PTR == JobRequest->UtestRuntime->UtestConfig)
        {
            /* The UtestConfig argument is a NULL pointer */
            ErrorId = MEM_43_INFLS_E_PARAM_POINTER;
        }
    }

    return ErrorId;
}

#endif /* (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON) */
/**
 * @brief    Check if the mem instance is idle and configure the new job request
 */
static uint32 Mem_43_INFLS_ConfigureJobRequest(const Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Start of exclusive area */
    SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_01();

    if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[JobRequest->InstanceIndex].JobResult)
    {
        /* A previous job is still being processed */
        ErrorId = MEM_43_INFLS_E_JOB_PENDING;
    }
    else
    {
        /* Accept the requested job */
        ErrorId = MEM_43_INFLS_E_OK;
        /* Configure the new job */
        Mem_43_INFLS_eJobRuntimeInfo[JobRequest->InstanceIndex] = *JobRequest;
    }

    /* End of exclusive area */
    SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_01();

    return ErrorId;
}

/**
* @brief        Process the HwSpecificService job
*
* @details      Process the HwSpecificService job with the corresponding serviceID stored in the variable JobInfo.HwServiceIdJob
*
*/
static Mem_43_INFLS_JobResultType Mem_43_INFLS_ProcessHwSpecificServiceJob(uint32 InstanceIndex, Mem_43_INFLS_JobRuntimeInfoType* JobInfo)
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;

    if (MEM_43_INFLS_HWSERVICEID_CANCEL == JobInfo->HwServiceIdJob)
    {
        /* Update job JobResult to MEM_43_INFLS_JOB_OK */
        JobResult = MEM_43_INFLS_JOB_OK;
        /* Update length  - with this job length is unuse, it only need use for first loop */
        JobInfo->Length = 0;
    }
#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
    if (MEM_43_INFLS_HWSERVICEID_COMPARE == JobInfo->HwServiceIdJob)
    {
        JobResult = Mem_43_INFLS_IPW_Compare(InstanceIndex, JobInfo);
    }
#endif
#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
switch (JobInfo->HwServiceIdJob)
{
    case MEM_43_INFLS_HWSERVICEID_ARRAY_INTEGRITY_CHECK:
        JobResult = Mem_43_INFLS_IPW_ArrayIntegrityCheck(InstanceIndex, JobInfo);
        /* Update length  - with this job length is unuse, it only need use for first loop */
        JobInfo->Length = 0;
        break;
    case MEM_43_INFLS_HWSERVICEID_USER_MARGIN_READ_CHECK:
        JobResult = Mem_43_INFLS_IPW_UserMarginReadCheck(InstanceIndex, JobInfo);
        /* Update length  - with this job length is unuse, it only need use for first loop */
        JobInfo->Length = 0;
        break;
    case MEM_43_INFLS_HWSERVICEID_ECC_LOGIC_CHECK:
        JobResult = Mem_43_INFLS_IPW_EccLogicCheck(JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].UtestEdcEccLogicCheck);
        /* Update length  - with this job length is unuse, it only need use for first loop */
        JobInfo->Length = 0;
        break;
    case MEM_43_INFLS_HWSERVICEID_EDC_AFTER_ECC_LOGIC_CHECK:
        JobResult = Mem_43_INFLS_IPW_EdcAfterEccLogicCheck(JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].UtestEdcEccLogicCheck);
        /* Update length  - with this job length is unuse, it only need use for first loop */
        JobInfo->Length = 0;
        break;
    case MEM_43_INFLS_HWSERVICEID_ADDRESS_ENCODE_LOGIC_CHECK:
        JobResult = Mem_43_INFLS_IPW_AddressEncodeLogicCheck(JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].UtestAddressEncodeCheck);
        /* Update length  - with this job length is unuse, it only need use for first loop */
        JobInfo->Length = 0;
        break;
    default:
        /*Do nothing*/
        break;
}
#endif
    (void)InstanceIndex;
    (void)JobInfo;

    return JobResult;
}

/**
 * @brief   Decides which sub-function to call based on the job type:
 *          Modify (Write, Erase) or Read (Read, BlankCheck).
 */
static Mem_43_INFLS_JobResultType Mem_43_INFLS_DoRequestedJobs(uint32 InstanceIndex,
                                                               Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                              )
{
    /* Assume no more data to process, previous asynchronous job completed successfully */
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_OK;

    if (0U != JobInfo->Length)
    {
        /* Call Low-level driver to work with physical flash device
         * Process the maximum length depending on the hardware capabilities, or until a sector boundary
         */
        switch (JobInfo->JobType)
        {
            case MEM_43_INFLS_JOB_ERASE:
                JobResult = Mem_43_INFLS_IPW_Erase(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_WRITE:
                JobResult = Mem_43_INFLS_IPW_Write(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_READ:
                JobResult = Mem_43_INFLS_IPW_Read(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_HWSPECIFICSERVICE:
                /* Process hw specific service job */
                JobResult = Mem_43_INFLS_ProcessHwSpecificServiceJob(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_BLANK_CHECK:
                JobResult = Mem_43_INFLS_IPW_BlankCheck(InstanceIndex, JobInfo);
                break;

            default:  /* MEM_43_INFLS_JOB_NONE */
                JobResult = MEM_43_INFLS_JOB_FAILED;
                break;
        };
        /* if This is Read/Compare/BlankCheck Jobs */
        if (((MEM_43_INFLS_JOB_OK == JobResult) || (MEM_43_INFLS_ECC_CORRECTED == JobResult))  && (0U != JobInfo->Length))
        {
            /* The current chunk has completed but there is still data to process, need more MainFunction calls */
            JobResult = MEM_43_INFLS_JOB_PENDING;
        }
    }
    return JobResult;
}


/**
 * @brief    Process the pending job for the mem instance
 */
static void Mem_43_INFLS_ProcessRequestedJobs(uint32 InstanceIndex)
{
    Mem_43_INFLS_JobRuntimeInfoType *JobInfo = &(Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex]);
    Mem_43_INFLS_JobResultType     JobResult = MEM_43_INFLS_JOB_OK;

    if ((JobInfo->JobFlags & MEM_43_INFLS_JOB_FLAG_STARTED) != 0U)
    {
        /* Clear flag */
        JobInfo->JobFlags &=  ~((uint8)MEM_43_INFLS_JOB_FLAG_STARTED);
    }
    else
    {
        /* Check the status of the job is being processed in the low-level driver */
        JobResult = Mem_43_INFLS_IPW_GetJobResult(InstanceIndex, JobInfo);
    }
    /* The case MEM_43_INFLS_ECC_CORRECTED == JobResult can be true when enable EraseVerify/ProgramVerify of Erase/Write job */
    if (((MEM_43_INFLS_JOB_OK == JobResult) || (MEM_43_INFLS_ECC_CORRECTED == JobResult)) && (0U != JobInfo->Length))
    {
        /* The previous pending job has been done, launch new operation */
        JobResult = Mem_43_INFLS_DoRequestedJobs(InstanceIndex, JobInfo);
    }

    /* Start of exclusive area */
    SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_06();

    if (MEM_43_INFLS_ECC_UNCORRECTED == JobResult)
    {
        /* abort pending job */
        JobInfo->JobType = MEM_43_INFLS_JOB_NONE;
    }

    /* Update the latest job result */
    JobInfo->JobResult = JobResult;

    /* End of exclusive area */
    SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_06();
}

static Std_ReturnType Mem_43_INFLS_Cancel(Mem_43_INFLS_InstanceIdType    InstanceId
                                          )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 InstanceIndex;

    InstanceIndex = Mem_43_INFLS_GetInstanceIndex(InstanceId);

    if ((InstanceIndex          != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
    && ((MEM_43_INFLS_JOB_ERASE == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobType)
    ||  (MEM_43_INFLS_JOB_WRITE == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobType)))
    {
        /* Check if there was a pending job in each instance */
        if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
        {
            /* Start of exclusive area */
            SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_02();

            /* Configure the new job request to global runtime variable */
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobType = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].HwServiceIdJob = MEM_43_INFLS_HWSERVICEID_CANCEL;

            /* End of exclusive area */
            SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_02();
        }
        else
        {
            /* Reject the requested job */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}

#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
static Std_ReturnType Mem_43_INFLS_Compare(Mem_43_INFLS_InstanceIdType    InstanceId,
                                           Mem_43_INFLS_AddressType       SourceAddress,
                                           Mem_43_INFLS_DataType          *DestinationDataPtr,
                                           Mem_43_INFLS_LengthType        Length
                                          )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);

    /* Config Hardware Service job for Compare Function  */
    JobRequest.JobType        = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob = MEM_43_INFLS_HWSERVICEID_COMPARE;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }

    return RetVal;
}
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */

#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
static Std_ReturnType Mem_43_INFLS_ArrayIntegrityCheck(Mem_43_INFLS_InstanceIdType  InstanceId,
                                                       Mem_43_INFLS_AddressType     UtestConfigIndex,
                                                       Mem_43_INFLS_MisrType        *MisrSeedValues,
                                                       Mem_43_INFLS_MisrType        *MisrExpectedValues
                                                      )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    /* with this job the length not use . so to run first loop we will init a value for it */
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, 0U, NULL_PTR, 1U);


    JobRequest.UtestConfigIndex = UtestConfigIndex;
    JobRequest.JobType          = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_ARRAY_INTEGRITY_CHECK;
    JobRequest.UtestRuntime     = Mem_43_INFLS_eJobUtestRuntimeInfo;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransferForUtestMode(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* The job is accepted, store Utest param*/
        /* Config Hardware Service job for ArrayIntegrityCheck Function  */
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].MisrSeedValues     = MisrSeedValues;
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].MisrExpectedValues = MisrExpectedValues;
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].UtestStateType     = MEM_43_INFLS_UTEST_JOB_OK;
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].UtestSuspendState  = FALSE;
    }
    else
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }

    return RetVal;
}

static Std_ReturnType Mem_43_INFLS_UserMarginReadCheck(Mem_43_INFLS_InstanceIdType  InstanceId,
                                                       Mem_43_INFLS_AddressType     UtestConfigIndex,
                                                       Mem_43_INFLS_MisrType        *MisrSeedValues,
                                                       Mem_43_INFLS_MisrType        *MisrExpectedValues
                                                      )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    /* With this job the length not use. So to run first loop we will init a value for it */
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, 0U, NULL_PTR, 1U);

    JobRequest.UtestConfigIndex = UtestConfigIndex;
    JobRequest.JobType          = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_USER_MARGIN_READ_CHECK;
    JobRequest.UtestRuntime     = Mem_43_INFLS_eJobUtestRuntimeInfo;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransferForUtestMode(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /*The job is accepted, store Utest param*/
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].MisrSeedValues     = MisrSeedValues;
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].MisrExpectedValues = MisrExpectedValues;
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].UtestStateType     = MEM_43_INFLS_UTEST_JOB_OK;
        Mem_43_INFLS_eJobUtestRuntimeInfo[UtestConfigIndex].UtestSuspendState  = FALSE;
    }
    else
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }

    return RetVal;
}

static Std_ReturnType Mem_43_INFLS_EccLogicCheck(Mem_43_INFLS_InstanceIdType InstanceId,
                                                 Mem_43_INFLS_EccLogicCheckDataType *UtestEdcEccLogicCheck
                                                )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    /* With this job the length not use. So to run first loop we will init a value for it */
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, 0U, NULL_PTR, 1U);

    JobRequest.UtestConfigIndex = 0U;
    JobRequest.JobType          = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_ECC_LOGIC_CHECK;
    JobRequest.UtestRuntime     = Mem_43_INFLS_eJobUtestRuntimeInfo;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransferForUtestMode(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* The job is accepted, store Utest param*/
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].MisrSeedValues        = NULL_PTR;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].MisrExpectedValues    = NULL_PTR;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestStateType        = MEM_43_INFLS_UTEST_JOB_OK;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestSuspendState     = FALSE;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestEdcEccLogicCheck = UtestEdcEccLogicCheck;
    }
    else
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }

    return RetVal;
}

static Std_ReturnType Mem_43_INFLS_EdcAfterEccLogicCheck( Mem_43_INFLS_InstanceIdType InstanceId,
                                                          Mem_43_INFLS_EccLogicCheckDataType *UtestEdcEccLogicCheck
                                                        )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    /* With this job the length not use. So to run first loop we will init a value for it */
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, 0U, NULL_PTR, 1U);

    JobRequest.UtestConfigIndex = 0U;
    JobRequest.JobType          = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_EDC_AFTER_ECC_LOGIC_CHECK;
    JobRequest.UtestRuntime     = Mem_43_INFLS_eJobUtestRuntimeInfo;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransferForUtestMode(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* The job is accepted, store Utest param*/
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].MisrSeedValues        = NULL_PTR;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].MisrExpectedValues    = NULL_PTR;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestStateType        = MEM_43_INFLS_UTEST_JOB_OK;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestSuspendState     = FALSE;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestEdcEccLogicCheck = UtestEdcEccLogicCheck;
    }
    else
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }

    return RetVal;
}
static Std_ReturnType Mem_43_INFLS_AddressEncodeLogicCheck( Mem_43_INFLS_InstanceIdType InstanceId,
                                                            Mem_43_INFLS_AddressEncodeDataType *AddressEncodeData
                                                          )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    /* With this job the length not use. So to run first loop we will init a value for it */
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, 0U, NULL_PTR, 1U);

    JobRequest.UtestConfigIndex = 0U;
    JobRequest.JobType          = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_ADDRESS_ENCODE_LOGIC_CHECK;
    JobRequest.UtestRuntime     = Mem_43_INFLS_eJobUtestRuntimeInfo;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransferForUtestMode(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* The job is accepted, store Utest param*/
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].MisrSeedValues        = NULL_PTR;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].MisrExpectedValues    = NULL_PTR;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestStateType        = MEM_43_INFLS_UTEST_JOB_OK;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestSuspendState     = FALSE;
        Mem_43_INFLS_eJobUtestRuntimeInfo[0U].UtestAddressEncodeCheck = AddressEncodeData;
    }
    else
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }

    return RetVal;
}
static Std_ReturnType Mem_43_INFLS_ArrayIntegrityCheckSuspend(Mem_43_INFLS_InstanceIdType InstanceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32                           InstanceIndex = 0U;
    Mem_43_INFLS_JobResultType       JobCurrentResult;
    Mem_43_INFLS_JobRuntimeInfoType *JobCurrentInfo;
    uint32 UtestConfigIndex;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }
    else
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
    {
        InstanceIndex  = Mem_43_INFLS_GetInstanceIndex(InstanceId);
        if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
        {
            /* Get Information of Job Current */
            JobCurrentInfo = &(Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex]);
            /* get index of Utest config */
            UtestConfigIndex = JobCurrentInfo->UtestConfigIndex;
            /* Check if Job current: in case not suspend operation is already in pending */
            if ((FALSE == JobCurrentInfo->UtestRuntime[UtestConfigIndex].UtestSuspendState) &&
                (MEM_43_INFLS_JOB_PENDING == JobCurrentInfo->JobResult))
            {
                JobCurrentResult = Mem_43_INFLS_IPW_ArrayIntegrityCheckSuspend(InstanceId);

                if (MEM_43_INFLS_JOB_OK == JobCurrentResult)
                {
                    JobCurrentInfo->UtestRuntime[UtestConfigIndex].UtestSuspendState = TRUE;
                    RetVal = E_OK;
                }
            }
        }
    }
    return RetVal;
}

static Std_ReturnType Mem_43_INFLS_ArrayIntegrityCheckResume(Mem_43_INFLS_InstanceIdType InstanceId)
{

    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32                           InstanceIndex = 0U;
    Mem_43_INFLS_JobResultType       JobCurrentResult;
    Mem_43_INFLS_JobRuntimeInfoType *JobCurrentInfo;
    uint32 UtestConfigIndex;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, ErrorId);
    }
    else
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
    {
        InstanceIndex  = Mem_43_INFLS_GetInstanceIndex(InstanceId);
        if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
        {
            /* Get Information of Job Current */
            JobCurrentInfo = &(Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex]);
            /* get index of Utest config */
            UtestConfigIndex = JobCurrentInfo->UtestConfigIndex;
            /* Check if Job current: in case not suspend operation is already in pending */
            if ((TRUE == JobCurrentInfo->UtestRuntime[UtestConfigIndex].UtestSuspendState) &&
                (MEM_43_INFLS_JOB_PENDING == JobCurrentInfo->JobResult))
            {
                JobCurrentResult = Mem_43_INFLS_IPW_ArrayIntegrityCheckResume(InstanceId);

                if (MEM_43_INFLS_JOB_OK == JobCurrentResult)
                {
                    JobCurrentInfo->UtestRuntime[UtestConfigIndex].UtestSuspendState = FALSE;
                    JobCurrentInfo->JobResult    = MEM_43_INFLS_JOB_PENDING;
                    RetVal = E_OK;
                }
            }
        }
    }

    return RetVal;
}
/**
 * @brief        Returns the result of the most recent job.
 *
 * @details      Returns synchronously the result of the last job.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Mem_43_INFLS_GetJobUtestState    Most recent job result.
 *
 * @api
 */
static Std_ReturnType Mem_43_INFLS_GetJobUtestState(Mem_43_INFLS_InstanceIdType InstanceId, Mem_43_INFLS_UtestStateType *UtestState)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    *UtestState = MEM_43_INFLS_UTEST_JOB_OK;
    uint32 InstanceIndex;

    InstanceIndex = Mem_43_INFLS_GetInstanceIndex(InstanceId);

    if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
    {
        /* Get the most recent job result of the according driver instance */
        *UtestState = Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].UtestRuntime[Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].UtestConfigIndex].UtestStateType;
        RetVal = E_OK;
    }

    return RetVal;
}
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief            Check dev error common for Mem_HwSpecificService API()
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        HwServiceId           Hardware specific service request identifier for dispatching the request.
 * @param[in]        DataPtr               Request specific data pointer.
 * @param[in]        LengthPtr             Size pointer of the data passed by dataPtr.
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : has dev error detect.
 *                   - E_NOT_OK               : hasn't dev error detect.
 */
static Std_ReturnType Mem_43_INFLS_CheckDevErrorCommon_HwSpecificService(Mem_43_INFLS_InstanceIdType     instanceId,
                                                                         Mem_43_INFLS_HwServiceIdType    hwServiceId,
                                                                         Mem_43_INFLS_DataType           *dataPtr,
                                                                         Mem_43_INFLS_LengthType         *lengthPtr
                                                                        )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Get the mem index number according to the mem instance id */
        uint32 InstanceIndex = Mem_43_INFLS_GetInstanceIndex(instanceId);

        if (MEM_43_INFLS_MEM_INSTANCE_COUNT <= InstanceIndex)
        {
            /* The provided instanceId is inconsistent with the configuration */
            ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
        }
        else if (((NULL_PTR == dataPtr) || (NULL_PTR == lengthPtr))
                 && (hwServiceId != MEM_43_INFLS_HWSERVICEID_CANCEL)
#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
                 && (hwServiceId != MEM_43_INFLS_HWSERVICEID_ARRAYINTEGRITYCHECK_SUSPEND) && (hwServiceId != MEM_43_INFLS_HWSERVICEID_ARRAYINTEGRITYCHECK_RESUME)
                 && (hwServiceId != MEM_43_INFLS_HWSERVICEID_GETSTATEUTEST_JOB)
#endif
                )
        {
            ErrorId = MEM_43_INFLS_E_PARAM_POINTER;
        }
#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
        else if ((MEM_43_INFLS_HWSERVICEID_COMPARE == hwServiceId) && (sizeof(Mem_43_INFLS_CompareConfigType) != *lengthPtr))
        {
            ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
        }
#endif
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Report the error */
        (void)Det_ReportError(MEM_43_INFLS_MODULE_ID, (uint8)instanceId, (uint8)MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, (uint8)ErrorId);
    }

#if (MEM_43_INFLS_HW_COMPARE_SERVICE != STD_ON)
    /* fix compiler warning */
    (void)hwServiceId;
#endif

    return RetVal;
}
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes Mem_43_INFLS module.
 *
 * @details      Initialization function - initializes all variables
 *               and sets the module state to initialized.
 *
 * @param[in]    ConfigPtr        Pointer to the configuration data structure - since Mem_43_INFLS driver
 *                                is a precompile module this parameter is typically not used.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @pre          None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_Init_Activity
 */
void Mem_43_INFLS_Init(const Mem_43_INFLS_ConfigType *ConfigPtr)
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_OK;
    Std_ReturnType Status;
    uint32 InstanceIndex;

    if (NULL_PTR != ConfigPtr)
    {
        /* The ConfigPtr argument is not a NULL pointer */
        Mem_43_INFLS_ReportDevError(0U, MEM_43_INFLS_INIT_ID, MEM_43_INFLS_E_PARAM_POINTER);
    }
    else
    {
        /* Initialize the Mem driver internal states and set the Mem driver job processing state to MEM_43_INFLS_JOB_OK */
        Mem_43_INFLS_pConfigPtr = &Mem_43_INFLS_Config;

        Status = Mem_43_INFLS_ValidateConfigCRC();
        if ((Std_ReturnType)E_OK == Status)
        {
#if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)
            Status = Mem_43_INFLS_Software_Semaphore_RequestLock();
            if ((Std_ReturnType)E_OK == Status)
            {
#endif
                /* Initialize low-level hardware */
                Status = Mem_43_INFLS_IPW_Init();

#if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)

                (void)Mem_43_INFLS_Software_Semaphore_ReleaseLock();
            }
#endif
        }

        if ((Std_ReturnType)E_OK != Status)
        {
            /* Mark the driver as un-initialized */
            Mem_43_INFLS_pConfigPtr = NULL_PTR;
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }

        /* Update job result */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
        }
    }
}


/**
 * @brief        The function de-initializes the Mem_43_INFLS module.
 *
 * @details      De-initialize module. If there is still an access job pending,
 *               it is immediately terminated (using hardware cancel operation)
 *               and the Mem driver module state is set to uninitialized.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre          The Mem_43_INFLS module must be re-initialized before it will accept
 *               any new job requests after this service is processed.
 *
 * @implements   Mem_43_INFLS_DeInit_Activity
 */
void Mem_43_INFLS_DeInit(void)
{
    uint32 InstanceIndex;
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_OK;

    /* Check if the driver has been initialized before */
    if (NULL_PTR != Mem_43_INFLS_pConfigPtr)
    {
        /* Cancel any ongoing flash operations in the hardware */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
                /* Cancel the on-going job for this mem instance (using hardware) */
                JobResult = Mem_43_INFLS_IPW_Cancel(InstanceIndex);
            }

            /* Update job result */
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
            /* Update job JobType to MEM_43_INFLS_JOB_NONE */
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobType   = MEM_43_INFLS_JOB_NONE;
        }

        /* De-initialize the Mem driver internal states */
        Mem_43_INFLS_pConfigPtr = NULL_PTR;
    }
}


/**
 * @brief        Return the version information of the Mem module.
 *
 * @details      Version information includes:
 *               - Module Id
 *               - Vendor Id
 *               - Vendor specific version numbers
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   VersionInfoPtr    Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 * @api
 *
 * @implements    Mem_43_INFLS_GetVersionInfo_Activity
 */
void Mem_43_INFLS_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
    if (NULL_PTR != VersionInfoPtr)
    {
        /* Return version information about Mem module */
        VersionInfoPtr->moduleID         = (uint16)MEM_43_INFLS_MODULE_ID;
        VersionInfoPtr->vendorID         = (uint16)MEM_43_INFLS_VENDOR_ID;
        VersionInfoPtr->sw_major_version =  (uint8)MEM_43_INFLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version =  (uint8)MEM_43_INFLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version =  (uint8)MEM_43_INFLS_SW_PATCH_VERSION;
    }
    else
    {
        /* The VersionInfoPtr argument is a NULL pointer */
        Mem_43_INFLS_ReportDevError(0U, MEM_43_INFLS_GET_VERSION_INFO_ID, MEM_43_INFLS_E_PARAM_POINTER);
    }
}


/**
 * @brief        Returns the result of the most recent job.
 *
 * @details      Returns synchronously the result of the last job.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Mem_43_INFLS_JobResultType    Most recent job result.
 *
 * @api
 *
 * @implements   Mem_43_INFLS_GetJobResult_Activity
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_GetJobResult(Mem_43_INFLS_InstanceIdType InstanceId)
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    uint32 InstanceIndex;

    InstanceIndex = Mem_43_INFLS_GetInstanceIndex(InstanceId);
    if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
    {
        /* Get the most recent job result of the according driver instance */
        JobResult = Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult;
    }

    return JobResult;
}

/**
 * @brief        Suspends active memory operation using hardware mechanism.
 *
 * @details      If the suspend mechanism is not supported by hardware,
 *               implementation based on physical segmentation.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_Suspend_Activity
 */
Std_ReturnType Mem_43_INFLS_Suspend(Mem_43_INFLS_InstanceIdType InstanceId)
{
    (void)InstanceId;
    Std_ReturnType RetVal = E_MEM_SERVICE_NOT_AVAIL;
    return RetVal;
}


/**
 * @brief        Resumes suspended memory operation using hardware mechanism.
 *
 * @details      Resumes suspended memory operation using hardware mechanism.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_Resume_Activity
 */
Std_ReturnType Mem_43_INFLS_Resume(Mem_43_INFLS_InstanceIdType InstanceId)
{
    (void)InstanceId;
    Std_ReturnType RetVal = E_MEM_SERVICE_NOT_AVAIL;
    return RetVal;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Reads from flash memory.
 *
 * @details          Triggers a read job to copy the from the source address into the referenced destination data
 *                   buffer. The result of this service can be retrieved using the Mem_GetJobResult API. If the read
 *                   operation was successful, the result of the job is MEM_43_INFLS_JOB_OK. If the read operation failed,
 *                   the result of the job is either MEM_43_INFLS_JOB_FAILED in case of a general error or MEM_ECC_
 *                   CORRECTED/MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        SourceAddress         Physical address to read data from.
 * @param[in]        Length                Read length in bytes.
 *
 * @param[out]       DestinationDataPtr    Destination memory pointer to store the read data
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_Read_Activity
 */
Std_ReturnType Mem_43_INFLS_Read(Mem_43_INFLS_InstanceIdType    InstanceId,
                                 Mem_43_INFLS_AddressType       SourceAddress,
                                 Mem_43_INFLS_DataType          *DestinationDataPtr,
                                 Mem_43_INFLS_LengthType        Length
                                )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_READ;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_READ_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Writes to flash memory.
 *
 * @details          Triggers a write job to store the passed data to the provided address area with given address
 *                   and length. The result of this service can be retrieved using the Mem_GetJobResult API. If the
 *                   write operation was successful, the job result is MEM_43_INFLS_JOB_OK. If there was an issue writing
 *                   the data, the result is MEM_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical write address (aligned to page size).
 * @param[out]       SourceDataPtr         Source data pointer (aligned to page size).
 * @param[in]        Length                Write length in bytes (aligned to page size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_Write_Activity
 */
Std_ReturnType Mem_43_INFLS_Write(Mem_43_INFLS_InstanceIdType     InstanceId,
                                  Mem_43_INFLS_AddressType        TargetAddress,
                                  const Mem_43_INFLS_DataType     *SourceDataPtr,
                                  Mem_43_INFLS_LengthType         Length
                                 )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_WRITE;

    /* Clause added to fulfil MISRA Rule 11.8 */
    const uint32 SourceDataAddr = (uint32)&(SourceDataPtr[0]);

    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, (Mem_43_INFLS_DataType *)(SourceDataAddr), Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);

    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_WRITE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Erase one or more complete flash sectors.
 *
 * @details          Triggers an erase job of the given sector/sector batch defined by targetAddress and length.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the erase operation
 *                   was successful, the result of the job is MEM_43_INFLS_JOB_OK. If the erase operation failed, e.g. due to
 *                   a hardware issue, the result of the job is MEM_43_INFLS_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical erase address (aligned to sector size).
 * @param[in]        Length                Erase length in bytes (aligned to sector size).
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_Erase_Activity
 */
Std_ReturnType Mem_43_INFLS_Erase(Mem_43_INFLS_InstanceIdType    InstanceId,
                                  Mem_43_INFLS_AddressType       TargetAddress,
                                  Mem_43_INFLS_LengthType        Length
                                 )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_ERASE;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_ERASE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 *
 * @details          Triggers a job to check the erased state of the page which is referenced by targetAddress.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the checked page is
 *                   blank, the result of the job is MEM_43_INFLS_JOB_OK. Otherwise, if the page is not blank, the result is
 *                   MEM_INCONSISTENT.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical blank check address.
 * @param[in]        Length                Blank check length.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_BlankCheck_Activity
 */
Std_ReturnType Mem_43_INFLS_BlankCheck(Mem_43_INFLS_InstanceIdType    InstanceId,
                                       Mem_43_INFLS_AddressType       TargetAddress,
                                       Mem_43_INFLS_LengthType        Length
                                      )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_BLANK_CHECK;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_BLANK_CHECK_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Trigger a hardware specific service.
 *
 * @details          Triggers a hardware specific memory driver job. DataPtr can be used to pass and return data to/
 *                   from this service. This service is just a dispatcher to the hardware specific service
 *                   implementation referenced by HwServiceId. The result of this service can be retrieved using the
 *                   Mem_GetJobResult API. If the hardware specific operation was successful, the result of the job
 *                   is MEM_43_INFLS_JOB_OK. If the hardware specific operation failed, the result of the job is MEM_43_INFLS_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        HwServiceId           Hardware specific service request identifier for dispatching the request.
 * @param[in]        DataPtr               Request specific data pointer.
 * @param[in]        LengthPtr             Size pointer of the data passed by dataPtr.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_HwSpecificService_Activity
 */
Std_ReturnType Mem_43_INFLS_HwSpecificService(Mem_43_INFLS_InstanceIdType     instanceId,
                                              Mem_43_INFLS_HwServiceIdType    hwServiceId,
                                              Mem_43_INFLS_DataType           *dataPtr,
                                              Mem_43_INFLS_LengthType         *lengthPtr
                                             )
{
    Std_ReturnType RetVal;

#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
    const Mem_43_INFLS_CompareConfigType*  pCompareConfig;
#endif
#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
    const Mem_43_INFLS_UtestModeConfigType*  pUtestConfig;
#endif
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Perform the input parameters checking */
    RetVal = Mem_43_INFLS_CheckDevErrorCommon_HwSpecificService(instanceId, hwServiceId, dataPtr, lengthPtr);

    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        switch (hwServiceId)
        {
            case MEM_43_INFLS_HWSERVICEID_CANCEL:
                RetVal = Mem_43_INFLS_Cancel(instanceId);
                break;
#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
            case MEM_43_INFLS_HWSERVICEID_COMPARE:
                pCompareConfig = (Mem_43_INFLS_CompareConfigType *)((uint32)dataPtr);
                RetVal = Mem_43_INFLS_Compare(instanceId, pCompareConfig->CompareAddr, pCompareConfig->DataSourcePtr, pCompareConfig->Length);
                break;
#endif
#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
            case MEM_43_INFLS_HWSERVICEID_ARRAY_INTEGRITY_CHECK:
                pUtestConfig = (Mem_43_INFLS_UtestModeConfigType *)((uint32)dataPtr);
                RetVal = Mem_43_INFLS_ArrayIntegrityCheck(instanceId, pUtestConfig->UtestConfigIndex, pUtestConfig->MisrSeedValues,pUtestConfig->MisrExpectedValues);
                break;
            case MEM_43_INFLS_HWSERVICEID_USER_MARGIN_READ_CHECK:
                pUtestConfig = (Mem_43_INFLS_UtestModeConfigType *)((uint32)dataPtr);
                RetVal = Mem_43_INFLS_UserMarginReadCheck(instanceId, pUtestConfig->UtestConfigIndex, pUtestConfig->MisrSeedValues,pUtestConfig->MisrExpectedValues);
                break;
            case MEM_43_INFLS_HWSERVICEID_ECC_LOGIC_CHECK:
                RetVal = Mem_43_INFLS_EccLogicCheck(instanceId, (Mem_43_INFLS_EccLogicCheckDataType *)dataPtr);
                break;
            case MEM_43_INFLS_HWSERVICEID_EDC_AFTER_ECC_LOGIC_CHECK:
                RetVal = Mem_43_INFLS_EdcAfterEccLogicCheck(instanceId, (Mem_43_INFLS_EccLogicCheckDataType *)dataPtr);
                break;
            case MEM_43_INFLS_HWSERVICEID_ADDRESS_ENCODE_LOGIC_CHECK:
                RetVal = Mem_43_INFLS_AddressEncodeLogicCheck(instanceId, (Mem_43_INFLS_AddressEncodeDataType *)dataPtr);
                break;
            case MEM_43_INFLS_HWSERVICEID_ARRAYINTEGRITYCHECK_SUSPEND:
                RetVal = Mem_43_INFLS_ArrayIntegrityCheckSuspend(instanceId);
                break;
            case MEM_43_INFLS_HWSERVICEID_ARRAYINTEGRITYCHECK_RESUME:
                RetVal = Mem_43_INFLS_ArrayIntegrityCheckResume(instanceId);
                break;
            case MEM_43_INFLS_HWSERVICEID_GETSTATEUTEST_JOB:
                RetVal = Mem_43_INFLS_GetJobUtestState(instanceId, (Mem_43_INFLS_UtestStateType *)(uint32)dataPtr);
                break;
#endif /* (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON) */
            default:
                RetVal = E_MEM_SERVICE_NOT_AVAIL;
                break;
        }
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    }
#else
    (void)instanceId;
    (void)dataPtr;
    (void)lengthPtr;
#endif

    return RetVal;
}


/**
 * @brief        Propagates an ECC error to the memory upper layers
 *
 * @details      This service can be used to report an access error in case
 *               the Mem driver cannot provide the access error information - typically for ECC faults.
 *               It is called by the system ECC handler to propagate an ECC error to the memory upper layers.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_PropagateError_Activity
 */
void Mem_43_INFLS_PropagateError(Mem_43_INFLS_InstanceIdType InstanceId)
{
    uint32 Index;
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
        /* Check if InstanceId is consistent with configuration */
        /* Get the mem index number according to the mem instance id */
        Index = Mem_43_INFLS_GetInstanceIndex(InstanceId);
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
        if (MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID == Index)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
        }
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_PROPAGATE_ERROR_ID, ErrorId);
    }
    else
    {
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */

        /* Start of exclusive area */
        SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_05();

        Mem_43_INFLS_eJobRuntimeInfo[Index].JobType = MEM_43_INFLS_JOB_NONE;
        /* Set the job result code to MEM_ECC_UNCORRECTED */
        Mem_43_INFLS_eJobRuntimeInfo[Index].JobResult = MEM_43_INFLS_ECC_UNCORRECTED;

        /* End of exclusive area */
        SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_05();

        Mem_43_INFLS_IPW_ReportEccValueToLayerUnder();
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
}
/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 *
 * @details          Service to handle the requested jobs and the internal management operations.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @note             This function have to be called cyclically by the Basic Software Module;
 *                   it will do nothing if there aren't pending job.
 *
 * @implements       Mem_43_INFLS_MainFunction_Activity
 */
void Mem_43_INFLS_MainFunction(void)
{
    uint32 InstanceIndex;
#if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)
    Std_ReturnType Status;
#endif

    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed
       then no error shall be reported and the main function shall return immediately.
    */
    if (NULL_PTR != Mem_43_INFLS_pConfigPtr)
    {
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
#if (MEM_43_INFLS_MULTICORE_ENABLED == STD_ON)
                /*Check if the core is the core that requested the job*/
                if (OsIf_GetUserId() == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].PartitionId)
#endif
                {
#if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)
                    Status = Mem_43_INFLS_Software_Semaphore_RequestLock();
                    if ((Std_ReturnType)E_OK == Status)
#endif
                    {
                        /* Process the requested job for this mem instance */
                        Mem_43_INFLS_ProcessRequestedJobs(InstanceIndex);
                    }
#if (MEM_43_INFLS_USING_SW_SEMAPHORE == STD_ON)
                    (void)Mem_43_INFLS_Software_Semaphore_ReleaseLock();
#endif

                }
            }
        }
    }
}


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
