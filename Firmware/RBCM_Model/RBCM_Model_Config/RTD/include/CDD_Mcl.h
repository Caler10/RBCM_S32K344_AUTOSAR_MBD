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

#ifndef CDD_MCL_H_
#define CDD_MCL_H_

/**
*   @file    CDD_Mcl.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details
*
*   @addtogroup MCL_DRIVER MCL Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"
#include "CDD_Mcl_Ipw.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCL_MODULE_ID                       255
#define CDD_MCL_VENDOR_ID                       43
#define CDD_MCL_AR_RELEASE_MAJOR_VERSION        4
#define CDD_MCL_AR_RELEASE_MINOR_VERSION        7
#define CDD_MCL_AR_RELEASE_REVISION_VERSION     0
#define CDD_MCL_SW_MAJOR_VERSION                5
#define CDD_MCL_SW_MINOR_VERSION                0
#define CDD_MCL_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and CDD_Mcl_Cfg.h file are of the same vendor */
#if (CDD_MCL_VENDOR_ID != CDD_MCL_CFG_VENDOR_ID)
    #error "CDD_Mcl.h and CDD_Mcl_Cfg.h have different vendor ids"
#endif

/* Check if header file and CDD_Mcl_Cfg.h file are of the same Autosar version */
#if ((CDD_MCL_AR_RELEASE_MAJOR_VERSION != CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_AR_RELEASE_MINOR_VERSION != CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_AR_RELEASE_REVISION_VERSION != CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl.h and CDD_Mcl_Cfg.h are different"
#endif

