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

#ifndef ADC_IPW_TYPES_H
#define ADC_IPW_TYPES_H

/**
*   @file
*
*   @internal
*   @addtogroup adc_ipw Adc Ipw
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

#include "Adc_Sar_Ip_Types.h"

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    #include "Sdadc_Ip_Types.h"
#endif /*(ADC_IPW_SDADC_IS_USED == STD_ON)*/

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    #include "Bctu_Ip_Types.h"
#endif /*(ADC_IPW_BCTU_AVAILABLE == STD_ON)*/

#include "Adc_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_TYPES                       43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES        4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES        7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES     0
#define ADC_IPW_SW_MAJOR_VERSION_TYPES                5
#define ADC_IPW_SW_MINOR_VERSION_TYPES                0
#define ADC_IPW_SW_PATCH_VERSION_TYPES                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ipw_Types.h file and Adc_Ipw_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != ADC_IPW_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_Types.h and Adc_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ipw_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != ADC_IPW_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != ADC_IPW_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Sar_Ip_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != ADC_SAR_IP_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Types.h and Adc_Sar_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Sar_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Sar_Ip_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != ADC_SAR_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != ADC_SAR_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != ADC_SAR_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Adc_Sar_Ip_Types.h are different"
#endif

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
/* Check if Adc_Ipw_Types.h file and Sdadc_Ip_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != SDADC_IP_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Types.h and Sdadc_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Sdadc_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != SDADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != SDADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != SDADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Sdadc_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Sdadc_Ip_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != SDADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != SDADC_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != SDADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Sdadc_Ip_Types.h are different"
#endif
#endif /*(ADC_IPW_SDADC_IS_USED == STD_ON)*/

#if (ADC_IPW_CTU_AVAILABLE == STD_ON)
/* Check if Adc_Ipw_Types.h file and Ctu_Ip_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != CTU_IP_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Types.h and Ctu_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Ctu_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != CTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != CTU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != CTU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Ctu_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Ctu_Ip_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != CTU_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != CTU_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != CTU_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Ctu_Ip_Types.h are different"
#endif
#else
/* Check if Adc_Ipw_Types.h file and Bctu_Ip_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != BCTU_IP_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Types.h and Bctu_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Bctu_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != BCTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != BCTU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != BCTU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Bctu_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Bctu_Ip_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != BCTU_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != BCTU_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != BCTU_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Bctu_Ip_Types.h are different"
#endif
#endif /*(ADC_IPW_CTU_AVAILABLE == STD_ON)*/

/* Check if Adc_Ipw_Types.h file and Adc_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != ADC_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_Types.h and Adc_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != ADC_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != ADC_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Adc_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != ADC_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != ADC_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != ADC_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Adc_CfgDefines.h are different"
#endif
/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef uint8 Adc_HwUnitType;             /**< @brief Numeric ID of an ADC Hw Unit */

/* SWS_Adc_00506 */
/** @implements     Adc_ChannelType_uint */
typedef uint16 Adc_ChannelType;            /**< @brief Numeric ID of an ADC channel */

/* SWS_Adc_00507 */
/** @implements     Adc_GroupType_uint */
typedef uint16 Adc_GroupType;             /**< @brief Numeric ID of an ADC channel group. No uC dependent */

typedef uint16 Adc_QueueIndexType;        /**< @brief Index for the queue of groups */

/**
* @brief           Symbolic names of threshold control register with encoded value.
* @details         Bit fields [12-15]:  The ADC Logical Unit Id
*                  Bit fields [0-11]:   Logical id of threshold control in HW unit (used in Adc_ConfigureThreshold())
*/
typedef uint16 Adc_ThresholdControlIndexType;       /**< @brief Index for the ADC WDG Threshold configuration register */

/**< @brief Notification function pointer definition - WDG
 * The Flags parameter shows which flag triggered it(high/low).
 * The flag values are represented by ADC_SAR_WDG_... defines.
 */
typedef void Adc_WdgNotificationType(const uint8 Flags);

/* SWS_Adc_00510 */
/** @implements     Adc_ConversionTimeType_uint */
typedef uint8 Adc_ConversionTimeType;    /**< @brief conversion time */

