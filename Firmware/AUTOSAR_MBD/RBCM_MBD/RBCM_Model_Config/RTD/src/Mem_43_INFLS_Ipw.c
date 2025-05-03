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
 * @file       Mem_43_INFLS_Ipw.c
 *
 * @addtogroup MEM_43_INFLS Driver
 * implement   Mem_43_INFLS_Ipw.c_Artifact
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
#include "Mem_43_INFLS.h"
#include "Mem_43_INFLS_Ipw.h"
#include "C40_Ip.h"
#include "C40_Ip_Ac.h"

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
#if (STD_ON == MEM_43_INFLS_CLEAN_CACHE_AFTER_LOAD_AC)
#include "Cache_Ip.h"
#endif /* MEM_43_INFLS_CLEAN_CACHE_AFTER_LOAD_AC */
#endif /* MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_IPW_VENDOR_ID_C                           43
#define MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C            7
#define MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C                    5
#define MEM_43_INFLS_IPW_SW_MINOR_VERSION_C                    0
#define MEM_43_INFLS_IPW_SW_PATCH_VERSION_C                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_INFLS.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "Mem_43_INFLS_Ipw.c and Mem_43_INFLS.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS.h are different"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS.h are different"
#endif

/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != MEM_43_INFLS_IPW_VENDOR_ID)
    #error "Mem_43_INFLS_Ipw.c and Mem_43_INFLS_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS_Ipw.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_INFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != MEM_43_INFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != MEM_43_INFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS_Ipw.h are different"
#endif

/* Check if current file and C40_Ip.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != C40_IP_VENDOR_ID_H)
    #error "Mem_43_INFLS_Ipw.c and C40_Ip.h have different vendor ids"
#endif
/* Check if current file and C40_Ip.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != C40_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != C40_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.c and C40_Ip.h are different"
#endif
/* Check if current file and C40_Ip.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != C40_IP_SW_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != C40_IP_SW_MINOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != C40_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.c and C40_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

/**
    @brief fill pattern used to clear write and erase access code in RAM
 */
#define MEM_43_INFLS_AC_UNLOAD_PATTERN 0xffffffffU

#endif

/* Get the current DomainID. */
#if (STD_ON == MEM_43_INFLS_USE_XRDC_CONFIG)

#define Mem_43_INFLS_u8DomainID          (Rm_XrdcGetDomainID(0U))

#else

#define Mem_43_INFLS_u8DomainID          (0U)

#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

#define MEM_43_INFLS_START_SEC_CONST_32
#include "Mem_43_INFLS_MemMap.h"

/* Note: Linker scripts symbol declarations must be accessed by the use of the '&' operators */
/* Start Position and Size of erase access code in flash */
extern const uint32 Mem_43_INFLS_ACEraseRomStart;
extern const uint32 Mem_43_INFLS_ACEraseSize;

/* Start Position and Size of write access code in flash */
extern const uint32 Mem_43_INFLS_ACWriteRomStart;
extern const uint32 Mem_43_INFLS_ACWriteSize;

#define MEM_43_INFLS_STOP_SEC_CONST_32
#include "Mem_43_INFLS_MemMap.h"

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

#define MEM_43_INFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_INFLS_MemMap.h"

/* Block of ACErase function address */
static Mem_43_INFLS_BlockType xMemBlockAcErase;
/* Block of ACWrite function address */
static Mem_43_INFLS_BlockType xMemBlockAcWrite;

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_INFLS_MemMap.h"

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

#define MEM_43_INFLS_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_INFLS_MemMap.h"

/* @brief verify that AC loaded or not */
static boolean Mem_43_INFLS_AcLoaded;                      /* implicit zero initialization: FALSE */

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_INFLS_MemMap.h"

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

static void Mem_43_INFLS_IPW_LoadAc(const Mem_43_INFLS_JobType JobType);
static void Mem_43_INFLS_IPW_UnloadAc(const Mem_43_INFLS_JobType JobType);
static inline void Mem_43_INFLS_IPW_CheckLoadAc(Mem_43_INFLS_BlockType BlockAc,
                                                Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                               );
static inline void Mem_43_INFLS_IPW_CheckUnLoadAc(const Mem_43_INFLS_JobType JobType);

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
 * @brief    Returns the result of the last job of Hw Service.
 */
