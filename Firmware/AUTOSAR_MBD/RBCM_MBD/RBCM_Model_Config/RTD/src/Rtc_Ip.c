/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/**
*   @file           Rtc_Ip.c
*
*   @addtogroup     rtc_ip Rtc IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Rtc_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define RTC_IP_VENDOR_ID_C                    43
#define RTC_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define RTC_IP_AR_RELEASE_MINOR_VERSION_C     7
#define RTC_IP_AR_RELEASE_REVISION_VERSION_C  0
#define RTC_IP_SW_MAJOR_VERSION_C             5
#define RTC_IP_SW_MINOR_VERSION_C             0
#define RTC_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (RTC_IP_VENDOR_ID_C != RTC_IP_VENDOR_ID)
    #error "Rtc_Ip.h and Rtc_Ip.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((RTC_IP_AR_RELEASE_MAJOR_VERSION_C != RTC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RTC_IP_AR_RELEASE_MINOR_VERSION_C != RTC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RTC_IP_AR_RELEASE_REVISION_VERSION_C != RTC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Rtc_Ip.h and Rtc_Ip.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((RTC_IP_SW_MAJOR_VERSION_C != RTC_IP_SW_MAJOR_VERSION) || \
     (RTC_IP_SW_MINOR_VERSION_C != RTC_IP_SW_MINOR_VERSION) || \
     (RTC_IP_SW_PATCH_VERSION_C != RTC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Rtc_Ip.h and Rtc_Ip.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (RTC_IP_USED == STD_ON)

#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/**
* @brief          array variable used to store the runtime target time value.
*/
uint32 Rtc_Ip_u32TargetValue = 0U;

/**
* @brief          array variable used to store the counter value when interrupt occurs.
*/
uint32 Rtc_Ip_u32CounterValueInterrupt = 0U;
#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_8
#include "Gpt_MemMap.h"
/** @brief  Table of month length (in days) for the Un-leap-year*/
static const uint8 ULY[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

/** @brief Table of month length (in days) for the Leap-year*/
static const uint8 LY[] = {0U, 31U, 29U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};
#define GPT_STOP_SEC_CONST_8
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_16
#include "Gpt_MemMap.h"
/** @brief Number of days from begin of the non Leap-year*/
static const uint16 MONTH_DAYS[] = {0U, 0U, 31U, 59U, 90U, 120U, 151U, 181U, 212U, 243U, 273U, 304U, 334U};
#define GPT_STOP_SEC_CONST_16
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of RTC base pointers */
static RTC_Type * const rtcBase[RTC_INSTANCE_COUNT] = IP_RTC_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Global array variable used to channel state for process common interrupt */
static Rtc_Ip_State Rtc_Ip_u32ChState[RTC_INSTANCE_COUNT] =  {
                                                                {
                                                                    (boolean)FALSE,
                                                                    0U,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    (boolean)FALSE,
                                                                    NULL_PTR,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    0U,
                                                                    0U,
                                                                    0U,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    NULL_PTR,
                                                                    0U,
                                                                    RTC_IP_CH_MODE_CONTINUOUS
                                                                }
                                                            };
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef RTC_0_CH_0_ISR_USED
ISR(RTC_0_Ch_0_ISR);
static void Rtc_Ip_ProcessInterrupt(uint8 instance);
static inline boolean Rtc_Ip_GetInterruptEnableFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode);
#endif

static inline void Rtc_Ip_Configure(RTC_Type * const base,
                                 boolean freezeEnable,
                                 Rtc_Ip_ClockSelectType clockSelect,
                                 boolean divBy512,
                                 boolean divBy32);
static inline void Rtc_Ip_EnableCounter(RTC_Type * const base, boolean enable);
static inline void Rtc_Ip_ClearInterruptStatusFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode);
static inline void Rtc_Ip_SetControlRegister(RTC_Type * const base, uint32 value);
static inline void Rtc_Ip_ApiEnable(RTC_Type * const base, boolean enable);
static inline void Rtc_Ip_SetInterruptEnableFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode, boolean enable);
static inline void Rtc_Ip_ApivalCompareValue(RTC_Type * const base, uint32 value);
#ifdef RTC_0_CH_0_ISR_USED
static inline void Rtc_Ip_ProcessAlarmInterrupt(uint8 instance);
#endif
static inline void Rtc_Ip_SetCompareValue(uint8 instance, uint32 value);
static void Rtc_Ip_ClearChState(uint8 instance);
static boolean Rtc_Ip_IsYearLeap(uint16 year);
static boolean Rtc_Ip_IsTimeDateCorrectFormat(const Rtc_Ip_TimedateType *timeDate);
static uint32 Rtc_Ip_TicksToSeconds(uint8 instance, uint32 ticks);
static uint32 Rtc_Ip_SecondsToTicks(uint8 instance, uint32 seconds);
static inline Rtc_Ip_StatusType Rtc_Ip_IsAPICompareValueValid(uint8 instance);
static inline Rtc_Ip_StatusType Rtc_Ip_IsRTCCompareValueValid(uint8 instance);

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == RTC_IP_ENABLE_USER_MODE_SUPPORT)
/**
 * @brief      Rtc_Ip_SetUserAccessAllowed
 * @details    This function allow registers are accessible in user mode is called externally by OS Application
 * @param[in]  none
 */
