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
 *   @file       Icu_MBDT_PBcfg.c
 *   @version    5.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup icu Icu Driver
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
#include "Icu.h"
#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_MBDT_PBcfg.h"

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
#include "CDD_Mcl.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define ICU_MBDT_PBCFG_VENDOR_ID_C                    43
#define ICU_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define ICU_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define ICU_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define ICU_MBDT_PBCFG_SW_MAJOR_VERSION_C             5
#define ICU_MBDT_PBCFG_SW_MINOR_VERSION_C             0
#define ICU_MBDT_PBCFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_MBDT_PBcfg.c and Std_Types.h are different"
    #endif

    #if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        #if ((ICU_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_MCL_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_MCL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_MBDT_PBcfg.c and CDD_Mcl.h are different"
        #endif
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_MBDT_PBCFG_VENDOR_ID_C != ICU_VENDOR_ID)
    #error "Icu_MBDT_PBcfg.c and Icu.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_MBDT_PBcfg.c and Icu.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_MBDT_PBCFG_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_MBDT_PBCFG_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION) || \
     (ICU_MBDT_PBCFG_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_MBDT_PBcfg.c and Icu.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_MBDT_PBCFG_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_MBDT_PBcfg.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_MBDT_PBcfg.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_MBDT_PBCFG_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_MBDT_PBCFG_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_MBDT_PBCFG_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_MBDT_PBcfg.c and Icu_Ipw_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_MBDT_PBCFG_VENDOR_ID_C != ICU_IPW_MBDT_PBCFG_VENDOR_ID)
    #error "Icu_MBDT_PBcfg.c and Icu_Ipw_MBDT_PBcfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_MBDT_PBcfg.c and Icu_Ipw_MBDT_PBcfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_MBDT_PBCFG_SW_MAJOR_VERSION_C != ICU_IPW_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (ICU_MBDT_PBCFG_SW_MINOR_VERSION_C != ICU_IPW_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (ICU_MBDT_PBCFG_SW_PATCH_VERSION_C != ICU_IPW_MBDT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_MBDT_PBcfg.c and Icu_Ipw_MBDT_PBcfg.h are different"
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

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
* @brief External Notifications for Timestamp
*
*/
extern void MBDT_ICU_Timestamp_Callback(void);
/**
* @brief External Notifications for Edge Detection
*
*/
extern void MBDT_USER_SW0_callback(void);
/**
 *   @brief  Overflow notification handlers
 */
extern void MBDT_ICU_OverflowNotif(void);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*
*   @brief Translation LUT for Logical channel number to Partition Configuration indexed location
*/
static const uint8 Icu_ChIndexMap_PB_MBDT[4U] = 
{
    0U,
    1U,
    2U,
    3U
};

/*
*  @brief    PB_MBDT Configuration
*/
static const Icu_ChannelConfigType Icu_ChannelConfig_PB_MBDT[4U]=
{
    /* IcuChannel_0 */
    {
        (boolean)FALSE,    /* Wakeup capability */
        ICU_RISING_EDGE,    /* Edge used */
        ICU_MODE_SIGNAL_EDGE_DETECT,    /* Measurement mode */
        (Icu_MeasurementSubModeType)0U,    /* Icu_MeasurementSubModeType */
        &MBDT_USER_SW0_callback,    /* Icu_Channel_Notification */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        (Mcl_ChannelType)NoMclDmaChannel,    /* Mcl_DmaChannel */
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        NULL_PTR,    /* Icu_Channel_OverflowNotification */
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        (Icu_WakeupValueType)0U,    /* Icu_Channel_WakeupValue */
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        &Icu_Ipw_IpChannelConfig_PB_MBDT[0U] /* Ipw channel pointer */
    },
    /* IcuChannel_1 */
    {
        (boolean)FALSE,    /* Wakeup capability */
        ICU_RISING_EDGE,    /* Edge used */
        ICU_MODE_SIGNAL_MEASUREMENT,    /* Measurement mode */
        (Icu_MeasurementSubModeType)ICU_DUTY_CYCLE,    /* Icu_MeasurementSubModeType */
        NULL_PTR,    /* Icu_Channel_Notification */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        (Mcl_ChannelType)NoMclDmaChannel,    /* Mcl_DmaChannel */
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        &MBDT_ICU_OverflowNotif,    /* Icu_Channel_OverflowNotification */
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        (Icu_WakeupValueType)0U,    /* Icu_Channel_WakeupValue */
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        &Icu_Ipw_IpChannelConfig_PB_MBDT[1U] /* Ipw channel pointer */
    },
    /* IcuChannel_2 */
    {
        (boolean)FALSE,    /* Wakeup capability */
        ICU_RISING_EDGE,    /* Edge used */
        ICU_MODE_TIMESTAMP,    /* Measurement mode */
        (Icu_MeasurementSubModeType)ICU_CIRCULAR_BUFFER,    /* Icu_MeasurementSubModeType */
        &MBDT_ICU_Timestamp_Callback,    /* Icu_Channel_Notification */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        (Mcl_ChannelType)NoMclDmaChannel,    /* Mcl_DmaChannel */
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        &MBDT_ICU_OverflowNotif,    /* Icu_Channel_OverflowNotification */
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        (Icu_WakeupValueType)0U,    /* Icu_Channel_WakeupValue */
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        &Icu_Ipw_IpChannelConfig_PB_MBDT[2U] /* Ipw channel pointer */
    },
    /* IcuChannel_3 */
    {
        (boolean)FALSE,    /* Wakeup capability */
        ICU_RISING_EDGE,    /* Edge used */
        ICU_MODE_EDGE_COUNTER,    /* Measurement mode */
        (Icu_MeasurementSubModeType)ICU_RISING_EDGE,    /* Starting edge */
        NULL_PTR,    /* Icu_Channel_Notification */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        (Mcl_ChannelType)NoMclDmaChannel,    /* Mcl_DmaChannel */
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        NULL_PTR,    /* Icu_Channel_OverflowNotification */
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        (Icu_WakeupValueType)0U,    /* Icu_Channel_WakeupValue */
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        &Icu_Ipw_IpChannelConfig_PB_MBDT[3U] /* Ipw channel pointer */
    }
};

/*
*   @brief Postbuild Configuration for each Partition
*/
const Icu_ConfigType Icu_Config_MBDT=
{
    (uint8)4,
    /** @brief The number of channels configured*/
    &Icu_ChannelConfig_PB_MBDT,
    /** @brief Icu Channel Configuration Pointer */
    (uint8)3, /* The number of IP instances configured*/
    /** @brief Icu Instance Configuration Pointer */
    &Icu_Ipw_IpConfig_PB_MBDT,
    /** @brief Index of channel in each partition map table*/
    &Icu_ChIndexMap_PB_MBDT,
    /** @brief Partition index*/
    (uint32)0U
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

