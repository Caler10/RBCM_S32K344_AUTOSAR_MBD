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

/**
*   @file Dma_Mux_Ip_MBDT_PBcfg.c
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Mux_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_MBDT_PBCFG_VENDOR_ID_C                     43
#define RM_DMA_MUX_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_DMA_MUX_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_DMA_MUX_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_DMA_MUX_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C              5
#define RM_DMA_MUX_IP_MBDT_PBCFG_SW_MINOR_VERSION_C              0
#define RM_DMA_MUX_IP_MBDT_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Dma_Mux_Ip.h */
#if (RM_DMA_MUX_IP_MBDT_PBCFG_VENDOR_ID_C != RM_DMA_MUX_IP_VENDOR_ID)
    #error "Dma_Mux_Ip_MBDT_PBcfg.c and Dma_Mux_Ip.h have different vendor ids"
#endif
#if ((RM_DMA_MUX_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_DMA_MUX_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_DMA_MUX_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip_MBDT_PBcfg.c and Dma_Mux_Ip.h are different"
#endif
#if ((RM_DMA_MUX_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C != RM_DMA_MUX_IP_SW_MAJOR_VERSION) || \
     (RM_DMA_MUX_IP_MBDT_PBCFG_SW_MINOR_VERSION_C != RM_DMA_MUX_IP_SW_MINOR_VERSION) || \
     (RM_DMA_MUX_IP_MBDT_PBCFG_SW_PATCH_VERSION_C != RM_DMA_MUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip_MBDT_PBcfg.c and Dma_Mux_Ip.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#define DMAMUX_CHANNEL_CFG_ENBL_MASK        DMAMUX_CHCFG_ENBL_MASK
#define DMAMUX_CHANNEL_CFG_TRIG             DMAMUX_CHCFG_TRIG
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

static const Dma_Mux_Ip_ChannelConfigType Dma_Mux_Channel_Config_MBDT[2] =
{
    {
        DMA_MUX_INSTANCE_1,
        0U,
        (DMA_MUX_1_LPUART_3_TRANSMIT | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG(0U))
    },
    {
        DMA_MUX_INSTANCE_1,
        1U,
        (DMA_MUX_1_LPUART_3_RECEIVE | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG(0U))
    }
};
const Dma_Mux_Ip_ConfigType Dma_Mux_Config_MBDT =
{
    2U,
    Dma_Mux_Channel_Config_MBDT
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

