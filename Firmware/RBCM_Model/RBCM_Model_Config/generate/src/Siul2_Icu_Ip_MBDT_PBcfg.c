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
 *   @file    Siul2_Icu_Ip_MBDT_PBcfg.c
 *   @version 5.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module
 *   @details Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup siul2_icu_ip SIUL2 IPL
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
#include "Std_Types.h"
#include "Siul2_Icu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_MBDT_PBCFG_VENDOR_ID_C                       43
#define SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define SIUL2_ICU_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C                5
#define SIUL2_ICU_IP_MBDT_PBCFG_SW_MINOR_VERSION_C                0
#define SIUL2_ICU_IP_MBDT_PBCFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_MBDT_PBcfg.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_MBDT_PBCFG_VENDOR_ID_C != SIUL2_ICU_IP_TYPES_VENDOR_ID)
    #error "Siul2_Icu_Ip_MBDT_PBcfg.c and Siul2_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_MBDT_PBcfg.c and Siul2_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C != SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_MBDT_PBCFG_SW_MINOR_VERSION_C != SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_MBDT_PBCFG_SW_PATCH_VERSION_C != SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_MBDT_PBcfg.c and Siul2_Icu_Ip_Types.h are different"
#endif
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/
 
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/*
 *  @brief    PB_MBDT SIUL2 Channels Configuration
 */
const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_0_ChannelConfig_PB_MBDT[1U] =
{
    /** @brief IcuSiul2Channels_0 */
    {
        /** @brief Siul2 HW Module and Channel used by the Icu channel */
        13U,
        /** @brief Siul2 Digital Filter enable */
        (boolean)FALSE,
        /** @brief Siul2 Digital Filter value */
        0U,
        /** @brief Siul2 request type*/
        SIUL2_ICU_IRQ,
        /** @brief Siul2 Edge type*/
        SIUL2_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        /** @brief The notification functions */
        NULL_PTR,
        /** @brief Callback Param1*/
        0U
    }
};

/*
 *  @brief    PB_MBDT SIUL2 Instance Configuration
 */
const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_0_InstanceConfig_PB_MBDT = 
{
    /** @brief Interrupt Filter Clock Prescaler */
    (uint8)0U,
    /** @brief Interrupt Filter Clock Alternate Prescaler  */
    (uint8)0U
};

/*
 *  @brief    PB_MBDT Default SIUL2 IP Configuration
 */
const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_0_Config_PB_MBDT = 
{
    /** @brief Number of Siul2 channels in the Icu configuration */
    (uint8)1U,
#if (SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT == STD_ON)
    /** @brief Interrupt Pdac Slot */
    (uint8)0U,
#endif
    /** @brief The Siul2 instance configuration */
    &Siul2_Icu_Ip_0_InstanceConfig_PB_MBDT,
    /** @brief Pointer to the array of Siul2 channel configurations */
    &Siul2_Icu_Ip_0_ChannelConfig_PB_MBDT
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */
/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

