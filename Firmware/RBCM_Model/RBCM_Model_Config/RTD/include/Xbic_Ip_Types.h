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

#ifndef XBIC_IP_TYPES_H
#define XBIC_IP_TYPES_H

/**
*   @file Xbic_Ip_Types.h
*
*   @addtogroup XBIC_IP XBIC IPV Driver
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
#include "Xbic_Ip_Cfg_Defines.h"
/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define RM_XBIC_IP_TYPES_VENDOR_ID                        43
#define RM_XBIC_IP_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define RM_XBIC_IP_TYPES_AR_RELEASE_MINOR_VERSION         7
#define RM_XBIC_IP_TYPES_AR_RELEASE_REVISION_VERSION      0
#define RM_XBIC_IP_TYPES_SW_MAJOR_VERSION                 5
#define RM_XBIC_IP_TYPES_SW_MINOR_VERSION                 0
#define RM_XBIC_IP_TYPES_SW_PATCH_VERSION                 0

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_XBIC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_XBIC_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Xbic_Ip_Types.h and Mcal.h are different"
    #endif
#endif
/* Checks against Xbic_Ip_Cfg_Defines.h */
#if (RM_XBIC_IP_TYPES_VENDOR_ID != RM_XBIC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Xbic_Ip_Types.h and Xbic_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip_Types.h and Xbic_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_XBIC_IP_TYPES_SW_MAJOR_VERSION != RM_XBIC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_TYPES_SW_MINOR_VERSION != RM_XBIC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_TYPES_SW_PATCH_VERSION != RM_XBIC_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip_Types.h and Xbic_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         Structure for error informations of Xbic Ip
*/
typedef struct
{
    boolean bErrorStatusValid;             /*!< No Error /Error detected—all fields of the ESR and EAR registers are valid */
    boolean aDataPhaseSlavePortError[XBIC_IP_NUM_SLAVE];   /*!< Feedback integrity error detected on slave*/
    boolean aDataPhaseMasterPortError[XBIC_IP_NUM_MASTER]; /*!< Feedback integrity error detected on master */
    uint8 masterID;                      /*!< The logical master ID number of the bus master which requested the most recent transfer with an attribute integrity check error detected. */
    uint8 slavePort;                     /*!< Slave port targeted by the most recent transfer with an attribute integrity check error detected. */
    uint8 synError;                      /*!< Indicate which syndrome calculated for the most recent transfer with an attribute integrity check error detected */
    uint32 errAddressDetect;              /*!< Indicate which address of the most recent transfer with an attribute integrity check error detected. */
} Xbic_Ip_ErrorStatusType;

/**
* @brief          Configuration structure for Xbic Ip
*/
typedef struct
{
    uint32 u32XbicTurnCheckOnPerPort[XBIC_IP_INSTANCE_COUNT];     /*!< This will be write on XBIC Module Control Register(MCR):to turn attribute integrity checking and feedback integrity checking on or off on a per-port basis*/
} Xbic_Ip_ConfigType;

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

#endif /* XBIC_IP_TYPES_H */
