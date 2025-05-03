/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
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
*   @file    Spi.c
*   @implements Spi.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Implements the AUTOSAR SPI driver functionality.
*   @details Implements the AUTOSAR SPI driver. All the API functions are described by AUTOSAR
*
*   @addtogroup SPI_DRIVER Spi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_Ipw.h"
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
#include "Det.h"
#include "SchM_Spi.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_C                     43
#define SPI_AR_RELEASE_MAJOR_VERSION_C      4
#define SPI_AR_RELEASE_MINOR_VERSION_C      7
#define SPI_AR_RELEASE_REVISION_VERSION_C   0
#define SPI_SW_MAJOR_VERSION_C              5
#define SPI_SW_MINOR_VERSION_C              0
#define SPI_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if this file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_VENDOR_ID)
    #error "Spi.c and Spi.h have different vendor ids"
#endif
/* Check if current file and Spi header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.c and Spi.h are different"
#endif
  /* Check if current file and Spi header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.c and Spi.h are different"
#endif

/* Check if this header file and Spi_IPW_Types.h are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi.c and Spi_Ipw.h have different vendor ids"
#endif
/* Check if current file and Spi_Ipw header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.c and Spi_Ipw.h are different"
#endif
  /* Check if current file and Spi_Ipw header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.c and Spi_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det.h header file are of the same Software version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi.h and Det.h are different"
    #endif

    #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
      /* Check if the current file and Dem.h header file are of the same version */
      #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (SPI_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Spi.c and Dem.h are different"
      #endif
    #endif

    /* Check if the current file and SchM_Spi.h header file are of the same version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Spi.c and SchM_Spi.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/**
* @brief   Internal structure used to manage the sequence state.
*/
typedef struct
{
    /** @brief Sequence Result. */
    Spi_SeqResultType Result;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    /** @brief Pointer to the configuration. */
    const Spi_SequenceConfigType *Sequence;
    /** @brief Position in JobIndexList to the job in transmission of an async sequence. */
    const Spi_JobType *CurrentJobIndexPointer;
    /** @brief Number of jobs in a pending async sequence, not yet transmitted. */
    Spi_JobType RemainingJobs;
#endif
} Spi_SequenceStateType;

/**
* @brief   Internal structure used to manage the job state.
*
*/
typedef struct
{
    /** @brief Job Result. */
    Spi_JobResultType Result;

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    /** @brief Pointer to the state information of the async sequence. */
    Spi_SequenceStateType *AsyncCrtSequenceState;
    /** @brief Pointer to the next async job planned for transmission. */
    Spi_JobType AsyncNextJob;
#endif
} Spi_JobStateType;

/**
* @brief   Internal structure used to manage the channel state.
*
*/
typedef struct
{
    uint8 Flags;                 /**< @brief Default Transmit Enabled. */
    Spi_NumberOfDataType Length; /**< @brief Actual Transfer size for EB. */
} Spi_ChannelStateType;


/**
* @brief   Internal structure used to manage the channel state.
*
*/
typedef struct
{
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL1))
    Spi_AsyncModeType AsyncMode;    /**< @brief Async mode used by HW Unit */
    boolean AsyncModeDirty;         /**< @brief Set when async mode needs to be updated */
#endif
    boolean SyncInProgress;         /**< @brief Sync Transmit is in progress */
} Spi_HWStateType;

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief  Values used to denote NULL indexes.
*/
#define SPI_JOB_NULL            ((Spi_JobType)(-1))
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

#define SPI_RET_OK        ((Std_ReturnType)E_OK)
#define SPI_RET_NOT_OK    ((Std_ReturnType)E_NOT_OK)

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

static const Spi_ConfigType *Spi_apxSpiConfigPtr[SPI_MAX_PARTITIONS];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

/**
* @brief Spi State.
*/
static Spi_SequenceStateType Spi_axSpiSequenceState[SPI_MAX_SEQUENCE];
/**
* @brief Array of HW units queues.
*/
static Spi_HWUnitQueue Spi_axSpiHwUnitQueueArray[SPI_MAX_HWUNIT];

static Spi_JobStateType Spi_axSpiJobState[SPI_MAX_JOB];

static Spi_ChannelStateType Spi_axSpiChannelState[SPI_MAX_CHANNEL];

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static Spi_HWStateType Spi_axHwUnitState[SPI_MAX_HWUNIT];
#endif

#if (SPI_MAX_HWUNIT > 32u)
    #error "Too many HW Units in configuration (max 32 units allowed)"
#endif

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#define   SPI_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Spi_MemMap.h"

/**
* @note Array of used HW units per sequence:
*         The element corresponding to a given sequence will have asserted the bits
*         corresponding to the used HW units.
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
static uint32 Spi_au32SpiSeqUsedHWUnits[SPI_MAX_SEQUENCE];
#endif

/**
* @brief Spi Sync Transmit Running HWUnits Status.
*/
static volatile uint32 Spi_au32SpiBusySyncHWUnitsStatus[SPI_MAX_HWUNIT];

#define   SPI_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Spi_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static inline void Spi_ScheduleJob(Spi_HWUnitQueue* HWUnitQueue,
                                   Spi_JobType Job,
                                   const Spi_JobConfigType *JobConfig);

#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))

static void Spi_AsyncTransmitCallback(Spi_HWUnitType HwUnit,
                                      Spi_JobResultType JobResult);

static Std_ReturnType Spi_LockJobs(Spi_SequenceStateType *SequenceState,
                                   const Spi_SequenceConfigType *Sequence);

static inline void Spi_UnlockRemainingJobs(Spi_JobType RemainingJobs,
                                           const Spi_SequenceConfigType *Sequence);

static void Spi_ScheduleNextJob(Spi_HWUnitQueue *HWUnitQueue,
                                uint32 SpiUserID);

#endif /* if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */
static inline Std_ReturnType Spi_CheckInit(const Spi_ConfigType *ConfigPtr,
                                           uint32 SpiUserID);

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_SynctransmitCheckJobsIsValid(const Spi_SequenceConfigType *SequenceConfig,
                                                       uint32 SpiUserID);
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2)) */
#endif /* #if (SPI_DEV_ERROR_DETECT == STD_ON)*/

static Std_ReturnType Spi_SyncJobsTranfer(const Spi_SequenceConfigType *SequenceConfig,
                                          uint32 SpiUserID);

#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))*/

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
static Spi_NumberOfDataType Spi_SetupEbGetLength(const uint8 FrameSize,
                                                 const Spi_NumberOfDataType Length);

#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_ChannelCheckValidity(const Spi_ChannelType Channel,
                                               const uint8 FunctionId);

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
static Std_ReturnType Spi_SetupEbCheckLength(const Spi_ChannelConfigType *ChannelConfig,
                                             Spi_NumberOfDataType Length);

#endif
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_AsyncTransmitCheckDemReport(uint32 SpiUserID,
                                                      Spi_SequenceType Sequence);

#endif
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
static Std_ReturnType Spi_AsyncTransmitCheckValidityOfChannels(uint32 SpiUserID,
                                                               const Spi_JobConfigType *JobConfig);

#endif
#endif
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_InitCheckDemError(uint32 SpiUserID,
                                            const Spi_ConfigType *ConfigPtr);

#endif

static void Spi_InitChannelsJobsSeqsState(uint32 SpiUserID);

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_InitJobsList(uint32 HWUnit);

static void Spi_JobTransferFinished(const Spi_JobConfigType *JobConfig,
                                    Spi_JobResultType JobResult,
                                    Spi_JobStateType *JobState);

#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_SyncTransmitCheckDemReport(uint32 SpiUserID,
                                                     Spi_SequenceType Sequence);

#endif
#endif

static Spi_StatusType Spi_GetStatusAsyncCheckHwBusy(uint32 SpiUserID);

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static Std_ReturnType Spi_LockJobsProcess(Spi_SequenceStateType *SequenceState,
                                          const Spi_SequenceConfigType *Sequence,
                                          Spi_JobType JobCount);

#endif

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static inline void Spi_DemReportStatus(uint32 SpiUserID,
                                       Dem_EventStatusType EventStatus);

#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    #if (((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON))
static Std_ReturnType Spi_HWUnitCheckValidity(const Spi_HWUnitType HWUnit,
                                              const uint8 FunctionId);

    #endif /* (((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON)) */
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    #if ( ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON))
/**
* @brief   This function check valid of HWUnit input
*
* @param[in]     HWUnit         The hardware Peripheral
* @param[in]     FunctionId     The Function Id to report error
* @param[out]    Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*/
static Std_ReturnType Spi_HWUnitCheckValidity(const Spi_HWUnitType HWUnit,
                                              const uint8 FunctionId)
{
    Std_ReturnType Status = (Std_ReturnType) E_NOT_OK;
    uint32 SpiUserID = Spi_GetUserID;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_UNINIT);

    }
    else if (HWUnit >= SPI_MAX_HWUNIT)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_UNIT);
    }
    /* Check partition has assigned for sequence */
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig)
    {
        /* Call Det_ReportError for wrong partition */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
    }
    else if (SpiUserID != Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiPartitionUse)
    {
        /* Call Det_ReportError for wrong partition */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
    }
    else
    {
        Status = (Std_ReturnType)E_OK;
    }

    return Status;
}
    #endif /* ( ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON)) */
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

/**
* @brief   This function report production error SPI_E_HARDWARE_ERROR to DEM.
*
* @param[in]     ReportStatus       Specifies the Event status
* @param[out]    void
*
*/
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static inline void Spi_DemReportStatus(uint32 SpiUserID,
                                       Dem_EventStatusType EventStatus)
{
    /* Call Dem_SetEventStatus. */
    if ((uint32)STD_ON == Spi_apxSpiConfigPtr[SpiUserID]->SpiErrorHardwareCfg.state)
    {
        (void)Dem_SetEventStatus((Dem_EventIdType)Spi_apxSpiConfigPtr[SpiUserID]->SpiErrorHardwareCfg.id, EventStatus);
    }
    else
    {
        /* Do nothing */
    }
}
#endif

/**
* @brief   This function checks parameters for initialization of SPI driver.
* @details This function checks parameters for initialization of SPI driver.
*
* @param[in]     ConfigPtr       Specifies the pointer to the configuration set
* @param[out]    CheckStatus      Specifies status of checking
*               - E_OK: The parameters are valid
*               - E_NOT_OK: The parameters are invalid
*
*/
static inline Std_ReturnType Spi_CheckInit(const Spi_ConfigType *ConfigPtr,
                                           uint32 SpiUserID)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;
#if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    uint32 Channel;
    uint32 Job;
    uint32 Sequence;
#endif

#if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    /* Configuration sizes must be checked for Post Build & Link Time configurations */
    Channel  = (uint32)(ConfigPtr->SpiMaxChannel);
    Job      = (uint32)(ConfigPtr->SpiMaxJob);
    Sequence = (uint32)(ConfigPtr->SpiMaxSequence);

    if ((Channel >= SPI_MAX_CHANNEL) || (Job >= SPI_MAX_JOB) || (Sequence >= SPI_MAX_SEQUENCE))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_CONFIG_OUT_OF_RANGE);
