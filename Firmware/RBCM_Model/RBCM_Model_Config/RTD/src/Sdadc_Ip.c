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
*   @file Sdadc_Ip.c
*
*   @addtogroup sd_adc_ip Sd Adc IPL
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
#include "Sdadc_Ip.h"
#include "Sdadc_Ip_Irq.h"  /* for ISR functions prototype */
#include "SchM_Adc.h"

#if (STD_ON == SDADC_IP_DSPSS_ENABLED)
#include "DSPSS_Api.h"          /* DSPSS header */
#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SDADC_IP_VENDOR_ID_C                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define SDADC_IP_SW_MAJOR_VERSION_C               5
#define SDADC_IP_SW_MINOR_VERSION_C               0
#define SDADC_IP_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if SDADC_Ip.c file and SDADC_Ip.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_C != SDADC_IP_VENDOR_ID)
    #error "SDADC_Ip.c and SDADC_Ip.h have different vendor ids"
#endif

/* Check if SDADC_Ip.c file and SDADC_Ip.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_C != SDADC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_C != SDADC_IP_AR_RELEASE_MINOR_VERSION) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_C != SDADC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip.c and SDADC_Ip.h are different"
#endif

/* Check if SDADC_Ip.c file and SDADC_Ip.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_C != SDADC_IP_SW_MAJOR_VERSION) || \
     (SDADC_IP_SW_MINOR_VERSION_C != SDADC_IP_SW_MINOR_VERSION) || \
     (SDADC_IP_SW_PATCH_VERSION_C != SDADC_IP_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of SDADC_Ip.c and SDADC_Ip.h are different"
#endif

/* Check if SDADC_Ip.c file and SDADC_Ip_Irq.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_C != SDADC_IP_VENDOR_ID_IRQ)
    #error "SDADC_Ip.c and SDADC_Ip_Irq.h have different vendor ids"
#endif

/* Check if SDADC_Ip.c file and SDADC_Ip_Irq.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_C != SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_C != SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_C != SDADC_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip.c and SDADC_Ip_Irq.h are different"
#endif

/* Check if SDADC_Ip.c file and SDADC_Ip_Irq.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_C != SDADC_IP_SW_MAJOR_VERSION_IRQ) || \
     (SDADC_IP_SW_MINOR_VERSION_C != SDADC_IP_SW_MINOR_VERSION_IRQ) || \
     (SDADC_IP_SW_PATCH_VERSION_C != SDADC_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of SDADC_Ip.c and SDADC_Ip_Irq.h are different"
#endif

#if (STD_ON == SDADC_IP_DSPSS_ENABLED)

/* Check if SDADC_Ip.c file and DSPSS_Api.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_C != DSPSS_VENDOR_ID_API)
    #error "SDADC_Ip.c and DSPSS_Api.h have different vendor ids"
#endif

/* Check if SDADC_Ip.c file and DSPSS_Api.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_C != DSPSS_AR_RELEASE_MAJOR_VERSION_API) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_C != DSPSS_AR_RELEASE_MINOR_VERSION_API) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_C != DSPSS_AR_RELEASE_REVISION_VERSION_API) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip.c and DSPSS_Api.h are different"
#endif

/* Check if SDADC_Ip.c file and DSPSS_Api.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_C != DSPSS_SW_MAJOR_VERSION_API) || \
     (SDADC_IP_SW_MINOR_VERSION_C != DSPSS_SW_MINOR_VERSION_API) || \
     (SDADC_IP_SW_PATCH_VERSION_C != DSPSS_SW_PATCH_VERSION_API) \
    )
  #error "Software Version Numbers of SDADC_Ip.c and DSPSS_Api.h are different"
#endif

#endif /* (STD_ON == SDADC_IP_DSPSS_ENABLED) */

#ifdef FEATURE_ADC_HAS_SDADC


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define MAX_S32 (2147483647)
#define MIN_S32 (-2147483648)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/* SEC_CONST_UNSPECIFIED */
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/* Table of base addresses for SDADC instances. */
static SDADC_Type * const Sdadc_Ip_apxSdadcBase[SDADC_INSTANCE_COUNT] = IP_SDADC_BASE_PTRS;

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"


/* SEC_VAR_INIT_32 */
#define ADC_START_SEC_VAR_INIT_32
#include "Adc_MemMap.h"

/* The gain error variable */
static sint32 Sdadc_Ip_as32GainErr[SDADC_INSTANCE_COUNT] = SDADC_IP_GAIN_ERRORS;

#define ADC_STOP_SEC_VAR_INIT_32
#include "Adc_MemMap.h"


/* SEC_VAR_CLEARED_16 */
#define ADC_START_SEC_VAR_CLEARED_16
#include "Adc_MemMap.h"

/* The offset error in case of data conversion after calibration */
static sint16 Sdadc_Ip_as16OffsetErr[SDADC_INSTANCE_COUNT];

#define ADC_STOP_SEC_VAR_CLEARED_16
#include "Adc_MemMap.h"


/* SEC_VAR_CLEARED_UNSPECIFIED */
#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

/* Global state structure */
static Sdadc_Ip_StateStructType Sdadc_Ip_axSdadcState[SDADC_INSTANCE_COUNT];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

static inline void Sdadc_CalculateSum(sint32 RawData, sint32 * Sum);
static Sdadc_Ip_StatusType Sdadc_AverageCalibrationResult(const uint32 Instance,
                                                          sint32 * const CalibResult);

static Sdadc_Ip_StatusType Sdadc_OffsetCalibration(const uint32 Instance);
static Sdadc_Ip_StatusType Sdadc_GainCalibration(const uint32 Instance);

static inline void Sdadc_CheckAndCallNotification(void (*Callback)(void));

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
static inline Sdadc_Ip_StatusType Sdadc_InitDspssThread(const uint32 Id,
                                                 const DSPSS_ThreadConfigType * const Config);

static inline Sdadc_Ip_StatusType Sdadc_InitDspssThreadConfigure(const uint32 Id,
                                                 const DSPSS_ThreadConfigType * const Config);

