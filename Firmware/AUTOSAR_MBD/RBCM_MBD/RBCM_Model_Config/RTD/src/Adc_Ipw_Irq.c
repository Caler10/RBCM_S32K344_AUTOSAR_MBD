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
*   @internal
*   @addtogroup adc_ipw Adc Ipw
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external Units
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc.h"
#include "Adc_Ipw.h"
#include "Adc_Ipw_Irq.h"
#include "Adc_Ipw_Types.h"
#include "Mcal.h"

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
#include "DSPSS_Api.h"          /* DSPSS header */
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_IRQ_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define ADC_IPW_SW_MAJOR_VERSION_IRQ_C               5
#define ADC_IPW_SW_MINOR_VERSION_IRQ_C               0
#define ADC_IPW_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_VENDOR_ID)
    #error "Adc_Ipw_Irq.c and Adc.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID)
    #error "Adc_Ipw_Irq.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID_IRQ)
    #error "Adc_Ipw_Irq.c and Adc_Ipw_Irq.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Irq.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION_IRQ) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION_IRQ) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Irq.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Irq.c and Adc_Ipw_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Types.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same AutoSar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

/* Check if Adc_Ipw_Irq.c file and DSPSS_Api.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != DSPSS_VENDOR_ID_API)
    #error "Adc_Ipw_Irq.c and DSPSS_Api.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and DSPSS_Api.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != DSPSS_AR_RELEASE_MAJOR_VERSION_API) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != DSPSS_AR_RELEASE_MINOR_VERSION_API) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != DSPSS_AR_RELEASE_REVISION_VERSION_API) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and DSPSS_Api.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and DSPSS_Api.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != DSPSS_SW_MAJOR_VERSION_API) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != DSPSS_SW_MINOR_VERSION_API) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != DSPSS_SW_PATCH_VERSION_API) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and DSPSS_Api.h are different"
#endif

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || \
     defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) \
    )

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
    ((ADC_HW_TRIGGER_API == STD_ON) && (defined(ADC_ANY_UNIT_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
static inline Std_ReturnType Adc_Ipw_RecordResult(Adc_HwUnitType Unit,
                                                  Adc_GroupType Group,
                                                  Adc_StreamNumSampleType GroupSamples,
                                                  uint8 UserId);
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */                                               
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON))  \
    ) 
static inline Adc_StreamNumSampleType Adc_Ipw_GetNumsCurrentSample(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                                   const Adc_GroupConfigurationType * const GroupPtr,
                                                                   boolean RuntimeChanUpdated);
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
static inline boolean Adc_Ipw_CheckNotification(Adc_GroupType Group,
                                                uint8 UserId);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) || \
     defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || \
     defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) \
    )
static inline void Adc_Ipw_UpdateQueue(Adc_HwUnitType Unit,
                                       uint8 UserId);
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON))  \
    )   
static inline void Adc_Ipw_UpdateGroupState(Adc_HwUnitType Unit,
                                            Adc_GroupType Group,
                                            Adc_StreamNumSampleType GroupSamples,
                                            boolean InjectedFlag,
                                            uint8 UserId);
#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_UpdateTcdDestAddr(const Adc_GroupConfigurationType * GroupPtr,
                                             const uint32 DmaLogicChannel);
static inline void Adc_Ipw_CheckAndEnableDmaHwRequest(const Adc_HwUnitType Unit,
                                                      const Adc_GroupConfigurationType * const GroupPtr,
                                                      const Adc_Ipw_Config * const AdcIpwConfigPtr);
static inline void Adc_Ipw_UpdateNextDestinationAddress(Adc_HwUnitType Unit,
                                                        const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                        const Adc_GroupConfigurationType * GroupPtr);
                                                      
#endif /*ADC_DMA_SUPPORTED*/                                                     
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_EnableDmaHwRequest(Adc_HwUnitType Unit,
                                              const Adc_GroupConfigurationType * GroupPtr,
                                              const Adc_Ipw_Config * const AdcIpwConfigPtr);

#ifdef ADC_ANY_UNIT_DMA_TRANSFER_USED
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static inline Std_ReturnType Adc_Ipw_CheckGroupConvResultDma(const Adc_GroupConfigurationType * GroupPtr,
                                                             uint32 AdcDmaLogicChId,
                                                             uint8 UserId);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* ADC_ANY_UNIT_DMA_TRANSFER_USED */
#if defined(ADC_DMA_ERROR_SUPPORTED)
static inline void Adc_Ipw_DMATransferErrorHandler(const Adc_HwUnitType PhysicalAdcUnit);
#endif /* ADC_DMA_ERROR_SUPPORTED*/

#endif /* ADC_DMA_SUPPORTED */
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
static inline void Adc_Ipw_ConfigureRuntimeSoftwareGroup(const Adc_GroupConfigurationType * GroupPtr,
                                                         Adc_HwUnitType PhysicalHwUnitId,
                                                         boolean InjectedFlag,
                                                         uint8 UserId);
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

static inline void Adc_Ipw_EndSoftwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint8 UserId);
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (ADC_HW_TRIGGER_API == STD_ON)
#if ( \
        ((defined(ADC_ANY_UNIT_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
        defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
        defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
        ((defined(ADC_ANY_UNIT_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
static inline Std_ReturnType Adc_Ipw_ConfigureRuntimeHardwareGroup(Adc_HwUnitType Unit,
                                                                   boolean InjectedFlag,
                                                                   uint8 UserId);
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
#ifdef ADC_DMA_SUPPORTED
static void Adc_Ipw_ResetResultPointer(const Adc_GroupConfigurationType * GroupPtr,
                                        const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                        uint32 AdcDmaLogicChId);
#endif /* ADC_DMA_SUPPORTED */

static inline void Adc_Ipw_DisableHwTriggerSrc(Adc_HwUnitType Unit,
                                               boolean InjectedFlag,
                                               Adc_HwTriggerTimerType TriggerSrc,
                                               uint8 UserId);
#endif /* ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF */

static inline void Adc_Ipw_EndHardwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint8 UserId);
#endif /* (((defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || ... */
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || defined(ADC_ANY_UNIT_DMA_TRANSFER_USED))
static inline void Adc_Ipw_EndNormalChainNotification(const Adc_HwUnitType PhysicalAdcUnit);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */

#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || defined(ADC_ANY_UNIT_DMA_TRANSFER_USED))
static inline void Adc_Ipw_EndInjectedChainNotification(const Adc_HwUnitType PhysicalAdcUnit);
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || ... */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
    ((ADC_HW_TRIGGER_API == STD_ON) && (defined(ADC_ANY_UNIT_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
static inline void Adc_Ipw_ReadData(const Adc_GroupConfigurationType * GroupPtr,
                                    Adc_ValueGroupType * Result,
                                    const Adc_StreamNumSampleType GroupSamples,
                                    const Adc_ChannelIndexType Index,
                                    const uint16 ConvResult);
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
static inline void Adc_Ipw_CallExtraNotification(Adc_GroupType Group,
                                                 uint8 UserId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#endif  /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || ... */

#if (defined(ADC_ANY_UNIT_WDG_ISR_USED))
#if defined(ADC_WDG_SUPPORTED)
static inline void Adc_Ipw_WdgThresholdNotification(const Adc_HwUnitType PhysicalAdcUnit,
                                                    const Adc_ChannelType PhysicalChanId,
                                                    const uint8 Flags);
#endif /* defined(ADC_WDG_SUPPORTED) */
#endif /* defined(ADC_ANY_UNIT_WDG_ISR_USED) */


#if (STD_ON == ADC_IPW_SDADC_IS_USED)

#if ( defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) )

static inline void Adc_Ipw_UpdateGroupStateSdAdc(const uint8 UserId,
                                                 const Adc_HwUnitType Unit,
                                                 const Adc_GroupType Group,
                                                 const Adc_StreamNumSampleType GroupSamples,
                                                 const Adc_HwUnitType PhysicalHwUnitId);
                                                 
static inline void Adc_Ipw_UpdateGroupStateReenableSdAdc(const Adc_HwUnitType PhysicalHwUnitId);

static inline Adc_StreamNumSampleType Adc_Ipw_CalcAvailableSamplesSdAdc(const uint8 UserId,
                                                                        const Adc_HwUnitType Unit);

static inline Adc_StreamNumSampleType Adc_Ipw_RecordResultSdAdc(const uint8 UserId,
                                                                const Adc_HwUnitType Unit,
                                                                const Adc_GroupType Group,
                                                                const Adc_StreamNumSampleType GroupSamples,
                                                                const Adc_HwUnitType PhysicalHwUnitId);

static inline void Adc_Ipw_EndSoftwareConvSdAdc(const uint8 UserId,
                                                const Adc_HwUnitType Unit,
                                                const Adc_GroupType Group);

static inline void Adc_Ipw_FifoFullNotification(const Adc_HwUnitType PhysicalAdcUnit);

#endif /* ( defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) ) */


#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED

static inline Adc_StreamNumSampleType Adc_Ipw_GetDmaTransferSamplesSdadc(const uint8 UserId,
                                                                         const Adc_GroupType Group,
                                                                         const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                                         const Adc_StreamNumSampleType GroupSamples);

static inline void Adc_Ipw_ResetDmaDestinationAddress(const Adc_HwUnitType LogicalHwUnitId,
                                                      const Adc_GroupConfigurationType * const GroupPtr,
                                                      const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                      const uint32 AdcDmaLogicChId,
                                                      const uint32 ResultsBufferrAddress);

#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

static inline void Adc_Ipw_ResetDmaSourceAddress(const Adc_HwUnitType LogicalHwUnitId,
                                                 const Adc_HwUnitType PhysicalHwUnitId,
                                                 const Adc_GroupConfigurationType * const GroupPtr,
                                                 const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                 const uint32 AdcDmaLogicChId);

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */

#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */

#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || \
     defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) \
    )

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
    ((ADC_HW_TRIGGER_API == STD_ON) && (defined(ADC_ANY_UNIT_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief          This function check if channel is enabled/disabled.
* @details        This function check if channel is enabled/disabled.
*
* @param[in]      LogicalHwUnitId   Hardware index in the structure.
* @param[in]      GroupId           Group index.
* @param[in]      ChIndex           Channel index of group.
* @param[in]      UserId            Current UserId.
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              Channel is enabled.
* @retval         E_NOT_OK          Channel is disabled.
*
*/
static inline Std_ReturnType Adc_Ipw_IsChannelEnable(Adc_HwUnitType LogicalHwUnitId,
                                                     Adc_GroupType GroupId,
                                                     Adc_ChannelType ChIndex,
                                                     uint8 UserId)
{
    uint32 ChannelEnBit = 0UL;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    const uint32 PhysicalChanId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->ChannelConfigsPtr[ChIndex].ChanIndex;

    if (PhysicalChanId < 32u)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[0u] >> PhysicalChanId) & 1UL;
    }
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 1u)
    else if (PhysicalChanId < 64u)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[1u] >> (PhysicalChanId % 32u)) & 1UL;
    }
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 1u) */
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 2u)
    else if (PhysicalChanId < 96u)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[2u] >> (PhysicalChanId % 32u)) & 1UL;
    }
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 2u) */
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 3u)
    #error "Adc IPW ADC_IPW_NUM_OF_GROUP_CHN out of range."
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 3u) */

    if (1UL == ChannelEnBit)
    {
        ReturnValue = (Std_ReturnType)E_OK;
    }

    return ReturnValue;
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

