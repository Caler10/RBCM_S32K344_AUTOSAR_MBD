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
*   @file    Lpspi_Ip.c
*   @implements     Lpspi_Ip.c_Artifact
*
*   @brief   LPSPI low-level driver implementations.
*   @details LPSPI low-level driver implementations.
*
*   @addtogroup LPSPI_DRIVER Lpspi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Lpspi_Ip.h"
#include "Lpspi_Ip_Cfg.h"
#include "OsIf.h"
#if (LPSPI_IP_DMA_USED == STD_ON)
    #include "Dma_Ip.h"
#endif
#if (LPSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
   #define USER_MODE_REG_PROT_ENABLED   (LPSPI_IP_ENABLE_USER_MODE_SUPPORT)
   #include "RegLockMacros.h"
#endif
#include "SchM_Spi.h"
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_VENDOR_ID_C                      43
#define LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define LPSPI_IP_AR_RELEASE_MINOR_VERSION_C       7
#define LPSPI_IP_AR_RELEASE_REVISION_VERSION_C    0
#define LPSPI_IP_SW_MAJOR_VERSION_C               5
#define LPSPI_IP_SW_MINOR_VERSION_C               0
#define LPSPI_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lpspi_Ip.c and Mcal.h are different"
    #endif

    #if (LPSPI_IP_DMA_USED == STD_ON)
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
             (DMA_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of Lpspi_Ip.c and Dma_Ip.h are different"
        #endif
    #endif

    #if (LPSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
        #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lpspi_Ip.c and RegLockMacros.h are different"
        #endif
    #endif

    /* Check if the current file and SchM_Spi.h header file are of the same version */
    #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpspi_Ip.c and SchM_Spi.h are different"
    #endif
#endif

/* Check if Lpspi_Ip.h and Lpspi_Ip.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP_VENDOR_ID_C)
    #error "Lpspi_Ip.h and Lpspi_Ip.c have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION_C) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION_C) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip.c are different"
#endif

/* Check if Lpspi_Ip_Cfg.h and Lpspi_Ip.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID_CFG != LPSPI_IP_VENDOR_ID_C)
    #error "Lpspi_Ip_Cfg.h and Lpspi_Ip.c have different vendor ids"
#endif
/* Check if Lpspi_Ip_Cfg.h file and Lpspi_Ip.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != LPSPI_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != LPSPI_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Lpspi_Ip_Cfg.h and Lpspi_Ip.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION_CFG != LPSPI_IP_SW_MAJOR_VERSION_C) || \
     (LPSPI_IP_SW_MINOR_VERSION_CFG != LPSPI_IP_SW_MINOR_VERSION_C) || \
     (LPSPI_IP_SW_PATCH_VERSION_CFG != LPSPI_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Lpspi_Ip_Cfg.h and Lpspi_Ip.c are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (LPSPI_IP_DMA_USED == STD_ON)
    /* the maximum of Major loop when Minor loop Channel Linking Disabled */
    #define LPSPI_IP_DMA_MAX_ITER_CNT_U16 ((uint16)0x7FFFu)
#endif

/**
* @brief SR mask
*/
#define LPSPI_IP_SR_W1C_MASK_U32    (uint32)((uint32)LPSPI_SR_WCF_MASK | (uint32)LPSPI_SR_FCF_MASK | (uint32)LPSPI_SR_TCF_MASK | \
                                             (uint32)LPSPI_SR_TEF_MASK | (uint32)LPSPI_SR_REF_MASK | (uint32)LPSPI_SR_DMF_MASK)
#ifdef ERR_IPV_LPSPIV2_E050456
#ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION
    #define LPSPI_IP_ERR_TIMEOUT_COUNTER (uint32)0xFFFFu
    #define LPSPI_IP_SR_RESET_VALUE_U32 (uint32)0x00000001u
#endif
#endif
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

static LPSPI_Type* const Lpspi_Ip_apxBases[LPSPI_INSTANCE_COUNT] = IP_LPSPI_BASE_PTRS;

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

static Lpspi_Ip_StateStructureType Lpspi_Ip_axStateStructure[LPSPI_IP_NUMBER_OF_INSTANCES];
static Lpspi_Ip_StateStructureType* Lpspi_Ip_apxStateStructureArray[LPSPI_INSTANCE_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#if (LPSPI_IP_DMA_USED == STD_ON)
#define SPI_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Spi_MemMap.h"
static uint32 Lpspi_Ip_u32DiscardData;
#define SPI_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Spi_MemMap.h"
#endif

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

LOCAL_INLINE void Lpspi_Ip_ReadDataFromFifo(uint8 Instance,
                                            uint8 NumberOfReads);

LOCAL_INLINE void Lpspi_Ip_PushDataToFifo(uint8 Instance,
                                          uint8 NumberOfWrites);

LOCAL_INLINE void Lpspi_Ip_TransmitProcess(uint8 Instance);

LOCAL_INLINE void Lpspi_Ip_ClearCS(uint8 Instance);

static void Lpspi_Ip_TransferFinished(uint8 Instance,
                                     boolean ErrorFlag);

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
static void Lpspi_Ip_TransferProcessHalfDuplex(uint8 Instance);

static boolean Lpspi_Ip_HalfDupleTransmitChannelComplete(uint8 Instance);

LOCAL_INLINE boolean Lpspi_Ip_HalfDuplexTransmitProcess(uint8 Instance,
                                                        uint8 NumberOfWrites);

LOCAL_INLINE boolean Lpspi_Ip_GetTxFifoTransferStatus(uint8 Instance);

LOCAL_INLINE void Lpspi_Ip_HalfDuplexPushCmdToFifo(uint8 Instance);

LOCAL_INLINE void Lpspi_Ip_HalfDuplexPushDataToFifo(uint8 Instance,
                                                    uint8 NumberOfWrites);

#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
LOCAL_INLINE boolean Lpspi_Ip_HalfDuplexDisableTxInterrupt(uint8 Instance);
#endif

static void Lpspi_Ip_HalfDuplexPrepare(uint8 Instance,
                                       uint8* Buffer);
#endif /* if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) */

static void Lpspi_Ip_TransferProcess(uint8 Instance);

static void Lpspi_TransmitTxInit(uint8 Instance,
                                 const uint8* TxBuffer,
                                 uint16 NumberOfFrames);

static void Lpspi_TransmitRxInit(uint8 Instance,
                                 uint8* RxBuffer,
                                 uint16 NumberOfFrames);

#if (LPSPI_IP_DMA_USED == STD_ON)
static void Lpspi_Ip_DmaInit(uint8 Instance);

static void Lpspi_Ip_TxDmaConfig(uint8 Instance);

static void Lpspi_Ip_RxDmaConfig(uint8 Instance);

static void Lpspi_Ip_TxDmaContinueTransfer(uint8 Instance);

static void Lpspi_Ip_RxDmaContinueTransfer(uint8 Instance);

#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
static void Lpspi_Ip_DmaFastConfig(uint8 Instance,
                                   const Lpspi_Ip_FastTransferType *FastTransferCfg,
                                   uint8 NumberOfTransfer);

static void Lpspi_Ip_RxDmaTcdSGConfig(uint8 Instance,
                                      uint8 TcdSgIndex,
                                      uint8 DisHwReq);

static void Lpspi_Ip_RxDmaTcdSGInit(uint8 Instance);

static void Lpspi_Ip_TxDmaTcdSGConfig(uint8 Instance,
                                      uint8 TcdSgIndex,
                                      uint8 DisHwReq,
                                      const uint32 *DefaultDataAddress);

static void Lpspi_Ip_TxDmaTcdSGInit(uint8 Instance);

static void Lpspi_Ip_CmdTxDmaTcdSGConfig(uint8 Instance,
                                         uint8 TcdSgIndex,
                                         uint32 CmdAdd,
                                         uint8 DisHwReq);

#endif /* if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) */
#if ((LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) || (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON))
static void Lpspi_TransmitTxDmaContMemReconfig(uint8 Instance,
                                               const uint8* TxBuffer,
                                               uint16 NumberOfFrames);

#endif
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
#if (LPSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
void Lpspi_Ip_SetUserAccess(uint8 Instance);

static void Lpspi_Ip_SetUserAccessAllowed(uint8 Instance);

#endif /* LPSPI_IP_ENABLE_USER_MODE_SUPPORT */
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
static void Lpspi_Ip_CheckValidParameters(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                          uint16 Length);

#endif

#ifdef ERR_IPV_LPSPIV2_E050456
static void Lpspi_ErrataHandle(LPSPI_Type* Base,
                               Lpspi_Ip_StateStructureType* State);

#else
static void Lpspi_HardResetFifo(LPSPI_Type* Base);

#endif
static void Lpspi_ResetFifo(LPSPI_Type* Base,
                            const Lpspi_Ip_StateStructureType* State,
                            uint32 StatusRegister);

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function will read Data from RX FIFO.
* @details This function will read Data from RX FIFO.
*
* @param[in]     Instance      Index of the hardware instance.
* @param[in]     NumberOfReads      Number of Data can be read from RX FIFO.
*/
LOCAL_INLINE void Lpspi_Ip_ReadDataFromFifo(uint8 Instance,
                                            uint8 NumberOfReads)
{
    const LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 Data = 0u;
    uint8 Index = 0u;

    /* To increase the performance of transfer, we will reduce the checking conditions in per "for" statement so we should have more than 1 "for"
     * statement here */
    if (NULL_PTR != State->RxBuffer)
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            for (Index = 0; Index < NumberOfReads; Index++)
            {
                Data = Base->RDR;
                *((uint8*)(&State->RxBuffer[State->RxIndex + Index])) = (uint8)Data;
            }
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            for (Index = 0; Index < NumberOfReads; Index++)
            {
                Data = Base->RDR;
                *((uint16*)(&State->RxBuffer[2u * (State->RxIndex + Index)])) = (uint16)(Data);
            }
        }
        else
        {
            for (Index = 0; Index < NumberOfReads; Index++)
            {
                Data = Base->RDR;
                *((uint32*)(&State->RxBuffer[4u * (State->RxIndex + Index)])) = (uint32)Data;
            }
        }
    }
    else
    {
        for (Index = 0; Index < NumberOfReads; Index++)
        {
            /* Read RDR register to discard data */
            (void)Base->RDR;
        }
    }

    State->RxIndex += NumberOfReads;
}

/**
* @brief   This function will push Data into TX FIFO.
* @details This function will push Data into TX FIFO.
*
* @param[in]     Instance            Index of the hardware instance.
* @param[in]     NumberOfWrites      Number of Data can be pushed to TX FIFO.
*/
LOCAL_INLINE void Lpspi_Ip_PushDataToFifo(uint8 Instance,
                                          uint8 NumberOfWrites)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 Data = 0u;
    uint8 Index = 0u;

    /* Default data will be sent if TX buffer is null */
    Data = State->ExternalDevice->DeviceParams->DefaultData;
    /* To increase the performance of transfer, we will reduce the checking conditions in per "for" statement so we should have more than 1 "for"
     * statement here */
    if (NULL_PTR != State->TxBuffer)
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            for (Index = 0; Index < NumberOfWrites; Index++)
            {
                Data = *((const uint8*)(&State->TxBuffer[State->TxIndex + Index]));
                Base->TDR = Data;
            }
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            for (Index = 0; Index < NumberOfWrites; Index++)
            {
                Data = *((const uint16*)(&State->TxBuffer[2u * (State->TxIndex + Index)]));
                Base->TDR = Data;
            }
        }
        else
        {
            for (Index = 0; Index < NumberOfWrites; Index++)
            {
                Data = *((const uint32*)(&State->TxBuffer[4u * (State->TxIndex + Index)]));
                Base->TDR = Data;
            }
        }
    }
    else
    {
        for (Index = 0; Index < NumberOfWrites; Index++)
        {
            Base->TDR = Data;
        }
    }

    State->TxIndex += NumberOfWrites;
}

/**
* @brief   This function will process to transmit data.
* @details This function will process to transmit data.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE void Lpspi_Ip_TransmitProcess(uint8 Instance)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint8 NumberOfWrites = 0u;

    NumberOfWrites = State->CurrentTxFifoSlot;
    /* Limits to remaining frames. */
    if (NumberOfWrites > (State->ExpectedFifoWrites - State->TxIndex))
    {
        NumberOfWrites = (uint8)(State->ExpectedFifoWrites - State->TxIndex);
    }

    /* Push Data into TX FIFO */
    Lpspi_Ip_PushDataToFifo(Instance, NumberOfWrites);
    State->CurrentTxFifoSlot -= NumberOfWrites;
}

/**
* @brief   This function will clear CS.
* @details This function will clear CS.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE void Lpspi_Ip_ClearCS(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];

    if ((FALSE == State->KeepCs) && (0u != (Base->TCR & LPSPI_TCR_CONT_MASK)))
    {
        /* Clear CS */
        Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
    }
}

/**
* @brief   This function will finish transfer of a channel.
* @details This function will finish transfer of a channel.
*
* @param[in]     Instance            Index of the hardware instance.
* @param[in]     ErrorFlag           Save the status of transfer error flags
*/
static void Lpspi_Ip_TransferFinished(uint8 Instance,
                                     boolean ErrorFlag)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Lpspi_Ip_EventType EventState = LPSPI_IP_EVENT_FAULT;

    if (TRUE == ErrorFlag)
    {
        State->Status = LPSPI_IP_FAULT;
        EventState = LPSPI_IP_EVENT_FAULT;
    }
    else
    {
        State->Status = LPSPI_IP_IDLE;
        EventState = LPSPI_IP_EVENT_END_TRANSFER;
    }

    if (NULL_PTR != State->Callback)
    {
        State->Callback(Instance, EventState);
    }
    else
    {
        (void)EventState;
    }
}

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
/**
* @brief   This function is called by Lpspi_Ip_IrqHandler or Lpspi_Ip_ManageBuffers. It will process transfer in interrupt mode or polling mode.
* @details This function will fill Data into TX FIFO and read Data in RX FIFO fill to Rx Buffers.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static void Lpspi_Ip_TransferProcessHalfDuplex(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister;
    uint8 NumberOfWrites = 0u;
    uint8 NumberOfReads = 0u;
    boolean ErrorFlag = FALSE;
    Lpspi_Ip_HalfDuplexType TransferType;
    boolean TransferCompleted = FALSE;
    uint8 NumberOfFramesTxFifo;

    if (LPSPI_IP_BUSY == State->Status)
    {
        /* Read Status and clear all flags. */
        SrStatusRegister = Base->SR;
        Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;
        TransferType = State->ExternalDevice->DeviceParams->TransferType;

        if ((SrStatusRegister & (LPSPI_SR_REF_MASK | LPSPI_SR_TEF_MASK)) != 0u)
        {
            /* mark error flag */
            ErrorFlag = TRUE;

            /* Reset FIFO after errors */
            Lpspi_ResetFifo(Base, State, SrStatusRegister);
        }
        else
        {
            /* TX of latest channel in job have done */
            /* Check TX FIFO is available to fill CMD */
            if ((State->ExpectedFifoWrites == State->TxIndex) && (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType))
            {
                ErrorFlag = Lpspi_Ip_HalfDupleTransmitChannelComplete(Instance);
                /* In Transmit only mode, masks the transfer has finish */
                TransferCompleted = TRUE;
            }

            if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
            {
                /* RECEIVE DATA */
                /* Read all Data available in receive HW fifo. */
                NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
                if (NumberOfReads > LPSPI_IP_FIFO_SIZE_U8)
                {
                    NumberOfReads = LPSPI_IP_FIFO_SIZE_U8;
                }
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }

                if (0u != NumberOfReads)
                {
                    Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                }

                /* In slave mode, do not need push CMD */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
                if (FALSE == State->PhyUnitConfig->SlaveMode)
#endif
                {
                    /* PUSH CMD */
                    /* Only write to TCR when TX FIFO is empty in receive mode */
                    Lpspi_Ip_HalfDuplexPushCmdToFifo(Instance);
                }
            }
            else
            {
                /* TRANSMIT */
                /* Push Data until HW fifo is full or transfer is done. */
                NumberOfFramesTxFifo = (uint8)(((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) >> LPSPI_FSR_TXCOUNT_SHIFT);
                if (NumberOfFramesTxFifo > LPSPI_IP_FIFO_SIZE_U8)
                {
                    NumberOfFramesTxFifo = LPSPI_IP_FIFO_SIZE_U8;
                }
                NumberOfWrites = LPSPI_IP_FIFO_SIZE_U8 - NumberOfFramesTxFifo;
                if ((0u != NumberOfWrites) && (State->ExpectedFifoWrites != State->TxIndex))
                {
                    Lpspi_Ip_HalfDuplexPushDataToFifo(Instance, NumberOfWrites);
                    /* In Slave transmit mode, disable TX interrupt after all frames have pushed into TX FIFO */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
                    TransferCompleted = Lpspi_Ip_HalfDuplexDisableTxInterrupt(Instance);
#endif
                }
            }
        }

        /* End of transfer */
        if (((LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType) && (TRUE == TransferCompleted)) ||
            ((State->RxIndex == State->ExpectedFifoReads) && (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)) ||
            (TRUE == ErrorFlag))
        {
            /* Disable interrupts */
            Base->IER = 0u;
            Lpspi_Ip_TransferFinished(Instance, ErrorFlag);
        }
    }
}

