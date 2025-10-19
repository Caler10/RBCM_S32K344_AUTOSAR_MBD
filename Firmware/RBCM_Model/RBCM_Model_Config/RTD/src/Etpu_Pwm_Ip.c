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
 *   @file       Etpu_Pwm_Ip.c
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
#include "Etpu_Pwm_Ip.h"
#include "SchM_Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETPU_PWM_IP_VENDOR_ID_C                     43
#define ETPU_PWM_IP_MODULE_ID_C                     121
#define ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION_C      4
#define ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION_C      7
#define ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION_C   0
#define ETPU_PWM_IP_SW_MAJOR_VERSION_C              5
#define ETPU_PWM_IP_SW_MINOR_VERSION_C              0
#define ETPU_PWM_IP_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this source file and SchM_Pwm.h file are of the same Autosar version */
    #if ((ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_PWM_AR_RELEASE_MAJOR_VERSION) || \
         (ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_PWM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Etpu_Pwm_Ip.c and SchM_Pwm.h are different"
    #endif
#endif

/* Check if Etpu_Pwm_Ip.c and Etpu_Pwm_Ip.h are of the same vendor */
#if (ETPU_PWM_IP_VENDOR_ID_C != ETPU_PWM_IP_VENDOR_ID)
#error "Vendor IDs of Etpu_Pwm_Ip.c and Etpu_Pwm_Ip.h are different."
#endif

/* Check if Etpu_Pwm_Ip.c and Etpu_Pwm_Ip.h are of the same AUTOSAR version */
#if ((ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION_C  != ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION_C != ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION_C != ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR version numbers of Etpu_Pwm_Ip.c and Etpu_Pwm_Ip.h are different."
#endif

/* Check if Etpu_Pwm_Ip.c and Etpu_Pwm_Ip.h are of the same software version */
#if ((ETPU_PWM_IP_SW_MAJOR_VERSION_C != ETPU_PWM_IP_SW_MAJOR_VERSION) || \
     (ETPU_PWM_IP_SW_MINOR_VERSION_C != ETPU_PWM_IP_SW_MINOR_VERSION) || \
     (ETPU_PWM_IP_SW_PATCH_VERSION_C != ETPU_PWM_IP_SW_PATCH_VERSION))
#error "Software version numbers of Eptu_Pwm_Ip.c and Etpu_Pwm_Ip.h are different."
#endif

#if (ETPU_PWM_IP_USED == STD_ON)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/** @brief Maximum value of the duty cycle (100% duty) */
#define ETPU_PWM_IP_MAX_DUTY 0x8000U

