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
*   @file       Pwm_Ipw.c
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
#include "Pwm_Ipw.h"

#if (PWM_EMIOS_USED == STD_ON)
#include "Emios_Pwm_Ip.h"
#endif

#if (PWM_FLEXPWM_USED == STD_ON)
#include "FlexPwm_Ip.h"
#endif

#if (PWM_FLEXIO_USED == STD_ON)
    #include "Flexio_Pwm_Ip.h"
    #include "Flexio_Pwm_Ip_HwAccess.h"
#endif

#if (PWM_ETPU_USED == STD_ON)
#include "Etpu_Pwm_Ip.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_IPW_VENDOR_ID_C                     43
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define PWM_IPW_AR_RELEASE_MINOR_VERSION_C      7
#define PWM_IPW_AR_RELEASE_REVISION_VERSION_C   0
#define PWM_IPW_SW_MAJOR_VERSION_C              5
#define PWM_IPW_SW_MINOR_VERSION_C              0
#define PWM_IPW_SW_PATCH_VERSION_C              0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Pwm_Ipw.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and PWM_Ipw.h file are of the same vendor */
#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and PWM_Ipw.h are different."
#endif

/* Check if source file and PWM_Ipw.h file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and PWM_Ipw.h are different."
#endif

/* Check if source file and PWM_Ipw.h file are of the same Software version */
#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_SW_MAJOR_VERSION)  || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_SW_MINOR_VERSION)  || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and PWM_Ipw.h are different."
#endif

#if (PWM_EMIOS_USED == STD_ON)
/* Check if source file and Emios_Pwm_Ip.h file are of the same vendor */
#if (PWM_IPW_VENDOR_ID_C != EMIOS_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same Software version */
#if ((PWM_IPW_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_SW_MAJOR_VERSION)  || \
     (PWM_IPW_SW_MINOR_VERSION_C != EMIOS_PWM_IP_SW_MINOR_VERSION)  || \
     (PWM_IPW_SW_PATCH_VERSION_C != EMIOS_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and Emios_Pwm_Ip.h are different."
#endif
#endif
#if (PWM_FLEXIO_USED == STD_ON)
    /* Check if source file and Flexio_Pwm_Ip.h file are of the same vendor */
    #if (PWM_IPW_VENDOR_ID_C != FLEXIO_PWM_IP_VENDOR_ID)
        #error "Vendor IDs of Pwm_Ipw.c and Flexio_Pwm_Ip.h are different."
    #endif

    /* Check if source file and Flexio_Pwm_Ip.h file are of the same AUTOSAR version */
    #if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR version numbers of Pwm_Ipw.c and Flexio_Pwm_Ip.h are different."
    #endif

    /* Check if source file and Flexio_Pwm_Ip.h file are of the same Software version */
    #if ((PWM_IPW_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_SW_MAJOR_VERSION)  || \
         (PWM_IPW_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_SW_MINOR_VERSION)  || \
         (PWM_IPW_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_SW_PATCH_VERSION))
        #error "Software version numbers of Pwm_Ipw.c and Flexio_Pwm_Ip.h are different."
    #endif

    /* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same vendor */
    #if (PWM_IPW_VENDOR_ID_C != FLEXIO_PWM_IP_HWACCESS_VENDOR_ID)
        #error "Vendor IDs of Pwm_Ipw.c and Flexio_Pwm_Ip_HwAccess.h are different."
    #endif

    /* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same AUTOSAR version */
    #if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR version numbers of Pwm_Ipw.c and Flexio_Pwm_Ip_HwAccess.h are different."
    #endif

    /* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same Software version */
    #if ((PWM_IPW_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
         (PWM_IPW_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
         (PWM_IPW_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_PATCH_VERSION))
        #error "Software version numbers of Pwm_Ipw.c and Flexio_Pwm_Ip_HwAccess.h are different."
    #endif
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    /* Check if source file and FlexPwm_Ip.h file are of the same vendor */
    #if (PWM_IPW_VENDOR_ID_C != FLEXPWM_IP_VENDOR_ID)
        #error "Vendor IDs of Pwm_Ipw.c and FlexPwm_Ip.h are different."
    #endif

    /* Check if source file and FlexPwm_Ip.h file are of the same AUTOSAR version */
    #if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_AR_RELEASE_MINOR_VERSION) || \
         (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_AR_RELEASE_REVISION_VERSION))
        #error "AUTOSAR version numbers of Pwm_Ipw.c and FlexPwm_Ip.h are different."
    #endif

    /* Check if source file and FlexPwm_Ip.h file are of the same Software version */
    #if ((PWM_IPW_SW_MAJOR_VERSION_C != FLEXPWM_IP_SW_MAJOR_VERSION)  || \
         (PWM_IPW_SW_MINOR_VERSION_C != FLEXPWM_IP_SW_MINOR_VERSION)  || \
         (PWM_IPW_SW_PATCH_VERSION_C != FLEXPWM_IP_SW_PATCH_VERSION))
        #error "Software version numbers of Pwm_Ipw.c and FlexPwm_Ip.h are different."
    #endif
#endif
#if (PWM_ETPU_USED == STD_ON)
/* Check if source file and Eptu_Pwm_Ip.h file are of the same vendor */
#if (PWM_IPW_VENDOR_ID_C != ETPU_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and Etpu_Pwm_Ip.h are different."
#endif

/* Check if source file and Etpu_Pwm_Ip.h file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != ETPU_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != ETPU_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != ETPU_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and Etpu_Pwm_Ip.h are different."
#endif

/* Check if source file and Etpu_Pwm_Ip.h file are of the same Software version */
#if ((PWM_IPW_SW_MAJOR_VERSION_C != ETPU_PWM_IP_SW_MAJOR_VERSION)  || \
     (PWM_IPW_SW_MINOR_VERSION_C != ETPU_PWM_IP_SW_MINOR_VERSION)  || \
     (PWM_IPW_SW_PATCH_VERSION_C != ETPU_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and Etpu_Pwm_Ip.h are different."
#endif
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
#if (PWM_ETPU_USED == STD_ON)
#if (PWM_DE_INIT_API == STD_ON)
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Default setting for instance structure of the Etpu PWM channel */
static const Etpu_Pwm_Ip_InstanceType Etpu_InstanceDefaultSetting =
{
    0U,
    ETPU_PRIORITY_DISABLE,
    ETPU_PWM_POLARITY_ACTIVE_HIGH,
    ETPU_PWM_TIME_BASE_TCR1,
    (uint8)ETPU_PWM_START_MODE_ABSOLUT,
    0U,
    NULL_PTR,
    NULL_PTR,
    {
        NULL_PTR,
        0U
    }
};

/** @brief Default setting for configuration structure of the Etpu PWM channel */
static const Etpu_Pwm_Ip_ConfigType Etpu_ConfigDefaultSetting =
{
    0U,
    0U,
    ETPU_PWM_INTERRUPT_SOURCE_NONE
};

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif /* PWM_DE_INIT_API == STD_ON */
#endif /* PWM_ETPU_USED == STD_ON */

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_16
#endif
#include "Pwm_MemMap.h"

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
#if (PWM_EMIOS_USED == STD_ON)
/** @brief Array to save the duty cycle of the emios channel */
static uint16 Pwm_Ipw_aEmiosDutyCycle[EMIOS_PWM_IP_INSTANCE_COUNT][EMIOS_PWM_IP_CHANNEL_COUNT];
#endif

#if (PWM_FLEXIO_USED == STD_ON)
/** @brief Array to save the duty cycle of the flexio channel */
static uint16 Pwm_Ipw_aFlexioDutyCycle[FLEXIO_PWM_IP_INSTANCE_COUNT][FLEXIO_PWM_IP_CHANNEL_COUNT];
#endif
#endif /* (PWM_GET_CHANNEL_STATE_API == STD_ON) */

#if (PWM_FLEXPWM_USED == STD_ON)
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
/** @brief Array to save the duty cycle of the FlexPwm channel */
static uint16 Pwm_Ipw_aFlexPwmDutyCycle[FLEXPWM_IP_INSTANCE_COUNT_U8][FLEXPWM_IP_UNIQUESUB_COUNT];
#endif
#endif

#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_16
#endif
#include "Pwm_MemMap.h"

#if (PWM_ETPU_USED == STD_ON)
#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"

/** @brief Array to save the instance structures for all Etpu PWM channels */
Etpu_Pwm_Ip_InstanceType Pwm_Ipw_aEtpuInstance[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];
/** @brief Array to save the configuration structures for all Etpu PWM channels */
Etpu_Pwm_Ip_ConfigType Pwm_Ipw_aEtpuConfig[ETPU_PWM_IP_ENGINE_COUNT][ETPU_PWM_IP_CHANNEL_COUNT];

#if (PWM_NO_CACHE_NEEDED == STD_ON)
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Pwm_MemMap.h"
#endif /* (PWM_ETPU_USED == STD_ON) */

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
#if (PWM_EMIOS_USED == STD_ON)
static Std_ReturnType Pwm_Ipw_EmiosValidateNotification(Pwm_EdgeNotificationType       Notification,
                                                        const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* (PWM_EMIOS_USED == STD_ON) */
#endif /* ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON)) */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
#if (PWM_ETPU_USED == STD_ON)
static void Pwm_Ipw_Etpu_SetDutyCycle(uint8  Channel, 
                                      uint16 DutyCycle);
#endif /* (PWM_ETPU_USED == STD_ON) */
#endif /* (PWM_SET_DUTY_CYCLE_API == STD_ON) */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
#if (PWM_ETPU_USED == STD_ON)
static Std_ReturnType Pwm_Ipw_Etpu_SetPeriodAndDuty(uint8  Channel, 
                                                    uint32 Period,
                                                    uint16 DutyCycle);
#endif /* (PWM_ETPU_USED == STD_ON) */
#endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
#if (PWM_EMIOS_USED == STD_ON)
static Std_ReturnType Pwm_Ipw_EmiosValidateNotification(Pwm_EdgeNotificationType       Notification,
                                                        const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(
        ((PWM_FALLING_EDGE == Notification) && (EMIOS_PWM_IP_ACTIVE_LOW == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->OutputPolarity)) ||
        ((PWM_RISING_EDGE == Notification) && (EMIOS_PWM_IP_ACTIVE_HIGH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->OutputPolarity))
      )
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        switch(((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode)
        {
            case EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH:
                RetVal = (PWM_BOTH_EDGES == Notification)? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK;
                break;
            case EMIOS_PWM_IP_MODE_OPWFMB_FLAG:
            case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWMB_FLAG:
            case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_DAOC_FLAG:
                RetVal = (PWM_BOTH_EDGES == Notification)? (Std_ReturnType)E_NOT_OK : (Std_ReturnType)E_OK;
                break;
            default:
                /* Do Nothing */
                break;
        }
    }
    return RetVal;
}
#endif /* (PWM_EMIOS_USED == STD_ON) */
#endif /* ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON)) */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
#if (PWM_ETPU_USED == STD_ON)
static void Pwm_Ipw_Etpu_SetDutyCycle(uint8  Channel, 
                                      uint16 DutyCycle)
{
    uint8 EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE(Channel);
    uint8 EtpuChannel = (uint8)Etpu_Ip_GetChannel(Channel);

    Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].u16DutyCycle = DutyCycle;

    /* Call Etpu api for updating the duty cycle */
#if (PWM_DUTYCYCLE_UPDATED_ENDPERIOD == STD_ON)
    Etpu_Pwm_Ip_UpdateDuty(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                           &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);
#else
    Etpu_Pwm_Ip_UpdateDutyImmed(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);
#endif

    if (0x00U == (uint8)(Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel].u8StartMode & (uint8)ETPU_PWM_IP_ENABLE_FLAG))
    {
        Etpu_Pwm_Ip_Start(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel]);
    }   
}
#endif /* (PWM_ETPU_USED == STD_ON) */
#endif /* (PWM_SET_DUTY_CYCLE_API == STD_ON) */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
#if (PWM_ETPU_USED == STD_ON)
static Std_ReturnType Pwm_Ipw_Etpu_SetPeriodAndDuty(uint8  Channel, 
                                                    uint32 Period,
                                                    uint16 DutyCycle)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint8 EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE(Channel);
    uint8 EtpuChannel = (uint8)Etpu_Ip_GetChannel(Channel);

    Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].u24Period = Period;
    Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].u16DutyCycle = DutyCycle;


    RetVal = (Std_ReturnType)Etpu_Pwm_Ip_Update(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                                &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);

    if (0x00U == (uint8)(Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel].u8StartMode & (uint8)ETPU_PWM_IP_ENABLE_FLAG))
    {
        Etpu_Pwm_Ip_Start(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel]);
    }

    return RetVal;
}
#endif /* (PWM_ETPU_USED == STD_ON) */
#endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

