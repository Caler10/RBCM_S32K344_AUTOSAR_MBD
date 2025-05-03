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

/** @cond DRIVER_INTERNAL_USE_ONLY */

/**
*   @file DSPSS_Api.c
*
*   @addtogroup sd_adc_ip Sd Adc IPL
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "DSPSS_Api.h"
#include "DSPSS_CFSDADC_PMEM.h"
#include "DSPSS_CFSDADC_XMEM.h"
#include "SchM_Adc.h"


#if (SDADC_IP_DSPSS_ENABLED == STD_ON)


#ifdef SDADC_IP_DSPSS_INIT_DMA_CHANNEL
#include "Dma_Ip.h"
#include "Dma_Ip_Hw_Access.h"  /* for using "Dma_Ip_uintPtrType" */
#endif /* SDADC_IP_DSPSS_INIT_DMA_CHANNEL */


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DSPSS_VENDOR_ID_API_C                      43
#define DSPSS_AR_RELEASE_MAJOR_VERSION_API_C       4
#define DSPSS_AR_RELEASE_MINOR_VERSION_API_C       7
#define DSPSS_AR_RELEASE_REVISION_VERSION_API_C    0
#define DSPSS_SW_MAJOR_VERSION_API_C               5
#define DSPSS_SW_MINOR_VERSION_API_C               0
#define DSPSS_SW_PATCH_VERSION_API_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if DSPSS_Api.c file and DSPSS_Api.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_API_C != DSPSS_VENDOR_ID_API)
    #error "DSPSS_Api.c and DSPSS_Api.h have different vendor ids"
#endif

/* Check if DSPSS_Api.c file and DSPSS_Api.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API_C != DSPSS_AR_RELEASE_MAJOR_VERSION_API) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API_C != DSPSS_AR_RELEASE_MINOR_VERSION_API) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_API_C != DSPSS_AR_RELEASE_REVISION_VERSION_API) \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.c and DSPSS_Api.h are different"
#endif

/* Check if DSPSS_Api.c file and DSPSS_Api.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_API_C != DSPSS_SW_MAJOR_VERSION_API) || \
     (DSPSS_SW_MINOR_VERSION_API_C != DSPSS_SW_MINOR_VERSION_API) || \
     (DSPSS_SW_PATCH_VERSION_API_C != DSPSS_SW_PATCH_VERSION_API) \
    )
  #error "Software Version Numbers of DSPSS_Api.c and DSPSS_Api.h are different"
#endif

/* Check if DSPSS_Api.c file and DSPSS_CFSDADC_PMEM.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_API_C != DSPSS_VENDOR_ID_CFSADC_PMEM)
    #error "DSPSS_Api.c and DSPSS_CFSDADC_PMEM.h have different vendor ids"
#endif

/* Check if DSPSS_Api.c file and DSPSS_CFSDADC_PMEM.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API_C != DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_PMEM) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API_C != DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_PMEM) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_API_C != DSPSS_AR_RELEASE_REVISION_VERSION_CFSADC_PMEM) \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.c and DSPSS_CFSDADC_PMEM.h are different"
#endif

/* Check if DSPSS_Api.c file and DSPSS_CFSDADC_PMEM.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_API_C != DSPSS_SW_MAJOR_VERSION_CFSADC_PMEM) || \
     (DSPSS_SW_MINOR_VERSION_API_C != DSPSS_SW_MINOR_VERSION_CFSADC_PMEM) || \
     (DSPSS_SW_PATCH_VERSION_API_C != DSPSS_SW_PATCH_VERSION_CFSADC_PMEM) \
    )
  #error "Software Version Numbers of DSPSS_Api.c and DSPSS_CFSDADC_PMEM.h are different"
#endif

/* Check if DSPSS_Api.c file and DSPSS_CFSDADC_XMEM.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_API_C != DSPSS_VENDOR_ID_CFSADC_XMEM)
    #error "DSPSS_Api.c and DSPSS_CFSDADC_XMEM.h have different vendor ids"
#endif

/* Check if DSPSS_Api.c file and DSPSS_CFSDADC_XMEM.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API_C != DSPSS_AR_RELEASE_MAJOR_VERSION_CFSADC_XMEM) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API_C != DSPSS_AR_RELEASE_MINOR_VERSION_CFSADC_XMEM) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_API_C != DSPSS_AR_RELEASE_REVISION_VERSION_CFSADC_XMEM) \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.c and DSPSS_CFSDADC_XMEM.h are different"
#endif

/* Check if DSPSS_Api.c file and DSPSS_CFSDADC_XMEM.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_API_C != DSPSS_SW_MAJOR_VERSION_CFSADC_XMEM) || \
     (DSPSS_SW_MINOR_VERSION_API_C != DSPSS_SW_MINOR_VERSION_CFSADC_XMEM) || \
     (DSPSS_SW_PATCH_VERSION_API_C != DSPSS_SW_PATCH_VERSION_CFSADC_XMEM) \
    )
  #error "Software Version Numbers of DSPSS_Api.c and DSPSS_CFSDADC_XMEM.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#ifdef SDADC_IP_DSPSS_INIT_DMA_CHANNEL
/* Check if DSPSS_Api.c file and Dma_Ip.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API_C != DMA_IP_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.c and Dma_Ip.h are different"
#endif

/* Check if DSPSS_Api.c file and Dma_Ip_Hw_Access.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API_C != DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API_C != DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.c and Dma_Ip_Hw_Access.h are different"
#endif
#endif /* SDADC_IP_DSPSS_INIT_DMA_CHANNEL */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION \
    DSPSS_CFSDADC_ThreadDescriptorType *ThreadDescriptors = (DSPSS_CFSDADC_ThreadDescriptorType*)(XMEM_0_BASEADDRESS + DSPSS_START_ADDRESS_THREAD_DESCRIPTORS);

#define DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION_CONST \
    const DSPSS_CFSDADC_ThreadDescriptorType *ThreadDescriptors = (DSPSS_CFSDADC_ThreadDescriptorType*)(XMEM_0_BASEADDRESS + DSPSS_START_ADDRESS_THREAD_DESCRIPTORS);


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
#define ADC_START_SEC_VAR_CLEARED_8
#include "Adc_MemMap.h"

/**
 * Store the last wrap status value for each internal Dma channel to detect the wrap event.
 * Within this variable, bit m stores the last value of wrap flag for DMA-m.
 * For example, bit 2 stores the value of DMA_CURR_RD_PTR2[DMA_READ_PTR_WRAP].
 */
static uint8 DSPSS_DmaReadBufferWrapStatus;

#define ADC_STOP_SEC_VAR_CLEARED_8
#include "Adc_MemMap.h"


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"


static DSPSS_StatusType DSPSS_LoadMemory(const uint32 * const SrcAddr,
                                         SDADC_IP_DSPSS_INIT_DSTADDR_QUALIFIER uint32 * const DstAddr,
                                         const uint32 NBytes);

static DSPSS_StatusType DSPSS_LoadPMEMAndXMEM(void);

static DSPSS_StatusType DSPSS_CleanPMEMAndXMEM(void);


/**
 * Internal functions to get/clear status flags.
 */
static inline uint32 DSPSS_DspToCoreTriggerErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_DspToCoreTriggerErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_DmaWriteBufferXfrErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_DmaWriteBufferXfrErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_DmaWriteBufferMismatchErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_DmaWriteBufferMismatchErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_DmaReadBufferXfrErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_DmaReadBufferXfrErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_DmaReadBufferMismatchErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_DmaReadBufferMismatchErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_DspCoreBufferUnderrunErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_DspCoreBufferUnderrunErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_SdadcSyncFifoOverflowErrorGet(const DSPSS_ThreadIdType ThrId);
static inline void   DSPSS_SdadcSyncFifoOverflowErrorClear(const DSPSS_ThreadIdType ThrId);

static inline uint32 DSPSS_GetStatusFlagsDSPCommon(const DSPSS_ThreadIdType Id);
static inline void DSPSS_ClearStatusFlagsDSPCommon(const DSPSS_ThreadIdType Id,
                                                   const DSPSS_InterruptType Mask);

