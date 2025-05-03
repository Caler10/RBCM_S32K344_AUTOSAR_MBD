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
*   @file    Dma_Ip_Irq.c
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
#include "Dma_Ip_Cfg.h"
#include "Dma_Ip_Irq.h"
#include "Dma_Ip_Hw_Access.h"
#include "Dma_Ip_Driver_State.h"

#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
#include "Dma_Ip_Multicore.h"
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_IRQ_VENDOR_ID_C                       43
#define DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define DMA_IP_IRQ_SW_MAJOR_VERSION_C                5
#define DMA_IP_IRQ_SW_MINOR_VERSION_C                0
#define DMA_IP_IRQ_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_Irq.c file and Dma_Ip_Cfg.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_CFG_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Cfg.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Cfg.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Cfg.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_CFG_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_CFG_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Cfg.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Irq.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_IRQ_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Irq.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Irq.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Irq.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Irq.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_IRQ_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_IRQ_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Irq.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Hw_Access.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_HW_ACCESS_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Hw_Access.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Hw_Access.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Hw_Access.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Hw_Access.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Driver_State.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_DRIVER_STATE_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Driver_State.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Driver_State.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Driver_State.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Driver_State.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_DRIVER_STATE_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_DRIVER_STATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Driver_State.h are different"
#endif

#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
/* Check if Dma_Ip_Irq.c file and Dma_Ip_Multicore.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_MULTICORE_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Multicore.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Multicore.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Multicore.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Multicore.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_MULTICORE_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_MULTICORE_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_MULTICORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Multicore.h are different"
#endif
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

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

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE

#include "Mcl_MemMap.h"

#if (STD_ON == DMA_IP_IRQ_DISPATCHER_IS_AVAILABLE) 
 /**
 * @brief This function Dma Irq Dispatcher
 * @details This function that shall Handle DMA interrupt.
 *
 * @param[in]  LocHwVers           Specifies the Logic Hw Version defined by the user.
 * @param[in]  LocHwInst           Specifies the Logic Hw Instance defined by the user.
 * @param[in]  HwChSet             Specifies the Hw Set. Represents the channel number of the first hardware channel in the current set.
 * @return void
 *
 *
 * */
static void Dma_IrqDispatcher(const uint32 LocHwVers, const uint32 LocHwInst, const uint8 HwChSet)
{

    uint32 ChIntStatus = 0U;
    uint32 ChErrStatus = 0U;
    uint32 ChIntEnable = 0U;
    uint32 ChErrEnable = 0U;
#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
    Dma_Ip_ReturnType MulticoreStatus = DMA_IP_STATUS_ERROR;
    Dma_Ip_HwChannelStateType * HwChannelStatePtr = NULL_PTR;
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

    uint8 LocHwCh = 0U; /* Specifies the Logic Hw channel */

    for (LocHwCh = HwChSet; LocHwCh < HwChSet + 2U; LocHwCh++)
    {
        ChIntStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT & DMA_IP_TCD_CH_INT_INT_MASK);
        ChErrStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_ES & DMA_IP_TCD_CH_ES_ERR_MASK);
        ChIntEnable = (uint32)(DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_CSR & ((uint32)DMA_IP_TCD_CSR_INTMAJOR_MASK | (uint32)DMA_IP_TCD_CSR_INTHALF_MASK));
        ChErrEnable = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_CSR & DMA_IP_TCD_CH_CSR_EEI_MASK);

    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
        HwChannelStatePtr = Dma_Ip_GetHwChannelStatePointer(LocHwVers, LocHwInst, LocHwCh);
        MulticoreStatus = Dma_Ip_ValidateMultiCoreChannelCall(HwChannelStatePtr->LogicChId->LogicChId);
        if (DMA_IP_STATUS_SUCCESS == MulticoreStatus)
        {
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
            if (0U != ChErrStatus)
            {
                if (0U != ChErrEnable)
                {
                    Dma_Ip_ErrorIrqHandler(LocHwVers, LocHwInst, LocHwCh);
                    /* The event status flag is cleared after execution of the irq handler sue to requirement exception. */
                    DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_ES = DMA_IP_TCD_CH_ES_ERR_MASK;
                }
            }
            if (0U != ChIntStatus)
            {
                if (0U != ChIntEnable)
                {
                    DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT = DMA_IP_TCD_CH_INT_INT_MASK;
                    Dma_Ip_IntIrqHandler(LocHwVers, LocHwInst, LocHwCh);
                }
            }
    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
        }
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
    }
}

