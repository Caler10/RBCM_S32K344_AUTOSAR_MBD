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

#ifndef ADC_SAR_IP_CFGDEFINES_H
#define ADC_SAR_IP_CFGDEFINES_H

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
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* Important Note: The header warapper file depends on header platform and can not be used independently.
*  Do not change #include order in this file */
#include "S32K344_ADC.h"
#include "S32K344_TEMPSENSE.h"
#include "Adc_Sar_Ip_HeaderWrapper_S32K3.h"
#include "OsIf.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_CFGDEFINES                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES               5
#define ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES               0
#define ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Sar_Ip_CfgDefines.h file and Adc_Sar_Ip_HeaderWrapper_S32K3.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_CFGDEFINES != ADC_SAR_IP_VENDOR_ID_HEADERWRAPPER_S32K3)
    #error "Adc_Sar_Ip_CfgDefines.h and Adc_Sar_Ip_HeaderWrapper_S32K3.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_CfgDefines.h file and Adc_Sar_Ip_HeaderWrapper_S32K3.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32K3) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32K3) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32K3) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_CfgDefines.h and Adc_Sar_Ip_HeaderWrapper_S32K3.h are different"
#endif

/* Check if Adc_Sar_Ip_CfgDefines.h file and Adc_Sar_Ip_HeaderWrapper_S32K3.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES != ADC_SAR_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32K3) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES != ADC_SAR_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32K3) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES != ADC_SAR_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32K3) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_CfgDefines.h and Adc_Sar_Ip_HeaderWrapper_S32K3.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check AutoSar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

#define ADC_SAR_IP_ECH_ENABLED                (STD_ON)
#define ADC_SAR_IP_JECH_ENABLED               (STD_OFF)
#define ADC_SAR_IP_EOCTU_ENABLED              (STD_OFF)
#define ADC_SAR_IP_EOC_ENABLED                (STD_OFF)
#define ADC_SAR_IP_WDG_ENABLED                (STD_ON)
#define ADC_SAR_IP_SELFTEST_ENABLED           (STD_OFF)
#define ADC_SAR_IP_DEV_ERROR_DETECT           (STD_OFF)
#define ADC_SAR_IP_TIMEOUT_TYPE               (OSIF_COUNTER_DUMMY)
#define ADC_SAR_IP_TIMEOUT_VAL                (3000UL)
#define ADC_SAR_IP_ASYNC_CALIBARTION_ENABLED  (STD_OFF)
#define ADC_SAR_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
#define ADC_SAR_IP_SET_RESOLUTION             (STD_ON)
#define ADC_SAR_IP_TEMPSENSE_ENABLED          (STD_OFF)
#define ADC_SAR_IP_TEMPSENSE_VOLTAGE_SUPPLY   (53U)
#define ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE    (STD_OFF)

#define FEATURE_ADC_HAS_HIGH_SPEED_ENABLE     (1U)
#define FEATURE_ADC_HAS_EXT_TRIGGER           (1U)
#define FEATURE_ADC_HAS_INJ_EXT_TRIGGER       (1U)
#define FEATURE_ADC_HAS_AUX_EXT_TRIGGER       (1U)
#define FEATURE_ADC_HAS_CLOCK_DIVIDER         (0U)
#define FEATURE_ADC_HAS_CALIBRATION           (1U)
#define FEATURE_ADC_HAS_PRESAMPLING           (1U)
#define FEATURE_ADC_HAS_CONVERSION_TIMING     (1U)
#define FEATURE_ADC_HAS_APPLICATION_EXTENSION (0U)
#define FEATURE_ADC_SAR_DECODE_DELAY          (STD_ON)
#define FEATURE_ADC_HAS_AVERAGING             (STD_ON)
#define FEATURE_ADC_SAF8544_CHANNEL_WORKAROUND             (0U)
#define ADC_SAR_IP_DEF_SAMPLE_TIME             (22U)
#define ADC_SAR_IP_NUM_GROUP_CHAN_INIT_VAL   {0U, 0U, 0U}
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_CFGDEFINES_H */

