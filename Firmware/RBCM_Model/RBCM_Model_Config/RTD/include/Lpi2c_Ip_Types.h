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
#ifndef LPI2C_IP_TYPES_H
#define LPI2C_IP_TYPES_H

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
#include "Std_Types.h"
#include "Lpi2c_Ip_CfgDefines.h"
#include "Lpi2c_Ip_Callbacks.h"
#include "Lpi2c_Ip_Features.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_TYPES_VENDOR_ID                      43
#define LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define LPI2C_IP_TYPES_SW_MAJOR_VERSION               5
#define LPI2C_IP_TYPES_SW_MINOR_VERSION               0
#define LPI2C_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Lpi2c_Ip_CfgDefines.h header file are of the same vendor */
#if (LPI2C_IP_TYPES_VENDOR_ID != LPI2C_IP_CFGDEFINES_VENDOR_ID)
    #error "Lpi2c_Ip_Types.h and Lpi2c_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and Lpi2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_Types.h and Lpi2c_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Lpi2c_Ip_CfgDefines.h header file are of the same Software version */
#if ((LPI2C_IP_TYPES_SW_MAJOR_VERSION != LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (LPI2C_IP_TYPES_SW_MINOR_VERSION != LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (LPI2C_IP_TYPES_SW_PATCH_VERSION != LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_Types.h and Lpi2c_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Lpi2c_Ip_Callbacks.h header file are of the same vendor */
#if (LPI2C_IP_TYPES_VENDOR_ID != LPI2C_IP_CALLBACKS_VENDOR_ID)
    #error "Lpi2c_Ip_Types.h and Lpi2c_Ip_Callbacks.h have different vendor ids"
#endif

/* Check if current file and Lpi2c_Ip_Callbacks.h header file are of the same Autosar version */
#if ((LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPI2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_Types.h and Lpi2c_Ip_Callbacks.h are different"
#endif

