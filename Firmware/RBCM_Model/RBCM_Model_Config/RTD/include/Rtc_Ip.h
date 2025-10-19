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

#ifndef RTC_IP_H
#define RTC_IP_H

/**
*   @file       Rtc_Ip.h
*
*   @addtogroup rtc_ip Rtc IPL
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
#include "Rtc_Ip_Types.h"
#include "Rtc_Ip_Cfg.h"
#include "OsIf.h"
#if RTC_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif
#include "SchM_Gpt.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define RTC_IP_VENDOR_ID                       43
#define RTC_IP_AR_RELEASE_MAJOR_VERSION        4
#define RTC_IP_AR_RELEASE_MINOR_VERSION        7
#define RTC_IP_AR_RELEASE_REVISION_VERSION     0
#define RTC_IP_SW_MAJOR_VERSION                5
#define RTC_IP_SW_MINOR_VERSION                0
#define RTC_IP_SW_PATCH_VERSION                0

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/
#if (RTC_IP_VENDOR_ID != RTC_IP_TYPES_VENDOR_ID)
    #error "Rtc_Ip.h and Rtc_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((RTC_IP_AR_RELEASE_MAJOR_VERSION != RTC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RTC_IP_AR_RELEASE_MINOR_VERSION != RTC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RTC_IP_AR_RELEASE_REVISION_VERSION != RTC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Rtc_Ip.h and Rtc_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((RTC_IP_SW_MAJOR_VERSION != RTC_IP_TYPES_SW_MAJOR_VERSION) || \
     (RTC_IP_SW_MINOR_VERSION != RTC_IP_TYPES_SW_MINOR_VERSION) || \
     (RTC_IP_SW_PATCH_VERSION != RTC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Rtc_Ip.h and Rtc_Ip_Types.h are different"
#endif

#if (RTC_IP_VENDOR_ID != RTC_IP_VENDOR_ID_CFG)
    #error "Rtc_Ip.h and Rtc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if RTC_IP header file and RTC_IP_Cfg header file are of the same Autosar version */
