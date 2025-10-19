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
#ifndef FLEXIO_I2C_IP_TYPES_H
#define FLEXIO_I2C_IP_TYPES_H

/**
*     @file
*
*     @addtogroup FLEXIO_I2C_DRIVER Flexio_I2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_I2c_Ip_CfgDefines.h"
#include "Flexio_I2c_Ip_Callbacks.h"
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_I2C_IP_TYPES_VENDOR_ID                      43
#define FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_I2C_IP_TYPES_SW_MAJOR_VERSION               5
#define FLEXIO_I2C_IP_TYPES_SW_MINOR_VERSION               0
#define FLEXIO_I2C_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Flexio_I2c_Ip_CfgDefines.h */
#if (FLEXIO_I2C_IP_TYPES_VENDOR_ID != FLEXIO_I2C_IP_CFGDEFINES_VENDOR_ID)
    #error "Flexio_I2c_Ip_Types.h and Flexio_I2c_Ip_CfgDefines.h have different vendor ids"
#endif
#if (( FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip_Types.h and Flexio_I2c_Ip_CfgDefines.h are different"
#endif
#if (( FLEXIO_I2C_IP_TYPES_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_SW_MINOR_VERSION != FLEXIO_I2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_SW_PATCH_VERSION != FLEXIO_I2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_Types.h and Flexio_I2c_Ip_CfgDefines.h are different"
#endif

/* Checks against Flexio_I2c_Ip_Callbacks.h */
#if (FLEXIO_I2C_IP_TYPES_VENDOR_ID != FLEXIO_I2C_IP_CALLBACKS_VENDOR_ID)
    #error "Flexio_I2c_Ip_Types.h and Flexio_I2c_Ip_Callbacks.h have different vendor ids"
#endif
#if (( FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip_Types.h and Flexio_I2c_Ip_Callbacks.h are different"
#endif
#if (( FLEXIO_I2C_IP_TYPES_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CALLBACKS_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_SW_MINOR_VERSION != FLEXIO_I2C_IP_CALLBACKS_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_TYPES_SW_PATCH_VERSION != FLEXIO_I2C_IP_CALLBACKS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_Types.h and Flexio_I2c_Ip_Callbacks.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Flexio_I2c_Ip_Types.h file and Std_Types.h file are of the same Autosar version */
    #if ((FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION  != STD_AR_RELEASE_MAJOR_VERSION)    || \
         (FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION   != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_I2c_Ip_Types.h and Std_Types.h are different"
    #endif
#endif

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/
/** @brief Type of FLEXIO I2C transfer status.
 */
 typedef enum
{
    /** I2C specific error codes */
    FLEXIO_I2C_IP_SUCCESS_STATUS                     = 0x000U,
    FLEXIO_I2C_IP_ERROR_STATUS                       = 0x001U,
    FLEXIO_I2C_IP_BUSY_STATUS                        = 0x002U,
    FLEXIO_I2C_IP_RECEIVED_NACK_STATUS               = 0x003U,  /**< NACK signal received  */
    FLEXIO_I2C_IP_TX_UNDERRUN_STATUS                 = 0x004U,  /**< TX underrun error */
    FLEXIO_I2C_IP_RX_OVERRUN_STATUS                  = 0x005U,  /**< RX overrun error */
    FLEXIO_I2C_IP_ARBITRATION_LOST_STATUS            = 0x006U,  /**< Arbitration lost */
    FLEXIO_I2C_IP_ABORTED_STATUS                     = 0x007U,  /**< A transfer was aborted */
    FLEXIO_I2C_IP_BUS_BUSY_STATUS                    = 0x008U,  /**< I2C bus is busy, cannot start transfer */
    FLEXIO_I2C_IP_TIMEOUT_STATUS                     = 0x009U,
    FLEXIO_I2C_IP_UNSUPPORTED_STATUS                 = 0x00AU,
    FLEXIO_I2C_IP_DMA_ERROR_STATUS                   = 0x00BU
}Flexio_I2c_Ip_StatusType;

/** @brief Type of FLEXIO I2C transfer (based on interrupts or DMA).
 */
typedef enum
{
   FLEXIO_I2C_USING_DMA         = 0,    /**< The driver will use DMA to perform flexio I2C transfer */
   FLEXIO_I2C_USING_INTERRUPTS  = 1,    /**< The driver will use interrupts to perform flexio I2C transfer */
} Flexio_I2c_Ip_AsyncTransferType;


/** @brief Driver type: timer decrement
 */
typedef enum
{
    FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_1        = 0U,  /**< Decrement counter on FlexIO clock, Shift clock equals Timer output */
    FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_16       = 4U,  /**< Decrement counter on FlexIO clock divided by 16, Shift clock equals Timer output */
    FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_256      = 5U,  /**< Decrement counter on FlexIO clock divided by 256, Shift clock equals Timer output. */
} Flexio_I2c_Ip_Timer_Decrement;

/** @brief Driver type: interrupts/polling/DMA
 */
typedef enum
{
    FLEXIO_I2C_IP_DRIVER_TYPE_INTERRUPTS    = 1U,  /**< Driver uses interrupts for data transfers */
    FLEXIO_I2C_IP_DRIVER_TYPE_POLLING       = 2U,  /**< Driver is based on polling */
    FLEXIO_I2C_IP_DRIVER_TYPE_DMA           = 0U,  /**< Driver uses DMA for data transfers */
} Flexio_Ip_DriverType;
/*******************************************************************************
 * Struct
 ******************************************************************************/

 /*! @cond DRIVER_INTERNAL_USE_ONLY */

/**
 * FlexIO common context structure
 * This is a common structure used by all FlexIO drivers as a part of their context structure.
 * It is needed for common operations such as interrupt handling.
 */
typedef struct
{
    uint8 Instance;          /**< FlexIO device instance number */
    uint8 ResourceCount;      /**< Count of internal resources used (shifters and timers) */
    uint8 ResourceIndex;      /**< Index of first used internal resource instance (shifter and timer) */
} Flexio_I2c_Ip_CommonStateType;

/*! @endcond */
 
/**
 * @brief Master internal context structure
 *
 * This structure is used by the driver for its internal logic. It must
 * be provided by the application through the FLEXIO_I2C_DRV_MasterInit() function, then
 * it cannot be freed until the driver is de-initialized using FLEXIO_I2C_DRV_MasterDeinit().
 * The application should make no assumptions about the content of this structure.
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    Flexio_I2c_Ip_CommonStateType FlexioCommon;         /**< Common flexio drivers structure */
    const uint8 *TxData;                                /**< Transmit buffer */
    uint8 *RxData;                                      /**< Receive buffer */
    uint32 TxRemainingBytes;                            /**< Number of remaining bytes to be transmitted */
    uint32 RxRemainingBytes;                            /**< Number of remaining bytes to be received */
    uint32 DmaRxChannel;                                /**< Rx DMA channel number */
    uint32 DmaTxChannel;                                /**< Tx DMA channel number */
    Flexio_I2c_Ip_MasterCallbackType Callback;          /**< User callback function */
    uint8 CallbackParam;                                /**< Parameter for the callback function */
    uint16 SlaveAddress;                                /**< Slave address */
    uint16 EventCount;                                  /**< Number of timer events, needed for long transfers */
    Flexio_Ip_DriverType DriverType;                    /**< Driver type: interrupts/polling/DMA */
    Flexio_I2c_Ip_AsyncTransferType I2cAsyncMethod;     /**<*< Driver type: interrupts/polling/DMA */
    Flexio_I2c_Ip_StatusType Status;                    /**< Current status of the driver */
    boolean Receive;                                    /**< Transfer direction, true = receive, false = transmit */
    boolean AddrReceived;                               /**< Indicated start of receive (after address transmission) */
    boolean DriverIdle;                                 /**< Idle/busy state of the driver */
    boolean Blocking;                                   /**< Specifies if the current transfer is blocking */
    boolean SendStop;                                   /**< Specifies if STOP condition must be generated after current transfer */
    uint8 SdaPin;                                       /**< Flexio pin to use as I2C SDA pin */
    uint8 SclPin;                                       /**< Flexio pin to use as I2C SCL pin */
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    uint8 TimerChannelDMA;                              /**< Flexio channel to use for optimize DMA */
    uint8 SclAddChannel;                                /**< Flexio channel to use for optimize DMA */
    uint8 SdaAddChannel;                                /**< Flexio channel to use for optimize DMA */
#endif
    uint8 DummyDmaIdle;                                 /**< Dummy location for DMA transfers */
    uint8 DummyDmaStop;                                 /**< Dummy location for DMA transfers */
    uint8 DummyDmaReceive;                              /**< Dummy location for DMA transfers */
    uint8 DmaReceiveTxStop0;                            /**< Stores setting for setting Tx shifter stop bit to 0 */
    uint8 DmaReceiveTxStop1;                            /**< Stores setting for setting Tx shifter stop bit to 1 */
    uint8 DmaReceiveRxStop1;                            /**< Stores setting for setting Rx shifter stop bit to 1 */
    uint8 LastReload;                                   /**< Counter value for the last timer reload. */
    uint8 CmpValue;
    Flexio_I2c_Ip_Timer_Decrement PrescaleValue;
/*! @endcond */
}Flexio_I2c_Ip_MasterStateType;

