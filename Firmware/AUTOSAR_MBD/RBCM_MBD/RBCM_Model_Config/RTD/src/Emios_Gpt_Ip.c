/*==================================================================================================
* Project :             RTD AUTOSAR 4.7
* Platform :            CORTEXM
* Peripheral :          Stm_Pit_Rtc_Emios
* Dependencies :        none
*
* Autosar Version :     4.7.0
* Autosar Revision :    ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version :          5.0.0
* Build Version :       S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
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
*   @file       Emios_Gpt_Ip.c
*   @implements Emios_Gpt_Ip.c_Artifact
*   @addtogroup emios_ip Emios IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Gpt_Ip.h"

#if (STD_ON == EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT)
    #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EMIOS_GPT_IP_VENDOR_ID_C                    43
#define EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_C     7
#define EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_C  0
#define EMIOS_GPT_IP_SW_MAJOR_VERSION_C             5
#define EMIOS_GPT_IP_SW_MINOR_VERSION_C             0
#define EMIOS_GPT_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and Emios_Gpt_Ip.c are different"
    #endif
#endif
#endif

#if (EMIOS_GPT_IP_VENDOR_ID != EMIOS_GPT_IP_VENDOR_ID_C)
    #error "Emios_Gpt_Ip.h and Emios_Gpt_Ip.c have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION != EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and Emios_Gpt_Ip.c are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((EMIOS_GPT_IP_SW_MAJOR_VERSION != EMIOS_GPT_IP_SW_MAJOR_VERSION_C) || \
     (EMIOS_GPT_IP_SW_MINOR_VERSION != EMIOS_GPT_IP_SW_MINOR_VERSION_C) || \
     (EMIOS_GPT_IP_SW_PATCH_VERSION != EMIOS_GPT_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Emios_Gpt_Ip.h and Emios_Gpt_Ip.c are different"
#endif
/*==================================================================================================
*                                          LOCAL DEFINIES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#if (EMIOS_GPT_IP_USED == STD_ON)
#define GPT_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#include "Gpt_MemMap.h"
/**
* @brief          array variable used to store the hw channels used in Emios_Gpt_Ip driver.
*/
static boolean Emios_Gpt_Ip_bHwChannelsUsed[eMIOS_INSTANCE_COUNT][eMIOS_CH_UC_UC_COUNT] =   {
                                                                                                {
                                                                                                (boolean)FALSE
                                                                                                }
                                                                                            };

#define GPT_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of base addresses for eMios instances. */
static eMIOS_Type * const eMiosGptBase[eMIOS_INSTANCE_COUNT] = IP_eMIOS_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Gpt_MemMap.h"
static Emios_Gpt_Ip_State Emios_Gpt_Ip_u32ChState[eMIOS_INSTANCE_COUNT][eMIOS_CH_UC_UC_COUNT] = {
                                                                                                    {
                                                                                                        {
                                                                                                            (boolean)FALSE,
                                                                                                            NULL_PTR,
                                                                                                            0U,
                                                                                                            0U,
                                                                                                            0U,
                                                                                                            EMIOS_GPT_IP_CH_MODE_CONTINUOUS
                                                                                                        }
                                                                                                    }
                                                                                                };

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
static inline void Emios_Gpt_Ip_SetInterruptEnableFlag(uint8 instance, uint8 channel, boolean enable);
static inline void Emios_Gpt_Ip_ConfigureChannel(uint8 instance, uint8 channel);
static inline void Emios_Gpt_Ip_ClearInterruptFlag(uint8 instance, uint8 channel);
static inline void Emios_Gpt_Ip_SetCompareValue(uint8 instance, uint8 channel, uint32 value);
static inline void Emios_Gpt_Ip_WriteControlVal(uint8 instance, uint8 channel, uint32 value);
static inline boolean Emios_Gpt_Ip_GetInterruptEnableFlag(uint8 instance, uint8 channel);
static inline uint32 Emios_Gpt_Ip_GetCntValue(uint8 instance, uint8 channel);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief
 * Function Name : Emios_Gpt_Ip_SetInterruptEnableFlag
 * Description   : Set Interrupt Enable Flag: FEN
 *      Enables the input capture flag (Sn[FLAG]) to generate an interrupt request or a DMA request, as selected in DMA.
 *          0b - Disable
 *          1b - Enable
 *
 * @param[in]     instance     eMios hw instance number
 * @param[in]     channel      eMios hw channel number
 * @param[in]     enable       True/False
 * @return        void
 *
 */
