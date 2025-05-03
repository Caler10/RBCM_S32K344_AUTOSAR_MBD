/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef ICU_IRQ_H
#define ICU_IRQ_H

/**
*     @file
*     @internal
*     @addtogroup icu Icu Driver
*     @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IRQ_VENDOR_ID                       43
#define ICU_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IRQ_AR_RELEASE_MINOR_VERSION        7
#define ICU_IRQ_AR_RELEASE_REVISION_VERSION     0
#define ICU_IRQ_SW_MAJOR_VERSION                5
#define ICU_IRQ_SW_MINOR_VERSION                0
#define ICU_IRQ_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IRQ_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu_Irq.h and Icu_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IRQ_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IRQ_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Irq.h and Icu_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IRQ_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IRQ_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_IRQ_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Irq.h and Icu_Types.h are different"
#endif

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
/**
* @internal
* @brief      This function reports the wakeup and overflow events, if available.
* @details    This function reports the wakeup and overflow events, if available.
*             Called from hardware interrupt routine and route to user overflow handler
*
* @param[in]  Channel        Hardware number identifier of the ICU channel
* @param[in]  bOverflow      Parameter that indicates the source of report is an overflow
*
* @return     void
* @pre        Icu_Init must be called before.
*
* @implements Icu_ReportWakeupAndOverflow_Activity
**/
void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow);

/**
 * @internal
 * @brief     This function reports the wakeup event, overflow event and notification, if available
 * @details   This function reports the wakeup event, overflow event and notification, if available
 *
 * @param[in]    Channel          Harware number identifier of the ICU channel
 * @param[in]    overflow         Parameter that indicates the source of report is an overflow
 *
 * @return      void
 * @pre        Icu_Init must be called before.
 *
 * @implements Icu_ReportEvents_Activity
 */
void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/**
* @internal
* @brief      This function saves the value of timestamps in the internal buffer
* @details    This function saves the value of timestamps in the internal buffer
*
* @param[in]  Channel   Logical number of the ICU channel
*
* @return     void
* @pre        Icu_Init must be called before.
* @implements Icu_TimestampDmaProcessing_Activity
**/
void Icu_TimestampDmaProcessing(Icu_ChannelType Channel);
#endif

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/**
* @internal
* @brief      This function saves the value of timestamps in the internal buffer
* @details    This function saves the value of timestamps in the internal buffer
*
* @param[in]  Channel   Logical number of the ICU channel
*
* @return     void
* @pre        Icu_Init must be called before.
*
**/
void Icu_SignalMeasurementDmaProcessing(Icu_ChannelType Channel);
#endif

/**
 * @internal
 * @brief Signature of change logic channel state callback function.
 * 
 * @param[in] logicChannel    Logical number of the ICU channel
 * @param[in] mask            Bit mark
 * @param[in] set             Set value
 *
 * @return     void
 */
void Icu_LogicChStateCallback(uint16 logicChannel, uint8 mask, boolean set);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_IRQ_H */