/* Check if header file and CDD_Mcl_Cfg.h file are of the same Software version */
#if ((CDD_MCL_SW_MAJOR_VERSION != CDD_MCL_CFG_SW_MAJOR_VERSION) || \
     (CDD_MCL_SW_MINOR_VERSION != CDD_MCL_CFG_SW_MINOR_VERSION) || \
     (CDD_MCL_SW_PATCH_VERSION != CDD_MCL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl.h and CDD_Mcl_Cfg.h are different"
#endif

/* Check if header file and CDD_Mcl_Ipw.h file are of the same vendor */
#if (CDD_MCL_VENDOR_ID != CDD_MCL_IPW_VENDOR_ID)
    #error "CDD_Mcl.h and CDD_Mcl_Ipw.h have different vendor ids"
#endif

/* Check if header file and CDD_Mcl_Ipw.h file are of the same Autosar version */
#if ((CDD_MCL_AR_RELEASE_MAJOR_VERSION != CDD_MCL_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_AR_RELEASE_MINOR_VERSION != CDD_MCL_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_AR_RELEASE_REVISION_VERSION != CDD_MCL_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl.h and CDD_Mcl_Ipw.h are different"
#endif

/* Check if header file and CDD_Mcl_Ipw.h file are of the same Software version */
#if ((CDD_MCL_SW_MAJOR_VERSION != CDD_MCL_IPW_SW_MAJOR_VERSION) || \
     (CDD_MCL_SW_MINOR_VERSION != CDD_MCL_IPW_SW_MINOR_VERSION) || \
     (CDD_MCL_SW_PATCH_VERSION != CDD_MCL_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl.h and CDD_Mcl_Ipw.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)
extern Mcl_EmiosInitConfigType * Mcl_pxEmiosCommonConfig;

extern uint8 Mcl_au8EmiosLogicToHwInstance[eMIOS_INSTANCE_COUNT];
#endif /* EMIOS_IS_AVAILABLE */

#if (STD_ON == MCL_FLEXIO_IS_AVAILABLE)
extern uint8 Mcl_au8FlexioLogicToHwInstance[FLEXIO_INSTANCE_COUNT];
#endif /* FLEXIO_IS_AVAILABLE */

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/* DET APIs */
/**
* @brief API service ID for Mcl_Init function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_INIT                                 ((uint8)0x00U)

#if (STD_ON == MCL_DMA_IS_AVAILABLE)

/**
* @brief API service ID for Mcl_SetDmaInstanceCommand function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_INSTANCE_COMMAND                 ((uint8)0x01U)

/**
* @brief API service ID for Mcl_GetDmaInstanceStatus function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_INSTANCE_STATUS                  ((uint8)0x02U)

/**
* @brief API service ID for Mcl_SetDmaChannelCommand function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_CHANNEL_COMMAND                  ((uint8)0x03U)

/**
* @brief API service ID for Mcl_GetDmaChannelStatus function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_CHANNEL_STATUS                   ((uint8)0x04U)

/**
* @brief API service ID for Mcl_SetDmaChannelGlobalList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_GLOBAL                           ((uint8)0x05U)

/**
* @brief API service ID for Mcl_SetDmaChannelTransferList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_TRANSFER                         ((uint8)0x06U)

/**
* @brief API service ID for Mcl_SetDmaChannelScatterGatherList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_SCATTER_GATHER_LIST              ((uint8)0x07U)

/**
* @brief API service ID for Mcl_GetDmaChannelParam function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_INFORMATION                      ((uint8)0x08U)

/**
* @brief API service ID for Mcl_SetDmaChannelScatterGatherConfig function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DMA_SCATTER_GATHER_CONFIG            ((uint8)0x09U)



#endif /* (STD_ON == MCL_DMA_IS_AVAILABLE) */

/**
* @brief API service ID for Mcl_DeInit function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_DEINIT                               ((uint8)0x0BU)

#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
/**
* @brief API service ID for Mcl_CacheEnable function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_CACHE_ENABLE                         ((uint8)0x10U)

/**
* @brief API service ID for Mcl_CacheDisable function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_CACHE_DISABLE                        ((uint8)0x11U)

/**
* @brief API service ID for Mcl_CacheInvalidate function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_CACHE_INVALIDATE                     ((uint8)0x12U)

/**
* @brief API service ID for Mcl_CacheClean function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_CACHE_CLEAN                          ((uint8)0x13U)

/**
* @brief API service ID for Mcl_CacheInvalidateByAddr function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_CACHE_INVALIDATE_BY_ADDRESS          ((uint8)0x14U)

/**
* @brief API service ID for Mcl_CacheCleanByAddr function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_CACHE_CLEAN_BY_ADDRESS               ((uint8)0x15U)
#endif /* if (STD_ON == MCL_CACHE_IS_AVAILABLE) */


#if (STD_ON == MCL_TRGMUX_IS_AVAILABLE)

/**
* @brief API service ID for Mcl_SetTrgMuxInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_TRGMUX_INPUT                         ((uint8)0x20U)

/**
* @brief API service ID for Mcl_SetTrgMuxLock function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_TRGMUX_LOCK                          ((uint8)0x21U)

#endif /* MCL_TRGMUX_IS_AVAILABLE */


#if (STD_ON == MCL_LCU_IS_AVAILABLE)

#if (STD_ON == MCL_LCU_ASYNC_FUNC_IS_AVAILABLE)
/**
* @brief API service ID for Mcl_SetLcuAsyncInputList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_ASYNC_SET_INPUT                  ((uint8)0x47U)

/**
* @brief API service ID for Mcl_SetLcuAsyncOutputList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_ASYNC_SET_OUTPUT                 ((uint8)0x48U)

#endif /* #if (STD_ON == MCL_LCU_ASYNC_FUNC_IS_AVAILABLE) */


#if (STD_ON == MCL_LCU_SYNC_FUNC_IS_AVAILABLE)
/**
* @brief API service ID for Mcl_SetLcuSyncInputSwOverrideEnable function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_INPUT_SW_OVERRIDE_EN     ((uint8)0x30U)

/**
* @brief API service ID for Mcl_SetLcuSyncInputSwOverrideValue function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_INPUT_SW_OVERRIDE_VALUE  ((uint8)0x31U)

/**
* @brief API service ID for Mcl_SetLcuSyncInputMuxSelect function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_INPUT_MUX_SEL            ((uint8)0x32U)

/**
* @brief API service ID for Mcl_SetLcuSyncInputSwSyncMode function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_INPUT_SW_SYNC_MODE       ((uint8)0x33U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputDebugMode function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_DEBUG_MODE_EN     ((uint8)0x34U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputEnable function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_ENABLE            ((uint8)0x35U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputForceInputSensitivity function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_FORCE_SENSITIVITY ((uint8)0x36U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputForceClearingMode function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_FORCE_CLEAR_MODE  ((uint8)0x37U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputForceSyncSelect function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_FORCE_SYNC_SEL    ((uint8)0x38U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputPolarity function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_POLARITY          ((uint8)0x39U)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputForceDma function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_FORCE_DMA         ((uint8)0x3AU)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputForceInt function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_FORCE_INT         ((uint8)0x3CU)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputLutDma function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_LUT_DMA           ((uint8)0x3BU)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputLutInt function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_LUT_INT           ((uint8)0x3DU)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputFallFilter function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_FALL_FILTER       ((uint8)0x3EU)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputRiseFilter function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_RISE_FILTER       ((uint8)0x3FU)

/**
* @brief API service ID for Mcl_SetLcuSyncOutputLutControl function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_SET_OUTPUT_LUT_CONTROL       ((uint8)0x40U)

/**
* @brief API service ID for Mcl_ClearLcuSyncOutputForceEvent function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_CLEAR_OUTPUT_FORCE_EVENT     ((uint8)0x49U)

/**
* @brief API service ID for Mcl_GetLcuSyncLogicInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_GET_LOGIC_INPUT              ((uint8)0x41U)

/**
* @brief API service ID for Mcl_GetLcuSyncSwOverrideInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_GET_SW_OVERRIDE_INPUT        ((uint8)0x42U)

/**
* @brief API service ID for Mcl_GetLcuSyncLogicOutput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_GET_LOGIC_OUTPUT             ((uint8)0x43U)

/**
* @brief API service ID for Mcl_GetLcuSyncForceOutput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_GET_FORCE_OUTPUT             ((uint8)0x44U)

/**
* @brief API service ID for Mcl_GetLcuSyncForceStatus function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_GET_FORCE_STATUS             ((uint8)0x45U)

/**
* @brief API service ID for Mcl_GetLcuSyncCombineForceInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SYNC_GET_COMBINE_FORCE_INPUT      ((uint8)0x46U)

#endif /* #if (STD_ON == MCL_LCU_SYNC_FUNC_IS_AVAILABLE) */

/**
* @brief API service ID for Mcl_GetLcuSyncCombineForceInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_SET_WRITE_PROTECT                 ((uint8)0x4CU)

#if (STD_ON == MCL_LCU_ASYNC_FUNC_IS_AVAILABLE)
/**
* @brief API service ID for Mcl_SetLcuAsyncInputList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_ASYNC_GET_INPUT_INFO              ((uint8)0x4AU)
/**
* @brief API service ID for Mcl_SetLcuAsyncOutputList function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_LCU_ASYNC_GET_OUTPUT_INFO             ((uint8)0x4BU)

#endif /* #if (STD_ON == MCL_LCU_ASYNC_FUNC_IS_AVAILABLE) */


#endif /* #if (STD_ON == MCL_LCU_IS_AVAILABLE) */

#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)

/** @brief All API's called with wrong logic channel shall return this error. */
#define MCL_DET_EMIOS_E_INVALID_CHANNEL               ((uint8)0x50)

/** @brief All API's called with wrong logic channel shall return this error. */
#define MCL_DET_EMIOS_E_INVALID_SET                   ((uint8)0x51)

#endif /* STD_ON == MCL_EMIOS_IS_AVAILABLE */

#if (STD_ON == MCL_TRGMUX_IS_AVAILABLE)

/**
* @brief API service ID for Mcl_SetTrgMuxInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_TRGMUX_SET_INPUT                       ((uint8)0x52)

/**
* @brief API service ID for Mcl_SetTrgMuxLock function
* @details Parameters used when raising an error/exception
* */
#define MCL_DET_TRGMUX_SET_LOC                         ((uint8)0x53)

#endif /* STD_ON == MCL_TRGMUX_IS_AVAILABLE */



/* DET ERRORS */
/**
* @brief   All API's having pointers as parameters shall return this error if
*          called with with a NULL value
* @implements MCL_E_UNINIT_define
* */
#define MCL_E_UNINIT                         ((uint8)0x00)

/**
* @brief   All API's having pointers as parameters shall return this error if
*          called with with a NULL value
* @implements MCL_E_PARAM_POINTER_define
* */
#define MCL_E_PARAM_POINTER                  ((uint8)0x01)

/**
* @brief   All API's called with wrong instance shall return this error
* @implements MCL_E_INVALID_INSTANCE_define
* */
#define MCL_E_INVALID_INSTANCE               ((uint8)0x02)

/**
* @brief   All API's called with wrong channel shall return this error
* @implements MCL_E_INVALID_CHANNEL_define
* */
#define MCL_E_INVALID_CHANNEL                ((uint8)0x03)

/**
* @brief   All API's called with wrong instance shall return this error
* @implements MCL_E_INVALID_COMMAND_define
* */
#define MCL_E_INVALID_COMMAND                ((uint8)0x04)

/**
* @brief   All API's called with wrong read parameter shall return this error
* @implements MCL_E_INVALID_PARAMETER_define
* */
#define MCL_E_INVALID_PARAMETER              ((uint8)0x05)

/**
* @brief   All API's called in wrong sequence shall return this error
* @implements MCL_E_INVALID_STATE_define
* */
#define MCL_E_INVALID_STATE                  ((uint8)0x06)

/**
* @brief   All API's called while hardware has error status shall return this error
* @implements MCL_E_INCONSISTENCY_define
* */
#define MCL_E_INCONSISTENCY                  ((uint8)0x07)

/**
* @brief   All API's called with a timeout value shall return this error if execution
*          is not finished in the allocated timeframe
*
* */
#define MCL_E_TIMEOUT                        ((uint8)0x08)

/**
* @brief   If DET error reporting is enabled, the MCL will check upon each API call
*          if the requested resource is configured to be available on the current core,
*          and in case of error will return MCL_E_PARAM_CONFIG.
* @implements MCL_E_PARAM_CONFIG_define
* */
#define MCL_E_PARAM_CONFIG                   ((uint8)0x09)

/**
* @brief   If DET error reporting is enabled, the MCL will check if registers are protected
* */
#define MCL_E_PROTECTED                      ((uint8)0x0A)

/**
* @brief   If VariantPreCompile is used, the configuration pointer shall have a NULL_PTR value.
*          If VariantPostBuild is used, the configuration pointer shall be different from NULL_PTR.
*          And in case of violate will return MCL_E_INIT_FAILED.
* */
#define MCL_E_INIT_FAILED                    ((uint8)0x0B)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if (STD_ON == MCL_DMA_IS_AVAILABLE)
/**
 * @brief This type contains the Mcl Dma Instance Commands.
 * @details The Commands trigger specific actions in the Dma Instance.
 *
 * @implements Mcl_DmaInstanceCmdType_enum
 * */
typedef enum{
    MCL_DMA_INST_STOP       = 0U, /**< @brief The Stop Command stops the executing channel and forces the Minor Loop to finish. */
    MCL_DMA_INST_STOP_ERROR = 1U, /**< @brief The StopError Command stops the executing channel, forces the Minor Loop to finish and generates an error interrupt. */
    MCL_DMA_INST_PAUSE      = 2U, /**< @brief The Pause Command allows the ongoing transfer to finish and pauses any new transfer. */
    MCL_DMA_INST_RESUME     = 3U, /**< @brief The Resume Command allows the transfer to continue. */
}Mcl_DmaInstanceCmdType;

/**
 * @brief This type contains the Mcl Dma Channel Commands.
 * @details The Commands trigger specific actions in the Dma Channel.
 *
 * @implements Mcl_DmaChannelCmdType_enum
 * */
typedef enum{
    MCL_DMA_CH_START_REQUEST           = 0U, /**< @brief The Start Request Command enables the Dma Channel to be triggered by hardware requests. */
    MCL_DMA_CH_STOP_REQUEST            = 1U, /**< @brief The Stop Request Command disables the Dma Channel to be triggered by hardware requests. */
    MCL_DMA_CH_START_SERVICE           = 2U, /**< @brief The Start Service Command sends a start request to the Dma Channel. */
    MCL_DMA_CH_ACK_DONE                = 3U, /**< @brief The Ack Done Command resets the Dma Channel Done status. */
    MCL_DMA_CH_ACK_ERROR               = 4U, /**< @brief The Ack Error Command resets the Dma Channel Error status. */
    MCL_DMA_CH_ACK_INTERRUPT_STATUS    = 5U, /**< @brief The Ack Done Command resets the Dma Channel Done status. */
}Mcl_DmaChannelCmdType;

/**
 * @brief This type contains the Mcl Dma Channel Global Parameters.
 * @details The Parameters set specific functionalities.
 *
 * @implements Mcl_DmaChannelGlobalParamType_enum
 * */
typedef enum{
#if (STD_ON == MCL_DMA_MASTER_ID_REPLICATION_IS_AVAILABLE)
    MCL_DMA_CH_SET_EN_MASTER_ID_REPLICATION =  0U, /**< @brief [BOOLEAN] The EnMasterIdReplication Parameter sets the Dma Channel to use the same protection level and system bus ID of the master programming the Dma Channel. */
#endif
#if (STD_ON == MCL_DMA_BUFFERED_WRITES_IS_AVAILABLE)
    MCL_DMA_CH_SET_EN_BUFFERED_WRITES       =  1U, /**< @brief [BOOLEAN] The EnBufferedWrites Parameter sets the Dma Channel writes to be bufferable. */
#endif
    MCL_DMA_CH_SET_EN_HARDWARE_REQ          =  2U, /**< @brief [BOOLEAN] The EnRequest Parameter enables the Dma Channel Request. */
    MCL_DMA_CH_SET_EN_ERROR_INTERRUPT       =  3U, /**< @brief [BOOLEAN] The EnError Parameter enables the Dma Channel Error Interrupt. */
    MCL_DMA_CH_SET_GROUP_PRIORITY           =  4U, /**< @brief [VALUE]   The Group Parameter sets the Dma Channel Group Priority. */
    MCL_DMA_CH_SET_LEVEL_PRIORITY           =  5U, /**< @brief [VALUE]   The Level Parameter sets the Dma Channel Level Priority. */
#if (STD_ON == MCL_DMA_PREEMPTION_IS_AVAILABLE)
    MCL_DMA_CH_SET_EN_PREEMPTION_PRIORITY   =  6U, /**< @brief [BOOLEAN] The EnPreemption Parameter enables the Dma Channel Preemption. */
#endif
#if (STD_ON == MCL_DMA_DISABLE_PREEMPT_IS_AVAILABLE)
    MCL_DMA_CH_SET_DIS_PREEMPT_PRIORITY     = 7U, /**< @brief [BOOLEAN] The DisPreempt Parameter disables the Dma Channel Preempt. */
#endif
}Mcl_DmaChannelGlobalParamType;

/**
 * @brief This type contains the Mcl Dma Channel Transfer Parameters.
 * @details The Parameters set specific functionalities.
 *
 * @implements Mcl_DmaChannelTransferParamType_enum
 * */
typedef enum{
    MCL_DMA_CH_SET_SOURCE_ADDRESS                        =  0U, /**< @brief [VALUE]   The Source Address Parameter sets the Dma Channel source address value. */
    MCL_DMA_CH_SET_SOURCE_SIGNED_OFFSET                  =  1U, /**< @brief [VALUE]   The Source Signed Offset Parameter sets the Dma Channel source signed offset value. */
    MCL_DMA_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ           =  2U, /**< @brief [VALUE]   The Source Signed Last Address Adjustment Parameter sets the Dma Channel source signed last address adjustment. */
    MCL_DMA_CH_SET_SOURCE_TRANSFER_SIZE                  =  3U, /**< @brief [VALUE]   The Source Transfer Size Parameter sets the Dma Channel source transfer size. */
    MCL_DMA_CH_SET_SOURCE_MODULO                         =  4U, /**< @brief [VALUE]   The Source Modulo Parameter sets the Dma Channel source modulo. */
    MCL_DMA_CH_SET_DESTINATION_ADDRESS                   =  5U, /**< @brief [VALUE]   The Destination Address Parameter sets the Dma Channel destination address value. */
    MCL_DMA_CH_SET_DESTINATION_SIGNED_OFFSET             =  6U, /**< @brief [VALUE]   The Destination Signed Offset Parameter sets the Dma Channel destination signed offset value. */
    MCL_DMA_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ      =  7U, /**< @brief [VALUE]   The Destination Signed Last Address Adjustment Parameter sets the Dma Channel destination signed last address adjustment. */
    MCL_DMA_CH_SET_DESTINATION_TRANSFER_SIZE             =  8U, /**< @brief [VALUE]   The Destination Transfer Size Parameter sets the Dma Channel destination transfer size. */
    MCL_DMA_CH_SET_DESTINATION_MODULO                    =  9U, /**< @brief [VALUE]   The Destination Modulo Parameter sets the Dma Channel destination modulo. */
    MCL_DMA_CH_SET_MINORLOOP_EN_SRC_OFFSET               = 10U, /**< @brief [BOOLEAN] The Minor Loop Enable Source Offset Parameter enables the Dma Channel minor loop source offset. */
    MCL_DMA_CH_SET_MINORLOOP_EN_DST_OFFSET               = 11U, /**< @brief [BOOLEAN] The Minor Loop Enable Destination Offset Parameter enables the Dma Channel minor loop destination offset. */
    MCL_DMA_CH_SET_MINORLOOP_SIGNED_OFFSET               = 12U, /**< @brief [VALUE]   The Minor Loop Signed Offset Parameter sets the Dma Channel minor loop signed offset. */
    MCL_DMA_CH_SET_MINORLOOP_EN_LINK                     = 13U, /**< @brief [BOOLEAN] The Minor Loop Enable Link Parameter enables the Dma Channel minor loop logic channel linking. */
    MCL_DMA_CH_SET_MINORLOOP_LOGIC_LINK_CH               = 14U, /**< @brief [VALUE]   The Minor Loop Logic Channel Link Parameter sets the Dma Channel minor loop logic channel link. */
    MCL_DMA_CH_SET_MINORLOOP_SIZE                        = 15U, /**< @brief [VALUE]   The Minor Loop Size Parameter sets the Dma Channel minor loop transfer size. */
    MCL_DMA_CH_SET_MAJORLOOP_EN_LINK                     = 16U, /**< @brief [BOOLEAN] The Major Loop Enable Link Parameter enables the Dma Channel major loop logic channel linking. */
    MCL_DMA_CH_SET_MAJORLOOP_LOGIC_LINK_CH               = 17U, /**< @brief [VALUE]   The Major Loop Logic Channel Link Parameter sets the Dma Channel major loop logic channel link. */
    MCL_DMA_CH_SET_MAJORLOOP_COUNT                       = 18U, /**< @brief [VALUE]   The Major Loop Count Parameter sets the Dma Channel major loop count. */
#if (STD_ON == MCL_DMA_STORE_DST_ADDR_IS_AVAILABLE)
    MCL_DMA_CH_SET_CONTROL_STORE_DST_ADDR                = 19U, /**< @brief [VALUE]   The Store Destination Address Parameter saves the final destination address in system memory. */
#endif
    MCL_DMA_CH_SET_CONTROL_SOFTWARE_REQUEST              = 20U, /**< @brief [BOOLEAN] The Enable Start Parameter enables the Dma Channel start service request. */
    MCL_DMA_CH_SET_CONTROL_EN_MAJOR_INTERRUPT            = 21U, /**< @brief [BOOLEAN] The Enable Major Interrupt Parameter enables the Dma Channel major interrupt. */
    MCL_DMA_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT       = 22U, /**< @brief [BOOLEAN] The Enable Half Interrupt Parameter enables the Dma Channel half major interrupt. */
    MCL_DMA_CH_SET_CONTROL_DIS_AUTO_REQUEST              = 23U, /**< @brief [BOOLEAN] The Disable Automatic Request Parameter disables the Dma Channel automatic request. */
#if (STD_ON == MCL_DMA_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
    MCL_DMA_CH_SET_CONTROL_EN_END_OF_PACKET_SIGNAL       = 24U, /**< @brief [BOOLEAN] The Enable End Of Packet Signal Parameter enables the Dma Channel end of packet signal. */
#endif
#if (STD_ON == MCL_DMA_BANDWIDTH_CONTROL_IS_AVAILABLE)
    MCL_DMA_CH_SET_CONTROL_BANDWIDTH                     = 25U, /**< @brief [VALUE]   The Bandwidth Control Parameter sets the Dma Channel bandwidth control. */
#endif
}Mcl_DmaChannelTransferParamType;

/**
 * @brief This type contains the Mcl Dma Channel State values.
 * @details The states represent the Channel status during runtime.
 *
 * @implements Mcl_DmaChannelStateType_enum
 * */
typedef enum{
    MCL_DMA_CH_RESET_STATE         = 0U,
    MCL_DMA_CH_READY_STATE         = 1U,
    MCL_DMA_CH_TRANSFER_STATE      = 2U,
    MCL_DMA_CH_SCATTERGATHER_STATE = 3U,
    MCL_DMA_CH_ERROR_STATE         = 4U,
}Mcl_DmaChannelStateType;


/**
 * @brief This type contains the Mcl Dma Channel Information Parameters.
 * @details The Parameters get specific information.
 *
 * @implements Mcl_DmaChannelInfoParamType_enum
 * */
typedef enum{
    MCL_DMA_CH_GET_SOURCE_ADDRESS       = 0U, /**< @brief [VALUE]   The Source Address Parameter gets the Dma Channel source address. */
    MCL_DMA_CH_GET_DESTINATION_ADDRESS  = 1U, /**< @brief [VALUE]   The Destination Address Parameter gets the Dma Channel destination address. */
    MCL_DMA_CH_GET_BEGIN_ITER_COUNT     = 2U, /**< @brief [VALUE]   The Begin Iteration Count Parameter gets the Dma Channel begin iteration count. */
    MCL_DMA_CH_GET_CURRENT_ITER_COUNT   = 3U, /**< @brief [VALUE]   The Current Iteration Count Parameter gets the Dma Channel current iteration count. */
#if (STD_ON == MCL_DMA_STORE_DST_ADDR_IS_AVAILABLE)
    MCL_DMA_CH_GET_STORE_DST_ADDR       = 4U, /**< @brief [VALUE]   The Store Destination Address Parameter gets the Dma Channel stored destination address. */
#endif
#if (STD_ON == MCL_DMA_MASTER_ID_REPLICATION_IS_AVAILABLE)
    MCL_DMA_CH_GET_MASTER_ID            = 5U, /**< @brief [VALUE]   The Master Id Parameter gets the Dma Channel master id. */
#endif
    MCL_DMA_CH_GET_MAJOR_INTERRUPT      = 6U, /**< @brief [BOOLEAN] The Major Interrupt Parameter gets the Dma Channel major interrupt. */
    MCL_DMA_CH_GET_HALF_MAJOR_INTERRUPT = 7U, /**< @brief [BOOLEAN] The Half Major Interrupt Parameter gets the Dma Channel half major interrupt. */
}Mcl_DmaChannelInfoParamType;
#endif /* #if (STD_ON == MCL_DMA_IS_AVAILABLE) */

#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
/**
 * @brief This type contains the Mcl Cache Type selection.
 * @details The Cache Types select specific cache memory types.
 *
 * @implements Mcl_CacheType_enum
 * */
typedef enum{
    MCL_CACHE_LMEM         = 0U, /**< @brief The Cache Lmem Parameter selects LMEM cache types. */
    MCL_CACHE_CORE         = 1U, /**< @brief The Cache Core Parameter selects CORE cache types. */
}Mcl_CacheType;

/**
 * @brief This type contains the Mcl Cache Bus Type selection.
 * @details The Cache Bus Types select Code and System caches and bus.
 *
 * @implements Mcl_CacheBusType_enum
 * */
typedef enum{
    MCL_CACHE_PC_BUS         = 0U, /**< @brief The Cache PC Bus selects Processor Code (PC) bus (used with Cache Lmem). */
    MCL_CACHE_PS_BUS         = 1U, /**< @brief The Cache PS Bus selects Processor System (PS) bus (used with Cache Lmem). */
    MCL_CACHE_ALL_BUS        = 2U, /**< @brief The Cache All Bus selects PC and PS bus (used with Cache Lmem). */
    MCL_CACHE_INSTRUCTION    = 3U, /**< @brief The Cache Instruction Parameter selects instruction cache (used with Cache Core). */
    MCL_CACHE_DATA           = 4U, /**< @brief The Cache Data Parameter selects data cache (used with Cache Core). */
}Mcl_CacheBusType;
#endif /* #if (STD_ON == MCL_CACHE_IS_AVAILABLE) */

#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)
/**
 * @brief This type contains the Mcl Emios Prescaler Type selection.
 * @details The EmiosSelectPrescaler Types select specific Emios prescaler.
 *
 * @implements Mcl_EmiosSelectPrescalerType_enum
 * */
typedef enum{
    MCL_EMIOS_PRESCALER                = 0U, /**< @brief The Mcl Emios selects presacler. */
    MCL_EMIOS_ALTERNATIVE_PRESCALER    = 1U, /**< @brief The Mcl Emios selects alternative presacler. */
}Mcl_EmiosSelectPrescalerType;

#endif /* #if (STD_ON == MCL_EMIOS_IS_AVAILABLE) */

#if (STD_ON == MCL_LCU_IS_AVAILABLE)

/**
 * @brief This type contains the LCU Input Param Type.
 * @details The Parameters set specific functionalities for Input
 *
 * @implements Mcl_LcuInputParamType_enum
 * */
typedef enum
{
    MCL_LCU_IP_INPUT_SET_MUX_SEL                   = 0U,    /**< @brief [MUXSEL] Input MUX Select. */
    MCL_LCU_IP_INPUT_SET_SW_SYNC_MODE              = 1U,    /**< @brief [SW_MODE] Specifies the software sync mode for the inputs to this LC.When Software Override is enabled (SWEN),these bits control whether Software Override Value (SWVALUE) changes occur immediately or on the rising edge of the selected sync pulse */
    MCL_LCU_IP_INPUT_SET_SW_OVERRIDE_EN            = 2U,    /**< @brief [SWEN] Software override input enable */
    MCL_LCU_IP_INPUT_SET_SW_VALUE                  = 3U     /**< @brief [SWVALUE] Software override input value */
}Mcl_LcuInputParamType;

/**
 * @brief This type contains the LCU Output Param Type.
 * @details The Parameters set specific functionalities for Output
 *
 * @implements Mcl_LcuOutputParamType_enum
 * */
typedef enum
{
    MCL_LCU_IP_OUTPUT_SET_EN_DEBUG_MODE            =  0U,   /**< @brief [DBGEN] Enables outputs to continue operation in Debug mode */
    MCL_LCU_IP_OUTPUT_SET_OUTPUT_ENABLE            =  1U,   /**< @brief [OUTEN] Enables LC outputs */
    MCL_LCU_IP_OUTPUT_SET_LUT_CONTROL              =  2U,   /**< @brief [LUTCTRL] LUT control */
    MCL_LCU_IP_OUTPUT_SET_LUT_RISE_FILTER          =  3U,   /**< @brief [LUT_RISE_FILT] LUT Rise Filter */
    MCL_LCU_IP_OUTPUT_SET_LUT_FALL_FILTER          =  4U,   /**< @brief [LUT_FALL_FILT] LUT Fall Filter */
    MCL_LCU_IP_OUTPUT_SET_EN_FORCE_DMA             =  5U,   /**< @brief [LUT_DMA_EN] Enables the generation of a DMA request when an LUT event occurs */
    MCL_LCU_IP_OUTPUT_SET_EN_LUT_DMA               =  6U,   /**< @brief [FORCE_DMA_EN] Enables the generation of a DMA request when a force event occurs */
    MCL_LCU_IP_OUTPUT_SET_EN_FORCE_INT             =  7U,   /**< @brief [LUT_INT_EN] Enables the generation of an interrupt request when an LUT event */
    MCL_LCU_IP_OUTPUT_SET_EN_LUT_INT               =  8U,   /**< @brief [FORCE_INT_EN] Enables the generation of an interrupt request when a force event occurs */
    MCL_LCU_IP_OUTPUT_SET_INVERT_OUTPUT            =  9U,   /**< @brief [OUTPOL] Set Output Polarity: invert or not. */
    MCL_LCU_IP_OUTPUT_SET_FORCE_SIGNAL_SEL         = 10U,   /**< @brief [FORCE_SENSE] Select Force signal */
    MCL_LCU_IP_OUTPUT_SET_CLEAR_FORCE_MODE         = 11U,   /**< @brief [FORCE_MODE] Force Clearing Mode */
    MCL_LCU_IP_OUTPUT_SET_FORCE_SYNC_SEL           = 12U,   /**< @brief [SYNC_SEL] The Force Sync Select Parameter specifies which sync input to use for this output */
    MCL_LCU_IP_OUTPUT_CLEAR_FORCE_STS              = 13U    /**< @brief [FORCESTS] Clear force event in STS */
}Mcl_LcuOutputParamType;

/**
 * @brief This type contains the LCU Param Type to get information for input
 * @details The Parameters get specific functionalities for Input
 *
 * @implements Mcl_LcuInputInfoParamType_enum
 * */
typedef enum
{
    MCL_LCU_IP_INPUT_GET_LOGIC_INPUT_STATE         = 0U,
    MCL_LCU_IP_INPUT_GET_SW_OVERRIDE_STATE         = 1U,
}Mcl_LcuInputInfoParamType;

/**
 * @brief This type contains the LCU Param Type to get information for output
 * @details The Parameters get specific functionalities for Output
 *
 * @implements Mcl_LcuOutputInfoParamType_enum
 * */
typedef enum
{
    MCL_LCU_IP_OUTPUT_GET_LOGIC_OUTPUT_STATE       = 0U,
    MCL_LCU_IP_OUTPUT_GET_FORCE_OUTPUT             = 1U,
    MCL_LCU_IP_OUTPUT_GET_FORCE_STATUS             = 2U,
    MCL_LCU_IP_OUTPUT_GET_LUT_STATUS               = 3U,
    MCL_LCU_IP_OUTPUT_GET_COMBINE_FORCE_INPUT      = 4U,
}Mcl_LcuOutputInfoParamType;

#endif /* #if (STD_ON == MCL_LCU_IS_AVAILABLE) */

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == MCL_DMA_IS_AVAILABLE)
/**
 * @brief This type contains the Mcl Dma Channel Global List.
 * @details The Mcl Dma Channel Global List contains a pair composed from Dma Channel Global Parameter
 *          Type and the Value of the parameter.
 *
 * @implements Mcl_DmaChannelGlobalListType_struct
 * */
