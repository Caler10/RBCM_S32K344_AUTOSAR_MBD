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

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
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
#include "SchM_Icu.h"
#include "Std_Types.h"
#include "Siul2_Icu_Ip.h"
#include "Siul2_Icu_Ip_Irq.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IRQ_VENDOR_ID_C                      43
#define SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define SIUL2_ICU_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define SIUL2_ICU_IRQ_SW_MAJOR_VERSION_C               5
#define SIUL2_ICU_IRQ_SW_MINOR_VERSION_C               0
#define SIUL2_ICU_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and Std_Types.h are different"
    #endif

    /* Check if header file and SchM_Icu.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and SchM_Icu.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IRQ_VENDOR_ID_C != SIUL2_ICU_IP_VENDOR_ID)
    #error "Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IRQ_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IRQ_VENDOR_ID_C != SIUL2_ICU_IP_IRQ_VENDOR_ID)
    #error "Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip_Irq.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IRQ_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip_Irq.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IRQ_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_IRQ_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_IRQ_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IRQ_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_Irq.c and Siul2_Icu_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                    GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"


/**
* @brief      This function will handle the group interrupt
*
* @param[in]  instance  - Siul2 module index
* @param[in]  firstHwChannel  - the first Siul2 hardware channel index in a group interrupt
*/
#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
static inline void Siul2_Icu_Ip_ProcessInterrupt(uint8 instance, uint8 firstHwChannel);
#endif

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED) || \
     (defined SIUL2_0_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_1_ICU_EIRQ_SINGLE_INT) || \
     (defined SIUL2_4_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_5_ICU_EIRQ_SINGLE_INT) || \
     (defined SIUL2_AE_ICU_EIRQ_SINGLE_INT))
/**
 * @brief This function will handle the event interrupt.
 *
 * @param instance  : Siul2 module index
 * @param channel   : Siul2 encoded hardware channel
 */
static inline void Siul2_Icu_Ip_ReportEvents(uint8 instance, uint8 hwChannel);
#endif
/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED)  || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
/** @implements Siul2_Icu_Ip_ProcessInterrupt_Activity */
static inline void Siul2_Icu_Ip_ProcessInterrupt(uint8 instance, uint8 firstHwChannel)
{
    SIUL2_Type* base;
    uint8  u8IrqChannel;
    uint32 u32RegIrqMask   = (uint32)0xFFU << (uint32)firstHwChannel;
    uint32 u32ChannelMask  = (uint32)1U << (uint32)firstHwChannel;
    uint32 u32RegFlags;
    uint32 u32RegIrqEn;
    
#if(SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT == STD_ON)
    base = Siul2_Icu_Ip_apxBase[instance][Siul2_Icu_Ip_au8InterruptPdacSlot[instance]];
#else
    base = Siul2_Icu_Ip_apxBase[instance];
#endif
    
    u32RegFlags = base->DISR0;
    u32RegIrqEn = base->DIRER0;

    /* Select which channels will be serviced - only the enabled irq ones*/
    u32RegIrqMask = u32RegFlags & u32RegIrqEn & u32RegIrqMask;

    for (u8IrqChannel = (uint8)firstHwChannel; u8IrqChannel < (uint8)(firstHwChannel + 8U); u8IrqChannel++)
    {
        if (0x0U != (u32RegIrqMask & u32ChannelMask))
        {
            /* Clear pending interrupt serviced */
            base->DISR0 = u32RegFlags & u32ChannelMask;

            Siul2_Icu_Ip_ReportEvents(instance, u8IrqChannel);
        }
        u32ChannelMask <<= (uint32)1U;
    }
}
#endif

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED)  || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) \
    || (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED) \
    || (defined SIUL2_0_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_1_ICU_EIRQ_SINGLE_INT) \
    || (defined SIUL2_4_ICU_EIRQ_SINGLE_INT) || (defined SIUL2_5_ICU_EIRQ_SINGLE_INT) \
    || (defined SIUL2_AE_ICU_EIRQ_SINGLE_INT))
static inline void Siul2_Icu_Ip_ReportEvents(uint8 instance, uint8 hwChannel)
{
    uint8 u8ChIndex = Siul2_Icu_Ip_au8IndexInChState[instance][hwChannel];

    /* Calling HLD Report Events for the logical channel. */
    if (Siul2_Icu_Ip_axChannelState[u8ChIndex].callback != NULL_PTR)
    {
        Siul2_Icu_Ip_axChannelState[u8ChIndex].callback(Siul2_Icu_Ip_axChannelState[u8ChIndex].callbackParam, FALSE);
    }
    else
    {
        /* Calling Notification for the IPL channel. */
        if ((NULL_PTR != Siul2_Icu_Ip_axChannelState[u8ChIndex].Siul2ChannelNotification) && \
            ((boolean)TRUE == Siul2_Icu_Ip_axChannelState[u8ChIndex].notificationEnable))
        {
            Siul2_Icu_Ip_axChannelState[u8ChIndex].Siul2ChannelNotification();
        }
    }
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if ((defined SIUL2_ICU_IRQ_CH_0_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_1_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_2_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_3_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_4_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_5_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_6_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_7_ISR_USED))
ISR(SIUL2_EXT_IRQ_0_7_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_0);
}
#endif  /* IRQ 0 - 7 */

#if ((defined SIUL2_ICU_IRQ_CH_8_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_9_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_10_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_11_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_12_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_13_ISR_USED) ||\
     (defined SIUL2_ICU_IRQ_CH_14_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_15_ISR_USED))
ISR(SIUL2_EXT_IRQ_8_15_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_8);
}
#endif  /* IRQ 8 - 15 */

#if ((defined SIUL2_ICU_IRQ_CH_16_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_17_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_18_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_19_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_20_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_21_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_22_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_23_ISR_USED))
ISR(SIUL2_EXT_IRQ_16_23_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_16);
}
#endif

#if ((defined SIUL2_ICU_IRQ_CH_24_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_25_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_26_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_27_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_28_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_29_ISR_USED) || \
     (defined SIUL2_ICU_IRQ_CH_30_ISR_USED) || (defined SIUL2_ICU_IRQ_CH_31_ISR_USED))
ISR(SIUL2_EXT_IRQ_24_31_ISR)
{
    /*implement IRQ for the instance 0*/
    Siul2_Icu_Ip_ProcessInterrupt(0U, SIUL2_ICU_IRQ_24);
}
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */
