/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
#ifndef DMA_MUX_IP_TYPES_H
#define DMA_MUX_IP_TYPES_H

/**
*   @file Dma_Mux_Ip_Types.h
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "BasicTypes.h"
#include "Dma_Mux_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_TYPES_VENDOR_ID                      43
#define RM_DMA_MUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define RM_DMA_MUX_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define RM_DMA_MUX_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define RM_DMA_MUX_IP_TYPES_SW_MAJOR_VERSION               5
#define RM_DMA_MUX_IP_TYPES_SW_MINOR_VERSION               0
#define RM_DMA_MUX_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/* Checks against Dma_Mux_Ip_Cfg_Defines.h */
#if (RM_DMA_MUX_IP_TYPES_VENDOR_ID != RM_DMA_MUX_IP_CFG_DEFINES_VENDOR_ID)
    #error "Dma_Mux_Ip_Types.h and Dma_Mux_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( RM_DMA_MUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip_Types.h and Dma_Mux_Ip_Cfg_Defines.h are different"
#endif
#if (( RM_DMA_MUX_IP_TYPES_SW_MAJOR_VERSION != RM_DMA_MUX_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_TYPES_SW_MINOR_VERSION != RM_DMA_MUX_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_TYPES_SW_PATCH_VERSION != RM_DMA_MUX_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip_Types.h and Dma_Mux_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief          Configuration structure containing the channel configuration
*/

typedef struct
{
    uint8 Instance;                    /*!< Select the instance request source. */
    uint8 Channel;                     /*!< Select the channel request source. */
    uint8 ConfigValue;                 /*!< Configuration value for the channel. */
} Dma_Mux_Ip_ChannelConfigType;

/**
* @brief          IP configuration structure
*/
typedef struct
{
    uint8 ChannelConfigCnt;                                         /*!< Channel Count */
    const Dma_Mux_Ip_ChannelConfigType *pChannelConfigArr;          /*!< Channel configuration array */
} Dma_Mux_Ip_ConfigType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_MUX_IP_TYPES_H */
