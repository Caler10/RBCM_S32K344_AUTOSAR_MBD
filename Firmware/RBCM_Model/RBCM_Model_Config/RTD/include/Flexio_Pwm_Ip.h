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

#ifndef FLEXIO_PWM_IP_H
#define FLEXIO_PWM_IP_H

/**
*   @file Flexio_Pwm_Ip.h
*
*   @addtogroup flexio_pwm_ip FlexIO Pwm IPL
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
#include "Std_Types.h"
#include "Flexio_Pwm_Ip_Cfg.h"
#include "Flexio_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_VENDOR_ID                    43
#define FLEXIO_PWM_IP_MODULE_ID                    121
#define FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_SW_MAJOR_VERSION             5
#define FLEXIO_PWM_IP_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_VENDOR_ID != FLEXIO_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_SW_MAJOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_MINOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_PATCH_VERSION != FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_VENDOR_ID != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_SW_MAJOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_MINOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_PATCH_VERSION != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (FLEXIO_PWM_IP_USED == STD_ON)
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with base addresses for Flexio instances available on platform */
extern Flexio_Pwm_Ip_HwAddrType * const Flexio_Pwm_Ip_aBasePtr[FLEXIO_PWM_IP_INSTANCE_COUNT];

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

#if (FLEXIO_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/** @brief Array with pointers to user cfg structs*/
extern const Flexio_Pwm_Ip_ChannelConfigType * Flexio_Pwm_Ip_aState[FLEXIO_PWM_IP_CHANNEL_COUNT];

#if (FLEXIO_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

#if (FLEXIO_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_8
#endif
#include "Pwm_MemMap.h"

/** @brief Interrupt enable masks for used timers */
extern volatile uint8 Flexio_Pwm_Ip_u8TimerIrqMask;

#if (FLEXIO_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_8
#endif
#include "Pwm_MemMap.h"

#if (FLEXIO_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_32
#endif
#include "Pwm_MemMap.h"
#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON))
/** @brief Interrupt enable masks for used pins */
extern volatile uint32 Flexio_Pwm_Ip_u32PinIrqMask;
#endif
#if (FLEXIO_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_32
#endif
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief Initialize a flexio channel in pwm mode.
 * @details The function will initialize one timer and pin of the selected flexio channel in pwm
 * mode, with the configuration of the user. The interrupts will be disabled.
 *
 * @param[in] InstanceId   The Flexio instance id
 * @param[in] UserCfg      The channel configuration for the selected Flexio instance
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_InitChannel(uint8 InstanceId, const Flexio_Pwm_Ip_ChannelConfigType * const UserCfg);

/**
 * @brief Deinitialize a flexio channel.
 * @details The function will reset the timer and pin of the selected flexio channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the deinitialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_DeInitChannel(uint8 InstanceId, uint8 Channel);

#if (defined(FLEXIO_PWM_IP_HAS_PRESCALER) && (FLEXIO_PWM_IP_HAS_PRESCALER == STD_ON))
/**
 * @brief Set clock prescaler for a flexio channel
 * @details The function will change the prescaller value for the selected flexio channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @param[in] Prescaler     The new prescaler value
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_UpdateClockPrescaler(uint8 InstanceId, uint8 Channel, Flexio_Pwm_Ip_ClockPrescalerType Prescaler);
#endif /* (defined(FLEXIO_PWM_IP_HAS_PRESCALER) && (FLEXIO_PWM_IP_HAS_PRESCALER == STD_ON)) */

#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON))
/**
 * @brief Force the pin ouput to logic one or zero
 * @details The function will override the pin ouput of the selected flexio channel to the desired
 * logic level.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @param[in] Level         The logic level that the pin ouput should be set at.
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_ForceOuputLevel(uint8 InstanceId, uint8 Channel, boolean Level);
#endif /* (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON)) */

/**
 * @brief Set a new value for duty cycle and period of the channel.
 * @details The function will update the selected flexio channel with the new values for the
 * duty cycle and period.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @param[in] Period        The new value for the period
 * @param[in] DutyCycle     The new value for the duty cycle
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_UpdatePeriodDuty(uint8 InstanceId, uint8 Channel, uint16 Period, uint16 DutyCycle);

/**
 * @brief Get the logic level of the channel ouput.
 * @details The function will return the logic level that the selected flexio channel is driving on
 * on the output pin.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
boolean Flexio_Pwm_Ip_GetOutputState(uint8 InstanceId, uint8 Channel);

/**
 * @brief Update the interrupt mode for a channel.
 * @details The function will set a new mode for the flag event response on the selected channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @param[in] IrqMode       The new irq mode for the channel
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_UpdateInterruptMode(uint8 InstanceId, uint8 Channel, Flexio_Pwm_Ip_InterruptType IrqMode);

/**
 * @brief Getting the period for a channel.
 * @details The function will get the period on the selected channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance

 * @return uint16
 */
uint16 Flexio_Pwm_Ip_GetPeriod(uint8 InstanceId, uint8 Channel);

#endif /* FLEXIO_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_H */
