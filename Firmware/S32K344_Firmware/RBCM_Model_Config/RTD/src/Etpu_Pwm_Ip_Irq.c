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

/**
 *   @file       Etpu_Pwm_Ip_Irq.c
 *
 *   @addtogroup etpu_pwm_driver
 *   @brief      This file contains API for using the eTPU function Pulse Width Modulation (PWM).
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
#include "Mcal.h"
#include "Etpu_Pwm_Ip_Irq.h"
#include "Etpu_Pwm_Ip_Cfg.h"
#include "Etpu_Pwm_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETPU_PWM_IP_IRQ_VENDOR_ID_C                     43
#define ETPU_PWM_IP_IRQ_MODULE_ID_C                     121
#define ETPU_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C      4
#define ETPU_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C      7
#define ETPU_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C   0
#define ETPU_PWM_IP_IRQ_SW_MAJOR_VERSION_C              5
#define ETPU_PWM_IP_IRQ_SW_MINOR_VERSION_C              0
#define ETPU_PWM_IP_IRQ_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Mcal.h are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Etpu_Pwm_Ip_Irq.c and Mcal.h are different"
#endif

/* Check if Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip_Cfg.h are of the same vendor */
#if (ETPU_PWM_IP_IRQ_VENDOR_ID_C != ETPU_PWM_IP_CFG_VENDOR_ID)
#error "Vendor IDs of Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip_Cfg.h are different."
#endif

/* Check if Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip_Cfg.h are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C  != ETPU_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != ETPU_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != ETPU_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR version numbers of Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip_Cfg.h are different."
#endif

/* Check if Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip_Cfg.h are of the same software version */
#if ((ETPU_PWM_IP_IRQ_SW_MAJOR_VERSION_C != ETPU_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_SW_MINOR_VERSION_C != ETPU_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_SW_PATCH_VERSION_C != ETPU_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
#error "Software version numbers of Eptu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip.h are of the same vendor */
#if (ETPU_PWM_IP_IRQ_VENDOR_ID_C != ETPU_PWM_IP_VENDOR_ID)
#error "Vendor IDs of Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_IpEtpu_Pwm_Ip.h are different."
#endif

/* Check if Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip.h are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR version numbers of Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip.h are different."
#endif

/* Check if Etpu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip.h are of the same software version */
#if ((ETPU_PWM_IP_IRQ_SW_MAJOR_VERSION_C != ETPU_PWM_IP_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_SW_MINOR_VERSION_C != ETPU_PWM_IP_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_IRQ_SW_PATCH_VERSION_C != ETPU_PWM_IP_SW_PATCH_VERSION))
#error "Software version numbers of Eptu_Pwm_Ip_Irq.c and Etpu_Pwm_Ip.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/** @brief Convert channel number expressed by (engine, channel) to absolute channel number. */
#define ETPU_PWM_IP_ENGINE_CHANNEL(engine, channel) (((engine) * 64U) + (channel))

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

void Etpu_Pwm_Ip_IrqHandler(Etpu_Ip_EngineType Engine, uint8 Channel)
{
    if ((ETPU_PWM_UNINIT_STATE == aEtpu_Pwm_Ip_ModuleState[(uint8)Engine][Channel]) &&
        ((uint8)1U == Etpu_Ip_GetChannelInterruptFlag((uint8)ETPU_PWM_IP_ENGINE_CHANNEL((uint8)Engine, Channel))))
    {
        /* Clear interrupt flag */
        Etpu_Ip_ClearChannelInterruptFlag((uint8)ETPU_PWM_IP_ENGINE_CHANNEL((uint8)Engine, Channel));
    }
    else
    {
        /*Interrupt Flag and Interrupt Enable is set*/
        if ((TRUE == Etpu_Ip_GetInterruptEnableBit((uint8)ETPU_PWM_IP_ENGINE_CHANNEL((uint8)Engine, Channel))) &&
            ((uint8)1U == Etpu_Ip_GetChannelInterruptFlag((uint8)ETPU_PWM_IP_ENGINE_CHANNEL((uint8)Engine, Channel))))
        {
            /* Clear interrupt flag */
            Etpu_Ip_ClearChannelInterruptFlag((uint8)ETPU_PWM_IP_ENGINE_CHANNEL((uint8)Engine, Channel));

            if ((NULL_PTR != aEtpu_Pwm_Ip_NotificationPtr[Engine][Channel]->CbFunction) && (0x00U != aEtpu_Pwm_Ip_DutyCycle[(uint8)Engine][Channel])
                && (aEtpu_Pwm_Ip_DutyCycle[(uint8)Engine][Channel] != aEtpu_Pwm_Ip_Period[(uint8)Engine][Channel]))
            {
                /* Call the user notification callback with the provided parameter */
                (aEtpu_Pwm_Ip_NotificationPtr[(uint8)Engine][Channel]->CbFunction)(aEtpu_Pwm_Ip_NotificationPtr[(uint8)Engine][Channel]->CbParameter);
            }
        }
    }
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
