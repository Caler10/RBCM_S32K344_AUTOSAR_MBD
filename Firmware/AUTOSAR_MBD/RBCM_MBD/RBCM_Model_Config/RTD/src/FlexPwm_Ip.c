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

/**
*   @file       FlexPwm_Ip.c
*
*   @addtogroup flexpwm_ip FlexPwm IPL
*   @{
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
#include "FlexPwm_Ip_HwAccess.h"
#include "Std_Types.h"
#include "SchM_Pwm.h"

#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif

#if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
#endif /* (FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) */

#include "Mcal.h"
/*===============================================================================================
*                            SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define FLEXPWM_IP_VENDOR_ID_C                         43
#define FLEXPWM_IP_MODULE_ID_C                         121
#define FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C          4
#define FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C          7
#define FLEXPWM_IP_AR_RELEASE_REVISION_VERSION_C       0
#define FLEXPWM_IP_SW_MAJOR_VERSION_C                  5
#define FLEXPWM_IP_SW_MINOR_VERSION_C                  0
#define FLEXPWM_IP_SW_PATCH_VERSION_C                  0

#if (FLEXPWM_IP_AVAILABLE == STD_ON)
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Check if this source file and RegLockMacros.h file are of the same Autosar version */
    #if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C  != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexPwm_Ip.c and RegLockMacros.h are different"
    #endif
#endif

    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip.c and Std_Types.h are different"
    #endif

#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check if header file and Devassert.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip.c and Devassert.h are different"
    #endif
#endif


    /* Check if header file and Mcal.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip.c and Mcal.h are different"
    #endif

#endif

/* Check if source file and FlexPwm_Ip.h file are of the same vendor */
#if (FLEXPWM_IP_VENDOR_ID_C != FLEXPWM_IP_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip.c and FlexPwm_Ip.h are different."
#endif

