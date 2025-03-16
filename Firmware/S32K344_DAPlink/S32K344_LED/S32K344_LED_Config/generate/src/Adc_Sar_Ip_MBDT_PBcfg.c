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
#include "Adc_Sar_Ip_MBDT_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_MBDT_PBCFG_C                     43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C      4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C      7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C   0
#define ADC_SAR_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C              4
#define ADC_SAR_IP_SW_MINOR_VERSION_MBDT_PBCFG_C              0
#define ADC_SAR_IP_SW_PATCH_VERSION_MBDT_PBCFG_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_MBDT_PBcfg.c file and Adc_Sar_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_MBDT_PBCFG_C != ADC_SAR_IP_VENDOR_ID_MBDT_PBCFG)
    #error "Adc_Sar_Ip_MBDT_PBcfg.c and Adc_Sar_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_MBDT_PBcfg.c file and Adc_Sar_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_MBDT_PBcfg.c and Adc_Sar_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_Sar_Ip_MBDT_PBcfg.c file and Adc_Sar_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_MBDT_PBcfg.c and Adc_Sar_Ip_MBDT_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          ADC SAR Ip List of Channels Configuration for Logical ID 0 corresponding to the ADC0 configuration variant MBDT .
*/
static const Adc_Sar_Ip_ChanConfigType AdcSarIpChansConfig_0_MBDT[1] =
{
    {
        0U, /* ChanIndex */
        (boolean)TRUE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)FALSE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    }
};

/**
* @brief          ADC SAR Ip List of Channels Configuration for Logical ID 1 corresponding to the ADC1 configuration variant MBDT .
*/
static const Adc_Sar_Ip_ChanConfigType AdcSarIpChansConfig_1_MBDT[1] =
{
    {
        34U, /* ChanIndex */
        (boolean)TRUE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)FALSE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    }
};

/**
* @brief          ADC SAR Ip List of Channels Configuration for Logical ID 2 corresponding to the ADC2 configuration variant MBDT .
*/
static const Adc_Sar_Ip_ChanConfigType AdcSarIpChansConfig_2_MBDT[1] =
{
    {
        43U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)FALSE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    }
};



/**
* @brief          ADC SAR Ip Config for Logical ID 0 corresponding to the ADC0 configuration variant MBDT .
*/
const Adc_Sar_Ip_ConfigType AdcSarIpConfig_0_MBDT =
{
    ADC_SAR_IP_CONV_MODE_ONESHOT, /* ConvMode */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    ADC_SAR_IP_RESOLUTION_14, /* AdcResolution */
    (boolean)FALSE, /* BypassResolution */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
    ADC_SAR_IP_CLK_FULL_BUS, /* ClkSelect */
    ADC_SAR_IP_CLK_FULL_BUS, /* CalibrationClkSelect */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    (boolean)FALSE, /* HighSpeedConvEn */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if ADC_SAR_IP_HAS_CTU
    ADC_SAR_IP_CTU_MODE_DISABLED, /* CtuMode */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_INJ_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* InjectedEdge */
#endif /* FEATURE_ADC_HAS_INJ_EXT_TRIGGER */
#if FEATURE_ADC_HAS_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* ExtTrigger */
    (boolean)FALSE, /* NormalExtTrgEn */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
    (boolean)FALSE, /* NormalAuxExtTrgEn */
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
#endif /* FEATURE_ADC_HAS_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME }, /* SampleTimeArr */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
#if FEATURE_ADC_HAS_PRESAMPLING
    (boolean)FALSE, /* BypassSampling */
    { ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL }, /* PresamplingSourceArr */
#endif /* FEATURE_ADC_HAS_PRESAMPLING */
    (boolean)FALSE, /* AutoClockOff */
    (boolean)FALSE, /* OverwriteEnable */
    ADC_SAR_IP_DATA_ALIGNED_RIGHT, /* DataAlign */
#if FEATURE_ADC_SAR_DECODE_DELAY
    15U, /* DecodeDelay */
#endif /* FEATURE_ADC_SAR_DECODE_DELAY */
    15U, /* PowerDownDelay */
#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
    NULL_PTR, /* SelfTestThresholdConfig */
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */
#if FEATURE_ADC_HAS_AVERAGING
    (boolean)FALSE, /* AvgEn */
    ADC_SAR_IP_AVG_4_CONV, /* AvgSel */
#endif /* FEATURE_ADC_HAS_AVERAGING */
    0U, /* UsrOffset */
    0U, /* UsrGain */
    (boolean)FALSE, /* DmaEnable */
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK, /* DmaClearSource */
    { 0U, 0U, 0U }, /* ChanMaskNormal */
    { 0U, 0U, 0U }, /* ChanMaskInjected */
    1U, /* NumChannels */
    AdcSarIpChansConfig_0_MBDT, /* ChannelConfigsPtr */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    0U, /* NumWdgThresholds */
    NULL_PTR, /* WdgThresholds */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    Adc_Ipw_Adc0EndNormalChainNotification, /* EndOfNormalChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    NULL_PTR, /* EndOfInjectedChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if ADC_SAR_IP_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    NULL_PTR, /* EndOfCtuConversionNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    NULL_PTR, /* EndOfConvNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    NULL_PTR /* WdgOutOfRangeNotification */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
};

