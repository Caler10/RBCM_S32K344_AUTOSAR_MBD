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

#ifndef SDADC_IP_IRQ_H
#define SDADC_IP_IRQ_H

/**
*   @file Sdadc_Ip_Irq.h
*
*   @addtogroup sd_adc_ip Sd Adc IPL
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Sdadc_Ip_CfgDefines.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SDADC_IP_VENDOR_ID_IRQ                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define SDADC_IP_SW_MAJOR_VERSION_IRQ               5
#define SDADC_IP_SW_MINOR_VERSION_IRQ               0
#define SDADC_IP_SW_PATCH_VERSION_IRQ               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if SDADC_Ip_Irq.h file and SDADC_Ip_CfgDefines.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_IRQ != SDADC_IP_VENDOR_ID_CFGDEFINES)
    #error "SDADC_Ip_Irq.h and SDADC_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if SDADC_Ip_Irq.h file and SDADC_Ip_CfgDefines.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ != SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ != SDADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_IRQ != SDADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Irq.h and SDADC_Ip_CfgDefines.h are different"
#endif

/* Check if SDADC_Ip_Irq.h file and SDADC_Ip_CfgDefines.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_IRQ != SDADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_SW_MINOR_VERSION_IRQ != SDADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_SW_PATCH_VERSION_IRQ != SDADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of SDADC_Ip_Irq.h and SDADC_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check AutoSar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Sdadc_Ip_Irq.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#ifdef FEATURE_ADC_HAS_SDADC


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

/* ISR prototypes required by IAR compiler for SDADC */
ISR(Sdadc_Isr);
void Sdadc_Ip_IRQHandler(void);

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/* ISR prototypes required by IAR compiler for DSPSS */
ISR(Dspss_Thread_0_Isr);
ISR(Dspss_Thread_1_Isr);
#if (DSPSS_THREAD_NUM > 2U)
ISR(Dspss_Thread_2_Isr);
ISR(Dspss_Thread_3_Isr);
#endif /* (DSPSS_THREAD_NUM > 2U) */

void Dspss_IRQHandler(const uint32 Thread);

#if (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON)
/* DSPSS errors interrupt */
ISR(Dspss_Error_Isr);
void Dspss_ErrorIRQHandler(void);
#endif /* (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON) */

#endif

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


#endif /* FEATURE_ADC_HAS_SDADC */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SDADC_IP_IRQ_H */
