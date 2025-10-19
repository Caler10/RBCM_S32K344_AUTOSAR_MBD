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

#ifndef LIN_43_LPUART_FLEXIO_CFG_H
#define LIN_43_LPUART_FLEXIO_CFG_H

/**
*   @file
*
*   @defgroup lin_driver LIN Driver
*   @addtogroup  lin_driver LIN Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Lin_43_LPUART_FLEXIO_MBDT_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_CFG_VENDOR_ID                    43
#define LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION     7
#define LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LPUART_FLEXIO_CFG_SW_MAJOR_VERSION             5
#define LIN_43_LPUART_FLEXIO_CFG_SW_MINOR_VERSION             0
#define LIN_43_LPUART_FLEXIO_CFG_SW_PATCH_VERSION             0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_MBDT_PBcfg.h */
#if (LIN_43_LPUART_FLEXIO_CFG_VENDOR_ID != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Cfg.h and Lin_43_LPUART_FLEXIO_MBDT_PBcfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Cfg.h and Lin_43_LPUART_FLEXIO_MBDT_PBcfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_CFG_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_MBDT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Cfg.h and Lin_43_LPUART_FLEXIO_MBDT_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_CONFIG_EXT \
    LIN_43_LPUART_FLEXIO_CONFIG_MBDT_PB \

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
extern const Lin_43_LPUART_FLEXIO_ConfigType * Lin_43_LPUART_FLEXIO_apxConfigPtr[LIN_43_LPUART_FLEXIO_MAX_PARTITIONS];

/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
extern const Lin_43_LPUART_FLEXIO_ChannelConfigType *Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief          LIN driver status variable.
* @details        LIN driver state machine.
*/
extern uint8 Lin_43_LPUART_FLEXIO_au8LinDrvStatus[LIN_43_LPUART_FLEXIO_MAX_PARTITIONS];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief          LIN channel state variable.
* @details        LIN channel state machine.
*/
extern uint8 Lin_43_LPUART_FLEXIO_au8LinChStatus[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                     EXTERNAL CONSTANTS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
extern const Mcal_DemErrorType Lin_43_LPUART_FLEXIO_xE_TimeoutCfg;
#endif /* LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LPUART_FLEXIO_CFG_H */