static inline void Sdadc_DeinitDspssThread(const uint32 Id);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Calculate sum of conversion results*/
static inline void Sdadc_CalculateSum(sint32 RawData, sint32 * Sum)
{
    if (RawData > 0)
    {
        if (((sint32)MAX_S32 - RawData) > *Sum)
        {
            *Sum += RawData;
        }
        else
        {
            *Sum = (sint32)MAX_S32;
        }
    }
    else
    {
        if (((sint32)MIN_S32 - RawData) < *Sum)
        {
            *Sum += RawData;
        }
        else
        {
            *Sum = (sint32)MIN_S32;
        }
    }
}
/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_AverageCalibrationResult
* Description   : This function takes multiple readings and calculate the average output
* to reduce contribution of noise during the calibration process
* Note:
*     - The function uses value of AverageCalib for number of conversions when calculating an average value.
*     - It also skips the first NbSkipSamples (number of samples) in order to ignore the unstable results.
*
* END**************************************************************************/
static Sdadc_Ip_StatusType Sdadc_AverageCalibrationResult(const uint32 Instance,
                                                          sint32 * const CalibResult)
{
    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    Sdadc_Ip_StatusType Status = SDADC_IP_STATUS_SUCCESS;
    /* Timeout counter variables */
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SDADC_IP_TIMEOUT_VAL, SDADC_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SDADC_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0U;
    const uint32 NbSkipSamples = (uint32)Sdadc_Ip_axSdadcState[Instance].Config->CalibSkipped;
    const uint32 AverageCalib  = (uint32)Sdadc_Ip_axSdadcState[Instance].Config->CalibAverage;
    sint32 Raw;
    sint32 Sum = 0;
    uint32 Cnt;

    /* Perform dummy reads to ignore some first unstable data */
    for (Cnt = 0U ; Cnt < NbSkipSamples; Cnt++)
    {
        /* Wait for conversion to finish - data is available and FIFO is not empty */
        while ( ((Base->SFR & SDADC_SFR_DFEF_MASK) != 0U) && (ElapsedTicks < TimeoutTicks) )
        {
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SDADC_IP_TIMEOUT_TYPE);
        }
        if (ElapsedTicks >= TimeoutTicks)
        {
            break;
        }
        /* Dummy read data from FIFO */
        (void)Base->CDR;
    }

    /* Reset timeout counter */
    CurrentTicks = OsIf_GetCounter(SDADC_IP_TIMEOUT_TYPE);
    ElapsedTicks = 0U;

    /* Take multiple readings and calculate the average output */
    for (Cnt = 0U; Cnt < AverageCalib; Cnt++)
    {
        /* Wait for conversion to finish - data is available and FIFO is not empty */
        while ( ((Base->SFR & SDADC_SFR_DFEF_MASK) != 0U) && (ElapsedTicks < TimeoutTicks) )
        {
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SDADC_IP_TIMEOUT_TYPE);
        }

        if (ElapsedTicks >= TimeoutTicks)
        {
            Status = SDADC_IP_STATUS_TIMEOUT;
            break;
        }

        Raw = (sint16)(uint16)((Base->CDR & SDADC_CDR_CDATA_MASK) >> SDADC_CDR_CDATA_SHIFT);
        Sdadc_CalculateSum(Raw, &Sum);
        /* If DFORF is set, further datawords will not be received into FIFO even if sufficient room exists,
        so make sure the data FIFO overrun flag is not set */
        Base->SFR = SDADC_SFR_DFORF_MASK | SDADC_SFR_DFFF_MASK;
    }

    if (SDADC_IP_STATUS_SUCCESS == Status)
    {
        /* Calculate the average output */
        *CalibResult = (sint32)(Sum / (sint32)AverageCalib);
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_GainCalibration
* Description   : This function performs a gain calibration of the SDADC. Gain calibration
* should be run before using the SDADC converter or after the operating conditions
* (particularly Vref) change significantly. The measured gain value is going be used to
* nullify the gain errors in the data conversion.
* The conversion number that is performed by calibration should be from 16 to 64. The higher the number
* of conversion done, the higher the rejection of noise during the calibration.
*
* END**************************************************************************/
static Sdadc_Ip_StatusType Sdadc_GainCalibration(const uint32 Instance)
{
    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    Sdadc_Ip_StatusType Status;
    sint32 Dmax = 0;
    sint32 Dmin = 0;

    /* Save the current state of MCR, CSR, OSDR to restore the configuration after calibration */
    const uint32 currentMCR  = Base->MCR;
    const uint32 currentCSR  = Base->CSR;
    const uint32 currentOSDR = Base->OSDR;

    /**** Part 0: Prepare settings for calibration ****/

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96();
    /* Disable SDADC */
    Base->MCR &= ~SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_97();
    /* Flush data FIFO to make sure the FIFO does not contains data of previous conversions */
    Base->FCR |= SDADC_FCR_FRST_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_97();

    /* Make sure that the data FIFO overrun flag is not set */
    Base->SFR = SDADC_SFR_DFORF_MASK | SDADC_SFR_DFFF_MASK;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96();
    /* Enable BIASGEN and common mode output */
    Base->MCR |= (SDADC_MCR_BIASGEN_EN_MASK | SDADC_MCR_VCOM2EN_MASK);
    /* Enable differential mode */
    Base->MCR &= ~SDADC_MCR_MODE_MASK;
    /* Configure output data is signed and sign extended to 16 bits */
    Base->MCR |= SDADC_MCR_ODF_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96();

    /* Configure OSDR[OSD] > 4 */
    Base->OSDR = SDADC_OSDR_OSD(0xFFU);

    /**** Part 1: Perform full positive scale calibration ****/
    /* Select pair VREFP - VREFN (full positive scale) */
    Base->CSR = SDADC_CSR_ANCHSEL(0x6U);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96();
    /* Enable SDADC */
    Base->MCR |= SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96();

    /* Start calibration */
    Base->RKR = SDADC_RKR_RESET_KEY(0x5AF0U);
    /* Calculate the average output of full positive scale data conversions */
    Status = Sdadc_AverageCalibrationResult(Instance, &Dmax);

    if (SDADC_IP_STATUS_SUCCESS == Status)
    {
        /**** Part 2: Perform full negative scale calibration ****/

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96();
        /* Disable SDADC */
        Base->MCR &= ~SDADC_MCR_EN_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96();

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_97();
        /* Flush data FIFO to make sure the FIFO does not contains data of previous conversions */
        Base->FCR |= SDADC_FCR_FRST_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_97();

        /* Make sure that the data FIFO overrun flag is not set */
        Base->SFR = SDADC_SFR_DFORF_MASK | SDADC_SFR_DFFF_MASK;

        /* Select pair VREFN - VREFP (full negative scale) */
        Base->CSR = SDADC_CSR_ANCHSEL(0x7U);

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96();
        /* Enable SDADC */
        Base->MCR |= SDADC_MCR_EN_MASK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96();

        /* Start calibration */
        Base->RKR = SDADC_RKR_RESET_KEY(0x5AF0U);
        /* Calculate the average output of full negative scale data conversions */
        Status = Sdadc_AverageCalibrationResult(Instance, &Dmin);
    }

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96();
    /* Stop conversion */
    Base->MCR &= ~SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96();

    /* Restore the register configuration */
    Base->OSDR = currentOSDR;
    Base->CSR  = currentCSR;
    Base->MCR  = currentMCR;

    if (SDADC_IP_STATUS_SUCCESS == Status)
    {
        /* Calculate the gain error: Gain = (Dmax - Dmin) / 65536
           Note: only storing the difference, the division by 65536 will be done in Sdadc_Ip_ApplyCalibration.
         */
        Sdadc_Ip_as32GainErr[Instance] = Dmax - Dmin;
    }

    return Status;
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_OffsetCalibration
* Description   : This function performs a offset calibration of the SDADC. Offset calibration
* should be run before using the SDADC converter or after the operating conditions
* (particularly Vref, input gain) change significantly.
* The measured offset is going be used to nullify the offset error in the data conversion.
* The offset calibration must be performed for each input gain changing since it is expected to
* vary with input gain configuration of SDADC.
*
* END**************************************************************************/
static Sdadc_Ip_StatusType Sdadc_OffsetCalibration(const uint32 Instance)
{
    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    Sdadc_Ip_StatusType Status;
    sint32 CalibResult = 0;

    /* Save the current state of registers to restore the configuration after calibration */
    uint32 currentMCR  = Base->MCR;
    uint32 currentCSR  = Base->CSR;
    uint32 currentOSDR = Base->OSDR;

    /**** Part 0: Prepare settings for calibration ****/
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_98();
    /* Disable SDADC */
    Base->MCR &= ~SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_98();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_99();
    /* Flush data FIFO to make sure the FIFO does not contains data of previous conversions */
    Base->FCR |= SDADC_FCR_FRST_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_99();

    /* Make sure that the data FIFO overrun flag is not set */
    Base->SFR = SDADC_SFR_DFORF_MASK | SDADC_SFR_DFFF_MASK;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_98();
    /* Enable BIASGEN and common mode output */
    Base->MCR |= (SDADC_MCR_BIASGEN_EN_MASK | SDADC_MCR_VCOM2EN_MASK);
    /* Enable differential mode */
    Base->MCR &= ~SDADC_MCR_MODE_MASK;
    /* Configure output data is signed and sign extended to 16 bits */
    Base->MCR |= SDADC_MCR_ODF_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_98();
    /* Configure OSDR[OSD] > 4 */
    Base->OSDR = SDADC_OSDR_OSD(0xFFU);


    /**** Part 1: Perform the offset calibration ****/
    /* Select pair vcom1_hv - vcom1_hv */
    Base->CSR = SDADC_CSR_ANCHSEL(0x4U);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_98();
    /* Enable SDADC */
    Base->MCR |= SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_98();

    /* Start calibration */
    Base->RKR = SDADC_RKR_RESET_KEY(0x5AF0U);
    /* Calculate the offset error by averaging output of multiple conversions */
    Status = Sdadc_AverageCalibrationResult(Instance, &CalibResult);

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_98();
    /* Stop conversion */
    Base->MCR &= ~SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_98();

    /* Restore the registers configuration */
    Base->OSDR = currentOSDR;
    Base->CSR  = currentCSR;
    Base->MCR  = currentMCR;

    if (SDADC_IP_STATUS_SUCCESS == Status)
    {
        Sdadc_Ip_as16OffsetErr[Instance] = (sint16)CalibResult;
    }

    return Status;
}


/*FUNCTION*********************************************************************
 *
 * Function Name : Sdadc_CheckAndCallNotification
 * Description   : Checks if the given callback is not NULL_PTR then calls it
 *
 *END*************************************************************************/
static inline void Sdadc_CheckAndCallNotification(void (*Callback)(void))
{
    if (Callback != NULL_PTR)
    {
        Callback();
    }
}

/*FUNCTION*********************************************************************
 *
 * Function Name : Sdadc_CallWdgNotification
 * Description   : Find physical channel id call appropriate notification
 *
 *END*************************************************************************/
static inline void Sdadc_CheckAndCallWdgNotification(const uint32 Instance,
                                                     const uint32 IsrFlags)
{
    const SDADC_Type * BasePtr;
    uint32 WdgFlags;
    uint32 MCRVal;
    uint32 Mode;
    uint32 Vcomsel;
    uint32 ChanSelect;
    uint32 PhysicalChannelId;

    if (Sdadc_Ip_axSdadcState[Instance].Config->WdgCrossOverNotification != NULL_PTR)
    {
        BasePtr = Sdadc_Ip_apxSdadcBase[Instance];

        /* Read the current channel from hardware register */
        MCRVal     = BasePtr->MCR;
        Mode       = (MCRVal       & SDADC_MCR_MODE_MASK )   >> SDADC_MCR_MODE_SHIFT;
        Vcomsel    = (MCRVal       & SDADC_MCR_VCOMSEL_MASK) >> SDADC_MCR_VCOMSEL_SHIFT;
        ChanSelect = (BasePtr->CSR & SDADC_CSR_ANCHSEL_MASK) >> SDADC_CSR_ANCHSEL_SHIFT;

        /* Compose to get the physical channel number */
        PhysicalChannelId = SDADC_IP_CHAN_SELECT(Mode, Vcomsel, ChanSelect);

        /* Decode to get wdg flag status */
        WdgFlags  = ((IsrFlags & SDADC_SFR_WTHH_MASK) != 0u) ? SDADC_IP_WDG_HIGH_FLAG : 0u;
        WdgFlags |= ((IsrFlags & SDADC_SFR_WTHL_MASK) != 0u) ? SDADC_IP_WDG_LOW_FLAG  : 0u;

        /* Call the Wdg notification */
        Sdadc_Ip_axSdadcState[Instance].Config->WdgCrossOverNotification((uint16)PhysicalChannelId, (uint8)WdgFlags);
    }
}

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/*FUNCTION*********************************************************************
 *
 * Function Name : Sdadc_InitDspssThread
 * Description   : Initializes the desired Dspss thread
 *                 This function will load the DSPSS firmware only once if it is not initialized yet.
 *
 *END*************************************************************************/
static inline Sdadc_Ip_StatusType Sdadc_InitDspssThread(const uint32 Id,
                                                 const DSPSS_ThreadConfigType * const Config)
{
    Sdadc_Ip_StatusType Status = SDADC_IP_STATUS_SUCCESS;

    if (NULL_PTR != Config)
    {
        if (FALSE == DSPSS_HasInitialized())
        {
            /* Load the FW init PMEM and default configuration into XMEM (only once) */
            if (DSPSS_OK != DSPSS_Init())
            {
                Status = SDADC_IP_STATUS_ERROR;
            }
        }

        if (SDADC_IP_STATUS_SUCCESS == Status)
        {
            Status = Sdadc_InitDspssThreadConfigure(Id, Config);
        }
    }

    return Status;
}

static inline Sdadc_Ip_StatusType Sdadc_InitDspssThreadConfigure(const uint32 Id,
                                                 const DSPSS_ThreadConfigType * const Config)
{
    Sdadc_Ip_StatusType Status = SDADC_IP_STATUS_SUCCESS;
    /* Timeout counter variables */
    uint32 TimeoutTicks;
    uint32 CurrentTicks;
    uint32 ElapsedTicks;

    /* Configure Thread_x for SDADC_x */
    (void)DSPSS_ThreadConfigure(Id, Config);

    /* Initialize DSPSS by deasserting reset to the periphery,
       which results in execution of reset routine that initializes enabled threads */
    (void)DSPSS_ThreadsInitialize();

    /* Prepare timeout counter variables */
    TimeoutTicks = OsIf_MicrosToTicks(SDADC_IP_TIMEOUT_VAL, SDADC_IP_TIMEOUT_TYPE);
    CurrentTicks = OsIf_GetCounter(SDADC_IP_TIMEOUT_TYPE);
    ElapsedTicks = 0U;

    /* Wait for CFSDADC FW to perform reset routine and set its enable threads status to initialized */
    while (DSPSS_ThreadsStatusGet(Id) != DSPSS_CFSDADC_STATUS_INITIALIZED)
    {
        /* Check for timeout */
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SDADC_IP_TIMEOUT_TYPE);
        if (ElapsedTicks >= TimeoutTicks)
        {
            Status = SDADC_IP_STATUS_TIMEOUT;
            break;
        }
    }

    return Status;
}


/*FUNCTION*********************************************************************
 *
 * Function Name : Sdadc_DeinitDspssThread
 * Description   : Suspend the DSPSS thread of the corresponding SDADC instance.
 *                 Deinit the DSPSS if there are no other threads running.
 *
 *END*************************************************************************/
static inline void Sdadc_DeinitDspssThread(const uint32 Id)
{
    boolean OtherThreadRunning = FALSE;
    DSPSS_CFSDADC_ThreadStatusType ThreadStatus;
    uint32 Instance;

    /* 1) Disable DSPSS thread along with SDADC */
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Id].Config->DspssConfig)
    {
        /* Suspend current thread */
        DSPSS_ThreadSuspend(Id);
    }

    /* 2.1) Check if there are any other SDADC instance running with DSPSS thread */
    for (Instance = 0U; Instance < SDADC_INSTANCE_COUNT; Instance++)
    {
        if (Instance != Id)
        {
            /* Get thread status */
            ThreadStatus = DSPSS_ThreadsStatusGet(Instance);
            if ( (ThreadStatus != DSPSS_CFSDADC_STATUS_INACTIVE) && (ThreadStatus != DSPSS_CFSDADC_STATUS_SUSPENDED) )
            {
                /* The thread is being used */
                OtherThreadRunning = TRUE;
                break;
            }
        }
    }
    /* 2.2) Deinit the DSPSS if there are no other threads running */
    if (FALSE == OtherThreadRunning)
    {
        /* Suspend all running threads */
        (void)DSPSS_Stop();
        /* Deinit the DSPSS */
        (void)DSPSS_Deinit();
    }
}
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_Init
* Description   : This function configures the SDADC module with the options
* provided in the structure.
*
* @implements     Sdadc_Ip_Init_Activity
* END**************************************************************************/
Sdadc_Ip_StatusType Sdadc_Ip_Init(const uint32 Instance,
                                  const Sdadc_Ip_ConfigType * const Config)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);
    SDADC_IP_DEV_ASSERT(Config != NULL_PTR);
    SDADC_IP_DEV_ASSERT(Config->ChannelConfigsPtr != NULL_PTR);
    SDADC_IP_DEV_ASSERT(Config->NumChannels > 0U);
    SDADC_IP_DEV_ASSERT(NULL_PTR == Sdadc_Ip_axSdadcState[Instance].Config);  /* Driver was not initialized */

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    Sdadc_Ip_StatusType Status = SDADC_IP_STATUS_SUCCESS;

    /* Only use the first channel (the others can be used to change the input channel in runtime) */
    const Sdadc_Ip_ChannelType ChannelConfig = Config->ChannelConfigsPtr[0];
    const uint32 Mode       = ((uint32)ChannelConfig & SDADC_IP_CHANNEL_ENUM_MODE_MASK)    >> SDADC_IP_CHANNEL_ENUM_MODE_SHIFT;
    const uint32 Vcomsel    = ((uint32)ChannelConfig & SDADC_IP_CHANNEL_ENUM_VCOMSEL_MASK) >> SDADC_IP_CHANNEL_ENUM_VCOMSEL_SHIFT;
    const uint32 ChannelSel = ((uint32)ChannelConfig & SDADC_IP_CHANNEL_ENUM_CHAN_MASK)    >> SDADC_IP_CHANNEL_ENUM_CHAN_SHIFT;

    uint32 McrValue = 0U;

    /* 1) Configure MCR to select the required mode, trigger, common mode voltage, input gain, and decimation rate */
    McrValue |= SDADC_MCR_PDR(Config->DecimaRate);
    McrValue |= SDADC_MCR_PGAN(Config->InputGain);
    McrValue |= SDADC_MCR_MODE(Mode);
    McrValue |= SDADC_MCR_VCOMSEL(Vcomsel);
    McrValue |= SDADC_MCR_VCOM2EN_MASK;  /* always enable vcom2 */
    McrValue |= SDADC_MCR_WDGEN(Config->WdgEnable ? 1U : 0U);
    McrValue |= SDADC_MCR_ODF(Config->Resolution);
    McrValue |= SDADC_MCR_FRZ(Config->StopInDebug ? 1U : 0U);
    McrValue |= SDADC_MCR_TRIGEDSEL(Config->TrigEdge);
    McrValue |= SDADC_MCR_BIASGEN_EN_MASK;  /* Enable biasgen before SDADC enables */

    /* 2) Trigger selection before enabling the wraparound mode */
    if (Config->TrigSelect != SDADC_IP_TRIGGER_DISABLE)
    {
        McrValue |= SDADC_MCR_TRIGSEL(Config->TrigSelect);
        McrValue |= SDADC_MCR_TRIGEN_MASK;
    }
    else
    {
        /* Trigger is disabled */
        McrValue &= ~SDADC_MCR_TRIGEN_MASK;
    }

    /* Configure MCR register */
    Base->MCR = McrValue;

    /* 3) Configure the input analog channel and wrap around value before entering wraparound mode */
    Base->CSR = SDADC_CSR_ANCHSEL_WRAP(Config->Wraparound) | SDADC_CSR_ANCHSEL(ChannelSel);
    /* Configure wraparound mode */
    Base->MCR |= SDADC_MCR_WRMODE(Config->WrapAroundEnable ? 1U : 0U);

    /* 4) Configure output settling delay */
    Base->OSDR = SDADC_OSDR_OSD(Config->OutputSetDelay);

    /* 5) Clear all request flags */
    Base->SFR = SDADC_IP_FLAG_STATUS_REQUEST;
    /* Flush data FIFO to make sure the FIFO does not contains data of previous conversions */
    Base->FCR |= SDADC_FCR_FRST_MASK;
    /* Configure data FIFO */
    Base->FCR = SDADC_FCR_FE(Config->FifoEnable ? 1U : 0U) |
                SDADC_FCR_FOWEN(Config->FifoOverwrite ? 1U : 0U) |
                SDADC_FCR_FTHLD(Config->FifoThreshold);

    /* 6) Configures the wdg monitor */
    Base->WTHHLR = SDADC_WTHHLR_THRH(Config->WdgUpperThreshold) | SDADC_WTHHLR_THRL(Config->WdgLowerThreshold);
    if (TRUE == Config->WdgEnable)
    {
        Sdadc_Ip_EnableInterruptEvents(Instance, SDADC_IP_EVENT_WDOG_CROSSOVER);
    }

    /* 7) Enable SDADC */
    Base->MCR |= SDADC_MCR_EN_MASK;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    /* 8) Configure DSPSS "thread" for the corresponding SDADC "instance" */
    Status = Sdadc_InitDspssThread(Instance, Config->DspssConfig);
