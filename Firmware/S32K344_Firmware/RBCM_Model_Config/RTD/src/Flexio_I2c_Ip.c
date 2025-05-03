/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
*     @addtogroup FLEXIO_I2C_DRIVER Flexio_I2c Driver
*     @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_I2c_Ip.h"
#include "Flexio_I2c_Ip_HwAccess.h"
#include "Flexio_I2c_Ip_Features.h"
#include "Flexio_I2c_Ip_Types.h"
#include "OsIf.h"
#include "Devassert.h"

#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
    #include "Dma_Ip.h"
#endif /* (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE) */
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_I2C_IP_VENDOR_ID_C                      43
#define FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_I2C_IP_SW_MAJOR_VERSION_C               5
#define FLEXIO_I2C_IP_SW_MINOR_VERSION_C               0
#define FLEXIO_I2C_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Flexio_I2c_Ip.h */
#if (FLEXIO_I2C_IP_VENDOR_ID_C != FLEXIO_I2C_IP_VENDOR_ID)
    #error "Flexio_I2c_Ip.c and Flexio_I2c_Ip.h have different vendor ids"
#endif
#if (( FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip.h are different"
#endif
#if (( FLEXIO_I2C_IP_SW_MAJOR_VERSION_C != FLEXIO_I2C_IP_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_MINOR_VERSION_C != FLEXIO_I2C_IP_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_PATCH_VERSION_C != FLEXIO_I2C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip.h are different"
#endif

/* Checks against Flexio_I2c_Ip_Features.h */
#if (FLEXIO_I2C_IP_VENDOR_ID_C != FLEXIO_I2C_IP_FEATURES_VENDOR_ID)
    #error "Flexio_I2c_Ip.c and Flexio_I2c_Ip_Features.h have different vendor ids"
#endif
#if (( FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_I2C_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_I2C_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_I2C_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip_Features.h are different"
#endif
#if (( FLEXIO_I2C_IP_SW_MAJOR_VERSION_C != FLEXIO_I2C_IP_FEATURES_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_MINOR_VERSION_C != FLEXIO_I2C_IP_FEATURES_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_PATCH_VERSION_C != FLEXIO_I2C_IP_FEATURES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip_Features.h are different"
#endif

/* Checks against Flexio_I2c_Ip_HwAccess.h */
#if (FLEXIO_I2C_IP_VENDOR_ID_C != FLEXIO_I2C_IP_HWACCESS_VENDOR_ID)
    #error "Flexio_I2c_Ip.c and Flexio_I2c_Ip_HwAccess.h have different vendor ids"
#endif
#if (( FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip_HwAccess.h are different"
#endif
#if (( FLEXIO_I2C_IP_SW_MAJOR_VERSION_C != FLEXIO_I2C_IP_HWACCESS_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_MINOR_VERSION_C != FLEXIO_I2C_IP_HWACCESS_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_PATCH_VERSION_C != FLEXIO_I2C_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip_HwAccess.h are different"
#endif

/* Checks against Flexio_I2c_Ip_Types.h */
#if (FLEXIO_I2C_IP_VENDOR_ID_C != FLEXIO_I2C_IP_TYPES_VENDOR_ID)
    #error "Flexio_I2c_Ip.c and Flexio_I2c_Ip_Types.h have different vendor ids"
#endif
#if (( FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip_Types.h are different"
#endif
#if (( FLEXIO_I2C_IP_SW_MAJOR_VERSION_C != FLEXIO_I2C_IP_TYPES_SW_MAJOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_MINOR_VERSION_C != FLEXIO_I2C_IP_TYPES_SW_MINOR_VERSION) || \
     ( FLEXIO_I2C_IP_SW_PATCH_VERSION_C != FLEXIO_I2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip.c and Flexio_I2c_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Osif.h header file are of the same Autosar version */
    #if ( (FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
          (FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Flexio_I2c_Ip.c and Osif.h are different"
    #endif
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ( (FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
          (FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Flexio_I2c_Ip.c and Devassert.h are different"
    #endif
    #if (FLEXIO_I2C_IP_ENABLE == STD_ON)
        #if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
            /* Check if current file and Dma_Ip.h header file are of the same Autosar version */
            #if ( (FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
                  (FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION)    \
                 )
                #error "AutoSar Version Numbers of Flexio_I2c_Ip.c and Dma_Ip.h are different"
            #endif
        #endif /* (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE) */
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
/*! @cond DRIVER_INTERNAL_USE_ONLY */

/* Constraints used for baud rate computation */
#define DIVIDER_MIN_VALUE  1U
#define DIVIDER_MAX_VALUE  0xFFU

/* Default value of timeout */
#ifndef I2C_TIMEOUT
#define I2C_TIMEOUT  0xFFFFU
#endif

/* Shifters/Timers used for I2C simulation The parameter x represents the ResourceIndex value for the current Driver Instance */
#define TX_SHIFTER(x)     ((uint8)(x))
#define RX_SHIFTER(x)     ((uint8)((x) + 1U))
#define SCL_TIMER(x)      ((uint8)(x))
#define CONTROL_TIMER(x)  ((uint8)((x) + 1U))

#define FLEXIO_I2C_IP_LEAVE_SDA_FREE_U32 (uint32)0x000000FFU
#define FLEXIO_I2C_IP_STOP_BYTE_VALUE_U32 (uint32)0x00000000U
#define FLEXIO_I2C_IP_MAX_CHANNEL_COUNT  (4U)

#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)

#define I2C_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "I2c_MemMap.h"

static uint32 Flexio_I2c_u32TimerComp;
static uint32 Flexio_I2c_au32ConfigValue[2U];

#define I2C_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "I2c_MemMap.h"

#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE*/

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
/* DMA definitions */
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)

#define FLEXIO_I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER  (10U)

#else

#define FLEXIO_I2C_DMA_TIMER_CONFIG     (0U) /*Index for Flexio config array*/
#define FLEXIO_I2C_DMA_TIMER_COMPARE    (1U) /*Index for Flexio config array*/
#define FLEXIO_I2C_INSTANCE_0           (0U) /*Instance hardware*/
#define FLEXIO_I2C_INSTANCE_0_CHANNEL_0 (0U) /*Index of Flexio_0_1*/
#define FLEXIO_I2C_INSTANCE_0_CHANNEL_2 (2U) /*Index of Flexio_4_5*/

#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
#endif /*STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE*/

#if (FLEXIO_I2C_IP_NUMBER_OF_MASTER_CHANNEL != 0U)
static Flexio_I2c_Ip_MasterStateType Flexio_I2c_Ip_MasterState[FLEXIO_I2C_IP_NUMBER_OF_MASTER_CHANNEL];
#endif
/* Structures for configuration the master DMA channel */
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)

static uint32 FlexIO_I2c_DiscardData;
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)

static Dma_Ip_LogicChannelTransferListType Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[FLEXIO_I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER];
static Dma_Ip_LogicChannelTransferListType Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[FLEXIO_I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER];
#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
#endif /* FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/* Pointer to runtime state structure.*/
static Flexio_I2c_Ip_MasterStateType* Flexio_I2c_Ip_pxMasterState[FLEXIO_I2C_IP_INSTANCE_COUNT][FLEXIO_I2C_IP_MAX_CHANNEL_COUNT];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

static FLEXIO_Type * const Flexio_I2c_Ip_pBaseAddr[FLEXIO_I2C_IP_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_8
#include "I2c_MemMap.h"

/* I2c channel init status*/
static uint8 Flexio_I2c_Ip_au8ChannelStatus[FEATURE_FLEXIO_MAX_CHANNEL_COUNT];

#define I2C_STOP_SEC_VAR_CLEARED_8
#include "I2c_MemMap.h"
/*******************************************************************************
 * Private Functions
 ******************************************************************************/
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)

static inline void Flexio_I2c_SetupTcdTimerDma(Flexio_I2c_Ip_MasterStateType * Master);
static inline void Flexio_I2c_Ip_HandleEventTimerDMA(Flexio_I2c_Ip_MasterStateType *Master);
static void I2c_Ip_InitDmaParamElementSg(Dma_Ip_LogicChannelScatterGatherListType * Flexio_I2c_ListTransfer);
static void Flexio_I2c_Ip_MasterStartDmaOptimizeTransfer(FLEXIO_Type *BaseAddr,
                                                         Flexio_I2c_Ip_MasterStateType *Master,
                                                         uint32 Size);

#ifdef FLEXIO_0_CH_0_USED
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationTimer2(void);
#endif
#ifdef FLEXIO_0_CH_4_USED
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationTimer6(void);
#endif

static void Flexio_I2c_Ip_EnableInterruptDmaTransfer(const Flexio_I2c_Ip_MasterStateType * Master);

#else
static void Flexio_I2c_Ip_MasterCmdDmaTcdInit(void);
static void Flexio_I2c_Ip_MasterStartDmaNormalTransfer(const FLEXIO_Type *BaseAddr,
                                                       const Flexio_I2c_Ip_MasterStateType *Master,
                                                       uint32 Size);

#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
#endif /* FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */

static Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterWaitTransferEnd(Flexio_I2c_Ip_MasterStateType *Master,
                                                                    uint32 Timeout);
static void Flexio_I2c_Ip_MasterStopTransfer(Flexio_I2c_Ip_MasterStateType *Master);
static void Flexio_I2c_Ip_DisableShifterTimer(FLEXIO_Type *BaseAddr, uint8 Resource);
static void Flexio_I2c_Ip_DisableDMARequest(FLEXIO_Type *BaseAddr, uint8 Resource);
static void Flexio_I2c_Ip_ClearFlagsShifterTimer(FLEXIO_Type *BaseAddr, uint8 Resource);
static void Flexio_I2c_Ip_MasterEnableInterrupt(const Flexio_I2c_Ip_MasterStateType *Master);

/*******************************************************************************
 * Global Functions
 ******************************************************************************/
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
void Flexio_I2c_Ip_MasterEndDmaTransfer(uint8 Instance,
                                        uint8 Channel,
                                        boolean Receive);
#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void Flexio_I2c_Ip_MasterDmaTransferErrorHandler(uint8 Instance,
                                                 uint8 Channel);