/**
* @brief   This function to complete TX channel in HD mode.
* @details This function to complete TX channel in HD mode.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static boolean Lpspi_Ip_HalfDupleTransmitChannelComplete(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 TimeoutTicks = OsIf_MicrosToTicks(LPSPI_IP_HALF_DUPLEX_TIMEOUT_COUNTER, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    boolean TimeOutError = FALSE;

    /* TX of latest channel in job have done */
    if (FALSE == State->KeepCs)
    {
        /* No need clear for slave mode */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        if (FALSE == State->PhyUnitConfig->SlaveMode)
#endif
        {
            /* Clear CS */
            Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
        }
    }

    /* If next channel is TX, there is no need to wait for TX FIFO to drain */
    if ((TRUE == State->NextChannelIsRX) || (FALSE == State->KeepCs))
    {
        /* Wait for TX FIFO to drain after transfer is completed */
        while ((((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
        {
            CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
        }

        if (ElapsedTicks >= TimeoutTicks)
        {
            /* mark error flag */
            TimeOutError = TRUE;
            /* Clear TX FIFO */
            Base->CR |= LPSPI_CR_RTF_MASK;
        }
    }
    else
    {
        (void)TimeoutTicks;
    }

    return TimeOutError;
}

/**
* @brief   This function will process to transmit data.
* @details This function will process to transmit data.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE boolean Lpspi_Ip_HalfDuplexTransmitProcess(uint8 Instance,
                                                        uint8 NumberOfWrites)
{
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    boolean TransferCompleted = FALSE;

    if (State->ExpectedFifoWrites != State->TxIndex)
    {
        Lpspi_Ip_HalfDuplexPushDataToFifo(Instance, NumberOfWrites);
    }
    else
    {
        /* At least 1 TX FIFO slot must be available at here to make sure that driver can push one more CMD to TX FIFO to clear CONT at the end of
         * latest channel in a job */
        if ((FALSE == State->KeepCs))
        {
            /* Clear CS if there is request to clear CONT bit, make sure that is having at least 1 entry TX FIFO is available to fill CMD by check TDF
             * flag */
            if (0u != (Base->TCR & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
                /* Set transfer flag is done to break from while loop to finish transfer */
            }
        }

        /* Transfer is finished */
        TransferCompleted = TRUE;
    }

    return TransferCompleted;
}

/**
* @brief   Get Tx FIFO transfer status.
* @details Get Tx FIFO transfer status.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE boolean Lpspi_Ip_GetTxFifoTransferStatus(uint8 Instance)
{
    const LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    boolean TransferCompleted = FALSE;

    /* Wait for TX FIFO to drain after transfer is completed */
    if (((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) == 0u)
    {
        TransferCompleted = TRUE;
    }

    return TransferCompleted;
}

/**
* @brief   This function will start transfer in half duplex receive mode.
* @details This function will start transfer in half duplex receive mode.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE void Lpspi_Ip_HalfDuplexPushCmdToFifo(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];

    if ((0u == ((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK)) && (State->ExpectedFifoWrites != State->TxIndex))
    {
        /* Push one CMD to start transfer. */
        Base->TCR = State->HalfDuplexTcrCommand;
        State->TxIndex++;
    }
}

/**
* @brief   This function will perform Transmit data in half duplex mode.
* @details This function will perform Transmit data in half duplex mode.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE void Lpspi_Ip_HalfDuplexPushDataToFifo(uint8 Instance,
                                                    uint8 NumberOfWrites)
{
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint8 WriteToFifoTime = NumberOfWrites;

    /* Limits to remaining frames. */
    if (NumberOfWrites > (State->ExpectedFifoWrites - State->TxIndex))
    {
        WriteToFifoTime = (uint8)(State->ExpectedFifoWrites - State->TxIndex);
    }

    /* Push Data into TX FIFO */
    Lpspi_Ip_PushDataToFifo(Instance, WriteToFifoTime);
}

#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
/**
* @brief   This function will disable Tx interrupt in half duplex transmit mode.
* @details This function will disable Tx interrupt in half duplex transmit mode.
*
* @param[in]     Instance      Index of the hardware instance.
*/
LOCAL_INLINE boolean Lpspi_Ip_HalfDuplexDisableTxInterrupt(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    boolean TransferCompleted = FALSE;

    if ((TRUE == State->PhyUnitConfig->SlaveMode) && (State->ExpectedFifoWrites == State->TxIndex))
    {
        /* Disable TX interrupt */
        Base->IER &= ~LPSPI_IER_TDIE_MASK;
        /* Masks the transfer has finish */
        TransferCompleted = TRUE;
    }

    return TransferCompleted;
}
#endif

/**
* @brief   This function will prepare to transfer in half duplex mode.
* @details This function will prepare to transfer in half duplex mode.
*
* @param[in]     Instance           Index of the hardware instance.
* @param[in]     Buffer             Transfer buffer.
*/
static void Lpspi_Ip_HalfDuplexPrepare(uint8 Instance,
                                       uint8* Buffer)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    uint32 LsbWriteValue = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
    uint32 ByteSwapWriteValue = State->ExternalDevice->DeviceParams->ByteSwap ? 1UL : 0UL;

    /* In half duplex mode, CFGR1 register should be updated to configure PCSCFG, OUTCFG, PINCFG fields. This bit fields should be reset before write
     * new value */
    Base->CFGR1 &= ~(LPSPI_CFGR1_PCSCFG_MASK | LPSPI_CFGR1_OUTCFG_MASK | LPSPI_CFGR1_PINCFG_MASK);
    Base->CFGR1 |= State->ExternalDevice->HalfDuplexCfgr1;
    /* This variable will be used only in polling mode, It do not determine the number of frames in TX FIFO in half mode. it only makes sure that in
     * Slave receive mode, TDF is set but it will not be used to execute process function */
    /* Set this variable to different 0 if is not in Slave Receive mode */
    State->CurrentTxFifoSlot = 1u;
    if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType)
    {
        State->TxBuffer = (const uint8*)Buffer;
    }
    else
    {
        State->RxBuffer = Buffer;

        /* Update TCR value to using in ISR function */
#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
        State->HalfDuplexTcrCommand = State->ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(LsbWriteValue) | LPSPI_TCR_BYSW(ByteSwapWriteValue);
#else
        State->HalfDuplexTcrCommand = State->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(LsbWriteValue) | LPSPI_TCR_BYSW(ByteSwapWriteValue);
#endif
        /* In Slave mode, CONT bit should be cleared */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            State->HalfDuplexTcrCommand &= ~LPSPI_TCR_CONT_MASK;
            /* This variable will be used only in polling mode, It do not determine the number of frames in TX FIFO in half mode. it only makes sure
             * that in Slave receive mode, TDF is set but it will not be used to execute process function */
            /* Set this variable to 0 in Slave Receive mode */
            State->CurrentTxFifoSlot = 0u;
        }

#endif
        /* Because of not supporting CS continous mode so nothing need to be done with CONT bit */
        /* Mark TX FIFO */
        State->HalfDuplexTcrCommand |= LPSPI_TCR_TXMSK_MASK;
    }
}

#endif /* if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) */
/**
* @brief   This function is called by Lpspi_Ip_IrqHandler or Lpspi_Ip_ManageBuffers. It will process transfer in interrupt mode or polling mode.
* @details This function will fill Data into TX FIFO and read Data in RX FIFO fill to Rx Buffers.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static void Lpspi_Ip_TransferProcess(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister;
    uint8 NumberOfReads = 0u;
    boolean ErrorFlag = FALSE;

    if (LPSPI_IP_BUSY == State->Status)
    {
        /* Read Status and clear all flags. */
        SrStatusRegister = Base->SR;
        Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;

        if ((SrStatusRegister & (LPSPI_SR_REF_MASK | LPSPI_SR_TEF_MASK)) != 0u)
        {
            /* mark error flag */
            ErrorFlag = TRUE;

            /* Reset FIFO after errors */
            Lpspi_ResetFifo(Base, State, SrStatusRegister);
        }
        else
        {
            /* RECEIVE */
            /* Read all Data available in receive HW fifo. */
            NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
            if (NumberOfReads != 0u)
            {
                if (NumberOfReads > LPSPI_IP_FIFO_SIZE_U8)
                {
                    NumberOfReads = LPSPI_IP_FIFO_SIZE_U8;
                }
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }

                /* If these are the first frames of this channel. Current TXFIFO slot must be plus 1 because the slot of CMD have moved out and
                  CurrentTxFifoSlot was minus 1 when prepare TX channel */
                if (0u == State->RxIndex)
                {
                    State->CurrentTxFifoSlot += 1u;
                }

                /* Read Data from RX FIFO */
                Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                /* Update current FIFO slots are available to fill .*/
                State->CurrentTxFifoSlot += NumberOfReads;
            }

            /*TRANSMIT*/
            /* Push Data until HW fifo is full or transfer is done. */
            /* After driver code read all frames in RX FIFO, if there are still some frames in TX FIFO, at the time before driver code check number of frames available in TX FIFO to prepare
            to fill TX FIFO. At that time, another interrupt occurred and preemptive current interrupt, and the time to process that interrupt is longer than the time to transfer all frames
            in TX FIFO. So TX FIFO will be empty and some frames received in RX FIFO, then the program is returned from that interrupt and fill TX FIFO until full and exist SPI interrupt function.
            And if there is a interrupt occurred with higher priority of SPI interrupt and the time to process that interrupt is longer than the time to transfer all frames in TX FIFO.
            So, RX FIFO can be overflow due to SPI interrupt function is not serviced to read RX FIFO.
            State->CurrentTxFifoSlot variable is used to hanlde number of frames are "on bus transfer". They are always less than FIFO size */
            if (State->CurrentTxFifoSlot != 0u)
            {
                if (State->ExpectedFifoWrites != State->TxIndex)
                {
                    Lpspi_Ip_TransmitProcess(Instance);
                }
                else
                {
                    /* Disable TX interrupt */
                    Base->IER &= ~LPSPI_IER_TDIE_MASK;
                    Lpspi_Ip_ClearCS(Instance);
                }
            }
        }

        /* End of transfer */
        if ((State->RxIndex == State->ExpectedFifoReads) || (TRUE == ErrorFlag))
        {
            if ((FALSE == State->KeepCs) || (TRUE == ErrorFlag))
            {
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_12();
                /* Disable module to stop transfer */
                Base->CR &= ~LPSPI_CR_MEN_MASK;
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_12();
            }

            /* Disable interrupts */
            Base->IER = 0u;
            Lpspi_Ip_TransferFinished(Instance, ErrorFlag);
        }
    }
}

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function will verify the validation of some input parameters of transmision functions.
* @details This function will verify the validation of some input parameters of transmision functions.
*
* @param[in]     ExternalDevice   Pointer to the external device where data is transmitted.
* @param[in]     Length         Number of bytes to be sent.
*/
static void Lpspi_Ip_CheckValidParameters(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                          uint16 Length)
{
    if (ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        DevAssert((Length % 4) == 0u);
    }
    else if (ExternalDevice->DeviceParams->FrameSize > 8u)
    {
        DevAssert((Length % 2) == 0u);
    }
    else
    {
        /* do nothing */
    }

    if (ExternalDevice->DeviceParams->ByteSwap)
    {
        DevAssert(ExternalDevice->DeviceParams->FrameSize == 32u);
    }
}

#endif /* if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON) */

