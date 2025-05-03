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
#include "OsIf.h"
#include "Icu.h"
#include "Icu_EnvCfg.h"
#include "Icu_Ipw.h"
#include "Icu_Irq.h"

#include "SchM_Icu.h"
#if ((ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_TIMESTAMP_API == STD_ON))
    #include "Det.h"
#endif

/*==================================================================================================
*                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_C                     43
#define ICU_AR_RELEASE_MAJOR_VERSION_C      4
#define ICU_AR_RELEASE_MINOR_VERSION_C      7
#define ICU_AR_RELEASE_REVISION_VERSION_C   0
#define ICU_SW_MAJOR_VERSION_C              5
#define ICU_SW_MINOR_VERSION_C              0
#define ICU_SW_PATCH_VERSION_C              0

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((ICU_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu.c and Mcal.h are different"
    #endif

    /* Check if source file and SchM_Icu.h file are of the same Autosar version */
    #if ((ICU_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu.c and SchM_Icu.h are different"
    #endif

    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((ICU_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of  and OsIf.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_VENDOR_ID)
    #error "Icu.c and Icu.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.c and Icu.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu.h are different"
#endif

/* Check if source file and Icu_EnvCfg header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_ENVCFG_VENDOR_ID)
    #error "Icu.c and Icu_EnvCfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same AutoSar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.c and Icu_EnvCfg.h are different"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_ENVCFG_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_ENVCFG_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_ENVCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_EnvCfg.h are different"
#endif

/* Check if source file and ICU IPW header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
#error "Icu.c and Icu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw header file are of the same version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Icu.c and Icu_Ipw.h are different"
#endif
/* Check if source file and Icu_Ipw header file are of the same Software Version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_Ipw.h are different"
#endif

/* Check if source file and DET header file are of the same version */
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((ICU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu.c and Det.h are different"
        #endif
    #endif
#endif /* ICU_DEV_ERROR_DETECT */

/* Check if source file and ICU IRQ header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_IRQ_VENDOR_ID)
    #error "Icu.c and Icu_Irq.h have different vendor IDs"
#endif
/* Check if source file and ICU IRQ header file are of the same version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.c and Icu_Irq.h are different"
#endif
/* Check if source file and ICU IRQ header are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_IRQ_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_IRQ_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_Irq.h are different"
#endif
/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON))
typedef enum
{
    ICU_STATE_UNINIT = 0x00,
    ICU_STATE_IDLE
} Icu_eGlobalStateType;
#endif /* ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)) */

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#if (ICU_MULTIPARTITION_SUPPORT == STD_ON)
    #define Icu_GetUserID()   (uint32)OsIf_GetUserId()
#else
    #define Icu_GetUserID()   ((uint32)0UL)
#endif

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
/**
* @brief      This function ends the validation of calling a function on a channel
* @details    This service is a non reentrant function on channel used for ending the validation
*                for the calls for functions that use one channel
*
* @param[in]   validation The function call was previously validated
*
* @return void
*
* where they are interchangeable.
*/
#define Icu_EndValidateCallAndChannel(validation)
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)*/

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/
#if (ICU_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON))
static Icu_eGlobalStateType Icu_GlobalState[ICU_MAX_PARTITIONS];
#endif /* ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)) */

#if (ICU_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Icu_MemMap.h"

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/** @brief Array for saving value of DMA **/
static volatile Icu_ValueType Icu_aDmaBuffer[ICU_MAX_CHANNEL][ICU_DMA_MAJORLOOP_COUNT];

/** @brief Array for saving the period */
static volatile Icu_ValueType Icu_aIsSecondInterrupt[ICU_MAX_CHANNEL];

/** @brief Array for saving the period */
static volatile Icu_ValueType Icu_aFirstEdgeTimeStamp[ICU_MAX_CHANNEL];

#endif /* ICU_SIGNALMEASUREMENT_USES_DMA */

#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#ifdef ICU_PRECOMPILE_SUPPORT

#if (ICU_MULTIPARTITION_SUPPORT == STD_ON)
extern const Icu_ConfigType* const Icu_Config[ICU_MAX_PARTITIONS];
#else
extern const Icu_ConfigType Icu_Config;
#endif

#endif /*ICU_PRECOMPILE_SUPPORT*/

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/
#if (ICU_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

/** @brief Pointer initialized during init with the address of the received configuration structure.
  *        Will be used by all functions to access the configuration data. */
const Icu_ConfigType * Icu_pCfgPtr[ICU_MAX_PARTITIONS];

/** @brief Saves the current Icu mode. */
Icu_ModeType              Icu_CurrentMode[ICU_MAX_PARTITIONS];

/** @brief Stores actual state and configuration of ICU Channels. */
volatile Icu_ChannelStateType Icu_aChannelState[ICU_MAX_CHANNEL];

#if (STD_ON == ICU_TIMESTAMP_API)
/** @brief Pointer to the buffer-array where the timestamp values shall be placed. */
Icu_ValueType            *Icu_aBuffer[ICU_MAX_CHANNEL];

/** @brief Array for saving the size of the external buffer (number of entries). */
uint16                   Icu_aBufferSize[ICU_MAX_CHANNEL];

/** @brief Array for saving Notification interval (number of events). */
uint16                   Icu_aBufferNotify[ICU_MAX_CHANNEL];

/** @brief Array for saving the number of notify counts. */
volatile uint16          Icu_aNotifyCount[ICU_MAX_CHANNEL];

/** @brief Array for saving the time stamp index. */
volatile Icu_IndexType   Icu_aBufferIndex[ICU_MAX_CHANNEL];
#endif /* ICU_TIMESTAMP_API */

#if (ICU_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief     Icu_SetBitChState
 * @details   Set the Icu_aChannelState bitfield specified by mask parameter in an atomic way.
 *
 * @param[in] Channel   - The logical number of ICU channel for current configuration structure
 * @param[in] mask      - bitfield mask
 *
 * @return void
 */
static inline void Icu_SetBitChState(Icu_ChannelType Channel, Icu_ChannelStateType mask);

static inline Icu_ChannelStateType Icu_GetBitChState(Icu_ChannelType Channel, Icu_ChannelStateType mask);

static inline void Icu_ClearBitChState(Icu_ChannelType Channel, Icu_ChannelStateType mask);

#if (STD_ON == ICU_VALIDATE_GLOBAL_CALL)
static inline Std_ReturnType Icu_ValidateGlobalCall(uint8 u8ServiceId, uint32 u32UserID);

static inline void Icu_EndValidateGlobalCall(Std_ReturnType validation, uint8 u8ServiceId, uint32 u32UserID);
#endif

#if ((STD_ON == ICU_VALIDATE_GLOBAL_CALL) && (STD_ON == ICU_SET_MODE_API))
static inline Std_ReturnType Icu_ValidateCallSetMode(Icu_ModeType Mode, uint32 u32UserID);
#endif

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
static inline Std_ReturnType Icu_ValidateCallAndChannel(Icu_ChannelType Channel, uint8 u8ModeMask,
                                                        uint8 u8ServiceId, uint32 u32UserID
                                                       );
#endif

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON))
#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
static inline boolean Icu_GetOverflow(Icu_ChannelType Channel,
                                                     uint8 u8ServiceId,
                                                     uint8 u8Error,
                                                     uint32 u32UserID
                                                    );
#endif
#endif  /* ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON) */

#if (ICU_VALIDATE_PARAMS == STD_ON)
static inline Std_ReturnType Icu_ValidatePtrInit(uint32 u32UserID,
                                                                const Icu_ConfigType * ConfigPtr
                                                               );
#endif /* (ICU_VALIDATE_PARAMS == STD_ON)*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON))
static inline Std_ReturnType Icu_ValidateMode(Icu_ModeType Mode);
#endif /*(ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON*/

#if((ICU_VALIDATE_PARAMS == STD_ON) && \
    ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) || (ICU_ENABLE_WAKEUP_API == STD_ON)|| \
     (ICU_DISABLE_WAKEUP_API == STD_ON)))

static inline Std_ReturnType Icu_ValidateWakeupChannel(Icu_ChannelType Channel,
                                                                      uint8 u8ServiceId,
                                                                      uint32 u32UserID
                                                                     );
#endif /* ICU_VALIDATE_PARAMS == STD_ON */

#if (ICU_VALIDATE_PARAMS == STD_ON)
static inline Std_ReturnType Icu_ValidateActivation(Icu_ActivationType Activation);
#endif /* ICU_VALIDATE_PARAMS == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON))
static inline Std_ReturnType Icu_ValidateTimestamp(Icu_ChannelType Channel,
                                                                  const Icu_ValueType * pBufferPtr,
                                                                  uint16 u16BufferSize,
                                                                  uint16 u16NotifyInterval,
                                                                  uint32 u32UserID
                                                                 );
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON) */


#if (ICU_TIMESTAMP_API == STD_ON)
static inline Std_ReturnType Icu_ValidateChannelStartState(Icu_ChannelType Channel);
#endif /* ICU_TIMESTAMP_API == STD_ON */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && \
        ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)))
static inline Std_ReturnType Icu_ValidateSignalMeasurementProperty(Icu_ChannelType Channel,
                                                                                  uint16 u16ModePropertyMask,
                                                                                  uint8  u8ServiceId,
                                                                                  uint32 u32UserID
                                                                                 );
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (...) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
static inline Std_ReturnType Icu_ValidatePtrDutyCycle(const Icu_DutyCycleType * DutyCycleValues);
#endif /* ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON))
static inline Std_ReturnType Icu_ValidateVersionInfoCall(const Std_VersionInfoType * versioninfo);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON */


#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON))
static inline Std_ReturnType Icu_ValidateClockModeCall(Icu_SelectPrescalerType Prescaler);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
static inline Std_ReturnType Icu_ValidateGetInputLevel(Icu_ChannelType Channel,
                                                       uint32 u32UserID);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
static inline Std_ReturnType Icu_ValidateModeForSetUpFeature(uint8 u8ApiId);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
static inline Std_ReturnType Icu_ValidateSignalMeasureWithoutInterrupt(Icu_ChannelType Channel,
                                                                       uint8  u8ServiceId,
                                                                       uint32 u32UserID);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/
static inline void Icu_CallNotification(Icu_ChannelType Channel, uint32 u32UserID);

static inline Icu_ChannelType Icu_ConvertChannelIndexToChannel(Icu_ChannelType ChannelIndex, uint32 u32UserID);

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
static inline void Icu_UpdateTimestampMclDma(Icu_ChannelType ChannelId,
                                             const Icu_ValueType* BufferPtr,
                                             uint16 BufferSize,
                                             uint16 NotifyInterval);
#endif /* ICU_TIMESTAMP_USES_DMA == STD_ON */