#endif
    }
    if (SpiUserID != ConfigPtr->SpiPartitionUse)
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_PARAM_CONFIG);
#endif
    }
#else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
    (void)ConfigPtr;
    if ( NULL_PTR == Spi_PBCfgVariantPredefined[SpiUserID] )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_INVALID_POINTER);
#endif
    }
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */

    return CheckStatus;
}

/**
* @brief   This function is called in order to mark the jobs of a sequence as ready to be transmitted.
* @details For each job in sequence, the function checks if it is already
*          linked to another pending sequence.
*          If at least one job is already linked, the function returns E_NOT_OK.
*          Elsewhere, all jobs in sequence are locked (linked to the current
*          sequence)
*
* @param[in]      Sequence        The sequence ID.
* @param[in]      Sequence       The sequence configuration.
*
* @return Std_ReturnType
* @retval E_OK       The given sequence does not share its jobs with some
*                    other sequences, and all its jobs were successfully
*                    locked.
* @retval E_NOT_OK  The given sequence shares its jobs with some other
*                   sequences. No lock performed for its jobs.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static Std_ReturnType Spi_LockJobs(Spi_SequenceStateType *SequenceState,
                                   const Spi_SequenceConfigType *Sequence)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType JobCount = Sequence->NumJobs;
    const Spi_JobType *Jobs = Sequence->JobIndexList;
    Spi_JobStateType *JobState;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03();
    /* Use an optimized implementation for one job sequences */
    if (1u == JobCount)
    {
        JobState = &Spi_axSpiJobState[*Jobs];
        if (NULL_PTR == JobState->AsyncCrtSequenceState)
        {
            /* Job not yet linked => link it to the current sequence */
            JobState->AsyncCrtSequenceState = SequenceState;
        }
        else
        {
            /* The job is already locked by a pending sequence */
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Status = Spi_LockJobsProcess(SequenceState, Sequence, JobCount);
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03();

    return Status;
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

/**
* @brief   This function is called to release the jobs at the end of an async sequence transmission.
* @details Mark the linked sequence for all jobs as NULL_PTR.
*
* @param[in]      RemainingJobs    The starting job
* @param[in]      Sequence        The sequence configuration
*
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON.
*
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static inline void Spi_UnlockRemainingJobs(Spi_JobType RemainingJobs,
                                           const Spi_SequenceConfigType *Sequence)
{
    Spi_JobType NumJobsInSeq = Sequence->NumJobs;
    Spi_JobType JobIdx;

    /* Mark the linked sequence for all jobs as NULL_PTR */
    for (JobIdx = NumJobsInSeq-RemainingJobs; JobIdx < NumJobsInSeq; JobIdx++)
    {
        MCAL_DATA_SYNC_BARRIER();
        Spi_axSpiJobState[Sequence->JobIndexList[JobIdx]].AsyncCrtSequenceState = NULL_PTR;
        MCAL_DATA_SYNC_BARRIER();
    }
}

#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) */

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
static void Spi_SequenceDmaFastTransfer(const Spi_SequenceConfigType *SequenceConfig,
                                        uint8 HWUnit,
                                        uint32 SpiUserID)
{
    uint8 TransferCount = 0u;
    const Spi_JobConfigType *JobConfig;
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_HWUnitConfigType *PhyUnitConfig;
    const Spi_Ipw_ExternalDeviceType *ExternalDeviceConfig;
    const Spi_ChannelStateType *ChannelState;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;
    Spi_JobType Job;
    boolean KeepCs;
    Spi_Ipw_ParamDMAFAst Param;

    PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
    /* Get the number of Jobs in the sequence */
    for (Job = 0u; Job < SequenceConfig->NumJobs; Job++)
    {
        /* Set the Job status as pending */
        Spi_axSpiJobState[SequenceConfig->JobIndexList[Job]].Result = SPI_JOB_PENDING;
        JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[SequenceConfig->JobIndexList[Job]].JobCfg;
        NumChannelsInJob = JobConfig->NumChannels;
        ExternalDeviceConfig = &JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig;
        for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
        {
            ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
            ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[ChannelID].ChannelCfg;
            ChannelState = &Spi_axSpiChannelState[ChannelID];
            KeepCs = ChannelIndex == (NumChannelsInJob - 1u);
            Param.Length = ChannelState->Length;
            Param.Flags = ChannelState->Flags;
            Param.KeepCs = KeepCs;
            Spi_Ipw_PrepareDMAFastTransferCfg(PhyUnitConfig, ChannelConfig,
                                              ExternalDeviceConfig, TransferCount, &Param);
            TransferCount++;
        }
    }

    Spi_axSpiHwUnitQueueArray[HWUnit].Channel = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[Spi_axSpiHwUnitQueueArray[HWUnit].Job].JobCfg->NumChannels - 1u;

    Spi_Ipw_DMAFastTransferStart(PhyUnitConfig, TransferCount);
}
#endif

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))

