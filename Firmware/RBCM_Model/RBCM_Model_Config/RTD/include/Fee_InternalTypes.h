/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : none
* Dependencies         : MemAcc
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 5.0.0
* Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
* in accordance with the applicable license terms.  By expressly accepting
* such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain,
* install, activate or otherwise use the software.
*
==================================================================================================*/

#ifndef FEE_INTERNALTYPES_H
#define FEE_INTERNALTYPES_H

/**
*   @file
*
*   @addtogroup FEE
*   @implements Fee_InternalTypes.h_Artifact
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Fee_Features.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FEE_INTERNALTYPES_VENDOR_ID                       43
#define FEE_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION        4
#define FEE_INTERNALTYPES_AR_RELEASE_MINOR_VERSION        7
#define FEE_INTERNALTYPES_AR_RELEASE_REVISION_VERSION     0
#define FEE_INTERNALTYPES_SW_MAJOR_VERSION                5
#define FEE_INTERNALTYPES_SW_MINOR_VERSION                0
#define FEE_INTERNALTYPES_SW_PATCH_VERSION                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this file and Fee_Features.h header file are of the same vendor */
#if (FEE_INTERNALTYPES_VENDOR_ID != FEE_FEATURES_VENDOR_ID)
    #error "Fee_InternalTypes.h and Fee_Features.h have different vendor IDs"
#endif

/* Check if this file and Fee_Features.h header file are of the same AUTOSAR version */
#if ((FEE_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION != FEE_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_INTERNALTYPES_AR_RELEASE_MINOR_VERSION != FEE_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != FEE_FEATURES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR version numbers of Fee_InternalTypes.h and Fee_Features.h are different"
#endif

