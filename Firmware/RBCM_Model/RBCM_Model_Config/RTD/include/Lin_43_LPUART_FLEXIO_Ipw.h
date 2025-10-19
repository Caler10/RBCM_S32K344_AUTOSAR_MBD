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

#ifndef LIN_43_LPUART_FLEXIO_IPW_H
#define LIN_43_LPUART_FLEXIO_IPW_H

/**
*   @internal
*   @file Lin_43_LPUART_FLEXIO_Ipw.h
*
*   @addtogroup LIN_43_LPUART_FLEXIO_IPW
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

#include "Lin_43_LPUART_FLEXIO_Ipw_Cfg.h"
#include "Lpuart_Lin_Ip.h"
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
#include "Flexio_Lin_Ip.h"
#endif
#include "Lin_GeneralTypes.h"
#include "Lin_43_LPUART_FLEXIO_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID                    43
#define LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION     7
#define LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION             5
#define LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION             0
#define LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
/* Check if current file and Flexio_Lin_Ip header file are of the same Vendor ID version */
#if (LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID != FLEXIO_LIN_IP_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw.c and Flexio_Lin_Ip.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION    != FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION    != FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION != FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and Flexio_Lin_Ip.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION != FLEXIO_LIN_IP_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION != FLEXIO_LIN_IP_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION != FLEXIO_LIN_IP_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and Flexio_Lin_Ip.h are different"
#endif
#endif

/* Checks against Lin_43_LPUART_FLEXIO_Ipw_Cfg.h */
#if (LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID != LIN_43_LPUART_FLEXIO_IPW_CFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw.h and Lin_43_LPUART_FLEXIO_Ipw_Cfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lin_43_LPUART_FLEXIO_Ipw_Cfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lin_43_LPUART_FLEXIO_Ipw_Cfg.h are different"
#endif

/* Checks against Lpuart_Lin_Ip.h */
#if (LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID != LPUART_LIN_IP_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw.h and Lpuart_Lin_Ip.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION    != LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION    != LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lpuart_Lin_Ip.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION != LPUART_LIN_IP_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION != LPUART_LIN_IP_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION != LPUART_LIN_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lpuart_Lin_Ip.h are different"
#endif

/* Checks against Lin_43_LPUART_FLEXIO_Defines.h */
#if (LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID != LIN_43_LPUART_FLEXIO_DEFINES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw.h and Lin_43_LPUART_FLEXIO_Defines.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Defines.h header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Lin_GeneralTypes.h header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.h and Lin_GeneralTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @details          LIN frame was sent; no errors.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_COMPLETE_STATE      ((uint8)0x06U)

/**
* @brief            LIN Channel states
* @details          LIN frame is receiving.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_RX_ONGOING_STATE    ((uint8)0x09U)

/**
* @brief            LIN Channel states
* @details          LIN header is transmission.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_HEADER_COMPLETE_STATE        ((uint8)0x0AU)

/**
* @brief            LIN Channel states
* @details          LIN frame is sending.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_ONGOING_STATE           ((uint8)0x0BU)


/**
* @brief            Commands IDs
* @details          Tx frame is a master frame (response is provided by
*                   master).
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_MASTER_RES_COMMAND  ((uint8)0x01U)

/**
* @brief            Commands IDs
* @details          Tx frame is a slave frame (response is provided by
*                   slave).
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_SLAVE_RES_COMMAND   ((uint8)0x02U)

/**
* @brief            Commands IDs
* @details          Tx frame is a slave to slave frame (response is provided by
*                   slave).
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_SLAVE_TO_SLAVE_COMMAND   ((uint8)0x03U)

/**
* @brief            Commands IDs
* @details          Tx frame is a sleep command frame.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_SLEEP_COMMAND       ((uint8)0x04U)

/**
* @brief            Commands IDs
* @details          No tx master command pending.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_TX_NO_COMMAND           ((uint8)0x05U)


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
* @internal
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies which LIN channel has been woken
*          up by the LIN bus transceiver This API is used when the
*          LIN channel wake up functionality is disabled (wake up
*          interrupt is disabled) it checks the wake up flag from
*          all LIN channels which are in sleep mode and which
*          have the wake up functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_CheckWakeup(const uint8 Channel);

/**
* @internal
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
*
* @return            void.
*
*/
void Lin_43_LPUART_FLEXIO_Ipw_InitChannel(const uint8 Channel, const Lin_43_LPUART_FLEXIO_HwConfigType* ChannelConfigPtr);

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)

/**
* @internal
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the LINFlex_Ipw_SendReponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   pcPduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_SendFrame(const uint8 Channel, const Lin_PduType* PduInfoPtr);

/**
* @internal
* @brief   Sends the sleep command.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return      Std_ReturnType.
* @retval      E_OK - If the sleep-command is started to trasmit successfully
* @retval      E_NOT_OK - Otherwise.
*
*
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_GoToSleep(const uint8 Channel);

/**
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error rised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 *
*/
Lin_StatusType Lin_43_LPUART_FLEXIO_Ipw_HardwareGetStatus(const uint8 Channel, const uint8 **LinSduPtr);
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

/**
* @internal
* @brief   Same function as Lin_Ipw_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_GoToSleepInternal(const uint8 Channel);

/**
* @internal
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
void Lin_43_LPUART_FLEXIO_Ipw_WakeUp(const uint8 Channel);

/**
* @internal
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL_STATE_U8 state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
void Lin_43_LPUART_FLEXIO_Ipw_WakeUpInternal(const uint8 Channel);

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LPUART_FLEXIO_IPW_H */
