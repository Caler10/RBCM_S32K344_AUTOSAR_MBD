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

#if !defined(LPI2C_IP_H)
#define LPI2C_IP_H

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
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
#include "Lpi2c_Ip_Callbacks.h"
#include "Lpi2c_Ip_Types.h"
#include "Lpi2c_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_VENDOR_ID                      43
#define LPI2C_IP_AR_RELEASE_MAJOR_VERSION       4
#define LPI2C_IP_AR_RELEASE_MINOR_VERSION       7
#define LPI2C_IP_AR_RELEASE_REVISION_VERSION    0
#define LPI2C_IP_SW_MAJOR_VERSION               5
#define LPI2C_IP_SW_MINOR_VERSION               0
#define LPI2C_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpi2c_Ip_Callbacks.h */
#if (LPI2C_IP_VENDOR_ID != LPI2C_IP_CALLBACKS_VENDOR_ID)
    #error "Lpi2c_Ip.h and Lpi2c_Ip_Callbacks.h have different vendor ids"
#endif
#if (( LPI2C_IP_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_REVISION_VERSION != LPI2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.h and Lpi2c_Ip_Callbacks.h are different"
#endif
#if (( LPI2C_IP_SW_MAJOR_VERSION != LPI2C_IP_CALLBACKS_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_SW_MINOR_VERSION != LPI2C_IP_CALLBACKS_SW_MINOR_VERSION) || \
     ( LPI2C_IP_SW_PATCH_VERSION != LPI2C_IP_CALLBACKS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip.h and Lpi2c_Ip_Callbacks.h are different"
#endif

/* Checks against LPI2C_Ip_Types.h */
#if (LPI2C_IP_VENDOR_ID != LPI2C_IP_TYPES_VENDOR_ID)
    #error "Lpi2c_Ip.h and LPI2C_Ip_Types.h have different vendor ids"
#endif
#if (( LPI2C_IP_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_REVISION_VERSION != LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.h and LPI2C_Ip_Types.h are different"
#endif
#if (( LPI2C_IP_SW_MAJOR_VERSION != LPI2C_IP_TYPES_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_SW_MINOR_VERSION != LPI2C_IP_TYPES_SW_MINOR_VERSION) || \
     ( LPI2C_IP_SW_PATCH_VERSION != LPI2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip.h and LPI2C_Ip_Types.h are different"
#endif

/* Checks against LPI2C_Ip_Cfg.h */
#if (LPI2C_IP_VENDOR_ID != LPI2C_IP_CFG_VENDOR_ID)
    #error "Lpi2c_Ip.h and LPI2C_Ip_Cfg.h have different vendor ids"
#endif
#if (( LPI2C_IP_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_AR_RELEASE_REVISION_VERSION != LPI2C_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.h and LPI2C_Ip_Cfg.h are different"
#endif
#if (( LPI2C_IP_SW_MAJOR_VERSION != LPI2C_IP_CFG_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_SW_MINOR_VERSION != LPI2C_IP_CFG_SW_MINOR_VERSION) || \
     ( LPI2C_IP_SW_PATCH_VERSION != LPI2C_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip.h and LPI2C_Ip_Cfg.h are different"
#endif

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/**
 * @name LPI2C Driver
 * @{
 */

/**
* @note put all I2C code into defined section
*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief Initialize the LPI2C master mode driver
 *
 * @details This function initializes the LPI2C driver in master mode.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] ConfigPtr    Pointer to the LPI2C master user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 * @return    void
 * @implements Lpi2c_Ip_MasterInit_Activity
 */
void Lpi2c_Ip_MasterInit(uint8 Instance,
                         const Lpi2c_Ip_MasterConfigType * ConfigPtr);


/**
 * @brief De-initialize the LPI2C master mode driver
 *
 * @details This function de-initializes the LPI2C driver in master mode. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @return    void
 * @implements Lpi2c_Ip_MasterDeinit_Activity
 */
void Lpi2c_Ip_MasterDeinit(uint8 Instance);


/**
 * @brief Get the currently configured baud rate
 *
 * @details This function returns the currently configured baud rate.
 *
 * @param[in] Instance   LPI2C peripheral instance number
 * @param[in] InputClock input clock in Hz
 * @param[out] BaudRate  structure that contains the current baud rate in hertz
 *                  and the baud rate in hertz for High-speed mode (unused
 *                  in other modes, can be NULL)
 * @implements Lpi2c_Ip_MasterGetBaudRate_Activity
 */
void Lpi2c_Ip_MasterGetBaudRate(uint8 Instance,
                                uint32 InputClock,
                                uint32 *BaudRate);


/**
 * @brief Set the baud rate for any subsequent I2C communication
 *
 * @details This function sets the baud rate (SCL frequency) for the I2C master. It can also
 * change the operating mode.
 * Note that due to module limitation not any baud rate can be achieved. The driver
 * will set a baud rate as close as possible to the requested baud rate, but there may
 * still be substantial differences, for example if requesting a high baud rate while
 * using a low-frequency protocol clock for the LPI2C module. The application should
 * call Lpi2c_Ip_MasterGetBaudRate() after Lpi2c_Ip_MasterSetBaudRate() to check
 * what baud rate was actually set.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] OperatingMode  I2C operating mode
 * @param[in] BaudRate  structure that contains the baud rate in hertz to use by current slave device
 *                  and also the baud rate in hertz for High-speed mode (unused in other modes)
 * @param[in] InputClock input clock in Hz
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_MasterSetBaudRate_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSetBaudRate(uint8 Instance,
                                               Lpi2c_Ip_ModeType OperatingMode,
                                               uint32 Baudrate,
                                               uint32 InputClock);


/**
 * @brief Set the slave address for any subsequent I2C communication
 *
 * @details This function sets the slave address which will be used for any future
 * transfer initiated by the LPI2C master.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] Address   slave address, 7-bit or 10-bit
 * @param[in] Is10bitAddr   specifies if provided address is 10-bit
 * @implements Lpi2c_Ip_MasterSetSlaveAddr_Activity
 */
void Lpi2c_Ip_MasterSetSlaveAddr(uint8 Instance,
                                 const uint16 Address,
                                 const boolean Is10bitAddr);


/**
 * @brief Perform a non-blocking send transaction on the I2C bus
 *
 * @details This function starts the transmission of a block of data to the currently
 * configured slave address and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine.
 * Use Lpi2c_Ip_MasterGetSendStatus() to check the progress of the transmission.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] TxBuff    pointer to the data to be transferred
 * @param[in] TxSize    length in bytes of the data to be transferred
 * @param[in] SendStop    specifies whether or not to generate stop condition after the transmission
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_MasterSendData_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSendData(uint8 Instance,
                                            uint8 * TxBuff,
                                            uint32 TxSize,
                                            boolean SendStop);


/**
 * @brief Perform a blocking send transaction on the I2C bus
 *
 * @details This function sends a block of data to the currently configured slave Address, and
 * only returns when the transmission is complete.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] TxBuff    pointer to the data to be transferred
 * @param[in] TxSize    length in bytes of the data to be transferred
 * @param[in] SendStop    specifies whether or not to generate stop condition after the transmission
 * @param[in] Timeout   Timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_MasterSendDataBlocking_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterSendDataBlocking(uint8 Instance,
                                                    uint8 * TxBuff,
                                                    uint32 TxSize,
                                                    boolean SendStop,
                                                    uint32 Timeout);


/**
 * @brief Perform a non-blocking receive transaction on the I2C bus
 *
 * @details This function starts the reception of a block of data from the currently
 * configured slave address and returns immediately.
 * The rest of the reception is handled by the interrupt service routine.
 * Use Lpi2c_Ip_MasterGetReceiveStatus() to check the progress of the reception.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[out] RxBuff    pointer to the buffer where to store received data
 * @param[in] RxSize    length in bytes of the data to be transferred
 * @param[in] SendStop    specifies whether or not to generate stop condition after the reception
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_MasterReceiveData_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterReceiveData(uint8 Instance,
                                               uint8 * RxBuff,
                                               uint32 RxSize,
                                               boolean SendStop);


/**
 * @brief Perform a blocking receive transaction on the I2C bus
 *
 * @details This function receives a block of data from the currently configured slave Address,
 * and only returns when the transmission is complete.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[out] RxBuff    pointer to the buffer where to store received data
 * @param[in] RxSize    length in bytes of the data to be transferred
 * @param[in] SendStop    specifies whether or not to generate stop condition after the reception
 * @param[in] Timeout   Timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_MasterReceiveDataBlocking_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterReceiveDataBlocking(uint8 Instance,
                                                       uint8 * RxBuff,
                                                       uint32 RxSize,
                                                       boolean SendStop,
                                                       uint32 Timeout);


/**
 * @brief Return the current status of the I2C master transfer
 *
 * @details This function can be called during a non-blocking transmission to check the
 * status of the transfer.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[out] BytesRemaining   the number of remaining bytes in the active I2C transfer
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_MasterGetTransferStatus_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_MasterGetTransferStatus(uint8 Instance,
                                                     uint32 *BytesRemaining);


/**
 * @brief Handle master operation when I2C interrupt occurs
 *
 * @details This is the interrupt service routine for the LPI2C master mode driver. It
 * handles the rest of the transfer started by one of the send/receive functions.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @implements Lpi2c_Ip_MasterIRQHandler_Activity
 */
void Lpi2c_Ip_MasterIRQHandler(uint8 Instance);


/**
 * @brief Initialize the I2C slave mode driver
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] ConfigPtr    Pointer to the LPI2C slave user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 * @return    void
 * @implements Lpi2c_Ip_SlaveInit_Activity
 */
void Lpi2c_Ip_SlaveInit(uint8 Instance,
                        const Lpi2c_Ip_SlaveConfigType * ConfigPtr);


/**
 * @brief De-initialize the I2C slave mode driver
 *
 * @details This function de-initializes the LPI2C driver in slave mode. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @return    void
 * @implements Lpi2c_Ip_SlaveDeinit_Activity
 */
void Lpi2c_Ip_SlaveDeinit(uint8 Instance);


/**
 * @brief Provide a buffer for transmitting data
 *
 * @details This function provides a buffer from which the LPI2C slave-mode driver can
 * transmit data. It can be called for example from the user callback provided at
 * initialization time, when the driver reports events LPI2C_SLAVE_EVENT_TX_REQ or
 * LPI2C_SLAVE_EVENT_TX_EMPTY.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] TxBuff    pointer to the data to be transferred
 * @param[in] TxSize    length in bytes of the data to be transferred
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_SlaveSetBuffer_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_SlaveSetBuffer(uint8 Instance,
                                            uint8 * DataBuff,
                                            uint32 DataSize);


/**
 * @brief Return the current status of the I2C slave transfer
 *
 * @details This function can be called during a non-blocking transmission to check the
 * status of the transfer.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @param[in] bytesRemaining[out]   the number of remaining bytes in the active I2C transfer
 * @return    Error or success status returned by API
 * @implements Lpi2c_Ip_SlaveGetTransferStatus_Activity
 */
Lpi2c_Ip_StatusType Lpi2c_Ip_SlaveGetTransferStatus(uint8 Instance,
                                                    uint32 *BytesRemaining);


/**
 * @brief Handle slave operation when I2C interrupt occurs
 *
 * @details This is the interrupt service routine for the LPI2C slave mode driver. It
 * handles any transfer initiated by an I2C master and notifies the application
 * via the provided callback when relevant events occur.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 * @implements Lpi2c_Ip_SlaveIRQHandler_Activity
 */
void Lpi2c_Ip_SlaveIRQHandler(uint8 Instance);

#if defined (LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE)

/**
 * @brief Handler for both slave and master operation when I2C interrupt occurs
 *
 * @details This is the interrupt service routine for the LPI2C slave and master mode driver. It
 * handles any transfer initiated by an I2C master and notifies the application
 * via the provided callback when relevant events occur.
 *
 * @param[in] Instance  LPI2C peripheral instance number
 *
 * @return void
 */
/* @implements Lpi2c_Ip_ModuleIRQHandler_Activity */
void Lpi2c_Ip_ModuleIRQHandler(uint8 Instance);

#endif /* LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE */

/**
 * @brief Sets the master callback
 *
 * @details This functions sets the master callback
 *
 * @param[in] u32Instance  LPI2C peripheral instance number
 * @param[in] masterCallback  master callback to be set
 *
 * @return void
 */
/* @implements Lpi2c_Ip_SetMasterCallback_Activity */
void Lpi2c_Ip_SetMasterCallback(uint8 Instance,
                                Lpi2c_Ip_MasterCallbackType MasterCallback);

/**
 * @brief Sets the slave callback
 *
 * @details This functions sets the slave callback
 *
 * @param[in] u32Instance  LPI2C peripheral instance number
 * @param[in] slaveCallback  slave callback to be set
 *
 * @return void
 */
/* @implements Lpi2c_Ip_SetSlaveCallback_Activity */
void Lpi2c_Ip_SetSlaveCallback(uint8 Instance,
                               Lpi2c_Ip_SlaveCallbackType SlaveCallback);

/**
 * @brief Start listening
 *
 * @details This is used to enable slave events
 *
 * @param[in] u32Instance  LPI2C peripheral instance number
 * @return void
 */
/* @implements Lpi2c_Ip_StartListening_Activity */
void Lpi2c_Ip_StartListening(uint8 Instance);

#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
/**
 * @brief Set high speed mode for master
 *
 * @details This function enables high speed mode for master
 *
 * @param[in] u32Instance  LPI2C peripheral instance number
 * @param[in] bHighSpeedEnabled  enables/disables master high speed mode
 * @return void
 */

void Lpi2c_Ip_SetMasterHighSpeedMode(uint8 Instance,
                                     boolean HighSpeedEnabled);
#endif /* STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE */

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)

#if (LPI2C_INSTANCE_COUNT >= 1U)
void Lpi2c_Ip_DmaCompleteNotification0(void);

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
void Lpi2c_Ip_MasterDmaErrorNotification0(void);
void Lpi2c_Ip_SlaveDmaErrorNotification0(void);
#endif

#endif /* LPI2C_INSTANCE_COUNT >= 1U */

#if (LPI2C_INSTANCE_COUNT >= 2U)
void Lpi2c_Ip_DmaCompleteNotification1(void);

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
void Lpi2c_Ip_MasterDmaErrorNotification1(void);
void Lpi2c_Ip_SlaveDmaErrorNotification1(void);
#endif

#endif /* LPI2C_INSTANCE_COUNT >= 2U */
#endif /* STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @}*/

#endif /* LPI2C_IP_H */

