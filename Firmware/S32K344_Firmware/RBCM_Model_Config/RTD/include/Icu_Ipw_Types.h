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

#ifndef ICU_IPW_TYPES_H
#define ICU_IPW_TYPES_H

/**
 *     @file
 *
 *     @internal
 *     @addtogroup icu_ipw Icu_Ipw Driver
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
#include "Emios_Icu_Ip_Types.h"
#include "Siul2_Icu_Ip_Types.h"
#include "Wkpu_Ip_Types.h"
#include "Cmp_Ip_Types.h"
#include "Icu_Cfg.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_TYPES_VENDOR_ID                       43
#define ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        7
#define ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     0
#define ICU_IPW_TYPES_SW_MAJOR_VERSION                5
#define ICU_IPW_TYPES_SW_MINOR_VERSION                0
#define ICU_IPW_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != EMIOS_ICU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Emios_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION  != EMIOS_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION  != EMIOS_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION   != EMIOS_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Emios_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION  != EMIOS_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION  != EMIOS_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION  != EMIOS_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_Types.h and Emios_Icu_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != SIUL2_ICU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Siul2_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Siul2_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION  != SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION  != SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION  != SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_Types.h and Siul2_Icu_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != WKPU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Wkpu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION  != WKPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION  != WKPU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION   != WKPU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Wkpu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION  != WKPU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION  != WKPU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION  != WKPU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_Types.h and Wkpu_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != CMP_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Cmp_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION  != CMP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION  != CMP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION   != CMP_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Cmp_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION  != CMP_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION  != CMP_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION  != CMP_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_Types.h and Cmp_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_CFG_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION  != ICU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION  != ICU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION   != ICU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION  != ICU_CFG_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION  != ICU_CFG_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION  != ICU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_Types.h and Icu_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Wakeup feature is currently enabled
*/
#define ICU_CHANNEL_STATE_WKUP                  (1U)

/**
* @brief The current channel status - IDLE / ACTIVE
*/
#define ICU_CHANNEL_STATE_IDLE                  (1U<<1)

/**
* @brief Notification is enabled
*/
#define ICU_CHANNEL_STATE_NOTIFICATION          (1U<<2)

/**
* @brief The current channel state
*/
#define ICU_CHANNEL_STATE_RUNNING               (1U<<3)

/**
* @brief Overflow flag
*/
#define ICU_CHANNEL_STATE_OVERFLOW              (1U<<4)

/**
* @brief Wakeup source
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE            (1U<<7)


#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/**
 * @brief  Definition majorloop count for dma
 */
#define ICU_DMA_MAJORLOOP_COUNT    ((uint32)2U)

/**
 * @brief  Definition majorloop count for dma
 */
#define ICU_DMA_MAJORLOOP_FIRST_COUNT    ((uint32)1U)
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if ((ICU_DEV_ERROR_DETECT == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
/**
 * @internal
 * @brief       Icu_Ipw_StatusType
 * @details     This indicates the operation success or fail
 */
typedef enum
{
    ICU_IPW_SUCCESS     = 0x0U,
    ICU_IPW_ERROR       = 0x1U
}Icu_Ipw_StatusType;
#endif

typedef enum
{
    ICU_EMIOS_MODULE = 0U,
    ICU_SIUL2_MODULE = 1U,
    ICU_WKPU_MODULE  = 3U,
    ICU_CMP_MODULE   = 4U
} Icu_Ipw_ModuleType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** 
 * @internal
 * @brief Icu channel low level configuration mapping.
 */
typedef struct
{
    /** @brief The IP used to implement this specific Icu channel */
    Icu_Ipw_ModuleType              channelIp;
    /** @brief The instance index used for the configuration of channel */
    uint8                           instanceNo;
#if (STD_ON == EMIOS_ICU_IP_USED)
    /** @brief Index in the Emios IP specific configuration table - aligned to respect Misra 11.5 */
    const eMios_Icu_Ip_ChannelConfigType  *pEmiosHwChannelConfig;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
    /** @brief Index in the Wkpu IP specific configuration table - aligned to respect Misra 11.5 */
    const Wkpu_Ip_ChannelConfigType       *pWkpuHwChannelConfig;
#if (defined(ICU_IPW_WKPU_NMI_API_USED))
    /** @brief Index in the Wkpu NMI specific configuration table - aligned to respect Misra 11.5 */
    const Wkpu_Ip_NmiCfgType              *pNmiConfig;
#endif
#endif  /* WKPU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
    /** @brief Index in the Siul2 IP specific configuration table - aligned to respect Misra 11.5 */
    const Siul2_Icu_Ip_ChannelConfigType  *pSiul2HwChannelConfig;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == CMP_IP_USED)
    /** @brief Index in the Cmp IP specific configuration table - aligned to respect Misra 11.5 */
    const Cmp_Ip_ConfigType               *pCmpHwChannelConfig; 
#endif  /* CMP_IP_USED */    
    /** @brief Index in the Ip configuration array */
    uint8                           index;
} Icu_Ipw_ChannelConfigType;

/** 
 * @internal
 * @brief      Icu instance low level configuration mapping.
 */
typedef struct
{
    /** @brief The IP type used. */
    Icu_Ipw_ModuleType      instanceIp;
#if (STD_ON == EMIOS_ICU_IP_USED)
    /** @brief Pointer to Emios IP specific configuration aligned to respect MISRA 11.5 */
    const eMios_Icu_Ip_ConfigType *pEmiosHwIpConfig;
#endif  /* EMIOS_ICU_IP_USED */
#if (STD_ON == WKPU_IP_USED)
    /** @brief Pointer to Wkpu IP specific configuration aligned to respect MISRA 11.5 */
    const Wkpu_Ip_IrqConfigType   *pWkpuHwIpConfig;
#endif  /* WKPU_IP_USED */
#if (STD_ON == SIUL2_ICU_IP_USED)
    /** @brief Pointer to Siul2 IP specific configuration aligned to respect MISRA 11.5 */
    const Siul2_Icu_Ip_ConfigType *pSiul2HwIpConfig;
#endif  /* SIUL2_ICU_IP_USED */
#if (STD_ON == CMP_IP_USED)
    /** @brief Pointer to Cmp IP specific configuration aligned to respect MISRA 11.5 */
    const Cmp_Ip_ConfigType       *pCmpHwIpConfig;    
#endif  /* CMP_IP_USED */
    /** @brief The instance number used. */
    uint8                   instanceNo;
} Icu_Ipw_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_IPW_TYPES_H */
