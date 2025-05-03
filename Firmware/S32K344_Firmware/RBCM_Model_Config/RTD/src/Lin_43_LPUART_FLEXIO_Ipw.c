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
   Copyright 2020 - 2024 NXP
*
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file   Lin_Ipw.c
*
*   @internal
*   @addtogroup LIN_IPW
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

#include "Lin_43_LPUART_FLEXIO_Ipw.h"
#include "OsIf.h"
#include "Lin_43_LPUART_FLEXIO_Types.h"
#include "LinIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID_C                    43
#define LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION_C             5
#define LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION_C             0
#define LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_43_LPUART_FLEXIO_Ipw.h */
#if (LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw.c and Lin_43_LPUART_FLEXIO_Ipw.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Ipw header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and Lin_43_LPUART_FLEXIO_Ipw.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Ipw header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and Lin_43_LPUART_FLEXIO_Ipw.h are different"
#endif

/* Checks against Lin_43_LPUART_FLEXIO_Types.h */
#if (LIN_43_LPUART_FLEXIO_IPW_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw.c and Lin_43_LPUART_FLEXIO_Types.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Types header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Types header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_IPW_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and OsIf.h are different"
    #endif
    /* Check if current file and LinIf.h header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MAJOR_VERSION_C != LINIF_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_IPW_AR_RELEASE_MINOR_VERSION_C != LINIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw.c and LinIf.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/**
* @brief        Sleep command frame
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_DATA              {0x00u, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu}

/**
* @brief        ID used in Gotosleep command transfer.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_PID_U8            ((uint8)0x3CU)

/**
* @brief        Number bytes of sleep data frame.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_DATA_LENGTH_U8    ((uint8)8U)
/**
* @brief        Number bytes of Lin data frame.
*
*
*/
#define LIN_43_LPUART_FLEXIO_IPW_MAX_DATA_LENGTH_U8              ((uint8)8U)

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief          Wakeup flags
* @details        This array contains booleans which indicate if a wakeup sign has been received or not.
*
*
*/
static volatile boolean Lin_Ipw_abWakeupFlag[LIN_43_LPUART_FLEXIO_HW_MAX_AVAILABLE_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*
*
*/
static const Lin_43_LPUART_FLEXIO_HwConfigType * Lin_Ipw_apxChannelsConfig[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief          Logic - Hw mapping
* @details        This array contains the mapping between logical channel and hw Instance.
*
*
*/
static uint8 Lin_Ipw_au8LpuartHwMapping[LPUART_INSTANCE_COUNT];

#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
/**
* @brief          Logic - Hw mapping for Flexio
* @details        This array contains the mapping between logical channel and hw Instance on Flexio
*
*
*/
static uint8 Lin_Ipw_au8FlexioHwMapping[FLEXIO_LIN_IP_NUMBER_OF_CHANNELS];

#endif

/**
* @brief          LIN header command type variable.
* @details        LIN header command type.
*
*
*/
static volatile uint8 Lin_Ipw_au8TransmitHeaderCommand[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static void Lin_Ipw_HandleTxSleepCmd(const uint8 Channel);
static void Lin_Ipw_Callback_TxCompleted_WakeUpEvent(const uint8 Instance, Lpuart_Lin_Ip_EventIdType EventID);
#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
static Std_ReturnType Lin_Ipw_CheckFrameInfo(const uint8 Dl, const uint8 Pid);

static Lin_StatusType Lpuart_Lin_Ipw_GetStatus(const uint8 Instance, const uint8 **Buffer);
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
static void Lpuart_Lin_Ipw_ProcessFrameData(const uint8 Instance, const Lpuart_Lin_Ip_StateStructType *LpuartStateStruct);

static void Lpuart_Lin_Ipw_SlaveReportError(const uint8 Instance);
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */

#if (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON)
static void Flexio_Lin_Ipw_Callback_TxCompleted_WakeupEvent(const uint8 Instance, Flexio_Lin_Ip_EventIdType EventId);
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
static void Flexio_Lin_Ipw_ProcessFrameData(const uint8 Instance, const Flexio_Lin_Ip_StateStructType *FlexioStateStruct);
static void Flexio_Lin_Ipw_SlaveReportError(const uint8 Instance);
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
static Lin_StatusType Flexio_Lin_Ipw_GetStatus(const uint8 Instance, const uint8 **Buffer);
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

#endif /* (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON)
/**
*
* @internal
* @brief   LIN callback.
* @details This callback function is used by low level driver to signal the events to the HLD layer for FLEXIO_LIN_IP_TX_COMPLETED and FLEXIO_LIN_IP_WAKEUP_SIGNAL event.
*
* @param[in]   Instance LIN hardware number.
*       [in]   FlexioStateStruct Flexio_Lin driver state structure.
* @return            void.
*
*/
static void Flexio_Lin_Ipw_Callback_TxCompleted_WakeupEvent(const uint8 Instance, Flexio_Lin_Ip_EventIdType EventId)
{
    uint8 Channel = Lin_Ipw_au8FlexioHwMapping[Instance];
    switch (EventId)
    {
        case FLEXIO_LIN_IP_TX_COMPLETED:
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                /* Calling the LinIf_TxConfirmation function to confirmed to the LIN interface */
                LinIf_TxConfirmation((NetworkHandleType)Channel);
            }
            else
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
            {
                if (LIN_43_LPUART_FLEXIO_IPW_TX_SLEEP_COMMAND == Lin_Ipw_au8TransmitHeaderCommand[Channel])
                {
                    (void)Flexio_Lin_Ip_GoToSleepMode(Instance);
                }
            }

            break;
        case FLEXIO_LIN_IP_WAKEUP_SIGNAL:
            /* Set wakeup signal flag */
            Lin_Ipw_abWakeupFlag[Channel] = TRUE;
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
            if (TRUE == Lin_Ipw_apxChannelsConfig[Channel]->LinChannelWakeupSupport)
            {
                /* Call EcuM_Checkwakeup */
                EcuM_CheckWakeup(Lin_Ipw_apxChannelsConfig[Channel]->LinChannelEcuMWakeupSource);
            }
#endif
            break;
        default:
            /* Do nothing */
            break;
    }
}
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
/**
*
* @internal
* @brief   LIN notifies to lin interface to about slave error.
* @details This callback function is used for notifing to LinIf about slave error.
*
* @param[in]        Instance - LIN hardware number.
* @return           void.
*
*/
static void Flexio_Lin_Ipw_SlaveReportError(const uint8 Instance)
{
    const uint8 *DummyBuff;
    uint8 Channel = Lin_Ipw_au8FlexioHwMapping[Instance];
    Flexio_Lin_Ip_TransferStatusType SlaveStatus = Flexio_Lin_Ip_GetStatus(Instance, &DummyBuff);
    (void)DummyBuff;

    switch (SlaveStatus)
    {
        case FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_HEADER);
            break;
        case FLEXIO_LIN_IP_STATUS_TX_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_DATABIT);
            break;
        case FLEXIO_LIN_IP_STATUS_RX_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_INC_RESP);
            break;
        case FLEXIO_LIN_IP_STATUS_RX_NO_RESPONSE:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_NO_RESP);
            break;
        default:
            /* Do nothing */
            break;
    }
}

