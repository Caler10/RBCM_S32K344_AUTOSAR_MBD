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

#ifndef SIUL2_ICU_IP_TYPES
#define SIUL2_ICU_IP_TYPES

/**
 *     @file
 * 
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Siul2_Icu_Ip_Defines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_TYPES_VENDOR_ID                   43
#define SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION    4
#define SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION    7
#define SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION 0
#define SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION            5
#define SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION            0
#define SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION            0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_TYPES_VENDOR_ID != SIUL2_ICU_IP_DEFINES_VENDOR_ID)
    #error "Siul2_Icu_Ip_Types.h and Siul2_Icu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Types.h and Siul2_Icu_Ip_Defines.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION  != SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip_Types.h and Siul2_Icu_Ip_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @brief         Definition of prescaler type.
 * @details       Definition of prescaler type (Normal or Alternate)
 */
typedef enum
{
    SIUL2_ICU_NORMAL_CLK        = 0x0U,  /**< @brief Normal prescaler         */
    SIUL2_ICU_ALTERNATE_CLK     = 0x1U,  /**< @brief Alternate prescaler      */
} Siul2_Icu_Ip_ClockModeType;
#endif

/**
 * @brief         Siul2_Icu_ActivationType
 * @details       This indicates the activation type SIUL2 channel (Rising, Falling or Both)
 */
typedef enum
{
    SIUL2_ICU_DISABLE           = 0x0U,  /**< @brief Interrupt disable.         */
    SIUL2_ICU_RISING_EDGE       = 0x1U,  /**< @brief Interrupt on rising edge.  */
    SIUL2_ICU_FALLING_EDGE      = 0x2U,  /**< @brief Interrupt on falling edge. */
    SIUL2_ICU_BOTH_EDGES        = 0x3U   /**< @brief Interrupt on either edge.  */
} Siul2_Icu_Ip_EdgeType;

/**
 * @brief       Siul2_Icu_IrqDmaSelectType
 * @details     This indicates the type of request DMA or IRQ when activation edge is detected
 */
typedef enum
{
    SIUL2_ICU_IRQ   = 0x0U, /**< @brief Generate an interrupt request */
    SIUL2_ICU_DMA   = 0x1U  /**< @brief Generate an DMA request       */
} Siul2_Icu_Ip_IrqDmaSelectType;

/** @brief SIUL2 IP layer operation status. */
typedef enum
{
    SIUL2_ICU_IP_SUCCESS     = 0x0U, /**< @brief Status for success operation return. */
    SIUL2_ICU_IP_ERROR       = 0x1U  /**< @brief General error return status.         */
}Siul2_Icu_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief The notification functions shall have no parameters and no return value.*/
typedef void                             (*Siul2_Icu_Ip_NotifyType)(void);
/** @brief Callback signature used in each channel with an active interrupt. */
typedef void (*Siul2_Icu_Ip_CallbackType)(uint16 callbackParam1, boolean callbackParam2);

/** @brief    SIUL2 IP layer channel configuration structure. */
typedef struct
{
    uint8                           hwChannel;      /**< @brief The interrupt pin index                      */
    boolean                         digFilterEn;    /**< @brief Enables digital filter                       */
    uint8                           maxFilterCnt;   /**< @brief Maximum interrupt filter value               */
    Siul2_Icu_Ip_IrqDmaSelectType   intSel;         /**< @brief Switch between DMA and interrupt request     */
    Siul2_Icu_Ip_EdgeType           intEdgeSel;     /**< @brief The type of edge event                       */
    Siul2_Icu_Ip_CallbackType       callback;       /**< @brief Pointer to the callback function.            */
    Siul2_Icu_Ip_NotifyType         Siul2ChannelNotification; /**< @brief The notification functions shall have no parameters and no return value.*/
    uint8                           callbackParam;            /**< @brief The logic channel for which callback is set. */
} Siul2_Icu_Ip_ChannelConfigType;

/** @brief    SIUL2 IP layer instance configuration structure. */
typedef struct
{
    uint8                           intFilterClk;       /**< @brief Siul2 interrupt clock prescaller digital filter */
    uint8                           altIntFilterClk;    /**< @brief Siul2 interrupt clock prescaller digital filter */
} Siul2_Icu_Ip_InstanceConfigType;

/**
 * @brief    SIUL2 IP state structure.
 * @details  This structure is used by the IPL driver for internal logic.
 *           The content is populated at initialization time.
 */
typedef struct
{
    boolean                   chInit;                   /**< @brief Initialization state. */
    Siul2_Icu_Ip_CallbackType callback;                 /**< @brief Pointer to the callback function. */
    Siul2_Icu_Ip_NotifyType   Siul2ChannelNotification; /**< @brief The notification functions for SIGNAL_EDGE_DETECT mode. */
    uint16                    callbackParam;            /**< @brief The logic channel for which callback is set. */
    boolean                   notificationEnable;       /**< @brief State of the notification. */
} Siul2_Icu_Ip_State;


/** @brief SIUL2 IP layer configuration structure. */
typedef struct
{
    uint8                                   numChannels;            /**< @brief Number of channels in the configuration. */
#if (STD_ON == SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT)
    uint8                                   interruptPdacSlot;      /**< @brief Configures Siul2 Interrupt PDAC Slot for VirtWrapper. */
#endif
    const Siul2_Icu_Ip_InstanceConfigType   *pInstanceConfig;       /**< @brief Pointer to the instance configuration.   */
    const Siul2_Icu_Ip_ChannelConfigType    (*pChannelsConfig)[];   /**< @brief Pointer to the channels configuration.   */
} Siul2_Icu_Ip_ConfigType;

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_TYPES */
