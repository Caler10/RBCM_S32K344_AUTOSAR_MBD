/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
#ifndef FLEXIO_I2C_IP_HWACCESS_H
#define FLEXIO_I2C_IP_HWACCESS_H

/**
*     @file
*
*     @addtogroup FLEXIO_I2C_DRIVER Flexio_I2c Driver
*     @{
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

#include "Flexio_I2c_Ip_CfgDefines.h"

#include "Flexio_I2c_Ip_Cfg.h"
#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
    #include "Flexio_Mcl_Ip_HwAccess.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_I2C_IP_HWACCESS_VENDOR_ID                      43
#define FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_I2C_IP_HWACCESS_SW_MAJOR_VERSION               5
#define FLEXIO_I2C_IP_HWACCESS_SW_MINOR_VERSION               0
#define FLEXIO_I2C_IP_HWACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_I2c_Ip_Cfg.h header file are of the same vendor. */
#if (FLEXIO_I2C_IP_HWACCESS_VENDOR_ID != FLEXIO_I2C_IP_CFG_VENDOR_ID)
    #error "Flexio_I2c_Ip_HwAccess.h and Flexio_I2c_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Flexio_I2c_Ip_Cfg.h header file are of the same Autosar version */
#if (( FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip_HwAccess.h and Flexio_I2c_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexio_I2c_Ip_Cfg.h header file are of the same Software version */
#if (( FLEXIO_I2C_IP_HWACCESS_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_SW_MINOR_VERSION != FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_SW_PATCH_VERSION != FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_HwAccess.h and Flexio_I2c_Ip_Cfg.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_CfgDefines.h header file are of the same vendor. */
#if (FLEXIO_I2C_IP_HWACCESS_VENDOR_ID != FLEXIO_I2C_IP_CFGDEFINES_VENDOR_ID)
    #error "Flexio_I2c_Ip_HwAccess.h and Flexio_I2c_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Flexio_I2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if (( FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip_HwAccess.h and Flexio_I2c_Ip_CfgDefines.h are different"