void Rtc_Ip_SetUserAccessAllowed(void);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef RTC_0_CH_0_ISR_USED
/**
 * @brief
 * Function Name : Rtc_Ip_GetInterruptEnableFlag
 * Description   : Get the state of RTC Interrupt Enable Flag (RTCIE),
 *                  API Interrupt Enable Flag (APIIE) and Counter Roll Over wakeup/Interrupt Enable Flag (ROVREN)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if the interrupt is enabled, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Rtc_Ip_GetInterruptEnableFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode)
{
    boolean returnFlag;
    /* Check all RTC Interrupt Enable Flags */
    switch(interruptMode)
    {
        case RTC_IP_COUNTER_INTERRUPT:
        {
            returnFlag = (0U != (rtcBase[instance]->RTCC & RTC_RTCC_RTCIE_MASK)) ? TRUE : FALSE;
        }
        break;
        case RTC_IP_API_INTERRUPT:
        {
            returnFlag = (0U != (rtcBase[instance]->RTCC & RTC_RTCC_APIIE_MASK)) ? TRUE : FALSE;
        }
        break;
        case RTC_IP_ROLLOVER_INTERRUPT:
        {
            returnFlag = (0U != (rtcBase[instance]->RTCC & RTC_RTCC_ROVREN_MASK)) ? TRUE : FALSE;
        }
        break;
        default:
        {
            returnFlag = FALSE;
        }
        break;
    }

    return returnFlag;
}
#endif

static inline void Rtc_Ip_Configure(RTC_Type * const base,
                                     boolean freezeEnable,
                                     Rtc_Ip_ClockSelectType clockSelect,
                                     boolean divBy512,
                                     boolean divBy32)
{
    uint32 configReg = 0UL;
    /* Set clock and prescalerValue */
    if(freezeEnable)
    {
        configReg |= RTC_RTCC_FRZEN_MASK;
    }
    if(divBy512)
    {
        configReg |= RTC_RTCC_DIV512EN_MASK;
    }
    if(divBy32)
    {
        configReg |= RTC_RTCC_DIV32EN_MASK;
    }
    /* Set clock and prescalerValue */
    switch(clockSelect)
    {
        case RTC_IP_CLOCK_SOURCE_0:
            configReg |= (0UL << RTC_RTCC_CLKSEL_SHIFT);
            break;
        case RTC_IP_CLOCK_SOURCE_1:
            configReg |= (1UL << RTC_RTCC_CLKSEL_SHIFT);
            break;
        case RTC_IP_CLOCK_SOURCE_2:
            configReg |= (2UL << RTC_RTCC_CLKSEL_SHIFT);
            break;
        case RTC_IP_CLOCK_SOURCE_3:
            configReg |= (3UL << RTC_RTCC_CLKSEL_SHIFT);
            break;
        default:
            /* This case should not be entered */
            break;
    }

    base->RTCC |= configReg;

}

static inline void Rtc_Ip_EnableCounter(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04();
    {
        /* Set EnableCounter */
        if (TRUE == enable)
        {
            base->RTCC |= RTC_RTCC_CNTEN_MASK;
        }
        else
        {
            base->RTCC &= ~(RTC_RTCC_CNTEN_MASK);
        }
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04();

}

/**
 * @brief
 * Function Name : Rtc_Ip_ClearInterruptStatusFlag
 * Description   : Clear th RTC Interrupt Flag (RTCF),
 *                  API Interrupt Flag (APIF) and Counter Roll Over Interrupt Flag (ROVRF): RTC Status register (RTCS)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  void
 * @pre     The driver needs to be initialized.
 */
static inline void Rtc_Ip_ClearInterruptStatusFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode)
{
    /* Clear the RTC interrupt flags: write 1 to clear flags */
    switch(interruptMode)
    {
        case RTC_IP_COUNTER_INTERRUPT:
        {
            rtcBase[instance]->RTCS = RTC_RTCS_RTCF_MASK;
        }
        break;
        case RTC_IP_API_INTERRUPT:
        {
            rtcBase[instance]->RTCS = RTC_RTCS_APIF_MASK;
        }
        break;
        case RTC_IP_ROLLOVER_INTERRUPT:
        {
            rtcBase[instance]->RTCS = RTC_RTCS_ROVRF_MASK;
        }
        break;
        default:
        {
            /* do nothing */
        }
        break;
    }
}

static inline void Rtc_Ip_SetControlRegister(RTC_Type * const base, uint32 value)
{
    /* SetControlRegister value */
    base->RTCC = value;
}

static inline void Rtc_Ip_ApiEnable(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06();
    {
        /* ApiEnable */
        if (TRUE == enable)
        {
            base->RTCC |= (uint32)(1UL << RTC_RTCC_APIEN_SHIFT);
        }
        else
        {
            base->RTCC &= ~(uint32)(1UL << RTC_RTCC_APIEN_SHIFT);
        }
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06();
}

/**
 * @brief
 * Function Name : Rtc_Ip_SetInterruptEnableFlag
 * Description   : Set the RTC Interrupt Enable Flag (RTCIE),
 *                  API Interrupt Enable Flag (APIIE) and Counter Roll Over wakeup/Interrupt Enable Flag (ROVREN)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 * @param[in]   enable          enable/disable the RTC Interrupt
 *
 * @return  void
 * @pre     The driver needs to be initialized.
 */
static inline void Rtc_Ip_SetInterruptEnableFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode, boolean enable)
{
    switch(interruptMode)
    {
        case RTC_IP_COUNTER_INTERRUPT:
        {
            /* Set the RTC Interrupt Enable Flag (RTCIE) */
            if (TRUE == enable)
            {
                rtcBase[instance]->RTCC |= RTC_RTCC_RTCIE_MASK;
            }
            else
            {
                rtcBase[instance]->RTCC &= ~(RTC_RTCC_RTCIE_MASK);
            }
        }
        break;
        case RTC_IP_API_INTERRUPT:
        {
            /* Set the API Interrupt Enable Flag (APIIE) */
            if (TRUE == enable)
            {
                rtcBase[instance]->RTCC |= RTC_RTCC_APIIE_MASK;
            }
            else
            {
                rtcBase[instance]->RTCC &= ~(RTC_RTCC_APIIE_MASK);
            }
        }
        break;
        case RTC_IP_ROLLOVER_INTERRUPT:
        {
            /* Set the Counter Roll Over wakeup/Interrupt Enable Flag (ROVREN) */
            if (TRUE == enable)
            {
                rtcBase[instance]->RTCC |= RTC_RTCC_ROVREN_MASK;
            }
            else
            {
                rtcBase[instance]->RTCC &= ~(RTC_RTCC_ROVREN_MASK);
            }
        }
        break;
        default:
        {
            /* do nothing */
        }
        break;
    }
}

