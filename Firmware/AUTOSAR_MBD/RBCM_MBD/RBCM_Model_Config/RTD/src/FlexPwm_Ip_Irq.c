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
*     @file         FlexPwm_Ip_Irq.c
*
*     @addtogroup flexpwm_ip IPL Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexPwm_Ip.h"
#include "FlexPwm_Ip_Irq.h"
#include "FlexPwm_Ip_HwAccess.h"
#include "Mcal.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_IRQ_VENDOR_ID_C                      43
#define FLEXPWM_IP_IRQ_MODULE_ID_C                      121
#define FLEXPWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXPWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXPWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXPWM_IP_IRQ_SW_MAJOR_VERSION_C               5
#define FLEXPWM_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXPWM_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip_Irq.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and FlexPwm_Ip_HwAccess.h file are of the same vendor */
#if (FLEXPWM_IP_IRQ_VENDOR_ID_C != FLEXPWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Irq.c and FlexPwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and FlexPwm_Ip_HwAccess.h file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Irq.c and FlexPwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and FlexPwm_Ip_HwAccess.h file are of the same Software version */
#if ((FLEXPWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXPWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
     (FLEXPWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXPWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
     (FLEXPWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXPWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Irq.c and FlexPwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Irq.h file are of the same vendor */
#if (FLEXPWM_IP_IRQ_VENDOR_ID_C != FLEXPWM_IP_IRQ_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Irq.c and FlexPwm_Ip_Irq.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Irq.h file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Irq.c and FlexPwm_Ip_Irq.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Irq.h file are of the same Software version */
#if ((FLEXPWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXPWM_IP_IRQ_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXPWM_IP_IRQ_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXPWM_IP_IRQ_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Irq.c and FlexPwm_Ip_Irq.h are different."
#endif

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#if (FLEXPWM_IP_AVAILABLE == STD_ON)

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if ((defined FLEXPWM_IP_INS_0_SUBMOD_0_ISR_USED) || \
     (defined FLEXPWM_IP_INS_0_SUBMOD_1_ISR_USED) || \
     (defined FLEXPWM_IP_INS_0_SUBMOD_2_ISR_USED) || \
     (defined FLEXPWM_IP_INS_0_SUBMOD_3_ISR_USED) || \
     (defined FLEXPWM_IP_INS_1_SUBMOD_0_ISR_USED) || \
     (defined FLEXPWM_IP_INS_1_SUBMOD_1_ISR_USED) || \
     (defined FLEXPWM_IP_INS_1_SUBMOD_2_ISR_USED) || \
     (defined FLEXPWM_IP_INS_1_SUBMOD_3_ISR_USED) || \
     (defined FLEXPWM_IP_INS_2_SUBMOD_0_ISR_USED) || \
     (defined FLEXPWM_IP_INS_2_SUBMOD_1_ISR_USED) || \
     (defined FLEXPWM_IP_INS_2_SUBMOD_2_ISR_USED) || \
     (defined FLEXPWM_IP_INS_2_SUBMOD_3_ISR_USED))
/**
* @brief        This function is a interrupt service routine used to process compare events
*               for each FlexPWM submodule
*
* @param        Instance            Hardware FlexPWM module index
*               Submodule           Hardware FlexPWM submodule index
*
* @return       void
* @implements FlexPwm_Ip_ProcessCompareIrq_Activity
*/
void FlexPwm_Ip_ProcessCompareIrq(uint8 Instance, uint8 SubModule)
{

    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8  Status;
    uint8  ChannelIdx;
    uint8  UniqueSub;
    uint8  ChInterruptEnStatus;
    /* Read status register and get CMPF bit field only for the 3 channels in submodule that had interrupts enabled */
    Status = FlexPwm_Ip_GetInterruptCmpFlagHw(Base, SubModule);
    
    /* Keep in Status variable only flags of enabled interrupts */
    Status &= FlexPwm_Ip_GetInterrupteCmpEnHw(Base, SubModule);

    /* Check the state of submodules is uninitialized state */
    if(((FlexPwm_Ip_StateTypes)FLEXPWM_IP_UNINIT_STATE == FlexPwm_Ip_aSubModuleSate[Instance][SubModule]) && (0x00U != FlexPwm_Ip_GetInterruptCmpFlagHw(Base, SubModule)))
    {
        /* Clear interrupt flags */
        FlexPwm_Ip_ClearInterruptCmpFlagHw(Base, SubModule, Status);
    }
    else
    {
        /* Check if interrupt flags and interrupts enabled for this submodules are set */
        if (0x00U != Status)
        {
            /* Clear interrupt flags */
            FlexPwm_Ip_ClearInterruptCmpFlagHw(Base, SubModule, Status);
            
            /* Check all hardware channels of the submodule for possible interrupt generation */
            for (ChannelIdx = (uint8)0U; ChannelIdx < FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8; ChannelIdx++)
            {
                UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + ChannelIdx);
                ChInterruptEnStatus = ((Status >> (2U * ChannelIdx)) & 3U);
                if ((NULL_PTR != FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbFunction) && (0x00U != ChInterruptEnStatus) \
                     && (0x00U != FlexPwm_Ip_aDutyCycle[Instance][UniqueSub]) && (FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] != FlexPwm_Ip_aPeriod[Instance][SubModule]))
                {
#if ((defined FLEXPWM_IP_NOTIFICATION_SUPPORT_HLD) && (FLEXPWM_IP_NOTIFICATION_SUPPORT_HLD == STD_ON))
                    (FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbFunction)(FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbParameter);
#else    
                     /* Avoid compiler warning */
                    (FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbFunction)(FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbParameter);
#endif
                }
            }
        }
    }
}
#endif

#if (defined FLEXPWM_IP_FAULT_ISR_USED)
/**
* @brief        This function is a interrupt service routine used to process fault events
*               for all FlexPWM modules
*
* @param        void
*
* @return       void
*
*/
void FlexPwm_Ip_ProcessFaultIrq(void)
{
    FlexPwm_Ip_HwAddrType *Base;
    uint8  Status;
    uint8  FaultChannel;
    uint8  ModuleIdx = (uint8)0U;

    /* Loop all FlexPWM modules */
    for (ModuleIdx = (uint8)0U; ModuleIdx < (uint8)FLEXPWM_IP_INSTANCE_COUNT_U8; ModuleIdx++)
    {
        Base =  FlexPwm_Ip_aBasePtr[ModuleIdx];

        /* Read status register and get only FFLAG bit field for all 4 channels of current module that had interrupts enabled */
        Status = FlexPwm_Ip_GetFltIntFlagHw(Base);

        /* Keep in Status variable only flags of enabled interrupts */
        Status &= FlexPwm_Ip_GetFltIntEnHw(Base);

        /* Check the state of instance is uninitialized state */
        if(((FlexPwm_Ip_StateTypes)FLEXPWM_IP_UNINIT_STATE == FlexPwm_Ip_aInstanceSate[ModuleIdx]) && (0x00U != FlexPwm_Ip_GetFltIntFlagHw(Base)))
        {
            /* Clear interrupt flags */
            FlexPwm_Ip_ClearFaultFlagHw(Base, Status);
        }
        else
        {
            /* Check if interrupt flags and interrupts enabled for this instance are set */
            if (0x00U != Status)
            {
                /* Clear interrupt flags */
                FlexPwm_Ip_ClearFaultFlagHw(Base, Status);
    
                /* If FlexPwm IP is configured, loop through all fault channels and call the notification handler */
                for (FaultChannel = (uint8)0U; FaultChannel < FLEXPWM_IP_FAULT_CHANNELS_NO_U8; FaultChannel++)
                {
                    /* Check all 4 fault channels for possible interrupt generation */
                    if (0x00U != (Status & ((uint8)1U << FaultChannel)))
                    {
                        /* Call notification if pointer not NULL */
                        if (NULL_PTR != FlexPwm_Ip_aFaultIrqCallback[ModuleIdx][FaultChannel])
                        {
                            FlexPwm_Ip_aFaultIrqCallback[ModuleIdx][FaultChannel]();
                        }
                    }
                }
            }
        }
    }
}
#endif