static Std_ReturnType Spi_SequenceDmaContMemTransfer(const Spi_SequenceConfigType *SequenceConfig,
                                                     Spi_HWUnitType HWUnit,
                                                     uint32 SpiUserID)
{
    Std_ReturnType Ret = E_OK;
    const Spi_JobConfigType *JobConfig;
    Spi_JobType Job;
    Spi_HWUnitQueue *HwQueue = &Spi_axSpiHwUnitQueueArray[HWUnit];
    uint16 ChannelIndex;
    Spi_ChannelType ChannelID;
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_Ipw_ExternalDeviceType *ExternalDeviceConfig;
    const Spi_Ipw_ExternalDeviceType *FirstExternalDeviceConfig = NULL_PTR;
    uint8 *FirstRxBufferAddr = NULL_PTR;
    uint8 TransferCount = 0u;
    Spi_Ipw_uintPtrType ComparedRxBufferAddr;
    Spi_Ipw_ParamDMACont Param;

    /* Sequence Prepare succeeded. Update HLD State*/
    Job = (Spi_JobType)0u;
    while ((Job < SequenceConfig->NumJobs) && (E_OK == Ret))
    {
        JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[SequenceConfig->JobIndexList[Job]].JobCfg;
        if (Job == 0u)
        {
            FirstExternalDeviceConfig = &JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig;
        }
        ChannelIndex = 0u;
        while (((Spi_ChannelType)ChannelIndex < JobConfig->NumChannels) && (E_OK == Ret))
        {
            ExternalDeviceConfig = &JobConfig->ExternalDeviceConfig->ExDeviceConfig->ExternalDeviceConfig;
            ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
            ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[ChannelID].ChannelCfg;
            Param.ChannelIndex = ChannelIndex;
            Param.ComparedRxBufferAddr = &ComparedRxBufferAddr;
            Param.ExternalDeviceConfig = ExternalDeviceConfig;
            Param.FirstExternalDeviceConfig = FirstExternalDeviceConfig;
            Param.FirstRxBufferAddr = &FirstRxBufferAddr;
            Param.IsFirstJob = (Job == (Spi_JobType)0u);
            Param.PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
            Param.SequenceConfig = SequenceConfig;
            Ret = Spi_Ipw_SequenceDmaContMemPrepare(
                ChannelConfig,
                JobConfig->NumChannels,
                (uint16)Spi_axSpiChannelState[ChannelID].Length,
                &TransferCount,
                &Param
            );
            ChannelIndex++;
        }
        Job++;
    }
    if ((Ret == E_OK) && (TransferCount > 0u))
    {
        /* Sequence Prepare succeeded. Update HLD State*/
        for (Job = (Spi_JobType)0u; Job < SequenceConfig->NumJobs; Job++)
        {
            /* Set the Job status as pending */
            Spi_axSpiJobState[SequenceConfig->JobIndexList[Job]].Result = SPI_JOB_PENDING;
        }
        HwQueue->Channel = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[HwQueue->Job].JobCfg->NumChannels - 1u;

        Ret = Spi_Ipw_SequenceDmaContMemTransfer(SequenceConfig, FirstExternalDeviceConfig,
                                                 FirstRxBufferAddr, TransferCount);
        if (E_OK != Ret)
        {
            /* Cleanup job status */
            for (Job = (Spi_JobType)0u; Job < SequenceConfig->NumJobs; Job++)
            {
                Spi_axSpiJobState[SequenceConfig->JobIndexList[Job]].Result = SPI_JOB_FAILED;
            }
        }
    }

    return Ret;
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Triggers first channel of the Job. */
static void Spi_JobTransfer(const Spi_JobConfigType *JobConfig, const Spi_JobStateType *JobState)
{
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_ChannelStateType *ChannelState;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    uint32 SpiUserID;
    Spi_Ipw_ParamAsyncTransmit Param;
    Spi_HWUnitType HWUnit;
    #if ((SPI_DMA_USED == STD_ON) && ((SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) || (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)))
    const Spi_SequenceConfigType *SequenceConfig = JobState->AsyncCrtSequenceState->Sequence;
    #else
    (void)JobState;
    #endif

    /* get user ID */
    SpiUserID = Spi_GetUserID;
    HWUnit = JobConfig->HWUnit;
    if ((boolean)TRUE == Spi_axHwUnitState[HWUnit].AsyncModeDirty)
    {
        Spi_axHwUnitState[HWUnit].AsyncModeDirty = FALSE;
        /* set the async mode & activate/deactivate the interrupts for the HW Unit */
        Spi_Ipw_IrqConfig(Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig,
                          Spi_axHwUnitState[HWUnit].AsyncMode,
                          &Spi_AsyncTransmitCallback);
    }

    /* Perform Job StartNotification (if there is one) */
    if (NULL_PTR != JobConfig->StartNotification)
    {
        JobConfig->StartNotification();
    }
    else
    {
        /* Do nothing */
    }

    #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    if (TRUE == SequenceConfig->EnableDmaFastTransfer)
    {
        Spi_SequenceDmaFastTransfer(SequenceConfig, HWUnit, SpiUserID);
    }
    else
    #endif
    {
        ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[JobConfig->ChannelIndexList[0u]].ChannelCfg;
        ChannelState = &Spi_axSpiChannelState[JobConfig->ChannelIndexList[0u]];
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if (0u != (ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            TxBuffer = NULL_PTR;
        }
        else
        {
            if (EB == ChannelConfig->BufferType)
            {
                TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
            }
        }

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
        if (TRUE == SequenceConfig->EnableDmaContMemTransfer)
        {
            (void)Spi_SequenceDmaContMemTransfer(SequenceConfig, HWUnit, SpiUserID);
        }
        else
#endif
        {
            Param.ChannelConfig = ChannelConfig;
            
            /* Check if this is the last channel */
            if (1U < JobConfig->NumChannels) 
            {
                Param.NextChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[JobConfig->ChannelIndexList[1u]].ChannelCfg;
            } 
            else 
            {
                Param.NextChannelConfig = NULL_PTR;
            }
            Param.FirstCmd = TRUE;
            Param.KeepCs = (1u != JobConfig->NumChannels);
            Spi_Ipw_AsyncTransfer(JobConfig->ExternalDeviceConfig->ExDeviceConfig,
                                TxBuffer,
                                RxBuffer,
                                ChannelState->Length,
                                &Param);
        }
    }
}

/**
* @brief   This function will schedule a job for a given HW unit.
* @details If the HWUnit is not busy, the transfer is started and the HW unit is
*          marked as busy.
*          If the HWUnit is not busy (another job is in progress), the new job is
*          scheduled in a waiting job list, according to its priority.
*
* @param[in]      HWUnitQueue     HW Unit to be used by the job
* @param[in]      Job             ID of the scheduled job
* @param[in]      JobConfig      Configuration of the scheduled job
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
static inline void Spi_ScheduleJob(Spi_HWUnitQueue *HWUnitQueue,
                                   Spi_JobType Job,
                                   const Spi_JobConfigType *JobConfig)
{
    sint8 Priority;
    Spi_JobType *JobListTail;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
    if (SPI_IDLE == HWUnitQueue->Status)
    {
        /* idle unit => the job can be started */
        HWUnitQueue->Status = SPI_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();

        /* mark the job as pending */
        Spi_axSpiJobState[Job].Result = SPI_JOB_PENDING;
        HWUnitQueue->Channel = 0;
        HWUnitQueue->Job = Job;
        Spi_JobTransfer(JobConfig, &Spi_axSpiJobState[Job]);
    }
    else
    {
        /* add the job to the scheduling corresponding queue */

        /* retrieve the tail of the scheduling queue for the job priority */
        Priority = JobConfig->Priority;

        if (Priority >= 0)
        {
            JobListTail = &HWUnitQueue->ScheduledJobsListTail[Priority];

            if (SPI_JOB_NULL == *JobListTail)
            {
                /* the list is empty => set also the head of the list */
                HWUnitQueue->ScheduledJobsListHead[Priority] = Job;
            }
            else
            {
                /* add the item at the end of the list */
                Spi_axSpiJobState[*JobListTail].AsyncNextJob = Job;
            }

            /* set the new tail of the list */
            *JobListTail = Job;

            /* the new item will be the last element in the list */
            Spi_axSpiJobState[Job].AsyncNextJob = SPI_JOB_NULL;

            if (HWUnitQueue->MaxScheduledPriority < Priority)
            {
                HWUnitQueue->MaxScheduledPriority = Priority;
            }
            else
            {
                /* Do nothing */
            }
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
        }
    }
}
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function will check validation of jobs in a sequence in Synchronous mode.
* @details This function will check validation of jobs in a sequence in Synchronous mode.
*
* @param[in]      SequenceConfig     The sequence configuration
* @param[in]      SpiUserID         ID of Partition
*
* @retval E_OK      No invalid configuration was found.
* @retval E_NOT_OK  The HWUnit which are assigning to the job is Async mode Or the buffer of channel is EB so Lenght is 0.
*
* @pre  This function will be called by Spi_Synctransmit()
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*/
static Std_ReturnType Spi_SynctransmitCheckJobsIsValid(const Spi_SequenceConfigType *SequenceConfig,
                                                       uint32 SpiUserID)
{
    Spi_JobType Job;
    Spi_JobType JobIndex;
    const Spi_JobConfigType *JobConfig;
    Spi_ChannelType ChannelID;
    Spi_ChannelType ChannelIndex;
    Std_ReturnType Status = (Std_ReturnType)E_OK;

    JobIndex = 0u;
    while ((JobIndex < SequenceConfig->NumJobs) && ((Std_ReturnType)E_OK == Status))
    {
        /* Get the job id */
        Job = SequenceConfig->JobIndexList[JobIndex];
        JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[Job].JobCfg;
        /* Check if all EBs have been setup */
        ChannelIndex = (Spi_ChannelType)0;
        while ((ChannelIndex < JobConfig->NumChannels) && ((Std_ReturnType)E_OK == Status))
        {
            ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
            if (EB == Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[ChannelID].ChannelCfg->BufferType)
            {
                /* Channel length is 0 for unconfigured ext. buffers */
                if (0U == Spi_axSpiChannelState[ChannelID].Length)
                {
                    /* An used EB not initialized  */
                    (void)Det_ReportError((uint16) SPI_MODULE_ID, (uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_EB_UNIT);
                    Status = (Std_ReturnType)E_NOT_OK;
                }
            }
            ChannelIndex++;
        }
        JobIndex++;
    }
    
    return Status;
}

#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2)) */
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/

static Std_ReturnType Spi_JobSyncTransmit(const Spi_JobConfigType *JobConfig,
                                          uint32 SpiUserID)
{
    const Spi_ChannelsCfgType *ChannelsConfig;
    const Spi_ChannelStateType *ChannelState;
    Std_ReturnType Ipw_Status = (Std_ReturnType)E_OK;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_ChannelConfigType *NextChannelConfig;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;
    Spi_Ipw_ParamSyncTransmit Param;

    ChannelsConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig;
    NumChannelsInJob = JobConfig->NumChannels;
    for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
        ChannelConfig = ChannelsConfig[ChannelID].ChannelCfg;
        ChannelState = &Spi_axSpiChannelState[ChannelID];
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if (0u != (ChannelState->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            TxBuffer = NULL_PTR;
        }
        else
        {
            if (EB == ChannelConfig->BufferType)
            {
                TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
            }
        }
        if (ChannelIndex < (NumChannelsInJob - 1u))
        {
            NextChannelConfig = ChannelsConfig[JobConfig->ChannelIndexList[ChannelIndex + 1u]].ChannelCfg;
        }
        else
        {
            NextChannelConfig = NULL_PTR;
        }

        Param.ChannelConfig = ChannelConfig;
        Param.NextChannelConfig = NextChannelConfig;
        Param.KeepCs = (ChannelIndex != (NumChannelsInJob - 1u));
        Param.FirstCmd = (ChannelIndex == 0u);
        Ipw_Status = Spi_Ipw_SyncTransmit(JobConfig->ExternalDeviceConfig->ExDeviceConfig,
                             TxBuffer,
                             RxBuffer,
                             ChannelState->Length,
                             &Param);
        if (Ipw_Status != E_OK)
        {
            break;
        }
    }

    return Ipw_Status;
}

/**
* @brief   This function transmit Jobs in a sequence by Synctransmit mode.
* @details This function transmit Jobs in a sequence by Synctransmit mode.
*
* @param[in]      SequenceConfig     The sequence configuration.
* @param[in]      SpiUserID         ID of Partition
* @return Std_ReturnType
* @retval E_OK      Transmission command has been completed successfully
* @retval E_NOT_OK  Transmission command has not been accepted
*
* @pre  This function will be called by Spi_Synctransmit()
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*
*/
static Std_ReturnType Spi_SyncJobsTranfer(const Spi_SequenceConfigType *SequenceConfig,
                                          uint32 SpiUserID)
{
    Spi_JobType Job;
    Spi_JobStateType *JobState;
    const Spi_JobConfigType *JobConfig;
    Std_ReturnType Status = (Std_ReturnType)E_OK;

    /* Get the number of jobs in the sequence */
    Job = 0u;
    while (Job < SequenceConfig->NumJobs)
    {
        /* Set the job status as pending */
        JobState = &Spi_axSpiJobState[SequenceConfig->JobIndexList[Job]];
        JobState->Result = SPI_JOB_PENDING;
        JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[SequenceConfig->JobIndexList[Job]].JobCfg;

        /* start job notification to assert the non-cs pin,
        when non-cs pin is used as chip select*/
        if (NULL_PTR != JobConfig->StartNotification)
        {
            JobConfig->StartNotification();
        }
        else
        {
            /* Do nothing */
        }
        /* Mark HWUnit as busy */
        Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit].Status = SPI_BUSY;
        Status = Spi_JobSyncTransmit(JobConfig, SpiUserID);

        /* release HWUnit */
        Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit].Status = SPI_IDLE;

        if ((Std_ReturnType)E_OK == Status)
        {
            /* Job is done set the status as OK */
            JobState->Result = SPI_JOB_OK;
            /* Perform job EndNotification (if there is one) */
            if (NULL_PTR != JobConfig->EndNotification)
            {
                JobConfig->EndNotification();
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* transmission failed */
            /* set the remaining job status (including the current one) as FAILED */
            do
            {
                /* Set the job status as FAILED */
                Spi_axSpiJobState[SequenceConfig->JobIndexList[Job]].Result = SPI_JOB_FAILED;
                /* Update pointer position for JobConfig */
                JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[SequenceConfig->JobIndexList[Job]].JobCfg;
                /* Perform job EndNotification (if there is one) */
                if (NULL_PTR != JobConfig->EndNotification)
                {
                    JobConfig->EndNotification();
                }
                else
                {
                    /* Do nothing */
                }
                Job++;
            } while (Job < SequenceConfig->NumJobs);
        }
        /* iterate to next job in sequence */
        Job++;
    }
    
    return Status;
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )*/

#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check valid for input Channel.
* @details This function check valid for input Channel.
*
* @param[in]      Channel              ID channel
* @param[in]      FunctionId           Function Id to report error
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/
static Std_ReturnType Spi_ChannelCheckValidity(const Spi_ChannelType Channel,
                                               const uint8 FunctionId)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint32 SpiUserID = Spi_GetUserID;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Channel ID - Valid channels range is from 0 to SpiMaxChannel*/
    else if (Channel > Spi_apxSpiConfigPtr[SpiUserID]->SpiMaxChannel)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CHANNEL);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Check partition has assigned for this channel */
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[Channel].ChannelCfg)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (SpiUserID != Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[Channel].ChannelCfg->SpiPartitionUse)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return Status;
}
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))

static Spi_NumberOfDataType Spi_SetupEbGetLength(const uint8 FrameSize,
                                                 const Spi_NumberOfDataType Length)
{
    Spi_NumberOfDataType RetLength;

#if SPI_USE_LEGACY_EB_LENGTH != STD_ON
    if (FrameSize > 8u)
    {
        if (FrameSize > 16u)
        {
            RetLength = Length * 4u;
        }
        else
        {
            RetLength = Length * 2u;
        }
    }
    else
#else
    /* Avoid compiler warning */
    (void)FrameSize;
#endif
    {
        RetLength = Length;
    }

    return RetLength;
}

#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check valid for input parameters Length and UserId.
* @details This function check valid for input parameters Length and UserId.
*
* @param[in]      SpiUserID         ID of Partition
* @param[in]      Channel              ID channel
* @param[in]      Length               Number of bytes
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/

/**
* @brief   Checks length validity based on Framesize
* @details 2 different checks depending on SPI_USE_LEGACY_EB_LENGTH
*              - STD_ON: Check if Length correspond to an exact number of frames
*              - STD_OFF: Check for overflow when converting number of data elements to bytes and
*                           that number of data elements correspond to an exact number of frames
* @param[in]      ChannelConfig      Channel configuration
* @param[in]      Length             Number of bytes or Number of data length (depending on SPI_USE_LEGACY_EB_LENGTH)
* @return none
*
*
*/
static Std_ReturnType Spi_SetupEbCheckLength(const Spi_ChannelConfigType *ChannelConfig,
                                             Spi_NumberOfDataType Length)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint16 BytesPerDataElement;
    uint16 BytesPerFrame;
#if SPI_USE_LEGACY_EB_LENGTH == STD_OFF
    uint16 DataElementsPerFrame;