#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
static void Lpspi_Ip_TxDmaTcdSGInit(uint8 Instance)
{
    const Lpspi_Ip_StateStructureType* State = (const Lpspi_Ip_StateStructureType*)Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];
    uint8 TcdSgIndex = 0u;

    /* initialze configuration software TCD Scatter Gather for Tx DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;

    DmaTcdList[1u].Value = 0u;    /* dummy dest address write, will be updated latter according to ScatterGather to update TCR or TDR */
    DmaTcdList[2u].Value = 1u;  /* dummy src offset is 1 byte, will be updated latter according to frame size and transfer default Data */
    DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* dummy 1 byte src transfer size, will be updated latter according to frame size */
    DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* dummy 1 byte dest transfer size, will be updated latter according to frame size */
    DmaTcdList[5u].Value = 1u;   /* dummy bytes to transfer for each request, will be updated latter according to frame size */
    DmaTcdList[6u].Value = 0u; /* no dest offset */
    DmaTcdList[7u].Value = 0u; /* dummy iteration count, will be updated latter according to number of frames */
    DmaTcdList[8u].Value = 1u; /* dummy disable hardware request when major loop complete, will be updated latter according to last transfer or not */
    DmaTcdList[0u].Value = 0u; /* dummy src address read, will be updated latter Base on TxBuffer */

    for (TcdSgIndex = 0u; TcdSgIndex < State->PhyUnitConfig->MaxNumOfFastTransfer; TcdSgIndex++)
    {
        /* Update software TX DMA TCD Scatter Gather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TcdSgIndex], DmaTcdList, 9u);
    }
}

static void Lpspi_Ip_CmdTxDmaTcdSGConfig(uint8 Instance,
                                         uint8 TcdSgIndex,
                                         uint32 CmdAdd,
                                         uint8 DisHwReq)
{
    const LPSPI_Type* Base = (const LPSPI_Type *)Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = (const Lpspi_Ip_StateStructureType *)Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];

    /* configure TX DMA TCD Scatter Gather to update transfer command TCR */
    /* No need to configure dest offset due to it are already set by Lpspi_Ip_TxDmaTcdSGInit */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    DmaTcdList[0u].Value = CmdAdd; /* src address read */
    DmaTcdList[1u].Value = (uint32) & Base->TCR;    /* dest address write*/
    DmaTcdList[2u].Value = 0u;  /* src offset is 0 byte */
    DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
    DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
    DmaTcdList[5u].Value = 4u;   /* bytes to transfer for each request */
    DmaTcdList[6u].Value = 1u; /* iteration count */
    DmaTcdList[7u].Value = DisHwReq; /* disable hardware request when major loop complete */
    DmaTcdList[8u].Value = DisHwReq; /* Enable Major interrupt at the end of transfer sequence(meanning when DisHwReq = 1u) */

    /* Update software TX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TcdSgIndex], DmaTcdList, 9u);
}

static void Lpspi_Ip_TxDmaTcdSGConfig(uint8 Instance,
                                      uint8 TcdSgIndex,
                                      uint8 DisHwReq,
                                      const uint32 *DefaultDataAddress)
{
    const LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];

    /* Update buffers index */
    State->TxIndex = State->ExpectedFifoWrites;

    /* configure TX DMA TCD Scatter Gather to fill tx Data to TDR */
    /* No need to configure dest offset due to it are already set by Lpspi_Ip_TxDmaTcdSGInit */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    DmaTcdList[1u].Value = (uint32) & Base->TDR;    /* dest address write*/
    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[2u].Value = 1u;  /* src offset is 1 byte */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[5u].Value = 1u;   /* bytes to transfer for each request */
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        DmaTcdList[2u].Value = 2u;  /* src offset is 2 bytes */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[5u].Value = 2u;   /* bytes to transfer for each request */
    }
    else
    {
        DmaTcdList[2u].Value = 4u;  /* src offset is 4 bytes */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[5u].Value = 4u;   /* bytes to transfer for each request */
    }

    DmaTcdList[6u].Value = State->ExpectedFifoWrites; /* iteration count */
    DmaTcdList[7u].Value = DisHwReq; /* disable hardware request when major loop complete */
    DmaTcdList[8u].Value = DisHwReq; /* Enable Major interrupt at the end of transfer sequence(meanning when DisHwReq = 1u) */
    if (NULL_PTR == State->TxBuffer)
    {
        /* send default Data */
        DmaTcdList[0u].Value = (uint32)DefaultDataAddress; /* src address read */
        DmaTcdList[2u].Value = 0u;  /* src offset is 0 byte */
    }
    else
    {
        DmaTcdList[0u].Value = (uint32)State->TxBuffer; /* src address read */
        /* cast to avoid CW */
        (void)DefaultDataAddress;
    }

    /* Update software TX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TcdSgIndex], DmaTcdList, 9u);
}

static void Lpspi_Ip_RxDmaTcdSGInit(uint8 Instance)
{
    const LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];
    uint8 TcdSgIndex = 0u;

    /* initialze configuration software TCD Scatter Gather for Rx DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;

    DmaTcdList[0u].Value = (uint32) & Base->RDR; /* src address read */
    DmaTcdList[2u].Value = 0u;  /* no src offset */
    DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* dummy 1 byte src transfer size, will be updated latter Base on frame size */
    DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* dummy 1 byte dest transfer size, will be updated latter Base on frame size */
    DmaTcdList[5u].Value = 1u;   /* dummy 1 byte to transfer for each request, will be updated latter Base on frame size */
    DmaTcdList[6u].Value = 1u; /* dummy dest offset is 1 byte, will be updated latter Base on frame size and discard info */
    DmaTcdList[1u].Value = 0u;    /* dummy dest address write, will be updated latter Base on RxBuffer */
    DmaTcdList[7u].Value = 0u; /* dummy iteration count, will be updated latter Base on number of frames */
    DmaTcdList[8u].Value = 1u; /* dummy disable hardware request when major loop complete, will be updated latter according to last transfer or not */

    for (TcdSgIndex = 0u; TcdSgIndex < State->PhyUnitConfig->MaxNumOfFastTransfer; TcdSgIndex++)
    {
        /* Update software RX DMA TCD Scatter Gather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[TcdSgIndex], DmaTcdList, 9u);
    }
}

static void Lpspi_Ip_RxDmaTcdSGConfig(uint8 Instance,
                                      uint8 TcdSgIndex,
                                      uint8 DisHwReq)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[8u];

    /* Update buffers index */
    State->RxIndex = State->ExpectedFifoReads;

    /* configure RX DMA TCD Scatter Gather */
    /* No need to configure src address and src offset due to they are already set by Lpspi_Ip_RxDmaTcdSGInit */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[1u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[3u].Value = 1u;   /* 1 byte to transfer for each request */
        DmaTcdList[4u].Value = 1u; /* dest offset is 1 bytes */
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        DmaTcdList[1u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[3u].Value = 2u;   /* 2 bytes to transfer for each request */
        DmaTcdList[4u].Value = 2u; /* dest offset is 2 bytes */
    }
    else
    {
        DmaTcdList[1u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[3u].Value = 4u;   /* 4 bytes to transfer for each request */
        DmaTcdList[4u].Value = 4u; /* dest offset is 4 bytes */
    }

    if (NULL_PTR == State->RxBuffer)
    {
        /* Discard Data */
        DmaTcdList[0u].Value = (uint32) & Lpspi_Ip_u32DiscardData;    /* dest address write*/
        DmaTcdList[4u].Value = 0u; /* dest offset is 0 bytes */
    }
    else
    {
        DmaTcdList[0u].Value = (uint32)State->RxBuffer;    /* dest address write*/
    }

    DmaTcdList[5u].Value = State->ExpectedFifoReads; /* iteration count */
    DmaTcdList[6u].Value = DisHwReq; /* disable hardware request when major loop complete */
    DmaTcdList[7u].Value = DisHwReq; /* Enable Major interrupt at the end of transfer sequence(meanning when DisHwReq = 1u) */

    /* Update software RX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[TcdSgIndex], DmaTcdList, 8u);
}

#endif /* (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) */

/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA with the default value.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static void Lpspi_Ip_DmaInit(uint8 Instance)
{
    const LPSPI_Type* Base = (const LPSPI_Type*)Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[10u];
    uint8 FrameSize = State->PhyUnitConfig->TcdConfigOptimizeFrameSize;

    /* configure TX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;

    DmaTcdList[0u].Value = (uint32) & Base->TDR;    /* dest address write*/
    DmaTcdList[5u].Value = 0u; /* no dest offset */
    if (TRUE == State->PhyUnitConfig->TcdConfigOptimize)
    {
        if (FrameSize < 9u)
        {
            DmaTcdList[1u].Value = 1u;  /* src offset is 1 byte */
            DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
            DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
            DmaTcdList[4u].Value = 1u;   /* bytes to transfer for each request */
            State->TxSrcSignedOffsetValue = 1u;
        }
        else if (FrameSize < 17u)
        {
            DmaTcdList[1u].Value = 2u;  /* src offset is 2 bytes */
            DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
            DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
            DmaTcdList[4u].Value = 2u;   /* bytes to transfer for each request */
            State->TxSrcSignedOffsetValue = 2u;
        }
        else
        {
            DmaTcdList[1u].Value = 4u;  /* src offset is 4 bytes */
            DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
            DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
            DmaTcdList[4u].Value = 4u;   /* bytes to transfer for each request */
            State->TxSrcSignedOffsetValue = 4u;
        }
    }
    else
    {
        /* Framesize 8 bits as the default value, it will be update in runtime if needed */
        DmaTcdList[1u].Value = 1u;  /* src offset is 1 byte */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[4u].Value = 1u;   /* bytes to transfer for each request */
        State->PreTxTransferSize = LPSPI_IP_TRANSFER_SIZE_1_BYTE;
        State->TxSrcSignedOffsetValue = 1u;
    }

    DmaTcdList[6u].Value = 1u; /* disable hardware request when major loop complete */
    /* Set DESTINATION_SIGNED_LAST_ADDR_ADJ = 0 to avoid the case it still stored from previous TCD Scatter Gather */
    DmaTcdList[7u].Value = 0u;    /* No adjust DADD when major loop completed */
    /* write TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 8u);

    /* configure RX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;

    DmaTcdList[0u].Value = (uint32) & Base->RDR; /* src address read */
    DmaTcdList[1u].Value = 0u;  /* no src offset */
    if (TRUE == State->PhyUnitConfig->TcdConfigOptimize)
    {
        if (FrameSize < 9u)
        {
            DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
            DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
            DmaTcdList[4u].Value = 1u;   /* 1 byte to transfer for each request */
            DmaTcdList[5u].Value = 1u; /* dest offset is 1 bytes */
            State->RxDesSignedOffsetValue = 1u;
        }
        else if (FrameSize < 17u)
        {
            DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
            DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
            DmaTcdList[4u].Value = 2u;   /* 2 bytes to transfer for each request */
            DmaTcdList[5u].Value = 2u; /* dest offset is 2 bytes */
            State->RxDesSignedOffsetValue = 2u;
        }
        else
        {
            DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
            DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
            DmaTcdList[4u].Value = 4u;   /* 4 bytes to transfer for each request */
            DmaTcdList[5u].Value = 4u; /* dest offset is 4 bytes */
            State->RxDesSignedOffsetValue = 4u;
        }
    }
    else
    {
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[4u].Value = 1u;   /* 1 byte to transfer for each request */
        DmaTcdList[5u].Value = 1u; /* dest offset is 1 bytes */
        State->PreRxTransferSize = LPSPI_IP_TRANSFER_SIZE_1_BYTE;
        State->RxDesSignedOffsetValue = 1u;
    }

    DmaTcdList[6u].Value = 1u; /* disable hardware request when major loop complete */
    /* Set DESTINATION_SIGNED_LAST_ADDR_ADJ = 0 to avoid the case it still stored from previous TCD Scatter Gather */
    DmaTcdList[7u].Value = 0u;    /* No adjust DADD when major loop completed */
    /* write TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 8u);

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    State->IsPreChanneHalfDuplexlRxMode = FALSE;
#endif
    /* Init default value for some channel TCD status. These variables will be update in time of configuring TX/RX DMA for each channel to save
     * current attributes of that channel */
    State->IsPreTxBufferNull = FALSE;
    State->IsPreRxBufferNull = FALSE;
    State->PreTxMajorLoopCount = 0u;
    State->PreRxMajorLoopCount = 0u;
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    /* reset dam mode used flag */
    State->IsPreTransferInDmaFastMode = FALSE;
#endif
}

/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA
*          according to current transfer configuration. DMA channels will be started at the end of the function.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static void Lpspi_Ip_TxDmaConfig(uint8 Instance)
{
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    const LPSPI_Type* Base = (const LPSPI_Type*)Lpspi_Ip_apxBases[Instance];
#endif
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[17u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites;
    uint8 DmaTcdListIndexCounter = 0u;
    boolean SrcSignedOffsetIsSet = FALSE;

    /* Limits number of major count */
    if (LPSPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = LPSPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    /* Update buffers index */
    State->TxIndex = NumberDmaIterWrite;

    if (NumberDmaIterWrite != State->PreTxMajorLoopCount)
    {
        DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTcdList[DmaTcdListIndexCounter].Value = NumberDmaIterWrite; /* iteration count */
        DmaTcdListIndexCounter++;
        /* At next channel, if PreTxMajorLoopCount is same current channel, do not need re-configure DMA_IP_CH_SET_MAJORLOOP_COUNT to increase the
         * performance */
        State->PreTxMajorLoopCount = NumberDmaIterWrite;
    }

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    /* In Half duplex receive mode. TX DMA will be used to push CMD to TXFIFO to start transfer */
    if ((LPSPI_IP_HALF_DUPLEX_RECEIVE == State->ExternalDevice->DeviceParams->TransferType) && (FALSE == State->IsPreChanneHalfDuplexlRxMode))
    {
        DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        DmaTcdList[DmaTcdListIndexCounter].Value = (uint32) & State->HalfDuplexTcrCommand; /* src address read */
        DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        DmaTcdList[DmaTcdListIndexCounter + 1u].Value = 0u;  /* src offset is 0 bytes */
        DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        DmaTcdList[DmaTcdListIndexCounter + 3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[DmaTcdListIndexCounter + 4u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
        DmaTcdList[DmaTcdListIndexCounter + 4u].Value = 4u;   /* bytes to transfer for each request */
        DmaTcdList[DmaTcdListIndexCounter + 5u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        DmaTcdList[DmaTcdListIndexCounter + 5u].Value = (uint32) & Base->TCR;    /* dest address write*/

        DmaTcdListIndexCounter += 6u;
        /* Masks this channel is master RX mode (only is in Master RX mode need to call Lpspi_Ip_TxDmaConfig)  */
        State->IsPreChanneHalfDuplexlRxMode = TRUE;
        /* reset PreTxTransferSize flag for next channel */
        State->PreTxTransferSize = LPSPI_IP_TRANSFER_SIZE_UNUNIT;
    }
    else
#endif /* if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) */
    {
        /* FrameSize information of channel has configure in DmaInit function. Do not need to re-configure here to increase the performance */
        /* If previous channel is receive mode, TCD should be updated for framesize if it is < 17 */
        if (
            (FALSE == State->PhyUnitConfig->TcdConfigOptimize)
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
            || (TRUE == State->IsPreChanneHalfDuplexlRxMode)
#endif
           )
        {
            if ((State->ExternalDevice->DeviceParams->FrameSize < 9u) && (LPSPI_IP_TRANSFER_SIZE_1_BYTE != State->PreTxTransferSize))
            {
                DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
                DmaTcdList[DmaTcdListIndexCounter].Value = 1u;   /* bytes to transfer for each request */
                DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
                DmaTcdList[DmaTcdListIndexCounter + 1u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
                DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
                DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
                DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
                DmaTcdList[DmaTcdListIndexCounter + 3u].Value = 1u;  /* src offset is 1 byte */
                DmaTcdListIndexCounter += 4u;
                State->PreTxTransferSize = LPSPI_IP_TRANSFER_SIZE_1_BYTE;
                SrcSignedOffsetIsSet = TRUE;
                State->TxSrcSignedOffsetValue = 1u;
            }

            if (
                (State->ExternalDevice->DeviceParams->FrameSize < 17u) && (State->ExternalDevice->DeviceParams->FrameSize >= 9u) &&
                (LPSPI_IP_TRANSFER_SIZE_2_BYTE != State->PreTxTransferSize)
               )
            {
                DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
                DmaTcdList[DmaTcdListIndexCounter].Value = 2u;   /* bytes to transfer for each request */
                DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
                DmaTcdList[DmaTcdListIndexCounter + 1u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 byte src transfer size */
                DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
                DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 byte dest transfer size */
                DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
                DmaTcdList[DmaTcdListIndexCounter + 3u].Value = 2u;  /* src offset is 2 byte */
                DmaTcdListIndexCounter += 4u;
                State->PreTxTransferSize = LPSPI_IP_TRANSFER_SIZE_2_BYTE;
                SrcSignedOffsetIsSet = TRUE;
                State->TxSrcSignedOffsetValue = 2u;
            }

            if ((State->ExternalDevice->DeviceParams->FrameSize >= 17u) && (LPSPI_IP_TRANSFER_SIZE_4_BYTE != State->PreTxTransferSize))
            {
                DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
                DmaTcdList[DmaTcdListIndexCounter].Value = 4u;   /* bytes to transfer for each request */
                DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
                DmaTcdList[DmaTcdListIndexCounter + 1u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 byte src transfer size */
                DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
                DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 byte dest transfer size */
                DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
                DmaTcdList[DmaTcdListIndexCounter + 3u].Value = 4u;  /* src offset is 4 byte */
                DmaTcdListIndexCounter += 4u;
                State->PreTxTransferSize = LPSPI_IP_TRANSFER_SIZE_4_BYTE;
                SrcSignedOffsetIsSet = TRUE;
                State->TxSrcSignedOffsetValue = 4u;
            }

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
            if (TRUE == State->IsPreChanneHalfDuplexlRxMode)
            {
                DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                DmaTcdList[DmaTcdListIndexCounter].Value = (uint32) & Base->TDR;    /* dest address write*/
                DmaTcdListIndexCounter++;
                /*Reset IsPreChanneHalfDuplexlRxMode flag */
                State->IsPreChanneHalfDuplexlRxMode = FALSE;
            }

#endif
        }

        if ((NULL_PTR == State->TxBuffer) && (FALSE == State->IsPreTxBufferNull))
        {
            /* send default Data */
            DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
            DmaTcdList[DmaTcdListIndexCounter].Value = (uint32) & State->ExternalDevice->DeviceParams->DefaultData; /* src address read */
            DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
            DmaTcdList[DmaTcdListIndexCounter + 1u].Value = 0u;
            DmaTcdListIndexCounter += 2u;
            State->IsPreTxBufferNull = TRUE;
        }

        if (NULL_PTR != State->TxBuffer)
        {
            DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
            DmaTcdList[DmaTcdListIndexCounter].Value = (uint32)State->TxBuffer; /* src address read */
            DmaTcdListIndexCounter++;
            /* If previous channel has RX buffer is NULL and DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET is not updated, It must be updated here */
            if ((TRUE == State->IsPreTxBufferNull) && (FALSE == SrcSignedOffsetIsSet))
            {
                DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
                DmaTcdList[DmaTcdListIndexCounter].Value = State->TxSrcSignedOffsetValue;   /* src offset is TxSrcSignedOffsetValue byte */
                DmaTcdListIndexCounter++;
            }

            State->IsPreTxBufferNull = FALSE;
        }
    }

    /* write TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, DmaTcdListIndexCounter);

    /* Enable TX DMA HW request */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA
*          according to current transfer configuration. DMA channels will be started at the end of the function.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static void Lpspi_Ip_RxDmaConfig(uint8 Instance)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[16u];
    uint16 NumberDmaIterRead = State->ExpectedFifoReads;
    uint8 DmaTcdListIndexCounter = 0u;
    boolean DesSignedOffsetIsSet = FALSE;

    /* Limits number of major count */
    if (LPSPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterRead)
    {
        NumberDmaIterRead = LPSPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    /* Update buffers index */
    State->RxIndex = NumberDmaIterRead;

    if (NumberDmaIterRead != State->PreRxMajorLoopCount)
    {
        DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTcdList[DmaTcdListIndexCounter].Value = NumberDmaIterRead; /* iteration count */
        DmaTcdListIndexCounter++;
        /* At next channel, if PreRxMajorLoopCount is same current channel, do not need re-configure DMA_IP_CH_SET_MAJORLOOP_COUNT to increase the
         * performance */
        State->PreRxMajorLoopCount = NumberDmaIterRead;
    }

    if (FALSE == State->PhyUnitConfig->TcdConfigOptimize)
    {
        if ((State->ExternalDevice->DeviceParams->FrameSize < 9u) && (LPSPI_IP_TRANSFER_SIZE_1_BYTE != State->PreRxTransferSize))
        {
            DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
            DmaTcdList[DmaTcdListIndexCounter].Value = 1u;  /* bytes to transfer for each request */
            DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
            DmaTcdList[DmaTcdListIndexCounter + 1u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
            DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
            DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
            DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
            DmaTcdList[DmaTcdListIndexCounter + 3u].Value = 1u;   /* src offset is 1 byte */
            DmaTcdListIndexCounter += 4u;
            State->PreRxTransferSize = LPSPI_IP_TRANSFER_SIZE_1_BYTE;
            State->RxDesSignedOffsetValue = 1u;
            DesSignedOffsetIsSet = TRUE;
        }

        if (
            (State->ExternalDevice->DeviceParams->FrameSize < 17u) && (State->ExternalDevice->DeviceParams->FrameSize >= 9u) &&
            (LPSPI_IP_TRANSFER_SIZE_2_BYTE != State->PreRxTransferSize)
           )
        {
            DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
            DmaTcdList[DmaTcdListIndexCounter].Value = 2u;  /* bytes to transfer for each request */
            DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
            DmaTcdList[DmaTcdListIndexCounter + 1u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 byte src transfer size */
            DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
            DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 byte dest transfer size */
            DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
            DmaTcdList[DmaTcdListIndexCounter + 3u].Value = 2u;   /* src offset is 2 byte */
            DmaTcdListIndexCounter += 4u;
            State->PreRxTransferSize = LPSPI_IP_TRANSFER_SIZE_2_BYTE;
            State->RxDesSignedOffsetValue = 2u;
            DesSignedOffsetIsSet = TRUE;
        }

        if ((State->ExternalDevice->DeviceParams->FrameSize >= 17u) && (LPSPI_IP_TRANSFER_SIZE_4_BYTE != State->PreRxTransferSize))
        {
            DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
            DmaTcdList[DmaTcdListIndexCounter].Value = 4u;  /* bytes to transfer for each request */
            DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
            DmaTcdList[DmaTcdListIndexCounter + 1u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 byte src transfer size */
            DmaTcdList[DmaTcdListIndexCounter + 2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
            DmaTcdList[DmaTcdListIndexCounter + 2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 byte dest transfer size */
            DmaTcdList[DmaTcdListIndexCounter + 3u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
            DmaTcdList[DmaTcdListIndexCounter + 3u].Value = 4u;   /* src offset is 4 byte */
            DmaTcdListIndexCounter += 4u;
            State->PreRxTransferSize = LPSPI_IP_TRANSFER_SIZE_4_BYTE;
            State->RxDesSignedOffsetValue = 4u;
            DesSignedOffsetIsSet = TRUE;
        }
    }

    if ((NULL_PTR == State->RxBuffer) && (FALSE == State->IsPreRxBufferNull))
    {
        /* Discard Data */
        DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        DmaTcdList[DmaTcdListIndexCounter].Value = (uint32) & Lpspi_Ip_u32DiscardData;    /* dest address write*/
        DmaTcdList[DmaTcdListIndexCounter + 1u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        DmaTcdList[DmaTcdListIndexCounter + 1u].Value = 0u;   /* src offset is 0 byte */
        DmaTcdListIndexCounter += 2u;
        /* If RxBuffer of next channel is null, do not need re-configure DMA_IP_CH_SET_DESTINATION_ADDRESS */
        State->IsPreRxBufferNull = TRUE;
    }

    if (NULL_PTR != State->RxBuffer)
    {
        DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        DmaTcdList[DmaTcdListIndexCounter].Value = (uint32)State->RxBuffer;    /* dest address write*/
        DmaTcdListIndexCounter++;
        /* If previous channel has RX buffer is NULL and DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET is not updated, It must be updated here */
        if ((TRUE == State->IsPreRxBufferNull) && (FALSE == DesSignedOffsetIsSet))
        {
            DmaTcdList[DmaTcdListIndexCounter].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
            DmaTcdList[DmaTcdListIndexCounter].Value = State->RxDesSignedOffsetValue;   /* src offset is RxDesSignedOffsetValue byte */
            DmaTcdListIndexCounter++;
        }

        State->IsPreRxBufferNull = FALSE;
    }

    /* write TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, DmaTcdListIndexCounter);

    /* Enable RX DMA HW request */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

static void Lpspi_Ip_TxDmaContinueTransfer(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites - State->TxIndex;

    /* Limits number of major count */
    if (LPSPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = LPSPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    State->TxIndex += NumberDmaIterWrite;

    /* Update TX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[0u].Value = NumberDmaIterWrite;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);

    /* Disable TX DMA request to avoid overflow because RX DMA needs time to be initialized for next transfer,
    TX DMA request will be enabled later when RX DMA complete by Lpspi_Ip_RxDmaContinueTransfer. */
    Base->DER &= ~LPSPI_DER_TDDE_MASK;
    /* Enable TX DMA HW request for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    if (TRUE == State->PhyUnitConfig->SlaveMode)
    {
        /* Push first frame to TX FIFO to ensure that TX FIFO is not empty and CS can be kept in the case of CS continue */
        (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_SOFTWARE_REQUEST);
    }

#endif
}

static void Lpspi_Ip_RxDmaContinueTransfer(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
    uint16 NumberDmaIterRead = State->ExpectedFifoReads - State->RxIndex;

    /* Limits number of major count */
    if (LPSPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterRead)
    {
        NumberDmaIterRead = LPSPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    State->RxIndex += NumberDmaIterRead;

    /* Update RX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[0u].Value = NumberDmaIterRead;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);

    /* Enable DMA HW request for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    /* Enable TX DMA request due to it is disabled in Lpspi_Ip_TxDmaContinueTransfer */
    Base->DER |= LPSPI_DER_TDDE_MASK;
}

#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
static void Lpspi_Ip_RxDmaRepeatedContinueTransfer(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[2u];

    /* Limits number of major count */
    if (LPSPI_IP_DMA_MAX_ITER_CNT_U16 < State->ExpectedFifoReads)
    {
        State->ExpectedFifoReads = LPSPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    State->RxIndex += State->ExpectedFifoReads;

    /* Update RX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[0u].Value = State->ExpectedFifoReads;    /* iteration count */
    /* Update RX DMA channel */
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[1u].Value = (uint32)State->RxBuffer;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 2u);

    /* Enable DMA HW request for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    /* Enable TX DMA request due to it is disabled in Lpspi_Ip_TxDmaContinueTransfer */
    Base->DER |= LPSPI_DER_TDDE_MASK;
}

#endif /* if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON) */

/**
* @brief   This function will finish channel transmission via DMA.
* @details This function will finish channel transmission via DMA.
*
* @param[in]     Instance      Index of the hardware instance.
*/
static void Lpspi_Ip_TxDmaFinishTransfer(const uint8 Instance)
{
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    Lpspi_Ip_HalfDuplexType TransferType;
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint32 TimeoutTicks = OsIf_MicrosToTicks(LPSPI_IP_HALF_DUPLEX_TIMEOUT_COUNTER, LPSPI_IP_TIMEOUT_METHOD);
#endif
    LPSPI_Type *Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType *State = Lpspi_Ip_apxStateStructureArray[Instance];

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    TransferType = State->ExternalDevice->DeviceParams->TransferType;
    /* If next channel is TX, there is no need to wait for TX FIFO to drain */
    if (((TRUE == State->NextChannelIsRX) && (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType)) || (FALSE == State->KeepCs))
#else
    if (FALSE == State->KeepCs)
#endif
    {
        if (FALSE == State->KeepCs)
        {
            /* Clear CS, in slave mode CONT bit is always 0 so nothing will be done. */
            if (0u != (Base->TCR & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
            }
        }

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
        if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType)
        {
            /* Wait for TX FIFO to drain after transfer is completed */
            while ((((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
            {
                CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
            }

            if (ElapsedTicks >= TimeoutTicks)
            {
                /* Clear TX FIFO */
                Base->CR |= LPSPI_CR_RTF_MASK;
            }
        }

#endif /* if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) */
    }

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    (void)TimeoutTicks;
#endif
}

#if (LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)
static void Lpspi_Ip_TxDmaContMemTransferHandler(const uint8 Instance)
{
    LPSPI_Type *Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType *State = Lpspi_Ip_apxStateStructureArray[Instance];

    State->FirstCmd = FALSE;
    if (State->ContMemTransferCfg->TotalNumberOfTransfer <= State->ContMemTransferCfg->TransferNumsByChannel[State->ContMemTransferCfg->CurrentChannelIndex])
    {
        /* uninitialize driver's state  */
        State->IsCurrTransferInDmaContMemMode = FALSE;
        State->KeepCs = FALSE;
        Lpspi_Ip_TxDmaFinishTransfer(Instance);
    }
    else
    {
        State->ContMemTransferCfg->TotalNumberOfTransfer -= State->ContMemTransferCfg->TransferNumsByChannel[State->ContMemTransferCfg->CurrentChannelIndex];
        State->ContMemTransferCfg->CurrentChannelIndex++;
        State->TxBuffer = State->ContMemTransferCfg->TxBuffer[State->ContMemTransferCfg->CurrentChannelIndex];
        if (TRUE == State->KeepCs)
        {
            /* move chip select */
            Base->TCR &= ~LPSPI_TCR_CONT_MASK;
            Base->TCR |= LPSPI_TCR_CONT_MASK;
        }

        if (1U == State->ContMemTransferCfg->ChannelNumsByJob[State->ContMemTransferCfg->CurrentJobIndex])
        {
            /* Clear CS, in slave mode CONT bit is always 0 so nothing will be done. */
            if (0u != (Base->TCR & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR &= ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK);
            }

            State->ContMemTransferCfg->CurrentJobIndex++;
        }
        else
        {
            State->ContMemTransferCfg->ChannelNumsByJob[State->ContMemTransferCfg->CurrentJobIndex]--;
        }

        Lpspi_TransmitTxDmaContMemReconfig(Instance, State->TxBuffer, State->ContMemTransferCfg->TransferNumsByChannel[State->ContMemTransferCfg->CurrentChannelIndex]);
        /* reconfigure DMA for Tx */
        Lpspi_Ip_TxDmaConfig(Instance);
    }
}

#endif /* if (LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) */
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
static void Lpspi_Ip_TxDmaRepeatedTransferHandler(const uint8 Instance)
{
    LPSPI_Type *Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType *State = Lpspi_Ip_apxStateStructureArray[Instance];

    if (TRUE == State->FirstCmd)
    {
        State->FirstCmd = FALSE;
    }

    if (State->RepeatedTransferAttr->NewTxBuffer != State->TxBuffer)
    {
        State->TxBuffer = State->RepeatedTransferAttr->NewTxBuffer;
    }

    /* Clear CS. */
    if (0u != (Base->TCR & LPSPI_TCR_CONT_MASK))
    {
        Base->TCR &= ~(LPSPI_TCR_CONTC_MASK);
    }

    Lpspi_TransmitTxDmaContMemReconfig(Instance, State->TxBuffer, State->RepeatedTransferAttr->NewDataLength);
    /* reconfigure DMA for Tx */
    Lpspi_Ip_TxDmaConfig(Instance);
}

static void Lpspi_Ip_CheckingRepeatedTransferAttr(Lpspi_Ip_RepeatedTransferAttrType* RepeatedTransferAttr)
{
    if ((NULL_PTR == RepeatedTransferAttr->NewTxBuffer) || (NULL_PTR == RepeatedTransferAttr->NewRxBuffer) || ((uint16)0U == RepeatedTransferAttr->NewDataLength))
    {
        /* if any new transfer attribute is not valid, stop transfer */
        RepeatedTransferAttr->StopTransfer = TRUE;
    }
}

static void Lpspi_Ip_RepeatedTranserTxHandler(uint8 Instance)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];

    /* Check if the callback is available and first time goes to DMA major completed callback */
    if (State->DmaRepeatedCallback != NULL_PTR)
    {
        /* Default stop transfer */
        State->RepeatedTransferAttr->StopTransfer = TRUE;
        State->DmaRepeatedCallback(Instance, State->RepeatedTransferAttr, LPSPI_IP_REPEATED_TRANSFER_RECONFIGURE_START);
        /* Verify the input for new transfer. If not valid, stop transfer immediately */
        Lpspi_Ip_CheckingRepeatedTransferAttr(State->RepeatedTransferAttr);
    }

    if (State->RepeatedTransferAttr->StopTransfer == TRUE)
    {
        /* Stop transfer */
        Lpspi_Ip_TxDmaFinishTransfer(Instance);
    }
    else
    {
        /* Continue transfer, re-setup TX */
        Lpspi_Ip_TxDmaRepeatedTransferHandler(Instance);
    }
}

#endif /* if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON) */
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function will handler the end event for specific transfer type.
* @details This function will handler the end event for specific transfer type.
*
* @param[in]     Instance              Index of the hardware instance.
* @param[in]     EndOfTransferFlag     Determine transfer will be end or continuous.
*/
static void Lpspi_Ip_IrqTxDmaEndTransferHandler(uint8 Instance, boolean* EndOfTransferFlag)
{
#if ((LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) || (LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) || (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON))
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
#endif

    /* Mask EndOfTransferFlag to TRUE to finish transfer if transmit only mode */
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    /* In Transmit only mode, the transfer can be finished after TX have done transfer */
    /* In Receive only mode, the transfer need to wait for RX finish */
    if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType)
    {
        *EndOfTransferFlag = TRUE;
    }
#endif

#if (LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)
    if (TRUE == State->IsCurrTransferInDmaContMemMode)
    {
        Lpspi_Ip_TxDmaContMemTransferHandler(Instance);
    }
    else
#endif
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
    {
        if (TRUE == State->RepeatedTransfer)
        {
            Lpspi_Ip_RepeatedTranserTxHandler(Instance);
        }
        else
#endif
        {
            Lpspi_Ip_TxDmaFinishTransfer(Instance);
        }
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
    }
#endif
    (void)EndOfTransferFlag; /* avoid compiler warning */
}

/**
* @brief   This function will process TX DMA transfer complete interrupt.
* @details This function will process continue transfer or end of transfer via TX DMA.
*
* @param[in]     Instance      Index of the hardware instance.
* @implements Lpspi_Ip_IrqTxDmaHandler_Activity
*/
void Lpspi_Ip_IrqTxDmaHandler(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister = 0u;
    boolean ErrorFlag = FALSE;
    boolean EndOfTransferFlag = FALSE;
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    Lpspi_Ip_HalfDuplexType TransferType;
#endif

    if (NULL_PTR != State)
    {
        if (LPSPI_IP_BUSY == State->Status)
        {
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
            TransferType = State->ExternalDevice->DeviceParams->TransferType;
#endif
            /* Read Status an clear all flags. */
            SrStatusRegister = Base->SR;
            Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;

            if ((SrStatusRegister & (LPSPI_SR_REF_MASK | LPSPI_SR_TEF_MASK)) != 0u)
            {
                /* mark error flag */
                ErrorFlag = TRUE;

                /* Reset FIFO after errors */
                Lpspi_ResetFifo(Base, State, SrStatusRegister);
            }
            else
            {
                if (State->ExpectedFifoWrites != State->TxIndex)
                {
                    /* Transfer is not finished => update TX pointers */
                    Lpspi_Ip_TxDmaContinueTransfer(Instance);
                }
                else
                {
                    Lpspi_Ip_IrqTxDmaEndTransferHandler(Instance, &EndOfTransferFlag);
                }
            }

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
            if ((TRUE == ErrorFlag) || (TRUE == EndOfTransferFlag))
#else
            if (TRUE == ErrorFlag)
#endif
            {
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
                if ((FALSE == State->KeepCs) || (TRUE == ErrorFlag))
#endif
                {
                    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_13();
                    /* Disable module to stop transfer */
                    Base->CR &= ~LPSPI_CR_MEN_MASK;
                    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_13();
                }

                /* Disable DMA requests. */
                Base->DER = 0;
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
                if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType)
                {
                    Lpspi_Ip_TransferFinished(Instance, ErrorFlag);
                }
                else
#endif
                {
                    /* Disable RX DMA HW request because may RX DMA is not completed, no need to apply for TX DMA due to DMA HW request is cleared
                     * automatically */
                    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                    
                    Lpspi_Ip_TransferFinished(Instance, ErrorFlag);
                }
            }
        }
    }
    else
    {
        /* Driver is initialized but there was no poll request*/
        /* nothing to do */
    }
}

/**
* @brief   This function will process RX DMA transfer complete interrupt.
* @details This function will process continue transfer or end of transfer via RX DMA.
*
* @param[in]     Instance      Index of the hardware instance.
* @implements Lpspi_Ip_IrqRxDmaHandler_Activity
*/
void Lpspi_Ip_IrqRxDmaHandler(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister = 0u;
    boolean ErrorFlag = FALSE;
    boolean EndOfTransferFlag = FALSE;

    if (NULL_PTR != State)
    {
        if (LPSPI_IP_BUSY == State->Status)
        {
            /* Read Status an clear all flags. */
            SrStatusRegister = Base->SR;
            Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;

            if ((SrStatusRegister & (LPSPI_SR_REF_MASK | LPSPI_SR_TEF_MASK)) != 0u)
            {
                /* mark error flag */
                ErrorFlag = TRUE;

                /* Reset FIFO after errors */
                Lpspi_ResetFifo(Base, State, SrStatusRegister);
            }
            else
            {
                if (State->ExpectedFifoReads != State->RxIndex)
                {
                    /* Transfer is not finished => update RX pointers */
                    Lpspi_Ip_RxDmaContinueTransfer(Instance);
                }
                else
                {
#if (STD_ON == LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT)
                    if (TRUE == State->RepeatedTransfer)
                    {
                        if (State->RepeatedTransferAttr->StopTransfer == TRUE)
                        {
                            EndOfTransferFlag = TRUE;
                        }
                        else
                        {
                            /* Continue transfer, re-setup RX */
                            Lpspi_TransmitRxInit(Instance, State->RepeatedTransferAttr->NewRxBuffer, State->RepeatedTransferAttr->NewDataLength);
                            /* re-setup RX */
                            Lpspi_Ip_RxDmaRepeatedContinueTransfer(Instance);
                            if ((State->DmaRepeatedCallback != NULL_PTR) && (FALSE == State->RepeatedTransferAttr->StopTransfer))
                            {
                                State->DmaRepeatedCallback(Instance, NULL_PTR, LPSPI_IP_REPEATED_TRANSFER_RECONFIGURE_END);
                            }
                        }
                    }
                    else
#endif /* if (STD_ON == LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT) */
                    {
                        EndOfTransferFlag = TRUE;
                    }
                }
            }

            if ((TRUE == EndOfTransferFlag) || (TRUE == ErrorFlag))
            {
                if ((FALSE == State->KeepCs) || (TRUE == ErrorFlag))
                {
                    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_14();
                    /* Disable module to stop transfer */
                    Base->CR &= ~LPSPI_CR_MEN_MASK;
                    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14();
                }

                /* Disable DMA requests. */
                Base->DER = 0;
                if (TRUE == ErrorFlag)
                {
                    /* Disable TX DMA HW request because may TX DMA is not completed, no need to apply for RX DMA due to DMA HW request is cleared
                     * automatically */
                    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                }
                Lpspi_Ip_TransferFinished(Instance, ErrorFlag);
            }
        }
    }
    else
    {
        /* Driver is initialized but there was no poll request*/
        /* nothing to do */
    }
}

#endif /* (LPSPI_IP_DMA_USED == STD_ON) */

#if (LPSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
/**
* @brief This function will set UAA bit in REG_PROT for SPI unit
*/
void Lpspi_Ip_SetUserAccess(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];

    SET_USER_ACCESS_ALLOWED((uint32)Base, LPSPI_IP_PROT_MEM_U32);
}

/**
* @brief This function will enable writing all SPI registers under protection in User mode by configuring REG_PROT
*/
static void Lpspi_Ip_SetUserAccessAllowed(uint8 Instance)
{
    OsIf_Trusted_Call1param(Lpspi_Ip_SetUserAccess, Instance);
}

#endif /* LPSPI_IP_ENABLE_USER_MODE_SUPPORT */
/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_Init(const Lpspi_Ip_ConfigType *PhyUnitConfigPtr)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(PhyUnitConfigPtr != NULL_PTR);
#endif
    Instance = PhyUnitConfigPtr->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    Base = Lpspi_Ip_apxBases[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State == NULL_PTR);
#endif
    Lpspi_Ip_apxStateStructureArray[Instance] = &Lpspi_Ip_axStateStructure[PhyUnitConfigPtr->StateIndex];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    State->PhyUnitConfig = PhyUnitConfigPtr;
    /* enable in debug mode to ensure CS will be kept when CPU halts at breakpoint */
    Base->CR = PhyUnitConfigPtr->Cr | LPSPI_CR_DBGEN_MASK;
    Base->CFGR1 = PhyUnitConfigPtr->Cfgr1;
    /* To avoid overflow error when interrupt service is delayed, the maximum number of TX FIFO entry
    can be filled is LPSPI_IP_FIFO_SIZE_U8 - 1 because may 1 frame is shifting out */
    Base->FCR = LPSPI_FCR_TXWATER((uint32)LPSPI_IP_FIFO_SIZE_U8 - (uint32)2u);
#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
    State->ClockMode = LPSPI_IP_NORMAL_CLOCK;
#endif
    State->KeepCs = FALSE;
    State->FirstCmd = TRUE;
#ifdef ERR_IPV_LPSPIV2_E050456
#ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION
    State->TxFifoResetNeeded = FALSE;
#endif
#endif
#if ((LPSPI_IP_DMA_USED == STD_ON) && (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    Lpspi_Ip_TxDmaTcdSGInit(Instance);
    Lpspi_Ip_RxDmaTcdSGInit(Instance);
#endif
#if (LPSPI_IP_DMA_USED == STD_ON)
    if (TRUE == State->PhyUnitConfig->DmaUsed)
    {
        Lpspi_Ip_DmaInit(Instance);
    }

#endif
    /* set State to idle */
    State->Status = LPSPI_IP_IDLE;
    (void)Lpspi_Ip_UpdateTransferMode(Instance, PhyUnitConfigPtr->TransferMode);

    return Status;
}

/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_DeInit(uint8 Instance)
{
    LPSPI_Type* Base;
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
#endif
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    if (LPSPI_IP_BUSY == State->Status)
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Use reset hardware feature. */
        Base->CR |= LPSPI_CR_RST(1u);
        Base->CR = 0;

        Lpspi_Ip_apxStateStructureArray[Instance] = NULL_PTR;
    }

    return Status;
}

/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_SyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                          const uint8 *TxBuffer,
                                          uint8 *RxBuffer,
                                          uint16 Length,
                                          uint32 TimeOut)
{
    LPSPI_Type *Base;
    Lpspi_Ip_StateStructureType *State;
    uint8 NumberOfReads;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 Instance = 0u;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    DevAssert(0u != TimeOut);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
#endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
#endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();

        /* Disable DMA requests and all interrupts */
        Base->DER = 0u;
        Base->IER = 0u;
        Base->CFGR0 = State->ExternalDevice->Cfgr0;

        /* Reset current FIFO slots are available to fill at beginning of job (HLD).*/
        State->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
        Lpspi_TransmitTxInit(Instance, (const uint8*)TxBuffer, Length);
        Lpspi_TransmitRxInit(Instance, RxBuffer, Length);

        CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD); /* initialize current counter */
        while (State->RxIndex != State->ExpectedFifoReads)
        {
            /* RECEIVE DATA */
            /* Read all Data available in receive HW fifo. */
            NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
            if (NumberOfReads != 0u)
            {
                if (NumberOfReads > LPSPI_IP_FIFO_SIZE_U8)
                {
                    NumberOfReads = LPSPI_IP_FIFO_SIZE_U8;
                }
                /* Limits to remaining frames. */
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }

                /* If these are the first frames of this channel. Current TXFIFO slot must be plus 1 because the slot of CMD have moved out */
                if (0u == State->RxIndex)
                {
                    State->CurrentTxFifoSlot += 1u;
                }

                /* Read Data from RX FIFO */
                Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                /* Update current FIFO slots are available to fill .*/
                State->CurrentTxFifoSlot += NumberOfReads;
                ElapsedTicks = 0u;
            }

            /* TRANSMIT DATA */
            /* Push Data until HW fifo is full or transfer is done. */
            /* After driver code read all frames in RX FIFO, if there are still some frames in TX FIFO, at the time before driver code check number of frames available in TX FIFO
            to prepare to fill TX FIFO. At that time, interrupt occurred, and the time to process interrupt is longer than the time to transfer all frames in TX FIFO.
            So TX FIFO will be empty and some frames received in RX FIFO, then the program is returned from interrupt and fill TX FIFO until full.
            And there is a interrupt occurred after that before read all frames in RX FIFO, and the time to process interrupt is longer than the time to transfer all frames in TX FIFO.
            State->CurrentTxFifoSlot variable is used to handle number of frames are "on bus transfer". They are always less than FIFO size */
            if ((State->CurrentTxFifoSlot != 0u))
            {
                if (State->ExpectedFifoWrites != State->TxIndex)
                {
                    Lpspi_Ip_TransmitProcess(Instance);
                    ElapsedTicks = 0u;
                }
                else
                {
                    Lpspi_Ip_ClearCS(Instance);
                }
            }

            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                Status = LPSPI_IP_TIMEOUT;
                break;
            }
        }

        if ((LPSPI_IP_STATUS_SUCCESS != Status) || (0u == Length))
        {
#if (STD_OFF == LPSPI_IP_DEV_ERROR_DETECT)
            /* Return Fail status if length is 0. Error Detect is enabled, nothing need to be done here */
            if (0u == Length)
            {
                Status = LPSPI_IP_STATUS_FAIL;
            }

#endif
            State->Status = LPSPI_IP_FAULT;
        }
        else
        {
            State->Status = LPSPI_IP_IDLE;
        }
    }

    return Status;
}

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
Lpspi_Ip_StatusType Lpspi_Ip_SyncTransmitHalfDuplex(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                    uint8 *Buffer,
                                                    uint16 Length,
                                                    Lpspi_Ip_HalfDuplexType TransferType,
                                                    uint32 TimeOut)
{
    LPSPI_Type *Base;
    Lpspi_Ip_StateStructureType *State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 Instance = 0u;
    boolean TransferCompleted = FALSE;
    uint8 NumberOfFramesTxFifo;
    uint8 NumberOfWrites;
    uint8 NumberOfReads;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
#endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
#endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        /* Update TransferType */
        State->ExternalDevice->DeviceParams->TransferType = TransferType;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();

        /* Prepare the transfer: Write to CFGR1 register the bit fields supporting Half duplex, get transfer buffer, get CMD value in receive mode.*/
        Lpspi_Ip_HalfDuplexPrepare(Instance, Buffer);

        /* Disable DMA requests and all interrupts */
        Base->DER = 0u;
        Base->IER = 0u;
        Base->CFGR0 = State->ExternalDevice->Cfgr0;
        /* Init TX channel */
        Lpspi_TransmitTxInit(Instance, NULL_PTR, Length);
        /* If in half duplex Transmit only mode, RX do not need to be configured */
        if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
        {
            Lpspi_TransmitRxInit(Instance, NULL_PTR, Length);
        }

        /* initialize current counter */
        CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
        while ((TRUE != TransferCompleted) && (LPSPI_IP_STATUS_SUCCESS == Status))
        {
            if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
            {
                /* RECEIVE DATA */
                /* Read all Data available in receive HW fifo. */
                NumberOfReads = (uint8)(((Base->FSR) & LPSPI_FSR_RXCOUNT_MASK) >> LPSPI_FSR_RXCOUNT_SHIFT);
                if (NumberOfReads > LPSPI_IP_FIFO_SIZE_U8)
                {
                    NumberOfReads = LPSPI_IP_FIFO_SIZE_U8;
                }
                if (NumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
                {
                    NumberOfReads = (uint8)(State->ExpectedFifoReads - State->RxIndex);
                }

                if (0u != NumberOfReads)
                {
                    Lpspi_Ip_ReadDataFromFifo(Instance, NumberOfReads);
                }

                /* PUSH CMD */
                /* Only write to TCR when TX FIFO is empty in receive mode */
                if ((0u == ((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK)) && (State->ExpectedFifoWrites != State->TxIndex))
                {
                    /* Push one CMD to start transfer. */
                    Base->TCR = State->HalfDuplexTcrCommand;
                    State->TxIndex++;
                }

                ElapsedTicks = 0u;
                if (State->ExpectedFifoReads == State->RxIndex)
                {
                    /* if all frames have received, break from the while loop to finish transfer */
                    break;
                }
            }
            else
            {
                /* TRANSMIT DATA */
                /* Push Data until HW fifo is full or transfer is done. */
                NumberOfFramesTxFifo = (uint8)(((Base->FSR) & LPSPI_FSR_TXCOUNT_MASK) >> LPSPI_FSR_TXCOUNT_SHIFT);
                if (NumberOfFramesTxFifo > LPSPI_IP_FIFO_SIZE_U8)
                {
                    NumberOfFramesTxFifo = LPSPI_IP_FIFO_SIZE_U8;
                }
                NumberOfWrites = LPSPI_IP_FIFO_SIZE_U8 - NumberOfFramesTxFifo;
                if (0u != NumberOfWrites)
                {
                    TransferCompleted = Lpspi_Ip_HalfDuplexTransmitProcess(Instance, NumberOfWrites);
                }

                /* If next channel is TX, there is no need to wait for TX FIFO to drain */
                if ((TRUE == TransferCompleted) && ((TRUE == State->NextChannelIsRX) || (FALSE == State->KeepCs)))
                {
                    TransferCompleted = Lpspi_Ip_GetTxFifoTransferStatus(Instance);
                }

                ElapsedTicks = 0u;
            }

            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                Status = LPSPI_IP_TIMEOUT;
            }
        }

        if (LPSPI_IP_STATUS_SUCCESS != Status)
        {
            State->Status = LPSPI_IP_FAULT;
        }
        else
        {
            State->Status = LPSPI_IP_IDLE;
        }
    }

    return Status;
}

#endif /* if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) */

#ifdef ERR_IPV_LPSPIV2_E050456
static void Lpspi_ErrataHandle(LPSPI_Type* Base,
                               Lpspi_Ip_StateStructureType* State)
{
#ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION
    uint32 Data;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(LPSPI_IP_ERR_TIMEOUT_COUNTER, LPSPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
#else
    uint32 Cfgr0 = 0u;
    uint32 Cfgr1 = 0u;
#endif
#ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION
    /* ERR050456 workaround second solution */
    Base->CR |= LPSPI_CR_RRF_MASK; /* Resetting Receive FIFO */

    /* reading the receive FIFO immediately after resetting the receive FIFO will reset the pointers correctly */
    Data = Base->RDR;
    (void)Data;

    /* Skip reset Tx fifo if hardware already reset */
    if (State->TxFifoResetNeeded)
    {
        /* Resetting Transmit FIFO */
        Base->CR |= LPSPI_CR_RTF_MASK;
        /* initialize current counter */
        CurrentTicks = OsIf_GetCounter(LPSPI_IP_TIMEOUT_METHOD);
        /* LPSPIn_CR[RTF] software needs to then wait for the transfer to complete with SR[TCF] set to 1 */
        while (LPSPI_SR_TCF_MASK != (Base->SR & LPSPI_SR_TCF_MASK))
        {
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, LPSPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                break;
            }
        }
    }
    else
    {
        State->TxFifoResetNeeded = TRUE;
    }

#else  /* ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION */
    /* ERR050456 workaround first solution: Reset FIFOs using CR[RST] bit */
    /* Store CFGR0 and CFGR1 and restore after all registers are reset */
    Cfgr0 = Base->CFGR0;
    Cfgr1 = Base->CFGR1;
    Base->CR |= LPSPI_CR_RST_MASK;
    Base->CR &= ~LPSPI_CR_RST_MASK;
    /* restore CFGR0 and CFGR1 */
    Base->CFGR0 = Cfgr0;
    Base->CFGR1 = Cfgr1;
    (void)State;
#endif /* ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION */
}

#else  /* ifdef ERR_IPV_LPSPIV2_E050456 */
static void Lpspi_HardResetFifo(LPSPI_Type* Base)
{
    uint32 Cfgr0 = 0u;
    uint32 Cfgr1 = 0u;

    /* Found a wrong behavior that needs to execute CR[RTF] and CR[RRF] twice to reset FIFO: ARTD-99928 */
    /* Temporary use CR[RST] to reset FIFO instead of CR[RTF] and CR[RRF] */
    /* Store CFGR0 and CFGR1 and restore after all registers are reset */
    Cfgr0 = Base->CFGR0;
    Cfgr1 = Base->CFGR1;
    Base->CR |= LPSPI_CR_RST_MASK;
    Base->CR &= ~LPSPI_CR_RST_MASK;
    /* restore CFGR0 and CFGR1 */
    Base->CFGR0 = Cfgr0;
    Base->CFGR1 = Cfgr1;
}

#endif /*ERR_IPV_LPSPIV2_E050456*/

static void Lpspi_ResetFifo(LPSPI_Type* Base,
                            const Lpspi_Ip_StateStructureType* State,
                            uint32 StatusRegister)
{
    if ((StatusRegister & LPSPI_SR_REF_MASK) != 0u)
    {
        /* Reset Receive FIFO after FIFO overflow error */
        Base->CR |= LPSPI_CR_RRF_MASK;
    }

#if (defined (ERR_IPV_LPSPIV2_E051588) && (LPSPI_IP_SLAVE_SUPPORT == STD_ON))
    if (((StatusRegister & LPSPI_SR_TEF_MASK) != 0u) && (TRUE == State->PhyUnitConfig->SlaveMode))
    {
        /* ERR051588 workaround: Reset Transmit FIFO after FIFO underrun by LPSPI Slave */
        Base->CR |= LPSPI_CR_RTF_MASK;
    }

#else
    (void)State; /* Avoid compiler warning */
#endif
}

static void Lpspi_ConfigureCCR(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
#ifdef ERR_IPV_LPSPIV2_E050456
    Lpspi_Ip_StateStructureType *State = Lpspi_Ip_apxStateStructureArray[Instance];
#else
    const Lpspi_Ip_StateStructureType *State = Lpspi_Ip_apxStateStructureArray[Instance];
#endif

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11();
    /* Disable module before configure CCR */
    Base->CR &= ~LPSPI_CR_MEN_MASK;
    /* Make sure that FIFOs will be empty before start new transfer session */
#ifdef ERR_IPV_LPSPIV2_E050456
    Lpspi_ErrataHandle(Base, State);
#else
    Lpspi_HardResetFifo(Base);
#endif
    /* clear all flags */
    Base->SR &= (uint32)0xFFFFFFFFu;
    /* Does not use the Clock Configuration Register (CCR) for Slave mode */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    if (FALSE == State->PhyUnitConfig->SlaveMode)
#endif
    {
#if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
        Base->CCR = State->ExternalDevice->Ccr[State->ClockMode];
#else
        Base->CCR = State->ExternalDevice->Ccr;
#endif
        /* Enable module after configure CCR completed. For Slave mode, it will be enabled after finish configuring TCR register */
        Base->CR |= LPSPI_CR_MEN_MASK;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
    }
}

static void Lpspi_TransmitTxInit(uint8 Instance,
                                 const uint8* TxBuffer,
                                 uint16 NumberOfFrames)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 TransferCommand = 0u;

    uint32 Lsbf = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
    uint32 ByteSwap = State->ExternalDevice->DeviceParams->ByteSwap ? 1UL : 0UL;

    /* Set clock configuration */
    if (TRUE == State->FirstCmd)
    {
        Lpspi_ConfigureCCR(Instance);
    }

    /* Get transfer command */
#if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
    TransferCommand = State->ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf) | LPSPI_TCR_BYSW(ByteSwap);
#else
    TransferCommand = State->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf) | LPSPI_TCR_BYSW(ByteSwap);
#endif

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    /* In RX only mode, TX FIFO will be masked, Push CMD to TX FIFO to transfer and pushing CMD will be done in transfer time. Push nothing to TCR
     * register here */
    if (LPSPI_IP_HALF_DUPLEX_RECEIVE != State->ExternalDevice->DeviceParams->TransferType)
#endif
    {
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
        if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType)
        {
            /* Mask RX FIFO in Transmit only mode */
            TransferCommand |= LPSPI_TCR_RXMSK_MASK;
        }

#endif
        /* In Slave mode, CONT bit should be cleared */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
        }

#endif

        if (TRUE == State->FirstCmd)
        {
            /* Set transfer command */
            Base->TCR = TransferCommand;
        }
        else
        {
            if (0u != (TransferCommand & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR = TransferCommand | LPSPI_TCR_CONTC_MASK;
            }
            else
            {
                Base->TCR = TransferCommand;
            }
        }

        /* Enable module after write to TCR in slave mode completed */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            Base->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }

#endif
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
        if (LPSPI_IP_FULL_DUPLEX == State->ExternalDevice->DeviceParams->TransferType)
#endif
        {
            /* CMD will take 1 slot in TXFIFO, update current TX FIFO slot. it will be plus 1 when the first frames of channel have received */
            State->CurrentTxFifoSlot -= 1u;
        }
    }

#if ((LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) && (LPSPI_IP_SLAVE_SUPPORT == STD_ON))
    else
    {
        /* In Receive only mode of Slave, a CMD with TXMSK should be push here */
        if (TRUE == State->PhyUnitConfig->SlaveMode)
        {
            /* Mask TX in Transmit only mode */
            TransferCommand |= LPSPI_TCR_TXMSK_MASK;
            TransferCommand &= ~LPSPI_TCR_CONT_MASK;
            Base->TCR = TransferCommand;
            /* Enable module after write to TCR in slave mode completed */
            Base->CR |= LPSPI_CR_MEN_MASK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
        }
    }
#endif /* if ((LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) && (LPSPI_IP_SLAVE_SUPPORT == STD_ON)) */
    /* Update State structure. */
    State->TxIndex = 0u;
    /* In half duplex mode, TX buffer have updated */
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
    {
        /* Avoid misra and compiler warning violation */
        (void)TxBuffer;
    }
    else
#endif
    {
        State->TxBuffer = TxBuffer;
    }

    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        State->ExpectedFifoWrites = NumberOfFrames;
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        if ((NumberOfFrames % 2u) == 0U)
        {
            State->ExpectedFifoWrites = NumberOfFrames / 2u;
        }
        else
        {
            State->ExpectedFifoWrites = (NumberOfFrames / 2u) + 1u;
        }
    }
    else
    {
        if ((NumberOfFrames % 4u) == 0U)
        {
            State->ExpectedFifoWrites = NumberOfFrames / 4u;
        }
        else
        {
            State->ExpectedFifoWrites = (NumberOfFrames / 4u) + 1u;
        }
    }
}

#if ((LPSPI_IP_DMA_USED == STD_ON) && ((LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) || (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)))
static void Lpspi_TransmitTxDmaContMemReconfig(uint8 Instance,
                                               const uint8* TxBuffer,
                                               uint16 NumberOfFrames)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 TransferCommand = 0u;
    uint32 Lsbf = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
    uint32 ByteSwap = State->ExternalDevice->DeviceParams->ByteSwap ? 1UL : 0UL;

    /* Set clock configuration */
    if (TRUE == State->FirstCmd)
    {
        Lpspi_ConfigureCCR(Instance);
    }

    /* Get transfer command */
#if (STD_ON == LPSPI_IP_DUAL_CLOCK_MODE)
    TransferCommand = State->ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf) | LPSPI_TCR_BYSW(ByteSwap);
#else
    TransferCommand = State->ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(Lsbf) | LPSPI_TCR_BYSW(ByteSwap);
#endif
    /* In Slave mode, CONT bit should be cleared */
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    if (TRUE == State->PhyUnitConfig->SlaveMode)
    {
        TransferCommand &= ~LPSPI_TCR_CONT_MASK;
    }

#endif
    {
        if (TRUE == State->FirstCmd)
        {
            /* Set transfer command */
            Base->TCR = TransferCommand;
        }
        else
        {
            if (0u != (TransferCommand & LPSPI_TCR_CONT_MASK))
            {
                Base->TCR = TransferCommand | LPSPI_TCR_CONTC_MASK;
            }
            else
            {
                Base->TCR = TransferCommand;
            }
        }

        {
            /* CMD will take 1 slot in TXFIFO, update current TX FIFO slot. it will be plus 1 when the first frames of channel have recieved */
            State->CurrentTxFifoSlot -= 1u;
        }
    }

    /* Update State structure. */
    State->TxIndex = 0u;
    /* In half duplex mode, TX buffer have updated */
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
    {
        /* Avoid misra and compiler warning violation */
        (void)TxBuffer;
    }
    else
#endif
    {
        State->TxBuffer = TxBuffer;
    }

    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        State->ExpectedFifoWrites = NumberOfFrames;
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        if ((NumberOfFrames % 2u) == 0U)
        {
            State->ExpectedFifoWrites = NumberOfFrames / 2u;
        }
        else
        {
            State->ExpectedFifoWrites = (NumberOfFrames / 2u) + 1u;
        }
    }
    else
    {
        if ((NumberOfFrames % 4u) == 0U)
        {
            State->ExpectedFifoWrites = NumberOfFrames / 4u;
        }
        else
        {
            State->ExpectedFifoWrites = (NumberOfFrames / 4u) + 1u;
        }
    }
}

#endif /* if ((LPSPI_IP_DMA_USED == STD_ON) && ((LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) ||
        * (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON))) */

static void Lpspi_TransmitRxInit(uint8 Instance,
                                 uint8* RxBuffer,
                                 uint16 NumberOfFrames)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];

    /* Update State structure. */
    State->RxIndex = 0u;
    /* In half duplex mode, RX buffer have updated */
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
    if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
    {
        (void)RxBuffer;
    }
    else
#endif
    {
        State->RxBuffer = RxBuffer;
    }

    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        State->ExpectedFifoReads = NumberOfFrames;
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        if ((NumberOfFrames % 2u) == 0U)
        {
            State->ExpectedFifoReads = NumberOfFrames / 2u;
        }
        else
        {
            State->ExpectedFifoReads = (NumberOfFrames / 2u) + 1u;
        }
    }
    else
    {
        if ((NumberOfFrames % 4u) == 0U)
        {
            State->ExpectedFifoReads = NumberOfFrames / 4u;
        }
        else
        {
            State->ExpectedFifoReads = (NumberOfFrames / 4u) + 1u;
        }
    }
}

Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                           const uint8 *TxBuffer,
                                           uint8 *RxBuffer,
                                           uint16 Length,
                                           Lpspi_Ip_CallbackType EndCallback)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
