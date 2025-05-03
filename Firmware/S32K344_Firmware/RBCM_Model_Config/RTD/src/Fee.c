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

/**
*   @file
*
*   @addtogroup FEE
*   @implements Fee.c_Artifact
*
*   @{
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
#include "Mcal.h"
#include "Fee.h"
#include "Fee_InternalTypes.h"
#include "Fee_Cbk.h"
#include "SchM_Fee.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_C                      43
#define FEE_AR_RELEASE_MAJOR_VERSION_C       4
#define FEE_AR_RELEASE_MINOR_VERSION_C       7
#define FEE_AR_RELEASE_REVISION_VERSION_C    0
#define FEE_SW_MAJOR_VERSION_C               5
#define FEE_SW_MINOR_VERSION_C               0
#define FEE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_VENDOR_ID)
    #error "Fee.c and Fee.h have different vendor ids"
#endif

/* Check if current file and Fee header file are of the same AUTOSAR version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_AR_RELEASE_REVISION_VERSION) \
    )
        #error "AUTOSAR version numbers of Fee.c and Fee.h are different"
#endif

/* Check if source file and Fee header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee.c and Fee.h are different"
#endif

/* Check if source file and Fee_InternalTypes.h header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_INTERNALTYPES_VENDOR_ID)
    #error "Fee.c and Fee_InternalTypes.h have different vendor IDs"
#endif

/* Check if source file and Fee_InternalTypes.h header file are of the same AUTOSAR version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C != FEE_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR version numbers of Fee.c and Fee_InternalTypes.h are different"
#endif

/* Check if source file and Fee_InternalTypes.h header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_INTERNALTYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee.c and Fee_InternalTypes.h are different"
#endif

/* Check if source file and Fee_Cbk.h header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_CBK_VENDOR_ID)
    #error "Fee.c and Fee_Cbk.h have different vendor IDs"
#endif

/* Check if source file and Fee_Cbk.h header file are of the same AUTOSAR version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C != FEE_CBK_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_CBK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR version numbers of Fee.c and Fee_Cbk.h are different"
#endif

/* Check if source file and Fee_Cbk.h header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_CBK_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_CBK_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_CBK_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee.c and Fee_Cbk.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FEE_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fee.c and Mcal.h are different"
    #endif
    /* Check if source file and SchM_Fee.h file are of the same version */
    #if ((FEE_AR_RELEASE_MAJOR_VERSION_C != SCHM_FEE_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_AR_RELEASE_MINOR_VERSION_C != SCHM_FEE_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fee.c and SchM_Fee.h are different"
    #endif

    #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /* Check if source file and DET header file are of the same version */
        #if ((FEE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (FEE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Fee.c and Det.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/* The Offset of flag status part in the cluster header */
#define FEE_CLUSTER_HEADER_STATUS_OFFSET     (FEE_CLUSTER_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE))
/* The Offset of flag status part in the block header */
#define FEE_BLOCK_HEADER_STATUS_OFFSET      (FEE_BLOCK_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE))
/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(uint8)
*
*/
#define FEE_SERIALIZE_UINT8(ParamVal, pSerialPtr) \
{ \
    *((uint8*)((Fee_UintPtrType)(pSerialPtr))) = (ParamVal); \
    (pSerialPtr) = &((pSerialPtr)[sizeof(uint8)]); \
}
/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(uint16)
*
*/
#define FEE_SERIALIZE_UINT16(ParamVal, pSerialPtr) \
{ \
    *((uint16*)((Fee_UintPtrType)(pSerialPtr))) = (ParamVal); \
    (pSerialPtr) = &((pSerialPtr)[sizeof(uint16)]); \
}
/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(uint32)
*
*/
#define FEE_SERIALIZE_UINT32(ParamVal, pSerialPtr) \
{ \
    *((uint32*)((Fee_UintPtrType)(pSerialPtr))) = (ParamVal); \
    (pSerialPtr) = &((pSerialPtr)[sizeof(uint32)]); \
}
/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(uint32)
*
*/
#define FEE_SERIALIZE_ADDRESS(ParamVal, pSerialPtr) \
{ \
    *((uint32*)((Fee_UintPtrType)(pSerialPtr))) = (ParamVal); \
    (pSerialPtr) = &((pSerialPtr)[sizeof(uint32)]); \
}
/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(uint32)
*
*/
#define FEE_SERIALIZE_LENGTH(ParamVal, pSerialPtr) \
{ \
    *((uint32*)((Fee_UintPtrType)(pSerialPtr))) = (ParamVal); \
    (pSerialPtr) = &((pSerialPtr)[sizeof(uint32)]); \
}

/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(uint8)
*
*/
#define FEE_DESERIALIZE_UINT8(pDeserialPtr, ParamVal) \
{ \
    (ParamVal) = *(const uint8*)((Fee_UintPtrType)(pDeserialPtr)); \
    (pDeserialPtr) = &((pDeserialPtr)[sizeof(uint8)]); \
}
/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(uint16)
*
*/
#define FEE_DESERIALIZE_UINT16(pDeserialPtr, ParamVal) \
{ \
    (ParamVal) = *(const uint16*)((Fee_UintPtrType)(pDeserialPtr)); \
    (pDeserialPtr) = &((pDeserialPtr)[sizeof(uint16)]); \
}
/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(uint32)
*
*/
#define FEE_DESERIALIZE_UINT32(pDeserialPtr, ParamVal) \
{ \
    (ParamVal) = *(const uint32*)((Fee_UintPtrType)(pDeserialPtr)); \
    (pDeserialPtr) = &((pDeserialPtr)[sizeof(uint32)]); \
}
/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(uint32)
*
*/
#define FEE_DESERIALIZE_ADDRESS(pDeserialPtr, ParamVal) \
{ \
    (ParamVal) = *(const uint32*)((Fee_UintPtrType)(pDeserialPtr)); \
    (pDeserialPtr) = &((pDeserialPtr)[sizeof(uint32)]); \
}
/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(uint32)
*
*/
#define FEE_DESERIALIZE_LENGTH(pDeserialPtr, ParamVal) \
{ \
    (ParamVal) = *(const uint32*)((Fee_UintPtrType)(pDeserialPtr)); \
    (pDeserialPtr) = &((pDeserialPtr)[sizeof(uint32)]); \
}
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define FEE_START_SEC_VAR_CLEARED_BOOLEAN
#include "Fee_MemMap.h"
/**
* @brief        Internal variable used to trigger a cluster swap. Used by the swap job.
*/
static boolean bSwapToBePerformed; /* implicit zero initialization to FALSE */
#define FEE_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_CLEARED_8
#include "Fee_MemMap.h"
/**
* @brief        Pointer to user data buffer. Used by the read Fee jobs
*/
static uint8 *Fee_pJobReadDataDestPtr; /* implicit zero initialization to NULL_PTR */

/**
* @brief        Pointer to user data buffer. Used by the write Fee jobs
*/
static const uint8 *Fee_pJobWriteDataDestPtr; /* implicit zero initialization to NULL_PTR */

/**
* @brief        Data buffer used by all jobs to store immediate data
*/
VAR_ALIGN(static uint8 Fee_aDataBuffer[FEE_DATA_BUFFER_SIZE], 4U) /* implicit zero initialization */
/**
* @brief        Internal cluster group iterator. Used by the scan and swap jobs
*               Warning: do not use it outside scan and swap functions
*                        (because it will be Out of Range)
*/
static uint8 Fee_uJobIntClrGrpIt; /* implicit zero initialization */

/**
* @brief        Internal cluster iterator. Used by the scan and swap jobs
*/
static uint8 Fee_uJobIntClrIt; /* implicit zero initialization */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Number of attempts when erasing each subAddressArea in the cluster in swap phase
*/
static uint8 Fee_uTransJobEraseRetries; /* implicit zero initialization */
#endif
#define FEE_STOP_SEC_VAR_CLEARED_8
#include "Fee_MemMap.h"


#define FEE_START_SEC_VAR_CLEARED_16
#include "Fee_MemMap.h"

/**
* @brief        Fee block index. Used by all Fee jobs
*/
static uint16 Fee_uJobBlockIndex; /* implicit zero initialization */

/**
* @brief        Internal block iterator. Used by the swap job
*/
static uint16 Fee_uJobIntBlockIt; /* implicit zero initialization */

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Used to keep the number of foreign blocks found when parsing the data memacc.
*               It represents the number of elements from the Fee_aForeignBlockConfig array.
*/
static uint16 Fee_uForeignBlocksNumber; /* implicit zero initialization */
#endif
#define FEE_STOP_SEC_VAR_CLEARED_16
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_CLEARED_32
#include "Fee_MemMap.h"

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
/**
* @brief        Run-time information about blocks touching the Reserved Area
* @implements   Fee_aReservedAreaTouched_Object
*/
static uint32 Fee_aReservedAreaTouched[(FEE_MAX_NR_OF_BLOCKS + ((sizeof(uint32) * 8U)-1U)) / (sizeof(uint32) * 8U)]; /* implicit zero initialization */
#endif

#define FEE_STOP_SEC_VAR_CLEARED_32
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
/**
* @brief        Currently executed job (including internal one)
*/
static Fee_JobType Fee_eJob = FEE_JOB_DONE;

/**
* @brief        Fee job which started internal management job(s) such as swap...
*/
static Fee_JobType Fee_eJobIntOriginalJob = FEE_JOB_DONE;

#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

/**
* @brief        Internal state of Fee module
*/
static MemIf_StatusType Fee_eModuleStatus;  /* implicit zero initialization to MEMIF_UNINIT */

/**
* @brief        Result of last Fee module job
*/
static MemIf_JobResultType Fee_eJobResult; /* implicit zero initialization to MEMIF_JOB_OK */
/**
* @brief        Fee block Offset. Used by the read Fee job
*/
static uint32 Fee_uJobBlockOffset; /* implicit zero initialization */

/**
* @brief        Number of bytes to read. Used by the read Fee job
*/
static uint32 Fee_uJobBlockLength; /* implicit zero initialization */

/**
* @brief        Internal memacc helper address iterator. Used by the scan and
*               swap jobs
*/
static uint32 Fee_uJobIntAddrIt; /* implicit zero initialization */

/**
* @brief        Internal address of current block header. Used by the swap job
*/
static uint32 Fee_uJobIntHdrAddr; /* implicit zero initialization */

/**
* @brief        Internal address of current data block. Used by the swap job.
*/
static uint32 Fee_uJobIntDataAddr; /* implicit zero initialization */

/**
* @brief        Run-time information of all configured Fee blocks. Contains
*               status, and data information. Used by all jobs
* @implements   Fee_aBlockInfo_Object
*/
static Fee_BlockInfoType Fee_aBlockInfo[FEE_MAX_NR_OF_BLOCKS]; /* implicit zero initialization */

/**
* @brief        Run-time information of all configured cluster groups
*/
static Fee_ClusterGroupInfoType Fee_aClrGrpInfo[FEE_NUMBER_OF_CLUSTER_GROUPS]; /* implicit zero initialization */

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Used to keep the config of the foreign blocks
*/
static Fee_BlockConfigType Fee_aForeignBlockConfig[FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS]; /* implicit zero initialization */
#endif
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Internal state of Fee translation jobs
*/
static Fee_TranslationJobType Fee_eTransJob; /* implicit zero initialization to FEE_TRANS_JOB_READ */

/**
* @brief        Number of bytes to read. Used by the Fee translation jobs
*/
static uint32 Fee_uTransJobLength; /* implicit zero initialization */

/**
* @brief        Point to current cluster. Used by the Fee translation jobs
*/
static Fee_ClusterRuntimeInfoType *Fee_pTransJobCluster; /* implicit zero initialization to NULL_PTR */

/**
* @brief        Point to current subAddressArea. Used by the Fee translation jobs and to scan the cluster header
*/
static Fee_SubAddressAreaRuntimeInfoType *Fee_pTransJobSubAddressArea; /* implicit zero initialization to NULL_PTR */

/**
* @brief        Pointer to internal data buffer. Used by the Fee translation jobs read and write
*/
static uint32 Fee_pTransJobBuffer; /* implicit zero initialization */
#endif
#define FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

/*==================================================================================================
*                                   GLOBAL FUNCTION DECLARATION
==================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

#if !defined(__DOXYGEN__)

/* Job end notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_END_NOTIFICATION_DECL

/* Job error notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_ERROR_NOTIFICATION_DECL

/* Cluster format notification routine provided by the upper layer module (declaration) */
FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL

#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Fee_SerializeBlockHdr(const Fee_BlockType *BlockHder,
                                  const uint32 TargetAddress,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                                  const Fee_BlockAssignmentType BlockAssignment,
#endif
                                  uint8 *BlockHdrPtr
                                 );

static Std_ReturnType Fee_BlankCheck(const uint8 *TargetPtr, const uint8 *const TargetEndPtr);

static Std_ReturnType Fee_DeserializeFlag(const uint8 *const TargetPtr, const uint8 FlagPattern, boolean *pFlagValue);

static Fee_BlockStatusType Fee_DeserializeBlockHdr(Fee_BlockType *const BlockHder,
                                                   uint32 *const TargetAddress,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                                                   uint8 *const BlockAssignment,
#endif
                                                   const uint8 *BlockHdrPtr
                                                  );

static Fee_ClusterStatusType Fee_DeserializeClusterHdr(Fee_ClusterHeaderType *ClrHdr,
                                                       const uint8 *ClrHdrPtr
                                                      );

static void Fee_SerializeClusterHdr(const Fee_ClusterHeaderType *ClrHdr,
                                    uint8 *ClrHdrPtr
                                   );

static uint16 Fee_GetBlockIndex(const uint16 BlockNumber);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
static uint16 Fee_GetForeignBlockIndex(const uint16 BlockNumber);

static inline Fee_BlockAssignmentType Fee_GetBlockAssignment(const uint16 BlockRuntimeInfoIndex);

static inline MemIf_JobResultType Fee_UpdateForeignBlockConfigInfo(uint16 *ForeignBlockIndex,
                                                                   const Fee_BlockType *BlockHder,
                                                                   Fee_BlockAssignmentType BlockAssignment
                                                                  );
#endif

static inline uint16 Fee_GetBlockNumber(const uint16 BlockRuntimeInfoIndex);

static inline uint16 Fee_GetBlockSize(const uint16 BlockRuntimeInfoIndex);

static inline uint8 Fee_GetBlockClusterGrp(const uint16 BlockRuntimeInfoIndex);

static inline boolean Fee_GetBlockImmediate(const uint16 BlockRuntimeInfoIndex);

static inline void Fee_TranferJobResultMemAccToMemif(MemAcc_JobResultType MemAcc_JobResult);

static uint16 Fee_AlignToVirtualPageSize(uint16 BlockSize);

static void Fee_CopyDataToPageBuffer(const uint8 *SourcePtr, uint8 *TargetPtr, const uint16 Length);

static void Fee_SerializeFlag(uint8 *TargetPtr, const uint8 FlagPattern);

static MemIf_JobResultType Fee_JobInternalSwapClusterVld(void);

static void Fee_JobGetHdrBlock(Fee_BlockType *BlockHder);

static MemIf_JobResultType Fee_JobInternalSwapBlock(void);

static MemIf_JobResultType Fee_JobInternalSwapClusterFmt(void);

static MemIf_JobResultType Fee_JobInternalSwapClusterErase(void);

static MemIf_JobResultType Fee_JobInternalSwap(void);
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
static MemIf_JobResultType Fee_JobInternalSwapRetry(void);
#endif
static MemIf_JobResultType Fee_JobInternalScanBlockHdrRead(void);

static MemIf_JobResultType Fee_JobInternalScanClusterErase(void);

static MemIf_JobResultType Fee_JobInternalScanCluster(void);

static MemIf_JobResultType Fee_JobInternalScanClusterFmt(void);

static MemIf_JobResultType Fee_JobInternalScanClusterFmtDone(void);

static MemIf_JobResultType Fee_JobInternalScanBlockHdrParse(const boolean BufferValid);

static MemIf_JobResultType Fee_JobCheckBlockHeaderMatchesFeeConfigOrNot(uint16 BlockIndex,
                                                                        uint16 BlockRuntimeInfoIndex,
                                                                        const Fee_BlockType *BlockHder,
                                                                        uint32 DataAddr,
                                                                        Fee_BlockStatusType BlockStatus);
static inline boolean Fee_JobInternalScanClusterHdrDone(void);

static MemIf_JobResultType Fee_JobInternalScanClusterHdrRead(void);

static MemIf_JobResultType Fee_JobInternalScan(void);

static MemIf_JobResultType Fee_JobInternalScanClusterHdrParse(const boolean BufferValid);

static MemIf_JobResultType Fee_JobReadBlock(void);

static MemIf_JobResultType Fee_JobInternalSwapBlockVld(void);

static MemIf_JobResultType Fee_JobInternalSwapDataRead(const boolean BufferValid);

static MemIf_JobResultType Fee_JobInternalSwapDataWrite(const boolean BufferValid);

static MemIf_JobResultType Fee_JobInternalSwapClusterVldDone(void);

static MemIf_JobResultType Fee_JobWriteHdr(void);

static MemIf_JobResultType Fee_JobWriteBlockData(void);

static MemIf_JobResultType Fee_JobWriteBlock(void);

static MemIf_JobResultType Fee_JobWriteBlockUnalignedData(void);

static MemIf_JobResultType Fee_JobWriteBlockValidate(void);

static MemIf_JobResultType Fee_JobWriteBlockDone(void);

static MemIf_JobResultType Fee_JobInvalidateBlock(void);

static MemIf_JobResultType Fee_JobInvalidateBlockDone(void);

static MemIf_JobResultType Fee_JobEraseImmediateBlock(void);

static MemIf_JobResultType Fee_JobSchedule(void);

static MemIf_JobResultType Fee_JobScheduleAfterSwapClusterVldDone(void);

static boolean Fee_ReservedAreaWritable(void);

static void Fee_JobErrorSchedule(void);

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
static inline boolean Fee_ReservedAreaTargetedInClrGrp(const uint8 ClrGrpIndex);

static inline uint32 Fee_PowerOf2Of5LSB(const uint32 InVal);

static inline boolean Fee_ReservedAreaTouchedByBlock(const uint16 BlockNumber);

static inline void Fee_TouchReservedAreaByBlock(const uint16 BlockNumber);

static inline void Fee_UntouchReservedAreaByClrGrp(const uint8 ClrGrpIndex);

static inline void Fee_UntouchReservedAreaAll(void);
#endif /* FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON */

static inline boolean Fee_IsBlockMatchedConfig(uint16 BlockIndex,
                                               uint16 BlockRuntimeInfoIndex,
                                               const Fee_BlockType *BlockHder,
                                               uint32 DataAddr
                                              );

static inline void Fee_UpdateBlockRuntimeInfo(uint16 BlockRuntimeInfoIndex,
                                              Fee_BlockStatusType BlockStatus,
                                              uint32 DataAddr,
                                              boolean ImmediateBlock
                                             );
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)

static void Fee_GetSubAddressAreaRunTimeInfo(uint8 ClrGrpIndex,
                                             const Fee_ClusterGroupRuntimeInfoType *ClrGrpRTInfo
                                            );

#if (FEE_NUMBER_OF_SUBADDRESSAREAS_TO_RECOVER > 0U)
static uint32 Fee_GetRecoverSubAddressAreaSize(const Fee_SubAddressAreaRuntimeInfoType *BadSubAddressArea);

static void Fee_RecoverBadSubAddressAreas(Fee_ClusterRuntimeInfoType *Cluster);
#endif

static MemIf_JobResultType Fee_TransJobSchedule(void);

static Std_ReturnType Fee_TranslationJobRead(uint32 OffsetAddress);

static Std_ReturnType Fee_TranslationJobWrite(uint32 OffsetAddress);

static Std_ReturnType Fee_TranslationJobErase(void);

static Std_ReturnType Fee_TranslationJobEraseFailed(void);

static uint32 Fee_CalcMaxTransferLength(uint32 *LogicalAddress,
                                                   uint32 OffsetAddress
                                                   );

static uint32 Fee_CalcTransferOffset(uint32 emulationAddress);

static uint32 Fee_SerializeSubAddressAreasInfo(const Fee_ClusterRuntimeInfoType *ClrInfo,
                                               uint8 *ClrHdrPtr
                                              );

static Std_ReturnType Fee_DeserializeSubAddressAreasInfo(Fee_ClusterRuntimeInfoType *ClrInfo,
                                                         const uint8 *ClrHdrPtr
                                                        );

static inline Fee_SubAddressAreaRuntimeInfoType * Fee_GetLastSubAddressAreaList(uint8 ClrGrpIt,
                                                                                uint8 ClrIt
                                                                               );

static boolean Fee_ClusterUsable(uint32 ClusterLength);

#endif /* FEE_SUBADDRESSAREA_RETIREMENT == STD_ON */
static Std_ReturnType Fee_ReadFromMemAcc(uint32 SourceAddress,
                                         const uint8 *TargetAddressPtr,
                                         uint32 Length
                                        );

static Std_ReturnType Fee_WriteToMemAcc(uint32 TargetAddress,
                                        const uint8 *SourceAddressPtr,
                                        uint32 Length
                                       );

static Std_ReturnType Fee_EraseCluster(uint8 ClrGrpIt,
                                       uint8 ClrIt
                                      );

static inline uint32 Fee_GetClusterLength(uint8 ClrGrpIt,
                                                     uint8 ClrIt
                                                    );

static inline uint8 Fee_GetNextClusterToSwap(uint8 CurrentCluster);

