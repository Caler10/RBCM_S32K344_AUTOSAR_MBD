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

#ifndef LPUART_LIN_IP_TYPESS_H
#define LPUART_LIN_IP_TYPESS_H

/**
*   @file   Lpuart_Lin_Ip_Types.h
*
*   @defgroup lpuart_lin_ip Lpuart Lin IPL
*   @addtogroup  lpuart_lin_ip Lpuart Lin IPL
*   @{
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
#include "Lpuart_Lin_Ip_Defines.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_TYPES_VENDOR_ID                    43
#define LPUART_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LPUART_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LPUART_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LPUART_LIN_IP_TYPES_SW_MAJOR_VERSION             5
#define LPUART_LIN_IP_TYPES_SW_MINOR_VERSION             0
#define LPUART_LIN_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (LPUART_LIN_IP_TYPES_VENDOR_ID != LPUART_LIN_IP_DEFINES_VENDOR_ID)
    #error "Lpuart_Lin_Ip_Types.h and Lpuart_Lin_Ip_Defines.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Defines header file are of the same Autosar version */
#if ((LPUART_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LPUART_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION != LPUART_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_Types.h and Lpuart_Lin_Ip_Defines.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Defines header file are of the same Software version */
#if ((LPUART_LIN_IP_TYPES_SW_MAJOR_VERSION != LPUART_LIN_IP_DEFINES_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_TYPES_SW_MINOR_VERSION != LPUART_LIN_IP_DEFINES_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_TYPES_SW_PATCH_VERSION != LPUART_LIN_IP_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_Types.h and Lpuart_Lin_Ip_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
 * @brief Macro that specifies usage of a SLAVE note
 *
 * @details This macro is used in user configuration structure to set the node type as SLAVE.
 *
 */
#define LPUART_LIN_IP_SLAVE  (0U)

/**
 * @brief Macro that specifies usage of a SLAVE note
 *
 * @details This macro is used in user configuration structure to set the node type as MASTER.
 *
 */
#define LPUART_LIN_IP_MASTER (1U)

/**
 * @brief Macro LPUART break char length 10 bit times
 *
 * @details LPUART break char length 10 bit times (if M = 0, SBNS = 0)
 * or 11 (if M = 1, SBNS = 0 or M = 0, SBNS = 1) or 12 (if M = 1,
 * SBNS = 1 or M10 = 1, SNBS = 0) or 13 (if M10 = 1, SNBS = 1)
 */
#define LPUART_LIN_IP_BREAK_CHAR_10_BIT_MINIMUM_U8  ((uint8)0x0U)

/**
 * @brief Macro LPUART break char length 10 bit times
 *
 * @details LPUART break char length 13 bit times (if M = 0, SBNS = 0
 * or M10 = 0, SBNS = 1) or 14 (if M = 1, SBNS = 0 or M = 1,
 * SBNS = 1) or 15 (if M10 = 1, SBNS = 1 or M10 = 1, SNBS = 0)
 */
#define LPUART_LIN_IP_BREAK_CHAR_13_BIT_MINIMUM_U8  ((uint8)0x1U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief Enum containing the events related to a ID
 *
 * @details This enum defines types for an enumerating event related to an Identifier.
 *
 * @implements Lpuart_Lin_Ip_EventIdType_enum
 *
 *
 */
typedef enum
{
    LPUART_LIN_IP_NO_EVENT                = 0x00U,    /**< @brief No event */
    LPUART_LIN_IP_WAKEUP_SIGNAL           = 0x01U,    /**< @brief Wakeup signal detected */
    LPUART_LIN_IP_BAUDRATE_ADJUSTED       = 0x02U,    /**< @brief Baudrate adjusted */
    LPUART_LIN_IP_RECV_BREAK_FIELD_OK     = 0x03U,    /**< @brief Break field received */
    LPUART_LIN_IP_SYNC_ERROR              = 0x04U,    /**< @brief Sync byte received with errors */
    LPUART_LIN_IP_SEND_HEADER_OK          = 0x05U,    /**< @brief Sync byte received  ok*/
    LPUART_LIN_IP_RECV_HEADER_OK          = 0x06U,    /**< @brief PID byte received ok */
    LPUART_LIN_IP_PID_ERROR               = 0x07U,    /**< @brief PID byte received with errors */
    LPUART_LIN_IP_FRAME_ERROR             = 0x08U,    /**< @brief Frame transfer has errors */
    LPUART_LIN_IP_READBACK_ERROR          = 0x09U,    /**< @brief Readback error */
    LPUART_LIN_IP_CHECKSUM_ERROR_EVENT    = 0x0AU,    /**< @brief Checksum error */
    LPUART_LIN_IP_TX_COMPLETED            = 0x0BU,    /**< @brief Tx completed */
    LPUART_LIN_IP_RX_COMPLETED            = 0x0CU,    /**< @brief Rx completed */
    LPUART_LIN_IP_RX_OVERRUN_ERROR        = 0x0DU,    /**< @brief Rx overrun error */
    LPUART_LIN_IP_TIMEOUT_ERROR           = 0x0EU     /**< @brief Timeout error */
} Lpuart_Lin_Ip_EventIdType;