/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
static inline void Icu_SetBitChState(Icu_ChannelType Channel, Icu_ChannelStateType mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    {
        Icu_aChannelState[Channel] |= mask;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
}

/**
 * @brief      Icu_GetBitChState
 * @details    Return the Icu_aChannelState bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]  Channel  - The logical number of ICU channel for current configuration structure
 * @param[in]  mask     - bitfield mask
 * @return     Bitfield specified by mask parameter
 * @retval     ICU_CHANNEL_STATE_WKUP Wakeup feature is currently enabled
 * @retval     ICU_CHANNEL_STATE_IDLE The current channel status is idle
 * @retval     ICU_CHANNEL_STATE_NOTIFICATION Notification is enabled
 * @retval     ICU_CHANNEL_STATE_RUNNING The current channel state is Running
 *
 */
static inline Icu_ChannelStateType Icu_GetBitChState(Icu_ChannelType Channel, Icu_ChannelStateType mask)
{
    return (uint8)(Icu_aChannelState[Channel] & mask);
}

/**
 * @brief      Icu_ClearBitChState
 * @details    Clear the Icu_aChannelState bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]  Channel   - The logical number of ICU channel for current configuration structure
 * @param[in]  mask      - bitfield mask
 *
 * @return void
 */
static inline void Icu_ClearBitChState(Icu_ChannelType Channel, Icu_ChannelStateType mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01();
    {
        Icu_aChannelState[Channel] &= ((Icu_ChannelStateType)(~mask));
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01();
}

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for functions
 *                that uses all the channels - Icu_Init, Icu_DeInit, Icu_SetMode.
 *
 * @param[in]   u8ServiceId           The service id of the caller function
 * @param[in]   u32UserID             The number of current partition ID
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Icu_ValidateGlobalCall_Activity
 *
 * */
static inline Std_ReturnType Icu_ValidateGlobalCall(uint8 u8ServiceId,
                                                    uint32 u32UserID)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if (ICU_STATE_UNINIT == Icu_GlobalState[u32UserID])
    {
        if (ICU_INIT_ID != u8ServiceId)
        {
            (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_UNINIT);
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if (ICU_INIT_ID == u8ServiceId)
        {
            (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_ALREADY_INITIALIZED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    return valid;
}
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if (STD_ON == ICU_VALIDATE_GLOBAL_CALL)
/**
 * @brief      This function ends the validation of the global call.
 * @details    This service is a non reentrant function used for end the validation the calls for
 *             functions that uses all the channels - Icu_Init, Icu_DeInit, Icu_SetMode.
 *
 * @param[in]   u8ServiceId     The service id of the caller function
 * @param[in]   validation      The function call was previously validated
 * @param[in]   u32UserID       The number of current partition ID
 *
 * @return void
 *
 */
static inline void Icu_EndValidateGlobalCall(Std_ReturnType validation, uint8 u8ServiceId, uint32 u32UserID)
{
    if ((Std_ReturnType)E_OK == validation)
    {
        if (ICU_DEINIT_ID == u8ServiceId)
        {
            Icu_GlobalState[u32UserID] = ICU_STATE_UNINIT;
        }
        else
        {
            Icu_GlobalState[u32UserID] = ICU_STATE_IDLE;
        }
    }
}
#endif /* STD_ON == ICU_VALIDATE_GLOBAL_CALL */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
 * @brief      This function checks if running operations are performed while changing the Icu mode
 *
 * @param[in]   Mode        The mode that user wants to change to
 * @param[in]   u32UserID   The number of current partition ID
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 * @implements Icu_ValidateCallSetMode_Activity
 */
static inline Std_ReturnType Icu_ValidateCallSetMode(Icu_ModeType Mode, uint32 u32UserID)
{
    Icu_ChannelType Channel;
    Icu_ChannelType ChannelIndex;
    Std_ReturnType valid = (Std_ReturnType)E_OK;
    boolean bChRunning  = FALSE;

    /*Check that there is no channel that is running and is not wake-up capable*/
    if (Mode != Icu_CurrentMode[u32UserID])
    {

        for (ChannelIndex = 0U; ChannelIndex < Icu_pCfgPtr[u32UserID]->nNumChannels; ChannelIndex++)
        {
            /* Call low level function. */
            Channel = Icu_ConvertChannelIndexToChannel(ChannelIndex, u32UserID);
            if((ICU_CHANNEL_STATE_RUNNING == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING|ICU_CHANNEL_STATE_WKUP)))
            {
                bChRunning  = TRUE;
                (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_SETMODE_ID, ICU_E_BUSY_OPERATION);
                break;
            }

        }
        valid = (TRUE == bChRunning)? (Std_ReturnType)E_NOT_OK : (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /*((ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) && #if (ICU_SET_MODE_API == STD_ON))*/

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
/**
 * @brief       This function validates the call for a specific channel
 * @details     This service is a non reentrant function on channel used for validating the calls
 *              for functions that use one channel
 *
 * @param[in]   Channel          Logical number of the ICU channel
 * @param[in]   ModeMask         The modes that are valid for the specific channel
 * @param[in]   u8ServiceId      The service id of the caller function
 * @param[in]   u32UserID        The number of current partition ID
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateCallAndChannel_Activity
 *
 * */
static inline Std_ReturnType Icu_ValidateCallAndChannel(Icu_ChannelType Channel, uint8 u8ModeMask,
                                                        uint8 u8ServiceId, uint32 u32UserID)
{
    Std_ReturnType valid = (Std_ReturnType)E_NOT_OK;
    uint8 tempMode;
    Icu_ChannelType ChannelIndex;
    uint8 errorId;
    boolean bReportError = FALSE;

    if (ICU_STATE_UNINIT == Icu_GlobalState[u32UserID])
    {
        bReportError = TRUE;
        errorId = ICU_E_UNINIT;
    }
    else
    {
        if(ICU_MAX_CHANNEL <= Channel)
        {
            bReportError = TRUE;
            errorId = ICU_E_PARAM_CHANNEL;
        }
        else
        {
            ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            tempMode = (uint8)((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChannelMode);
            tempMode = (uint8)((uint8)1U << (uint8)tempMode);

            if (ChannelIndex > Icu_pCfgPtr[u32UserID]->nNumChannels)
            {
                bReportError = TRUE;
                errorId = ICU_E_PARAM_CONFIG;
            }
            else if ( (uint8)tempMode != (u8ModeMask & (uint8)tempMode) )
            {
                bReportError = TRUE;
                errorId = ICU_E_PARAM_CHANNEL;
            }
            else
            {
                valid = (Std_ReturnType)E_OK;
            }
        }
    }
    if(bReportError)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, errorId);
    }
    return valid;
}
#endif

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON))
#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
/**
 * @brief      This indicates the overflow status for a specific channel
 * @details    In case the overflow notification is not activated, this service reports the overflow
 *                status on a specific channel
 *
 * @param[in]   Channel              Logical number of the ICU channel
 * @param[in]   u8ServiceId          The service id of the caller function
 * @param[in]   u8Error              The error id that is reported in case of overflow
 * @param[in]   u32UserID            The number of current partition ID
 *
 * @return      Status of the overflow flag
 * @retval      TRUE          an overflow event occurred for the given channel
 * @retval      FALSE         an overflow event has not occurred for a given channel
 */
static inline boolean Icu_GetOverflow(Icu_ChannelType Channel, uint8 u8ServiceId,
                                      uint8 u8Error, uint32 u32UserID
                                     )
{
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    boolean bOverflow        = FALSE;
    boolean bChOverflowState = FALSE;
    uint8   ChannelIndex     = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];

    /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;

    if (ICU_CHANNEL_STATE_OVERFLOW == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW))
    {
        bChOverflowState = TRUE;
    }

    if ((TRUE == Icu_Ipw_Get_Overflow(ChannelConfig)) || (TRUE == bChOverflowState))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, u8ServiceId, u8Error);
        bOverflow = TRUE;
    }
    return bOverflow;
}
#endif
#endif  /* ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON) */

#if (ICU_VALIDATE_PARAMS == STD_ON)
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   ConfigPtr   Pointer to a selected configuration structure.
 *
 * @return                  The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 *
 * */
static inline Std_ReturnType Icu_ValidatePtrInit(uint32 u32UserID, const Icu_ConfigType * ConfigPtr)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

#ifdef ICU_PRECOMPILE_SUPPORT
    if (NULL_PTR != ConfigPtr)
    {
#else
    if (NULL_PTR == ConfigPtr)
    {
#endif /*ICU_PRECOMPILE_SUPPORT*/
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_INIT_ID, ICU_E_INIT_FAILED);
        valid = (Std_ReturnType)E_NOT_OK;
    }
#ifndef ICU_PRECOMPILE_SUPPORT
#if (ICU_MULTIPARTITION_SUPPORT == STD_ON)
    else if (u32UserID != ConfigPtr->u32UserID)
    {
        (void)Det_ReportError((uint16) ICU_MODULE_ID, 0U, ICU_INIT_ID, ICU_E_PARAM_CONFIG);
        valid = (Std_ReturnType)E_NOT_OK;
    }
#endif /*ICU_MULTIPARTITION_SUPPORT*/
    else
    {
        /* Do nothing */
    }
#else
    else
    {
#if (ICU_MULTIPARTITION_SUPPORT == STD_ON)
        if (NULL_PTR == Icu_Config[u32UserID])
        {
            /* Avoid compiler warning */
            (void)u32UserID;
            (void)Det_ReportError((uint16) ICU_MODULE_ID, 0U, ICU_INIT_ID, ICU_E_INIT_FAILED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
        else if (u32UserID != Icu_Config[u32UserID]->u32UserID)
        {
            (void)Det_ReportError((uint16) ICU_MODULE_ID, 0U, ICU_INIT_ID, ICU_E_PARAM_CONFIG);
            valid = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
#endif /*ICU_MULTIPARTITION_SUPPORT*/
    }
#endif /*ICU_PRECOMPILE_SUPPORT*/
    (void)u32UserID;
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON)*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
 * @brief       This function validate the mode that will be set in the driver.
 *
 * @param[in]   Mode        Specifies the operation mode
 *
 * @return                  The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 *
 * @implements  Icu_ValidateMode_Activity
 *
 * */
static inline Std_ReturnType Icu_ValidateMode(Icu_ModeType Mode)
{
    Std_ReturnType valid =  (Std_ReturnType)E_NOT_OK;

    if ((ICU_MODE_SLEEP != Mode) && (ICU_MODE_NORMAL != Mode))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_SETMODE_ID, ICU_E_PARAM_MODE);
    }
    else
    {
        valid = (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /*(ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON*/

#if((ICU_VALIDATE_PARAMS == STD_ON) && \
    ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) || (ICU_ENABLE_WAKEUP_API == STD_ON)|| \
     (ICU_DISABLE_WAKEUP_API == STD_ON)))
/**
 * @brief          This function validates a wakeup channel
 *
 * @param[in]   Channel            Logical number of the ICU channel
 * @param[in]   u8ServiceId        The service id of the caller function
 * @param[in]   u32UserID          The number of current partition ID
 *
 * @return                  The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 *
 * @implements Icu_ValidateWkupChannel_Activity
 * */
