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

#ifndef LIN_43_LPUART_FLEXIO_H
#define LIN_43_LPUART_FLEXIO_H

/**
*   @file   Lin.h
*   @implements Lin.h_Artifact
*
*   @defgroup lin_driver LIN Driver
*   @addtogroup  lin_driver LIN Driver
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
#include "Lin_43_LPUART_FLEXIO_Types.h"
#include "Lin_GeneralTypes.h"
#include "Lin_43_LPUART_FLEXIO_Cfg.h"
#include "Lin_43_LPUART_FLEXIO_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_MODULE_ID                      82
#define LIN_43_LPUART_FLEXIO_VENDOR_ID                      43
#define LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION       4
#define LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION       7
#define LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION    0
#define LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION               5
#define LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION               0
#define LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_43_LPUART_FLEXIO_Types.h */
#if (LIN_43_LPUART_FLEXIO_VENDOR_ID != LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Types.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Types header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Types header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
/* Checks against Lin_43_LPUART_FLEXIO_Cfg.h */
 #if (LIN_43_LPUART_FLEXIO_VENDOR_ID != LIN_43_LPUART_FLEXIO_CFG_VENDOR_ID)
    #error "Lin.h and Lin_43_LPUART_FLEXIO_Cfg.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Cfg header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Cfg.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Cfg header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Cfg.h are different"