#if (PWM_FLEXPWM_USED == STD_ON)
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON)))
static inline uint8 Pwm_Ipw_GetUniqueSubModule(uint8 SubModule, FlexPwm_Ip_ChannelTypes ChannelTypes)
{
    uint8 UniqueSub = 0U;
    switch(ChannelTypes)
    {
        case FLEXPWM_IP_PWMX:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 0U);
            break;
        case FLEXPWM_IP_PWMA:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 1U);
            break;
        case FLEXPWM_IP_PWMB:
            UniqueSub = (uint8)((SubModule * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE_U8) + 2U);
            break;
        default:
            /* Do Nothing */
            break;
    }
    return UniqueSub;
}
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
static inline uint8 Pwm_Ipw_GetInterruptMask(FlexPwm_Ip_ChannelTypes ChannelTypes, FlexPwm_Ip_PolarityTypes Polarity, Pwm_EdgeNotificationType NotifTypes)
{
    uint8 InterruptMask = 0U;
    switch(ChannelTypes)
    {
        case FLEXPWM_IP_PWMX:
            if (PWM_RISING_EDGE == NotifTypes)
            {
                InterruptMask = (FLEXPWM_IP_POL_HIGH == Polarity) ? 0x01U : 0x02U;
            }
            else if (PWM_FALLING_EDGE == NotifTypes)
            {
                InterruptMask = (FLEXPWM_IP_POL_HIGH == Polarity) ? 0x02U : 0x01U;
            }
            else if (PWM_BOTH_EDGES == NotifTypes)
            {
                InterruptMask = 0x03U;
            }
            else
            {
                /* Do Nothing */
            }
            break;
        case FLEXPWM_IP_PWMA:
            if (PWM_RISING_EDGE == NotifTypes)
            {
                InterruptMask = (FLEXPWM_IP_POL_HIGH == Polarity) ? 0x04U : 0x08U;
            }
            else if (PWM_FALLING_EDGE == NotifTypes)
            {
                InterruptMask = (FLEXPWM_IP_POL_HIGH == Polarity) ? 0x08U : 0x04U;
            }
            else if (PWM_BOTH_EDGES == NotifTypes)
            {
                InterruptMask = 0x0CU;
            }
            else
            {
                /* Do Nothing */
            }

            break;
        case FLEXPWM_IP_PWMB:
            if (PWM_RISING_EDGE == NotifTypes)
            {
                InterruptMask = (FLEXPWM_IP_POL_HIGH == Polarity) ? 0x10U : 0x20U;
            }
            else if (PWM_FALLING_EDGE == NotifTypes)
            {
                InterruptMask = (FLEXPWM_IP_POL_HIGH == Polarity) ? 0x20U : 0x10U;
            }
            else if (PWM_BOTH_EDGES == NotifTypes)
            {
                InterruptMask = 0x30U;
            }
            else
            {
                /* Do Nothing */
            }

            break;
        default:
            /* Do Nothing */
            break;
    }
    return InterruptMask;
}
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */
#endif /* (PWM_FLEXPWM_USED == STD_ON) */
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Pwm_Ipw_Init
* @details      This function call the supported IP initialization functions.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_Init(const Pwm_IpwChannelConfigType * const IpConfig)
{
#if (PWM_FLEXPWM_USED == STD_ON)
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
#endif
#if (PWM_ETPU_USED == STD_ON)
    uint8 EtpuEngine = 0U;
    uint8 EtpuChannel = 0U;
#endif
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            if (NULL_PTR != IpConfig->EmiosChConfig)
            {
                /* Call Emios IP initialize function */
                Emios_Pwm_Ip_InitChannel(IpConfig->ChannelInstanceId, (const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                /* Duty cycle of Emios Ip */
                Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = IpConfig->ChannelDutyCycle;
#endif
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            if (NULL_PTR != IpConfig->FlexioChConfig)
            {
                /* Call Flexio IP initialize function */
                (void)Flexio_Pwm_Ip_InitChannel(IpConfig->ChannelInstanceId, (const Flexio_Pwm_Ip_ChannelConfigType *)IpConfig->FlexioChConfig);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                /* Duty cycle of Flexio Ip */
                Pwm_Ipw_aFlexioDutyCycle[IpConfig->ChannelInstanceId][(IpConfig->FlexioChConfig)->TimerId] = IpConfig->ChannelDutyCycle;
#endif
            }
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            if (NULL_PTR != IpConfig->FlexPwmChConfig)
            {
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
                UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
                /* Duty cycle of FlexPwm Ip */
                Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = IpConfig->ChannelDutyCycle;
#endif
            }
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            if ((NULL_PTR != IpConfig->EtpuPwmInstance) && (NULL_PTR != IpConfig->EtpuChConfig))
            {
                EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel);
                EtpuChannel = (uint8)Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel);

                Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel] = *(const Etpu_Pwm_Ip_InstanceType *)IpConfig->EtpuPwmInstance;
                Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel] = *(const Etpu_Pwm_Ip_ConfigType *)IpConfig->EtpuChConfig;

                (void)Etpu_Pwm_Ip_Init(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                       &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
}

/*=============================================================================================*/
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
void Pwm_Ipw_InitInstance(const Pwm_IpwInstanceConfigType * const IpConfig)
{

    switch(IpConfig->InstanceType)
    {
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_INSTANCE_FLEXPWM:
            if (NULL_PTR != IpConfig->FlexPwmInsConfig)
            {
                /* Call FlexPwm IP initialize instances */
                FlexPwm_Ip_Init(IpConfig->InstanceId, (const FlexPwm_Ip_InstanceCfgTypes *)IpConfig->FlexPwmInsConfig);
            }
            break;
#endif
        case PWM_INSTANCE_NONE:
            /* Nothing to do. No hw channel assigned to the logical channel */
            break;
        default:
            /* Nothing to do. */
            break;
    }
}
#endif /* PWM_HW_INSTANCE_USED == STD_ON */

/*===============================================================================================*/
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
void Pwm_Ipw_DeInit(const Pwm_IpwChannelConfigType * const IpConfig, Pwm_OutputStateType ChannelIdleState)
{
#if (PWM_FLEXPWM_USED == STD_ON)
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
    FlexPwm_Ip_OutputStateTypes FlexPwmChState = (PWM_HIGH == ChannelIdleState) ? FLEXPWM_IP_OUT_HIGH : FLEXPWM_IP_OUT_LOW;
#endif
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_OutputStateType EmiosChState = EMIOS_PWM_IP_OUTPUT_STATE_LOW;
    /* Idle state is true when requested level is PWM_HIGH*/
    EmiosChState = (PWM_HIGH == ChannelIdleState) ? EMIOS_PWM_IP_OUTPUT_STATE_HIGH : EMIOS_PWM_IP_OUTPUT_STATE_LOW;
#endif
#if (PWM_ETPU_USED == STD_ON)
    uint8 EtpuEngine = 0U;
    uint8 EtpuChannel = 0U;
#endif
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            if (NULL_PTR != IpConfig->EmiosChConfig)
            {
                Emios_Pwm_Ip_DeInitChannel(IpConfig->ChannelInstanceId, ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
                /* Set output to Idle state */
                Emios_Pwm_Ip_SetOutputState(IpConfig->ChannelInstanceId,
                                           ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                           EmiosChState);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = 0U;
#endif
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            if (NULL_PTR != IpConfig->FlexioChConfig)
            {
                (void)Flexio_Pwm_Ip_DeInitChannel(IpConfig->ChannelInstanceId, ((const Flexio_Pwm_Ip_ChannelConfigType *)IpConfig->FlexioChConfig)->TimerId);
#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON))
                /* Set output to Idle state */
                (void)Flexio_Pwm_Ip_ForceOuputLevel(IpConfig->ChannelInstanceId,
                                                    IpConfig->FlexioChConfig->TimerId,
                                                    (PWM_HIGH == ChannelIdleState));
#else
                (void)ChannelIdleState;
#endif

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
                /* Duty cycle of Flexio Ip */
                Pwm_Ipw_aFlexioDutyCycle[IpConfig->ChannelInstanceId][(IpConfig->FlexioChConfig)->TimerId] = 0U;
#endif
            }
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            if (NULL_PTR != IpConfig->FlexPwmChConfig)
            {
                FlexPwm_Ip_OverwriteOutputChannels(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                                ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                                FlexPwmChState);
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
                UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
                /* Duty cycle of FlexPwm Ip */
                Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = 0U;
#endif
            }
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            if ((NULL_PTR != IpConfig->EtpuPwmInstance) && (NULL_PTR != IpConfig->EtpuChConfig))
            {
                EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel);
                EtpuChannel = (uint8)Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel);

                Etpu_Pwm_Ip_DeInit(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                   (PWM_HIGH == ChannelIdleState) ? ETPU_PIN_HIGH : ETPU_PIN_LOW);

                /* Set configuration parameters of EtpuPwm Ip channel to default values */
                Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel] = Etpu_InstanceDefaultSetting;
                Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel] = Etpu_ConfigDefaultSetting;
            }
            break;
