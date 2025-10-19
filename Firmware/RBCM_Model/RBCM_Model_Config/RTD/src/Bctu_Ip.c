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
#include "Bctu_Ip.h"
#include "Bctu_Ip_Irq.h"
#include "OsIf.h"
#include "SchM_Adc.h"

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BCTU_IP_VENDOR_ID_C                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_C       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define BCTU_IP_SW_MAJOR_VERSION_C               5
#define BCTU_IP_SW_MINOR_VERSION_C               0
#define BCTU_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip.c file and Bctu_Ip.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_C != BCTU_IP_VENDOR_ID)
    #error "Bctu_Ip.c and Bctu_Ip.h have different vendor ids"
#endif

/* Check if Bctu_Ip.c file and Bctu_Ip.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_C != BCTU_IP_AR_RELEASE_MINOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_C != BCTU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.c and Bctu_Ip.h are different"
#endif

/* Check if Bctu_Ip.c file and Bctu_Ip.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_C != BCTU_IP_SW_MAJOR_VERSION) || \
     (BCTU_IP_SW_MINOR_VERSION_C != BCTU_IP_SW_MINOR_VERSION) || \
     (BCTU_IP_SW_PATCH_VERSION_C != BCTU_IP_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Bctu_Ip.c and Bctu_Ip.h are different"
#endif

/* Check if Bctu_Ip.c file and Bctu_Ip_Irq.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_C != BCTU_IP_VENDOR_ID_IRQ)
    #error "Bctu_Ip.c and Bctu_Ip_Irq.h have different vendor ids"
#endif

/* Check if Bctu_Ip.c file and Bctu_Ip_Irq.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_C != BCTU_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_C != BCTU_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.c and Bctu_Ip_Irq.h are different"
#endif

/* Check if Bctu_Ip.c file and Bctu_Ip_Irq.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_C != BCTU_IP_SW_MAJOR_VERSION_IRQ) || \
     (BCTU_IP_SW_MINOR_VERSION_C != BCTU_IP_SW_MINOR_VERSION_IRQ) || \
     (BCTU_IP_SW_PATCH_VERSION_C != BCTU_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Bctu_Ip.c and Bctu_Ip_Irq.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.c and OsIf.h are different"
#endif

/* Check if Bctu_Ip.c file and SchM_Adc.h file are of the same version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.c and SchM_Adc.h are different"
#endif

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
/* Check if Bctu_Ip.c and Devassert.h are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.c and Devassert.h are different"
#endif
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/
#define BCTU_HW_REG_SIZE            (32u)
#define BCTU_LIST_NUM_ELEMS         (BCTU_LISTCHR_COUNT * 2u) /* Each LISTCHR reg contains 2 list elements */
#define BCTU_PROTEC_CODE_TEMP       (9u)  /* 0b1001u */
#define BCTU_PROTEC_CODE_PERMANENT  (10u) /* 0b1010u */
#define BCTU_ADC_INSTANCE_BITMASK   (Bctu_GetBitmask(FEATURE_BCTU_NUM_ADC) - 1u)


/*==================================================================================================
*                                     GLOBAL VARIABLES
==================================================================================================*/
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/* Table of base addresses for BCTU instances. */
static BCTU_Type * const Bctu_Ip_apxBctuBase[BCTU_INSTANCE_COUNT] = IP_BCTU_BASE_PTRS;

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

/* BCTU State structure for storing callbacks */
static Bctu_Ip_StateStructType Bctu_Ip_axBctuState[BCTU_INSTANCE_COUNT];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"

#ifdef BCTU_IP_DMA_SUPPORTED
static uint32 Bctu_Ip_au32BctuFifoDmaChannel[BCTU_INSTANCE_COUNT][BCTU_IP_FIFO_COUNT];
#endif /* BCTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONST_8
#include "Adc_MemMap.h"

/* Offset for mapping some bit fields and registers of BCTU to corresponding ADC instance.
Eg: ADC0DR of BCTU0 using for ADC0 but ADC0DR of BCTU1 is for ADC3 */
static const uint8 Bctu_Ip_au8AdcOffset[BCTU_INSTANCE_COUNT] = BCTU_IP_ADC_INDEX_OFFSET_ARRAY;

#define ADC_STOP_SEC_CONST_8
#include "Adc_MemMap.h"

/*==================================================================================================
*                                     LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

static inline uint32 Bctu_GetBitmask(const uint8 Pos);
static inline uint32 Bctu_CollectMcrMasks(const Bctu_Ip_ConfigType * const Config);
static inline Bctu_Ip_StatusType Bctu_PrepareReconfigBlocking(BCTU_Type * const BctuBasePtr,
                                                       const uint8 TrigIdx);
static inline Bctu_Ip_StatusType Bctu_PrepareReconfigNonBlocking(BCTU_Type * const BctuBasePtr,
                                                          const uint8 TrigIdx);
static inline void Bctu_ConfigMultiAdcSubLists(const uint32 Instance,
                                               const Bctu_Ip_ListItemConfigType * const AdcCmdArray,
                                               const uint8 NumCmds);
static inline void Bctu_ConfigAndUpdateFifoNotification(const uint32 Instance,
                                                        const Bctu_Ip_FifoConfigType * const FifoConfigArray,
                                                        const uint8 NumFifoConfigs);
static inline void Bctu_SetConvListElemWithTag(const uint32 Instance,
                                               const uint8 ElemIdx,
                                               const uint8 AdcChanNumbers,
                                               const boolean NextChanWaitOnTrig);
static inline void Bctu_SetConvListLastElement(const uint32 Instance,
                                               const uint8 ElemIdx);
static inline void Bctu_CheckAndCallFifoNotification(const uint32 Instance,
                                                     const uint8 FifoIdx);
#if (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON)
static inline uint16 Bctu_GetResolutionScaledResult(const uint8 AdcIdx,
                                                    const uint32 RawResult);
#endif /* (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON) */

#ifdef BCTU_IP_DMA_SUPPORTED
static inline void Bctu_FifoSetupDma(const Bctu_Ip_FifoConfigType * const FifoConfig,
                                     const uint32 FifoAddress);
#endif /* BCTU_IP_DMA_SUPPORTED */

