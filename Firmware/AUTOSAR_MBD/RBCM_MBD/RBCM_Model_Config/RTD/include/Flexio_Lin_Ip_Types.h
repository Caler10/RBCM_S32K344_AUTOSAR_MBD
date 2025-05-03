/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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

#ifndef FLEXIO_LIN_IP_TYPES_H
#define FLEXIO_LIN_IP_TYPES_H

/**
*   @file Flexio_Lin_Ip_Types.h
*
*   @addtogroup FLEXIO_IP
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
#include "Flexio_Lin_Ip_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_LIN_IP_TYPES_VENDOR_ID                    43
#define FLEXIO_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_LIN_IP_TYPES_SW_MAJOR_VERSION             5
#define FLEXIO_LIN_IP_TYPES_SW_MINOR_VERSION             0
#define FLEXIO_LIN_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (FLEXIO_LIN_IP_TYPES_VENDOR_ID != FLEXIO_LIN_IP_DEFINES_VENDOR_ID)
    #error "Flexio_Lin_Ip_Types.h and Flexio_Lin_Ip_Defines.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip_Defines header file are of the same Autosar version */
#if ((FLEXIO_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION != FLEXIO_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION != FLEXIO_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_LIN_IP_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip_Types.h and Flexio_Lin_Ip_Defines.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip_Defines header file are of the same Software version */
#if ((FLEXIO_LIN_IP_TYPES_SW_MAJOR_VERSION != FLEXIO_LIN_IP_DEFINES_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_TYPES_SW_MINOR_VERSION != FLEXIO_LIN_IP_DEFINES_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_TYPES_SW_PATCH_VERSION != FLEXIO_LIN_IP_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip_Types.h and Flexio_Lin_Ip_Defines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
 * @brief Macro that specifies usage of a SLAVE note
 *
 * @details This macro is used in user configuration structure to set the node type as SLAVE.
 *
 */
#define FLEXIO_LIN_IP_SLAVE  (0U)

/**
 * @brief Macro that specifies usage of a SLAVE note
 *
 * @details This macro is used in user configuration structure to set the node type as MASTER.
 *
 */
#define FLEXIO_LIN_IP_MASTER (1U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/*!
 * @brief Defines types for an enumerating event related to an Identifier.
 */
typedef enum
{
    FLEXIO_LIN_IP_NO_EVENT                = 0x00U,    /**< @brief No event */
    FLEXIO_LIN_IP_WAKEUP_SIGNAL           = 0x01U,    /**< @brief Wakeup signal detected */
    FLEXIO_LIN_IP_BAUDRATE_ADJUSTED       = 0x02U,    /**< @brief Baudrate adjusted */
    FLEXIO_LIN_IP_RECV_BREAK_FIELD_OK     = 0x03U,    /**< @brief Break field received */
    FLEXIO_LIN_IP_SEND_HEADER_OK          = 0x04U,
    FLEXIO_LIN_IP_SYNC_ERROR              = 0x05U,    /**< @brief Sync byte received with errors */
    FLEXIO_LIN_IP_RECV_HEADER_OK          = 0x06U,    /**< @brief PID byte received ok */
    FLEXIO_LIN_IP_PID_ERROR               = 0x07U,    /**< @brief PID byte received with errors */
    FLEXIO_LIN_IP_TX_UNDERRUN_ERROR       = 0x08U,    /**< @brief Tx underrun error */
    FLEXIO_LIN_IP_READBACK_ERROR          = 0x09U,    /**< @brief Readback error */
    FLEXIO_LIN_IP_CHECKSUM_ERROR_EVENT    = 0x0AU,    /**< @brief CheckSum error */
    FLEXIO_LIN_IP_TX_COMPLETED            = 0x0BU,    /**< @brief Tx completed */
    FLEXIO_LIN_IP_RX_COMPLETED            = 0x0CU,    /**< @brief Rx completed */
    FLEXIO_LIN_IP_RX_OVERRUN_ERROR        = 0x0DU,     /**< @brief Rx overrun error */
    FLEXIO_LIN_IP_TIMEOUT_ERROR           = 0x0EU     /**< @brief Timeout error */
} Flexio_Lin_Ip_EventIdType;

/*!
 * @brief Define type for an enumerating LIN Node state.
 */