/* DMA 0*/
ISR(Dma0_Ch0_Ch1_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 0U);
}
ISR(Dma0_Ch2_Ch3_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 2U);
}
ISR(Dma0_Ch4_Ch5_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 4U);
}
ISR(Dma0_Ch6_Ch7_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 6U);
}
ISR(Dma0_Ch8_Ch9_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 8U);
}
ISR(Dma0_Ch10_Ch11_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 10U);
}
ISR(Dma0_Ch12_Ch13_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 12U);
}
ISR(Dma0_Ch14_Ch15_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 14U);
}
ISR(Dma0_Ch16_Ch17_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 16U);
}
ISR(Dma0_Ch18_Ch19_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 18U);
}
ISR(Dma0_Ch20_Ch21_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 20U);
}
ISR(Dma0_Ch22_Ch23_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 22U);
}
ISR(Dma0_Ch24_Ch25_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 24U);
}
ISR(Dma0_Ch26_Ch27_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 26U);
}
ISR(Dma0_Ch28_Ch29_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 28U);
}
ISR(Dma0_Ch30_Ch31_IrqHandler)
{
    Dma_IrqDispatcher(3U, 0U, 30U);
}
/* Dma 1 */
ISR(Dma1_Ch0_Ch1_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 0U);
}
ISR(Dma1_Ch2_Ch3_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 2U);
}
ISR(Dma1_Ch4_Ch5_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 4U);
}
ISR(Dma1_Ch6_Ch7_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 6U);
}
ISR(Dma1_Ch8_Ch9_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 8U);
}
ISR(Dma1_Ch10_Ch11_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 10U);
}
ISR(Dma1_Ch12_Ch13_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 12U);
}
ISR(Dma1_Ch14_Ch15_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 14U);
}
ISR(Dma1_Ch16_Ch17_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 16U);
}
ISR(Dma1_Ch18_Ch19_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 18U);
}
ISR(Dma1_Ch20_Ch21_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 20U);
}
ISR(Dma1_Ch22_Ch23_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 22U);
}
ISR(Dma1_Ch24_Ch25_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 24U);
}
ISR(Dma1_Ch26_Ch27_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 26U);
}
ISR(Dma1_Ch28_Ch29_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 28U);
}
ISR(Dma1_Ch30_Ch31_IrqHandler)
{
    Dma_IrqDispatcher(3U, 1U, 30U);
}
#else
 /**
 * @brief This function Dma Irq 
 * @details This function that shall Handle DMA interrupt.
 *
 * @param[in]  LocHwVers           Specifies the Logic Hw Version defined by the user.
 * @param[in]  LocHwInst           Specifies the Logic Hw Instance defined by the user.
 * @param[in]  LocHwCh             Specifies the Logic Hw channel defined by the user.
 *
 * @return void
 *
 * @implements Dma_IrqDispatcher_Activity
 * */
static void IrqHandler(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    uint32 ChIntStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT & DMA_IP_TCD_CH_INT_INT_MASK);
    uint32 ChErrStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_ES & DMA_IP_TCD_CH_ES_ERR_MASK);
    uint32 ChIntEnable = (uint32)(DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_CSR & ((uint32)DMA_IP_TCD_CSR_INTMAJOR_MASK | (uint32)DMA_IP_TCD_CSR_INTHALF_MASK));
    uint32 ChErrEnable = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_CSR & DMA_IP_TCD_CH_CSR_EEI_MASK);

    if (0U != ChErrStatus)
    {
        if (0U != ChErrEnable)
        {
            Dma_Ip_ErrorIrqHandler(LocHwVers, LocHwInst, LocHwCh);
            /* The event status flag is cleared after execution of the irq handler sue to requirement exception. */
            DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_ES = DMA_IP_TCD_CH_ES_ERR_MASK;
        }
    }
    if (0U != ChIntStatus)
    {
        if (0U != ChIntEnable)
        {
            DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT = DMA_IP_TCD_CH_INT_INT_MASK;
            Dma_Ip_IntIrqHandler(LocHwVers, LocHwInst, LocHwCh);
        }
    }
}

