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

/**
 *     @file
 *
 *     @addtogroup wkpu_icu_ip WKPU IPL
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
#include "Std_Types.h"
#include "Wkpu_Ip.h"
#include "OsIf.h"

#if (STD_ON == WKPU_IP_USED)
    #if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
        #include "Devassert.h"
    #endif

#if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT))
    #if (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT)
        #define USER_MODE_REG_PROT_ENABLED  (WKPU_IP_ENABLE_USER_MODE_SUPPORT)
        #include "RegLockMacros.h"
    #endif
#endif

#endif /* WKPU_IP_USED */

#include "SchM_Icu.h"
/*==================================================================================================
*                                         SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WKPU_IP_VENDOR_ID_C                    43
#define WKPU_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define WKPU_IP_AR_RELEASE_MINOR_VERSION_C     7
#define WKPU_IP_AR_RELEASE_REVISION_VERSION_C  0
#define WKPU_IP_SW_MAJOR_VERSION_C             5
#define WKPU_IP_SW_MINOR_VERSION_C             0
#define WKPU_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((WKPU_IP_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wkpu_Ip.c and Std_Types.h are different"
    #endif

    /* Check if source file and OsIf.h are of the same AUTOSAR version */
    #if ((WKPU_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Wkpu_Ip.c and OsIf.h are different."
    #endif

    #if (STD_ON == WKPU_IP_USED)
        #if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
            /* Check if this header file and Devassert.h file are of the same Autosar version */
            #if ((WKPU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (WKPU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Wkpu_Ip.c and Devassert.h are different"
            #endif
        #endif

        #if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT))
        #if (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT)
        /* Check if header file and RegLockMacros.h file are of the same Autosar version */
        #if ((WKPU_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (WKPU_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wkpu_Ip.c and RegLockMacros.h are different"
        #endif
        #endif
    #endif
    #endif /* WKPU_IP_USED */
    /* Check if this header file and SchM_Icu.h file are of the same Autosar version */
    #if ((WKPU_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
        (WKPU_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wkpu_Ip.c and SchM_Icu.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_VENDOR_ID_C != WKPU_IP_VENDOR_ID)
    #error "Wkpu_Ip.c and Wkpu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_AR_RELEASE_MAJOR_VERSION_C  != WKPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_AR_RELEASE_MINOR_VERSION_C  != WKPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_AR_RELEASE_REVISION_VERSION_C   != WKPU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip.c and Wkpu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_SW_MAJOR_VERSION_C  != WKPU_IP_SW_MAJOR_VERSION) || \
     (WKPU_IP_SW_MINOR_VERSION_C  != WKPU_IP_SW_MINOR_VERSION) || \
     (WKPU_IP_SW_PATCH_VERSION_C  != WKPU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip.c and Wkpu_Ip.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == WKPU_IP_USED)
#if (WKPU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

/* Table of initialized WKPU channels */
Wkpu_Ip_State Wkpu_Ip_u32ChState[WKPU_IP_NUM_OF_CHANNELS_USED];

#if (WKPU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if (WKPU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"

/* This array stores the positions in the Wkpu_Ip_u32ChState array of the configured Wkpu channels. */
uint8 Wkpu_Ip_IndexInChState[WKPU_IP_NUM_OF_CHANNELS] = WKPU_IP_INITIAL_INDEX_OF_CHANNELS;

#if (WKPU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
/* Table of base addresses for WKPU instances. */
WKPU_Type * const Wkpu_Ip_apxBase[] = IP_WKPU_BASE_PTRS;
#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT))

#if (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT)
void Wkpu_SetUserAccessAllowed(uint32 WkpuBaseAddr);
#endif

#if (defined (MCAL_WKPU_REG_PROT_AVAILABLE) && (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT))
    #define Call_Wkpu_SetUserAccessAllowed(BaseAddr) OsIf_Trusted_Call1param(Wkpu_SetUserAccessAllowed,(BaseAddr))
#else
    #define Call_Wkpu_SetUserAccessAllowed(BaseAddr)
#endif

#endif /* defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT) */

#if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT))
#if (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT)
/**
 * @brief        Enables WKPU registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the WKPU IP allowing WKPU registers writing in User Mode
 *
 * @param[in]    WkpuBaseAddr
 *
 * @return       none
 *
 * @pre          Should be executed in supervisor mode
 */
