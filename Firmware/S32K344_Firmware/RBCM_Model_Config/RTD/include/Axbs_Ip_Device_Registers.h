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

#ifndef AXBS_IP_DEVICE_REGISTERS_H
#define AXBS_IP_DEVICE_REGISTERS_H

/**
*   @file Axbs_Ip_Device_Registers.h
*
*   @addtogroup AXBS_IP AXBS IPV Driver
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
#include "Axbs_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_AXBS_IP_DEVICE_REGISTERS_VENDOR_ID                      43
#define RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION       4
#define RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION       7
#define RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION    0
#define RM_AXBS_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION               5
#define RM_AXBS_IP_DEVICE_REGISTERS_SW_MINOR_VERSION               0
#define RM_AXBS_IP_DEVICE_REGISTERS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Axbs_Ip_Cfg_Defines.h */
#if (RM_AXBS_IP_DEVICE_REGISTERS_VENDOR_ID != RM_AXBS_IP_CFG_DEFINES_VENDOR_ID)
    #error "Axbs_Ip_Device_Registers.h and Axbs_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Axbs_Ip_Device_Registers.h and Axbs_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_AXBS_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION != RM_AXBS_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_DEVICE_REGISTERS_SW_MINOR_VERSION != RM_AXBS_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_DEVICE_REGISTERS_SW_PATCH_VERSION != RM_AXBS_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip_Device_Registers.h and Axbs_Ip_Cfg_Defines.h are different"
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
#ifdef RM_IP_ENABLE_AXBS
#if (RM_IP_ENABLE_AXBS == STD_ON)

#define AXBS_BASE_ADDR32(instance)      (Axbs_Ip_InstanceAddress[instance])

/*  AXBS_PRS register */
/*  priority values of the masters */
#define AXBS_PRIORITY_0_U32             ((uint32)(0U))
#define AXBS_PRIORITY_1_U32             ((uint32)(1U))
#define AXBS_PRIORITY_2_U32             ((uint32)(2U))
#define AXBS_PRIORITY_3_U32             ((uint32)(3U))
#define AXBS_PRIORITY_4_U32             ((uint32)(4U))
#define AXBS_PRIORITY_5_U32             ((uint32)(5U))
#define AXBS_PRIORITY_6_U32             ((uint32)(6U))
#define AXBS_PRIORITY_7_U32             ((uint32)(7U))

/*  mask for master bits */
#define AXBS_PRS_MASK32                 ((uint32)(0x77777777UL))
#define AXBS_MASTER0_MASK32             ((uint32)(0x00000007UL))
#define AXBS_MASTER1_MASK32             ((uint32)(0x00000070UL))
#define AXBS_MASTER2_MASK32             ((uint32)(0x00000700UL))
#define AXBS_MASTER3_MASK32             ((uint32)(0x00007000UL))
#define AXBS_MASTER4_MASK32             ((uint32)(0x00070000UL))
#define AXBS_MASTER5_MASK32             ((uint32)(0x00700000UL))
#define AXBS_MASTER6_MASK32             ((uint32)(0x07000000UL))
#define AXBS_MASTER7_MASK32             ((uint32)(0x70000000UL))


/*  bits to shift to get the master priority */
#define AXBS_MASTER0_SHIFT_U32          ((uint32)(0U))
#define AXBS_MASTER1_SHIFT_U32          ((uint32)(4U))
#define AXBS_MASTER2_SHIFT_U32          ((uint32)(8U))
#define AXBS_MASTER3_SHIFT_U32          ((uint32)(12U))
#define AXBS_MASTER4_SHIFT_U32          ((uint32)(16U))
#define AXBS_MASTER5_SHIFT_U32          ((uint32)(20U))
#define AXBS_MASTER6_SHIFT_U32          ((uint32)(24U))
#define AXBS_MASTER7_SHIFT_U32          ((uint32)(28U))

/*  AXBS_CRS registers */

#define AXBS_LOCK_EN_U32                ((uint32)(1U))

#define AXBS_LOCK_DIS_U32               ((uint32)(0U))

#define AXBS_HLP_LOWEST_U32             ((uint32)(1U))

#define AXBS_HLP_HIGHEST_U32            ((uint32)(0U))

#define AXBS_HPE_EN_U32                 ((uint32)(1U))

#define AXBS_HPE_DIS_U32                ((uint32)(0U))

#define AXBS_ARB_FIXED_U32              ((uint32)(0U))

#define AXBS_ARB_ROUND_ROBIN_U32        ((uint32)(1U))