/* SWS_Adc_00508 */
/** @implements     Adc_ValueGroupType_int */
typedef uint16 Adc_ValueGroupType;        /**< @brief type for ADC result of one channel */

/* SWS_Adc_00521 */
/** @implements     Adc_HwTriggerTimerType_uint */
typedef uint16 Adc_HwTriggerTimerType;    /**< @brief Type for the reload value of the ADC embedded timer */

typedef uint8 Adc_ChannelIndexType;      /**< @brief Number of channels */

typedef uint16 Adc_WdgThresholdValueType;      /**< @brief Watchdog threshold type */

#if (ADC_CALIBRATION == STD_ON)
typedef uint32 Adc_UserGainType;      /**< @brief User Gain type */

typedef uint32 Adc_UserOffsetType;      /**< @brief User Offset type */
#endif /* ADC_CALIBRATION == STD_ON */

/**
* @brief          Adc group conversion.
* @details        Used for value received by Tressos interface configuration.
*
*/
typedef enum
{
    ADC_CONV_TYPE_NORMAL   = ADC_SAR_IP_CONV_CHAIN_NORMAL,      /**< @brief Normal conversion mode */
    ADC_CONV_TYPE_INJECTED = ADC_SAR_IP_CONV_CHAIN_INJECTED,    /**< @brief Injected conversion mode */
} Adc_GroupConvType;

#if (ADC_SET_HW_UNIT_POWER_MODE_API==STD_ON) || \
    ((ADC_SAR_IP_HAS_TEMPSENSE_CHN == 1U) && (ADC_ENABLE_TEMPSENSE_API == STD_ON))
/**
* @brief          AdcSetHwUnitPowerMode values.
* @details        Indicates all the values to set the Adc mode.
*
*/
typedef enum
{
    ADC_NORMAL_MODE = 0U, /**< @brief Normal mode */
    ADC_POWER_DOWN_MODE   /**< @brief Power down mode */
} Adc_SetPowerModeType;
#endif /* (ADC_SET_HW_UNIT_POWER_MODE_API==STD_ON) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || ((ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON))
/**
* @brief      Power state type
* @details    Power state currently active or set as target power state.
*
* @implements     Adc_PowerStateType_enum
* SWS_Adc_00526
*/
typedef enum
{
    ADC_FULL_POWER = 0U,    /**< @brief Adc full power mode. */
    ADC_LOW_POWER,          /**< @brief Adc low power mode. */
    ADC_NODEFINE_POWER      /**< @brief Adc no define power mode. */
} Adc_PowerStateType;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) || ((ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) */
#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief      Result of power state type
* @details    Result of the requests related to power state transitions.
*
* @implements     Adc_PowerStateRequestResultType_enum
* SWS_Adc_00527
*/
typedef enum
{
    ADC_SERVICE_ACCEPTED = 0U,  /**< @brief Power state change executed. */
    ADC_NOT_INIT,               /**< @brief Module not initialized. */
    ADC_SEQUENCE_ERROR,         /**< @brief Wrong API call sequence. */
    ADC_HW_FAILURE,             /**< @brief The HW module has a failure which prevents it to enter the required power state. */
    ADC_POWER_STATE_NOT_SUPP,   /**< @brief Module does not support the requested power state. */
    ADC_TRANS_NOT_POSSIBLE      /**< @brief Module cannot transition directly from the current power state to the requested power state. */
} Adc_PowerStateRequestResultType;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */


#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Group Access Mode type.
* @details        Used for value received by Tressos interface configuration.
*/
typedef enum
{
    ADC_NORMAL = 0U, /**< @brief Normal mode */
    ADC_ALTERNATE    /**< @brief Alternate mode */
} Adc_SelectPrescalerType;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

/**
* @brief          Adc Group conversion mode.
* @details        Used for value received by Tressos interface configuration.
*
* SWS_Adc_00515, SWS_Adc_00380, SWS_Adc_00381
* @implements     Adc_GroupConvModeType_enum
*/
typedef enum
{
    ADC_CONV_MODE_ONESHOT    = ADC_SAR_IP_CONV_MODE_ONESHOT,  /*!< One-shot conversion mode */
    ADC_CONV_MODE_CONTINUOUS = ADC_SAR_IP_CONV_MODE_SCAN      /*!< Scan conversion mode */
} Adc_GroupConvModeType;


#if (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Range select values.
* @details        Indicates which range select is used.
*
* @implements  Adc_ChannelRangeSelectType_enum
* SWS_Adc_00524
*/
typedef enum
{
    ADC_RANGE_ALWAYS = 0U,   /**< @brief Complete range - independent from channel limit settings */
    ADC_RANGE_BETWEEN,       /**< @brief Range between low limit and high limit - high limit value included */
    ADC_RANGE_NOT_BETWEEN,   /**< @brief Range above high limit or below low limit - low limit value included */
    ADC_RANGE_NOT_OVER_HIGH, /**< @brief Range below high limit - high limit value included */
    ADC_RANGE_NOT_UNDER_LOW, /**< @brief Range above low limit */
    ADC_RANGE_OVER_HIGH,     /**< @brief Range above high limit */
    ADC_RANGE_UNDER_LOW      /**< @briefRange below low limit - low limit value included */
} Adc_ChannelRangeSelectType;

typedef struct
{
    const boolean ChannelLimitCheckEnabled;        /**< @brief Channel limit checking enabled */
    const Adc_ChannelRangeSelectType ChannelRange; /**< @brief  Range conversion */
    const uint16 ChannelHighLimit; /**< @brief High limit channel conversion value */
    const uint16 ChannelLowLimit; /**< @brief Low limit channel conversion value */
} Adc_ChannelLimitCheckingType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__) */

