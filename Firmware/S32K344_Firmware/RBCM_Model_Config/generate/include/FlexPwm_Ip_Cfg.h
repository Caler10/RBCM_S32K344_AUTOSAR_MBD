/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm eTpu
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
#ifndef FLEXPWM_IP_CFG_H
#define FLEXPWM_IP_CFG_H

/**
*   @file       FlexPwm_Ip_Cfg.h
*
*   @addtogroup flexpwm_ip FlexPwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Standard Types */
#include "Std_Types.h"

/* Register definitions */

/* Include all variants header files. */
#include "FlexPwm_Ip_MBDT_PBcfg.h"

/* Include Feature Defines */
#include "FlexPwm_Ip_CfgDefines.h"
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_CFG_VENDOR_ID                    43
#define FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FLEXPWM_IP_CFG_SW_MAJOR_VERSION             5
#define FLEXPWM_IP_CFG_SW_MINOR_VERSION             0
#define FLEXPWM_IP_CFG_SW_PATCH_VERSION             0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip_Cfg.h and Std_Types.h are different"
    #endif

    /* Check if header file and Reg_eSys.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif

    /* Check if header file and FlexPwm_Ip_MBDT_PBcfg header file are of the same vendor */
#if (FLEXPWM_IP_CFG_VENDOR_ID != FLEXPWM_IP_MBDT_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_MBDT_PBcfg.h are different."
#endif

    /* Check if header file and FlexPwm_Ip_MBDT_PBcfg header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_MBDT_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_MBDT_PBcfg.h are different."
#endif

    /* Check if header file and FlexPwm_Ip_MBDT_PBcfg header file are of the same software version */
#if ((FLEXPWM_IP_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_MBDT_PB_CFG_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_MINOR_VERSION != FLEXPWM_IP_MBDT_PB_CFG_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_PATCH_VERSION != FLEXPWM_IP_MBDT_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_MBDT_PBcfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same vendor */
#if (FLEXPWM_IP_CFG_VENDOR_ID != FLEXPWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same software version */
#if ((FLEXPWM_IP_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_MINOR_VERSION != FLEXPWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_PATCH_VERSION != FLEXPWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief      In HLD this macro is OFF */
#define FLEXPWM_IP_DEV_ERROR_DETECT            (STD_OFF)

/** @brief    Support for User mode */
#define FLEXPWM_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

/** @brief      The number of FlexPwm instances available on platform */
#define FLEXPWM_IP_INSTANCE_COUNT_U8           (uint8)(0U)
/** @brief      The number of channels available on each FlexPwm instance */
#define FLEXPWM_IP_SUBMODULE_COUNT_U8          (uint8)(0U)

#define FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8   (uint8)(0U)


/** @brief      The number of channels available on each FlexPwm instance */
#define FLEXPWM_IP_UNIQUESUB_COUNT             (FLEXPWM_IP_SUBMODULE_COUNT_U8 * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8)

#define FLEXPWM_IP_SIGNED_REG_OFFSET            0x8000

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FLEXPWM_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running FLEXPWM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#if ((STD_ON == FLEXPWM_IP_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_FLEXPWM_AE_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_FLEXPWM_AE_REG_PROT_AVAILABLE)
        #define  FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_ON)
    #else
        #define  FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
    #endif
#else
#define  FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
#endif

/* @brief Define if global variables need to be placed in non-cache area or not */
#define FLEXPWM_IP_NO_CACHE_NEEDED               (STD_OFF)


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP_CFG_H */

