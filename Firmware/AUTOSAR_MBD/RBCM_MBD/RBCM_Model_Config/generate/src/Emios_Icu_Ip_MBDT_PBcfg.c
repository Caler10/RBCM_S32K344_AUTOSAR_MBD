/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
 *   @file    Emios_Icu_Ip_MBDT_PBcfg.c
 *   @version 5.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup emios_icu_ip EMIOS IPL
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
*================================================================================================*/
#include "Emios_Icu_Ip_Types.h"

#if (STD_ON == EMIOS_ICU_IP_USED)
    #if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
        #include "Dma_Ip.h"
    #endif
#endif
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_ICU_IP_MBDT_PBCFG_VENDOR_ID_C                    43
#define EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define EMIOS_ICU_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C             5
#define EMIOS_ICU_IP_MBDT_PBCFG_SW_MINOR_VERSION_C             0
#define EMIOS_ICU_IP_MBDT_PBCFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == EMIOS_ICU_IP_USED)
        #if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
            /* Check if header file and Dma_Ip.h file are of the same Autosar version */
            #if ((EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
                 (EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Emios_Icu_Ip_MBDT_PBcfg.c and Dma_Ip.h are different"
            #endif
        #endif
    #endif
#endif

#if (EMIOS_ICU_IP_MBDT_PBCFG_VENDOR_ID_C != EMIOS_ICU_IP_TYPES_VENDOR_ID)
    #error "Emios_Icu_Ip_MBDT_PBcfg.c and Emios_Icu_Ip_Types.h have different vendor ids"
#endif

/* Check if  source file and Emios_Icu_Ip_Types.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != EMIOS_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != EMIOS_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != EMIOS_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_MBDT_PBcfg.c and Emios_Icu_Ip_Types.h are different"
#endif

/* Check if source file and Emios_Icu_Ip_Types.h file are of the same Software version */
#if ((EMIOS_ICU_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C != EMIOS_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_MBDT_PBCFG_SW_MINOR_VERSION_C != EMIOS_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_MBDT_PBCFG_SW_PATCH_VERSION_C != EMIOS_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_MBDT_PBcfg.c and Emios_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
/** @brief External Notifications for Timestamp */ 
extern void MBDT_ICU_Timestamp_Callback(void);

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

/** @brief Signature of wakeup and overflow interrupt function. */
extern void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow);

/** @brief Signature of wakeup and overflow interrupt function. */
extern void Icu_LogicChStateCallback(uint16 logicChannel, uint8 mask, boolean set);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*
 *  @brief    PB_MBDT Channels Configuration 0
 */
const eMios_Icu_Ip_ChannelConfigType eMios_Icu_Ip_0_ChannelConfig_PB_MBDT[1U] =
{
    /** @brief IcueMios_0_Channel_3 */
    {
        /** @brief EMIOS hardware channel used by the ICU driver. */
        3U,
        /** @brief Channel DutyCycle measurement mode. */
        EMIOS_ICU_IPWM,
        /** @brief Emios Channel Freeze bit. */
        (boolean)FALSE,
        /** @brief Value of EMIOS channel prescaler. */
        EMIOS_PRESCALER_DIVIDE_1,
        /** @brief Value of EMIOS channel alternate prescaler. */
        EMIOS_PRESCALER_DIVIDE_1,
        /** @brief Channel Counter bus selection. */
        EMIOS_ICU_BUS_INTERNAL_COUNTER,
        /** @brief eMios IPL mode of operation */
        EMIOS_ICU_MODE_EDGE_COUNTER,
        /** @brief DMA support for timestamp measurement. */
        EMIOS_ICU_MODE_WITHOUT_DMA,
        /** @brief Measurement mode for signal measurement. */
        EMIOS_ICU_NO_MEASUREMENT,
        /** @brief Edge alignment for signal measurement. */
        EMIOS_ICU_RISING_EDGE,
        /** @brief Value of EMIOS channel digital filter. */
        EMIOS_DIGITAL_FILTER_BYPASSED,
        /** @brief Clock source for the programmable input filter. */
        (boolean)FALSE,
        /** @brief Callback function for channels. */
        &Icu_ReportWakeupAndOverflow,
        /** @brief Callback function for changing channels status */
        &Icu_LogicChStateCallback,
        /** @brief Parameters used by callback function. */
        (uint8)3U,
        /** @brief Channel perform measurements without interrupt. */
        (boolean)FALSE,
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API)
        /** @brief Timestamp buffer used. */
        EMIOS_ICU_NO_TIMESTAMP,
#endif
#if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
        /** @brief Dma channel Id. */
        255U,
#endif
        /** @brief Channel specific notification */
        NULL_PTR,
        /** @brief Channel overflow notification. */
        NULL_PTR
    }
};

/*
 *  @brief    PB_MBDT Channels Configuration 2
 */