#endif

    if (ChannelConfig->FrameSize > 16u)
    {
        BytesPerDataElement = 4u;
        BytesPerFrame = (uint16)ChannelConfig->FrameSize / 32u * BytesPerDataElement;
        if (0u != (ChannelConfig->FrameSize % 32u))
        {
            /* Access to data elements with FrameSize > 16 is done using uint32 */
            BytesPerFrame += BytesPerDataElement;
        }
    }
    else if (ChannelConfig->FrameSize > 8u)
    {
        BytesPerFrame = 2u;
        BytesPerDataElement = 2u;
    }
    else
    {
        BytesPerFrame = 1u;
        BytesPerDataElement = 1u;
    }

    if (ChannelConfig->FrameSize > 0u)
    {
#if SPI_USE_LEGACY_EB_LENGTH == STD_ON
        /* Check that an exact number of frames fits in Length */
        if (0u != (Spi_NumberOfDataType)(Length % BytesPerFrame))
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
#else
        (void)BytesPerFrame;
        DataElementsPerFrame = (uint16)ChannelConfig->FrameSize / 32u;
        if (0u != (ChannelConfig->FrameSize % 32u))
        {
            DataElementsPerFrame++;
        }

        /* Check:
         *  - Transforming number of element to bytes won't overflow
         *  - Exact number of frames fits in Length
         */
        if ((Length > (Spi_NumberOfDataType)(NUMBER_OF_DATA_TYPE_MAX / BytesPerDataElement))
            || (0u != (Length % DataElementsPerFrame)))
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
#endif /* SPI_USE_LEGACY_EB_LENGTH == STD_ON */
    }

    if ((Std_ReturnType)E_NOT_OK == Status)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_LENGTH);
    }

    return Status;
}
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check the initialization of driver and sequence ID is compatible.
* @details This function check the initialization of driver and sequence ID is compatible.
*
* @param[in]      SpiUserID      UserID
* @param[in]      Sequence          Sequence ID
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/
static Std_ReturnType Spi_AsyncTransmitCheckDemReport(uint32 SpiUserID,
                                                      Spi_SequenceType Sequence)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Sequence Valid Range */
    else if (Sequence > (Spi_apxSpiConfigPtr[SpiUserID]->SpiMaxSequence))
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_SEQ);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }
    
    return Status;
}
#endif /*((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))*/
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
/**
* @brief   Check channel with EB buffer.
* @details Check channel with EB buffer.
*
* @param[in]      SpiUserID      ID of Partition
* @param[in]      JobConfig       Job configuration
* @return Std_ReturnType
*
*
*/
static Std_ReturnType Spi_AsyncTransmitCheckValidityOfChannels(uint32 SpiUserID,
                                                               const Spi_JobConfigType *JobConfig)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;

    /* Check if all EBs have been setup */
    NumChannelsInJob = JobConfig->NumChannels;
    for(ChannelIndex=(Spi_ChannelType)0;ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
        if (EB == Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[ChannelID].ChannelCfg->BufferType)
        {
            /* Length is 0 for unconfigured ext. buffers */
            if (0U == Spi_axSpiChannelState[ChannelID].Length)
            {
                /* An used EB not initialized  */
                (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_EB_UNIT);
                Status = (Std_ReturnType)E_NOT_OK;
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    
    return Status;
}
#endif /* #if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2)) */
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */


#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   Check Dem report error in Init function.
* @details Check Dem report error in Init function.
*
* @param[in]      SpiUserID      ID of Partition
* @return Std_ReturnType
*
*
*/
static Std_ReturnType Spi_InitCheckDemError(uint32 SpiUserID,
                                            const Spi_ConfigType *ConfigPtr)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;

    if (NULL_PTR != Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_ALREADY_INITIALIZED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    else if (NULL_PTR == ConfigPtr)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_INIT_FAILED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
    else if (NULL_PTR != ConfigPtr)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_INIT_FAILED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #endif /*(SPI_PRECOMPILE_SUPPORT == STD_OFF)*/
    else
    {
        /* Do nothing */
    }
    
    return CheckStatus;
}
#endif

/**
* @brief   This function initiate channels, jobs, sequences state.
* @details This function initiate channels, jobs, sequences state.
*
* @param[in]      SpiUserID      ID of Partition
* @return None
*
*
*/
static void Spi_InitChannelsJobsSeqsState(uint32 SpiUserID)
{
    uint32 Channel;
    uint32 Job;
    uint32 Sequence;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    Spi_HWUnitType HWUnit;
#endif
#endif
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_JobConfigType *JobConfig;
    const Spi_SequenceConfigType *SequenceConfig;
    const Spi_ConfigType *PartitionConfig;

    PartitionConfig = Spi_apxSpiConfigPtr[SpiUserID];
    for (Channel = 0u; Channel <= (uint32)(PartitionConfig->SpiMaxChannel); Channel++)
    {
        ChannelConfig = PartitionConfig->ChannelConfig[Channel].ChannelCfg;
        /* Check which channel has assigned for current partition */
        if ((NULL_PTR != ChannelConfig) && (SpiUserID == ChannelConfig->SpiPartitionUse))
        {
            /* Check if configured buffers are External (EB) */
            if (EB == ChannelConfig->BufferType)
            {
                /* Initialize all buffers */
                ChannelConfig->BufferDescriptor->ExternalBufferTX = NULL_PTR;
                ChannelConfig->BufferDescriptor->BufferRX = NULL_PTR;

                /* Channel length is zero for unconfigured external buffers */
                Spi_axSpiChannelState[Channel].Length = (Spi_NumberOfDataType) 0;
            }
            else
            {
                /* Setup channel length according to configuration */
                Spi_axSpiChannelState[Channel].Length = ChannelConfig->Length;
            }
            Spi_axSpiChannelState[Channel].Flags = SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
        }
    }

    /* initialize job results */
    for (Job = 0u; Job <= (uint32)(PartitionConfig->SpiMaxJob); Job++)
    {
        JobConfig = PartitionConfig->JobConfig[Job].JobCfg;
        if ((NULL_PTR != JobConfig) && (SpiUserID == JobConfig->SpiPartitionUse))
        {
            Spi_axSpiJobState[Job].Result = SPI_JOB_OK;
        #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
            /* mark the job as unlocked / not linked to a pending async sequence */
            Spi_axSpiJobState[Job].AsyncCrtSequenceState = NULL_PTR;
        #endif
        }
    }

    for (Sequence = 0u; Sequence <= (uint32)(PartitionConfig->SpiMaxSequence); Sequence++)
    {
        SequenceConfig = PartitionConfig->SequenceConfig[Sequence].SeqConfig;
        if ((NULL_PTR != SequenceConfig) && (SpiUserID == SequenceConfig->SpiPartitionUse))
        {
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
            Spi_axSpiSequenceState[Sequence].Sequence = SequenceConfig;
            #endif

            /* initialize sequence results */
            Spi_axSpiSequenceState[Sequence].Result = SPI_SEQ_OK;

            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
            #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
            /* initialize the map of used HWUnits per sequence */
            Spi_au32SpiSeqUsedHWUnits[Sequence] = (uint32)0;

            for (Job = 0u; Job < SequenceConfig->NumJobs; Job++)
            {
                HWUnit = PartitionConfig->JobConfig[SequenceConfig->JobIndexList[Job]].JobCfg->HWUnit;

                Spi_au32SpiSeqUsedHWUnits[Sequence] |=
                    (uint32)((uint32)1 << (HWUnit));
            }
            #else /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
            /* SPI135: Spi_SyncTransmit() must fail if an other sync transmission
                    is ongoing.*/
            /* mark all HW units as used by the sync transmission, in order to
                force the mutual exclusion of Spi_SyncTransmit() calls */

            Spi_au32SpiSeqUsedHWUnits[Sequence] = 0xFFFFFFFFU;
            #endif /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
            #endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0)) */

        }
        else
        {
            /* Do nothing */
        }
    }
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   This function initiate the jobs list.
* @details This function initiate the jobs list.
*
* @param[in]      HWUnit      The HW peripheral
* @return None
*
*
*/
static void Spi_InitJobsList(uint32 HWUnit)
{
    sint8 Priority;

    /* initialize the Job lists => no scheduled job for the unit */
    for (Priority = 0; Priority < SPI_JOB_PRIORITY_LEVELS_COUNT; Priority++)
    {
        Spi_axSpiHwUnitQueueArray[HWUnit].ScheduledJobsListHead[Priority] = SPI_JOB_NULL;
        Spi_axSpiHwUnitQueueArray[HWUnit].ScheduledJobsListTail[Priority] = SPI_JOB_NULL;
    }

    /* no scheduled job => MaxScheduledPriority is -1 */
    Spi_axSpiHwUnitQueueArray[HWUnit].MaxScheduledPriority = -1;
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check the initialization of driver and sequence ID is compatible in Synchronous mode.
* @details This function check the initialization of driver and sequence ID is compatible in Synchronous mode.
*
* @param[in]      SpiUserID      UserID
* @param[in]      Sequence          Sequence ID
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/
static Std_ReturnType Spi_SyncTransmitCheckDemReport(uint32 SpiUserID,
                                                     Spi_SequenceType Sequence)
{
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;

    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, SPI_SYNCTRANSMIT_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range */
    else if (Sequence > Spi_apxSpiConfigPtr[SpiUserID]->SpiMaxSequence)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_SEQ);
    }
    /* Verify the partition has assigned for sequence */
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig)
    {
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG);
    }
    else if (SpiUserID != Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig->SpiPartitionUse)
    {
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG);
    }
    else
    {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
        /* Check the validation of Job */
        Status = Spi_SynctransmitCheckJobsIsValid(Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig, SpiUserID);
#else
        Status = (Std_ReturnType)E_OK;
#endif
    }

    return Status;
}
#endif
#endif

