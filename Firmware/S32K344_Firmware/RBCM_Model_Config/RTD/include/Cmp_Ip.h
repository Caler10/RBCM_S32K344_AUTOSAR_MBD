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

#ifndef CMP_IP_H
#define CMP_IP_H

/**
 *     @file
 *
 *     @addtogroup cmp_icu_ip CMP IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
==================================================================================================*/
#include "Cmp_Ip_Cfg.h"
#include "OsIf.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CMP_IP_VENDOR_ID                      43
#define CMP_IP_AR_RELEASE_MAJOR_VERSION       4
#define CMP_IP_AR_RELEASE_MINOR_VERSION       7
#define CMP_IP_AR_RELEASE_REVISION_VERSION    0
#define CMP_IP_SW_MAJOR_VERSION               5
#define CMP_IP_SW_MINOR_VERSION               0
#define CMP_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (CMP_IP_VENDOR_ID != CMP_IP_CFG_VENDOR_ID)
    #error "Cmp_Ip.h and Cmp_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((CMP_IP_AR_RELEASE_MAJOR_VERSION  != CMP_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CMP_IP_AR_RELEASE_MINOR_VERSION  != CMP_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CMP_IP_AR_RELEASE_REVISION_VERSION   != CMP_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Cmp_Ip.h and Cmp_Ip_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((CMP_IP_SW_MAJOR_VERSION  != CMP_IP_CFG_SW_MAJOR_VERSION) || \
     (CMP_IP_SW_MINOR_VERSION  != CMP_IP_CFG_SW_MINOR_VERSION) || \
     (CMP_IP_SW_PATCH_VERSION  != CMP_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Cmp_Ip.h and Cmp_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == CMP_IP_USED)

#if (defined CMP_CONFIG_EXT)
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/* Macro used to import CMP generated configurations. */
CMP_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
/**
 * @brief Configure all comparator features with the given configuration structure
 *
 * This function configures the comparator module with the options
 * provided in the config structure.
 *
 * @param instance - instance number
 * @param config - the configuration structure
 * @return
 *        - CMP_IP_STATUS_SUCCESS : Completed successfully.
 *        - CMP_IP_STATUS_ERROR : Error occurred.
 */
Cmp_Ip_StatusType Cmp_Ip_Init(uint8 instance, const Cmp_Ip_ConfigType* userConfig);

#if (CMP_IP_DEINIT_API == STD_ON)
/**
 * @brief Reset all register used by ICU driver on current CMP instance.
 *
 * @param Instance - The number instance to be deinitialize.
 * @return Cmp_Ip_StatusType
 */
Cmp_Ip_StatusType Cmp_Ip_Deinit(uint8 instance);
#endif  /* CMP_IP_DEINIT_API  */

#if (CMP_IP_SET_MODE_API == STD_ON)
void Cmp_Ip_SetSleepMode(uint8 instance);
void Cmp_Ip_SetNormalMode(uint8 instance);
#endif  /* CMP_IP_SET_MODE_API  */

/**
 * @brief Enable CMP notification.
 *
 * @param Instance The number of instance for which the notifcation will be enabled.
 */
void Cmp_Ip_EnableNotification(uint8 instance);

/**
 * @brief Disable CMP notification.
 *
 * @param Instance The number of instance for which the notifcation will be enabled.
 */
void Cmp_Ip_DisableNotification(uint8 instance);

/**
 * @brief Set the type of activation for interrupt.
 *
 * @param Instance The number of instance for which the interrupt activation will be set.
 * @param Edge
 */
void Cmp_Ip_SetInterruptActivation(uint8 instance, Cmp_Ip_OutputInterruptTriggerType Edge);

/**
 * @brief Enable CMP interrupt.
 *
 * @param Instance The number of instance for which the interrupt will be enabled.
 */
void Cmp_Ip_EnableInterrupt(uint8 instance);

/**
 * @brief Disable CMP interrupt.
 *
 * @param Instance The number of instance for which the interrupt will be disable.
 */
void Cmp_Ip_DisableInterrupt(uint8 instance);

#if (CMP_IP_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief Get instance status.
 *
 * @param Instance The number of instace to get the status.
 * @return boolean
 */
boolean Cmp_Ip_GetStatus(uint8 instance);
#endif

#if (defined(ICU_CMP_0_ISR_USED))
/**
 * @brief     Interrupt handler for CMP 0.
 * @details   Process the interrupt of instance 0.
 *
 * @remarks   This will be defined only if CMP 0 is configured.
 */
ISR(CMP_0_ISR);

#endif

#if (defined(ICU_CMP_1_ISR_USED))
/**
 * @brief     Interrupt handler for CMP 1.
 * @details   Process the interrupt of instance 1.
 *
 * @remarks   This will be defined only if CMP 1 is configured.
 */
ISR(CMP_1_ISR);

#endif

#if (defined(ICU_CMP_2_ISR_USED))
/**
 * @brief     Interrupt handler for CMP 2.
 * @details   Process the interrupt of instance 2.
 *
 * @remarks   This will be defined only if CMP 2 is configured.
 */
ISR(CMP_2_ISR);

#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* CMP_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* WKPU_ICU_IP_H */
