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

#ifndef ADC_CFGDEFINES_H
#define ADC_CFGDEFINES_H

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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_CFGDEFINES                      43
#define ADC_AR_RELEASE_MAJOR_VERSION_CFGDEFINES       4
#define ADC_AR_RELEASE_MINOR_VERSION_CFGDEFINES       7
#define ADC_AR_RELEASE_REVISION_VERSION_CFGDEFINES    0
#define ADC_SW_MAJOR_VERSION_CFGDEFINES               5
#define ADC_SW_MINOR_VERSION_CFGDEFINES               0
#define ADC_SW_PATCH_VERSION_CFGDEFINES               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Enables or disables Multipartition feature in the ADC driver ((STD_ON)/(STD_OFF)).
*/
#define ADC_MULTIPARTITION_SUPPORT               (STD_OFF)

/**
* @brief          Number of configured partitions.
*/
#define ADC_MAX_PARTITIONS                  (1U)

/**
* @brief          Averaging functionality is supported
*/
#define ADC_AVERAGING_FUNCTIONALITY_SUPPORT

/**
* @brief           Adds/removes ((STD_ON)/(STD_OFF)) the services Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() from the code.
*/
#define ADC_HW_TRIGGER_API                  (STD_OFF)

/**
* @brief           AdcSetHwUnitPowerMode api enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define ADC_SET_HW_UNIT_POWER_MODE_API                    (STD_ON)

/**
* @brief           Enables or disables limit checking feature in the ADC driver.
*/
#define ADC_ENABLE_LIMIT_CHECK              (STD_ON)

/**
* @brief           Group notification mechanism is/is not ((STD_ON)/(STD_OFF)) available at runtime.
*/
#define ADC_GRP_NOTIF_CAPABILITY            (STD_ON)

/**
* @brief           Type of prioritization mechanism ADC_PRIORITY_HW, ADC_PRIORITY_HW_SW and ADC_PRIORITY_NONE.
*/
/* SWS_Adc_00522 */
#define ADC_PRIORITY_HW                     (0U)
#define ADC_PRIORITY_HW_SW                  (1U)
#define ADC_PRIORITY_NONE                   (2U)

/**
* @brief           Priority implementation.
*/
#define ADC_PRIORITY_IMPLEMENTATION         (ADC_PRIORITY_NONE)

/**
* @brief           Type of alignment mechanism ADC_ALIGN_RIGHT, ADC_ALIGN_LEFT.
*/
/* SWS_Adc_00525 */
#define ADC_ALIGN_RIGHT                     (0U)
#define ADC_ALIGN_LEFT                      (1U)

/**
* @brief           Result Alignment.
*/
#define ADC_RESULT_ALIGNMENT                (ADC_ALIGN_RIGHT)

/**
* @brief         This is a timeout value which is used to wait until
*                  - the conversion is not aborted.
*                  - ADC hardware is not entered in power down state.
*                  - ADC hardware is not entered in idle state.
*/
#define ADC_TIMEOUT_COUNTER                 (3000UL)

/**
* @brief           Specifies for reducing the number of interrupts for streaming groups
*/
#define ADC_OPTIMIZE_DMA_STREAMING_GROUPS         (STD_OFF)

/**
* @brief           Specifies to optimize conversions for hw triggered, one shot group.
*/
#define ADC_OPTIMIZE_ONESHOT_HW_TRIGGER     (STD_OFF)

/**
* @brief           Specifies to configure BCTU/CTU list at initialization for ctu hardware trigger mode groups.
*/
#define ADC_CTU_HW_TRIGGER_OPTIMIZATION     (STD_OFF)




/**
* @brief           Active DMA transfer notification.
*/

/**
 * @brief   Define the number of maximum hardware unit configured
 */
#define ADC_MAX_HW_UNITS_CFG                ADC_IPW_MAX_HW_UNITS_CFG

/**
* @brief           Adc transfer type.
*/
#ifdef ADC_DMA_SUPPORTED
#define ADC_DMA                             (0U)
#endif /* ADC_DMA_SUPPORTED */
#define ADC_INTERRUPT                       (1U)

/**
* @brief           Add/Remove Autosar Extension Adc_EnableChannel() and Adc_DisableChannel() api.
*/
#define ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API      (STD_ON)

