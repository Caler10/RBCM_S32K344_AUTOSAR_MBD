/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
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
*   @file    Lpspi_Ip_Irq.c
*   @implements     Lpspi_Ip_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup LPSPI_IP_DRIVER Lpspi Driver
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
#include "Lpspi_Ip.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_VENDOR_ID_IRQ_C                      43
#define LPSPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define LPSPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define LPSPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define LPSPI_IP_SW_MAJOR_VERSION_IRQ_C               5
#define LPSPI_IP_SW_MINOR_VERSION_IRQ_C               0
#define LPSPI_IP_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lpspi_Ip.h and Lpspi_Ip_Irq.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP_VENDOR_ID_IRQ_C)
    #error "Lpspi_Ip.h and Lpspi_Ip_Irq.c have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip_Irq.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip_Irq.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION_IRQ_C) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION_IRQ_C) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION_IRQ_C))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip_Irq.c are different"
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#ifdef LPSPI_IP_0_ENABLED
    #if (LPSPI_IP_0_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_0_IRQHandler);
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_0_IrqTxDmaHandler(void);
void Lpspi_Ip_LPSPI_0_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef LPSPI_IP_1_ENABLED
    #if (LPSPI_IP_1_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_1_IRQHandler);
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_1_IrqTxDmaHandler(void);
void Lpspi_Ip_LPSPI_1_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef LPSPI_IP_2_ENABLED
    #if (LPSPI_IP_2_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_2_IRQHandler);
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_2_IrqTxDmaHandler(void);
void Lpspi_Ip_LPSPI_2_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef LPSPI_IP_3_ENABLED
    #if (LPSPI_IP_3_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_3_IRQHandler);
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_3_IrqTxDmaHandler(void);
void Lpspi_Ip_LPSPI_3_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef LPSPI_IP_4_ENABLED
    #if (LPSPI_IP_4_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_4_IRQHandler);
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_4_IrqTxDmaHandler(void);
void Lpspi_Ip_LPSPI_4_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef LPSPI_IP_5_ENABLED
    #if (LPSPI_IP_5_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_5_IRQHandler);
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_5_IrqTxDmaHandler(void);
void Lpspi_Ip_LPSPI_5_IrqRxDmaHandler(void);
        #endif
    #endif
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef LPSPI_IP_0_ENABLED
    #if (LPSPI_IP_0_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_0_IRQHandler)
{
    Lpspi_Ip_IrqHandler(0u); /* Call Lpspi_Ip_IrqHandler for instance 0 */
    EXIT_INTERRUPT();
}
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_0_IrqTxDmaHandler(void)
{
    Lpspi_Ip_IrqTxDmaHandler(0u); /* Call Lpspi_Ip_IrqTxDmaHandler for instance 0 */
}
void Lpspi_Ip_LPSPI_0_IrqRxDmaHandler(void)
{
    Lpspi_Ip_IrqRxDmaHandler(0u); /* Call Lpspi_Ip_IrqRxDmaHandler for instance 0 */
}
        #endif
    #endif
#endif
#ifdef LPSPI_IP_1_ENABLED
    #if (LPSPI_IP_1_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_1_IRQHandler)
{
    Lpspi_Ip_IrqHandler(1u); /* Call Lpspi_Ip_IrqHandler for instance 1 */
    EXIT_INTERRUPT();
}
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_1_IrqTxDmaHandler(void)
{
    Lpspi_Ip_IrqTxDmaHandler(1u); /* Call Lpspi_Ip_IrqTxDmaHandler for instance 1 */
}
void Lpspi_Ip_LPSPI_1_IrqRxDmaHandler(void)
{
    Lpspi_Ip_IrqRxDmaHandler(1u); /* Call Lpspi_Ip_IrqRxDmaHandler for instance 1 */
}
        #endif
    #endif
#endif
#ifdef LPSPI_IP_2_ENABLED
    #if (LPSPI_IP_2_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_2_IRQHandler)
{
    Lpspi_Ip_IrqHandler(2u); /* Call Lpspi_Ip_IrqHandler for instance 2 */
    EXIT_INTERRUPT();
}
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_2_IrqTxDmaHandler(void)
{
    Lpspi_Ip_IrqTxDmaHandler(2u); /* Call Lpspi_Ip_IrqTxDmaHandler for instance 2 */
}
void Lpspi_Ip_LPSPI_2_IrqRxDmaHandler(void)
{
    Lpspi_Ip_IrqRxDmaHandler(2u); /* Call Lpspi_Ip_IrqRxDmaHandler for instance 2 */
}
        #endif
    #endif
#endif
#ifdef LPSPI_IP_3_ENABLED
    #if (LPSPI_IP_3_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_3_IRQHandler)
{
    Lpspi_Ip_IrqHandler(3u); /* Call Lpspi_Ip_IrqHandler for instance 3 */
    EXIT_INTERRUPT();
}
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_3_IrqTxDmaHandler(void)
{
    Lpspi_Ip_IrqTxDmaHandler(3u); /* Call Lpspi_Ip_IrqTxDmaHandler for instance 3 */
}
void Lpspi_Ip_LPSPI_3_IrqRxDmaHandler(void)
{
    Lpspi_Ip_IrqRxDmaHandler(3u); /* Call Lpspi_Ip_IrqRxDmaHandler for instance 3 */
}
        #endif
    #endif
#endif
#ifdef LPSPI_IP_4_ENABLED
    #if (LPSPI_IP_4_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_4_IRQHandler)
{
    Lpspi_Ip_IrqHandler(4u); /* Call Lpspi_Ip_IrqHandler for instance 4 */
    EXIT_INTERRUPT();
}
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_4_IrqTxDmaHandler(void)
{
    Lpspi_Ip_IrqTxDmaHandler(4u); /* Call Lpspi_Ip_IrqTxDmaHandler for instance 4 */
}
void Lpspi_Ip_LPSPI_4_IrqRxDmaHandler(void)
{
    Lpspi_Ip_IrqRxDmaHandler(4u); /* Call Lpspi_Ip_IrqRxDmaHandler for instance 4 */
}
        #endif
    #endif
#endif
#ifdef LPSPI_IP_5_ENABLED
    #if (LPSPI_IP_5_ENABLED == STD_ON)
ISR(Lpspi_Ip_LPSPI_5_IRQHandler)
{
    Lpspi_Ip_IrqHandler(5u); /* Call Lpspi_Ip_IrqHandler for instance 5 */
    EXIT_INTERRUPT();
}
        #if (LPSPI_IP_DMA_USED == STD_ON)
void Lpspi_Ip_LPSPI_5_IrqTxDmaHandler(void)
{
    Lpspi_Ip_IrqTxDmaHandler(5u); /* Call Lpspi_Ip_IrqTxDmaHandler for instance 5 */
}
void Lpspi_Ip_LPSPI_5_IrqRxDmaHandler(void)
{
    Lpspi_Ip_IrqRxDmaHandler(5u); /* Call Lpspi_Ip_IrqRxDmaHandler for instance 5 */
}
        #endif
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
