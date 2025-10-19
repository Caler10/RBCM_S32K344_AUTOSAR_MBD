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

#ifndef LPUART_LIN_IP_H
#define LPUART_LIN_IP_H

/**
*   @file
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

#include "Lpuart_Lin_Ip_Hw_Access.h"
#include "Lpuart_Lin_Ip_Cfg.h"
#include "Lin_Ip_Common.h"
#include "Lpuart_Lin_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_VENDOR_ID                      43
#define LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION       4
#define LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION       7
#define LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION    0
#define LPUART_LIN_IP_SW_MAJOR_VERSION               5
#define LPUART_LIN_IP_SW_MINOR_VERSION               0
#define LPUART_LIN_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpuart_Lin_Ip_Hw_Access.h */
#if (LPUART_LIN_IP_VENDOR_ID != LPUART_LIN_IP_HW_ACCESS_VENDOR_ID)
    #error "Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Hw_Access.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same Autosar version */
#if ((LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION    != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Hw_Access.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same Software version */
#if ((LPUART_LIN_IP_SW_MAJOR_VERSION != LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_SW_MINOR_VERSION != LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_SW_PATCH_VERSION != LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Hw_Access.h are different"
#endif

/* Checks against Lpuart_Lin_Ip_Cfg.h */
#if (LPUART_LIN_IP_VENDOR_ID != LPUART_LIN_IP_CFG_VENDOR_ID)
    #error "Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LPUART_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION    != LPUART_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Cfg header file are of the same Software version */
#if ((LPUART_LIN_IP_SW_MAJOR_VERSION != LPUART_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_SW_MINOR_VERSION != LPUART_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_SW_PATCH_VERSION != LPUART_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Cfg.h are different"
#endif

/* Checks against Lin_Ip_Common.h */
#if (LPUART_LIN_IP_VENDOR_ID != LIN_IP_COMMON_VENDOR_ID)
    #error "Lpuart_Lin_Ip.h and Lin_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Lin_Ip_Common header file are of the same Autosar version */
#if ((LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION    != LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION != LIN_IP_COMMON_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lpuart_Lin_Ip.h and Lin_Ip_Common.h are different"
#endif
/* Check if current file and Lin_Ip_Common header file are of the same Software version */
#if ((LPUART_LIN_IP_SW_MAJOR_VERSION != LIN_IP_COMMON_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_SW_MINOR_VERSION != LIN_IP_COMMON_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_SW_PATCH_VERSION != LIN_IP_COMMON_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip.h and Lin_Ip_Common.h are different"
#endif

/* Checks against Lpuart_Lin_Ip_Types.h */
#if (LPUART_LIN_IP_VENDOR_ID != LPUART_LIN_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Autosar version */
#if ((LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LPUART_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION    != LPUART_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Types.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Software version */
#if ((LPUART_LIN_IP_SW_MAJOR_VERSION != LPUART_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_SW_MINOR_VERSION != LPUART_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_SW_PATCH_VERSION != LPUART_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip.h and Lpuart_Lin_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/* Calling the external Configuration symbols defined by Lpuart_Lin_Ip_Cfg.h */
LPUART_LIN_IP_CONFIG_EXT

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
 * @brief Initializes an LIN_LPUART instance for LIN Network.
 *
 * @details The caller provides memory for the driver state structures during initialization.
 * The user must select the LIN_LPUART clock source in the application to initialize the LIN_LPUART.
 * This function initializes a LPUART instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the LPUART module transmitter and receiver
 *
 * @param Instance LIN_LPUART instance number
 * @param UserConfig user configuration structure of type #lin_user_config_t
 *
 * @return  LPUART_LIN_IP_STATUS_SUCCESS - Initialization command has been accepted.
 *          LPUART_LIN_IP_STATUS_ERROR - Initialization command has not been accepted.
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_Init(const uint8 Instance, const Lpuart_Lin_Ip_UserConfigType * UserConfig);

/**
 * @brief Shuts down the LIN_LPUART by disabling interrupts and transmitter/receiver.
 *
 * @param Instance LIN_LPUART instance number
 *
 * @return  LPUART_LIN_IP_STATUS_SUCCESS - De-initialization command has been accepted.
 *          LPUART_LIN_IP_STATUS_ERROR - De-initialization command has not been accepted. *
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_Deinit(const uint8 Instance);

/**
 * @brief Sends frame out through the LIN_LPUART module using non-blocking method.
 *
 * @details This enables an a-sync method for transmitting lin frame.
 *  Non-blocking  means that the function returns immediately.
 *  The application has to get the transferring status to know when the frame is complete.
 *  This function will calculate the checksum byte and send it with the frame data.
 *  If txSize is equal to 0 or greater than 8 or node's current state is in SLEEP mode
 *  then the function will return LPUART_LIN_IP_STATUS_ERROR. If isBusBusy is currently true then the
 *  function will return LPUART_LIN_IP_STATUS_BUSY.
 *
 * @param[in]  Instance LIN_LPUART instance number
 * @param[in]  PduInfo PDU containing the ID, Checksum model, Response type, Data Length and SDU data pointer.
 *
 * @return operation status:
 * @retval   LPUART_LIN_IP_STATUS_SUCCESS - Send command has been accepted.
 * @retval   LPUART_LIN_IP_STATUS_BUSY - Operation failed due to hardware instance busy.
 * @retval   LPUART_LIN_IP_STATUS_ERROR - Send command has not been accepted.
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_SendFrame(const uint8 Instance, const Lpuart_Lin_Ip_PduType *PduInfo);

/**
 * @brief Aborts an on-going non-blocking transmission/reception.
 *
 * @details While performing a non-blocking transferring data, users can call this function
 *  to terminate immediately the transferring.
 *
 * @param Instance LIN_LPUART instance number
 * @return Lpuart_Lin_Ip_StatusType
 *
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_AbortTransferData(const uint8 Instance);

/**
 * @brief This function puts current node to sleep mode
 * @details This function changes current node state to LIN_NODE_STATE_SLEEP_MODE
 *
 * @param Instance LIN_LPUART instance number
 * @return function always return LPUART_LIN_IP_STATUS_SUCCESS
 *
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_GoToSleepMode(const uint8 Instance);

/**
 * @brief Puts current LIN node to Idle state
 * This function changes current node state to LIN_NODE_STATE_IDLE
 *
 * @param Instance LIN_LPUART instance number
 * @return function always return LPUART_LIN_IP_STATUS_SUCCESS
 *
 *
 */
