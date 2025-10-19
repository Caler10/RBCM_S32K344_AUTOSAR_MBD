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

#ifndef SIUL2_ICU_IP_TRUSTEDFUNCTIONS_H
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_H

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Siul2_Icu_Ip_Defines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             5
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_VENDOR_ID != SIUL2_ICU_IP_DEFINES_VENDOR_ID)
    #error "Siul2_Icu_Ip_TrustedFunctions.h and Siul2_Icu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_TrustedFunctions.h and Siul2_Icu_Ip_Defines.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_TrustedFunctions.h and Siul2_Icu_Ip_Defines.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Siul2_Icu_SetUserAccessAllowed
 * @details    This function is called externally by OS Application
 * @param[in]  siul2BaseAddr - The base address of Siul2 module.
 */
#if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
    extern void Siul2_Icu_SetUserAccessAllowed(uint32 siul2BaseAddr);
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_TRUSTEDFUNCTIONS_H */