static inline void DSPSS_SetsThreadConfigure(const DSPSS_ThreadIdType Id,
                                       const DSPSS_ThreadConfigType * const Config);
/*==================================================================================================
*                                        LOCAL FUNCTION
==================================================================================================*/

/**
 * Load memory content.
 */
static DSPSS_StatusType DSPSS_LoadMemory(const uint32 * const SrcAddr,
                                         SDADC_IP_DSPSS_INIT_DSTADDR_QUALIFIER uint32 * const DstAddr,
                                         const uint32 NBytes)
{
    DSPSS_StatusType ReturnStatus = DSPSS_OK;

#ifdef SDADC_IP_DSPSS_INIT_DMA_CHANNEL
    /* Reset value to clean PMEM and XMEM */
    static const uint32 FirmwareResetValue = 0U;

    /* Local variables to check for hardware errors and software timeout */
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
    uint32 TimeoutTicks;
    uint32 CurrentTicks;
    uint32 ElapsedTicks;

    /* Prepare for Software TCD Configuration to transfer data by DMA hardware */
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[13U] =
    {
        /* [0-2] Source */
        {DMA_IP_CH_SET_SOURCE_ADDRESS,                     (Dma_Ip_uintPtrType)SrcAddr},
        {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE,               DMA_IP_TRANSFER_SIZE_4_BYTE},
        {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET,               4U                         },

        /* [3-5] Destination */
        {DMA_IP_CH_SET_DESTINATION_ADDRESS,                (Dma_Ip_uintPtrType)DstAddr},
        {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE,          DMA_IP_TRANSFER_SIZE_4_BYTE},
        {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET,          4U                         },

        /* [6-7] Number of bytes to be transferred in one major loop */
        {DMA_IP_CH_SET_MINORLOOP_SIZE,                     NBytes},
        {DMA_IP_CH_SET_MAJORLOOP_COUNT,                    1U    },

        /* [8-9] Disable all channel links */
        {DMA_IP_CH_SET_MINORLOOP_EN_LINK,                  0U},  /* FALSE */
        {DMA_IP_CH_SET_MAJORLOOP_EN_LINK,                  0U},  /* FALSE */

        /* [10-11] Disable all interrupts */
        {DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT,    0U},  /* FALSE */
        {DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT,         0U},  /* FALSE */

        /* [12] Disable soft start request */
        {DMA_IP_CH_SET_CONTROL_SOFTWARE_REQUEST,           0U}   /* FALSE */
    };

    /* Overwrite TCD settings in case of cleaning to zero */
    if (NULL_PTR == SrcAddr)
    {
        LocTransferList[0U].Value = (Dma_Ip_uintPtrType)(&FirmwareResetValue);  /* Load zero data from static variable */
        LocTransferList[2U].Value = 0U;                                         /* Not increasing source address */
    }

    /* Clear status and error flags */
    (void)Dma_Ip_SetLogicChannelCommand(SDADC_IP_DSPSS_INIT_DMA_CHANNEL, DMA_IP_CH_CLEAR_DONE);
    (void)Dma_Ip_SetLogicChannelCommand(SDADC_IP_DSPSS_INIT_DMA_CHANNEL, DMA_IP_CH_CLEAR_ERROR);

    /* Setup Dma Channel */
    (void)Dma_Ip_SetLogicChannelTransferList(SDADC_IP_DSPSS_INIT_DMA_CHANNEL, LocTransferList, 13U);

    /* Prepare DMA status variables */
    DmaChannelStatus.Errors = 0UL;
    DmaChannelStatus.Done   = FALSE;
    /* Prepare timeout counter variables */
    TimeoutTicks = OsIf_MicrosToTicks(SDADC_IP_TIMEOUT_VAL, SDADC_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(SDADC_IP_TIMEOUT_TYPE);
    ElapsedTicks = 0U;

    /* Send the soft start request to start transfer */
    (void)Dma_Ip_SetLogicChannelCommand(SDADC_IP_DSPSS_INIT_DMA_CHANNEL, DMA_IP_CH_SET_SOFTWARE_REQUEST);
    do
    {
        /* Get channel status */
        (void)Dma_Ip_GetLogicChannelStatus(SDADC_IP_DSPSS_INIT_DMA_CHANNEL, &DmaChannelStatus);

        /* Check for hardware errors */
        if (DmaChannelStatus.Errors != 0U)
        {
            /* A non-zero value indicates the presence of a channel error */
            ReturnStatus = DSPSS_HW_ERR;
        }
        else
        {
            /* Check for software timeout */
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SDADC_IP_TIMEOUT_TYPE);
            if (ElapsedTicks >= TimeoutTicks)
            {
                ReturnStatus = DSPSS_TIMEOUT;
            }
        }

        if (ReturnStatus != DSPSS_OK)
        {
            /* Exit the loop */
            break;
        }
    }
    while (DmaChannelStatus.Done != TRUE);    /* Wait until DMA has completed the major loop */

#else /* SDADC_IP_DSPSS_INIT_DMA_CHANNEL */

    /* Use for-loop to copy manually */
    uint32 Idx;

    if (SrcAddr != NULL_PTR)
    {
        /* Load each word (4-byte) of data */
        for (Idx = 0U; Idx < (NBytes / sizeof(uint32)); Idx++)
        {
            DstAddr[Idx] = SrcAddr[Idx];
        }
    }
    else
    {
        /* Clean to zero */
        for (Idx = 0U; Idx < (NBytes / sizeof(uint32)); Idx++)
        {
            DstAddr[Idx] = 0U;
        }
    }
#endif /* SDADC_IP_DSPSS_INIT_DMA_CHANNEL */

    return ReturnStatus;
}


/**
 * Initialize PMEM and XMEM with 0h.
 */
static DSPSS_StatusType DSPSS_CleanPMEMAndXMEM(void)
{
    DSPSS_StatusType Status;

    /* Initialize PMEM with 0h. */
    Status = DSPSS_LoadMemory(NULL_PTR, (uint32 *)PMEM_0_BASEADDRESS, PMEM_SIZE);

    if (DSPSS_OK == Status)
    {
        /* Initialize XMEM with 0h. */
        Status = DSPSS_LoadMemory(NULL_PTR, (uint32 *)XMEM_0_BASEADDRESS, XMEM_SIZE);
    }

    return Status;
}


/**
 * Load content of PMEM and XMEM.
 */
static DSPSS_StatusType DSPSS_LoadPMEMAndXMEM(void)
{
    DSPSS_StatusType Status;

    /* Load XMEM */
    Status = DSPSS_LoadMemory(u32Xmem_NogapArray, (uint32 *)XMEM_0_BASEADDRESS, sizeof(u32Xmem_NogapArray));

    if (DSPSS_OK == Status)
    {
        /* Load PMEM */
        Status = DSPSS_LoadMemory(u32Pmem_NogapArray, (uint32 *)PMEM_0_BASEADDRESS, sizeof(u32Pmem_NogapArray));
    }

    return Status;
}


/**
 * Initialize driver internal variables.
 */
static inline void DSPSS_InitVariables(void)
{
    DSPSS_DmaReadBufferWrapStatus = 0U;
}


/**
 * Internal functions to get/clear status flags.
 */
static inline uint32 DSPSS_DspToCoreTriggerErrorGet(const DSPSS_ThreadIdType ThrId)
{
    uint32 ErrFlag = 0U;

    /* Read the error flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            ErrFlag = IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS0 & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;

        case DSPSS_THREAD_ID1:
            ErrFlag = IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS1 & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            ErrFlag = IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS2 & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;

        case DSPSS_THREAD_ID3:
            ErrFlag = IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS3 & DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;
#endif /* (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return ErrFlag;
}


static inline void DSPSS_DspToCoreTriggerErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Write 1 to clear the flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS0 = DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS0_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS1 = DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS1_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS2 = DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS2_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSP_TO_CORE_TRIG_ERR_STATUS3 = DSPSS_DSP_TO_CORE_TRIG_ERR_STATUS3_DSP_TO_CORE_TRIG_ERR_STATUS_MASK;
            break;
#endif /* (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


static inline uint32 DSPSS_DmaWriteBufferXfrErrorGet(const DSPSS_ThreadIdType ThrId)
{
    uint32 ErrFlag = 0U;

    /* Read the error flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS0 & DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_MASK;
            break;

        case DSPSS_THREAD_ID1:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS1 & DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS2 & DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_MASK;
            break;

        case DSPSS_THREAD_ID3:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS3 & DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_MASK;
            break;
#endif /* (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return ErrFlag;
}


static inline void DSPSS_DmaWriteBufferXfrErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Write 1 to clear the flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DMA_ERROR_STATUS0 = DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_WRITE_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DMA_ERROR_STATUS1 = DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_WRITE_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DMA_ERROR_STATUS2 = DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_WRITE_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DMA_ERROR_STATUS3 = DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_WRITE_MASK;
            break;
#endif /* (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


static inline uint32 DSPSS_DmaWriteBufferMismatchErrorGet(const DSPSS_ThreadIdType ThrId)
{
    uint32 ErrFlag = 0U;

    /* Read the error flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS0 & DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID1:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS1 & DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS2 & DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID3:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS3 & DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return ErrFlag;
}


static inline void DSPSS_DmaWriteBufferMismatchErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Write 1 to clear the flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DMA_ERROR_STATUS0 = DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DMA_ERROR_STATUS1 = DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DMA_ERROR_STATUS2 = DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DMA_ERROR_STATUS3 = DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_WR_BUFFER_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    } 
}


static inline uint32 DSPSS_DmaReadBufferXfrErrorGet(const DSPSS_ThreadIdType ThrId)
{
    uint32 ErrFlag = 0U;

    /* Read the error flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS0 & DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_MASK;
            break;

        case DSPSS_THREAD_ID1:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS1 & DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS2 & DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_MASK;
            break;

        case DSPSS_THREAD_ID3:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS3 & DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return ErrFlag;
}


static inline void DSPSS_DmaReadBufferXfrErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Write 1 to clear the flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DMA_ERROR_STATUS0 = DSPSS_DMA_ERROR_STATUS0_DMA_XFR_ERR_READ_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DMA_ERROR_STATUS1 = DSPSS_DMA_ERROR_STATUS1_DMA_XFR_ERR_READ_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DMA_ERROR_STATUS2 = DSPSS_DMA_ERROR_STATUS2_DMA_XFR_ERR_READ_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DMA_ERROR_STATUS3 = DSPSS_DMA_ERROR_STATUS3_DMA_XFR_ERR_READ_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


static inline uint32 DSPSS_DmaReadBufferMismatchErrorGet(const DSPSS_ThreadIdType ThrId)
{
    uint32 ErrFlag = 0U;

    /* Read the error flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS0 & DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID1:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS1 & DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS2 & DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID3:
            ErrFlag = IP_DSPSS_0->DMA_ERROR_STATUS3 & DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return ErrFlag;
}


static inline void DSPSS_DmaReadBufferMismatchErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Write 1 to clear the flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DMA_ERROR_STATUS0 = DSPSS_DMA_ERROR_STATUS0_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DMA_ERROR_STATUS1 = DSPSS_DMA_ERROR_STATUS1_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DMA_ERROR_STATUS2 = DSPSS_DMA_ERROR_STATUS2_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DMA_ERROR_STATUS3 = DSPSS_DMA_ERROR_STATUS3_DMA_ADDR_MISMATCH_RD_BUFFER_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


static inline uint32 DSPSS_DspCoreBufferUnderrunErrorGet(const DSPSS_ThreadIdType ThrId)
{
    uint32 UdrFlag = 0U;

    /* Read the overflow flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            UdrFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS0 & DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_MASK;
            break;

        case DSPSS_THREAD_ID1:
            UdrFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS1 & DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            UdrFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS2 & DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_MASK;
            break;

        case DSPSS_THREAD_ID3:
            UdrFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS3 & DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return UdrFlag;
}


static inline void DSPSS_DspCoreBufferUnderrunErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Write 1 to clear the flag */
    switch (ThrId)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS0 = DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_UNDF_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS1 = DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_UNDF_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS2 = DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_UNDF_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS3 = DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_UNDF_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


static inline uint32 DSPSS_SdadcSyncFifoOverflowErrorGet(const DSPSS_ThreadIdType ThrId)
{
    /* Create flag mask for this thread */
    const uint32 FlagMask = 1UL << (ThrId + DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_SHIFT);
    /* Read the flag */
    return (IP_DSPSS_0->SDADC_SYNC_FIFO_ERROR_STATUS & FlagMask);
}


static inline void DSPSS_SdadcSyncFifoOverflowErrorClear(const DSPSS_ThreadIdType ThrId)
{
    /* Create flag mask for this thread */
    const uint32 FlagMask = 1UL << (ThrId + DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_OVERFLOW_SHIFT);
    /* Write 1 to clear the flag */
    IP_DSPSS_0->SDADC_SYNC_FIFO_ERROR_STATUS = FlagMask;
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

boolean DSPSS_HasInitialized(void)
{
    boolean InitCompleted = FALSE;

    if ((IP_DSPSS_0->CURR_ACTIVE_THRD & DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_MASK) != 0U)
    {
        InitCompleted = TRUE;
    }

    return InitCompleted;
}


/* Initializes the DSPSS by loading the FW init PMEM and default configuration into XMEM and reset DSPSS registers.
 */
DSPSS_StatusType DSPSS_Init(void)
{
    DSPSS_StatusType Status;

    /* 1) Initialize PMEM with 0h. */
    /* 2) Initialize XMEM with 0h. */
    Status = DSPSS_CleanPMEMAndXMEM();

    if (DSPSS_OK == Status)
    {
        /* 3) Load PMEM */
        /* 4) Write default config to XMEM */
        Status = DSPSS_LoadPMEMAndXMEM();
    }

    if (DSPSS_OK == Status)
    {
        /* 6) Reset internal variables */
        DSPSS_InitVariables();
    }

    return Status;
}


void DSPSS_DspInit(void)
{
    /* Reset everything inside DSPSS except the DSP core:
         - Threads, buffers, interrupts registers will be reset to their default values.
         - Flags (overflow, underrun, suspend) will also be clears.
     */
    /* Performs a soft reset */
    IP_DSPSS_0->DSPSS_SOFT_RESET_REGISTER |=  DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_MASK;
    /* Clear reset request (this bit is not cleared by hardware) */
    IP_DSPSS_0->DSPSS_SOFT_RESET_REGISTER &= ~DSPSS_DSPSS_SOFT_RESET_REGISTER_SFTRST_MASK;
}


DSPSS_StatusType DSPSS_Deinit(void)
{
    DSPSS_StatusType Status;

    /* Assert reset */
    DSPSS_DspAssertReset();

    /* Clean PMEM and XMEM with 0h */
    Status = DSPSS_CleanPMEMAndXMEM();

    return Status;
}


void DSPSS_FirmwareVersionGet(uint16 * const FirmwareVersion,
                              const uint32 Length)
{
    const uint16 * const CFSDADCFirmwareBuildTag = (uint16*)(XMEM_0_BASEADDRESS + DSPSS_START_ADDRESS_FIRMWARE_BUILD_TAG);
    uint32 Idx;

    DSPSS_DEV_ASSERT(DSPSS_FIRMWARE_BUILD_TAG_SIZE == Length);
    /* Unused variable */
    (void)Length;

    /* Use half-word access to XMEM to read the FW version
       (Byte access will lead to hardfault)
     */
    for (Idx = 0U; Idx < (DSPSS_FIRMWARE_BUILD_TAG_SIZE / sizeof(uint16)); Idx++)
    {
        FirmwareVersion[Idx] = CFSDADCFirmwareBuildTag[Idx];
    }

}


DSPSS_StatusType DSPSS_ThreadConfigure(const DSPSS_ThreadIdType Id,
                                       const DSPSS_ThreadConfigType * const Config)
{
    DSPSS_DEV_ASSERT(Config != NULL_PTR);

    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION
    /* 0) Reads the threads descriptors */
    DSPSS_CFSDADC_ThreadDescriptorType * const ThreadDescriptor = &ThreadDescriptors[Id];
    DSPSS_DEV_ASSERT(DSPSS_CFSDADC_STATUS_INACTIVE == ThreadDescriptor->Status);
    (void)ThreadDescriptor;

    /* 1) Sets thread DSPSS registers */
    DSPSS_ThreadThresholdSet(Id, Config->InputThreshold);

    /* 2) Sets thread */
    DSPSS_SetsThreadConfigure(Id, Config);

    /* 3) Set scheduling mode (Note: this will be overwritten each time configuring a thread) */
    DSPSS_ThreadSchedulingConfigure(Config->SchedMode, Config->SchedOrder);

#if (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON)
    /* 4) Enable error interrupts if configured */
    if (Config->ErrorNotification != NULL_PTR)
    {
        DSPSS_InterruptEnable(Id, DSPSS_ERROR_INTERRUPT_ALL);
    }
#endif /* (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON) */

    return DSPSS_OK;
}

static inline void DSPSS_SetsThreadConfigure(const DSPSS_ThreadIdType Id,
                                       const DSPSS_ThreadConfigType * const Config)
{
    uint32 Idx;
    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION

    DSPSS_CFSDADC_ThreadDescriptorType * const ThreadDescriptor = &ThreadDescriptors[Id];
    /* Point to thread parameter structures */
    const uint16 * const ConfigParams = (uint16 *)(uint32)(&Config->ThreadParams);
    uint16 * const ThreadParams       = (uint16 *)(uint32)(&ThreadDescriptor->ThreadParams);

    /* Configure the length of the output buffer for this thread */
    ThreadDescriptor->BufferOutputLength = Config->BufferOutputLength;

    const uint16 StartInAddr  = ThreadDescriptor->BufferInputStart;
    const uint16 EndInAddr    = ThreadDescriptor->BufferInputStart  + ThreadDescriptor->BufferInputLength - 2U;
    const uint16 StartOutAddr = ThreadDescriptor->BufferOutputStart;
    const uint16 EndOutAddr   = ThreadDescriptor->BufferOutputStart + ThreadDescriptor->BufferOutputLength - 2U;

    /* 1) Sets input & output buffer thresholds */
    ThreadDescriptor->InputThreshold  = Config->InputThreshold;
    ThreadDescriptor->OutputThreshold = Config->OutputThreshold;

    /* 2) Sets thread I/O type (DMA, dsp core buffer) */
    if (DSPSS_TRANSFER_DMA != Config->InputTransferMethod)
    {
        DSPSS_ThreadInputBufferConfigure(Id, StartInAddr, EndInAddr);
    }

    if (DSPSS_TRANSFER_DMA == Config->OutputTransferMethod)
    {
        ThreadDescriptor->OutputDMAChannel = (DSPSS_CFSDADC_DmaChannelType)Id;

        DSPSS_DmaReadBufferConfigure((DSPSS_CFSDADC_DmaChannelType)Id, StartOutAddr, EndOutAddr);
        DSPSS_DmaReadBufferEnable( (DSPSS_CFSDADC_DmaChannelType)Id );
    }
    else
    {
        DSPSS_DspCoreBufferConfigure(Id, StartOutAddr, EndOutAddr, DSPSS_DSP_WRITE_OWNER);
        DSPSS_DspCoreBufferEnable(Id);
    }

    /* 3) Sets filter type (chooses thread PCINIT) */
    DSPSS_ThreadPCInitSet(Id, ThreadDescriptor->EntryPoint);

    /* 4) Sets specific filter parameters */
    for (Idx = 0U; Idx < (sizeof(DSPSS_CFSDADC_ThreadParamsType) / sizeof(uint16)); Idx++)
    {
        ThreadParams[Idx] = ConfigParams[Idx];
    }

    /* 5) Notify the thread that it is configured. */
    ThreadDescriptor->Status = DSPSS_CFSDADC_STATUS_CONFIGURED;

#if (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON)
    /* 9) Enable error interrupts if configured */
    if (Config->ErrorNotification != NULL_PTR)
    {
        DSPSS_InterruptEnable(Id, DSPSS_ERROR_INTERRUPT_ALL);
    }
#endif /* (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON) */
}


DSPSS_StatusType DSPSS_ThreadsInitialize(void)
{
    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION
    uint32 ThrId;

    /* 1) Perform the reset routine (all running threads will be interrupted) */
    DSPSS_DspStartResetRoutine();

    /* 2) Resume the running threads which were interrupted by the reset routine step above */
    for (ThrId = 0U; ThrId < (uint32)DSPSS_THREAD_NUM; ThrId++)
    {
        if (DSPSS_CFSDADC_STATUS_RUNNING == ThreadDescriptors[ThrId].Status)
        {
            /* Bring back to ready state */
            ThreadDescriptors[ThrId].Status = DSPSS_CFSDADC_STATUS_INITIALIZED;
        }
    }

    return DSPSS_OK;
}


DSPSS_StatusType DSPSS_Start(void)
{
    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION_CONST
    uint32 ThrId;

    for (ThrId = 0U; ThrId < (uint32)DSPSS_THREAD_NUM; ThrId++)
    {
        if (DSPSS_CFSDADC_STATUS_INITIALIZED == ThreadDescriptors[ThrId].Status)
        {
            /* Enable the configured and initialized threads */
            DSPSS_ThreadEnable(ThrId);
        }
    }

    return DSPSS_OK;
}


DSPSS_StatusType DSPSS_Stop(void)
{
    uint32 ThrId;

    /* 1) Allow DSPSS to process all the scheduled requests (Flush request FIFO?) */

    /* 2) Suspend the running threads */
    for (ThrId = 0U; ThrId < (uint32)DSPSS_THREAD_NUM; ThrId++)
    {
        /* Suspend the running threads */
        DSPSS_ThreadSuspend(ThrId);
    }

    return DSPSS_OK;
}


DSPSS_StatusType DSPSS_ThreadsCalibrationSet(const DSPSS_ThreadIdType Id,
                                             const DSPSS_CFSDADC_CalibParamsType * CalibrationParams)
{
    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION

    /* 1) Sets specific calibration parameters */
    ThreadDescriptors[Id].ConfigMessage = DSPSS_CFSDADC_PARAMS_SET;
    ThreadDescriptors[Id].ThreadParams.StandardParams.CalibParams = *CalibrationParams;

    return DSPSS_OK;
}


DSPSS_CFSDADC_ThreadStatusType DSPSS_ThreadsStatusGet(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION_CONST
    /* Get the status */
    return ThreadDescriptors[Id].Status;
}


uint32 DSPSS_CoreBufferRead(const DSPSS_ThreadIdType Id,
                            const uint32 Length,
                            sint16 * const Data)
{
    DSPSS_DEV_ASSERT(Data != NULL_PTR);
    DSPSS_DEV_ASSERT(Length > 0U);

    uint16 BuffAddr;
    const sint16 * BuffPtr;
    uint32 Num;

    for (Num = 0U; Num < Length; Num++)
    {
        /* Get current read pointer in core buffer */
        BuffAddr  = DSPSS_DspCoreBufferCurrReadPtrGet(Id);
        BuffPtr   = (sint16 *)(XMEM_0_BASEADDRESS + BuffAddr);
        /* Copy sample to user buffer */
        Data[Num] = BuffPtr[0U];
    }

    return Num;
}


void DSPSS_FlushOutputBuffer(const DSPSS_ThreadIdType Id,
                             const DSPSS_TransferMethodType TransferMethod)
{
    if (DSPSS_TRANSFER_CORE_BUFFER == TransferMethod)
    {
        /* Re-enable the buffer to trigger DSPSS updates both read and write pointers to DSP_CORE_BUF_ADDRn[DSP_CORE_BUF_START_ADDR] */
        DSPSS_DspCoreBufferDisable(Id);
        DSPSS_DspCoreBufferEnable(Id);
    }
    else
    {
        /* Re-enable the DMA read buffer to trigger DSPSS updates current read pointer to DMA_READ_ADDRn[DMA_READ_START_ADDR] */
        DSPSS_DmaReadBufferDisable((DSPSS_CFSDADC_DmaChannelType)Id);
        DSPSS_DmaReadBufferEnable((DSPSS_CFSDADC_DmaChannelType)Id);
    }
}


/*==================================================================================================
*                                       DSPSS_threads
==================================================================================================*/

void DSPSS_DspStartResetRoutine(void)
{
    uint32 RegVal;

    /* 0) Assert reset to trigger another reset signal (because this function is called after each time configuring a thread) */
    DSPSS_DspAssertReset();

    /* 1) Deassert reset */
    /* 2) Start reset routine */
    RegVal  = DSPSS_DSPSS_DSP0_CFG_SCHED_DSP_RST_CTRL_EN(0U);        /*  0b - Reset deasserts whenever dspss_scheduler_dsp0_reset is 1 */
    /* Only level signal type have to be used for triggers. Pulse signal type was proclaimed as unstable by HW design team */
    RegVal |= DSPSS_DSPSS_DSP0_CFG_dspss_dsp0_core_trigger_cfg(2U);  /* 10b - Trigger to core would be a level signal */
    RegVal |= DSPSS_DSPSS_DSP0_CFG_dspss_scheduler_dsp0_reset(1U);   /*  1b - DSP reset deasserts */
    IP_DSPSS_0->DSPSS_DSP0_CFG = RegVal;

    /* The following tasks are running inside of the CoolFlux */
    /* 3) Do threads specific initialization */
    /* 4) (Go to TH-0 task if enabled) */
    /* 5) Put TH-0 to sleep */
}


void DSPSS_DspAssertReset(void)
{
    /* 1) Thread Reset Assertion Control */
    IP_DSPSS_0->DSPSS_DSP0_CFG = 0U;
}


void DSPSS_ThreadSchedulingConfigure(DSPSS_SchedulingModeType SchedMode, const DSPSS_ThreadIdType* SchedSeq)
{
    /* Set scheduling mode */
    if (DSPSS_SAMPLE_THRESHOLD_MODE == SchedMode)
    {
        DSPSS_ThreadSchedulingSampleThresholdMode(DSPSS_HALT_ACK_WAIT);
    }
    else
    {
        /* Note: using fixed schedule order: Thread 0 -> Thread 3 */
        DSPSS_ThreadSchedulingClockThresholdMode(DSPSS_HALT_ACK_NO_WAIT, SchedSeq);
    }
}


void DSPSS_ThreadSchedulingSampleThresholdMode(const DSPSS_NextReqHaltAckWaitModeType ContrlMode)
{
    uint32 RegVal;

    /* Configures sample threshold mode */
    RegVal  = DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE( DSPSS_SAMPLE_THRESHOLD_MODE );
    RegVal |= DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL(ContrlMode);

    IP_DSPSS_0->SCHEDULER_MODE_CFG = RegVal;
}


void DSPSS_ThreadSchedulingClockThresholdMode(const DSPSS_NextReqHaltAckWaitModeType ContrlMode, const DSPSS_ThreadIdType* SchedSeq)
{
    uint32 RegVal;

    /* Configures clock threshold mode */
    RegVal  = DSPSS_SCHEDULER_MODE_CFG_SCHEDULER_MODE( DSPSS_CLOCK_THRESHOLD_MODE );
    RegVal |= DSPSS_SCHEDULER_MODE_CFG_NEXT_REQ_HALT_ACK_WAIT_CTRL(ContrlMode);

    /* Configures the thread order to be scheduled */
    RegVal |= DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_1(1UL << (uint32)SchedSeq[0]);
    RegVal |= DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_2(1UL << (uint32)SchedSeq[1]);
#if (DSPSS_THREAD_NUM > 2U)
    RegVal |= DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_3(1UL << (uint32)SchedSeq[2]);
    RegVal |= DSPSS_SCHEDULER_MODE_CFG_SCHD_SEQ_4(1UL << (uint32)SchedSeq[3]);
#endif /* DSPSS_THREAD_NUM > 2U */
    IP_DSPSS_0->SCHEDULER_MODE_CFG = RegVal;
}


void DSPSS_ThreadPCInitSet(const DSPSS_ThreadIdType Id,
                           const uint16 PCInit)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSPSS_SCHEDULER_DSP_CFG_TH0 = DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH0_DSPSS_SCHEDULER_DSP_PCINIT(PCInit);
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSPSS_SCHEDULER_DSP_CFG_TH1 = DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH1_DSPSS_SCHEDULER_DSP_PCINIT(PCInit);
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSPSS_SCHEDULER_DSP_CFG_TH2 = DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH2_DSPSS_SCHEDULER_DSP_PCINIT(PCInit);
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSPSS_SCHEDULER_DSP_CFG_TH3 = DSPSS_DSPSS_SCHEDULER_DSP_CFG_TH3_DSPSS_SCHEDULER_DSP_PCINIT(PCInit);
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


void DSPSS_ThreadInputBufferConfigure(const DSPSS_ThreadIdType Id,
                                      const uint16 StartAddress,
                                      const uint16 EndAddress)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_ADDR_TH0 = DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_START_ADDR(StartAddress) |
                                                        DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH0_SCHEDULER_THRD_END_ADDR(EndAddress);
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_ADDR_TH1 = DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_START_ADDR(StartAddress) |
                                                        DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH1_SCHEDULER_THRD_END_ADDR(EndAddress);
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_ADDR_TH2 = DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_START_ADDR(StartAddress) |
                                                        DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH2_SCHEDULER_THRD_END_ADDR(EndAddress);
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_ADDR_TH3 = DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_START_ADDR(StartAddress) |
                                                        DSPSS_DSPSS_SCHEDULER_XMEM_ADDR_TH3_SCHEDULER_THRD_END_ADDR(EndAddress);
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


void DSPSS_ThreadThresholdSet(const DSPSS_ThreadIdType Id,
                              const uint16 Threshold)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    /* Whole register is updated, because threads must be enabled after setting the threshold */
    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH0 = DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_TH(Threshold);
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH1 = DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_TH(Threshold);
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH2 = DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_TH(Threshold);
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH3 = DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_TH(Threshold);
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}

void DSPSS_ThreadEnable(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION
    DSPSS_CFSDADC_ThreadDescriptorType * const ThreadDescriptor = &ThreadDescriptors[Id];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_87();
    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH0 |= DSPSS_DSPSS_SCHEDULER_XMEM_TH0_SCHEDULER_THRD_EN_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH1 |= DSPSS_DSPSS_SCHEDULER_XMEM_TH1_SCHEDULER_THRD_EN_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH2 |= DSPSS_DSPSS_SCHEDULER_XMEM_TH2_SCHEDULER_THRD_EN_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSPSS_SCHEDULER_XMEM_TH3 |= DSPSS_DSPSS_SCHEDULER_XMEM_TH3_SCHEDULER_THRD_EN_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_87();

    /* Notify the thread that it is ready to run. */
    ThreadDescriptor->Status = DSPSS_CFSDADC_STATUS_INITIALIZED;
}


void DSPSS_ThreadSuspend(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION
    DSPSS_CFSDADC_ThreadDescriptorType * const ThreadDescriptor = &ThreadDescriptors[Id];

    if ((ThreadDescriptor->Status & (DSPSS_CFSDADC_STATUS_INITIALIZED | DSPSS_CFSDADC_STATUS_RUNNING)) != 0U) 
    {
        switch (Id)
        {
            case DSPSS_THREAD_ID0:
                IP_DSPSS_0->THREAD_SUSPEND_REQ0 = DSPSS_THREAD_SUSPEND_REQ0_SUSPEND_REQ(1U);
                break;

            case DSPSS_THREAD_ID1:
                IP_DSPSS_0->THREAD_SUSPEND_REQ1 = DSPSS_THREAD_SUSPEND_REQ1_SUSPEND_REQ(1U);
                break;

#if (DSPSS_THREAD_NUM > 2U)
            case DSPSS_THREAD_ID2:
                IP_DSPSS_0->THREAD_SUSPEND_REQ2 = DSPSS_THREAD_SUSPEND_REQ2_SUSPEND_REQ(1U);
                break;

            case DSPSS_THREAD_ID3:
                IP_DSPSS_0->THREAD_SUSPEND_REQ3 = DSPSS_THREAD_SUSPEND_REQ3_SUSPEND_REQ(1U);
                break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

            default:
                /* Do nothing */
                break;
        }

        /* Notify the thread that it is suspended. */
        ThreadDescriptor->Status = DSPSS_CFSDADC_STATUS_SUSPENDED;
    }
}


uint32 DSPSS_ThreadGetOutputBufferStart(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION_CONST
    const DSPSS_CFSDADC_ThreadDescriptorType * const ThreadDescriptor = &ThreadDescriptors[Id];

    /* Convert XMEM address to a real address */
    return (XMEM_0_BASEADDRESS + (uint32)(ThreadDescriptor->BufferOutputStart));
}


uint32 DSPSS_ThreadGetOutputBufferLength(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    DSPSS_CFSDADC_THREADS_DESCRIPTORS_DECLARATION_CONST
    const DSPSS_CFSDADC_ThreadDescriptorType * const ThreadDescriptor = &ThreadDescriptors[Id];

    /* Get length of the output buffer for this thread */
    return ThreadDescriptor->BufferOutputLength;
}


/*==================================================================================================
*                                       DSPSS core buffer
==================================================================================================*/

void DSPSS_DspCoreBufferConfigure(const DSPSS_ThreadIdType Id,
                                  const uint16 StartAddr,
                                  const uint16 EndAddr,
                                  const DSPSS_DspCoreBufferOwnerType Owner)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    uint16 CoreBufStartAddr;
    uint16 CoreBufEndAddr;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_88();
    uint32 RegVal = IP_DSPSS_0->DSP_CORE_BUFFER_CFG;

    if (DSPSS_M7_WRITE_OWNER == Owner)
    {
        /* A value of 0 means the Cortex-M7 core has only write access and DSP has only read access */
        DSPSS_CLR_BIT(RegVal, Id + DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_SHIFT);
    }
    else
    {
        /* A value of 1 means the Cortex-M7 core has only read access and DSP has only write access */
        DSPSS_SET_BIT(RegVal, Id + DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_MASTER_SHIFT);
    }

    IP_DSPSS_0->DSP_CORE_BUFFER_CFG = RegVal;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_88();

    /* Start pointer for the circular buffer defined for the scratch pad between the two buffers.
     * This address field is half-word aligned. */
    CoreBufStartAddr = StartAddr >> 1U;

    /* End pointer for the circular buffer defined for the scratch pad between the two buffers.
     * Address rolls back to start adress after reaching the last location.
     * This address field is half-word aligned. */
    CoreBufEndAddr = EndAddr >> 1U;

    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSP_CORE_BUF_ADDR0 = DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_START_ADDR(CoreBufStartAddr) |
                                             DSPSS_DSP_CORE_BUF_ADDR0_DSP_CORE_BUF_END_ADDR(CoreBufEndAddr);
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSP_CORE_BUF_ADDR1 = DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_START_ADDR(CoreBufStartAddr) |
                                             DSPSS_DSP_CORE_BUF_ADDR1_DSP_CORE_BUF_END_ADDR(CoreBufEndAddr);
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSP_CORE_BUF_ADDR2 = DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_START_ADDR(CoreBufStartAddr) |
                                             DSPSS_DSP_CORE_BUF_ADDR2_DSP_CORE_BUF_END_ADDR(CoreBufEndAddr);
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSP_CORE_BUF_ADDR3 = DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_START_ADDR(CoreBufStartAddr) |
                                             DSPSS_DSP_CORE_BUF_ADDR3_DSP_CORE_BUF_END_ADDR(CoreBufEndAddr);
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


void DSPSS_DspCoreBufferEnable(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_89();
    uint32 RegVal = IP_DSPSS_0->DSP_CORE_BUFFER_CFG;

    /* Enable core buffer */
    DSPSS_SET_BIT(RegVal, Id + DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_SHIFT);
    IP_DSPSS_0->DSP_CORE_BUFFER_CFG = RegVal;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_89();
}


void DSPSS_DspCoreBufferDisable(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_90();
    uint32 RegVal = IP_DSPSS_0->DSP_CORE_BUFFER_CFG;

    /* Disable core buffer */
    DSPSS_CLR_BIT(RegVal, Id + DSPSS_DSP_CORE_BUFFER_CFG_DSP_CORE_BUFFER_EN_SHIFT);
    IP_DSPSS_0->DSP_CORE_BUFFER_CFG = RegVal;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_90();
}


uint16 DSPSS_DspCoreBufferCurrReadPtrGet(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    uint32 CurrReadPtr = 0U;

    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            CurrReadPtr = DSPSS_GET_BITS(IP_DSPSS_0->DSP_CORE_CURR_RD_PTR0,
                                         DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_SHIFT,
                                         DSPSS_DSP_CORE_CURR_RD_PTR0_DSP_CORE_CURR_RD_PTR_WIDTH);
            break;

        case DSPSS_THREAD_ID1:
            CurrReadPtr = DSPSS_GET_BITS(IP_DSPSS_0->DSP_CORE_CURR_RD_PTR1,
                                         DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_SHIFT,
                                         DSPSS_DSP_CORE_CURR_RD_PTR1_DSP_CORE_CURR_RD_PTR_WIDTH);
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            CurrReadPtr = DSPSS_GET_BITS(IP_DSPSS_0->DSP_CORE_CURR_RD_PTR2,
                                         DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_SHIFT,
                                         DSPSS_DSP_CORE_CURR_RD_PTR2_DSP_CORE_CURR_RD_PTR_WIDTH);
            break;

        case DSPSS_THREAD_ID3:
            CurrReadPtr = DSPSS_GET_BITS(IP_DSPSS_0->DSP_CORE_CURR_RD_PTR3,
                                         DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_SHIFT,
                                         DSPSS_DSP_CORE_CURR_RD_PTR3_DSP_CORE_CURR_RD_PTR_WIDTH);
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    /* Convert to half-word to byte address */
    CurrReadPtr <<= 1U;

    return (uint16)CurrReadPtr;
}


void DSPSS_DspCoreBufferOverflowClear(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    /* Write 1 to clear the flag */
    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS0 = DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_MASK;
            break;

        case DSPSS_THREAD_ID1:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS1 = DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS2 = DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_MASK;
            break;

        case DSPSS_THREAD_ID3:
            IP_DSPSS_0->DSP_CORE_BUFFER_STATUS3 = DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }
}


