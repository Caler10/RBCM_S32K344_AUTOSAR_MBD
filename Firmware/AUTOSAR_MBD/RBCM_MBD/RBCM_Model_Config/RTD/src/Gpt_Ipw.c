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
*   @file       Gpt_Ipw.c
*
*   @internal
*   @addtogroup gpt gpt_ipw
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
#include "Gpt_Ipw.h"
#include "Std_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_IPW_VENDOR_ID_C                    43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define GPT_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define GPT_IPW_SW_MAJOR_VERSION_C             5
#define GPT_IPW_SW_MINOR_VERSION_C             0
#define GPT_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_IPW_VENDOR_ID_C != GPT_IPW_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt_Ipw.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Std_Types.h are different"
    #endif

    #if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Gpt_Ipw.c are different"
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#if (STM_IP_USED == STD_ON)
    /**
    * @brief Number of counter cycles missed due to overflow
    */
    #define STM_OVERFLOW_PAD_U32         ((uint32)1U)

    /**
    * @brief Highest possible value for STM channels
    */
    #define STM_CNT_MAX_VALUE_U32        ((uint32)0xFFFFFFFFUL)
#endif


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (RTC_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_RtcGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
#if (STM_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_StmGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
#if (PIT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_PitGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
#if (EMIOS_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_EmiosGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    /* Read the current target time before to read the elapsed time. */
    pReturnHwChannelInfo->uTargetTime = Emios_Gpt_Ip_GetPeriodValue(pHwChannelConfig->instance, pHwChannelConfig->channel);

    Gpt_ValueType returnValue = Emios_Gpt_Ip_GetCounterValue(pHwChannelConfig->instance, pHwChannelConfig->channel);

    /* Check for interrupt status flag */
    boolean interruptStatusFlag = Emios_Gpt_Ip_GetInterruptStatusFlag(pHwChannelConfig->instance, pHwChannelConfig->channel);
    if (TRUE == interruptStatusFlag)
    {
        /* Channel counter was rollover */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not rollover */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return returnValue;
}
#endif

#if (RTC_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_RtcGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    Gpt_ValueType returnValue;
    uint32 tempValue;
    boolean apiInterruptStatusFlag;
    
    /* Read compare and counter registers */
    uint32 compareValue = Rtc_Ip_GetAPICompareRegister(pHwChannelConfig->instance);
    uint32 counterValue = Rtc_Ip_GetCounterRegister(pHwChannelConfig->instance);

    /* Calculate the elapsed time */
    if (counterValue >= compareValue)
    {
        tempValue = Rtc_Ip_u32CounterValueInterrupt - counterValue;
    }
    else
    {
        tempValue = compareValue - counterValue;
    }
    
    pReturnHwChannelInfo->uTargetTime = Rtc_Ip_u32TargetValue;

    if (tempValue > pReturnHwChannelInfo->uTargetTime)
    {
        returnValue = pReturnHwChannelInfo->uTargetTime;
    }
    else
    {
        returnValue = pReturnHwChannelInfo->uTargetTime;
        returnValue -= tempValue;
    }

    /* Check interrupt status flag */
    apiInterruptStatusFlag = Rtc_Ip_GetInterruptStatusFlag(pHwChannelConfig->instance, RTC_IP_API_INTERRUPT);
    if (TRUE == apiInterruptStatusFlag)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return returnValue;
}
#endif