#endif

    /* 9) Mark the driver as initialized */
    Sdadc_Ip_axSdadcState[Instance].Config = Config;

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_Deinit
* Description   : This function returns the SDADC internal registers to their reset values.
*
* @implements     Sdadc_Ip_Deinit_Activity
* END**************************************************************************/
void Sdadc_Ip_Deinit(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);
    SDADC_IP_DEV_ASSERT(Sdadc_Ip_axSdadcState[Instance].Config != NULL_PTR);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    /* Reset the SDADC registers to their reset values */
    Base->MCR    = 0U;
    Base->CSR    = 0U;
    Base->OSDR   = 0U;
    Base->RSER   = 0U;
    Base->FCR    = 0U;
    Base->WTHHLR = 0U;
    /* Flush data FIFO to make sure the FIFO does not contains data of previous conversions */
    Base->FCR |= SDADC_FCR_FRST_MASK;
    /* Clear all status request flags */
    Base->SFR = SDADC_IP_FLAG_STATUS_REQUEST;

    /* Set gain error and offset variables to default value */
    Sdadc_Ip_as32GainErr[Instance]   = SDADC_IP_GAIN_ERROR_DEFAULT;
    Sdadc_Ip_as16OffsetErr[Instance] = SDADC_IP_OFFSET_ERROR_DEFAULT;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    /* Disable DSPSS thread along with SDADC */
    Sdadc_DeinitDspssThread(Instance);
