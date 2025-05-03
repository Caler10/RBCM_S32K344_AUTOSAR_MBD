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
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Ipw.h"
#include "Adc.h"
#if (ADC_MULTIPARTITION_SUPPORT == STD_ON)
    #include "OsIf.h"
#endif
#if (ADC_ENABLE_QUEUING == STD_ON)
    #include "SchM_Adc.h"
#endif

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
#include "DSPSS_Api.h"          /* DSPSS header */
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_C                    43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define ADC_IPW_SW_MAJOR_VERSION_C             5
#define ADC_IPW_SW_MINOR_VERSION_C             0
#define ADC_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC IPW header file are from the same vendor */
#if (ADC_IPW_VENDOR_ID_C != ADC_IPW_VENDOR_ID)
    #error "Adc_Ipw.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC IPW header file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_C != ADC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_C != ADC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_C != ADC_IPW_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_C != ADC_IPW_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_C != ADC_IPW_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC header file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_C != ADC_VENDOR_ID)
#error "Adc_Ipw.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Ipw.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Adc_Ipw.c and Adc.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (ADC_MULTIPARTITION_SUPPORT == STD_ON)
/* Check if Adc_Ipw.c file and OsIf.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ipw.c and OsIf.h are different"
#endif
#endif /* ADC_MULTIPARTITION_SUPPORT == STD_ON */

#if (ADC_ENABLE_QUEUING == STD_ON)
/* Check if Adc_Ipw.c file and SchM_Adc.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ipw.c and SchM_Adc.h are different"
#endif
#endif /* ADC_ENABLE_QUEUING == STD_ON */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

/* Check if Adc_Ipw.c file and DSPSS_Api.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_C != DSPSS_VENDOR_ID_API)
    #error "Adc_Ipw.c and DSPSS_Api.h have different vendor ids"
#endif

/* Check if Adc_Ipw.c file and DSPSS_Api.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_C != DSPSS_AR_RELEASE_MAJOR_VERSION_API) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_C != DSPSS_AR_RELEASE_MINOR_VERSION_API) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_C != DSPSS_AR_RELEASE_REVISION_VERSION_API) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw.c and DSPSS_Api.h are different"
#endif

/* Check if Adc_Ipw.c file and DSPSS_Api.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_C != DSPSS_SW_MAJOR_VERSION_API) || \
     (ADC_IPW_SW_MINOR_VERSION_C != DSPSS_SW_MINOR_VERSION_API) || \
     (ADC_IPW_SW_PATCH_VERSION_C != DSPSS_SW_PATCH_VERSION_API) \
    )
  #error "Software Version Numbers of Adc_Ipw.c and DSPSS_Api.h are different"
#endif

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef ADC_DMA_SUPPORTED
#define ADC_IPW_GET_COMPLEMENT_OF_2(x)      ((uint32)(~((uint32)(x)) + 1U))
#endif /* ADC_DMA_SUPPORTED */
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONST_8
#include "Adc_MemMap.h"

#if ( (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) )

/* Mapping ADC instance to BCTU instance*/
static const uint8 Adc_Ipw_au8AdcIdToCtuId[ADC_IPW_MAX_HW_UNITS] = ADC_IPW_ADC_TO_CTU_MAPPING_ARRAY;

#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) */


#if ( (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) )

/* Offset for mapping some bit fields and registers of BCTU to corresponding ADC instance.
Eg: ADC_SEL0 of BCTU0 using for ADC0 but ADC_SEL0 of BCTU1 is for ADC3 */
static const uint8 Adc_Ipw_au8AdcIndexOffset[ADC_IPW_CTU_MAX_HW_UNITS] = ADC_IPW_ADC_INDEX_OFFSET_BITFIELD_ARRAY;

#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) */

#define ADC_STOP_SEC_CONST_8
#include "Adc_MemMap.h"


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifdef ADC_DMA_SUPPORTED
#define ADC_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Adc_MemMap.h"

/* Internal Buffer filled in by DMA for clear pending HW Dma Request (Adc_Ipw_DmaClearPendingReq). It makes a temp transfer by itself. */
static uint8 Adc_Ipw_u8DmaDraftBuffer;

#define ADC_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Adc_MemMap.h"

#if (ADC_READ_GROUP_API == STD_ON)
#define ADC_START_SEC_CONST_8
#include "Adc_MemMap.h"

/* Available resolutions. */
static const uint8 Adc_Ipw_au8AvailableResolutions[4U] = ADC_IPW_AVAILABLE_RESOLUTIONS;

#define ADC_STOP_SEC_CONST_8
#include "Adc_MemMap.h"
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#define ADC_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Adc_MemMap.h"
/* Internal Dma Buffer filled in by DMA for groups having Without Interrupts enabled.
Store all 32 bits result data, because it is required to check if last conversion from group has completed in ReadGroup. */
static uint32 Adc_Ipw_au32DmaNoIrqBuffer[ADC_IPW_MAX_HW_UNITS][ADC_MAX_CHANNEL_PER_HW_UNIT];

#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
/* Intermediate buffer is used for Optimize DMA streaming groups to avoid overwriting data in Adc_Ipw_au32DmaNoIrqBuffer of without interrupt groups.
Rationale: Adc_Ipw_au32DmaNoIrqBuffer is used in Adc_ReadGroup for DMA without interrupt groups whereas optimize streaming group has interrupts
and Adc_ReadGroup gets data from user buffer. Therefore, if Adc_Ipw_au32DmaNoIrqBuffer is shared, an normal without interrupt group might lost
converted data in Adc_Ipw_au32DmaNoIrqBuffer before using Adc_ReadGroup for that group when the injected optimize streaming groups starts its own
conversions with different set of channels. */
static uint32 Adc_Ipw_au32DmaIntermediateBuffer[ADC_IPW_MAX_HW_UNITS][ADC_MAX_CHANNEL_PER_HW_UNIT];
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#define ADC_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Adc_MemMap.h"
#endif /* ADC_DMA_SUPPORTED */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if ((ADC_READ_GROUP_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON))
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
static inline Std_ReturnType Adc_Ipw_IsChannelEnable(Adc_HwUnitType LogicalHwUnitId,
                                                     Adc_GroupType GroupId,
                                                     Adc_ChannelType ChIndex,
                                                     uint8 UserId);
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
#endif /* ((ADC_READ_GROUP_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)) */

#if (ADC_READ_GROUP_API == STD_ON)
static inline Adc_Sar_Ip_ChanResultType Adc_Ipw_CalculateLastChan(const Adc_GroupType Group,
                                                                  const Adc_Sar_Ip_ConvChainType ConversionType,
                                                                  const uint8 UserId);

static inline Std_ReturnType Adc_Ipw_GetChanResultNoInt(const Adc_GroupType Group,
                                                        const Adc_Sar_Ip_ConvChainType ConversionType,
                                                        const uint8 UserId,
                                                        Adc_ValueGroupType * DataPtr,
                                                        boolean * Flag);

static inline Std_ReturnType Adc_Ipw_ReadGroupNoInt(const Adc_GroupType Group,
                                                    Adc_ValueGroupType * DataPtr,
                                                    boolean * Flag,
                                                    uint8 UserId);

static inline Std_ReturnType Adc_Ipw_ReadGroupAdcSar(const Adc_GroupType Group,
                                                     Adc_ValueGroupType * DataPtr,
                                                     boolean * Flag,
                                                     uint8 UserId);
static inline void Adc_Ipw_ReadGroupIntAdcSar(const Adc_GroupType Group,
                                                Adc_ValueGroupType * DataPtr,
                                                uint8 UserId);

#if (ADC_IPW_SDADC_IS_USED == STD_ON)

static inline Std_ReturnType Adc_Ipw_ReadGroupNoIntSdAdc(const Adc_GroupType Group,
                                                         Adc_ValueGroupType * DataPtr,
                                                         boolean * Flag,
                                                         uint8 UserId);

static inline Std_ReturnType Adc_Ipw_ReadGroupSdAdc(const Adc_GroupType Group,
                                                    Adc_ValueGroupType * DataPtr,
                                                    boolean * Flag,
                                                    uint8 UserId);

#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */

#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if ((ADC_HW_TRIGGER_API == STD_ON) && (((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) || (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)))
#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_DisableHardwareTriggerChannelDma(const Adc_HwUnitType PhysicalHwUnitId, uint32 Group);
#endif
#endif

#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_DmaClearPendingReq(const uint32 DmaLogicChannel);

static inline uint32 Adc_Ipw_GetDataAddress(const Adc_HwUnitType PhysicalHwUnitId,
                                            const uint8 PhysChannelId);

static inline uint32 Adc_Ipw_GetDataOffset(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                           const Adc_HwUnitType LogicalHwUnitId,
                                           const Adc_HwUnitType PhysicalHwUnitId);

static inline void Adc_Ipw_DisableHardwareTriggerChannelDma(const Adc_HwUnitType PhysicalHwUnitId, uint32 Group);

#if ( (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) )

static inline void Adc_Ipw_SetupTcdSingleAdcChannelMajorLink(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                             const Adc_GroupConfigurationType * const GroupPtr,
                                                             const Adc_HwUnitType PhysicalHwUnitId);

#endif /* (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

static inline void Adc_Ipw_SetupTcdSingleAdcChannelDmaConfig(const uint32 AdcDmaLogicChId,
                                                             const Dma_Ip_LogicChannelTransferListType LocTransferList[],
                                                             const uint32 LocTransferListNumElems);

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

static inline uint32 Adc_Ipw_GetDspssThreadOutputBufferLength(const Adc_HwUnitType PhysicalHwUnitId);

static inline void Adc_Ipw_SetupTcdLastSourceAddressOffset(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                           const Adc_GroupConfigurationType * const GroupPtr);

#if ((STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS))

static inline void Adc_Ipw_SetupTcdSingleAdcChannelMinorLink(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                             const Adc_GroupConfigurationType * const GroupPtr);

#endif /* (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */

#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */

static inline void Adc_Ipw_SetupTcdSingleAdcChannel(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                    const Adc_GroupConfigurationType * const GroupPtr,
                                                    uint8 PhysChannelId);

static inline void Adc_Ipw_SetupTcdMultiAdcChannel(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                   const Adc_GroupConfigurationType * const GroupPtr,
                                                   Adc_ChannelIndexType ChannelCount);

static inline void Adc_Ipw_StartDmaOperation(uint8 Unit,
                                             Adc_GroupType Group,
                                             uint8 UserId);

#if (ADC_DEINIT_API == STD_ON)
static inline void Adc_Ipw_DmaClearHwRequest(uint8 UserId,
                                            Adc_HwUnitType LogicalHwUnitId);
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
static void Adc_Ipw_MaskConvResult(uint32 DmaResult,
                                   Adc_Sar_Ip_ChanResultType * const Result,
                                   const boolean SkipValidation,
                                   const uint8 Resolution,
                                   Adc_Sar_Ip_DataAlignedType DataAlignment)
{
    uint32 DmaBufferMask;

    Result->ConvData = 0u;
    Result->ValidFlag = FALSE;
    Result->OverWrittenFlag = FALSE;

    /* Check if the the conversion data is valid */
    if (((DmaResult != ADC_IPW_INVALID_DATA_RESULT_DMA) && ((DmaResult & ADC_CDR_VALID_MASK) != 0U)) || SkipValidation)
    {
        /* The data is correct, store the result in and clear the flag */
        Result->ValidFlag = TRUE;
        Result->OverWrittenFlag = (1U == ((DmaResult & ADC_CDR_OVERW_MASK) >> ADC_CDR_OVERW_SHIFT));
        if (ADC_SAR_IP_DATA_ALIGNED_LEFT == DataAlignment)
        {
            DmaBufferMask = (uint32)ADC_CDR_CDATA_MASK << (16u - Resolution);
            Result->ConvData = (uint16)(DmaResult & DmaBufferMask) >> ADC_CDR_CDATA_SHIFT;
        }
        else
        {
            DmaBufferMask = ((uint32)ADC_CDR_CDATA_MASK >> 1) & ((uint32)ADC_CDR_CDATA_MASK << (ADC_SAR_IP_RESULT_RESOLUTION - Resolution));
            Result->ConvData = ((uint16)(DmaResult & DmaBufferMask)) >> (ADC_SAR_IP_RESULT_RESOLUTION - Resolution + ADC_CDR_CDATA_SHIFT);
        }
    }
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
static inline void Adc_Ipw_EnableDMA(Adc_HwUnitType Unit,
                                     uint8 UserId,
                                     Adc_GroupType Group,
                                     const Adc_GroupConfigurationType * GroupPtr);
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
static inline void Adc_Ipw_StartNormalConversionAdcSarDmaEnable(const Adc_HwUnitType Unit,
                                                const uint8 UserId,
                                                const Adc_GroupType Group,
                                                const Adc_GroupConfigurationType * GroupPtr,
                                                const Adc_HwUnitType PhysicalHwUnitId);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
static inline void Adc_Ipw_InitNcmrMask(const Adc_ConfigType * CfgPtr);
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
static inline void Adc_Ipw_PrepareGroupStart(Adc_HwUnitType Unit,
                                             const Adc_GroupConfigurationType * GroupPtr,
                                             uint8 UserId);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */

#if ((ADC_IPW_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON))
static inline Std_ReturnType Adc_Ipw_BctuTriggerEnable(const Adc_GroupType Group,
                                                       Adc_HwTriggerTimerType TriggerSource,
                                                       boolean AutosarApi,
                                                       boolean FirstTrigger,
                                                       uint8 UserId);
#endif /* ((ADC_IPW_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON)) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
static void Adc_Ipw_StartNormalConversionAdcSar(const Adc_HwUnitType Unit,
                                                const uint8 UserId,
                                                const Adc_GroupType Group,
                                                const Adc_GroupConfigurationType * GroupPtr,
                                                const Adc_HwUnitType PhysicalHwUnitId);

static Std_ReturnType Adc_Ipw_StopCurrentConversionAdcSar(Adc_HwUnitType Unit,
                                                          Adc_GroupType Group,
                                                          uint8 UserId,
                                                          Adc_HwUnitType PhysicalHwUnitId);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
static inline  Std_ReturnType Adc_Ipw_ConfigureThresholdAdcSar(const Adc_ThresholdControlIndexType ThresholdControlIndex,
                                                               const Adc_ValueGroupType LowValue,
                                                               const Adc_ValueGroupType HighValue,
                                                               const uint8 UserId);
#endif /* (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
static inline void Adc_Ipw_StartNormalConversionSdAdcClearFifo(const Adc_HwUnitType PhysicalHwUnitId);

static void Adc_Ipw_StartNormalConversionSdAdc(const Adc_HwUnitType Unit,
                                               const uint8 UserId,
                                               const Adc_GroupType Group,
                                               const Adc_GroupConfigurationType * GroupPtr,
                                               const Adc_HwUnitType PhysicalHwUnitId);

static Std_ReturnType Adc_Ipw_StopCurrentConversionSdAdc(Adc_HwUnitType Unit,
                                                         Adc_GroupType Group,
                                                         uint8 UserId,
                                                         Adc_HwUnitType PhysicalHwUnitId);
#endif /* ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON)) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
static inline Std_ReturnType Adc_Ipw_ConfigureThresholdSdAdc(const Adc_ThresholdControlIndexType ThresholdControlIndex,
                                                             const Adc_ValueGroupType LowValue,
                                                             const Adc_ValueGroupType HighValue,
                                                             const uint8 UserId);
#endif /* (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */


#if (ADC_HW_TRIGGER_API == STD_ON)

static inline Std_ReturnType Adc_Ipw_EnableHardwareTriggerAdcSar(const Adc_GroupType Group,
                                                                 const Adc_HwUnitType Unit,
                                                                 const uint8 UserId);

static inline void Adc_Ipw_DisableHardwareTriggerAdcSar(const Adc_GroupType Group,
                                                        const Adc_HwUnitType Unit,
                                                        const uint8 UserId);

#if (ADC_IPW_SDADC_IS_USED == STD_ON)

static inline Std_ReturnType Adc_Ipw_EnableHardwareTriggerSdAdc(const Adc_GroupType Group,
                                                                const Adc_HwUnitType Unit,
                                                                const uint8 UserId);

static inline void Adc_Ipw_DisableHardwareTriggerSdAdc(const Adc_GroupType Group,
                                                       const Adc_HwUnitType Unit,
                                                       const uint8 UserId);

#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */


#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)

/* Limit check for ADCSAR and SDADC (Both Sign and Unsign cases) */
static inline boolean Adc_Ipw_IsValueInRange(const Adc_ValueGroupType Value,
                                             const Adc_ChannelRangeSelectType ChRange,
                                             const Adc_ValueGroupType LowLimit,
                                             const Adc_ValueGroupType HighLimit,
                                             const boolean SignChecking);

#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (ADC_ENABLE_QUEUING == STD_ON)
/**
* @brief          This function performs the dequeue operation on the internal ADC queue.
* @details        This function performs the dequeue operation on the internal ADC queue.
*
* @param[in]      Unit            Adc unit used. Recommended to use generated define for Adc Logical Unit Id.
* @param[in]      CurQueueIndex   The current queue index.
*
* @return         void
*
* @pre This function must be called from a critical region. It is not protecting itself against interruptions.
*/
void Adc_Ipw_RemoveFromQueue(const Adc_HwUnitType Unit,
                             const Adc_QueueIndexType CurQueueIndex)
{
    Adc_QueueIndexType PositionIndex = 0U;
    Adc_QueueIndexType CurrentIndex = 0U;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();
    CurrentIndex = Adc_axUnitStatus[Unit].SwNormalQueueIndex;
    if ((Adc_QueueIndexType)1U >= CurrentIndex)
    {
        /* Zero or one element present in the queue */
        Adc_axUnitStatus[Unit].SwNormalQueueIndex = 0U;
    }
    else
    {
        /* More than one element in the queue */
        /* Move all elements after the one to remove (from CurQueueIndex position) one place to the left */
        for (PositionIndex = (CurQueueIndex + 1U); PositionIndex < CurrentIndex; PositionIndex++)
        {
            Adc_axUnitStatus[Unit].SwNormalQueue[PositionIndex - 1U] = (Adc_GroupType)Adc_axUnitStatus[Unit].SwNormalQueue[PositionIndex];
        }
        Adc_axUnitStatus[Unit].SwNormalQueueIndex--;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
}
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#ifndef ADC_CMR_REGISTER_NOT_SUPPORTED
void Adc_Ipw_GetCmrRegister(Adc_HwUnitType Unit,
                            Adc_GroupType Group,
                            Adc_ChansIdxMaskType * CmrMask,
                            uint8 UserId)
{
#if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_SETCHANNEL_API == STD_OFF))
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_SETCHANNEL_API == STD_OFF) */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_GroupType Adc_IndividualGroupId;
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
#if (ADC_SETCHANNEL_API == STD_ON)
    Adc_ChannelType ChId;
    Adc_ChannelIndexType Ch;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    uint8 i;

    (void)Unit;

    for (i = 0; i < ADC_SAR_IP_NUM_GROUP_CHAN; i++)
    {
        CmrMask->ChanMaskArr[i] = 0UL;
    }

    /* If the Individual group channel enable capability is ON*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_IndividualGroupId = GroupPtr->EnableChDisableChGroupIndex;
    if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != Adc_IndividualGroupId)
    {
        for (i = 0; i < ADC_SAR_IP_NUM_GROUP_CHAN; i++)
        {
            CmrMask->ChanMaskArr[i] = Adc_axRuntimeChansEnMask[Adc_IndividualGroupId].ChanMaskArr[i];
        }
    }
    else
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        for (Ch = 0U; Ch < Adc_axRuntimeGroupChannel[Group].ChannelCount; Ch++)
        {
            ChId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[Ch]].ChanIndex;
            Adc_Ipw_SetChansMask(CmrMask, ChId);
        }
#else
        /* Program the mask registers */
        for (i = 0; i < ADC_SAR_IP_NUM_GROUP_CHAN; i++)
        {
            CmrMask->ChanMaskArr[i] = GroupPtr->AssignedChannelMask.ChanMaskArr[i];
        }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    }
}
#endif /* ADC_CMR_REGISTER_NOT_SUPPORTED */

#if ((ADC_READ_GROUP_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON))
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

    if (PhysicalChanId < 32U)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[0U] >> PhysicalChanId) & 1UL;
    }
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 1U)
    else if (PhysicalChanId < 64U)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[1U] >> (PhysicalChanId % 32U)) & 1UL;
    }
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 1u) */
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 2U)
    else if (PhysicalChanId < 96U)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[2U] >> (PhysicalChanId % 32U)) & 1UL;
    }
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 2u) */
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 3U)
    #error "Adc IPW ADC_IPW_NUM_OF_GROUP_CHN out of range."
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 3u) */

    if (1UL == ChannelEnBit)
    {
        ReturnValue = (Std_ReturnType)E_OK;
    }

    return ReturnValue;
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
#endif /* ((ADC_READ_GROUP_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)) */

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function calculates last channel in group and return its struct value.
* @details        This function calculates last channel in group and return its struct value.
*
* @param[in]      Group                 Group index.
* @param[in]      ConversionType        Group conversion type (normal/inject/CTU).
* @param[in]      UserId                User Id.
*
* @return         AdcResultLastCh       Last channel result struct.
*
*/
static inline Adc_Sar_Ip_ChanResultType Adc_Ipw_CalculateLastChan(const Adc_GroupType Group,
                                                                  const Adc_Sar_Ip_ConvChainType ConversionType,
                                                                  const uint8 UserId)
{
    Adc_Sar_Ip_ChanResultType AdcResultLastCh;
    Adc_ChannelType LastCh;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AdcLogicalUnitId;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
#if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_OFF))
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]); /* Pointer to AdcGroup */
#endif
#ifdef ADC_DMA_SUPPORTED
    uint8 Res;
    const Adc_Sar_Ip_DataAlignedType DataAlign = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->DataAlign;
#endif /* ADC_DMA_SUPPORTED */
#if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON))
    Adc_ChannelIndexType ChannelCount;
#endif
#if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_SETCHANNEL_API == STD_ON))
    Adc_ChannelIndexType Channel;
    const Adc_Sar_Ip_ConfigType * AdcPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId];
    #if (ADC_SETCHANNEL_API == STD_ON)
        Adc_ChannelType CrtChannel;
    #else
        Std_ReturnType ChannelEnable = (Std_ReturnType)E_NOT_OK;
        Std_ReturnType ChannelExist = (Std_ReturnType)E_NOT_OK;
        Adc_GroupType GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
        Adc_ChannelType ChIndex;
    #endif /* (ADC_SETCHANNEL_API == STD_ON) */
#endif

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    #if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(ADC_DMA_SUPPORTED))
        ChannelCount = GroupPtr->AssignedChannelCount;
    #endif