#define AXBS_PCTL_PARK_FIELD_U32        ((uint32)(0U))

#define AXBS_PCTL_LAST_MASTER_U32       ((uint32)(1U))

#define AXBS_PCTL_LOW_POWER_PARK_U32    ((uint32)(2U))

#define AXBS_MASTER_0_U32               ((uint32)(0U))

#define AXBS_MASTER_1_U32               ((uint32)(1U))

#define AXBS_MASTER_2_U32               ((uint32)(2U))

#define AXBS_MASTER_3_U32               ((uint32)(3U))

#define AXBS_MASTER_4_U32               ((uint32)(4U))

#define AXBS_MASTER_5_U32               ((uint32)(5U))

#define AXBS_MASTER_6_U32               ((uint32)(6U))

#define AXBS_MASTER_7_U32               ((uint32)(7U))

#define AXBS_LK_BIT_MASK32              ((uint32)(0x80000000UL))
#define AXBS_HLP_BIT_MASK32             ((uint32)(0x40000000UL))
#define AXBS_HPE7_BIT_MASK32            ((uint32)(0x00800000UL))
#define AXBS_HPE6_BIT_MASK32            ((uint32)(0x00400000UL))
#define AXBS_HPE5_BIT_MASK32            ((uint32)(0x00200000UL))
#define AXBS_HPE4_BIT_MASK32            ((uint32)(0x00100000UL))
#define AXBS_HPE3_BIT_MASK32            ((uint32)(0x00080000UL))
#define AXBS_HPE2_BIT_MASK32            ((uint32)(0x00040000UL))
#define AXBS_HPE1_BIT_MASK32            ((uint32)(0x00020000UL))
#define AXBS_HPE0_BIT_MASK32            ((uint32)(0x00010000UL))
#define AXBS_ARB_BITS_MASK32            ((uint32)(0x00000300UL))
#define AXBS_PCTL_BITS_MASK32           ((uint32)(0x00000030UL))
#define AXBS_PARK_BITS_MASK32           ((uint32)(0x00000007UL))

/*  shifts for AXBS_CRS registers */
#define AXBS_LOCK_SHIFT_U32             ((uint32)(31U))
#define AXBS_HLP_SHIFT_U32              ((uint32)(30U))
#define AXBS_HPE7_SHIFT_U32             ((uint32)(23U))
#define AXBS_HPE6_SHIFT_U32             ((uint32)(22U))
#define AXBS_HPE5_SHIFT_U32             ((uint32)(21U))
#define AXBS_HPE4_SHIFT_U32             ((uint32)(20U))
#define AXBS_HPE3_SHIFT_U32             ((uint32)(19U))
#define AXBS_HPE2_SHIFT_U32             ((uint32)(18U))
#define AXBS_HPE1_SHIFT_U32             ((uint32)(17U))
#define AXBS_HPE0_SHIFT_U32             ((uint32)(16U))
#define AXBS_ARB_SHIFT_U32              ((uint32)(8U))
#define AXBS_PCTL_SHIFT_U32             ((uint32)(4U))

#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
#if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)
    /*  masks for AXBS_MGPCR registers */
    #define AXBS_MGPCR_MASK32           ((uint32)(0x00000007UL))
    /*  shifts for AXBS_MGPCR registers */
    #define AXBS_AULB_SHIFT_U32         ((uint32)(0U))
#endif
#endif


/*  offsets used to calculate the registers addresses */
#define AXBS_PORT_OFFSET_U32            ((uint32)(0x100))
#define AXBS_CRS_OFFSET_U32             ((uint32)(0x10))
#define AXBS_MGPCR_OFFSET_U32           ((uint32)(0x800))

/*
* @brief macros used to calculate the address of a AXBS_PRS register.
*/

#define AXBS_PRS_ADDR(port, instance)  \
        (AXBS_BASE_ADDR32(instance) +  (AXBS_PORT_OFFSET_U32 * (port)))

/*
* @brief macros used to calculate the address of a AXBS_CRS register.
*/

#define AXBS_CRS_ADDR(port, instance)  \
        (AXBS_BASE_ADDR32(instance) +  (AXBS_PORT_OFFSET_U32 * (port)) + AXBS_CRS_OFFSET_U32)


#endif /* if (RM_IP_ENABLE_AXBS == STD_ON) */
#endif /* ifdef RM_IP_ENABLE_AXBS */
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

#endif /* AXBS_IP_DEVICE_REGISTERS_H */
