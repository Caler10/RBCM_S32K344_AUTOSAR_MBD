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
#ifndef EMIOS_ICU_IP_DEFINES_H
#define EMIOS_ICU_IP_DEFINES_H

/**
 *   @file
 *   @implements Emios_Icu_Ip_Defines.h_Artifact
 *   @addtogroup emios_icu_ip EMIOS IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Std_Types.h"
/* Include platform header file. */
#include "S32K344_EMIOS.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_ICU_IP_DEFINES_VENDOR_ID                       43
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_ICU_IP_DEFINES_SW_MAJOR_VERSION                5
#define EMIOS_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define EMIOS_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define EMIOS_ICU_IP_USED                        (STD_ON)

#if (STD_ON == EMIOS_ICU_IP_USED)

#define EMIOS_ICU_IP_CHANNEL_24_USED              (STD_OFF)

/** @brief The number of EMIOS instances available on platform */
#define EMIOS_ICU_IP_INSTANCE_COUNT               (3U)

/** @brief The number of channels available on each EMIOS instance */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS              (24U)

/** @brief The number of eMios channels are used in configuration */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS_USED         ((uint8)3U)

#define EMIOS_ICU_IP_CHANNEL_NOT_USED             ((uint8)0xFF)

#define EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED       ((uint8)0xFE)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define EMIOS_ICU_IP_DEV_ERROR_DETECT             (STD_ON)
#define EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL         (EMIOS_ICU_IP_DEV_ERROR_DETECT)

/** @brief Adds or removes all services related to the timestamp functionality. */
#define EMIOS_ICU_IP_TIMESTAMP_API                (STD_ON)

/** @brief Adds or removes all services related to the edge detect functionality. */
#define EMIOS_ICU_IP_EDGE_DETECT_API              (STD_ON)

/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API       (STD_ON)

/** @brief Adds or removes all services related to the input level. */
#define EMIOS_ICU_IP_GET_INPUT_LEVEL_API          (STD_OFF)

/** @brief define SAIC mode if any channels not supporting IPWM or IPM mode is configured. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE          (STD_OFF)

/** @brief Adds or removes the service set Max Counter for eMios. */
#define EMIOS_ICU_IP_SET_MAX_COUNTER              (STD_OFF)

/** @brief Adds or removes the service set Initial Counter for eMios. */
#define EMIOS_ICU_IP_SET_INITIAL_COUNTER          (STD_OFF)

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define EMIOS_ICU_IP_DEINIT_API                   (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define EMIOS_ICU_IP_SET_MODE_API                 (STD_ON)

/** @brief Adds or removes all services related to edge count functionality. */
#define EMIOS_ICU_IP_EDGE_COUNT_API               (STD_ON)

/** @brief Adds or removes all services related to input state functionality. */
#define EMIOS_ICU_IP_GET_INPUT_STATE_API          (STD_ON)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define EMIOS_ICU_IP_DUAL_CLOCK_MODE_API          (STD_OFF)

#define EMIOS_ICU_IP_CAPTURERGISTER_API           (STD_OFF)

/** @brief Adds or Removes the code related to overflow notification */
#define EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API    (STD_ON)

/** @brief Define if global variables need to be placed in non-cache area or not */
#define EMIOS_ICU_IP_NO_CACHE_USED                (STD_OFF)

/** @brief Adds or removes the support measurement with DMA. */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA   (STD_OFF)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA           (STD_OFF)

/** @brief Adds or removes the support measurement with DMA in IPL */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL   (STD_OFF)
#define EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT              (2U)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL           (STD_OFF)

#define EMIOS_ICU_IP_GET_PULSE_WIDTH_API          (STD_ON)


#define EMIOS_ICU_USES_MCL_DRIVER          (STD_ON)

#if ((EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON) || (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON))
#define EMIOS_ICU_IP_COUNTER_MASK              ((uint32)65535)
#endif

/** @brief Adds or removes SAIC with edge capturing support. */
#define EMIOS_ICU_IP_SAIC_EDGE_CAPTURING_SUPPORT                  (STD_OFF)

#define EMIOS_ICU_IP_INITIAL_INDEX_OF_CHANNELS \
    { \
        {255U, 255U, 255U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, \
        {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, \
        {255U, 1U, 2U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U} \
    } \

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 eMios_Icu_ValueType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_DEFINES_H */

