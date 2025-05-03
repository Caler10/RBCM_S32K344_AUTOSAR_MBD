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

#ifndef WKPU_IP_TYPES_H
#define WKPU_IP_TYPES_H

/**
 *     @file
 * 
 *     @addtogroup wkpu_icu_ip WKPU IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Wkpu_Ip_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WKPU_IP_TYPES_VENDOR_ID                     43
#define WKPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define WKPU_IP_TYPES_AR_RELEASE_MINOR_VERSION      7
#define WKPU_IP_TYPES_AR_RELEASE_REVISION_VERSION   0
#define WKPU_IP_TYPES_SW_MAJOR_VERSION              5
#define WKPU_IP_TYPES_SW_MINOR_VERSION              0
#define WKPU_IP_TYPES_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_TYPES_VENDOR_ID != WKPU_IP_DEFINES_VENDOR_ID)
    #error "Wkpu_Ip_Types.h and Wkpu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION  != WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_TYPES_AR_RELEASE_MINOR_VERSION  != WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_TYPES_AR_RELEASE_REVISION_VERSION   != WKPU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Types.h and Wkpu_Ip_Defines.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_TYPES_SW_MAJOR_VERSION  != WKPU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (WKPU_IP_TYPES_SW_MINOR_VERSION  != WKPU_IP_DEFINES_SW_MINOR_VERSION) || \
     (WKPU_IP_TYPES_SW_PATCH_VERSION  != WKPU_IP_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip_Types.h and Wkpu_Ip_Defines.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
#if (STD_ON == WKPU_IP_USED)

#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))
/**
 * @brief         NMI destination source
 */
typedef enum
{
#ifdef WKPU_IP_SUPPORT_NONE_REQUEST
    WKPU_IP_NMI_NONE               = 3U,    /**< @brief No NMI, critical interrupt, or machine check request generated */
#endif
#ifdef WKPU_IP_SUPPORT_MACHINE_CHK_REQ
    WKPU_IP_NMI_MACHINE_CHK_REQ    = 2U,   /**< @brief Machine check request interrupt */
#endif
#ifdef WKPU_IP_SUPPORT_CRITICAL_INT
    WKPU_IP_NMI_CRITICAL_INT       = 1U,   /**< @brief Critical interrupt */
#endif
#ifdef WKPU_IP_SUPPORT_NON_MASK_INT
    WKPU_IP_NMI_NON_MASK_INT       = 0U   /**< @brief Non-maskable interrupt */
#endif
} Wkpu_Ip_NmiDestSrcType;

/* @brief WKPU core source. */
typedef enum
{
    WKPU_CORE0       = 0U,    /*!< Core 0 */
    WKPU_CORE1       = 1U,    /*!< Core 1 */
    WKPU_CORE2       = 2U,    /*!< Core 2 */
    WKPU_CORE3       = 3U     /*!< Core 3 */
} Wkpu_Ip_CoreType;
#endif /* (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API)) */

/** @brief Edge event. */
typedef enum
{
    WKPU_IP_NONE_EDGE       = 0U,   /**< @brief None event */
    WKPU_IP_RISING_EDGE     = 1U,   /**< @brief Rising edge event */
    WKPU_IP_FALLING_EDGE    = 2U,   /**< @brief Falling edge event */
    WKPU_IP_BOTH_EDGES       = 3U    /**< @brief Both rising and falling edge event */
} Wkpu_Ip_EdgeType;

/**
 * @brief       Wkpu_Ip_StatusType
 * @details     This indicates the operation success or fail
 */
typedef enum
{
    WKPU_IP_SUCCESS     = 0x0U,  /**< @brief Status for success operation return. */
    WKPU_IP_ERROR       = 0x1U,  /**< @brief General error return status.         */
} Wkpu_Ip_StatusType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief The notification functions shall have no parameters and no return value.*/
typedef void                             (*Wkpu_Ip_NotifyType)(void);
#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))

/*!
 * @brief NMI configuration structure.
 */
 
typedef struct
{
    Wkpu_Ip_CoreType            core;               /**< @brief WKPU core source */
    Wkpu_Ip_NmiDestSrcType      destination;        /**< @brief NMI destination source */
    boolean                     wkpReqEn;           /**< @brief NMI request enable */
    boolean                     filterEn;           /**< @brief NMI filter enable */
    Wkpu_Ip_EdgeType            edgeEvent;          /**< @brief NMI edge events */
    boolean                     lockEn;             /**< @brief NMI configuration lock register */
} Wkpu_Ip_NmiCfgType;
#endif /* (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API)) */

#ifdef WKPU_IP_SUPPORT_INTERRUPT_REQUEST
/* Callback type for each channel */
typedef void (*Wkpu_Ip_CallbackType)(uint16 callbackParam1, boolean callbackParam2);

/** @brief    WKPU interrupt configuration structure. */
typedef struct
{
    uint8                   hwChannel;                 /**< @brief The WKPU hardware channel.                   */
    boolean                 filterEn;                  /**< @brief WKPU/interrupt filter enable.                */
    boolean                 pullEn;                    /**< @brief WKPU/interrupt pull enable.                  */
    Wkpu_Ip_EdgeType        edgeEvent;                 /**< @brief WKPU/interrupt edge events.                  */
#ifdef WKPU_IP_SUPPORT_SELECT_BOOT_MODE                
    boolean                 fullBoot;                  /**< @brief WKPU select boot mode. 
                                                        *          If true, WKPU will trigger a full boot,
                                                        *          otherwise it will trigger a shot boot.       */
#endif /* WKPU_IP_SUPPORT_SELECT_BOOT_MODE */
    Wkpu_Ip_CallbackType    callback;                  /**< @brief Pointer to the callback function.            */
    Wkpu_Ip_NotifyType      WkpuChannelNotification;   /**< @brief The notification functions shall have no parameters and no return value.*/
    uint16                  callbackParam;             /**< @brief The logic channel for which callback is set. */
} Wkpu_Ip_ChannelConfigType;
#endif /* WKPU_IP_SUPPORT_INTERRUPT_REQUEST */

/** @brief    Wkpu IP specific configuration structure type. */
typedef struct
{
#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))
    /** @brief Number of channels in NMI configuration */
    uint8                           numNMIChannels;
    /** @brief Pointer to channels configration */
    const Wkpu_Ip_NmiCfgType             (*pNMIChannelsConfig)[]; 
#endif
    /** @brief Number of channels in configuration */
    uint8                           numChannels;
    /** @brief Pointer to channels configration */
    const Wkpu_Ip_ChannelConfigType       (*pChannelsConfig)[];
} Wkpu_Ip_IrqConfigType;

/**
 * @brief    WKPU IP state structure.
 * @details  This structure is used by the IPL driver for internal logic.
 *           The content is populated at initialization time.
 */
typedef struct
{
    /** @brief Initialization state. */
    boolean                     chInit;
    /** @brief Pointer to the callback function. */
    Wkpu_Ip_CallbackType        callback;
    /** @brief The notification functions for SIGNAL_EDGE_DETECT mode. */
    Wkpu_Ip_NotifyType     WkpuChannelNotification;
    /** @brief The logic channel for which callback is set. */
    uint16                       callbackParam;
    /** @brief Store the initialization state that determines whether Notifications are enabled. */
    boolean                      notificationEnable;
} Wkpu_Ip_State;

#endif /* WKPU_IP_USED */
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/**@}*/

#endif  /* WKPU_IP_TYPES_H */
