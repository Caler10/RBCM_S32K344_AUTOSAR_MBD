/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : Emios Flexio FlexPwm eTpu
* Dependencies         : none
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 5.0.0
* Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
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

#ifndef FLEXPWM_IP_TYPES_H
#define FLEXPWM_IP_TYPES_H

/**
*   @file       FlexPwm_Ip_Types.h
*
*   @addtogroup flexpwm_ip FlexPwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "FlexPwm_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_TYPES_VENDOR_ID                             43
#define FLEXPWM_IP_TYPES_MODULE_ID                             121
#define FLEXPWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION              4
#define FLEXPWM_IP_TYPES_AR_RELEASE_MINOR_VERSION              7
#define FLEXPWM_IP_TYPES_AR_RELEASE_REVISION_VERSION           0
#define FLEXPWM_IP_TYPES_SW_MAJOR_VERSION                      5
#define FLEXPWM_IP_TYPES_SW_MINOR_VERSION                      0
#define FLEXPWM_IP_TYPES_SW_PATCH_VERSION                      0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXPWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of FlexPwm_Ip_Types.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same vendor */
#if (FLEXPWM_IP_TYPES_VENDOR_ID != FLEXPWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Types.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Types.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same software version */
#if ((FLEXPWM_IP_TYPES_SW_MAJOR_VERSION != FLEXPWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_TYPES_SW_MINOR_VERSION != FLEXPWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_TYPES_SW_PATCH_VERSION != FLEXPWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Types.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*!
 * @brief FlexPWM state Type options.
 * Implements : FlexPwm_Ip_StateTypes
 */
typedef enum
{
    FLEXPWM_IP_UNINIT_STATE  = 0U,   /*!< uninit state */
    FLEXPWM_IP_INIT_STATE    = 1U,   /*!< init state */
    FLEXPWM_IP_IDLE_STATE    = 2U    /*!< idle state */
} FlexPwm_Ip_StateTypes;

/*!
 * @brief FlexPWM channel Type options.
 * Implements : FlexPwm_Ip_ChannelTypes
 */
typedef enum
{
    FLEXPWM_IP_PWMX   = 0U,   /*!< channel X   */
    FLEXPWM_IP_PWMA   = 1U,   /*!< channel A   */
    FLEXPWM_IP_PWMB   = 2U   /*!< channel B   */
} FlexPwm_Ip_ChannelTypes;

/*!
 * @brief FlexPWM polarity Type options.
 * Implements : FlexPwm_Ip_PolarityTypes
 */
typedef enum
{
    FLEXPWM_IP_POL_HIGH   = 0U,   /*!< output not inverted   */
    FLEXPWM_IP_POL_LOW    = 1U    /*!< output inverted   */
} FlexPwm_Ip_PolarityTypes;

/*!
 * @brief FlexPWM output state Type options.
 * Implements : FlexPwm_Ip_OutputStateTypes
 */
typedef enum
{
    FLEXPWM_IP_OUT_LOW   = 0U,   /*!< output low   */
    FLEXPWM_IP_OUT_HIGH  = 1U    /*!< output high   */
} FlexPwm_Ip_OutputStateTypes;

/*!
 * @brief FlexPWM Interrupts Type options.
 * Implements : FlexPwm_Ip_InterruptTypes
 */
typedef enum
{
    FLEXPWM_IP_DISABLE_INT  = 0U,   /*!< Disable all Interrupt */
    FLEXPWM_IP_RELOAD_INT   = 1U,   /*!< Reload Interrupt */
    FLEXPWM_IP_COMPARE_INT  = 2U    /*!< Compare Interrupt */
} FlexPwm_Ip_InterruptTypes;

/*!
 * @brief FlexPWM Output Trigger control
 * Implements : FlexPwm_Ip_OuputTriggerTypes
 */
