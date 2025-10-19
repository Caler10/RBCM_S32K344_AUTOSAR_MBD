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

#ifndef FLEXIO_LIN_IP_H
#define FLEXIO_LIN_IP_H

/**
*   @file Flexio_Lin_Ip.h
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
#include "Flexio_Lin_Ip_Cfg.h"
#include "Lin_Ip_Common.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_LIN_IP_VENDOR_ID                      43
#define FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_LIN_IP_SW_MAJOR_VERSION               5
#define FLEXIO_LIN_IP_SW_MINOR_VERSION               0
#define FLEXIO_LIN_IP_SW_PATCH_VERSION               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Flexio_Lin_Ip_Cfg.h */
#if (FLEXIO_LIN_IP_VENDOR_ID != FLEXIO_LIN_IP_CFG_VENDOR_ID)
    #error "Flexio_Lin_Ip.h and Flexio_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Flexio_Lin_Ip.h and Flexio_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip_Cfg header file are of the same Software version */
#if ((FLEXIO_LIN_IP_SW_MAJOR_VERSION != FLEXIO_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_MINOR_VERSION != FLEXIO_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_PATCH_VERSION != FLEXIO_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip.h and Flexio_Lin_Ip_Cfg.h are different"
#endif

/* Checks against Lin_Ip_Common.h */
#if (FLEXIO_LIN_IP_VENDOR_ID != LIN_IP_COMMON_VENDOR_ID)
    #error "Flexio_Lin_Ip.h and Lin_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Lin_Ip_Common header file are of the same Autosar version */
#if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION    != LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION    != LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION != LIN_IP_COMMON_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Flexio_Lin_Ip.h and Lin_Ip_Common.h are different"
#endif
/* Check if current file and Lin_Ip_Common header file are of the same Software version */
#if ((FLEXIO_LIN_IP_SW_MAJOR_VERSION != LIN_IP_COMMON_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_MINOR_VERSION != LIN_IP_COMMON_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_PATCH_VERSION != LIN_IP_COMMON_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip.h and Lin_Ip_Common.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/* Calling the external Configuration symbols defined by Flexio_Lin_Ip_Cfg.h */
FLEXIO_LIN_IP_CONFIG_EXT

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(x)      (((uint32)((uint32)(x) << 1U) - 1U) << 8U)
#define FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(x)   ((uint16)((uint16)((x) / (2U)) - 1U))
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
 * @brief Initializes an LIN_FLEXIO channel for LIN Network.
 *
 * @details The caller provides memory for the driver state structures during initialization.
 * The user must select the LIN_FLEXIO clock source in the application to initialize the LIN_FLEXIO.
 * This function initializes a FLEXIO channel for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings. It will configure two timers, two shifters and two pins
 * for Rx and Tx transmissions and at the end will enable the FLEXIO module.
 *
 * @param Channel LIN_FLEXIO channel number
 * @param UserConfig user configuration structure of type #Flexio_Lin_Ip_UserConfigType
 *
 * @return Flexio_Lin_Ip_StatusType
 * @retval FLEXIO_LIN_IP_STATUS_SUCCESS : Init command has been accepted.
 * @retval FLEXIO_LIN_IP_STATUS_ERROR   : Flexio module is not enabled, thus flexio channel cannot be initialized.
 * */
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_Init(const uint8 Channel, const Flexio_Lin_Ip_UserConfigType * UserConfig);

/**
 * @brief Puts current LIN node to Idle state
 * This function changes current node state to FLEXIO_LIN_IP_NODE_STATE_IDLE
 *
 * @param channel LIN_FLEXIO channel number
 * @return void
 */
void Flexio_Lin_Ip_GoToIdleState(const uint8 Channel);

/**
 * @brief Aborts an on-going non-blocking transmission/reception.
 *
 * @details While performing a non-blocking transferring data, users can call this function
 *  to terminate immediately the transferring.
 *
 * @param channel LIN_FLEXIO channel number
 * @return operation status:
 * @retval FLEXIO_LIN_IP_STATUS_SUCCESS : The frame was aborted
 * @retval FLEXIO_LIN_IP_STATUS_ERROR   : Operation failed due to transmission/reception could not stopped in timeout.
 *
 */
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_AbortTransferData(const uint8 Channel);

/**
 * @brief This function puts current node to sleep mode
 * @details This function changes current node state to FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE
 *
 * @param channel LIN_FLEXIO channel number
 * @return Flexio_Lin_Ip_StatusType
 * @retval FLEXIO_LIN_IP_STATUS_SUCCESS : Gotosleep command has been accepted.
 *
 *
 */
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_GoToSleepMode(const uint8 Channel);

