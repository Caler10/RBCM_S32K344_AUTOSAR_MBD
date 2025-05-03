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

#ifndef SPI_IPW_TYPES_H
#define SPI_IPW_TYPES_H

/**
*   @file    Spi_Ipw_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
*   @addtogroup SPI_DRIVER Spi Driver
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
#include "Lpspi_Ip_Types.h"
#include "Flexio_Spi_Ip_Types.h"
#include "Dspi_Ip_Types.h"
#include "Spi_Ipw_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_TYPES_VENDOR_ID                       43
#define SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION        7
#define SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION     0
#define SPI_IPW_TYPES_SW_MAJOR_VERSION                5
#define SPI_IPW_TYPES_SW_MINOR_VERSION                0
#define SPI_IPW_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw_Types.h and Lpspi_Ip_Types.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != LPSPI_IP_TYPES_VENDOR_ID)
    #error "Spi_Ipw_Types.h and Lpspi_Ip_Types.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Lpspi_Ip_Types.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION != LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw_Types.h and Lpspi_Ip_Types.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != LPSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != LPSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != LPSPI_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw_Types.h and Lpspi_Ip_Types.h are different"
#endif

/* Check if Spi_Ipw_Types.h and Flexio_Spi_Ip_Types.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != FLEXIO_SPI_IP_TYPES_VENDOR_ID)
    #error "Spi_Ipw_Types.h and Flexio_Spi_Ip_Types.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Flexio_Spi_Ip_Types.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_Ipw_Types.h and Flexio_Spi_Ip_Types.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_SPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_SPI_IP_TYPES_SW_MINOR_VERSION) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_SPI_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_Ipw_Types.h and Flexio_Spi_Ip_Types.h are different"
#endif

/* Check if Spi_Ipw_Types.h and Dspi_Ip_Types.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != DSPI_IP_TYPES_VENDOR_ID)
    #error "Spi_Ipw_Types.h and Dspi_Ip_Types.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Dspi_Ip_Types.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != DSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != DSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != DSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_Ipw_Types.h and Dspi_Ip_Types.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != DSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != DSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != DSPI_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_Ipw_Types.h and Dspi_Ip_Types.h are different"
#endif

/* Check if Spi_Ipw_Types.h and Spi_Ipw_Cfg.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != SPI_IPW_VENDOR_ID_CFG_H)
    #error "Spi_Ipw_Types.h and Spi_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Spi_Ipw_Cfg.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != SPI_IPW_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION != SPI_IPW_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SPI_IPW_AR_RELEASE_REVISION_VERSION_CFG_H))
#error "AutoSar Version Numbers of Spi_Ipw_Types.h and Spi_Ipw_Cfg.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != SPI_IPW_SW_MAJOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != SPI_IPW_SW_MINOR_VERSION_CFG_H) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != SPI_IPW_SW_PATCH_VERSION_CFG_H))
#error "Software Version Numbers of Spi_Ipw_Types.h and Spi_Ipw_Cfg.h are different"
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

#if (CPU_TYPE == CPU_TYPE_64)
typedef uint64 Spi_Ipw_uintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
typedef uint32 Spi_Ipw_uintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif

/**
 * @brief This enum contains all IPs which can integrate SPI functionalityes
 */
typedef enum
{
    SPI_OVER_LPSPI = 0,
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    SPI_OVER_FLEXIO = 1,
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    SPI_OVER_DSPI = 2
#endif
} Spi_Ipw_SupportedIpsType;

/**
 * @brief This union contains config structure for all IPs available.
 */
typedef struct
{
    const Lpspi_Ip_ConfigType *LpspiIpConfig;
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    const Flexio_Spi_Ip_ConfigType *FlexioSpiIpConfig;
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    const Dspi_Ip_ConfigType *DspiIpConfig;
#endif
#if (SPI_IPW_DMA_USED == STD_ON)
#if (SPI_IPW_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    Lpspi_Ip_FastTransferType *LpspiFastTransferCfg; /* config structure for a sequence transfer with Dma Fast */
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    Dspi_Ip_FastTransferType *DspiFastTransferCfg; /* config structure for a sequence transfer with Dma Fast */
#endif
#endif
#endif
} Spi_Ipw_IpConfigType;

/**
 * @brief This union contains config structure for all external device available.
 */
typedef struct
{
    const Lpspi_Ip_ExternalDeviceType *LpspiExternalDeviceConfig;
#if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
    const Flexio_Spi_Ip_ExternalDeviceType *Flexio_SpiExternalDeviceConfig;
#endif
#if (SPI_IPW_DSPI_ENABLE == STD_ON)
    const Dspi_Ip_ExternalDeviceType *DspiExternalDeviceConfig;
#endif
} Spi_Ipw_ExternalDeviceType;

/**
* @brief   This structure holds the HWUnit configuration parameters.
*
* @implements Spi_HWUnitConfigType_struct
*/
typedef struct
{
    Spi_Ipw_SupportedIpsType IpType;
    uint8 Instance;
    uint32 SpiPartitionUse;
    Spi_Ipw_IpConfigType IpConfig;
} Spi_HWUnitConfigType;

/**
* @brief   This structure holds the PhyUnit configuration.
*/
typedef struct
{
    /** @brief Point to PhyUnit configuration. */
    const Spi_HWUnitConfigType * PhyUnitConfig;
} Spi_PhyUnitsConfigType;

/**
* @brief   This structure holds the configuration parameters for each ExternalDevice.
*/
typedef struct
{
    Spi_Ipw_SupportedIpsType IpType;
    uint8 Instance;
    Spi_Ipw_ExternalDeviceType ExternalDeviceConfig;
    uint32 SpiPartitionUse;
} Spi_ExternalDeviceConfigType;

/**
* @brief   This structure holds the ExternalDevice configuration.
*/
typedef struct
{
    /** @brief Point to ExternalDevice configuration. */
    const Spi_ExternalDeviceConfigType * ExDeviceConfig;
} Spi_ExDevicesConfigType;

#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
typedef Lpspi_Ip_TxBufferListType Spi_DmaContMemState;
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SPI_IPW_TYPES_H*/