/**
*
* @internal
* @brief   LIN callback.
* @details This callback function is used by low level driver to signal the events the correct PID was transmitted/received.
*          This also updates the status variables of the driver and calls for Flexio_Lin_Ip_AsyncReceiveFrameData and
*          FLexio_Lin_Ip_SendFrameData functions depending on the response source.
*
*
* @param[in]        Instance - LIN hardware number.
*       [in-out]    FlexioStateStruct - Flexio_Lin driver state structure.
* @return           void.
*
*/
static void Flexio_Lin_Ipw_ProcessFrameData(const uint8 Instance, const Flexio_Lin_Ip_StateStructType *FlexioStateStruct)
{
    Std_ReturnType TempReturn;
    uint8 Channel = Lin_Ipw_au8FlexioHwMapping[Instance];
    Lin_PduType PduInfo;
    uint8 SduBuf[LIN_43_LPUART_FLEXIO_IPW_MAX_DATA_LENGTH_U8];

    PduInfo.Pid = FlexioStateStruct->CurrentPid;
    PduInfo.SduPtr = &SduBuf[0u];
    /* Assign data length and direction as 0 to avoid misra rule 9.1 violation. After LinIf_HeaderIndication is called, it must be updated */
    PduInfo.Dl = 0u;
    PduInfo.Drc = LIN_FRAMERESPONSE_TX;

    /* Calling the LinIf_HeaderIndication function to indicate header reception to the LIN interface */
    TempReturn = LinIf_HeaderIndication((NetworkHandleType)Channel, &PduInfo);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        PduInfo.Drc = LIN_FRAMERESPONSE_IGNORE;
        PduInfo.Dl = 1u;
    }

    (void)Flexio_Lin_Ip_SendFrame(Instance, (const Flexio_Lin_Ip_PduType *)&PduInfo);
}
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
#endif /* (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON) */

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
/**
 * @internal
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  Buffer pointer to pointer to a shadow buffer or memory
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
 * @retval LIN_RX_NO_RESPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 *
*/
static Lin_StatusType Lpuart_Lin_Ipw_GetStatus(const uint8 Instance, const uint8 **Buffer)
{
    Lpuart_Lin_Ip_TransferStatusType status = Lpuart_Lin_Ip_GetStatus(Instance, Buffer);
    Lin_StatusType RetStatus = LIN_NOT_OK;

    switch (status)
    {
        case LPUART_LIN_IP_STATUS_TX_OK:
            RetStatus = LIN_TX_OK;
            break;
        case LPUART_LIN_IP_STATUS_TX_BUSY:
            RetStatus = LIN_TX_BUSY;
            break;
        case LPUART_LIN_IP_STATUS_TX_HEADER_ERROR:
            RetStatus = LIN_TX_HEADER_ERROR;
            break;
        case LPUART_LIN_IP_STATUS_TX_ERROR:
            RetStatus = LIN_TX_ERROR;
            break;
        case LPUART_LIN_IP_STATUS_RX_OK:
            RetStatus = LIN_RX_OK;
            break;
        case LPUART_LIN_IP_STATUS_RX_BUSY:
            RetStatus = LIN_RX_BUSY;
            break;
        case LPUART_LIN_IP_STATUS_RX_ERROR:
            RetStatus = LIN_RX_ERROR;
            break;
        case LPUART_LIN_IP_STATUS_RX_NO_RESPONSE:
            RetStatus = LIN_RX_NO_RESPONSE;
            break;
        case LPUART_LIN_IP_STATUS_OPERATIONAL:
            RetStatus = LIN_OPERATIONAL;
            break;
        case LPUART_LIN_IP_STATUS_SLEEP:
            RetStatus = LIN_CH_SLEEP;
            break;
        case LPUART_LIN_IP_STATUS_RX_HEADER_OK:
            /* fall-through */
        case LPUART_LIN_IP_STATUS_RX_HEADER_BUSY:
            /* fall-through */
        case LPUART_LIN_IP_STATUS_RX_HEADER_ERROR:
            /* fall-through */
        case LPUART_LIN_IP_STATUS_FAIL:
            /* fall-through */
        default:
            RetStatus = LIN_NOT_OK;
            break;
    }

    return RetStatus;
}

