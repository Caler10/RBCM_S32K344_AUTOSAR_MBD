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

#ifndef CMP_IP_TYPES_H
#define CMP_IP_TYPES_H

/**
 *     @file
 *
 *     @addtogroup cmp_icu_ip CMP IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Cmp_Ip_Defines.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CMP_IP_TYPES_VENDOR_ID                     43
#define CMP_IP_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define CMP_IP_TYPES_AR_RELEASE_MINOR_VERSION      7
#define CMP_IP_TYPES_AR_RELEASE_REVISION_VERSION   0
#define CMP_IP_TYPES_SW_MAJOR_VERSION              5
#define CMP_IP_TYPES_SW_MINOR_VERSION              0
#define CMP_IP_TYPES_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (CMP_IP_TYPES_VENDOR_ID != CMP_IP_DEFINES_VENDOR_ID)
    #error "Cmp_Ip_Types.h and Cmp_Ip_Defines.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((CMP_IP_TYPES_AR_RELEASE_MAJOR_VERSION != CMP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CMP_IP_TYPES_AR_RELEASE_MINOR_VERSION != CMP_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CMP_IP_TYPES_AR_RELEASE_REVISION_VERSION != CMP_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Cmp_Ip_Types.h and Cmp_Ip_Defines.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((CMP_IP_TYPES_SW_MAJOR_VERSION != CMP_IP_DEFINES_SW_MAJOR_VERSION) || \
     (CMP_IP_TYPES_SW_MINOR_VERSION != CMP_IP_DEFINES_SW_MINOR_VERSION) || \
     (CMP_IP_TYPES_SW_PATCH_VERSION != CMP_IP_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Cmp_Ip_Types.h and Cmp_Ip_Defines.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
#if (STD_ON == CMP_IP_USED)

typedef enum
{
    CMP_IP_STATUS_SUCCESS,
    CMP_IP_STATUS_ERROR
} Cmp_Ip_StatusType;

typedef enum {
    CMP_IP_FUNCTIONALMODE_DISABLED,
    CMP_IP_FUNCTIONALMODE_CONTINUOUS,
    CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_INT_CLK,
    CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_EXT_CLK,
    CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_INT_CLK,
    CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_EXT_CLK,
    CMP_IP_FUNCTIONALMODE_WINDOWED,
    CMP_IP_FUNCTIONALMODE_WINDOWED_RESAMPLED,
    CMP_IP_FUNCTIONALMODE_WINDOWED_FILTERED
} Cmp_Ip_FunctionalModeType;

typedef enum {
    CMP_IP_HYSTERESISLEVEL_0 = 0u,
    CMP_IP_HYSTERESISLEVEL_1 = 1u,
    CMP_IP_HYSTERESISLEVEL_2 = 2u,
    CMP_IP_HYSTERESISLEVEL_3 = 3u,
} Cmp_Ip_HysteresisLevelType;

typedef enum {
    CMP_IP_OFFSETLEVEL_0 = 0x00u,
    CMP_IP_OFFSETLEVEL_1 = 0x01u,
} Cmp_Ip_OffsetLevelType;

typedef enum {
    CMP_IP_INPUTMUX_IN0 = 0x00u, /* INxSEL = 0x01. xSEL=0 */
    CMP_IP_INPUTMUX_IN1 = 0x01u, /* INxSEL = 0x01. xSEL=1 */
    CMP_IP_INPUTMUX_IN2 = 0x02u,
    CMP_IP_INPUTMUX_IN3 = 0x03u,
    CMP_IP_INPUTMUX_IN4 = 0x04u,
    CMP_IP_INPUTMUX_IN5 = 0x05u,
    CMP_IP_INPUTMUX_IN6 = 0x06u,
    CMP_IP_INPUTMUX_IN7 = 0x07u,
    CMP_IP_INPUTMUX_DAC = 0x80u, /* INxSEL = 0x00. xSEL=0 */
} Cmp_Ip_InputMuxType;

typedef enum {
    CMP_IP_INTTRIG_NONE         = 0x00u,
    CMP_IP_INTTRIG_FALLING_EDGE = 0x01u,
    CMP_IP_INTTRIG_RISING_EDGE  = 0x02u,
    CMP_IP_INTTRIG_BOTH_EDGES   = 0x03u,
} Cmp_Ip_OutputInterruptTriggerType;

typedef enum {
    CMP_IP_OUTPUTSELECT_COUT    = 0x00u,
    CMP_IP_OUTPUTSELECT_COUTA   = 0x01u,
} Cmp_Ip_OutputSelectType;

typedef enum {
    CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_DISABLED  = 0x00u,
    CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_LOW       = 0x01u,
    CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_HIGH      = 0x02u,
} Cmp_Ip_WindowCloseOutputOverwriteType;

typedef enum {
    CMP_IP_WINDOWCLOSEEVENT_RISING  = 0x00u,
    CMP_IP_WINDOWCLOSEEVENT_FALLING = 0x01u,
    CMP_IP_WINDOWCLOSEEVENT_BOTH    = 0x02u,
    CMP_IP_WINDOWCLOSEEVENT_NONE    = 0x04u,
} Cmp_Ip_WindowCloseEventType;

typedef enum {
    CMP_IP_VOLTAGEREFSOURCE_VREF0 = 0x00u,
    CMP_IP_VOLTAGEREFSOURCE_VREF1 = 0x01u,
} Cmp_Ip_VoltageRefSourceType;

