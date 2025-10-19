/*==================================================================================================
* Project :             RTD AUTOSAR 4.7
* Platform :            CORTEXM
* Peripheral :          Stm_Pit_Rtc_Emios
* Dependencies :        none
*
* Autosar Version :     4.7.0
* Autosar Revision :    ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version :          5.0.0
* Build Version :       S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
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
/**
 *   @file        Emios_Gpt_Ip_PBcfg.c
 *
 *   @addtogroup  emios_ip Emios IPL
 *
 *   @{
 */

/*==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Emios_Gpt_Ip_MBDT_PBcfg.h"
#include "Gpt_Irq.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_GPT_IP_VENDOR_ID_MBDT_PBCFG_C                    43
#define EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C     4
#define EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C     7
#define EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C  0
#define EMIOS_GPT_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C             5
#define EMIOS_GPT_IP_SW_MINOR_VERSION_MBDT_PBCFG_C             0
#define EMIOS_GPT_IP_SW_PATCH_VERSION_MBDT_PBCFG_C             0
/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
 /* TBD */
/*================================================================================================*/
#if (EMIOS_GPT_IP_VENDOR_ID_MBDT_PBCFG_C != EMIOS_GPT_IP_VENDOR_ID_MBDT_PBCFG_H)
    #error "Emios_Gpt_Ip_MBDT_PBcfg.c and Emios_Gpt_Ip_MBDT_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H) || \
     (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H) || \
     (EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Emios_Gpt_Ip_MBDT_PBcfg.c and Emios_Gpt_Ip_MBDT_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((EMIOS_GPT_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C != EMIOS_GPT_IP_SW_MAJOR_VERSION_MBDT_PBCFG_H) || \
     (EMIOS_GPT_IP_SW_MINOR_VERSION_MBDT_PBCFG_C != EMIOS_GPT_IP_SW_MINOR_VERSION_MBDT_PBCFG_H) || \
     (EMIOS_GPT_IP_SW_PATCH_VERSION_MBDT_PBCFG_C != EMIOS_GPT_IP_SW_PATCH_VERSION_MBDT_PBCFG_H) \
    )
    #error "Software Version Numbers of Emios_Gpt_Ip_MBDT_PBcfg.c and Emios_Gpt_Ip_MBDT_PBcfg.h are different"
#endif
#if (EMIOS_GPT_IP_VENDOR_ID_MBDT_PBCFG_C != GPT_IRQ_VENDOR_ID)
    #error "Emios_Gpt_Ip_MBDT_PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Emios_Gpt_Ip_MBDT_PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((EMIOS_GPT_IP_SW_MAJOR_VERSION_MBDT_PBCFG_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_GPT_IP_SW_MINOR_VERSION_MBDT_PBCFG_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_GPT_IP_SW_PATCH_VERSION_MBDT_PBCFG_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Emios_Gpt_Ip_MBDT_PBcfg.c and Gpt_Irq.h are different"
#endif

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

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
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

#ifdef __cplusplus
}
#endif  /*EMIOS_GPT_IP_PBCFG_C*/
/** @} */