#if (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON)
#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
/**
 * @internal
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  Buffer pointer to pointer to a shadow buffer or memory
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
 * @retval LIN_RX_NO_RESPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 *
*/
static Lin_StatusType Flexio_Lin_Ipw_GetStatus(const uint8 Instance, const uint8 **Buffer)
{
    Flexio_Lin_Ip_TransferStatusType Status = Flexio_Lin_Ip_GetStatus(Instance, Buffer);
    Lin_StatusType RetStatus = LIN_NOT_OK;

    switch(Status)
    {
        case FLEXIO_LIN_IP_STATUS_TX_OK:
            RetStatus = LIN_TX_OK;
            break;
        case FLEXIO_LIN_IP_STATUS_TX_BUSY:
            RetStatus = LIN_TX_BUSY;
            break;
        case FLEXIO_LIN_IP_STATUS_TX_HEADER_ERROR:
            RetStatus = LIN_TX_HEADER_ERROR;
            break;
        case FLEXIO_LIN_IP_STATUS_TX_ERROR:
            RetStatus = LIN_TX_ERROR;
            break;
        case FLEXIO_LIN_IP_STATUS_RX_OK:
            RetStatus = LIN_RX_OK;
            break;
        case FLEXIO_LIN_IP_STATUS_RX_BUSY:
            RetStatus = LIN_RX_BUSY;
            break;
        case FLEXIO_LIN_IP_STATUS_RX_ERROR:
            RetStatus = LIN_RX_ERROR;
            break;
        case FLEXIO_LIN_IP_STATUS_RX_NO_RESPONSE:
            RetStatus = LIN_RX_NO_RESPONSE;
            break;
        case FLEXIO_LIN_IP_STATUS_OPERATIONAL:
            RetStatus = LIN_OPERATIONAL;
            break;
        case FLEXIO_LIN_IP_STATUS_SLEEP:
            RetStatus = LIN_CH_SLEEP;
            break;
        case FLEXIO_LIN_IP_STATUS_RX_HEADER_OK:
            /* fall-through */
        case FLEXIO_LIN_IP_STATUS_RX_HEADER_BUSY:
            /* fall-through */
        case FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR:
            /* fall-through */
        case FLEXIO_LIN_IP_STATUS_FAIL:
            /* fall-through */
        default:
            RetStatus = LIN_NOT_OK;
            break;
    }

    return RetStatus;
}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */
#endif /* (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON) */
/**
 * @internal
 * @brief   Check correctness of data length and Pid byte of the current frame.
 * @details This function will return the state E_OK if data length and Pid byte is correct following autosar standard
 *          and E_NOT_OK in otherwise.
 *
 * @param[in]   Dl - Number of data byte of the current frame.
 * @param[in]   Pid - Pid value of current frame.
 *
 * @return          Std_ReturnType.
 * @retval E_OK     Frame information is correct.
 * @retval E_NOT_OK Otherwise.
 *
 */