typedef enum {
    CMP_IP_DACPOWERSTATE_DISABLED   = 0x00u, /*< DAC disabled */
    CMP_IP_DACPOWERSTATE_ENABLED    = 0x01u, /*< DAC enabled */
    CMP_IP_DACPOWERSTATE_LINKED     = 0x02u, /*< DAC enablement linked to comparator */
} Cmp_Ip_DacPowerStateType;

typedef enum {
    CMP_IP_SAMPLEDELAY_0_CYCLES = 0x00u,
    CMP_IP_SAMPLEDELAY_1_CYCLES = 0x01u,
    CMP_IP_SAMPLEDELAY_2_CYCLES = 0x02u,
    CMP_IP_SAMPLEDELAY_3_CYCLES = 0x03u,
} Cmp_Ip_SampleDelayType;

typedef enum {
    CMP_IP_FIXEDCHANNEL_0 = 0x00u,
    CMP_IP_FIXEDCHANNEL_1 = 0x01u,
    CMP_IP_FIXEDCHANNEL_2 = 0x02u,
    CMP_IP_FIXEDCHANNEL_3 = 0x03u,
    CMP_IP_FIXEDCHANNEL_4 = 0x04u,
    CMP_IP_FIXEDCHANNEL_5 = 0x05u,
    CMP_IP_FIXEDCHANNEL_6 = 0x06u,
    CMP_IP_FIXEDCHANNEL_7 = 0x07u,
} Cmp_Ip_FixedChannelType;

typedef enum {
    CMP_IP_FIXEDPORT_PLUS  = 0x00u,
    CMP_IP_FIXEDPORT_MINUS = 0x01u,
} Cmp_Ip_FixedPortType;

/** @brief    CMP initialization status */
typedef enum
{
    ICU_CMP_IP_UNINIT,
    ICU_CMP_IP_INIT
} Cmp_Ip_StateEType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Callback type for each channel */
typedef void (*Cmp_Ip_TriggerNotificationType) (uint16 CallbackParam1, boolean CallbackParam2);
typedef void (*Cmp_Ip_ComparatorNotificationType) (uint16 CallbackParam1, boolean CallbackParam2);

/**
 * @brief    CMP IP state structure.
 * @details  This structure is used by the IPL driver for internal logic.
 *           The content is populated at initialization time.
 */
typedef struct
{
    Cmp_Ip_StateEType                   State;
    Cmp_Ip_OutputInterruptTriggerType   CmpInterruptEdge;
    boolean                             NotificationEnabled;
    Cmp_Ip_TriggerNotificationType      TriggerNotification;
    Cmp_Ip_ComparatorNotificationType   ComparatorNotification;
    uint16                              CallbackParam1;
} Cmp_Ip_StateType;


typedef struct
{
    Cmp_Ip_FunctionalModeType               FunctionalMode;
    Cmp_Ip_HysteresisLevelType              HysteresisLevel;
    Cmp_Ip_OffsetLevelType                  OffsetLevel;
    boolean                                 EnablePinOutput;
    boolean                                 EnableInverter;
    boolean                                 EnableHighPowerMode;
    uint8                                   FilterSamplePeriod;
    uint8                                   FilterSampleCount;
    boolean                                 EnableDma;
    Cmp_Ip_InputMuxType                     NegativeInputMux;
    Cmp_Ip_InputMuxType                     PositiveInputMux;
    Cmp_Ip_OutputInterruptTriggerType       OutputInterruptTrigger;     /* this is mapped to IcuDefaultStartEdge */
    boolean                                 EnableComparatorInvert;
    Cmp_Ip_WindowCloseOutputOverwriteType   WindowCloseOutputOverwrite;
    Cmp_Ip_WindowCloseEventType             WindowCloseEvent;
    boolean                                 EnableInStop;
    Cmp_Ip_OutputSelectType                 OutputSelect;
} Cmp_Ip_ComparatorConfigType;

typedef struct
{
    uint8                       VoltageLevel;
    Cmp_Ip_VoltageRefSourceType VoltageRefSource;
    Cmp_Ip_DacPowerStateType    PowerState;

} Cmp_Ip_DacConfigType;

typedef struct
{
    uint8                   RoundRobinEnChannelMask;
    uint8                   PrepgmStateChannelMask;
    uint8                   InitDelayValue;
    Cmp_Ip_SampleDelayType  SampleDelay;
    Cmp_Ip_FixedChannelType FixedChannel;
    Cmp_Ip_FixedPortType    FixedPort;
    boolean                 EnableRoundRobinInterrupt;
    boolean                 EnableRoundRobin;
} Cmp_Ip_TriggerConfigType;

typedef struct
{
    uint8                               Instance;
    Cmp_Ip_ComparatorConfigType         Comparator;
    Cmp_Ip_DacConfigType                Dac;
    Cmp_Ip_TriggerConfigType            Trigger;
    Cmp_Ip_TriggerNotificationType      TriggerNotification;
    Cmp_Ip_ComparatorNotificationType   ComparatorNotification;
    uint16                              CallbackParam1;
} Cmp_Ip_ConfigType;

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* CMP_IP_USED */

#ifdef __cplusplus
}
#endif

/**@}*/

#endif  /* CMP_IP_TYPES_H */
