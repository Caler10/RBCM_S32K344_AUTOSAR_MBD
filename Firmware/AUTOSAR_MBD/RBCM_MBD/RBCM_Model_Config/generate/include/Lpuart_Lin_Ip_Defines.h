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


#ifndef LPUART_LIN_IP_DEFINES_H
#define LPUART_LIN_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup LPUART_LIN
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "S32K344_LPUART.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_DEFINES_VENDOR_ID                    43
#define LPUART_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define LPUART_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define LPUART_LIN_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define LPUART_LIN_IP_DEFINES_SW_MAJOR_VERSION             5
#define LPUART_LIN_IP_DEFINES_SW_MINOR_VERSION             0
#define LPUART_LIN_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LPUART_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPUART_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Lpuart_Lin_Ip_Defines.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
*
*/
#define LPUART_LIN_IP_DEV_ERROR_DETECT            (STD_OFF)  /*!< Development error detection */

/**
* @brief   No of Channels configured for Lpuart
*
*
*/
#define LPUART_LIN_IP_NUMBER_OF_INSTANCES         (1U)


/**
* @brief          Lin Osif source counter
* @details        This parameter is used to select between different OsIf counter implementation
*
*
*/
#define  LPUART_LIN_IP_TIMEOUT_TYPE         (OSIF_COUNTER_DUMMY)

/**
* @brief   Number of microsecond before returning LPUART_STATUS_TIMEOUT.
*
*
*/
#define LPUART_LIN_IP_TIMEOUT_VALUE_US    (65535U)

/**
* @brief   Enable/Disable Autobaud feature. This feature only support for IPV layer
* So HLD layer always disable for this feature.
*
*
*/
#define LPUART_LIN_IP_AUTO_BAUD     (STD_OFF)
/**
* @brief   Enable/Disable timeout feature.
*
*
*/
#define LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE     (STD_ON)
/**
* @brief          Link Lin channels symbolic names with Lin hardware channel IDs for LPUART instance.
* @details        Link Lin channels symbolic names with Lin hardware channel IDs for LPUART instance.
*
*
*/
#define LPUART_IP_5       ((uint8)5U)
#define LPUART_LIN_IP_LPUART_BASE_PTRS      IP_LPUART_BASE_PTRS /* Default from Base */
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
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

#endif /* LPUART_LIN_IP_DEFINES_H */