/**
* @brief           Get injected conversion status api enabled/disabled (STD_ON/STD_OFF).
*/
#define ADC_GET_INJECTED_CONVERSION_STATUS_API    (STD_OFF)

/**
* @brief          Add/Remove Autosar Extension Adc_SetClockMode().
*/
#define ADC_DUAL_CLOCK_MODE                       (STD_OFF)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_Calibration() from the code.
*/
#define ADC_CALIBRATION                           (STD_ON)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_ApplyCalibration() from the code.
*/
#define ADC_APPLY_CALIBRATION                     (STD_OFF)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_SetChannel() from the code.
*/
#define ADC_SETCHANNEL_API                        (STD_OFF)

/**
* @brief          Extra group notification mechanism is/is not ((STD_ON)/(STD_OFF)) available at runtime.
*/
#define ADC_ENABLE_INITIAL_NOTIFICATION           (STD_OFF)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_SelfTest() from the code.
*/
#define ADC_SELF_TEST                             (STD_OFF)

/**
* @brief           ADC Configure Threshold enabled/disabled (STD_ON/STD_OFF).
*/
#define ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API    (STD_ON)

/**
* @brief           Switch to enable/disable the API for the CPR_RTD_00056, CPR_RTD_00057, CPR_RTD_00058, CPR_RTD_00059 and CPR_RTD_00060.
*/
#define ADC_CTU_CONTROL_MODE_EXTRA_APIS           (STD_OFF)

/**
* @brief           This switch is used to enable the hardware trigger Autosar Extension API for the CPR_RTD_00037, CPR_RTD_00038, CPR_RTD_00039, CPR_RTD_00040, CPR_RTD_00041.
*/
#define ADC_ENABLE_CTUTRIG_NONAUTO_API            (STD_OFF)

/**
* @brief           Switch to enable/disable the API for the CPR-MCAL-726, CPR-MCAL-727, CPR-MCAL-728.
*/
#define ADC_ENABLE_CTU_CONTROL_MODE_API           (STD_ON)

/**
* @brief           Switch to enable/disable the API for Tempsense.
*/
#define ADC_ENABLE_TEMPSENSE_API                  (STD_OFF)
#define ADC_POWER_ON_TEMPSENSE                    (STD_OFF)

/**
* @brief           Enable the read of raw data API (CPR_RTD_00508).
*/
#define ADC_ENABLE_READ_RAW_DATA_API              (STD_OFF)

/**
* @brief           Enable Group Streaming Result as multiple set.
*/
#define ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER (STD_OFF)

/**
* @brief           WDG functionality activated.
*/
#define ADC_WDG_SUPPORTED                         ADC_SAR_IP_WDG_ENABLED

/**
* @brief IRQ definition
*/
#define ADC_UNIT_0_ISR_USED
#define ADC_UNIT_1_ISR_USED
#define ADC_UNIT_2_ISR_USED
/* This macro will be defined if there is at least an interrupt for ADC instance */
#define ADC_ANY_UNIT_ISR_USED


/**
* @brief End Of Chain Notification
*/
#define ADC_UNIT_0_NORMAL_ISR_USED
#define ADC_UNIT_1_NORMAL_ISR_USED
#define ADC_UNIT_2_NORMAL_ISR_USED

/* This macro will be defined for ISR of normal conversion if there is at least one ADC instance having ADC_CONV_TYPE_NORMAL group */
#define ADC_ANY_UNIT_NORMAL_ISR_USED


/**
* @brief Fifo full Notification
*/


/**
* @brief           max queue depth configured across all configset.
*/
#define ADC_QUEUE_MAX_DEPTH_MAX             (1U)

/**
* @brief           max number of groups configured across all configset.
*/
#define ADC_MAX_GROUPS                      (6U)

/**
* @brief           Invalid Hardware group ID to determine there is no ongoing hardware group
*/
#define ADC_INVALID_HW_GROUP_ID             (0xFFFFU)

#if defined(ADC_DMA_SUPPORTED) || (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief           Maximum number of channels across all hardware units.
*/
#define ADC_MAX_CHANNEL_PER_HW_UNIT         (6U)
#endif /* defined(ADC_DMA_SUPPORTED) || ...  */