static void Fee_DoJobErrorNotification(void);

static void Fee_ContinueHandleInternalJob(void);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


/*==================================================================================================
*                                       FEE JOB SCHEDULE LOOKUP TABLE AREA
==================================================================================================*/

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/* Function prototypes */
static inline MemIf_JobResultType Fee_JobInternalScanClusterHdrParse_Wrapper(void);
static inline MemIf_JobResultType Fee_JobInternalScanBlockHdrParse_Wrapper(void);
static inline MemIf_JobResultType Fee_JobInternalSwapDataRead_Wrapper(void);
static inline MemIf_JobResultType Fee_JobInternalSwapDataWrite_Wrapper(void);
static inline MemIf_JobResultType Fee_JobSystemDone(void);


/**
* @brief    A wrapper function for Fee_JobInternalScanClusterHdrParse
*
*/
static inline MemIf_JobResultType Fee_JobInternalScanClusterHdrParse_Wrapper(void)
{
    return Fee_JobInternalScanClusterHdrParse(TRUE);
}

/**
* @brief    A wrapper function for Fee_JobInternalScanBlockHdrParse
*
*/
static inline MemIf_JobResultType Fee_JobInternalScanBlockHdrParse_Wrapper(void)
{
    return Fee_JobInternalScanBlockHdrParse(TRUE);
}

/**
* @brief    A wrapper function for Fee_JobInternalSwapDataRead
*
*/
static inline MemIf_JobResultType Fee_JobInternalSwapDataRead_Wrapper(void)
{
    return Fee_JobInternalSwapDataRead(TRUE);
}

/**
* @brief    A wrapper function for Fee_JobInternalSwapDataWrite
*
*/
static inline MemIf_JobResultType Fee_JobInternalSwapDataWrite_Wrapper(void)
{
    return Fee_JobInternalSwapDataWrite(TRUE);
}

/**
* @brief     Fee job done
*
*/
static inline MemIf_JobResultType Fee_JobSystemDone(void)
{
    return MEMIF_JOB_FAILED;
}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


#define FEE_START_SEC_CONST_32
#include "Fee_MemMap.h"

/**
* @brief     List of Fee job functions, used by Fee_JobSchedule
*            The order of functions in this table must be identical
*            with the enumeration Fee_JobType from Fee_InternalTypes.h
*
*/
static MemIf_JobResultType (*const Fee_JobScheduleLookupTable[])(void) =
{
    /* Fee_Read() related jobs */
    &Fee_JobReadBlock,                                /* FEE_JOB_READ */

    /* Fee_Write() related jobs */
    &Fee_JobWriteBlock,                               /* FEE_JOB_WRITE */
    &Fee_JobWriteBlockData,                           /* FEE_JOB_WRITE_DATA */
    &Fee_JobWriteBlockUnalignedData,                  /* FEE_JOB_WRITE_UNALIGNED_DATA */
    &Fee_JobWriteBlockValidate,                       /* FEE_JOB_WRITE_VALIDATE */
    &Fee_JobWriteBlockDone,                           /* FEE_JOB_WRITE_DONE */

    /* Fee_InvalidateBlock() related jobs */
    &Fee_JobInvalidateBlock,                          /* FEE_JOB_INVAL_BLOCK */
    &Fee_JobInvalidateBlockDone,                      /* FEE_JOB_INVAL_BLOCK_DONE */

    /* Fee_EraseImmediateBlock() related jobs */
    &Fee_JobEraseImmediateBlock,                      /* FEE_JOB_ERASE_IMMEDIATE */

    /* Fee_Init() realted jobs */
    &Fee_JobInternalScan,                             /* FEE_JOB_INT_SCAN */
    &Fee_JobInternalScanCluster,                      /* FEE_JOB_INT_SCAN_CLR */
    &Fee_JobInternalScanClusterHdrParse_Wrapper,      /* FEE_JOB_INT_SCAN_CLR_HDR_PARSE */
    &Fee_JobInternalScanClusterFmt,                   /* FEE_JOB_INT_SCAN_CLR_FMT */
    &Fee_JobInternalScanClusterFmtDone,               /* FEE_JOB_INT_SCAN_CLR_FMT_DONE */
    &Fee_JobInternalScanBlockHdrParse_Wrapper,        /* FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE */

    /* Internal swap jobs */
    &Fee_JobInternalSwapClusterFmt,                   /* FEE_JOB_INT_SWAP_CLR_FMT */
    &Fee_JobInternalSwapBlock,                        /* FEE_JOB_INT_SWAP_BLOCK */
    &Fee_JobInternalSwapDataRead_Wrapper,             /* FEE_JOB_INT_SWAP_DATA_READ */
    &Fee_JobInternalSwapDataWrite_Wrapper,            /* FEE_JOB_INT_SWAP_DATA_WRITE */
    &Fee_JobInternalSwapClusterVldDone,               /* FEE_JOB_INT_SWAP_CLR_VLD_DONE */

    /* Fee system jobs done */
    &Fee_JobSystemDone,                               /* FEE_JOB_DONE */
};

#define FEE_STOP_SEC_CONST_32
#include "Fee_MemMap.h"


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/**
* @brief   Returns the cluster group for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         uint8
* @retval         cluster group number
* @pre            -
*/
static inline uint8 Fee_GetBlockClusterGrp(const uint16 BlockRuntimeInfoIndex)
{
    uint8 BlockClusterGrp;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockClusterGrp = Fee_BlockConfig[BlockRuntimeInfoIndex].ClrGrp;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        BlockClusterGrp = Fee_aForeignBlockConfig[BlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].ClrGrp;
    }
#else
        /* the config is part of Fee_BlockConfig*/
        BlockClusterGrp = Fee_BlockConfig[BlockRuntimeInfoIndex].ClrGrp;
#endif

    return BlockClusterGrp;
}

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
/**
* @brief Checks whether the area specified by Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt
*              and Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt touches the Reserved Area.
* @param[in] ClrGrpIndex - Cluster Group Index
* @return boolean
* @retval TRUE The Reserved Area is touched.
* @retval FALSE The Reserved Area is not touched.
*
* @pre Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt must be up to date
* @pre Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt must be up to date
*
* @implements   Fee_ReservedAreaTargetedInClrGrp_Activity
*
*/
static inline boolean Fee_ReservedAreaTargetedInClrGrp(const uint8 ClrGrpIndex)
{
    boolean RetVal;
    uint32 AvailClrSpace;
    uint32 ReservedSpace;

    /* Reserved space of cluster group*/
    ReservedSpace = Fee_ClrGrps[ ClrGrpIndex ].ReservedSize;

    /* Calculate available space in active cluster */
    AvailClrSpace = Fee_aClrGrpInfo[ ClrGrpIndex ].DataAddrIt -
                    Fee_aClrGrpInfo[ ClrGrpIndex ].HdrAddrIt;

    if ((FEE_BLOCK_OVERHEAD + ReservedSpace) > AvailClrSpace)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }

    return RetVal;
}

/**
* @brief Function to compute the power of 2 out of the 5 LSB bits of InVal value.
* @return uint32
* @retval Power of 2 computed out of the 5 LSB bits of InVal value.
*
* @param[in] InVal - value out of which 5 LSB bits is taken as an input for the
*                     power of 2 computation
*
* @implements   Fee_PowerOf2Of5LSB_Activity
*
*/
static inline uint32 Fee_PowerOf2Of5LSB(const uint32 InVal)
{
    return (uint32)(0x00000001UL << (InVal & 0x1FUL));
}

