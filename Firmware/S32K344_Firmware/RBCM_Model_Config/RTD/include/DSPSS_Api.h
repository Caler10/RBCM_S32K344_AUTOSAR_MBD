/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

#ifndef DSPSS_API_H
#define DSPSS_API_H

/** @cond DRIVER_INTERNAL_USE_ONLY */

/**
*   @file DSPSS_Api.h
*
*   @addtogroup sd_adc_ip Sd Adc IPL
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "DSPSS_Types.h"





/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DSPSS_VENDOR_ID_API                      43
#define DSPSS_AR_RELEASE_MAJOR_VERSION_API       4
#define DSPSS_AR_RELEASE_MINOR_VERSION_API       7
#define DSPSS_AR_RELEASE_REVISION_VERSION_API    0
#define DSPSS_SW_MAJOR_VERSION_API               5
#define DSPSS_SW_MINOR_VERSION_API               0
#define DSPSS_SW_PATCH_VERSION_API               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if DSPSS_Api.h file and DSPSS_Types.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_API != DSPSS_VENDOR_ID_TYPES)
    #error "DSPSS_Api.h and DSPSS_Types.h have different vendor ids"
#endif

/* Check if DSPSS_Api.h file and DSPSS_Types.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API != DSPSS_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API != DSPSS_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_API != DSPSS_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.h and DSPSS_Types.h are different"
#endif

/* Check if DSPSS_Api.h file and DSPSS_Types.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_API != DSPSS_SW_MAJOR_VERSION_TYPES) || \
     (DSPSS_SW_MINOR_VERSION_API != DSPSS_SW_MINOR_VERSION_TYPES) || \
     (DSPSS_SW_PATCH_VERSION_API != DSPSS_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of DSPSS_Api.h and DSPSS_Types.h are different"
#endif

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"


/*!
 * @brief Check if the DSP has been initialized before.
 *
 * @return Return boolean DSP initialization completion status
 */
boolean DSPSS_HasInitialized(void);


/*!
 * @brief Initializes the DSPSS by loading the FW init PMEM and default configuration into XMEM.
 *
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_Init(void);


/*!
 * @brief DSP initialization
 *
 * @return void
 */
void DSPSS_DspInit(void);


/**
 * @brief This function allows the user to de-initialize the DSPSS
 *
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_Deinit(void);


/**
 * @brief This function get the information about CFSDADC firmware
 *
 * @param[out] FirmwareVersion The pointer to the address that will contain the CFSDADC firmware build tag
 * @param[in] Length The length of the string that will contain the CFSDADC firmware build tag
 * @return void
 */
void DSPSS_FirmwareVersionGet(uint16 * const FirmwareVersion,
                              const uint32 Length);


/**
 * @brief Configure the DSPSS thread
 *
 * @param[in] Id Thread id
 * @param[in] Config Thread configuration information
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_ThreadConfigure(const DSPSS_ThreadIdType Id,
                                       const DSPSS_ThreadConfigType * const Config);


/**
 * @brief Initialize the threads
 *
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_ThreadsInitialize(void);


/**
 * @brief Start running threads on DSPSSS
 *
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_Start(void);


/**
 * @brief Stop running threads on DSPSS
 *
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_Stop(void);


/**
 * @brief Set calibration parameters
 *
 * @param[in] Id Thread id
 * @param[in] CalibrationParams Calibration information
 * @return Return DSPSS_StatusType error code
 */
DSPSS_StatusType DSPSS_ThreadsCalibrationSet(const DSPSS_ThreadIdType Id,
                                             const DSPSS_CFSDADC_CalibParamsType * CalibrationParams);


/**
 * @brief Get thread running status
 *
 * @param[in] Id Thread id
 * @return thread running status
 */
DSPSS_CFSDADC_ThreadStatusType DSPSS_ThreadsStatusGet(const DSPSS_ThreadIdType Id);


/**
 * @brief Read data from DSP-Core buffer
 *
 * @param[in] Id Thread id
 * @param[in] Length The length of data array
 * @param[out] Data Pointer to the values read from DSP-Core buffer
 * @return The actual number of values read from the buffer
 */
uint32 DSPSS_CoreBufferRead(const DSPSS_ThreadIdType Id,
                            const uint32 Length,
                            sint16 * const Data);


/**
 * @brief Flush output buffer to discard all the previous processed data.
 *
 * @param[in] Id Thread id
 * @param[in] TransferMethod The transfer type on output buffer (DMA or Core buffer)
 * @return void
 */
void DSPSS_FlushOutputBuffer(const DSPSS_ThreadIdType Id,
                             const DSPSS_TransferMethodType TransferMethod);


