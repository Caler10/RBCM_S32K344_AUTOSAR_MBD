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
 *     @file Cmp_Ip.c
 *
 *     @addtogroup cmp_icu_ip CMP IPL
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
#include "Std_Types.h"
#include "Cmp_Ip.h"

#if (STD_ON == CMP_IP_USED)
    #if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
        #include "Devassert.h"
    #endif /* CMP_IP_DEV_ERROR_DETECT == STD_ON */
#endif /* CMP_IP_USED */

#include "SchM_Icu.h"
#include "Mcal.h"

/*==================================================================================================
*                                         SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CMP_IP_VENDOR_ID_C                     43
#define CMP_IP_AR_RELEASE_MAJOR_VERSION_C      4
#define CMP_IP_AR_RELEASE_MINOR_VERSION_C      7
#define CMP_IP_AR_RELEASE_REVISION_VERSION_C   0
#define CMP_IP_SW_MAJOR_VERSION_C              5
#define CMP_IP_SW_MINOR_VERSION_C              0
#define CMP_IP_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (CMP_IP_VENDOR_ID_C != CMP_IP_VENDOR_ID)
    #error "Cmp_Ip.c and Cmp_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C  != CMP_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CMP_IP_AR_RELEASE_MINOR_VERSION_C  != CMP_IP_AR_RELEASE_MINOR_VERSION) || \
     (CMP_IP_AR_RELEASE_REVISION_VERSION_C   != CMP_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Cmp_Ip.c and Cmp_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((CMP_IP_SW_MAJOR_VERSION_C  != CMP_IP_SW_MAJOR_VERSION) || \
     (CMP_IP_SW_MINOR_VERSION_C  != CMP_IP_SW_MINOR_VERSION) || \
     (CMP_IP_SW_PATCH_VERSION_C  != CMP_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Cmp_Ip.c and Cmp_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == CMP_IP_USED)
        #if(CMP_IP_DEV_ERROR_DETECT == STD_ON)
            /* Check if this header file and Devassert.h file are of the same Autosar version */
            #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (CMP_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Cmp_Ip.c and Devassert.h are different"
            #endif
        #endif
    #endif /* CMP_IP_USED */

    /* Check if this header file and SchM_Icu.h file are of the same Autosar version */
    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.c and SchM_Icu.h are different"
    #endif

    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == CMP_IP_USED)

#if (CMP_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

static Cmp_Ip_StateType Cmp_Ip_axState[ICU_CMP_INSTANCE_COUNT];

#if (CMP_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

static LPCMP_Type * const Cmp_Ip_apxBase[ICU_CMP_INSTANCE_COUNT] = IP_LPCMP_BASE_PTRS;

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

static inline void Cmp_Ip_InitCcr0(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ccr0 = 0u;

    switch(userConfig->Comparator.FunctionalMode)
    {
        case CMP_IP_FUNCTIONALMODE_DISABLED:
            ccr0 |= LPCMP_CCR0_CMP_EN(0U);
            break;
        case CMP_IP_FUNCTIONALMODE_CONTINUOUS:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_EXT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_INT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_INT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_EXT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_RESAMPLED:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_FILTERED:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        default:
            /* Impossible case */
            break;
    }
    ccr0 |= LPCMP_CCR0_CMP_STOP_EN(userConfig->Comparator.EnableInStop?(uint32)1U:(uint32)0U);
    base->CCR0 = ccr0;
}