static inline void Rtc_Ip_ApivalCompareValue(RTC_Type * const base, uint32 value)
{
    /* Set APIVAL */
    base->APIVAL = value;
}

/*================================================================================================*/
/**
* @brief         Rtc Driver function to set compare value in RTC Mode.
* @details       This function:
*                           - writes compare value in RTCVAL Register
* @param[in]    instance    RTC hw instance number
* @param[in]    value       compare value
* @return       void
* @pre          The driver needs to be initialized.
* @implements
*/
static inline void Rtc_Ip_SetCompareValue(uint8 instance, uint32 value)
{
    /* Set RTCVAL */
    rtcBase[instance]->RTCVAL = value;
}

/* ClearChState  */
static void Rtc_Ip_ClearChState(uint8 instance)
{

    Rtc_Ip_u32ChState[instance].alarmInit = FALSE;
    Rtc_Ip_u32ChState[instance].repetitionInterval = 0U;
    Rtc_Ip_u32ChState[instance].numberOfRepeats = 0U;
    Rtc_Ip_u32ChState[instance].repeatForever = FALSE;
    Rtc_Ip_u32ChState[instance].alarmIntEnable = FALSE;
    Rtc_Ip_u32ChState[instance].alarmCallback = NULL_PTR;
    Rtc_Ip_u32ChState[instance].callbackParams = 0U;
    Rtc_Ip_u32ChState[instance].isAlarmTimeNew    = FALSE;
    Rtc_Ip_u32ChState[instance].timeOffset        = 0U;
    Rtc_Ip_u32ChState[instance].startTime         = 0U;
    Rtc_Ip_u32ChState[instance].rolloverCount     = 0U;
    Rtc_Ip_u32ChState[instance].ticksPerSecond    = 0U;
    Rtc_Ip_u32ChState[instance].chInit            = FALSE;
    Rtc_Ip_u32ChState[instance].callback          = NULL_PTR;
    Rtc_Ip_u32ChState[instance].callbackParam     = 0U;
}

static boolean Rtc_Ip_IsYearLeap(uint16 year)
{
    boolean returnValue;
    /* Check if yearLeap */
    if ((((year % 4U) == 0U) && ((year % 100U) != 0U)) || ((year % 400U) == 0U))
    {
        returnValue = TRUE;
    }
    else
    {
        returnValue = FALSE;
    }
    /* Return the exit code */
    return returnValue;
}

static boolean Rtc_Ip_IsTimeDateCorrectFormat(const Rtc_Ip_TimedateType *timeDate)
{

    /* Declare local variables */
    boolean returnValue;
    const uint8 * pDays;

    /* Set the days-in-month table for the corresponding year */
    pDays = Rtc_Ip_IsYearLeap(timeDate->year) ? (LY) : (ULY);

    /* Check if the time and date are in the correct ranges */
    if ((timeDate->year < YEAR_RANGE_START) || (timeDate->year > YEAR_RANGE_END)
            ||  (timeDate->month < 1U) || (timeDate->month > 12U)
            ||  (timeDate->day < 1U) || (timeDate->day > 31U)
            ||  (timeDate->hour >= HOURS_IN_A_DAY)
            ||  (timeDate->minutes >= MINS_IN_A_HOUR) || (timeDate->seconds >= SECONDS_IN_A_MIN))
    {
        returnValue = FALSE;
    }
    /* Check if the day is a valid day from the corresponding month */
    else if (timeDate->day > pDays[timeDate->month])
    {
        returnValue = FALSE;
    }
    else
    {
        returnValue = TRUE;
    }

    /* Return the exit code */
    return returnValue;
}

static uint32 Rtc_Ip_TicksToSeconds(uint8 instance, uint32 ticks)
{
    uint32 returnValue;

    /* Calculate the number of seconds passed since setting the time and date */
    uint64 totalTicks = ((uint64)(Rtc_Ip_u32ChState[instance].rolloverCount)) * MAX_32BIT;
    totalTicks += ticks;
    totalTicks -= Rtc_Ip_u32ChState[instance].timeOffset;
    uint64 seconds = totalTicks / Rtc_Ip_u32ChState[instance].ticksPerSecond;
    
    /* Approximate if conversion of seconds from ticks is less than tolerance to not lose precision */
    if( (totalTicks % Rtc_Ip_u32ChState[instance].ticksPerSecond) >= \
        (Rtc_Ip_u32ChState[instance].ticksPerSecond - (uint32)RTC_IP_PPM_TOLERANCE) )
    {
        /* Increment seconds because value was truncated by div operation */
        seconds++;
    }
    returnValue = (uint32)seconds;
    return returnValue;
}

static uint32 Rtc_Ip_SecondsToTicks(uint8 instance, uint32 seconds)
{
    uint32 returnValue;

    /* Calculate the number of ticks passed since setting the time and date */
    uint64 ticks = ((uint64)seconds) * Rtc_Ip_u32ChState[instance].ticksPerSecond;
    ticks += Rtc_Ip_u32ChState[instance].timeOffset;
    ticks -= ((uint64)(Rtc_Ip_u32ChState[instance].rolloverCount)) * MAX_32BIT;
    returnValue = (uint32)ticks;
    return returnValue;
}

