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

#ifndef PWM_IPW_TYPES_H
#define PWM_IPW_TYPES_H

/**
*   @file       Pwm_Ipw_Types.h
*
*   @internal
*   @addtogroup pwm_driver Pwm Driver
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
#include "Pwm_Ipw_Cfg.h"
#if (PWM_EMIOS_USED == STD_ON)
#include "Emios_Pwm_Ip.h"
#endif

#if (PWM_FLEXIO_USED == STD_ON)
    #include "Flexio_Pwm_Ip_Types.h"
#endif

#if (PWM_FLEXPWM_USED == STD_ON)
#include "FlexPwm_Ip.h"
#endif

#if (PWM_ETPU_USED == STD_ON)
#include "Etpu_Pwm_Ip.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_IPW_TYPES_VENDOR_ID                         43
#define PWM_IPW_TYPES_MODULE_ID                         121
#define PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION          7
#define PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION       0
#define PWM_IPW_TYPES_SW_MAJOR_VERSION                  5
#define PWM_IPW_TYPES_SW_MINOR_VERSION                  0
#define PWM_IPW_TYPES_SW_PATCH_VERSION                  0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Pwm_Ipw_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Pwm_Ipw_Cfg header file are of the same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_IPW_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw_Types.h and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if header file and Pwm_Ipw_Cfg header file are of the same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION != PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Types.h and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if header file and Pwm_Ipw_Cfg header file are of the same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION != PWM_IPW_CFG_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION != PWM_IPW_CFG_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION != PWM_IPW_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Types.h and Pwm_Ipw_Cfg.h are different."
#endif

#if (PWM_EMIOS_USED == STD_ON)
    /* Check if header file and Emios_Pwm_Ip header file are of the same vendor */
    #if (PWM_IPW_TYPES_VENDOR_ID != EMIOS_PWM_IP_VENDOR_ID)
        #error "Vendor IDs of Pwm_Ipw_Types.h and Emios_Pwm_Ip.h are different."
    #endif

    /* Check if header file and Emios_Pwm_Ip header file are of the same AUTOSAR version */
    #if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
         (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR version numbers of Pwm_Ipw_Types.h and Emios_Pwm_Ip.h are different."
    #endif

    /* Check if header file and Emios_Pwm_Ip header file are of the same software version */
    #if ((PWM_IPW_TYPES_SW_MAJOR_VERSION != EMIOS_PWM_IP_SW_MAJOR_VERSION) || \
         (PWM_IPW_TYPES_SW_MINOR_VERSION != EMIOS_PWM_IP_SW_MINOR_VERSION) || \
         (PWM_IPW_TYPES_SW_PATCH_VERSION != EMIOS_PWM_IP_SW_PATCH_VERSION))
        #error "Software version numbers of Pwm_Ipw_Types.h and Emios_Pwm_Ip.h are different."
    #endif
#endif

