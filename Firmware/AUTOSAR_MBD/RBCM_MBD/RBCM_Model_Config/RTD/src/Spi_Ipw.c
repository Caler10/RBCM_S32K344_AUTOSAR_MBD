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
*   @file    Spi_Ipw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Isolation level file for SPI driver.
*   @details Implementation file for function definition on isolation level between high and low level driver.
*
*   @addtogroup SPI_DRIVER Spi Driver
*   @{
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
#include "Spi_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID_C                       43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION_C        4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION_C        7
#define SPI_IPW_AR_RELEASE_REVISION_VERSION_C     0
#define SPI_IPW_SW_MAJOR_VERSION_C                5
#define SPI_IPW_SW_MINOR_VERSION_C                0
#define SPI_IPW_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw.c and Spi_Ipw.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi_Ipw.c and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi_Ipw.c file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw.c and Spi_Ipw.h are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw.c and Spi_Ipw.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#define   SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief Mapping between Lpspi channel id and instance id
*/
static Spi_HWUnitType Spi_Ipw_au8LpspiHWUnitMapping[LPSPI_INSTANCE_COUNT];
static Spi_CallbackType Spi_Ipw_LpspiCallbacks[LPSPI_INSTANCE_COUNT];

#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
/**
* @brief Mapping between Flexio channel id and hardware unit id
*/
static Spi_HWUnitType Spi_Ipw_au8FlexioHWUnitMapping[FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8];
static Spi_CallbackType Spi_Ipw_FlexioCallbacks[FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8];
#endif

#if (SPI_IPW_DSPI_ENABLE == STD_ON)
/**
* @brief Mapping between Dspi channel id and hardware unit id
*/
static Spi_HWUnitType Spi_Ipw_au8DspiHWUnitMapping[DSPI_INSTANCE_COUNT];
static Spi_CallbackType Spi_Ipw_DspiCallbacks[DSPI_INSTANCE_COUNT];
#endif
#endif

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_Ipw_CallbackLpspi(uint8 Instance,
                                  Lpspi_Ip_EventType Event);

#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
static void Spi_Ipw_CallbackFlexio(uint8 Instance,
                                   Flexio_Spi_Ip_EventType Event);

#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
static void Spi_Ipw_CallbackDspi(uint8 Instance,
                                 Dspi_Ip_EventType Event);

#endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Spi_Ipw_Init */
void Spi_Ipw_Init(const Spi_HWUnitType HWUnitId,
                  const Spi_HWUnitConfigType *HWUnit)
{
    #if (SPI_LEVEL_DELIVERED != SPI_LEVEL1) && (SPI_LEVEL_DELIVERED != SPI_LEVEL2)
    (void)HWUnitId;
    #endif
    if (SPI_OVER_LPSPI == HWUnit->IpType)
    {
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        Spi_Ipw_au8LpspiHWUnitMapping[HWUnit->Instance] = HWUnitId;
    #endif
        (void)Lpspi_Ip_Init(HWUnit->IpConfig.LpspiIpConfig);
    }

#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == HWUnit->IpType)
    {
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        Spi_Ipw_au8FlexioHWUnitMapping[HWUnit->Instance] = HWUnitId;
    #endif
        (void)Flexio_Spi_Ip_Init(HWUnit->IpConfig.FlexioSpiIpConfig);
    }
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else if (SPI_OVER_DSPI == HWUnit->IpType)
    {
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
        Spi_Ipw_au8DspiHWUnitMapping[HWUnit->Instance] = HWUnitId;
    #endif
        (void)Dspi_Ip_Init(HWUnit->IpConfig.DspiIpConfig);
    }
#endif
    else
    {
        /* Do nothing */
    }
}

/* Spi_Ipw_DeInit */
void Spi_Ipw_DeInit(const Spi_HWUnitConfigType * PhyUnitConfig)
{
    if (SPI_OVER_LPSPI == PhyUnitConfig->IpType)
    {
        (void)Lpspi_Ip_DeInit(PhyUnitConfig->Instance);
    }

#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == PhyUnitConfig->IpType)
    {
        (void)Flexio_Spi_Ip_DeInit(PhyUnitConfig->Instance);
    }
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else if (SPI_OVER_DSPI == PhyUnitConfig->IpType)
    {
        (void)Dspi_Ip_DeInit(PhyUnitConfig->Instance);
    }
#endif
    else
    {
        /* Do nothing */
    }
}

/* Spi_Ipw_SyncTransmit */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
Std_ReturnType Spi_Ipw_SyncTransmit(const Spi_ExternalDeviceConfigType *ExDeviceConfig,
                                    const uint8 *TxBuffer,
                                    uint8 *RxBuffer,
                                    uint16 NumberOfBytes,
                                    const Spi_Ipw_ParamSyncTransmit *Param)
{
    Lpspi_Ip_StatusType Lpspi_spiStatus = LPSPI_IP_STATUS_SUCCESS;
    const Lpspi_Ip_ExternalDeviceType* LpspiExternalDevice;
    Lpspi_Ip_TransferAdjustmentType LpspiAdjustmentParam;
    const Spi_ChannelConfigType *ChannelConfig = Param->ChannelConfig;

#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    Flexio_Spi_Ip_StatusType Flexio_spiStatus = FLEXIO_SPI_IP_STATUS_SUCCESS;
    const Flexio_Spi_Ip_ExternalDeviceType* Flexio_SpiExternalDevice;
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    Dspi_Ip_StatusType Spi_DspiStatus = DSPI_IP_STATUS_SUCCESS;
    const Dspi_Ip_ExternalDeviceType* Dspi_SpiExternalDevice;
    Dspi_Ip_TransferAdjustmentType DspiAdjustmentParam;
#endif
    Std_ReturnType Ipw_Status = (Std_ReturnType)E_OK;
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
    Lpspi_Ip_HalfDuplexType HalfDuplexMode;
    boolean HalfDuplexModeSupport = TRUE;
    Spi_DataBufferType *Buffer;

    if (SPI_HALF_DUPLEX_TRANSMIT == ChannelConfig->HalfDuplexMode)
    {
        HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_TRANSMIT;
        Buffer = (uint8*)TxBuffer;
    }
    else if (SPI_HALF_DUPLEX_RECEIVE == ChannelConfig->HalfDuplexMode)
    {
        HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_RECEIVE;
        Buffer = RxBuffer;
    }
    else
    {
        HalfDuplexMode = LPSPI_IP_FULL_DUPLEX;
        HalfDuplexModeSupport = FALSE;
    }
#endif


    if (SPI_OVER_LPSPI == ExDeviceConfig->IpType)
    {
        
        LpspiAdjustmentParam.KeepCs = Param->KeepCs;
        LpspiAdjustmentParam.FirstCmd = Param->FirstCmd;
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
        /* Get mode of next channel */
        if ((NULL_PTR != Param->NextChannelConfig) &&
            (SPI_HALF_DUPLEX_RECEIVE == Param->NextChannelConfig->HalfDuplexMode))
        {
            LpspiAdjustmentParam.NextHalfDuplexIsTX = FALSE;
        }
        else
        {
            LpspiAdjustmentParam.NextHalfDuplexIsTX = TRUE;
        }
#endif
    }
    else
    {
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
        if (SPI_OVER_DSPI == ExDeviceConfig->IpType)
        {
            DspiAdjustmentParam.KeepCs = Param->KeepCs;
        }
#endif
    }
    if (SPI_OVER_LPSPI == ExDeviceConfig->IpType)
    {
        LpspiExternalDevice = ExDeviceConfig->ExternalDeviceConfig.LpspiExternalDeviceConfig;
        LpspiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        LpspiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        LpspiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        LpspiExternalDevice->DeviceParams->ByteSwap = ChannelConfig->ByteSwap;
        /* TODO handle return of update transfer */
        (void)Lpspi_Ip_UpdateTransferParam(LpspiExternalDevice, &LpspiAdjustmentParam);
        #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
        if (HalfDuplexModeSupport)
        {
            Lpspi_spiStatus = Lpspi_Ip_SyncTransmitHalfDuplex(LpspiExternalDevice, Buffer, NumberOfBytes, HalfDuplexMode, SPI_TIMEOUT_COUNTER_U32);
        }
        else
        #endif
        {
            Lpspi_spiStatus = Lpspi_Ip_SyncTransmit(LpspiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, SPI_TIMEOUT_COUNTER_U32);
        }
        if (LPSPI_IP_STATUS_SUCCESS != Lpspi_spiStatus)
        {
            Ipw_Status = (Std_ReturnType)E_NOT_OK;
        }
    }
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == ExDeviceConfig->IpType)
    {
        Flexio_SpiExternalDevice = ExDeviceConfig->ExternalDeviceConfig.Flexio_SpiExternalDeviceConfig;
        Flexio_SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        Flexio_SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        Flexio_SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        Flexio_spiStatus = Flexio_Spi_Ip_SyncTransmit(Flexio_SpiExternalDevice, (const uint8*)TxBuffer, RxBuffer, NumberOfBytes, SPI_TIMEOUT_COUNTER_U32);
        if (FLEXIO_SPI_IP_STATUS_SUCCESS != Flexio_spiStatus)
        {
            Ipw_Status = (Std_ReturnType)E_NOT_OK;
        }
    }
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else if (SPI_OVER_DSPI == ExDeviceConfig->IpType)
    {
        Dspi_SpiExternalDevice = ExDeviceConfig->ExternalDeviceConfig.DspiExternalDeviceConfig;
        Dspi_SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        Dspi_SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        Dspi_SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        DspiAdjustmentParam.DeviceParams = NULL_PTR;
        /* TODO handle return of update transfer */
        (void)Dspi_Ip_UpdateTransferParam(Dspi_SpiExternalDevice, &DspiAdjustmentParam);
        Spi_DspiStatus = Dspi_Ip_SyncTransmit(Dspi_SpiExternalDevice, TxBuffer, RxBuffer, NumberOfBytes, SPI_TIMEOUT_COUNTER_U32);
        if (DSPI_IP_STATUS_SUCCESS != Spi_DspiStatus)
        {
            Ipw_Status = (Std_ReturnType)E_NOT_OK;
        }
    }
#endif
    else
    {
        Ipw_Status = E_NOT_OK;
    }

    return Ipw_Status;
}
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0)) */


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_IrqPoll */
void Spi_Ipw_IrqPoll(const Spi_HWUnitConfigType * PhyUnitConfig)
{
    if (SPI_OVER_LPSPI == PhyUnitConfig->IpType)
    {
        Lpspi_Ip_ManageBuffers(PhyUnitConfig->Instance);
    }
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == PhyUnitConfig->IpType)
    {
        Flexio_Spi_Ip_ManageBuffers(PhyUnitConfig->Instance);
    }
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else if (SPI_OVER_DSPI == PhyUnitConfig->IpType)
    {
        Dspi_Ip_ManageBuffers(PhyUnitConfig->Instance);
    }
#endif
    else
    {
        /* Do nothing */
    }
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_IrqConfig */
void Spi_Ipw_IrqConfig(const Spi_HWUnitConfigType * PhyUnitConfig,
                       Spi_AsyncModeType Mode,
                       Spi_CallbackType Callback)
{
    Lpspi_Ip_StatusType Lpspi_Ip_Status = LPSPI_IP_STATUS_SUCCESS;
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    Dspi_Ip_StatusType Dspi_Ip_Status = DSPI_IP_STATUS_SUCCESS;
#endif

    if (SPI_OVER_LPSPI == PhyUnitConfig->IpType)
    {
        Spi_Ipw_LpspiCallbacks[PhyUnitConfig->Instance] = Callback;
        if (SPI_POLLING_MODE == Mode)
        {
            Lpspi_Ip_Status = Lpspi_Ip_UpdateTransferMode(PhyUnitConfig->Instance, LPSPI_IP_POLLING);
        }
        else
        {
            Lpspi_Ip_Status = Lpspi_Ip_UpdateTransferMode(PhyUnitConfig->Instance, LPSPI_IP_INTERRUPT);
        }
        /* HLD do not require return value. This code to avoid misra violation */
        (void) Lpspi_Ip_Status;
    }
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == PhyUnitConfig->IpType)
    {
        Spi_Ipw_FlexioCallbacks[PhyUnitConfig->Instance] = Callback;
        if (SPI_POLLING_MODE == Mode)
        {
            Flexio_Spi_Ip_Status = Flexio_Spi_Ip_UpdateTransferMode(PhyUnitConfig->Instance, FLEXIO_SPI_IP_POLLING);
        }
        else
        {
            Flexio_Spi_Ip_Status = Flexio_Spi_Ip_UpdateTransferMode(PhyUnitConfig->Instance, FLEXIO_SPI_IP_INTERRUPT);
        }
        (void) Flexio_Spi_Ip_Status;
    }
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else if (SPI_OVER_DSPI == PhyUnitConfig->IpType)
    {
        Spi_Ipw_DspiCallbacks[PhyUnitConfig->Instance] = Callback;
        if (SPI_POLLING_MODE == Mode)
        {
            Dspi_Ip_Status = Dspi_Ip_UpdateTransferMode(PhyUnitConfig->Instance, DSPI_IP_POLLING);
        }
        else
        {
            Dspi_Ip_Status = Dspi_Ip_UpdateTransferMode(PhyUnitConfig->Instance, DSPI_IP_INTERRUPT);
        }
        (void) Dspi_Ip_Status;
    }