static inline Std_ReturnType Icu_ValidateWakeupChannel(Icu_ChannelType Channel, uint8 u8ServiceId,
                                                       uint32 u32UserID)
{
    Std_ReturnType  valid =  (Std_ReturnType)E_OK;
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
    boolean   bWakeup = (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_WakeupCapabile;

    if (TRUE != bWakeup)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        valid =  (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ICU_VALIDATE_PARAMS == STD_ON */

#if (ICU_VALIDATE_PARAMS == STD_ON)
/**
 * @brief      This service validates the activation condition.
 *
 * @param[in]   Activation       Type of activation.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateActivation_Activity
 *
 * */
static inline Std_ReturnType Icu_ValidateActivation(Icu_ActivationType Activation)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if ((ICU_RISING_EDGE != Activation) && (ICU_FALLING_EDGE != Activation) && \
        (ICU_BOTH_EDGES != Activation))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_SETACTIVATIONCONDITION_ID, ICU_E_PARAM_ACTIVATION);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ICU_VALIDATE_PARAMS == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON))
/**
 * @brief          This function validate of the timestamp parameters.
 * @details        This service validates the timestamp parameters passed to Icu_StartTimestamp.
 *
 * @param[in]   Channel             Logical number of the ICU channel
 * @param[in]   pBufferPtr          Pointer to the buffer-array where the timestamp values shall be
 *                                  placed.
 * @param[in]   u16BufferSize       Size of the external buffer (number of entries)
 * @param[in]   u16NotifyInterval   Notification interval (number of events).
 * @param[in]   u32UserID           The number of current partition ID
 *
 * @return                  The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 *
 * @implements  Icu_ValidateTimestamp_Activity
 *
 * */
static inline Std_ReturnType Icu_ValidateTimestamp(Icu_ChannelType Channel, const Icu_ValueType * pBufferPtr,
                                                   uint16 u16BufferSize, uint16 u16NotifyInterval,
                                                   uint32 u32UserID)
{
    Std_ReturnType  valid = (Std_ReturnType)E_NOT_OK;
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];

    if (NULL_PTR == pBufferPtr)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_POINTER);
    }

    else  if ((uint16)0U == u16BufferSize)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_BUFFER_SIZE);
    }
    else if ((ICU_CHANNEL_STATE_NOTIFICATION == Icu_GetBitChState(Channel,ICU_CHANNEL_STATE_NOTIFICATION)) &&
             (NULL_PTR != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChannelNotification) &&
             ((uint16)0U == u16NotifyInterval)
            )
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_NOTIFY_INTERVAL);
    }
    else
    {
        valid= (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON) */


#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief      This function validates the state of timestamp channel
 *
 * @param[in]   Channel          Logical number of the ICU channel
 *
 * @return                  The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 *
 * @implements Icu_ValidateChannelStartState_Activity
 * */
static inline Std_ReturnType Icu_ValidateChannelStartState(Icu_ChannelType Channel)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if(ICU_CHANNEL_STATE_RUNNING != Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING))
    {
        (void)Det_ReportRuntimeError((uint16)ICU_MODULE_ID, 0U, ICU_STOPTIMESTAMP_ID, ICU_E_NOT_STARTED);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ICU_TIMESTAMP_API == STD_ON */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && \
        ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)))
/**
 * @brief       This function validates the signal measurement property
 *
 * @param[in]   Channel                 Logical number of the ICU channel
 * @param[in]   u16ModePropertyMask     The mode property valid
 * @param[in]   u8ServiceId             The service id of the caller function
 * @param[in]   u32UserID               The number of current partition ID
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateSignalMeasurementProperty_Activity
 * */
static inline Std_ReturnType Icu_ValidateSignalMeasurementProperty(Icu_ChannelType Channel,
                                                                                  uint16 u16ModePropertyMask,
                                                                                  uint8  u8ServiceId,
                                                                                  uint32 u32UserID
                                                                                 )
{
    Std_ReturnType  valid = (Std_ReturnType)E_OK;
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
    Icu_MeasurementSubModeType tempProperty = \
                        (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChannelProperty;

    tempProperty = (uint16)((uint16)0x1U << tempProperty);

    if((tempProperty) != (u16ModePropertyMask & tempProperty))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (...) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
/**
 * @brief       This function validates the duty cycle parameter
 *
 * @param[in]   DutyCycleValues  Pointer to a buffer where the results (high time and period time)
 *                                 shall be placed.
 *
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidatePtrDutyCycle_Activity
 *
 * */
static inline Std_ReturnType Icu_ValidatePtrDutyCycle(const Icu_DutyCycleType * DutyCycleValues)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if (NULL_PTR == DutyCycleValues)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_GETDUTYCYCLEVALUES_ID, ICU_E_PARAM_POINTER);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON))
/**
 * @brief       This function validates the versionInfo parameter
 *
 * @param[in]   versioninfo  Pointer to a buffer where the results for version shall be saved
 *
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
static inline Std_ReturnType Icu_ValidateVersionInfoCall(const Std_VersionInfoType * versioninfo)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_GETVERSIONINFO_ID, ICU_E_PARAM_VINFO);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON */


#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON))
/**
 * @brief       This function validates the Prescaler parameter
 *
 * @param[in]   Prescaler One of the two clock functioning modes
 *
 *
 * @return      The validity of the function call
 * @retval      E_OK     The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
static inline Std_ReturnType Icu_ValidateClockModeCall(Icu_SelectPrescalerType Prescaler)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if ((ICU_NORMAL_CLOCK_MODE != Prescaler) && (ICU_ALTERNATE_CLOCK_MODE != Prescaler))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_SET_CLOCK_MODE_ID, (uint8)ICU_E_PARAM_CLOCK_MODE);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
/**
 * @brief       This function validates the Channel type
 *
 * @param[in]   Channel               The logical channel
 * @param[in]   u32UserID             The number of current partition ID
 *
 * @return      The validity of the channel type
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK  The function call is invalid
 *
 */
static inline Std_ReturnType Icu_ValidateGetInputLevel(Icu_ChannelType Channel, uint32 u32UserID)
{
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    Icu_ChannelType ChannelIndex;
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    /* ChannelIndex - Index of channel in the partition where is used.*/
    ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
    /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;

    if (ICU_IPW_ERROR == Icu_Ipw_ValidateGetInputLevel(ChannelConfig))
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_GET_INPUT_LEVEL_ID, (uint8)ICU_E_PARAM_CHANNEL);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief       This function validates mode when Enable feature
 *
 * @param[in]   u8ApiId - the id of function
 *
 *
 * @return      The validity of the channel type
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Icu_ValidateModeForSetUpFeature_Activity
 *
 **/
