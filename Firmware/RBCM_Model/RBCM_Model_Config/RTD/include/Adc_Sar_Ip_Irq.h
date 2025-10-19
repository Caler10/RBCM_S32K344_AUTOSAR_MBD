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

#ifndef ADC_SAR_IP_IRQ_H
#define ADC_SAR_IP_IRQ_H

/**
*   @file
*
*   @addtogroup adc_sar_ip Adc Sar IPL
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
#include "Std_Types.h"
#include "Adc_Sar_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_IRQ                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_IRQ               5
#define ADC_SAR_IP_SW_MINOR_VERSION_IRQ               0
#define ADC_SAR_IP_SW_PATCH_VERSION_IRQ               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Sar_Ip_Irq.h file and Std_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Irq.h and Std_Types.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Adc_Sar_Ip_Irq.h file and Adc_Sar_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_IRQ != ADC_SAR_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Sar_Ip_Irq.h and Adc_Sar_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Irq.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_IRQ != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_IRQ != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_IRQ != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Irq.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Sar_Ip_Irq.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_IRQ != ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_IRQ != ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_IRQ != ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Irq.h and Adc_Sar_Ip_CfgDefines.h are different"
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

/* ISR prototypes required by IAR compiler */
ISR(Adc_Sar_0_Isr);
#if (ADC_SAR_IP_INSTANCE_COUNT >= 2)
ISR(Adc_Sar_1_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 2) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 3)
ISR(Adc_Sar_2_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 3) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 4)
ISR(Adc_Sar_3_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 4) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 5)
ISR(Adc_Sar_4_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 5) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 6)
ISR(Adc_Sar_5_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 6) */
#if (ADC_SAR_IP_INSTANCE_COUNT >= 7)
ISR(Adc_Sar_6_Isr);
#endif /* (ADC_SAR_IP_INSTANCE_COUNT >= 7) */

void Adc_Sar_Ip_IRQHandler(const uint32 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* ADC_SAR_IP_IRQ_H */
