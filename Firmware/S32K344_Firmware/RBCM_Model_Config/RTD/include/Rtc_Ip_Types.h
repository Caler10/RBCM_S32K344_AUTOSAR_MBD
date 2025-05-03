/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef RTC_IP_TYPES_H
#define RTC_IP_TYPES_H

/**
*   @file       Rtc_Ip_Types.h
*
*   @addtogroup rtc_ip Rtc IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Rtc_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define RTC_IP_TYPES_VENDOR_ID                       43
#define RTC_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define RTC_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define RTC_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define RTC_IP_TYPES_SW_MAJOR_VERSION                5
#define RTC_IP_TYPES_SW_MINOR_VERSION                0
#define RTC_IP_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (RTC_IP_TYPES_VENDOR_ID != RTC_IP_DEFINES_VENDOR_ID_CFG)
    #error "Rtc_Ip_Types.h and Rtc_Ip_Cfg_Defines.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((RTC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != RTC_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (RTC_IP_TYPES_AR_RELEASE_MINOR_VERSION != RTC_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (RTC_IP_TYPES_AR_RELEASE_REVISION_VERSION != RTC_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Rtc_Ip_Types.h and Rtc_Ip_Cfg_Defines.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((RTC_IP_TYPES_SW_MAJOR_VERSION != RTC_IP_DEFINES_SW_MAJOR_VERSION_CFG) || \
     (RTC_IP_TYPES_SW_MINOR_VERSION != RTC_IP_DEFINES_SW_MINOR_VERSION_CFG) || \
     (RTC_IP_TYPES_SW_PATCH_VERSION != RTC_IP_DEFINES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Rtc_Ip_Types.h and Rtc_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (RTC_IP_USED == STD_ON)
/**
* @internal
* @brief RTC Channels defines
*/
#define     SECONDS_IN_A_DAY           (86400UL)
#define     SECONDS_IN_A_HOUR          (3600U)
#define     SECONDS_IN_A_MIN           (60U)
#define     MINS_IN_A_HOUR             (60U)
#define     HOURS_IN_A_DAY             (24U)
#define     DAYS_IN_A_YEAR             (365U)
#define     DAYS_IN_A_LEAP_YEAR        (366U)
#define     YEAR_RANGE_START           (1970U)
#define     YEAR_RANGE_END             (2099U)

#define MAX_32BIT ((uint32)0xFFFFFFFFUL)
/**
* @internal
* @brief Value used for approximation when is made the conversion from ticks to seconds
*/
#define RTC_IP_PPM_TOLERANCE           (100UL)
#define RTC_IP_MINIMUM_API_VALUE       (4UL)
#define RTC_IP_SYNC_TICKS_VALUE        (6UL)

#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief     Enum containing the RTC module clock sources
* @details   Rtc_Ip_ClockSelectType
*
*/
typedef enum
{
    RTC_IP_CLOCK_SOURCE_0 = 0,      /**< @brief RTC clock source 0 */
    RTC_IP_CLOCK_SOURCE_1 = 1,      /**< @brief RTC clock source 1 */
    RTC_IP_CLOCK_SOURCE_2 = 2,      /**< @brief RTC clock source 2 */
    RTC_IP_CLOCK_SOURCE_3 = 3       /**< @brief RTC clock source 3 */
} Rtc_Ip_ClockSelectType;

/**
* @brief     Enum containing RTC interrupt type
* @details   Rtc_Ip_InterruptType
*
*/
typedef enum
{
    RTC_IP_COUNTER_INTERRUPT  = 0x00U,      /**< @brief RTC_COUNTER_INTERRUPT  */
    RTC_IP_API_INTERRUPT      = 0x01U,      /**< @brief RTC_API_INTERRUPT      */
    RTC_IP_ROLLOVER_INTERRUPT = 0x02U       /**< @brief RTC_ROLLOVER_INTERRUPT */
} Rtc_Ip_InterruptType;

/**
* @brief Enum containing RTC interrupt mode
* @details    Rtc_Ip_ModeType
*
*/
typedef enum
{
    RTC_IP_API_MODE  = 0x00U,  /**< @brief API(Autonomous periodic interrupt) Mode  */
    RTC_IP_RTC_MODE  = 0x01U   /**< @brief RTC Mode                                 */
} Rtc_Ip_ModeType;

/**
* @brief     Rtc Status error
* @details   Status error
*
*/
typedef enum
{
    RTC_IP_SUCCESS = E_OK,      /**< @brief Status value is SUCCESS */
    RTC_IP_ERROR = E_NOT_OK     /**< @brief Status value is ERROR   */
} Rtc_Ip_StatusType;


