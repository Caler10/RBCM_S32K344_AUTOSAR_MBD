/**
*   @file    CanIf_Types.h
*   @version 5.0.0
*
*   @brief   AUTOSAR CanIf - CanIf module interface
*   @details AUTOSAR CanIf module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   (c) Copyright 2020 - 2024 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "EcuM.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_TYPES_VENDOR_ID                         43
#define CANIF_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_TYPES_AR_RELEASE_MINOR_VERSION          7
#define CANIF_TYPES_AR_RELEASE_REVISION_VERSION       0
#define CANIF_TYPES_SW_MAJOR_VERSION                  5
#define CANIF_TYPES_SW_MINOR_VERSION                  0
#define CANIF_TYPES_SW_PATCH_VERSION                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Can_GeneralTypes.h header file are of the same version */
    #if ((CANIF_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_TYPES_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf_Types.h and Can_GeneralTypes.h are different"
    #endif

    /* Check if current file and EcuM.h header file are of the same version */
    #if ((CANIF_TYPES_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_TYPES_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf_Types.h and EcuM.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*! @brief Development Error ID for "API service called with invalid CAN ID" */
#define CANIF_E_PARAM_CANID                             ((uint8)10U)
/*! @brief Development Error ID for "API service called with invalid hardware object" */
#define CANIF_E_PARAM_HOH                               ((uint8)12U)
/*! @brief Development Error ID for "API service called with invalid PDU ID" */
#define CANIF_E_PARAM_LPDU                              ((uint8)13U)
/*! @brief Development Error ID for "API service called with invalid controller ID" */
#define CANIF_E_PARAM_CONTROLLERID                      ((uint8)15U)
/*! @brief Development Error ID for "API service called with invalid wakeup source" */
#define CANIF_E_PARAM_WAKEUPSOURCE                      ((uint8)16U)
/*! @brief Development Error ID for "API service called with invalid transceiver ID" */
#define CANIF_E_PARAM_TRCV                              ((uint8)17U)
/*! @brief Development Error ID for "API service called with invalid transceiver mode" */
#define CANIF_E_PARAM_TRCVMODE                          ((uint8)18U)
/*! @brief Development Error ID for "API service called with invalid transceiver wakeup mode" */
#define CANIF_E_PARAM_TRCVWAKEUPMODE                    ((uint8)19U)
/*! @brief Development Error ID for "API service called with invalid pointer" */
#define CANIF_E_PARAM_POINTER                           ((uint8)20U)
/*! @brief Development Error ID for "API service called with invalid controller mode" */
#define CANIF_E_PARAM_CTRLMODE                          ((uint8)21U)
/*! @brief Development Error ID for "API service called with invalid PDU mode" */
#define CANIF_E_PARAM_PDU_MODE                          ((uint8)22U)
/*! @brief Development Error ID for "API services called with invalid parameter" */
#define CANIF_E_PARAM_CAN_ERROR                         ((uint8)23U)
/*! @brief Development Error ID for "API service used without module initialization" */
#define CANIF_E_UNINIT                                  ((uint8)30U)
/*! @brief Development Error ID for "Transmit PDU ID invalid" */
#define CANIF_INVALID_TXPDUID                           ((uint8)50U)
/*! @brief Development Error ID for "Receive PDU ID invalid" */
#define CANIF_INVALID_RXPDUID                           ((uint8)60U)
/*! @brief Development Error ID for "CAN Interface initialisation failed" */
#define CANIF_INIT_FAILED                               ((uint8)80U)
/*! @brief Runtime Error ID for "Failed Data Length Check" */
#define CANIF_E_INVALID_DATA_LENGTH                     ((uint8)61U)
/*! @brief Runtime Error ID for "Data Length" */
#define CANIF_E_DATA_LENGTH_MISMATCH                    ((uint8)62U)
/*! @brief Runtime Error ID for "Transmit requested on offline PDU channel" */
#define CANIF_E_STOPPED                                 ((uint8)70U)
/*! @brief Runtime Error ID for "Message length was exceeding the maximum length" */
#define CANIF_E_TXPDU_LENGTH_EXCEEDED                   ((uint8)90U)


