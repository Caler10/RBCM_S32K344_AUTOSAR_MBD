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

/**
*   @file   Lpuart_Lin_Ip.c
*
*   @addtogroup LPUART_LIN_IP
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

#include "Lpuart_Lin_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_VENDOR_ID_C                      43
#define LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION_C       7
#define LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION_C    0
#define LPUART_LIN_IP_SW_MAJOR_VERSION_C               5
#define LPUART_LIN_IP_SW_MINOR_VERSION_C               0
#define LPUART_LIN_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if (LPUART_LIN_IP_VENDOR_ID_C != LPUART_LIN_IP_VENDOR_ID)
    #error "Lpuart_Lin_Ip.c and Lpuart_Lin_Ip.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip header file are of the same Autosar version */
#if ((LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION_C    != LPUART_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION_C    != LPUART_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION_C != LPUART_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lpuart_Lin_Ip.c and Lpuart_Lin_Ip.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip header file are of the same Software version */
#if ((LPUART_LIN_IP_SW_MAJOR_VERSION_C != LPUART_LIN_IP_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_SW_MINOR_VERSION_C != LPUART_LIN_IP_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_SW_PATCH_VERSION_C != LPUART_LIN_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip.c and Lpuart_Lin_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define LPUART_LIN_IP_MAX_DATA_LENGTH_U8                        ((uint8)8u)

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
/* Define nanosecond to calculate baudrate for Auto Baudrate */
#define LPUART_LIN_IP_CONVERT_SEC_TO_NANOSEC                    ((uint32)1000000000U)
/* Define nanosecond to calculate baudrate for Auto Baudrate */
#define LPUART_LIN_IP_CONVERT_SEC_TO_MICROSEC                   ((uint32)1000000U)
/* Define number of active edge (both falling and rising) for Auto Baudrate */
#define LPUART_LIN_IP_TOTAL_EDGE_SYNC_FIELD                     ((uint8)10U)


/*Min/Max of valid range in Baudrate */
#define LPUART_LIN_IP_AUTOBAUD_BAUDRATE_MIN_RANGE               ((uint16)1000U)
#define LPUART_LIN_IP_AUTOBAUD_BAUDRATE_MAX_RANGE               ((uint16)20000U)

/* Accept Bit rate deviation from the slave to be 2% */
#define LPUART_LIN_IP_AUTOBAUD_BAUDRATE_TOLERANCE               (uint32)2U

/* calculate range of 13 bit time minimum with baudrate 19200 for autobaud feature */
#define LPUART_LIN_IP_AUTOBAUD_BREAK_TIME_MIN                   (13U * LPUART_LIN_IP_CONVERT_SEC_TO_NANOSEC/LPUART_LIN_IP_AUTOBAUD_BAUDRATE_MAX_RANGE)
/* Minimum Wakeup field time in Autobaud Feature */
#define LPUART_LIN_IP_AUTOBAUD_WAKEUP_TIME_MIN_IN_NS            (150000U)
#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON)*/

#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
/* Minimum and Maximum Wakeup field time */
#define LPUART_LIN_IP_WAKEUP_TIME_MIN_IN_NS            (150000U)
#define LPUART_LIN_IP_WAKEUP_TIME_MAX_IN_NS            (5000000U)

#endif /* LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION */
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static uint8 Lpuart_Lin_Ip_au8WakeupSignal[LPUART_INSTANCE_COUNT];

static uint8 Lpuart_Lin_Ip_au8SduBuffer[LPUART_INSTANCE_COUNT][LPUART_LIN_IP_MAX_DATA_LENGTH_U8];

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    static uint8 Lpuart_Lin_Ip_au8CountMeasure[LPUART_INSTANCE_COUNT];
#endif

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    #define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Lin_43_LPUART_FLEXIO_MemMap.h"

    static uint32 Lpuart_Lin_Ip_au32Previous2BitsTimeLen[LPUART_INSTANCE_COUNT];
    static uint32 Lpuart_Lin_Ip_au32TimeMeasure[LPUART_INSTANCE_COUNT];

    #define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Lin_43_LPUART_FLEXIO_MemMap.h"
#endif


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
/* Table of Base addresses for LPUART instances. */
#define LIN_43_LPUART_FLEXIO_START_SEC_CONST_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static LPUART_Type * const Lpuart_Lin_Ip_apxBases[LPUART_INSTANCE_COUNT] = LPUART_LIN_IP_LPUART_BASE_PTRS;

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONST_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

Lpuart_Lin_Ip_StateStructType Lpuart_Lin_Ip_axStateStructure[LPUART_LIN_IP_NUMBER_OF_INSTANCES];

/* Table to save LIN user config structure pointers */
static const Lpuart_Lin_Ip_UserConfigType * Lpuart_Lin_Ip_apxUserConfigs[LPUART_INSTANCE_COUNT];

static Lpuart_Lin_Ip_StateStructType *Lpuart_Lin_Ip_apxStateStructureArray[LPUART_INSTANCE_COUNT];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static void Lpuart_Lin_Ip_ProcessBreakDetect(const uint8 Instance);
#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
static void Lpuart_Lin_Ip_ProcessWakeupDetect(const uint8 Instance);
static void Lpuart_Lin_Ip_CheckWakeupSignal(const uint8 Instance);
#endif /*LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION*/
static void Lpuart_Lin_Ip_FrameIrqHandler(const uint8 Instance);
static void Lpuart_Lin_Ip_ProcessReceiveFrameData(const uint8 Instance, const uint8 ReadData);
static void Lpuart_Lin_Ip_ProcessSendFrameData(const uint8 Instance, const uint8 TmpByte);
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
static void Lpuart_Lin_Ip_AutobaudTimerValEval(const uint8 Instance,
                                               const uint32 TwoBitTimeLength);
#endif /*(LPUART_LIN_IP_AUTO_BAUD == STD_ON)*/
static void Lpuart_Lin_Ip_FrameErrorIrqHandler(const uint8 Instance);
static void Lpuart_Lin_Ip_GetBytetoBuffer(const uint8 ByteCnt, \
                                          const uint8 BuffSize, \
                                          const uint8 Instance, \
                                          const uint8 DataByte \
                                         );