static inline void Emios_Gpt_Ip_SetInterruptEnableFlag(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_35();
    if (TRUE == enable)
    {
        eMiosGptBase[instance]->CH.UC[channel].C |= eMIOS_C_FEN_MASK;
    }
    else
    {
        eMiosGptBase[instance]->CH.UC[channel].C &= ~eMIOS_C_FEN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_35();
}

/**
* @brief        Function Name : Emios_Gpt_Ip_GetCntValue
* @details      This function to get the current counter value in
*               counter(MC/MCB) mode.
 *
 * @param[in]     instance     eMios hw instance number
 * @param[in]     channel      eMios hw channel number
 * @return        uint32
 *
 */
static inline uint32 Emios_Gpt_Ip_GetCntValue(uint8 instance, uint8 channel)
{
    /* Read the elapsed time */
    return ((eMiosGptBase[instance]->CH.UC[channel].CNT & eMIOS_CNT_C_MASK) >> eMIOS_CNT_C_SHIFT);
}

/**
* @brief
* Function Name : Emios_Gpt_Ip_ConfigureChannel
* Description   : Configure Channel: (UC Control Reg)
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
* @return        void
*
*/
static inline void Emios_Gpt_Ip_ConfigureChannel(uint8 instance, uint8 channel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_36();
    eMiosGptBase[instance]->CH.UC[channel].C = (eMiosGptBase[instance]->CH.UC[channel].C & (~(eMIOS_C_MODE_MASK)|(eMIOS_C_EDSEL_MASK))) | ((EMIOS_C_MODE_GPI_U32)|(eMIOS_C_EDSEL_MASK));
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_36();
}


/**
* @brief
* Function Name : Emios_Gpt_Ip_ClearInterruptFlag
* Description   : Write 1 to clear : (UC Status Reg)
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
* @return        void
*
*/
static inline void Emios_Gpt_Ip_ClearInterruptFlag(uint8 instance, uint8 channel)
{
    /* Write 1 to FLAG bit to clear it */
    eMiosGptBase[instance]->CH.UC[channel].S = eMIOS_S_FLAG_MASK;
}

/**
* @brief
* Function Name : Emios_Gpt_Ip_SetCompareValue
* Description   : Set new value  : (UC A Reg)
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
* @param[in]     value        New Value
* @return        void
*
*/
static inline void Emios_Gpt_Ip_SetCompareValue(uint8 instance, uint8 channel, uint32 value)
{
    eMiosGptBase[instance]->CH.UC[channel].A = value;
}

/**
* @brief
* Function Name : Emios_Gpt_Ip_WriteControlVal
* Description   : Write value to UC C Reg
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
* @param[in]     value
*
* @return        void
*/
static inline void Emios_Gpt_Ip_WriteControlVal(uint8 instance, uint8 channel, uint32 value)
{
    eMiosGptBase[instance]->CH.UC[channel].C = value;
}

/*================================================================================================*/
#if (STD_ON == EMIOS_GPT_IP_SET_CLOCK_MODE)
/**
* @brief
* Function Name : Emios_Gpt_Ip_GetControlVal
* Description   : Read Value (UC Control Reg)
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
*
* @return        currentValueCnt
*/
static inline uint32 Emios_Gpt_Ip_GetControlVal(uint8 instance, uint8 channel)
{
    return eMiosGptBase[instance]->CH.UC[channel].C;
}
#endif /* EMIOS_GPT_IP_SET_CLOCK_MODE */

/**
 * @brief
 * Function Name : Emios_Gpt_Ip_GetInterruptEnableFlag
 * Description   : Get the state of Interrupt Enable Flag: FEN
 *
 * @param[in]   instance    eMios hw instance number
 * @param[in]   channel     eMios hw channel number
 *
  * @return TRUE if 'Interrupt Enable Flag' is set, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Emios_Gpt_Ip_GetInterruptEnableFlag(uint8 instance, uint8 channel)
{
    return (0U != (eMiosGptBase[instance]->CH.UC[channel].C & eMIOS_C_FEN_MASK)) ? TRUE : FALSE;
}

/**
* @brief
* Function Name : Emios_Gpt_Ip_GetPeriodValue
* Description   : Get the value   (UC C Reg)
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
*
* @return        currentValuePeriod
*/
uint32 Emios_Gpt_Ip_GetPeriodValue(uint8 instance, uint8 channel)
{
    uint32 currentValuePeriod;
    currentValuePeriod = eMiosGptBase[instance]->CH.UC[channel].A;
    return currentValuePeriod;

}

/*================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief
 * Function Name : Emios_Gpt_Ip_GetInterruptStatusFlag
 * Description   : Get the state of FLAG bit    (UC Status Reg)
 *
 * @param[in]   instance    eMios hw instance number
 * @param[in]   channel     eMios hw channel number
 *
 * @return  TRUE if an input capture or a match event in the comparators has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
boolean Emios_Gpt_Ip_GetInterruptStatusFlag(uint8 instance, uint8 channel)
{
    return (0U != (eMiosGptBase[instance]->CH.UC[channel].S & eMIOS_S_FLAG_MASK)) ? TRUE : FALSE;
}


/*================================================================================================*/
/**
* @brief         Function Name : Emios_Gpt_Ip_InitChannel
* @details       Initializes the EMIOS channels. This functions is called for each EMIOS hardware channel and:
*               - disables the interrupt corresponding to Emios channel
*               - puts the Emios channel into GPIO mode
*               - sets the prescaler value
*               - enables/disables the Freeze Mode
*               - clears the (pending) interrupt flag corresponding to Emios channel
*               - resets the UC A register.
* @param[in]     instance     EMIOS hardware instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Emios_Gpt_Ip_InitChannel_Activity
*/
void Emios_Gpt_Ip_InitChannel(uint8 instance, const Emios_Gpt_Ip_ChannelConfigType *configPtr)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != configPtr);
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > configPtr->hwChannel);
#endif
    uint32  u32Temp;
    eMIOS_Type * base;
    base = eMiosGptBase[instance];

    /* FLAG Disable */
    Emios_Gpt_Ip_SetInterruptEnableFlag(instance, configPtr->hwChannel, FALSE);

    /* Stop Channel to Configure Channel */
    Emios_Gpt_Ip_ConfigureChannel(instance, configPtr->hwChannel);

    /* Save current emios channel param value in local variable */
    if (TRUE == configPtr->stopInDebugMode)
    {
        u32Temp = (((uint32)configPtr->clockPrescaler << eMIOS_C_UCPRE_SHIFT) | eMIOS_C_FREN_MASK | eMIOS_C_BSL_MASK);
    }
    else
    {
        u32Temp = (((uint32)configPtr->clockPrescaler << eMIOS_C_UCPRE_SHIFT) | eMIOS_C_BSL_MASK);
    }

    /* Initialize prescale value, channel filter, freeze enable, and bus select and disable the prescaler */
    base->CH.UC[configPtr->hwChannel].C = (base->CH.UC[configPtr->hwChannel].C & ~(eMIOS_C_FREN_MASK| \
                                                                                   eMIOS_C_UCPREN_MASK| \
                                                                                   eMIOS_C_IF_MASK| \
                                                                                   eMIOS_C_FCK_MASK| \
                                                                                   eMIOS_C_BSL_MASK)) | ((u32Temp)&(eMIOS_C_FREN_MASK| \
                                                                                                                    eMIOS_C_UCPREN_MASK| \
                                                                                                                    eMIOS_C_IF_MASK| \
                                                                                                                    eMIOS_C_FCK_MASK| \
                                                                                                                    eMIOS_C_BSL_MASK));
    /* Initialize prescaler value. The two LSBs of UCEXTPRE are mirrored in UCPRE bits */
    base->CH.UC[configPtr->hwChannel].C2 &= ~eMIOS_C2_UCEXTPRE_MASK;
    base->CH.UC[configPtr->hwChannel].C2 |= eMIOS_C2_UCEXTPRE(configPtr->clockPrescaler);

    /* Clear pending interrupts */
    Emios_Gpt_Ip_ClearInterruptFlag(instance, configPtr->hwChannel);
    /* Set Compare Value to 1 (writing 0 may lead to unpredictable result ) */
    Emios_Gpt_Ip_SetCompareValue(instance, configPtr->hwChannel, 1U);

    Emios_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].chInit = TRUE;
    Emios_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].callback = configPtr->callback;
    Emios_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].callbackParam = configPtr->callbackParam;
    Emios_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].channelMode = configPtr->channelMode;