typedef struct{
    Mcl_DmaChannelGlobalParamType Param;   /**< @brief The Mcl Dma Channel Global Parameter Type selects a parameter form the Global Parameter enum type. */
    uint32 Value;                          /**< @brief The Value stores the parameter's value. */
}Mcl_DmaChannelGlobalListType;

/**
 * @brief This type contains the Mcl Dma Channel Transfer List.
 * @details The Mcl Dma Channel Transfer List contains a pair composed from Dma Channel Transfer
 *          Parameter Type and the Value of the parameter.
 *
 * @implements Mcl_DmaChannelTransferListType_struct
 * */
typedef struct{
    Mcl_DmaChannelTransferParamType Param; /**< @brief The Mcl Dma Channel Transfer Parameter Type selects a parameter form the Transfer Parameter enum type. */
    uint32 Value;                          /**< @brief The Value stores the parameter's value. */
}Mcl_DmaChannelTransferListType;

/**
 * @brief This type contains the Mcl Dma Channel Scatter/Gather List.
 * @details The Mcl Dma Channel Scatter/Gather List contains a pair composed from Dma Channel Scatter/Gather
 *          Parameter Type and the Value of the parameter.
 *
 * @implements Mcl_DmaChannelScatterGatherListType_struct
 * */
typedef struct{
    Mcl_DmaChannelTransferParamType Param; /**< @brief The Mcl Dma Channel Transfer Parameter Type selects a parameter form the Transfer Parameter enum type. */
    uint32 Value;                          /**< @brief The Value stores the parameter's value. */
}Mcl_DmaChannelScatterGatherListType;