#endif
        default:
            /* Nothing to do. */
            (void)ChannelIdleState;
            break;
    }
}

/*===============================================================================================*/
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
void Pwm_Ipw_DeInitInstance(const Pwm_IpwInstanceConfigType * const IpConfig)
{

    switch(IpConfig->InstanceType)
    {
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_INSTANCE_FLEXPWM:
            if (NULL_PTR != IpConfig->FlexPwmInsConfig)
            {
                /* Call FlexPwm IP de-initialize instances */
                FlexPwm_Ip_DeInit(IpConfig->InstanceId);
            }
            break;
#endif
        case PWM_INSTANCE_NONE:
            /* Nothing to do. No hw instance assigned to the logical instance */
            break;
        default:
            /* Nothing to do. */
            break;
    }
}
#endif
#endif /* PWM_DE_INIT_API */

/*===============================================================================================*/
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
                                    const Pwm_IpwChannelConfigType * const IpConfig)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Pwm_Ipw_PeriodType EmiosChPeriod = 0U;
    Pwm_Ipw_DutyType EmiosChDuty = 0U;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    uint16 FlexPwmChDuty = 0U;
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
#endif
#if (PWM_FLEXIO_USED == STD_ON)
    uint16 FlexioChDuty = 0U;
    uint16 FlexioPeriod = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Get the period of the chanel  */
            EmiosChPeriod = Emios_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                                  ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint64)EmiosChPeriod * DutyCycle) / 0x8000U);
#else
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint32)EmiosChPeriod * DutyCycle) / 0x8000U);
#endif
            /* Call Emios api for setting the polarity and mode */
            Emios_Pwm_Ip_SetOutputToNormal(IpConfig->ChannelInstanceId,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                            DutyCycle,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->OutputPolarity,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode
                                           );
            /* Call Emios IP function */
            RetVal = (Std_ReturnType)Emios_Pwm_Ip_SetDutyCycle(IpConfig->ChannelInstanceId,
                                                               ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                               EmiosChDuty);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = DutyCycle;
#endif
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            FlexioPeriod = Flexio_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                                   IpConfig->FlexioChConfig->TimerId);
            /* Calculate new duty value in ticks */
            FlexioChDuty = (uint16)(((uint32)FlexioPeriod * DutyCycle)/0x8000U);
            /* Call Flexio api for setting the period and duty cycle */
            (void)Flexio_Pwm_Ip_UpdatePeriodDuty(IpConfig->ChannelInstanceId,
                                                 IpConfig->FlexioChConfig->TimerId,
                                                 FlexioPeriod,
                                                 FlexioChDuty);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            /* Duty cycle of Flexio Ip */
            Pwm_Ipw_aFlexioDutyCycle[IpConfig->ChannelInstanceId][(IpConfig->FlexioChConfig)->TimerId] = DutyCycle;
#endif
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            FlexPwm_Ip_ClearLoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId);
            /* Calculate the duty cycle in ticks */
            FlexPwmChDuty = (uint16)(((uint32)FlexPwm_Ip_aPeriod[IpConfig->ChannelInstanceId][IpConfig->SubModuleId] * DutyCycle) / 0x8000U);
            /* Call FlexPwm IP function */
            FlexPwm_Ip_UpdateDutyCycle(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                       ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                       FlexPwmChDuty);
            /* Set LDOK bit for configured submodule */
#if (PWM_DUTYCYCLE_UPDATED_ENDPERIOD == STD_ON)
                FlexPwm_Ip_LoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId, FALSE);
#else
                FlexPwm_Ip_LoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId, TRUE);
#endif
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = DutyCycle;
#endif
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            Pwm_Ipw_Etpu_SetDutyCycle(((const Etpu_Pwm_Ip_InstanceType *)IpConfig->EtpuPwmInstance)->u8Channel, DutyCycle);
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) DutyCycle;
            (void) IpConfig;
            break;
    }

    return RetVal;
}
#endif /* PWM_SET_DUTY_CYCLE_API */

/*===============================================================================================*/
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
*
*/
Std_ReturnType Pwm_Ipw_SetPeriodAndDuty(Pwm_Ipw_PeriodType              Period,
                                        uint16                          DutyCycle,
                                        const Pwm_IpwChannelConfigType * const IpConfig)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_StatusType EmiosStatusType = (Emios_Pwm_Ip_StatusType)EMIOS_PWM_IP_STATUS_SUCCESS;
    Pwm_Ipw_DutyType EmiosChDuty = 0U;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    uint16 FlexPwmChDuty = 0U;
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
#endif
#if (PWM_FLEXIO_USED == STD_ON)
    Flexio_Pwm_Ip_StatusType FlexioStatusType = (Flexio_Pwm_Ip_StatusType)FLEXIO_PWM_IP_STATUS_SUCCESS;
    uint16 FlexioChDuty = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call Emios api for setting the period */
            Emios_Pwm_Ip_SetPeriod(IpConfig->ChannelInstanceId,
                                   ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                   Period);

            /* Calculate new duty value in ticks */
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint64)Period * DutyCycle)/0x8000U);
#else
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint32)Period * DutyCycle)/0x8000U);
#endif
            /* Call Emios api for setting the polarity and mode */
            Emios_Pwm_Ip_SetOutputToNormal(IpConfig->ChannelInstanceId,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                            DutyCycle,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->OutputPolarity,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode
                                           );
            /* Call Emios api for setting the duty cycle */
            EmiosStatusType = Emios_Pwm_Ip_SetDutyCycle(IpConfig->ChannelInstanceId,
                                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                        EmiosChDuty);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = DutyCycle;
#endif
            if (EMIOS_PWM_IP_STATUS_SUCCESS != EmiosStatusType)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Calculate new duty value in ticks */
            FlexioChDuty = (uint16)(((uint32)Period * DutyCycle)/0x8000U);
            /* Call Flexio api for setting the period */
            FlexioStatusType = Flexio_Pwm_Ip_UpdatePeriodDuty(IpConfig->ChannelInstanceId,
                                                              IpConfig->FlexioChConfig->TimerId,
                                                              (uint16)Period,
                                                              FlexioChDuty);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            /* Duty cycle of Flexio Ip */
            Pwm_Ipw_aFlexioDutyCycle[IpConfig->ChannelInstanceId][(IpConfig->FlexioChConfig)->TimerId] = DutyCycle;