/**
 * @brief Define type for an enumerating LIN Node state.
 * @implements Lpuart_Lin_Ip_NodeStateType_enum
 *
 *
 */
typedef enum
{
    LPUART_LIN_IP_NODE_STATE_UNINIT                 = 0x00U,    /**< @brief Uninitialized state */
    LPUART_LIN_IP_NODE_STATE_SLEEP_MODE             = 0x01U,    /**< @brief Sleep mode state */
    LPUART_LIN_IP_NODE_STATE_IDLE                   = 0x02U,    /**< @brief Idle state */
    LPUART_LIN_IP_NODE_STATE_SEND_BREAK_FIELD       = 0x03U,    /**< @brief Send break field state */
    LPUART_LIN_IP_NODE_STATE_SEND_SYNC              = 0x04U,    /**< @brief Send the synchronization byte state */
    LPUART_LIN_IP_NODE_STATE_RECV_SYNC              = 0x05U,    /**< @brief Receive the synchronization byte state */
    LPUART_LIN_IP_NODE_STATE_SEND_PID               = 0x06U,    /**< @brief Send PID state */
    LPUART_LIN_IP_NODE_STATE_RECV_PID               = 0x07U,    /**< @brief Receive PID state */
    LPUART_LIN_IP_NODE_STATE_RECV_DATA              = 0x08U,    /**< @brief Receive data state */
    LPUART_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED    = 0x09U,    /**< @brief Receive data completed state */
    LPUART_LIN_IP_NODE_STATE_SEND_DATA              = 0x0AU,    /**< @brief Send data state */
    LPUART_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED    = 0x0BU     /**< @brief Send data completed state */
} Lpuart_Lin_Ip_NodeStateType;

/**
 * @brief LPUART status type
 * @implements Lpuart_Lin_Ip_StatusType_enum
 */
typedef enum
{
    LPUART_LIN_IP_STATUS_SUCCESS = 0x00,
    LPUART_LIN_IP_STATUS_ERROR,
    LPUART_LIN_IP_STATUS_BUSY
} Lpuart_Lin_Ip_StatusType;

/**
 * @brief Define type for checksum type of the frame.
 * @implements Lpuart_Lin_Ip_FrameCsModelType_enum
 */
typedef enum
{
    LPUART_LIN_IP_ENHANCED_CS,    /**< @brief Enhanced CheckSum model.*/
    LPUART_LIN_IP_CLASSIC_CS      /**< @brief Classic CheckSum model.*/
} Lpuart_Lin_Ip_FrameCsModelType;

/**
 * @brief Define type for Response type of the frame.
 * @implements Lpuart_Lin_Ip_FrameResponseType_enum
 */
typedef enum
{
    LPUART_LIN_IP_FRAMERESPONSE_TX = 0,     /**< @brief Response is generated from this node*/
    LPUART_LIN_IP_FRAMERESPONSE_RX,         /**< @brief Response is generated from another node and is
                                                relevant for this node.*/
    LPUART_LIN_IP_FRAMERESPONSE_IGNORE      /**< @brief Response is generated from another node and is
                                                irrelevant for this node*/
} Lpuart_Lin_Ip_FrameResponseType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*!
 * @brief Define type for an structure containing information regarding the LIN Frame .
 * @implements Lpuart_Lin_Ip_PduType_structure
 */
typedef struct
{
    uint8                               Pid;     /**< @brief LIN frame identifier.*/
    Lpuart_Lin_Ip_FrameCsModelType      Cs;      /**< @brief Checksum model type.*/
    Lpuart_Lin_Ip_FrameResponseType     Drc;     /**< @brief Response type.*/
    uint8                               Dl;      /**< @brief Data length.*/
    uint8*                              SduPtr;  /**< @brief Pointer to Sdu.*/
} Lpuart_Lin_Ip_PduType;

/*!
 * @brief Description: This type defines a range of transfer status.
 * @implements Lpuart_Lin_Ip_TransferStatusType_enum
 */
typedef enum
{
    LPUART_LIN_IP_STATUS_FAIL = 0x00u,      /**< @brief Command has not been accepted. */
    LPUART_LIN_IP_STATUS_TX_OK,             /**< @brief Transmission successfully. */
    LPUART_LIN_IP_STATUS_TX_BUSY,           /**< @brief Transmission is ongoing. */
    LPUART_LIN_IP_STATUS_TX_HEADER_ERROR,   /**< @brief Erroneous header transmission. */
    LPUART_LIN_IP_STATUS_TX_ERROR,          /**< @brief Erroneous response transmission. */
    LPUART_LIN_IP_STATUS_RX_OK,             /**< @brief Reception of correct response. */
    LPUART_LIN_IP_STATUS_RX_BUSY,           /**< @brief Ongoing reception. At least one response byte has been received. */
    LPUART_LIN_IP_STATUS_RX_ERROR,          /**< @brief Erroneous response reception. */
    LPUART_LIN_IP_STATUS_RX_NO_RESPONSE,    /**< @brief No response byte has been received so far(timeout occurred). */
    LPUART_LIN_IP_STATUS_RX_HEADER_OK,      /**< @brief Slave received a correct header. */
    LPUART_LIN_IP_STATUS_RX_HEADER_BUSY,    /**< @brief Slave is receiving header. */
    LPUART_LIN_IP_STATUS_RX_HEADER_ERROR,   /**< @brief Erroneous header reception of slave. */
    LPUART_LIN_IP_STATUS_OPERATIONAL,       /**< @brief Normal operation. */
    LPUART_LIN_IP_STATUS_SLEEP,             /**< @brief Sleep state operation. */
} Lpuart_Lin_Ip_TransferStatusType;

/**
 *
 * @brief Runtime state of the LIN driver.
 *
 *
 *
 */
typedef struct
{
    const uint8 * TxBuff;                                   /**< @brief The buffer of data being sent. */
    uint8 * RxBuff;                                         /**< @brief The buffer of received data. */
    uint8 CntByte;                                          /**< @brief To count number of bytes already transmitted or received. */
    volatile uint8 TxSize;                                  /**< @brief The remaining number of bytes to be transmitted. */
    volatile uint8 RxSize;                                  /**< @brief The remaining number of bytes to be received. */
    uint8 Checksum;                                         /**< @brief Checksum byte */
    volatile boolean IsBusBusy;                             /**< @brief True if there are data, frame headers being transferred on bus */
    uint8 CurrentPid;                                       /**< @brief Current PID */
    volatile Lpuart_Lin_Ip_EventIdType CurrentEventId;      /**< @brief Current ID Event */
    volatile Lpuart_Lin_Ip_NodeStateType CurrentNodeState;  /**< @brief Current Node state */
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    volatile boolean BaudrateEvalEnable;                    /**< @brief Baudrate Evaluation Process Enable */
    volatile uint8 ActiveEdgeInterruptCount;               /**< @brief Falling Edge count of a sync byte */
#endif
    uint32 LinSourceClockFreq;                              /**< @brief Frequency of the source clock for LIN */
    volatile Lpuart_Lin_Ip_NodeStateType PreviousNodeState; /*!< @brief Store previous node state when set Lin channel to idle for further processing.*/
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #if defined(LPUART_LIN_IP_STOP_TIMER_NOTIFICATION) && defined(LPUART_LIN_IP_START_TIMER_NOTIFICATION)
    volatile boolean TimerCounting;                       /*!< @brief This field is set to FALSE in init and after the protocol timeout timer is stopped and it is set to TRUE when timer starts to count..*/
#endif
#endif/*(LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)*/
}
Lpuart_Lin_Ip_StateStructType;

/**
 * @brief LIN Driver callback function type
 * @implements Lpuart_Lin_Ip_CallbackType_pointer
 */
typedef void (*Lpuart_Lin_Ip_CallbackType)(const uint8 Instance, const Lpuart_Lin_Ip_StateStructType *LinState);


/**
 * @brief User configuration structure of the LIN driver.
 * @implements Lpuart_Lin_Ip_UserConfigType_structure
 *
 *
 */
typedef struct
{
    uint8 Instance;                                         /**< @brief Hardware Instance */
    uint32 BaudRateDivisor;                                 /**< @brief Baudrate divider to be configured in hardware */
    uint32 OverSamplingRatio;                               /**< @brief baudrate of LIN Hardware Interface to configure */
    boolean NodeFunction;                                   /**< @brief Node function as Master or Slave */
    uint8 BreakLength;                                      /**< @brief Length of break character will be transmitted */
    uint8 BreakLengthDetect;                                /**< @brief Length of break character can be detected */
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    boolean AutobaudEnable;                                 /**< @brief Enable Autobaud feature */
#endif
    Lpuart_Lin_Ip_CallbackType Callback;                    /**< @brief Callback function to invoke after receiving a byte or transmitting a byte. */
    Lpuart_Lin_Ip_StateStructType *StateStruct;
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
#ifdef LPUART_LIN_IP_START_TIMER_NOTIFICATION
    uint32 HeaderTimeoutValue;                              /**< @brief Header timeout duration(in bit time) converted to micro seconds. */
    uint32 ResponseTimeoutValue;                            /**< @brief Response timeout duration(in bit time) for 1 byte converted to micro seconds. */
#endif
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
    uint8 WakeupByte;                                       /**< @brief Byte will be sent to generate wakeup pulse [400us->4ms] */
    uint32 ChannelClock;                                    /**< @brief Channel clock */
} Lpuart_Lin_Ip_UserConfigType;

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

#endif /* LPUART_LIN_IP_TYPESS_H  */
