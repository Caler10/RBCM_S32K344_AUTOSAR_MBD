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

#ifndef LPI2C_IP_TRUSTEDFUNCTIONS_H
#define LPI2C_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Lpi2c_Ip_TrustedFunctions.h
*   
*
*   @brief   LPI2C IP driver header file.
*   @details LPI2C IP driver header file.

*   @addtogroup LPI2C_DRIVER LPI2C Driver
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
#include "Lpi2c_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define LPI2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define LPI2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define LPI2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define LPI2C_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                5
#define LPI2C_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define LPI2C_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lpi2c_Ip_CfgDefines.h header file are of the same vendor */
#if (LPI2C_IP_TRUSTEDFUNCTIONS_VENDOR_ID != LPI2C_IP_CFGDEFINES_VENDOR_ID)
    #error "Lpi2c_Ip_TrustedFunctions.h and Lpi2c_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and Lpi2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((LPI2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_TrustedFunctions.h and Lpi2c_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Lpi2c_Ip_CfgDefines.h header file are of the same Software version */
#if ((LPI2C_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (LPI2C_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (LPI2C_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_TrustedFunctions.h and Lpi2c_Ip_CfgDefines.h are different"
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
 
#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
/**
* @brief            Starts a lpi2c ip master DMA transfer
* @details          Starts a lpi2c ip master DMA transfer
*
* @param[in]        Instance - I2C peripheral instance number.
*
* @return           void.
*/
extern void Lpi2c_Ip_MasterCompleteDMATransfer(uint8 Instance);

#if (STD_ON == LPI2C_IP_DMA_TRANSFER_ERROR_DETECT)
 /**
* @brief            Starts a lpi2c ip master DMA transfer error handler
* @details          Starts a lpi2c ip master DMA transfer error handler
*
* @param[in]        Instance - I2C peripheral instance number.
*
* @return           void.
*/                                             
extern void Lpi2c_Ip_MasterDMATransferErrorHandler(uint8 Instance);
                                          
#endif
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* LPI2C_IP_TRUSTEDFUNCTIONS_H */

/** @} */