static inline Std_ReturnType Icu_ValidateModeForSetUpFeature(uint8 u8ApiId)
{
    Std_ReturnType valid =  (Std_ReturnType)E_NOT_OK;
    /* Get partition ID of current processor */
    uint32 u32UserID = Icu_GetUserID();

    if (ICU_MODE_SLEEP == Icu_CurrentMode[u32UserID])
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ApiId, ICU_E_FORBIDEN_MODE);
    }
    else
    {
        valid = (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
/**
 * @brief       This function validates for SignalMeasurement without interrupt
 *
 * @param[in]   Channel               The logical channel
 * @param[in]   u8ApiId               The id of function
 * @param[in]   u32UserID             The number of current partition ID
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 **/
static inline Std_ReturnType Icu_ValidateSignalMeasureWithoutInterrupt(Icu_ChannelType Channel,
                                                                                     uint8  u8ServiceId,
                                                                                     uint32 u32UserID
                                                                                     )
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
    valid = (Std_ReturnType)Icu_Ipw_ValidateSignalMeasureWithoutInterrupt((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_IpwChannelConfigPtr);

    if((Std_ReturnType)E_NOT_OK == valid)
    {
        (void)Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/
/**
 * @brief      This function calls the notification, if available for specific channels
 *
 * @param[in]  Channel               Logical number of the ICU channel
 * @param[in]  u32UserID             The number of current partition ID
 *
 * @return     void
 * @pre        Icu_Init must be called before.
 */
static inline void Icu_CallNotification(Icu_ChannelType Channel, uint32 u32UserID)
{
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];

    if ((ICU_CHANNEL_STATE_NOTIFICATION == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_NOTIFICATION)) \
        && (NULL_PTR != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChannelNotification))
    {
        (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChannelNotification();
    }
}

/**
 * @brief       This function get the channel number corresponding to the index of channel
 *
 * @param[in]   ChannelIndex          Channel Index of the ICU channel
 * @param[in]   u32UserID             The number of current partition ID
 *
 * @return      The channel number corresponds to the channel in the partition
 * @pre         Icu_Init must be called before.
 *
 *
 * */
static inline Icu_ChannelType Icu_ConvertChannelIndexToChannel(Icu_ChannelType ChannelIndex,
                                                               uint32 u32UserID)
{
    Icu_ChannelType index;
    Icu_ChannelType Channel;

    for (index = 0U; index < ICU_MAX_CHANNEL; index++)
    {
        Channel = index;
        if(ChannelIndex == (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[index])
        {
            break;
        }
    }
    return Channel;
}

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/**
 * @brief       This function will configure the channels which is use Dma feature in timestamp mode.
 *
 * @param[in]   ChannelId        Channel Index of the ICU channel
 * @param[in]   BufferPtr        Pointer to the buffer-array where the timestamp values shall be placed.
 * @param[in]   BufferSize       Size of the external buffer (number of entries)
 * @param[in]   NotifyInterval   Notification interval (number of events).
 *
 * @return      None
 *
 * */
static inline void Icu_UpdateTimestampMclDma(Icu_ChannelType ChannelId,
                                             const Icu_ValueType* BufferPtr,
                                             uint16 BufferSize,
                                             uint16 NotifyInterval)
{
    Mcl_DmaChannelTransferListType global_Mcl_DmaChannelTransferList[11U];

    const Icu_Ipw_ChannelConfigType* ChannelConfig;
    uint32  u32UserID = Icu_GetUserID();

    /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelId]).Icu_IpwChannelConfigPtr;

    /* Create the desired configuration list. */
    global_Mcl_DmaChannelTransferList[0U].Param = MCL_DMA_CH_SET_SOURCE_ADDRESS;
    global_Mcl_DmaChannelTransferList[0U].Value = Icu_Ipw_GetStartAddress(ChannelConfig);
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe.
     * The application should ensure that only addresses that fit in uint32 are used for configuring DMA. */
    global_Mcl_DmaChannelTransferList[1U].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
    global_Mcl_DmaChannelTransferList[1U].Value = (uint32)BufferPtr;
    global_Mcl_DmaChannelTransferList[2U].Param = MCL_DMA_CH_SET_DESTINATION_TRANSFER_SIZE;
    global_Mcl_DmaChannelTransferList[2U].Value = (uint32)ICU_DMA_SIZE;
    global_Mcl_DmaChannelTransferList[3U].Param = MCL_DMA_CH_SET_SOURCE_TRANSFER_SIZE;
    global_Mcl_DmaChannelTransferList[3U].Value = (uint32)ICU_DMA_SIZE;
    global_Mcl_DmaChannelTransferList[4U].Param = MCL_DMA_CH_SET_SOURCE_SIGNED_OFFSET;
    global_Mcl_DmaChannelTransferList[4U].Value = (uint32)0U;
    global_Mcl_DmaChannelTransferList[5U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_OFFSET;
    global_Mcl_DmaChannelTransferList[5U].Value = (uint32)ICU_DMA_OFFSET;
    global_Mcl_DmaChannelTransferList[6U].Param = MCL_DMA_CH_SET_SOURCE_MODULO;
    global_Mcl_DmaChannelTransferList[6U].Value = (uint32)0U;
    global_Mcl_DmaChannelTransferList[7U].Param = MCL_DMA_CH_SET_DESTINATION_MODULO;
    global_Mcl_DmaChannelTransferList[7U].Value = (uint32)0U;

    if ((NotifyInterval >= BufferSize) || (NotifyInterval == (uint16)0))
    {
        global_Mcl_DmaChannelTransferList[8U].Param = MCL_DMA_CH_SET_MINORLOOP_SIZE;
        global_Mcl_DmaChannelTransferList[8U].Value = ICU_DMA_NUM_BYTES;
        global_Mcl_DmaChannelTransferList[9U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
        global_Mcl_DmaChannelTransferList[9U].Value = BufferSize;
        if ((uint8) ICU_CIRCULAR_BUFFER == (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelId].Icu_ChannelProperty)
        {
            global_Mcl_DmaChannelTransferList[10U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
            global_Mcl_DmaChannelTransferList[10U].Value = (uint32)((uint64)(~((uint64)BufferSize * (uint64)ICU_DMA_NUM_BYTES)) + (uint64)1U);
        }
        else
        {
            global_Mcl_DmaChannelTransferList[10U].Param = MCL_DMA_CH_SET_CONTROL_DIS_AUTO_REQUEST;
            global_Mcl_DmaChannelTransferList[10U].Value = (uint32)1U;
        }
    }
    else if (NotifyInterval < BufferSize)
    {
        global_Mcl_DmaChannelTransferList[8U].Param = MCL_DMA_CH_SET_MINORLOOP_SIZE;
        global_Mcl_DmaChannelTransferList[8U].Value = ICU_DMA_NUM_BYTES;
        global_Mcl_DmaChannelTransferList[9U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
        global_Mcl_DmaChannelTransferList[9U].Value = NotifyInterval;
        if ((uint8) ICU_CIRCULAR_BUFFER == (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelId].Icu_ChannelProperty)
        {

            global_Mcl_DmaChannelTransferList[10U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
            global_Mcl_DmaChannelTransferList[10U].Value = (uint32)0U;
        }
        else
        {
            global_Mcl_DmaChannelTransferList[10U].Param = MCL_DMA_CH_SET_CONTROL_DIS_AUTO_REQUEST;
            global_Mcl_DmaChannelTransferList[10U].Value = (uint32)0U;
        }
    }
    else
    {
        /* does nothing */
    }

    Mcl_SetDmaChannelTransferList((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelId].Mcl_DmaChannel, \
                                   global_Mcl_DmaChannelTransferList, (uint32)11U);

    Mcl_SetDmaChannelCommand((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelId].Mcl_DmaChannel, \
                             MCL_DMA_CH_START_REQUEST);
}
#endif /* ICU_TIMESTAMP_USES_DMA == STD_ON */
/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/

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
 * @implements         Icu_Init_Activity
 */
void Icu_Init(const Icu_ConfigType *ConfigPtr)
{
    Icu_ChannelType Channel;
    Icu_ChannelType ChannelIndex;
    uint32 u32UserID;
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
    Icu_ChannelConfigType const * ChannelConfig;
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType valid;
#endif

    /* Get partition ID of current processor */
    u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Icu_ValidateGlobalCall(ICU_INIT_ID, u32UserID);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_GLOBAL_CALL == STD_ON */
#if (ICU_VALIDATE_PARAMS == STD_ON)
        valid = Icu_ValidatePtrInit(u32UserID ,ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */

#ifdef ICU_PRECOMPILE_SUPPORT
#if (ICU_MULTIPARTITION_SUPPORT == STD_ON)
            Icu_pCfgPtr[u32UserID] = Icu_Config[u32UserID];
#else /* ICU_MULTIPARTITION_SUPPORT == STD_OFF */
            Icu_pCfgPtr[u32UserID] = &Icu_Config;
#endif /* ICU_MULTIPARTITION_SUPPORT */
            (void)ConfigPtr;
#else
            Icu_pCfgPtr[u32UserID] = ConfigPtr;
#endif /* ICU_PRECOMPILE_SUPPORT */

#ifdef ICU_NONBONDED_WAKEUP_PULLUP
            Icu_Ipw_PullUpNonBondedWakeupPin();
#endif
            Icu_Ipw_Init((Icu_pCfgPtr[u32UserID]->nNumInstances), (Icu_pCfgPtr[u32UserID]->Icu_IpConfigPtr));

            for (ChannelIndex = 0U; ChannelIndex < Icu_pCfgPtr[u32UserID]->nNumChannels; ChannelIndex++)
            {
                Channel = Icu_ConvertChannelIndexToChannel(ChannelIndex, u32UserID);
                /* Clear channel internal state */
                if (ICU_MAX_CHANNEL > Channel)
                {
                    Icu_aChannelState[Channel] = 0x00U;
                }
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                ChannelConfig = (&(*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]);
                if ((ICU_MODE_TIMESTAMP == ChannelConfig->Icu_ChannelMode) && (Channel < ICU_MAX_CHANNEL))
                {
                    Icu_aBuffer[Channel] = NULL_PTR;
                }
#endif /* ICU_TIMESTAMP_API */
            }
            Icu_CurrentMode[u32UserID] = ICU_MODE_NORMAL;
#if (ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (STD_ON == ICU_VALIDATE_GLOBAL_CALL)
    }
    Icu_EndValidateGlobalCall(valid, ICU_INIT_ID, u32UserID);
#endif
}

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
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_DeInit_Activity
 */
void Icu_DeInit(void)
{
    Icu_ChannelType Channel;
    Icu_ChannelType ChannelIndex;
    uint32 u32UserID = Icu_GetUserID();

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    Std_ReturnType valid = Icu_ValidateGlobalCall(ICU_DEINIT_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/

        Icu_Ipw_DeInit((Icu_pCfgPtr[u32UserID]->nNumInstances), (Icu_pCfgPtr[u32UserID]->Icu_IpConfigPtr));

        for (ChannelIndex = 0U; ChannelIndex < Icu_pCfgPtr[u32UserID]->nNumChannels; ChannelIndex++)
        {
            Channel = Icu_ConvertChannelIndexToChannel(ChannelIndex, u32UserID);
            /* Clear channel internal state */
            if (ICU_MAX_CHANNEL > Channel)
            {
                Icu_aChannelState[Channel] =  0x00U;
            }
        }

        Icu_pCfgPtr[u32UserID] = NULL_PTR;
        Icu_CurrentMode[u32UserID] = ICU_MODE_NORMAL;
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_DEINIT_ID, u32UserID);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/
}
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
 * @return      void
 *
 * @pre         Icu_Init must be called before.
 * @implements  Icu_SetMode_Activity
 */
void Icu_SetMode(Icu_ModeType Mode)
{
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    Icu_ChannelType Channel;
    Icu_ChannelType ChannelIndex;
    uint32 u32UserID;

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType valid;
#endif

    /* Get partition ID of current processor */
    u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)

    valid = Icu_ValidateGlobalCall(ICU_SETMODE_ID, u32UserID);
    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Icu_ValidateCallSetMode(Mode, u32UserID);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */
#if (ICU_VALIDATE_PARAMS == STD_ON)
            valid = Icu_ValidateMode(Mode);
            if ((Std_ReturnType)E_OK == valid)
            {
#endif /* ICU_VALIDATE_PARAMS == STD_ON */
                for (ChannelIndex = 0U; ChannelIndex < Icu_pCfgPtr[u32UserID]->nNumChannels; ChannelIndex++)
                {
                    /* Decode logic channel.  */
                    Channel = Icu_ConvertChannelIndexToChannel(ChannelIndex, u32UserID);
                    /* Channel configuration for actual ChannelIndex in this partition. */
                    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
                        if (ICU_MODE_SLEEP == Mode)
                        {
                            if ((Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_WKUP) != ICU_CHANNEL_STATE_WKUP) && \
                                (Icu_CurrentMode[u32UserID] != Mode))
                            {
                                Icu_Ipw_SetSleepMode(ChannelConfig);
                            }
                        }
                        else
                        {
                            if ((Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING) == ICU_CHANNEL_STATE_RUNNING) && \
                                (Icu_CurrentMode[u32UserID] != Mode))
                            {
                                Icu_Ipw_SetNormalMode(ChannelConfig);
                            }
                        }
                }
                Icu_CurrentMode[u32UserID] = Mode;
#if (ICU_VALIDATE_PARAMS == STD_ON)
            }
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
        }
    }
    Icu_EndValidateGlobalCall(valid, ICU_SETMODE_ID, u32UserID);
#endif /* (ICU_VALIDATE_GLOBAL_CALL == STD_ON)*/
}
#endif /* ICU_SET_MODE_API */

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/**
 * @brief   This function disables the wakeup capability of a single ICU channel.
 * @details This service is reentrant function and shall disable  the wakeup capability of
 *          a single ICU channel.This  service is only feasible for ICU channels configured
 *          statically as wakeup capable TRUE.
 *          The  function  Icu_DisableWakeup shall  be  pre compile  time  configurable On,Off by
 *          the configuration parameter IcuDisableWakeupApi.
 *
 * @param[in]     Channel          Logical number of the ICU channel
 *
 * @return void
 * @pre Icu_Init must be called before.
 * @implements Icu_DisableWakeup_Activity
 */
void Icu_DisableWakeup(Icu_ChannelType Channel)
{
#if ((ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON))
    uint32 u32UserID = Icu_GetUserID();
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;

    uint8 mask = (uint8)((uint32)((uint32)1U << ICU_MODE_EDGE_COUNTER) | (uint32)((uint32)1U << ICU_MODE_SIGNAL_EDGE_DETECT) | \
                                (uint32)((uint32)1U << ICU_MODE_SIGNAL_MEASUREMENT) | (uint32)((uint32)1U << ICU_MODE_TIMESTAMP));

    valid = Icu_ValidateCallAndChannel (Channel, mask, ICU_DISABLEWAKEUP_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */
#if (ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateWakeupChannel(Channel, ICU_DISABLEWAKEUP_ID, u32UserID))
        {
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_WKUP);
#if (ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif /*(ICU_VALIDATE_PARAMS == STD_ON)*/
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */
}
#endif /* ICU_DISABLE_WAKEUP_API */

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/**
 * @brief   This function (re-)enables the wakeup capability of the given ICU channel.
 * @details The function is reentrant and re-enable the wake-up capability of a single ICU channel.
 *
 * @param[in]  Channel          Logical number of the ICU channel
 *
 * @return     void
 * @pre        Icu_Init must be called before. The channel must be configured as wakeup capable.
 * @implements Icu_EnableWakeup_Activity
 */
void Icu_EnableWakeup(Icu_ChannelType Channel)
{
#if (( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) || ( ICU_VALIDATE_PARAMS == STD_ON))
    uint32 u32UserID = Icu_GetUserID();
#endif

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
    uint8 mask;
#endif /* ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_ENABLEWAKEUP_ID))
    {
#endif

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    mask = (uint8)((uint32)((uint32)1U << ICU_MODE_EDGE_COUNTER) | (uint32)((uint32)1U << ICU_MODE_SIGNAL_EDGE_DETECT) | \
                  (uint32)((uint32)1U << ICU_MODE_SIGNAL_MEASUREMENT) | (uint32)((uint32)1U << ICU_MODE_TIMESTAMP));
    valid = Icu_ValidateCallAndChannel (Channel, mask, ICU_ENABLEWAKEUP_ID, u32UserID);

    if((Std_ReturnType)E_OK == valid)
    {
#endif
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        if((Std_ReturnType)E_OK == Icu_ValidateWakeupChannel(Channel, ICU_ENABLEWAKEUP_ID, u32UserID))
        {
#endif
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_WKUP);
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* ICU_ENABLE_WAKEUP_API */


#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief  Checks if a wakeup capable ICU channel is the source for a wakeup event.
 * @details The function calls the ECU state manager service EcuM_SetWakeupEvent
 * in case of a valid ICU channel wakeup event.
 *
 * @param[in]     WakeupSource          Information on wakeup source to be checked.
 *
 * @return     void
 * @pre        Icu_Init must be called before. The channel must be configured as wakeup capable.
 * @implements Icu_CheckWakeup_Activity
 */
void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    Icu_ChannelType Channel;
    Icu_ChannelType ChannelIndex;
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    Std_ReturnType valid = Icu_ValidateGlobalCall(ICU_CHECKWAKEUP_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/

        for (ChannelIndex = 0U; ChannelIndex < Icu_pCfgPtr[u32UserID]->nNumChannels; ChannelIndex++)
        {
            Channel = Icu_ConvertChannelIndexToChannel(ChannelIndex, u32UserID);
            if ((Icu_ChannelStateType)(ICU_CHANNEL_IS_WAKEUP_SOURCE | ICU_CHANNEL_STATE_WKUP) ==  \
                 Icu_GetBitChState(Channel, ICU_CHANNEL_IS_WAKEUP_SOURCE | ICU_CHANNEL_STATE_WKUP) \
                )
            {
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
                if (WakeupSource == (EcuM_WakeupSourceType)(*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_Channel_WakeupValue)
                {
                    EcuM_SetWakeupEvent(WakeupSource);
                    Icu_ClearBitChState(Channel, ICU_CHANNEL_IS_WAKEUP_SOURCE);
                }
#else
                Icu_ClearBitChState(Channel, ICU_CHANNEL_IS_WAKEUP_SOURCE);
#endif
                break;
            }
        }
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_CHECKWAKEUP_ID, u32UserID);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/
}
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
 * @param[in]  Channel          Logical number of the ICU channel
 * @param[in]  Activation       Type of activation.
 *
 * @return     void
 * @pre        Icu_Init must be called before. The channel must be properly configured
 *             (ICU_MODE_SIGNAL_EDGE_DETECT, ICU_MODE_TIMESTAMP, ICU_MODE_EDGE_COUNTER).
 * @implements Icu_SetActivationCondition_Activity
 */
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
    Icu_ChannelType ChannelIndex;
    uint32 u32UserID = Icu_GetUserID();
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
    uint8 mask = (uint8)((uint32)((uint32)0x1U << ICU_MODE_EDGE_COUNTER) | (uint32)((uint32)0x1U << ICU_MODE_SIGNAL_EDGE_DETECT) | (uint32)((uint32)0x1U << ICU_MODE_TIMESTAMP));

    valid = Icu_ValidateCallAndChannel (Channel, mask, ICU_SETACTIVATIONCONDITION_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateActivation(Activation))
        {
#endif
            /* Clear IDLE status */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_IDLE);

            /* ChannelIndex - Index of channel in the partition where is used.*/
            ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            Icu_Ipw_SetActivationCondition(Activation, \
                           (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_IpwChannelConfigPtr);

#if ( ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}


/**
* @brief   This function disables the notification of a channel.
*
* @details This function is reentrant and disables the notification of a channel.
* @param[in]     Channel          Logical number of the ICU channel
*
* @return     void
* @pre        Icu_Init must be called before.
* @implements Icu_DisableNotification_Activity
**/
void Icu_DisableNotification(Icu_ChannelType Channel)
{
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType ChannelIndex;
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
    uint8 mask;

    mask = (uint8)((uint32)((uint32)0x1U << ICU_MODE_SIGNAL_EDGE_DETECT) | (uint32)((uint32)0x1U << ICU_MODE_TIMESTAMP));

    valid = Icu_ValidateCallAndChannel(Channel, mask, ICU_DISABLENOTIFICATION_ID, u32UserID);


    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* Clear notification enable status */
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_NOTIFICATION);

        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        Icu_Ipw_DisableNotification((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_IpwChannelConfigPtr);

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_DISABLENOTIFICATION_ID, u32UserID);
#endif
}


/**
* @brief   This function enables the notification on the given channel.
* @details This function is reentrant and enables the notification on the given channel. The
*          notification  will be reported only when the channel measurement property is enabled or
*          started
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
* @pre Icu_Init must be called before.
* @implements Icu_EnableNotification_Activity
**/
void Icu_EnableNotification(Icu_ChannelType Channel)
{
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType ChannelIndex;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
    uint8 mask;

    mask = (uint8)((uint32)((uint32)0x1U << ICU_MODE_SIGNAL_EDGE_DETECT) | (uint32)((uint32)0x1U << ICU_MODE_TIMESTAMP));

    valid = Icu_ValidateCallAndChannel(Channel, mask, ICU_ENABLENOTIFICATION_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* Set notification enable status */
        Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_NOTIFICATION);

        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        Icu_Ipw_EnableNotification((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_IpwChannelConfigPtr);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_ENABLENOTIFICATION_ID, u32UserID);
#endif
}


#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief   This function returns the status of the ICU input.
 * @details This service is reentrant shall return the status of  the ICU input.
 *          Only channels which are configured for the following Icu_MeasurementMode shall be
 *          supported:
 *          - ICU_MODE_SIGNAL_EDGE_DETECT,
 *          - ICU_MODE_SIGNAL_MEASUREMENT.
 *
 * @param[in]  Channel - Logical number of the ICU channel
 *
 * @return     Icu_InputStateType
 * @retval     ICU_ACTIVE     An activation edge has been detected
 * @retval     ICU_IDLE       No activation edge has been detected since the last call of
 *             Icu_GetInputState() or Icu_Init().
 *
 * @pre        Icu_Init must be called before.
 *
 * @implements Icu_GetInputState_Activity
 */
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    Icu_InputStateType tempState = ICU_IDLE;
    uint32             u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
    uint8 mask;

    mask = (uint8)((uint32)((uint32)0x1U << ICU_MODE_SIGNAL_EDGE_DETECT) | (uint32)((uint32)0x1U << ICU_MODE_SIGNAL_MEASUREMENT));

    valid = Icu_ValidateCallAndChannel(Channel, mask, ICU_GETINPUTSTATE_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        if (ICU_CHANNEL_STATE_IDLE == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_IDLE))
        {
            tempState = ICU_ACTIVE;
            /* Clear IDLE status. */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
        }
        else if (ICU_MODE_SIGNAL_EDGE_DETECT == \
                 ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_ChannelMode)
        {
            tempState = Icu_Ipw_GetInputState(ChannelConfig) ? ICU_ACTIVE : ICU_IDLE;
        }
#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
        else if (ICU_MODE_SIGNAL_MEASUREMENT == \
                 ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_ChannelMode)
        {
            tempState = Icu_Ipw_GetInputState(ChannelConfig) ? ICU_ACTIVE : ICU_IDLE;
        }
#endif
        else
        {
            /* Do nothing. */
        }
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_GETINPUTSTATE_ID, u32UserID);
#endif
    return (tempState);
}
#endif /* ICU_GET_INPUT_STATE_API */


#if (ICU_TIMESTAMP_API == STD_ON)

/** @implements Icu_StartTimestamp_Activity */
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
    Icu_ChannelType                  ChannelIndex;
    const Icu_Ipw_ChannelConfigType* ChannelConfig;
    uint32  u32UserID = Icu_GetUserID();

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_STARTTIMESTAMP_ID))
    {
#endif

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        Std_ReturnType valid = Icu_ValidateCallAndChannel(Channel, (uint8)(1U << ICU_MODE_TIMESTAMP), \
                                                          ICU_STARTTIMESTAMP_ID, u32UserID);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Icu_ValidateTimestamp(Channel, BufferPtr, BufferSize,\
                NotifyInterval, u32UserID))
            {
#endif
                /* Time stamp is running. */
                Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);

                /* Clear the previous overflow status flag (if was the case). */
                Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);

                /* ChannelIndex - Index of channel in the partition where is used.*/
                ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
                /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
                ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02 ();
                {
                    Icu_aBuffer[Channel]       = BufferPtr;
                    Icu_aBufferSize[Channel]   = BufferSize;
                    Icu_aBufferNotify[Channel] = NotifyInterval;
                    Icu_aNotifyCount[Channel]  = 0U;
                    Icu_aBufferIndex[Channel]  = 0U;
                }
                SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();

                if(NoMclDmaChannel != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel)
                {
                    Icu_UpdateTimestampMclDma(ChannelIndex, BufferPtr, BufferSize, NotifyInterval);
                }
#endif /* ICU_TIMESTAMP_USES_DMA == STD_ON */
                Icu_Ipw_StartTimestamp(ChannelConfig, BufferPtr, BufferSize, NotifyInterval);
#if (ICU_VALIDATE_PARAMS == STD_ON)
            }
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    Icu_EndValidateGlobalCall(valid, ICU_STARTTIMESTAMP_ID, u32UserID);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}