static void Lpuart_Lin_Ip_StartSendFrame(const uint8 Instance, const Lpuart_Lin_Ip_PduType *PduInfoPtr);
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromTimeoutError(const uint8 Instance);
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromReadBackError(const uint8 Instance);
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromSendHeaderOk(const uint8 Instance, Lpuart_Lin_Ip_NodeStateType CurrentNodeState);
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromNoEvent(Lpuart_Lin_Ip_NodeStateType CurrentNodeState);
static void Lpuart_Lin_Ip_RxOverrunErrorProcess(const uint8 Instance);
static void Lpuart_Lin_Ip_SlaveRxPidByteProcess(const uint8 Instance, const uint8 Data);
static void Lpuart_Lin_Ip_MasterRxPidByteProcess(const uint8 Instance, const uint8 Data);
static void Lpuart_Lin_Ip_MasterRxSyncByteProcess(const uint8 Instance, const uint8 Data);
static void Lpuart_Lin_Ip_SlaveRxSyncByteProcess(const uint8 Instance, const uint8 Data);
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromFrameError(const uint8 Instance);
static void Lpuart_Lin_Ip_DisableAllInterrupt(const uint8 Instance);
static Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_HwSetTransceiverCmd(const uint8 Instance, boolean Enable);
static Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_AbortTransferWhenBusBusy(const uint8 Instance, boolean NodeFunction, Lpuart_Lin_Ip_NodeStateType CurrentNodeState);
static void Lpuart_Lin_Ip_HwSetBreakCharInInit(const uint8 Instance, const Lpuart_Lin_Ip_UserConfigType * UserConfig);
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static void Lpuart_Lin_Ip_StartSendFrame(const uint8 Instance, const Lpuart_Lin_Ip_PduType *PduInfoPtr)
{
    uint8 Idx;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    LPUART_Type *Base = Lpuart_Lin_Ip_apxBases[Instance];
    const Lpuart_Lin_Ip_UserConfigType *UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    LinCurrentState->CurrentPid = PduInfoPtr->Pid;

    /* Current Checksum is 0x00u if checksum type is classic or CurrentPid in otherwise */
    LinCurrentState->Checksum = (LPUART_LIN_IP_CLASSIC_CS == PduInfoPtr->Cs) ? 0x00u : PduInfoPtr->Pid;

    if (LPUART_LIN_IP_FRAMERESPONSE_TX == PduInfoPtr->Drc)
    {
        /* Copy data to buffer */
        for (Idx = 0u; Idx < PduInfoPtr->Dl; Idx++)
        {
            Lpuart_Lin_Ip_au8SduBuffer[Instance][Idx] = PduInfoPtr->SduPtr[Idx];
        }

        LinCurrentState->Checksum = Lin_Ip_MakeChecksumByte(PduInfoPtr->SduPtr, PduInfoPtr->Dl, LinCurrentState->Checksum);

        LinCurrentState->TxBuff = &Lpuart_Lin_Ip_au8SduBuffer[Instance][0u];
        /*TxSize will be total number of data bytes and checksum (PduInfoPtr->Dl + 1u)*/
        LinCurrentState->TxSize = PduInfoPtr->Dl + 1u;
        LinCurrentState->RxSize = 0u;
    }
    else if (LPUART_LIN_IP_FRAMERESPONSE_RX == PduInfoPtr->Drc)
    {
        /* Copy data to buffer */
        for (Idx = 0u; Idx < LPUART_LIN_IP_MAX_DATA_LENGTH_U8; Idx++)
        {
            Lpuart_Lin_Ip_au8SduBuffer[Instance][Idx] = 0u;
        }
        LinCurrentState->TxSize = 0u;
        /* RxSize plus checksum byte to it (PduInfoPtr->Dl + 1u)*/
        LinCurrentState->RxSize = PduInfoPtr->Dl + 1u;
    }
    else
    {
        /* Ignor frame, so set length of buffer is 0 */
        LinCurrentState->TxSize = 0u;
        LinCurrentState->RxSize = 0u;
    }

    LinCurrentState->CntByte = 0u;

    /* Clear all interrupt flag when starting to send frame */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_ALL_INT_FLAGS);

    if ((boolean)LPUART_LIN_IP_MASTER == UserConfig->NodeFunction)
    {
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_NO_EVENT;
        /* Set Break char detect length as 13 bits minimum */
        Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, UserConfig->BreakLength);
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, TRUE);

        LinCurrentState->IsBusBusy = TRUE;
        LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SEND_BREAK_FIELD;

        /* Send break char by using queue mode, timeout will be set up after detect break */
        Lpuart_Lin_Ip_HwQueueBreakField(Base);
    }
    /* Slave processes the response frame */
    else
    {
        if (LPUART_LIN_IP_FRAMERESPONSE_TX == PduInfoPtr->Drc)
        {
            /* Set Break char detect length as 10 bits minimum */
            Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, LPUART_LIN_IP_BREAK_CHAR_10_BIT_MINIMUM_U8);
            /* Set LIN current state to sending Break field */
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SEND_DATA;
            LinCurrentState->IsBusBusy = TRUE;

            /* Start sending data */
            Lpuart_Lin_Ip_HwPutchar(Base, Lpuart_Lin_Ip_au8SduBuffer[Instance][0u]);
        }
        else if (LPUART_LIN_IP_FRAMERESPONSE_RX == PduInfoPtr->Drc)
        {
        #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
            #ifdef LPUART_LIN_IP_START_TIMER_NOTIFICATION
            LinCurrentState->TimerCounting = TRUE;
            /* Call notification to start timer for Lpuart instance and configure timeout value */
            LPUART_LIN_IP_START_TIMER_NOTIFICATION(Instance, UserConfig->ResponseTimeoutValue * (uint32)(PduInfoPtr->Dl + 1UL));
            #endif
        #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
            /* Set LIN current state to sending Break field */
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_DATA;
            LinCurrentState->IsBusBusy = TRUE;
        }
        else
        {
            Lpuart_Lin_Ip_GoToIdleState(Instance);
        }
    }
}
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetStatusFromTimeoutError
 * Description   : This function get status from Timeout error event.
 *
 *END**************************************************************************/
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromTimeoutError(const uint8 Instance)
{
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    Lpuart_Lin_Ip_TransferStatusType RetStatus = LPUART_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = (const Lpuart_Lin_Ip_StateStructType *)Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    switch (LinCurrentState->PreviousNodeState)
    {
        /* If the node is RECEIVING DATA */
        case LPUART_LIN_IP_NODE_STATE_RECV_DATA:
            if (0u == LinCurrentState->CntByte)
            {
                RetStatus = LPUART_LIN_IP_STATUS_RX_NO_RESPONSE;
            }
            else
            {
                RetStatus = LPUART_LIN_IP_STATUS_RX_ERROR;
            }
            break;
         /* If the node is RECEIVING HEADER */
        case LPUART_LIN_IP_NODE_STATE_RECV_SYNC:
            /* fall-through */
        case LPUART_LIN_IP_NODE_STATE_RECV_PID:
            RetStatus = LPUART_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        default:
            /* Do nothing */
            break;
    }

    return RetStatus;
}
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetStatusFromReadBackError
 * Description   : This function get status from Readback error event.
 *
 *END**************************************************************************/
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromReadBackError(const uint8 Instance)
{
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    Lpuart_Lin_Ip_TransferStatusType RetStatus = LPUART_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = (const Lpuart_Lin_Ip_StateStructType *)Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    if (LPUART_LIN_IP_NODE_STATE_SEND_DATA == LinCurrentState->PreviousNodeState)
    {
        /* Error occurred in receiving reponse */
        RetStatus = LPUART_LIN_IP_STATUS_TX_ERROR;
    }
    else if ((LPUART_LIN_IP_NODE_STATE_SEND_PID == LinCurrentState->PreviousNodeState) || (LPUART_LIN_IP_NODE_STATE_SEND_SYNC == LinCurrentState->PreviousNodeState))
    {
        RetStatus = LPUART_LIN_IP_STATUS_TX_HEADER_ERROR;
    }
    else
    {
        /* Should not enter here */
    }

    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetStatusFromSendHeaderOk
 * Description   : This function get status from send header event is successfully.
 *
 *END**************************************************************************/
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromSendHeaderOk(const uint8 Instance, Lpuart_Lin_Ip_NodeStateType CurrentNodeState)
{
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    Lpuart_Lin_Ip_TransferStatusType RetStatus = LPUART_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = (const Lpuart_Lin_Ip_StateStructType *)Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    if (LPUART_LIN_IP_NODE_STATE_SEND_DATA == CurrentNodeState)
    {
        RetStatus = LPUART_LIN_IP_STATUS_TX_BUSY;
    }
    else if (LPUART_LIN_IP_NODE_STATE_RECV_DATA == CurrentNodeState)
    {
        if (LinCurrentState->CntByte != 0u)
        {
            RetStatus = LPUART_LIN_IP_STATUS_RX_BUSY;
        }
        else
        {
            RetStatus = LPUART_LIN_IP_STATUS_RX_NO_RESPONSE;
        }
    }
    else
    {
        /* Do nothing */
    }

    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_RxOverrunErrorProcess
 * Description   : This function checks if rx overrun error occured.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_RxOverrunErrorProcess(const uint8 Instance)
{
    Lpuart_Lin_Ip_StateStructType *LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    LPUART_Type *Base = Lpuart_Lin_Ip_apxBases[Instance];
    const Lpuart_Lin_Ip_UserConfigType *UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];


    #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = FALSE;
    /* Call notification to stop timer when overrun error */
    LPUART_LIN_IP_STOP_TIMER_NOTIFICATION(Instance);
    #endif
    #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
    /* Clear overrun flag */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_RX_OVERRUN);

    /* Change node's state to IDLE */
    Lpuart_Lin_Ip_GoToIdleState(Instance);

    /* Set current event id to LIN_RX_OVERRUN */
    LinCurrentState->CurrentEventId = LPUART_LIN_IP_RX_OVERRUN_ERROR;

    /* Callback function to handle RX Overrun Event */
    if (NULL_PTR != UserConfig->Callback)
    {
        UserConfig->Callback(Instance, LinCurrentState);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetStatusFromNoEvent
 * Description   : This function get status when no event.
 *
 *END**************************************************************************/
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromNoEvent(Lpuart_Lin_Ip_NodeStateType CurrentNodeState)
{
    Lpuart_Lin_Ip_TransferStatusType RetStatus = LPUART_LIN_IP_STATUS_FAIL;

    switch (CurrentNodeState)
    {
        case LPUART_LIN_IP_NODE_STATE_SLEEP_MODE:
            RetStatus = LPUART_LIN_IP_STATUS_SLEEP;
            break;
        case LPUART_LIN_IP_NODE_STATE_SEND_BREAK_FIELD:
            /* fall-through */
        case LPUART_LIN_IP_NODE_STATE_SEND_SYNC:
            /* fall-through */
        case LPUART_LIN_IP_NODE_STATE_SEND_PID:
            RetStatus = LPUART_LIN_IP_STATUS_TX_BUSY;
            break;
        case LPUART_LIN_IP_NODE_STATE_IDLE:
            RetStatus = LPUART_LIN_IP_STATUS_OPERATIONAL;
            break;
        default:
            RetStatus = LPUART_LIN_IP_STATUS_FAIL;
            break;
    }
    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetBytetoBuffer
 * Description   : This function get received byte then stored to up and also update instance state.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_GetBytetoBuffer(const uint8 ByteCnt, \
                                          const uint8 BuffSize, \
                                          const uint8 Instance, \
                                          const uint8 DataByte
                                         )
{
    Lpuart_Lin_Ip_StateStructType *LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    uint8 CurrentChecksum;

    if (ByteCnt < BuffSize)
    {
        /* No error happened, get data bytes */
        Lpuart_Lin_Ip_au8SduBuffer[Instance][ByteCnt] = DataByte;
    }
    else
    {
        /* Get current Checksum which is 0x00u if checksum type is classic or CurrentPid in otherwise */
        /* The LinCurrentState->Checksum is assigned in Ip_StartSendFrame() function */
        CurrentChecksum = LinCurrentState->Checksum;

        /* When the Lin instance is reception data, current Checksum is 0x00u if checksum type is classic or CurrentPid in otherwise*/
        LinCurrentState->Checksum = Lin_Ip_MakeChecksumByte(&Lpuart_Lin_Ip_au8SduBuffer[Instance][0u], BuffSize, CurrentChecksum);

        if (DataByte != LinCurrentState->Checksum)
        {
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_CHECKSUM_ERROR_EVENT;
        }
        else
        {
            /* store received data buffer to inform to ipw layer */
            LinCurrentState->RxBuff = &Lpuart_Lin_Ip_au8SduBuffer[Instance][0u];
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_RX_COMPLETED;
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED;
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_FrameErrorIrqHandler
 * Description   : This function handles frame error when it occurs
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_FrameErrorIrqHandler(const uint8 Instance)
{
    LPUART_Type *Base = Lpuart_Lin_Ip_apxBases[Instance];
    Lpuart_Lin_Ip_StateStructType *LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    const Lpuart_Lin_Ip_UserConfigType *UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];
    uint8 TmpByte;

    /* Clear Framing Error Interrupt Flag */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_FRAME_ERR);

    /* Read dummy to clear LPUART_LIN_IP_RX_DATA_REG_FULL flag */
    Lpuart_Lin_Ip_HwGetchar(Base, &TmpByte);

    /* Change node's state to IDLE */
    Lpuart_Lin_Ip_GoToIdleState(Instance);

    /* Set current event id to LIN_FRAME_ERROR */
    LinCurrentState->CurrentEventId = LPUART_LIN_IP_FRAME_ERROR;

    /* Check if the current node is SLAVE. Callback function will only call to report frame error to Linif via LinIf_LinErrorIndication with LIN_ERR_RESP_STOPBIT error when current node is SLAVE. */
    if ((boolean)LPUART_LIN_IP_SLAVE == UserConfig->NodeFunction)
    {
        /* Check error in case as: Error during header reception, Framing error in response and Bit error during response transmission */
        if ((LPUART_LIN_IP_NODE_STATE_SEND_DATA == LinCurrentState->PreviousNodeState) || \
            (LPUART_LIN_IP_NODE_STATE_RECV_DATA == LinCurrentState->PreviousNodeState) || \
            (LPUART_LIN_IP_NODE_STATE_RECV_SYNC == LinCurrentState->PreviousNodeState) || \
            (LPUART_LIN_IP_NODE_STATE_RECV_PID == LinCurrentState->PreviousNodeState)
           )
        {
            /* Callback function to handle Framing Error Event */
            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Instance, LinCurrentState);
            }
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_ProcessBreakDetect
 * Description   : This function process break detect for LIN communication.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_ProcessBreakDetect(const uint8 Instance)
{
    /* Get the current LIN user configure structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];
    uint8 DiscardData;

    /* Get Base address of the LPUART instance. */
    LPUART_Type * Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    /* Clear LIN Break Detect Interrupt Flag */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_BREAK_DETECT);

    /* Set Break char detect length as 10 bits minimum */
    Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, LPUART_LIN_IP_BREAK_CHAR_10_BIT_MINIMUM_U8);
    /* Disable LIN Break Detect Interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, FALSE);
    /* Clear Rx complete interrupt flag */
    Lpuart_Lin_Ip_HwGetchar(Base, &DiscardData);
    (void)DiscardData;
    /* Enable RX complete interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL, TRUE);

    /* Check if the current node is MASTER */
    if ((boolean)LPUART_LIN_IP_MASTER == UserConfig->NodeFunction)
    {
        /* Check if LIN current node state is LPUART_LIN_IP_NODE_STATE_SEND_BREAK_FIELD */
        if (LPUART_LIN_IP_NODE_STATE_SEND_BREAK_FIELD == LinCurrentState->CurrentNodeState)
        {
            /* Change the node's current state to SENDING PID to send PID after send SYNC */
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SEND_SYNC;
            /* Send Sync Field 0x55 */
            Lpuart_Lin_Ip_HwPutchar(Base, 0x55u);
        }
    }
    /* If the current node is SLAVE */
    else
    {
        /* Set flag LIN bus busy */
        LinCurrentState->IsBusBusy = TRUE;
        /* Change the node's current state to RECEIVED BREAK FIELD */
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_RECV_BREAK_FIELD_OK;
        /* Change the node's current state to RECEIVING SYNC FIELD */
        LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_SYNC;

        #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        #ifdef LPUART_LIN_IP_START_TIMER_NOTIFICATION
        LinCurrentState->TimerCounting = TRUE;
        /* Call notification to start timer for the checking header reception timeout */
        /* Header Timeout duration(in microseconds) after detection break */
        LPUART_LIN_IP_START_TIMER_NOTIFICATION(Instance, UserConfig->HeaderTimeoutValue);
        #endif
        #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
    }
}
#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_ProcessWakeupDetect
 * Description   : This function process wake-up signal detect for LIN communication.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_ProcessWakeupDetect(const uint8 Instance)
{
    /* Get the current LIN state of this LPUART instance. */
    const Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    if (LPUART_LIN_IP_NODE_STATE_SLEEP_MODE == LinCurrentState->CurrentNodeState)
    {
        /* Check if a wakeup signal has been received */
        Lpuart_Lin_Ip_CheckWakeupSignal(Instance);
    }
}
#endif /* LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION */
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_FrameIrqHandler
 * Description   : Part of Interrupt handler for receiving and sending data.
 * Receive Header, Data and Send Data.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_FrameIrqHandler(const uint8 Instance)
{
    uint8 TmpByte;
    const LPUART_Type *Base = (const LPUART_Type*)Lpuart_Lin_Ip_apxBases[Instance];
    /* Get the current LIN state of this LPUART instance. */
    const Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    /* Get data in buffer register */
    Lpuart_Lin_Ip_HwGetchar(Base, &TmpByte);

    /* Check node's current state */
    switch (LinCurrentState->CurrentNodeState)
    {
        /* if current state is RECEIVE SYNC FIELD */
        case LPUART_LIN_IP_NODE_STATE_RECV_SYNC:
            Lpuart_Lin_Ip_SlaveRxSyncByteProcess(Instance, TmpByte);
            break;
        /* If current state is MASTER CHECK SYNC BYTE and after that send PID */
        case LPUART_LIN_IP_NODE_STATE_SEND_SYNC:
            Lpuart_Lin_Ip_MasterRxSyncByteProcess(Instance, TmpByte);
            break;
        case LPUART_LIN_IP_NODE_STATE_SEND_PID:
            Lpuart_Lin_Ip_MasterRxPidByteProcess(Instance, TmpByte);
            break;
        /* if current state is RECEIVE PID */
        case LPUART_LIN_IP_NODE_STATE_RECV_PID:
            /* Get data from Data Register & Clear LPUART_LIN_IP_RX_DATA_REG_FULL flag */
            Lpuart_Lin_Ip_SlaveRxPidByteProcess(Instance, TmpByte);
            break;
        /* if current state is RECEIVE DATA */
        case LPUART_LIN_IP_NODE_STATE_RECV_DATA:
            Lpuart_Lin_Ip_ProcessReceiveFrameData(Instance, TmpByte);
            break;
        /* if current state is SENDING DATA */
        case LPUART_LIN_IP_NODE_STATE_SEND_DATA:
            Lpuart_Lin_Ip_ProcessSendFrameData(Instance, TmpByte);
            break;
        default:
            /* Other node state */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_SlaveRxSyncByteProcess
 * Description   : Processing receive SYNC byte in Slave mode.
 *  This function will check SYNC byte and update node state to receive PID.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_SlaveRxSyncByteProcess(const uint8 Instance, const uint8 Data)
{
    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    if (0x55U == Data)
    {
        /* Change node's current state to RECEIVE PID */
        LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_PID;
    }
    else
    {
        /* Set current event ID to Sync byte is incorrect */
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_SYNC_ERROR;

        /* Change node's current state to IDLE */
        Lpuart_Lin_Ip_GoToIdleState(Instance);

        /* Callback function to handle event RECEIVED SYNC FIELD ERROR */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }

    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_MasterRxSyncByteProcess
 * Description   : Processing the transfer PID byte in Master mode after checking the sync byte read-back.
 *  This function will check SYNC readback byte and update node state to receive PID.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_MasterRxSyncByteProcess(const uint8 Instance, const uint8 Data)
{
    /* Get Base address of the LPUART instance. */
    LPUART_Type * Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    /* Check if master node sent SYNC byte correctly before send PID */
    if (0x55U == Data)
    {
        /* Change node's current state to SENDING PID */
        LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SEND_PID;
        /* Send the current PID byte */
        Lpuart_Lin_Ip_HwPutchar(Base, LinCurrentState->CurrentPid);
    }
    /* In case of errors during header transmission, it is up to the implementer
        * how to handle these errors (stop/continue transmission) and to decide if the
        * corresponding response is valid or not.
        * By default, LIN Driver set IsBusBusy to FALSE, and change node's state to IDLE.
        */
    else
    {
        /* Set current event ID to read-back error */
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_READBACK_ERROR;

        Lpuart_Lin_Ip_GoToIdleState(Instance);

            /* Callback function to handle event SENT SYNC BYTE ERROR */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }

    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_MasterRxPidByteProcess
 * Description   : CheckS of PID byte transmission.
 *  This function will check if PID has been sent correctly by the Master and starts processing response.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_MasterRxPidByteProcess(const uint8 Instance, const uint8 Data)
{
    /* Get Base address of the LPUART instance. */
    LPUART_Type * Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

     /* Check if master node sent PID correctly */
    if (Data == LinCurrentState->CurrentPid)
    {
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_SEND_HEADER_OK;
        /* Process reponse */
        if (LinCurrentState->TxSize > 0u)
        {
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SEND_DATA;
            /* Send the first byte of transmitting buffer  */
            Lpuart_Lin_Ip_HwPutchar(Base, Lpuart_Lin_Ip_au8SduBuffer[Instance][0u]);
        }
        else if (LinCurrentState->RxSize > 0u)
        {
        #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
            #ifdef LPUART_LIN_IP_START_TIMER_NOTIFICATION
            LinCurrentState->TimerCounting = TRUE;
            /* Call notification to start timer for Lpuart instance and configure timeout value. The Master node will receive Response frame */
            LPUART_LIN_IP_START_TIMER_NOTIFICATION(Instance, UserConfig->ResponseTimeoutValue * (uint32)(LinCurrentState->RxSize));
            #endif
        #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_DATA;
        }
        else
        {
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_TX_COMPLETED;
            /* Slave to slave frame, ignor data */
            Lpuart_Lin_Ip_GoToIdleState(Instance);
        }
    }
    /* In case of errors during header transmission, it is up to the implementer
        * how to handle these errors (stop/continue transmission) and to decide if the
        * corresponding response is valid or not.
        * By default, LIN Driver set IsBusBusy to (boolean)FALSE, and change node's state to IDLE.
        */
    else
    {
        /* Set current event ID to read-back incorrect */
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_READBACK_ERROR;

        Lpuart_Lin_Ip_GoToIdleState(Instance);

        /* Callback function to handle event MASTER SENT PID ERROR */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_SlaveRxPidByteProcess
 * Description   : CheckS of PID byte reception.
 *  This function will check if PID has been received correctly, checks the checksum.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_SlaveRxPidByteProcess(const uint8 Instance, const uint8 Data)
{
    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = FALSE;
    /* Call notification to stop timer after PID byte received for Slave node */
    LPUART_LIN_IP_STOP_TIMER_NOTIFICATION(Instance);
    #endif
    #endif/*(LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)*/

    /* Check the received PID */
    LinCurrentState->CurrentPid = Lin_Ip_ProcessParity(Data, LIN_IP_CHECK_PARITY);

    if (0xFFu != LinCurrentState->CurrentPid)
    {
        LinCurrentState->CurrentPid = Data;
        /* Set current event ID to PID correct */
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_RECV_HEADER_OK;

        /* Clear Bus bus flag */
        LinCurrentState->IsBusBusy = FALSE;

        /* Callback function to handle event PID correct */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }
    }
    else
    {
        /* Set current event ID to PID ERROR */
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_PID_ERROR;

        /* Change node's current state to IDLE */
        Lpuart_Lin_Ip_GoToIdleState(Instance);

        /* Callback function to handle event PID incorrect */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }
    }
}


#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_AutobaudTimerValEval
 * Description   : This function calculate LIN bus baudrate and set slave's baudrate accordingly.
 * Autobaud process runs only once after reset. After setting slave's baudrate to LIN bus baudrate,
 * slave does not evaluate LIN bus baudrate anymore.
 * This is not a public API as it is called from other driver functions.
 *
 * Implements    : Lpuart_Lin_Ip_AutobaudTimerValEval_Activity
 *END**************************************************************************/
static void Lpuart_Lin_Ip_AutobaudTimerValEval(const uint8 Instance, const uint32 TwoBitTimeLength)
{
    uint32 MasterBaudrate = 0U;
    uint32 MasterBaudrateDivisor = 0U;
    uint8 WakeupByte = 0UL;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;
    LPUART_Type *Base = Lpuart_Lin_Ip_apxBases[Instance];

    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Start checking at active edge number 5th, just checking at falling edge */
    if ((LinCurrentState->ActiveEdgeInterruptCount % 2U) && (LinCurrentState->ActiveEdgeInterruptCount >= 5U))
    {
        /* If 2 bits time length of current measure is not nearly equal the previous one */
        if ((TwoBitTimeLength < ((100U - LPUART_LIN_IP_AUTOBAUD_BAUDRATE_TOLERANCE) * Lpuart_Lin_Ip_au32Previous2BitsTimeLen[Instance] / 100U)) || \
            (TwoBitTimeLength > ((100U + LPUART_LIN_IP_AUTOBAUD_BAUDRATE_TOLERANCE) * Lpuart_Lin_Ip_au32Previous2BitsTimeLen[Instance] / 100U))
           )
        {
            /* Error, finish Baudrate evaluation */
            /* Set current event ID to Sync byte is incorrect */
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_SYNC_ERROR;
            /* Change node's current state to IDLE */
            Lpuart_Lin_Ip_GoToIdleState(Instance);
        }
    }

    /* Check the current active edge is the last falling edge and the current node state is still RECV SYNC state */
    if ((LinCurrentState->ActiveEdgeInterruptCount >= LPUART_LIN_IP_TOTAL_EDGE_SYNC_FIELD -1U) && \
        (LinCurrentState->CurrentNodeState == LPUART_LIN_IP_NODE_STATE_RECV_SYNC) \
       )
    {
        MasterBaudrate = LPUART_LIN_IP_CONVERT_SEC_TO_NANOSEC / (TwoBitTimeLength/2U);
        if ((MasterBaudrate >= LPUART_LIN_IP_AUTOBAUD_BAUDRATE_MIN_RANGE) && (MasterBaudrate <= LPUART_LIN_IP_AUTOBAUD_BAUDRATE_MAX_RANGE))
        {
            /* Calculate Lin baud rate divider */
            MasterBaudrateDivisor = UserConfig->ChannelClock / (UserConfig->OverSamplingRatio * MasterBaudrate);

            /* Assign wakeup signal to satisfy LIN Specifications specifies that wakeup signal shall be in range from 250us to 5 ms */
            if (MasterBaudrate > 10000U)
            {
                /* Wakeup signal will be range from 400us to 800us depend on baudrate */
                WakeupByte = 0x80U;
            }
            else
            {
                /* Wakeup signal will be range from 400us to 4ms depend on baudrate */
                WakeupByte = 0xF8U;
            }

            if ((0U != MasterBaudrateDivisor) && (MasterBaudrateDivisor <= 8191U))
            {
                /* Set the new baudrate divisor value */
                Lpuart_Lin_Ip_HwSetBaudRateDivisor(Base, MasterBaudrateDivisor);
                /* Configure wakeup byte because it depends on baudrate */
                Lpuart_Lin_Ip_au8WakeupSignal[Instance] = WakeupByte;

                /* Update current state and current event */
                LinCurrentState->CurrentEventId = LPUART_LIN_IP_BAUDRATE_ADJUSTED;
                LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_PID;
                /* Disable baudrate evaluation process */
                LinCurrentState->BaudrateEvalEnable = FALSE;
                /* Set Break char detect length as 10 bits minimum */
                Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, LPUART_LIN_IP_BREAK_CHAR_10_BIT_MINIMUM_U8);
            }
            else
            {
                /* Set current event ID to Sync byte is incorrect */
                LinCurrentState->CurrentEventId = LPUART_LIN_IP_SYNC_ERROR;
                /* Change node's current state to IDLE */
                Lpuart_Lin_Ip_GoToIdleState(Instance);
            }
        }
        else
        {
            /* Set current event ID to Sync byte is incorrect */
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_SYNC_ERROR;

            /* Change node's current state to IDLE */
            Lpuart_Lin_Ip_GoToIdleState(Instance);
        }
    }
}

#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON) */

static void Lpuart_Lin_Ip_InitialHwSetup(const uint8 Instance)
{
    LPUART_Type *Base;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;
    /* Get the current LIN User config. */
    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_26();
    /* Check if osr is between 4x and 7x oversampling.
    * If so, then "BOTHEDGE" sampling must be turned on */
    if (UserConfig->OverSamplingRatio < 8U)
    {
        Lpuart_Lin_Ip_HwEnableBothEdgeSamplingCmd(Base);
    }
    /* program the osr value (bit value is one less than actual value) */
    Lpuart_Lin_Ip_HwSetOversamplingRatio(Base, (UserConfig->OverSamplingRatio - 1U));
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_26();
    /* write the sbr value to the BAUD registers */
    Lpuart_Lin_Ip_HwSetBaudRateDivisor(Base, UserConfig->BaudRateDivisor);

    /* Set 8 bit counts per char */
    Lpuart_Lin_Ip_HwSetBitCountPerChar(Base, LPUART_LIN_IP_8_BITS_PER_CHAR, FALSE);

    /* Set no parity mode */
    Lpuart_Lin_Ip_HwSetParityMode(Base, LPUART_LIN_IP_PARITY_DISABLED);
    /* One stop bit */
    Lpuart_Lin_Ip_HwSetStopBitCount(Base, LPUART_LIN_IP_ONE_STOP_BIT);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetStatusFromFrameError
 * Description   : This function used for checking FrameError return status of each event
 * This is not a public API as it is called from other driver functions.
 *
 * Implements    : Lpuart_Lin_Ip_AutobaudTimerValEval_Activity
 *END**************************************************************************/
static Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatusFromFrameError(const uint8 Instance)
{
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    Lpuart_Lin_Ip_TransferStatusType RetStatus = LPUART_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = (const Lpuart_Lin_Ip_StateStructType *)Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    switch (LinCurrentState->PreviousNodeState)
    {
        case LPUART_LIN_IP_NODE_STATE_SEND_DATA:
            RetStatus = LPUART_LIN_IP_STATUS_TX_ERROR;
            break;
        case LPUART_LIN_IP_NODE_STATE_RECV_DATA:
            RetStatus = LPUART_LIN_IP_STATUS_RX_ERROR;
            break;
        case LPUART_LIN_IP_NODE_STATE_RECV_SYNC:
             /* fall-through */
        case LPUART_LIN_IP_NODE_STATE_RECV_PID:
            RetStatus = LPUART_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        case LPUART_LIN_IP_NODE_STATE_SEND_SYNC:
            /* fall-through */
        case LPUART_LIN_IP_NODE_STATE_SEND_PID:
            RetStatus = LPUART_LIN_IP_STATUS_TX_HEADER_ERROR;
            break;
        default:
            /* Do nothing */
            break;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_DisableAllInterrupt
 * Description   : This function clear all the interrupts that can be possible enabled during the execution are disabled at the beginning.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_DisableAllInterrupt(const uint8 Instance)
{
    LPUART_Type * Base;

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_OVERRUN, FALSE);
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_FRAME_ERR_FLAG, FALSE);
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, FALSE);
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL, FALSE);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_IRQHandlerWhenInitializedExceptBreakIRQ
 * Description   : This function used for handling interrupt when driver initialized expect handling break detect interrupt
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_IRQHandlerWhenInitializedExceptBreakIRQ(const uint8 Instance)
{
    const LPUART_Type *Base;
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
#ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
#endif
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

    /* Get Base address of the LPUART instance. */
    Base = (const LPUART_Type *)Lpuart_Lin_Ip_apxBases[Instance];

#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
    /* If LPUART_RX Pin Active Edge has been detected, falling if RXINV = 0, rising if RXINV=1*/
    if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_RX_ACTIVE_EDGE_DETECT) && Lpuart_Lin_Ip_HwGetIntMode(Base, LPUART_LIN_IP_INT_RX_ACTIVE_EDGE))
    {
        Lpuart_Lin_Ip_ProcessWakeupDetect(Instance);
    }
    else
#endif /* LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION */
    {
        /* If Framing Error has been detected */
        if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_FRAME_ERR) && Lpuart_Lin_Ip_HwGetIntMode(Base, LPUART_LIN_IP_INT_FRAME_ERR_FLAG))
        {
            #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
            #ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
            LinCurrentState->TimerCounting = FALSE;
            /* Call notification to stop timer when frame error */
            LPUART_LIN_IP_STOP_TIMER_NOTIFICATION(Instance);
            #endif
            #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

            Lpuart_Lin_Ip_FrameErrorIrqHandler(Instance);
        }
        /* If Overrun Error has been detected */
        else if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_RX_OVERRUN) && Lpuart_Lin_Ip_HwGetIntMode(Base, LPUART_LIN_IP_INT_RX_OVERRUN))
        {
            Lpuart_Lin_Ip_RxOverrunErrorProcess(Instance);
        }
        /* Check full received register flag and handler */
        else if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_RX_DATA_REG_FULL) && Lpuart_Lin_Ip_HwGetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL))
        {
            Lpuart_Lin_Ip_FrameIrqHandler(Instance);
        }
        else
        {
            /* CPR_RTD_00664.lin Spurious interrupt*/
            /* Do nothing - Return immediately */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwSetTransceiverCmd
 * Description   : This function used for enable or disable Transmitter and Receiver
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_HwSetTransceiverCmd(const uint8 Instance, boolean Enable)
{
    LPUART_Type * Base;
    Lpuart_Lin_Ip_StatusType RetStatus = LPUART_LIN_IP_STATUS_SUCCESS;
    boolean TimeoutOccuredTx = FALSE;
    boolean TimeoutOccuredRx = FALSE;

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    TimeoutOccuredTx = Lpuart_Lin_Ip_HwSetTransmitterCmd(Base, Enable);
    TimeoutOccuredRx = Lpuart_Lin_Ip_HwSetReceiverCmd(Base, Enable);

    /*Check TX/RX is enable/disable successful or not?*/
    if (TimeoutOccuredTx || TimeoutOccuredRx)
    {
        RetStatus = LPUART_LIN_IP_STATUS_ERROR;
    }

    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_AbortTransferWhenBusBusy
 * Description   : This function used for abort transfer data when bus is busy
 * This is not a public API as it is called from other driver functions.
 * The function created to reduce HIS_CALLS for Lpuart_Lin_Ip_AbortTransferData() function
 *
 *END**************************************************************************/
static Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_AbortTransferWhenBusBusy(const uint8 Instance, boolean NodeFunction, Lpuart_Lin_Ip_NodeStateType CurrentNodeState)
{
    LPUART_Type * Base;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    uint8 TmpByte;
    Lpuart_Lin_Ip_StatusType RetVal = LPUART_LIN_IP_STATUS_ERROR;

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Check if the current node is MASTER and it in the SEND BREAK BYTE state. In this case we must wait for the completion of the BREAK FIELD transmission and check the STAT[LBKDIF] flag
    and also for the completion of the break byte sending*/
    if (((boolean)LPUART_LIN_IP_MASTER == NodeFunction) && (CurrentNodeState == LPUART_LIN_IP_NODE_STATE_SEND_BREAK_FIELD))
    {
        /* Wait until the data is completely shifted out of shift register and the breakbyte has been detected*/
        Lpuart_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, LPUART_LIN_IP_TIMEOUT_VALUE_US, LPUART_LIN_IP_TIMEOUT_TYPE);
        do
        {
            if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_BREAK_DETECT) && Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_TX_COMPLETE))
            {
                /* Abort transmission completed, change return value */
                RetVal = LPUART_LIN_IP_STATUS_SUCCESS;
                break;
            }
        }
        while (!Lpuart_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, LPUART_LIN_IP_TIMEOUT_TYPE));

        /* Clear the flag */
        (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_BREAK_DETECT);
    }
    else /* Bus is busy so in all the other cases of transfer in progress check the READBACK BYTE RECEPTION completed (STAT[RDRF] flag)*/
    {
            /* Wait until the data is completely shifted out of shift register */
        Lpuart_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, LPUART_LIN_IP_TIMEOUT_VALUE_US, LPUART_LIN_IP_TIMEOUT_TYPE);
        do
        {
            if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_RX_DATA_REG_FULL))
            {
                /* Abort transmission completed, change return value */
                RetVal = LPUART_LIN_IP_STATUS_SUCCESS;
                break;
            }
        }
        while (!Lpuart_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, LPUART_LIN_IP_TIMEOUT_TYPE));
    }

    /* Get data from Data Register to Clear LPUART_LIN_IP_RX_DATA_REG_FULL flag in both cases */
    Lpuart_Lin_Ip_HwGetchar(Base, &TmpByte);

    return RetVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwSetBreakCharInInit
 * Description   : This function used for setting up Break Character in Init mode
 * This is not a public API as it is called from other driver functions.
 * The function created to reduce HIS_CALLS for Lpuart_Lin_Ip_Init() function
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_HwSetBreakCharInInit(const uint8 Instance, const Lpuart_Lin_Ip_UserConfigType * UserConfig)
{
    LPUART_Type *Base;

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Check if the current node is MASTER */
    if ((boolean)LPUART_LIN_IP_MASTER == UserConfig->NodeFunction)
    {
        /* Set Break char length as 13 bits minimum */
        Lpuart_Lin_Ip_HwSetBreakCharTransmitLength(Base, UserConfig->BreakLength);
        /* Set Break char detect length as 11 bits minimum */
        Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, UserConfig->BreakLengthDetect);
    }
    else
    {
        /* Set Break char detect length as 11 bits minimum */
        Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, UserConfig->BreakLengthDetect);
        /* Enable LIN break detect interrupt */
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, TRUE);
    }
}
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_Init
 * Description   : This function initializes a LPUART instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the LPUART module transmitter and receiver.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_Init_Activity
