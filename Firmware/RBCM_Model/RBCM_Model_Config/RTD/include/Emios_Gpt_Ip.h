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

#ifndef EMIOS_GPT_IP_H
#define EMIOS_GPT_IP_H

/**
*   @file       Emios_Gpt_Ip.h
*
*   @addtogroup emios_ip  Emios IPL
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
#include "Emios_Gpt_Ip_Types.h"
#include "Emios_Gpt_Ip_Cfg.h"
#include "OsIf.h"
#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif
#if (EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
#include "Reg_eSys.h"
#endif
#include "SchM_Gpt.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EMIOS_GPT_IP_VENDOR_ID                       43
#define EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_GPT_IP_SW_MAJOR_VERSION                5
#define EMIOS_GPT_IP_SW_MINOR_VERSION                0
#define EMIOS_GPT_IP_SW_PATCH_VERSION                0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and OsIf.h are different"
    #endif
#endif

#if (EMIOS_GPT_IP_VENDOR_ID != EMIOS_GPT_IP_TYPES_VENDOR_ID)
    #error "Emios_Gpt_Ip.h and Emios_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != EMIOS_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION != EMIOS_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and Emios_Gpt_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((EMIOS_GPT_IP_SW_MAJOR_VERSION != EMIOS_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_GPT_IP_SW_MINOR_VERSION != EMIOS_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_GPT_IP_SW_PATCH_VERSION != EMIOS_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Emios_Gpt_Ip.h and Emios_Gpt_Ip_Types.h are different"
#endif

#if (EMIOS_GPT_IP_VENDOR_ID != EMIOS_GPT_IP_VENDOR_ID_CFG)
    #error "Emios_Gpt_Ip.h and Emios_Gpt_Ip_Cfg.h have different vendor ids"
#endif
/* Check if EMIOS_GPT_IP header file and EMIOS_GPT_IP_Cfg header file are of the same Autosar version */
#if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION != EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and Emios_Gpt_Ip_Cfg.h are different"
#endif
/* Check if Emios_Gpt_Ip file and Emios_Gpt_Ip_Cfg header file are of the same Software version */
#if ((EMIOS_GPT_IP_SW_MAJOR_VERSION != EMIOS_GPT_IP_SW_MAJOR_VERSION_CFG) || \
     (EMIOS_GPT_IP_SW_MINOR_VERSION != EMIOS_GPT_IP_SW_MINOR_VERSION_CFG) || \
     (EMIOS_GPT_IP_SW_PATCH_VERSION != EMIOS_GPT_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Emios_Gpt_Ip.h and Emios_Gpt_Ip_Cfg.h are different"
#endif


#if (EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and Reg_eSys.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and SchM_Gpt.h are different"
    #endif
#endif

#if EMIOS_GPT_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Gpt_Ip.h and Devassert.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                           CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (EMIOS_GPT_IP_USED == STD_ON)
/* Unified channel mode field */
#define EMIOS_C_MODE_GPI_U32         ((uint32)(0x00))

/* Mode MCB (up counter) */
#define EMIOS_C_MODE_MCB_U32         ((uint32)(0x50))
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*================================================================================================*/

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
boolean Emios_Gpt_Ip_GetInterruptStatusFlag(uint8 instance, uint8 channel);

/*================================================================================================*/
/**
* @brief       Function Name : Driver routine to process all the interrupts of eMios.
* @details     Non-AutoSar support function used by interrupt service routines to call notification
*              functions if provided and enabled
*
* @param[in]   instance      hardware channel index
* @param[in]   channel       channel index
*
*/
void Emios_Gpt_Ip_IrqHandler(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief         Function Name : Emios_Gpt_Ip_InitChannel
* @details       Initializes the EMIOS channels. This functions is called for each EMIOS hardware channel and:
*
* @param[in]     instance     EMIOS hardware instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Emios_Gpt_Ip_InitChannel_Activity
*/
void Emios_Gpt_Ip_InitChannel(uint8 instance, const Emios_Gpt_Ip_ChannelConfigType *configPtr);
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
void Emios_Gpt_Ip_Deinit(uint8 instance);
/*================================================================================================*/
/**
* @brief        Function Name : Emios_Gpt_Ip_StartTimer
* @details      This function is called for starting the EMIOS timer channel
*
*
* @param[in]     instance        EMIOS hardware instance
* @param[in]     channel         EMIOS hardware channel
* @param[in]     compareValue    Compare value
*                With S32K396 (S32K3XX family) counter regiter is on 24bits and that for the rest the counter register is on 16bits.
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the EMIOS timer channel.
* @implements    Emios_Gpt_Ip_StartTimer_Activity
*/
void Emios_Gpt_Ip_StartTimer(uint8 instance, uint8 channel, uint32 compareValue);
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
void Emios_Gpt_Ip_StopTimer(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief
* Function Name : Emios_Gpt_Ip_GetPeriodValue
* Description   : Get the value   (UC C Reg)
*
* @param[in]     instance     eMios hw instance number
* @param[in]     channel      eMios hw channel number
*
* @return        currentValuePeriod
* @pre           The driver needs to be initialized.
* @implements    Emios_Gpt_Ip_GetPeriodValue_Activity
*/
uint32 Emios_Gpt_Ip_GetPeriodValue(uint8 instance, uint8 channel);

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
void Emios_Gpt_Ip_EnableChannelInterrupt(uint8 instance, uint8 channel);
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
void Emios_Gpt_Ip_DisableChannelInterrupt(uint8 instance, uint8 channel);
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
uint32 Emios_Gpt_Ip_GetCounterValue(uint8 instance, uint8 channel);

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
void Emios_Gpt_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value);
#endif /* EMIOS_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE */

#if (EMIOS_GPT_IP_SET_CLOCK_MODE == STD_ON)
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
void Emios_Gpt_Ip_SetClockMode(uint8 instance, uint8 channel, Emios_Gpt_Ip_ClockModeType clockMode);
#endif/* EMIOS_GPT_IP_SET_CLOCK_MODE */

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* EMIOS_GPT_IP_USED == STD_ON */

#ifdef __cplusplus
}
#endif
/** @} */
#endif/*EMIOS_GPT_IP_H*/