/**
 * @brief Master configuration structure
 *
 * This structure is used to provide configuration parameters for the flexio_i2c master at initialization time.
 * @implements Flexio_I2c_Ip_MasterConfigType_struct
 */
typedef struct
{
    uint16 SlaveAddress;                                /**< Slave address, 7-bit */
    Flexio_I2c_Ip_AsyncTransferType I2cAsyncMethod;     /**< Driver type: interrupts/polling/DMA */
    uint32 BaudRate;                                    /**< Baud rate in hertz */
    uint8 CmpValue;
    Flexio_I2c_Ip_Timer_Decrement PrescaleValue;
    uint8 SdaPin;                                       /**< Flexio pin to use as I2C SDA pin */
    uint8 SclPin;                                       /**< Flexio pin to use as I2C SCL pin */
    Flexio_I2c_Ip_MasterCallbackType Callback;          /**< User callback function. Note that this function will be
                                                            called from the interrupt service routine, so its
                                                            execution time should be as small as possible. It can be
                                                            NULL if it is not needed */
    uint8 CallbackParam;                                /**< Parameter for the callback function */
    uint8 Instance;  
    uint8 ResourceIndex;                                /**< Index of first used internal resource instance (shifter and timer) */
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    uint8 TimerChannelDMA;                              /**< Timer channel for optimize DMA mode*/
    uint8 SclAddChannel;                                /**< Flexio channel to use for optimize DMA */
    uint8 SdaAddChannel;                                /**< Flexio channel to use for optimize DMA */
#endif
    uint32 DmaRxChannel;                                /**< Rx DMA channel number. Only used in DMA mode */
    uint32 DmaTxChannel;                                /**< Tx DMA channel number. Only used in DMA mode */
    uint8 MasterStateIdx;                               /**< Master state index */
}Flexio_I2c_Ip_MasterConfigType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2C_IP_TYPES_H*/

