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

#ifndef SDADC_IP_TYPES_H
#define SDADC_IP_TYPES_H

/**
*   @file Sdadc_Ip_Types.h
*
*   @addtogroup sd_adc_ip Sd Adc IPL
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
#include "StandardTypes.h"
#include "Sdadc_Ip_CfgDefines.h"

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
#include "DSPSS_Types.h"
#endif


/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SDADC_IP_VENDOR_ID_TYPES                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_TYPES       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_TYPES    0
#define SDADC_IP_SW_MAJOR_VERSION_TYPES               5
#define SDADC_IP_SW_MINOR_VERSION_TYPES               0
#define SDADC_IP_SW_PATCH_VERSION_TYPES               0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if SDADC_Ip_Types.h file and SDADC_Ip_CfgDefines.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_TYPES != SDADC_IP_VENDOR_ID_CFGDEFINES)
    #error "SDADC_Ip_Types.h and SDADC_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if SDADC_Ip_Types.h file and SDADC_Ip_CfgDefines.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != SDADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_TYPES != SDADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Types.h and SDADC_Ip_CfgDefines.h are different"
#endif

/* Check if SDADC_Ip_Types.h file and SDADC_Ip_CfgDefines.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_TYPES != SDADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_SW_MINOR_VERSION_TYPES != SDADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (SDADC_IP_SW_PATCH_VERSION_TYPES != SDADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of SDADC_Ip_Types.h and SDADC_Ip_CfgDefines.h are different"
#endif

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
#if (SDADC_IP_VENDOR_ID_TYPES != DSPSS_VENDOR_ID_TYPES)
    #error "SDADC_Ip_Types.h and DSPSS_Types.h have different vendor ids"
#endif

/* Check if SDADC_Ip_Types.h file and DSPSS_Types.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != DSPSS_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != DSPSS_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_TYPES != DSPSS_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Types.h and DSPSS_Types.h are different"
#endif

/* Check if SDADC_Ip_Types.h file and DSPSS_Types.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_TYPES != DSPSS_SW_MAJOR_VERSION_TYPES) || \
     (SDADC_IP_SW_MINOR_VERSION_TYPES != DSPSS_SW_MINOR_VERSION_TYPES) || \
     (SDADC_IP_SW_PATCH_VERSION_TYPES != DSPSS_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of SDADC_Ip_Types.h and DSPSS_Types.h are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if SDADC_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#ifdef FEATURE_ADC_HAS_SDADC


/*==================================================================================================
 *                                        DEFINITIONS
 ==================================================================================================*/

/*!
 * @brief Macros for status flags
 *
 * These flags map to internal hardware flags in the status flag register.
 * ORing these macros to clear multiple flags.
 *
 */
#define SDADC_IP_FLAG_DATA_FIFO_EMPTY              (SDADC_SFR_DFEF_MASK)   /*!< DATA FIFO is empty */
#define SDADC_IP_FLAG_WDG_UPPER_THRES_CROSS_OVER   (SDADC_SFR_WTHH_MASK)   /*!< Watchdog Upper Threshold is cross Over */
#define SDADC_IP_FLAG_WDG_LOWER_THRES_CROSS_OVER   (SDADC_SFR_WTHL_MASK)   /*!< Watchdog Lower Threshold is cross Over */
#define SDADC_IP_FLAG_CONVERTED_DATA_VALID         (SDADC_SFR_CDVF_MASK)   /*!< Converted Data is Valid */
#define SDADC_IP_FLAG_DATA_FIFO_OVERRUN            (SDADC_SFR_DFORF_MASK)  /*!< Data FIFO is overrun */
#define SDADC_IP_FLAG_DATA_FIFO_FULL               (SDADC_SFR_DFFF_MASK)   /*!< Data FIFO is full */

