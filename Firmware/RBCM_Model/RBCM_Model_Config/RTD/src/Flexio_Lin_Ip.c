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
*   @file Flexio_Lin_Ip.c
*
*   @internal
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

#include "Flexio_Lin_Ip.h"
#include "Flexio_Lin_Ip_Irq.h"
#if (STD_ON == FLEXIO_LIN_IP_FLEXIO_USED)
    #include "Flexio_Mcl_Ip_HwAccess.h"
#endif
#include "OsIf.h"
#include "SchM_Lin_43_LPUART_FLEXIO.h"

#if (STD_ON == FLEXIO_LIN_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif /* (STD_ON == FLEXIO_LIN_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_LIN_IP_VENDOR_ID_C                      43
#define FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_LIN_IP_SW_MAJOR_VERSION_C               5
#define FLEXIO_LIN_IP_SW_MINOR_VERSION_C               0
#define FLEXIO_LIN_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Lin_Ip header file are of the same Vendor ID version */
#if (FLEXIO_LIN_IP_VENDOR_ID_C != FLEXIO_LIN_IP_VENDOR_ID)
    #error "Flexio_Lin_Ip.c and Flexio_Lin_Ip.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip header file are of the same Autosar version */
#if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Lin_Ip.c and Flexio_Lin_Ip.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip header file are of the same Software version */
#if ((FLEXIO_LIN_IP_SW_MAJOR_VERSION_C != FLEXIO_LIN_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_MINOR_VERSION_C != FLEXIO_LIN_IP_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_PATCH_VERSION_C != FLEXIO_LIN_IP_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip.c and Flexio_Lin_Ip.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip_Irq header file are of the same Vendor ID version */
#if (FLEXIO_LIN_IP_VENDOR_ID_C != FLEXIO_LIN_IP_IRQ_VENDOR_ID)
    #error "Flexio_Lin_Ip.c and Flexio_Lin_Ip_Irq.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip_Irq header file are of the same Autosar version */
#if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_LIN_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_LIN_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_LIN_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Lin_Ip.c and Flexio_Lin_Ip_Irq.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip_Irq header file are of the same Software version */
#if ((FLEXIO_LIN_IP_SW_MAJOR_VERSION_C != FLEXIO_LIN_IP_IRQ_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_MINOR_VERSION_C != FLEXIO_LIN_IP_IRQ_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IP_SW_PATCH_VERSION_C != FLEXIO_LIN_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip.c and Flexio_Lin_Ip_Irq.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (STD_ON == FLEXIO_LIN_IP_FLEXIO_USED)
    /* Check if current file and Flexio_Mcl_Ip_HwAccess.h header file are of the same Autosar version */
    #if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_Lin_Ip.c and Flexio_Mcl_Ip_HwAccess.h are different"
    #endif
#endif
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_Lin_Ip.c and OsIf.h are different"
    #endif
    /* Check if current file and SchM_Lin_43_LPUART_FLEXIO.h header file are of the same Autosar version */
    #if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_Lin_Ip_Hw_Access.h and SchM_Lin_43_LPUART_FLEXIO.h are different"
    #endif
#if (STD_ON == FLEXIO_LIN_IP_DEV_ERROR_DETECT)
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ((FLEXIO_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_LIN_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_Lin_Ip.c and Devassert.h are different"
    #endif
#endif /* (STD_ON == FLEXIO_LIN_IP_DEV_ERROR_DETECT) */
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32  ((uint32)0x0000FF00UL)
#define FLEXIO_IP_DATA_8BITS_MASK_U32          ((uint32)0x000000FFUL)
#define FLEXIO_IP_MAX_DATA_LENGTH              ((uint8)8UL)
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == FLEXIO_LIN_IP_FLEXIO_USED)
/* Table of base addresses for FLEXIO channels. */
#define LIN_43_LPUART_FLEXIO_START_SEC_CONST_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static FLEXIO_Type * const Flexio_Lin_Ip_apxBases[FLEXIO_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONST_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"


#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static uint8 Flexio_Lin_Ip_au8SduBuffer[FLEXIO_LIN_IP_NUMBER_OF_CHANNELS][FLEXIO_IP_MAX_DATA_LENGTH];

static uint8 Flexio_Lin_Ip_au8ShiftersIndex[FLEXIO_LIN_IP_NUMBER_OF_FLEXIO_SHIFTERS];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

Flexio_Lin_Ip_StateStructType Flexio_Lin_Ip_axStateStructure[FLEXIO_LIN_IP_NUMBER_OF_CHANNELS];

/* Table to save LIN user config structure pointers */
static const Flexio_Lin_Ip_UserConfigType * Flexio_Lin_Ip_apxUserConfigs[FLEXIO_LIN_IP_NUMBER_OF_CHANNELS];

static Flexio_Lin_Ip_StateStructType *Flexio_Lin_Ip_apxStateStructureArray[FLEXIO_LIN_IP_NUMBER_OF_CHANNELS];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Flexio_Lin_Ip_ErrInterruptHandler(const uint8 Channel, uint8 ShiftErrMask);
static void Flexio_Lin_Ip_RxInterruptHandler(const uint8 Channel);
static void Flexio_Lin_Ip_WakeupInterruptHandler(const uint8 Channel, const uint16 Data);
static void Flexio_Lin_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter);
static boolean Flexio_Lin_Ip_TimeoutExpired(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter);
static void Flexio_Lin_Ip_RxPidByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_SlaveRxSyncByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_RxBreakFrameProcess(const uint8 Channel, const uint16 Data);
static void Flexio_Lin_Ip_RxSyncByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_SlaveRxPidByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_RxDataByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_RxCheckSumByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_RxSlaveResCheckSumByteProcess(const uint8 Channel, const uint8 Data);
static void Flexio_Lin_Ip_SlaveRxBreakLengthProcess(const uint8 Channel, const uint16 Data);
static void Flexio_Lin_Ip_AsyncSendFrameData (const uint8 Channel);
static void Flexio_Lin_Ip_AsyncReceiveFrameData(const uint8 Channel);
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromTimeoutError(const uint8 Channel);
#endif /*(FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)*/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromSendHeaderOk(const uint8 Channel, Flexio_Lin_Ip_NodeStateType CurrentNodeState);
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromNoEvent(Flexio_Lin_Ip_NodeStateType CurrentNodeState);
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromReadBackError(const uint8 Channel);
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromRxOverrunError(const uint8 Channel);
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromTxUnderrunError(const uint8 Channel);
static void Flexio_Lin_Ip_MasterSendHeader(const uint8 Channel);
static void Flexio_Lin_Ip_SlaveStartProcessingResponse(const uint8 Channel);
static void Flexio_Lin_Ip_DisableAllInterrupt(const uint8 Channel);
static void Flexio_Lin_Ip_ClearShifterErrorStatus(const uint8 Channel);
static void Flexio_Lin_Ip_RxInterruptHandlerInMasterMode(const uint8 Channel, uint16 Data, Flexio_Lin_Ip_NodeStateType NodeState);
static Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_AbortTransferWhenBusBusy(const uint8 Channel, const Flexio_Lin_Ip_UserConfigType * UserConfig);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_AsyncReceiveFrameData
 * Description   : This function receives data from FLEXIO module using
 * non-blocking method. This function returns immediately after initiating the
 * receive function. The application has to get the receive status to see when
 * the receive is complete. In other words, after calling non-blocking get
 * function, the application must get the receive status to check if receive
 * is completed or not. The interrupt handler Flexio_Lin_Ip_IRQHandler will check
 * the CheckSum byte. If the CheckSum is correct, it will receive the frame data.
 * If the CheckSum is incorrect, this function will return FLEXIO_LIN_IP_STATUS_TIMEOUT and data in
 * rxBuff might be wrong. This function also check if RxSize is in range from 1 to 8.
 * If not, it will return FLEXIO_LIN_IP_STATUS_ERROR. This function also returns FLEXIO_LIN_IP_STATUS_ERROR if
 * node's current state is in SLEEP mode. This function checks if the
 * bIsBusBusy is (boolean)FALSE, if not it will return FLEXIO_LIN_IP_STATUS_BUSY.
 *
 *END**************************************************************************/

