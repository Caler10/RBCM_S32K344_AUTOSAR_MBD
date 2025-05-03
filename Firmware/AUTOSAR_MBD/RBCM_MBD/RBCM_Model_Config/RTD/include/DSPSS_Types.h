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

/*!
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */


#ifndef DSPSS_TYPES_H
#define DSPSS_TYPES_H

/** @cond DRIVER_INTERNAL_USE_ONLY */

/**
*   @file DSPSS_Types.h
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
#include "Sdadc_Ip_CfgDefines.h"
#include "DSPSS_CFSDADC_MemoryMap.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DSPSS_VENDOR_ID_TYPES                      43
#define DSPSS_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define DSPSS_AR_RELEASE_MINOR_VERSION_TYPES       7
#define DSPSS_AR_RELEASE_REVISION_VERSION_TYPES    0
#define DSPSS_SW_MAJOR_VERSION_TYPES               5
#define DSPSS_SW_MINOR_VERSION_TYPES               0
#define DSPSS_SW_PATCH_VERSION_TYPES               0

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if DSPSS_Types.h file and Sdadc_Ip_CfgDefines.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_TYPES != SDADC_IP_VENDOR_ID_CFGDEFINES)
    #error "DSPSS_Types.h and Sdadc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if DSPSS_Types.h file and Sdadc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_TYPES != SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_TYPES != SDADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_TYPES != SDADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of DSPSS_Types.h and Sdadc_Ip_CfgDefines.h are different"
#endif

/* Check if DSPSS_Types.h file and Sdadc_Ip_CfgDefines.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_TYPES != SDADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (DSPSS_SW_MINOR_VERSION_TYPES != SDADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (DSPSS_SW_PATCH_VERSION_TYPES != SDADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of DSPSS_Types.h and Sdadc_Ip_CfgDefines.h are different"
#endif

/* Check if DSPSS_Types.h file and DSPSS_CFSDADC_MemoryMap.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_TYPES != DSPSS_VENDOR_ID_CFSADC_MEMORYMAP)
    #error "DSPSS_Types.h and DSPSS_CFSDADC_MemoryMap.h have different vendor ids"
#endif

/* Check if DSPSS_Types.h file and DSPSS_CFSDADC_MemoryMap.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_TYPES != DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_MEMORYMAP) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_TYPES != DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_MEMORYMAP) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_TYPES != DSPSS_AR_RELEASE_REVISION_VERSION_CFSADC_MEMORYMAP) \
    )
    #error "AutoSar Version Numbers of DSPSS_Types.h and DSPSS_CFSDADC_MemoryMap.h are different"
#endif

/* Check if DSPSS_Types.h file and DSPSS_CFSDADC_MemoryMap.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_TYPES != DSPSS_SW_MAJOR_VERSION_CFSADC_MEMORYMAP) || \
     (DSPSS_SW_MINOR_VERSION_TYPES != DSPSS_SW_MINOR_VERSION_CFSADC_MEMORYMAP) || \
     (DSPSS_SW_PATCH_VERSION_TYPES != DSPSS_SW_PATCH_VERSION_CFSADC_MEMORYMAP) \
    )
  #error "Software Version Numbers of DSPSS_Types.h and DSPSS_CFSDADC_MemoryMap.h are different"
#endif

/*==================================================================================================
 *                                        DEFINITIONS
 ==================================================================================================*/

/* Dev assert */
#define DSPSS_DEV_ASSERT SDADC_IP_DEV_ASSERT


#define DSPSS_CHK_BIT(var, pos)                    (  (var) &    (1UL    << (pos)) )
#define DSPSS_SET_BIT(var, pos)                    (  (var) |=   (1UL    << (pos)) )
#define DSPSS_GET_BIT(var, pos)                    ( ((var) >>   (pos))  & 1UL     )
#define DSPSS_CLR_BIT(var, pos)                    (  (var) &= ~((1UL)   << (pos)) )
#define DSPSS_TGL_BIT(var, pos)                    (  (var) ^=   (1UL    << (pos)) )


#define DSPSS_CHK_BITS(var, pos, width)            (  (var) &   (((1UL   << (width)) - 1UL) << (pos)) )
#define DSPSS_SET_BITS(var, pos, width, bits)      (  (var) |=  ((bits)  << (pos))                    )
#define DSPSS_GET_BITS(var, pos, width)            ( ((var) >>  (pos)) & ((1UL << (width)) - 1UL)     )
#define DSPSS_CLR_BITS(var, pos, width)            (  (var) &= ~(((1UL   << (width)) - 1UL) << (pos)) )


