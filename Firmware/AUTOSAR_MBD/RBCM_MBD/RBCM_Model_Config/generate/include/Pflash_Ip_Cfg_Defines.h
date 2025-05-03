/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef PFLASH_IP_CFG_DEFINES_H
#define PFLASH_IP_CFG_DEFINES_H

/**
*   @file Pflash_Ip_Cfg_Defines.h
*
*   @addtogroup Pflash_Ip Pflash IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
 * Include specific header file
 */
#include "Std_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_PFLASH_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_PFLASH_IP_CFG_DEFINES_SW_MAJOR_VERSION             5
#define RM_PFLASH_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_PFLASH_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                   FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against Std_Types.h */
#if ((RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pflash_Ip_Cfg_Defines.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
 * @brief        Define MAP fields in PFAPR register
 */
#define PFLASH_M15AP                    0u
#define PFLASH_M14AP                    1u
#define PFLASH_M13AP                    2u
#define PFLASH_M12AP                    3u
#define PFLASH_M11AP                    4u
#define PFLASH_M10AP                    5u
#define PFLASH_M9AP                     6u
#define PFLASH_M8AP                     7u
#define PFLASH_M7AP                     8u
#define PFLASH_M6AP                     9u
#define PFLASH_M5AP                     10u
#define PFLASH_M4AP                     11u
#define PFLASH_M3AP                     12u
#define PFLASH_M2AP                     13u
#define PFLASH_M1AP                     14u
#define PFLASH_M0AP                     15u

/**
 * @brief        Define PFLASH Enable
 */
#define  RM_IP_ENABLE_PFLASH            (STD_OFF)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PFLASH_IP_DEVICE_REGISTERS_H */