#if ((RTC_IP_AR_RELEASE_MAJOR_VERSION != RTC_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (RTC_IP_AR_RELEASE_MINOR_VERSION != RTC_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (RTC_IP_AR_RELEASE_REVISION_VERSION != RTC_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of RTC_IP.h and RTC_IP_Cfg.h are different"
#endif
/* Check if RTC_IP file and RTC_IP_Cfg header file are of the same Software version */
#if ((RTC_IP_SW_MAJOR_VERSION != RTC_IP_SW_MAJOR_VERSION_CFG) || \
     (RTC_IP_SW_MINOR_VERSION != RTC_IP_SW_MINOR_VERSION_CFG) || \
     (RTC_IP_SW_PATCH_VERSION != RTC_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Rtc_Ip.h and Rtc_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((RTC_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (RTC_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Rtc_Ip.h and SchM_Gpt.h are different"
    #endif
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((RTC_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (RTC_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Rtc_Ip.h and OsIf.h are different"
    #endif
#endif

#if RTC_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((RTC_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (RTC_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Rtc_Ip.h and Devassert.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (RTC_IP_USED == STD_ON)

#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

extern uint32 Rtc_Ip_u32TargetValue;
extern uint32 Rtc_Ip_u32CounterValueInterrupt;

#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief
 * Function Name : Rtc_Ip_GetInterruptStatusFlag
 * Description   : Get the state of RTC Interrupt Flag (RTCF),
 *                  API Interrupt Flag (APIF) and Counter Roll Over Interrupt Flag (ROVRF): RTC Status register (RTCS)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if an interrupt has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
boolean Rtc_Ip_GetInterruptStatusFlag(uint8 instance, Rtc_Ip_InterruptType interruptMode);

uint32 Rtc_Ip_GetAPICompareRegister(uint8 instance);
uint32 Rtc_Ip_GetCounterRegister(uint8 instance);

/*================================================================================================*/
/**
* @brief         Rtc Driver initialization function
* @details       initialization function
*
* @param[in]     instance     hw instance
* @param[in]     *config      pointer to configuration
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*/
void Rtc_Ip_Init(uint8 instance, const Rtc_Ip_ConfigType *config);

/*================================================================================================*/
/**
* @brief         Rtc driver de-initialization function
* @details       This function:
*                       - resets the Rtc control register
*                       - clears the Rtc interrupt flags
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*
*/
void Rtc_Ip_DeInit(uint8 instance);
/*================================================================================================*/
/**
* @brief         Function for starting the Rtc timer channel.
* @details       This function:
*                       - disables the API functionality
*                       - sets the timeout value (in RTCC - APIVAL)
*                       - enables API functionality (RTCC - APIEN).
*                       - reads the RTC counter register and stores the value of the channel start time
*
* @param[in]     value            channel timeout value
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*
*/
void Rtc_Ip_StartTimer(uint8 instance, uint32 value);

/*================================================================================================*/
/**
* @brief         Gpt driver function for stopping the Rtc timer channel.
* @details       This function:
*                           - disables the API functionality
*                           - clears the API interrupt flag
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*/
void Rtc_Ip_StopTimer(uint8 instance);

/*================================================================================================*/
/**
* @brief         Rtc Driver function for starting the Rtc counter.
* @details       This function:
*                           - enables the counter
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*/
void Rtc_Ip_StartCounter(uint8 instance);

/*================================================================================================*/
/**
* @brief         Rtc Driver function for stopping the Rtc counter.
* @details       This function:
*                           - disables the counter
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*/
void Rtc_Ip_StopCounter(uint8 instance);

/*================================================================================================*/
/**
* @brief         Gpt driver function for Enable Interrupt for RTC channel
* @details       This function:
*                        - Enable Interrupt for RTC channel
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_EnableInterrupt(uint8 instance, Rtc_Ip_InterruptType interruptMode);

/*================================================================================================*/
/**
* @brief         Gpt driver function for Disable Interrupt for RTC channel
* @details       This function:
*                        - Disable Interrupt for RTC channel
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_DisableInterrupt(uint8 instance, Rtc_Ip_InterruptType interruptMode);
/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        -
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_TriggerEnable(uint8 instance, boolean enable);
 /*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will set the date passed by the user.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Rtc_Ip_StatusType Rtc_Ip_SetTimeDate(uint8 instance, const Rtc_Ip_TimedateType *timeDate);

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will get the current time and date and it will
*                               store in the state structure.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_GetTimeDate(uint8 instance, Rtc_Ip_TimedateType * const timeDate);

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will configure a periodic interrupt(using the
*                               RTC's API functionality) with the period configured by the user.
*                               It will calculate the necessary compare value using periodInMs
*                               parameter and the clock source of the module.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     periodInMs         period value in microseconds
* @param[in]     enable             if functionalitu enable or disabled
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Rtc_Ip_StatusType Rtc_Ip_ConfigurePeriodicInterrupt(uint8 instance, uint32 periodInMs, boolean enable);

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will configure the alarm based on the
*                               configuration structure passed by the user.
*                               When using alarm that are configured to be repetitive,
*                               enable the interrupt. Otherwise the repeat function will
*                               not work.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *alarmConfig       pointer to configuration
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Rtc_Ip_StatusType Rtc_Ip_ConfigureAlarm(uint8 instance, const Rtc_Ip_AlarmConfigType *alarmConfig);

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will convert seconds into time-date format.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_ConvertSecondsToTimeDate(const uint32 *seconds, Rtc_Ip_TimedateType * const timeDate);

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will convert time-date into seconds.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Rtc_Ip_ConvertTimeDateToSeconds(const Rtc_Ip_TimedateType *timeDate, uint32 * const seconds);

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will check if the RTCVAL or APIVAL Value is synchronized with the
*                 RTC Counter
*
* @param[in]     instance           Rtc hw instance
* @param[in]     mode               compare value Mode
* @return        Rtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Rtc_Ip_StatusType Rtc_Ip_IsCounterSync(uint8 instance, Rtc_Ip_ModeType mode);

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* RTC_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
#endif /* RTC_IP_H*/