/**
* @brief Returns the information about touching the Reserved Area by the block
*         specified by uBlockuNumber.
* @return boolean
* @retval TRUE - the Reserved Area is touched by the block
* @retval FALSE - the Reserved Area is not touched by the block
*
* @param[in] BlockNumber - number of the block under request
*
* @implements   Fee_ReservedAreaTouchedByBlock_Activity
*
*/
static inline boolean Fee_ReservedAreaTouchedByBlock(const uint16 BlockNumber)
{
    uint32 Idx;
    boolean RetVal;

    /*The Block information is stored by 1 bit, 32 blocks will be stored in one element of Fee_aReservedAreaTouched*/
    /*Calculate index of the element that store the block information*/
    Idx = ((uint32)BlockNumber) >> 5U;
    /*Check if the bit is 1*/
    if (0U != (Fee_aReservedAreaTouched[ Idx ] & Fee_PowerOf2Of5LSB((uint32)BlockNumber)))
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief Stores the information about touching the Reserved Area for the block
*           specified by BlockNumber.
* @return void
*
* @param[in] BlockNumber - number of the block touching the Reserved Area
*
* @implements   Fee_TouchReservedAreaByBlock_Activity
*
*/
static inline void Fee_TouchReservedAreaByBlock(const uint16 BlockNumber)
{
    uint32 Idx;

    Idx = ((uint32)BlockNumber) >> 5U;

    Fee_aReservedAreaTouched[Idx] |= Fee_PowerOf2Of5LSB((uint32)BlockNumber);
}

/**
* @brief Removes the information about touching the Reserved Area for all blocks
*           within a cluster group specified by ClrGrpIndex.
* @return void
*
* @param[in] ClrGrpIndex - see above
*
* @implements   Fee_UntouchReservedAreaByClrGrp_Activity
*
*/
static inline void Fee_UntouchReservedAreaByClrGrp(const uint8 ClrGrpIndex)
{
    uint32 BlockIt;
    uint32 Idx = 0UL;
    uint32 Mask = 0x00000001UL;
    uint8  BlockClusterGrp;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for (BlockIt = 0U; BlockIt < ((uint32)FEE_CRT_CFG_NR_OF_BLOCKS + (uint32)Fee_uForeignBlocksNumber); BlockIt++)
#else
    for (BlockIt = 0U; BlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; BlockIt++)
#endif
    {
        /*Get cluster group of block "BlockIt"*/
        BlockClusterGrp = Fee_GetBlockClusterGrp((uint16)BlockIt);

        /*Check if the block "BlockIt" is in ClrGrpIndex*/
        if (ClrGrpIndex == BlockClusterGrp)
        {
            /*Remove information bit of the block*/
            Fee_aReservedAreaTouched[Idx] &= (~Mask);
        }
        /*Check if the block is the last block in one element of Fee_aReservedAreaTouched*/
        if (0x80000000UL == Mask)
        {
            /*Reset Mask to the 1st bit*/
            Mask = 0x00000001UL;
            /*Move to the next element of Fee_aReservedAreaTouched*/
            Idx++;
        }
        else
        {
            /*Move to next bit for next block "BlockIt+1"*/
            Mask = Mask << 1U;
        }
    }
}

/**
* @brief Removes information about touching the Reserved Area globally for all blocks.
* @return void
*
* @implements   Fee_UntouchReservedAreaAll_Activity
*
*/
static inline void Fee_UntouchReservedAreaAll(void)
{
    uint32 Idx;

    for (Idx = 0UL; Idx < (sizeof(Fee_aReservedAreaTouched)/sizeof(*Fee_aReservedAreaTouched)); Idx++)
    {
        Fee_aReservedAreaTouched[Idx] = 0x00000000UL;
    }
}
#endif /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) */

/**
* @brief        Serialize Fee block parameters into a write buffer
*
* @param[in]    BlockHder       hder block (block number and Length)
* @param[in]    TargetAddress   Logical address of Fee block in MemAcc adress
*                                space
* @param[out]   BlockHdrPtr     Pointer to serialization buffer
*
* @pre          BlockHdrPtr must be valid pointer
*
*/
static void Fee_SerializeBlockHdr(const Fee_BlockType *BlockHder,
                                  const uint32 TargetAddress,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                                  const Fee_BlockAssignmentType BlockAssignment,
#endif
                                  uint8 *BlockHdrPtr
                                 )
{
    uint32 CheckSum = 0UL;
    const uint8 *TargetEndPtr;
    uint8 *TempBlockHdrPtr = BlockHdrPtr;

    TargetEndPtr = &BlockHdrPtr[FEE_BLOCK_OVERHEAD];

    /* Calculate the block header Checksum */
    CheckSum = ((uint32) BlockHder->BlockNumber) + ((uint32) BlockHder->Length) + TargetAddress;

    /* Use MSB of the Checksum for the immediate block flag so the Checksum is 31-bit */
    if (TRUE == (BlockHder->ImmediateBlock))
    {
        CheckSum += 1U;
        CheckSum |= 0x80000000U;
    }
    else
    {
        CheckSum &= 0x7fffffffU;
    }
    /*Serialize Fee block parameters into a write buffer*/
    FEE_SERIALIZE_UINT16(BlockHder->BlockNumber, TempBlockHdrPtr)

    FEE_SERIALIZE_UINT16(BlockHder->Length, TempBlockHdrPtr)

    FEE_SERIALIZE_ADDRESS(TargetAddress, TempBlockHdrPtr)

    FEE_SERIALIZE_UINT32(CheckSum, TempBlockHdrPtr)

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    FEE_SERIALIZE_UINT8((uint8)BlockAssignment, TempBlockHdrPtr)
#endif

    /* Fill rest of the header with the erase pattern */
    for ( ; TempBlockHdrPtr < TargetEndPtr; TempBlockHdrPtr++)
    {
        *TempBlockHdrPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief          Check whether specified data buffer contains only
*                 the FEE_ERASED_VALUE value
*
* @param[in]      TargetPtr     pointer to start of the checked buffer
* @param[in]      TargetEndPtr  pointer to end + 1 of the checked buffer
*
* @return         Std_ReturnType
* @retval         E_OK           The buffer contains only erased value
* @retval         E_NOT_OK       The buffer doesn't contain only erased value
*
* @pre            TargetPtr and TargetEndPtr pointers must be valid
*
*/
static Std_ReturnType Fee_BlankCheck(const uint8 *TargetPtr, const uint8 *const TargetEndPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    const uint8 *TempTargetPtr = TargetPtr;

    for ( ; TempTargetPtr < TargetEndPtr; TempTargetPtr++)
    {
        if (FEE_ERASED_VALUE == *TempTargetPtr)
        {
            /* Pattern match */
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return RetVal;
}

/**
* @brief        Deserialize the valid or invalid flag from a read buffer
*
* @param[in]    TargetPtr       Pointer to the read buffer
* @param[in]    FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
* @param[out]   pFlagValue       TRUE if flag of above type is set
*
* @return       Std_ReturnType
* @retval       E_OK             The flag is set or cleared and rest of the read buffer
*                                (FEE_VIRTUAL_PAGE_SIZE - 1) contains FEE_ERASED_VALUE
* @retval       E_NOT_OK         Buffer doesn't contain valid flag data. It's garbled...
*
* @pre          TargetPtr and pFlagValue pointers must be valid
*
*/
static Std_ReturnType Fee_DeserializeFlag(const uint8 *const TargetPtr, const uint8 FlagPattern, boolean *pFlagValue)
{
    Std_ReturnType RetVal;

    if ((FlagPattern == *TargetPtr) || (FEE_ERASED_VALUE == *TargetPtr))
    {
        /* The bytePattern can be either present or not */
        if (FlagPattern == *TargetPtr)
        {
            *pFlagValue = TRUE;
        }
        else
        {
            *pFlagValue = FALSE;
        }

        /* Check rest of the FEE_VIRTUAL_PAGE_SIZE */
        RetVal = Fee_BlankCheck(&TargetPtr[1], &TargetPtr[FEE_VIRTUAL_PAGE_SIZE]);
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}

/**
* @brief        Deserialize Fee block header parameters from read buffer
*
* @param[out]   BlockHder               Fee BlockHder( Pblock number and Length)
* @param[out]   TargetAddress           Logical address of Fee block in MemAcc adress space
* @param[in]    BlockHdrPtr             Pointer to read buffer
*
* @return       Fee_BlockStatusType
* @retval       FEE_BLOCK_VALID          Fee block is valid
* @retval       FEE_BLOCK_INVALID        Fee block is invalid (has been invalidated)
* @retval       FEE_BLOCK_INCONSISTENT   Fee block is inconsistent, it may contain corrupted data...
* @retval       FEE_BLOCK_HEADER_INVALID Fee block header is invalid (garbled)
* @retval       FEE_BLOCK_HEADER_BLANK   Fee block header is filled with FEE_ERASED_VALUE
*
* @pre          BlockHdrPtr             pointer must be valid
*
*/
static Fee_BlockStatusType Fee_DeserializeBlockHdr(Fee_BlockType *const BlockHder,
                                                   uint32 *const TargetAddress,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                                                   uint8 *const BlockAssignment,
#endif
                                                   const uint8 *BlockHdrPtr
                                                  )
{
    Fee_BlockStatusType RetVal = FEE_BLOCK_INVALID;
    uint32 ReadCheckSum;
    uint32 CalcCheckSum;
    const uint8 *TargetEndPtr;
    const uint8 *TempBlockHdrPtr = BlockHdrPtr;
    boolean FlagValid = FALSE;
    boolean FlagInvalid = FALSE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_OFF)
    uint8 ReservedSpace;
#endif

    if (Fee_BlankCheck(BlockHdrPtr, &BlockHdrPtr[FEE_BLOCK_OVERHEAD]) == ((Std_ReturnType)E_OK))
    {
        RetVal = FEE_BLOCK_HEADER_BLANK;
    }
    else
    {
        /* Check 1st part of the header */
        TargetEndPtr = &BlockHdrPtr[FEE_BLOCK_HEADER_STATUS_OFFSET];

        FEE_DESERIALIZE_UINT16(TempBlockHdrPtr,BlockHder->BlockNumber)

        FEE_DESERIALIZE_UINT16(TempBlockHdrPtr,BlockHder->Length)

        FEE_DESERIALIZE_ADDRESS(TempBlockHdrPtr, *TargetAddress)

        FEE_DESERIALIZE_UINT32(TempBlockHdrPtr, ReadCheckSum)

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        FEE_DESERIALIZE_UINT8(TempBlockHdrPtr, *BlockAssignment)
#else
        /* BlockHdrPtr must be advanced with 1 bytes.
         * the reason is to avoid blank check for this area reserved for BlockAssignment even when
         * SWAP_FOREIGN is disabled to allow disabling SWAP_FOREIGN at production time. */
        FEE_DESERIALIZE_UINT8(TempBlockHdrPtr, ReservedSpace)

        /* variable ReservedSpace not used */
        (void)ReservedSpace;
#endif
        /* Use MSB of Checksum for immediate block flag so
           the Checksum is 31-bit long */
        CalcCheckSum = BlockHder->Length + *TargetAddress + BlockHder->BlockNumber;

        if (0U == (ReadCheckSum & 0x80000000U))
        {
            BlockHder->ImmediateBlock = FALSE;
        }
        else
        {
            BlockHder->ImmediateBlock = TRUE;
            CalcCheckSum += 1U;
        }

        /* Ignore MSB since it's used for ImmediateBlock flag */
        if (((ReadCheckSum & 0x7fffffffU) != (CalcCheckSum & 0x7fffffffU)) ||
            (((Std_ReturnType)E_OK) != Fee_BlankCheck(TempBlockHdrPtr, TargetEndPtr)) ||
            (((Std_ReturnType)E_OK) != Fee_DeserializeFlag(TargetEndPtr, FEE_VALIDATED_VALUE, &FlagValid)) ||
            (((Std_ReturnType)E_OK) != Fee_DeserializeFlag(&TargetEndPtr[FEE_VIRTUAL_PAGE_SIZE], FEE_INVALIDATED_VALUE, &FlagInvalid))
           )
        {
            RetVal = FEE_BLOCK_HEADER_INVALID;
        }
        else
        {
            /* Block header is valid */
            if (TRUE == FlagValid)
            {
                if (FALSE == FlagInvalid)
                {
                    RetVal = FEE_BLOCK_VALID;           /* TRUE vs FALSE */
                }
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                else
                {
                    RetVal = FEE_BLOCK_INVALIDATED;     /* TRUE vs TRUE */
                }
#endif
            }
            else
            {
                if (FALSE == FlagInvalid)
                {
                    RetVal = FEE_BLOCK_INCONSISTENT;    /* FALSE vs FALSE */
                }
            }
        }
    }

    return RetVal;
}
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Deserialize the subAddressAreas information of Fee cluster from read buffer
*
*/
static Std_ReturnType Fee_DeserializeSubAddressAreasInfo(Fee_ClusterRuntimeInfoType *ClrInfo,
                                                         const uint8 *ClrHdrPtr
                                                        )
{
    Std_ReturnType RetVal = E_NOT_OK;
    const uint8 *TempClrHdrPtr = ClrHdrPtr;
    uint16 SubAddressAreaCountHdr;
    uint16 Offset;
    uint8 DataTemp;
    uint32 i;

    /* Deserialize the first byte for number of subAddressAreas */
    FEE_DESERIALIZE_UINT16(TempClrHdrPtr, SubAddressAreaCountHdr)
    if (SubAddressAreaCountHdr == ClrInfo->SubAddressAreaCount)
    {
        /* SubAddressArea count is matched, compare the unused bytes with zero values */
        RetVal = E_OK;

        /* The unused bits in the first unused bytes */
        Offset = SubAddressAreaCountHdr >> 3U;
        DataTemp = TempClrHdrPtr[Offset] >> SubAddressAreaCountHdr;

        do
        {
            if (0U != DataTemp)
            {
                RetVal = E_NOT_OK;
                break;
            }
            Offset++;
            DataTemp = TempClrHdrPtr[Offset];
        }
        while (Offset < (FEE_CLUSTER_HEADER_SUBADDRESSAREAINFO_SIZE - 2U));  /* Skip 2-byte of subAddressArea count */
    }

    /* Parse the subAddressAreas information from header to runtime data */
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Overwrite the runtime data */
        ClrInfo->SubAddressAreaCount = SubAddressAreaCountHdr;
        /* Start from subAddressArea 0 */
        Offset = 0U;  
        /* Deserialize the subAddressAreasList status, process 8 bits at a time to speed up */
        while (SubAddressAreaCountHdr > 8U)
        {
            /* Read from buffer */
            FEE_DESERIALIZE_UINT8(TempClrHdrPtr, DataTemp)

            for (i = 0U ; i < 8U; i++)
            {
                if (0U == (DataTemp & 1U))
                {
                    /* bad subAddressArea: decrease cluster Length and mark subAddressArea as bad */
                    ClrInfo->Length -= ClrInfo->SubAddressAreaList[Offset].SubAddressAreaSize;
                    ClrInfo->SubAddressAreaList[Offset].SubAddressAreaSize = 0U;
                }

                DataTemp >>= 1U;
                Offset++;
            }
            SubAddressAreaCountHdr -= 8U;
        }

        /* Process remaining bits one by one */
        FEE_DESERIALIZE_UINT8(TempClrHdrPtr, DataTemp)
        for (i = 0U ; i < SubAddressAreaCountHdr; i++)
        {
            if (0U == (DataTemp & 1U))
            {
                /* bad subAddressArea: decrease cluster Length and mark subAddressArea as bad */
                ClrInfo->Length -= ClrInfo->SubAddressAreaList[Offset].SubAddressAreaSize;
                ClrInfo->SubAddressAreaList[Offset].SubAddressAreaSize = 0U;
            }

            DataTemp >>= 1U;
            Offset++;
        }
    }

    return RetVal;
}
#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */
/**
* @brief        Deserialize Fee cluster header parameters from read buffer
*
* @param[out]   pClrID                     32-bit cluster ID
* @param[out]   pStartAddress              Logical address of Fee cluster in MemAcc address space
* @param[out]   pClusteSize                Size of Fee cluster in bytes
* @param[in]    ClrHdrPtr                 Pointer to read buffer
*
* @return       Fee_ClusterStatusType
* @retval       FEE_CLUSTER_VALID          Fee cluster is valid
* @retval       FEE_CLUSTER_INVALID        Fee cluster has been invalidated
* @retval       FEE_CLUSTER_INCONSISTENT   Fee cluster is inconsistent, it may
*                                          contain corrupted data
* @retval       FEE_CLUSTER_HEADER_INVALID Fee cluster header is invalid (garbled)
*
* @pre          ClrHdrPtr pointer must be valid
*
*/
static Fee_ClusterStatusType Fee_DeserializeClusterHdr(Fee_ClusterHeaderType *ClrHdr,
                                                       const uint8 *ClrHdrPtr
                                                      )
{
    Fee_ClusterStatusType RetVal = FEE_CLUSTER_HEADER_INVALID;
    uint32 CheckSumHdr;
    uint32 CheckSumCal;
    boolean FlagValid = FALSE;
    boolean FlagInvalid = FALSE;
    const uint8 *TargetEndPtr;
    const uint8 *TempClrHdrPtr = ClrHdrPtr;
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    const uint8 *SubAddressAreasInfoPtr;
    uint16 SubAddressAreaCount;
    uint32 i;
#endif
    /* Check 1st part of the header */
    TargetEndPtr = &ClrHdrPtr[FEE_CLUSTER_HEADER_STATUS_OFFSET];

    FEE_DESERIALIZE_UINT32(TempClrHdrPtr, ClrHdr->ClrID)

    FEE_DESERIALIZE_ADDRESS(TempClrHdrPtr, ClrHdr->StartAddr)

    FEE_DESERIALIZE_LENGTH(TempClrHdrPtr, ClrHdr->Length)

    CheckSumCal = ClrHdr->ClrID + ClrHdr->StartAddr + ClrHdr->Length;
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    /* Start address subAddressAreas information */
    SubAddressAreasInfoPtr = TempClrHdrPtr;

    /* Include 2-byte of the number of subAddressAreas into the Checksum */
    FEE_DESERIALIZE_UINT16(TempClrHdrPtr, SubAddressAreaCount)
    CheckSumCal += (uint32)SubAddressAreaCount;

    /* Include each byte of the subAddressAreas information into the Checksum */
    for (i = 0U; i < (FEE_CLUSTER_HEADER_SUBADDRESSAREAINFO_SIZE - 2U); i++)
    {
        CheckSumCal += (uint32)(*TempClrHdrPtr);
        TempClrHdrPtr++;
    }
#endif
    FEE_DESERIALIZE_UINT32(TempClrHdrPtr, CheckSumHdr)

    if ((CheckSumCal != CheckSumHdr) ||
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        (((Std_ReturnType)E_OK) != Fee_DeserializeSubAddressAreasInfo(ClrHdr->ClrInfo, SubAddressAreasInfoPtr)) ||
#endif
        (((Std_ReturnType)E_OK) != Fee_BlankCheck(TempClrHdrPtr, TargetEndPtr)) ||
        (((Std_ReturnType)E_OK) != Fee_DeserializeFlag(TargetEndPtr, FEE_VALIDATED_VALUE, &FlagValid)) ||
        (((Std_ReturnType)E_OK) != Fee_DeserializeFlag(&TargetEndPtr[FEE_VIRTUAL_PAGE_SIZE],FEE_INVALIDATED_VALUE, &FlagInvalid))
       )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else if (FALSE == FlagInvalid)
    {
        if (FALSE == FlagValid)
        {
            RetVal = FEE_CLUSTER_INCONSISTENT;
        }
        else
        {
            RetVal = FEE_CLUSTER_VALID;
        }
    }
    else
    {
        RetVal = FEE_CLUSTER_INVALID;
    }
    return(RetVal);
}
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Serialize        Fee cluster header subAddressAreas information to write buffer
*
* @param[in]    ClrInfo          Pointer to the cluster information
* @param[out]   ClrHdrPtr       Pointer to write buffer
*
* @pre          ClrHdrPtr       pointer must be valid
*
*/
static uint32 Fee_SerializeSubAddressAreasInfo(const Fee_ClusterRuntimeInfoType *ClrInfo,
                                               uint8 *ClrHdrPtr
                                              )
{
    uint8 *TempClrHdrPtr = ClrHdrPtr;
    const uint8 *TargetEndPtr = &ClrHdrPtr[FEE_CLUSTER_HEADER_SUBADDRESSAREAINFO_SIZE];
    uint32 i;
    uint32 DataTemp = 0U;
    uint32 CheckSum;  /* Checksum of 16 bytes subAddressArea info */
    uint32 SubAddressAreaCount = (uint32)(ClrInfo->SubAddressAreaCount);
    const Fee_SubAddressAreaRuntimeInfoType *SubAddressAreaList = ClrInfo->SubAddressAreaList;

    /* Serialize the first 2-byte for number of subAddressAreas */
    FEE_SERIALIZE_UINT16((uint16)SubAddressAreaCount, TempClrHdrPtr)
    CheckSum = SubAddressAreaCount;

    /* Serialize the next rest bytes of subAddressAreas status, process 8 bits at a time to speed up */
    while (SubAddressAreaCount > 8U)
    {
        for (i = 0U ; i < 8U; i++)
        {
            DataTemp >>= 1U;
            if (SubAddressAreaList->SubAddressAreaSize != 0U)
            {
                DataTemp |= 0x80U;
            }
            SubAddressAreaList++;
        }

        /* Write to buffer */
        FEE_SERIALIZE_UINT8((uint8)DataTemp, TempClrHdrPtr)
        CheckSum += DataTemp;

        SubAddressAreaCount -= 8U;
    }

    /* Process remaining bits one by one */
    for (i = 0U ; i < SubAddressAreaCount; i++)
    {
        DataTemp >>= 1U;
        if (SubAddressAreaList->SubAddressAreaSize != 0U)
        {
            DataTemp |= 0x80U;
        }
        SubAddressAreaList++;
    }
    /* Fill rest bits of byte with the zero values: default = bad subAddressArea */
    DataTemp >>= (8U - SubAddressAreaCount);

    /* Write to buffer */
    FEE_SERIALIZE_UINT8((uint8)DataTemp, TempClrHdrPtr)
    CheckSum += DataTemp;

    /* Fill rest of FEE_CLUSTER_HEADER_SUBADDRESSAREAINFO_SIZE with the zero values: default = bad subAddressArea */
    for ( ; TempClrHdrPtr < TargetEndPtr; TempClrHdrPtr++)
    {
        *TempClrHdrPtr = 0U;
    }

    return CheckSum;
}
#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */
/**
* @brief        Serialize        Fee cluster header parameters to write buffer
*
* @param[in]    ClrHdr          Cluster header type
* @param[out]   ClrHdrPtr       Pointer to write buffer
*
* @pre          ClrHdrPtr       pointer must be valid
*
*/
static void Fee_SerializeClusterHdr(const Fee_ClusterHeaderType *ClrHdr,
                                    uint8 *ClrHdrPtr
                                   )
{
    uint32 CheckSum;
    const uint8 *TargetEndPtr;
    uint8 *TempClrHdrPtr = ClrHdrPtr;

    TargetEndPtr = &ClrHdrPtr[FEE_CLUSTER_OVERHEAD];

    /* Calculate the cluster header Checksum */
    CheckSum = ClrHdr->ClrID + ClrHdr->StartAddr + ClrHdr->Length;

    /*Fee cluster header parameters to write buffer*/
    FEE_SERIALIZE_UINT32(ClrHdr->ClrID, TempClrHdrPtr)

    FEE_SERIALIZE_ADDRESS(ClrHdr->StartAddr, TempClrHdrPtr)

    FEE_SERIALIZE_LENGTH(ClrHdr->Length, TempClrHdrPtr)
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    /* Serialize next 16 bytes of subAddressAreas status into the cluster header */
    CheckSum   += Fee_SerializeSubAddressAreasInfo(ClrHdr->ClrInfo, TempClrHdrPtr);
    TempClrHdrPtr = &TempClrHdrPtr[FEE_CLUSTER_HEADER_SUBADDRESSAREAINFO_SIZE];
#endif
    FEE_SERIALIZE_UINT32(CheckSum, TempClrHdrPtr)

    /* Fill rest of the header with the erase pattern */
    for ( ; TempClrHdrPtr < TargetEndPtr; TempClrHdrPtr++)
    {
        *TempClrHdrPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    BlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if BlockNumber is invalid
*
*/
static uint16 Fee_GetBlockIndex(const uint16 BlockNumber)
{
    sint32 Low = 0L;
    sint32 High = (sint32)FEE_CRT_CFG_NR_OF_BLOCKS - 1;
    sint32 Middle;
    uint16 RetVal = 0xFFFFU;

    /*Using binary search to find the index of BlockNumber*/
    while (Low <= High)
    {
        Middle = Low + ((High - Low) / 2);

        if (BlockNumber < Fee_BlockConfig[Middle].BlockNumber)
        {
            /*Store High for next searching*/
            High = Middle - 1;
        }
        else if (BlockNumber > Fee_BlockConfig[Middle].BlockNumber)
        {
            /*Store Low for next searching*/
            Low = Middle + 1;
        }
        else
        {
            /*BlockNumber is matched, store the index and return*/
            RetVal = (uint16)Middle;
            break;
        }
    }
    /*RetVal will be 0xFFFFU if BlockNumber is not matched with any index*/
    return RetVal;
}
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    BlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if BlockNumber is invalid
*
*/
static uint16 Fee_GetForeignBlockIndex(const uint16 BlockNumber)
{
    uint16 ForeignBlockIt;
    uint16 RetVal = 0xFFFFU;

    /*Only check when Fee_uForeignBlocksNumber large than 0*/
    if (Fee_uForeignBlocksNumber >= 1UL)
    {
        for (ForeignBlockIt = 0U; ForeignBlockIt < Fee_uForeignBlocksNumber; ForeignBlockIt++)
        {
            if (BlockNumber == Fee_aForeignBlockConfig[ForeignBlockIt].BlockNumber)
            {
                /*Found the block, store and return*/
                RetVal = ForeignBlockIt;
                break;
            }
        }
    }

    return RetVal;
}
/**
* @brief  Returns the block project assignement for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         Fee_BlockAssignmentType
* @retval         FEE_PROJECT_SHARED
* @retval         FEE_PROJECT_APPLICATION
* @retval         FEE_PROJECT_BOOTLOADER
* @retval         FEE_PROJECT_RESERVED
* @pre            -
*/
static inline Fee_BlockAssignmentType Fee_GetBlockAssignment(const uint16 BlockRuntimeInfoIndex)
{
    Fee_BlockAssignmentType BlockAssignment;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockAssignment = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockAssignment;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        BlockAssignment = Fee_aForeignBlockConfig[BlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].BlockAssignment;
    }
#else
        /* the config is part of Fee_BlockConfig*/
        BlockAssignment = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockAssignment;
#endif

    return BlockAssignment;
}
#endif


/**
* @brief  Returns the block size for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         uint16
* @retval         block size
* @pre            -
*/
static inline uint16 Fee_GetBlockSize(const uint16 BlockRuntimeInfoIndex)
{
    uint16 BlockSize;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockSize = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockSize;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        BlockSize = Fee_aForeignBlockConfig[BlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].BlockSize;
    }
#else
    /* the config is part of Fee_BlockConfig*/
    BlockSize = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockSize;
#endif

    return BlockSize;
}
/**
* @brief  Returns the block number for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         uint16
* @retval         block number
* @pre            -
*/
static inline uint16 Fee_GetBlockNumber(const uint16 BlockRuntimeInfoIndex)
{
    uint16 BlockNumber = 0U;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockNumber = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockNumber;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        BlockNumber = Fee_aForeignBlockConfig[BlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].BlockNumber;
    }
#else
    /* the config is part of Fee_BlockConfig*/
    BlockNumber = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockNumber;
#endif

    return BlockNumber;
}
/**
* @brief  Returns the immediate attribute for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         boolean
* @retval         value of the immediate attribute
* @pre            -
*/
static inline boolean Fee_GetBlockImmediate(const uint16 BlockRuntimeInfoIndex)
{
    boolean Immediate;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        Immediate = Fee_BlockConfig[BlockRuntimeInfoIndex].ImmediateData;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        Immediate = Fee_aForeignBlockConfig[BlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].ImmediateData;
    }
#else
    /* the config is part of Fee_BlockConfig*/
    Immediate = Fee_BlockConfig[BlockRuntimeInfoIndex].ImmediateData;
#endif

    return Immediate;
}
/**
* @brief        Adjusts passed size so it's integer multiple of pre-configured + FEE_VIRTUAL_PAGE_SIZE
*
* @param[in]    BlockSize        Fee block size (FeeBlockSize)
*
* @return       uint16
* @retval       Adjusted          Fee block size to integer multiple of FEE_VIRTUAL_PAGE_SIZE
*
*/
static uint16 Fee_AlignToVirtualPageSize(uint16 BlockSize)
{
    uint16 Retval = 0U;

    /* Check whether the block size is integer multiple of FEE_VIRTUAL_PAGE_SIZE */
    if (0U == (BlockSize % FEE_VIRTUAL_PAGE_SIZE))
    {
        /* block size is an integer multiple of FEE_VIRTUAL_PAGE_SIZE */
        Retval = BlockSize;
    }
    else
    {
        Retval = ((BlockSize / FEE_VIRTUAL_PAGE_SIZE) + 1U) * FEE_VIRTUAL_PAGE_SIZE;
    }

    return((uint16)Retval);
}

/**
* @brief        Copy data from user to internal write buffer and fills
*               rest of the write buffer with FEE_ERASED_VALUE
*
* @param[in]    SourcePtr        Pointer to user data buffer
* @param[out]   TargetPtr        Pointer to internal write buffer
* @param[in]    Length           Number of bytes to copy
*
* @pre          SourcePtr and TargetPtr must be valid pointers
* @pre          Length must be <= FEE_VIRTUAL_PAGE_SIZE
*
*/
static void Fee_CopyDataToPageBuffer(const uint8 *SourcePtr, uint8 *TargetPtr, const uint16 Length)
{
    const uint8 *TargetEndPtr = &TargetPtr[Length];
    const uint8 *PageEndPtr = &TargetPtr[FEE_VIRTUAL_PAGE_SIZE];
    uint8 *TempTargetPtr = TargetPtr;
    const uint8 *TempSourcePtr = SourcePtr;

    /* Copy data to page buffer */
    for ( ; TempTargetPtr < TargetEndPtr; TempTargetPtr++)
    {
        *TempTargetPtr = *TempSourcePtr;
        TempSourcePtr++;
    }

    /* Fill rest of the page buffer with FEE_ERASED_VALUE */
    for ( ; TempTargetPtr < PageEndPtr; TempTargetPtr++)
    {
        *TempTargetPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Serialize validation or invalidation flag to write buffer
*
* @param[out]   TargetPtr       Pointer to write buffer
* @param[in]    FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
*
* @pre          TargetPtr       must be valid pointer
*
*/
static void Fee_SerializeFlag(uint8 *TargetPtr, const uint8 FlagPattern)
{
    const uint8 *TargetEndPtr = &TargetPtr[FEE_VIRTUAL_PAGE_SIZE];
    uint8 *TempPtr = TargetPtr;

    *TempPtr = FlagPattern;
    TempPtr++;


    for (; TempPtr < TargetEndPtr; TempPtr++)
    {
        /*Store erase value to target address*/
        *TempPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Validate current Fee cluster in current Fee cluster group by
*               writing FEE_VALIDATED_VALUE into memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the write job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current cluster group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalSwapClusterVld(void)
{
    MemIf_JobResultType RetVal;
    uint32 StartAddr;

    /* Get start address of swap cluster */
    StartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;

    /* Serialize validation pattern to write buffer */
    Fee_SerializeFlag(Fee_aDataBuffer, FEE_VALIDATED_VALUE);

    /* Write validation pattern to memacc */
    if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc((StartAddr + FEE_CLUSTER_OVERHEAD) - (2U * FEE_VIRTUAL_PAGE_SIZE),
                                                  Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE
                                                 )
       )
    {
        /* MemAcc write job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* MemAcc write job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule subsequent Fee job */
    Fee_eJob = FEE_JOB_INT_SWAP_CLR_VLD_DONE;

    return RetVal;
}


static void Fee_JobGetHdrBlock(Fee_BlockType *BlockHder)
{
    /* get size of block */
    BlockHder->Length = Fee_GetBlockSize(Fee_uJobIntBlockIt);
    /* get ImmediateBlock of block */
    BlockHder->ImmediateBlock = Fee_GetBlockImmediate(Fee_uJobIntBlockIt);
    /* get BlockNumber of block */
    BlockHder->BlockNumber = Fee_GetBlockNumber(Fee_uJobIntBlockIt);
}
/**
* @brief        Copy next block from source to target cluster
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying MemAcc didn't accept the write job
*
* @pre          Fee_uJobIntBlockIt       must contain index of currently swaped
*                                        Fee block
* @pre          Fee_uJobBlockIndex       must contain index of Fee block which
*                                        caused the swap
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster
*                                        group
* @pre          Fee_uJobIntHdrAddr       must contain valid address of Fee block
*                                        header in target cluster
*
* @post         Fee_uJobIntHdrAddr is advanced on to next Fee block
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ, FEE_JOB_INT_SWAP_BLOCK,
* or            FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
* @implements   Fee_JobInternalSwapBlock_Activity
*/
static MemIf_JobResultType Fee_JobInternalSwapBlock(void)
{
    MemIf_JobResultType RetVal;
    uint32 DataAddr;
    Fee_BlockType BlockHder;
    uint16 AlignedBlockSize;
    uint8 BlockClusterGrp;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    Fee_BlockAssignmentType BlockAssignment;
#endif

    /* Find first valid or inconsistent block in same cluster group */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for ( ; Fee_uJobIntBlockIt < (FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber); Fee_uJobIntBlockIt++)
#else
    for ( ; Fee_uJobIntBlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; Fee_uJobIntBlockIt++)
#endif
    {
        /* get cluster group */
        BlockClusterGrp = Fee_GetBlockClusterGrp(Fee_uJobIntBlockIt);
        /* process only valid and inconsistent blocks from the current cluster */
        if ((Fee_uJobIntClrGrpIt == BlockClusterGrp) &&
            ((FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].BlockStatus) ||
             (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[Fee_uJobIntBlockIt].BlockStatus) ||
             (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[Fee_uJobIntBlockIt].BlockStatus)
            )
           )

        {
            break;
        }
        else
        {
            /* No match. Try next one... */
        }
    }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if ((FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber) == Fee_uJobIntBlockIt)
#else
    if (FEE_CRT_CFG_NR_OF_BLOCKS == Fee_uJobIntBlockIt)
#endif
    {
        /* No more matching blocks. Validate the cluster */
        RetVal = Fee_JobInternalSwapClusterVld();
    }
    else
    {
        /* Get header of block */
        Fee_JobGetHdrBlock(&BlockHder);

        #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        BlockAssignment = Fee_GetBlockAssignment(Fee_uJobIntBlockIt);
        #endif

        /* Data space no more allocated even for inconsistent immediate (pre-erased) blocks */
        if (FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].BlockStatus)
        {
            /* Align Fee block size to the virtual page boundary */
            AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockHder.Length);

            /* Calculate data address */
            DataAddr = Fee_uJobIntDataAddr - AlignedBlockSize;

            /* Update the block address info */
            Fee_uJobIntDataAddr = DataAddr;

            /* Initialize the data transfer iterator */
            Fee_uJobIntAddrIt = DataAddr;
        }
        else
        {
            /* Don't allocate data space for inconsistent block */
            DataAddr = 0U;
        }

        /* Serialize block header to the write buffer */
        Fee_SerializeBlockHdr(&BlockHder, DataAddr,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                              BlockAssignment,
#endif
                              Fee_aDataBuffer
                             );

        if (FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].BlockStatus)
        {
            /* Read block data */
            Fee_eJob = FEE_JOB_INT_SWAP_DATA_READ;
        }
        else
        {
            /* Nothing to read. Move on to next block */
            Fee_uJobIntBlockIt++;
            Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;
        }

        /* Write header block to memacc */
        if (((Std_ReturnType)E_OK) != Fee_WriteToMemAcc(Fee_uJobIntHdrAddr, Fee_aDataBuffer, FEE_BLOCK_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE)))
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* MemAcc write job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }

        /* Move on to next block header */
        Fee_uJobIntHdrAddr += FEE_BLOCK_OVERHEAD;
    }

    return RetVal;
}
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Check if the new erased cluster has enough memory space to contain
*               all blocks to be copied and the new block to be written.
*               If not, a new swap phase will be scheduled.
*
*/
static boolean Fee_ClusterUsable(uint32 ClusterLength)
{
    boolean RetVal;
    uint16 BlockIt;
    uint16 BlockSize;
    uint8 BlockClusterGrp;
    uint32 uNeededSize = (uint32)FEE_CLUSTER_OVERHEAD;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    uint16 uTotalBlocks = FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber;
#else
    uint16 uTotalBlocks = FEE_CRT_CFG_NR_OF_BLOCKS;
#endif

    /* Find all valid or inconsistent blocks in same cluster group */
    for (BlockIt = 0U ; BlockIt < uTotalBlocks; BlockIt++)
    {
        /* Get cluster group */
        BlockClusterGrp = Fee_GetBlockClusterGrp(BlockIt);
        /* Process only valid and inconsistent blocks from the current cluster */
        if ((Fee_uJobIntClrGrpIt == BlockClusterGrp) &&
            ((FEE_BLOCK_VALID == Fee_aBlockInfo[BlockIt].BlockStatus) ||
             (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[BlockIt].BlockStatus) ||
             (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[BlockIt].BlockStatus)
            )
           )
        {
            uNeededSize += (uint32)FEE_BLOCK_OVERHEAD;

            BlockSize   = Fee_GetBlockSize(BlockIt);
            uNeededSize += (uint32)Fee_AlignToVirtualPageSize(BlockSize);
        }
    }

    /* Only count the new block to write in case it's not an immediate one */
    if (FALSE == Fee_GetBlockImmediate(Fee_uJobBlockIndex))
    {
        uNeededSize += (uint32)FEE_BLOCK_OVERHEAD;

        BlockSize   = Fee_GetBlockSize(Fee_uJobBlockIndex);
        uNeededSize += (uint32)Fee_AlignToVirtualPageSize(BlockSize);
    }

    /* Reserved space of this cluster group*/
    uNeededSize += (uint32)Fee_ClrGrps[Fee_uJobIntClrGrpIt].ReservedSize;

    /* Now compare the two sizes */
    if (ClusterLength >= uNeededSize)
    {
        /* This cluster is usable */
        RetVal = TRUE;
    }
    else
    {
        /* Cannot use this cluster */
        RetVal = FALSE;
    }

    return RetVal;
}