/**
* @brief   This function stops the timestamp measurement of the given channel.
* @details This function is reentrant and stops the timestamp measurement of the given channel.
*
* @param[in]     Channel          Logical number of the ICU channel
*
* @return void
*
* @implements Icu_StopTimestamp_Activity
**/
void Icu_StopTimestamp(Icu_ChannelType Channel)
{
    Icu_ChannelType ChannelIndex = 0U;
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid= Icu_ValidateCallAndChannel(Channel,(uint8)(1U << ICU_MODE_TIMESTAMP), ICU_STOPTIMESTAMP_ID, u32UserID);
#endif

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        if ((Std_ReturnType)E_OK == Icu_ValidateChannelStartState(Channel))
        {
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
            if (NoMclDmaChannel != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel)
            {
                Mcl_SetDmaChannelCommand((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel, \
                                         MCL_DMA_CH_STOP_REQUEST);
            }
#endif
            Icu_Ipw_StopTimestamp(((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr);
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
        }
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* STD_ON == ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/** @implements Icu_GetTimestampIndex_Activity */
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
    Icu_IndexType timestampIndex = 0U;
    Icu_ChannelType ChannelIndex;
    const Icu_Ipw_ChannelConfigType* ChannelConfig;
    uint32 u32UserID = Icu_GetUserID();

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
    uint32          startIter = 0U;
    uint32          crtIter = 0U;
    uint32* const   pStartIter = &startIter;
    uint32* const   pCrtIter = &crtIter;
#endif

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel(Channel, (uint8)(1U << ICU_MODE_TIMESTAMP), ICU_GETTIMESTAMPINDEX_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF))
        if (FALSE == Icu_GetOverflow(Channel, ICU_GETTIMESTAMPINDEX_ID, ICU_E_TIMESTAMP_OVERFLOW, u32UserID))
        {
#endif

            /* ChannelIndex - Index of channel in the partition where is used.*/
            ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
            if (NoMclDmaChannel != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel)
            {
                if (NULL_PTR == Icu_aBuffer[Channel])
                {
                    timestampIndex = 0U;
                }
                else
                {
                    Mcl_GetDmaChannelParam((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel, \
                                            MCL_DMA_CH_GET_BEGIN_ITER_COUNT, pStartIter);
                    Mcl_GetDmaChannelParam((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel, \
                                            MCL_DMA_CH_GET_CURRENT_ITER_COUNT, pCrtIter);
                    crtIter = startIter - crtIter;
                    timestampIndex =  Icu_aBufferIndex[Channel] + (Icu_IndexType)crtIter;
                }
            }
            else
            {
#endif /* ICU_TIMESTAMP_USES_DMA == STD_ON */
                /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
                ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
                timestampIndex = Icu_Ipw_GetTimestampIndex(ChannelConfig);
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
            }
#endif

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF))
        }
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return timestampIndex;
}
#endif /* ICU_TIMESTAMP_API */


#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @brief      This function resets the value of the counted edges to zero.
 * @details    This function is reentrant and resets the value of the counted edges to zero.
 *
 * @param[in]  Channel - Logical number of the ICU channel.
 *
 * @return     void
 *
 * @pre        Icu_Init must be called before.
 *
 * @implements Icu_ResetEdgeCount_Activity
 */
void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get used partition. */
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
                (Channel, (uint8)(1U << ICU_MODE_EDGE_COUNTER), ICU_RESETEDGECOUNT_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the current partition. */
        ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        /* Clear overflow flag. */
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
        Icu_Ipw_ResetEdgeCount(ChannelConfig);

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Icu_EndValidateCallAndChannel(valid);
    }
#endif
}
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_COUNT_API)
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
 * @pre Icu_Init must be called before. The given channel must be configured in Measurement Mode
 *      Edge Counter.
 *
 * @implements Icu_EnableEdgeCount_Activity
 */