*/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_Init(const uint8 Instance, const Lpuart_Lin_Ip_UserConfigType * UserConfig)
{
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *CrtStateStruct;
    Lpuart_Lin_Ip_StatusType RetStatus = LPUART_LIN_IP_STATUS_SUCCESS;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
    LPUART_LIN_IP_DEV_ASSERT((uint8)Instance == UserConfig->Instance);
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];
    /* Check if current instance is already initialized. */

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR == Lpuart_Lin_Ip_apxStateStructureArray[Instance]);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the pointer of the state structure  */
    CrtStateStruct = UserConfig->StateStruct;
    /* Save LIN user config structure pointer. */
    Lpuart_Lin_Ip_apxUserConfigs[Instance] = UserConfig;
    /* Init LPUART */
    Lpuart_Lin_Ip_HwInit(Base);

    Lpuart_Lin_Ip_InitialHwSetup(Instance);

    Lpuart_Lin_Ip_HwSetBreakCharInInit(Instance, UserConfig);

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    /* if autobaud is enabled */
    /* Setting Slave's baudrate to 19200 will help Slave node always */
    /* detect LIN Break from Master.The config has been generated in config file */
    if ((UserConfig->AutobaudEnable) && ((boolean)LPUART_LIN_IP_SLAVE == UserConfig->NodeFunction))
    {
        CrtStateStruct->ActiveEdgeInterruptCount = 0U;
        CrtStateStruct->BaudrateEvalEnable = TRUE;
        Lpuart_Lin_Ip_au32Previous2BitsTimeLen[Instance] = 0U;
        Lpuart_Lin_Ip_au8CountMeasure[Instance] = 0U;
        Lpuart_Lin_Ip_au32TimeMeasure[Instance] = 0U;
        /* Disable LIN break detect interrupt */
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, FALSE);
    }
    else
    {
        CrtStateStruct->BaudrateEvalEnable = FALSE;
    }