/**
* @brief        Re-initialize the cluster swap internal operation on
*               the next cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase job,
*                                        or the current Fee group does not have enough clusters to swap in subAddressArea retirement mode
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_eJob                 must contain type of Fee job which caused the cluster swap
*
* @post         Schedule erase of the target cluster
*
*
*/
static MemIf_JobResultType Fee_JobInternalSwapRetry(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;
    uint8 CurrentCluster;
    uint8 NextCluster;

    /* Get cluster index of swap job */
    CurrentCluster = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClr;
    /* Get the next cluster to erase */
    NextCluster = Fee_GetNextClusterToSwap(CurrentCluster);

    if (NextCluster != CurrentCluster)  /* Check if group has enough clusters */
    {
        /* Save index of cluster to swap to */
        Fee_uJobIntClrIt = NextCluster;
        /* Erase the swap cluster */
        RetVal = Fee_JobInternalSwapClusterErase();
    }

    return RetVal;
}
#endif /* FEE_SUBADDRESSAREA_RETIREMENT == STD_ON */
/**
* @brief        Format current Fee cluster in current Fee cluster group by
*               writing cluster header into memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the write job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_uJobIntClrIt         must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
*
*/
static MemIf_JobResultType Fee_JobInternalSwapClusterFmt(void)
{
    MemIf_JobResultType RetVal;
    Fee_ClusterHeaderType ClrHdr;
    uint32 ClusterLength;

    ClusterLength = Fee_GetClusterLength(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt);
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    if (FALSE == Fee_ClusterUsable(ClusterLength))
    {
        /* Bad cluster: try with the next cluster */
        RetVal = Fee_JobInternalSwapRetry();
    }
    else
#endif
    {
        ClrHdr.StartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;
        ClrHdr.Length = ClusterLength;
        ClrHdr.ClrID = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClrID + 1U;

        #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        ClrHdr.ClrInfo = &(Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ClrInfo[Fee_uJobIntClrIt]);
        #endif
        /* Build cluster header with new ActClrID + 1 */
        Fee_SerializeClusterHdr(&ClrHdr, Fee_aDataBuffer);

        /* Write the cluster header to memacc */
        if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(ClrHdr.StartAddr, Fee_aDataBuffer, FEE_CLUSTER_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE)))
        {
            /* MemAcc read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* Calculate header address: Move on to the first block header */
        Fee_uJobIntHdrAddr = ClrHdr.StartAddr + FEE_CLUSTER_OVERHEAD;

        /* Calculate data address: Move on to the end of cluster */
        Fee_uJobIntDataAddr = ClrHdr.StartAddr + ClrHdr.Length;

        /* Reset the block iterator */
        Fee_uJobIntBlockIt = 0U;

        /* Schedule cluster format done job */
        Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;
    }
    return RetVal;
}

/**
* @brief        Erase current Fee cluster in current Fee cluster group by erasing memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_uJobIntClrIt         must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_FMT subsequent job
*
*
*/
static MemIf_JobResultType Fee_JobInternalSwapClusterErase(void)
{
    MemIf_JobResultType RetVal;

    /* Erase cluster */
    if (((Std_ReturnType)E_OK) == Fee_EraseCluster(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt))
    {
        /* MemAcc read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* MemAcc read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format job */
    Fee_eJob = FEE_JOB_INT_SWAP_CLR_FMT;

    return RetVal;
}

/**
* @brief        Calculate the index of the next cluster in current cluster group.
*               In subAddressArea retirement mode, find the next good cluster with Length greater than zero.
*
* @return       The index of the next cluster to be erased in the group
*/
static inline uint8 Fee_GetNextClusterToSwap(uint8 CurrentCluster)
{
    uint8 NextCluster = CurrentCluster;
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    /* Check if this group cluster was bad (all clusters were bad) */
    if (0U != Fee_GetClusterLength(Fee_uJobIntClrGrpIt, CurrentCluster))
    {
        /* Find the next good cluster */
        do
        {
            NextCluster++;

            if (NextCluster == Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrCount)
            {
                /* Cluster roll over */
                NextCluster = 0U;
            }
        }
        while (0U == Fee_GetClusterLength(Fee_uJobIntClrGrpIt, NextCluster));
    }

#else
    /* Calculate index of cluster to swap to */
    NextCluster++;

    if (NextCluster == Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrCount)
    {
        /* Cluster roll over */
        NextCluster = 0U;
    }
#endif
    return NextCluster;
}

/**
* @brief        Initialize the cluster swap internal operation on
*               current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase job,
*                                        or the current Fee group does not have enough clusters to swap in subAddressArea retirement mode
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_eJob                 must contain type of Fee job which caused the cluster swap
*
* @post         Fee module status is set to MEMIF_BUSY_INTERNAL
* @post         Fee_eJob is stored in Fee_eJobIntOriginalJob so it can be rescheduled
*               once the swap operation is finished
* @post         Fee internal block iterator Fee_uJobIntBlockIt is set to zero
* @post         Fee internal cluster iterator Fee_uJobIntClrIt is set to
*               the target cluster
* @post         Fee_uJobIntHdrAddr and Fee_uJobIntDataAddr addresses are initialized to
*               point to the target cluster
* @post         Schedule erase of the target cluster
*
*
*/
static MemIf_JobResultType Fee_JobInternalSwap(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;
    uint8 CurrentCluster;
    uint8 NextCluster;

    /* Get cluster index the block belongs to */
    CurrentCluster = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClr;
    /* Get the next cluster to erase */
    NextCluster = Fee_GetNextClusterToSwap(CurrentCluster);
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    if (NextCluster != CurrentCluster)  /* Check if group has enough clusters */
#endif
    {
        /* Save index of cluster to swap to */
        Fee_uJobIntClrIt = NextCluster;

        /* Store type of original job so Fee can re-schedule
           this job once the swap is complete */
        Fee_eJobIntOriginalJob = Fee_eJob;

        /* Erase the swap cluster */
        RetVal = Fee_JobInternalSwapClusterErase();
    }
    return RetVal;
}

/**
* @brief        Read the Fee block header into internal buffer
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying MemAcc accepted the read job
* @retval       MEMIF_JOB_FAILED Underlying MemAcc didn't accept the read job
*
* @pre          Fee_uJobIntAddrIt must contain valid logical address of
*               Fee block header to read
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScanBlockHdrRead(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    /* Read the block header */
    if (((Std_ReturnType)E_OK) != Fee_ReadFromMemAcc(Fee_uJobIntAddrIt, Fee_aDataBuffer, FEE_BLOCK_OVERHEAD))
    {
        /* MemAcc read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* MemAcc read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }

    Fee_eJob = FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE;

    return RetVal;
}

/**
* @brief        Erase first Fee cluster in current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScanClusterErase(void)
{
    MemIf_JobResultType RetVal;

    /* Erase first cluster in the current cluster group */
    if (((Std_ReturnType)E_OK) == Fee_EraseCluster(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt))
    {
        /* MemAcc read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* MemAcc read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format job */
    Fee_eJob = FEE_JOB_INT_SCAN_CLR_FMT;

    return RetVal;
}

/**
* @brief        Scan active cluster of current cluster group or erase and format
*               first cluster if an active cluster can't be found
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @post         Initialize the Fee_uJobIntAddrIt iterator to address of
*               the first Fee block header to scan
* @post         Initialize the HdrAddrIt and DataAddrIt iterators to addresses of
*               the first Fee block header and data block
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScanCluster(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    uint8 ClrIndex;
    uint32 ClrStartAddr;
    uint32 ClrLength;

    if (FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_uJobIntClrGrpIt)
    {
        /* Nor more cluster groups to scan */
        Fee_eJob = FEE_JOB_DONE;
    }
    else
    {
        if (0U == Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClrID)
        {
            /* call the cluster format notification */
            FEE_NVM_CLUSTER_FORMAT_NOTIFICATION
            /* No active cluster found in current group so erase and format the first one... */
            Fee_uJobIntClrIt = 0U;
            RetVal = Fee_JobInternalScanClusterErase();
        }
        else
        {
            /* Active cluster found */
            /* Get index of active cluster */
            ClrIndex = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClr;

            ClrStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[ClrIndex].StartAddr;

            /* Calculate logical address of first block header in active cluster */
            Fee_uJobIntAddrIt = FEE_CLUSTER_OVERHEAD + ClrStartAddr;

            /* Initialize the block header pointer */
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt = Fee_uJobIntAddrIt;

            /* Initialize the block data pointer */
            ClrLength = Fee_GetClusterLength(Fee_uJobIntClrGrpIt, ClrIndex);
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = ClrStartAddr + ClrLength;

            /* Active cluster found so read the first block header */
            RetVal = Fee_JobInternalScanBlockHdrRead();
        }
    }
    /* to avoid error compiler warning */
    (void)ClrIndex;

    return RetVal;
}

/**
* @brief        Format first Fee cluster in current Fee cluster group by writing
*               cluster header into memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT_DONE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScanClusterFmt(void)
{
    MemIf_JobResultType RetVal;
    Fee_ClusterHeaderType ClrHdr;
    uint32 ClusterLength;

    ClusterLength = Fee_GetClusterLength(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt);
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    if (0U == ClusterLength)
    {
        /* Bad cluster: try with the next cluster */
        Fee_uJobIntClrIt++;
        if (Fee_uJobIntClrIt < Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrCount)
        {
            RetVal = Fee_JobInternalScanClusterErase();
        }
        else
        {
            /* Out of clusters */
            RetVal = MEMIF_JOB_FAILED;
        }
    }
    else
#endif
    {
        /* Get address and size of first cluster in the current cluster group */
        ClrHdr.StartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;
        ClrHdr.Length = ClusterLength;
        ClrHdr.ClrID = 1U;
        #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        ClrHdr.ClrInfo = &(Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ClrInfo[Fee_uJobIntClrIt]);
        #endif
        /* Build cluster header with clusterID = 1 */
        Fee_SerializeClusterHdr(&ClrHdr, Fee_aDataBuffer);

        /* Make the cluster valid right away as it's empty anyway... */
        Fee_SerializeFlag(&Fee_aDataBuffer[FEE_CLUSTER_HEADER_STATUS_OFFSET], FEE_VALIDATED_VALUE);

        /* Write the cluster header to memacc */
        if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(ClrHdr.StartAddr, Fee_aDataBuffer, FEE_CLUSTER_OVERHEAD - FEE_VIRTUAL_PAGE_SIZE))
        {
            /* MemAcc read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* Schedule cluster format done job */
        Fee_eJob = FEE_JOB_INT_SCAN_CLR_FMT_DONE;
    }
    return RetVal;
}

/**
* @brief        Finalize format of first Fee cluster in current Fee cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Assign index (ActClr) and ID (ActClrID) of active cluster in
*               current cluster group
* @post         Initialize the HdrAddrIt and DataAddrIt iterators to addresses
*               of the first Fee block header and data block
* @post         Advance the Fee_uJobIntClrGrpIt iterator to next cluster group
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScanClusterFmtDone(void)
{
    MemIf_JobResultType RetVal;
    uint32 ClrStartAddr;
    uint32 ClrLength;

    /* Assign Index and ID of active cluster */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClr = Fee_uJobIntClrIt;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClrID = 1U;

    ClrStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;
    ClrLength = Fee_GetClusterLength(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt);

    /* Initialize the block header pointer */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt = ClrStartAddr + FEE_CLUSTER_OVERHEAD;

    /* Initialize the block data pointer */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = ClrStartAddr + ClrLength;

    /* Move on to next cluster group */
    Fee_uJobIntClrGrpIt++;

    /* Scan next cluster group if any */
    RetVal = Fee_JobInternalScanCluster();

    return(RetVal);
}

/**
* @brief        Check the block's size and type match the configuration,
*               and its data pointer points to an acceptable area
*
*/
static inline boolean Fee_IsBlockMatchedConfig(uint16 BlockIndex,
                                               uint16 BlockRuntimeInfoIndex,
                                               const Fee_BlockType *BlockHder,
                                               uint32 DataAddr
                                              )
{
    boolean RetVal = TRUE;
    uint16 AlignedBlockSize;

    if ( (0xFFFFU != BlockIndex) || (0xFFFFU != BlockRuntimeInfoIndex) )
    {
        AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockHder->Length);

        if ((DataAddr <= (Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt - AlignedBlockSize)) &&
            (DataAddr >= (Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD))))
        {
            if (0xFFFFU == BlockRuntimeInfoIndex)  /* Only checks non-foreign blocks */
            {
                if ((Fee_BlockConfig[BlockIndex].ClrGrp != Fee_uJobIntClrGrpIt) ||
                    (Fee_BlockConfig[BlockIndex].BlockSize != BlockHder->Length) ||
                    (Fee_BlockConfig[BlockIndex].ImmediateData != BlockHder->ImmediateBlock)
                   )
                {
                    /* Not matched with the configuration */
                    RetVal = FALSE;;
                }
            }
        }
        else
        {
            /* Invalid area */
            RetVal = FALSE;
        }
    }
    else
    {
        /* Both indexes are FFFF: Invalid block number */
        RetVal = FALSE;
    }

    return RetVal;
}

/**
* @brief        Update block run-time information
*
*/
static inline void Fee_UpdateBlockRuntimeInfo(uint16 BlockRuntimeInfoIndex,
                                              Fee_BlockStatusType BlockStatus,
                                              uint32 DataAddr,
                                              boolean ImmediateBlock
                                             )
{
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)

    /* Update block run-time information when:
     - new valid block is found
     - block was invalidated
     - block contains immediate data (basically just ignore INCONSISTENT non-immediate blocks) */

    if (FEE_BLOCK_INCONSISTENT != BlockStatus)
    {
        /* Mark invalidated blocks as invalid */
        if (FEE_BLOCK_INVALIDATED == BlockStatus)
        {
            Fee_aBlockInfo[BlockRuntimeInfoIndex].BlockStatus = FEE_BLOCK_INVALID;
        }
        else
        {
            Fee_aBlockInfo[BlockRuntimeInfoIndex].BlockStatus = BlockStatus;
        }

        /* Update the block data pointer */
        Fee_aBlockInfo[BlockRuntimeInfoIndex].DataAddr = DataAddr;
        Fee_aBlockInfo[BlockRuntimeInfoIndex].InvalidAddr = (Fee_uJobIntAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;
        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = DataAddr;

    }
    else
    {
        /* header is valid but data is corrupted, in this case it is important to update
           DataAddrIt to avoid corrupted space, cluster swap is not needed */
        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = DataAddr;
    }

    /* Check for blocks potentially overlapping the Reserved Area */

    /* Let Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt] be completely updated before calling Fee_ReservedAreaTargetedInClrGrp() */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt = Fee_uJobIntAddrIt + FEE_BLOCK_OVERHEAD;

    if (FALSE != Fee_ReservedAreaTargetedInClrGrp(Fee_uJobIntClrGrpIt))
    {
        if (TRUE == ImmediateBlock)
        {
            /* Mark the imm. block as touching the Reserved Area (we are esp.
               interested only about inconsistent imm. blocks here, but it does not
               matter if also consistent imm. block will be marked) */
            Fee_TouchReservedAreaByBlock(BlockRuntimeInfoIndex);

        }
        else
        {
            /* Non-immediate data found in the Reserved Area => swap */
            bSwapToBePerformed = TRUE;
            /* bSwapToBePerformed is not reset to FALSE upon recognition of the next written header =>
               the swap is mandatory. */
        }
    }

#else
    /* FEE_BLOCK_ALWAYS_AVAILABLE mode is off, just update block run-time information */
    /* No special treatment of immediate data and overlapping the Reserved Area needed any more */
    (void)ImmediateBlock;

    Fee_aBlockInfo[BlockRuntimeInfoIndex].BlockStatus = BlockStatus;
    /* Update the block data pointer */
    Fee_aBlockInfo[BlockRuntimeInfoIndex].DataAddr = DataAddr;
    Fee_aBlockInfo[BlockRuntimeInfoIndex].InvalidAddr = (Fee_uJobIntAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = DataAddr;

#endif /* FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON */
}

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)

/**
* @brief        Update foreign block configuration information
*
*/
static inline MemIf_JobResultType Fee_UpdateForeignBlockConfigInfo(uint16 *ForeignBlockIndex,
                                                                   const Fee_BlockType *BlockHder,
                                                                   Fee_BlockAssignmentType BlockAssignment
                                                                  )
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    uint16 BlockIndex = *ForeignBlockIndex;

    if (0xFFFFU == BlockIndex)
    {
        /* it's a new foreign block */
        if (Fee_uForeignBlocksNumber < (FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS))
        {
            /* update the foreign block index */
            BlockIndex = Fee_uForeignBlocksNumber;
            *ForeignBlockIndex = BlockIndex;

            /* update the foreign block config */
            Fee_aForeignBlockConfig[BlockIndex].ClrGrp          = Fee_uJobIntClrGrpIt;
            Fee_aForeignBlockConfig[BlockIndex].BlockSize       = BlockHder->Length;
            Fee_aForeignBlockConfig[BlockIndex].BlockNumber     = BlockHder->BlockNumber;
            Fee_aForeignBlockConfig[BlockIndex].ImmediateData   = BlockHder->ImmediateBlock;
            Fee_aForeignBlockConfig[BlockIndex].BlockAssignment = (Fee_BlockAssignmentType)BlockAssignment;
            /* increment the number of foreign blocks */
            Fee_uForeignBlocksNumber++;
        }
        else
        {
            #if (FEE_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_FOREIGN_BLOCKS_OVF);
            #endif
            /* Call job error notification function */
            FEE_NVM_JOB_ERROR_NOTIFICATION
            /* Foreign block overflow, set job failed */
            RetVal = MEMIF_JOB_FAILED;
        }
    }

    return RetVal;
}
#endif /* FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON */

static MemIf_JobResultType Fee_JobCheckBlockHeaderMatchesFeeConfigOrNot(uint16 BlockIndex,
                                                                        uint16 BlockRuntimeInfoIndex,
                                                                        const Fee_BlockType *BlockHder,
                                                                        uint32 DataAddr,
                                                                        Fee_BlockStatusType BlockStatus)
{
    MemIf_JobResultType RetVal;
    uint16 TempBlockRuntimeInfoIndex = BlockRuntimeInfoIndex;

    /* If block header matches Fee config and its data pointer is in an acceptable area: update its runtime info */
    if (TRUE == Fee_IsBlockMatchedConfig(BlockIndex, TempBlockRuntimeInfoIndex, BlockHder, DataAddr))
    {
        /* No foreign blocks found, use the index from our configuration */
        if (0xFFFFU == TempBlockRuntimeInfoIndex)
        {
            TempBlockRuntimeInfoIndex = BlockIndex;
        }
        Fee_UpdateBlockRuntimeInfo(TempBlockRuntimeInfoIndex, BlockStatus, DataAddr, BlockHder->ImmediateBlock);
    }
    else
    {
        /* 1. Invalid block number (removed from Fee config...) next write cluster swap occurs. Or */
        /* 2. Block header doesn't match Fee config or the FEE algorithm... during next write cluster swap occurs */
        bSwapToBePerformed = TRUE;
    }
    /* Move on to next block header */
    Fee_uJobIntAddrIt += FEE_BLOCK_OVERHEAD;
    /* Update the block header pointer */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt = Fee_uJobIntAddrIt;
    /* Read next header */
    RetVal = Fee_JobInternalScanBlockHdrRead();

    return RetVal;
}
/**
* @brief        Parse Fee block header
*
* @param[in]    BufferValid             FALSE if previous MemAcc read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current Fee
*                                        cluster group
*
* @post         Initialize internal recovery swap operation in case of bogus
*               Fee block header or failure of previous read job (perhaps ECC failure..)
* @post         Advance the Fee_uJobIntClrGrpIt iterator to next cluster group in
*               case of blank Fee block header (end of header list)
* @post         Update the BlockStatus, DataAddr, and InvalidAddr block
*               information and the HdrAddrIt and DataAddrIt iterators in case of valid
*               Fee block header
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job in case
*               of valid Fee block header
*
*
*/
static MemIf_JobResultType Fee_JobInternalScanBlockHdrParse(const boolean BufferValid)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    Fee_BlockStatusType BlockStatus;
    Fee_BlockType BlockHder;
    uint32 DataAddr = 0U;
    uint16 BlockIndex;
    uint16 BlockRuntimeInfoIndex = 0xFFFFU;  /* Default value: invalid block number */
    BlockHder.ImmediateBlock = FALSE;
    BlockHder.Length = 0U;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    Fee_BlockAssignmentType BlockAssignment = FEE_PROJECT_RESERVED;
    uint16 ForeignBlockIndex;
#endif

    /* Deserialize block header from read buffer */
    BlockStatus = Fee_DeserializeBlockHdr(&BlockHder, &DataAddr,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                                           (uint8 *)&BlockAssignment,
#endif
                                           Fee_aDataBuffer
                                          );

    /* bSwapToBePerformed was set because previously processed block wasn't properly recognized.
       => perform a swap to prevent a risk that this block overlaps the Reserved Area. */
    if ((FEE_BLOCK_HEADER_INVALID  == BlockStatus) || (FALSE == BufferValid))
    {
        /* Invalidate the block index so Fee won't skip the Fee_uJobBlockIndex block */
        Fee_uJobBlockIndex = 0xffffU;

        /* Move on to next block header */
        Fee_uJobIntAddrIt += FEE_BLOCK_OVERHEAD;

        /* Update the block header pointer */
        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt = Fee_uJobIntAddrIt;

        /* Set swap-to-be-performed flag */
        bSwapToBePerformed = TRUE;

        /* Read next header */
        RetVal = Fee_JobInternalScanBlockHdrRead();

    }
    else if (FEE_BLOCK_HEADER_BLANK == BlockStatus)
    {
        /* If SwapToBePerformed is set, it means that last header is corrupted and
           ONLY now the DataAddrIt variable will be updated to cause swap. */
        if (TRUE == bSwapToBePerformed)
        {
           bSwapToBePerformed = FALSE;
           Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = Fee_uJobIntAddrIt + (2U * FEE_BLOCK_OVERHEAD);
        }

        /* End of header list so move on to next cluster group */
        Fee_uJobIntClrGrpIt++;

        RetVal = Fee_JobInternalScanCluster();
    }
    else
    {
        /* Look for found block in the block configuration */
        BlockIndex = Fee_GetBlockIndex(BlockHder.BlockNumber);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        /* Check if block was not found in the configuration and it is a foreign block */
        if ( (0xFFFFU == BlockIndex) &&
#if (FEE_BOOTLOADER_CONFIG == STD_ON)
             (FEE_PROJECT_APPLICATION == BlockAssignment)
#else
             (FEE_PROJECT_BOOTLOADER == BlockAssignment)
#endif
           )
        {
            /* search for block index in the foreign blocks config */
            ForeignBlockIndex = Fee_GetForeignBlockIndex(BlockHder.BlockNumber);
            /* Check and update foreign block configuration information */
            /* Set job as failed in case of foreign block overflow */
            RetVal = Fee_UpdateForeignBlockConfigInfo(&ForeignBlockIndex, &BlockHder, BlockAssignment);
            /* Found a foreign block: Prepare index to be used for the runtime info data */
            BlockRuntimeInfoIndex = FEE_CRT_CFG_NR_OF_BLOCKS + ForeignBlockIndex;
        }
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        if (MEMIF_JOB_OK == RetVal)
        {
#endif
            /* fix "CHECKED_RETURN" misra violation */
            /* BlockIndex = 0xFFFFU is handled inside function Fee_JobCheckBlockHeaderMatchesFeeConfigOrNot so pass direct value "0xFFFFU" is no problem */
            if (0xFFFFU == BlockIndex)
            {  
                RetVal = Fee_JobCheckBlockHeaderMatchesFeeConfigOrNot(0xFFFFU,
                                                                      BlockRuntimeInfoIndex,
                                                                      &BlockHder,
                                                                      DataAddr,
                                                                      BlockStatus);
            }
            else
            {
                RetVal = Fee_JobCheckBlockHeaderMatchesFeeConfigOrNot(BlockIndex,
                                                                      BlockRuntimeInfoIndex,
                                                                      &BlockHder,
                                                                      DataAddr,
                                                                      BlockStatus);
            }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        }
#endif
    }
    return RetVal;
}

/**
* @brief        Read Fee cluster header
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept read job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_uJobIntClrIt must contain index of current Fee cluster
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScanClusterHdrRead(void)
{
    MemIf_JobResultType RetVal;
    uint32 ReadAddress;
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    /* Get address of current subAddressArea */
    ReadAddress = Fee_pTransJobSubAddressArea->SubAddressAreaAddr;
#else

    /* Get address of current cluster */
    ReadAddress = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;
#endif
    /* Cluster header will be read directly from logical address, don't need translation here */
    if (((Std_ReturnType)E_OK) != MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID_USED, ReadAddress, Fee_aDataBuffer, FEE_CLUSTER_OVERHEAD))
    {
        /* MemAcc read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* MemAcc read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }

    /* Schedule cluster scan job */
    Fee_eJob = FEE_JOB_INT_SCAN_CLR_HDR_PARSE;

    return RetVal;
}
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Get the address of the last subAddressArea of the cluster, prepare before scanning the cluster headers
*
*/
static inline Fee_SubAddressAreaRuntimeInfoType * Fee_GetLastSubAddressAreaList(uint8 ClrGrpIt,
                                                                                uint8 ClrIt
                                                                                )
{
    uint16 uSubAddressAreaCount = Fee_aClrGrpInfo[ClrGrpIt].ClrInfo[ClrIt].SubAddressAreaCount;

    /* Point to the last subAddressArea */
    return &(Fee_aClrGrpInfo[ClrGrpIt].ClrInfo[ClrIt].SubAddressAreaList[uSubAddressAreaCount - 1U]);
}
#endif
/**
* @brief        Initialize the cluster scan job
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept read job
*
* @post         Reset the Fee_uJobIntClrGrpIt and Fee_uJobIntClrIt iterators
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalScan(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    /* Point to the last subAddressArea of the first cluster of first group */
    Fee_pTransJobSubAddressArea = Fee_GetLastSubAddressAreaList(0U, 0U);
    #endif
    /* Reset iterators to first cluster of first cluster group */
    Fee_uJobIntClrGrpIt = 0U;
    Fee_uJobIntClrIt = 0U;

    /* Schedule reading of first cluster header */
    RetVal = Fee_JobInternalScanClusterHdrRead();

    return RetVal;
}

/**
* @brief        Check if all cluster have been scanned or not
*
*/
static inline boolean Fee_JobInternalScanClusterHdrDone(void)
{
    boolean RetVal;

    /* Move on to next cluster */
    Fee_uJobIntClrIt++;

    if (Fee_uJobIntClrIt == Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrCount)
    {
        /* Move on to next cluster group */
        Fee_uJobIntClrGrpIt++;
        Fee_uJobIntClrIt = 0U;
    }

    if (FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_uJobIntClrGrpIt)
    {
        Fee_uJobIntClrGrpIt = 0U;

        /* Done scanning all cluster headers */
        RetVal = TRUE;
    }
    else
    {
        /* There are still clusters to scan */
        RetVal = FALSE;
        #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        /* Point to the last subAddressArea in the next cluster */
        Fee_pTransJobSubAddressArea = Fee_GetLastSubAddressAreaList(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt);
        #endif
    }

    return RetVal;
}

/**
* @brief        Parse Fee cluster header
*
* @param[in]    BufferValid             FALSE if previous MemAcc read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept the erase or read job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Update the Fee_uJobIntClrIt and/or Fee_uJobIntClrGrpIt iterators to move
*               into next cluster and/or cluster group and read next cluster header if
*               there is any
* @post         Scan first active cluster if Fee is done with reading the cluster headers
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE, FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent jobs
*
*/
static MemIf_JobResultType Fee_JobInternalScanClusterHdrParse(const boolean BufferValid)
{
    MemIf_JobResultType RetVal;
    Fee_ClusterStatusType ClrStatus;
    uint32 CfgStartAddr;
    Fee_ClusterHeaderType ClrHdr;
    uint32 CfgClrSize;
    boolean bScanClusterDone = FALSE;
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    boolean ScanSubAddressAreasDone = FALSE;

    /* Point to the cluster runtime information */
    ClrHdr.ClrInfo = &(Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ClrInfo[Fee_uJobIntClrIt]);
#endif
    /* Deserialize cluster parameters from the read buffer */
    ClrStatus = Fee_DeserializeClusterHdr(&ClrHdr, Fee_aDataBuffer);

    /* Get configured cluster start address and size */
    CfgStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;
    CfgClrSize = Fee_GetClusterLength(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt);

    if ((TRUE == BufferValid) &&
        (FEE_CLUSTER_VALID == ClrStatus) &&
        (ClrHdr.StartAddr == CfgStartAddr) &&
        (ClrHdr.Length == CfgClrSize)
       )
    {
        /* Found valid cluster */
        #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        ScanSubAddressAreasDone = TRUE;
        #endif
        if (ClrHdr.ClrID > Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClrID)
        {
            /* Found active cluster */
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClr = Fee_uJobIntClrIt;
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClrID = ClrHdr.ClrID;
        }
    }
    else
    {
        /* Invalid, inconsistent, move to the next one */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        if (Fee_pTransJobSubAddressArea != Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ClrInfo[Fee_uJobIntClrIt].SubAddressAreaList)
        {
            Fee_pTransJobSubAddressArea--;
        }
        else
        {
            /* Done reading all subAddressAreas, move to the next cluster */
            ScanSubAddressAreasDone = TRUE;
        }
#endif
    }
    /* Move on to next cluster */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    if (TRUE == ScanSubAddressAreasDone)
#endif
    {
        bScanClusterDone = Fee_JobInternalScanClusterHdrDone();
    }
    if (TRUE == bScanClusterDone)
    {
        /* Done reading all cluster headers. Now scan active clusters */
        RetVal = Fee_JobInternalScanCluster();
    }
    else
    {
        /* Read next cluster header */
        RetVal = Fee_JobInternalScanClusterHdrRead();
    }

    return RetVal;
}

