/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef ICU_H
#define ICU_H

/**
 *     @file
 *
 *     @addtogroup icu Icu Driver
 *     @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Std_Types.h"
#include "Icu_Cfg.h"
#include "Icu_Types.h"
#include "Icu_Ipw_Types.h"

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Externals.h"
#endif

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
#include "CDD_Mcl.h"
#endif
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID                       43
#define ICU_MODULE_ID                       122
#define ICU_AR_RELEASE_MAJOR_VERSION        4
#define ICU_AR_RELEASE_MINOR_VERSION        7
#define ICU_AR_RELEASE_REVISION_VERSION     0
#define ICU_SW_MAJOR_VERSION                5
#define ICU_SW_MINOR_VERSION                0
#define ICU_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu.h and Std_Types.h are different"
    #endif

    #if ((ICU_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu.h and Mcal.h are different"
    #endif

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
    /* Check Icu_Cfg.c against CDD_Mcl.h file versions */
    #if ((ICU_AR_RELEASE_MAJOR_VERSION != CDD_MCL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION != CDD_MCL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu.h and CDD_Mcl.h are different"
    #endif
#endif
#endif

/* Check if source file and ICU configuration header file are of the same vendor */
#if (ICU_VENDOR_ID != ICU_CFG_VENDOR_ID)
    #error "Icu.h and Icu_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and ICU configuration header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu.h and Icu_Cfg.h are different"
#endif
/* Check if header file and ICU configuration header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_CFG_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION != ICU_CFG_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION != ICU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.h and Icu_Cfg.h are different"
#endif

/* Check if source file and ICU types header file are of the same vendor */
#if (ICU_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu.h and Icu_Types.h have different vendor IDs"
#endif
    /* Check if header file and ICU types header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu.h and Icu_Types.h are different"
#endif
/* Check if header file and ICU types header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.h and Icu_Types.h are different"
#endif

/* Check if source file and ICU types header file are of the same vendor */
#if (ICU_VENDOR_ID != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu.h and Icu_Ipw_Types.h have different vendor IDs"
#endif
    /* Check if header file and ICU types header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu.h and Icu_Ipw_Types.h are different"
#endif
/* Check if header file and ICU types header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.h and Icu_Ipw_Types.h are different"
#endif

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if header file and EcuM_Cbk.h file are of the same Autosar version */
        #if ((ICU_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu.h and EcuM_Cbk.h are different"
        #endif
    #endif