#endif

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
#endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
#endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
        /* Clear some bits which support for half duplex mode at previous transfer */
        Base->CFGR1 &= ~(LPSPI_CFGR1_PCSCFG_MASK | LPSPI_CFGR1_OUTCFG_MASK | LPSPI_CFGR1_PINCFG_MASK);
#endif
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();

        Base->CFGR0 = State->ExternalDevice->Cfgr0;
        /* Update State structure. */
        State->Callback = EndCallback;

        /* Reset current FIFO slots are available to fill at beginning of job (HLD).*/
        State->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
        Lpspi_TransmitTxInit(Instance, (const uint8*)TxBuffer, Length);
        Lpspi_TransmitRxInit(Instance, RxBuffer, Length);

#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMA_REPEATED_TRANSFER_SUPPORT == STD_ON)
        /* Set the initial value for RepeatedTransfer Attribute */
        State->RepeatedTransfer = ExternalDevice->RepeatedTransfer;
        State->RepeatedTransferAttr->NewDataLength = Length;
        State->RepeatedTransferAttr->NewTxBuffer = TxBuffer;
        State->RepeatedTransferAttr->NewRxBuffer = RxBuffer;
        /* If not having input from user, the transfer will be stopped automatically after complete current transfer */
        State->RepeatedTransferAttr->StopTransfer = TRUE;
        /* Store repeated user callback for using in runtime */
        State->DmaRepeatedCallback = ExternalDevice->DmaRepeatedCallback;