static Std_ReturnType Lin_Ipw_CheckFrameInfo(const uint8 Dl, const uint8 Pid)
{
    Std_ReturnType RetVal = (uint8) E_NOT_OK;

    /* Check of the data length parameter and invalid ID which return status error in LLD*/
    if ((0U != Dl) && (8U >= Dl))
    {
        /* Check Pid */
        if (0xFFU != Lin_Ip_ProcessParity(Pid, LIN_IP_CHECK_PARITY))
        {
            RetVal = (uint8)E_OK;
        }
    }

    return RetVal;
}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
/**
*
* @internal
* @brief   LIN callback.
* @details This callback function is used by low level driver to signal the events.
*
* @param[in]        Instance - LIN hardware number.
*       [in-out]    LpuartStateStruct - Lpuart_Lin driver state structure.
* @return           void.
*
*/
static void Lpuart_Lin_Ipw_ProcessFrameData(const uint8 Instance, const Lpuart_Lin_Ip_StateStructType *LpuartStateStruct)
{
    Std_ReturnType TempReturn;
    uint8 Channel = Lin_Ipw_au8LpuartHwMapping[Instance];
    uint8 SduBuf[LIN_43_LPUART_FLEXIO_IPW_MAX_DATA_LENGTH_U8];
    Lin_PduType LinPdu;

    LinPdu.Pid = LpuartStateStruct->CurrentPid;
    LinPdu.Cs = LIN_CLASSIC_CS;
    LinPdu.SduPtr = &SduBuf[0u];

    /* Calling the LinIf_HeaderIndication function to indicate header reception to the LIN interface */
    TempReturn = LinIf_HeaderIndication((NetworkHandleType)Channel, &LinPdu);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        LinPdu.Drc = LIN_FRAMERESPONSE_IGNORE;
        LinPdu.Dl = 1u;
    }

    (void)Lpuart_Lin_Ip_SendFrame(Instance, (const Lpuart_Lin_Ip_PduType *)&LinPdu);
}

/**
*
* @internal
* @brief   LIN notifies to lin interface to about slave error.
* @details This callback function is used for notifing to LinIf about slave error.
*
* @param[in]        Instance - LIN hardware number.
* @return           void.
*
*/
static void Lpuart_Lin_Ipw_SlaveReportError(const uint8 Instance)
{
    const uint8 *DummyBuff;
    uint8 Channel = Lin_Ipw_au8LpuartHwMapping[Instance];
    Lpuart_Lin_Ip_TransferStatusType SlaveStatus = Lpuart_Lin_Ip_GetStatus(Instance, &DummyBuff);
    (void)DummyBuff;

    switch (SlaveStatus)
    {
        case LPUART_LIN_IP_STATUS_RX_HEADER_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_HEADER);
            break;
        case LPUART_LIN_IP_STATUS_TX_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_DATABIT);
            break;
        case LPUART_LIN_IP_STATUS_RX_ERROR:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_INC_RESP);
            break;
        case LPUART_LIN_IP_STATUS_RX_NO_RESPONSE:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_NO_RESP);
            break;
        default:
            /* Do nothing */
            break;
    }
}
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */

/**
*
* @internal
* @brief   Handle Tx sleep command when errors occurs
* @details This function is used for handling Tx sleep command when errors occurs.
*
* @param[in]        Instance - LIN hardware number.
* @return           void.
*
*/
static void Lin_Ipw_HandleTxSleepCmd(const uint8 Channel)
{
    uint8 Instance = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;

    if (LIN_43_LPUART_FLEXIO_IPW_TX_SLEEP_COMMAND == Lin_Ipw_au8TransmitHeaderCommand[Channel])
    {
        if(LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
        {
            (void)Lpuart_Lin_Ip_AbortTransferData(Instance);
            /* Bus is idle after having error in sending sleep command, so don't need check return status */
            (void)Lpuart_Lin_Ip_GoToSleepMode(Instance);
        }
        #if (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON)
        else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
        {
            (void)Flexio_Lin_Ip_AbortTransferData(Instance);
            (void)Flexio_Lin_Ip_GoToSleepMode(Instance);
        }
        #endif /* (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON) */
        else
        {
            /* Do nothing */
        }
    }

}
/**
*
* @brief   LIN callback.
* @details This callback function is used by low level driver to signal the events to the HLD layer for LPUART_LIN_IP_TX_COMPLETED and LPUART_LIN_IP_WAKEUP_SIGNAL event
*
* @param[in]       Instance LIN hardware number.
*       [in-out]   LpuartStateStruct Lpuart_Lin driver state structure.
* @return          void.
*
*/
static void Lin_Ipw_Callback_TxCompleted_WakeUpEvent(const uint8 Instance, Lpuart_Lin_Ip_EventIdType EventID)
{
    uint8 Channel = Lin_Ipw_au8LpuartHwMapping[Instance];

    switch (EventID)
    {
        case LPUART_LIN_IP_TX_COMPLETED:
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                /* Calling the LinIf_TxConfirmation function to confirmed to the LIN interface */
                LinIf_TxConfirmation((NetworkHandleType)Channel);
            }
            else
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
            {
                if (LIN_43_LPUART_FLEXIO_IPW_TX_SLEEP_COMMAND == Lin_Ipw_au8TransmitHeaderCommand[Channel])
                {
                    /* The sleep command transmission completed, so bus is free. Don't need check return status */
                    (void)Lpuart_Lin_Ip_GoToSleepMode(Instance);
                }
            }

            break;
        case LPUART_LIN_IP_WAKEUP_SIGNAL:
            /* Set wakeup signal flag */
            Lin_Ipw_abWakeupFlag[Channel] = TRUE;
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
            if (TRUE == Lin_Ipw_apxChannelsConfig[Channel]->LinChannelWakeupSupport)
            {
                /* Call EcuM_Checkwakeup */
                EcuM_CheckWakeup(Lin_Ipw_apxChannelsConfig[Channel]->LinChannelEcuMWakeupSource);
            }
#endif
            break;
        default:
            /* Do nothing*/
            break;
    }
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
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
* @retval E_OK       If the LIN channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_CheckWakeup(const uint8 Channel)
{
    Std_ReturnType RetVal = (uint8)E_NOT_OK;

    if (TRUE == Lin_Ipw_abWakeupFlag[Channel])
    {
        RetVal = (uint8)E_OK;
        /* Reset Wakeup Flag */
        Lin_Ipw_abWakeupFlag[Channel] = FALSE;
    }

    return RetVal;
}

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
void Lin_43_LPUART_FLEXIO_Ipw_InitChannel(const uint8 Channel, const Lin_43_LPUART_FLEXIO_HwConfigType* ChannelConfigPtr)
{
    uint8 HwUnit = ChannelConfigPtr->LinHwChannel;
    const Lpuart_Lin_Ip_UserConfigType *TempPointer;

    /* Save a pointer to the Channel configuration structure */
    Lin_Ipw_apxChannelsConfig[Channel] = ChannelConfigPtr;

    if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == ChannelConfigPtr->LinIpType)
    {
        TempPointer = ChannelConfigPtr->IpConfig.LpuartConfigPtr;
        (void)Lpuart_Lin_Ip_Init(HwUnit, TempPointer);

        /* Initialization of the array which contain the mapping between hardware Instances and logical channels */
        Lin_Ipw_au8LpuartHwMapping[HwUnit] = Channel;

        /* Set LIN channel state machine to LIN_CH_SLEEP_STATE */
        (void)Lpuart_Lin_Ip_GoToSleepMode(HwUnit);
    }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == ChannelConfigPtr->LinIpType)
    {
        Lin_Ipw_au8FlexioHwMapping[HwUnit] = Channel;
        (void)Flexio_Lin_Ip_Init(HwUnit, ChannelConfigPtr->IpConfig.FlexioConfigPtr);

        /* Set LIN channel state machine to LIN_CH_SLEEP_STATE */
        (void)Flexio_Lin_Ip_GoToSleepMode(HwUnit);
    }
    #endif
    else
    {
        /* Impossible */
    }

    /* Reset header command type */
    Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_43_LPUART_FLEXIO_IPW_TX_NO_COMMAND;
}

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
* @retval LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR   In case of a timeout situation only.
* @retval E_NOT_OK   Other errors than timeout error.
* @retval E_OK       There is no error.
*
*
*/
/**
* @implements Lin_Ipw_SendFrame_Activity
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_SendFrame(const uint8 Channel, const Lin_PduType* PduInfoPtr)
{
    Std_ReturnType TempReturn = (uint8)E_OK;
    uint8 HwUnit = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;

    if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Abort any ongoing transmission for any type of frame response */
        if (LPUART_LIN_IP_STATUS_ERROR == Lpuart_Lin_Ip_AbortTransferData(HwUnit))
        {
            TempReturn = (uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR;
        }
    }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        if (FLEXIO_LIN_IP_STATUS_ERROR == Flexio_Lin_Ip_AbortTransferData(HwUnit))
        {
            TempReturn = (uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR;
        }
    }
    #endif
    else
    {
        /* Impossible */
        TempReturn = (uint8)E_NOT_OK;
    }

    /* Check Pid and Data length is whether correct following autosar */
    if (((uint8)E_OK == TempReturn) &&
        ((uint8)E_OK == Lin_Ipw_CheckFrameInfo(PduInfoPtr->Dl, PduInfoPtr->Pid))
       )
    {
        TempReturn = (uint8)E_NOT_OK;

        /* Master channel start sending the header */
        if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
        {
            if (LPUART_LIN_IP_STATUS_SUCCESS == Lpuart_Lin_Ip_SendFrame(HwUnit, (const Lpuart_Lin_Ip_PduType *)PduInfoPtr))
            {
                TempReturn = (uint8)E_OK;
            }
        }
        #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
        else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
        {
            if (FLEXIO_LIN_IP_STATUS_SUCCESS == Flexio_Lin_Ip_SendFrame(HwUnit, (const Flexio_Lin_Ip_PduType *)PduInfoPtr))
            {
                TempReturn = (uint8)E_OK;
            }
        }
        #endif
        else
        {
            /* Impossible */
        }

        if ((uint8)E_OK == TempReturn)
        {
            /* If Master waits for a response from a slave */
            if (LIN_FRAMERESPONSE_RX == PduInfoPtr->Drc)
            {
                /* Set the response source (from a remote slave) */
                Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_43_LPUART_FLEXIO_IPW_TX_SLAVE_RES_COMMAND;
            }
            else if (LIN_FRAMERESPONSE_TX == PduInfoPtr->Drc)
            {
                Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_43_LPUART_FLEXIO_IPW_TX_MASTER_RES_COMMAND;
            }
            /* It's a slave to slave response */
            else
            {
                /* Set the response source (none - it is a slave to slave communication) */
                Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_43_LPUART_FLEXIO_IPW_TX_SLAVE_TO_SLAVE_COMMAND;
            }
        }
    }
    else if ((uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR != TempReturn)
    {
        /* Update status to E_NOT_OK when Pid and Data length is incorrect */
        TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Should not enter here. Avoid to misra error */
    }

    return TempReturn;
}

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
* @retval LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR   In case of a timeout situation only.
* @retval E_NOT_OK   Other errors than timeout error.
* @retval E_OK       There is no error.
*
*
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_GoToSleep(const uint8 Channel)
{
    Std_ReturnType TempReturn = (uint8)E_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;
    Lin_PduType SleepPduInfo;
    uint8 SleepFrameData[LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_DATA_LENGTH_U8] = LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_DATA;

    /* Prepare sleep data */
    SleepPduInfo.SduPtr = &SleepFrameData[0u];
    SleepPduInfo.Dl = LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_DATA_LENGTH_U8;
    SleepPduInfo.Drc = LIN_FRAMERESPONSE_TX;
    SleepPduInfo.Cs = LIN_CLASSIC_CS;
    SleepPduInfo.Pid = LIN_43_LPUART_FLEXIO_IPW_SLEEP_COMMAND_PID_U8;

    if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Abort any ongoing transmission for any type of frame response */
        if (LPUART_LIN_IP_STATUS_ERROR == Lpuart_Lin_Ip_AbortTransferData(HwUnit))
        {
            TempReturn = (uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR;
        }
        else
        {
            if (LPUART_LIN_IP_STATUS_SUCCESS == Lpuart_Lin_Ip_SendFrame(HwUnit, (const Lpuart_Lin_Ip_PduType *)&SleepPduInfo))
            {
                /* Set the type of header command */
                Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_43_LPUART_FLEXIO_IPW_TX_SLEEP_COMMAND;
                TempReturn = (uint8)E_OK;
            }
        }
    }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Abort any ongoing transmission for any type of frame response */
        if (FLEXIO_LIN_IP_STATUS_ERROR == Flexio_Lin_Ip_AbortTransferData(HwUnit))
        {
            TempReturn = (uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR;
        }
        else
        {
            if (FLEXIO_LIN_IP_STATUS_SUCCESS == Flexio_Lin_Ip_SendFrame(HwUnit, (const Flexio_Lin_Ip_PduType *)&SleepPduInfo))
            {
                /* Set the type of header command */
                Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_43_LPUART_FLEXIO_IPW_TX_SLEEP_COMMAND;
                TempReturn = (uint8)E_OK;
            }
        }
    }
    #endif
    else
    {
        /* Impossible */
    }

    return TempReturn;
}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

