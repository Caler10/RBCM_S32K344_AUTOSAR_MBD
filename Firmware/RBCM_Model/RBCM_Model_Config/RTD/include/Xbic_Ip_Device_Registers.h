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

#ifndef XBIC_IP_DEVICE_REGISTERS_H
#define XBIC_IP_DEVICE_REGISTERS_H

/**
*   @file Xbic_Ip_Device_Registers.h
*
*   @addtogroup XBIC_IP XBIC IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Xbic_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XBIC_IP_DEVICE_REGISTERS_VENDOR_ID                      43
#define RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION       4
#define RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION       7
#define RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION    0
#define RM_XBIC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION               5
#define RM_XBIC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION               0
#define RM_XBIC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Axbs_Ip_Cfg_Defines.h */
#if (RM_XBIC_IP_DEVICE_REGISTERS_VENDOR_ID != RM_XBIC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Xbic_Ip_Device_Registers.h and Xbic_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip_Device_Registers.h and Xbic_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_XBIC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION != RM_XBIC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION != RM_XBIC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION != RM_XBIC_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip_Device_Registers.h and Xbic_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 Xbic_Ip_UintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 Xbic_Ip_UintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif

#define XBIC_REG_WRITE32(address, value)        ((*(volatile uint32 *)((Xbic_Ip_UintPtrType)address)) = (value))

#define XBIC_REG_READ32(address)                (*(volatile uint32 *)((Xbic_Ip_UintPtrType)address))

#define XBIC_REG_RMW32(address, mask, value)    (XBIC_REG_WRITE32((address), (((XBIC_REG_READ32(address)) & ((uint32) ~(mask))) | (value))))

#define XBIC_IP_BASE_ADDR32(u8instance)         (s_xbicBase[(u8instance)])

#define XBIC_IP_MCR_ADDR32(u8instance)          (XBIC_IP_BASE_ADDR32(u8instance) + (uint32)0x0U)
#define XBIC_IP_EIR_ADDR32(u8instance)          (XBIC_IP_BASE_ADDR32(u8instance) + (uint32)0x4U)
#define XBIC_IP_ESR_ADDR32(u8instance)          (XBIC_IP_BASE_ADDR32(u8instance) + (uint32)0x8U)
#define XBIC_IP_EAR_ADDR32(u8instance)          (XBIC_IP_BASE_ADDR32(u8instance) + (uint32)0xCU)

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

#endif /* XBIC_IP_DEVICE_REGISTERS_H */