/* Check if source file and FlexPwm_Ip.h file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip.c and FlexPwm_Ip.h are different."
#endif

/* Check if source file and FlexPwm_Ip.h file are of the same Software version */
#if ((FLEXPWM_IP_SW_MAJOR_VERSION_C != FLEXPWM_IP_SW_MAJOR_VERSION)  || \
     (FLEXPWM_IP_SW_MINOR_VERSION_C != FLEXPWM_IP_SW_MINOR_VERSION)  || \
     (FLEXPWM_IP_SW_PATCH_VERSION_C != FLEXPWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip.c and FlexPwm_Ip.h are different."
#endif

/* Check if source file and FlexPwm_Ip_HwAccess.h file are of the same vendor */
#if (FLEXPWM_IP_VENDOR_ID_C != FLEXPWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip.c and FlexPwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and FlexPwm_Ip_HwAccess.h file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip.c and FlexPwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and FlexPwm_Ip_HwAccess.h file are of the same Software version */
#if ((FLEXPWM_IP_SW_MAJOR_VERSION_C != FLEXPWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
     (FLEXPWM_IP_SW_MINOR_VERSION_C != FLEXPWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
     (FLEXPWM_IP_SW_PATCH_VERSION_C != FLEXPWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip.c and FlexPwm_Ip_HwAccess.h are different."
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

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/

#if (FLEXPWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_16
#endif
#include "Pwm_MemMap.h"

/*! @brief Arrays to store the offset values that will be wrote in initial count register for each SubModules */
static uint16 FlexPwm_Ip_aOffSetVal[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Arrays to store the period values for each SubModules */
uint16 FlexPwm_Ip_aPeriod[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Arrays to store the initial count values for each SubModules */
static uint16 FlexPwm_Ip_aInitialCount[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Arrays to store the VAL1 register for each SubModules */
static uint16 FlexPwm_Ip_aVal1Reg[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Arrays to store the phase shift values for each SubModules */
static uint16 FlexPwm_Ip_aPhaseShift[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];

/*! @brief Arrays to store the duty cycle values for each SubModules */
uint16 FlexPwm_Ip_aDutyCycle[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];

#if (FLEXPWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_16
#endif
#include "Pwm_MemMap.h"

#if (FLEXPWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/*! @brief Arrays for irq fault notifications */
FlexPwm_Ip_FaultCallbackType FlexPwm_Ip_aFaultIrqCallback[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_FAULT_CHANNELS_NO_U8];

/*! @brief Arrays for irq channels notifications */
FlexPwm_Ip_NotificationType FlexPwm_Ip_aIrqCallback[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];

/*! @brief Arrays to store the Pwm signal of each SubModule */
static FlexPwm_Ip_SignalPwmTypes FlexPwm_Ip_aSignalPwm[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Arrays to store the polarity for each channel */
static FlexPwm_Ip_PolarityTypes FlexPwm_Ip_aPolarity[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];

/*! @brief Array holding the state of all FlexPWM submodules */
FlexPwm_Ip_StateTypes FlexPwm_Ip_aSubModuleSate[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Array holding the state of all FlexPWM instances */
FlexPwm_Ip_StateTypes FlexPwm_Ip_aInstanceSate[FLEXPWM_IP_INSTANCE_COUNT_U8];

#if (FLEXPWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/*! @brief Arrays of base addresses for FlexPWM instances. */
FlexPwm_Ip_HwAddrType * const FlexPwm_Ip_aBasePtr[FLEXPWM_IP_INSTANCE_COUNT_U8] = IP_FLEXPWM_BASE_PTRS;

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the Instance accessible in user mode.
 *
 *END**************************************************************************/
void FlexPwm_Ip_SetUserAccessAllowed(uint8 Instance);

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the Instance not accessible in user mode.
 *
 *END**************************************************************************/
void FlexPwm_Ip_ClrUserAccessAllowed(uint8 Instance);
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) */

static inline void FlexPwm_Ip_SetupControl2Reg(uint8 Instance, const FlexPwm_Ip_SubModuleCfgTypes * SubModCfg);

static inline void FlexPwm_Ip_SetupControl1Reg(uint8 Instance, const FlexPwm_Ip_SubModuleCfgTypes * SubModCfg);

static inline void FlexPwm_Ip_SetupFaultIns(uint8 Instance, const FlexPwm_Ip_InstanceCfgTypes * InsCfg);

static inline void FlexPwm_Ip_SetupDutyChannelX(uint8 Instance, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, uint16 DutyCycle);

static inline void FlexPwm_Ip_SetupDutyChannelA(uint8 Instance, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, uint16 DutyCycle);

static inline void FlexPwm_Ip_SetupDutyChannelB(uint8 Instance, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, uint16 DutyCycle);

static inline void FlexPwm_Ip_SetupChannels(uint8 Instance, FlexPwm_Ip_ChannelPairTypes ChannelPairType, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, const FlexPwm_Ip_ChannelCfgTypes * ChannelCfg);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the Instance accessible in user mode.
 *
 *END**************************************************************************/
void FlexPwm_Ip_SetUserAccessAllowed(uint8 Instance)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    SET_USER_ACCESS_ALLOWED((uint32)Base, FLEXPWM_AE_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the Instance not accessible in user mode.
 *
 *END**************************************************************************/
void FlexPwm_Ip_ClrUserAccessAllowed(uint8 Instance)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    CLR_USER_ACCESS_ALLOWED((uint32)Base, FLEXPWM_AE_PROT_MEM_U32);
}
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) */

static inline void FlexPwm_Ip_SetupControl2Reg(uint8 Instance, const FlexPwm_Ip_SubModuleCfgTypes * SubModCfg)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    /* Updates Clock source select. */
    FlexPwm_Ip_SetClockSrcHw(Base, SubModCfg->SubModuleId, SubModCfg->ClkSource);
    /* Update the source of the INIT signal which goes to the counter. */
    FlexPwm_Ip_SetInitSrcHw(Base, SubModCfg->SubModuleId, SubModCfg->InitControl);
    /* Updates the source of the RELOAD signal. */
    FlexPwm_Ip_SetReloadSrcHw(Base, SubModCfg->SubModuleId, SubModCfg->ReloadSrc);
    /* Update the source of the FORCE OUTPUT signal. */
    FlexPwm_Ip_SetForceSrcHw(Base, SubModCfg->SubModuleId, SubModCfg->ForceSrc);
    /* If FORCE_SEL equals local force */
    if (FLEXPWM_IP_LOCAL_FORCE == SubModCfg->ForceSrc)
    {
        FlexPwm_Ip_SetForceInitEnHw(Base, SubModCfg->SubModuleId, 1U);
        FlexPwm_Ip_SetForceInitHw(Base, SubModCfg->SubModuleId, 1U);
    }
    /* The PWMA and PWMB channels will be independent PWMs or a complementary PWM pair. */
    FlexPwm_Ip_SetPairHw(Base, SubModCfg->SubModuleId, SubModCfg->ChPair);
    /* Enable or Disable Debug mode.*/
    FlexPwm_Ip_SetDebugModeHw(Base, SubModCfg->SubModuleId, SubModCfg->DebugModeEnable);
}

static inline void FlexPwm_Ip_SetupControl1Reg(uint8 Instance, const FlexPwm_Ip_SubModuleCfgTypes * SubModCfg)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    /* Selects the divide ratio of the PWM clock frequency. */
    FlexPwm_Ip_SetPrescalerHw(Base, SubModCfg->SubModuleId, SubModCfg->Prescaler);
    /* Select the options how to load the buffered-registers with new values. */
    FlexPwm_Ip_SetReloadTypesHw(Base, SubModCfg->SubModuleId, SubModCfg->Reload);
    /* Selects the PWM load frequency. */
    FlexPwm_Ip_SetLoadFrqHw(Base, SubModCfg->SubModuleId, SubModCfg->LoadFrq);
}

static inline void FlexPwm_Ip_SetupFaultIns(uint8 Instance, const FlexPwm_Ip_InstanceCfgTypes * InsCfg)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8 Index = 0U;
    /* Select the active logic level of the individual fault inputs */
    FlexPwm_Ip_SetFaultLevelHw(Base, InsCfg->FaultChCfg->FaultLevel);
    /* Select automatic or manual clearing of faults. */
    FlexPwm_Ip_SetAutoFltClrHw(Base, InsCfg->FaultChCfg->AutoFaultClearing);
    /* Select the safety mode during manual fault clearing. */
    FlexPwm_Ip_SetFltSafeModeHw(Base, InsCfg->FaultChCfg->FaultSafetyMode);
    /* Control the timing for re-enabling the PWM outputs after a fault condition. */
    FlexPwm_Ip_SetFltFullCycleHw(Base, InsCfg->FaultChCfg->FullCycle);
    /* Control the combinational path from the fault inputs to the PWM outputs. */
    FlexPwm_Ip_SetCombPathHw(Base, InsCfg->NoCombinationalPath);
    /* Setup the fault glitch stretching logic */
    FlexPwm_Ip_SetFltGlitHw(Base, InsCfg->FaultGlitchStretchEnable);
    /* Represents the number of consecutive samples. */
    FlexPwm_Ip_SetFltFilterCntHw(Base, InsCfg->FaultFilterCounter);
    /* Represent the sampling period */
    FlexPwm_Ip_SetFltFilterPerHw(Base, InsCfg->FaultFilterPeriod);
    if(0x00U != InsCfg->FaultChCfg->FaultInterruptEn)
    {
        /* Enable fault interrupt */
        FlexPwm_Ip_SetFltInterruptHw(Base, InsCfg->FaultChCfg->FaultInterruptEn);
        /* Holding the callback function in the array */
        for (Index = 0; Index < FLEXPWM_IP_FAULT_CHANNELS_NO_U8; Index ++)
        {
            FlexPwm_Ip_aFaultIrqCallback[Instance][Index] = InsCfg->FaultChCfg->FaultNotification[Index];
        }
    }
}

static inline void FlexPwm_Ip_SetupDutyChannelX(uint8 Instance, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, uint16 DutyCycle)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint16 ValueOff = 0U;
    uint8 UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 0U);
    if (FLEXPWM_IP_EDGE_ALIGNED == PwmSign)
    {
        if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
        {
            ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule] - (uint16)1U;
            /* Set VAL0 register */
            FlexPwm_Ip_SetVal0Hw(Base, SubModule, ValueOff);
            /* Write the POL bit in OCTRL */
            FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FlexPwm_Ip_aPolarity[Instance][UniqueSub]);
        }
        else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
        {
            ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule] - (uint16)1U;
            /* Set VAL0 register */
            FlexPwm_Ip_SetVal0Hw(Base, SubModule, ValueOff);
            /* Set polarity */
            if (FLEXPWM_IP_POL_LOW == FlexPwm_Ip_aPolarity[Instance][UniqueSub])
            {
                /* The compare will be in 0 so set the POL bit */
                /* 0 percent will mean constant 1 logic level in PWM_LOW mode */
                FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FLEXPWM_IP_POL_HIGH);
            }
            else
            {
                /* The compare will be in 0 so clear the POL bit */
                /* 0 percent will mean constant 0 logic level in PWM_LOW mode */
                FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FLEXPWM_IP_POL_LOW);
            }
        }
        else
        {
            ValueOff = (uint16)(DutyCycle + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint32)FLEXPWM_IP_SIGNED_REG_OFFSET);
            /* Set VAL0 register */
            FlexPwm_Ip_SetVal0Hw(Base, SubModule, ValueOff);
            /* Set polarity */
            if (FLEXPWM_IP_POL_LOW == FlexPwm_Ip_aPolarity[Instance][UniqueSub])
            {
                /* The compare will be in 0 so set the POL bit */
                /* 0 percent will mean constant 1 logic level in PWM_LOW mode */
                FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FLEXPWM_IP_POL_HIGH);
            }
            else
            {
                /* The compare will be in 0 so clear the POL bit */
                /* 0 percent will mean constant 0 logic level in PWM_LOW mode */
                FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FLEXPWM_IP_POL_LOW);
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
}

static inline void FlexPwm_Ip_SetupDutyChannelA(uint8 Instance, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, uint16 DutyCycle)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint16 ValueOff = 0U;
    uint16 ValueOn = 0U;
    uint8 UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);

    switch(PwmSign)
    {
        case FLEXPWM_IP_EDGE_ALIGNED:
            if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOn);
            }
            else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint16)1U;
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
            }
            else
            {
                /* Align to signed values for VAL registers */
                ValueOn  = (uint16)((uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule]);
                ValueOff = (uint16)(DutyCycle + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + 1U);
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
                /* Set the initial bit */
                FlexPwm_Ip_SetInitialValHw(Base, SubModule, FLEXPWM_IP_PWMA, 1U);
            }
            break;
        case FLEXPWM_IP_CENTER_ALIGNED:
            if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
            {
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, FlexPwm_Ip_aInitialCount[Instance][SubModule]);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, FlexPwm_Ip_aInitialCount[Instance][SubModule]);
            }
            else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
            {
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, FlexPwm_Ip_aInitialCount[Instance][SubModule]);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, (FlexPwm_Ip_aVal1Reg[Instance][SubModule] + 1U));
            }
            else
            {
                ValueOff = (uint16)(DutyCycle >> 1U);
                ValueOn = (((uint16)0xFFFF - ValueOff) + (uint16)1U);
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
            }
            break;
        case FLEXPWM_IP_PHASE_SHIFTED:
            if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOn);
            }
            else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aPeriod[Instance][SubModule];
                ValueOff += FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] + (uint16)1U;
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
            }
            else
            {
                ValueOn  = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                ValueOff +=(uint16)((FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] + DutyCycle + (uint16)1U) % (FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)1U));
                /* Write On value to register VAL2 */
                FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL3 */
                FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
            }
            break;
        default:
            /* Do Nothing */
            break;
    }

}