#endif

    /* Without interrupts the caller doesn't know if all the conversions in the group have completed
    So first need to check if the result is valid (completed) for the channel with largest physical index (last channel),
    because ADC_SAR executes conversions in ascending order of channel index.
    If yes, then read all the channels. */
#if (ADC_SETCHANNEL_API == STD_ON)
    LastCh = AdcPtr->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[0]].ChanIndex;
    for (Channel = 1U; Channel < ChannelCount; Channel++)
    {
        CrtChannel = AdcPtr->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[Channel]].ChanIndex;
        if (CrtChannel > LastCh)
        {
            /* Calculate the last channel to configure DMA when SetChannel function is invoked */
            LastCh = CrtChannel;
        }
    }
#else
    LastCh = (Adc_ChannelType)GroupPtr->LastCh;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /* Get index of the group with AdcEnableChDisableChGroup enabled */
    GroupId = (Adc_GroupType)GroupPtr->EnableChDisableChGroupIndex;
    /* Check if group have AdcEnableChDisableChGroup enabled */
    if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupId)
    {
        for (Channel = 0U; Channel < ChannelCount; Channel++)
        {
            ChIndex = GroupPtr->AssignmentPtr[Channel];
            ChannelEnable = Adc_Ipw_IsChannelEnable(LogicalHwUnitId, GroupId, ChIndex, UserId);
            if ((Std_ReturnType)E_OK == ChannelEnable)
            {
                if ((Std_ReturnType)E_NOT_OK == ChannelExist)
                {
                    ChannelExist = (Std_ReturnType)E_OK;
                    LastCh = AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex;
                }
                if (AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex > LastCh)
                {
                    /* Calculate the last channel to check convert status when disableChannel function is invoked */
                    LastCh = AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex;
                }
            }
        }
    }
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    /* Initialize the value for AdcResultLastCh*/
    AdcResultLastCh.ConvData = 0U;
    AdcResultLastCh.AdcChnIdx = (uint8)LastCh;
    AdcResultLastCh.ValidFlag = FALSE;
    AdcResultLastCh.OverWrittenFlag = FALSE;

#ifdef ADC_DMA_SUPPORTED
    if ((ADC_DMA != Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) || (TRUE == GroupPtr->AdcWithoutDma))
    {
#endif /*ADC_DMA_SUPPORTED*/
        Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, LastCh, ConversionType, &AdcResultLastCh);
#ifdef ADC_DMA_SUPPORTED
    }
    else
    {
        /* If BypassResolution enabled, number of bits in results always are 15 even the resolution is lower than. */
        if (FALSE == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->BypassResolution)
        {
            Res = Adc_Ipw_au8AvailableResolutions[(uint8)(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->AdcResolution)];
        }
        else
        {
            Res = ADC_SAR_IP_RESULT_RESOLUTION;
        }
        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            Adc_Ipw_MaskConvResult(Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][ChannelCount - 1U], &AdcResultLastCh, FALSE, Res, DataAlign);
        }
        else
        {
            if (ADC_IPW_INVALID_DATA_RESULT_DMA != Adc_axGroupStatus[Group].ResultsBufferPtr[ChannelCount - 1U])
            {
                Adc_Ipw_MaskConvResult((uint32)Adc_axGroupStatus[Group].ResultsBufferPtr[ChannelCount - 1U], &AdcResultLastCh, TRUE, Res, DataAlign);
            }
        }
    }
#endif /*ADC_DMA_SUPPORTED*/

    return AdcResultLastCh;
}

/**
* @brief          This function records conversion result of channels in group.
* @details        This function records conversion result of channels in group.
*
* @param[in]      Group                Group index.
* @param[in]      ConversionType       Group conversion type (normal/inject/CTU).
* @param[in]      UserId               User Id.
* @param[out]     DataPtr              Pointer to a buffer which will be filled by the conversion results.
* @param[out]     Flag                 Pointer to limit check flag
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              Channel result is valid.
* @retval         E_NOT_OK          Channel result is invalid.
*
*/
static inline Std_ReturnType Adc_Ipw_GetChanResultNoInt(const Adc_GroupType Group,
                                                        const Adc_Sar_Ip_ConvChainType ConversionType,
                                                        const uint8 UserId,
                                                        Adc_ValueGroupType * DataPtr,
                                                        boolean * Flag)
{
    Adc_Sar_Ip_ChanResultType AdcResultLastCh;
    Adc_ChannelIndexType Channel;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Std_ReturnType ChannelEnable = (Std_ReturnType)E_NOT_OK;
    Adc_GroupType GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
    Adc_ChannelType ChIndex;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    const Adc_Sar_Ip_ConfigType * AdcPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId];
#ifdef ADC_DMA_SUPPORTED
    uint8 Res;
    const Adc_Sar_Ip_DataAlignedType DataAlign = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->DataAlign;
#endif /* ADC_DMA_SUPPORTED */
    Std_ReturnType ReadGroupRet = (Std_ReturnType)E_OK;
    Adc_ChannelIndexType ChannelCount;
    Adc_Sar_Ip_ChanResultType AdcResult;
    uint16 ConvData;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Flag to set if ADC results are in the selected range */
    boolean WriteFlag = TRUE;
#ifdef ADC_DMA_SUPPORTED
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    const uint32 AdcDmaLogicChId = (uint32) Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
#endif /*ADC_DMA_SUPPORTED*/
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    ChannelCount = GroupPtr->AssignedChannelCount;
#endif

#ifdef ADC_DMA_SUPPORTED
    /* If BypassResolution enabled, number of bits in results always are 15 even the resolution is lower than. */
    if (FALSE == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->BypassResolution)
    {
        Res = Adc_Ipw_au8AvailableResolutions[(uint8)(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->AdcResolution)];
    }
    else
    {
        Res = ADC_SAR_IP_RESULT_RESOLUTION;
    }
#endif /*ADC_DMA_SUPPORTED*/

    AdcResultLastCh = Adc_Ipw_CalculateLastChan(Group, ConversionType, UserId);
    if (TRUE == AdcResultLastCh.ValidFlag)
    {
        /* Result for LastCh is valid, so all conversions from the group have been completed */
        for (Channel = 0U; Channel < ChannelCount; Channel++)
        {
#if (ADC_SETCHANNEL_API == STD_ON)
            ChIndex = Adc_axRuntimeGroupChannel[Group].ChannelPtr[Channel];
#else
            ChIndex = GroupPtr->AssignmentPtr[Channel];
#endif
            if ((uint32)AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex != AdcResultLastCh.AdcChnIdx)
            {
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
                /* Get index of the group with AdcEnableChDisableChGroup enabled */
                GroupId = (Adc_GroupType) GroupPtr->EnableChDisableChGroupIndex;
                /* Check if group have AdcEnableChDisableChGroup enabled */
                if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupId)
                {
                    ChannelEnable = Adc_Ipw_IsChannelEnable(LogicalHwUnitId, GroupId, ChIndex, UserId);
                }
                else
                {
                    ChannelEnable = (Std_ReturnType)E_OK;
                }
                /* If channel is enabled, check valid and result bit */
                if ((Std_ReturnType)E_OK == ChannelEnable)
                {
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
#ifdef ADC_DMA_SUPPORTED
                    if ((ADC_DMA != Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) || (TRUE == GroupPtr->AdcWithoutDma))
                    {
#endif /*ADC_DMA_SUPPORTED*/
                        Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), ConversionType, &AdcResult);
#ifdef ADC_DMA_SUPPORTED
                    }
                    else
                    {
                        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
                        {
                            Adc_Ipw_MaskConvResult(Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][Channel], &AdcResult, FALSE, Res, DataAlign);
                        }
                        else
                        {
                            Adc_Ipw_MaskConvResult((uint32)Adc_axGroupStatus[Group].ResultsBufferPtr[Channel], &AdcResult, TRUE, Res, DataAlign);
                        }
                    }
#endif /*ADC_DMA_SUPPORTED*/

                    if (FALSE == AdcResult.ValidFlag)
                    {
                        ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                        break;
                    }
                    ConvData = AdcResult.ConvData;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
                }
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
            }
            else
            {
                /* For LastChan do not read again the result, but use the result already read */
                ConvData = AdcResultLastCh.ConvData;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
                /* The Last Channel is always enabled */
                ChannelEnable = (Std_ReturnType)E_OK;
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
            }

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
            if ((Std_ReturnType)E_OK == ChannelEnable)
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
            {
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
                if ((TRUE == GroupPtr->AdcGroupLimitcheck)
#if (ADC_SETCHANNEL_API == STD_ON)
                    || (TRUE == Adc_axRuntimeGroupChannel[Group].AdcRuntimeGroupLimitcheck)
#endif /* ADC_SETCHANNEL_API == STD_ON */
                   )
                {
                    (*Flag) = Adc_Ipw_CheckConversionValuesInRange(ConvData, LogicalHwUnitId, ChIndex, UserId);
                    if (FALSE == (*Flag))
                    {
                        /* SWS_Adc_00448, SWS_Adc_00449, SWS_Adc_00450 */
                        Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
                        ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                        WriteFlag = FALSE;
#ifdef ADC_DMA_SUPPORTED
                        if ((ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) && ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable))
                        {
                            /* If the Result Conversion is out of range, need to reset Destination Address to previous Buffer Address. */
                            /* Because the Destination Offset for Streaming Group that has one channel configured be 4U to reducing additional in the callback. */
                            if (GroupPtr->AccessMode == ADC_ACCESS_MODE_STREAMING)
                            {
                                LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                                (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                            }
                        }
#endif /*ADC_DMA_SUPPORTED*/
                    }
                    else
                    {
                        Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
                    }
                }
                if (TRUE == WriteFlag)
#else
                (*Flag) = TRUE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
                {
                    DataPtr[Channel] = ConvData;
                }
            }
        }
#ifdef ADC_DMA_SUPPORTED
        if ((ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) && (GroupPtr->AdcWithoutDma == FALSE))
        {
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* Because all conversions were completed so need to reset last buffer to invalid value before starting next conversion */
                Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][(ChannelCount - 1U)] = ADC_IPW_INVALID_DATA_RESULT_DMA;
            }
            else
            {
                Adc_axGroupStatus[Group].ResultsBufferPtr[(ChannelCount - 1U)] = ADC_IPW_INVALID_DATA_RESULT_DMA;
            }
        }
#endif /* ADC_DMA_SUPPORTED */
    }
    else
    {
        ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    }

    return ReadGroupRet;
}

/**
* @brief          This function reads the converted data for the requested group without interrupt.
* @details        Reads the converted data for the requested group.
*
* @param[in]      Group           The group number.
* @param[out]     DataPtr         Pointer to a buffer which will be filled by the conversion results.
* @param[out]     Flag            Pointer to limit check flag
* @param[in]      UserId          Current UserId.
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*/
static inline Std_ReturnType Adc_Ipw_ReadGroupNoInt(const Adc_GroupType Group,
                                                    Adc_ValueGroupType * DataPtr,
                                                    boolean * Flag,
                                                    uint8 UserId)
{
    Std_ReturnType ReadGroupRet = (Std_ReturnType)E_OK;
    Adc_Sar_Ip_ConvChainType ConversionType;
    boolean bCompletedConvChain = FALSE;
    uint32 IsrFlags = 0U;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];

    IsrFlags = Adc_Sar_Ip_GetStatusFlags(PhysicalHwUnitId);
