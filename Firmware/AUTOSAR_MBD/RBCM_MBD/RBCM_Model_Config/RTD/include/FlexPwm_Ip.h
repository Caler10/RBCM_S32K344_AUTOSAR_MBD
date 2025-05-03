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

#ifndef FLEXPWM_IP_H
#define FLEXPWM_IP_H

/**
*   @file       FlexPwm_Ip.h
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
#include "FlexPwm_Ip_Cfg.h"
#include "FlexPwm_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXPWM_IP_VENDOR_ID                       43
#define FLEXPWM_IP_MODULE_ID                       121
#define FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION        4
#define FLEXPWM_IP_AR_RELEASE_MINOR_VERSION        7
#define FLEXPWM_IP_AR_RELEASE_REVISION_VERSION     0
#define FLEXPWM_IP_SW_MAJOR_VERSION                5
#define FLEXPWM_IP_SW_MINOR_VERSION                0
#define FLEXPWM_IP_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of FlexPwm_Ip.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and FlexPwm_Ip_Cfg header file are of the same vendor */
#if (FLEXPWM_IP_VENDOR_ID != FLEXPWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Cfg header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Cfg header file are of the same software version */
#if ((FLEXPWM_IP_SW_MAJOR_VERSION != FLEXPWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_SW_MINOR_VERSION != FLEXPWM_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_SW_PATCH_VERSION != FLEXPWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same vendor */
#if (FLEXPWM_IP_VENDOR_ID != FLEXPWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip.h and FlexPwm_Ip_Types.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip.h and FlexPwm_Ip_Types.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same software version */
#if ((FLEXPWM_IP_SW_MAJOR_VERSION != FLEXPWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_SW_MINOR_VERSION != FLEXPWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_SW_PATCH_VERSION != FLEXPWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip.h and FlexPwm_Ip_Types.h are different."
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

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (FLEXPWM_IP_AVAILABLE == STD_ON)

#if (FLEXPWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/*! @brief Arrays for irq fault notifications */
extern FlexPwm_Ip_FaultCallbackType FlexPwm_Ip_aFaultIrqCallback[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_FAULT_CHANNELS_NO_U8];

/*! @brief Arrays for irq channels notifications */
extern FlexPwm_Ip_NotificationType FlexPwm_Ip_aIrqCallback[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];