#endif

            if (FLEXIO_PWM_IP_STATUS_SUCCESS != FlexioStatusType)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            FlexPwm_Ip_ClearLoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId);
            /* Call FlexPwm api for setting the period */
            FlexPwm_Ip_UpdatePeriod(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, (uint16)Period);
                                                  
            FlexPwmChDuty = (uint16)(((uint32)Period * DutyCycle) / 0x8000U);
            /* Call FlexPwm IP function */
            FlexPwm_Ip_UpdateDutyCycle(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                       ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                       FlexPwmChDuty);
#if (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON)
                FlexPwm_Ip_LoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId, FALSE);
#else
                FlexPwm_Ip_LoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId, TRUE);
#endif
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = DutyCycle;
#endif
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            RetVal =  Pwm_Ipw_Etpu_SetPeriodAndDuty(((const Etpu_Pwm_Ip_InstanceType *)IpConfig->EtpuPwmInstance)->u8Channel, (uint32)Period, DutyCycle);
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) Period;
            (void) DutyCycle;
            (void) IpConfig;
            break;
    }

    return RetVal;
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */

/*===============================================================================================*/
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
void Pwm_Ipw_SetOutputToIdle(const Pwm_OutputStateType IdleState, const Pwm_IpwChannelConfigType * const IpConfig)
{
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_OutputStateType EmiosChState = EMIOS_PWM_IP_OUTPUT_STATE_LOW;
    /* Idle state is true when requested level is PWM_HIGH*/
    EmiosChState = (PWM_HIGH == IdleState) ? EMIOS_PWM_IP_OUTPUT_STATE_HIGH : EMIOS_PWM_IP_OUTPUT_STATE_LOW;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    FlexPwm_Ip_OutputStateTypes FlexPwmChState = (PWM_HIGH == IdleState) ? FLEXPWM_IP_OUT_HIGH : FLEXPWM_IP_OUT_LOW;
#endif
#if (PWM_ETPU_USED == STD_ON)
    uint8 EtpuEngine = 0U;
    uint8 EtpuChannel = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            Emios_Pwm_Ip_SetOutputState(IpConfig->ChannelInstanceId,
                                       ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        EmiosChState);
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (FLEXIO_PWM_IP_HAS_PIN_OVERRIDE == STD_ON))
            (void)Flexio_Pwm_Ip_ForceOuputLevel(IpConfig->ChannelInstanceId,
                                          IpConfig->FlexioChConfig->TimerId,
                                          (PWM_HIGH == IdleState));
#else
            (void) IdleState;
#endif
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            FlexPwm_Ip_OverwriteOutputChannels(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                                ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                                FlexPwmChState);
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel);
            EtpuChannel = (uint8)Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel);

            Etpu_Pwm_Ip_StopAndSetPin(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                      (PWM_HIGH == IdleState) ? ETPU_PIN_HIGH : ETPU_PIN_LOW);              

            Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].u16DutyCycle = 0U;

            Etpu_Pwm_Ip_UpdateDutyImmed(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                        &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) IdleState;
            break;
    }
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

/*===============================================================================================*/
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
Pwm_OutputStateType Pwm_Ipw_GetOutputState(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Store return value */
    Pwm_OutputStateType RetVal = PWM_LOW;

#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_OutputStateType EmiosChState = EMIOS_PWM_IP_OUTPUT_STATE_LOW;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
    boolean FlexioChState = FALSE;
#endif
#if (PWM_ETPU_USED == STD_ON)
    Etpu_Ip_PinStateType EtpuChState = ETPU_PIN_LOW;
#endif

#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXIO_USED == STD_ON) || (PWM_ETPU_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
        /* Call Emios IP function */
            EmiosChState = Emios_Pwm_Ip_GetOutputState(IpConfig->ChannelInstanceId,
                                                      ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);

            if (EMIOS_PWM_IP_OUTPUT_STATE_LOW == EmiosChState)
            {
                RetVal = PWM_LOW;
            }
            else
            {
                RetVal = PWM_HIGH;
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Call Flexio IP function */
            FlexioChState = Flexio_Pwm_Ip_GetOutputState(IpConfig->ChannelInstanceId,
                                                         IpConfig->FlexioChConfig->TimerId);

            if (TRUE == FlexioChState)
            {
                RetVal = PWM_HIGH;
            }
            else
            {
                RetVal = PWM_LOW;
            }
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            /* Call Etpu IP function */
            EtpuChState = Etpu_Ip_GetOutputState(Pwm_Ipw_aEtpuInstance[ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel)][Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel)].u8Channel);

            if (ETPU_PIN_LOW == EtpuChState)
            {
                RetVal = PWM_LOW;
            }
            else
            {
                RetVal = PWM_HIGH;
            }
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
#else
    (void) IpConfig;
#endif    

    return RetVal;
    }
#endif /* PWM_GET_OUTPUT_STATE_API */

/*===============================================================================================*/
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
void Pwm_Ipw_DisableNotification(const Pwm_IpwChannelConfigType * const IpConfig)
{
#if (PWM_FLEXPWM_USED == STD_ON)
    uint8 IntMask = 0U;
#endif
#if (PWM_ETPU_USED == STD_ON)
    uint8 EtpuEngine = 0U;
    uint8 EtpuChannel = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call Emios IP function */
            if((EMIOS_PWM_IP_MODE_DAOC_FLAG != ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) &&
               (EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH != ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode))
            {
                Emios_Pwm_Ip_SetFlagRequest(IpConfig->ChannelInstanceId,
                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                            EMIOS_PWM_IP_NOTIFICATION_DISABLED);
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Call Flexio IP function */
            (void)Flexio_Pwm_Ip_UpdateInterruptMode(IpConfig->ChannelInstanceId,
                                              IpConfig->FlexioChConfig->TimerId,
                                              FLEXIO_PWM_IP_IRQ_DISABLED);
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            IntMask = Pwm_Ipw_GetInterruptMask(((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                              ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->Polarity,
                                               PWM_BOTH_EDGES);
            if (0U != IntMask)
            {
                /* Call FlexPwm IP function */
                FlexPwm_Ip_DisableInterrupt(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, FLEXPWM_IP_COMPARE_INT, IntMask);
                /* Clear interrupt flag*/
                FlexPwm_Ip_ClearInterruptFlag(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, FLEXPWM_IP_COMPARE_INT, IntMask);
            }
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel);
            EtpuChannel = (uint8)Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel);

            Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].eInterruptSource = ETPU_PWM_INTERRUPT_SOURCE_NONE;

            Etpu_Pwm_Ip_UpdateInterruptMode(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                            &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) IpConfig;
            break;
    }

}
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
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
                                const Pwm_IpwChannelConfigType * const IpConfig)
{
#if (PWM_FLEXPWM_USED == STD_ON)
    uint8 IntMask = 0U;
#endif
#if (PWM_ETPU_USED == STD_ON)
    Etpu_Pwm_Ip_PolarityType EtpuCurrentPolarity = ((const Etpu_Pwm_Ip_InstanceType *)IpConfig->EtpuPwmInstance)->ePolarity;
    uint8 EtpuEngine = 0U;
    uint8 EtpuChannel = 0U;
#endif
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call Emios IP function */
            if(EMIOS_PWM_IP_MODE_GPO != ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode)
            {
                Emios_Pwm_Ip_SetFlagRequest(IpConfig->ChannelInstanceId,
                                           ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                            EMIOS_PWM_IP_INTERRUPT_REQUEST);
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Call Flexio IP function */
            switch (Notification)
            {
                case PWM_RISING_EDGE:
                    (void)Flexio_Pwm_Ip_UpdateInterruptMode(IpConfig->ChannelInstanceId,
                                                      IpConfig->FlexioChConfig->TimerId,
                                                      FLEXIO_PWM_IP_IRQ_ON_RISING_EDGE);
                    break;
                case PWM_FALLING_EDGE:
                    (void)Flexio_Pwm_Ip_UpdateInterruptMode(IpConfig->ChannelInstanceId,
                                                      IpConfig->FlexioChConfig->TimerId,
                                                      FLEXIO_PWM_IP_IRQ_ON_FALLING_EDGE);
                    break;
                case PWM_BOTH_EDGES:
                    (void)Flexio_Pwm_Ip_UpdateInterruptMode(IpConfig->ChannelInstanceId,
                                                      IpConfig->FlexioChConfig->TimerId,
                                                      FLEXIO_PWM_IP_IRQ_ON_BOTH_EDGES);
                    break;
                default:
                    /* Noting to do */
                    break;
            }
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            IntMask = Pwm_Ipw_GetInterruptMask(((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                              ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->Polarity,
                                               Notification);
            if (0U != IntMask)
            {
                /* Clear interrupt flag*/
                FlexPwm_Ip_ClearInterruptFlag(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, FLEXPWM_IP_COMPARE_INT, IntMask);
                /* Call FlexPwm IP function */
                FlexPwm_Ip_EnableInterrupt(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, FLEXPWM_IP_COMPARE_INT, IntMask);
            }
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            EtpuEngine = (uint8)ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel);
            EtpuChannel = (uint8)Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel);

            switch (Notification)
            {
                case PWM_RISING_EDGE:
                    if (ETPU_PWM_POLARITY_ACTIVE_HIGH == EtpuCurrentPolarity)
                    {
                        Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].eInterruptSource = ETPU_PWM_INTERRUPT_SOURCE_FRAME_EDGE;
                    }
                    else
                    {
                        Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].eInterruptSource = ETPU_PWM_INTERRUPT_SOURCE_ACTIVE_EDGE;
                    }
                    break;
                case PWM_FALLING_EDGE:
                    if (ETPU_PWM_POLARITY_ACTIVE_HIGH == EtpuCurrentPolarity)
                    {
                        Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].eInterruptSource = ETPU_PWM_INTERRUPT_SOURCE_ACTIVE_EDGE;
                    }
                    else
                    {
                        Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].eInterruptSource = ETPU_PWM_INTERRUPT_SOURCE_FRAME_EDGE;
                    }
                    break;
                case PWM_BOTH_EDGES:
                    Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel].eInterruptSource = ETPU_PWM_INTERRUPT_SOURCE_BOTH_EDGES;
                    break;
                default:
                    /* Noting to do */
                    break;
            }

            Etpu_Ip_ClearChannelInterruptFlag(Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel].u8Channel);

            Etpu_Pwm_Ip_UpdateInterruptMode(&Pwm_Ipw_aEtpuInstance[EtpuEngine][EtpuChannel],
                                            &Pwm_Ipw_aEtpuConfig[EtpuEngine][EtpuChannel]);
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void)Notification;
            break;
    }
}
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
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
uint16 Pwm_Ipw_GetChannelState(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Store return value */
    uint16 DutyCycle = (uint16)0U;
#if (PWM_FLEXPWM_USED == STD_ON)
    uint8 UniqueSub = 0U;
#endif
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call Emios IP function */
            if(EMIOS_PWM_IP_MODE_GPO != ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode)
            {
                DutyCycle = Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId];
            }
            else
            {
                DutyCycle = 0U;
            }

            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Get Duty cycle of Flexio Ip */
            DutyCycle =  Pwm_Ipw_aFlexioDutyCycle[IpConfig->ChannelInstanceId][(IpConfig->FlexioChConfig)->TimerId];
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            /* Call FlexPwm IP function */
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            DutyCycle = Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub];
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            DutyCycle = Pwm_Ipw_aEtpuConfig[ETPU_PWM_IP_GET_ENGINE((IpConfig->EtpuPwmInstance)->u8Channel)][Etpu_Ip_GetChannel((IpConfig->EtpuPwmInstance)->u8Channel)].u16DutyCycle;
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) DutyCycle;
            (void) IpConfig;
            break;
    }

    return DutyCycle;
}
#endif /* PWM_GET_CHANNEL_STATE */