/*==================================================================================================
*                                     FUNCTION DEFINITIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_Init
* Description   : This function configures the global functionalities of
* a BCTU instance.
*
* @implements     Bctu_Ip_Init_Activity
* END**************************************************************************/
void Bctu_Ip_Init(const uint32 u32Instance,
                  const Bctu_Ip_ConfigType * const pConfig)
{
    uint8 Index;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(pConfig != NULL_PTR);
    DevAssert(pConfig->NewDataDmaEnMask <= BCTU_ADC_INSTANCE_BITMASK);
    DevAssert(pConfig->NumTrigConfigs <= BCTU_TRGCFG_COUNT);
    DevAssert(pConfig->NumListItems <= (BCTU_LISTCHR_COUNT  * 2u));
    DevAssert(pConfig->NumFifoConfigs <= BCTU_IP_FIFO_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    BctuBasePtr->MCR = Bctu_CollectMcrMasks(pConfig);

    /* Clear pending interrupt flags - CPR_RTD_01182 */
    Bctu_Ip_ClearStatusFlags(u32Instance, (uint32) BCTU_IP_STATUS_ALL);

    /* Configure triggers */
    if ((pConfig->TrigConfigs != NULL_PTR) && (pConfig->NumTrigConfigs > 0u))
    {
        for (Index = 0u; Index < pConfig->NumTrigConfigs; Index++)
        {
            (void)Bctu_Ip_ConfigTrigger(u32Instance, &pConfig->TrigConfigs[Index]);
        }
    }

    /* Configure lists */
    if (pConfig->ListItemConfigs != NULL_PTR)
    {
        Bctu_ConfigMultiAdcSubLists(u32Instance, pConfig->ListItemConfigs, pConfig->NumListItems);
    }

    /* Configure FIFOs */
    if (pConfig->FifoConfigs != NULL_PTR)
    {
        Bctu_ConfigAndUpdateFifoNotification(u32Instance, pConfig->FifoConfigs, pConfig->NumFifoConfigs);
    }

    /* Save notifications to state structure */
    Bctu_Ip_axBctuState[u32Instance].TriggerNotification = pConfig->TriggerNotification;
    for (Index = 0u; Index < FEATURE_BCTU_NUM_ADC; Index++)
    {
        Bctu_Ip_axBctuState[u32Instance].AdcNotifications[Index].NewConvDataNotification = pConfig->AdcNotifications[Index].NewConvDataNotification;
        Bctu_Ip_axBctuState[u32Instance].AdcNotifications[Index].ConvDataOverrunNotification = pConfig->AdcNotifications[Index].ConvDataOverrunNotification;
        Bctu_Ip_axBctuState[u32Instance].AdcNotifications[Index].ListLastConversionNotification = pConfig->AdcNotifications[Index].ListLastConversionNotification;
    }

    /* Mark that the driver was initialized */
    Bctu_Ip_axBctuState[u32Instance].InitStatus = TRUE;
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_Deinit
* Description   : This function resets the BCTU registers to default values.
* It globally disables all triggers, leaving the BCTU in configuration mode.
*
* @implements     Bctu_Ip_Deinit_Activity
* END**************************************************************************/
Bctu_Ip_StatusType Bctu_Ip_Deinit(const uint32 u32Instance)
{
    Bctu_Ip_ConfigType DefaultConfig;
    uint8 Index;
    Bctu_Ip_StatusType Status = BCTU_IP_STATUS_SUCCESS;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    /* First step: globally disable the triggers. */
    BctuBasePtr->MCR &= ~(BCTU_MCR_GTRGEN_MASK);

    /* Reset global config register. */
    DefaultConfig.LowPowerModeEn      = FALSE;
    DefaultConfig.GlobalHwTriggersEn  = FALSE;
    DefaultConfig.NewDataDmaEnMask   = 0u;
    DefaultConfig.TriggerNotification = NULL_PTR;
    for (Index = 0u; Index < FEATURE_BCTU_NUM_ADC; Index++)
    {
        DefaultConfig.AdcNotifications[Index].NewConvDataNotification = NULL_PTR;
        DefaultConfig.AdcNotifications[Index].ConvDataOverrunNotification = NULL_PTR;
        DefaultConfig.AdcNotifications[Index].ListLastConversionNotification = NULL_PTR;
    }
    DefaultConfig.NumFifoConfigs     = 0u;
    DefaultConfig.FifoConfigs         = NULL_PTR;
    DefaultConfig.NumTrigConfigs     = 0u;
    DefaultConfig.TrigConfigs         = NULL_PTR;
    DefaultConfig.NumListItems       = 0u;
    DefaultConfig.ListItemConfigs     = NULL_PTR;
    Bctu_Ip_Init(u32Instance, &DefaultConfig);

    /* First, attempt to reset all TRGCFG registers in provided timeout interval.
     * If any current active conversion completes in time,
     * status and result registers may get updated - they must be reset later. */
    for (Index = 0u; Index < BCTU_TRGCFG_COUNT; Index++)
    {
        if (Bctu_PrepareReconfigBlocking(BctuBasePtr, Index) == BCTU_IP_STATUS_SUCCESS)
        {
            /* After this point the TRGCFG register can be modified freely. */

            /* Reserved bits are written with '0'.
            * Any bits w1c are cleared when preparing on the fly reconfiguration. */
            BctuBasePtr->TRGCFG[Index] = 0u;

            Status = BCTU_IP_STATUS_SUCCESS;
        }
        else
        {
            Status = BCTU_IP_STATUS_TIMEOUT;
            break;
        }
    }

    if (Status == BCTU_IP_STATUS_SUCCESS)
    {
        /* Reset LISTCHR */
        for (Index = 0u; Index < BCTU_LISTCHR_COUNT; Index++)
        {
            BctuBasePtr->LISTCHR[Index] = 0u;
        }

        /* Reset FIFO configs */
        for (Index = 0u; Index < BCTU_IP_FIFO_COUNT; Index++)
        {
            Bctu_Ip_SetFifoWatermark(u32Instance, Index, 0u);
        }
        BctuBasePtr->FIFOCR = 0u;

        /* Reset status register */
        Bctu_Ip_ClearStatusFlags(u32Instance, (uint32) BCTU_IP_STATUS_ALL);

        /* Write protection and result registers cannot be reset */

        /* Mark that the driver was deinitialized */
        Bctu_Ip_axBctuState[u32Instance].InitStatus = FALSE;
    }

    return Status;
}


/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_SetGlobalTriggerEn
* Description   : This function sets the state of the Global Trigger Enable flag.
*
* @implements     Bctu_Ip_SetGlobalTriggerEn_Activity
* END**************************************************************************/
void Bctu_Ip_SetGlobalTriggerEn(const uint32 u32Instance,
                                const boolean bState)
{
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    if (TRUE == bState)
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_54();
        BctuBasePtr->MCR |= BCTU_MCR_GTRGEN_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_54();
    }
    else
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_54();
        BctuBasePtr->MCR &= (~BCTU_MCR_GTRGEN_MASK);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_54();
    }
}