/**
 * Maximum number of taps for filters
 */
#define DSPSS_CFSDADC_MAX_FIR_SIZE                   (128U)     /**< Maximum number of taps for FIR filter */
#define DSPSS_CFSDADC_MAX_IIR_SIZE                   (5U)       /**< Maximum number of taps for IIR filter */


/*==================================================================================================
*                                       DSPSS_CFSDAD
==================================================================================================*/

/**
 * Enumeration identifying the thread status.
 */
#define DSPSS_CFSDADC_STATUS_INACTIVE                      0x0000U
#define DSPSS_CFSDADC_STATUS_CONFIGURED                    0x0001U
#define DSPSS_CFSDADC_STATUS_INITIALIZED                   0x0002U
#define DSPSS_CFSDADC_STATUS_RUNNING                       0x0004U
#define DSPSS_CFSDADC_STATUS_SUSPENDED                     0x0008U
#define DSPSS_CFSDADC_STATUS_INVALID_PARAMETER             0x0010U
#define DSPSS_CFSDADC_STATUS_INPUT_BUFFER_OVERFLOW         0x0020U
#define DSPSS_CFSDADC_STATUS_OUTPUT_BUFFER_OVERFLOW        0x0040U
#define DSPSS_CFSDADC_STATUS_ERRORS                        0x8000U

typedef uint16 DSPSS_CFSDADC_ThreadStatusType;


/**
 * Enumeration identifying the configuration message status.
 */
#define DSPSS_CFSDADC_PARAMS_IDLE                          0U
#define DSPSS_CFSDADC_PARAMS_SET                           1U

typedef uint16 DSPSS_CFSDADC_ConfigMessageType;


/**
 * Enumeration identifying the different DMA channels.
 */
#define DSPSS_DMA_NONE                                    -1
#define DSPSS_DMA_CHANNEL0                                 0
#define DSPSS_DMA_CHANNEL1                                 1
#define DSPSS_DMA_CHANNEL2                                 2
#define DSPSS_DMA_CHANNEL3                                 3
#define DSPSS_DMA_CHANNEL4                                 4
#define DSPSS_DMA_CHANNEL5                                 5
#define DSPSS_DMA_NUM                                      6

typedef sint16 DSPSS_CFSDADC_DmaChannelType;


/**
 * Enumeration identifying the different optimization levels.
 */
#define DSPSS_CFSDADC_OPTIMIZATION_NONE                    0U
#define DSPSS_CFSDADC_OPTIMIZATION_LEVEL_1                 1U

typedef uint16 DSPSS_CFSDADC_OptimizationLevelType;


/**
 * FIR filter config filled by M7, interpreted and managed by CoolFlux
 */
typedef struct
{
    DSPSS_CFSDADC_OptimizationLevelType    OptimizationLevel;                 /**< Optimization level for different filters */
    uint16                                 UpsamplingFactor;                  /**< Upsampling factor: 1 (no upsampling) or 2 */
    uint16                                 DownsamplingFactor;                /**< Downsampling factor */
    uint16                                 NbTaps;                            /**< Nr of taps*/
    sint16                                 Taps[DSPSS_CFSDADC_MAX_FIR_SIZE];  /**< Taps array */
} DSPSS_CFSDADC_FIRParamsType;


/**
 * IIR filter config filled by M7, interpreted and managed by CoolFlux
 */
typedef struct
{
    uint16    Order;                                /**< Current usecase is 2nd order, biquad */
    uint16    Shift;
    sint16    Taps[DSPSS_CFSDADC_MAX_IIR_SIZE];     /**< Taps array */
    uint16    Padd;                                 /**< Padding for alignment */
} DSPSS_CFSDADC_IIRParamsType;


/**
 * Calibration config filled by M7, interpreted and managed by CoolFlux
 */
typedef struct
{
    sint16    UseCalibration;     /**< Flag indicating the calibration is used or not */
    sint16    Gain;               /**< Calibration gain */
    sint32    Offset;             /**< Calibration offset */
} DSPSS_CFSDADC_CalibParamsType;


/**
 * Parameters for standard filtering using FIR, IIR and calibration
 */