#endif
    else
    {
        /* Do nothing */
    }
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))

/* LPSPI end of channel callback. */
static void Spi_Ipw_CallbackLpspi(uint8 Instance,
                                  Lpspi_Ip_EventType Event)
{
    Spi_HWUnitType HwUnit = Spi_Ipw_au8LpspiHWUnitMapping[Instance];
    if (Event != LPSPI_IP_EVENT_END_TRANSFER)
    {
        Spi_Ipw_LpspiCallbacks[Instance](HwUnit, SPI_JOB_FAILED);
    }
    else
    {
        Spi_Ipw_LpspiCallbacks[Instance](HwUnit, SPI_JOB_OK);
    }
}

#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
/* FLEXIO_SPI end of channel callback. */
static void Spi_Ipw_CallbackFlexio(uint8 Instance,
                                   Flexio_Spi_Ip_EventType Event)
{
    Spi_HWUnitType HwUnit = Spi_Ipw_au8FlexioHWUnitMapping[Instance];
    if (Event != FLEXIO_SPI_IP_EVENT_END_TRANSFER)
    {
        Spi_Ipw_FlexioCallbacks[Instance](HwUnit, SPI_JOB_FAILED);
    }
    else
    {
        Spi_Ipw_FlexioCallbacks[Instance](HwUnit, SPI_JOB_OK);
    }
}
#endif

