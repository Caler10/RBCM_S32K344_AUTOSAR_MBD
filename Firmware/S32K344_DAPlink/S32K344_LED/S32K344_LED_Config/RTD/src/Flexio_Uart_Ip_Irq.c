/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*   @defgroup flexio_uart_ip Flexio UART IPL
*   @addtogroup  flexio_uart_ip Flexio UART IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Uart_Ip.h"
#include "Flexio_Uart_Ip_Irq.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_UART_IP_IRQ_VENDOR_ID_C                      43
#define FLEXIO_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_UART_IP_IRQ_SW_MAJOR_VERSION_C               4
#define FLEXIO_UART_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXIO_UART_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Flexio_Uart_Ip.h */
#if (FLEXIO_UART_IP_IRQ_VENDOR_ID_C != FLEXIO_UART_IP_VENDOR_ID)
    #error "Flexio_Uart_Ip_Irq.c and Flexio_Uart_Ip.h have different vendor ids"
#endif
#if ((FLEXIO_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_UART_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_UART_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_UART_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Flexio_Uart_Ip_Irq.c and Flexio_Uart_Ip.h are different"
#endif
#if ((FLEXIO_UART_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_UART_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_UART_IP_SW_MINOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_UART_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Uart_Ip_Irq.c and Flexio_Uart_Ip.h are different"
#endif
/* Checks against Flexio_Uart_Ip_Irq.h */
#if (FLEXIO_UART_IP_IRQ_VENDOR_ID_C != FLEXIO_UART_IP_IRQ_VENDOR_ID)
    #error "Flexio_Uart_Ip_Irq.c and Flexio_Uart_Ip_Irq.h have different vendor ids"
#endif
#if ((FLEXIO_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Flexio_Uart_Ip_Irq.c and Flexio_Uart_Ip_Irq.h are different"
#endif
#if ((FLEXIO_UART_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_UART_IP_IRQ_SW_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_UART_IP_IRQ_SW_MINOR_VERSION) || \
     (FLEXIO_UART_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_UART_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Uart_Ip_Irq.c and Flexio_Uart_Ip_Irq.h are different"
#endif
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

#ifdef FLEXIO_UART_IP_IS_USING
#if (FLEXIO_UART_IP_IS_USING == STD_ON)
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"


#if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 0U)
void Flexio_0_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(0);
}
void Flexio_0_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(0);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 1U)
void Flexio_1_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(1);
}
void Flexio_1_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(1);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 2U)
void Flexio_2_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(2);
}
void Flexio_2_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(2);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 3U)
void Flexio_3_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(3);
}
void Flexio_3_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(3);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 4U)
void Flexio_4_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(4);
}
void Flexio_4_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(4);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 5U)
void Flexio_5_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(5);
}
void Flexio_5_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(5);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 6U)
void Flexio_6_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(6);
}
void Flexio_6_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(6);
}
#endif

#if (FLEXIO_UART_IP_NUMBER_OF_SHIFTER_AND_TIMER > 7U)
void Flexio_7_Uart_Ip_DmaRxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteReceiveUsingDma(7);
}
void Flexio_7_Uart_Ip_DmaTxCompleteCallback(void)
{
    Flexio_Uart_Ip_CompleteSendUsingDma(7);
}
#endif
#endif /*(FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)*/

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#endif /* (FLEXIO_UART_IP_IS_USING == STD_ON) */
#endif /* #ifdef FLEXIO_UART_IP_IS_USING */

#ifdef __cplusplus
}
#endif

/** @} */