typedef enum
{
    FLEXPWM_IP_NO_TRIGGER     = 0U,    /*!< No trigger */
    FLEXPWM_IP_FIRST_EDGE_X   = 1U,   /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL0 registers*/
    FLEXPWM_IP_SECOND_EDGE_X  = 2U,   /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL1 registers*/
    FLEXPWM_IP_BOTH_EDGES_X   = 3U,   /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL0 and VAL1 registers*/
    FLEXPWM_IP_FIRST_EDGE_A   = 4U,   /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL2 registers*/
    FLEXPWM_IP_SECOND_EDGE_A  = 8U,   /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL3 registers*/
    FLEXPWM_IP_BOTH_EDGES_A   = 12U,  /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL2 and VAL3 registers*/
    FLEXPWM_IP_FIRST_EDGE_B   = 16U,  /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL4 registers*/
    FLEXPWM_IP_SECOND_EDGE_B  = 32U,  /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL5 registers*/
    FLEXPWM_IP_BOTH_EDGES_B   = 48U  /*!< Enable the generation of OUT_TRIG outputs based on the counter value matching VAL4 and VAL5 registers*/
} FlexPwm_Ip_OuputTriggerTypes;

/*!
 * @brief PWM output state during fault conditions
 * Implements : FlexPwm_Ip_FaultStateChTypes
 */
typedef enum
{
    FLEXPWM_IP_OUTPUT_STATE_LOGIC_0    = 0U,    /*!< Output is forced to logic 0 state prior to consideration of output polarity control */
    FLEXPWM_IP_OUTPUT_STATE_LOGIC_1    = 1U,    /*!< Output is forced to logic 1 state prior to consideration of output polarity control */
    FLEXPWM_IP_OUTPUT_STATE_TRISTATED  = 2U     /*!< Output is tri-stated */
} FlexPwm_Ip_FaultStateChTypes;

/*!
 * @brief FlexPWM Signal Type options.
 * Implements : FlexPwm_Ip_SignalPwmTypes
 */
typedef enum
{
    FLEXPWM_IP_CENTER_ALIGNED    = 0U,   /*!< Center-aligned PWM     */
    FLEXPWM_IP_EDGE_ALIGNED      = 1U,   /*!< Edge aligned PWM       */
    FLEXPWM_IP_PHASE_SHIFTED     = 2U,   /*!< Phase shifted PWM      */
    FLEXPWM_IP_DOUBLE_SWITCHING  = 3U    /*!< Double switching PWM   */
} FlexPwm_Ip_SignalPwmTypes;

/*!
 * @brief PWM clock source selection.
 * Implements : FlexPwm_Ip_ClockSourceTypes
 */
typedef enum
{
    FLEXPWM_IP_CLKSOURCE_PERIPHERAL_CLK = 0U,     /*!< The peripheral clock is used as the clock. */
    FLEXPWM_IP_CLKSOURCE_EXT_CLK        = 1U,     /*!< EXT_CLK is used as the clock. */
    FLEXPWM_IP_CLKSOURCE_AUX_CLK        = 2U      /*!< Clock of the submodule 0 (AUX_CLK) is used as the source clock. */
} FlexPwm_Ip_ClockSourceTypes;

/*!
 * @brief PWM pre scaler factor selection for clock source.
 * Implements : FlexPwm_Ip_PrescalerTypes
 */
typedef enum
{
    FLEXPWM_IP_DIV1   = 0U,       /*!< PWM clock frequency = fclk/1. */
    FLEXPWM_IP_DIV2   = 1U,       /*!< PWM clock frequency = fclk/2. */
    FLEXPWM_IP_DIV4   = 2U,       /*!< PWM clock frequency = fclk/4. */
    FLEXPWM_IP_DIV8   = 3U,       /*!< PWM clock frequency = fclk/8. */
    FLEXPWM_IP_DIV16  = 4U,       /*!< PWM clock frequency = fclk/16. */
    FLEXPWM_IP_DIV32  = 5U,       /*!< PWM clock frequency = fclk/32. */
    FLEXPWM_IP_DIV64  = 6U,       /*!< PWM clock frequency = fclk/64. */
    FLEXPWM_IP_DIV128 = 7U        /*!< PWM clock frequency = fclk/128. */
} FlexPwm_Ip_PrescalerTypes;

/**
* @brief        Prescaler mode type
* @details      This enumeration specifies the possible types of prescalers used to configure base-clock timers
*
*/
typedef enum
{
    /** @brief  Selected value is the default/primary prescaler */
    FLEXPWM_IP_PRIMARY_PRESCALER       = 0x00U,
    /** @brief  Selected value is the alternative configured prescaler */
    FLEXPWM_IP_ALTERNATIVE_PRESCALER   = 0x01U
} FlexPwm_Ip_PrescalerModeTypes;
/*!
 * @brief Options available to select reload signal for loading the buffered-registers with new values.
 * Implements : FlexPwm_Ip_ReloadSourceSelTypes
 */
