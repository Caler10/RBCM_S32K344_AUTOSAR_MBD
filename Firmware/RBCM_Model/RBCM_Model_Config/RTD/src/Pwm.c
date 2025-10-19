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
*   @file           Pwm.c
*   @implements     Pwm.c_Artifact
*
*   @addtogroup pwm_driver Pwm Driver
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
#include "Std_Types.h"

#include "Pwm.h"
#include "Pwm_Notif.h"
#include "Pwm_Ipw.h"
#include "SchM_Pwm.h"

#if ((PWM_POWER_STATE_SUPPORTED == STD_ON) || (PWM_DEV_ERROR_DETECT == STD_ON))
    #include "Det.h"
#endif

#if (PWM_MULTIPARTITION_ENABLED == STD_ON)
    #include "OsIf.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_C                         43
#define PWM_AR_RELEASE_MAJOR_VERSION_C          4
#define PWM_AR_RELEASE_MINOR_VERSION_C          7
#define PWM_AR_RELEASE_REVISION_VERSION_C       0
#define PWM_SW_MAJOR_VERSION_C                  5
#define PWM_SW_MINOR_VERSION_C                  0
#define PWM_SW_PATCH_VERSION_C                  0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm.c and Std_Types.h are different."
    #endif

    #if ((PWM_DEV_ERROR_DETECT == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
        /* Check if source file and DET header file are of the same version */
        #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (PWM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Pwm.c and Det.h are different."
        #endif
    #endif

    /* Check if source file and SchM_Pwm.h header file are of the same version */
    #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != SCHM_PWM_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_AR_RELEASE_MINOR_VERSION_C != SCHM_PWM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR version numbers of Pwm.c and SchM_Pwm.h are different."
    #endif

    #if (PWM_MULTIPARTITION_ENABLED == STD_ON)
        /* Check if source file and OsIf header file are of the same version */
        #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (PWM_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Pwm.c and OsIf.h are different."
        #endif
    #endif
#endif

/* Check if source file and PWM header file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Vendor IDs of Pwm.c and Pwm.h are different."
#endif

/* Check if source file and PWM header file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.c and Pwm.h are different."
#endif

/* Check if source file and PWM header file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION)  || \
     (PWM_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION)  || \
     (PWM_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.c and Pwm.h are different."
#endif

/* Check if source file and Pwm_Ipw.h file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_IPW_VENDOR_ID)
    #error "Vendor IDs of Pwm.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw.h file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw.h file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_IPW_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION_C != PWM_IPW_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION_C != PWM_IPW_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_NOTIF_VENDOR_ID)
    #error "Vendor IDs of Pwm.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C    != PWM_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C    != PWM_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION_C != PWM_NOTIF_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION_C != PWM_NOTIF_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.c and Pwm_Notif.h are different."
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if ((PWM_VALIDATE_GLOBAL_CONFIG_CALL  == STD_ON) || (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON))
/**
* @brief        Enumeration containing the possible states of the PWM driver
*/
typedef enum
{
    /** @brief  Pwm driver is not initialized */
    PWM_STATE_UNINIT = 0x00U,
    /** @brief  Pwm driver is initialized and running */
    PWM_STATE_IDLE   = 0x01U
} Pwm_GlobalStateType;
#endif

/**
* @brief        State structure for the PWM driver
*/
typedef struct
{
#if ((PWM_VALIDATE_GLOBAL_CONFIG_CALL  == STD_ON) || (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON))
    /** @brief       Variable storing the current state of the Pwm driver */
    Pwm_GlobalStateType            PwmDriverState;
#endif
    /** @brief        Pointer to the top level configuration structure - valid only when the driver is in the initialized state */
    const Pwm_ConfigType         * PwmConfig;
    /** @brief       Variable storing the current power state of the PWM driver */
    Pwm_PowerStateType             PwmCurrentPowerState;
    /** @brief       Variable storing the target power state of the PWM driver */
    Pwm_PowerStateType             PwmTargetPowerState;
    /** @brief       Array holding all channel configured for this partition */
    const Pwm_ChannelConfigType  * PwmChannelConfigs[PWM_CONFIG_LOGIC_CHANNELS];
    /** @brief       Array holding all channel configured for this partition */
    boolean                        PwmChannelIdleState[PWM_CONFIG_LOGIC_CHANNELS];
} Pwm_DriverStateType;

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (PWM_MULTIPARTITION_ENABLED == STD_ON)
    #define Pwm_GetPartitionId()           (uint32)OsIf_GetUserId()
#else
    #define Pwm_GetPartitionId()           (uint32)0U
#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"


#if (PWM_MULTIPARTITION_ENABLED == STD_ON)
    static Pwm_DriverStateType Pwm_aState[PWM_MAX_PARTITION_NO] = PWM_DRIVER_STATE_INITIALIZATION;
#else
    static Pwm_DriverStateType Pwm_aState[1U] = PWM_DRIVER_STATE_INITIALIZATION;
#endif

#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"



#if (PWM_POWER_STATE_SUPPORTED == STD_ON)

#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/**
* @brief        Variable storing the current power state of the PWM driver
*
*/
static Pwm_PowerStateType Pwm_eCurrentPowerState[PWM_MAX_PARTITION_NO];

/**
* @brief        Variable storing the target power state of the PWM driver
*
*/
static Pwm_PowerStateType Pwm_eTargetPowerState[PWM_MAX_PARTITION_NO];

#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

#endif /* PWM_POWER_STATE_SUPPORTED */

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Pwm_MemMap.h"

#if (PWM_MULTIPARTITION_ENABLED == STD_ON)
extern const Pwm_ConfigType * const Pwm_Config[PWM_MAX_PARTITION_NO];
#else
extern const Pwm_ConfigType Pwm_Config;
#endif

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Pwm_MemMap.h"

#endif /* PWM_PRECOMPILE_SUPPORT */

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE

#include "Pwm_MemMap.h"

#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))
/*=============================================================================================*/
static inline uint8 Pwm_GetPartitionChannelIdx(uint32              PartitionId,
                                               Pwm_ChannelType     ChannelNumber
                                              );
#endif


#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
/*=============================================================================================*/
static Std_ReturnType Pwm_ValidateGlobalConfigCall(uint32   PartitionId,
                                                   uint8    ServiceId
                                                  );


/*=============================================================================================*/
static inline void Pwm_EndValidateGlobalConfigCall(uint32           PartitionId,
                                                   Std_ReturnType   ValidCall,
                                                   uint8            ServiceId
                                                  );
#endif /* PWM_VALIDATE_GLOBAL_CONFIG_CALL */


#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))
/*=============================================================================================*/
static inline Std_ReturnType Pwm_ValidateChannelConfigCall(uint32              PartitionId,
                                                           Pwm_ChannelType     ChannelNumber,
                                                           uint8               ServiceId
                                                          );


/*=============================================================================================*/
static inline void Pwm_EndValidateChannelConfigCall(Pwm_ChannelType     ChannelNumber);
#endif
#endif /* PWM_VALIDATE_CHANNEL_CONFIG_CALL */


/*=============================================================================================*/
#if (PWM_PARAM_CHECK == STD_ON)

/*=============================================================================================*/
static inline Std_ReturnType Pwm_ValidateParamPtrInit(uint32                  PartitionId,
                                                      const Pwm_ConfigType *  ConfigPtr
                                                     );

/*=============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
static inline Std_ReturnType Pwm_ValidateParamDuty(uint16   DutyCycle,
                                                   uint8    ServiceId
                                                  );
#endif


/*=============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
static inline Std_ReturnType Pwm_ValidateParamsPeriodClass(uint32                PartitionId,
                                                           Pwm_ChannelType       ChannelNumber,
                                                           Pwm_ChannelClassType  ChannelClass,
                                                           Pwm_PeriodType        Period,
                                                           uint8                 ServiceId
                                                          );
#endif


/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
static inline Std_ReturnType Pwm_ValidateParamNotification(uint32                      PartitionId,
                                                           Pwm_ChannelType             ChannelNumber,
                                                           Pwm_EdgeNotificationType    Notification
                                                          );
#endif

/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateParamTriggerDelay(uint32           PartitionId,
                                                           Pwm_ChannelType  ChannelNumber,
                                                           Pwm_PeriodType   TriggerDelay
                                                          );
#endif


/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateTriggerDelay(uint32            PartitionId,
                                                      Pwm_ChannelType   ChannelNumber
                                                     );
#endif

/*=============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateDeadTime(uint32           PartitionId,
                                                  Pwm_ChannelType  ChannelNumber
                                                 );


static inline Std_ReturnType Pwm_ValidateParamDeadTime(uint32           PartitionId,
                                                       Pwm_ChannelType  ChannelNumber,
                                                       Pwm_PeriodType   DeadTimeTicks
                                                      );
#endif

/*=============================================================================================*/
#if ((PWM_SYNC_UPDATE_API            == STD_ON) || \
     (PWM_FAST_UPDATE_API            == STD_ON) || \
     (PWM_ENABLE_MASKING_OPERATIONS  == STD_ON))