static C40_Ip_StatusType Mem_43_INFLS_IPW_HwServiceGetJobResult(uint32 InstanceIndex,
                                                                Mem_43_INFLS_JobRuntimeInfoType *JobInfo)
{
    C40_Ip_StatusType IpStatus;

#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
    C40_Ip_UtestStateType       UtestResult = C40_IP_OK;
    Mem_43_INFLS_UtestStateType TmpOpStatus = MEM_43_INFLS_UTEST_JOB_OK;
#endif

    switch (JobInfo->HwServiceIdJob)
    {
    case MEM_43_INFLS_HWSERVICEID_CANCEL:
        /* Abort a program or erase operation */
        IpStatus = C40_Ip_Abort();
        break;

#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
    case MEM_43_INFLS_HWSERVICEID_ARRAY_INTEGRITY_CHECK:
    case MEM_43_INFLS_HWSERVICEID_USER_MARGIN_READ_CHECK:
        /* Process ongoing utest asynchronous hardware job. */
        IpStatus = C40_Ip_CheckUserTestStatus((const Mem_43_INFLS_MisrType *)JobInfo->UtestRuntime[InstanceIndex].MisrExpectedValues, &UtestResult);
        if (C40_IP_STATUS_BUSY != IpStatus)
        {
            switch (UtestResult)
            {
            case C40_IP_USER_TEST_SUS:
                /* The UTest check operation is in suspend state */
                TmpOpStatus = MEM_43_INFLS_UTEST_JOB_USER_TEST_SUS;
                break;
            case C40_IP_USER_TEST_BREAK_SBC:
                /* The UTest check operation is broken by Single bit correction */
                TmpOpStatus = MEM_43_INFLS_UTEST_JOB_USER_TEST_BREAK_SBC;
                break;

            case C40_IP_USER_TEST_BREAK_DBD:
                /* The UTest check operation is broken by Double bit detection */
                TmpOpStatus = MEM_43_INFLS_UTEST_JOB_USER_TEST_BREAK_DBD;
                break;

            default:
                /* Successful operation */
                TmpOpStatus = MEM_43_INFLS_UTEST_JOB_OK;
                break;
            }
        }

        if (MEM_43_INFLS_UTEST_JOB_USER_TEST_SUS == TmpOpStatus)
        {
            /* Make job status to busy when it suspended */
            IpStatus = C40_IP_STATUS_BUSY;
        }
        JobInfo->UtestRuntime->UtestStateType = TmpOpStatus;
        break;

#endif /* MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON */
    default:
        /* fix compiler warning */
        IpStatus = C40_IP_STATUS_SUCCESS;
        break;
    }

    (void)InstanceIndex; /* fix compiler warning */
    return IpStatus;
}


/*
 * Description:    Get the memory unit index of the memory instance
 *
 * Mem_43_INFLS_IPW_GetMemoryUnitIndex - This function maybe will be implemented next feature.
 */

/*
 * Description:    Update the job status after processing a chunk
 */
static void Mem_43_INFLS_IPW_UpdateJobProcessedLength(Mem_43_INFLS_JobRuntimeInfoType *JobInfo,
                                                      Mem_43_INFLS_LengthType            TransferLength
                                                     )
{
    /* Move to the next chunk of job */
    JobInfo->Address += TransferLength;
    JobInfo->Length  -= TransferLength;

    /* Update data buffer pointer if required */
    if (NULL_PTR != JobInfo->DataPtr)
    {
        JobInfo->DataPtr = &(JobInfo->DataPtr[TransferLength]);
    }
}


/*
 * Description:    Compute the number of bytes to read for the current job.
 */
static Mem_43_INFLS_LengthType Mem_43_INFLS_IPW_ComputeReadLength(const Mem_43_INFLS_JobRuntimeInfoType *JobInfo)
{
    Mem_43_INFLS_LengthType ReadLength = JobInfo->Length;

    return ReadLength;
}


/**
 * @brief    Computes the size for an erase job.
 *           Based on physical hardware capability and device sector size boundary.
 */
static Mem_43_INFLS_LengthType Mem_43_INFLS_IPW_ComputeEraseLength(const Mem_43_INFLS_JobRuntimeInfoType *JobInfo)
{
    Mem_43_INFLS_LengthType EraseLength = JobInfo->SectorBatch->SectorSize;  /* default is normal size */

    return EraseLength;
}


/**
 * @brief    Computes the size of the next chunk of a write job.
 *           Based on physical hardware capability and device page size boundary.
 */
static Mem_43_INFLS_LengthType Mem_43_INFLS_IPW_ComputeWriteLength(const Mem_43_INFLS_JobRuntimeInfoType *JobInfo)
{
    uint32 Offset;
    uint32 WriteLength;
    Mem_43_INFLS_AddressType TargetAddress = JobInfo->Address;
    uint32 Length = JobInfo->Length;  /* The remaining length of the job */

    /* Byte offset of a quad-page */
    Offset = TargetAddress & (C40_IP_WRITE_MAX_SIZE - 1U);

    /* Computes WriteLength */
    /* TargetAddress is not aligned a quad-page */
    if (0U != Offset)
    {
        if ((Length + Offset) > C40_IP_WRITE_MAX_SIZE)
        {
            /* Length + Offset must fall within a quad-page */
            WriteLength = C40_IP_WRITE_MAX_SIZE - Offset;
        }
        else
        {
            WriteLength  = Length;
        }
    }
    else /* TargetAddress is aligned a quad-page */
    {

        if (Length > C40_IP_WRITE_MAX_SIZE)
        {
            /* max programble length to HW is C40_IP_WRITE_MAX_SIZE */
            WriteLength = C40_IP_WRITE_MAX_SIZE;
        }
        else
        {
            WriteLength = Length;
        }

    }

    return WriteLength;
}


