/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file    Emios_Mcl_Ip_MBDTPBcfg.c
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Data structures for the Mcl driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Mcl_Ip_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_MBDT_PBCFG_VENDOR_ID_C                     43
#define EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define EMIOS_MCL_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C              5
#define EMIOS_MCL_IP_MBDT_PBCFG_SW_MINOR_VERSION_C              0
#define EMIOS_MCL_IP_MBDT_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Emios_Mcl_Ip_MBDT_PBcfg.c file and Emios_Mcl_Ip_Cfg.h file are of the same vendor */
#if (EMIOS_MCL_IP_MBDT_PBCFG_VENDOR_ID_C != EMIOS_MCL_IP_CFG_VENDOR_ID)
    #error "Emios_Mcl_Ip_MBDT_PBcfg.c and Emios_Mcl_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Emios_Mcl_Ip_MBDT_PBcfg.c file and Emios_Mcl_Ip_Cfg.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_MBDT_PBcfg.c and Emios_Mcl_Ip_Cfg.h are different"
#endif

/* Check if Emios_Mcl_Ip_MBDT_PBcfg.c file and Emios_Mcl_Ip_Cfg.h file are of the same Software version */
#if ((EMIOS_MCL_IP_MBDT_PBCFG_SW_MAJOR_VERSION_C != EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_MBDT_PBCFG_SW_MINOR_VERSION_C != EMIOS_MCL_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_MBDT_PBCFG_SW_PATCH_VERSION_C != EMIOS_MCL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Emios_Mcl_Ip_MBDT_PBcfg.c and Emios_Mcl_Ip_Cfg.h are different"
#endif


/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/**
* @brief   Configuration for EMIOS counter bus
* @details This structure should contains data about the EMIOS common
*          part configured using Mcl driver
* @implements Emios_Ip_MasterBusConfigType
*/
const Emios_Ip_MasterBusConfigType Emios_Mcl_Ip_0_MasterBusConfig_MBDT[1U] =
{
    {
        /** @brief EMIOS hardware channel used. */
        (uint8)EMIOS_CH_23,
        /** @brief Master bus mode for use. */
        EMIOS_IP_MCB_UP_COUNTER,
        /** @brief  Default period */
        (uint32) 16000U,
        /** @brief  Offset at start. */
        (uint32) 0U,
        /** @brief  Prescaler value */
        (uint8) 0U,
        /** @brief  Alternate prescaler value */
        (uint8) 0U,
        /** @brief  Channel Allow Debug Mode */
        (boolean)TRUE
    }
};

const Emios_Ip_MasterBusConfigType Emios_Mcl_Ip_1_MasterBusConfig_MBDT[1U] =
{
    {
        /** @brief EMIOS hardware channel used. */
        (uint8)EMIOS_CH_23,
        /** @brief Master bus mode for use. */
        EMIOS_IP_MCB_UP_COUNTER,
        /** @brief  Default period */
        (uint32) 16000U,
        /** @brief  Offset at start. */
        (uint32) 0U,
        /** @brief  Prescaler value */
        (uint8) 0U,
        /** @brief  Alternate prescaler value */
        (uint8) 0U,
        /** @brief  Channel Allow Debug Mode */
        (boolean)TRUE
    }
};

const Emios_Ip_MasterBusConfigType Emios_Mcl_Ip_2_MasterBusConfig_MBDT[2U] =
{
    {
        /** @brief EMIOS hardware channel used. */
        (uint8)EMIOS_CH_23,
        /** @brief Master bus mode for use. */
        EMIOS_IP_MCB_UP_COUNTER,
        /** @brief  Default period */
        (uint32) 40000U,
        /** @brief  Offset at start. */
        (uint32) 0U,
        /** @brief  Prescaler value */
        (uint8) 9U,
        /** @brief  Alternate prescaler value */
        (uint8) 9U,
        /** @brief  Channel Allow Debug Mode */
        (boolean)TRUE
    },
    {
        /** @brief EMIOS hardware channel used. */
        (uint8)EMIOS_CH_0,
        /** @brief Master bus mode for use. */
        EMIOS_IP_MCB_UP_COUNTER,
        /** @brief  Default period */
        (uint32) 65535U,
        /** @brief  Offset at start. */
        (uint32) 0U,
        /** @brief  Prescaler value */
        (uint8) 9U,
        /** @brief  Alternate prescaler value */
        (uint8) 9U,
        /** @brief  Channel Allow Debug Mode */
        (boolean)TRUE
    }
};


/**
* @brief   Configuration for EMIOS IP instance
* @details This structure should contains data about the EMIOS common
*          part configurated using Mcl driver
* @implements Emios_Ip_GlobalConfigType
*/
const Emios_Ip_GlobalConfigType Emios_Ip_0_GlobalConfig_MBDT =
{
    /** @brief  Allow Debug Mode */
    (boolean)TRUE,
    /** @brief  Clock Divider Value */
    (uint8) 0U,
    /** @brief  Enable Global Time Base */
    (boolean)TRUE
};

const Emios_Ip_GlobalConfigType Emios_Ip_1_GlobalConfig_MBDT =
{
    /** @brief  Allow Debug Mode */
    (boolean)TRUE,
    /** @brief  Clock Divider Value */
    (uint8) 0U,
    /** @brief  Enable Global Time Base */
    (boolean)TRUE
};

const Emios_Ip_GlobalConfigType Emios_Ip_2_GlobalConfig_MBDT =
{
    /** @brief  Allow Debug Mode */
    (boolean)TRUE,
    /** @brief  Clock Divider Value */
    (uint8) 159U,
    /** @brief  Enable Global Time Base */
    (boolean)TRUE
};

/** 
* @brief   Configuration for EMIOS initialization.
* @details This structure contains data about one instance of EMIOS.
*/
const Emios_Mcl_Ip_ConfigType Emios_Mcl_Ip_0_Config_MBDT =
{
    /** @brief Number of master buses used by this EMIOS IP. */
    (uint8)1,
    /** @brief EMIOS instance configuration. */
    &Emios_Ip_0_GlobalConfig_MBDT,
    /** @brief EMIOS master buses configuration. */
    &Emios_Mcl_Ip_0_MasterBusConfig_MBDT
};

const Emios_Mcl_Ip_ConfigType Emios_Mcl_Ip_1_Config_MBDT =
{
    /** @brief Number of master buses used by this EMIOS IP. */
    (uint8)1,
    /** @brief EMIOS instance configuration. */
    &Emios_Ip_1_GlobalConfig_MBDT,
    /** @brief EMIOS master buses configuration. */
    &Emios_Mcl_Ip_1_MasterBusConfig_MBDT
};

const Emios_Mcl_Ip_ConfigType Emios_Mcl_Ip_2_Config_MBDT =
{
    /** @brief Number of master buses used by this EMIOS IP. */
    (uint8)2,
    /** @brief EMIOS instance configuration. */
    &Emios_Ip_2_GlobalConfig_MBDT,
    /** @brief EMIOS master buses configuration. */
    &Emios_Mcl_Ip_2_MasterBusConfig_MBDT
};


#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