/**
* @brief        Read Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept read job
* @retval       MEMIF_BLOCK_INVALID      Requested Fee block is invalid
* @retval       MEMIF_BLOCK_INCONSISTENT Requested Fee block is inconsistent
*
* @pre          Fee_uJobBlockIndex       must contain index of requested Fee block
* @pre          Fee_uJobBlockOffset      must contain Offset in requested Fee block
* @pre          Fee_uJobBlockLength      must contain number of bytes to read from requested Fee block
* @post         Schedule the FEE_JOB_DONE    subsequent job
*
* @implements   Fee_JobReadBlock_Activity
*/
static MemIf_JobResultType Fee_JobReadBlock(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;
    Fee_BlockStatusType BlockStatus = FEE_BLOCK_VALID;
    uint32 BlockAddress = 0UL;
    BlockStatus = Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus;
    BlockAddress = Fee_aBlockInfo[Fee_uJobBlockIndex].DataAddr;

    if (FEE_BLOCK_VALID == BlockStatus)
    {
        if (((Std_ReturnType)E_OK) != Fee_ReadFromMemAcc(BlockAddress+Fee_uJobBlockOffset, Fee_pJobReadDataDestPtr, Fee_uJobBlockLength))
        {
            /* MemAcc read job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* MemAcc read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
    }
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
    else if (FEE_BLOCK_NEVER_WRITTEN == BlockStatus)
    {
        /* in case the block was never written */
        RetVal = MEMIF_BLOCK_INCONSISTENT;
    }
#endif
    else if (FEE_BLOCK_INVALID == BlockStatus)
    {
        RetVal = MEMIF_BLOCK_INVALID;
    }
    else if ((FEE_BLOCK_INCONSISTENT == BlockStatus) || (FEE_BLOCK_INCONSISTENT_COPY == BlockStatus))
    {
        /* No special treatment of immediate blocks needed anymore */
        RetVal = MEMIF_BLOCK_INCONSISTENT;
    }
    else
    {
        /* Something is wrong... MEMIF_JOB_FAILED */
    }

    /* There is no consecutive job to schedule */
    Fee_eJob = FEE_JOB_DONE;

    return RetVal;
}

/**
* @brief        Validate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc did not accept write job
*
* @pre          Fee_uJobIntHdrAddr must contain address of Fee block header to
*               validate
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
* @implements   Fee_JobInternalSwapBlockVld_Activity
*/
static MemIf_JobResultType Fee_JobInternalSwapBlockVld(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    /* Serialize validation pattern to buffer */
    Fee_SerializeFlag(Fee_aDataBuffer, FEE_VALIDATED_VALUE);
    /* Write header to memacc */
    if (((Std_ReturnType)E_OK) != Fee_WriteToMemAcc(Fee_uJobIntHdrAddr - (2U*FEE_VIRTUAL_PAGE_SIZE), Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE))
    {
        /* MemAcc read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* MemAcc read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }

    /* Finalize the write operation */
    Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;

    return RetVal;
}

/**
* @brief        Read data from source cluster to internal Fee buffer
*
* @param[in]    BufferValid             FALSE if previous MemAcc read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept read job
*
* @pre          Fee_uJobIntBlockIt must contain index of currently swaped
*               Fee block
* @pre          Fee_uJobIntDataAddr must contain start address of Fee data block
*               in the target cluster
* @pre          Fee_uJobIntAddrIt must contain current address of Fee data block
*               in the target cluster
* @post         Move on to next block Fee block if BufferValid == FALSE
* @post         Validates the Fee block if there is no more data to read
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_WRITE subsequent job
*
*
*/
static MemIf_JobResultType Fee_JobInternalSwapDataRead(const boolean BufferValid)
{
    MemIf_JobResultType RetVal;
    uint32 ReadAddr;
    uint16 AlignedBlockSize;
    uint16 BlockSize;

    /* Get size of swapped block */
    BlockSize = Fee_GetBlockSize(Fee_uJobIntBlockIt);

    /* Get size of swapped block aligned to virtual page boundary */
    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);

    /* Calculate remaining number of bytes to read */
    Fee_uJobBlockLength = (Fee_uJobIntDataAddr + AlignedBlockSize) - Fee_uJobIntAddrIt;

    if (FALSE == BufferValid)
    {
        /* There was error while reading the source cluster.
           Change the block status to FEE_BLOCK_INCONSISTENT_COPY to mark the status change
           during swap, leave the block (in memacc) INCONSITENT and move on to next block */
        Fee_aBlockInfo[Fee_uJobIntBlockIt].BlockStatus = FEE_BLOCK_INCONSISTENT_COPY;

        Fee_uJobIntBlockIt++;

        RetVal = Fee_JobInternalSwapBlock();
    }
    else if (0U == Fee_uJobBlockLength)
    {
        /* No more bytes to copy. Validate the block and move on to next block... */
        Fee_uJobIntBlockIt++;

        RetVal = Fee_JobInternalSwapBlockVld();
    }
    else
    {
        if (Fee_uJobBlockLength > FEE_DATA_BUFFER_SIZE)
        {
            Fee_uJobBlockLength = FEE_DATA_BUFFER_SIZE;
        }
        else
        {
            /* Block data fits into the buffer */
        }

        /* Calculate source address */
        ReadAddr = (Fee_aBlockInfo[Fee_uJobIntBlockIt].DataAddr + Fee_uJobIntAddrIt) - Fee_uJobIntDataAddr;

        /* Read the block data */
        if (((Std_ReturnType)E_OK) != Fee_ReadFromMemAcc(ReadAddr, Fee_aDataBuffer, Fee_uJobBlockLength))
        {
            /* MemAcc read job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* MemAcc read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }

        Fee_eJob = FEE_JOB_INT_SWAP_DATA_WRITE;
    }

    return RetVal;
}

/**
* @brief        Write data from internal Fee buffer to target cluster
*
* @param[in]    BufferValid              FALSE if previous MemAcc read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING         Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED          Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockLength       must contain size of data block being
*                                         transfered(up to FEE_DATA_BUFFER_SIZE)
* @pre          Fee_uJobIntAddrIt         must contain current address of Fee
*                                         data block in the target cluster
* @post         Update the Fee_uJobIntAddrIt data iterator for next data
*               transfer if any
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ subsequent job
*
*/
static MemIf_JobResultType Fee_JobInternalSwapDataWrite(const boolean BufferValid)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    if (TRUE == BufferValid)
    {
        if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(Fee_uJobIntAddrIt, Fee_aDataBuffer, Fee_uJobBlockLength))
        {
            /* MemAcc read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        Fee_uJobIntAddrIt += Fee_uJobBlockLength;

        Fee_eJob = FEE_JOB_INT_SWAP_DATA_READ;
    }
    else
    {
        RetVal = Fee_JobInternalSwapDataRead(FALSE);
    }

    return RetVal;
}

/**
* @brief        Finalize cluster validation
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Update the DataAddr and InvalidAddr Fee_BlockConfig variables of
*               all affected (swaped) Fee blocks
* @post         Update ActClr, ActClrID, HdrAddrIt, DataAddrIt Fee_aClrGrpInfo
*               variables of current cluster group
* @post         Change Fee module status from MEMIF_BUSYINTERNAL to MEMIF_BUSY
* @post         Re-schedule the Fee_eJobIntOriginalJob subsequent job
*
* @implements   Fee_JobInternalSwapClusterVldDone_Activity
*/
static MemIf_JobResultType Fee_JobInternalSwapClusterVldDone(void)
{
    MemIf_JobResultType RetVal;
    uint16 BlockIt;
    uint32 HdrAddrIt;
    uint32 DataAddrIt;
    uint16 BlockSize;
    uint16 AlignedBlockSize;
    uint8 BlockClusterGrp;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* Swap is done => re-initialize info about the blocks touching the Reserved Area within a cluster group where the swap has happened. */
    Fee_UntouchReservedAreaByClrGrp(Fee_uJobIntClrGrpIt);
#endif

    HdrAddrIt = Fee_ClrGrps[Fee_uJobIntClrGrpIt].ClrPtr[Fee_uJobIntClrIt].StartAddr;
    DataAddrIt = HdrAddrIt + Fee_GetClusterLength(Fee_uJobIntClrGrpIt, Fee_uJobIntClrIt);

    /* Move on to the first block header */
    HdrAddrIt += FEE_CLUSTER_OVERHEAD;

    /* Sync block info */

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
   for (BlockIt = 0U; BlockIt < (FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber); BlockIt++)
#else
   for (BlockIt = 0U; BlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; BlockIt++)
#endif
    {
        BlockClusterGrp = Fee_GetBlockClusterGrp(BlockIt);

        if (Fee_uJobIntClrGrpIt == BlockClusterGrp)
        {
            /* Valid blocks and inconsistent blocks with allocated data were copied,
               update the block info and internal pointers accordingly.
            */
            if ((FEE_BLOCK_VALID == Fee_aBlockInfo[BlockIt].BlockStatus) ||
                (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[BlockIt].BlockStatus) ||
                (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[BlockIt].BlockStatus)
               )
            {
                /* Sync InvalidAddr */
                Fee_aBlockInfo[BlockIt].InvalidAddr = (HdrAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;

                /* Update the block data address info */
                if (FEE_BLOCK_VALID == Fee_aBlockInfo[BlockIt].BlockStatus)
                {
                    BlockSize = Fee_GetBlockSize(BlockIt);
                    /* Align block size to the virtual page boundary */
                    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);
                    /* "Allocate" data already swapped (written to the memacc) */
                    DataAddrIt -= AlignedBlockSize;
                    /* store the data address to the block runtime record */
                    Fee_aBlockInfo[BlockIt].DataAddr = DataAddrIt;
                }
                else
                {
                    /* (Inconsistent plain block in LEGACY == ON) or
                       (Inconsistent plain or immediate block in LEGACY == OFF) -- no data written (swapped, allocated)/available */
                    Fee_aBlockInfo[BlockIt].DataAddr = 0U;
                }

                if (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[ BlockIt ].BlockStatus)
                {
                    BlockSize = Fee_GetBlockSize(BlockIt);
                    /* Align block size to the virtual page boundary */
                    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);
                    /* "Allocate" data already swapped (written to the memacc) */
                    DataAddrIt -= AlignedBlockSize;
                    /* Damaged data read during copy, but already allocated => inconsistent */
                    Fee_aBlockInfo[ BlockIt ].BlockStatus = FEE_BLOCK_INCONSISTENT;
                }

                /* Advance the header pointer */
                HdrAddrIt += FEE_BLOCK_OVERHEAD;
            }
            else
            {
                /* Not a usable block */
                /* clear the addresses of the block not present in the new active cluster */
                Fee_aBlockInfo[BlockIt].DataAddr = 0U;
                Fee_aBlockInfo[BlockIt].InvalidAddr = 0U;
            }
        }
    }

    /* Switch to the new cluster */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClr = Fee_uJobIntClrIt;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].ActClrID++;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].HdrAddrIt = HdrAddrIt;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].DataAddrIt = DataAddrIt;

    /* restore original Fee_eJob */
    if (FEE_JOB_INT_SCAN_CLR == Fee_eJobIntOriginalJob)
    {
        Fee_uJobIntClrGrpIt++;
    }
    else
    {
        /* Do nothing */
    }

    /* Internal job has finished so transition from MEMIF_BUSYINTERNAL to MEMIF_BUSY */
    Fee_eModuleStatus = MEMIF_BUSY;

    /* And now cross fingers and re-schedule original job ... */
    Fee_eJob = Fee_eJobIntOriginalJob;

    RetVal = Fee_JobScheduleAfterSwapClusterVldDone();

    return RetVal;
}

/**
* @brief        Write Fee block header to memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         Update the DataAddr and InvalidAddr Fee_BlockConfig variables of
*               written Fee block
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
*
* @implements   Fee_JobWriteHdr_Activity
*/
static MemIf_JobResultType Fee_JobWriteHdr(void)
{
    MemIf_JobResultType RetVal;
    Fee_BlockType BlockHder;
    uint16 AlignedBlockSize;
    uint8 ClrGrpIndex;
    uint32 DataAddr;
    uint32 HdrAddr;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif

        /* Index of cluster group the Fee block belongs to */
        ClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;

        /* Get size, Blocknumber, type of Fee block */
        BlockHder.Length = Fee_BlockConfig[Fee_uJobBlockIndex].BlockSize;
        BlockHder.BlockNumber = Fee_BlockConfig[Fee_uJobBlockIndex].BlockNumber;
        BlockHder.ImmediateBlock = Fee_BlockConfig[Fee_uJobBlockIndex].ImmediateData;
        /* Align Fee block size to the virtual page boundary */
        AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockHder.Length);

        if (FALSE == (boolean)Fee_ReservedAreaWritable())
        {
            /* The block won't fit into current cluster. Init swap sequence... */
            /* Get cluster group index the block belongs to */
            Fee_uJobIntClrGrpIt = ClrGrpIndex;

            RetVal = Fee_JobInternalSwap();
        }
        else
        {
            /* Calculate data and header addresses */
            DataAddr = Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt - AlignedBlockSize;
            HdrAddr = Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt;

            /* Serialize block header to the write buffer */
            Fee_SerializeBlockHdr(&BlockHder,
                                  DataAddr,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                                  Fee_BlockConfig[Fee_uJobBlockIndex].BlockAssignment,
#endif
                                  Fee_aDataBuffer
                                 );

            /* Write header to memacc */
            if (((Std_ReturnType)E_OK) != Fee_WriteToMemAcc(HdrAddr, Fee_aDataBuffer, FEE_BLOCK_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE)))
            {
                /* MemAcc read job hasn't been accepted */
                RetVal = MEMIF_JOB_FAILED;
            }
            else
            {
                /* MemAcc read job has been accepted */
                RetVal = MEMIF_JOB_PENDING;
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Write Fee block data to memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockIndex       must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Update HdrAddrIt, DataAddrIt Fee_aClrGrpInfo variables of current
*               cluster group if ImmediateData == FALSE only
* @post         Changes BlockStatus to FEE_BLOCK_INCONSISTENT
* @post         Schedule either FEE_JOB_WRITE_VALIDATE or
*               FEE_JOB_WRITE_UNALIGNED_DATA subsequent job
*
* @implements   Fee_JobWriteBlockData_Activity
*/
static MemIf_JobResultType Fee_JobWriteBlockData(void)
{
    uint32 DataAddr;
    MemIf_JobResultType RetVal;
    uint16 BlockSize;
    uint16 AlignedBlockSize;
    uint32 WriteLength;
    uint8 ClrGrp;
    const uint8 *WriteDataPtr;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    boolean IsReservedAreaTouched;
#endif

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    uint32 HdrAddr;
    uint8 ClrGrpIndex;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
        /* Get size of Fee block */
        BlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].BlockSize;

        /* Align Fee block size to the virtual page boundary */
        AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
        /* No special treatment of immediate blocks needed anymore; dataAddr and invalidAddr
           has to be updated for a newly written imm/non-imm block  */

        /* Index of cluster group the Fee block belongs to */
        ClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;

        /* Calculate data and header addresses */
        DataAddr = Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt - AlignedBlockSize;
        HdrAddr = Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt;

        Fee_aBlockInfo[Fee_uJobBlockIndex].DataAddr = DataAddr;
        Fee_aBlockInfo[Fee_uJobBlockIndex].InvalidAddr = (HdrAddr + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;

        /* Mark the block as inconsistent since the block header has been written */
        Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus = FEE_BLOCK_INCONSISTENT;
#endif  /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF) */

        /* Index of cluster group the Fee block belongs to */
        ClrGrp = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;

        /* Header has been written so update both header and data addresses;
           no special treatment of immediate blocks needed anymore */
        Fee_aClrGrpInfo[ClrGrp].HdrAddrIt += FEE_BLOCK_OVERHEAD;
        Fee_aClrGrpInfo[ClrGrp].DataAddrIt -= AlignedBlockSize;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* When FEE_BLOCK_ALWAYS_AVAILABLE is enabled, Fee_BlockInfo is not updated immediatelly
           upon a header write. In case of FEE Cancel, the information about the incosistent
           (due to incomplete write) immediate block potentially residing in the Reserved Area
           might be lost and therefore it need to be extra handled. */
        IsReservedAreaTouched = Fee_ReservedAreaTargetedInClrGrp(ClrGrp);
        if ((FALSE != Fee_BlockConfig[Fee_uJobBlockIndex].ImmediateData) && (FALSE != IsReservedAreaTouched))
        {
            /* Store the information about immediate blook touching the Reserved Area. */
            Fee_TouchReservedAreaByBlock(Fee_uJobBlockIndex);
        }
#endif

        if (BlockSize < FEE_VIRTUAL_PAGE_SIZE)
        {
            /* Go through buffer... */
            Fee_CopyDataToPageBuffer(Fee_pJobWriteDataDestPtr, Fee_aDataBuffer, BlockSize);
            WriteDataPtr = Fee_aDataBuffer;
            WriteLength = FEE_VIRTUAL_PAGE_SIZE;

            /* Schedule write of validation pattern */
            Fee_eJob = FEE_JOB_WRITE_VALIDATE;
        }
        else
        {
            WriteDataPtr = Fee_pJobWriteDataDestPtr;

            if (AlignedBlockSize == BlockSize)
            {
                WriteLength = BlockSize;

                /* Schedule write of validation pattern */
                Fee_eJob = FEE_JOB_WRITE_VALIDATE;
            }
            else
            {
                WriteLength = ((uint32)AlignedBlockSize) - FEE_VIRTUAL_PAGE_SIZE;

                /* Schedule write of unaligned data */
                Fee_eJob = FEE_JOB_WRITE_UNALIGNED_DATA;
            }
        }

        DataAddr = Fee_aClrGrpInfo[ClrGrp].DataAddrIt;

        if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(DataAddr, WriteDataPtr,WriteLength))
        {
            /* MemAcc write job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Write Fee block to memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_WRITE_DATA subsequent job
*
* @implements   Fee_JobWriteBlock_Activity
*/
static MemIf_JobResultType Fee_JobWriteBlock(void)
{
    MemIf_JobResultType RetVal;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
        {
            /* Write block header */
            RetVal = Fee_JobWriteHdr();

            /* Schedule next job */
            if (FEE_JOB_INT_SWAP_CLR_FMT == Fee_eJob)
            {
                /* Block didn't fit into the cluster. Cluster swap has been enforced... */
            }
            else
            {
                Fee_eJob = FEE_JOB_WRITE_DATA;
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Write unaligned rest of Fee block data to memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Schedule FEE_JOB_WRITE_VALIDATE subsequent job
*
*
*/
static MemIf_JobResultType Fee_JobWriteBlockUnalignedData(void)
{
    MemIf_JobResultType RetVal;
    uint32 DataAddr;
    uint16 WriteOffset;
    uint16 WriteLength;
    uint16 BlockSize;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    uint16 ClrGrp;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Index of cluster group the Fee block belongs to */
        ClrGrp = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;
#endif

        /* Get size of Fee block */
        BlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].BlockSize;

        /* Calculate number of bytes already written */
        WriteOffset = (BlockSize / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE;

        /* Calculate Length remaining data to write */
        WriteLength = BlockSize % FEE_VIRTUAL_PAGE_SIZE;

        Fee_CopyDataToPageBuffer(&Fee_pJobWriteDataDestPtr[WriteOffset], Fee_aDataBuffer,WriteLength);

        /* No special treatment of immediate data needed any more */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Use ClrGrp info */
        DataAddr = Fee_aClrGrpInfo[ClrGrp].DataAddrIt;
#else
        /* Use Block info because it has been updated */
        DataAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].DataAddr;
#endif

        if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(DataAddr+WriteOffset, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE))
        {
            /* MemAcc write job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* Schedule write of validation pattern */
        Fee_eJob = FEE_JOB_WRITE_VALIDATE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Validate Fee block by writing validation flag to memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to validate
* @post         Schedule FEE_JOB_WRITE_DONE subsequent job
*
* @implements   Fee_JobWriteBlockValidate_Activity
*/
static MemIf_JobResultType Fee_JobWriteBlockValidate(void)
{
    MemIf_JobResultType RetVal;
    uint32 HdrAddr;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    uint8 ClrGrpIndex;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Index of cluster group the Fee block belongs to */
        ClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;
#endif
        /* Serialize validation pattern to buffer */
        Fee_SerializeFlag(Fee_aDataBuffer, FEE_VALIDATED_VALUE);

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Use ClrGrp info */
        HdrAddr = Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt - (2U *  FEE_VIRTUAL_PAGE_SIZE);
#else
        /* Use Block info */
        HdrAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].InvalidAddr - FEE_VIRTUAL_PAGE_SIZE;
#endif

        /* Write validation pattern to memacc */
        if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(HdrAddr, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE))
        {
            /* MemAcc read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* MemAcc write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* Finalize the write operation */
        Fee_eJob = FEE_JOB_WRITE_DONE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Finalize validation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_VALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*
*/
static MemIf_JobResultType Fee_JobWriteBlockDone(void)
{
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    uint32 DataAddr;
    uint32 HdrAddr;
    uint8 ClrGrpIndex;

    /* Index of cluster group the Fee block belongs to */
    ClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;

    /* Calculate data and header addresses */
    DataAddr = Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt;
    HdrAddr = Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt;

    /* Update the block address info */
    Fee_aBlockInfo[Fee_uJobBlockIndex].DataAddr = DataAddr;
    Fee_aBlockInfo[Fee_uJobBlockIndex].InvalidAddr = HdrAddr - FEE_VIRTUAL_PAGE_SIZE;
#endif

    /* Mark the Fee block as valid */
    Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus = FEE_BLOCK_VALID;

    /* No more MemAcc jobs to schedule */
    Fee_eJob = FEE_JOB_DONE;

    return(MEMIF_JOB_OK);
}

/**
* @brief        Invalidate Fee block by writing the invalidation flag to memacc
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept write job
* @retval       MEMIF_JOB_OK             The Fee block is already invalid
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to invalidate
* @post         Schedule FEE_JOB_DONE or FEE_JOB_INVAL_BLOCK_DONE subsequent
*               jobs
*
*/
static MemIf_JobResultType Fee_JobInvalidateBlock(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    if (FEE_BLOCK_INVALID == Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus)
    {
        /* No more subsequent MemAcc jobs to schedule */
        Fee_eJob = FEE_JOB_DONE;

        /* Fee job completed */
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
        #if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
        if (FEE_BLOCK_NEVER_WRITTEN == Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus)
        {
            /* set status as INVALID */
            Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus = FEE_BLOCK_INVALID;

            /* No more subsequent MemAcc jobs to schedule */
            Fee_eJob = FEE_JOB_DONE;

            /* Fee job completed */
            RetVal = MEMIF_JOB_OK;
        }
        else
        #endif
        {
            /* Serialize invalidation pattern to buffer */
            Fee_SerializeFlag(Fee_aDataBuffer, FEE_INVALIDATED_VALUE);

            /* Write invalidation pattern to memacc */
            if (((Std_ReturnType)E_OK) == Fee_WriteToMemAcc(Fee_aBlockInfo[Fee_uJobBlockIndex].InvalidAddr, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE))
            {
                /* MemAcc read job has been accepted */
                RetVal = MEMIF_JOB_PENDING;
            }
            else
            {
                /* MemAcc write job hasn't been accepted */
                RetVal = MEMIF_JOB_FAILED;
            }

            /* Finalize the invalidation operation */
            Fee_eJob = FEE_JOB_INVAL_BLOCK_DONE;
        }
    }

    return RetVal;
}

/**
* @brief        Finalize invalidation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex       must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_INVALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*/
static MemIf_JobResultType Fee_JobInvalidateBlockDone(void)
{
    /* Mark the Fee block as in valid */
    Fee_aBlockInfo[Fee_uJobBlockIndex].BlockStatus = FEE_BLOCK_INVALID;

    /* No more subsequent MemAcc jobs to schedule */
    Fee_eJob = FEE_JOB_DONE;

    /* Fee job completed */
    return(MEMIF_JOB_OK);
}

/**
* @brief        Erase (pre-allocate) immediate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying MemAcc accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying MemAcc didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to
*               pre-allocated
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_DONE subsequent jobs
*
* @implements   Fee_JobEraseImmediateBlock_Activity
*
*/
static MemIf_JobResultType Fee_JobEraseImmediateBlock(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
#if (FEE_LEGACY_IMM_ERASE_MODE == STD_ON)
        /* Legacy mode enabled, Fee_JobEraseImmediateBlock shall invalidate the block */
        if (FALSE == Fee_ReservedAreaWritable())
        {
            /* In legacy mode, pronounce the block to be erased as invalidated and then force the swap */
            Fee_aBlockInfo[ Fee_uJobBlockIndex ].BlockStatus = FEE_BLOCK_INVALID;
            Fee_uJobIntClrGrpIt = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;              /* Get cluster group index */
            RetVal = Fee_JobInternalSwap();
        }
        else
        {
            /* Otherwise trigger invalidate operation (in legacy mode) */
            RetVal = Fee_JobInvalidateBlock();
        }
#else
        /* In standard mode, perform swap if reserved area has been touched, or do nothing. */
        if (FALSE == Fee_ReservedAreaWritable())
        {
            /* Reserved area is not writable, force the swap */
            Fee_uJobIntClrGrpIt = Fee_BlockConfig[Fee_uJobBlockIndex].ClrGrp;              /* Get cluster group index */
            RetVal = Fee_JobInternalSwap();
        }
        else
        {
            /* Do effectively nothing */
            Fee_eJob = FEE_JOB_DONE;
        }
#endif
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Schedule subsequent jobs
* @return       MemIf_JobResultType
* @pre          Fee_eJob must contain type of job to schedule
* @implements   Fee_JobSchedule_Activity
*/
static MemIf_JobResultType Fee_JobSchedule(void)
{
    /* Jump to the current Fee job through function pointer */
    return Fee_JobScheduleLookupTable[Fee_eJob]();
}

/**
* @brief        Schedule subsequent jobs
* @return       MemIf_JobResultType
* @pre          Fee_eJob must contain type of job to schedule
*/
static MemIf_JobResultType Fee_JobScheduleAfterSwapClusterVldDone(void)
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_FAILED;

    switch (Fee_eJob)
    {
        /* Fee_Write() related jobs */
        case FEE_JOB_WRITE:
            eRetVal = Fee_JobWriteBlock();
            break;
        /* Fee_EraseImmediateBlock() related jobs */
        case FEE_JOB_ERASE_IMMEDIATE:
            eRetVal = Fee_JobEraseImmediateBlock();
            break;
        default:
            /* Compiler_Warning: This default branch will never be reached in FTE */
            break;
    }

    return(eRetVal);
}

/**
* @brief Checks whether the block specified by Fee_JobBlockIndex is writable into the reserved area.
*
* @return sint8
* @retval TRUE The block is writable into the reserved area.
* @retval FALSE The block is not writable into the reserved area.
*
* @pre Fee_JobBlockIndex must contain index of Fee block to be written
* @pre Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt must be up to date
* @pre Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt must be up to date
*
* @implements   Fee_ReservedAreaWritable_Activity
*/
static boolean Fee_ReservedAreaWritable(void)
{
    boolean RetVal;
    uint16 BlockSize;
    uint16 AlignedBlockSize;
    uint32 AvailClrSpace;
    uint8 ClrGrpIndex;
    uint32 ReservedSpace;
    boolean ImmediateData;
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    boolean IsReservedAreaTouched;
#endif

    /* Index of cluster group the Fee block belongs to */
    ClrGrpIndex = Fee_GetBlockClusterGrp(Fee_uJobBlockIndex);

    /* Reserved space of cluster group*/
    ReservedSpace = Fee_ClrGrps[ClrGrpIndex].ReservedSize;

    /* Calculate available space in active cluster */
    AvailClrSpace = Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt - Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt;

    /* Get size of Fee block */
    BlockSize = Fee_GetBlockSize(Fee_uJobBlockIndex);

    /* Align Fee block size to the virtual page boundary */
    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);

    /* Hard Stop condition: One FEE_BLOCK_OVERHEAD must be left blank to have a clear separation
       between header block space and data block space */
    if ((((uint32)AlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD)) > AvailClrSpace)
    {
        RetVal = FALSE;
    }
    else if ((((uint32)AlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD) + ReservedSpace) > AvailClrSpace)
    {
        ImmediateData = Fee_GetBlockImmediate(Fee_uJobBlockIndex);
        /* Block targets reserved area */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        IsReservedAreaTouched = Fee_ReservedAreaTouchedByBlock(Fee_uJobBlockIndex);
        if ((TRUE == ImmediateData) && (FALSE == IsReservedAreaTouched))
#else
        if (TRUE == ImmediateData)
#endif
        {
            /* Immediate block - only writable if not already present in the reserved area */
            if (((0UL == Fee_aBlockInfo[Fee_uJobBlockIndex].DataAddr) && (0UL == Fee_aBlockInfo[Fee_uJobBlockIndex].InvalidAddr)) ||
               /* The block is written in the cluster - is it written in the reserved area? */
                ((FEE_BLOCK_OVERHEAD + ReservedSpace) <= (Fee_aBlockInfo[Fee_uJobBlockIndex].DataAddr - (Fee_aBlockInfo[Fee_uJobBlockIndex].InvalidAddr + FEE_VIRTUAL_PAGE_SIZE)))
               )
            {
                /* The block is not written in the cluster at all => writable */
                /* or The block is not written in the reserved area */
                RetVal = TRUE;
            }
            else
            {
                RetVal = FALSE;
            }
        }
        else
        {
            RetVal = FALSE;
        }
    }
    else
    {
        /* Block does not target reserved area */
        RetVal = TRUE;
    }
    return RetVal;
}

static inline void Fee_TranferJobResultMemAccToMemif(MemAcc_JobResultType MemAcc_JobResult)
{
    switch(MemAcc_JobResult)
    {
        /* the Job is failed */ 
        case MEMACC_MEM_FAILED:
        case MEMACC_MEM_ECC_UNCORRECTED:
        {
            Fee_eJobResult = MEMIF_JOB_FAILED;
            break;
        }
        /* the Job is canceled */ 
        case MEMACC_MEM_CANCELED:
            Fee_eJobResult = MEMIF_JOB_CANCELED;
            break;
        /* the last job didn't meet the expected result */
        case MEMACC_MEM_INCONSISTENT:
            Fee_eJobResult = MEMIF_BLOCK_INCONSISTENT;
            break;
        /* the Job is OK/ECC_CORRECTED */
        case MEMACC_MEM_OK:
        case MEMACC_MEM_ECC_CORRECTED:
        default:
            Fee_eJobResult = MEMIF_JOB_OK;
            break;
    }
}
/**
* @brief        Schedule the error jobs
* @return       void
* @pre          Fee_eJob must contain type of job to schedule
*/
static void Fee_JobErrorSchedule(void)
{
    uint8 ClrGrpIndex;
    MemAcc_JobResultType MemAcc_JobResult;

    switch (Fee_eJob)
    {
        /* Error while reading block header. Treat block header as invalid and stop reading further block headers */
        case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            Fee_eJobResult = Fee_JobInternalScanBlockHdrParse(FALSE);
            break;

        /* Error while reading cluster header. Treat cluster as invalid and move on to next cluster */
        case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            Fee_eJobResult = Fee_JobInternalScanClusterHdrParse(FALSE);
            break;

        /* Error while reading data from source cluster. Leave block as INCONSISTENT and move on to next block */
        case FEE_JOB_INT_SWAP_DATA_WRITE:
            Fee_eJobResult = Fee_JobInternalSwapDataWrite(FALSE);
            break;

        /* for all the following cases based on the Fee module status error notification will be called */
        case FEE_JOB_WRITE:
        case FEE_JOB_WRITE_DATA:
        case FEE_JOB_WRITE_UNALIGNED_DATA:
        case FEE_JOB_ERASE_IMMEDIATE:
        case FEE_JOB_WRITE_VALIDATE:
        case FEE_JOB_WRITE_DONE:
        {
            ClrGrpIndex = Fee_GetBlockClusterGrp(Fee_uJobBlockIndex);

            /* Something wrong in memaccMemory (cluster swap occurs to next write) */
            Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt = Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD);
            MemAcc_JobResult = MemAcc_GetJobResult(FEE_MEMACC_ADDRESS_AREA_ID_USED);
            Fee_TranferJobResultMemAccToMemif(MemAcc_JobResult);
            Fee_eModuleStatus = MEMIF_IDLE;

            /* Call job error notification function */
            FEE_NVM_JOB_ERROR_NOTIFICATION
            break;
        }

        case FEE_JOB_READ:
        case FEE_JOB_INVAL_BLOCK:
        case FEE_JOB_INVAL_BLOCK_DONE:
        case FEE_JOB_INT_SCAN:
        case FEE_JOB_INT_SCAN_CLR:
        case FEE_JOB_INT_SCAN_CLR_FMT:
        case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
        case FEE_JOB_INT_SWAP_BLOCK:
        case FEE_JOB_INT_SWAP_CLR_FMT:
        case FEE_JOB_INT_SWAP_DATA_READ:
        case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
        case FEE_JOB_DONE:
        default:
            MemAcc_JobResult = MemAcc_GetJobResult(FEE_MEMACC_ADDRESS_AREA_ID_USED);
            Fee_TranferJobResultMemAccToMemif(MemAcc_JobResult);
            Fee_eModuleStatus = MEMIF_IDLE;

            /* Call job error notification function */
            FEE_NVM_JOB_ERROR_NOTIFICATION

            break;
    }
}
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)

#if (FEE_NUMBER_OF_SUBADDRESSAREAS_TO_RECOVER > 0U)

/**
* @brief        Check if the bad subAddressArea appears in the recovery list or not
* @return       uint32
*
*/
static uint32 Fee_GetRecoverSubAddressAreaSize(const Fee_SubAddressAreaRuntimeInfoType *BadSubAddressArea)
{
    uint32 RecoverSize = 0U;
    uint32 SubAddressAreaIt;

    /* Check if it appears in the recovery list */
    for (SubAddressAreaIt = 0U; SubAddressAreaIt < FEE_NUMBER_OF_SUBADDRESSAREAS_TO_RECOVER; SubAddressAreaIt++)
    {
        /* Match with the requested subAddressArea to recover in the configuration */
        if (BadSubAddressArea == Fee_SubAddressAreaToRecover[SubAddressAreaIt].SubAddressAreaToRecover)
        {
            /* Recover to the original size */
            RecoverSize = Fee_SubAddressAreaToRecover[SubAddressAreaIt].SubAddressAreaSize;
            break;
        }
    }

    return RecoverSize;
}

/**
* @brief        Try to recover bad subAddressAreas in the requested cluster
*
*/
static void Fee_RecoverBadSubAddressAreas(Fee_ClusterRuntimeInfoType *Cluster)
{
    uint32 SubAddressAreaIt;
    uint32 SubAddressAreaSize;

    for (SubAddressAreaIt = 0U; SubAddressAreaIt < Cluster->SubAddressAreaCount; SubAddressAreaIt++)
    {
        /* Find bad subAddressAreas */
        if (0U == Cluster->SubAddressAreaList[SubAddressAreaIt].SubAddressAreaSize)
        {
            /* Get the recover size */
            SubAddressAreaSize = Fee_GetRecoverSubAddressAreaSize( &(Cluster->SubAddressAreaList[SubAddressAreaIt]) );
            /* Recover to the original size */
            Cluster->SubAddressAreaList[SubAddressAreaIt].SubAddressAreaSize = SubAddressAreaSize;
            /* Increase cluster Length */
            Cluster->Length += SubAddressAreaSize;
        }
    }
}
#endif /* (FEE_NUMBER_OF_SUBADDRESSAREAS_TO_RECOVER > 0U) */

/**
* @brief        Schedule translation address jobs in case the Fee address range is on the discontinuous MemAcc subAddressAreas
* @return       MemIf_JobResultType
* @pre          Fee_eTransJob must contain type of job to schedule
*/
static MemIf_JobResultType Fee_TransJobSchedule(void)
{
    MemIf_JobResultType RetVal;
    Std_ReturnType SubJobResult;

    switch (Fee_eTransJob)
    {
        case FEE_TRANS_JOB_READ:
            SubJobResult = Fee_TranslationJobRead(0U);
            break;

        case FEE_TRANS_JOB_WRITE:
            SubJobResult = Fee_TranslationJobWrite(0U);
            break;

        case FEE_TRANS_JOB_ERASE:
            SubJobResult = Fee_TranslationJobErase();
            break;

        default:
            /* Nothing to do */
            SubJobResult = E_OK;
            break;
    }

    if ((Std_ReturnType)E_OK == SubJobResult)
    {
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        RetVal = MEMIF_JOB_FAILED;
    }
    return RetVal;
}

/**
* @brief        Calculate the Offset over the cluster corresponding to the emulation address
*
*/
static uint32 Fee_CalcTransferOffset(uint32 emulationAddress)
{
    uint32 GroupIt = 0U;
    uint32 ClusterIt = 0U;
    uint32 Offset;

    /* Find the cluster index that the emulation address belongs to */
    do
    {
        /* Calculate the Offset on this cluster */
        Offset = emulationAddress - Fee_ClrGrps[GroupIt].ClrPtr[ClusterIt].StartAddr;
        if (Offset < Fee_GetClusterLength((uint8)GroupIt, (uint8)ClusterIt))
        {
            /* Point to the subAddressArea list of this cluster */
            Fee_pTransJobSubAddressArea = Fee_aClrGrpInfo[GroupIt].ClrInfo[ClusterIt].SubAddressAreaList;
            break;
        }

        /* Move to next cluster */
        ClusterIt++;

        if (ClusterIt == Fee_ClrGrps[GroupIt].ClrCount)
        {
            /* Cluster roll over */
            ClusterIt = 0U;
            GroupIt++;
        }
    }
    while (GroupIt < FEE_NUMBER_OF_CLUSTER_GROUPS);

    /* The address Offset of this job */
    return Offset;
}

/**
* @brief        Calculate the maximum Length of transfer data from the next good subAddressArea
*
*/
static uint32 Fee_CalcMaxTransferLength(uint32 *LogicalAddress, uint32 OffsetAddress)
{
    uint32 TransferLength;
    uint32 SubAddressAreaSize = Fee_pTransJobSubAddressArea->SubAddressAreaSize;
    uint32 Offset = OffsetAddress;

    /* Find the next good subAddressArea that contains the Offset */
    while (Offset >= SubAddressAreaSize)
    {
        Offset -= SubAddressAreaSize;
        Fee_pTransJobSubAddressArea++;
        SubAddressAreaSize = Fee_pTransJobSubAddressArea->SubAddressAreaSize;
    }

    /* Calculate the logical memacc address on this subAddressArea */
    *LogicalAddress = Fee_pTransJobSubAddressArea->SubAddressAreaAddr + Offset;
    /* Move to next subAddressArea */
    Fee_pTransJobSubAddressArea++;

    /* Calculate maximum transfer Length */
    if ((Offset + Fee_uTransJobLength) > SubAddressAreaSize)
    {
        TransferLength = SubAddressAreaSize - Offset;
        /* Update information for the next translation job */
        Fee_pTransJobBuffer += (uint32)TransferLength;
    }
    else
    {
        TransferLength = Fee_uTransJobLength;
    }

    /* Update the remaining Length of data */
    Fee_uTransJobLength -= TransferLength;

    return TransferLength;
}

/**
* @brief        Performs the translation address to read the data from MemAcc
*
*/
static Std_ReturnType Fee_TranslationJobRead(uint32 OffsetAddress)
{
    uint8 *pBuffer = (uint8 *)(Fee_UintPtrType)Fee_pTransJobBuffer;
    uint32 LogicalAddress;
    uint32 TransferLength;

    /* Calculate maximum transfer Length */
    TransferLength = Fee_CalcMaxTransferLength(&LogicalAddress, OffsetAddress);

    return MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID_USED,LogicalAddress, pBuffer, TransferLength);
}

/**
* @brief        Performs the translation address to write the data to MemAcc
*
*/
static Std_ReturnType Fee_TranslationJobWrite(uint32 OffsetAddress)
{
    const uint8 *pBuffer = (const uint8 *)(Fee_UintPtrType)Fee_pTransJobBuffer;
    uint32 LogicalAddress;
    uint32 TransferLength;

    /* Calculate maximum transfer Length */
    TransferLength = Fee_CalcMaxTransferLength(&LogicalAddress, OffsetAddress);

    return MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID_USED,LogicalAddress, pBuffer, TransferLength);
}

/**
* @brief        Erase the next subAddressArea of the cluster
*
*/
static Std_ReturnType Fee_TranslationJobErase(void)
{
    /* Find the next good subAddressArea */
    do
    {
        Fee_pTransJobSubAddressArea++;
    }
    while (0U == Fee_pTransJobSubAddressArea->SubAddressAreaSize);

    /* Update the remaining Length of job */
    Fee_uTransJobLength -= Fee_pTransJobSubAddressArea->SubAddressAreaSize;

    /* Reset counter */
    Fee_uTransJobEraseRetries = FEE_SUBADDRESSAREA_ERASE_RETRIES;

    return MemAcc_Erase(FEE_MEMACC_ADDRESS_AREA_ID_USED, Fee_pTransJobSubAddressArea->SubAddressAreaAddr, Fee_pTransJobSubAddressArea->SubAddressAreaSize);
}

/**
* @brief        Process the erase cluster in case there was a failed erase job
*
*/
static Std_ReturnType Fee_TranslationJobEraseFailed(void)
{
    Std_ReturnType RetVal;

    /* All attemps have failed */
    if (0U == Fee_uTransJobEraseRetries)
    {
        /* Decrease the Length of cluster by the size of the bad subAddressArea */
        Fee_pTransJobCluster->Length -= Fee_pTransJobSubAddressArea->SubAddressAreaSize;
        /* Mark the current subAddressArea as a bad subAddressArea */
        Fee_pTransJobSubAddressArea->SubAddressAreaSize = 0U;

        /* The last subAddressArea of cluster was erased, move to the next job */
        if (0U == Fee_uTransJobLength)
        {
            if (MEMIF_JOB_PENDING == Fee_JobSchedule())
            {
                RetVal = E_OK;
            }
            else
            {
                RetVal = E_NOT_OK;
            }
        }
        else
        {
            /* Move to the next one */
            RetVal = Fee_TranslationJobErase();
        }
    }
    else
    {
        Fee_uTransJobEraseRetries--;
        /* Try to erase the current subAddressArea again */
        RetVal = MemAcc_Erase(FEE_MEMACC_ADDRESS_AREA_ID_USED, Fee_pTransJobSubAddressArea->SubAddressAreaAddr, Fee_pTransJobSubAddressArea->SubAddressAreaSize);
    }

    return RetVal;
}
#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */
/**
* @brief        Read data from MemAcc, translate the emulation to logical address in subAddressArea retirement mode
*
*/
static Std_ReturnType Fee_ReadFromMemAcc(uint32 SourceAddress,
                                      const uint8 *TargetAddressPtr,
                                      uint32 Length
                                     )
{
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    uint32 Offset;

    /* Find cluster & calculate the Offset address on it */
    Offset = Fee_CalcTransferOffset(SourceAddress);

    /* Prepare information for the next sub job */
    Fee_uTransJobLength = Length;
    /*To fix Cert-C violation*/
    Fee_pTransJobBuffer = (Fee_UintPtrType)&TargetAddressPtr[0];
    Fee_eTransJob = FEE_TRANS_JOB_READ;

    return Fee_TranslationJobRead(Offset);
#else
    return MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID_USED, SourceAddress, (MemAcc_DataType *)TargetAddressPtr, Length);
#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */
}