#endif
/* Checks against Lin_43_LPUART_FLEXIO_Ipw.h */
#if (LIN_43_LPUART_FLEXIO_VENDOR_ID != LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID)
    #error "Lin.h and Lin_43_LPUART_FLEXIO_Ipw.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Ipw header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Ipw.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Ipw header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_43_LPUART_FLEXIO_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Lin_GeneralTypes.h header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
            (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.h and Lin_GeneralTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
/**
* @brief            API service used without module initialization
* @details          The LIN Driver module shall report the development error "LIN_43_LPUART_FLEXIO_E_UNINIT (0x00)",
*                   when the API Service is used without module initialization.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_UNINIT            ((uint8)0x00U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LPUART_FLEXIO_E_INVALID_CHANNEL (0x02)", when API Service used with
*                   an invalid or inactive channel parameter.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LPUART_FLEXIO_E_INIT_FAILED (0x03)", when API Service is called
*                   with invalid configuration pointer.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_INIT_FAILED   ((uint8)0x03U)

/**
* @brief            Invalid state transition for the current state
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LPUART_FLEXIO_E_STATE_TRANSITION (0x04)", when Invalid state transition
*                   occurs from the current state.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_STATE_TRANSITION  ((uint8)0x04U)

/**
* @brief            API service called with a NULL pointer
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LPUART_FLEXIO_E_PARAM_POINTER (0x05)", when API Service is called
*                   with a NULL pointer. In case of this error, the API service
*                   shall return immediately without any further action,
*                   beside reporting this development error.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_PARAM_POINTER  ((uint8)0x05U)

/**
* @brief            Timeout caused by hardware error
* @details          The LIN Driver module shall report the development error
*                   "LIN_43_LPUART_FLEXIO_E_TIMEOUT (0x06)", when the error "Timeout caused by hardware error"
*                   has occurred and the reference LinDemEventParameterRefs/LIN_E_TIMEOUT is
*                   not configured.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_TIMEOUT       ((uint8)0x06U)

/**
* @brief            API service called with the requested resource is not configured to be available on the current core.
* @details          The LIN will check upon each API call if the requested resource is configured to be available on the current core,
*                   and in case of error will return LIN_43_LPUART_FLEXIO_E_PARAM_CONFIG
*
* 
*/
#define LIN_43_LPUART_FLEXIO_E_PARAM_CONFIG       ((uint8)0x07U)

#endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */

/**
* @brief            LIN driver states
* @details          The state LIN_43_LPUART_FLEXIO_UNINIT means that the Lin module has not
*                   been initialized yet and cannot be used.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_UNINIT              (0x01U)

/**
* @brief            LIN driver states
* @details          The LIN_43_LPUART_FLEXIO_INIT state indicates that the LIN driver has been
*                   initialized, making each available channel ready for service.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_INIT                (0x02U)

/**
* @brief            LIN Channel states
* @details          go-to-sleep-command has been issued on the bus, LIN channel stay at this state
*                   until Lin_43_LPUART_FLEXIO_GetStatus() is called
*
* 
*/
#define LIN_43_LPUART_FLEXIO_CH_SLEEP_PENDING    ((uint8)0x01U)

/**
* @brief            LIN Channel states
* @details          The detection of a wake-up pulse is enabled. The LIN
*                   hardware is into a low power mode if such a mode is
*                   provided by the hardware.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE      ((uint8)0x02U)

/**
* @brief            LIN Channel states
* @details          The individual channel has been initialized (using
*                   at least one statically configured data set) and
*                   is able to participate in the LIN cluster.
*
* 
*/
#define LIN_43_LPUART_FLEXIO_CH_OPERATIONAL      ((uint8)0x03U)

/* Service IDs of the AUTOSAR LIN API. */

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_GetStatus() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_GETSTATUS_ID            ((uint8)0x08U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_GetVersionInfo() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_GETVERSIONINFO_ID       ((uint8)0x01U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_GoToSleep() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_GOTOSLEEP_ID            ((uint8)0x06U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_GoToSleepInternal() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_GOTOSLEEPINTERNAL_ID    ((uint8)0x09U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_Init() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_INIT_ID                 ((uint8)0x00U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_SendFrame() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_SENDFRAME_ID            ((uint8)0x04U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_WakeUp() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_WAKEUP_ID               ((uint8)0x07U)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_WakeupInternal() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_WAKEUPINTERNAL_ID       ((uint8)0x0BU)

/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_CheckWakeup() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_CHECKWAKEUP_ID          ((uint8)0x0AU)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#if (STD_OFF == LIN_43_LPUART_FLEXIO_PRECOMPILE_SUPPORT)
LIN_43_LPUART_FLEXIO_CONFIG_EXT
#endif

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief   Validates for upper layers the wake up of LIN channel.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up signal.
*
* @param[in] Channel LIN channel to be addressed.
*
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          the addressed LIN Channel is not
*                          in sleep state.
* @retval E_OK             Otherwise.
*
*
**/
Std_ReturnType  Lin_43_LPUART_FLEXIO_CheckWakeup(uint8 Channel);

/**
* @brief   Initializes the LIN module.
* @details This function performs software initialization of LIN
*          driver:
*          - Clears the shadow buffer of all available Lin channels
*          - Sets all the available channels to sleep mode and configures
*            their state machine to LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE.
*          - Set driver state machine to LIN_43_LPUART_FLEXIO_INIT.
*
* @param[in] Config - Pointer to LIN driver configuration set.
*
* @return  void
*
* @pre     -
* 
*
**/
void            Lin_43_LPUART_FLEXIO_Init(const Lin_43_LPUART_FLEXIO_ConfigType * Config);

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)

/**
* @brief   Gets the status of the LIN driver when Channel is operating.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in]   Channel LIN channel to be addressed
* @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LIN Hardware receive buffer where the current SDU is
*              stored
* @return                  Lin_StatusType.
* @retval LIN_NOT_OK       Development or production error rised
*                          none of the below conditions.
* @retval  LIN_TX_OK        Successful transmission.
* @retval  LIN_TX_BUSY      Ongoing transmission of header or response.
* @retval  LIN_TX_HEADER_ERROR Error occurred during header
*                          transmission.
* @retval  LIN_TX_ERROR     Error occurred during response
*                          transmission.
* @retval  LIN_RX_OK        Reception of correct response.
* @retval  LIN_RX_BUSY      Ongoing reception where at least one byte
*                          has been received.
* @retval  LIN_RX_ERROR     Error occurred during reception.
* @retval  LIN_RX_NO_REPONSE No data byte has been received yet.
* @retval  LIN_OPERATIONAL  Channel is ready for next header.
*                          transmission and no data are available.
*
* @pre: This API is available only if at least one node is configured as MASTER.
*
**/
Lin_StatusType  Lin_43_LPUART_FLEXIO_GetStatus(uint8 Channel, \
                                    const uint8 ** Lin_43_LPUART_FLEXIO_SduPtr);
/**
* @brief   Sends a LIN frame.
* @details Sends a LIN header and a LIN response, if necessary. The
*          direction of the frame response (master response, slave
*          response, slave-to-slave communication) is provided by
*          the PduInfoPtr.
*
* @param[in] Channel       LIN channel to be addressed.
* @param[in] PduInfoPtr    pointer to PDU containing the PID,
*                          Checksum model, Response type, Dl and SDU
*                          data pointer.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          PduInfoPtr is NULL or
*                          a timeout occurs or
*                          LIN Channel is in sleep state.
* @retval E_OK             Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API. 
*          This API is available only if at least one node is configured as MASTER.
*
*
**/
Std_ReturnType  Lin_43_LPUART_FLEXIO_SendFrame(uint8 Channel, const Lin_PduType * PduInfoPtr);

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return  Std_ReturnType.
* @retval  E_NOT_OK   In case of a timeout situation only.
* @retval  E_OK       Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*          This API is available only if at least one node is configured as MASTER.
*
*
**/
Std_ReturnType  Lin_43_LPUART_FLEXIO_GoToSleep(uint8 Channel);

#endif /* LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON */

/**
* @brief   Same function as Lin_43_LPUART_FLEXIO_Ipw_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return  Std_ReturnType.
* @retval  E_NOT_OK   In case of a timeout situation only.
* @retval  E_OK       Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*
*
**/
Std_ReturnType  Lin_43_LPUART_FLEXIO_GoToSleepInternal(uint8 Channel);

/**
* @brief   Generates a wake up pulse.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_43_LPUART_FLEXIO_CH_OPERATIONAL state.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*
*
**/
Std_ReturnType  Lin_43_LPUART_FLEXIO_Wakeup(uint8 Channel);

/**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_43_LPUART_FLEXIO_CH_OPERATIONAL state without sending a
*          wake up signal to the LIN bus
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*
*
**/
Std_ReturnType  Lin_43_LPUART_FLEXIO_WakeupInternal(uint8 Channel);

#if (LIN_43_LPUART_FLEXIO_VERSION_INFO_API == STD_ON)

/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return void.
*
* 
*
*
**/
void Lin_43_LPUART_FLEXIO_GetVersionInfo (Std_VersionInfoType * versioninfo);

#endif  /* LIN_43_LPUART_FLEXIO_VERSION_INFO_API == STD_ON */

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LPUART_FLEXIO_H */