/**
* @brief           Software injected conversion use
*/
#define ADC_SOFTWARE_INJECTED_CONVERSIONS_USED    (STD_OFF)

/**
* @brief           Hardware normal conversion use
*/
#define ADC_HARDWARE_NORMAL_CONVERSIONS_USED      (STD_OFF)

/**
* @brief          Enable/Disable Adc External Trigger
*/
#define ADC_EXTERNAL_TRIGGER_ENABLE               (STD_OFF)


/**
* @brief          Configuration Precompile variant.
* @details        Configuration Precompile variant.
*/
#define ADC_PRECOMPILE_SUPPORT                    (STD_OFF)

/**
* @brief          Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define ADC_DEV_ERROR_DETECT                      (STD_ON)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_GetVersionInfo() from the code.
*/
#define ADC_VERSION_INFO_API                      (STD_ON)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_DeInit() from the code.
*/
#define ADC_DEINIT_API                            (STD_ON)

/**
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the services Adc_StartGroupConversion()and Adc_StopGroupConversion() from the code.
*/
#define ADC_ENABLE_START_STOP_GROUP_API           (STD_ON)

/**
* @brief          Add/Remove the services Adc_ReadGroup() from the code.
*/
#define ADC_READ_GROUP_API                        (STD_ON)

/**
* @brief          Add/Remove One time setting of Conversion time registers from Init() function.
*/
#define ADC_SET_ADC_CONV_TIME_ONCE                (STD_OFF)

/**
* @brief   Switch to enable that power state mode is supported
*
*/
#define ADC_POWER_STATE_SUPPORTED                 (STD_OFF)

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief   Enable/Disable the asynchronous power mode
*
*/
#define ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED     (STD_OFF)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/**
* @brief           This switch is used to enable the queue.
*/
#define ADC_ENABLE_QUEUING                        (STD_ON)

/**
* @brief           This switch is used to enable the Autosar Extension ADC performance optimization feature.
*/
#define ADC_BYPASS_ABORT_CHAIN_CHECK              (STD_OFF)
/**
* @brief           Max number of groups supports the individual group channel enable or disable support.
*/
#define ADC_NO_OF_ENABLE_CH_DISABLE_CH_GROUPS     (1U)

/**
* @brief           Symbolic names of ADC Hardware units.
* @details         Values generated are the ADC Logical Unit ID selected from configurator.
*                  These defines are recommended to be used with any ADC driver API that takes as input parameter Adc Unit.
*/
#define AdcHwUnit_0                               (0U)
#define AdcHwUnit_1                               (1U)
#define AdcHwUnit_2                               (2U)

/**
* @brief           Symbolic names of CTU Hardware units.
* @details         Values generated are the CTU Logical Unit ID selected from configurator.
*                  These defines are recommended to be used with any CTU driver API that takes as input parameter Adc Unit.
*/
#define BctuHwUnit_0                               (0U)

/**
* @brief          Adc channel id.
*/
#define ADC_ID_CHANNEL_U8(Id)                     (Id)

/**
* @brief          macros to simplify access to structures.
* @details        Streaming number of samples
*/
#define ADC_STREAMING_NUM_SAMPLES(num)            (num)

/**
* @brief          Adc group priority.
*/
#define ADC_GROUP_PRIORITY(Priority)              (Priority)

/**
* @brief           AUTOSAR Symbolic names of channels on all HW units with encoded value.
* @details         Bit fields [12-15]:  HW unit logical id
*                  Bit fields [0-11]:   Logical id of channel in HW unit (used in Adc_EnableChannel()/Adc_DisableChannel()/Adc_EnableWdgNotification()/Adc_DisableWdgNotification())
*/
#define lpHSD1_IS_PTB1                       (0x0U)
#define lpHSD2_IS_PTB0                       (0x1U)
#define lpHSD5_IS_PTD3                       (0x2U)
#define hpHSD2_IS_PTD20                       (0x3U)
#define hpHSD4_IS_PTE16                       (0x4U)
#define hpHSD5_IS_PTD0                       (0x5U)
#define ADC_POT_0                       (0x1000U)
#define lpHSD4_IS_PTD28                       (0x1001U)
#define hpHSD6_IS_PTE1                       (0x1002U)
#define lpHSD3_IS_PTD31                       (0x2000U)
#define hpHSD1_IS_PTD22                       (0x2001U)
#define hpHSD3_IS_PTE5                       (0x2002U)
#define Vbat_Monitor_PTC23                       (0x2003U)
#define Ibat_Monitor_PTE24                       (0x2004U)

