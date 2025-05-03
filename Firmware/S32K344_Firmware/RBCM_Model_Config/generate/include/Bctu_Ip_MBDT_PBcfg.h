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

#ifndef BCTU_IP_MBDT_PBCFG_H
#define BCTU_IP_MBDT_PBCFG_H

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
#include "Bctu_Ip_Types.h"
#ifdef BCTU_IP_DMA_SUPPORTED
#include "Dma_Ip.h"
#endif /* BCTU_IP_DMA_SUPPORTED */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define BCTU_IP_VENDOR_ID_MBDT_PBCFG                       43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG        4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG        7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG     0
#define BCTU_IP_SW_MAJOR_VERSION_MBDT_PBCFG                5
#define BCTU_IP_SW_MINOR_VERSION_MBDT_PBCFG                0
#define BCTU_IP_SW_PATCH_VERSION_MBDT_PBCFG                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip_MBDT_PBcfg.h file and Bctu_Ip_Types.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_MBDT_PBCFG != BCTU_IP_VENDOR_ID_TYPES)
    #error "Bctu_Ip_MBDT_PBcfg.h and Bctu_Ip_Types.h have different vendor ids"
#endif

/* Check if Bctu_Ip_MBDT_PBcfg.h file and Bctu_Ip_Types.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG != BCTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG != BCTU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG != BCTU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_MBDT_PBcfg.h and Bctu_Ip_Types.h are different"
#endif

/* Check if Bctu_Ip_MBDT_PBcfg.h file and Bctu_Ip_Types.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_MBDT_PBCFG != BCTU_IP_SW_MAJOR_VERSION_TYPES) || \
     (BCTU_IP_SW_MINOR_VERSION_MBDT_PBCFG != BCTU_IP_SW_MINOR_VERSION_TYPES) || \
     (BCTU_IP_SW_PATCH_VERSION_MBDT_PBCFG != BCTU_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Bctu_Ip_MBDT_PBcfg.h and Bctu_Ip_Types.h are different"
#endif

#ifdef BCTU_IP_DMA_SUPPORTED
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip_MBDT_PBcfg.c file and Dma_Ip.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG != DMA_IP_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_MBDT_PBcfg.c and Dma_Ip.h are different"
#endif
#endif
#endif /* BCTU_IP_DMA_SUPPORTED */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


/**
* @brief     Bctu Ip Config for Control Mode configuration logical id 0 variant MBDT .
*/
extern const Bctu_Ip_ConfigType BctuIpConfigControlMode_0_MBDT;

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"


/**
* @brief     Bctu Control Mode Notification function prototypes.
*/
void Adc0_CtuNewDataNotification(void);
void Adc0_CtuDataOverrunNotification(void);
void Adc0_CtuListLastNotification(void);
void Adc1_CtuNewDataNotification(void);
void Adc1_CtuDataOverrunNotification(void);
void Adc1_ListLastNotification(void);


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* BCTU_IP_MBDT_PBCFG_H */