static inline void FlexPwm_Ip_SetupDutyChannelB(uint8 Instance, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, uint16 DutyCycle)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint16 ValueOff = 0U;
    uint16 ValueOn  = 0U;
    uint8 UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 2U);

    switch(PwmSign)
    {
        case FLEXPWM_IP_EDGE_ALIGNED:
            if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOn);
            }
            else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint16)1U;
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
            }
            else
            {
                /* Align to signed values for VAL registers */
                ValueOn  = (uint16)((uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule]);
                ValueOff = (uint16)(DutyCycle + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + 1U);
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
                /* Set the initial bit */
                FlexPwm_Ip_SetInitialValHw(Base, SubModule, FLEXPWM_IP_PWMB, 1U);
            }
            break;
        case FLEXPWM_IP_CENTER_ALIGNED:
            if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
            {
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, FlexPwm_Ip_aInitialCount[Instance][SubModule]);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, FlexPwm_Ip_aInitialCount[Instance][SubModule]);
            }
            else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
            {
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, FlexPwm_Ip_aInitialCount[Instance][SubModule]);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, (FlexPwm_Ip_aVal1Reg[Instance][SubModule] + 1U));
            }
            else
            {
                ValueOff = (uint16)(DutyCycle >> 1U);
                ValueOn = (((uint16)0xFFFF - ValueOff) + (uint16)1U);
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
            }
            break;
        case FLEXPWM_IP_PHASE_SHIFTED:
            if ((DutyCycle == 0U) || (FlexPwm_Ip_aPeriod[Instance][SubModule] == 0U))
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOn);
            }
            else if (DutyCycle == FlexPwm_Ip_aPeriod[Instance][SubModule])
            {
                ValueOn = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint16)FlexPwm_Ip_aPeriod[Instance][SubModule];
                ValueOff += FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] + (uint16)1U;
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
            }
            else
            {
                ValueOn  = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                ValueOff +=(uint16)((FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] + DutyCycle + (uint16)1U) % (FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)1U));
                /* Write On value to register VAL4 */
                FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                /* Write Off value to register VAL5 */
                FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
            }
            break;
        default:
            /* Do Nothing */
            break;
    }
}

static inline void FlexPwm_Ip_SetupChannels(uint8 Instance, FlexPwm_Ip_ChannelPairTypes ChannelPairType, uint8 SubModule, FlexPwm_Ip_SignalPwmTypes PwmSign, const FlexPwm_Ip_ChannelCfgTypes * ChannelCfg)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8 UniqueSub = 0U;
    /* Specify the fault state for the PWM channel output during fault, stop and debug conditions.*/
    FlexPwm_Ip_SetChFltStateHw(Base, SubModule, ChannelCfg->ChannelId, ChannelCfg->FaultState);
    /* Set Output Polarity */
    FlexPwm_Ip_SetPolarityHw(Base, SubModule, ChannelCfg->ChannelId, ChannelCfg->Polarity);
    /* Define the CTU trigger configuration for FlexPWM channels. */
    FlexPwm_Ip_SetOutputTrigHw(Base, SubModule, ChannelCfg->OutputTrig);
    /* Disable the PWM output on detection of fault on fault channel. */
    FlexPwm_Ip_SetChFltDisableHw(Base, SubModule, ChannelCfg->ChannelId, ChannelCfg->DisOutputFault);
    /* Setup the duty cycle */
    switch(ChannelCfg->ChannelId)
    {
        case FLEXPWM_IP_PWMX:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 0U);
            FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] = ChannelCfg->DutyCycle;
            FlexPwm_Ip_aPolarity[Instance][UniqueSub] = ChannelCfg->Polarity;
            FlexPwm_Ip_SetupDutyChannelX(Instance, SubModule, PwmSign, ChannelCfg->DutyCycle);
            break;
        case FLEXPWM_IP_PWMA:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);
            FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] = ChannelCfg->PhaseShiftTicks;
            FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] = ChannelCfg->DutyCycle;
            FlexPwm_Ip_aPolarity[Instance][UniqueSub] = ChannelCfg->Polarity;
            FlexPwm_Ip_SetupDutyChannelA(Instance, SubModule, PwmSign, ChannelCfg->DutyCycle);
            if(FLEXPWM_IP_COMPLEMENTARY == ChannelPairType)
            {
                if(FLEXPWM_IP_POL_LOW == ChannelCfg->Polarity)
                {
                    FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMB, FLEXPWM_IP_POL_LOW);
                }
                else
                {
                    FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMB, FLEXPWM_IP_POL_HIGH);
                }
            }
            break;
        case FLEXPWM_IP_PWMB:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 2U);
            FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] = ChannelCfg->PhaseShiftTicks;
            FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] = ChannelCfg->DutyCycle;
            FlexPwm_Ip_aPolarity[Instance][UniqueSub] = ChannelCfg->Polarity;
            FlexPwm_Ip_SetupDutyChannelB(Instance, SubModule, PwmSign, ChannelCfg->DutyCycle);
            break;
        default:
            /* Do Nothing */
            break;
    }
    if(FLEXPWM_IP_COMPARE_INT == ChannelCfg->InterruptType)
    {
        FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbFunction = ChannelCfg->ChannelCb.CbFunction;
        FlexPwm_Ip_aIrqCallback[Instance][UniqueSub].CbParameter = ChannelCfg->ChannelCb.CbParameter;
    }
}

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
/**
* @brief        This function initializes an instance of the FlexPWM module
* @details      This function will initialize with default values all FlexPWM submodule registers.
*               Will loop through all FlexPWM channels in the configuration structure and will
*               setup required submodules for each channel
*
* @param[in]    Instance       Instance number of the PWM module.
* @param[in]    InstanceCfg    Pointer to FlexPWM instance configuration structure
*
* @return       void
* @implements FlexPwm_Ip_Init_Activity
*/
void FlexPwm_Ip_Init(uint8 Instance, const FlexPwm_Ip_InstanceCfgTypes * InstanceCfg)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Set the UAA bit in REG_PROT to make the Instance accessible in user mode */
    OsIf_Trusted_Call1param(FlexPwm_Ip_SetUserAccessAllowed, Instance);