/**
 * @brief This type contains the Mcl Dma Instance Status.
 * @details The Mcl Dma Instance Status contains the Hardware Errors, Active Id and Active indication for
 *          the running Dma Channel.
 *
 * @implements Mcl_DmaInstanceStatusType_struct
 * */
typedef struct{
    uint32  Errors;                        /**< @brief [VALUE]   The Errors value is read from the DMA Instance Error Register (ES) as it is. */
    uint8   ActiveId;                      /**< @brief [VALUE]   The ActiveId value is read from the DMA Instance Control Register (CR) field ACTIVE_ID. */
    boolean Active;                        /**< @brief [BOOLEAN] The Active value is read from the DMA Instance Control Register (CR) field ACTIVE. */
    uint8 Version;                         /**< @brief [VALUE]   The Version value is read from the DMA Instance Control Register (CR) field VER. */
}Mcl_DmaInstanceStatusType;

/**
 * @brief This type contains the Mcl Dma Channel Status.
 * @details The Mcl Dma Channel Status contains the Hardware Errors, Active status and Done indication for
 *          the running Dma Channel.
 *
 * @implements Mcl_DmaChannelStatusType_struct
 * */
typedef struct{
    Mcl_DmaChannelStateType ChannelState;  /**< @brief [VALUE]   The ChStateValue value is read from the internal DMA Driver Channel State Machine. Check UM for additional information. */
    uint32  Errors;                        /**< @brief [VALUE]   The Errors value is read from the DMA Channel Error Register (CHx_ES) as it is. */
    boolean Active;                        /**< @brief [BOOLEAN] The Active value is read from the DMA Channel Control and Status Register (CHx_CSR) field ACTIVE. */
    boolean Done;                          /**< @brief [BOOLEAN] The Active value is read from the DMA Channel Control and Status Register (CHx_CSR) field DONE. */
}Mcl_DmaChannelStatusType;
#endif /* #if (STD_ON == MCL_DMA_IS_AVAILABLE) */

