/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
*
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Flexio_Lin_Ip_PBcfg.c
*
*   @addtogroup FLEXIO_IP
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
#include "Flexio_Lin_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_LIN_IPMBDT_PBCFG_VENDOR_ID_C                     43
#define FLEXIO_LIN_IPMBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define FLEXIO_LIN_IPMBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define FLEXIO_LIN_IPMBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define FLEXIO_LIN_IPMBDT_PBCFG_SW_MAJOR_VERSION_C              4
#define FLEXIO_LIN_IPMBDT_PBCFG_SW_MINOR_VERSION_C              0
#define FLEXIO_LIN_IPMBDT_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Flexio_Lin_Ip_Cfg.h */
#if (FLEXIO_LIN_IPMBDT_PBCFG_VENDOR_ID_C != FLEXIO_LIN_IP_CFG_VENDOR_ID)
    #error "Flexio_Lin_IpMBDT_PBcfg.c and Flexio_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((FLEXIO_LIN_IPMBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IPMBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IPMBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Lin_IpMBDT_PBcfg.c and Flexio_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip_Cfg header file are of the same Software version */
#if ((FLEXIO_LIN_IPMBDT_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IPMBDT_PBCFG_SW_MINOR_VERSION_C != FLEXIO_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IPMBDT_PBCFG_SW_PATCH_VERSION_C != FLEXIO_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_IpMBDT_PBcfg.c and Flexio_Lin_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

extern Flexio_Lin_Ip_StateStructType Flexio_Lin_Ip_axStateStructure[FLEXIO_LIN_IP_NUMBER_OF_CHANNELS];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
 * @brief   FlexIO Config parameters
 */
const Flexio_Lin_Ip_UserConfigType Flexio_Lin_Ip_pxHwConfigPB_0_MBDT=
{
    (uint8)0U, /*Instance*/
    (uint8)1U, /* TxShifterId */
    (uint8)1U, /* TxTimerId */
    (uint8)27U, /* TxPin */
    (uint8)0U, /* RxShifterId */
    (uint8)0U, /* RxTimerId */
    (uint8)28U, /* RxPin */
    (uint8)0U, /* FlexioHwInstance */
    (uint8)13U,  /* MasterBreakLength */
    (uint8)11U,  /* SlaveSyncBreakLength */
    (uint8)5,/* Timer clock source */
    (uint16)15, /* Baudratedivider */
    (boolean)FLEXIO_LIN_IP_MASTER, /* NodeFunction */
    (Flexio_Lin_Ip_CallbackType)Flexio_Lin_Ipw_Callback, /* Callback function */
    &Flexio_Lin_Ip_axStateStructure[0U], /*!< Runtime state structure reference */
    (uint32)19200, /*Baudrate. ActualBaudrate: 19531.25*/
#if (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
#ifdef FLEXIO_LIN_IP_START_TIMER_NOTIFICATION
    (uint32)2253, /*!< HeaderTimeoutValue in microseconds */
    (uint32)72, /*!< ResponseTimeoutValue in microseconds for 1 byte */
#endif
#endif /* (FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF) */
    (uint8)0, /*!< Wakeup byte to generate wake up pulse 460.8us */
    (uint8)1 /*!< Byte use to check a wake up pulse 102.4us detection */
};

    #define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