/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockModeChannel
* @details      This function will call SetClockMode function of all configured hardware channels.
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockModeChannel(Pwm_PrescalerType              Prescaler,
                                 const Pwm_IpwChannelConfigType * const IpConfig)
{
#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXIO_USED == STD_ON))    
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            if(PWM_PRIMARY_PRESCALER == Prescaler)
            {
                Emios_Pwm_Ip_SetClockPs(IpConfig->ChannelInstanceId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->InternalPs
                                        );
            }
            else
            {
                Emios_Pwm_Ip_SetClockPs(IpConfig->ChannelInstanceId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->InternalPsAlt
                                        );
            }
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            if(PWM_PRIMARY_PRESCALER == Prescaler)
            {
                (void)Flexio_Pwm_Ip_UpdateClockPrescaler(IpConfig->ChannelInstanceId,
                                                   IpConfig->FlexioChConfig->TimerId,
                                                   IpConfig->FlexioChConfig->Prescaler
                                                  );
            }
            else
            {
                (void)Flexio_Pwm_Ip_UpdateClockPrescaler(IpConfig->ChannelInstanceId,
                                                   IpConfig->FlexioChConfig->TimerId,
                                                   IpConfig->FlexioAlternateClk
                                                  );
            }
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) IpConfig;
            (void) Prescaler;
            break;
    }
#else
    (void) IpConfig;
    (void) Prescaler;
#endif
}

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockModeInstance
* @details      This function will call SetClockMode function of all configured hardware modules.
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM instance configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockModeInstance(Pwm_PrescalerType              Prescaler,
                                  const Pwm_IpwInstanceConfigType * const IpConfig)
{
#if (PWM_FLEXPWM_USED == STD_ON)
    FlexPwm_Ip_PrescalerModeTypes FlexPwmPrescaler;

    if (PWM_PRIMARY_PRESCALER == Prescaler)
    {
        FlexPwmPrescaler = FLEXPWM_IP_PRIMARY_PRESCALER;
    }
    else
    {
        FlexPwmPrescaler = FLEXPWM_IP_ALTERNATIVE_PRESCALER;
    }
#endif
    switch(IpConfig->InstanceType)
    {
        case PWM_INSTANCE_FLEXPWM:
#if (PWM_FLEXPWM_USED == STD_ON)
            FlexPwm_Ip_SetClockPs(IpConfig->InstanceId,
                                 (const FlexPwm_Ip_InstanceCfgTypes *)IpConfig->FlexPwmInsConfig,
                                  FlexPwmPrescaler);
#endif
            break;
        default:
            /* Nothing to do. */
            break;
    }
    /* Avoid compiler warning */
    (void)Prescaler;
}
#endif /* PWM_HW_INSTANCE_USED */
#endif /* PWM_SET_CLOCK_MODE_API */

/*===============================================================================================*/
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
                           const Pwm_IpwChannelConfigType * const IpConfig)
{
    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        if (0x00U == Bus)
        {
            Emios_Pwm_Ip_SetBusSelected(IpConfig->ChannelInstanceId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        EMIOS_PWM_IP_BUS_A);
        }
        else if (0x01U == Bus)
        {
            Emios_Pwm_Ip_SetBusSelected(IpConfig->ChannelInstanceId,
                                       ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                       EMIOS_PWM_IP_BUS_BCDE);
        }
        else
        {
            Emios_Pwm_Ip_SetBusSelected(IpConfig->ChannelInstanceId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        EMIOS_PWM_IP_BUS_F);
        }
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)Bus;
    }
}
#endif /* PWM_SET_COUNTER_BUS_API */

/*===============================================================================================*/
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
                              const Pwm_IpwChannelConfigType * const IpConfig)
{
    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        if ((EMIOS_PWM_IP_MODE_OPWFMB_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode)
            )
        {
            if(PWM_EMIOS_ACTIVE == State)
            {
                /* Call Emios IP Force match on trailing edge */
                Emios_Pwm_Ip_ForceMatchTrailingEdge(IpConfig->ChannelInstanceId,
                                                ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                TRUE);
            }
            else if(PWM_EMIOS_INACTIVE == State)
            {
                /* Call Emios IP Force match on leading edge */
                Emios_Pwm_Ip_ForceMatchLeadingEdge(IpConfig->ChannelInstanceId,
                                                ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                TRUE);
            }
            else
            {
                /* Do nothing */
            }
        }
        else if ((EMIOS_PWM_IP_MODE_DAOC_FLAG != ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) &&
                 (EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH != ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode)
                 )
        {
            if(PWM_EMIOS_ACTIVE == State)
            {
                /* Call Emios IP Force match on leading edge */
                Emios_Pwm_Ip_ForceMatchLeadingEdge(IpConfig->ChannelInstanceId,
                                                ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                TRUE);
            }
            else if(PWM_EMIOS_INACTIVE == State)
            {
                /* Call Emios IP Force match on trailing edge */
                Emios_Pwm_Ip_ForceMatchTrailingEdge(IpConfig->ChannelInstanceId,
                                                ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                TRUE);

            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
            /* Pwm_SetChannelOutput does not support DAOC mode */
        }
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)State;
    }
}
#endif /* PWM_SET_CHANNEL_OUTPUT_API */

/*===============================================================================================*/
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
                             const Pwm_IpwChannelConfigType * const IpConfig)
{
    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        /* Call eMIOS IP function */
        Emios_Pwm_Ip_SetTriggerPlacement(IpConfig->ChannelInstanceId,
                                        ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        TriggerDelay);
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)TriggerDelay;
    }
}
#endif /* PWM_SET_TRIGGER_DELAY_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        Implementation specific function to write a value into UCRegA register.
* @details      This function may be used to change duty cycle and phase shift 
*               with minimum overhead.
*
* @param[in]    Value          Value to write in register
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateSetUCRegA(Pwm_Ipw_PeriodType Value, const Pwm_IpwChannelConfigType * const IpConfig)
{
    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        /* Call eMIOS IP function */
        Emios_Pwm_Ip_UpdateUCRegA(IpConfig->ChannelInstanceId,
                                 ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                 (Emios_Pwm_Ip_PeriodType)Value);
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)Value;
    }
}
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        Implementation specific function to write a value into UCRegB register.
* @details      This function  may be used to change duty cycle, phase shift or
*               inserted dead time buffer with minimum overhead.
*
* @param[in]    Value          Value to write in register
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateSetUCRegB(Pwm_Ipw_PeriodType Value, const Pwm_IpwChannelConfigType * const IpConfig)
{
    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        /* Call eMIOS IP function */
        Emios_Pwm_Ip_UpdateUCRegB(IpConfig->ChannelInstanceId,
                                 ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                 (Emios_Pwm_Ip_PeriodType)Value);
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)Value;
    }
}
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        
* @details      This function shall be used to disable output update for an Emios instance
*
* @param[in]    ModuleId         Pwm hardware module id
* @param[in]    ChannelMask      Bit mask of Emios hardware channels
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateDisableOU(uint8 ModuleId, uint32 ChannelMask)
{

#if (PWM_EMIOS_USED == STD_ON)
    /* Call eMIOS IP function */
    Emios_Pwm_Ip_ComparatorTransferDisable(ModuleId, ChannelMask);
#else
    /* Mitigate parameter not used warnings if Emios Ip is not supported */
    (void)ModuleId;
    (void)ChannelMask;
#endif
}
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        
* @details      This function shall be used to enable output update for an Emios instance
*
* @param[in]    ModuleId         Pwm hardware module id
* @param[in]    ChannelMask      Bit mask of Emios hardware channels
*
* @return       void
*
*/
void Pwm_Ipw_FastUpdateEnableOU(uint8 ModuleId, uint32 ChannelMask)
{

#if (PWM_EMIOS_USED == STD_ON)
    /* Call eMIOS IP function */
    Emios_Pwm_Ip_ComparatorTransferEnable(ModuleId, ChannelMask);
#else
    /* Mitigate parameter not used warnings if Emios Ip is not supported */
    (void)ModuleId;
    (void)ChannelMask;
#endif
}
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
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
void Pwm_Ipw_SetChannelDeadTime(Pwm_Ipw_PeriodType              DeadTimeTicks,
                                const Pwm_IpwChannelConfigType * const IpConfig)
{
#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call eMIOS IP function */
            Emios_Pwm_Ip_SetDeadTime(IpConfig->ChannelInstanceId,
                                     ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                     DeadTimeTicks);
            break;
#endif 
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            /* Call FlexPwm IP function */
            FlexPwm_Ip_SetDeadTime(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, FLEXPWM_IP_DEADTIME_COUNT_0, (uint16)DeadTimeTicks);
            FlexPwm_Ip_SetDeadTime(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, FLEXPWM_IP_DEADTIME_COUNT_1, (uint16)DeadTimeTicks);
            break;
#endif
        default:
            /* Nothing to do */
            /* Avoid compiler warning */
            (void) DeadTimeTicks;
            break;
    }
