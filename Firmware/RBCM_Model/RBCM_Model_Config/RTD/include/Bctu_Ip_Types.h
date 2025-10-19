/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

#ifndef BCTU_IP_TYPES_H
#define BCTU_IP_TYPES_H

/**
*   @file
*
*   @addtogroup bctu_ip
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
#include "StandardTypes.h"
#include "Bctu_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BCTU_IP_VENDOR_ID_TYPES                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_TYPES       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_TYPES    0
#define BCTU_IP_SW_MAJOR_VERSION_TYPES               5
#define BCTU_IP_SW_MINOR_VERSION_TYPES               0
#define BCTU_IP_SW_PATCH_VERSION_TYPES               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip_Types.h file and Bctu_Ip_CfgDefines.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_TYPES != BCTU_IP_VENDOR_ID_CFGDEFINES)
    #error "Bctu_Ip_Types.h and Bctu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Bctu_Ip_Types.h file and Bctu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES != BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_TYPES != BCTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_TYPES != BCTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_Types.h and Bctu_Ip_CfgDefines.h are different"
#endif

/* Check if Bctu_Ip_Types.h file and Bctu_Ip_CfgDefines.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_TYPES != BCTU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_SW_MINOR_VERSION_TYPES != BCTU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (BCTU_IP_SW_PATCH_VERSION_TYPES != BCTU_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Bctu_Ip_Types.h and Bctu_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_Types.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief BCTU status return type
 *
 * This structure is used as return type
 *
 * Implements : Bctu_Ip_StatusType_Class
 */
typedef enum
{
    BCTU_IP_STATUS_SUCCESS  = 0x00u,   /*!< Function completed successfully */
    BCTU_IP_STATUS_ERROR    = 0x01u,   /*!< Function didn't complete successfully */
    BCTU_IP_STATUS_TIMEOUT  = 0x02u,   /*!< Function timed out */
    BCTU_IP_STATUS_BUSY     = 0x03u    /*!< Functionality busy */
} Bctu_Ip_StatusType;

/*!
 * @brief Enumeration for selecting data destination
 *
 * This enumeration selects the data destination
 *
 * Implements : Bctu_Ip_TrigDataDestType_Class
 */
typedef enum {
    BCTU_IP_DATA_DEST_ADC_DATA_REG = 0x00u,
    BCTU_IP_DATA_DEST_FIFO1        = 0x01u,
    BCTU_IP_DATA_DEST_FIFO2        = 0x02u,
    BCTU_IP_DATA_DEST_FIFO3        = 0x03u
} Bctu_Ip_TrigDataDestType;

/*!
 * @brief Enumeration for selecting trigger type
 *
 * This enumeration selects the trigger type
 *
 * Implements : Bctu_Ip_TrigType_Class
 */
typedef enum {
    BCTU_IP_TRIG_TYPE_SINGLE = 0x00u,
    BCTU_IP_TRIG_TYPE_LIST   = 0x01u
} Bctu_Ip_TrigType;

/*!
 * @brief Structure for configuring Adc notification
 *
 * This structure is used for configuring Adc notification
 *
 * Implements : Bctu_Ip_AdcNotificationType_Class
 */
typedef struct {
    void (*NewConvDataNotification)(void);
    void (*ConvDataOverrunNotification)(void);
    void (*ListLastConversionNotification)(void);
} Bctu_Ip_AdcNotificationType;

/*!
 * @brief Structure for storing channel information
 *
 * This structure is used for storing channel information.
 *
 * Implements : Bctu_Ip_ListItemConfigType_Class
 */
typedef struct {
    boolean NextChanWaitOnTrig;
    uint8 AdcChanIndex;
    boolean LastChanInList;
} Bctu_Ip_ListItemConfigType;

/*!
 * @brief Structure for storing channel information at runtime
 *
 * This structure is used for storing channel information at runtime.
 *
 * Implements : Bctu_Ip_ListItemType_Class
 */
typedef struct {
    boolean NextChanWaitOnTrig;
    uint8 AdcChanIndex;
} Bctu_Ip_ListItemType;

/*!
 * @brief Structure for configuring BCTU FIFO
 *
 * This structure is used for configuring the BCTU FIFO.
 *
 * Implements : Bctu_Ip_FifoConfigType_Class
 */
typedef struct {
    uint8 FifoIndex;
    uint8 WatermarkValue;
    boolean FifoDmaEnable;
    uint32 FifoDmaChannel;
#ifdef BCTU_IP_FIFO_DMA_RAW_EN
    uint32 ** UserFifoBuffer;
#else
    uint16 ** UserFifoBuffer;
#endif
    boolean bEnNotif;
    void (*WatermarkNotification)(void);
    void (*UnderrunNotification)(void);
    void (*OverrunNotification)(void);
} Bctu_Ip_FifoConfigType;

