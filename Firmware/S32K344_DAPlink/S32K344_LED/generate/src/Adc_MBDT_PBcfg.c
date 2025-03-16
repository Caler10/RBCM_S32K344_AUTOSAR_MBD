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
#include "Adc_MBDT_PBcfg.h"
#include "Adc_Ipw_MBDT_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_VENDOR_ID_MBDT_PBCFG_C                    43
#define ADC_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C     4
#define ADC_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C     7
#define ADC_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C  0
#define ADC_SW_MAJOR_VERSION_MBDT_PBCFG_C             4
#define ADC_SW_MINOR_VERSION_MBDT_PBCFG_C             0
#define ADC_SW_PATCH_VERSION_MBDT_PBCFG_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_MBDT_PBcfg.c file and Adc_MBDT_PBcfg.h file are of the same vendor */
#if (ADC_VENDOR_ID_MBDT_PBCFG_C != ADC_VENDOR_ID_MBDT_PBCFG)
    #error "Adc_MBDT_PBcfg.c and Adc_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_MBDT_PBcfg.c file and Adc_MBDT_PBcfg.h file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != ADC_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != ADC_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != ADC_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_MBDT_PBcfg.c and Adc_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_MBDT_PBcfg.c file and Adc_MBDT_PBcfg.h file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_MBDT_PBCFG_C != ADC_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_SW_MINOR_VERSION_MBDT_PBCFG_C != ADC_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_SW_PATCH_VERSION_MBDT_PBCFG_C != ADC_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_MBDT_PBcfg.c and Adc_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_MBDT_PBcfg.c file and Adc_Ipw_MBDT_PBcfg.h file are of the same vendor */
#if (ADC_VENDOR_ID_MBDT_PBCFG_C != ADC_IPW_VENDOR_ID_MBDT_PBCFG)
    #error "Adc_MBDT_PBcfg.c and Adc_Ipw_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_MBDT_PBcfg.c file and Adc_Ipw_MBDT_PBcfg.h file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_MBDT_PBcfg.c and Adc_Ipw_MBDT_PBcfg.h are different"
#endif

/* Check if Adc_MBDT_PBcfg.c file and Adc_Ipw_MBDT_PBcfg.h file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (ADC_SW_MINOR_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (ADC_SW_PATCH_VERSION_MBDT_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Adc_MBDT_PBcfg.c and Adc_Ipw_MBDT_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Group Assignments on ADC0 MBDT.
*
*/
static const Adc_ChannelType Adc_Group0_Assignment_0_MBDT[ADC_CFGSET_MBDT_GROUP_0_CHANNELS] =
{
    0U
};

/**
* @brief          Group Assignments on ADC0 MBDT.
*
*/
static const Adc_ChannelType Adc_Group3_Assignment_0_MBDT[ADC_CFGSET_MBDT_GROUP_3_CHANNELS] =
{
    0U
};

/**
* @brief          Group Assignments on ADC1 MBDT.
*
*/
static const Adc_ChannelType Adc_Group1_Assignment_1_MBDT[ADC_CFGSET_MBDT_GROUP_1_CHANNELS] =
{
    0U
};

/**
* @brief          Group Assignments on ADC1 MBDT.
*
*/
static const Adc_ChannelType Adc_Group4_Assignment_1_MBDT[ADC_CFGSET_MBDT_GROUP_4_CHANNELS] =
{
    0U
};

/**
* @brief          Group Assignments on ADC2 MBDT.
*
*/
static const Adc_ChannelType Adc_Group2_Assignment_2_MBDT[ADC_CFGSET_MBDT_GROUP_2_CHANNELS] =
{
    0U
};

/**
* @brief          Group Assignments on ADC2 MBDT.
*
*/
static const Adc_ChannelType Adc_Group5_Assignment_2_MBDT[ADC_CFGSET_MBDT_GROUP_5_CHANNELS] =
{
    0U
};