#endif
#endif

    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8 SubIndex = 0U;
    uint8 ChIndex  = 0U;
    /* Configure all subModule in the used Instance */
    for (SubIndex = 0; SubIndex < InstanceCfg->NumSubModuleCfg; SubIndex++)
    {
        FlexPwm_Ip_aOffSetVal[Instance][InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId] = InstanceCfg->SubModuleCfgArray[SubIndex]->InitVal;
        FlexPwm_Ip_aPeriod[Instance][InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId] = InstanceCfg->SubModuleCfgArray[SubIndex]->Period;
        FlexPwm_Ip_aSignalPwm[Instance][InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId] = InstanceCfg->SubModuleCfgArray[SubIndex]->SigPwm;
        /* Configure subModule control 2 register */
        FlexPwm_Ip_SetupControl2Reg(Instance, InstanceCfg->SubModuleCfgArray[SubIndex]);
        /* Configure subModule control 1 register */
        FlexPwm_Ip_SetupControl1Reg(Instance, InstanceCfg->SubModuleCfgArray[SubIndex]);
        /* Set Period */
        FlexPwm_Ip_UpdatePeriod(Instance, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, InstanceCfg->SubModuleCfgArray[SubIndex]->Period);
        /* Configure all channels in the used SubModule */
        for (ChIndex = 0; ChIndex < (InstanceCfg->SubModuleCfgArray[SubIndex])->NumChannelCfg ; ChIndex++)
        {
            /* Configure all channels in the used subModule */
            FlexPwm_Ip_SetupChannels(Instance, InstanceCfg->SubModuleCfgArray[SubIndex]->ChPair, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, InstanceCfg->SubModuleCfgArray[SubIndex]->SigPwm, \
                                                                                                                                   (InstanceCfg->SubModuleCfgArray[SubIndex])->ChannelCfgArray[ChIndex]);
        }
        if (FLEXPWM_IP_COMPLEMENTARY == InstanceCfg->SubModuleCfgArray[SubIndex]->ChPair)
        {
            /* Setup the dead time count 0 value */
            FlexPwm_Ip_SetDeadTimeHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, FLEXPWM_IP_DEADTIME_COUNT_0, InstanceCfg->SubModuleCfgArray[SubIndex]->DeadTimeCount0);
            /* Setup the dead time count 1 value */
            FlexPwm_Ip_SetDeadTimeHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, FLEXPWM_IP_DEADTIME_COUNT_1, InstanceCfg->SubModuleCfgArray[SubIndex]->DeadTimeCount1);
            /* Source selection for the generation of complementary PWM pair output. */
            FlexPwm_Ip_SetSrcCompHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, (InstanceCfg->SubModuleCfgArray[SubIndex])->CompSrc);
        }
        /* Set the corresponding bit so that the specific LDOK bits are cleared */
        FlexPwm_Ip_ClearLoadOkayHw(Base, 1U << InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId);
        /* Set the corresponding bit so that the new values are loaded */
        FlexPwm_Ip_SetLoadOkayHw(Base, 1U << InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId);
        FlexPwm_Ip_aSubModuleSate[Instance][InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId] = (FlexPwm_Ip_StateTypes)FLEXPWM_IP_INIT_STATE;
    }
    if(TRUE == InstanceCfg->FaultFunctionalityEnable)
    {
        /* Setup for fault configuration */
        FlexPwm_Ip_SetupFaultIns(Instance, InstanceCfg);
    }

    /* Enables the clocks to the PWM generator in each instance */
    FlexPwm_Ip_StartCounterHw(Base, InstanceCfg->MasterControlRun);
    /* Mask the channel outputs of each instance. */
    FlexPwm_Ip_MaskOutputChannels(Instance, InstanceCfg->MaskOutput, TRUE);
    /* Enable the channel outputs of each instance. */
    FlexPwm_Ip_SetOutputEnHw(Base, InstanceCfg->OutputEnable);
    /* Confirm the instance is initialized*/
    FlexPwm_Ip_aInstanceSate[Instance] = (FlexPwm_Ip_StateTypes)FLEXPWM_IP_INIT_STATE;
}

/*!
 * @brief      De-initialize an instance of the FlexPWM module
 * @details    The function De-initializes an instance of the FlexPWM module restoring all the
 *             registers to their reset values.
 *
 * @param[in]  Instance      Instance number of the PWM module.
 *
 * @return     void
 * @implements FlexPwm_Ip_DeInit_Activity
 */
void FlexPwm_Ip_DeInit(uint8 Instance)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8 SubIndex = 0U;

    FlexPwm_Ip_UnMaskOutputChannels(Instance, 0xFFFU, TRUE);
    /* De-initialize all subModule in the used Instance */
    for (SubIndex = 0; SubIndex < FLEXPWM_IP_SUBMODULE_COUNT_U8; SubIndex++)
    {
        if (FLEXPWM_IP_INIT_STATE == FlexPwm_Ip_aSubModuleSate[Instance][SubIndex])
        {
            /* Configure subModule control 2 register */
            FlexPwm_Ip_SetResetSubHw(Base, SubIndex);
            FlexPwm_Ip_aSubModuleSate[Instance][SubIndex] = (FlexPwm_Ip_StateTypes)FLEXPWM_IP_UNINIT_STATE;
        }
    }
    /* Confirm the instance is uninitialized*/
    FlexPwm_Ip_aInstanceSate[Instance] = (FlexPwm_Ip_StateTypes)FLEXPWM_IP_UNINIT_STATE;
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Clear the UAA bit in REG_PROT */
    OsIf_Trusted_Call1param(FlexPwm_Ip_ClrUserAccessAllowed, Instance);
#endif
#endif
}

 /*!
 * @brief      Update pwm pulse width.
 * @details    This function will update the PWM signal pulse width.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 * @param[in]  ChannelType   FlexPWM channel Type options.
 * @param[in]  DutyCycle     Duty cycle value in ticks
 *
 * @return     void
 * @implements FlexPwm_Ip_UpdateDutyCycle_Activity
 */
void FlexPwm_Ip_UpdateDutyCycle(uint8 Instance, uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelType, uint16 DutyCycle)
{
    uint8 UniqueSub = 0U;
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_50();

    switch(ChannelType)
    {
        case FLEXPWM_IP_PWMX:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 0U);
            FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] = DutyCycle;
            FlexPwm_Ip_SetupDutyChannelX(Instance, SubModule, FlexPwm_Ip_aSignalPwm[Instance][SubModule], DutyCycle);
            break;
        case FLEXPWM_IP_PWMA:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);
            FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] = DutyCycle;
            FlexPwm_Ip_SetupDutyChannelA(Instance, SubModule, FlexPwm_Ip_aSignalPwm[Instance][SubModule], DutyCycle);
            break;
        case FLEXPWM_IP_PWMB:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 2U);
            FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] = DutyCycle;
            FlexPwm_Ip_SetupDutyChannelB(Instance, SubModule, FlexPwm_Ip_aSignalPwm[Instance][SubModule], DutyCycle);
            break;
        default:
            /* Do Nothing */
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_50();
}

/**
 * @brief      Update pwm pulse width for 3 channels (A, B, X)
 * @details    This function will update the PWM signal pulse width for 3 channels at the same time
 *             The main differences between this function and FlexPwm_Ip_UpdateDutyCycle() is the execution speed. This
 *             feature makes this function ideal for applications like motor controlling.
 *             The downside is the low flexibility of the parameters (this function accept only updates in ticks).
 *
 * @param[in]  Instance            Instance number of the FlexPwm module.
 * @param[in]  SubModule           SubModule number of the FlexPwm module.
 * @param[in]  NumberOfChannels    The number of channels which should be updated.
 * @param[in]  PwmPulseWidth       The list of duty cycles for selected channels.
 * @param[in]  ChannelType         The list of channels types which should be updated.
 *
 * @return     void
 * @implements FlexPwm_Ip_FastUpdateDutyCycle_Activity
 */