#endif

        if (FALSE == State->PhyUnitConfig->DmaUsed)
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
        {
            /* Disable DMA requests */
            Base->DER = 0u;
            switch (State->TransferMode)
            {
                case LPSPI_IP_POLLING:
                    /* Disable interrupts. */
                    Base->IER = 0u;
                break;
                case LPSPI_IP_INTERRUPT:
                    Base->IER = LPSPI_IER_RDIE_MASK | LPSPI_IER_TDIE_MASK | LPSPI_IER_REIE_MASK | LPSPI_IER_TEIE_MASK;
                break;
                default:
                    /* Nothing to do */
                break;
            }
        }

#if (LPSPI_IP_DMA_USED == STD_ON)
        else
        {
            /* Disable all interrupts */
            Base->IER = 0u;
            /* If previous transfer used DMA fast mode, DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT must be set again here for normal DMA mode */
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
            if (State->IsPreTransferInDmaFastMode)
            {
                /* Clear all flags of previous transfer. Some of thems will be cleared in Lpspi_Ip_DmaInit */
                State->PreTxTransferSize = LPSPI_IP_TRANSFER_SIZE_UNUNIT;
                State->PreRxTransferSize = LPSPI_IP_TRANSFER_SIZE_UNUNIT;
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
                State->IsPreChanneHalfDuplexlRxMode = FALSE;
#endif
                /* If previous transfer using DMA fast mode. Tcds for normal dma mode should be init again here */
                Lpspi_Ip_DmaInit(Instance);
                /* Activate TX DMA and RX DMA interrupt in interrupt mode or disable then in polling mode. */
                DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
                switch (State->TransferMode)
                {
                    case LPSPI_IP_POLLING:
                        /* Disable DMA major interrupt. */
                        DmaTcdList[0u].Value = 0u;
                    break;
                    case LPSPI_IP_INTERRUPT:
                        /* Enable DMA major interrupt. */
                        DmaTcdList[0u].Value = 1u;
                    break;
                    default:
                        /* Nothing to do */
                    break;
                }

                (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);
                (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);
                /* Set DMA fast mode used flag */
                State->IsPreTransferInDmaFastMode = FALSE;
            }
            else
            {
                (void)DmaTcdList[0];
            }

#endif /* if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) */
            /* Initialize DMA configuration for RX before TX*/
            Lpspi_Ip_RxDmaConfig(Instance);
            Lpspi_Ip_TxDmaConfig(Instance);
            /* Enable DMA request. */
            Base->DER = LPSPI_DER_RDDE_MASK | LPSPI_DER_TDDE_MASK;
        }
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
    }

    return Status;
}