#else
    (void) IpConfig;
    (void) DeadTimeTicks;
#endif    
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*===============================================================================================*/
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
*                                       TRUE     Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                                       FALSE    Set phase shift and duty cycle value immediately
*
* @return       void
*
*/
void Pwm_Ipw_SetDutyPhaseShift(uint16                           DutyCycle,
                               Pwm_Ipw_DutyType                 PhaseShift,
                               const Pwm_IpwChannelConfigType * const IpConfig,
                               boolean                          SyncUpdate)
{

#if (PWM_EMIOS_USED == STD_ON)
    Pwm_Ipw_DutyType DutyCycleTicks = 0U;
    Pwm_Ipw_PeriodType PeriodChTicks = 0U;
    uint32 ChannelMask = 0U;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    uint16 FlexPwmChDuty = 0U;
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
#endif

#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)        
        case PWM_CHANNEL_EMIOS:
            ChannelMask = (uint32)((uint32)1U << (((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId));

            Emios_Pwm_Ip_ComparatorTransferDisable(IpConfig->ChannelInstanceId,
                                                   ChannelMask);

            PeriodChTicks = Emios_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                                  ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
            /* Call eMIOS IP function */
            (void)Emios_Pwm_Ip_SetPhaseShift(IpConfig->ChannelInstanceId,
                                       ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                        PhaseShift);

            DutyCycleTicks = (Pwm_Ipw_DutyType)(((uint32)PeriodChTicks * DutyCycle) >> 15U);

            (void)Emios_Pwm_Ip_SetDutyCycle(IpConfig->ChannelInstanceId,
                                      ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                       DutyCycleTicks);
            if (SyncUpdate == FALSE)
            {
                Emios_Pwm_Ip_ComparatorTransferEnable(IpConfig->ChannelInstanceId,
                                                      ChannelMask);
            }
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = DutyCycle;
#endif
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            FlexPwm_Ip_ClearLoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId);
            /* Calculate the duty cycle in ticks */
            FlexPwmChDuty = (uint16)(((uint32)FlexPwm_Ip_aPeriod[IpConfig->ChannelInstanceId][IpConfig->SubModuleId] * DutyCycle) / 0x8000U);
            /* Call FlexPwm IP function */
            FlexPwm_Ip_UpdateDutyCycle(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                       ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                       FlexPwmChDuty);

            FlexPwm_Ip_SetPhaseShift(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                     ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                     (uint16)PhaseShift);
            if (SyncUpdate == FALSE)
            {
                FlexPwm_Ip_LoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId, TRUE);
            }
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = DutyCycle; 
#endif

            break;
#endif
        default:
            /* Nothing to do */
            /* Avoid compiler warning */
            (void)PhaseShift;
            (void)DutyCycle;
            (void)SyncUpdate;
            break;
    }
#else
    /* Avoid compiler warning */
    (void)PhaseShift;
    (void)DutyCycle;
    (void)SyncUpdate;  
    (void)IpConfig;   
#endif

}
#endif /* PWM_SET_DUTY_PHASE_SHIFT_API */

/*===============================================================================================*/
#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SYNC_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SyncUpdate
* @details      This function will allow synchronized loading
*               of the value register.
*
* @param[in]    ModuleId        instance ID
*
* @return       void
*
*/
void Pwm_Ipw_SyncUpdate(uint8  ModuleId)
{
#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
#if (PWM_FLEXPWM_USED == STD_ON)
    uint8 SubIndex       = 0U;
    uint8 ActualModuleId = 0U;
#endif
#if (PWM_EMIOS_USED == STD_ON)
    if (ModuleId < PWM_HW_MODULE_EMIOS_NO_U8)
    {
        /* Call eMIOS IP function */
        Emios_Pwm_Ip_SyncUpdate(ModuleId);
    }
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
#if (PWM_EMIOS_USED == STD_ON)
    if ((ModuleId >= (uint8)PWM_HW_MODULE_EMIOS_NO_U8) && (ModuleId < (uint8)(PWM_HW_MODULE_EMIOS_NO_U8 + PWM_HW_MODULE_FLEXPWM_NO_U8)))
#else
    if (ModuleId < PWM_HW_MODULE_FLEXPWM_NO_U8)
#endif
    {
        ActualModuleId = ModuleId - PWM_HW_MODULE_EMIOS_NO_U8;
        for (SubIndex = 0U; SubIndex < FLEXPWM_IP_SUBMODULE_COUNT_U8; SubIndex++)
        {
            if (FLEXPWM_IP_INIT_STATE == FlexPwm_Ip_aSubModuleSate[ActualModuleId][SubIndex])
            {
                /* Set LDOK bit for configured submodule */
                FlexPwm_Ip_LoadValue(ActualModuleId, 1U << SubIndex, TRUE);   
            }
        }
    }
#endif /* (PWM_FLEXPWM_USED == STD_ON) */
#else
/* Avoid compiler warning */
    (void)ModuleId;
#endif /* ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON)) */
}
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SYNC_UPDATE_API */

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_SetDutyCycle_NoUpdate(uint16                               DutyCycle,
                                             const Pwm_IpwChannelConfigType * const IpConfig)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Pwm_Ipw_PeriodType EmiosChPeriod = 0U;
    Pwm_Ipw_DutyType EmiosChDuty = 0U;
    uint32 ChannelMask = 0U;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    uint16 FlexPwmChDuty = 0U;
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
#endif
#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            ChannelMask = (uint32)((uint32)1U << (((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId));

            Emios_Pwm_Ip_ComparatorTransferDisable(IpConfig->ChannelInstanceId,
                                                   ChannelMask);
            /* Get the period of the chanel  */
            EmiosChPeriod = Emios_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                                  ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint64)EmiosChPeriod * DutyCycle) / 0x8000U);
#else
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint32)EmiosChPeriod * DutyCycle) / 0x8000U);
#endif
            /* Call Emios api for setting the polarity and mode */
            Emios_Pwm_Ip_SetOutputToNormal(IpConfig->ChannelInstanceId,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                            DutyCycle,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->OutputPolarity,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode
                                           );            
            /* Call Emios IP function */
            RetVal = (Std_ReturnType)Emios_Pwm_Ip_SetDutyCycle(IpConfig->ChannelInstanceId,
                                                               ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                               EmiosChDuty);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = DutyCycle;
#endif
            break;
#endif

#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            FlexPwm_Ip_ClearLoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId);
            /* Calculate the duty cycle in ticks */
            FlexPwmChDuty = (uint16)(((uint32)FlexPwm_Ip_aPeriod[IpConfig->ChannelInstanceId][IpConfig->SubModuleId] * DutyCycle) / 0x8000U);
            /* Call FlexPwm IP function */
            FlexPwm_Ip_UpdateDutyCycle(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                       ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                       FlexPwmChDuty);
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = DutyCycle;
#endif
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) DutyCycle;
            (void) IpConfig;
            break;
    }
#else
    /* Avoid compiler warning */
    (void) DutyCycle;
    (void) IpConfig;    
#endif    

    return RetVal;

}
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_DUTY_CYCLE_NO_UPDATE_API */

/*===============================================================================================*/
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
                                       const Pwm_IpwChannelConfigType * const IpConfig)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Pwm_Ipw_DutyType EmiosChDuty = 0U;
    uint32 ChannelMask = 0U;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    uint16 FlexPwmChDuty = 0U;
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
    uint8 UniqueSub = 0U;
#endif
#endif
#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            ChannelMask = (uint32)((uint32)1U << (((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId));

            Emios_Pwm_Ip_ComparatorTransferDisable(IpConfig->ChannelInstanceId,
                                                   ChannelMask);
            /* Call Emios api for setting the period */
            Emios_Pwm_Ip_SetPeriod(IpConfig->ChannelInstanceId,
                                   ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                   Period);

            /* Calculate new duty value in ticks */
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint64)Period * DutyCycle)/0x8000U);
#else
            EmiosChDuty = (Pwm_Ipw_DutyType)(((uint32)Period * DutyCycle)/0x8000U);