/**
* @brief          This function gets the conversion result and save to buffer
* @details        This function gets the conversion result and save to buffer
*
* @param[in]      Unit              The used hardware unit
* @param[in]      Group             The group to be converted
* @param[in]      GroupSamples      Number of group samples
* @param[in]      UserId            Current UserId
*
* @return         Std_ReturnType    Checking value
* @retval         E_OK              Result is satisfied limit checking function
* @retval         E_NOT_OK          Result is NOT satisfied limit checking function
*
* @implements Adc_Ipw_RecordResult_Activity
*/
static inline Std_ReturnType Adc_Ipw_RecordResult(Adc_HwUnitType Unit,
                                                  Adc_GroupType Group,
                                                  Adc_StreamNumSampleType GroupSamples,
                                                  uint8 UserId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    Adc_ChannelIndexType Ch = 0U;
    Adc_ChannelType ChIndex = 0U;
    Adc_ValueGroupType * Result = NULL_PTR;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_GroupDefType * Channel;
    const Adc_Sar_Ip_ConfigType * AdcPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_Sar_Ip_ChanResultType AdcResult;
    Adc_TriggerSourceType GrTriggerSrc = GroupPtr->TriggerSource;

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_GroupType GroupId;
    Std_ReturnType ChannelEnable;
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Flag to set if ADC results are in the range selected */
    boolean Flag;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    Adc_ChannelIndexType ChannelCount;

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get channel count at runtime */
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
    Channel = &(Adc_axRuntimeGroupChannel[Group].ChannelPtr[0u]);
#else
    /* Get channel count from configuration */
    ChannelCount = GroupPtr->AssignedChannelCount;
    Channel = &(GroupPtr->AssignmentPtr[0u]);
#endif

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    /* Get the result buffer pointer */
    if (FALSE == GroupPtr->StreamResultGroupMultiSets)
    {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        Result = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]);
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    }
    else
    {
        Result = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex * ChannelCount]);
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

    for (Ch = 0U; Ch < ChannelCount; Ch++)
    {
        ChIndex = Channel[Ch];

        /* Get the result */
        if (ADC_TRIGG_SRC_SW == GrTriggerSrc)
        {
            Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), (Adc_Sar_Ip_ConvChainType)GroupPtr->Type, &AdcResult);
        }
#if (STD_ON == ADC_HW_TRIGGER_API)
        else
        {
            if (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType) ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
            {
                /* Data conversion comes from CTU Trigger */
                Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), ADC_SAR_IP_CONV_CHAIN_CTU, &AdcResult);
            }
            else
            {
                /* Data conversion comes from Normal and Injected Trigger */
                Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), (Adc_Sar_Ip_ConvChainType)GroupPtr->Type, &AdcResult);
            }
        }
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /* Get index of the group with AdcEnableChDisableChGroup enabled */
        GroupId = (Adc_GroupType)GroupPtr->EnableChDisableChGroupIndex;
        /* Check if group have AdcEnableChDisableChGroup enabled */
        if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupId)
        {
            /* Check if ChIndex is enabled */
            ChannelEnable = Adc_Ipw_IsChannelEnable(Unit, GroupId, ChIndex, UserId);
        }
        else
        {
            /* ChIndex is always enabled when AdcEnableChDisableChGroup disabled */
            ChannelEnable = E_OK;
        }
        if ((Std_ReturnType)E_OK == ChannelEnable)
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
        {
            /* If channel is enabled, check valid and result bit */
            if (TRUE == AdcResult.ValidFlag)
            {
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
                /* Checks if conversion values are in the configured range */
                if (
                        (TRUE == GroupPtr->AdcGroupLimitcheck)
#if (ADC_SETCHANNEL_API == STD_ON)
                        || (TRUE == Adc_axRuntimeGroupChannel[Group].AdcRuntimeGroupLimitcheck)
#endif /* ADC_SETCHANNEL_API == STD_ON */
                   )
                {
                    Flag = Adc_Ipw_CheckConversionValuesInRange(AdcResult.ConvData, Unit, ChIndex, UserId);
                    if (TRUE == Flag)
                    {
                        Adc_Ipw_ReadData(GroupPtr, Result, GroupSamples, Ch, AdcResult.ConvData);
                    }
                    else
                    {
                        /* SWS_Adc_00448 */
                        /* Return an error */
                        Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
                        Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;

                        ReturnValue = (Std_ReturnType)E_NOT_OK;
                    }
                }
                else /* In case of AdcGroupLimitcheck = FALSE */
                {
                    Adc_Ipw_ReadData(GroupPtr, Result, GroupSamples, Ch, AdcResult.ConvData);
                    Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
                }
#else
                Adc_Ipw_ReadData(GroupPtr, Result, GroupSamples, Ch, AdcResult.ConvData);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
            }
            else /* In case of result is not true for this convert type*/
            {
                ReturnValue = (Std_ReturnType)E_NOT_OK;
            }

            if ((Std_ReturnType)E_NOT_OK == ReturnValue)
            {
                break;
            }
        }
    }
    return ReturnValue;
}
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */      
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON))  \
    ) 
static inline Adc_StreamNumSampleType Adc_Ipw_GetNumsCurrentSample(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                                   const Adc_GroupConfigurationType * const GroupPtr,
                                                                   boolean RuntimeChanUpdated)
{
    Adc_StreamNumSampleType NumsCurrentSample = 0U;
    const Adc_GroupType Group = GroupPtr->GroupId;
#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    uint32 CurrentIter = 0U;
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const Adc_StreamNumSampleType GroupSamples = GroupPtr->NumSamples;
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    const uint32 AdcCountingDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[LogicalHwUnitId];

    if (TRUE == GroupPtr->AdcOptimizeDmaStream)
    {
        if (1U < (GroupPtr->AssignedChannelCount))
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcCountingDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &CurrentIter);
        }
        else
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &CurrentIter);
        }

        /* This condition only occurs at half interrupt */
        if (CurrentIter != GroupSamples)
        {
            /* Re-calculate NumsCurrentSample because CITER decrements its value from GroupSamples to 1 */
            NumsCurrentSample = GroupSamples - (Adc_StreamNumSampleType)CurrentIter;
        }
        else
        {
            /* When major loop completed, CITER roll back to be equal to GroupSamples so no need to re-calculate */
            NumsCurrentSample = (Adc_StreamNumSampleType)CurrentIter;
        }
        Adc_axGroupStatus[Group].ResultIndex = NumsCurrentSample;
    }
    else
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */
    {
        if (
            (ADC_TRIGG_SRC_SW != GroupPtr->TriggerSource)
#if (ADC_SETCHANNEL_API == STD_ON)
             && (FALSE == RuntimeChanUpdated)
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
           )
        {
            /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
            Adc_axGroupStatus[Group].ResultIndex++;
        }
        NumsCurrentSample = Adc_axGroupStatus[Group].ResultIndex;
    }

    /* Avoid Compiler Warning */
    (void) AdcIpwConfigPtr;
    (void) RuntimeChanUpdated;

    return NumsCurrentSample;
}
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
* @brief          This function checks group notification
* @details        This function checks group notification
*
* @param[in]      Group             The group to be converted
* @param[in]      UserId            Current UserId
*
* @return         boolean      Checking result
* @retval         TRUE:        Notification call is available
* @retval         FALSE:       Notification call is NOT available
*
*/
static inline boolean Adc_Ipw_CheckNotification(Adc_GroupType Group,
                                                uint8 UserId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    boolean CallNotification =  FALSE;

    /* SWS_Adc_00080, SWS_Adc_00083 */
    if ((ADC_NOTIFICATION_ENABLED == Adc_axGroupStatus[Group].Notification) && \
        (NULL_PTR != Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].Notification)
       )
    {
        CallNotification =  TRUE;
    }
    return CallNotification;
}
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) || \
     defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || \
     defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) \
    )
/**
* @brief          This function updates queue
* @details        This function updates queue elements after a conversion
*                 and start conversion if requests are still available in queue
*
* @param[in]      Unit              The ADC hardware unit
* @param[in]      UserId            Current UserId
*
* @return         void
*
*/
static inline void Adc_Ipw_UpdateQueue(Adc_HwUnitType Unit,
                                       uint8 UserId)
{
#if (ADC_ENABLE_QUEUING == STD_ON)
    /* Remove current request element in queue */
    Adc_Ipw_RemoveFromQueue(Unit, 0U);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    if (Adc_axUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
        /* Start conversion if request elements are still available in queue */
        Adc_Ipw_StartNormalConversion(Unit, UserId);
    }
#endif
#else
    /* No element will be present in the queue */
    Adc_axUnitStatus[Unit].SwNormalQueueIndex= (Adc_QueueIndexType)0;
#endif /* ADC_ENABLE_QUEUING == STD_ON */
    (void)UserId;
}
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON))  \
    )  
