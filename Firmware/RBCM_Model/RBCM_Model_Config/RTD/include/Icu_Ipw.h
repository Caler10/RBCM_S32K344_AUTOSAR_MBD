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

#ifndef ICU_IPW_H
#define ICU_IPW_H

/**
 *     @file
 *     @internal
 *     @addtogroup icu_ipw Icu_Ipw Driver
 *     @{
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
#include "Icu_Cfg.h"
#include "Icu_Types.h"
#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_VENDOR_ID                       43
#define ICU_IPW_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_AR_RELEASE_MINOR_VERSION        7
#define ICU_IPW_AR_RELEASE_REVISION_VERSION     0
#define ICU_IPW_SW_MAJOR_VERSION                5
#define ICU_IPW_SW_MINOR_VERSION                0
#define ICU_IPW_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_CFG_VENDOR_ID)
    #error "Icu_Ipw.h and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION  != ICU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION  != ICU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION   != ICU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.h and Icu_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION  != ICU_CFG_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION  != ICU_CFG_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION  != ICU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.h and Icu_Cfg.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu_Ipw.h and Icu_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION  != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION  != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION   != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.h and Icu_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION  != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION  != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION  != ICU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.h and Icu_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Ipw.h and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION  != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION  != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION   != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.h and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION  != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION  != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION  != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.h and Icu_Ipw_Types.h are different"
#endif

/* Check if current file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Ipw.h and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if current file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION    != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION    != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.h and Icu_Ipw_Types.h are different"
#endif
/* Check if current file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION != ICU_IPW_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Icu_Ipw.h and Icu_Ipw_Types.h are different"
#endif

/* Check if current file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_IPW_CFG_VENDOR_ID)
    #error "Icu_Ipw.h and Icu_Ipw_Cfg.h have different vendor IDs"
#endif
/* Check if current file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION    != ICU_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION    != ICU_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION != ICU_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.h and Icu_Ipw_Cfg.h are different"
#endif
/* Check if current file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION != ICU_IPW_CFG_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION != ICU_IPW_CFG_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION != ICU_IPW_CFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of Icu_Ipw.h and Icu_Ipw_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @internal
* @brief                Icu_Ipw_Init
* @details              Initialize a hardware Icu IP Instance
*
* @param[in]            count       - Number of instances to be configured
* @param[in]            pIpConfig   - Pointer that contains IP specific configuration data for the Icu driver
*
* @return void
*
* @pre                  Icu_DeInit must be called before.
*
*/
void Icu_Ipw_Init(uint8 count, const Icu_Ipw_IpConfigType (*pIpConfig)[]);

#if (ICU_DE_INIT_API == STD_ON)
/**
* @brief              Icu_Ipw_DeInit
* @details            De-initialize ICU hardware channel
*
* @param[in]          pIpConfig - Pointer to ICU top configuration structure
*
* @internal
* @return void
*
* @pre                Icu_Init must be called before.
*
*/
void Icu_Ipw_DeInit(uint8 count, const Icu_Ipw_IpConfigType (*pIpConfig)[]);
#endif /* ICU_DE_INIT_API == STD_ON */

#if (ICU_SET_MODE_API == STD_ON)
/**
 * @brief Put the channel in a reduce power state.
 * 
 * @internal
 * @param channelConfig - configuration of the channel
 */
void Icu_Ipw_SetSleepMode(const Icu_Ipw_ChannelConfigType * ChannelConfig);

/**
 * @brief Set the channel to run again.
 * 
 * @internal
 * @param channelConfig - configuration of the channel
 */
void Icu_Ipw_SetNormalMode(const Icu_Ipw_ChannelConfigType * ChannelConfig);
#endif  /* ICU_SET_MODE_API == STD_ON */