#endif
/* Check if current file and Flexio_I2c_Ip_CfgDefines.h header file are of the same Software version */
#if (( FLEXIO_I2C_IP_HWACCESS_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_SW_MINOR_VERSION != FLEXIO_I2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_HWACCESS_SW_PATCH_VERSION != FLEXIO_I2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_HwAccess.h and Flexio_I2c_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (FLEXIO_I2C_IP_ENABLE == STD_ON)
        /* Check if current file and Flexio_Mcl_Ip_HwAccess.h header file are of the same Autosar version */
        #if ( (FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
              (FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Flexio_I2c_Ip_HwAccess.h and Flexio_Mcl_Ip_HwAccess.h are different"
        #endif
    #endif
#endif

 /*******************************************************************************
 * Definitions
 ******************************************************************************/

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*!
 * @name FLEXIO_I2C Driver
 * @{
 */
 
#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
    

/**
 * FlexIO shifter control register
 * This is a structure used by all FlexIO drivers as shifter control value.
 * It is needed for parameter of set shifter register value.
 */
typedef struct
{
    Flexio_Mcl_Ip_ShifterModeType Mode;          /**< FlexIO device instance number */
    uint8 Pin;      /**< Count of internal resources used (shifters and timers) */
    Flexio_Mcl_Ip_PinPolarityType PinPolarity;      /**< Index of first used internal resource instance (shifter and timer) */
    Flexio_Mcl_Ip_PinConfigType PinConfig;
    uint8 Timer;
    Flexio_Mcl_Ip_TimerPolarityType TimerPolarity;
} Flexio_I2c_Ip_ShifterControl;

/**
 * FlexIO timer config register
 * This is a structure used by all FlexIO drivers as timer config value.
 * It is needed for parameter of set timer config register value.
 */
typedef struct
{
    Flexio_Mcl_Ip_TimerStartType Start;
    Flexio_Mcl_Ip_TimerStopType Stop;
    Flexio_Mcl_Ip_TimerEnableType Enable;
    Flexio_Mcl_Ip_TimerDisableType Disable;
    Flexio_Mcl_Ip_TimerResetType Reset;
    uint32 Decrement;
    Flexio_Mcl_Ip_TimerOutputType Output;
} Flexio_I2c_Ip_TimerConfig;

/**
 * FlexIO timer control register
 * This is a structure used by all FlexIO drivers as timer control value.
 * It is needed for parameter of set timer control register value.
 */
typedef struct
{
    uint8 Trigger;
    Flexio_Mcl_Ip_TriggerPolarityType TriggerPolarity;
    Flexio_Mcl_Ip_TriggerSourceType TriggerSource;
    uint8 Pin;
    Flexio_Mcl_Ip_PinPolarityType PinPolarity;
    Flexio_Mcl_Ip_PinConfigType PinConfig;
    Flexio_Mcl_Ip_TimerModeType Mode;
} Flexio_I2c_Ip_TimerControl;

/*
 * This function returns the data read from all the FLEXIO pins. Only the lower
 * n bits are valid, where n is the number of pins returned by FLEXIO_GetPinNum().
 */
static inline uint32 Flexio_I2c_Ip_GetPinData(const FLEXIO_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->PIN;

    Tmp = (Tmp & FLEXIO_PIN_PDI_MASK) >> FLEXIO_PIN_PDI_SHIFT;
    return Tmp;
}

/*
 * This function assigns a timer to control the specified shifter, and also configures its Polarity.
 */
static inline void Flexio_I2c_Ip_SetShifterTimer(FLEXIO_Type *BaseAddr,
                                                 uint8 Shifter,
                                                 uint8 Timer,
                                                 Flexio_Mcl_Ip_TimerPolarityType Polarity)
{
    uint32 Tmp = BaseAddr->SHIFTCTL[Shifter];

    Tmp &= ~(FLEXIO_SHIFTCTL_TIMSEL_MASK);
    Tmp |= FLEXIO_SHIFTCTL_TIMSEL(Timer);
    Tmp &= ~(FLEXIO_SHIFTCTL_TIMPOL_MASK);
    Tmp |= FLEXIO_SHIFTCTL_TIMPOL(Polarity);
    BaseAddr->SHIFTCTL[Shifter] = Tmp;
}


/**
 * This function assigns the specified pin to the specified shifter, and also sets
 * its polarity and configuration.
 */
static inline void Flexio_I2c_Ip_SetShifterPin(FLEXIO_Type *BaseAddr,
                                               uint8 Shifter,
                                               uint8 Pin,
                                               Flexio_Mcl_Ip_PinPolarityType Polarity,
                                               Flexio_Mcl_Ip_PinConfigType Config)
{
    uint32 Tmp = BaseAddr->SHIFTCTL[Shifter];

    Tmp &= ~(FLEXIO_SHIFTCTL_PINSEL_MASK);
    Tmp |= FLEXIO_SHIFTCTL_PINSEL(Pin);
    Tmp &= ~(FLEXIO_SHIFTCTL_PINPOL_MASK);
    Tmp |= FLEXIO_SHIFTCTL_PINPOL(Polarity);
    Tmp &= ~(FLEXIO_SHIFTCTL_PINCFG_MASK);
    Tmp |= FLEXIO_SHIFTCTL_PINCFG(Config);
    BaseAddr->SHIFTCTL[Shifter] = Tmp;
}

/**
 * This function configures the pin assigned to the specified specified shifter.
 * It does not change the other pin-related settings.
 */
static inline void Flexio_I2c_Ip_SetShifterPinConfig(FLEXIO_Type *BaseAddr,
                                                     uint8 Shifter,
                                                     Flexio_Mcl_Ip_PinConfigType Config)
{
    uint32 Tmp = BaseAddr->SHIFTCTL[Shifter];

    Tmp &= ~(FLEXIO_SHIFTCTL_PINCFG_MASK);
    Tmp |= FLEXIO_SHIFTCTL_PINCFG(Config);
    BaseAddr->SHIFTCTL[Shifter] = Tmp;
}


/**
 * This function configures the mode for the specified shifter.
 */
static inline void Flexio_I2c_Ip_SetShifterMode(FLEXIO_Type *BaseAddr,
                                                uint8 Shifter,
                                                Flexio_Mcl_Ip_ShifterModeType Mode)
{
    uint32 Tmp = BaseAddr->SHIFTCTL[Shifter];

    Tmp &= ~(FLEXIO_SHIFTCTL_SMOD_MASK);
    Tmp |= FLEXIO_SHIFTCTL_SMOD(Mode);
    BaseAddr->SHIFTCTL[Shifter] = Tmp;
}


/**
 * This function configures the control settings for the specified shifter: mode settings,
 * Pin settings and timer settings.
 */
static inline void Flexio_I2c_Ip_SetShifterControl(FLEXIO_Type *BaseAddr,
                                                   uint8 Shifter,
                                                   const Flexio_I2c_Ip_ShifterControl *ShifterControl)
{
    BaseAddr->SHIFTCTL[Shifter] = FLEXIO_SHIFTCTL_SMOD(ShifterControl->Mode)
                                | FLEXIO_SHIFTCTL_PINPOL(ShifterControl->PinPolarity)
                                | FLEXIO_SHIFTCTL_PINSEL(ShifterControl->Pin)
                                | FLEXIO_SHIFTCTL_PINCFG(ShifterControl->PinConfig)
                                | FLEXIO_SHIFTCTL_TIMPOL(ShifterControl->TimerPolarity)
                                | FLEXIO_SHIFTCTL_TIMSEL(ShifterControl->Timer);
}


/**
 * This function configures the input source of the specified shifter.
 */
static inline void Flexio_I2c_Ip_SetShifterInputSource(FLEXIO_Type *BaseAddr,
                                                       uint8 Shifter,
                                                       Flexio_Mcl_Ip_ShifterSourceType Source)
{
    uint32 Tmp;

    Tmp = BaseAddr->SHIFTCFG[Shifter];
    Tmp &= ~(FLEXIO_SHIFTCFG_INSRC_MASK);
    Tmp |= FLEXIO_SHIFTCFG_INSRC(Source);
    BaseAddr->SHIFTCFG[Shifter] = Tmp;
}


/**
 * This function configures the sending or receiving of
 * a stop bit in Transmit, Receive or Match Store modes.
 */
static inline void Flexio_I2c_Ip_SetShifterStopBit(FLEXIO_Type *BaseAddr, uint8 Shifter,
                                                   Flexio_Mcl_Ip_ShifterStopType Stop)
{
    uint32 Tmp;

    Tmp = BaseAddr->SHIFTCFG[Shifter];
    Tmp &= ~(FLEXIO_SHIFTCFG_SSTOP_MASK);
    Tmp |= FLEXIO_SHIFTCFG_SSTOP(Stop);
    BaseAddr->SHIFTCFG[Shifter] = Tmp;
}


/**
 * This function configures the sending or receiving of
 * a start bit in Transmit, Receive or Match Store modes.
 */
static inline void Flexio_I2c_Ip_SetShifterStartBit(FLEXIO_Type *BaseAddr,
                                                    uint8 Shifter,
                                                    Flexio_Mcl_Ip_ShifterStartType Start)
{
    uint32 Tmp;

    Tmp = BaseAddr->SHIFTCFG[Shifter];
    Tmp &= ~(FLEXIO_SHIFTCFG_SSTART_MASK);
    Tmp |= FLEXIO_SHIFTCFG_SSTART(Start);
    BaseAddr->SHIFTCFG[Shifter] = Tmp;
}


/**
 * This function sets the following configurations for the specified shifter:
 * start bit, stop bit, input source
 */
static inline void Flexio_I2c_Ip_SetShifterConfig(FLEXIO_Type *BaseAddr,
                                                  uint8 Shifter,
                                                  Flexio_Mcl_Ip_ShifterStartType Start,
                                                  Flexio_Mcl_Ip_ShifterStopType Stop,
                                                  Flexio_Mcl_Ip_ShifterSourceType Source)
{
    BaseAddr->SHIFTCFG[Shifter] = FLEXIO_SHIFTCFG_SSTART(Start)
                                | FLEXIO_SHIFTCFG_SSTOP(Stop)
                                | FLEXIO_SHIFTCFG_INSRC(Source);
}


/**
 * This function reads data from the specified shifter buffer. The data can be
 * read in any of the four ways allowed by the hardware - see description of type
 * Flexio_Mcl_Ip_ShifterBufferModeType for details.
 */
static inline uint32 Flexio_I2c_Ip_ReadShifterBuffer(const FLEXIO_Type *BaseAddr,
                                                     uint8 Shifter,
                                                     Flexio_Mcl_Ip_ShifterBufferModeType Mode)
{
    uint32 Data;

    switch (Mode)
    {
        case FLEXIO_SHIFTER_RW_MODE_NORMAL:
            Data = BaseAddr->SHIFTBUF[Shifter];
            break;
        case FLEXIO_SHIFTER_RW_MODE_BIT_SWAP:
            Data = BaseAddr->SHIFTBUFBIS[Shifter];
            break;
        default:
            /* bad read Mode */
            Data = 0U;
            break;
    }
    return Data;
}


/**
 * This function writes data in the specified shifter buffer. The data can be
 * written in any of the four ways allowed by the hardware - see description of type
 * Flexio_Mcl_Ip_ShifterBufferModeType for details.
 */
static inline void Flexio_I2c_Ip_WriteShifterBuffer(FLEXIO_Type *BaseAddr,
                                                    uint8 Shifter,
                                                    uint32 Value,
                                                    Flexio_Mcl_Ip_ShifterBufferModeType Mode)
{
    switch (Mode)
    {
        case FLEXIO_SHIFTER_RW_MODE_NORMAL:
            BaseAddr->SHIFTBUF[Shifter] = Value;
            break;
        case FLEXIO_SHIFTER_RW_MODE_BIT_SWAP:
            BaseAddr->SHIFTBUFBIS[Shifter] = Value;
            break;
        default:
            /* bad write Mode */
            break;
    }
}


/**
 * This function configures the trigger for the specified timer, and also its
 * source (internal or external) and polarity settings.
 * For internal triggers, the selection is as follows:
 *  - 4*N - Pin 2*N input
 *  - 4*N+1 - Shifter N status flag
 *  - 4*N+2 - Pin 2*N+1 input
 *  - 4*N+3 - Timer N trigger output
 */
static inline void Flexio_I2c_Ip_SetTimerTrigger(FLEXIO_Type *BaseAddr,
                                                 uint8 Timer,
                                                 uint8 Trigger,
                                                 Flexio_Mcl_Ip_TriggerPolarityType Polarity,
                                                 Flexio_Mcl_Ip_TriggerSourceType Source)
{
    uint32 Tmp = BaseAddr->TIMCTL[Timer];

    Tmp &= ~(FLEXIO_TIMCTL_TRGSEL_MASK);
    Tmp |= FLEXIO_TIMCTL_TRGSEL(Trigger);
    Tmp &= ~(FLEXIO_TIMCTL_TRGPOL_MASK);
    Tmp |= FLEXIO_TIMCTL_TRGPOL(Polarity);
    Tmp &= ~(FLEXIO_TIMCTL_TRGSRC_MASK);
    Tmp |= FLEXIO_TIMCTL_TRGSRC(Source);
    BaseAddr->TIMCTL[Timer] = Tmp;
}


/**
 * This function assigns the specified pin to the specified timer, and also sets
 * its polarity and configuration.
 */
static inline void Flexio_I2c_Ip_SetTimerPin(FLEXIO_Type *BaseAddr,
                                             uint8 Timer,
                                             uint8 Pin,
                                             Flexio_Mcl_Ip_PinPolarityType Polarity,
                                             Flexio_Mcl_Ip_PinConfigType Config)
{
    uint32 Tmp = BaseAddr->TIMCTL[Timer];

    Tmp &= ~(FLEXIO_TIMCTL_PINSEL_MASK);
    Tmp |= FLEXIO_TIMCTL_PINSEL(Pin);
    Tmp &= ~(FLEXIO_TIMCTL_PINPOL_MASK);
    Tmp |= FLEXIO_TIMCTL_PINPOL(Polarity);
    Tmp &= ~(FLEXIO_TIMCTL_PINCFG_MASK);
    Tmp |= FLEXIO_TIMCTL_PINCFG(Config);
    BaseAddr->TIMCTL[Timer] = Tmp;
}


/**
 * This function configures the mode for the specified timer.
 * In 8-bit counter mode, the lower 8-bits of the counter and compare register are used to
 * configure the baud rate of the timer shift clock and the upper 8-bits are used to configure
 * the shifter bit count.
 * In 8-bit PWM mode, the lower 8-bits of the counter and compare
 * register are used to configure the high period of the timer shift clock and the upper
 * 8-bits are used to configure the low period of the timer shift clock. The shifter bit count
 * is configured using another timer or external signal.
 * In 16-bit counter mode, the full 16-bits of the counter and compare register are used to
 * configure either the baud rate of the shift clock or the shifter bit count.
 */
static inline void Flexio_I2c_Ip_SetTimerMode(FLEXIO_Type *BaseAddr,
                                              uint8 Timer,
                                              Flexio_Mcl_Ip_TimerModeType Mode)
{
    uint32 Tmp = BaseAddr->TIMCTL[Timer];

    Tmp &= ~(FLEXIO_TIMCTL_TIMOD_MASK);
    Tmp |= FLEXIO_TIMCTL_TIMOD(Mode);
    BaseAddr->TIMCTL[Timer] = Tmp;
}


/**
 * This function configures the control settings for the specified timer: mode settings,
 * pin settings and trigger settings.
 */
static inline void Flexio_I2c_Ip_SetTimerControl(FLEXIO_Type *BaseAddr,
                                                 uint8 Timer,
                                                 const Flexio_I2c_Ip_TimerControl *TimerControl)
{
    BaseAddr->TIMCTL[Timer] = FLEXIO_TIMCTL_TIMOD(TimerControl->Mode)
                            | FLEXIO_TIMCTL_PINSEL(TimerControl->Pin)
                            | FLEXIO_TIMCTL_PINPOL(TimerControl->PinPolarity)
                            | FLEXIO_TIMCTL_PINCFG(TimerControl->PinConfig)
                            | FLEXIO_TIMCTL_TRGSRC(TimerControl->TriggerSource)
                            | FLEXIO_TIMCTL_TRGPOL(TimerControl->TriggerPolarity)
                            | FLEXIO_TIMCTL_TRGSEL(TimerControl->Trigger);
}


/**
 * This function configures the initial output of the specified timer and whether it is
 * affected by the Timer reset.
 */
static inline void Flexio_I2c_Ip_SetTimerInitialOutput(FLEXIO_Type *BaseAddr,
                                                       uint8 Timer,
                                                       Flexio_Mcl_Ip_TimerOutputType Output)
{
    uint32 Tmp = BaseAddr->TIMCFG[Timer];

    Tmp &= ~(FLEXIO_TIMCFG_TIMOUT_MASK);
    Tmp |= FLEXIO_TIMCFG_TIMOUT(Output);
    BaseAddr->TIMCFG[Timer] = Tmp;
}


/**
 * This function configures the decrement condition for the specified timer and the source
 * of the shift clock.
 * See description of type Flexio_Mcl_Ip_TimerDecrementType for a list of options.
 */
static inline void Flexio_I2c_Ip_SetTimerDecrement(FLEXIO_Type *BaseAddr,
                                                   uint8 Timer,
                                                   Flexio_Mcl_Ip_TimerDecrementType Decrement)
{
    uint32 Tmp = BaseAddr->TIMCFG[Timer];

    Tmp &= ~(FLEXIO_TIMCFG_TIMDEC_MASK);
    Tmp |= FLEXIO_TIMCFG_TIMDEC(Decrement);
    BaseAddr->TIMCFG[Timer] = Tmp;
}


/**
 * This function configures the conditions that cause the timer counter (and optionally
 * output) to be reset. In 8-bit counter mode, the timer reset will only reset the
 * lower 8-bits that configure the baud rate. In all other modes, the timer reset
 * will reset the full 16-bits of the counter.
 * See description of type Flexio_Mcl_Ip_TimerDecrementType for a list of options.
 */
static inline void Flexio_I2c_Ip_SetTimerReset(FLEXIO_Type *BaseAddr,
                                               uint8 Timer,
                                               Flexio_Mcl_Ip_TimerResetType Reset)
{
    uint32 Tmp = BaseAddr->TIMCFG[Timer];

    Tmp &= ~(FLEXIO_TIMCFG_TIMRST_MASK);
    Tmp |= FLEXIO_TIMCFG_TIMRST(Reset);
    BaseAddr->TIMCFG[Timer] = Tmp;
}


/**
 * This function configures the condition that cause the specified timer to be disabled.
 * See description of type Flexio_Mcl_Ip_TimerDisableType for a list of options.
 */
static inline void Flexio_I2c_Ip_SetTimerDisable(FLEXIO_Type *BaseAddr,
                                                 uint8 Timer,
                                                 Flexio_Mcl_Ip_TimerDisableType Disable)
{
    uint32 Tmp = BaseAddr->TIMCFG[Timer];

    Tmp &= ~(FLEXIO_TIMCFG_TIMDIS_MASK);
    Tmp |= FLEXIO_TIMCFG_TIMDIS(Disable);
    BaseAddr->TIMCFG[Timer] = Tmp;
}


/**
 * This function configures the condition that cause the specified timer to be enabled
 * and start decrementing.
 * See description of type Flexio_Mcl_Ip_TimerDisableType for a list of options.
 */
static inline void Flexio_I2c_Ip_SetTimerEnable(FLEXIO_Type *BaseAddr,
                                                uint8 Timer,
                                                Flexio_Mcl_Ip_TimerEnableType Enable)
{
    uint32 Tmp = BaseAddr->TIMCFG[Timer];

    Tmp &= ~(FLEXIO_TIMCFG_TIMENA_MASK);
    Tmp |= FLEXIO_TIMCFG_TIMENA(Enable);
    BaseAddr->TIMCFG[Timer] = Tmp;
}


/**
 * This function configures stop bit insertion for the specified timer.
 * The stop bit can be added on a timer compare (between each word) or on a timer disable.
 * When stop bit is enabled, configured shifters will output the contents of the stop bit
 * when the timer is disabled. When stop bit is enabled on timer disable, the timer remains
 * disabled until the next rising edge of the shift clock. If configured for both timer
 * compare and timer disable, only one stop bit is inserted on timer disable.
 */
static inline void Flexio_I2c_Ip_SetTimerStop(FLEXIO_Type *BaseAddr,
                                              uint8 Timer,
                                              Flexio_Mcl_Ip_TimerStopType Stop)
{
    uint32 Tmp = BaseAddr->TIMCFG[Timer];

    Tmp &= ~(FLEXIO_TIMCFG_TSTOP_MASK);
    Tmp |= FLEXIO_TIMCFG_TSTOP(Stop);
    BaseAddr->TIMCFG[Timer] = Tmp;
}


/**
 * This function sets the following configurations for the specified timer:
 * start bit, stop bit, enable condition, disable condition, reset condition,
 * decrement condition, initial output
 */
static inline void Flexio_I2c_Ip_SetTimerConfig(FLEXIO_Type *BaseAddr,
                                                uint8 Timer,
                                                const Flexio_I2c_Ip_TimerConfig *TimerConfig)
{

    BaseAddr->TIMCFG[Timer] = FLEXIO_TIMCFG_TSTART(TimerConfig->Start)
                            | FLEXIO_TIMCFG_TSTOP(TimerConfig->Stop)
                            | FLEXIO_TIMCFG_TIMENA(TimerConfig->Enable)
                            | FLEXIO_TIMCFG_TIMDIS(TimerConfig->Disable)
                            | FLEXIO_TIMCFG_TIMRST(TimerConfig->Reset)
                            | FLEXIO_TIMCFG_TIMDEC(TimerConfig->Decrement)
                            | FLEXIO_TIMCFG_TIMOUT(TimerConfig->Output);
}


/**
 * This function returns the compare value currently set for the specified timer.
 */
static inline uint16 Flexio_I2c_Ip_GetTimerCompare(const FLEXIO_Type *BaseAddr,
                                                   uint8 Timer)
{
    return (uint16)(BaseAddr->TIMCMP[Timer]);
}


/**
 * This function configures the compare value for the specified timer.
 * The timer compare value is loaded into the timer counter when the timer is first enabled,
 * when the timer is reset and when the timer decrements down to zero.
 * In dual 8-bit counters baud/bit mode, the lower 8-bits configure the baud rate divider
 * and the upper 8-bits configure the number of bits in each word.
 * In dual 8-bit counters PWM mode, the lower 8-bits configure the high period of the output
 * and the upper 8-bits configure the low period.
 * In 16-bit counter mode, the compare value can be used to generate the baud rate divider
 * (if shift clock source is timer output) or the number of bits in each word (when the shift
 * clock source is a pin or trigger input).
 */
static inline void Flexio_I2c_Ip_SetTimerCompare(FLEXIO_Type *BaseAddr,
                                                 uint8 Timer,
                                                 uint16 Value)
{
    BaseAddr->TIMCMP[Timer] = (uint32)Value;
}

#endif /* FLEXIO_I2C_IP_ENABLE == STD_OFF */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* FLEXIO_I2C_IP_HWACCESS_H */

