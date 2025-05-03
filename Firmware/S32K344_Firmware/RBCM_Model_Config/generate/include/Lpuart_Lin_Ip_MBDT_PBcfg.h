/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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


#ifndef LPUART_LIN_IP_MBDT_PBCFG_H
#define LPUART_LIN_IP_MBDT_PBCFG_H

/**
*   @file
*
*   @addtogroup LPUART_LIN
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Lpuart_Lin_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_MBDT_PBCFG_VENDOR_ID                    43
#define LPUART_LIN_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define LPUART_LIN_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define LPUART_LIN_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define LPUART_LIN_IP_MBDT_PBCFG_SW_MAJOR_VERSION             5
#define LPUART_LIN_IP_MBDT_PBCFG_SW_MINOR_VERSION             0
#define LPUART_LIN_IP_MBDT_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpuart_Lin_Ip_Types.h */
#if (LPUART_LIN_IP_MBDT_PBCFG_VENDOR_ID != LPUART_LIN_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Lin_Ip_MBDT_PBcfg.h and Lpuart_Lin_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Autosar version */
#if ((LPUART_LIN_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION    != LPUART_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION    != LPUART_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lpuart_Lin_Ip_MBDT_PBcfg.h and Lpuart_Lin_Ip_Types.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Software version */
#if ((LPUART_LIN_IP_MBDT_PBCFG_SW_MAJOR_VERSION != LPUART_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_MBDT_PBCFG_SW_MINOR_VERSION != LPUART_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_MBDT_PBCFG_SW_PATCH_VERSION != LPUART_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_MBDT_PBcfg.h and Lpuart_Lin_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define LPUART_LIN_IP_CONFIG_MBDT_PB \
    extern const Lpuart_Lin_Ip_UserConfigType Lpuart_Lin_Ip_pxHwConfigPB_1_MBDT;\
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPUART_LIN_IP_MBDT_PBCFG_H */

