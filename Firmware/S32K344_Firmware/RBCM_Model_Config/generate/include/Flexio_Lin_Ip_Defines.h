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
#ifndef FLEXIO_LIN_IP_DEFINES_H
#define FLEXIO_LIN_IP_DEFINES_H

/**
*   @file
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "S32K344_FLEXIO.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_LIN_IP_DEFINES_VENDOR_ID                    43
#define FLEXIO_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_LIN_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_LIN_IP_DEFINES_SW_MAJOR_VERSION             5
#define FLEXIO_LIN_IP_DEFINES_SW_MINOR_VERSION             0
#define FLEXIO_LIN_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((FLEXIO_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Flexio_Lin_Ip_Defines.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @ brief   Switches the Development Error Detection and Notification ON or OFF.
*
*
*/
#define FLEXIO_LIN_IP_DEV_ERROR_DETECT               (STD_OFF)  /*!< Development error detection */

/**
* @brief          Lin Osif source counter
* @details        This parameter is used to select between different OsIf counter implementation
*
*
*/

#define  FLEXIO_LIN_IP_TIMEOUT_TYPE     (OSIF_COUNTER_DUMMY)

/**
* @brief   Number of loops before returning FLEXIO_STATUS_TIMEOUT.
*
*
*/
#define FLEXIO_LIN_IP_TIMEOUT_VALUE_US    (65535U)

/**
* @brief   Total number of flexio channels
*
*/
#define FLEXIO_LIN_IP_NUMBER_OF_CHANNELS           (4U)

/**
* @brief   Total number of flexio shifters
*
*/
#define FLEXIO_LIN_IP_NUMBER_OF_FLEXIO_SHIFTERS    (8U)

#if (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    #define FLEXIO_LIN_IP_DEV_ASSERT(x)      DevAssert(x)
#endif /* (FLEXIO_LIN_IP_DEV_ERROR_DETECT == STD_ON) */



/**
* @brief          Lin FlexIO Used
* @details        When LinGlobalConfig/LinChannel/LinHwChannel contains FLEXIO.
*
*
*/
#define FLEXIO_LIN_IP_FLEXIO_USED (STD_ON) /* Flexio Used */

/**
* @ brief   Enable/Disable timeout feature.
*/
#define FLEXIO_LIN_IP_FRAME_TIMEOUT_DISABLE        (STD_ON)

/**
* @brief          Link Lin channels symbolic names with Lin hardware channel IDs for FLEXIO instance.
* @details        Link Lin channels symbolic names with Lin hardware channel IDs for FLEXIO instance.
*
*
*/

#define FLEXIO_IP_0       ((uint8)0U)
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

#endif  /* FLEXIO_LIN_IP_DEFINES_H */

