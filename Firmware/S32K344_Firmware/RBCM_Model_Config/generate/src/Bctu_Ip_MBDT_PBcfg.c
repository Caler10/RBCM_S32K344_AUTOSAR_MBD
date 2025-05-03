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

/**
*   @file
*
*   @addtogroup bctu_ip_driver_config Bctu IPL Configuration
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
#include "Bctu_Ip_MBDT_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define BCTU_IP_VENDOR_ID_MBDT_PBCFG_C                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C    0
#define BCTU_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C               5
#define BCTU_IP_SW_MINOR_VERSION_MBDT_PBCFG_C               0
#define BCTU_IP_SW_PATCH_VERSION_MBDT_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip_MBDT_PBcfg.c file and Bctu_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_MBDT_PBCFG_C != BCTU_IP_VENDOR_ID_MBDT_PBCFG)
    #error "Bctu_Ip_MBDT_PBcfg.c and Bctu_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if Bctu_Ip_MBDT_PBcfg.c file and Bctu_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != BCTU_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_MBDT_PBcfg.c and Bctu_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if Bctu_Ip_MBDT_PBcfg.c file and Bctu_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C != BCTU_IP_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (BCTU_IP_SW_MINOR_VERSION_MBDT_PBCFG_C != BCTU_IP_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (BCTU_IP_SW_PATCH_VERSION_MBDT_PBCFG_C != BCTU_IP_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of Bctu_Ip_MBDT_PBcfg.c and Bctu_Ip_MBDT_PBcfg.h are different"
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
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

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief     Bctu Ip Internal Triggers Config for Control Mode configuration logical id 0 variant MBDT  .
*/
static const Bctu_Ip_TrigConfigType BctuIpControlModeInternalTriggers_0_MBDT[] =
{
    {
        0U, /* TrigIndex - AdcHwTrigger_0 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_ADC_DATA_REG, /* DataDest */
        (boolean)FALSE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_SINGLE, /* TrigType */
        2U, /* AdcTargetMask */
        39U /* AdcChanOrListStart - Adc channel ID, because trigger is configured in single mode */
    },
    {
        1U, /* TrigIndex - AdcHwTrigger_1 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_ADC_DATA_REG, /* DataDest */
        (boolean)FALSE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_SINGLE, /* TrigType */
        4U, /* AdcTargetMask */
        34U /* AdcChanOrListStart - Adc channel ID, because trigger is configured in single mode */
    },
    {
        24U, /* TrigIndex - AdcHwTrigger_2 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_ADC_DATA_REG, /* DataDest */
        (boolean)FALSE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_LIST, /* TrigType */
        6U, /* AdcTargetMask */
        0U /* AdcChanOrListStart - Start index in BCTU LIST, because trigger is configured in LIST mode */
    }
};

/**
* @brief     Bctu Ip Bctu List Items Config for Control Mode configuration logical id 0 variant MBDT .
*/
static const Bctu_Ip_ListItemConfigType BctuIpControlModeListItems_0_MBDT[] =
{
    { /* Command List Index: 0 - BctuListItems_0 */
        (boolean)FALSE, /* NextChanWaitOnTrig */
        34U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 1 - BctuListItems_1 */
        (boolean)FALSE, /* NextChanWaitOnTrig */
        43U, /* AdcChanIndex */
        (boolean)TRUE /* LastChanInList */
    }
};

/**
* @brief     Bctu Ip Bctu Fifos Config for Control Mode configuration logical id 0 variant MBDT .
*/
static const Bctu_Ip_FifoConfigType BctuIpResultFifos_0_MBDT[] =
{
    /* Configuration for BCTU_FIFO1 */
    {
        0U, /* FifoIndex */
        0U, /* WatermarkValue */
        (boolean)FALSE, /* FifoDmaEnable */
        0U, /* FifoDmaChannel */
        NULL_PTR, /* UserFifoBuffer */
        (boolean)FALSE, /* bEnNotif */
        NULL_PTR, /* WatermarkNotification */
        NULL_PTR, /* UnderrunNotification */
        NULL_PTR /* OverrunNotification */
    },
    /* Configuration for BCTU_FIFO2 */
    {
        1U, /* FifoIndex */
        0U, /* WatermarkValue */
        (boolean)FALSE, /* FifoDmaEnable */
        0U, /* FifoDmaChannel */
        NULL_PTR, /* UserFifoBuffer */
        (boolean)FALSE, /* bEnNotif */
        NULL_PTR, /* WatermarkNotification */
        NULL_PTR, /* UnderrunNotification */
        NULL_PTR /* OverrunNotification */
    }
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


/**
* @brief     Bctu Ip Config for Control Mode  configuration logical id 0 variant MBDT .
*/
const Bctu_Ip_ConfigType BctuIpConfigControlMode_0_MBDT =
{
    (boolean)FALSE, /* LowPowerModeEn */
    (boolean)TRUE, /* GlobalHwTriggersEn */
    0U, /* NewDataDmaEnMask */
    NULL_PTR, /* TriggerNotification */
    { { Adc0_CtuNewDataNotification, Adc0_CtuDataOverrunNotification, Adc0_CtuListLastNotification }, { Adc1_CtuNewDataNotification, Adc1_CtuDataOverrunNotification, Adc1_ListLastNotification }, { NULL_PTR, NULL_PTR, NULL_PTR } }, /* AdcNotifications */
    3U, /* NumTrigConfigs */
    BctuIpControlModeInternalTriggers_0_MBDT, /* TrigConfigs */
    2U, /* NumListItems */
    BctuIpControlModeListItems_0_MBDT, /* ListItemConfigs */
    2U, /* NumFifoConfigs */
    BctuIpResultFifos_0_MBDT /* FifoConfigs */
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