static void Flexio_Lin_Ip_AsyncReceiveFrameData(const uint8 Channel)
{
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_START_TIMER_NOTIFICATION
    const Flexio_Lin_Ip_UserConfigType *UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    #endif
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    /* Set the node and mark the channels as busy */
    LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_RECV_DATA;
    LinCurrentState->IsBusBusy = TRUE;

    /* Add a place for CheckSum byte */
    LinCurrentState->CntByte = 0U;

#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_START_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = TRUE;
    /* Call notification to start timer for the checking response reception timeout */
    /* Response Timeout duration(in microseconds) will be response timeout for 1 byte * (number of data bytes + checksum byte) */
    FLEXIO_LIN_IP_START_TIMER_NOTIFICATION(Channel, UserConfig->ResponseTimeoutValue * (LinCurrentState->Dl + 1UL));
    #endif
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
}
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatusFromTimeoutError
 * Description   : This function get status from Timeout error event.
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromTimeoutError(const uint8 Channel)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this FLEXIO instance. */
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];

    switch (LinCurrentState->PreviousNodeState)
    {
        /* If the node is RECEIVING DATA */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA:
            if (0u == LinCurrentState->CntByte)
            {
                RetStatus = FLEXIO_LIN_IP_STATUS_RX_NO_RESPONSE;
            }
            else
            {
                RetStatus = FLEXIO_LIN_IP_STATUS_RX_ERROR;
            }
            break;
        /* Timeout in receiving checksum byte */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_ERROR;
            break;
         /* If the node is RECEIVING HEADER */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_SYNC:
            /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_PID:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        default:
            /* Need to do nothing */
            break;
    }

    return RetStatus;
}
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatusFromSendHeaderOk
 * Description   : This function get status from send header event is successfully.
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromSendHeaderOk(const uint8 Channel, Flexio_Lin_Ip_NodeStateType CurrentNodeState)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this FLEXIO instance. */
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if ((FLEXIO_LIN_IP_NODE_STATE_SEND_DATA == CurrentNodeState) || (FLEXIO_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED == CurrentNodeState))
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_TX_BUSY;
    }
    else
    {
        if (0u != LinCurrentState->CntByte)
        {
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_BUSY;
        }
        else
        {
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_NO_RESPONSE;
        }
    }

    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatusFromNoEvent
 * Description   : This function get status when no event.
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromNoEvent(Flexio_Lin_Ip_NodeStateType CurrentNodeState)
{
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;

    switch (CurrentNodeState)
    {
        case FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE:
            RetStatus = FLEXIO_LIN_IP_STATUS_SLEEP;
            break;
        case FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD:
            /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_SYNC:
            /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_PID:
            RetStatus = FLEXIO_LIN_IP_STATUS_TX_BUSY;
            break;
        case FLEXIO_LIN_IP_NODE_STATE_IDLE:
            RetStatus = FLEXIO_LIN_IP_STATUS_OPERATIONAL;
            break;
        default:
            RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;
            break;
    }

    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatusFromReadBackError
 * Description   : This function get status from Readback error event.
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromReadBackError(const uint8 Channel)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this FLEXIO instance. */
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if ((FLEXIO_LIN_IP_NODE_STATE_SEND_PID == LinCurrentState->PreviousNodeState) ||
        (FLEXIO_LIN_IP_NODE_STATE_SEND_SYNC == LinCurrentState->PreviousNodeState) ||
        (FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD == LinCurrentState->PreviousNodeState)
       )
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_TX_HEADER_ERROR;
    }
    else
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_TX_ERROR;
    }

    return RetStatus;

}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatusFromRxOverrunError
 * Description   : This function obtains information from the Rx Overrun error event.
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromRxOverrunError(const uint8 Channel)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this FLEXIO instance. */
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];

    /* Found cause of the error from header or reponse */
    switch (LinCurrentState->PreviousNodeState)
    {
        case FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD:
        /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_SYNC:
        /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_PID:
            RetStatus = FLEXIO_LIN_IP_STATUS_TX_HEADER_ERROR;
            break;
        case FLEXIO_LIN_IP_NODE_STATE_SEND_DATA:
        /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED:
            RetStatus = FLEXIO_LIN_IP_STATUS_TX_ERROR;
            break;
        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA:
        /* fall-through */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_ERROR;
            break;
        default:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
    }

    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatusFromTxUnderrunError
 * Description   : This function obtains information from the Tx Underrun error event.
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatusFromTxUnderrunError(const uint8 Channel)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;

    /* Get the current LIN state of this FLEXIO instance. */
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if ((FLEXIO_LIN_IP_NODE_STATE_SEND_DATA == LinCurrentState->PreviousNodeState) || (FLEXIO_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED == LinCurrentState->PreviousNodeState))
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_TX_ERROR;
    }
    else
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_TX_HEADER_ERROR;
    }
    return RetStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_AsyncSendFrameData
 * Description   : This enables an a-sync method for transmitting data.
 * The application has to get the transmit status to know when the transmit is complete.
 * This function will calculate the CheckSum byte and send it with the frame data.
 * If txSize is equal to 0 or greater than 8 or node's current state is in SLEEP mode
 * then the function will return FLEXIO_LIN_IP_STATUS_ERROR. If bIsBusBusy is currently true then the
 * function will return FLEXIO_LIN_IP_STATUS_BUSY.
 *
 *END**************************************************************************/

