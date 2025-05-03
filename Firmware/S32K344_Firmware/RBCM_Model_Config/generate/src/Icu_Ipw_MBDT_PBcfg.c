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
 *   @file       Icu_Ipw_MBDT_PBcfg.c
 *   @version    5.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup icu_ipw
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
*================================================================================================*/
#include "Std_Types.h"
#include "Icu_Ipw_Types.h"
#include "Siul2_Icu_Ip.h"
#include "Wkpu_Ip.h"
#include "Cmp_Ip.h"
#include "Emios_Icu_Ip.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define ICU_IPW_MBDT_PBCFG_VENDOR_ID_C                   43
#define ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    4
#define ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C    7
#define ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C 0
#define ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C            5
#define ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C            0
#define ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C            0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_MBDT_PBCFG_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Ipw_MBDT_PBcfg.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if  source file and Icu_Ipw_Types.h file are of the same Autosar version */
#if ((ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types.h file are of the same Software version */
#if ((ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Icu_Ipw_Types.h are different"
#endif

/* Check if  source file and Siul2_Icu_Ip.h file are of the same Autosar version */
#if (ICU_IPW_MBDT_PBCFG_VENDOR_ID_C != SIUL2_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw_MBDT_PBcfg.c and Siul2_Icu_Ip.h have different vendor IDs"
#endif
/* Check if  source file and Siul2_Icu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Siul2_Icu_Ip.h are different"
#endif
/* Check if source file and Siul2_Icu_Ip.h file are of the same Software version */
#if ((ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != SIUL2_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != SIUL2_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != SIUL2_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Siul2_Icu_Ip.h are different"
#endif

/* Check if  source file and Wkpu_Ip.h file are of the same Autosar version */
#if (ICU_IPW_MBDT_PBCFG_VENDOR_ID_C != WKPU_IP_VENDOR_ID)
    #error "Icu_Ipw_MBDT_PBcfg.c and Wkpu_Ip.h have different vendor IDs"
#endif
/* Check if  source file and Wkpu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != WKPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != WKPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != WKPU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Wkpu_Ip.h are different"
#endif
/* Check if source file and Wkpu_Ip.h file are of the same Software version */
#if ((ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != WKPU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != WKPU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != WKPU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Wkpu_Ip.h are different"
#endif

/* Check if  source file and Cmp_Ip.h file are of the same Autosar version */
#if (ICU_IPW_MBDT_PBCFG_VENDOR_ID_C != CMP_IP_VENDOR_ID)
    #error "Icu_Ipw_MBDT_PBcfg.c and Cmp_Ip.h have different vendor IDs"
#endif
/* Check if  source file and Cmp_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CMP_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != CMP_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != CMP_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Cmp_Ip.h are different"
#endif
/* Check if source file and Cmp_Ip.h file are of the same Software version */
#if ((ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != CMP_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != CMP_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != CMP_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Cmp_Ip.h are different"
#endif

/* Check if  source file and Emios_Icu_Ip.h file are of the same Autosar version */
#if (ICU_IPW_MBDT_PBCFG_VENDOR_ID_C != EMIOS_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw_MBDT_PBcfg.c and Emios_Icu_Ip.h have different vendor IDs"
#endif
/* Check if  source file and Emios_Icu_Ip.h file are of the same Autosar version */
#if ((ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Emios_Icu_Ip.h are different"
#endif
/* Check if source file and Emios_Icu_Ip.h file are of the same Software version */
#if ((ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION_C != EMIOS_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION_C != EMIOS_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION_C != EMIOS_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_MBDT_PBcfg.c and Emios_Icu_Ip.h are different"
#endif
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*
 *   @brief This index relates the Hardware channels with the respective ICU channel. *
 *   When an normal interrupt is asserted this index is used to locate the corresponding ICU channel
 */

/** 
 * @brief   Icu channels IP related configuration array
 */