#endif

    /* Mark the driver as un-initialized */
    Sdadc_Ip_axSdadcState[Instance].Config = NULL_PTR;
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_Powerup
* Description   : This function enables the SDADC block.
*
* @implements     Sdadc_Ip_Powerup_Activity
* END**************************************************************************/
void Sdadc_Ip_Powerup(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_72();
    /* Enable SDADC Block */
    Base->MCR |= SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_72();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_Powerdown
* Description   : This function disables the SDADC block.
*                 SDADC internal modulator placed in low consumption mode
* Note          : This function also clears RSER[DFFDIRE] to ensure safe operation.
*
* @implements     Sdadc_Ip_Powerdown_Activity
* END**************************************************************************/
void Sdadc_Ip_Powerdown(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_73();
    /* Put SDADC internal modulator in low consumption mode */
    Base->MCR &= ~SDADC_MCR_EN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_73();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_102();
    /* Also clear RSER[DFFDIRE] (disable "Data FIFO Full DMA/Interrupt Request") alongwith MCR[EN] to ensure safe operation.
       Note: this follows the recommendation in the description of SFR[DFFF] bit from the Reference manual.
     */
    Base->RSER &= ~SDADC_RSER_DFFDIRE_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_102();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_ReloadConversion
* Description   : This function resets SDADC internal modulator to start a fresh conversion.
* This function must be call after changing converter configuration (gain, input channel, trigger, watchdog...).
*
* @implements     Sdadc_Ip_ReloadConversion_Activity
* END**************************************************************************/
void Sdadc_Ip_ReloadConversion(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    /* Enable the thread if configured */
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        DSPSS_ThreadEnable(Instance);
    }
#endif

    /* Reset SDADC to start a fresh conversion */
    Base->RKR = SDADC_RKR_RESET_KEY(0x5AF0u);
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_SwTriggerConversion
* Description   : This function generates the trigger event output which can be used
* for triggering conversions.
*
* @implements     Sdadc_Ip_SwTriggerConversion_Activity
* END**************************************************************************/
void Sdadc_Ip_SwTriggerConversion(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    /* Generates the trigger event output */
    Base->STKR = SDADC_STKR_ST_KEY(0xFFFFU);
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_SetWdgThreshold
* Description   : This function configures the High/Low thresholds for the Watchdog monitor.
*
* @implements     Sdadc_Ip_SetWdgThreshold_Activity
* END**************************************************************************/
void Sdadc_Ip_SetWdgThreshold(const uint32 Instance,
                              const uint16 UpperThreshold,
                              const uint16 LowerThreshold)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    /* Configures the high/low thresholds */
    Base->WTHHLR = SDADC_WTHHLR_THRH(UpperThreshold) | SDADC_WTHHLR_THRL(LowerThreshold);
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_EnableWatchdog
* Description   : This function enables the Watchdog monitor.
*
* @implements     Sdadc_Ip_EnableWatchdog_Activity
* END**************************************************************************/
void Sdadc_Ip_EnableWatchdog(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_74();
    /* Enables the WDG monitor */
    Base->MCR |= SDADC_MCR_WDGEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_74();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_DisableWatchdog
* Description   : This function disables the Watchdog monitor.
*
* @implements     Sdadc_Ip_DisableWatchdog_Activity
* END**************************************************************************/
void Sdadc_Ip_DisableWatchdog(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_75();
    /* Disables the WDG monitor */
    Base->MCR &= ~SDADC_MCR_WDGEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_75();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_EnableWraparound
* Description   : This function enables the Wraparound mechanism for conversion of
* programmed sequence of channels
*
* @implements     Sdadc_Ip_EnableWraparound_Activity
* END**************************************************************************/
void Sdadc_Ip_EnableWraparound(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_76();
    /* Enable wrap around mode */
    Base->MCR |= SDADC_MCR_WRMODE_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_76();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_DisableWraparound
* Description   : This function disables the Wraparound mechanism for conversion of
* programmed sequence of channels
*
* @implements     Sdadc_Ip_DisableWraparound_Activity
* END**************************************************************************/
void Sdadc_Ip_DisableWraparound(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_77();
    /* Disable wrap around mode */
    Base->MCR &= ~SDADC_MCR_WRMODE_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_77();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_SetInputChannel
* Description   : This function configures the connectivity of analog inputs to either positive or negative polarity
* terminals of the SDADC. If Wraparound mode is enabled, this function supports to configure
* initial entry value for the first loop of the Wraparound sequence.
*
* @implements     Sdadc_Ip_SetInputChannel_Activity
* END**************************************************************************/
void Sdadc_Ip_SetInputChannel(const uint32 Instance,
                              const Sdadc_Ip_ChannelType Channel)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    /* Extract value from the channel enum */
    const uint32 Mode    = ((uint32)Channel & SDADC_IP_CHANNEL_ENUM_MODE_MASK)    >> SDADC_IP_CHANNEL_ENUM_MODE_SHIFT;
    const uint32 Vcomsel = ((uint32)Channel & SDADC_IP_CHANNEL_ENUM_VCOMSEL_MASK) >> SDADC_IP_CHANNEL_ENUM_VCOMSEL_SHIFT;
    const uint32 Chan    = ((uint32)Channel & SDADC_IP_CHANNEL_ENUM_CHAN_MASK)    >> SDADC_IP_CHANNEL_ENUM_CHAN_SHIFT;

    uint32 RegVal;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_78();
    /* Configures mode and vcom */
    RegVal  = Base->MCR;
    RegVal &= ~(SDADC_MCR_MODE_MASK | SDADC_MCR_VCOMSEL_MASK);
    RegVal |=  SDADC_MCR_MODE(Mode) | SDADC_MCR_VCOMSEL(Vcomsel);
    Base->MCR = RegVal;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_78();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_101();
    /* Configures input channel */
    RegVal  = Base->CSR;
    RegVal &= ~SDADC_CSR_ANCHSEL_MASK;
    RegVal |=  SDADC_CSR_ANCHSEL(Chan);
    Base->CSR = RegVal;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_101();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_FlushFifo
* Description   : This function flushes data FIFO, all data in the FIFO will be erased.
*
* @implements     Sdadc_Ip_FlushFifo_Activity
* END**************************************************************************/
void Sdadc_Ip_FlushFifo(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * Base;
    uint32 Cnt;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    const DSPSS_ThreadConfigType * const DspssConfig = Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig;

    if (NULL_PTR != DspssConfig)
    {
        /* Flush DSPSS output buffer */
        DSPSS_FlushOutputBuffer(Instance, DspssConfig->OutputTransferMethod);
    }
    else
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
    {
        /* Flush SDADC FIFO */
        Base = Sdadc_Ip_apxSdadcBase[Instance];

        if (0U == (Base->MCR & SDADC_MCR_EN_MASK))
        {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_79();
            /* SDADC is disabled, use FIFO Flush Reset */
            Base->FCR |= SDADC_FCR_FRST_MASK;
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_79();
        }
        else
        {
            /* SDADC is enabled, manually remove all data from FIFO */
            /* Loop until the empty flag is set or up to the FIFO size */
            for (Cnt = 0U ; Cnt < SDADC_IP_FIFO_MAX_SIZE; Cnt++)
            {
                if (0U != (Base->SFR & SDADC_SFR_DFEF_MASK))
                {
                    /* FIFO is empty */
                    break;
                }
                /* Dummy read data from FIFO */
                (void)Base->CDR;
            }
        }
    }
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_GetConvData
* Description   : This function retrieves the converted data and writes it in the given data array.
*
* @implements     Sdadc_Ip_GetConvData_Activity
* END**************************************************************************/
uint32 Sdadc_Ip_GetConvData(const uint32 Instance,
                            const uint32 Length,
                            sint16 * const Data)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);
    SDADC_IP_DEV_ASSERT(Data != NULL_PTR);

    const SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    sint32 RawData = 0;
    sint32 RawDataGainErr = 0;
    uint32 FifoStatus;
    uint32 Num;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        /* DSPSS is used, read data from Core buffer */
        Num = DSPSS_CoreBufferRead(Instance, Length, Data);
    }
    else
#endif
    {
        /* DSPSS is not used, read results from SDADC FIFO */
        for (Num = 0U; Num < Length; Num++)
        {
            /* Check the two status flags: FIFO empty and data valid */
            FifoStatus = Base->SFR & (SDADC_SFR_DFEF_MASK | SDADC_SFR_CDVF_MASK);
            if (SDADC_SFR_CDVF_MASK == FifoStatus)
            {
                /* Read raw data from FIFO */
                RawData = (sint16)(uint16)((Base->CDR & SDADC_CDR_CDATA_MASK) >> SDADC_CDR_CDATA_SHIFT);
            }
            else
            {
                /* FIFO is empty or data is invalid */
                break;
            }

            /* The calibrated results is calculated by equation: Dadj = (Dout - OFS) / Gain */
            /* Nullify the offset error in the data conversion */
            RawData = RawData - Sdadc_Ip_as16OffsetErr[Instance];
            /* Nullify the gain error in the data conversion */
            if ((((sint32)MAX_S32 / SDADC_IP_GAIN_ERROR_DIVISION) > RawData) && (((sint32)MIN_S32 / SDADC_IP_GAIN_ERROR_DIVISION) < RawData))
            {
                RawDataGainErr = RawData * SDADC_IP_GAIN_ERROR_DIVISION;
            }
            else if(((sint32)MAX_S32 / SDADC_IP_GAIN_ERROR_DIVISION) < RawData)
            {
                RawDataGainErr = (sint32)MAX_S32;
            }
            else
            {
                RawDataGainErr = (sint32)MIN_S32;
            }

            RawData = RawDataGainErr / Sdadc_Ip_as32GainErr[Instance];

            /* Constraint result */
            if (RawData > SDADC_IP_MAX_CONV_DATA)
            {
                RawData = SDADC_IP_MAX_CONV_DATA;
            }
            else if (RawData < SDADC_IP_MIN_CONV_DATA)
            {
                RawData = SDADC_IP_MIN_CONV_DATA;
            }
            else
            {
                /* Do nothing */
            }

            /* Store to user's buffer */
            Data[Num] = (sint16)RawData;
        }
    }

    return Num;
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_GetRawConvDataFifo
* Description   : This function retrieves the raw (uncalibrated) converted data and writes it in the given data array.
* The data will be consecutive popped out the FIFO until the FIFO is empty or the data array is full,
* so the data array length should be big enough to contain all data
*
* @implements     Sdadc_Ip_GetRawConvDataFifo_Activity
* END**************************************************************************/
uint32 Sdadc_Ip_GetRawConvDataFifo(const uint32 Instance,
                                   const uint32 Length,
                                   sint16 * const Data)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);
    SDADC_IP_DEV_ASSERT(Data != NULL_PTR);
    SDADC_IP_DEV_ASSERT(Length > 0U);

    const SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    uint32 FifoStatus;
    uint32 Num;

    for (Num = 0U; Num < Length; Num++)
    {
        /* Check the two status flags: FIFO empty and data valid */
        FifoStatus = Base->SFR & (SDADC_SFR_DFEF_MASK | SDADC_SFR_CDVF_MASK);
        if (SDADC_SFR_CDVF_MASK == FifoStatus)
        {
            /* Read raw data from FIFO */
            Data[Num] = (sint16)(uint16)((Base->CDR & SDADC_CDR_CDATA_MASK) >> SDADC_CDR_CDATA_SHIFT);
        }
        else
        {
            /* FIFO is empty or data is invalid */
            break;
        }
    }

    return Num;
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_GetStatusFlags
* Description   : This function returns the status flags of the SDADC.
* Bitwise AND the returned value with the SDADC_IP_FLAG_ defines to get a specific status flag.
*
* @implements     Sdadc_Ip_GetStatusFlags_Activity
* END**************************************************************************/
uint32 Sdadc_Ip_GetStatusFlags(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    const SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    /* Read status flags */
    uint32 Flags = Base->SFR & SDADC_IP_FLAG_STATUS_ALL;

    return Flags;
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_ClearStatusFlags
* Description   : This function clears the status flags that are set to '1' in the mask.
* The mask input parameter can be set using SDADC_IP_FLAG_ defines.
*
* @implements     Sdadc_Ip_ClearStatusFlags_Activity
* END**************************************************************************/
void Sdadc_Ip_ClearStatusFlags(const uint32 Instance,
                               const uint32 Mask)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    /* Write-1-to-clear bits in the status register */
    Base->SFR = (Mask & SDADC_IP_FLAG_STATUS_REQUEST);

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        /* Clear the corresponding core buffer OVF flag if DSPSS is being used */
        if ( (Mask & SDADC_IP_FLAG_DATA_FIFO_FULL) != 0U )
        {
            DSPSS_DspCoreBufferOverflowClear(Instance);
        }
    }
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_EnableDmaEvents
* Description   : This function enables SDADC DMA request generation.
*
* @implements     Sdadc_Ip_EnableDmaEvents_Activity
* END**************************************************************************/
void Sdadc_Ip_EnableDmaEvents(const uint32 Instance,
                              const uint32 EventsMask)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    uint32 RserVal = 0U;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (NULL_PTR == Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
    {
        /* Enables Data FIFO Full Request and selects DMA */
        RserVal |= ((EventsMask & SDADC_IP_EVENT_FIFO_FULL)      != 0U) ? (SDADC_RSER_DFFDIRE_MASK | SDADC_RSER_DFFDIRS_MASK) : 0U;

        /* Enables WDG Threshold Cross Over and selects DMA */
        RserVal |= ((EventsMask & SDADC_IP_EVENT_WDOG_CROSSOVER) != 0U) ? (SDADC_RSER_WTHDIRE_MASK | SDADC_RSER_WTHDIRS_MASK) : 0U;

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_80();
        /* Enable DMA generating */
        Base->RSER |= RserVal;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_80();
    }
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_EnableInterruptEvents
* Description   : This function enables SDADC interrupt request generation.
*
* @implements     Sdadc_Ip_EnableInterruptEvents_Activity
* END**************************************************************************/
void Sdadc_Ip_EnableInterruptEvents(const uint32 Instance,
                                    const uint32 EventsMask)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * Base;
    uint32 RserVal;
    uint32 IntEnable = 0U;
    uint32 IntSel    = 0U;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        /* With SDADC_IP_EVENT_FIFO_FULL: The DSPSS core buffer interrupt is enabled by default, nothing to do */
        /* NOTE: current implementation only supports for FIFO Full, other interrupt events are not implemented */
    }
    else
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
    {
        /* Get value RSER register */
        Base    = Sdadc_Ip_apxSdadcBase[Instance];

        /* Enable interrupt */
        IntEnable |= ((EventsMask & SDADC_IP_EVENT_FIFO_FULL)       != 0U) ? SDADC_RSER_DFFDIRE_MASK : 0U;
        IntEnable |= ((EventsMask & SDADC_IP_EVENT_WDOG_CROSSOVER)  != 0U) ? SDADC_RSER_WTHDIRE_MASK : 0U;
        IntEnable |= ((EventsMask & SDADC_IP_EVENT_FIFO_OVERRUN)    != 0U) ? SDADC_RSER_DFORIE_MASK  : 0U;

        /* Select interrupt request */
        IntSel    |= ((EventsMask & SDADC_IP_EVENT_FIFO_FULL)       != 0U) ? SDADC_RSER_DFFDIRS_MASK : 0U;
        IntSel    |= ((EventsMask & SDADC_IP_EVENT_WDOG_CROSSOVER)  != 0U) ? SDADC_RSER_WTHDIRS_MASK : 0U;

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_81();
        RserVal = Base->RSER;
        /* Select interrupt request */
        RserVal &= ~IntSel;
        /* Enable interrupt */
        RserVal |=  IntEnable;
        /* Clear pending interrupt flags - CPR_RTD_01182 */
        Sdadc_Ip_ClearStatusFlags(Instance, SDADC_IP_FLAG_STATUS_REQUEST);
        /* Set again the RSER register */
        Base->RSER = RserVal;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_81();
    }
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_DisableInterruptEvents
* Description   : This function disable SDADC DMA and interrupt request generation
*
* @implements     Sdadc_Ip_DisableInterruptEvents_Activity
* END**************************************************************************/
void Sdadc_Ip_DisableInterruptEvents(const uint32 Instance,
                                     const uint32 EventsMask)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * Base;
    uint32 IntDisable = 0U;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        /* With SDADC_IP_EVENT_FIFO_FULL: The DSPSS core buffer interrupt is disabled when Deinit, nothing to do */
        /* NOTE: current implementation only supports for FIFO Full, other interrupt events are not implemented */
    }
    else
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
    {
        Base = Sdadc_Ip_apxSdadcBase[Instance];

        IntDisable |= ((EventsMask & SDADC_IP_EVENT_FIFO_FULL)      != 0U) ? SDADC_RSER_DFFDIRE_MASK : 0U;
        IntDisable |= ((EventsMask & SDADC_IP_EVENT_WDOG_CROSSOVER) != 0U) ? SDADC_RSER_WTHDIRE_MASK : 0U;
        IntDisable |= ((EventsMask & SDADC_IP_EVENT_FIFO_OVERRUN)   != 0U) ? SDADC_RSER_DFORIE_MASK  : 0U;

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_82();
        /* Disable DMA and interrupt */
        Base->RSER &= ~IntDisable;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_82();
    }
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_DoCalibration
* Description   : This function performs an offset calibration of the SDADC. Offset 
* calibration should be done before using the SDADC module or after the operating conditions
* (particularly Vref, input gain) change significantly.
* The measured gain value is going be used to nullify the gain errors in the data conversion.
* The measured offset is going be used to nullify the offset error in the data conversion.
* The offset calibration must be performed for each input gain changing since it is expected to
* vary with input gain configuration of SDADC.
*
* @implements     Sdadc_Ip_DoCalibration_Activity
* END**************************************************************************/
Sdadc_Ip_StatusType Sdadc_Ip_DoCalibration(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);
    SDADC_IP_DEV_ASSERT(Sdadc_Ip_axSdadcState[Instance].Config != NULL_PTR);

    Sdadc_Ip_StatusType Status;

    /* 1) Perform offset calibration */
    Status = Sdadc_OffsetCalibration(Instance);

    if (SDADC_IP_STATUS_SUCCESS == Status)
    {
        /* 2) Perform gain calibration */
        Status = Sdadc_GainCalibration(Instance);
    }

    return Status;
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_ApplyCalibration
* Description   : This function applies calibration to the uncalibrated converted data
* acquired by DMA or Sdadc_Ip_GetRawConvDataFifo function.
* In the case uncalibrated converted data gathered by DMA, this function should be
* called in the DMA callback.
*
* @implements     Sdadc_Ip_ApplyCalibration_Activity
* END**************************************************************************/
void Sdadc_Ip_ApplyCalibration(const uint32 Instance,
                               const uint32 BufferLength,
                               const sint16 * const UncalibratedBuffer,
                               sint16 * const CalibratedBuffer)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);
    SDADC_IP_DEV_ASSERT(UncalibratedBuffer != NULL_PTR);
    SDADC_IP_DEV_ASSERT(CalibratedBuffer   != NULL_PTR);

    sint32 Dadj;
    uint32 Index;
    sint32 DadjGerr;
    for (Index = 0; Index < BufferLength; Index++)
    {
        /* Data calculation after gain and offset calibration: Dadj = (Dout - OFS) / Gain */
        Dadj = (sint16)UncalibratedBuffer[Index];

        /* 1) Nullify the offset error in the data conversion */
        Dadj = Dadj - Sdadc_Ip_as16OffsetErr[Instance];
        /* 2) Nullify the gain error in the data conversion */
        if ((((sint32)MAX_S32 / SDADC_IP_GAIN_ERROR_DIVISION) > Dadj) && (((sint32)MIN_S32 / SDADC_IP_GAIN_ERROR_DIVISION) < Dadj))
        {
            DadjGerr = Dadj * SDADC_IP_GAIN_ERROR_DIVISION;
        }
        else if(((sint32)MAX_S32 / SDADC_IP_GAIN_ERROR_DIVISION) < Dadj)
        {
            DadjGerr = (sint32)MAX_S32;
        }
        else
        {
            DadjGerr = (sint32)MIN_S32;
        }

        Dadj = DadjGerr / Sdadc_Ip_as32GainErr[Instance];
        /* Constraint result */
        if (Dadj > SDADC_IP_MAX_CONV_DATA)
        {
            Dadj = SDADC_IP_MAX_CONV_DATA;
        }
        else if (Dadj < SDADC_IP_MIN_CONV_DATA)
        {
            Dadj = SDADC_IP_MIN_CONV_DATA;
        }
        else
        {
            /* Do nothing */
        }

        CalibratedBuffer[Index] = (sint16)Dadj;
    }
}


/*FUNCTION*********************************************************************
 *
 * Function Name : Sdadc_Ip_SetUserGainAndOffset
 * Description   : This function applies user gain and offset
 *
* @implements     Sdadc_Ip_SetUserGainAndOffset_Activity
 *END*************************************************************************/
void Sdadc_Ip_SetUserGainAndOffset(const uint32 Instance,
                                   const sint32 Gain,
                                   const sint32 Offset)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    DSPSS_CFSDADC_CalibParamsType CalibrationParams;

    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        if ( (0 == Gain) && (0 == Offset) )
        {
            CalibrationParams.UseCalibration = 0;  /* calibration disabled */
        }
        else
        {
            CalibrationParams.UseCalibration = 1;  /* calibration enabled */
        }
        CalibrationParams.Gain   = (sint16)Gain;
        CalibrationParams.Offset = Offset;
        /* Set calibration parameters */
        (void)DSPSS_ThreadsCalibrationSet(Instance, &CalibrationParams);
    }
    else
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
    {
        /* Set gain error and offset variables to user value */
        Sdadc_Ip_as32GainErr[Instance]   = Gain;
        Sdadc_Ip_as16OffsetErr[Instance] = (sint16)Offset;
    }

}