/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    RTC_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief channel mode -  continuous mode */
    RTC_IP_CH_MODE_ONESHOT    = 1U       /**< @brief channel mode -  one-shot mode.  */
} Rtc_Ip_ChannelModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @internal
* @brief    Callback type for each channel
* @details  Rtc_Ip_CallbackType
*
*/
typedef void (*Rtc_Ip_CallbackType)(uint8 callbackParam);

/**
* @internal
* @brief       Structure to configure the RTC
* @details     This structure holds the configuration settings for the RTC
*
*/
typedef struct
{
    boolean                      freezeEnable;          /**< @brief Enable freezing the counter in debug mode */
    boolean                      divideBy512;           /**< @brief Enable clock divide by 512                */
    boolean                      divideBy32;            /**< @brief Enable clock divide by 32                 */
    Rtc_Ip_ClockSelectType       clockSelect;           /**< @brief RTC Clock Select                          */
    Rtc_Ip_CallbackType          callback;              /**< @brief Periodic interrupt callback               */
    uint8                        callbackParam;         /**< @brief Pointer to callback parameters            */
    Rtc_Ip_ChannelModeType       channelMode;           /**< @brief channelMode                               */
} Rtc_Ip_ConfigType;

/**
* @internal
* @brief   RTC Time Date structure
* @details Rtc_Ip_TimedateType
*
*/
typedef struct
{
    uint16                  year;      /**< @brief Year       */
    uint16                  month;     /**< @brief Month      */
    uint16                  day;       /**< @brief Day        */
    uint16                  hour;      /**< @brief Hour       */
    uint16                  minutes;   /**< @brief Minutes    */
    uint8                   seconds;   /**< @brief Seconds    */
} Rtc_Ip_TimedateType;

/**
* @internal
* @brief   RTC alarm configuration
* @details Rtc_Ip_AlarmConfigType
*
*/
typedef struct
{
    Rtc_Ip_TimedateType     alarmTime;          /**< @brief Alarm time                                       */
    uint32                  repetitionInterval; /**< @brief Interval of repetition in seconds                */
    uint32                  numberOfRepeats;    /**< @brief Number of alarm repeats                          */
    boolean                 repeatForever;      /**< @brief Repeat forever if set, discard number of repeats */
    boolean                 alarmIntEnable;     /**< @brief Enable alarm interrupt                           */
    Rtc_Ip_CallbackType     alarmCallback;      /**< @brief Pointer to the user callback method.             */
    uint8                   callbackParams;     /**< @brief Pointer to the callback parameters.              */
} Rtc_Ip_AlarmConfigType;


/**
* @internal
* @brief       Internal context structure Rtc_Ip_State
* @details     This structure is used by the IPL driver for internal logic.
*              The content is populated on Init.
*
*/
typedef struct
{
    boolean                 alarmInit;           /**< @brief alarmInit                                                             */
    uint32                  repetitionInterval;  /**< @brief Interval of repetition in seconds                                     */
    volatile uint32         numberOfRepeats;     /**< @brief Number of alarm repeats                                               */
    boolean                 repeatForever;       /**< @brief Repeat forever if set, discard number of repeats                      */
    boolean                 alarmIntEnable;      /**< @brief Enable alarm interrupt                                                */
    Rtc_Ip_CallbackType     alarmCallback;       /**< @brief Pointer to the user callback method.                                  */
    uint8                   callbackParams;      /**< @brief Pointer to the callback parameters.                                   */
    volatile boolean        isAlarmTimeNew;      /**< @brief Check if there is a new alarm                                         */
    uint32                  timeOffset;          /**< @brief Time offset saved when the time and date were configured              */
    uint32                  startTime;           /**< @brief Time stamp with the start time, used for calculating the current time */
    volatile uint32         rolloverCount;       /**< @brief Overflow count, it is incremented when the counter has overflowed     */
    uint32                  ticksPerSecond;      /**< @brief Number of ticks per second                                            */
    boolean                 chInit;              /**< @brief chInit                                                                */
    Rtc_Ip_CallbackType     callback;            /**< @brief callback                                                              */
    uint8                   callbackParam;       /**< @brief callbackParam                                                         */
    Rtc_Ip_ChannelModeType  channelMode;         /**< @brief channelMode                                                           */
} Rtc_Ip_State;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /*RTC_IP_TYPES_H*/
