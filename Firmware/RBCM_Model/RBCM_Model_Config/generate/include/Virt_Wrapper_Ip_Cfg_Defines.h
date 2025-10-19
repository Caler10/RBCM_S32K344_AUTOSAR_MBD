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

#ifndef VIRT_WRAPPER_IP_CFG_DEFINES_H
#define VIRT_WRAPPER_IP_CFG_DEFINES_H

/**
*   @file Virt_Wrapper_Ip_Cfg_Defines.h
*
*   @addtogroup Virt_Wrapper_Ip Virt Wrapper IPV Driver
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
#include "Mcal.h"
/* NOT include base header file of Virtual Wrapper - RM will re-implement it */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_SW_MAJOR_VERSION             5
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_VIRT_WRAPPER_IP_CFG_DEFINES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip_Cfg_Defines.h and Mcal.h are different"
    #endif
    /* Checks against Std_Types.h */
    #if ((RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Virt_Wrapper_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define RM_VIRT_WRAPPER_REG_A_COUNT                         (32U)
#define RM_VIRT_WRAPPER_A_RESERVED                          (0U)
#define RM_VIRT_WRAPPER_REG_B_COUNT                         (32U)
#define RM_VIRT_WRAPPER_B_RESERVED                          (0U)
#define RM_VIRT_WRAPPER_REG_C_COUNT                         (1U)
#define RM_VIRT_WRAPPER_C_RESERVED                          (0U)
#define RM_VIRT_WRAPPER_REG_D_COUNT                         (1U)

/** VIRT_WRAPPER - Register Layout Typedef */
typedef struct {
#if RM_VIRT_WRAPPER_REG_A_COUNT > 0U
  __IO uint32 REG_A[RM_VIRT_WRAPPER_REG_A_COUNT];   /**< Parameter_n Register, array offset: 0x0, array step: 0x4 */
#endif    /** RM_VIRT_WRAPPER_REG_A_COUNT */
#if RM_VIRT_WRAPPER_A_RESERVED > 0U
  uint8 RESERVED_A[RM_VIRT_WRAPPER_A_RESERVED];
#endif    /** RM_VIRT_WRAPPER_A_RESERVED */
#if RM_VIRT_WRAPPER_REG_B_COUNT > 0U
  __IO uint32 REG_B[RM_VIRT_WRAPPER_REG_B_COUNT];   /**< Parameter_n Register, array offset: 0x80, array step: 0x4 */
#endif    /** RM_VIRT_WRAPPER_REG_B_COUNT */
#if RM_VIRT_WRAPPER_B_RESERVED > 0U
  uint8 RESERVED_B[RM_VIRT_WRAPPER_B_RESERVED];
#endif    /** RM_VIRT_WRAPPER_B_RESERVED */
#if RM_VIRT_WRAPPER_REG_C_COUNT > 0U
  __IO uint32 REG_C[RM_VIRT_WRAPPER_REG_C_COUNT];   /**< Parameter_n Register, array offset: 0x100, array step: 0x4 */
#endif    /** RM_VIRT_WRAPPER_REG_C_COUNT */
#if RM_VIRT_WRAPPER_C_RESERVED > 0U
  uint8 RESERVED_C[RM_VIRT_WRAPPER_C_RESERVED];
#endif    /** RM_VIRT_WRAPPER_C_RESERVED */
#if RM_VIRT_WRAPPER_REG_D_COUNT > 0U
  __IO uint32 REG_D[RM_VIRT_WRAPPER_REG_D_COUNT];   /**< Parameter_n Register, array offset: 0x104, array step: 0x4 */
#endif    /** RM_VIRT_WRAPPER_REG_D_COUNT */
} RM_VIRT_WRAPPER_Type, *RM_VIRT_WRAPPER_MemMapPtr;

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define RM_IP_ENABLE_VIRT_WRAPPER           (STD_OFF)


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* VIRT_WRAPPER_IP_CFG_DEFINES_H */

