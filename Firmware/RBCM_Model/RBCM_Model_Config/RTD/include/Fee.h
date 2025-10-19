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

#ifndef FEE_H
#define FEE_H

/**
*   @file
*
*   @addtogroup FEE
*   @implements Fee.h_Artifact
*
*   @{
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
#include "Fee_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_AR_RELEASE_MAJOR_VERSION     4
#define FEE_AR_RELEASE_MINOR_VERSION     7
#define FEE_AR_RELEASE_REVISION_VERSION  0
#define FEE_SW_MAJOR_VERSION             5
#define FEE_SW_MINOR_VERSION             0
#define FEE_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* AUTOSAR module vendor identification */
#define FEE_VENDOR_ID            43

/* AUTOSAR module identification */
#define FEE_MODULE_ID            21

 /* AUTOSAR module instance identification */
#define FEE_INSTANCE_ID          0U

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fee configuration header file are of the same vendor */
#if (FEE_VENDOR_ID != FEE_VENDOR_ID_CFG)
    #error "Fee.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fee configuration header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION    != FEE_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_MINOR_VERSION    != FEE_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_REVISION_VERSION != FEE_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif
/* Check if current file and Fee configuration header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_CFG) || \
     (FEE_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_CFG) || \
     (FEE_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*  All service IDs (passed to DET) */

/**
*   @brief service ID of function: Fee_Init. (passed to DET)
*/
#define FEE_INIT_ID                    ((uint8)0x00)

/**
*   @brief service ID of function: Fee_Read. (passed to DET)
*/
#define FEE_READ_ID                    ((uint8)0x02)

/**
*   @brief service ID of function: Fee_Write. (passed to DET)
*/
#define FEE_WRITE_ID                   ((uint8)0x03)

/**
*   @brief service ID of function: Fee_Cancel. (passed to DET)
*/
#define FEE_CANCEL_ID                  ((uint8)0x04)

/**
*   @brief service ID of function: Fee_GetStatus. (passed to DET)
*/
#define FEE_GETSTATUS_ID               ((uint8)0x05)

/**
*   @brief service ID of function: Fee_GetJobResult. (passed to DET)
*/
#define FEE_GETJOBRESULT_ID            ((uint8)0x06)

/**
*   @brief service ID of function: Fee_InvalidateBlock. (passed to DET)
*/
#define FEE_INVALIDATEBLOCK_ID         ((uint8)0x07)

/**
*   @brief service ID of function: Fee_GetVersionInfo. (passed to DET)
*/
#define FEE_GETVERSIONINFO_ID          ((uint8)0x08)

/**
*   @brief service ID of function: Fee_EraseImmediateBlock. (passed to DET)
*/
#define FEE_ERASEIMMEDIATEBLOCK_ID     ((uint8)0x09)

/**
*   @brief service ID of function: Fee_JobEndNotification. (passed to DET)
*/
#define FEE_JOBENDNOTIFICATION_ID      ((uint8)0x10)

/**
*   @brief service ID of function: Fee_MainFunction. (passed to DET)
*/
#define FEE_MAINFUNCTION_ID            ((uint8)0x12)

/* Vendor specific ID */

/**
*   @brief service ID of function: Fee_GetRunTimeInfo. (passed to DET)
*/
#define FEE_GETRUNTIMEINFO_ID          ((uint8)0x13)

/**
*   @brief service ID of function: Fee_ForceSwapOnNextWrite. (passed to DET)
*/
#define FEE_FORCESWAPONNEXTWRITE_ID    ((uint8)0x14)


/* Development error codes (passed to DET) */

/** @brief API called when module was not initialized */
#define FEE_E_UNINIT                   ((uint8)0x01)

/** @brief API called with invalid block number */
#define FEE_E_INVALID_BLOCK_NO         ((uint8)0x02)

/** @brief API called with invalid block offset */
#define FEE_E_INVALID_BLOCK_OFS        ((uint8)0x03)

/** @brief API called with invalid data pointer */
#define FEE_E_PARAM_POINTER            ((uint8)0x04)

/** @brief API called with invalid length information */
#define FEE_E_INVALID_BLOCK_LEN        ((uint8)0x05)

/** @brief API called while module is busy processing a user request */
#define FEE_E_BUSY                     ((uint8)0x06)

/** @brief API called while module is not busy because there is no job to cancel */
#define FEE_E_INVALID_CANCEL           ((uint8)0x08)

