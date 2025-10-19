/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

#ifndef BCTU_IP_IRQ_H
#define BCTU_IP_IRQ_H

/**
*   @file
*
*   @addtogroup bctu_ip
*   @{
*/
#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Bctu_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BCTU_IP_VENDOR_ID_IRQ                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define BCTU_IP_SW_MAJOR_VERSION_IRQ               5
#define BCTU_IP_SW_MINOR_VERSION_IRQ               0
#define BCTU_IP_SW_PATCH_VERSION_IRQ               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip_Irq.h file and StandardTypes.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_Irq.h and StandardTypes.h are different"
#endif
#endif

/* Check if Bctu_Ip_Irq.h file and Bctu_Ip_CfgDefines.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_IRQ != BCTU_IP_VENDOR_ID_CFGDEFINES)
    #error "Bctu_Ip_Irq.h and Bctu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Bctu_Ip_Irq.h file and Bctu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ != BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ != BCTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_IRQ != BCTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_Irq.h and Bctu_Ip_CfgDefines.h are different"
#endif

/* Check if Bctu_Ip_Irq.h file and Bctu_Ip_CfgDefines.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_IRQ != BCTU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_SW_MINOR_VERSION_IRQ != BCTU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_SW_PATCH_VERSION_IRQ != BCTU_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Bctu_Ip_Irq.h and Bctu_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/* ISR prototype required by IAR compiler */
/* This function represents the BCTU Interrupt of the driver to let the
 * application register them in the IVT (interrupt vector table). */
ISR(Bctu_0_Isr);

#if (BCTU_INSTANCE_COUNT > 1U)
ISR(Bctu_1_Isr);
#endif

#ifdef BCTU_IP_DMA_SUPPORTED
/* 
 * The following functions handle internal CTU updates after a DMA transfer is completed in Control Mode.
 * They are notifications to be called by DMA IPL, each corresponding to the completion of data transfer
 * from an internal FIFO, triggered by threshold from that FIFO being exceeded.
 */
void Bctu_Ip_Bctu0Fifo1DmaComplete(void);
void Bctu_Ip_Bctu0Fifo2DmaComplete(void);
#if (BCTU_IP_FIFO_COUNT > 2U)
void Bctu_Ip_Bctu0Fifo3DmaComplete(void);
#endif

#if (BCTU_INSTANCE_COUNT > 1U)
void Bctu_Ip_Bctu1Fifo1DmaComplete(void);
void Bctu_Ip_Bctu1Fifo2DmaComplete(void);
#if (BCTU_IP_FIFO_COUNT > 2U)
void Bctu_Ip_Bctu1Fifo3DmaComplete(void);
#endif
#endif

#endif /* BCTU_IP_DMA_SUPPORTED */

void Bctu_Ip_IRQHandler(const uint32 Instance);
#ifdef BCTU_IP_DMA_SUPPORTED
void Bctu_Ip_FifoDmaHandler(const uint32 Instance,
                            const uint8 FifoIndex);
#endif /* BCTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* BCTU_IP_IRQ_H */