#if (STD_ON == MCL_LCU_IS_AVAILABLE)
/**
 * @brief This type contains the Mcl Lcu Multiple Inputs and Multiple Value.
 * @details The Mcl Lcu Multi Input Value contains a pair composed from Logic Input ID and the
 *          Value of configuration.
 *          The LogicInputId selects a Logic Input
 *          The Value stores the configuration's value.
 * @implements Mcl_LcuSyncInputValueType_struct
 * */
typedef Lcu_Ip_SyncInputValueType Mcl_LcuSyncInputValueType;

/**
 * @brief This type contains the Mcl Lcu Multiple Outputs and Multiple Value.
 * @details The Mcl Lcu Multi Output Value contains a pair composed from Logic Output ID and the
 *          Value of configuration.
 *          The LogicOutputId selects a Logic Output
 *          The Value stores the configuration's value.
 * @implements Mcl_LcuSyncOutputValueType_struct
 * */
typedef Lcu_Ip_SyncOutputValueType Mcl_LcuSyncOutputValueType;

/**
 * @brief This type contains the Mcl Lcu Input with multiple value
 * @details The Mcl Lcu Input with Multiple Value contains a pair composed from Input Parameter and
 *          Value of the Parameter.
 *          The Mcl Lcu Input Param Type selects a parameter from the Lcu_Ip_InputParamType enum
 *          The Value stores the configuration's value.
 * @implements Mcl_LcuAsyncInputValueType_struct
 * */
typedef Lcu_Ip_AsyncInputValueType Mcl_LcuAsyncInputValueType;

/**
 * @brief This type contains the Mcl Lcu Output with multiple value
 * @details The Mcl Lcu Output with Multiple Value contains a pair composed from Output Parameter
 *          and Value of the Parameter.
 *          The Mcl Lcu Output Param Type selects a parameter from the Lcu_Ip_OutputParamType enum
 *          The Value stores the configuration's value.
 * @implements Mcl_LcuAsyncOutputValueType_struct
 * */
typedef Lcu_Ip_AsyncOutputValueType Mcl_LcuAsyncOutputValueType;

#endif /* #if (STD_ON == MCL_LCU_IS_AVAILABLE) */

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"
/**
 * @brief This function initializes the Mcl Driver.
 * @details This service is a non reentrant function that shall initialize the Mcl driver.
 *             The initialization is applied for the enabled IPs, configured statically.
 *
 * @param[in]  ConfigPtr         Pointer to the configuration structure.
 *
 * @return void
 *
 * @implements Mcl_Init_Activity
 * */
void Mcl_Init(const Mcl_ConfigType * const ConfigPtr);

/**
 * @brief This function deinitializes the Mcl Driver.
 * @details This service is a non reentrant function that shall deinitialize the Mcl driver.
 *          The deinitialization is applied for the enabled IPs, configured statically.
 *
 * @return void
 *
 * @implements Mcl_DeInit_Activity
 * */
void Mcl_DeInit(void);

#if (STD_ON == MCL_DMA_IS_AVAILABLE)
/**
 * @brief This function sets Dma Instance Command.
 * @details This service is a reentrant function that shall command the Dma Instance.
 *          The command shall trigger specific functionalities of the Dma Instance.
 *
 * @param[in]  Instance          Selection value of the Logic Instance.
 * @param[in]  Command           The command for the Logic Instance.
 *
 * @return void
 *
 * @implements Mcl_SetDmaInstanceCommand_Activity
 * */
void Mcl_SetDmaInstanceCommand(const uint32 Instance, const Mcl_DmaInstanceCmdType Command);

/**
 * @brief This function gets Dma Instance Status.
 * @details This service is a reentrant function that shall get the Dma Instance status.
 *          The command shall read specific functionalities of the Dma Instance.
 *
 * @param[in]  Instance          Selection value of the Logic Instance.
 * @param[out] Status            Pointer to the Dma Instance status.
 *
 * @return void
 *
 * @implements Mcl_GetDmaInstanceStatus_Activity
 * */
void Mcl_GetDmaInstanceStatus(const uint32 Instance, Mcl_DmaInstanceStatusType * const Status);

/**
 * @brief This function sets Dma Channel Command.
 * @details This service is a reentrant function that shall command the Dma Channel.
 *          The command shall trigger specific functionalities of the Dma Channel.
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[in]  Command           The command for the Logic Channel.
 *
 * @return void
 *
 * @implements Mcl_SetDmaChannelCommand_Activity
 * */
void Mcl_SetDmaChannelCommand(const uint32 Channel, const Mcl_DmaChannelCmdType Command);

/**
 * @brief This function gets Dma Channel Status.
 * @details This service is a reentrant function that shall get the Dma Channel status.
 *          The command shall read specific functionalities of the Dma Channel.
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[out] Status            Pointer to the Dma Channel status.
 *
 * @return void
 *
 * @implements Mcl_GetDmaChannelStatus_Activity
 * */
void Mcl_GetDmaChannelStatus(const uint32 Channel, Mcl_DmaChannelStatusType * const Status);

/**
 * @brief This function sets Dma Channel Global List settings.
 * @details This service is a reentrant function that shall set the Dma Channel
 *          global parameters list.
 *          The list is composed of an array of Dma Channel global parameters settings.
 *          The settings list(array) is defined by the user needs: it contains the
 *          desired parameters to be configured, in any desired order.
 *
 *          How to use this interface:
 *          1. Use the "Mcl_DmaChannelGlobalListType" to create a list(array) with the desired
 *          paramaters to configure (see parameters: "Mcl_DmaChannelGlobalParamType")
 *            The list can declared globally or locally:
 *          Global example:
 *              Mcl_DmaChannelGlobalListType global_Mcl_DmaChannelGlobalList0[NUMBER_OF_PARAMETERS] = {...};
 *          Local example:
 *              Mcl_DmaChannelGlobalListType Mcl_DmaChannelGlobalList[NUMBER_OF_PARAMETERS];
 *              Mcl_DmaChannelGlobalList[PARAMETER0].Param = MCL_DMA_CH_SET_EN_BUFFERED_WRITES;
 *              Mcl_DmaChannelGlobalList[PARAMETER0].Value = TRUE;
 *              Mcl_DmaChannelGlobalList[PARAMETER1].Param = ...;
 *              Mcl_DmaChannelGlobalList[PARAMETER1].Value = ...;
 *          2. Call the "Mcl_SetDmaChannelGlobalList()" interface:
 *              Mcl_SetDmaChannelGlobalList(LOGIC_CHANNELx, Mcl_DmaChannelGlobalList, NUMBER_OF_PARAMETERS);
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[in]  List              Pointer to the Global List Array.
 * @param[in]  ListDimension     Number of entries in the List.
 *
 * @return void
 *
 * @implements Mcl_SetDmaChannelGlobalList_Activity
 * */
void Mcl_SetDmaChannelGlobalList(const uint32 Channel, const Mcl_DmaChannelGlobalListType List[], const uint32 ListDimension);