/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_EnableHwTrigger
* Description   : This function enables the hardware trigger functionality
*
* @implements     Sdadc_Ip_EnableHwTrigger_Activity
* END**************************************************************************/
void Sdadc_Ip_EnableHwTrigger(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    /* Enable the thread if configured */
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        DSPSS_ThreadEnable(Instance);
    }
#endif

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_83();
    /* Enables the hardware trigger */
    Base->MCR |= SDADC_MCR_TRIGEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_83();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_DisableHwTrigger
* Description   : This function disables the hardware trigger functionality
*
* @implements     Sdadc_Ip_DisableHwTrigger_Activity
* END**************************************************************************/
void Sdadc_Ip_DisableHwTrigger(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_84();
    /* Disables the hardware trigger */
    Base->MCR &= ~SDADC_MCR_TRIGEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_84();
}


/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Ip_SetHwTrigger
* Description   : This function configures the input used for hardware-triggered conversions.
*
* @implements     Sdadc_Ip_SetHwTrigger_Activity
* END**************************************************************************/
void Sdadc_Ip_SetHwTrigger(const uint32 Instance,
                           const Sdadc_Ip_TriggerEdgeType TriggerEdge,
                           const Sdadc_Ip_TriggerSelectType TriggerSrc)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_85();
    uint32 RegVal = Base->MCR;
    /* Set the hardware trigger input value */
    RegVal &= ~(SDADC_MCR_TRIGEDSEL_MASK         | SDADC_MCR_TRIGSEL_MASK);
    RegVal |=  (SDADC_MCR_TRIGEDSEL(TriggerEdge) | SDADC_MCR_TRIGSEL(TriggerSrc));
    Base->MCR = RegVal;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_85();
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sdadc_Ip_GetDataAddress
 * Description   : This function returns the address where the converted data will be stored.
 *
 * @implements     Sdadc_Ip_GetDataAddress_Activity
 * END**************************************************************************/
