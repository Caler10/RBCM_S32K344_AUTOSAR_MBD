/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
*   Dependencies         : none
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

#ifndef ADC_SAR_IP_MBDT_PBCFG_H
#define ADC_SAR_IP_MBDT_PBCFG_H

/**
*   @file
*
*   @addtogroup adc_sar_ip_config Adc Sar IPL Configuration
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
#include "Adc_Sar_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_MBDT_PBCFG                     43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG      4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG      7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG   0
#define ADC_SAR_IP_SW_MAJOR_VERSION_MBDT_PBCFG              4
#define ADC_SAR_IP_SW_MINOR_VERSION_MBDT_PBCFG              0
#define ADC_SAR_IP_SW_PATCH_VERSION_MBDT_PBCFG              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_MBDT_PBcfg.h file and Adc_Sar_Ip_Types.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_MBDT_PBCFG != ADC_SAR_IP_VENDOR_ID_TYPES)
    #error "Adc_Sar_Ip_MBDT_PBcfg.h and Adc_Sar_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_MBDT_PBcfg.h file and Adc_Sar_Ip_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_MBDT_PBcfg.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Sar_Ip_MBDT_PBcfg.h file and Adc_Sar_Ip_Types.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_MBDT_PBCFG != ADC_SAR_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_MBDT_PBCFG != ADC_SAR_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_MBDT_PBCFG != ADC_SAR_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_MBDT_PBcfg.h and Adc_Sar_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

void Adc_Ipw_Adc0EndNormalChainNotification(void);
void Adc_Ipw_Adc1EndNormalChainNotification(void);
void Adc_Ipw_Adc2EndNormalChainNotification(void);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          ADC SAR Ip Config for Logical ID 0 corresponding to the ADC0 configuration variant MBDT .
*/
extern const Adc_Sar_Ip_ConfigType AdcSarIpConfig_0_MBDT;

/**
* @brief          ADC SAR Ip Config for Logical ID 1 corresponding to the ADC1 configuration variant MBDT .
*/
extern const Adc_Sar_Ip_ConfigType AdcSarIpConfig_1_MBDT;

/**
* @brief          ADC SAR Ip Config for Logical ID 2 corresponding to the ADC2 configuration variant MBDT .
*/
extern const Adc_Sar_Ip_ConfigType AdcSarIpConfig_2_MBDT;


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_MBDT_PBCFG_H */