#endif  /* ICU_REPORT_WAKEUP_SOURCE */
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
/**
* @brief   API service used with a value is not in range
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_CONFIG             ((uint8)0x09)

/**
* @brief   API Icu_Init service called with wrong parameter
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_INIT_FAILED               ((uint8)0x0D)

/**
* @brief   API service used with an invalid channel identifier or channel was not configured for
*          the functionality of the calling API
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_CHANNEL             ((uint8)0x0B)

/**
* @brief   API service used with an invalid or not feasible activation
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_ACTIVATION          ((uint8)0x0C)

/**
* @brief   API service used with an invalid application-buffer pointer
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_POINTER             ((uint8)0x0A)

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON))
/**
* @brief   API service used with an invalid buffer size
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_BUFFER_SIZE         ((uint8)0x0E)
#endif

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
* @brief   API service Icu_SetMode used with an invalid mode
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_MODE                ((uint8)0x0F)
#endif

/**
* @brief   API service used without module initialization
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_UNINIT                    ((uint8)0x14)

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
* @brief   API service Icu_SetMode is called while a running operation
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_BUSY_OPERATION            ((uint8)0x16)
#endif

/**
* @brief   API Icu_Init service called when the ICU driver and the Hardware
*          are already initialized
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_ALREADY_INITIALIZED       ((uint8)0x17)

/**
* @brief   API Icu_StartTimeStamp is called and the parameter NotifyInterval is invalid (e.g. 0,
*           NotifyInterval < 1)
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_NOTIFY_INTERVAL     ((uint8)0x18)

/**
* @brief   API Icu_GetVersionInfo is called and the parameter versioninfo is is invalid
*          ( e.g. NULL )
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_VINFO               ((uint8)0x19)

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON))
/**
* @brief    API Icu_SetClockMode service called with wrong parameter
* @implements Icu_ErrorCodes_define
*/
#define ICU_E_PARAM_CLOCK_MODE          ((uint8)0x7AU)
#endif

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON))
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (STD_ON == ICU_EDGE_COUNT_API)
/**
* @brief   API Icu_GetEdgeNumbers service called when the Counter rolls over
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_EDGECOUNTING_OVERFLOW     ((uint8)0xD0)
#endif
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief   API Icu_GetTimestampIndex service called when the Time stamp count overflows
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_TIMESTAMP_OVERFLOW        ((uint8)0xD1)
#endif

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)&&((ICU_GET_TIME_ELAPSED_API== STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API== STD_ON)))
/**
* @brief   API Icu_GetTimeElapsed service called when the Time elapsed overflows
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_MEASUREMENT_OVERFLOW      ((uint8)0xD2)
#endif
#endif

/**
* @brief   API Check mode before set up feature for channel
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_FORBIDEN_MODE             ((uint8)0xD4)

/**
* @brief API service ID for Icu_Init function
* @details Parameters used when raising an error/exception
* */
#define ICU_INIT_ID                     ((uint8)0x00)
/**
* @brief API service ID for Icu_DeInit function
* @details Parameters used when raising an error/exception
* */
#define ICU_DEINIT_ID                   ((uint8)0x01)

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
* @brief API service ID for Icu_SetMode function
* @details Parameters used when raising an error/exception
* */
#define ICU_SETMODE_ID                  ((uint8)0x02)
#endif

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
#if ((ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON))
/**
* @brief API service ID for Icu_DisableWakeup function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLEWAKEUP_ID            ((uint8)0x03)

#endif
#endif

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON))

/**
* @brief API service ID for Icu_EnableWakeup function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLEWAKEUP_ID             ((uint8)0x04)

#endif
#endif

/**
* @brief API service ID for Icu_SetActivationCondition function
* @details Parameters used when raising an error/exception
* */
#define ICU_SETACTIVATIONCONDITION_ID   ((uint8)0x05)

/**
* @brief API service ID for Icu_DisableNotification function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLENOTIFICATION_ID      ((uint8)0x06)

/**
* @brief API service ID for Icu_EnableNotification function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLENOTIFICATION_ID       ((uint8)0x07)

#if ((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON))
/**
* @brief API service ID for Icu_GetInputState function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETINPUTSTATE_ID            ((uint8)0x08)
#endif

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON))
/**
* @brief API service ID for Icu_StartTimestamp function
* @details Parameters used when raising an error/exception
* */
#define ICU_STARTTIMESTAMP_ID           ((uint8)0x09)

/**
* @brief API service ID for Icu_GetTimestampIndex function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETTIMESTAMPINDEX_ID        ((uint8)0x0B)
#endif /* ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON)) */

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
* @brief API service ID for Icu_ResetEdgeCount function
* @details Parameters used when raising an error/exception
* */
#define ICU_RESETEDGECOUNT_ID           ((uint8)0x0C)

/**
* @brief API service ID for Icu_EnableEdgeCount function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLEEDGECOUNT_ID          ((uint8)0x0D)

/**
* @brief API service ID for Icu_DisableEdgeCount function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLEEDGECOUNT_ID         ((uint8)0x0E)

/**
* @brief API service ID for Icu_GetEdgeNumbers function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETEDGENUMBERS_ID           ((uint8)0x0F)

#if (defined ICU_SET_INITIAL_COUNTER)
#if ((STD_ON == ICU_SET_INITIAL_COUNTER) && (STD_ON == ICU_VALIDATE_PARAMS))
/**
* @brief API service ID for Icu_SetInitialCounterValue function (not an AUTOSAR function)
* @details Parameters used when raising an error/exception
* */
#define ICU_SETINITIALCOUNTER_ID     ((uint8)0x1E)
#endif
#endif

#if (defined ICU_SET_MAX_COUNTER)
#if ((STD_ON == ICU_SET_MAX_COUNTER) && (STD_ON == ICU_VALIDATE_PARAMS))
/**
* @brief API service ID for Icu_SetMaxCounterValue function (not an AUTOSAR function)
* @details Parameters used when raising an error/exception
* */
#define ICU_SETMAXCOUNTER_ID    ((uint8)0x1F)
#endif
#endif