static void Flexio_Lin_Ip_AsyncSendFrameData (const uint8 Channel)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    FLEXIO_Type *Base;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_SEND_DATA;
    LinCurrentState->IsBusBusy = TRUE;

    /* Add a place for CheckSum byte */
    LinCurrentState->CntByte = 1U;

    /* Send the first byte of data frame */
    Base->SHIFTBUF[UserConfig->TxShifterId]=((uint32)Flexio_Lin_Ip_au8SduBuffer[Channel][0]);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter)
{
    *StartTimeOut    = OsIf_GetCounter(OsifCounter);
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, OsifCounter);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
static boolean Flexio_Lin_Ip_TimeoutExpired(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter)
{
    boolean RetVal = FALSE;
    uint32 CurrentElapsedTicks = OsIf_GetElapsed(StartTime, OsifCounter);

    *ElapsedTicks += CurrentElapsedTicks;
    if (*ElapsedTicks >= TimeoutTicks)
    {
        RetVal = TRUE;
    }

    return RetVal;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_ErrInterruptHandler
 * Description   : Error interrupt handler for FLEXIO.
 * This function shall manage all the Error ISRs on the addressed Channel.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_ErrInterruptHandler(const uint8 Channel, uint8 ShiftErrMask)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Flexio_Lin_Ip_StateStructType *LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    /* Check underrun error in transmitted shifter */
    if ((uint8)0U != (ShiftErrMask & (uint8)(1UL << UserConfig->TxShifterId)))
    {
        /* Update event id */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_TX_UNDERRUN_ERROR;

        Flexio_Lin_Ip_GoToIdleState(Channel);

        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    /* Check overrun error in received shifter */
    else if ((uint8)0U != (ShiftErrMask & (uint8)(1UL << UserConfig->RxShifterId)))
    {
        #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        #ifdef FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION
        LinCurrentState->TimerCounting = FALSE;
        /* Call notification to stop timer if there is overrun error */
        FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION(Channel);
        #endif
        #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

        /* Update Event Id */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_RX_OVERRUN_ERROR;

        Flexio_Lin_Ip_GoToIdleState(Channel);

        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    else
    {
        /* Should not enter here */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxBreakFrameProcess
 * Description   : Processing receive SYNC byte in Master mode.
 *  This function will check read-back error for SYNC byte and send PID byte.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxBreakFrameProcess(const uint8 Channel, const uint16 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    FLEXIO_Type *Base;
    uint32 TempByte = 0UL;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (0x0000U != Data)
    {
        /* Set current event ID to read-back */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_READBACK_ERROR;

        /* Change node's current state to IDLE */
        Flexio_Lin_Ip_GoToIdleState(Channel);

        /* Callback function to handle event SYNC incorrect */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    else
    {
        SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_11();
        /* Configure 8-bit transfer for TX */
        TempByte = Base->TIMCMP[UserConfig->TxTimerId];
        TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
        TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U);
        Base->TIMCMP[UserConfig->TxTimerId] = TempByte;

        /* Configure 8-bit transfer for RX */
        TempByte = Base->TIMCMP[UserConfig->RxTimerId];
        TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
        TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U);
        Base->TIMCMP[UserConfig->RxTimerId] = TempByte;
        SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_11();

        /* Change node state */
        LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_SEND_SYNC;

        /* Push Sync byte to shifter */
        Base->SHIFTBUF[UserConfig->TxShifterId] =(uint32)0x55U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxSyncByteProcess
 * Description   : Processing receive SYNC byte in Master mode.
 *  This function will check read-back error for SYNC byte and send PID byte.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxSyncByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    FLEXIO_Type *Base;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (0x55U != Data)
    {
        /* Set current event ID to read-back */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_READBACK_ERROR;

        /* Change node's current state to IDLE */
        Flexio_Lin_Ip_GoToIdleState(Channel);

        /* Callback function to handle event SYNC incorrect */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    else
    {
        /* Update node state*/
        LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_SEND_PID;

        /* Push Pid byte to shifter */
        Base->SHIFTBUF[UserConfig->TxShifterId] =(uint32)LinCurrentState->CurrentPid;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_SlaveRxSyncByteProcess
 * Description   : Processing receive SYNC byte in Slave mode.
 *  This function will check SYNC byte and update node state to receive PID.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_SlaveRxSyncByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (0x55U != Data)
    {
        /* Set current event ID to sync error */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_SYNC_ERROR;

        /* Change node's current state to IDLE */
        Flexio_Lin_Ip_GoToIdleState(Channel);

        /* Callback function to handle event SYNC incorrect */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    else
    {
        /* Update node state*/
        LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_RECV_PID;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxPidByteProcess
 * Description   : Processing receive PID byte in Master mode.
 *  This function will check read-back error for PID byte and
 *  call Callback notification to process transmit or receive response.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxPidByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (Data != LinCurrentState->CurrentPid)
    {
         /* Set current event ID to PID incorrect */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_READBACK_ERROR;

        /* Change node's current state to IDLE */
        Flexio_Lin_Ip_GoToIdleState(Channel);

        /* Callback function to handle event PID correct */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    else
    {
        /* Set current event ID to Header successfully transmitted */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_SEND_HEADER_OK;

        /* This is the response generated from master */
        if (FLEXIO_LIN_IP_FRAMERESPONSE_TX == LinCurrentState->FrameCommand)
        {
            Flexio_Lin_Ip_AsyncSendFrameData(Channel);
        }
        else if (FLEXIO_LIN_IP_FRAMERESPONSE_RX == LinCurrentState->FrameCommand)
        {
            Flexio_Lin_Ip_AsyncReceiveFrameData(Channel);
        }
        else /* Slave to slave communication */
        {
            LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_TX_COMPLETED;

            /* Change node's current state to IDLE */
            Flexio_Lin_Ip_GoToIdleState(Channel);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_SlaveRxPidByteProcess
 * Description   : Processing receive PID byte in Slave mode.
 *  This function will check PID byte and
 *  call Callback notification to process transmit or receive response.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_SlaveRxPidByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    LinCurrentState->CurrentId = Lin_Ip_ProcessParity(Data, LIN_IP_CHECK_PARITY);
    LinCurrentState->CurrentPid = Data;
    #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = FALSE;
    /* Call notification to stop timer after PID received */
    FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION(Channel);
    #endif
    #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

   /* Check parity bits is whether correct or not */
    if (0xFFu != LinCurrentState->CurrentId)
    {
        /* Set event ID to PID_OK */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_RECV_HEADER_OK;


        /* Clear Bus bus flag */
        LinCurrentState->IsBusBusy = FALSE;

        /* Callback function to handle event receive pid */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
    else
    {
        /* Set event Id to PID error */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_PID_ERROR;

        /* Change node's current state to IDLE */
        (void)Flexio_Lin_Ip_GoToIdleState(Channel);

        /* Callback function to handle event receive pid */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxDataByteProcess
 * Description   : Processing receive DATA byte in Master mode.
 *  This function will check read-back error for DATA byte transmitted and
 *  transmit next DATA byte.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxDataByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    FLEXIO_Type *Base;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (0U != LinCurrentState->CntByte)
    {
        if (Data != LinCurrentState->SduBuf[LinCurrentState->CntByte - 1U])
        {
            /* Set event to read-back error */
            LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_READBACK_ERROR;

            /* Change node's current state to IDLE */
            Flexio_Lin_Ip_GoToIdleState(Channel);

            /* Callback function to handle event PID correct */
            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Channel, LinCurrentState);
            }
        }
        /* Read-back byte is correct so transmit next byte in data frame */
        else
        {
            /* Send next byte of data frame */
            if (LinCurrentState->CntByte < LinCurrentState->Dl)
            {
                /* Write current byte to buffer */
                Base->SHIFTBUF[UserConfig->TxShifterId] = FLEXIO_SHIFTBUF_SHIFTBUF(LinCurrentState->SduBuf[LinCurrentState->CntByte]);
                /* Increase byte counter */
                LinCurrentState->CntByte++;
            }
            /* Send CheckSum byte */
            else
            {
                /* Change node state to transmit data completely */
                LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED;

                /* Write check sum byte to buffer */
                Base->SHIFTBUF[UserConfig->TxShifterId] = FLEXIO_SHIFTBUF_SHIFTBUF(LinCurrentState->CheckSum);
            }
        }
    }
    else
    {
        /* Set event to read-back error */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_READBACK_ERROR;

        /* Change node's current state to IDLE */
        Flexio_Lin_Ip_GoToIdleState(Channel);

        /* Callback function to handle event PID correct */
        if (NULL_PTR != UserConfig->Callback)
        {
            UserConfig->Callback(Channel, LinCurrentState);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxCheckSumByteProcess
 * Description   : Processing receive CHECKSUM byte in Master mode.
 *  This function will check read-back error for CHECKSUM byte transmitted and
 *  call Callback notification to process TX completed.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxCheckSumByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (Data != LinCurrentState->CheckSum)
    {
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_READBACK_ERROR;
    }
    else
    {
        /* Update event id to transmit completed */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_TX_COMPLETED;
    }

    /* Change node's current state to IDLE */
    Flexio_Lin_Ip_GoToIdleState(Channel);

    /* Callback function to handle event of  checksum received. Use LinCurrentState->CurrentEventId to distinguish
       between the type of events happened */
    if (NULL_PTR != UserConfig->Callback)
    {
        UserConfig->Callback(Channel, LinCurrentState);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxSlaveResCheckSumByteProcess
 * Description   : Processing receive response CHECKSUM byte from Slave.
 *  This function will check CHECKSUM byte responded from Slave and
 *  call Callback notification to process RX completed.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxSlaveResCheckSumByteProcess(const uint8 Channel, const uint8 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    uint32 TempByte = 0UL;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if (FLEXIO_LIN_IP_CLASSIC_CS != LinCurrentState->Cs)
    {
        /* Calculate enhanced CheckSum byte */
        TempByte = Lin_Ip_MakeChecksumByte(&Flexio_Lin_Ip_au8SduBuffer[Channel][0u],
                                        LinCurrentState->Dl, \
                                        LinCurrentState->CurrentPid \
                                        );
    }
    else
    {
        /* Compute classic CheckSum byte */
        TempByte = Lin_Ip_MakeChecksumByte(&Flexio_Lin_Ip_au8SduBuffer[Channel][0u],
                                        LinCurrentState->Dl, \
                                        0U \
                                        );
    }

    /* Check CheckSum byte received */
    if (TempByte != Data)
    {
        /* Incorrect CheckSum byte */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_CHECKSUM_ERROR_EVENT;
    }
    else
    {
        /* Reception frame completed */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_RX_COMPLETED;
    }

    #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = FALSE;
    /* Call notification to stop timer after checksum byte received */
    FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION(Channel);
    #endif
    #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

    /* Change node's current state to IDLE */
    Flexio_Lin_Ip_GoToIdleState(Channel);

    /* Callback function to handle current event */
    if (NULL_PTR != UserConfig->Callback)
    {
        UserConfig->Callback(Channel, LinCurrentState);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_SlaveRxBreakLengthProcess
 * Description   : Processing Break Length detected in Slave mode.
 *  This function will process when Break Length detected in Slave mode and
 *  change node state to receive SYNC byte.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_SlaveRxBreakLengthProcess(const uint8 Channel, const uint16 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    uint32 TempByte = 0UL;
    FLEXIO_Type *Base;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    if ((boolean)FLEXIO_LIN_IP_SLAVE == UserConfig->NodeFunction)
    {
        /* Data of break field should be 0 */
        if (0U != Data)
        {
            /* Not enough bit length so this is not break character */
        }
        else
        {
            /* In Slave mode, when external master send break length greater than 11 bits break detection then the Shifter Error Flag is set with overload
            it should be clean before get other fields of header frame from Master*/
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->RxShifterId);
            SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_11();
            /* Configure 8-bit transfer for TX */
            TempByte = Base->TIMCMP[UserConfig->TxTimerId];
            TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
            TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8);
            Base->TIMCMP[UserConfig->TxTimerId] = TempByte;

            /* Configure 8-bit transfer for RX */
            TempByte = Base->TIMCMP[UserConfig->RxTimerId];
            TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
            TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8);
            Base->TIMCMP[UserConfig->RxTimerId] = TempByte;

            SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_11();

            LinCurrentState->IsBusBusy = TRUE;
            LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_RECV_SYNC;

            /* Enable Shifters error interrupt */
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base,
                                                   (uint8)(1U << UserConfig->TxShifterId) | \
                                                   (uint8)(1U << UserConfig->RxShifterId), \
                                                   (boolean)TRUE \
                                                  );

            #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
            #ifdef FLEXIO_LIN_IP_START_TIMER_NOTIFICATION
            LinCurrentState->TimerCounting = TRUE;
            /* Call notification to start timer for the checking header reception timeout */
            /* Header Timeout duration(in microseconds) after detection break */
            FLEXIO_LIN_IP_START_TIMER_NOTIFICATION(Channel, UserConfig->HeaderTimeoutValue);
            #endif
            #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

            LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_RECV_BREAK_FIELD_OK;
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxInterruptHandlerInMasterMode
 * Description   : Rx interrupt handler for FLEXIO in Master Mode.
 * This function shall manage all the Rx ISRs on the addressed Channel to handle
 * transmit or receive a lin frame in Master Mode.
 * This function is created to reduce HIS_CALLS in Flexio_Lin_Ip_RxInterruptHandler function.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxInterruptHandlerInMasterMode(const uint8 Channel, uint16 Data, Flexio_Lin_Ip_NodeStateType NodeState)
{
    switch (NodeState)
    {
        /* Check if LIN current node state is FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD:
            /* Check read-back error for Break frame and send Sync byte */
            Flexio_Lin_Ip_RxBreakFrameProcess(Channel, Data);
            break;
        case FLEXIO_LIN_IP_NODE_STATE_SEND_SYNC:
            /* Check read-back error for sync byte and send pid byte */
            Flexio_Lin_Ip_RxSyncByteProcess(Channel, (uint8)Data);
            break;
        case FLEXIO_LIN_IP_NODE_STATE_SEND_PID:
            /* Check read-back error for PID byte */
            Flexio_Lin_Ip_RxPidByteProcess(Channel, (uint8)Data);
            break;
        case FLEXIO_LIN_IP_NODE_STATE_SEND_DATA:
            /* Check read-back error to transmitted byte and send next DATA byte */
            Flexio_Lin_Ip_RxDataByteProcess(Channel, (uint8)Data);
            break;
        case FLEXIO_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED:
            /* Check read-back error for CHECKSUM byte */
            Flexio_Lin_Ip_RxCheckSumByteProcess(Channel, (uint8)Data);
            break;
        default:
            /* Do nothing */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_RxInterruptHandler
 * Description   : Rx interrupt handler for FLEXIO.
 * This function shall manage all the Rx ISRs on the addressed Channel to handle
 * transmit or receive a lin frame.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_RxInterruptHandler(const uint8 Channel)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    uint16 Data = 0u;
    const FLEXIO_Type *Base;
    Flexio_Lin_Ip_NodeStateType NodeState;
    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = (const FLEXIO_Type *)Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    /* Read the data and Clear status flag */
    switch (LinCurrentState->CurrentNodeState)
    {
        /* Check if LIN current node state is FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD */
        case FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD:
            Data = (uint16)(Base->SHIFTBUF[UserConfig->RxShifterId] >> (32u - UserConfig->MasterBreakLength - 1u));
            break;
        /* Check if LIN current node state is FLEXIO_LIN_IP_NODE_STATE_IDLE */
        case FLEXIO_LIN_IP_NODE_STATE_IDLE:
            /* During detect break filed in Slave mode */
            Data = (uint16)(Base->SHIFTBUF[UserConfig->RxShifterId] >> (32u - UserConfig->SlaveSyncBreakLength - 1u));
            break;
        default:
            /* During send wakeup byte, receive wakeup byte or normal reception */
            Data = (uint16)(Base->SHIFTBUFBYS[UserConfig->RxShifterId] & FLEXIO_IP_DATA_8BITS_MASK_U32);
            break;
    }
    NodeState = LinCurrentState->CurrentNodeState;

    /* Check if the current node is MASTER */
    switch (NodeState)
    {
        case FLEXIO_LIN_IP_NODE_STATE_UNINIT:
            break;

        case FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE:
            /* check wakeup pulse detection */
            Flexio_Lin_Ip_WakeupInterruptHandler(Channel, Data);
            break;
        case FLEXIO_LIN_IP_NODE_STATE_RECV_SYNC:
            /* Only slave jump to state */
            Flexio_Lin_Ip_SlaveRxSyncByteProcess(Channel, (uint8)Data);
            break;
        
        case FLEXIO_LIN_IP_NODE_STATE_RECV_PID:
            /* Check PID and process to transmit or receive response */
            Flexio_Lin_Ip_SlaveRxPidByteProcess(Channel, (uint8)Data);
            break;

        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA:
            /* Store data when receive response from Slave */
            Flexio_Lin_Ip_au8SduBuffer[Channel][LinCurrentState->CntByte] = (uint8)Data;
            LinCurrentState->CntByte++;

            /* Check has gotten enough data bytes */
            if (LinCurrentState->CntByte == LinCurrentState->Dl)
            {
                /* Data reception completed */
                LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED;
            }
            break;

        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED:
            /* Check CHECKSUM byte received from Slave */
            Flexio_Lin_Ip_RxSlaveResCheckSumByteProcess(Channel, (uint8)Data);
            break;

        case FLEXIO_LIN_IP_NODE_STATE_IDLE:
            /* Slave node detected a break length */
            Flexio_Lin_Ip_SlaveRxBreakLengthProcess(Channel, Data);
            break;
        default:
            /* Handler in Master Mode */
            Flexio_Lin_Ip_RxInterruptHandlerInMasterMode(Channel, Data, NodeState);
            break;
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_WakeupInterruptHandler
 * Description   : Interrupt handler for Timer on FLEXIO.
 * This function shall manage all the Timer ISRs on the addressed Channel to handle
 * wake-up function.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_WakeupInterruptHandler(const uint8 Channel, const uint16 Data)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Flexio_Lin_Ip_StateStructType *LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    /* Check byte received has enough bit0 duration for a wakeup pulse */
    if (0u == (UserConfig->BaseWakeupByteDetectInverted & (uint8)Data))
    {
        /* Update wake-up event */
        LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_WAKEUP_SIGNAL;

        /* Callback will only call when current node detects a wake-up signal sent by other */
        if (FALSE == LinCurrentState->IsBusBusy)
        {
            /* Change node's state to IDLE to ready operation */
            Flexio_Lin_Ip_GoToIdleState(Channel);

            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Channel, LinCurrentState);
            }
        }
        else
        {
            /* Change node's state to IDLE to ready operation */
            Flexio_Lin_Ip_GoToIdleState(Channel);
        }
    }
    else
    {
        /* reset bus busy in the case of wakeup pulse was generated by current node */
        LinCurrentState->IsBusBusy = FALSE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_MasterSendHeader
 * Description   : Starts the transmission of the header.
 * This function shall prepare the hardware to start the transmission of the first byte of the header (break byte)
 * and send it.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_MasterSendHeader(const uint8 Channel)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    FLEXIO_Type *Base;
    uint32 TempByte = 0UL;

    /* Get the current LIN UserConfig of this FLEXIO Channel. */
    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];
    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

    /* Set LIN current state to sending Break field */
    LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_NO_EVENT;
    /* Set the node state  and mark the bus as busy */
    LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_SEND_BREAK_FIELD;
    LinCurrentState->IsBusBusy = TRUE;

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_16();
    /* Configure Tx Timer to transfer break field */
    TempByte = Base->TIMCMP[UserConfig->TxTimerId];
    /* Set frame size for break field equal number of break length - 1 Start bit */
    TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
    TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32((uint32)(UserConfig->MasterBreakLength) - 1u);
    Base->TIMCMP[UserConfig->TxTimerId] = TempByte;

    /* Configure Rx Timer to receive break field */
    TempByte = Base->TIMCMP[UserConfig->RxTimerId];
    /* Set frame size for break field equal number of break length - 1 Start bit */
    TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
    TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32((uint32)(UserConfig->MasterBreakLength) - 1u);
    Base->TIMCMP[UserConfig->RxTimerId] = TempByte;

    /* Enable the timers in 8 bits counters baud */
    Base->TIMCTL[UserConfig->RxTimerId] = (Base->TIMCTL[UserConfig->RxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_8BIT_BAUD);
    Base->TIMCTL[UserConfig->TxTimerId] = (Base->TIMCTL[UserConfig->TxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_8BIT_BAUD);
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_16();

    /* Clear any leftover  flags */
    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->RxShifterId);
    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->TxShifterId);
    Flexio_Mcl_Ip_ClearShifterStatus(Base, UserConfig->RxShifterId);

    /* Enable error rx and tx interrupt */
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base, \
                                            (uint8)(1U << UserConfig->TxShifterId) | \
                                            (uint8)(1U << UserConfig->RxShifterId), \
                                            (boolean)TRUE \
                                          );
    /* Enable Receive Complete Interrupt */
    Flexio_Mcl_Ip_SetShifterInterrupt(Base,
                                        (uint8)(1U << UserConfig->RxShifterId),
                                        TRUE);

    /* With Master, send break frame first */
    Base->SHIFTBUF[UserConfig->TxShifterId]=((uint32)0x0000U);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_SlaveStartProcessingResponse
 * Description   : Starts the transfer of the response (reception or transfer).
 * This function shall start the reception or send of the response for a slave, depending on the
 * type of frame requested.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_SlaveStartProcessingResponse(const uint8 Channel)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = (const  Flexio_Lin_Ip_StateStructType *) Flexio_Lin_Ip_apxStateStructureArray[Channel];

  /* This is the response generated from master */
    if (FLEXIO_LIN_IP_FRAMERESPONSE_TX == LinCurrentState->FrameCommand)
    {
        Flexio_Lin_Ip_AsyncSendFrameData(Channel);
    }
    else if (FLEXIO_LIN_IP_FRAMERESPONSE_RX == LinCurrentState->FrameCommand)
    {
        Flexio_Lin_Ip_AsyncReceiveFrameData(Channel);
    }
    else
    {
        /* Ignore slave to slave frame */
        Flexio_Lin_Ip_GoToIdleState(Channel);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_DisableAllInterrupt
 * Description   : This function clear all the interrupts that can be possible enabled during the execution are disabled at the beginning.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_DisableAllInterrupt(const uint8 Channel)
{
    FLEXIO_Type * Base;
    const Flexio_Lin_Ip_UserConfigType * UserConfig;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    /* Get Base address of the Flexio instance. */
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Disable error interrupt */
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base,
                                           (uint8)(1U << UserConfig->RxShifterId) |
                                           (uint8)(1U << UserConfig->TxShifterId),
                                           FALSE
                                          );
    /* Disable Rx interrupt */
    Flexio_Mcl_Ip_SetShifterInterrupt(Base,
                                      (uint8)(1U << UserConfig->RxShifterId),
                                      FALSE
                                     );
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_ClearShifterErrorStatus
 * Description   : This function clear shifter error status for Tx channel and Rx channel.
 *
 *END**************************************************************************/
static void Flexio_Lin_Ip_ClearShifterErrorStatus(const uint8 Channel)
{
    FLEXIO_Type * Base;
    const Flexio_Lin_Ip_UserConfigType * UserConfig;

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    /* Get Base address of the Flexio instance. */
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->RxShifterId);
    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->TxShifterId);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_AbortTransferWhenBusBusy
 * Description   : This function abort transfer data when bus is busy
 * This function created to reduce HIS_CALLS for Flexio_Lin_Ip_AbortTransferData() function
 *
 *END**************************************************************************/
static Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_AbortTransferWhenBusBusy(const uint8 Channel, const Flexio_Lin_Ip_UserConfigType * UserConfig)
{
    const FLEXIO_Type * Base;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    Flexio_Lin_Ip_StatusType RetVal = FLEXIO_LIN_IP_STATUS_ERROR;

    Base = (const FLEXIO_Type *)Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* Wait until the data is completely shifted out of shift register */
    Flexio_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, FLEXIO_LIN_IP_TIMEOUT_VALUE_US, FLEXIO_LIN_IP_TIMEOUT_TYPE);
    do
    {
        if (Flexio_Mcl_Ip_GetShifterStatus(Base,UserConfig->RxShifterId))
        {
            RetVal = FLEXIO_LIN_IP_STATUS_SUCCESS;
            break;
        }
    }
    while (!Flexio_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, FLEXIO_LIN_IP_TIMEOUT_TYPE));

    /* Discard data already received */
    (void)Base->SHIFTBUF[UserConfig->RxShifterId];
    Flexio_Lin_Ip_ClearShifterErrorStatus(Channel);

    return RetVal;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_Init
 * Description   :
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_Init_Activity
*/
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_Init(const uint8 Channel, const Flexio_Lin_Ip_UserConfigType * UserConfig)
{
    FLEXIO_Type *Base;
    uint32 TempRegVal = 0UL;
    uint8  TxTRGSEL = 0U;
    uint8  TimModVal = 0U;
    Flexio_Lin_Ip_StatusType RetStatus = FLEXIO_LIN_IP_STATUS_SUCCESS;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
    /* Check if current Channel is already initialized. */
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR == Flexio_Lin_Ip_apxStateStructureArray[Channel]);
#endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the FLEXIO Channel. */
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];
    TempRegVal = Base->CTRL;

    /* Check if flexio module is enabled */
    if (0UL == (TempRegVal & FLEXIO_CTRL_FLEXEN_MASK))
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_ERROR;
    }
    else
    {
        /* Save LIN user config structure pointer. */
        Flexio_Lin_Ip_apxUserConfigs[Channel] = UserConfig;

        /* Calculate TRGSEL - Trigger Select for Timer control */
        /* Select Tx Shifter flag as trigger source for Tx Timer,
        so Tx Timer will start generate shift clock for Tx Shifter when SHIFTBUF register is written. */
        TxTRGSEL = (4U*(UserConfig->TxShifterId)) + 1U;

        if ((boolean)FLEXIO_LIN_IP_MASTER == UserConfig->NodeFunction)
        {
            TimModVal = (uint8)FLEXIO_TIMER_MODE_DISABLED;       /* Have the timer disabled for master mode first and enable later when start send frame */
        }
        else
        {
            TimModVal = (uint8)FLEXIO_TIMER_MODE_8BIT_BAUD;      /* Enable the timer only for slave mode to ready operation after initialization */
        }

        SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_13();
        /* Ensure all shifters/timers are disabled before configure */
        Base->SHIFTCTL[UserConfig->TxShifterId] &= ~(FLEXIO_SHIFTCTL_SMOD_MASK);
        Base->SHIFTCTL[UserConfig->RxShifterId] &= ~(FLEXIO_SHIFTCTL_SMOD_MASK);
        Base->TIMCTL[UserConfig->TxTimerId]     &= ~(FLEXIO_TIMCTL_TIMOD_MASK);
        Base->TIMCTL[UserConfig->RxTimerId]     &= ~(FLEXIO_TIMCTL_TIMOD_MASK);

        /* Configure for Transmit */
        TempRegVal  = Base->SHIFTCFG[UserConfig->TxShifterId];
        TempRegVal |=   (FLEXIO_SHIFTCFG_SSTART(FLEXIO_SHIFTER_START_BIT_0)     /* Start bit 0 */
                        | FLEXIO_SHIFTCFG_SSTOP(FLEXIO_SHIFTER_STOP_BIT_1)          /* Stop  bit 1 */
                        | FLEXIO_SHIFTCFG_INSRC(FLEXIO_SHIFTER_SOURCE_PIN)          /* In transmit mode, data for Tx Shifter will take from SHIFTBUF so set dummy Input Source from PIN */
                        );
        Base->SHIFTCFG[UserConfig->TxShifterId] = TempRegVal;

        /* Configure for Reception */
        TempRegVal = Base->SHIFTCFG[UserConfig->RxShifterId];
        TempRegVal |=   (FLEXIO_SHIFTCFG_SSTART(FLEXIO_SHIFTER_START_BIT_0)     /* Start bit 0 */
                        | FLEXIO_SHIFTCFG_SSTOP(FLEXIO_SHIFTER_STOP_BIT_1)          /* Stop  bit 1 */
                        | FLEXIO_SHIFTCFG_INSRC(FLEXIO_SHIFTER_SOURCE_PIN)          /* In receive mode, data on Rx PIN will be shift into Rx Shifter */
                        );
        Base->SHIFTCFG[UserConfig->RxShifterId] = TempRegVal;

        /* SHIFTCTLn Select timer, pin Tx for Tx Shifter */
        TempRegVal = Base->SHIFTCTL[UserConfig->TxShifterId];
        TempRegVal |= (FLEXIO_SHIFTCTL_TIMSEL(UserConfig->TxTimerId)      /* Timer selection */
                      | FLEXIO_SHIFTCTL_PINCFG(FLEXIO_PIN_CONFIG_OUTPUT)            /* Shifter Pin configured as an output to shift data out */
                      | FLEXIO_SHIFTCTL_PINSEL(UserConfig->TxPin)             /* Select Shifter Pin to shift data out */
                      | FLEXIO_SHIFTCTL_SMOD(FLEXIO_SHIFTER_MODE_TRANSMIT)          /* Select transmit mode to shift data out */
                      );
        Base->SHIFTCTL[UserConfig->TxShifterId] = TempRegVal;

        /* SHIFTCTLn Select timer, pin Rx*/
        TempRegVal = Base->SHIFTCTL[UserConfig->RxShifterId];
        TempRegVal |= (FLEXIO_SHIFTCTL_TIMSEL(UserConfig->RxTimerId)      /* Timer selection */
                      | FLEXIO_SHIFTCTL_PINCFG(FLEXIO_PIN_CONFIG_DISABLED)          /* Rx Shifter in receive mode so disable Shifter Pin output */
                      | FLEXIO_SHIFTCTL_PINSEL(UserConfig->RxPin)             /* Select Shifter Pin to shift data in */
                      | FLEXIO_SHIFTCTL_SMOD(FLEXIO_SHIFTER_MODE_RECEIVE)           /* Shifter receive mode*/
                      | FLEXIO_SHIFTCTL_TIMPOL(FLEXIO_TIMER_POLARITY_NEGEDGE)       /* Shift data in on negedge of Shift clock generated from Rx Timer */
                      );
        Base->SHIFTCTL[UserConfig->RxShifterId] = TempRegVal;

        /* Configure the Tx Timer to generate shift clock for 8 bits each frame */
        Base->TIMCMP[UserConfig->TxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(UserConfig->Baudratedivider) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U))); /* Tx Timer */
        if ((boolean)FLEXIO_LIN_IP_MASTER == UserConfig->NodeFunction)
        {
            /* Configure the Rx Timer to generate shift clock for receiving frame 8 bits */
            Base->TIMCMP[UserConfig->RxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(UserConfig->Baudratedivider) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U))); /* Rx Timer */
        }
        else
        {
            /* Configure the Rx Timer to generate shift clock for receiving bits of break length included Start bit */
            Base->TIMCMP[UserConfig->RxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(UserConfig->Baudratedivider) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32((uint32)(UserConfig->SlaveSyncBreakLength) - 1u))); /* Rx Timer */
        }

        TempRegVal = Base->TIMCFG[UserConfig->RxTimerId];
        TempRegVal |= (FLEXIO_TIMCFG_TSTART(FLEXIO_TIMER_START_BIT_ENABLED)          /* Start bit enabled */
                      | FLEXIO_TIMCFG_TSTOP(FLEXIO_TIMER_STOP_BIT_TIM_DIS)            /* Stop bit is enabled on timer disable */
                      | FLEXIO_TIMCFG_TIMENA(FLEXIO_TIMER_ENABLE_PIN_POSEDGE)         /* Timer enabled on Pin rising edge Enable when data is available*/
                      | FLEXIO_TIMCFG_TIMDIS(FLEXIO_TIMER_DISABLE_TIM_CMP)            /* Timer disabled on Timer compare */
                      | FLEXIO_TIMCFG_TIMRST(FLEXIO_TIMER_RESET_PIN_RISING)           /* Timer reset on Timer Pin rising edge */
                      | FLEXIO_TIMCFG_TIMDEC(UserConfig->TimerClkSrc)                 /* Timer decrement counter on FlexIO clock */
                      | FLEXIO_TIMCFG_TIMOUT(FLEXIO_TIMER_INITOUT_ONE_RESET)          /* Timer output is logic one when enabled and on timer reset */
                      );
        Base->TIMCFG[UserConfig->RxTimerId] = TempRegVal;

        TempRegVal = Base->TIMCFG[UserConfig->TxTimerId];
        TempRegVal |= (FLEXIO_TIMCFG_TSTART(FLEXIO_TIMER_START_BIT_ENABLED)         /* Start bit enabled */
                      | FLEXIO_TIMCFG_TSTOP(FLEXIO_TIMER_STOP_BIT_TIM_DIS)           /* Stop bit is enabled on timer disable */
                      | FLEXIO_TIMCFG_TIMENA(FLEXIO_TIMER_ENABLE_TRG_HIGH)           /* Tx Timer will enable on trigger high from Tx Shifter flag(inverted) */
                      | FLEXIO_TIMCFG_TIMDEC(UserConfig->TimerClkSrc)                /* Timer decrement counter on FlexIO clock */
                      | FLEXIO_TIMCFG_TIMDIS(FLEXIO_TIMER_DISABLE_TIM_CMP)           /* Timer disabled on Timer compare */
                      );
        Base->TIMCFG[UserConfig->TxTimerId] = TempRegVal;

      /* Configure dual 8-bit counters baud mode using Tx Shifter flag as inverted internal trigger source */
        TempRegVal = Base->TIMCTL[UserConfig->TxTimerId];
        TempRegVal |= (FLEXIO_TIMCTL_TRGSEL(TxTRGSEL)                                /* Select Trigger source is Tx Shifter Flag */
                      | FLEXIO_TIMCTL_TRGPOL(FLEXIO_TRIGGER_POLARITY_LOW)             /* Trigger is active low, the signal from Tx Shifter flag will be inverted */
                      | FLEXIO_TIMCTL_TRGSRC(FLEXIO_TRIGGER_SOURCE_INTERNAL)          /* Internal trigger selected */
                      | FLEXIO_TIMCTL_PINCFG(FLEXIO_PIN_CONFIG_DISABLED)              /* Timer pin output disabled, Tx Timer will generate clock to Tx Shifter, no need out data to timer pin when expire */
                      | FLEXIO_TIMCTL_PINSEL(UserConfig->TxPin)                       /* Timer Pin disabled so set dummy value is TxPin */
                      | FLEXIO_TIMCTL_PINPOL(FLEXIO_PIN_POLARITY_LOW)                 /* Pin is active low as dummy value */
                      | FLEXIO_TIMCTL_TIMOD(TimModVal)                                /* Select Tx Timer mode */
                      );
        Base->TIMCTL[UserConfig->TxTimerId] = TempRegVal;

        TempRegVal = Base->TIMCTL[UserConfig->RxTimerId];
        TempRegVal |= (FLEXIO_TIMCTL_TRGSEL(0)                                       /* Trigger is not used to enable timer so Select dummy trigger source */
                      | FLEXIO_TIMCTL_TRGPOL(FLEXIO_TRIGGER_POLARITY_HIGH)            /* Trigger is active high */
                      | FLEXIO_TIMCTL_TRGSRC(FLEXIO_TRIGGER_SOURCE_EXTERNAL)          /* External trigger selected */
                      | FLEXIO_TIMCTL_PINCFG(FLEXIO_PIN_CONFIG_DISABLED)              /* Rx Timer pin output disabled, Rx Timer only use pin input to enable timer */
                      | FLEXIO_TIMCTL_PINSEL(UserConfig->RxPin)                       /* Select Rx Timer Pin to enable timer on input Pin rising edge */
                      | FLEXIO_TIMCTL_PINPOL(FLEXIO_PIN_POLARITY_LOW)                 /* Pin is active low, input signal will be inverted */
                      | FLEXIO_TIMCTL_TIMOD(TimModVal)
                      );
        Base->TIMCTL[UserConfig->RxTimerId] = TempRegVal;
        SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_13();
        /* Save runtime structure pointer. */
        Flexio_Lin_Ip_apxStateStructureArray[Channel] = UserConfig->StateStruct;
        /* Set event and node state to default */
        Flexio_Lin_Ip_apxStateStructureArray[Channel]->CurrentEventId = FLEXIO_LIN_IP_NO_EVENT;
        Flexio_Lin_Ip_apxStateStructureArray[Channel]->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_IDLE;
        /* Clear flags in current LIN state structure */
        Flexio_Lin_Ip_apxStateStructureArray[Channel]->IsBusBusy = FALSE;
        /* Set the shifter-channel mapping used in ISR */
        Flexio_Lin_Ip_au8ShiftersIndex[UserConfig->RxShifterId] = Channel;
        Flexio_Lin_Ip_au8ShiftersIndex[UserConfig->TxShifterId] = Channel;
    #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        #if defined(FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION) && defined(FLEXIO_LIN_IP_START_TIMER_NOTIFICATION)
        /* Default value for the Timercounting flag */
        Flexio_Lin_Ip_apxStateStructureArray[Channel]->TimerCounting = FALSE;
        #endif
    #endif
        /* Make sure timer interrupts are disabled */
        Flexio_Mcl_Ip_SetTimerInterrupt(Base,(uint8)(1U << UserConfig->TxTimerId) | (uint8)(1U << UserConfig->RxTimerId), FALSE);

        /* The driver needs to ready for receiving break frame after initialized */
        if ((boolean)FLEXIO_LIN_IP_SLAVE == UserConfig->NodeFunction)
        {
            /* Clear any leftover flags */
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->RxShifterId);
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->TxShifterId);

            /* Disable error rx and tx interrupt because frame error will be occured
            when external master send break length greater than 11 bits break detection.
            They will be enabled after receiving correct 11 bits break. */
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base, \
                                                    (uint8)(1U << UserConfig->TxShifterId) | \
                                                    (uint8)(1U << UserConfig->RxShifterId), \
                                                    (boolean)FALSE \
                                                  );
            /* Enable Receive Complete Interrupt */
            Flexio_Mcl_Ip_SetShifterInterrupt(Base, \
                                              (uint8)(1U << UserConfig->RxShifterId), \
                                              (boolean)TRUE \
                                             );
        }
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GoToIdleState
 * Description   : This function puts current node to Idle state.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_GoToIdleState_Activity
*/
void Flexio_Lin_Ip_GoToIdleState(const uint8 Channel)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    FLEXIO_Type *Base;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    uint32 TempByte = 0UL;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
#endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
#endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get Base address of the FLEXIO Channel. */
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];

    /* In Slave mode, disable error rx and tx interrupt because frame error will be occured
    when external master send break length greater than 11 bits break detection.
    They will be enabled after receiving correct 11 bits break.
    In Master mode, Shifters error rx and tx interrupt will be enabled later when send frame */
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base,
                                           (uint8)(1U << UserConfig->RxShifterId) |
                                           (uint8)(1U << UserConfig->TxShifterId),
                                            FALSE
                                          );

    if ((boolean)FLEXIO_LIN_IP_SLAVE == UserConfig->NodeFunction)
    {
        SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_11();
        /* Slave will enable break length detect interrupt */
        /* Configure Rx Timer to generate clock for receiving bits of break frame - 1 Start bit */
        TempByte = Base->TIMCMP[UserConfig->RxTimerId];
        TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
        TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32((uint32)(UserConfig->SlaveSyncBreakLength) - 1u);
        Base->TIMCMP[UserConfig->RxTimerId] = TempByte;

        SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_11();
    }
    else
    {
        SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_15();
        /* Disable the Rx and Tx timers */
        Base->TIMCTL[UserConfig->RxTimerId] = (Base->TIMCTL[UserConfig->RxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_DISABLED);
        Base->TIMCTL[UserConfig->TxTimerId] = (Base->TIMCTL[UserConfig->TxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_DISABLED);

        SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_15();
        /* Disable Rx interrupt */
        Flexio_Mcl_Ip_SetShifterInterrupt(Base,
                                          (uint8)(1U << UserConfig->RxShifterId),
                                          FALSE);
    }
    /* Clear Bus busy Flag */
    LinCurrentState->IsBusBusy = FALSE;

    LinCurrentState->PreviousNodeState = LinCurrentState->CurrentNodeState;
    /* Change node's current state to IDLE */
    LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_IDLE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_AbortTransferData
 * Description   : Aborts an on-going non-blocking transmission/reception.
 * While performing a non-blocking transferring data, users can call this
 * function to terminate immediately the transferring.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_AbortTransferData_Activity
*/
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_AbortTransferData(const uint8 Channel)
{
    const Flexio_Lin_Ip_UserConfigType * UserConfig;
    Flexio_Lin_Ip_StatusType RetVal;
    const uint8 *DummyBuff;
    volatile Flexio_Lin_Ip_TransferStatusType TransmissionStatus;
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION
    const Flexio_Lin_Ip_StateStructType * LinCurrentState;
    #endif
#endif

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
#endif

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
#endif

    Flexio_Lin_Ip_DisableAllInterrupt(Channel);
    /*Call Flexio_Lin_Ip_GetStatus to get status of current node*/
    TransmissionStatus = Flexio_Lin_Ip_GetStatus(Channel, &DummyBuff);
    (void)DummyBuff;
    /*Add label Fault Injecton */
    MCAL_FAULT_INJECTION_POINT(FLEXIO_FIP_1_T_TIME_OUT_1);
    /* Check if driver is ongoing transmission in some case as : Master: Ongoing transmission (Header or Response). Slave: Ongoing transmission response" */
    /* The LIN driver shall abort the current frame transmission if a new frame transmission is requested by the LIN interface (see LinSendFrame), also if an ongoing transmission may be still in progress or unsuccessfully completed */
    if (FLEXIO_LIN_IP_STATUS_TX_BUSY != TransmissionStatus)
    {
        RetVal = FLEXIO_LIN_IP_STATUS_SUCCESS;
    }
    else
    {
        RetVal = Flexio_Lin_Ip_AbortTransferWhenBusBusy(Channel, UserConfig);
    }
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif
    if (LinCurrentState->TimerCounting)
    {
        /* Call notification to stop timer in case this is counting */
        FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION(Channel);
    }
    #endif
#endif
    /* Change node's current state to IDLE */
    Flexio_Lin_Ip_GoToIdleState(Channel);

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_MasterSendHeader
 * Description   : This function sends frame header out through the FLEXIO module
 * using a non-blocking method. Non-blocking  means that the function returns
 * immediately. This function sends LIN Break field, sync field then the ID with
 * correct parity. This function checks if the interface is Master, if not, it will
 * return FLEXIO_LIN_IP_STATUS_ERROR.This function checks if id is in range from 0 to 0x3F, if not
 * it will return FLEXIO_LIN_IP_STATUS_ERROR. This function also check node's current state is in
 * SLEEP mode then the function will return FLEXIO_LIN_IP_STATUS_ERROR. And check if bIsBusBusy is
 * currently (boolean)TRUE then the function will return FLEXIO_LIN_IP_STATUS_BUSY.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_SendFrame_Activity
*/
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_SendFrame(const uint8 Channel, const Flexio_Lin_Ip_PduType* PduInfo)
{
    Flexio_Lin_Ip_StatusType RetVal = FLEXIO_LIN_IP_STATUS_SUCCESS;
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    boolean CheckSleepMode;
    uint8 IndexLoop = 0U;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
#endif

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
#endif
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif

    /* Check whether current mode is sleep mode */
    CheckSleepMode = (FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE == LinCurrentState->CurrentNodeState);

    /* Check if the current node is slave or id is invalid or node's current
     * state is in SLEEP state */
    if  (
        (0U == PduInfo->Dl) || (8U < PduInfo->Dl) ||
        (0xFFU == Lin_Ip_ProcessParity(PduInfo->Pid, LIN_IP_CHECK_PARITY)) ||
          CheckSleepMode
        )
    {
        RetVal = FLEXIO_LIN_IP_STATUS_ERROR;
    }
    else
    {
        /* Check if driver is busy */
        if (LinCurrentState->IsBusBusy)
        {
            RetVal = FLEXIO_LIN_IP_STATUS_BUSY;
        }
        else
        {
            /* Clean buffer */
            for (IndexLoop = 0u; IndexLoop < FLEXIO_IP_MAX_DATA_LENGTH; IndexLoop++)
            {
                Flexio_Lin_Ip_au8SduBuffer[Channel][IndexLoop] = 0u;
            }

            if (FLEXIO_LIN_IP_FRAMERESPONSE_TX == PduInfo->Drc)
            {
                for (IndexLoop = 0u; IndexLoop < PduInfo->Dl; IndexLoop++)
                {
                    Flexio_Lin_Ip_au8SduBuffer[Channel][IndexLoop] = PduInfo->SduPtr[IndexLoop];
                }

                /* Make the CheckSum byte */
                if (FLEXIO_LIN_IP_CLASSIC_CS != PduInfo->Cs)
                {
                    /* Calculate enhanced CheckSum byte */
                    LinCurrentState->CheckSum = Lin_Ip_MakeChecksumByte(PduInfo->SduPtr, PduInfo->Dl, PduInfo->Pid);
                }
                else
                {
                    /* Classic CheckSum is not maked by Pid */
                    LinCurrentState->CheckSum = Lin_Ip_MakeChecksumByte(PduInfo->SduPtr, PduInfo->Dl, 0x00U);
                }
            }

            /* Save the current ID */
            LinCurrentState->CurrentId = PduInfo->Pid & LIN_IP_ID_MASK_U8;

            /* Save current PID */
            LinCurrentState->CurrentPid = PduInfo->Pid;

            /* Save the type of the current frame */
            LinCurrentState->FrameCommand = PduInfo->Drc;

            /* Save the type of checksum */
            LinCurrentState->Cs = PduInfo->Cs;

            /* Save the pointer to buffer */
            LinCurrentState->SduBuf = Flexio_Lin_Ip_au8SduBuffer[Channel];

            /* Save the data length */
            LinCurrentState->Dl = PduInfo->Dl;

            if ((boolean)FLEXIO_LIN_IP_MASTER == UserConfig->NodeFunction)
            {
                Flexio_Lin_Ip_MasterSendHeader(Channel);
            }
            else
            {
                Flexio_Lin_Ip_SlaveStartProcessingResponse(Channel);
            }
        }
    }

    return RetVal;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GoToSleepMode
 * Description   : This function puts current LIN node to sleep mode.
 * This function changes current node state to FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_GoToSleepMode_Activity
*/
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_GoToSleepMode(const uint8 Channel)
{
    FLEXIO_Type *Base;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    uint32 TempByte = 0UL;
    Flexio_Lin_Ip_StatusType RetStatus = FLEXIO_LIN_IP_STATUS_SUCCESS;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
#endif

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
#endif
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif
    if (LinCurrentState->IsBusBusy)
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_ERROR;
    }
    else
    {

        if (FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE != LinCurrentState->CurrentNodeState)
        {
            Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];
            /* Disable Timers and Shifters before ready to detect wakeup pulse */
            /* Disable the Rx and Tx timers */
            SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_17();
            Base->TIMCTL[UserConfig->RxTimerId] = (Base->TIMCTL[UserConfig->RxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_DISABLED);
            Base->TIMCTL[UserConfig->TxTimerId] = (Base->TIMCTL[UserConfig->TxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_DISABLED);
            SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_17();
            Flexio_Lin_Ip_DisableAllInterrupt(Channel);

            /* Discard data in Rx shift buffer */
            (void)Base->SHIFTBUFBYS[UserConfig->RxTimerId];
            /* Reset to no event */
            LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_NO_EVENT;
            /* Set bus to idle */
            LinCurrentState->IsBusBusy = FALSE;
            /* Update node state to fit sleep mode */
            LinCurrentState->CurrentNodeState = FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE;

            SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_18();
            /* Enable wakeup pulse detection */
            /* Configure Tx Timer */
            TempByte = Base->TIMCMP[UserConfig->TxTimerId];
            /* Set frame size to 8 bits */
            TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
            TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8u);
            Base->TIMCMP[UserConfig->TxTimerId] = TempByte;

            /* Configure Rx Timer */
            TempByte = Base->TIMCMP[UserConfig->RxTimerId];
            /* Set frame size to 8 bits */
            TempByte = TempByte & (~FLEXIO_IP_TIMCMP_BITS_NUMBER_MASK_U32);
            TempByte |= FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8u);
            Base->TIMCMP[UserConfig->RxTimerId] = TempByte;

            /* Enable the timers in 8 bits counters baud */
            Base->TIMCTL[UserConfig->RxTimerId] = (Base->TIMCTL[UserConfig->RxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_8BIT_BAUD);
            Base->TIMCTL[UserConfig->TxTimerId] = (Base->TIMCTL[UserConfig->TxTimerId] & ~(FLEXIO_TIMCTL_TIMOD_MASK)) | FLEXIO_TIMCTL_TIMOD(FLEXIO_TIMER_MODE_8BIT_BAUD);
            SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_18();

            /* Clear any leftover  flags */
            Flexio_Lin_Ip_ClearShifterErrorStatus(Channel);
            Flexio_Mcl_Ip_ClearShifterStatus(Base, UserConfig->RxShifterId);

            /* No need to enable shifters error interrupt due to wakeup pulse may greater than normal frame duration and lead to frame error */
            /* Enable Receive Complete Interrupt */
            Flexio_Mcl_Ip_SetShifterInterrupt(Base, \
                                              (uint8)(1U << UserConfig->RxShifterId), \
                                              (boolean)TRUE);
        }
        else
        {
            /*Do - Nothing*/
        }
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_SendWakeupSignal
 * Description   : This function sends a wakeup signal through the FLEXIO interface
 * after the Channel is in Idle state.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_SendWakeupSignal_Activity
*/
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_SendWakeupSignal(const uint8 Channel)
{
    Flexio_Lin_Ip_StatusType RetVal = FLEXIO_LIN_IP_STATUS_SUCCESS;
    FLEXIO_Type *Base;
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    const Flexio_Lin_Ip_UserConfigType *UserConfig;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
#endif

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
#endif
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif

    /* Wakeup signal is only sent when node state in Sleep mode and not busy */
    if ((FALSE != LinCurrentState->IsBusBusy) || (FLEXIO_LIN_IP_NODE_STATE_SLEEP_MODE != LinCurrentState->CurrentNodeState))
    {
        RetVal = FLEXIO_LIN_IP_STATUS_ERROR;
    }
    else
    {
        Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];
        /* mark the bus as busy */
        LinCurrentState->IsBusBusy = TRUE;

        /* Clear any leftover  flags */
        Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->RxShifterId);
        Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, UserConfig->TxShifterId);
        (void)Base->SHIFTBUF[UserConfig->RxShifterId];

        /* In Sleep mode, other node can send wakeup signal at the same time lead to frame error may be occurred, so no need to enable frame error checking.
        No need to disbale Shifters error interrupt again due to they are already disabled in Flexio_Lin_Ip_GoToSleepMode() */
        /* Rx Complete Interrupt already enabled in Flexio_Lin_Ip_GoToSleepMode(), it used to set node ready in Idle mode after wakeup byte sent */
        /* Write wakeup byte to buffer */
        Base->SHIFTBUF[UserConfig->TxShifterId]=(uint32)UserConfig->WakeupByte;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_IRQHandler
 * Description   : Interrupt handler for FLEXIO.
 * This handler uses the buffers stored in the Flexio_Lin_Ip_StateStructType struct to transfer
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_IRQHandler_Activity
*/
void Flexio_Lin_Ip_IrqHandler(uint8 ShifterIndex, uint8 ShifterMaskFlag, uint8 ShifterErrorMaskFlag)
{
    uint8 ShifterStatus = 0U;
    uint8 ShifterError = 0U;
    uint8 ShifterErrEnabled = 0U;
    FLEXIO_Type *Base;
    uint8 FlexioLinChannel = 0U;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_FLEXIO_SHIFTERS > ShifterIndex);
#endif
    FlexioLinChannel = Flexio_Lin_Ip_au8ShiftersIndex[ShifterIndex];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > FlexioLinChannel);
#endif
    Base = Flexio_Lin_Ip_apxBases[Flexio_Lin_Ip_apxUserConfigs[FlexioLinChannel]->FlexioHwInstance];
    /* Check if driver is initialized */
    if (NULL_PTR == Flexio_Lin_Ip_apxStateStructureArray[FlexioLinChannel])
    {
        Flexio_Mcl_Ip_ClearShifterStatus(Base, Flexio_Lin_Ip_apxUserConfigs[FlexioLinChannel]->TxShifterId);
        Flexio_Mcl_Ip_ClearShifterStatus(Base, Flexio_Lin_Ip_apxUserConfigs[FlexioLinChannel]->RxShifterId);
    }
    else
    {
        ShifterStatus = ShifterMaskFlag      &  (uint8)(1UL << ShifterIndex);
        ShifterError  = ShifterErrorMaskFlag &  (uint8)(1UL << ShifterIndex) ;
        /* In Slave mode, driver was disabled error rx and tx interrupt because frame error will be occured
        when external master send break length greater than 11 bits break detection but Shifter Error Flag still is set.
        Therefore to avoid jump Flexio_Lin_Ip_ErrInterruptHandler function, driver should be checked Shifter Error Interrupt is enable or not.*/
        ShifterErrEnabled  = (uint8)Flexio_Mcl_Ip_GetAllShifterErrorInterrupt(Base);
        ShifterErrEnabled &= (uint8)(1UL << ShifterIndex);

        /* Error Interrupt */
        if (0U != (ShifterError & ShifterErrEnabled))
        {
            Flexio_Lin_Ip_ErrInterruptHandler(FlexioLinChannel, ShifterErrorMaskFlag);
        }
        /* Receiver Interrupt */
        else if (0U != ShifterStatus)
        {
            Flexio_Lin_Ip_RxInterruptHandler(FlexioLinChannel);
        }
        else
        {
            /* Nothing to do */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_Deinit
 * Description   : This function shuts down the FLEXIO by disabling interrupts and
 *                 shifters and timers
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_Deinit_Activity
*/
Flexio_Lin_Ip_StatusType Flexio_Lin_Ip_Deinit(const uint8 Channel)
{
    const Flexio_Lin_Ip_UserConfigType *UserConfig;
    FLEXIO_Type *Base;
    const Flexio_Lin_Ip_StateStructType * LinCurrentState;
    Flexio_Lin_Ip_StatusType RetStatus = FLEXIO_LIN_IP_STATUS_SUCCESS;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
#endif

    UserConfig = Flexio_Lin_Ip_apxUserConfigs[Channel];
    Base = Flexio_Lin_Ip_apxBases[UserConfig->FlexioHwInstance];
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];
#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    FLEXIO_LIN_IP_DEV_ASSERT(Channel == UserConfig->Instance);
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != UserConfig);
#endif

    if (LinCurrentState->IsBusBusy)
    {
        RetStatus = FLEXIO_LIN_IP_STATUS_ERROR;
    }
    else
    {
        SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_19();
        /* Disable shifters and timers  */
        Base->SHIFTCTL[UserConfig->TxShifterId] &= ~(FLEXIO_SHIFTCTL_SMOD_MASK);
        Base->SHIFTCTL[UserConfig->RxShifterId] &= ~(FLEXIO_SHIFTCTL_SMOD_MASK);
        Base->TIMCTL[UserConfig->TxTimerId]     &= ~(FLEXIO_TIMCTL_TIMOD_MASK);
        Base->TIMCTL[UserConfig->RxTimerId]     &= ~(FLEXIO_TIMCTL_TIMOD_MASK);
        SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_19();
        /* Disable interrupt */
        Flexio_Mcl_Ip_SetShifterInterrupt(Base,(uint8)(1U << UserConfig->TxShifterId) | (uint8)(1U << UserConfig->RxShifterId), FALSE);
        Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base,(uint8)(1U << UserConfig->TxShifterId) | (uint8)(1U << UserConfig->RxShifterId), FALSE);
        Flexio_Mcl_Ip_SetTimerInterrupt(Base,(uint8)(1U << UserConfig->TxTimerId) | (uint8)(1U << UserConfig->RxTimerId), FALSE);

        /* Clear our saved pointer to the LIN state structure */
        Flexio_Lin_Ip_apxStateStructureArray[Channel] = NULL_PTR;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_GetStatus
 * Description   : This function returns the current state of the transmission.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_GetStatus_Activity
*/
Flexio_Lin_Ip_TransferStatusType Flexio_Lin_Ip_GetStatus(const uint8 Channel, const uint8 **Buffer)
{
    const Flexio_Lin_Ip_StateStructType *LinCurrentState;
    Flexio_Lin_Ip_TransferStatusType RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;
    Flexio_Lin_Ip_NodeStateType CurrentNodeState;

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_LIN_IP_NUMBER_OF_CHANNELS > Channel);
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != Buffer);
#endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this FLEXIO instance. */
    LinCurrentState = (const Flexio_Lin_Ip_StateStructType *)Flexio_Lin_Ip_apxStateStructureArray[Channel];

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    CurrentNodeState = LinCurrentState->CurrentNodeState;

    switch (LinCurrentState->CurrentEventId)
    {
        case FLEXIO_LIN_IP_SYNC_ERROR:
            /* fall-through */
        case FLEXIO_LIN_IP_PID_ERROR:
            /* Error occurred in header reception */
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        case FLEXIO_LIN_IP_RECV_BREAK_FIELD_OK:
            /* fall-through */
        case FLEXIO_LIN_IP_BAUDRATE_ADJUSTED:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_HEADER_BUSY;
            break;
        case FLEXIO_LIN_IP_SEND_HEADER_OK:
            /* Call Flexio_Lin_Ip_GetStatusFromSendHeaderOk to get status from send header event is successfully */
            RetStatus = Flexio_Lin_Ip_GetStatusFromSendHeaderOk(Channel, CurrentNodeState);
            break;
        case FLEXIO_LIN_IP_RECV_HEADER_OK:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_HEADER_OK;
            break;
        case FLEXIO_LIN_IP_WAKEUP_SIGNAL:
            RetStatus = FLEXIO_LIN_IP_STATUS_OPERATIONAL;
            break;
        case FLEXIO_LIN_IP_RX_OVERRUN_ERROR:
            /* Call Flexio_Lin_Ip_GetStatusFromRxOverrunError to get status from the Rx Overrun error event. */
            RetStatus = Flexio_Lin_Ip_GetStatusFromRxOverrunError(Channel);
            break;
        #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
        case FLEXIO_LIN_IP_TIMEOUT_ERROR:
            /* Call Flexio_Lin_Ip_GetStatusFromTimeoutError to get status from time out error event */
            RetStatus = Flexio_Lin_Ip_GetStatusFromTimeoutError(Channel);

            break;
        #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
        case FLEXIO_LIN_IP_READBACK_ERROR:
            /* Call Flexio_Lin_Ip_GetStatusFromReadBackError to get status from readback error event */
            RetStatus = Flexio_Lin_Ip_GetStatusFromReadBackError(Channel);
            break;
        case FLEXIO_LIN_IP_CHECKSUM_ERROR_EVENT:
            /* Received checksum byte is incorrect */
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_ERROR;
            break;
        case FLEXIO_LIN_IP_TX_UNDERRUN_ERROR:
            /* To obtain status from the Tx Underrun error event, use Flexio_Lin_Ip_GetStatusFromTxUnderrunError.*/
            RetStatus = Flexio_Lin_Ip_GetStatusFromTxUnderrunError(Channel);
            break;
        case FLEXIO_LIN_IP_TX_COMPLETED:
            RetStatus = FLEXIO_LIN_IP_STATUS_TX_OK;
            break;
        case FLEXIO_LIN_IP_RX_COMPLETED:
            RetStatus = FLEXIO_LIN_IP_STATUS_RX_OK;
            *Buffer = Flexio_Lin_Ip_au8SduBuffer[Channel];
            break;
        case FLEXIO_LIN_IP_NO_EVENT:
            /* Call Flexio_Lin_Ip_GetStatusFromNoEvent to get status when no event */
            RetStatus = Flexio_Lin_Ip_GetStatusFromNoEvent(CurrentNodeState);
            break;
        default:
            RetStatus = FLEXIO_LIN_IP_STATUS_FAIL;
            break;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Lin_Ip_TimerExpiredService
 * Description   : This is callback function for Timer Interrupt Handler.
 * Users shall initialize a timer (for example FTM)
 * and the time period in microseconds will be set by the driver via LinFlexioStartTimerNotification.
 * In timer IRQ handler, call this function.
 *
 *END**************************************************************************/
/**
* @implements Flexio_Lin_Ip_TimerExpiredService_Activity
*/
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
void Flexio_Lin_Ip_TimerExpiredService(const uint8 Channel)
{
    Flexio_Lin_Ip_StateStructType *LinCurrentState;
    const Flexio_Lin_Ip_UserConfigType *UserConfig;

    #if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(FLEXIO_INSTANCE_COUNT > Channel);
    #endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this FLEXIO Channel. */
    LinCurrentState = Flexio_Lin_Ip_apxStateStructureArray[Channel];
    UserConfig   = Flexio_Lin_Ip_apxUserConfigs[Channel];

    #if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    FLEXIO_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
    #endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    #if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
    #ifdef FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION
    LinCurrentState->TimerCounting = FALSE;
    /* Call notification to stop timer when timeout occurred */
    FLEXIO_LIN_IP_STOP_TIMER_NOTIFICATION(Channel);
    #endif
    #endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

    /* Check LIN node's current state when timeout occurred */
    switch(LinCurrentState->CurrentNodeState)
    {
        /* If the node is receiving SYNC byte */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_SYNC:
            /* fall-through */
        /* If the node is receiving PID byte */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_PID:
            /* fall-through */
        /* If the node is receiving DATA response bytes */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA:
            /* fall-through */
        /* If the node is receiving CHECKSUM byte */
        case FLEXIO_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED:
            /* Set current event to timeout error */
            LinCurrentState->CurrentEventId = FLEXIO_LIN_IP_TIMEOUT_ERROR;
            /* Change node's current state to IDLE to switch lin node ready operation soon */
            Flexio_Lin_Ip_GoToIdleState(Channel);

            if (NULL_PTR != UserConfig->Callback)
            {
                UserConfig->Callback(Channel, LinCurrentState);
            }
            break;

        default:
            /* The node state is not receiving header, response data bytes or checksum */
            break;
    }
}
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#endif /* (STD_ON == FLEXIO_LIN_IP_FLEXIO_USED) */

#ifdef __cplusplus
}
#endif

/** @} */