/*! @brief Array holding the state of all FlexPWM submodules */
extern FlexPwm_Ip_StateTypes FlexPwm_Ip_aSubModuleSate[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

/*! @brief Array holding the state of all FlexPWM instances */
extern FlexPwm_Ip_StateTypes FlexPwm_Ip_aInstanceSate[FLEXPWM_IP_INSTANCE_COUNT_U8];

/*! @brief Arrays to store the duty cycle values for each SubModules */
extern uint16 FlexPwm_Ip_aDutyCycle[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];

/*! @brief Arrays to store the period values for each SubModules */
extern uint16 FlexPwm_Ip_aPeriod[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_SUBMODULE_COUNT_U8];

#if (FLEXPWM_IP_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

#endif /* FLEXPWM_IP_AVAILABLE */

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (FLEXPWM_IP_AVAILABLE == STD_ON)

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
* @brief        This function initializes an instance of the FlexPWM module
* @details      This function will initialize with default values all FlexPWM submodule registers.
*               Will loop through all FlexPWM channels in the configuration structure and will
*               setup required submodules for each channel
*
* @param[in]    Instance       Instance number of the FlexPwm module.
* @param[in]    InstanceCfg    Pointer to FlexPWM instance configuration structure
*
* @return       void
*
*/
void FlexPwm_Ip_Init(uint8 Instance, const FlexPwm_Ip_InstanceCfgTypes * InstanceCfg);

/*!
 * @brief      De-initialize an instance of the FlexPWM module
 * @details    The function De-initializes an instance of the FlexPWM module restoring all the
 *             registers to their reset values.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  InstanceCfg   Pointer to FlexPWM instance configuration structure
 * @return     void
 */
void FlexPwm_Ip_DeInit(uint8 Instance);

/**
 * @brief      Update pwm pulse width.
 * @details    This function will update the PWM signal pulse width.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 * @param[in]  ChannelType   FlexPWM channel Type options.
 * @param[in]  PwmType       Pwm Signal Type options.
 * @param[in]  DutyCycle     Duty cycle value in ticks
 *
 * @return     void
 */
void FlexPwm_Ip_UpdateDutyCycle(uint8 Instance, uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelType, uint16 DutyCycle);

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
 */
void FlexPwm_Ip_FastUpdateDutyCycle(uint8 Instance, uint8 SubModule, uint8 NumberOfChannels,
                                    const uint16 * PwmPulseWidth, const FlexPwm_Ip_ChannelTypes * ChannelType
                                   );

/**
 * @brief      Update pwm period.
 * @details    This function will update the PWM signal period.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 * @param[in]  Period        Period value in ticks
 *
 * @return     void
 */
void FlexPwm_Ip_UpdatePeriod(uint8 Instance, uint8 SubModule, uint16 Period);

/**
 * @brief      Function Name : FlexPwm_Ip_OverwriteOutputChannels
 * @details    This function change the output value for a channel.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 * @param[in]  ChannelType   
 * @param[in]  OutputState   
 *
 * @return     void
 */
void FlexPwm_Ip_OverwriteOutputChannels(uint8 Instance, uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelType, FlexPwm_Ip_OutputStateTypes OutputState);

/*!
* @brief      Function Name : FlexPwm_Ip_MaskOutputChannels
* @details    This function shall mask the output of the channels and at match events shall be ignored by the masked channels.
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
*/
void FlexPwm_Ip_MaskOutputChannels(uint8 Instance, uint16 ChannelsMask, boolean UpdateType);

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
*/
void FlexPwm_Ip_UnMaskOutputChannels(uint8 Instance, uint16 ChannelsMask, boolean UpdateType);

/**
 * @brief      Enable interrupts for the FlexPWM module.
 * @details    This function will enable the interrupts for each SubModule
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  InterruptMask     
 *
 * @return     void
 */
void FlexPwm_Ip_EnableInterrupt(uint8 Instance, uint8 SubModule, FlexPwm_Ip_InterruptTypes IntType, uint8 InterruptMask);

/**
 * @brief      Disable interrupts for the FlexPWM module.
 * @details    This function will disable the interrupts for each SubModule
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  InterruptMask     
 *
 * @return     void
 */
void FlexPwm_Ip_DisableInterrupt(uint8 Instance, uint8 SubModule, FlexPwm_Ip_InterruptTypes IntType, uint8 InterruptMask);

/**
 * @brief      FlexPwm_Ip_ClearInterruptFlag
 * @details    Clears the interrupt flags based on the mask provided.
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  IntType     
 * @param[in]  IntFlagMask     
 *
 * @return     void
 */
void FlexPwm_Ip_ClearInterruptFlag(uint8 Instance, uint8 SubModule, FlexPwm_Ip_InterruptTypes IntType, uint8 IntFlagMask);

/**
 * @brief      Set FlexPWM trigger command.
 * @details    This function will load the effective values in the modules registers based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModule          SubModule number of the FlexPwm module.
 * @param[in]  LoadValueTiming    Select the timing for loading the buffered registers in the submodule
 *                                  TRUE   Update immediately
 *                                  FALSE  Next Pwm reload
 *
 * @return     void
 */
void FlexPwm_Ip_LoadValue(uint8 Instance, uint8 SubModuleMask, boolean LoadValueTiming);

/**
 * @brief      Clear FlexPWM trigger command.
 * @details    This function will clear load the effective values in the modules registers based
 * on the provided mask
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  SubModule     SubModule number of the FlexPwm module.
 *
 * @return     void
 */
void FlexPwm_Ip_ClearLoadValue(uint8 Instance, uint8 SubModuleMask);

 /**
 * @brief      Start FlexPWM counter.
 * @details    This function will start the PWM subModule counters based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModuleMask      SubModule Mask
 *
 * @return     void
 */
void FlexPwm_Ip_CounterStart(uint8 Instance, uint8 SubModuleMask);

/**
 * @brief      Stop FlexPWM counter.
 * @details    This function will stop the PWM subModule counters based
 * on the provided mask
 *
 * @param[in]  Instance           Instance number of the FlexPwm module.
 * @param[in]  SubModuleMask      SubModule Mask
 *
 * @return     void
 */
void FlexPwm_Ip_CounterStop(uint8 Instance, uint8 SubModuleMask);

/**
 * @brief      FlexPwm_Ip_SetPhaseShift
 * @details    Set Phase shift for each channels
 *
 * @param[in]  Instance          Instance number of the FlexPwm module.
 * @param[in]  SubModule         SubModule number of the FlexPwm module.
 * @param[in]  ChannelType     
 * @param[in]  PhaseShiftVal     
 *
 * @return     void
 */
void FlexPwm_Ip_SetPhaseShift(uint8 Instance, uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelType, uint16 PhaseShiftVal);

/*!
 * @brief Update the value used for the dead time logic in terms of clock cycles.
 *
 * @param[in]  Instance        Instance number of the FlexPwm module.
 * @param[in]  SubModule       SubModule number of the FlexPwm module.
 * @param[in]  DeadCountType   Select Dead Time Count
 * @param[in]  DeadCountVal    Dead Time Value
 *
 * @return void
 */

void FlexPwm_Ip_SetDeadTime(uint8 Instance, uint8 SubModule, FlexPwm_Ip_DeadTimeCountTypes DeadCountType, uint16 DeadCountVal);

/*!
 * @brief      This function set the value of the prescaler on FlexPwm instace.
 *
 * @param[in]  Instance      Instance number of the FlexPwm module.
 * @param[in]  InstanceCfg   Pointer to FlexPWM instance configuration structure
 * @param[in]  Value         Prescaler Value
 * @return     void
 */
void FlexPwm_Ip_SetClockPs(uint8 Instance, const FlexPwm_Ip_InstanceCfgTypes * InstanceCfg, FlexPwm_Ip_PrescalerModeTypes PrescalerMode);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* FLEXPWM_IP_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP_H */