#if (PWM_FLEXIO_USED == STD_ON)
    /* Check if header file and Flexio_Pwm_Ip header file are of the same vendor */
    #if (PWM_IPW_TYPES_VENDOR_ID != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
        #error "Vendor IDs of Pwm_Ipw_Types.h and Flexio_Pwm_Ip_Types.h are different."
    #endif

    /* Check if header file and Flexio_Pwm_Ip header file are of the same AUTOSAR version */
    #if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
         (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR version numbers of Pwm_Ipw_Types.h and Flexio_Pwm_Ip_Types.h are different."
    #endif

    /* Check if header file and Flexio_Pwm_Ip header file are of the same software version */
    #if ((PWM_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
         (PWM_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
         (PWM_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
        #error "Software version numbers of Pwm_Ipw_Types.h and Flexio_Pwm_Ip_Types.h are different."
    #endif
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
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        Defines state of PWM channel
* @details      PWM_EMIOS_ACTIVE   - The PWM pin will be in the same state of configured polarity
*               PWM_EMIOS_INACTIVE - The PWM pin will be in the opposite state of configured polarity
*/
typedef enum
{
    PWM_EMIOS_ACTIVE = 0,
    PWM_EMIOS_INACTIVE
} Pwm_StateType;
#endif

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief     Defines enum for a type of instance
* @details   IPW type used to identify pointer to instance configuration.
*
*/
typedef enum
{
    /** @brief  No instance type */
    PWM_INSTANCE_NONE   = 0x00U,
    /** @brief  Ip instance configured is Emios */
    PWM_INSTANCE_EMIOS  = 0x01U,
    /** @brief  Ip instance configured is Flexio */
    PWM_INSTANCE_FLEXIO = 0x02U,
    /** @brief  Ip instance configured is FlexPwm */
    PWM_INSTANCE_FLEXPWM  = 0x03U
} Pwm_IpwHwInstanceType;
#endif

/**
* @brief        Defines enum for a type of channel
* @details      IPW type used to identify a hardware channel
*
*/
typedef enum
{
    /** @brief  No channel type */
    PWM_CHANNEL_NONE                = 0x00U,
    /** @brief  Channel type is Emios */
    PWM_CHANNEL_EMIOS               = 0x01U,
    /** @brief  Channel type is FlexPwm */
    PWM_CHANNEL_FLEXPWM             = 0x02U,
#if (PWM_FLEXIO_USED == STD_ON)
    /** @brief  Channel type is Flexio */
    PWM_CHANNEL_FLEXIO              = 0x03U,
#endif
    PWM_CHANNEL_ETPU                = 0x04U
} Pwm_IpwHwChannelType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief        PWM instance type
*/
typedef uint8 Pwm_IpwInstanceType;

/**
* @internal
* @brief      Defines struct for a hardware channel
* @details    IPW type used to implement a PWM channel
*
*/
typedef struct
{
    /** @brief  The type of ip channel configured */
    const Pwm_IpwHwChannelType               ChannelType;
#if (PWM_EMIOS_USED == STD_ON)
    /** @brief  Pointer to the Emios ip channel configuration structure */
    const Emios_Pwm_Ip_ChannelConfigType   * EmiosChConfig;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
    /** @brief  Pointer to the Flexio ip channel configuration structure */
    const Flexio_Pwm_Ip_ChannelConfigType  * FlexioChConfig;
    /** @brief  Alternate Clock for flexio channel */
    const Flexio_Pwm_Ip_ClockPrescalerType   FlexioAlternateClk;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    /** @brief  Pointer to the FlexPwm ip channel configuration structure */
    const FlexPwm_Ip_ChannelCfgTypes       * FlexPwmChConfig;
    /** @brief SubModule id for this channel */
    const uint8                              SubModuleId;
#endif
#if (PWM_ETPU_USED == STD_ON)
    /** @brief  Pointer to the Etpu_Pwm ip channel instance structure */
    const Etpu_Pwm_Ip_InstanceType         * EtpuPwmInstance;
    /** @brief  Pointer to the Etpu_Pwm ip channel configuration structure */
    const Etpu_Pwm_Ip_ConfigType           * EtpuChConfig;
#endif
    /** @brief Instance id for this channel */
    const Pwm_IpwInstanceType                ChannelInstanceId;
    /** @brief The duty cycle of this channel */
    const uint16                             ChannelDutyCycle;
} Pwm_IpwChannelConfigType;

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @internal
* @brief          Defines struct for a hardware instance
* @details        IPW type used to implement a PWM HW instance configuration.
*
*/
typedef struct
{
    /** @brief  The Id instance configured */
    uint8                                 InstanceId;
    /** @brief  The type of ip instance configured */
    const Pwm_IpwHwInstanceType           InstanceType;
#if (PWM_FLEXPWM_USED == STD_ON)
    /** @brief  Pointer to the ip instance configuration structure */
    const FlexPwm_Ip_InstanceCfgTypes    * FlexPwmInsConfig;
#endif
} Pwm_IpwInstanceConfigType;
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_IPW_TYPES_H */
