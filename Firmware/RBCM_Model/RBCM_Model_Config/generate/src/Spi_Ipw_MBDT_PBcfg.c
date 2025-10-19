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
/**
*   @file    Spi_Ipw_MBDT_PBcfg.c
*   @version 5.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
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
==================================================================================================*/
#include "Spi_Ipw_MBDT_PBcfg.h"
#include "Lpspi_Ip_Cfg.h"
#include "Flexio_Spi_Ip_Cfg.h"
#include "Dspi_Ip_Cfg.h"
#include "Spi.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_MBDT_VENDOR_ID_PBCFG_C                        43
#define SPI_IPW_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_IPW_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG_C         7

#define SPI_IPW_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_IPW_MBDT_SW_MAJOR_VERSION_PBCFG_C                 5
#define SPI_IPW_MBDT_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_IPW_MBDT_SW_PATCH_VERSION_PBCFG_C                 0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (SPI_IPW_VENDOR_ID_MBDT_PBCFG_H != SPI_IPW_MBDT_VENDOR_ID_PBCFG_C)
    #error "Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Spi_Ipw_PBcfg.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_MBDT_PBCFG_H != SPI_IPW_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_MBDT_PBCFG_H != SPI_IPW_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_MBDT_PBCFG_H != SPI_IPW_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_MBDT_PBCFG_H != SPI_IPW_MBDT_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IPW_SW_MINOR_VERSION_MBDT_PBCFG_H != SPI_IPW_MBDT_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_IPW_SW_PATCH_VERSION_MBDT_PBCFG_H != SPI_IPW_MBDT_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c are different"
#endif