typedef enum
{
    FLEXPWM_IP_LOCAL_RELOAD  = 0U,   /*!< The local RELOAD signal is used to reload registers. */
    FLEXPWM_IP_MASTER_RELOAD = 1U    /*!< The master RELOAD signal (from submodule 0) is used to reload registers */
} FlexPwm_Ip_ReloadSourceSelTypes;

/*!
 * @brief Options available on how to load the buffered-registers with new values.
 * Implements : FlexPwm_Ip_ReloadTypes
 */
typedef enum
{
    FLEXPWM_IP_RELOAD_IMMEDIATE  = 0U,   /*!< Buffered-registers get loaded with new values as soon as LDOK bit is set. */
    FLEXPWM_IP_RELOAD_FULL       = 1U,   /*!< Registers loaded on a PWM full cycle. */
    FLEXPWM_IP_RELOAD_HALF       = 2U,   /*!< Registers loaded on a PWM half cycle. */
    FLEXPWM_IP_RELOAD_FULL_HALF  = 3U    /*!< Registers loaded on a PWM half & full cycle. */
} FlexPwm_Ip_ReloadTypes;

/*!
 * @brief PWM load frequency selection.
 * Implements :FlexPwm_Ip_LoadFrequencyTypes
 */
typedef enum
{
    FLEXPWM_IP_LDFQ_EACH1  = 0U,      /*!< Every 1 PWM opportunity. */
    FLEXPWM_IP_LDFQ_EACH2  = 1U,      /*!< Every 2 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH3  = 2U,      /*!< Every 3 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH4  = 3U,      /*!< Every 4 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH5  = 4U,      /*!< Every 5 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH6  = 5U,      /*!< Every 6 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH7  = 6U,      /*!< Every 7 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH8  = 7U,      /*!< Every 8 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH9  = 8U,      /*!< Every 9 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH10 = 9U,      /*!< Every 10 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH11 = 10U,     /*!< Every 11 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH12 = 11U,     /*!< Every 12 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH13 = 12U,     /*!< Every 13 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH14 = 13U,     /*!< Every 14 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH15 = 14U,     /*!< Every 15 PWM opportunities. */
    FLEXPWM_IP_LDFQ_EACH16 = 15U      /*!< Every 16 PWM opportunities. */
} FlexPwm_Ip_LoadFrequencyTypes;

/*!
 * @brief Options that can trigger a PWM FORCE_OUT.
 * Implements :FlexPwm_Ip_ForceSourceSelTypes
 */
typedef enum
{
    FLEXPWM_IP_LOCAL_FORCE         = 0U,  /*!< The local force signal, CTRL2[FORCE], from this sub-module is used to force updates. */
    FLEXPWM_IP_MASTER_FORCE        = 1U,  /*!< The master force signal from sub-module 0 is used to force updates. */
    FLEXPWM_IP_LOCAL_RELOAD_FORCE  = 2U,  /*!< The local reload signal from this sub-module is used to force updates without regard to the state of LDOK. */
    FLEXPWM_IP_MASTER_RELOAD_FORCE = 3U,  /*!< The master reload signal from sub-module 0 is used to force updates if LDOK is set. */
    FLEXPWM_IP_LOCAL_SYNC          = 4U,  /*!< The local sync signal from this sub-module is used to force updates. */
    FLEXPWM_IP_MASTER_SYNC         = 5U,  /*!< The master sync signal from submodule0 is used to force updates. */
    FLEXPWM_IP_EXT_FORCE           = 6U   /*!< The external force signal, EXT_FORCE, from outside the PWM module causes updates. */
} FlexPwm_Ip_ForceSourceSelTypes;

/*!
 * @brief Options available for the PWM A & B pair operation.
 * Implements : FlexPwm_Ip_ChannelPairTypes
 */
typedef enum
{
   FLEXPWM_IP_COMPLEMENTARY   = 0U,   /*!< PWM A & PWM B are complementary channels.*/
   FLEXPWM_IP_INDEPENDENT     = 1U    /*!< PWM A & PWM B operation as 2 independent channels.*/
} FlexPwm_Ip_ChannelPairTypes;