static inline Std_ReturnType Pwm_ValidateModuleId(uint8 ModuleId,
                                                  uint8 ServiceId
                                                 );
#endif

/*=============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateCounterBus(uint32          PartitionId,
                                                    Pwm_ChannelType ChannelNumber,
                                                    uint32          Bus
                                                   );
#endif


/*=============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateSetChannelOutput(uint32            PartitionId,
                                                          Pwm_ChannelType   ChannelNumber,
                                                          Pwm_StateType     State
                                                         );
#endif

/*=============================================================================================*/
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateParamsDutyPhaseShift(uint32            PartitionId,
                                                              Pwm_DutyType      PhaseShift,
                                                              uint16            DutyCycle,
                                                              Pwm_ChannelType   ChannelNumber,
                                                              uint8             ServiceId
                                                             );
#endif

/*=============================================================================================*/

/*=============================================================================================*/

/*=============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateGetOutputState(uint32            PartitionId,
                                                        Pwm_ChannelType   ChannelNumber
                                                       );
#endif /* (PWM_GET_OUTPUT_STATE_API == STD_ON) */

#endif /* PWM_PARAM_CHECK */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))

static inline uint8 Pwm_GetPartitionChannelIdx(uint32          PartitionId,
                                               Pwm_ChannelType ChannelNumber
                                              )
{
#if (PWM_MULTIPARTITION_ENABLED == STD_ON)
    return (*(Pwm_aState[PartitionId].PwmConfig)->PwmLogicalToPartitionMap)[ChannelNumber];
#else
    /* Avoid compiler warning */
    (void)PartitionId;

    return ChannelNumber;
#endif
}
#endif



/*=============================================================================================*/
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
/**
* @brief        Validate the call of a function impacting the configuration of the entire driver.
* @details      Before executing, a function which changes the configuration of the entire driver
*               shall check if:
*               1. It is not preempting itself
*               2. It is not preempting another function that changes the configuration of the
*                  entire driver
*               3. It is not preempting a function that changes the configuration of one of the
*                  driver's channels
*               In any of the above cases, the function will report an error to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    PartitionId              The number of current partition
* @param[in]    ServiceId           Id of the service calling this function
*
* @return       Std_ReturnType      Call is valid or not
* @retval       E_OK                Caller of the function can continue its execution
* @retval       E_NOT_OK            Caller of the function should drop execution
*
*/
static Std_ReturnType Pwm_ValidateGlobalConfigCall(uint32   PartitionId,
                                                   uint8    ServiceId
                                                  )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    if (PWM_STATE_UNINIT == Pwm_aState[PartitionId].PwmDriverState)
    {
        if (PWM_INIT_ID != ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_UNINIT
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if (PWM_INIT_ID == ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_ALREADY_INITIALIZED
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return RetVal;
}
#endif /* PWM_VALIDATE_GLOBAL_CONFIG_CALL */



/*=============================================================================================*/
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
/**
* @brief        Completes the execution of a function impacting the configuration of the entire driver.
* @details      Performs actions in order to ensure that after it's caller has completed the execution
*               the driver will remain in a state allowing execution of other functions updating the
*               configuration of the entire driver or of a single channel
*
* @param[in]    PartitionId     The number of current partition
* @param[in]    ValidCall  The function call was previously validated
* @param[in]    ServiceId  The service id of the caller function
*
* @return       void
*
*/
static inline void Pwm_EndValidateGlobalConfigCall(uint32           PartitionId,
                                                   Std_ReturnType   ValidCall,
                                                   uint8            ServiceId
                                                  )
{
    /* Change the state of the driver only if the previous call to
    Pwm_ValidateGlobalConfigCall() stated that the API call is valid */
    if ((Std_ReturnType)E_OK == ValidCall)
    {
        if (PWM_DEINIT_ID == ServiceId)
        {
            Pwm_aState[PartitionId].PwmDriverState = PWM_STATE_UNINIT;
        }
        else
        {
            Pwm_aState[PartitionId].PwmDriverState = PWM_STATE_IDLE;
        }
    }
}
#endif /* PWM_VALIDATE_GLOBAL_CONFIG_CALL */



/*=============================================================================================*/
#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))
/**
* @brief        Validate the call of a function impacting the configuration of one of the driver's
* @details      channels. Before executing, a function which changes the configuration of a
*               channel shall check if:
*               1. It is not preempting itself
*               2. It is not preempting a function that changes the configuration of the
*                  entire driver
*               In any of the above cases, the function will report an error to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    PartitionId         The number of current partition
* @param[in]    ChannelNumber  Id of the channel the caller tries to update
* @param[in]    ServiceId      Id of the service calling this function
*
* @return       Std_ReturnType  Call is valid or not
* @retval       E_OK            Caller of the function can continue its execution
* @retval       E_NOT_OK        Caller of the function should drop execution
*
*/
static inline Std_ReturnType Pwm_ValidateChannelConfigCall(uint32          PartitionId,
                                                           Pwm_ChannelType ChannelNumber,
                                                           uint8           ServiceId
                                                          )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType          RetVal = (Std_ReturnType)E_OK;
    Pwm_ChannelType         PartitionChannelIdx;

    /* Check if the driver is initialized */
    if (PWM_STATE_UNINIT == Pwm_aState[PartitionId].PwmDriverState)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        /* Driver not initialized yet */
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_UNINIT
        );
    }
    else
    {
        /* Check that the channel is in valid range */
        if (PWM_CONFIG_LOGIC_CHANNELS <= ChannelNumber)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;

            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
            PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

            /* Check that the channel is not in current partition */
            if (PartitionChannelIdx >= Pwm_aState[PartitionId].PwmConfig->NumChannels)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;

                (void)Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  ServiceId,
                    (uint8)  PWM_E_PARAM_CONFIG
                );
            }
            else
            {
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
                if (PWM_SETDUTYPHASESHIFT_ID == ServiceId)
                {
                    if ((Std_ReturnType)E_OK != Pwm_Ipw_ValidateSetPhaseShift(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg)))
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;

                        (void)Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)  PWM_INDEX,
                            (uint8)  ServiceId,
                            (uint8)  PWM_E_CHANNEL_PHASE_SHIFT_NOT_SUPPORTED
                        );
                    }
                }
#endif

#if ((PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SYNC_UPDATE_API == STD_ON))
                if ((PWM_SETPERIODANDDUTY_NO_UPDATE_ID == ServiceId) || (PWM_SETDUTYCYCLE_NO_UPDATE_ID == ServiceId) || (PWM_SYNCUPDATE_ID == ServiceId))
                {
                    if ((Std_ReturnType)E_OK != Pwm_Ipw_ValidateUpdateSynchronous(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg)))
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;

                        (void)Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)  PWM_INDEX,
                            (uint8)  ServiceId,
                            (uint8)  PWM_E_DUTY_SYNCHRONOUS_NOT_SUPPORTED
                        );
                    }
                }
#endif
            /* Do nothing */
            }
        }
    }

    return RetVal;
}



/*=============================================================================================*/
/**
* @brief        Completes the execution of a function impacting the configuration of a driver channel.
* @details      Performs actions in order to ensure that after it's caller has completed the execution
*               the driver will remain in a state allowing execution of other functions updating the
*               configuration of the entire driver or of a single channel.
*
* @param[in]    ChannelNumber  Id of the Pwm channel.
*
* @return       void
*
*/
static inline void Pwm_EndValidateChannelConfigCall(Pwm_ChannelType ChannelNumber)
{
    /* Avoid compiler warning */
    (void)ChannelNumber;
}
#endif
#endif /* PWM_VALIDATE_CHANNEL_CONFIG_CALL */



/*=============================================================================================*/
#if (PWM_PARAM_CHECK == STD_ON)