#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON) */

    /* Clear interupt flag for guarantee */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_ALL_INT_FLAGS);
    /* Enable RX overrun interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_OVERRUN, TRUE);
    /* Disable RX complete interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL, FALSE);
    /* Enable frame error interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_FRAME_ERR_FLAG, TRUE);

    /* Change node's current state to IDLE */
    CrtStateStruct->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_IDLE;

    /* Clear flags in current LIN state structure */
    CrtStateStruct->IsBusBusy = FALSE;


#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #if defined(LPUART_LIN_IP_STOP_TIMER_NOTIFICATION) && defined(LPUART_LIN_IP_START_TIMER_NOTIFICATION)
    /* Default value for the Timercounting flag */
    CrtStateStruct->TimerCounting = FALSE;
    #endif
#endif

    /* Assign wakeup signal to satisfy LIN Specifications specifies that
    * wakeup signal shall be in range from 250us to 5 ms.
    */
    Lpuart_Lin_Ip_au8WakeupSignal[Instance] = UserConfig->WakeupByte;
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    if (TRUE == CrtStateStruct->BaudrateEvalEnable)
    {
        /* Disable the LPUART transmitter and receiver */
        RetStatus = Lpuart_Lin_Ip_HwSetTransceiverCmd(Instance, FALSE);
    }
    else