/**
 * @brief Sends a wakeup signal through the LIN_FLEXIO interface
 *
 * @param channel LIN_FLEXIO channel number
 * @return operation status:
 * @retval  FLEXIO_LIN_IP_STATUS_SUCCESS : Command has been accepted.
 * @retval  FLEXIO_LIN_IP_STATUS_ERROR   : Command has not been accepted, error occurred.
 *
 */
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_SendWakeupSignal(const uint8 Channel);

/**
 * @brief De-initialize a FLEXIO LIN channel
 * @details This function shall de initialize a flexio lin channel. If no channel is available, disables also the FLEXIO module.
 * @param channel LIN_FLEXIO instance number.
 * @return operation status: VOID
 *
 */
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_Deinit(const uint8 Channel);

/**
 * @brief Returns the status of an on going transmission.
 * @details This function returns the status of the current non-blocking transfer. If a response reception has been successfully received, Buffer will be referenced to receive buffer.
 * @param channel LIN_FLEXIO instance number.
 * @param Buffer Pointer to the received data buffer.

 * @return operation status: Flexio_Lin_Ip_TransferStatusType
 * @retval FLEXIO_LIN_IP_STATUS_FAIL                       Command has not been accepted .
 * @retval FLEXIO_LIN_IP_STATUS_TX_OK,                  Master: Header or Response successful transmission. Slave: Response successful transmission.
 * @retval FLEXIO_LIN_IP_STATUS_TX_BUSY,                Master: Ongoing transmission (Header or Response). Slave: Ongoing transmission response.
 * @retval FLEXIO_LIN_IP_STATUS_TX_HEADER_ERROR,        Master: Erroneous header transmission such as: Mismatch between sent and read back data or Physical bus error./
 * @retval FLEXIO_LIN_IP_STATUS_TX_ERROR,               Master or Slave: Erroneous response transmission such as mismatch between sent and read back data, Physical bus error
 * @retval FLEXIO_LIN_IP_STATUS_RX_OK,                  Master or Slave: Reception of correct response.
 * @retval FLEXIO_LIN_IP_STATUS_RX_BUSY,                Master or Slave: Ongoing reception. At least one response byte has been received, but the checksum byte has not been received.
 * @retval FLEXIO_LIN_IP_STATUS_RX_ERROR,               Master or Slave: Erroneous response reception such as: - Framing error - Overrun error - Checksum error or Short response(timeout occurred).
 * @retval FLEXIO_LIN_IP_STATUS_RX_NO_RESPONSE,         Master or Slave: No response byte has been received so far(timeout occurred).
 * @retval FLEXIO_LIN_IP_STATUS_RX_HEADER_OK,           Slave: Reception of correct header.
 * @retval FLEXIO_LIN_IP_STATUS_RX_HEADER_BUSY,        Slave: Ongoing header reception.
 * @retval FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR,        Slave: Erroneous header reception such as: Break field error, Sync field error, Identifier parity error, Framing error, timeout occurred or Physical bus error.
 * @retval FLEXIO_LIN_IP_STATUS_OPERATIONAL,            Normal operation; there is no data has been sent or received after channel initialized or switched to IDLE from SLEEP.
 * @retval FLEXIO_LIN_IP_STATUS_SLEEP                   Sleep state operation.
 */
Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatus(const uint8 Channel, const uint8 **Buffer);

/**
 * @brief Sends a LIN frame as master or a response as a slave.
 *
 * @param channel LIN_FLEXIO channel number
 * @param PduInfo Structure which contains information about the current frame which is to be transfered such as PID, Data Length, Type of checksum, Data buffer and Type of the response expected.
 * @return operation status:
 * @retval  FLEXIO_LIN_IP_STATUS_SUCCESS : Command has not been accepted .
 * @retval  FLEXIO_LIN_IP_STATUS_BUSY    : Driver is busy with another transfer.
 * @retval  FLEXIO_LIN_IP_STATUS_ERROR   : Parameters such as Data Length and Pid are not correct or the current node is in sleep mode.
 */
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_SendFrame(const uint8 Channel, const Flexio_Lin_Ip_PduType* PduInfo);


 /**
 * @brief This is callback function for Timer Interrupt Handler.
 * Users shall initialize a timer (for example FTM)
 * and the time period in microseconds will be set by the driver via LinFlexioStartTimerNotification.
 * In timer IRQ handler, call this function.
 *
 *
 *
 */
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
void Flexio_Lin_Ip_TimerExpiredService(const uint8 Channel);
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_LIN_IP_H */