#if (ADC_HW_TRIGGER_API == STD_ON)
    if ((ADC_TRIGG_SRC_SW != GroupPtr->TriggerSource) && (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType) ADC_IPW_MAX_CTU_TRIG_SOURCE_ID))
    {
        ConversionType = ADC_SAR_IP_CONV_CHAIN_CTU;
        if ((IsrFlags & ADC_SAR_IP_NOTIF_FLAG_CTU_EOC) != 0U)
        {
            bCompletedConvChain = TRUE;
        }
    }
    else
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    {
        ConversionType = (Adc_Sar_Ip_ConvChainType)GroupPtr->Type;
        if (((ADC_SAR_IP_CONV_CHAIN_NORMAL == ConversionType) && ((IsrFlags & ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN) != 0U)) || \
            ((ADC_SAR_IP_CONV_CHAIN_INJECTED == ConversionType) && ((IsrFlags & ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN) != 0U)) \
           )
        {
            bCompletedConvChain = TRUE;
        }
    }

    if (TRUE == bCompletedConvChain)
    {
        ReadGroupRet = Adc_Ipw_GetChanResultNoInt(Group, ConversionType, UserId, DataPtr, Flag);
    }
    else
    {
        ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    }

    return ReadGroupRet;
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_DmaClearPendingReq(const uint32 DmaLogicChannel)
{
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[12U];

    /* Prepare for Software TCD Configuration:
    0. Source Address (SADDR): Address of Draft Buffer.
    1. Source Transfer Size (SSIZE): Number of bytes to read each time.
    2. Source Address Offset (SOFF): Each source read is completed,
        this value will be added to the current source address (Signed).
    3. Destination Address (DADDR): Address of Draft Buffer (same with SADDR)
    4. Destination Transfer Size (DSIZE): Number of bytes to write each time.
    5. Destination Address Offset (DOFF): Each destination write is completed,
        this value will be added to the current destination address (Signed).
    6. Minor Loop Size (NBYTES): number of bytes to transfer per service request.
    7. Major Loop Count (CITER): Number of minor loop in a major loop.
    8. Start to Transfer by Software (TCDn_CSR.START).
    9. Enable Major Interrupt (INTMAJOR): Enable Interrupt If Major count complete.
    10. Enable Half Major Interrupt (INTHALF): Enable Interrupt If Major Counter Half-complete
    11. Disable Automatic Hardware Request (DREQ): clear automatically the ERQ bit.
    */
    LocTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    LocTransferList[0].Value = (uint32)&Adc_Ipw_u8DmaDraftBuffer;
    LocTransferList[1].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    LocTransferList[1].Value = (uint32)0U; /* 1 Bytes */
    LocTransferList[2].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    LocTransferList[2].Value = (uint32)0U;
    LocTransferList[3].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    LocTransferList[3].Value = (uint32)&Adc_Ipw_u8DmaDraftBuffer;
    LocTransferList[4].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    LocTransferList[4].Value = (uint32)0U; /* 1 Bytes */
    LocTransferList[5].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    LocTransferList[5].Value = (uint32)0U;
    LocTransferList[6].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    LocTransferList[6].Value = (uint32)1U; /* 1 Bytes*/
    LocTransferList[7].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    LocTransferList[7].Value = (uint32)1U;
    LocTransferList[8].Param = DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST;
    LocTransferList[8].Value = 0U; /* FALSE */
    LocTransferList[9].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    LocTransferList[9].Value = 0U; /* FALSE */
    LocTransferList[10].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
    LocTransferList[10].Value = 0U; /* FALSE */
    LocTransferList[11].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    LocTransferList[11].Value = 1U; /* TRUE */

    (void)Dma_Ip_SetLogicChannelTransferList(DmaLogicChannel, LocTransferList, 12U);
    (void)Dma_Ip_SetLogicChannelCommand(DmaLogicChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    (void)Dma_Ip_SetLogicChannelCommand(DmaLogicChannel, DMA_IP_CH_SET_SOFTWARE_REQUEST);
    /* Major Elink bit only enabled when DONE bit is cleared */
    (void)Dma_Ip_SetLogicChannelCommand(DmaLogicChannel, DMA_IP_CH_CLEAR_DONE);
}


static inline uint32 Adc_Ipw_GetDataAddress(const Adc_HwUnitType PhysicalHwUnitId,
                                            const uint8 PhysChannelId)
{
    uint32 DataAddress;

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        DataAddress = Sdadc_Ip_GetDataAddress((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        DataAddress = Adc_Sar_Ip_GetDataAddress(PhysicalHwUnitId, PhysChannelId);
    }

    return DataAddress;
}


static inline uint32 Adc_Ipw_GetDataOffset(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                           const Adc_HwUnitType LogicalHwUnitId,
                                           const Adc_HwUnitType PhysicalHwUnitId)
{
    /* The source offset is no needed for AdcSar and Sdadc Fifo. Only apply for SdAdc with DSPSS enabled */
    uint32 DataOffset = 0U;

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
    /* Check if this unit is SDADC with DSPSS enabled */
    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        if (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
        {
            /* Auto add 2 to get next address in the DSPSS Dma read buffer */
            DataOffset = (uint32)2U;
        }
    }
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */

    /* Avoid compiler warnings */
    (void)AdcIpwConfigPtr;
    (void)LogicalHwUnitId;
    (void)PhysicalHwUnitId;

    return DataOffset;
}


#if ( (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) )

static inline void Adc_Ipw_SetupTcdSingleAdcChannelMajorLink(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                             const Adc_GroupConfigurationType * const GroupPtr,
                                                             const Adc_HwUnitType PhysicalHwUnitId)
{
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const uint32 AdcDmaLogicChId         = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    /* Link to counting DMA channel to transfer results from Adc_Ipw_au32DmaNoIrqBuffer to buffer setup by user.
     Use extra transfer via Adc_Ipw_au32DmaNoIrqBuffer to allow usage of ReadGroup */
    const uint32 AdcCountingDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[LogicalHwUnitId];

    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[2U];
    uint32 MajorLinkEnable = 0U;  /* FALSE */

    if (
         (
            /* Stream without interrupt */
           ((uint8)STD_ON             == GroupPtr->AdcWithoutInterrupt) &&
           (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
         )
#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
         ||
         (
            /* Stream optimized DMA with DSPSS enabled */
           (TRUE == GroupPtr->AdcOptimizeDmaStream) &&
           (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) &&
           (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
         )
#endif /* STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS */
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
       )
    {
        MajorLinkEnable = 1U;  /* TRUE */
    }

    /* Configure major linking */
    LocTransferList[0U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
    LocTransferList[0U].Value = MajorLinkEnable;
    LocTransferList[1U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
    LocTransferList[1U].Value = AdcCountingDmaLogicChId;

    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 2U);

    /* Avoid compiler warning */
    (void)PhysicalHwUnitId;
}

#endif /* (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */


#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

static inline uint32 Adc_Ipw_GetDspssThreadOutputBufferLength(const Adc_HwUnitType PhysicalHwUnitId)
{
    /* Get thread output buffer length*/
    return DSPSS_ThreadGetOutputBufferLength((uint32)PhysicalHwUnitId);
}

static inline void Adc_Ipw_SetupTcdLastSourceAddressOffset(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                           const Adc_GroupConfigurationType * const GroupPtr)
{
    const Adc_HwUnitType LogicalHwUnitId  = GroupPtr->AdcLogicalUnitId;
    const uint32 AdcDmaLogicChId          = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    const Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    uint32 LastSourceAddressOffset        = 0U;  /* Initial value is 0 to disable adjustment if it was previously used for another group */
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];

    /* Check if this unit is SDADC with DSPSS enabled */
    if ( (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) &&
         (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
       )
    {
        /* Check if this group is in without interrupt mode or optimized DMA */
        if (
              ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
              ||
              (TRUE == GroupPtr->AdcOptimizeDmaStream)
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
           )
        {
            /* Adjust last source address to the beginning of DSPSS output buffer */
            LastSourceAddressOffset = ADC_IPW_GET_COMPLEMENT_OF_2(Adc_Ipw_GetDspssThreadOutputBufferLength(PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET));
        }
    }

    /* Setup last source address offset */
    LocTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
    LocTransferList[0U].Value = LastSourceAddressOffset;

    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
}

#if ((STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS))

static inline void Adc_Ipw_SetupTcdSingleAdcChannelMinorLink(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                             const Adc_GroupConfigurationType * const GroupPtr)
{
    const Adc_HwUnitType LogicalHwUnitId  = GroupPtr->AdcLogicalUnitId;
    const uint32 AdcDmaLogicChId          = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    const Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    const uint32 AdcCountingDmaLogicChId  = AdcIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[LogicalHwUnitId];

    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[2U];
    uint32 LocTransferListNumElems = 1U;
    uint32 MinorLinkEnable         = 0U;  /* Initial value is FALSE to disable linking if it was previously enabled for another group */

    /* Check if this unit is SDADC with DSPSS enabled */
    if ( (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) &&
         (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
       )
    {
        /* Check if this group is in circular access mode without interrupt OR optimized DMA mode */
        if (
             (
               ((uint8)STD_ON             == GroupPtr->AdcWithoutInterrupt) &&
               (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
             )
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
             ||
             (
               (TRUE == GroupPtr->AdcOptimizeDmaStream)
             )
#endif /* STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS */
           )
        {
            MinorLinkEnable  = 1U; /* TRUE */
        }
    }

    /* Setup minor linking */
    LocTransferList[0U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
    LocTransferList[0U].Value = MinorLinkEnable;
    /* Only configure link channel number in case minor linking is enabled to avoid impacting BITER value */
    if (0U != MinorLinkEnable)
    {
        LocTransferList[1U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
        LocTransferList[1U].Value = AdcCountingDmaLogicChId;
        LocTransferListNumElems   = 2U;
    }

    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, LocTransferListNumElems);
}

#endif /* (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */


static inline void Adc_Ipw_SetupTcdSingleAdcChannel(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                    const Adc_GroupConfigurationType * const GroupPtr,
                                                    uint8 PhysChannelId)
{
    const uint32 LocTransferListNumElems = 13U;
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[13U];
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    const Adc_GroupType Group = GroupPtr->GroupId;
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    const Adc_StreamNumSampleType GroupNumSample = GroupPtr->NumSamples;
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */

    /* Prepare for Software TCD Configuration:
    0. Source Address (SADDR): Starting address of the first ADC channel.
    1. Source Transfer Size (SSIZE): Number of bytes to read each time.
    2. Source Address Offset (SOFF): Each source read is completed,
        this value will be added to the current source address (Signed).
    3. Destination Address (DADDR): Address of Group Buffer.
    4. Destination Transfer Size (DSIZE): Number of bytes to write each time.
    5. Destination Address Offset (DOFF): Each destination write is completed,
        this value will be added to the current destination address (Signed).
    6. Minor Loop Size (NBYTES): number of bytes to transfer per service request.
    7. Major Loop Count (CITER): Number of minor loop in a major loop.
    8. Start to Transfer by Software (TCDn_CSR.START).
    9. Enable Major Interrupt (INTMAJOR): Enable Interrupt If Major count complete.
    10. Enable Half Major Interrupt (INTHALF): Enable Interrupt If Major Counter Half-complete
    11. Disable Automatic Hardware Request (DREQ): clear automatically the ERQ bit.
    Other fields upto type of the group:
    - The Destination Signed Last Address Adjustment (DLAST_SGA): The DADDR will be calculated automatically when a major done.
    - The Major Loop Enable Link (TCDn_BITER_ELINKYES.ELINK): Enable Linking Channel
    - The Major Loop Logic Channel Link (TCDn_BITER_ELINKYES.LINKCH): The DMA Channel Logic ID
    */
    LocTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    LocTransferList[0].Value = Adc_Ipw_GetDataAddress(PhysicalHwUnitId, PhysChannelId);
    LocTransferList[1].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    LocTransferList[1].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
    LocTransferList[2].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    LocTransferList[2].Value = Adc_Ipw_GetDataOffset(AdcIpwConfigPtr, LogicalHwUnitId, PhysicalHwUnitId);
    LocTransferList[3].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    LocTransferList[3].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[0]));
    LocTransferList[4].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    LocTransferList[4].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;
    LocTransferList[5].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    if (GroupPtr->AccessMode == ADC_ACCESS_MODE_STREAMING)
    {
        LocTransferList[5].Value = (uint32)2U; /* Auto add 2 bytes to get address of next Result Buffer */
    }
    else
    {
        LocTransferList[5].Value = (uint32)0U; /* Single Sample doesn't need this offset. */
    }
    LocTransferList[6].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    LocTransferList[6].Value = (uint32)2U; /* 2 Bytes*/
    LocTransferList[7].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    LocTransferList[7].Value = (uint32)1U;
    LocTransferList[8].Param = DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST;
    LocTransferList[8].Value = 0U; /* FALSE */
    LocTransferList[9].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    LocTransferList[9].Value = 1U; /* TRUE */
    LocTransferList[10].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
    LocTransferList[10].Value = 0U; /* FALSE */
    LocTransferList[11].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    LocTransferList[11].Value = 1U; /* TRUE */
    LocTransferList[12].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    LocTransferList[12].Value = (uint32)0U;

#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    if (TRUE == GroupPtr->AdcOptimizeDmaStream)
    {
        /* Overwrite settings for optimized mode */
#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
            if ( (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) &&
                 (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
               )
            {
                /* Overwrite settings for SDADC with DSPSS enabled */
                LocTransferList[3].Value  = (uint32)(&(Adc_Ipw_au32DmaIntermediateBuffer[PhysicalHwUnitId][0U]));
                LocTransferList[5].Value  = 0U;                             /* No increment, because only one channel is continuously transferred into one element in the intermediate buffer */
                LocTransferList[7].Value  = Adc_Ipw_GetDspssThreadOutputBufferLength(PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) >> 1U;  /* Major count = Number of samples (1 sample = 2 bytes) */
                LocTransferList[9].Value  = 0U;                             /* FALSE: major interrupt disabled */
                LocTransferList[11].Value = 0U;                             /* FALSE: keep hardware request enabled */
            }
            else
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
            {
                /* Overwrite settings for other cases (e.g. ADCSAR and SDADC with DSPSS disabled) */
                LocTransferList[7].Value  = (uint32)GroupNumSample;                                     /* DMA_IP_CH_SET_MAJORLOOP_COUNT */
                LocTransferList[10].Value = GroupPtr->HalfInterrupt ? 1U : 0U;                          /* DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT */
                LocTransferList[12].Value = ADC_IPW_GET_COMPLEMENT_OF_2((uint32)GroupNumSample << 1U);  /* DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ */
            }
    }
    else
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
    {
        if ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt)
        {
            /* Common settings for without interrupt mode */
            LocTransferList[3].Value  = (uint32)(&(Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][0U]));
            LocTransferList[5].Value  = 0U; /* No needed, because only one channel is continuously transferred into one element in the internal buffer */
            LocTransferList[9].Value  = 0U; /* FALSE */
            LocTransferList[11].Value = 0U; /* FALSE */

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
            if ( (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) &&
                 (NULL_PTR != AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->DspssConfig)
               )
            {
                /* Overwrite settings for SDADC with DSPSS enabled */
                LocTransferList[1].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE     : Read 2 bytes from XMEM */
                LocTransferList[4].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE: Write 2 bytes to internal buffer */
                LocTransferList[6].Value = 2U;                             /* DMA_IP_CH_SET_MINORLOOP_SIZE           : Transfer 2 bytes each minor loop (i.e. a Dma request) */
                LocTransferList[7].Value = Adc_Ipw_GetDspssThreadOutputBufferLength(PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET) >> 1U;  /* Major count = Number of samples (1 sample = 2 bytes) */
            }
            else
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
            {
                /* Overwrite settings for other cases (e.g. ADCSAR and SDADC with DSPSS disabled) */
                LocTransferList[1].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;  /* Read 4 bytes from hardware register */
                LocTransferList[4].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;  /* Write 4 bytes to interrup buffer */
                LocTransferList[6].Value = 4U; /* DMA_IP_CH_SET_MINORLOOP_SIZE: Transfer 4 Bytes each minor loop (i.e. a Dma request) */
            }
        }
    }

#if ( (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) )
    /* Setup channel major linking */
    Adc_Ipw_SetupTcdSingleAdcChannelMajorLink(AdcIpwConfigPtr, GroupPtr, PhysicalHwUnitId);
#endif /* (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
    /* Setup last source address adjusment */
    Adc_Ipw_SetupTcdLastSourceAddressOffset(AdcIpwConfigPtr, GroupPtr);

#if ((STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS))
    /* Setup channel minor linking */
    Adc_Ipw_SetupTcdSingleAdcChannelMinorLink(AdcIpwConfigPtr, GroupPtr);
#endif /* (STD_ON == ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER) || (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
    Adc_Ipw_SetupTcdSingleAdcChannelDmaConfig(AdcDmaLogicChId, LocTransferList, LocTransferListNumElems);

}
static inline void Adc_Ipw_SetupTcdSingleAdcChannelDmaConfig(const uint32 AdcDmaLogicChId,
                                                             const Dma_Ip_LogicChannelTransferListType LocTransferList[],
                                                             const uint32 LocTransferListNumElems)
{
    /* Configure Dma transfer settings */
    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, LocTransferListNumElems);
    /* Enable Hardware Request for Dma */
    (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

static inline void Adc_Ipw_SetupTcdMultiAdcChannel(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                   const Adc_GroupConfigurationType * const GroupPtr,
                                                   Adc_ChannelIndexType ChannelCount)
{
    uint8 Index;
    uint8 PhysChannelId;
    uint8 LocTransferListNumElems;
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[15U];
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    const uint32 AdcCountingDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[LogicalHwUnitId];
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_StreamNumSampleType GroupNumSample = GroupPtr->NumSamples;
    const uint32 NumSgaElement = AdcIpwConfigPtr->Mapping.DmaNumSgaElement[LogicalHwUnitId];
    const Adc_Sar_Ip_ConfigType * AdcPtr = AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId];

    /* Prepare for Software TCD Configuration:
    0. Source Address (SADDR): Starting address of the first ADC channel
    1. Source Transfer Size (SSIZE): Number of bytes to read each time.
    2. Source Address Offset (SOFF): Each source read is completed,
        this value will be added to the current source address (Signed).
    3. Destination Address (DADDR): Address of Group Buffer.
    4. Destination Transfer Size (DSIZE): Number of bytes to write each time.
    5. Destination Address Offset (DOFF): Each destination write is completed,
        this value will be added to the current destination address (Signed).
    6. Minor Loop Size (NBYTES): number of bytes to transfer per service request.
    7. Major Loop Count (CITER): Number of minor loop in a major loop.
    8. Start to Transfer by Software (TCDn_CSR.START).
    9. Enable Major Interrupt (INTMAJOR): Enable Interrupt If Major count complete.
    10. Enable Half Major Interrupt (INTHALF): Enable Interrupt If Major Counter Half-complete
    11. Disable Automatic Hardware Request (DREQ): clear automatically the ERQ bit.
    Other fields upto type of the group:
    - The Destination Signed Last Address Adjustment (DLAST_SGA): The DADDR will be calculated automatically when a major done.
    - The Major Loop Enable Link (TCDn_BITER_ELINKYES.ELINK): Enable Linking Channel
    - The Major Loop Logic Channel Link (TCDn_BITER_ELINKYES.LINKCH): The DMA Channel Logic ID
    */
    for (Index = 0; Index < ChannelCount; Index++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        PhysChannelId = AdcPtr->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[Index]].ChanIndex;
#else
        PhysChannelId = AdcPtr->ChannelConfigsPtr[GroupPtr->AssignmentPtr[Index]].ChanIndex;
#endif
        LocTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        LocTransferList[0].Value = Adc_Sar_Ip_GetDataAddress(PhysicalHwUnitId, PhysChannelId);
        LocTransferList[1].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        LocTransferList[1].Value = (uint32)1U; /* 2 Bytes */
        LocTransferList[2].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        LocTransferList[2].Value = (uint32)0U;
        LocTransferList[3].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        /* Overwritten below if necessary */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        if (FALSE == GroupPtr->StreamResultGroupMultiSets)
        {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
            LocTransferList[3].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Index * GroupNumSample]));
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        }
        else
        {
            LocTransferList[3].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Index]));
        }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        LocTransferList[4].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        LocTransferList[4].Value = (uint32)1U; /* 2 Bytes */
        LocTransferList[5].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        LocTransferList[5].Value = (uint32)0U;
        LocTransferList[6].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
        LocTransferList[6].Value = (uint32)2U;
        LocTransferList[7].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        LocTransferList[7].Value = (uint32)1U;
        LocTransferList[8].Param = DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST;
        /* See below */
        LocTransferList[9].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
        /* See below */
        LocTransferList[10].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
        LocTransferList[10].Value = 0U; /* FALSE */
        LocTransferList[11].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
        LocTransferList[11].Value = 1U; /* TRUE */
        LocTransferListNumElems = 12U;
        /* If this is the first TCD configuration */
        if (0U == Index)
        {
            LocTransferList[8].Value = 0U; /* FALSE */
            LocTransferList[9].Value = 0U; /* FALSE */
        }
        /* If this is the last TCD configuration */
        else if (Index == (ChannelCount - 1U))
        {
            LocTransferList[8].Value = 1U; /* TRUE */
            LocTransferList[9].Value = 1U; /* TRUE */
        }
        else
        {
            LocTransferList[8].Value = 1U; /* TRUE */
            LocTransferList[9].Value = 0U; /* FALSE */
        }
        if ( \
                ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
            || (TRUE == GroupPtr->AdcOptimizeDmaStream)
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
           )
        {
            LocTransferList[1].Value = (uint32)2U; /* 4U Bytes because 2 is the ADC result register size and 2 are additional info Adc_Ipw_au32DmaNoIrqBuffer because needed for ReadGroup*/
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
            if (TRUE == GroupPtr->AdcOptimizeDmaStream)
            {
                LocTransferList[3].Value = (uint32)(&(Adc_Ipw_au32DmaIntermediateBuffer[PhysicalHwUnitId][Index])); /* Transfer results in internal buffer first */
            }
            else
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
            {
                LocTransferList[3].Value = (uint32)(&(Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][Index])); /* Transfer results in internal buffer first */
            }
            LocTransferList[4].Value = (uint32)2U; /* 4U Bytes because 2 is the ADC result register size and 2 are additional info Adc_Ipw_au32DmaNoIrqBuffer because needed for ReadGroup*/
            LocTransferList[6].Value = (uint32)4U; /* 4U Bytes because 2 is the ADC result register size and 2 are additional info Adc_Ipw_au32DmaNoIrqBuffer because needed for ReadGroup*/
            LocTransferList[9].Value = 0U; /* FALSE */
            LocTransferList[11].Value = 0U; /* FALSE */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
            /* No other type of DMA STREAMING without interrupt supported */
            if ( \
                    ((GroupPtr->AccessMode == ADC_ACCESS_MODE_STREAMING) && ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt))
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
                || (TRUE == GroupPtr->AdcOptimizeDmaStream)
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
               )
            {
                /* For groups withoutInterrupt and streaming, all channel results for 1 sample are transferred using SG into an internal buffer.
                From this internal buffer, after each sample complete, transfer using linked AdcCountingDmaChanLogicId all samples into buffer registered via SetupResultBuffer. */
                if (Index == (ChannelCount - 1U))
                {
                    LocTransferList[12].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
                    LocTransferList[12].Value = 1U; /* TRUE */
                    LocTransferList[13].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
                    LocTransferList[13].Value = AdcCountingDmaLogicChId;
                }
                else
                {
                    LocTransferList[12].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
                    LocTransferList[12].Value = 0U; /* FALSE */
                    LocTransferList[13].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
                    LocTransferList[13].Value = 0U;
                }
                LocTransferListNumElems = 14U;
            }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        }
        /* Write TCD Configuration for each channel */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(AdcDmaLogicChId, Index, LocTransferList, LocTransferListNumElems);

        /* When number of element of Scatter Gather List is greater than number of channel of current group, the next TCD should not use */
        if ((Index == (ChannelCount - 1U)) && (Index < (NumSgaElement - 1U)))
        {
            LocTransferList[8].Value = 0U; /* FALSE */
            /* Disable start bit of the next tcd in case it was enabled earlier by a larger group.*/
            (void)Dma_Ip_SetLogicChannelScatterGatherList(AdcDmaLogicChId, ((uint32)Index + 1U), LocTransferList, LocTransferListNumElems);
        }
    }
    /* Write the first Software TCD to the Hardware. The next one will be loaded automaticaly by Scatter/Gather Programming */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(AdcDmaLogicChId, 0U);
    /* Enable Hardware Request for Dma */
    (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/**
* @brief        This function configures the DMA Transfer involved in the ADC conversion process.
* @details      This function configures the Dma Ip to Transfer data from Data Register to Result Buffer.
*               It should be called with the ADC Unit on standby (no ADC interrupt event allowed
*               because its code is not protected by critical regions) - no conversions is ongoing.
*
* @param[in]    Unit        The Adc Logical Unit Id.
* @param[in]    UserId   Current UserId
*
* @return       void
*
* @pre  ADC Unit is in stand by, there is no ongoing conversion.
*/
static inline void Adc_Ipw_StartDmaOperation(uint8 Unit,
                                             Adc_GroupType Group,
                                             uint8 UserId)
{
    uint8 Index;
    uint8 PhysChannelId;
    Adc_ChannelIndexType ChannelCount;
    const Adc_Ipw_Config * LocIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
    const Adc_HwUnitType PhysicalHwUnitId = LocIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group]; /* Group index in each partition */
    const uint32 AdcDmaLogicChId = LocIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    const Adc_GroupConfigurationType * LocGroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]); /* Pointer to AdcGroup */
    const Adc_Sar_Ip_ConfigType * AdcPtr = LocIpwConfigPtr->AdcConfigPtrArr[Unit];
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    Dma_Ip_LogicChannelScatterGatherListType CountingDmaLocTransferList[16U];
    const uint32 AdcCountingDmaLogicChId = LocIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[Unit];
    Adc_StreamNumSampleType GroupNumSample = LocGroupPtr->NumSamples;
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    /* Only needed for AdcSar units */
    if (PhysicalHwUnitId < ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* Clear DMA Request to make sure there is not any pending request */
        /* To clear pending request from ADC, need to force DMA Clear Source Mode to be Clearing of DMA Request on Acknowledgment from DMA Controller.
        Clear on Read means actually clear on read from ADC Data Register, and because the dummy transfer (Adc_Ipw_DmaClearPendingReq) does not read from ADC Data Register, the ADC request to DMA doesn't get cleared at all (unless configured as CLEAR ON ACK) */
        Adc_Sar_Ip_SetDmaClearSource(PhysicalHwUnitId, ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK);
        Adc_Ipw_DmaClearPendingReq(AdcDmaLogicChId);

        /* Back to previous configuration */
        Adc_Sar_Ip_SetDmaClearSource(PhysicalHwUnitId, AdcPtr->DmaClearSource);
    }

    /* Get number of channel in the Group */
#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    ChannelCount = LocGroupPtr->AssignedChannelCount;
#endif

    if ((uint8)STD_ON == LocGroupPtr->AdcWithoutInterrupt)
    {
        /* Reset Adc_Ipw_au32DmaNoIrqBuffer when enabling the group, because this buffer is used by ReadGroup to check that conversions are complete and results available */
        for (Index = 0; Index < ADC_MAX_CHANNEL_PER_HW_UNIT; Index++)
        {
            Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][Index] = ADC_IPW_INVALID_DATA_RESULT_DMA;
        }
    }

    /* For each channel in the list of ADC Channels in the Group, driver will configure the TCD in the Dma Ip driver.
    Depend on ChannelCount, driver uses Scatter/Gather Format (TCDn_CSR[ESG]=1, ChannelCount > 1) or Normal Format
    (TCDn_CSR[ESG]=0, ChannelCount=1). Associates one Software TCD for each Adc channel. Note that in Scatter/Gather,
    user have to configure number of elements be equivalent to ChannelCount, for more detail please see User Manual. */
    /* If there is more than one channel in the group */
    if (1U < ChannelCount)
    {
        Adc_Ipw_SetupTcdMultiAdcChannel(LocIpwConfigPtr, LocGroupPtr, ChannelCount);
    }
    /* If there is only one channel in the group, use normal TCD format instead of Scatter/Gather format */
    else
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        PhysChannelId = AdcPtr->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[0]].ChanIndex;
#else
        PhysChannelId = AdcPtr->ChannelConfigsPtr[LocGroupPtr->AssignmentPtr[0]].ChanIndex;
