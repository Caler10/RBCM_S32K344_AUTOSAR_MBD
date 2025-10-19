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

#ifndef RTC_IP_CFG_H
#define RTC_IP_CFG_H

/**
*   @file           Rtc_Ip_Cfg.h
*
*   @addtogroup     rtc_ip Rtc IPL
*
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
/* Include all variants header files. */
#include "Rtc_Ip_MBDT_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RTC_IP_VENDOR_ID_CFG                    43
#define RTC_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define RTC_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define RTC_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define RTC_IP_SW_MAJOR_VERSION_CFG             5
#define RTC_IP_SW_MINOR_VERSION_CFG             0
#define RTC_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (RTC_IP_VENDOR_ID_CFG != RTC_IP_VENDOR_ID_MBDT_PBCFG_H)
    #error "Rtc_Ip_Cfg.h and Rtc_Ip_MBDT_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((RTC_IP_AR_RELEASE_MAJOR_VERSION_CFG != RTC_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H) || \
     (RTC_IP_AR_RELEASE_MINOR_VERSION_CFG != RTC_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H) || \
     (RTC_IP_AR_RELEASE_REVISION_VERSION_CFG != RTC_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Rtc_Ip_Cfg.h and Rtc_Ip_MBDT_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((RTC_IP_SW_MAJOR_VERSION_CFG != RTC_IP_SW_MAJOR_VERSION_MBDT_PBCFG_H) || \
     (RTC_IP_SW_MINOR_VERSION_CFG != RTC_IP_SW_MINOR_VERSION_MBDT_PBCFG_H) || \
     (RTC_IP_SW_PATCH_VERSION_CFG != RTC_IP_SW_PATCH_VERSION_MBDT_PBCFG_H) \
    )
    #error "Software Version Numbers of Rtc_Ip_Cfg.h and Rtc_Ip_MBDT_PBcfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Dev error detect switch
*/
#define RTC_IP_DEV_ERROR_DETECT (STD_ON)
/*================================================================================================*/
/**
* @brief Trigger enable API
*/
#define RTC_IP_TRIGGER_ENABLE_API   STD_ON
/*================================================================================================*/
/**
* @brief    RTC_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to `TRUE` the driver code can be executed from both supervisor and user mode.
*/
#define RTC_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef RTC_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == RTC_IP_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == RTC_IP_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT*/
/*================================================================================================*/
/**
* @brief    RTC_IP_STANDBY_WAKEUP_SUPPORT
* @details  StandBy Mode is not supported in this release
*/
#define RTC_IP_STANDBY_WAKEUP_SUPPORT    (STD_OFF)
/*================================================================================================*/
/**
* @brief        RTC_IP_TICKS_PER_SECONDS define
* @details      This define contains the ticks number per seconds based on which clock source is configured; Used just in Non-Autosar Context
*/
#define RTC_IP_TICKS_PER_SECOND            0UL
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
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
#endif  /* RTC_IP_CFG_H */

