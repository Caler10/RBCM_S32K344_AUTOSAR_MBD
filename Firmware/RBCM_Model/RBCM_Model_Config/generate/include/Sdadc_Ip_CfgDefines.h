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

#ifndef SDADC_IP_CFGDEFINES_H
#define SDADC_IP_CFGDEFINES_H

/**
*   @file Sdadc_Ip_CfgDefines.h
*
*   @addtogroup sd_adc_ip Sd Adc IPL
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
==================================================================================================*/
#include "OsIf.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SDADC_IP_VENDOR_ID_CFGDEFINES                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES    0
#define SDADC_IP_SW_MAJOR_VERSION_CFGDEFINES               5
#define SDADC_IP_SW_MINOR_VERSION_CFGDEFINES               0
#define SDADC_IP_SW_PATCH_VERSION_CFGDEFINES               0
/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check AutoSar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/

/**
* @brief           Macro to guard for DSPSS of SDADC, which uses DSPSS or not.
*/
#define SDADC_IP_DSPSS_ENABLED                           (STD_OFF)
/**
* @brief           Macro to guard for DSPSS Error Notification Capability.
*/
#define SDADC_IP_DSPSS_ERROR_NOTIFICATION_ENABLED        (STD_OFF)

/* Use "volatile" to prevent compiler from optimizing or reordering accesses which leads to hardfault */
#define SDADC_IP_DSPSS_INIT_DSTADDR_QUALIFIER             volatile



#ifdef FEATURE_ADC_HAS_SDADC


/* Pre-processor switch to enable/disable development error detection */
#define SDADC_IP_DEV_ASSERT(x)                             

/* OsIf counter type used in timeout detection for SDADC operations  */
#define SDADC_IP_TIMEOUT_TYPE                              (OSIF_COUNTER_DUMMY)
/* Timeout value for SDADC operations */
#define SDADC_IP_TIMEOUT_VAL                               (3000UL)


/* Default gain error value */
#define SDADC_IP_GAIN_ERROR_DEFAULT                        (65536)

#define SDADC_IP_GAIN_ERRORS                               {SDADC_IP_GAIN_ERROR_DEFAULT, \
                                                            SDADC_IP_GAIN_ERROR_DEFAULT, \
                                                            SDADC_IP_GAIN_ERROR_DEFAULT, \
                                                            SDADC_IP_GAIN_ERROR_DEFAULT}

/* Gain division value, used when applying gain calibration into raw data */
#define SDADC_IP_GAIN_ERROR_DIVISION                       (65536)

/* Default offset error value */
#define SDADC_IP_OFFSET_ERROR_DEFAULT                      (0)


/* The max of signed 16-bit conversion data, it is (2 ^ 15) - 1 */
#define SDADC_IP_MAX_CONV_DATA                             (+32767)
/* The min of signed 16-bit conversion data, it is -(2 ^ 15) */
#define SDADC_IP_MIN_CONV_DATA                             (-32768)


/* Maximum number of converted datawords that can be stored in the data FIFO */
#define SDADC_IP_FIFO_MAX_SIZE                             (16U)

/*! @brief Number of Threshold register of SDADC */
#define SDADC_IP_NUM_OF_THRESHOLD_REG                      (1U)

/**
 * Enumeration identifying the different threads.
 */

#endif  /* FEATURE_ADC_HAS_SDADC */


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


/** @} */

#endif /* SDADC_IP_CFGDEFINES_H */