static inline uint32 Cmp_Ip_ConfigFunctionalModeCcr1(const Cmp_Ip_ConfigType* userConfig)
{
    uint32 ccr1 = 0u;

    switch(userConfig->Comparator.FunctionalMode)
    {
        case CMP_IP_FUNCTIONALMODE_DISABLED:
            break;
        case CMP_IP_FUNCTIONALMODE_CONTINUOUS:
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_EXT_CLK:
            ccr1 |= LPCMP_CCR1_SAMPLE_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(1U);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_INT_CLK:
            ccr1 |= LPCMP_CCR1_FILT_CNT(1U);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_INT_CLK:
            ccr1 |= LPCMP_CCR1_FILT_CNT(userConfig->Comparator.FilterSampleCount);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_EXT_CLK:
            ccr1 |= LPCMP_CCR1_SAMPLE_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(userConfig->Comparator.FilterSampleCount);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED:
            ccr1 |= LPCMP_CCR1_WINDOW_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(0U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_RESAMPLED:
            ccr1 |= LPCMP_CCR1_WINDOW_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(1U);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_FILTERED:
            ccr1 |= LPCMP_CCR1_WINDOW_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(userConfig->Comparator.FilterSampleCount);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        default:
            /* Impossible case */
            break;
    }
    
    return ccr1;
}

static inline void Cmp_Ip_InitCcr1(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ccr1 = 0u;

    ccr1 = Cmp_Ip_ConfigFunctionalModeCcr1(userConfig);

    ccr1 |= LPCMP_CCR1_COUT_PEN((userConfig->Comparator.EnablePinOutput)?1U:0U);
    ccr1 |= LPCMP_CCR1_WINDOW_INV((userConfig->Comparator.EnableInverter)?1U:0U);
    ccr1 |= LPCMP_CCR1_COUT_INV((userConfig->Comparator.EnableComparatorInvert)?1U:0U);
    ccr1 |= LPCMP_CCR1_DMA_EN((userConfig->Comparator.EnableDma)?1U:0U);
    ccr1 |= LPCMP_CCR1_COUT_SEL(userConfig->Comparator.OutputSelect);
    ccr1 |= LPCMP_CCR1_COUTA_OWEN((userConfig->Comparator.WindowCloseOutputOverwrite == CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_DISABLED)?0U:1U);
    ccr1 |= LPCMP_CCR1_COUTA_OW((userConfig->Comparator.WindowCloseOutputOverwrite == CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_HIGH)?1U:0U);
    switch (userConfig->Comparator.WindowCloseEvent)
    {
        case CMP_IP_WINDOWCLOSEEVENT_RISING:
            ccr1 &= (~LPCMP_CCR1_EVT_SEL_MASK);
            ccr1 |= LPCMP_CCR1_WINDOW_CLS(1u);
            break;
        case CMP_IP_WINDOWCLOSEEVENT_FALLING:
            ccr1 &= (~LPCMP_CCR1_EVT_SEL_MASK);
            ccr1 |= LPCMP_CCR1_WINDOW_CLS(1u) | LPCMP_CCR1_EVT_SEL(1u);
            break;
        case CMP_IP_WINDOWCLOSEEVENT_BOTH:
            ccr1 |= LPCMP_CCR1_WINDOW_CLS(1u) | LPCMP_CCR1_EVT_SEL(2u);
            break;
        case CMP_IP_WINDOWCLOSEEVENT_NONE:
            ccr1 &= (~LPCMP_CCR1_WINDOW_CLS_MASK);
            break;
        default:
            /* Impossible case */
            break;
    }
    base->CCR1 = ccr1;
}

static inline void Cmp_Ip_InitCcr2(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    /* Initialize the base address of the given instance */
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ccr2 = 0u;

    ccr2 |= LPCMP_CCR2_HYSTCTR(userConfig->Comparator.HysteresisLevel);
    ccr2 |= LPCMP_CCR2_OFFSET(userConfig->Comparator.OffsetLevel);
    ccr2 |= LPCMP_CCR2_CMP_HPMD((userConfig->Comparator.EnableHighPowerMode)?1U:0U);
    ccr2 |= LPCMP_CCR2_INMSEL((userConfig->Comparator.NegativeInputMux == CMP_IP_INPUTMUX_DAC)?0U:1U);
    ccr2 |= LPCMP_CCR2_MSEL((userConfig->Comparator.NegativeInputMux == CMP_IP_INPUTMUX_DAC)?0U:(uint32)(userConfig->Comparator.NegativeInputMux));
    ccr2 |= LPCMP_CCR2_INPSEL((userConfig->Comparator.PositiveInputMux == CMP_IP_INPUTMUX_DAC)?0U:1U);
    ccr2 |= LPCMP_CCR2_PSEL((userConfig->Comparator.PositiveInputMux == CMP_IP_INPUTMUX_DAC)?0U:(uint32)(userConfig->Comparator.PositiveInputMux));
    base->CCR2 = ccr2;
}

static inline void Cmp_Ip_InitDcr(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    /* Initialize the base address of the given instance */
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 dcr = 0u;

    dcr |= LPCMP_DCR_DAC_DATA(userConfig->Dac.VoltageLevel);
    dcr |= LPCMP_DCR_VRSEL(userConfig->Dac.VoltageRefSource);
    dcr |= LPCMP_DCR_DAC_EN((userConfig->Dac.PowerState == CMP_IP_DACPOWERSTATE_ENABLED)?1U:0U);

#if (defined (CMP_IP_SUPPORT_CMPTODAC_LINK))
    #if (STD_ON == CMP_IP_SUPPORT_CMPTODAC_LINK)
    dcr |= LPCMP_CCR0_LINKEN((userConfig->Dac.PowerState == CMP_IP_DACPOWERSTATE_LINKED)?1U:0U);
    #endif
#endif

    base->DCR = dcr;
}

#if (defined(ICU_CMP_0_ISR_USED) || \
     defined(ICU_CMP_1_ISR_USED) || \
     defined(ICU_CMP_2_ISR_USED))

