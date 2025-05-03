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
#ifndef SPI_IPW_MBDT_PBCFG_H
#define SPI_IPW_MBDT_PBCFG_H

/**
*   @file    Spi_Ipw_MBDT_PBcfg.h
*   @version 5.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the extern declaration for SPI
*            module configuration(s).
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
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
* 4) user callback header files
==================================================================================================*/
#include "Spi_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID_MBDT_PBCFG_H                    43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H     4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H     7
#define SPI_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H  0
#define SPI_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_H             5
#define SPI_IPW_SW_MINOR_VERSION_MBDT_PBCFG_H             0
#define SPI_IPW_SW_PATCH_VERSION_MBDT_PBCFG_H             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi_Ipw.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_MBDT_PBCFG_H != SPI_IPW_VENDOR_ID)
    #error "Spi_Ipw_PBcfg.h and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi_Ipw_PBcfg.h file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw.h are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_H != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_MBDT_PBCFG_H != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_MBDT_PBCFG_H != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
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
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/* External device configuration */
extern const Spi_ExDevicesConfigType Spi_aExternalDeviceConfigList_MBDT[2U];

/* Hardwre unit device configuration */
extern const Spi_PhyUnitsConfigType Spi_aHwUnitConfigList_MBDT[SPI_MAX_HWUNIT];
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif 