#endif
        Adc_Ipw_SetupTcdSingleAdcChannel(LocIpwConfigPtr, LocGroupPtr, PhysChannelId);
    }

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    /* Configure Counting DMA channel to transfer results from Adc_Ipw_au32DmaNoIrqBuffer to buffer setup by user.
     Streaming results reorder feature must be enabled to allow running without interrupts for groups with ChannelCount > 1, and also ChannelCount == 1, but for the latter reorder is not necessary to be enabled at group level. */
    if ( \
            ((LocGroupPtr->AccessMode == ADC_ACCESS_MODE_STREAMING) && ((uint8)STD_ON == LocGroupPtr->AdcWithoutInterrupt))
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
         || ((TRUE == LocGroupPtr->AdcOptimizeDmaStream)
              &&
              (
                (ChannelCount > 1U)
#if (STD_ON == ADC_IPW_SDADC_IS_USED)
#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
                ||
                (
                  (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
                  &&
                  (NULL_PTR != LocIpwConfigPtr->SdadcConfigPtrArr[ LocGroupPtr->AdcLogicalUnitId ]->DspssConfig)
                )
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
#endif /* (STD_ON == ADC_IPW_SDADC_IS_USED) */
              )
            )
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
       )
    {
        /* Prepare for Software TCD Configuration:
        0. Source Address (SADDR): Address of Internal Buffer.
        1. Source Transfer Size (SSIZE): Number of bytes to read each time.
        2. Source Address Offset (SOFF): Each source read is completed,
            this value will be added to the current source address (Signed).
        3. Destination Address (DADDR): Address of Group Buffer.
        4. Destination Transfer Size (DSIZE): Number of bytes to write each time.
        5. Destination Address Offset (DOFF): Each destination write is completed,
            this value will be added to the current destination address (Signed).
        6. Minor Loop Size (NBYTES): number of bytes to transfer per service request.
        7. Major Loop Count (CITER): Number of minor loop in a major loop.
        8. Start to Transfer by Software (TCDn_CSR.START).
        9. Enable Major Interrupt (INTMAJOR): Enable Interrupt If Major count complete.
        10. Enable Half Major Interrupt (INTHALF): Enable Interrupt If Major Counter Half-complete
        11. Disable Automatic Hardware Request (DREQ): clear automatically the ERQ bit.
        Other fields upto type of the group:
        - The Destination Signed Last Address Adjustment (DLAST_SGA): The DADDR will be calculated automatically when a major done.
        - The Major Loop Enable Link (TCDn_BITER_ELINKYES.ELINK): Enable Linking Channel
        - The Major Loop Logic Channel Link (TCDn_BITER_ELINKYES.LINKCH): The DMA Channel Logic ID
        */
        if ((1U == ChannelCount) || ((ChannelCount > 1U) && (TRUE == LocGroupPtr->StreamResultGroupMultiSets)))
        {
            CountingDmaLocTransferList[0].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
            if (TRUE == LocGroupPtr->AdcOptimizeDmaStream)
            {
                CountingDmaLocTransferList[0].Value = (uint32)&(Adc_Ipw_au32DmaIntermediateBuffer[PhysicalHwUnitId][0U]);
            }
            else
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
            {
                CountingDmaLocTransferList[0].Value = (uint32)&(Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][0U]);
            }
            CountingDmaLocTransferList[1].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
            CountingDmaLocTransferList[1].Value = (uint32)1U; /* 2 Bytes */
            CountingDmaLocTransferList[2].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
            CountingDmaLocTransferList[2].Value = (uint32)4U; /* move by 4 Bytes, instead of 2 because they are store in Adc_Ipw_au32DmaNoIrqBuffer because needed for ReadGroup, but must not be in final result buffer */
            CountingDmaLocTransferList[3].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
            CountingDmaLocTransferList[3].Value = (uint32) & (Adc_axGroupStatus[Group].ResultsBufferPtr[0U]);
            CountingDmaLocTransferList[4].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
            CountingDmaLocTransferList[4].Value = (uint32)1U; /* 2 Bytes */
            CountingDmaLocTransferList[5].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
            CountingDmaLocTransferList[5].Value = (uint32)2U; /* 2U because this is ADC result register size. */
            CountingDmaLocTransferList[6].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
            CountingDmaLocTransferList[6].Value = (uint32)ChannelCount << 1UL; /* multiply by 2U because this is the ADC result data size */
            CountingDmaLocTransferList[7].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
            CountingDmaLocTransferList[7].Value = (uint32)GroupNumSample;

            CountingDmaLocTransferList[8].Param = DMA_IP_CH_SET_MINORLOOP_EN_SRC_OFFSET;
            CountingDmaLocTransferList[8].Value = 1U; /* TRUE */
            CountingDmaLocTransferList[9].Param = DMA_IP_CH_SET_MINORLOOP_SIGNED_OFFSET;
            CountingDmaLocTransferList[9].Value = ADC_IPW_GET_COMPLEMENT_OF_2((uint32)ChannelCount << 2UL); /* multiply by 4U because 2 is the ADC result register size and 2 are additional info Adc_Ipw_au32DmaNoIrqBuffer because needed for ReadGroup*/

            CountingDmaLocTransferList[10].Param = DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST;
            CountingDmaLocTransferList[10].Value = 0U; /* FALSE */
            CountingDmaLocTransferList[11].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
            CountingDmaLocTransferList[11].Value = 0U; /* FALSE */
            CountingDmaLocTransferList[12].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
            CountingDmaLocTransferList[12].Value = 0U; /* FALSE */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
            if (TRUE == LocGroupPtr->AdcOptimizeDmaStream)
            {
                CountingDmaLocTransferList[11].Value = 1U; /* TRUE */
                CountingDmaLocTransferList[12].Value = LocGroupPtr->HalfInterrupt ? 1U : 0U;
            }
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
            CountingDmaLocTransferList[13].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
            CountingDmaLocTransferList[13].Value = 1U; /* TRUE */
            CountingDmaLocTransferList[14].Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
            CountingDmaLocTransferList[14].Value = ADC_IPW_GET_COMPLEMENT_OF_2((uint32)ChannelCount << 2UL); /* multiply by 4U because 2 is the ADC result register size and 2 are additional info Adc_Ipw_au32DmaNoIrqBuffer because needed for ReadGroup*/
            CountingDmaLocTransferList[15].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
            CountingDmaLocTransferList[15].Value = ADC_IPW_GET_COMPLEMENT_OF_2(((uint32)ChannelCount * (uint32)GroupNumSample) << 1U); /* multiply by 2U because this is the ADC result data size */

            (void)Dma_Ip_SetLogicChannelTransferList(AdcCountingDmaLogicChId, CountingDmaLocTransferList, 16U);
            /* Enable Hardware Request for Counting Dma channel */
            (void)Dma_Ip_SetLogicChannelCommand(AdcCountingDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
        }
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
}

#if (ADC_DEINIT_API == STD_ON)
static inline void Adc_Ipw_DmaClearHwRequest(uint8 UserId,
                                             Adc_HwUnitType LogicalHwUnitId)
{
    Adc_GroupType GroupIter = 0U;

    if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId])
    {
        for (GroupIter = 0U; GroupIter < (Adc_GroupType)Adc_apxCfgPtr[UserId]->GroupCount; GroupIter++)
        {
            if (((Adc_HwUnitType)LogicalHwUnitId == Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIter].AdcLogicalUnitId) && \
                ((uint8)STD_OFF == Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIter].AdcExtDMAChanEnable) \
               )
            {
                /* Disable DMA interrupt */
                (void)Dma_Ip_SetLogicChannelCommand(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            }
        }
    }
}
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
static inline void Adc_Ipw_EnableDMA(Adc_HwUnitType Unit,
                                     uint8 UserId,
                                     Adc_GroupType Group,
                                     const Adc_GroupConfigurationType * GroupPtr)
{
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Enable DMA for ADC module */
    Adc_Sar_Ip_DisableChannelDmaAll(PhysicalHwUnitId);
    Adc_Sar_Ip_EnableChannelDma(PhysicalHwUnitId,GroupPtr->LastCh);
    Adc_Sar_Ip_EnableDma(PhysicalHwUnitId);
    if((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
    {
        Adc_Ipw_StartDmaOperation(Unit, Group, UserId);
    }
}
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

static inline void Adc_Ipw_StartNormalConversionAdcSarDmaEnable(const Adc_HwUnitType Unit,
                                                const uint8 UserId,
                                                const Adc_GroupType Group,
                                                const Adc_GroupConfigurationType * GroupPtr,
                                                const Adc_HwUnitType PhysicalHwUnitId)
{
    /* Disables DMA requests for all chanels */
    Adc_Sar_Ip_DisableChannelDmaAll(PhysicalHwUnitId);

    /* Enable DMA requests for ADC module */
    Adc_Sar_Ip_EnableChannelDma(PhysicalHwUnitId,GroupPtr->LastCh);
    /* Enable DMA for ADC module */
    Adc_Sar_Ip_EnableDma(PhysicalHwUnitId);

    if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            /* Configure DMA in MCL module */
            Adc_Ipw_StartDmaOperation(Unit, Group, UserId);
        }
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#endif /*ADC_DMA_SUPPORTED*/

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief          Initializes the Ncmr mask for group.
* @details        Initializes the Ncmr mask for group.
*
* @param[in]      CfgPtr       Pointer to configuration structure.
*
* @return         void
*
* @pre            Driver must be initialized.
*/
static inline void Adc_Ipw_InitNcmrMask(const Adc_ConfigType * CfgPtr)
{
    Adc_GroupType Group = 0U; /* Group Index */
    Adc_GroupType GroupIndex = 0U; /* Group Index */
    uint8 i;

    /* Initialize Group Status structures to beginning values */
    for (Group = 0U; Group < CfgPtr->GroupCount; Group++)  /* GroupCount = total number of groups */
    {
        GroupIndex = (Adc_GroupType)CfgPtr->GroupsPtr[Group].EnableChDisableChGroupIndex;
        if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupIndex)
        {
          for (i = 0u; i < ADC_IPW_NUM_OF_GROUP_CHN; i++)
          {
              Adc_axRuntimeChansEnMask[GroupIndex].ChanMaskArr[i] = CfgPtr->GroupsPtr[Group].AssignedChannelMask.ChanMaskArr[i];
          }
        }
    }
}
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          This function performs general configurations to the adc hardware prior to starting a conversion.
* @details        This function performs general configurations to the adc hardware prior to starting a conversion.
*
* @param[in]      Unit       The Adc Logical Unit Id.
* @param[in]      GroupPtr   The pointer to the group configuration structure.
* @param[in]      UserId     Current UserId
*
* @return         void
*/
static inline void Adc_Ipw_PrepareGroupStart(Adc_HwUnitType Unit,
                                             const Adc_GroupConfigurationType * GroupPtr,
                                             uint8 UserId)
{
#if (FEATURE_ADC_HAS_CONVERSION_TIMING || defined(ADC_AVERAGING_FUNCTIONALITY_SUPPORT))
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    const Adc_ConversionTimeType * ConvTimePtr;
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
#endif /* (FEATURE_ADC_HAS_CONVERSION_TIMING || defined(ADC_AVERAGING_FUNCTIONALITY_SUPPORT)) */

#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
if (ADC_NORMAL == Adc_aeClockMode[UserId])
    {
        if ((uint8)STD_ON == GroupPtr->AdcIpwGroupConfigPtr->GroupAvgEnable)
        {
            Adc_Sar_Ip_SetAveraging(PhysicalHwUnitId, TRUE, GroupPtr->AdcIpwGroupConfigPtr->GroupAvgSelect);
        }
    }
    else
    {
        if ((uint8)STD_ON == GroupPtr->AdcIpwGroupConfigPtr->GroupAvgEnableAlternate)
        {
            Adc_Sar_Ip_SetAveraging(PhysicalHwUnitId, TRUE, GroupPtr->AdcIpwGroupConfigPtr->GroupAvgSelectAlternate);
        }
    }
#else /* (ADC_DUAL_CLOCK_MODE == STD_OFF) */
    {
        if ((uint8)STD_ON == GroupPtr->AdcIpwGroupConfigPtr->GroupAvgEnable)
        {
            Adc_Sar_Ip_SetAveraging(PhysicalHwUnitId, TRUE, GroupPtr->AdcIpwGroupConfigPtr->GroupAvgSelect);
        }
    }
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT) */

#if FEATURE_ADC_HAS_CONVERSION_TIMING
    /* Get the configuration value of conversion time */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    if (ADC_NORMAL == Adc_aeClockMode[UserId])
    {
        ConvTimePtr = GroupPtr->AdcIpwGroupConfigPtr->ConvTime;
    }
    else
    {
        ConvTimePtr = GroupPtr->AdcIpwGroupConfigPtr->AlternateConvTime;
    }
#else
    /* ADC_DUAL_CLOCK_MODE == STD_OFF */
    ConvTimePtr = GroupPtr->AdcIpwGroupConfigPtr->ConvTime;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

    /*  Program Conversion Time */
    Adc_Sar_Ip_SetSampleTimes(PhysicalHwUnitId, ConvTimePtr);
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */

    (void)UserId;
}
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief    This function starts a normal conversion for AdcSar
*/
static void Adc_Ipw_StartNormalConversionAdcSar(const Adc_HwUnitType Unit,
                                                const uint8 UserId,
                                                const Adc_GroupType Group,
                                                const Adc_GroupConfigurationType * GroupPtr,
                                                const Adc_HwUnitType PhysicalHwUnitId)
{
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /* Configure group params (e.g. conversion time) if need before starting conversion */
    Adc_Ipw_PrepareGroupStart(Unit, GroupPtr, UserId);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    Adc_Ipw_GetCmrRegister(Unit, Group, &CmrMask, UserId);
    /* Program the Normal Conversion Mask register */
    Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_NORMAL);
    Adc_Sar_Ip_SetConversionMode(PhysicalHwUnitId, (Adc_Sar_Ip_ConvModeType)GroupPtr->Mode);

    /* Clear Interrupt status flag */
    Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);

#ifdef ADC_DMA_SUPPORTED
    if ((ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]) && (FALSE == GroupPtr->AdcWithoutDma))
    {
        /* Enable DMA for ADC module */
        Adc_Ipw_StartNormalConversionAdcSarDmaEnable(Unit, UserId, Group, GroupPtr, PhysicalHwUnitId);


    }
    else
#endif /* ADC_DMA_SUPPORTED */
    /* ADC_INTERRUPT */
    {
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
        /* If the group is configured for with interrupts */
        if ((uint8)STD_OFF == GroupPtr->AdcWithoutInterrupt)
        {
            /* Enable Interrupt */
            Adc_Sar_Ip_EnableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
        }
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
    }

#if (ADC_SETCHANNEL_API == STD_ON)
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        /* Reset the update status */
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated = FALSE;
    }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    Adc_Sar_Ip_StartConversion(PhysicalHwUnitId, ADC_SAR_IP_CONV_CHAIN_NORMAL);
}

#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */


#if (ADC_IPW_SDADC_IS_USED == STD_ON)
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
/**
* @brief    This function starts a normal conversion for SDADC
*/
static void Adc_Ipw_StartNormalConversionSdAdc(const Adc_HwUnitType Unit,
                                               const uint8 UserId,
                                               const Adc_GroupType Group,
                                               const Adc_GroupConfigurationType * GroupPtr,
                                               const Adc_HwUnitType PhysicalHwUnitId)
{
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
    /* SDADC units only support one channel per group */
    const Adc_ChannelType LogicChannelId = GroupPtr->AssignmentPtr[0];
    /* Get the physical channel */
    const Sdadc_Ip_ChannelType ChannelConfig = AdcIpwConfigPtr->SdadcConfigPtrArr[Unit]->ChannelConfigsPtr[LogicChannelId];

    /* Configure the input channel */
    Sdadc_Ip_SetInputChannel(PhysicalHwUnitId, ChannelConfig);

    Adc_Ipw_StartNormalConversionSdAdcClearFifo(PhysicalHwUnitId);

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    if ( (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]) &&
         (FALSE   == GroupPtr->AdcWithoutDma)
       )
    {
        /* Enable DMA for SDADC module */
        Sdadc_Ip_EnableDmaEvents(PhysicalHwUnitId, SDADC_IP_EVENT_FIFO_FULL);

        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            /* Configure DMA in MCL module */
            Adc_Ipw_StartDmaOperation(Unit, Group, UserId);
        }
    }
    else
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */
    /* ADC_INTERRUPT */
    {
#ifdef ADC_ANY_UNIT_FIFOFULL_ISR_USED
        /* If the group is configured for with interrupts */
        if ((uint8)STD_OFF == GroupPtr->AdcWithoutInterrupt)
        {
            /* Enable Interrupt */
            Sdadc_Ip_EnableInterruptEvents(PhysicalHwUnitId, SDADC_IP_EVENT_FIFO_FULL);
        }
#endif /* ADC_ANY_UNIT_FIFOFULL_ISR_USED */
    }

#if (ADC_HW_TRIGGER_API == STD_ON)
    if (ADC_TRIGG_SRC_HW == GroupPtr->TriggerSource)
    {
        /* Enable hardware trigger */
        Sdadc_Ip_EnableHwTrigger(PhysicalHwUnitId);
    }
    else
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    {
        /* Start conversion */
        Sdadc_Ip_ReloadConversion(PhysicalHwUnitId);
    }

    /* Unused variable */
    (void)Group;
}

static inline void Adc_Ipw_StartNormalConversionSdAdcClearFifo(const Adc_HwUnitType PhysicalHwUnitId)
{
    /* Make sure there is no garbage in Fifo */
    Sdadc_Ip_FlushFifo(PhysicalHwUnitId);
    /* Clear all fifo status flags */
    Sdadc_Ip_ClearStatusFlags(PhysicalHwUnitId, SDADC_IP_FLAG_DATA_FIFO_FULL | SDADC_IP_FLAG_DATA_FIFO_OVERRUN);
}

/**
* @brief          This function stops the on-going conversion for SDADC
*/
static Std_ReturnType Adc_Ipw_StopCurrentConversionSdAdc(Adc_HwUnitType Unit,
                                                         Adc_GroupType Group,
                                                         uint8 UserId,
                                                         Adc_HwUnitType PhysicalHwUnitId)
{
#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    const Adc_GroupType                    GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * const GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);    /* Pointer to AdcGroup */
    const Adc_Ipw_Config      * const AdcIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;
#else
    /* Unused variable */
    (void)Unit;
    (void)Group;
    (void)UserId;
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */

    Std_ReturnType Status = (Std_ReturnType)E_OK;

    /* Stop the current conversion by temporarily disabling the SDADC */
    Sdadc_Ip_Powerdown(PhysicalHwUnitId);
    /* Disable fifo full request generation (for both interrupt and DMA) */
    Sdadc_Ip_DisableInterruptEvents(PhysicalHwUnitId, SDADC_IP_EVENT_FIFO_FULL);

#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    if ( (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]) &&
         (FALSE   == GroupPtr->AdcWithoutDma)
       )
    {
        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            /* Disable DMA hardware request */
            (void)Dma_Ip_SetLogicChannelCommand(AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        }
    }
#endif /* ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */

    /* Re-enable the SDADC to be ready for the next conversion */
    Sdadc_Ip_Powerup(PhysicalHwUnitId);

    return Status;
}
#endif /* ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON)) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
static inline Std_ReturnType Adc_Ipw_ConfigureThresholdSdAdc(const Adc_ThresholdControlIndexType ThresholdControlIndex,
                                                             const Adc_ValueGroupType LowValue,
                                                             const Adc_ValueGroupType HighValue,
                                                             const uint8 UserId)
{
    Std_ReturnType Status                 = (Std_ReturnType)E_NOT_OK;
    const Adc_HwUnitType LogicalHwUnitId  = (uint8)(ThresholdControlIndex >> ADC_THRESHOLD_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16);
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId] - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
    const uint16 LogicalThresholdId       = ThresholdControlIndex & ADC_THRESHOLD_SYMBOLIC_NAME_MASK_THRESHOLD_ID_U16;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType RangeValid                = (Std_ReturnType)E_NOT_OK;
    const Sdadc_Ip_ResolutionType Resolution = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->Resolution;

    if (SDADC_IP_RESOLUTION_15 == Resolution)
    {
        if ((uint16)LowValue <= (uint16)HighValue)
        {
            RangeValid = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        if ((sint16)LowValue <= (sint16)HighValue)
        {
            RangeValid = (Std_ReturnType)E_OK;
        }
    }

    if ((Std_ReturnType)E_OK == RangeValid)
#endif
    {
        /* Check to avoid out of bound array index, and
        Check to avoid setting disabled threshold control
        */
        if ((LogicalThresholdId <= SDADC_IP_NUM_OF_THRESHOLD_REG) &&
            (TRUE == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->WdgEnable)
           )
        {
            /* Configure threshold values */
            Sdadc_Ip_SetWdgThreshold(PhysicalHwUnitId, HighValue, LowValue);
            /* Enable WDG interrupt events */
            Sdadc_Ip_EnableInterruptEvents(PhysicalHwUnitId, SDADC_IP_EVENT_WDOG_CROSSOVER);

            Status = (Std_ReturnType)E_OK;
        }
    }

    return Status;
}
#endif /* (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */


#if (ADC_HW_TRIGGER_API == STD_ON)

static inline Std_ReturnType Adc_Ipw_EnableHardwareTriggerAdcSar(const Adc_GroupType Group,
                                                                 const Adc_HwUnitType Unit,
                                                                 const uint8 UserId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
#if ( \
     ((defined(ADC_ANY_UNIT_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
     (defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) \
    )
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
    uint32  ImrSetVal = (uint32)0UL;
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) && ... */
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
    uint32  IsrSetVal = (uint32)0UL;
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;
    Adc_Sar_Ip_ExtTriggerEdgeType TriggerEdge = ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED;
    Adc_Sar_Ip_ExtTriggerSourceType TriggerSrc;
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
    Std_ReturnType ValidStatus = (Std_ReturnType)E_OK;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /* Configure group params (e.g. conversion time) if need before starting conversion */
    Adc_Ipw_PrepareGroupStart(Unit, GroupPtr, UserId);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */

#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    if (ADC_CONV_TYPE_NORMAL == GroupPtr->Type)
    {
        Adc_Sar_Ip_SetConversionMode(PhysicalHwUnitId, ADC_SAR_IP_CONV_MODE_ONESHOT);
    }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON))
    /* If the HW trigger source for the HW triggered group comes from BCTU/CTU */
    if (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
    {
        /* Switch to CTU trigger mode */
        (void)Adc_Sar_Ip_SetCtuMode(PhysicalHwUnitId, ADC_SAR_IP_CTU_MODE_TRIGGER);
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
            /* Enable DMA for ADC module */
            Adc_Sar_Ip_DisableChannelDmaAll(PhysicalHwUnitId);
            Adc_Sar_Ip_EnableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
            Adc_Sar_Ip_EnableDma(PhysicalHwUnitId);
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* Configure DMA in MCL module */
                Adc_Ipw_StartDmaOperation(Unit, Group, UserId);
            }
        }
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        /* Configure for BCTU trigger */
        ValidStatus = Adc_Ipw_BctuTriggerEnable(Group, GroupPtr->HwTriggerSource, TRUE, TRUE, UserId);
#endif /* ADC_IPW_BCTU_AVAILABLE == STD_ON */
    }
    else
#endif /* ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) */
    {
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
        /* Get configuration of normal conversion mask registers */
        Adc_Ipw_GetCmrRegister(Unit, Group, &CmrMask, UserId);
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        /* Normal conversion */
        if (ADC_CONV_TYPE_NORMAL == GroupPtr->Type)
        {
            /* Program the Normal Conversion Mask register */
            Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_NORMAL);
            /* Clear Interrupt status flag */
            IsrSetVal |= ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN;
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
            ImrSetVal |= ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN;
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */

            /* Select the Edge */
            if (ADC_HW_TRIG_RISING_EDGE == GroupPtr->TriggerEdge)
            {
                TriggerEdge = ADC_SAR_IP_EXT_TRIG_EDGE_RISING;
            }
            else
            {
                TriggerEdge = ADC_SAR_IP_EXT_TRIG_EDGE_FALLING;
            }

#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
            if (GroupPtr->HwTriggerSource == (Adc_HwTriggerTimerType)ADC_IPW_EXT_TRG_SRC)
            {
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
                TriggerSrc = ADC_SAR_IP_NORMAL_EXT_TRIG;
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
            }
            else if (GroupPtr->HwTriggerSource == (Adc_HwTriggerTimerType)ADC_IPW_AUX_EXT_TRG_SRC)
            {
                TriggerSrc = ADC_SAR_IP_AUX_NORMAL_EXT_TRIG;
            }
            else /* normal and auxiliary are enabled simultaneously */
            {
                TriggerSrc = ADC_SAR_IP_ALL_NORMAL_EXT_TRIG;
            }
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, TriggerEdge, TriggerSrc);
        }
        else
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
        {
            /* Program the Injected Conversion Mask register */
            Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_INJECTED);
            /* Clear Interrupt status flag and CTU interrupt flag */
            IsrSetVal |= ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_CTU_EOC;
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED))
            ImrSetVal |= ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN;
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */

            /* Select the Edge */
            if (ADC_HW_TRIG_RISING_EDGE == GroupPtr->TriggerEdge)
            {
                TriggerEdge = ADC_SAR_IP_EXT_TRIG_EDGE_RISING;
            }
            else
            {
                TriggerEdge = ADC_SAR_IP_EXT_TRIG_EDGE_FALLING;
            }
            TriggerSrc = ADC_SAR_IP_INJECTED_EXT_TRIG;
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, TriggerEdge, TriggerSrc);
        }

#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
            /* Enable DMA for ADC module */
            Adc_Sar_Ip_DisableChannelDmaAll(PhysicalHwUnitId);
            Adc_Sar_Ip_EnableChannelDma(PhysicalHwUnitId,GroupPtr->LastCh);
            Adc_Sar_Ip_EnableDma(PhysicalHwUnitId);
            /* Configure DMA in MCL module */
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* Configure DMA in MCL module */
                Adc_Ipw_StartDmaOperation(Unit, Group, UserId);
            }
        }
        else
#endif /* ADC_DMA_SUPPORTED */
        {
#if ( \
     ((defined(ADC_ANY_UNIT_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
     (defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) \
    )
            if ((uint8)STD_OFF == GroupPtr->AdcWithoutInterrupt)
            {
                /* Enable Interrupt */
                Adc_Sar_Ip_EnableNotifications(PhysicalHwUnitId, ImrSetVal);
            }
            else
            {
                /* Disable Interrupt */
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ImrSetVal);
            }
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) && .. */
        }

        /* Clear Interrupt status flag */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, IsrSetVal);
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
    }

    return ValidStatus;
}


static inline void Adc_Ipw_DisableHardwareTriggerAdcSar(const Adc_GroupType Group,
                                                        const Adc_HwUnitType Unit,
                                                        const uint8 UserId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
#if ( \
     ((defined(ADC_ANY_UNIT_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
     (defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) \
    )
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
    uint32 ImrValue = (uint32)0UL;
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) && ... */
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
    uint32 IsrValue = (uint32)0UL;
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    /* Mapping PhysicalHwUnitId to CtuPhysicalId */
    uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];

    /* Set AdcIndex corresponding to bitfield in BCTU. eg: ADC0-2: BCTU0 and ADC3-6: BCTU1 */
    uint8 AdcIndexForCtu = PhysicalHwUnitId - Adc_Ipw_au8AdcIndexOffset[CtuPhysicalId];
#endif /* ADC_IPW_BCTU_AVAILABLE == STD_ON */

#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON))
    if (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        Bctu_Ip_DisableHwTrigger(CtuPhysicalId, (uint8)GroupPtr->HwTriggerSource);

        /* Clear interrupt flag status */
        Bctu_Ip_ClearStatusFlags(CtuPhysicalId,  (BCTU_IP_STATUS_ADC0_NDATA | BCTU_IP_STATUS_ADC0_DATAOVR | BCTU_IP_STATUS_ADC0_LAST) << AdcIndexForCtu);
#endif /* ADC_IPW_BCTU_AVAILABLE == STD_ON */

        /* Clear interrupt flags Interrupt Status */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_CTU_EOC);

#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
            Adc_Ipw_DisableHardwareTriggerChannelDma(PhysicalHwUnitId, (uint32)GroupPtr->LastCh);

            if ((uint8)STD_ON == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[Unit])
            {
                if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
                {
                    /* Disable DMA interrupt */
                    (void)Dma_Ip_SetLogicChannelCommand(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                }
            }
        }
#endif /* ADC_DMA_SUPPORTED */
    }
    else
#endif /* ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) */
    {
#if (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON)
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
            Adc_Ipw_DisableHardwareTriggerChannelDma(PhysicalHwUnitId, (uint32)GroupPtr->LastCh);

            if ((uint8)STD_ON == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[Unit])
            {
                if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
                {
                    /* Disable DMA interrupt */
                    (void)Dma_Ip_SetLogicChannelCommand(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                }
            }
        }
#endif /* ADC_DMA_SUPPORTED */

/* SWS_Adc_00116 */
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        if (ADC_CONV_TYPE_NORMAL == GroupPtr->Type)
        {
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
            ImrValue = ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN;
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
            IsrValue = ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_NORMAL_EOC;

            /* Disable hardware trigger */
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_ALL_NORMAL_EXT_TRIG);
        }
        else
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
        {
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED))
            ImrValue = ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN;
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */
            IsrValue = ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_EOC;

            /* Disable injected external trigger */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_ALL_NORMAL_EXT_TRIG);
#else
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_NORMAL_EXT_TRIG);
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
        }

#if ( \
     ((defined(ADC_ANY_UNIT_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
     (defined(ADC_ANY_UNIT_INJECTED_ISR_USED)) \
    )
        /* Disable Interrupt */
        Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ImrValue);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) && ... */

        /* Clear interrupt flags Interrupt Status */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, IsrValue);
#endif /* (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON) */
    }

    (void)GroupPtr;
}
#if (((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) || (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON))
#ifdef ADC_DMA_SUPPORTED

static inline void Adc_Ipw_DisableHardwareTriggerChannelDma(const Adc_HwUnitType PhysicalHwUnitId, uint32 Group)
{
    /* Disables DMA requests for ADC module */
    Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, Group);

    /* Disable DMA for ADC module */
    Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
}

#endif /* ADC_DMA_SUPPORTED */
#endif /* (((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) || (ADC_EXTERNAL_TRIGGER_ENABLE == STD_ON))*/
#if (ADC_IPW_SDADC_IS_USED == STD_ON)

static inline Std_ReturnType Adc_Ipw_EnableHardwareTriggerSdAdc(const Adc_GroupType Group,
                                                                const Adc_HwUnitType Unit,
                                                                const uint8 UserId)
{
    const Adc_GroupType                GroupIndex       = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr         = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    const Adc_HwUnitType               PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit] - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
    Std_ReturnType                     ValidStatus      = (Std_ReturnType)E_OK;
    const Sdadc_Ip_TriggerSelectType   TriggerSrc       = (Sdadc_Ip_TriggerSelectType)GroupPtr->HwTriggerSource;
    Sdadc_Ip_TriggerEdgeType           TriggerEdge;

    /* Select the Edge */
    if (ADC_HW_TRIG_RISING_EDGE == GroupPtr->TriggerEdge)
    {
        TriggerEdge = SDADC_IP_TRIGGER_RISING_EDGE;
    }
    else if (ADC_HW_TRIG_FALLING_EDGE == GroupPtr->TriggerEdge)
    {
        TriggerEdge = SDADC_IP_TRIGGER_FALLING_EDGE;
    }
    else
    {
        TriggerEdge = SDADC_IP_TRIGGER_BOTH_EDGE;
    }

    /* Configure hardware trigger */
    Sdadc_Ip_SetHwTrigger(PhysicalHwUnitId, TriggerEdge, TriggerSrc);

    /* Perform additional settings to be ready for hardware trigger event */
    Adc_Ipw_StartNormalConversionSdAdc(Unit, UserId, Group, GroupPtr, PhysicalHwUnitId);

    return ValidStatus;
}


static inline void Adc_Ipw_DisableHardwareTriggerSdAdc(const Adc_GroupType Group,
                                                       const Adc_HwUnitType Unit,
                                                       const uint8 UserId)
{
    /* Get the SDADC physical hardware instance */
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit] - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;

    /* Disable HW trigger */
    Sdadc_Ip_DisableHwTrigger(PhysicalHwUnitId);

    /* Perform additional settings to completely stop the HW group */
    (void)Adc_Ipw_StopCurrentConversionSdAdc(Unit, Group, UserId, PhysicalHwUnitId);
}

#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */


#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
static inline  Std_ReturnType Adc_Ipw_ConfigureThresholdAdcSar(const Adc_ThresholdControlIndexType ThresholdControlIndex,
                                                               const Adc_ValueGroupType LowValue,
                                                               const Adc_ValueGroupType HighValue,
                                                               const uint8 UserId)
{
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;
    uint16 LogicalThresholdId;
    uint8 CfgThresholdNum;
    Adc_Sar_Ip_WdgThresholdType WdgThreshold;

    const Adc_HwUnitType  LogicalHwUnitId = (uint8)(ThresholdControlIndex >> ADC_THRESHOLD_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16);
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    const Adc_WdgThresholdValueType MaxHighThreshold = ((Adc_WdgThresholdValueType)1U << ADC_SAR_IP_MAX_RESOLUTION) - 1U;
    const Adc_WdgThresholdValueType MaxLowThreshold  = ((Adc_WdgThresholdValueType)1U << ADC_SAR_IP_MAX_RESOLUTION) - 1U;

    if ((HighValue >= LowValue) && (HighValue <= MaxHighThreshold) && (LowValue <= MaxLowThreshold))
#endif /* if (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        LogicalThresholdId = ThresholdControlIndex & ADC_THRESHOLD_SYMBOLIC_NAME_MASK_THRESHOLD_ID_U16;
        CfgThresholdNum    = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->NumWdgThresholds;

        /* check to avoid out of bound array index */
        if (LogicalThresholdId <= CfgThresholdNum)
        {
            WdgThreshold.HighThresholdIntEn = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->WdgThresholds[LogicalThresholdId].HighThresholdIntEn;
            WdgThreshold.LowThresholdIntEn  = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->WdgThresholds[LogicalThresholdId].LowThresholdIntEn;

            /* Check to avoid setting disabled threshold control */
            if ((TRUE == WdgThreshold.HighThresholdIntEn) && (TRUE == WdgThreshold.LowThresholdIntEn))
            {
                WdgThreshold.LowThreshold  = LowValue;
                WdgThreshold.HighThreshold = HighValue;
                MCAL_DATA_SYNC_BARRIER();
                WdgThreshold.WdgIndex      = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->WdgThresholds[LogicalThresholdId].WdgIndex;
                MCAL_DATA_SYNC_BARRIER();
                Adc_Sar_Ip_SetWdgThreshold(PhysicalHwUnitId, WdgThreshold.WdgIndex, &WdgThreshold);

                Status = (Std_ReturnType)E_OK;
            }
        }
    }

    return Status;
}
#endif /* (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief          This function performs the mapping of Bctu (Ctu) Physical ID to corresponding ADC instance.
* @details        This function performs the mapping of Bctu (Ctu) Physical ID to corresponding ADC instance.
*
* @param[in]      AdcPhysicalId   Adc HW instance used. 
*
* @return         uint8
*/
uint8 Adc_Ipw_AdcPhysicalToCtuPhysical(Adc_HwUnitType AdcPhysicalId)
{
    /* Mapping CTU HW instance to corresponding ADC HW instance */
    return Adc_Ipw_au8AdcIdToCtuId[AdcPhysicalId];
}
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

#if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_SETCHANNEL_API == STD_ON))
void Adc_Ipw_SetChansMask(Adc_ChansIdxMaskType * const ChansMask,
                          const uint32 ChanIdx)
{
    uint32 GroupIdx = ChanIdx / 32U;
    uint32 Shift = ChanIdx % 32U;

    if (GroupIdx < ADC_IPW_NUM_OF_GROUP_CHN)
    {
        ChansMask->ChanMaskArr[GroupIdx] |= ((uint32)1U << Shift);
    }

    #if (ADC_IPW_NUM_OF_GROUP_CHN > 3U)
        #error "Adc Ipw ADC_IPW_NUM_OF_GROUP_CHN out of range."
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 3U) */
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON || ADC_SETCHANNEL_API == STD_ON */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
void Adc_Ipw_ClearChansMask(Adc_ChansIdxMaskType * const ChansMask,
                            const uint32 ChanIdx)
{
    uint32 GroupIdx = ChanIdx / 32U;
    uint32 Shift = ChanIdx % 32U;

    if (GroupIdx < ADC_IPW_NUM_OF_GROUP_CHN)
    {
        ChansMask->ChanMaskArr[GroupIdx] &= ~((uint32)1U << Shift);
    }

    #if (ADC_IPW_NUM_OF_GROUP_CHN > 3U)
        #error "Adc Ipw ADC_IPW_NUM_OF_GROUP_CHN out of range."
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 3U) */
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

/**
* @brief          This function clears VALID bit from ADC Conversion Data Registers
* @details        This function clears VALID bit from ADC Conversion Data Registers
*
* @param[in]      Unit          The ADC hardware unit
* @param[in]      Group         The group to be converted
* @param[in]      UserId        Current UserId
*
* @return         void
*
*/
void Adc_Ipw_ClearValidBit(Adc_HwUnitType Unit,
                           Adc_GroupType Group,
                           uint8 UserId)
{
    Adc_ChannelIndexType ChTemp;
    Adc_ChannelType ChIndexTemp;
    Adc_ChannelIndexType ChannelCount;
#if (ADC_SETCHANNEL_API == STD_OFF)
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
#endif /*ADC_SETCHANNEL_API == STD_OFF*/
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    ChannelCount = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AssignedChannelCount;
#endif

    /* Clear VALID bit from ADC result registers for all channels assigned to the group when conversion is aborted */
    for (ChTemp = 0U; ChTemp < ChannelCount; ChTemp++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        ChIndexTemp = Adc_axRuntimeGroupChannel[Group].ChannelPtr[ChTemp];
#else
        ChIndexTemp = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AssignmentPtr[ChTemp];
#endif
        (void) Adc_Sar_Ip_GetConvData(PhysicalHwUnitId, (uint32)Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->ChannelConfigsPtr[ChIndexTemp].ChanIndex);
    }
}

/**
* @brief          This function initializes the ADC hardware modules, triggering units and the ADC driver.
* @details        This function initializes the ADC hardware module, and the ADC driver.
*
* @param[in]      IpwCfg           Configuration data pointer.
* @param[in]      UserId           Current UserId
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              If Power up/Power down activities return status as expected.
* @retval         E_NOT_OK          If Power up/Power down activities couldn't return status as expected.
*
*/
Std_ReturnType Adc_Ipw_Init(const Adc_Ipw_Config * IpwCfg,
                            const uint8 UserId)
{
    Adc_HwUnitType LogicalHwUnitId = 0U;
    Adc_HwUnitType PhysicalHwUnitId = 0U;
    Std_ReturnType TimeOutStatus = (Std_ReturnType)E_OK;

#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON))
    uint8 CtuPhysicalId = 0U;
    uint8 CheckCallBctu = 0U;
#endif

    /* Initialize Unit Status structures */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_Ipw_InitNcmrMask(Adc_apxCfgPtr[UserId]);
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

    for (LogicalHwUnitId = 0U; LogicalHwUnitId < ADC_IPW_MAX_HW_UNITS; LogicalHwUnitId++)
    {
        if (IpwCfg->Mapping.AdcHwUnitArr[LogicalHwUnitId] == (uint8)STD_ON) /* Hardware Unit is enabled on current partition */
        {
            PhysicalHwUnitId = IpwCfg->AdcPhysicalIdArr[LogicalHwUnitId];

            /* 1) Init ADC hardware */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
            if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
            {
                /* SDADC */
                if (SDADC_IP_STATUS_SUCCESS != Sdadc_Ip_Init((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET, IpwCfg->SdadcConfigPtrArr[LogicalHwUnitId]))
                {
                    TimeOutStatus = E_NOT_OK;
                }
            }
            else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
            {
                /* ADCSAR */
                if (ADC_SAR_IP_STATUS_SUCCESS != Adc_Sar_Ip_Init(PhysicalHwUnitId, IpwCfg->AdcConfigPtrArr[LogicalHwUnitId]))
                {
                    TimeOutStatus = E_NOT_OK;
                }
            }

            /* 2) Init BCTU hardware */
#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && (ADC_IPW_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON))
            /* Mapping PhysicalHwUnitId to CtuPhysicalId */
            CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];
            if ( (CtuPhysicalId != ADC_IPW_INVALID_PHYSICAL_UNIT_ID) && (IpwCfg->CtuConfigTriggerMode[CtuPhysicalId] != NULL_PTR) )
            {
                /* Check if the Bctu instance is already called */
                if (0U == (CheckCallBctu & (1U << CtuPhysicalId)))
                {
                    Bctu_Ip_Init(CtuPhysicalId, IpwCfg->CtuConfigTriggerMode[CtuPhysicalId]);
                    CheckCallBctu |= (1U << CtuPhysicalId);
                }
            }
#endif /* (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) &&... */

            if (TimeOutStatus != (Std_ReturnType)E_OK)
            {
                break;
            }
        }
    }

    (void)UserId;

    return TimeOutStatus;
}

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function de-initializes the ADC driver, and the ADC hardware.
* @details        This function de-initializes the ADC driver, and ensures that the ADC hardware
*                 will be in the power on after reset state.
*
* @param[in]      UserId         Current UserId
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              If the operation completed successfully.
* @retval         E_NOT_OK          In case of timeout while waiting for adc hardware operations.
*
*/
Std_ReturnType Adc_Ipw_DeInit(uint8 UserId)
{
    Adc_HwUnitType LogicalHwUnitId = 0U;
    Adc_HwUnitType PhysicalHwUnitId = 0U;
    Adc_GroupType GroupId = 0U;
    Adc_GroupType GroupIter = 0U;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_GroupType GroupIndex = 0U;
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    Std_ReturnType ReturnStatus = E_OK;

#if ((ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON))
    uint8 CtuPhysicalId;
    boolean CtuOnGoing;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

    for (LogicalHwUnitId = 0U; LogicalHwUnitId < ADC_IPW_MAX_HW_UNITS; LogicalHwUnitId++)
    {
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[LogicalHwUnitId] == (uint8)STD_ON) /* HW unit enabled on current partition */
        {
            PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];

#if ((ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON))
            /* Mapping AdcPhysicalID to CtuPhysicalID */
            CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];
            if (CtuPhysicalId != ADC_IPW_INVALID_PHYSICAL_UNIT_ID)
            {
                /* Set default as NOT on-going */
                CtuOnGoing = FALSE;

                /* Check CTU trigger mode configuration pointer */
                if (NULL_PTR != Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigTriggerMode[CtuPhysicalId])
                {
                    CtuOnGoing = TRUE;
                }

                /* 1) De-init BCTU hardware */
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
                /* Check CTU control mode status variable */
                if (TRUE == Adc_axUnitStatus[LogicalHwUnitId].CtuControlOngoing)
                {
                    CtuOnGoing = TRUE;
                    /* Mark the unit as CTU control mode is not ongoing */
                    Adc_axUnitStatus[LogicalHwUnitId].CtuControlOngoing = FALSE;
                }
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
                /* Deinit Bctu */
                if (TRUE == CtuOnGoing)
                {
                    /* De-init CTU hardware */
                    (void)Bctu_Ip_Deinit((uint32)CtuPhysicalId);
                }
            }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

            /* 2) De-init ADC hardware */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
            if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
            {
                /* SDADC */
                Sdadc_Ip_Deinit((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET);
            }
            else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
            {
                if (ADC_SAR_IP_STATUS_SUCCESS != Adc_Sar_Ip_Deinit(PhysicalHwUnitId))
                {
                    ReturnStatus = E_NOT_OK;
                }
            }

            /* 3) Disable DMA hardware */
#ifdef ADC_DMA_SUPPORTED
            Adc_Ipw_DmaClearHwRequest(UserId, LogicalHwUnitId);
#endif /* ifdef ADC_DMA_SUPPORTED */

            if ((Std_ReturnType)E_OK != ReturnStatus)
            {
                break;
            }
        }
    }

    for (GroupIter = 0U; GroupIter < (Adc_GroupType)Adc_apxCfgPtr[UserId]->GroupCount; GroupIter++)
    {
        GroupId = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIter].GroupId;
#if (ADC_SETCHANNEL_API == STD_ON)
        Adc_axRuntimeGroupChannel[GroupId].ChannelPtr = NULL_PTR;
        Adc_axRuntimeGroupChannel[GroupId].ChannelCount = 0U;
        Adc_axRuntimeGroupChannel[GroupId].RuntimeUpdated = FALSE;
#endif
        Adc_axGroupStatus[GroupId].ResultsBufferPtr = NULL_PTR;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_axGroupStatus[GroupId].Notification = ADC_NOTIFICATION_DISABLED;
#endif  /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /* Disable all normal conversion mask */
        GroupIndex = (Adc_GroupType)Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIter].EnableChDisableChGroupIndex;
        if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupIndex)
        {
            Adc_axRuntimeChansEnMask[GroupIndex].ChanMaskArr[0u] = (uint32)0u;
        #if (ADC_SAR_IP_NUM_GROUP_CHAN > 1u)
            Adc_axRuntimeChansEnMask[GroupIndex].ChanMaskArr[1u] = (uint32)0u;
        #endif /* (ADC_SAR_IP_NUM_GROUP_CHAN > 1u) */
        #if (ADC_SAR_IP_NUM_GROUP_CHAN > 2u)
            Adc_axRuntimeChansEnMask[GroupIndex].ChanMaskArr[2u] = (uint32)0u;
        #endif /* (ADC_SAR_IP_NUM_GROUP_CHAN > 2u) */
        }
#endif  /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    }
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    Adc_aeClockMode[UserId] = ADC_NORMAL;
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

    return ReturnStatus;
}
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          This function starts the conversion on the specified hardware Unit.
* @details        This function starts the conversion on the specified hardware Unit.
*                 This function should be called with the ADC Unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      Unit            the used hw Unit.
* @param[in]      UserId          Current UserId
*
* @return         void
*
*/
void Adc_Ipw_StartNormalConversion(Adc_HwUnitType Unit,
                                   uint8 UserId)
{
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
    Adc_GroupType Group = 0U; /* Active group in the Queue */
    Adc_GroupType GroupIndex = 0U; /* Group index in each partition */
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Do nothing if there is no request available in queue */
    if ((Adc_QueueIndexType)0 != Adc_axUnitStatus[Unit].SwNormalQueueIndex)
    {
        /* Get the Group ID of the current active group */
        /* Load the first group in the queue (Adc_axUnitStatus[Unit].SwNormalQueue[0])*/
        Group = Adc_axUnitStatus[Unit].SwNormalQueue[0];
        GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
        GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        if (!((TRUE == Adc_axGroupStatus[Group].LimitCheckFailed) && (ADC_SAR_IP_CONV_MODE_ONESHOT == (Adc_Sar_Ip_ConvModeType) GroupPtr->Mode)))
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
        {

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
            if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
            {
                /* SDADC */
                PhysicalHwUnitId -= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
                Adc_Ipw_StartNormalConversionSdAdc(Unit, UserId, Group, GroupPtr, PhysicalHwUnitId);
            }
            else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
            {
                /* ADCSAR */
                Adc_Ipw_StartNormalConversionAdcSar(Unit, UserId, Group, GroupPtr, PhysicalHwUnitId);
            }

        }
    }
}

#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
/**
* @brief          This function starts the injected conversion on the specified hardware Unit.
* @details        This function starts the injected conversion on the specified hardware Unit.
*                 This function should be called with the ADC Unit on idle or busy.
*
* @param[in]      Unit            The used hw Unit.
* @param[in]      UserId          Current UserId
*
* @return         void
*/
void Adc_Ipw_StartInjectedConversion(Adc_HwUnitType Unit,
                                     uint8 UserId)
{
    Adc_GroupType Group = 0U; /* Active group in the Queue */
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) || defined(ADC_DMA_SUPPORTED))
    Adc_GroupType GroupIndex = 0U;
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
#endif

    /* Do nothing if there is no request available in queue */
    if ((Adc_QueueIndexType)0 != Adc_axUnitStatus[Unit].SwInjectedQueueIndex)
    {
        /* Get the Group ID of the current active group */
        /* Load the first group in the queue (Adc_axUnitStatus[Unit].SwInjectedQueue[0])*/
        Group = Adc_axUnitStatus[Unit].SwInjectedQueue[0];
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) || defined(ADC_DMA_SUPPORTED))
        GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
        GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
#endif
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        /* Configure group params (e.g. conversion time) if need before starting conversion */
        Adc_Ipw_PrepareGroupStart(Unit, GroupPtr, UserId);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */

        /* Get mask of channels using injected conversion */
        Adc_Ipw_GetCmrRegister(Unit, Group, &CmrMask, UserId);

        /* Program the Injected Conversion Mask register */
        Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_INJECTED);

        /* Clear Interrupt status flag */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);

#ifdef ADC_DMA_SUPPORTED
        if ((ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]) && (FALSE == GroupPtr->AdcWithoutDma))
        {
            /* Enable DMA for ADC module */
            Adc_Ipw_EnableDMA(Unit, UserId, Group, GroupPtr);
        }
        else
#endif /* ADC_DMA_SUPPORTED */
        {
#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED))
            /* If the group is configured for with interrupts */
            if ((uint8)STD_OFF == GroupPtr->AdcWithoutInterrupt)
            {
                /* If the group is configured for with interrupts */
                /* Enable Injected Interrupt */
                Adc_Sar_Ip_EnableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
            }
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */
        }

#if (defined(ADC_ANY_UNIT_INJECTED_ISR_USED))
        if ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt)
        {
            /* Disable Injected Interrupt */
            Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        }
#endif /* (defined(ADC_ANY_UNIT_INJECTED_ISR_USED) */

#if (ADC_SETCHANNEL_API == STD_ON)
        if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
        {
            /* Reset the update status */
            Adc_axRuntimeGroupChannel[Group].RuntimeUpdated =  FALSE;
        }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

        /* Start Injected Conversion */
        Adc_Sar_Ip_StartConversion(PhysicalHwUnitId, ADC_SAR_IP_CONV_CHAIN_INJECTED);
    }
}
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */


static Std_ReturnType Adc_Ipw_StopCurrentConversionAdcSar(Adc_HwUnitType Unit,
                                                          Adc_GroupType Group,
                                                          uint8 UserId,
                                                          Adc_HwUnitType PhysicalHwUnitId)
{
#if ((ADC_BYPASS_ABORT_CHAIN_CHECK == STD_ON) || defined(ADC_DMA_SUPPORTED))
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
#endif /* (ADC_BYPASS_ABORT_CHAIN_CHECK == STD_ON) || defined(ADC_DMA_SUPPORTED) */
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Adc_Sar_Ip_StatusType AdcSarStatus = ADC_SAR_IP_STATUS_SUCCESS;

#ifdef ADC_DMA_SUPPORTED
    if ((ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]) && (FALSE == Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AdcWithoutDma))
    {
        /* Disable all DMA mask register */
#if ((ADC_BYPASS_ABORT_CHAIN_CHECK == STD_ON) || (ADC_SETCHANNEL_API == STD_OFF))
        Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].LastCh);
