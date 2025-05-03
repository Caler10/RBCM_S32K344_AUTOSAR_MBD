/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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


/**
*   @file    Lin_43_LPUART_FLEXIO_Ipw_PBcfg.c
*   @implements Lin_43_LPUART_FLEXIO_Ipw_PBcfg.c_Artifact
*
*   @internal
*   @addtogroup LIN_IPW
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
#include "Lin_43_LPUART_FLEXIO_Ipw_Cfg.h"
#include "Lpuart_Lin_Ip_Cfg.h"
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
#include "Flexio_Lin_Ip_Cfg.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_VENDOR_ID_C                     43
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C              5
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C              0
#define LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_Ipw_Cfg.h */
#if (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_IPW_CFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Lin_43_LPUART_FLEXIO_Ipw_Cfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Lin_43_LPUART_FLEXIO_Ipw_Cfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Lin_43_LPUART_FLEXIO_Ipw_Cfg.h are different"
#endif

/* Checks against Lpuart_Lin_Ip_Cfg.h */
#if (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_VENDOR_ID_C != LPUART_LIN_IP_CFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Lpuart_Lin_Ip_Cfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPUART_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LPUART_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPUART_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Lpuart_Lin_Ip_Cfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != LPUART_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != LPUART_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != LPUART_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Lpuart_Lin_Ip_Cfg.h are different"
#endif

#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
/* Checks against Flexio_Lin_Ip_Cfg.h */
#if (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_VENDOR_ID_C != FLEXIO_LIN_IP_CFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Flexio_Lin_Ip_Cfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Flexio_Lin_Ip_Cfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != FLEXIO_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != FLEXIO_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c and Flexio_Lin_Ip_Cfg.h are different"
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief   Export LPUART_LIN configurations.
*/
LPUART_LIN_IP_CONFIG_EXT

#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
/**
* @brief   Export FLEXIO_LIN configurations.
*/
FLEXIO_LIN_IP_CONFIG_EXT
#endif
/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/**
* @brief          Hardware configuration for Lin Hardware Instance FLEXIO_IP_0 - Configuration:
*
*
*/

const Lin_43_LPUART_FLEXIO_HwConfigType Lin_43_LPUART_FLEXIO_Ipw_pxHwConfigPB_0_MBDT =
{
    FLEXIO_IP_0,
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
    (boolean)FALSE, /* Wakeup support disabled */

    (EcuM_WakeupSourceType)LIN_43_LPUART_FLEXIO_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
#endif
    LIN_43_LPUART_FLEXIO_MASTER_NODE, /* Lin Node Type */
    LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL, /*Hardware type*/
    {
        NULL_PTR,
        &Flexio_Lin_Ip_pxHwConfigPB_0_MBDT
    }
    };
/**
* @brief          Hardware configuration for Lin Hardware Instance LPUART_IP_5 - Configuration:
*
*
*/

const Lin_43_LPUART_FLEXIO_HwConfigType Lin_43_LPUART_FLEXIO_Ipw_pxHwConfigPB_1_MBDT =
{
    LPUART_IP_5,
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
    (boolean)FALSE, /* Wakeup support disabled */

    (EcuM_WakeupSourceType)LIN_43_LPUART_FLEXIO_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
#endif
    LIN_43_LPUART_FLEXIO_SLAVE_NODE, /* Lin Node Type */

    LIN_43_LPUART_FLEXIO_LPUART_CHANNEL, /*Hardware type*/
    {
        &Lpuart_Lin_Ip_pxHwConfigPB_1_MBDT
    #if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
        ,
        NULL_PTR
    #endif
    }
};

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

