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
==================================================================================================*/

#ifndef LIN_43_LPUART_FLEXIO_TYPES_H
#define LIN_43_LPUART_FLEXIO_TYPES_H 

/**
*   @file    Lin_Types.h
*   @implements Lin_Types.h_Artifact
*
*   @defgroup lin_driver LIN Driver
*   @addtogroup  lin_driver LIN Driver
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
#include "Lin_43_LPUART_FLEXIO_Ipw_Types.h"
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
#include "EcuM_Externals.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID                    43
#define LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION             5
#define LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION             0
#define LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_43_LPUART_FLEXIO_Defines.h */
#if (LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID != LIN_43_LPUART_FLEXIO_DEFINES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Types.h and Lin_43_LPUART_FLEXIO_Defines.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Defines header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Types.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Defines.h header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Types.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
/* Checks against Lin_43_LPUART_FLEXIO_Ipw_Types.h */
#if (LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID != LIN_43_LPUART_FLEXIO_IPW_TYPES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Types.h and Lin_43_LPUART_FLEXIO_Ipw_Types.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Types.h and Lin_43_LPUART_FLEXIO_Ipw_Types.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Ipw_Types.h header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Types.h and Lin_43_LPUART_FLEXIO_Ipw_Types.h are different"
#endif
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Types.h and EcuM_Externals.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Return code for timeout error.
*/
#define LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR    0x02

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          LIN channel configuration type structure.
* @details        This is the type of the external data structure containing
*                 the overall initialization data for one LIN Channel.
*                 A pointer to such a structure is provided to the LIN channel
*                 initialization routine for configuration of the LIN hardware
*                 channel.
*
*
*/
typedef struct
{
    uint8 LinChannelID;                                     /**!< @brief Lin Channel ID */
    const Lin_43_LPUART_FLEXIO_HwConfigType *ChannelConfigPtr;               /**!< @brief LIN Hardware configuration pointer.*/
    uint32 ChannelPartitionID;                                   /**!< @brief LIN Channel Partition ID.*/
    boolean AllocatedPartition;                             /**!< @brief LIN Channel is allocated partition or not.*/
} Lin_43_LPUART_FLEXIO_ChannelConfigType;

/**
* @brief          LIN driver configuration type structure.
* @details        This is the type of the pointer to the external data
*                 LIN Channels.
*                 A pointer of such a structure is provided to the LIN driver
*                 initialization routine for configuration of the LIN hardware
*                 channel.
*
* 
*
* @implements Lin_ConfigType_struct
*/
typedef struct
{
    uint32 PartitionId;              /**!< @brief Partition id is assigned for this configuration */
    /**
     * @brief     Hardware channel.
     * @details   Constant pointer of the constant external data
     *            structure containing the overall initialization data
     *            for all the configured LIN Channels.
     */
    const Lin_43_LPUART_FLEXIO_ChannelConfigType *Lin_43_LPUART_FLEXIO_ChannelPtr[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES]; /**!< @brief Constant pointer to an array containing
                                                                         the configurations for the available LIN channels */
} Lin_43_LPUART_FLEXIO_ConfigType;

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

#endif /*LIN_43_LPUART_FLEXIO_TYPES_H*/
