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

#ifndef AXBS_IP_TYPES_H
#define AXBS_IP_TYPES_H

/**
*   @file Axbs_Ip_Types.h
*
*   @addtogroup AXBS_IP AXBS IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Mcal.h"

#include "Axbs_Ip_Cfg_Defines.h"

/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define RM_AXBS_IP_TYPES_VENDOR_ID                      43
#define RM_AXBS_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define RM_AXBS_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define RM_AXBS_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define RM_AXBS_IP_TYPES_SW_MAJOR_VERSION               5
#define RM_AXBS_IP_TYPES_SW_MINOR_VERSION               0
#define RM_AXBS_IP_TYPES_SW_PATCH_VERSION               0

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_AXBS_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_AXBS_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Axbs_Ip_Types.h and Mcal.h are different"
    #endif
#endif

/* Checks against Axbs_Ip_Cfg_Defines.h */
#if (RM_AXBS_IP_TYPES_VENDOR_ID != RM_AXBS_IP_CFG_DEFINES_VENDOR_ID)
    #error "Axbs_Ip_Types.c and Axbs_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_AXBS_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Axbs_Ip_Types.c and Axbs_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_AXBS_IP_TYPES_SW_MAJOR_VERSION != RM_AXBS_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_TYPES_SW_MINOR_VERSION != RM_AXBS_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_TYPES_SW_PATCH_VERSION != RM_AXBS_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip_Types.c and Axbs_Ip_Cfg_Defines.h are different"
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
*     Axbs port number type
*/
typedef uint8 Axbs_Ip_PortNumberType;
/**
*     Axbs instance number type
*/
typedef uint32 Axbs_Ip_InstanceNumberType;
/**
*     Axbs port priority config
*/
typedef uint32 Axbs_Ip_PortPriorityType;
/**
*     Axbs port control type
*/
typedef uint32 Axbs_Ip_PortControlType;
/**
* @brief     Axbs port type
*/
typedef uint8  Axbs_Ip_CrossbarPortType;


/* Forward AXBS structure declarations */

/**
* @brief          Configuration structure for Slave ports
*/
typedef struct
{
    const Axbs_Ip_PortNumberType Axbs_PortNumber;           /*!< hardware slave port number */
    const Axbs_Ip_InstanceNumberType Axbs_InstanceNumber;   /*!< hardware instance  */
#ifdef RM_CROSSBAR_PRS_READONLY
#if (RM_CROSSBAR_PRS_READONLY == STD_OFF)
    const Axbs_Ip_PortPriorityType Axbs_PortPriorityConfig;  /*!< port priority config */
#endif
#endif
    const Axbs_Ip_PortControlType Axbs_PortControlConfig;    /*!< port control config */

} Axbs_Ip_SlavePortConfigType;


/**
* @brief          Configuration structure for Axbs Ip
*/
typedef struct
{
    const Axbs_Ip_CrossbarPortType AxbsCrossbarIpNumPorts;   /*!< The number of slave port. **/
    const Axbs_Ip_SlavePortConfigType(*const pAxbsCrossbarSlaveHwIpConfig)[];  /*!< configuration of the crossbar IP for Slave */
} Axbs_Ip_ConfigType;

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

#endif /* AXBS_IP_TYPES_H */
