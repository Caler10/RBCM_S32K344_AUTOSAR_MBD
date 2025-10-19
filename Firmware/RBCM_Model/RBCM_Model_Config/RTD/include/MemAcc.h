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

#ifndef MEMACC_H
#define MEMACC_H

/**
*   @file MemAcc.h
*
*   @addtogroup MEMACC
*   @implements MemAcc.h_Artifact
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
#include "MemAcc_Cfg.h"
#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
#include "Mcal.h"
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_VENDOR_ID                      43
#define MEMACC_AR_RELEASE_MAJOR_VERSION       4
#define MEMACC_AR_RELEASE_MINOR_VERSION       7
#define MEMACC_AR_RELEASE_REVISION_VERSION    0
#define MEMACC_SW_MAJOR_VERSION               5
#define MEMACC_SW_MINOR_VERSION               0
#define MEMACC_SW_PATCH_VERSION               0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and MemAcc_Cfg.h file are of the same vendor */
#if (MEMACC_VENDOR_ID != MEMACC_VENDOR_ID_CFG)
    #error "MemAcc.h and MemAcc_Cfg.h have different vendor ids"
#endif
/* Check if current file and MemAcc_Cfg.h file are of the same Autosar version */
#if ((MEMACC_AR_RELEASE_MAJOR_VERSION    != MEMACC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEMACC_AR_RELEASE_MINOR_VERSION    != MEMACC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEMACC_AR_RELEASE_REVISION_VERSION != MEMACC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of MemAcc.h and MemAcc_Cfg.h are different"
#endif
/* Check if current file and MemAcc_Cfg.h file are of the same software version */
#if ((MEMACC_SW_MAJOR_VERSION != MEMACC_SW_MAJOR_VERSION_CFG) || \
     (MEMACC_SW_MINOR_VERSION != MEMACC_SW_MINOR_VERSION_CFG) || \
     (MEMACC_SW_PATCH_VERSION != MEMACC_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of MemAcc.h and MemAcc_Cfg.h are different"
#endif

#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files MemAcc.h and Mcal.h are of the same version */
   #if ((MEMACC_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (MEMACC_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
       )
       #error "AutoSar Version Numbers of MemAcc.h and Mcal.h are different"
   #endif
#endif
#endif
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
*  @brief    AUTOSAR module identification
*/
#define MEMACC_MODULE_ID                41U

/**
*  @brief    AUTOSAR module instance identification
*/
#define MEMACC_INSTANCE_ID              0U


/**
*  Development error codes (passed to DET)
*/
#define MEMACC_E_UNINIT                            0x01U  /**< @brief Development error codes (passed to DET). API service called without module initialization                                        */
#define MEMACC_E_PARAM_POINTER                     0x02U  /**< @brief Development error codes (passed to DET). API service called with NULL pointer argument                                           */
#define MEMACC_E_PARAM_ADDRESS_AREA_ID             0x03U  /**< @brief Development error codes (passed to DET). API service called with wrong address area ID                                           */
#define MEMACC_E_PARAM_ADDRESS_LENGTH              0x04U  /**< @brief Development error codes (passed to DET). API service called with address and length not belonging to the passed address area ID  */
#define MEMACC_E_PARAM_HW_ID                       0x05U  /**< @brief Development error codes (passed to DET). API service called with a hardware ID not belonging to the passed address area ID       */
#define MEMACC_E_BUSY                              0x06U  /**< @brief Development error codes (passed to DET). API service called for an address area ID with a pending job request                    */
#define MEMACC_E_MEM_INIT_FAILED                   0x07U  /**< @brief Development error codes (passed to DET). Dynamic MEM driver activation failed due to inconsistent MEM driver binary              */
#define MEMACC_E_OK                                0xFFU  /**< @brief Development error codes (passed to DET). API service called without errors                                                       */


/**
* All service IDs (passed to DET)
*/
/* Synchronous Functions */
#define MEMACC_DEINIT_ID                           0x00U  /**< @brief Service ID of function MemAcc_DeInit                        */
#define MEMACC_INIT_ID                             0x01U  /**< @brief Service ID of function MemAcc_Init                          */
#define MEMACC_GETVERSIONINFO_ID                   0x02U  /**< @brief Service ID of function MemAcc_GetVersionInfo                */

#define MEMACC_GETJOBRESULT_ID                     0x05U  /**< @brief Service ID of function MemAcc_GetJobResult                  */
#define MEMACC_GETJOBSTATUS_ID                     0x05U  /**< @brief Service ID of function MemAcc_GetJobStatus                  */
#define MEMACC_GETMEMORYINFO_ID                    0x06U  /**< @brief Service ID of function MemAcc_GetMemoryInfo                 */
#define MEMACC_GETPROCESSEDLENGTH_ID               0x07U  /**< @brief Service ID of function MemAcc_GetProcessedLength            */
#define MEMACC_GETJOBINFO_ID                       0x08U  /**< @brief Service ID of function MemAcc_GetJobInfo                    */