/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_SetLowPowerMode
* Description   : This function sets the BCTU operating mode: normal or low power.
* In low power mode all trigger inputs are ignored and any pending triggers remain active.
*
* @implements     Bctu_Ip_SetLowPowerMode_Activity
* END**************************************************************************/
void Bctu_Ip_SetLowPowerMode(const uint32 u32Instance,
                             const boolean bState)
{
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    if (TRUE == bState)
    {
        /* Enable Low Power Mode */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_55();
        BctuBasePtr->MCR |= BCTU_MCR_MDIS_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_55();
    }
    else
    {
        /* Disable Low Power Mode */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_55();
        BctuBasePtr->MCR &= (~BCTU_MCR_MDIS_MASK);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_55();
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_GetStatusFlags
* Description   : This function returns the value of selected BCTU status flags.
*
* @implements     Bctu_Ip_GetStatusFlags_Activity
* END**************************************************************************/
uint32 Bctu_Ip_GetStatusFlags(const uint32 u32Instance)
{
    uint32 Reg;
    uint32 Mask = 0u;
    uint8 Index;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    Reg = BctuBasePtr->MSR;

    /* Get ADC related status flags */
    for (Index = 0u; Index < FEATURE_BCTU_NUM_ADC; Index++)
    {
        Mask |= ((Reg & ((uint32)BCTU_MSR_NDATA0_MASK << Index)) != 0U) ? (BCTU_IP_STATUS_ADC0_NDATA << Index) : 0U;
        Mask |= ((Reg & ((uint32)BCTU_MSR_DATAOVR0_MASK << Index)) != 0U) ? (BCTU_IP_STATUS_ADC0_DATAOVR << Index) : 0U;
        Mask |= ((Reg & ((uint32)BCTU_MSR_LIST0_Last_MASK << Index)) != 0U) ? (BCTU_IP_STATUS_ADC0_LAST << Index) : 0U;
    }

    /* Get TRGCF status flag */
    Mask |= ((Reg & ((uint32)BCTU_MSR_TRGF_MASK)) != 0U) ? (BCTU_IP_STATUS_TRG) : 0U;

    /* Get FIFO related status flags */
    Reg = BctuBasePtr->FIFOERR;
    for (Index = 0u; Index < BCTU_IP_FIFO_COUNT; Index++)
    {
        Mask |= ((BctuBasePtr->FIFOSR & ((uint32)BCTU_FIFOSR_FULL_FIFO1_MASK << Index)) != 0U) ? (BCTU_IP_STATUS_FIFO1_FULL << Index) : 0U;

        Mask |= ((Reg & ((uint32)BCTU_FIFOERR_WM_INT_FIFO1_MASK << Index)) != 0U) ? (BCTU_IP_STATUS_FIFO1_WM_INT << Index) : 0U;

        /*
         * The following fields are intertwined e.g. OVR for FIFO1 is
         * next to UNDR for FIFO1 so the *2 is needed to shift into the
         * correct field position.
         */
        Mask |= ((Reg & ((uint32)BCTU_FIFOERR_OVR_ERR_FIFO1_MASK << (Index * 2u))) != 0U) ? (BCTU_IP_STATUS_FIFO1_OVR_ERR << Index) : 0U;
        Mask |= ((Reg & ((uint32)BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK << (Index * 2u))) != 0U) ? (BCTU_IP_STATUS_FIFO1_UNDR_ERR << Index) : 0U;
    }

    return Mask;
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_ClearStatusFlags
* Description   : This function clears selected BCTU status flags.
* Note: u32Mask should use BCTU_IP_STATUS_... defines to select flags to clear.
*
* @implements     Bctu_Ip_ClearStatusFlags_Activity
* END**************************************************************************/
void Bctu_Ip_ClearStatusFlags(const uint32 u32Instance,
                              const uint32 u32Mask)
{
    uint32 ClrMask = 0u;
    uint8 Index;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert((u32Mask & (~BCTU_IP_STATUS_ALL)) == 0UL);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    /* Create mask to clear MSR status flags */
    for (Index = 0u; Index < FEATURE_BCTU_NUM_ADC; Index++)
    {
        ClrMask |= ((u32Mask & (BCTU_IP_STATUS_ADC0_NDATA << Index)) != 0U) ? (BCTU_MSR_NDATA0_CLR_MASK << Index) : 0U;
        ClrMask |= ((u32Mask & (BCTU_IP_STATUS_ADC0_DATAOVR << Index)) != 0U) ? (BCTU_MSR_DATAOVR0_CLR_MASK << Index) : 0U;
        ClrMask |= ((u32Mask & (BCTU_IP_STATUS_ADC0_LAST << Index)) != 0U) ? (BCTU_MSR_LIST0_Last_CLR_MASK << Index) : 0U;
    }
    ClrMask |= ((u32Mask & BCTU_IP_STATUS_TRG) != 0U) ? (BCTU_MSR_TRGF_CLR_MASK) : 0U;

    /* Write to register */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_70();
    BctuBasePtr->MSR |= ClrMask;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_70();

    /* Dummy read to guarantee write is complete, when memory write buffering is enabled. */
    (void) BctuBasePtr->MSR;

    /* Create mask to clear FIFOERR status flags */
    ClrMask = 0u;
    for (Index = 0u; Index < BCTU_IP_FIFO_COUNT; Index++)
    {
        ClrMask |= ((u32Mask & (BCTU_IP_STATUS_FIFO1_WM_INT << Index)) != 0U) ? (BCTU_FIFOERR_WM_INT_FIFO1_MASK << Index) : 0U;

        /*
         * The following fields are intertwined e.g. OVR for FIFO1 is
         * next to UNDR for FIFO1 so the *2 is needed to shift into the
         * correct field position.
         */
        ClrMask |= ((u32Mask & (BCTU_IP_STATUS_FIFO1_OVR_ERR << (Index * 2u))) != 0U) ? (BCTU_FIFOERR_OVR_ERR_FIFO1_MASK << Index) : 0U;
        ClrMask |= ((u32Mask & (BCTU_IP_STATUS_FIFO1_UNDR_ERR << (Index * 2u))) != 0U) ? (BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK << Index) : 0U;
    }

    /* Write to register */
    BctuBasePtr->FIFOERR = ClrMask;

    /* Dummy read to guarantee write is complete, when memory write buffering is enabled. */
    (void) BctuBasePtr->FIFOERR;
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_ConfigTrigger
* Description   : Attempts to configure a trigger configuration register for
* an individual conversion. If there is an on-going conversion started via
* target trigger, it only disables the trigger (will ignore any new triggers)
* and returns error code.
*
* @implements     Bctu_Ip_ConfigTrigger_Activity
* END**************************************************************************/
Bctu_Ip_StatusType Bctu_Ip_ConfigTrigger(const uint32 u32Instance,
                                         const Bctu_Ip_TrigConfigType * const pTrigConfig)
{
    uint32 Trgcfg;
    uint8 Idx;
    Bctu_Ip_StatusType Status;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(pTrigConfig != NULL_PTR);
    DevAssert(pTrigConfig->TrigIndex < BCTU_TRGCFG_COUNT);
    DevAssert((pTrigConfig->AdcTargetMask <= BCTU_ADC_INSTANCE_BITMASK) && \
                    (pTrigConfig->AdcTargetMask != 0u));
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    Status = Bctu_PrepareReconfigNonBlocking(BctuBasePtr, pTrigConfig->TrigIndex);

    if (Status == BCTU_IP_STATUS_SUCCESS)
    {
        /* After this point the TRGCFG register can be modified freely. */
        Trgcfg = 0u;
        Trgcfg |= (TRUE == pTrigConfig->LoopEn) ? BCTU_TRGCFG_LOOP_MASK : 0u;
        Trgcfg |= (TRUE == pTrigConfig->HwTriggersEn) ? BCTU_TRGCFG_TRIGEN_MASK : 0u;
        Trgcfg |= BCTU_TRGCFG_DATA_DEST(pTrigConfig->DataDest);
        Trgcfg |= BCTU_TRGCFG_TRS(pTrigConfig->TrigType);
        Trgcfg |= BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR(pTrigConfig->AdcChanOrListStart);

        /* Selecting more than one ADC is valid only for list conversion. If selecting
        more than one ADC for a single-conversion trigger, BCTU ignores the trigger. */
        switch (pTrigConfig->AdcTargetMask)
        {
            case 1u:
                Trgcfg |= BCTU_TRGCFG_ADC_SEL0_MASK;
                break;
#if (FEATURE_BCTU_NUM_ADC >= 2u)
            case 2u:
                Trgcfg |= BCTU_TRGCFG_ADC_SEL1_MASK;
                break;
#endif /* (FEATURE_BCTU_NUM_ADC >= 2u) */
#if (FEATURE_BCTU_NUM_ADC >= 3u)
            case 4u:
                Trgcfg |= BCTU_TRGCFG_ADC_SEL2_MASK;
                break;
#endif /* (FEATURE_BCTU_NUM_ADC >= 3u) */
#if (FEATURE_BCTU_NUM_ADC >= 4u)
            case 8u:
                Trgcfg |= BCTU_TRGCFG_ADC_SEL3_MASK;
                break;
#endif /* (FEATURE_BCTU_NUM_ADC >= 4u) */
            default:
                /* If configuration is LIST */
                if (pTrigConfig->TrigType == BCTU_IP_TRIG_TYPE_LIST)
                {
                    for (Idx = 0u; Idx < FEATURE_BCTU_NUM_ADC; Idx++)
                    {
                        Trgcfg |= ((pTrigConfig->AdcTargetMask & Bctu_GetBitmask(Idx)) != 0u) ? ((uint32)BCTU_TRGCFG_ADC_SEL0_MASK << Idx) : 0u;
                    }
                }
                else /* Configuration is SINGLE */
                {
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
                    DevAssert(FALSE); /* A single (non-list) conversion can be triggered only on a single ADC. */
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
                }
                break;
        }

        BctuBasePtr->TRGCFG[pTrigConfig->TrigIndex] = Trgcfg;
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_SetTriggerChnListAddr
* Description   : Attempts to configure the first address of the command list
* associated with an internal trigger or channel. If there is an on-going conversion started via
* target trigger, it only disables the trigger (will ignore any new triggers)
* and returns error code.
*
* @implements     Bctu_Ip_SetTriggerChnListAddr_Activity
* END**************************************************************************/
Bctu_Ip_StatusType Bctu_Ip_SetTriggerChnListAddr(const uint32 u32Instance,
                                                 const uint8 u8TrigIdx,
                                                 const boolean bList,
                                                 const uint8 u8ChnOrListAddr)
{
    uint32 Trgcfg = 0u;
    Bctu_Ip_StatusType Status;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8TrigIdx < BCTU_TRGCFG_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    Status = Bctu_PrepareReconfigNonBlocking(BctuBasePtr, u8TrigIdx);

    if (Status == BCTU_IP_STATUS_SUCCESS)
    {
        /* Clear TRS and CHANNEL_VALUE_OR_LADDR bit fields before updating new value */
        BctuBasePtr->TRGCFG[u8TrigIdx] &= ~(BCTU_TRGCFG_TRS_MASK | BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR_MASK);

        Trgcfg |= BCTU_TRGCFG_TRS(bList ? 1U : 0U);
        Trgcfg |= BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR(u8ChnOrListAddr);

        BctuBasePtr->TRGCFG[u8TrigIdx] |= Trgcfg;
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_EnableHwTrigger
* Description   : This function clears any eventual pending hw input signals already
* occurred on the selected trigger and enables new occurrences of the hw input signals
* to start new conversions.
*
* @implements     Bctu_Ip_EnableHwTrigger_Activity
* END**************************************************************************/
void Bctu_Ip_EnableHwTrigger(const uint32 u32Instance,
                             const uint8 u8TrigIdx)
{
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8TrigIdx < BCTU_TRGCFG_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_58();
    /* Clear any pending hw input signals already occurred on the selected trigger. */
    BctuBasePtr->TRGCFG[u8TrigIdx] |= BCTU_TRGCFG_TRG_FLAG_MASK;
    /* Enable new occurrences of the hw input signals to start new conversions. */
    BctuBasePtr->TRGCFG[u8TrigIdx] |= BCTU_TRGCFG_TRIGEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_58();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_DisableHwTrigger
* Description   : This function prevents the selected BCTU trigger to start
* new conversions on the occurrence of a hw input signal and also new conversions
* in an on-going conversion loop (loop flag enabled).
* After calling this function, new conversions may still be started by BCTU software trigger.
* Note: the function does NOT stop an on-going conversion.
*
* @implements     Bctu_Ip_DisableHwTrigger_Activity
* END**************************************************************************/
void Bctu_Ip_DisableHwTrigger(const uint32 u32Instance,
                              const uint8 u8TrigIdx)
{
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8TrigIdx < BCTU_TRGCFG_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_59();
    /* Prevent any new conversions from starting when external input signal occurs.
     * This also stops new conversions from starting when loop flag is enabled. */
    BctuBasePtr->TRGCFG[u8TrigIdx] &= (~BCTU_TRGCFG_TRIGEN_MASK);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_59();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_StopLoopConversions
* Description   : This function stops a series of loop conversions initiated by
* the selected BCTU trigger.
* Note0: the function does NOT stop an on-going conversion.
* Note1: the function assumes that no HW trigger occurs on the selected trigger
* during its execution - the reset & restore operation on the LOOP flag is not atomic!
* Occurrence of a HW trigger may start a new conversion with an inconsistent value
* for the LOOP flag.
* For stopping HW triggered loops of conversions consider also using Bctu_Ip_DisableHwTrigger.
*
* @implements     Bctu_Ip_StopLoopConversions_Activity
* END**************************************************************************/
void Bctu_Ip_StopLoopConversions(const uint32 u32Instance,
                                 const uint8 u8TrigIdx)
{
    uint32 LoopBitmask = 0u;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8TrigIdx < BCTU_TRGCFG_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_60();
    LoopBitmask = BctuBasePtr->TRGCFG[u8TrigIdx] & BCTU_TRGCFG_LOOP_MASK;

    /* Reset loop flag to stop a series of loop conversions */
    BctuBasePtr->TRGCFG[u8TrigIdx] &= (~BCTU_TRGCFG_LOOP_MASK);

    /* Restore loop flag */
    BctuBasePtr->TRGCFG[u8TrigIdx] |= (LoopBitmask & BCTU_TRGCFG_LOOP_MASK);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_60();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_ConfigChanList
* Description   : This function sets the conversion list using an array of ListItemType structures.
* Also marks the element corresponding to the last channel in the array, as last element in the list.
* Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
*
* @implements     Bctu_Ip_ConfigChanList_Activity
* END**************************************************************************/
void Bctu_Ip_ConfigChanList(const uint32 u32Instance,
                            const uint8 u8StartListElemIdx,
                            const Bctu_Ip_ListItemType * const pConvListItems,
                            const uint8 u8NumItems)
{
    uint8 Index;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8StartListElemIdx < BCTU_LIST_NUM_ELEMS);
    DevAssert(pConvListItems != NULL_PTR);
    DevAssert(u8NumItems > 0u);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    for (Index = 0u; Index < u8NumItems; Index++)
    {
        Bctu_SetConvListElemWithTag(u32Instance, ((Index + u8StartListElemIdx) % (uint8)BCTU_LIST_NUM_ELEMS), pConvListItems[Index].AdcChanIndex, pConvListItems[Index].NextChanWaitOnTrig);
    }
    Bctu_SetConvListLastElement(u32Instance, (u8NumItems + u8StartListElemIdx - 1u) % (uint8)BCTU_LIST_NUM_ELEMS);
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_ConfigChanListSimple
* Description   : This function sets an array of adc channel numbers in the conversion list.
* Also marks the element corresponding to the last channel in the array, as last element in the list.
* Other configurable fields of a conversion element, like NEXT_CH_WAIT_ON_TRIG_y is set to false/0.
* Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
*
* @implements     Bctu_Ip_ConfigChanListSimple_Activity
* END**************************************************************************/
void Bctu_Ip_ConfigChanListSimple(const uint32 u32Instance,
                                  const uint8 u8StartListElemIdx,
                                  const uint8 * const pConvListItems,
                                  const uint8 u8NumItems)
{
    uint8 Index;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8StartListElemIdx < BCTU_LIST_NUM_ELEMS);
    DevAssert(pConvListItems != NULL_PTR);
    DevAssert(u8NumItems > 0u);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    for (Index = 0u; Index < u8NumItems; Index++)
    {
        Bctu_SetConvListElemWithTag(u32Instance, ((Index + u8StartListElemIdx) % (uint8)BCTU_LIST_NUM_ELEMS), pConvListItems[Index], FALSE);
    }
    Bctu_SetConvListLastElement(u32Instance, (u8NumItems + u8StartListElemIdx - 1u) % (uint8)BCTU_LIST_NUM_ELEMS);
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_ConfigMultiAdcSubLists
* Description   : This function configures an array of ADC commands that might contains multiple sub lists
*
* END**************************************************************************/
static inline void Bctu_ConfigMultiAdcSubLists(const uint32 Instance,
                                               const Bctu_Ip_ListItemConfigType * const AdcCmdArray,
                                               const uint8 NumCmds)
{
    uint8 Index = 0U;

    for (Index = 0U; Index < NumCmds; Index++)
    {
        Bctu_SetConvListElemWithTag(Instance, (Index % (uint8)BCTU_LIST_NUM_ELEMS), AdcCmdArray[Index].AdcChanIndex, AdcCmdArray[Index].NextChanWaitOnTrig);

        if (AdcCmdArray[Index].LastChanInList)
        {
            Bctu_SetConvListLastElement(Instance, (Index % (uint8)BCTU_LIST_NUM_ELEMS));
        }
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_SwTriggerConversion
* Description   : This function triggers a conversion or list of conversions associated
* with a trigger index. The function disables write protection for SFTRGR for 1 cycle.
* It is recommended that this function is used with HW triggers disabled for the target trigger index,
* to avoid ambiguity regarding source of trigger (hw or sw) for conversion results.
*
* The BCTU HW will ignore attempts to trigger a new conversion or list,
* while there is a pending conversion or, in case of an active conversion list,
* before the last conversion is started.
*
* @implements     Bctu_Ip_SwTriggerConversion_Activity
* END**************************************************************************/
void Bctu_Ip_SwTriggerConversion(const uint32 u32Instance,
                                 const uint8 u8TrigIdx)
{
    uint32 Bitmask;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8TrigIdx < BCTU_TRGCFG_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    /* The function disables write protection for SFTRGR for 1 cycle. */
    BctuBasePtr->WRPROT = BCTU_WRPROT_PROTEC_CODE(BCTU_PROTEC_CODE_TEMP);

    /* Set the bit corresponding to the TrigIndex position in the 32 bit register. */
    Bitmask = Bctu_GetBitmask(u8TrigIdx % BCTU_HW_REG_SIZE);
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_71();
    switch (u8TrigIdx / BCTU_HW_REG_SIZE)
    {
        case 0u:
            BctuBasePtr->SFTRGR1 |= Bitmask;
            break;
#if (BCTU_TRGCFG_COUNT > (1u * BCTU_HW_REG_SIZE))
        case 1u:
            BctuBasePtr->SFTRGR2 |= Bitmask;
            break;
#endif /* (BCTU_TRGCFG_COUNT > (1u * BCTU_HW_REG_SIZE)) */
#if (BCTU_TRGCFG_COUNT > (2u * BCTU_HW_REG_SIZE))
        case 2u:
            BctuBasePtr->SFTRGR3 |= Bitmask;
            break;
#endif /* (BCTU_TRGCFG_COUNT > (2u * BCTU_HW_REG_SIZE)) */
        default:
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE); /* Invalid index of SWTRG register. */
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_71();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_GetConvData
* Description   : This function returns the current conversion result data
* corresponding to an adc instance.
* Note: In order to return the result with the correct resolution, the
* ADC_SAR instance used must still be initialized when calling this function.
*
* @implements     Bctu_Ip_GetConvData_Activity
* END**************************************************************************/
uint16 Bctu_Ip_GetConvData(const uint32 u32Instance,
                           const uint8 u8AdcIdx)
{
    uint32 Data;
    /* Mapping the index of BCTU instance's register ADCDR corresponding to ADC instance */
    const uint8 AdcIndexForBctu = u8AdcIdx - Bctu_Ip_au8AdcOffset[u32Instance];

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(AdcIndexForBctu < FEATURE_BCTU_NUM_ADC);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    Data = (BctuBasePtr->ADCDR[AdcIndexForBctu] & BCTU_ADCDR_ADC_DATA_MASK) >> BCTU_ADCDR_ADC_DATA_SHIFT;
#if (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON)
    return Bctu_GetResolutionScaledResult(u8AdcIdx, Data);
#else
    return Data;
#endif /* FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON */
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_GetConvResult
* Description   : This function returns the full conversion result information
* corresponding to an adc instance.
* Note: In order to return the result with the correct resolution, the
* ADC_SAR instance used must still be initialized when calling this function.
*
* @implements     Bctu_Ip_GetConvResult_Activity
* END**************************************************************************/
void Bctu_Ip_GetConvResult(const uint32 u32Instance,
                           const uint8 u8AdcIdx,
                           Bctu_Ip_ResultType * const pResult)
{
    uint32 dr;
    /* Mapping the index of BCTU instance's register ADCDR corresponding to ADC instance */
    const uint8 AdcIndexForBctu = u8AdcIdx - Bctu_Ip_au8AdcOffset[u32Instance];

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(AdcIndexForBctu < FEATURE_BCTU_NUM_ADC);
    DevAssert(pResult != NULL_PTR);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];
    dr = BctuBasePtr->ADCDR[AdcIndexForBctu];
#if (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON)
    pResult->AdcData   = Bctu_GetResolutionScaledResult(u8AdcIdx, (dr & BCTU_ADCDR_ADC_DATA_MASK) >> BCTU_ADCDR_ADC_DATA_SHIFT);
#else
    pResult->AdcData   = (dr & BCTU_ADCDR_ADC_DATA_MASK) >> BCTU_ADCDR_ADC_DATA_SHIFT;
#endif /* FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON */
    pResult->ChanIdx    = (uint8)  ((dr & BCTU_ADCDR_CH_MASK)       >> BCTU_ADCDR_CH_SHIFT);
    pResult->TriggerIdx = (uint8)  ((dr & BCTU_ADCDR_TRG_SRC_MASK)  >> BCTU_ADCDR_TRG_SRC_SHIFT);
    pResult->LastFlag    = ((dr & BCTU_ADCDR_LAST_MASK) != 0u) ? TRUE : FALSE;
    pResult->ListFlag    = ((dr & BCTU_ADCDR_LIST_MASK) != 0u) ? TRUE : FALSE;
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_GetFifoData
* Description   : This function returns the conversion result data stored in
* the BCTU result FIFO at the given index.
* Note: In order to return the result with the correct resolution, the
* ADC_SAR instance used must still be initialized when calling this function.
*
* @implements     Bctu_Ip_GetFifoData_Activity
* END**************************************************************************/
uint16 Bctu_Ip_GetFifoData(const uint32 u32Instance,
                           const uint8 u8FifoIdx)
{
    uint32 Data = 0u;
    uint32 ResultFifo = 0u;
    uint8 AdcIdx = 0u;
    /* Offset for mapping ADC instance with BCTU (ADC0-ADC2: BCTU0, ADC3-ADC6: BCTU1) 
    because bitfield ADC_NUM in register FIFODR just from 0-3 */
    const uint8 AdcOffset = Bctu_Ip_au8AdcOffset[u32Instance];

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8FifoIdx < BCTU_IP_FIFO_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    switch (u8FifoIdx)
    {
        case 0u:
            ResultFifo = BctuBasePtr->FIFO1DR;
            AdcIdx = (uint8)((ResultFifo & BCTU_FIFO1DR_ADC_NUM_MASK) >> BCTU_FIFO1DR_ADC_NUM_SHIFT) + AdcOffset;
            Data = (ResultFifo & BCTU_FIFO1DR_ADC_DATA_MASK) >> BCTU_FIFO1DR_ADC_DATA_SHIFT;
            break;
        case 1u:
            ResultFifo = BctuBasePtr->FIFO2DR;
            AdcIdx = (uint8)((ResultFifo & BCTU_FIFO2DR_ADC_NUM_MASK) >> BCTU_FIFO2DR_ADC_NUM_SHIFT) + AdcOffset;
            Data = (ResultFifo & BCTU_FIFO2DR_ADC_DATA_MASK) >> BCTU_FIFO2DR_ADC_DATA_SHIFT;
            break;
#if (BCTU_IP_FIFO_COUNT > 2U)
        case 2u:
            ResultFifo = BctuBasePtr->FIFO3DR;
            AdcIdx = (uint8)((ResultFifo & BCTU_FIFO3DR_ADC_NUM_MASK) >> BCTU_FIFO3DR_ADC_NUM_SHIFT) + AdcOffset;
            Data = (ResultFifo & BCTU_FIFO3DR_ADC_DATA_MASK) >> BCTU_FIFO3DR_ADC_DATA_SHIFT;
            break;
#endif
        default:
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }
#if (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON)
    return Bctu_GetResolutionScaledResult(AdcIdx, Data);
#else
    return Data;
#endif /* FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON */
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_GetFifoResult
* Description   : This function returns the full conversion result information
* that is stored in the BCTU result FIFO at the given index.
* Note: In order to return the result with the correct resolution, the
* ADC_SAR instance used must still be initialized when calling this function.
*
* @implements     Bctu_Ip_GetFifoResult_Activity
* END**************************************************************************/
void Bctu_Ip_GetFifoResult(const uint32 u32Instance,
                           const uint8 u8FifoIdx,
                           Bctu_Ip_FifoResultType * const pResult)
{
    uint32 ResultFifo = 0u;
    uint32 TempResult = 0u;
    /* Offset for mapping ADC instance with BCTU (ADC0-ADC2: BCTU0, ADC3-ADC6: BCTU1) 
    because bitfield ADC_NUM in register FIFODR just from 0-3 */
    const uint8 AdcOffset = Bctu_Ip_au8AdcOffset[u32Instance];

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8FifoIdx < BCTU_IP_FIFO_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    switch (u8FifoIdx)
    {
        case 0:
            ResultFifo         = BctuBasePtr->FIFO1DR;
            TempResult         = (ResultFifo & BCTU_FIFO1DR_ADC_DATA_MASK) >> BCTU_FIFO1DR_ADC_DATA_SHIFT;
            pResult->TriggerIdx = (uint8)  ((ResultFifo & BCTU_FIFO1DR_TRG_SRC_MASK)  >> BCTU_FIFO1DR_TRG_SRC_SHIFT);
            pResult->ChanIdx    = (uint8)  ((ResultFifo & BCTU_FIFO1DR_CH_MASK)       >> BCTU_FIFO1DR_CH_SHIFT);
            pResult->AdcNum     = (uint8)  ((ResultFifo & BCTU_FIFO1DR_ADC_NUM_MASK)  >> BCTU_FIFO1DR_ADC_NUM_SHIFT) + AdcOffset;
            break;
        case 1:
            ResultFifo         = BctuBasePtr->FIFO2DR;
            TempResult         = (ResultFifo & BCTU_FIFO2DR_ADC_DATA_MASK) >> BCTU_FIFO2DR_ADC_DATA_SHIFT;
            pResult->TriggerIdx = (uint8)  ((ResultFifo & BCTU_FIFO2DR_TRG_SRC_MASK)  >> BCTU_FIFO2DR_TRG_SRC_SHIFT);
            pResult->ChanIdx    = (uint8)  ((ResultFifo & BCTU_FIFO2DR_CH_MASK)       >> BCTU_FIFO2DR_CH_SHIFT);
            pResult->AdcNum     = (uint8)  ((ResultFifo & BCTU_FIFO2DR_ADC_NUM_MASK)  >> BCTU_FIFO2DR_ADC_NUM_SHIFT) + AdcOffset;
            break;
#if (BCTU_IP_FIFO_COUNT > 2U)
        case 2:
            ResultFifo         = BctuBasePtr->FIFO3DR;
            TempResult         = (ResultFifo & BCTU_FIFO3DR_ADC_DATA_MASK) >> BCTU_FIFO3DR_ADC_DATA_SHIFT;
            pResult->TriggerIdx = (uint8)  ((ResultFifo & BCTU_FIFO3DR_TRG_SRC_MASK)  >> BCTU_FIFO3DR_TRG_SRC_SHIFT);
            pResult->ChanIdx    = (uint8)  ((ResultFifo & BCTU_FIFO3DR_CH_MASK)       >> BCTU_FIFO3DR_CH_SHIFT);
            pResult->AdcNum     = (uint8)  ((ResultFifo & BCTU_FIFO3DR_ADC_NUM_MASK)  >> BCTU_FIFO3DR_ADC_NUM_SHIFT) + AdcOffset;
            break;
#endif
        default:
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }
#if (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON)
    pResult->AdcData = Bctu_GetResolutionScaledResult(pResult->AdcNum, TempResult);
#else
    pResult->AdcData = TempResult;
#endif /* FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON*/
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_EnableNotifications
* Description   : This function enables notifications selected by the given mask
* on the selected BCTU instance.
*
* @implements     Bctu_Ip_EnableNotifications_Activity
* END**************************************************************************/
void Bctu_Ip_EnableNotifications(const uint32 u32Instance,
                                 const uint32 u32NotificationMask)
{
    uint32 Reg = 0u;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    /* Clear pending interrupt flags - CPR_RTD_01182 */
    Bctu_Ip_ClearStatusFlags(u32Instance, (uint32) BCTU_IP_STATUS_ALL);

    /* Set MCR notifications */
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC0) != 0U) ? BCTU_MCR_IEN0(1U) : 0U;
#if (FEATURE_BCTU_NUM_ADC >= 2u)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC1) != 0U) ? BCTU_MCR_IEN1(1U) : 0U;
#endif /* (FEATURE_BCTU_NUM_ADC >= 2u) */
#if (FEATURE_BCTU_NUM_ADC >= 3u)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC2) != 0U) ? BCTU_MCR_IEN2(1U) : 0U;
#endif /* (FEATURE_BCTU_NUM_ADC >= 3u) */
#if (FEATURE_BCTU_NUM_ADC >= 4u)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC3) != 0U) ? BCTU_MCR_IEN3(1U) : 0U;
#endif /* (FEATURE_BCTU_NUM_ADC >= 4u) */
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_TRG) != 0U) ? BCTU_MCR_TRGEN(1U) : 0U;
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_LIST) != 0U) ? BCTU_MCR_LIST_IEN(1U) : 0U;
   
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_56();
    BctuBasePtr->MCR |= Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_56();

    /* Set FIFOCR notifications */
    Reg = 0u;
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_FIFO1) != 0U) ? BCTU_FIFOCR_IEN_FIFO1(1U) : 0U;
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_FIFO2) != 0U) ? BCTU_FIFOCR_IEN_FIFO2(1U) : 0U;
#if (BCTU_IP_FIFO_COUNT > 2U)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_FIFO3) != 0U) ? BCTU_FIFOCR_IEN_FIFO3(1U) : 0U;
#endif
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_63();
    BctuBasePtr->FIFOCR |= Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_63();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_DisableNotifications
* Description   : This function disables notifications selected by the given mask
* on the selected BCTU instance.
*
* @implements     Bctu_Ip_DisableNotifications_Activity
* END**************************************************************************/
void Bctu_Ip_DisableNotifications(const uint32 u32Instance,
                                  const uint32 u32NotificationMask)
{
    uint32 Reg = 0u;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    /* Clear selected MCR notifications */
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC0) != 0U) ? BCTU_MCR_IEN0(1U) : 0U;
#if (FEATURE_BCTU_NUM_ADC >= 2u)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC1) != 0U) ? BCTU_MCR_IEN1(1U) : 0U;
#endif /* (FEATURE_BCTU_NUM_ADC >= 2u) */
#if (FEATURE_BCTU_NUM_ADC >= 3u)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC2) != 0U) ? BCTU_MCR_IEN2(1U) : 0U;
#endif /* (FEATURE_BCTU_NUM_ADC >= 3u) */
#if (FEATURE_BCTU_NUM_ADC >= 4u)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_ADC3) != 0U) ? BCTU_MCR_IEN3(1U) : 0U;
#endif /* (FEATURE_BCTU_NUM_ADC >= 4u) */
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_TRG) != 0U) ? BCTU_MCR_TRGEN(1U) : 0U;
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_LIST) != 0U) ? BCTU_MCR_LIST_IEN(1U) : 0U;
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_57();
    BctuBasePtr->MCR &= ~(Reg);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_57();

    /* Clear selected FIFOCR notifications */
    Reg = 0u;
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_FIFO1) != 0U) ? BCTU_FIFOCR_IEN_FIFO1(1U) : 0U;
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_FIFO2) != 0U) ? BCTU_FIFOCR_IEN_FIFO2(1U) : 0U;
#if (BCTU_IP_FIFO_COUNT > 2U)
    Reg |= ((u32NotificationMask & BCTU_IP_NOTIF_FIFO3) != 0U) ? BCTU_FIFOCR_IEN_FIFO3(1U) : 0U;
