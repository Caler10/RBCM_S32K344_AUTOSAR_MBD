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

#ifndef ICU_TYPES_H
#define ICU_TYPES_H

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
#include "Std_Types.h"
#include "Icu_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_TYPES_VENDOR_ID                       43
#define ICU_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_TYPES_AR_RELEASE_MINOR_VERSION        7
#define ICU_TYPES_AR_RELEASE_REVISION_VERSION     0
#define ICU_TYPES_SW_MAJOR_VERSION                5
#define ICU_TYPES_SW_MINOR_VERSION                0
#define ICU_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_TYPES_VENDOR_ID != ICU_CFG_VENDOR_ID)
    #error "Icu_Types.h and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_TYPES_AR_RELEASE_MINOR_VERSION != ICU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_TYPES_AR_RELEASE_REVISION_VERSION != ICU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Types.h and Icu_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_TYPES_SW_MAJOR_VERSION != ICU_CFG_SW_MAJOR_VERSION) || \
     (ICU_TYPES_SW_MINOR_VERSION != ICU_CFG_SW_MINOR_VERSION) || \
     (ICU_TYPES_SW_PATCH_VERSION != ICU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Types.h and Icu_Cfg.h are different"
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

/**
* @brief Allow enabling or disabling of all interrupts which are not required for the ECU wakeup
* @implements Icu_ModeType_enum
*/
typedef enum
{
    ICU_MODE_NORMAL = 0x00U,    /**< @brief Normal operation, all used interrupts are enabled
                                   * according to the notification requests. */
    ICU_MODE_SLEEP  = 0x01U     /**< @brief Reduced power operation. In sleep mode only those
                                   * notifications are available which are configured as wakeup capable. */
} Icu_ModeType;

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief          Input state of an ICU channel.
* @implements     Icu_InputStateType_enum
*/
typedef enum
{
    ICU_ACTIVE = 0x00U,         /**< @brief An activation edge has been detected. */
    ICU_IDLE   = 0x01U          /**< @brief No activation edge has been detected since the last call of
                                   *  Icu_GetInputState() or Icu_Init(). */
} Icu_InputStateType;
#endif

/**
* @brief Definition of the measurement mode type.
* @implements Icu_MeasurementModeType_enum
*/
typedef enum
{
    ICU_MODE_SIGNAL_EDGE_DETECT = 0x00U,    /**< @brief Mode for detecting edges */
    ICU_MODE_SIGNAL_MEASUREMENT = 0x01U,    /**< @brief Mode for measuring different times between
                                               * various configurable edges */
    ICU_MODE_TIMESTAMP          = 0x02U,    /**< @brief Mode for capturing timer values on
                                               * configurable edges */
    ICU_MODE_EDGE_COUNTER       = 0x03U,     /**< @brief Mode for counting edges on configurable edges */
} Icu_MeasurementModeType;


#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief Definition of the measurement property type.
* @implements Icu_SignalMeasurementPropertyType_enum
*/
typedef enum
{
    ICU_LOW_TIME    = 0x00U,    /**< @brief The channel is configured for reading the
                                   * elapsed Signal Low Time. */
    ICU_HIGH_TIME   = 0x01U,    /**< @brief The channel is configured for reading the
                                   * elapsed Signal High Time. */
    ICU_PERIOD_TIME = 0x02U,    /**< @brief The channel is configured for reading the
                                   * elapsed Signal Period Time. */
    ICU_DUTY_CYCLE  = 0x03U     /**< @brief The channel is configured to read values which
                                   * are needed for calculating the duty cycle
                                   * (coherent Active and Period Time). */
} Icu_SignalMeasurementPropertyType;
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief Definition of the Time-stamp measurement property type.
* @implements Icu_TimestampBufferType_enum
*/
typedef enum
{
    ICU_LINEAR_BUFFER    = 0x00U,     /**< @brief The buffer will just be filled once. */
    ICU_CIRCULAR_BUFFER  = 0x01U      /**< @brief After reaching the end of the buffer, the driver
                                         * restarts at the beginning of the buffer. */
} Icu_TimestampBufferType;
#endif /* (STD_ON == ICU_TIMESTAMP_API) */

/** @brief Definition of the type of activation of an ICU channel.
* @implements Icu_ActivationType_enum
*/
typedef enum
{
    ICU_RISING_EDGE  = 0x00U,   /**< @brief An appropriate action shall be executed when a rising
                                   * edge occurs on the ICU input signal */
    ICU_FALLING_EDGE = 0x01U,   /**< @brief An appropriate action shall be executed when a falling
                                   * edge occurs on the ICU input signal. */
    ICU_BOTH_EDGES   = 0x02U    /**< @brief An appropriate action shall be executed when either a
                                   * rising or falling edge occur on the ICU input signal. */
} Icu_ActivationType;


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief   Return the status of the pin.
* @details Enumeration of to check the status of pin.
*/
typedef enum
{
    /** @brief Default Input PIN Status */
    ICU_LEVEL_LOW    = 0x0U,
    /** @brief As Icu_GetInputState do not give the Actual PIN status user can call the Non Autosar API
        Icu_GetInputLevel to get the Actual status of PIN*/
    ICU_LEVEL_HIGH = 0x1U
} Icu_LevelType;

#endif /* ICU_GET_INPUT_LEVEL_API */


#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/**
* @brief   Definition of prescaler type.
*
*/
typedef enum
{
    ICU_NORMAL_CLOCK_MODE     = 0x0U,                /**< @brief Default channel prescaler. */
    ICU_ALTERNATE_CLOCK_MODE  = 0x1U                 /**< @brief Alternate channel prescaler mode */
} Icu_SelectPrescalerType;

#endif /* ICU_DUAL_CLOCK_MODE_API */


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief ICU Channel state type. */
typedef uint8                           Icu_ChannelStateType;

/** @brief This gives the numeric ID (hardware channel number) of an ICU channel
* @implements Icu_ChannelType_typedef
*/
typedef uint16                          Icu_ChannelType;

/** @brief Type for saving the timer register width value. 
* @implements Icu_ValueType_typedef
*/
typedef Icu_TimerRegisterWidthType      Icu_ValueType;

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief          Type for saving the ICU Hardware specific index
* @implements     Icu_IndexType_typedef
*/
typedef Icu_HwSpecificIndexType         Icu_IndexType;
#endif /* (STD_ON == ICU_TIMESTAMP_API) */

#if (STD_ON == ICU_EDGE_COUNT_API)
/** @brief          Type for saving hardware specific edge number
* @implements     Icu_EdgeNumberType_typedef
*/
typedef Icu_HwSpecificEdgeNumberType    Icu_EdgeNumberType;
#endif /* (STD_ON == ICU_EDGE_COUNT_API) */

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
/**
* @brief          Type for saving the Wakeup value
*/
typedef uint32                          Icu_WakeupValueType;
#endif 

/**
* @brief          Type for saving the ICU measurement submode type
*
*/
typedef uint16                           Icu_MeasurementSubModeType;

/** @brief The notification functions shall have no parameters and no return value.
* @implements     Icu_NotifyType_typedef
*/
typedef void                             (*Icu_NotifyType)(void);

#if (ICU_GET_DUTY_CYCLE_VALUES_API== STD_ON)
/**
* @brief Structure that contains ICU Duty cycle parameters. It contains the values needed for
*        calculating duty cycles i.e Period time value and active time value.
* @implements Icu_DutyCycleType_struct
*/
typedef struct
{
    Icu_ValueType ActiveTime;         /**< @brief Low or High time value. */
    Icu_ValueType PeriodTime;         /**< @brief Period time value. */
} Icu_DutyCycleType;
#endif


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_TYPES_H */