/*=============================================================================================*/
/**
* @brief        Validate the configuration parameter of the Pwm_Init API. In case an
*               error is detected, the function will report an error to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ConfigPtr       Pointer to the configuration of Pwm driver
*
* @return       Std_ReturnType  Validity of the pointer
* @retval       E_OK            Pointer is valid
* @retval       E_NOT_OK        Pointer is invalid
*
*/
static inline Std_ReturnType Pwm_ValidateParamPtrInit(uint32                 PartitionId,
                                                      const Pwm_ConfigType * ConfigPtr
                                                     )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType      RetVal = (Std_ReturnType)E_OK;

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
    /* For pre-compile, check DET error if the received config pointer is not NULL_PTR */
    if (NULL_PTR != ConfigPtr)
    {
#else
    /* For post build, check DET error if the received config pointer is NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
#endif
        /* Avoid compiler warning */
        (void)PartitionId;

        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_INIT_ID,
            (uint8)  PWM_E_INIT_FAILED
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
    #if (PWM_MULTIPARTITION_ENABLED == STD_ON)
    else if (PartitionId != ConfigPtr->PartitionId)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_INIT_ID,
            (uint8)  PWM_E_PARAM_CONFIG
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    #endif
    else
    {
        /* Do nothing */
    }
#else
    else
    {
    #if (PWM_MULTIPARTITION_ENABLED == STD_ON)
        if (NULL_PTR == Pwm_Config[PartitionId])
        {
            /* Avoid compiler warning */
            (void)PartitionId;

            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_INIT_ID,
                (uint8)  PWM_E_INIT_FAILED
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }

        else if (PartitionId != Pwm_Config[PartitionId]->PartitionId)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_INIT_ID,
                (uint8)  PWM_E_PARAM_CONFIG
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }

        else
        {
            /* Do nothing */
        }
    #endif
        /* Do nothing */
    }
#endif

    return RetVal;
}



/*=============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Validate the DutyCycle parameter of the Pwm_SetDutyCycle API.In case an
*               error is detected, the function will report it to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    DutyCycle         DutyCycle value to be validated
* @param[in]    ServiceId         Id of calling API
*
* @return       Std_ReturnType    Validity of the DutyCycle parameter
* @retval       E_OK              Duty Cycle is valid
* @retval       E_NOT_OK          Duty Cycle is invalid
*
*/
static inline Std_ReturnType Pwm_ValidateParamDuty(uint16   DutyCycle,
                                                   uint8    ServiceId
                                                  )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    /* Check if the DutyCycle is in valid range */
    if (DutyCycle > PWM_DUTY_CYCLE_100_U16)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_DUTYCYCLE_RANGE
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}
#endif /* PWM_SET_DUTY_CYCLE_API || PWM_SET_DUTY_CYCLE_NO_UPDATE_API */



/*=============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
/**
* @brief        Validate the Period and channel class parameters for Pwm_SetPeriodAndDuty API.
*               The Period is validated in the sense that it can be updated only for channels having
*               Variable Period class. Also it may be possible (when hardware allows it)
*               for the PWM period that would be written to hardware, to be constructed taking into
*               consideration some initial value. In such case the total value (maximum value)
*               should not exceed the maximum value supported by the hardware .
*               In case any of the parameters is invalid, the function will report an error to
*               DET or SERR, depending on the environment the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    ChannelClass    PWM channel class
* @param[in]    Period          Period in ticks
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  Validity of Channel Class, DutyCycle, Period parameters
* @retval       E_OK            Channel Class, Period are all valid
* @retval       E_NOT_OK        One of Channel Class, Period is invalid
*
*/
static inline Std_ReturnType Pwm_ValidateParamsPeriodClass(uint32                PartitionId,
                                                           Pwm_ChannelType       ChannelNumber,
                                                           Pwm_ChannelClassType  ChannelClass,
                                                           Pwm_PeriodType        Period,
                                                           uint8                 ServiceId
                                                          )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
    uint32                      PeriodMaxValue = (uint32)0U;
#else
    (void)Period;
    (void)ChannelNumber;
    (void)PartitionId;
#endif

    /* Check if channel supports updates of the period */
    if (PWM_VARIABLE_PERIOD != ChannelClass)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_PERIOD_UNCHANGEABLE
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
        PeriodMaxValue = (uint32)Pwm_Ipw_GetMaxPeriodValue(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

        /* Check if period is in range */
        if ((uint32)Period > PeriodMaxValue)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_PERIODVALUE
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Nothing to do in this branch */
        }
#else
        /* Nothing to do in this branch */
#endif
    }

    return RetVal;
}


#endif /*PWM_SET_PERIOD_AND_DUTY_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */



/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Validate the notification handler of a PWM channel.
*               In order to be valid, the notification handler should not be
*               NULL_PTR. In case it is NULL_PTR, the function will report an error to
*               DET or SERR, depending on the environment the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    Notification    Notification edge type
*
* @return       Std_ReturnType  Validity of notification handler
* @retval       E_OK            Notification handler is valid
* @retval       E_NOT_OK        Notification handler is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamNotification(uint32                   PartitionId,
                                                           Pwm_ChannelType          ChannelNumber,
                                                           Pwm_EdgeNotificationType Notification
                                                          )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;
    /** @brief  Notification pointer */
    Pwm_NotifyType                      PwmChannelNotification;

#if (PWM_NOTIFICATION_PLAUSABILITY == STD_OFF)
    (void) Notification;
#endif

    /* Get Notification handler pointer */
    PwmChannelNotification = (*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].PwmChannelNotification;

    /* Check if Notification is NULL_PTR */
    if (NULL_PTR == PwmChannelNotification)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_ENABLENOTIFICATION_ID,
            (uint8)  PWM_E_PARAM_NOTIFICATION_NULL
        );

        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_NOTIFICATION_PLAUSABILITY == STD_ON)
    }
    else
    {
        RetVal = Pwm_Ipw_ValidateNotification(Notification, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

        /* Check if Notification can support for specific mode */
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_ENABLENOTIFICATION_ID,
                (uint8)  PWM_E_PARAM_NOTIFICATION
            );
        }
#endif
    }

    return RetVal;
}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Validate the trigger delay with current period of PWM channel.
*               In order to be valid, the trigger value should less than current period. In this
*               case the function will report an error to DET or SERR, depending on the environment
*               the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    TriggerDelay    Trigger delay value
*
* @return       Std_ReturnType  Validity of trigger delay parameter
* @retval       E_OK            The trigger delay parameter is valid
* @retval       E_NOT_OK        The trigger delay parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamTriggerDelay(uint32           PartitionId,
                                                           Pwm_ChannelType  ChannelNumber,
                                                           Pwm_PeriodType   TriggerDelay
                                                          )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;
    /** @brief  Period value */
    Pwm_PeriodType                      PeriodCurValue = (Pwm_PeriodType)0U;


    PeriodCurValue = Pwm_Ipw_GetCurrentPeriodValue(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if (TriggerDelay >= PeriodCurValue)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETTRIGGERDELAY_ID,
            (uint8)  PWM_E_OPWMT_CHANNEL_TRIGGER_RANGE
        );
    }

    return RetVal;
}
#endif /* PWM_SET_TRIGGER_DELAY_API */



/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Validate the mode of current channel.
*               In order to be valid, the mode of current channel must be OPWMT
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   The Id of the given channel
*
* @return       Std_ReturnType  Validity of a channel when setting trigger delay
* @retval       E_OK            The mode of current channel is valid
* @retval       E_NOT_OK        The mode of current channel is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateTriggerDelay(uint32           PartitionId,
                                                      Pwm_ChannelType  ChannelNumber
                                                     )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateTriggerMode(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETTRIGGERDELAY_ID,
            (uint8)  PWM_E_PARAM_CHANNEL
        );
    }

    return RetVal;
}
#endif /* PWM_SET_TRIGGER_DELAY_API */

/*=============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        Validate the mode of current channel.
*               In order to be valid, the mode of current channel must be OPWMCB
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   The Id of the given channel
*
* @return       Std_ReturnType  Validity of channel when setting the dead time
* @retval       E_OK            The mode of current channel is valid
* @retval       E_NOT_OK        The mode of current channel is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateDeadTime(uint32           PartitionId,
                                                  Pwm_ChannelType  ChannelNumber
                                                 )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateDeadTime(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELDEADTIME_ID,
            (uint8)  PWM_E_PARAM_CHANNEL
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*=============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        Validate the dead time value of current channel.
*               In order to be valid, the mode of current channel must be OPWMCB
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   The Id of the given channel
* @param[in]    DeadTimeTicks   The dead time value in ticks
*
* @return       Std_ReturnType  Validity of dead time value
* @retval       E_OK            The mode of current channel is valid
* @retval       E_NOT_OK        The mode of current channel is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamDeadTime(uint32           PartitionId,
                                                       Pwm_ChannelType  ChannelNumber,
                                                       Pwm_PeriodType   DeadTimeTicks
                                                      )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateParamDeadTime(DeadTimeTicks, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELDEADTIME_ID,
            (uint8)  PWM_E_DEADTIME_RANGE
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*=============================================================================================*/
#if ((PWM_SYNC_UPDATE_API            == STD_ON) || \
     (PWM_FAST_UPDATE_API            == STD_ON) || \
     (PWM_ENABLE_MASKING_OPERATIONS            == STD_ON))