/**
* @internal
* @brief   Same function as Lin_43_LPUART_FLEXIO_Ipw_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR   In case of a timeout situation only.
* @retval E_NOT_OK   Other errors than timeout error.
* @retval E_OK       There is no error.
*
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_Ipw_GoToSleepInternal(const uint8 Channel)
{
    Std_ReturnType TempReturn = (uint8)E_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;

    if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Abort any ongoing transmission for any type of frame response */
        if (LPUART_LIN_IP_STATUS_ERROR == Lpuart_Lin_Ip_AbortTransferData(HwUnit))
        {
            TempReturn = (uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR;
        }
        else
        {
            /* Set channel to sleep mode */
            (void)Lpuart_Lin_Ip_GoToSleepMode(HwUnit);
            TempReturn = (uint8)E_OK;
        }
    }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Abort any ongoing transmission for any type of frame response */
        if (FLEXIO_LIN_IP_STATUS_ERROR == Flexio_Lin_Ip_AbortTransferData(HwUnit))
        {
            TempReturn = (uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR;
        }
        else
        {
            /* Set channel to sleep mode */
            (void)Flexio_Lin_Ip_GoToSleepMode(HwUnit);
            TempReturn = (uint8)E_OK;
        }
    }
    #endif
    else
    {
        /* Impossible */
    }

    return TempReturn;
}

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
 * @retval LIN_RX_NO_RESPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 *