#if (STM_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_StmGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    Gpt_ValueType returnValue;
    uint32 tempValue;
    boolean HasChEvOccurred;

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08();
    /* Read compare and counter registers */
    uint32 counterValue = Stm_Ip_GetCounterValue(pHwChannelConfig->instance);
    uint32 compareValue = Stm_Ip_GetCompareValue(pHwChannelConfig->instance, pHwChannelConfig->channel);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08();

    /* Calculate the elapsed time */
    if (counterValue >= compareValue)
    {
        tempValue = ((STM_CNT_MAX_VALUE_U32 - counterValue) + compareValue) + STM_OVERFLOW_PAD_U32;
    }
    else
    {
        tempValue = compareValue - counterValue;
    }

    pReturnHwChannelInfo->uTargetTime = Stm_Ip_u32TargetValue[pHwChannelConfig->instance][pHwChannelConfig->channel];

    if (tempValue > pReturnHwChannelInfo->uTargetTime)
    {
        returnValue = (pReturnHwChannelInfo->uTargetTime);
    }
    else
    {
        returnValue = pReturnHwChannelInfo->uTargetTime;
        returnValue -= tempValue;
    }

    /* Check interrupt status flag */
    HasChEvOccurred = Stm_Ip_GetInterruptStatusFlag(pHwChannelConfig->instance, pHwChannelConfig->channel);
    if (TRUE == HasChEvOccurred)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return returnValue;
}
#endif

#if (PIT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_PitGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
#if(PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
    pReturnHwChannelInfo->uTargetTime = Pit_Ip_u32OldTargetValue;
#endif
    pReturnHwChannelInfo->uTargetTime = Pit_Ip_GetLoadValue(pHwChannelConfig->instance, pHwChannelConfig->channel);
    pReturnHwChannelInfo->uTargetTime += 1U;

    Gpt_ValueType returnValue = ((pReturnHwChannelInfo->uTargetTime) - Pit_Ip_GetCurrentTimer(pHwChannelConfig->instance, pHwChannelConfig->channel));

    /* check if channel event has occurred */
    boolean HasChEvOccurred = Pit_Ip_GetInterruptStatusFlag(pHwChannelConfig->instance, pHwChannelConfig->channel);
    if (HasChEvOccurred)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return returnValue;
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief        Gpt driver Autosar independent and IP dependent initialization function.
* @details      This Gpt_Ipw_InitInstances is called once for each channel in the used configuration.
*               It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    configPtr    Pointer to the channel configuration structure dependent by platform
*
* @return       void
* @pre          The driver needs to be initialized.
*/
void Gpt_Ipw_InitInstances(const Gpt_ConfigType * configPtr)
{

    uint8 index = 0U;

    for(index = 0; index < configPtr->instanceCount; index++)
    {
        switch((*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].instanceType)
        {
#if (PIT_IP_USED == STD_ON)
            case(GPT_PIT_MODULE):
            {
                Pit_Ip_Init((*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].instance,
                            (*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].Gpt_Ipw_InstanceConfig.Pit_Ip_InstanceConfig);
            }
            break;
#endif
#if (STM_IP_USED == STD_ON)
            case(GPT_STM_MODULE):
            {
                Stm_Ip_Init((*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].instance,
                            (*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].Gpt_Ipw_InstanceConfig.Stm_Ip_InstanceConfig);
            }
            break;
#endif

#if (EMIOS_GPT_IP_USED == STD_ON)
            case(GPT_EMIOS_MODULE):
            {
                /*EMIOS is empty because it shall not be executed for InitInstances */
            }
            break;
#endif

#if (RTC_IP_USED == STD_ON)
            case(GPT_RTC_MODULE):
            {
                /*RTC is empty because it shall not be executed for InitInstances */
            }
            break;
#endif
            default:
                /*This switch branch is empty because it shall not be executed for normal behaviour*/
            break;
        }
    }
    return;
}