/**
* @brief        Validate the module id.
*               In order to be valid, the module id should less than number of module that supported
*
* @param[in]    ModuleId        The Id of the ipv module
* @param[in]    ServiceId       Id of the service calling this function
*
* @return       Std_ReturnType  Validity of the module id
* @retval       E_OK            The module id is valid
* @retval       E_NOT_OK        The module id is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateModuleId(uint8 ModuleId,
                                                  uint8 ServiceId
                                                 )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    if ((PWM_HW_MODULE_NO <= ModuleId) || ((Std_ReturnType)E_NOT_OK == Pwm_Ipw_ValidateModuleId(ModuleId, ServiceId)))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_PARAM_INSTANCE
        );
    }

    return RetVal;
}
#endif



/*=============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief        Validate the counter bus.
*               In order to be valid, the trigger value should less than current default. In this
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    PartitionId          The number of current partition
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    Bus             The Id current counter bus
*
* @return       Std_ReturnType  Validity of the counter bus.
* @retval       E_OK            Counter bus parameter is valid
* @retval       E_NOT_OK        Counter bus parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateCounterBus(uint32          PartitionId,
                                                    Pwm_ChannelType ChannelNumber,
                                                    uint32          Bus
                                                   )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateCounterBus(Bus, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCOUNTERBUS_ID,
            (uint8)  PWM_E_COUNTERBUS
        );
    }

    return RetVal;
}
#endif /* PWM_SET_COUNTER_BUS_API */



/*=============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        Validate the set channel output feature. This validate function only applies for eMIOS.
*
* @param[in]    PartitionId          The number of current partition.
* @param[in]    ChannelNumber   The id of channel number.
* @param[in]    State           The state of output.
*
* @return       Std_ReturnType  Validity of the channel in the set channel output feature.
* @retval       E_OK            Set channel output parameter is valid.
* @retval       E_NOT_OK        Set channel output parameter is not valid.
*
*/
static inline Std_ReturnType Pwm_ValidateSetChannelOutput(uint32            PartitionId,
                                                          Pwm_ChannelType   ChannelNumber,
                                                          Pwm_StateType     State
                                                         )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateSetChannelOutput(State, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELOUTPUT_ID,
            (uint8)  PWM_E_SET_CHANNEL_OUTPUT
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_OUTPUT_API */



#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        Pwm_ValidateParamsDutyPhaseShift
* @details      This function will check phase shift  and duty parameter .
*
* @param[in]    PartitionId               The number of current partition
* @param[in]    PhaseShift           Phase shift value
* @param[in]    DutyCycle            Duty Cycle value
* @param[in]    ChannelNumber        PWM channel ID in top configuration structure
* @param[in]    ServiceId            Service ID
*
* @return       Std_ReturnType       Validity of the phase shift feature.
* @retval       E_OK                 Parameter is valid
* @retval       E_NOT_OK             Parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamsDutyPhaseShift(uint32            PartitionId,
                                                              Pwm_DutyType      PhaseShift,
                                                              uint16            DutyCycle,
                                                              Pwm_ChannelType   ChannelNumber,
                                                              uint8             ServiceId
                                                             )
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateSetDutyPhaseShiftParams(PhaseShift,
                                                     DutyCycle,
                                                     &((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_PARAM_PHASESHIFT_RANGE
        );
    }

    return RetVal;
}
#endif




/*=============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief            Pwm_ValidateGetOutputState
* @details          This function will check the validation when calling the Pwm_GetOutputState api.
*
* @param[in]        PartitionId           The Index of current partition
* @param[in]        ChannelNumber    The id of channel number
*
* @retval           RetVal          E_NOT_OK  Get ouput state is not valid
                                    E_OK      Get ouput state is valid
*/
static inline Std_ReturnType Pwm_ValidateGetOutputState(uint32            PartitionId,
                                                        Pwm_ChannelType   ChannelNumber
                                                       )
{
    
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateGetOutputState(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETOUTPUTSTATE_ID,
            (uint8)  PWM_E_GETOUTPUTSTATE_NOT_SUPPORTED
        );
    }

    return RetVal;
}
#endif /* (PWM_GET_OUTPUT_STATE_API == STD_ON) */

#endif /* PWM_PARAM_CHECK */

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
static inline Std_ReturnType Pwm_ProcessPowerState(Pwm_PowerStateRequestResultType * Result, uint32 PartitionId)
{
    uint8 Index;
    /* The return value */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    switch(Pwm_eTargetPowerState[PartitionId])
    {
        case PWM_NODEFINE_POWER:
#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETPOWERSTATE_ID,
            (uint8)  PWM_E_PERIPHERAL_NOT_PREPARED
        );
#endif
            *Result = PWM_SEQUENCE_ERROR;
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        case PWM_LOW_POWER:
        case PWM_FULL_POWER:
            for(Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumChannels; Index++)
            {
                RetVal = Pwm_Ipw_ValidateIdleState(&((*Pwm_aState[PartitionId].PwmConfig->PwmChannelsConfig)[Index].IpwChannelCfg));
                if (RetVal == (Std_ReturnType)E_NOT_OK)
                {
                    break;
                }
            }

            if((Std_ReturnType)E_OK == RetVal)
            {
#if (PWM_HW_INSTANCE_USED == STD_ON)
                for (Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumInstances; Index ++)
                {
                    Pwm_Ipw_SetPowerStateInstance(&((*Pwm_aState[PartitionId].PwmConfig->PwmInstancesConfig)[Index]), Pwm_eTargetPowerState[PartitionId]);
                }
#endif
                for(Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumChannels; Index++)
                {
                    Pwm_Ipw_SetPowerStateChannel(Pwm_eTargetPowerState[PartitionId], &((*Pwm_aState[PartitionId].PwmChannelConfigs)[Index].IpwChannelCfg));
                }

                *Result = PWM_SERVICE_ACCEPTED;
                Pwm_eCurrentPowerState[PartitionId] = Pwm_eTargetPowerState[PartitionId];
                Pwm_eTargetPowerState[PartitionId] = PWM_NODEFINE_POWER;
            }
            else
            {
                (void)Det_ReportRuntimeError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  PWM_SETPOWERSTATE_ID,
                    (uint8)  PWM_E_NOT_DISENGAGED
                );

                *Result = PWM_HW_FAILURE;
            }
            break;
        default:
#if (PWM_PARAM_CHECK == STD_ON)
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_SETPOWERSTATE_ID,
                (uint8)  PWM_E_POWER_STATE_NOT_SUPPORTED
            );