#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON) */
    {
        /* Enable the LPUART transmitter and receiver */
        RetStatus = Lpuart_Lin_Ip_HwSetTransceiverCmd(Instance, TRUE);
    }

    /* Save runtime structure pointer. */
    Lpuart_Lin_Ip_apxStateStructureArray[Instance] = UserConfig->StateStruct;
    /* Set event and node state to default */
    Lpuart_Lin_Ip_apxStateStructureArray[Instance]->CurrentEventId = LPUART_LIN_IP_NO_EVENT;
    Lpuart_Lin_Ip_apxStateStructureArray[Instance]->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_IDLE;

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_Deinit
 * Description   : This function shuts down the LPUART by disabling interrupts and
 *                 transmitter/receiver.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_Deinit_Activity
*/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_Deinit(const uint8 Instance)
{
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    Lpuart_Lin_Ip_StatusType RetStatus = LPUART_LIN_IP_STATUS_SUCCESS;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check if current instance is already de-initialized or is gated.*/
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */
    /*Check if the Bus is busy, driver should return error */
    if (TRUE == LinCurrentState->IsBusBusy)
    {
        /* Transfer is in progress, change return value */
        RetStatus = LPUART_LIN_IP_STATUS_ERROR;
    }
    else
    {
        /* Disable the LPUART transmitter and receiver */
        RetStatus = Lpuart_Lin_Ip_HwSetTransceiverCmd(Instance, FALSE);

        /* When attempting to disable the transceiver and receiver, the timeout should be checked */
        if (LPUART_LIN_IP_STATUS_SUCCESS == RetStatus)
        {
            /* Change node's current state to UNINIT */
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_UNINIT;
        }
        else
        {
            /* Do nothing */
        }
        /* Clear all interrupt flag */
        (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_ALL_INT_FLAGS);
        /* Disable all interrupts */
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_OVERRUN, FALSE);
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_FRAME_ERR_FLAG, FALSE);
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, FALSE);
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL, FALSE);
        /* Clear our saved pointer to the LIN state structure */
        Lpuart_Lin_Ip_apxStateStructureArray[Instance] = NULL_PTR;
    }

    return RetStatus;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_AbortTransferData
 * Description   : Aborts an on-going non-blocking transmission/reception.
 * While performing a non-blocking transferring data, users can call this
 * function to terminate immediately the transferring.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_AbortTransferData_Activity
*/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_AbortTransferData(const uint8 Instance)
{
    Lpuart_Lin_Ip_StatusType RetVal;
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;
    const uint8 *DummyBuff;
    volatile Lpuart_Lin_Ip_TransferStatusType TransmissionStatus;

    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];
#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check if current instance is already de-initialized or is gated.*/
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check if current instance is already de-initialized or is gated.*/
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* In order to prevent a jump to ISR during this function execution, all the interrupts that can be possible enabled during the execution are disabled at the beginning.*/
    Lpuart_Lin_Ip_DisableAllInterrupt(Instance);
    /*Call Lpuart_Lin_Ip_GetStatus to get status of current node*/
    TransmissionStatus = Lpuart_Lin_Ip_GetStatus(Instance, &DummyBuff);
    (void)DummyBuff;
    /*Add label Fault Injecton */
    MCAL_FAULT_INJECTION_POINT(LPUART_FIP_1_T_TIME_OUT_1);

    /* Check if driver is ongoing transmission in some case as : Master: Ongoing transmission (Header or Response). Slave: Ongoing transmission response" */
    /* The LIN driver shall abort the current frame transmission if a new frame transmission is requested by the LIN interface (see LinSendFrame), also if an ongoing transmission may be still in progress or unsuccessfully completed */
    if (LPUART_LIN_IP_STATUS_TX_BUSY != TransmissionStatus)
    {
        /* Abort transmission completed, change return value */
        RetVal = LPUART_LIN_IP_STATUS_SUCCESS;
    }
    else /* Bus is busy */
    {
        RetVal = Lpuart_Lin_Ip_AbortTransferWhenBusBusy(Instance, UserConfig->NodeFunction, LinCurrentState->CurrentNodeState);
    }