/* All status flags */
#define SDADC_IP_FLAG_STATUS_ALL                   (SDADC_IP_FLAG_DATA_FIFO_EMPTY | \
                                                    SDADC_IP_FLAG_WDG_UPPER_THRES_CROSS_OVER | \
                                                    SDADC_IP_FLAG_WDG_LOWER_THRES_CROSS_OVER | \
                                                    SDADC_IP_FLAG_CONVERTED_DATA_VALID | \
                                                    SDADC_IP_FLAG_DATA_FIFO_OVERRUN | \
                                                    SDADC_IP_FLAG_DATA_FIFO_FULL)

/* Only the request flags */
#define SDADC_IP_FLAG_STATUS_REQUEST               (SDADC_IP_FLAG_WDG_UPPER_THRES_CROSS_OVER | \
                                                    SDADC_IP_FLAG_WDG_LOWER_THRES_CROSS_OVER | \
                                                    SDADC_IP_FLAG_DATA_FIFO_OVERRUN | \
                                                    SDADC_IP_FLAG_DATA_FIFO_FULL)

/*!
 * @brief Macros for setting DMA and Interrupt request generating
 *
 * These macros are directly mapped to bits in the RSER register.
 * ORing these macros to setting DMA and Interrupt request generating of multiple events
 *
 */
#define SDADC_IP_EVENT_FIFO_FULL                   (SDADC_RSER_DFFDIRE_MASK)  /*!< Data FIFO Full Event */
#define SDADC_IP_EVENT_WDOG_CROSSOVER              (SDADC_RSER_WTHDIRE_MASK)  /*!< WDG Threshold Cross Over Event */
#define SDADC_IP_EVENT_FIFO_OVERRUN                (SDADC_RSER_DFORIE_MASK)   /*!< Data FIFO Full Event, only used to enable interrupt */


/*! @brief The position of the mode bit in the input channel enum */
#define SDADC_IP_CHANNEL_ENUM_MODE_MASK            (0x20U)
#define SDADC_IP_CHANNEL_ENUM_MODE_SHIFT           (5U)

/*! @brief The position of the common voltage bias selection bits in the input channel enum */
#define SDADC_IP_CHANNEL_ENUM_VCOMSEL_MASK         (0x18U)
#define SDADC_IP_CHANNEL_ENUM_VCOMSEL_SHIFT        (3U)

/*! @brief The position of the analog channel selection bits in the input channel enum */
#define SDADC_IP_CHANNEL_ENUM_CHAN_MASK            (0x7U)
#define SDADC_IP_CHANNEL_ENUM_CHAN_SHIFT           (0U)

/*!
 * @brief Macros for watchdog registers
 *
 * These macros help decode and compose bit mask for watchdog functionality
 *
 */
#define SDADC_IP_WDG_HIGH_FLAG                      ((uint8)1U << 1U)
#define SDADC_IP_WDG_LOW_FLAG                       ((uint8)1U << 0U)

/*! @brief The macro to decode and compose bit mask for the input channel enum
 * Enum value format:
 *    - Bit field  [5]  : Mode Selection
 *    - Bit fields [4-3]: Common Voltage Bias Selection
 *    - Bit fields [2-0]: Analog Channel Selection
 * */
#define SDADC_IP_CHAN_SELECT(mode, vcom, chan)  ( ((mode) << SDADC_IP_CHANNEL_ENUM_MODE_SHIFT) | ((vcom) << SDADC_IP_CHANNEL_ENUM_VCOMSEL_SHIFT) | (chan) )



/*! @brief These macros are used to select which input source is used for hardware-triggered conversions */
#define SDADC_IP_TRIGGER_DISABLE                   0xFFU  /*!< Trigger is disabled. The configured instance will not be triggered by any trigger source */