void Wkpu_SetUserAccessAllowed(uint32 WkpuBaseAddr)
{
    SET_USER_ACCESS_ALLOWED(WkpuBaseAddr, WKPU_PROT_MEM_U32);
}
#endif /* STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT */
#endif /* STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT */

/*!
 * @brief Enables or disables wakeup request
 *
 * This function enables or disables wakeup request
 *
 * @param[in] base The WKPU peripheral base address
 * @param[in] channelMask The channel mask
 * @param[in] enable Enables or disables wakeup request
 */
static inline void Wkpu_Ip_WakeupRequest(WKPU_Type * const base,
                                      uint32 channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                                      uint32 channelMaskHi,
#endif
                                      boolean enable)
{
    /* Enable wake-up request */
    if (enable)
    {
        base->WRER |= channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WRER_64 |= channelMaskHi;
#endif
    }
    /* Disable wake-up request */
    else
    {
        base->WRER &= ~channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WRER_64 &= ~channelMaskHi;
#endif
    }
}

static inline void Wkpu_Ip_InterruptRequest(WKPU_Type * const base,
                                            uint32 channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                                            uint32 channelMaskHi,
#endif
                                            boolean enable)
{
    /* Enable interrupt request */
    if (enable)
    {
        base->IRER |= channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->IRER_64 |= channelMaskHi;
#endif
    }
    /* Disable interrupt request */
    else
    {
        base->IRER &= ~channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->IRER_64 &= ~channelMaskHi;
#endif
    }
}

/*!
 * @brief Enables or disables rising edge event
 *
 * This function enables or disables rising edge event
 *
 * @param[in] base The WKPU peripheral base address
 * @param[in] channelMask The channel mask
 * @param[in] enable Enables or disables rising edge event
 */
static inline void Wkpu_Ip_EnableRisingEdge(WKPU_Type * const base,
                                     uint32 channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                                     uint32 channelMaskHi,
#endif
                                     boolean enable)
{
    /* Enables Wakeup/Interrupt Rising edge event enable Register */
    if (enable)
    {
        base->WIREER |= channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIREER_64 |= channelMaskHi;
#endif
    }
    /* Disables Wakeup/Interrupt Rising edge event enable Register */
    else
    {
        base->WIREER &= ~channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIREER_64 &= ~channelMaskHi;
#endif
    }
}

/*!
 * @brief Enables or disables falling edge event
 *
 * This function enables or disables falling edge event
 *
 * @param[in] base The WKPU peripheral base address
 * @param[in] channelMask The channel mask
 * @param[in] enable Enables or disables falling edge event
 */
static inline void Wkpu_Ip_EnableFallingEdge(WKPU_Type * const base,
                                      uint32 channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                                      uint32 channelMaskHi,
#endif
                                      boolean enable)
{
    /* Enables Wakeup/Interrupt Falling edge event enable Register */
    if (enable)
    {
        base->WIFEER |= channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIFEER_64 |= channelMaskHi;
#endif
    }
    /* Disables Wakeup/Interrupt Falling edge event enable Register */
    else
    {
        base->WIFEER &= ~channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIFEER_64 &= ~channelMaskHi;
#endif
    }
}

/*!
 * @brief Enables or disables filter
 *
 * This function enables or disables filter
 *
 * @param[in] base The WKPU peripheral base address
 * @param[in] channelMask The channel mask
 * @param[in] enable Enables or disables filter
 */
static inline void Wkpu_Ip_Filter(WKPU_Type * const base,
                                    uint32 channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                                    uint32 channelMaskHi,
#endif
                                    boolean enable)
{
    /* Enables Wakeup/Interrupt Filter Enable Register */
    if (enable)
    {
        base->WIFER |= channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIFER_64 |= channelMaskHi;
#endif
    }
    /* Disables Wakeup/Interrupt Filter Enable Register */
    else
    {
        base->WIFER &= ~channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIFER_64 &= ~channelMaskHi;
#endif
    }
}

#ifdef WKPU_IP_SUPPORT_PULLUP
/*!
 * @brief Enables or disables request enable
 *
 * This function enables or disables request enable
 *
 * @param[in] base The WKPU peripheral base address
 * @param[in] channelMask The channel mask
 * @param[in] enable Enables or disables pull
 */
