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

#ifndef MSCM_IP_TYPES_H
#define MSCM_IP_TYPES_H

/**
*   @file
*
*   @addtogroup Mscm_Ip Mscm IPV Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mscm_Ip_Cfg_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_TYPES_VENDOR_ID                      43
#define RM_MSCM_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define RM_MSCM_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define RM_MSCM_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define RM_MSCM_IP_TYPES_SW_MAJOR_VERSION               5
#define RM_MSCM_IP_TYPES_SW_MINOR_VERSION               0
#define RM_MSCM_IP_TYPES_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mscm_Ip_CfgDefines header file are of the same vendor */
#if (RM_MSCM_IP_TYPES_VENDOR_ID != RM_MSCM_IP_CFG_DEFINES_VENDOR_ID)
    #error "Mscm_Ip_Types.h and Mscm_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Fls header file are of the same Software version */
#if ((RM_MSCM_IP_TYPES_SW_MAJOR_VERSION != RM_MSCM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_TYPES_SW_MINOR_VERSION != RM_MSCM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_TYPES_SW_PATCH_VERSION != RM_MSCM_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip_Types.h and Mscm_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef IRQn_Type Mscm_IRQn_Type;
/**
* @brief          Structure storing the configuration for interrupt Router.
*/
typedef struct
{
    /** @brief Interrupt number */
    uint16 u16IrqNumber;
    /** @brief Target cores for the interrupt */
    uint16 u16TargetCores;
} Mscm_Ip_IrqRouteConfigType;
/**
* @brief          Structure storing the list of state configurations for interrupt Router.
*/
typedef struct
{
    /** @brief Total of SPI interrupts routing */
    uint32 u32GlobalRouteConfigCount;
    /** @brief List of interrupts routing configurations */
    const Mscm_Ip_IrqRouteConfigType *aGlobalRouteConfig;
} Mscm_Ip_ConfigType;

#endif /* MSCM_IP_TYPES_H */


/** @} */