/*==================================================================================================
*                                       DSPSS threads
==================================================================================================*/

/**
 * @brief Start reset routine
 *
 * @return void
 */
void DSPSS_DspStartResetRoutine(void);


/**
 * @brief Assert reset
 *
 * @return void
 */
void DSPSS_DspAssertReset(void);



/**
 * @brief Program the scheduling sequence. Change of scheduling modes is possible only after the DSPSS reset.
 *
 * @param[in] SchedMode Scheduling mode
 * @param[in] SchdSeq Thread Sequence that will be scheduled in clock threshold mode.
 * @return void
 */
void DSPSS_ThreadSchedulingConfigure(DSPSS_SchedulingModeType SchedMode, const DSPSS_ThreadIdType* SchedSeq);


/**
 * @brief Program the scheduling to Sample Threshold mode. Change of scheduling modes is possible only after the DSPSS reset.
 *
 * @param[in] ContrlMode Controlling mode of thread scheduling.
 * @return void
 */
void DSPSS_ThreadSchedulingSampleThresholdMode(const DSPSS_NextReqHaltAckWaitModeType ContrlMode);


/**
 * @brief Program the scheduling to Clock Threshold mode. Change of scheduling modes is possible only after the DSPSS reset.
 *
 * @param[in] ContrlMode Controlling mode of thread scheduling.
 * @param[in] SchdSeq Thread Sequence that will be scheduled in clock threshold mode.
 * @return void
 */
void DSPSS_ThreadSchedulingClockThresholdMode(const DSPSS_NextReqHaltAckWaitModeType ContrlMode, const DSPSS_ThreadIdType* SchedSeq);

/**
 * @brief Program the PC_INIT values for every thread in Hardware scheduler of DSP sub-system.
 *
 * The PCINIT value for each of the thread should be in multiples of 8 PMEM locations.
 * @param[in] Id Thread id
 * @param[in] PCInit PC initial value for the threads of DSP-0
 * @return void
 */
void DSPSS_ThreadPCInitSet(const DSPSS_ThreadIdType Id,
                           const uint16 PCInit);


/**
 * @brief Program the start and end address memory location for respective threads in memory.
 *
 * Specifies the start and end addresses of the SDADC input buffer to write the SDADC data in the XMEM.
 * @param[in] Id Thread id that will be configured.
 * @param[in] StartAddress Start address for the thread in data memory.
 * @param[in] EndAddress End address (byte address aligned) location for the thread in data memory.
 * @return void
 */
void DSPSS_ThreadInputBufferConfigure(const DSPSS_ThreadIdType Id,
                                      const uint16 StartAddress,
                                      const uint16 EndAddress);


/**
 * @brief Set thread threshold
 *
 * @param[in] Id Thread id that will be configured.
 * @param[in] Threshold The number of ADC samples in sample mode, after which the corresponding DSP thread is scheduled for operation or
 *                  number of clock cycles for which a thread stays in operation in Clock-Cycle mode after which a new thread is scheduled.
 * @return void
 */
void DSPSS_ThreadThresholdSet(const DSPSS_ThreadIdType Id,
                              const uint16 Threshold);


/**
 * @brief Enable the thread.
 *
 * @param[in] Id Thread id.
 * @return void
 */
void DSPSS_ThreadEnable(const DSPSS_ThreadIdType Id);


/**
 * @brief Suspend the thread.
 *
 * @param[in] Id Thread id.
 * @return void
 */
void DSPSS_ThreadSuspend(const DSPSS_ThreadIdType Id);


/**
 * @brief Get the start address of output buffer.
 *
 * @param[in] Id Identifier of the thread.
 * @return Current start address of output buffer space inside XMEM.
 */
uint32 DSPSS_ThreadGetOutputBufferStart(const DSPSS_ThreadIdType Id);


/**
 * @brief Get the length in byte of output buffer.
 *
 * @param[in] Id Identifier of the thread.
 * @return length of the output buffer for the specific thread.
 */
uint32 DSPSS_ThreadGetOutputBufferLength(const DSPSS_ThreadIdType Id);


/*==================================================================================================
*                                       DSPSS_dsp_core_buffer
==================================================================================================*/

/**
 * @brief Configure the buffer address in XMEM by programming the start and end address
 *
 * and the read and write owners
 * @param[in] Id Identifier of the thread.
 * @param[in] StartAddr Start address of the DSP_CORE circular buffer.
 * @param[in] EndAddr End address of the DSP_CORE circular buffer.
 * @param[in] Owner Read and write owners of the buffers.
 * @return void
 */