static inline void Wkpu_Ip_PullUp(WKPU_Type * const base,
                                  uint32 channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                                  uint32 channelMaskHi,
#endif
                                  boolean enable)
{
    if (enable)
    {
        base->WIPER |= channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIPER_64 |= channelMaskHi;
#endif
    }
    else
    {
        base->WIPER &= ~channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
        base->WIPER_64 &= ~channelMaskHi;
#endif
    }
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Icu driver function that enables the interrupt of WKPU channel.
* @details    This function enables WKPU Channel Interrupt
*
* @param[in]  u32ChannelMask - Channel's Bit Mask
*
* @implements Wkpu_Ip_EnableInterrupt_Activity
*/
void Wkpu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel)
{
    WKPU_Type * base;
    uint32 channelMaskLo = (uint32)0U;
    uint32 channelMaskHi = (uint32)0U;

#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
    DevAssert(hwChannel < WKPU_IP_NUM_OF_CHANNELS);
#endif

    base = Wkpu_Ip_apxBase[instance];

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_57();

    if(32U > hwChannel)
    {
        channelMaskLo = (uint32)1UL << (uint32)hwChannel;
        channelMaskHi = (uint32)0U;
    }
#ifdef WKPU_IP_64_CH_USED
    else
    {
        channelMaskLo = (uint32)0U;
        channelMaskHi = (uint32)1UL << ((uint32)hwChannel - (uint32)32U);
    }
#endif

    /* Write 1 to wakeup/interrupt status flag register to clear the flag. */
    base->WISR    = channelMaskLo;
#ifdef WKPU_IP_64_CH_USED
    base->WISR_64 = channelMaskHi;
#endif

    Wkpu_Ip_InterruptRequest(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            TRUE);

    Wkpu_Ip_WakeupRequest(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            TRUE);
#ifndef WKPU_IP_64_CH_USED
    /* To avoid compilerwarning*/
    (void)channelMaskHi;
#endif
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_57();
}


/**
* @brief      Icu driver function that disables the interrupt of WKPU channel.
* @details    This function disables WKPU Channel Interrupt
*
* @param[in]  u32ChannelMask - Channel's Bit Mask
*
* @implements Wkpu_Ip_DisableInterrupt_Activity
*/
void Wkpu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel)
{
    WKPU_Type * base;
    uint32 channelMaskLo = (uint32)0U;
    uint32 channelMaskHi = (uint32)0U;

#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
    DevAssert(hwChannel < WKPU_IP_NUM_OF_CHANNELS);
#endif

    base = Wkpu_Ip_apxBase[instance];

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_58();

    if(32U > hwChannel)
    {
        channelMaskLo = (uint32)1UL << (uint32)hwChannel;
        channelMaskHi = (uint32)0U;
    }
#ifdef WKPU_IP_64_CH_USED
    else
    {
        channelMaskLo = (uint32)0U;
        channelMaskHi = (uint32)1UL << ((uint32)hwChannel - (uint32)32U);
    }
#endif

    Wkpu_Ip_InterruptRequest(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            FALSE);

    Wkpu_Ip_WakeupRequest(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            FALSE);
#ifndef WKPU_IP_64_CH_USED
    /* To avoid compilerwarning*/
    (void)channelMaskHi;
#endif
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_58();
}

/**
* @brief      Icu driver function that initializes Wkpu.
* @details    This function:
*              - Sets Interrupt Filter Enable Register
*              - Sets Wakeup/Interrupt Pull-up Enable Register
*              - Sets Activation Condition
*
* @param[in]  instance   - Instance number
* @param[in]  userConfig - Pointer to channel configuration structure
*
* @implements Wkpu_Ip_Init_Activity
*/
Wkpu_Ip_StatusType Wkpu_Ip_Init (uint8 instance, const Wkpu_Ip_IrqConfigType* userConfig)
{
    WKPU_Type * base;
    uint8 hwChannel, index;
    uint32 channelMaskLo = (uint32)0U;
    uint32 channelMaskHi = (uint32)0U;
#ifdef WKPU_IP_STANDBY_WAKEUP_SUPPORT
#if (WKPU_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
    uint32 u32regWkpuWISR = (uint32)0U;
#endif
#endif

#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
    DevAssert(userConfig != NULL_PTR);
#endif
    base = Wkpu_Ip_apxBase[instance];

#if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT))
    Call_Wkpu_SetUserAccessAllowed((uint32)Wkpu_Ip_apxBase[instance]);
#endif

    for(index=0; index < userConfig->numChannels; index++)
    {
        /* Configure for Interrupt */
        hwChannel = (*userConfig->pChannelsConfig)[index].hwChannel;
        /* Save in state structure the callback information */
        Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].callback = (*userConfig->pChannelsConfig)[index].callback;
        Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].callbackParam = (*userConfig->pChannelsConfig)[index].callbackParam;
        Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].WkpuChannelNotification = (*userConfig->pChannelsConfig)[index].WkpuChannelNotification;

        if(32U > hwChannel)
        {
            channelMaskLo = (uint32)1UL << (uint32)hwChannel;
            channelMaskHi = (uint32)0U;
#ifdef WKPU_IP_STANDBY_WAKEUP_SUPPORT
#if (WKPU_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
            u32regWkpuWISR = base->WISR & channelMaskLo;
#endif
#endif
        }
#ifdef WKPU_IP_64_CH_USED
        else
        {
            channelMaskLo = (uint32)0U;
            channelMaskHi = (uint32)1UL << ((uint32)hwChannel - (uint32)32U);
#ifdef WKPU_IP_STANDBY_WAKEUP_SUPPORT
#if (WKPU_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
            u32regWkpuWISR = base->WISR_64 & channelMaskHi;
#endif
#endif
        }
#endif

#ifdef WKPU_IP_STANDBY_WAKEUP_SUPPORT
#if (WKPU_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
        if (0U == u32regWkpuWISR)
        {
#endif
#endif
            /* Disable interrupt request */
            Wkpu_Ip_DisableInterrupt(instance, hwChannel);
#ifdef WKPU_IP_STANDBY_WAKEUP_SUPPORT
#if (WKPU_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
        }
#endif
#endif

        /* Set Wakeup/Interrupt Filter Enable Register */
        Wkpu_Ip_Filter(base,
                        channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                        channelMaskHi,
#endif
                        (*userConfig->pChannelsConfig)[index].filterEn);

#ifdef WKPU_IP_SUPPORT_PULLUP
        /* Set Wakeup/Interrupt Pull-up Enable Register */
        Wkpu_Ip_PullUp(base,
                        channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                        channelMaskHi,
#endif
                        (*userConfig->pChannelsConfig)[index].pullEn);
#endif

        /* Set edge events enable registers */
        Wkpu_Ip_SetActivationCondition(instance, hwChannel, (*userConfig->pChannelsConfig)[index].edgeEvent);
        if(WKPU_IP_NUM_OF_CHANNELS > hwChannel)
        {
            Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].chInit = TRUE;
        }
    }
    #ifndef WKPU_IP_64_CH_USED
        /* To avoid compilerwarning*/
        (void)channelMaskHi;
    #endif
    return WKPU_IP_SUCCESS;
}

/**
* @brief      Icu driver function that resets Wkpu configuration.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Clears Wakeup/Interrupt Filter Enable Register
*              - Clears Wakeup/Interrupt Pull-up Enable Register
*              - Clears edge event enable registers
*              - Clear Interrupt Filter Enable Register
*
* @param[in]  instance - Instance number
* @implements Wkpu_Ip_DeInit_Activity
*/
Wkpu_Ip_StatusType Wkpu_Ip_DeInit(uint8 instance)
{
    uint32 u32ChannelMask;
    uint8 index;

#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
#endif
    for(index=0U; index < WKPU_IP_NUM_OF_CHANNELS; index++)
    {
#ifdef WKPU_IP_64_CH_USED
        if((uint8)32U > index)
#endif
        {
            u32ChannelMask = (uint32)1U << (uint32)(index);
            /* Disable IRQ Interrupt */
            Wkpu_Ip_DisableInterrupt(instance, index);
            /* Clear Wakeup/Interrupt Filter Enable Register  */
            Wkpu_Ip_apxBase[instance]->WIFER &= ~u32ChannelMask;
            /* Clear edge event enable registers */
            Wkpu_Ip_apxBase[instance]->WIREER &= ~u32ChannelMask;
            Wkpu_Ip_apxBase[instance]->WIFEER &= ~u32ChannelMask;
            /* Clear Interrupt Filter Enable Register */
            Wkpu_Ip_apxBase[instance]->WIFER &= ~u32ChannelMask;
            /* Write 1 to wakeup/interrupt status flag register to clear the flag. */
            Wkpu_Ip_apxBase[instance]->WISR  = u32ChannelMask;
        }
#ifdef WKPU_IP_64_CH_USED
        if((uint8)32U <= index)
        {
            u32ChannelMask = (uint32)1U << ((uint32)index - (uint32)32U);
            /* Disable IRQ Interrupt */
            Wkpu_Ip_DisableInterrupt(instance, index);
            /* Clear Wakeup/Interrupt Filter Enable Register  */
            Wkpu_Ip_apxBase[instance]->WIFER_64 &= ~u32ChannelMask;
            /* Clear edge event enable registers */
            Wkpu_Ip_apxBase[instance]->WIREER_64 &= ~u32ChannelMask;
            Wkpu_Ip_apxBase[instance]->WIFEER_64 &= ~u32ChannelMask;
            /* Clear Interrupt Filter Enable Register */
            Wkpu_Ip_apxBase[instance]->WIFER_64 &= ~u32ChannelMask;
            /* Write 1 to wakeup/interrupt status flag register to clear the flag. */
            Wkpu_Ip_apxBase[instance]->WISR_64  = u32ChannelMask;
        }
#endif
    }
    return WKPU_IP_SUCCESS;
}

/**
* @brief      Icu driver function that sets activation condition of WKUP channel
* @details    This function enables the requested activation condition(rising, falling or both edges)
*             for corresponding WKPU channels.
*
* @param[in]  instance - Instance number used
* @param[in]  hwChannel - Wake up hardware channel
* @param[in]  edge - edge type for activation
* @implements Wkpu_Ip_SetActivationCondition_Activity
*/
void Wkpu_Ip_SetActivationCondition (uint8 instance, uint8 hwChannel, Wkpu_Ip_EdgeType edge)
{
    WKPU_Type * base;
    uint32 channelMaskLo = (uint32)0U;
    uint32 channelMaskHi = (uint32)0U;

#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
    DevAssert(hwChannel < WKPU_IP_NUM_OF_CHANNELS);
#endif

    base = Wkpu_Ip_apxBase[instance];
    if(32U > hwChannel)
    {
        channelMaskLo = (uint32)1UL << (uint32)hwChannel;
        channelMaskHi = (uint32)0U;
    }
#ifdef WKPU_IP_64_CH_USED
    else
    {
        channelMaskLo = (uint32)0U;
        channelMaskHi = (uint32)1UL << ((uint32)hwChannel - (uint32)32U);
    }
#endif

    switch (edge)
    {
        case WKPU_IP_RISING_EDGE:
            Wkpu_Ip_EnableRisingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            TRUE);
            Wkpu_Ip_EnableFallingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            FALSE);
            break;
        case WKPU_IP_FALLING_EDGE:
            Wkpu_Ip_EnableRisingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            FALSE);
            Wkpu_Ip_EnableFallingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            TRUE);
            break;
        case WKPU_IP_NONE_EDGE:
            Wkpu_Ip_EnableRisingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            FALSE);
            Wkpu_Ip_EnableFallingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            FALSE);
            break;
        case WKPU_IP_BOTH_EDGES:
        default:
            /* fall-through */
            Wkpu_Ip_EnableRisingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            TRUE);
            Wkpu_Ip_EnableFallingEdge(base,
                            channelMaskLo,
#ifdef WKPU_IP_64_CH_USED
                            channelMaskHi,
#endif
                            TRUE);
            break;
    }
#ifndef WKPU_IP_64_CH_USED
    /* To avoid compilerwarning*/
    (void)channelMaskHi;
#endif
}

/**
* @brief      Icu driver function that gets the input state of WKPU channel.
* @details    This function:
*             - Checks if interrupt flags for corresponding WKPU channel is set then
*             it clears the interrupt flag and returns the value as TRUE.
*
* @param[in]  instance - Instance number used
* @param[in]  hwChannel - HW Channel used
*
* @return     boolean
*              - TRUE - if channel is active
*              - FALSE - If channel is in idle
*/
/** @implements Wkpu_Ip_GetInputState_Activity */
boolean Wkpu_Ip_GetInputState(uint8 instance, uint8 hwChannel)
{
    boolean bstate = FALSE;
    uint32 u32regWkpuWISR = 0;
    uint32 u32regWkpuIRER = 0;
    uint32 channelMask;

    WKPU_Type * base;

#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
    DevAssert(hwChannel < WKPU_IP_NUM_OF_CHANNELS);
#endif

    base = Wkpu_Ip_apxBase[instance];

    if((uint8)32U > hwChannel)
    {
        channelMask = 1UL << hwChannel;
        u32regWkpuWISR = base->WISR & channelMask;
        u32regWkpuIRER = base->IRER & channelMask;
        if ((0x0U != u32regWkpuWISR) && (0x0U == u32regWkpuIRER))
        {
            base->WISR = channelMask;
            bstate = TRUE;
        }
    }
#ifdef WKPU_IP_64_CH_USED
    else
    {
        channelMask = 1UL << (hwChannel - 32U);
        u32regWkpuWISR = base->WISR_64 & channelMask;
        u32regWkpuIRER = base->IRER_64 & channelMask;
        if ((0x0U != u32regWkpuWISR) && (0x0U == u32regWkpuIRER))
        {
            base->WISR_64 = channelMask;
            bstate = TRUE;
        }
    }
#endif
    return bstate;
}

/**
 * @brief      Driver function Enable Notification for timestamp.
 */

/** @implements Wkpu_Ip_EnableNotification_Activity */
void Wkpu_Ip_EnableNotification(uint8 hwChannel)
{
#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(hwChannel < WKPU_IP_NUM_OF_CHANNELS);
#endif

    Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].notificationEnable = TRUE;
}

/**
 * @brief      Driver function Disable Notification for timestamp.
 */
/** @implements Wkpu_Ip_DisableNotification_Activity */
void Wkpu_Ip_DisableNotification(uint8 hwChannel)
{
#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(hwChannel < WKPU_IP_NUM_OF_CHANNELS);
#endif

    Wkpu_Ip_u32ChState[Wkpu_Ip_IndexInChState[hwChannel]].notificationEnable = FALSE;
}

#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))
/*!
 * @brief Gets NMI/Reset configuration lock
 *
 * This function gets NMI/Reset configuration lock
 *
 * @param[in] base The WKPU peripheral base address
 * @param[in] position The position of source
 * @return Status of configuration lock
 */
static inline boolean Wkpu_Ip_IsNMIConfigLock(const WKPU_Type * base,
                                        uint32 position)
{
    return (base->NCR & (WKPU_NCR_NLOCK0_MASK >> position)) != 0U;
}

/**
* @brief      Icu driver function that initializes NMI part of Wkpu.
* @details    This function:
*              - Configure destination
*              - Configure wakeup request
               - Configure glitch filter if used
*              - Sets Activation Condition
*
* @param[in]  instance   - Instance number
* @param[in]  userConfig - Pointer to channel configuration structure
*/
/** @implements Wkpu_Ip_InitNMI_Activity */
Wkpu_Ip_StatusType Wkpu_Ip_InitNMI(uint8 instance, const Wkpu_Ip_IrqConfigType* userConfig)
{
#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
    DevAssert(userConfig->pNMIChannelsConfig != NULL_PTR);
#endif

    uint8 coreNumber;
    uint8 i;
    WKPU_Type * base = Wkpu_Ip_apxBase[instance];
    Wkpu_Ip_StatusType retVal = WKPU_IP_SUCCESS;
    uint32 coreShift = 0U;
    const Wkpu_Ip_NmiCfgType * userConfigNMI = (*userConfig->pNMIChannelsConfig);

#if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT))
    Call_Wkpu_SetUserAccessAllowed((uint32)Wkpu_Ip_apxBase[instance]);
#endif

    retVal = Wkpu_Ip_DeinitNMI(instance);

    if(WKPU_IP_SUCCESS == retVal)
    {
        for (i = 0U; ((i < WKPU_IP_NMI_CORE_CNT) && (i < (userConfig->numNMIChannels))); i++)
        {
            coreNumber = (uint8)userConfigNMI[i].core;
            coreShift = coreNumber * (uint32)WKPU_IP_CORE_OFFSET_SIZE;

            /* Configure destination source */
            base->NCR &= ~(WKPU_NCR_NDSS0_MASK >> coreShift);
            base->NCR |= WKPU_NCR_NDSS0((uint8)userConfigNMI[i].destination) >> coreShift;

            /* Configure wake-up request */
            base->NCR &= ~(WKPU_NCR_NWRE0_MASK >> coreShift);
            base->NCR |= WKPU_NCR_NWRE0(userConfigNMI[i].wkpReqEn ? 1UL : 0UL) >> coreShift;

        #ifndef WKPU_IP_SUPPORT_FILTER_ON_EACH_CORE
            /* Only set filter for Core 0 */
            if ( 0UL == coreNumber)
        #endif /* #ifndef WKPU_IP_SUPPORT_FILTER_ON_EACH_CORE */
            {
                /* Configure glitch filter */
                base->NCR &= ~(WKPU_NCR_NFE0_MASK >> coreShift);
                base->NCR |= WKPU_NCR_NFE0(userConfigNMI[i].filterEn ? 1UL : 0UL) >> coreShift;
            }

            /* Configure edge events */
            if (WKPU_IP_RISING_EDGE == userConfigNMI[i].edgeEvent)
            {
#ifdef ERR_IPV_WKPU_E050394
                base->NCR |= WKPU_NCR_NFEE0_MASK >> coreShift;
#endif
                base->NCR |= WKPU_NCR_NREE0_MASK >> coreShift;
                base->NCR &= ~(WKPU_NCR_NFEE0_MASK >> coreShift);
            }
            else if (WKPU_IP_FALLING_EDGE == userConfigNMI[i].edgeEvent)
            {
                base->NCR &= ~(WKPU_NCR_NREE0_MASK >> coreShift);
                base->NCR |= WKPU_NCR_NFEE0_MASK >> coreShift;
            }
            else
            {
                base->NCR |= WKPU_NCR_NFEE0_MASK >> coreShift;
                base->NCR |= WKPU_NCR_NREE0_MASK >> coreShift;
            }
            /* Configure lock */
            base->NCR |= WKPU_NCR_NLOCK0(userConfigNMI[i].lockEn ? 1UL : 0UL) >> coreShift;
        }
    }
    return retVal;
}

/** @implements Wkpu_Ip_DeinitNMI_Activity */
Wkpu_Ip_StatusType Wkpu_Ip_DeinitNMI(uint8 instance)
{
#if(WKPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < WKPU_INSTANCE_COUNT);
#endif
    uint8 i;
    uint32 coreShift = 0U;
    Wkpu_Ip_StatusType retVal = WKPU_IP_SUCCESS;
    static const Wkpu_Ip_CoreType coreNumber[WKPU_IP_NMI_NUM_CORES] = WKPU_IP_CORE_ARRAY;

    WKPU_Type * base = Wkpu_Ip_apxBase[instance];

    for (i = 0U; i < WKPU_IP_NMI_NUM_CORES; i++)
    {
        coreShift = (uint32)coreNumber[i] * WKPU_IP_CORE_OFFSET_SIZE;

        if (Wkpu_Ip_IsNMIConfigLock(base, coreShift) == FALSE)
        {
            /* Clear status flag and overrun status flag */
            base->NSR = ((WKPU_NSR_NIF0_MASK | WKPU_NSR_NOVF0_MASK) >> coreShift);
            /* Clear edge events */
            base->NCR &= ~(WKPU_NCR_NREE0_MASK >> coreShift);
            base->NCR &= ~(WKPU_NCR_NFEE0_MASK >> coreShift);

        #ifndef WKPU_IP_SUPPORT_FILTER_ON_EACH_CORE
            /* Only set filter for Core 0 */
            if (WKPU_CORE0 == coreNumber[i])
        #endif /* #ifndef WKPU_IP_SUPPORT_FILTER_ON_EACH_CORE */
            {
                /* Disable glitch filter */
                base->NCR &= ~(WKPU_NCR_NFE0_MASK >> coreShift);
            }

            /* Disable wake-up request */
            base->NCR &= ~(WKPU_NCR_NWRE0_MASK >> coreShift);

        #ifdef WKPU_IP_SUPPORT_NONE_REQUEST
            /* Configure destination source */
            base->NCR &= ~(WKPU_NCR_NDSS0_MASK >> coreShift);
            base->NCR |= WKPU_NCR_NDSS0((uint8)WKPU_IP_NMI_NONE) >> coreShift;
        #endif /* #ifndef WKPU_IP_SUPPORT_NONE_REQUEST */
        }
        else
        {
            retVal = WKPU_IP_ERROR;
            break;
        }
    }
    return retVal;
}
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

