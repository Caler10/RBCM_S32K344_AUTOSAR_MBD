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
*   @file Flexio_Pwm_Ip_Irq.c
*
*   @addtogroup flexio_pwm_ip_irq FlexIO Pwm IPL
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
#include "Flexio_Pwm_Ip_Irq.h"
#include "Flexio_Pwm_Ip.h"
#include "Flexio_Pwm_Ip_HwAccess.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_IRQ_VENDOR_ID_C                      43
#define FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C               5
#define FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Flexio_Pwm_Ip_Irq.h file are of the same vendor */
#if (FLEXIO_PWM_IP_IRQ_VENDOR_ID_C != FLEXIO_PWM_IP_IRQ_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_Irq.h file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_Irq.h file are of the same Software version */
#if ((FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same vendor */
#if (FLEXIO_PWM_IP_IRQ_VENDOR_ID_C != FLEXIO_PWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same Software version */
#if ((FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip.h file are of the same vendor */
#if (FLEXIO_PWM_IP_IRQ_VENDOR_ID_C != FLEXIO_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip.h file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip.h file are of the same Software version */
#if ((FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_SW_MAJOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_SW_MINOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip.h are different."
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

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
#if (FLEXIO_PWM_IP_USED == STD_ON)
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 *
 * Function Name : Flexio_Pwm_Ip_IrqHandler
 * Description   : Flexio Pwm Interrupt Request handler
 * The function will determine the type of interrupt that occurred and call the user
 * callback.
 *
 * @implements Flexio_Pwm_Ip_IrqHandler_Activity
 */
void Flexio_Pwm_Ip_IrqHandler(uint8 ChannelId,
                              uint8 TimerFlags
#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON))
                              , 
                              uint32 PinFlags
#endif
                              )
{
#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON))
    Flexio_Pwm_Ip_OccurredIRQType IrqType = FLEXIO_PWM_IP_PIN_RISING_EDGE_IRQ;
    boolean PinState = Flexio_Pwm_Ip_GetPinState(
                                            Flexio_Pwm_Ip_aBasePtr[0U],
                                            Flexio_Pwm_Ip_aState[ChannelId]->PinId);
    
    /* Check if it is a pin interrupt */
    if ((PinFlags & Flexio_Pwm_Ip_u32PinIrqMask & (1U << Flexio_Pwm_Ip_aState[ChannelId]->PinId)) != 0U)
    {
        if(NULL_PTR != Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbFunction)
        {
            if (TRUE ==  PinState)
            {
                /* The Pin falling edge occurred */
                IrqType = FLEXIO_PWM_IP_PIN_FALLING_EDGE_IRQ;
            }
            else
            {
                /* The Pin falling edge occurred */
                IrqType = FLEXIO_PWM_IP_PIN_RISING_EDGE_IRQ;
            }
            Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbFunction(
                                        IrqType,
                                        Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbParameter);
        }
        else
        {
            if(NULL_PTR != Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbFunction)
            {
                Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbFunction(
                            Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbParameter);
            }
        }
    }
#endif
    /* Find what type of interrupt occurred */
    if ((TimerFlags & Flexio_Pwm_Ip_u8TimerIrqMask & (1U << Flexio_Pwm_Ip_aState[ChannelId]->TimerId)) != 0U)
    {
        if(NULL_PTR != Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbFunction)
        {
            /* The timer end of period occurred */
            Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbFunction(
                                        FLEXIO_PWM_IP_TIMER_IRQ,
                                        Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbParameter);
        }
        else
        {
            if(NULL_PTR != Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbFunction)
            {
                Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbFunction(
                            Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbParameter);
            }
        }
    }

    (void)TimerFlags;
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* FLEXIO_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
