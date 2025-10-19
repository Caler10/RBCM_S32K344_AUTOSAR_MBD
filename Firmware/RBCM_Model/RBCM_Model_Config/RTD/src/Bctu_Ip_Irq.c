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

/**
*   @file
*
*   @addtogroup bctu_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Bctu_Ip_Irq.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BCTU_IP_VENDOR_ID_IRQ_C                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define BCTU_IP_SW_MAJOR_VERSION_IRQ_C               5
#define BCTU_IP_SW_MINOR_VERSION_IRQ_C               0
#define BCTU_IP_SW_PATCH_VERSION_IRQ_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip_Irq.c file and OsIf.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_Irq.c and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Bctu_Ip_Irq.c file and Bctu_Ip_Irq.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_IRQ_C != BCTU_IP_VENDOR_ID_IRQ)
    #error "Bctu_Ip_Irq.c and Bctu_Ip_Irq.h have different vendor ids"
#endif

/* Check if Bctu_Ip_Irq.c file and Bctu_Ip_Irq.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_IRQ_C != BCTU_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_Irq.c and Bctu_Ip_Irq.h are different"
#endif

/* Check if Bctu_Ip_Irq.c file and Bctu_Ip_Irq.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_IRQ_C != BCTU_IP_SW_MAJOR_VERSION_IRQ) || \
     (BCTU_IP_SW_MINOR_VERSION_IRQ_C != BCTU_IP_SW_MINOR_VERSION_IRQ) || \
     (BCTU_IP_SW_PATCH_VERSION_IRQ_C != BCTU_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Bctu_Ip_Irq.c and Bctu_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

ISR(Bctu_0_Isr)
{
    /* Call IRQ handler for BCTU0 */
    Bctu_Ip_IRQHandler(0UL);
}

#if (BCTU_INSTANCE_COUNT > 1U)
ISR(Bctu_1_Isr)
{
    /* Call IRQ handler for BCTU1 */
    Bctu_Ip_IRQHandler(1UL);
}
#endif

#ifdef BCTU_IP_DMA_SUPPORTED
void Bctu_Ip_Bctu0Fifo1DmaComplete(void)
{
    /*Bctu0 - FIFO1 but the index is 0 */
    Bctu_Ip_FifoDmaHandler(0U, 0U);
}

void Bctu_Ip_Bctu0Fifo2DmaComplete(void)
{
    /*Bctu0 - FIFO2 but the index is 1 */
    Bctu_Ip_FifoDmaHandler(0U, 1U);
}

#if (BCTU_IP_FIFO_COUNT > 2U)
void Bctu_Ip_Bctu0Fifo3DmaComplete(void)
{
    /*Bctu0 - FIFO3 but the index is 2 */
    Bctu_Ip_FifoDmaHandler(0U, 2U);
}
#endif

#if (BCTU_INSTANCE_COUNT > 1U)
void Bctu_Ip_Bctu1Fifo1DmaComplete(void)
{
    /*Bctu1 - FIFO1 but the index is 0 */
    Bctu_Ip_FifoDmaHandler(1U, 0U);
}

void Bctu_Ip_Bctu1Fifo2DmaComplete(void)
{
    /*Bctu1 - FIFO2 but the index is 1 */
    Bctu_Ip_FifoDmaHandler(1U, 1U);
}

#if (BCTU_IP_FIFO_COUNT > 2U)
void Bctu_Ip_Bctu1Fifo3DmaComplete(void)
{
    /*Bctu1 - FIFO3 but the index is 2 */
    Bctu_Ip_FifoDmaHandler(1U, 2U);
}
#endif

#endif

#endif /* BCTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