/**
* @brief   Check for busy HWUnit in async transmissions.
* @details Check for busy HWUnit in async transmissions.
*
* @param[in]      SpiUserID      UserID
* @return Spi_StatusType
*
*
*/
static Spi_StatusType Spi_GetStatusAsyncCheckHwBusy(uint32 SpiUserID)
{
    Spi_StatusType StatusFlag = SPI_IDLE;
    Spi_HWUnitType HWUnit;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
    {
        PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
        if ((NULL_PTR != PhyUnitConfig) && (SpiUserID == PhyUnitConfig->SpiPartitionUse))
        {
            if (SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status)
            {
                StatusFlag = SPI_BUSY;
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    
    return StatusFlag;
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))

static void Spi_AsyncTransmitCallback(Spi_HWUnitType HwUnit,
                                      Spi_JobResultType JobResult)
{
    uint32 SpiUserID;
    Spi_ChannelType ChannelIndex, ChannelNumber;
    Spi_JobType Job;
    const Spi_JobConfigType *JobConfig;
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_ChannelStateType *ChannelState;
    Spi_DataBufferType *RxBuffer;
    const Spi_DataBufferType *TxBuffer;
    Spi_Ipw_ParamAsyncTransmit Param;

    /* Get current userID */
    SpiUserID = Spi_GetUserID;
    ChannelIndex = Spi_axSpiHwUnitQueueArray[HwUnit].Channel + 1u;
    Job = Spi_axSpiHwUnitQueueArray[HwUnit].Job;
    JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[Job].JobCfg;

    if ((ChannelIndex < JobConfig->NumChannels) && (SPI_JOB_OK == JobResult))
    {
        Spi_axSpiHwUnitQueueArray[HwUnit].Channel++;
        MCAL_DATA_SYNC_BARRIER();
        ChannelNumber = JobConfig->ChannelIndexList[ChannelIndex];
        ChannelConfig = (Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig)[ChannelNumber].ChannelCfg;
        ChannelState = &Spi_axSpiChannelState[ChannelNumber];
        MCAL_DATA_SYNC_BARRIER();
        RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if (EB == ChannelConfig->BufferType)
        {
            TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
        }
        else
        {
            TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
        }

        Param.ChannelConfig = ChannelConfig;
        /* Adjust param depending on the next transfer */
        ChannelIndex++;
        Param.FirstCmd = FALSE;
        if (ChannelIndex < JobConfig->NumChannels)
        {
            ChannelNumber = JobConfig->ChannelIndexList[ChannelIndex];
            Param.KeepCs = (boolean)TRUE;
            MCAL_DATA_SYNC_BARRIER();
            Param.NextChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[ChannelNumber].ChannelCfg;
            MCAL_DATA_SYNC_BARRIER();
        }
        else
        {
            Param.KeepCs = (boolean)FALSE;
            Param.NextChannelConfig = NULL_PTR;
        }

        Spi_Ipw_AsyncTransfer(JobConfig->ExternalDeviceConfig->ExDeviceConfig,
                              TxBuffer,
                              RxBuffer,
                              ChannelState->Length,
                              &Param);
    }
    else
    {
        Spi_JobTransferFinished(JobConfig, JobResult, &Spi_axSpiJobState[Job]);
    }
}

/**
* @brief   This function is called in order to mark the jobs of a sequence as ready to be transmitted.
* @details For each job in sequence, the function checks if it is already
*          linked to another pending sequence.
*          If at least one job is already linked, the function returns E_NOT_OK.
*          Elsewhere, all jobs in sequence are locked (linked to the current
*          sequence)
*
* @param[in]      Sequence        The sequence ID.
* @param[in]      JobCount        Number of job in sequence
*
* @return Std_ReturnType
* @retval E_OK       The given sequence does not share its jobs with some
*                    other sequences, and all its jobs were successfully
*                    locked.
* @retval E_NOT_OK  The given sequence shares its jobs with some other
*                   sequences. No lock performed for its jobs.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
static Std_ReturnType Spi_LockJobsProcess(Spi_SequenceStateType *SequenceState,
                                          const Spi_SequenceConfigType *Sequence,
                                          Spi_JobType JobCount)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType Job;
    Spi_JobStateType *JobState;

    Job = 0u;
    while (Job < JobCount)
    {
        JobState = &Spi_axSpiJobState[Sequence->JobIndexList[Job]];
        if (NULL_PTR == JobState->AsyncCrtSequenceState)
        {
            /* Job not yet linked => link it to the current sequence */
            JobState->AsyncCrtSequenceState = SequenceState;
        }
        else
        {
            /* The job is already locked by a pending sequence =>
               rollback all the previous locks */
            while (Job > 0u)
            {
                Job--;
                JobState = &Spi_axSpiJobState[Sequence->JobIndexList[Job]];
                JobState->AsyncCrtSequenceState = NULL_PTR;
            }
            Status = (Std_ReturnType)E_NOT_OK;
            break;
        }

        /* Next job */
        Job++;
    }

    return Status;
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if (SPI_VERSION_INFO_API == STD_ON)
/**
* @brief   This function returns the version information for the SPI driver.
* @details This function returns the version information for the SPI driver.
*          - Service ID:       0x09
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in,out]    VersionInfo      Pointer to where to store the version
*                                    information of this module.
*
* @pre  Pre-compile parameter SPI_VERSION_INFO_API shall be STD_ON.
*
*/
/** @implements Spi_GetVersionInfo_Activity */
void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if ( SPI_DEV_ERROR_DETECT == STD_ON )
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID,(uint8)0,SPI_GETVERSIONINFO_ID,SPI_E_PARAM_POINTER);
    }
    else
    {
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
    versioninfo->moduleID = (uint8)SPI_MODULE_ID;
    versioninfo->sw_major_version = (uint8)SPI_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)SPI_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)SPI_SW_PATCH_VERSION;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
}
#endif /* (SPI_VERSION_INFO_API == STD_ON) */

/**
* @brief   This function initializes the SPI driver.
* @details This function initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x00
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]     ConfigPtr      Specifies the pointer to the configuration set
*
*/
/** @implements Spi_Init_Activity */
void Spi_Init(const Spi_ConfigType *ConfigPtr)
{
    Spi_HWUnitType HWUnit;
    uint32 SpiUserID;
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    CheckStatus = Spi_InitCheckDemError(SpiUserID, ConfigPtr);
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

    CheckStatus = Spi_CheckInit(ConfigPtr, SpiUserID);

    if ((Std_ReturnType)E_OK == CheckStatus)
    {
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
        Spi_apxSpiConfigPtr[SpiUserID] = ConfigPtr;
    #else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
        Spi_apxSpiConfigPtr[SpiUserID] = Spi_PBCfgVariantPredefined[SpiUserID];
    #endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */
    /* Initiate Channels, Jobs, Sequences state */
    Spi_InitChannelsJobsSeqsState(SpiUserID);

        /* initialize all physical HWUnits */
        for (HWUnit = (Spi_HWUnitType) 0;
            HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT;
            HWUnit++)
        {
            PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
            if ((NULL_PTR != PhyUnitConfig) && (SpiUserID == PhyUnitConfig->SpiPartitionUse))
            {
                Spi_Ipw_Init(HWUnit, PhyUnitConfig);

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL1)
                /* handler uses interrupt mode only if LEVEL 1 is selected */
                Spi_axHwUnitState[HWUnit].AsyncMode = SPI_INTERRUPT_MODE;
#endif
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL2)
                /* handler uses polling mode only if LEVEL 2 is selected */
                Spi_axHwUnitState[HWUnit].AsyncMode = SPI_POLLING_MODE;
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
                Spi_Ipw_IrqConfig(PhyUnitConfig, Spi_axHwUnitState[HWUnit].AsyncMode, &Spi_AsyncTransmitCallback);
                /* initialize the Job lists => no scheduled job for the unit */
                Spi_InitJobsList(HWUnit);
#endif
                Spi_axSpiHwUnitQueueArray[HWUnit].Status = SPI_IDLE;
            }
        }
    }
    else
    {
        /*Do nothing. Should not enter here*/
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/
}

/**
* @brief   This function de-initializes the SPI driver.
* @details This function de-initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x01
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @return Std_ReturnType
* @retval E_OK       de-initialisation command has been accepted
* @retval E_NOT_OK   de-initialisation command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_DeInit()
*       otherwise, the function Spi_DeInit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_DeInit_Activity
*/
Std_ReturnType Spi_DeInit(void)
{
    Std_ReturnType TempExit = (Std_ReturnType)E_OK;
    Spi_HWUnitType HWUnit;
    uint32 SpiUserID;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_DEINIT_ID,SPI_E_UNINIT);
        TempExit = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /* Check if Spi Status is Busy */
        if (SPI_BUSY == Spi_GetStatus())
        {
            TempExit = E_NOT_OK;
        }
        else
        {
            /* De-initialize all physical HWUnits */
            for (HWUnit = (Spi_HWUnitType) 0;
                 HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT;
                 HWUnit++)
            {
                PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
                if ((NULL_PTR != PhyUnitConfig) && (SpiUserID == PhyUnitConfig->SpiPartitionUse))
                {
                    Spi_Ipw_DeInit(PhyUnitConfig);

                    Spi_axSpiHwUnitQueueArray[HWUnit].Status = SPI_UNINIT;
                }
                else
                {
                    /* Do nothing */
                }
            }
            /* Reset configuration pointer */
            Spi_apxSpiConfigPtr[SpiUserID] = NULL_PTR;
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return TempExit;
}

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE0) ||(SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
/**
* @brief   This function writes the given data into the buffer of a specific channel.
* @details This function writes the given data into the buffer of a specific channel.
*          - Service ID:       0x02
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      DataBufferPtr       Pointer to source data buffer
*
* @return Std_ReturnType
* @retval E_OK       Command has been accepted
* @retval E_NOT_OK   Command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_WriteIB()
*       otherwise, the function Spi_WriteIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE0 or SPI_USAGE2.
*
*/
/** @implements Spi_WriteIB_Activity */
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel,
                           const Spi_DataBufferType *DataBufferPtr)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint16 Index;
    Spi_ChannelStateType *ChannelState;
    const Spi_ChannelConfigType *ChannelConfig;
    uint32 SpiUserID;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_ChannelCheckValidity(Channel, SPI_WRITEIB_ID);

    if ((Std_ReturnType)E_OK != Status)
    {
       /* Do nothing */
    }
    else
    {
#endif
        ChannelState = &Spi_axSpiChannelState[Channel];
        ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[Channel].ChannelCfg;

        /* exit early if this is the wrong buffer type */
        if (EB == ChannelConfig->BufferType)
        {
            Status = (Std_ReturnType)E_NOT_OK;
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_WRITEIB_ID,SPI_E_PARAM_CHANNEL);
#endif
        }
        else
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04();
            /* if DataBufferPtr is zero, then transmit default value */
            if (NULL_PTR == DataBufferPtr)
            {

                ChannelState->Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }

            /* otherwise, copy data from DataBufferPtr to IB */
            else
            {
                for (Index = 0u; Index < ChannelConfig->Length; Index++)
                {
                    ChannelConfig->BufferDescriptor->InternalBufferTX[Index] = DataBufferPtr[Index];
                }
                ChannelState->Flags =
                    (uint8)(ChannelState->Flags & ((uint8)(~SPI_CHANNEL_FLAG_TX_DEFAULT_U8)));
            }
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04();
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    /* Return status */
    return Status;
}
#endif


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   This function triggers the asynchronous transmission for the given sequence.
* @details This function triggers the asynchronous transmission for the given sequence.
*          - Service ID:       0x03
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK       Transmission command has been accepted
* @retval E_NOT_OK   Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_AsyncTransmit()
*       otherwise, the function Spi_AsyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
/** @implements Spi_AsyncTransmit_Activity */
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType JobIndex;
    Spi_JobType JobId;
    const Spi_SequenceConfigType *SequenceConfig;
    Spi_SequenceStateType *SequenceState;
    const Spi_JobConfigType *JobConfig;
    /* Get current UserID */
    uint32 SpiUserID = Spi_GetUserID;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error and do nothing if driver isn't init or sequence ID is not in correct range */
    Status = Spi_AsyncTransmitCheckDemReport(SpiUserID, Sequence);
    if ((Std_ReturnType)E_OK == Status)
    {
#endif
        SequenceConfig = Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Check partition has assigned for sequence */
        if (NULL_PTR == SequenceConfig)
        {
            /* Has wrong partition */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG);
            Status = (Std_ReturnType)E_NOT_OK;
        } else if (SpiUserID != SequenceConfig->SpiPartitionUse)
        {
            /* Has wrong partition */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }
    if ((Std_ReturnType)E_OK == Status)
    {
        /* check for empty sequence */
        if (0u == SequenceConfig->NumJobs)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_SEQ_EMPTY);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
    }
    JobIndex = 0u;
    while(((Std_ReturnType)E_OK == Status) && (JobIndex < SequenceConfig->NumJobs))
    {
        /* Get the job id */
        JobId = SequenceConfig->JobIndexList[JobIndex];

        JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[JobId].JobCfg;

        /* check for empty jobs */
        if (0u == JobConfig->NumChannels)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_JOB_EMPTY);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Check the validity of EB channels */
            Status = Spi_AsyncTransmitCheckValidityOfChannels(SpiUserID, JobConfig);
        }
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2)) */
        if ((Std_ReturnType)E_OK != Status)
        {
            /* break */
            break;
        }
        else
        {
            /* Do nothing */
        }
        JobIndex++;
    }
    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */
        SequenceState = &Spi_axSpiSequenceState[Sequence];
        Status = Spi_LockJobs(SequenceState, SequenceConfig);
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Mark sequence pending */
            SequenceState->Result = SPI_SEQ_PENDING;

            /* Initialize job related information */
            SequenceState->RemainingJobs = SequenceConfig->NumJobs - 1u;
            for(JobIndex = 0u; JobIndex < SequenceConfig->NumJobs; JobIndex++)
            {
                JobId = SequenceConfig->JobIndexList[JobIndex];
                Spi_axSpiJobState[JobId].Result = SPI_JOB_QUEUED;
            }
            SequenceState->CurrentJobIndexPointer = &SequenceConfig->JobIndexList[0];
            /* Schedule transmission of the first job */
            JobId = SequenceConfig->JobIndexList[0];
            JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[JobId].JobCfg;
            Spi_ScheduleJob(&Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit], JobId, JobConfig);
        }
        else
        {
            /* Call Det_ReportRuntimeError */
            (void)Det_ReportRuntimeError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_SEQ_PENDING);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

    return Status;
}