static inline Rtc_Ip_StatusType Rtc_Ip_IsAPICompareValueValid(uint8 instance)
{
    Rtc_Ip_StatusType returnValue;
    
    /* Check if timer is synchronized or not */
    if(0U != (rtcBase[instance]->RTCS & RTC_RTCS_INV_API_MASK))
    {
        returnValue = RTC_IP_ERROR;
    }
    else
    {
        returnValue = RTC_IP_SUCCESS;
    }

    return returnValue;
}

static inline Rtc_Ip_StatusType Rtc_Ip_IsRTCCompareValueValid(uint8 instance)
{
    Rtc_Ip_StatusType returnValue;
    returnValue = RTC_IP_ERROR;
    /* Check if timer is synchronized or not */
    if(0U != (rtcBase[instance]->RTCS & RTC_RTCS_INV_RTC_MASK))
    {
        returnValue = RTC_IP_ERROR;
    }
    else
    {
        returnValue = RTC_IP_SUCCESS;
    }

    return returnValue;
}

#ifdef RTC_0_CH_0_ISR_USED
static inline void Rtc_Ip_ProcessAlarmInterrupt(uint8 instance)
{
    uint32 counterValue;
    uint32 newAlarmTime;
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif  
    /* If the alarm interrupt configuration has been defined */
    if((FALSE != Rtc_Ip_u32ChState[instance].alarmInit) && (TRUE == Rtc_Ip_u32ChState[instance].alarmIntEnable))
    {
        if ((0UL < Rtc_Ip_u32ChState[instance].numberOfRepeats) || (TRUE == Rtc_Ip_u32ChState[instance].repeatForever))
        {
            counterValue = Rtc_Ip_GetCounterRegister(instance);
            newAlarmTime = counterValue + Rtc_Ip_SecondsToTicks(instance, Rtc_Ip_u32ChState[instance].repetitionInterval);

            /* Check the value of newAlrm to be more than 6 ticks to have time to synchronize */
            if( (newAlarmTime >= (counterValue + 6U)) ||
                (   (newAlarmTime > 0U) &&
                    (newAlarmTime < counterValue) &&
                    (((uint32)(MAX_32BIT - counterValue) + newAlarmTime) >= 6U) ) )
            {
                Rtc_Ip_SetCompareValue(instance, newAlarmTime);
                Rtc_Ip_u32ChState[instance].isAlarmTimeNew = TRUE;
            }
            /* If the alarm repeats forever, set number of repeats to 0 to avoid an accidental trigger of the core overflow flag */
            Rtc_Ip_u32ChState[instance].numberOfRepeats = (Rtc_Ip_u32ChState[instance].repeatForever == FALSE) ? (Rtc_Ip_u32ChState[instance].numberOfRepeats - 1UL) : 0UL;
        }
        else
        {
            Rtc_Ip_u32ChState[instance].isAlarmTimeNew = FALSE;
        }

        /* If the user has defined a callback, call it */
        if (NULL_PTR != Rtc_Ip_u32ChState[instance].alarmCallback)
        {
            Rtc_Ip_u32ChState[instance].alarmCallback(Rtc_Ip_u32ChState[instance].callbackParams);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTC_0_CH_0_ISR_USED
/**
* @brief   RTC_Gpt_ProcessInterrupt.
* @details Function used by interrupt service routines to call notification
*          functions if provided and enabled
*
* @param[in]     channel      hardware channel index
* @implements    Rtc_Ip_ProcessInterrupt_Activity
*/
static void Rtc_Ip_ProcessInterrupt(uint8 instance)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    boolean apiInterruptStatusFlag;
    boolean apiInterruptEnableFlag;
    boolean rtcInterruptStatusFlag;
    boolean rtcInterruptEnableFlag;
    boolean rollOverInterruptStatusFlag;
    boolean rollOverInterruptEnableFlag;
    boolean                 chInit;
    Rtc_Ip_CallbackType     callback;
    uint8                   callbackParam;
    Rtc_Ip_ChannelModeType  channelMode;

    if (instance < RTC_INSTANCE_COUNT)
    {
        /* Check if driver is initialized */
        chInit = Rtc_Ip_u32ChState[instance].chInit;
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05();
        {
            if (TRUE == chInit)
            {
                /* Check for spurious interrupts: check the status flag register and interrupts enable register */
                apiInterruptStatusFlag = Rtc_Ip_GetInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
                apiInterruptEnableFlag = Rtc_Ip_GetInterruptEnableFlag(instance, RTC_IP_API_INTERRUPT);
                rtcInterruptStatusFlag = Rtc_Ip_GetInterruptStatusFlag(instance, RTC_IP_COUNTER_INTERRUPT);
                rtcInterruptEnableFlag = Rtc_Ip_GetInterruptEnableFlag(instance, RTC_IP_COUNTER_INTERRUPT);
                rollOverInterruptStatusFlag = Rtc_Ip_GetInterruptStatusFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);
                rollOverInterruptEnableFlag = Rtc_Ip_GetInterruptEnableFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);

                if (apiInterruptStatusFlag && apiInterruptEnableFlag)
                {
                    /* Clear interrupt status flags */
                    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
                }

                /* Check if an alarm has occurred */
                if(rtcInterruptStatusFlag && rtcInterruptEnableFlag)
                {
                    /* Clear interrupt status flags */
                    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_COUNTER_INTERRUPT);
                }

                if (rollOverInterruptStatusFlag && rollOverInterruptEnableFlag)
                {
                    /* Clear interrupt status flags */
                    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);
                }
            }
            else
            {
                /* Driver isn't initialized and just clear pending interrupts */
                Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
                Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_COUNTER_INTERRUPT);
                Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05();
        if (TRUE == chInit)
        {
            Rtc_Ip_u32CounterValueInterrupt = Rtc_Ip_u32TargetValue + Rtc_Ip_GetCounterRegister(instance);
            if (apiInterruptStatusFlag && apiInterruptEnableFlag)
            {
                callback        = Rtc_Ip_u32ChState[instance].callback;
                channelMode     = Rtc_Ip_u32ChState[instance].channelMode;
                callbackParam   = Rtc_Ip_u32ChState[instance].callbackParam;
                /* Check if channel mode is ONE-SHOT */
                if(RTC_IP_CH_MODE_ONESHOT == channelMode)
                {
                    Rtc_Ip_StopTimer(instance);
                }
                /* Call upper layer handler */
                if(NULL_PTR != callback)
                {
                    callback(callbackParam);
                }
            }

            /* Check if an alarm has occurred */
            if(rtcInterruptStatusFlag && rtcInterruptEnableFlag)
            {
                /* Process AlarmInterrupt */
                Rtc_Ip_ProcessAlarmInterrupt(instance);
            }

            if (rollOverInterruptStatusFlag && rollOverInterruptEnableFlag)
            {
                Rtc_Ip_u32ChState[instance].rolloverCount++;
            }
        }
    }
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief
 * Function Name : Rtc_Ip_GetInterruptStatusFlag
 * Description   : Get the state of RTC Interrupt Flag (RTCF),
 *                  API Interrupt Flag (APIF) and Counter Roll Over Interrupt Flag (ROVRF): RTC Status register (RTCS)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if an interrupt has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
