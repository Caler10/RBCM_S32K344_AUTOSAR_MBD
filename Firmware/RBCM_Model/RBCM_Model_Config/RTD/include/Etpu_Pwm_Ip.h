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

#ifndef ETPU_PWM_IP_H
#define ETPU_PWM_IP_H

/**
 *   @file       Etpu_Pwm_Ip.h
 *
 *   @addtogroup etpu_pwm_driver
 *   @brief      This file contains useful macros and prototypes for PWM API.
 *
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Etpu_Pwm_Ip_Cfg.h"
#include "Etpu_Pwm_Ip_Types.h"

#if (ETPU_PWM_IP_USED == STD_ON)
    #include "Etpu_Ip.h"
#endif /* ETPU_PWM_IP_USED == STD_ON */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETPU_PWM_IP_VENDOR_ID                     43
#define ETPU_PWM_IP_MODULE_ID                     121
#define ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION      4
#define ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION      7
#define ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION   0
#define ETPU_PWM_IP_SW_MAJOR_VERSION              5
#define ETPU_PWM_IP_SW_MINOR_VERSION              0
#define ETPU_PWM_IP_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     #if (ETPU_PWM_IP_USED == STD_ON)
          /* Check if header file and Etpu_Ip.h header file are of the same AUTOSAR version */
          #if ((ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION  != ETPU_IP_AR_RELEASE_MAJOR_VERSION) || \
               (ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION != ETPU_IP_AR_RELEASE_MINOR_VERSION))
          #error "AUTOSAR version numbers of Etpu_Pwm_Ip.h and Etpu_Ip.h are different."
          #endif
     #endif /* ETPU_PWM_IP_USED == STD_ON */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Etpu_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (ETPU_PWM_IP_VENDOR_ID != ETPU_PWM_IP_CFG_VENDOR_ID)