#endif
            /* Call Emios api for setting the polarity and mode */
            Emios_Pwm_Ip_SetOutputToNormal(IpConfig->ChannelInstanceId,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                            DutyCycle,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->OutputPolarity,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode
                                           );
            /* Call Emios api for setting the duty cycle */
            RetVal = (Std_ReturnType)Emios_Pwm_Ip_SetDutyCycle(IpConfig->ChannelInstanceId,
                                                               ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId,
                                                               EmiosChDuty);
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
            Pwm_Ipw_aEmiosDutyCycle[IpConfig->ChannelInstanceId][((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId] = DutyCycle;
#endif
            break;
#endif

#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
            FlexPwm_Ip_ClearLoadValue(IpConfig->ChannelInstanceId, 1U << IpConfig->SubModuleId);
            /* Call FlexPwm api for setting the period */
            FlexPwm_Ip_UpdatePeriod(IpConfig->ChannelInstanceId, IpConfig->SubModuleId, (uint16)Period);
                                                  
            FlexPwmChDuty = (uint16)(((uint32)Period * DutyCycle) / 0x8000U);
            /* Call FlexPwm IP function */
            FlexPwm_Ip_UpdateDutyCycle(IpConfig->ChannelInstanceId, IpConfig->SubModuleId,
                                       ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId,
                                       FlexPwmChDuty);
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)))
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub] = DutyCycle;
#endif
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) Period;
            (void) DutyCycle;
            (void) IpConfig;
            break;
    }
#else
    /* Avoid compiler warning */
    (void) Period;
    (void) DutyCycle;
    (void) IpConfig;    
#endif    

    (void) RetVal;

}
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */

/*===============================================================================================*/
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
Std_ReturnType  Pwm_Ipw_ValidateModuleId(uint8 ModuleId, uint8 ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType      RetVal = (Std_ReturnType)E_OK;

#if ((PWM_EMIOS_USED == STD_ON) || ((PWM_FLEXPWM_USED == STD_ON)))
    if ((PWM_MASKOUTPUT_ID == ServiceId) || (PWM_UNMASKOUTPUT_ID == ServiceId))
    {
#if (PWM_FLEXPWM_USED == STD_ON)
        if(PWM_HW_MODULE_FLEXPWM_NO_U8 <= ModuleId)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
#endif
    }
    else if (PWM_SYNCUPDATE_ID == ServiceId)
    {
        if((PWM_HW_MODULE_EMIOS_NO_U8 + PWM_HW_MODULE_FLEXPWM_NO_U8) <= ModuleId)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
    }
    else     
    {
#if (PWM_EMIOS_USED == STD_ON)
        if(PWM_HW_MODULE_EMIOS_NO_U8 <= ModuleId)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
#endif
    }
#else
    RetVal = (Std_ReturnType)E_NOT_OK;
    (void)ServiceId;
    (void)ModuleId;
#endif

    return RetVal;
}
#endif

/*===============================================================================================*/
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
                                            const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXIO_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call Emios IP function */
            RetVal = Pwm_Ipw_EmiosValidateNotification(Notification, IpConfig);

            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Call Flexio IP function */
            if(
                ((PWM_FALLING_EDGE == Notification) && (FLEXIO_PWM_IP_IRQ_ON_FALLING_EDGE == IpConfig->FlexioChConfig->IrqMode)) ||
                ((PWM_RISING_EDGE == Notification) && (FLEXIO_PWM_IP_IRQ_ON_RISING_EDGE == IpConfig->FlexioChConfig->IrqMode)) ||
                ((PWM_BOTH_EDGES == Notification) && (FLEXIO_PWM_IP_IRQ_ON_BOTH_EDGES == IpConfig->FlexioChConfig->IrqMode))
              )
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                RetVal = (Std_ReturnType)E_OK;
            }

            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void)IpConfig;
            (void)Notification;
            break;
    }
#else
    /* Avoid compiler warning */
    (void)IpConfig;
    (void)Notification;    
#endif    

    return RetVal;
}
#endif

/*===============================================================================================*/
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
                                                       const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_EMIOS_USED == STD_ON)
    Pwm_Ipw_PeriodType EmiosPeriod = 0U;
    Pwm_Ipw_DutyType EmiosDuty = 0U;
#endif

#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        /* Call eMIOS IP function */
        EmiosPeriod = Emios_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                            ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);

        EmiosDuty = (Pwm_Ipw_DutyType)(((uint32)EmiosPeriod * DutyCycle) >> 15U);

        if (EMIOS_PWM_IP_MODE_OPWMT == Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,
                                                                ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId)
            )
        {
            if(EmiosPeriod >= PhaseShift)
            {
                RetVal = (Std_ReturnType)E_OK;
            }
        }
        else
        {
            if(EmiosPeriod >= (PhaseShift + EmiosDuty))
            {
               RetVal = (Std_ReturnType)E_OK;
            }
        }
#endif
    }
#if (PWM_FLEXPWM_USED == STD_ON)
    else if (PWM_CHANNEL_FLEXPWM == (IpConfig->ChannelType))
    {
        /* Check the validity of the given flexpwm channel */
        if (((uint16)PhaseShift < FlexPwm_Ip_aPeriod[IpConfig->ChannelInstanceId][IpConfig->SubModuleId]) &&
            (FLEXPWM_IP_PWMX != ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId)
           )
        {
            RetVal = (Std_ReturnType)E_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }

        /* Avoid compiler warning. */
        (void)DutyCycle;
    }
#endif
    else
    {
        /* Do Nothing */
    }
#else
        /* Avoid compiler warning. */
        (void)IpConfig;
        (void)PhaseShift;
        (void)DutyCycle;
#endif

    return RetVal;

}
#endif

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_ValidateTriggerMode(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        /* Call eMIOS IP function */
        if (EMIOS_PWM_IP_MODE_OPWMT == Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,
                                                                ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId)
            )
        {
            RetVal = (Std_ReturnType)E_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif
    }
    return RetVal;
}
#endif

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_ValidateUpdateSynchronous(const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;
    (void)IpConfig;

    return RetVal;

}
#endif /* PWM_DEV_ERROR_DETECT && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API || PWM_SYNC_UPDATE_API) */

/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_COUNTER_BUS_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateCounterBus
* @details      This function will validate of counter bus
*
* @param[in]    Bus      Counter bus ID
* @param[in]    IpConfig    Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK    The selected bus is invalid
*               E_OK        The selected bus is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateCounterBus(uint32                         Bus,
                                          const Pwm_IpwChannelConfigType * const IpConfig)
{
/** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

#if (PWM_EMIOS_USED == STD_ON)
    if (NULL_PTR != IpConfig->EmiosChConfig)
    {
        /* Call eMIOS IP function */
        if ((0x00U != Bus) && (0x01U != Bus) && (0x02U == Bus))
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        if ((EMIOS_PWM_IP_MODE_OPWFMB_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
            (EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode))
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* This parameter is not used */
        (void)Bus;
    }
#else
    /* This parameter is not used */
    (void)Bus;
    (void)IpConfig;
#endif

    return RetVal;
}
#endif

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_ValidateDeadTime(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_PwmModeType ChannelMode;
#endif

    if (PWM_CHANNEL_EMIOS == (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        ChannelMode = Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
        /* Call eMIOS IP function */
        if ((EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG == ChannelMode) ||
           (EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH == ChannelMode) ||
           (EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG == ChannelMode) ||
           (EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH == ChannelMode)
           )
        {
            RetVal = (Std_ReturnType)E_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif
    }
#if (PWM_FLEXPWM_USED == STD_ON)
    else if (PWM_CHANNEL_FLEXPWM == (IpConfig->ChannelType))
    {
        RetVal = (Std_ReturnType)E_OK;
    }
#endif
    else
    {
        /* Do nothing */
    }

    return RetVal;
}
#endif

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_ValidateParamDeadTime(Pwm_Ipw_PeriodType   DeadTimeTicks,
                                             const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_PwmModeType ChannelMode;
    Pwm_Ipw_PeriodType Period;
    Pwm_Ipw_DutyType DutyCycle;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
    uint8 UniqueSub = 0U;
#endif

    switch(IpConfig->ChannelType)
    {
        case PWM_CHANNEL_EMIOS:
#if (PWM_EMIOS_USED == STD_ON)
            Period    = Emios_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                              ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
            DutyCycle = Emios_Pwm_Ip_GetDutyCycle(IpConfig->ChannelInstanceId,
                                                 ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
            ChannelMode = Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
            /* Call eMIOS IP function */
            if ((EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG == ChannelMode) ||
                (EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH == ChannelMode)
            )
            {
                if (DeadTimeTicks < (DutyCycle >> 1U))
                {
                    RetVal = (Std_ReturnType)E_OK;
                }
                else
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
            }
            else
            {
                if (DeadTimeTicks < (Period - DutyCycle))
                {
                    RetVal = (Std_ReturnType)E_OK;
                }
                else
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }

            }
#endif
            break;
        case PWM_CHANNEL_FLEXPWM:
#if (PWM_FLEXPWM_USED == STD_ON)
            UniqueSub = Pwm_Ipw_GetUniqueSubModule(IpConfig->SubModuleId, ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId);
            if ((DeadTimeTicks < 0x800U) && 
                ((uint16)DeadTimeTicks < Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub]) &&
                (((uint16)DeadTimeTicks + Pwm_Ipw_aFlexPwmDutyCycle[IpConfig->ChannelInstanceId][UniqueSub]) < FlexPwm_Ip_aPeriod[IpConfig->ChannelInstanceId][IpConfig->SubModuleId]) &&
                (FLEXPWM_IP_PWMX != ((const FlexPwm_Ip_ChannelCfgTypes *)IpConfig->FlexPwmChConfig)->ChannelId)
               )
            {
                RetVal = (Std_ReturnType)E_OK;
            }
            else
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
#endif
            break;
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) DeadTimeTicks;
            break;
    }

    return RetVal;
}
#endif