*/
Lin_StatusType Lin_43_LPUART_FLEXIO_Ipw_HardwareGetStatus(const uint8 Channel, const uint8 **LinSduPtr)
{
    Lin_StatusType ReturnStatus = LIN_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;

    if (LIN_43_LPUART_FLEXIO_MASTER_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
    {
        if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
        {
            ReturnStatus = Lpuart_Lin_Ipw_GetStatus(HwUnit, LinSduPtr);
        }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
        else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
        {
            ReturnStatus = Flexio_Lin_Ipw_GetStatus(HwUnit, LinSduPtr);
        }
    #endif
        else
        {
            /* Should not enter here */
        }
    }

    return ReturnStatus;
}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

/**
* @internal
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_43_LPUART_FLEXIO_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
void Lin_43_LPUART_FLEXIO_Ipw_WakeUp(const uint8 Channel)
{
    uint8 HwUnit = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;

    if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Send the wakeup pulse */
        (void)Lpuart_Lin_Ip_SendWakeupSignal(HwUnit);
        /* Put the  node in the idle state*/
    }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Send the wakeup pulse */
        (void)Flexio_Lin_Ip_SendWakeupSignal(HwUnit);
    }
    #endif
    else
    {
        /* Impossible */
    }
}

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
void Lin_43_LPUART_FLEXIO_Ipw_WakeUpInternal(const uint8 Channel)
{
    uint8 HwUnit = Lin_Ipw_apxChannelsConfig[Channel]->LinHwChannel;

    if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Put the  node in the idle state*/
        Lpuart_Lin_Ip_GoToIdleState(HwUnit);
    }
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == Lin_Ipw_apxChannelsConfig[Channel]->LinIpType)
    {
        /* Put the  node in the idle state*/
        (void)Flexio_Lin_Ip_GoToIdleState(HwUnit);
    }
    #endif
    else
    {
        /* Impossible */
    }
}

