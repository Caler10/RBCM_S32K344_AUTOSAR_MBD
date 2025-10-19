/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef DMA_IP_DRIVER_STATES_H_
#define DMA_IP_DRIVER_STATES_H_

/**
*   @file    Dma_Ip_Driver_State.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver header file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_DRIVER_STATE_VENDOR_ID                       43
#define DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION                5
#define DMA_IP_DRIVER_STATE_SW_MINOR_VERSION                0
#define DMA_IP_DRIVER_STATE_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip.h file are of the same vendor */
#if (DMA_IP_DRIVER_STATE_VENDOR_ID != DMA_IP_VENDOR_ID)
    #error "Dma_Ip_Driver_State.h and Dma_Ip.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip.h file are of the same Autosar version */
#if ((DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION != DMA_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Driver_State.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip.h file are of the same Software version */
#if ((DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION != DMA_IP_SW_MAJOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_SW_MINOR_VERSION != DMA_IP_SW_MINOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_SW_PATCH_VERSION != DMA_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Driver_State.h and Dma_Ip.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/* The enumeration values are linked to the Dma State Machine */
typedef enum{
    DMA_IP_CH_RESET_EVENT         = 0U,
    DMA_IP_CH_READY_EVENT         = 1U,
    DMA_IP_CH_TRANSFER_EVENT      = 2U,
    DMA_IP_CH_SCATTERGATHER_EVENT = 3U,
    DMA_IP_CH_ERROR_EVENT         = 4U,
}Dma_Ip_HwChannelEventValueEnum;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct{
    #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    Dma_Ip_HwChannelStateType * volatile ptHwChV3StateArray[DMA_IP_DMA_NOF_HWV3_INST][DMA_IP_TCD_NOF_HWV3_CH];
    #endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */
}Dma_Ip_HwStateType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

void Dma_Ip_SetHwChannelState(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const Dma_Ip_HwChannelEventValueEnum EventValue);
Dma_Ip_HwChannelStateValueType Dma_Ip_GetHwChannelState(uint32 LocHwVers, uint32 LocHwInst, uint32 LocHwCh);
Dma_Ip_HwChannelStateType * Dma_Ip_GetHwChannelStatePointer(uint32 LocHwVers, uint32 LocHwInst, uint32 LocHwCh);
void Dma_Ip_SetHwChannelStatePointer(uint32 LocHwVers, uint32 LocHwInst, uint32 LocHwCh, Dma_Ip_HwChannelStateType * StatePointer);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #if !defined(DMA_IP_DRIVER_STATES_H_) */