#endif /* (STD_ON == ICU_EDGE_COUNT_API) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_TIME_ELAPSED_API == STD_ON))
/**
* @brief API service ID for Icu_GetTimeElapsed function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETTIMEELAPSED_ID           ((uint8)0x10)
#endif

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
/**
* @brief API service ID for Icu_GetDutyCycleValues function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETDUTYCYCLEVALUES_ID       ((uint8)0x11)
#endif

/**
* @brief API service ID for Icu_GetVersionInfo function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETVERSIONINFO_ID           ((uint8)0x12)

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
* @brief API service ID for Icu_StartSignalMeasurement function
* @details Parameters used when raising an error/exception
* */
#define ICU_STARTSIGNALMEASUREMENT_ID   ((uint8)0x13)

/**
* @brief API service ID for Icu_StopSignalMeasurement function
* @details Parameters used when raising an error/exception
* */
#define ICU_STOPSIGNALMEASUREMENT_ID    ((uint8)0x14)
#endif /* (STD_ON == ICU_SIGNAL_MEASUREMENT_API) */

#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && (ICU_VALIDATE_GLOBAL_CALL == STD_ON))
/**
* @brief API service ID for Icu_CheckWakeup function
* @details Parameters used when raising an error/exception
* */
#define ICU_CHECKWAKEUP_ID              ((uint8)0x15)
#endif

/**
* @brief API service ID for Icu_EnableEdgeDetection function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLEEDGEDETECTION_ID      ((uint8)0x16)

/**
* @brief API service ID for Icu_DisableEdgeDetection function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLEEDGEDETECTION_ID     ((uint8)0x17)

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON))
/**
* @brief   API service ID for Icu_SetClockMode function
* @details Parameters used when raising an error/exception
*/
#define ICU_SET_CLOCK_MODE_ID           ((uint8)0x7BU)
#endif

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))
/**
* @brief   API service ID for Icu_GetCaptureRegisterValue function
* @details Parameters used when raising an error/exception
*/
#define ICU_GET_CAPTURE_REGISTER_VALUE_ID           ((uint8)0x19U)
#endif

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief   API service ID for Icu_GetPulseWidth function
* @details Parameters used when raising an error/exception
*/
#define ICU_GET_PULSE_WIDTH_ID                      ((uint8)0x1AU)
#endif

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
 * @brief   API service ID for Icu_GetInputLevel function
 * @details Parameters used when raising an error/exception
 * */
 #define ICU_GET_INPUT_LEVEL_ID          ((uint8)0x7CU)
#endif /* ICU_GET_INPUT_LEVEL_API */
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief API service ID for Icu_StopTimestamp function
* @details Parameters used when raising an error/exception
* */
#define ICU_STOPTIMESTAMP_ID            ((uint8)0x0A)

/**
* @brief   API service Icu_StopTimestamp called on a channel which was not
*          started or already stopped
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_NOT_STARTED               ((uint8)0x15)
#endif
/*================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
/** @brief Typedef for Mcl_ChannelType.  */
typedef uint8 Mcl_ChannelType;
#endif

/**
 * @brief    Structure that contains ICU channel configuration.
 * @details  It contains the information like Icu Channel Mode, Channel Notification function,
 *           overflow Notification function.
 * @implements Icu_ChannelConfigType_struct
 * */