#endif
            *Result = PWM_POWER_STATE_NOT_SUPP;
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
    }

    return RetVal;
}
#endif /* PWM_POWER_STATE_SUPPORTED */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        This function initializes the Pwm driver.
* @details      The function Pwm_Init shall initialize all internals variables and the used
*               PWM structure of the microcontroller according to the parameters
*               specified in ConfigPtr.
*               If the duty cycle parameter equals:
*
*                   - 0% or 100% : Then the PWM output signal shall be in the state according
*                       to the configured polarity parameter;
*
*                   - >0% and <100%: Then the PWM output signal shall be modulated according
*                       to parameters period, duty cycle and configured polarity.
*
*               The function Pwm_SetDutyCycle shall update the duty cycle always at the end
*               of the period if supported by the implementation and configured
*               with PwmDutycycleUpdatedEndperiod.
*
*               The driver shall avoid spikes on the PWM output signal when updating
*               the PWM period and duty.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the parameter ChannelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development
*               error occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The function Pwm_Init shall disable all notifications. The reason is that the users
*               of these notifications may not be ready. They can call Pwm_EnableNotification
*               to start notifications.
*
*               The function Pwm_Init shall only initialize the configured resources and shall not touch
*               resources that are not configured in the configuration file.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection is enabled, calling the routine Pwm_Init
*               while the PWM driver and hardware are already initialized will cause a
*               development error PWM_E_ALREADY_INITIALIZED.
*               The desired functionality shall be left without any action.
*
*               For pre-compile and link time configuration variants, a NULL_PTR pointer shall be passed
*               to the initialization routine. In this case the check for this NULL_PTR pointer
*               has to be omitted.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ConfigPtr       Pointer to PWM top configuration structure
*
* @return       void
*
* @implements   Pwm_Init_Activity
*
*/
void Pwm_Init(const Pwm_ConfigType * ConfigPtr)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON) || (PWM_PARAM_CHECK == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      PartitionId;
    uint8                       Index;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_INIT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        CallIsValid = Pwm_ValidateParamPtrInit(PartitionId, ConfigPtr);

        if ((Std_ReturnType)E_OK == CallIsValid)
        {
#endif

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
            /* Save configuration pointer in global variable */
#if (PWM_MULTIPARTITION_ENABLED == STD_ON)
            Pwm_aState[PartitionId].PwmConfig = Pwm_Config[PartitionId];
#else
            Pwm_aState[PartitionId].PwmConfig = &Pwm_Config;
#endif
            (void)ConfigPtr;
#else
            Pwm_aState[PartitionId].PwmConfig = ConfigPtr;
#endif

#if (PWM_HW_INSTANCE_USED == STD_ON)
            /* IPW call to hw instance initialization when PWM controls the entire hw instance */
            for (Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_InitInstance(&((*Pwm_aState[PartitionId].PwmConfig->PwmInstancesConfig)[Index]));
            }
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            for(Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumChannels; Index++)
            {
                Pwm_aState[PartitionId].PwmChannelConfigs[Index] = &((*Pwm_aState[PartitionId].PwmConfig->PwmChannelsConfig)[Index]);
                /* Continue to hw channel initialization */
                Pwm_Ipw_Init(&((*Pwm_aState[PartitionId].PwmConfig->PwmChannelsConfig)[Index].IpwChannelCfg));
            }

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
            Pwm_aState[PartitionId].PwmCurrentPowerState = PWM_FULL_POWER;
            Pwm_aState[PartitionId].PwmTargetPowerState = PWM_NODEFINE_POWER;
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_INIT_ID);
#endif
}



/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        This function deinitializes the Pwm driver.
* @details      The function Pwm_DeInit shall deinitialize the PWM module.
*
*               The function Pwm_DeInit shall set the state of the PWM output signals
*               to the idle state.
*               The function Pwm_DeInit shall disable PWM interrupts and PWM signal edge notifications.
*               The function Pwm_DeInit shall be pre-compile time configurable On-Off by the
*               configuration parameter PwmDeInitApi function prototype.
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    None
*
* @return       void
*
* @implements   Pwm_DeInit_Activity
*
*/
void Pwm_DeInit(void)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
#if (PWM_HW_INSTANCE_USED == STD_ON)
    const Pwm_ConfigType      * ConfigPtr;
#endif
    uint32                      PartitionId;
    uint8                       Index;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_DEINIT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

        /* All validations passed. Here starts the actual functional code of the function */
        /* Deinitialize all channels */
        for(Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumChannels; Index++)
        {
            Pwm_Ipw_DeInit(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[Index].IpwChannelCfg), (*Pwm_aState[PartitionId].PwmChannelConfigs)[Index].ChannelIdleState);
        }

#if (PWM_HW_INSTANCE_USED == STD_ON)
        ConfigPtr =  Pwm_aState[PartitionId].PwmConfig;
        /* IPW call to hw instance initialization when PWM controls the entire hw instance */
        for (Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumInstances; Index++)
        {
            Pwm_Ipw_DeInitInstance(&((*ConfigPtr->PwmInstancesConfig)[Index]));
        }
#endif
        /* Set global configuration pointer back to NULL_PTR */
        Pwm_aState[PartitionId].PwmConfig = NULL_PTR;

        /* Set all channels config to NULL_PTR */
        for(Index = 0; Index < PWM_CONFIG_LOGIC_CHANNELS; Index++)
        {
            Pwm_aState[PartitionId].PwmChannelConfigs[Index] = NULL_PTR;
        }
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
        /* Reset Power State */
        Pwm_aState[PartitionId].PwmCurrentPowerState = PWM_NODEFINE_POWER;
        Pwm_aState[PartitionId].PwmTargetPowerState = PWM_NODEFINE_POWER;
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_DEINIT_ID);
#endif

}
#endif /* PWM_DE_INIT_API */



/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        This function sets the dutycycle for the specified Pwm channel.
* @details      The function Pwm_SetDutyCycle shall set the duty cycle of the PWM channel.
*
*               The function Pwm_SetDutyCycle shall set the PWM output state according
*               to the configured polarity parameter, when the duty cycle = 0% or 100%.
*               The function Pwm_SetDutyCycle shall modulate the PWM output signal according
*               to parameters period, duty cycle and configured polarity,
*               when the duty cycle > 0 % and < 100%.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetDutyCycle_Activity
*
*/
void Pwm_SetDutyCycle(Pwm_ChannelType   ChannelNumber,
                      uint16            DutyCycle
                     )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETDUTYCYCLE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETDUTYCYCLE_ID))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            RetVal = Pwm_Ipw_SetDutyCycle(DutyCycle, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

            /* Avoid compiler warning */
            (void)RetVal;

#if (PWM_PARAM_CHECK == STD_ON)
            if ((Std_ReturnType)E_OK != RetVal)
            {
                (void)Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  PWM_SETDUTYCYCLE_ID,
                    (uint8)  PWM_E_CHANNEL_OFFSET_VALUE
                );
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_DUTY_CYCLE_API */



/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        This function sets the period and the dutycycle for the specified Pwm channel.
* @details      The function Pwm_SetPeriodAndDuty shall set the duty cycle of the PWM channel.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*               raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    Period          Pwm signal period value
* @param[in]    DutyCycle       Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetPeriodAndDuty_Activity
*
*/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType   ChannelNumber,
                          Pwm_PeriodType    Period,
                          uint16            DutyCycle
                         )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETPERIODANDDUTY_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamsPeriodClass(PartitionId, PartitionChannelIdx, (*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].PwmChannelClass, Period, PWM_SETPERIODANDDUTY_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETPERIODANDDUTY_ID))
            {
#endif

                /* All validations passed. Here starts the actual functional code of the function */
                (void)Pwm_Ipw_SetPeriodAndDuty(Period, DutyCycle, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */



/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        This function sets the generated pwm signal to the idle value configured.
* @details      The function Pwm_SetOutputToIdle shall set immediately the
*               PWM output to the configured Idle state.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the parameter ChannelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a
*               development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of data
*                       or hardware registers (this means leave the function without any actions).
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               After the call of the function Pwm_SetOutputToIdle, variable period type channels
*               shall be reactivated either using the Api Pwm_SetPeriodAndDuty() to activate
*               the PWM channel with the new passed period or Api Pwm_SetDutyCycle() to activate
*               the PWM channel with the old period.
*
*               After the call of the function Pwm_SetOutputToIdle, fixed period type channels
*               shall be reactivated using only the API Api Pwm_SetDutyCycle() to activate
*               the PWM channel with the old period.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber   Pwm channel id
*
* @return       void
*
* @implements   Pwm_SetOutputToIdle_Activity
*
*/
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETOUTPUTTOIDLE_ID))
    {
#endif

        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);
            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetOutputToIdle((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].ChannelIdleState, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

            /* Mark the channel in idle output mode */

            Pwm_aState[PartitionId].PwmChannelIdleState[PartitionChannelIdx] = TRUE;
#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */



/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        This function returns the signal output state.
* @details      The function Pwm_GetOutputState shall read the internal state of
*               the PWM output signal and return it as defined in the diagram below (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter ChannelNumber and
*               raise development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a
*               development error occurs, the corresponding PWM function shall:
*                  - Report the error to the Development Error Tracer.
*                  - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                  - Return pwm level low for the function Pwm_GetOutputState.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               Due to real time constraint and setting of the PWM channel (project dependant),
*               the output state can be modified just after the call of the service Pwm_GetOutputState.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber        Pwm channel id
*
* @return       Pwm_OutputStateType  Pwm signal output logic value
* @retval       PWM_LOW              The output state of PWM channel is low
* @retval       PWM_HIGH             The output state of PWM channel is high
*
* @implements   Pwm_GetOutputState_Activity
*
*/
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{

    uint32                  PartitionId;
    Pwm_ChannelType         PartitionChannelIdx;
    /** @brief  Variable to store the value returned by the function */
    Pwm_OutputStateType     RetVal = PWM_LOW;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_GETOUTPUTSTATE_ID))
    {
#endif

        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Pwm_ValidateGetOutputState(PartitionId, PartitionChannelIdx))
        {
#endif /* PWM_PARAM_CHECK */

            /* All validations passed. Here starts the actual functional code of the function */
            RetVal = Pwm_Ipw_GetOutputState(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif /* PWM_PARAM_CHECK */

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

    return RetVal;
}
#endif /* PWM_GET_OUTPUT_STATE_API */



/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function disables the user notifications.
* @details      If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ChannelNumber and raise
*               development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*               - Report the error to the Development Error Tracer.
*               - Skip the desired functionality in order to avoid any corruptions of
*                  data or hardware registers (this means leave the function without any actions).
*               - Return pwm level low for the function Pwm_GetOutputState.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*                All functions from the PWM module except Pwm_Init, Pwm_DeInit and Pwm_GetVersionInfo
*               shall be re-entrant for different PWM channel numbers. In order to keep a simple module
*               implementation, no check of PWM088 must be performed by the module.
*               The function Pwm_DisableNotification shall be pre compile time configurable On-Off by the
*               configuration parameter: PwmNotificationSupported.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*               raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber    Pwm channel id
*
* @return       void
*
* @implements   Pwm_DisableNotification_Activity
*
*/
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_DISABLENOTIFICATION_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        Pwm_Ipw_DisableNotification(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function enables the user notifications.
* @details      The function Pwm_EnableNotification shall enable the PWM signal edge notification
*               according to notification parameter.
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ChannelNumber and raise
*               development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development error
*               occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    Notification    Notification type to be enabled
*
* @return       void
*
* @implements   Pwm_EnableNotification_Activity
*
*/
void Pwm_EnableNotification(Pwm_ChannelType           ChannelNumber,
                            Pwm_EdgeNotificationType  Notification
                           )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_ENABLENOTIFICATION_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamNotification(PartitionId, PartitionChannelIdx, Notification))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_EnableNotification(Notification, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_VERSION_INFO_API == STD_ON)
/**
* @brief        This function returns Pwm driver version details
* @details      The function Pwm_GetVersionInfo shall return the version information of this module.
*               The version information includes: Module Id, Vendor Id, Vendor specific version number.
*
* @param[out]   versioninfo   Pointer to Std_VersionInfoType output variable
*
* @return       void
*
* @implements   Pwm_GetVersionInfo_Activity
*
*/
void Pwm_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != versioninfo)
    {
#endif

        (versioninfo)->vendorID         = (uint16)PWM_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PWM_MODULE_ID;

        (versioninfo)->sw_major_version = (uint8)PWM_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PWM_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PWM_SW_PATCH_VERSION;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        /* if the parameter versionInfo is NULL_PTR then report the error */
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETVERSIONINFO_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
    }
#endif

}
#endif /* PWM_VERSION_INFO_API */