/*===============================================================================================*/
#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_OUTPUT_API == STD_ON))
/**
* @brief        Validate the set channel output feature.
*               In order to be valid, the set channel output feature only supported for eMIOS.
*
* @param[in]    State          The state of output
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType  Validity of notification handler
*                   E_OK            set channel output parameter is valid
*                   E_NOT_OK        set channel output parameter is not valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetChannelOutput(Pwm_StateType            State,
                                                const Pwm_IpwChannelConfigType * const IpConfig)
{

    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_EMIOS_USED == STD_ON)
    switch(IpConfig->ChannelType)
    {
        case PWM_CHANNEL_EMIOS:
            /* Check if state is not included */
            if ((PWM_EMIOS_ACTIVE == State) || (PWM_EMIOS_INACTIVE == State))
            {
                RetVal = (Std_ReturnType)E_OK;
            }
            /* Check if channel mode is configured to DAOC. Pwm_SetChannelOutput does not support DAOC mode. */
            if ((EMIOS_PWM_IP_MODE_DAOC_FLAG == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode) ||
                (EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH == ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->Mode)
                )
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }

            break;
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) State;
            break;
    }
#else
    /* Avoid compiler warning */
    (void) State;   
    (void) IpConfig;    
#endif    

    return RetVal;
}
#endif

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_ValidateSetPhaseShift(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_PwmModeType ChannelMode;
#endif

#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXPWM_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            ChannelMode = Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
            /* Call eMIOS IP function */
            if ((EMIOS_PWM_IP_MODE_OPWMT == ChannelMode) ||
               (EMIOS_PWM_IP_MODE_OPWMB_FLAG == ChannelMode) ||
               (EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH == ChannelMode) ||
               (EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG == ChannelMode) ||
               (EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH == ChannelMode) ||
               (EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG == ChannelMode) ||
               (EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH == ChannelMode)
               )
            {
                RetVal = (Std_ReturnType)E_OK;
            }
            else
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
            break;
#endif
#if (PWM_FLEXPWM_USED == STD_ON)
        case PWM_CHANNEL_FLEXPWM:
                RetVal = (Std_ReturnType)E_OK;
            break;
#endif
        default:
            /* Nothing to do. */
            break;
    }
#else
    (void) IpConfig;
#endif

    return RetVal;
}
#endif /* PWM_DEV_ERROR_DETECT && PWM_SET_DUTY_PHASE_SHIFT_API */

/*===============================================================================================*/
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
uint32 Pwm_Ipw_GetMaxPeriodValue(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Store return value */
    uint32 RetVal = (uint32)0xFFFFU;

#if ((PWM_EMIOS_USED == STD_ON) || (PWM_FLEXIO_USED == STD_ON) || (PWM_ETPU_USED == STD_ON))
    switch(IpConfig->ChannelType)
    {
#if (PWM_EMIOS_USED == STD_ON)
        case PWM_CHANNEL_EMIOS:
            /* Call eMIOS IP function */
            RetVal = EMIOS_PWM_IP_MAX_CNT_VAL;
            break;
#endif
#if (PWM_FLEXIO_USED == STD_ON)
        case PWM_CHANNEL_FLEXIO:
            /* Call Flexio IP function */
            RetVal = FLEXIO_PWM_IP_TIMER_CMP_MAX_VALUE << 1U;
            break;
#endif
#if (PWM_ETPU_USED == STD_ON)
        case PWM_CHANNEL_ETPU:
            RetVal = ETPU_PWM_IP_MAX_PERIOD;
            break;
#endif
        default:
            /* Nothing to do. */
            /* Avoid compiler warning */
            (void) IpConfig;
            break;
    }
#else
    /* Avoid compiler warning */
    (void) IpConfig;
#endif

    return RetVal;
}
#endif /* PWM_DEV_ERROR_DETECT && (PWM_SET_PERIOD_AND_DUTY_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API) */

/*===============================================================================================*/
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
Pwm_Ipw_PeriodType Pwm_Ipw_GetCurrentPeriodValue(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Pwm_Ipw_PeriodType Period = (Pwm_Ipw_PeriodType)0U;

    if (PWM_CHANNEL_EMIOS ==  (IpConfig->ChannelType))
    {
#if (PWM_EMIOS_USED == STD_ON)
        /* Call eMIOS IP function */
        Period = Emios_Pwm_Ip_GetPeriod(IpConfig->ChannelInstanceId,
                                       ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
#endif
    }

    return Period;
}
#endif

/*===============================================================================================*/
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
Std_ReturnType Pwm_Ipw_ValidateIdleState(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

#if (PWM_EMIOS_USED == STD_ON)
    if (NULL_PTR != IpConfig->EmiosChConfig)
    {
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,
                                                             ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId)
            )
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
#else
    (void)IpConfig;
#endif

    return RetVal;
}
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
#if ((PWM_GET_OUTPUT_STATE_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
/**
* @brief            Pwm_Ipw_ValidateGetOutputState
* @details          This function will check the validation when calling the Pwm_GetOutputState api.
*
* @param[in]        IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Get output state is not valid
*               E_OK            Get output state is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateGetOutputState(const Pwm_IpwChannelConfigType * const IpConfig)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType      RetVal = (Std_ReturnType)E_OK;

    switch(IpConfig->ChannelType)
    {
        case PWM_CHANNEL_FLEXPWM:
#if (PWM_FLEXPWM_USED == STD_ON)
            RetVal = (Std_ReturnType)E_NOT_OK;
#endif
            break;
        default:
            RetVal = (Std_ReturnType)E_OK;
            break;
    }

    return RetVal; 
}
#endif /* (PWM_GET_OUTPUT_STATE_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_SetPowerStateChannel
* @details      This function will call SetPowerState function of all configured hardware channels
*
* @param[in]    PowerState     Target power mode
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPowerStateChannel(Pwm_PowerStateType               PowerState,
                                  const Pwm_IpwChannelConfigType * const IpConfig)
{
#if (PWM_EMIOS_USED == STD_ON)
    Emios_Pwm_Ip_PwmModeType ChannelMode;
    uint8 Channel;
    boolean State;

    if (NULL_PTR != IpConfig->EmiosChConfig)
    {
        ChannelMode = Emios_Pwm_Ip_GetChannelMode(IpConfig->ChannelInstanceId,
                                                  ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
        Channel = Emios_Pwm_Ip_GetMasterBusChannel(IpConfig->ChannelInstanceId,
                                                    ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId);
        if((EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG == ChannelMode) ||
           (EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH == ChannelMode) ||
           (EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG == ChannelMode) ||
           (EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH == ChannelMode)
          )
        {
            State = (PWM_LOW_POWER == PowerState) ? FALSE : TRUE;
            Emios_Pwm_Ip_SetPreEnableClock(IpConfig->ChannelInstanceId, ((const Emios_Pwm_Ip_ChannelConfigType *)IpConfig->EmiosChConfig)->ChannelId, State);
            Emios_Pwm_Ip_SetPreEnableClock(IpConfig->ChannelInstanceId, Channel, State);
        }
    }
#else
    (void)PowerState;
    (void)IpConfig;
#endif
}
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
                                   Pwm_PowerStateType       PowerState)
{
#if (PWM_FLEXPWM_USED == STD_ON)
    uint8 SubModuleMask = 0x0FU;
    if (PWM_INSTANCE_FLEXPWM == IpConfig->InstanceType)
    {
        if (PWM_LOW_POWER == PowerState)
        {
            FlexPwm_Ip_CounterStop(IpConfig->InstanceId, SubModuleMask);
        }
        else
        {
            FlexPwm_Ip_CounterStart(IpConfig->InstanceId, SubModuleMask);
        }
    }
#else
    (void)PowerState;
    (void)IpConfig;
#endif
}
#endif /* PWM_HW_INSTANCE_USED */
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
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
                         const Pwm_IpwInstanceConfigType * const IpConfig)
{
    if (ModuleId == IpConfig->InstanceId)
    {
         /* Call FlexPwm IP function */
#if (PWM_FLEXPWM_USED == STD_ON)
        FlexPwm_Ip_MaskOutputChannels(ModuleId, ChannelMask, UpdateType);
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)ModuleId;
        (void)ChannelMask;
        (void)UpdateType;
    }
}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

/*===============================================================================================*/
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
                           const Pwm_IpwInstanceConfigType * const IpConfig)
{
    if (ModuleId == IpConfig->InstanceId)
    {
        /* Call FlexPwm IP function */
#if (PWM_FLEXPWM_USED == STD_ON)
        FlexPwm_Ip_UnMaskOutputChannels(ModuleId, ChannelMask, UpdateType);
#endif
    }
    else
    {
        /* This parameter is not used */
        (void)ModuleId;
        (void)ChannelMask;
        (void)UpdateType;
    }
}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