boolean Rtc_Ip_GetInterruptStatusFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode)
{
    boolean returnFlag;
    /* Check all RTC interrupt flags */
    switch(interruptMode)
    {
        case RTC_IP_COUNTER_INTERRUPT:
        {
            returnFlag = (0U != (rtcBase[instance]->RTCS & RTC_RTCS_RTCF_MASK)) ? TRUE : FALSE;
        }
        break;
        case RTC_IP_API_INTERRUPT:
        {
            returnFlag = (0U != (rtcBase[instance]->RTCS & RTC_RTCS_APIF_MASK)) ? TRUE : FALSE;
        }
        break;
        case RTC_IP_ROLLOVER_INTERRUPT:
        {
            returnFlag = (0U != (rtcBase[instance]->RTCS & RTC_RTCS_ROVRF_MASK)) ? TRUE : FALSE;
        }
        break;
        default:
        {
            returnFlag = FALSE;
        }
        break;
    }

    return returnFlag;
}

#if (STD_ON == RTC_IP_ENABLE_USER_MODE_SUPPORT)
void Rtc_Ip_SetUserAccessAllowed(void)
{
    RTC_Type * base = rtcBase[0U];
    /* Registers are accessible in user mode*/
    base->RTCSUPV &= ~(uint32)(1UL << RTC_RTCSUPV_SUPV_SHIFT);
}
#endif

uint32 Rtc_Ip_GetAPICompareRegister(uint8 instance)
{
    uint32 compareValue;
    /* Get CompareRegister value */
    compareValue = rtcBase[instance]->APIVAL;
    return compareValue;
}

uint32 Rtc_Ip_GetCounterRegister(uint8 instance)
{

    uint32 counterValue;
    /* Get GetCounterRegister value */
    counterValue = rtcBase[instance]->RTCCNT;

    return counterValue;
}

/**
* @brief         Rtc Driver initialization function
* @details       initialization function
*
* @param[in]     instance     hw instance
* @param[in]     *config      pointer to configuration
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Rtc_Ip_Init_Activity
*/
void Rtc_Ip_Init(uint8 instance, const Rtc_Ip_ConfigType *config)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != config);
#endif
#if (STD_ON == RTC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(Rtc_Ip_SetUserAccessAllowed);
#endif
    RTC_Type * base = rtcBase[instance];

#if (RTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
    /* Check if RTCC_CNTEN is not set */
    if(0x0U == (base->RTCC & RTC_RTCC_CNTEN_MASK))
    {
#endif
    /* Clear the Control Register, this will trigger a software reset of the module */
    Rtc_Ip_SetControlRegister(base, 0UL);
    /* Clear interrupt status flags */
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_COUNTER_INTERRUPT);
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);
#if (RTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
    }
    else
    {
        /* Clear interrupt status flags without APIF flag */
        Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_COUNTER_INTERRUPT);
        Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);
    }
#endif
    /* Configure the RTC based on the user configuration and enable global and rollover interrupt */
    Rtc_Ip_Configure(base,
                      config->freezeEnable,
                      config->clockSelect,
                      config->divideBy512,
                      config->divideBy32);

    Rtc_Ip_u32ChState[instance].chInit = TRUE;
    Rtc_Ip_u32ChState[instance].callback = config->callback;
    Rtc_Ip_u32ChState[instance].callbackParam = config->callbackParam;
    Rtc_Ip_u32ChState[instance].ticksPerSecond = RTC_IP_TICKS_PER_SECOND;
    Rtc_Ip_u32ChState[instance].channelMode = config->channelMode;
    Rtc_Ip_u32TargetValue = 0U;
}

/*================================================================================================*/
/**
* @brief         Rtc driver de-initialization function
* @details       This function:
*                       - resets the Rtc control register
*                       - clears the Rtc interrupt flags
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*
* @implements       Rtc_Ip_DeInit_Activity
*/
void Rtc_Ip_DeInit(uint8 instance)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    Rtc_Ip_u32TargetValue = 0U;
    RTC_Type * base = rtcBase[instance];

    /* Clear interrupt status flags */
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_COUNTER_INTERRUPT);
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_ROLLOVER_INTERRUPT);
    /* Clear the Control Register, this will trigger a software reset of the module */
    Rtc_Ip_SetControlRegister(base, 0UL);
    /* Deallocate the state structure to avoid errors on reinitialization */
    Rtc_Ip_ClearChState(instance);
}