/* Check if this file and Fee_Features.h header file are of the same software version */
#if ((FEE_INTERNALTYPES_SW_MAJOR_VERSION != FEE_FEATURES_SW_MAJOR_VERSION) || \
     (FEE_INTERNALTYPES_SW_MINOR_VERSION != FEE_FEATURES_SW_MINOR_VERSION) || \
     (FEE_INTERNALTYPES_SW_PATCH_VERSION != FEE_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee_InternalTypes.h and Fee_Features.h are different"
#endif


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief        Status of Fee block header
* @api
*/
typedef enum
{
    FEE_BLOCK_VALID = 0,         /**< @brief Fee block is valid */
    FEE_BLOCK_INVALID,           /**< @brief Fee block is invalid (has been invalidated) */
    FEE_BLOCK_INCONSISTENT,      /**< @brief Fee block is inconsistent (contains bogus data) */
    FEE_BLOCK_HEADER_INVALID,    /**< @brief Fee block header is garbled */
    FEE_BLOCK_INVALIDATED,       /**< @brief Fee block header is invalidated by Fee_InvalidateBlock(BlockNumber)(not used when
                                      FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF) */
    FEE_BLOCK_HEADER_BLANK,      /**< @brief Fee block header is blank, it is used to mark the end of Fee block header list
                                      when parsing the memory at initialization*/
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
    FEE_BLOCK_INCONSISTENT_COPY  /**< @brief FEE data read error during swap (ie data area was allocated) */
#else
    FEE_BLOCK_INCONSISTENT_COPY, /**< @brief FEE data read error during swap (ie data area was allocated) */
    FEE_BLOCK_NEVER_WRITTEN      /**< @brief FEE block was never written in data memacc */
#endif
} Fee_BlockStatusType;

/**
* @brief        Status of Fee cluster header
* @api
*/
typedef enum
{
    FEE_CLUSTER_VALID = 0,       /**< @brief Fee cluster is valid */
    FEE_CLUSTER_INVALID,         /**< @brief Fee cluster is invalid */
    FEE_CLUSTER_INCONSISTENT,    /**< @brief Fee cluster is inconsistent (contains bogus data) */
    FEE_CLUSTER_HEADER_INVALID   /**< @brief Fee cluster header is garbled */
} Fee_ClusterStatusType;

/**
* @brief        Type of job currently executed by Fee_MainFunction
* @api
*/
typedef enum
{
    /* Fee_Read() related jobs */
    FEE_JOB_READ = 0,                /**< @brief Read Fee block */

    /* Fee_Write() related jobs */
    FEE_JOB_WRITE,                   /**< @brief Write Fee block to memacc */
    FEE_JOB_WRITE_DATA,              /**< @brief Write Fee block data to memacc */
    FEE_JOB_WRITE_UNALIGNED_DATA,    /**< @brief Write unaligned rest of Fee block data to memacc */
    FEE_JOB_WRITE_VALIDATE,          /**< @brief Validate Fee block by writing validation flag to memacc */
    FEE_JOB_WRITE_DONE,              /**< @brief Finalize validation of Fee block */

    /* Fee_InvalidateBlock() related jobs */
    FEE_JOB_INVAL_BLOCK,             /**< @brief Invalidate Fee block by writing the invalidation flag to memacc */
    FEE_JOB_INVAL_BLOCK_DONE,        /**< @brief Finalize invalidation of Fee block */

    /* Fee_EraseImmediateBlock() related jobs */
    FEE_JOB_ERASE_IMMEDIATE,         /**< @brief Erase (pre-allocate) immediate Fee block */

    /* Fee_Init() realted jobs */
    FEE_JOB_INT_SCAN,                /**< @brief Initialize the cluster scan job */
    FEE_JOB_INT_SCAN_CLR,            /**< @brief Scan active cluster of current cluster group */
    FEE_JOB_INT_SCAN_CLR_HDR_PARSE,  /**< @brief Parse Fee cluster header */
    FEE_JOB_INT_SCAN_CLR_FMT,        /**< @brief Format first Fee cluster */
    FEE_JOB_INT_SCAN_CLR_FMT_DONE,   /**< @brief Finalize format of first Fee cluster */
    FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE,/**< @brief Parse Fee block header */

    /* Internal swap jobs */
    FEE_JOB_INT_SWAP_CLR_FMT,        /**< @brief Format current Fee cluster in current Fee cluster group */
    FEE_JOB_INT_SWAP_BLOCK,          /**< @brief Copy next block from source to target cluster */
    FEE_JOB_INT_SWAP_DATA_READ,      /**< @brief Read data from source cluster to internal Fee buffer */
    FEE_JOB_INT_SWAP_DATA_WRITE,     /**< @brief Write data from internal Fee buffer to target cluster */
    FEE_JOB_INT_SWAP_CLR_VLD_DONE,   /**< @brief Finalize cluster validation */

    /* Fee system jobs */
    FEE_JOB_DONE,                    /**< @brief No more subsequent jobs to schedule */

    /* Fee_Setmode() related job */
    FEE_JOB_SETMODE                  /**< @brief Setmode to MemAcc */
} Fee_JobType;
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Type of translation jobs to translate emulation address to logical address.
* @api
*/
typedef enum
{
    FEE_TRANS_JOB_READ = 0,            /**< @brief Translation read data from MemAcc */
    FEE_TRANS_JOB_WRITE,               /**< @brief Translation write data to MemAcc */
    FEE_TRANS_JOB_ERASE,               /**< @brief Translation erase MemAcc subAdressAreas */
} Fee_TranslationJobType;
#endif

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief        Fee cluster group run-time status
* @api
*/
typedef struct
{
    uint32 DataAddrIt;        /**< @brief Address of current Fee data block in memacc */
    uint32 HdrAddrIt;         /**< @brief Address of current Fee block header in memacc */
    uint32 ActClrID;                   /**< @brief ID of active cluster */
    uint8 ActClr;                      /**< @brief Index of active cluster */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    Fee_ClusterRuntimeInfoType *ClrInfo;   /**< @brief Pointer to array of Fee cluster runtime infomation */
#endif
} Fee_ClusterGroupInfoType;

/**
* @brief        Fee block run-time status
* @api
*/
typedef struct
{
    uint32 DataAddr;          /**< @brief Address of Fee block data in memacc */
    uint32 InvalidAddr;       /**< @brief Address of Fee block invalidation field in memacc */
    Fee_BlockStatusType BlockStatus;   /**< @brief Current status of Fee block */
} Fee_BlockInfoType;

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* FEE_INTERNALTYPES_H */
