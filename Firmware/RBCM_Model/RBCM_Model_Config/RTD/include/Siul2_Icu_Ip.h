/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef SIUL2_ICU_IP_H
#define SIUL2_ICU_IP_H

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
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
#include "Siul2_Icu_Ip_Cfg.h"

#if (STD_ON == SIUL2_ICU_IP_USED)
    #if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
        #include "Reg_eSys.h"
    #endif
#endif /* SIUL2_ICU_IP_USED */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_VENDOR_ID                    43
#define SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION     4
#define SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION     7
#define SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION  0
#define SIUL2_ICU_IP_SW_MAJOR_VERSION             5
#define SIUL2_ICU_IP_SW_MINOR_VERSION             0
#define SIUL2_ICU_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_VENDOR_ID != SIUL2_ICU_IP_CFG_VENDOR_ID)
    #error "Siul2_Icu_Ip.h and Siul2_Icu_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip.h and Siul2_Icu_Ip_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_SW_MAJOR_VERSION  != SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SW_MINOR_VERSION  != SIUL2_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SW_PATCH_VERSION  != SIUL2_ICU_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Siul2_Icu_Ip.h and Siul2_Icu_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == SIUL2_ICU_IP_USED)
        #if (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
        /* Check if header file and Reg_eSys.h file are of the same Autosar version */
            #if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
                (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Siul2_Icu_Ip.h and Reg_eSys.h are different"
            #endif
        #endif
    #endif /* SIUL2_ICU_IP_USED */
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#if (defined SIUL2_ICU_CONFIG_EXT)
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/* Macro used to import SIUL2 PB generated configurations. */
SIUL2_ICU_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#if(SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT == STD_ON)
extern SIUL2_Type * const Siul2_Icu_Ip_apxBase[][SIUL2_ICU_IP_NUM_PDAC_SLOT];
#else
extern SIUL2_Type * const Siul2_Icu_Ip_apxBase[];
#endif

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"
/* This array stores the positions in the Siul2_Icu_Ip_axChannelState array of the configured Siul2 channels. */
extern uint8 Siul2_Icu_Ip_au8IndexInChState[SIUL2_ICU_IP_NUM_OF_INSTANCES][SIUL2_ICU_IP_NUM_OF_CHANNELS];
#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"
extern Siul2_Icu_Ip_State Siul2_Icu_Ip_axChannelState[SIUL2_ICU_IP_NUM_OF_CHANNELS_USED];
#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_8
#endif
#include "Icu_MemMap.h"
#if (SIUL2_ICU_IP_VIRTWRAPPER_SUPPORT == STD_ON)
extern uint8 Siul2_Icu_Ip_au8InterruptPdacSlot[SIUL2_ICU_IP_NUM_OF_INSTANCES];
#endif
#if (SIUL2_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_8
#endif
#include "Icu_MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (SIUL2_ICU_IP_DEINIT_API == STD_ON)
/**
 * @brief      Driver function that de-initializes SIUL hardware channel.
 * @details    This function:
 *              - Restore to reset values SIUL2 registers used on init.
 *
 * @param[in]  instance - Instance number used
 * @return     Siul2_Icu_Ip_StatusType - The status of DeInit
 */
Siul2_Icu_Ip_StatusType Siul2_Icu_Ip_DeInit(uint8 instance);
#endif /* SIUL2_ICU_IP_DEINIT_API == STD_ON */

/**
 * @brief      Driver function that initializes SIUL hardware channel.
 * @details    This function:
 *              - Disables interrupt.
 *              - Sets Interrupt filter enable register
 *              - Sets Interrupt Filter Clock Prescaler Register
 *              - Sets Activation Condition
 *
 * @param[in]  instance  Hardware instance of SIUL2 used.
 * @param[in]  userConfig    Instance configuration.
 *
 * @return     Siul2_Icu_Ip_StatusType - The status of Init
 */
Siul2_Icu_Ip_StatusType Siul2_Icu_Ip_Init(uint8 instance, const Siul2_Icu_Ip_ConfigType* userConfig);

/**
 * @brief
 * @details   This function enables the requested activation condition(rising, falling or both
 *            edges) for corresponding SIUL2 channels.
 *
 * @param[in] instance  Hardware instance of SIUL2 used.
 * @param[in] hwChannel Hardware channel of SIUL2 used.
 * @param[in] edge      Edge activation type used.
 */
void Siul2_Icu_Ip_SetActivationCondition(uint8 instance, uint8 hwChannel, Siul2_Icu_Ip_EdgeType edge);

#if (SIUL2_ICU_IP_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief ICU driver function that sets activation condition of SIUL2 channel.
 *
 * @param[in]      instance  Hardware instance of SIUL2 used.
 * @param[in]      hwChannel Hardware channel of SIUL2 used.
 * @return boolean Input state.
 */
boolean Siul2_Icu_Ip_GetInputState(uint8 instance, uint8 hwChannel);
#endif  /* SIUL2_ICU_IP_GET_INPUT_STATE_API */

/**
 * @brief      ICU driver function that enables the interrupt of SIUL2 channel.
 * @details    This function enables SIUL2 Channel Interrupt.
 *
 * @param[in]  instance  Hardware instance of SIUL2 used.
 * @param[in]  hwChannel Hardware channel of SIUL2 used.
 * @return     void
 */
void Siul2_Icu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel);

/**
 * @brief      ICU driver function that disables the interrupt of SIUL2 channel.
 * @details    This function disables SIUL2 Channel Interrupt.
 *
 * @param[in]  instance  Hardware instance of SIUL2 used.
 * @param[in]  hwChannel Hardware channel of SIUL2 used.
 * @return     void
 */
void Siul2_Icu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel);

#if (SIUL2_ICU_IP_SET_MODE_API == STD_ON)
/**
 * @brief      Driver function sets SIUL2 hardware channel into SLEEP mode.
 * @details    This function enables the interrupt if wakeup is enabled for corresponding SIUL2 channel.
 *
 * @param[in]  instance  Hardware instance of SIUL2 used.
 * @param[in]  hwChannel Hardware channel of SIUL2 used.
 * @return     void
 */
void Siul2_Icu_Ip_SetSleepMode(uint8 instance, uint8 hwChannel);

/**
 * @brief      Driver function that sets SIUL2 hardware channel into NORMAL mode.
 * @details    This function enables the interrupt if Notification is enabled for corresponding
 *             SIUL2 channel.
 *
 * @param[in]  instance  Hardware instance of SIUL2 used.
 * @param[in]  hwChannel Hardware channel of SIUL2 used.
 * @return     void
 */
void Siul2_Icu_Ip_SetNormalMode(uint8 instance, uint8 HwChannel);
#endif  /* SIUL2_ICU_IP_SET_MODE_API  */

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @brief      Icu driver function used to set the global prescaler of a SIUL2 module.
 * @details    This function:
 *             - Sets IFCPR register with a prescaler value
 *
 * @param[in]  instance  Hardware instance of SIUL2 used.
 * @param[in]  mode Global prescaler for the SIUL2 module.
 * @return     void
 */
void Siul2_Icu_Ip_SetClockMode(uint8 instance, Siul2_Icu_Ip_ClockModeType mode);
#endif  /* SIUL2_ICU_IP_DUAL_CLOCK_MODE_API */

/**
 * @brief      Driver function Enable Notification for timestamp.
 *
 * @param[in]  instance  Hardware instance of FTM used.
 * @param[in]  hwChannel Hardware channel of FTM used.
 * @return     void
 */
void Siul2_Icu_Ip_EnableNotification(uint8 instance, uint8 hwChannel);

/**
 * @brief      Driver function Disable Notification for timestamp.
 *
 * @param[in]  instance  Hardware instance of FTM used.
 * @param[in]  hwChannel Hardware channel of FTM used.
 * @return     void
 */
void Siul2_Icu_Ip_DisableNotification(uint8 instance, uint8 hwChannel);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_H */