/**
* @brief      Icu_Ipw_SetActivationCondition
* @details
*
* @param[in]      activation    - the type of activation for the ICU channel.
* @param[in]      ChannelConfig            - the measurement mode of the channel
*
* @internal
* @return void
*
*/
void Icu_Ipw_SetActivationCondition(Icu_ActivationType activation,
                                    const Icu_Ipw_ChannelConfigType* ChannelConfig);

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu_Ipw_GetInputState
* @details    Service that returns the state of the ICU driver
*
* @param[in]      ChannelConfig - The current channel configuration structure
*
* @internal
* @return Icu_InputStateType
* @retval   ICU_ACTIVE          An active edge has been detected
* @retval   ICU_IDLE            No active edge has been detected since the cast call to
*                               Icu_Ipw_Init or Icu_Ipw_GetInputState
*/
boolean Icu_Ipw_GetInputState (const Icu_Ipw_ChannelConfigType *ChannelConfig);
#endif  /* ICU_GET_INPUT_STATE_API == STD_ON */

#if (STD_ON == ICU_TIMESTAMP_API)
/**
 * @brief 
 * @internal
 * @param channelConfig 
 * @param bDmaSupport 
 */
void Icu_Ipw_StartTimestamp(const Icu_Ipw_ChannelConfigType* channelConfig,
                            Icu_ValueType* bufferPtr,
                            uint16  bufferSize,
                            uint16  notifyInterval);

/**
 * @brief 
 * @internal
 * @param channelConfig 
 */
void Icu_Ipw_StopTimestamp(const Icu_Ipw_ChannelConfigType *channelConfig);

/**
 * @brief 
 * 
 * @param channelConfig 
 * @return uint16 
 */
uint16 Icu_Ipw_GetTimestampIndex(const Icu_Ipw_ChannelConfigType* channelConfig);
#endif  /* ICU_TIMESTAMP_API == STD_ON */

#if ((ICU_TIMESTAMP_USES_DMA == STD_ON) || (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON))
uint32 Icu_Ipw_GetStartAddress(const Icu_Ipw_ChannelConfigType *ChannelConfig);
#endif  /* ICU_TIMESTAMP_USES_DMA == STD_ON || ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON*/

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
Icu_ValueType Icu_Ipw_GetIPVMaxCouter(const Icu_Ipw_ChannelConfigType *ChannelConfig);
#endif  /* ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON */

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @brief
 * @internal
 * @param ChannelConfig 
 */
void Icu_Ipw_ResetEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig);

/**
 * @brief 
 * @internal
 * @param ChannelConfig 
 */
void Icu_Ipw_EnableEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig);

/**
 * @brief 
 * @internal
 * @param ChannelConfig 
 */
void Icu_Ipw_DisableEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig);

/**
 * @brief 
 * @internal
 * @param ChannelConfig 
 * @return uint16 
 */
Icu_EdgeNumberType Icu_Ipw_GetEdgeNumbers(const Icu_Ipw_ChannelConfigType *ChannelConfig);

#if (defined ICU_SET_INITIAL_COUNTER)
#if (STD_ON == ICU_SET_INITIAL_COUNTER)
/**
 * @brief 
 * @internal
 * @param ChannelConfig 
 * @param InitialCounterValue 
 */
void Icu_Ipw_SetInitialCounterValue(const Icu_Ipw_ChannelConfigType *ChannelConfig, uint32 InitialCounterValue);
#endif  /* STD_ON == ICU_SET_INITIAL_COUNTER */
#endif  /* ICU_SET_INITIAL_COUNTER */

#if (defined ICU_SET_MAX_COUNTER)
#if (STD_ON == ICU_SET_MAX_COUNTER)
/**
 * @brief 
 * @internal
 * @param ChannelConfig 
 * @param MaxCounterValue 
 */
void Icu_Ipw_SetMaxCounterValue(const Icu_Ipw_ChannelConfigType *ChannelConfig, uint32 MaxCounterValue);
#endif  /* STD_ON == ICU_SET_MAX_COUNTER */
#endif  /* ICU_SET_MAX_COUNTER */

#endif  /* STD_ON == ICU_EDGE_COUNT_API */


#if (STD_ON == ICU_EDGE_DETECT_API)
void Icu_Ipw_EnableEdgeDetection(const Icu_Ipw_ChannelConfigType * ChannelConfig);
void Icu_Ipw_DisableEdgeDetection(const Icu_Ipw_ChannelConfigType* ChannelConfig);
#endif


#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
/**
 * @brief The function get the state of the overflow flag
 * @internal
 * @param ChannelConfig      Channel configuration pointer
 * @return      boolean      the state of the overflow flag
 * @retval      TRUE         the overflow flag is set
 * @retval      FALSE        the overflow flag is not set
 */