static void Cmp_Ip_IrqHandler(uint8 instance);
#endif


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Icu driver function that initializes CMP.
* @details    This function enables CMP instance for signal compare and trigger interrupt
*
* @param[in]  instance      - The instance index
* @param[in]  userConfig    - Pointer to channel configuration structure
*
* @implements Cmp_Ip_Init_Activity
*/
Cmp_Ip_StatusType Cmp_Ip_Init(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    Cmp_Ip_StatusType   retStatus = CMP_IP_STATUS_SUCCESS;
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ier;
    uint32 csr;
    uint32 rrcr0;
    uint32 rrcr1;
    uint32 rrcsr;
    uint32 rrsr;

#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
    DevAssert(Cmp_Ip_axState[instance].State == ICU_CMP_IP_UNINIT);
#endif

    if(ICU_CMP_IP_UNINIT == Cmp_Ip_axState[instance].State)
    {
        ier = 0u;
        csr = 0u;
        rrcr0 = 0u;
        rrcr1 = 0u;
        rrcsr = 0u;
        rrsr = 0u;

        Cmp_Ip_InitCcr0(instance, userConfig);
        Cmp_Ip_InitCcr1(instance, userConfig);
        Cmp_Ip_InitCcr2(instance, userConfig);
        Cmp_Ip_InitDcr(instance, userConfig);

        ier |= LPCMP_IER_RRF_IE((userConfig->Trigger.EnableRoundRobinInterrupt)?1U:0U);
        Cmp_Ip_axState[instance].CmpInterruptEdge =  userConfig->Comparator.OutputInterruptTrigger;

        rrcr1 |= (uint32)userConfig->Trigger.RoundRobinEnChannelMask << (uint32)LPCMP_RRCR1_RR_CH0EN_SHIFT;
        rrcsr |= (uint32)userConfig->Trigger.PrepgmStateChannelMask << (uint32)LPCMP_RRCSR_RR_CH0OUT_SHIFT;
        rrcr0 |= LPCMP_RRCR0_RR_INITMOD(userConfig->Trigger.InitDelayValue);
        rrcr0 |= LPCMP_RRCR0_RR_NSAM(userConfig->Trigger.SampleDelay);
        rrcr1 |= LPCMP_RRCR1_FIXCH(userConfig->Trigger.FixedChannel);
        rrcr1 |= LPCMP_RRCR1_FIXP(userConfig->Trigger.FixedPort);
        rrcr0 |= LPCMP_RRCR0_RR_EN((userConfig->Trigger.EnableRoundRobin)?1U:0U);


        base->IER = ier;
        base->CSR = csr;
        base->RRCR0 = rrcr0;
        base->RRCR1 = rrcr1;
        base->RRCSR = rrcsr;
        base->RRSR = rrsr;

        Cmp_Ip_axState[instance].State = ICU_CMP_IP_INIT;
        Cmp_Ip_axState[instance].TriggerNotification = userConfig->TriggerNotification;
        Cmp_Ip_axState[instance].ComparatorNotification = userConfig->ComparatorNotification;
        Cmp_Ip_axState[instance].CallbackParam1 = userConfig->CallbackParam1;

    }
    else
    {
        /* instance already initialized - use deinitialize first */
        retStatus = CMP_IP_STATUS_ERROR;
    }
    return retStatus;
}

#if (CMP_IP_DEINIT_API == STD_ON)
/**
* @brief      Icu driver function that reset CMP.
* @details    This function reset CMP instance on reset values
*
* @param[in]  instance      - The instance index
*
* @implements Cmp_Ip_Deinit_Activity
*/
Cmp_Ip_StatusType Cmp_Ip_Deinit(uint8 instance)
{
    Cmp_Ip_StatusType   retStatus = CMP_IP_STATUS_SUCCESS;
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];

    /* disable interrupt, stop notifications */
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
    DevAssert(Cmp_Ip_axState[instance].State == ICU_CMP_IP_INIT);