void Lpuart_Lin_Ip_GoToIdleState(const uint8 Instance);

/**
 * @brief Sends a wakeup signal through the LIN_LPUART interface
 *
 * @param Instance LIN_LPUART instance number
 * @return operation status:
 * @retval  LPUART_LIN_IP_STATUS_SUCCESS : Command has been accepted.
 * @retval  LPUART_LIN_IP_STATUS_ERROR   : Command has not been accepted, error occurred.
 *
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_SendWakeupSignal(const uint8 Instance);

/**
 * @brief Returns the status of an on going transmission.
 * @details This function returns the status of the current non-blocking transfer. If a response reception has been successfully received, Buffer will be referenced to receive buffer.
 * @param channel LIN_LPUART instance number.
 * @param Buffer Pointer to the received data buffer.

 * @return operation status: LPUART_Lin_Ip_TransferStatusType
 * @retval LPUART_LIN_IP_STATUS_FAIL                       Command has not been accepted .
 * @retval LPUART_LIN_IP_STATUS_TX_OK,                  Master: Header or Response successful transmission. Slave: Response successful transmission.
 * @retval LPUART_LIN_IP_STATUS_TX_BUSY,                Master: Ongoing transmission (Header or Response). Slave: Ongoing transmission response.
 * @retval LPUART_LIN_IP_STATUS_TX_HEADER_ERROR,        Master: Erroneous header transmission such as: Mismatch between sent and read back data or Physical bus error./
 * @retval LPUART_LIN_IP_STATUS_TX_ERROR,               Master or Slave: Erroneous response transmission such as mismatch between sent and read back data, Physical bus error
 * @retval LPUART_LIN_IP_STATUS_RX_OK,                  Master or Slave: Reception of correct response.
 * @retval LPUART_LIN_IP_STATUS_RX_BUSY,                Master or Slave: Ongoing reception. At least one response byte has been received, but the checksum byte has not been received.
 * @retval LPUART_LIN_IP_STATUS_RX_ERROR,               Master or Slave: Erroneous response reception such as: - Framing error - Overrun error - Checksum error or Short response(timeout occurred).
 * @retval LPUART_LIN_IP_STATUS_RX_NO_RESPONSE,         Master or Slave: No response byte has been received so far(timeout occurred).
 * @retval LPUART_LIN_IP_STATUS_RX_HEADER_OK,           Slave: Reception of correct header.
 * @retval LPUART_LIN_IP_STATUS_RX_HEADER_BUSY,        Slave: Ongoing header reception.
 * @retval LPUART_LIN_IP_STATUS_RX_HEADER_ERROR,        Slave: Erroneous header reception such as: Break field error, Sync field error, Identifier parity error, Framing error, timeout occurred or Physical bus error.
 * @retval LPUART_LIN_IP_STATUS_OPERATIONAL,            Normal operation; there is no data has been sent or received after channel initialized or switched to IDLE from SLEEP.
 * @retval LPUART_LIN_IP_STATUS_SLEEP                   Sleep state operation.
 */
Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatus(const uint8 Instance, const uint8 **Buffer);

 /**
 * @brief This is callback function for Timer Interrupt Handler.
 * Users shall initialize a timer (for example FTM)
 * and the time period in microseconds will be set by the driver via LinLpuartStartTimerNotification.
 * In timer IRQ handler, call this function.
 *
 * @param Instance LIN_LPUART instance number
 * @return None
 *
 *
 */
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
void Lpuart_Lin_Ip_TimerExpiredService(const uint8 Instance);
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

/**
 * @brief LIN_LPUART interrupt handler for RX_TX and Error interrupts.
 *
 * @param Instance LIN_LPUART instance number
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_IRQHandler(const uint8 Instance);

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)

/**
 * @brief This is autobaudrate capture function for Lin Slave.
 * This function capture bits time to detect break char, calculate
 * baudrate from sync bits and enable transmiter and receiver if autobaud successful.
 * This function should only be used in Slave.
 *
 * @param Instance LIN_LPUART instance number
 * @return Lpuart_Lin_Ip_StatusType
 * @retval   LPUART_LIN_IP_STATUS_SUCCESS - The autobaudrate evaluation has been finished successfully.
 * @retval   LPUART_LIN_IP_STATUS_BUSY - The autobaudrate evaluation is still in processing.
 * @retval   LPUART_LIN_IP_STATUS_ERROR - The autobaudrate evaluation has been finished with error.
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_AutoBaudCapture(uint8 Instance);

#endif

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPUART_LIN_IP_H */
