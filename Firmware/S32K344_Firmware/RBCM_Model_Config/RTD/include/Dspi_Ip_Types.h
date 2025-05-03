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

#ifndef DSPI_IP_TYPES_H
#define DSPI_IP_TYPES_H

/**
*   @file    Dspi_Ip_Types.h
*
*   @brief   DSPI IP driver types header file.
*   @details DSPI IP driver types header file.

*   @addtogroup DSPI_IP_DRIVER Dspi Ip Driver
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
#include "Std_Types.h"
#include "Dspi_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_IP_TYPES_VENDOR_ID                      43
#define DSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define DSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define DSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define DSPI_IP_TYPES_SW_MAJOR_VERSION               5
#define DSPI_IP_TYPES_SW_MINOR_VERSION               0
#define DSPI_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((DSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (DSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dspi_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Dspi_Ip_Types.h header file and Dspi_Ip_Cfg.h configuration header file are of the same vendor */
#if (DSPI_IP_TYPES_VENDOR_ID != DSPI_IP_VENDOR_ID_CFG)
    #error "Dspi_Ip_Types.h and Dspi_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if Dspi_Ip_Types.h header file and Dspi_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((DSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (DSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
    (DSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != DSPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Dspi_Ip_Types.h and Dspi_Ip_Cfg.h are different"
#endif
/* Check if Dspi_Ip_Types.h header file and Dspi_Ip_Cfg.h configuration header file are of the same software version */
#if ((DSPI_IP_TYPES_SW_MAJOR_VERSION != DSPI_IP_SW_MAJOR_VERSION_CFG) || \
    (DSPI_IP_TYPES_SW_MINOR_VERSION != DSPI_IP_SW_MINOR_VERSION_CFG) || \
    (DSPI_IP_TYPES_SW_PATCH_VERSION != DSPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Dspi_Ip_Types.h and Dspi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == DSPI_IP_ENABLE)
/** @brief   Enum defining the possible events which triggers end of transfer callback.
*
* @implements Dspi_Ip_EventType_enum
*/
typedef enum
{
    DSPI_IP_EVENT_END_TRANSFER = 0, /**< The transfer is successfully done. */
    DSPI_IP_EVENT_FAULT = 1         /**< The transfer failed due to overflow/underflow. */
} Dspi_Ip_EventType;

/** @brief   Callback for all peripherals which supports SPI features. */
typedef void (*Dspi_Ip_CallbackType)(uint8 Instance,
                                     Dspi_Ip_EventType Event);

/** @brief   Enum defining the possible transfer modes.
*
* @implements Dspi_Ip_ModeType_enum
*/
typedef enum
{
    DSPI_IP_POLLING = 0, /**< For polling mode the application must call periodically Dspi_Ip_ManageBuffers after asynchronous transfers. */
    DSPI_IP_INTERRUPT   /**< For interrupt mode the application doesn't need to perform any additional operations after asynchronous transfers.
                            The application must enable the interrupt requests and install the right callbacks. */
} Dspi_Ip_ModeType;

/** @brief   Enum defining the possible states of hardware unit.
 * @implements Dspi_Ip_HwStatusType_enum
*/
typedef enum
{
    DSPI_IP_UNINIT = 0u, /**< Module is not initialized. */
    DSPI_IP_IDLE = 1u, /**< Module is not used. */
    DSPI_IP_BUSY = 2u,  /**< A transfer is in progress. */
    DSPI_IP_FAULT = 3u  /**< During last transfer a fault occurred. */
} Dspi_Ip_HwStatusType;

/** @brief   Enum defining the possible return types.
*
* @implements Dspi_Ip_StatusType_enum
*/
typedef enum
{
    DSPI_IP_STATUS_SUCCESS = 0u, /**< Successful operation. */
    DSPI_IP_STATUS_FAIL    = 1u,/**< Failed operation. */
    DSPI_IP_FIFO_ERROR     = 2u,/**< Overflow or underflow error. */
    DSPI_IP_TIMEOUT        = 3u /**< Timeout error. */
} Dspi_Ip_StatusType;

/** @brief   Structure defining some parameters often change of the spi bus. */
typedef struct
{
    uint8 FrameSize;   /**< Frame size configured */
    boolean Lsb;   /**< Transfer LSB first or MSB first */
    uint32 DefaultData; /**< Default data to send when TxBuffer is NULL_PTR */
} Dspi_Ip_DeviceParamsType;

/** @brief   Structure defining the parameters of the spi bus. */
typedef struct
{
    uint8 Instance; /**< Instance of the hardware unit. */
   #if (DSPI_IP_DUAL_CLOCK_MODE == STD_ON)
    uint32 Ctar[2u];        /**< CTAR register which contains clocking and frame size configuration. */
   #else
    uint32 Ctar;        /**< CTAR register which contains clocking and frame size configuration. */
   #endif
    uint32 Ctare;       /**< CTARE registers which contains frame size configuration. */
    uint16 PushrCmd;    /**< PUSHR CMD Fifo register which contains CS and continuos mode. */
    Dspi_Ip_DeviceParamsType * DeviceParams; /**< Contain configuration for bit order, frame size, default transmit data. */
} Dspi_Ip_ExternalDeviceType;

#if (DSPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*/
typedef enum
{
    DSPI_IP_NORMAL_CLOCK = 0,        /**< @brief Clock reference is from SpiClockRef. */
    DSPI_IP_ALTERNATE_CLOCK          /**< @brief Clock reference is from SpiAlternateClockRef. */
} Dspi_Ip_DualClockModeType;
#endif

#if ((DSPI_IP_DMA_USED == STD_ON) && (DSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
/** @brief   Structure defining transmition command needed for Dma Fast transfer. */
typedef struct
{
    uint16 DmaFastPushrCmd;  /**< PUSHR CMD Fifo register which contains CS and continuos mode. */
    uint16 DmaFastPushrCmdLast;  /**< PUSHR CMD Fifo register which contains CS and disable continuos mode. */
    uint32 DefaultData; /**< Default data to send when TxBuffer is NULL_PTR */
} Dspi_Ip_CmdDmaFastType;

/** @brief   Structure defining information needed for Dma Fast transfer session.
* @implements Dspi_Ip_FastTransferType_struct
*/
typedef struct
{
    const Dspi_Ip_ExternalDeviceType *ExternalDevice; /**< Point to external device configuration */
    const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
    uint8* RxBuffer;  /**< Store pointer for Rx buffer */
    uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
    uint16 Length;  /**< Number of bytes to be sent */
    boolean KeepCs;  /**< Keep CS signal after transfer session completed */
} Dspi_Ip_FastTransferType;
#endif /* if ((DSPI_IP_DMA_USED == STD_ON) && (DSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)) */

/** @brief   Structure defining information needed for SPI driver initialization. */
typedef struct
{
    uint8 Instance; /**< Instance of the hardware unit. */
    uint32 Mcr; /**< Select master/slave. */
   #if (DSPI_IP_SLAVE_SUPPORT == STD_ON)
    boolean SlaveMode;
   #endif
   #if (DSPI_IP_DMA_USED == STD_ON)
    boolean DmaUsed;   /**< DMA is used or not */
    uint8 TxDmaChannel;     /**< Id of TX DMA channel for transmition */
    uint8 TxCmdDmaChannel;     /**< Id of CMD DMA channel for transmition */
    uint8 NumTxCmdDmaSGId; /**< Number of TCD Scatter Gather for CMD DMA channel */
    const uint8 *TxCmdDmaSGId;   /**< Point to list of TCD Scatter Gather Id for CMD DMA channel */
    uint8 RxDmaChannel;     /**< Id of RX DMA channel for receive */
   #if (DSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    uint8 MaxNumOfFastTransfer; /**< Maximum number of transfers in Dma Fast */
    Dspi_Ip_CmdDmaFastType *CmdDmaFast; /**< Point to list of PUSH command used in Dma Fast transfer */
    uint8 NumberRxSG; /**< Number of TCD Scatter Gather for Rx DMA channel used in Dma Fast transfer */
    const uint8 *TxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Tx DMA channel used in Dma Fast transfer */
    const uint8 *RxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Rx DMA channel used in Dma Fast transfer */
   #endif
   #endif /* if (DSPI_IP_DMA_USED == STD_ON) */
    Dspi_Ip_ModeType TransferMode; /**< Transfer mode for HWunit */
    uint8 StateIndex; /**< State of current transfer  */
} Dspi_Ip_ConfigType;

/** @brief   Structure defining information needed for internal state of the driver. */
typedef struct
{
   #if (DSPI_IP_DUAL_CLOCK_MODE == STD_ON)
    Dspi_Ip_DualClockModeType ClockMode; /**< Store current clock mode for HWunit */
   #endif
    Dspi_Ip_ModeType TransferMode; /**< Store current transfer mode for HWunit */
    Dspi_Ip_HwStatusType Status; /**< 0 = available, 1 = busy, 2 = fail due to overflow or underflow */
    uint8* RxBuffer; /**< Store pointer for Rx buffer */
    const uint8* TxBuffer; /**< Store pointer for Tx buffer */
    Dspi_Ip_CallbackType Callback; /**< Store pointer for call back function */
    uint16 RxIndex; /**< Store current Rx index to receive data in Rx buffer */
    uint16 TxIndex; /**< Store current Tx index to transmit data in Tx buffer */
    uint16 ExpectedFifoReads;   /**< Store number of frames needs to be receive for current transfer */
    uint16 ExpectedFifoWrites;  /**< Store number of frames needs to be transmit for current transfer */
    uint16 ExpectedCmdFifoWrites;  /**< Store number of frames needs to be transmit for current transfer */
    uint16 PushrCmd;  /**< PUSHR CMD Fifo register which contains CS and continuos mode. */
    boolean KeepCs;  /**< Keep CS signal after tranfers completed. */
    uint16 CurrentTxFifoSlot; /**< Number of TX FIFO slots are current available. */ uint16 Pushr0Repeat;     /**< Number of times to write
                                                                                                               * PushrCmds[0] to FIFO >*/
    uint16 Pushr0RepeatIndex; /**< Counter for Pushr0Repeat >*/
    uint16 PushrCmds[3]; /**< Pushr Cmds to be written to FIFO >*/
    uint16 DTCPValue[3]; /**< Values of DTCP to be written in CTARE0-3 >*/
    uint16 NbCmds; /**< Number of different Cmds >*/
    uint16 NbCmdsIndex; /**< Counter for NbCmds >*/
    const Dspi_Ip_ConfigType *PhyUnitConfig;
    const Dspi_Ip_ExternalDeviceType *ExternalDevice;
} Dspi_Ip_StateStructureType;

typedef struct
{
    /* Keep CS asserted after the next transfer */
    boolean KeepCs;
    Dspi_Ip_DeviceParamsType *DeviceParams; /**< Device params to be updated. If null, device params are not updated */
} Dspi_Ip_TransferAdjustmentType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#endif /*(STD_ON == DSPI_IP_ENABLE)*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*DSPI_IP_TYPES*/