typedef struct
{
    /** @brief Channel wakeup capability enable. */
    boolean                     Icu_WakeupCapabile;
    /** @brief RISING_EDGE, FALLING_EDGE or BOTH_EDGES for EDGE_COUNTER. */
    Icu_ActivationType          Icu_ActivEdge;
    /** @brief EDGE_DETECT, TIME_STAMP, SIGNAL_MEASUREMENT or EDGE_COUNTER. */
    Icu_MeasurementModeType     Icu_ChannelMode;
    /** @brief CIRCULAR_BUFFER or LINEAR_BUFFER for TIME_STAMP, DUTY_CYCLE, HIGH_TIME, LOW_TIME
     *         or PERIOD_TIME for SIGNAL_MEASUREMENT and RISING_EDGE, FALLING_EDGE or
     *         BOTH_EDGES for EDGE_COUNTER. */
    Icu_MeasurementSubModeType  Icu_ChannelProperty;
    /** @brief Icu Channel Notification function for TIME_STAMP or EDGE_COUNTER mode. */
    Icu_NotifyType              Icu_ChannelNotification;
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
    /** @brief Mcl_DmaChannel Id. */
    Mcl_ChannelType             Mcl_DmaChannel;
#endif
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /** @brief  Icu Channel Overflow Notification function. */
    Icu_NotifyType              Icu_ChOverflowNotification;
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    Icu_WakeupValueType         Icu_Channel_WakeupValue;           /**< @brief EcuM wakeup source Id. */
#endif  /* ICU_REPORT_WAKEUP_SOURCE == STD_ON */
    /** @brief Pointer to the ipw channel pointer configuration */
    const Icu_Ipw_ChannelConfigType   (*Icu_IpwChannelConfigPtr);
} Icu_ChannelConfigType;

/**
 * @brief This type contains initialization data.
 * @details he notification functions shall be configurable
 *         as function pointers within the initialization data structure (Icu_ConfigType).
 *         This type of the external data structure shall contain the
 *         initialization data for the ICU driver. It shall contain:
 *         - Wakeup Module Info (in case the wakeup-capability is true)
 *         - ICU dependent properties for used HW units
 *         - Clock source with optional prescaler (if provided by HW)
 * @implements Icu_ConfigType_struct
 * */
typedef struct
{
    /** @brief The number of configured logical channels. */
    uint8                       nNumChannels;

    /** @brief Pointer to the list of Icu configured channels */
    const Icu_ChannelConfigType       (*Icu_ChannelConfigPtr)[];

    /** @brief The number of IP instances configured */
    uint8                       nNumInstances;

    /** @brief Pointer to the list of Icu configured channels */
    const Icu_Ipw_IpConfigType  (*Icu_IpConfigPtr)[];
    
    /** @brief channel index in each partition map table*/
    const uint8                       (*Icu_IndexChannelMap)[];

    /** @brief partition index*/
    uint32                       u32UserID;
} Icu_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef ICU_PRECOMPILE_SUPPORT
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

ICU_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#endif /* #ifndef ICU_PRECOMPILE_SUPPORT */

#if (ICU_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"
/**
 * @brief Pointer initialized during init with the address of the received configuration structure.
 * @details Will be used by all functions to access the configuration data.
 **/
extern const Icu_ConfigType           *Icu_pCfgPtr[ICU_MAX_PARTITIONS];


/**
 * @brief Saves the current Icu mode
 **/
extern Icu_ModeType             Icu_CurrentMode[ICU_MAX_PARTITIONS];


/**
 * @brief   Stores actual state and configuration of ICU Channels
 **/
extern volatile Icu_ChannelStateType    Icu_aChannelState[ICU_MAX_CHANNEL];