#if (SPI_IPW_DSPI_ENABLE == STD_ON)
/* DSPI end of channel callback. */
static void Spi_Ipw_CallbackDspi(uint8 Instance,
                                 Dspi_Ip_EventType Event)
{
    Spi_HWUnitType HwUnit = Spi_Ipw_au8DspiHWUnitMapping[Instance];
    if (Event != DSPI_IP_EVENT_END_TRANSFER)
    {
        Spi_Ipw_DspiCallbacks[Instance](HwUnit, SPI_JOB_FAILED);
    }
    else
    {
        Spi_Ipw_DspiCallbacks[Instance](HwUnit, SPI_JOB_OK);
    }
}
#endif

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
void Spi_Ipw_PrepareDMAFastTransferCfg(const Spi_HWUnitConfigType *PhyUnitConfig,
                                       const Spi_ChannelConfigType *ChannelConfig,
                                       const Spi_Ipw_ExternalDeviceType *ExternalDeviceConfig,
                                       uint8 TransferCount,
                                       const Spi_Ipw_ParamDMAFAst *Param)
{
    Lpspi_Ip_FastTransferType *LpspiDmaFastTransferCfg = PhyUnitConfig->IpConfig.LpspiFastTransferCfg;
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    Dspi_Ip_FastTransferType *DspiDmaFastTransferCfg = PhyUnitConfig->IpConfig.DspiFastTransferCfg;
#endif
    if (SPI_OVER_LPSPI == PhyUnitConfig->IpType)
    {
        LpspiDmaFastTransferCfg[TransferCount].Length = Param->Length;
        LpspiDmaFastTransferCfg[TransferCount].RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if (0u != (Param->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            LpspiDmaFastTransferCfg[TransferCount].TxBuffer = NULL_PTR;
        }
        else
        {
            if (EB == ChannelConfig->BufferType)
            {
                LpspiDmaFastTransferCfg[TransferCount].TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                LpspiDmaFastTransferCfg[TransferCount].TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
            }
        }

        LpspiDmaFastTransferCfg[TransferCount].ExternalDevice = ExternalDeviceConfig->LpspiExternalDeviceConfig;
        LpspiDmaFastTransferCfg[TransferCount].KeepCs = Param->KeepCs;
        /* For Dma Fast transfer, All transfers use the same HWUnit and in Master Mode only.
        Some parameters such as Baudrate, Delays timming SpiTimeClk2Cs, SpiTimeCs2Clk, SpiTimeCs2Cs, SpiDataWidth, SpiTransferStart configuration
        must be the same between transfers. So, make sure they are configured the same in each External Device allocated to Jobs for Dma Fast Transfers. */
        /* update default data */
        LpspiDmaFastTransferCfg[TransferCount].DefaultData = ChannelConfig->DefaultTransmitValue;
        (void)Lpspi_Ip_UpdateFrameSize(LpspiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->FrameSize);
        (void)Lpspi_Ip_UpdateLsb(LpspiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->Lsb);
        (void)Lpspi_Ip_UpdateByteSwap(LpspiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->ByteSwap);
    }
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else
    {
        DspiDmaFastTransferCfg[TransferCount].Length = Param->Length;
        DspiDmaFastTransferCfg[TransferCount].RxBuffer = ChannelConfig->BufferDescriptor->BufferRX;
        if (0u != (Param->Flags & SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            DspiDmaFastTransferCfg[TransferCount].TxBuffer = NULL_PTR;
        }
        else
        {
            if (EB == ChannelConfig->BufferType)
            {
                DspiDmaFastTransferCfg[TransferCount].TxBuffer = ChannelConfig->BufferDescriptor->ExternalBufferTX;
            }
            else
            {
                DspiDmaFastTransferCfg[TransferCount].TxBuffer = (const uint8*)(ChannelConfig->BufferDescriptor->InternalBufferTX);
            }
        }
        DspiDmaFastTransferCfg[TransferCount].ExternalDevice = ExternalDeviceConfig->DspiExternalDeviceConfig;
        DspiDmaFastTransferCfg[TransferCount].KeepCs = Param->KeepCs;
        /* For Dma Fast transfer, All transfers use the same HWUnit and in Master Mode only. Only some parameters can be changed as Continuous CS, PCS.
        Some parameters such as Baudrate, Clock Polarity, Clock Phase, Delays timing configuration, Bit Order, Frame Size
        must be the same between transfers. So, make sure they are configured the same in each External Device, Channel allocated to Jobs for Dma Fast Transfers. */
        /* update default data */
        DspiDmaFastTransferCfg[TransferCount].DefaultData = ChannelConfig->DefaultTransmitValue;
        (void)Dspi_Ip_UpdateFrameSize(DspiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->FrameSize);
        (void)Dspi_Ip_UpdateLsb(DspiDmaFastTransferCfg[TransferCount].ExternalDevice, ChannelConfig->Lsb);
    }
#endif
}

void Spi_Ipw_DMAFastTransferStart(const Spi_HWUnitConfigType *PhyUnitConfig,
                                  uint8 TransferCount)
{
    const Lpspi_Ip_FastTransferType *LpspiDmaFastTransferCfg = PhyUnitConfig->IpConfig.LpspiFastTransferCfg;
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    Dspi_Ip_FastTransferType *DspiDmaFastTransferCfg = PhyUnitConfig->IpConfig.DspiFastTransferCfg;
#endif

    /* Because of all Channels and all Jobs are transferred successfully when Spi_Ipw_CallbackLpspi called.
    So, remaining of Channels in current Job must set to 0, this will lead to Spi_JobTransferFinished() called when Spi_Ipw_CallbackLpspi called.
    And Spi_JobTransferFinished() will set remaining of Job to 0 and set all Jobs result to SPI_JOB_OK, unlock all Jobs for this Dma Fast Sequence. */
    if (SPI_OVER_LPSPI == PhyUnitConfig->IpType)
    {
        (void)Lpspi_Ip_AsyncTransmitFast(LpspiDmaFastTransferCfg, TransferCount, &Spi_Ipw_CallbackLpspi);
    }
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else
    {
        (void)Dspi_Ip_AsyncTransmitFast(DspiDmaFastTransferCfg, TransferCount, &Spi_Ipw_CallbackDspi);
    }
#endif
}
#endif

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
Std_ReturnType Spi_Ipw_SequenceDmaContMemTransfer(const Spi_SequenceConfigType *SequenceConfig,
                                                  const Spi_Ipw_ExternalDeviceType *ExternalDeviceConfig,
                                                  uint8 *FirstRxBufferAddr,
                                                  uint8 TransferCount)
{
    Std_ReturnType Ret = E_OK;
    Lpspi_Ip_StatusType Status;
    Lpspi_Ip_TxBufferListType* SeqTxBufferList = SequenceConfig->DmaContTransferState;
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice = ExternalDeviceConfig->LpspiExternalDeviceConfig;

    /* Update TxBufferList parameters */
    SeqTxBufferList->CurrentChannelIndex = 0;
    SeqTxBufferList->CurrentJobIndex = 0;
    SeqTxBufferList->TotalNumberOfChannel = TransferCount;
    Status = Lpspi_Ip_DmaContMemAsyncTransmit(ExternalDevice, SeqTxBufferList, FirstRxBufferAddr, &Spi_Ipw_CallbackLpspi);
    if (LPSPI_IP_STATUS_SUCCESS != Status)
    {
        Ret = E_NOT_OK;
    }
    
    return Ret;
}

Std_ReturnType Spi_Ipw_SequenceDmaContMemPrepare(const Spi_ChannelConfigType *ChannelConfig,
                                                 uint16 NumChannelsInJob,
                                                 uint16 Length,
                                                 uint8 *TransferCount,
                                                 const Spi_Ipw_ParamDMACont *Param)
{
    Std_ReturnType Ret = E_OK;
    Lpspi_Ip_TxBufferListType* SeqTxBufferList = Param->SequenceConfig->DmaContTransferState;
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice;
    Spi_Ipw_uintPtrType RxBufferAddr = 0u;

#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    if (TRUE == Param->PhyUnitConfig->IpConfig.LpspiIpConfig->SlaveMode)
    {
        Ret = E_NOT_OK;
    }
    else
    {
#endif
        /* Handle Jobs loop */
        if (Param->ChannelIndex == 0u)
        {
            if (Param->IsFirstJob)
            {
                SeqTxBufferList->TotalNumberOfTransfer = 0U;
                SeqTxBufferList->CurrentJobIndex = 0U;
            }

            SeqTxBufferList->ChannelNumsByJob[SeqTxBufferList->CurrentJobIndex] = NumChannelsInJob;
        }
        else if (Param->ChannelIndex == (NumChannelsInJob - 1u))
        {
            /* Last channel in job */
            SeqTxBufferList->CurrentJobIndex++;
        }
        else
        {
            /* Do nothing */
        }

        /* Handle channel loop */
        if (EB == ChannelConfig->BufferType)
        {
            ExternalDevice = Param->ExternalDeviceConfig->LpspiExternalDeviceConfig;
            RxBufferAddr = (Spi_Ipw_uintPtrType)ChannelConfig->BufferDescriptor->BufferRX;
            if (Param->IsFirstJob && (0U == Param->ChannelIndex))
            {
                *(Param->FirstRxBufferAddr) = ChannelConfig->BufferDescriptor->BufferRX;
                *(Param->ComparedRxBufferAddr) = RxBufferAddr;
                ExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
                ExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
                ExternalDevice->DeviceParams->ByteSwap = ChannelConfig->ByteSwap;
            }
            else
            {
                if ((*(Param->ComparedRxBufferAddr) != RxBufferAddr) ||
                    (ExternalDevice != Param->FirstExternalDeviceConfig->LpspiExternalDeviceConfig) ||
                    (ExternalDevice->DeviceParams->FrameSize != ChannelConfig->FrameSize) ||
                    (ExternalDevice->DeviceParams->Lsb != ChannelConfig->Lsb) ||
                    (ExternalDevice->DeviceParams->ByteSwap != ChannelConfig->ByteSwap))
                {
                    Ret = E_NOT_OK;
                }
            }

            if (E_OK == Ret)
            {
                /* Get address for next Rx buffer */
                RxBufferAddr += Length;
                *(Param->ComparedRxBufferAddr) = RxBufferAddr;
                SeqTxBufferList->TxBuffer[*TransferCount] = ChannelConfig->BufferDescriptor->ExternalBufferTX;
                SeqTxBufferList->TransferNumsByChannel[*TransferCount] = Length;
                SeqTxBufferList->TotalNumberOfTransfer += Length;
                /* update default data */
                (*TransferCount)++;
            }
        }
        else
        {
            Ret = E_NOT_OK;
        }
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    }
#endif

    return Ret;
}
#endif /* if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)) */

void Spi_Ipw_AsyncTransfer(const Spi_ExternalDeviceConfigType *ExDeviceConfig,
                           const uint8 *TxBuffer,
                           uint8 *RxBuffer,
                           uint16 NumberOfBytes,
                           const Spi_Ipw_ParamAsyncTransmit *Param)
{
    const Spi_ChannelConfigType *ChannelConfig = Param->ChannelConfig;
    Lpspi_Ip_TransferAdjustmentType LpspiAdjustmentParam;
    const Lpspi_Ip_ExternalDeviceType *LpspiExternalDevice;
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    const Flexio_Spi_Ip_ExternalDeviceType *Flexio_SpiExternalDevice;
    Flexio_Spi_Ip_TransferAdjustmentType Flexio_SpiAdjustmentParam;
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    const Dspi_Ip_ExternalDeviceType *Dspi_SpiExternalDevice;
    Dspi_Ip_TransferAdjustmentType DspiAdjustmentParam;
#endif

#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
    Lpspi_Ip_HalfDuplexType HalfDuplexMode;
    boolean HalfDuplexModeSupport = TRUE;
    uint8 *Buffer;

    if (SPI_HALF_DUPLEX_TRANSMIT == ChannelConfig->HalfDuplexMode)
    {
        HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_TRANSMIT;
        Buffer = (uint8*)TxBuffer;
    }
    else if (SPI_HALF_DUPLEX_RECEIVE == ChannelConfig->HalfDuplexMode)
    {
        HalfDuplexMode = LPSPI_IP_HALF_DUPLEX_RECEIVE;
        Buffer = RxBuffer;
    }
    else
    {
        HalfDuplexMode = LPSPI_IP_FULL_DUPLEX;
        HalfDuplexModeSupport = FALSE;
    }
#endif
    if (SPI_OVER_LPSPI == ExDeviceConfig->IpType)
    {
        LpspiAdjustmentParam.KeepCs = Param->KeepCs;
        LpspiAdjustmentParam.FirstCmd = Param->FirstCmd;
#if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
        /* Get mode of next channel */
        if (Param->KeepCs && (NULL_PTR != Param->NextChannelConfig) &&
            (SPI_HALF_DUPLEX_TRANSMIT == Param->NextChannelConfig->HalfDuplexMode))
        {
            LpspiAdjustmentParam.NextHalfDuplexIsTX = TRUE;
        }
        else
        {
            LpspiAdjustmentParam.NextHalfDuplexIsTX = FALSE;
        }
#endif
        LpspiExternalDevice = ExDeviceConfig->ExternalDeviceConfig.LpspiExternalDeviceConfig;
        /* update default data, Lsb, Framesize */
        LpspiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        LpspiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        LpspiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        LpspiExternalDevice->DeviceParams->ByteSwap = ChannelConfig->ByteSwap;
        (void)Lpspi_Ip_UpdateTransferParam(LpspiExternalDevice, &LpspiAdjustmentParam);
        #if (STD_ON == SPI_IPW_SPI_HALF_DUPLEX_MODE_SUPPORT)
        if (HalfDuplexModeSupport)
        {
            (void)Lpspi_Ip_AsyncTransmitHalfDuplex(LpspiExternalDevice, Buffer, NumberOfBytes,
                                                    HalfDuplexMode, &Spi_Ipw_CallbackLpspi);
        }
        else
        #endif
        {
            (void)Lpspi_Ip_AsyncTransmit(LpspiExternalDevice, TxBuffer, RxBuffer,
                                            NumberOfBytes, &Spi_Ipw_CallbackLpspi);
        }
    }
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == ExDeviceConfig->IpType)
    {
        /* Mark for the first channel */
        Flexio_SpiAdjustmentParam.FirstTransfer = TRUE;
        /* update default data, Lsb, Framesize */
        Flexio_SpiExternalDevice = ExDeviceConfig->ExternalDeviceConfig.Flexio_SpiExternalDeviceConfig;
        Flexio_SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        Flexio_SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        Flexio_SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        (void)Flexio_Spi_Ip_UpdateTransferParam(Flexio_SpiExternalDevice, &Flexio_SpiAdjustmentParam);
        (void)Flexio_Spi_Ip_AsyncTransmit(Flexio_SpiExternalDevice, TxBuffer, RxBuffer, 
                                          NumberOfBytes, &Spi_Ipw_CallbackFlexio);
    }
#endif /*(SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)*/
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else if (SPI_OVER_DSPI == ExDeviceConfig->IpType)
    {
        DspiAdjustmentParam.KeepCs = Param->KeepCs;
        /* update default data, Lsb, Framesize */
        Dspi_SpiExternalDevice = ExDeviceConfig->ExternalDeviceConfig.DspiExternalDeviceConfig;
        Dspi_SpiExternalDevice->DeviceParams->DefaultData = ChannelConfig->DefaultTransmitValue;
        Dspi_SpiExternalDevice->DeviceParams->FrameSize = ChannelConfig->FrameSize;
        Dspi_SpiExternalDevice->DeviceParams->Lsb = ChannelConfig->Lsb;
        DspiAdjustmentParam.DeviceParams = NULL_PTR;
        (void)Dspi_Ip_UpdateTransferParam(Dspi_SpiExternalDevice, &DspiAdjustmentParam);
        (void)Dspi_Ip_AsyncTransmit(Dspi_SpiExternalDevice, TxBuffer, RxBuffer,
                                    NumberOfBytes, &Spi_Ipw_CallbackDspi);
    }
#endif /*(SPI_IPW_DSPI_ENABLE == STD_ON)*/
    else
    {
        /* Do nothing */
    }
}
#endif

#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/* Spi_Ipw_SlaveCancel */
Std_ReturnType Spi_Ipw_SlaveCancel(const Spi_HWUnitConfigType *PhyUnitConfig)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    if (SPI_OVER_LPSPI == PhyUnitConfig->IpType)
    {
#if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
        if (TRUE == PhyUnitConfig->IpConfig.LpspiIpConfig->SlaveMode)
        {
            Lpspi_Ip_Cancel(PhyUnitConfig->Instance);
            Ret = E_OK;
        }
#endif
    }
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else
    {
#if (FLEXIO_SPI_IP_SLAVE_SUPPORT == STD_ON)
        if (TRUE == PhyUnitConfig->IpConfig.FlexioSpiIpConfig->SlaveMode)
        {
            Flexio_Spi_Ip_Cancel(PhyUnitConfig->Instance);
            Ret = E_OK;
        }
#endif
    }
#endif
    return Ret;
}
    #endif
#endif

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
void Spi_Ipw_SetClockMode(Spi_DualClockModeType ClockMode,
                          const Spi_HWUnitConfigType * HWUnitConfig)
{
    if (SPI_OVER_LPSPI == HWUnitConfig->IpType)
    {
        (void)Lpspi_Ip_SetClockMode(HWUnitConfig->Instance, (Lpspi_Ip_DualClockModeType)ClockMode);
    }
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    else if (SPI_OVER_FLEXIO == HWUnitConfig->IpType)
    {
        (void)Flexio_Spi_Ip_SetClockMode(HWUnitConfig->Instance, (Flexio_Spi_Ip_DualClockModeType)ClockMode);
    }
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    else
    {
        (void)Dspi_Ip_SetClockMode(HWUnitConfig->Instance, (Dspi_Ip_DualClockModeType)ClockMode);
    }
#endif
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
