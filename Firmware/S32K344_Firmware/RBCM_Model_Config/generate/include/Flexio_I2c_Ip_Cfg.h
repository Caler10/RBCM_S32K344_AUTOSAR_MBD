
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

#ifndef FLEXIO_I2C_IP_CFG_H
#define FLEXIO_I2C_IP_CFG_H

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
#include "Flexio_I2c_Ip_MBDT_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_CFG_VENDOR_ID                     43
#define FLEXIO_I2C_IP_CFG_MODULE_ID                     255
#define FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION              5
#define FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION              0
#define FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Flexio_I2c_Ip_MBDT_PBcfg.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_CFG_VENDOR_ID != FLEXIO_I2C_IP_MBDT_PBCFG_VENDOR_ID)
    #error "Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_MBDT_PBcfg.h have different vendor IDs"
#endif
/* Check if current file and Flexio_I2c_Ip_MBDT_PBcfg.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXIO_I2C_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXIO_I2C_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_MBDT_PBcfg.h are different"
#endif
/* Check if current file and Flexio_I2c_Ip_MBDT_PBcfg.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION != FLEXIO_I2C_IP_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION != FLEXIO_I2C_IP_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION != FLEXIO_I2C_IP_MBDT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_MBDT_PBcfg.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/**
* @brief          FLEXIO Channel Used
*/
#define FLEXIO_I2C_IP_ENABLE  (STD_ON)
#if (FLEXIO_I2C_IP_ENABLE == STD_ON)
#define  FLEXIO_I2C_IP_MAX(a, b)          (((a) > (b)) ? (a) : (b))
#define FLEXIO_I2C_IP_NUMBER_OF_MASTER_CHANNEL \
    FLEXIO_I2C_IP_MAX(FLEXIO_I2C_IP_NUM_MASTER_USED_MBDT, \
    0 )

#define FLEXIO_I2C_COMMON_IRQ_MASTER_AND_SLAVE
/**
* @brief            Development error detection for IP layer
*/
#define FLEXIO_I2C_IP_DEV_ERROR_DETECT   (STD_ON)

/**
* @brief            Event error detection for IP layer
*/
#define FLEXIO_I2C_IP_EVENT_ERROR_DETECT   (STD_OFF)

/**
* @brief            Dma support enable/disabled
*/
#define FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE    (STD_OFF)

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT   (STD_OFF)

/**
* @brief            FLEXIO timeout type
*/
#define FLEXIO_I2C_IP_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#endif /* FLEXIO_I2C_IP_ENABLE == STD_ON */

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

#endif /* FLEXIO_I2C_IP_CFG_H */