uint32 Sdadc_Ip_GetDataAddress(const uint32 Instance)
{
    SDADC_IP_DEV_ASSERT(Instance < SDADC_INSTANCE_COUNT);

    const SDADC_Type * const Base = Sdadc_Ip_apxSdadcBase[Instance];
    uint32 DataAddress;

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
    if (NULL_PTR != Sdadc_Ip_axSdadcState[Instance].Config->DspssConfig)
    {
        /* Get DSPSS output buffer start address from XMEM */
        DataAddress = DSPSS_ThreadGetOutputBufferStart(Instance);
    }
    else
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */
    {
        /* Get the address of SDADC FIFO register */
        DataAddress = (uint32)&(Base->CDR);
    }

    return DataAddress;
}


/*FUNCTION*********************************************************************
 *
 * Function Name : SDADC_Ip_IRQHandler
 * Description   : Handles Adc Sar interrupts
 *
 * @implements     SDADC_Ip_IRQHandler_Activity
 *END*************************************************************************/
void Sdadc_Ip_IRQHandler(void)
{
    SDADC_Type * Base;
    const Sdadc_Ip_StateStructType * State;
    uint32 IsrRequests;
    uint32 IsrFlags;
    uint32 IsrFlagsToBeCleared;
    uint32 Instance;

    /* Loop to find the instances which raised the interrupt event, because multiple SDADC instances use the same IRQ number */
    for (Instance = 0U; Instance < SDADC_INSTANCE_COUNT; Instance++)
    {
        Base = Sdadc_Ip_apxSdadcBase[Instance];
        IsrFlags = Base->SFR & SDADC_IP_FLAG_STATUS_REQUEST;  /* Get only the request flags of this instance */
        if (0U == IsrFlags)
        {
            /* If no request flags were set, meaning that the interrupt event was not from this instance */
            continue;
        }

        /* Check whether the respective driver is initialized */
        State = &(Sdadc_Ip_axSdadcState[Instance]);
        if (State->Config != NULL_PTR)
        {
            /* CPR_RTD_00664
               Check which interrupt was triggered and not spurious (request was enabled, type is interrupt and flag was set)
               Clear it and call the associated callback
             */
            IsrRequests = Base->RSER;
            IsrFlagsToBeCleared = 0U;

            /* FIFO full interrupt (request type is interrupt and the FIFO full flag was set) */
            if ( (SDADC_RSER_DFFDIRE_MASK == (IsrRequests & (SDADC_RSER_DFFDIRE_MASK | SDADC_RSER_DFFDIRS_MASK))) &&
                 ((IsrFlags & SDADC_SFR_DFFF_MASK) != 0U)
               )
            {
                IsrFlagsToBeCleared |= SDADC_SFR_DFFF_MASK;
                Sdadc_CheckAndCallNotification( State->Config->FifoFullNotification );
            }

            /* FIFO overrun interrupt */
            if ( ((IsrRequests & SDADC_RSER_DFORIE_MASK) != 0U) &&
                 ((IsrFlags    & SDADC_SFR_DFORF_MASK  ) != 0U)
               )
            {
                IsrFlagsToBeCleared |= SDADC_SFR_DFORF_MASK;
                Sdadc_CheckAndCallNotification( State->Config->FifoOverrunNotification );
            }

            /* Wdg cross over interrupt (request type is interrupt and one of the threshold flags was set) */
            if ( (SDADC_RSER_WTHDIRE_MASK == (IsrRequests & (SDADC_RSER_WTHDIRE_MASK | SDADC_RSER_WTHDIRS_MASK))) &&
                 ((IsrFlags & (SDADC_SFR_WTHH_MASK | SDADC_SFR_WTHL_MASK)) != 0U)
               )
            {
                IsrFlagsToBeCleared |= (IsrFlags & (SDADC_SFR_WTHH_MASK | SDADC_SFR_WTHL_MASK));
                Sdadc_CheckAndCallWdgNotification(Instance, IsrFlags);
            }
        }
        else
        {
            /* CPR_RTD_00011 */
            IsrFlagsToBeCleared = IsrFlags;
        }

        /* Clear interrupt flags (W1C) */
        Base->SFR = IsrFlagsToBeCleared;
    }
}