/**
* @brief          ADC SAR Ip Config for Logical ID 1 corresponding to the ADC1 configuration variant MBDT .
*/
const Adc_Sar_Ip_ConfigType AdcSarIpConfig_1_MBDT =
{
    ADC_SAR_IP_CONV_MODE_ONESHOT, /* ConvMode */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    ADC_SAR_IP_RESOLUTION_14, /* AdcResolution */
    (boolean)FALSE, /* BypassResolution */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
    ADC_SAR_IP_CLK_FULL_BUS, /* ClkSelect */
    ADC_SAR_IP_CLK_FULL_BUS, /* CalibrationClkSelect */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    (boolean)FALSE, /* HighSpeedConvEn */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if ADC_SAR_IP_HAS_CTU
    ADC_SAR_IP_CTU_MODE_DISABLED, /* CtuMode */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_INJ_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* InjectedEdge */
#endif /* FEATURE_ADC_HAS_INJ_EXT_TRIGGER */
#if FEATURE_ADC_HAS_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* ExtTrigger */
    (boolean)FALSE, /* NormalExtTrgEn */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
    (boolean)FALSE, /* NormalAuxExtTrgEn */
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
#endif /* FEATURE_ADC_HAS_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME }, /* SampleTimeArr */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
#if FEATURE_ADC_HAS_PRESAMPLING
    (boolean)FALSE, /* BypassSampling */
    { ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL }, /* PresamplingSourceArr */
#endif /* FEATURE_ADC_HAS_PRESAMPLING */
    (boolean)FALSE, /* AutoClockOff */
    (boolean)FALSE, /* OverwriteEnable */
    ADC_SAR_IP_DATA_ALIGNED_RIGHT, /* DataAlign */
#if FEATURE_ADC_SAR_DECODE_DELAY
    15U, /* DecodeDelay */
#endif /* FEATURE_ADC_SAR_DECODE_DELAY */
    15U, /* PowerDownDelay */
#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
    NULL_PTR, /* SelfTestThresholdConfig */
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */
#if FEATURE_ADC_HAS_AVERAGING
    (boolean)FALSE, /* AvgEn */
    ADC_SAR_IP_AVG_4_CONV, /* AvgSel */
#endif /* FEATURE_ADC_HAS_AVERAGING */
    0U, /* UsrOffset */
    0U, /* UsrGain */
    (boolean)FALSE, /* DmaEnable */
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK, /* DmaClearSource */
    { 0U, 0U, 0U }, /* ChanMaskNormal */
    { 0U, 0U, 0U }, /* ChanMaskInjected */
    1U, /* NumChannels */
    AdcSarIpChansConfig_1_MBDT, /* ChannelConfigsPtr */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    0U, /* NumWdgThresholds */
    NULL_PTR, /* WdgThresholds */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    Adc_Ipw_Adc1EndNormalChainNotification, /* EndOfNormalChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    NULL_PTR, /* EndOfInjectedChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if ADC_SAR_IP_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    NULL_PTR, /* EndOfCtuConversionNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    NULL_PTR, /* EndOfConvNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    NULL_PTR /* WdgOutOfRangeNotification */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
};

/**
* @brief          ADC SAR Ip Config for Logical ID 2 corresponding to the ADC2 configuration variant MBDT .
*/
const Adc_Sar_Ip_ConfigType AdcSarIpConfig_2_MBDT =
{
    ADC_SAR_IP_CONV_MODE_ONESHOT, /* ConvMode */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    ADC_SAR_IP_RESOLUTION_14, /* AdcResolution */
    (boolean)FALSE, /* BypassResolution */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
    ADC_SAR_IP_CLK_FULL_BUS, /* ClkSelect */
    ADC_SAR_IP_CLK_FULL_BUS, /* CalibrationClkSelect */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    (boolean)FALSE, /* HighSpeedConvEn */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if ADC_SAR_IP_HAS_CTU
    ADC_SAR_IP_CTU_MODE_DISABLED, /* CtuMode */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_INJ_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* InjectedEdge */
#endif /* FEATURE_ADC_HAS_INJ_EXT_TRIGGER */
#if FEATURE_ADC_HAS_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* ExtTrigger */
    (boolean)FALSE, /* NormalExtTrgEn */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
    (boolean)FALSE, /* NormalAuxExtTrgEn */
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
#endif /* FEATURE_ADC_HAS_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME }, /* SampleTimeArr */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
#if FEATURE_ADC_HAS_PRESAMPLING
    (boolean)FALSE, /* BypassSampling */
    { ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL }, /* PresamplingSourceArr */
#endif /* FEATURE_ADC_HAS_PRESAMPLING */
    (boolean)FALSE, /* AutoClockOff */
    (boolean)FALSE, /* OverwriteEnable */
    ADC_SAR_IP_DATA_ALIGNED_RIGHT, /* DataAlign */
#if FEATURE_ADC_SAR_DECODE_DELAY
    15U, /* DecodeDelay */
#endif /* FEATURE_ADC_SAR_DECODE_DELAY */
    15U, /* PowerDownDelay */
#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
    NULL_PTR, /* SelfTestThresholdConfig */
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */
#if FEATURE_ADC_HAS_AVERAGING
    (boolean)FALSE, /* AvgEn */
    ADC_SAR_IP_AVG_4_CONV, /* AvgSel */
#endif /* FEATURE_ADC_HAS_AVERAGING */
    0U, /* UsrOffset */
    0U, /* UsrGain */
    (boolean)FALSE, /* DmaEnable */
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK, /* DmaClearSource */
    { 0U, 0U, 0U }, /* ChanMaskNormal */
    { 0U, 0U, 0U }, /* ChanMaskInjected */
    1U, /* NumChannels */
    AdcSarIpChansConfig_2_MBDT, /* ChannelConfigsPtr */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    0U, /* NumWdgThresholds */
    NULL_PTR, /* WdgThresholds */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    Adc_Ipw_Adc2EndNormalChainNotification, /* EndOfNormalChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    NULL_PTR, /* EndOfInjectedChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if ADC_SAR_IP_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    NULL_PTR, /* EndOfCtuConversionNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    NULL_PTR, /* EndOfConvNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    NULL_PTR /* WdgOutOfRangeNotification */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


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