/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        This function returns the duty cycle of the channel passed as parameter
* @details      The function Pwm_GetChannelState shall return the DutyCycle of the channel.
*               In case the channel is idle, the returned value will be zero.
*
* @param[in]    ChannelNumber   Pwm channel id
*
* @return       uint16          DutyCycle of the requested channel
*
* @implements   Pwm_GetChannelState_Activity
*
*/
uint16 Pwm_GetChannelState(Pwm_ChannelType ChannelNumber)
{
    uint32            PartitionId;
    Pwm_ChannelType   PartitionChannelIdx;
    /** @brief  Duty cycle value */
    uint16            DutyCycle = (uint16)0U;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_GETCHANNELSTATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        DutyCycle = Pwm_Ipw_GetChannelState(&((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

    return DutyCycle;
}
#endif /* PWM_GET_CHANNEL_STATE_API */



/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Notification
* @details      This function is called from Pwm_Ipw.c file in order to forward a
*               channel notification call from the IP configuration.
*
* @param[in]    Channel   Hw channel for which notification should be called
*
* @return       void
*
* @implements   Pwm_Notification_Activity
*
*/
void Pwm_Notification(uint8 Channel)
{
    uint8            LogicChannel;
    uint32           PartitionId;
    Pwm_ChannelType  PartitionChannelIdx;
    Pwm_NotifyType   Notify;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

    if (NULL_PTR != Pwm_aState[PartitionId].PwmConfig)
    {
        LogicChannel = Pwm_aState[PartitionId].PwmConfig->HwToLogicChannelMap[Channel];

        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, LogicChannel);

        /* Check that there is a logic channel associated with the Hw one */
        Notify = (*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].PwmChannelNotification;

        /* Check that a notification is defined for the associated
        logic channel. This is a double check not necessarily needed because if notification were
        enabled in IP layer for the channel that generated the interrupt causing this notify to
        be called, it means that this channel cannot have a null notification, otherwise notification
        could not have been enabled */
        if (NULL_PTR != Notify)
        {
            Notify();
        }
    }
}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief        This function will change the bus of pwm channels running.
* @details      This function is useful to change the frequency of the output PWM signal between
*               two counter buses frequency
*
* @param[in]    ChannelNumber    Pwm channel id
* @param[in]    Bus              The bus need to be changed
*
* @return       void
*
*/
void Pwm_SetCounterBus(Pwm_ChannelType  ChannelNumber,
                       uint32           Bus
                      )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETCOUNTERBUS_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateCounterBus(PartitionId, PartitionChannelIdx, Bus))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetCounterBus(Bus, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_COUNTER_BUS_API */



/*===============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        function to set the state of the PWM pin as requested for the current cycle
* @details      This function is useful to set the state of the PWM pin as requested
*               for the current cycle and continues with normal PWM operation from the next cycle
*
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    State           Active-Inactive state of the channel
*
* @return       void
*
*/
void Pwm_SetChannelOutput(Pwm_ChannelType   ChannelNumber,
                          Pwm_StateType     State
                         )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETCHANNELOUTPUT_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateSetChannelOutput(PartitionId, PartitionChannelIdx, State))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetChannelOutput(State, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_CHANNEL_OUTPUT_API */



/*===============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Implementation specific function to change the trigger delay
* @details      This function is useful to set the trigger delay to opwmt mode. If no DET error
*               reported then the trigger delay for  the PWM channels will be set. If development
*               error detection for the Pwm module is enabled:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of data
*               or hardware registers: This means leave the function without any actions.
*
* @param[in]    ChannelNumber    Pwm channel id
* @param[in]    TriggerDelay     Trigger delay value
*
* @return       void
* @implements   Pwm_SetTriggerDelay_Activity
*/
void Pwm_SetTriggerDelay(Pwm_ChannelType    ChannelNumber,
                         Pwm_PeriodType     TriggerDelay
                        )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETTRIGGERDELAY_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateTriggerDelay(PartitionId, PartitionChannelIdx))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamTriggerDelay(PartitionId, PartitionChannelIdx, TriggerDelay))
            {
#endif

                /* All validations passed. Here starts the actual functional code of the function */
                Pwm_Ipw_SetTriggerDelay(TriggerDelay, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_TRIGGER_DELAY_API */



/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Implementation specific function to change the peripheral clock frequency.
* @details      This function is useful to set the prescalers that divide the PWM channels
*               clock frequency.
*
* @param[in]    Prescaler   Pwm prescaler type
*
* @return       void
*
* @implements   Pwm_SetClockMode_Activity
*
*/
void Pwm_SetClockMode(Pwm_PrescalerType Prescaler)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      PartitionId;
    uint8                       Index;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_SETCLOCKMODE_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_HW_INSTANCE_USED == STD_ON)
    for (Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumInstances; Index++)
    {
        Pwm_Ipw_SetClockModeInstance(Prescaler, &((*Pwm_aState[PartitionId].PwmConfig->PwmInstancesConfig)[Index]));
    }
#endif
    for(Index = 0; Index < Pwm_aState[PartitionId].PwmConfig->NumChannels; Index++)
    {
        Pwm_Ipw_SetClockModeChannel(Prescaler, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[Index].IpwChannelCfg));
    }


#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_SETCLOCKMODE_ID);
#endif

}
#endif /* PWM_SET_CLOCK_MODE_API */



/*===============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief
* @details      This function is used to update the deadtime at runtime for Pwm channels.
*
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DeadTimeTicks       Dead Time value
*
* @return       void
*
* @implements   Pwm_SetChannelDeadTime_Activity
*/
void Pwm_SetChannelDeadTime(Pwm_ChannelType  ChannelNumber,
                            Pwm_PeriodType   DeadTimeTicks
                           )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETCHANNELDEADTIME_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);
