/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Stm_Pit_Rtc_Emios
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

#ifndef STM_IP_TRUSTEDFUNCTIONS_H
#define STM_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Stm_Ip_TrustedFunctions.h
*
*   @addtogroup stm_ip Stm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Stm_Ip_Cfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_TRUSTEDFUNCTIONS_VENDOR_ID                           43
#define STM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION            4
#define STM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION            7
#define STM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION         0
#define STM_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                    5
#define STM_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                    0
#define STM_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (STM_IP_TRUSTEDFUNCTIONS_VENDOR_ID != STM_IP_VENDOR_ID_CFG)
    #error "Stm_Ip_TrustedFunctions.h and Stm_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((STM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != STM_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (STM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != STM_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (STM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != STM_IP_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Stm_Ip_TrustedFunctions.h and Stm_Ip_Cfg.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((STM_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != STM_IP_SW_MAJOR_VERSION_CFG) || \
     (STM_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != STM_IP_SW_MINOR_VERSION_CFG) || \
     (STM_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != STM_IP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Stm_Ip_TrustedFunctions.h and Stm_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief      Stm_Ip_SetUserAccessAllowed
 * @details    This function is called externally by OS Application
 * @param[in]  StmBaseAddr - The base address of Stm.
 */
#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
extern void Stm_Ip_SetUserAccessAllowed(uint32 StmBaseAddr);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* STM_IP_TRUSTEDFUNCTIONS_H */