void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32 u32UserID = Icu_GetUserID();

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_ENABLEEDGECOUNT_ID))
    {
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        Std_ReturnType valid = Icu_ValidateCallAndChannel \
            (Channel,(uint8)(1U << ICU_MODE_EDGE_COUNTER), ICU_ENABLEEDGECOUNT_ID, u32UserID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
            /* Clear the previous overflow status flag (if was the case). */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
            /* Clear overflow flag */
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
            /* ChannelIndex - Index of channel in the partition where is used.*/
            ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
            ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
            Icu_Ipw_EnableEdgeCount(ChannelConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @details This function is reentrant and disables the counting of edges of the given channel.
 * @brief   This function disables the counting of edges of the given channel.
 *
 * @param[in]     Channel          Logical number of the ICU channel
 *
 * @return void
 *
 * @pre Icu_Init must be called before.The given channel must be configured in Measurement
 *      Mode Edge Counter.
 *
 * @implements Icu_DisableEdgeCount_Activity
 */
void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)(1U << ICU_MODE_EDGE_COUNTER), ICU_DISABLEEDGECOUNT_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        Icu_Ipw_DisableEdgeCount(ChannelConfig);
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* STD_ON == ICU_EDGE_COUNT_API */


#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @brief   This function reads the number of counted edges.
 * @details This function is reentrant reads the number of counted edges after the last call
 *          of Icu_ResetEdgeCount().
 *
 * @param[in]     Channel          Logical number of the ICU channel
 *
 * @return Icu_EdgeNumberType - Number of the counted edges.
 *
 * @pre Icu_Init must be called before. The given channel must be configured in Measurement
 *      Mode Edge Counter.
 *
 * @implements Icu_GetEdgeNumbers_Activity
 **/
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32             u32UserID   = Icu_GetUserID();
    Icu_EdgeNumberType edgeNumbers = 0U;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)(1U << ICU_MODE_EDGE_COUNTER), ICU_GETEDGENUMBERS_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if (FALSE == Icu_GetOverflow(Channel, ICU_GETEDGENUMBERS_ID, ICU_E_EDGECOUNTING_OVERFLOW, u32UserID))
        {
#endif
#endif
            /* ChannelIndex - Index of channel in the partition where is used.*/
            ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
            ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
            edgeNumbers = Icu_Ipw_GetEdgeNumbers(ChannelConfig);
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return edgeNumbers;
}
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_COUNT_API)
#if (defined ICU_SET_INITIAL_COUNTER)
#if (STD_ON == ICU_SET_INITIAL_COUNTER)
/**
 * @details    This function Set Initial setting of eMIOS Counter
 * @brief      Icu driver function that Set Initial setting of eMIOS Counter.
 *
 * @param[in]  Channel                Logical number of the ICU channel
 * @param[in]  InitialCounterValue    eMios Initial counter value
 *
 * @return void
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
void Icu_SetInitialCounterValue(Icu_ChannelType Channel, uint32 InitialCounterValue)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)(1U << ICU_MODE_EDGE_COUNTER), ICU_SETINITIALCOUNTER_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        Icu_Ipw_SetInitialCounterValue(ChannelConfig, InitialCounterValue);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif  /* STD_ON == ICU_SET_INITIAL_COUNTER */
#endif  /* ICU_SET_INITIAL_COUNTER */
#endif /* STD_ON == ICU_EDGE_COUNT_API */
#if (STD_ON == ICU_EDGE_COUNT_API)
#if (defined ICU_SET_MAX_COUNTER)
#if (STD_ON == ICU_SET_MAX_COUNTER)
/**
 * @details    This function Set Max setting of eMIOS Counter
 * @brief      Icu driver function that Set Max setting of eMIOS Counter.
 *
 * @param[in]  Channel                Logical number of the ICU channel
 * @param[in]  MaxCounterValue        eMios Max counter value
 *
 * @return void
 *
 * @pre        This function is not required because the counter value is
 *             set automatically. But to arbitrarily change the Max value
 *             of the counter value, it is necessary to call this function before
 *             the Icu_EnableEdgeCount function.
 *
 * @implements Icu_SetMaxCounterValue_Activity
 **/
void Icu_SetMaxCounterValue(Icu_ChannelType Channel, uint32 MaxCounterValue)
{
    Icu_ChannelType                  ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)(1U << ICU_MODE_EDGE_COUNTER), ICU_SETMAXCOUNTER_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        Icu_Ipw_SetMaxCounterValue(ChannelConfig, MaxCounterValue);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif  /* STD_ON == ICU_SET_MAX_COUNTER */
#endif  /* ICU_SET_MAX_COUNTER */
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_DETECT_API)
/**
 * @brief     This function enables or re-enables the detection of edges of the given channel.
 * @details   This function is reentrant enables or re-enables the detection of edges of the given
 *            channel.
 *
 * @param[in] Channel          Logical number of the ICU channel
 *
 * @return    void
 *
 * @pre       Icu_Init must be called before. The channel must be configured in Measurement Mode Edge
 *            Counter
 * @implements Icu_EnableEdgeDetection_Activity
 */