/**
*
* @brief   LIN callback.
* @details This callback function is used by low level driver to signal the events to the HLD layer.
*
* @param[in]       Instance LIN hardware number.
*       [in-out]   LpuartStateStruct Lpuart_Lin driver state structure.
* @return          void.
*
*/
void Lin_43_LPUART_FLEXIO_Ipw_Callback(const uint8 Instance, const Lpuart_Lin_Ip_StateStructType *LpuartStateStruct)
{
    uint8 Channel = Lin_Ipw_au8LpuartHwMapping[Instance];
    Lpuart_Lin_Ip_EventIdType EventID = LpuartStateStruct->CurrentEventId;

    switch (EventID)
    {
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
        /* Header transmission ok */
        case LPUART_LIN_IP_RECV_HEADER_OK:
            /* To continue handle data frame */
            Lpuart_Lin_Ipw_ProcessFrameData(Instance, LpuartStateStruct);
            break;

        case LPUART_LIN_IP_RX_COMPLETED:
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                /* Calling the LinIf_RxIndication function to send the received data available to the LIN interface */
                (void)LinIf_RxIndication((NetworkHandleType)Channel, LpuartStateStruct->RxBuff);
            }

            break;

        case LPUART_LIN_IP_FRAME_ERROR:
            if ((LPUART_LIN_IP_NODE_STATE_RECV_SYNC == LpuartStateStruct->PreviousNodeState) ||
                (LPUART_LIN_IP_NODE_STATE_RECV_PID == LpuartStateStruct->PreviousNodeState)
               )
            {
                /* LIN_ERR_HEADER is reported when a frame error occurs in the header part of the frame*/
                LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_HEADER);
            }
            else /* In case of LPUART_LIN_IP_NODE_STATE_RECV_DATA and LPUART_LIN_IP_NODE_STATE_SENT_DATA*/
            {
                /* LIN_ERR_RESP_STOPBIT is reported when a frame error occurs in the response part of the frame*/
                LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_STOPBIT);
            }
            break;

        case LPUART_LIN_IP_CHECKSUM_ERROR_EVENT:
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_CHKSUM);
            }

            break;
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
        #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        case LPUART_LIN_IP_TIMEOUT_ERROR:
            /* fall-through */
        #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
        case LPUART_LIN_IP_READBACK_ERROR:
            /* fall-through */
            /* Error in header reception */
        case LPUART_LIN_IP_PID_ERROR:
            /* fall-through */
        case LPUART_LIN_IP_SYNC_ERROR:
            /* fall-through */
            /* Error in response reception */
        case LPUART_LIN_IP_RX_OVERRUN_ERROR:
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                Lpuart_Lin_Ipw_SlaveReportError(Instance);
            }
            else
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
            {
                /* Handle Tx sleep command */
                Lin_Ipw_HandleTxSleepCmd(Channel);
            }
            break;

        case LPUART_LIN_IP_NO_EVENT:
            /* fall-through */
        case LPUART_LIN_IP_RECV_BREAK_FIELD_OK:
            break;
        default:
            /* IPW callback handler for LPUART_LIN_IP_TX_COMPLETED, LPUART_LIN_IP_WAKEUP_SIGNAL event for LPUART */
            Lin_Ipw_Callback_TxCompleted_WakeUpEvent(Instance, EventID);
            break;
    }
}

#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
/**
*
* @internal
* @brief   LIN callback.
* @details This callback function is used by low level driver to signal the events to the HLD layer.
*
* @param[in]   Instance LIN hardware number.
*       [in]   FlexioStateStruct Flexio_Lin driver state structure.
* @return            void.
*
*/
void Flexio_Lin_Ipw_Callback(const uint8 Instance, const Flexio_Lin_Ip_StateStructType * FlexioStateStruct)
{
    uint8 Channel = Lin_Ipw_au8FlexioHwMapping[Instance];
    Flexio_Lin_Ip_EventIdType EventId;

    EventId = FlexioStateStruct->CurrentEventId;

    switch (EventId)
    {
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
        /* Header transmission ok */
        case FLEXIO_LIN_IP_RECV_HEADER_OK:
            /* To continue handle data frame */
            Flexio_Lin_Ipw_ProcessFrameData(Instance, FlexioStateStruct);
            break;
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */

#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
        case FLEXIO_LIN_IP_RX_COMPLETED:
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                /* Calling the LinIf_RxIndication function to send the received data available to the LIN interface */
                (void)LinIf_RxIndication((NetworkHandleType)Channel, FlexioStateStruct->SduBuf);
            }

            break;
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */

        case FLEXIO_LIN_IP_SYNC_ERROR:
            /* fall-through */
        case FLEXIO_LIN_IP_PID_ERROR:
            /* fall-through */
        case FLEXIO_LIN_IP_READBACK_ERROR:
            /* fall-through */
        case FLEXIO_LIN_IP_TX_UNDERRUN_ERROR:
            /* fall-through */
        #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        case FLEXIO_LIN_IP_TIMEOUT_ERROR:
        #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                Flexio_Lin_Ipw_SlaveReportError(Instance);
            }
            else
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
            {
                /* Handle Tx sleep command */
                Lin_Ipw_HandleTxSleepCmd(Channel);
            }
            break;
#if (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON)
        case FLEXIO_LIN_IP_RX_OVERRUN_ERROR:
            if (LIN_43_LPUART_FLEXIO_SLAVE_NODE == Lin_Ipw_apxChannelsConfig[Channel]->LinNodeType)
            {
                LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_STOPBIT);
            }
            break;

        case FLEXIO_LIN_IP_CHECKSUM_ERROR_EVENT:
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_CHKSUM);
            break;
#endif /* (LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE == STD_ON) */
        case FLEXIO_LIN_IP_NO_EVENT:
            break;
        default:
            /* IPW callback handler for FLEXIO_LIN_IP_TX_COMPLETED, FLEXIO_LIN_IP_WAKEUP_SIGNAL event for FLEXIO */
            Flexio_Lin_Ipw_Callback_TxCompleted_WakeupEvent(Instance, EventId);
            break;
    }
}
#endif /*(STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)*/

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
