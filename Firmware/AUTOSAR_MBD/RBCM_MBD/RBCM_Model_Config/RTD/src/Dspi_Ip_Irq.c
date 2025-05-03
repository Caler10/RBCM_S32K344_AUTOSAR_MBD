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
*   @file    Dspi_Ip_Irq.c
*   @implements     Dspi_Ip_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup DSPI_IP_DRIVER Dspi Ip Driver
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
#include "Dspi_Ip.h"

#if (STD_ON == DSPI_IP_ENABLE)
/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_IP_VENDOR_ID_IRQ_C                      43
#define DSPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define DSPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define DSPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define DSPI_IP_SW_MAJOR_VERSION_IRQ_C               5
#define DSPI_IP_SW_MINOR_VERSION_IRQ_C               0
#define DSPI_IP_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dspi_Ip.h and Dspi_Ip_Irq.c are of the same vendor */
#if (DSPI_IP_VENDOR_ID != DSPI_IP_VENDOR_ID_IRQ_C)
    #error "Dspi_Ip.h and Dspi_Ip_Irq.c have different vendor ids"
#endif
/* Check if Dspi_Ip.h file and Dspi_Ip_Irq.c file are of the same Autosar version */
#if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION != DSPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C) || \
     (DSPI_IP_AR_RELEASE_MINOR_VERSION != DSPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C) || \
     (DSPI_IP_AR_RELEASE_REVISION_VERSION != DSPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C))
#error "AutoSar Version Numbers of Dspi_Ip.h and Dspi_Ip_Irq.c are different"
#endif
#if ((DSPI_IP_SW_MAJOR_VERSION != DSPI_IP_SW_MAJOR_VERSION_IRQ_C) || \
     (DSPI_IP_SW_MINOR_VERSION != DSPI_IP_SW_MINOR_VERSION_IRQ_C) || \
     (DSPI_IP_SW_PATCH_VERSION != DSPI_IP_SW_PATCH_VERSION_IRQ_C))
#error "Software Version Numbers of Dspi_Ip.h and Dspi_Ip_Irq.c are different"
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

#ifdef DSPI_IP_0_ENABLED
    #if (DSPI_IP_0_ENABLED == STD_ON)
ISR(Dspi_Ip_DSPI_0_IRQHandler);
        #if (DSPI_IP_DMA_USED == STD_ON)
void Dspi_Ip_DSPI_0_IrqDmaHandler(void);
        #endif
    #endif
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#ifdef DSPI_IP_0_ENABLED
    #if (DSPI_IP_0_ENABLED == STD_ON)
ISR(Dspi_Ip_DSPI_0_IRQHandler)
{
    /* Calling interrupt handler for instance 0 */
    Dspi_Ip_IrqHandler(0u);
}
        #if (DSPI_IP_DMA_USED == STD_ON)
void Dspi_Ip_DSPI_0_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 0 */
    Dspi_Ip_IrqDmaHandler(0u);
}
        #endif
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif /*(STD_ON == DSPI_IP_ENABLE)*/

#ifdef __cplusplus
}
#endif

/** @} */