#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
#ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
    if (LinCurrentState->TimerCounting)
    {
        /* Call notification to stop timer in case this is counting */
        LPUART_LIN_IP_STOP_TIMER_NOTIFICATION(Instance);
    }
#endif
#endif

    /* Change node's current state to IDLE */
    Lpuart_Lin_Ip_GoToIdleState(Instance);

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GoToSleepMode
 * Description   : This function puts current LIN node to sleep mode.
 * This function changes current node state to LPUART_LIN_IP_NODE_STATE_SLEEP_MODE.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_GoToSleepMode_Activity
*/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_GoToSleepMode(const uint8 Instance)
{
    Lpuart_Lin_Ip_StatusType RetVal = LPUART_LIN_IP_STATUS_SUCCESS;
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;
#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON)*/

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    /* Get user configuration */
    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];
#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON)*/

    if (LinCurrentState->IsBusBusy)
    {
        /* Must abort current transfer */
        RetVal = LPUART_LIN_IP_STATUS_ERROR;
    }
    else
    {
        if (LPUART_LIN_IP_NODE_STATE_SLEEP_MODE != LinCurrentState->CurrentNodeState)
        {
            /* Get Base address of the LPUART instance. */
            Base = Lpuart_Lin_Ip_apxBases[Instance];
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_NO_EVENT;
            /* Update node's current state to SLEEP_MODE. */
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SLEEP_MODE;
            /* Set Break char detect length as 10 bits minimum */
            Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, LPUART_LIN_IP_BREAK_CHAR_10_BIT_MINIMUM_U8);
#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
            /* Set Receive data not inverted to detecting the falling edge of wake up signal corresponding Start bit */
            Lpuart_Lin_Ip_HwSetRxDataPolarity(Base, FALSE);
            /* Clear LPUART_RX Pin Active Edge Interrupt Flag. */
            (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_RX_ACTIVE_EDGE_DETECT);
            /* Enable RX Input Active Edge interrupt */
            Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_ACTIVE_EDGE, TRUE);
#endif /* LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION*/
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
            /* Set Lpuart_Lin_Ip_au8CountMeasure to one */
            if ((UserConfig->AutobaudEnable) && ((boolean)LPUART_LIN_IP_SLAVE == UserConfig->NodeFunction))
            {
                Lpuart_Lin_Ip_au8CountMeasure[Instance] = 1U;
                /* Disable RX Input Active Edge interrupt when using autobaud feature */
                Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_ACTIVE_EDGE, FALSE);
            }
#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON)*/
            /* Disable overrun error interrupt, the overrun interrupt in wakeup pulse is ignored and the flag overrun will clear when call Lpuart_Lin_Ip_GoToIdleState() */
            Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_OVERRUN, FALSE);
            /* Disable frame error interrupt, wakeup pulse may greater than normal frame duration and lead to frame error */
            Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_FRAME_ERR_FLAG, FALSE);

            /* Disable LIN break detect interrupt */
            Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, FALSE);

        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_SendWakeupSignal
 * Description   : This function sends a wakeup signal through the LPUART interface.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_SendWakeupSignal_Activity
*/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_SendWakeupSignal(const uint8 Instance)
{
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    Lpuart_Lin_Ip_StatusType RetVal = LPUART_LIN_IP_STATUS_SUCCESS;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Check if bus is not busy */
    if ((TRUE == LinCurrentState->IsBusBusy) ||
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
        (TRUE == LinCurrentState->BaudrateEvalEnable) ||
#endif
        (LPUART_LIN_IP_NODE_STATE_SLEEP_MODE != LinCurrentState->CurrentNodeState) \
       )
    {
        RetVal = LPUART_LIN_IP_STATUS_ERROR;
    }
    else
    {
        LinCurrentState->IsBusBusy = TRUE;
        /* In Sleep mode, other node can send wakeup signal at the same time lead to frame error may be occurred, so no need to enable frame error checking.
        No need to disbale frame error interrupt again due to it is already disabled in Lpuart_Lin_Ip_GoToSleepMode() */
        /* Rx Complete Interrupt already enabled in Lpuart_Lin_Ip_GoToSleepMode(), it used to set node ready in Idle mode after wakeup byte sent */
        /* Send a wakeup signal */
        Lpuart_Lin_Ip_HwPutchar(Base, Lpuart_Lin_Ip_au8WakeupSignal[Instance]);
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_TimerExpiredService
 * Description   : This is callback function for Timer Interrupt Handler.
 * Users shall initialize a timer (for example FTM)
 * and the time period in microseconds will be set by the driver via LinLpuartStartTimerNotification.
 * In timer IRQ handler, call this function.
 *
 *END**************************************************************************/
 /**
* @implements Lpuart_Lin_Ip_TimerExpiredService_Activity
*/
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
void Lpuart_Lin_Ip_TimerExpiredService(const uint8 Instance)
{
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;

    #if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
    #endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART Instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    UserConfig   = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    #if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
    #endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    #ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = FALSE;
    /* Call notification to stop timer when timeout occurred */
    LPUART_LIN_IP_STOP_TIMER_NOTIFICATION(Instance);
    #endif

    /* Check LIN node's current state when timeout occurred */
    switch (LinCurrentState->CurrentNodeState)
    {
        /* If the node is receiving SYNC byte */
        case LPUART_LIN_IP_NODE_STATE_RECV_SYNC:
            /* fall-through */
        /* If the node is receiving PID byte */
        case LPUART_LIN_IP_NODE_STATE_RECV_PID:
            /* fall-through */
        /* If the node is receiving DATA response bytes */
        case LPUART_LIN_IP_NODE_STATE_RECV_DATA:
            /* fall-through */
        /* If the node is receiving CHECKSUM byte */
        case LPUART_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED:
            /* Set current event to timeout error */
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_TIMEOUT_ERROR;
            /* Change node's current state to IDLE to switch lin node ready operation soon */
            Lpuart_Lin_Ip_GoToIdleState(Instance);
            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Instance, LinCurrentState);
            }
            break;
        default:
            /* The node state is not receiving header, response data bytes or checksum */
            break;
    }
}
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_SendFrame
 * Description   : This function sends frame out through the LPUART module
 * using a non-blocking method. Non-blocking  means that the function returns
 * immediately. This function sends header and response with
 * correct information. This function also check node's current state is in
 * SLEEP mode then the function will return LPUART_LIN_IP_STATUS_ERROR. And check if IsBusBusy is
 * currently TRUE then the function will return LPUART_LIN_IP_STATUS_BUSY.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_SendFrame_Activity
*/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_SendFrame(const uint8 Instance, const Lpuart_Lin_Ip_PduType *PduInfo)
{
    Lpuart_Lin_Ip_StatusType RetVal = LPUART_LIN_IP_STATUS_SUCCESS;
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    boolean CheckSleepMode;
    boolean CheckPid;
    boolean CheckDl;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != PduInfo);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    LinCurrentState = (const Lpuart_Lin_Ip_StateStructType *)Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    /* Check whether current mode is sleep mode */
    CheckSleepMode = (LPUART_LIN_IP_NODE_STATE_SLEEP_MODE == LinCurrentState->CurrentNodeState);
    /* Check whether Pid is valid */
    CheckPid = (0xFFu == Lin_Ip_ProcessParity(PduInfo->Pid, LIN_IP_CHECK_PARITY));
    /* Check whether data length is in range */
    CheckDl = (0u == PduInfo->Dl) || (8u < PduInfo->Dl);

    /* Check if valid state and frame information */
    if (CheckPid || CheckDl ||
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
        (TRUE == LinCurrentState->BaudrateEvalEnable) ||
#endif
        CheckSleepMode \
       )
    {
        RetVal = LPUART_LIN_IP_STATUS_ERROR;
    }
    else
    {
        /* Check if the LIN bus is busy */
        if (LinCurrentState->IsBusBusy)
        {
            RetVal = LPUART_LIN_IP_STATUS_BUSY;
        }
        else
        {
            /* Start to send frame */
            Lpuart_Lin_Ip_StartSendFrame(Instance, PduInfo);
        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GoToIdleState
 * Description   : This function puts current node to Idle state.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_GoToIdleState_Activity
*/
void Lpuart_Lin_Ip_GoToIdleState(const uint8 Instance)
{
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];
    /* Get user configuration */
    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];
#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
    /* Set Receive data not inverted */
    Lpuart_Lin_Ip_HwSetRxDataPolarity(Base, FALSE);

    /* Disable RXEDG interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_ACTIVE_EDGE, FALSE);
#endif /* LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION */

    /* Clear overrun error interrupt */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_RX_OVERRUN);
    /* Enable overrun error interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_OVERRUN, TRUE);
    /* Clear frame error interrupt */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_FRAME_ERR);
    /* Enable frame error interrupt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_FRAME_ERR_FLAG, TRUE);

    /* Disable Rx buffer full interurpt */
    Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL, FALSE);

    if ((boolean)LPUART_LIN_IP_SLAVE == UserConfig->NodeFunction)
    {
        /* Clear LIN break detect interrupt */
        (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_BREAK_DETECT);
        /* Set Break char detect length as configuration */
        Lpuart_Lin_Ip_HwSetBreakCharDetectLength(Base, UserConfig->BreakLengthDetect);
        /* Only in slave mode, break detection interrupt should be enabled to know new frame. Be side that, the interrupt of master is enable when start transmit a new frame */
        /* Enable LIN break detect interrupt */
        Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT, TRUE);
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
        /* Set ActiveEdgeInterruptCount and Lpuart_Lin_Ip_au8CountMeasure to zero */
        if (UserConfig->AutobaudEnable)
        {
            LinCurrentState->ActiveEdgeInterruptCount = 0U;
            Lpuart_Lin_Ip_au8CountMeasure[Instance] = 0U;
        }
#endif /* (LPUART_LIN_IP_AUTO_BAUD == STD_ON)*/
    }

    /* Restored current state to get status */
    LinCurrentState->PreviousNodeState = LinCurrentState->CurrentNodeState;
    /* Change node's current state to IDLE */
    LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_IDLE;
    /* Clear Bus busy Flag */
    LinCurrentState->IsBusBusy = FALSE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_GetStatus
 * Description   : This function give current state of the Lin instance.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_GetStatus_Activity