#define SDADC_IP_SW_0_TRIGGER                      0x00U  /*!< SDADC_IP_0 output software trigger is selected. The configured instance will be triggered by SDADC0 SW trigger output */
#define SDADC_IP_SW_1_TRIGGER                      0x01U  /*!< SDADC_IP_1 output software trigger is selected. The configured instance will be triggered by SDADC1 SW trigger output */
#define SDADC_IP_SW_2_TRIGGER                      0x02U  /*!< SDADC_IP_2 output software trigger is selected. The configured instance will be triggered by SDADC2 SW trigger output */
#define SDADC_IP_SW_3_TRIGGER                      0x03U  /*!< SDADC_IP_3 output software trigger is selected. The configured instance will be triggered by SDADC3 SW trigger output */

#define SDADC_IP_TRGMUX_28_32_36_40_TRIGGER        0x04U  /*!< TRGMUX output port 28, 32, 36, 40 trigger is selected to correspond to SDADC instance 0, 1, 2, 3.
                                                               The configured instance will be triggered by the corresponding TRGMUX output port */

#define SDADC_IP_ETPU_1_20_22_24_26_TRIGGER        0x05U  /*!< ETPU_1 channel 20, 22, 24, 26 output trigger is selected to correspond to SDADC instance 0, 1, 2, 3.
                                                               The configured instance will be triggered by the corresponding ETPU_1 channel output */

#define SDADC_IP_ETPU_1_21_23_25_27_TRIGGER        0x06U  /*!< ETPU_1 channel 21, 23, 25, 27 output trigger is selected to correspond to SDADC instance 0, 1, 2, 3.
                                                               The configured instance will be triggered by the corresponding ETPU_1 channel output */

#define SDADC_IP_ETPU_2_20_22_24_26_TRIGGER        0x07U  /*!< ETPU_2 channel 20, 22, 24, 26 output trigger is selected to correspond to SDADC instance 0, 1, 2, 3.
                                                               The configured instance will be triggered by the corresponding ETPU_2 channel output */

#define SDADC_IP_ETPU_2_21_23_25_27_TRIGGER        0x08U  /*!< ETPU_2 channel 21, 23, 25, 27 output trigger is selected to correspond to SDADC instance 0, 1, 2, 3.
                                                               The configured instance will be triggered by the corresponding ETPU_2 channel output */


/*==================================================================================================
*                              TYPEDEFS (STRUCTURES, ENUMS)
==================================================================================================*/

/*!
 * @brief SDADC status return type
 *
 * This enum is used as return type
 *
 * Implements : Sdadc_Ip_StatusType_Class
 */
typedef enum
{
    SDADC_IP_STATUS_SUCCESS    = 0x00U,    /*!< Function completed successfully */
    SDADC_IP_STATUS_ERROR      = 0x01U,    /*!< Function didn't complete successfully */
    SDADC_IP_STATUS_TIMEOUT    = 0x02U     /*!< Function timed out */
} Sdadc_Ip_StatusType;


/*!
 * @brief Programmable Decimation Rate
 *
 * This enum is used to configure the programmable Decimation Rate to select the over-sampling ratio (OSR) to be applied
 * to support different passbands with a fixed input sampling clock.
 * When external modulator is selected, the output data rate is independent of this field and is fixed to fs_ext/128
 *
 * Implements : Sdadc_Ip_DecimationRateType_Class
 */