/**
* @brief          Definition of all ADC groups for configuration variant MBDT.
*/
static const Adc_GroupConfigurationType Adc_GroupsCfg_MBDT[] =
{
    /**< @brief Group0 -- Logical Unit Id 0 -- Hardware Unit ADC0 */
    {
        /**< @brief Index of group */
        0U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)0, /* AdcLogicalUnitId */
        /**< @brief Access mode */
        ADC_ACCESS_MODE_SINGLE, /* AccessMode */
        /**< @brief Conversion mode */
        ADC_CONV_MODE_ONESHOT, /* Mode */
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL, /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        (Adc_GroupPriorityType)ADC_GROUP_PRIORITY(0), /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* ReplacementMode */
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW, /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger source for the group */
        0U, /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_RISING_EDGE, /* TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        Adc_Adc0Group0Notification, /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        NULL_PTR, /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR, /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX, /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES(1), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)FALSE, /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group0_Assignment_0_MBDT, /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_MBDT_GROUP_0_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(0)), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(0)), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)(STD_OFF), /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)(STD_OFF), /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)FALSE, /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)FALSE, /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)FALSE, /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)FALSE, /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        { { 0x1U, 0x0U, 0x0U } }, /* AssignedChannelMask */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
        /**< @brief First position of channel in BCTU channel list or CTU command list. */
        0U, /* CtuTrigListPos */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        &AdcIpwGroupConfig_0_MBDT /* AdcIpwGroupConfigPtr */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */
    },
    /**< @brief Group1 -- Logical Unit Id 1 -- Hardware Unit ADC1 */
    {
        /**< @brief Index of group */
        1U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)1, /* AdcLogicalUnitId */
        /**< @brief Access mode */
        ADC_ACCESS_MODE_SINGLE, /* AccessMode */
        /**< @brief Conversion mode */
        ADC_CONV_MODE_ONESHOT, /* Mode */
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL, /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        (Adc_GroupPriorityType)ADC_GROUP_PRIORITY(0), /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* ReplacementMode */
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW, /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger source for the group */
        0U, /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_RISING_EDGE, /* TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        Adc_Adc1Group0Notification, /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        NULL_PTR, /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR, /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX, /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES(1), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)FALSE, /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group1_Assignment_1_MBDT, /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_MBDT_GROUP_1_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(34)), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(34)), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)(STD_OFF), /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)(STD_OFF), /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)FALSE, /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)FALSE, /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)FALSE, /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)FALSE, /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        { { 0x0U, 0x4U, 0x0U } }, /* AssignedChannelMask */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
        /**< @brief First position of channel in BCTU channel list or CTU command list. */
        0U, /* CtuTrigListPos */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        &AdcIpwGroupConfig_1_MBDT /* AdcIpwGroupConfigPtr */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */
    },
    /**< @brief Group2 -- Logical Unit Id 2 -- Hardware Unit ADC2 */
    {
        /**< @brief Index of group */
        2U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)2, /* AdcLogicalUnitId */
        /**< @brief Access mode */
        ADC_ACCESS_MODE_SINGLE, /* AccessMode */
        /**< @brief Conversion mode */
        ADC_CONV_MODE_ONESHOT, /* Mode */
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL, /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        (Adc_GroupPriorityType)ADC_GROUP_PRIORITY(0), /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* ReplacementMode */
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW, /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger source for the group */
        0U, /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_RISING_EDGE, /* TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        Adc_Adc2Group0Notification, /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        NULL_PTR, /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR, /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX, /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES(1), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)FALSE, /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group2_Assignment_2_MBDT, /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_MBDT_GROUP_2_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(43)), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(43)), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)(STD_OFF), /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)(STD_OFF), /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)FALSE, /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)FALSE, /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)FALSE, /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)FALSE, /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        { { 0x0U, 0x800U, 0x0U } }, /* AssignedChannelMask */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
        /**< @brief First position of channel in BCTU channel list or CTU command list. */
        0U, /* CtuTrigListPos */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        &AdcIpwGroupConfig_2_MBDT /* AdcIpwGroupConfigPtr */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */
    },
    /**< @brief Group3 -- Logical Unit Id 0 -- Hardware Unit ADC0 */
    {
        /**< @brief Index of group */
        3U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)0, /* AdcLogicalUnitId */
        /**< @brief Access mode */
        ADC_ACCESS_MODE_STREAMING, /* AccessMode */
        /**< @brief Conversion mode */
        ADC_CONV_MODE_CONTINUOUS, /* Mode */
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL, /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        (Adc_GroupPriorityType)ADC_GROUP_PRIORITY(0), /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* ReplacementMode */
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW, /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger source for the group */
        0U, /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_RISING_EDGE, /* TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        Adc_Adc0Group1Notification, /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        NULL_PTR, /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR, /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX, /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES(1), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)FALSE, /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group3_Assignment_0_MBDT, /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_MBDT_GROUP_3_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(0)), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(0)), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)(STD_OFF), /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)(STD_OFF), /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)FALSE, /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)FALSE, /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)FALSE, /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)FALSE, /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        { { 0x1U, 0x0U, 0x0U } }, /* AssignedChannelMask */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
        /**< @brief First position of channel in BCTU channel list or CTU command list. */
        0U, /* CtuTrigListPos */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        &AdcIpwGroupConfig_3_MBDT /* AdcIpwGroupConfigPtr */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */
    },
    /**< @brief Group4 -- Logical Unit Id 1 -- Hardware Unit ADC1 */
    {
        /**< @brief Index of group */
        4U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)1, /* AdcLogicalUnitId */
        /**< @brief Access mode */
        ADC_ACCESS_MODE_STREAMING, /* AccessMode */
        /**< @brief Conversion mode */
        ADC_CONV_MODE_CONTINUOUS, /* Mode */
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL, /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        (Adc_GroupPriorityType)ADC_GROUP_PRIORITY(0), /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* ReplacementMode */
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW, /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger source for the group */
        0U, /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_RISING_EDGE, /* TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        Adc_Adc1Group1Notification, /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        NULL_PTR, /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR, /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX, /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES(1), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)FALSE, /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group4_Assignment_1_MBDT, /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_MBDT_GROUP_4_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(34)), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(34)), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)(STD_OFF), /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)(STD_OFF), /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)FALSE, /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)FALSE, /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)FALSE, /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)FALSE, /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        { { 0x0U, 0x4U, 0x0U } }, /* AssignedChannelMask */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
        /**< @brief First position of channel in BCTU channel list or CTU command list. */
        0U, /* CtuTrigListPos */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        &AdcIpwGroupConfig_4_MBDT /* AdcIpwGroupConfigPtr */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */
    },
    /**< @brief Group5 -- Logical Unit Id 2 -- Hardware Unit ADC2 */
    {
        /**< @brief Index of group */
        5U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)2, /* AdcLogicalUnitId */
        /**< @brief Access mode */
        ADC_ACCESS_MODE_STREAMING, /* AccessMode */
        /**< @brief Conversion mode */
        ADC_CONV_MODE_CONTINUOUS, /* Mode */
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL, /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        (Adc_GroupPriorityType)ADC_GROUP_PRIORITY(0), /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* ReplacementMode */
        /**< @brief Trigger source configured */
        ADC_TRIGG_SRC_SW, /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger source for the group */
        0U, /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        ADC_HW_TRIG_RISING_EDGE, /* TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        Adc_Adc2Group1Notification, /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        NULL_PTR, /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
        /**< @brief Group Streaming Buffer Mode */
        ADC_STREAM_BUFFER_LINEAR, /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX, /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES(3), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)FALSE, /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group5_Assignment_2_MBDT, /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET_MBDT_GROUP_5_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(43)), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8(43)), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)(STD_OFF), /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)(STD_OFF), /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)FALSE, /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)FALSE, /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)FALSE, /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)FALSE, /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        { { 0x0U, 0x800U, 0x0U } }, /* AssignedChannelMask */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
        /**< @brief First position of channel in BCTU channel list or CTU command list. */
        0U, /* CtuTrigListPos */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        &AdcIpwGroupConfig_5_MBDT /* AdcIpwGroupConfigPtr */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */
    }
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_16
#include "Adc_MemMap.h"