#if ((LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) && (LPSPI_IP_DMA_USED == STD_ON))
Lpspi_Ip_StatusType Lpspi_Ip_DmaContMemAsyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                     Lpspi_Ip_TxBufferListType *SeqTxBufferList,
                                                     uint8 *RxBuffer,
                                                     Lpspi_Ip_CallbackType EndCallback)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(NULL_PTR != SeqTxBufferList);
    DevAssert(NULL_PTR != RxBuffer);
#endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
#endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();

        /* Update State structure. */
        State->Callback = EndCallback;
        /* Update State structure. */
        State->FirstCmd = TRUE;
        /* Update State structure. */
        State->IsCurrTransferInDmaContMemMode = TRUE;
        /* Update State structure. */
        State->ContMemTransferCfg = SeqTxBufferList;
        Base->CFGR0 = State->ExternalDevice->Cfgr0;

        /* Reset current FIFO slots are available to fill at beginning of job (HLD).*/
        State->CurrentTxFifoSlot = LPSPI_IP_FIFO_SIZE_U8;
        Lpspi_TransmitTxInit(Instance, (const uint8*)State->ContMemTransferCfg->TxBuffer[State->ContMemTransferCfg->CurrentChannelIndex], SeqTxBufferList->TransferNumsByChannel[State->ContMemTransferCfg->CurrentChannelIndex]);
        Lpspi_TransmitRxInit(Instance, RxBuffer, (uint16)SeqTxBufferList->TotalNumberOfTransfer);
        /* Disable all interrupts */
        Base->IER = 0u;
        /* Initialize DMA configuration for RX before TX*/
        Lpspi_Ip_RxDmaConfig(Instance);
        Lpspi_Ip_TxDmaConfig(Instance);
        /* Enable DMA request. */
        Base->DER = LPSPI_DER_RDDE_MASK | LPSPI_DER_TDDE_MASK;
    }

    return Status;
}

