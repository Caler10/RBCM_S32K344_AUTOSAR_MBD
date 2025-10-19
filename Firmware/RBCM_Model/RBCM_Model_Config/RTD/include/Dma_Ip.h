/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef DMA_IP_DRIVER_H_
#define DMA_IP_DRIVER_H_

/**
*   @file    Dma_Ip.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver header file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_VENDOR_ID                       43
#define DMA_IP_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_SW_MAJOR_VERSION                5
#define DMA_IP_SW_MINOR_VERSION                0
#define DMA_IP_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Cfg.h file are of the same vendor */
#if (DMA_IP_VENDOR_ID != DMA_IP_CFG_VENDOR_ID)
    #error "Dma_Ip.h and Dma_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Cfg.h file are of the same Autosar version */
#if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_AR_RELEASE_MINOR_VERSION != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_AR_RELEASE_REVISION_VERSION != DMA_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip.h and Dma_Ip_Cfg.h are different"
#endif

/* Check if header file and Dma_Ip_Cfg.h file are of the same Software version */
#if ((DMA_IP_SW_MAJOR_VERSION != DMA_IP_CFG_SW_MAJOR_VERSION) || \
     (DMA_IP_SW_MINOR_VERSION != DMA_IP_CFG_SW_MINOR_VERSION) || \
     (DMA_IP_SW_PATCH_VERSION != DMA_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip.h and Dma_Ip_Cfg.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief This type contains the Dma Ip Logic Instance Commands.
 * @details The Commands trigger specific actions in the Dma Logic Instance.
 *
 * */
typedef enum{
    DMA_IP_INST_CANCEL_TRANSFER            = 0U, /**< @brief The Cancel Transfer cancels the executing channel and forces the Minor Loop to finish. */
    DMA_IP_INST_CANCEL_TRANSFER_WITH_ERROR = 1U, /**< @brief The Cancel Transfer With Error Command cancels the executing channel, forces the Minor Loop to finish and generates an error interrupt. */
    DMA_IP_INST_HALT                       = 2U, /**< @brief The Halt Command allows the ongoing transfer to finish and halts any new transfer. */
    DMA_IP_INST_RESUME                     = 3U, /**< @brief The Resume Command allows the transfer to continue. */
}Dma_Ip_LogicInstanceCmdType;

/**
 * @brief This type contains the Dma Ip Logic Channel Commands.
 * @details The Commands trigger specific actions in the Dma Ip Logic Channel.
 *
 * */
typedef enum{
    DMA_IP_CH_SET_HARDWARE_REQUEST   = 0U, /**< @brief The Set Hardware Request Command enables the Dma Channel to be triggered by hardware requests. */
    DMA_IP_CH_CLEAR_HARDWARE_REQUEST = 1U, /**< @brief The Clear Hardware Request Command disables the Dma Channel to be triggered by hardware requests. */
    DMA_IP_CH_SET_SOFTWARE_REQUEST   = 2U, /**< @brief The Set Software Request Command sends a soft start request to the Dma Channel. */
    DMA_IP_CH_CLEAR_DONE             = 3U, /**< @brief The Clear Done Command resets the Dma Channel Done status. */
    DMA_IP_CH_CLEAR_ERROR            = 4U, /**< @brief The Clear Error Command resets the Dma Channel Error status. */
    DMA_IP_CH_CLEAR_INTERRUPT_STATUS = 5U, /**< @brief The Clear Interrupt Status Command clears the Dma Channel Interrupt status. */
}Dma_Ip_LogicChannelCmdType;

/**
 * @brief This type contains the Dma Ip Logic Channel Global Parameters.
 * @details The Parameters set specific functionalities for the Dma Ip Logic Channel.
 *
 * */
typedef enum{
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
    DMA_IP_CH_SET_EN_MASTER_ID_REPLICATION =  0U, /**< @brief [BOOLEAN] The EnMasterIdReplication Parameter sets the Dma Channel to use the same protection level and system bus ID of the master programming the Dma Channel. */
#endif
#if (STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE)
    DMA_IP_CH_SET_EN_BUFFERED_WRITES       =  1U, /**< @brief [BOOLEAN] The EnBufferedWrites Parameter sets the Dma Channel writes to be bufferable. */
#endif
    DMA_IP_CH_SET_EN_HARDWARE_REQ          =  2U, /**< @brief [BOOLEAN] The EnRequest Parameter enables the Dma Channel Request. */
    DMA_IP_CH_SET_EN_ERROR_INTERRUPT       =  3U, /**< @brief [BOOLEAN] The EnError Parameter enables the Dma Channel Error Interrupt. */
    DMA_IP_CH_SET_GROUP_PRIORITY           =  4U, /**< @brief [VALUE]   The Group Parameter sets the Dma Channel Group Priority. */
    DMA_IP_CH_SET_LEVEL_PRIORITY           =  5U, /**< @brief [VALUE]   The Level Parameter sets the Dma Channel Level Priority. */
#if (STD_ON == DMA_IP_PREEMPTION_IS_AVAILABLE)
    DMA_IP_CH_SET_EN_PREEMPTION_PRIORITY   =  6U, /**< @brief [BOOLEAN] The EnPreemption Parameter enables the Dma Channel Preemption. */
#endif
#if (STD_ON == DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE)
    DMA_IP_CH_SET_DIS_PREEMPT_PRIORITY     = 7U, /**< @brief [BOOLEAN] The DisPreempt Parameter disables the Dma Channel Preempt. */
#endif
#if (STD_ON == DMA_IP_SWAP_SIZE_IS_AVAILABLE)
    DMA_IP_CH_SET_SWAP_SIZE                = 8U, /**< @brief [VALUE]   The Swap Size sets the swap data elements within the specified transfer. */
#endif
}Dma_Ip_LogicChannelGlobalParamType;

/**
 * @brief This type contains the Dma Ip Logic Channel Transfer Parameters.
 * @details The Parameters set specific functionalities.
 *
 * */
typedef enum{
    DMA_IP_CH_SET_SOURCE_ADDRESS                   =  0U, /**< @brief [VALUE]   The Source Address Parameter sets the Dma Channel source address value. */
    DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET             =  1U, /**< @brief [VALUE]   The Source Signed Offset Parameter sets the Dma Channel source signed offset value. */
    DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ      =  2U, /**< @brief [VALUE]   The Source Signed Last Address Adjustment Parameter sets the Dma Channel source signed last address adjustment. */
    DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE             =  3U, /**< @brief [VALUE]   The Source Transfer Size Parameter sets the Dma Channel source transfer size. */
    DMA_IP_CH_SET_SOURCE_MODULO                    =  4U, /**< @brief [VALUE]   The Source Modulo Parameter sets the Dma Channel source modulo. */
    DMA_IP_CH_SET_DESTINATION_ADDRESS              =  5U, /**< @brief [VALUE]   The Destination Address Parameter sets the Dma Channel destination address value. */
    DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET        =  6U, /**< @brief [VALUE]   The Destination Signed Offset Parameter sets the Dma Channel destination signed offset value. */
    DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ =  7U, /**< @brief [VALUE]   The Destination Signed Last Address Adjustment Parameter sets the Dma Channel destination signed last address adjustment. */
    DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE        =  8U, /**< @brief [VALUE]   The Destination Transfer Size Parameter sets the Dma Channel destination transfer size. */
    DMA_IP_CH_SET_DESTINATION_MODULO               =  9U, /**< @brief [VALUE]   The Destination Modulo Parameter sets the Dma Channel destination modulo. */
    DMA_IP_CH_SET_MINORLOOP_EN_SRC_OFFSET          = 10U, /**< @brief [BOOLEAN] The Minor Loop Enable Source Offset Parameter enables the Dma Channel minor loop source offset. */
    DMA_IP_CH_SET_MINORLOOP_EN_DST_OFFSET          = 11U, /**< @brief [BOOLEAN] The Minor Loop Enable Destination Offset Parameter enables the Dma Channel minor loop destination offset. */
    DMA_IP_CH_SET_MINORLOOP_SIGNED_OFFSET          = 12U, /**< @brief [VALUE]   The Minor Loop Signed Offset Parameter sets the Dma Channel minor loop signed offset. */
    DMA_IP_CH_SET_MINORLOOP_EN_LINK                = 13U, /**< @brief [BOOLEAN] The Minor Loop Enable Link Parameter enables the Dma Channel minor loop logic channel linking. */
    DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH          = 14U, /**< @brief [VALUE]   The Minor Loop Logic Channel Link Parameter sets the Dma Channel minor loop logic channel link. */
    DMA_IP_CH_SET_MINORLOOP_SIZE                   = 15U, /**< @brief [VALUE]   The Minor Loop Size Parameter sets the Dma Channel minor loop transfer size. */
    DMA_IP_CH_SET_MAJORLOOP_EN_LINK                = 16U, /**< @brief [BOOLEAN] The Major Loop Enable Link Parameter enables the Dma Channel major loop logic channel linking. */
    DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH          = 17U, /**< @brief [VALUE]   The Major Loop Logic Channel Link Parameter sets the Dma Channel major loop logic channel link. */
    DMA_IP_CH_SET_MAJORLOOP_COUNT                  = 18U, /**< @brief [VALUE]   The Major Loop Count Parameter sets the Dma Channel major loop count. */
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
    DMA_IP_CH_SET_CONTROL_STORE_DST_ADDR           = 19U, /**< @brief [VALUE]   The Store Destination Address Parameter saves the final destination address in system memory. */
#endif
    DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST         = 20U, /**< @brief [BOOLEAN] The Enable Start Parameter enables the Dma Channel start service request. The main usage is for ScatterGather Element configuration. */
    DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT       = 21U, /**< @brief [BOOLEAN] The Enable Major Interrupt Parameter enables the Dma Channel major interrupt. */
    DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT  = 22U, /**< @brief [BOOLEAN] The Enable Half Interrupt Parameter enables the Dma Channel half major interrupt. */
    DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST         = 23U, /**< @brief [BOOLEAN] The Disable Automatic Request Parameter disables the Dma Channel automatic request. */
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
    DMA_IP_CH_SET_CONTROL_EN_END_OF_PACKET_SIGNAL  = 24U, /**< @brief [BOOLEAN] The Enable End Of Packet Signal Parameter enables the Dma Channel end of packet signal. */
#endif
    DMA_IP_CH_SET_CONTROL_BANDWIDTH                = 25U, /**< @brief [VALUE]   The Bandwidth Control Parameter sets the Dma Channel bandwidth control. */
#if (STD_ON == DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE)
    DMA_IP_CH_SET_CONTROL_TRANSFER_MODE            = 26U, /**< @brief [VALUE]   The Transfer mode Control Parameter sets the Dma Channel transfer mode control. */
#endif
}Dma_Ip_LogicChannelTransferParamType;


/**
 * @brief This type contains the Dma Ip Logic Channel Information Parameters.
 * @details The Parameters get specific information.
 *
 * */
typedef enum{
    DMA_IP_CH_GET_SOURCE_ADDRESS       = 0U, /**< @brief [VALUE]   The Source Address Parameter gets the Dma Channel source address. */
    DMA_IP_CH_GET_DESTINATION_ADDRESS  = 1U, /**< @brief [VALUE]   The Destination Address Parameter gets the Dma Channel destination address. */
    DMA_IP_CH_GET_BEGIN_ITER_COUNT     = 2U, /**< @brief [VALUE]   The Begin Iteration Count Parameter gets the Dma Channel begin iteration count. */
    DMA_IP_CH_GET_CURRENT_ITER_COUNT   = 3U, /**< @brief [VALUE]   The Current Iteration Count Parameter gets the Dma Channel current iteration count. */
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
    DMA_IP_CH_GET_STORE_DST_ADDR       = 4U, /**< @brief [VALUE]   The Store Destination Address Parameter gets the Dma Channel stored destination address. */
#endif
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
    DMA_IP_CH_GET_MASTER_ID            = 5U, /**< @brief [VALUE]   The Master Id Parameter gets the Dma Channel master id. */
#endif
    DMA_IP_CH_GET_MAJOR_INTERRUPT      = 6U, /**< @brief [BOOLEAN] The Major Interrupt Parameter gets the Dma Channel major interrupt. */
    DMA_IP_CH_GET_HALF_MAJOR_INTERRUPT = 7U, /**< @brief [BOOLEAN] The Half Major Interrupt Parameter gets the Dma Channel half major interrupt. */
#if (STD_ON == DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE)
    DMA_IP_CH_GET_TRANSACTIONS_TYPE    = 9U, /**< @brief [VALUE]   The Transactions Type Parameter gets the Dma Channel transactions type. */
#endif
#if (STD_ON == DMA_IP_SECURITY_LEVEL_IS_AVAILABLE)
    DMA_IP_CH_GET_SECURITY_LEVEL       = 10U, /**< @brief [VALUE]   The Security Level Parameter gets the Dma Channel security level. */
#endif
#if (STD_ON == DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE)
    DMA_IP_CH_GET_PROTECTION_LEVEL     = 11U, /**< @brief [VALUE]   The Protection Level Parameter gets the Dma Channel protection level. */
#endif
}Dma_Ip_LogicChannelInfoParamType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This type contains the Dma Ip Logic Channel Global List.
 * @details The Dma Ip Channel Global List contains a pair composed from Dma Channel Global Parameter
 *          Type and the Value of the parameter.
 *          The Dma Ip Channel Global Parameter Type selects a parameter form the Global Parameter
 *          enum type.
 *          The Value stores the parameter's value.
 * */
typedef struct{
    Dma_Ip_LogicChannelGlobalParamType Param;
    uint32 Value;
}Dma_Ip_LogicChannelGlobalListType;

/**
 * @brief This type contains the Dma Ip Channel Transfer List.
 * @details The Dma Ip Channel Transfer List contains a pair composed from Dma Channel Transfer
 *          Parameter Type and the Value of the parameter.
 *          The Dma Ip Channel Transfer Parameter Type selects a parameter form the Transfer Parameter
 *          enum type.
 *          The Value stores the parameter's value.
 * @implements Dma_Ip_LogicChannelTransferListType_struct
 * */
/**
 * @brief This type contains the Dma Ip Channel ScatterGather List.
 * @details The Dma Ip Channel Transfer List contains a pair composed from Dma Channel ScatterGather
 *          Parameter Type and the Value of the parameter.
 *          The Dma Ip Channel ScatterGather Parameter Type selects a parameter form the ScatterGather
 *          Parameter enum type.
 *          The Value stores the parameter's value.
 * @implements Dma_Ip_LogicChannelScatterGatherListType_struct
 * */
typedef struct{
    Dma_Ip_LogicChannelTransferParamType Param;
    uint32 Value;
}Dma_Ip_LogicChannelTransferListType, Dma_Ip_LogicChannelScatterGatherListType;


/**
 * @brief This type contains the Dma Ip Instance Status.
 * @details The Dma Ip Instance Status contains the Hardware Errors, Active Id and Active indication for
 *          the running Dma Channel.
 *          The Errors shall contain the Hardware Errors.
 *          The ActiveId shall contain the running Dma Channel Id.
 *          The Active shall contain the running Dma Channel Active status.
 * @implements Dma_Ip_LogicInstanceStatusType_struct
 * */
/* DMA Logic Instance Status */
typedef struct{
    uint32 Errors;    /**< @brief [VALUE]   The Errors value is read from the DMA Instance Error Register (ES) as it is. */
    uint8 ActiveId;   /**< @brief [VALUE]   The ActiveId value is read from the DMA Instance Control Register (CR) field ACTIVE_ID. */
    boolean Active;   /**< @brief [BOOLEAN] The Active value is read from the DMA Instance Control Register (CR) field ACTIVE. */
    uint8 Version;   /**< @brief [VALUE]   The Version value is read from the DMA Instance Control Register (CR) field VER. */
}Dma_Ip_LogicInstanceStatusType;

/**
 * @brief This type contains the Dma Ip Channel Status.
 * @details The Dma Ip Channel Status contains the Hardware Errors, Active status and Done indication for
 *          the running Dma Channel.
 *          The Channel State Value shall contain the internal driver state of the Dma Channel.
 *          The Errors shall contain the Hardware Dma Channel Errors.
 *          The Active shall contain the running Dma Channel Id.
 *          The Done shall contain the running Dma Channel Active status.
 * @implements Dma_Ip_LogicChannelStatusType_struct
 * */
/* DMA Logic Channel Status */
typedef struct{
    Dma_Ip_HwChannelStateValueType ChStateValue;
                      /**< @brief [VALUE]   The ChStateValue value is read from the internal DMA Driver Channel State Machine. Check UM for additional information.  */
    uint32 Errors;    /**< @brief [VALUE]   The Errors value is read from the DMA Channel Error Register (CHx_ES) as it is. */
    boolean Active;   /**< @brief [BOOLEAN] The Active value is read from the DMA Channel Control and Status Register (CHx_CSR) field ACTIVE. */
    boolean Done;     /**< @brief [BOOLEAN] The Active value is read from the DMA Channel Control and Status Register (CHx_CSR) field DONE. */
}Dma_Ip_LogicChannelStatusType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

const Dma_Ip_InitType * Dma_Ip_GetInitPtr(void);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/**
 * @brief This function initializes the Dma Ip Driver.
 * @details This service is a non reentrant function that shall initialize the Dma Ip driver.
 *
 * @param[in]  DmaInit           Pointer to the configuration structure.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ResetState.
 *
 * @implements Dma_Ip_Init_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_Init(const Dma_Ip_InitType * const DmaInit);

/**
 * @brief This function deinitializes the Dma Ip Driver.
 * @details This service is a non reentrant function that shall deinitialize the Dma Ip driver.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the deinitialization finished ok
 *
 * @implements Dma_Ip_Deinit_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_Deinit(void);

/**
 * @brief This function sets Dma Ip Instance Command.
 * @details This service is a reentrant function that shall command the Dma Instance.
 *          The command shall trigger specific functionalities of the Dma Instance.
 *
 * @param[in]  LogicInst         Selection value of the Logic Instance.
 * @param[in]  Command           The command for the Logic Instance.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the command finished ok.
 *
 * @implements Dma_Ip_SetLogicInstanceCommand_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_SetLogicInstanceCommand(const uint32 LogicInst, const Dma_Ip_LogicInstanceCmdType Command);

/**
 * @brief This function gets Dma Ip Instance Status.
 * @details This service is a reentrant function that shall get the Dma Instance status.
 *          The command shall read specific functionalities of the Dma Instance.
 *
 * @param[in]  LogicInst         Selection value of the Logic Instance.
 * @param[out] Status            Pointer to the Dma Instance status.
 *
 * @return Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the get status finished ok.
 *
 * @implements Dma_Ip_GetLogicInstanceStatus_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_GetLogicInstanceStatus(const uint32 LogicInst, Dma_Ip_LogicInstanceStatusType * const Status);

/**
 * @brief This function initializes the Dma Ip Logic Channel.
 * @details This service is a non reentrant function that shall initialize the Dma Ip Logic Channel.
 *
 * @param[in]  LogicCh           Selection value of the Logic Channel.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ResetState.
 *
 * @implements Dma_Ip_LogicChannelInit_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_LogicChannelInit(const uint32 LogicCh);

/**
 * @brief This function deinitializes the Dma Ip Logic Channel.
 * @details This service is a non reentrant function that shall deinitialize the Dma Ip Logic Channel.
 *
 * @param[in]  LogicCh           Selection value of the Logic Channel.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the deinitialization finished ok.
 *
 * @implements Dma_Ip_LogicChannelDeinit_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_LogicChannelDeinit(const uint32 LogicCh);

/**
 * @brief This function sets Dma Ip Logic Channel Command.
 * @details This service is a reentrant function that shall command the Dma Channel.
 *          The command shall trigger specific functionalities of the Dma Channel.
 *
 * @param[in]  LogicCh           Selection value of the Logic Channel.
 * @param[in]  Command           The command for the Logic Channel.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ReadyState.
 *
 * @implements Dma_Ip_SetLogicChannelCommand_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_SetLogicChannelCommand(const uint32 LogicCh, const Dma_Ip_LogicChannelCmdType Command);

/**
 * @brief This function gets Dma Ip Logic Channel Status.
 * @details This service is a reentrant function that shall get the Dma Channel status.
 *          The command shall read specific functionalities of the Dma Channel.
 *
 * @param[in]  LogicCh           Selection value of the Logic Channel.
 * @param[out] Status            Pointer to the Dma Channel status.
 *
 * @return Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the get status finished ok.
 *
 * @implements Dma_Ip_GetLogicChannelStatus_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_GetLogicChannelStatus(const uint32 LogicCh, Dma_Ip_LogicChannelStatusType * const ChStatus);

/**
 * @brief This function sets Dma Ip Logic Channel Global List settings.
 * @details This service is a reentrant function that shall set the Dma Ip Logic Channel
 *          global parameters list.
 *          The list is composed of an array of Dma Ip Logic Channel global parameters settings.
 *          The settings list(array) is defined by the user needs: it contains the
 *          desired parameters to be configured, in any desired order.
 *
 *          How to use this interface:
 *          1. Use the "Dma_Ip_LogicChannelGlobalListType" to create a list(array) with the desired
 *          paramaters to configure (see parameters: "Dma_Ip_LogicChannelGlobalParamType")
 *          The list can declared globally or locally:
 *          A. Global example:
 *              Dma_Ip_LogicChannelGlobalListType global_Dma_Ip_ChannelGlobalList0[NUMBER_OF_PARAMETERS] = {...};
 *          B. Local example:
 *              Dma_Ip_LogicChannelGlobalListType Dma_Ip_ChannelGlobalList[NUMBER_OF_PARAMETERS];
 *              Dma_Ip_ChannelGlobalList[PARAMETER0].Param = DMA_IP_CH_SET_EN_PREEMPTION_PRIORITY;
 *              Dma_Ip_ChannelGlobalList[PARAMETER0].Value = TRUE;
 *              Dma_Ip_ChannelGlobalList[PARAMETER1].Param = ...;
 *              Dma_Ip_ChannelGlobalList[PARAMETER1].Value = ...;
 *          2. Call the "Dma_Ip_SetLogicChannelGlobalList()" interface:
 *              Dma_Ip_SetLogicChannelGlobalList(LOGIC_CHANNELx, Dma_Ip_ChannelGlobalList, NUMBER_OF_PARAMETERS);
 *
 * @param[in]  Channel           Specifies the Logic Channel Id.
 * @param[in]  List              Pointer to the Global List Array.
 * @param[in]  ListDimension     Number of entries in the List.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ReadyState.
 *
 * @implements Dma_Ip_SetLogicChannelGlobalList_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_SetLogicChannelGlobalList(const uint32 LogicCh, const Dma_Ip_LogicChannelGlobalListType List[], const uint32 ListDimension);

/**
 * @brief This function sets Dma Ip Logic Channel Transfer List settings.
 * @details -> This service is a reentrant function that shall set the Dma Ip Logic Channel
 *          transfer parameters list.
 *          -> The "Transfer List" loads the configuration directly into the Hardware TCD and disables
 *          the ScatterGather for the Hardware TCD.
 *          -> The list is composed of an array of Dma Ip Logic Channel transfer parameters settings.
 *          -> The settings array is defined by the user needs: it contains entries for each desired
 *          parameter to be configured, in any suitable order.
 *
 *          -> How to use this interface: <-
 *          1. Use the "Dma_Ip_LogicChannelTransferListType" to create a list(array) with the desired
 *          paramaters to configure (see parameters: "Dma_Ip_LogicChannelTransferParamType")
 *          The list can declared globally or locally:
 *          Global example:
 *              #define DMA_IP_TRANSFER_LIST0_DIMENSION ((uint32)2U)
 *              Dma_Ip_LogicChannelTransferListType global_Dma_Ip_ChannelTransferList0[DMA_IP_TRANSFER_LIST0_DIMENSION] = {...};
 *          Local example:
 *              #define DMA_IP_TRANSFER_LIST0_DIMENSION ((uint32)2U)
 *              Dma_Ip_LogicChannelTransferListType Dma_Ip_ChannelTransferList0[DMA_IP_TRANSFER_LIST0_DIMENSION];
 *              Dma_Ip_ChannelTransferList0[PARAMETER0].Param = DMA_IP_CH_SET_VAL_SOURCE_ADDRESS;
 *              Dma_Ip_ChannelTransferList0[PARAMETER0].Value = &SourceBuffer;
 *              Dma_Ip_ChannelTransferList0[PARAMETER1].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
 *              Dma_Ip_ChannelTransferList0[PARAMETER1].Value = &DestinationBuffer;
 *          2. Call the "Dma_Ip_SetLogicChannelTransferList()" interface:
 *              Dma_Ip_SetLogicChannelTransferList(LOGIC_CHANNELx, Dma_Ip_ChannelTransferList0, DMA_IP_TRANSFER_LIST0_DIMENSION);
 *
 *          -> Coding Example: <-
 *              -> The user shall create the desired configuration list for his specific application.
 *              "UserDefinedFileName.h"
 *              #define DMA_IP_TRANSFER_LIST0_DIMENSION ((uint32)8U)
 *              #define DMA_IP_SET_TRANSFER_TYPE0(CHANNEL, DIMENSION, SADDR, SOFF, SSIZE, DADDR, DOFF, DSIZE, MINOR_SIZE, MAJOR_COUNT) \
 *                          Dma_Ip_LogicChannelTransferListType Dma_Ip_ChannelTransferList0[DIMENSION];                \
 *                          Dma_Ip_ChannelTransferList0[0U].Param = DMA_IP_CH_SET_VAL_SOURCE_ADDRESS;                         \
 *                          Dma_Ip_ChannelTransferList0[0U].Value = SADDR;                                             \
 *                          Dma_Ip_ChannelTransferList0[1U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;                    \
 *                          Dma_Ip_ChannelTransferList0[1U].Value = SOFF;                                              \
 *                          Dma_Ip_ChannelTransferList0[2U].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;                    \
 *                          Dma_Ip_ChannelTransferList0[2U].Value = SSIZE;                                             \
 *                          Dma_Ip_ChannelTransferList0[3U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;                    \
 *                          Dma_Ip_ChannelTransferList0[3U].Value = DADDR;                                             \
 *                          Dma_Ip_ChannelTransferList0[4U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;               \
 *                          Dma_Ip_ChannelTransferList0[4U].Value = DOFF;                                              \
 *                          Dma_Ip_ChannelTransferList0[5U].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;               \
 *                          Dma_Ip_ChannelTransferList0[5U].Value = DSIZE;                                             \
 *                          Dma_Ip_ChannelTransferList0[6U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;                         \
 *                          Dma_Ip_ChannelTransferList0[6U].Value = MINOR_SIZE;                                        \
 *                          Dma_Ip_ChannelTransferList0[7U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;                        \
 *                          Dma_Ip_ChannelTransferList0[7U].Value = MAJOR_COUNT;                                       \
 *                          Dma_Ip_SetLogicChannelTransferList(CHANNEL, Dma_Ip_ChannelTransferList0, DIMENSION);
 *
 *              "ApplicationFileName.c"
 *              void ConfigureDmaChannel(ConfigType * pxConfig)
 *              {
 *                  uint32 MinorLoopSize = 2U;
 *                  uint32 MajorLoopCount;
 *                  if(pxConfig->MajorLoopCondition == TRUE)
 *                  {
 *                      MajorLoopCount = 8U;
 *                  }
 *                  else
 *                  {
 *                      MajorLoopCount = 24U;
 *                  }
 *                  DMA_IP_SET_TRANSFER_TYPE0(pxConfig->LogicChannel,
 *                                            DMA_IP_TRANSFER_LIST0_DIMENSION,
 *                                            pxConfig->SourceBuffer,
 *                                            2U,
 *                                            DMA_IP_TRANSFER_SIZE_2_BYTE,
 *                                            &RegisterAddress,
 *                                            0U,
 *                                            DMA_IP_TRANSFER_SIZE_2_BYTE,
 *                                            MinorLoopSize,
 *                                            MajorLoopCount);
 *              }
 *
 * @param[in]  Channel           Specifies the Logic Channel Id.
 * @param[in]  List              Pointer to the Transfer List Array.
 * @param[in]  ListDimension     Number of entries in the List.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ReadyState.
 *
 * @implements Dma_Ip_SetLogicChannelTransferList_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_SetLogicChannelTransferList(const uint32 LogicCh, const Dma_Ip_LogicChannelTransferListType List[], const uint32 ListDimension);

/**
 * @brief This function sets Dma Ip Logic Channel Scatter/Gather List settings.
 * @details -> This service is a reentrant function that shall set the Dma Ip Logic Channel
 *          scatter/gather parameters list.
 *          -> The "Scatter/Gather List" configures Logic Elements belonging to the same
 *          Dma Logic Channel.
 *          -> The "Scatter/Gather List" loads the configuration into the Software TCD.
 *          The Software TCD has the Scatter/Gather Enable set (ESG bit) and the Next Software
 *          TCD Address already loaded during the configuration generation process.
 *          -> The "Scatter/Gather List" shall not be able to modify the Scatter/Gather Element
 *          linkage (reorder of elements in the chain). The linkage of the elements is set only
 *          during the configuration process.
 *          -> The settings array is defined by the user needs: it contains entries for
 *          each desired parameter to be configured, in any suitable order.
 *          -> This service does not load the Logic Element into the Hardware TCD. This functionality
 *          is covered by Dma_Ip_SetLogicChannelScatterGatherConfig.
 *
 *          How to use this interface:
 *          1. Use the "Dma_Ip_LogicChannelScatterGatherListType" to create a list(array) with the desired
 *          paramaters to configure (see parameters: "Dma_Ip_LogicChannelTransferParamType")
 *          The list can declared globally or locally:
 *          Global example:
 *              Dma_Ip_LogicChannelScatterGatherListType global_Dma_Ip_ChannelScatterGatherList0[NUMBER_OF_PARAMETERS] = {...};
 *          Local example:
 *              Dma_Ip_LogicChannelScatterGatherListType Dma_Ip_ChannelScatterGatherList[NUMBER_OF_PARAMETERS];
 *              Dma_Ip_ChannelScatterGatherList[PARAMETER0].Param = DMA_IP_CH_SET_VAL_SOURCE_ADDRESS;
 *              Dma_Ip_ChannelScatterGatherList[PARAMETER0].Value = &SourceBuffer;
 *              Dma_Ip_ChannelScatterGatherList[PARAMETER1].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
 *              Dma_Ip_ChannelScatterGatherList[PARAMETER1].Value = &DestinationBuffer;
 *          2. Call the "Dma_Ip_SetLogicChannelScatterGatherList()" interface:
 *              Dma_Ip_SetLogicChannelScatterGatherList(LOGIC_CHANNELx, LOGIC_ELEMENTy, Dma_Ip_ChannelScatterGatherList, NUMBER_OF_PARAMETERS);
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ReadyState.
 *
 * @implements Dma_Ip_SetLogicChannelScatterGatherList_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_SetLogicChannelScatterGatherList(const uint32 LogicCh, const uint32 Element, const Dma_Ip_LogicChannelScatterGatherListType List[], const uint32 ListDimension);


/**
 * @brief This function gets the Dma Ip Logic Channel Parameter value.
 * @details This service is a reentrant function that shall get the Dma Channel
 *          parameters value.
 *
 * @param[in]  LogicCh           Selection value of the Logic Channel.
 * @param[in]  Param             Selection parameter.
 * @param[out] Value             Pointer to the parameter value.
 *
 * @return Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the get information finished ok.
 *
 * @implements Dma_Ip_GetLogicChannelParam_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_GetLogicChannelParam(const uint32 LogicCh, const Dma_Ip_LogicChannelInfoParamType Param, uint32 * const Value);

/**
 * @brief This function configures the Dma Ip Logic Channel Scatter/Gather.
 * @details This service is a reentrant function that shall configure the Dma Channel
 *          scatter/gather functionality.
 *          The specified Logic Element (corresponding to a Software TCD) shall be loaded
 *          into the Dma Logic Channel's Hardware TCD.
 *          The Logic Elements (describing the Software TCDs) form a simple chained list
 *          and the "Element" parameter represents the lists's head.
 *
 * @param[in]  LogicCh           Selection value of the Logic Channel.
 * @param[in]  Element           Selection value of the Logic Element representing the
 *                               list's head.
 *
 * @return     Dma_Ip_ReturnType DMA_IP_STATUS_SUCCESS is returned if the initialization finished ok.
 *                               DMA_IP_STATUS_WRONG_STATE is returned if the Dma Ip Channel state is
 *                               not Dma_Ip_Ch_ReadyState.
 *                               DMA_IP_STATUS_ERROR is returned if the Dma Ip Channel contains an error.
 *
 * @implements Dma_Ip_SetLogicChannelScatterGatherConfig_Activity
 * */
Dma_Ip_ReturnType Dma_Ip_SetLogicChannelScatterGatherConfig(const uint32 LogicCh, const uint32 Element);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef DMA_IP_DRIVER_H_ */