/*================================================================================================*/
/**
* @brief         Rtc Driver function for starting the Rtc timer channel.
* @details       This function:
*                       - disables the API functionality
*                       - sets the timeout value (in RTCC - APIVAL)
*                       - enables API functionality (RTCC - APIEN).
*
* @param[in]     value            channel timeout value
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Rtc_Ip_StartTimer_Activity
*
*/
void Rtc_Ip_StartTimer(uint8 instance, uint32 value)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    Rtc_Ip_u32TargetValue = value;
    RTC_Type * base = rtcBase[instance];

    /* Disable API(Autonomous Periodic Interrupt) */
    Rtc_Ip_ApiEnable(base, FALSE);

    /* Disable Counter */
    Rtc_Ip_EnableCounter(base, FALSE);

    /* Configure channel compare register */
    Rtc_Ip_ApivalCompareValue(base, value);
    /* Clear interrupt status flags */
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
    /* Enable API(Autonomous Periodic Interrupt) */
    Rtc_Ip_ApiEnable(base, TRUE);

    /* Enable Counter */
    Rtc_Ip_EnableCounter(base, TRUE);
}

/*================================================================================================*/
/**
* @brief         Rtc Driver function for stopping the Rtc timer channel.
* @details       This function:
*                           - disables the API functionality
*                           - clears the API interrupt flag
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_StopTimer_Activity
*/
void Rtc_Ip_StopTimer(uint8 instance)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = rtcBase[instance];
    /* Stop API counter */
    Rtc_Ip_ApiEnable(base, FALSE);

    /* Clear interrupt status flag */
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
}

/*================================================================================================*/
/**
* @brief         Rtc Driver function for starting the Rtc counter.
* @details       This function:
*                           - enables the counter
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_StartCounter_Activity
*/
void Rtc_Ip_StartCounter(uint8 instance)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = rtcBase[instance];

    /* Disable Counter */
    Rtc_Ip_EnableCounter(base, TRUE);
}

/*================================================================================================*/
/**
* @brief         Rtc Driver function for stopping the Rtc counter.
* @details       This function:
*                           - disables the counter
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_StopCounter_Activity
*/
void Rtc_Ip_StopCounter(uint8 instance)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = rtcBase[instance];

    /* Disable Counter */
    Rtc_Ip_EnableCounter(base, FALSE);

}

/*================================================================================================*/
/**
* @brief         Rtc Driver function for Enable Interrupt for RTC channel
* @details       This function:
*                        - Enable Interrupt for RTC channel
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/

void Rtc_Ip_EnableInterrupt(uint8 instance, Rtc_Ip_InterruptType interruptMode)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

#if (RTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
    /* Clear interrupt status flag */
    Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