#endif /* (ADC_BYPASS_ABORT_CHAIN_CHECK == STD_ON) || (ADC_SETCHANNEL_API == STD_OFF) */
        Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
        if ((uint8)STD_ON == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[Unit])
        {
            if ((uint8)STD_OFF == Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AdcExtDMAChanEnable)
            {
                /* Disable DMA hardware request */
                (void)Dma_Ip_SetLogicChannelCommand(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            }
        }
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
#if (defined(ADC_ANY_UNIT_NORMAL_ISR_USED))
        Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_ANY_UNIT_NORMAL_ISR_USED) */
    }

    /*  Stop the conversion and abort the current group conversion */
#if (ADC_BYPASS_ABORT_CHAIN_CHECK == STD_ON)
    if ((uint8)STD_ON == Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AdcWithoutInterrupt)
    {
        AdcSarStatus = Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, FALSE, FALSE);
    }
    else
    {
        /* Check timeout after aborting current conversion */
        AdcSarStatus = Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, TRUE, FALSE);
    }
#else
    AdcSarStatus = Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, TRUE, FALSE);
#endif /* (ADC_BYPASS_ABORT_CHAIN_CHECK == STD_ON) */

    /* Clear interrupt status after hardware disabled */
    Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);

    if (ADC_SAR_IP_STATUS_SUCCESS != AdcSarStatus)
    {
        Status = E_NOT_OK;
    }
    else
    {
        /* Clear VALID bit from ADC Data Registers for all channels assigned to the group when conversion is aborted */
        Adc_Ipw_ClearValidBit(Unit, Group, UserId);
    }

    return Status;
}

/**
* @brief          This function stops the current conversion of a group.
* @details        This function stops the current conversion of a group.
*
* @param[in]      Unit      The hardware Unit.
* @param[in]      Group     The group id.
* @param[in]      UserId    Current UserId
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            If the conversion has stopped as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc hardware to stop a conversion.
*
*/
Std_ReturnType Adc_Ipw_StopCurrentConversion(Adc_HwUnitType Unit,
                                             Adc_GroupType Group,
                                             uint8 UserId)
{
    Std_ReturnType Status;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        PhysicalHwUnitId -= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
        Status = Adc_Ipw_StopCurrentConversionSdAdc(Unit, Group, UserId, PhysicalHwUnitId);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        Status = Adc_Ipw_StopCurrentConversionAdcSar(Unit, Group, UserId, PhysicalHwUnitId);
    }

    return Status;
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function enables the hardware triggers for the specified group.
* @details        This function enables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
* @param[in]      UserId          Current UserId
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              If there is no running conversion.
* @retval         E_NOT_OK          If there is a running conversion.
*
*/
Std_ReturnType Adc_Ipw_EnableHardwareTrigger(Adc_GroupType Group,
                                             Adc_HwUnitType Unit,
                                             uint8 UserId)
{
    Std_ReturnType ValidStatus = (Std_ReturnType)E_OK;

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        ValidStatus = Adc_Ipw_EnableHardwareTriggerSdAdc(Group, Unit, UserId);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        ValidStatus = Adc_Ipw_EnableHardwareTriggerAdcSar(Group, Unit, UserId);
    }

#if (ADC_SETCHANNEL_API == STD_ON)
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        /* Roll back to the first sample */
        Adc_axGroupStatus[Group].ResultIndex = 0U;
        /* Reset the update status */
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated =  FALSE;
    }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    return ValidStatus;
}

/**
* @brief          This function disables the hardware triggers for the specified group.
* @details        This function disables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
void Adc_Ipw_DisableHardwareTrigger(Adc_GroupType Group,
                                    Adc_HwUnitType Unit,
                                    uint8 UserId)
{
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        Adc_Ipw_DisableHardwareTriggerSdAdc(Group, Unit, UserId);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        Adc_Ipw_DisableHardwareTriggerAdcSar(Group, Unit, UserId);
    }
}

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
/**
* @brief          This function gets channel list.
* @details        This local function to get the channel list used with CTU Triggered Mode.
*                   Finding the position of largest physical channel id and swap with last channel of list in case of DMA is used
*
* @param[out]     ChanList           List of channels.
* @param[in]      ChannelCount       The size of channel list
* @param[in]      Group              Group index
* @param[in]      LogicalHwUnitId    Adc logical id
* @param[in]      UserId             Current user id
*
* @return         void
*
*/
void Adc_Ipw_GetCtuChanList(uint8 * ChanList,
                            uint8 ChannelCount,
                            Adc_GroupType Group,
                            Adc_HwUnitType LogicalHwUnitId,
                            uint8 UserId)
{
    uint8 Index;
#ifdef ADC_DMA_SUPPORTED
    uint8 LastChIndex = 0U;
    uint8 LastChTemp;
#endif /* ADC_DMA_SUPPORTED */
#if ((ADC_SETCHANNEL_API == STD_OFF) || defined(ADC_DMA_SUPPORTED))
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
#endif /* (ADC_SETCHANNEL_API == STD_OFF) || defined(ADC_DMA_SUPPORTED) */
    const Adc_Ipw_Config * LocIpwConfigPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr;

    for (Index = 0U; Index < ChannelCount; Index++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        ChanList[Index] = LocIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[Index]].ChanIndex;
#else
        ChanList[Index] = LocIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->ChannelConfigsPtr[(GroupPtr->AssignmentPtr[Index])].ChanIndex;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#ifdef ADC_DMA_SUPPORTED
        if ((ADC_DMA == LocIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) && (ChanList[Index] == GroupPtr->LastCh))
        {
            /* Save position of largest physical channel id */
            LastChIndex = Index;
        }
#endif /* ADC_DMA_SUPPORTED */
    }

#ifdef ADC_DMA_SUPPORTED
    /* Place largest physical channel id to end of list */
    if ((ADC_DMA == LocIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) && (LastChIndex != (ChannelCount - 1U)))
    {
        LastChTemp = ChanList[LastChIndex];
        ChanList[LastChIndex] = ChanList[(ChannelCount - 1U)];
        ChanList[(ChannelCount - 1U)] = LastChTemp;
    }
#endif /* ADC_DMA_SUPPORTED */
}

/**
* @brief          This function enables the hardware trigger for the specified group.
* @details        Autosar Extension API to enable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
* @param[in]      AutosarApi      Indicates whether function is called from ASR function or non-ASR function
* @param[in]      FirstTrigger    Indicates whether trigger source is the first trigger source is enabled
* @param[in]      UserId          UserId
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              If there is no running conversion.
* @retval         E_NOT_OK          If there is a running conversion.
*
*/
static inline Std_ReturnType Adc_Ipw_BctuTriggerEnable(const Adc_GroupType Group,
                                                       Adc_HwTriggerTimerType TriggerSource,
                                                       boolean AutosarApi,
                                                       boolean FirstTrigger,
                                                       uint8 UserId)
{
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_OFF)
    uint8 Index;
    Adc_ChannelIndexType ChannelCount;
    uint8 ChanList[ADC_MAX_CHANNEL_PER_HW_UNIT];
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_OFF) */
    Bctu_Ip_TrigConfigType TrigConfig;
    const Adc_ConfigType * CfgPtr = Adc_apxCfgPtr[UserId];
    const Adc_GroupType GroupIndex = CfgPtr->GroupIdToIndexMapPtr[Group];
    const Adc_HwUnitType LogicalHwUnitId = CfgPtr->GroupsPtr[GroupIndex].AdcLogicalUnitId;
    const Adc_HwUnitType PhysicalHwUnitId = CfgPtr->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    /* Mapping PhysicalHwUnitId to CtuPhysicalId */
    uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];

    /* Set AdcIndex corresponding to bitfield in BCTU. eg: ADC0-2: BCTU0 and ADC3-6: BCTU1 */
    uint8 AdcIndexForCtu = PhysicalHwUnitId - Adc_Ipw_au8AdcIndexOffset[CtuPhysicalId];

    const Adc_GroupConfigurationType * GroupPtr = &(CfgPtr->GroupsPtr[GroupIndex]);
    Bctu_Ip_StatusType BctuStatus;
    const uint8 BctuNotifAdcUnitFlag = (uint8)(BCTU_IP_NOTIF_ADC0 << AdcIndexForCtu);
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;

    Bctu_Ip_SetGlobalTriggerEn(CtuPhysicalId, FALSE);
    Bctu_Ip_DisableNotifications(CtuPhysicalId, (BCTU_IP_NOTIF_LIST | BctuNotifAdcUnitFlag));

    if (TRUE == AutosarApi)
    {
        if ((uint8)STD_OFF == GroupPtr->AdcWithoutInterrupt)
        {
#ifdef ADC_DMA_SUPPORTED
            if (ADC_INTERRUPT == CfgPtr->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId])
#endif /* ADC_DMA_SUPPORTED */
            {
                Bctu_Ip_EnableNotifications(CtuPhysicalId, BCTU_IP_NOTIF_LIST);
            }
        }
    }

    TrigConfig.TrigIndex       = (uint8)TriggerSource;
    TrigConfig.LoopEn         = FALSE;
    TrigConfig.DataDest       = BCTU_IP_DATA_DEST_ADC_DATA_REG;
    TrigConfig.HwTriggersEn   = TRUE;
    TrigConfig.AdcTargetMask = (1u << AdcIndexForCtu);

    /* Configure for list mode */
    TrigConfig.TrigType = BCTU_IP_TRIG_TYPE_LIST;

#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
    /* Each CTU trigger group has its own start position in channel list */
    TrigConfig.AdcChanOrListStart = GroupPtr->CtuTrigListPos;
    (void)FirstTrigger;

#else /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_OFF) */
    TrigConfig.AdcChanOrListStart = CfgPtr->AdcIpwConfigPtr->CtuListStartIndex[LogicalHwUnitId];

    /* If this is the first call for this group */
    if (TRUE == FirstTrigger)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
        ChannelCount = GroupPtr->AssignedChannelCount;
#endif
        /* Initialize all sorted channel list to zero (avoid GCC compiler error) */
        for (Index = 0U; Index < ADC_MAX_CHANNEL_PER_HW_UNIT; Index++)
        {
            ChanList[Index] = 0U;
        }
        Adc_Ipw_GetCtuChanList(ChanList, (uint8)ChannelCount, Group, LogicalHwUnitId, UserId);
        Bctu_Ip_ConfigChanListSimple(CtuPhysicalId, TrigConfig.AdcChanOrListStart, ChanList, ChannelCount);
    }
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_OFF) */

#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
    if (TRUE == AutosarApi)
    {
        Bctu_Ip_EnableHwTrigger(CtuPhysicalId, TrigConfig.TrigIndex);
    }
    else
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
    {
        BctuStatus = Bctu_Ip_ConfigTrigger(CtuPhysicalId, &TrigConfig);

        if (BctuStatus != BCTU_IP_STATUS_SUCCESS)
        {
            ReturnStatus = E_NOT_OK;
        }
    }

    /* Enable global trigger for all trigger input */
    Bctu_Ip_SetGlobalTriggerEn(CtuPhysicalId, TRUE);

    return ReturnStatus;
}
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
* @brief          This function enables the hardware trigger for the specified group.
* @details        Autosar Extension API to enable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
* @param[in]      FirstTrigger    Indicates whether trigger source is the first trigger source is enabled
* @param[in]      UserId          UserId
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              If there is no running conversion.
* @retval         E_NOT_OK          If there is a running conversion.
*
*/
Std_ReturnType Adc_Ipw_EnableCtuTrigger(Adc_GroupType Group,
                                        Adc_HwTriggerTimerType TriggerSource,
                                        boolean FirstTrigger,
                                        uint8 UserId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupConfig = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_HwUnitType LogicalHwUnitId = GroupConfig->AdcLogicalUnitId;
    Std_ReturnType ValidStatus = (Std_ReturnType)E_OK;

    if (TRUE == FirstTrigger)
    {
        Adc_axUnitStatus[LogicalHwUnitId].OngoingHwGroup = Group;
        /* SWS_Adc_00222 */
        /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
        Adc_axGroupStatus[Group].Conversion = ADC_BUSY;
        /* SWS_Adc_00432 */
        /* Put the conversion results from Results Buffer Base Address */
        Adc_axGroupStatus[Group].ResultIndex = 0U;
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
        /* Configure group params (e.g. conversion time) if need before starting conversion */
        Adc_Ipw_PrepareGroupStart(LogicalHwUnitId, GroupConfig, UserId);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    }
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    ValidStatus = Adc_Ipw_BctuTriggerEnable(Group, TriggerSource, FALSE, FirstTrigger, UserId);
#endif /* ADC_IPW_BCTU_AVAILABLE == STD_ON */

#if (ADC_SETCHANNEL_API == STD_ON)
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        /* Roll back to the first sample */
        Adc_axGroupStatus[Group].ResultIndex = 0U;
        /* Reset the update status */
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated =  FALSE;
    }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    return ValidStatus;
}

/**
* @brief          This function disables the hardware trigger for the specified group.
* @details        Autosar Extension API to disable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be disabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
void Adc_Ipw_DisableCtuTrigger(Adc_GroupType Group,
                               Adc_HwTriggerTimerType TriggerSource,
                               boolean LastTrigger,
                               uint8 UserId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupConfig = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_HwUnitType LogicalHwUnitId = GroupConfig->AdcLogicalUnitId;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    /* Mapping PhysicalHwUnitId to CtuPhysicalId */
    uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];

    /* Set AdcIndex corresponding to bitfield in BCTU. eg: ADC0-2: BCTU0 and ADC3-6: BCTU1 */
    uint8 AdcIndexForCtu = PhysicalHwUnitId - Adc_Ipw_au8AdcIndexOffset[CtuPhysicalId];

    Bctu_Ip_DisableHwTrigger(CtuPhysicalId, (uint8)TriggerSource);
    /* Clear interrupt flag status */
    Bctu_Ip_ClearStatusFlags(CtuPhysicalId, (BCTU_IP_STATUS_ADC0_NDATA | BCTU_IP_STATUS_ADC0_DATAOVR | BCTU_IP_STATUS_ADC0_LAST) << AdcIndexForCtu);
#endif /* ADC_IPW_BCTU_AVAILABLE == STD_ON */

    if (TRUE == LastTrigger)
    {
        if ((ADC_INVALID_HW_GROUP_ID != Adc_axUnitStatus[LogicalHwUnitId].OngoingHwGroup) && (ADC_CONV_TYPE_INJECTED == GroupConfig->Type))
        {
            Adc_axUnitStatus[LogicalHwUnitId].OngoingHwGroup = ADC_INVALID_HW_GROUP_ID;
        }

        /*Mark the group as IDLE */
        Adc_axGroupStatus[Group].Conversion = ADC_IDLE;

        /* Clear CTU interrupt flag */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_CTU_EOC);
    }
}

/**
* @brief          This function reads the data from the ADC channel hardware data register.
* @details        This Autosar Extension API is used to copy the data from the ADC channel
*                 hardware data register to the ADC group result buffer.
*
* @param[in]      Group           The group for which the data will be read.
* @param[in]      DataPtr        Pointer to a buffer which will be filled by the
*                                 conversion results.
*

* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
Std_ReturnType Adc_Ipw_HwResultReadGroup(Adc_GroupType Group,
                                         Adc_ValueGroupType * DataPtr,
                                         uint8 UserId)
{
    Adc_ChannelIndexType Channel;
    Adc_ChannelType LastCh;
    Adc_ChannelType ChIndex;
#if (ADC_SETCHANNEL_API == STD_ON)
    Adc_ChannelType CrtChannel;
    Adc_ChannelIndexType Ch;
#endif
    Adc_ChannelIndexType ChannelCount;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_GroupType GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
    Std_ReturnType ChannelEnable = (Std_ReturnType)E_NOT_OK;
    Std_ReturnType ChannelExist = (Std_ReturnType)E_NOT_OK;
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
    Std_ReturnType ReadGroupRet = (Std_ReturnType)E_OK;
    Adc_Sar_Ip_ChanResultType AdcResultLastCh;
    Adc_Sar_Ip_ChanResultType AdcResult;
    uint16 ConvData;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AdcLogicalUnitId;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    const Adc_Sar_Ip_ConfigType * AdcPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId];
    Adc_HwTriggerTimerType GrHwTriggerSrc = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].HwTriggerSource;

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
    LastCh = AdcPtr->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[0]].ChanIndex;
    for (Ch = 0U; Ch < ChannelCount; Ch++)
    {
        CrtChannel = AdcPtr->ChannelConfigsPtr[Adc_axRuntimeGroupChannel[Group].ChannelPtr[Ch]].ChanIndex;
        if (CrtChannel > LastCh)
        {
            LastCh = CrtChannel;
        }
    }
#else
    ChannelCount = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AssignedChannelCount;
    LastCh = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].LastCh;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /* Get index of the group with AdcEnableChDisableChGroup enabled */
    GroupId = (Adc_GroupType)Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].EnableChDisableChGroupIndex;
    /* Check if group have AdcEnableChDisableChGroup enabled */
    if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupId)
    {
        for (Channel = 0U; Channel < ChannelCount; Channel++)
        {
            ChIndex = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AssignmentPtr[Channel];
            ChannelEnable = Adc_Ipw_IsChannelEnable(LogicalHwUnitId, GroupId, ChIndex, UserId);
            if ((Std_ReturnType)E_OK == ChannelEnable)
            {
                if ((Std_ReturnType)E_NOT_OK == ChannelExist)
                {
                    ChannelExist = (Std_ReturnType)E_OK;
                    LastCh = AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex;
                }
                if (AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex > LastCh)
                {
                    /* Calculate the last channel to check convert status when disableChannel function is invoked */
                    LastCh = AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex;
                }
            }
        }
    }
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
#endif
    if (GrHwTriggerSrc <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
    {
        Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, LastCh, ADC_SAR_IP_CONV_CHAIN_CTU, &AdcResultLastCh);
    }
    else
    {
        Adc_Sar_Ip_ConvChainType convChainType = (Adc_Sar_Ip_ConvChainType)Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].Type;
        Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, LastCh, convChainType, &AdcResultLastCh);
    }

    if (TRUE == AdcResultLastCh.ValidFlag)
    {
        /* Result for LastCh is valid, so all conversions from the group have been completed */
        for (Channel = 0U; Channel < ChannelCount; Channel++)
        {
#if (ADC_SETCHANNEL_API == STD_ON)
            ChIndex = Adc_axRuntimeGroupChannel[Group].ChannelPtr[Channel];
#else
            ChIndex = Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].AssignmentPtr[Channel];
#endif
            if ((uint32)AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex != LastCh)
            {
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
                /* Get index of the group with AdcEnableChDisableChGroup enabled */
                GroupId = (Adc_GroupType)Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].EnableChDisableChGroupIndex;
                /* Check if group have AdcEnableChDisableChGroup enabled */
                if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupId)
                {
                    ChannelEnable = Adc_Ipw_IsChannelEnable(LogicalHwUnitId, GroupId, ChIndex, UserId);
                }
                else
                {
                    ChannelEnable = (Std_ReturnType)E_OK;
                }
                /* If channel is enable, check valid and result bit */
                if ((Std_ReturnType)E_OK == ChannelEnable)
                {
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
                    if (GrHwTriggerSrc <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
                    {
                        Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), ADC_SAR_IP_CONV_CHAIN_CTU, &AdcResult);
                    }
                    else
                    {
                        Adc_Sar_Ip_ConvChainType convChainType = (Adc_Sar_Ip_ConvChainType)Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex].Type;
                        Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), convChainType, &AdcResult);
                    }
                    if (FALSE == AdcResult.ValidFlag)
                    {
                        ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                        break;
                    }
                    ConvData = AdcResult.ConvData;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
                }
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
            }
            else
            {
                /* For LastChan do not read again the result, but use the result already read */
                ConvData = AdcResultLastCh.ConvData;
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
                /* The Last Channel is always enabled */
                ChannelEnable = (Std_ReturnType)E_OK;
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
            }
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
            if ((Std_ReturnType)E_OK == ChannelEnable)
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
            {
                DataPtr[Channel] = ConvData;
            }
        }
    }
    else
    {
        ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    }

    return ReadGroupRet;
}
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_READ_GROUP_API == STD_ON)

static inline Std_ReturnType Adc_Ipw_ReadGroupAdcSar(const Adc_GroupType Group,
                                                     Adc_ValueGroupType * DataPtr,
                                                     boolean * Flag,
                                                     uint8 UserId)
{
    Std_ReturnType ReadGroupRet = (Std_ReturnType)E_OK;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;

    /* If the group is configured for without interrupts */
    if ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt)
    {
        /* Return error if group is not at the first of queue */
        if (ADC_CONV_TYPE_NORMAL == GroupPtr->Type)
        {
            if (ADC_TRIGG_SRC_SW == GroupPtr->TriggerSource)
            {
                if (Group != Adc_axUnitStatus[LogicalHwUnitId].SwNormalQueue[0])
                {
                    ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                }
            }
#if (STD_ON == ADC_HW_TRIGGER_API)
            else
            {
                if (Group != Adc_axUnitStatus[LogicalHwUnitId].OngoingHwGroup)
                {
                    ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                }
            }
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
        }
        if ((Std_ReturnType)E_OK == ReadGroupRet)
        {
            ReadGroupRet = Adc_Ipw_ReadGroupNoInt(Group, DataPtr, Flag, UserId);
        }
    }
    else  /* If the group is configured with interrupts */
    {
        if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
        {
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Adc_Ipw_ReadGroupIntAdcSar(Group, DataPtr, UserId);
        }
    }

    return ReadGroupRet;
}

static inline void Adc_Ipw_ReadGroupIntAdcSar(const Adc_GroupType Group,
                                                Adc_ValueGroupType * DataPtr,
                                                uint8 UserId)
{
    Adc_ChannelIndexType ChannelCount;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    Adc_ChannelIndexType Index = 0U;
    Adc_ValueGroupType * ResultPtr = NULL_PTR;
    uint32 DestOffset = (uint32)0UL;
    Adc_StreamNumSampleType ResultIndex = 0U;

#ifdef ADC_DMA_SUPPORTED
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;

    /* When DMA is used, the masking result is required according to safety analysis. Interrupt was done by Adc_Sar_Ip_GetConvResult. */
    Adc_Sar_Ip_ChanResultType AdcResult;
    
    uint8 Res;
    const Adc_Sar_Ip_DataAlignedType DataAlign = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->DataAlign;

    /* If BypassResolution enabled, number of bits in results always are 15 even the resolution is lower than. */
    if (FALSE == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->BypassResolution)
    {
        Res = Adc_Ipw_au8AvailableResolutions[(uint8)(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->AdcResolution)];
    }
    else
    {
        Res = ADC_SAR_IP_RESULT_RESOLUTION;
    }
#endif /*ADC_DMA_SUPPORTED*/

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    ChannelCount = GroupPtr->AssignedChannelCount;
#endif
    /* Get index of last completed sample */
    ResultIndex = Adc_axGroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1U;
    if ((Adc_StreamNumSampleType)0U == Adc_axGroupStatus[Group].ResultIndex)
    {
        ResultIndex = GroupPtr->NumSamples - (Adc_StreamNumSampleType)1U;
    }

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    /* Get the result buffer pointer */
    if (FALSE == GroupPtr->StreamResultGroupMultiSets)
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
    {
        ResultPtr = (Adc_ValueGroupType *)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[ResultIndex]));
        DestOffset = GroupPtr->NumSamples;

        /* Copy results of last conversion from streaming buffer to internal buffer */
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId])
        {
            for (Index = 0U; Index < ChannelCount; Index++)
            {
                Adc_Ipw_MaskConvResult((*ResultPtr), &AdcResult, TRUE, Res, DataAlign);
                DataPtr[Index] = AdcResult.ConvData;
                ResultPtr = &(ResultPtr[DestOffset]);
            }
        }
        else