#if(STD_ON == EMIOS_GPT_IP_SET_CLOCK_MODE)
    Emios_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].clockPrescaler = configPtr->clockPrescaler;
    Emios_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].clockAlternatePrescaler = configPtr->clockAlternatePrescaler;
#endif
    /* Mark if the initialized hw channel is used*/
    Emios_Gpt_Ip_bHwChannelsUsed[instance][configPtr->hwChannel] = TRUE;
}

/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_Deinit
* @details      De-Initializes the EMIOS module. This functions is called for each EMIOS hardware instance and:
*                    - resets all channels to default

*
* @param[in]     instance     EMIOS hardware instance number
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
* @implements    Emios_Gpt_Ip_Deinit_Activity
*/
void Emios_Gpt_Ip_Deinit(uint8 instance)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
#endif

    uint8 channelIndex;
    /*Reset all channels to default*/
    for (channelIndex = 0; channelIndex < eMIOS_CH_UC_UC_COUNT; channelIndex++)
    {
        if(TRUE == Emios_Gpt_Ip_bHwChannelsUsed[instance][channelIndex])
        {
            /* Clear Interrupt Flag */
            Emios_Gpt_Ip_ClearInterruptFlag(instance, channelIndex);

            /* Reset Timer control register: Write value to reset (UC C Reg) */
            /* Internal Counter is also cleared when entering GPIO Mode */
            Emios_Gpt_Ip_WriteControlVal(instance, channelIndex, 0U);

            /* Set Compare Value to 1 (writing 0 may lead to unpredictable result ) */
            Emios_Gpt_Ip_SetCompareValue(instance, channelIndex, 1U);
        }
    }
}