/**
* @brief           Symbolic names of threshold control register with encoded value.
* @details         Bit fields [12-15]:  The ADC Logical Unit Id
*                  Bit fields [0-11]:   Logical id of threshold control in HW unit (used in Adc_ConfigureThreshold())
*/

/**
* @brief          Definitions used for extracting the ADC Logical Unit Id and logical id of channels in each unit from equivalent channel symbolic name
*/
#if (defined(ADC_WDG_SUPPORTED) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON))
#define ADC_CHANNEL_SYMBOLIC_NAME_MASK_CHANNEL_ID_U16           (0xFFFU)
#endif /* (defined(ADC_WDG_SUPPORTED) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)) */
#if (defined(ADC_WDG_SUPPORTED) || (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON))
#define ADC_CHANNEL_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16          (12U)
#endif /* (defined(ADC_WDG_SUPPORTED) || (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)) */

/**
* @brief          Definitions used for extracting the ADC Logical Unit Id and threshold controls in each unit from equivalent threshold control symbolic name
*/
#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
#define ADC_THRESHOLD_SYMBOLIC_NAME_MASK_THRESHOLD_ID_U16       ADC_CHANNEL_SYMBOLIC_NAME_MASK_CHANNEL_ID_U16
#define ADC_THRESHOLD_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16        ADC_CHANNEL_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16
#endif /* (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

/**
* @brief           Symbolic names of CTU trigger control index with encoded value.
* @details         Bit fields [15-8]: The CTU Logical Unit Id
*                  Bit fields [7-0]: Trigger Control index in CTU unit.
*/
#define BctuHwUnit_0_BctuInternalTrigger_0             (0x0U)
#define BctuHwUnit_0_BctuInternalTrigger_1             (0x1U)
#define BctuHwUnit_0_BctuInternalTrigger_2             (0x18U)

/**
* @brief           Symbolic names of FIFO index with encoded value.
* @details         Bit fields [15-8]: The CTU Logical Unit Id
*                  Bit fields [7-0]: FIFO index in CTU unit.
*/
#define BctuHwUnit_0_BctuResultFifos_0           (0x0U)
#define BctuHwUnit_0_BctuResultFifos_1           (0x1U)


/**
* @brief           Symbolic names of groups.
*/

#define Adc0Group_0                                (0U)
#define Adc1Group_0                                (1U)
#define Adc2Group_0                                (2U)
#define Adc0Group_1                                (3U)
#define Adc1Group_1                                (4U)
#define Adc2Group_1                                (5U)

/**
* @brief           Symbolic names of groups - ecuc 2108 compliant.
*/

#define AdcConf_AdcGroup_Adc0Group_0               (0U)
#define AdcConf_AdcGroup_Adc1Group_0               (1U)
#define AdcConf_AdcGroup_Adc2Group_0               (2U)
#define AdcConf_AdcGroup_Adc0Group_1               (3U)
#define AdcConf_AdcGroup_Adc1Group_1               (4U)
#define AdcConf_AdcGroup_Adc2Group_1               (5U)

/**
* @brief           Adc Autosar Extension Enable/Disable invalid group index.
*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
#define ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX   ((Adc_GroupType)0xFFFF)
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

/**
* @brief          Hardware trigger sources configured.
*
*/
#define AdcHwTrigger_0                            (0U) /* BCTU_EMIOS_0_0 */
#define AdcHwTrigger_1                            (1U) /* BCTU_EMIOS_0_1 */
#define AdcHwTrigger_2                            (24U) /* BCTU_EMIOS_1_0 */


/**
* @brief          ADC Global Validation.
*/
#define ADC_VALIDATE_GLOBAL_CALL         (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_CALL_AND_GROUP      (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_CALL_AND_UNIT       (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_PARAMS              (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_NOTIFY_CAPABILITY   (ADC_DEV_ERROR_DETECT)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_CFGDEFINES_H */
