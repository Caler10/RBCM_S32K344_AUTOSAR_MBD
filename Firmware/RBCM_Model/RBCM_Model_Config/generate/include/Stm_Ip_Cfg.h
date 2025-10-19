/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef STM_IP_CFG_H
#define STM_IP_CFG_H

/**
*   @file           Stm_Ip_Cfg.h
*
*   @addtogroup     stm_ip Stm IPL
*
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
/* Include all variants header files. */
#include "Stm_Ip_MBDT_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_VENDOR_ID_CFG                    43
#define STM_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define STM_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define STM_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define STM_IP_SW_MAJOR_VERSION_CFG             5
#define STM_IP_SW_MINOR_VERSION_CFG             0
#define STM_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (STM_IP_VENDOR_ID_CFG != STM_IP_VENDOR_ID_MBDT_PBCFG_H)
    #error "Stm_Ip_Cfg.h and Stm_Ip_MBDT_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION_CFG != STM_IP_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION_CFG != STM_IP_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION_CFG != STM_IP_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_MBDT_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION_CFG != STM_IP_SW_MAJOR_VERSION_MBDT_PBCFG_H) || \
     (STM_IP_SW_MINOR_VERSION_CFG != STM_IP_SW_MINOR_VERSION_MBDT_PBCFG_H) || \
     (STM_IP_SW_PATCH_VERSION_CFG != STM_IP_SW_PATCH_VERSION_MBDT_PBCFG_H) \
    )
    #error "Software Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_MBDT_PBcfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Dev error detect switch
*/
#define STM_IP_DEV_ERROR_DETECT     (STD_ON)
/*================================================================================================*/
/**
* @brief    STM_IP_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define STM_IP_CHANGE_NEXT_TIMEOUT_VALUE     (STD_OFF)
/*================================================================================================*/
/**
* @brief    STM_IP_PREDEFTIMER_FUNCTIONALITY_API switch
* @details  Enable/disable GPT_PREDEFTIMER_FUNCTIONALITY_API.
*/
#define STM_IP_PREDEFTIMER_FUNCTIONALITY_API     (STD_ON)
/*================================================================================================*/
/**
* @brief    STM_IP_ABSOLUTE_COUTNING_API switch
* @details  Enable/disable support for absolute compare value
*/
#define STM_IP_ABSOLUTE_COUNTING_API    (STD_OFF)
/*================================================================================================*/

/**
* @brief    STM_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to TRUE the GPT driver code can be executed from both supervisor and user mode.
*/
#define STM_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef STM_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
        #endif /* (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT*/

#if(defined(CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED) && (CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED == STD_ON))
#define GPT_STM_INSTANCE_COUNT (STM_INSTANCE_COUNT + RTU_STM_INSTANCE_COUNT)
#else
#define GPT_STM_INSTANCE_COUNT (STM_INSTANCE_COUNT)
#endif

/*================================================================================================*/
/*================================================================================================*/
/** Channels number instance STM_0 */
#define STM_0_IP_CHANNELS_NUMBER  (4U)
#define STM_0_IP_EXISTS
#define STM_0_IP_INSTANCE_NUMBER    (0U)
/** Channels number instance STM_1 */
#define STM_1_IP_CHANNELS_NUMBER  (4U)
#define STM_1_IP_EXISTS
#define STM_1_IP_INSTANCE_NUMBER    (1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* STM_IP_CFG_H */
