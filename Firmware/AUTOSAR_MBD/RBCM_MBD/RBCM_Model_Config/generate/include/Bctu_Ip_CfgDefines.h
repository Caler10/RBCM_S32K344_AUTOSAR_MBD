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

#ifndef BCTU_IP_CFGDEFINES_H
#define BCTU_IP_CFGDEFINES_H

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
#include "S32K344_ADC.h"
#include "S32K344_BCTU.h"

#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define BCTU_IP_VENDOR_ID_CFGDEFINES                       43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES        4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES        7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES     0
#define BCTU_IP_SW_MAJOR_VERSION_CFGDEFINES                5
#define BCTU_IP_SW_MINOR_VERSION_CFGDEFINES                0
#define BCTU_IP_SW_PATCH_VERSION_CFGDEFINES                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip_CfgDefines.h file and OsIf.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION  (STD_ON)
#define BCTU_IP_DEV_ERROR_DETECT                 (STD_OFF)
#define BCTU_IP_TIMEOUT_TYPE                     (OSIF_COUNTER_DUMMY)
#define BCTU_IP_TIMEOUT_VAL                      (3000UL)
#define BCTU_IP_INSTANCE_COUNT                   (1U)
#define BCTU_IP_FIFO_COUNT                       (2U)
#define BCTU_IP_INVALID_DMA_CHANNEL_ID           (0xFFU)

/**
* @brief          Offset for ADC index when using BCTU IP
*/
#define BCTU_IP_ADC_INDEX_OFFSET_ARRAY            {0U}

#define FEATURE_BCTU_NUM_ADC                      (3U)

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
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* BCTU_IP_CFGDEFINES_H */