#endif
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_64();
    BctuBasePtr->FIFOCR &= ~(Reg);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_64();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_SetFifoWatermark
* Description   : This function sets the watermark value for the selected FIFO.
*
* @implements     Bctu_Ip_SetFifoWatermark_Activity
* END**************************************************************************/
void Bctu_Ip_SetFifoWatermark(const uint32 u32Instance,
                              const uint8 u8FifoIdx,
                              const uint8 u8Watermark)
{
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8FifoIdx < BCTU_IP_FIFO_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_66();
    switch (u8FifoIdx)
    {
        case 0:
            BctuBasePtr->FIFOWM &= ~(BCTU_FIFOWM_WM_FIFO1_MASK);
            BctuBasePtr->FIFOWM |= BCTU_FIFOWM_WM_FIFO1(u8Watermark);
            break;
        case 1:
            BctuBasePtr->FIFOWM &= ~(BCTU_FIFOWM_WM_FIFO2_MASK);
            BctuBasePtr->FIFOWM |= BCTU_FIFOWM_WM_FIFO2(u8Watermark);
            break;
#if (BCTU_IP_FIFO_COUNT > 2U)
        case 2:
            BctuBasePtr->FIFOWM &= ~(BCTU_FIFOWM_WM_FIFO3_MASK);
            BctuBasePtr->FIFOWM |= BCTU_FIFOWM_WM_FIFO3(u8Watermark);
            break;
#endif
        default:
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_66();
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_GetFifoCount
* Description   : This function returns the the counter value of the given FIFO.
*
* @implements     Bctu_Ip_GetFifoCount_Activity
* END**************************************************************************/
uint8 Bctu_Ip_GetFifoCount(const uint32 u32Instance,
                           const uint8 u8FifoIdx)
{
    uint8 Count = 0u;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u32Instance < BCTU_INSTANCE_COUNT);
    DevAssert(u8FifoIdx < BCTU_IP_FIFO_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    const BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[u32Instance];

    switch (u8FifoIdx)
    {
        case 0:
            Count = (uint8) ((BctuBasePtr->FIFOCNTR & BCTU_FIFOCNTR_CNTR_FIFO1_MASK) >> BCTU_FIFOCNTR_CNTR_FIFO1_SHIFT);
            break;
        case 1:
            Count = (uint8) ((BctuBasePtr->FIFOCNTR & BCTU_FIFOCNTR_CNTR_FIFO2_MASK) >> BCTU_FIFOCNTR_CNTR_FIFO2_SHIFT);
            break;
#if (BCTU_IP_FIFO_COUNT > 2U)
        case 2:
            Count = (uint8) ((BctuBasePtr->FIFOCNTR & BCTU_FIFOCNTR_CNTR_FIFO3_MASK) >> BCTU_FIFOCNTR_CNTR_FIFO3_SHIFT);
            break;
#endif
        default:
#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */
            break;
    }

    return Count;
}

/*FUNCTION*********************************************************************
 *
 * Function Name : Bctu_CollectMcrMasks
 * Description   : The function collects the mask for MCR register from provided
 * structure. The funcion is used to reduce the complexity of Bctu_Ip_Init()
 *
 *END*************************************************************************/
static inline uint32 Bctu_CollectMcrMasks(const Bctu_Ip_ConfigType * const Config)
{
    uint32 Mcr = 0U;
    uint8 Index;

    Mcr |= (Config->LowPowerModeEn) ? BCTU_MCR_MDIS_MASK : 0U;
    Mcr |= (Config->GlobalHwTriggersEn) ? 0U : BCTU_MCR_FRZ_MASK;
    Mcr |= BCTU_MCR_GTRGEN_MASK;  /* Triggers globally enabled by default */
    Mcr |= (Config->TriggerNotification != NULL_PTR) ? BCTU_MCR_TRGEN_MASK : 0U;

    for (Index = 0U; Index < FEATURE_BCTU_NUM_ADC; Index++)
    {
        if ((Config->AdcNotifications[Index].NewConvDataNotification != NULL_PTR) || (Config->AdcNotifications[Index].ConvDataOverrunNotification != NULL_PTR))
        {
            Mcr |= (uint32)BCTU_MCR_IEN0_MASK << Index;
        }

        if ((Config->NewDataDmaEnMask & Bctu_GetBitmask(Index)) != 0U)
        {
            Mcr |= (uint32)BCTU_MCR_DMA0_MASK << Index;
        }

        Mcr |= (Config->AdcNotifications[Index].ListLastConversionNotification != NULL_PTR) ? BCTU_MCR_LIST_IEN_MASK : 0U;
    }

    return Mcr;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_GetBitmask
* Description   : Internal helper function to get 32b bitmask with '1' set on input position.
* END**************************************************************************/
static inline uint32 Bctu_GetBitmask(const uint8 Pos)
{
    return (uint32)((uint32)1U << Pos);
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_PrepareReconfigNonBlocking
* Description   : Attempts to prepare on the fly reconfiguration of a trigger config register:
* - disable new conversions \n
* - if there is no running conversion, clear pending triggers and return BCTU_IP_STATUS_SUCCESS \n
* - if there is a running conversion, abort and return BCTU_IP_STATUS_BUSY
* END**************************************************************************/
static inline Bctu_Ip_StatusType Bctu_PrepareReconfigNonBlocking(BCTU_Type * const BctuBasePtr,
                                                          const uint8 TrigIdx)
{
    Bctu_Ip_StatusType Status;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_61();
    /* Disable any new conversions from this trigger.
     * This also stops new conversions from starting when loop flag is enabled. */
    BctuBasePtr->TRGCFG[TrigIdx] &= (~BCTU_TRGCFG_TRIGEN_MASK);

    /* Check if there is any ongoing conversion triggered by current trigger config register. */
    if ((BctuBasePtr->TRGCFG[TrigIdx] & BCTU_TRGCFG_TRG_FLAG_MASK) != 0u)
    {
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_61();
        Status = BCTU_IP_STATUS_BUSY;
    }
    else
    {
        /* Clear pending trigger sources */
        BctuBasePtr->TRGCFG[TrigIdx] |= BCTU_TRGCFG_TRG_FLAG_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_61();

        /* After this point the TRGCFG register can be modified freely. */

        Status = BCTU_IP_STATUS_SUCCESS;
    }

    return Status;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_PrepareReconfigBlocking
* Description   : Prepares on the fly reconfiguration of a trigger configuration
* register: disables new conversions, clears pending triggers and waits for current conversion
* to finish execution, within a provided timeout interval.
* Returns error, if the current active conversion doesn't finish in the provided interval.
*
* END**************************************************************************/
static inline Bctu_Ip_StatusType Bctu_PrepareReconfigBlocking(BCTU_Type * const BctuBasePtr,
                                                       const uint8 TrigIdx)
{
    Bctu_Ip_StatusType Status = BCTU_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(BCTU_IP_TIMEOUT_VAL, BCTU_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(BCTU_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_62();
    /* Disable any new conversions from this trigger. */
    BctuBasePtr->TRGCFG[TrigIdx] &= (~BCTU_TRGCFG_TRIGEN_MASK);

    /* Make sure looping is disabled. */
    BctuBasePtr->TRGCFG[TrigIdx] &= (~ BCTU_TRGCFG_LOOP_MASK);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_62();

    /* Wait until current ongoing conversion (if any) finishes execution or timeout occurs. */
    while (((BctuBasePtr->TRGCFG[TrigIdx] & BCTU_TRGCFG_TRG_FLAG_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, BCTU_IP_TIMEOUT_TYPE);
    }
    if (ElapsedTicks >= TimeoutTicks)
    {
        Status = BCTU_IP_STATUS_TIMEOUT;
    }
    else
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_62();
        /* Clear pending trigger sources */
        BctuBasePtr->TRGCFG[TrigIdx] |= BCTU_TRGCFG_TRG_FLAG_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_62();

        /* After this point the TRGCFG register can be modified freely. */
        Status = BCTU_IP_STATUS_SUCCESS;
    }

    return Status;
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_SetConvListElemWithTag
* Description   : Set an element of adc channel numbers and NEXT_CH_WAIT_ON_TRIG
* in the conversion list.
* Set only a element in list and detecting if odd or even.
*
* END**************************************************************************/
static inline void Bctu_SetConvListElemWithTag(const uint32 Instance,
                                               const uint8 ElemIdx,
                                               const uint8 AdcChanNumbers,
                                               const boolean NextChanWaitOnTrig)
{
    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[Instance];
    uint8 ChanIdx;
    uint32 u32TempListChr = 0u;

    ChanIdx = ElemIdx / 2u;
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_67();
    u32TempListChr = BctuBasePtr->LISTCHR[ChanIdx];

    if ((ElemIdx % 2u) == 0u)
    {
        u32TempListChr &= ~(BCTU_LISTCHR_ADC_CH_y_MASK | BCTU_LISTCHR_LAST_y_MASK | BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_MASK);
        u32TempListChr |= BCTU_LISTCHR_ADC_CH_y(AdcChanNumbers);
        u32TempListChr |= BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y(NextChanWaitOnTrig ? 1U : 0U);
    }
    else
    {
        u32TempListChr &= ~(BCTU_LISTCHR_ADC_CHL_y_plus_1_MASK | BCTU_LISTCHR_LAST_y_plus_1_MASK | BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1_MASK);
        u32TempListChr |= BCTU_LISTCHR_ADC_CHL_y_plus_1(AdcChanNumbers);
        u32TempListChr |= BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1(NextChanWaitOnTrig ? 1U : 0U);
    }

    BctuBasePtr->LISTCHR[ChanIdx] = u32TempListChr;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_67();
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_SetConvListLastElement
* Description   : Marks the element corresponding to the last channel in the array, as last element in the list.
*
* END**************************************************************************/
static inline void Bctu_SetConvListLastElement(const uint32 Instance,
                                               const uint8 ElemIdx)
{
    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[Instance];
    uint8 ChanIdx;

    ChanIdx = ElemIdx / 2u;
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_68();
    if ((ElemIdx % 2u) == 0u)
    {
        BctuBasePtr->LISTCHR[ChanIdx] |= BCTU_LISTCHR_LAST_y_MASK;
    }
    else
    {
        BctuBasePtr->LISTCHR[ChanIdx] |= BCTU_LISTCHR_LAST_y_plus_1_MASK;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_68();
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Bctu_CheckAndCallNotification
 * Description   : Checks if the given channel interrupt was triggered, clears
 *                 the interrupt, checks that the callback is not null and calls it.
 *
 *END*************************************************************************/
static inline void Bctu_CheckAndCallNotification(const uint32 Instance,
                                                 volatile uint32 * Reg,
                                                 const uint32 Mask,
                                                 const uint32 ClrMask,
                                                 void (*Callback)(void))
{
    /* Check if the interrupt was spurious. */
    if ((*Reg & (Mask)) != 0U)
    {
        *Reg = (ClrMask);
        /* Check if the driver was initialized and if the callback is not null. */
        if ((Bctu_Ip_axBctuState[Instance].InitStatus) && (Callback != NULL_PTR))
        {
            Callback();
        }
    }
}

/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Bctu_CheckAndCallFifoNotification
 * Description   : Checks if a given Fifo interrupt was triggered and was not
 * spurrious and call the associated callback.
 *
 *END*********************************************************************************/
static inline void Bctu_CheckAndCallFifoNotification(const uint32 Instance,
                                                     const uint8 FifoIdx)
{
    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[Instance];
    uint32 FifoWatermarkMask;

    if ((BctuBasePtr->FIFOCR & ((uint32)BCTU_FIFOCR_IEN_FIFO1_MASK << FifoIdx)) != 0u)
    {
        /* Call FIFO watermark notification before calling the user callback, to allow the user to read the results from FIFO before clearing the flag.
        Otherwise, if the flag is cleared before reading the results from FIFO, the flag remains 1 and notification is called again. */
        FifoWatermarkMask = (BCTU_FIFOERR_WM_INT_FIFO1_MASK << FifoIdx);
        if ((BctuBasePtr->FIFOERR & FifoWatermarkMask) != 0U)
        {
            /*
            * Check if the driver was initialized, callback is not null and
            * if the interrupt was spurious.
            */
            if ((Bctu_Ip_axBctuState[Instance].InitStatus) &&
                (Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoIdx].WatermarkNotification != NULL_PTR))
            {
                (Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoIdx].WatermarkNotification)();
            }
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_69();
            BctuBasePtr->FIFOERR |= FifoWatermarkMask;
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_69();
        }

        /*
         * The following fields are intertwined e.g. OVR for FIFO1 is
         * next to UNDR for FIFO1 so the *2 is needed to shift into the
         * correct field position.
         */
        Bctu_CheckAndCallNotification(Instance, (volatile uint32 *)&BctuBasePtr->FIFOERR, (uint32)BCTU_FIFOERR_OVR_ERR_FIFO1_MASK << (FifoIdx * 2u),
            (uint32)BCTU_FIFOERR_OVR_ERR_FIFO1_MASK << (FifoIdx * 2u), Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoIdx].OverrunNotification);
        Bctu_CheckAndCallNotification(Instance, (volatile uint32 *)&BctuBasePtr->FIFOERR, (uint32)BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK << (FifoIdx * 2u),
            (uint32)BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK << (FifoIdx * 2u), Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoIdx].UnderrunNotification);
    }
}


/*LOCAL FUNCTION*********************************************************************
 *
 * Function Name : Bctu_FifoSetupDma
 * Description   : Setup the TCD for Dma Channel to use DMA Transfer Result from FIFO.
 *                 Note that FIFO interrupts and DMA should not enables in the same time
 *
 *END*************************************************************************/
#ifdef BCTU_IP_DMA_SUPPORTED
static inline void Bctu_FifoSetupDma(const Bctu_Ip_FifoConfigType * const FifoConfig,
                                     const uint32 FifoAddress)
{
    Dma_Ip_LogicChannelTransferListType LocTransferList[12U];

    if (FifoConfig->FifoDmaEnable)
    {
        /* Prepare for Software TCD Configuration:
        0. Source Address (SADDR): Point to Address of Bctu Fifo Result Data Register.
        1. Source Transfer Size (SSIZE): Number of bytes to read each time.
        2. Source Address Offset (SOFF): Each source read is completed,
        this value will be added to the current source address (Signed).
        3. Destination Address (DADDR): Point to Result Buffter Pointer.
        4. Destination Transfer Size (DSIZE): Number of bytes to write each time.
        5. Destination Address Offset (DOFF): Each destination write is completed,
        this value will be added to the current destination address (Signed).
        6. Minor Loop Size (NBYTES): number of bytes to transfer per service request.
        Number of bytes of enties FIFO that need to transfer.
        7. Major Loop Count (CITER): Number of minor loop in a major loop.
        8. Last Destination Add Adj (DLAST): this value will be added to the destination address
        at the completion of the major iteration count.
        9. Enable Major Interrupt (INTMAJOR): Enable Interrupt If Major count complete
        10. Enable Half Major Interrupt (INTHALF): Enable Interrupt If Major Counter Half-complete
        11. Disable Automatic Hardware Request (DREQ): clear automatically the ERQ bit
            when the current major iteration count reaches 0 To avoid overwriting any new results
            before this gets processed. Will be re-enabled in notification callback.
        */
        LocTransferList[0].Param  = DMA_IP_CH_SET_SOURCE_ADDRESS;
        LocTransferList[0].Value  = FifoAddress + ((uint32)FifoConfig->FifoIndex << 2U); /* Shifted 2 bits is equivalent to multiplying the number by 4 */
        LocTransferList[1].Param  = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        LocTransferList[2].Param  = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        LocTransferList[2].Value  = (uint32)0U;
        LocTransferList[3].Param  = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        LocTransferList[3].Value  = (uint32)(*(FifoConfig->UserFifoBuffer));
        LocTransferList[4].Param  = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        LocTransferList[5].Param  = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        LocTransferList[6].Param  = DMA_IP_CH_SET_MINORLOOP_SIZE;
        LocTransferList[7].Param  = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        LocTransferList[7].Value  = (uint32)(1U);
        LocTransferList[8].Param  = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
        LocTransferList[9].Param  = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
        LocTransferList[9].Value  = 1U; /* TRUE */
        LocTransferList[10].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
        LocTransferList[10].Value = (uint32)0U;
        LocTransferList[11].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
        LocTransferList[11].Value = 1U; /* TRUE */
#ifdef BCTU_IP_FIFO_DMA_RAW_EN
        LocTransferList[1].Value  = (uint32)2U; /* 4 Bytes. It means read all FIFO Result Data (Raw Data) */
        LocTransferList[4].Value  = (uint32)2U; /* 4 Bytes */
        LocTransferList[5].Value  = (uint32)4U;
        LocTransferList[6].Value  = (4U*(FifoConfig->WatermarkValue + 1U));
#else /* BCTU_IP_FIFO_DMA_RAW_EN == OFF */
        LocTransferList[1].Value  = (uint32)1U; /* 2 Bytes. It means read FIFO Data Only */
        LocTransferList[4].Value  = (uint32)1U; /* 2 Bytes */
        LocTransferList[5].Value  = (uint32)2U;
        LocTransferList[6].Value  = (2U*((uint32)FifoConfig->WatermarkValue + 1U));
#endif /* BCTU_IP_FIFO_DMA_RAW_EN */
        LocTransferList[8].Value  = ((uint32)(~((uint32)(LocTransferList[6].Value)) + 1U));
        /* Write TCD Configuration for the channel */
        (void)Dma_Ip_SetLogicChannelTransferList(FifoConfig->FifoDmaChannel, LocTransferList, 12U);
        /* Enable Hardware Request for Dma */
        (void)Dma_Ip_SetLogicChannelCommand(FifoConfig->FifoDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_FifoDmaHandler
* Description   : Handle BCTU DMA FIFO Transfer
* END**************************************************************************/
void Bctu_Ip_FifoDmaHandler(const uint32 Instance,
                            const uint8 FifoIndex)
{
    Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoIndex].WatermarkNotification();
    /* DMA Hardware Request was disabled after the transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
    (void)Dma_Ip_SetLogicChannelCommand(Bctu_Ip_au32BctuFifoDmaChannel[Instance][FifoIndex], DMA_IP_CH_SET_HARDWARE_REQUEST);
}
#endif /* BCTU_IP_DMA_SUPPORTED */

/*FUNCTION**********************************************************************
*
* Function Name : Bctu_Ip_IRQHandler
* Description   : Handles Bctu interrupts
*
* @implements     Bctu_Ip_IRQHandler_Activity
* END**************************************************************************/
void Bctu_Ip_IRQHandler(const uint32 Instance)
{
    uint8 Index;

#if (BCTU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < BCTU_INSTANCE_COUNT);
#endif /* (BCTU_IP_DEV_ERROR_DETECT == STD_ON) */

    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[Instance];
    const boolean CheckList = ((BctuBasePtr->MCR & BCTU_MCR_LIST_IEN_MASK) != 0u) ? TRUE : FALSE;

    /* Check TRGF interrupt */
    if ((BctuBasePtr->MCR & BCTU_MCR_TRGEN_MASK) != 0u)
    {
        Bctu_CheckAndCallNotification(Instance, (volatile uint32 *)&BctuBasePtr->MSR, (uint32)BCTU_MSR_TRGF_MASK,
            (uint32)BCTU_MSR_TRGF_CLR_MASK, Bctu_Ip_axBctuState[Instance].TriggerNotification);
    }

    /* Check interrupts for individual ADC modules */
    for (Index = 0u; Index < FEATURE_BCTU_NUM_ADC; Index++)
    {
        if ((BctuBasePtr->MCR & ((uint32)BCTU_MCR_IEN0_MASK << Index)) != 0u)
        {
            Bctu_CheckAndCallNotification(Instance, (volatile uint32 *)&BctuBasePtr->MSR, (uint32)BCTU_MSR_NDATA0_MASK << Index,
                (uint32)BCTU_MSR_NDATA0_CLR_MASK << Index, Bctu_Ip_axBctuState[Instance].AdcNotifications[Index].NewConvDataNotification);
            Bctu_CheckAndCallNotification(Instance, (volatile uint32 *)&BctuBasePtr->MSR, (uint32)BCTU_MSR_DATAOVR0_MASK << Index,
                (uint32)BCTU_MSR_DATAOVR0_CLR_MASK << Index, Bctu_Ip_axBctuState[Instance].AdcNotifications[Index].ConvDataOverrunNotification);
        }
        if (CheckList)
        {
            Bctu_CheckAndCallNotification(Instance, (volatile uint32 *)&BctuBasePtr->MSR, (uint32)BCTU_MSR_LIST0_Last_MASK << Index,
                (uint32)BCTU_MSR_LIST0_Last_CLR_MASK << Index, Bctu_Ip_axBctuState[Instance].AdcNotifications[Index].ListLastConversionNotification);
        }
    }

    /* Dummy read to guarantee write is complete, when memory write buffering is enabled. */
    (void) BctuBasePtr->MSR;

    /* Check Fifo interrupts */
    for (Index = 0u; Index < BCTU_IP_FIFO_COUNT; Index++)
    {
        Bctu_CheckAndCallFifoNotification(Instance, Index);
    }
}

/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_ConfigAndUpdateFifoNotification
* Description   : Configure Fifo with an array of provided structure and update Fifo
* notification
*
* END*********************************************************************************/
static inline void Bctu_ConfigAndUpdateFifoNotification(const uint32 Instance,
                                                        const Bctu_Ip_FifoConfigType * const FifoConfigArray,
                                                        const uint8 NumFifoConfigs)
{
    uint8 Index;
    uint32 Mask;
    const Bctu_Ip_FifoConfigType * FifoConfig;
    BCTU_Type * const BctuBasePtr = Bctu_Ip_apxBctuBase[Instance];
#ifdef BCTU_IP_DMA_SUPPORTED
    /* Get Start Address of FIFO Data Register */
    const uint32 FifoStartAdd = (uint32)(&BctuBasePtr->FIFO1DR);
#endif /* BCTU_IP_DMA_SUPPORTED */

    for (Index = 0U; Index < NumFifoConfigs; Index++)
    {
        FifoConfig = &(FifoConfigArray[Index]);

        /* Configure FIFO interrupts and DMA */
        Mask = 0U;
        Mask |= FifoConfig->FifoDmaEnable ? (BCTU_FIFOCR_DMA_EN_FIFO1_MASK << FifoConfig->FifoIndex) : 0U;
        Mask |= FifoConfig->bEnNotif ? (BCTU_FIFOCR_IEN_FIFO1_MASK << FifoConfig->FifoIndex) : 0U;
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_65();
        BctuBasePtr->FIFOCR &= ~(Mask);
        BctuBasePtr->FIFOCR |= Mask;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_65();

        /* Set FIFO watermark */
        Bctu_Ip_SetFifoWatermark(Instance, FifoConfig->FifoIndex, FifoConfig->WatermarkValue);
#ifdef BCTU_IP_DMA_SUPPORTED
        Bctu_FifoSetupDma(FifoConfig, FifoStartAdd);
        Bctu_Ip_au32BctuFifoDmaChannel[Instance][Index] = FifoConfig->FifoDmaChannel;
#endif /* BCTU_IP_DMA_SUPPORTED */
        /* Save FIFO notifications to state structure */
        Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoConfig->FifoIndex].WatermarkNotification = FifoConfig->WatermarkNotification;
        Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoConfig->FifoIndex].UnderrunNotification = FifoConfig->UnderrunNotification;
        Bctu_Ip_axBctuState[Instance].FifoNotifications[FifoConfig->FifoIndex].OverrunNotification = FifoConfig->OverrunNotification;
    }
}
#if (FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION == STD_ON)
/*LOCAL FUNCTION**********************************************************************
*
* Function Name : Bctu_GetResolutionScaledResult
* Description   : Update the given result based on the resolution selected by the
*                 given ADC_SAR instance.
*
* END*********************************************************************************/
static inline uint16 Bctu_GetResolutionScaledResult(const uint8 AdcIdx,
                                                    const uint32 RawResult)
{
    static const ADC_Type * const pAdcBaseTable[ADC_INSTANCE_COUNT] = IP_ADC_BASE_PTRS;
    static const uint8 ResolutionArray[] = {14U, 12U, 10U, 8U}; /* maps each register bit value to resolution bit number */
    uint8 Resolution;
    /* ResolutionArray can be used only for 2 bits resolutions. On S32K3 platforms only 2 bits are used so "& 3U" operation is needed */
    uint8 ResolutionBits = (uint8)(((pAdcBaseTable[AdcIdx]->CALBISTREG & ADC_CALBISTREG_RESN_MASK) >> ADC_CALBISTREG_RESN_SHIFT) & 3U); 

    Resolution = ResolutionArray[ResolutionBits];

    /* Assumes 15-bit resolution is read */
    return (uint16)(RawResult >> (15u - Resolution));
}
#endif /* FEATURE_ADC_HAS_BCTU_DYNAMIC_RESOLUTION ==STD_ON */
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