/**
* @brief          This function update state of software conversion according to AutoSar diagrams
* @details        This function update state of software conversion according to AutoSar diagrams
*
* @param[in]      Unit              ADC hardware unit
* @param[in]      Group             ADC group number
* @param[in]      GroupSamples      Number of samples per channel in streaming access mode
* @param[in]      InjectedFlag      Normal or injected conversion
* @param[in]      UserId            Current UserId
*
* @return         void
*
*/
static inline void Adc_Ipw_UpdateGroupState(Adc_HwUnitType Unit,
                                            Adc_GroupType Group,
                                            Adc_StreamNumSampleType GroupSamples,
                                            boolean InjectedFlag,
                                            uint8 UserId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_StreamNumSampleType CurrentSampleCount = 0U;
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
#ifdef ADC_DMA_SUPPORTED
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
#endif /* ADC_DMA_SUPPORTED */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    boolean  CallNotification = FALSE;
#endif
    boolean StreamBuffLinear = FALSE;

    CurrentSampleCount = Adc_Ipw_GetNumsCurrentSample(AdcIpwConfigPtr, GroupPtr, FALSE);
    /* At least once the group was converted */
    Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
    {
        /* SWS_Adc_00224 */
        Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
    }

    /* If buffer is full of samples, wrap to 0 */
    if (GroupSamples <= CurrentSampleCount)
    {
        /* Change to stream complete according to AUTOSAR diagram */
        /* SWS_Adc_00325 */
        Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

        if ((ADC_STREAM_BUFFER_LINEAR == GroupPtr->BufferMode) && \
           (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
          )
        {
            StreamBuffLinear = TRUE;
#ifdef ADC_DMA_SUPPORTED
            /* Not required to check AdcWithoutDma == FALSE, because AdcWithoutDma is only supported for SW normal triggered which cannot be ADC_ACCESS_MODE_STREAMING when DMA transfer selected for HW unit */
            if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
                /* Disable ADC DMA Request */
                Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
                Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
            }
#endif /* ADC_DMA_SUPPORTED */

            if (Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, TRUE, FALSE) == ADC_SAR_IP_STATUS_SUCCESS)
            {
                Adc_Ipw_ClearValidBit(Unit, Group, UserId);
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
                Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);

                /* Update queue and execute new start conversion request from queue if available */
                Adc_Ipw_UpdateQueue(Unit, UserId);

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
                /* Check user notification function and execute if available */
                CallNotification = Adc_Ipw_CheckNotification(Group, UserId);

                if (TRUE == CallNotification)
                {
                    /* SWS_Adc_00140, SWS_Adc_00060 */
                    GroupPtr->Notification();
                }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
            }
        }
        else
        {
            Adc_axGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_DMA_SUPPORTED
            if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
                if (((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable) && (1U == GroupPtr->AssignedChannelCount))
                {
                    LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                    LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                }
            }
#endif /* ADC_DMA_SUPPORTED */
        }
    }

    if (FALSE == StreamBuffLinear)
    {
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        CallNotification = Adc_Ipw_CheckNotification(Group, UserId);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

        if (ADC_CONV_MODE_ONESHOT == GroupPtr->Mode)
        {
            /* SWS_Adc_00325 */
            Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

            if (FALSE == InjectedFlag)
            {
                /* Disable Normal Interrupt Mask */
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
                Adc_Ipw_UpdateQueue(Unit, UserId);
            }
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
            else
            {
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED))
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */
                /* No element will be present in the sw inj queue */
                Adc_axUnitStatus[Unit].SwInjectedQueueIndex = 0U;
            }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
        }

#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        if (TRUE == InjectedFlag)
        {
            /* Clear injected end of chain interrupt flag */
            Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        }
        else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
        {
            /* Clear normal end of chain interrupt flag */
            Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
        }

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        if (TRUE == CallNotification)
        {
            /* Call user notification (SWS_Adc_00140, SWS_Adc_00060) */
            GroupPtr->Notification();
        }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
#ifdef ADC_DMA_SUPPORTED
        /* Checks and enables DMA Hardware request */
        Adc_Ipw_CheckAndEnableDmaHwRequest(Unit, GroupPtr, AdcIpwConfigPtr);
#endif /* ADC_DMA_SUPPORTED */
    }
}

#ifdef ADC_DMA_SUPPORTED
/**
* @brief        This function updates TCD Destination Address of Next Result Buffer for Streaming Group
* @details      This function is called after one sample completes the conversion. The next address of
*               Result Buffer should be updated if number of channel in the Group greater than one.
*
* @param[in]    GroupPtr           The pointer to the group configuration structure.
* @param[in]    DmaLogicChannel  The Logical Dma Channel Id that was configured.
*
* @return       void
*
*/
static inline void Adc_Ipw_UpdateTcdDestAddr(const Adc_GroupConfigurationType * GroupPtr,
                                             const uint32 DmaLogicChannel)
{
    uint8 Index;
    const Adc_StreamNumSampleType GroupNumSample = GroupPtr->NumSamples;
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_ChannelIndexType ChannelCount = GroupPtr->AssignedChannelCount;
    uint32 DestAddOff;
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];

    if ( \
            (1U < ChannelCount)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
         && (FALSE == GroupPtr->AdcOptimizeDmaStream)
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
       )
    {
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        if (FALSE == GroupPtr->StreamResultGroupMultiSets)
        {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
            DestAddOff = (uint32)Adc_axGroupStatus[Group].ResultIndex << 1UL;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        }
        else
        {
            DestAddOff = ((uint32)Adc_axGroupStatus[Group].ResultIndex * ChannelCount) << 1UL;
        }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

        for (Index = 0; Index < ChannelCount; Index++)
        {
            LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
            if (FALSE == GroupPtr->StreamResultGroupMultiSets)
            {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Index * GroupNumSample])) + DestAddOff;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
            }
            else
            {
                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Index])) + DestAddOff;
            }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

            /* Write TCD Configuration for each channel */
            (void)Dma_Ip_SetLogicChannelScatterGatherList(DmaLogicChannel, Index, LocTransferList, 1U);
        }
        /* Write the first Software TCD to the Hardware. The next one will be loaded automaticaly by Scatter/Gather Programming */
        (void)Dma_Ip_SetLogicChannelScatterGatherConfig(DmaLogicChannel, 0U);
    }
}

/**
* @brief        This function checks and enables DMA Hardware request
* @details      This function checks and enables DMA Hardware request for other cases of (ONESHOT + SINGLE) which was disabled automatically (by enabling DREQ) at the end of DMA major loop.
*
* @param[in]    Unit                 Physical HW unit index.
* @param[in]    GroupPtr             Configuration pointer of group.
* @param[in]    AdcIpwConfigPtr      Configuration pointer contains DMA channel ID.
*
* @return       void
*
*/
static inline void Adc_Ipw_CheckAndEnableDmaHwRequest(const Adc_HwUnitType Unit,
                                                      const Adc_GroupConfigurationType * const GroupPtr,
                                                      const Adc_Ipw_Config * const AdcIpwConfigPtr)
{
    const uint32 AdcDmaLogicChId = (uint32) AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];

    if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
    {
        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            /* Update the Next Destination Address for Streaming Group. For Software (Single Group + One shot mode), the DMA will be re-configured by Adc_StartGroupConversion */
            if (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
            {
                Adc_Ipw_UpdateTcdDestAddr(GroupPtr, AdcDmaLogicChId);
            }
            /* Don't re-enable DMA for Software trigger one shot mode */
            if ( (ADC_CONV_MODE_ONESHOT != GroupPtr->Mode) || (ADC_ACCESS_MODE_SINGLE != GroupPtr->AccessMode) )
            {
                Adc_Ipw_EnableDmaHwRequest(Unit, GroupPtr, AdcIpwConfigPtr);
            }
        }
    }
}
static inline void Adc_Ipw_UpdateNextDestinationAddress(Adc_HwUnitType Unit,
                                                        const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                        const Adc_GroupConfigurationType * GroupPtr)
{
    const uint32 AdcDmaLogicChId = (uint32) AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];

    if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
    {
        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            /* Update the Next Destination Address for Streaming Group and Hardware Group */
            Adc_Ipw_UpdateTcdDestAddr(GroupPtr, AdcDmaLogicChId);
            Adc_Ipw_EnableDmaHwRequest(Unit, GroupPtr, AdcIpwConfigPtr);
        }
    }
}
#endif /*ADC_DMA_SUPPORTED */
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#ifdef ADC_DMA_SUPPORTED

/**
* @brief        This function enables DMA Hardware request
* @details      This function enables DMA Hardware request which was disabled automatically (by enabling DREQ) at the end of DMA major loop.
*
* @param[in]    Unit                  Physical HW unit index.
* @param[in]    GroupPtr             Configuration pointer of group.
* @param[in]    AdcIpwConfigPtr      Configuration pointer contains DMA channel ID.
*
* @return       void
*
*/
static inline void Adc_Ipw_EnableDmaHwRequest(Adc_HwUnitType Unit,
                                              const Adc_GroupConfigurationType * GroupPtr,
                                              const Adc_Ipw_Config * const AdcIpwConfigPtr)
{
    uint32 AdcDmaLogicChId = (uint32) AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    Adc_GroupType Group = GroupPtr->GroupId;

    if (TRUE == GroupPtr->AdcOptimizeDmaStream)
    {
        if ((ADC_STREAM_COMPLETED == Adc_axGroupStatus[Group].Conversion) && (1U == (GroupPtr->AssignedChannelCount)))
        {
            /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
            (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
        }
    }
    else
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
    {
        /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
        (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
        /* Avoid Compiler Warning */
        (void)GroupPtr;
    }
}

#ifdef ADC_ANY_UNIT_DMA_TRANSFER_USED
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          This function checks the conversion result when Limit Check and DMA are enabled.
* @details        This function checks the conversion result when Limit Check and DMA are enabled.
*
* @param[in]      GroupPtr         The Adc Group Pointer.
* @param[in]      AdcDmaLogicChId  Dma logical channel
* @param[in]      UserId           Current UserId
*
* @return         Std_ReturnType
*
*/
static inline Std_ReturnType Adc_Ipw_CheckGroupConvResultDma(const Adc_GroupConfigurationType * GroupPtr,
                                                             uint32 AdcDmaLogicChId,
                                                             uint8 UserId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_HwUnitType Unit = GroupPtr->AdcLogicalUnitId;
    const uint8 AvailableResolutions[4U] = ADC_IPW_AVAILABLE_RESOLUTIONS;
    Adc_ValueGroupType * ResultData = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]);
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    Adc_ValueGroupType LocalValue = ResultData[0];

    if (TRUE == GroupPtr->AdcGroupLimitcheck)
    {
        if (FALSE == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->BypassResolution)
        {
            /* Shift the result right to have the correct resolution for limit checking. */
            LocalValue >>= (ADC_SAR_IP_RESULT_RESOLUTION - AvailableResolutions[(uint8)(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->AdcResolution)]);
        }
        /* Assumption: because of SWS_Adc_00451, the number of channels configured for a group when limit checking is disabled, must be one.*/
        if (FALSE == Adc_Ipw_CheckConversionValuesInRange(LocalValue, Unit, GroupPtr->AssignmentPtr[0], UserId))
        {
            /* SWS_Adc_00448 */
            /* Return an error */
            Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
            Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
            ResultData[0] = 0U;
            ReturnValue = (Std_ReturnType) E_NOT_OK;
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* If the Result Conversion is out of range, need to reset Destination Address to previous Buffer Address. */
                /* Because the Destination Offset for Streaming Group that has one channel configured be 2U to reducing additional in the callback. */
                if (GroupPtr->AccessMode == ADC_ACCESS_MODE_STREAMING)
                {
                    LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                    LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                }
                /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
                (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
            }
        }
        else
        {
            Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
        }
    }

    return ReturnValue;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* ADC_ANY_UNIT_DMA_TRANSFER_USED */

#endif /* ADC_DMA_SUPPORTED */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
     ((defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief          This function reconfigures runtime updated channels
* @details        This function reconfigures runtime updated channels for software trigger groups
*
* @param[in]      GroupPtr                  Group configuration pointer
* @param[in]      PhysicalHwUnitId             Adc Physical Unit Id
* @param[in]      InjectedFlag              Injected (TRUE) or Normal (FALSE) group
* @param[in]      UserId                    Current UserId
*
* @return         void.
*/
static inline void Adc_Ipw_ConfigureRuntimeSoftwareGroup(const Adc_GroupConfigurationType * GroupPtr,
                                                         Adc_HwUnitType PhysicalHwUnitId,
                                                         boolean InjectedFlag,
                                                         uint8 UserId)
{
    Adc_Sar_Ip_ConvChainType ChainType = ADC_SAR_IP_CONV_CHAIN_NORMAL;
    uint32 EndChainFlag = ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN;
    Adc_GroupType Group = GroupPtr->GroupId;
    Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;

    if (ADC_SAR_IP_STATUS_SUCCESS == Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, TRUE, FALSE))
    {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        if (TRUE == InjectedFlag)
        {
            ChainType = ADC_SAR_IP_CONV_CHAIN_INJECTED;
            EndChainFlag = ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN;
        }
#else
        (void)InjectedFlag;
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

        Adc_axGroupStatus[Group].ResultIndex = 0U;
        /* Get run-time configuration and update normal conversion mask registers */
        Adc_Ipw_GetCmrRegister(LogicalHwUnitId, Group, &CmrMask, UserId);
        Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ChainType);
        /* Clear pending ISR request which might occur with continuous groups */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, EndChainFlag);
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated = FALSE;

        /* Restart group conversion */
        Adc_Sar_Ip_StartConversion(PhysicalHwUnitId, ChainType);
    }
}
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