#define MEMACC_ACTIVATEMEM_ID                      0x14U  /**< @brief Service ID of function MemAcc_ActivateMem                   */
#define MEMACC_DEACTIVATEMEM_ID                    0x15U  /**< @brief Service ID of function MemAcc_DeactivateMem                 */


/* Asynchronous Functions */
#define MEMACC_CANCEL_ID                           0x04U  /**< @brief Service ID of function MemAcc_Cancel                        */
#define MEMACC_READ_ID                             0x09U  /**< @brief Service ID of function MemAcc_Read                          */
#define MEMACC_WRITE_ID                            0x0AU  /**< @brief Service ID of function MemAcc_Write                         */
#define MEMACC_ERASE_ID                            0x0BU  /**< @brief Service ID of function MemAcc_Erase                         */
#define MEMACC_COMPARE_ID                          0x0CU  /**< @brief Service ID of function MemAcc_Compare                       */
#define MEMACC_BLANKCHECK_ID                       0x0DU  /**< @brief Service ID of function MemAcc_BlankCheck                    */
#define MEMACC_HWSPECIFICSERVICE_ID                0x0EU  /**< @brief Service ID of function MemAcc_HwSpecificService             */
#define MEMACC_REQUESTLOCK_ID                      0x11U  /**< @brief Service ID of function MemAcc_RequestLock                   */
#define MEMACC_RELEASELOCK_ID                      0x12U  /**< @brief Service ID of function MemAcc_ReleaseLock                   */


/* Scheduled Functions */
#define MEMACC_MAINFUNCTION_ID                     0x03U  /**< @brief Service ID of function MemAcc_MainFunction                  */


/* Notification Functions */
#define MEMACC_ADDRESSAREAJOBENDNOTIFICATION_ID    0x0FU  /**< @brief Service ID of function AddressAreaJobEndNotification        */
#define MEMACC_APPLICATIONLOCKNOTIFICATION_ID      0x14U  /**< @brief Service ID of function MemAcc_ApplicationLockNotification   */

#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
    #define MemAcc_GetUserID()            OsIf_GetUserId()
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#ifndef MEMACC_PRECOMPILE_SUPPORT
#define MEMACC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemAcc_MemMap.h"

MEMACC_CONFIG_EXT

#define MEMACC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemAcc_MemMap.h"
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
#define MEMACC_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "MemAcc_MemMap.h"

/* Pointer to current memacc module configuration set */
extern const MemAcc_ConfigType            *MemAcc_pConfigPtr;

#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
#define MEMACC_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "MemAcc_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief        The function initializes MemAcc module.
 *
 * @details      Initialization function - initializes all variables
 *               and sets the module state to initialized.
 *
 * @param[in]    ConfigPtr    Pointer to selected configuration structure.
 *
 * @return       None
 *
 * @pre          ConfigPtr must not be NULL_PTR and the module status must not be BUSY.
 *
 * @api
 */
void MemAcc_Init(const MemAcc_ConfigType * ConfigPtr);


/**
 * @brief        The function de-initializes the MemAcc module.
 *
 * @details      De-initialize module.
 *               If there is still an access job pending, it is immediately terminated (using hardware cancel operation)
 *               and the Mem driver module state is set to unitialized.
 *               Therefore, Mem must be re-initialized before it will accept any new job requests after this service is processed.
 *
 * @return       None
 *
 * @api
 *
 * @pre          The MemAcc module must be re-initialized before it will accept
 *               any new job requests after this service is processed.
 */
void MemAcc_DeInit(void);


/**
 * @brief        Service to return the version information of the MemAcc module.
 *
 * @details      Version information includes:
 *               - Module Id
 *               - Vendor Id
 *               - Vendor specific version numbers
 *
 * @param[out]   VersionInfoPtr    Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 * @api
 */
void MemAcc_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr);


/**
 * @brief        Get the most recent job result of the referenced address area.
 *
 * @details      Returns the consolidated job result of the address area referenced by AddressAreaId.
 *               If a MemAcc job is still pending, the API returns the result of the last MemAcc job.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @return       MemAcc_JobResultType    Most recent job result.
 *
 * @api
 */