const eMios_Icu_Ip_ChannelConfigType eMios_Icu_Ip_2_ChannelConfig_PB_MBDT[2U] =
{
    /** @brief IcueMios_2_Channel_1 */
    {
        /** @brief EMIOS hardware channel used by the ICU driver. */
        1U,
        /** @brief Channel DutyCycle measurement mode. */
        EMIOS_ICU_IPWM,
        /** @brief Emios Channel Freeze bit. */
        (boolean)FALSE,
        /** @brief Value of EMIOS channel prescaler. */
        EMIOS_PRESCALER_DIVIDE_10,
        /** @brief Value of EMIOS channel alternate prescaler. */
        EMIOS_PRESCALER_DIVIDE_10,
        /** @brief Channel Counter bus selection. */
        EMIOS_ICU_BUS_DIVERSE,
        /** @brief eMios IPL mode of operation */
        EMIOS_ICU_MODE_SIGNAL_MEASUREMENT,
        /** @brief DMA support for timestamp measurement. */
        EMIOS_ICU_MODE_WITHOUT_DMA,
        /** @brief Measurement mode for signal measurement. */
        EMIOS_ICU_DUTY_CYCLE,
        /** @brief Edge alignment for signal measurement. */
        EMIOS_ICU_RISING_EDGE,
        /** @brief Value of EMIOS channel digital filter. */
        EMIOS_DIGITAL_FILTER_BYPASSED,
        /** @brief Clock source for the programmable input filter. */
        (boolean)FALSE,
        /** @brief Callback function for channels. */
        &Icu_ReportEvents,
        /** @brief Callback function for changing channels status */
        &Icu_LogicChStateCallback,
        /** @brief Parameters used by callback function. */
        (uint8)1U,
        /** @brief Channel perform measurements without interrupt. */
        (boolean)FALSE,
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API)
        /** @brief Timestamp buffer used. */
        EMIOS_ICU_NO_TIMESTAMP,
#endif
#if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
        /** @brief Dma channel Id. */
        255U,
#endif
        /** @brief Channel specific notification */
        NULL_PTR,
        /** @brief Channel overflow notification. */
        NULL_PTR
    },
    /** @brief IcueMios_2_Channel_2 */
    {
        /** @brief EMIOS hardware channel used by the ICU driver. */
        2U,
        /** @brief Channel DutyCycle measurement mode. */
        EMIOS_ICU_IPWM,
        /** @brief Emios Channel Freeze bit. */
        (boolean)FALSE,
        /** @brief Value of EMIOS channel prescaler. */
        EMIOS_PRESCALER_DIVIDE_10,
        /** @brief Value of EMIOS channel alternate prescaler. */
        EMIOS_PRESCALER_DIVIDE_10,
        /** @brief Channel Counter bus selection. */
        EMIOS_ICU_BUS_DIVERSE,
        /** @brief eMios IPL mode of operation */
        EMIOS_ICU_MODE_TIMESTAMP,
        /** @brief DMA support for timestamp measurement. */
        EMIOS_ICU_MODE_WITHOUT_DMA,
        /** @brief Measurement mode for signal measurement. */
        EMIOS_ICU_NO_MEASUREMENT,
        /** @brief Edge alignment for signal measurement. */
        EMIOS_ICU_RISING_EDGE,
        /** @brief Value of EMIOS channel digital filter. */
        EMIOS_DIGITAL_FILTER_BYPASSED,
        /** @brief Clock source for the programmable input filter. */
        (boolean)FALSE,
        /** @brief Callback function for channels. */
        &Icu_ReportEvents,
        /** @brief Callback function for changing channels status */
        &Icu_LogicChStateCallback,
        /** @brief Parameters used by callback function. */
        (uint8)2U,
        /** @brief Channel perform measurements without interrupt. */
        (boolean)FALSE,
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API)
        /** @brief Timestamp buffer used. */
        EMIOS_ICU_CIRCULAR_BUFFER,
#endif
#if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
        /** @brief Dma channel Id. */
        255U,
#endif
        /** @brief Channel specific notification */
        &MBDT_ICU_Timestamp_Callback,
        /** @brief Channel overflow notification. */
        NULL_PTR
    }
};

/** @brief Emios PB_MBDT instance 0 IP configuration. */
const eMios_Icu_Ip_ConfigType eMios_Icu_Ip_0_Config_PB_MBDT = 
{
    /** @brief Number of channels in the configuration */
    (uint8) 1U,
    /** @brief Instance Channels configuration */
    &eMios_Icu_Ip_0_ChannelConfig_PB_MBDT
};

/** @brief Emios PB_MBDT instance 2 IP configuration. */
const eMios_Icu_Ip_ConfigType eMios_Icu_Ip_2_Config_PB_MBDT = 
{
    /** @brief Number of channels in the configuration */
    (uint8) 2U,
    /** @brief Instance Channels configuration */
    &eMios_Icu_Ip_2_ChannelConfig_PB_MBDT
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

