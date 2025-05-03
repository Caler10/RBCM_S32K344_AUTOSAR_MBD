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

#ifndef FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_H
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Flexio_I2c_Ip_TrustedFunctions.h
*   
*
*   @brief   FLEXIO I2C IP driver header file.
*   @details FLEXIO I2C IP driver header file.

*   @addtogroup FLEXIO_I2C_DRIVER Flexio I2c Driver
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
#include "Flexio_I2c_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                5
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_I2c_Ip_TrustedFunctions.h header file and Flexio_I2c_Ip_Cfg.h configuration header file are of the same vendor */
#if (FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FLEXIO_I2C_IP_CFG_VENDOR_ID)
    #error "Flexio_I2c_Ip_TrustedFunctions.h and Flexio_I2c_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Flexio_I2c_Ip_TrustedFunctions.h header file and Flexio_I2c_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Flexio_I2c_Ip_TrustedFunctions.h and Flexio_I2c_Ip_Cfg.h are different"
#endif
/* Check if Flexio_I2c_Ip_TrustedFunctions.h header file and Flexio_I2c_Ip_Cfg.h configuration header file are of the same software version */
#if ((FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Flexio_I2c_Ip_TrustedFunctions.h and Flexio_I2c_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*!
 * @name FLEXIO_I2C Driver
 * @{
 */
 
#if (STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE)
/**
* @brief            Starts a flexio i2c ip master DMA transfer
* @details          Starts a flexio i2c ip master DMA transfer
*
* @param[in]        Instance - I2C peripheral instance number.
*
* @return           void.
*/
extern void Flexio_I2c_Ip_MasterEndDmaTransfer(uint8 Instance,
                                               uint8 Channel,
                                               boolean Receive);

#if (STD_ON == FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT)
 /**
* @brief            Starts a flexio i2c ip master DMA transfer error handler
* @details          Starts a flexio i2c ip master DMA transfer error handler
*
* @param[in]        Instance - I2C peripheral instance number.
*
* @return           void.
*/
extern void Flexio_I2c_Ip_MasterDmaTransferErrorHandler(uint8 Instance,
                                                        uint8 Channel);
#endif
#endif /* STD_ON == FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FLEXIO_I2C_IP_TRUSTEDFUNCTIONS_H */

/** @} */