#endif
    /* Enable RTC interrupt */
    Rtc_Ip_SetInterruptEnableFlag(instance, interruptMode, TRUE);
}

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function for Disable Interrupt for RTC channel
* @details       This function:
*                        - Disable Interrupt for RTC channel
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_DisableInterrupt(uint8 instance, Rtc_Ip_InterruptType interruptMode)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    /* Clear interrupt status flag */
    Rtc_Ip_ClearInterruptStatusFlag(instance, interruptMode);
    /* Disable RTC interrupt */
    Rtc_Ip_SetInterruptEnableFlag(instance, interruptMode, FALSE);

}
/*================================================================================================*/
#if (RTC_IP_TRIGGER_ENABLE_API == STD_ON)
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - sets TRIG_EN bit
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_TriggerEnable(uint8 instance, boolean enable)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07();
    /* enable TRIG_EN */
    if (TRUE == enable)
    {
        rtcBase[instance]->RTCC |= (uint32)(1UL << RTC_RTCC_TRIG_EN_SHIFT);
    }
    else
    {
        rtcBase[instance]->RTCC &= ~(uint32)(1UL << RTC_RTCC_TRIG_EN_SHIFT);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07();
}
#endif
 /*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will set the date passed by the user.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_SetTimeDate_Activity
*/
Rtc_Ip_StatusType Rtc_Ip_SetTimeDate(uint8 instance,
                                     const Rtc_Ip_TimedateType *timeDate)
{
    Rtc_Ip_StatusType returnValue;

#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != timeDate);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Check if the date/time format is correct */
    if(!Rtc_Ip_IsTimeDateCorrectFormat(timeDate))
    {
        /* Set the status code to error */
        returnValue = RTC_IP_ERROR;
    }
    else
    {
        /* Save the value of the RTC counter in the state structure */
        Rtc_Ip_u32ChState[instance].timeOffset = Rtc_Ip_GetCounterRegister(instance);
        /* Reset the number of overflows */
        Rtc_Ip_u32ChState[instance].rolloverCount = 0UL;
        /* Convert the time and date to seconds and save it in the state structure */
        Rtc_Ip_ConvertTimeDateToSeconds(timeDate, &(Rtc_Ip_u32ChState[instance].startTime));
        returnValue = RTC_IP_SUCCESS;
    }

    return returnValue;
}

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will get the current time and date and it will
*                               store in the state structure.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_GetTimeDate_Activity
*/
void Rtc_Ip_GetTimeDate(uint8 instance,
                        Rtc_Ip_TimedateType * const timeDate)
{
    uint32 counterValue = 0U;
    uint32 secondsPassed = 0U;

#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != timeDate);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Get the current counter value in ticks */
    counterValue = Rtc_Ip_GetCounterRegister(instance);
    /* Compute the number of the seconds passed since setting the time and date */
    secondsPassed = Rtc_Ip_TicksToSeconds(instance, counterValue);
    /* Add the start time to the calculated value */
    secondsPassed += Rtc_Ip_u32ChState[instance].startTime;
    /* Convert the seconds into time/date format */
    Rtc_Ip_ConvertSecondsToTimeDate(&secondsPassed, timeDate);
}

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will configure a periodic interrupt(using the
*                               RTC's API functionality) with the period configured by the user.
*                               It will calculate the necessary compare value using periodInMs
*                               parameter and the clock source of the module.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     periodInMs         period value in microseconds
* @param[in]     enable             if functionalitu enable or disabled
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_ConfigurePeriodicInterrupt_Activity
*/
Rtc_Ip_StatusType Rtc_Ip_ConfigurePeriodicInterrupt(uint8 instance,
                                                    uint32 periodInMs,
                                                    boolean enable)
{
    Rtc_Ip_StatusType returnValue;
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    RTC_Type * base = rtcBase[instance];
    uint64 configuredPeriod;

#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Disable API Interrupt request */
    Rtc_Ip_ApiEnable(base, FALSE);
    /* Disable API Interrupt */
    Rtc_Ip_SetInterruptEnableFlag(instance, RTC_IP_API_INTERRUPT, FALSE);

    if(TRUE == enable)
    {
        /* Calculate the period */
        configuredPeriod = (((uint64)Rtc_Ip_u32ChState[instance].ticksPerSecond * periodInMs) / 1000UL) - 1UL;

        /* Check if the calculated period is valid */
        if((configuredPeriod > RTC_IP_MINIMUM_API_VALUE) && (configuredPeriod < MAX_32BIT))
        {
            returnValue = Rtc_Ip_IsAPICompareValueValid(instance);
            if(RTC_IP_SUCCESS == returnValue)
            {
                /* Configure the API with new values */
                Rtc_Ip_ApivalCompareValue(base, (uint32)configuredPeriod);
                /* Clear interrupt status flags */
                Rtc_Ip_ClearInterruptStatusFlag(instance, RTC_IP_API_INTERRUPT);
                /* Enable API(Autonomous Periodic Interrupt) */
                Rtc_Ip_ApiEnable(base, TRUE);
                /* Enable API Interrupt */
                Rtc_Ip_SetInterruptEnableFlag(instance, RTC_IP_API_INTERRUPT, TRUE);
            }
        }
        else
        {
            /* Set the return code to error */
            returnValue = RTC_IP_ERROR;
        }
    }
    else
    {
        returnValue = RTC_IP_ERROR;
    }

    return returnValue;
}

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will configure the alarm based on the
*                               configuration structure passed by the user.
*                               When using alarm that are configured to be repetitive,
*                               enable the interrupt. Otherwise the repeat function will
*                               not work.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *alarmConfig       pointer to configuration
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_ConfigureAlarm_Activity
*
*/
Rtc_Ip_StatusType Rtc_Ip_ConfigureAlarm(uint8 instance,
                                        const Rtc_Ip_AlarmConfigType *alarmConfig)
{
    Rtc_Ip_StatusType returnValue;
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != alarmConfig);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    uint32 convertedAlarmTime;
    uint32 counterValue;
    uint32 currentTime;
    uint32 newAlarmTime;

    /* Check if the alarm time is in a correct format */
    if (TRUE == Rtc_Ip_IsTimeDateCorrectFormat(&(alarmConfig->alarmTime)))
    {
        Rtc_Ip_u32ChState[instance].alarmInit = TRUE;
        Rtc_Ip_u32ChState[instance].repetitionInterval = alarmConfig->repetitionInterval;
        Rtc_Ip_u32ChState[instance].numberOfRepeats = alarmConfig->numberOfRepeats;
        Rtc_Ip_u32ChState[instance].repeatForever = alarmConfig->repeatForever;
        Rtc_Ip_u32ChState[instance].alarmIntEnable = alarmConfig->alarmIntEnable;
        Rtc_Ip_u32ChState[instance].alarmCallback = alarmConfig->alarmCallback;
        Rtc_Ip_u32ChState[instance].callbackParams = alarmConfig->callbackParams;
        /* Convert the time date to seconds */
        Rtc_Ip_ConvertTimeDateToSeconds(&(alarmConfig->alarmTime), &convertedAlarmTime);
        /* Get current time in seconds */
        counterValue = Rtc_Ip_GetCounterRegister(instance);

        currentTime = Rtc_Ip_TicksToSeconds(instance, counterValue);

        currentTime += Rtc_Ip_u32ChState[instance].startTime;

        /* Check if the alarm time is greater than current time */
        if(convertedAlarmTime > currentTime)
        {
            /* Write alarm time into Time Alarm Register */
            newAlarmTime = Rtc_Ip_SecondsToTicks(instance, convertedAlarmTime - Rtc_Ip_u32ChState[instance].startTime);
            if(newAlarmTime >= (uint32)(counterValue + RTC_IP_SYNC_TICKS_VALUE))
            {
                returnValue = Rtc_Ip_IsRTCCompareValueValid(instance);
                if(RTC_IP_SUCCESS == returnValue)
                {
                    Rtc_Ip_SetCompareValue(instance, newAlarmTime);
                    Rtc_Ip_u32ChState[instance].isAlarmTimeNew = TRUE;
                }
            }
            else
            {
                returnValue = RTC_IP_ERROR;
            }
        }
        else
        {
            returnValue = RTC_IP_ERROR;
        }
    }
    else
    {
        returnValue = RTC_IP_ERROR;
    }

    /* Return the exit code */
    return returnValue;
}
/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will convert seconds into time-date format.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_ConvertSecondsToTimeDate_Activity
*/
void Rtc_Ip_ConvertSecondsToTimeDate(const uint32 *seconds,
                                     Rtc_Ip_TimedateType * const timeDate)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != seconds);
    DevAssert(NULL_PTR != timeDate);