typedef struct
{
    DSPSS_CFSDADC_FIRParamsType      FirParams;           /**< FIR filter configuration */
    DSPSS_CFSDADC_IIRParamsType      IirParams;           /**< IIR filter configuration */
    DSPSS_CFSDADC_CalibParamsType    CalibParams;         /**< Calibration configuration */
    uint16                           NbSkippedSamples;    /**< Number of sampled skipped for filter processing */
    uint16                           Padd;                /**< Padding for alignment */
} DSPSS_CFSDADC_StandardParamsType;


/**
 * Thread parameters specific to each use-case
 */
typedef struct
{
    DSPSS_CFSDADC_StandardParamsType    StandardParams;                    /**< Standard parameters */
} DSPSS_CFSDADC_ThreadParamsType;


/**
 * Type definition that contains the thread configuration.
 */
typedef struct
{
    volatile DSPSS_CFSDADC_ThreadStatusType   Status;              /**< Thread status */
    volatile DSPSS_CFSDADC_ConfigMessageType  ConfigMessage;       /**< Thread message for parameter configuration */
    volatile uint16                           Counter;             /**< Thread running counter */

    DSPSS_CFSDADC_DmaChannelType              InputDMAChannel;     /**< Specifies usage of DMA channel for SDASC */
    DSPSS_CFSDADC_DmaChannelType              OutputDMAChannel;    /**< Specifies usage of DMA channel or Core buffer on output */

    uint16                                    EntryPoint;          /**< PC initial value for thread */
    uint16                                    Stack;               /**< Thread stack */

    uint16                                    InputThreshold;      /**< The number of samples used for thread threshold (to schedule a thread) */
    uint16                                    BufferInputStart;    /**< Start address for the thread in data memory. */
    uint16                                    BufferInputLength;   /**< Size in bytes of the input buffer for the thread in data memory */

    uint16                                    OutputThreshold;     /**< The number of samples to be transferred/provided in the minor loop (to generate transfer request - OVF event) */
    uint16                                    BufferOutputStart;   /**< Start address for circular buffer used for filter output data */
    uint16                                    BufferOutputLength;  /**< Size in bytes of the circular buffer used for filter output data */

    uint16                                    CoreMsgQueueStart;   /**< Start address for circular buffer used for DSP-HOST communication */
    uint16                                    CoreMsgQueueLength;  /**< Size in bytes of the circular buffer used for DSP-HOST communication */

    uint16                                    WorkAreaStart;       /**< Area for filter state, scratch buffers */
    uint16                                    WorkAreaLength;      /**< Size in bytes of the area for filter state, scratch buffers */

    uint16                                    Padd;                /**< Padding for alignment */
    DSPSS_CFSDADC_ThreadParamsType            ThreadParams;        /**< Thread parameters specific to each use-case */
} DSPSS_CFSDADC_ThreadDescriptorType;


/*==================================================================================================
*                              TYPEDEFS (STRUCTURES, ENUMS)
==================================================================================================*/

/**
 * Enumeration values for the different scheduling mode
 */
#define DSPSS_SAMPLE_THRESHOLD_MODE                        0UL
#define DSPSS_CLOCK_THRESHOLD_MODE                         1UL
#define DSPSS_SOFTWARE_SCHEDULING_MODE                     2UL

typedef uint32 DSPSS_SchedulingModeType;


/**
 * Enumeration identifying the different controlling modes of thread scheduling in sample threshold mode.
 */
#define DSPSS_HALT_ACK_WAIT                                0UL
#define DSPSS_HALT_ACK_NO_WAIT                             1UL

typedef uint32 DSPSS_NextReqHaltAckWaitModeType;


/**
 * Enumeration values for the read and write pointer owners of DSP-Core buffer
 */
#define DSPSS_M7_WRITE_OWNER                               0UL
#define DSPSS_DSP_WRITE_OWNER                              1UL

typedef uint32 DSPSS_DspCoreBufferOwnerType;

typedef uint32 DSPSS_ThreadIdType;


/**
 * Enumeration identifying the different transfer types.
 * NOTE: For input all three are possible
 *       For output only first and third are possible
 */
#define DSPSS_TRANSFER_DMA                                 0UL
#define DSPSS_TRANSFER_SDADC                               1UL
#define DSPSS_TRANSFER_CORE_BUFFER                         2UL

typedef uint32 DSPSS_TransferMethodType;


/**
 * Enumeration values for return codes
 */
#define DSPSS_OK                                           0UL
#define DSPSS_SW_ERR                                       1UL
#define DSPSS_HW_ERR                                       2UL
#define DSPSS_TIMEOUT                                      3UL

typedef uint32 DSPSS_StatusType;


/**
 * Enumeration values for the different interrupt type.
 */
/* Interrupt 1 (thread specific interrupts) */
#define DSPSS_DSP_ERROR_INTR_ENABLE                        (1UL << 0UL)    /* DSP firmware detects internal DSP ERROR */
#define DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE             (1UL << 1UL)    /* Address mismatch error in DMA read buffer */
#define DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE              (1UL << 2UL)    /* Address mismatch error in DMA write buffer */
#define DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE         (1UL << 3UL)    /* Unaligned DMA access error in DMA write buffer */
#define DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE          (1UL << 4UL)    /* Unaligned DMA access error in DMA read buffer */

/* Interrupt 2 (thread specific interrupts) */
#define DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE         (1UL << 5UL)    /* Overflow in DSP Cortex-M7 core buffer */
#define DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE         (1UL << 6UL)    /* Underrun in DSP Cortex-M7 core buffer */
#define DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE         (1UL << 7UL)    /* SDADC async FIFO overflow error */

/* Interrupt 2 (DSP common interrupts) */
#define DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE              (1UL << 8UL)    /* DSP ACK timeout error */
#define DSPSS_DSP_INIT_LOW_INTR_ENABLE                     (1UL << 9UL)    /* DSP initialization error */
#define DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE     (1UL << 10UL)   /* Request FIFO overflow error */
#define DSPSS_REQ_FIFO_ERR_INTR_ENABLE                     (1UL << 11UL)   /* Request FIFO threshold crossing */

/* All error interrupts/flags */
#define DSPSS_ERROR_INTERRUPT_ALL                         (DSPSS_DSP_ERROR_INTR_ENABLE | \
                                                           DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE | \
                                                           DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE | \
                                                           DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE | \
                                                           DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE | \
                                                           \
                                                           DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE | \
                                                           DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE | \
                                                           DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE | \
                                                           \
                                                           DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE | \
                                                           DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE | \
                                                           DSPSS_REQ_FIFO_ERR_INTR_ENABLE)

/* Error interrupt 1 */
#define DSPSS_INTERRUPT_1_FLAGS                           (DSPSS_DSP_ERROR_INTR_ENABLE | \
                                                           DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE | \
                                                           DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE | \
                                                           DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE | \
                                                           DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE)

/* Error interrupt 2 */
#define DSPSS_INTERRUPT_2_FLAGS                           (DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE | \
                                                           DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE | \
                                                           DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE | \
                                                           DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE | \
                                                           DSPSS_DSP_INIT_LOW_INTR_ENABLE | \
                                                           DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE | \
                                                           DSPSS_REQ_FIFO_ERR_INTR_ENABLE)

typedef uint32 DSPSS_InterruptType;


#if (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON)

/*!
 * @brief Defines the dspss error notification
 *
 * This is used for error notification callback.
 * Events will contain flags which triggered the interrupt.
 */
typedef void DSPSS_ErrorNotificationType(const uint32 Events);

#endif /* (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON) */

/**
 * Type definition that contains the thread configuration set by M7.
 */
typedef struct
{
    DSPSS_SchedulingModeType          SchedMode;              /**< Thread scheduling mode */
    uint16                            InputThreshold;         /**< The number of samples used for thread threshold */
    uint16                            OutputThreshold;        /**< The number of samples to be transferred/provided in the minor loop */
    uint16                            BufferOutputLength;     /**< Size in bytes of the circular buffer used for filter output data */
    DSPSS_DspCoreBufferOwnerType      Owner;                  /**< Read and write pointer owners of DSP-Core buffer */
    DSPSS_TransferMethodType          InputTransferMethod;    /**< Specifies usage of DMA or SDADC transfer to the input buffer */
    DSPSS_TransferMethodType          OutputTransferMethod;   /**< Specifies usage of DMA or Core buffer transfer on output buffer */
    DSPSS_CFSDADC_ThreadParamsType    ThreadParams;
    DSPSS_ThreadIdType                SchedOrder[DSPSS_THREAD_NUM];         /**< Specifies the thread order to be scheduled in Clock Threshold mode. */
#if (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON)
    DSPSS_ErrorNotificationType     * ErrorNotification;      /**< Callback function to be called when DSPSS encounters error during processing */
#endif /* (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON) */
} DSPSS_ThreadConfigType;


#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
/** @endcond */

#endif  /* DSPSS_TYPES_H */