boolean Icu_Ipw_Get_Overflow(const Icu_Ipw_ChannelConfigType* ChannelConfig);
#endif

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))/**
 * @brief      Capture the value of counter register for a specified channel.
 * 
 * @details   The API shall return the value stored in capture register.
 *            The API is the equivalent of AUTOSAR API GetCaptureRegisterValue.
 * 
 * @param ChannelConfig      Channel configuration pointer
 * @return     uint32  Value of the register captured.
 */
Icu_ValueType Icu_Ipw_GetCaptureRegisterValue(const Icu_Ipw_ChannelConfigType* ChannelConfig);
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
 * @brief
 * @internal
 * @param channelConfig 
 */
void Icu_Ipw_StartSignalMeasurement(const Icu_Ipw_ChannelConfigType *ChannelConfig);

/**
 * @brief 
 * @internal
 * @param channelConfig 
 */
void Icu_Ipw_StopSignalMeasurement(const Icu_Ipw_ChannelConfigType * ChannelConfig);

void Icu_Ipw_SetPWandPeriod(const Icu_Ipw_ChannelConfigType* channelConfig, \
                            Icu_ValueType Icu_aActivePulseWidth, \
                            Icu_ValueType Icu_aPeriod);
#endif /* STD_ON == ICU_SIGNAL_MEASUREMENT_API */

#if (STD_ON == ICU_DUAL_CLOCK_MODE_API)
/**
 * @brief 
 * @internal
 * @param moduleConfig 
 * @param selectPrescaler 
 * @param modulesNumber 
 */
void Icu_Ipw_SetClockMode(const Icu_Ipw_IpConfigType (*moduleConfig)[], Icu_SelectPrescalerType selectPrescaler, 
                          uint8 modulesNumber);
#endif /* STD_ON == ICU_DUAL_CLOCK_MODE_API */

#if (STD_ON == ICU_GET_INPUT_LEVEL_API)
/**
 * @brief Mapping macro between IP input level functionality and HL function.
 * @internal
 * @param channelConfig 
 * @return Icu_LevelType 
 */
Icu_LevelType Icu_Ipw_GetInputLevel(const Icu_Ipw_ChannelConfigType * ChannelConfig);
#endif   /* STD_ON == ICU_GET_INPUT_LEVEL_API */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
/**
 * @brief 
 * @internal
 * @param channelConfig 
 * @return Icu_Ipw_StatusType 
 */
Icu_Ipw_StatusType Icu_Ipw_ValidateGetInputLevel(const Icu_Ipw_ChannelConfigType * ChannelConfig);
#endif

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
/**
 * @brief 
 * 
 * @param channelConfig 
 * @param DutyCycleValues 
 * @internal
 */
void Icu_Ipw_GetDutyCycleValues(const Icu_Ipw_ChannelConfigType* channelConfig,
                                Icu_DutyCycleType* DutyCycleValues);
#endif /* STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API */


#if (STD_ON == ICU_GET_TIME_ELAPSED_API)
/**
 * @brief 
 * 
 * @param channelConfig 
 * @return Icu_ValueType 
 * @internal
 */
Icu_ValueType Icu_Ipw_GetTimeElapsed(const Icu_Ipw_ChannelConfigType* channelConfig);
#endif /* STD_ON == ICU_GET_TIME_ELAPSED_API */


/**
 * @brief      Icu_Ipw_EnableNotification
 * @details    Enable Notification for timestamp
 *
 * @param[in]  ChannelConfig - The index of ICU channel for current configuration structure
 *
 * @internal
 * @return void
 */
void Icu_Ipw_EnableNotification(const Icu_Ipw_ChannelConfigType* ChannelConfig);

/**
 * @brief      Icu_Ipw_DisableNotification
 * @details    Disable Notification for timestamp
 *
 * @param[in]  ChannelConfig - The index of ICU channel for current configuration structure
 *
 * @internal
 * @return void
 */
void Icu_Ipw_DisableNotification(const Icu_Ipw_ChannelConfigType* ChannelConfig);

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
Std_ReturnType Icu_Ipw_ValidateSignalMeasureWithoutInterrupt(const Icu_Ipw_ChannelConfigType * ChannelConfig);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
void Icu_Ipw_GetPulseWidth(const Icu_Ipw_ChannelConfigType * ChannelConfig);
#endif /* (ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_IPW_H */