#if (ICU_TIMESTAMP_API == STD_ON)
/** @brief Pointer to the buffer-array where the timestamp values shall be placed. */
extern Icu_ValueType            *Icu_aBuffer[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving the size of the external buffer (number of entries)
 **/
extern uint16                   Icu_aBufferSize[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving Notification interval (number of events).
 **/
extern uint16                   Icu_aBufferNotify[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving the number of notify counts
 **/
extern volatile  uint16         Icu_aNotifyCount[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving the time stamp index
 **/
extern volatile  Icu_IndexType  Icu_aBufferIndex[ICU_MAX_CHANNEL];

#endif /* ICU_TIMESTAMP_API */

#if (ICU_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
* @brief          This function initializes the driver.
* @details        This service is a non reentrant function used for driver initialization.
*        The  Initialization function  shall initialize  all relevant  registers of  the configured
*        hardware with the  values of the  structure referenced by  the parameter ConfigPtr.
*        If  the  hardware  allows  for   only  one  usage   of  the  register,   the  driver
*        module implementing that functionality is responsible for initializing the register.
*        The initialization function of this module shall always have a pointer as a parameter,
*        even though for Variant PC no configuration set shall be given.
*        Instead a NULL pointer shall be passed to the initialization function.
*        The Icu  module environment  shall not  call Icu_Init  during a  running operation (e. g.
*        timestamp measurement or edge counting).
*
* @param[in]         ConfigPtr        Pointer to a selected configuration structure.
*
* @return             void
**/
void Icu_Init(const Icu_ConfigType* ConfigPtr);

#if (ICU_DE_INIT_API == STD_ON)
/**
* @brief   This function de-initializes the ICU module.
* @details This service is a Non reentrant function used for ICU De-Initialization
*        After the call of this service, the state of the peripherals used by configuration shall be
*        the  same as  after power  on reset.  Values of  registers which  are not  writable  are
*        excluded.
*        This service shall disable all used interrupts and notifications.
*        The Icu module environment shall not  call Icu_DeInit during a running  operation  (e. g.
*        timestamp measurement or edge counting)
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.
* @implements Icu_DeInit_Activity
*
**/
void Icu_DeInit(void);
#endif /* ICU_DE_INIT_API */


#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief           This function sets the ICU mode.
* @details     This service is a non reentrant function used for ICU mode  selection.
*       This service shall  set the  operation mode  to the given mode parameter.
*       This service  can be  called during  running operations.  If so,  an ongoing operation that
*       generates interrupts on a wakeup capable  channel like e.g. time stamping or  edge counting
*       might lead to the  ICU module not being  able to properly enter sleep  mode. This is then a
*       system or ECU configuration issue not a problem of this specification.
*
* @param[in]   Mode        Specifies the operation mode
* @return         void
*
* @pre         Icu_Init must be called before.
* @implements     Icu_SetMode_Activity
*
* @api
*
**/
void Icu_SetMode(Icu_ModeType Mode);
#endif /* ICU_SET_MODE_API */


#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/**
* @brief   This function disables the wakeup capability of a single ICU channel.
* @details This service is reentrant function and shall disable  the wakeup capability of
*          a single ICU channel.This  service is only feasible for ICU channels configured
*          statically as wakeup capable true.
*          The  function  Icu_DisableWakeup shall  be  pre compile  time  configurable On,Off by
*          the configuration parameter IcuDisableWakeupApi.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.
* @implements Icu_DisableWakeup_Activity
*
**/
void Icu_DisableWakeup(Icu_ChannelType Channel);
#endif /* ICU_DISABLE_WAKEUP_API */


#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/**
* @brief   This function (re-)enables the wakeup capability of the given ICU channel.
* @details The function is reentrant and re-enable the wake-up capability of a single ICU channel.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The channel must be configured as wakeup capable.
* @implements Icu_EnableWakeup_Activity
*
**/
void Icu_EnableWakeup(Icu_ChannelType Channel);
#endif /* ICU_ENABLE_WAKEUP_API */


#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief  Checks if a wakeup capable ICU channel is the source for a wakeup event.
* @details The function calls the ECU state manager service EcuM_SetWakeupEvent
* in case of a valid ICU channel wakeup event.
*
* @param[in]     WakeupSource          Information on wakeup source to be checked.
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The channel must be configured as wakeup capable.
*
* @implements Icu_CheckWakeup_Activity
*
**/
void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif /* ICU_WAKEUP_FUNCTIONALITY_API */

/**
* @brief   This function sets the activation-edge for the given channel.
* @details This service  is reentrant and shall set  the  activation-edge according to Activation
*          parameter for the given channel.
*          This service shall support channels which are configured
*          for  the following Icu_MeasurementMode:
*          - ICU_MODE_SIGNAL_EDGE_DETECT
*          - ICU_MODE_TIMESTAMP
*          - ICU_MODE_EDGE_COUNTER
*
* @param[in]     Channel          Logical number of the ICU channel
* @param[in]     Activation       Type of activation.
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The channel must be properly configured
*      (ICU_MODE_SIGNAL_EDGE_DETECT, ICU_MODE_TIMESTAMP, ICU_MODE_EDGE_COUNTER).
*
* @implements Icu_SetActivationCondition_Activity
*
**/
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);

/**
* @brief   This function disables the notification of a channel.
*
* @details This function is reentrant and disables the notification of a channel.
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.
*
* @implements Icu_DisableNotification_Activity
*
**/
void Icu_DisableNotification(Icu_ChannelType Channel);

/**
* @brief   This function enables the notification on the given channel.
* @details This function is reentrant and enables the notification on the given channel. The
*          notification  will be reported only when the channel measurement property is enabled or
*          started
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.
*
* @implements Icu_EnableNotification_Activity
*
**/
void Icu_EnableNotification(Icu_ChannelType Channel);

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief   This function returns the status of the ICU input.
* @details This service is reentrant shall return the status of  the ICU input.
*          Only channels which are configured for the following Icu_MeasurementMode shall be
*          supported:
*          - ICU_MODE_SIGNAL_EDGE_DETECT,
*          - ICU_MODE_SIGNAL_MEASUREMENT.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return Icu_InputStateType
* @retval  ICU_ACTIVE     An activation edge has been detected
* @retval  ICU_IDLE       No activation edge has been detected since the last call of
* Icu_GetInputState() or Icu_Init().
*
* @api
*
* @pre Icu_Init must be called before.
*
* @implements Icu_GetInputState_Activity
*
**/
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel);
#endif /* ICU_GET_INPUT_STATE_API */


#if (STD_ON == ICU_TIMESTAMP_API)
/**
 * @brief   This function starts the capturing of timer values on the edges.
 * @details This function is reentrant and starts the capturing of timer values on the edges
 *          activated by the service Icu_SetActivationCondition() to an external buffer.
 *
 * @param[in]     Channel          Logical number of the ICU channel
 * @param[in]     BufferPtr        Pointer to the buffer-array where the timestamp values shall be
 *                                 placed.
 * @param[in]     BufferSize       Size of the external buffer (number of entries)
 * @param[in]     NotifyInterval   Notification interval (number of events).
 * 
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 */
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval);

/**
* @brief   This function stops the timestamp measurement of the given channel.
* @details This function is reentrant and stops the timestamp measurement of the given channel.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @pre Icu_Init must be called before.
**/
void Icu_StopTimestamp(Icu_ChannelType Channel);

/**
 * @brief   This function reads the timestamp index of the given channel.
 * @details This service is reentrant and read the timestamp index of the given channel, 
 *          which is the next to be written. 
 *          This function shall return "0" in case the service is called before Icu_StartTimestamp()
 *
 * @param[in]  Channel          Logical number of the ICU channel
 *
 * @return     Icu_IndexType -  Abstract return type to cover different microcontrollers.
 *
 * @pre        Icu_Init must be called before the given channel must be configured in Measurement
 *             Mode ICU_MODE_TIMESTAMP. Icu_StartTimestamp must be called before.
 *
 */
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel);