typedef enum
{
    FLEXIO_LIN_IP_NODE_STATE_UNINIT                 = 0x00U,    /**< @brief Uninitialized state */
    FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE             = 0x01U,    /**< @brief Sleep mode state */
    FLEXIO_LIN_IP_NODE_STATE_IDLE                   = 0x02U,    /**< @brief Idle state */
    FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD       = 0x03U,    /**< @brief Send break field state */
    FLEXIO_LIN_IP_NODE_STATE_RECV_SYNC              = 0x04U,    /**< @brief Receive the synchronization byte state */
    FLEXIO_LIN_IP_NODE_STATE_SEND_PID               = 0x05U,    /**< @brief Send PID state */
    FLEXIO_LIN_IP_NODE_STATE_RECV_PID               = 0x06U,    /**< @brief Receive PID state */
    FLEXIO_LIN_IP_NODE_STATE_RECV_DATA              = 0x07U,    /**< @brief Receive data state */
    FLEXIO_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED    = 0x08U,    /**< @brief Receive data completed state */
    FLEXIO_LIN_IP_NODE_STATE_SEND_DATA              = 0x09U,    /**< @brief Send data state */
    FLEXIO_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED    = 0x0AU,     /**< @brief Send data completed state */
    FLEXIO_LIN_IP_NODE_STATE_SEND_SYNC              = 0x0BU     /**< @brief Send data completed state */

} Flexio_Lin_Ip_NodeStateType;

/*!
 * @brief Define type function possible return values.
 * @implements Flexio_Lin_Ip_StatusType_enum
 */
typedef enum
{
    FLEXIO_LIN_IP_STATUS_SUCCESS = 0x00U,
    FLEXIO_LIN_IP_STATUS_ERROR,
    FLEXIO_LIN_IP_STATUS_BUSY
} Flexio_Lin_Ip_StatusType;

/*!
 * @brief Define type for check sum type of the frame.
 * @implements Flexio_Lin_Ip_FrameCsModelType_enum
 */
typedef enum
{
    FLEXIO_LIN_IP_ENHANCED_CS,    /**< @brief Enhanced CheckSum model.*/
    FLEXIO_LIN_IP_CLASSIC_CS      /**< @brief Classic CheckSum model.*/
} Flexio_Lin_Ip_FrameCsModelType;


/*!
 * @brief Define type of the response part of frame.
 * @implements Flexio_Lin_Ip_FrameResponseType_enum
 */
typedef enum
{
    FLEXIO_LIN_IP_FRAMERESPONSE_TX,     /**< @brief Response is generated from this node*/
    FLEXIO_LIN_IP_FRAMERESPONSE_RX,     /**< @brief Response is generated from another node and is relevant for this node. */
    FLEXIO_LIN_IP_FRAMERESPONSE_IGNORE  /**< @brief Response is generated from another node and is irrelevant for this node */
} Flexio_Lin_Ip_FrameResponseType;

/*!
 * @brief Description: This type defines a range of transfer status.
 * @implements Flexio_Lin_Ip_TransferStatusType_enum
 */
typedef enum
{
    FLEXIO_LIN_IP_STATUS_FAIL = 0x00,           /**< @brief Command has not been accepted . */
    FLEXIO_LIN_IP_STATUS_TX_OK,                 /**< @brief Master: Header or Response successful transmission. Slave: Response successful transmission.*/
    FLEXIO_LIN_IP_STATUS_TX_BUSY,               /**< @brief Master: Ongoing transmission (Header or Response). Slave: Ongoing transmission response.*/
    FLEXIO_LIN_IP_STATUS_TX_HEADER_ERROR,       /**< @brief Master: Erroneous header transmission such as: Mismatch between sent and read back data or Physical bus error.*/
    FLEXIO_LIN_IP_STATUS_TX_ERROR,              /**< @brief Master or Slave: Erroneous response transmission such as mismatch between sent and read back data, Physical bus error.*/
    FLEXIO_LIN_IP_STATUS_RX_OK,                 /**< @brief Master or Slave: Reception of correct response.*/
    FLEXIO_LIN_IP_STATUS_RX_BUSY,               /**< @brief Master or Slave: Ongoing reception. At least one response byte has been received, but the checksum byte has not been received.*/
    FLEXIO_LIN_IP_STATUS_RX_ERROR,              /**< @brief Master or Slave: Erroneous response reception such as: - Framing error - Overrun error - Checksum error or Short response(timeout occurred).*/
    FLEXIO_LIN_IP_STATUS_RX_NO_RESPONSE,        /**< @brief Master or Slave: No response byte has been received so far(timeout occurred).*/
    FLEXIO_LIN_IP_STATUS_RX_HEADER_OK,          /**< @brief Slave: Reception of correct header.*/
    FLEXIO_LIN_IP_STATUS_RX_HEADER_BUSY,       /**< @brief Slave: Ongoing header reception.*/
    FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR,       /**< @brief Slave: Erroneous header reception such as: Break field error, Sync field error, Identifier parity error, Framing error, timeout occurred or Physical bus error.*/
    FLEXIO_LIN_IP_STATUS_OPERATIONAL,           /**< @brief Normal operation; there is no data has been sent or received after channel initialized or switched to IDLE from SLEEP.*/
    FLEXIO_LIN_IP_STATUS_SLEEP                  /**< @brief Sleep state operation. */
} Flexio_Lin_Ip_TransferStatusType;
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This Type is used to provide PID, checksum model, response type of the frame, data length and SDU pointer from the LIN Interface to the Flexio Lin Ip driver.
 * @implements Flexio_Lin_Ip_PduType_structure
 */
