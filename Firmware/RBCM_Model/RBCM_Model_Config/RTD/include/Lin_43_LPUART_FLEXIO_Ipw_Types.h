/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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
*/

#ifndef LIN_43_LPUART_FLEXIO_IPW_TYPES_H
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_H

/**
*   @file
*
*   @internal
*   @addtogroup LIN_43_LPUART_FLEXIO_IPW
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Lin_43_LPUART_FLEXIO_Defines.h"
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
#include "EcuM_Externals.h"
#endif
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
#include "Flexio_Lin_Ip_Types.h"
#endif
#include "Lpuart_Lin_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_IPW_TYPES_VENDOR_ID                    43
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MAJOR_VERSION             5
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MINOR_VERSION             0
#define LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#if (LIN_43_LPUART_FLEXIO_IPW_TYPES_VENDOR_ID != LPUART_LIN_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Ipw_Types.h and Lpuart_Lin_Ip_Types.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LPUART_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LPUART_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lpuart_Ipw_Types.h and Lpuart_Lin_Ip_Types.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MAJOR_VERSION != LPUART_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MINOR_VERSION != LPUART_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_PATCH_VERSION != LPUART_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Ipw_Types.h and Lpuart_Lin_Ip_Types.h are different"
#endif

#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    #if (LIN_43_LPUART_FLEXIO_IPW_TYPES_VENDOR_ID != FLEXIO_LIN_IP_TYPES_VENDOR_ID)
        #error "Lpuart_Ipw_Types.h and Flexio_Lin_Ip_Types.h have different vendor ids"
    #endif
    #if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
        (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpuart_Ipw_Types.h and Flexio_Lin_Ip_Types.h are different"
    #endif
    /* Check if current file and Flexio_Lin_Ip_Types header file are of the same Software version */
    #if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
        (LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_LIN_IP_TYPES_SW_MINOR_VERSION) || \
        (LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_LIN_IP_TYPES_SW_PATCH_VERSION) \
        )
        #error "Software Version Numbers of Lpuart_Ipw_Types.h and Flexio_Lin_Ip_Types.h are different"
    #endif
#endif

/* Checks against Lin_43_LPUART_FLEXIO_Defines.h */
#if (LIN_43_LPUART_FLEXIO_IPW_TYPES_VENDOR_ID != LIN_43_LPUART_FLEXIO_DEFINES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_Types.h and Lin_43_LPUART_FLEXIO_Defines.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Types.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Types.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Types.h and EcuM_Externals.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * @internal
 * @brief         Definition of the available types of LIN hardware instances on the current platform.
 * @details       This type enumerates the type of hardware instance used for the current configured channel.
 *
 *
 * */
typedef enum
{
    LIN_43_LPUART_FLEXIO_LPUART_CHANNEL       = 0x0U, /**< @brief This is used for LPUART channels */
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL       = 0x1U, /**< @brief This is used for FLEXIO channels */
#endif
} Lin_43_LPUART_FLEXIO_Ipw_HwChannelType;

/**
 * @brief         Definition of the LIN node type of the current channel.
 * @details       This type enumerates the node types for a LIN channel.
 *
 *
 **/
typedef enum
{
    LIN_43_LPUART_FLEXIO_MASTER_NODE       = 0x0U, /**< @brief This is used for Master node */
    LIN_43_LPUART_FLEXIO_SLAVE_NODE        = 0x1U  /**< @brief This is used for Slave node */
} Lin_43_LPUART_FLEXIO_Ipw_NodeType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @internal
 * @brief        Structure which contains the hardware specific configured information.
 * @details      This structure contains pointers to the hardware specific channel configuration.
 *               Depending on the type of channel available via u8LinIpType parameter in Lin_HwConfigType
 *               only the specific member of this structure will contain a valid pointer. The rest of available
 *               members of structure (if any) will point to invalid address.
 *
 *
 * */
typedef struct
{
    const Lpuart_Lin_Ip_UserConfigType *LpuartConfigPtr; /**< @brief A pointer to a LPUART user configuration structure */
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    const Flexio_Lin_Ip_UserConfigType *FlexioConfigPtr; /**< @brief A pointer to a FLEXIO user configuration structure */
#endif
} Lin_43_LPUART_FLEXIO_Ipw_IpConfigType;

/**
 * @internal
 * @brief        Structure which brings together all the hardware specific information regarding a channel
 * @details      This structure contains:
 *               - u8LinIpType member which indicates the type of hardware instance configured for the current channel.
 *               - pIpConfig member containing a singular valid pointer to a hardware specific user configured structure.
 *               - u8LinHwChannel which specifies the number of hardware instance configured for the current channel.
 *
 *
 * */
typedef struct
{
    const uint8 LinHwChannel;                           /**< @brief The number of hardware instance configured */
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
    boolean LinChannelWakeupSupport;                    /**!< @brief Is wake-up supported by the LIN channel ?.*/
    EcuM_WakeupSourceType LinChannelEcuMWakeupSource;   /**!< @brief [SWS_Lin_00098] This parameter contains a reference to
                                                              the Wakeup Source for this controller as defined in the
                                                              ECU State Manager.*/
#endif
    const Lin_43_LPUART_FLEXIO_Ipw_NodeType LinNodeType;                 /**!< @brief LIN Node Type.*/
    Lin_43_LPUART_FLEXIO_Ipw_HwChannelType LinIpType;                    /**< @brief Type of hardware instance configured for the current channel */
    Lin_43_LPUART_FLEXIO_Ipw_IpConfigType IpConfig;                      /**< @brief A structure contains pointer to a hardware specific user configured structure */
#if (LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON)
    uint32 BaudrateRegValueAlternate;                 /**!< @brief Baudrate configuration value for alternate clock */
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    uint8 TimerClkSrcAlternate;                            /**< @brief Timer clock source */
#endif
#endif /* LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON */
} Lin_43_LPUART_FLEXIO_HwConfigType;

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

#endif /* LIN_IPW_TYPES_H */