/*! @brief Service ID of CanIf_Init */
#define CANIF_SID_INIT                                  ((uint8)0x01U)
/*! @brief Service ID of CanIf_DeInit */
#define CANIF_SID_DEINIT                                ((uint8)0x02U)
/*! @brief Service ID of CanIf_SetControllerMode */
#define CANIF_SID_SET_CONTROLLER_MODE                   ((uint8)0x03U)
/*! @brief Service ID of CanIf_GetControllerMode */
#define CANIF_SID_GET_CONTROLLER_MODE                   ((uint8)0x04U)
/*! @brief Service ID of CanIf_GetControllerErrorState */
#define CANIF_SID_GET_CONTROLLER_ERROR_STATE            ((uint8)0x4BU)
/*! @brief Service ID of CanIf_Transmit */
#define CANIF_SID_TRANSMIT                              ((uint8)0x49U)
/*! @brief Service ID of CanIf_ReadRxPduData */
#define CANIF_SID_READ_RX_PDU_DATA                      ((uint8)0x06U)
/*! @brief Service ID of CanIf_ReadTxNotifStatus */
#define CANIF_SID_READ_TX_NOTIF_STATUS                  ((uint8)0x07U)
/*! @brief Service ID of CanIf_ReadRxNotifStatus */
#define CANIF_SID_READ_RX_NOTIF_STATUS                  ((uint8)0x08U)
/*! @brief Service ID of CanIf_SetPduMode */
#define CANIF_SID_SET_PDU_MODE                          ((uint8)0x09U)
/*! @brief Service ID of CanIf_GetPduMode */
#define CANIF_SID_GET_PDU_MODE                          ((uint8)0x0AU)
/*! @brief Service ID of CanIf_GetVersionInfo */
#define CANIF_SID_GET_VERSION_INFO                      ((uint8)0x0BU)
/*! @brief Service ID of CanIf_SetDynamicTxId */
#define CANIF_SID_SET_DYNAMIC_TX_ID                     ((uint8)0x0CU)
/*! @brief Service ID of CanIf_SetTrcvMode */
#define CANIF_SID_SET_TRCV_MODE                         ((uint8)0x0DU)
/*! @brief Service ID of CanIf_GetTrcvMode */
#define CANIF_SID_GET_TRCV_MODE                         ((uint8)0x0EU)
/*! @brief Service ID of CanIf_GetTrcvWakeupReason */
#define CANIF_SID_GET_TRCV_WAKEUP_REASON                ((uint8)0x0FU)
/*! @brief Service ID of CanIf_SetTrcvWakeupMode */
#define CANIF_SID_SET_TRCV_WAKEUP_MODE                  ((uint8)0x10U)
/*! @brief Service ID of CanIf_CheckWakeup */
#define CANIF_SID_CHECK_WAKEUP                          ((uint8)0x11U)
/*! @brief Service ID of CanIf_CheckValidation */
#define CANIF_SID_CHECK_VALIDATION                      ((uint8)0x12U)
/*! @brief Service ID of CanIf_GetTxConfirmationState */
#define CANIF_SID_GET_TX_CONFIRMATION_STATE             ((uint8)0x19U)
/*! @brief Service ID of CanIf_ClearTrcvWufFlag */
#define CANIF_SID_CLEAR_TRCV_WUF_FLAG                   ((uint8)0x1EU)
/*! @brief Service ID of CanIf_CheckTrcvWakeFlag */
#define CANIF_SID_CHECK_TRCV_WAKE_FLAG                  ((uint8)0x1FU)
/*! @brief Service ID of CanIf_SetBaudrate */
#define CANIF_SID_SET_BAUDRATE                          ((uint8)0x27U)
/*! @brief Service ID of CanIf_GetControllerRxErrorCounter */
#define CANIF_SID_GET_CONTROLLER_RX_ERROR_COUNTER       ((uint8)0x4DU)
/*! @brief Service ID of CanIf_GetControllerTxErrorCounter */
#define CANIF_SID_GET_CONTROLLER_TX_ERROR_COUNTER       ((uint8)0x4EU)
/*! @brief Service ID of CanIf_EnableBusMirroring */
#define CANIF_SID_ENABLE_BUS_MIRRORING                  ((uint8)0x4CU)
/*! @brief Service ID of CanIf_GetCurrentTime */
#define CANIF_SID_GET_CURRENT_TIME                      ((uint8)0x51U)
/*! @brief Service ID of CanIf_EnableEgressTimeStamp */
#define CANIF_SID_ENABLE_EGRESS_TIMESTAMP               ((uint8)0x52U)
/*! @brief Service ID of CanIf_GetEgressTimeStamp */
#define CANIF_SID_GET_EGRESS_TIMESTAMP                  ((uint8)0x53U)
/*! @brief Service ID of CanIf_GetIngressTimeStamp */
#define CANIF_SID_GET_INGRESS_TIMESTAMP                 ((uint8)0x54U)
/*! @brief Service ID of CanIf_TriggerTransmit */
#define CANIF_SID_TRIGGER_TRANSMIT                      ((uint8)0x41U)
/*! @brief Service ID of CanIf_TxConfirmation */
#define CANIF_SID_TX_CONFIRMATION                       ((uint8)0x13U)
/*! @brief Service ID of CanIf_RxIndication */
#define CANIF_SID_RX_INDICATION                         ((uint8)0x14U)
/*! @brief Service ID of CanIf_ControllerBusOff */
#define CANIF_SID_CONTROLLER_BUSOFF                     ((uint8)0x16U)
/*! @brief Service ID of CanIf_ConfirmPnAvailability */
#define CANIF_SID_CONFIRM_PN_AVAILABILITY               ((uint8)0x1AU)
/*! @brief Service ID of CanIf_ClearTrcvWufFlagIndication */
#define CANIF_SID_CLEAR_TRCV_WUF_FLAG_INDICATION        ((uint8)0x20U)
/*! @brief Service ID of CanIf_CheckTrcvWakeFlagIndication */
#define CANIF_SID_CHECK_TRCV_WAKE_FLAG_INDICATION       ((uint8)0x21U)
/*! @brief Service ID of CanIf_ControllerModeIndication */
#define CANIF_SID_CONTROLLER_MODE_INDICATION            ((uint8)0x17U)
/*! @brief Service ID of CanIf_TrcvModeIndication */
#define CANIF_SID_TRCV_MODE_INDICATION                  ((uint8)0x22U)
/*! @brief Service ID of CanIf_ControllerErrorStatePassive */
#define CANIF_SID_CONTROLLER_ERROR_STATE_PASSIVE        ((uint8)0x4FU)
/*! @brief Service ID of CanIf_ErrorNotification */
#define CANIF_SID_ERROR_NOTIFICATION                    ((uint8)0x50U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
    CANIF_EXTENDED_CAN = 0U,        /* CAN frame with extended identifier (29 bits) */
    CANIF_EXTENDED_FD_CAN,          /* CAN FD frame with extended identifier (29 bits) */
    CANIF_STANDARD_CAN,             /* CAN frame with standard identifier (11 bits) */
    CANIF_STANDARD_FD_CAN           /* CAN FD frame with standard identifier (11 bits) */
} CanIf_FrameType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* This is a function pointer type for the TriggerTransmit function of all upper layers of CanIf. */
typedef Std_ReturnType (*CanIf_UserTriggerTransmitPtrType)(PduIdType TxPduId, PduInfoType* PduInfoPtr);
/* This is a function pointer type for the TxConfirmation function of all upper layers of CanIf. */
typedef void (*CanIf_UserTxConfirmationPtrType)(PduIdType CanIfTxPduId, Std_ReturnType result);
/* This is a function pointer type for the RxIndication function of all upper layers of CanIf. */
typedef void (*CanIf_UserRxIndicationPtrType)(PduIdType RxPduId, const PduInfoType * PduInfoPtr);
/* This is a function pointer type for the ValidateWakeupEvent function of all upper layers of CanIf. */
typedef void (*CanIf_UserValidateWakeupEventPtrType)(EcuM_WakeupSourceType sources);
/* This is a function pointer type for the ControllerBusOff function of all upper layers of CanIf. */
typedef void (*CanIf_UserControllerBusOffPtrType)(uint8 ControllerId);
/* This is a function pointer type for the ConfirmPnAvailability function of all upper layers of CanIf. */
typedef void (*CanIf_UserConfirmPnAvailabilityPtrType)(uint8 TransceiverId);
/* This is a function pointer type for the ClearTrcvWufFlagIndication function of all upper layers of CanIf. */
typedef void (*CanIf_UserClearTrcvWufFlagIndicationPtrType)(uint8 TransceiverId);
/* This is a function pointer type for the CheckTrcvWakeFlagIndication function of all upper layers of CanIf. */
typedef void (*CanIf_UserCheckTrcvWakeFlagIndicationPtrType)(uint8 TransceiverId);
/* This is a function pointer type for the ControllerModeIndication function of all upper layers of CanIf. */
typedef void (*CanIf_UserControllerModeIndicationPtrType)(uint8 ControllerId, Can_ControllerStateType ControllerMode);
/* This is a function pointer type for the TrcvModeIndication function of all upper layers of CanIf. */
typedef void (*CanIf_UserTrcvModeIndicationPtrType)(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

/* ----------------------Definition of function pointer types to CanDrv API(s)---------------------*/
/* Pointer to Can_Write */
typedef Std_ReturnType (*CanIf_CanWriteFuncPtrType)(Can_HwHandleType Hth, const Can_PduType * PduInfo);

/* -------------Pre-compile structures - which always are constant accorss all variants------------*/
typedef struct
{
    const CanIf_CanWriteFuncPtrType CanWrite;     /**< Pointer to corresponding Can_Write API defined in corresponding CanDRV */
} CanIf_CanDrvFuncPtrType;

/* Define structure for callback notification function of upper layer modules  */
typedef struct
{
    const CanIf_UserValidateWakeupEventPtrType UserValidateWakeupEvent;                     /* Callback function indicates if a wake up event initiated from the wake up source */
    const CanIf_UserControllerBusOffPtrType UserControllerBusOff;                           /* Callback function indicates a bus-off event to the corresponding upper layer module */
    const CanIf_UserConfirmPnAvailabilityPtrType UserConfirmPnAvailability;                 /* Callback function indicates that the CAN transceiver is running in PN communication mode */
    const CanIf_UserClearTrcvWufFlagIndicationPtrType UserClearTrcvWufFlagIndication;       /* Callback function indicates that the CAN transceiver has cleared the WufFlag */
    const CanIf_UserCheckTrcvWakeFlagIndicationPtrType UserCheckTrcvWakeFlagIndication;     /* Callback function indicates that the wake up flag in the CAN transceiver is set */
    const CanIf_UserControllerModeIndicationPtrType UserControllerModeIndication;           /* Callback function indicates a CAN controller state transition to the corresponding upper layer module */
    const CanIf_UserTrcvModeIndicationPtrType UserTrcvModeIndication;                       /* Callback function indicates a CAN transceiver state transition to the corresponding upper layer module */
}CanIf_CallbackNotifULPtrType;


typedef struct
{
    const uint8 CanDrvId;                           /**<  CanDrv Id confugred in CanIf */
    const Can_HwHandleType NumCanHoh;               /**<  Total number of HOH of CanDrv */
    const CanIf_CanDrvFuncPtrType * CanApi;         /**<  Pointer to Can_Write API */
} CanIf_CanDrvPCConfigType;

typedef struct
{
    const uint8 CanIfCtrlId;                            /**< Specifies the CanIf controller Id configured in CanIf Drv */
    const uint8 CanCtrlId;                              /**< Specifies the Can controller Id configured in Can Drv referred from CanIf Drv */
    const CanIf_CanDrvPCConfigType * CanDrvConfigPtr;  /**< The CanDrv which the CanIf controller refers to */
} CanIf_CtrlPCConfigType;

typedef struct
{
    const uint8 NumOfCtrl;
    const CanIf_CallbackNotifULPtrType * CanIfDispatchCfgPtr;
    const CanIf_CtrlPCConfigType * CanIfCtrlConfigPtr;
} CanIf_PCConfigType;
/* --------------------Postbuild structures - which can have different values accross all variants---*/
typedef struct
{
    const PduIdType PduId;                                  /* PduId */
    const boolean PduLengthCheck;                           /* Specifies if the Pdu length will be checked */
    const uint16 PduLength;                                 /* PduLength */
    const uint8 CanIfCtrlId;                                /* The CanIf controller Id which the PDU belongs to */
    const CanIf_UserRxIndicationPtrType UserRxIndication;   /*  UserRxIndication function pointer */
} CanIf_RxPduType;

typedef struct
{
    const PduIdType PduId;                                      /* PduId */
    const Can_IdType CanId;                                     /* CanId */
    const CanIf_FrameType CanFrameType;                         /* Frame type */
    const Can_HwHandleType CanHth;                              /* Hth */
    const uint8 CanIfCtrlId;                                    /* The CanIf controller Id which the PDU belongs to */
    const CanIf_UserTxConfirmationPtrType UserTxConfirmation;   /*  UserRxIndication function pointer */
} CanIf_TxPduType;

typedef struct
{
    const CanIf_RxPduType * const * HohToRxPduMappingPtr;
} CanIf_CanDrvConfigType;

#ifdef __cplusplus
}
#endif

#endif 
