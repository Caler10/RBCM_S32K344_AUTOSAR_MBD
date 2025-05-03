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

#ifndef DMA_IP_CFG_H_
#define DMA_IP_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Types.h"
#include "Dma_Ip_MBDT_PBcfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_VENDOR_ID                       43
#define DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_SW_MAJOR_VERSION                5
#define DMA_IP_CFG_SW_MINOR_VERSION                0
#define DMA_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Types.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_TYPES_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Types.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_Types.h are different"
#endif

/* Check if header file and Dma_Ip_Types.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_TYPES_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_TYPES_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_Types.h are different"
#endif

/* Check if header file and Dma_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_MBDT_PBCFG_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if header file and Dma_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_MBDT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_MBDT_PBcfg.h are different"
#endif
    
/*******************************************************************************
 * Definitions
 ******************************************************************************/


#define MCL_ENABLE_USER_MODE_SUPPORT    STD_OFF

#if (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT)
#define MCL_DMA_REG_PROT_AVAILABLE
#endif

/* Number Of Configured Logic Instances */
#define DMA_IP_NOF_CFG_LOGIC_INSTANCES   ((uint32)1U)

/* Logic Instance 0 */
#define DMA_LOGIC_INST_0   ((uint32)0U)

/* Number Of Configured Logic Channels */
#define DMA_IP_NOF_CFG_LOGIC_CHANNELS   ((uint32)3U)

/* Logic Channel 0 */
#define DMA_LOGIC_CH_16_TX   ((uint8)0U)

/* Logic Channel 1 */
#define DMA_LOGIC_CH_17_RX   ((uint8)1U)

/* Logic Channel 2 */
#define DMA_LOGIC_CH_0_TRANSFER   ((uint8)2U)

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
extern const Dma_Ip_InitType Dma_Ip_xDmaInitPB_MBDT;

extern const Dma_Ip_LogicChannelConfigType Dma_Ip_xLogicChannelResetConfig;

extern const Dma_Ip_LogicInstanceConfigType Dma_Ip_xLogicInstanceResetConfig;

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
/* DMA IRQ Handlers */
ISR(Dma0_Ch0_IRQHandler);
ISR(Dma0_Ch1_IRQHandler);
ISR(Dma0_Ch2_IRQHandler);
ISR(Dma0_Ch3_IRQHandler);
ISR(Dma0_Ch4_IRQHandler);
ISR(Dma0_Ch5_IRQHandler);
ISR(Dma0_Ch6_IRQHandler);
ISR(Dma0_Ch7_IRQHandler);
ISR(Dma0_Ch8_IRQHandler);
ISR(Dma0_Ch9_IRQHandler);
ISR(Dma0_Ch10_IRQHandler);
ISR(Dma0_Ch11_IRQHandler);
ISR(Dma0_Ch12_IRQHandler);
ISR(Dma0_Ch13_IRQHandler);
ISR(Dma0_Ch14_IRQHandler);
ISR(Dma0_Ch15_IRQHandler);
ISR(Dma0_Ch16_IRQHandler);
ISR(Dma0_Ch17_IRQHandler);
ISR(Dma0_Ch18_IRQHandler);
ISR(Dma0_Ch19_IRQHandler);
ISR(Dma0_Ch20_IRQHandler);
ISR(Dma0_Ch21_IRQHandler);
ISR(Dma0_Ch22_IRQHandler);
ISR(Dma0_Ch23_IRQHandler);
ISR(Dma0_Ch24_IRQHandler);
ISR(Dma0_Ch25_IRQHandler);
ISR(Dma0_Ch26_IRQHandler);
ISR(Dma0_Ch27_IRQHandler);
ISR(Dma0_Ch28_IRQHandler);
ISR(Dma0_Ch29_IRQHandler);
ISR(Dma0_Ch30_IRQHandler);
ISR(Dma0_Ch31_IRQHandler);
#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DMA_IP_CFG_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