/*!
 * @brief Source selection for the generation of complementary PWM pair output.
 * Implements : FlexPwm_Ip_SrcCompSelTypes
 */
typedef enum
{
    FLEXPWM_IP_COMP_SOURCE23    =0U,    /*!< PWM23 is used as the source for the generation */
    FLEXPWM_IP_COMP_SOURCE45    =1U     /*!< PWM45 is used as the source for the generation */
} FlexPwm_Ip_SrcCompSelTypes;

/*!
 * @brief PWM counter initialization options.
 * Implements : FlexPwm_Ip_InitControlSelTypes
 */
typedef enum
{
    FLEXPWM_IP_INIT_LOCAL_SYNC    = 0U,   /*!< Local sync (PWMX) causes initialization. */
    FLEXPWM_IP_INIT_MASTER_RELOAD = 1U,   /*!< Master reload from sub-module 0 causes initialization. */
    FLEXPWM_IP_INIT_MASTER_SYNC   = 2U,   /*!< Master sync from sub-module 0 causes initialization. */
    FLEXPWM_IP_INIT_EXT_SYNC      = 3U    /*!< EXT_SYNC causes initialization. */
}  FlexPwm_Ip_InitControlSelTypes;

/*!
 * @brief FlexPWM dead time control available counter registers.
 * Implements : FlexPwm_Ip_DeadTimeCountTypes
 */
typedef enum
{
    FLEXPWM_IP_DEADTIME_COUNT_0  = 0U,   /*!< Abstract of DTCNT0. */
    FLEXPWM_IP_DEADTIME_COUNT_1  = 1U    /*!< Abstract of DTCNT1. */
} FlexPwm_Ip_DeadTimeCountTypes;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if ((defined FLEXPWM_IP_NOTIFICATION_SUPPORT_HLD) && (FLEXPWM_IP_NOTIFICATION_SUPPORT_HLD == STD_ON))
/**
 * @internal
 * @brief       Notification function callback type.
 */
typedef void (* FlexPwm_Ip_CallbackType)(uint8 param);

/**
 * @internal
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    FlexPwm_Ip_CallbackType       CbFunction;
    /** @brief Callback function parameter */
    uint8                         CbParameter;
} FlexPwm_Ip_NotificationType;
#else
/**
 * @internal
 * @brief       Notification function callback type.
 */
typedef void (* FlexPwm_Ip_CallbackType)(void * Param);

/**
 * @internal
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    FlexPwm_Ip_CallbackType       CbFunction;
    /** @brief Callback function parameter pointer */
    void                          * CbParameter;
} FlexPwm_Ip_NotificationType;
#endif

/**
*
* @brief     FlexPwm channel configuration parameters structure
* @details   FlexTimer Channel configuration parameters structure type
*/
typedef struct
{
    FlexPwm_Ip_ChannelTypes        ChannelId;           /*!< FlexPWM channel Type options. */
    FlexPwm_Ip_PolarityTypes       Polarity;            /*!< Output Polarity */
    uint16                         DutyCycle;           /*!< Duty Cycle */
    uint16                         PhaseShiftTicks;     /*!< The Phase Shift of the current FlexPWM channel in ticks. */
    FlexPwm_Ip_OuputTriggerTypes   OutputTrig;          /*!< Define the CTU trigger configuration for FlexPWM channels. */
    FlexPwm_Ip_FaultStateChTypes   FaultState;          /*!< Specify the fault state for the PWM channel output during fault, stop and debug conditions.*/
    uint8                          DisOutputFault;      /*!< Disable the PWM output on detection of fault on fault channel. */
    FlexPwm_Ip_InterruptTypes      InterruptType;       /*!< Type of interrupts */
    FlexPwm_Ip_NotificationType    ChannelCb;           /*!< Callback for the flexPwm channels */
} FlexPwm_Ip_ChannelCfgTypes;

/**
* @brief      Fault channel notification typedef
*/
typedef void (* FlexPwm_Ip_FaultCallbackType)(void);


/**
*
* @brief     Fault channels configuration parameters structure
* @details   FlexTimer fault channels configuration parameters structure type
*/
typedef struct
{
    uint8 FaultLevel;             /*!< Select the active logic level of the individual fault inputs.*/
    uint8 AutoFaultClearing;      /*!< Select automatic or manual clearing of faults.*/
    uint8 FaultSafetyMode;        /*!< select the safety mode during manual fault clearing.*/
    uint8 FullCycle;              /*!< This is used to control the timing for re-enabling the PWM outputs after a fault condition.*/
    uint8 FaultInterruptEn;       /*!< Enables fault interrupt.*/
    FlexPwm_Ip_FaultCallbackType   FaultNotification[FLEXPWM_IP_FAULT_CHANNELS_NO_U8]; /*!< Fault notification callbacks */
} FlexPwm_Ip_FaultChCfgTypes;

/**
*
* @brief     Configuration Sub Module parameters structure
* @details   FlexPwm IP specific Sub Module configuration structure type
*/
typedef struct
{
    uint8                             SubModuleId;              /*!< FlexPWM submodule Id*/
    FlexPwm_Ip_ClockSourceTypes       ClkSource;                /*!< Select clock source for current FlexPWM submodule.*/
    FlexPwm_Ip_InitControlSelTypes    InitControl;              /*!< Option to initialize the counter. */
    FlexPwm_Ip_PrescalerTypes         Prescaler;                /*!< Select pre-scaler for clock source. */
    FlexPwm_Ip_PrescalerTypes         PrescalerAlt;             /*!< Select pre-scaler alternate for clock source. */
    FlexPwm_Ip_ReloadSourceSelTypes   ReloadSrc;                /*!< Select reload signal for loading the buffered-registers with new values. */
    FlexPwm_Ip_ReloadTypes            Reload;                   /*!< Select the options how to load the buffered-registers with new values. */
    FlexPwm_Ip_LoadFrequencyTypes     LoadFrq;                  /*!< Load frequency selection. */
    FlexPwm_Ip_ForceSourceSelTypes    ForceSrc;                 /*!< Options that can trigger a PWM FORCE_OUT. */
    FlexPwm_Ip_ChannelPairTypes       ChPair;                   /*!< Options available for the PWM A & B pair operation. */
    FlexPwm_Ip_SignalPwmTypes         SigPwm;                   /*!< Signal Type options */
    uint16                            InitVal;                  /*!< Shift simultaneously in time the rising edges of the PWM channels of 2 or more FlexPWM submodules */
    FlexPwm_Ip_SrcCompSelTypes        CompSrc;                  /*!< Source selection for the generation of complementary PWM pair output. */
    uint16                            DeadTimeCount0;           /*!< Controls the dead time during 0 to 1 transitions of the PWMA output */
    uint16                            DeadTimeCount1;           /*!< Controls the dead time during 0 to 1 transitions of the complementary PWMB output */
    uint8                             DebugModeEnable;          /*!< Enable/disable Debug Mode */
    const FlexPwm_Ip_ChannelCfgTypes* const * ChannelCfgArray;  /*!< Configure the channels in each subModule */
    uint8                             NumChannelCfg;            /*!< Number of the channels that is configured*/
    uint16                            Period;                   /*!< Period in ticks */
} FlexPwm_Ip_SubModuleCfgTypes;

/**
*
* @brief     Configuration Instance parameters structure
* @details   FlexPwm IP specific instance configuration structure type
*/
typedef struct
{
    uint16  OutputEnable;               /*!< Enable the channel outputs of each instance. */
    uint16  MaskOutput;                 /*!< Mask the channel outputs of each instance. */
    uint8   MasterControlRun;           /*!< Enables the clocks to the PWM generator in each instance */
    boolean FaultFunctionalityEnable;   /*!< Allow to use fault Functionality or not */
    uint8   FaultGlitchStretchEnable;   /*!< Enable the fault glitch stretching logic */
    uint8   FaultFilterCounter;         /*!< Represents the number of consecutive samples */
    uint8   FaultFilterPeriod;          /*!< Represent the sampling period */
    uint8   NoCombinationalPath;        /*!< This is used to control the combinational path from the fault inputs to the PWM outputs.*/
    const FlexPwm_Ip_FaultChCfgTypes* FaultChCfg; /*!< Configure the channel fault in each instance */
    const FlexPwm_Ip_SubModuleCfgTypes* const * SubModuleCfgArray; /*!< Configure the SubModule in each instance */
    uint8 NumSubModuleCfg;              /*!< Number of the subModule that is configured*/
} FlexPwm_Ip_InstanceCfgTypes;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP_TYPES_H */