#endif

    if(ICU_CMP_IP_INIT == Cmp_Ip_axState[instance].State)
    {
        base->CCR0 = 0U;
        base->CCR1 = 0U;
        base->CCR2 = 0U;
        base->DCR  = 0U;
        base->IER  = 0U;

        /*Clean interrupt flags*/
        base->CSR   = (base->CSR | (LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK | LPCMP_CSR_RRF_MASK));
        base->RRSR  = (base->RRSR | (0xFFu << LPCMP_RRSR_RR_CH0F_SHIFT));

        base->RRCR0 = 0U;
        base->RRCR1 = 0U;
        base->RRCSR = 0U;

        Cmp_Ip_axState[instance].State = ICU_CMP_IP_UNINIT;
    }
    else
    {
        /* instance already de-initialize - use initialize first */
        retStatus = CMP_IP_STATUS_ERROR;
    }
    return retStatus;
}
#endif  /* CMP_IP_DEINIT_API  */

#if (CMP_IP_SET_MODE_API == STD_ON)
/**
* @brief      Driver function that sets Cmp hardware channel into SLEEP mode.
* @details    This function enables the interrupt if wakeup is enabled for corresponding
*             Cmp channel
*
* @param[in]  instance       - HW instance
*
* @return void
*
* */

void Cmp_Ip_SetSleepMode(uint8 instance)
{
    /* Disable IRQ Interrupt */
    Cmp_Ip_DisableInterrupt(instance);
}

/**
* @brief      Driver function that sets the Cmp hardware channel into NORMAL mode.
* @details    This function enables the interrupt if Notification is enabled for corresponding
*             Cmp channel
*
* @param[in]  instance       - HW instance
*
* @return void
*
* */

void Cmp_Ip_SetNormalMode(uint8 instance)
{
    /* Enable IRQ Interrupt */
    Cmp_Ip_EnableInterrupt(instance);
}
#endif  /* CMP_IP_SET_MODE_API */

/**
* @brief      Icu driver function that enable user notification.
* @details    This function enables CMP instance for calling user notification on interrupt
*
* @param[in]  instance      - The instance index
*
* @implements Cmp_Ip_EnableNotification_Activity
*/
void Cmp_Ip_EnableNotification(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
    if((NULL_PTR == Cmp_Ip_axState[instance].TriggerNotification) && (NULL_PTR == Cmp_Ip_axState[instance].ComparatorNotification))
    {
        DevAssert(FALSE);
    }
#endif

    Cmp_Ip_axState[instance].NotificationEnabled = TRUE;
}

/**
* @brief      Icu driver function that disable user notification.
* @details    This function disable CMP instance for calling user notification on interrupt
*
* @param[in]  instance      - The instance index
*
* @implements Cmp_Ip_DisableNotification_Activity
*/
void Cmp_Ip_DisableNotification(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    Cmp_Ip_axState[instance].NotificationEnabled = FALSE;
}
/* @implements Cmp_Ip_EnableInterrupt_Activity */
void Cmp_Ip_EnableInterrupt(uint8 instance)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];

#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    /* clear w1c bits */
    base->CSR = LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK | LPCMP_CSR_RRF_MASK;

    switch (Cmp_Ip_axState[instance].CmpInterruptEdge)
    {
        case CMP_IP_INTTRIG_NONE:
            base->IER  |= LPCMP_IER_CFR_IE(0u) | LPCMP_IER_CFF_IE(0u);
            break;
        case CMP_IP_INTTRIG_FALLING_EDGE:
            base->IER  |= LPCMP_IER_CFR_IE(0u) | LPCMP_IER_CFF_IE(1u);
            break;
        case CMP_IP_INTTRIG_RISING_EDGE:
            base->IER  |= LPCMP_IER_CFR_IE(1u) | LPCMP_IER_CFF_IE(0u);
            break;
        case CMP_IP_INTTRIG_BOTH_EDGES:
            base->IER  |= LPCMP_IER_CFR_IE(1u) | LPCMP_IER_CFF_IE(1u);
            break;
        default:
            /* Impossible case */
            break;
    }
}

/**
 * @brief Disable CMP interrupt.
 * @implements Cmp_Ip_DisableInterrupt_Activity
 */