typedef enum
{
    SDADC_IP_DECIMATION_RATE_120  = 0x00U,   /*!< OSR is 120 */
    SDADC_IP_DECIMATION_RATE_140  = 0x01U,   /*!< OSR is 140 */
    SDADC_IP_DECIMATION_RATE_160  = 0x02U,   /*!< OSR is 160 */
    SDADC_IP_DECIMATION_RATE_180  = 0x03U,   /*!< OSR is 180 */
    SDADC_IP_DECIMATION_RATE_200  = 0x04U,   /*!< OSR is 200 */
    SDADC_IP_DECIMATION_RATE_220  = 0x05U,   /*!< OSR is 220 */
    SDADC_IP_DECIMATION_RATE_240  = 0x06U,   /*!< OSR is 240 */
    SDADC_IP_DECIMATION_RATE_280  = 0x07U,   /*!< OSR is 280 */
    SDADC_IP_DECIMATION_RATE_320  = 0x08U,   /*!< OSR is 320 */
    SDADC_IP_DECIMATION_RATE_360  = 0x09U,   /*!< OSR is 360 */
    SDADC_IP_DECIMATION_RATE_376  = 0x0AU,   /*!< OSR is 376 */
    SDADC_IP_DECIMATION_RATE_400  = 0x0BU,   /*!< OSR is 400 */
    SDADC_IP_DECIMATION_RATE_440  = 0x0CU,   /*!< OSR is 440 */
    SDADC_IP_DECIMATION_RATE_480  = 0x0DU,   /*!< OSR is 480 */
    SDADC_IP_DECIMATION_RATE_560  = 0x0EU,   /*!< OSR is 560 */
    SDADC_IP_DECIMATION_RATE_640  = 0x0FU,   /*!< OSR is 640 */
    SDADC_IP_DECIMATION_RATE_720  = 0x10U,   /*!< OSR is 720 */
    SDADC_IP_DECIMATION_RATE_800  = 0x11U,   /*!< OSR is 800 */
    SDADC_IP_DECIMATION_RATE_880  = 0x12U,   /*!< OSR is 880 */
    SDADC_IP_DECIMATION_RATE_960  = 0x13U,   /*!< OSR is 960 */
    SDADC_IP_DECIMATION_RATE_1120 = 0x14U,   /*!< OSR is 1120 */
    SDADC_IP_DECIMATION_RATE_1280 = 0x15U,   /*!< OSR is 1280 */
    SDADC_IP_DECIMATION_RATE_125  = 0x16U,   /*!< OSR is 125 (special case. CIC decimation rate is 25 and FIR is suppose to do decimation by 5) */
} Sdadc_Ip_DecimationRateType;


/*!
 * @brief Programmable Gain
 *
 * This enum is used to select the gain to be applied to the analog input stage of SDADC.
 * The effective analog input becomes the input voltage level multiplied by the gain factor.
 *
 * Implements : Sdadc_Ip_InputGainType_Class
 */
typedef enum
{
    SDADC_IP_INPUT_GAIN_1  = 0x00u,   /*!< Input gain is 1 */
    SDADC_IP_INPUT_GAIN_2  = 0x01u,   /*!< Input gain is 2 */
    SDADC_IP_INPUT_GAIN_4  = 0x02u,   /*!< Input gain is 4 */
    SDADC_IP_INPUT_GAIN_8  = 0x03u,   /*!< Input gain is 8 */
} Sdadc_Ip_InputGainType;


/*!
 * @brief Trigger Source Selection
 *
 * This enum is used to select which input is used for hardware-triggered conversions.
 *
 * Implements : Sdadc_Ip_TriggerSelectType_Class
 */
typedef uint8 Sdadc_Ip_TriggerSelectType;


/*!
 * @brief Trigger Edge Selection
 *
 * This enum is used to select the edge of input hardware trigger
 *
 * Implements : Sdadc_Ip_TriggerEdgeType_Class
 */
typedef enum
{
    SDADC_IP_TRIGGER_FALLING_EDGE    = 0x00u,   /*!< Falling edge */
    SDADC_IP_TRIGGER_RISING_EDGE     = 0x01u,   /*!< Rising edge */
    SDADC_IP_TRIGGER_BOTH_EDGE       = 0x02u    /*!< Both edges */
} Sdadc_Ip_TriggerEdgeType;

/*!
 * @brief Output data format selection
 *
 * This enum is used to control the output data in CDR.
 *
 * Implements : Sdadc_Ip_ResolutionType_Class
 */
typedef enum
{
    SDADC_IP_RESOLUTION_15    = 0x00u,   /*!< Output data is 15-bit unsigned */
    SDADC_IP_RESOLUTION_16    = 0x01u,   /*!< Output data is signed and sign extended to 16 bits */
} Sdadc_Ip_ResolutionType;


/*!
 * @brief Analog Channel Selection
 *
 * This enum is used to select analog input channel
 * 
 * Bit fields format:
 *    - Bit fields [5]  : Mode Selection (MODE)
 *    - Bit fields [4-3]: Common Voltage Bias Selection (VCOMSEL)
 *    - Bit fields [2-0]: Analog Channel Selection (ANCHSEL)
 *
 * Implements : Sdadc_Ip_ChannelType_Class
 */
typedef enum
{
    /*!< Differential input mode */
    SDADC_IP_CHAN_AN0_AN1      = SDADC_IP_CHAN_SELECT(0, 0, 0),   /*!< AN0 to INP and AN1 to INM */
    SDADC_IP_CHAN_AN2_AN3      = SDADC_IP_CHAN_SELECT(0, 0, 1),   /*!< AN2 to INP and AN3 to INM */
    SDADC_IP_CHAN_AN4_AN5      = SDADC_IP_CHAN_SELECT(0, 0, 2),   /*!< AN4 to INP and AN5 to INM */
    SDADC_IP_CHAN_AN6_AN7      = SDADC_IP_CHAN_SELECT(0, 0, 3),   /*!< AN6 to INP and AN7 to INM */
    SDADC_IP_CHAN_VCOM1_VCOM1  = SDADC_IP_CHAN_SELECT(0, 0, 4),   /*!< VCOM1_HV to both INP and INM */
    SDADC_IP_CHAN_VCOM2_VCOM2  = SDADC_IP_CHAN_SELECT(0, 0, 5),   /*!< VCOM2_HV to both INP and INM */
    SDADC_IP_CHAN_VREFP_VREFN  = SDADC_IP_CHAN_SELECT(0, 0, 6),   /*!< VREFP to INP and VREFN to INM */
    SDADC_IP_CHAN_VREFN_VREFP  = SDADC_IP_CHAN_SELECT(0, 0, 7),   /*!< VREFN to INP and VREFP to INM */

    /*!< Single-ended input mode, AN[x] is connected to INP terminal, VCOM0 is connected to INM terminal */
    SDADC_IP_CHAN_AN0_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 0),
    SDADC_IP_CHAN_AN1_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 1),
    SDADC_IP_CHAN_AN2_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 2),
    SDADC_IP_CHAN_AN3_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 3),
    SDADC_IP_CHAN_AN4_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 4),
    SDADC_IP_CHAN_AN5_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 5),
    SDADC_IP_CHAN_AN6_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 6),
    SDADC_IP_CHAN_AN7_VCOM0    = SDADC_IP_CHAN_SELECT(1, 0, 7),

    /*!< Single-ended input mode, AN[x] is connected to INP terminal, VCOM1 is connected to INM terminal */
    SDADC_IP_CHAN_AN0_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 0),
    SDADC_IP_CHAN_AN1_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 1),
    SDADC_IP_CHAN_AN2_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 2),
    SDADC_IP_CHAN_AN3_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 3),
    SDADC_IP_CHAN_AN4_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 4),
    SDADC_IP_CHAN_AN5_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 5),
    SDADC_IP_CHAN_AN6_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 6),
    SDADC_IP_CHAN_AN7_VCOM1    = SDADC_IP_CHAN_SELECT(1, 1, 7),

    /*!< Single-ended input mode, AN[x] is connected to INP terminal, VCOM2 is connected to INM terminal */
    SDADC_IP_CHAN_AN0_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 0),
    SDADC_IP_CHAN_AN1_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 1),
    SDADC_IP_CHAN_AN2_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 2),
    SDADC_IP_CHAN_AN3_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 3),
    SDADC_IP_CHAN_AN4_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 4),
    SDADC_IP_CHAN_AN5_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 5),
    SDADC_IP_CHAN_AN6_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 6),
    SDADC_IP_CHAN_AN7_VCOM2    = SDADC_IP_CHAN_SELECT(1, 2, 7),
} Sdadc_Ip_ChannelType;


