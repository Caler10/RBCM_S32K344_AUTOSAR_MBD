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

#ifndef LIN_43_LPUART_FLEXIO_ASREXT_H
#define LIN_43_LPUART_FLEXIO_ASREXT_H

/**
*   @file Lin_ASRExt.h
*
*   @addtogroup LIN
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
#include "Lin_43_LPUART_FLEXIO_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID                    43
#define LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION     7
#define LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION             5
#define LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION             0
#define LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID != LIN_43_LPUART_FLEXIO_DEFINES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_ASRExt.h and Lin_43_LPUART_FLEXIO_Defines.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Defines header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Defines header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.h and Lin_43_LPUART_FLEXIO_Defines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON)
#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
/**
* @brief            API service ID for Lin_43_LPUART_FLEXIO_SetClockMode() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LIN_43_LPUART_FLEXIO_SETCLOCKMODE_ID       ((uint8)0x0CU)
#endif /* #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
#endif /* #if LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Clock modes.
* @pre            LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @note           Possible clock modes: LIN_43_LPUART_FLEXIO_NORMAL (normal execution mode),
*                 LIN_43_LPUART_FLEXIO_ALTERNATE (low power mode).
*
*/
typedef enum
{
    LIN_43_LPUART_FLEXIO_NORMAL     =   (uint8)0x01U, /**< @brief
                                               LIN_43_LPUART_FLEXIO_NORMAL mode.*/
    LIN_43_LPUART_FLEXIO_ALTERNATE  =   (uint8)0x02U  /**< @brief
                                               LIN_43_LPUART_FLEXIO_ALTERNATE mode.*/
} Lin_43_LPUART_FLEXIO_ClockModesType;

#endif /* #if LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON */

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#if (LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Lin_43_LPUART_FLEXIO_SetClockMode.
* @details        Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*
* @param[in]      ClockMode   New clock mode.
*
* @return                     The result of the switching clock operation.
* @retval E_OK                The switching operation was OK.
* @retval E_NOT_OK            The switching operation has failed caused by the
*                             wrong driver state.
*
* @api            Switch the clock mode to the alternate clock mode on all
*                 the Lin channels.
*
* @pre            LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @note           Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_SetClockMode(Lin_43_LPUART_FLEXIO_ClockModesType ClockMode);
#endif

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LPUART_FLEXIO_ASREXT_H */
