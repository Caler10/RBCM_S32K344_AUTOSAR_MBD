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

#ifndef GPT_PIT_TYPES_H
#define GPT_PIT_TYPES_H
/**
*   @file    Pit_Ip_Types.h
*
*   @addtogroup pit_ip Pit IPL
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
#include "Pit_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define PIT_IP_TYPES_VENDOR_ID                       43
#define PIT_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define PIT_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define PIT_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define PIT_IP_TYPES_SW_MAJOR_VERSION                5
#define PIT_IP_TYPES_SW_MINOR_VERSION                0
#define PIT_IP_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (PIT_IP_DEFINES_VENDOR_ID_CFG != PIT_IP_TYPES_VENDOR_ID)
    #error "Pit_Ip_Cfg_Defines.h and Pit_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((PIT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != PIT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PIT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != PIT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PIT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG != PIT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pit_Ip_Cfg_Defines.h and Pit_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((PIT_IP_DEFINES_SW_MAJOR_VERSION_CFG != PIT_IP_TYPES_SW_MAJOR_VERSION) || \
     (PIT_IP_DEFINES_SW_MINOR_VERSION_CFG != PIT_IP_TYPES_SW_MINOR_VERSION) || \
     (PIT_IP_DEFINES_SW_PATCH_VERSION_CFG != PIT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pit_Ip_Cfg_Defines.h and Pit_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/

#if (PIT_IP_USED == STD_ON)
/**
* @internal
* @brief PIT Channels defines
*/
#ifdef PIT_IP_RTI_CHANNEL_EXISTS
#define RTI         ((uint8)4)
#endif

#endif /*PIT_IP_USED == STD_ON*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/**
 * @brief     Pit Status error
 * @details   Status error
 */
typedef enum
{
    PIT_IP_SUCCESS = E_OK,      /**< @brief Status value is SUCCESS */
    PIT_IP_ERROR = E_NOT_OK     /**< @brief Status value is ERROR   */
} Pit_Ip_StatusType;

/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    PIT_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief hannel mode -  continuous mode */
    PIT_IP_CH_MODE_ONESHOT    = 1U       /**< @brief hannel mode -  one-shot mode.  */
} Pit_Ip_ChannelModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @internal
* @brief    Callback type for each channel
* @details  Pit_Ip_CallbackType
*
*/
typedef void (*Pit_Ip_CallbackType)(uint8 callbackParam);

/**
* @internal
* @brief       Structure to configure the PIT
* @details     This structure holds the configuration settings for the PIT
*
*/
typedef struct
{
#if (defined(PIT_IP_MDIS_BIT_EXISTS) && (PIT_IP_MDIS_BIT_EXISTS == STD_ON))
    boolean enableStandardTimers;  /**< @brief Enable standard timer */
#endif
#if (defined(PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
    boolean enableRTITimer;        /**< @brief Enable real time interrupt timer */
#endif
    boolean stopRunInDebug;        /**< @brief Stop timer running in debug mode */
} Pit_Ip_InstanceConfigType;

/**
* @internal
* @brief       Structure to configure the PIT timer channel
* @details     This structure holds the configuration settings for the PIT timer channel
*
*/
typedef struct
{
    uint8                      hwChannel;           /**< @brief Timer channel number          */
    boolean                    enableInterrupt;     /**< @brief Enable interrupt generation   */
    Pit_Ip_CallbackType        callback;            /**< @brief callback                      */
    uint8                      callbackParam;       /**< @brief callbackParam                 */
    Pit_Ip_ChannelModeType     channelMode;         /**< @brief channelMode                   */
} Pit_Ip_ChannelConfigType;

/**
* @internal
* @brief       internal context structure
* @details     This structure is used by the IPL driver for internal logic.
*              The content is populated on Init
*
*/
typedef struct
{
    boolean                    chInit;                  /**< @brief chInit        */
    Pit_Ip_CallbackType        callback;                /**< @brief callback      */
    uint8                      callbackParam;           /**< @brief callbackParam */
    Pit_Ip_ChannelModeType     channelMode;             /**< @brief channelMode   */
} Pit_Ip_State;

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
#endif /*PIT_IP_TYPES_H*/

