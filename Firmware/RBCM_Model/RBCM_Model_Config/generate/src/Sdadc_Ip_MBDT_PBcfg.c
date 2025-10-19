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
#include "Sdadc_Ip_MBDT_PBcfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SDADC_IP_VENDOR_ID_MBDT_PBCFG_C                     43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C      4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C      7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C   0
#define SDADC_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C              5
#define SDADC_IP_SW_MINOR_VERSION_MBDT_PBCFG_C              0
#define SDADC_IP_SW_PATCH_VERSION_MBDT_PBCFG_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if SDADC_Ip_MBDT_PBcfg.c file and SDADC_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_MBDT_PBCFG_C != SDADC_IP_VENDOR_ID_MBDT_PBCFG)
    #error "SDADC_Ip_MBDT_PBcfg.c and SDADC_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if SDADC_Ip_MBDT_PBcfg.c file and SDADC_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != SDADC_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != SDADC_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != SDADC_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_MBDT_PBcfg.c and SDADC_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if SDADC_Ip_MBDT_PBcfg.c file and SDADC_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C != SDADC_IP_SW_MAJOR_VERSION_MBDT_PBCFG) || \
     (SDADC_IP_SW_MINOR_VERSION_MBDT_PBCFG_C != SDADC_IP_SW_MINOR_VERSION_MBDT_PBCFG) || \
     (SDADC_IP_SW_PATCH_VERSION_MBDT_PBCFG_C != SDADC_IP_SW_PATCH_VERSION_MBDT_PBCFG) \
    )
  #error "Software Version Numbers of SDADC_Ip_MBDT_PBcfg.c and SDADC_Ip_MBDT_PBcfg.h are different"
#endif
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




#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

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