/**
* @brief        Write data to MemAcc, translate the emulation to logical address in subAddressArea retirement mode
*
*/
static Std_ReturnType Fee_WriteToMemAcc(uint32 TargetAddress,
                                     const uint8 *SourceAddressPtr,
                                     uint32 Length
                                    )
{

#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    uint32 Offset;

    /* Find cluster & calculate the Offset address on it */
    Offset = Fee_CalcTransferOffset(TargetAddress);

    /* Prepare information for the next sub job */
    Fee_uTransJobLength = Length;
    Fee_pTransJobBuffer = (Fee_UintPtrType)&SourceAddressPtr[0];
    Fee_eTransJob = FEE_TRANS_JOB_WRITE;

    return Fee_TranslationJobWrite(Offset);
#else
    return MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID_USED, TargetAddress, SourceAddressPtr, Length);
#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */
}

/**
* @brief        Erase the whole cluster, translate the emulation to logical address in subAddressArea retirement mode
*               and erase a subAddressArea at a time
*
*/
static Std_ReturnType Fee_EraseCluster(uint8 ClrGrpIt,
                                       uint8 ClrIt
                                      )
{
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)

    #if (FEE_NUMBER_OF_SUBADDRESSAREAS_TO_RECOVER > 0U)
    /* Firstly, check the recover list to refresh the subAddressArea list */
    Fee_RecoverBadSubAddressAreas( &(Fee_aClrGrpInfo[ClrGrpIt].ClrInfo[ClrIt]) );
    #endif

    /* Point to the subAddressArea list of this cluster */
    Fee_pTransJobSubAddressArea = Fee_aClrGrpInfo[ClrGrpIt].ClrInfo[ClrIt].SubAddressAreaList;

    /* Find the first good subAddressArea */
    while (0U == Fee_pTransJobSubAddressArea->SubAddressAreaSize)
    {
        Fee_pTransJobSubAddressArea++;
    }

    /* Save information for the next sub job */
    Fee_pTransJobCluster = &(Fee_aClrGrpInfo[ClrGrpIt].ClrInfo[ClrIt]);
    Fee_uTransJobLength = Fee_pTransJobCluster->Length - Fee_pTransJobSubAddressArea->SubAddressAreaSize;
    Fee_eTransJob = FEE_TRANS_JOB_ERASE;

    /* Reset counter */
    Fee_uTransJobEraseRetries = FEE_SUBADDRESSAREA_ERASE_RETRIES;

    /* Erase the first good subAddressArea on the list */
    return MemAcc_Erase(FEE_MEMACC_ADDRESS_AREA_ID_USED, Fee_pTransJobSubAddressArea->SubAddressAreaAddr, Fee_pTransJobSubAddressArea->SubAddressAreaSize);
#else
    uint32 clusterAddress;
    uint32  ClusterLength;

    /* Get address and size of cluster in the cluster group */
    clusterAddress = Fee_ClrGrps[ClrGrpIt].ClrPtr[ClrIt].StartAddr;
    ClusterLength  = Fee_GetClusterLength(ClrGrpIt, ClrIt);

    return MemAcc_Erase(FEE_MEMACC_ADDRESS_AREA_ID_USED, clusterAddress, ClusterLength);
#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */
}

/**
* @brief        Get the Length of the cluster by the group index and cluster index
*
*/
static inline uint32 Fee_GetClusterLength(uint8 ClrGrpIt,
                                                  uint8 ClrIt
                                                 )
{
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    return Fee_aClrGrpInfo[ClrGrpIt].ClrInfo[ClrIt].Length;    /* Get from runtime data information */
#else
    return Fee_ClrGrps[ClrGrpIt].ClrPtr[ClrIt].Length;          /* Get from constant data configuration */
#endif
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Service to initialize the FEE module.
* @details      The function Fee_Init shall initialize the memacc EEPROM
*               Emulation module.
*
* @param[in]    ConfigPtr        Pointer to fee driver configuration set.
* 
* @pre          The FEE module'  s environment shall not call the function
*               Fee_Init shall during a running operation of the FEE module.
* @note         The function Autosar Service ID[hex]: 0x00.
* @note         Asynchronous
* @note         Non Reentrant
*
* @api
*
* @implements   Fee_Init_Activity
*/
void Fee_Init(const Fee_ConfigType *ConfigPtr)
{
    uint32 InvalIndex;

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != ConfigPtr)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_INIT_ID, FEE_E_PARAM_POINTER);
    }
    else if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID, FEE_E_BUSY);
    }
    else
#else
        (void)ConfigPtr;
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    {
        /* Initialize all block info records */
        for (InvalIndex = 0U; InvalIndex < FEE_MAX_NR_OF_BLOCKS; InvalIndex++)
        {
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
            /* for blocks which were never written Fee returns INVALID status */
            Fee_aBlockInfo[InvalIndex].BlockStatus = FEE_BLOCK_INVALID;
#else
            /* for blocks which were never written Fee returns INCONSISTENT status */
            Fee_aBlockInfo[InvalIndex].BlockStatus = FEE_BLOCK_NEVER_WRITTEN;
#endif
            Fee_aBlockInfo[InvalIndex].DataAddr = 0U;
            Fee_aBlockInfo[InvalIndex].InvalidAddr = 0U;
        }

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        /* Initialize all foreign block config records */
        for (InvalIndex = 0U; InvalIndex < (FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS); InvalIndex++)
        {
            Fee_aForeignBlockConfig[InvalIndex].BlockNumber = 0U;
            Fee_aForeignBlockConfig[InvalIndex].BlockSize = 0U;
            Fee_aForeignBlockConfig[InvalIndex].ClrGrp = 0U;
            Fee_aForeignBlockConfig[InvalIndex].ImmediateData = FALSE;
            Fee_aForeignBlockConfig[InvalIndex].BlockAssignment = FEE_PROJECT_RESERVED;
        }
#endif
        /* Invalidate all cluster groups */
        for (InvalIndex = 0U; InvalIndex < FEE_NUMBER_OF_CLUSTER_GROUPS; InvalIndex++)
        {
            Fee_aClrGrpInfo[InvalIndex].ActClrID = 0U;
            #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
            /* Link to the Fee cluster set information */
            Fee_aClrGrpInfo[InvalIndex].ClrInfo = Fee_ClusterRuntimeInfo[InvalIndex];
            #endif
        }

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        Fee_UntouchReservedAreaAll();
#endif
        /* Schedule init job */
        Fee_eJob = FEE_JOB_INT_SCAN;
        Fee_eJobResult = MEMIF_JOB_PENDING;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        Fee_uForeignBlocksNumber = 0U;
#endif
    }
}

/**
* @brief        Service to Initialize a read job.
* @details      The function Fee_Read shall take the block start address and
*               Offset and calculate the corresponding memory read address.
*
* @param[in]    BlockNumber     Number of logical block, also denoting
*                                start address of that block in memacc memory.
* @param[in]    BlockOffset     Read address Offset inside the block.
* @param[out]   DataBufferPtr   Pointer to data buffer.
* @param[in]    Length          Number of bytes to read.
*
* @pre          The module must be initialized, not busy, BlockNumber must be
*               valid, Length != 0, DataBufferPtr != NULL_PTR, BlockOffset and
*               (BlockOffset + Length - 1) must be in range and Length must be aligned with FEE_MINIMUM_READ_PAGE_SIZE.
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockOffset,
*               Fee_uJobBlockLength, Fee_uJobBlockIndex, Fee_pJobReadDataDestPtr,
*               Fee_eJob, Fee_eJobResult job control internal variables.
*
* @return       Std_ReturnType
* @retval       E_OK             The read job was accepted by the
*                                underlying memory driver.
* @retval       E_NOT_OK         The read job has not been accepted
*                                by the underlying memory driver.
* @note         The function Autosar Service ID[hex]: 0x02.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_Read_Activity
*/
Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00();

    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_UNINIT);
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_BUSY);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        if (0xFFFFU == BlockIndex)
        {
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_NO);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if (BlockOffset >= Fee_BlockConfig[BlockIndex].BlockSize)
            {
                (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_OFS);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            if ((0U == Length) || ((BlockOffset + Length) > Fee_BlockConfig[BlockIndex].BlockSize) || (0U != (Length % FEE_MINIMUM_READ_PAGE_SIZE)))
            {
                (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_LEN);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
        if (NULL_PTR == DataBufferPtr)
        {
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_PARAM_POINTER);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Configure the read job */
        Fee_uJobBlockIndex = BlockIndex;

        Fee_uJobBlockOffset = BlockOffset;

        Fee_uJobBlockLength = Length;

        Fee_pJobReadDataDestPtr = DataBufferPtr;

        Fee_eJob = FEE_JOB_READ;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the read job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
    }
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00();

    return RetVal;
}

