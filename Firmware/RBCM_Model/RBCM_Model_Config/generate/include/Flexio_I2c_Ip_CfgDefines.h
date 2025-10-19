/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_I2C_IP_CFGDEFINES_H
#define FLEXIO_I2C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup FLEXIO_I2C_DRIVER_CONFIGURATION Flexio_I2c Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32K344_FLEXIO.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_CFGDEFINES_VENDOR_ID                     43
#define FLEXIO_I2C_IP_CFGDEFINES_MODULE_ID                     255
#define FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_I2C_IP_CFGDEFINES_SW_MAJOR_VERSION              5
#define FLEXIO_I2C_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define FLEXIO_I2C_IP_CFGDEFINES_SW_PATCH_VERSION              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* @brief            Dma optimize of the i2c module enable/disabled
*/
#define FLEXIO_I2C_IP_DMA_OPTIMIZE_ENABLE   (STD_OFF)
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"
/* Macros that indicate FLEXIO channels used by I2C */

#ifndef FLEXIO_0_CH_2_USED
    #define FLEXIO_0_CH_2_USED
#else
    #error "CHANNEL_2 cannot be used by I2C driver. Channel locked by another driver"
#endif

#ifdef FLEXIO_0_CH_2_USED
    #define I2C_CHANNEL_2_USED
#else
    #error "CHANNEL_2 cannot be used by I2C driver. Channel locked by another driver"
#endif

#ifndef FLEXIO_0_CH_3_USED
    #define FLEXIO_0_CH_3_USED
#else
    #error "CHANNEL_3 cannot be used by I2C driver. Channel locked by another driver"
#endif

#ifdef FLEXIO_0_CH_3_USED
    #define I2C_CHANNEL_3_USED
#else
    #error "CHANNEL_3 cannot be used by I2C driver. Channel locked by another driver"
#endif

/*Macros that indicate FLEXIO pins used by I2C */

#ifndef FLEXIO_0_PIN_10_USED
    #define FLEXIO_0_PIN_10_USED
#else
    #error "PIN_10 cannot be used by I2C driver. Pin used by another driver!"
#endif

#ifndef FLEXIO_0_PIN_11_USED
    #define FLEXIO_0_PIN_11_USED
#else
    #error "PIN_11 cannot be used by I2C driver. Pin used by another driver!"
#endif

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2C_IP_CFGDEFINES_H */

