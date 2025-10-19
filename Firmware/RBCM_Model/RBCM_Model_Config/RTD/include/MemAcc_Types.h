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

#ifndef MEMACC_TYPES_H
#define MEMACC_TYPES_H

/**
*   @file MemAcc_Types.h
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
#include "Std_Types.h"
#include "MemAcc_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_TYPES_VENDOR_ID                      43
#define MEMACC_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEMACC_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEMACC_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEMACC_TYPES_SW_MAJOR_VERSION               5
#define MEMACC_TYPES_SW_MINOR_VERSION               0
#define MEMACC_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((MEMACC_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEMACC_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of MemAcc_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if current file and MemAcc_CfgDefines.h file are of the same vendor */
#if (MEMACC_TYPES_VENDOR_ID != MEMACC_VENDOR_ID_CFG_DEFINES)
    #error "MemAcc_Types.h and MemAcc_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and MemAcc_CfgDefines.h file are of the same Autosar version */
#if ((MEMACC_TYPES_AR_RELEASE_MAJOR_VERSION    != MEMACC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (MEMACC_TYPES_AR_RELEASE_MINOR_VERSION    != MEMACC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (MEMACC_TYPES_AR_RELEASE_REVISION_VERSION != MEMACC_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of MemAcc_Types.h and MemAcc_CfgDefines.h are different"
#endif
/* Check if current file and MemAcc_CfgDefines.h file are of the same software version */
#if ((MEMACC_TYPES_SW_MAJOR_VERSION != MEMACC_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (MEMACC_TYPES_SW_MINOR_VERSION != MEMACC_SW_MINOR_VERSION_CFG_DEFINES) || \
     (MEMACC_TYPES_SW_PATCH_VERSION != MEMACC_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of MemAcc_Types.h and MemAcc_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Define the type with exactly the size of a pointer for working with pointers */
#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 MemAcc_UintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 MemAcc_UintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif


/* Burst settings */
#define MEMACC_BURST_ERASE                        (1U << 0U)
#define MEMACC_BURST_READ                         (1U << 1U)
#define MEMACC_BURST_WRITE                        (1U << 2U)


/* Job flags */
#define MEMACC_JOB_FLAG_NONE                       0x00U     /* Initial value                               */
#define MEMACC_JOB_FLAG_STARTED                    0x01U     /* Indicates that new job has been accepted    */
#define MEMACC_JOB_FLAG_BURST_MODE                 0x02U     /* Indicates that the job uses burts settings  */

#define MEMACC_MEMSERVICE_COMPARE_API_ID           0x11U     /* Hardware-specific service ID for Compare API */

#define MEMACC_MEMDRIVER_ABI_VERSION               0x01U     /*ABI version of the Mem driver binary, it should be 0001*/
#define MEMACC_MEMDRIVER_RELOCATABLE_BINARY        0x01U     /*The Mem driver binary is relocatable */
/*==================================================================================================
*                                             TYPEDEFS
==================================================================================================*/

/**
* @brief         MemAcc Address Area Id Type
* @details       Unique address area ID type
* @implements    MemAcc_AddressAreaIdType_typedef
*/
typedef uint16 MemAcc_AddressAreaIdType;


/**
* @brief         MemAcc Address Type
* @details       Logical memory address type (depends on based on MemAcc64BitSupport configuration 32 or 64 bit)
* @implements    MemAcc_AddressType_typedef
*/
typedef MEMACC_ADDRESSTYPE MemAcc_AddressType;


/**
* @brief         MemAcc Length Type
* @details       Job length type (depends on based on MemAcc64BitSupport configuration 32 or 64 bit)
* @implements    MemAcc_LengthType_typedef
*/
typedef MEMACC_LENGTHTYPE MemAcc_LengthType;


/**
* @brief          MemAcc Data Type
* @details        General data type
* @implements     MemAcc_DataType_typedef
*/
typedef uint8 MemAcc_DataType;

/*==================================================================================================
*                                             MEM RELATED TYPES
==================================================================================================*/

/**
* @brief         Memory driver configuration structure type
* @details       Memory driver configuration structure type
* @implements    MemAcc_MemConfigType_typedef
*/
typedef void MemAcc_MemConfigType;


/**
* @brief         MemAcc Mem Data Type
* @details       General data type
* @implements    MemAcc_MemDataType_typedef
*/
typedef uint8 MemAcc_MemDataType;


/**
* @brief         Memory driver instance ID type
* @details       Memory driver instance ID type
* @implements    MemAcc_MemInstanceIdType_typedef
*/
typedef uint32 MemAcc_MemInstanceIdType;


/**
* @brief         Physical memory device length type
* @details       Physical memory device length type
* @implements    MemAcc_MemLengthType_typedef
*/
typedef MemAcc_LengthType MemAcc_MemLengthType;


/**
* @brief         Physical memory device address type
* @details       Derived from MemAcc_AddressType
* @implements    MemAcc_MemAddressType_typedef
*/
typedef MemAcc_AddressType MemAcc_MemAddressType;


/**
* @brief         Index type for Mem driver hardware specific service table
* @details       Index type for Mem driver hardware specific service table
* @implements    MemAcc_MemHwServiceIdType_typedef
*/
typedef uint32 MemAcc_MemHwServiceIdType;


/**
* @brief          MemAcc mem job result type
* @implements     MemAcc_MemJobResultType_enum
*/
typedef enum
{
    MEM_JOB_OK                 = 0x00,    /**< @brief The last job has been finished successfully                                    */
    MEM_JOB_PENDING            = 0x01,    /**< @brief A job is currently being processed                                             */
    MEM_JOB_FAILED             = 0x02,    /**< @brief Job failed for some unspecific reason                                          */
    MEM_INCONSISTENT           = 0x03,    /**< @brief The checked page is not blank                                                  */
    MEM_ECC_UNCORRECTED        = 0x04,    /**< @brief Uncorrectable ECC errors occurred during memory access                         */
    MEM_ECC_CORRECTED          = 0x05     /**< @brief Correctable ECC errors occurred during memory access                           */
} MemAcc_MemJobResultType;


/**
* @brief         MemAcc_MemInvocationType
* @details       Defines how the Mem driver services are accessed and how the Mem driver is scheduled and activated/initialized.
*
*/
typedef enum
{
    /**
    * Mem driver is linked with application.
    * Mem service functions are directly called by MemAcc.
    * Mem_Init is called by EcuM and Mem_MainFunction is triggered by SchM.
    */
    MEMACC_MEM_DIRECT_STATIC    = 0x00,

    /**
    * Mem driver is linked as a separate binary and is dynamically activated.
    * MemAcc will use Mem driver header table to invoke Mem service functions.
    * Call of Mem_Init and Mem_MainFunction is handled by MemAcc.
    */
    MEMACC_MEM_INDIRECT_DYNAMIC = 0x01,

    /**
    * Mem driver is linked with application.
    * MemAcc will use Mem driver header table to invoke Mem service functions.
    * Call of Mem_Init and Mem_MainFunction is handled by MemAcc.
    */
    MEMACC_MEM_INDIRECT_STATIC  = 0x02
} MemAcc_MemInvocationType;


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief          Asynchronous job result type
* @implements     MemAcc_JobResultType_enum
*/
typedef enum
{
    MEMACC_MEM_OK               = 0x00,    /**< @brief The last MemAcc job was finished successfully                                                    */
    MEMACC_MEM_FAILED           = 0x01,    /**< @brief The last MemAcc job resulted in an unspecific failure and the job was not completed              */
    MEMACC_MEM_INCONSISTENT     = 0x02,    /**< @brief The last MemAcc job didn't meet the expected result, e.g. a blank check operation                */
    MEMACC_MEM_CANCELED         = 0x03,    /**< @brief The last MemAcc job was canceled                                                                 */
    MEMACC_MEM_ECC_UNCORRECTED  = 0x04,    /**< @brief The last memory operation returned an uncorrectable ECC error                                    */
    MEMACC_MEM_ECC_CORRECTED    = 0x05     /**< @brief The last memory operation returned a correctable ECC error                                       */
} MemAcc_JobResultType;

/**
* @brief          Lock address area status type
*/
typedef enum
{
    MEMACC_UNLOCK             = 0x00,      /**< @brief The address area is unlock                                                                       */
    MEMACC_LOCKING            = 0x01,      /**< @brief The address area is locking                                                                      */
    MEMACC_LOCKED             = 0x02       /**< @brief The address area is locked                                                                       */
} MemAcc_LockStatusType;

/**
* @brief          Asynchronous job status type
* @implements     MemAcc_JobStatusType_enum
*/
typedef enum
{
    MEMACC_JOB_IDLE             = 0x00,    /**< @brief Job processing was completed or no job currently pending                                         */
    MEMACC_JOB_PENDING          = 0x01     /**< @brief A job is currently being processed                                                               */
} MemAcc_JobStatusType;

/**
* @brief          Type for asynchronous jobs
* @implements     MemAcc_JobType_enum
*/
typedef enum
{
    MEMACC_NO_JOB               = 0x00,    /**< @brief No job currently pending          */
    MEMACC_WRITE_JOB            = 0x01,    /**< @brief Write job pending                 */
    MEMACC_READ_JOB             = 0x02,    /**< @brief Read job pending                  */
    MEMACC_COMPARE_JOB          = 0x03,    /**< @brief Compare job pending               */
    MEMACC_ERASE_JOB            = 0x04,    /**< @brief Erase job pending                 */
    MEMACC_MEMHWSPECIFIC_JOB    = 0x05,    /**< @brief Hardware specific job pending     */
    MEMACC_BLANKCHECK_JOB       = 0x06,    /**< @brief Blank check job pending           */
    MEMACC_REQUESTLOCK_JOB      = 0x07     /**< @brief Request lock job pending          */
} MemAcc_JobType;


/**
* @brief          Internal asynchronous job state transition
*                 MemAcc_JobStateType_enum
*/
typedef enum
{
    MEMACC_JOB_STATE_STARTING    = 0x00,   /**< @brief The job is pending to be processed             */
    MEMACC_JOB_STATE_PROCESSING  = 0x01,   /**< @brief The job is being processed                     */
    MEMACC_JOB_STATE_RETRYING    = 0x02,   /**< @brief The job is attempting a retry after a failure  */
    MEMACC_JOB_STATE_SUSPENDING  = 0x03,   /**< @brief The job is being suspended                     */
    MEMACC_JOB_STATE_RESUMING    = 0x04,   /**< @brief The job is being resumed                       */
    MEMACC_JOB_STATE_CANCELING   = 0x05,   /**< @brief The job is being canceled                      */
    MEMACC_JOB_STATE_STOP        = 0x06    /**< @brief The job is stop                                */
} MemAcc_JobStateType;

#if (MEMACC_MULTICORE_TYPE_1_ENABLED == STD_ON)
/**
* @brief          MemAcc Multi Core Request Return Type.
* @details        The return value for the function requesting multi core access.
*
*/
typedef enum
{
    MEMACC_MCORE_ERROR = 0, /**< @brief return error */
    MEMACC_MCORE_TIMEOUT,   /**< @brief return timeout */
    MEMACC_MCORE_PENDING,   /**< @brief return pending */
    MEMACC_MCORE_GRANTED,   /**< @brief return granted */
    MEMACC_MCORE_CANCELLED  /**< @brief return cancelled */
} MemAcc_MCoreReqReturnType;

/**
* @brief          MemAcc Multi Core hardware job status
* @details        The status of a multi core core flash job, in hardware. Used to determine
*                 if a flash job subject to multi core arbitration was started/suspended/aborted
*                 in hardware, in the flash controller. This can be used for example, to
*                 clear a semaphore granted for erase directly, if the job was not actually started
*                 in hardware, instead of attempting to suspend it.
*
*/
typedef enum
{
    MEMACC_MCORE_HW_JOB_IDLE = 0,       /**< @brief idle status */
    MEMACC_MCORE_HW_JOB_MAINF_STARTED,  /**< @brief mainf started status */
    MEMACC_MCORE_HW_JOB_STARTED,        /**< @brief started status */
    MEMACC_MCORE_HW_JOB_CANCELLED       /**< @brief cancelled status */
} MemAcc_MCoreHwJobStatusType;

/**
* @brief          MemAcc Multi Core timeout notification jobs
* @details        The timeout notification specifies the job during which timeout occurred.
*
*/
typedef enum
{
    MEMACC_MCORE_TIMEOUT_ERASE = 0,       /**< @brief timeout job erase */
    MEMACC_MCORE_TIMEOUT_WRITE,           /**< @brief timeout job write */
    MEMACC_MCORE_TIMEOUT_READ,            /**< @brief timeout job read */
    MEMACC_MCORE_TIMEOUT_COMPARE,         /**< @brief timeout job compare */
    MEMACC_MCORE_TIMEOUT_BLANK_CHECK      /**< @brief timeout job blank check */
} MemAcc_MCoreTimeoutJobType;
#endif /* MEMACC_MULTICORE_TYPE_1_ENABLED == STD_ON */

/**
* @brief         MemAcc Hardware Id Type
* @details       The name of each enum parameter is constructed from the Mem module name and the Mem instance name.
*                Type for the unique numeric identifiers of all Mem hardware instances used for hardware specific requests.
*
* @implements    MemAcc_HwIdType_typedef
*/
typedef uint32 MemAcc_HwIdType;


/*==================================================================================================
*                                            FUNCTION POINTER PROTOTYPE
==================================================================================================*/

/**
 * @brief    Function pointer for the Mem_Init service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemInitFuncType_functionPointer
*/
typedef void (*MemAcc_MemInitFuncType)
(
    MemAcc_MemConfigType    *ConfigPtr
);


/**
 * @brief    Function pointer for the Mem_DeInit service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemDeInitFuncType_functionPointer
*/
typedef void (*MemAcc_MemDeInitFuncType)(void);


/**
 * @brief    Function pointer for the Mem_JobResultType service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemGetJobResultFuncType_functionPointer
*/
typedef MemAcc_MemJobResultType (*MemAcc_MemGetJobResultFuncType)
(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_Suspend service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemSuspendFuncType_functionPointer
*/
typedef void (*MemAcc_MemSuspendFuncType)(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_Resume service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemResumeFuncType_functionPointer
*/
typedef void (*MemAcc_MemResumeFuncType)
(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_PropagateError service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemPropagateErrorFuncType_functionPointer
*/
typedef void (*MemAcc_MemPropagateErrorFuncType)
(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_Read service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemReadFuncType_functionPointer
*/
typedef Std_ReturnType (*MemAcc_MemReadFuncType)
(
    MemAcc_MemInstanceIdType    InstanceId,
    MemAcc_MemAddressType       SourceAddress,
    MemAcc_MemDataType         *DestinationDataPtr,
    MemAcc_MemLengthType        Length
);


/**
 * @brief    Function pointer for the Mem_Write service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemWriteFuncType_functionPointer
*/
typedef Std_ReturnType (*MemAcc_MemWriteFuncType)
(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemAddressType        TargetAddress,
    const  MemAcc_MemDataType   *SourceDataPtr,
    MemAcc_MemLengthType         Length
);


/**
 * @brief    Function pointer for the Mem_Erase service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemEraseFuncType_functionPointer
*/
typedef Std_ReturnType (*MemAcc_MemEraseFuncType)
(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemAddressType        TargetAddress,
    MemAcc_MemLengthType         Length
);


/**
 * @brief    Function pointer for the Mem_BlankCheck service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemBlankCheckFuncType_functionPointer
*/
typedef Std_ReturnType (*MemAcc_MemBlankCheckFuncType)
(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemAddressType        TargetAddress,
    MemAcc_MemLengthType         Length
);


/**
 * @brief    Function pointer for the Mem_HwSpecificService service for the invocation of the Mem driver API via function pointer interface.
 * @implements     MemAcc_MemHwSpecificServiceFuncType_functionPointer
*/
typedef Std_ReturnType (*MemAcc_MemHwSpecificServiceFuncType)
(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemHwServiceIdType    HwServiceId,
    MemAcc_MemDataType          *DataPtr,
    MemAcc_MemLengthType        *LengthPtr
);


/**
 * @brief    Function pointer for the Mem_MainFunction service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemMainFuncType)(void);


/*==================================================================================================
*                                           NOTIFICATION PROTOTYPE
==================================================================================================*/
/**
* @brief          MemAcc application job end notification callback.The function name is configurable
*
* @implements     MemAcc_AddressAreaJobEndNotification_functionPointer
*/
typedef void (*MemAcc_AddressAreaJobEndNotification)
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_JobResultType        JobResult
);

/**
* @brief          Address area lock application callback. The function name is configurable.
*
* @implements     MemAcc_ApplicationLockNotification_functionPointer
*/
typedef void (*MemAcc_ApplicationLockNotification)(void);

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          MemAcc memory infomation type
* @details        This structure contains information of Mem device characteristics.
*                 It can be accessed via the MemAcc_GetMemoryInfo() service.
* @implements     MemAcc_MemoryInfoType_struct
*/
typedef struct
{
    MemAcc_AddressType    LogicalStartAddress;     /**< @brief Logical start address of sub address area                                          */
    MemAcc_AddressType    PhysicalStartAddress;    /**< @brief Physical start address of sub address area                                         */
    MemAcc_LengthType     MaxOffset;               /**< @brief Size of sub address area in bytes -1                                               */
    uint32                EraseSectorSize;         /**< @brief Size of a sector in bytes                                                          */
    uint32                EraseSectorBurstSize;    /**< @brief Size of a sector burst in bytes. Equals SectorSize in case burst is disabled       */
    uint32                ReadPageSize;            /**< @brief Read size of a page in bytes                                                       */
    uint32                WritePageSize;           /**< @brief Write size of a page in bytes                                                      */
    uint32                ReadPageBurstSize;       /**< @brief Size of a read page burst in bytes. Equals ReadPageSize in case burst is disabled  */
    uint32                WritePageBurstSize;      /**< @brief Size of a page burst in bytes. Equals WritePageSize in case burst is disabled      */
    MemAcc_HwIdType       HwId;                    /**< @brief Referenced memory driver hardware identifier                                       */
} MemAcc_MemoryInfoType;


/**
* @brief          MemAcc job infomation type
* @details        This structure contains information the current processing state of the MemAcc module.
* @implements     MemAcc_JobInfoType_struct
*/
typedef struct
{
    MemAcc_AddressType      LogicalAddress;    /**< @brief Address of currently active address area request             */
    MemAcc_LengthType       Length;            /**< @brief Length of the currently active address area request          */
    MemAcc_HwIdType         HwId;              /**< @brief Referenced memory driver hardware identifier                 */
    uint32                  MemInstanceId;     /**< @brief Instance ID of the current memory request                    */
    uint32                  MemAddress;        /**< @brief Physical address of the current memory driver request        */
    uint32                  MemLength;         /**< @brief Length of memory driver request                              */
    MemAcc_JobType          CurrentJob;        /**< @brief Currently active MemAcc job                                  */
    MemAcc_JobResultType    MemResult;         /**< @brief Current or last Mem driver result                            */
} MemAcc_JobInfoType;


/**
* @brief          MemAcc_MemApiType
* @details        This structure contains elements for accessing the Mem driver service functions and consistency information.
* @implements     MemAcc_MemApiType_struct
*/
typedef struct
{
    uint64                                 UniqueId;                 /**< @brief Unique ID                                     */
    uint64                                 Flags;                    /**< @brief Header flags                                  */
    MemAcc_AddressType                     Header;                   /**< @brief Address of Mem driver header structure        */
    MemAcc_AddressType                     Delimiter;                /**< @brief Address of Mem driver delimiter field         */
    MemAcc_MemInitFuncType                 InitFunc;                 /**< @brief Mem_Init function pointer                     */
    MemAcc_MemDeInitFuncType               DeInitFunc;               /**< @brief Mem_Init function pointer                     */
    MemAcc_MemMainFuncType                 MainFunc;                 /**< @brief Mem_Main function pointer                     */
    MemAcc_MemGetJobResultFuncType         GetJobResultFunc;         /**< @brief Mem_GetJobResult function pointer             */
    MemAcc_MemReadFuncType                 ReadFunc;                 /**< @brief Mem_Read function pointer                     */
    MemAcc_MemWriteFuncType                WriteFunc;                /**< @brief Mem_Write function pointer                    */
    MemAcc_MemEraseFuncType                EraseFunc;                /**< @brief Mem_Erase function pointer                    */
    MemAcc_MemBlankCheckFuncType           BlankCheckFunc;           /**< @brief Mem_BlankCheck function pointer               */
    MemAcc_MemPropagateErrorFuncType       PropagateErrorFunc;       /**< @brief Mem_PropagateError function pointer           */
    MemAcc_MemSuspendFuncType              SuspendFunc;              /**< @brief Mem_Suspend function pointer                  */
    MemAcc_MemResumeFuncType               ResumeFunc;               /**< @brief Mem_Resume function pointer                   */
    MemAcc_MemHwSpecificServiceFuncType    HwSpecificServiceFunc;    /**< @brief Hardware specific service function pointer    */
} MemAcc_MemApiType;

/**
* @brief          MemAcc_SectorBatchInfoType
* @details        Data structure for a sector batch infomation.
*/
typedef struct
{
    const uint32                   SectorSize;         /**< @brief Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                   ReadPageSize;       /**< @brief Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                   WritePageSize;      /**< @brief Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                   EraseBurstSize;     /**< @brief Size of sector erase burst in bytes (for improved performance)          */
    const uint32                   ReadBurstSize;      /**< @brief Size of page read burst in bytes (for improved performance)             */
    const uint32                   WriteBurstSize;     /**< @brief Size of page write/program burst in bytes (for improved performance)    */
} MemAcc_SectorBatchInfoType;

/**
* @brief          MemAcc_SubAddressAreaType
* @details        Data structure for a sub address area
* @implements     MemAcc_SubAddressAreaType_struct
*/
typedef struct
{
    MemAcc_AddressType                  LogicalStartAddress;     /**< @brief Logical start address of sub address area                      */
    MemAcc_AddressType                  PhysicalStartAddress;    /**< @brief Physical start address of sub address area                     */
    MemAcc_LengthType                   Length;                  /**< @brief Size of sub address area in bytes                              */
    uint8                               NumOfEraseRetries;       /**< @brief The number of retries of a failed erase job                    */
    uint8                               NumOfWriteRetries;       /**< @brief The number of retries of a failed write job                    */
    uint8                               BurstSettings;           /**< @brief Burst settings of Erase/read/write operations                  */
    /* Mem related information */
    MemAcc_MemInvocationType            MemInvocation;           /**< @brief How the Mem driver is invocated                                */
    const MemAcc_MemApiType            *MemApi;                  /**< @brief Mem driver service functions and consistency information       */
    MemAcc_MemInstanceIdType            MemInstanceId;           /**< @brief Instance ID of the current memory request                      */
    const MemAcc_SectorBatchInfoType    MemSectorBatchInfo;      /**< @brief Sector batch information                                       */
    uint8                               MemHwResource;           /**< @brief The hardware resource identifier value                         */
    uint8                               Hw_Id;                   /**< @brief Referenced memory driver hardware identifier                   */
} MemAcc_SubAddressAreaType;


/**
* @brief          MemAcc_AddressAreaType
* @details        This structure contains configured information for each memory address areas.
* @implements     MemAcc_AddressAreaType_struct
*/
typedef struct
{
    MemAcc_AddressAreaIdType                AreaId;             /**< @brief Unique numeric identifier of address area                              */
    MemAcc_LengthType                       Length;             /**< @brief Size of the whole address area in bytes                                */
    uint16                                  Priority;           /**< @brief The priority of an AddressArea compared to other AddressAreas          */
    uint8                                   BufferAlignment;    /**< @brief Buffer alignment value                                                 */
    MemAcc_AddressAreaJobEndNotification    JobEndNotif;        /**< @brief The notification function which is called after MemAcc job completion  */
    uint16                                  SubAreaCount;       /**< @brief Number of sub address areas in this memory address area                */
    const MemAcc_SubAddressAreaType        *SubAreas;           /**< @brief Point to first element in array of sub address areas configurations    */
} MemAcc_AddressAreaType;


/**
* @brief          MemAcc job runtime information type
* @details        This structure contains runtime information the current processing job of each address area.
* @implements     MemAcc_JobRuntimeInfoType_struct
*/
typedef struct
{
    /* Input information */
    MemAcc_AddressAreaIdType            AreaId;              /**< @brief Requested address area id                                                    */
    MemAcc_JobType                      JobType;             /**< @brief Type of currently executed job (Erase, Write, or Read,...)                   */
    MemAcc_AddressType                  LogicAddress;        /**< @brief Last logical address to be processed                                         */
    MemAcc_AddressType                  PhysicAddress;       /**< @brief Last physical address to be processed                                        */
    MemAcc_LengthType                   LengthOrigin;        /**< @brief Requested bytes of data to be processed                                      */
    MemAcc_DataType                    *DataPtr;             /**< @brief Pointer to user data buffer (used in Read, Write, Compare)                   */
    MemAcc_LengthType                  *LengthPtr;           /**< @brief Size pointer of the data passed by dataPtr (used in HwSpecificService only)  */
    MemAcc_MemHwServiceIdType           MemHwServiceId;      /**< @brief Hardware specific service request identifier for dispatching the request     */
    /* Output result of the parameter checking stage */
    uint16                              AreaIndex;           /**< @brief The index of address area being processed                                    */
    const MemAcc_SubAddressAreaType    *SubArea;             /**< @brief The start sub address area of the requested job                              */
    /* Runtime information */
    MemAcc_LengthType                   LengthRemain;        /**< @brief Remaining bytes of data to be processed                                      */
    MemAcc_LengthType                   LengthChunk;         /**< @brief The amount of data in bytes to be processed each chunk                       */
    MemAcc_JobStateType                 JobState;            /**< @brief The internal transition state                                                */
    MemAcc_JobResultType                JobResult;           /**< @brief The result of the most recent job                                            */
    MemAcc_JobStatusType                JobStatus;           /**< @brief The asynchronous job status                                                  */
    uint8                               JobRetries;          /**< @brief The number of retries of a failed erase or write job                         */
    MemAcc_LockStatusType               LockStatus;          /**< @brief The lock status of the address area                                          */
    boolean                             JobLocked;           /**< @brief The requested job is locked or not                                           */
    MemAcc_AddressType                  LockAddress;         /**< @brief The start address of locked area                                             */
    MemAcc_LengthType                   LockLength;          /**< @brief The length of locked area                                                    */
    MemAcc_ApplicationLockNotification  LockNotif;           /**< @brief The callback function is called when the lock is complete                    */
} MemAcc_JobRuntimeInfoType;


/**
* @brief          MemAcc Configuration type
* @details        Postbuild configuration structure type
* @implements     MemAcc_ConfigType_struct
*/
typedef struct
{
    const uint32                    AddressAreaCount;    /**< @brief Number of address areas are configured in this configuration set   */
    const MemAcc_AddressAreaType   *AddressAreas;        /**< @brief Point to first element in array of address areas configurations    */
    MemAcc_JobRuntimeInfoType      *JobRuntimeInfo;      /**< @brief Point to first element in array of job runtime infomation          */
    const uint32                    MemApiCount;         /**< @brief Number of Mem drivers are used by MemAcc in this configuration set */
    MemAcc_MemApiType              *MemApis;             /**< @brief Mem driver service functions and consistency information           */
#if (MEMACC_MULTICORE_TYPE_3_ENABLED == STD_ON)
    const uint8                    *PartitionList;       /**< @brief Pointer to used partitions                                         */
    const uint32                   *PartitionMapping;    /**< @brief Pointer to AddressArea partition mapping                           */
#endif
    const MemAcc_MemInvocationType *MemApisInvocation;   /**< @brief How the Mem drivers is invocated                                   */
} MemAcc_ConfigType;

/**
* @brief          MemAcc Mem Driver UniqueID Type
* @details        Mem Driver binary UniqueID structure type
*/
typedef struct
{
    uint16 ABIVersion;
    uint16 VendorID;
    uint32 DriverID;
} MemAcc_MemDriverUniqueIDType;

/**
* @brief          MemAcc Mem Driver Flags Type
* @details        Mem Driver binary Flags structure type
*/
typedef struct
{
    uint32 RelocatableBinary;
    uint32 VendorSpecific;
} MemAcc_MemDriverFlagsType;

/**
* @brief          MemAcc Mem Driver Header Type
* @details        Mem Driver binary Header structure type
*/
typedef struct
{
    MemAcc_MemDriverUniqueIDType      UniqueID;
    MemAcc_MemDriverFlagsType         Flags;
    MemAcc_AddressType                HeaderAddress;
    MemAcc_AddressType                DelimiterAddress;
} MemAcc_MemDriverHeaderType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEMACC_TYPES_H */
