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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
*   only be used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef LPI2C_IP_CALLBACKS_H
#define LPI2C_IP_CALLBACKS_H

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_CALLBACKS_VENDOR_ID                      43
#define LPI2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION       4
#define LPI2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION       7
#define LPI2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION    0
#define LPI2C_IP_CALLBACKS_SW_MAJOR_VERSION               5
#define LPI2C_IP_CALLBACKS_SW_MINOR_VERSION               0
#define LPI2C_IP_CALLBACKS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ( (LPI2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
          (LPI2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Lpi2c_Ip_Callbacks.h and Mcal.h are different"
    #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

 /**
 * @brief Define the enum of the events which can trigger I2C slave callback
 *
 * This enum should include the events for all platforms
 * implements Lpi2c_Ip_SlaveEventType_enum
 */
typedef enum
{
    I2C_SLAVE_EVENT_ERROR_BIT = 0x00U,
    I2C_SLAVE_EVENT_UNDERRUN = 0x01U,
    I2C_SLAVE_EVENT_OVERRUN = 0x02U,
    I2C_SLAVE_EVENT_RX_FULL = 0x03U,
    I2C_SLAVE_EVENT_TX_EMPTY = 0x04U,
    I2C_SLAVE_EVENT_TX_REQ = 0x05U,
    I2C_SLAVE_EVENT_RX_REQ = 0x06U,
    I2C_SLAVE_EVENT_STOP = 0x07U,
    I2C_SLAVE_EVENT_DMA_TRANSFER_ERROR = 0x0EU
}Lpi2c_Ip_SlaveEventType;

 /**
 * @brief Define the enum of the events which can trigger I2C master callback
 *
 * This enum should include the events for all platforms
 * implements Lpi2c_Ip_MasterEventType_enum
 */
typedef enum
{
    I2C_MASTER_EVENT_NACK                              = 0x08U,
    I2C_MASTER_EVENT_ARBITRATION_LOST                  = 0x09U,
    I2C_MASTER_EVENT_ERROR_FIFO                        = 0x0AU,
    I2C_MASTER_EVENT_END_TRANSFER                      = 0x0BU,
    I2C_MASTER_EVENT_PIN_LOW_TIMEOUT                   = 0x0CU,
    I2C_MASTER_EVENT_DMA_TRANSFER_ERROR                = 0x0DU,
#ifdef LPI2C_IP_FEATURE_DETECT_START_CONDITION
    I2C_MASTER_EVENT_START                             = 0x0FU
#endif /* LPI2C_IP_FEATURE_DETECT_START_CONDITION */
} Lpi2c_Ip_MasterEventType;


/* Callback for all peripherals which supports I2C features for slave mode */
/* implements Lpi2c_Ip_SlaveCallbackType_typedef */
typedef void (*Lpi2c_Ip_SlaveCallbackType)(Lpi2c_Ip_SlaveEventType Event, uint8 UserData);

/* Callback for all peripherals which supports I2C features for master mode */
/* implements Lpi2c_Ip_MasterCallbackType_typedef */
typedef void (*Lpi2c_Ip_MasterCallbackType)(Lpi2c_Ip_MasterEventType Event, uint8 UserData);

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* LPI2C_IP_CALLBACKS_H */