#endif /* ICU_TIMESTAMP_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief   This function resets the value of the counted edges to zero.
* @details This function is reentrant and resets the value of the counted edges to zero.
*
* @param[in]     Channel          Logical number of the ICU channel.
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.
*
* @implements Icu_ResetEdgeCount_Activity
*
**/
void Icu_ResetEdgeCount(Icu_ChannelType Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief   This function enables the counting of edges of the given channel.
* @details This service is reentrant and shall enable the counting of  edges of the given channel.
*          Note: This  service does not do the real counting itself. This is done by the hardware
*          (capture unit). Only the configured edges shall be counted (rising edge, falling edge or
*           both edges).
*
*          Configuration  of  the  edge  is  done  in  Icu_Init  or  Icu_SetActivationCondition.The
*          configured edge can be  changed during runtime using  Icu_SetActivationCondition.
*          Interrupts are not required for edge counting.If interrupts are enabled, the interrupt
*          service routine
*          will set the overflow flag if more than 0xFFFFFF edges are measured.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The given channel must be configured in Measurement Mode
*      Edge Counter.
* @implements Icu_EnableEdgeCount_Activity
*
**/
void Icu_EnableEdgeCount(Icu_ChannelType Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief   This function disables the counting of edges of the given channel.
* @details This function is reentrant and disables the counting of edges of the given channel.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.The given channel must be configured in Measurement
*      Mode Edge Counter.
*
* @implements Icu_DisableEdgeCount_Activity
*
**/
void Icu_DisableEdgeCount(Icu_ChannelType Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief   This function reads the number of counted edges.
* @details This function is reentrant reads the number of counted edges after the last call
*          of Icu_ResetEdgeCount().
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return Icu_EdgeNumberType - Number of the counted edges.
*
* @api
*
* @pre Icu_Init must be called before. The given channel must be configured in Measurement
*      Mode Edge Counter.
*
* @implements Icu_GetEdgeNumbers_Activity
**/
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel);
#endif /* ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_COUNT_API)
#if (defined ICU_SET_INITIAL_COUNTER)
#if (STD_ON == ICU_SET_INITIAL_COUNTER)
/**
* @brief   Icu driver function that Set Initial setting of eMIOS Counter.
* @details This function Set Initial setting of eMIOS Counter
*
* @param[in]  Channel                Logical number of the ICU channel
* @param[in]  InitialCounterValue    eMios Initial counter value
*
* @return void
*
* @api
*
* @pre        This function is not required because the counter value is 
*             set automatically. But to arbitrarily change the Initial value 
*             of the counter value, it is necessary to call this function before 
*             the Icu_EnableEdgeCount function. After call Icu_ResetEdgeCount
*             function to reset counter value to 0, the previously set Initial
*             value will no longer be valid.
*
* @implements Icu_SetInitialCounterValue_Activity
**/
void Icu_SetInitialCounterValue(Icu_ChannelType Channel, uint32 InitialCounterValue);
#endif  /* STD_ON == ICU_SET_INITIAL_COUNTER */
#endif  /* ICU_SET_INITIAL_COUNTER */
#endif /* STD_ON == ICU_EDGE_COUNT_API */
#if (STD_ON == ICU_EDGE_COUNT_API)
#if (defined ICU_SET_MAX_COUNTER)
#if (STD_ON == ICU_SET_MAX_COUNTER)
/**
* @brief   Icu driver function that Set Max setting of eMIOS Counter.
* @details This function Set Max setting of eMIOS Counter
*
* @param[in]  Channel                Logical number of the ICU channel
* @param[in]  MaxCounterValue        eMios Max counter value
*
* @return void
*
* @api
*
 * @pre        This function is not required because the counter value is 
 *             set automatically. But to arbitrarily change the Max value 
 *             of the counter value, it is necessary to call this function before 
 *             the Icu_EnableEdgeCount function.
*
* @implements Icu_SetMaxCounterValue_Activity
**/
void Icu_SetMaxCounterValue(Icu_ChannelType Channel, uint32 MaxCounterValue);
#endif  /* STD_ON == ICU_SET_MAX_COUNTER */
#endif  /* ICU_SET_MAX_COUNTER */
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief   This function enables or re-enables the detection of edges of the given channel.
* @details This function is reentrant enables or re-enables the detection of edges of the given
*          channel.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Edge
*      Counter
*
* @implements Icu_EnableEdgeDetection_Activity
**/
void Icu_EnableEdgeDetection(Icu_ChannelType Channel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief   This function disables the detection of edges of the given channel.
* @details This function is reentrant and disables the detection of edges of the given channel.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Edge
*      Detection.
*
* @implements Icu_DisableEdgeDetection_Activity
*
**/
void Icu_DisableEdgeDetection(Icu_ChannelType Channel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_TIME_ELAPSED_API== STD_ON)
/**
* @brief   This function reads the elapsed Signal Low, High or Period Time for the given channel.
* @details This service is reentrant and reads the elapsed Signal Low Time for the given channel
*          that is configured  in Measurement Mode Signal Measurement, Signal Low Time.
*          The elapsed time is measured between a falling edge and the consecutive rising edge of
*          the channel.
*          This service reads the elapsed Signal High Time for the given channel that is configured
*          in Measurement Mode Signal Measurement,Signal High Time.The elapsed time is measured
*          between a rising edge and the consecutive falling edge of the channel.
*          This service reads the elapsed Signal Period Time for the given channel that is
*          configured in Measurement Mode Signal Measurement,  Signal Period Time.The elapsed time
*          is measured between consecutive  rising (or falling) edges  of the  channel. The  period
*          start edge is
*
*          configurable.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return Icu_ValueType -  the elapsed Signal Low Time for the given channel that is configured in
*          Measurement Mode Signal Measurement, Signal Low Time
*
* @api
*
* @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Signal
*      Measurement.
*
* @implements Icu_GetTimeElapsed_Activity
*
**/
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel);
#endif /* ICU_GET_TIME_ELAPSED_API */


#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/**
 * @brief   This function reads the coherent active time and period time for the given ICU Channel.
 * @details The function is reentrant and reads the coherent active time and period time for
 *          the given ICU Channel, if it is configured in Measurement Mode Signal Measurement, Duty
 *          Cycle Values.
 *
 * @param[in]     Channel          Logical number of the ICU channel
 * @param[out]    DutyCycleValues  Pointer to a buffer where the results (high time and period time)
 *                                 shall be placed.
 *
 * @return     void
 * @pre        Icu_Init must be called before. The given channel must be configured in Measurement Mode
 *             Signal Measurement, Duty Cycle Values.
 */
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues);

#endif /* ICU_GET_DUTY_CYCLE_VALUES_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief   This function starts the measurement of signals.
* @details This service is reentrant and starts the measurement of signals beginning with the
*          configured default start edge which occurs first after the call of this service.
*          This service shall only be available in Measurement Mode ICU_MODE_SIGNAL_MEASUREMENT.
*          This service shall reset the state for the given channel to ICU_IDLE.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Signal
*      Measurement.
*
* @implements Icu_StartSignalMeasurement_Activity
*
**/
void Icu_StartSignalMeasurement(Icu_ChannelType Channel);

/**
 * @brief      This function stops the measurement of signals of the given channel.
 * @details    This function is reentrant and stops the measurement of signals of the given channel.
 * 
 * @param[in]  Channel - Logical number of the ICU channel
 * @return     void
 * 
 * @pre        Icu_Init must be called before. The channel must be configured in Measurement Mode 
 *             Signal Measurement.
 */
void Icu_StopSignalMeasurement(Icu_ChannelType Channel);
#endif /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_GET_VERSION_INFO_API == STD_ON)
/**
* @brief   This service returns the version information of this module.
* @details This  service is Non reentrant and returns the version information of this module.
*          The version information includes:
*          - Module Id
*          - Vendor Id
*          - Vendor specific version numbers
*          If source code for caller and callee of this function is available this function should
*          be realized as a macro. The macro should be defined in the modules header file.
*
* @param[out]    versioninfo      Pointer to location to store version info
*
* @return void
*
* @api
*
* @implements Icu_GetVersionInfo_Activity
**/
void Icu_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif  /* ICU_GET_VERSION_INFO_API == STD_ON */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @brief This function sets all channels prescalers based on the input mode.
 * 
 * @param   selectPrescaler Select the used prescaler: prescaler/alternatePresclaer.
 * @return  void
 * @pre     Icu_Init must be called before.
 */
void Icu_SetClockMode(Icu_SelectPrescalerType selectPrescaler);
#endif  /* ICU_DUAL_CLOCK_MODE_API == STD_ON */


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief      This function returns the actual status of PIN.
*
* @details    This function returns the actual status of PIN.
*
* @param[in]     Channel    Logical number of the ICU channel
*
* @return  Icu_LevelType
*
* @pre        Icu_Init must be called before.
*
* @implements Icu_GetInputLevel_Activity
*
**/
Icu_LevelType Icu_GetInputLevel(Icu_ChannelType Channel);
#endif

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || \
                                                                    (ICU_TIMESTAMP_API == STD_ON)))
/**
* @brief   This function starts the measurement of signals.
* @details. This service returns the value of Capture register.
*   This API is used to measure the time difference  between 2 different timer channels.
*
* @param[in]    Channel     Logical number of the ICU channel
*
* @return Icu_ValueType     Value of Capture register
* @api
* @pre Icu_Init must be called before.
* @pre The given channel must be configured in SignalMeasurement or in Timestamp mode
* @implements Icu_GetCaptureRegisterValue_Activity
*
**/
Icu_ValueType Icu_GetCaptureRegisterValue(Icu_ChannelType Channel);
#endif

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief      This function returns the signals High time, Low time and Period without using the
*             channel interrupt.
* @details    This function returns the signals High time, Low time and Period without using the
*             channel interrupt.
* @param[in]  Channel       Logical number of the ICU channel
* @pre        Icu_Init must be called before.
*
**/
void Icu_GetPulseWidth(Icu_ChannelType Channel);
#endif



#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_H */
