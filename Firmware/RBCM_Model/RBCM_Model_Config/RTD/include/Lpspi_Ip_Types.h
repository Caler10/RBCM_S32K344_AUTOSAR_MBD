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

#ifndef SPI_IP_TYPES_H
#define SPI_IP_TYPES_H

/**
*   @file    Lpspi_Ip_Types.h
*
*   @brief   LPSPI IP driver types header file.
*   @details LPSPI IP driver types header file.

*   @addtogroup LPSPI_DRIVER Lpspi Driver
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
#include "Lpspi_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_TYPES_VENDOR_ID                      43
#define LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define LPSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define LPSPI_IP_TYPES_SW_MAJOR_VERSION               5
#define LPSPI_IP_TYPES_SW_MINOR_VERSION               0
#define LPSPI_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lpspi_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Lpspi_Ip_Types.h header file and Lpspi_Ip_Cfg.h configuration header file are of the same vendor */
#if (LPSPI_IP_TYPES_VENDOR_ID != LPSPI_IP_VENDOR_ID_CFG)
    #error "Lpspi_Ip_Types.h and Lpspi_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if Lpspi_Ip_Types.h header file and Lpspi_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
    (LPSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Lpspi_Ip_Types.h and Lpspi_Ip_Cfg.h are different"
#endif
/* Check if Lpspi_Ip_Types.h header file and Lpspi_Ip_Cfg.h configuration header file are of the same software version */
#if ((LPSPI_IP_TYPES_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION_CFG) || \
    (LPSPI_IP_TYPES_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION_CFG) || \
    (LPSPI_IP_TYPES_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Lpspi_Ip_Types.h and Lpspi_Ip_Cfg.h are different"
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
/** @brief   Enum defining the possible events which triggers end of transfer callback.
*
* @implements Lpspi_Ip_EventType_enum
*/
typedef enum
{
    LPSPI_IP_EVENT_END_TRANSFER = 0, /**< The transfer is successfully done. */
    LPSPI_IP_EVENT_FAULT = 1         /**< The transfer failed due to overflow/underflow. */
} Lpspi_Ip_EventType;

/** @brief   Callback for all peripherals which supports SPI features. */
typedef void (*Lpspi_Ip_CallbackType)(uint8 Instance,
                                      Lpspi_Ip_EventType Event);

/** @brief   Enum defining the possible transfer modes.
*
* @implements Lpspi_Ip_ModeType_enum
*/
typedef enum
{
    LPSPI_IP_POLLING = 0, /**< For polling mode the application must call periodically Spi_Ip_ManageBuffers after asynchronous transfers. */
    LPSPI_IP_INTERRUPT   /**< For interrupt mode the application doesn't need to perform any additional operations after asynchronous transfers.
                            The application must enable the interrupt requests and install the right callbacks. */
} Lpspi_Ip_ModeType;

/** @brief   Enum defining the possible states of hardware unit.
* @implements Lpspi_Ip_HwStatusType_enum
*/
typedef enum
{
    LPSPI_IP_UNINIT = 0u, /**< Module is not initialized. */
    LPSPI_IP_IDLE = 1u, /**< Module is not used. */
    LPSPI_IP_BUSY = 2u,  /**< A transfer is in progress. */
    LPSPI_IP_FAULT = 3u  /**< During last transfer a fault occurred. */
} Lpspi_Ip_HwStatusType;

/** @brief   Enum defining the possible return types.
*
* @implements Lpspi_Ip_StatusType_enum
*/
typedef enum
{
    LPSPI_IP_STATUS_SUCCESS = 0u, /**< Successful operation. */
    LPSPI_IP_STATUS_FAIL    = 1u,/**< Failed operation. */
    LPSPI_IP_FIFO_ERROR     = 2u,/**< Overflow or underflow error. */
    LPSPI_IP_TIMEOUT        = 3u /**< Timeout error. */
} Lpspi_Ip_StatusType;

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
/** @brief   Enum defining the half duplex types.
*/
typedef enum
{
    LPSPI_IP_HALF_DUPLEX_TRANSMIT   = 0u,/**< Transmit only. */
    LPSPI_IP_HALF_DUPLEX_RECEIVE    = 1u,/**< Receive only. */
    LPSPI_IP_FULL_DUPLEX                 = 2u/**< Full duplex mode. */
} Lpspi_Ip_HalfDuplexType;
#endif

/** @brief   Structure defining some parameters often change of the spi bus. */
typedef struct
{
    uint16 FrameSize;   /**< Frame size configured */
    boolean Lsb;   /**< Transfer LSB first or MSB first */
    boolean ByteSwap;   /**< Enables byte swap on each 32-bit word when transmitting and receiving data */
    uint32 DefaultData; /**< Default data to send when TxBuffer is NULL_PTR */
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    Lpspi_Ip_HalfDuplexType TransferType;   /**< TransferType */
#endif
} Lpspi_Ip_DeviceParamsType;

/** @brief   Enum defining the transfer size.
*
*/
typedef enum
{
    LPSPI_IP_TRANSFER_SIZE_1_BYTE  = 0u,/**< Framesize <= 8 */
    LPSPI_IP_TRANSFER_SIZE_2_BYTE  = 1u,/**<  8 < Framesize <= 16 */
    LPSPI_IP_TRANSFER_SIZE_4_BYTE  = 2u,/**< 16 < Framesize <= 32 */
    LPSPI_IP_TRANSFER_SIZE_UNUNIT  = 3u /**< Uninitialised */
} Lpspi_Ip_TransferSize;

#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
typedef struct
{
    const uint8* NewTxBuffer;  /**< Store pointer for Tx buffer */
    uint8* NewRxBuffer;  /**< Store pointer for Tx buffer */
    uint16 NewDataLength; /**< Store new data length of next transfer */
    boolean StopTransfer; /**< Stop transfer imediately after current transfer or continue with next transfer */
} Lpspi_Ip_RepeatedTransferAttrType;

/** @brief   Enum defining the event of repeated transfer.
*
*/
typedef enum
{
    LPSPI_IP_REPEATED_TRANSFER_RECONFIGURE_START  = 0u,/**< Reconfiguring to prepare for new transfer starts*/
    LPSPI_IP_REPEATED_TRANSFER_RECONFIGURE_END  = 1u,/**<  Reconfiguring ends, ready to transfer */
} Lpspi_Ip_RepeatedTransferEventType;

/** @brief   Callback for DMA repeated transfer feature.
*
* @param        Instance - SPI peripheral instance number.
* @param        RepeatedTransferAttr - struct store current transfer attribute and can be changed to apply for next transfer.
*               RepeatedTransferAttr->NewTxBuffer: Store pointer for Tx buffer, not touching if unchanged
*               RepeatedTransferAttr->NewRxBuffer: Store pointer for Tx buffer, not touching if unchanged
*               RepeatedTransferAttr->NewDataLength: Store new data length of next transfer, not touching if unchanged
*               RepeatedTransferAttr->StopTransfer: Stop transfer imediately after current transfer or continue with next transfer, default is TRUE (Stop imediately)
*               Event: the event of repeated transfer.
*
*/
typedef void (*Lpspi_Ip_DmaRepeadtedTransferCallbackType)(uint8 Instance,
                                                          Lpspi_Ip_RepeatedTransferAttrType* RepeatedTransferAttr,
                                                          Lpspi_Ip_RepeatedTransferEventType Event);
#endif /* if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON) */
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */

/** @brief   Structure defining the parameters of the spi bus. */
typedef struct
{
    uint8 Instance; /**< Instance of the hardware unit. */
    uint32 Cfgr0;  /**< CFGR0 register contains HREQ configuration. */
   #if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
    uint32 Ccr[2u];    /**< CCR register which contains clocking and frame size configuration. */
    uint32 Tcr[2u];    /**< TCR register which contains clock polarities, frame size, which PCS and continuous mode. */
   #else
    uint32 Ccr;    /**< CCR register which contains clocking and frame size configuration. */
    uint32 Tcr;    /**< TCR register which contains clock polarities, frame size, which PCS and continuous mode. */
   #endif
   #if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    uint32 HalfDuplexCfgr1; /**< CFGR1 register which contains bit fields to support half duplex mode . */
   #endif
    Lpspi_Ip_DeviceParamsType * DeviceParams;  /**< Contain configuration for bit order, frame size, default transmit data. */
#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
    boolean RepeatedTransfer;
    Lpspi_Ip_DmaRepeadtedTransferCallbackType DmaRepeatedCallback;
#endif
#endif
} Lpspi_Ip_ExternalDeviceType;

#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*/
typedef enum
{
    LPSPI_IP_NORMAL_CLOCK = 0,        /**< @brief Clock reference is from SpiClockRef. */
    LPSPI_IP_ALTERNATE_CLOCK          /**< @brief Clock reference is from SpiAlternateClockRef. */
} Lpspi_Ip_DualClockModeType;
#endif

#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
/** @brief   Structure defining transmition command needed for Dma Fast transfer. */
typedef struct
{
    uint32 DmaFastTcrCmd;  /**< Contains transfer command for Dma Fast transfer. */
    uint32 DmaFastTcrCmdLast;  /**< Contains transfer command  and disable continuos mode for Dma Fast transfer. */
    uint32 DefaultData; /**< Default data to send when TxBuffer is NULL_PTR */
} Lpspi_Ip_CmdDmaFastType;

/** @brief   Structure defining information needed for Dma Fast transfer session.
 * @implements Lpspi_Ip_FastTransferType_struct
 */
typedef struct
{
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice; /**< Point to external device configuration */
    const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
    uint8* RxBuffer;  /**< Store pointer for Rx buffer */
    uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
    uint16 Length;  /**< Number of bytes to be sent */
    boolean KeepCs;  /**< Keep CS signal after transfer session completed */
} Lpspi_Ip_FastTransferType;
#endif /* if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) */
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */

typedef struct
{
    const uint8** TxBuffer;  /**< Store pointer for Tx buffer */
    uint16* TransferNumsByChannel;  /**< Store number of transfers for each channel */
    uint32 CurrentChannelIndex;
    uint16* ChannelNumsByJob;  /**< Store number of channels for each job */
    uint32 CurrentJobIndex;
    uint32 TotalNumberOfTransfer;
    uint32 TotalNumberOfChannel;
} Lpspi_Ip_TxBufferListType;
/** @brief   Structure defining information needed for SPI driver initialization. */
typedef struct
{
    uint8 Instance; /**< Instance of the hardware unit. */
    uint32 Cr;     /**< It contains only debug enable. */
    uint32 Cfgr1;  /**< It contains PCS polarities. */
   #if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    boolean SlaveMode;
   #endif
   #if (LPSPI_IP_DMA_USED == STD_ON)
    boolean DmaUsed;   /**< DMA is used or not */
    uint8 TxDmaChannel;     /**< Id of TX DMA channel for transmition */
    uint8 RxDmaChannel;     /**< Id of RX DMA channel for receive */
   #if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    uint8 MaxNumOfFastTransfer; /**< Maximum number of transfers in Dma Fast */
    Lpspi_Ip_CmdDmaFastType *CmdDmaFast; /**< Point to list of TCR command used in Dma Fast transfer */
    uint8 NumberTxSG; /**< Number of TCD Scatter Gather for Tx DMA channel used in Dma Fast transfer */
    uint8 NumberRxSG; /**< Number of TCD Scatter Gather for Rx DMA channel used in Dma Fast transfer */
    const uint8 *TxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Tx DMA channel used in Dma Fast transfer */
    const uint8 *RxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Rx DMA channel used in Dma Fast transfer */
   #endif
   #endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
    Lpspi_Ip_ModeType TransferMode; /**< Transfer mode for HWunit */
    uint8 StateIndex; /**< State of current transfer  */
   #if (LPSPI_IP_DMA_USED == STD_ON)
    boolean TcdConfigOptimize; /**< If channels in HWunit are the same framesize. */
    uint8 TcdConfigOptimizeFrameSize; /**< Framesize of channels */
   #endif
} Lpspi_Ip_ConfigType;

/** @brief   Structure defining information needed for internal state of the driver. */
typedef struct
{
   #if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
    Lpspi_Ip_DualClockModeType ClockMode; /**< Store current clock mode for HWunit */
   #endif
    Lpspi_Ip_ModeType TransferMode; /**< Store current transfer mode for HWunit */
    Lpspi_Ip_HwStatusType Status; /**< 0 = available, 1 = busy, 2 = fail due to overflow or underflow */
    uint8* RxBuffer; /**< Store pointer for Rx buffer */
    const uint8* TxBuffer; /**< Store pointer for Tx buffer */
    Lpspi_Ip_CallbackType Callback; /**< Store pointer for call back function */
    uint16 RxIndex; /**< Store current Rx index to receive data in Rx buffer */
    uint16 TxIndex; /**< Store current Tx index to transmit data in Tx buffer */
    uint16 ExpectedFifoReads;   /**< Store number of frames needs to be receive for current transfer */
    uint16 ExpectedFifoWrites;  /**< Store number of frames needs to be transmit for current transfer */
    boolean KeepCs;  /**< Keep CS signal after tranfers completed. */
    boolean FirstCmd;
    const Lpspi_Ip_ConfigType *PhyUnitConfig;
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice;
    boolean TxLsb;  /**< Transfer LSB first or MSB first */
    uint8 CurrentTxFifoSlot;  /**< Number of TX FIFO slots are current available. */
   #if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    uint32 HalfDuplexTcrCommand;  /**< Save the value which will be written to TCR register in DMA mode */
    boolean NextChannelIsRX;  /**< Save the value which will be written to TCR register in DMA mode */
    boolean IsPreChanneHalfDuplexlRxMode;  /**< If previous channel is in RX mode */
   #endif
    boolean TxDoneFlag;  /**< Flag to check TX is done */
   #if (LPSPI_IP_DMA_USED == STD_ON)
    uint8 TxSrcSignedOffsetValue; /**< Save TX DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
    uint8 RxDesSignedOffsetValue; /**< Save RX DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET */
    uint16 PreTxMajorLoopCount; /**< Save major loop counter of previous channel */
    uint16 PreRxMajorLoopCount; /**< Save major loop counter of previous channel */
    boolean IsPreTxBufferNull; /**< TX buffer os previous channel is null */
    boolean IsPreRxBufferNull; /**< RX buffer os previous channel is null */
    Lpspi_Ip_TransferSize PreTxTransferSize; /**< FrameSize of previous TX channel */
    Lpspi_Ip_TransferSize PreRxTransferSize; /**< FrameSize of previous TX channel */
   #endif
   #if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    boolean IsPreTransferInDmaFastMode; /**<  Flag to identify is previous transfer DMA fast mode */
   #endif
   #if (LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)
    boolean IsCurrTransferInDmaContMemMode; /**<  Flag to identify is previous transfer DMA fast mode */
    Lpspi_Ip_TxBufferListType *ContMemTransferCfg;
   #endif
#ifdef ERR_IPV_LPSPIV2_E050456
#ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION
    boolean TxFifoResetNeeded;
#endif
#endif
#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
    boolean RepeatedTransfer;
    Lpspi_Ip_RepeatedTransferAttrType* RepeatedTransferAttr;
    Lpspi_Ip_DmaRepeadtedTransferCallbackType DmaRepeatedCallback;
#endif
#endif
} Lpspi_Ip_StateStructureType;

typedef struct
{
    /* Keep CS asserted after the next transfer */
    boolean KeepCs;
    /* When multiple consecutive transfers have the same time delay or KeepCs is used
     * between them, set to true for the first one and to false for the remaining ones
     * to improve performance */
    boolean FirstCmd;
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    /* For consecutive Half Duplex TX transfers, if set to True before each TX transfer
     * will avoid waiting for the TX Fifo to be drained. */
    boolean NextHalfDuplexIsTX;
#endif
} Lpspi_Ip_TransferAdjustmentType;

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

#endif /*LPSPI_IP_TYPES*/