/**
* @brief        Service to Initialize a write job.
* @details      The function Fee_Write shall take the block start address and
*               calculate the corresponding memory write address. The block
*               address Offset shall be fixed to zero.
*               The function Fee_Write shall copy the given or computed
*               parameters to module internal variables, Initialize a write job,
*               set the FEE module status to MEMIF_BUSY, set the job result to
*               MEMIF_JOB_PENDING and return with E_OK.The FEE module shall
*               execute the write job of the function Fee_Write
*               asynchronously within the FEE module' s main function.
*
* @param[in]    BlockNumber     Number of logical block, also denoting
*                                start address of that block in emulated
*                                EEPROM.
* @param[out]   DataBufferPtr   Pointer to data buffer.
*
* @return       Std_ReturnType
* @retval       E_OK             The write job was accepted by the
*                                underlying memory driver.
* @retval       E_NOT_OK         The write job has not been accepted by
*                                the underlying memory driver.
*
* @pre          The module must be initialized, not busy, BlockNumber must be
*               valid, and DataBufferPtr != NULL_PTR and must be aligned with FEE_BUFFER_ALIGN_VALUE.
*               Before call the function "Fee_Write" for immediate date must be
*               called the function "Fee_EraseImmediateBlock".
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockIndex,
*               Fee_pJobWriteDataDestPtr, Fee_eJob, Fee_eJobResult job control internal
*               variables.
* @note         The function Autosar Service ID[hex]: 0x03.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_Write_Activity
*/
Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8 *DataBufferPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01();

    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_BUSY);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        if (0xFFFFU == BlockIndex)
        {
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        if ((NULL_PTR == DataBufferPtr) || (0U != ((Fee_UintPtrType)(&DataBufferPtr[0]) % FEE_BUFFER_ALIGN_VALUE)))
        {
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_WRITE_ID, FEE_E_PARAM_POINTER);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Configure the write job */
        Fee_uJobBlockIndex = BlockIndex;

        Fee_pJobWriteDataDestPtr = DataBufferPtr;

        Fee_eJob = FEE_JOB_WRITE;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the write job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
    }
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01();

    return RetVal;
}

/**
* @brief        Service to call the cancel function of the underlying memacc
*               driver.
* @details      The function Fee_Cancel and the cancel function of the
*               underlying MemAcc driver are asynchronous w.r.t. an ongoing
*               read, erase or write job in the memacc memory.
*
* @pre          The module must be initialized.
* @post         Changes Fee_eModuleStatus module status and job result
*               Fee_eJobResult internal variables.
* @note         The function Autosar Service ID[hex]: 0x04.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_Cancel_Activity
*/
void Fee_Cancel(void)
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_UNINIT);
    }
    else
    {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */

        if (MEMIF_JOB_PENDING == Fee_eJobResult)
        {
            /* Cancel ongoing MemAcc job if any */
            if (MEMIF_BUSY == Fee_eModuleStatus)
            {
                Fee_eJobResult = MEMIF_JOB_CANCELED;
                Fee_eJob = FEE_JOB_DONE;
                MemAcc_Cancel(FEE_MEMACC_ADDRESS_AREA_ID_USED);
                Fee_eModuleStatus = MEMIF_IDLE;

                /* No notifications from internal jobs */
            }
            else
            {
                (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_INVALID_CANCEL);
                /* Call job error notification function */
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
        }
        else
        {
            /* Leave the job result unchanged */
        }

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
}

/**
* @brief        Return the Fee module state.
* @details      Return the Fee module state synchronously.
*
* @note         The function Autosar Service ID[hex]: 0x05.
* @note         Synchronous
* @note         Non Reentrant
*
* @return       Fee_eModuleStatus
* @retval       MEMIF_UNINIT             Module has not been initialized (yet).
* @retval       MEMIF_IDLE               Module is currently idle.
* @retval       MEMIF_BUSY               Module is currently busy.
* @retval       MEMIF_BUSY_INTERNAL      Module is busy with internal management
*                                        operations.
*
* @api
*
* @implements   Fee_GetStatus_Activity
*/
MemIf_StatusType Fee_GetStatus(void)
{
    return(Fee_eModuleStatus);
}

/**
* @brief        Return the result of the last job.
* @details      Return the result of the last job synchronously.
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK              The job has been finished successfully.
* @retval       MEMIF_JOB_FAILED          The job has not been finished
*                                         successfully.
* @retval       MEMIF_JOB_PENDING         The job has not yet been finished.
* @retval       MEMIF_JOB_CANCELED        The job has been canceled.
* @retval       MEMIF_BLOCK_INCONSISTENT  The requested block is inconsistent,
*                                         it may contain corrupted data.
* @retval       MEMIF_BLOCK_INVALID       The requested block has been invalidated,
*                                         the requested read operation can not be performed.
* @note         The function Autosar Service ID[hex]: 0x06.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_GetJobResult_Activity
*/
MemIf_JobResultType Fee_GetJobResult(void)
{
    MemIf_JobResultType RetVal = Fee_eJobResult;

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETJOBRESULT_ID, FEE_E_UNINIT);
        RetVal = MEMIF_JOB_FAILED;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}

/**
* @brief        Service to invalidate a logical block.
*
* @param[in]    BlockNumber     Number of logical block, also denoting
*                                start address of that block in memacc memory
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the
*                                underlying memory driver.
*
* @pre          The module must be initialized, not busy, and BlockNumber must be
*               valid
*
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockIndex,
*               Fee_eJob, and Fee_eJobResult job control internal variables.
*               EEPROM.
* @note         The function Autosar Service ID[hex]: 0x07.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_InvalidateBlock_Activity
*/
Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_02();

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else
    {
        if (0xFFFFU == BlockIndex)
        {
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Configure the invalidate block job */
        Fee_uJobBlockIndex = BlockIndex;

        Fee_eJob = FEE_JOB_INVAL_BLOCK;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the invalidate block job */
        Fee_eJobResult = MEMIF_JOB_PENDING;

        RetVal = (Std_ReturnType)E_OK;
    }
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_02();

    return RetVal;
}

/* @implements  FEE_VERSION_INFO_API==STD_ON_ActivityPartition */
#if ((FEE_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__))
/**
* @brief        Return the version information of the Fee module.
* @details      The version information includes: Module Id, Vendor Id,
*               Vendor specific version numbers.
*
* @param[out]   VersionInfoPtr  Pointer to where to store the version
*                                information of this module .
*
* @pre          VersionInfoPtr must not be NULL_PTR.
* @note         The function Autosar Service ID[hex]: 0x08.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_GetVersionInfo_Activity
*/
void Fee_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_GETVERSIONINFO_ID, FEE_E_PARAM_POINTER);
    }
    else
    {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        VersionInfoPtr->moduleID = (uint16)FEE_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)FEE_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)FEE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FEE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FEE_SW_PATCH_VERSION;
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FEE_VERSION_INFO_API == STD_ON */

/**
* @brief        Service to erase a logical block.
* @details      The function Fee_EraseImmediateBlock shall take the block number
*               and calculate the corresponding memory block address.
*               The function Fee_EraseImmediateBlock shall ensure that the FEE
*               module can write immediate data. Whether this involves
*               physically erasing a memory area and therefore calling the erase
*               function of the underlying driver depends on the implementation.
*               If development error detection for the FEE module is enabled,
*               the function Fee_EraseImmediateBlock shall check whether the
*               addressed logical block is configured as containing immediate
*               data (configuration parameter FeeImmediateData == TRUE).
*               If not, the function Fee_EraseImmediateBlock
*               shall report the error code FEE_E_INVALID_BLOCK_NO.
*
* @param[in]    BlockNumber     Number of logical block, also denoting.
*
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the underlying
*                                memory driver.
*                                start address of that block in emulated EEPROM.
*
* @pre          The module must be initialized, not busy, BlockNumber must be
*               valid, and type of Fee block must be immediate.
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockIndex,
*               Fee_eJob, and Fee_eJobResult job control internal variables.
*
* @note         The function Autosar Service ID[hex]: 0x09.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_EraseImmediateBlock_Activity
*/
Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_03();

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else 
    {
        if (0xFFFFU == BlockIndex)
        {
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if (FALSE == Fee_BlockConfig[BlockIndex].ImmediateData)
            {
                (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Configure the erase immediate block job */
        Fee_uJobBlockIndex = BlockIndex;
        Fee_eJob = FEE_JOB_ERASE_IMMEDIATE;
        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the erase immediate block job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
    }

    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_03();

    return RetVal;
}

/**
* @brief      To report the error end of an asynchronous operation.
*/
static void Fee_DoJobErrorNotification(void)
{
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    Std_ReturnType TransStatus;
#endif

    if (MEMIF_JOB_CANCELED == Fee_eJobResult)
    {
        /* MemAcc job has been canceled. Do nothing in this callback.
        The NvM_JobErrorNotification() callback will be called from the Fee_Cancel()function which called the MemAcc_Cancel() function */
    }   
    else
    {
    #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        if (Fee_eTransJob == FEE_TRANS_JOB_ERASE)
        {
            /* An erase job has failed, check and update the subAddressAreas information */
            TransStatus = Fee_TranslationJobEraseFailed();
        }
        else
        {
            /* If not an erase operation */
            TransStatus = E_NOT_OK;
        }
        /* A read, write job has failed, or a cluster became bad: check the Fee job status */
        if ((Std_ReturnType)E_OK != TransStatus)
    #endif
        {
            /* Schedule the error job */
            Fee_JobErrorSchedule();
        }
    }
}

static void Fee_ContinueHandleInternalJob(void)
{
    if (FEE_JOB_DONE == Fee_eJob)
    {
        /* Last schedule MemAcc job finished */
        Fee_eJobResult = MEMIF_JOB_OK;
        Fee_eModuleStatus = MEMIF_IDLE;
        /* Call job end notification function */
        FEE_NVM_JOB_END_NOTIFICATION
    }
    else
    {
        Fee_eJobResult = Fee_JobSchedule();
        if (MEMIF_JOB_OK == Fee_eJobResult)
        {
            Fee_eModuleStatus = MEMIF_IDLE;
            /* Call job end notification function */
            FEE_NVM_JOB_END_NOTIFICATION
        }
        else if (MEMIF_JOB_PENDING == Fee_eJobResult)
        {
            /* Nothing to do (ongoing MemAcc job) */
        }
        else
        {
            Fee_eModuleStatus = MEMIF_IDLE;
            /* Call job error notification function */
            FEE_NVM_JOB_ERROR_NOTIFICATION
        }
    }
}
/**
* @brief        Service to report the FEE module the successful/error end of
*               an asynchronous operation.
* @details      The underlying memacc driver shall call the function
*               Fee_JobEndNotification to report the successful/error end of
*               an asynchronous operation.
*
* @pre          The module must be initialized.
* @post         Changes Fee_eModuleStatus module status and Fee_eJobResult
*               internal variables.
* @note         The function Autosar Service ID[hex]: 0x10.
* @note         Synchronous.
* @note         Non Reentrant
*
* @api
*
* @implements   Fee_JobEndNotification_Activity
*/
void Fee_JobEndNotification(MemAcc_AddressAreaIdType    AddressAreaId,
                            MemAcc_JobResultType        JobResult)
{
    if ((MEMIF_UNINIT == Fee_eModuleStatus) && (MEMIF_JOB_OK == Fee_eJobResult) && (FEE_JOB_DONE == Fee_eJob))
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_JOBENDNOTIFICATION_ID, FEE_E_UNINIT);
#else
     /* Do nothing. Fee is not initialized */
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        if ((JobResult == MEMACC_MEM_OK) || (JobResult == MEMACC_MEM_ECC_CORRECTED))
        {
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
            /* There's still data, continue with the translation jobs */
            if (Fee_uTransJobLength != 0U)
            {
                Fee_eJobResult = Fee_TransJobSchedule();
            }
            else
#endif
            {
                Fee_ContinueHandleInternalJob();
            }
        }
        else
        {
            Fee_DoJobErrorNotification();
        }
    }
    /* to avoid error compiler warning */
    (void)AddressAreaId;
}


/**
* @brief        Service to handle the requested read, write, or erase jobs
*               respectively the internal management operations.
* @details      The function shall asynchronously handle the requested
*               read, write, or erase jobs respectively the internal management operations.
*               The function shall check, whether
*               the block requested for reading has been invalidated by the
*               upper layer module.
*               If so, the function shall set the job result to
*               MEMIF_BLOCK_INVALID and call the error notification routine
*               of the upper layer if configured.
*               The function shall check the consistency of the logical block
*               being read before notifying the caller. If an inconsistency
*               of the read data is detected, the function
*               shall set the job result to MEMIF_BLOCK_INCONSISTENT and call
*               the error notification routine of the upper layer.
* @pre          The module must be initialized.
* @note         The function Autosar Service ID[hex]: 0x12.
*
* @api
*
* @implements   Fee_MainFunction_Activity
*/
void Fee_MainFunction(void)
{
    if (MEMIF_JOB_PENDING == Fee_eJobResult)
    {
        switch (Fee_eJob)
        {
            /* for all the following jobs subsequent jobs will be called in Fee job schedule function based on Job */
            case FEE_JOB_INT_SCAN:
            case FEE_JOB_READ:
            case FEE_JOB_WRITE:
            case FEE_JOB_INVAL_BLOCK:
            case FEE_JOB_ERASE_IMMEDIATE:
                Fee_eJobResult = Fee_JobSchedule();
                break;
            /* for all the following jobs job end or job error notification will be called based on the job result */
            case FEE_JOB_WRITE_DATA:
            case FEE_JOB_WRITE_UNALIGNED_DATA:
            case FEE_JOB_WRITE_VALIDATE:
            case FEE_JOB_WRITE_DONE:
            case FEE_JOB_INVAL_BLOCK_DONE:
            case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            case FEE_JOB_INT_SCAN_CLR:
            case FEE_JOB_INT_SCAN_CLR_FMT:
            case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
            case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            case FEE_JOB_INT_SWAP_BLOCK:
            case FEE_JOB_INT_SWAP_CLR_FMT:
            case FEE_JOB_INT_SWAP_DATA_READ:
            case FEE_JOB_INT_SWAP_DATA_WRITE:
            case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
            case FEE_JOB_DONE:
            default:
                /* Internal or subsequent job */
                break;
        }

        if (MEMIF_JOB_PENDING == Fee_eJobResult)
        {
            /* Nothing to do */
        }
        else if (MEMIF_JOB_OK == Fee_eJobResult)
        {
            Fee_eModuleStatus = MEMIF_IDLE;
            /* Call job end notification function */
            FEE_NVM_JOB_END_NOTIFICATION
        }
        else
        {
            Fee_eModuleStatus = MEMIF_IDLE;
            /* Call job error notification function */
            FEE_NVM_JOB_ERROR_NOTIFICATION
        }
    }
}
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Service to read all subAddressArea runtime information in the selected cluster.
*               The information includes the start address and size of each subAddressArea.
*               If the subAddressArea size value is 0, it means that subAddressArea is bad.
*               User can replace it from the GUI configuration.
*               Detail step-by-step instructions will be in the chapter "SubAddressArea Managerment and SubAddressArea Retirement" in the User manual.
*
*/
static void Fee_GetSubAddressAreaRunTimeInfo(uint8 ClrGrpIndex,
                                     const Fee_ClusterGroupRuntimeInfoType *ClrGrpRTInfo
                                    )
{
    uint32 clrIt;
    uint32 SubAddressAreaIt;
    Fee_SubAddressAreaRuntimeInfoType *UserSubAddressAreaList = ClrGrpRTInfo->SubAddressAreaInfo;

    /* Check if there is a request to get subAddressArea information */
    if (NULL_PTR != UserSubAddressAreaList)
    {
        for (clrIt = 0U; clrIt < Fee_ClrGrps[ClrGrpIndex].ClrCount; clrIt++)
        {
            for (SubAddressAreaIt = 0U; SubAddressAreaIt < Fee_aClrGrpInfo[ClrGrpIndex].ClrInfo[clrIt].SubAddressAreaCount; SubAddressAreaIt++)
            {
                /* Copy internal data to user memory */
                *UserSubAddressAreaList = Fee_aClrGrpInfo[ClrGrpIndex].ClrInfo[clrIt].SubAddressAreaList[SubAddressAreaIt];
                UserSubAddressAreaList++;
            }
        }
    }
}
#endif /* FEE_SUBADDRESSAREA_RETIREMENT == STD_ON */
/**
* @brief        Service to read runtime information in the selected cluster group.
*
* @param[in]    ClrGrpIndex    Index of the selected cluster group
* @param[in]    ClrGrpRTInfo   Pointer to point Fee cluster group run-time Information
*
* @return       Fee_ClusterGroupRuntimeInfoType
* @retval       ClusterTotalSpace current cluster total size
* @retval       ClusterFreeSpace current cluster available space.
* @retval       BlockHeaderOverhead the block header overhead (blk header, valid flag and inval flag),
* @retval       VirtualPageSize the virtual page size (the size of an allocation unit)
* @retval       NumberOfSwap number of cluster swap already performed
* @retval       SubAddressAreaInfo subAddressArea information from all clusters in the selected cluster group (in subAddressArea retirement mode only)
*
* @pre          The module must be initialized, not busy and ClrGrpIndex must be valid
*
* @api
*
* @implements   Fee_GetRunTimeInfo_Activity
*/
void Fee_GetRunTimeInfo(uint8 ClrGrpIndex, Fee_ClusterGroupRuntimeInfoType *ClrGrpRTInfo)
{
    uint8 ActiveClrIndex;

    /* DET Check for cluster group should be added:
        - INITIALIZED driver
        - BUSY and BUSY_INTERNAL driver
        - Cluster group valid */
    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == ClrGrpRTInfo)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_GETRUNTIMEINFO_ID, FEE_E_PARAM_POINTER);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_BUSY);
    }
    /* Cluster group index in valid range */
    else if (FEE_NUMBER_OF_CLUSTER_GROUPS <= ClrGrpIndex)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_CLUSTER_GROUP_IDX);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Get active cluster index for selected cluster group */
        ActiveClrIndex = Fee_aClrGrpInfo[ ClrGrpIndex ].ActClr;

        /* Size of the active cluster in selected cluster group */
        ClrGrpRTInfo->ClusterTotalSpace = Fee_GetClusterLength(ClrGrpIndex, ActiveClrIndex);

        ClrGrpRTInfo->ClusterFreeSpace = Fee_aClrGrpInfo[ ClrGrpIndex ].DataAddrIt -
                                          (Fee_aClrGrpInfo[ ClrGrpIndex ].HdrAddrIt + FEE_BLOCK_OVERHEAD);

        ClrGrpRTInfo->BlockHeaderOverhead = (uint16)FEE_BLOCK_OVERHEAD;
        ClrGrpRTInfo->VirtualPageSize = (uint16)FEE_VIRTUAL_PAGE_SIZE;
        ClrGrpRTInfo->NumberOfSwap = Fee_aClrGrpInfo[ ClrGrpIndex ].ActClrID - 1U;
        #if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
        /* Get subAddressArea information from all clusters for selected cluster group */
        Fee_GetSubAddressAreaRunTimeInfo(ClrGrpIndex, ClrGrpRTInfo);
        #endif
    }
    /* to avoid error compiler warning */ 
    (void)ActiveClrIndex;
}

/**
* @brief        Service to prepare the driver for a cluster swap in the selected cluster group.
*
* @detailes     While the computed amount of memory is allocated as a result of Fee_Write
*               call for plain data blocks, for immediate data blocks memory gets completely
*               pre-allocated through Fee_EraseImmediateBlock function (i.e. Fee_Write does
*               not change the remaining space).
*               As a result, swaps triggered by the planned Fee_ForceSwapOnNextWrite function
*               behave the same way, or in other words, an operation that really activates the
*               pysical swap must be either Fee_Write on plain FEE block or
*               Fee_EraseImmediateBlock on immediate data block.
*
* @param[in]    ClrGrpIndex    Index of the selected cluster group

* @return       Std_ReturnType
* @retval       E_NOT_OK  module is not initialized, busy or ClrGrpIndex is not in the
*                         valid range.
* @retval       E_OK      No more space available in the selected cluster.
*
* @pre          The module must be initialized, not busy and ClrGrpIndex must be valid.
*
* @note         As this API manipulates the internal driver state, it has to be claimed
*               non-reentrant and colliding with other FEE ASR APIs
* @api
*
* @implements   Fee_ForceSwapOnNextWrite_Activity
*/
Std_ReturnType Fee_ForceSwapOnNextWrite(uint8 ClrGrpIndex)
{
    Std_ReturnType RetVal;

    /* DET Check for cluster group should be added:
        - INITIALIZED driver
        - BUSY and BUSY_INTERNAL driver
        - Cluster group valid */

    if (MEMIF_UNINIT == Fee_eModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_UNINIT);
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (MEMIF_BUSY == Fee_eModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_BUSY);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    /* Cluster group index in valid range */
    else if (FEE_NUMBER_OF_CLUSTER_GROUPS <= ClrGrpIndex)
    {
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_CLUSTER_GROUP_IDX);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {
        Fee_aClrGrpInfo[ClrGrpIndex].DataAddrIt = Fee_aClrGrpInfo[ClrGrpIndex].HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD);
        RetVal = (Std_ReturnType)E_OK;
    }

    return RetVal;
}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