/** @brief onversion from number of bytes to number of words (4-byte chunks) including granularity alignment to 8 bytes */
#define ETPU_PWM_IP_BYTES_TO_WORDS_8B_ALIGN(x) ((((uint32)(x) + 7U) >> 3) << 1)

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
#if (ETPU_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/** @brief Array with notification handlers for all configurable channels */
Etpu_Pwm_Ip_NotificationType *aEtpu_Pwm_Ip_NotificationPtr[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

/** @brief Array to check the state of PWM channels */
Etpu_Pwm_Ip_StateType aEtpu_Pwm_Ip_ModuleState[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the period values for each channel */
Etpu_Ip_Uint24Type aEtpu_Pwm_Ip_Period[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the duty cycle values for each channel */
Etpu_Ip_Uint24Type aEtpu_Pwm_Ip_DutyCycle[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

#if (ETPU_PWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"


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

Etpu_Ip_ErrorType Etpu_Pwm_Ip_Init(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                   Etpu_Pwm_Ip_ConfigType *pPwmConfig)
{
    uint32 *pCpba; /* channel parameter base address */
    Etpu_Ip_ErrorType eErrorCode = ETPU_ERROR_NONE; /* error return status*/
    uint8 u8EtpuEng = (uint8)ETPU_PWM_IP_GET_ENGINE(pPwmInstance->u8Channel);
    uint8 u8EtpuCh = (uint8)Etpu_Ip_GetChannel(pPwmInstance->u8Channel);

    /* disable channel to assign function safely */
    Etpu_Ip_DisableChannel(pPwmInstance->u8Channel);

    pCpba = pPwmInstance->pCpba;
    if (pCpba == NULL_PTR)
    {
        pCpba = Etpu_Ip_Malloc2(pPwmInstance->u8Channel, ETPU_PWM_IP_NUM_PARMS);
        if (pCpba == NULL_PTR)
        {
            eErrorCode = ETPU_ERROR_MALLOC;
        }
        else
        {
            pPwmInstance->pCpba = pCpba;
        }
    }

    if (ETPU_ERROR_NONE == eErrorCode)
    {
        Etpu_Ip_DisableInterrupt(pPwmInstance->u8Channel);

        pPwmInstance->u8StartMode |= ETPU_PWM_IP_ENABLE_FLAG;

        if (pPwmInstance->pRefAddress != NULL_PTR)
        {
            pPwmInstance->pRefAddress = (uint32*)((uint32)pPwmInstance->pRefAddress - (uint32)ETPU_PWM_IP_DATA_RAM_START);
        }

        aEtpu_Pwm_Ip_NotificationPtr[u8EtpuEng][u8EtpuCh] = &pPwmInstance->UserCallback;
        aEtpu_Pwm_Ip_Period[u8EtpuEng][u8EtpuCh] = pPwmConfig->u24Period;
        aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh] = (Etpu_Ip_Uint24Type)(((uint64)pPwmConfig->u24Period * pPwmConfig->u16DutyCycle) / ETPU_PWM_IP_MAX_DUTY);

        /* write parameters to data memory */
        Etpu_Ip_WriteU24Param(pCpba, ETPU_PWM_IP_OFFSET_PERIOD, aEtpu_Pwm_Ip_Period[u8EtpuEng][u8EtpuCh]);
        Etpu_Ip_WriteU24Param(pCpba, ETPU_PWM_IP_OFFSET_ACTIVE, aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh]);
        Etpu_Ip_WriteU24Param(pCpba, ETPU_PWM_IP_OFFSET_START_OFFSET, pPwmInstance->u24StartDelay);
        Etpu_Ip_WriteU24Param(pCpba, ETPU_PWM_IP_OFFSET_REF_ADDRESS, (Etpu_Ip_Uint24Type)pPwmInstance->pRefAddress);
        Etpu_Ip_WriteU8Param((uint8*)pCpba, ETPU_PWM_IP_OFFSET_START_MODE, pPwmInstance->u8StartMode);
        Etpu_Ip_WriteU8Param((uint8*)pCpba, ETPU_PWM_IP_OFFSET_IRQ_OPTION, (uint8)pPwmConfig->eInterruptSource);

        /* write channel configuration register */
        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].CR.B.CPR = (uint8)pPwmInstance->ePriority;
        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].CR.B.ETCS = ETPU_PWM_IP_TABLE_SELECT;
        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].CR.B.CFS = ETPU_PWM_IP_FUNCTION_NUMBER;
        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].CR.B.CPBA = ((uint32)pCpba - (uint32)ETPU_PWM_IP_DATA_RAM_START) >> 3U;

        /* write FM (function mode) bits */
        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].SCR.B.FM = (uint32)pPwmInstance->eTimebase + (uint8)pPwmInstance->ePolarity;

        /* write hsr to start channel running */
        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].HSRR.B.HSR = ETPU_PWM_IP_HSR_INIT;

        /* Confirm the Channel is active */
        aEtpu_Pwm_Ip_ModuleState[u8EtpuEng][u8EtpuCh] = ETPU_PWM_INIT_STATE;
    }

    return eErrorCode;
}

/*================================================================================================*/
void Etpu_Pwm_Ip_DeInit(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                        Etpu_Ip_PinStateType ePinState)
{
    uint8 u8EtpuEng = (uint8)ETPU_PWM_IP_GET_ENGINE(pPwmInstance->u8Channel);
    uint8 u8EtpuCh = (uint8)Etpu_Ip_GetChannel(pPwmInstance->u8Channel);

    Etpu_Pwm_Ip_StopAndSetPin(pPwmInstance, ePinState);
    Etpu_Ip_ClearChannelInterruptFlag(pPwmInstance->u8Channel);
    Etpu_Ip_DisableInterrupt(pPwmInstance->u8Channel);
    Etpu_Ip_DisableChannel(pPwmInstance->u8Channel);

    /* clean pointer for callback */
    aEtpu_Pwm_Ip_NotificationPtr[u8EtpuEng][u8EtpuCh] = NULL_PTR;
    aEtpu_Pwm_Ip_Period[u8EtpuEng][u8EtpuCh] = 0U;
    aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh] = 0U;

    /* clean memory region for channel */
    Etpu_Ip_MemsetU32(pPwmInstance->pCpba,
                      0U,
                      (uint32)ETPU_PWM_IP_BYTES_TO_WORDS_8B_ALIGN(ETPU_PWM_IP_NUM_PARMS));

    /* Confirm the Channel is in-active */
    aEtpu_Pwm_Ip_ModuleState[u8EtpuEng][u8EtpuCh] = ETPU_PWM_UNINIT_STATE;
}