/**
* @brief          This function handles the normal conversion ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit                the current HW Unit.
* @param[in]      InjectedFlag        Normal or Injected conversion.
* @param[in]      UserId              Current UserId
*
* @return         void
*
* @api
* @implements     Adc_Ipw_EndSoftwareConv_Activity
*/
static inline void Adc_Ipw_EndSoftwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint8 UserId)
{
    Adc_GroupType GroupIndex = 0U;
    Adc_GroupType Group = 0U;
    /* Streaming num samples should be at least 1U */
    Adc_StreamNumSampleType GroupSamples;
    Std_ReturnType CheckingStatus = (Std_ReturnType) E_OK;
#if defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON)
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
#endif /* defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON) */
#ifdef ADC_DMA_SUPPORTED
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Std_ReturnType LimitCheckDmaStatus = (Std_ReturnType) E_OK;
    const uint32 AdcDmaLogicChId = (uint32) Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
#endif /*ADC_DMA_SUPPORTED*/
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Get the group to be converted */
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
    if (TRUE == InjectedFlag)
    {
        Group = Adc_axUnitStatus[Unit].SwInjectedQueue[0];
    }
    else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
    {
        Group = Adc_axUnitStatus[Unit].SwNormalQueue[0];
    }

    GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    GroupSamples = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].NumSamples;

#if defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON)
    GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
#endif /* defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Check if channel was updated before interrupt of previous conversions */
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        Adc_Ipw_ConfigureRuntimeSoftwareGroup(GroupPtr, PhysicalHwUnitId, InjectedFlag, UserId);
    }
    else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    {
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA != Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
#endif /*ADC_DMA_SUPPORTED*/
            /* Get the conversion result and save to buffer */
            CheckingStatus = Adc_Ipw_RecordResult(Unit, Group, GroupSamples, UserId);
#ifdef ADC_DMA_SUPPORTED
            Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
            Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        else
        {
            LimitCheckDmaStatus = Adc_Ipw_CheckGroupConvResultDma(GroupPtr, AdcDmaLogicChId, UserId);
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /*ADC_DMA_SUPPORTED*/

#if (defined(ADC_DMA_SUPPORTED) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
        if ((Std_ReturnType)E_OK == LimitCheckDmaStatus)
#endif /* defined(ADC_DMA_SUPPORTED) && (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
            /* Call extra notification (if available) before updating registers (SWS_Adc_00060) */
            Adc_Ipw_CallExtraNotification(Group, UserId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
            if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
            {
                Adc_Ipw_ConfigureRuntimeSoftwareGroup(GroupPtr, PhysicalHwUnitId, InjectedFlag, UserId);
            }
            else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
            {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
                if (TRUE == InjectedFlag)
                {
    #ifdef ADC_DMA_SUPPORTED
        #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
                    if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
                    {
                        if (Adc_axUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
                        {
                            /* Restart normal conversion */
                            Adc_Ipw_StartNormalConversion(Unit, UserId);
                        }
                    }
        #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
    #endif /* ADC_DMA_SUPPORTED */
                    if ((Std_ReturnType)E_NOT_OK == CheckingStatus)
                    {
                        Adc_axGroupStatus[Group].ResultIndex = 0U;
                    }
                }
                else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
                {
                    if ((Std_ReturnType)E_NOT_OK == CheckingStatus)
                    {
                        if (ADC_CONV_MODE_ONESHOT == Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].Mode)
                        {
                            /* Disable end of chain interrupt mask */
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
                            Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
                        }

                        /* Clear normal interrupt flag */
                        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
                    }
#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
                    if (FALSE == GroupPtr->AdcOptimizeDmaStream)
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */
                    {
                        if ((Std_ReturnType)E_OK == CheckingStatus)
                        {
                            /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
                            Adc_axGroupStatus[Group].ResultIndex++;
                        }
                    }
                }
            }
            if ((Std_ReturnType)E_OK == CheckingStatus)
            {
                /* Update group state and continue conversion */
                Adc_Ipw_UpdateGroupState(Unit, Group, GroupSamples, InjectedFlag, UserId);
            }
        }
    }
}
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (ADC_HW_TRIGGER_API == STD_ON)
#if ( \
        ((defined(ADC_ANY_UNIT_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
        defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
        defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
        ((defined(ADC_ANY_UNIT_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief          This function configs command lists for trigger unit
*                 channel in adc unit when a hardware conversion ends
*
* @details        This function configs command lists for trigger unit
*                 channel in adc unit when a hardware conversion ends
*
* @param[in]      Unit                  The current HW Unit.
* @param[in]      InjectedFlag          Normal or Injected conversion.
* @param[in]      UserId                Current UserId
*
* @return         Std_ReturnType
*
* @api
* @implements     Adc_Ipw_ConfigureRuntimeHardwareGroup_Activity
*/
static inline Std_ReturnType Adc_Ipw_ConfigureRuntimeHardwareGroup(Adc_HwUnitType Unit,
                                                                   boolean InjectedFlag,
                                                                   uint8 UserId)
{
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    uint8 ChanList[ADC_MAX_CHANNEL_PER_HW_UNIT];
    Adc_ChannelIndexType ChannelCount;
    Bctu_Ip_TrigConfigType TrigConfig;
    Bctu_Ip_StatusType BctuStatus;
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    /* Mapping AdcPhysicalID to CtuPhysicalId */
    const uint8 AdcIdToCtuId[ADC_IPW_MAX_HW_UNITS] = ADC_IPW_ADC_TO_CTU_MAPPING_ARRAY;
    const uint8 CtuPhysicalId = AdcIdToCtuId[PhysicalHwUnitId];
    /* Set AdcIndex corresponding to bitfield in BCTU. eg: ADC0-2: BCTU0 and ADC3-6: BCTU1 */
    const uint8 AdcIndexOffset[ADC_IPW_CTU_MAX_HW_UNITS] = ADC_IPW_ADC_INDEX_OFFSET_BITFIELD_ARRAY;
    const uint8 AdcIndexForCtu = PhysicalHwUnitId - AdcIndexOffset[CtuPhysicalId];
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */

    /* Get the group to be converted */
    Adc_GroupType Group = Adc_axUnitStatus[Unit].OngoingHwGroup;
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);

#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_CTU_AVAILABLE == STD_ON) || (ADC_IPW_BCTU_AVAILABLE == STD_ON)))
    if (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        Bctu_Ip_SetGlobalTriggerEn(CtuPhysicalId, FALSE);

        /* Get index of List channel register */
        TrigConfig.TrigIndex       = (uint8)GroupPtr->HwTriggerSource;
        TrigConfig.LoopEn         = FALSE;
        TrigConfig.DataDest       = BCTU_IP_DATA_DEST_ADC_DATA_REG;
        TrigConfig.HwTriggersEn   = TRUE;
        TrigConfig.AdcTargetMask = (1u << AdcIndexForCtu);
        TrigConfig.TrigType = BCTU_IP_TRIG_TYPE_LIST;
        /* Use list address start index allocated for the HW unit */
        TrigConfig.AdcChanOrListStart = AdcIpwConfigPtr->CtuListStartIndex[Unit];

        BctuStatus = Bctu_Ip_ConfigTrigger(CtuPhysicalId, &TrigConfig);
        if (BctuStatus == BCTU_IP_STATUS_SUCCESS)
        {
            ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;

            Adc_Ipw_GetCtuChanList(ChanList, (uint8)ChannelCount, Group, Unit, UserId);

            Bctu_Ip_ConfigChanListSimple(CtuPhysicalId, AdcIpwConfigPtr->CtuListStartIndex[Unit], ChanList, ChannelCount);

            Bctu_Ip_SetGlobalTriggerEn(CtuPhysicalId, TRUE);
        }
        else
        {
            ReturnStatus = (Std_ReturnType)E_NOT_OK;
        }
#else /* ADC_IPW_BCTU_AVAILABLE */
        ReturnStatus = Adc_Ipw_CtuTriggerEnable(Group, GroupPtr->HwTriggerSource, TRUE, TRUE, UserId);
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
    }
    else
#endif /* (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_CTU_AVAILABLE == STD_ON) || (ADC_IPW_BCTU_AVAILABLE == STD_ON)) */
    {
        Adc_Ipw_GetCmrRegister(Unit, Group, &CmrMask, UserId);
        if (TRUE == InjectedFlag)
        {
            Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_INJECTED);
        }
    #if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        else
        {
            Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_NORMAL);
        }
    #endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
    }

    if (ReturnStatus == (Std_ReturnType)E_OK)
    {
        Adc_axGroupStatus[Group].ResultIndex = 0U;
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated =  FALSE;
    }

    return ReturnStatus;
}
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
#ifdef ADC_DMA_SUPPORTED
static void Adc_Ipw_ResetResultPointer(const Adc_GroupConfigurationType * GroupPtr,
                                        const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                        uint32 AdcDmaLogicChId)
{
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_HwUnitType Unit = GroupPtr->AdcLogicalUnitId;
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
    const Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    /* Check the DMA of ADC instance */
    if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
    {
        if (((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable) && (1U == GroupPtr->AssignedChannelCount))
        {
            LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
            LocTransferList[0].Value = (Adc_Sar_Ip_uintPtrType)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
#if FEATURE_ADC_HAS_APPLICATION_EXTENSION
            if (PhysicalHwUnitId >= ADC_INSTANCE_COUNT)
            {
                LocTransferList[0].Value -= ADC_SAR_IP_APPLICATION_EXTENSION_BASE_ADDRESS;
            }
#endif /* FEATURE_ADC_HAS_APPLICATION_EXTENSION */
            /* Write TCD Configuration for the channel */
            (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
        }
    }
}
#endif /* ADC_DMA_SUPPORTED */
/**
* @brief          This function disable trigger source and notifications.
* @details        This function disable trigger source and notifications.
*
* @param[in]      Unit                 The current HW Unit.
* @param[in]      InjectedFlag         Normal or Injected conversion.
* @param[in]      TriggerSrc           Hardware trigger source
* @param[in]      UserId               Current UserId
*
* @return         void
*
* @api
* @implements     Adc_Ipw_DisableHwTriggerSrc_Activity
*/
static inline void Adc_Ipw_DisableHwTriggerSrc(Adc_HwUnitType Unit,
                                               boolean InjectedFlag,
                                               Adc_HwTriggerTimerType TriggerSrc,
                                               uint8 UserId)
{
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    /* Mapping AdcPhysicalID to CtuPhysicalId */
    const uint8 AdcIdToCtuId[ADC_IPW_MAX_HW_UNITS] = ADC_IPW_ADC_TO_CTU_MAPPING_ARRAY;
    const uint8 CtuPhysicalId = AdcIdToCtuId[PhysicalHwUnitId];
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */

    /* Stop Conversion */
    if (TRUE == InjectedFlag)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        if (TriggerSrc <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
        {
            /* Conversion triggered by BCTU/CTU */
            Bctu_Ip_DisableHwTrigger(CtuPhysicalId, (uint8)TriggerSrc);

            /* Not needed to clear interrupt flags status, because this is already done in IPL interrupt,
            before calling the IPW function as notification */
        }
        else
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
        {
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
            /* Conversion is External Trigger */
            /* Disable injected external trigger input */
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_INJECTED_EXT_TRIG);
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED))
            Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */
#endif /* #if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
        }
    }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    else
    {
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
        /* Disable normal external trigger input */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
        Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_ALL_NORMAL_EXT_TRIG);
#else
        Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_NORMAL_EXT_TRIG);
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
        Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
    }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

    Adc_axUnitStatus[Unit].OngoingHwGroup = ADC_INVALID_HW_GROUP_ID;
}
#endif /* ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF */

/**
* @brief          This function handles the conversion by hardware trigger ending.
* @details        When a hardware conversion ends, and the end of conversion
*                 ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit                The current HW Unit.
* @param[in]      InjectedFlag        Normal or Injected conversion.
* @param[in]      UserId              Current UserId
*
* @return         void
*
* @api
* @implements     Adc_Ipw_EndHardwareConv_Activity
*/
static inline void Adc_Ipw_EndHardwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint8 UserId)
{
    Adc_GroupType GroupIndex;
    Adc_GroupType Group;
    /* Streaming num samples should be at least 1U */
    Adc_StreamNumSampleType GroupSamples;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    boolean  CallNotification = FALSE;
#endif /* ADC_GRP_NOTIF_CAPABILITY */
    Std_ReturnType  ReturnStatus = (Std_ReturnType) E_OK;
#if (ADC_SETCHANNEL_API == STD_ON)
    Std_ReturnType  TempStatus = (Std_ReturnType) E_OK;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    const Adc_GroupConfigurationType * GroupPtr = NULL_PTR;
#if (defined(ADC_DMA_SUPPORTED) || (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF))
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
#endif /* defined(ADC_DMA_SUPPORTED) || (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#ifdef ADC_DMA_SUPPORTED
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    boolean StreamLinearDone = FALSE;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
    Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#endif /* defined(ADC_DMA_SUPPORTED) */
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    boolean RuntimeChanUpdated = FALSE;
    Adc_StreamNumSampleType CurrentSampleCount = 0U;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

    /* Get the group to be converted. There is only one Hardware Group working at a time. */
    Group = Adc_axUnitStatus[Unit].OngoingHwGroup;
    GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);

#if (ADC_SETCHANNEL_API == STD_ON)
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        /* Configure the new list of channels even recording results were incorrect.*/
        (void)Adc_Ipw_ConfigureRuntimeHardwareGroup(Unit, InjectedFlag, UserId);
    }
    else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    {
        if (((ADC_CONV_TYPE_INJECTED == GroupPtr->Type) && (FALSE == InjectedFlag)) || \
            ((ADC_CONV_TYPE_NORMAL == GroupPtr->Type) && ((boolean)TRUE == InjectedFlag)) \
           )
        {
            /* Return when group conversion type doesn't match the ISR handler type (normal/injected) */
            ReturnStatus = (Std_ReturnType) E_NOT_OK;
        }

        if ((Std_ReturnType)E_OK == ReturnStatus)
        {
            GroupSamples = GroupPtr->NumSamples;

#ifdef ADC_DMA_SUPPORTED
            if (ADC_DMA != AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
#endif /*ADC_DMA_SUPPORTED*/
                /* Get the conversion result and save to buffer */
                ReturnStatus = Adc_Ipw_RecordResult(Unit, Group, GroupSamples, UserId);
#ifdef ADC_DMA_SUPPORTED
                Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
                Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
            }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            else
            {
                ReturnStatus = Adc_Ipw_CheckGroupConvResultDma(GroupPtr, AdcDmaLogicChId, UserId);
            }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /*ADC_DMA_SUPPORTED*/
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /* Call extra notification (if available) before updating registers (SWS_Adc_00060) */
            Adc_Ipw_CallExtraNotification(Group, UserId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
            if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
            {
                /* Configure the new list of channels even recording results were incorrect.*/
                TempStatus = Adc_Ipw_ConfigureRuntimeHardwareGroup(Unit, InjectedFlag, UserId);
                if ((Std_ReturnType)E_NOT_OK == TempStatus)
                {
                    ReturnStatus = (Std_ReturnType)E_NOT_OK;
                }
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                else
                {
                    RuntimeChanUpdated = TRUE;
                }
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
            }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

            if ((Std_ReturnType)E_OK == ReturnStatus)
            {
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                CurrentSampleCount = Adc_Ipw_GetNumsCurrentSample(AdcIpwConfigPtr, GroupPtr, RuntimeChanUpdated);
                /* At least once the group was converted */
                Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
                if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
                {
                    /* SWS_Adc_00224 */
                    Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
                }

                /* If all samples completed, wrap to 0 */
                if (GroupSamples <= CurrentSampleCount)
                {
                    /* SWS_Adc_00325 */
                    Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;
                    if ((ADC_STREAM_BUFFER_LINEAR == GroupPtr->BufferMode) && (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode))
                    {
#ifdef ADC_DMA_SUPPORTED
                        StreamLinearDone = TRUE;
#endif /* ADC_DMA_SUPPORTED */
                        /* Disable trigger source and notification from trigger unit */
                        Adc_Ipw_DisableHwTriggerSrc(Unit, InjectedFlag, GroupPtr->HwTriggerSource, UserId);
                    }
                    else
                    {
                        Adc_axGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_DMA_SUPPORTED
                        Adc_Ipw_ResetResultPointer(GroupPtr, AdcIpwConfigPtr, AdcDmaLogicChId);
#endif /* ADC_DMA_SUPPORTED */
                    }
                }
#else
                /* SWS_Adc_00325 */
                Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
                CallNotification = Adc_Ipw_CheckNotification(Group, UserId);
                if (TRUE == CallNotification)
                {
                    /* SWS_Adc_00140, SWS_Adc_00060 */
                    GroupPtr->Notification();
                }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#ifdef ADC_DMA_SUPPORTED
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                if (FALSE == StreamLinearDone)
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
                {
                    Adc_Ipw_UpdateNextDestinationAddress(Unit, AdcIpwConfigPtr, GroupPtr);
                }
#endif /* ADC_DMA_SUPPORTED */
            }
        }
    }
#ifdef ADC_DMA_SUPPORTED
    (void)AdcDmaLogicChId;
#endif /* ADC_DMA_SUPPORTED */
}
#endif /* (((defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || ... */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || defined(ADC_ANY_UNIT_DMA_TRANSFER_USED))
/**
* @brief          This function handles the Normal conversion ending.
* @details        When a normal conversion finishes, in callback of ISR, this function
*                 is called to update status, get the result of conversion.
*
* @param[in]      PhysicalAdcUnit   ADC Hardware Unit Physical
*
* @return         void
*
* @implements Adc_Ipw_EndNormalChainNotification_Activity
*/
static inline void Adc_Ipw_EndNormalChainNotification(const Adc_HwUnitType PhysicalAdcUnit)
{
    volatile uint8 UserId;
    Adc_HwUnitType LogicalAdcUnit;
    Adc_QueueIndexType SwNormalQueueIndex;

    /* Check that ADC unit is assigned to current user partition */
    UserId = Adc_GetUserID();

    LogicalAdcUnit = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (LogicalAdcUnit == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        SwNormalQueueIndex = Adc_axUnitStatus[LogicalAdcUnit].SwNormalQueueIndex;
        /*Software Normal queue is not empty and End of Normal chain conversion occurred (PR-MCAL-3272.adc) */
        if (SwNormalQueueIndex > (Adc_QueueIndexType)0)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndSoftwareConv(LogicalAdcUnit, FALSE, UserId);
        }

#if (ADC_HW_TRIGGER_API == STD_ON)
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        /* Hardware Normal queue is not empty and End of Normal chain conversion occurred (PR-MCAL-3272.adc) */
        if (ADC_INVALID_HW_GROUP_ID != Adc_axUnitStatus[LogicalAdcUnit].OngoingHwGroup)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndHardwareConv(LogicalAdcUnit, FALSE, UserId);
        }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
    }
}
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || ... */