void FlexPwm_Ip_FastUpdateDutyCycle(uint8 Instance, uint8 SubModule, uint8 NumberOfChannels,
                                    const uint16 * PwmPulseWidth, const FlexPwm_Ip_ChannelTypes * ChannelType)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint16 ValueOff = 0U;
    uint16 ValueOn = 0U;
    uint8 UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);
    uint8 Index;
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_51();

    for (Index = 0U; Index < NumberOfChannels; Index++)
    {
        switch(ChannelType[Index])
        {
            case FLEXPWM_IP_PWMX:
                if (FLEXPWM_IP_EDGE_ALIGNED == FlexPwm_Ip_aSignalPwm[Instance][SubModule])
                {
                    /* Set VAL0 register */
                    FlexPwm_Ip_SetVal0Hw(Base, SubModule, PwmPulseWidth[Index] + FlexPwm_Ip_aInitialCount[Instance][SubModule]);
                }
                else
                {
                    /* Do Nothing */
                }
                break;
            case FLEXPWM_IP_PWMA:
                switch(FlexPwm_Ip_aSignalPwm[Instance][SubModule])
                {
                    case FLEXPWM_IP_EDGE_ALIGNED:
                        /* Align to signed values for VAL registers */
                        ValueOn  = (uint16)((uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule]);
                        ValueOff = (uint16)(PwmPulseWidth[Index] + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + 1U);
                        /* Write On value to register VAL2 */
                        FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                        /* Write Off value to register VAL3 */
                        FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
                        /* Set the initial bit */
                        FlexPwm_Ip_SetInitialValHw(Base, SubModule, FLEXPWM_IP_PWMA, 1U);
                        break;
                    case FLEXPWM_IP_CENTER_ALIGNED:
                        ValueOff = (uint16)(PwmPulseWidth[Index] >> 1U);
                        ValueOn = (((uint16)0xFFFF - ValueOff) + (uint16)1U);
                        /* Write On value to register VAL2 */
                        FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                        /* Write Off value to register VAL3 */
                        FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
                        break;
                    case FLEXPWM_IP_PHASE_SHIFTED:
                        ValueOn  = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                        ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                        ValueOff +=(uint16)((FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] + PwmPulseWidth[Index] + (uint16)1U) % (FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)1U));
                        /* Write On value to register VAL2 */
                        FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
                        /* Write Off value to register VAL3 */
                        FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
                        break;
                    default:
                        /* Do Nothing */
                        break;
                }
                break;
            case FLEXPWM_IP_PWMB:
                switch(FlexPwm_Ip_aSignalPwm[Instance][SubModule])
                {
                    case FLEXPWM_IP_EDGE_ALIGNED:
                        /* Align to signed values for VAL registers */
                        ValueOn  = (uint16)((uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule]);
                        ValueOff = (uint16)(PwmPulseWidth[Index] + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule] + (uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + 1U);
                        /* Write On value to register VAL4 */
                        FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                        /* Write Off value to register VAL5 */
                        FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
                        /* Set the initial bit */
                        FlexPwm_Ip_SetInitialValHw(Base, SubModule, FLEXPWM_IP_PWMB, 1U);
                        break;
                    case FLEXPWM_IP_CENTER_ALIGNED:
                        ValueOff = (uint16)(PwmPulseWidth[Index] >> 1U);
                        ValueOn = (((uint16)0xFFFF - ValueOff) + (uint16)1U);
                        /* Write On value to register VAL4 */
                        FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                        /* Write Off value to register VAL5 */
                        FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
                        break;
                    case FLEXPWM_IP_PHASE_SHIFTED:
                        ValueOn  = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule] + FlexPwm_Ip_aPhaseShift[Instance][UniqueSub];
                        ValueOff = (uint16)FLEXPWM_IP_SIGNED_REG_OFFSET + FlexPwm_Ip_aOffSetVal[Instance][SubModule];
                        ValueOff +=(uint16)((FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] + PwmPulseWidth[Index] + (uint16)1U) % (FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint16)1U));
                        /* Write On value to register VAL4 */
                        FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
                        /* Write Off value to register VAL5 */
                        FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
                        break;
                    default:
                        /* Do Nothing */
                        break;
                }
                break;
            default:
                /* Do Nothing */
                break;
        }
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_51();
}

 /*!
 * @brief      Update pwm period.
 * @details    This function will update the PWM signal period.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 * @param[in]  Period        Period value in ticks
 *
 * @return     void
 * @implements FlexPwm_Ip_UpdatePeriod_Activity
 */
void FlexPwm_Ip_UpdatePeriod(uint8 Instance, uint8 SubModule, uint16 Period)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint32 TempVal1 = 0U;
    uint32 TempInit = 0U;
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_52();

    FlexPwm_Ip_aPeriod[Instance][SubModule] = Period;

    switch(FlexPwm_Ip_aSignalPwm[Instance][SubModule])
    {
        case FLEXPWM_IP_EDGE_ALIGNED:
        case FLEXPWM_IP_PHASE_SHIFTED:
            /* Calculate the value of VAL1 register for edge aligned or phase shifted */
            TempVal1 = (uint32)((uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint32)FlexPwm_Ip_aPeriod[Instance][SubModule] + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule]) - (uint32)(1U);
            TempInit = (uint32)FLEXPWM_IP_SIGNED_REG_OFFSET + (uint32)FlexPwm_Ip_aOffSetVal[Instance][SubModule];
            TempVal1 &= (uint32)0xFFFF;
            TempInit &= (uint32)0xFFFF;
            /* Set INT reg */
            FlexPwm_Ip_SetInitialCountHw(Base, SubModule, (uint16)TempInit);
            /* Set VAL1 register */
            FlexPwm_Ip_SetVal1Hw(Base, SubModule, (uint16)TempVal1);
            FlexPwm_Ip_aInitialCount[Instance][SubModule] = (uint16)TempInit;
            FlexPwm_Ip_aVal1Reg[Instance][SubModule] = (uint16)TempVal1;
            break;
        case FLEXPWM_IP_CENTER_ALIGNED:
            /* Update the new period */
            TempVal1 = (uint32)((uint32)Period >> 1U);
            /* Now compute the 2's complement for initialization */
            TempInit =  (~TempVal1) + (uint32)0x0001U;
            TempInit &= (uint32)0xFFFF;
            /* Set INT reg */
            FlexPwm_Ip_SetInitialCountHw(Base, SubModule, (uint16)TempInit);
            /* Set VAL1 register */
            FlexPwm_Ip_SetVal1Hw(Base, SubModule, (uint16)TempVal1);
            /* Set VAL0 to 0x0000 - to set a proper middle reload reference point */
            FlexPwm_Ip_SetVal0Hw(Base, SubModule, (uint16)0U);
            FlexPwm_Ip_aInitialCount[Instance][SubModule] = (uint16)TempInit;
            FlexPwm_Ip_aVal1Reg[Instance][SubModule] = (uint16)TempVal1;
            break;
        default:
            /* Do Nothing */
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_52();
}

 /*!
 * @brief      Function Name : FlexPwm_Ip_OverwriteOutputChannels
 * @details    This function change the output value for a channel.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 * @param[in]  ChannelType
 * @param[in]  OutputState
 *
 * @return     void
 * @implements FlexPwm_Ip_OverwriteOutputChannels_Activity
 */