MemAcc_JobResultType MemAcc_GetJobResult(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief        Get the most recent job status of the referenced address area.
 *
 * @details      Returns the status of the MemAcc job referenced by addressAreaId.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @return       MemAcc_JobStatusType    Most recent job status.
 *
 * @api
 */
MemAcc_JobStatusType MemAcc_GetJobStatus(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief        Get the memory information of the referenced address area.
 *
 * @details      This service function retrieves the physical memory device information of a specific address area.
 *               It can be used by an upper layer to get all necessary information to align the start address
 *               and trim the length for erase/write jobs.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 * @param[in]    Address          Address in logical address space from which corresponding memory device information shall be retrieved.
 *
 * @param[out]   MemoryInfoPtr    Destination memory pointer to store the memory device information.
 *
 * @return       Std_ReturnType
 *                   - E_OK                   : The requested addressAreaId and address are valid.
 *                   - E_NOT_OK               : The requested addressAreaId and address are invalid.
 *
 * @api
 */
Std_ReturnType MemAcc_GetMemoryInfo (MemAcc_AddressAreaIdType    AddressAreaId,
                                     MemAcc_AddressType          Address,
                                     MemAcc_MemoryInfoType      *MemoryInfoPtr
                                    );


/**
 * @brief        Get the processed length of data of the referenced address area.
 *
 * @details      Returns the accumulated number of bytes that have already been processed in the current job.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @return       MemAcc_LengthType    Processed length of current job (in bytes).
 *
 * @api
 */
MemAcc_LengthType MemAcc_GetProcessedLength(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief        Get the job information of the referenced address area.
 *
 * @details      Returns detailed information of the current memory job
 *               like memory device ID, job type, job processing state or job result, address area as well as address and length.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @param[out]   JobInfoPtr       Structure pointer to return the detailed processing information of the current job.
 *
 * @return       None
 *
 * @api
 */
void MemAcc_GetJobInfo (MemAcc_AddressAreaIdType    AddressAreaId,
                        MemAcc_JobInfoType         *JobInfoPtr
                       );


/**
 * @brief        Dynamic activation and initialization of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @details      Dynamic activation and initialization of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @param[in]    HeaderAddress    Physical start address of Mem driver header structure.
 * @param[in]    HwId             Unique numeric memory driver identifier.
 *
 * @return       Std_ReturnType
 *               - E_OK         Mem driver activation successful.
 *               - E_NOT_OK     Mem driver activation failed.
 *
 * @api
 */
Std_ReturnType MemAcc_ActivateMem (MemAcc_AddressType    HeaderAddress,
                                   MemAcc_HwIdType       HwId
                                  );


/**
 * @brief        Dynamic deactivation of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @details      Dynamic deactivation of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @param[in]    HwId             Unique numeric memory driver identifier.
 * @param[in]    HeaderAddress    Physical start address of Mem driver header structure.
 *
 * @return       Std_ReturnType
 *               - E_OK         Mem driver deactivation successful.
 *               - E_NOT_OK     Mem driver deactivation failed.
 *
 * @api
 */
Std_ReturnType MemAcc_DeactivateMem (MemAcc_HwIdType       HwId,
                                     MemAcc_AddressType    HeaderAddress
                                    );


/**
 * @brief            Cancel an ongoing job.
 *
 * @details          Triggers a cancel operation of the pending job for the address area referenced by the AddressAreaId.
 *                   Cancelling affects only jobs in pending state. For any other states, the request will be ignored.
 *                   Abort a running job synchronously so that directly after returning from this function a new job can be started.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 *
 * @return           None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
void MemAcc_Cancel(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief            Reads from an address area.
 *
 * @details          Triggers a read job to copy data from the source address into the referenced destination data buffer.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the read operation was successful, the result of the job is MEMACC_MEM_OK.
 *                   If the read operation failed, the result of the job is either MEMACC_MEM_FAILED in case of a general error
 *                   or MEMACC_MEM_ECC_CORRECTED/MEMACC_MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        SourceAddress         Read address in logical address space.
 * @param[in]        Length                Read length in bytes (aligned to read page size).
 *
 * @param[out]       DestinationDataPtr    Destination memory pointer to store the read data
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_Read (MemAcc_AddressAreaIdType    AddressAreaId,
                            MemAcc_AddressType          SourceAddress,
                            MemAcc_DataType            *DestinationDataPtr,
                            MemAcc_LengthType           Length
                           );

/**
 * @brief            Writes to an address area.
 *
 * @details          Triggers a write job to store the passed data to the provided address area with given address and length.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the write operation was successful, the job result is MEMACC_MEM_OK.
 *                   If there was an issue writing the data, the result is MEMACC_MEM_FAILED.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        TargetAddress         Write address in logical address space.
 * @param[out]       SourceDataPtr         Source data pointer (aligned to MemAccBufferAlignmentValue).
 * @param[in]        Length                Write length in bytes (aligned to page size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_Write (MemAcc_AddressAreaIdType     AddressAreaId,
                             MemAcc_AddressType           TargetAddress,
                             const MemAcc_DataType       *SourceDataPtr,
                             MemAcc_LengthType            Length
                            );


/**
 * @brief            Erase one or more complete subaddress area in an address area.
 *
 * @details          Triggers an erase job of the given area.
 *                   Triggers an erase job of the given area defined by targetAddress and length.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API.
 *                   If the erase operation was successful, the result of the job is MEM_JOB_OK.
 *                   If the erase operation failed, e.g. due to a hardware issue, the result of the job is MEM_JOB_FAILED.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        TargetAddress         Erase address in logical address space (aligned to sector size).
 * @param[in]        Length                Erase length in bytes (aligned to sector size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_Erase (MemAcc_AddressAreaIdType    AddressAreaId,
                             MemAcc_AddressType          TargetAddress,
                             MemAcc_LengthType           Length
                            );


#if (MEMACC_COMPARE_API == STD_ON)

/**
 * @brief            Compares a memory area with an application data buffer.
 *
 * @details          Triggers a job to compare the passed data to the memory content of the provided address area.
 *                   The job terminates, if all bytes matched or a difference was detected.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult() API.
 *                   If the compare operation determined a mismatch, the result code is MEMACC_MEM_INCONSISTENT.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        SourceAddress         Compare address in logical address space.
 * @param[in]        DataPtr               Pointer to user data which shall be compared to data in memory.
 * @param[in]        Length                Compare length in bytes.
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_Compare (MemAcc_AddressAreaIdType    AddressAreaId,
                               MemAcc_AddressType          SourceAddress,
                               const MemAcc_DataType      *DataPtr,
                               MemAcc_LengthType           Length
                              );

#endif


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 *
 * @details          Checks if the passed address space is blank, i.e. erased and writeable.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the address area defined by targetAddress and length is blank, the result is MEMACC_MEM_OK,
 *                   otherwise the result is MEMACC_MEM_INCONSISTENT.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        TargetAddress         Blank check address in logical address space.
 * @param[in]        Length                Blank check length in bytes.
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_BlankCheck (MemAcc_AddressAreaIdType    AddressAreaId,
                                  MemAcc_AddressType          TargetAddress,
                                  MemAcc_LengthType           Length
                                 );


/**
 * @brief            Trigger a hardware specific service.
 *
 * @details          Triggers a hardware specific job request referenced by hwServiceId.
 *                   Service specific data can be passed/retrieved by dataPtr.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the hardware specific operation was successful, the result of the job is MEMACC_MEM_OK.
 *                   If the hardware specific operation failed, the result of the job is MEMACC_MEM_FAILED.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        HwId                  Unique numeric memory driver identifier.
 * @param[in]        HwServiceId           Array index pointing to the hardware specific service function pointer.
 *
 * @param[inout]     DataPtr               Data pointer pointing to the job buffer. Value can be NULL_PTR, if not needed.
 *                                         If dataPtr is used by the hardware specific service, the pointer must be valid until the job completed.
 * @param[inout]     LengthPtr             Size pointer of the data passed by dataPtr. Can be NULL_PTR if dataPtr is also NULL_PTR.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_HwSpecificService (MemAcc_AddressAreaIdType     AddressAreaId,
                                         MemAcc_HwIdType              HwId,
                                         MemAcc_MemHwServiceIdType    HwServiceId,
                                         MemAcc_DataType             *DataPtr,
                                         MemAcc_LengthType           *LengthPtr
                                        );


/**
 * @brief            Request lock of an address area for exclusive access.
 *
 * @details          Request lock of an address area for exclusive access.
 *                   Once the lock is granted, the referenced lock notification function is called by MemAcc.
 *
 * @param[in]        AddressAreaId           Numeric identifier of address area.
 * @param[in]        Address                 Logical start address of the address area to identify the Mem driver to be locked.
 * @param[in]        Length                  Length of the address area to identify the Mem driver to be locked.
 * @param[in]        LockNotificationFctPtr  Pointer to address area lock notification callback function.
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module. The address area is locked/locking or validation fail.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_RequestLock (MemAcc_AddressAreaIdType            AddressAreaId,
                                   MemAcc_AddressType                  Address,
                                   MemAcc_LengthType                   Length,
                                   MemAcc_ApplicationLockNotification  LockNotificationFctPtr
                                  );


/**
 * @brief            Release access lock of provided address area.
 *
 * @details          Release access lock of provided address area.
 *
 * @param[in]        AddressAreaId           Numeric identifier of address area.
 * @param[in]        Address                 Logical start address to identify lock area.
 * @param[in]        Length                  Length to identify lock area.
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 */
Std_ReturnType MemAcc_ReleaseLock (MemAcc_AddressAreaIdType    AddressAreaId,
                                   MemAcc_AddressType          Address,
                                   MemAcc_LengthType           Length
                                  );


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEMACC_H */
