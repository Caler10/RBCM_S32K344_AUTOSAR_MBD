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

#ifndef ADC_MBDT_PBCFG_H
#define ADC_MBDT_PBCFG_H

/**
*   @file
*
*   @addtogroup adc_driver_config Adc Driver Configuration
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

#include "Adc_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_MBDT_PBCFG                      43
#define ADC_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG       4
#define ADC_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG       7
#define ADC_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG    0
#define ADC_SW_MAJOR_VERSION_MBDT_PBCFG               5
#define ADC_SW_MINOR_VERSION_MBDT_PBCFG               0
#define ADC_SW_PATCH_VERSION_MBDT_PBCFG               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc Configuration header file and Adc Types header file are of the same vendor */
#if (ADC_VENDOR_ID_MBDT_PBCFG != ADC_VENDOR_ID_TYPES)
    #error "Adc_MBDT_PBcfg.h and Adc_Types.h have different vendor ids"
#endif

/* Check if Adc Configuration header file and Adc Types header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG != ADC_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG != ADC_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG != ADC_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_MBDT_PBcfg.h and Adc_Types.h are different"
#endif

/* Check if Adc Configuration header file and Adc Types header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_MBDT_PBCFG != ADC_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION_MBDT_PBCFG != ADC_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION_MBDT_PBCFG != ADC_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_MBDT_PBcfg.h and Adc_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define ADC_CONFIG_MBDT_PB \
 extern const Adc_ConfigType Adc_Config_MBDT;\
/**
* @brief           Number of channels configured for each group.
*
*/

#define ADC_CFGSET_MBDT_GROUP_0_CHANNELS      (6U)
#define ADC_CFGSET_MBDT_GROUP_1_CHANNELS      (3U)
#define ADC_CFGSET_MBDT_GROUP_2_CHANNELS      (5U)
#define ADC_CFGSET_MBDT_GROUP_3_CHANNELS      (6U)
#define ADC_CFGSET_MBDT_GROUP_4_CHANNELS      (3U)
#define ADC_CFGSET_MBDT_GROUP_5_CHANNELS      (5U)

/**
* @brief          Total number of groups in Config.
*
*/
#define ADC_GROUPS_MBDT                       (6U)


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
* @brief         ADC Notification functions.
* @details       ADC Notification functions defined by user.
*
*/
void Adc_Adc0Group0Notification(void);
void Adc_Adc1Group0Notification(void);
void Adc_Adc2Group0Notification(void);
void Adc_Adc0Group1Notification(void);
void Adc_Adc1Group1Notification(void);
void Adc_Adc2Group1Notification(void);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_MBDT_PBCFG_H */

