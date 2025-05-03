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
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
* only be used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef LPI2C_IP_CFGDEFINES_H
#define LPI2C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup LPI2C_DRIVER_CONFIGURATION LPI2C Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32K344_LPI2C.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_CFGDEFINES_VENDOR_ID                       43
#define LPI2C_IP_CFGDEFINES_MODULE_ID                       255
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION        7
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION     0
#define LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION                5
#define LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION                0
#define LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/**
* @brief            Unified Interrupt.
*/
#define LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE
/**
* @brief            Development error detection for IP layer
*/
#define LPI2C_IP_DEV_ERROR_DETECT   (STD_ON)

/**
* @brief            Event error detection for IP layer
*/
#define LPI2C_IP_EVENT_ERROR_DETECT   (STD_OFF)

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define LPI2C_IP_DMA_TRANSFER_ERROR_DETECT   (STD_OFF)

/**
* @brief            Dma support enable/disabled
*/
#define LPI2C_IP_DMA_FEATURE_AVAILABLE    (STD_OFF)

/**
* @brief            LPI2C timeout type
*/
#define I2C_TIMEOUT_TYPE    (OSIF_COUNTER_DUMMY)

/**
* @brief            The offset value will start with the first Lpi2c instance of the hardware
*/
#define LPI2C_IP_OFFSET_INSTANCE                (0U)



/**
* @brief   Lpi2c Support High-speed mode for Controller.
*/
#define LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE          (STD_OFF)

/*
* @brief   ERR052121: LPI2C: NACK Detect Flag can be set when IGNACK=1.
*/
#define ERRATA_ERR052121          (STD_OFF)

/*==================================================================================================
*                                       LOCAL MACROS
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

#endif /* LPI2C_IP_CFGDEFINES_H */