uint32 DSPSS_DspCoreBufferOverflowCheck(const DSPSS_ThreadIdType Id)
{
    DSPSS_DEV_ASSERT(Id < DSPSS_THREAD_NUM);

    uint32 OvfFlag = 0U;

    /* Read the overflow flag */
    switch (Id)
    {
        case DSPSS_THREAD_ID0:
            OvfFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS0 & DSPSS_DSP_CORE_BUFFER_STATUS0_DSP_CORE_BUFFER_OVF_MASK;
            break;

        case DSPSS_THREAD_ID1:
            OvfFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS1 & DSPSS_DSP_CORE_BUFFER_STATUS1_DSP_CORE_BUFFER_OVF_MASK;
            break;

#if (DSPSS_THREAD_NUM > 2U)
        case DSPSS_THREAD_ID2:
            OvfFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS2 & DSPSS_DSP_CORE_BUFFER_STATUS2_DSP_CORE_BUFFER_OVF_MASK;
            break;

        case DSPSS_THREAD_ID3:
            OvfFlag = IP_DSPSS_0->DSP_CORE_BUFFER_STATUS3 & DSPSS_DSP_CORE_BUFFER_STATUS3_DSP_CORE_BUFFER_OVF_MASK;
            break;
#endif /* #if (DSPSS_THREAD_NUM > 2U) */

        default:
            /* Do nothing */
            break;
    }

    return OvfFlag;
}