#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateDeadTime(PartitionId, PartitionChannelIdx))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamDeadTime(PartitionId, PartitionChannelIdx, DeadTimeTicks))
            {
#endif
                Pwm_Ipw_SetChannelDeadTime(DeadTimeTicks, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_DEAD_TIME_CHANNEL_API */



/*===============================================================================================*/
#if (PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON)


/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON)
/**
* @brief        This function sets the values of dutycycle for the specified Pwm channel but without
*               updating the PWM output.
* @details      The function Pwm_SetDutyCycle_NoUpdate shall set the duty cycle of the PWM channel to the
*               coresponding hardware buffers without updating the wave form on the output pin.
*               This feature will allow a pre-buffering of new PWM duty cycle values for several channel,
*               which can all be updated synchronos by calling Pwm_SyncUpdate.
*
*               The function Pwm_SetDutyCycle_NoUpdate shall set the PWM output state according
*               to the configured polarity parameter, when the duty cycle = 0% or 100%.
*               The function Pwm_SetDutyCycle_NoUpdate shall modulate the PWM output signal according
*               to parameters period, duty cycle and configured polarity,
*               when the duty cycle > 0 % and < 100%.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetDutyCycle_NoUpdate_Activity
*
*/
void Pwm_SetDutyCycle_NoUpdate(Pwm_ChannelType  ChannelNumber,
                               uint16           DutyCycle
                              )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETDUTYCYCLE_NO_UPDATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETDUTYCYCLE_NO_UPDATE_ID))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            RetVal = Pwm_Ipw_SetDutyCycle_NoUpdate(DutyCycle, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

            /* Avoid compiler warning */
            (void)RetVal;

#if (PWM_PARAM_CHECK == STD_ON)
            if ((Std_ReturnType)E_OK != RetVal)
            {
                (void)Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  PWM_SETDUTYCYCLE_NO_UPDATE_ID,
                    (uint8)  PWM_E_CHANNEL_OFFSET_VALUE
                );
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_DUTY_CYCLE_NO_UPDATE_API */



/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)
/**
* @brief        This function sets the values of the period and the dutycycle for the specified Pwm channel
*               into the hardware buffers but without updating the PWM output..
* @details      The function Pwm_SetPeriodAndDuty_NoUpdate shall set the period and duty cycle of the PWM
*               channel to the coresponding hardware buffers without updating the wave form on the output pin.
*               This feature will allow a pre-buffering of new PWM duty cycle values for several channel,
*               which can all be updated synchronos by calling Pwm_SyncUpdate.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*               raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber    Pwm channel id
* @param[in]    Period           Pwm signal period value
* @param[in]    DutyCycle        Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetPeriodAndDuty_NoUpdate_Activity
*
*/
void Pwm_SetPeriodAndDuty_NoUpdate(Pwm_ChannelType  ChannelNumber,
                                   Pwm_PeriodType   Period,
                                   uint16           DutyCycle
                                  )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETPERIODANDDUTY_NO_UPDATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamsPeriodClass(PartitionId, PartitionChannelIdx, (*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].PwmChannelClass, Period, PWM_SETPERIODANDDUTY_NO_UPDATE_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETPERIODANDDUTY_NO_UPDATE_ID))
            {
#endif

                /* All validations passed. Here starts the actual functional code of the function */
                Pwm_Ipw_SetPeriodAndDuty_NoUpdate(Period, DutyCycle, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */



/*===============================================================================================*/
#if (PWM_SYNC_UPDATE_API == STD_ON)
/**
* @brief        Implementation specific function to updates duty synchronization.
*
* @details      This function is used to update duty synchronization for channels in given module,
*               this should be called after calling Pwm_SetPeriodAndDuty_NoUpdate() or
*               Pwm_SetDutyCycle_NoUpdate() API.
*
* @param[in]    ModuleId             pwm module id
*                                    Ex : PWM_EMIOS_INSTANCE_0
*                                         PWM_EMIOS_INSTANCE_1
*                                         ...
*                                         PWM_FLEXPWM_INSTANCE_0
*                                         ...
*                                         PWM_FTM_INSTANCE_0
*
* @return       void
*
* @implements   Pwm_SyncUpdate_Activity
*
*/
void Pwm_SyncUpdate(uint8 ModuleId)
{

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType                      CallIsValid;
    uint32                              PartitionId;
    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_SYNCUPDATE_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_SYNCUPDATE_ID))
        {
#endif
            Pwm_Ipw_SyncUpdate(ModuleId);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }
    Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_SYNCUPDATE_ID);
#endif

}
#endif /* PWM_SYNC_UPDATE_API */


#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS */



/*===============================================================================================*/
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Pwm_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    ChannelNumber           Pwm Channel Id in the configuration
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShift              Phase shift value (in ticks)
* @param[in]    SyncUpdate              Update duty and phases shift value synchronization for channels in given module or not
*                                       TRUE     Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                                       FALSE    Set phase shift and duty cycle value immediately
*
* @return       void
*
* @implements   Pwm_SetDutyPhaseShift_Activity
*/
void Pwm_SetDutyPhaseShift(Pwm_ChannelType  ChannelNumber,
                           uint16           DutyCycle,
                           Pwm_DutyType     PhaseShift,
                           boolean          SyncUpdate
                          )
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETDUTYPHASESHIFT_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETDUTYPHASESHIFT_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamsDutyPhaseShift(PartitionId, PhaseShift, DutyCycle, PartitionChannelIdx, PWM_SETDUTYPHASESHIFT_ID))
            {
#endif
                /* All validations passed. Here starts the actual functional code of the function */
                Pwm_Ipw_SetDutyPhaseShift(DutyCycle, PhaseShift, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg), SyncUpdate);

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_DUTY_PHASE_SHIFT_API */