#endif /* if ((LPSPI_IP_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON) && (LPSPI_IP_DMA_USED == STD_ON)) */

#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmitHalfDuplex(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                     uint8 *Buffer,
                                                     uint16 Length,
                                                     Lpspi_Ip_HalfDuplexType TransferType,
                                                     Lpspi_Ip_CallbackType EndCallback)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
    uint32 InterruptEnable = 0u;
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
#endif

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Lpspi_Ip_CheckValidParameters(ExternalDevice, Length);
#endif
    Instance = ExternalDevice->Instance;
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
#endif

    Base = Lpspi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        /* Update TransferType */
        State->ExternalDevice->DeviceParams->TransferType = TransferType;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();

        Base->CFGR0 = State->ExternalDevice->Cfgr0;
        /* Prepare the transfer: Write to CFGR1 register the bit fields supporting Half duplex, get transfer buffer, get CMD value in reeive mode.*/
        Lpspi_Ip_HalfDuplexPrepare(Instance, Buffer);

        /* Update State structure. */
        State->Callback = EndCallback;

        /* Init TX channel */
        Lpspi_TransmitTxInit(Instance, NULL_PTR, Length);
        /* If in half duplex Transmit only mode, RX do not need to be configured */
        if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
        {
            Lpspi_TransmitRxInit(Instance, NULL_PTR, Length);
        }

#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        if ((TRUE == State->PhyUnitConfig->SlaveMode) && (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType))
        {
            /* In slave receive mode, only use RX Flags */
            InterruptEnable = LPSPI_IER_RDIE_MASK | LPSPI_IER_REIE_MASK;
        }
        else
#endif
        {
            /* Others mode still use TX flag to trigger to push CMDs */
            /* In Transmit mode, RXFIFO will be masked so RX flag will not be enabled.*/
            if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType)
            {
                InterruptEnable = LPSPI_IER_TDIE_MASK | LPSPI_IER_TEIE_MASK;
            }
            else
            {
                InterruptEnable = LPSPI_IER_RDIE_MASK | LPSPI_IER_TDIE_MASK | LPSPI_IER_REIE_MASK | LPSPI_IER_TEIE_MASK;
            }
        }

#if (LPSPI_IP_DMA_USED == STD_ON)
        if (FALSE == State->PhyUnitConfig->DmaUsed)
#endif
        {
            /* In Receive mode, Next CMD could be only pushed to TXFIFO when previous CMD have moved out (TXFIFO is empty)
               On Slave receive mode, do not care about TX WATER because TDIE flag is not set */
            if (LPSPI_IP_HALF_DUPLEX_RECEIVE == TransferType)
            {
                Base->FCR = LPSPI_FCR_TXWATER(0u);
            }
            else
            {
                Base->FCR = LPSPI_FCR_TXWATER((uint32)LPSPI_IP_FIFO_SIZE_U8 - (uint32)1u);
            }

            /* Disable DMA requests */
            Base->DER = 0u;
            switch (State->TransferMode)
            {
                case LPSPI_IP_POLLING:
                    /* Disable interrupts. */
                    Base->IER = 0u;
                break;
                case LPSPI_IP_INTERRUPT:
                    Base->IER = InterruptEnable;
                break;
                default:
                    /* Nothing to do */
                break;
            }
        }

#if (LPSPI_IP_DMA_USED == STD_ON)
        else
        {
            /* Disable all interrupts */
            Base->IER = 0u;
            /* If previous transfer used DMA fast mode, DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT must be set again here for normal DMA mode */
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
            if (State->IsPreTransferInDmaFastMode)
            {
                /* Activate TX DMA and RX DMA interrupt in interrupt mode or disable then in polling mode. */
                DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
                switch (State->TransferMode)
                {
                    case LPSPI_IP_POLLING:
                        /* Disable DMA major interrupt. */
                        DmaTcdList[0u].Value = 0u;
                    break;
                    case LPSPI_IP_INTERRUPT:
                        /* Enable DMA major interrupt. */
                        DmaTcdList[0u].Value = 1u;
                    break;
                    default:
                        /* Nothing to do */
                    break;
                }

                (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);
                (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);
                /* Set DMA fast mode used flag */
                State->IsPreTransferInDmaFastMode = FALSE;
            }

#endif /* if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) */
            if (LPSPI_IP_HALF_DUPLEX_TRANSMIT == TransferType)
            {
                /* In Transmit only mode, this function only is called here */
                Lpspi_Ip_TxDmaConfig(Instance);
                /* Enable DMA request. */
                Base->DER = LPSPI_DER_TDDE_MASK;
            }
            else
            {
                /* TX WATER sets to 0 to make sure that TX DMA only write 1 CMD and waiting for this CMD have moved out to perform to push next CMD */
                Base->FCR = LPSPI_FCR_TXWATER(0u);

#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
                if (TRUE == State->PhyUnitConfig->SlaveMode)
                {
                    /* In Half duplex slave receive mode, only RX DMA channel needed */
                    Lpspi_Ip_RxDmaConfig(Instance);
                    /* Enable DMA request. */
                    Base->DER = LPSPI_DER_RDDE_MASK;
                }
                else
#endif
                {
                    /* In receive only mode, TX DMA Channel will be used to push CMD to start transfer */
                    Lpspi_Ip_RxDmaConfig(Instance);
                    Lpspi_Ip_TxDmaConfig(Instance);
                    /* Enable DMA request. */
                    Base->DER = LPSPI_DER_RDDE_MASK | LPSPI_DER_TDDE_MASK;
                }
            }
        }
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
    }

    return Status;
}

#endif /* if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON) */

#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmitFast(const Lpspi_Ip_FastTransferType *FastTransferCfg,
                                               uint8 NumberOfTransfer,
                                               Lpspi_Ip_CallbackType EndCallback)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    uint8 Count = 0u;
#endif

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != FastTransferCfg);
    DevAssert(NULL_PTR != FastTransferCfg[0u].ExternalDevice);
#endif
    Instance = FastTransferCfg[0u].ExternalDevice->Instance;
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
    DevAssert(State->TransferMode == LPSPI_IP_INTERRUPT);
    DevAssert(NumberOfTransfer <= State->PhyUnitConfig->MaxNumOfFastTransfer);
    for (Count = 0u; Count < NumberOfTransfer; Count++)
    {
        DevAssert(NULL_PTR != FastTransferCfg[Count].ExternalDevice);
        DevAssert(0u != FastTransferCfg[Count].Length);
        if (FastTransferCfg[0u].ExternalDevice->DeviceParams->FrameSize > 16u)
        {
            DevAssert((FastTransferCfg[Count].Length % 4) == 0u);
        }
        else if (FastTransferCfg[0u].ExternalDevice->DeviceParams->FrameSize > 8u)
        {
            DevAssert((FastTransferCfg[Count].Length % 2) == 0u);
        }
        else
        {
            DevAssert(LPSPI_IP_DMA_MAX_ITER_CNT_U16 >= FastTransferCfg[Count].Length);
        }
    }

#endif /* if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON) */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_15();
    if (LPSPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark this instance used DMA fast mode */
        State->IsPreTransferInDmaFastMode = TRUE;
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
        /* Clear some bits which support for half duplex mode at previous transfer */
        Base->CFGR1 &= ~(LPSPI_CFGR1_PCSCFG_MASK | LPSPI_CFGR1_OUTCFG_MASK | LPSPI_CFGR1_PINCFG_MASK);
#endif

        /* Mark the hardware as busy. */
        State->Status = LPSPI_IP_BUSY;

        /* Update State structure. */
        /* For Dma Fast transfer, All transfers use the same HWUnit and in Master mode only.
        Some parameters such as Baudrate, Delays timming SpiTimeClk2Cs, SpiTimeCs2Clk, SpiTimeCs2Cs, SpiDataWidth, SpiTransferStart configuration
        must be the same between transfers. So, make sure they are configured the same in each External Device allocated for Dma Fast Transfers.
        And all those attributes can be got from first transfer in FastTransferCfg */
        State->ExternalDevice = FastTransferCfg[0u].ExternalDevice;
        State->Callback = EndCallback;
        Base->CFGR0 = State->ExternalDevice->Cfgr0;

        /* Disable module before configure CCR */
        Base->CR &= ~LPSPI_CR_MEN_MASK;
        /* Make sure that FIFOs will be empty before start new transfer session */
#ifdef ERR_IPV_LPSPIV2_E050456
        Lpspi_ErrataHandle(Base, State);
#else
        Lpspi_HardResetFifo(Base);
#endif
        /* clear all flags */
        Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;
#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
        Base->CCR = FastTransferCfg[0u].ExternalDevice->Ccr[State->ClockMode];
#else
        Base->CCR = FastTransferCfg[0u].ExternalDevice->Ccr;
#endif
        Base->CR |= LPSPI_CR_MEN_MASK;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_15();

        /* Disable all interrupts */
        Base->IER = 0u;
        /* Config and Enable DMA request. */
        Lpspi_Ip_DmaFastConfig(Instance, FastTransferCfg, NumberOfTransfer);
        Base->DER = LPSPI_DER_RDDE_MASK | LPSPI_DER_TDDE_MASK;
    }

    return Status;
}