#endif /* ADC_DMA_SUPPORTED */
        {
            for (Index = 0U; Index < ChannelCount; Index++)
            {
                /* When DMA disabled, results are already masked by Adc_Sar_Ip_GetConvResult.*/
                DataPtr[Index] = (*ResultPtr);
                ResultPtr = &(ResultPtr[DestOffset]);
            }
        }
    }
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    else
    {
        ResultPtr = (Adc_ValueGroupType *)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[ResultIndex * ChannelCount]));
        /* Copy results of last conversion from streaming buffer to internal buffer */
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId])
        {
            for (Index = 0U; Index < ChannelCount; Index++)
            {
                Adc_Ipw_MaskConvResult(ResultPtr[Index], &AdcResult, TRUE, Res, DataAlign);
                DataPtr[Index] = AdcResult.ConvData;
            }
        }
        else
#endif /* ADC_DMA_SUPPORTED */
        {
            for (Index = 0U; Index < ChannelCount; Index++)
            {
                /* When DMA disabled, results are already masked by Adc_Sar_Ip_GetConvResult.*/
                DataPtr[Index] = ResultPtr[Index];
            }
        }
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
}


#if (ADC_IPW_SDADC_IS_USED == STD_ON)

static inline Std_ReturnType Adc_Ipw_ReadGroupNoIntSdAdc(const Adc_GroupType Group,
                                                         Adc_ValueGroupType * DataPtr,
                                                         boolean * Flag,
                                                         uint8 UserId)
{
    const Adc_GroupType              GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    const Adc_HwUnitType        LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const Adc_HwUnitType       PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    Std_ReturnType                 ReadGroupRet = (Std_ReturnType)E_OK;
    uint32                            ConvLength;
    uint16                            ConvData = 0U;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    const uint32 AdcDmaLogicChId = (uint32) Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
#endif /*ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED*/
#else
    /* Avoid compiler warning */
    (void)Flag;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

    /* Get the last converted sample */
#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
    if ( (ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) &&
         (FALSE   == GroupPtr->AdcWithoutDma)
       )
    {
        /* Get the result from DMA buffer */
        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            ConvData = (uint16)(Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][0U]);
        }
        else
        {
            ConvData = Adc_axGroupStatus[Group].ResultsBufferPtr[0U];
        }

        /* Check if the result is valid */
        if (ADC_IPW_INVALID_DATA_RESULT_DMA == ConvData)
        {
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;  /* Invalid data */
        }
        else
        {
            /* Because the conversion was completed, the buffer needs to be reset to invalid value before starting next conversion */
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                Adc_Ipw_au32DmaNoIrqBuffer[PhysicalHwUnitId][0U] = ADC_IPW_INVALID_DATA_RESULT_DMA;
            }
            else
            {
                Adc_axGroupStatus[Group].ResultsBufferPtr[0U] = ADC_IPW_INVALID_DATA_RESULT_DMA;
            }
        }
    }
    else
#endif /*ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED */
    {
        /* Get the result from hardware */
        ConvLength = Sdadc_Ip_GetConvData((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET, 1U, (sint16 *)(&ConvData) );
        /* Check if the result is valid */
        if (ConvLength != 1U)
        {
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;  /* Invalid data */
        }
    }

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Checks if conversion values are in the configured range */
    if (TRUE == GroupPtr->AdcGroupLimitcheck)
    {
        if (FALSE == Adc_Ipw_CheckConversionValuesInRange(ConvData, LogicalHwUnitId, GroupPtr->AssignmentPtr[0U], UserId))
        {
            *Flag = FALSE;
            /* SWS_Adc_00448, SWS_Adc_00449, SWS_Adc_00450 */
            Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;
#ifdef ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED
            if ((ADC_DMA == Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId]) && ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable))
            {
                /* If the Result Conversion is out of range, need to reset Destination Address to previous Buffer Address. */
                /* Because the Destination Offset for Streaming Group that has one channel configured be 4U to reducing additional in the callback. */
                if (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
                {
                    LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                    LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                }
            }
#endif /*ADC_ANY_UNIT_SDADC_DMA_TRANSFER_USED*/
        }
        else
        {
            Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
        }
    }
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

    /* Copy data to user's buffer */
    if ((Std_ReturnType)E_OK == ReadGroupRet)
    {
        DataPtr[0U] = ConvData;
    }

    return ReadGroupRet;
}


static inline Std_ReturnType Adc_Ipw_ReadGroupSdAdc(const Adc_GroupType Group,
                                                    Adc_ValueGroupType * DataPtr,
                                                    boolean * Flag,
                                                    uint8 UserId)
{
    Std_ReturnType                 ReadGroupRet = (Std_ReturnType)E_OK;
    const Adc_GroupType              GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    const Adc_HwUnitType        LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    Adc_StreamNumSampleType         ResultIndex;

    /* If the group is configured for without interrupts */
    if ((uint8)STD_ON == GroupPtr->AdcWithoutInterrupt)
    {
        /* Return error if group is not at the first of queue */

#if (STD_ON == ADC_HW_TRIGGER_API)
        if (ADC_TRIGG_SRC_HW == GroupPtr->TriggerSource)
        {
            if (Group != Adc_axUnitStatus[LogicalHwUnitId].OngoingHwGroup)
            {
                ReadGroupRet = (Std_ReturnType)E_NOT_OK;
            }
        }
        else
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
        {
            if (Group != Adc_axUnitStatus[LogicalHwUnitId].SwNormalQueue[0U])
            {
                ReadGroupRet = (Std_ReturnType)E_NOT_OK;
            }
        }

        if ((Std_ReturnType)E_OK == ReadGroupRet)
        {
            ReadGroupRet = Adc_Ipw_ReadGroupNoIntSdAdc(Group, DataPtr, Flag, UserId);
        }
    }
    else  /* If the group is configured with interrupts */
    {
        if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
        {
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Get index of last completed sample */
            if ((Adc_StreamNumSampleType)0U == Adc_axGroupStatus[Group].ResultIndex)
            {
                ResultIndex = GroupPtr->NumSamples - (Adc_StreamNumSampleType)1U;
            }
            else
            {
                ResultIndex = Adc_axGroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1U;
            }

            /* Result is already available in Group's buffer */
            DataPtr[0U] = Adc_axGroupStatus[Group].ResultsBufferPtr[ResultIndex];
        }
    }

    return ReadGroupRet;
}

#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */


/**
* @brief          This function reads the converted data for the requested group.
* @details        Reads the converted data for the requested group.
*
* @param[in]      Group           The group number.
* @param[in]      DataPtr        Pointer to a buffer which will be filled by the
*                                 conversion results.
* @param[in]      Flag
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
Std_ReturnType Adc_Ipw_ReadGroup(const Adc_GroupType Group,
                                 Adc_ValueGroupType * DataPtr,
                                 boolean * Flag,
                                 uint8 UserId)
{
    Std_ReturnType ReadGroupRet;

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    const Adc_GroupType              GroupIndex = Adc_apxCfgPtr[UserId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[UserId]->GroupsPtr[GroupIndex]);
    const Adc_HwUnitType        LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const Adc_HwUnitType       PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];

    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        ReadGroupRet = Adc_Ipw_ReadGroupSdAdc(Group, DataPtr, Flag, UserId);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        ReadGroupRet = Adc_Ipw_ReadGroupAdcSar(Group, DataPtr, Flag, UserId);
    }

    return ReadGroupRet;
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_ENABLE_READ_RAW_DATA_API == STD_ON)
/* Get the Conversion Data of Channel */
Std_ReturnType Adc_Ipw_GetConvData(Adc_HwUnitType Unit,
                                   Adc_ChannelType ChnIdx,
                                   uint8 UserId,
                                   uint16 * Result)
{
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    Std_ReturnType ValidStatus = (Std_ReturnType)E_OK;

#if (ADC_IPW_SDADC_IS_USED == STD_ON) 
    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        if(1U != Sdadc_Ip_GetRawConvDataFifo(((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET), 1U, (sint16 *)Result))
        {
            ValidStatus = E_NOT_OK;
        }
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        *Result = Adc_Sar_Ip_GetConvData(PhysicalHwUnitId, (uint32)ChnIdx);
    }

    return ValidStatus;
}
#endif /* (ADC_ENABLE_READ_RAW_DATA_API == STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)

/* Limit check for ADCSAR and SDADC (Both Sign and Unsign cases) */
static inline boolean Adc_Ipw_IsValueInRange(const Adc_ValueGroupType Value,
                                             const Adc_ChannelRangeSelectType ChRange,
                                             const Adc_ValueGroupType LowLimit,
                                             const Adc_ValueGroupType HighLimit,
                                             const boolean SignChecking)
{
    boolean ValInRange = FALSE;

    /* Local variables to perform the checks in both signed and unsigned cases */
    sint32 LocalLowLimit;
    sint32 LocalHighLimit;
    sint32 LocalValueLimit;

    if (TRUE == SignChecking)
    {
        /* Cast through "sint16" first to preserve signed bit */
        LocalLowLimit   = (sint32)( (sint16)LowLimit  );
        LocalHighLimit  = (sint32)( (sint16)HighLimit );
        LocalValueLimit = (sint32)( (sint16)Value     );
    }
    else
    {
        /* Cast directly to "sint32" to ignore sign bit */
        LocalLowLimit   = (sint32)( LowLimit  );
        LocalHighLimit  = (sint32)( HighLimit );
        LocalValueLimit = (sint32)( Value     );
    }

    switch (ChRange)
    {
        /* Complete range - independent from channel limit settings. */
        case ADC_RANGE_ALWAYS:
        {
            ValInRange = TRUE;
            break;
        }

        /* Range between low limit and high limit - high limit value included. */
        case ADC_RANGE_BETWEEN:
        {
            if ((LocalValueLimit > LocalLowLimit) && (LocalValueLimit <= LocalHighLimit))
            {
                ValInRange = TRUE;
            }
            break;
        }

        /* Range above high limit or below low limit - low limit value included. */
        case ADC_RANGE_NOT_BETWEEN:
        {
            if ((LocalValueLimit > LocalHighLimit) || (LocalValueLimit <= LocalLowLimit))
            {
                ValInRange = TRUE;
            }
            break;
        }

        /* Range below high limit -high limit value included. */
        case ADC_RANGE_NOT_OVER_HIGH:
        {
            if (LocalValueLimit <= LocalHighLimit)
            {
                ValInRange = TRUE;
            }
            break;
        }
        /* Range above low limit. */
        case ADC_RANGE_NOT_UNDER_LOW:
        {
            if (LocalValueLimit > LocalLowLimit)
            {
                ValInRange = TRUE;
            }
            break;
        }

        /* Range above high limit. */
        case ADC_RANGE_OVER_HIGH:
        {
            if (LocalValueLimit > LocalHighLimit)
            {
                ValInRange = TRUE;
            }
            break;
        }

        /* Range below low limit - low limit value included. */
        case ADC_RANGE_UNDER_LOW:
        {
            if (LocalValueLimit <= LocalLowLimit)
            {
                ValInRange = TRUE;
            }
            break;
        }

        /* Unexpected value */
        default:
        {
            ; /* no-op */
            break;
        }
    }

    return ValInRange;
}

/**
* @brief          Checks if conversion values are in the configured range.
* @details        Return true if conversion values are in the configured range, otherwise false.
*
* @param[in]      value       Adc conversion value.
*                 Unit        Adc Hardware Unit.
*                 Index       Adc channel index assigned to a group.
*                 UserId       Current UserId
*
* @return         boolean     Conversion value in range flag.
* @retval         TRUE        if conversion values are in the configured range.
* @retval         FALSE       if conversion values are not in the configured range.
*
* @pre            Driver must be initialized.
*/
boolean Adc_Ipw_CheckConversionValuesInRange(Adc_ValueGroupType Value,
                                             Adc_HwUnitType LogicalHwUnitId,
                                             Adc_ChannelType ChannelIndex,
                                             uint8 UserId)
{
    const Adc_ChannelLimitCheckingType * const LimitCfg = &(Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcIpwChannelConfig[LogicalHwUnitId][ChannelIndex].ChannelLimitCheckingConfig);
    Adc_ValueGroupType LocalValue = Value;
    boolean SignCheck             = FALSE;
    boolean ValInRange;

#if (STD_ON == ADC_IPW_SDADC_IS_USED)
    const Adc_HwUnitType          PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
    const Sdadc_Ip_ResolutionType SdAdcResolution  = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->SdadcConfigPtrArr[LogicalHwUnitId]->Resolution;

    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        if (SDADC_IP_RESOLUTION_16 == SdAdcResolution)
        {
            SignCheck = TRUE;
        }
    }
    else
#endif
    {
        /* ADCSAR */
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    LocalValue = (LocalValue & ADC_IPW_DATA_MASK_U16) >> (16U - ADC_SAR_IP_RESULT_RESOLUTION);
#else
    LocalValue =  LocalValue & (ADC_IPW_DATA_MASK_U16 >> (16U - ADC_SAR_IP_RESULT_RESOLUTION));
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */
    }

    ValInRange = Adc_Ipw_IsValueInRange(LocalValue, LimitCfg->ChannelRange, LimitCfg->ChannelLowLimit, LimitCfg->ChannelHighLimit, SignCheck);

    return ValInRange;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
 * @brief   Function to reconfigure High and Low thresholds for a given threshold control index.
 * @details This function is used to reconfigure High and Low thresholds for a given threshold control index.
 *
 * @param[in]  ThresholdControlIndex Symbolic names of threshold control register with encoded value
 * @param[in]  LowValue              Low threshold value of the threshold control
 * @param[in]  HighValue             High threshold value of the threshold control
 * @param[in]  UserId                Current UserId
 *
 * @return         Std_ReturnType    E_OK or E_NOT_OK.
 * @retval         E_OK              All checking is ok.
 * @retval         E_NOT_OK          Threshold control index is out of range or the configured threshold control is disabled.
 */
Std_ReturnType Adc_Ipw_ConfigureThreshold(Adc_ThresholdControlIndexType ThresholdControlIndex,
                                          Adc_ValueGroupType LowValue,
                                          Adc_ValueGroupType HighValue,
                                          uint8 UserId)
{
    Std_ReturnType Status;

#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    const Adc_HwUnitType  LogicalHwUnitId = (uint8)(ThresholdControlIndex >> ADC_THRESHOLD_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16);
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];

    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
       /* SDADC */
       Status = Adc_Ipw_ConfigureThresholdSdAdc(ThresholdControlIndex, LowValue, HighValue, UserId);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
       /* ADCSAR */
       Status = Adc_Ipw_ConfigureThresholdAdcSar(ThresholdControlIndex, LowValue, HighValue, UserId);
    }

    return Status;
}
#endif /* if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

#ifdef ADC_WDG_SUPPORTED
/**
 * @brief   Enable notification of a channel that has watchdog functionality configured at initialization
 * @details Enable notification of a channel that has watchdog functionality configured at initialization
 *
 * @param[in]   Unit                Logical Unit Id
 * @param[in]   ChannelId           AUTOSAR Symbolic name of channel
 * @param[in]   UserId           Current UserId
 *
 * @return      Std_ReturnType      E_OK or E_NOT_OK.
 * @retval      E_OK                All checking is ok.
 * @retval      E_NOT_OK            Channel does not have wdg associated/configured at init
 *
 */
Std_ReturnType Adc_Ipw_EnableWdgNotification(Adc_HwUnitType Unit,
                                             Adc_ChannelType ChannelId,
                                             uint8 UserId)
{
    Std_ReturnType                  Status = E_NOT_OK;
    const Adc_HwUnitType  PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_ChannelType LogicalChannelId = ChannelId & ADC_CHANNEL_SYMBOLIC_NAME_MASK_CHANNEL_ID_U16;
    Adc_ChannelType      PhysicalChannelId;

    /* Check to avoid out of bound index */
    if ( (LogicalChannelId < Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcChannels[Unit]) &&
         (NULL_PTR != Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcIpwChannelConfig[Unit][LogicalChannelId].WdgNotification)
       )
    {
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
        if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
        {
            /* SDADC */
            Sdadc_Ip_EnableWatchdog((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET);
        }
        else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
        {
            /* Adc_Sar */
            /* Enable CWENR bit field associated with this channel */
            PhysicalChannelId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->ChannelConfigsPtr[LogicalChannelId].ChanIndex;
            Adc_Sar_Ip_EnableChannelNotifications(PhysicalHwUnitId, PhysicalChannelId, ADC_SAR_IP_CHAN_NOTIF_WDG);
        }

        /* Wdg notif was enabled successfully */
        Status = E_OK;
    }

    return Status;
}

/**
 * @brief   Disable notification of a channel that has watchdog functionality configured at initialization
 * @details Disable notification of a channel that has watchdog functionality configured at initialization
 *
 * @param[in]   Unit                Logical Unit Id
 * @param[in]   ChannelId           AUTOSAR Symbolic name of channel
 * @param[in]   UserId           Current UserId
 *
 * @return      Std_ReturnType      E_OK or E_NOT_OK.
 * @retval      E_OK                All checking is ok.
 * @retval      E_NOT_OK            Channel does not have wdg associated/configured at init
 *
 */
Std_ReturnType Adc_Ipw_DisableWdgNotification(Adc_HwUnitType Unit,
                                              Adc_ChannelType ChannelId,
                                              uint8 UserId)
{
    Std_ReturnType                  Status = E_NOT_OK;
    const Adc_HwUnitType  PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_ChannelType LogicalChannelId = ChannelId & ADC_CHANNEL_SYMBOLIC_NAME_MASK_CHANNEL_ID_U16;
    Adc_ChannelType      PhysicalChannelId;

    /* Check to avoid out of bound index */
    if ( (LogicalChannelId < Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcChannels[Unit]) &&
         (NULL_PTR != Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcIpwChannelConfig[Unit][LogicalChannelId].WdgNotification)
       )
    {
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
        if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
        {
            /* SDADC */
            Sdadc_Ip_DisableWatchdog((uint32)PhysicalHwUnitId - ADC_IPW_SDADC_PHYSICAL_ID_OFFSET);
        }
        else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
        {
            /* Adc_Sar */
            /* Enable CWENR bit field associated with this channel */
            PhysicalChannelId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->ChannelConfigsPtr[LogicalChannelId].ChanIndex;
            Adc_Sar_Ip_DisableChannelNotifications(PhysicalHwUnitId, PhysicalChannelId, ADC_SAR_IP_CHAN_NOTIF_WDG);
        }

        /* Wdg notif was disabled successfully */
        Status = E_OK;
    }

    return Status;
}
#endif /* ADC_WDG_SUPPORTED */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          This function sets the Prescaler value only when ADC is in power down mode.
* @details        Set prescaler clock divider only in power down mode.
*
* @param[in]      Prescaler       ADC_NORMAL, ADC_ALTERNATE.
* @param[in]      UserId          Current UserId
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful set hw unit power mode.
* @retval         E_NOT_OK        In case of unsuccessful set hw unit power mode.
*
*/
Std_ReturnType Adc_Ipw_SetClockMode(Adc_SelectPrescalerType Prescaler,
                                    uint8 UserId)
{
    Adc_HwUnitType LogicalHwUnitId = 0U; /* Logical Unit Id */
    Adc_HwUnitType PhysicalHwUnitId = 0U; /* Physical Hardware Unit Id */
    Adc_Sar_Ip_StatusType AdcSarStatus;
    Adc_Sar_Ip_ClockConfigType AdcNormalClockConfig;
    const Adc_Sar_Ip_ConfigType * AdcPtr;
    Std_ReturnType Status = E_OK;
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    uint8 Iter;
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */

    for (LogicalHwUnitId = 0U; LogicalHwUnitId < ADC_IPW_MAX_HW_UNITS; LogicalHwUnitId++)
    {
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[LogicalHwUnitId] == (uint8)STD_ON) /* HW unit enabled on current partition */
        {
            PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
            AdcPtr = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId];
            if (Prescaler == ADC_NORMAL)
            {
#if FEATURE_ADC_HAS_CONVERSION_TIMING
                for (Iter = 0; Iter < ADC_SAR_IP_NUM_GROUP_CHAN; Iter++)
                {
                    AdcNormalClockConfig.SampleTimeArr[Iter] = AdcPtr->SampleTimeArr[Iter];
                }
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
                AdcNormalClockConfig.ClkSelect = AdcPtr->ClkSelect;
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
                AdcNormalClockConfig.HighSpeedConvEn = AdcPtr->HighSpeedConvEn;
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
                AdcNormalClockConfig.PowerDownDelay = AdcPtr->PowerDownDelay;
#if FEATURE_ADC_HAS_AVERAGING
                AdcNormalClockConfig.AvgEn = AdcPtr->AvgEn;
                AdcNormalClockConfig.AvgSel = AdcPtr->AvgSel;
#endif /* FEATURE_ADC_HAS_AVERAGING */
                AdcSarStatus = Adc_Sar_Ip_SetClockMode(PhysicalHwUnitId, &AdcNormalClockConfig);
            }
            else
            {
                AdcSarStatus = Adc_Sar_Ip_SetClockMode(PhysicalHwUnitId, Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcAltClockConfig[LogicalHwUnitId]);
            }

            if (AdcSarStatus != ADC_SAR_IP_STATUS_SUCCESS)
            {
                Status = E_NOT_OK;
                break;
            }
        }
    }

    return Status;
}
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON)
/**
* @brief          This function sets the PWDN bit while going in power down mode or clears it
*                 upon exit from power down mode.
* @details        Set power down/normal mode.
*
* @param[in]      SetHwUnitPowerMode         ADC_NORMAL_MODE, ADC_POWER_DOWN_MODE.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful set hw unit power mode.
* @retval         E_NOT_OK        In case of unsuccessful set hw unit power mode.
*
*/
Std_ReturnType Adc_Ipw_SetHwUnitPowerMode(Adc_HwUnitType Unit,
                                          Adc_SetPowerModeType SetHwUnitPowerMode,
                                          uint8 UserId)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    if (ADC_POWER_DOWN_MODE == SetHwUnitPowerMode)
    {
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
        /* CTUSTART is reset by HW after each CTU conv is finished only if CTU is in triggered mode */
        if (FALSE == Adc_axUnitStatus[Unit].CtuControlOngoing)
        {
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
            if ((Adc_Sar_Ip_GetStatusFlags(PhysicalHwUnitId) & ADC_SAR_IP_STATUS_FLAG_CTU_STARTED) != 0u)
            {
                ReturnStatus = (Std_ReturnType)E_NOT_OK;
            }
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
        }
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

        /* enter into power-down Mode */
        if (ReturnStatus == (Std_ReturnType)E_OK)
        {
            if (ADC_SAR_IP_STATUS_SUCCESS != Adc_Sar_Ip_Powerdown(PhysicalHwUnitId))
            {
                ReturnStatus = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    else
    {
        /* Exit from PowerDown Mode */
        if (ADC_SAR_IP_STATUS_SUCCESS != Adc_Sar_Ip_Powerup(PhysicalHwUnitId))
        {
            ReturnStatus = (Std_ReturnType)E_NOT_OK;
        }
    }

    return ReturnStatus;
}
#endif /* (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON) */

#if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON))
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
/* The next condition is true if CTU/BCTU Unit is used */
#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
/**
* @brief          This function turns on or puts the CTU unit in power down mode.
* @details        Set CTU power down/normal mode.
*
* @param[in]      CtuUnit         CTU hardware unit
* @param[in]      State           Target power state
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            Transition successful.
* @retval         E_NOT_OK        CTU unit out of range.
*
*/
Std_ReturnType Adc_Ipw_CtuSetPowerMode(Adc_HwUnitType CtuUnit,
                                       Adc_PowerStateType State)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    boolean LowPowerMode = (State == ADC_LOW_POWER) ? TRUE : FALSE;

    /* Check if CTU unit is out of range */
    if (CtuUnit < ADC_IPW_CTU_MAX_HW_UNITS)
    {
        if (State != ADC_NODEFINE_POWER)
        {
            Bctu_Ip_SetLowPowerMode((uint32)CtuUnit, LowPowerMode);
            ReturnStatus = (Std_ReturnType)E_OK;
        }
    }

    return ReturnStatus;
}
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || */
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
#endif /* ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON)) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief          Set the desired power state.
* @details        This API changes power state of ADC module.
*
* @param[in]      PowerState     The power state to set
* @param[in]      UserId         Current UserId
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Power Mode changed.
* @retval         E_NOT_OK:       Request rejected.
*
* @api
*
*/
Std_ReturnType Adc_Ipw_SetPowerState(Adc_PowerStateType PowerState,
                                     uint8 UserId)
{
    Adc_HwUnitType LogicalHwUnitId;
    Adc_HwUnitType PhysicalHwUnitId;
    Adc_Sar_Ip_StatusType AdcSarStatus = ADC_SAR_IP_STATUS_ERROR;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
    uint8 CtuPhysicalId = 0;
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || */
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */

    for (LogicalHwUnitId = 0U; LogicalHwUnitId < ADC_IPW_MAX_HW_UNITS; LogicalHwUnitId++)
    {
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[LogicalHwUnitId] == (uint8)STD_ON) /* HW unit enabled on current partition */
        {
            PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[LogicalHwUnitId];
            #if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
            /* The next condition is true if CTU/BCTU Unit is used */
            #if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
                /* Mapping PhysicalHwUnitId to CtuPhysicalId */
                CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];
                ReturnValue = Adc_Ipw_CtuSetPowerMode(CtuPhysicalId, PowerState);
            #endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || */
            #endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
            if (ADC_FULL_POWER == PowerState)
            {
                /* comes out from PowerDown */
                AdcSarStatus = Adc_Sar_Ip_Powerup(PhysicalHwUnitId);
            }
            else if (ADC_LOW_POWER == PowerState)
            {
                /* enter into power-down mode */
                AdcSarStatus = Adc_Sar_Ip_Powerdown(PhysicalHwUnitId);
            }
            else
            {
                ; /* Empty else branch to avoid MISRA */
            }

            if ((AdcSarStatus != ADC_SAR_IP_STATUS_SUCCESS) || (ReturnValue != (Std_ReturnType)E_OK))
            {
                ReturnValue = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

    return ReturnValue;
}
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
void Adc_Ipw_Calibrate(Adc_HwUnitType Unit,
                       Adc_CalibrationStatusType * Status,
                       uint8 UserId)
{
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    Status->AdcUnitSelfTestStatus = E_OK;

    /* Call IPL calibration function */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        PhysicalHwUnitId -= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
        if (SDADC_IP_STATUS_SUCCESS != Sdadc_Ip_DoCalibration(PhysicalHwUnitId))
        {
            Status->AdcUnitSelfTestStatus = E_NOT_OK;
        }
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        if (ADC_SAR_IP_STATUS_SUCCESS != Adc_Sar_Ip_DoCalibration(PhysicalHwUnitId))
        {
            Status->AdcUnitSelfTestStatus = E_NOT_OK;
        }
    }
}

Std_ReturnType Adc_Ipw_SetUserGainAndOffset(const Adc_HwUnitType Unit,
                                            const uint8 UserId,
                                            const Adc_UserGainType Gain,
                                            const Adc_UserOffsetType Offset)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Call IPL set user gain and offset function */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* SDADC */
        PhysicalHwUnitId -= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
        Sdadc_Ip_SetUserGainAndOffset(PhysicalHwUnitId, (sint32)Gain, (sint32)Offset);
    }
    else
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    {
        /* ADCSAR */
        Adc_Sar_Ip_SetUserGainAndOffset(PhysicalHwUnitId, (uint16)Gain, (uint8)Offset);
    }

    return ReturnValue;
}
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_APPLY_CALIBRATION == STD_ON)
Std_ReturnType Adc_Ipw_ApplyCalibration(const Adc_HwUnitType Unit,
                                        const uint8 UserId,
                                        const uint32 BufferLength,
                                        const sint16 * const UncalibratedBuffer,
                                        sint16 * const CalibratedBuffer)
{
    Std_ReturnType ReturnValue      = (Std_ReturnType)E_NOT_OK;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    if (PhysicalHwUnitId >= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET)
    {
        /* Call IPL apply calibration function */
        PhysicalHwUnitId -= ADC_IPW_SDADC_PHYSICAL_ID_OFFSET;
        Sdadc_Ip_ApplyCalibration(PhysicalHwUnitId, BufferLength, UncalibratedBuffer, CalibratedBuffer);
        /* Mark return value as successful */
        ReturnValue = (Std_ReturnType)E_OK;
    }

    return ReturnValue;
}
#endif /* ADC_APPLY_CALIBRATION == STD_ON */