/*==================================================================================================
*                                       DSPSS_interrupts
==================================================================================================*/

void DSPSS_InterruptEnable(const DSPSS_ThreadIdType Id,
                           const DSPSS_InterruptType InterruptMask)
{
    uint32 InterruptEnRes  = 0U;

    /* Interrupt 1 (thread specific interrupts) */
    if ((InterruptMask & DSPSS_DSP_ERROR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_SHIFT);
    }

    /* Clear pending interrupt flags - CPR_RTD_01182 */
    DSPSS_ClearStatusFlags(Id, DSPSS_INTERRUPT_1_FLAGS);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_91();
    IP_DSPSS_0->INTERRUPT_ENABLE_REGISTER |= InterruptEnRes;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_91();

    InterruptEnRes = 0U;

    /* Interrupt 2 (thread specific interrupts) */
    if ((InterruptMask & DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_SHIFT);
    }

    /* Interrupt 2 (DSP common interrupts) */
    if ((InterruptMask & DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_DSP_INIT_LOW_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_REQ_FIFO_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_SET_BIT(InterruptEnRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_SHIFT);
    }

    /* Clear pending interrupt flags - CPR_RTD_01182 */
    DSPSS_ClearStatusFlags(Id, DSPSS_INTERRUPT_2_FLAGS);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_92();
    IP_DSPSS_0->INTERRUPT_ENABLE_REGISTER2 |= InterruptEnRes;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_92();
}


void DSPSS_InterruptDisable(const DSPSS_ThreadIdType Id,
                            const DSPSS_InterruptType InterruptMask)
{
    uint32 InterruptDisRes  = 0xFFFFFFFFU;

    /* Interrupt 1 (thread specific interrupts) */
    if ((InterruptMask & DSPSS_DSP_ERROR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_SHIFT);
    }

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_93();
    IP_DSPSS_0->INTERRUPT_ENABLE_REGISTER &= InterruptDisRes;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_93();

    InterruptDisRes = 0xFFFFFFFFU;

    /* Interrupt 2 (thread specific interrupts) */
    if ((InterruptMask & DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_SHIFT);
    }

    /* Interrupt 2 (DSP common interrupts) */
    if ((InterruptMask & DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_DSP_INIT_LOW_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_SHIFT);
    }

    if ((InterruptMask & DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_SHIFT);
    }

    if ((InterruptMask & DSPSS_REQ_FIFO_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_CLR_BIT(InterruptDisRes, DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_SHIFT);
    }

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_94();
    IP_DSPSS_0->INTERRUPT_ENABLE_REGISTER2 &= InterruptDisRes;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_94();
}


uint32 DSPSS_GetInterruptEnable(const DSPSS_ThreadIdType Id)
{
    uint32 InterruptEn = 0UL;
    uint32 InterruptRegVal;

    /* Interrupt 1 */
    InterruptRegVal = IP_DSPSS_0->INTERRUPT_ENABLE_REGISTER;

    /* Interrupt 1 (thread specific interrupts) */
    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DSP_ERROR_INTR_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DSP_ERROR_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_ERR_INTR_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_ERR_INTR_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_WRITE_BUFFER_XFR_ERR_INTR_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER_DMA_READ_BUFFER_XFR_ERR_INTR_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE;
    }

    /* Interrupt 2 */
    InterruptRegVal = IP_DSPSS_0->INTERRUPT_ENABLE_REGISTER2;

    /* Interrupt 2 (thread specific interrupts) */
    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_OVERFLOW_IE_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_CORE_BUFFER_UNDERRUN_IE_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, Id + DSPSS_INTERRUPT_ENABLE_REGISTER2_SDADC_SYNC_FIFO_OVERFLOW_IE_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE;
    }

    /* Interrupt 2 (DSP common interrupts) */
    if (DSPSS_CHK_BIT(InterruptRegVal, DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_ACK_TIMEOUT_ERR_IE_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, DSPSS_INTERRUPT_ENABLE_REGISTER2_DSP_INIT_LOW_IE_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_DSP_INIT_LOW_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_ACC_FIFO_THRESHOLD_CROSS_INT_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE;
    }

    if (DSPSS_CHK_BIT(InterruptRegVal, DSPSS_INTERRUPT_ENABLE_REGISTER2_REQ_FIFO_ERR_IE_EN_SHIFT) != 0U)
    {
        InterruptEn |= DSPSS_REQ_FIFO_ERR_INTR_ENABLE;
    }

    return InterruptEn;
}


uint32 DSPSS_GetStatusFlags(const DSPSS_ThreadIdType Id)
{
    uint32 Flags = 0UL;

    /* Interrupt 1 (thread specific interrupts) */
    if (DSPSS_DspToCoreTriggerErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_DSP_ERROR_INTR_ENABLE;
    }

    if (DSPSS_DmaWriteBufferXfrErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE;
    }

    if (DSPSS_DmaWriteBufferMismatchErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE;
    }

    if (DSPSS_DmaReadBufferXfrErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE;
    }

    if (DSPSS_DmaReadBufferMismatchErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE;
    }


    Flags |= DSPSS_GetStatusFlagsDSPCommon(Id);

    return Flags;
}

static inline uint32 DSPSS_GetStatusFlagsDSPCommon(const DSPSS_ThreadIdType Id)
{
    uint32 Flags = 0UL;
    /* Interrupt 2 (thread specific interrupts) */
    if (DSPSS_DspCoreBufferOverflowCheck(Id) != 0U)
    {
        Flags |= DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE;
    }

    if (DSPSS_DspCoreBufferUnderrunErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE;
    }

    if (DSPSS_SdadcSyncFifoOverflowErrorGet(Id) != 0U)
    {
        Flags |= DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE;
    }
    /* Interrupt 2 (DSP common interrupts) */
    if ((IP_DSPSS_0->DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_MASK) != 0U)
    {
        Flags |= DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE;
    }

    if ((IP_DSPSS_0->DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL & DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_MASK) != 0U)
    {
        Flags |= DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE;
    }

    if ((IP_DSPSS_0->SDADC_SYNC_FIFO_ERROR_STATUS & DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_MASK) != 0U)
    {
        Flags |= DSPSS_REQ_FIFO_ERR_INTR_ENABLE;
    }

    if ((IP_DSPSS_0->CURR_ACTIVE_THRD & DSPSS_CURR_ACTIVE_THRD_DSP_INIT_COMP_MASK) != 0U)
    {
        Flags |= DSPSS_DSP_INIT_LOW_INTR_ENABLE;
    }

    return Flags;
}


void DSPSS_ClearStatusFlags(const DSPSS_ThreadIdType Id,
                            const DSPSS_InterruptType Mask)
{
    /* Interrupt 1 (thread specific interrupts) */
    if ((Mask & DSPSS_DSP_ERROR_INTR_ENABLE) != 0U)
    {
        DSPSS_DspToCoreTriggerErrorClear(Id);
    }

    if ((Mask & DSPSS_DMA_WRITE_BUFFER_XFR_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_DmaWriteBufferXfrErrorClear(Id);
    }

    if ((Mask & DSPSS_DMA_WRITE_BUFFER_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_DmaWriteBufferMismatchErrorClear(Id);
    }

    if ((Mask & DSPSS_DMA_READ_BUFFER_XFR_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_DmaReadBufferXfrErrorClear(Id);
    }

    if ((Mask & DSPSS_DMA_READ_BUFFER_ERR_INTR_ENABLE) != 0U)
    {
        DSPSS_DmaReadBufferMismatchErrorClear(Id);
    }


    DSPSS_ClearStatusFlagsDSPCommon(Id,Mask);
}

static inline void DSPSS_ClearStatusFlagsDSPCommon(const DSPSS_ThreadIdType Id,
                                                   const DSPSS_InterruptType Mask)
{
    /* Interrupt 2 (thread specific interrupts) */
    if ((Mask & DSPSS_DSP_CORE_BUFFER_OVERFLOW_INTR_ENABLE) != 0U)
    {
        DSPSS_DspCoreBufferOverflowClear(Id);
    }

    if ((Mask & DSPSS_DSP_CORE_BUFFER_UNDERRUN_INTR_ENABLE) != 0U)
    {
        DSPSS_DspCoreBufferUnderrunErrorClear(Id);
    }

    if ((Mask & DSPSS_SDADC_SYNC_FIFO_OVERFLOW_INTR_ENABLE) != 0U)
    {
        DSPSS_SdadcSyncFifoOverflowErrorClear(Id);
    }
    /* Interrupt 2 (DSP common interrupts) */
    if ((Mask & DSPSS_DSP_ACK_TIMEOUT_ERR_INTR_ENABLE) != 0U)
    {
        IP_DSPSS_0->DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL = DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_DSP_ACK_TIMEOUT_ERR_MASK;
    }

    if ((Mask & DSPSS_REQ_ACC_FIFO_THRESHOLD_CROSS_INTR_ENABLE) != 0U)
    {
        IP_DSPSS_0->DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL = DSPSS_DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL_REQ_ACC_FIFO_INTR_MASK;
    }

    if ((Mask & DSPSS_REQ_FIFO_ERR_INTR_ENABLE) != 0U)
    {
        IP_DSPSS_0->SDADC_SYNC_FIFO_ERROR_STATUS = DSPSS_SDADC_SYNC_FIFO_ERROR_STATUS_REQ_FIFO_OVERFLOW_MASK;
    }
}


/*==================================================================================================
*                                       DSPSS_dma
==================================================================================================*/

void DSPSS_DmaReadBufferConfigure(const DSPSS_CFSDADC_DmaChannelType DmaChannel,
                                  const uint16 StartAddr,
                                  const uint16 EndAddr)
{
    DSPSS_DEV_ASSERT(DmaChannel < DSPSS_DMA_NUM);

    /* These addresses field is half-word aligned */
    uint16 DmaReadBufStartAddr = StartAddr >> 1U;
    uint16 DmaReadBufEndAddr   = EndAddr   >> 1U;

    switch (DmaChannel)
    {
        case DSPSS_DMA_CHANNEL0:
            IP_DSPSS_0->DMA_READ_ADDR0 = DSPSS_DMA_READ_ADDR0_DMA_READ_START_ADDR(DmaReadBufStartAddr) |
                                         DSPSS_DMA_READ_ADDR0_DMA_READ_END_ADDR(DmaReadBufEndAddr);
            break;

        case DSPSS_DMA_CHANNEL1:
            IP_DSPSS_0->DMA_READ_ADDR1 = DSPSS_DMA_READ_ADDR1_DMA_READ_START_ADDR(DmaReadBufStartAddr) |
                                         DSPSS_DMA_READ_ADDR1_DMA_READ_END_ADDR(DmaReadBufEndAddr);
            break;

        case DSPSS_DMA_CHANNEL2:

            IP_DSPSS_0->DMA_READ_ADDR2 = DSPSS_DMA_READ_ADDR2_DMA_READ_START_ADDR(DmaReadBufStartAddr) |
                                         DSPSS_DMA_READ_ADDR2_DMA_READ_END_ADDR(DmaReadBufEndAddr);
            break;

        case DSPSS_DMA_CHANNEL3:
            IP_DSPSS_0->DMA_READ_ADDR3 = DSPSS_DMA_READ_ADDR3_DMA_READ_START_ADDR(DmaReadBufStartAddr) |
                                         DSPSS_DMA_READ_ADDR3_DMA_READ_END_ADDR(DmaReadBufEndAddr);
            break;

        case DSPSS_DMA_CHANNEL4:
            IP_DSPSS_0->DMA_READ_ADDR4 = DSPSS_DMA_READ_ADDR4_DMA_READ_START_ADDR(DmaReadBufStartAddr) |
                                         DSPSS_DMA_READ_ADDR4_DMA_READ_END_ADDR(DmaReadBufEndAddr);
            break;

        case DSPSS_DMA_CHANNEL5:
            IP_DSPSS_0->DMA_READ_ADDR5 = DSPSS_DMA_READ_ADDR5_DMA_READ_START_ADDR(DmaReadBufStartAddr) |
                                         DSPSS_DMA_READ_ADDR5_DMA_READ_END_ADDR(DmaReadBufEndAddr);
            break;

        default:
            /* Do nothing */
            break;
    }
}


void DSPSS_DmaReadBufferEnable(const DSPSS_CFSDADC_DmaChannelType DmaChannel)
{
    DSPSS_DEV_ASSERT(DmaChannel < DSPSS_DMA_NUM);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_95();
    /* Enable dma read buffer */
    IP_DSPSS_0->DMA_BUFFER_CFG |=  DSPSS_DMA_BUFFER_CFG_DMA_READ_EN(1UL << (uint32)DmaChannel);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_95();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_86();
    /* Also update the global variable because DMA_CURR_RD_PTR_n[DMA_READ_PTR_WRAP] is cleared when we enable DMA buffer monitoring */
    DSPSS_DmaReadBufferWrapStatus &= ~(1U << (uint8)DmaChannel);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_86();
}


void DSPSS_DmaReadBufferDisable(const DSPSS_CFSDADC_DmaChannelType DmaChannel)
{
    DSPSS_DEV_ASSERT(DmaChannel < DSPSS_DMA_NUM);

    /* Disable dma read buffer */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_103();
    IP_DSPSS_0->DMA_BUFFER_CFG &= ~DSPSS_DMA_BUFFER_CFG_DMA_READ_EN(1UL << (uint32)DmaChannel);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_103();
}


boolean DSPSS_DmaReadBufferWrapPtrCheck(const DSPSS_CFSDADC_DmaChannelType DmaChannel)
{
    DSPSS_DEV_ASSERT(DmaChannel < DSPSS_DMA_NUM);

    boolean WrapStatus = FALSE;
    uint32 PrevWrapValue;
    uint32 CurrWrapValue = 0UL;

    /* Read the current wrap status value of the according Dma read buffer */
    switch (DmaChannel)
    {
        case DSPSS_DMA_CHANNEL0:
            CurrWrapValue = DSPSS_GET_BIT(IP_DSPSS_0->DMA_CURR_RD_PTR0, DSPSS_DMA_CURR_RD_PTR0_DMA_READ_PTR_WRAP_SHIFT);
            break;

        case DSPSS_DMA_CHANNEL1:
            CurrWrapValue = DSPSS_GET_BIT(IP_DSPSS_0->DMA_CURR_RD_PTR1, DSPSS_DMA_CURR_RD_PTR1_DMA_READ_PTR_WRAP_SHIFT);
            break;

        case DSPSS_DMA_CHANNEL2:
            CurrWrapValue = DSPSS_GET_BIT(IP_DSPSS_0->DMA_CURR_RD_PTR2, DSPSS_DMA_CURR_RD_PTR2_DMA_READ_PTR_WRAP_SHIFT);
            break;

        case DSPSS_DMA_CHANNEL3:
            CurrWrapValue = DSPSS_GET_BIT(IP_DSPSS_0->DMA_CURR_RD_PTR3, DSPSS_DMA_CURR_RD_PTR3_DMA_READ_PTR_WRAP_SHIFT);
            break;

        case DSPSS_DMA_CHANNEL4:
            CurrWrapValue = DSPSS_GET_BIT(IP_DSPSS_0->DMA_CURR_RD_PTR4, DSPSS_DMA_CURR_RD_PTR4_DMA_READ_PTR_WRAP_SHIFT);
            break;

        case DSPSS_DMA_CHANNEL5:
            CurrWrapValue = DSPSS_GET_BIT(IP_DSPSS_0->DMA_CURR_RD_PTR5, DSPSS_DMA_CURR_RD_PTR5_DMA_READ_PTR_WRAP_SHIFT);
            break;

        default:
            /* Do nothing */
            break;
    }

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_100();
    /* Read the according buffer wrap status value */
    PrevWrapValue = ((uint32)DSPSS_DmaReadBufferWrapStatus >> (uint32)DmaChannel) & 1UL;

    /* The wrap bit toggles whenever the read pointer in the DMA-READ buffer wraps */
    if (CurrWrapValue != PrevWrapValue)
    {
        /* Update the global variable along with hardware by toggling it */
        DSPSS_DmaReadBufferWrapStatus ^= (1U << (uint8)DmaChannel);
        WrapStatus = TRUE;
    }
    /*Exit the exclusive area*/
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_100();

    return WrapStatus;
}


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */


#ifdef __cplusplus
}
#endif

/** @} */
/** @endcond */
