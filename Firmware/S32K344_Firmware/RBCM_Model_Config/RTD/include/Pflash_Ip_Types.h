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

#ifndef PFLASH_IP_TYPES_H
#define PFLASH_IP_TYPES_H

/**
*   @file Pflash_Ip_Types.h
*
*   @addtogroup Pflash_Ip Pflash IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Mcal.h"
#include "Pflash_Ip_Cfg_Defines.h"

/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define RM_PFLASH_IP_TYPES_VENDOR_ID                      43
#define RM_PFLASH_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define RM_PFLASH_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define RM_PFLASH_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define RM_PFLASH_IP_TYPES_SW_MAJOR_VERSION               5
#define RM_PFLASH_IP_TYPES_SW_MINOR_VERSION               0
#define RM_PFLASH_IP_TYPES_SW_PATCH_VERSION               0

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_PFLASH_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_PFLASH_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Pflash_Ip_Types.h and Mcal.h are different"
    #endif
#endif

/* Checks against Pflash_Ip_Cfg_Defines.h */
#if (RM_PFLASH_IP_TYPES_VENDOR_ID != RM_PFLASH_IP_CFG_DEFINES_VENDOR_ID)
    #error "Pflash_Ip_Types.h and Pflash_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_PFLASH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_PFLASH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_PFLASH_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Pflash_Ip_Types.h and Pflash_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_PFLASH_IP_TYPES_SW_MAJOR_VERSION != RM_PFLASH_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_PFLASH_IP_TYPES_SW_MINOR_VERSION != RM_PFLASH_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_PFLASH_IP_TYPES_SW_PATCH_VERSION != RM_PFLASH_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pflash_Ip_Types.h and Pflash_Ip_Cfg_Defines.h are different"
#endif
/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/**
* @brief          Enumeration listing Pflash access type
*/
typedef enum
{
    PFLASH_READ_NOT_ALLOWED = 0,
    PFLASH_READ_ALLOWED = 1
} Pflash_Ip_MasterAccessType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Structure containing the configuration of the Pflash Ip
*/
typedef struct
{
#if (STD_ON == RM_IP_ENABLE_PFLASH)
    Pflash_Ip_MasterType Pflash_Master;          /*!< Pflash master access protection field */
#endif
    Pflash_Ip_MasterAccessType Pflash_Access;          /*!< Pflash access type */
} Pflash_Ip_MasterProtectionType;

/**
* @brief          Structure containing the configuration of the Pflash Ip
*/
typedef struct
{
    const uint32 u32Pflash_MasterProtectionConfigCnt;         /*!< Pflash Size of Master Protection configuration array*/
    const Pflash_Ip_MasterProtectionType *pPflash_MasterProtectionConfig;              /*!< Pflash Master Protection configuration array*/
} Pflash_Ip_ConfigType;
/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PFLASH_IP_TYPES_H */