/**
* @brief          NCMR structure type
* @details        This structure is used to enable/disable SW (not injected) trigger groups
*
*/
typedef Adc_Sar_Ip_ChansIdxMaskType Adc_ChansIdxMaskType;

#if (ADC_CALIBRATION == STD_ON)
typedef struct
{
    /** @brief Unit calibration result status */
    Std_ReturnType AdcUnitSelfTestStatus;
#if (ADC_IPW_CALSTAT_AVAILABLE == STD_ON)
    /** @brief List of failed tests */
    uint8 AdcCalibrateFailedSteps[ADC_SAR_IP_MAX_CALIBRATION_STEPS];
#endif /* (ADC_IPW_CALSTAT_AVAILABLE == STD_ON) */
} Adc_CalibrationStatusType;
#endif /* ADC_CALIBRATION == STD_ON */

typedef struct
{
    Adc_WdgNotificationType * WdgNotification;
    const uint8 LogicalThresholdId;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__)
    Adc_ChannelLimitCheckingType ChannelLimitCheckingConfig;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__) */
} Adc_Ipw_ChannelConfig;


#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
typedef struct
{
#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
    /**< @brief Main Average enable status of group */
    const uint8 GroupAvgEnable;
    /**< @brief Main Average selection of group */
    const Adc_Sar_Ip_AvgSelectType GroupAvgSelect;
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    const uint8 GroupAvgEnableAlternate;
    /**< @brief Alternate Average selection of group */
    const Adc_Sar_Ip_AvgSelectType GroupAvgSelectAlternate;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */

    Adc_ConversionTimeType ConvTime[ADC_SAR_IP_NUM_GROUP_CHAN];
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    Adc_ConversionTimeType AlternateConvTime[ADC_SAR_IP_NUM_GROUP_CHAN];
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
} Adc_Ipw_GroupConfig;
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */

typedef struct
{
    const uint8 AdcDmaInterruptSoftware[ADC_IPW_MAX_HW_UNITS];              /**< @brief DMA or Interrupt driven */
    const Adc_HwUnitType AdcMaxHwCfg;                                     /**< @brief Number of the maximum hw units. */
    const Adc_GroupType AdcGroups[ADC_IPW_MAX_HW_UNITS];                     /**< @brief   Number of groups configured for each unit */
    const Adc_ChannelType AdcChannels[ADC_IPW_MAX_HW_UNITS];                 /**< @brief Number of channels of the hw unit x */
#if ((defined(ADC_ANY_UNIT_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
    const Adc_ChannelType ChannelLogicalId[ADC_IPW_MAX_HW_UNITS][ADC_SAR_IP_CDR_COUNT];
#endif /* ((defined(ADC_ANY_UNIT_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */
    const uint32 AdcDmaChannelLogicId[ADC_IPW_MAX_HW_UNITS];                       /**< @brief If dma driven then indicates the dma channel number for HW UNITS */
    const uint32 DmaNumSgaElement[ADC_IPW_MAX_HW_UNITS];                   /**< @brief Indicates number of Scatter/Gather Elements of each assigned Dma Channel for HW UNITS */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    const uint32 AdcCountingDmaChanLogicId[ADC_IPW_MAX_HW_UNITS];               /**< @brief If dma driven then indicates the dma linked channel number for HW UNITS in optimize DMA streaming groups multiple channels feature*/
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
    const uint8 AdcHwUnitArr[ADC_IPW_MAX_HW_UNITS];                           /**< @brief If unit x is active STD_ON/STD_OFF on current partition. Indexed by Physical Hw Index */
    const Adc_HwUnitType HwLogicalId[ADC_IPW_MAX_HW_UNITS];                   /**< Mapping between Physical Id and Logical Id */
#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON))
    const uint8 CtuLogToPhyId[ADC_IPW_CTU_MAX_HW_UNITS_CFG];                  /**< Mapping from CTU Logical Id to Physical Id */
    const uint8 CtuPhyToLogId[ADC_IPW_CTU_MAX_HW_UNITS];                      /**< Mapping from CTU Physical Id to Logical Id */
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
    const uint8 HwTriggIndex[ADC_IPW_MAX_HARDWARE_TRIGGERS];                /**< Hardware trigger sources in configuration array */
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */
} Adc_Ipw_MultiConfigType;

typedef struct
{
    const Adc_Sar_Ip_ConfigType *AdcConfigPtrArr[ADC_IPW_MAX_HW_UNITS];  /**< ADCSAR hardware configuration array */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    const Sdadc_Ip_ConfigType *SdadcConfigPtrArr[ADC_IPW_MAX_HW_UNITS];  /**< SDADC hardware configuration array */
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */

    Adc_HwUnitType AdcPhysicalIdArr[ADC_IPW_MAX_HW_UNITS];
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    const Adc_Sar_Ip_ClockConfigType * AdcAltClockConfig[ADC_IPW_MAX_HW_UNITS];
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

    const Adc_Ipw_ChannelConfig *AdcIpwChannelConfig[ADC_IPW_MAX_HW_UNITS];

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    const Bctu_Ip_ConfigType *CtuConfigTriggerMode[ADC_IPW_CTU_MAX_HW_UNITS];
    const Bctu_Ip_ConfigType *CtuConfigControlMode[ADC_IPW_CTU_MAX_HW_UNITS];
#endif /*(ADC_IPW_BCTU_AVAILABLE == STD_ON)*/

#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_BCTU_AVAILABLE == STD_ON) || (ADC_IPW_CTU_AVAILABLE == STD_ON)))
    const uint8 CtuListStartIndex[ADC_IPW_MAX_HW_UNITS]; /* Starting index in the CTU List, from which the channels from groups targeting each ADC HW Unit, can be written.
                                                        Array index is the Logical ADC HW unit. If HW unit not used on partition, should be set to invalid value. */
    const uint8 CtuListMaxNumElems[ADC_IPW_MAX_HW_UNITS]; /* Max number of CTU List elements which can be used by the ADC HW Unit
                                                        Array index is the Logical ADC HW unit. If HW unit not used on partition, should be set to invalid value. */
#endif /* ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_BCTU_AVAILABLE == STD_ON) || (ADC_IPW_CTU_AVAILABLE == STD_ON))) */

    uint8 AdcUnitSupportCtuControlMode[ADC_IPW_MAX_HW_UNITS];

    /** @brief Miscellaneous configuration parameters */
    const Adc_Ipw_MultiConfigType Mapping;
} Adc_Ipw_Config;

/*!
 * @brief Macros for watchdog registers
 *
 * These macros help decode and compose bit mask for watchdog functionality
 *
 */
#define ADC_IPW_WDG_HIGH_FLAG                                       ADC_SAR_IP_WDG_HIGH_FLAG
#define ADC_IPW_WDG_LOW_FLAG                                        ADC_SAR_IP_WDG_LOW_FLAG