/**
 * @brief    Translate the return code from IPV to HLD.
 */
static Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_TranslateReturnCode(C40_Ip_StatusType IpReturnValue)
{
    Mem_43_INFLS_JobResultType JobResult;

    switch (IpReturnValue)
    {
        case C40_IP_STATUS_BUSY:
            /* The job is still being processed */
            JobResult = MEM_43_INFLS_JOB_PENDING;
            break;

        case C40_IP_STATUS_SUCCESS:
            /* The job has completed */
            JobResult = MEM_43_INFLS_JOB_OK;
            break;
        case C40_IP_STATUS_ECC_UNCORRECTED:
            /* The job has completed */
            JobResult = MEM_43_INFLS_ECC_UNCORRECTED;
            break;
        case C40_IP_STATUS_ECC_CORRECTED:
            /* The job has completed */
            JobResult = MEM_43_INFLS_ECC_CORRECTED;
            break;
        default:
            /* Timeout or hardware errors */
            JobResult = MEM_43_INFLS_JOB_FAILED;
            break;
    }

    return JobResult;
}

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
/**
 * @brief        Load access code to RAM
 *
 * @details      Load erase or write access code to statically
 *               pre-configured location in RAM
 *
 * @param[in]    JobType Type of access code to load. Can be either
 *               MEM_43_INFLS_JOB_ERASE or MEM_43_INFLS_JOB_WRITE
 *
 * @pre          The module must be initialized
 *
 */
static void Mem_43_INFLS_IPW_LoadAc(const Mem_43_INFLS_JobType JobType)
{
    uint32        Count;
    uint32        AcSize;  /* Word size */
    uint32       *RamPtr;
    const uint32 *RomPtr;

    if (MEM_43_INFLS_JOB_ERASE == JobType)
    {
        RomPtr = (const uint32 *)((uint32)(&Mem_43_INFLS_ACEraseRomStart));
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcErasePtr));
        AcSize = (uint32)(&Mem_43_INFLS_ACEraseSize);
    }
    else
    {
        /* MEM_43_INFLS_JOB_WRITE */
        RomPtr = (const uint32 *)((uint32)(&Mem_43_INFLS_ACWriteRomStart));
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcWritePtr));
        AcSize = (uint32)(&Mem_43_INFLS_ACWriteSize);
    }

    /* Copy erase or write access code to RAM */
    /* AcSize is dynamically calculated and might not be multiple of 4U */
    for (Count = 0U; Count < AcSize; Count++)
    {
        /* Copy 4 bytes at a time*/
        RamPtr[Count] = RomPtr[Count];
    }
}


/**
 * @brief        Unload access code to RAM
 *
 * @details      Erase write or erase access code from statically
 *               pre-configured location in RAM. Fills the RAM location
 *               with MEM_43_INFLS_AC_UNLOAD_PATTERN
 *
 * @param[in]    JobType Type of access code to unload. Can be either
 *               MEM_43_INFLS_JOB_ERASE or MEM_43_INFLS_JOB_WRITE
 *
 * @pre          The module must be initialized
 *
 */
static void Mem_43_INFLS_IPW_UnloadAc(const Mem_43_INFLS_JobType JobType)
{
    uint32  Count;
    uint32  AcSize;  /* Word size */
    uint32 *RamPtr;

    if (MEM_43_INFLS_JOB_ERASE == JobType)
    {
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcErasePtr));
        AcSize = (uint32)(&Mem_43_INFLS_ACEraseSize);
    }
    else
    {
        /* MEM_43_INFLS_JOB_WRITE */
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcWritePtr));
        AcSize = (uint32)(&Mem_43_INFLS_ACWriteSize);
    }

    /* Unload (erase) write or erase access code from RAM */
    for (Count = 0U; Count < AcSize; Count++)
    {
        /* Clear 4 bytes at a time*/
        RamPtr[Count] = MEM_43_INFLS_AC_UNLOAD_PATTERN;
    }
}

