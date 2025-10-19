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

/**
*   @file    Dma_Ip_Driver_State.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver source file.
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
#include "Dma_Ip_Driver_State.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_DRIVER_STATE_VENDOR_ID_C                       43
#define DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION_C        4
#define DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION_C        7
#define DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION_C     0
#define DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION_C                5
#define DMA_IP_DRIVER_STATE_SW_MINOR_VERSION_C                0
#define DMA_IP_DRIVER_STATE_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_Driver_State.c file and Dma_Ip_Driver_State.h file are of the same vendor */
#if (DMA_IP_DRIVER_STATE_VENDOR_ID_C != DMA_IP_DRIVER_STATE_VENDOR_ID)
    #error "Dma_Ip_Driver_State.c and Dma_Ip_Driver_State.h have different vendor ids"
#endif

/* Check if Dma_Ip_Driver_State.c file and Dma_Ip_Driver_State.h file are of the same Autosar version */
#if ((DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Driver_State.c and Dma_Ip_Driver_State.h are different"
#endif

/* Check if Dma_Ip_Driver_State.c file and Dma_Ip_Driver_State.h file are of the same Software version */
#if ((DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION_C != DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_SW_MINOR_VERSION_C != DMA_IP_DRIVER_STATE_SW_MINOR_VERSION) || \
     (DMA_IP_DRIVER_STATE_SW_PATCH_VERSION_C != DMA_IP_DRIVER_STATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Driver_State.c and Dma_Ip_Driver_State.h are different"
#endif


#if (STD_ON == DMA_IP_IS_AVAILABLE)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

static Dma_Ip_HwStateType Dma_Ip_xHwState;

#define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

static void Dma_Ip_SetHwChannel_ResetEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void Dma_Ip_SetHwChannel_ReadyEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void Dma_Ip_SetHwChannel_TransferEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void Dma_Ip_SetHwChannel_ScatterGatherEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void Dma_Ip_SetHwChannel_ErrorEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

static void Dma_Ip_SetHwChannel_ResetEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue = DMA_IP_CH_RESET_STATE;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

static void Dma_Ip_SetHwChannel_ReadyEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue = DMA_IP_CH_READY_STATE;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

static void Dma_Ip_SetHwChannel_TransferEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue = DMA_IP_CH_TRANSFER_STATE;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

static void Dma_Ip_SetHwChannel_ScatterGatherEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue = DMA_IP_CH_SCATTERGATHER_STATE;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

static void Dma_Ip_SetHwChannel_ErrorEvent(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue = DMA_IP_CH_ERROR_STATE;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

void Dma_Ip_SetHwChannelState(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const Dma_Ip_HwChannelEventValueEnum EventValue)
{
    static void (* const fpa_Dma_Ip_HwChannelState[5U][5U])(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh) =
    {
        {&Dma_Ip_SetHwChannel_ResetEvent, &Dma_Ip_SetHwChannel_ReadyEvent, &Dma_Ip_SetHwChannel_ErrorEvent, &Dma_Ip_SetHwChannel_ErrorEvent, &Dma_Ip_SetHwChannel_ErrorEvent},
        {&Dma_Ip_SetHwChannel_ResetEvent, &Dma_Ip_SetHwChannel_ReadyEvent, &Dma_Ip_SetHwChannel_TransferEvent, &Dma_Ip_SetHwChannel_ScatterGatherEvent, &Dma_Ip_SetHwChannel_ErrorEvent},
        {&Dma_Ip_SetHwChannel_ResetEvent, &Dma_Ip_SetHwChannel_ReadyEvent, &Dma_Ip_SetHwChannel_TransferEvent, &Dma_Ip_SetHwChannel_ScatterGatherEvent, &Dma_Ip_SetHwChannel_ErrorEvent},
        {&Dma_Ip_SetHwChannel_ResetEvent, &Dma_Ip_SetHwChannel_ReadyEvent, &Dma_Ip_SetHwChannel_TransferEvent, &Dma_Ip_SetHwChannel_ScatterGatherEvent, &Dma_Ip_SetHwChannel_ErrorEvent},
        {&Dma_Ip_SetHwChannel_ResetEvent, &Dma_Ip_SetHwChannel_ReadyEvent, &Dma_Ip_SetHwChannel_ErrorEvent, &Dma_Ip_SetHwChannel_ErrorEvent, &Dma_Ip_SetHwChannel_ErrorEvent},
    };

    Dma_Ip_HwChannelStateValueType StateValue = DMA_IP_CH_RESET_STATE;

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        StateValue = Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue;
        fpa_Dma_Ip_HwChannelState[StateValue][EventValue](LocHwVers, LocHwInst, LocHwCh);
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
Dma_Ip_HwChannelStateValueType Dma_Ip_GetHwChannelState(uint32 LocHwVers, uint32 LocHwInst, uint32 LocHwCh)
{
    Dma_Ip_HwChannelStateValueType StateValue = DMA_IP_CH_RESET_STATE;

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        StateValue = Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh]->StateValue;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */


    return StateValue;
}

Dma_Ip_HwChannelStateType * Dma_Ip_GetHwChannelStatePointer(uint32 LocHwVers, uint32 LocHwInst, uint32 LocHwCh)
{
    Dma_Ip_HwChannelStateType * PtStatePtr = NULL_PTR;

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        PtStatePtr = Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh];
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */


    return PtStatePtr;
}

void Dma_Ip_SetHwChannelStatePointer(uint32 LocHwVers, uint32 LocHwInst, uint32 LocHwCh, Dma_Ip_HwChannelStateType * StatePointer)
{
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        Dma_Ip_xHwState.ptHwChV3StateArray[LocHwInst][LocHwCh] = StatePointer;
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