ISR(Dma0_Ch0_IRQHandler)
{
    /* Dma 0 Channel 0 IRQHandler */
    IrqHandler(3U, 0U, 0U);
}
ISR(Dma0_Ch1_IRQHandler)
{
    /* Dma 0 Channel 1 IRQHandler */
    IrqHandler(3U, 0U, 1U);
}
ISR(Dma0_Ch2_IRQHandler)
{
    /* Dma 0 Channel 2 IRQHandler */
    IrqHandler(3U, 0U, 2U);
}
ISR(Dma0_Ch3_IRQHandler)
{
    /* Dma 0 Channel 3 IRQHandler */
    IrqHandler(3U, 0U, 3U);
}
ISR(Dma0_Ch4_IRQHandler)
{
    /* Dma 0 Channel 4 IRQHandler */
    IrqHandler(3U, 0U, 4U);
}
ISR(Dma0_Ch5_IRQHandler)
{
    /* Dma 0 Channel 5 IRQHandler */
    IrqHandler(3U, 0U, 5U);
}
ISR(Dma0_Ch6_IRQHandler)
{
    /* Dma 0 Channel 6 IRQHandler */
    IrqHandler(3U, 0U, 6U);
}
ISR(Dma0_Ch7_IRQHandler)
{
    /* Dma 0 Channel 7 IRQHandler */
    IrqHandler(3U, 0U, 7U);
}
ISR(Dma0_Ch8_IRQHandler)
{
    /* Dma 0 Channel 8 IRQHandler */
    IrqHandler(3U, 0U, 8U);
}
ISR(Dma0_Ch9_IRQHandler)
{
    /* Dma 0 Channel 9 IRQHandler */
    IrqHandler(3U, 0U, 9U);
}
ISR(Dma0_Ch10_IRQHandler)
{
    /* Dma 0 Channel 10 IRQHandler */
    IrqHandler(3U, 0U, 10U);
}
ISR(Dma0_Ch11_IRQHandler)
{
    /* Dma 0 Channel 11 IRQHandler */
    IrqHandler(3U, 0U, 11U);
}
ISR(Dma0_Ch12_IRQHandler)
{
    /* Dma 0 Channel 12 IRQHandler */
    IrqHandler(3U, 0U, 12U);
}
ISR(Dma0_Ch13_IRQHandler)
{
    /* Dma 0 Channel 13 IRQHandler */
    IrqHandler(3U, 0U, 13U);
}
ISR(Dma0_Ch14_IRQHandler)
{
    /* Dma 0 Channel 14 IRQHandler */
    IrqHandler(3U, 0U, 14U);
}
ISR(Dma0_Ch15_IRQHandler)
{
    /* Dma 0 Channel 15 IRQHandler */
    IrqHandler(3U, 0U, 15U);
}
ISR(Dma0_Ch16_IRQHandler)
{
    /* Dma 0 Channel 16 IRQHandler */
    IrqHandler(3U, 0U, 16U);
}
ISR(Dma0_Ch17_IRQHandler)
{
    /* Dma 0 Channel 17 IRQHandler */
    IrqHandler(3U, 0U, 17U);
}
ISR(Dma0_Ch18_IRQHandler)
{
    /* Dma 0 Channel 18 IRQHandler */
    IrqHandler(3U, 0U, 18U);
}
ISR(Dma0_Ch19_IRQHandler)
{
    /* Dma 0 Channel 19 IRQHandler */
    IrqHandler(3U, 0U, 19U);
}
ISR(Dma0_Ch20_IRQHandler)
{
    /* Dma 0 Channel 20 IRQHandler */
    IrqHandler(3U, 0U, 20U);
}
ISR(Dma0_Ch21_IRQHandler)
{
    /* Dma 0 Channel 21 IRQHandler */
    IrqHandler(3U, 0U, 21U);
}
ISR(Dma0_Ch22_IRQHandler)
{
    /* Dma 0 Channel 22 IRQHandler */
    IrqHandler(3U, 0U, 22U);
}
ISR(Dma0_Ch23_IRQHandler)
{
    /* Dma 0 Channel 23 IRQHandler */
    IrqHandler(3U, 0U, 23U);
}
ISR(Dma0_Ch24_IRQHandler)
{
    /* Dma 0 Channel 24 IRQHandler */
    IrqHandler(3U, 0U, 24U);
}
ISR(Dma0_Ch25_IRQHandler)
{
    /* Dma 0 Channel 25 IRQHandler */
    IrqHandler(3U, 0U, 25U);
}
ISR(Dma0_Ch26_IRQHandler)
{
    /* Dma 0 Channel 26 IRQHandler */
    IrqHandler(3U, 0U, 26U);
}
ISR(Dma0_Ch27_IRQHandler)
{
    /* Dma 0 Channel 27 IRQHandler */
    IrqHandler(3U, 0U, 27U);
}
ISR(Dma0_Ch28_IRQHandler)
{
    /* Dma 0 Channel 28 IRQHandler */
    IrqHandler(3U, 0U, 28U);
}
ISR(Dma0_Ch29_IRQHandler)
{
    /* Dma 0 Channel 29 IRQHandler */
    IrqHandler(3U, 0U, 29U);
}
ISR(Dma0_Ch30_IRQHandler)
{
    /* Dma 0 Channel 30 IRQHandler */
    IrqHandler(3U, 0U, 30U);
}
ISR(Dma0_Ch31_IRQHandler)
{
    /* Dma 0 Channel 31 IRQHandler */
    IrqHandler(3U, 0U, 31U);
}
#endif /* STD_ON == DMA_IP_IRQ_DISPATCHER_IS_AVAILABLE */

#define MCL_STOP_SEC_CODE

#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
