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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef FLEXIO_I2C_IP_H
#define FLEXIO_I2C_IP_H

/**
*     @file
*
*     @addtogroup FLEXIO_I2C_DRIVER Flexio_I2c Driver
*     @{
*/

#if defined(__cplusplus)
extern "C" {
#endif

 /*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_I2c_Ip_Types.h"
#include "Flexio_I2c_Ip_Cfg.h"

#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
    #if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
        #include "Dma_Ip.h"
    #endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_I2C_IP_VENDOR_ID                      43
#define FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_I2C_IP_SW_MAJOR_VERSION               5
#define FLEXIO_I2C_IP_SW_MINOR_VERSION               0
#define FLEXIO_I2C_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_I2c_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_VENDOR_ID != FLEXIO_I2C_IP_TYPES_VENDOR_ID)
    #error "Flexio_I2c_Ip.h and Flexio_I2c_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2c_Ip_Types.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION   != FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION   != FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION!= FLEXIO_I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip.h and Flexio_I2c_Ip_Types.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_Types.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP_SW_MAJOR_VERSION != FLEXIO_I2C_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_SW_MINOR_VERSION != FLEXIO_I2C_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_SW_PATCH_VERSION != FLEXIO_I2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip.h and Flexio_I2c_Ip_Types.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_Cfg.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_VENDOR_ID != FLEXIO_I2C_IP_CFG_VENDOR_ID)
    #error "Flexio_I2c_Ip.h and Flexio_I2c_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2c_Ip_Cfg.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip.h and Flexio_I2c_Ip_Cfg.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_Cfg.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_SW_MINOR_VERSION != FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_SW_PATCH_VERSION != FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip.h and Flexio_I2c_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (FLEXIO_I2C_IP_ENABLE == STD_ON)
        #if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
            /* Check if current file and Dma_Ip.h header file are of the same Autosar version */
            #if ((FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
                 (FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Flexio_I2c_Ip.c and Dma_Ip.h are different"
            #endif
        #endif /* (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE) */
    #endif /* (FLEXIO_I2C_IP_ENABLE == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/*******************************************************************************
* Definitions
******************************************************************************/

/*! @cond DRIVER_INTERNAL_USE_ONLY */
/* Length of the DMA scatter-gather chain for Tx. Two blocks are needed, but as the fist one is
   loaded directly in the TCD, only one block needs to be in RAM  */
#define FLEXIO_I2C_IP_DMA_TX_CHAIN_LENGTH      (1U)
/* Length of the DMA scatter-gather chain for Rx. Six blocks are needed, but as the fist one is
   loaded directly in the TCD, only five blocks needs to be in RAM  */
#define FLEXIO_I2C_IP_DMA_RX_CHAIN_LENGTH      (5U)
/* Total size of the DMA scatter-gather buffer. Add 1 because STCD_SIZE already compensates for the
   first stcd not being loaded in RAM */
#define FLEXIO_I2C_IP_DMA_BUF_SIZE   (STCD_SIZE(FLEXIO_I2C_IP_DMA_TX_CHAIN_LENGTH + FLEXIO_I2C_IP_DMA_RX_CHAIN_LENGTH + 1U))
/*! @endcond */

/*******************************************************************************
 * Variables
 ******************************************************************************/

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*!
 * @name FLEXIO_I2C Driver
 * @{
 */

/**
 * @brief Initialize the FLEXIO_I2C master mode driver
 *
 * This function initializes the FLEXIO_I2C driver in master mode.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param ConfigPtr    Pointer to the FLEXIO_I2C master user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterInit_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterInit(uint8 Instance,
                                                  uint8 Channel,
                                                  const Flexio_I2c_Ip_MasterConfigType * ConfigPtr);


/**
 * @brief De-initialize the FLEXIO_I2C master mode driver
 *
 * This function de-initializes the FLEXIO_I2C driver in master mode. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterDeinit_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterDeinit(uint8 Instance,
                                                    uint8 Channel);


/**
 * @brief Set the baud rate for any subsequent I2C communication
 *
 * This function sets the baud rate (SCL frequency) for the I2C master.
 * Note that due to module limitation not any baud rate can be achieved. The driver
 * will set a baud rate as close as possible to the requested baud rate, but there may
 * still be substantial differences, for example if requesting a high baud rate while
 * using a low-frequency FlexIO clock. The application should call
 * Flexio_I2c_Ip_DRV_MasterGetBaudRate() after Flexio_I2c_Ip_DRV_MasterSetBaudRate() to check
 * what baud rate was actually set.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param BaudRate  the desired baud rate in hertz
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterSetBaudRate_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSetBaudRate(uint8 Instance,
                                                         uint8 Channel,
                                                         uint32 InputClock,
                                                         uint32 BaudRate);


/**
 * @brief Get the currently configured baud rate
 *
 * This function returns the currently configured I2C baud rate.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param BaudRate  the current baud rate in hertz
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterGetBaudRate_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterGetBaudRate(uint8 Instance,
                                                         uint8 Channel,
                                                         uint32 InputClock,
                                                         uint32 *BaudRate);


/**
 * @brief Set the slave address for any subsequent I2C communication
 *
 * This function sets the slave address which will be used for any future transfer.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param Address   slave address, 7-bit
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterSetSlaveAddr_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSetSlaveAddr(uint8 Instance,
                                                          uint8 Channel,
                                                          const uint16 Address);


/**
 * @brief Perform a non-blocking send transaction on the I2C bus
 *
 * This function starts the transmission of a block of data to the currently
 * configured slave address and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2c_Ip_DRV_MasterGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2c_Ip_DRV_MasterGetStatus() to check the progress of the transmission.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param TxBuff    pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the transmission
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterSendData_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSendData(uint8 Instance,
                                                      uint8 Channel,
                                                      const uint8 * TxBuff,
                                                      uint32 TxSize,
                                                      boolean SendStop);



/**
 * @brief Perform a blocking send transaction on the I2C bus
 *
 * This function sends a block of data to the currently configured slave address, and
 * only returns when the transmission is complete.
 *
 * @param[in] Instance  FLEXIO peripheral Instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param TxBuff    pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the transmission
 * @param timeout  timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterSendDataBlocking_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSendDataBlocking(uint8 Instance,
                                                              uint8 Channel,
                                                              const uint8 * TxBuff,
                                                              uint32 TxSize,
                                                              boolean SendStop,
                                                              uint32 Timeout);


/**
 * @brief Perform a non-blocking receive transaction on the I2C bus
 *
 * This function starts the reception of a block of data from the currently
 * configured slave address and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2c_Ip_DRV_MasterGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2c_Ip_DRV_MasterGetStatus() to check the progress of the reception.
 *
 * @param[in] Instance  FLEXIO peripheral instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param RxBuff    pointer to the buffer where to store received data
 * @param RxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the reception
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterReceiveData_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterReceiveData(uint8 Instance,
                                                         uint8 Channel,
                                                         uint8 * RxBuff,
                                                         uint32 RxSize,
                                                         boolean SendStop);


/**
 * @brief Perform a blocking receive transaction on the I2C bus
 *
 * This function receives a block of data from the currently configured slave address,
 * and only returns when the transmission is complete.
 *
 * @param[in] Instance  FLEXIO peripheral Instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param RxBuff    pointer to the buffer where to store received data
 * @param RxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the reception
 * @param Timeout  timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterReceiveDataBlocking_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterReceiveDataBlocking(uint8 Instance,
                                                                 uint8 Channel,
                                                                 uint8 * RxBuff,
                                                                 uint32 RxSize,
                                                                 boolean SendStop,
                                                                 uint32 Timeout);


/**
 * @brief Aborts a non-blocking I2C master transaction
 *
 * This function aborts a non-blocking I2C transfer.
 *
 * @param[in] Instance  FLEXIO peripheral Instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterTransferAbort_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterTransferAbort(uint8 Instance,
                                                           uint8 Channel);

/**
 * @brief Get the status of the current non-blocking I2C master transaction
 *
 * This function returns the current status of a non-blocking I2C master transaction.
 * A return code of STATUS_BUSY means the transfer is still in progress.
 * Otherwise the function returns a status reflecting the outcome of the last transfer.
 * When the driver is initialized in polling mode this function also advances the transfer
 * by checking and handling the transmit and receive events, so it must be called
 * frequently to avoid overflows or underflows.
 *
 * @param[in] Instance  FLEXIO peripheral Instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param BytesRemaining  The remaining number of bytes to be transferred
 * @return    Error or success status returned by API
 * @implements Flexio_I2c_Ip_MasterGetStatus_Activity
 */
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterGetStatus(uint8 Instance,
                                                       uint8 Channel,
                                                       uint32 *BytesRemaining);

/**
 * @brief Sets the master callback
 *
 * @details This functions sets the master callback
 *
 * @param[in] Instance  FLEXIO peripheral Instance number
 * @param[in] Channel  FLEXIO I2C logical channel number
 * @param[in] MasterCallback  master callback to be set
 *
 * @return void
 */
/* @implements Flexio_I2c_Ip_SetMasterCallback_Activity */
void Flexio_I2c_Ip_SetMasterCallback(uint8 Instance,
                                     uint8 Channel,
                                     Flexio_I2c_Ip_MasterCallbackType MasterCallback);


/**
* @brief   Interrupt handler for FlexIO.
* @details This function shall manage all the interrupts of a FlexIO module
*
* @param[in]    FlexIOChannel FlexIO channel to be addressed.
* @param[in]    ShifterMaskFlag shifters status
* @param[in]    ShifterErrMaskFlag shifters error status
* @param[in]    TimerMaskFlag FlexIO timers status
*
* @return       void.
*
*
* @note         Internal driver function.
*/
/* @implements Flexio_I2c_Ip_IrqHandler_Activity */
void Flexio_I2c_Ip_IrqHandler(const uint8 FlexIOChannel,
                              uint8 ShifterMaskFlag,
                              uint8 ShifterErrMaskFlag,
                              uint8 TimerMaskFlag);

#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter0(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter1(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter2(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter3(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter4(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter5(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter6(void);

void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter7(void);

#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
    
void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler0(void);

void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler1(void);

void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler2(void);

void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler3(void);

#endif

#endif /* STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#endif /* FLEXIO_I2C_IP_ENABLE == STD_OFF */

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* Flexio_I2c_Ip_DRIVER_H */