/*!
 * @brief Store BCTU FIFO notifications
 *
 * This structure is used for storing BCTU FIFO notifications
 *
 * Implements : Bctu_Ip_FifoNotificationType_Class
 */
typedef struct {
    void (*WatermarkNotification)(void);
    void (*UnderrunNotification)(void);
    void (*OverrunNotification)(void);
} Bctu_Ip_FifoNotificationType;

/*!
 * @brief Structure for configuring a trigger configuration register.
 *
 * This structure is used for configuring a trigger configuration register (TRGCFG)
 *
 * Implements : Bctu_Ip_TrigConfigType_Class
 */
typedef struct {
    uint8 TrigIndex;
    boolean LoopEn;                  /*!< Select if a trigger (hw or sw) starts a loop of conversions. */
    Bctu_Ip_TrigDataDestType DataDest;
    boolean HwTriggersEn;            /*!< Enable/disable initiation of ADC conversions by hw input trigger: true - enabled; false - disabled. */
    Bctu_Ip_TrigType TrigType;
    uint8 AdcTargetMask;        /*!< Bitmask to select target ADC instance(s): (1 << n) corresponds to n-th ADC instance. */
    uint8 AdcChanOrListStart;
} Bctu_Ip_TrigConfigType;

/*!
 * @brief Structure for storing full information of the conversion result
 *
 * This structure is used for storing full information of the conversion result
 *
 * Implements : Bctu_Ip_ResultType_Class
 */
typedef struct {
    uint8 TriggerIdx;     /*!< Index of the trigger which started the conversion. */
    uint8 ChanIdx;        /*!< Index of the ADC channel which executed the conversion. */
    uint16 AdcData;      /*!< Conversion result data. */
    boolean ListFlag;      /*!< Conversion initiated from a LIST: true / false. */
    boolean LastFlag;      /*!< Last conversion in a LIST: true / false */
} Bctu_Ip_ResultType;

/*!
 * @brief Structure for storing full information of the conversion result stored in the FIFO
 *
 * This structure is used for storing full information of the conversion result stored in the FIFO
 *
 * Implements : Bctu_Ip_FifoResultType_Class
 */
typedef struct {
    uint8 TriggerIdx;     /*!< Index of the trigger which started the conversion. */
    uint8 ChanIdx;        /*!< Index of the ADC channel which executed the conversion. */
    uint8 AdcNum;         /*!< Index of the ADC instance which executed the conversion. */
    uint16 AdcData;      /*!< Conversion result data. */
} Bctu_Ip_FifoResultType;

/*!
 * @brief Structure for configuring global BCTU functionalities
 *
 * This structure is used for configuring global BCTU functionalities
 *
 * Implements : Bctu_Ip_ConfigType_Class
 */
typedef struct {
    boolean LowPowerModeEn;                /*!< Low power operating mode: true - low power; false - normal operating mode. */
    boolean GlobalHwTriggersEn;            /*!< HW triggers globally enabled/disabled: true - enabled; false - all hw triggers disabled (BCTU in freeze mode). */
    uint8 NewDataDmaEnMask;               /*!< Bitmask for DMA transfer enable per ADC instance: (1 << n) corresponds to n-th ADC instance. */

    void (*TriggerNotification)(void);     /*!< TRGF */

    Bctu_Ip_AdcNotificationType AdcNotifications[FEATURE_BCTU_NUM_ADC];

    uint8 NumTrigConfigs;
    const Bctu_Ip_TrigConfigType * TrigConfigs;

    uint8 NumListItems;
    const Bctu_Ip_ListItemConfigType * ListItemConfigs;

    uint8 NumFifoConfigs;
    const Bctu_Ip_FifoConfigType * FifoConfigs;
} Bctu_Ip_ConfigType;

/*!
 * @brief Structure used to store runtime info
 *
 * This structure is used to store BCTU runtime info
 *
 * Implements : Bctu_Ip_StateStructType_Class
 */
typedef struct {
    boolean InitStatus;                          /*!< Check if the driver was initialized. */
    void (*TriggerNotification)(void);     /*!< TRGF */
    Bctu_Ip_AdcNotificationType AdcNotifications[FEATURE_BCTU_NUM_ADC];
    Bctu_Ip_FifoNotificationType FifoNotifications[BCTU_IP_FIFO_COUNT];
} Bctu_Ip_StateStructType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* BCTU_IP_TYPES_H */