/*=======================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to change duty cycle or phase shift
*               with minimum overhead
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ChannelNumber    Pwm logic channel id
* @param[in]    Value            Value to write in register
*
* @return       void
*
* @implements   Pwm_FastUpdateSetUCRegA_Activity
*
*/
void Pwm_FastUpdateSetUCRegA(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Value)
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETUCREGA_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        Pwm_Ipw_FastUpdateSetUCRegA((Pwm_Ipw_PeriodType)Value, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_FAST_UPDATE_API */


/*=======================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to change duty cycle, phase shift or
*               inserted dead time buffer with minimum overhead
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ChannelNumber    Pwm logic channel id
* @param[in]    Value            Value to write in register
*
* @return       void
*
* @implements   Pwm_FastUpdateSetUCRegB_Activity
*
*/
void Pwm_FastUpdateSetUCRegB(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Value)
{
    uint32          PartitionId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(PartitionId, ChannelNumber, PWM_SETUCREGB_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(PartitionId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        Pwm_Ipw_FastUpdateSetUCRegB((Pwm_Ipw_PeriodType)Value, &((*Pwm_aState[PartitionId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_FAST_UPDATE_API */



/*=======================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to disable output update for selected Emios channels
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ModuleId       Pwm hardware module id
* @param[in]    ChannelMask    Bit mask of Emios hardware channels
*
* @return       void
*
* @implements   Pwm_FastUpdateDisableOU_Activity
*
*/
void  Pwm_FastUpdateDisableOU(uint8 ModuleId, uint32 ChannelMask)
{
#if (PWM_PARAM_CHECK == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_DISABLEOU_ID))
    {
#endif
        Pwm_Ipw_FastUpdateDisableOU(ModuleId, ChannelMask);

#if (PWM_PARAM_CHECK == STD_ON)
    }
#endif

}
#endif /* PWM_FAST_UPDATE_API */



/*=======================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to enable output update for selected Emios channels
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ModuleId       Pwm hardware module id
* @param[in]    ChannelMask    Bit mask of Emios hardware channels
*
* @return       void
*
* @implements   Pwm_FastUpdateEnableOU_Activity
*
*/
void  Pwm_FastUpdateEnableOU(uint8 ModuleId, uint32 ChannelMask)
{
#if (PWM_PARAM_CHECK == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_ENABLEOU_ID))
    {
#endif
        Pwm_Ipw_FastUpdateEnableOU(ModuleId, ChannelMask);

#if (PWM_PARAM_CHECK == STD_ON)
    }
#endif

}
#endif /* PWM_FAST_UPDATE_API */



/*=======================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function forces channels output to logic 0 before consideration of the output polarity.
*               Due to hardware specific feature, channels X will be forced to their active state, channels A and B will be forced to their inactive state.
* @details      Corresponding bits with masked channels are shown as bellow:
*                        ----- --------- -----------
*                       | Bit | Channel | Submodule |
*                        ----- --------- -----------
*                       |  0  |         |     0     |
*                        -----           -----------
*                       |  1  |         |     1     |
*                        -----           -----------
*                       |  2  |    X    |     2     |
*                        -----           -----------
*                       |  3  |         |     3     |
*                        ----- --------- -----------
*                       |  4  |         |     0     |
*                        -----           -----------
*                       |  5  |         |     1     |
*                        -----           -----------
*                       |  6  |    B    |     2     |
*                        -----           -----------
*                       |  7  |         |     3     |
*                        ----- --------- -----------
*                       |  8  |         |     0     |
*                        -----           -----------
*                       |  9  |         |     1     |
*                        -----           -----------
*                       |  10 |    A    |     2     |
*                        -----           -----------
*                       |  11 |         |     3     |
*                        ----- --------- -----------
*
* @param[in]    ModuleId      Pwm Hardware module id
* @param[in]    ChannelsMask  Bitmask's used to select corresponding channels.
* @param[in]    UpdateType    The update is immediate or wait for a trigger event.
*                             TRUE     Update immediately
*                             FALSE    Wait for a trigger event
*
* @return       void
*
* @implements   Pwm_MaskOutputs_Activity
*
*/
void Pwm_MaskOutputs
(
    uint8   ModuleId,
    uint16  ChannelsMask,
    boolean UpdateType
)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType          CallIsValid;
#endif
    uint32                  PartitionId;
    uint8                   Index;
    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_MASKOUTPUT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId(ModuleId, PWM_MASKOUTPUT_ID))
        {
#endif
            for (Index = 0 ; Index < Pwm_aState[PartitionId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_MaskOutputs(ModuleId, ChannelsMask, UpdateType, &((*Pwm_aState[PartitionId].PwmConfig->PwmInstancesConfig)[Index]));
            }

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_MASKOUTPUT_ID);
#endif

}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */



/*=======================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function puts channels output to normal operation state.
* @details      Corresponding bits with un-masked channels are shown as bellow:
*                        ----- --------- -----------
*                       | Bit | Channel | Submodule |
*                        ----- --------- -----------
*                       |  0  |         |     0     |
*                        -----           -----------
*                       |  1  |         |     1     |
*                        -----           -----------
*                       |  2  |    X    |     2     |
*                        -----           -----------
*                       |  3  |         |     3     |
*                        ----- --------- -----------
*                       |  4  |         |     0     |
*                        -----           -----------
*                       |  5  |         |     1     |
*                        -----           -----------
*                       |  6  |    B    |     2     |
*                        -----           -----------
*                       |  7  |         |     3     |
*                        ----- --------- -----------
*                       |  8  |         |     0     |
*                        -----           -----------
*                       |  9  |         |     1     |
*                        -----           -----------
*                       |  10 |    A    |     2     |
*                        -----           -----------
*                       |  11 |         |     3     |
*                        ----- --------- -----------
*
* @param[in]    ModuleId      Pwm Hardware module id
* @param[in]    ChannelsMask  Bitmask's used to select corresponding channels.
* @param[in]    UpdateType    The update is immediate or wait for a trigger event.
*                             TRUE     Update immediately
*                             FALSE    Wait for a trigger event
*
* @return       void
*
* @implements   Pwm_UnMaskOutputs_Activity
*
*/
void Pwm_UnMaskOutputs
(
    uint8   ModuleId,
    uint16  ChannelsMask,
    boolean UpdateType
)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      PartitionId;
    uint8                       Index;
    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_UNMASKOUTPUT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_UNMASKOUTPUT_ID))
        {
#endif
            for (Index = 0 ; Index < Pwm_aState[PartitionId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_UnMaskOutputs(ModuleId, ChannelsMask, UpdateType, &((*Pwm_aState[PartitionId].PwmConfig->PwmInstancesConfig)[Index]));
            }

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_UNMASKOUTPUT_ID);
#endif

}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */





/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Enters the already prepared power state.
* @details      This API configures the Pwm module so that it enters the already prepared power
*               state, chosen between a predefined set of configured ones.
*
* @param[out]   Result          Pointer to a variable to store the result of this function
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK            Power Mode changed.
* @retval       E_NOT_OK        Request rejected.
*
* @implements   Pwm_SetPowerState_Activity
*
*/
Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32         PartitionId;
    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

    if (NULL_PTR == Result)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif

    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        RetVal = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_SETPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            if (Pwm_eCurrentPowerState[PartitionId] == Pwm_eTargetPowerState[PartitionId])
            {
                *Result = PWM_SERVICE_ACCEPTED;
            }
            else
            {
                RetVal = Pwm_ProcessPowerState(Result, PartitionId);
            }
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(PartitionId, RetVal, PWM_SETPOWERSTATE_ID);
#endif
    }

    return RetVal;

}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Get the current power state of the Pwm HW unit.
* @details      This API returns the current power state of the Pwm HW unit.
*
* @param[out]   CurrentPowerState    The current power mode of the Pwm HW Unit is returned in this parameter
* @param[out]   Result               Pointer to a variable to store the result of this function
*
* @return       Std_ReturnType       Standard return type.
* @retval       E_OK                 Mode could be read.
* @retval       E_NOT_OK             Service is rejected.
*
* @implements   Pwm_GetCurrentPowerState_Activity
*
*/
Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType *              CurrentPowerState,
                                        Pwm_PowerStateRequestResultType * Result
                                       )
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32          PartitionId;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

    if ((NULL_PTR == Result) || (NULL_PTR == CurrentPowerState))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETCURRENTPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif
    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        RetVal = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_GETCURRENTPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            *CurrentPowerState = Pwm_eCurrentPowerState[PartitionId];
            *Result = PWM_SERVICE_ACCEPTED;

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(PartitionId, RetVal, PWM_GETCURRENTPOWERSTATE_ID);
#endif
    }

    return RetVal;

}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Get the target power state of the Pwm HW unit.
* @details      This API returns the target power state of the Pwm HW unit.
*
* @param[out]   TargetPowerState     The Target power mode of the Pwm HW Unit is returned in this parameter.
* @param[out]   Result               Pointer to a variable to store the result of this function.
*
* @return       Std_ReturnType       Standard return type.
* @retval       E_OK                 Mode could be read.
* @retval       E_NOT_OK             Service is rejected.
*
* @implements   Pwm_GetTargetPowerState_Activity
*
*/
Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType *              TargetPowerState,
                                       Pwm_PowerStateRequestResultType * Result
                                      )
{
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      PartitionId;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

    if ((NULL_PTR == Result) || (NULL_PTR == TargetPowerState))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETTARGETPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif
    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        CallIsValid = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_GETTARGETPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == CallIsValid)
        {
#endif
            *TargetPowerState = Pwm_eTargetPowerState[PartitionId];
            *Result = PWM_SERVICE_ACCEPTED;

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(PartitionId, CallIsValid, PWM_GETTARGETPOWERSTATE_ID);
#endif
    }

    return RetVal;

}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Starts the needed process to allow the Pwm HW module to enter the requested power state.
* @details      This API starts the needed process to allow the Pwm HW module to enter the requested power state.
*
* @param[in]    PowerState      The target power state intended to be attained.
* @param[out]   Result          Pointer to a variable to store the Result of this function.
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK            Mode could be read.
* @retval       E_NOT_OK        Service is rejected.
*
* @implements   Pwm_PreparePowerState_Activity
*
*/
Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType                PowerState,
                                     Pwm_PowerStateRequestResultType * Result
                                    )
{
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
    uint32                      PartitionId;

    /* Get partition Id of current processor */
    PartitionId = Pwm_GetPartitionId();

    if (NULL_PTR == Result)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_PREPAREPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif
    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        RetVal = Pwm_ValidateGlobalConfigCall(PartitionId, PWM_PREPAREPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            if (Pwm_eCurrentPowerState[PartitionId] != PowerState)
            {
                if ((PWM_LOW_POWER != PowerState) && (PWM_FULL_POWER != PowerState))
                {
                    *Result = PWM_POWER_STATE_NOT_SUPP;
                    RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
                    (void)Det_ReportError
                    (
                        (uint16) PWM_MODULE_ID,
                        (uint8)  PWM_INDEX,
                        (uint8)  PWM_PREPAREPOWERSTATE_ID,
                        (uint8)  PWM_E_POWER_STATE_NOT_SUPPORTED
                    );
#endif
                }
                else
                {
                    *Result = PWM_SERVICE_ACCEPTED;
                    Pwm_eTargetPowerState[PartitionId] = PowerState;
                }
            }
            else
            {
                *Result = PWM_SEQUENCE_ERROR;
                RetVal = (Std_ReturnType)E_NOT_OK;
            }

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(PartitionId, RetVal, PWM_PREPAREPOWERSTATE_ID);
#endif
    }

    return RetVal;
}
#endif /* PWM_POWER_STATE_SUPPORTED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