#endif
    /* Declare the variables needed */
    uint8 index;
    boolean yearLeap;
    uint32 numberOfDays;
    uint32 tempSeconds;
    uint16 daysInYear;

    /* Because the starting year(1970) is not leap, set the daysInYear
     * variable with the number of the days in a normal year
     */
    daysInYear = DAYS_IN_A_YEAR;

    /* Set the year to the beginning of the range */
    timeDate->year = YEAR_RANGE_START;

    /* Get the number of days */
    numberOfDays = (*seconds) / SECONDS_IN_A_DAY;
    /* Get the number of seconds remaining */
    tempSeconds = (*seconds) % SECONDS_IN_A_DAY;

    /* Get the current hour */
    timeDate->hour        = (uint16)(tempSeconds / SECONDS_IN_A_HOUR);
    /* Get the remaining seconds */
    tempSeconds           = tempSeconds % SECONDS_IN_A_HOUR;
    /* Get the minutes */
    timeDate->minutes     = (uint16)(tempSeconds / SECONDS_IN_A_MIN);
    /* Get seconds */
    timeDate->seconds     = (uint8)(tempSeconds % SECONDS_IN_A_MIN);

    /* Get the current year */
    while (numberOfDays >= daysInYear)
    {
        /* Increment year if the number of days is greater than the ones in
         * one year
         */
        timeDate->year++;
        /* Subtract the number of the days */
        numberOfDays -= daysInYear;

        /* Check if the year is leap or unleap */
        if (!Rtc_Ip_IsYearLeap(timeDate->year))
        {
            /* Set the number of non leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_YEAR;
        }
        else
        {
            /* Set the number of leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_LEAP_YEAR;
        }
    }

    /* Add the current day */
    numberOfDays += 1U;

    /* Check if the current year is leap */
    yearLeap = Rtc_Ip_IsYearLeap(timeDate->year);

    /* Get the month */
    for (index = 1U; index <= 12U; index++)
    {
        uint32 daysInCurrentMonth = ((yearLeap == TRUE) ? (uint32)LY[index] : (uint32)ULY[index]);
        if (numberOfDays <= daysInCurrentMonth)
        {
            timeDate->month = (uint16)index;
            break;
        }
        else
        {
            numberOfDays -= daysInCurrentMonth;
        }

    }

    /* Set the current day */
    timeDate->day = (uint16)numberOfDays;
}

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will convert time-date into seconds.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_ConvertTimeDateToSeconds_Activity
*/
void Rtc_Ip_ConvertTimeDateToSeconds(const Rtc_Ip_TimedateType *timeDate,
                                      uint32 * const seconds)
{
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != seconds);
    DevAssert(NULL_PTR != timeDate);
#endif

    /* Declare local variables */
    uint16 year;

    /* Convert years to seconds */
    (*seconds) = (uint32)(DAYS_IN_A_YEAR * (uint32)(SECONDS_IN_A_DAY));
    (*seconds) *= ((uint32)timeDate->year - YEAR_RANGE_START);

    /* Add the seconds from the leap years */
    for (year = YEAR_RANGE_START; year < timeDate->year; year++)
    {
        if (Rtc_Ip_IsYearLeap(year))
        {
            (*seconds) += SECONDS_IN_A_DAY;
        }
    }

    /* If the current year is leap and 29th of February has passed, add
     * another day to seconds passed.
     */
    if ((Rtc_Ip_IsYearLeap(year)) && (timeDate->month > 2U))
    {
        (*seconds) += SECONDS_IN_A_DAY;
    }

    /* Add the rest of the seconds from the current month */
    (*seconds) += MONTH_DAYS[timeDate->month] * SECONDS_IN_A_DAY;
    /* Add the rest of the seconds from the current day */
    (*seconds) += (uint32)(((uint32)timeDate->day - 1U) * (uint32)SECONDS_IN_A_DAY);
    /* Add the rest of the seconds from the current time */
    (*seconds) += (uint32)(((uint32)timeDate->hour * SECONDS_IN_A_HOUR)   + \
                           ((uint32)timeDate->minutes * SECONDS_IN_A_MIN) + \
                            (uint32)timeDate->seconds);
}

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will check if the RTCVAL or APIVAL Value written was correctly done
*                 RTC Counter
*
* @param[in]     instance           Rtc hw instance
* @param[in]     mode               compare value Mode
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Rtc_Ip_IsCounterSync_Activity
*/
Rtc_Ip_StatusType Rtc_Ip_IsCounterSync(uint8 instance,
                             Rtc_Ip_ModeType mode)
{
    Rtc_Ip_StatusType status;
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    if(RTC_IP_API_MODE == mode)
    {
        status = Rtc_Ip_IsAPICompareValueValid(instance);
    }
    else
    {
        status = Rtc_Ip_IsRTCCompareValueValid(instance);
    }

     return status;
}

#ifdef RTC_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief          Interrupt handler for RTC channel
* @details        Interrupt Service Routine corresponding to Gpt_RTC_Ch_0 hw channel.
* @param[in]      none
* @return         void
* @isr
* @pre            The driver needs to be initialized.
*/
ISR(RTC_0_Ch_0_ISR)
{
    uint8 instance = 0U;

    Rtc_Ip_ProcessInterrupt(instance);

}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* RTC_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif /*RTC_IP_C*/

/** @} */