void FlexPwm_Ip_OverwriteOutputChannels(uint8 Instance, uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelType, FlexPwm_Ip_OutputStateTypes OutputState)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint16 ValueOn = FlexPwm_Ip_aInitialCount[Instance][SubModule];
    uint16 ValueOff = FlexPwm_Ip_aVal1Reg[Instance][SubModule];
    uint8 UniqueSub = 0U;
    if (FLEXPWM_IP_PWMX == ChannelType)
    {
        UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 0U);
    }
    else if (FLEXPWM_IP_PWMA == ChannelType)
    {
        UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);
    }
    else
    {
        UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 2U);
    }
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
#endif
    /* Polarity is HIGH */
    if (FLEXPWM_IP_POL_HIGH == FlexPwm_Ip_aPolarity[Instance][UniqueSub])
    {
        ValueOff = (FLEXPWM_IP_OUT_LOW == OutputState)? ValueOn : (ValueOff + (uint16)1U);
        ValueOn  = (FLEXPWM_IP_OUT_LOW == OutputState)? (ValueOn - (uint16)1U) : ValueOn;
    }
    else
    {
        ValueOff = (FLEXPWM_IP_OUT_LOW == OutputState)? (ValueOff + (uint16)1U) : ValueOn;
        ValueOn  = (FLEXPWM_IP_OUT_LOW == OutputState)? ValueOn : (ValueOn - (uint16)1U);
    }

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_53();

    /* Clear LDOK if is set before setting VALx registers */
    FlexPwm_Ip_ClearLoadOkayHw(Base, 1U << SubModule);

    switch(ChannelType)
    {
        case FLEXPWM_IP_PWMX:
            ValueOff = FlexPwm_Ip_aVal1Reg[Instance][SubModule];
            /* Write Off value to register VAL0 */
            FlexPwm_Ip_SetVal0Hw(Base, SubModule, ValueOff);
            /* Do this to ensure the channel's polarity is set to a proper value when exiting from 0% to any other mode*/
            if (FLEXPWM_IP_OUT_HIGH == OutputState)
            {
                /* The compare will be in 0 so set the POL bit */
                /* 0 percent will mean constant 1 logic level in PWM_LOW mode */
                FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FLEXPWM_IP_POL_LOW);
            }
            else
            {
                /* The compare will be in 0 so clear the POL bit */
                /* 0 percent will mean constant 0 logic level in PWM_HIGH mode */
                FlexPwm_Ip_SetPolarityHw(Base, SubModule, FLEXPWM_IP_PWMX, FLEXPWM_IP_POL_HIGH);
            }
            break;
        case FLEXPWM_IP_PWMA:
            FlexPwm_Ip_SetVal2Hw(Base, SubModule, ValueOn);
            FlexPwm_Ip_SetVal3Hw(Base, SubModule, ValueOff);
            break;
        case FLEXPWM_IP_PWMB:
            FlexPwm_Ip_SetVal4Hw(Base, SubModule, ValueOn);
            FlexPwm_Ip_SetVal5Hw(Base, SubModule, ValueOff);
            break;
        default:
            /* Do Nothing */
            break;
    }
    FlexPwm_Ip_SetLoadModeHw(Base, SubModule, 1U);
    /* Set the corresponding bit so that the specific LDOK bits are cleared */
    FlexPwm_Ip_ClearLoadOkayHw(Base, 1U << SubModule);
    /* Set the corresponding bit so that the new values are loaded */
    FlexPwm_Ip_SetLoadOkayHw(Base, 1U << SubModule);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_53();
}

