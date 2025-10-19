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

#ifndef ADC_SAR_IP_HW_ACCESS_H
#define ADC_SAR_IP_HW_ACCESS_H

/**
*   @file
*
*   @internal
*   @addtogroup adc_sar_ip Adc Sar IPL
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
#include "Std_Types.h"
#include "Adc_Sar_Ip_CfgDefines.h"

#if (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif /* (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_HWACCESS                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HWACCESS    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_HWACCESS               5
#define ADC_SAR_IP_SW_MINOR_VERSION_HWACCESS               0
#define ADC_SAR_IP_SW_PATCH_VERSION_HWACCESS               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_HwAccess.h file and Adc_Sar_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_HWACCESS != ADC_SAR_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Sar_Ip_HwAccess.h and Adc_Sar_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_HwAccess.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HWACCESS != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Sar_Ip_HwAccess.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_HWACCESS != ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_HWACCESS != ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_HWACCESS != ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_HwAccess.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Sar_Ip_HwAccess.h file and Std_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and Std_Types.h are different"
#endif

#if (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON)
/* Check if Adc_Sar_Ip_HwAccess.h and Devassert.h are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_HwAccess.h and Devassert.h are different"
#endif
#endif /* (ADC_SAR_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Define the hardware register size when calculating bit positions */
#define ADC_SAR_IP_HW_REG_SIZE (32u)

/* Definitions to compute bit positions from channel index */
#define ADC_SAR_IP_CHAN_2_VECT(CHNIDX) ((CHNIDX) / ADC_SAR_IP_HW_REG_SIZE)
#define ADC_SAR_IP_CHAN_2_BIT(CHNIDX)  ((CHNIDX) % ADC_SAR_IP_HW_REG_SIZE)
/*==================================================================================================
                                     FUNCTION DEFINITIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Sar_EnableHighSpeed
 * Description   : Enable a high-speed calibration or a high-speed conversion
 *
 *END*************************************************************************/
static inline void Adc_Sar_EnableHighSpeed(ADC_Type * const Base,
                                           boolean Enable)
{
    uint32 Amsio = Base->AMSIO;

    Amsio &= ~(ADC_AMSIO_HSEN_MASK | ADC_AMSIO_CMPCTRL0_MASK);
    if (TRUE == Enable)
    {
        Amsio |= (ADC_AMSIO_HSEN(1u) | ADC_AMSIO_CMPCTRL0(1u));
    }

    Base->AMSIO = Amsio;
}
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_HW_ACCESS_H */