/**
 * @brief This function sets Dma Channel Transfer List settings.
 * @details This service is a reentrant function that shall set the Dma Channel
 *          transfer parameters list.
 *          The list is composed of an array of Dma Channel transfer parameters settings.
 *          The settings array is defined by the user needs: it contains entries for each desired
 *          parameter to be configured, in any suitable order.
 *
 *          How to use this interface:
 *          1. Use the "Mcl_DmaChannelTransferListType" to create a list(array) with the desired
 *          paramaters to configure (see parameters: "Mcl_DmaChannelTransferParamType")
 *            The list can declared globally or locally:
 *          Global example:
 *              Mcl_DmaChannelTransferListType global_Mcl_DmaChannelTransferList0[NUMBER_OF_PARAMETERS] = {...};
 *          Local example:
 *              Mcl_DmaChannelTransferListType Mcl_DmaChannelTransferList[NUMBER_OF_PARAMETERS];
 *              Mcl_DmaChannelTransferList[PARAMETER0].Param = MCL_DMA_CH_SET_SOURCE_ADDRESS;
 *              Mcl_DmaChannelTransferList[PARAMETER0].Value = &SourceBuffer;
 *              Mcl_DmaChannelTransferList[PARAMETER1].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
 *              Mcl_DmaChannelTransferList[PARAMETER1].Value = &DestinationBuffer;
 *          2. Call the "Mcl_SetDmaChannelTransferList()" interface:
 *              Mcl_SetDmaChannelTransferList(LOGIC_CHANNELx, Mcl_DmaChannelTransferList, NUMBER_OF_PARAMETERS);
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[in]  List              Pointer to the Transfer List Array.
 * @param[in]  ListDimension     Number of entries in the List.
 *
 * @return void
 *
 * @implements Mcl_SetDmaChannelTransferList_Activity
 * */
void Mcl_SetDmaChannelTransferList(const uint32 Channel, const Mcl_DmaChannelTransferListType List[], const uint32 ListDimension);

/**
 * @brief This function sets Dma Channel Scatter/Gather List settings.
 * @details This service is a reentrant function that shall set the Dma Channel
 *          scatter/gather parameters list.
 *          The Scatter/Gather List configures Logic Elements belonging to the same
 *          Dma Logic Channel.
 *          The settings array is defined by the user needs: it contains entries for
 *          each desired parameter to be configured, in any suitable order.
 *
 *          How to use this interface:
 *          1. Use the "Mcl_DmaChannelScatterGatherListType" to create a list(array) with the desired
 *          paramaters to configure (see parameters: "Mcl_DmaChannelTransferParamType")
 *            The list can declared globally or locally:
 *          Global example:
 *              Mcl_DmaChannelScatterGatherListType global_Mcl_DmaChannelScatterGatherList0[NUMBER_OF_PARAMETERS] = {...};
 *          Local example:
 *              Mcl_DmaChannelScatterGatherListType Mcl_DmaChannelScatterGatherList[NUMBER_OF_PARAMETERS];
 *              Mcl_DmaChannelScatterGatherList[PARAMETER0].Param = MCL_DMA_CH_SET_SOURCE_ADDRESS;
 *              Mcl_DmaChannelScatterGatherList[PARAMETER0].Value = &SourceBuffer;
 *              Mcl_DmaChannelScatterGatherList[PARAMETER1].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
 *              Mcl_DmaChannelScatterGatherList[PARAMETER1].Value = &DestinationBuffer;
 *          2. Call the "Mcl_SetDmaChannelScatterGatherList()" interface:
 *              Mcl_SetDmaChannelScatterGatherList(LOGIC_CHANNELx, LOGIC_ELEMENTy, Mcl_DmaChannelScatterGatherList, NUMBER_OF_PARAMETERS);
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[in]  Element           Specifies the Logic Element Id.
 * @param[in]  List              Pointer to the Scatter/Gather List Array.
 * @param[in]  ListDimension     Number of entries in the List.
 *
 * @return void
 *
 * @implements Mcl_SetDmaChannelScatterGatherList_Activity
 * */
void Mcl_SetDmaChannelScatterGatherList(const uint32 Channel, const uint32 Element, const Mcl_DmaChannelScatterGatherListType List[],const uint32 ListDimension);


/**
 * @brief This function gets the Dma Channel Parameter value.
 * @details This service is a reentrant function that shall get the Dma Channel
 *          parameters value.
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[in]  Param             Selection parameter.
 * @param[out] Value             Pointer to the parameter value.
 *
 * @return void
 *
 * @implements Mcl_GetDmaChannelParam_Activity
 * */
void Mcl_GetDmaChannelParam(const uint32 Channel, const Mcl_DmaChannelInfoParamType Param, uint32 * const Value);

/**
 * @brief This function configures the Dma Channel Scatter/Gather.
 * @details This service is a reentrant function that shall configure the Dma Channel
 *          scatter/gather functionality.
 *          The Scatter/Gather settings, for the specified Dma Logic Channel, are loaded
 *          into the Software TCDs. Each software TCD corresponds to a Logic Element.
 *          The specified Logic Element shall be loaded into the Dma Logic Channel's
 *          Hardware TCD.
 *          The Logic Elements (describing the Software TCDs) form a simple chained list,
 *          the "Element" function parameter representing the lists's head.
 *
 * @param[in]  Channel           Specifies the Logic Channel Tag defined by the user.
 * @param[in]  Element           Specifies the Logic Element Id representing the
 *                               list's head.
 *
 * @return void
 *
 * @implements Mcl_SetDmaChannelScatterGatherConfig_Activity
 * */
void Mcl_SetDmaChannelScatterGatherConfig(const uint32 Channel, const uint32 Element);
#endif /* #if (STD_ON == MCL_DMA_IS_AVAILABLE) */



#if (STD_ON == MCL_TRGMUX_IS_AVAILABLE)
/**
 * @brief This function sets the Trgmux Trigger Input selection.
 * @details This service is a reentrant function that shall configure the Trgmux Trigger
 *          functionality.
 *
 * @param[in]  Trigger           Selection value of the Logic Trigger.
 * @param[in]  Input             Selection value for the Logic Trigger's Input.
 *
 * @return void
 *
 * @implements Mcl_SetTrgMuxInput_Activity
 * */
void Mcl_SetTrgMuxInput(const uint32 Trigger, const uint32 Input);

/**
 * @brief This function sets the Trgmux Trigger Lock.
 * @details This service is a reentrant function that shall configure the Trgmux Trigger
 *          Lock functionality.
 *
 * @param[in]  Trigger           Selection value of the Logic Trigger.
 *
 * @return void
 *
 * @implements Mcl_SetTrgMuxLock_Activity
 * */
void Mcl_SetTrgMuxLock(const uint32 Trigger);
#endif /* MCL_TRGMUX_IS_AVAILABLE */


#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
/**
 * @brief This function enables the Cache.
 * @details This service is a reentrant function that shall enable the Cache functionality.
 *
 * @param[in]  CacheType         Selection value of the Cache Type.
 * @param[in]  BusType           Selection value of the Bus Type.
 *
 * @return void
 *
 * @implements Mcl_CacheEnable_Activity
 * */
void Mcl_CacheEnable(Mcl_CacheType CacheType, Mcl_CacheBusType BusType);


/**
 * @brief This function disables the Cache.
 * @details This service is a reentrant function that shall disable the Cache functionality.
 *
 * @param[in]  CacheType         Selection value of the Cache Type.
 * @param[in]  BusType           Selection value of the Bus Type.
 *
 * @return void
 *
 * @implements Mcl_CacheDisable_Activity
 * */
void Mcl_CacheDisable(Mcl_CacheType CacheType, Mcl_CacheBusType BusType);


/**
 * @brief This function Invalidates the Cache.
 * @details This service is a reentrant function that shall Invalidate the Cache functionality.
 *          The Invalidation applies to the entire Cache.
 *
 * @param[in]  CacheType         Selection value of the Cache Type.
 * @param[in]  BusType           Selection value of the Bus Type.
 *
 * @return void
 *
 * @implements Mcl_CacheInvalidate_Activity
 * */
void Mcl_CacheInvalidate(Mcl_CacheType CacheType, Mcl_CacheBusType BusType);


/**
 * @brief This function Cleans the Cache.
 * @details This service is a reentrant function that shall Clean the Cache functionality.
 *          The Clean applies to the entire Cache.
 *          By enabling the Invalidation, the function shall execute specific Cache
 *          Clean&Invalidate function.
 *
 * @param[in]  CacheType         Selection value of the Cache Type.
 * @param[in]  BusType           Selection value of the Bus Type.
 * @param[in]  EnInvalidate      Enable the Invalidation specific functionality.
 *
 * @return void
 *
 * @implements Mcl_CacheClean_Activity
 * */
void Mcl_CacheClean(Mcl_CacheType CacheType, Mcl_CacheBusType BusType, boolean EnInvalidate);


/**
 * @brief This function Invalidates the Cache by address.
 * @details This service is a reentrant function that shall Invalidate the Cache
 *          by address.
 *          The Invalidation applies to the area in Cache specified by the address and length.
 *          The buffer shall be aligned to the Cache Line size.
 *
 * @param[in]  CacheType         Selection value of the Cache Type.
 * @param[in]  BusType           Selection value of the Bus Type.
 * @param[in]  Addr              Address value of the buffer.
 * @param[in]  Length            Length value of the buffer.
 *
 * @return void
 *
 * @implements Mcl_CacheInvalidateByAddr_Activity
 * */
void Mcl_CacheInvalidateByAddr(Mcl_CacheType CacheType, Mcl_CacheBusType BusType, uint32 Addr, uint32 Length);