void Icu_EnableEdgeDetection(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32             u32UserID   = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
#endif

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_ENABLEEDGEDETECTION_ID))
    {
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        valid = Icu_ValidateCallAndChannel(Channel, (uint8)(1U << ICU_MODE_SIGNAL_EDGE_DETECT), \
                                           ICU_ENABLEEDGEDETECTION_ID, u32UserID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
            /* ChannelIndex - Index of channel in the partition where is used.*/
            ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
            ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
            Icu_Ipw_EnableEdgeDetection(ChannelConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* STD_ON == ICU_EDGE_DETECT_API */


#if (STD_ON == ICU_EDGE_DETECT_API)
/**
 * @brief      This function is reentrant and disables the detection of edges of the given channel.
 *
 * @param[in]  Channel - Logical number of the ICU channel
 *
 * @return     void
 *
 * @pre        Icu_Init must be called before. The channel must be configured in Measurement
 *             Mode Edge Detection.
 * @implements Icu_DisableEdgeDetection_Activity
 */
void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    /* Get partition number. */
    uint32             u32UserID   = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)(1U << ICU_MODE_SIGNAL_EDGE_DETECT), ICU_DISABLEEDGEDETECTION_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        Icu_Ipw_DisableEdgeDetection(ChannelConfig);
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* STD_ON == ICU_EDGE_DETECT_API */


#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
 * @brief   This function starts the measurement of signals.
 * @details This service is reentrant and starts the measurement of signals beginning with the
 *          configured default start edge which occurs first after the call of this service.
 *          This service shall only be available in Measurement Mode ICU_MODE_SIGNAL_MEASUREMENT.
 *          This service shall reset the state for the given channel to ICU_IDLE.
 *
 * @param[in]  Channel - Logical number of the ICU channel
 *
 * @return     void
 *
 * @pre        Icu_Init must be called before. The channel must be configured in Measurement Mode Signal
 *             Measurement.
 *
 * @implements Icu_StartSignalMeasurement_Activity
 */
void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
    uint8 u8index = 0U;
    Mcl_DmaChannelTransferListType global_Mcl_DmaChannelTransferList[10U];
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid;
#endif

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_STARTSIGNALMEASUREMENT_ID))
    {
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        valid = Icu_ValidateCallAndChannel(Channel, (uint8)(1U << ICU_MODE_SIGNAL_MEASUREMENT), ICU_STARTSIGNALMEASUREMENT_ID, u32UserID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
            /* ChannelIndex - Index of channel in the partition where is used.*/
            ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
            ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
            /*Clear the previous overflow status flag (if was the case) */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08();
            {
#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
                if(NoMclDmaChannel != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel)
                {
                    Icu_aIsSecondInterrupt[Channel] = 0U;
                    /* initialize the members of the structure */
                    global_Mcl_DmaChannelTransferList[0U].Param = MCL_DMA_CH_SET_SOURCE_ADDRESS;
                    global_Mcl_DmaChannelTransferList[0U].Value = Icu_Ipw_GetStartAddress(ChannelConfig);
                    /* Compiler_Warning: This warning is thrown because of a conversion between a Icu_ValyeType pointer and a uint32 */
                    global_Mcl_DmaChannelTransferList[1U].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
                    global_Mcl_DmaChannelTransferList[1U].Value = (uint32)&Icu_aDmaBuffer[Channel][0];
                    global_Mcl_DmaChannelTransferList[2U].Param = MCL_DMA_CH_SET_DESTINATION_TRANSFER_SIZE;
                    global_Mcl_DmaChannelTransferList[2U].Value = (uint32)ICU_DMA_SIZE;
                    global_Mcl_DmaChannelTransferList[3U].Param = MCL_DMA_CH_SET_SOURCE_TRANSFER_SIZE;
                    global_Mcl_DmaChannelTransferList[3U].Value = (uint32)ICU_DMA_SIZE;
                    global_Mcl_DmaChannelTransferList[4U].Param = MCL_DMA_CH_SET_SOURCE_SIGNED_OFFSET;
                    global_Mcl_DmaChannelTransferList[4U].Value = (uint32)0U;
                    global_Mcl_DmaChannelTransferList[5U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_OFFSET;
                    global_Mcl_DmaChannelTransferList[5U].Value = (uint32)ICU_DMA_OFFSET;
                    global_Mcl_DmaChannelTransferList[6U].Param = MCL_DMA_CH_SET_SOURCE_MODULO;
                    global_Mcl_DmaChannelTransferList[6U].Value = (uint32)0U;
                    global_Mcl_DmaChannelTransferList[7U].Param = MCL_DMA_CH_SET_DESTINATION_MODULO;
                    global_Mcl_DmaChannelTransferList[7U].Value = (uint32)0U;
                    global_Mcl_DmaChannelTransferList[8U].Param = MCL_DMA_CH_SET_MINORLOOP_SIZE;
                    global_Mcl_DmaChannelTransferList[8U].Value = (uint32)ICU_DMA_NUM_BYTES;
                    global_Mcl_DmaChannelTransferList[9U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
                    global_Mcl_DmaChannelTransferList[9U].Value = (uint32)ICU_DMA_MAJORLOOP_FIRST_COUNT;
                    Mcl_SetDmaChannelTransferList((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel, \
                                                  global_Mcl_DmaChannelTransferList, (uint32)10U);
                    Mcl_SetDmaChannelCommand((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel, \
                                             MCL_DMA_CH_START_REQUEST);

                     /*Clear the DMA result buffer for configured DMA channel*/
                    for(u8index = 0U; u8index < ICU_DMA_MAJORLOOP_COUNT; u8index++)
                    {
                        Icu_aDmaBuffer[Channel][u8index] = (uint16)0;
                    }
                }
#endif
            }
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08();
            Icu_Ipw_StartSignalMeasurement(ChannelConfig);
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}

/** @implements Icu_StopSignalMeasurement_Activity */
void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel, (uint8)(1U << ICU_MODE_SIGNAL_MEASUREMENT), ICU_STOPSIGNALMEASUREMENT_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* ChannelIndex - Index of channel in the partition where is used.*/
        ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
        ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
        Icu_Ipw_StopSignalMeasurement(ChannelConfig);
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* STD_ON == ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/** @implements Icu_GetTimeElapsed_Activity */
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
    Icu_ValueType timeElapsed = (Icu_ValueType)0U;
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel(Channel,\
                           (uint8)(1U << ICU_MODE_SIGNAL_MEASUREMENT), ICU_GETTIMEELAPSED_ID, u32UserID);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if (FALSE == Icu_GetOverflow(Channel, ICU_GETTIMEELAPSED_ID, ICU_E_MEASUREMENT_OVERFLOW, u32UserID))
        {
#endif
            if ((Std_ReturnType)E_OK == Icu_ValidateSignalMeasurementProperty(Channel, \
                     (uint16)((uint32)((uint32)0x1U << ICU_LOW_TIME) | (uint32)((uint32)0x1U << ICU_HIGH_TIME) | (uint32)((uint32)0x1U << ICU_PERIOD_TIME)), \
                     ICU_GETTIMEELAPSED_ID, u32UserID ))
            {
#endif
                /* ChannelIndex - Index of channel in the partition where is used.*/
                ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
                /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
                ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
                timeElapsed = Icu_Ipw_GetTimeElapsed(ChannelConfig);
                Icu_ClearBitChState(Channel,ICU_CHANNEL_STATE_IDLE);
#if (ICU_VALIDATE_PARAMS == STD_ON)
            }
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return timeElapsed;
}
#endif /* ICU_GET_TIME_ELAPSED_API */

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/** @implements Icu_GetDutyCycleValues_Activity */
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues)
{
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType                 ChannelIndex;
    const Icu_Ipw_ChannelConfigType *ChannelConfig;

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel \
        (Channel, (uint8)(1U << ICU_MODE_SIGNAL_MEASUREMENT), ICU_GETDUTYCYCLEVALUES_ID, u32UserID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if (FALSE == Icu_GetOverflow(Channel, ICU_GETDUTYCYCLEVALUES_ID, ICU_E_MEASUREMENT_OVERFLOW, u32UserID))
        {
#endif
            if ((Std_ReturnType)E_OK == Icu_ValidateSignalMeasurementProperty
                        (Channel, (uint16)((uint16)0x1U << ICU_DUTY_CYCLE), ICU_GETDUTYCYCLEVALUES_ID, u32UserID))
            {
                if ((Std_ReturnType)E_OK == Icu_ValidatePtrDutyCycle(DutyCycleValues))
                {
#endif
                    /* ChannelIndex - Index of channel in the partition where is used.*/
                    ChannelIndex  = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
                    /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
                    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;
                    Icu_Ipw_GetDutyCycleValues(ChannelConfig, DutyCycleValues);
#if (ICU_VALIDATE_PARAMS == STD_ON)
                }
            }
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* ICU_GET_DUTY_CYCLE_VALUES_API */

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
* @param[out] versioninfo      Pointer to location to store version info
*
* @return     void
* @implements Icu_GetVersionInfo_Activity
**/
void Icu_GetVersionInfo (Std_VersionInfoType *versioninfo)
{
#if (ICU_VALIDATE_PARAMS == STD_ON)
    if ((Std_ReturnType)E_OK == Icu_ValidateVersionInfoCall(versioninfo))
    {
#endif
        (versioninfo)->vendorID         = (uint16)ICU_VENDOR_ID;
        (versioninfo)->moduleID         = (uint8)ICU_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)ICU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)ICU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)ICU_SW_PATCH_VERSION;
#if (ICU_VALIDATE_PARAMS == STD_ON)
    }
#endif
}
#endif  /* ICU_GET_VERSION_INFO_API == STD_ON */

#if (STD_ON == ICU_DUAL_CLOCK_MODE_API)
/**
 * @brief      This function changes the channel prescaler.
 * @details    This function sets all channels prescalers based on the input mode.
 *
 * @param[in]  Prescaler - Prescaler type: Normal or Alternate
 *
 * @return     void
 *
 * @pre        Icu_Init must be called before.
 *
 * @implements Icu_SetClockMode_Activity
 */
void Icu_SetClockMode(Icu_SelectPrescalerType selectPrescaler)
{
    const Icu_Ipw_IpConfigType (*modulesIpwConfig)[];
    uint8                      instancesNumber;
    /* Get partition ID of current processor */
    uint32 u32UserID = Icu_GetUserID();
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType valid;
#endif

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Icu_ValidateGlobalCall(ICU_SET_CLOCK_MODE_ID, u32UserID);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_GLOBAL_CALL == STD_ON */
#if (ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateClockModeCall(selectPrescaler))
        {
#endif
            modulesIpwConfig = Icu_pCfgPtr[u32UserID]->Icu_IpConfigPtr;
            instancesNumber  = Icu_pCfgPtr[u32UserID]->nNumInstances;
            Icu_Ipw_SetClockMode(modulesIpwConfig, selectPrescaler, instancesNumber);
#if (ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (STD_ON == ICU_VALIDATE_GLOBAL_CALL)
    }
    Icu_EndValidateGlobalCall(valid, ICU_SET_CLOCK_MODE_ID, u32UserID);
#endif
}
#endif /* STD_ON == ICU_DUAL_CLOCK_MODE_API */

#if (STD_ON == ICU_GET_INPUT_LEVEL_API)
/**
 * @brief      This function returns the actual status of PIN.
 *
 * @param[in]  Channel - Logical number of the ICU channel
 *
 * @return     Icu_LevelType
 *
 * @pre        Icu_Init must be called before.
 * @implements Icu_GetInputLevel_Activity
 */
Icu_LevelType Icu_GetInputLevel(Icu_ChannelType Channel)
{

    Icu_ChannelType ChannelIndex = 0U;
    Icu_LevelType level     = (Icu_LevelType)ICU_LEVEL_LOW;
    uint32        u32UserID = Icu_GetUserID();

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType valid = Icu_ValidateCallAndChannel(Channel,(uint8)((1U << ICU_MODE_SIGNAL_MEASUREMENT)|(uint8)(1U << ICU_MODE_SIGNAL_EDGE_DETECT)), \
                                       ICU_GET_INPUT_LEVEL_ID, u32UserID);
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */
        ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];

#if (ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateGetInputLevel(Channel, u32UserID))
        {
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */

            level = (Icu_LevelType)Icu_Ipw_GetInputLevel(((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr);

#if (ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */
    return level;
}
#endif /* ICU_GET_INPUT_LEVEL_API */

/**
 * @brief      This function reports the wakeup and overflow events, if available.
 *
 * @param[in]  hwChannel        Hardware number identifier of the ICU channel
 * @param[in]  bOverflow        Parameter that indicates the source of report is an overflow
 *
 * @return     void
 * @pre        Icu_Init must be called before.
 * @implements Icu_ReportWakeupAndOverflow_Activity
 **/
void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow)
{
    uint32  u32UserID = Icu_GetUserID();
#if ((ICU_REPORT_WAKEUP_SOURCE == STD_ON) || \
    (defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)))
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
#endif /* ICU_REPORT_WAKEUP_SOURCE == STD_ON */

    if ((ICU_CHANNEL_STATE_WKUP == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_WKUP)) && \
        (ICU_MODE_SLEEP == Icu_CurrentMode[u32UserID]))
    {
        Icu_SetBitChState(Channel, ICU_CHANNEL_IS_WAKEUP_SOURCE);
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        EcuM_CheckWakeup((EcuM_WakeupSourceType)\
                         (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_Channel_WakeupValue);
#endif /* ICU_REPORT_WAKEUP_SOURCE == STD_ON */
    }
    if (TRUE == bOverflow)
    {
        Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        if (NULL_PTR != (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChOverflowNotification)
        {
            (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChOverflowNotification();
        }
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
    }
}

/**
* @brief     This function reports the wakeup event, overflow event and notification, if available
*
* @param[in]    hwChannel          Harware number identifier of the ICU channel
* @param[in]    overflow           Parameter that indicates the source of report is an overflow
*
* @return      void
* @pre        Icu_Init must be called before.
* @implements Icu_ReportEvents_Activity
**/
void Icu_ReportEvents(uint16 Channel, boolean bOverflow)
{
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];

    Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
    Icu_ReportWakeupAndOverflow(Channel, bOverflow);
    if ((ICU_MODE_TIMESTAMP != ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_ChannelMode))
    {
        Icu_CallNotification(Channel, u32UserID);
    }
}

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/** @implements Icu_TimestampDmaProcessing_Activity */
void Icu_TimestampDmaProcessing(Icu_ChannelType Channel)
{
    const Icu_Ipw_ChannelConfigType *ChannelConfig;
    uint32 crtIterCount = 0U;
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
    Mcl_ChannelType Mcl_DmaChannel = (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel;
    Icu_IndexType  noOfBufferElemToFill = 0U;

    Mcl_DmaChannelTransferListType Mcl_DmaChUpdateDestAddress[1U];
    Mcl_DmaChannelTransferListType Mcl_DmaChUpdateIterCount[2U];

    Mcl_GetDmaChannelParam((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel, \
                            MCL_DMA_CH_GET_BEGIN_ITER_COUNT, &crtIterCount);

    /* ChannelConfig - Address of logic configuration for channel on u32UserID partition. */
    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
    {
        Icu_aBufferIndex[Channel] += (uint16)crtIterCount;
        noOfBufferElemToFill = Icu_aBufferSize[Channel] - Icu_aBufferIndex[Channel];

        /* Handling notification*/
        if ((Icu_IndexType)0 != Icu_aBufferNotify[Channel])
        {
            Icu_aNotifyCount[Channel] += (uint16)crtIterCount;
            if  (Icu_aNotifyCount[Channel] == Icu_aBufferNotify[Channel])
            {
                Icu_aNotifyCount[Channel] = 0U;
                /* Call User Notification Function and/or Wakeup Function */
                Icu_CallNotification(Channel, u32UserID);
            }
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();

    if (0U == noOfBufferElemToFill)
    {
        if ((uint8) ICU_CIRCULAR_BUFFER ==  \
                (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_ChannelProperty)
        {
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
            {
                Icu_aBufferIndex[Channel] = 0U;
                if ((Icu_aBufferNotify[Channel] < Icu_aBufferSize[Channel]) && ((Icu_IndexType)0 != Icu_aBufferNotify[Channel]))
                {
                    Mcl_DmaChUpdateDestAddress[0U].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
                    Mcl_DmaChUpdateDestAddress[0U].Value = (uint32)Icu_aBuffer[Channel];
                    Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateDestAddress, 1U);
                }

                if ((Icu_aBufferSize[Channel] > (Icu_aBufferNotify[Channel] - Icu_aNotifyCount[Channel])) &&
                    ((Icu_IndexType)0U != Icu_aBufferNotify[Channel]))
                {
                    Mcl_DmaChUpdateIterCount[0U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
                    Mcl_DmaChUpdateIterCount[0U].Value = (uint32)Icu_aBufferNotify[Channel] - (uint32)Icu_aNotifyCount[Channel];
                    Mcl_DmaChUpdateIterCount[1U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
                    Mcl_DmaChUpdateIterCount[1U].Value = (uint32)0U;
                    Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateIterCount, 2U);
                }
            }
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
        }
        else /* if linear buffer stop the timestamp*/
        {
            Icu_Ipw_StopTimestamp(ChannelConfig);
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
        }
    }
    else
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
        {
            if (crtIterCount < Icu_aBufferNotify[Channel])
            {
                Mcl_DmaChUpdateIterCount[0U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
                Mcl_DmaChUpdateIterCount[0U].Value = Icu_aBufferNotify[Channel];
                Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateIterCount, 1U);
            }
            if (noOfBufferElemToFill < Icu_aBufferNotify[Channel])
            {
                Mcl_DmaChUpdateIterCount[0U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
                Mcl_DmaChUpdateIterCount[0U].Value = noOfBufferElemToFill;
                Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateIterCount, 1U);
            }
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
    }
}
#endif /* (ICU_TIMESTAMP_USES_DMA == STD_ON) */

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
void Icu_SignalMeasurementDmaProcessing(Icu_ChannelType Channel)
{
    uint32 u32UserID = Icu_GetUserID();
    uint8 u8index;
    Icu_ValueType BufferValue1;
    Icu_ValueType BufferValue2;
    Icu_ValueType BufferValue3;
    Mcl_DmaChannelTransferListType Mcl_DmaChUpdateDestAddress[1U];
    Mcl_DmaChannelTransferListType Mcl_DmaChUpdateIterCount[1U];
    uint8 ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
    Mcl_ChannelType Mcl_DmaChannel =(*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Mcl_DmaChannel;
    Icu_ActivationType Activation = ICU_BOTH_EDGES;

    Icu_ValueType Icu_aActivePulseWidth;
    Icu_ValueType Icu_aPeriod;

    const Icu_Ipw_ChannelConfigType *ChannelConfig;

    /* Address of logic configuration for channel on u32UserID partition */
    ChannelConfig = ((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr;

    Mcl_SetDmaChannelCommand(Mcl_DmaChannel, MCL_DMA_CH_STOP_REQUEST);

    if ((uint32)1 == Icu_aIsSecondInterrupt[Channel])
    {
        BufferValue1 = Icu_aFirstEdgeTimeStamp[Channel];
        BufferValue2 = Icu_aDmaBuffer[Channel][0] & ICU_SHADOW_REGISTER_MAX_MASK;
        BufferValue3 = Icu_aDmaBuffer[Channel][1] & ICU_SHADOW_REGISTER_MAX_MASK;
        Mcl_DmaChUpdateDestAddress[0U].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
        Mcl_DmaChUpdateDestAddress[0U].Value = (uint32)&Icu_aDmaBuffer[Channel][0];
        Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateDestAddress, 1U);
        Mcl_SetDmaChannelCommand(Mcl_DmaChannel, MCL_DMA_CH_START_REQUEST);

        /* Store the aPeriod value */
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09();
        {
            if(BufferValue2 > BufferValue1)
            {
                Icu_aActivePulseWidth = BufferValue2 - BufferValue1;
            }
            else
            {
                Icu_aActivePulseWidth = (ICU_CAPTURE_REGISTER_MASK(Icu_Ipw_GetIPVMaxCouter(ChannelConfig)) - BufferValue1) + BufferValue2;
            }

            /* Store the aPeriod value */
            if(BufferValue3 > BufferValue1)
            {
                Icu_aPeriod =  BufferValue3 - BufferValue1;
            }
            else
            {
                Icu_aPeriod = (ICU_CAPTURE_REGISTER_MASK(Icu_Ipw_GetIPVMaxCouter(ChannelConfig)) - BufferValue1) + BufferValue3;
            }
            Icu_Ipw_SetPWandPeriod(ChannelConfig, Icu_aActivePulseWidth, Icu_aPeriod);
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09();
        Icu_aFirstEdgeTimeStamp[Channel] = Icu_aDmaBuffer[Channel][1] & ICU_SHADOW_REGISTER_MAX_MASK;
    }
    else
    {
        Icu_aIsSecondInterrupt[Channel] = (uint16)1;
        Icu_aFirstEdgeTimeStamp[Channel] = Icu_aDmaBuffer[Channel][0] & ICU_SHADOW_REGISTER_MAX_MASK;
        Mcl_DmaChUpdateDestAddress[0U].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;
        Mcl_DmaChUpdateDestAddress[0U].Value = (uint32)&Icu_aDmaBuffer[Channel][0];
        Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateDestAddress, 1U);
        Mcl_DmaChUpdateIterCount[0U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
        Mcl_DmaChUpdateIterCount[0U].Value = (uint16)ICU_DMA_MAJORLOOP_COUNT;
        Mcl_SetDmaChannelTransferList(Mcl_DmaChannel, Mcl_DmaChUpdateIterCount, 1U);
        Mcl_SetDmaChannelCommand(Mcl_DmaChannel, MCL_DMA_CH_START_REQUEST);
        for(u8index = 0U; u8index < ICU_DMA_MAJORLOOP_COUNT; u8index++)
        {
            Icu_aDmaBuffer[Channel][u8index] = (uint16)0;
        }
        Icu_Ipw_SetActivationCondition(Activation, \
                       (*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_IpwChannelConfigPtr);
    }
    Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
}
#endif/* ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON */

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
* @pre Icu_Init must be called before.
* @pre The given channel must be configured in SignalMeasurement or in Timestamp mode
* @implements Icu_GetCaptureRegisterValue_Activity
**/
Icu_ValueType Icu_GetCaptureRegisterValue(Icu_ChannelType Channel)
{
    Icu_ValueType tempValue = (Icu_ValueType)0U;
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType ChannelIndex;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType validchannel = Icu_ValidateCallAndChannel \
                (Channel,(uint8)((1U << ICU_MODE_SIGNAL_MEASUREMENT) | (uint8)(1U << ICU_MODE_TIMESTAMP)), ICU_GET_CAPTURE_REGISTER_VALUE_ID, u32UserID);

    if ((Std_ReturnType)E_OK == validchannel)
    {
#endif
        ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
        tempValue = (Icu_ValueType)Icu_Ipw_GetCaptureRegisterValue(((*Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr)[ChannelIndex]).Icu_IpwChannelConfigPtr);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
#endif
    return tempValue;
}
#endif

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))

/**
* @brief      This function returns the signals High time, Low time and Period without using the
*             channel interrupt.
* @details    This function returns the signals High time, Low time and Period without using the
*             channel interrupt.
* @param[in]  Channel       Logical number of the ICU channel
* @pre        Icu_Init must be called before.
**/
void Icu_GetPulseWidth(Icu_ChannelType Channel)
{
    uint32 u32UserID = Icu_GetUserID();
    Icu_ChannelType ChannelIndex;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Std_ReturnType validchannel1 = Icu_ValidateCallAndChannel \
                (Channel,(uint8)(1U << ICU_MODE_SIGNAL_MEASUREMENT), ICU_GET_PULSE_WIDTH_ID, u32UserID);

    if ((Std_ReturnType)E_OK == validchannel1)
    {
        if((Std_ReturnType)E_OK == Icu_ValidateSignalMeasureWithoutInterrupt(Channel, ICU_GET_PULSE_WIDTH_ID, u32UserID))
        {
#endif
            ChannelIndex = (*Icu_pCfgPtr[u32UserID]->Icu_IndexChannelMap)[Channel];
            Icu_Ipw_GetPulseWidth((*(Icu_pCfgPtr[u32UserID]->Icu_ChannelConfigPtr))[ChannelIndex].Icu_IpwChannelConfigPtr);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    }
#endif
}
#endif

/**
 * @brief The callback function
 */
void Icu_LogicChStateCallback(uint16 logicChannel, uint8 mask, boolean set)
{
    if (set)
    {
        Icu_SetBitChState((Icu_ChannelType)logicChannel, (Icu_ChannelStateType)mask);
    }
    else
    {
        Icu_ClearBitChState((Icu_ChannelType)logicChannel, (Icu_ChannelStateType)mask);
    }
}


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