/*================================================================================================*/
void Etpu_Pwm_Ip_UpdateDuty(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                            Etpu_Pwm_Ip_ConfigType *pPwmConfig)
{
    Etpu_Ip_Uint24Type u24ChannelPeriod;
    uint8 u8EtpuEng = (uint8)ETPU_PWM_IP_GET_ENGINE(pPwmInstance->u8Channel);
    uint8 u8EtpuCh = (uint8)Etpu_Ip_GetChannel(pPwmInstance->u8Channel);

    u24ChannelPeriod = Etpu_Ip_ReadU24Param(pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_PERIOD);

    aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh] = (Etpu_Ip_Uint24Type)(((uint64)u24ChannelPeriod * pPwmConfig->u16DutyCycle) / ETPU_PWM_IP_MAX_DUTY);

    Etpu_Ip_WriteU24Param(pPwmInstance->pCpba,
                          ETPU_PWM_IP_OFFSET_ACTIVE,
                          aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh]);
}

/*================================================================================================*/
void Etpu_Pwm_Ip_UpdateDutyImmed(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                 Etpu_Pwm_Ip_ConfigType *pPwmConfig)
{
    Etpu_Ip_Uint24Type u24ChannelPeriod;
    uint8 u8EtpuEng = (uint8)ETPU_PWM_IP_GET_ENGINE(pPwmInstance->u8Channel);
    uint8 u8EtpuCh = (uint8)Etpu_Ip_GetChannel(pPwmInstance->u8Channel);

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_35();

    u24ChannelPeriod = Etpu_Ip_ReadU24Param(pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_PERIOD);

    aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh] = (Etpu_Ip_Uint24Type)(((uint64)u24ChannelPeriod * pPwmConfig->u16DutyCycle) / ETPU_PWM_IP_MAX_DUTY);

    Etpu_Ip_WriteU24Param(pPwmInstance->pCpba,
                          ETPU_PWM_IP_OFFSET_ACTIVE,
                          aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh]);

    /* do immediate update of duty cycle is possible */
    pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].HSRR.B.HSR = ETPU_PWM_IP_HSR_IMM_UPDATE;

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_35();
}

/*================================================================================================*/
Etpu_Ip_ErrorType Etpu_Pwm_Ip_Update(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                     Etpu_Pwm_Ip_ConfigType *pPwmConfig)
{
    Etpu_Ip_ErrorType eRetStatus = ETPU_ERROR_NONE;  /* error return status*/
    uint8 u8EtpuEng = (uint8)ETPU_PWM_IP_GET_ENGINE(pPwmInstance->u8Channel);
    uint8 u8EtpuCh = (uint8)Etpu_Ip_GetChannel(pPwmInstance->u8Channel);

    if (pPwmConfig->u24Period > (Etpu_Ip_Uint24Type)ETPU_PWM_IP_MAX_PERIOD)
    {
        eRetStatus = ETPU_ERROR_PERIOD;
    }
    else
    {
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_36();

        aEtpu_Pwm_Ip_Period[u8EtpuEng][u8EtpuCh] = pPwmConfig->u24Period;
        aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh] = (Etpu_Ip_Uint24Type)(((uint64)pPwmConfig->u24Period * pPwmConfig->u16DutyCycle) / ETPU_PWM_IP_MAX_DUTY);

        /* write parameters to data memory */
        Etpu_Ip_WriteU24Param(pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_CO_PERIOD, aEtpu_Pwm_Ip_Period[u8EtpuEng][u8EtpuCh]);
        Etpu_Ip_WriteU24Param(pPwmInstance->pCpba,
                              ETPU_PWM_IP_OFFSET_CO_ACTIVE,
                              aEtpu_Pwm_Ip_DutyCycle[u8EtpuEng][u8EtpuCh]);

        pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].HSRR.B.HSR = ETPU_PWM_IP_HSR_CO_UPDATE;

        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_36();
    }

    return eRetStatus;
}

/*================================================================================================*/
void Etpu_Pwm_Ip_UpdateInterruptMode(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                                     Etpu_Pwm_Ip_ConfigType *pPwmConfig)
{
    Etpu_Pwm_Ip_InterruptSourceType eNewInterruptSource = pPwmConfig->eInterruptSource;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_45();

    Etpu_Ip_ClearChannelInterruptFlag(pPwmInstance->u8Channel);

    /* enable interrupt */
    if (ETPU_PWM_INTERRUPT_SOURCE_NONE != eNewInterruptSource)
    {
        Etpu_Ip_EnableInterrupt(pPwmInstance->u8Channel);
    }

    /* select the source of the interrupt */
    Etpu_Ip_WriteU8Param((uint8*)pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_IRQ_OPTION, (uint8)eNewInterruptSource);

    /* disable interrupt */
    if (ETPU_PWM_INTERRUPT_SOURCE_NONE == eNewInterruptSource)
    {
        Etpu_Ip_DisableInterrupt(pPwmInstance->u8Channel);
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_45();
}

/*================================================================================================*/
Etpu_Ip_Uint24Type Etpu_Pwm_Ip_GetPeriod(Etpu_Pwm_Ip_InstanceType *pPwmInstance)
{
    return Etpu_Ip_ReadU24Param(pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_PERIOD);
}

/*================================================================================================*/
uint16 Etpu_Pwm_Ip_GetDuty(Etpu_Pwm_Ip_InstanceType *pPwmInstance)
{
    Etpu_Ip_Uint24Type u24ChannelPeriod;
    Etpu_Ip_Uint24Type u24ActiveTime;

    u24ChannelPeriod = Etpu_Ip_ReadU24Param(pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_PERIOD);
    u24ActiveTime = Etpu_Ip_ReadU24Param(pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_ACTIVE);

    return (uint16)(((uint64)u24ActiveTime * ETPU_PWM_IP_MAX_DUTY) / u24ChannelPeriod);
}

/*================================================================================================*/
Etpu_Pwm_Ip_LastInterruptType Etpu_Pwm_Ip_GetLastInterrupt(Etpu_Pwm_Ip_InstanceType *pPwmInstance)
{
    return (Etpu_Pwm_Ip_LastInterruptType)(Etpu_Ip_ReadU8Param((uint8*)pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_LAST_IRQ));
}

/*================================================================================================*/
void Etpu_Pwm_Ip_Stop(Etpu_Pwm_Ip_InstanceType *pPwmInstance)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_37();

    pPwmInstance->u8StartMode &= ~(uint8)ETPU_PWM_IP_ENABLE_FLAG;

    /* write parameter to data memory */
    Etpu_Ip_WriteU8Param((uint8*)pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_START_MODE, pPwmInstance->u8StartMode);

    /* write hsr to stop channel running */
    pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].HSRR.B.HSR = ETPU_PWM_IP_HSR_INIT;

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_37();
}

/*================================================================================================*/
void Etpu_Pwm_Ip_StopAndSetPin(Etpu_Pwm_Ip_InstanceType *pPwmInstance,
                               Etpu_Ip_PinStateType ePinState)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_38();

    pPwmInstance->u8StartMode &= ~(uint8)ETPU_PWM_IP_ENABLE_FLAG;

    /* write parameter to data memory */
    Etpu_Ip_WriteU8Param((uint8*)pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_START_MODE, pPwmInstance->u8StartMode);

    /* write FM (function mode) bits */
    Etpu_Pwm_Ip_PolarityType ePolarity = (ETPU_PIN_LOW == ePinState) ? ETPU_PWM_POLARITY_ACTIVE_HIGH :
                                                                       ETPU_PWM_POLARITY_ACTIVE_LOW;
    pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].SCR.B.FM = (uint32)pPwmInstance->eTimebase + (uint8)ePolarity;

    /* write hsr to stop channel running */
    pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].HSRR.B.HSR = ETPU_PWM_IP_HSR_INIT;

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_38();
}

/*================================================================================================*/
void Etpu_Pwm_Ip_Start(Etpu_Pwm_Ip_InstanceType *pPwmInstance)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_39();

    pPwmInstance->u8StartMode |= ETPU_PWM_IP_ENABLE_FLAG;

    /* write parameter to data memory */
    Etpu_Ip_WriteU8Param((uint8*)pPwmInstance->pCpba, ETPU_PWM_IP_OFFSET_START_MODE, pPwmInstance->u8StartMode);

    /* write FM (function mode) bits */
    pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].SCR.B.FM = (uint32)pPwmInstance->eTimebase + (uint8)pPwmInstance->ePolarity;

    /* write hsr to start channel running */
    pEtpu_Ip_Regs->CHAN[pPwmInstance->u8Channel].HSRR.B.HSR = ETPU_PWM_IP_HSR_INIT;

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_39();
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* ETPU_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
