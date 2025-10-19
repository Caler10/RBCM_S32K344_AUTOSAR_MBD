/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
*   only be used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
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
#include "Lpi2c_Ip_HwAccess.h"
#include "Lpi2c_Ip_Features.h"
#include "OsIf.h"
#include "Lpi2c_Ip.h"
#include "SchM_I2c.h"

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
    #include "Dma_Ip.h"
#endif /* (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE) */

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == LPI2C_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_VENDOR_ID_C                      43
#define LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define LPI2C_IP_AR_RELEASE_MINOR_VERSION_C       7
#define LPI2C_IP_AR_RELEASE_REVISION_VERSION_C    0
#define LPI2C_IP_SW_MAJOR_VERSION_C               5
#define LPI2C_IP_SW_MINOR_VERSION_C               0
#define LPI2C_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpi2c_Ip.h */
#if (LPI2C_IP_VENDOR_ID_C !=  LPI2C_IP_VENDOR_ID)
    #error "Lpi2c_Ip.c and Lpi2c_Ip.h have different vendor ids"
#endif
#if (( LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C    !=  LPI2C_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_MINOR_VERSION_C    !=  LPI2C_IP_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_REVISION_VERSION_C !=  LPI2C_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.c and Lpi2c_Ip.h are different"
#endif
#if (( LPI2C_IP_SW_MAJOR_VERSION_C !=  LPI2C_IP_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_SW_MINOR_VERSION_C !=  LPI2C_IP_SW_MINOR_VERSION) || \
     ( LPI2C_IP_SW_PATCH_VERSION_C !=  LPI2C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip.c and Lpi2c_Ip.h are different"
#endif

/* Checks against Lpi2c_Ip_HwAccess.h */
#if (LPI2C_IP_VENDOR_ID_C !=  LPI2C_IP_HWACCESS_VENDOR_ID)
    #error "Lpi2c_Ip.c and Lpi2c_Ip_HwAccess.h have different vendor ids"
#endif
#if (( LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C    !=  LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_MINOR_VERSION_C    !=  LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_REVISION_VERSION_C !=  LPI2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.c and Lpi2c_Ip_HwAccess.h are different"
#endif
#if (( LPI2C_IP_SW_MAJOR_VERSION_C !=  LPI2C_IP_HWACCESS_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_SW_MINOR_VERSION_C !=  LPI2C_IP_HWACCESS_SW_MINOR_VERSION) || \
     ( LPI2C_IP_SW_PATCH_VERSION_C !=  LPI2C_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of LPI2C_Ip.c and Lpi2c_Ip_HwAccess.h are different"
#endif

/* Checks against Lpi2c_Ip_Features.h */
#if (LPI2C_IP_VENDOR_ID_C !=  LPI2C_IP_FEATURES_VENDOR_ID)
    #error "Lpi2c_Ip.c and Lpi2c_Ip_Features.h have different vendor ids"
#endif
#if (( LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C    !=  LPI2C_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_MINOR_VERSION_C    !=  LPI2C_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_REVISION_VERSION_C !=  LPI2C_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.c and Lpi2c_Ip_Features.h are different"
#endif
#if (( LPI2C_IP_SW_MAJOR_VERSION_C !=  LPI2C_IP_FEATURES_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_SW_MINOR_VERSION_C !=  LPI2C_IP_FEATURES_SW_MINOR_VERSION) || \
     ( LPI2C_IP_SW_PATCH_VERSION_C !=  LPI2C_IP_FEATURES_SW_PATCH_VERSION))
    #error "Software Version Numbers of LPI2C_Ip.c and Lpi2c_Ip_Features.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ( (LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
          (LPI2C_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Lpi2c_Ip.c and OsIf.h are different"
    #endif

    #if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
        /* Check if current file and Devassert.h header file are of the same Autosar version */
        #if ( (LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
              (LPI2C_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Lpi2c_Ip.c and Devassert.h are different"
        #endif
    #endif
    #if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        /* Check if current file and Dma_Ip.h header file are of the same Autosar version */
        #if ( (LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
              (LPI2C_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION)    \
             )
            #error "AutoSar Version Numbers of Lpi2c_Ip.c and Dma_Ip.h are different"
        #endif
    #endif /* (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE) */
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_I2c header file are of the same Autosar version */
    #if ((LPI2C_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_I2C_AR_RELEASE_MAJOR_VERSION) || \
         (LPI2C_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_I2C_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lpi2c_Ip.c and SchM_I2c.h are different"
    #endif
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/** @cond DRIVER_INTERNAL_USE_ONLY */

/* Constraints used for baud rate computation */
#define CLKHI_MIN_VALUE 1U
#define CLKLO_MIN_VALUE 3U
#define CLKHI_MAX_VALUE ((1U << LPI2C_MCCR0_CLKHI_WIDTH) - 1U)
#define CLKLO_MAX_VALUE CLKHI_MAX_VALUE
#define DATAVD_MIN_VALUE 1U
#define SETHOLD_MIN_VALUE 2U

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
/* DMA definitions */
#define I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER  (10U)
#define I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_SLAVE   (9U)
#endif

#define I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD   (256U)

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

/* Table of base addresses for LPI2C instances. */
static LPI2C_Type * const Lpi2c_Ip_pxBase[LPI2C_INSTANCE_COUNT] = IP_LPI2C_BASE_PTRS;

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

#if (LPI2C_IP_NUMBER_OF_MASTER_INSTANCES != 0U)

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

static Lpi2c_Ip_MasterStateType Lpi2c_Ip_MasterState[LPI2C_IP_NUMBER_OF_MASTER_INSTANCES];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

#endif

#if (LPI2C_IP_NUMBER_OF_SLAVE_INSTANCES != 0U)

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

static Lpi2c_Ip_SlaveStateType Lpi2c_Ip_SlaveState[LPI2C_IP_NUMBER_OF_SLAVE_INSTANCES];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

#endif

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

/* Pointer to runtime state structure.*/
static Lpi2c_Ip_MasterStateType* Lpi2c_Ip_pxMasterState[LPI2C_INSTANCE_COUNT];
static Lpi2c_Ip_SlaveStateType* Lpi2c_Ip_pxSlaveState[LPI2C_INSTANCE_COUNT];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"
/*******************************************************************************
 * Global Functions
 ******************************************************************************/
#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)

void Lpi2c_Ip_MasterCompleteDMATransfer(uint8 Instance);
static void Lpi2c_Ip_SetupLogicChannel(uint8 Instance);

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
void Lpi2c_Ip_MasterDMATransferErrorHandler(uint8 Instance);
#endif /* LPI2C_IP_DMA_TRANSFER_ERROR_DETECT */
#endif /* LPI2C_IP_DMA_FEATURE_AVAILABLE */

/** @brief Direction of a LPI2C transfer - transmit or receive. */
typedef enum
{
    LPI2C_TX_REQ = 0,    /**< The driver will perform an I2C transmit transfer */
    LPI2C_RX_REQ = 1,    /**< The driver will perform an I2C receive transfer */
} Lpi2c_Ip_TransferDirectionType;

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/*******************************************************************************
 * API
 ******************************************************************************/

static void Lpi2c_Ip_MasterIRQHandlerInternal(uint8 Instance);

static void Lpi2c_Ip_SlaveIRQHandlerInternal(uint8 Instance);

#ifdef LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE
static void Lpi2c_Ip_MasterBusRecovery(LPI2C_Type *BaseAddr,
                                       Lpi2c_Ip_MasterStateType * Master);
#endif

static void Lpi2c_Ip_MasterQueueReceiveCmd(LPI2C_Type *BaseAddr,
                                           Lpi2c_Ip_MasterStateType * Master);

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterCmdQueueEmpty
 * Description   : checks if there are any commands in the master software queue
 *
 *END**************************************************************************/
static inline boolean Lpi2c_Ip_MasterCmdQueueEmpty(const Lpi2c_Ip_MasterStateType * Master)
{
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    return (Master->CmdQueue.WriteIdx == Master->CmdQueue.ReadIdx);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterResetQueue
 * Description   : resets the master software queue
 *
 *END**************************************************************************/
static inline void Lpi2c_Ip_MasterResetQueue(Lpi2c_Ip_MasterStateType * Master)
{
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    Master->CmdQueue.ReadIdx = 0U;
    Master->CmdQueue.WriteIdx = 0U;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterQueueCmd
 * Description   : queues a command in the hardware FIFO or in the master software queue
 *
 *END**************************************************************************/
static inline void Lpi2c_Ip_MasterQueueCmd(LPI2C_Type *BaseAddr,
                                           Lpi2c_Ip_MasterStateType * Master,
                                           Lpi2c_Ip_MasterCommandType Cmd,
                                           uint8 Data)
{
    uint16 TxFIFOCount;
    uint16 TxFIFOSize;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(BaseAddr != NULL_PTR);
#endif

    TxFIFOCount = LPI2C_Get_MasterTxFIFOCount(BaseAddr);
    TxFIFOSize = LPI2C_Get_MasterTxFIFOSize(BaseAddr);

    /* Check if there is room in the hardware FIFO */
    if (TxFIFOCount < TxFIFOSize)
    {
        LPI2C_Cmd_MasterTransmit(BaseAddr, Cmd, Data);
    }
    else
    {
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
        /* Hardware FIFO full, use software FIFO */
        DevAssert(Master->CmdQueue.WriteIdx < LPI2C_MASTER_CMD_QUEUE_SIZE);
#endif
        Master->CmdQueue.Cmd[Master->CmdQueue.WriteIdx] = Cmd;
        Master->CmdQueue.Data[Master->CmdQueue.WriteIdx] = Data;
        Master->CmdQueue.WriteIdx++;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSendQueuedCmd
 * Description   : transfers commands from the master software queue to the hardware FIFO
 *
 *END**************************************************************************/
static inline void Lpi2c_Ip_MasterSendQueuedCmd(LPI2C_Type *BaseAddr,
                                                Lpi2c_Ip_MasterStateType * Master)
{
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(BaseAddr != NULL_PTR);
#endif
    uint16 TxFIFOCount = LPI2C_Get_MasterTxFIFOCount(BaseAddr);
    uint16 TxFIFOSize = LPI2C_Get_MasterTxFIFOSize(BaseAddr);

    while ((!Lpi2c_Ip_MasterCmdQueueEmpty(Master)) && (TxFIFOCount < TxFIFOSize))
    {
        LPI2C_Cmd_MasterTransmit(BaseAddr,
                                    Master->CmdQueue.Cmd[Master->CmdQueue.ReadIdx],
                                    Master->CmdQueue.Data[Master->CmdQueue.ReadIdx]);
        Master->CmdQueue.ReadIdx = (uint8)(Master->CmdQueue.ReadIdx + 1U);

        TxFIFOCount = LPI2C_Get_MasterTxFIFOCount(BaseAddr);
    }

    if (Lpi2c_Ip_MasterCmdQueueEmpty(Master))
    {
        /* Reset queue */
        Lpi2c_Ip_MasterResetQueue(Master);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSendAddress
 * Description   : send start event and slave address
 *                 parameter receive specifies the direction of the transfer
 *
 * @implements Lpi2c_Ip_MasterSendAddress_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterSendAddress(LPI2C_Type *BaseAddr,
                                       Lpi2c_Ip_MasterStateType * Master,
                                       boolean Receive)
{
    uint8 AddrByte;
    Lpi2c_Ip_MasterCommandType StartCommand;
    
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(BaseAddr != NULL_PTR);
#endif
#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
#if (STD_ON == ERRATA_ERR052121)
    if (LPI2C_ULTRAFAST_MODE == Master->OperatingMode)
    {
        /* When (MCFGR1[IGNACK]=0b1), the (MSR[NDF]) must be cleared by software, writing (MSR[NDF]=0b1) to allow new I2C
           transfers to start. */
        LPI2C_Clear_MasterNACKDetectEvent(BaseAddr);
    }
#endif
#endif

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
    if ((LPI2C_HIGHSPEED_MODE == Master->OperatingMode) && (FALSE == Master->HighSpeedInProgress))
    {
        /* Initiating High-speed mode - send master code first */
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_START_NACK, Master->MasterCode);
        Master->HighSpeedInProgress = TRUE;
    }

    if (TRUE == Master->HighSpeedInProgress)
    {
        /* Use high-speed settings after start event in High Speed mode */
        StartCommand = LPI2C_MASTER_COMMAND_START_HS;
    }
    else
#endif /* LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE */
    {
        /* Normal START command */
        StartCommand = LPI2C_MASTER_COMMAND_START;
    }

    if (Master->Is10bitAddr)
    {
        /* 10-bit addressing */
        /* First address byte: 1111 0XXD, where XX are bits 10 and 9 of address, and D = 0(transmit) */
        AddrByte = (uint8)(0xF0U + ((Master->SlaveAddress >> 7U) & 0x6U) + (uint8)0U);
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, StartCommand, AddrByte);
        /* Second address byte: Remaining 8 bits of address */
        AddrByte = (uint8)(Master->SlaveAddress & 0xFFU);
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_TRANSMIT, AddrByte);
        if (TRUE == Receive)
        {
            /* Receiving from 10-bit slave - must send repeated start and resend first Address byte */
            /* First address byte: 1111 0XXD, where XX are bits 10 and 9 of address, and D = 1 (Receive) */
            AddrByte = (uint8)(0xF0U + ((Master->SlaveAddress >> 7U) & 0x6U) + (uint8)1U);
            Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, StartCommand, AddrByte);
        }
    }
    else
    {
        /* 7-bit addressing */
        /* Address byte: rlave 7-bit Address + D = 0(transmit) or 1 (receive) */
        AddrByte = (uint8)((Master->SlaveAddress << 1U) + (uint8)((Receive == TRUE)?1U:0U));        
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, StartCommand, AddrByte);
    }
}

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterTxDmaConfig
 * Description   : This function configures DMA Tx channel for master transfer.
 *
 *END**************************************************************************/

static void Lpi2c_Ip_MasterTxDmaConfig(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;
    Dma_Ip_LogicChannelTransferListType Lpi2c_DmaTransferList[I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER];
    Dma_Ip_ReturnType DmaReturnStatus;
    uint32 TxBytes = 0;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];

    /* Configure watermarks for transmit DMA for Master */
    TxBytes = LPI2C_Get_MasterTxFIFOSize(BaseAddr);

    if (TxBytes > Master->BufferSize)
    {
        TxBytes = Master->BufferSize;
    }

    /* Source  address  */
    Lpi2c_DmaTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Lpi2c_DmaTransferList[0u].Value = (uint32)(&(Master->DataBuffer[0]));

    /* Source offset for next transfer */
    Lpi2c_DmaTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[1u].Value = 1U;

    /* Source transfer size*/
    Lpi2c_DmaTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Destination address*/
    Lpi2c_DmaTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Lpi2c_DmaTransferList[3u].Value = (uint32)(&(BaseAddr->MTDR));

    /* Destination offset for next transfer*/
    Lpi2c_DmaTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[4u].Value = 0U;

     /* Destination transfer size*/
    Lpi2c_DmaTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Number of bytes transfer per one minor loop*/
    Lpi2c_DmaTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Lpi2c_DmaTransferList[6u].Value = 1U;

    /* Number of minor loops per one major loop*/
    Lpi2c_DmaTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    Lpi2c_DmaTransferList[7u].Value = Master->BufferSize;

    /* Disable hardware auto request*/
    Lpi2c_DmaTransferList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    Lpi2c_DmaTransferList[8u].Value = 1U;

    /* Enable major interrupt*/
    Lpi2c_DmaTransferList[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    Lpi2c_DmaTransferList[9u].Value = 1U;

    /* Clear error status before setting up DMA configuration */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Master->DmaTxChannel, DMA_IP_CH_CLEAR_ERROR);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif

    /* Configure DMA channel */
    DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(Master->DmaTxChannel, Lpi2c_DmaTransferList, I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif

    /* Start DMA channel */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Master->DmaTxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    LPI2C_Set_MasterTxFIFOWatermark(BaseAddr, (uint16)(TxBytes - 1U));

    /* Send Address */
    Lpi2c_Ip_MasterSendAddress(BaseAddr, Master, FALSE);

    /* Enable transmit DMA requests */
    (void)LPI2C_Set_MasterTxDMA(BaseAddr, TRUE);
    (void)DmaReturnStatus;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterRxDmaConfig
 * Description   : This function configures DMA Rx channel for master transfer.
 *
 *END**************************************************************************/

static void Lpi2c_Ip_MasterRxDmaConfig(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;
    Dma_Ip_LogicChannelTransferListType Lpi2c_DmaTransferList[I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER];
    Dma_Ip_ReturnType DmaReturnStatus;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];

    /* Source  address  */
    Lpi2c_DmaTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Lpi2c_DmaTransferList[0u].Value = (uint32) (&(BaseAddr->MRDR));

    /* Source offset for next transfer */
    Lpi2c_DmaTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[1u].Value = 0U;

    /* Source transfer size*/
    Lpi2c_DmaTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Destination address*/
    Lpi2c_DmaTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Lpi2c_DmaTransferList[3u].Value = (uint32)(&(Master->DataBuffer[0]));

    /* Destination offset for next transfer*/
    Lpi2c_DmaTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[4u].Value = 1U;

    /* Destination transfer size*/
    Lpi2c_DmaTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Number of bytes transfer per one minor loop*/
    Lpi2c_DmaTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Lpi2c_DmaTransferList[6u].Value = 1U;

    /* Number of minor loops per one major loop*/
    Lpi2c_DmaTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;

    /* Disable hardware auto request*/
    Lpi2c_DmaTransferList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    Lpi2c_DmaTransferList[8u].Value = 1U;

    /* Enable major interrupt*/
    Lpi2c_DmaTransferList[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    Lpi2c_DmaTransferList[9u].Value = 1U;

    if (I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD > Master->BufferSize)
    {
        Lpi2c_DmaTransferList[7u].Value = Master->BufferSize;
    }
    else
    {
        Lpi2c_DmaTransferList[7u].Value = I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD - 1U;
    }
    /* Clear error status before setting up DMA configuration */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Master->DmaRxChannel, DMA_IP_CH_CLEAR_ERROR);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif

    /* Configure DMA channel */
    DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(Master->DmaRxChannel, Lpi2c_DmaTransferList, I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif

    /* Start DMA channel */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Master->DmaRxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    /* Configure watermarks for receive DMA for master */
    LPI2C_Set_MasterRxFIFOWatermark(BaseAddr, 0U);

    /* Send Address */
    Lpi2c_Ip_MasterSendAddress(BaseAddr, Master, TRUE);

    if (Master->BufferSize > I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD)
    {
        Master->ByteReceiveCount = I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD;
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD - 1U));
    }
    else
    {
        Master->ByteReceiveCount = Master->BufferSize;
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(Master->BufferSize - 1U));
    }
    (void)LPI2C_Set_MasterRxDMA(BaseAddr, TRUE);
    (void)DmaReturnStatus;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveTxDmaConfig
 * Description   : This function configures DMA Tx channel for slave transfer.
 *
 *END**************************************************************************/

static void Lpi2c_Ip_SlaveTxDmaConfig(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_SlaveStateType * Slave;
    Dma_Ip_LogicChannelTransferListType Lpi2c_DmaTransferList[I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_SLAVE];
    Dma_Ip_ReturnType DmaReturnStatus;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Slave = Lpi2c_Ip_pxSlaveState[Instance];

    /* Source  address  */
    Lpi2c_DmaTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Lpi2c_DmaTransferList[0u].Value = (uint32)(&(Slave->DataBuffer[0]));

    /* Source offset for next transfer */
    Lpi2c_DmaTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[1u].Value = 1U;

    /* Source transfer size*/
    Lpi2c_DmaTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Destination address*/
    Lpi2c_DmaTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Lpi2c_DmaTransferList[3u].Value = (uint32)(&(BaseAddr->STDR));

    /* Destination offset for next transfer*/
    Lpi2c_DmaTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[4u].Value = 0U;

    /* Destination transfer size*/
    Lpi2c_DmaTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Number of bytes transfer per one minor loop*/
    Lpi2c_DmaTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Lpi2c_DmaTransferList[6u].Value = 1U;

    /* Number of minor loops per one major loop*/
    Lpi2c_DmaTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    Lpi2c_DmaTransferList[7u].Value = Slave->BufferSize;

    /* Adjustment added to source address at the beginning of TX buffer*/
    Lpi2c_DmaTransferList[8u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
    Lpi2c_DmaTransferList[8u].Value = (uint32)(~Slave->BufferSize + 1U);

    /* Clear error status before setting up DMA configuration */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Slave->DmaTxChannel, DMA_IP_CH_CLEAR_ERROR);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(Slave->DmaTxChannel, Lpi2c_DmaTransferList, I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_SLAVE);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    /* Start DMA channel */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Slave->DmaTxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    (void)LPI2C_Set_SlaveTxDMA(BaseAddr, TRUE);
    (void)DmaReturnStatus;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveRxDmaConfig
 * Description   : This function configures DMA Rx channel for slave transfer.
 *
 *END**************************************************************************/

static void Lpi2c_Ip_SlaveRxDmaConfig(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_SlaveStateType * Slave;
    Dma_Ip_LogicChannelTransferListType Lpi2c_DmaTransferList[I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_SLAVE];
    Dma_Ip_ReturnType DmaReturnStatus;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Slave = Lpi2c_Ip_pxSlaveState[Instance];

    /* Source  address  */
    Lpi2c_DmaTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Lpi2c_DmaTransferList[0u].Value = (uint32)(&(BaseAddr->SRDR));

    /* Source offset for next transfer */
    Lpi2c_DmaTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[1u].Value = 0U;

    /* Source transfer size*/
    Lpi2c_DmaTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Destination address*/
    Lpi2c_DmaTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Lpi2c_DmaTransferList[3u].Value = (uint32)(&(Slave->DataBuffer[0]));

    /* Destination offset for next transfer*/
    Lpi2c_DmaTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Lpi2c_DmaTransferList[4u].Value = 1U;

    /* Destination transfer size*/
    Lpi2c_DmaTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    Lpi2c_DmaTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;

    /* Number of bytes transfer per one minor loop*/
    Lpi2c_DmaTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Lpi2c_DmaTransferList[6u].Value = 1U;

    /* Number of minor loops per one major loop*/
    Lpi2c_DmaTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    Lpi2c_DmaTransferList[7u].Value = Slave->BufferSize;

    /* Adjustment added to source address at the beginning of TX buffer*/
    Lpi2c_DmaTransferList[8u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    Lpi2c_DmaTransferList[8u].Value = (uint32)(~Slave->BufferSize + 1U);

    /* Clear error status before setting up DMA configuration */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Slave->DmaRxChannel, DMA_IP_CH_CLEAR_ERROR);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(Slave->DmaRxChannel, Lpi2c_DmaTransferList, I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_SLAVE);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    /* Start DMA channel */
    DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(Slave->DmaRxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(DMA_IP_STATUS_SUCCESS == DmaReturnStatus);
#endif
    (void)LPI2C_Set_SlaveRxDMA(BaseAddr, TRUE);
    (void)DmaReturnStatus;

}

#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterQueueData
 * Description   : queues transmit data in the LPI2C tx fifo until it is full
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterQueueData(LPI2C_Type *BaseAddr,
                                     Lpi2c_Ip_MasterStateType * Master)
{

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(BaseAddr != NULL_PTR);
#endif

    uint16 TxFIFOCount = LPI2C_Get_MasterTxFIFOCount(BaseAddr);
    uint16 TxFIFOSize = LPI2C_Get_MasterTxFIFOSize(BaseAddr);

    /* Don't queue any data if there are commands in the software queue */
    if (Lpi2c_Ip_MasterCmdQueueEmpty(Master))
    {
        while ((Master->BufferSize > 0U) && (TxFIFOCount < TxFIFOSize))
        {
            LPI2C_Cmd_MasterTransmit(BaseAddr, LPI2C_MASTER_COMMAND_TRANSMIT, Master->DataBuffer[0U]);
            Master->DataBuffer = (uint8 *)((uint32)Master->DataBuffer + (uint32)1U);
            Master->BufferSize--;

            TxFIFOCount = LPI2C_Get_MasterTxFIFOCount(BaseAddr);
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterEndTransfer
 * Description   : ends current transmission or reception
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterEndTransfer(LPI2C_Type *BaseAddr,
                                       Lpi2c_Ip_MasterStateType * Master,
                                       boolean SendStop,
                                       boolean ResetFIFO)
{
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(BaseAddr != NULL_PTR);
#endif

    /* Disable all events */
    LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_FIFO_ERROR_INT                \
                                  | LPI2C_IP_MASTER_ARBITRATION_LOST_INT        \
                                  | LPI2C_IP_MASTER_NACK_DETECT_INT             \
                                  | LPI2C_IP_MASTER_TRANSMIT_DATA_INT           \
                                  | LPI2C_IP_MASTER_PIN_LOW_TIMEOUT_INT         \
                                  | LPI2C_IP_MASTER_RECEIVE_DATA_INT
                        ,FALSE);

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
    if (LPI2C_USING_DMA == Master->TransferType)
    {
        /* Disable LPI2C DMA request. */
        if (LPI2C_IP_RECEIVE == Master->Direction)
        {
            (void)LPI2C_Set_MasterRxDMA(BaseAddr, FALSE);
        }
        else
        {
            (void)LPI2C_Set_MasterTxDMA(BaseAddr, FALSE);
        }
    }
#endif

    if (TRUE == ResetFIFO)
    {
        /* Reset FIFOs if requested */
        LPI2C_Reset_MasterTxFIFOCmd(BaseAddr);
        LPI2C_Reset_MasterRxFIFOCmd(BaseAddr);
    }

    /* Queue STOP command if requested */
    if (TRUE == SendStop)
    {
        LPI2C_Cmd_MasterTransmit(BaseAddr, LPI2C_MASTER_COMMAND_STOP, 0U);

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
        Master->HighSpeedInProgress = FALSE; /* High-speed transfers end at STOP condition */
#endif
    }

    Master->DataBuffer = NULL_PTR;
    Master->BufferSize = 0U;
    Master->I2cIdle = TRUE;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSetOperatingMode
 * Description   : sets the operating mode of the I2C master
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterSetOperatingMode(uint8 Instance,
                                            Lpi2c_Ip_ModeType OperatingMode)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif


#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
    if (LPI2C_ULTRAFAST_MODE == OperatingMode)
    {
        LPI2C_Set_MasterPinConfig(BaseAddr, LPI2C_CFG_2PIN_OUTPUT_ONLY);
        LPI2C_Set_MasterNACKConfig(BaseAddr, LPI2C_NACK_IGNORE);
    }
    else
#endif
    {
        LPI2C_Set_MasterPinConfig(BaseAddr, LPI2C_CFG_2PIN_OPEN_DRAIN);
        LPI2C_Set_MasterNACKConfig(BaseAddr, LPI2C_NACK_RECEIVE);
    }

    Master->OperatingMode = OperatingMode;
}

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveConfigureUltraFastMode
 * Description   : configures slave in ultra fast mode
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveConfigureUltraFastMode(LPI2C_Type *BaseAddr)
{
    /* ignore NACK received */
    LPI2C_Set_SlaveIgnoreNACK(BaseAddr, LPI2C_SLAVE_NACK_CONTINUE_TRANSFER);
    /* Transmit NACK */
    LPI2C_Set_SlaveTransmitNACK(BaseAddr, LPI2C_SLAVE_TRANSMIT_NACK);
    /* Disable all clock stretching in ultra-fast mode */
    LPI2C_Set_SlaveACKStall(BaseAddr, FALSE);
    LPI2C_Set_SlaveTXDStall(BaseAddr, FALSE);
    LPI2C_Set_SlaveRXStall(BaseAddr, FALSE);
    LPI2C_Set_SlaveAddrStall(BaseAddr, FALSE);
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveConfigureNormalMode
 * Description   : configures slave for normal operations
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveConfigureNormalMode(LPI2C_Type *BaseAddr)
{
    /* End transfer when NACK is received */
    LPI2C_Set_SlaveIgnoreNACK(BaseAddr, LPI2C_SLAVE_NACK_END_TRANSFER);
    /* Transmit ACK */
    LPI2C_Set_SlaveTransmitNACK(BaseAddr, LPI2C_SLAVE_TRANSMIT_ACK);
    /* Enable clock stretching except ACKSTALL (we don't need to send ACK/NACK manually) */
    LPI2C_Set_SlaveACKStall(BaseAddr, FALSE);
    LPI2C_Set_SlaveTXDStall(BaseAddr, TRUE);
    LPI2C_Set_SlaveRXStall(BaseAddr, TRUE);
    LPI2C_Set_SlaveAddrStall(BaseAddr, TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveSetOperatingMode
 * Description   : sets the operating mode of the I2C slave
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveSetOperatingMode(uint8 Instance,
                                           Lpi2c_Ip_ModeType OperatingMode)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_SlaveStateType * Slave;
    boolean HighSpeedMode = FALSE;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Slave = Lpi2c_Ip_pxSlaveState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
#endif

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
    if (LPI2C_ULTRAFAST_MODE == OperatingMode)
    {
        Lpi2c_Ip_SlaveConfigureUltraFastMode(BaseAddr);
    }
    else
#endif
    {
        Lpi2c_Ip_SlaveConfigureNormalMode(BaseAddr);
    }

    if (LPI2C_HIGHSPEED_MODE == OperatingMode)
    {
        /* Enable detection of high speed mode */
        HighSpeedMode = TRUE;
    }

     /* Enable/disable detection of the High-speed Mode master code */
    LPI2C_Set_SlaveHighSpeedModeDetect(BaseAddr, HighSpeedMode);

    Slave->OperatingMode = OperatingMode;
}

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterCompleteDMATransfer
 * Description   : Finish up a transfer DMA for master. The main purpose of
 *                 this function is to create a function compatible with DMA
 *                 callback type
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterCompleteDMATransfer(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType *Master;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];

    if ((Master->BufferSize > 0U) && (LPI2C_IP_SEND == Master->Direction))
    {
        Master->BufferSize = 0U;

        LPI2C_Set_MasterTxFIFOWatermark(BaseAddr, 0U);

        /* Disable transmit data DMA requests */
        (void)LPI2C_Set_MasterTxDMA(BaseAddr, FALSE);

        /* Activate transmit data events */
        LPI2C_Set_MasterInt(BaseAddr, (uint32)LPI2C_IP_MASTER_TRANSMIT_DATA_INT, TRUE);
    }
    else
    {
        if (LPI2C_IP_SEND == Master->Direction)
        {
            /* Signal transfer end for blocking transfers */
            Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

            Master->Status = LPI2C_IP_SUCCESS_STATUS;

            if (Master->MasterCallback != NULL_PTR)
            {
                Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
            }
        }
        else
        {
            if (Master->BufferSize == Master->ByteReceiveCount)
            {
                /* Signal transfer end for blocking transfers */
                Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

                Master->Status = LPI2C_IP_SUCCESS_STATUS;

                if (Master->MasterCallback != NULL_PTR)
                {
                    Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
                }
            }
            else
            {
                if ((Master->BufferSize - Master->ByteReceiveCount) >= I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD)
                {
                    Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(0xffU));
                    Master->ByteReceiveCount += I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD;

                    Lpi2c_Ip_SetupLogicChannel(Instance);
                }
                else
                {
                    Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(Master->BufferSize - Master->ByteReceiveCount - 1U));

                    Lpi2c_Ip_SetupLogicChannel(Instance);
                    Master->ByteReceiveCount = Master->BufferSize;
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SetupLogicChannel
 * Description   : This function to using setup Logic Channel TransferList and Logic Channel Command
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SetupLogicChannel(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_MasterStateType * Master;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
    Dma_Ip_LogicChannelTransferListType TempReceiveDmaTransferList;

    (void)LPI2C_Set_MasterRxDMA(BaseAddr, FALSE);

    if (((Master->BufferSize) - (Master->ByteReceiveCount)) >= I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD)
    {
        TempReceiveDmaTransferList.Value = I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD;
    }
    else
    {
        /* Use 16 bit width instead of 32 bit to avoid CWE INTEGER_OVERFLOW when performing subtraction and addition below */
        TempReceiveDmaTransferList.Value = (uint16)((uint16)Master->BufferSize - (uint16)Master->ByteReceiveCount + (uint16)1U);
    }

    TempReceiveDmaTransferList.Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;

    (void)Dma_Ip_SetLogicChannelTransferList(Master->DmaRxChannel, &TempReceiveDmaTransferList, 1U);
    (void)Dma_Ip_SetLogicChannelCommand(Master->DmaRxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);

    (void)LPI2C_Set_MasterRxDMA(BaseAddr, TRUE);
}

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterDMATransferErrorHandler
 * Description   : Handle error when transfer DMA for master. The main purpose of
 *                 this function is to create a function compatible with DMA
 *                 callback type
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterDMATransferErrorHandler(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Dma_Ip_LogicChannelStatusType DmaStatus;
    Lpi2c_Ip_MasterStateType *Master;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
    DmaStatus.ChStateValue = DMA_IP_CH_RESET_STATE;

    if (LPI2C_IP_SEND == Master->Direction)
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(Master->DmaTxChannel, &DmaStatus);
    }
    else
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(Master->DmaRxChannel, &DmaStatus);
    }

    if (DMA_IP_CH_ERROR_STATE == DmaStatus.ChStateValue)
    {
        /* Signal transfer end for blocking transfers */
        Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

        /* Report status error if an error occurred in EDMA channel */
        Master->Status = LPI2C_IP_DMA_ERROR_STATUS;

        if (Master->MasterCallback != NULL_PTR)
        {
            Master->MasterCallback(I2C_MASTER_EVENT_DMA_TRANSFER_ERROR, Master->CallbackParam);
        }
    }
}
#endif
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterHandleTransmitDataRequest
 * Description   : handle a transmit request for master
 *
 * @implements Lpi2c_Ip_MasterHandleTransmitDataRequest_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterHandleTransmitDataRequest(LPI2C_Type *BaseAddr,
                                                     Lpi2c_Ip_MasterStateType *Master)
{
    /* More data needed for transmission */
    if (!Lpi2c_Ip_MasterCmdQueueEmpty(Master))
    {
        /* If there are queued commands, send them */
        Lpi2c_Ip_MasterSendQueuedCmd(BaseAddr, Master);
    }
    else if ((Master->DataBuffer != NULL_PTR) && (LPI2C_IP_SEND == Master->Direction))
    {
        /* A transmission is in progress */
        if (0U == Master->BufferSize)
        {
            /* There is no more data in buffer, the transmission is over */
            Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

            Master->Status = LPI2C_IP_SUCCESS_STATUS;

            if (Master->MasterCallback != NULL_PTR)
            {
                Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
            }
        }
        else
        {
            /* Queue data bytes to fill tx fifo */
            Lpi2c_Ip_MasterQueueData(BaseAddr, Master);
        }
    }
    else
    {
        /* No more commands and no transmission in progress - disable tx event */
        LPI2C_Set_MasterInt(BaseAddr, (uint32)LPI2C_IP_MASTER_TRANSMIT_DATA_INT, FALSE);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterHandleReceiveDataRequest
 * Description   : handle a receive request for master
 *
 * @implements Lpi2c_Ip_MasterHandleReceiveDataReadyEvent_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterHandleReceiveDataReadyEvent(LPI2C_Type *BaseAddr,
                                                       Lpi2c_Ip_MasterStateType *Master)
{
    /* Received data ready */
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master->DataBuffer != NULL_PTR);
#endif

    /* Transfer received data to user buffer */
    while ((LPI2C_Get_MasterRxFIFOCount(BaseAddr) > 0U) && (Master->BufferSize > 0U))
    {
        Master->DataBuffer[0U] = LPI2C_Get_MasterRxData(BaseAddr);
        Master->DataBuffer = (uint8 *)((uint32)Master->DataBuffer + (uint32)1U);
        Master->BufferSize--;
        Master->ByteReceiveCount++;
    }

    if (0U == Master->BufferSize)
    {
        /* Done receiving */
        Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

        Master->Status = LPI2C_IP_SUCCESS_STATUS;

        if (Master->MasterCallback != NULL_PTR)
        {
            Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
        }
    }
    else if (Master->BufferSize <= LPI2C_Get_MasterRxFIFOWatermark(BaseAddr))
    {
        /* Reduce rx watermark to receive the last few bytes */
        LPI2C_Set_MasterRxFIFOWatermark(BaseAddr, (uint16)(Master->BufferSize - 1U));
    }
    else
    {
        /* Continue reception */
        /* More data needed for transmission */
        if (((Master->ByteReceiveCount + 4U) % I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD) == 0U)
        {
            if ((Master->BufferSize - 4U) > I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD){

                /* Queue receive command for RxSize bytes */
                Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(0xffU));
            }
            else
            {
                /* Queue receive command for RxSize bytes */
                Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(Master->BufferSize - 5U));
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveHandleAddressValidEvent
 * Description   : handle an address valid event for slave
 *
 * @implements Lpi2c_Ip_SlaveHandleAddressValidEvent_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveHandleAddressValidEvent(uint8 Instance,
                                                  const LPI2C_Type *BaseAddr,
                                                  Lpi2c_Ip_SlaveStateType *Slave)
{
    uint16 ReceivedAddr;

    ReceivedAddr = LPI2C_Get_SlaveReceivedAddr(BaseAddr);
    if ((ReceivedAddr & 1U) != (uint16)0U)
    {
        /* Request from master to transmit data */
        Slave->Direction = LPI2C_IP_SEND;

        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_TX_REQ, Slave->CallbackParam);
        }

#if defined(ERRATA_E10792)
        if (LPI2C_USING_INTERRUPTS == Slave->TransferType)
        {
            /* Enable interrupt for transmitting Data */
            LPI2C_Set_SlaveInt(Lpi2c_Ip_pxBase[Instance], (uint32)LPI2C_IP_SLAVE_TRANSMIT_DATA_INT, TRUE);
        }
#endif

        Slave->TxUnderrunWarning = FALSE;

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        if (LPI2C_USING_DMA == Slave->TransferType)
        {
            Lpi2c_Ip_SlaveTxDmaConfig(Instance);
        }
#endif
    }
    else
    {
        /* Request from master to receive data */
        Slave->Direction = LPI2C_IP_RECEIVE;

        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_RX_REQ, Slave->CallbackParam);
        }
#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        if (LPI2C_USING_DMA == Slave->TransferType)
        {
            Lpi2c_Ip_SlaveRxDmaConfig(Instance);
        }
#endif
    }

    (void) Instance;
    Slave->Status = LPI2C_IP_BUSY_STATUS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveHandleTransmitDataEvent
 * Description   : handle a transmit data event for slave
 *
 * @implements Lpi2c_Ip_SlaveHandleTransmitDataEvent_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveHandleTransmitDataEvent(LPI2C_Type *BaseAddr,
                                                  Lpi2c_Ip_SlaveStateType *Slave)
{
    if (TRUE == Slave->TxUnderrunWarning)
    {
        /* Another Tx event after underflow warning means the dummy char was sent */
        Slave->Status = LPI2C_IP_TX_UNDERRUN_STATUS;

#if (STD_ON == LPI2C_IP_EVENT_ERROR_DETECT)
        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_UNDERRUN, Slave->CallbackParam);
        }
#endif
    }

    if (0U == Slave->BufferSize)
    {
        /* Out of data, call callback to allow user to provide a new buffer */
        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_TX_EMPTY, Slave->CallbackParam);
        }
    }

    if (0U == Slave->BufferSize)
    {
        /*
        * Still no data, record tx underflow event and send dummy char.
        * Special case after the last tx byte: the device will ask for more data
        * but the dummy char will not be sent if NACK and then STOP condition are
        * received from master. So only record a "warning" for now.
        */
        Slave->TxUnderrunWarning = TRUE;
        LPI2C_Transmit_SlaveData(BaseAddr, (uint8)0xFFU);
    }
    else
    {
        LPI2C_Transmit_SlaveData(BaseAddr, Slave->DataBuffer[0U]);
        Slave->DataBuffer++;
        Slave->BufferSize--;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveHandleReceiveDataEvent
 * Description   : handle a receive data event for slave
 *
 * @implements  Lpi2c_Ip_SlaveHandleReceiveDataEvent_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveHandleReceiveDataEvent(const LPI2C_Type *BaseAddr,
                                                 Lpi2c_Ip_SlaveStateType *Slave)
{
    if (0U == Slave->BufferSize)
    {
        /* No more room for data, call callback to allow user to provide a new buffer */
        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_RX_FULL, Slave->CallbackParam);
        }
    }

    if (0U == Slave->BufferSize)
    {
        /* Still no room for data, record rx overrun event and dummy read data */
        Slave->Status = LPI2C_IP_RX_OVERRUN_STATUS;
        (void)LPI2C_Get_SlaveData(BaseAddr);

#if (STD_ON == LPI2C_IP_EVENT_ERROR_DETECT)
        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_OVERRUN, Slave->CallbackParam);
        }
#endif
    }
    else
    {
        Slave->DataBuffer[0U] = LPI2C_Get_SlaveData(BaseAddr);
        Slave->DataBuffer++;
        Slave->BufferSize--;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_Get_MasterFIFOErrorEventHandler
 * Description   : handles master fifo error
 *
 *END**************************************************************************/
static void Lpi2c_Ip_Get_MasterFIFOErrorEventHandler(LPI2C_Type *BaseAddr,
                                                  Lpi2c_Ip_MasterStateType * Master)
{
    /* FIFO error */
    LPI2C_Clear_MasterFIFOErrorEvent(BaseAddr);

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
    if (LPI2C_HIGHSPEED_MODE == Master->OperatingMode)
    {
        /* High-speed transfers end at STOP condition */
        Master->HighSpeedInProgress = FALSE;
    }
#endif

    Master->Status = LPI2C_IP_ERROR_STATUS;

    /* End transfer: no stop generation (the module will handle that by itself
       if needed), reset FIFOs */
    Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, FALSE, TRUE);

    if (Master->MasterCallback != NULL_PTR)
    {
#if (STD_ON == LPI2C_IP_EVENT_ERROR_DETECT)
        Master->MasterCallback(I2C_MASTER_EVENT_ERROR_FIFO, Master->CallbackParam);
#else
        Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
#endif
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_Get_MasterNACKDetectEventHandler
 * Description   : handles master NACK detection event
 *
 *END**************************************************************************/
static void Lpi2c_Ip_Get_MasterNACKDetectEventHandler(LPI2C_Type *BaseAddr,
                                                   Lpi2c_Ip_MasterStateType * Master)
{

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
    /* Ignore NACK in Ultra Fast mode */
    if (LPI2C_ULTRAFAST_MODE != Master->OperatingMode)
    {
#endif

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
        /* High-speed transfers end at STOP condition */
        Master->HighSpeedInProgress = FALSE;
#endif

        Master->Status = LPI2C_IP_RECEIVED_NACK_STATUS;

        /* End transfer: no stop generation (the module will handle that by itself
           if needed), reset FIFOs */
        Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, FALSE, TRUE);

        if (Master->MasterCallback != NULL_PTR)
        {
#if (STD_ON == LPI2C_IP_EVENT_ERROR_DETECT)
            Master->MasterCallback(I2C_MASTER_EVENT_NACK, Master->CallbackParam);
#else
            Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
#endif
        }

        /* Clear NACK flag */
        LPI2C_Clear_MasterNACKDetectEvent(BaseAddr);
#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
    }
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_Get_MasterArbitrationLostEventHandler
 * Description   : handles master arbitration lost event
 *
 *END**************************************************************************/
static void Lpi2c_Ip_Get_MasterArbitrationLostEventHandler(LPI2C_Type *BaseAddr,
                                                           Lpi2c_Ip_MasterStateType * Master)
{
    /* Arbitration lost */
    LPI2C_Clear_MasterArbitrationLostEvent(BaseAddr);

    /* End transfer: no stop generation (the module will handle that by itself
       if needed), reset FIFOs */
    Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, FALSE, TRUE);

    Master->Status = LPI2C_IP_ARBITRATION_LOST_STATUS;

    if (Master->MasterCallback != NULL_PTR)
    {
#if (STD_ON == LPI2C_IP_EVENT_ERROR_DETECT)
        Master->MasterCallback(I2C_MASTER_EVENT_ARBITRATION_LOST, Master->CallbackParam);
#else
        Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
#endif
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterCheckErrorEvents
 * Description   : checks error events for Master module
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterCheckErrorEvents(LPI2C_Type *BaseAddr,
                                            Lpi2c_Ip_MasterStateType * Master)
{
    if (LPI2C_Get_MasterFIFOErrorEvent(BaseAddr))
    {
        /* Handle FIFO error event */
        Lpi2c_Ip_Get_MasterFIFOErrorEventHandler(BaseAddr, Master);
    }

    if (LPI2C_Get_MasterArbitrationLostEvent(BaseAddr))
    {
        /* Handle arbitration lost event */
        Lpi2c_Ip_Get_MasterArbitrationLostEventHandler(BaseAddr, Master);
    }

    if (Lpi2c_Ip_Get_MasterNACKDetectEvent(BaseAddr))
    {
        /* Handle Received NACK */
        Lpi2c_Ip_Get_MasterNACKDetectEventHandler(BaseAddr, Master);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSend
 * Description   : sync send transfer handler
 *
 * @implements Lpi2c_Ip_MasterSend_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterSend(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;
    boolean MasterCmdQueueEmpty = FALSE;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    /* Check which event caused the interrupt */
    if (LPI2C_Get_MasterTransmitDataRequestEvent(BaseAddr))
    {
        /* More data needed for transmission */
        if (!Lpi2c_Ip_MasterCmdQueueEmpty(Master))
        {
            /* If there are queued commands, send them */
            Lpi2c_Ip_MasterSendQueuedCmd(BaseAddr, Master);
        }
        else
        {
            MasterCmdQueueEmpty = TRUE;
        }
    }

    if (MasterCmdQueueEmpty)
    {
        if (Master->DataBuffer != NULL_PTR)
        {
            /* A transmission is in progress */
            if (0U == Master->BufferSize)
            {
                /* There is no more data in buffer, the transmission is over */
                Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

                Master->Status = LPI2C_IP_SUCCESS_STATUS;

                if (Master->MasterCallback != NULL_PTR)
                {
                    Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
                }
            }
            else
            {
                /* Queue data bytes to fill tx fifo */
                Lpi2c_Ip_MasterQueueData(BaseAddr, Master);
            }
        }
        else
        {
            /* else case */
        }
    }

    /* Check error event */
    Lpi2c_Ip_MasterCheckErrorEvents(BaseAddr, Master);

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterGetReceivedData
 * Description   : read data receive from RX FIFO
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterGetReceivedData(const LPI2C_Type *BaseAddr,
                                           Lpi2c_Ip_MasterStateType * Master)
{
    /* Read data from RX FIFO */
    while ((LPI2C_Get_MasterRxFIFOCount(BaseAddr) > 0U) && (Master->BufferSize > 0U))
    {
        Master->DataBuffer[0U] = LPI2C_Get_MasterRxData(BaseAddr);
        Master->DataBuffer = (uint8 *)((uint32)Master->DataBuffer + (uint32)1U);;
        Master->BufferSize--;
        Master->ByteReceiveCount++;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterQueue
 * Description   : Queue receive command for RxSize bytes.
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterQueueReceiveCmd(LPI2C_Type *BaseAddr,
                                           Lpi2c_Ip_MasterStateType * Master)
{
    /* Continue reception */
    /* More data needed for transmission */
    if (((Master->ByteReceiveCount + 4U) % I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD) == 0U)
    {
        if ((Master->BufferSize - 4U) > I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD)
        {
            /* Queue receive command for RxSize bytes */
            Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(0xffU));
        }
        else
        {
            /* Queue receive command for RxSize bytes */
            Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(Master->BufferSize - 5U));
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterReceive
 * Description   : sync receive transfer handler
 *
 * @implements Lpi2c_Ip_MasterReceive_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterReceive(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    if ((LPI2C_Get_MasterReceiveDataReadyEvent(BaseAddr)))
    {
        /* Read data from RX FIFO */
        Lpi2c_Ip_MasterGetReceivedData(BaseAddr, Master);

        if (0U == Master->BufferSize)
        {
            /* Done receiving */
            Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);

            Master->Status = LPI2C_IP_SUCCESS_STATUS;

            if (Master->MasterCallback != NULL_PTR)
            {
                Master->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
            }
        }
        else if (Master->BufferSize <= LPI2C_Get_MasterRxFIFOWatermark(BaseAddr))
        {
            LPI2C_Set_MasterRxFIFOWatermark(BaseAddr, (uint16)(Master->BufferSize - 1U));
        }
        else
        {
            /* Queue receive command for RxSize bytes. */
            Lpi2c_Ip_MasterQueueReceiveCmd(BaseAddr, Master);
        }
    }

    /* Check error event */
    Lpi2c_Ip_MasterCheckErrorEvents(BaseAddr, Master);

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_BaudRateConfig
 * Description   : configures MCCR0 register
 *
 *END**************************************************************************/
static void Lpi2c_Ip_BaudRateConfig(LPI2C_Type *BaseAddr,
                                    const Lpi2c_Ip_BaudRateType * BaudRate)
{
    /* Set prescaler */
    LPI2C_Set_MasterPrescaler(BaseAddr, BaudRate->Prescaler);
    /* Set hold delay */
    LPI2C_Set_MasterSetupHoldDelay(BaseAddr, (uint8)BaudRate->SetHold);
    /* Set data valid delay */
    LPI2C_Set_MasterDataValidDelay(BaseAddr, (uint8)BaudRate->DataValid);
    /* Set clock HIGH period */
    LPI2C_Set_MasterClockHighPeriod(BaseAddr, (uint8)BaudRate->ClkHI);
    /* Set clock low period */
    LPI2C_Set_MasterClockLowPeriod(BaseAddr, (uint8)BaudRate->ClkLO);
}

#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_HSBaudRateConfig
 * Description   : configures MCCR1 register
 *
 *END**************************************************************************/
static void Lpi2c_Ip_HSBaudRateConfig(LPI2C_Type *BaseAddr,
                                      const Lpi2c_Ip_BaudRateType * BaudRate)
{
     /* Set data valid delay */
    LPI2C_Set_MasterDataValidDelayHS(BaseAddr, (uint8)BaudRate->SetHoldHS);
    /* Set hold delay */
    LPI2C_Set_MasterSetupHoldDelayHS(BaseAddr, (uint8)BaudRate->DataValidHS);
    /* Set clock HIGH period */
    LPI2C_Set_MasterClockHighPeriodHS(BaseAddr, (uint8)BaudRate->ClkHIHS);
    /* Set clock low period */
    LPI2C_Set_MasterClockLowPeriodHS(BaseAddr, (uint8)BaudRate->ClkLOHS);
}
#endif /* STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSetBaudRate
 * Description   : set the baud rate for any subsequent I2C communication
 *
 * Implements : Lpi2c_Ip_MasterSetBaudRate_Activity
 *
 *END**************************************************************************/
 Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSetBaudRate(uint8 Instance,
                                                Lpi2c_Ip_ModeType OperatingMode,
                                                uint32 Baudrate,
                                                uint32 InputClock)
{
    LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_MasterStateType * Master;
    Lpi2c_Ip_BaudRateType BaudRateParams;
    uint32 MinPrescaler = 0U;
    uint32 Prescaler;
    uint32 ClkTotal;
    uint32 ClkLo;
    uint32 ClkHi;
    uint32 SetHold;
    uint32 DataVd;
    Lpi2c_Ip_StatusType RetStatus = LPI2C_IP_BUSY_STATUS;
    const Lpi2c_Ip_MasterPrescalerType PrescalerArr[8U] =
                                                    {
                                                        LPI2C_MASTER_PRESC_DIV_1,
                                                        LPI2C_MASTER_PRESC_DIV_2,
                                                        LPI2C_MASTER_PRESC_DIV_4,
                                                        LPI2C_MASTER_PRESC_DIV_8,
                                                        LPI2C_MASTER_PRESC_DIV_16,
                                                        LPI2C_MASTER_PRESC_DIV_32,
                                                        LPI2C_MASTER_PRESC_DIV_64,
                                                        LPI2C_MASTER_PRESC_DIV_128
                                                    };
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    /* Check if driver is busy */
    if (Master->I2cIdle)
    {
        /* Disable daster */
        LPI2C_Set_MasterEnable(BaseAddr, FALSE);

        /* Ignoring the glitch filter, the baud rate formula is:
                SCL_freq = Input_freq / (2^PRESCALER * (CLKLO + CLKHI + 2))
                Assume CLKLO = CLKHI, SETHOLD = CLKHI, DATAVD = CLKHI/2
        */
        if (Baudrate != 0U)
        {
            /* Compute minimum Prescaler for which CLKLO and CLKHI values are in valid range. Always round up. */
            MinPrescaler = ((InputClock - 1U) / ((Baudrate) * (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U))) + (uint32)1U;
            for (Prescaler = 0U; Prescaler < 7U; Prescaler++)
            {
                if (((uint32)1U << Prescaler) >= MinPrescaler)
                {
                    break;
                }
            }
            /* Compute CLKLO and CLKHI values for this Prescaler. Round to nearest integer. */
            ClkTotal = (InputClock + ((Baudrate << Prescaler) >> 1U)) / (Baudrate << Prescaler);
        }
        else
        {
            Prescaler = 7U;
            ClkTotal = (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U);
        }

        if (ClkTotal > (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U))
        {
            ClkTotal = (CLKHI_MAX_VALUE + CLKLO_MAX_VALUE + 2U);
        }

        /*
         * If we try to compute clk high and low values using ClkTotal equal with 0
         * (this is the case when the baudrate is 0), we will get negative values for
         * them, so we set them to 0 for this case.
         */
        if (ClkTotal <= 1U)
        {
            ClkHi = 0U;
            ClkLo = 0U;
        }
        else
        {
            ClkHi = (ClkTotal - 2U) / 2U;
            ClkLo = ClkTotal - 2U - ClkHi;
        }

        if (ClkHi < CLKHI_MIN_VALUE)
        {
            ClkHi = CLKHI_MIN_VALUE;
        }
        if (ClkLo < CLKLO_MIN_VALUE)
        {
            ClkLo = CLKLO_MIN_VALUE;
        }

        /* Compute DATAVD and SETHOLD */
        SetHold = ClkHi;
        DataVd = ClkHi >> 1U;
        if (SetHold < SETHOLD_MIN_VALUE)
        {
            SetHold = SETHOLD_MIN_VALUE;
        }
        if (DataVd < DATAVD_MIN_VALUE)
        {
            DataVd = DATAVD_MIN_VALUE;
        }

        /* Init baud rate params */
        BaudRateParams.Prescaler = PrescalerArr[Prescaler];
        BaudRateParams.DataValid = DataVd;
        BaudRateParams.SetHold = SetHold;
        BaudRateParams.ClkHI = ClkHi;
        BaudRateParams.ClkLO = ClkLo;

        /* Apply settings */
        Lpi2c_Ip_BaudRateConfig(BaseAddr, &BaudRateParams);

        /* Perform other settings related to the chosen operating mode */
        Lpi2c_Ip_MasterSetOperatingMode(Instance, OperatingMode);

        /* Re-enable master */
        LPI2C_Set_MasterEnable(BaseAddr, TRUE);
        RetStatus = LPI2C_IP_SUCCESS_STATUS;
    }
    (void) MinPrescaler;
    (void)Master;

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSetBaudRateInit
 * Description   : set the baud rate for any subsequent I2C communication
 *
 * Implements : Lpi2c_Ip_MasterSetBaudRateInit_Activity
 *
 *END**************************************************************************/
static Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSetBaudRateInit(uint8 Instance,
                                                          const Lpi2c_Ip_ModeType OperatingMode,
                                                          const Lpi2c_Ip_BaudRateType * BaudRate)
{

    LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_MasterStateType *Master;
    Lpi2c_Ip_StatusType RetStatus = LPI2C_IP_BUSY_STATUS;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Master = Lpi2c_Ip_pxMasterState[Instance];
    BaseAddr = Lpi2c_Ip_pxBase[Instance];

    /* Check if driver is busy */
    if (Master->I2cIdle)
    {
        /* Disable master */
        LPI2C_Set_MasterEnable(BaseAddr, FALSE);

        /* Apply settings */
        Lpi2c_Ip_BaudRateConfig(BaseAddr, BaudRate);

#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
        /* Apply High-speed settings */
        Lpi2c_Ip_HSBaudRateConfig(BaseAddr, BaudRate);
#endif
        /* Perform other settings related to the chosen operating mode */
        Lpi2c_Ip_MasterSetOperatingMode(Instance, OperatingMode);

        /* Re-enable master */
        LPI2C_Set_MasterEnable(BaseAddr, TRUE);
        RetStatus = LPI2C_IP_SUCCESS_STATUS;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterInitModule
 * Description   : resets software queue and resets master FIFOs
 *END**************************************************************************/
static void Lpi2c_Ip_MasterInitModule(LPI2C_Type *BaseAddr,
                                      Lpi2c_Ip_MasterStateType * Master)
{
    /* Reset software queue */
    Lpi2c_Ip_MasterResetQueue(Master);

    /* Initialize module */
    Lpi2c_Ip_Init(BaseAddr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterConfigFeatures
 * Description   : configures glitch filter for SDA and SCL, bus idle and pin low Timeout
 *END**************************************************************************/
static void Lpi2c_Ip_MasterConfigFeatures(LPI2C_Type *BaseAddr,
                                          const Lpi2c_Ip_MasterConfigType * ConfigPtr)
{
    /* Set glitch filters for SDA and SCL */
    LPI2C_Set_MasterGlitchFilterSDA(BaseAddr, ConfigPtr->GlitchFilterSDA);
    LPI2C_Set_MasterGlitchFilterSCL(BaseAddr, ConfigPtr->GlitchFilterSCL);

    /* Set bus idle Timeout */
    LPI2C_Set_MasterBusIdleTimeout(BaseAddr, ConfigPtr->BusIdleTimeout);

    /* Configure pin low Timeout for both SDA and SCL */
    LPI2C_Set_MasterPinLowTimeoutConfiguration(BaseAddr, TRUE);

    /* Configure Pin Low Timeout  */
    LPI2C_Set_MasterPinLowTimeout(BaseAddr, ConfigPtr->PinLowTimeout);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterInit
 * Description   : initialize the I2C master mode driver
 *
 * Implements : Lpi2c_Ip_MasterInit_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterInit(uint8 Instance,
                         const Lpi2c_Ip_MasterConfigType * ConfigPtr)
{
    LPI2C_Type *BaseAddr;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(ConfigPtr != NULL_PTR);
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    /* Check to see if the LPI2C master instance is already initialized */
    DevAssert(Lpi2c_Ip_pxMasterState[Instance] == NULL_PTR);
#endif

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
#if (LPI2C_IP_NUMBER_OF_MASTER_INSTANCES != 0U)
    Lpi2c_Ip_pxMasterState[Instance] = &(Lpi2c_Ip_MasterState[ConfigPtr->MasterStateIdx]);
#endif
    Lpi2c_Ip_MasterStateType * Master =  Lpi2c_Ip_pxMasterState[Instance];

    /* Initialize driver status structure */
    Master->Direction = LPI2C_IP_SEND;
    Master->DataBuffer = NULL_PTR;
    Master->BufferSize = 0U;
    Master->Status = LPI2C_IP_SUCCESS_STATUS;
    Master->I2cIdle = TRUE;
    Master->SlaveAddress = ConfigPtr->SlaveAddress;
    Master->Is10bitAddr = ConfigPtr->Is10bitAddr;
    Master->TransferType = ConfigPtr->TransferType;
    /* Store DMA channel number used in transfer */
    Master->DmaTxChannel = ConfigPtr->DmaTxChannel;
    Master->DmaRxChannel = ConfigPtr->DmaRxChannel;
    Master->MasterCallback = ConfigPtr->MasterCallback;
    Master->CallbackParam = ConfigPtr->CallbackParam;
    /* Master code require : 0b00001XXX and Master code generated: 0b00000XXX */
    Master->MasterCode = ConfigPtr->MasterCode | ((uint8)1U << 3);
    Master->HighSpeedInProgress = FALSE;

    Master->BaudrateParams = ConfigPtr->BaudrateParams;

    /* Init/enable master module */
    Lpi2c_Ip_MasterInitModule(BaseAddr, Master);

    /* CPR_RTD_01182.i2c: Pending interrupt flags shall be cleared before enabling interrupts */
    LPI2C_Clear_MasterStatusFlags(BaseAddr, LPI2C_IP_FLAG_CONTROLLER_STATUS_REQUEST);

    /* Configure glitch filter, bus idle and pin low Timeout */
    Lpi2c_Ip_MasterConfigFeatures(BaseAddr, ConfigPtr);

    /* Set baud rate */
    (void)Lpi2c_Ip_MasterSetBaudRateInit(Instance, ConfigPtr->OperatingMode, Master->BaudrateParams);

    /* Set slave address */
    Lpi2c_Ip_MasterSetSlaveAddr(Instance, ConfigPtr->SlaveAddress, ConfigPtr->Is10bitAddr);

    /* Enable LPI2C master */
    LPI2C_Set_MasterEnable(BaseAddr, TRUE);

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterDeinit
 * Description   : deinitialize the I2C master mode driver
 *
 * Implements : Lpi2c_Ip_MasterDeinit_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterDeinit(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_MasterStateType *Master;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    Lpi2c_Ip_pxMasterState[Instance] = NULL_PTR;

    /* Clear all status request flags */
    BaseAddr->MSR = LPI2C_IP_FLAG_CONTROLLER_STATUS_REQUEST ;

    /* Disable master */
    LPI2C_Set_MasterEnable(BaseAddr, FALSE);

    /* Reset registers to default value*/
    BaseAddr->MCR    = 0x0U;
    BaseAddr->MDER   = 0x0U;
    BaseAddr->MIER   = 0x0U;
    BaseAddr->MCCR0  = 0x0U;
    BaseAddr->MCCR1  = 0x0U;
    BaseAddr->MCFGR0 = 0x0U;
    BaseAddr->MCFGR1 = 0x0U;
    BaseAddr->MCFGR2 = 0x0U;
    BaseAddr->MCFGR3 = 0x0U;
    BaseAddr->MFCR   = 0x0U;
    BaseAddr->MTDR   = 0x0U;

    (void) Master;

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterGetBaudRate
 * Description   : returns the currently configured baud rate
 *
 * Implements : Lpi2c_Ip_MasterGetBaudRate_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterGetBaudRate(uint8 Instance,
                                uint32 InputClock,
                                uint32 *BaudRate)
{
    const LPI2C_Type *BaseAddr;
    const Lpi2c_Ip_MasterStateType *Master;
    uint32 Prescaler;
    uint32 ClkLo;
    uint32 ClkHi;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    
    Master = Lpi2c_Ip_pxMasterState[Instance];

    /* Ignoring the glitch filter, the baud rate formula is:
            SCL_freq = Input_freq / (2^PRESCALER * (CLKLO + CLKHI + 2))
    */
    Prescaler = LPI2C_Get_MasterPrescaler(BaseAddr);
    ClkHi = (uint32)LPI2C_Get_MasterClockHighPeriod(BaseAddr);
    ClkLo = (uint32)LPI2C_Get_MasterClockLowPeriod(BaseAddr);

    *BaudRate = InputClock / (((uint32)1U << Prescaler) * (ClkLo + ClkHi + (uint32)2U));

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
    if (LPI2C_HIGHSPEED_MODE == Master->OperatingMode)
    {
        ClkHi = LPI2C_Get_MasterClockHighPeriodHS(BaseAddr);
        ClkLo = LPI2C_Get_MasterClockLowPeriodHS(BaseAddr);

        *BaudRate = InputClock / (((uint32)1U << Prescaler) * (ClkLo + ClkHi + (uint32)2U));
    }

#endif

#if (STD_OFF == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
    (void) Master;
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSetSlaveAddr
 * Description   : set the slave address for any subsequent I2C communication
 *
 * Implements : Lpi2c_Ip_MasterSetSlaveAddr_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterSetSlaveAddr(uint8 Instance,
                                 const uint16 Address,
                                 const boolean Is10bitAddr)
{
    Lpi2c_Ip_MasterStateType * Master;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    Master->SlaveAddress = Address;
    Master->Is10bitAddr = Is10bitAddr;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSendData
 * Description   : perform a non-blocking send transaction on the I2C bus
 *
 * Implements : Lpi2c_Ip_MasterSendData_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSendData(uint8 Instance,
                                            uint8 * TxBuff,
                                            uint32 TxSize,
                                            boolean SendStop)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType *Master;
    Lpi2c_Ip_StatusType RetStatus = LPI2C_IP_BUSY_STATUS;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    /* Enter critical section */
    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_29();

    /* Check if driver is busy */
    if (Master->I2cIdle)
    {
        Master->I2cIdle = FALSE;

        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_29();

        /* Copy parameters to driver state structure */
        Master->BufferSize = TxSize;
        Master->DataBuffer = TxBuff;
        Master->Direction = LPI2C_IP_SEND;
        Master->SendStop = SendStop;
        Master->Status = LPI2C_IP_BUSY_STATUS;

        /* CPR_RTD_01182.i2c: Pending interrupt flags shall be cleared before enabling interrupts */
        LPI2C_Clear_MasterStatusFlags(BaseAddr, LPI2C_IP_FLAG_CONTROLLER_STATUS_REQUEST);

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        if (LPI2C_USING_DMA == Master->TransferType)
        {
            LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_FIFO_ERROR_INT            \
                                          | LPI2C_IP_MASTER_ARBITRATION_LOST_INT    \
                                          | LPI2C_IP_MASTER_NACK_DETECT_INT
                                ,TRUE);

            Lpi2c_Ip_MasterTxDmaConfig(Instance);
        }
        else
        {
#endif

            /* Enable relevant events */
#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
            if (LPI2C_ULTRAFAST_MODE == Master->OperatingMode)
            {
                /* Do not enable NACK event reporting in ultra-fast mode */
                LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_FIFO_ERROR_INT            \
                                              | LPI2C_IP_MASTER_ARBITRATION_LOST_INT
                                    ,TRUE);
            }
            else
#endif
            {
                LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_FIFO_ERROR_INT            \
                                              | LPI2C_IP_MASTER_ARBITRATION_LOST_INT    \
                                              | LPI2C_IP_MASTER_NACK_DETECT_INT         \
                                              | LPI2C_IP_MASTER_PIN_LOW_TIMEOUT_INT
                                    ,TRUE);
            }

            /* Initiate communication */
            Lpi2c_Ip_MasterSendAddress(BaseAddr, Master, FALSE);

            /* Queue data bytes to fill tx fifo */
            Lpi2c_Ip_MasterQueueData(BaseAddr, Master);

            /* Set tx FIFO watermark */
            LPI2C_Set_MasterTxFIFOWatermark(BaseAddr, 0U);

            /* Enables interrupt for transmit data */
            LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_TRANSMIT_DATA_INT, TRUE);

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        }
#endif
        RetStatus = LPI2C_IP_SUCCESS_STATUS;
    }
    else
    {
        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_29();
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterInitSendTransfer
 * Description   : initializes send transfer

 *END**************************************************************************/
static void Lpi2c_Ip_MasterInitSendTransfer(LPI2C_Type *BaseAddr,
                                            Lpi2c_Ip_MasterStateType *Master)
{
    /* Initiate communication */
    Lpi2c_Ip_MasterSendAddress(BaseAddr, Master, FALSE);

    /* Queue Data bytes to fill tx fifo */
    Lpi2c_Ip_MasterQueueData(BaseAddr, Master);

    /* Set tx FIFO watermark */
    LPI2C_Set_MasterTxFIFOWatermark(BaseAddr, 0U);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterSendDataBlocking
 * Description   : perform a blocking send transaction on the I2C bus
 *
 * Implements : Lpi2c_Ip_MasterSendDataBlocking_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSendDataBlocking(uint8 Instance,
                                                    uint8 * TxBuff,
                                                    uint32 TxSize,
                                                    boolean SendStop,
                                                    uint32 Timeout)
{
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, I2C_TIMEOUT_TYPE);
    Lpi2c_Ip_StatusType RetStatus = LPI2C_IP_BUSY_STATUS;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif
    LPI2C_Type *BaseAddr;
    BaseAddr = Lpi2c_Ip_pxBase[Instance];

    Lpi2c_Ip_MasterStateType *Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    /* Enter critical section */
    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_32();

    if (Master->I2cIdle)
    {
        Master->I2cIdle = FALSE;

        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_32();

        Master->BufferSize = TxSize;
        Master->DataBuffer = TxBuff;
        Master->Direction = LPI2C_IP_SEND;
        Master->SendStop = SendStop;
        
        Master->Status = LPI2C_IP_BUSY_STATUS;

        /* Initiate send transfer */
        Lpi2c_Ip_MasterInitSendTransfer(BaseAddr, Master);

        /* Get current ticks */
        CurrentTicks = OsIf_GetCounter(I2C_TIMEOUT_TYPE);

        do
        {
            /* Master send data */
            Lpi2c_Ip_MasterSend(Instance);
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, I2C_TIMEOUT_TYPE);

        }while ((Lpi2c_Ip_MasterGetTransferStatus(Instance, NULL_PTR) == LPI2C_IP_BUSY_STATUS) && (ElapsedTicks < TimeoutTicks));

        /* Check Timeout */
        if (ElapsedTicks >= TimeoutTicks)
        {
            Master->Status = LPI2C_IP_TIMEOUT_STATUS;
        }
        RetStatus = Master->Status;
    }
    else
    {
        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_32();
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterInterruptReceiveInit
 * Description   : configures interrupt receive transfer
 *END**************************************************************************/
static void Lpi2c_Ip_MasterInterruptReceiveInit(uint8 Instance,
                                                uint32 RxSize)
{
    LPI2C_Type *BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Lpi2c_Ip_MasterStateType *Master = Lpi2c_Ip_pxMasterState[Instance];
    uint16 RxBytes;

    /* Send Address */
    Lpi2c_Ip_MasterSendAddress(BaseAddr, Master, TRUE);

    if (I2C_MAX_DATA_RECEIVE_BYTE_PER_CMD < RxSize)
    {
    /* Queue receive command for RxSize bytes */
    Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(0xff));

    }
    else
    {
        /* Queue receive command for RxSize bytes */
        Lpi2c_Ip_MasterQueueCmd(BaseAddr, Master, LPI2C_MASTER_COMMAND_RECEIVE, (uint8)(RxSize - 1U));

    }

    /* Set rx FIFO watermark */
    RxBytes = LPI2C_Get_MasterRxFIFOSize(BaseAddr);
    if (RxBytes > RxSize)
    {
        RxBytes = (uint8)RxSize;
    }

    /* Set RX watermark */
    LPI2C_Set_MasterRxFIFOWatermark(BaseAddr, (uint16)(RxBytes - 1U));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterReceiveData
 * Description   : perform a non-blocking Receive transaction on the I2C bus
 *
 * Implements : Lpi2c_Ip_MasterReceiveData_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterReceiveData(uint8 Instance,
                                               uint8 * RxBuff,
                                               uint32 RxSize,
                                               boolean SendStop)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;
    Lpi2c_Ip_StatusType RetStatus = LPI2C_IP_BUSY_STATUS;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    /* Enter critical section */
    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_30();

    /* Check if driver is busy */
    if (!Master->I2cIdle)
    {
        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_30();

        RetStatus = LPI2C_IP_BUSY_STATUS;
    }
    else
    {
    #if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
        if (LPI2C_ULTRAFAST_MODE == Master->OperatingMode)
        {
            /* Exit critical section */
            SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_30();

            /* No reception possible in ultra-fast mode */
            RetStatus = LPI2C_IP_ERROR_STATUS;
        }
        else
        {
    #endif
            Master->I2cIdle = FALSE;
            /* Exit critical section */
            SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_30();

            RetStatus = LPI2C_IP_SUCCESS_STATUS;
            /* Copy parameters to driver state structure */
            Master->BufferSize = RxSize;
            Master->SendStop = SendStop;
            Master->DataBuffer = RxBuff;
            Master->Direction = LPI2C_IP_RECEIVE;
            Master->Status = LPI2C_IP_BUSY_STATUS;

            /* CPR_RTD_01182.i2c: Pending interrupt flags shall be cleared before enabling interrupts */
            LPI2C_Clear_MasterStatusFlags(BaseAddr, LPI2C_IP_FLAG_CONTROLLER_STATUS_REQUEST);

        #if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
            if (LPI2C_USING_DMA == Master->TransferType)
            {
                LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_FIFO_ERROR_INT            \
                                              | LPI2C_IP_MASTER_ARBITRATION_LOST_INT    \
                                              | LPI2C_IP_MASTER_NACK_DETECT_INT
                                    ,TRUE);

                Lpi2c_Ip_MasterRxDmaConfig(Instance);
            }
            else
            {
        #endif

                /* Enable tx event too if there are commands in the software FIFO */
                LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_FIFO_ERROR_INT            \
                                              | LPI2C_IP_MASTER_ARBITRATION_LOST_INT    \
                                              | LPI2C_IP_MASTER_NACK_DETECT_INT         \
                                              | LPI2C_IP_MASTER_RECEIVE_DATA_INT
                                        ,TRUE);

                /* Init interrupt receive transfer */
                Lpi2c_Ip_MasterInterruptReceiveInit(Instance, RxSize);
                Master->ByteReceiveCount = 0U;

                /* Enable relevant events */
                if (!Lpi2c_Ip_MasterCmdQueueEmpty(Master))
                {
                    /* Enable tx event too if there are commands in the software FIFO */
                    LPI2C_Set_MasterInt(BaseAddr, LPI2C_IP_MASTER_TRANSMIT_DATA_INT,TRUE);
                }

        #if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
            }
        #endif
    #if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
        }
    #endif
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterReceiveDataBlocking
 * Description   : perform a blocking receive transaction on the I2C bus
 *
 * Implements : Lpi2c_Ip_MasterReceiveDataBlocking_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterReceiveDataBlocking(uint8 Instance,
                                                       uint8 * RxBuff,
                                                       uint32 RxSize,
                                                       boolean SendStop,
                                                       uint32 Timeout)
{
    Lpi2c_Ip_MasterStateType * Master;

    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, I2C_TIMEOUT_TYPE);
    Lpi2c_Ip_StatusType RetStatus = LPI2C_IP_BUSY_STATUS;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    /* Enter critical section */
    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_31();

    if (Master->I2cIdle)
    {
        Master->I2cIdle = FALSE;

        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_31();

        Master->BufferSize = RxSize;
        Master->DataBuffer = RxBuff;
        Master->Direction = LPI2C_IP_RECEIVE;
        Master->SendStop = SendStop;
        Master->Status = LPI2C_IP_BUSY_STATUS;

        /* Initiate communication */
        Lpi2c_Ip_MasterInterruptReceiveInit(Instance, RxSize);

        CurrentTicks = OsIf_GetCounter(I2C_TIMEOUT_TYPE);
        Master->ByteReceiveCount = 0U;
        do
        {
            /* Master send data */
            Lpi2c_Ip_MasterReceive(Instance);
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, I2C_TIMEOUT_TYPE);

        }while ((Lpi2c_Ip_MasterGetTransferStatus(Instance, NULL_PTR) == LPI2C_IP_BUSY_STATUS) && (ElapsedTicks < TimeoutTicks));

        if (ElapsedTicks >= TimeoutTicks)
        {
            Master->Status = LPI2C_IP_TIMEOUT_STATUS;
        }
        RetStatus = Master->Status;
    }
    else
    {
        /* Exit critical section */
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_31();
    }

    return RetStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterGetTransferStatus
 * Description   : return the current status of the I2C master transfer
 *
 * When performing an a-sync (non-blocking) transfer, the user can call this function
 * to ascertain the state of the current transfer. In addition, if the transfer is still
 * in progress, the user can get the number of words that should be receive.
 *
 * Implements : Lpi2c_Ip_MasterGetTransferStatus_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterGetTransferStatus(uint8 Instance,
                                                     uint32 *BytesRemaining)
{
    const Lpi2c_Ip_MasterStateType * Master;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    if ((BytesRemaining != NULL_PTR) && (LPI2C_USING_INTERRUPTS == Master->TransferType))
    {
        *BytesRemaining = Master->BufferSize;
    }

    return Master->Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterCheckDataTxRxEvent
 * Description   : checks if data send or data receive event occurred
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterCheckDataTxRxEvent(LPI2C_Type *BaseAddr,
                                              Lpi2c_Ip_MasterStateType * Master)
{

    if (LPI2C_Get_MasterTransmitDataRequestEvent(BaseAddr))
    {   /* Send data event */
        Lpi2c_Ip_MasterHandleTransmitDataRequest(BaseAddr, Master);
    }

    if ((LPI2C_Get_MasterReceiveDataReadyEvent(BaseAddr)))
    {
        /* Receive data event */
        Lpi2c_Ip_MasterHandleReceiveDataReadyEvent(BaseAddr, Master);
    }
}

#ifdef LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterBusRecovery
 * Description   : Handle relax mode.
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterBusRecovery(LPI2C_Type *BaseAddr,
                                       Lpi2c_Ip_MasterStateType * Master)
{
    /* Use relax mode to attempt to recover a target with SDA stuck low */
    LPI2C_Set_RelaxMode(BaseAddr, TRUE);
    
    /* Initiating a Start command with address 0xFFh, then the Stop condition (refer to chapter 57.3.1.5 Error conditions in reference manual) */
    LPI2C_Cmd_MasterTransmit(BaseAddr, LPI2C_MASTER_COMMAND_START, 0xFF);
    
    Lpi2c_Ip_MasterEndTransfer(BaseAddr, Master, Master->SendStop, FALSE);
}
#endif /* LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterIRQHandlerInternal
 * Description   : handle non-blocking master operation when I2C interrupt occurs
 *
 *END**************************************************************************/
static void Lpi2c_Ip_MasterIRQHandlerInternal(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_MasterStateType * Master;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Master = Lpi2c_Ip_pxMasterState[Instance];


    /* Check which event caused the interrupt */
    Lpi2c_Ip_MasterCheckDataTxRxEvent(BaseAddr, Master);

    /* Master check error events */
    Lpi2c_Ip_MasterCheckErrorEvents(BaseAddr, Master);

    /* Check Pin Timeout Flag */
    if (LPI2C_Get_MasterPinLowTimeoutEvent(BaseAddr))
    {
        /* CPR_RTD_00516.i2c: Clearing the interrupt flag at the beginning of the ISR */
        LPI2C_Clear_MasterPinLowTimeoutEvent(BaseAddr);

        if (Master->MasterCallback != NULL_PTR)
        {
            Master->MasterCallback(I2C_MASTER_EVENT_PIN_LOW_TIMEOUT, Master->CallbackParam);
        }

#ifdef LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE
        Lpi2c_Ip_MasterBusRecovery(BaseAddr, Master);
#endif
    }
}

static void Lpi2c_Ip_SlaveActivateEvents(uint8 Instance)
{
    LPI2C_Type *BaseAddr;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    const Lpi2c_Ip_SlaveStateType *Slave = Lpi2c_Ip_pxSlaveState[Instance];

    /* CPR_RTD_01182.i2c: Pending interrupt flags shall be cleared before enabling interrupts */
    LPI2C_Clear_SlaveStatusFlags(BaseAddr, LPI2C_IP_FLAG_TARGET_STATUS_REQUEST);

    if (LPI2C_USING_DMA == Slave->TransferType)
    {
       /* Activate events */
       LPI2C_Set_SlaveInt(BaseAddr, LPI2C_IP_SLAVE_BIT_ERROR_INT |
                                    LPI2C_IP_SLAVE_FIFO_ERROR_INT |
                                    LPI2C_IP_SLAVE_STOP_DETECT_INT |
                                    LPI2C_IP_SLAVE_REPEATED_START_INT |
                                    LPI2C_IP_SLAVE_ADDRESS_VALID_INT,
                                    TRUE);
    }

    if (LPI2C_USING_INTERRUPTS == Slave->TransferType)
    {
           /* Activate events */
#if defined(ERRATA_E10792)
        LPI2C_Set_SlaveInt(BaseAddr, LPI2C_IP_SLAVE_BIT_ERROR_INT |
                                     LPI2C_IP_SLAVE_FIFO_ERROR_INT |
                                     LPI2C_IP_SLAVE_STOP_DETECT_INT |
                                     LPI2C_IP_SLAVE_REPEATED_START_INT |
                                     LPI2C_IP_SLAVE_ADDRESS_VALID_INT |
                                     LPI2C_IP_SLAVE_RECEIVE_DATA_INT,
                                     TRUE);

#else
        LPI2C_Set_SlaveInt(BaseAddr, LPI2C_IP_SLAVE_BIT_ERROR_INT |
                                     LPI2C_IP_SLAVE_FIFO_ERROR_INT |
                                     LPI2C_IP_SLAVE_STOP_DETECT_INT |
                                     LPI2C_IP_SLAVE_REPEATED_START_INT |
                                     LPI2C_IP_SLAVE_ADDRESS_VALID_INT |
                                     LPI2C_IP_SLAVE_RECEIVE_DATA_INT |
                                     LPI2C_IP_SLAVE_TRANSMIT_DATA_INT,
                                     TRUE);

#endif

    }

    /* Enable LPI2C slave */
    LPI2C_Set_SlaveEnable(BaseAddr, TRUE);

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveConigureAddress
 * Description   : configures slave address
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveConigureAddress(LPI2C_Type *BaseAddr,
                                          uint16 SlaveAddr,
                                          boolean Is10bitAddr)
{
    LPI2C_Set_SlaveAddr0(BaseAddr, SlaveAddr);

    if (Is10bitAddr)
    {
        LPI2C_Set_SlaveAddrConfig(BaseAddr, LPI2C_SLAVE_ADDR_MATCH_0_10BIT);
    }
    else
    {
        LPI2C_Set_SlaveAddrConfig(BaseAddr, LPI2C_SLAVE_ADDR_MATCH_0_7BIT);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveConfigureGlitchFilter
 * Description   : configures slave glitch filter
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveConfigureGlitchFilter(LPI2C_Type *BaseAddr,
                                                uint32 GlitchFilterSDA,
                                                uint32 GlitchFilterSCL)
{
    /* Set SDA glitch filter */
    LPI2C_Set_SlaveGlitchFilterSDA(BaseAddr, GlitchFilterSDA);
    /* Set SCL glitch filter */
    LPI2C_Set_SlaveGlitchFilterSCL(BaseAddr, GlitchFilterSCL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveInit
 * Description   : initialize the I2C slave mode driver
 *
 * Implements : Lpi2c_Ip_SlaveInit_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_SlaveInit(uint8 Instance,
                        const Lpi2c_Ip_SlaveConfigType * ConfigPtr)
{
    LPI2C_Type *BaseAddr;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(ConfigPtr != NULL_PTR);
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    DevAssert(Lpi2c_Ip_pxSlaveState[Instance] == NULL_PTR);
#endif

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
#if (LPI2C_IP_NUMBER_OF_SLAVE_INSTANCES != 0U)
    Lpi2c_Ip_pxSlaveState[Instance] = &(Lpi2c_Ip_SlaveState[ConfigPtr->SlaveStateIdx]);
#endif
    Lpi2c_Ip_SlaveStateType * Slave = Lpi2c_Ip_pxSlaveState[Instance];

    /* Initialize driver status structure */
    Slave->Status = LPI2C_IP_SUCCESS_STATUS;
    Slave->SlaveCallback = ConfigPtr->SlaveCallback;
    Slave->CallbackParam = ConfigPtr->CallbackParam;
    Slave->DataBuffer = NULL_PTR;
    Slave->BufferSize = 0U;
    Slave->Direction = LPI2C_IP_SEND;
    Slave->TransferType = ConfigPtr->TransferType;
    /* Store DMA channel number used in transfer */
    Slave->DmaTxChannel = ConfigPtr->DmaTxChannel;
    Slave->DmaRxChannel = ConfigPtr->DmaRxChannel;
    Slave->IsTransferInProgress = FALSE;
    Slave->Is10bitAddress = ConfigPtr->Is10bitAddr;
    Slave->RepeatedStarts = 0U;
    Slave->SlaveListening = ConfigPtr->SlaveListening;

    /* Initialize module */
    Lpi2c_Ip_Init(BaseAddr);

    /* Configure slave address */
    Lpi2c_Ip_SlaveConigureAddress(BaseAddr, ConfigPtr->SlaveAddress, ConfigPtr->Is10bitAddr);

    /* Configure operating mode */
    Lpi2c_Ip_SlaveSetOperatingMode(Instance, ConfigPtr->OperatingMode);

    /* Set glitch filters for SDA and SCL */
    Lpi2c_Ip_SlaveConfigureGlitchFilter(BaseAddr, ConfigPtr->GlitchFilterSDA, ConfigPtr->GlitchFilterSCL);

    if (Slave->SlaveListening)
    {
        Lpi2c_Ip_SlaveActivateEvents(Instance);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_StartListening
 * Description   : Makes a slave channel available for processing request in case
 *                 slave is in not listening mode
 * Implements    : I2c_Ip_StartListening_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_StartListening(uint8 Instance)
{
    const Lpi2c_Ip_SlaveStateType * Slave;

    Slave = Lpi2c_Ip_pxSlaveState[Instance];

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
    DevAssert(!Slave->SlaveListening);
#endif

    Lpi2c_Ip_SlaveActivateEvents(Instance);
    (void) Slave;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveDeinit
 * Description   : de-initialize the I2C slave mode driver
 *
 * Implements : Lpi2c_Ip_SlaveDeinit_Activity
 *
 *END**************************************************************************/
void Lpi2c_Ip_SlaveDeinit(uint8 Instance)
{
    LPI2C_Type *BaseAddr;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    const Lpi2c_Ip_SlaveStateType *Slave = Lpi2c_Ip_pxSlaveState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
#endif
    if ((LPI2C_USING_DMA == Slave->TransferType) && (TRUE == Slave->SlaveListening))
    {
        /* Disable LPI2C DMA requests. */
        (void)LPI2C_Set_SlaveRxDMA(BaseAddr, FALSE);
        (void)LPI2C_Set_SlaveTxDMA(BaseAddr, FALSE);
    }

    Lpi2c_Ip_pxSlaveState[Instance] = NULL_PTR;

    /* Clear all status request flags */
    BaseAddr->SSR = LPI2C_IP_FLAG_TARGET_STATUS_REQUEST;

    /* Disable LPI2C slave */
    LPI2C_Set_SlaveEnable(BaseAddr, FALSE);

    /* Reset registers value to default value*/
    BaseAddr->SCR    = 0x0U;
    BaseAddr->SIER   = 0x0U;
    BaseAddr->SCFGR1 = 0x0U;
    BaseAddr->SCFGR2 = 0x0U;
    BaseAddr->SAMR   = 0x0U;
    BaseAddr->STDR   = 0x0U;
    BaseAddr->SDER   = 0x0U;
    BaseAddr->STAR   = 0x0U;

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveSetTxBuffer
 * Description   : Provide a buffer for transmitting data.
 *
 * Implements : Lpi2c_Ip_SlaveSetTxBuffer_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_SlaveSetBuffer(uint8 Instance,
                                            uint8 * DataBuff,
                                            uint32 DataSize)
{
    Lpi2c_Ip_SlaveStateType * Slave;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
    DevAssert(DataBuff != NULL_PTR);
    DevAssert(DataSize > 0U);
#endif
    Slave = Lpi2c_Ip_pxSlaveState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
#endif
    Slave->DataBuffer = DataBuff;
    Slave->BufferSize = DataSize;

    return LPI2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveGetTransferStatus
 * Description   : return the current status of the I2C slave transfer
 *
 * When performing an a-sync (non-blocking) transfer, the user can call this function
 * to ascertain the state of the current transfer. In addition, if the transfer is still
 * in progress, the user can get the number of words that should be receive.
 *
 * Implements : Lpi2c_Ip_SlaveGetTransferStatus_Activity
 *
 *END**************************************************************************/
Lpi2c_Ip_StatusType Lpi2c_Ip_SlaveGetTransferStatus(uint8 Instance,
                                                    uint32 *BytesRemaining)
{
    const Lpi2c_Ip_SlaveStateType *Slave;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Slave = Lpi2c_Ip_pxSlaveState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
#endif
    if ((BytesRemaining != NULL_PTR) && (LPI2C_USING_INTERRUPTS == Slave->TransferType))
    {
        *BytesRemaining = Slave->BufferSize;
    }

    return Slave->Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPI2C_DRV_SlaveEndTransfer
 * Description   : ends current transmission or reception
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveEndTransfer(LPI2C_Type *BaseAddr)
{
    /* Deactivate events */

    LPI2C_Set_SlaveInt(BaseAddr, LPI2C_IP_SLAVE_BIT_ERROR_INT |
                                    LPI2C_IP_SLAVE_FIFO_ERROR_INT |
                                    LPI2C_IP_SLAVE_STOP_DETECT_INT |
                                    LPI2C_IP_SLAVE_REPEATED_START_INT |
                                    LPI2C_IP_SLAVE_ADDRESS_VALID_INT |
                                    LPI2C_IP_SLAVE_RECEIVE_DATA_INT |
                                    LPI2C_IP_SLAVE_TRANSMIT_DATA_INT,
                          FALSE);

    /* Disable LPI2C Slave */
    LPI2C_Set_SlaveEnable(BaseAddr, FALSE);


}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveEndTransferHandler
 * Description   : handle slave end transfer operations
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveEndTransferHandler(const Lpi2c_Ip_SlaveStateType *Slave,
                                             LPI2C_Type *BaseAddr)
{
    /* Check Slave state */
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
#endif

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
    /* Stop DMA channel if slave is transferring data in DMA mode */
    if (LPI2C_USING_DMA == Slave->TransferType)
    {
        if (LPI2C_IP_SEND == Slave->Direction)
        {
            /* Stop TX DMA channel */
            (void)Dma_Ip_SetLogicChannelCommand(Slave->DmaTxChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        }
        else
        {
            /* Stop RX DMA channel */
            (void)Dma_Ip_SetLogicChannelCommand(Slave->DmaRxChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        }
    }
#endif

    if (!Slave->SlaveListening)
    {
        Lpi2c_Ip_SlaveEndTransfer(BaseAddr);
    }

    if (Slave->SlaveCallback != NULL_PTR)
    {
        Slave->SlaveCallback(I2C_SLAVE_EVENT_STOP, Slave->CallbackParam);
    }

    (void) BaseAddr;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveCheckDataEvent
 * Description   : check slave adress valid and tx/rx event
 *
 * @implements Lpi2c_Ip_SlaveCheckDataEvent_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveCheckDataEvent(uint8 Instance,
                                         LPI2C_Type *BaseAddr,
                                         Lpi2c_Ip_SlaveStateType * Slave)
{
    boolean SlaveInterrupt = FALSE;

    /* Check which event caused the interrupt */
    if (LPI2C_Get_SlaveAddressValidEvent(BaseAddr))
    {
        Lpi2c_Ip_SlaveHandleAddressValidEvent(Instance, BaseAddr, Slave);
    }

    /* Check transmit event */
    if (LPI2C_Get_SlaveTransmitDataEvent(BaseAddr))
    {
        SlaveInterrupt = LPI2C_Get_SlaveInt(BaseAddr, (uint32)LPI2C_IP_SLAVE_TRANSMIT_DATA_INT);
        if (SlaveInterrupt)
        {
            /* Handle transmit event */
            Lpi2c_Ip_SlaveHandleTransmitDataEvent(BaseAddr, Slave);
        }
    }

    /* Check receive event */
    if (LPI2C_Get_SlaveReceiveDataEvent(BaseAddr))
    {
        SlaveInterrupt = LPI2C_Get_SlaveInt(BaseAddr, (uint32)LPI2C_IP_SLAVE_RECEIVE_DATA_INT);
        if (SlaveInterrupt)
        {
            /* Handle receive event */
            Lpi2c_Ip_SlaveHandleReceiveDataEvent(BaseAddr, Slave);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveStopDetectHandler
 * Description   : handles stop/repeated start event
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveStopDetectHandler(LPI2C_Type *BaseAddr,
                                            Lpi2c_Ip_SlaveStateType * Slave)
{
    /* Either STOP or repeated START have the same meaning here: the current transfer is over */
    LPI2C_Clear_SlaveSTOPDetectEvent(BaseAddr);
    LPI2C_Clear_SlaveRepeatedStartEvent(BaseAddr);

#if defined(ERRATA_E10792)
    /* Deactivate interrupts for transmitting Data */
    LPI2C_Set_SlaveInt(BaseAddr, (uint32)LPI2C_IP_SLAVE_TRANSMIT_DATA_INT, FALSE);
#endif

    if (LPI2C_IP_BUSY_STATUS == Slave->Status)
    {
        /* Report success if no error was recorded */
        Slave->Status = LPI2C_IP_SUCCESS_STATUS;
    }

    Lpi2c_Ip_SlaveEndTransferHandler(Slave, BaseAddr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveBitErrorEventHandler
 * Description   : handles Slave bit error event
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveBitErrorEventHandler(LPI2C_Type *BaseAddr,
                                               Lpi2c_Ip_SlaveStateType * Slave)
{
    Slave->Status = LPI2C_IP_ERROR_STATUS;

    LPI2C_Clear_SlaveBitErrorEvent(BaseAddr);

#if (STD_ON == LPI2C_IP_EVENT_ERROR_DETECT)
    if (Slave->SlaveCallback != NULL_PTR)
    {
        Slave->SlaveCallback(I2C_SLAVE_EVENT_ERROR_BIT, Slave->CallbackParam);
    }
#endif

#if defined(ERRATA_E10792)
    /* Deactivate interrupts for transmitting Data */
    LPI2C_Set_SlaveInt(BaseAddr, (uint32)LPI2C_IP_SLAVE_TRANSMIT_DATA_INT, FALSE);
#endif

    /* Slave end transfer */
    Lpi2c_Ip_SlaveEndTransferHandler(Slave, BaseAddr);
}

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveFIFOErrorEventHandler
 * Description   : handles Slave FIFO error event
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveFIFOErrorEventHandler(LPI2C_Type *BaseAddr,
                                                Lpi2c_Ip_SlaveStateType * Slave)
{
    /* In Ultra-Fast mode clock stretching is disabled, so it is possible to get
    this event if the slave can't keep up */
    Slave->Status = LPI2C_IP_RX_OVERRUN_STATUS;
    LPI2C_Clear_SlaveFIFOErrorEvent(BaseAddr);

#if defined(ERRATA_E10792)
    /* Deactivate interrupts for transmitting data */
    LPI2C_Set_SlaveInt(BaseAddr, LPI2C_IP_SLAVE_TRANSMIT_DATA_INT, FALSE);
#endif

    Lpi2c_Ip_SlaveEndTransferHandler(Slave, BaseAddr);
}
#endif

#if ((STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE) && (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT))
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveDmaTransferErrorHandler
 * Description   : handles Slave dma transfer error
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveDmaTransferErrorHandler(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Dma_Ip_LogicChannelStatusType DmaStatus;
    Lpi2c_Ip_SlaveStateType *Slave;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Slave = Lpi2c_Ip_pxSlaveState[Instance];
    DmaStatus.ChStateValue = DMA_IP_CH_RESET_STATE;

    if (LPI2C_IP_SEND == Slave->Direction)
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(Slave->DmaTxChannel, &DmaStatus);
    }
    else
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(Slave->DmaRxChannel, &DmaStatus);
    }

    if (DMA_IP_CH_ERROR_STATE == DmaStatus.ChStateValue)
    {
        /* Signal transfer end for blocking transfers */
        Lpi2c_Ip_SlaveEndTransferHandler(Slave, BaseAddr);

        /* Report status error if an error occurred in EDMA channel */
        Slave->Status = LPI2C_IP_DMA_ERROR_STATUS;

        if (Slave->SlaveCallback != NULL_PTR)
        {
            Slave->SlaveCallback(I2C_SLAVE_EVENT_DMA_TRANSFER_ERROR, Slave->CallbackParam);
        }
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveCheckErrorEvent
 * Description   : checks for slave errors
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveCheckErrorEvent(LPI2C_Type *BaseAddr,
                                          Lpi2c_Ip_SlaveStateType * Slave)
{
    if (LPI2C_Get_SlaveBitErrorEvent(BaseAddr))
    {
        /* Handle slave bit error event */
        Lpi2c_Ip_SlaveBitErrorEventHandler(BaseAddr, Slave);
    }

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
    if (LPI2C_Get_SlaveFIFOErrorEvent(BaseAddr))
    {
        /* Handle Slave FIFO error event */
        Lpi2c_Ip_SlaveFIFOErrorEventHandler(BaseAddr, Slave);
    }
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveIRQHandlerInternal
 * Description   : handle non-blocking slave operation when I2C interrupt occurs
 *
 * @implements Lpi2c_Ip_SlaveIRQHandlerInternal_Activity
 *
 *END**************************************************************************/
static void Lpi2c_Ip_SlaveIRQHandlerInternal(uint8 Instance)
{
    LPI2C_Type *BaseAddr;
    Lpi2c_Ip_SlaveStateType * Slave;
    boolean StopDetect = FALSE;
    boolean RepeatStartDetect = FALSE;

    BaseAddr = Lpi2c_Ip_pxBase[Instance];
    Slave = Lpi2c_Ip_pxSlaveState[Instance];

    StopDetect =  LPI2C_Get_SlaveSTOPDetectEvent(BaseAddr);
    RepeatStartDetect = LPI2C_Get_SlaveRepeatedStartEvent(BaseAddr);

    /* Check address valid and tx/rx event */
    Lpi2c_Ip_SlaveCheckDataEvent(Instance, BaseAddr, Slave);

    if (RepeatStartDetect)
    {
        Slave->RepeatedStarts++;

        if ((1U == Slave->RepeatedStarts) && (Slave->Is10bitAddress))
        {
            RepeatStartDetect = FALSE;
            LPI2C_Clear_SlaveRepeatedStartEvent(BaseAddr);
        }
    }

    if ((TRUE == StopDetect) || (TRUE == RepeatStartDetect))
    {
        /* Stop/repeated start detected */
        Lpi2c_Ip_SlaveStopDetectHandler(BaseAddr, Slave);

        if (TRUE == StopDetect)
        {
            /* reset repetead starts for a new transfer */
            Slave->RepeatedStarts = 0U;
        }
    }

    /* Check for slave errors */
    Lpi2c_Ip_SlaveCheckErrorEvent(BaseAddr, Slave);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterIRQHandler
 * Description   : perform safety checks when I2C interrupt occurs
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterIRQHandler(uint8 Instance)
{
    uint32 IsrEnable;
    uint32 IsrStatus;

#if !defined (LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE)
    /* NOTE:
     * - The checks below are only needed in case "LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE" is not defined (separated interrupt vectors for Master and Slave)
     * - When "LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE" is defined, these checks will be performed in the function "Lpi2c_Ip_ModuleIRQHandler"
     */

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif

    /* Check whether the respective driver is initialized */
    if (NULL_PTR == Lpi2c_Ip_pxMasterState[Instance])
    {
        /* CPR_RTD_00011
         * The driver is not initialized, only clear interrupt status flag and return immediately
         */
        Lpi2c_Ip_pxBase[Instance]->MSR &= (uint32)0xFFFFFFFFU;
    }
    else
#endif /* LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE */
    {
        /* The driver has been initialized */
        IsrEnable = Lpi2c_Ip_pxBase[Instance]->MIER & (LPI2C_MIER_PLTIE_MASK | LPI2C_MIER_FEIE_MASK | LPI2C_MIER_ALIE_MASK |
                                                       LPI2C_MIER_NDIE_MASK  | LPI2C_MIER_RDIE_MASK | LPI2C_MIER_TDIE_MASK
                                                       );

        IsrStatus = Lpi2c_Ip_pxBase[Instance]->MSR  & (LPI2C_MSR_PLTF_MASK | LPI2C_MSR_FEF_MASK | LPI2C_MSR_ALF_MASK |
                                                       LPI2C_MSR_NDF_MASK  | LPI2C_MSR_RDF_MASK | LPI2C_MSR_TDF_MASK
                                                       );

        /* CPR_RTD_00664
         * Check if the interrupt not spurious (respective interrupt status flag and interrupt enable flag are set)
         * Ignore spurious ones (return immediately from ISR)
         */
        if (0u != (IsrEnable & IsrStatus))
        {
            Lpi2c_Ip_MasterIRQHandlerInternal(Instance);
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveIRQHandler
 * Description   : perform safety checks when I2C interrupt occurs
 *
 *END**************************************************************************/
void Lpi2c_Ip_SlaveIRQHandler(uint8 Instance)
{
    uint32 IsrEnable;
    uint32 IsrStatus;

#if !defined (LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE)
    /* NOTE:
     * - The checks below are only needed in case "LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE" is not defined (separated interrupt vectors for Master and Slave)
     * - When "LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE" is defined, these checks will be performed in the function "Lpi2c_Ip_ModuleIRQHandler"
     */

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif

    /* Check whether the respective driver is initialized */
    if (NULL_PTR == Lpi2c_Ip_pxSlaveState[Instance])
    {
        /* CPR_RTD_00011
         * The driver is not initialized, only clear interrupt status flag and return immediately
         */
        Lpi2c_Ip_pxBase[Instance]->SSR &= (uint32)0xFFFFFFFFU;
    }
    else
#endif /* LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE */
    {
        /* The driver has been initialized */
        IsrEnable = Lpi2c_Ip_pxBase[Instance]->SIER & (LPI2C_SIER_FEIE_MASK | LPI2C_SIER_BEIE_MASK | LPI2C_SIER_SDIE_MASK | LPI2C_SIER_RSIE_MASK  |
                                                       LPI2C_SIER_AVIE_MASK | LPI2C_SIER_RDIE_MASK | LPI2C_SIER_TDIE_MASK);

        IsrStatus = Lpi2c_Ip_pxBase[Instance]->SSR  & (LPI2C_SSR_FEF_MASK | LPI2C_SSR_BEF_MASK | LPI2C_SSR_SDF_MASK | LPI2C_SSR_RSF_MASK  |
                                                       LPI2C_SSR_AVF_MASK | LPI2C_SSR_RDF_MASK | LPI2C_SSR_TDF_MASK);

        /* CPR_RTD_00664
         * Check if the interrupt not spurious (respective interrupt status flag and interrupt enable flag are set)
         * Ignore spurious ones (return immediately from ISR)
         */
        if (0u != (IsrEnable & IsrStatus))
        {
            Lpi2c_Ip_SlaveIRQHandlerInternal(Instance);
        }
    }
}

#if defined (LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE)

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_ModuleIRQHandler
 * Description   : handle events for lpi2c module
 *
 *END**************************************************************************/
void Lpi2c_Ip_ModuleIRQHandler(uint8 Instance)
{
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif

    LPI2C_Type *BaseAddr;

    /* Check whether the respective driver (either Master or Slave) is initialized */
    if ((NULL_PTR == Lpi2c_Ip_pxSlaveState[Instance]) && (NULL_PTR == Lpi2c_Ip_pxMasterState[Instance]))
    {
        /* CPR_RTD_00011: the driver is not initialized, only clear interrupt status flag and return immediately */
        BaseAddr = Lpi2c_Ip_pxBase[Instance];
        BaseAddr->MSR &= (uint32)0xFFFFFFFFU;
        BaseAddr->SSR &= (uint32)0xFFFFFFFFU;
    }
    else
    {
        /* Check if it is master or slave */
        if (NULL_PTR == Lpi2c_Ip_pxSlaveState[Instance])
        {
            Lpi2c_Ip_MasterIRQHandler(Instance);
        }
        else
        {
            Lpi2c_Ip_SlaveIRQHandler(Instance);
        }
    }
}

#endif /* LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE */

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)


#if (LPI2C_INSTANCE_COUNT > 0u)

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_DmaCompleteNotification0
 * Description   : Dma complete notification for instance 0
 *
 *END**************************************************************************/
void Lpi2c_Ip_DmaCompleteNotification0(void)
{
    Lpi2c_Ip_MasterCompleteDMATransfer(0U - (uint8)(LPI2C_IP_OFFSET_INSTANCE));
}

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterDmaErrorNotification0
 * Description   : Dma error notification for instance 0 master mode
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterDmaErrorNotification0(void)
{
    Lpi2c_Ip_MasterDMATransferErrorHandler(0U - (uint8)(LPI2C_IP_OFFSET_INSTANCE));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveDmaErrorNotification0
 * Description   : Dma error notification for instance 0 slave mode
 *
 *END**************************************************************************/
void Lpi2c_Ip_SlaveDmaErrorNotification0(void)
{
    Lpi2c_Ip_SlaveDmaTransferErrorHandler(0U - (uint8)(LPI2C_IP_OFFSET_INSTANCE));
}
#endif /* STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT */
#endif /* (LPI2C_INSTANCE_COUNT > 0u) */


#if (LPI2C_INSTANCE_COUNT > 1u)

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_DmaCompleteNotification1
 * Description   : Dma complete notification for instance 1
 *
 *END**************************************************************************/
void Lpi2c_Ip_DmaCompleteNotification1(void)
{
    Lpi2c_Ip_MasterCompleteDMATransfer(1U - (uint8)(LPI2C_IP_OFFSET_INSTANCE));
}

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_MasterDmaErrorNotification1
 * Description   : Dma error notification for instance 1 master mode
 *
 *END**************************************************************************/
void Lpi2c_Ip_MasterDmaErrorNotification1(void)
{
    Lpi2c_Ip_MasterDMATransferErrorHandler(1U - (uint8)(LPI2C_IP_OFFSET_INSTANCE));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SlaveDmaErrorNotification1
 * Description   : Dma error notification for instance 1 slave mode
 *
 *END**************************************************************************/
void Lpi2c_Ip_SlaveDmaErrorNotification1(void)
{
    Lpi2c_Ip_SlaveDmaTransferErrorHandler(1U - (uint8)(LPI2C_IP_OFFSET_INSTANCE));
}
#endif /* STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT */
#endif /* (LPI2C_INSTANCE_COUNT > 1u) */


#endif /* STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SetMasterCallback
 * Description   : Sets the master callback
 *
 *END**************************************************************************/
void Lpi2c_Ip_SetMasterCallback(uint8 Instance,
                                Lpi2c_Ip_MasterCallbackType MasterCallback)
{
    Lpi2c_Ip_MasterStateType * Master;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    Master->MasterCallback = MasterCallback;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SetSlaveCallback
 * Description   : Sets the slave callback
 *
 *END**************************************************************************/
void Lpi2c_Ip_SetSlaveCallback(uint8 Instance,
                               Lpi2c_Ip_SlaveCallbackType SlaveCallback)
{
    Lpi2c_Ip_SlaveStateType * Slave;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Slave = Lpi2c_Ip_pxSlaveState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Slave != NULL_PTR);
#endif

    Slave->SlaveCallback = SlaveCallback;
}

#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_SetMasterHighSpeedMode
 * Description   : Sets high speed mode for master
 *
 *END**************************************************************************/
void Lpi2c_Ip_SetMasterHighSpeedMode(uint8 Instance,
                                     boolean HighSpeedEnabled)
{
    Lpi2c_Ip_MasterStateType * Master;

#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < LPI2C_INSTANCE_COUNT);
#endif
    Master = Lpi2c_Ip_pxMasterState[Instance];
#if (STD_ON == LPI2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    if (TRUE == HighSpeedEnabled)
    {
        /* Set high speed operating mode */
        Master->OperatingMode = LPI2C_HIGHSPEED_MODE;
    }
    else
    {
        /* High speed mode is not selected */
        Master->OperatingMode = LPI2C_STANDARD_MODE;
    }
}
#endif /* STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