void Cmp_Ip_DisableInterrupt(uint8 instance)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    base->IER &= (~(LPCMP_IER_CFR_IE(1u) | LPCMP_IER_CFF_IE(1u)));

}

/**
 * @brief Set the type of activation for interrupt.
 */
void Cmp_Ip_SetInterruptActivation(uint8 instance, Cmp_Ip_OutputInterruptTriggerType Edge)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    Cmp_Ip_axState[instance].CmpInterruptEdge = Edge;

}

#if (CMP_IP_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief Get instance status.
 */
boolean Cmp_Ip_GetStatus(uint8 instance)
{
    boolean status;

#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    status = (0U != (Cmp_Ip_apxBase[instance]->CSR & (LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK | LPCMP_CSR_RRF_MASK)))?TRUE:FALSE;

    return status;
}
#endif

#if (defined(ICU_CMP_0_ISR_USED) || defined(ICU_CMP_1_ISR_USED) || defined(ICU_CMP_2_ISR_USED))
/* @implements Cmp_Ip_IrqHandler_Activity */
static void Cmp_Ip_IrqHandler(uint8 instance)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 flag_LpCmp;
    uint32 intterEnable_LpCmp;
    uint32 flag_RR;
    uint32 rrChannelEnInterrupt;
    uint32 intterEnable_RR;
    uint32 rrChannelMask;
    uint8 rrChannel;

#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif
    flag_LpCmp = base->CSR & (LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK);
    intterEnable_LpCmp = base->IER & (LPCMP_IER_CFR_IE_MASK | LPCMP_IER_CFF_IE_MASK);
    flag_RR = base->RRSR;
    rrChannelEnInterrupt = base->RRCR1;
    intterEnable_RR = base->IER & LPCMP_IER_RRF_IE_MASK;

    if(ICU_CMP_IP_INIT == Cmp_Ip_axState[instance].State)
    {
        /* Comparator interrupt */
        if ((0U != flag_LpCmp) && (0U != intterEnable_LpCmp))
        {
            /* clear w1c bits */
            base->CSR = LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK;
            if ((Cmp_Ip_axState[instance].NotificationEnabled) && (NULL_PTR != Cmp_Ip_axState[instance].ComparatorNotification))
            {
                Cmp_Ip_axState[instance].ComparatorNotification(Cmp_Ip_axState[instance].CallbackParam1, FALSE);
            }
        }

        /* Round-Robin interrupt */
        if ((0U != intterEnable_RR) && ((uint32)0U != (base->CSR & LPCMP_CSR_RRF_MASK)))
        {
            base->CSR = LPCMP_CSR_RRF_MASK;

            rrChannelMask = (uint32)1U;
            for (rrChannel = 0U; rrChannel < 8U; rrChannel++)
            {
                if (0U != (flag_RR & rrChannelEnInterrupt & rrChannelMask))
                {
                    /* clear w1c bits */
                    base->RRSR = rrChannelMask;
                    if ((Cmp_Ip_axState[instance].NotificationEnabled) && (NULL_PTR != Cmp_Ip_axState[instance].TriggerNotification))
                    {
                        Cmp_Ip_axState[instance].TriggerNotification(Cmp_Ip_axState[instance].CallbackParam1, FALSE);
                    }
                }
                rrChannelMask <<= 1U;
            }
        }
    }
    else
    {
        /* clear w1c bits */
        base->CSR = LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK;
        /* clear w1c bits */
        base->RRSR = (uint32)0xFFu << LPCMP_RRSR_RR_CH0F_SHIFT;
    }
}
#endif /* (defined(ICU_CMP_0_ISR_USED) || defined(ICU_CMP_1_ISR_USED) || defined(ICU_CMP_2_ISR_USED)) */

#if (defined(ICU_CMP_0_ISR_USED))
ISR(CMP_0_ISR)
{
    /*enable IRQs*/
    Cmp_Ip_IrqHandler(0U);
    EXIT_INTERRUPT();
}
#endif

#if (defined(ICU_CMP_1_ISR_USED))
ISR(CMP_1_ISR)
{
    /*enable IRQ*/
    Cmp_Ip_IrqHandler(1U);
    EXIT_INTERRUPT();
}
#endif

#if (defined(ICU_CMP_2_ISR_USED))
ISR(CMP_2_ISR)
{
    /*enable IRQ*/
    Cmp_Ip_IrqHandler(2U);
    EXIT_INTERRUPT();
}
#endif


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* CMP_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */
