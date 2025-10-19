
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
 *     @internal
 *     @addtogroup icu_ipw Icu Driver
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
#include "Icu_Ipw.h"
#include "Emios_Icu_Ip.h"
#include "Siul2_Icu_Ip.h"
#include "Wkpu_Ip.h"
#include "Cmp_Ip.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_VENDOR_ID_C                     43
#define ICU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define ICU_IPW_AR_RELEASE_MINOR_VERSION_C      7
#define ICU_IPW_AR_RELEASE_REVISION_VERSION_C   0
#define ICU_IPW_SW_MAJOR_VERSION_C              5
#define ICU_IPW_SW_MINOR_VERSION_C              0
#define ICU_IPW_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != ICU_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif

#if (ICU_IPW_VENDOR_ID_C != EMIOS_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Emios_Icu_Ip.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Emios_Icu_Ip.h are different"
#endif

/* Check if header file and Emios_Icu_Ip.h file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != EMIOS_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != EMIOS_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != EMIOS_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw.c and Emios_Icu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != SIUL2_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Siul2_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Siul2_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Siul2_Icu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != WKPU_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Wkpu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != WKPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != WKPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != WKPU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Wkpu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != WKPU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != WKPU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != WKPU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Wkpu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != CMP_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Cmp_Ip.h have different vendor IDs"
#endif

/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != CMP_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != CMP_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != CMP_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Cmp_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != CMP_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != CMP_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != CMP_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Cmp_Ip.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
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

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief                Icu_Ipw_Init
* @details              Initialize a hardware Icu IP Instance
*
* @param[in]            count       - Number of instances to be configured
* @param[in]            pIpConfig   - Pointer that contains IP specific configuration data for the Icu driver
*
* @return void
*
* @pre                  Icu_DeInit must be called before.
*
*/
void Icu_Ipw_Init (uint8 count, const Icu_Ipw_IpConfigType (*pIpConfig)[])
{
    uint8 index;
    Icu_Ipw_ModuleType ipType;

    for(index = 0; index < count; index++)
    {
        ipType = (*pIpConfig)[index].instanceIp;
        switch(ipType)
        {
#if (STD_ON == SIUL2_ICU_IP_USED)
            case ICU_SIUL2_MODULE:
            {
                /* External Interrupt Channel Configuration */
                (void)Siul2_Icu_Ip_Init((*pIpConfig)[index].instanceNo, \
                                        (*pIpConfig)[index].pSiul2HwIpConfig);
            }
            break;
#endif /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
            case ICU_WKPU_MODULE:
            {
                if((*pIpConfig)[index].pWkpuHwIpConfig->numChannels > 0U)
                {
                    /* External WKPU Channels Configuration */
                    (void)Wkpu_Ip_Init((*pIpConfig)[index].instanceNo, \
                                      (*pIpConfig)[index].pWkpuHwIpConfig);
                }
            #if (defined(ICU_IPW_WKPU_NMI_API_USED))
                if((*pIpConfig)[index].pWkpuHwIpConfig->numNMIChannels > 0U)
                {
                    /* NMI WKPU Channels Configuration */
                    (void)Wkpu_Ip_InitNMI((*pIpConfig)[index].instanceNo, \
                                            (*pIpConfig)[index].pWkpuHwIpConfig);
                }
            #endif
            }
            break;
#endif /* WKPU_IP_USED */
#if (STD_ON == EMIOS_ICU_IP_USED)
            case ICU_EMIOS_MODULE:
            {
                /* Default to Emios Configuration */
                (void)Emios_Icu_Ip_Init((*pIpConfig)[index].instanceNo, \
                                         (*pIpConfig)[index].pEmiosHwIpConfig);
            }
            break;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == CMP_IP_USED)
            case ICU_CMP_MODULE:
            {
                /* Default to Cmp Configuration */
                (void)Cmp_Ip_Init((*pIpConfig)[index].instanceNo, \
                            (*pIpConfig)[index].pCmpHwIpConfig);
            }
            break;
#endif  /* CMP_IP_USED */
            default:
            {
                /* Do nothing. */
            }
            break;
        }
    }
}

 #if (STD_ON == ICU_DE_INIT_API)
/**
* @brief              Icu_Ipw_DeInit
* @details            De-initialize ICU hardware channel
*
* @param[in]          pIpConfig - Pointer to ICU top configuration structure
*
* @return void
*
* @pre                Icu_Init must be called before.
*
*/
void Icu_Ipw_DeInit(uint8 count, const Icu_Ipw_IpConfigType (*pIpConfig)[])
{
    uint8 index;
    Icu_Ipw_ModuleType ipType;

    for(index = 0; index < count; index++)
    {
        ipType = (*pIpConfig)[index].instanceIp;
        switch(ipType)
        {
            /* External Interrupt Channel Configuration */
#if (STD_ON == SIUL2_ICU_IP_USED)
            case ICU_SIUL2_MODULE:
            {   
                /* DeInit entire IP - used with exclusive access */
                (void)Siul2_Icu_Ip_DeInit((*pIpConfig)[index].instanceNo);
            } 
            break;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
            case ICU_WKPU_MODULE:
            {
                /* DeInit entire IP - used with exclusive access */
                (void)Wkpu_Ip_DeInit((*pIpConfig)[index].instanceNo);
            #if (defined(ICU_IPW_WKPU_NMI_API_USED))
                (void)Wkpu_Ip_DeinitNMI((*pIpConfig)[index].instanceNo);
            #endif
            }
            break;
#endif  /* WKPU_IP_USED */
#if (STD_ON == EMIOS_ICU_IP_USED)
            case ICU_EMIOS_MODULE:
            {
                /* DeInit only used channels from IP - may be shared used */
                (void)Emios_Icu_Ip_Deinit((*pIpConfig)[index].instanceNo);
            }
            break;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == CMP_IP_USED)
            case ICU_CMP_MODULE:
            {
                /* DeInit only used channels from IP - may be shared used */
                (void)Cmp_Ip_Deinit((*pIpConfig)[index].instanceNo);
            }
            break;
#endif  /* CMP_IP_USED */
            default:
            {
                /* Do nothing. */
            }
            break;
        }
    }
}
#endif /* ICU_DE_INIT_API == STD_ON */

