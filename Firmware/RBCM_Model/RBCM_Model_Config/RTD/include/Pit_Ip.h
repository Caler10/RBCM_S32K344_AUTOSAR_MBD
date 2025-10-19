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

#ifndef PIT_IP_H
#define PIT_IP_H
/**
*   @file       Pit_Ip.h
*
*   @addtogroup pit_ip Pit IPL
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
#include "Pit_Ip_Types.h"
#include "Pit_Ip_Cfg.h"
#include "OsIf.h"
#include "SchM_Gpt.h"
#if PIT_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define PIT_IP_VENDOR_ID                       43
#define PIT_IP_AR_RELEASE_MAJOR_VERSION        4
#define PIT_IP_AR_RELEASE_MINOR_VERSION        7
#define PIT_IP_AR_RELEASE_REVISION_VERSION     0
#define PIT_IP_SW_MAJOR_VERSION                5
#define PIT_IP_SW_MINOR_VERSION                0
#define PIT_IP_SW_PATCH_VERSION                0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PIT_IP_VENDOR_ID != PIT_IP_TYPES_VENDOR_ID)
    #error "Pit_Ip.h and Pit_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((PIT_IP_AR_RELEASE_MAJOR_VERSION != PIT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PIT_IP_AR_RELEASE_MINOR_VERSION != PIT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PIT_IP_AR_RELEASE_REVISION_VERSION != PIT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pit_Ip.h and Pit_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((PIT_IP_SW_MAJOR_VERSION != PIT_IP_TYPES_SW_MAJOR_VERSION) || \
     (PIT_IP_SW_MINOR_VERSION != PIT_IP_TYPES_SW_MINOR_VERSION) || \
     (PIT_IP_SW_PATCH_VERSION != PIT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pit_Ip.h and Pit_Ip_Types.h are different"
#endif

#if (PIT_IP_VENDOR_ID != PIT_IP_VENDOR_ID_CFG)
    #error "Pit_ip.h and Pit_ip_Cfg.h have different vendor ids"
#endif
/* Check if Pit_ip header file and Pit_ip_Cfg header file are of the same Autosar version */
#if ((PIT_IP_AR_RELEASE_MAJOR_VERSION != PIT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PIT_IP_AR_RELEASE_MINOR_VERSION != PIT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PIT_IP_AR_RELEASE_REVISION_VERSION != PIT_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Pit_ip.h and Pit_ip_Cfg.h are different"
#endif
/* Check if Pit_ip file and PIT_IP_Cfg header file are of the same Software version */
#if ((PIT_IP_SW_MAJOR_VERSION != PIT_IP_SW_MAJOR_VERSION_CFG) || \
     (PIT_IP_SW_MINOR_VERSION != PIT_IP_SW_MINOR_VERSION_CFG) || \
     (PIT_IP_SW_PATCH_VERSION != PIT_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Pit_ip.h and Pit_ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PIT_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (PIT_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pit_Ip.h and SchM_Gpt.h are different"
    #endif
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((PIT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (PIT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pit_Ip.h and OsIf.h are different"
    #endif
#endif

#if PIT_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PIT_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (PIT_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pit_Ip.h and Devassert.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                           CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (PIT_IP_USED == STD_ON)

/**
* @internal
* @brief The total PIT timer channel includes standard and RTI timer channels
*/
#if (defined (PIT_IP_RTI_USED) && (PIT_IP_RTI_USED == STD_ON))
#define PIT_CHANNEL_COUNT   (PIT_TIMER_COUNT + 1U)
#else
#define PIT_CHANNEL_COUNT   PIT_TIMER_COUNT
#endif

#define PIT_MAX_VALUE ((uint32)0xFFFFFFFFU)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Gpt_MemMap.h"

/**
* @internal
* @brief            Pit_Ip_u32OldTargetValue
* @details          Local variable used to store the previous target time value after call ChangeNextTimeout.
*/
extern uint32 Pit_Ip_u32OldTargetValue;

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Gpt_MemMap.h"
#endif /* (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) */
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/*!
 * @brief   Get the Interrupt Status Flag of PIT peripheral timer channel.
 * @details Support get of PIT interrupt status flag
 *          This register is intended for Timer interrupt status flag
 *
 * @param[in] instance - Instance number of PIT module
 * @param[in] channel - The channel in the PIT instance
 *
 * @return Channel Interrupt Status Flag
 *         - True : Channel interrupt has occurred
 *         - False: No channel interrupt has occurred
 * @pre The driver needs to be initialized.
 *
 */
boolean Pit_Ip_GetInterruptStatusFlag(uint8 instance, uint8 channel);

uint32 Pit_Ip_GetLoadValue(uint8 instance, uint8 channel);

/**
* @brief         Function Name : Pit_Ip_Init
* @details       Driver initialization function. This function is called for each PIT hw Instance and
*                   - enables the functional clock for PIT Instance or for RTI_PIT
*                   - Sets PIT operation in Debug mode
*
* @param[in]     instance     PIT hw instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
*/
void Pit_Ip_Init(uint8 instance, const Pit_Ip_InstanceConfigType *config);
/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_InitChannel
* @details       Initializes the PIT channels. This function should be called for each PIT hw channel and:
*                   - stops channel
*                   - disable interrupts
*                   - clears pending interrupts
*                   - initializes the state sructure for common process interrupt
*
* @param[in]     instance      PIT hw instance number
* @param[in]     chnlConfig    Pointer to a selected configuration structure.
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver.
*/
void Pit_Ip_InitChannel(uint8 instance, const Pit_Ip_ChannelConfigType *chnlConfig);
/*================================================================================================*/
/**
* @brief         Pit_Ip_DeInit
* @details       De-Initializes the PIT instances. This functions is called for each PIT Instance and
*                    - resets all channels to default
*
* @param[in]     instance        Pit hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
*
*/
void Pit_Ip_Deinit(uint8 instance);
/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_StartChannel
* @details      This function is called for starting the Pit timer channel.
*                    - sets the timeout value into the PIT timer channel register
*                    - enables the PIT channel
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
* @param[in]     countValue      channel timeout value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the Pit timer channel.
*/
Pit_Ip_StatusType Pit_Ip_StartChannel(uint8 instance, uint8 channel, uint32 countValue);
/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_StopChannel
* @details       This function is called for stopping the Pit counter. This function disables the PIT channel and:
*                    - stops PIT counter
*                    - clears interrupt flag
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
* @return        void
* @pre           The driver needs to be initialized. Pit_Ip_StartChannel must be call before.
*/
void Pit_Ip_StopChannel(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_GetCurrentTimer
* @details       Gets counter value from CVAL Register.
*                The period range depends on the frequency of the PIT source clock
*
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
*
* @return        counterValue    counter value
* @pre           The driver needs to be initialized.
*/
uint64 Pit_Ip_GetCurrentTimer(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_EnableChannelInterrupt
* @details      This function enables the IRQ corresponding to the Pit timer channel
*
*
* @param[in]    instance        Pit hw instance
* @param[in]    channel         Pit hw channel
* @return       void
* @pre          The driver needs to be initialized.
*/
void Pit_Ip_EnableChannelInterrupt(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_DisableChannelInterrupt
* @details      This function disables the IRQ corresponding to the Pit timer channel
*
*
* @param[in]     instance        Pit hw instance
* @param[in]     channel         Pit hw channel
* @return        void
* @pre           The driver needs to be initialized.
*/
void Pit_Ip_DisableChannelInterrupt(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief        Function Name : Pit_Ip_SetLifetimeTimer
* @details      Build the 64-bit lifetimer.
*               The lifetime timer is a 64-bit timer which chains timer channel 0 and timer channel 1 together
*               with the start value of both channels is set to the maximum value(0xFFFFFFFF).
*               The period of lifetime timer is equal to the "period of
*               timer 0 * period of timer 1".
*
* @param[in]    instance        Pit hw instance
* @return       void
* @pre          The driver needs to be initialized.
*/
void Pit_Ip_SetLifetimeTimer(uint8 instance);
/*================================================================================================*/
/**
* @brief         Function Name : Pit_Ip_GetLifetimeTimer
* @details       Read current lifefime counter value.
*                The Lifetime timer is 64-bit timer which chains timer 0 and timer 1 together.
*                The period of lifetime timer equals to "period of timer 0 * period of timer 1".
*                This feature returns an absolute time stamp in count. The time stamp
*                value does not exceed the timer period. The timer is down-counting.
*
*
*
* @param[in]     instance        Pit hw instance
*
* @return        lifeTimeValue
* @pre           The driver needs to be initialized.
*/
uint64 Pit_Ip_GetLifetimeTimer(uint8 instance);
/*================================================================================================*/
#if (PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief      The function changes Pit Timer Load Value Register value.
* @details    This function:
*               - sets the next timeout value to PIT_RTI_LDVAL.
*
* @param[in]     u8HwChannel        Pit hw channel ID
* @param[in]     u32Value           channel timeout value
* @return        void
* @pre           The driver needs to be initialized. PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON
*/
void Pit_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value);
#endif /*PIT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON*/
#if (PIT_IP_CHAIN_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function Pit_Ip_EnableChainMode.
* @details    This function:
*               - Chains the timers.
*
* @param[in]     instance        Pit hw channel ID
* @param[in]     channel         channel timeout value
* @return        returnValue
* @pre           The driver needs to be initialized. PIT_IP_CHAIN_MODE == STD_ON
*/
Pit_Ip_StatusType Pit_Ip_ChainMode(uint8 instance, uint8 channel, boolean enable);
#endif  /*PIT_IP_CHAIN_MODE == STD_ON */

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
#endif /* PIT_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif
/** @} */
#endif  /*PIT_IP_H*/