#endif /* FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT */
#endif /* FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterComputeBaudRateDivider
 * Description   : Computes the baud rate divider for a target baud rate
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterComputeBaudRateDivider(uint32 BaudRate,
                                                       uint16 *Divider,
                                                       uint32 InputClock)
{
    uint32 TmpDiv;

    /* Compute divider: ((input_clock / baud_rate) / 2) - 1 - 1. The extra -1 is from the
       timer reset setting used for clock stretching. Round to nearest integer */
    TmpDiv = (((uint32)InputClock + (uint32)BaudRate) / (2U * (uint32)BaudRate)) - 2U;
    /* Enforce upper/lower limits */
    if (TmpDiv < DIVIDER_MIN_VALUE)
    {
        TmpDiv = DIVIDER_MIN_VALUE;
    }
    if (TmpDiv > DIVIDER_MAX_VALUE)
    {
        TmpDiv = DIVIDER_MAX_VALUE;
    }

    *Divider = (uint16)TmpDiv;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_DisableShifterTimer
 * Description   : This function to use disable Shifter and Timer
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_DisableShifterTimer(FLEXIO_Type *BaseAddr, uint8 Resource)
{
    /* Ensure all shifters/timers are disabled */
    Flexio_I2c_Ip_SetShifterMode(BaseAddr, Resource, FLEXIO_SHIFTER_MODE_DISABLED);
    Flexio_I2c_Ip_SetTimerMode(BaseAddr, Resource, FLEXIO_TIMER_MODE_DISABLED);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_DisableDMARequest
 * Description   : This function to use disable all interrupts and DMA requests
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_DisableDMARequest(FLEXIO_Type *BaseAddr, uint8 Resource)
{
    /* Ensure all interrupts and DMA requests are disabled */
    Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
    Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)(1U << Resource), FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_ClearFlagsShifterTimer
 * Description   : This function to use disable all interrupts and DMA requests
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_ClearFlagsShifterTimer(FLEXIO_Type *BaseAddr, uint8 Resource)
{
    /* Clear any leftover flags */
    Flexio_Mcl_Ip_ClearShifterStatus(BaseAddr, Resource);
    Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, Resource);
    Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, Resource);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_ResourcesInit
 * Description   : Initializes the resources for the current driver
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_ResourcesInit(uint8 Instance,
                                        const Flexio_I2c_Ip_CommonStateType *Driver)
{
    uint8 Resource;
    uint8 ResourceCount;
    uint8 ResourceIndex;
    FLEXIO_Type *BaseAddr;

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Instance];
    ResourceCount = Driver->ResourceCount;
    ResourceIndex = Driver->ResourceIndex;
    for (Resource = ResourceIndex; Resource < (uint8)(ResourceIndex + ResourceCount); Resource++)
    {
        /* Disable Shifter and Timer */
        Flexio_I2c_Ip_DisableShifterTimer(BaseAddr, Resource);

        /* Disable all interrupts and DMA requests */
        Flexio_I2c_Ip_DisableDMARequest(BaseAddr, Resource);

        /* Clear any leftover flags */
        Flexio_I2c_Ip_ClearFlagsShifterTimer(BaseAddr, Resource);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_InitDriver
 * Description   : Initializes an Instance of FlexIO driver
 *
 *END**************************************************************************/
static inline void Flexio_I2c_Ip_InitDriver(uint8 Instance,
                                            const Flexio_I2c_Ip_CommonStateType *Driver)
{
    uint8 FlexioChannelIndex;
    FlexioChannelIndex = (uint8)((Driver->ResourceIndex)/2U);

    Flexio_I2c_Ip_au8ChannelStatus[FlexioChannelIndex] = 1U;

    /* initialize the allocated resources */
    Flexio_I2c_Ip_ResourcesInit(Instance, Driver);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_DeinitDriver
 * Description   : De-initializes an Instance of FlexIO driver
 *
 *END**************************************************************************/
static Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_DeinitDriver(const Flexio_I2c_Ip_CommonStateType *Driver)
{
    uint8 Instance;
    uint8 FlexioChannelIndex;

    Instance = Driver->Instance;
    FlexioChannelIndex = (uint8)((Driver->ResourceIndex)/2U);

    Flexio_I2c_Ip_au8ChannelStatus[FlexioChannelIndex] = 0U;
    (void)Instance;

    return FLEXIO_I2C_IP_SUCCESS_STATUS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterConfigure
 * Description   : configures the FLEXIO module as I2C master
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterConfigure(const Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    uint8 TimerScl;
    uint8 TimerControl;

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    Flexio_I2c_Ip_ShifterControl TempShifterControl;
    Flexio_I2c_Ip_TimerConfig TempTimerConfig;
    Flexio_I2c_Ip_TimerControl TempTimerControl;
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    TimerScl = Master->SclAddChannel;
    TimerControl = Master->SdaAddChannel;
#else
    TimerScl = SCL_TIMER(ResourceIndex);
    TimerControl = CONTROL_TIMER(ResourceIndex);
#endif
    /* Compute divider.*/
    /* Configure tx shifter */
    Flexio_I2c_Ip_SetShifterConfig(BaseAddr,
                                TX_SHIFTER(ResourceIndex),
                                FLEXIO_SHIFTER_START_BIT_0,
                                FLEXIO_SHIFTER_STOP_BIT_1,
                                FLEXIO_SHIFTER_SOURCE_PIN);

    TempShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
    TempShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempShifterControl.Pin = Master->SdaPin;
    TempShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_POSEDGE;
    TempShifterControl.Timer = TimerControl;

    /* Shifter disabled and pin enabled causes the pin to be held low.
       So disable pin too, will be enabled at transfer time.  */
    Flexio_I2c_Ip_SetShifterControl(BaseAddr,
                                 TX_SHIFTER(ResourceIndex),
                                 &TempShifterControl);

    /* Configure rx shifter */
    Flexio_I2c_Ip_SetShifterConfig(BaseAddr,
                                RX_SHIFTER(ResourceIndex),
                                FLEXIO_SHIFTER_START_BIT_DISABLED,
                                FLEXIO_SHIFTER_STOP_BIT_0,
                                FLEXIO_SHIFTER_SOURCE_PIN);

    TempShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
    TempShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    TempShifterControl.Pin = Master->SdaPin;
    TempShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_NEGEDGE;
    TempShifterControl.Timer = TimerControl;

    Flexio_I2c_Ip_SetShifterControl(BaseAddr,
                                 RX_SHIFTER(ResourceIndex),
                                 &TempShifterControl);

    /* Configure SCL timer */
    Flexio_I2c_Ip_SetTimerCompare(BaseAddr, TimerScl, Master->CmpValue);

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_ENABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_TIM_DIS;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_NEVER;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_PIN_OUT;
    TempTimerConfig.Decrement = (uint32)Master->PrescaleValue;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ZERO;

    Flexio_I2c_Ip_SetTimerConfig(BaseAddr,
                                 TimerScl,
                                 &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(TX_SHIFTER(ResourceIndex) << 2U) + 1U); /* trigger on tx shifter status flag */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_LOW;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = Master->SclPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_OPEN_DRAIN;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2c_Ip_SetTimerControl(BaseAddr,
                               TimerScl,
                               &TempTimerControl);

    /* Configure control timer for shifters */
    Flexio_I2c_Ip_SetTimerCompare(BaseAddr, TimerControl, 0x000FU);

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_ENABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_TIM_CMP;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TIM_ENABLE;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TIM_DISABLE;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = (uint32)FLEXIO_TIMER_DECREMENT_PIN_SHIFT_PIN;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;

    Flexio_I2c_Ip_SetTimerConfig(BaseAddr,
                              TimerControl,
                              &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(TX_SHIFTER(ResourceIndex) << 2U) + 1U); /* trigger on tx shifter status flag */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_LOW;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = Master->SclPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2c_Ip_SetTimerControl(BaseAddr,
                               TimerControl,
                               &TempTimerControl);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterSetBytesNo
 * Description   : configures the number of SCL clocks needed for the entire transmission
 *
 *END**************************************************************************/

static void Flexio_I2c_Ip_MasterSetBytesNo(FLEXIO_Type *BaseAddr,
                                           Flexio_I2c_Ip_MasterStateType *Master)
{
    uint16 TimerCmp;
    uint32 EdgeNo;        /* total number of clock edges */
    uint32 Counter;       /* edge Counter per timer reload */
    uint32 Reloads;       /* number of timer Reloads */
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    uint8 TimerScl;

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    TimerScl = Master->SclAddChannel;
    (void)ResourceIndex;
#else
    TimerScl = SCL_TIMER(ResourceIndex);
#endif
    /* Compute number of SCL edges, including address */
    EdgeNo = (uint32)(Master->TxRemainingBytes * 18U) + 2U;
    Reloads = (uint32)((EdgeNo + 255U) / 256U);
    Counter = (uint32)((uint32)(EdgeNo + (Reloads - 1U)) / Reloads); /* round up */

    /* Set number of ticks in high part of timer compare register */
    TimerCmp = Flexio_I2c_Ip_GetTimerCompare(BaseAddr, TimerScl);
    TimerCmp = (uint16)((TimerCmp & 0x00FFU) | (uint16)(((Counter - 1U) & 0xFFU) << 8U));
    Flexio_I2c_Ip_SetTimerCompare(BaseAddr, TimerScl, TimerCmp);

    /* Store reload information */
    Master->EventCount =(uint16) Reloads;
    Master->LastReload = (uint8)(EdgeNo - ((Reloads - 1U) * Counter) - 1U);
    /* Handle no reload case */
    if (1U == Reloads)
    {
        Flexio_I2c_Ip_SetTimerDisable(BaseAddr, TimerScl, FLEXIO_TIMER_DISABLE_TIM_CMP);
    }
    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterSendAddress
 * Description   : send address byte
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterSendAddress(FLEXIO_Type *BaseAddr,
                                            const Flexio_I2c_Ip_MasterStateType *Master)
{
    uint8 AddrByte;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    /* Address byte: slave 7-bit address + D = 0(transmit) or 1 (Receive) */
    AddrByte = (uint8)((uint8)(Master->SlaveAddress << 1U) + (uint8)(Master->Receive ? 1U : 0U));
    Flexio_I2c_Ip_WriteShifterBuffer(BaseAddr, TX_SHIFTER(ResourceIndex), (uint32)AddrByte << 24U, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_TimerEventHandler
 * Description   : handler for timer event
 *
 *END**************************************************************************/
static inline void Flexio_I2c_Ip_TimerEventHandler(Flexio_I2c_Ip_MasterStateType *Master,
                                                   boolean TimerEventClear)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource instance (shifter and timer) */
    uint16 TimerCmp;

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (TimerEventClear)
    {
        /* Clear timer status */
        Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, SCL_TIMER(ResourceIndex));
    }
    if (2U == Master->EventCount)
    {
         /* Adjust number of ticks in high part of timer compare register  for the last reload */
         TimerCmp = Flexio_I2c_Ip_GetTimerCompare(BaseAddr, SCL_TIMER(ResourceIndex));
         TimerCmp = (uint16)((uint16)((uint32)TimerCmp & 0x00FFU) | (uint16)(((uint32)(Master->LastReload) & 0xFFU) << 8U));
         Flexio_I2c_Ip_SetTimerCompare(BaseAddr, SCL_TIMER(ResourceIndex), TimerCmp);
    }
    if (1U == Master->EventCount)
    {
        /* Timer will disable on the next countdown complete */
        Flexio_I2c_Ip_SetTimerDisable(BaseAddr, SCL_TIMER(ResourceIndex), FLEXIO_TIMER_DISABLE_TIM_CMP);
    }

    if (0U == Master->EventCount)
    {
        Flexio_I2c_Ip_SetTimerDisable(BaseAddr, SCL_TIMER(ResourceIndex), FLEXIO_TIMER_DISABLE_NEVER);

        /* Record success if there was no error */
        if (FLEXIO_I2C_IP_BUSY_STATUS == Master->Status)
        {
            Master->Status = FLEXIO_I2C_IP_SUCCESS_STATUS;
        }
        /* End transfer. In case of race condition between Tx_shifter and timer_end events,
           it is possible for the clock to be restarted. So we use forced stop to avoid this. */
        Flexio_I2c_Ip_MasterStopTransfer(Master);
        /* Call callback to announce the event to the user */
        if (Master->Callback != NULL_PTR)
        {
            Master->Callback(FLEXIO_I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
        }
    }
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_SetupTcdTimerDma
 * Description   : Configure TCD and Enable DMA for Timer
 *
 *END**************************************************************************/
static inline void Flexio_I2c_SetupTcdTimerDma(Flexio_I2c_Ip_MasterStateType * Master)
{
    FLEXIO_Type *BaseAddress;

    Dma_Ip_LogicChannelScatterGatherListType FlexIO_I2c_TimerTransferList[10U];

    BaseAddress = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Calculate timer compare value to update for last time*/
    Flexio_I2c_u32TimerComp = Flexio_I2c_Ip_GetTimerCompare(BaseAddress, Master->SclAddChannel);
    Flexio_I2c_u32TimerComp = (uint32)((uint16)((uint32)Flexio_I2c_u32TimerComp & 0x00FFU) | (uint16)(((uint32)(Master->LastReload) & 0xFFU) << 8U));

    /* Configure the Timer Config register*/
    Flexio_I2c_au32ConfigValue[FLEXIO_I2C_DMA_TIMER_CONFIG] = (BaseAddress->TIMCFG[Master->SclAddChannel] & (~FLEXIO_TIMCFG_TIMDIS_MASK)) | FLEXIO_TIMCFG_TIMDIS(FLEXIO_TIMER_DISABLE_TIM_CMP);
    /* Updated value for Timer Compare register*/
    Flexio_I2c_au32ConfigValue[FLEXIO_I2C_DMA_TIMER_COMPARE] = Flexio_I2c_u32TimerComp & 0x0000FFFFU;

    FlexIO_I2c_TimerTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    FlexIO_I2c_TimerTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    FlexIO_I2c_TimerTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    FlexIO_I2c_TimerTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    FlexIO_I2c_TimerTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    FlexIO_I2c_TimerTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    FlexIO_I2c_TimerTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    FlexIO_I2c_TimerTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    FlexIO_I2c_TimerTransferList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    FlexIO_I2c_TimerTransferList[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    /* TCD0: Clear TSF flag to create new DMA Hw request for the next event*/
    FlexIO_I2c_TimerTransferList[0u].Value = (uint32)&(BaseAddress->TIMCMP[Master->SclAddChannel]);
    FlexIO_I2c_TimerTransferList[1u].Value = 0U;
    FlexIO_I2c_TimerTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
    FlexIO_I2c_TimerTransferList[3u].Value = (uint32)&(FlexIO_I2c_DiscardData);
    FlexIO_I2c_TimerTransferList[4u].Value = 0U;
    FlexIO_I2c_TimerTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
    FlexIO_I2c_TimerTransferList[6u].Value = 4U;
    FlexIO_I2c_TimerTransferList[7u].Value = Master->EventCount - 3U;
    FlexIO_I2c_TimerTransferList[9u].Value = 0u;
    FlexIO_I2c_TimerTransferList[8u].Value = 0u;
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->TimerChannelDMA, 0U, FlexIO_I2c_TimerTransferList, 10U);

    /* TCD1: Update TIMCMP for the last time*/
    FlexIO_I2c_TimerTransferList[0u].Value = (uint32)&(Flexio_I2c_u32TimerComp);
    FlexIO_I2c_TimerTransferList[1u].Value = 0U;
    FlexIO_I2c_TimerTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
    FlexIO_I2c_TimerTransferList[3u].Value = (uint32)&(BaseAddress->TIMCMP[Master->SclAddChannel]);
    FlexIO_I2c_TimerTransferList[4u].Value = 0U;
    FlexIO_I2c_TimerTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
    FlexIO_I2c_TimerTransferList[6u].Value = 2U;
    FlexIO_I2c_TimerTransferList[7u].Value = 1U;
    FlexIO_I2c_TimerTransferList[9u].Value = 0u;
    FlexIO_I2c_TimerTransferList[8u].Value = 0u;
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->TimerChannelDMA, 1U, FlexIO_I2c_TimerTransferList, 10U);

    /* TCD2: Disable timer after the last bytes were transferred and clear TSF flag*/
    FlexIO_I2c_TimerTransferList[0u].Value = (uint32)&(Flexio_I2c_au32ConfigValue[0U]);
    FlexIO_I2c_TimerTransferList[1u].Value = 4U;
    FlexIO_I2c_TimerTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
    FlexIO_I2c_TimerTransferList[3u].Value = (uint32)&(BaseAddress->TIMCFG[Master->SclAddChannel]);
    FlexIO_I2c_TimerTransferList[4u].Value = (uint32)&(BaseAddress->TIMCMP[Master->SclAddChannel]) - (uint32)&(BaseAddress->TIMCFG[Master->SclAddChannel]);
    FlexIO_I2c_TimerTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
    FlexIO_I2c_TimerTransferList[6u].Value = 8U;
    FlexIO_I2c_TimerTransferList[7u].Value = 1U;
    FlexIO_I2c_TimerTransferList[9u].Value = 0U;
    FlexIO_I2c_TimerTransferList[8u].Value = 0U;
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->TimerChannelDMA, 2U, FlexIO_I2c_TimerTransferList, 10U);

    /* TCD3: Clear TSF flag and Stop transfer*/
    FlexIO_I2c_TimerTransferList[0u].Value = (uint32)&(BaseAddress->TIMCMP[Master->SclAddChannel]);
    FlexIO_I2c_TimerTransferList[1u].Value = 0U;
    FlexIO_I2c_TimerTransferList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
    FlexIO_I2c_TimerTransferList[3u].Value = (uint32)&(FlexIO_I2c_DiscardData);
    FlexIO_I2c_TimerTransferList[4u].Value = 0U;
    FlexIO_I2c_TimerTransferList[5u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
    FlexIO_I2c_TimerTransferList[6u].Value = 4U;
    FlexIO_I2c_TimerTransferList[7u].Value = 1U;
    FlexIO_I2c_TimerTransferList[9u].Value = 1u;
    FlexIO_I2c_TimerTransferList[8u].Value = 1u;
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->TimerChannelDMA, 3U, FlexIO_I2c_TimerTransferList, 10U);

    if (3U == Master->EventCount)
    {
        Dma_Ip_SetLogicChannelScatterGatherConfig(Master->TimerChannelDMA, 1U);
    }
    else if (2U == Master->EventCount)
    {
        Dma_Ip_SetLogicChannelScatterGatherConfig(Master->TimerChannelDMA, 2U);
    }
    else if (1U == Master->EventCount)
    {
        Dma_Ip_SetLogicChannelScatterGatherConfig(Master->TimerChannelDMA, 3U);
    }
    else
    {
        Dma_Ip_SetLogicChannelScatterGatherConfig(Master->TimerChannelDMA, 0U);
    }
    (void)Dma_Ip_SetLogicChannelCommand(Master->TimerChannelDMA, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_HandleEventTimerDMA
 * Description   : Enable dma request for i2c transfer
 *
 *END**************************************************************************/
static inline void Flexio_I2c_Ip_HandleEventTimerDMA(Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddress;
    uint8 ResourceIndex;

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    BaseAddress = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    Flexio_I2c_Ip_SetTimerDisable(BaseAddress, Master->SclAddChannel, FLEXIO_TIMER_DISABLE_NEVER);

    if (Master->Receive)
    {
        (void)Dma_Ip_SetLogicChannelCommand(Master->DmaRxChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddress, (uint8)(1U << RX_SHIFTER(ResourceIndex)), FALSE);
    }
    else
    {
        (void)Dma_Ip_SetLogicChannelCommand(Master->DmaTxChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddress, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
    }

    (void)Dma_Ip_SetLogicChannelCommand(Master->TimerChannelDMA, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
    Flexio_Mcl_Ip_SetTimerDMARequest(BaseAddress, (uint8)(1U << Master->SclAddChannel), FALSE);

    /* Record success if there was no error */
    if (FLEXIO_I2C_IP_BUSY_STATUS == Master->Status)
    {
        Master->Status = FLEXIO_I2C_IP_SUCCESS_STATUS;
    }
    /* End transfer. In case of race condition between Tx_shifter and timer_end events,
        it is possible for the clock to be restarted. So we use forced stop to avoid this. */
    Flexio_I2c_Ip_MasterStopTransfer(Master);
    /* Call callback to announce the event to the user */
    if (Master->Callback != NULL_PTR)
    {
        Master->Callback(FLEXIO_I2C_MASTER_EVENT_END_TRANSFER, Master->CallbackParam);
    }
}

#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_EnableInterruptDmaTransfer
 * Description   : This function will use to enable all interrupt on Flexio before start transfer data
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_EnableInterruptDmaTransfer(const Flexio_I2c_Ip_MasterStateType * Master)
{
    uint8 ResourceIndex;    /* Index of first used internal resource instance (shifter and timer) */
    FLEXIO_Type *BaseAddr;
    uint8 TimerScl;

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    TimerScl = Master->SclAddChannel;
#else
    TimerScl = SCL_TIMER(ResourceIndex);
#endif

#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_Mcl_Ip_SetTimerDMARequest(BaseAddr, 1U << TimerScl, TRUE);
#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
    /* Enable FlexIO DMA requests for both shifters */
    Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))), TRUE);
    /* Enable error interrupt for Rx shifter - for NACK detection */
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << RX_SHIFTER(ResourceIndex)), TRUE);
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    /* Enable interrupt for SCL timer - for end of transfer detection */
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << TimerScl), TRUE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_DmaTransferEnable
 * Description   : Enable dma request for i2c transfer
 *
 *END**************************************************************************/
static inline void Flexio_I2c_Ip_DmaTransferEnable(Flexio_I2c_Ip_MasterStateType *Master)
{
    uint8 ResourceIndex;    /* Index of first used internal resource instance (shifter and timer) */
    FLEXIO_Type *BaseAddr;
    boolean ShifterStatus;
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(I2C_TIMEOUT, FLEXIO_I2C_IP_TIMEOUT_TYPE);
    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (TRUE == Master->Receive)
    {
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), TRUE);
    }
    CurrentTicks = OsIf_GetCounter(FLEXIO_I2C_IP_TIMEOUT_TYPE);
    do
    {
        if (TRUE == Master->Receive)
        {
            ShifterStatus = Flexio_Mcl_Ip_GetShifterStatus(BaseAddr, RX_SHIFTER(ResourceIndex));
        }
        else
        {
            ShifterStatus = Flexio_Mcl_Ip_GetShifterStatus(BaseAddr, TX_SHIFTER(ResourceIndex));
        }
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FLEXIO_I2C_IP_TIMEOUT_TYPE);
    }
    while ((ElapsedTicks < TimeoutTicks) &&(FALSE == ShifterStatus));

    if (ElapsedTicks >= TimeoutTicks)
    {
        Master->Status = FLEXIO_I2C_IP_TIMEOUT_STATUS;
    }
    else
    {

        if (TRUE == Master->Receive)
        {
            (void)Flexio_I2c_Ip_ReadShifterBuffer(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
            Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_0);
        }

        /* This function will use to enable all interrupt on Flexio before start transfer data */
        Flexio_I2c_Ip_EnableInterruptDmaTransfer(Master);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterStartDmaTransfer
 * Description   :
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterStartDmaTransfer(FLEXIO_Type *BaseAddr,
                                                 Flexio_I2c_Ip_MasterStateType *Master,
                                                 uint32 Size)
{
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
        Flexio_I2c_Ip_MasterStartDmaOptimizeTransfer(BaseAddr,Master,Size);
#else
        Flexio_I2c_Ip_MasterStartDmaNormalTransfer(BaseAddr,Master,Size);
#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/

        (void)Dma_Ip_SetLogicChannelCommand(Master->DmaTxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        (void)Dma_Ip_SetLogicChannelCommand(Master->DmaRxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        OsIf_SuspendAllInterrupts();
        /* Send address to start transfer */
        Flexio_I2c_Ip_MasterSendAddress(BaseAddr, Master);
        Flexio_I2c_Ip_DmaTransferEnable(Master);
        OsIf_ResumeAllInterrupts();
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE) /* Transmission with optimize mode*/
static void Flexio_I2c_Ip_MasterStartDmaOptimizeTransfer(FLEXIO_Type *BaseAddr,
                                                         Flexio_I2c_Ip_MasterStateType *Master,
                                                         uint32 Size)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    static const uint32 I2c_FlexIO_LeaveSdaFree = FLEXIO_I2C_IP_LEAVE_SDA_FREE_U32;
    static const uint32 I2c_FlexIO_SendStop = FLEXIO_I2C_IP_STOP_BYTE_VALUE_U32;
    static const uint32 ShiftConfigNack[2] = {FLEXIO_SHIFTCFG_SSTOP(3U)|FLEXIO_SHIFTCFG_SSTART(2U), FLEXIO_SHIFTCFG_SSTOP(3U)};
    Dma_Ip_LogicChannelScatterGatherListType Flexio_I2c_SgTransmitLocalList[11U];
    Dma_Ip_LogicChannelTransferListType Flexio_I2c_ReceiveLocalList[11U];

    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Init parammeters for Tx channel*/
    I2c_Ip_InitDmaParamElementSg(Flexio_I2c_SgTransmitLocalList);

    if (FALSE == Master->Receive) /*Send data*/
    {
        Flexio_I2c_SgTransmitLocalList[0u].Value = (uint32)(&(Master->TxData[0U]));
        Flexio_I2c_SgTransmitLocalList[1u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_SgTransmitLocalList[3u].Value = (uint32)(&(BaseAddr->SHIFTBUFBBS[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_SgTransmitLocalList[4u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_SgTransmitLocalList[6u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[7u].Value = Size + 1U;
        Flexio_I2c_SgTransmitLocalList[8u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[9u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[10u].Value = 0U;
    }
    else /* Send NACK*/
    {
        Flexio_I2c_SgTransmitLocalList[0u].Value = (uint32)(&(ShiftConfigNack[0]));
        Flexio_I2c_SgTransmitLocalList[1u].Value = 4U;
        Flexio_I2c_SgTransmitLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
        Flexio_I2c_SgTransmitLocalList[3u].Value = (uint32)(&(BaseAddr->SHIFTCFG[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_SgTransmitLocalList[4u].Value = 4U;
        Flexio_I2c_SgTransmitLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
        Flexio_I2c_SgTransmitLocalList[6u].Value = 8U;
        Flexio_I2c_SgTransmitLocalList[7u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[8u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[9u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[10u].Value = 1U;
    }
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->DmaTxChannel, 1U, Flexio_I2c_SgTransmitLocalList, 11U);

    /* Send STOP Condition*/
    if (FALSE == Master->Receive)
    {
        Flexio_I2c_SgTransmitLocalList[0u].Value = (Master->SendStop == TRUE)?((uint32)(&I2c_FlexIO_SendStop)):((uint32)(&I2c_FlexIO_LeaveSdaFree));
        Flexio_I2c_SgTransmitLocalList[1u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
        Flexio_I2c_SgTransmitLocalList[3u].Value = (uint32)(&(BaseAddr->SHIFTBUF[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_SgTransmitLocalList[4u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
        Flexio_I2c_SgTransmitLocalList[6u].Value = 4U;
        Flexio_I2c_SgTransmitLocalList[7u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[8u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[9u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[10u].Value = 1U;
    }
    else
    {
        Flexio_I2c_SgTransmitLocalList[0u].Value = (Master->SendStop == TRUE)?((uint32)(&I2c_FlexIO_SendStop)):((uint32)(&I2c_FlexIO_LeaveSdaFree));
        Flexio_I2c_SgTransmitLocalList[1u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
        Flexio_I2c_SgTransmitLocalList[3u].Value = (uint32)(&(BaseAddr->SHIFTBUF[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_SgTransmitLocalList[4u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;
        Flexio_I2c_SgTransmitLocalList[6u].Value = 4U;
        Flexio_I2c_SgTransmitLocalList[7u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[8u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[9u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[10u].Value = 1U;
    }
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->DmaTxChannel, 2U, Flexio_I2c_SgTransmitLocalList, 11U);
    
    /*SDA Free*/
    if (TRUE == Master->Receive)
    {
        /* Set source address and major loop transfer size */
        Flexio_I2c_SgTransmitLocalList[0u].Value = (uint32)(&(I2c_FlexIO_LeaveSdaFree));
        Flexio_I2c_SgTransmitLocalList[1u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_SgTransmitLocalList[3u].Value = (uint32)(&(BaseAddr->SHIFTBUFBBS[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_SgTransmitLocalList[4u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_SgTransmitLocalList[6u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[7u].Value = Size + 1U;
        Flexio_I2c_SgTransmitLocalList[8u].Value = 1U;
        Flexio_I2c_SgTransmitLocalList[9u].Value = 0U;
        Flexio_I2c_SgTransmitLocalList[10u].Value = 0U;
    }
    (void)Dma_Ip_SetLogicChannelScatterGatherList(Master->DmaTxChannel, 0U, Flexio_I2c_SgTransmitLocalList, 11U);

    /* Init parammeters for Rx channel*/
    I2c_Ip_InitDmaParamElementSg(Flexio_I2c_ReceiveLocalList);

    if (FALSE == Master->Receive) /*Receive dummy data*/
    {
        Flexio_I2c_ReceiveLocalList[0u].Value = (uint32) (&(BaseAddr->SHIFTBUFBIS[RX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_ReceiveLocalList[1u].Value = 0U;
        Flexio_I2c_ReceiveLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_ReceiveLocalList[3u].Value = (uint32)(&FlexIO_I2c_DiscardData);
        Flexio_I2c_ReceiveLocalList[4u].Value = 0U;
        Flexio_I2c_ReceiveLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_ReceiveLocalList[6u].Value = 1U;
        Flexio_I2c_ReceiveLocalList[7u].Value = Size + 1U;
        Flexio_I2c_ReceiveLocalList[8u].Value = 1U;
        Flexio_I2c_ReceiveLocalList[9u].Value = 0U;
        Flexio_I2c_ReceiveLocalList[10u].Value = 0U;
    }
    else /*Receive data*/
    {
        Flexio_I2c_ReceiveLocalList[0u].Value = (uint32) (&(BaseAddr->SHIFTBUFBIS[RX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_ReceiveLocalList[1u].Value = 0U;
        Flexio_I2c_ReceiveLocalList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_ReceiveLocalList[3u].Value = (uint32)(&(Master->RxData[0]));
        Flexio_I2c_ReceiveLocalList[4u].Value = 1U;
        Flexio_I2c_ReceiveLocalList[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
        Flexio_I2c_ReceiveLocalList[6u].Value = 1U;
        Flexio_I2c_ReceiveLocalList[7u].Value = Size;
        Flexio_I2c_ReceiveLocalList[8u].Value = 1U;
        Flexio_I2c_ReceiveLocalList[9u].Value = 0U;
        Flexio_I2c_ReceiveLocalList[10u].Value = 0U;
    }
    (void)Dma_Ip_SetLogicChannelTransferList(Master->DmaRxChannel, Flexio_I2c_ReceiveLocalList, 11U);

    if (FALSE == Master->Receive)
    {
        Dma_Ip_SetLogicChannelScatterGatherConfig(Master->DmaTxChannel, 1U);
    }
    else
    {
        Dma_Ip_SetLogicChannelScatterGatherConfig(Master->DmaTxChannel, 0U);
    }

    Flexio_I2c_SetupTcdTimerDma(Master);
}
#else /* Transmission with non-optimize mode*/
static void Flexio_I2c_Ip_MasterStartDmaNormalTransfer(const FLEXIO_Type *BaseAddr,
                                                       const Flexio_I2c_Ip_MasterStateType *Master,
                                                       uint32 Size)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    static const uint32 I2c_FlexIO_LeaveSdaFree = FLEXIO_I2C_IP_LEAVE_SDA_FREE_U32;

    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (FALSE == Master->Receive) /*Send data*/
    {
        /* Set source address and major loop transfer size */
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[0u].Value = (uint32)(&(Master->TxData[0U]));
        /* Source  configuration values */
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[1u].Value = 1U;
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[3u].Value = (uint32)(&(BaseAddr->SHIFTBUFBBS[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[7u].Value = Size + 1U;

        /* Set destination address and major loop transfer size */
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[0u].Value = (uint32) (&(BaseAddr->SHIFTBUFBIS[RX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[3u].Value = (uint32)(&FlexIO_I2c_DiscardData);
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[4u].Value = 0U;
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[7u].Value = Size;
    }
    else
    {
        /* Set source address and major loop transfer size */
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[0u].Value = (uint32)(&(I2c_FlexIO_LeaveSdaFree));
        /* Source  configuration values */
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[1u].Value = 0U;
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[3u].Value = (uint32)(&(BaseAddr->SHIFTBUFBBS[TX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[7u].Value = Size ;
        /* Set destination address and major loop transfer size */
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[0u].Value = (uint32) (&(BaseAddr->SHIFTBUFBIS[RX_SHIFTER(ResourceIndex)]));
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[3u].Value = (uint32)(&(Master->RxData[0]));
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[4u].Value = 1U;
        Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[7u].Value = Size - 1U;
    }

    (void)Dma_Ip_SetLogicChannelTransferList(Master->DmaRxChannel, Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive, FLEXIO_I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER);
    (void)Dma_Ip_SetLogicChannelTransferList(Master->DmaTxChannel, Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend, FLEXIO_I2C_DMA_CHANNEL_CONFIG_LIST_SIZE_MASTER);
}
#endif /* STD_ON==FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE */
#endif /* STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_ReadData
 * Description   : Handles data reception
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_ReadData(Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint8 Data;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Read data from rx shifter */
    Data = (uint8)Flexio_I2c_Ip_ReadShifterBuffer(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);

    if (FALSE == Master->AddrReceived)
    {
        /* This was the address byte */
        Master->AddrReceived = TRUE;
        if (TRUE == Master->Receive)
        {
            /* Send ACK from now on */
            Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_0);
        }
    }
    else
    {
        Master->RxRemainingBytes--;
        if (TRUE == Master->Receive)
        {
            /* Put data in user buffer */
            *(Master->RxData) = Data;
            Master->RxData++;
        }
    }
    if ((TRUE == Master->Receive) && (1U == Master->RxRemainingBytes))
    {
        /* Send NACK for last byte */
        Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
        /* Also instruct rx shifter to expect NACK */
        Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_WriteData
 * Description   : Handles data transmission
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_WriteData(Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint32 Data;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* If txRemainingBytes == 0 the transmission is over */
    if (Master->TxRemainingBytes != 0U)
    {
        Master->TxRemainingBytes--;

        if (0U == Master->TxRemainingBytes)
        {
            /* Done transmitting */
            if (TRUE == Master->SendStop)
            {
                /* Transmit stop condition */
                Data = 0x0U;
            }
            else
            {
                /* Do not transmit stop condition */
                Data = 0xFFU;
            }
        }
        else if (TRUE == Master->Receive)
        {
            /* Transmit 0xFF to leave the line free while receiving */
            Data = 0xFFU;
        }
        else
        {
            /* Read data from user buffer */
            Data =  *(Master->TxData);
            Master->TxData++;
        }

        /* Shift data before bit-swapping it to get the relevant bits in the lower part of the shifter */
        Data <<= 24U;
        Flexio_I2c_Ip_WriteShifterBuffer(BaseAddr, TX_SHIFTER(ResourceIndex), Data, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterEndTransfer
 * Description   : End the current transfer
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterEndTransfer(Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Restore Rx stop bit, in case it was changed by a receive */
    Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_0);
    /* Restore Tx stop bit, in case it was changed by a receive */
    Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
    /* Clear Rx status in case there is a character left in the buffer */
    Flexio_Mcl_Ip_ClearShifterStatus(BaseAddr, RX_SHIFTER(ResourceIndex));

    /* Disable transfer engine */
    switch (Master->DriverType)
    {
        case FLEXIO_I2C_IP_DRIVER_TYPE_INTERRUPTS:
            /* Disable interrupts for Rx and Tx shifters */
            Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr,
                                 (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                                 FALSE);
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr,
                                 (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                                 FALSE);
            /* Disable interrupt for SCL timer */
            Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << SCL_TIMER(ResourceIndex)), FALSE);
            break;
        case FLEXIO_I2C_IP_DRIVER_TYPE_POLLING:
            /* Nothing to do here */
            break;
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
        case FLEXIO_I2C_IP_DRIVER_TYPE_DMA:
            /* Disable error interrupt for Rx shifter */
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << RX_SHIFTER(ResourceIndex)), FALSE);
            /* Disable interrupt for SCL timer */
            Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << SCL_TIMER(ResourceIndex)), FALSE);
            /* Disable FlexIO DMA requests for both shifters */
            Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))), FALSE);
            break;
#endif
        default:
            /* Impossible type - do nothing */
            break;
    }

    Master->DriverIdle = TRUE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterEnableTransfer
 * Description   : Enables timers and shifters to start a transfer
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterEnableTransfer(const Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    uint8 TimerScl;
    uint8 TimerControl;

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    TimerScl = Master->SclAddChannel;
    TimerControl = Master->SdaAddChannel;
#else
    TimerScl = SCL_TIMER(ResourceIndex);
    TimerControl = CONTROL_TIMER(ResourceIndex);
#endif
    /* enable timers and shifters */
    Flexio_I2c_Ip_SetShifterMode(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_TRANSMIT);
    Flexio_I2c_Ip_SetShifterMode(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_RECEIVE);
    Flexio_I2c_Ip_SetTimerMode(BaseAddr, TimerScl, FLEXIO_TIMER_MODE_8BIT_BAUD);
    Flexio_I2c_Ip_SetTimerMode(BaseAddr, TimerControl, FLEXIO_TIMER_MODE_16BIT);
    /* enable Tx pin */
    Flexio_I2c_Ip_SetShifterPinConfig(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_PIN_CONFIG_OPEN_DRAIN);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterStopTransfer
 * Description   : Forcefully stops the current transfer
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterStopTransfer(Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    uint8 TimerScl;
    uint8 TimerControl;
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    TimerScl = Master->SclAddChannel;
    TimerControl = Master->SdaAddChannel;
#else
    TimerScl = SCL_TIMER(ResourceIndex);
    TimerControl = CONTROL_TIMER(ResourceIndex);
#endif
    /* disable Tx pin */
    Flexio_I2c_Ip_SetShifterPinConfig(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_PIN_CONFIG_DISABLED);
    /* disable and re-enable timers and shifters to reset them */
    Flexio_I2c_Ip_SetShifterMode(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_DISABLED);
    Flexio_I2c_Ip_SetShifterMode(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_DISABLED);
    Flexio_I2c_Ip_SetTimerMode(BaseAddr, TimerScl, FLEXIO_TIMER_MODE_DISABLED);
    Flexio_I2c_Ip_SetTimerMode(BaseAddr, TimerControl, FLEXIO_TIMER_MODE_DISABLED);

    /* clear any leftover error flags */
    Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, TX_SHIFTER(ResourceIndex));
    Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, RX_SHIFTER(ResourceIndex));
    /* discard any leftover rx. data */
    Flexio_Mcl_Ip_ClearShifterStatus(BaseAddr, RX_SHIFTER(ResourceIndex));
    /* Clear timer status */
    Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, TimerScl);

    /* end the transfer */
    Flexio_I2c_Ip_MasterEndTransfer(Master);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterWaitTransferEnd
 * Description   : waits for the end of a blocking transfer
 *
 *END**************************************************************************/
static Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterWaitTransferEnd(Flexio_I2c_Ip_MasterStateType *Master,
                                                                    uint32 Timeout)
{
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, FLEXIO_I2C_IP_TIMEOUT_TYPE);
    Flexio_I2c_Ip_StatusType OsifError = FLEXIO_I2C_IP_SUCCESS_STATUS;

    switch (Master->DriverType)
    {
        case FLEXIO_I2C_IP_DRIVER_TYPE_INTERRUPTS:
            /* Wait for transfer to be completed by the IRQ */
            break;
        case FLEXIO_I2C_IP_DRIVER_TYPE_POLLING:
            CurrentTicks = OsIf_GetCounter(FLEXIO_I2C_IP_TIMEOUT_TYPE);
            /* Call Flexio_I2c_Ip_MasterGetStatus() to do the transfer */
            do
            {
                OsifError = Flexio_I2c_Ip_MasterGetStatus(Master->FlexioCommon.Instance, (uint8)Master->FlexioCommon.ResourceIndex/2U, NULL_PTR);
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FLEXIO_I2C_IP_TIMEOUT_TYPE);
            }
            while ((FLEXIO_I2C_IP_BUSY_STATUS == OsifError) && (ElapsedTicks < TimeoutTicks));
            if (ElapsedTicks >= TimeoutTicks)
            {
                OsifError = FLEXIO_I2C_IP_TIMEOUT_STATUS;
            }
            break;
        case FLEXIO_I2C_IP_DRIVER_TYPE_DMA:
            /* Wait for transfer to be completed by the DMA IRQ */
            break;
        default:
            /* Impossible type - do nothing */
            break;
    }

    /* blocking transfer is over */
    Master->Blocking = FALSE;
    if (FLEXIO_I2C_IP_TIMEOUT_STATUS == OsifError)
    {
        /* abort current transfer */
        Master->Status = FLEXIO_I2C_IP_TIMEOUT_STATUS;
        Flexio_I2c_Ip_MasterStopTransfer(Master);
    }

    (void) Timeout;

    return Master->Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterCheckNack
 * Description   : Checks if the current Rx shifter error is NACK or RX_OVERFLOW
 *
 *         If there is a Tx event active it is an indication that module was not
 *         serviced for a long time - chances are this is an overflow.
 *         It is not certain, and it is even possible to have both NACK and overflow,
 *         but there is no way to tell, so we chose the safe option (if it is an
 *         overflow and we abort the transfer we may block the I2C bus).
 *
 *
 *END**************************************************************************/
static inline boolean Flexio_I2c_Ip_MasterCheckNack(const FLEXIO_Type *BaseAddr,
                                                    const Flexio_I2c_Ip_MasterStateType *Master)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    return !(Flexio_Mcl_Ip_GetShifterStatus(BaseAddr, TX_SHIFTER(ResourceIndex)));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterBusBusy
 * Description   : Check status of the I2C bus.
 *                 If either SDA or SCL is low, the bus is busy.
 *
 *END**************************************************************************/
static inline boolean Flexio_I2c_Ip_MasterBusBusy(const FLEXIO_Type *BaseAddr,
                                                  const Flexio_I2c_Ip_MasterStateType *Master)
{
    boolean RetValue = TRUE;
    uint32 PinMask = ((uint32)1U << Master->SdaPin) | ((uint32)1U << Master->SclPin);

    if ((Flexio_I2c_Ip_GetPinData(BaseAddr) & PinMask) == PinMask)
    {
        /* both pins are high, bus is not busy */
        RetValue = FALSE;
    }

    return RetValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterCheckStatus
 * Description   : Check status of the I2C transfer. This function can be
 *                 called either in an interrupt routine or directly in polling
 *                 mode to advance the I2C transfer.
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterCheckStatus(uint8 Instance,
                                            uint8 Channel)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    uint8 TimerScl;
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    TimerScl = Master->SclAddChannel;
#else
    TimerScl = SCL_TIMER(ResourceIndex);
#endif
    boolean EscapeFunction = FALSE;

    /* Check for errors */
    if (Flexio_Mcl_Ip_GetShifterErrorStatus(BaseAddr, TX_SHIFTER(ResourceIndex)))
    {
        Master->Status = FLEXIO_I2C_IP_TX_UNDERRUN_STATUS;
        Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, TX_SHIFTER(ResourceIndex));
        /* don't stop the transfer, continue processing events */
    }
    if (Flexio_Mcl_Ip_GetShifterErrorStatus(BaseAddr, RX_SHIFTER(ResourceIndex)))
    {
        /* Device limitation: not possible to tell the difference between NACK and receive overflow */
        if (Flexio_I2c_Ip_MasterCheckNack(BaseAddr, Master))
        {
            Master->Status = FLEXIO_I2C_IP_RECEIVED_NACK_STATUS;
            /* Force the transfer to stop */
            Flexio_I2c_Ip_MasterStopTransfer(Master);
#if (STD_ON == FLEXIO_I2C_IP_EVENT_ERROR_DETECT)
            /* Call callback to announce the event to the user */
            if (Master->Callback != NULL_PTR)
            {
                Master->Callback(FLEXIO_I2C_MASTER_EVENT_NACK, Master->CallbackParam);
            }
#endif
            EscapeFunction = TRUE;
        }
        else
        {
            Master->Status = FLEXIO_I2C_IP_RX_OVERRUN_STATUS;
            Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, RX_SHIFTER(ResourceIndex));
            /* don't stop the transfer, continue processing events */
        }
    }
    if ((Master->DriverType != FLEXIO_I2C_IP_DRIVER_TYPE_DMA) && (FALSE == EscapeFunction))
    {
        /* Check if data was received */
        if (Flexio_Mcl_Ip_GetShifterStatus(BaseAddr, RX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2c_Ip_ReadData(Master);
        }
        /* Check if transmitter needs more data */
        if (Flexio_Mcl_Ip_GetShifterStatus(BaseAddr, TX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2c_Ip_WriteData(Master);
            if (0U == Master->TxRemainingBytes)
            {
                /* Done transmitting, disable Tx interrupt */
                Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
            }
        }
    }
    /* Check if the transfer is over */
    if ((Flexio_Mcl_Ip_GetTimerStatus(BaseAddr, TimerScl)) && (FALSE == EscapeFunction))
    {
        Master->EventCount--;

        Flexio_I2c_Ip_TimerEventHandler(Master, TRUE);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterEnableInterrupt
 * Description   : This function use to Enable Interrupt for Shifter and Timer
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterEnableInterrupt(const Flexio_I2c_Ip_MasterStateType *Master)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Enable interrupt for Tx and Rx shifters */
    Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr,
                            (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                            TRUE);
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr,
                            (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                            TRUE);
    /* Enable interrupt for SCL timer */
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << SCL_TIMER(ResourceIndex)), TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterStartTransfer
 * Description   : Perform a send or receive transaction on the I2C bus
 *
 *END**************************************************************************/
static Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterStartTransfer(Flexio_I2c_Ip_MasterStateType *Master,
                                                                  uint32 Size,
                                                                  boolean SendStop,
                                                                  boolean Receive)
{
    FLEXIO_Type *BaseAddr;
    Flexio_I2c_Ip_StatusType ReturnStatus = FLEXIO_I2C_IP_SUCCESS_STATUS;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Check if bus is busy */
    if (Flexio_I2c_Ip_MasterBusBusy(BaseAddr, Master))
    {
        ReturnStatus = FLEXIO_I2C_IP_BUS_BUSY_STATUS;
    }
    else
    {
        /* Tx - one extra byte for stop condition */
        Master->TxRemainingBytes = Size + 1U;
        Master->RxRemainingBytes = Size;
        Master->Status = FLEXIO_I2C_IP_BUSY_STATUS;
        Master->DriverIdle = FALSE;
        Master->SendStop = SendStop;
        Master->Receive = Receive;
        Master->AddrReceived = FALSE;

        /* Configure device for requested number of bytes, keeping the existing baud rate */
        Flexio_I2c_Ip_MasterSetBytesNo(BaseAddr, Master);
        /* Enable timers and shifters */
        Flexio_I2c_Ip_MasterEnableTransfer(Master);
        /* Enable transfer engine */
        switch (Master->DriverType)
        {
            case FLEXIO_I2C_IP_DRIVER_TYPE_INTERRUPTS:
                /* Send address to start transfer */
                Flexio_I2c_Ip_MasterSendAddress(BaseAddr, Master);
                Flexio_I2c_Ip_MasterEnableInterrupt(Master);
                break;
            case FLEXIO_I2C_IP_DRIVER_TYPE_POLLING:
                /* Send address to start transfer */
                Flexio_I2c_Ip_MasterSendAddress(BaseAddr, Master);
                /* Nothing to do here, Flexio_I2c_Ip_MasterGetStatus() will handle the transfer */
                break;
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2C_IP_DRIVER_TYPE_DMA:
                Flexio_I2c_Ip_MasterStartDmaTransfer(BaseAddr, Master, Size);
                break;
#endif
            default:
                /* Impossible type - do nothing */
                break;
        }
        if (FLEXIO_I2C_IP_TIMEOUT_STATUS == Master->Status)
        {
            ReturnStatus = FLEXIO_I2C_IP_TIMEOUT_STATUS;
        }
    }

    return ReturnStatus;
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterEndDmaTransfer
 * Description   : Starts a DMA transfer
 *
 *END**************************************************************************/
void Flexio_I2c_Ip_MasterEndDmaTransfer(uint8 Instance,
                                        uint8 Channel,
                                        boolean Receive)
{
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(I2C_TIMEOUT, FLEXIO_I2C_IP_TIMEOUT_TYPE);
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    FLEXIO_Type *BaseAddr;
    boolean ShifterStatus;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Master);
#endif

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (Receive)
    {
        (void)Dma_Ip_SetLogicChannelCommand(Master->DmaRxChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)(1U << RX_SHIFTER(ResourceIndex)), FALSE);
    }
    else
    {
        (void)Dma_Ip_SetLogicChannelCommand(Master->DmaTxChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
    }

    if (Receive == Master->Receive)
    {
        if (Master->Receive)
        {
            /* Send NACK for last byte */
            Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
            /* Also instruct rx shifter to expect NACK */
            Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
        }
        if (Master->SendStop)
        {
            /* send stop condition */
            Flexio_I2c_Ip_WriteShifterBuffer(BaseAddr, TX_SHIFTER(ResourceIndex), (((uint32)FLEXIO_I2C_IP_STOP_BYTE_VALUE_U32)<<24U), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
        }
        else
        {
            /* leave bus free(repeated start condition) */
            Flexio_I2c_Ip_WriteShifterBuffer(BaseAddr, TX_SHIFTER(ResourceIndex), (((uint32)FLEXIO_I2C_IP_LEAVE_SDA_FREE_U32)<<24U), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
        }
        if (Master->Receive)
        {
            CurrentTicks = OsIf_GetCounter(FLEXIO_I2C_IP_TIMEOUT_TYPE);
            do
            {
                ShifterStatus = Flexio_Mcl_Ip_GetShifterStatus(BaseAddr, RX_SHIFTER(ResourceIndex));
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FLEXIO_I2C_IP_TIMEOUT_TYPE);
            }
            while ((ElapsedTicks < TimeoutTicks) &&(FALSE == ShifterStatus));

            if (ElapsedTicks >= TimeoutTicks)
            {
                /* report Timeout error */
                Master->Status = FLEXIO_I2C_IP_TIMEOUT_STATUS;
            }
            else
            {
                /* read last byte */
                Master->RxData[Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[7u].Value] = (uint8)Flexio_I2c_Ip_ReadShifterBuffer(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
            }
        }
    }
}
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterDmaTransferErrorHandler
 * Description   : Starts a DMA transfer
 *
 *END**************************************************************************/
void Flexio_I2c_Ip_MasterDmaTransferErrorHandler(uint8 Instance,
                                                 uint8 Channel)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    FLEXIO_Type *BaseAddr;
    Dma_Ip_LogicChannelStatusType eStatus;
    /*  Initial value is equal to DMA_IP_CH_RESET_STATE, in the event that Dma has not initialized the channel. */
    eStatus.ChStateValue = DMA_IP_CH_RESET_STATE;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Master);
#endif

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;


    if (!Master->Receive)
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(Master->DmaTxChannel, &eStatus);
    }
    else
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(Master->DmaRxChannel, &eStatus);
    }

    if (DMA_IP_CH_ERROR_STATE == eStatus.ChStateValue)
    {
         if (Master->Receive)
        {
            /* Send NACK for last byte */
            Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
            /* Also instruct rx shifter to expect NACK */
            Flexio_I2c_Ip_SetShifterStopBit(BaseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_STOP_BIT_1);
        }
        
        /* send stop condition */
        Flexio_I2c_Ip_WriteShifterBuffer(BaseAddr, TX_SHIFTER(ResourceIndex), (((uint32)FLEXIO_I2C_IP_STOP_BYTE_VALUE_U32)<<24U), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);

        /* Stop tranfer */
        Flexio_I2c_Ip_MasterStopTransfer(Master);

        /* report dma channel error */
        Master->Status = FLEXIO_I2C_IP_DMA_ERROR_STATUS;
#if (STD_ON == FLEXIO_I2C_IP_EVENT_ERROR_DETECT)
        if (Master->Callback != NULL_PTR)
        {
            Master->Callback(FLEXIO_I2C_MASTER_EVENT_DMA_TRANSFER_ERROR, Master->CallbackParam);
        }
#endif
    }
}
#endif /* STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT */

/*! @endcond */
#endif /* STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */
/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterInit
 * Description   : Initialize the FLEXIO_I2C master mode driver
 * Implements : Flexio_I2c_Ip_MasterInit_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterInit(uint8 Instance,
                                                  uint8 Channel,
                                                  const Flexio_I2c_Ip_MasterConfigType * ConfigPtr)
{
    Flexio_I2c_Ip_StatusType RetCode = FLEXIO_I2C_IP_ERROR_STATUS;
    Flexio_I2c_Ip_MasterStateType * Master;
    
#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Flexio_I2c_Ip_pxMasterState[Instance][Channel] == NULL_PTR);
    DevAssert(Instance < FLEXIO_I2C_IP_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2C_IP_MAX_CHANNEL_COUNT);
#endif
#if (FLEXIO_I2C_IP_NUMBER_OF_MASTER_CHANNEL != 0U)
    Flexio_I2c_Ip_pxMasterState[Instance][Channel] = &(Flexio_I2c_Ip_MasterState[ConfigPtr->MasterStateIdx]);
#endif
    Master =  Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    
    /* Instruct the resource allocator that we need two shifters/timers */
    Master->FlexioCommon.ResourceCount = 2U;

    /* Flexio Instance used */
    Master->FlexioCommon.Instance = ConfigPtr->Instance;
    
    /* Index of first used internal resource Instance (shifter and timer) */
    Master->FlexioCommon.ResourceIndex = ConfigPtr->ResourceIndex;

    /* The initial state prior to initialization must be FLEXIO_I2C_IP_SUCCESS_STATUS
       to make sure that no parallel actions are taking place simultaneously */
    if (FLEXIO_I2C_IP_SUCCESS_STATUS == Master->Status)
    {
        /* Common FlexIO driver initialization */
        Flexio_I2c_Ip_InitDriver(Instance, &(Master->FlexioCommon));

        /* Initialize driver-specific context structure */
        Master->I2cAsyncMethod = ConfigPtr->I2cAsyncMethod;
        Master->SlaveAddress = ConfigPtr->SlaveAddress;
        Master->SdaPin = ConfigPtr->SdaPin;
        Master->SclPin = ConfigPtr->SclPin;
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
        Master->TimerChannelDMA = ConfigPtr->TimerChannelDMA;
        Master->SclAddChannel=ConfigPtr->SclAddChannel;
        Master->SdaAddChannel=ConfigPtr->SdaAddChannel;
#endif
        Master->Callback = ConfigPtr->Callback;
        Master->CallbackParam = ConfigPtr->CallbackParam;
        Master->Blocking = FALSE;
        Master->DriverIdle = TRUE;
        Master->Status = FLEXIO_I2C_IP_SUCCESS_STATUS;

        /* Compare value of Flexio */
        Master->CmpValue = ConfigPtr->CmpValue;
        /* timer decrement value */
        Master->PrescaleValue = ConfigPtr->PrescaleValue;
        /* Configure device for I2C mode */
        Flexio_I2c_Ip_MasterConfigure(Master);

        /* Set up transfer engine */
        switch (Master->I2cAsyncMethod)
        {
            case FLEXIO_I2C_USING_INTERRUPTS:
                break;
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2C_USING_DMA:
                /* Store DMA channel numbers */
                Master->DmaTxChannel = ConfigPtr->DmaTxChannel;
                Master->DmaRxChannel = ConfigPtr->DmaRxChannel;
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
                Flexio_I2c_Ip_MasterCmdDmaTcdInit();
#endif
                break;
#endif
            default:
                /* Impossible type - do nothing */
                break;
        }
        RetCode = FLEXIO_I2C_IP_SUCCESS_STATUS;
    }

    return RetCode;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterDeinit
 * Description   : De-initialize the FLEXIO_I2C master mode driver
 * Implements : Flexio_I2c_Ip_MasterDeinit_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterDeinit(uint8 Instance,
                                                    uint8 Channel)
{
    FLEXIO_Type *BaseAddr;
    Flexio_I2c_Ip_StatusType RetStatus = FLEXIO_I2C_IP_BUSY_STATUS;
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Clear timer status */
    Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, (Master->FlexioCommon.ResourceIndex + 1U));

    /* Clear Shifter status */
    Flexio_Mcl_Ip_ClearShifterStatus(BaseAddr, Master->FlexioCommon.ResourceIndex);

    /* Check if Driver is busy */
    if (Master->DriverIdle)
    {
        RetStatus = (Flexio_I2c_Ip_StatusType)Flexio_I2c_Ip_DeinitDriver(&(Master->FlexioCommon));

        /* Clear the status to be ready for the next initialization */
        Master->Status = FLEXIO_I2C_IP_SUCCESS_STATUS;
        Flexio_I2c_Ip_pxMasterState[Instance][Channel] = NULL_PTR;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterSetBaudRate
 * Description   : Set the baud rate for any subsequent I2C communication
 * Implements : Flexio_I2c_Ip_MasterSetBaudRate_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSetBaudRate(uint8 Instance,
                                                         uint8 Channel,
                                                         uint32 InputClock,
                                                         uint32 BaudRate)
{
    const Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType RetStatus = FLEXIO_I2C_IP_BUSY_STATUS;
    FLEXIO_Type *BaseAddr;

    uint16 Divider;
    uint16 TimerCmp;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex; 
    /* Check if driver is busy */
    if (Master->DriverIdle)
    {
        /* Compute divider */
        Flexio_I2c_Ip_MasterComputeBaudRateDivider(BaudRate, &Divider, InputClock);

        /* Configure timer divider in the lower 8 bits of TIMCMP[CMP] */
        TimerCmp = Flexio_I2c_Ip_GetTimerCompare(BaseAddr, SCL_TIMER(ResourceIndex));
        TimerCmp = (uint16)((TimerCmp & 0xFF00U) | Divider);
        Flexio_I2c_Ip_SetTimerCompare(BaseAddr, SCL_TIMER(ResourceIndex), TimerCmp);
        RetStatus = FLEXIO_I2C_IP_SUCCESS_STATUS;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterGetBaudRate
 * Description   : Get the currently configured baud rate
 * Implements : Flexio_I2c_Ip_MasterGetBaudRate_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterGetBaudRate(uint8 Instance,
                                                         uint8 Channel,
                                                         uint32 InputClock,
                                                         uint32 *BaudRate)
{
    const Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    const FLEXIO_Type *BaseAddr;
    uint16 Divider;
    uint16 TimerCmp;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(BaudRate != NULL_PTR);
#endif
    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
 
    /* Get the currently configured divider */
    TimerCmp = Flexio_I2c_Ip_GetTimerCompare(BaseAddr, SCL_TIMER(ResourceIndex));
    Divider = (uint16)(TimerCmp & 0x00FFU);

    /* Compute baud rate: input_clock / (2 * (Divider + 2)). Round to nearest integer */
    *BaudRate = (InputClock + Divider + 2U) / (2U * ((uint32)Divider + 2U));

    return FLEXIO_I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterSetSlaveAddr
 * Description   : Set the slave address for any subsequent I2C communication
 * Implements : Flexio_I2c_Ip_MasterSetSlaveAddr_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSetSlaveAddr(uint8 Instance,
                                                          uint8 Channel,
                                                          const uint16 Address)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType RetStatus = FLEXIO_I2C_IP_BUSY_STATUS;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    /* Check if Driver is busy */
    if (Master->DriverIdle)
    {
        Master->SlaveAddress = Address;
        RetStatus = FLEXIO_I2C_IP_SUCCESS_STATUS;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterSendData
 * Description   : Perform a non-blocking send transaction on the I2C bus
 * Implements : Flexio_I2c_Ip_MasterSendData_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSendData(uint8 Instance,
                                                      uint8 Channel,
                                                      const uint8 * TxBuff,
                                                      uint32 TxSize,
                                                      boolean SendStop)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType RetStatus = FLEXIO_I2C_IP_BUSY_STATUS;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif
    
    if (FLEXIO_I2C_USING_INTERRUPTS == Master->I2cAsyncMethod)
    {
        Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_INTERRUPTS;
    }
    else if (FLEXIO_I2C_USING_DMA == Master->I2cAsyncMethod)
    {
        Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_DMA;
    }
    else
    {
        Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_POLLING;
    }
    
    /* Check if driver is busy */
    if (Master->DriverIdle)
    {
        /* Initialize transfer data */
        Master->TxData = TxBuff;
        /* Start the transfer */
        RetStatus = Flexio_I2c_Ip_MasterStartTransfer(Master, TxSize, SendStop, FALSE);
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterSendDataBlocking
 * Description   : Perform a blocking send transaction on the I2C bus
 * Implements : Flexio_I2c_Ip_MasterSendDataBlocking_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterSendDataBlocking(uint8 Instance,
                                                              uint8 Channel,
                                                              const uint8 * TxBuff,
                                                              uint32 TxSize,
                                                              boolean SendStop,
                                                              uint32 Timeout)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType RetStatus = FLEXIO_I2C_IP_BUSY_STATUS;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif

    Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_POLLING;
    /* Check if Driver is busy */
    if (Master->DriverIdle)
    {
        /* Initialize transfer data */
        Master->TxData = TxBuff;
        /* Start the transfer */
        RetStatus = Flexio_I2c_Ip_MasterStartTransfer(Master, TxSize, SendStop, FALSE);

        if (RetStatus != FLEXIO_I2C_IP_SUCCESS_STATUS)
        {
            /* Transfer could not be started */
            Master->Blocking = FALSE;
        }
        else
        {
            /* Wait for transfer to end */
            RetStatus = Flexio_I2c_Ip_MasterWaitTransferEnd(Master, Timeout);
        }
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterReceiveData
 * Description   : Perform a non-blocking receive transaction on the I2C bus
 * Implements : Flexio_I2c_Ip_MasterReceiveData_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterReceiveData(uint8 Instance,
                                                         uint8 Channel,
                                                         uint8 * RxBuff,
                                                         uint32 RxSize,
                                                         boolean SendStop)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType RetStatus = FLEXIO_I2C_IP_BUSY_STATUS;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif

    if (FLEXIO_I2C_USING_INTERRUPTS == Master->I2cAsyncMethod)
    {
        Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_INTERRUPTS;
    }
    else if (FLEXIO_I2C_USING_DMA == Master->I2cAsyncMethod)
    {
        Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_DMA;
    }
    else
    {
        Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_POLLING;
    }
    
    /* Check if Driver is busy */
    if (Master->DriverIdle)
    {
        /* Initialize transfer data */
        Master->RxData = RxBuff;
        /* Start the transfer */
        RetStatus = Flexio_I2c_Ip_MasterStartTransfer(Master, RxSize, SendStop, TRUE);
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterReceiveDataBlocking
 * Description   : Perform a blocking receive transaction on the I2C bus
 * Implements : Flexio_I2c_Ip_MasterReceiveDataBlocking_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterReceiveDataBlocking(uint8 Instance,
                                                                 uint8 Channel,
                                                                 uint8 * RxBuff,
                                                                 uint32 RxSize,
                                                                 boolean SendStop,
                                                                 uint32 Timeout)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType Status = FLEXIO_I2C_IP_BUSY_STATUS;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif
    Master->DriverType = FLEXIO_I2C_IP_DRIVER_TYPE_POLLING;
    /* Check if driver is busy */
    if (Master->DriverIdle)
    {
        /* Initialize transfer data */
        Master->RxData = RxBuff;

        /* Start the transfer */
        Status = Flexio_I2c_Ip_MasterStartTransfer(Master, RxSize, SendStop, TRUE);
        if (Status != FLEXIO_I2C_IP_SUCCESS_STATUS)
        {
            /* Transfer could not be started */
            Master->Blocking = FALSE;
        }
        else
        {
            /* Wait for transfer to end */
            Status = Flexio_I2c_Ip_MasterWaitTransferEnd(Master, Timeout);
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterTransferAbort
 * Description   : Aborts a non-blocking I2C master transaction
 * Implements : Flexio_I2c_Ip_MasterTransferAbort_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterTransferAbort(uint8 Instance,
                                                           uint8 Channel)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    /* Warning: an ongoing transfer can't be aborted safely due to device limitation;
       there is no way to know the exact stage of the transfer, and if we disable the module
       during the ACK bit (transmit) or during a 0 data bit (receive) the slave will hold
       the SDA line low forever and block the I2C bus. NACK reception is the only exception,
       as there is no slave to hold the line low. Therefore this function should only be used
       in extreme circumstances, and the application must have a way to reset the I2C slave
    */

    /* Check if Driver is busy */
    if (!(Master->DriverIdle))
    {
        Master->Status = FLEXIO_I2C_IP_ABORTED_STATUS;
        Flexio_I2c_Ip_MasterStopTransfer(Master);
    }

    return FLEXIO_I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterGetStatus
 * Description   : Get the status of the current non-blocking I2C master transaction
 * Implements : Flexio_I2c_Ip_MasterGetSTATUS_FLEXIO_I2C_IP_Activity
 *
 *END**************************************************************************/
Flexio_I2c_Ip_StatusType Flexio_I2c_Ip_MasterGetStatus(uint8 Instance,
                                                       uint8 Channel,
                                                       uint32 *BytesRemaining)
{
    const Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];
    Flexio_I2c_Ip_StatusType Status = FLEXIO_I2C_IP_BUSY_STATUS;
    uint32 RemainingBytes;

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    /* Use rxRemainingBytes even for transmit; byte is not transmitted
       until rx shifter confirms the ACK */
    RemainingBytes = Master->RxRemainingBytes;

    if (!Master->DriverIdle)
    {
        switch (Master->DriverType)
        {
            case FLEXIO_I2C_IP_DRIVER_TYPE_POLLING:
                /* In polling mode advance the I2C transfer here */
                (void)Flexio_I2c_Ip_MasterCheckStatus(Instance, Channel);
                break;

            case FLEXIO_I2C_IP_DRIVER_TYPE_DMA:
                /* In DMA mode just update the remaining count.
                DO NOT write Master->RxRemainingBytes directly !!! */
                break;

            default:
                /* Nothing */
                break;
        }

    }

    if (BytesRemaining != NULL_PTR)
    {
        *BytesRemaining = RemainingBytes;
    }

    if (Master->DriverIdle)
    {
        Status = Master->Status;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_SetMasterCallback
 * Description   : Sets the master callback
 *
 *END**************************************************************************/
void Flexio_I2c_Ip_SetMasterCallback(uint8 Instance,
                                     uint8 Channel,
                                     Flexio_I2c_Ip_MasterCallbackType MasterCallback)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[Instance][Channel];

#if (STD_ON == FLEXIO_I2C_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Master);
#endif
    Master->Callback = MasterCallback;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_MasterCheckEvent
 * Description   : Check if event had occurred for selected FlexIO channel
 *
 *END**************************************************************************/
static boolean Flexio_I2c_Ip_MasterCheckEvent(uint8 StatusMask,
                                              uint8 Channel)
{
    return ((((((uint32)StatusMask) >> Channel) & 1U) == 1U) ? TRUE : FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_TransmitEventHandler
 * Description   : handler for transmit event
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_TransmitEventHandler(Flexio_I2c_Ip_MasterStateType *Master,
                                               uint8 ShifterMaskFlag,
                                               uint8 ShifterErrMaskFlag,
                                               uint8 TimerMaskFlag)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    boolean EscapeFunction = FALSE;

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Handle events for TX shifter or SCL timer */

    if (Flexio_I2c_Ip_MasterCheckEvent(ShifterErrMaskFlag, TX_SHIFTER(ResourceIndex)))
    {
        Master->Status = FLEXIO_I2C_IP_TX_UNDERRUN_STATUS;
        /* don't stop the transfer, continue processing events */
    }

    /* Check NACK */
    if (Flexio_I2c_Ip_MasterCheckEvent(ShifterErrMaskFlag, RX_SHIFTER(ResourceIndex)))
    {
     /* If NACK occurred, don't check other events for TX channel */
        EscapeFunction = TRUE;
    }

    if ((Master->DriverType != FLEXIO_I2C_IP_DRIVER_TYPE_DMA) && (FALSE == EscapeFunction))
    {
        /* Check if transmitter needs more data */
        if (Flexio_I2c_Ip_MasterCheckEvent(ShifterMaskFlag, TX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2c_Ip_WriteData(Master);
            if (0U == Master->TxRemainingBytes)
            {
                /* Done transmitting, disable Tx interrupt */
                Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
            }
        }
     }

    /* Check if the transfer is over */
    if ((Flexio_I2c_Ip_MasterCheckEvent(TimerMaskFlag, SCL_TIMER(ResourceIndex))) && (FALSE == EscapeFunction))
    {
        Master->EventCount--;
        Flexio_I2c_Ip_TimerEventHandler(Master, FALSE);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_ReceiveEventHandler
 * Description   : handler for receive event
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_ReceiveEventHandler(Flexio_I2c_Ip_MasterStateType *Master,
                                              uint8 ShifterMaskFlag,
                                              uint8 ShifterErrMaskFlag)
{
    const FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    boolean EscapeFunction = FALSE;

    BaseAddr = Flexio_I2c_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (Flexio_I2c_Ip_MasterCheckEvent(ShifterErrMaskFlag, RX_SHIFTER(ResourceIndex)))
    {
        /* Device limitation: not possible to tell the difference between NACK and Receive overflow */
        if (Flexio_I2c_Ip_MasterCheckNack(BaseAddr, Master))
        {
            Master->Status = FLEXIO_I2C_IP_RECEIVED_NACK_STATUS;
            /* Force the transfer to stop */
            Flexio_I2c_Ip_MasterStopTransfer(Master);
#if (STD_ON == FLEXIO_I2C_IP_EVENT_ERROR_DETECT)
            /* Call callback to announce the event to the user */
            if (Master->Callback != NULL_PTR)
            {
                Master->Callback(FLEXIO_I2C_MASTER_EVENT_NACK, Master->CallbackParam);
            }
#endif

            EscapeFunction = TRUE;
        }
        else
        {
            Master->Status = FLEXIO_I2C_IP_RX_OVERRUN_STATUS;
            /* don't stop the transfer, continue processing events */
        }
    }

    if ((Master->DriverType != FLEXIO_I2C_IP_DRIVER_TYPE_DMA) && (FALSE == EscapeFunction))
    {
        /* Check if data was received */
        if (TRUE == Flexio_I2c_Ip_MasterCheckEvent(ShifterMaskFlag, RX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2c_Ip_ReadData(Master);
        }
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2c_Ip_IrqHandler
 * Description   : Handler for FlexIO I2c channels
 * Implements    : Flexio_I2c_Ip_IrqHandler_Activity
 *END**************************************************************************/
void Flexio_I2c_Ip_IrqHandler(const uint8 FlexIOChannel,
                              uint8 ShifterMaskFlag,
                              uint8 ShifterErrMaskFlag, 
                              uint8 TimerMaskFlag)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2c_Ip_MasterStateType *Master;
    uint8 I2cChannel = (uint8)(FlexIOChannel/2U);

    uint8 Instance = 0U;
    Master = Flexio_I2c_Ip_pxMasterState[Instance][I2cChannel];

    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (0U != Flexio_I2c_Ip_au8ChannelStatus[I2cChannel])
    {
        if (FlexIOChannel == ResourceIndex)
        {
            Flexio_I2c_Ip_TransmitEventHandler(Master, ShifterMaskFlag, ShifterErrMaskFlag, TimerMaskFlag);
        }
        else
        {
            Flexio_I2c_Ip_ReceiveEventHandler(Master, ShifterMaskFlag, ShifterErrMaskFlag);
        }
    }
}


#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_InitDmaParamElementSg
 * Description   : This function configures the TCD for I2C DMA transfers
 *
 *END**************************************************************************/
static void I2c_Ip_InitDmaParamElementSg(Dma_Ip_LogicChannelScatterGatherListType * Flexio_I2c_ListTransfer)
{
    Flexio_I2c_ListTransfer[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Flexio_I2c_ListTransfer[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Flexio_I2c_ListTransfer[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    Flexio_I2c_ListTransfer[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Flexio_I2c_ListTransfer[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Flexio_I2c_ListTransfer[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    Flexio_I2c_ListTransfer[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Flexio_I2c_ListTransfer[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    Flexio_I2c_ListTransfer[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    Flexio_I2c_ListTransfer[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    Flexio_I2c_ListTransfer[10u].Param = DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST;
}
#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/

#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_CmdDmaTcdInit
 * Description   : This function configures the TCD for I2C DMA transfers
 *
 *END**************************************************************************/
static void Flexio_I2c_Ip_MasterCmdDmaTcdInit(void)
{
    /* Configure DMA channel for send transfers */
    /* Source  configuration parameters  */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    /* Destination configuration parameters */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    /* Minor/Major Loop parameters */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    /* Disable Hw auto request and enable interrupts */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    /* Source  configuration values */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[1u].Value = 1U;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Destination configuration values */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[4u].Value = 0U;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Minor/Major Loop values */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[6u].Value = 1U;
    /* Disable Hw auto request and enable interrupts */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[8u].Value = 1U;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListSend[9u].Value = 1U;

    /* Configure DMA channel for receive transfers*/
    /* Source  configuration parameters  */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    /* Destination configuration parameters  */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    /* Minor/Major Loop parameters */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    /* Disable Hw auto request and enable interrupts */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    /* Source  configuration values */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[1u].Value = 0U;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Destination configuration values */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[4u].Value = 1U;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Minor/Major Loop values */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[6u].Value = 1U;
    /* Disable Hw auto request and enable interrupts */
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[8u].Value = 1U;
    Flexio_I2c_Ip_aDmaFlexioChannelTransferListReceive[9u].Value = 1U;
}
#endif /* STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE */

#endif /* STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */

#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_0_1_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 0_1
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter0(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 0U,FALSE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}
/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_2_3_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 2_3
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter1(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 0U,TRUE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler0
 * Description   : Dma error notification for flexio channel 0_1
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler0(void)
{
    Flexio_I2c_Ip_MasterDmaTransferErrorHandler(0U, 0U);
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_4_5_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 4_5
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter2(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 1U,FALSE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_6_7_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 6_7
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter3(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 1U,TRUE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler1
 * Description   : Dma error notification for flexio channel 2_3
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler1(void)
{
    Flexio_I2c_Ip_MasterDmaTransferErrorHandler(0U, 1U);
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_4_5_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 4_5
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter4(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 2U,FALSE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_4_5_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 4_5
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter5(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 2U,TRUE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler2
 * Description   : Dma error notification for flexio channel 3_4
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler2(void)
{
    Flexio_I2c_Ip_MasterDmaTransferErrorHandler(0U, 2U);
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_6_7_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 6_7
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter6(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 3U,FALSE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_6_7_DmaCompleteNotification
 * Description   : Dma complete notification for flexio channel 6_7
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationShifter7(void)
{
#if (STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
    Flexio_I2c_Ip_MasterEndDmaTransfer(0U, 3U,TRUE);
#endif /*STD_OFF == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
}

#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler3
 * Description   : Dma error notification for flexio channel 6_7
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferNotificationErrorHandler3(void)
{
    Flexio_I2c_Ip_MasterDmaTransferErrorHandler(0U, 3U);
}
#endif

#if (STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE)
#ifdef FLEXIO_0_CH_0_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_DmaCompleteNotification
 * Description   : Dma complete notification for flexio Timer 2
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationTimer2(void)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[FLEXIO_I2C_INSTANCE_0][FLEXIO_I2C_INSTANCE_0_CHANNEL_0];
    Flexio_I2c_Ip_HandleEventTimerDMA(Master);
}
#endif /*FLEXIO_0_CH_0_USED*/

#ifdef FLEXIO_0_CH_4_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_FLEXIO_DmaCompleteNotification
 * Description   : Dma complete notification for flexio Timer 6
 *
 *END**************************************************************************/
void FlexIO_I2c_Ip_DmaTransferCompleteNotificationTimer6(void)
{
    Flexio_I2c_Ip_MasterStateType * Master = Flexio_I2c_Ip_pxMasterState[FLEXIO_I2C_INSTANCE_0][FLEXIO_I2C_INSTANCE_0_CHANNEL_2];
    Flexio_I2c_Ip_HandleEventTimerDMA(Master);
}
#endif /*FLEXIO_0_CH_4_USED*/

#endif /*STD_ON == FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE*/
#endif /* STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */
#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#endif /* FLEXIO_I2C_IP_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} */