typedef struct
{
    uint8 Pid;                              /**< @brief LIN frame identifier. */
    Flexio_Lin_Ip_FrameCsModelType Cs;      /**< @brief Checksum model type */
    Flexio_Lin_Ip_FrameResponseType Drc;    /**< @brief Response type */
    uint8 Dl;                               /**< @brief Data length */
    uint8*  SduPtr;                         /**< @brief Pointer to Sdu */
} Flexio_Lin_Ip_PduType;

/**
 *
 * @brief Flexio Lin Ip driver state structure type. It is internal for the driver use only.
 * Implements : Flexio_Lin_Ip_StateStructType_Class
 */
typedef struct
{
    uint8 CntByte;                                            /**< @brief To count number of bytes already transmitted or received. */
    uint8 CheckSum;                                           /**< @brief CheckSum byte. */
    volatile boolean IsBusBusy;                                /**< @brief True if there are data, frame headers being transferred on bus */
    uint8 * SduBuf;                                           /**< @brief The buffer of received data. */
    volatile uint8 Dl;                                    /**< @brief The remaining number of bytes to be transmitted. */
    uint8 CurrentId;                                          /**< @brief Current ID */
    uint8 CurrentPid;                                         /**< @brief Current PID */
    Flexio_Lin_Ip_FrameResponseType FrameCommand;
    Flexio_Lin_Ip_FrameCsModelType Cs;                         /**< @brief Current Checksum type */
    volatile Flexio_Lin_Ip_EventIdType CurrentEventId;         /**< @brief Current ID Event */
    volatile Flexio_Lin_Ip_NodeStateType CurrentNodeState;     /**< @brief Current Node state */
    volatile Flexio_Lin_Ip_NodeStateType PreviousNodeState;    /*!< @brief Store previous node state when set Lin channel to idle for further processing.*/
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #if defined(FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION) && defined(FLEXIO_LIN_IP_START_TIMER_NOTIFICATION)
    volatile boolean TimerCounting;                       /*!< @brief This field is set to FALSE in init and after the protocol timeout timer is stopped and it is set to TRUE when timer starts to count..*/
#endif
#endif/*(FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)*/
} Flexio_Lin_Ip_StateStructType;

/**
 * @brief LIN Driver callback function type
 * @implements Flexio_Lin_Ip_CallbackType_pointer
 */
typedef void (*Flexio_Lin_Ip_CallbackType)(const uint8 Instance, const Flexio_Lin_Ip_StateStructType *LinState);

/**
 * @brief Flexio Lin Ip driver User configuration structure type
 * @Implements : Flexio_Lin_Ip_UserConfigType_Class
 */
typedef struct
{
    uint8 Instance;                               /**< @brief Flexio hardware channel for this configuration. */
    uint8 TxShifterId;                            /**< @brief Flexio shifter use for transmission(Tx). */
    uint8 TxTimerId;                              /**< @brief Flexio timer use for transmission(Tx). */
    uint8 TxPin;                                  /**< @brief Flexio pin use for transmission(Tx). */
    uint8 RxShifterId;                            /**< @brief Flexio shifter use for reception(Rx). */
    uint8 RxTimerId;                              /**< @brief Flexio timer use for reception(Rx). */
    uint8 RxPin;                                  /**< @brief Flexio pin use for reception(Rx). */
    uint8 FlexioHwInstance;                       /**< @brief Flexio hardware module number. */
    uint8 MasterBreakLength;                      /**< @brief Number of bits for break length. */
    uint8 SlaveSyncBreakLength;                   /**< @brief Number of bits detected by slave node(break length). */
    uint8 TimerClkSrc;                            /**< @brief Timer clock source */
    uint16 Baudratedivider;                       /**< @brief Baudrate divider. */
    boolean NodeFunction;                         /**< @brief Type of Lin node. It can be Master node or Slave node. */
    Flexio_Lin_Ip_CallbackType Callback;          /**< @brief Callback function to invoke after receiving a byte or transmitting a byte. */
    Flexio_Lin_Ip_StateStructType *StateStruct;   /**< @brief Pointer for the internal state structure of the driver. */
    uint32 Baudrate;                              /**< @brief Baudrate value configured. */
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
#ifdef FLEXIO_LIN_IP_START_TIMER_NOTIFICATION
    uint32 HeaderTimeoutValue;                    /**< @brief Header timeout duration(in bit time) converted to micro seconds. */
    uint32 ResponseTimeoutValue;                  /**< @brief Response timeout duration(in bit time) for 1 byte converted to micro seconds. */
#endif
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
    uint8 WakeupByte;                             /**< @brief Byte will be sent to generate wakeup pulse [450us->5ms] */
    uint8 BaseWakeupByteDetectInverted;           /**< @brief Byte use to check detection of wake up pulse longer than 150us */
} Flexio_Lin_Ip_UserConfigType;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_LIN_IP_TYPES_H */