*/
Lpuart_Lin_Ip_TransferStatusType Lpuart_Lin_Ip_GetStatus(const uint8 Instance, const uint8 **Buffer)
{
    const Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;
    Lpuart_Lin_Ip_TransferStatusType RetStatus = LPUART_LIN_IP_STATUS_FAIL;
    Lpuart_Lin_Ip_NodeStateType CurrentNodeState;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != Buffer);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = (const Lpuart_Lin_Ip_StateStructType *)Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    CurrentNodeState = LinCurrentState->CurrentNodeState;

    switch (LinCurrentState->CurrentEventId)
    {
        case LPUART_LIN_IP_SYNC_ERROR:
            /* fall-through */
        case LPUART_LIN_IP_PID_ERROR:
            /* Error occurred in header reception */
            RetStatus = LPUART_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        case LPUART_LIN_IP_RECV_BREAK_FIELD_OK:
            if ((boolean)LPUART_LIN_IP_MASTER == UserConfig->NodeFunction)
            {
                RetStatus = LPUART_LIN_IP_STATUS_TX_BUSY;
            }
            else
            {
                RetStatus = LPUART_LIN_IP_STATUS_RX_HEADER_BUSY;
            }
            break;
        case LPUART_LIN_IP_BAUDRATE_ADJUSTED:
            /* Header reception is processing */
            RetStatus = LPUART_LIN_IP_STATUS_RX_HEADER_BUSY;
            break;
        case LPUART_LIN_IP_SEND_HEADER_OK:
            /* Call Lpuart_Lin_Ip_GetStatusFromSendHeaderOk to get status from send header event is successfully */
            RetStatus = Lpuart_Lin_Ip_GetStatusFromSendHeaderOk(Instance, CurrentNodeState);

            break;
        case LPUART_LIN_IP_RECV_HEADER_OK:
            /* Received a vaild header*/
            RetStatus = LPUART_LIN_IP_STATUS_RX_HEADER_OK;
            break;
        case LPUART_LIN_IP_WAKEUP_SIGNAL:
            RetStatus = LPUART_LIN_IP_STATUS_OPERATIONAL;
            break;
        case LPUART_LIN_IP_RX_OVERRUN_ERROR:
            /* fall-through */
        case LPUART_LIN_IP_FRAME_ERROR:
            /* Found cause of the error from header or reponse */
            RetStatus = Lpuart_Lin_Ip_GetStatusFromFrameError(Instance);
            break;
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        case LPUART_LIN_IP_TIMEOUT_ERROR:
            /* Call Lpuart_Lin_Ip_GetStatusFromTimeoutError to get status from time out error event */
            RetStatus = Lpuart_Lin_Ip_GetStatusFromTimeoutError(Instance);

            break;
#endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
        case LPUART_LIN_IP_READBACK_ERROR:
            /* Call Lpuart_Lin_Ip_GetStatusFromReadBackError to get status from readback error event */
            RetStatus = Lpuart_Lin_Ip_GetStatusFromReadBackError(Instance);

            break;
        case LPUART_LIN_IP_CHECKSUM_ERROR_EVENT:
            /* Received checksum byte is incorrect */
            RetStatus = LPUART_LIN_IP_STATUS_RX_ERROR;
            break;
        case LPUART_LIN_IP_TX_COMPLETED:
            RetStatus = LPUART_LIN_IP_STATUS_TX_OK;
            break;
        case LPUART_LIN_IP_RX_COMPLETED:
            RetStatus = LPUART_LIN_IP_STATUS_RX_OK;
            *Buffer = Lpuart_Lin_Ip_au8SduBuffer[Instance];
            break;
        case LPUART_LIN_IP_NO_EVENT:
            /* Call Lpuart_Lin_Ip_GetStatusFromNoEvent to get status when no event */
            RetStatus = Lpuart_Lin_Ip_GetStatusFromNoEvent(CurrentNodeState);
            break;
        default:
            RetStatus = LPUART_LIN_IP_STATUS_FAIL;
            break;
    }

    return RetStatus;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_IRQHandler
 * Description   : Interrupt handler for LPUART.
 * This handler uses the buffers stored in the Lpuart_Lin_Ip_StateStructType struct to transfer
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
/**
* @implements Lpuart_Lin_Ip_IRQHandler_Activity
*/
void Lpuart_Lin_Ip_IRQHandler(const uint8 Instance)
{
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the LPUART instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];
    /* Get the current LIN state of this LPUART instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    /* Check instance was initialized or not */
    if (NULL_PTR == LinCurrentState)
    {
        /* Clear all interrupt flag */
        (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_ALL_INT_FLAGS);
    }
    else
    {
        /* If LIN break character has been detected. */
        if (Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_BREAK_DETECT) && Lpuart_Lin_Ip_HwGetIntMode(Base, LPUART_LIN_IP_INT_BREAK_DETECT))
        {
            Lpuart_Lin_Ip_ProcessBreakDetect(Instance);
        }
        else
        {
            Lpuart_Lin_Ip_IRQHandlerWhenInitializedExceptBreakIRQ(Instance);
        }
    }
} /* End void Lpuart_Lin_Ip_IRQHandler(uint8 Instance) */
#ifdef LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_CheckWakeupSignal
 * Description   : This function check if a dominant signal received is a wakeup
 *                signal.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_CheckWakeupSignal(const uint8 Instance)
{
    uint32 WakeupSignalLength = 0U;

    LPUART_Type * Base = Lpuart_Lin_Ip_apxBases[Instance];
    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    /* Clear LPUART_RX Pin Active Edge Interrupt Flag. */
    (void)Lpuart_Lin_Ip_HwClearStatusFlag(Base, LPUART_LIN_IP_RX_ACTIVE_EDGE_DETECT);

    /* If Lpuart_Lin_Ip_HwGetRxDataPolarity is 0: Receive Data is not inverted meaning that active edge is falling (Start bit)*/
    if (FALSE == Lpuart_Lin_Ip_HwGetRxDataPolarity(Base))
    {
        /* Start measure time when detecting the falling edge of Start bit */
        LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION(Instance, &WakeupSignalLength);
        /* Set Receive Data Inverted to detecte the rising edge of Wake up signal corresponding Stop bit */
        Lpuart_Lin_Ip_HwSetRxDataPolarity(Base, TRUE);
    }
    else
    {

        /* Calculate time interval between the falling and rising edge */
        LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION(Instance, &WakeupSignalLength);

        /*If length of the dominant signal is longer than 150 us and less than 5 ms for Master and Slave node, it is a wake up signal */
        if ((WakeupSignalLength >= LPUART_LIN_IP_WAKEUP_TIME_MIN_IN_NS) && (WakeupSignalLength <= LPUART_LIN_IP_WAKEUP_TIME_MAX_IN_NS))
        {
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_WAKEUP_SIGNAL;

            /* Callback will only call when current node detects a wake-up signal sent by other */
            if (FALSE == LinCurrentState->IsBusBusy)
            {
                /* Change node's state to IDLE to ready operation */
                Lpuart_Lin_Ip_GoToIdleState(Instance);

                if (NULL_PTR != UserConfig->Callback)
                {
                    /* Callback to handle event: Received a wakeup signal */
                    UserConfig->Callback(Instance, LinCurrentState);
                }
            }
            else
            {
                /* Change node's state to IDLE to ready operation */
                Lpuart_Lin_Ip_GoToIdleState(Instance);
            }
        }
        else
        {
            /*When falling edge of Stop bit is detected, Setting RXINV bit to default value (0 - Receive data not inverted)*/
            Lpuart_Lin_Ip_HwSetRxDataPolarity(Base, FALSE);
            /* Reset bus busy in the case of wakeup pulse was generated by current node */
            LinCurrentState->IsBusBusy = FALSE;
        }
    }
}
#endif /* LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION */
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_ProcessReceiveFrameData
 * Description   : Part of Interrupt handler for receiving.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_ProcessReceiveFrameData(const uint8 Instance, const uint8 ReadData)
{
    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* RxSize plused checksum byte to it, so must to decrease 1 in if condition */
    Lpuart_Lin_Ip_GetBytetoBuffer(LinCurrentState->CntByte, \
                                  LinCurrentState->RxSize - 1U, \
                                  Instance, \
                                  ReadData \
                                 );

    if ((LPUART_LIN_IP_CHECKSUM_ERROR_EVENT != LinCurrentState->CurrentEventId) \
        && (LPUART_LIN_IP_RX_COMPLETED != LinCurrentState->CurrentEventId) \
       )
    {
        /* Increase index to receive next byte */
       LinCurrentState->CntByte++;
    }
    else
    {
        /* callback function to handle checksum error or reception completed */
    #if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        #ifdef LPUART_LIN_IP_STOP_TIMER_NOTIFICATION
        LinCurrentState->TimerCounting = FALSE;
        /* Call notification to stop timer after checksum received */
        LPUART_LIN_IP_STOP_TIMER_NOTIFICATION(Instance);
        #endif
    #endif /* (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

        /* Change node's current state to IDLE */
        Lpuart_Lin_Ip_GoToIdleState(Instance);

        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }
    }
}