#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/*FUNCTION*********************************************************************
 *
 * Function Name : Dspss_IRQHandler
 * Description   : Handles Dspss interrupts
 *
 * @implements     Dspss_IRQHandler_Activity
 *END*************************************************************************/
void Dspss_IRQHandler(const uint32 Thread)
{
    const Sdadc_Ip_StateStructType * const State = &(Sdadc_Ip_axSdadcState[Thread]);
    const uint32 IsrFlags      = IP_DSPSS_0->DSPSS_DSP_IO_INTF0;  /* DSP Trigger to Core status flags */
    uint32 IsrFlagsToBeCleared = 0UL;

    /* Check whether the respective driver is initialized */
    if (State->Config != NULL_PTR)
    {
        /* CPR_RTD_00664
           Check which interrupt was triggered and not spurious (interrupt was enabled and flag was set)
           Clear it and call the associated callback
         */
        if ((IsrFlags & ((uint32)DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_MASK << Thread)) != 0U)
        {
            IsrFlagsToBeCleared = (uint32)DSPSS_DSPSS_DSP_IO_INTF0_DSP_TRIGGER_CORE_TH0_MASK << Thread;
            Sdadc_CheckAndCallNotification(State->Config->FifoFullNotification);
        }
    }
    else
    {
        /* CPR_RTD_00011 */
        IsrFlagsToBeCleared = IsrFlags;
    }

    /* Clear interrupt flags (W1C) */
    IP_DSPSS_0->DSPSS_DSP_IO_INTF0 = IsrFlagsToBeCleared;
}