#endif

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
/**
* @brief   This function reads the data from the buffer of a channel and puts at the memory location.
* @details This function reads the data from the buffer of a specific channel
*          and puts at the specified memory location.
*          - Service ID:       0x04
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
*
* @param[in]      Channel             Channel ID
* @param[in,out]  DataBufferPointer       Pointer to the memory location that will
*                                     be written with the data in the internal
*                                     buffer
*
* @return Std_ReturnType
* @retval E_OK      read command has been accepted
* @retval E_NOT_OK  read command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_ReadIB()
*       otherwise, the function Spi_ReadIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE0 or SPI_USAGE2.
*
*/
/** @implements Spi_ReadIB_Activity */
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel,
                          Spi_DataBufferType *DataBufferPointer)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_NumberOfDataType Index;
    const Spi_ChannelConfigType *ChannelConfig;
    uint32 SpiUserID;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_ChannelCheckValidity(Channel, SPI_READIB_ID);

    if ((Std_ReturnType)E_OK != Status)
    {
        /* Do nothing */
    }
    else
    {
#endif
        ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[Channel].ChannelCfg;

        /* exit early if this is the wrong buffer type or destination
           is invalid */
        if (EB == ChannelConfig->BufferType)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else if (NULL_PTR == DataBufferPointer)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Copy Rx buffer to IB buffer */
            for (Index = 0u; Index < ChannelConfig->Length; Index++)
            {
                DataBufferPointer[Index] = ChannelConfig->BufferDescriptor->BufferRX[Index];
            }
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
/**
* @brief   This function setup an external buffer to be used by a specific channel.
* @details This function setup an external buffer to be used by a specific channel.
*          - Service ID:       0x05
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      SrcDataBufferPtr    Pointer to the memory location that will hold
*                                     the transmitted data
* @param[in]      Length              Length of the data in the external buffer
* @param[out]     DesDataBufferPtr    Pointer to the memory location that will hold
*                                     the received data
*
* @return Std_ReturnType
* @retval E_OK      Setup command has been accepted
* @retval E_NOT_OK  Setup command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SetupEB()
*       otherwise, the function Spi_SetupEB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE1 or SPI_USAGE2.
*
*/
/** @implements Spi_SetupEB_Activity */
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel,
                           const Spi_DataBufferType  *SrcDataBufferPtr,
                           Spi_DataBufferType *DesDataBufferPtr,
                           Spi_NumberOfDataType Length)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_ChannelStateType *ChannelState;
    const Spi_ChannelConfigType *ChannelConfig;
    uint32 SpiUserID;

    /* get current UserID */
    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_ChannelCheckValidity(Channel, SPI_SETUPEB_ID);
    if ((Std_ReturnType)E_OK == Status)
    {
        ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[Channel].ChannelCfg;
        if (IB == ChannelConfig->BufferType)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_CHANNEL);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        if ((Std_ReturnType)E_OK == Status) {
            if ((Length > ChannelConfig->Length) || (0u == Length)) {
                /* Call Det_ReportError */
                (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID, SPI_E_PARAM_LENGTH);
                Status = (Std_ReturnType)E_NOT_OK;
            } else {
                /* Length - Valid range */
                Status = Spi_SetupEbCheckLength(ChannelConfig, Length);
            }
        }
    }
    if ((Std_ReturnType)E_OK == Status)
    {
#endif
        ChannelConfig = Spi_apxSpiConfigPtr[SpiUserID]->ChannelConfig[Channel].ChannelCfg;
        /* exit early if this is the wrong buffer type */
        if (EB == ChannelConfig->BufferType)
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05();
            /* save the new parameters */
            ChannelConfig->BufferDescriptor->ExternalBufferTX = SrcDataBufferPtr;
            ChannelConfig->BufferDescriptor->BufferRX = DesDataBufferPtr;

            ChannelState = &Spi_axSpiChannelState[Channel];
            /* Get channel length from framesize and data NumberOfData */
            ChannelState->Length = Spi_SetupEbGetLength(ChannelConfig->FrameSize, Length);

            /* if source data pointer is zero, transmit default value */
            if (NULL_PTR == SrcDataBufferPtr)
            {
                ChannelState->Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }
            else
            {
                ChannelState->Flags &= (uint8) (~SPI_CHANNEL_FLAG_TX_DEFAULT_U8);
            }

            /* if destination data pointer is zero, discard receiving data */
            if (NULL_PTR == DesDataBufferPtr)
            {
                ChannelState->Flags |= SPI_CHANNEL_FLAG_RX_DISCARD_U8;
            }
            else
            {
                ChannelState->Flags &= (uint8) (~SPI_CHANNEL_FLAG_RX_DISCARD_U8);
            }
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();
        }
        else
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

/**
* @brief   This function returns the status of the SPI driver.
* @details This function returns the status of the SPI driver.
*          - Service ID:       0x06
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetStatus()
*       otherwise, the function Spi_GetStatus() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_GetStatus_Activity
*/
Spi_StatusType Spi_GetStatus(void)
{
    Spi_StatusType StatusFlag = SPI_IDLE;
    Spi_HWUnitType HWUnit;
    uint32 SpiUserID;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* If Development Error Detection is enabled, report error if not */
        /* initialized */
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSTATUS_ID,SPI_E_UNINIT);
#endif
        StatusFlag = SPI_UNINIT;
    }
    else
    {
        /* The SPI Handler Driver software module shall be busy when any
           HWUnit is busy */
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
        {
            PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
            if ((NULL_PTR != PhyUnitConfig) && (SpiUserID == PhyUnitConfig->SpiPartitionUse))
            {
                if (1u == Spi_au32SpiBusySyncHWUnitsStatus[HWUnit])
                {
                    StatusFlag = SPI_BUSY;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        /* check for busy HWUnit in async transmissions */
        if (SPI_BUSY != StatusFlag)
        {
            /* Note: Checking for IsSync attribute for HWUnit is not really needed
                 It is preferable to skip this check in order to have a more compact code
            */
            StatusFlag = Spi_GetStatusAsyncCheckHwBusy(SpiUserID);
        }
        else
        {
            /* Do nothing */
        }
    }
    
    return StatusFlag;
}

/**
* @brief   This function is used to request the status of a specific job.
* @details This function is used to request the status of a specific job.
*          - Service ID:       0x07
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Job                 Job ID
*
* @return Spi_JobResultType
* @retval SPI_JOB_OK        The job ended successfully
* @retval SPI_JOB_PENDING   The job is pending
* @retval SPI_JOB_FAILED    The job has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetJobResult()
*       otherwise, the function Spi_GetJobResult() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
*/
/** @implements Spi_GetJobResult_Activity */
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
{
    Spi_JobResultType JobResult;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32 SpiUserID;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_UNINIT);
    }
    /* Job Valid Range - from 0 to SpiMaxJob*/
    else if (Job > Spi_apxSpiConfigPtr[SpiUserID]->SpiMaxJob)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_JOB);
    }
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[Job].JobCfg)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_CONFIG);
    }
    else if (SpiUserID != Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[Job].JobCfg->SpiPartitionUse)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_CONFIG);
    }
    else
    {
#endif
        JobResult = Spi_axSpiJobState[Job].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return JobResult;
}

/**
* @brief   This function is used to request the status of a specific sequence.
* @details This function is used to request the status of a specific sequence.
*          - Service ID:       0x08
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Spi_SeqResultType
* @retval SPI_SEQ_OK       The sequence ended successfully
* @retval SPI_SEQ_PENDING  The sequence is pending
* @retval SPI_SEQ_FAILED   The sequence has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetSequenceResult()
*       otherwise, the function Spi_GetSequenceResult() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
*
*/
/** @implements Spi_GetSequenceResult_Activity */
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
    Spi_SeqResultType SequenceResult;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32 SpiUserID;
    const Spi_SequenceConfigType *SequenceConfig;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        SequenceResult = SPI_SEQ_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range from 0 to SpiMaxSequence*/
    else if (Sequence > Spi_apxSpiConfigPtr[SpiUserID]->SpiMaxSequence)
    {
        SequenceResult = SPI_SEQ_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_SEQ);
    }
    else
    {
        SequenceConfig = Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig;
        /* Check partition has assigned for sequence */
        if (NULL_PTR == SequenceConfig)
        {
            SequenceResult = SPI_SEQ_FAILED;
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_CONFIG);
        }
        else if (SpiUserID != SequenceConfig->SpiPartitionUse)
        {
            SequenceResult = SPI_SEQ_FAILED;
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_CONFIG);
        }
        else
        {
#endif
           SequenceResult = Spi_axSpiSequenceState[Sequence].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif

    return SequenceResult;
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))

