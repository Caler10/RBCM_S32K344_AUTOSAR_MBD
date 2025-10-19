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

#ifndef PWM_IPW_H
#define PWM_IPW_H

/**
*   @file       Pwm_Ipw.h
*
*   @internal
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Include standard types */
#include "Std_Types.h"

/* Include IPW header files */
#include "Pwm_Ipw_Cfg.h"
#include "Pwm_Ipw_Types.h"
#include "Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_IPW_VENDOR_ID                         43
#define PWM_IPW_MODULE_ID                         121
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION          4
#define PWM_IPW_AR_RELEASE_MINOR_VERSION          7
#define PWM_IPW_AR_RELEASE_REVISION_VERSION       0
#define PWM_IPW_SW_MAJOR_VERSION                  5
#define PWM_IPW_SW_MINOR_VERSION                  0
#define PWM_IPW_SW_PATCH_VERSION                  0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Pwm_Ipw.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Pwm_Ipw_Cfg header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_IPW_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.h and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if header file and Pwm_Ipw_Cfg header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.h and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if header file and Pwm_Ipw_Cfg header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_IPW_CFG_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_IPW_CFG_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_IPW_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.h and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_VENDOR_ID)
    #error "Pwm_Ipw.h and Pwm.h have different vendor ids"
#endif