static inline void Mem_43_INFLS_IPW_CheckLoadAc(Mem_43_INFLS_BlockType BlockAc,
                                                Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                               )
{
    Mem_43_INFLS_BlockType   JobBlockSector;

    /* Get block number of the sector to be erased or written */
    JobBlockSector = (Mem_43_INFLS_BlockType)C40_Ip_GetBlockNumberFromAddress((uint32)JobInfo->Address);

    /* Only load if erase/write to the same block */
    if (((Mem_43_INFLS_BlockType)C40_IP_BLOCK_INVALID != JobBlockSector) && ((Mem_43_INFLS_BlockType)C40_IP_BLOCK_INVALID != BlockAc) && (JobBlockSector == BlockAc))
    {
        /* Load position independent access code to RAM */
        Mem_43_INFLS_IPW_LoadAc(JobInfo->JobType);

        /* Mask the status as loaded */
        Mem_43_INFLS_AcLoaded = (boolean)TRUE;

#if (STD_ON == MEM_43_INFLS_CLEAN_CACHE_AFTER_LOAD_AC)
        if (MEM_43_INFLS_JOB_ERASE == JobInfo->JobType)
        {
            /* Clean cache after loading to sync with RAM for Erase job */
            (void)Cache_Ip_CleanByAddr(CACHE_IP_CORE, CACHE_IP_DATA, TRUE, (uint32)Mem_43_INFLS_pConfigPtr->MemAcErasePtr, ((uint32)(&Mem_43_INFLS_ACEraseSize) * 4U));
        }
        else
        {
            /* Clean cache after loading to sync with RAM for Write job */
            (void)Cache_Ip_CleanByAddr(CACHE_IP_CORE, CACHE_IP_DATA, TRUE, (uint32)Mem_43_INFLS_pConfigPtr->MemAcWritePtr, ((uint32)(&Mem_43_INFLS_ACWriteSize) * 4U));
        }
#endif /* MEM_43_INFLS_SUPPORT_CACHE_FEATURE */
    }
}

static inline void Mem_43_INFLS_IPW_CheckUnLoadAc(const Mem_43_INFLS_JobType JobType)
{
    /* If the access code was loaded */
    if (TRUE == Mem_43_INFLS_AcLoaded)
    {
        /* Unload from RAM */
        Mem_43_INFLS_IPW_UnloadAc(JobType);

        /* Mask the status as unloaded */
        Mem_43_INFLS_AcLoaded = (boolean)FALSE;
    }
}
#endif /* MEM_43_INFLS_AC_LOAD_ON_JOB_START */

#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
static uint32 Mem_43_INFLS_IPW_GetAddrFormBlockNumber(C40_Ip_FlashBlocksNumberType BlockNumber)
{
    uint32 BaseAddressofBlock;

    switch (BlockNumber)
    {
    case C40_IP_CODE_BLOCK_0:
        /* The address is in the code block 0 */
        BaseAddressofBlock = C40_IP_CODE_BLOCK_0_BASE_ADDR;
        break;
#ifdef C40_IP_CODE_BLOCK_1_BASE_ADDR
    case C40_IP_CODE_BLOCK_1:
        /* The address is in the code block 1 */
        BaseAddressofBlock = C40_IP_CODE_BLOCK_1_BASE_ADDR;
        break;
#endif
#ifdef C40_IP_CODE_BLOCK_2_BASE_ADDR
    case C40_IP_CODE_BLOCK_2:
        /* The address is in the code block 2 */
        BaseAddressofBlock = C40_IP_CODE_BLOCK_2_BASE_ADDR;
        break;
#endif
#ifdef C40_IP_CODE_BLOCK_3_BASE_ADDR
    case C40_IP_CODE_BLOCK_3:
        /* The address is in the code block 3 */
        BaseAddressofBlock = C40_IP_CODE_BLOCK_3_BASE_ADDR;
        break;
#endif
#ifdef C40_IP_DATA_BLOCK_BASE_ADDR
    case C40_IP_DATA_BLOCK:
        /* The address is in the data block */
        BaseAddressofBlock = C40_IP_DATA_BLOCK_BASE_ADDR;
        break;
#endif
#ifdef C40_IP_UTEST_BLOCK_BASE_ADDR
    case C40_IP_BLOCK_UTEST:
        /* The address is in the UTEST block */
        BaseAddressofBlock = C40_IP_UTEST_BLOCK_BASE_ADDR;
        break;
#endif
    default:
        BaseAddressofBlock = C40_IP_INVALID_ADDR;
        break;
    }

    return BaseAddressofBlock;
}
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief        Mem_43_INFLS_IPW_Init
 * @details      Initialize memory flash devices.
 */