/*!
* @brief      Function Name : FlexPwm_Ip_MaskOutputChannels
* @details    This function shall mask the output of the channels and at match events shall be ignored by the masked channels.
*             Due to hardware specific feature, channels X will be forced to their active state, channels A and B will be forced to their inactive state.
*
* @param[in]  Instance      Instance number of the FlexPwm module.
* @param[in]  ChannelsMask  Bits mask will be set to mask corresponding channels.
*                           Corresponding bits with masked channels are shown as bellow:
*                                       ----- --------- -----------
*                                      | Bit | Channel | Submodule |
*                                       ----- --------- -----------
*                                      |  0  |         |     0     |
*                                       -----           -----------
*                                      |  1  |         |     1     |
*                                       -----           -----------
*                                      |  2  |    X    |     2     |
*                                       -----           -----------
*                                      |  3  |         |     3     |
*                                       ----- --------- -----------
*                                      |  4  |         |     0     |
*                                       -----           -----------
*                                      |  5  |         |     1     |
*                                       -----           -----------
*                                      |  6  |    B    |     2     |
*                                       -----           -----------
*                                      |  7  |         |     3     |
*                                       ----- --------- -----------
*                                      |  8  |         |     0     |
*                                       -----           -----------
*                                      |  9  |         |     1     |
*                                       -----           -----------
*                                      |  10 |    A    |     2     |
*                                       -----           -----------
*                                      |  11 |         |     3     |
*                                       ----- --------- -----------
* @param[in]  UpdateType    The update is immediate or wait for a FORCE_OUT event.
*                           TRUE     Update immediately
*                           FALSE    Wait for a trigger event
*
* @return     void
* @implements FlexPwm_Ip_MaskOutputChannels_Activity
*/
void FlexPwm_Ip_MaskOutputChannels(uint8   Instance,
                                   uint16  ChannelsMask,
                                   boolean UpdateType
                                  )
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8  UpdateMaskValue            = 0U;
    uint8  SubIndex                   = 0U;
    uint16 IsSubModuleSelected        = 0U;
    uint16 Submodule0IndexsInMask     = ((uint16)1U << FLEXPWM_MASK_MASKX_SHIFT) | ((uint16)1U << FLEXPWM_MASK_MASKA_SHIFT) | ((uint16)1U << FLEXPWM_MASK_MASKB_SHIFT);
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(0xFFFU >= ChannelsMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_54();

    FlexPwm_Ip_SetOutmaskReg(Base, ChannelsMask);
    for (SubIndex = 0; SubIndex < FLEXPWM_IP_SUBMODULE_COUNT_U8; SubIndex++)
    {
        IsSubModuleSelected = (uint16)(Submodule0IndexsInMask << SubIndex) & ChannelsMask;
        /* Check if a submodule's selected in the mask */
        if (0U != IsSubModuleSelected)
        {
            /* If the type of update is immediate */
            if (TRUE == UpdateType)
            {
                UpdateMaskValue |= (1U << SubIndex);
                FlexPwm_Ip_SetUpdateOutputMaskType(Base, UpdateMaskValue);
            }
            else
            {
                /* If the local force signal is selected, enable force Initialization to trigger FORCE_OUT event */
                if (0U == FlexPwm_Ip_GetForceOutputSource(Base, SubIndex))
                {
                    FlexPwm_Ip_SetForceInitHw(Base, SubIndex, 1U);
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_54();
}

/*!
* @brief      Function Name : FlexPwm_Ip_UnMaskOutputChannels
* @details    This function shall un-mask the output of the channels, then channels shall operate normally.
*
* @param[in]  Instance      Instance number of the FlexPwm module.
* @param[in]  ChannelsMask  Bits mask will be cleared to unmask corresponding channels.
*                           Corresponding bits with un-masked channels are shown as bellow:
*                                       ----- --------- -----------
*                                      | Bit | Channel | Submodule |
*                                       ----- --------- -----------
*                                      |  0  |         |     0     |
*                                       -----           -----------
*                                      |  1  |         |     1     |
*                                       -----           -----------
*                                      |  2  |    X    |     2     |
*                                       -----           -----------
*                                      |  3  |         |     3     |
*                                       ----- --------- -----------
*                                      |  4  |         |     0     |
*                                       -----           -----------
*                                      |  5  |         |     1     |
*                                       -----           -----------
*                                      |  6  |    B    |     2     |
*                                       -----           -----------
*                                      |  7  |         |     3     |
*                                       ----- --------- -----------
*                                      |  8  |         |     0     |
*                                       -----           -----------
*                                      |  9  |         |     1     |
*                                       -----           -----------
*                                      |  10 |    A    |     2     |
*                                       -----           -----------
*                                      |  11 |         |     3     |
*                                       ----- --------- -----------
* @param[in]  UpdateType    The update is immediate or wait for a FORCE_OUT event.
*                           TRUE     Update immediately
*                           FALSE    Wait for a trigger event
*
* @return     void
* @implements FlexPwm_Ip_UnMaskOutputChannels_Activity
*/
void FlexPwm_Ip_UnMaskOutputChannels(uint8   Instance,
                                     uint16  ChannelsMask,
                                     boolean UpdateType
                                    )
{
    FlexPwm_Ip_HwAddrType *const Base  = FlexPwm_Ip_aBasePtr[Instance];
    uint8  UpdateMaskValue             = 0U;
    uint8  SubIndex                    = 0U;
    uint16 IsSubModuleSelected         = 0U;
    uint16 Submodule0IndexsInMask      = ((uint16)1U << FLEXPWM_MASK_MASKX_SHIFT) | ((uint16)1U << FLEXPWM_MASK_MASKA_SHIFT) | ((uint16)1U << FLEXPWM_MASK_MASKB_SHIFT);
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(0xFFFU >= ChannelsMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_55();

    FlexPwm_Ip_ClearOutmaskReg(Base, ChannelsMask);
    for (SubIndex = 0; SubIndex < FLEXPWM_IP_SUBMODULE_COUNT_U8; SubIndex++)
    {
        IsSubModuleSelected = (uint16)(Submodule0IndexsInMask << SubIndex) & ChannelsMask;
        /* Check if a submodule's selected in the mask */
        if (0U != IsSubModuleSelected)
        {
            /* If the type of update is immediate */
            if (TRUE == UpdateType)
            {
                UpdateMaskValue |= (1U << SubIndex);
                FlexPwm_Ip_SetUpdateOutputMaskType(Base, UpdateMaskValue);
            }
            else
            {
                /* If the local force signal is selected, enable force Initialization to trigger FORCE_OUT event */
                if (0U == FlexPwm_Ip_GetForceOutputSource(Base, SubIndex))
                {
                    FlexPwm_Ip_SetForceInitHw(Base, SubIndex, 1U);
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_55();
}

 /*!
 * @brief      Enable interrupts for the FlexPWM module.
 * @details    This function will enable the interrupts for each SubModule
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  IntType
 * @param[in]  InterruptMask
 *
 * @return     void
 * @implements FlexPwm_Ip_EnableInterrupt_Activity
 */
void FlexPwm_Ip_EnableInterrupt(uint8 Instance, uint8 SubModule, FlexPwm_Ip_InterruptTypes IntType, uint8 InterruptMask)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
    DevAssert(FLEXPWM_IP_DISABLE_INT != IntType);
    DevAssert(0x20 > InterruptMask);
    DevAssert(0x00 < InterruptMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_56();

    switch (IntType)
    {
        case FLEXPWM_IP_RELOAD_INT:
            FlexPwm_Ip_ClearInterruptReloadFlagHw(Base, SubModule);
            FlexPwm_Ip_SetReloadIntHw(Base, SubModule, 1U);
            break;
        case FLEXPWM_IP_COMPARE_INT:
            FlexPwm_Ip_ClearInterruptCmpFlagHw(Base, SubModule, InterruptMask);
            FlexPwm_Ip_SetCompareIntHw(Base, SubModule, InterruptMask);
            break;
        default:
            /* Do Nothing */
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_56();

    (void)InterruptMask;
}

 /*!
 * @brief      Disable interrupts for the FlexPWM module.
 * @details    This function will disable the interrupts for each SubModule
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  IntType
 * @param[in]  InterruptMask
 *
 * @return     void
 * @implements FlexPwm_Ip_DisableInterrupt_Activity
 */
void FlexPwm_Ip_DisableInterrupt(uint8 Instance, uint8 SubModule, FlexPwm_Ip_InterruptTypes IntType, uint8 InterruptMask)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
    DevAssert(0x20 > InterruptMask);
    DevAssert(0x00 < InterruptMask);
    DevAssert(FLEXPWM_IP_DISABLE_INT != IntType);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_57();

    switch (IntType)
    {
        case FLEXPWM_IP_RELOAD_INT:
            FlexPwm_Ip_SetReloadIntHw(Base, SubModule, 0U);
            break;
        case FLEXPWM_IP_COMPARE_INT:
            FlexPwm_Ip_ClearCompareIntHw(Base, SubModule, InterruptMask);
            break;
        default:
            /* Do Nothing */
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_57();

    (void)InterruptMask;
}

 /*!
 * @brief      FlexPwm_Ip_ClearInterruptFlag
 * @details    Clears the interrupt flags based on the mask provided.
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  IntType
 * @param[in]  IntFlagMask
 *
 * @return     void
 * @implements FlexPwm_Ip_ClearInterruptFlag_Activity
 */
void FlexPwm_Ip_ClearInterruptFlag(uint8 Instance, uint8 SubModule, FlexPwm_Ip_InterruptTypes IntType, uint8 IntFlagMask)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
    DevAssert(0x20 > IntFlagMask);
    DevAssert(0x00 < IntFlagMask);
    DevAssert(FLEXPWM_IP_DISABLE_INT != IntType);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_58();

    switch (IntType)
    {
        case FLEXPWM_IP_RELOAD_INT:
            FlexPwm_Ip_ClearInterruptReloadFlagHw(Base, SubModule);
            break;
        case FLEXPWM_IP_COMPARE_INT:
            FlexPwm_Ip_ClearInterruptCmpFlagHw(Base, SubModule, IntFlagMask);
            break;
        default:
            /* Do Nothing */
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_58();

    (void)IntFlagMask;
}

 /*!
 * @brief      Set FlexPWM trigger command.
 * @details    This function will load the effective values in the modules registers based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModuleMask      SubModule Mask
 * @param[in]  LoadValueTiming    Select the timing for loading the buffered registers in the submodule
 *                                  TRUE   Update immediately
 *                                  FALSE  Next Pwm reload
 * @return     void
 * @implements FlexPwm_Ip_LoadValue_Activity
 */
void FlexPwm_Ip_LoadValue(uint8 Instance, uint8 SubModuleMask, boolean LoadValueTiming)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
    uint8 SubIndex = 0U;
    uint8 SubModuleId = 0U;
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(0x10 > SubModuleMask);
    DevAssert(0x00 < SubModuleMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_59();

    for (SubIndex = 0; SubIndex < FLEXPWM_IP_SUBMODULE_COUNT_U8; SubIndex++)
    {
        SubModuleId = (uint8)(1U << SubIndex) & SubModuleMask;
        if (0U != SubModuleId)
        {
            FlexPwm_Ip_SetLoadModeHw(Base, SubIndex, (LoadValueTiming == FALSE) ? 0U : 1U);
        }
    }
    /* Set the corresponding bit so that the specific LDOK bits are cleared */
    FlexPwm_Ip_ClearLoadOkayHw(Base, SubModuleMask);
    /* Set the corresponding bit so that the new values are loaded */
    FlexPwm_Ip_SetLoadOkayHw(Base, SubModuleMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_59();
}

 /*!
 * @brief      Clear FlexPWM trigger command.
 * @details    This function will clear load the effective values in the modules registers based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModuleMask      SubModule Mask
 *
 * @return     void
 * @implements FlexPwm_Ip_ClearLoadValue_Activity
 */
void FlexPwm_Ip_ClearLoadValue(uint8 Instance, uint8 SubModuleMask)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(0x10 > SubModuleMask);
    DevAssert(0x00 < SubModuleMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_60();

    /* Set the corresponding bit so that the specific LDOK bits are cleared */
    FlexPwm_Ip_ClearLoadOkayHw(Base, SubModuleMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_60();
}

  /*!
 * @brief      Start FlexPWM counter.
 * @details    This function will start the PWM subModule counters based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModuleMask      SubModule Mask
 *
 * @return     void
 * @implements FlexPwm_Ip_CounterStart_Activity
 */
void FlexPwm_Ip_CounterStart(uint8 Instance, uint8 SubModuleMask)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(0x10 > SubModuleMask);
    DevAssert(0x00 < SubModuleMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_61();

    /* Start FlexPWM counter. */
    FlexPwm_Ip_StartCounterHw(Base, SubModuleMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_61();
}

 /*!
 * @brief      Stop FlexPWM counter.
 * @details    This function will stop the PWM subModule counters based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModuleMask      SubModule Mask
 *
 * @return     void
 * @implements FlexPwm_Ip_CounterStop_Activity
 */
void FlexPwm_Ip_CounterStop(uint8 Instance, uint8 SubModuleMask)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(0x10 > SubModuleMask);
    DevAssert(0x00 < SubModuleMask);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_62();

    /* Stop FlexPWM counter. */
    FlexPwm_Ip_StopCounterHw(Base, SubModuleMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_62();
}

 /*!
 * @brief      FlexPwm_Ip_SetPhaseShift
 * @details    Set Phase shift for each channels
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  ChannelType
 * @param[in]  PhaseShiftVal
 *
 * @return     void
 * @implements FlexPwm_Ip_SetPhaseShift_Activity
 */
void FlexPwm_Ip_SetPhaseShift(uint8 Instance, uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelType, uint16 PhaseShiftVal)
{
    uint8 UniqueSub = (uint8)0U;
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
    DevAssert(FLEXPWM_IP_PWMX != ChannelType);
    DevAssert(FLEXPWM_IP_PHASE_SHIFTED == FlexPwm_Ip_aSignalPwm[Instance][SubModule]);
    DevAssert(PhaseShiftVal < FlexPwm_Ip_aPeriod[Instance][SubModule]);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_63();

    switch(ChannelType)
    {
        case FLEXPWM_IP_PWMA:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);
            FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] = PhaseShiftVal;
            FlexPwm_Ip_SetupDutyChannelA(Instance, SubModule, FLEXPWM_IP_PHASE_SHIFTED, FlexPwm_Ip_aDutyCycle[Instance][UniqueSub]);
            break;
        case FLEXPWM_IP_PWMB:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 2U);
            FlexPwm_Ip_aPhaseShift[Instance][UniqueSub] = PhaseShiftVal;
            FlexPwm_Ip_SetupDutyChannelB(Instance, SubModule, FLEXPWM_IP_PHASE_SHIFTED, FlexPwm_Ip_aDutyCycle[Instance][UniqueSub]);
            break;
        default:
            /* Do Nothing */
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_63();
}

/*!
 * @brief Update the value used for the dead time logic in terms of clock cycles.
 *
 * @param[in]  Instance        Instance number of the FlexPwm module.
 * @param[in]  SubModule       SubModule number of the FlexPwm module.
 * @param[in]  DeadCountType   Select Dead Time Count
 * @param[in]  DeadCountVal    Dead Time Value
 *
 * @return void
 * @implements FlexPwm_Ip_SetDeadTime_Activity
 */
void FlexPwm_Ip_SetDeadTime(uint8 Instance, uint8 SubModule, FlexPwm_Ip_DeadTimeCountTypes DeadCountType, uint16 DeadCountVal)
{
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];

#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    uint8 UniqueSub = (uint8)0U;
    /* Deadtime operation applies only to complementary channel operation, only channel A can be configured when the complementary feature's used */
    UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);

    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
    DevAssert(FLEXPWM_IP_SUBMODULE_COUNT_U8 > SubModule);
    DevAssert(0x800U > DeadCountVal);

    if (FLEXPWM_IP_DEADTIME_COUNT_0 == DeadCountType)
    {
        DevAssert(FlexPwm_Ip_aDutyCycle[Instance][UniqueSub] > DeadCountVal);
    }
    else
    {
        DevAssert(FlexPwm_Ip_aPeriod[Instance][SubModule] > (DeadCountVal + FlexPwm_Ip_aDutyCycle[Instance][UniqueSub]));
    }
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_64();

    FlexPwm_Ip_SetDeadTimeHw(Base, SubModule, DeadCountType, DeadCountVal);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_64();
}

/*!
 * @brief   : This function set the value of the prescaler on FlexPwm instance.
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  InstanceCfg       Pointer to the FlexPwm instance configuration structure.
 * @param[in]  PrescalerMode     Type of the prescaler to be selected (primary or alternate).
 *
 * @return void
 * @implements FlexPwm_Ip_SetClockPs_Activity
 */
void FlexPwm_Ip_SetClockPs(uint8 Instance,
                           const FlexPwm_Ip_InstanceCfgTypes * InstanceCfg,
                           FlexPwm_Ip_PrescalerModeTypes PrescalerMode
                          )
{
#if (FLEXPWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FLEXPWM_IP_INSTANCE_COUNT_U8 > Instance);
#endif
    uint8 SubIndex = 0;
    FlexPwm_Ip_HwAddrType *const Base = FlexPwm_Ip_aBasePtr[Instance];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_65();

    /* Configure all subModule in the used Instance */
    for (SubIndex = 0; SubIndex < InstanceCfg->NumSubModuleCfg; SubIndex++)
    {
        /* Set the LDMOD to 1 to Buffered registers of this submodule are loaded and take effect immediately upon LDOK being set. */
        FlexPwm_Ip_SetLoadModeHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, 1U);
        /* Selects the divide ratio of the PWM clock frequency. */
        if(FLEXPWM_IP_PRIMARY_PRESCALER == PrescalerMode)
        {
            FlexPwm_Ip_SetPrescalerHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, InstanceCfg->SubModuleCfgArray[SubIndex]->Prescaler);
        }
        else
        {
            FlexPwm_Ip_SetPrescalerHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, InstanceCfg->SubModuleCfgArray[SubIndex]->PrescalerAlt);
        }
        /* Set LDOK bit to update prescaler immediately */
        FlexPwm_Ip_SetLoadOkayHw(Base, 1U << InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId);
        /* Set the LDMOD to 0 Buffered registers of this submodule are loaded and take effect at the next PWM reload if LDOK is set. */
        FlexPwm_Ip_SetLoadModeHw(Base, InstanceCfg->SubModuleCfgArray[SubIndex]->SubModuleId, 0U);
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_65();
}


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* (FLEXPWM_IP_AVAILABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