/* Set used HW units status */
static void Spi_SetHWUnitsStatus(const Spi_ConfigType *SpiConfig,
                                 const Spi_SequenceConfigType *SequenceConfig,
                                 uint32 Busy)
{
    Spi_JobType JobIndex;
    Spi_JobType Job;
    Spi_HWUnitType HWUnit;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07();
    for (JobIndex = 0u; JobIndex < SequenceConfig->NumJobs; JobIndex++)
    {
        /* Get the job id */
        Job = SequenceConfig->JobIndexList[JobIndex];
        /* Logical Spi HWUnit */
        HWUnit = SpiConfig->JobConfig[Job].JobCfg->HWUnit;
        Spi_au32SpiBusySyncHWUnitsStatus[HWUnit] = Busy;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        if (1u == Busy)
        {
            Spi_axHwUnitState[HWUnit].SyncInProgress = (boolean)TRUE;
        }
        else
        {
            Spi_axHwUnitState[HWUnit].SyncInProgress = (boolean)FALSE;
        }
#endif
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07();
}

/**
* @brief   This function is used for synchronous transmission of a given sequence.
* @details This function is used for synchronous transmission of a given sequence.
*          - Service ID:       0x0a
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK      Transmission command has been completed successfully
* @retval E_NOT_OK  Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SyncTransmit().
*       otherwise, the function Spi_SyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*
*/
/** @implements Spi_SyncTransmit_Activity */
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    Spi_SequenceStateType *SequenceState;
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_HWUnitType HWUnit;
    const Spi_SequenceConfigType *SequenceConfig;
    uint32 SpiUserID;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_SyncTransmitCheckDemReport(SpiUserID, Sequence);
    if ((Std_ReturnType)E_NOT_OK != Status)
    {
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
        SequenceConfig = Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig;

        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06();
        /* check if there are HW units already running */
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
        {
            if ((0u != Spi_au32SpiBusySyncHWUnitsStatus[HWUnit]) &&
                (0u != (((uint32)1u << HWUnit) & Spi_au32SpiSeqUsedHWUnits[Sequence])))
            {
                Status = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
        }

        if ((Std_ReturnType)E_NOT_OK != Status)
        {
            /* Set the sequence as pending */
            SequenceState = &Spi_axSpiSequenceState[Sequence];
            SequenceState->Result = SPI_SEQ_PENDING;
            /* set used HW units as busy */
            Spi_SetHWUnitsStatus(Spi_apxSpiConfigPtr[SpiUserID], SequenceConfig, 1u);
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06();
            /* Transmit Jobs */
            Status = Spi_SyncJobsTranfer(SequenceConfig, SpiUserID);

            if ((Std_ReturnType)E_OK == Status)
            {
                /* Set the sequence as OK */
                SequenceState->Result = SPI_SEQ_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* Report to DEM */
                Spi_DemReportStatus(SpiUserID, DEM_EVENT_STATUS_PASSED);
#endif
            }
            else
            {
                /* Set the sequence as FAILED */
                SequenceState->Result = SPI_SEQ_FAILED;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* Report to DEM */
                Spi_DemReportStatus(SpiUserID, DEM_EVENT_STATUS_FAILED);
#endif
            }

            /* Set used HW units as idle */
            Spi_SetHWUnitsStatus(Spi_apxSpiConfigPtr[SpiUserID], SequenceConfig, 0u);

            /* End Sequence Notification */
            if (NULL_PTR != SequenceConfig->EndNotification)
            {
                SequenceConfig->EndNotification();
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06();
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
            /* Call Det_ReportRuntimeError */
            (void)Det_ReportRuntimeError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_SEQ_IN_PROCESS);
#endif
#endif
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0)) */


#if (SPI_HW_STATUS_API == STD_ON)
/**
* @brief   This function is used to request the status of a specific SPI peripheral unit.
* @details This function is used to request the status of a specific SPI peripheral unit.
*          - Service ID:       0x0b
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      HWUnit              The HW peripheral for which we need the status
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The peripheral is un-initialized
* @retval SPI_IDLE    The peripheral is in idle state
* @retval SPI_BUSY    The peripheral is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetHWUnitStatus()
*       otherwise, the function Spi_GetHWUnitStatus() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  SPI_HW_STATUS_API == STD_ON
*
*/
/** @implements Spi_GetHWUnitStatus_Activity */
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    Spi_StatusType Status = SPI_UNINIT;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    if ((Std_ReturnType)E_OK != Spi_HWUnitCheckValidity(HWUnit, SPI_GETHWUNITSTATUS_ID))
    {
        /* Do nothing */
    }
    else
    {
#endif
        Status = Spi_axSpiHwUnitQueueArray[HWUnit].Status;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

#if (SPI_CANCEL_API == STD_ON)
/**
* @brief   This function is used to request the cancellation of the given sequence.
* @details This function is used to request the cancellation of the given sequence.
*          - Service ID:       0x0c
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @pre  The driver needs to be initialized before calling Spi_Cancel()
*       otherwise, the function Spi_Cancel() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON
* @post  The SPI Handler Driver is not responsible on external devices damages or
*       undefined state due to cancelling a sequence transmission.
*
*/
/**  @implements Spi_Cancel_Activity */
void Spi_Cancel(Spi_SequenceType Sequence)
{
#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0)) 
    const Spi_HWUnitConfigType *PhyUnitConfig;
    const Spi_JobConfigType *JobConfig;
#endif
#if (((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0)) || \
    (SPI_DEV_ERROR_DETECT == STD_ON))
    uint32 SpiUserID;
    const Spi_SequenceConfigType *SequenceConfig;
    Std_ReturnType Ret = E_NOT_OK;
#endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Get current UserID */
    SpiUserID = Spi_GetUserID;
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range  from 0 to SpiMaxSequence*/
    else if (Sequence > Spi_apxSpiConfigPtr[SpiUserID]->SpiMaxSequence)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_SEQ);
    }
    else
    {
        SequenceConfig = Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig;
        /* Check partition has assigned for sequence */
        if (NULL_PTR == SequenceConfig)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_CONFIG);
        }
        else if (SpiUserID != SequenceConfig->SpiPartitionUse)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_CONFIG);
        }
        else
        {
            Ret = E_OK;
        }
    }
    if (Ret == E_OK)
    {
#endif
        /* Set sequence state to Cancel */
        Spi_axSpiSequenceState[Sequence].Result = SPI_SEQ_CANCELLED;

        /* In Slave mode: Stop sequence immediately */
        #if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0))
        SpiUserID = Spi_GetUserID;
        SequenceConfig = Spi_apxSpiConfigPtr[SpiUserID]->SequenceConfig[Sequence].SeqConfig;
        JobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[SequenceConfig->JobIndexList[0u]].JobCfg;
        PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[JobConfig->HWUnit].PhyUnitConfig;
        Ret = Spi_Ipw_SlaveCancel(PhyUnitConfig);
        if (Ret == E_OK)
        {
            Spi_JobTransferFinished(JobConfig, SPI_JOB_FAILED, &Spi_axSpiJobState[SequenceConfig->JobIndexList[0u]]);
        }
        #endif /* #if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0)) */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))

static Spi_StatusType Spi_IsAsyncModeChangeable(uint32 SpiUserID, Spi_HWUnitType HWUnit)
{
    Spi_StatusType Ret;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
    if ((NULL_PTR == PhyUnitConfig) || (PhyUnitConfig->SpiPartitionUse != SpiUserID))
    {
        /* HWUnit update should be ignore and don't fail */
        Ret = SPI_UNINIT;
    }
    else if ((SPI_IDLE == Spi_axSpiHwUnitQueueArray[HWUnit].Status) ||
             ((SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status) && 
             ((boolean)TRUE == Spi_axHwUnitState[HWUnit].SyncInProgress)))
    {
        /* Async Mode can be updated */
        Ret = SPI_IDLE;
    }
    else
    {
        /* Async Mode can't be updated */
        Ret = SPI_BUSY;
    }
    return Ret;
}

/**
* @brief   This function specifies the asynchronous mode for the SPI busses handled asynchronously.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          - Service ID:       0x0d
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]      Mode         This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK      The command ended successfully
* @retval E_NOT_OK  The command has failed
*
* @pre  The driver needs to be initialized before calling Spi_SetAsyncMode()
*       otherwise, the function Spi_SetAsyncMode() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2
*
*/
/** @implements Spi_SetAsyncMode_Activity */
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    Spi_HWUnitType HWUnit;
    Std_ReturnType Ret = SPI_RET_OK;
    Spi_StatusType Status[SPI_MAX_HWUNIT];
    uint32 SpiUserID;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETASYNCMODE_ID,SPI_E_UNINIT);
        Ret = SPI_RET_NOT_OK;
    }
    else
    {
#endif
        /* set the async mode for each HW Unit;
            activate/deactivate EOQ interrupts for Async HWUnits */
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
        {
            Status[HWUnit] = Spi_IsAsyncModeChangeable(SpiUserID, HWUnit);
            if (SPI_BUSY == Status[HWUnit])
            {
                Ret = SPI_RET_NOT_OK;
                break;
            }
        }
        if (SPI_RET_OK == Ret)
        {
            for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
            {
                if (SPI_IDLE == Status[HWUnit])
                {
                    Spi_axHwUnitState[HWUnit].AsyncMode = Mode;
                    Spi_axHwUnitState[HWUnit].AsyncModeDirty = TRUE;
                }
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Ret;
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL1) && (SPI_LEVEL_DELIVERED == SPI_LEVEL2) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
/**
* @brief   This function specifies the asynchronous mode for a given HWUnit.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          For synchronous HW units, the function has no impact.
*          The function will fail in two cases:
*          - driver not initialised (SPI_E_UNINIT reported by DET)
*          - a sequence transmission is pending the the asynchronous HW unit
*            (SPI_E_SEQ_PENDING reported by DET)
*
* @param[in]      HWUnit       The ID of the HWUnit to be configured
* @param[in]      AsyncMode    This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK       The command ended successfully
* @retval E_NOT_OK   The command has failed
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL2 and
*       SPI_HWUNIT_ASYNC_MODE should be on STD_ON
*
*/
/** @implements Spi_SetHWUnitAsyncMode_Activity */
Std_ReturnType Spi_SetHWUnitAsyncMode(Spi_HWUnitType HWUnit,
                                      Spi_AsyncModeType AsyncMode)
{
    Std_ReturnType Ret = SPI_RET_OK;
    uint32 SpiUserID = Spi_GetUserID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Ret = Spi_HWUnitCheckValidity(HWUnit, SPI_SETHWUNITASYNCMODE_ID);
    if (SPI_RET_OK == Ret)
    {
#endif
        /* Update Async mode only if HWUnit is idle or Synchronous transmission is in progress */
        if (SPI_IDLE == Spi_IsAsyncModeChangeable(SpiUserID, HWUnit))
        {
            Spi_axHwUnitState[HWUnit].AsyncMode = AsyncMode;
            Spi_axHwUnitState[HWUnit].AsyncModeDirty = TRUE;
        }
        else
        {
            Ret = SPI_RET_NOT_OK;
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Ret;
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

/**
* @brief   This function shall asynchronously poll SPI interrupts and call ISR if appropriate.
* @details This function shall asynchronously poll SPI interrupts and call
*          ISR if appropriate.
*          - Service ID:       0x10
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
/** @implements Spi_MainFunction_Handling_Activity */
void Spi_MainFunction_Handling(void)
{
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    Spi_HWUnitType HWUnit;
    uint32 SpiUserID;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;

    if (NULL_PTR != Spi_apxSpiConfigPtr[SpiUserID])
    {
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
        {
            PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
            if ((NULL_PTR != PhyUnitConfig) &&
               (SpiUserID == PhyUnitConfig->SpiPartitionUse) &&
               ((boolean)FALSE == Spi_axHwUnitState[HWUnit].SyncInProgress)
              )
            {
                if ((SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status) &&
                    (SPI_POLLING_MODE == Spi_axHwUnitState[HWUnit].AsyncMode))
                {
                    Spi_Ipw_IrqPoll(PhyUnitConfig);
                }
            }
        }
    }
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */
}

/**
* @brief   This function starts the transfer of the first scheduled job for a given HW unit.
* @details If the list of scheduled jobs is not empty, pop the first job and
*          start the transfer. Elsewhere, mark the HW unit as IDLE.
*
* @param[in]      HWUnitQueue     The HW Unit used for scheduling
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_ScheduleNextJob(Spi_HWUnitQueue *HWUnitQueue,
                                uint32 SpiUserID)
{
    Spi_JobType Job;
    Spi_JobType *JobListHead;
    sint8 Priority;
    sint8 MaxScheduledPriority;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01();
    MaxScheduledPriority = HWUnitQueue->MaxScheduledPriority;
    if (0 > MaxScheduledPriority)
    {
        /* no job waiting => mark the HWUnit as IDLE */
        HWUnitQueue->Status = SPI_IDLE;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();
    }
    else
    {
        /* a job is waiting => get the job ID from the highest priority queue */
        JobListHead = &HWUnitQueue->ScheduledJobsListHead[MaxScheduledPriority];
        Job = *JobListHead;

        /* set the new head of the list */
        *JobListHead = Spi_axSpiJobState[Job].AsyncNextJob;

        /* if the list is empty, set the tail accordingly and adjust the
           scheduled priority level */
        if (SPI_JOB_NULL == *JobListHead)
        {
            /* reset the tail */
            HWUnitQueue->ScheduledJobsListTail[MaxScheduledPriority] = SPI_JOB_NULL;

            /* find the first non empty scheduling queue */
            for (Priority = MaxScheduledPriority - 1; Priority >= 0; Priority--)
            {
                if (SPI_JOB_NULL != HWUnitQueue->ScheduledJobsListHead[Priority])
                {
                    /* there is a scheduled Job for this priority level */
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }

            /* Priority is set on the highest priority queue having
               scheduled jobs, or -1 if no other jobs scheduled */
            HWUnitQueue->MaxScheduledPriority = Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();

        /* mark the job as pending */
        Spi_axSpiJobState[Job].Result = SPI_JOB_PENDING;
        HWUnitQueue->Channel = 0u;
        HWUnitQueue->Job = Job;
        Spi_JobTransfer(Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[Job].JobCfg, &Spi_axSpiJobState[Job]);
    }
}

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) || (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)))
static void Spi_Handle_DMAFast_ContMem(const Spi_SequenceConfigType *SequenceConfig,
                                       Spi_SequenceStateType *SequenceState)
{
    Spi_JobType JobIdx;
    boolean SkipAllJob = FALSE;

    #if (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    SkipAllJob = SequenceConfig->EnableDmaFastTransfer;
    #endif
    #if (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)
    SkipAllJob = SkipAllJob || SequenceConfig->EnableDmaContMemTransfer;
    #endif
    if (TRUE == SkipAllJob)
    {
        /* Set Job result to SPI_JOB_OK for all remaining Jobs */
        for (JobIdx = SequenceConfig->NumJobs - SequenceState->RemainingJobs; JobIdx < SequenceConfig->NumJobs; JobIdx++)
        {
            MCAL_DATA_SYNC_BARRIER();
            Spi_axSpiJobState[SequenceConfig->JobIndexList[JobIdx]].Result = SPI_JOB_OK;
            MCAL_DATA_SYNC_BARRIER();
        }

        /* unlock jobs */
        Spi_UnlockRemainingJobs(SequenceState->RemainingJobs, SequenceConfig);
        /* Set remaining Jobs to 0 */
        SequenceState->RemainingJobs = 0u;
    }
}
#endif

static void Spi_Handle_SequenceNextJobs(const Spi_JobConfigType *JobConfig,
                                        Spi_SequenceStateType *SequenceState)
{
    Spi_HWUnitQueue *HWUnitQueue = &Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit];
    const Spi_JobConfigType *CurrentJobConfig;
    Spi_JobType JobId;
    uint32 SpiUserID;
    
    SpiUserID = JobConfig->SpiPartitionUse;
    /* advance to the next job */
    SequenceState->CurrentJobIndexPointer++;
    JobId = *SequenceState->CurrentJobIndexPointer;
    SequenceState->RemainingJobs--;
    CurrentJobConfig = Spi_apxSpiConfigPtr[SpiUserID]->JobConfig[JobId].JobCfg;
    if (JobConfig->HWUnit != CurrentJobConfig->HWUnit)
    {
        /* schedule the next job on the new DSPI unit */
        Spi_ScheduleJob(&Spi_axSpiHwUnitQueueArray[CurrentJobConfig->HWUnit], JobId, CurrentJobConfig);

        /* transmit the next scheduled job on the current DSPI unit */
        Spi_ScheduleNextJob(HWUnitQueue, SpiUserID);
    }
    else
    {
        /* the next job uses the same DSPI unit */

#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
        if (1u == SequenceState->Sequence->Interruptible)
        {
            /* if the sequence is interruptible,
                then schedule the next job */
            /* DSPI is marked as BUSY => the new job is scheduled only */
            Spi_ScheduleJob(HWUnitQueue, JobId, CurrentJobConfig);

            /* run the first eligible job */
            Spi_ScheduleNextJob(HWUnitQueue, SpiUserID);
        }
        else
#endif
        {
            /* non-interruptible sequence =>
                start transmission without scheduling */
            /* mark the job as pending */
            Spi_axSpiJobState[JobId].Result = SPI_JOB_PENDING;
            HWUnitQueue->Channel = 0;
            HWUnitQueue->Job = JobId;
            Spi_JobTransfer(CurrentJobConfig, &Spi_axSpiJobState[JobId]);
        }
    }
}

/**
* @brief   This function is called after a Job has been executed.
* @details The function calls Job and Sequence end notifications and schedules
*          the next job of the sequence or on the liberated HW Unit.
*
* @param[in]    JobConfig   The just transmited job pointer.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
* @implements Spi_JobTransferFinished_Activity
*/
static void Spi_JobTransferFinished(const Spi_JobConfigType *JobConfig,
                                    Spi_JobResultType JobResult,
                                    Spi_JobStateType *JobState)
{
    Spi_HWUnitQueue *HWUnitQueue = &Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit];
    Spi_SequenceStateType *SequenceState;
    const Spi_SequenceConfigType *SequenceConfig;
    uint32 SpiUserID;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02();
    if ((SPI_JOB_OK != JobState->Result) && (NULL_PTR != JobState->AsyncCrtSequenceState))
    {
        JobState->Result = JobResult;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();

        SpiUserID = JobConfig->SpiPartitionUse;
        SequenceState = JobState->AsyncCrtSequenceState;
        SequenceConfig = SequenceState->Sequence;
        /* unlink the job from its sequence */
        JobState->AsyncCrtSequenceState = NULL_PTR;
        /* Perform job EndNotification (if there is one) */
        if (NULL_PTR != JobConfig->EndNotification)
        {
            JobConfig->EndNotification();
        }
        /* set Sequence to fail if Job has been failed */
        if ((SPI_JOB_FAILED == JobState->Result) && (SequenceState->Result != SPI_SEQ_CANCELLED))
        {
            SequenceState->Result = SPI_SEQ_FAILED;
        }
        /* Check if current sequence has been cancelled or fail*/
        if ((SPI_SEQ_FAILED == SequenceState->Result)
#if (SPI_CANCEL_API == STD_ON)
            || (SPI_SEQ_CANCELLED == SequenceState->Result)
#endif
           )
        {
            /* unlock jobs */
            Spi_UnlockRemainingJobs(SequenceState->RemainingJobs, SequenceConfig);
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if (SPI_SEQ_FAILED == SequenceState->Result)
            {
                /* Report to DEM */
                Spi_DemReportStatus(SpiUserID, DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                /* Report to DEM */
                Spi_DemReportStatus(SpiUserID, DEM_EVENT_STATUS_PASSED);
            }
#endif
            /* SeqEndNotification */
            if (NULL_PTR != SequenceConfig->EndNotification)
            {
                SequenceConfig->EndNotification();
            }

            Spi_ScheduleNextJob(HWUnitQueue, SpiUserID);
        }
        else
        {
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) || (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)))
            Spi_Handle_DMAFast_ContMem(SequenceConfig, SequenceState);
#endif
            /* Check if this job is the last one */
            if (0u == SequenceState->RemainingJobs)
            {
                /* Reset sequence state */
                SequenceState->Result = SPI_SEQ_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* Report to DEM */
                Spi_DemReportStatus(SpiUserID, DEM_EVENT_STATUS_PASSED);
#endif

                /* SeqEndNotification */
                if (NULL_PTR != SequenceConfig->EndNotification)
                {
                    SequenceConfig->EndNotification();
                }

                Spi_ScheduleNextJob(HWUnitQueue, SpiUserID);

            }
            else
            {
                Spi_Handle_SequenceNextJobs(JobConfig, SequenceState);
            }
        }
    }
    else
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();
    }
}