Std_ReturnType Mem_43_INFLS_IPW_Init(void)
{
    const Mem_43_INFLS_InternalUnitType *InternalUnits = Mem_43_INFLS_pConfigPtr->MemDevices->InternalUnits;
    Std_ReturnType                       RetVal        = (Std_ReturnType)E_OK;
    C40_Ip_StatusType                    Status;
    uint32                               Unit;

    for (Unit = 0U; Unit < MEM_43_INFLS_INTERNAL_UNIT_COUNT; Unit++)
    {
        if (NULL_PTR != InternalUnits[Unit].InternalConfig)
        {
            /* Use configuration "InternalConfig" to initialize C40 */
            Status = C40_Ip_Init(InternalUnits[Unit].InternalConfig);

            if (C40_IP_STATUS_SUCCESS != Status)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    /* Get block number of ACWrite/Erase function address */
    xMemBlockAcWrite = (Mem_43_INFLS_BlockType)C40_Ip_GetBlockNumberFromAddress((uint32)(&Mem_43_INFLS_ACWriteRomStart));
    xMemBlockAcErase = (Mem_43_INFLS_BlockType)C40_Ip_GetBlockNumberFromAddress((uint32)(&Mem_43_INFLS_ACEraseRomStart));
#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

    return RetVal;
}


/**
 * @brief          IP wrapper sector function.
 * @details        Route the erase job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Erase(uint32 InstanceIndex,
                                                  Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                 )
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_LengthType    TransferLength;
    C40_Ip_StatusType          Status;
    C40_Ip_VirtualSectorsType  VirtualSector;
    boolean                    AsyncMode = TRUE;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_INFLS_IPW_ComputeEraseLength(JobInfo);

    /*If Sync mode is enabled                         ->  AsyncMode is FALSE */
    /*If Load Code to Ram is enabled and AC is loaded ->  AsyncMode is FALSE */
    /*Remaining cases                                 ->  AsyncMode is TRUE */
#if (STD_ON == MEM_43_INFLS_SYNC_MODE_ENABLE)
    /* Set Synch Mode for IP layer */
    AsyncMode = FALSE;
#endif

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    Mem_43_INFLS_IPW_CheckLoadAc(xMemBlockAcErase, JobInfo);
    if (TRUE == Mem_43_INFLS_AcLoaded)
    {
        /* Set Synch Mode for IP layer */
        AsyncMode = FALSE;
    }
#endif

    /* Get the physical sector number */
    VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address);
    /* Unlocks the Virtual sector */
    Status = C40_Ip_ClearLock(VirtualSector, (uint8)Mem_43_INFLS_u8DomainID);
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        C40_Ip_SetAsyncMode(AsyncMode);
        /* Call IP routine to erase internal flash memory sector */
        Status = C40_Ip_MainInterfaceSectorErase(VirtualSector, (uint8)Mem_43_INFLS_u8DomainID);
    }

    if (C40_IP_STATUS_SUCCESS == Status)
    {
        /*If Load Code to Ram is enabled, AC is loaded (don't care Sync/Async mode)     ->  run access code on RAM   */
        /*If Load Code to Ram is enabled, AC is not loaded and Sync mode is enabled     ->  run access code on Flash */
        /*If Load Code to Ram is enabled, AC is not loaded and Sync mode is disabled    ->  no run access code, C40 job is set on IP layer*/
        /*If Load Code to Ram is disabled, Sync mode is enabled                         ->  run access code on Flash */
        /*If Load Code to Ram is disabled, Sync mode is disabled                        ->  no run access code, C40 job is set on IP layer*/
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
        if (TRUE == Mem_43_INFLS_AcLoaded)
        {
            /* Wait for IP to finish */
            MEM_43_INFLS_AC_CALL(Mem_43_INFLS_pConfigPtr->MemAcErasePtr, Mem_43_INFLS_AcErasePtrType)(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
        }
        else
#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */
        {
            if (FALSE == AsyncMode)
            {
                C40_Ip_AccessCode(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
            }
        }

        /* Update job state */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);

        if (FALSE == AsyncMode)
        {
            if ( JobInfo->Length == 0U )
            {
                JobResult =  Mem_43_INFLS_IPW_GetJobResult(InstanceIndex, JobInfo);
            }
            else
            {
                JobResult = MEM_43_INFLS_JOB_PENDING;
            }
        }
        else
        {
            /* Command is sent, the actual job is being processed in the memory device */
            JobResult = MEM_43_INFLS_JOB_PENDING;
        }

    }
    else
    {
        /*Operation failed. Command have not sent yet*/
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    Mem_43_INFLS_IPW_CheckUnLoadAc(JobInfo->JobType);
#endif

    (void)InstanceIndex;

    return JobResult;
}

/**
 * @brief          IP wrapper sector write function.
 * @details        Route the write job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Write(uint32 InstanceIndex,
                                                  Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                 )
{
    Mem_43_INFLS_JobResultType     JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_LengthType        TransferLength;
    C40_Ip_StatusType              Status;
    C40_Ip_VirtualSectorsType      VirtualSector;
    boolean                        AsyncMode = TRUE;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_INFLS_IPW_ComputeWriteLength(JobInfo);

    /*If Sync mode is enabled                         ->  AsyncMode is FALSE */
    /*If Load Code to Ram is enabled and AC is loaded ->  AsyncMode is FALSE */
    /*Remaining cases                                 ->  AsyncMode is TRUE */
#if (STD_ON == MEM_43_INFLS_SYNC_MODE_ENABLE)
    /* Set Synch Mode for IP layer */
    AsyncMode = FALSE;
#endif

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    Mem_43_INFLS_IPW_CheckLoadAc(xMemBlockAcWrite, JobInfo);
    if (TRUE == Mem_43_INFLS_AcLoaded)
    {
        /* Set Synch Mode for IP layer */
        AsyncMode = FALSE;
    }
#endif

    /* Get the physical sector number */
    VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address);
    /* Unlocks the Virtual sector */
    Status = C40_Ip_ClearLock(VirtualSector, (uint8)Mem_43_INFLS_u8DomainID);
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        C40_Ip_SetAsyncMode(AsyncMode);
        /* Call IP routine to write data to internal flash memory */
        Status = C40_Ip_MainInterfaceWrite(JobInfo->Address, TransferLength, JobInfo->DataPtr, (uint8)Mem_43_INFLS_u8DomainID);
    }
    if ((C40_IP_STATUS_SUCCESS == Status) || (C40_IP_STATUS_ECC_CORRECTED == Status))
    {
        /* If Load Code to Ram is enabled, AC is loaded (don't care Sync/Async mode)     ->  run access code on RAM   */
        /* If Load Code to Ram is enabled, AC is not loaded and Sync mode is enabled     ->  run access code on Flash */
        /* If Load Code to Ram is enabled, AC is not loaded and Sync mode is disabled    ->  no run access code, C40 job is set on IP layer*/
        /* If Load Code to Ram is disabled, Sync mode is enabled                         ->  run access code on Flash */
        /* If Load Code to Ram is disabled, Sync mode is disabled                        ->  no run access code, C40 job is set on IP layer*/
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
        if (TRUE == Mem_43_INFLS_AcLoaded)
        {
            /* Wait for IP to finish */
            MEM_43_INFLS_AC_CALL(Mem_43_INFLS_pConfigPtr->MemAcWritePtr, Mem_43_INFLS_AcWritePtrType)(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
        }
        else
#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */
        {
            if (FALSE == AsyncMode)
            {
                C40_Ip_AccessCode(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
            }
        }

        /* Update job state */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);

        if (FALSE == AsyncMode)
        {
            if ( JobInfo->Length == 0U )
            {
                JobResult =  Mem_43_INFLS_IPW_GetJobResult(InstanceIndex, JobInfo);
            }
            else
            {
                JobResult = MEM_43_INFLS_JOB_PENDING;
            }
        }
        else
        {
            /* Command is sent, the actual job is being processed in the memory device */
            JobResult = MEM_43_INFLS_JOB_PENDING;
        }
    }
    else if (C40_IP_STATUS_ECC_UNCORRECTED == Status)
    {
        /* The job result is ecc uncorrected. Command have not sent yet */
        JobResult = MEM_43_INFLS_ECC_UNCORRECTED;
    }
    else
    {
        /* Operation failed. Command have not sent yet */
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    Mem_43_INFLS_IPW_CheckUnLoadAc(JobInfo->JobType);
#endif

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief          IP wrapper read function.
 * @details        Route the read job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Read(uint32 InstanceIndex,
                                                 Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                )
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_LengthType TransferLength;
    C40_Ip_StatusType Status;


    /* Calculate length of data transfer */
    TransferLength = Mem_43_INFLS_IPW_ComputeReadLength(JobInfo);
    /* Read data from flash memory device */
    Status = C40_Ip_Read(JobInfo->Address, TransferLength, JobInfo->DataPtr);
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        /* Update length */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        /* Update state */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else if (C40_IP_STATUS_ECC_CORRECTED == Status)
    {
        /* Update length */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        /* Update state */
        JobResult = MEM_43_INFLS_ECC_CORRECTED;
    }
    else if (C40_IP_STATUS_ECC_UNCORRECTED == Status)
    {
        /* The job result is ecc uncorrected */
        JobResult = MEM_43_INFLS_ECC_UNCORRECTED;
    }
    else
    {
        /* Do nothing */
    }

    (void)InstanceIndex;

    return JobResult;
}

#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
/**
 * @brief          IP wrapper comparison check function.
 * @details        Route the comparison check job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Compare(uint32 InstanceIndex,
                                                    Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                   )
{
    Mem_43_INFLS_JobResultType JobResult;
    Mem_43_INFLS_LengthType TransferLength;
    C40_Ip_StatusType Status;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_INFLS_IPW_ComputeReadLength(JobInfo);
    /* Check comparison */
    Status = C40_Ip_Compare(JobInfo->Address, TransferLength, JobInfo->DataPtr);
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        /* Update length */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        /* Update state */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else if (C40_IP_STATUS_ECC_CORRECTED == Status)
    {
        /* Update length */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        /* Update state */
        JobResult = MEM_43_INFLS_ECC_CORRECTED;
    }
    else if (C40_IP_STATUS_ECC_UNCORRECTED == Status)
    {
        /* The job result is ecc uncorrected */
        JobResult = MEM_43_INFLS_ECC_UNCORRECTED;
    }
    else
    {
        /* The job result is inconsistent */
        JobResult = MEM_43_INFLS_INCONSISTENT;
    }

    (void)InstanceIndex;

    return JobResult;
}
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */


/**
 * @brief          IP wrapper blank check function.
 * @details        Route the blank check job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_BlankCheck(uint32 InstanceIndex,
                                                       Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                      )
{
    Mem_43_INFLS_JobResultType JobResult;
    Mem_43_INFLS_LengthType TransferLength;
    C40_Ip_StatusType Status;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_INFLS_IPW_ComputeReadLength(JobInfo);
    /* Read data from flash memory device and verify that it is in erased state */
    Status = C40_Ip_Compare(JobInfo->Address, TransferLength, NULL_PTR);
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        /* Update length */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        /* Update state */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else if (C40_IP_STATUS_ECC_CORRECTED == Status)
    {
        /* Update length */
        Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        /* Update state */
        JobResult = MEM_43_INFLS_ECC_CORRECTED;
    }
    else if (C40_IP_STATUS_ECC_UNCORRECTED == Status)
    {
        /* The job result is ecc uncorrected */
        JobResult = MEM_43_INFLS_ECC_UNCORRECTED;
    }
    else
    {
        /* The job result is inconsistent */
        JobResult = MEM_43_INFLS_INCONSISTENT;
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief    Returns the result of the last job.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_GetJobResult(uint32 InstanceIndex,
                                                         Mem_43_INFLS_JobRuntimeInfoType * JobInfo
                                                        )
{
    C40_Ip_StatusType          Status;
    Mem_43_INFLS_JobResultType JobResult;
    Mem_43_INFLS_JobType       JobType = JobInfo->JobType;

    switch (JobType)
    {
        case MEM_43_INFLS_JOB_ERASE:
            /* Process ongoing erase asynchronous hardware job. */
            Status = C40_Ip_MainInterfaceSectorEraseStatus();
            break;

        case MEM_43_INFLS_JOB_WRITE:
            /* Process ongoing write asynchronous hardware job. */
            Status = C40_Ip_MainInterfaceWriteStatus();
            break;

        case MEM_43_INFLS_JOB_HWSPECIFICSERVICE:
            /* Process ongoing hardware service job. */
            Status = Mem_43_INFLS_IPW_HwServiceGetJobResult(InstanceIndex, JobInfo);
            break;

        default:
            Status = C40_IP_STATUS_SUCCESS;
            break;
    };

#if (STD_ON == C40_IP_SECTOR_SET_LOCK_API)
    /* The job has finished. Time to lock the sector */
    if ((C40_IP_STATUS_SUCCESS == Status) && (JobInfo->Length == 0U) && (JobInfo->Address != 0U))
    {
        /* Get the physical sector number. Address - 1U Make sure to get the exact sector that worked before */
        C40_Ip_VirtualSectorsType VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address - 1U);

    if (C40_IP_STATUS_SUCCESS != C40_Ip_SetLock(VirtualSector, (uint8)Mem_43_INFLS_u8DomainID))
    {
        /* Sector locking failed */
        Status = C40_IP_STATUS_ERROR;
    }
}
#endif /* STD_ON == C40_IP_SECTOR_SET_LOCK_API */

    JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief       Cancel an ongoing flash read, write, erase or compare job.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Cancel(uint32 InstanceIndex)
{
    C40_Ip_StatusType          Status = C40_IP_STATUS_SUCCESS;
    Mem_43_INFLS_JobResultType JobResult;

    /* Abort a program or erase operation */
    Status = C40_Ip_Abort();

    JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}

/**
 * @brief Report ECC Error value result for IP Layer.
 */
void Mem_43_INFLS_IPW_ReportEccValueToLayerUnder(void)
{
    C40_Ip_ReportEccUnCorrectedError();
}


#if (MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON)
/**
 * @brief       Suspend a current operation of Flash erase sector command.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_ArrayIntegrityCheckSuspend(uint32 InstanceIndex)
{
    C40_Ip_StatusType  Status;
    Mem_43_INFLS_JobResultType JobResult;

    Status = C40_Ip_ArrayIntegrityCheckSuspend();

    JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}

/**
 * @brief       Resume a current operation of Flash erase sector command.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_ArrayIntegrityCheckResume(uint32 InstanceIndex)
{
    C40_Ip_StatusType  Status;
    Mem_43_INFLS_JobResultType JobResult;

    Status = C40_Ip_ArrayIntegrityCheckResume();

    JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}

Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_ArrayIntegrityCheck(uint32 InstanceIndex,
                                                                Mem_43_INFLS_JobRuntimeInfoType *JobInfo
                                                               )
{
    uint32 BlockBaseAddr;
    C40_Ip_StatusType Status;
    Mem_43_INFLS_JobResultType JobResult;
    const Mem_43_INFLS_UtestConfigType * UtestConfig = JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].UtestConfig;

    BlockBaseAddr = Mem_43_INFLS_IPW_GetAddrFormBlockNumber(UtestConfig->BlockReceiveCheck);
    Status = C40_Ip_ArrayIntegrityCheck(BlockBaseAddr,
                                        UtestConfig->ArrayIntegritySequenceType,
                                        UtestConfig->BreakPointsType,
                                        JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].MisrSeedValues,
                                        (uint8)Mem_43_INFLS_u8DomainID
                                       );
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        JobResult = MEM_43_INFLS_JOB_PENDING;
    }
    else
    {
        /* Operation failed. Command is sent */
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }
    (void)InstanceIndex;
    return JobResult;
}

Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_UserMarginReadCheck
(
    uint32                           InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType *JobInfo
)
{
    uint32 BlockBaseAddr;
    C40_Ip_StatusType Status;
    Mem_43_INFLS_JobResultType JobResult;
    const Mem_43_INFLS_UtestConfigType * UtestConfig = JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].UtestConfig;

    BlockBaseAddr = Mem_43_INFLS_IPW_GetAddrFormBlockNumber(UtestConfig->BlockReceiveCheck);
    Status = C40_Ip_UserMarginReadCheck(BlockBaseAddr,
                                        UtestConfig->BreakPointsType,
                                        UtestConfig->MarginLevelType,
                                        JobInfo->UtestRuntime[JobInfo->UtestConfigIndex].MisrSeedValues,
                                        (uint8)Mem_43_INFLS_u8DomainID
                                       );
    if (C40_IP_STATUS_SUCCESS == Status)
    {
        JobResult = MEM_43_INFLS_JOB_PENDING;
    }
    else
    {
        /* Operation failed. Command is sent */
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }

    (void)InstanceIndex;

    return JobResult;
}
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_EccLogicCheck
(
    const Mem_43_INFLS_EccLogicCheckDataType *EccCheckData
)
{
    C40_Ip_StatusType Status;
    Mem_43_INFLS_JobResultType JobResult;

    Status = C40_Ip_EccLogicCheck( EccCheckData->AddressCheck,
                                   EccCheckData->DataValue,
                                   EccCheckData->EccDataCheckBitValue
                                 );
    if ( Status != C40_IP_STATUS_ERROR)
    {
        JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    }
    else
    {
        /* Operation failed. Command is sent */
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }
    return JobResult;
}

Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_EdcAfterEccLogicCheck
(
   const Mem_43_INFLS_EccLogicCheckDataType *EccCheckData
)
{
    C40_Ip_StatusType Status;
    Mem_43_INFLS_JobResultType JobResult;

    Status = C40_Ip_EdcAfterEccLogicCheck(  EccCheckData->AddressCheck,
                                            EccCheckData->DataValue,
                                            EccCheckData->EccDataCheckBitValue
                                         );
    if ( Status != C40_IP_STATUS_ERROR)
    {
        JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    }
    else
    {
        /* Operation failed. Command is sent */
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }

    return JobResult;
}

Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_AddressEncodeLogicCheck
(
    const Mem_43_INFLS_AddressEncodeDataType *AddressEncodeData
)
{
    C40_Ip_StatusType Status;
    Mem_43_INFLS_JobResultType JobResult;

    Status = C40_Ip_AddressEncodeLogicCheck(
                                            AddressEncodeData->AddressCheck,
                                            AddressEncodeData->InvertBits
                                           );

    if ( Status != C40_IP_STATUS_ERROR)
    {
        JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    }
    else
    {
        /* Operation failed. Command is sent */
        JobResult = MEM_43_INFLS_JOB_FAILED;
    }

    return JobResult;
}
#endif /* MEM_43_INFLS_HW_UTESTMODE_SERVICE == STD_ON */


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
