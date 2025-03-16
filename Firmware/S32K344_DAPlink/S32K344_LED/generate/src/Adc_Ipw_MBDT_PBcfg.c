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

#include "Adc_Ipw_CfgDefines.h"
#include "Adc_Ipw_MBDT_PBcfg.h"
#include "Adc_Sar_Ip_MBDT_PBcfg.h"
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
#include "Sdadc_Ip_MBDT_PBcfg.h"
#endif
#include "Bctu_Ip_MBDT_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_MBDT_PBCFG_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C       7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C    0
#define ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_C               4
#define ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG_C               0
#define ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_MBDT_PBCFG_C != ADC_IPW_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_MBDT_PBcfg.c and Adc_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Ipw_MBDT_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_MBDT_PBCFG_C != ADC_IPW_VENDOR_ID_MBDT_PBCFG)
    #error "Adc_Ipw_MBDT_PBcfg.c and Adc_Ipw_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Ipw_MBDT_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Adc_Ipw_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Ipw_MBDT_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Adc_Ipw_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Sar_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_MBDT_PBCFG_C != ADC_SAR_IP_VENDOR_ID_MBDT_PBCFG)
    #error "Adc_Ipw_MBDT_PBcfg.c and Adc_Sar_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Sar_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Adc_Sar_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Adc_Sar_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG_C != ADC_SAR_IP_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Adc_Sar_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Bctu_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_MBDT_PBCFG_C != BCTU_IP_VENDOR_ID_MBDT_PBCFG)
    #error "Adc_Ipw_MBDT_PBcfg.c and Bctu_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Bctu_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != BCTU_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Bctu_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_MBDT_PBcfg.c file and Bctu_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_C != BCTU_IP_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG_C != BCTU_IP_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG_C != BCTU_IP_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_MBDT_PBcfg.c and Bctu_Ip_MBDT_PBcfg.h are different"
#endif


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


/**
* @brief          Definition of Adc Ipw Channel for Logical Unit Id 0 configuration variant MBDT .
*/
static const Adc_Ipw_ChannelConfig AdcIpwChannelConfig_0_MBDT[] =
{
    /**< @brief Channel logical Id 0 */
    {
        NULL_PTR, /* WdgNotification */
        0U, /* LogicalThresholdId */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* ChannelLimitCheckingConfig */
        {
            /**< @brief limit check enabled */
            (boolean)FALSE, /* ChannelLimitCheckEnabled */
            /**< @brief range for limit check */
            ADC_RANGE_ALWAYS, /* ChannelRange */
            /**< @brief high limit value */
            4095U, /* ChannelHighLimit */
            /**< @brief low limit value */
            0U /* ChannelLowLimit */
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }
};

/**
* @brief          Definition of Adc Ipw Channel for Logical Unit Id 1 configuration variant MBDT .
*/
static const Adc_Ipw_ChannelConfig AdcIpwChannelConfig_1_MBDT[] =
{
    /**< @brief Channel logical Id 0 */
    {
        NULL_PTR, /* WdgNotification */
        0U, /* LogicalThresholdId */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* ChannelLimitCheckingConfig */
        {
            /**< @brief limit check enabled */
            (boolean)FALSE, /* ChannelLimitCheckEnabled */
            /**< @brief range for limit check */
            ADC_RANGE_ALWAYS, /* ChannelRange */
            /**< @brief high limit value */
            4095U, /* ChannelHighLimit */
            /**< @brief low limit value */
            0U /* ChannelLowLimit */
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }
};

/**
* @brief          Definition of Adc Ipw Channel for Logical Unit Id 2 configuration variant MBDT .
*/
static const Adc_Ipw_ChannelConfig AdcIpwChannelConfig_2_MBDT[] =
{
    /**< @brief Channel logical Id 0 */
    {
        NULL_PTR, /* WdgNotification */
        0U, /* LogicalThresholdId */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* ChannelLimitCheckingConfig */
        {
            /**< @brief limit check enabled */
            (boolean)FALSE, /* ChannelLimitCheckEnabled */
            /**< @brief range for limit check */
            ADC_RANGE_ALWAYS, /* ChannelRange */
            /**< @brief high limit value */
            4095U, /* ChannelHighLimit */
            /**< @brief low limit value */
            0U /* ChannelLowLimit */
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Adc Ipw Config configuration variant MBDT.
*/
const Adc_Ipw_Config AdcIpwCfg_MBDT =
{
    { &AdcSarIpConfig_0_MBDT, &AdcSarIpConfig_1_MBDT, &AdcSarIpConfig_2_MBDT }, /* AdcConfigPtrArr */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    { NULL_PTR, NULL_PTR, NULL_PTR }, /* SdadcConfigPtrArr  */
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    { 0U, 1U, 2U }, /* AdcPhysicalIdArr */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { NULL_PTR, NULL_PTR, NULL_PTR }, /* AdcAltClockConfig */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { AdcIpwChannelConfig_0_MBDT, AdcIpwChannelConfig_1_MBDT, AdcIpwChannelConfig_2_MBDT }, /* AdcIpwChannelConfig */
#if ((ADC_IPW_BCTU_AVAILABLE == STD_ON))
    { NULL_PTR }, /* CtuConfigTriggerMode */
    { &BctuIpConfigControlMode_0_MBDT }, /* CtuConfigControlMode */
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_BCTU_AVAILABLE == STD_ON) || (ADC_IPW_CTU_AVAILABLE == STD_ON)))
    { 0U, 0U, 0U }, /* CtuListStartIndex */
    { 0U, 0U, 0U }, /* CtuListMaxNumElems */
#endif /* ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_BCTU_AVAILABLE == STD_ON) || (ADC_IPW_CTU_AVAILABLE == STD_ON))) */

    { 1U, 1U, 1U }, /* AdcUnitSupportCtuControlMode */

    /* Mapping */
    {
        { ADC_INTERRUPT, ADC_INTERRUPT, ADC_INTERRUPT }, /* AdcDmaInterruptSoftware */
        /**< @brief number of the maximum hardware units in the current configuration */
        3U, /* AdcMaxHwCfg */
        /**< @brief number of groups per hw unit > */
        { 2U, 2U, 2U }, /* AdcGroups */
        /**< @brief number of channels per hw unit > */
        { 1U, 1U, 1U }, /* AdcChannels */
#if ((defined(ADC_ANY_UNIT_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
        /* ChannelLogicalId */
        {
            { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
            { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
            { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
        },
#endif /* ((defined(ADC_ANY_UNIT_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcDmaChannelLogicId */
        { 0U, 0U, 0U }, /* DmaNumSgaElement */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcCountingDmaChanLogicId */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        { STD_ON, STD_ON, STD_ON }, /* AdcHwUnitArr */
        { 0U, 1U, 2U }, /* HwLogicalId */
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
        { 0U }, /* CtuLogToPhyId */
        { 0U }, /* CtuPhyToLogId */
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
    }
};

#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          ADC Ipw Group 0 Config MBDT.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_0_MBDT =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

/**
* @brief          ADC Ipw Group 1 Config MBDT.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_1_MBDT =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

/**
* @brief          ADC Ipw Group 2 Config MBDT.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_2_MBDT =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

/**
* @brief          ADC Ipw Group 3 Config MBDT.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_3_MBDT =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

/**
* @brief          ADC Ipw Group 4 Config MBDT.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_4_MBDT =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

/**
* @brief          ADC Ipw Group 5 Config MBDT.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_5_MBDT =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