/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_StartTimer
* @details      This function is called for starting the EMIOS timer channel
*
*
* @param[in]     instance        EMIOS hardware instance
* @param[in]     channel         EMIOS hardware channel
* @param[in]     compareValue    Compare value
*                With S32K39 (S32K3XX family) counter regiter is on 24bits and that for the rest the counter register is on 16bits.
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the EMIOS timer channel.
* @implements    Emios_Gpt_Ip_StartTimer_Activity
*/
void Emios_Gpt_Ip_StartTimer(uint8 instance, uint8 channel, uint32 compareValue)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > channel);
#endif
    if(compareValue < EMIOS_GPT_MAX_COUNTER)
    {
        /* Configure Channel */
        Emios_Gpt_Ip_ConfigureChannel(instance, channel);
        /* Set Compare value */
        Emios_Gpt_Ip_SetCompareValue(instance, channel, compareValue);
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_38();
        {
            /* Set UCPREN */
            eMiosGptBase[instance]->CH.UC[channel].C |= eMIOS_C_UCPREN_MASK;
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_38();
        /* TODO: ERRATA versioning*/
#ifdef ERR_IPV_EMIOS_009978
        /* FLAG Disable */
        Emios_Gpt_Ip_SetInterruptEnableFlag(instance, channel, FALSE);
#endif
        /* Set Mode MCB */
        eMiosGptBase[instance]->CH.UC[channel].C = (eMiosGptBase[instance]->CH.UC[channel].C & ~(eMIOS_C_MODE_MASK)) | (EMIOS_C_MODE_MCB_U32);
        /* TODO: ERRATA versioning*/
#ifdef ERR_IPV_EMIOS_009978
        /* Clear Interrupt Flag */
        Emios_Gpt_Ip_ClearInterruptFlag(instance, channel);
        /* FLAG Enable */
        Emios_Gpt_Ip_SetInterruptEnableFlag(instance, channel, TRUE);
#endif
    }

}