/**
* @brief         Array of index for mapping the groups.
* @details       Array of index for mapping the groups in each partition.
*
*/
static const uint16 Adc_au16GroupIdToIndexMap_MBDT[ADC_MAX_GROUPS] =
{
    0,
    1,
    2,
    3,
    4,
    5
};

#define ADC_STOP_SEC_CONFIG_DATA_16
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONFIG_DATA_8
#include "Adc_MemMap.h"

/**
* @brief         Array contains coreId used for MBDT.
* @details       Array contains coreId used for MBDT.
*
*/
static const uint8 Adc_Partition_Assignment_MBDT[1] =
{
    (uint8)(0UL)
};

#define ADC_STOP_SEC_CONFIG_DATA_8
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/* VariantPostBuild or more than 1 configured variant */
/* No ADC configured Ecuc Partitions */

/**
* @brief          ADC driver Configuration structure MBDT.
*/
const Adc_ConfigType Adc_Config_MBDT =
{
    &AdcIpwCfg_MBDT, /* AdcIpwConfigPtr */
    /** @brief Group configurations */
    Adc_GroupsCfg_MBDT, /* GroupsPtr */
    ADC_GROUPS_MBDT, /* GroupCount */
    /**< @brief Array for mapping the groups */
    Adc_au16GroupIdToIndexMap_MBDT, /* GroupIdToIndexMapPtr */
    /** @brief Configuration CoreID */
    (uint8)(0U), /* CoreId */
    /**< @brief Array contains CoreId */
    Adc_Partition_Assignment_MBDT, /* AssignmentPartitionPtr */
    /**< @brief Number of partitions */
    (uint8)1UL /* AssignedPartitionCount */
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

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

