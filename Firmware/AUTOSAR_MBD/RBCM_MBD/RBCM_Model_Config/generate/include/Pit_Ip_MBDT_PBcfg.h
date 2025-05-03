/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef PIT_IP_MBDT_PBCFG_H
#define PIT_IP_MBDT_PBCFG_H

/**
*   @file           Pit_Ip_MBDT_PBcfg.h
*
*   @addtogroup     pit_ip Pit IPL
*
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
#include "Pit_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */
#define PIT_IP_VENDOR_ID_MBDT_PBCFG_H                    43
#define PIT_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H     4
#define PIT_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H     7
#define PIT_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H  0
#define PIT_IP_SW_MAJOR_VERSION_MBDT_PBCFG_H             5
#define PIT_IP_SW_MINOR_VERSION_MBDT_PBCFG_H             0
#define PIT_IP_SW_PATCH_VERSION_MBDT_PBCFG_H             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PIT_IP_VENDOR_ID_MBDT_PBCFG_H != PIT_IP_TYPES_VENDOR_ID)
    #error "Pit_Ip_MBDT_PBcfg.h and Pit_Ip_Types.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((PIT_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H != PIT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PIT_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H != PIT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PIT_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H != PIT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pit_Ip_MBDT_PBcfg.h and Pit_Ip_Types.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((PIT_IP_SW_MAJOR_VERSION_MBDT_PBCFG_H != PIT_IP_TYPES_SW_MAJOR_VERSION) || \
     (PIT_IP_SW_MINOR_VERSION_MBDT_PBCFG_H != PIT_IP_TYPES_SW_MINOR_VERSION) || \
     (PIT_IP_SW_PATCH_VERSION_MBDT_PBCFG_H != PIT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pit_Ip_MBDT_PBcfg.h and Pit_Ip_Types.h are different"
#endif
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
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
extern const Pit_Ip_InstanceConfigType PIT_0_InitConfig_PB_MBDT;
extern const Pit_Ip_ChannelConfigType PIT_0_ChannelConfig_PB_MBDT[4U];
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif /* PIT_IP_MBDT_PBCFG_H */
/** @} */

#endif