void DSPSS_DspCoreBufferConfigure(const DSPSS_ThreadIdType Id,
                                  const uint16 StartAddr,
                                  const uint16 EndAddr,
                                  const DSPSS_DspCoreBufferOwnerType Owner);


/**
 * @brief Enable the DSP-Core buffer.
 *
 * @param[in] Id Identifier of the thread.
 * @return void
 */
void DSPSS_DspCoreBufferEnable(const DSPSS_ThreadIdType Id);


/**
 * @brief Disable the DSP-Core buffer.
 *
 * @param[in] Id Identifier of the thread.
 * @return void
 */
void DSPSS_DspCoreBufferDisable(const DSPSS_ThreadIdType Id);


/**
 * @brief Get the current read pointer
 *
 * @param[in] Id Identifier of the thread.
 * @return Current read pointer value of DSP_CORE buffer space inside XMEM.
 */
uint16 DSPSS_DspCoreBufferCurrReadPtrGet(const DSPSS_ThreadIdType Id);


/**
 * @brief Check overflow of write pointer inside DSP-CORE buffer
 *
 * @param[in] Id Identifier of the thread.
 * @return Overflow bit check.
 */
uint32 DSPSS_DspCoreBufferOverflowCheck(const DSPSS_ThreadIdType Id);


/**
 * @brief Clear overrflow bit
 *
 * @param[in] Id Identifier of the thread.
 * @return void
 */
void DSPSS_DspCoreBufferOverflowClear(const DSPSS_ThreadIdType Id);


/*==================================================================================================
*                                       DSPSS_interrupts
==================================================================================================*/

/**
 * @brief Enable an interrupt
 *
 * @param[in] Id Thread id
 * @param[in] InterruptMask Selected interrupts mask
 * @return void
 */
void DSPSS_InterruptEnable(const DSPSS_ThreadIdType Id,
                           const DSPSS_InterruptType InterruptMask);


/**
 * @brief Disable an interrupt
 *
 *
 * @param[in] Id Thread id
 * @param[in] InterruptMask Selected interrupts mask
 * @return void
 */
void DSPSS_InterruptDisable(const DSPSS_ThreadIdType Id,
                            const DSPSS_InterruptType InterruptMask);


/**
 * @brief Get the status flags
 *
 * @param[in] Id Thread id
 * @return State of the enabled interrupts of the thread
 */
uint32 DSPSS_GetInterruptEnable(const DSPSS_ThreadIdType Id);


/**
 * @brief Get the status flags
 *
 * @param[in] Id Thread id
 * @return State of the selected flags (include both DSPSS common and thread specific flags)
 */
uint32 DSPSS_GetStatusFlags(const DSPSS_ThreadIdType Id);


/**
 * @brief Clear the status flags
 *
 * @param[in] Id Thread id
 * @param[in] Mask Selected flags mask to clear (include both DSPSS common and thread specific flags)
 * @return void
 */
void DSPSS_ClearStatusFlags(const DSPSS_ThreadIdType Id,
                            const DSPSS_InterruptType Mask);


/*==================================================================================================
*                                       DSPSS_dma
==================================================================================================*/

/**
 * @brief Configure the dma read buffer
 *
 * @param[in] DmaChannel Dma channel id
 * @param[in] StartAddr Start address of the DMA_READ circular buffer.
 * @param[in] EndAddr End address of the DMA_READ circular buffer.
 * @return void
 */
void DSPSS_DmaReadBufferConfigure(const DSPSS_CFSDADC_DmaChannelType DmaChannel,
                                  const uint16 StartAddr,
                                  const uint16 EndAddr);


/**
 * @brief Enable the dma read buffer
 *
 * @param[in] DmaChannel Dma channel id
 * @return void
 */
void DSPSS_DmaReadBufferEnable(const DSPSS_CFSDADC_DmaChannelType DmaChannel);


/**
 * @brief Disable the dma read buffer
 *
 * @param[in] DmaChannel Dma channel id
 * @return void
 */
void DSPSS_DmaReadBufferDisable(const DSPSS_CFSDADC_DmaChannelType DmaChannel);


/**
 * @brief Check wrap status of the read pointer
 *
 * @param[in] DmaChannel Identifier of the DMA channel.
 * @return DMA-READ buffer wrap status check.
 */
boolean DSPSS_DmaReadBufferWrapPtrCheck(const DSPSS_CFSDADC_DmaChannelType DmaChannel);


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */


#ifdef __cplusplus
}
#endif

/** @} */
/** @endcond */

#endif  /* DSPSS_API_H */