/**
 * @brief This function Cleans the Cache by address.
 * @details This service is a reentrant function that shall Clean the Cache by address.
 *          The Clean applies to the area in Cache specified by the address and length.
 *          By enabling the Invalidation, the function shall execute specific Cache
 *          Clean&Invalidate function.
 *
 * @param[in]  CacheType         Selection value of the Cache Type.
 * @param[in]  BusType           Selection value of the Bus Type.
 * @param[in]  EnInvalidate      Enable the Invalidation specific functionality.
 * @param[in]  Addr              Address value of the buffer.
 * @param[in]  Length            Length value of the buffer.
 *
 * @return void
 *
 * @implements Mcl_CacheCleanByAddr_Activity
 * */
void Mcl_CacheCleanByAddr(Mcl_CacheType CacheType, Mcl_CacheBusType BusType, boolean EnInvalidate, uint32 Addr, uint32 Length);

#endif /* #if (STD_ON == MCL_CACHE_IS_AVAILABLE) */

#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)
/**
 * @brief Allow the user to specify the number of bus reload events skipped. Reload Signal Output Delay Interval.
 *
 * @param Channel       Should be used the generated define MCL_EMIOS_LOGIC_CH[number]
 *                          - [number] can be indentied by (uint16)((0U << hwNumber) + hwChannel) from define
 *                      A list with this generated defines can be found on Emios_Mcl_Ip_Cfg_Defines.h
 * @param Interval      00000b - Every event
 *                      00001b - Every 2nd event
 *                      00010b - Every 3rd event
 *                      . . .
 *                      11111b - Every 32nd event
 */
void Mcl_Emios_SetReloadInterval(uint16 Channel, uint8 Interval);

/**
 * @brief Change the period on active/intialized EMIOS counter(master) bus.
 *
 * @param logicalChannel Should be used the generated define MCL_EMIOS_LOGIC_CH[number]
 *                          - [number] can be indentied by (uint16)((0U << hwNumber) + hwChannel) from define
 *                     A list with this generated defines can be found on Emios_Mcl_Ip_Cfg_Defines.h
 * @param period       New period value.
 * @param syncUpdate   Stop the channel output if syncronus start is chose.
 *                         FALSE - the function will update the period and the transfer compartor will be enable
 *                         TRUE  - the function will disable the comparator transfer and after that update the period
 *                     After the function is called with syncUpdate=TRUE, it will be needed to call a function
 *                     which will enable the transfer comparator.
 *
 *                     Running the following code will NOT DISABLE AND after ENABLE compartor transfer.
 *                     Mcl_Emios_SetCounterBusPeriod(logicChannel, period, syncUpdate=TRUE);
 *                     Mcl_Emios_SetCounterBusPeriod(logicChannel, period, syncUpdate=FALSE);
 */
void Mcl_Emios_SetCounterBusPeriod(uint16 logicalChannel, uint32 period, boolean syncUpdate);

 /*!
 * @brief   eMios Global Timebase Enable.
 *
 * This function enables or disables the GTBE bit of the EMIOSMCR register of an
 * addressed eMIOS instance.
 *
 * @param[in] Instance       Instance of EMIOS used
 *
 * @param[in] Value          STD_ON   --> Global Timebase Enabled
 *                           STD_OFF  --> Global Timebase Disabled
 *
 * @return                   void
 */
void Mcl_EmiosConfigureGlobalTimebase(uint8 Instance, uint8 Value);


 /*!
 * @brief   eMios Set Clock Mode.
 *
 * This function set the clock mode.
 *
 * @param[in] pConfig        Configuration pointer
 *
 * @param[in] Prescaler      MCL_EMIOS_PRESCALER              --> Select emios prescaler
 *                           MCL_EMIOS_ALTERNATIVE_PRESCALER  --> Select emios alternative prescaler
 *
 * @return                   void
 */
void Mcl_Emios_SetClockMode(const Mcl_EmiosInitConfigType *const pConfig, Mcl_EmiosSelectPrescalerType Prescaler);

#endif /* STD_ON == MCL_EMIOS_IS_AVAILABLE */


#if (STD_ON == MCL_LCU_IS_AVAILABLE)

/* Instance configuration */
/**
 * @brief [WP]This function Enable Write Protect feature for the Logic Instance.
 * @details This service is a reentrant function that shall turns on write protection for all LCU
 *          registers except SWVALUE, LCn_STS, and FORCEST.
 *
 * @param[in]  LogicInstance         Specifies the Logic Instance.Using define generated by the
 *                                   configurator (Example : LCU_LOGIC_INSTANCE_0)
 *
 * @return void
 *
 * @implements Mcl_SetLcuWriteProtect_Activity
 * */
void Mcl_SetLcuWriteProtect(const uint8 LogicInstance);

#if (STD_ON == MCL_LCU_SYNC_FUNC_IS_AVAILABLE)

/* Input configuration */

/**
 * @brief [SWEN] This function Enable/Disable software override of LC input.
 * @details This service is a reentrant function that shall Enable/Disable software override of LC
 *          input. When enable multi cores, the API shall write the values into the register only
 *          if the list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_SW_OVERRIDE_DISABLE/LCU_IP_SW_OVERRIDE_ENABLE
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncInputSwOverrideEnable_Activity
 * */