#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || defined(ADC_ANY_UNIT_DMA_TRANSFER_USED))
/**
* @brief          This function handles the Injected conversion ending.
* @details        When a injected conversion finishes, in callback of ISR, this function
*                 is called to update status, get the result of conversion.
*
* @param[in]      PhysicalAdcUnit   ADC Hardware Unit Physical
*
* @return         void
*
* @implements Adc_Ipw_EndInjectedChainNotification_Activity
*/
static inline void Adc_Ipw_EndInjectedChainNotification(const Adc_HwUnitType PhysicalAdcUnit)
{
    volatile uint8 UserId;
    Adc_HwUnitType LogicalAdcUnit;
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
    Adc_QueueIndexType SwInjectedQueueIndex;
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

    /* Check that ADC unit is assigned to current user partition */
    UserId = Adc_GetUserID();

    LogicalAdcUnit = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (LogicalAdcUnit == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        SwInjectedQueueIndex = Adc_axUnitStatus[LogicalAdcUnit].SwInjectedQueueIndex;
        /* Software Injected queue is not empty and End of Injected chain conversion occurred (PR-MCAL-3272.adc) */
        if (SwInjectedQueueIndex > (Adc_QueueIndexType)0)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndSoftwareConv(LogicalAdcUnit, TRUE, UserId);
        }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
        /* Hardware Injected queue is not empty and End of Injected chain conversion occurred (PR-MCAL-3272.adc) */
        if (ADC_INVALID_HW_GROUP_ID != Adc_axUnitStatus[LogicalAdcUnit].OngoingHwGroup)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndHardwareConv(LogicalAdcUnit, TRUE, UserId);
        }
#endif /* ADC_HW_TRIGGER_API == STD_ON */
    }
}
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */

#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || \
     defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || \
     defined(ADC_ANY_UNIT_DMA_TRANSFER_USED) || \
    ((ADC_HW_TRIGGER_API == STD_ON) && (defined(ADC_ANY_UNIT_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
/**
* @brief          This function read conversion results
* @details        This function read conversion results
*
* @param[in]      GroupPtr      Group Pointer
* @param[in]      Result       Pointer to conversion results
* @param[in]      GroupSamples  Number of samples
* @param[in]      Index         Current index of result
* @param[in]      ConvResult    Conversion result
*
* @return         void
*/
static inline void Adc_Ipw_ReadData(const Adc_GroupConfigurationType * GroupPtr,
                                    Adc_ValueGroupType * Result,
                                    const Adc_StreamNumSampleType GroupSamples,
                                    const Adc_ChannelIndexType Index,
                                    const uint16 ConvResult)
{
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    if (FALSE == GroupPtr->StreamResultGroupMultiSets)
    {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        Result[(Index * GroupSamples)] = ConvResult;
        (void)GroupPtr;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    }
    else
    {
        Result[Index] = ConvResult;
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
}
#endif /* defined(ADC_ANY_UNIT_NORMAL_ISR_USED) ||... */

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
/**
* @brief          This function calls extra notification
* @details        This function calls extra notification
*
* @param[in]      Group         The channel group to be converted
* @param[in]      UserId        Current UserId
*
* @return         void
* CPR-MCAL-797.adc, SWS_Adc_00140
*/
static inline void Adc_Ipw_CallExtraNotification(Adc_GroupType Group,
                                                 uint8 UserId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];

    /* Call notification if available */
    if (Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].ExtraNotification != NULL_PTR)
    {
        Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].ExtraNotification();
    }
}
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#endif  /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) || ... */

#if (defined(ADC_ANY_UNIT_WDG_ISR_USED))
#ifdef ADC_WDG_SUPPORTED
/**
* @brief          This function handles the watchdog threshold ending.
* @details        When a conversion result is out of threshold range, in callback of ISR, this function
*                 is called to call watchdog threshold notification.
*
* @param[in]      PhysicalAdcUnit   ADC Physical Hardware Unit
* @param[in]      PhysicalChanId    ADC Physical Channel ID
*
* @return         void
*
* @implements Adc_Ipw_WdgThresholdNotification_Activity
*/
static inline void Adc_Ipw_WdgThresholdNotification(const Adc_HwUnitType PhysicalAdcUnit,
                                                    const Adc_ChannelType PhysicalChanId,
                                                    const uint8 Flags)
{
    volatile uint8 UserId;
    Adc_HwUnitType LogicalAdcUnit;
    Adc_ChannelType LogicalChanId;
    Adc_Ipw_Config const * AdcIpwConfigPtr;

    /* Check that ADC unit is assigned to current user partition */
    UserId = Adc_GetUserID();

    AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
    LogicalAdcUnit = AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (LogicalAdcUnit == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        /* Call notification callback */
        LogicalChanId = AdcIpwConfigPtr->Mapping.ChannelLogicalId[LogicalAdcUnit][PhysicalChanId];

        AdcIpwConfigPtr->AdcIpwChannelConfig[LogicalAdcUnit][LogicalChanId].WdgNotification(Flags);
    }
}
#endif /* ADC_WDG_SUPPORTED */
#endif /* defined(ADC_ANY_UNIT_WDG_ISR_USED) */

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                          ADC HW UNIT 0
==================================================================================================*/
#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_0_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_0_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_0_NORMAL_ISR_USED */

#ifdef ADC_UNIT_0_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_0_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 1
==================================================================================================*/
#if ((defined(ADC_UNIT_1_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_1_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_1_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_1_NORMAL_ISR_USED */

#ifdef ADC_UNIT_1_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_1_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 2
==================================================================================================*/
#if ((defined(ADC_UNIT_2_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_2_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_2_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_2_NORMAL_ISR_USED */

#ifdef ADC_UNIT_2_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_2_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_2_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_2_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 3
==================================================================================================*/
#if ((defined(ADC_UNIT_3_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 3.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 3.
*
* @return         void
*
*/
void Adc_Ipw_Adc3WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 3U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_3_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_3_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 3.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 3.
*
* @return         void
*
*/
void Adc_Ipw_Adc3EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 3U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_3_NORMAL_ISR_USED */

#ifdef ADC_UNIT_3_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 3.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 3.
*
* @return         void
*
*/
void Adc_Ipw_Adc3EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 3U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_3_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_3_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 3.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 3.
*
* @return         void
*
*/
void Adc_Ipw_Adc3DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 3U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 3.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 3.
*
* @return         void
*
*/
void Adc_Ipw_Adc3DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 3U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_3_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 4
==================================================================================================*/
#if ((defined(ADC_UNIT_4_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 4.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 4.
*
* @return         void
*
*/
void Adc_Ipw_Adc4WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 4U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_4_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_4_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 4.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 4.
*
* @return         void
*
*/
void Adc_Ipw_Adc4EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 4U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_4_NORMAL_ISR_USED */

#ifdef ADC_UNIT_4_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 4.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 4.
*
* @return         void
*
*/
void Adc_Ipw_Adc4EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 4U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_4_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_4_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 4.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 4.
*
* @return         void
*
*/
void Adc_Ipw_Adc4DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 4U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 4.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 4.
*
* @return         void
*
*/
void Adc_Ipw_Adc4DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 4U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_4_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 5
==================================================================================================*/
#if ((defined(ADC_UNIT_5_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 5.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 5.
*
* @return         void
*
*/
void Adc_Ipw_Adc5WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 5U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_5_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_5_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 5.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 5.
*
* @return         void
*
*/
void Adc_Ipw_Adc5EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 5U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_5_NORMAL_ISR_USED */

#ifdef ADC_UNIT_5_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 5.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 5.
*
* @return         void
*
*/
void Adc_Ipw_Adc5EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 5U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_5_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_5_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 5.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 5.
*
* @return         void
*
*/
void Adc_Ipw_Adc5DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 5U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 5.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 5.
*
* @return         void
*
*/
void Adc_Ipw_Adc5DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 5U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_5_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 6
==================================================================================================*/
#if ((defined(ADC_UNIT_6_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 6.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 6.
*
* @return         void
*
*/
void Adc_Ipw_Adc6WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 6U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_6_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_6_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 6.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 6.
*
* @return         void
*
*/
void Adc_Ipw_Adc6EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 6U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_6_NORMAL_ISR_USED */

#ifdef ADC_UNIT_6_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 6.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 6.
*
* @return         void
*
*/
void Adc_Ipw_Adc6EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 6U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_6_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_6_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 6.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 6.
*
* @return         void
*
*/
void Adc_Ipw_Adc6DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 6U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 6.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 6.
*
* @return         void
*
*/
void Adc_Ipw_Adc6DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 6U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_6_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          DMA Error Notification
==================================================================================================*/
#ifdef ADC_DMA_SUPPORTED
#if defined(ADC_DMA_ERROR_SUPPORTED)
/*FUNCTION**********************************************************************
 *
 * Function Name : Adc_Ipw_DMATransferErrorHandler
 * Description   : Handle error for DMA transfer. The main purpose of
 *                 this function is to create a function compatible with DMA
 *                 callback type
 *
 *END**************************************************************************/
static inline void Adc_Ipw_DMATransferErrorHandler(const Adc_HwUnitType PhysicalAdcUnit)
{
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
    const volatile uint8 UserId = Adc_GetUserID();
    Adc_HwUnitType LogicalAdcUnit = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];
    Adc_GroupType Group = Adc_axUnitStatus[LogicalAdcUnit].SwNormalQueue[0];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[Group]);
    Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const uint32 AdcDmaLogicChId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    uint32 TimeoutTicks = OsIf_MicrosToTicks(ADC_IPW_TIMEOUT_VAL, ADC_IPW_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(ADC_IPW_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0U;

    /* Prepare DMA status variables */
    DmaChannelStatus.Errors = 0UL;

    /* Get DMA channel status */
    while((0UL == DmaChannelStatus.Errors) && (ElapsedTicks < TimeoutTicks))
    {
        (void)Dma_Ip_GetLogicChannelStatus(AdcDmaLogicChId, &DmaChannelStatus);
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, ADC_IPW_TIMEOUT_TYPE);
    }
    /* Check for hardware errors */
    if (DmaChannelStatus.Errors != 0U)
    {
        if (GroupPtr->DmaErrorNotification != NULL_PTR)
        {
            /* Dma error notification*/
            GroupPtr->DmaErrorNotification();
        }
    }
}
#endif /* ADC_DMA_ERROR_SUPPORTED*/
#endif /*ADC_DMA_SUPPORTED*/

