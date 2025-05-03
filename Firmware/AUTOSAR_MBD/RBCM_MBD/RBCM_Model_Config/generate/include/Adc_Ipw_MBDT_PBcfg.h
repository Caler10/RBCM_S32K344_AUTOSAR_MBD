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

#ifndef ADC_IPW_MBDT_PBCFG_H
#define ADC_IPW_MBDT_PBCFG_H

/**
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
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
#include "Adc_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_MBDT_PBCFG                       43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG        4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG        7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG     0
#define ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG                5
#define ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG                0
#define ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check vendor id */
#if (ADC_IPW_VENDOR_ID_MBDT_PBCFG != ADC_IPW_VENDOR_ID_TYPES)
    #error "Adc_Ipw_MBDT_PBcfg.h and Adc_Ipw_Types.h have different vendor ids"
#endif

/* Check Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG != ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG != ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_MBDT_PBcfg.h and Adc_Ipw_Types.h are different"
#endif

/* Check Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG != ADC_IPW_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG != ADC_IPW_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG != ADC_IPW_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_MBDT_PBcfg.h and Adc_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Adc Ipw Config configuration variant MBDT.
*/
extern const Adc_Ipw_Config AdcIpwCfg_MBDT;

#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          ADC Ipw Group 0 Config MBDT.
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_0_MBDT;

/**
* @brief          ADC Ipw Group 1 Config MBDT.
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_1_MBDT;

/**
* @brief          ADC Ipw Group 2 Config MBDT.
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_2_MBDT;

/**
* @brief          ADC Ipw Group 3 Config MBDT.
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_3_MBDT;

/**
* @brief          ADC Ipw Group 4 Config MBDT.
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_4_MBDT;

/**
* @brief          ADC Ipw Group 5 Config MBDT.
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_5_MBDT;

#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"



#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_MBDT_PBCFG_H */