void Mcl_SetLcuSyncInputSwOverrideEnable(const Mcl_LcuSyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [SWVALUE] This function specifies the software override value for each LC input.
 * @details This service is a reentrant function that shall specifies the software override value
 *          for each LC input. When enable multi cores, the API shall write the values into the
 *          register only if the list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_SW_OVERRIDE_LOGIC_LOW/LCU_IP_SW_OVERRIDE_LOGIC_HIGH
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncInputSwOverrideValue_Activity
 * */
void Mcl_SetLcuSyncInputSwOverrideValue(const Mcl_LcuSyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [MUXSEL] This function selects the source of the LC input.
 * @details This service is a reentrant function that shall selects the source of the LC input.
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 255]
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncInputMuxSelect_Activity
 * */
void Mcl_SetLcuSyncInputMuxSelect(const Mcl_LcuSyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [SW_MODE] specifies the software sync mode for the inputs to this LC.
 * @details This service is a reentrant function that shall specifies the software sync mode for
 *          the inputs to this LC.When Software Override is enabled (SWEN), these bits control
 *          whether Software Override Value (SWVALUE) changes occur immediately or on the rising
 *          edge of the selected sync pulse. When enable multi cores, the API shall write the
 *          values into the register only if the list contains all the Inputs related to the same
 *          partition
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_SW_SYNC_IMMEDIATE/LCU_IP_SW_SYNC_ON_RISING_EDGE
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncInputSwSyncMode_Activity
 * */
void Mcl_SetLcuSyncInputSwSyncMode(const Mcl_LcuSyncInputValueType List[], const uint8 Dimension);

/* Output configuration */

/**
 * @brief [DBGEN] This function Enables/Disables outputs to continue operation in Debug mode.
 * @details This service is a reentrant function that shall Enables/Disables outputs to continue
 *          operation in Debug mode. When enable multi cores, the API shall write the values into
 *          the register only if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_DEBUG_DISABLE/LCU_IP_DEBUG_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputDebugMode_Activity
 * */
void Mcl_SetLcuSyncOutputDebugMode(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [OUTEN] This function Enables/Disables LC outputs.
 * @details This service is a reentrant function that shall Enables/Disables LC outputs. When
 *          enable multi cores, the API shall write the values into the register only if the list
 *          contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_OUTPUT_DISABLE/LCU_IP_OUTPUT_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputEnable_Activity
 * */
void Mcl_SetLcuSyncOutputEnable(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCE_SENSE] This function specifies which force inputs affect output.
 * @details This service is a reentrant function that shall specifies which force inputs affect
 *          output. When enable multi cores, the API shall write the values into the register only
 *          if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 255]
 *          For each bit:
 *              0b - Does not affect
 *              1b - Affects
.*          Example: 011b specifies: force inputs 0 and 1 will affect for this logic output,
.*          but force inputs 2 will not affect
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputForceInputSensitivity_Activity
 * */
void Mcl_SetLcuSyncOutputForceInputSensitivity(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/* [FORCE_MODE] Specifies the timing for clearing force events for output */
/**
 * @brief [FORCE_MODE] This function specifies the timing for clearing force events for output.
 * @details This service is a reentrant function that shall specifies the timing for clearing
 *          force events for output. When enable multi cores, the API shall write the values into
 *          the register only if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE/
 *          LCU_IP_CLEAR_FORCE_SIGNAL_ON_RISING_EDGE/
 *          LCU_IP_CLEAR_FORCE_SIGNAL_AFTER_CLEAR_STATUS/
 *          LCU_IP_CLEAR_FORCE_SIGNAL_ON_RISING_EDGE_AFTER_CLEAR_STATUS
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputForceClearingMode_Activity
 * */
void Mcl_SetLcuSyncOutputForceClearingMode(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [SYNC_SEL] This function specifies which sync input to use for Force signal.
 * @details This service is a reentrant function that shall specifies which sync input to use for
 *          Force signal. When enable multi cores, the API shall write the values into the
 *          register only if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value ->  Unsigned Integer: [0, 255]
 *                            00b - Sync input 0
 *                            01b - Sync input 1
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputForceSyncSelect_Activity
 * */
void Mcl_SetLcuSyncOutputForceSyncSelect(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [OUTPOL] This function specifies the polarity of the outputs.
 * @details This service is a reentrant function that shall specifies the polarity of the outputs
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_FORCE_POL_NOT_INVERTED/LCU_IP_FORCE_POL_INVERTED
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputPolarity_Activity
 * */
void Mcl_SetLcuSyncOutputPolarity(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCE_DMA_EN] This function Enables/Disable the generation of a DMA request when a
 *          force event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of a
 *          DMA request when a force event occurs. When enable multi cores, the API shall write
 *          the values into the register only if the list contains all the Outputs related to the
 *          same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_DMA_DISABLE/LCU_IP_DMA_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputForceDma_Activity
 * */
void Mcl_SetLcuSyncOutputForceDma(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCE_INT_EN] This function Enables/Disable the generation of an interrupt request when
 *          force event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of an
 *          interrupt request when force event occurs. When enable multi cores, the API shall
 *          write the values into the register only if the list contains all the Outputs related
 *          to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_INT_DISABLE/LCU_IP_INT_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputForceInt_Activity
 * */
void Mcl_SetLcuSyncOutputForceInt(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_DMA_EN] This function Enables/Disable the generation of a DMA request when a
 *          LUT event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of a
 *          DMA request when a LUT event occurs. When enable multi cores, the API shall write the
 *          values into the register only if the list contains all the Outputs related to the same
 *          partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_DMA_DISABLE/LCU_IP_DMA_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputLutDma_Activity
 * */
void Mcl_SetLcuSyncOutputLutDma(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_INT_EN] This function Enables/Disable the generation of an interrupt request when
 *          LUT event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of an
 *          interrupt request when LUT event occurs. When enable multi cores, the API shall write
 *          the values into the register only if the list contains all the Outputs related to the
 *          same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_INT_DISABLE/LCU_IP_INT_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputLutInt_Activity
 * */
void Mcl_SetLcuSyncOutputLutInt(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_FALL_FILT] This function specifies the number of consecutive clock cycles the
 *          filter output must be logic 0 before the output signal goes low
 * @details This service is a reentrant function that shall specifies the number of consecutive
 *          clock cycles the filter output must be logic 0 before the output signal goes low
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 65535]
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputFallFilter_Activity
 * */
void Mcl_SetLcuSyncOutputFallFilter(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_RISE_FILT] This function specifies the number of consecutive clock cycles the
 *          filter output must be logic 1 before the output signal goes high
 * @details This service is a reentrant function that shall Specifies the number of consecutive
 *          clock cycles the filter output must be logic 1 before the output signal goes high
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 65535]
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputRiseFilter_Activity
 * */
void Mcl_SetLcuSyncOutputRiseFilter(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUTCTRL] This function specifies the LUT positions, based on the combined LC input value
 * @details This service is a reentrant function that shall Specifies the LUT positions, based on
 *          the combined LC input value
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 65535]
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuSyncOutputLutControl_Activity
 * */
void Mcl_SetLcuSyncOutputLutControl(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCESTS] This function Clear Force Event
 * @details This service is a reentrant function that shall Clear Force Event
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_ClearLcuSyncOutputForceEvent_Activity
 * */
void Mcl_ClearLcuSyncOutputForceEvent(const Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LC_INPUTS] This function Indicates states of LC inputs
 * @details This service is a reentrant function that shall Indicates states of LC inputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicInputId -> The Logic Input Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the states of LC inputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_GetLcuSyncLogicInput_Activity
 * */
void Mcl_GetLcuSyncLogicInput(Mcl_LcuSyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [SWOUT] This function Indicates states of LC inputs or software-overridden inputs
 * @details This service is a reentrant function that shall Indicates states of LC inputs or
 *          software-overridden inputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicInputId -> The Logic Input Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the states of LC inputs or
 *                                              software-overridden inputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_GetLcuSyncSwOverrideInput_Activity
 * */
void Mcl_GetLcuSyncSwOverrideInput(Mcl_LcuSyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [LCOUT] This function Indicates states of LC outputs
 * @details This service is a reentrant function that shall Indicates states of LC outputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the states of LC outputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_GetLcuSyncLogicOutput_Activity
 * */
void Mcl_GetLcuSyncLogicOutput(Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCEOUT] This function Indicates the current state of force outputs for the logic
 *                   outputs
 * @details This service is a reentrant function that shall the current state of force outputs for
 *          the logic outputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the current state of force outputs for the
 *                logic outputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_GetLcuSyncForceOutput_Activity
 * */
void Mcl_GetLcuSyncForceOutput(Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCESTS] This function Indicates that a force event has occurred on the associated
          output
 * @details This service is a reentrant function that shall Indicates that a force event has
 *          occurred on the associated output
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the force event value.
 *                Value = 0: force event not occurs
 *                Value = 1: force event occurs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_GetLcuSyncForceStatus_Activity
 * */
void Mcl_GetLcuSyncForceStatus(Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [COMB_FORCE] This function Indicates the combined value of force inputs to each output
 * @details This service is a reentrant function that shall Indicates the combined value of force
 *          inputs to each output
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the combined value of force inputs to each
 *                output
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_GetLcuSyncCombineForceInput_Activity
 * */
void Mcl_GetLcuSyncCombineForceInput(Mcl_LcuSyncOutputValueType List[], const uint8 Dimension);
#endif /* #if (STD_ON == MCL_LCU_SYNC_FUNC_IS_AVAILABLE) */

#if (STD_ON == MCL_LCU_ASYNC_FUNC_IS_AVAILABLE)

/**
 * @brief This function configure multiple configuration for one logic input
 * @details This service is a reentrant function that shall configure multiple configuration for
 *          one logic input
 *
 *          How to use this interface:
 *          List[x].Param -> Select member of Mcl_LcuInputParamType
 *          List[x].Value -> Unsigned Integer: [0, 255] or some defines generated by configurator
 *                           base on Param
 *
 * @param[in]  LogicInput    Logic input Id
 * @param[in]  List          List of param and value
 * @param[in]  Dimension     Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuAsyncInputList_Activity
 * */
void Mcl_SetLcuAsyncInputList(const uint8 LogicInput, const Mcl_LcuAsyncInputValueType List[], const uint8 Dimension);

/**
 * @brief This function configure multiple configuration for one logic output
 * @details This service is a reentrant function that shall configure multiple configuration for
 *          one logic output
 *
 *          How to use this interface:
 *          List[x].Param -> Select member of Mcl_LcuOutputParamType
 *          List[x].Value -> Unsigned Integer: [0, 255] or some defines generated by configurator
 *                           base on Param
 *
 * @param[in]  LogicOutput    Logic output Id
 * @param[in]  List           List of param and value
 * @param[in]  Dimension      Number of entries in the List
 *
 * @return void
 *
 * @implements Mcl_SetLcuAsyncOutputList_Activity
 * */
void Mcl_SetLcuAsyncOutputList(const uint8 LogicOutput, const Mcl_LcuAsyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief This function get information of Logic Input
 * @details This service is a reentrant function that shall get states of Logic Inputs
 *          How to use this interface:
 *          [in] LogicInput -> The Logic Input Name generated by the configurator.
 *                             By default: LCU_LOGIC_INPUT_0, LCU_LOGIC_INPUT_1,...
 *          [in] Param -> Select parameter. Example: MCL_LCU_IP_INPUT_GET_LOGIC_INPUT_STATE
 *          [out] Value -> Store the states of LC inputs
 *
 * @param[in]  LogicInput    The Logic Input Name
 * @param[in]  Param         Selection parameter
 * @param[out] Value         Output value
 *
 * @return void
 *
 *
 * @implements Mcl_GetLcuAsyncLogicInputInfo_Activity
 * */
void Mcl_GetLcuAsyncLogicInputInfo(const uint8 LogicInput, const Mcl_LcuInputInfoParamType Param, uint8 * const Value);

/**
 * @brief This function get information of Logic Output
 * @details This service is a reentrant function that shall get states of Logic Outputs
 *          How to use this interface:
 *          [in] LogicOutput -> The Logic Output Name generated by the configurator.
 *                              By default: LCU_LOGIC_OUTPUT_0, LCU_LOGIC_OUTPUT_1,...
 *          [in] Param -> Select parameter. Example: MCL_LCU_IP_OUTPUT_GET_LOGIC_OUTPUT_STATE
 *          [out] Value -> Store the states of LC inputs
 *
 * @param[in]  LogicOutput    The Logic Output Name
 * @param[in]  Param          Selection parameter
 * @param[out] Value          Output value
 *
 * @return void
 *
 *
 * @implements Mcl_GetLcuAsyncLogicOutputInfo_Activity
 * */
void Mcl_GetLcuAsyncLogicOutputInfo(const uint8 LogicOutput, const Mcl_LcuOutputInfoParamType Param, uint8 * const Value);

#endif /* #if (STD_ON == MCL_LCU_ASYNC_FUNC_IS_AVAILABLE) */
#endif /* #if (STD_ON == MCL_LCU_IS_AVAILABLE) */


#if (STD_ON == MCL_VERSION_INFO_API_IS_AVAILABLE)
/**
 * @brief   Returns the version information of this module.
 * @details Returns the version information of MCL module.
 *
 * @param[out]  VersionInfo    A pointer to a structure used to get version information.
 *
 * @return void
 *
 * @implements Mcl_GetVersionInfo_Activity
 * */
void Mcl_GetVersionInfo(Std_VersionInfoType * const VersionInfo);
#endif /* STD_ON == MCL_VERSION_INFO_API_IS_AVAILABLE */

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* CDD_MCL_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