#ifdef FLEXPWM_IP_INS_0_SUBMOD_0_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 0 submodule 0
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_0_SUBMOD_0_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_0, FLEXPWM_IP_SUBMOD_0);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_0_SUBMOD_0_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_0_SUBMOD_1_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 0 submodule 1
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_0_SUBMOD_1_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_0, FLEXPWM_IP_SUBMOD_1);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_0_SUBMOD_1_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_0_SUBMOD_2_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 0 submodule 2
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_0_SUBMOD_2_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_0, FLEXPWM_IP_SUBMOD_2);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_0_SUBMOD_2_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_0_SUBMOD_3_ISR_USED
/**
* @brief          Interrupt handler for FlexPwm channel
* @details        Process the interrupt of FlexPWM 0 submodule 3
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_0_SUBMOD_3_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_0, FLEXPWM_IP_SUBMOD_3);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_0_SUBMOD_3_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_1_SUBMOD_0_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 1 submodule 0
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_1_SUBMOD_0_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_1, FLEXPWM_IP_SUBMOD_0);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_1_SUBMOD_0_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_1_SUBMOD_1_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 1 submodule 1
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_1_SUBMOD_1_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_1, FLEXPWM_IP_SUBMOD_1);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_1_SUBMOD_1_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_1_SUBMOD_2_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 1 submodule 2
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_1_SUBMOD_2_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_1, FLEXPWM_IP_SUBMOD_2);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_1_SUBMOD_2_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_1_SUBMOD_3_ISR_USED
/**
* @brief          Interrupt handler for FlexPwm channel
* @details        Process the interrupt of FlexPWM 1 submodule 3
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_1_SUBMOD_3_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_1, FLEXPWM_IP_SUBMOD_3);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_1_SUBMOD_3_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_2_SUBMOD_0_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 2 submodule 0
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_2_SUBMOD_0_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_2, FLEXPWM_IP_SUBMOD_0);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_2_SUBMOD_0_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_2_SUBMOD_1_ISR_USED
/**
* @brief          Interrupt handler for FlexPwm channel
* @details        Process the interrupt of FlexPWM 2 submodule 1
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_2_SUBMOD_1_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_2, FLEXPWM_IP_SUBMOD_1);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_2_SUBMOD_1_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_2_SUBMOD_2_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 2 submodule 2
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_2_SUBMOD_2_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_2, FLEXPWM_IP_SUBMOD_2);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_2_SUBMOD_2_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_INS_2_SUBMOD_3_ISR_USED
/**
* @brief        Interrupt handler for FlexPwm channel
* @details      Process the interrupt of FlexPWM 2 submodule 3
*
* @isr
*
*/
ISR(FLEXPWM_IP_INS_2_SUBMOD_3_CMP_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessCompareIrq(FLEXPWM_IP_INS_2, FLEXPWM_IP_SUBMOD_3);
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_INS_2_SUBMOD_3_ISR_USED */

/*===============================================================================================*/
#ifdef FLEXPWM_IP_FAULT_ISR_USED
/**
* @brief          Interrupt handler for FlexPWM Fault functionality
* @details        Process the interrupt of FlexPWM Fault pins
*
* @isr
*
*/
ISR(FLEXPWM_IP_FAULT_ISR)
{
    /* Interrupt handler */
    FlexPwm_Ip_ProcessFaultIrq();
    EXIT_INTERRUPT();
}
#endif /* FLEXPWM_IP_FAULT_ISR_USED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* FLEXPWM_IP_AVAILABLE */

#ifdef __cplusplus
}

/** @} */

#endif