/*!
 * @brief Defines the watchdog notification header
 *
 * This header is used for out of range watchdog notification callbacks
 * u8Flags will contain which WDG flag was triggered(low and/or high). These
 * are defined by SDADC_IP_WDG_LOW_FLAG and SDADC_IP_WDG_HIGH_FLAG
 *
 * Implements : Sdadc_Ip_WdgNotificationType_Class
 */
typedef void Sdadc_Ip_WdgNotificationType(const uint16 ChanIdx, const uint8 Flags);


/*!
 * @brief Defines the converter configuration
 *
 * This structure is used to configure the SDADC converter
 *
 * Implements : Sdadc_Ip_ConfigType
 */
typedef struct
{
    Sdadc_Ip_InputGainType         InputGain;            /*!< Programmable Gain */
    Sdadc_Ip_DecimationRateType    DecimaRate;           /*!< Programmable Decimation Rate */
    uint8                          OutputSetDelay;       /*!< Output Settling Delay */
    Sdadc_Ip_ResolutionType        Resolution;           /*!< Output data format */

    uint8                          CalibSkipped;         /*!< The number of first samples will be skipped to ignore the unstable results before performing actual SDADC calibration */
    uint8                          CalibAverage;         /*!< The number of consecutive calibration samples to be read to calculate the average SDADC calibration output */

    Sdadc_Ip_TriggerSelectType     TrigSelect;                 /*!< Trigger input selection */
    Sdadc_Ip_TriggerEdgeType       TrigEdge;                   /*!< Trigger edge selection, this member is not influent if trigger selection is disabled */

    uint8                          NumChannels;
    const Sdadc_Ip_ChannelType   * ChannelConfigsPtr;          /*!< Select analog input is connected to SDADC terminals.
                                                               In Wrap Around mode, this indicates the initial entry value for the first loop.
                                                               Only the first element will be used by Sdadc_Ip_Init() */

    boolean                        WrapAroundEnable;           /*!< Enable Wrap-Around mode */
    uint8                          Wraparound;                 /*!< In Wrap Around mode, this indicates the maximum value of the wraparound counter */

    boolean                        FifoEnable;                 /*!< Enable Fifo */
    boolean                        FifoOverwrite;              /*!< Fifo Over Write Enable */
    uint8                          FifoThreshold;              /*!< Fifo Threshold */

    boolean                        WdgEnable;                  /*!< Enable Wdg monitor */
    uint16                         WdgUpperThreshold;          /*!< Wdg Upper Threshold Value */
    uint16                         WdgLowerThreshold;          /*!< Wdg Lower Threshold Value */

    boolean                        StopInDebug;                /*!< Enable stopping the SDADC conversions when the chip enters debug mode */

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    const DSPSS_ThreadConfigType * DspssConfig;                /*!< Dspss configuration for processing (e.g. FIR, FFT) SDADC data (set as NULL_PTR to disable) */
#endif

    /* The callback function will be called when the interrupt event occurs */
    void (*FifoFullNotification)(void);                        /*!< Fifo full event */
    void (*FifoOverrunNotification)(void);                     /*!< Fifo overrun event */
    Sdadc_Ip_WdgNotificationType * WdgCrossOverNotification;   /*!< Wdg cross over event */
} Sdadc_Ip_ConfigType;


/*!
 * @brief Structure used to store runtime info
 *
 * This structure is used to store SDADC runtime info
 *
 * Implements : Sdadc_Ip_StateStructType_Class
 */
typedef struct
{
    const Sdadc_Ip_ConfigType     * Config;          /*!< Point to user's configuration structure (Also used to check if the driver was initialized) */
} Sdadc_Ip_StateStructType;


#endif /* FEATURE_ADC_HAS_SDADC */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SDADC_IP_TYPES_H */