const Icu_Ipw_ChannelConfigType Icu_Ipw_IpChannelConfig_PB_MBDT[4U] =
{

    /** @brief IcuChannel_0 */
    {
        /** @brief IP type of this channel */
        ICU_SIUL2_MODULE,
        /** @brief Instance number */
        (uint8)0U,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief Emios IP channel pointer */
        NULL_PTR,
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief Wkpu IP channel pointer */
        NULL_PTR,
    #if (defined(ICU_IPW_WKPU_NMI_API_USED))
        /** @brief Wkpu NMI pointer */
        NULL_PTR,
    #endif
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief Siul2 IP channel pointer */
        &Siul2_Icu_Ip_0_ChannelConfig_PB_MBDT[0U],
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief Cmp IP channel pointer */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief Index in the configuration table of the channels */
        (uint8)0U
    },
    /** @brief IcuChannel_1 */
    {
        /** @brief IP type of this channel */
        ICU_EMIOS_MODULE,
        /** @brief Instance number */
        (uint8)2U,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief Emios IP channel pointer */
        &eMios_Icu_Ip_2_ChannelConfig_PB_MBDT[0U],
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief Wkpu IP channel pointer */
        NULL_PTR,
    #if (defined(ICU_IPW_WKPU_NMI_API_USED))
        /** @brief Wkpu NMI pointer */
        NULL_PTR,
    #endif
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief Siul2 IP channel pointer */
        NULL_PTR,
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief Cmp IP channel pointer */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief Index in the configuration table of the channels */
        (uint8)0U
    },
    /** @brief IcuChannel_2 */
    {
        /** @brief IP type of this channel */
        ICU_EMIOS_MODULE,
        /** @brief Instance number */
        (uint8)2U,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief Emios IP channel pointer */
        &eMios_Icu_Ip_2_ChannelConfig_PB_MBDT[1U],
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief Wkpu IP channel pointer */
        NULL_PTR,
    #if (defined(ICU_IPW_WKPU_NMI_API_USED))
        /** @brief Wkpu NMI pointer */
        NULL_PTR,
    #endif
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief Siul2 IP channel pointer */
        NULL_PTR,
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief Cmp IP channel pointer */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief Index in the configuration table of the channels */
        (uint8)1U
    },
    /** @brief IcuChannel_3 */
    {
        /** @brief IP type of this channel */
        ICU_EMIOS_MODULE,
        /** @brief Instance number */
        (uint8)0U,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief Emios IP channel pointer */
        &eMios_Icu_Ip_0_ChannelConfig_PB_MBDT[0U],
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief Wkpu IP channel pointer */
        NULL_PTR,
    #if (defined(ICU_IPW_WKPU_NMI_API_USED))
        /** @brief Wkpu NMI pointer */
        NULL_PTR,
    #endif
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief Siul2 IP channel pointer */
        NULL_PTR,
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief Cmp IP channel pointer */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief Index in the configuration table of the channels */
        (uint8)0U
    }
};

/**
 * @brief   Icu instances related configuration array
 */
const Icu_Ipw_IpConfigType Icu_Ipw_IpConfig_PB_MBDT[3U] =
{
    {
        /** @brief IP type */
        ICU_EMIOS_MODULE,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief pointer to Emios HW configuration of instance */
        &eMios_Icu_Ip_0_Config_PB_MBDT,
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief pointer to Wkpu HW configuration of instance */
        NULL_PTR,
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief pointer to Siul2 HW configuration of instance */
        NULL_PTR,
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief pointer to LpCmp HW configuration of instance */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief IP instance number */
        (uint8)0U
    },
    {
        /** @brief IP type */
        ICU_EMIOS_MODULE,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief pointer to Emios HW configuration of instance */
        &eMios_Icu_Ip_2_Config_PB_MBDT,
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief pointer to Wkpu HW configuration of instance */
        NULL_PTR,
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief pointer to Siul2 HW configuration of instance */
        NULL_PTR,
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief pointer to LpCmp HW configuration of instance */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief IP instance number */
        (uint8)2U
    },
    {
        /** @brief IP type */
        ICU_SIUL2_MODULE,
    #if (STD_ON == EMIOS_ICU_IP_USED)
        /** @brief pointer to Emios HW configuration of instance */
        NULL_PTR,
    #endif  /* EMIOS_ICU_IP_USED */
    #if (STD_ON == WKPU_IP_USED)
        /** @brief pointer to Wkpu HW configuration of instance */
        NULL_PTR,
    #endif  /* WKPU_IP_USED */
    #if (STD_ON == SIUL2_ICU_IP_USED)
        /** @brief pointer to Siul2 HW configuration of instance */
        &Siul2_Icu_Ip_0_Config_PB_MBDT,
    #endif  /* SIUL2_ICU_IP_USED */
    #if (STD_ON == CMP_IP_USED)
        /** @brief pointer to LpCmp HW configuration of instance */
        NULL_PTR,
    #endif  /* CMP_IP_USED */
        /** @brief IP instance number */
        (uint8)0U
    }
};


#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