#if (ICU_SET_MODE_API == STD_ON)
/**
 * @brief Put the channel in a reduce power state.
* @details    Set sleep mode
 * 
 * @param ChannelConfig - configuration of the channel
*
* @return void
*/
void Icu_Ipw_SetSleepMode(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_SetSleepMode(ChannelConfig->instanceNo, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        case ICU_SIUL2_MODULE:
            {
#if (STD_ON == SIUL2_ICU_IP_USED)
                Siul2_Icu_Ip_SetSleepMode(ChannelConfig->instanceNo, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
#endif  /* SIUL2_ICU_IP_USED */
                break;
            }
        case ICU_WKPU_MODULE:
            {
#if (STD_ON == WKPU_IP_USED)
                Wkpu_Ip_DisableInterrupt(ChannelConfig->instanceNo, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
#endif  /* WKPU_IP_USED */
                break;
            }
        case ICU_CMP_MODULE:
            {
#if (STD_ON == CMP_IP_USED)
                Cmp_Ip_SetSleepMode(ChannelConfig->instanceNo);
#endif  /* CMP_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}

/**
* @brief      Icu_Ipw_SetNormalMode
* @details    Set normal mode
*
* @param[in]      ChannelConfig - The index of ICU channel for current configuration structure
*
* @return void
*
*/
void Icu_Ipw_SetNormalMode (const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_SetNormalMode(ChannelConfig->instanceNo, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        case ICU_SIUL2_MODULE:
            {
#if (STD_ON == SIUL2_ICU_IP_USED)
                Siul2_Icu_Ip_SetNormalMode(ChannelConfig->instanceNo, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
#endif  /* SIUL2_ICU_IP_USED */
                break;
            }
        case ICU_WKPU_MODULE:
            {
#if (STD_ON == WKPU_IP_USED)
                Wkpu_Ip_EnableInterrupt(ChannelConfig->instanceNo, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
#endif  /* WKPU_IP_USED */
                break;
            }
        case ICU_CMP_MODULE:
            {
#if (STD_ON == CMP_IP_USED)
                Cmp_Ip_SetNormalMode(ChannelConfig->instanceNo);
#endif  /* CMP_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}
#endif  /* ICU_SET_MODE_API */

/**
* @brief      Icu_Ipw_SetActivationCondition
 * @brief 
 * 
 * @param activation    - the type of activation for the ICU channel.
 * @param ChannelConfig - channel to be configured.
*
* @return void
*
*/
void Icu_Ipw_SetActivationCondition(Icu_ActivationType activation,
                                    const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
#if (STD_ON == EMIOS_ICU_IP_USED)
        case ICU_EMIOS_MODULE:
            {
                if (ICU_FALLING_EDGE == activation)
                {
                    Emios_Icu_Ip_SetActivation(module, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel, EMIOS_ICU_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Emios_Icu_Ip_SetActivation(module, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel, EMIOS_ICU_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Emios_Icu_Ip_SetActivation(module, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel, EMIOS_ICU_BOTH_EDGES);
                }
                else
                {
                    Emios_Icu_Ip_SetActivation(module, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel, EMIOS_ICU_NO_PIN_CONTROL);
                }
            }
            break;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
        case ICU_SIUL2_MODULE:
            {
                if (ICU_FALLING_EDGE == activation)
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel, SIUL2_ICU_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel, SIUL2_ICU_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel, SIUL2_ICU_BOTH_EDGES);
                }
                else
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel, SIUL2_ICU_DISABLE);
                }
            }
            break;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
        case ICU_WKPU_MODULE:
            {
                if (ICU_FALLING_EDGE == activation)
                {
                    Wkpu_Ip_SetActivationCondition(module, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel, WKPU_IP_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Wkpu_Ip_SetActivationCondition(module, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel, WKPU_IP_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Wkpu_Ip_SetActivationCondition(module, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel, WKPU_IP_BOTH_EDGES);
                }
                else
                {
                    Wkpu_Ip_SetActivationCondition(module, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel, WKPU_IP_NONE_EDGE);
                }
            }
            break;
#endif  /* WKPU_IP_USED */
#if (STD_ON == CMP_IP_USED)
        case ICU_CMP_MODULE:
            {
                if (ICU_FALLING_EDGE == activation)
                {
                    Cmp_Ip_SetInterruptActivation(module, CMP_IP_INTTRIG_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Cmp_Ip_SetInterruptActivation(module, CMP_IP_INTTRIG_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Cmp_Ip_SetInterruptActivation(module, CMP_IP_INTTRIG_BOTH_EDGES);
                }
                else
                {
                    Cmp_Ip_SetInterruptActivation(module, CMP_IP_INTTRIG_NONE);
                }
            }
            break;
#endif  /* CMP_IP_USED */
        default:
            {
                /* Do nothing. */
            }
            break;
    }
}

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief Service that returns the state of the ICU driver.
 * 
 * @param ChannelConfig 
 * @return boolean 
 */
boolean Icu_Ipw_GetInputState(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    boolean retState = FALSE;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
#if (STD_ON == EMIOS_ICU_IP_USED)
        case ICU_EMIOS_MODULE:
            {
                retState = Emios_Icu_Ip_GetInputState(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
            }
            break;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
        case ICU_SIUL2_MODULE:
            {
                retState = Siul2_Icu_Ip_GetInputState(ChannelConfig->instanceNo, \
                               (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
            }
            break;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
        case ICU_WKPU_MODULE:
            {
                retState = Wkpu_Ip_GetInputState(ChannelConfig->instanceNo, \
                               (ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
            }
            break;
#endif  /* WKPU_IP_USED */
#if (STD_ON == CMP_IP_USED)
        case ICU_CMP_MODULE:
            {
                retState = Cmp_Ip_GetStatus(ChannelConfig->instanceNo);
            }
            break;
#endif  /* CMP_IP_USED */
        default:
            {
                /* Do nothing. */
            }
            break;
    }

    return (retState);
}
#endif /* ICU_GET_INPUT_STATE_API */

#if (STD_ON == ICU_TIMESTAMP_API)
void Icu_Ipw_StartTimestamp(const Icu_Ipw_ChannelConfigType* channelConfig,
                            Icu_ValueType* bufferPtr,
                            uint16  bufferSize,
                            uint16  notifyInterval)
{
    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_StartTimestamp(channelConfig->instanceNo, \
                                   (channelConfig->pEmiosHwChannelConfig)->hwChannel, \
                                    bufferPtr, bufferSize, notifyInterval);
#endif  /* EMIOS_ICU_IP_USED */
                 break;
            }
        default:
            {
                /* Do nothing. */
                /* Avoid compiler warning */
                (void) bufferPtr;
                (void) bufferSize;
                (void) notifyInterval;
                break;
            }
    }
}

void Icu_Ipw_StopTimestamp(const Icu_Ipw_ChannelConfigType *channelConfig)
{
    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_StopTimestamp(channelConfig->instanceNo, \
                                  (channelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}

uint16 Icu_Ipw_GetTimestampIndex(const Icu_Ipw_ChannelConfigType* channelConfig)
{
    uint16 timestampIndex = 0U;
    /* Select IP type. */
    switch(channelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
        {
#if (STD_ON == EMIOS_ICU_IP_USED)
            timestampIndex = Emios_Icu_Ip_GetTimestampIndex(channelConfig->instanceNo, \
                                                          (channelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
            break;
        }
        default:
        {
            /* Do nothing. */
            break;
        }
    }
    return timestampIndex;
}

#endif  /* ICU_TIMESTAMP_API == STD_ON */
#if ((ICU_TIMESTAMP_USES_DMA == STD_ON) || (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON))
uint32 Icu_Ipw_GetStartAddress(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    uint32 startAddr = 0U;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                startAddr = Emios_Icu_Ip_GetStartAddress(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
    return startAddr;
}
#endif  /* ICU_TIMESTAMP_USES_DMA == STD_ON || ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON*/

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
Icu_ValueType Icu_Ipw_GetIPVMaxCouter(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    Icu_ValueType maxCouter = 0U;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                maxCouter = EMIOS_ICU_IP_COUNTER_MASK;
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }

    return maxCouter;
}
#endif  /* ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON*/

#if (STD_ON == ICU_EDGE_COUNT_API)
void Icu_Ipw_ResetEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_ResetEdgeCount(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}

void Icu_Ipw_EnableEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_EnableEdgeCount(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}

void Icu_Ipw_DisableEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_DisableEdgeCount(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}

Icu_EdgeNumberType Icu_Ipw_GetEdgeNumbers(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    Icu_EdgeNumberType edgeNumber = (Icu_EdgeNumberType)0U;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                edgeNumber = (Icu_EdgeNumberType)Emios_Icu_Ip_GetEdgeNumbers(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }

    return edgeNumber;
}

#if (defined ICU_SET_INITIAL_COUNTER)
#if (STD_ON == ICU_SET_INITIAL_COUNTER)
void Icu_Ipw_SetInitialCounterValue(const Icu_Ipw_ChannelConfigType *ChannelConfig, uint32 InitialCounterValue)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_SetInitialCounterValue(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel, InitialCounterValue);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
    /* Avoid compiler warning */
    (void)InitialCounterValue;
}
#endif  /* STD_ON == ICU_SET_INITIAL_COUNTER */
#endif  /* ICU_SET_INITIAL_COUNTER */

#if (defined ICU_SET_MAX_COUNTER)
#if (STD_ON == ICU_SET_MAX_COUNTER)
void Icu_Ipw_SetMaxCounterValue(const Icu_Ipw_ChannelConfigType *ChannelConfig, uint32 MaxCounterValue)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_SetMaxCounterValue(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel, MaxCounterValue);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
    /* Avoid compiler warning */
    (void)MaxCounterValue;
}
#endif  /* STD_ON == ICU_SET_MAX_COUNTER */
#endif  /* ICU_SET_MAX_COUNTER */

#endif  /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_DETECT_API)
/**
 * @brief          Retrieve the number of edges
 *
 * @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
 * @return         void
 */
void Icu_Ipw_EnableEdgeDetection(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
#if (STD_ON == EMIOS_ICU_IP_USED)
        case ICU_EMIOS_MODULE:
            {
                Emios_Icu_Ip_EnableEdgeDetection(module, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
            }
            break;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
        case ICU_SIUL2_MODULE:
            {
                Siul2_Icu_Ip_EnableInterrupt(module, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
            }
            break;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
        case ICU_WKPU_MODULE:
            {
                Wkpu_Ip_EnableInterrupt(module, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
            }
            break;
#endif  /* WKPU_IP_USED */
#if (STD_ON == CMP_IP_USED)
        case ICU_CMP_MODULE:
            {
                Cmp_Ip_EnableInterrupt(module);
                Cmp_Ip_EnableNotification(module);
            }
            break;
#endif  /* CMP_IP_USED */
        default:
            {
                /* Do nothing. */
            }
            break;
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief 
 * 
 * @param ChannelConfig - channel configuration used.
 */
void Icu_Ipw_DisableEdgeDetection(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;
    
    /* Select IP type case. */
    switch(ipType)
    {
#if (STD_ON == EMIOS_ICU_IP_USED)
        case ICU_EMIOS_MODULE:
            {
                Emios_Icu_Ip_DisableEdgeDetection(module, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
            }
            break;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
        case ICU_SIUL2_MODULE:
            {
                Siul2_Icu_Ip_DisableInterrupt(module, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
            }
            break;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
        case ICU_WKPU_MODULE:
            {
                Wkpu_Ip_DisableInterrupt(module, (ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
            }
            break;
#endif  /* WKPU_IP_USED */
#if (STD_ON == CMP_IP_USED)
        case ICU_CMP_MODULE:
            {
                Cmp_Ip_DisableInterrupt(module);
                Cmp_Ip_DisableNotification(module);
            }
            break;
#endif  /* CMP_IP_USED */
        default:
            {
                /* Do nothing. */
            }
            break;
    } 
}
#endif /* ICU_EDGE_DETECT_API */

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
/**
 * @brief The function get the state of the overflow flag
 * @internal
 * @param ChannelConfig      Channel configuration pointer
 * @return      boolean      the state of the overflow flag
 * @retval      TRUE         the overflow flag is set
 * @retval      FALSE        the overflow flag is not set
 */
boolean Icu_Ipw_Get_Overflow(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    boolean bOverflow = FALSE;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                /* Check if eMios Module Overflow. */
                bOverflow = Emios_Icu_Ip_GetOverflow(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
    
    return bOverflow;
}
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (STD_ON == ICU_GET_INPUT_LEVEL_API)
Icu_LevelType Icu_Ipw_GetInputLevel(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_LevelType nInputLevel = ICU_LEVEL_LOW;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                nInputLevel = (Emios_Icu_Ip_GetInputLevel(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel) == EMIOS_ICU_LEVEL_HIGH)?ICU_LEVEL_HIGH:ICU_LEVEL_LOW;
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }

    return nInputLevel;
}
#endif /* STD_ON == ICU_GET_INPUT_LEVEL_API */

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))/**
 * @brief      Capture the value of counter register for a specified channel.
 * 
 * @details   The API shall return the value stored in capture register.
 *            The API is the equivalent of AUTOSAR API GetCaptureRegisterValue.
 * 
 * @param ChannelConfig      Channel configuration pointer
 * @return     uint32  Value of the register captured.
 */
Icu_ValueType Icu_Ipw_GetCaptureRegisterValue (const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_ValueType nRValue = (Icu_ValueType)0U;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                /* Get EMIOS Module Capture Register Value */
                nRValue = (Icu_ValueType)Emios_Icu_Ip_GetCaptureRegValue(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }

    return nRValue;
}
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
* @brief      Icu_Ipw_StartSignalMeasurement
* @details    Starts the signal measurement service
*
* @param[in]      hwChannel     - The index of ICU channel for current configuration structure
*
* @return void
*
*/
void Icu_Ipw_StartSignalMeasurement (const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_StartSignalMeasurement(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}
#endif /* ICU_SIGNAL_MEASUREMENT_API */

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
void Icu_Ipw_StopSignalMeasurement(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_StopSignalMeasurement(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}
#endif /* ICU_SIGNAL_MEASUREMENT_API */

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
void Icu_Ipw_SetPWandPeriod(const Icu_Ipw_ChannelConfigType* channelConfig, \
                            Icu_ValueType Icu_aActivePulseWidth, \
                            Icu_ValueType Icu_aPeriod)
{
    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_SetPWandPeriod(channelConfig->instanceNo, \
                                  (channelConfig->pEmiosHwChannelConfig)->hwChannel, \
                                  (Icu_ValueType)Icu_aActivePulseWidth, \
                                  (Icu_ValueType)Icu_aPeriod);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                /* Avoid compiler warning */
                (void) Icu_aActivePulseWidth;
                (void) Icu_aPeriod;
                break;
            }
    }
}
#endif  /* STD_ON == ICU_SIGNAL_MEASUREMENT_API */

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
void Icu_Ipw_GetDutyCycleValues(const Icu_Ipw_ChannelConfigType* channelConfig,
                                Icu_DutyCycleType* DutyCycleValues)
{
#if (STD_ON == EMIOS_ICU_IP_USED)
    eMios_Icu_Ip_DutyCycleType emiosDutyCycleValues;
 
    emiosDutyCycleValues.ActiveTime = (Icu_ValueType)0U;
    emiosDutyCycleValues.PeriodTime = (Icu_ValueType)0U;
#endif  /* EMIOS_ICU_IP_USED */

    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_GetDutyCycleValues(channelConfig->instanceNo, \
                                      (channelConfig->pEmiosHwChannelConfig)->hwChannel, \
                                      &emiosDutyCycleValues);
                DutyCycleValues->ActiveTime = (Icu_ValueType)emiosDutyCycleValues.ActiveTime;
                DutyCycleValues->PeriodTime = (Icu_ValueType)emiosDutyCycleValues.PeriodTime;
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                /* Avoid compiler warning */
                (void) DutyCycleValues;
                break;
            }
    }
}
#endif /* STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API */

#if (STD_ON == ICU_GET_TIME_ELAPSED_API)
Icu_ValueType Icu_Ipw_GetTimeElapsed(const Icu_Ipw_ChannelConfigType* channelConfig)
{
    Icu_ValueType timeElapsed = 0U;

    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                timeElapsed = Emios_Icu_Ip_GetTimeElapsed(channelConfig->instanceNo, \
                                                   (channelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }

    return (Icu_ValueType)timeElapsed;
}

#endif /* STD_ON == ICU_GET_TIME_ELAPSED_API */

#if (STD_ON == ICU_DUAL_CLOCK_MODE_API)
/**
 * @brief This function sets the module prescalers based on the input mode.
 * 
 * @param moduleConfig 
 * @param selectPrescaler Prescaler type ( Normal or Alternate )
 * @param modulesNumber 
 */
void Icu_Ipw_SetClockMode(const Icu_Ipw_IpConfigType (*moduleConfig)[], Icu_SelectPrescalerType selectPrescaler, uint8 modulesNumber)
{
    uint8              index;
    uint8              module;

    Icu_Ipw_ModuleType ipType;

    for(index = 0; index < modulesNumber; index++)
    {
        ipType = (*moduleConfig)[index].instanceIp;
        module = (*moduleConfig)[index].instanceNo;

        /* Select IP type case. */
        switch(ipType)
        {
            case ICU_EMIOS_MODULE:
                {
#if (STD_ON == EMIOS_ICU_IP_USED)
                    Emios_Icu_Ip_SetClockMode(module, \
                        (*moduleConfig)[index].pEmiosHwIpConfig, \
                        (selectPrescaler == ICU_ALTERNATE_CLOCK_MODE)?EMIOS_ICU_ALTERNATE_CLK:EMIOS_ICU_NORMAL_CLK);
#endif  /* EMIOS_ICU_IP_USED */
                    break;
                }
            case ICU_SIUL2_MODULE:
                {
#if (STD_ON == SIUL2_ICU_IP_USED)
                    Siul2_Icu_Ip_SetClockMode(module, \
                        (selectPrescaler == ICU_ALTERNATE_CLOCK_MODE)?SIUL2_ICU_ALTERNATE_CLK:SIUL2_ICU_NORMAL_CLK);
#endif  /* SIUL2_ICU_IP_USED */
                    break;
                }
            default:
                {
                    /* Do nothing. */
                    break;
                }
        }
    }
}
#endif /* STD_ON == ICU_DUAL_CLOCK_MODE_API */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
Icu_Ipw_StatusType Icu_Ipw_ValidateGetInputLevel(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    Icu_Ipw_StatusType valid = (Icu_Ipw_StatusType)ICU_IPW_ERROR;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                valid = (Icu_Ipw_StatusType)ICU_IPW_SUCCESS;
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                valid = (Icu_Ipw_StatusType)ICU_IPW_ERROR;
                break;
            }
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
Std_ReturnType Icu_Ipw_ValidateSignalMeasureWithoutInterrupt(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    Std_ReturnType valid = (Std_ReturnType)E_NOT_OK;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                valid = (Std_ReturnType)Emios_Icu_Ip_ValidateSignalMeasureWithoutInterrupt(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
    
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
void Icu_Ipw_GetPulseWidth(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_EMIOS_MODULE:
            {
#if (STD_ON == EMIOS_ICU_IP_USED)
                Emios_Icu_Ip_GetPulseWidth(ChannelConfig->instanceNo, \
                               (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
#endif  /* EMIOS_ICU_IP_USED */
                break;
            }
        default:
            {
                /* Do nothing. */
                break;
            }
    }
}
#endif /* (ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

void Icu_Ipw_EnableNotification(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
#if (STD_ON == EMIOS_ICU_IP_USED)
        case ICU_EMIOS_MODULE:
        {
            Emios_Icu_Ip_EnableNotification(ChannelConfig->instanceNo, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
            break;
        }
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
        case ICU_SIUL2_MODULE:
        {
            Siul2_Icu_Ip_EnableNotification(ChannelConfig->instanceNo, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
            break;
        }
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
        case ICU_WKPU_MODULE:
        {
            Wkpu_Ip_EnableNotification((ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
            break;
        }
#endif  /* WKPU_IP_USED */
#if (STD_ON == CMP_IP_USED)
        case ICU_CMP_MODULE:
        {
            Cmp_Ip_EnableNotification(ChannelConfig->instanceNo);
            break;
        }
#endif  /* CMP_IP_USED */
        default:
        {
            /* Do nothing. */
        }
        break;
    }
}

void Icu_Ipw_DisableNotification(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
#if (STD_ON == EMIOS_ICU_IP_USED)
        case ICU_EMIOS_MODULE:
        {
            Emios_Icu_Ip_DisableNotification(ChannelConfig->instanceNo, (ChannelConfig->pEmiosHwChannelConfig)->hwChannel);
            break;
        }
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
        case ICU_SIUL2_MODULE:
        {
            Siul2_Icu_Ip_DisableNotification(ChannelConfig->instanceNo, (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
            break;
        }
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
        case ICU_WKPU_MODULE:
        {
            Wkpu_Ip_DisableNotification((ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
            break;
        }
#endif  /* WKPU_IP_USED */
#if (STD_ON == CMP_IP_USED)
        case ICU_CMP_MODULE:
        {
            Cmp_Ip_DisableNotification(ChannelConfig->instanceNo);
            break;
        }
#endif  /* CMP_IP_USED */
        default:
        {
            /* Do nothing. */
        }
        break;
    }
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