/**
* @brief        Gpt driver Autosar independent and IP dependent initialization function.
* @details      This function Gpt_Ipw_Init is called once for each channel in the used configuration.
*               It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized.
*/
void Gpt_Ipw_Init(const Gpt_Ipw_HwChannelConfigType *pHwChannelConfig)
{

    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case(GPT_PIT_MODULE):
        {
            Pit_Ip_InitChannel(pHwChannelConfig->instance,
                               pHwChannelConfig->Gpt_Ipw_ChannelConfig.Pit_Ip_ChannelConfig);
        }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case(GPT_STM_MODULE):
        {
            Stm_Ip_InitChannel(pHwChannelConfig->instance,
                               pHwChannelConfig->Gpt_Ipw_ChannelConfig.Stm_Ip_ChannelConfig);
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
        {
            Emios_Gpt_Ip_InitChannel(pHwChannelConfig->instance,
                                     pHwChannelConfig->Gpt_Ipw_ChannelConfig.Emios_Gpt_Ip_ChannelConfig);
        }
        break;
#endif
#if (RTC_IP_USED == STD_ON)
        case(GPT_RTC_MODULE):
        {
            Rtc_Ip_Init(pHwChannelConfig->instance,
                        pHwChannelConfig->Gpt_Ipw_ChannelConfig.Rtc_Ip_Config);
        }
        break;
#endif
        default:
            /* This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }
    return;
}
/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and platform dependent function for starting the timer channel.
* @details       It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*                IP function for starting the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uValue              Timeout period (in ticks) after which a notification shall occur (if enabled).
* @return        void
* @pre           The driver needs to be initialized.Call Gpt_StartTimer before.
*/
Std_ReturnType Gpt_Ipw_StartTimer(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_ValueType uValue)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case(GPT_PIT_MODULE):
            {
                returnValue = (Std_ReturnType)Pit_Ip_StartChannel(pHwChannelConfig->instance,
                                                                  pHwChannelConfig->channel, (uint32)uValue);
            }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case(GPT_STM_MODULE):
            {
                Stm_Ip_StartCounting(pHwChannelConfig->instance,
                                     pHwChannelConfig->channel,
                                     (uint32)uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
            {
                Emios_Gpt_Ip_StartTimer(pHwChannelConfig->instance,
                                        pHwChannelConfig->channel,
                                        (uint32)uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
        break;
#endif
#if (RTC_IP_USED == STD_ON)
        case(GPT_RTC_MODULE):
            {
                Rtc_Ip_StartTimer(pHwChannelConfig->instance,
                                  (uint32)uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }

    return returnValue;
}

/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and IP dependent function for fetching the elapsed timer value.
* @details       It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*                appropriate IP function for reading the elapsed timer value from the HW.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uTargetTime         Target time value
* @param[out]    pbReturnChannelOverflow  Rollover status flag value of the hardware timer channel
* @return        returnValue         The elapsed time
* @pre           The driver needs to be initialized.Call GetTimeElapsed before.
*
*/
Gpt_ValueType Gpt_Ipw_GetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                      Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    Gpt_ValueType returnValue = 0U;

switch(pHwChannelConfig->instanceType)
{
#if (PIT_IP_USED == STD_ON)
   case(GPT_PIT_MODULE):
    {
        returnValue = Gpt_Ipw_PitGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
    }
    break;
#endif
#if (STM_IP_USED == STD_ON)
    case(GPT_STM_MODULE):
    {
        returnValue = Gpt_Ipw_StmGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
    }
    break;
#endif
#if (RTC_IP_USED == STD_ON)
    case(GPT_RTC_MODULE):
    {
        returnValue = Gpt_Ipw_RtcGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
    }
    break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
    case(GPT_EMIOS_MODULE):
    {
        returnValue = Gpt_Ipw_EmiosGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
    }
    break;
#endif
    default:
         /*This switch branch is empty because it shall not be executed for normal behaviour*/
    break;
}
    return returnValue;
}


/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and platform dependent function for stopping the timer channel.
* @details       It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*                IP function for stopping the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.Call StopTimer before.
*/
void Gpt_Ipw_StopTimer(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case(GPT_PIT_MODULE):
        {
            Pit_Ip_StopChannel(pHwChannelConfig->instance,
                               pHwChannelConfig->channel);
        }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case(GPT_STM_MODULE):
        {
            /*TBD: check if we need to store value of channel */
            Stm_Ip_DisableChannel(pHwChannelConfig->instance,
                                  pHwChannelConfig->channel);
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
        {
            Emios_Gpt_Ip_StopTimer(pHwChannelConfig->instance,
                                   pHwChannelConfig->channel);
        }
        break;
#endif
#if (RTC_IP_USED == STD_ON)
        case(GPT_RTC_MODULE):
        {
            Rtc_Ip_StopTimer(pHwChannelConfig->instance);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and platform dependent function for enabling hardware timer interrupts.
* @details       It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*                IP function for enabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.
*/
void Gpt_Ipw_EnableInterrupt(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case(GPT_PIT_MODULE):
        {
            Pit_Ip_EnableChannelInterrupt(pHwChannelConfig->instance, pHwChannelConfig->channel);
        }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case(GPT_STM_MODULE):
        {
            /*For a STM enabled channel the interrupts are always activated*/
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
        {
           Emios_Gpt_Ip_EnableChannelInterrupt(pHwChannelConfig->instance, pHwChannelConfig->channel);
        }
        break;
#endif
#if (RTC_IP_USED == STD_ON)
        case(GPT_RTC_MODULE):
        {
            Rtc_Ip_EnableInterrupt(pHwChannelConfig->instance, RTC_IP_API_INTERRUPT);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief         Gpt driver Autosar independent and IP dependent de-initialization function.
* @details       This function is called for each  channel from the current configuration.
*                It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*                appropriate IP function in order to de-initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized. On/Off by the configuration parameter: GPT_DEINIT_API
*/
void Gpt_Ipw_DeInit(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case(GPT_PIT_MODULE):
        {
            Pit_Ip_Deinit(pHwChannelConfig->instance);
        }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case(GPT_STM_MODULE):
        {
           Stm_Ip_Deinit(pHwChannelConfig->instance);
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
        {
           Emios_Gpt_Ip_Deinit(pHwChannelConfig->instance);
        }
        break;
#endif
#if (RTC_IP_USED == STD_ON)
        case(GPT_RTC_MODULE):
        {
           Rtc_Ip_DeInit(pHwChannelConfig->instance);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
    return;
}

#endif
/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief         Gpt driver Autosar independent and platform dependent function for disabling hardware timer interrupts.
* @details       It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*                IP function for disabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*/
void Gpt_Ipw_DisableInterrupt(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case(GPT_PIT_MODULE):
        {
            Pit_Ip_DisableChannelInterrupt(pHwChannelConfig->instance, pHwChannelConfig->channel);
        }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case(GPT_STM_MODULE):
        {
            /*For a STM enabled channel the interrupts are always activated*/
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
        {
           Emios_Gpt_Ip_DisableChannelInterrupt(pHwChannelConfig->instance, pHwChannelConfig->channel);
        }
        break;
#endif
#if (RTC_IP_USED == STD_ON)
        case(GPT_RTC_MODULE):
        {
            Rtc_Ip_DisableInterrupt(pHwChannelConfig->instance, RTC_IP_API_INTERRUPT);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}
#endif
/*================================================================================================*/

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief        Gpt driver Autosar independent and IP dependent function to change STM/PIT/eMIOS compare register value.
* @details      This function:
*                - Write next timeout to local variable
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent
*                                       by platform
* @param[in]     value               New Timeout period (in ticks) after which a notification
*                                       shall occur (if enabled).
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_CHANGE_NEXT_TIMEOUT_VALUE
*
*/

Std_ReturnType Gpt_Ipw_ChangeNextTimeoutValue(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                               Gpt_ValueType value)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case (GPT_PIT_MODULE):
        {
            Pit_Ip_ChangeNextTimeoutValue(pHwChannelConfig->instance, pHwChannelConfig->channel, (uint32)value);
            returnValue =(Std_ReturnType)E_OK;
        }
        break;
#endif
#if (STM_IP_USED == STD_ON)
        case (GPT_STM_MODULE):
        {
            Stm_Ip_ChangeNextTimeoutValue(pHwChannelConfig->instance, pHwChannelConfig->channel, (uint32)value);
            returnValue =(Std_ReturnType)E_OK;
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case(GPT_EMIOS_MODULE):
        {
           Emios_Gpt_Ip_ChangeNextTimeoutValue(pHwChannelConfig->instance, pHwChannelConfig->channel, (uint32)value);
           returnValue =(Std_ReturnType)E_OK;
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }

    return returnValue;
}
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */

/*================================================================================================*/
/**
* @brief         Gpt_Ipw_SetClockModeInStance
* @details       Calls the SetClockModeInStance for instance
*
* @param[in]     pHwInstanceConfig   Pointer to the Instance configuration structure dependent by platform
* @param[in]     clkMode             Clock mode for configuration channel
*
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_SET_CLOCK_MODE
*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
void Gpt_Ipw_SetClockModeInStance(const Gpt_Ipw_HwInstanceConfigType * pHwInstanceConfig,
                                                    Gpt_ClockModeType clkMode)
{

    switch(pHwInstanceConfig->instanceType)
    {
#if (STM_IP_USED == STD_ON)
        case (GPT_STM_MODULE):
        {
            if(GPT_CLOCKMODE_NORMAL == clkMode)
            {
                Stm_Ip_SetClockMode(pHwInstanceConfig->instance, STM_IP_CLOCKMODE_NORMAL);
            }
            else
            {
                Stm_Ip_SetClockMode(pHwInstanceConfig->instance, STM_IP_CLOCKMODE_ALTERNATE);
            }
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case (GPT_EMIOS_MODULE):
        {
            /* To Do Nothing*/
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
}

/**
* @brief         Gpt_Ipw_SetClockModeChannel
* @details       Calls the SetClockModeChannel for channel
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     clkMode             Clock mode for configuration channel
*
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_SET_CLOCK_MODE
*/
void Gpt_Ipw_SetClockModeChannel(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                    Gpt_ClockModeType clkMode)
{

    switch(pHwChannelConfig->instanceType)
    {
#if (STM_IP_USED == STD_ON)
        case (GPT_STM_MODULE):
        {
            /* To Do Nothing*/
        }
        break;
#endif
#if (EMIOS_GPT_IP_USED == STD_ON)
        case (GPT_EMIOS_MODULE):
        {
            if(GPT_CLOCKMODE_NORMAL == clkMode)
            {
                Emios_Gpt_Ip_SetClockMode(pHwChannelConfig->instance, pHwChannelConfig->channel, EMIOS_GPT_IP_CLOCKMODE_NORMAL);
            }
            else
            {
                Emios_Gpt_Ip_SetClockMode(pHwChannelConfig->instance, pHwChannelConfig->channel, EMIOS_GPT_IP_CLOCKMODE_ALTERNATE);
            }
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
            (void)clkMode;
        break;
    }
}
#endif /* GPT_SET_CLOCK_MODE == STD_ON */
/*================================================================================================*/
#if(GPT_CHAIN_MODE == STD_ON)
/**
* @brief         The function Gpt_Ipw_EnableChainMode.
* @details       This function:
*               - Chain the timer.
*
* @param[in]     pHwChannelConfig        Pointer to the channel configuration structure dependent by platform
* @return        returnValue
* @pre           The driver needs to be initialized. CHAIN_MODE == STD_ON
*/
Std_ReturnType Gpt_Ipw_EnableChainMode(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case (GPT_PIT_MODULE):
        returnValue = (Std_ReturnType)Pit_Ip_ChainMode(pHwChannelConfig->instance, pHwChannelConfig->channel, TRUE);
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
    return returnValue;
}
#endif /*(GPT_CHAIN_MODE == STD_ON)*/
/*================================================================================================*/
#if(GPT_CHAIN_MODE == STD_ON)
/**
* @brief         The function Gpt_Ipw_DisableChainMode.
* @details       This function:
*               - Chain the timer.
*
* @param[in]     pHwChannelConfig        Pointer to the channel configuration structure dependent by platform
* @return        returnValue
* @pre           The driver needs to be initialized. CHAIN_MODE == STD_ON
*/
Std_ReturnType Gpt_Ipw_DisableChainMode(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (PIT_IP_USED == STD_ON)
        case (GPT_PIT_MODULE):
        returnValue = (Std_ReturnType)Pit_Ip_ChainMode(pHwChannelConfig->instance, pHwChannelConfig->channel, FALSE);
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
    return returnValue;
}
#endif /*(GPT_CHAIN_MODE == STD_ON)*/
/*================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief        Gpt driver Autosar start predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized. On/Off GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/

void Gpt_Ipw_StartPredefTimer
(
    const Gpt_ConfigType * configPtr
)
{
    Gpt_ChannelType channel;
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig;

    for(channel = 0U; channel < GPT_HW_PREDEFTIMER_NUM; channel++)
    {
        pHwChannelConfig = (configPtr->Gpt_pChannelPredefConfigType)[channel];

        if(NULL_PTR != pHwChannelConfig)
        {
            switch(pHwChannelConfig->instanceType)
            {
#if (STM_IP_USED == STD_ON)
            case (GPT_STM_MODULE):
            {
                Stm_Ip_PredefCounting(pHwChannelConfig->instance, \
                                      pHwChannelConfig->Gpt_uPrescaler, \
                                      pHwChannelConfig->Gpt_bFreezeEnable);

            }
            break;
#endif
            default:
                /*This switch branch is empty because it shall not be executed for normal behaviour*/
            break;
            }

        }

    }

    return;
}

/**
* @brief        Gpt driver Autosar get value of predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]    TimeValuePtr        The pointer using for save current value of hardware channel
* @param[in]    PredefTimer         Gpt_PredefTimerType
* @return       void
* @pre          The driver needs to be initialized. On/Off GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/
void Gpt_Ipw_GetPredefTimerValue
(
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig,
    Gpt_PredefTimerType PredefTimer,
    uint32 * TimeValuePtr
)
{
    uint32 u32ReturnValue = 0U;
    switch(pHwChannelConfig->instanceType)
    {
#if (STM_IP_USED == STD_ON)
        case (GPT_STM_MODULE):
        {
            u32ReturnValue = Stm_Ip_GetCounterValue(pHwChannelConfig->instance);
            switch(PredefTimer)
            {
                case GPT_PREDEF_TIMER_1US_16BIT:
                    *TimeValuePtr = (0x0000FFFFU & u32ReturnValue);
                break;
                case GPT_PREDEF_TIMER_1US_24BIT:
                    *TimeValuePtr = (0x00FFFFFFU & u32ReturnValue);
                break;
                case GPT_PREDEF_TIMER_1US_32BIT:
                    *TimeValuePtr = u32ReturnValue;
                break;
                case GPT_PREDEF_TIMER_100US_32BIT:
                    *TimeValuePtr = u32ReturnValue;
                break;
                default:
                    /* 32bit timer */
                break;
            }
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/**
* @brief        Gpt driver Autosar stop predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel (e.g. eMios, STM,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized. GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/
void Gpt_Ipw_StopPredefTimer
(
    const Gpt_ConfigType * configPtr
)
{
    Gpt_ChannelType channel;
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig;

    for(channel = 0U; channel < GPT_HW_PREDEFTIMER_NUM; channel++)
    {

        pHwChannelConfig = (configPtr->Gpt_pChannelPredefConfigType)[channel];
        if(NULL_PTR != pHwChannelConfig)
        {
            switch(pHwChannelConfig->instanceType)
            {
#if (STM_IP_USED == STD_ON)
            case GPT_STM_MODULE:
            {
                Stm_Ip_StopTimer(pHwChannelConfig->instance);
            }
            break;
#endif
            default:
                /*This switch branch is empty because it shall not be executed for normal behaviour*/
            break;
            }
        }
    }
    return;
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
/** @} */
#endif/*GPT_IPW_C*/