#error "Vendor IDs of Etpu_Pwm_Ip.h and Etpu_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION  != ETPU_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION != ETPU_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION != ETPU_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR version numbers of Etpu_Pwm_Ip.h and Etpu_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((ETPU_PWM_IP_SW_MAJOR_VERSION != ETPU_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_SW_MINOR_VERSION != ETPU_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_SW_PATCH_VERSION != ETPU_PWM_IP_CFG_SW_PATCH_VERSION))
#error "Software version numbers of Eptu_Pwm_Ip.h and Etpu_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Types.h header file are of the same vendor */
#if (ETPU_PWM_IP_VENDOR_ID != ETPU_PWM_IP_TYPES_VENDOR_ID)
#error "Vendor IDs of Etpu_Pwm_Ip.h and Etpu_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION  != ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION != ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION != ETPU_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR version numbers of Etpu_Pwm_Ip.h and Etpu_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_Types.h header file are of the same software version */
#if ((ETPU_PWM_IP_SW_MAJOR_VERSION != ETPU_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_SW_MINOR_VERSION != ETPU_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_SW_PATCH_VERSION != ETPU_PWM_IP_TYPES_SW_PATCH_VERSION))
#error "Software version numbers of Eptu_Pwm_Ip.h and Etpu_Pwm_Ip_Types.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Deduce eTPU engine number from absolute channel number. */
#define ETPU_PWM_IP_GET_ENGINE(absch) ((((uint8)(absch) & 0x40U) >> 6U))
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (ETPU_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

extern Etpu_Pwm_Ip_NotificationType *aEtpu_Pwm_Ip_NotificationPtr[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

extern Etpu_Pwm_Ip_StateType aEtpu_Pwm_Ip_ModuleState[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

extern Etpu_Ip_Uint24Type aEtpu_Pwm_Ip_Period[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

extern Etpu_Ip_Uint24Type aEtpu_Pwm_Ip_DutyCycle[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

#if (ETPU_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief      This function initializes eTPU channels to run PWM function.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  pPwmConfig pointer to the structure of configuration parameters @ref Etpu_Pwm_ConfigType.
 *
 * @return     Error codes that can be returned are:
 *             - @ref ETPU_ERROR_NONE - No error
 *             - @ref ETPU_ERROR_MALLOC - Allocation error
 *             - @ref ETPU_ERROR_PERIOD - Period range error
 *
 * @warning    This function does not configure the pins, only the eTPU channels.
 * 
 * @implements Etpu_Pwm_Ip_Init_Activity
 */
Etpu_Ip_ErrorType Etpu_Pwm_Ip_Init(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                   Etpu_Pwm_Ip_ConfigType *pPwmConfig);

/**
 * @brief      This function de-itializes eTPU PWM channels.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  ePinState Required pin state while PWM is not active.
 *
 * @return     none
 *
 * @warning    This function does not configure the pins, only the eTPU channels.
 * 
 * @implements Etpu_Pwm_Ip_DeInit_Activity
 */
void Etpu_Pwm_Ip_DeInit(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                        Etpu_Ip_PinStateType ePinState);

/**
 * @brief      This function changes the PWM duty cycle.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  pPwmConfig pointer to the structure of configuration parameters @ref Etpu_Pwm_ConfigType.
 *
 * @return     none
 * 
 * @implements Etpu_Pwm_Ip_UpdateDuty_Activity
 */
void Etpu_Pwm_Ip_UpdateDuty(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                            Etpu_Pwm_Ip_ConfigType *pPwmConfig);

/**
 * @brief      This function changes the PWM duty cycle immediately.
 * @details    To immediately update a channel dutycycle using a 16 bit integer value.
 *             This function will update the dutycycle during the current period if possible.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  pPwmConfig pointer to the structure of configuration parameters @ref Etpu_Pwm_ConfigType.
 *
 * @return     none
 * 
 * @implements Etpu_Pwm_Ip_UpdateDutyImmed_Activity
 */
void Etpu_Pwm_Ip_UpdateDutyImmed(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                 Etpu_Pwm_Ip_ConfigType *pPwmConfig);

/**
 * @brief      This function changes the PWM period and duty cycle.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  pPwmConfig pointer to the structure of configuration parameters @ref Etpu_Pwm_ConfigType.
 *
 * @return     Error code that can be returned is:
 *             - @ref ETPU_ERROR_PERIOD - Period range error
 * 
 * @implements Etpu_Pwm_Ip_Update_Activity
 */
Etpu_Ip_ErrorType Etpu_Pwm_Ip_Update(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                     Etpu_Pwm_Ip_ConfigType *pPwmConfig);

/**
 * @brief      This function changes the PWM interrupt mode.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  pPwmConfig pointer to the structure of configuration parameters @ref Etpu_Pwm_ConfigType.
 *
 * @return     Error code that can be returned is:
 *             - @ref ETPU_ERROR_PERIOD - Period range error
 * @implements Etpu_Pwm_Ip_UpdateInterruptMode_Activity
 */
void Etpu_Pwm_Ip_UpdateInterruptMode(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                     Etpu_Pwm_Ip_ConfigType *pPwmConfig);

/**
 * @brief      This function gets actual period of PWM.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 *
 * @return     The actual period of PWM
 * 
 * @implements Etpu_Pwm_Ip_GetPeriod_Activity
 */
Etpu_Ip_Uint24Type Etpu_Pwm_Ip_GetPeriod(Etpu_Pwm_Ip_InstanceType *pPwmInstance);

/**
 * @brief      This function gets actual duty cycle of PWM.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 *
 * @return     The actual duty cycle of PWM
 * 
 * @implements Etpu_Pwm_Ip_GetDuty_Activity
 */
uint16 Etpu_Pwm_Ip_GetDuty(Etpu_Pwm_Ip_InstanceType *pPwmInstance);

/**
 * @brief      This function gets last source of interrupt.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 *
 * @return     Source of interrupt that can be returned is:
 *             - @ref ETPU_PWM_LAST_INTERRUPT_FRAME_EDGE - Interrupt generated by the frame PWM edge
 *             - @ref ETPU_PWM_LAST_INTERRUPT_ACTIVE_EDGE - Interrupt generated by the active PWM edge
 * 
 * @implements Etpu_Pwm_Ip_GetLastInterrupt_Activity
 */
Etpu_Pwm_Ip_LastInterruptType Etpu_Pwm_Ip_GetLastInterrupt(Etpu_Pwm_Ip_InstanceType *pPwmInstance);

/**
 * @brief      This function stops PWM activity.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 *
 * @return     none
 * 
 * @implements Etpu_Pwm_Ip_Stop_Activity
 */
void Etpu_Pwm_Ip_Stop(Etpu_Pwm_Ip_InstanceType *pPwmInstance);

/**
 * @brief      This function stops PWM activity and sets pin to required state.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 * @param[in]  ePinState Required pin state while PWM is not active.
 *
 * @return     none
 * 
 * @implements Etpu_Pwm_Ip_StopAndSetPin_Activity
 */
void Etpu_Pwm_Ip_StopAndSetPin(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                               Etpu_Ip_PinStateType ePinState);

/**
 * @brief      This function starts PWM activity.
 *
 * @param[in]  pPwmInstance Pointer to the instance structure @ref Etpu_Pwm_InstanceType.
 *
 * @return     none
 * 
 * @implements Etpu_Pwm_Ip_Start_Activity
 */
void Etpu_Pwm_Ip_Start(Etpu_Pwm_Ip_InstanceType *pPwmInstance);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETPU_PWM_IP_H */
