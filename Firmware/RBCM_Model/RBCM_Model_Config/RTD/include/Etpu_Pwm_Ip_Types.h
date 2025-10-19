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

#ifndef ETPU_PWM_IP_TYPES_H
#define ETPU_PWM_IP_TYPES_H

/**
 *   @file       Etpu_Pwm_Ip_Types.h
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
#include "Std_Types.h"
#include "Etpu_Pwm_Ip_CfgDefines.h"

#if (ETPU_PWM_IP_USED == STD_ON)
    #include "Etpu_Ip_Types.h"
    #include "Etpu_Pwm_Ip_Auto.h"
#endif /* ETPU_PWM_IP_USED == STD_ON */
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETPU_PWM_IP_TYPES_VENDOR_ID                     43
#define ETPU_PWM_IP_TYPES_MODULE_ID                     121
#define ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION      7
#define ETPU_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION   0
#define ETPU_PWM_IP_TYPES_SW_MAJOR_VERSION              5
#define ETPU_PWM_IP_TYPES_SW_MINOR_VERSION              0
#define ETPU_PWM_IP_TYPES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Etpu_Pwm_Ip_Types.h and Std_Types.h are different"
    #endif

    #if (ETPU_PWM_IP_USED == STD_ON)
        /* Check if header file and Etpu_Ip_Types.h header file are of the same AUTOSAR version */
        #if ((ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != ETPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
             (ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != ETPU_IP_TYPES_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Etpu_Pwm_Ip_Types.h and Etpu_Ip_Types.h are different."
        #endif

        /* Check if header file and Etpu_Pwm_Ip_Auto.h header file are of the same AUTOSAR version */
        #if ((ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != ETPU_PWM_IP_AUTO_AR_RELEASE_MAJOR_VERSION) || \
             (ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != ETPU_PWM_IP_AUTO_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Etpu_Pwm_Ip_Types.h and Etpu_Pwm_Ip_Auto.h are different."
        #endif
    #endif /* ETPU_PWM_IP_USED == STD_ON */
#endif

/* Check if header file and Etpu_Pwm_Ip_CfgDefines.h header file are of the same vendor */
#if (ETPU_PWM_IP_TYPES_VENDOR_ID != ETPU_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Etpu_Pwm_Ip_Types.h and Etpu_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_CfgDefines.h header file are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != ETPU_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != ETPU_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION != ETPU_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Etpu_Pwm_Ip_Types.h and Etpu_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Etpu_Pwm_Ip_CfgDefines.h header file are of the same software version */
#if ((ETPU_PWM_IP_TYPES_SW_MAJOR_VERSION != ETPU_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_TYPES_SW_MINOR_VERSION != ETPU_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_TYPES_SW_PATCH_VERSION != ETPU_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Etpu_Pwm_Ip_Types.h and Etpu_Pwm_Ip_CfgDefines.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief Possible polarity options of PWM.
 */
typedef enum
{
    /** @brief Active high polarity option */
    ETPU_PWM_POLARITY_ACTIVE_HIGH = ETPU_PWM_IP_FM0_ACTIVEHIGH,

    /** @brief Active low polarity option */
    ETPU_PWM_POLARITY_ACTIVE_LOW = ETPU_PWM_IP_FM0_ACTIVELOW
} Etpu_Pwm_Ip_PolarityType;

/**
 * @brief Possible time base options.
 */
typedef enum
{
    /** @brief TCR1 counter will be used as time base */
    ETPU_PWM_TIME_BASE_TCR1 = ETPU_PWM_IP_FM1_USE_TCR1,

    /** @brief TCR2 counter will be used as time base */
    ETPU_PWM_TIME_BASE_TCR2 = ETPU_PWM_IP_FM1_USE_TCR2
} Etpu_Pwm_Ip_TimeBaseType;

/**
 * @brief Possible start mode options.
 */
typedef enum
{
    /** @brief PWM starts at absolute counter value */
    ETPU_PWM_START_MODE_ABSOLUT = ETPU_PWM_IP_START_ABS_VALUE,

    /** @brief PWM starts at time delay from now (current counter value) */
    ETPU_PWM_START_MODE_DELAY = ETPU_PWM_IP_START_REL_OFFSET,

    /** @brief PWM starts at absolute counter value + reference time */
    ETPU_PWM_START_MODE_ABSOLUT_PLUS_REF = ETPU_PWM_IP_START_ABS_VALUE_PLUS_REF,

    /** @brief PWM starts at time delay + reference time from now (current counter value) */
    ETPU_PWM_START_MODE_DELAY_PLUS_REF = ETPU_PWM_IP_START_REL_OFFSET_PLUS_REF
} Etpu_Pwm_Ip_StartModeType;

/**
 * @brief Possible interrupt sources.
 */
typedef enum
{
    /** @brief Interrupt requests are disabled */
    ETPU_PWM_INTERRUPT_SOURCE_NONE = 0x00U,

    /** @brief Interrupt requests are generated on frame edge */
    ETPU_PWM_INTERRUPT_SOURCE_FRAME_EDGE = ETPU_PWM_IP_INTERRUPT_SOURCE_FRAME_EDGE,

    /** @brief Interrupt requests are generated on active edge */
    ETPU_PWM_INTERRUPT_SOURCE_ACTIVE_EDGE = ETPU_PWM_IP_INTERRUPT_SOURCE_ACTIVE_EDGE,

    /** @brief Interrupt requests are generated on both edges */
    ETPU_PWM_INTERRUPT_SOURCE_BOTH_EDGES = (ETPU_PWM_IP_INTERRUPT_SOURCE_FRAME_EDGE | ETPU_PWM_IP_INTERRUPT_SOURCE_ACTIVE_EDGE)
} Etpu_Pwm_Ip_InterruptSourceType;

/**
 * @brief Possible sources of generated interrupt.
 */
typedef enum
{
    /** @brief Interrupt generated by the frame edge (start edge of the period) */
    ETPU_PWM_LAST_INTERRUPT_FRAME_EDGE = ETPU_PWM_IP_LAST_IRQ_FRAME_EDGE,

    /** @brief Interrupt generated by the active edge (ending edge of the active state) */
    ETPU_PWM_LAST_INTERRUPT_ACTIVE_EDGE = ETPU_PWM_IP_LAST_IRQ_ACTIVE_EDGE
} Etpu_Pwm_Ip_LastInterruptType;

/**
 * @brief Possible Etpu PWM channel state options.
 */
typedef enum
{
    ETPU_PWM_UNINIT_STATE = 0U, /**< @brief Etpu PWM is un-initialized */
    ETPU_PWM_INIT_STATE   = 1U  /**< @brief Etpu PWM is initialized */
} Etpu_Pwm_Ip_StateType;

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (defined (ETPU_PWM_IP_NOTIFICATION_SUPPORT) && (ETPU_PWM_IP_NOTIFICATION_SUPPORT == STD_ON))
/**
 * @brief       Notification function callback type.
 */
typedef void (* Etpu_Pwm_Ip_CallbackType)(uint8 param);

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    Etpu_Pwm_Ip_CallbackType CbFunction;
    /** @brief Callback function parameter pointer */
    uint8 CbParameter;
} Etpu_Pwm_Ip_NotificationType;
#else
/**
 * @brief       Notification function callback type.
 */
typedef void (* Etpu_Pwm_Ip_CallbackType)(void * Param);

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    Etpu_Pwm_Ip_CallbackType CbFunction;
    /** @brief Callback function parameter pointer */
    void * CbParameter;
} Etpu_Pwm_Ip_NotificationType;
#endif