#if (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON)
/*FUNCTION*********************************************************************
 *
 * Function Name : Dspss_ErrorIRQHandler
 * Description   : Handles Dspss error interrupts
 *
 * @implements     Dspss_ErrorIRQHandler_Activity
 *END*************************************************************************/
void Dspss_ErrorIRQHandler(void)
{
    const Sdadc_Ip_StateStructType * State;
    uint32 IsrFlags;
    uint32 IsrEnabled;
    uint32 IsrFlagsToBeCleared;
    uint32 Thread;

    /* Loop to find the threads which raised the interrupt event, because multiple DSPSS threads use the same IRQ number */
    for (Thread = 0U; Thread < DSPSS_THREAD_NUM; Thread++)
    {
        IsrFlags = DSPSS_GetStatusFlags(Thread);
        State = &(Sdadc_Ip_axSdadcState[Thread]);

        /* Check whether the respective driver is initialized */
        if (State->Config != NULL_PTR)
        {
            IsrFlagsToBeCleared = 0U;
            IsrEnabled = DSPSS_GetInterruptEnable(Thread);

            /* CPR_RTD_00664
               Check which interrupt was triggered and not spurious (interrupt was enabled and flag was set)
               Clear it and call the associated callback
             */
            if ((IsrEnabled & IsrFlags) != 0U)
            {
                IsrFlagsToBeCleared = IsrEnabled & IsrFlags;
                /* Call notification */
                if (State->Config->DspssConfig->ErrorNotification != NULL_PTR)
                {
                    State->Config->DspssConfig->ErrorNotification(IsrFlagsToBeCleared);
                }
            }
        }
        else
        {
            /* CPR_RTD_00011: If the driver is not initialized, the ISR shall only clear interrupt status flag and return immediately */
            IsrFlagsToBeCleared = IsrFlags;
        }

        if (IsrFlagsToBeCleared != 0U)
        {
            DSPSS_ClearStatusFlags(Thread, IsrFlagsToBeCleared);
        }
    }
}
#endif /* (SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED == STD_ON) */

#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


#endif /* FEATURE_ADC_HAS_SDADC */


#ifdef __cplusplus
}
#endif

/** @} */