/* Check if Lpspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID_CFG != SPI_IPW_MBDT_VENDOR_ID_PBCFG_C)
    #error "Lpspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Lpspi_Ip_Cfg.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Lpspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION_CFG != SPI_IPW_MBDT_SW_MAJOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_SW_MINOR_VERSION_CFG != SPI_IPW_MBDT_SW_MINOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_SW_PATCH_VERSION_CFG != SPI_IPW_MBDT_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Lpspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are different"
#endif

/* Check if Spi.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (SPI_VENDOR_ID != SPI_IPW_MBDT_VENDOR_ID_PBCFG_C)
    #error "Spi.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Spi.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_IPW_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_AR_RELEASE_MINOR_VERSION != SPI_IPW_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_AR_RELEASE_REVISION_VERSION != SPI_IPW_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((SPI_SW_MAJOR_VERSION != SPI_IPW_MBDT_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_SW_MINOR_VERSION != SPI_IPW_MBDT_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_SW_PATCH_VERSION != SPI_IPW_MBDT_SW_PATCH_VERSION_PBCFG_C))
    #error "Software Version Numbers of Spi.h and Spi_Ipw_PBcfg.c are different"
#endif

/* Check if Flexio_Spi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_CFG != SPI_IPW_MBDT_VENDOR_ID_PBCFG_C)
    #error "Flexio_Spi_Ip_Cfg.h and Spi_Ipw_MBDT_PBcfg.c have different vendor ids"
#endif
/* Check if Flexio_Spi_Ip_Cfg.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG_C))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip_Cfg.h and Spi_Ipw_MBDT_PBcfg.c are different"
#endif

#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG != SPI_IPW_MBDT_SW_MAJOR_VERSION_PBCFG_C) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG != SPI_IPW_MBDT_SW_MINOR_VERSION_PBCFG_C) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG != SPI_IPW_MBDT_SW_PATCH_VERSION_PBCFG_C))
    #error "Software Version Numbers of Flexio_Spi_Ip_Cfg.h and Spi_Ipw_MBDT_PBcfg.c are different"
#endif

#if (SPI_IPW_DSPI_ENABLE == STD_ON)
/* Check if Dspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (DSPI_IP_VENDOR_ID_CFG != SPI_IPW_MBDT_VENDOR_ID_PBCFG_C)
    #error "Dspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Dspi_Ip_Cfg.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (DSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != SPI_IPW_MBDT_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Dspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((DSPI_IP_SW_MAJOR_VERSION_CFG != SPI_IPW_MBDT_SW_MAJOR_VERSION_PBCFG_C) || \
     (DSPI_IP_SW_MINOR_VERSION_CFG != SPI_IPW_MBDT_SW_MINOR_VERSION_PBCFG_C) || \
     (DSPI_IP_SW_PATCH_VERSION_CFG != SPI_IPW_MBDT_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Dspi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are different"
#endif
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
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

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/* External device configuration for SpiExternalDevice_0 */
static const Spi_ExternalDeviceConfigType Spi_ExternalDeviceConfig_SpiExternalDevice_0_MBDT =
{
    SPI_OVER_LPSPI, /* IpType */
    2U,  /* Instance */
    {   /* ExternalDeviceConfig */
        &Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_2_MBDT, /* Lpspi IP Config */
        #if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
        NULL_PTR, /* Flexio_Spi IP Config */
        #endif
        #if (SPI_IPW_DSPI_ENABLE == STD_ON)
        NULL_PTR /* Dspi IP Config */
        #endif
    },
        (uint32)SPI_SPURIOUS_USER_ID_U32 /* UserId */
};
/* External device configuration for SpiExternalDevice_1 */
static const Spi_ExternalDeviceConfigType Spi_ExternalDeviceConfig_SpiExternalDevice_1_MBDT =
{
    SPI_OVER_LPSPI, /* IpType */
    1U,  /* Instance */
    {   /* ExternalDeviceConfig */
        &Lpspi_Ip_DeviceAttributes_SpiExternalDevice_1_Instance_1_MBDT, /* Lpspi IP Config */
        #if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
        NULL_PTR, /* Flexio_Spi IP Config */
        #endif
        #if (SPI_IPW_DSPI_ENABLE == STD_ON)
        NULL_PTR /* Dspi IP Config */
        #endif
    },
        (uint32)SPI_SPURIOUS_USER_ID_U32 /* UserId */
};
/* Array External device configuration */
const Spi_ExDevicesConfigType Spi_aExternalDeviceConfigList_MBDT[2U] =
{
    /* SpiExternalDevice_0 */
    {
        &Spi_ExternalDeviceConfig_SpiExternalDevice_0_MBDT
    },
    /* SpiExternalDevice_1 */
    {
        &Spi_ExternalDeviceConfig_SpiExternalDevice_1_MBDT
    }
};
/* Hardware unit device configuration for SpiPhyUnit_0*/
static const Spi_HWUnitConfigType Spi_HwUnitConfig_SpiPhyUnit_0_MBDT =
{
        SPI_OVER_LPSPI, /* IpType */
        (uint8)2U, /* Instance */
        (uint32)SPI_SPURIOUS_USER_ID_U32, /* User Id */
        {
            &Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_2_MBDT /* Lpspi IpConfig */
            #if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
            ,NULL_PTR /* Flexio_Spi IpConfig */
            #endif
            #if (SPI_IPW_DSPI_ENABLE == STD_ON)
            ,NULL_PTR /* Dspi IpConfig */
            #endif
#if ((SPI_IPW_DMA_USED == STD_ON) && (SPI_IPW_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
            ,NULL_PTR
            #if (SPI_IPW_DSPI_ENABLE == STD_ON)
            ,NULL_PTR
            #endif
#endif
        }
};
/* Hardware unit device configuration for SpiPhyUnit_1*/
static const Spi_HWUnitConfigType Spi_HwUnitConfig_SpiPhyUnit_1_MBDT =
{
        SPI_OVER_LPSPI, /* IpType */
        (uint8)1U, /* Instance */
        (uint32)SPI_SPURIOUS_USER_ID_U32, /* User Id */
        {
            &Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_1_Instance_1_MBDT /* Lpspi IpConfig */
            #if (SPI_IPW_SPI_FLEXIO_ENABLE == STD_ON)
            ,NULL_PTR /* Flexio_Spi IpConfig */
            #endif
            #if (SPI_IPW_DSPI_ENABLE == STD_ON)
            ,NULL_PTR /* Dspi IpConfig */
            #endif
#if ((SPI_IPW_DMA_USED == STD_ON) && (SPI_IPW_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
            ,NULL_PTR
            #if (SPI_IPW_DSPI_ENABLE == STD_ON)
            ,NULL_PTR
            #endif
#endif
        }
};
/* Array Hardware unit device configuration */
const Spi_PhyUnitsConfigType Spi_aHwUnitConfigList_MBDT[SPI_MAX_HWUNIT] =
{
    /* SpiPhyUnit_0 */
    {
        &Spi_HwUnitConfig_SpiPhyUnit_0_MBDT
    },
    /* SpiPhyUnit_1 */
    {
        &Spi_HwUnitConfig_SpiPhyUnit_1_MBDT
    }
};

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