/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_StopTimer
* @details      This function is callded for stopping the EMIOS counter.
*                   - disables the EMIOS counter
*
* @param[in]     instance        EMIOS hardware instance
* @return        void
* @pre           The driver needs to be initialized. This function is called for stoping the EMIOS timer channel.
* @implements    Emios_Gpt_Ip_StopTimer_Activity
*/
void Emios_Gpt_Ip_StopTimer(uint8 instance, uint8 channel)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > channel);
#endif
    /* Stop channel configure */
    Emios_Gpt_Ip_ConfigureChannel(instance, channel);
    /* Clear Flag */
    Emios_Gpt_Ip_ClearInterruptFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_EnableChannelInterrupt
* @details      This function allows enabling interrupt generation of timer channel
*               when time-out occurs
*
* @param[in]    instance        EMIOS hardware instance
* @param[in]    channel         EMIOS hardware channel
* @return       void
* @pre          The driver needs to be initialized.
* @implements   Emios_Gpt_Ip_EnableChannelInterrupt_Activity
*/
void Emios_Gpt_Ip_EnableChannelInterrupt(uint8 instance, uint8 channel)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > channel);
#endif

    /* Clear interrupt flag */
    Emios_Gpt_Ip_ClearInterruptFlag(instance, channel);
    /* Enables FLAG */
    Emios_Gpt_Ip_SetInterruptEnableFlag(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_DisableChannelInterrupt
* @details      This function allows disabling interrupt generation of timer channel
*               when time-out occurs
*
* @param[in]     instance        EMIOS hardware instance
* @param[in]     channel         EMIOS hardware channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Emios_Gpt_Ip_DisableChannelInterrupt_Activity
*/
void Emios_Gpt_Ip_DisableChannelInterrupt(uint8 instance, uint8 channel)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > channel);
#endif

    /* Disable timer interrupt */
    Emios_Gpt_Ip_SetInterruptEnableFlag(instance, channel, FALSE);

    /* Clear interrupt flag */
    Emios_Gpt_Ip_ClearInterruptFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_GetCounterValue
* @details      This function to get the current counter value in 
*               counter(MC/MCB) mode.
*
* @param[in]     instance        EMIOS hardware instance
* @param[in]     channel         EMIOS hardware channel
 *
 * @return       uint32 - current counter value
* @pre           The driver needs to be initialized.
* @implements    Emios_Gpt_Ip_GetCounterValue_Activity
*/
uint32 Emios_Gpt_Ip_GetCounterValue(uint8 instance, uint8 channel)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > channel);
#endif

    uint32 currentCounterValue = 0;

    currentCounterValue = Emios_Gpt_Ip_GetCntValue(instance, channel);

    return currentCounterValue;
}

#if (EMIOS_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the EMIOS compare register value.
* @details This function:
*          - Write next timeout to local variable
*
* @param[in]     instance        EMIOS hardware instance
* @param[in]     channel         Channel
* @param[in]     value           Channel timeout value
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Emios_Gpt_Ip_ChangeNextTimeoutValue_Activity
*/
void Emios_Gpt_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
    DevAssert(eMIOS_CH_UC_UC_COUNT > channel);
#endif
    if(value < EMIOS_GPT_MAX_COUNTER)
    {
        /*Write timeout value*/
        Emios_Gpt_Ip_SetCompareValue(instance, channel, value);
    }
}
#endif /* EMIOS_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE */

#if (STD_ON == EMIOS_GPT_IP_SET_CLOCK_MODE)
/*================================================================================================*/
/**
* @brief        The function changes the EMIOS prescaler value.
* @details      This function sets the EMIOS prescaler based on the input mode.
*
* @param[in]    instance     EMIOS hardware instance
* @param[in]    channel      EMIOS hardware channel
* @param[in]    clockMode    EMIOS_GPT_IP_CLOCKMODE_NORMAL or EMIOS_GPT_IP_CLOCKMODE_ALTERNATE
*
* @return       void
* @pre          The driver needs to be initialized.On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
* @implements   Emios_Gpt_Ip_SetClockMode_Activity
*/
void Emios_Gpt_Ip_SetClockMode(uint8 instance, uint8 channel, Emios_Gpt_Ip_ClockModeType clockMode)
{
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(eMIOS_INSTANCE_COUNT > instance);
#endif
    uint32 TempParam = 0U;
    uint8 prescalerValue = 0U;

    if(EMIOS_GPT_IP_CLOCKMODE_NORMAL == clockMode)
    {
        prescalerValue =  Emios_Gpt_Ip_u32ChState[instance][channel].clockPrescaler;
    }
    else
    {
        prescalerValue =  Emios_Gpt_Ip_u32ChState[instance][channel].clockAlternatePrescaler;
    }

     /* Write prescaler rate at UCEXTPRE[0:3] bits in EMIOSC2[n] */
    eMiosGptBase[instance]->CH.UC[channel].C2 &= ~eMIOS_C2_UCEXTPRE_MASK;
    eMiosGptBase[instance]->CH.UC[channel].C2 |= ((((uint32)prescalerValue) << eMIOS_C2_UCEXTPRE_SHIFT) & (uint32)eMIOS_C2_UCEXTPRE_MASK);

    /* Save current emios channel param value in local variable */
    TempParam = Emios_Gpt_Ip_GetControlVal(instance, channel);

    Emios_Gpt_Ip_WriteControlVal(instance, channel, TempParam);
}
#endif /* EMIOS_GPT_IP_SET_CLOCK_MODE */


/**
* @brief   Driver routine to process all the interrupts of eMios.
* @details Non-AutoSar support function used by interrupt service routines to call notification
*          functions if provided and enabled
*
* @param[in]   instance      hardware channel index
* @param[in]   channel       channel index
*
*/
void Emios_Gpt_Ip_IrqHandler(uint8 instance, uint8 channel)
{
    boolean interruptStatusFlag;
    boolean interruptEnableFlag;
    boolean                         chInit;
    Emios_Gpt_Ip_CallbackType       callback;
    uint8                           callbackParam;
    Emios_Gpt_Ip_ChannelModeType    channelMode;

    if ((instance < eMIOS_INSTANCE_COUNT) && (channel < eMIOS_CH_UC_UC_COUNT))
    {
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10();
        {
            /* check if channel event is enabled */
            interruptStatusFlag = Emios_Gpt_Ip_GetInterruptStatusFlag(instance, channel);

            /* check if channel event has occurred */
            interruptEnableFlag = Emios_Gpt_Ip_GetInterruptEnableFlag(instance, channel);

            /* Check for spurious interrupts */
            if (interruptStatusFlag && interruptEnableFlag)
            {
                /* Clear interrupt flag */
                Emios_Gpt_Ip_ClearInterruptFlag(instance, channel);
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10();

        if (interruptStatusFlag && interruptEnableFlag)
        {
            chInit          = Emios_Gpt_Ip_u32ChState[instance][channel].chInit;
            callback        = Emios_Gpt_Ip_u32ChState[instance][channel].callback;
            channelMode     = Emios_Gpt_Ip_u32ChState[instance][channel].channelMode;
            callbackParam   = Emios_Gpt_Ip_u32ChState[instance][channel].callbackParam;
            
            /* Check if channel mode is ONE-SHOT */
            if(EMIOS_GPT_IP_CH_MODE_ONESHOT == channelMode)
            {
                Emios_Gpt_Ip_StopTimer(instance, channel);
            }

            /* Call GPT upper layer handler */
            if ((TRUE == chInit) && (NULL_PTR != callback))
            {
                callback(callbackParam);
            }
        }
    }
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
#endif /* EMIOS_GPT_IP_USED == STD_ON */
/*================================================================================================*/
#ifdef __cplusplus
}
#endif  /*EMIOS_GPT_IP_C*/
/** @} */