#if (ADC_ENABLE_READ_RAW_DATA_API == STD_ON)
/**
* @brief           Number of ADC result registers
*/
#define ADC_IPW_RES_REG_NUM                                     (ADC_SAR_IP_CDR_COUNT)
/**
* @brief           Max channel index
*/
#define ADC_IPW_MAX_CHN_ID                                      (ADC_SAR_IP_CDR_COUNT)
#endif /* (ADC_ENABLE_READ_RAW_DATA_API == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief           Number of CTU/BCTU Instances
*/
#define ADC_IPW_NUM_CTU_INSTANCES                               (BCTU_IP_INSTANCE_COUNT)
/**
* @brief           Number of CTU/BCTU Result FIFOs
*/
#define ADC_IPW_NUM_CTU_FIFO                                    (BCTU_IP_FIFO_COUNT)
/**
* @brief           Number of CTU/BCTU LIST elements
*/
#define ADC_IPW_NUM_CTU_LIST_ELEMS                              (BCTU_LISTCHR_COUNT * 2u) /* Each LISTCHR reg contains 2 list elements */

/**
* @brief           BCTU notifications defines.
*                  These defines are inputs for Adc_CtuEnableNotification/Adc_CtuDisableNotification API
*/
#define ADC_IPW_BCTU_NOTIF_FIFO1                (BCTU_IP_NOTIF_FIFO1) /**< @brief Set when the number of valid FIFO1 entries is greater than the watermark level, Underrun or Overrun event. */
#define ADC_IPW_BCTU_NOTIF_FIFO2                (BCTU_IP_NOTIF_FIFO2) /**< @brief Set when the number of valid FIFO2 entries is greater than the watermark level, Underrun or Overrun event. */
#define ADC_IPW_BCTU_NOTIF_FIFO3                (BCTU_IP_NOTIF_FIFO3) /**< @brief Set when the number of valid FIFO3 entries is greater than the watermark level, Underrun or Overrun event. */
#define ADC_IPW_BCTU_NOTIF_DATA_ADC0            (BCTU_IP_NOTIF_ADC0)  /**< @brief Set when Data Overrun and New Data event is issued on ADC0 Result Data Register. */
#define ADC_IPW_BCTU_NOTIF_DATA_ADC1            (BCTU_IP_NOTIF_ADC1)  /**< @brief Set when Data Overrun and New Data event is issued on ADC1 Result Data Register. */
#define ADC_IPW_BCTU_NOTIF_DATA_ADC2            (BCTU_IP_NOTIF_ADC2)  /**< @brief Set when Data Overrun and New Data event is issued on ADC2 Result Data Register. */
#define ADC_IPW_BCTU_NOTIF_DATA_ADC3            (BCTU_IP_NOTIF_ADC3)  /**< @brief Set when Data Overrun and New Data event is issued on ADC3 Result Data Register. */
#define ADC_IPW_BCTU_NOTIF_LAST_CONVERSION      (BCTU_IP_NOTIF_LIST)  /**< @brief Set when the last conversion in a Conversion List is completed. */
#define ADC_IPW_BCTU_NOTIF_TRIGGER              (BCTU_IP_NOTIF_TRG)   /**< @brief Set when BCTU received a trigger request. */
#define ADC_IPW_BCTU_NOTIF_DATA_ALL             (BCTU_IP_NOTIF_ADC0 | BCTU_IP_NOTIF_ADC1 | BCTU_IP_NOTIF_ADC2 | BCTU_IP_NOTIF_ADC3)
#define ADC_IPW_BCTU_FIFO_NOTIF_ALL             (BCTU_IP_NOTIF_FIFO1 | BCTU_IP_NOTIF_FIFO2 | BCTU_IP_NOTIF_FIFO3)
#define ADC_IPW_BCTU_NOTIF_ALL                  (BCTU_IP_NOTIF_ALL)

typedef uint16 Adc_CtuTrigSrcType;                               /**< @brief ID of the Bctu Trigger Source */
typedef Bctu_Ip_ResultType Adc_CtuResultType;                   /**< @brief This structure is used for storing full information of the conversion result */
typedef Bctu_Ip_FifoResultType Adc_CtuFifoResultType;           /**< @brief This structure is used for storing full information of the conversion result from BCTU FIFO*/
typedef uint16 Adc_CtuFifoIdxType;                               /**< @brief CTU result FIFO index */
typedef uint32 Adc_CtuNotificationType;                         /**< @brief BCTU notification type. To be used with ADC_IPW_BCTU_NOTIF_ defines. */
typedef uint8 Adc_CtuListPtrType;                               /**< @brief Type used for the pointer index in the CTU/BCTU list. */
typedef Bctu_Ip_ListItemType Adc_CtuListItemType;               /**< @brief Type is used for storing channel information in Conversion List at runtime. */

#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_TYPES_H */