/**
* @brief   This function will configure Scatter/Gather TCDs for the channels TX DMA, RX DMA and CMD DMA
*          according to Dma Fast transfers configuration. DMA channels will be started at the end of the function.
*/
static void Lpspi_Ip_DmaFastConfig(uint8 Instance,
                                   const Lpspi_Ip_FastTransferType *FastTransferCfg,
                                   uint8 NumberOfTransfer)
{
    Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    boolean ClearCS = FALSE;
    uint8 DisHwRequest = 0u;
    uint8 Count = 0u;
    uint8 TxDmaTCDSGIndex = 0u;
    uint32 TransferCommand = 0u;
    uint32 LSBBit = 0UL;
    uint32 ByteSwap = 0UL;
    boolean FirstCmd = TRUE;
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];

    DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    DmaTcdList[0u].Value = 1u;

    for (Count = 0u; Count < NumberOfTransfer; Count++)
    {
        /* Update State structure. */
        State->RxIndex = 0u;
        State->TxIndex = 0u;
        State->TxBuffer = FastTransferCfg[Count].TxBuffer;
        State->RxBuffer = FastTransferCfg[Count].RxBuffer;
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            State->ExpectedFifoWrites = FastTransferCfg[Count].Length;
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            State->ExpectedFifoWrites = FastTransferCfg[Count].Length / 2u;
        }
        else
        {
            State->ExpectedFifoWrites = FastTransferCfg[Count].Length / 4u;
        }

        State->ExpectedFifoReads = State->ExpectedFifoWrites;
        State->PhyUnitConfig->CmdDmaFast[Count].DefaultData = FastTransferCfg[Count].DefaultData;
        LSBBit = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
        ByteSwap = State->ExternalDevice->DeviceParams->ByteSwap ? 1UL : 0UL;

        /* Get transfer command */
#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
        TransferCommand = FastTransferCfg[Count].ExternalDevice->Tcr[State->ClockMode] | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(LSBBit) | LPSPI_TCR_BYSW(ByteSwap);
#else
        TransferCommand = FastTransferCfg[Count].ExternalDevice->Tcr | LPSPI_TCR_FRAMESZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) | LPSPI_TCR_LSBF(LSBBit) | LPSPI_TCR_BYSW(ByteSwap);
#endif

        if (0u != (TransferCommand & LPSPI_TCR_CONT_MASK))
        {
            if (TRUE == FirstCmd)
            {
                FirstCmd = FALSE;
                /* In continue CS, no need to set CONTC for first command */
                State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmd = TransferCommand;
            }
            else
            {
                /* In continue CS, need to set CONTC for next command */
                State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmd = TransferCommand | LPSPI_TCR_CONTC_MASK;
            }

            State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmdLast = TransferCommand & (~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK));
        }
        else
        {
            /* In non-continue CS, set DmaFastTcrCmd = DmaFastTcrCmdLast */
            State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmd = TransferCommand;
            State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmdLast = TransferCommand;
        }

        if (FALSE == FastTransferCfg[Count].KeepCs)
        {
            /* After CS is cleared, next transfer will be set as first command */
            FirstCmd = TRUE;
        }

        /* CS will be cleared for last transfer or depend on KeepCs if not last transfer.
        Disable DMA HW request at the end of transfer. */
        if (Count == (NumberOfTransfer - 1u))
        {
            ClearCS = TRUE;
            DisHwRequest = 1u;
        }
        else
        {
            if (FALSE == FastTransferCfg[Count].KeepCs)
            {
                ClearCS = TRUE;
            }
            else
            {
                ClearCS = FALSE;
            }

            DisHwRequest = 0u;
        }

        /* Configure software TCDs Scatter Gather for TX DMA channel to update TCR */
        /* No disable dma hw request for transfer command */
        Lpspi_Ip_CmdTxDmaTcdSGConfig(Instance, TxDmaTCDSGIndex, (uint32) & State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmd, 0u);
        TxDmaTCDSGIndex++;

        if ((TRUE == ClearCS) && (0u != (TransferCommand & LPSPI_TCR_CONT_MASK)))
        {
            /* Configure software TCDs Scatter Gather for TX DMA channel to fill TDR, no disable dma hw request */
            Lpspi_Ip_TxDmaTcdSGConfig(Instance, TxDmaTCDSGIndex, 0u, (const uint32 *)&State->PhyUnitConfig->CmdDmaFast[Count].DefaultData);
            TxDmaTCDSGIndex++;
            /* disable dma hw request for last transfer command */
            Lpspi_Ip_CmdTxDmaTcdSGConfig(Instance, TxDmaTCDSGIndex, (uint32) & State->PhyUnitConfig->CmdDmaFast[Count].DmaFastTcrCmdLast, DisHwRequest);
            TxDmaTCDSGIndex++;
        }
        else
        {
            /* Configure software TCDs Scatter Gather for TX DMA channel to fill TDR */
            Lpspi_Ip_TxDmaTcdSGConfig(Instance, TxDmaTCDSGIndex, DisHwRequest, (const uint32 *)&State->PhyUnitConfig->CmdDmaFast[Count].DefaultData);
            TxDmaTCDSGIndex++;
        }

        /* Configure software TCDs Scatter Gather for RX DMA channel */
        Lpspi_Ip_RxDmaTcdSGConfig(Instance, Count, DisHwRequest);
    }

    /* When all transfers session are completed and next TCD ScatterGather is loaded to HW. If next TCD ScatterGather loaded has INTMAJOR=0 then
    Dma_Ip interrupt function will not call Spi Dma notification due to it understood as spurious interrupt(Done flag = 1, INTMAJOR=0).
    So, the workaround is set INTMAJOR=1 for next TCD ScatterGather. */
    if (TxDmaTCDSGIndex < State->PhyUnitConfig->NumberTxSG)
    {
        /* Set INTMAJOR=1 for next TX TCD ScatterGather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TxDmaTCDSGIndex], DmaTcdList, 1u);
    }

    if (NumberOfTransfer < State->PhyUnitConfig->NumberRxSG)
    {
        /* Set INTMAJOR=1 for next RX TCD ScatterGather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[NumberOfTransfer], DmaTcdList, 1u);
    }

    /* Load first software TCD to hardware TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[0u]);
    /* Load first software TCD to hardware TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[0u]);

    /* Enable HW request for RX DMA channel before TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

#endif /*STD_ON == LPSPI_IP_DMA_USED*/
#endif /*STD_ON == LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT*/

void Lpspi_Ip_ManageBuffers(uint8 Instance)
{
    const LPSPI_Type* Base;
    const Lpspi_Ip_StateStructureType* State;
#if (LPSPI_IP_DMA_USED == STD_ON)
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
#endif

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
#endif
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    if (LPSPI_IP_POLLING == State->TransferMode)
    {
#if (LPSPI_IP_DMA_USED == STD_ON)
        if (FALSE == State->PhyUnitConfig->DmaUsed)
#endif
        {
            /* In half duplex master mode:
                - Transmit: TDF is set only, RDF will never be set by RX FIFO have masked.
                - Receive: Both TDF (push CDM) and DRF (receive data) are set.
               In half duplex Slave mode:
                - Transmit: TDF is set only, RDF will never be set by RX FIFO have masked.
                - Receive: Both TDF and RDF are set. But only process for RDF to receive data. In this case, State->CurrentTxFifoSlot will be set to 0 */
            if (
                (0u != (Base->SR & LPSPI_SR_RDF_MASK)) ||
                ((0u != (Base->SR & LPSPI_SR_TDF_MASK)) && (0u != State->CurrentTxFifoSlot))
               )
            {
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
                if (LPSPI_IP_FULL_DUPLEX != State->ExternalDevice->DeviceParams->TransferType)
                {
                    Lpspi_Ip_TransferProcessHalfDuplex(Instance);
                }
                else
#endif
                {
                    Lpspi_Ip_TransferProcess(Instance);
                }
            }
        }

#if (LPSPI_IP_DMA_USED == STD_ON)
        else
        {
            DmaChannelStatus.Done = FALSE;
            /* Polling RX before TX */
            (void)Dma_Ip_GetLogicChannelStatus(State->PhyUnitConfig->RxDmaChannel, &DmaChannelStatus);
            if (TRUE == DmaChannelStatus.Done)
            {
                /* Clear DONE bit */
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_DONE);
                Lpspi_Ip_IrqRxDmaHandler(Instance);
            }

            (void)Dma_Ip_GetLogicChannelStatus(State->PhyUnitConfig->TxDmaChannel, &DmaChannelStatus);
            if (TRUE == DmaChannelStatus.Done)
            {
                /* Clear DONE bit */
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_DONE);
                Lpspi_Ip_IrqTxDmaHandler(Instance);
            }
        }
#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
    }
}

/*================================================================================================*/
Lpspi_Ip_StatusType Lpspi_Ip_UpdateTransferParam(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                 const Lpspi_Ip_TransferAdjustmentType *Param)
{
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(NULL_PTR != Param);
    DevAssert(NULL_PTR != Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance]);
#endif

    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08();
    if (State->Status == LPSPI_IP_BUSY)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
        Status = LPSPI_IP_STATUS_FAIL;
    }
    else
    {
        State->KeepCs = Param->KeepCs;
        State->FirstCmd = Param->FirstCmd;
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
        State->NextChannelIsRX = !Param->NextHalfDuplexIsTX;
#endif
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
    }

    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateFrameSize(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                             uint16 FrameSize)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(LPSPI_IP_FRAMESIZE_MAX_U16 >= FrameSize);
    DevAssert(LPSPI_IP_FRAMESIZE_MIN_U16 <= FrameSize);
#endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    /* Frame size can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->FrameSize = FrameSize;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }

    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateLsb(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                       boolean Lsb)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
#endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->Lsb = Lsb;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }

    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateByteSwap(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                            boolean ByteSwap)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
#endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->ByteSwap = ByteSwap;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }

    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateDefaultTransmitData(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                       uint32 DefaultData)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
#endif
    State = Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->DefaultData = DefaultData;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }

    return Status;
}

Lpspi_Ip_StatusType Lpspi_Ip_UpdateTransferMode(uint8 Instance,
                                                Lpspi_Ip_ModeType Mode)
{
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;
#if (LPSPI_IP_DMA_USED == STD_ON)
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
#endif

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
#endif
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    /* Transfer mode can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        State->TransferMode = Mode;
#if (LPSPI_IP_DMA_USED == STD_ON)
        if (TRUE == State->PhyUnitConfig->DmaUsed)
        {
            /* Activate TX DMA and RX DMA interrupt in interrupt mode or disable then in polling mode. */
            DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
            switch (State->TransferMode)
            {
                case LPSPI_IP_POLLING:
                    /* Disable DMA major interrupt. */
                    DmaTcdList[0u].Value = 0u;
                break;
                case LPSPI_IP_INTERRUPT:
                    /* Enable DMA major interrupt. */
                    DmaTcdList[0u].Value = 1u;
                break;
                default:
                    /* Nothing to do */
                break;
            }

            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);
            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);
        }

#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }

    return Status;
}

void Lpspi_Ip_Cancel(uint8 Instance)
{
    LPSPI_Type* Base;
    Lpspi_Ip_StateStructureType* State;
    uint32 Cfgr0 = 0u;
    uint32 Cfgr1 = 0u;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
#endif
    Base = Lpspi_Ip_apxBases[Instance];
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_10();
    if (LPSPI_IP_BUSY == State->Status)
    {
        /* Disable module to stop transfer */
        Base->CR &= ~LPSPI_CR_MEN_MASK;
        /* Store CFGR0 and CFGR1 and restore after all registers are reset */
        Cfgr0 = Base->CFGR0;
        Cfgr1 = Base->CFGR1;
        /* Disable interrupts and DMA requests. */
        /* Clear FIFO */
        /* RTF and RRF will not clear shifter, so RST must be used to ensure old Data in shifter will also be cleared. */
        Base->CR |= LPSPI_CR_RST_MASK;
        Base->CR &= ~LPSPI_CR_RST_MASK;
#ifdef ERR_IPV_LPSPIV2_E050456
#ifdef ERR_IPV_LPSPIV2_E050456_2ND_SOLUTION
        State->TxFifoResetNeeded = FALSE;
#endif
#endif
        /* restore CFGR0 and CFGR1 */
        Base->CFGR0 = Cfgr0;
        Base->CFGR1 = Cfgr1;
#if (LPSPI_IP_DMA_USED == STD_ON)
        if (TRUE == State->PhyUnitConfig->DmaUsed)
        {
            /* Disable all HW request */
            (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            /* Reset value for some channel TCD status. These variables will be updated in time of configuring TX/RX DMA for each channel to save
             * current attributes of that channel */
            State->IsPreTxBufferNull = FALSE;
            State->IsPreRxBufferNull = FALSE;
            State->PreTxMajorLoopCount = 0u;
            State->PreRxMajorLoopCount = 0u;
        }

#endif /* if (LPSPI_IP_DMA_USED == STD_ON) */
        /* set State to idle */
        State->Status = LPSPI_IP_IDLE;
    }

    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_10();
}

/**
* @brief   This function is called by LSPI ISRs.
* @details This function will process activities for flags TDF, RDF, REF and TEF.
*
* @param[in]     Instance            Instance of the hardware unit.
*
* @implements Lpspi_Ip_IrqHandler_Activity
*/
void Lpspi_Ip_IrqHandler(uint8 Instance)
{
    LPSPI_Type* Base = Lpspi_Ip_apxBases[Instance];
    const Lpspi_Ip_StateStructureType* State = Lpspi_Ip_apxStateStructureArray[Instance];
    uint32 IrqFlags = 0u;

    if (NULL_PTR != State)
    {
        /* the driver has been initialized */
        IrqFlags = Base->SR & (LPSPI_SR_TDF_MASK | LPSPI_SR_RDF_MASK | LPSPI_SR_TEF_MASK | LPSPI_SR_REF_MASK);
        IrqFlags &= Base->IER & (LPSPI_IER_TDIE_MASK | LPSPI_IER_RDIE_MASK | LPSPI_IER_TEIE_MASK | LPSPI_IER_REIE_MASK);
        if (0u != IrqFlags)
        {
#if (LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT == STD_ON)
            if (
                (LPSPI_IP_HALF_DUPLEX_TRANSMIT == State->ExternalDevice->DeviceParams->TransferType) ||
                (LPSPI_IP_HALF_DUPLEX_RECEIVE == State->ExternalDevice->DeviceParams->TransferType)
               )
            {
                Lpspi_Ip_TransferProcessHalfDuplex(Instance);
            }
            else
#endif
            {
                Lpspi_Ip_TransferProcess(Instance);
            }
        }
        else
        {
            /* Do nothing - Return immediately */
        }
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags */
        Base->SR &= LPSPI_IP_SR_W1C_MASK_U32;
    }
}

/**
* @brief            Get status of HW unit.
* @details          This function returns the status of the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           Lpspi_Ip_HwStatusType
*/
Lpspi_Ip_HwStatusType Lpspi_Ip_GetStatus(uint8 Instance)
{
    const Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_HwStatusType Status = LPSPI_IP_UNINIT;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
#endif
    State = Lpspi_Ip_apxStateStructureArray[Instance];
    if (State != NULL_PTR)
    {
        Status = State->Status;
    }

    return Status;
}

#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
Lpspi_Ip_StatusType Lpspi_Ip_SetClockMode(uint8 Instance,
                                          Lpspi_Ip_DualClockModeType ClockMode)
{
    Lpspi_Ip_StateStructureType* State;
    Lpspi_Ip_StatusType Status = LPSPI_IP_STATUS_SUCCESS;

#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < LPSPI_INSTANCE_COUNT);
#endif
    State = Lpspi_Ip_apxStateStructureArray[Instance];
#if (LPSPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
#endif
    /* Clock mode can be changed when no transfers are in progress. */
    if (State->Status != LPSPI_IP_BUSY)
    {
        State->ClockMode = ClockMode;
    }
    else
    {
        Status = LPSPI_IP_STATUS_FAIL;
    }

    return Status;
}

#endif /* if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
