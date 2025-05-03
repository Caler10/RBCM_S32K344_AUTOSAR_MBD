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

#ifndef DSPI_IP_H
#define DSPI_IP_H

/**
*   @file    Dspi_Ip.h
*
*
*   @brief   SPI/DSPI IP driver header file.
*   @details SPI/DSPI IP driver header file.

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
#include "Dspi_Ip_Types.h"
#ifdef DSPI_IP_ENABLE_USER_MODE_SUPPORT
#include "Mcal.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_IP_VENDOR_ID                      43
#define DSPI_IP_AR_RELEASE_MAJOR_VERSION       4
#define DSPI_IP_AR_RELEASE_MINOR_VERSION       7
#define DSPI_IP_AR_RELEASE_REVISION_VERSION    0
#define DSPI_IP_SW_MAJOR_VERSION               5
#define DSPI_IP_SW_MINOR_VERSION               0
#define DSPI_IP_SW_PATCH_VERSION               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dspi_Ip.h and Dspi_Ip_Types.h are of the same vendor */
#if (DSPI_IP_VENDOR_ID != DSPI_IP_TYPES_VENDOR_ID)
    #error "Dspi_Ip.h and Dspi_Ip_Types.h have different vendor ids"
#endif
/* Check if Dspi_Ip.h file and Dspi_Ip_Types.h file are of the same Autosar version */
#if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION != DSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (DSPI_IP_AR_RELEASE_MINOR_VERSION != DSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (DSPI_IP_AR_RELEASE_REVISION_VERSION != DSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dspi_Ip.h and Dspi_Ip_Types.h are different"
#endif
#if ((DSPI_IP_SW_MAJOR_VERSION != DSPI_IP_TYPES_SW_MAJOR_VERSION) || \
    (DSPI_IP_SW_MINOR_VERSION != DSPI_IP_TYPES_SW_MINOR_VERSION) || \
    (DSPI_IP_SW_PATCH_VERSION != DSPI_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Dspi_Ip.h and Dspi_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Mcal header file are of the same Autosar version */
    #if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (DSPI_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dspi_Ip.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_ON == DSPI_IP_ENABLE)
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief   Export Post-Build configurations.
*/
DSPI_IP_CONFIG_EXT

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
* @brief            SPI/DSPI peripheral initialization.
* @details          The function initialize the SPI Unit specified in the configuration.
*
* @param[in]        PhyUnitConfigPtr -  pointer to the specified SPI Unit configuration.
*
* @return           DSPI_IP_STATUS_SUCCESS: Initialization command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Initialization command has not been accepted.
* @implements Dspi_Ip_Init_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_Init(const Dspi_Ip_ConfigType *PhyUnitConfigPtr);

/**
* @brief            SPI/DSPI peripheral deinitialization.
* @details          The function de-initialize the SPI peripheral instance specified.
*                   All registers of SPI peripheral will be reset.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           DSPI_IP_STATUS_SUCCESS: De-initialization command has been accepted.
*                   DSPI_IP_STATUS_FAIL: De-initialization command has not been accepted.
* @implements Dspi_Ip_DeInit_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_DeInit(uint8 Instance);

/**
* @brief            SPI/DSPI synchronous transmission.
* @details          This function initializes a synchronous transfer using the bus parameters provided
*                   by external device.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted.
* @param[in]        TxBuffer - pointer to transmit buffer.
* @param[in,out]    RxBuffer - pointer to receive buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        TimeOut - duration for sending one frame.
*
* @return           DSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   DSPI_IP_FIFO_ERROR: Overflow or underflow error occurred.
*                   DSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
*                   DSPI_IP_TIMEOUT: Timeout error occurred.
*
* @implements Dspi_Ip_SyncTransmit_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_SyncTransmit(const Dspi_Ip_ExternalDeviceType *ExternalDevice,
                                        const uint8 *TxBuffer,
                                        uint8 *RxBuffer,
                                        uint16 Length,
                                        uint32 TimeOut);

/**
* @brief            SPI/DSPI asynchronous transmission.
* @details          This function initializes an asynchronous transfer using the bus parameters provided
*                   by external device. After Dspi_Ip_Init function is called, DSPI_IP_POLLING
*                    mode is set as default to change the default mode Dspi_Ip_UpdateTransferMode should be called.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted
* @param[in]        TxBuffer - pointer to transmit buffer.
* @param[in,out]    RxBuffer - pointer to receive buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        EndCallback - callback function is called at the end of transfer.
*
* @return           DSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
* @implements Dspi_Ip_AsyncTransmit_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_AsyncTransmit(const Dspi_Ip_ExternalDeviceType *ExternalDevice,
                                         const uint8 *TxBuffer,
                                         uint8 *RxBuffer,
                                         uint16 Length,
                                         Dspi_Ip_CallbackType EndCallback);

#if (DSPI_IP_DMA_USED == STD_ON)
#if (DSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
/**
* @brief            SPI/DSPI asynchronous transmission fast.
* @details          This function initializes an asynchronous transmission for multiple transfers session
*                   and CPU used only for processing at the end of sequence transfer.
*                   The list of transfers session is composed of an array of fast transfers settings.
*                   The settings array is defined by the user needs: it contains entries parameters to be configured
*                   for each transfer session as defined in Dspi_Ip_FastTransferType.
*
*    How to use this interface:
*    1. Use the "Dspi_Ip_FastTransferType" to create a list(array) of transfer session.
*    Each field in Dspi_Ip_FastTransferType for each transfer session must be configured.
*    Note: This feature requires:
*        a. All parameters in all External Devices used(pointed by ExternalDevice) must be the same in each transfer session except SpiCsIdentifier, SpiCsContinous.
*        b. In each transfer section, the number of data buffer(Length) is NOT higher than 32767 if SpiDataWidth < 9.
*        c. Only Master mode is supported(SpiPhyUnit/SpiPhyUnitMode = SPI_MASTER).
*        d. Make sure that SpiPhyUnit/SpiMaxDmaFastTransfer value must NOT lower than total of transfer sessions.
*        e. Make sure that number of ScatterGathers configuration in SpiPhyUnit/SpiPhyTxCmdDmaChannel must NOT lower than
*        total of transfer sessions plus number of time request CS de-assert(KeepCs = FALSE) at the end of transfer session in the list configured.
*        f. Make sure that number of ScatterGathers configuration in each SpiPhyUnit/SpiPhyTxDmaChannel, SpiPhyRxDmaChannel must NOT lower than total of transfer sessions.
*    2. Call the "Dspi_Ip_AsyncTransmitFast()" interface.
*
*    Example:
*        The user shall create the desired configuration list for his specific application.
*        For example use case:
*        - Requiring 2 transfers session, keep CS assert at the end of first transfer session.
*        - Transfer session 1:
*            + Use SpiExternalDevice_0 with SpiCsIdentifier = PCS0, SpiCsContinous = TRUE.
*            + Send 5 bytes. Tx buffer is "uint8 u8TxBuffer1[5u]={0,1,2,3,4};". Rx buffer is "uint8 u8RxBuffer1[5u];".
*            + Keep CS assert at the end of this transfer session.
*        - Transfer session 2:
*            + Use SpiExternalDevice_0 with SpiCsIdentifier = PCS0, SpiCsContinous = TRUE.
*            + Send 10 bytes with default transmit data value is 5. Tx buffer is NULL_PTR. Rx buffer is "uint8 u8RxBuffer2[10u];".
*            + This is last transfer session, so CS will not kipped by default at the end of last transfer session.
*        - Configuration example on configuration tool:
*            + SpiGeneral/SpiEnableDmaFastTransferSupport = true.
*            + SpiPhyUnit/SpiMaxDmaFastTransfer = 2(2 transfers session).
*            + Number of ScatterGathers configuration for SpiPhyTxCmdDmaChannel is 3(2 transfers session + 1 time CS de-assert at the end of last transfer session).
*            + Number of ScatterGathers configuration for SpiPhyTxDmaChannel, SpiPhyRxDmaChannel is 2(2 transfers session).
*        - Call "UserCallbackFunc" when Fast transfer completed.
*        - Coding example:
*            void UserCallbackFunc(uint8 Instance, Dspi_Ip_EventType event);
*            Dspi_Ip_FastTransferType aUserFastTransferCfgList[2u] =
*            {
*                {
*                    Dspi_Ip_DeviceAttributes_SpiExternalDevice_0_BOARD_InitPeripherals, ->Point to External Device 0 configuration generated by configuration tool
*                    u8TxBuffer1, -> Store pointer for Tx buffer
*                    u8RxBuffer1, -> Store pointer for Rx buffer
*                    0u, -> Default transmit data, don't care due to Tx buffer is not NULL_PTR
*                    5u, -> Number of bytes to be sent
*                    (boolean)TRUE -> Keep CS signal at the end of this transfer session
*                },
*                {
*                    Dspi_Ip_DeviceAttributes_SpiExternalDevice_0_BOARD_InitPeripherals, -> Point to external device configuration
*                    NULL_PTR, -> Store pointer for Tx buffer
*                    u8RxBuffer2, -> Store pointer for Rx buffer
*                    5u, -> Default transmit data, don't care due to Tx buffer is not NULL_PTR
*                    10u, -> Number of bytes to be sent
*                    (boolean)FALSE -> Not keep CS signal at the end of this transfer session, don't care this parameter for last transfer
*                }
*            };
*            Dspi_Ip_AsyncTransmitFast(aUserFastTransferCfgList, 2u, &UserCallbackFunc);
*
* @param[in,out]    FastTransferCfg - pointer to the list of transfers section configuration.
* @param[in]        NumberOfTransfer - number of transfers session in the list is pointed by pFastTransferCfg.
* @param[in]        EndCallback - callback function is called at the end of sequence transfer.
*
* @return           DSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
* @implements Dspi_Ip_AsyncTransmitFast_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_AsyncTransmitFast(const Dspi_Ip_FastTransferType *FastTransferCfg,
                                             uint8 NumberOfTransfer,
                                             Dspi_Ip_CallbackType EndCallback);

#endif
#endif

/**
* @brief            Get status of HW unit.
* @details          This function returns the status of the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           Dspi_Ip_HwStatusType
* @implements Dspi_Ip_GetStatus_Activity
*/
Dspi_Ip_HwStatusType Dspi_Ip_GetStatus(uint8 Instance);

/**
* @brief            Process transfer in POLLING mode.
* @details          This function shall polls the SPI interrupts linked to SPI peripheral instance allocated to
*                   the transmission of data to enable the evolution of transmission state machine.
*
* @param[in]        Instance - SPI peripheral instance number.
* @implements Dspi_Ip_ManageBuffers_Activity
*/
void Dspi_Ip_ManageBuffers(uint8 Instance);

/**
* @brief            Adjust transfer based on external conditions
* @details          Use parameters to improve transfer
*
* @param[in]        ExternalDevice - External device where data is transmitted
* @param[in]        Param - Parameter with adjustments
*
* @return           DSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Setting command has not been accepted.
*/
Dspi_Ip_StatusType Dspi_Ip_UpdateTransferParam(const Dspi_Ip_ExternalDeviceType *ExternalDevice,
                                               const Dspi_Ip_TransferAdjustmentType *Param);

/**
* @brief            SPI/DSPI change frame size.
* @details          This function updates frame size of specific external device configuration for next transfers.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        FrameSize - Frame size.
*
* @return           DSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Dspi_Ip_UpdateFrameSize_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_UpdateFrameSize(const Dspi_Ip_ExternalDeviceType *ExternalDevice,
                                           uint8 FrameSize);

/**
* @brief            SPI/DSPI change bit order.
* @details          This function updates bits order LSB or MSB of specific external device configuration for next transfer.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        Lsb - Data is transferred LSB first or not.
*
* @return           DSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Dspi_Ip_UpdateLsb_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_UpdateLsb(const Dspi_Ip_ExternalDeviceType *ExternalDevice,
                                     boolean Lsb);

/**
* @brief            SPI/DSPI change default transmit data.
* @details          This function updates default transmit data of specific external device configuration for next transfer.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        DefaultData - New default transmit data.
*
* @return           DSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Dspi_Ip_UpdateDefaultTransmitData_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_UpdateDefaultTransmitData(const Dspi_Ip_ExternalDeviceType *ExternalDevice,
                                                     uint32 DefaultData);

/**
* @brief            SPI/DSPI change transfer mode.
* @details          This function updates the asynchronous mechanism mode for the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
* @param[in]        Mode - new mode (interrupt or polling).
*
* @return           DSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Dspi_Ip_UpdateTransferMode_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_UpdateTransferMode(uint8 Instance,
                                              Dspi_Ip_ModeType Mode);

/**
* @brief            SPI/DSPI cancel current asynchronous transmission.
* @details          This function cancels an asynchronous transmission in progress for the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @implements Dspi_Ip_Cancel_Activity
*/
void Dspi_Ip_Cancel(uint8 Instance);

#if (DSPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief            Change clock mode.
* @details          This function will change clock mode to operate with other clock reference.
*
* @param[in]        Instance - SPI peripheral instance number.
* @param[in]        ClockMode           Clock mode.
*
* @return           DSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   DSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Dspi_Ip_SetClockMode_Activity
*/
Dspi_Ip_StatusType Dspi_Ip_SetClockMode(uint8 Instance,
                                        Dspi_Ip_DualClockModeType ClockMode);

#endif

void Dspi_Ip_IrqHandler(uint8 Instance);

#if (DSPI_IP_DMA_USED == STD_ON)
void Dspi_Ip_IrqDmaHandler(uint8 Instance);

#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*(STD_ON == DSPI_IP_ENABLE)*/

/** @} */

#endif /* DSPI_IP_H */