#if (ADC_SELF_TEST == STD_ON)
Std_ReturnType Adc_Ipw_SelfTest(Adc_HwUnitType Unit,
                                uint8 UserId)
{
    Adc_Sar_Ip_StatusType AdcSarStatus;
    Std_ReturnType Status = (Std_ReturnType)E_NOT_OK;
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    AdcSarStatus = Adc_Sar_Ip_SelfTest(PhysicalHwUnitId);

    if (AdcSarStatus == ADC_SAR_IP_STATUS_SUCCESS)
    {
        Status = (Std_ReturnType)E_OK;
    }
    else if (AdcSarStatus == ADC_SAR_IP_STATUS_ERROR)
    {
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }

    return Status;
}
#endif /* ADC_SELF_TEST == STD_ON */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
 * @brief   Function to enable CTU control mode for an ADC unit.
 *
 * @details Enable CTU control mode for an ADC unit.
 *          This function to enable CTU control mode for Adc. When a unit works in CTU control mode,
 *          no other conversions shall run in parallel(Adc). The only conversions occurring shall be
 *          the ones defined in the CTU configuration.
 *
 * @param[in]      AdcLogicalId      ADC Logical Unit Id.
 * @param[in]      UserId            Current UserId
 *
 * @note    The function Service ID[hex]: 0x39.
 *
 * @return       Std_ReturnType  Standard return type.
 * @retval       E_OK:           All checking conditions are valid
 * @retval       E_NOT_OK:       CTU unit is not configured for this ADC unit
 * @api
 */
Std_ReturnType Adc_Ipw_EnableCtuControlMode(Adc_HwUnitType Unit,
                                  uint8 UserId)
{
    uint8 Index;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    boolean AlreadyCall = FALSE;
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];
    const uint8 CtuLogicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuPhyToLogId[CtuPhysicalId];
    Adc_HwUnitType TempAdcPhysicalId;

    (void)Adc_Sar_Ip_SetCtuMode(PhysicalHwUnitId, ADC_SAR_IP_CTU_MODE_CONTROL);

    /* Check are there any Adc Unit which was enabled Ctu Control Mode to avoid duplication of init Bctu */
    for (Index = 0U; Index < ADC_IPW_MAX_HW_UNITS; Index++)
    {
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[Index] == (uint8)STD_ON) /* HW unit enabled on current partition */
        {
            TempAdcPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Index];
            if ((CtuPhysicalId == Adc_Ipw_au8AdcIdToCtuId[TempAdcPhysicalId]) && (TRUE == Adc_axUnitStatus[Index].CtuControlOngoing))
            {
                AlreadyCall = TRUE;
                break;
            }
        }
    }
    /* Mark the unit as CTU control mode is ongoing */
    Adc_axUnitStatus[Unit].CtuControlOngoing = TRUE;

    if (FALSE == AlreadyCall)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
#if (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON)
        /* Stop BCTU triggered mode */
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigTriggerMode[CtuPhysicalId] != NULL_PTR)
        {
            (void)Bctu_Ip_Deinit(CtuPhysicalId);
        }
#endif /* (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) */
        /* Start CTU control */
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigControlMode[CtuLogicalId] != NULL_PTR)
        {
            /* Start BCTU control */
            Bctu_Ip_Init(CtuPhysicalId, Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigControlMode[CtuLogicalId]);
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
    }

    return ReturnValue;
}

/**
 * @brief   Function to disable CTU control mode for an ADC unit.
 *
 * @details Disable CTU control mode for an ADC unit.
 *          This function to disable CTU control mode for Adc. The other Adc conversions can run in
 *          software trigger normal mode, software trigger injected mode or hardware trigger mode.
 *
 * @param[in]  AdcLogicalId   ADC Logical Unit Id.
 * @param[in]  UserId         Current UserId
 *
 * @note    The function Service ID[hex]: 0x4A.
 *
 * @api
 */
void Adc_Ipw_DisableCtuControlMode(Adc_HwUnitType Unit,
                                   uint8 UserId)
{
    uint8 Index;
    boolean LastCall = TRUE;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[PhysicalHwUnitId];
    Adc_HwUnitType TempPhysicalHwUnitId;

    /* Mark the unit as CTU control mode is not ongoing */
    Adc_axUnitStatus[Unit].CtuControlOngoing = FALSE;

    for (Index = 0U; Index < ADC_IPW_MAX_HW_UNITS; Index++)
    {
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.AdcHwUnitArr[Index] == (uint8)STD_ON) /* HW unit enabled on current partition */
        {
            TempPhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Index];
            if ((TRUE == Adc_axUnitStatus[Index].CtuControlOngoing) && (CtuPhysicalId == Adc_Ipw_au8AdcIdToCtuId[TempPhysicalHwUnitId]))
            {
                LastCall = FALSE;
                break;
            }
        }
    }

    if (TRUE == LastCall)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        /* Stop BCTU control */
        (void)Bctu_Ip_Deinit(CtuPhysicalId);
#if (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON)
        if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigTriggerMode[CtuPhysicalId] != NULL_PTR)
        {
            Bctu_Ip_Init(CtuPhysicalId, Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigTriggerMode[CtuPhysicalId]);
        }
#endif /* (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) */
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
    }

#if (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON)
    if (Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->CtuConfigTriggerMode[CtuPhysicalId] != NULL_PTR)
    {
        (void)Adc_Sar_Ip_SetCtuMode(PhysicalHwUnitId, ADC_SAR_IP_CTU_MODE_TRIGGER);
    }
    else
#endif /* (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) */
    {
        (void)Adc_Sar_Ip_SetCtuMode(PhysicalHwUnitId, ADC_SAR_IP_CTU_MODE_DISABLED);
    }
}

/**
 * @brief   Function to read CTU Fifo data.
 *
 * @details This function returns the conversion result data stored in
 * the BCTU result FIFO at the given index.
 *
 * @param[in]  CtuLogicalId       CTU logical Id
 * @param[in]  FifoIdx            CTU Fifo index
 *
 * @api
 */
uint16 Adc_Ipw_CtuReadFifoData(uint32 CtuLogicalId,
                               uint8 FifoIdx,
                               uint8 UserId)
{
    uint16 Data = 0u;
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Data = Bctu_Ip_GetFifoData(CtuPhysicalId, FifoIdx);

    return Data;
}

/**
 * @brief   This function enables notifications selected by the given mask
 * on the selected BCTU instance.
 *
 * @param[in]  UserId             User id
 * @param[in]  CtuLogicalId       CTU logical ID
 * @param[in]  NotificationMask   CTU notifications to be enabled
 *
 * @api
 */
void Adc_Ipw_CtuEnableNotification(const uint8 UserId,
                                   const uint32 CtuLogicalId,
                                   const uint32 NotificationMask)
{
    const uint8 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_EnableNotifications(CtuPhysicalId, NotificationMask);
}

/**
 * @brief   This function disables notifications selected by the given mask
 * on the selected BCTU instance.
 *
 * @param[in]  UserId             User id
 * @param[in]  CtuLogicalId       CTU logical ID
 * @param[in]  NotificationMask   CTU notifications to be disabled
 *
 * @api
 */
void Adc_Ipw_CtuDisableNotification(const uint8 UserId,
                                    const uint32 CtuLogicalId,
                                    const uint32 NotificationMask)
{
    const uint8 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_DisableNotifications(CtuPhysicalId, NotificationMask);
}

/**
 * @brief   Function to enable hw input signal.
 *
 * @details This function clears any eventual pending hw input signals already
 * occurred on the selected trigger and enables new occurrences of the hw input signals
 * to start new conversions
 *
 * @param[in]  CtuLogicalId          CTU logical Id
 * @param[in]  TrigIdx               Trigger index
 * @param[in]  UserId                User id
 *
 */
void Adc_Ipw_CtuEnableHwTrigger(const uint32 CtuLogicalId,
                                const uint8 TrigIdx,
                                const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_EnableHwTrigger(CtuPhysicalId, TrigIdx);
}

/**
 * @brief   Function to disable hw input signal.
 *
 * @details This function prevents the selected BCTU trigger to start
 * new conversions on the occurrence of a hw input signal and also new conversions
 * in an on-going conversion loop (loop flag enabled).
 *
 * @param[in]  CtuLogicalId          CTU logical Id
 * @param[in]  TrigIdx               Trigger index
 * @param[in]  UserId                User id
 *
 */
void Adc_Ipw_CtuDisableHwTrigger(const uint32 CtuLogicalId,
                                 const uint8 TrigIdx,
                                 const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_DisableHwTrigger(CtuPhysicalId, TrigIdx);
}

/**
 * @brief   This function triggers a conversion or list of conversions associated
 * with a trigger index.
 *
 * @param[in]  CtuLogicalId          CTU logical Id
 * @param[in]  TrigIdx               Trigger index
 * @param[in]  UserId                User id
 *
 */
void Adc_Ipw_CtuStartConversion(const uint32 CtuLogicalId,
                                const uint8 TrigIdx,
                                const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_SwTriggerConversion(CtuPhysicalId, TrigIdx);
}

/**
 * @brief   This function returns the current conversion result data
 * corresponding to an adc instance.
 *
 * @param[in]  AdcIdx          Adc Hardware Instance
 *
 */
uint16 Adc_Ipw_CtuReadConvData(const uint8 AdcIdx)
{
    uint16 ConvData;
    const uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[AdcIdx];

    ConvData = Bctu_Ip_GetConvData(CtuPhysicalId, AdcIdx);

    return ConvData;
}

/**
 * @brief   his function returns the full conversion result information
 * corresponding to an adc instance.
 *
 * @param[in]  AdcIdx          Adc Hardware Instance
 * @param[in]  ConvResultPtr   Full information of the conversion result
 *
 */
void Adc_Ipw_CtuReadConvResult(const uint8 AdcIdx, Adc_CtuResultType * ConvResultPtr)
{
    const uint8 CtuPhysicalId = Adc_Ipw_au8AdcIdToCtuId[AdcIdx];

    Bctu_Ip_GetConvResult(CtuPhysicalId, AdcIdx, ConvResultPtr);
}

/**
 * @brief   This function returns the full conversion result information
 * that is stored in the BCTU result FIFO at the given index.
 *
 * @param[in]  CtuLogicalId          CTU logical Id
 * @param[in]  FifoIdx               Fifo index
 * @param[in]  Results               Conversion result
 * @param[in]  UserId                User id
 *
 */
void Adc_Ipw_CtuReadFifoResult(const uint32 CtuLogicalId,
                               const uint8 FifoIdx,
                               Bctu_Ip_FifoResultType * const Results,
                               const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_GetFifoResult(CtuPhysicalId, FifoIdx, Results);
}

/**
 * @brief   Function to enable sw trigger on corresponding trigger index.
 *
 * @details This function gets the full conversion result information, with
 * the conversion data aligned according to the alignment parameter.
 *
 * @param[in]  CtuLogicalId          CTU logical Id
 * @param[in]  FifoIdx               Fifo index
 * @param[in]  Results               Conversion result
 * @param[in]  UserId                User id
 *
 */
void Adc_Ipw_CtuSetFifoWatermark(const uint32 CtuLogicalId,
                                 const uint8 FifoIdx,
                                 const uint8 Watermark,
                                 const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_SetFifoWatermark(CtuPhysicalId, FifoIdx, Watermark);
}

/**
 * @brief   This function sets the conversion list using an array of ListItemType structures.
 * Also marks the element corresponding to the last channel in the array, as last element in the list.
 * Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
 *
 * @param[in]  CtuLogicalId          CTU logical Id
 * @param[in]  StartListElemIdx      Start command address
 * @param[in]  AdcCmdArray           Command list
 * @param[in]  NumCmds               Number of command
 * @param[in]  UserId                User id
 *
 */
void Adc_Ipw_CtuSetList(const uint32 CtuLogicalId,
                        const uint8 StartListElemIdx,
                        const Bctu_Ip_ListItemType * const ConvListItems,
                        const uint8 NumItems,
                        const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    Bctu_Ip_ConfigChanList(CtuPhysicalId, StartListElemIdx, ConvListItems, NumItems);
}

/**
 * @brief   Attempts to configure the first address of the command list
 * associated with an internal trigger or channel. If there is an on-going conversion started via
 * target trigger, it only disables the trigger (will ignore any new triggers)
 * and returns error code.
 *
 * @param[in]  CtuLogicalId         CTU logical Id
 * @param[in]  TrigIdx              Trigger index
 * @param[in]  AdcCmdAddress        First command address
 * @param[in]  UserId               User id
 *
 */
void Adc_Ipw_CtuSetListPointer(const uint32 CtuLogicalId,
                               const uint32 TrigIdx,
                               const uint8 ChnOrListAddr,
                               const uint8 UserId)
{
    const uint32 CtuPhysicalId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.CtuLogToPhyId[CtuLogicalId];

    (void)Bctu_Ip_SetTriggerChnListAddr(CtuPhysicalId, (uint8)TrigIdx, TRUE, ChnOrListAddr);
}
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if ADC_SAR_IP_HAS_TEMPSENSE_CHN
#if (ADC_ENABLE_TEMPSENSE_API == STD_ON)
/**
 * @brief Get the temperature on chip directly.
 *
 * @details This function starts a normal software conversion on tempsense channel and calculates
 *          the temperature on chip from the data conversion
 *
 * @param[in]  Unit                ADC Unit Id.
 * @param[in]  TempInstance     Tempsense Unit Id.
 * @param[out] TempSenseVal       Temperature value on chip.
 *
 * @return         Std_ReturnType  Standard return type.
 *                 E_OK:           Temperature read successfully
 *                 E_NOT_OK:       An error occurred
 *
 * @api
 */
Std_ReturnType Adc_Ipw_TempSenseGetTemp(Adc_HwUnitType Unit,
                                        const uint32 TempInstance,
                                        uint16 * const TempSenseVal,
                                        uint8 UserId)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    Adc_Sar_Ip_StatusType IpStatus;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    IpStatus = Adc_Sar_Ip_TempSenseGetTemp(PhysicalHwUnitId, TempInstance, TempSenseVal);
    if (IpStatus == ADC_SAR_IP_STATUS_SUCCESS)
    {
        ReturnStatus = (Std_ReturnType)E_OK;
    }

    return ReturnStatus;
}
#endif /* (ADC_ENABLE_TEMPSENSE_API == STD_ON) */
#endif /* ADC_SAR_IP_HAS_TEMPSENSE_CHN */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
 * @brief Get the Hw Trigger index.
 *
 * @details This function returns the Hw Trigger index in AdcHwTrigger array.
 *
 * @param[in]  TriggerSource      Trigger source
 * @param[in]  UserId             Current UserId.
 * @param[out] TriggerIndex       Trigger index
 *
 * @return         boolean         TRUE if trigger source is within configured triggers / FALSE otherwise
 *
 */
boolean Adc_Ipw_MapCTUTriggerIndex(Adc_HwTriggerTimerType TriggerSource,
                                   uint8 UserId,
                                   uint8 * TriggerIndex)
{
    uint8 TriggerIdx;
    uint8 TrigIdx;
    boolean Found = FALSE;
    const uint8 * HwTriggerSource = &Adc_apxCfgPtr[UserId]->AdcIpwConfigPtr->Mapping.HwTriggIndex[0U];

    *TriggerIndex = 0U;
    for (TriggerIdx = 0U; TriggerIdx < ADC_IPW_MAX_HARDWARE_TRIGGERS; TriggerIdx++)
    {
        TrigIdx = HwTriggerSource[TriggerIdx];
        if (TriggerSource == TrigIdx)
        {
            Found = TRUE;
            *TriggerIndex = TriggerIdx;
            break;
        }
    }
    return Found;
}
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */

/**
* @brief        This function returns the id of the Partition from which it is called.
* @details      This function returns the result of the OsIf_GetUserID OS function
*               (which is called in the appropriate context depending on USER MODE)
*               If the multipartition feature is disabled for ADC, this function will return 0.
*
* @param[in]    void
*
* @return       uint8   the Partition Id number.
*/
uint8 Adc_GetUserID(void)
{
    uint8 PartitionValue;

#if (ADC_MULTIPARTITION_SUPPORT == STD_ON)
    PartitionValue = (uint8)OsIf_GetUserId();
#else
    PartitionValue = 0U;
#endif /* (ADC_MULTIPARTITION_SUPPORT == STD_ON) */
    return PartitionValue;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