/*==================================================================================================
                                          BCTU UNIT 0 (0 and 1 for S32K396)
==================================================================================================*/
#if (ADC_HW_TRIGGER_API == STD_ON)
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
#ifdef ADC_UNIT_0_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC0
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc0(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[0U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_0_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_1_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC1
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc1(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[1U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_1_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_2_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC2
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc2(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[2U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_2_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_3_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC3
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc3(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[3U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_3_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_4_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC4
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc4(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[4U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_4_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_5_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC5
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc5(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[5U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_5_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_6_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC6
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc6(void)
{
    const volatile uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[6U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, UserId);
    }
}
#endif /* ADC_UNIT_6_BCTU_LIST_ISR_USED */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */


/*==================================================================================================
                                          SDADC section
==================================================================================================*/

#if (STD_ON == ADC_IPW_SDADC_IS_USED)

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED

/**
* @brief     This function gets number of current samples that were converted in the group in DMA mode.
*
*/
static inline Adc_StreamNumSampleType Adc_Ipw_GetDmaTransferSamplesSdadc(const uint8 UserId,
                                                                         const Adc_GroupType Group,
                                                                         const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                                         const Adc_StreamNumSampleType GroupSamples)
{
    /* In normal DMA mode, only 1-sample was read per DMA request (NOTE: this can be improved by transfering upto the fifo threshold).
       In optimized DMA mode, the number of samples will be calculated from iteration value of the transferring DMA channel.
     */
    Adc_StreamNumSampleType TransferSamples = 1U;

#if ((ADC_ENABLE_LIMIT_CHECK == STD_ON) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS))
    const Adc_GroupType                GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr   = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    const Adc_HwUnitType          LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const uint32                  AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
#else
    /* Unused variables */
    (void)UserId;
    (void)Group;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    const sint16 * const ReadBuffer = (sint16 *)( &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]) );
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
    const uint32          AdcCountingDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[LogicalHwUnitId];
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
    uint32                   TotalTransferSamples = 0U;  /* Total number of samples have been transferred so far */

    if (TRUE == GroupPtr->AdcOptimizeDmaStream)
    {
        /* Get current iter of the transferring DMA channel because Sdadc only supports 1 channel per group */
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
        if (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcCountingDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &TotalTransferSamples);
        }
        else
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &TotalTransferSamples);
        }

        /* This condition only occurs at half interrupt
           When major loop completed, CITER roll back to be equal to GroupSamples, so no need to re-calculate
         */
        if (TotalTransferSamples != GroupSamples)
        {
            /* Recalculation is needed because CITER decreases its value from GroupSamples to 1 */
            TotalTransferSamples = (uint32)GroupSamples - TotalTransferSamples;
        }

        /* Calculate the number of samples transferred in the last DMA request */
        TransferSamples = (Adc_StreamNumSampleType)TotalTransferSamples - Adc_axGroupStatus[Group].ResultIndex;
    }
#else

    /* Unused variables */
    (void)AdcIpwConfigPtr;
    (void)GroupSamples;

#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if (TRUE == GroupPtr->AdcGroupLimitcheck)
    {
        if (FALSE == Adc_Ipw_CheckConversionValuesInRange((uint16)ReadBuffer[0U], LogicalHwUnitId, GroupPtr->AssignmentPtr[0U], UserId))
        {
            Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
            TransferSamples = 0U;
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                if (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
                {   /* Reset DMA destination address */
                    Adc_Ipw_ResetDmaDestinationAddress(LogicalHwUnitId, GroupPtr, AdcIpwConfigPtr, AdcDmaLogicChId, (uint32)(&ReadBuffer[0U]));
                }
                /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
                (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
            }
        }
    }
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

    return TransferSamples;
}


static inline void Adc_Ipw_ResetDmaDestinationAddress(const Adc_HwUnitType LogicalHwUnitId,
                                                      const Adc_GroupConfigurationType * const GroupPtr,
                                                      const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                      const uint32 AdcDmaLogicChId,
                                                      const uint32 ResultsBufferrAddress)
{
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    boolean ResetRequired = FALSE;

    if ( (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) &&
         ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
       )
    {
        ResetRequired = TRUE;
    }

#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    if ( (TRUE == GroupPtr->AdcOptimizeDmaStream) &&
         (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
       )
    {
        /* No needed for optimized DMA mode wit DSPSS enabled, because only one channel is continuously transferred into one element in the intermediate buffer */
        ResetRequired = FALSE;
    }
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */

    if (TRUE == ResetRequired)
    {
        /* Re-configure the DMA destination address to the beginning of Group's buffer */
        LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        LocTransferList[0].Value = ResultsBufferrAddress;
        (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
    }

    /* Avoid compiler warning */
    (void)LogicalHwUnitId;
}


#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

static inline void Adc_Ipw_ResetDmaSourceAddress(const Adc_HwUnitType LogicalHwUnitId,
                                                 const Adc_HwUnitType PhysicalHwUnitId,
                                                 const Adc_GroupConfigurationType * const GroupPtr,
                                                 const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                 const uint32 AdcDmaLogicChId)
{
    Dma_Ip_LogicChannelScatterGatherListType  LocTransferList[1U];

   if ( (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
       && (FALSE == GroupPtr->AdcOptimizeDmaStream)  /* No needed for optimized DMA mode, because it's reset automatically by "Adc_Ipw_SetupTcdLastSourceAddressOffset" */
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
      )
   {
       /* Check and re-configure the DMA source address to the beginning of DSPSS's output buffer */
       if (TRUE == DSPSS_DmaReadBufferWrapPtrCheck((DSPSS_CFSDADC_DmaChannelType)PhysicalHwUnitId))
       {
           LocTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
           LocTransferList[0].Value = DSPSS_ThreadGetOutputBufferStart(PhysicalHwUnitId);
           (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
       }
   }

#if (STD_OFF == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    /* Avoid compiler warning */
    (void)GroupPtr;
#endif /* (STD_OFF == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
}

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */

#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */


#if ( defined(ADC_ANY_UNIT_FIFOFULL_ISR_USED) || defined(ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED) )

static inline void Adc_Ipw_UpdateGroupStateSdAdc(const uint8 UserId,
                                                 const Adc_HwUnitType Unit,
                                                 const Adc_GroupType Group,
                                                 const Adc_StreamNumSampleType GroupSamples,
                                                 const Adc_HwUnitType PhysicalHwUnitId)
{
    const Adc_GroupType                GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr   = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    /* Get current sampling count */
    const Adc_StreamNumSampleType CurrentSampleCount = Adc_axGroupStatus[Group].ResultIndex;

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    const Adc_Ipw_Config                    * const AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
    const uint32                              AdcDmaLogicChId       = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    const uint32                              ResultsBufferrAddress = (uint32)( &(Adc_axGroupStatus[Group].ResultsBufferPtr[0]) );
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */

    /* At least once the group was converted */
    Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
    {
        /* SWS_Adc_00224 */
        Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
    }

    /* If buffer is full of samples, wrap to 0 */
    if (GroupSamples <= CurrentSampleCount)
    {
        /* Change to stream complete according to AUTOSAR diagram (SWS_Adc_00325) */
        Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

        /* SWS_Adc_00519: For streaming linear groups:
           The ADC Driver stops the conversion as soon as the stream buffer is full (number of samples reached)
         */
        if ( (ADC_STREAM_BUFFER_LINEAR  == GroupPtr->BufferMode) &&
             (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
           )
        {
#if (ADC_HW_TRIGGER_API == STD_ON)
            if (ADC_TRIGG_SRC_HW == GroupPtr->TriggerSource)
            {
                /* Disable HW trigger */
                Sdadc_Ip_DisableHwTrigger(PhysicalHwUnitId);
                /* Remove the group from hardware queue */
                Adc_axUnitStatus[Unit].OngoingHwGroup = ADC_INVALID_HW_GROUP_ID;
            }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

            /* Re-enable the SDADC */
            Adc_Ipw_UpdateGroupStateReenableSdAdc(PhysicalHwUnitId);
            /* Update queue and execute new start conversion request from queue if available */
            Adc_Ipw_UpdateQueue(Unit, UserId);
        }

        /* Wrap-around (regardless of the access mode) */
        Adc_axGroupStatus[Group].ResultIndex = 0U;

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
        Adc_Ipw_ResetDmaDestinationAddress(Unit, GroupPtr, AdcIpwConfigPtr, AdcDmaLogicChId, ResultsBufferrAddress);
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */
    }

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* Check user notification function and execute if available */
    if (TRUE == Adc_Ipw_CheckNotification(Group, UserId))
    {
        /* SWS_Adc_00140, SWS_Adc_00060 */
        GroupPtr->Notification();
    }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    if ( (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]) &&
         ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
       )
    {
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
        /* Re-configure source address */
        Adc_Ipw_ResetDmaSourceAddress(Unit, PhysicalHwUnitId, GroupPtr, AdcIpwConfigPtr, AdcDmaLogicChId);
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */

        /* Re-enable DMA Hardware request */
        Adc_Ipw_EnableDmaHwRequest(Unit, GroupPtr, AdcIpwConfigPtr);
    }
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */
}

static inline void Adc_Ipw_UpdateGroupStateReenableSdAdc(const Adc_HwUnitType PhysicalHwUnitId)
{
    /* Stop the current conversion by disabling the SDADC */
    Sdadc_Ip_Powerdown(PhysicalHwUnitId);
    /* Disable fifo full request generation (for both interrupt and DMA) */
    Sdadc_Ip_DisableInterruptEvents(PhysicalHwUnitId, SDADC_IP_EVENT_FIFO_FULL);
    /* Re-enable the SDADC to be ready for the next conversion */
    Sdadc_Ip_Powerup(PhysicalHwUnitId);
}

static inline Adc_StreamNumSampleType Adc_Ipw_CalcAvailableSamplesSdAdc(const uint8 UserId,
                                                                        const Adc_HwUnitType Unit)
{
    Adc_StreamNumSampleType AvailableSamples;
    const Sdadc_Ip_ConfigType * const Config = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->SdadcConfigPtrArr[Unit];

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (Config->DspssConfig != NULL_PTR)
    {
        /* Use DSPSS core buffer fifo output threshold value */
        AvailableSamples = (Adc_StreamNumSampleType)(Config->DspssConfig->OutputThreshold);
    }
    else
#endif
    {
        /* The number of available conversion results in SDADC hardware fifo (threshold plus 1) */
        AvailableSamples = (Adc_StreamNumSampleType)(Config->FifoThreshold) + 1U;

        /* The actual test shows that it can only read a maximum of 8 elements from the FIFO.
        For example: With threshold = 9, after 8 reads the fifo empty flag was set.
                     With threshold = 15, after 8 reads the fifo empty flag was set.
        */
        if (AvailableSamples > 8U)
        {
            AvailableSamples = 8U;
        }
    }

    return AvailableSamples;
}


static inline Adc_StreamNumSampleType Adc_Ipw_RecordResultSdAdc(const uint8 UserId,
                                                                const Adc_HwUnitType Unit,
                                                                const Adc_GroupType Group,
                                                                const Adc_StreamNumSampleType GroupSamples,
                                                                const Adc_HwUnitType PhysicalHwUnitId)
{
    /* Get current sampling count */
    const Adc_StreamNumSampleType CurrentSampleCount = Adc_axGroupStatus[Group].ResultIndex;
    /* Local variables to calculate the maximum samples can be read from fifo */
    Adc_StreamNumSampleType AvailableSamples;
    Adc_StreamNumSampleType ExpectedSamples;
    Adc_StreamNumSampleType ActualSamples = 0U;
    /* Current index in group buffer */
    sint16 * const ReadBuffer = (sint16 *)( &(Adc_axGroupStatus[Group].ResultsBufferPtr[CurrentSampleCount]) );

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    uint32 SampleCnt;
    sint16 ConvValue = 0;
    const Adc_GroupType              GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

    /* Calculate the number of available samples in fifo */
    AvailableSamples = Adc_Ipw_CalcAvailableSamplesSdAdc(UserId, Unit);

    /* Read upto fifo length or the remaining samples */
    ExpectedSamples = GroupSamples - CurrentSampleCount;
    if (ExpectedSamples > AvailableSamples)
    {
        ExpectedSamples = AvailableSamples;
    }

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Checks if conversion values are in the configured range */
    if (TRUE == GroupPtr->AdcGroupLimitcheck)
    {
        /* Read each sample from FIFO and perform range checking one by one */
        for (SampleCnt = 0U; SampleCnt < ExpectedSamples; SampleCnt++)
        {
            if (1U == (Adc_StreamNumSampleType)Sdadc_Ip_GetConvData(PhysicalHwUnitId, 1U, &ConvValue))
            {
                if (TRUE == Adc_Ipw_CheckConversionValuesInRange((uint16)ConvValue, Unit, 0U, UserId))
                {
                    /* Result is is valid range, put it to buffer */
                    ReadBuffer[ActualSamples] = ConvValue;
                    ActualSamples++;
                }
            }
        }
        /* Check if all samples are valid*/
        if (ActualSamples != ExpectedSamples)
        {
            Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
            Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
        }
    }
    else
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    {
        /* Get the converted results from hardware into group buffer */
        ActualSamples = (Adc_StreamNumSampleType)Sdadc_Ip_GetConvData(PhysicalHwUnitId, (uint32)ExpectedSamples, ReadBuffer);
    }
    
    /* Check if the requested read results are valid */
    if (ActualSamples != ExpectedSamples)
    {
        ActualSamples = 0U;  /* The converted data is invalid */
    }

    return ActualSamples;
}


static inline void Adc_Ipw_EndSoftwareConvSdAdc(const uint8 UserId,
                                                const Adc_HwUnitType Unit,
                                                const Adc_GroupType Group)
{
    /* Get the group to be converted */
    const Adc_GroupType           GroupIndex       = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_StreamNumSampleType GroupSamples     = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].NumSamples;
    const Adc_Ipw_Config * const  AdcIpwConfigPtr  = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
    const Adc_HwUnitType          PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[Unit] - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
    Adc_StreamNumSampleType       CompletedSamples;

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
    {
        /* In DMA mode, the conversion result has been already transfered into buffer, only need to get the number of transferred samples */
        CompletedSamples = Adc_Ipw_GetDmaTransferSamplesSdadc(UserId, Group, AdcIpwConfigPtr, GroupSamples);
    }
    else
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */
    {
        /* Get the conversion result and save to buffer */
        CompletedSamples = Adc_Ipw_RecordResultSdAdc(UserId, Unit, Group, GroupSamples, PhysicalHwUnitId);
    }

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
    /* Call extra notification (if available) before updating registers (SWS_Adc_00060) */
    Adc_Ipw_CallExtraNotification(Group, UserId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

    /* Check if the result is valid */
    if (0U != CompletedSamples)
    {
        /* Update the completed samples */
        Adc_axGroupStatus[Group].ResultIndex += CompletedSamples;

        /* Update group state and continue conversion */
        Adc_Ipw_UpdateGroupStateSdAdc(UserId, Unit, Group, GroupSamples, PhysicalHwUnitId);
    }
    else
    {
        /* Do nothing */
    }
}


static inline void Adc_Ipw_FifoFullNotification(const Adc_HwUnitType PhysicalAdcUnit)
{
    Adc_QueueIndexType SwNormalQueueIndex;
    /* Check that ADC unit is assigned to current user partition */
    const uint8 UserId = Adc_GetUserID();
    const Adc_HwUnitType LogicalAdcUnit = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (ADC_IPW_INVALID_LOGICAL_UNIT_ID == LogicalAdcUnit)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid user partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        SwNormalQueueIndex = Adc_axUnitStatus[LogicalAdcUnit].SwNormalQueueIndex;
        /* Software queue is not empty and FIFO full event occurred */
        if (SwNormalQueueIndex > (Adc_QueueIndexType)0U)
        {
            /* Handle the end of conversion for the first group in queue */
            Adc_Ipw_EndSoftwareConvSdAdc(UserId, LogicalAdcUnit, Adc_axUnitStatus[LogicalAdcUnit].SwNormalQueue[0U]);
        }

#if (ADC_HW_TRIGGER_API == STD_ON)
        /* Hardware queue is not empty and FIFO full event occurred */
        if (ADC_INVALID_HW_GROUP_ID != Adc_axUnitStatus[LogicalAdcUnit].OngoingHwGroup)
        {
            /* Handle the end of conversion for the on going HW group (There is only one hardware group working at a time) */
            Adc_Ipw_EndSoftwareConvSdAdc(UserId, LogicalAdcUnit, Adc_axUnitStatus[LogicalAdcUnit].OngoingHwGroup);
        }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    }

}

#endif /* ADC_ANY_UNIT_FIFOFULL_ISR_USED || ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */


/*==================================================================================================
                                          SDADC FIFO FULL NOTIFICATIONS
==================================================================================================*/

#ifdef ADC_UNIT_SDADC_0_FIFOFULL_ISR_USED
/**
* @brief          This function implements the fifo full notification for SDADC Hardware Unit 0.
* @return         void
*
*/
void Adc_Ipw_Sdadc0FifoFullNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 0U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_SDADC_0_FIFOFULL_ISR_USED */


#ifdef ADC_UNIT_SDADC_1_FIFOFULL_ISR_USED
/**
* @brief          This function implements the fifo full notification for SDADC Hardware Unit 1.
* @return         void
*
*/
void Adc_Ipw_Sdadc1FifoFullNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 1U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_SDADC_1_FIFOFULL_ISR_USED */


#ifdef ADC_UNIT_SDADC_2_FIFOFULL_ISR_USED
/**
* @brief          This function implements the fifo full notification for SDADC Hardware Unit 2.
* @return         void
*/
void Adc_Ipw_Sdadc2FifoFullNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 2U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_SDADC_2_FIFOFULL_ISR_USED */


#ifdef ADC_UNIT_SDADC_3_FIFOFULL_ISR_USED
/**
* @brief          This function implements the fifo full notification for SDADC Hardware Unit 3.
* @return         void
*/
void Adc_Ipw_Sdadc3FifoFullNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 3U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_SDADC_3_FIFOFULL_ISR_USED */


/*==================================================================================================
                                          SDADC DMA NOTIFICATIONS
==================================================================================================*/

#ifdef ADC_UNIT_SDADC_0_DMA_TRANSFER_USED
/**
* @brief          This function implements the end of dma transfer notification for SDADC Hardware Unit 0.
* @return         void
*
*/
void Adc_Ipw_Sdadc0DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 0U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}

#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Sdadc0DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 0U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /* ADC_DMA_ERROR_SUPPORTED */
#endif /* ADC_UNIT_SDADC_0_DMA_TRANSFER_USED */


#ifdef ADC_UNIT_SDADC_1_DMA_TRANSFER_USED
/**
* @brief          This function implements the end of dma transfer notification for SDADC Hardware Unit 1.
* @return         void
*
*/
void Adc_Ipw_Sdadc1DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 1U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}

#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Sdadc1DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 1U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /*ADC_DMA_ERROR_SUPPORTED*/
#endif /* ADC_UNIT_SDADC_1_DMA_TRANSFER_USED */


#ifdef ADC_UNIT_SDADC_2_DMA_TRANSFER_USED
/**
* @brief          This function implements the end of dma transfer notification for SDADC Hardware Unit 2.
* @return         void
*
*/
void Adc_Ipw_Sdadc2DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 2U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}

#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Sdadc2DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 2U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /*ADC_DMA_ERROR_SUPPORTED*/
#endif /* ADC_UNIT_SDADC_2_DMA_TRANSFER_USED */


#ifdef ADC_UNIT_SDADC_3_DMA_TRANSFER_USED
/**
* @brief          This function implements the end of dma transfer notification for SDADC Hardware Unit 3.
* @return         void
*
*/
void Adc_Ipw_Sdadc3DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 3U;

    Adc_Ipw_FifoFullNotification(PhysicalAdcUnit);
}

#if defined(ADC_DMA_ERROR_SUPPORTED)
/**
* @brief          This function implements the dma Error notification for
*                 ADC Hardware Unit 3.
* @details        This function implements the dma Error notification for
*                 ADC Hardware Unit 3.
*
* @return         void
*
*/
void Adc_Ipw_Sdadc3DmaTransferError(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 3U;
    Adc_Ipw_DMATransferErrorHandler(PhysicalAdcUnit);
}
#endif /*ADC_DMA_ERROR_SUPPORTED*/
#endif /* ADC_UNIT_SDADC_3_DMA_TRANSFER_USED */


/*==================================================================================================
                                          SDADC WDG NOTIFICATIONS
==================================================================================================*/

#ifdef ADC_UNIT_SDADC_0_WDG_ISR_USED
/**
* @brief          This function implements the Wdg threshold notification for
*                 SDADC Hardware Unit 0.
* @return         void
*
*/
void Adc_Ipw_Sdadc0WdgThresholdNotification(const uint16 PhysicalChanId,
                                            const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 0U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ADC_UNIT_SDADC_0_WDG_ISR_USED */

#ifdef ADC_UNIT_SDADC_1_WDG_ISR_USED
/**
* @brief          This function implements the Wdg threshold notification for
*                 SDADC Hardware Unit 1.
* @return         void
*
*/
void Adc_Ipw_Sdadc1WdgThresholdNotification(const uint16 PhysicalChanId,
                                            const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 1U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ADC_UNIT_SDADC_1_WDG_ISR_USED */

#ifdef ADC_UNIT_SDADC_2_WDG_ISR_USED
/**
* @brief          This function implements the Wdg threshold notification for
*                 SDADC Hardware Unit 2.
* @return         void
*
*/
void Adc_Ipw_Sdadc2WdgThresholdNotification(const uint16 PhysicalChanId,
                                            const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 2U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ADC_UNIT_SDADC_2_WDG_ISR_USED */

#ifdef ADC_UNIT_SDADC_3_WDG_ISR_USED
/**
* @brief          This function implements the Wdg threshold notification for
*                 SDADC Hardware Unit 3.
* @return         void
*
*/
void Adc_Ipw_Sdadc3WdgThresholdNotification(const uint16 PhysicalChanId,
                                            const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = ADC_IPW_SDADC_PHYSICAL_ID_OFFSET + 3U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ADC_UNIT_SDADC_3_WDG_ISR_USED */


#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */

/*==================================================================================================
                                        End of SDADC section
==================================================================================================*/


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
