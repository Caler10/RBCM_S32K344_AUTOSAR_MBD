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
#ifndef FLEXIO_I2C_IP_CALLBACKS_H
#define FLEXIO_I2C_IP_CALLBACKS_H

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
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_CALLBACKS_VENDOR_ID                      43
#define FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_I2C_IP_CALLBACKS_SW_MAJOR_VERSION               5
#define FLEXIO_I2C_IP_CALLBACKS_SW_MINOR_VERSION               0
#define FLEXIO_I2C_IP_CALLBACKS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Mcal.h header file are of the same Autosar version */
        #if ( (FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
              (FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Flexio_I2c_Ip_Callbacks.h and Mcal.h are different"
        #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 /**
 * @brief Define the enum of the events which can trigger I2C master callback
 *
 * This enum should include the events for all platforms
 *
 */
 /* implements Flexio_I2c_Ip_MasterEventType_enum */
typedef enum
{
    FLEXIO_I2C_MASTER_EVENT_NACK                              = 0x08U,
    FLEXIO_I2C_MASTER_EVENT_ARBITRATION_LOST                  = 0x09U,
    FLEXIO_I2C_MASTER_EVENT_ERROR_FIFO                        = 0x0AU,
    FLEXIO_I2C_MASTER_EVENT_END_TRANSFER                      = 0x0BU,
    FLEXIO_I2C_MASTER_EVENT_PIN_LOW_TIMEOUT                   = 0x0CU,
    FLEXIO_I2C_MASTER_EVENT_DMA_TRANSFER_ERROR                = 0x0DU
}Flexio_I2c_Ip_MasterEventType;

/* Callback for all peripherals which supports I2C features for master mode */
/* implements Flexio_I2c_Ip_MasterCallbackType_typedef */
typedef void (*Flexio_I2c_Ip_MasterCallbackType)(Flexio_I2c_Ip_MasterEventType Event, uint8 UserData);


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* FLEXIO_I2C_IP_CALLBACKS_H */