/* Check if current file and Lpi2c_Ip_Callbacks.h header file are of the same Software version */
#if ((LPI2C_IP_TYPES_SW_MAJOR_VERSION != LPI2C_IP_CALLBACKS_SW_MAJOR_VERSION) || \
     (LPI2C_IP_TYPES_SW_MINOR_VERSION != LPI2C_IP_CALLBACKS_SW_MINOR_VERSION) || \
     (LPI2C_IP_TYPES_SW_PATCH_VERSION != LPI2C_IP_CALLBACKS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_Types.h and Lpi2c_Ip_Callbacks.h are different"
#endif

/* Check if current file and Lpi2c_Ip_Features.h header file are of the same vendor */
#if (LPI2C_IP_TYPES_VENDOR_ID !=  LPI2C_IP_FEATURES_VENDOR_ID)
    #error "Lpi2c_Ip_Types.h and Lpi2c_Ip_Features.h have different vendor ids"
#endif

/* Check if current file and Lpi2c_Ip_Features.h header file are of the same Autosar version */
#if ((LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    !=  LPI2C_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    !=  LPI2C_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION !=  LPI2C_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_Types.h and Lpi2c_Ip_Features.h are different"
#endif

/* Check if current file and Lpi2c_Ip_Features.h header file are of the same Software version */
#if ((LPI2C_IP_TYPES_SW_MAJOR_VERSION !=  LPI2C_IP_FEATURES_SW_MAJOR_VERSION) || \
     (LPI2C_IP_TYPES_SW_MINOR_VERSION !=  LPI2C_IP_FEATURES_SW_MINOR_VERSION) || \
     (LPI2C_IP_TYPES_SW_PATCH_VERSION !=  LPI2C_IP_FEATURES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_Types.h and Lpi2c_Ip_Features.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if ((LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Lpi2c_Ip_Types.h and Std_Types.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*==================================================================================================
 *                                        DEFINITIONS
 ==================================================================================================*/

/* The request flags from controller */
#define LPI2C_IP_FLAG_CONTROLLER_STATUS_REQUEST    (LPI2C_MSR_DMF_MASK  | \
                                                    LPI2C_MSR_PLTF_MASK | \
                                                    LPI2C_MSR_FEF_MASK  | \
                                                    LPI2C_MSR_ALF_MASK  | \
                                                    LPI2C_MSR_NDF_MASK  | \
                                                    LPI2C_MSR_SDF_MASK  | \
                                                    LPI2C_MSR_EPF_MASK)

/* The request flags from target */
#define LPI2C_IP_FLAG_TARGET_STATUS_REQUEST    (LPI2C_SSR_FEF_MASK  | \
                                                LPI2C_SSR_BEF_MASK  | \
                                                LPI2C_SSR_SDF_MASK  | \
                                                LPI2C_SSR_RSF_MASK)

/** @cond DRIVER_INTERNAL_USE_ONLY */
/** Size of the master command queue. Worst case: 5 commands in High-Speed receive with 10-bit address:
   START + master code, REP START + addr_1 + tx, addr_2, REP START + addr_1 + rx, receive command */
#define LPI2C_MASTER_CMD_QUEUE_SIZE   5U
/** @endcond */

/*==================================================================================================
*                              TYPEDEFS (STRUCTURES, ENUMS)
==================================================================================================*/


/** @brief I2C operating modes
 * @implements Lpi2c_Ip_ModeType_enum
 */
typedef enum
{
    LPI2C_STANDARD_MODE      = 0x0U,   /**< Standard-mode (Sm), bidirectional data transfers up to 100 kbit/s */
    LPI2C_FAST_MODE          = 0x1U,   /**< Fast-mode (Fm), bidirectional data transfers up to 400 kbit/s */
    LPI2C_FASTPLUS_MODE      = 0x2U,   /**< Fast-mode Plus (Fm+), bidirectional data transfers up to 1 Mbit/s */
    LPI2C_HIGHSPEED_MODE     = 0x3U,   /**< High-speed Mode (Hs-mode), bidirectional data transfers up to 3.4 Mbit/s */
#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
    LPI2C_ULTRAFAST_MODE     = 0x4U    /**< Ultra Fast Mode (UFm), unidirectional data transfers up to 5 Mbit/s */
#endif
} Lpi2c_Ip_ModeType;

/** @brief Type of LPI2C transfer (based on interrupts or DMA).
 * @implements Lpi2c_Ip_AsyncTransferType_enum
 */
typedef enum
{
   LPI2C_USING_DMA         = 0,    /**< The driver will use DMA to perform I2C transfer */
   LPI2C_USING_INTERRUPTS  = 1,    /**< The driver will use interrupts to perform I2C transfer */
} Lpi2c_Ip_AsyncTransferType;

/** @brief Type of LPI2C transfer (based on interrupts or DMA).
 */
typedef enum
{
    /** I2C specific error codes */
    LPI2C_IP_SUCCESS_STATUS                     = 0x000U,
    LPI2C_IP_ERROR_STATUS                       = 0x001U,
    LPI2C_IP_BUSY_STATUS                        = 0x002U,
    LPI2C_IP_RECEIVED_NACK_STATUS               = 0x003U,  /**< NACK signal received  */
    LPI2C_IP_TX_UNDERRUN_STATUS                 = 0x004U,  /**< TX underrun error */
    LPI2C_IP_RX_OVERRUN_STATUS                  = 0x005U,  /**< RX overrun error */
    LPI2C_IP_ARBITRATION_LOST_STATUS            = 0x006U,  /**< Arbitration lost */
    LPI2C_IP_ABORTED_STATUS                     = 0x007U,  /**< A transfer was aborted */
    LPI2C_IP_BUS_BUSY_STATUS                    = 0x008U,  /**< I2C bus is busy, cannot start transfer */
    LPI2C_IP_TIMEOUT_STATUS                     = 0x009U,
    LPI2C_IP_UNSUPPORTED_STATUS                 = 0x00AU,
    LPI2C_IP_DMA_ERROR_STATUS                   = 0x00BU
}Lpi2c_Ip_StatusType;


/**
 * @brief Defines the example structure
 *
 * This structure is used as an example.
 */

 /** @brief LPI2C master prescaler options
 */
typedef enum
{
    LPI2C_MASTER_PRESC_DIV_1    = 0U,  /**< Divide by 1   */
    LPI2C_MASTER_PRESC_DIV_2    = 1U,  /**< Divide by 2   */
    LPI2C_MASTER_PRESC_DIV_4    = 2U,  /**< Divide by 4   */
    LPI2C_MASTER_PRESC_DIV_8    = 3U,  /**< Divide by 8   */
    LPI2C_MASTER_PRESC_DIV_16   = 4U,  /**< Divide by 16  */
    LPI2C_MASTER_PRESC_DIV_32   = 5U,  /**< Divide by 32  */
    LPI2C_MASTER_PRESC_DIV_64   = 6U,  /**< Divide by 64  */
    LPI2C_MASTER_PRESC_DIV_128  = 7U,  /**< Divide by 128 */
} Lpi2c_Ip_MasterPrescalerType;


/**
 * @brief Baud rate structure
 *
 * This structure is used for setting or getting the baud rate.
 * @implements Lpi2c_Ip_BaudRateType_struct
 */
typedef struct
{
    Lpi2c_Ip_MasterPrescalerType Prescaler;
    uint32 ClkHI;
    uint32 ClkLO;
    uint32 SetHold;
    uint32 DataValid;
#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
    uint32 ClkHIHS;
    uint32 ClkLOHS;
    uint32 SetHoldHS;
    uint32 DataValidHS;
#endif
} Lpi2c_Ip_BaudRateType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/** LPI2C master commands */
typedef enum
{
    LPI2C_MASTER_COMMAND_TRANSMIT         = 0U,  /**< Transmit DATA[7:0] */
    LPI2C_MASTER_COMMAND_RECEIVE          = 1U,  /**< Receive (DATA[7:0] + 1) bytes */
    LPI2C_MASTER_COMMAND_STOP             = 2U,  /**< Generate STOP condition */
    LPI2C_MASTER_COMMAND_RECEIVE_DISCARD  = 3U,  /**< Receive and discard (DATA[7:0] + 1) bytes */
    LPI2C_MASTER_COMMAND_START            = 4U,  /**< Generate START and transmit address in DATA[7:0] */
    LPI2C_MASTER_COMMAND_START_NACK       = 5U,  /**< Generate START and transmit address in DATA[7:0], expect a NACK to be returned */
    LPI2C_MASTER_COMMAND_START_HS         = 6U,  /**< Generate START and transmit address in DATA[7:0] in high speed mode */
    LPI2C_MASTER_COMMAND_START_NACK_HS    = 7U,  /**< Generate START and transmit address in DATA[7:0] in high speed mode, expect a NACK to be returned */
} Lpi2c_Ip_MasterCommandType;
/** @endcond */

/** @cond DRIVER_INTERNAL_USE_ONLY */
/* Master software command queue */
typedef struct
{
    Lpi2c_Ip_MasterCommandType Cmd[LPI2C_MASTER_CMD_QUEUE_SIZE];
    uint8 Data[LPI2C_MASTER_CMD_QUEUE_SIZE];
    uint8 WriteIdx;
    uint8 ReadIdx;
}Lpi2c_Ip_MasterCmdQueueType;
/** @endcond */

typedef enum
{
    LPI2C_IP_SEND = 0x00U,    /**< Send operation */
    LPI2C_IP_RECEIVE = 0x01U  /**< Receive operation */
}Lpi2c_Ip_DirectionType;


/**
 * @brief Master internal context structure
 *
 * This structure is used by the master-mode driver for its internal logic. It must
 * be provided by the application through the LPI2C_DRV_MasterInit() function, then
 * it cannot be freed until the driver is de-initialized using LPI2C_DRV_MasterDeinit().
 * The application should make no assumptions about the content of this structure.
 */
typedef struct
{
/** @cond DRIVER_INTERNAL_USE_ONLY */
    Lpi2c_Ip_MasterCmdQueueType CmdQueue;            /**< Software queue for commands, when LPI2C FIFO is not big enough */
    uint32 BufferSize;                               /**< Size of tx/rx buffer */
    uint8 * DataBuffer;
    uint32 ByteReceiveCount;                         /**< Number of receive bytes */
    Lpi2c_Ip_DirectionType Direction;                /**< Specifies the direction of the transfer, send or receive */
    volatile Lpi2c_Ip_StatusType Status;             /**< Status of last driver operation */
    Lpi2c_Ip_ModeType OperatingMode;                 /**< I2C Operating mode */
    uint16 SlaveAddress;                             /**< Slave address */
    volatile boolean I2cIdle;                        /**< Idle/busy state of the driver */
    uint8 MasterCode;                                /**< Master code for High-speed mode */
    boolean HighSpeedInProgress;                     /**< High-speed communication is in progress */
    boolean SendStop;                                /**< Specifies if STOP condition must be generated after current transfer */
    boolean Is10bitAddr;                             /**< Selects 7-bit or 10-bit slave address */
    Lpi2c_Ip_AsyncTransferType TransferType;         /**< Type of LPI2C transfer */
    uint32 DmaTxChannel;                             /**< Channel number for DMA Tx channel */
    uint32 DmaRxChannel;                             /**< Channel number for DMA Rx channel */
    Lpi2c_Ip_MasterCallbackType MasterCallback;      /**< Master callback function */
    uint8 CallbackParam;                             /**< Parameter for the master callback function */
    const Lpi2c_Ip_BaudRateType * BaudrateParams;    /**< Baud rate in Hz*/
/** @endcond */
} Lpi2c_Ip_MasterStateType;


 /**
 * @brief Master configuration structure
 *
 * This structure is used to provide configuration parameters for the LPI2C master at initialization time.
 * @implements Lpi2c_Ip_MasterConfigType_struct
 */
typedef struct
{
    uint16 SlaveAddress;                              /**< Slave address, 7-bit or 10-bit */
    boolean Is10bitAddr;                              /**< Selects 7-bit or 10-bit slave address */
    Lpi2c_Ip_ModeType OperatingMode;                  /**< I2C Operating mode */
    const Lpi2c_Ip_BaudRateType * BaudrateParams;     /**< Baud rate in Hz*/
    uint32 PinLowTimeout;                          /**< Pin Low Timeout */
    uint32 BusIdleTimeout;                         /**< Bus Idle Timeout */
    uint32 GlitchFilterSDA;                        /**< SDA glitch filter */
    uint32 GlitchFilterSCL;                        /**< SCL glitch filter */
    uint8 MasterCode;                                 /**< Master code for High-speed mode. Valid range: 0-7. Unused in other operating modes */
    Lpi2c_Ip_AsyncTransferType TransferType;          /**< Type of LPI2C transfer */
    uint32 DmaTxChannel;                              /**< Channel number for DMA Tx channel. If DMA mode isn't used this field will be ignored. */
    uint32 DmaRxChannel;                              /**< Channel number for DMA Rx channel. If DMA mode isn't used this field will be ignored. */
    Lpi2c_Ip_MasterCallbackType MasterCallback;       /**< Master callback function. Note that this function will be
                                                            called from the interrupt service routine at the end of a transfer,
                                                            so its execution time should be as small as possible. It can be
                                                            NULL if you want to check manually the status of the transfer. */
    uint8 CallbackParam;                              /**< Parameter for the master callback function */
    uint8 MasterStateIdx;                             /**< Master State index*/
} Lpi2c_Ip_MasterConfigType;

/**
 * @brief Slave internal context structure
 *
 * This structure is used by the slave-mode driver for its internal logic. It must
 * be provided by the application through the LPI2C_DRV_SlaveInit() function, then
 * it cannot be freed until the driver is de-initialized using LPI2C_DRV_SlaveDeinit().
 * The application should make no assumptions about the content of this structure.
 */
typedef struct
{
/** @cond DRIVER_INTERNAL_USE_ONLY */
    Lpi2c_Ip_StatusType Status;                     /**< The I2C slave status */
    volatile boolean IsTransferInProgress;          /**< Slave is busy because of an ongoing transfer */
    uint32 BufferSize;                              /**< Size of tx/rx buffer */
    uint8 * DataBuffer;                             /**< Pointer to data buffer */
    Lpi2c_Ip_ModeType OperatingMode;                /**< I2C Operating mode */
    boolean Is10bitAddress;                         /**< Specifies if 10-bit or 7-bit address */
    uint8 RepeatedStarts;                           /**< Specifies the number of repeated starts */
    boolean SlaveListening;                         /**< Specifies if slave is in listening mode */
    boolean TxUnderrunWarning;                      /**< Possible slave tx underrun */
    Lpi2c_Ip_AsyncTransferType TransferType;        /**< Type of LPI2C transfer */
    uint32 DmaTxChannel;                            /**< Channel number for TX DMA channel */
    uint32 DmaRxChannel;                            /**< Channel number for RX DMA channel */
    Lpi2c_Ip_SlaveCallbackType SlaveCallback;       /**< Slave callback function */
    uint8 CallbackParam;                            /**< Parameter for the slave callback function */
    Lpi2c_Ip_DirectionType Direction;               /**< Specifies the direction of the transfer, send or receive */
/** @endcond */
} Lpi2c_Ip_SlaveStateType;


/**
 * @brief Slave configuration structure
 *
 * This structure is used to provide configuration parameters for the LPI2C slave at initialization time.
 * @implements Lpi2c_Ip_SlaveConfigType_struct
 */
typedef struct
{
    uint16 SlaveAddress;                            /**< Slave address, 7-bit or 10-bit */
    boolean Is10bitAddr;                            /**< Selects 7-bit or 10-bit slave address */
    boolean SlaveListening;                         /**<Specifies if slave is in listening mode */
    Lpi2c_Ip_ModeType OperatingMode;                /**< I2C Operating mode */
    Lpi2c_Ip_AsyncTransferType TransferType;        /**< Type of LPI2C transfer */
    uint32 GlitchFilterSDA;                         /**< SDA glitch filter */
    uint32 GlitchFilterSCL;                         /**< SCL glitch filter */
    uint32 DmaTxChannel;                            /**< Channel number for DMA tx channel. If DMA mode isn't used this field will be ignored. */
    uint32 DmaRxChannel;                            /**< Channel number for DMA rx channel. If DMA mode isn't used this field will be ignored. */
    Lpi2c_Ip_SlaveCallbackType SlaveCallback;       /**< Slave callback function. Note that this function will be
                                                        called from the interrupt service routine, so its
                                                        execution time should be as small as possible. It can be
                                                        NULL if the slave is not in listening mode
                                                        (slaveListening = false) */
    uint8 CallbackParam;                            /**< Parameter for the slave callback function */
    uint8 SlaveStateIdx;                            /**< Slave State index*/
} Lpi2c_Ip_SlaveConfigType;

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* LPI2C_IP_TYPES_H */