/* Vendor Specific Definition */
/** @brief API called with invalid cluster group index */
#define FEE_E_CLUSTER_GROUP_IDX        ((uint8)0x0B)

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/** @brief API number of foreign blocks from data flash exceeds the total number of blocks allowed which is FEE_MAX_NR_OF_BLOCKS */
#define FEE_E_FOREIGN_BLOCKS_OVF       ((uint8)0x0C)
#endif
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/**
* @brief        Service to initialize the FEE module.
* @details      The function Fee_Init shall initialize the Flash EEPROM
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

extern void Fee_Init(const Fee_ConfigType *ConfigPtr);

/**
* @brief        Service to initiate a read job.
* @details      The function Fee_Read shall take the block start address and
*               offset and calculate the corresponding memory read address.
*
* @param[in]    BlockNumber     Number of logical block, also denoting
*                                start address of that block in flash memory.
* @param[in]    BlockOffset     Read address offset inside the block.
* @param[out]   DataBufferPtr   Pointer to data buffer.
* @param[in]    Length          Number of bytes to read.
*
* @pre          The module must be initialized, not busy, uBlockNumber must be
*               valid, uLength != 0, pDataBufferPtr != NULL_PTR, uBlockOffset and
*               (uBlockOffset + uLength - 1) must be in range Length must be aligned with FEE_MINIMUM_READ_PAGE_SIZE.
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
extern Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length);

/**
* @brief        Service to initiate a write job.
* @details      The function Fee_Write shall take the block start address and
*               calculate the corresponding memory write address. The block
*               address offset shall be fixed to zero.
*               The function Fee_Write shall copy the given or computed
*               parameters to module internal variables, initiate a write job,
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
* @pre          The module must be initialized, not busy, uBlockNumber must be
*               valid, and pDataBufferPtr != NULL_PTR must be aligned with FEE_BUFFER_ALIGN_VALUE.
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
extern Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8 *DataBufferPtr);

/**
* @brief        Service to call the cancel function of the underlying flash
*               driver.
* @details      The function Fee_Cancel and the cancel function of the
*               underlying flash driver are asynchronous w.r.t. an ongoing
*               read, erase or write job in the flash memory.
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
extern void Fee_Cancel(void);

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
extern MemIf_StatusType Fee_GetStatus(void);

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
extern MemIf_JobResultType Fee_GetJobResult(void);

/**
* @brief        Service to invalidate a logical block.
*
* @param[in]    BlockNumber     Number of logical block, also denoting
*                                start address of that block in flash memory
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the
*                                underlying memory driver.
*
* @pre          The module must be initialized, not busy, and uBlockNumber must be
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
extern Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber);

#if( FEE_VERSION_INFO_API == STD_ON )
/**
* @brief        Return the version information of the Fee module.
* @details      The version information includes: Module Id, Vendor Id,
*               Vendor specific version numbers.
*
* @param[out]   VersionInfoPtr  Pointer to where to store the version
*                                information of this module .
*
* @pre          pVersionInfoPtr must not be NULL_PTR.
* @note         The function Autosar Service ID[hex]: 0x08.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_GetVersionInfo_Activity
*/
extern void Fee_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
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
* @pre          The module must be initialized, not busy, uBlockNumber must be
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
extern Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber);

/**
* @brief        Service to read runtime information in the selected cluster.
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
* @retval       SectorInfo sector information from all clusters in the selected cluster group (in sector retirement mode only)
*
* @pre          The module must be initialized, not busy and uClrGrpIndex must be valid
*
* @api
*
* @implements   Fee_GetRunTimeInfo_Activity
*/
extern void Fee_GetRunTimeInfo(uint8 ClrGrpIndex, Fee_ClusterGroupRuntimeInfoType *ClrGrpRTInfo);

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
* @retval       E_NOT_OK  module is not initialized, busy or uClrGrpIndex is not in the
*                         valid range.
* @retval       E_OK      No more space available in the selected cluster.
*
* @pre          The module must be initialized, not busy and uClrGrpIndex must be valid.
*
* @note         As this API manipulates the internal driver state, it has to be claimed
*               non-reentrant and colliding with other FEE ASR APIs
* @api
*
* @implements   Fee_ForceSwapOnNextWrite_Activity
*/
extern Std_ReturnType Fee_ForceSwapOnNextWrite(uint8 ClrGrpIndex);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FEE_H */