#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   This function shall set different MCU clock configuration .
* @details This function shall set different MCU clock configuration .
*
* @param[in]    ClockMode   Clock mode to be set (SPI_NORMAL | SPI_ALTERNATE).
*
* @return Std_ReturnType
* @retval E_OK       The driver is initialised and in an IDLE state. The clock
*                    mode can be changed.
* @retval E_NOT_OK   The driver is NOT initialised OR is NOT in an IDLE state.
*                    The clock mode can NOT be changed.
*
* @pre  Pre-compile parameter SPI_DUAL_CLOCK_MODE shall be STD_ON.
*
*/
/** @implements Spi_SetClockMode_Activity */
Std_ReturnType Spi_SetClockMode(Spi_DualClockModeType ClockMode)
{
   Std_ReturnType Status = (Std_ReturnType)E_OK;
   Spi_HWUnitType HWUnit;
   uint32 SpiUserID;
    const Spi_HWUnitConfigType *PhyUnitConfig;

    /* Get current UserID */
    SpiUserID = Spi_GetUserID;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiUserID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETCLOCKMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /* Check if Spi Status is Busy */
        if (SPI_BUSY == Spi_GetStatus())
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            for (HWUnit = (Spi_HWUnitType)0;
            HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT;
            HWUnit++)
            {
                PhyUnitConfig = Spi_apxSpiConfigPtr[SpiUserID]->HWUnitConfig[HWUnit].PhyUnitConfig;
                if ((NULL_PTR != PhyUnitConfig) && (SpiUserID == PhyUnitConfig->SpiPartitionUse))
                {
                    Spi_Ipw_SetClockMode(ClockMode, PhyUnitConfig);
                }
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