/**
 * @brief Pulse Width Modulation instance structure.
 */
typedef struct
{
    /** @brief Channel number: 0-31 for eTPU A and 64-95 for eTPU B */
    uint8 u8Channel;

    /** @brief Channel priority */
    Etpu_Ip_ChannelPrioType ePriority;

    /** @brief Polarity of PWM */
    Etpu_Pwm_Ip_PolarityType ePolarity;

    /** @brief Time base of PWM */
    Etpu_Pwm_Ip_TimeBaseType eTimebase;

    /** @brief Start mode of PWM */
    uint8 u8StartMode;

    /** @brief Value of start delay or absolute counter value */
    Etpu_Ip_Uint24Type u24StartDelay;

    /** @brief Pointer to address which contains the value of time added to time delay */
    uint32 *pRefAddress;

    /**
     * @brief Channel parameter base address
     *
     * @note  Set Cpba = 0 to use automatic allocation of eTPU DATA RAM for
     *        channel parameters using the eTPU utility function Etpu_Ip_Malloc2
     *        (recommended), or assign the Cpba manually by an address where the
     *        channel parameter space will start from, e.g. 0xC3FC8100.
     */
    uint32 *pCpba;

    /** @brief Interrupt callback */
    Etpu_Pwm_Ip_NotificationType UserCallback;
} Etpu_Pwm_Ip_InstanceType;

/**
 * @brief PWM configuration structure.
 * @note  It includes PWM configuration items which can mostly be changed during run-time.
 */
typedef struct
{
    /** @brief Period of PWM in counter ticks, the range of this parameter is 0 - 0x007FFFFF. */
    Etpu_Ip_Uint24Type u24Period;

    /** @brief Duty cycle of PWM, the range of this parameter is 0 - 0x8000. */
    uint16 u16DutyCycle;

    /** @brief Interrupt source */
    Etpu_Pwm_Ip_InterruptSourceType eInterruptSource;
} Etpu_Pwm_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETPU_PWM_IP_TYPES_H */