static void Lpuart_Lin_Ip_HandleSendDataEvent(const uint8 Instance, boolean SendFlag)
{
    /* Get Base address of the LPUART instance. */
    LPUART_Type * Base = Lpuart_Lin_Ip_apxBases[Instance];

    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    if (SendFlag)
    {
        if (LinCurrentState->CntByte < LinCurrentState->TxSize)
        {
            /* Send checksum byte */
            if (1U == (LinCurrentState->TxSize - LinCurrentState->CntByte))
            {
                Lpuart_Lin_Ip_HwPutchar(Base, LinCurrentState->Checksum);
            }
            /* Send data bytes */
            else
            {
                Lpuart_Lin_Ip_HwPutchar(Base, *LinCurrentState->TxBuff);
            }
        }
        else
        {
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_TX_COMPLETED;
            LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED;

            /* Change node's current state to IDLE */
            Lpuart_Lin_Ip_GoToIdleState(Instance);

            /* callback function to handle event TX COMPLETED */
            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Instance, LinCurrentState);
            }

        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_ProcessSendFrameData
 * Description   : Part of Interrupt handler for sending data.
 *
 *END**************************************************************************/
static void Lpuart_Lin_Ip_ProcessSendFrameData(const uint8 Instance, const uint8 TmpByte)
{
    boolean SendFlag = TRUE;
    uint8 TmpSize;
    boolean TmpCheckSumAndSize;
    boolean TmpBuffAndSize;

    /* Get Base address of the LPUART instance. */
    const LPUART_Type *Base = (const LPUART_Type*)Lpuart_Lin_Ip_apxBases[Instance];

    /* Get the current LIN user config structure of this LPUART instance. */
    const Lpuart_Lin_Ip_UserConfigType * UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    /* Get the current LIN state of this LPUART instance. */
    Lpuart_Lin_Ip_StateStructType * LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];

    /* Check if Tx data register empty flag is FALSE */
    if (TRUE != Lpuart_Lin_Ip_HwGetStatusFlag(Base, LPUART_LIN_IP_TX_DATA_REG_EMPTY))
    {
        LinCurrentState->CurrentEventId = LPUART_LIN_IP_READBACK_ERROR;

        /* Change node's current state to IDLE */
        Lpuart_Lin_Ip_GoToIdleState(Instance);

        /* callback function to handle Readback error */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Instance, LinCurrentState);
        }
        SendFlag = FALSE;
    }
    else
    {
        TmpSize = (uint8)(LinCurrentState->TxSize - LinCurrentState->CntByte);
        TmpCheckSumAndSize = (1U  == TmpSize) && (LinCurrentState->Checksum != TmpByte);
        TmpBuffAndSize = (TmpByte != *LinCurrentState->TxBuff) && (1U != TmpSize);

        if (TmpBuffAndSize || TmpCheckSumAndSize)
        {
            LinCurrentState->CurrentEventId = LPUART_LIN_IP_READBACK_ERROR;

            /* Change node's current state to IDLE */
            Lpuart_Lin_Ip_GoToIdleState(Instance);

            /* callback function to handle Readback error */
            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Instance, LinCurrentState);
            }
            SendFlag = FALSE;
        }
        else
        {
            LinCurrentState->TxBuff++;
            LinCurrentState->CntByte++;
        }
    }

    Lpuart_Lin_Ip_HandleSendDataEvent(Instance, SendFlag);
}

#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
/*FUNCTION************************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_AutoBaudCapture
 * Description   : This function capture bits time to detect break char, calculate
 * baudrate from sync bits and enable transceiver if autobaud successful.
 * This function should only be used in Slave.
 *END*****************************************************************************/
/**
 * Implements    : Lpuart_Lin_Ip_AutoBaudCapture_Activity
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_AutoBaudCapture(uint8 Instance)
{
    LPUART_Type *Base;
    Lpuart_Lin_Ip_StateStructType *LinCurrentState;
    const Lpuart_Lin_Ip_UserConfigType *UserConfig;
    Lpuart_Lin_Ip_StatusType RetVal = LPUART_LIN_IP_STATUS_BUSY;
    uint32 TmpTime = 0U;
    uint8 DiscardData;

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LPUART_LIN_IP_DEV_ASSERT(LPUART_INSTANCE_COUNT > Instance);
#endif /* (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LPUART Instance. */
    LinCurrentState = Lpuart_Lin_Ip_apxStateStructureArray[Instance];
    /* Get Base address of the LPUART Instance. */
    Base = Lpuart_Lin_Ip_apxBases[Instance];
    /* Get user configuration */
    UserConfig = Lpuart_Lin_Ip_apxUserConfigs[Instance];

    if (LinCurrentState->BaudrateEvalEnable)
    {
        /* Calculate time between two consecutive active edges on Rx pin (for service autobaud) in nanosecond */
        LPUART_LIN_IP_TIMER_AUTOBAUD_NOTIFICATION(Instance, &TmpTime);

        /* Get two bits time length */
        Lpuart_Lin_Ip_au32TimeMeasure[Instance] += TmpTime;
        Lpuart_Lin_Ip_au8CountMeasure[Instance] += 1U;
        if (Lpuart_Lin_Ip_au8CountMeasure[Instance] > 1U)
        {
            switch (LinCurrentState->CurrentNodeState)
            {
                /* If current state is SLEEP MODE */
                case LPUART_LIN_IP_NODE_STATE_SLEEP_MODE:
                    /* If length of the dominant signal is longer than 150us, it is a wakeup signal */
                    if (TmpTime >= LPUART_LIN_IP_AUTOBAUD_WAKEUP_TIME_MIN_IN_NS)
                    {
                        LinCurrentState->CurrentEventId = LPUART_LIN_IP_WAKEUP_SIGNAL;

                         /* Callback to handle event: Received a wakeup signal */
                        if (NULL_PTR != UserConfig->Callback)
                        {
                            /* Callback to handle event: Received a wakeup signal */
                            UserConfig->Callback(Instance, LinCurrentState);
                        }

                        /* Change node's state to IDLE */
                        LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_IDLE;
                    }
                    else
                    {
                        RetVal = LPUART_LIN_IP_STATUS_ERROR;
                    }
                    Lpuart_Lin_Ip_au8CountMeasure[Instance] = 0U;

                    break;
                /* If current state is IDLE */
                case LPUART_LIN_IP_NODE_STATE_IDLE:
                    /* Check break time minimum */
                    if ((Lpuart_Lin_Ip_au32TimeMeasure[Instance] - TmpTime) >= LPUART_LIN_IP_AUTOBAUD_BREAK_TIME_MIN)
                    {
                        /* Change the node's current state to RECEIVED BREAK FIELD */
                        LinCurrentState->CurrentEventId = LPUART_LIN_IP_RECV_BREAK_FIELD_OK;

                        /* Callback function */
                        if (NULL_PTR != UserConfig->Callback)
                        {
                            /* Callback to handle event: Received a break field */
                            UserConfig->Callback(Instance, LinCurrentState);
                        }

                        /* Change the node's current state to RECEIVING SYNC FIELD */
                        LinCurrentState->CurrentNodeState = LPUART_LIN_IP_NODE_STATE_RECV_SYNC;

                        /* Start Autobaud Count(initialize number of measurements in sync byte) */
                        LinCurrentState->ActiveEdgeInterruptCount = 0U;

                        Lpuart_Lin_Ip_au32TimeMeasure[Instance] = 0U;

                        Lpuart_Lin_Ip_au8CountMeasure[Instance] = 1U;
                    }
                    else
                    {
                        Lpuart_Lin_Ip_au8CountMeasure[Instance] = 0U;
                        RetVal = LPUART_LIN_IP_STATUS_ERROR;
                    }

                    break;
                /* If current state is RECEIVE SYNC */
                case LPUART_LIN_IP_NODE_STATE_RECV_SYNC:
                    /* Reset time measurement for capture the time interval between first falling edge */
                    if (0U == LinCurrentState->ActiveEdgeInterruptCount)
                    {
                        Lpuart_Lin_Ip_au32TimeMeasure[Instance] = 0U;
                    }
                    /* Increase active edges count */
                    LinCurrentState->ActiveEdgeInterruptCount += 1U;

                    /* Only call Lpuart_Lin_Ip_AutobaudTimerValEval when active edge number 5th,
                    just checking at falling edge then driver will have enough 2 bits time length before and after of SYNC to compare and update the baud rate when receiving whole SYNC */
                    if (LinCurrentState->ActiveEdgeInterruptCount >= 5U)
                    {
                        /* Calculate baudrate */
                        Lpuart_Lin_Ip_AutobaudTimerValEval(Instance, Lpuart_Lin_Ip_au32TimeMeasure[Instance]);
                    }

                    /* Reset to measure in next times */
                    if (LinCurrentState->ActiveEdgeInterruptCount % 2U)
                    {
                        Lpuart_Lin_Ip_au32Previous2BitsTimeLen[Instance] = Lpuart_Lin_Ip_au32TimeMeasure[Instance];
                        Lpuart_Lin_Ip_au32TimeMeasure[Instance] = 0U;
                    }

                    /* If error occur when evaluating Sync field */
                    if (LinCurrentState->CurrentNodeState == LPUART_LIN_IP_NODE_STATE_IDLE)
                    {
                        RetVal = LPUART_LIN_IP_STATUS_ERROR;
                        Lpuart_Lin_Ip_au32Previous2BitsTimeLen[Instance] = 0U;
                        Lpuart_Lin_Ip_au32TimeMeasure[Instance] = 0U;
                        LinCurrentState->ActiveEdgeInterruptCount = 0U;
                        Lpuart_Lin_Ip_au8CountMeasure[Instance] = 0U;

                        /* Callback function to handle event RECEIVED SYNC FIELD ERROR */
                        if (NULL_PTR != UserConfig->Callback)
                        {
                            UserConfig->Callback(Instance, LinCurrentState);
                        }
                    }

                    break;
                default:
                    RetVal = LPUART_LIN_IP_STATUS_ERROR;
                    break;
            }
        }
    }
    else
    {
        if (LinCurrentState->ActiveEdgeInterruptCount >= LPUART_LIN_IP_TOTAL_EDGE_SYNC_FIELD -1U)
        {
            /* Clear Rx complete interrupt flag */
            Lpuart_Lin_Ip_HwGetchar(Base, &DiscardData);
            (void)DiscardData;
            /* Enable RX complete interrupt */
            Lpuart_Lin_Ip_HwSetIntMode(Base, LPUART_LIN_IP_INT_RX_DATA_REG_FULL, TRUE);
            /* Enable the LPUART transmitter and receiver and check if these processes timeout */
            Base->CTRL = (Base->CTRL & ~LPUART_CTRL_RE_MASK) | (1UL << LPUART_CTRL_RE_SHIFT);
            Base->CTRL = (Base->CTRL & ~LPUART_CTRL_TE_MASK) | (1UL << LPUART_CTRL_TE_SHIFT);
            if (((Base->CTRL & (1UL << LPUART_CTRL_RE_SHIFT)) == 0U) || ((Base->CTRL & (1UL << LPUART_CTRL_TE_SHIFT)) == 0U))
            {
                RetVal = LPUART_LIN_IP_STATUS_ERROR;
            }
            else
            {
                RetVal = LPUART_LIN_IP_STATUS_SUCCESS;
                /* Callback to handle event: Received a sync field */
                if (NULL_PTR != UserConfig->Callback)
                {
                    UserConfig->Callback(Instance, LinCurrentState);
                }
            }
            Lpuart_Lin_Ip_au32Previous2BitsTimeLen[Instance] = 0U;
            Lpuart_Lin_Ip_au32TimeMeasure[Instance] = 0U;
            LinCurrentState->ActiveEdgeInterruptCount = 0U;
            Lpuart_Lin_Ip_au8CountMeasure[Instance] = 0U;
        }
    }

    return RetVal;
}
#endif

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