/* Check if header file and Pwm header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.h and Pwm.h are different"
#endif

/* Check if header file and Pwm header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.h and Pwm.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
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
#if (PWM_ETPU_USED == STD_ON)
#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/** @brief Array to save the instance structures for all Etpu PWM channels */
extern Etpu_Pwm_Ip_InstanceType Pwm_Ipw_aEtpuInstance[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];
/** @brief Array to save the configuration structures for all Etpu PWM channels */
extern Etpu_Pwm_Ip_ConfigType Pwm_Ipw_aEtpuConfig[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"
#endif /* (PWM_ETPU_USED == STD_ON) */

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
/**
* @brief        Pwm_Ipw_Init
* @details      This function call the supported IP initialization functions.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_Init(const Pwm_IpwChannelConfigType * const IpConfig);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_InitInstance
* @details      This Pwm_Ipw_InitInstance is called once for each channel in the used configuration.
*               It determines the type of the HW channel (e.g. FlexPwm,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_InitInstance(const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_HW_INSTANCE_USED */

#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        Pwm_Ipw_DeInit
* @details      This function call the supported IP de-initialization functions.
*
* @param[in]    IpConfig            Pointer to PWM top configuration structure
* @param[in]    ChannelIdleState    The state of the channel output in idle mode
*
* @return       void
*
*/
void Pwm_Ipw_DeInit(const Pwm_IpwChannelConfigType * const IpConfig, Pwm_OutputStateType ChannelIdleState);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_DeInitInstance
* @details      This function call the supported IP de-initialization instances.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_DeInitInstance(const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_HW_INSTANCE_USED */
#endif /* PWM_DE_INIT_API */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetDutyCycle
* @details      This function will call SetDutyCycle function for the corresponding IP of PwmChannel
*
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        The duty cycle could not be set
*               E_OK            The duty cycle is set to the new value
*
*/
Std_ReturnType Pwm_Ipw_SetDutyCycle(uint16                         DutyCycle,
                                    const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_DUTY_CYCLE_API */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetPeriodAndDuty
* @details      This function will call SetPeriodAndDuty function for the corresponding IP of PwmChannel
*
* @param[in]    Period         Period value for this channel
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        The period and duty cycle could not be set
*               E_OK            The period and duty cycle is set to the new value
*/
Std_ReturnType Pwm_Ipw_SetPeriodAndDuty(Pwm_Ipw_PeriodType              Period,
                                        uint16                          DutyCycle,
                                        const Pwm_IpwChannelConfigType *const IpConfig);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetOutputToIdle
* @details      This function will call SetOutputToIdle function for the corresponding IP of PwmChannel
*
* @param[in]    IdleState      The Level that the hw channel must drive on the ouput pin
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetOutputToIdle(const Pwm_OutputStateType IdleState, const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        Pwm_Ipw_GetOutputState
* @details      This function will call GetOutputState function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Pwm_OutputStateType
*
*/
Pwm_OutputStateType Pwm_Ipw_GetOutputState(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_GET_OUTPUT_STATE_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_DisableNotification
* @details      This function will call DisableNotification function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_DisableNotification(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_EnableNotification
* @details      This function will call EnableNotification function for the corresponding IP of PwmChannel
*
* @param[in]    Notification   Notification edge type to be enabled
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_EnableNotification(Pwm_EdgeNotificationType       Notification,
                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        Pwm_Ipw_GetChannelState
* @details      This function will call GetChannelState function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       uint16
*
*/
uint16 Pwm_Ipw_GetChannelState(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_GET_CHANNEL_STATE_API */

#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockModeChannel
* @details      This function will call SetClockMode function of all configured hardware channels.
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockModeChannel(Pwm_PrescalerType              Prescaler,
                                 const Pwm_IpwChannelConfigType * const IpConfig);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockModeInstance
* @details      This function will call SetClockMode function of all configured hardware eMIOS modules.
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM instance configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockModeInstance(Pwm_PrescalerType              Prescaler,
                                  const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_HW_INSTANCE_USED */                                 
#endif /* PWM_SET_CLOCK_MODE_API */

#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetCounterBus
* @details      This function will change the counter bus of PWM channels running.
*
* @param[in]    Bus            eMIOS bus to change to
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetCounterBus(uint32                         Bus,
                           const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_COUNTER_BUS_API */

#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetChannelOutput
* @details      This function is useful to set the state of the PWM pin as requested
*
* @param[in]    State          State of the channel to change to
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetChannelOutput(Pwm_StateType                  State,
                              const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_CHANNEL_OUTPUT_API */

#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Implementation specific function to change the trigger delay
* @details      This function is useful to set the trigger delay in OPWMT mode. If no DET error
*               reported from function Pwm_Ipw_ValidateTriggerMode then the trigger delay for
*               current channel will be set.
*
* @param[in]    TriggerDelay   Delay value for trigger
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetTriggerDelay(Pwm_Ipw_PeriodType                 TriggerDelay,
                             const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_TRIGGER_DELAY_API */

#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief
* @details      This function is used to update the deadtime at runtime for Pwm channels.
*
* @param[in]    DeadTimeTicks   DeadTime value in ticks
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetChannelDeadTime(Pwm_Ipw_PeriodType             DeadTimeTicks,
                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief
* @details      This function shall be used to write a value into UCRegA.
*
* @param[in]    Value           Value to write in register
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateSetUCRegA(Pwm_Ipw_PeriodType            Value,
                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_FAST_UPDATE_API */

#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief
* @details      This function shall be used to write a value into UCRegB.
*
* @param[in]    Value           Value to write in register
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateSetUCRegB(Pwm_Ipw_PeriodType            Value,
                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_FAST_UPDATE_API */

#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief
* @details      This function shall be used to disable output update for selected Emios channels
*
* @param[in]    ModuleId        Pwm hardware module id
* @param[in]    ChannelMask     Bit mask of Emios hardware channels
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateDisableOU(uint8 ModuleId, uint32 ChannelMask);
#endif /* PWM_FAST_UPDATE_API */

#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief
* @details      This function shall be used to enable output update for selected Emios channels
*
* @param[in]    ModuleId         Pwm hardware module id
* @param[in]    ChannelMask      Bit mask of Emios hardware channels
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateEnableOU(uint8 ModuleId, uint32 ChannelMask);
#endif /* PWM_FAST_UPDATE_API */

#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Pwm_Ipw_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShift              Phase shift value (in ticks)
* @param[in]    IpConfig                Pointer to PWM top configuration structure
* @param[in]    SyncUpdate              Update duty and phases shift value synchronization for channels in given module or not
*                                       TRUE    Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                                       FALSE   Set phase shift and duty cycle value immediately
*
* @return       void
*
*/
void Pwm_Ipw_SetDutyPhaseShift(uint16                           DutyCycle,
                               Pwm_Ipw_DutyType                 PhaseShift,
                               const Pwm_IpwChannelConfigType * const IpConfig,
                               boolean                          SyncUpdate);
#endif /*PWM_SET_DUTY_PHASE_SHIFT_API*/

#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SYNC_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SyncUpdate
* @details      This function will allow synchronized loading
*               of the value register.
*
* @param[in]    ModuleId        module Id
*
* @return       void
*
*/
void Pwm_Ipw_SyncUpdate(uint8   ModuleId);
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SYNC_UPDATE_API */

#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SetDutyCycle_NoUpdate
*
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
Std_ReturnType Pwm_Ipw_SetDutyCycle_NoUpdate(uint16                         DutyCycle,
                                             const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_DUTY_CYCLE_NO_UPDATE_API */


#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SetPeriodAndDuty_NoUpdate
*
* @param[in]    Period         Period value for this channel
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPeriodAndDuty_NoUpdate(Pwm_Ipw_PeriodType             Period,
                                       uint16                         DutyCycle,
                                       const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */

#if ((PWM_GET_OUTPUT_STATE_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
/**
* @brief            Pwm_Ipw_ValidateGetOutputState
* @details          This function will check the validation when calling the Pwm_GetOutputState api.
*
* @param[in]        IpConfig        Pointer to PWM top configuration structure
*
* @retVal           RetVal          E_NOT_OK  Get output state is not valid
                                    E_OK      Get output state is valid
*/
Std_ReturnType Pwm_Ipw_ValidateGetOutputState(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* (PWM_GET_OUTPUT_STATE_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) */
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SYNC_UPDATE_API == STD_ON) || (PWM_FAST_UPDATE_API == STD_ON) || (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)))
/**
* @brief        Pwm_Ipw_ValidateModuleId
* @details      Validate the module id.
*               In order to be valid, the module id should less than number of module that supported
*
* @param[in]    ModuleId        The Id of the ipv module
* @param[in]    ServiceId       Id of the service calling this function
*
* @return       Std_ReturnType
*               E_NOT_OK        The ModuleId is invalid
*               E_OK            The ModuleId is valid
*
*/     
Std_ReturnType  Pwm_Ipw_ValidateModuleId(uint8 ModuleId, uint8 ServiceId);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateNotification
* @details      This function will check validate of edge notification type with polarity
*
* @param[in]    Notification   Notification edge type to check if available
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK       Notification handler is not valid
*               E_OK           Notification handler is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateNotification(Pwm_EdgeNotificationType       Notification,
                                            const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SYNC_UPDATE_API == STD_ON)))
/**
* @brief        Pwm_Ipw_ValidateUpdateSynchronous
* @details      This function will check given channel with synchronization supported
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK   synchronization is not supported this channel
*               E_OK       synchronization is supported this channel
*
*/
Std_ReturnType Pwm_Ipw_ValidateUpdateSynchronous(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API || PWM_SYNC_UPDATE_API) */

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_TRIGGER_DELAY_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateTriggerMode
* @details      This function will check validate operation mode of current channel to use
*               trigger delay feature.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Current channel mode is invalid
*               E_OK            Current channel mode is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateTriggerMode(const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON))
/**
* @brief        Pwm_ValidateDeadTime
* @details      This function will check validate operation mode of current channel to use
*               trigger delay feature.
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Current channel mode is invalid
*               E_OK            Current channel mode is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateDeadTime(const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateSetDutyPhaseShiftParams
* @details      This function will check phase shift and duty cycle value
*
* @param[in]    PhaseShift   Phase shift value
* @param[in]    DutyCycle    Duty Cycle value
* @param[in]    IpConfig     Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK    Phase shift or duty cycle value is invalid
*               E_OK        Phase shift or duty cycle is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetDutyPhaseShiftParams(Pwm_Ipw_DutyType PhaseShift,
                                                       uint16 DutyCycle,
                                                       const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON))
/**
* @brief        Pwm_ValidateDeadTime
* @details      This function will check validate operation mode of current channel to use
*               trigger delay feature.
*
* @param[in]    DeadTimeTicks   DeadTime value in ticks
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Current channel mode is invalid
*               E_OK            Current channel mode is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateParamDeadTime(Pwm_Ipw_PeriodType               DeadTimeTicks,
                                             const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_COUNTER_BUS_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateCounterBus
* @details      This function will validate of counter bus
*
* @param[in]    Bus         Counter bus ID
* @param[in]    IpConfig    Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK    The selected bus is invalid
*               E_OK        The selected bus is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateCounterBus(uint32                         Bus,
                                          const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
/**
* @brief        Validate the set channel output feature.
*               In order to be valid, the set channel output feature only supported for eMIOS.
*
* @param[in]    State           The state of output
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType  Validity of notification handler
*                   E_OK            set channel output parameter is valid
*                   E_NOT_OK        set channel output parameter is not valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetChannelOutput(Pwm_StateType                          State,
                                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateSetPhaseShift
* @details      This function will check given channel with phase shift supported
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Phase shift is not supported this channel
*               E_OK            Phase shift is supported this channel
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetPhaseShift(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && PWM_SET_DUTY_PHASE_SHIFT_API */

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) ||(PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)))

/**
* @brief        Pwm_Ipw_GetMaxPeriodValue
* @details      This function will calculate the maximum period value supported by hardware
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       uint32
*
*/
uint32 Pwm_Ipw_GetMaxPeriodValue(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && (PWM_SET_PERIOD_AND_DUTY_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API) */

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_TRIGGER_DELAY_API == STD_ON))
/**
* @brief        Pwm_Ipw_GetCurrentPeriodValue
* @details      This function will calculate the period value of current channel
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Pwm_Ipw_PeriodType  Period value of current channel
*
*/
Pwm_Ipw_PeriodType Pwm_Ipw_GetCurrentPeriodValue(const Pwm_IpwChannelConfigType * const IpConfig);
#endif

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_ValidateIdleState
* @details      This function will call ValidateIdleState function of all configured hardware eMIOS modules
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        The Idle state is not ready
*               E_OK            The Idle state is ready
*
*/
Std_ReturnType Pwm_Ipw_ValidateIdleState(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_POWER_STATE_SUPPORTED */

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_SetPowerStateChannel
* @details      This function will call SetPowerState function of all configured hardware channels.
*
* @param[in]    PowerState     Target power mode
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPowerStateChannel(Pwm_PowerStateType                  PowerState,
                                  const Pwm_IpwChannelConfigType * const IpConfig);
#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_SetPowerStateInstance
* @details      This function will call SetPowerState function of all configured hardware modules
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
* @param[in]    PowerState     Target power mode
*
* @return       void
*
*/
void Pwm_Ipw_SetPowerStateInstance(const Pwm_IpwInstanceConfigType * const IpConfig,
                                   Pwm_PowerStateType       PowerState);
#endif /* PWM_HW_INSTANCE_USED */
#endif /* PWM_POWER_STATE_SUPPORTED */

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to logic 0 before consideration of the output polarity.
* @details      Corresponding bits with channel will be masked:
*               Bit  0   The ouput mask of channel X - submodule 0
*               Bit  1   The ouput mask of channel X - submodule 1
*               Bit  2   The ouput mask of channel X - submodule 2
*               Bit  3   The ouput mask of channel X - submodule 3
*               Bit  4   The ouput mask of channel B - submodule 0
*               Bit  5   The ouput mask of channel B - submodule 1
*                                  ............
*               Bit  8   The ouput mask of channel A - submodule 0
*                                  ............
*               Bit 11   The ouput mask of channel A - submodule 3
*
* @param[in]    ModuleId      FlexPwm module ID
* @param[in]    ChannelMask   Bits mask will be set to mask corresponding channels
* @param[in]    UpdateType    The update is immediate or wait for a trigger event
*                             TRUE     Update immediately
*                             FALSE    Wait for a trigger event
* @param[in]    IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_MaskOutputs(uint8                             ModuleId,
                         uint16                            ChannelMask,
                         boolean                           UpdateType,
                         const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function puts channels output to normal operation state
* @details      Corresponding bits with channel will be un-masked:
*               Bit  0   The ouput mask of channel X - submodule 0
*               Bit  1   The ouput mask of channel X - submodule 1
*               Bit  2   The ouput mask of channel X - submodule 2
*               Bit  3   The ouput mask of channel X - submodule 3
*               Bit  4   The ouput mask of channel B - submodule 0
*               Bit  5   The ouput mask of channel B - submodule 1
*                                  ............
*               Bit  8   The ouput mask of channel A - submodule 0
*                                  ............
*               Bit 11   The ouput mask of channel A - submodule 3
*
* @param[in]    ModuleId      FlexPwm module ID
* @param[in]    ChannelMask   Bits mask will be cleared to unmask corresponding channels
* @param[in]    UpdateType    The update is immediate or wait for a trigger event
*                             TRUE     Update immediately
*                             FALSE    Wait for a trigger event
* @param[in]    IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_UnMaskOutputs(uint8                             ModuleId,
                           uint16                            ChannelMask,
                           boolean                           UpdateType,
                           const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_IPW_H */
