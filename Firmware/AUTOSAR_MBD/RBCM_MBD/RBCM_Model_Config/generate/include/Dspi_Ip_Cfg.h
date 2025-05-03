/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
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

#ifndef DSPI_IP_CFG_H
#define DSPI_IP_CFG_H

/**
*   @file    Dspi_Ip_Cfg.h
*   @version 5.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup DSPI_IP_DRIVER_CONFIGURATION Dspi Ip Driver Configuration
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"
#include "Dspi_Ip_MBDT_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_IP_VENDOR_ID_CFG                       43
#define DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define DSPI_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define DSPI_IP_SW_MAJOR_VERSION_CFG                5
#define DSPI_IP_SW_MINOR_VERSION_CFG                0
#define DSPI_IP_SW_PATCH_VERSION_CFG                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dspi_Ip_Cfg.h and Mcal.h are different"
    #endif

    /* Check if the current file and OsIf.h header file are of the same version */
    #if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Dspi_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif
/* Check if Dspi_Ip_MBDT_PBcfg header file and Spi configuration header file are of the same vendor */
#if (DSPI_IP_MBDT_VENDOR_ID_PBCFG != DSPI_IP_VENDOR_ID_CFG)
    #error "Dspi_Ip_MBDT_PBcfg.h and Dspi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Dspi_Ip_MBDT_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((DSPI_IP_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG != DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DSPI_IP_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG != DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DSPI_IP_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG != DSPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Dspi_Ip_MBDT_PBcfg.h and Dspi_Ip_Cfg.h are different"
#endif
/* Check if Dspi_Ip_MBDT_PBcfg header file and Spi configuration header file are of the same software version */
#if ((DSPI_IP_MBDT_SW_MAJOR_VERSION_PBCFG != DSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (DSPI_IP_MBDT_SW_MINOR_VERSION_PBCFG != DSPI_IP_SW_MINOR_VERSION_CFG) || \
     (DSPI_IP_MBDT_SW_PATCH_VERSION_PBCFG != DSPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Dspi_Ip_MBDT_PBcfg.h and Dspi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                            CONSTANTS
==================================================================================================*/
/**
* @brief DSPI support
*/
/** @implements DSPI_IP_ENABLE_define  */
#define DSPI_IP_ENABLE      (STD_OFF)
#define DSPI_IP_DMA_USED    (STD_OFF)
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
#endif

/** @} */

