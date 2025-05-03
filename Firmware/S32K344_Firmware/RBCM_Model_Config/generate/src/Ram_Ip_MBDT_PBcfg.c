/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file       Ram_Ip_MBDT_PBcfg.c
*   @version    5.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup RAM_DRIVER_CONFIGURATION Ram Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ram_Ip_MBDT_PBcfg.h"
#include "Std_Types.h"
#include "Ram_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define RAM_IP_PBCFG_VENDOR_ID_C                      43
#define RAM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define RAM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define RAM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define RAM_IP_PBCFG_SW_MAJOR_VERSION_C               5
#define RAM_IP_PBCFG_SW_MINOR_VERSION_C               0
#define RAM_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Ram_Ip_PBcfg.h file are of the same vendor */
#if (RAM_IP_PBCFG_VENDOR_ID_C != RAM_IP_PBCFG_VENDOR_ID)
    #error "Ram_Ip_PBcfg.c and Ram_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if source file and Ram_Ip_PBcfg.h file are of the same Autosar version */
#if ((RAM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != RAM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != RAM_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RAM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RAM_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ram_Ip_PBcfg.c and Ram_Ip_PBcfg.h are different"
#endif
/* Check if source file and Ram_Ip_PBcfg.h file are of the same Software version */
#if ((RAM_IP_PBCFG_SW_MAJOR_VERSION_C != RAM_IP_PBCFG_SW_MAJOR_VERSION) || \
     (RAM_IP_PBCFG_SW_MINOR_VERSION_C != RAM_IP_PBCFG_SW_MINOR_VERSION) || \
     (RAM_IP_PBCFG_SW_PATCH_VERSION_C != RAM_IP_PBCFG_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Ram_Ip_PBcfg.c and Ram_Ip_PBcfg.h are different"
#endif

/* Check if source file and Ram_Ip.h file are of the same vendor */
#if (RAM_IP_PBCFG_VENDOR_ID_C != RAM_IP_VENDOR_ID)
    #error "Ram_Ip_PBcfg.c and Ram_Ip.h have different vendor ids"
#endif
/* Check if source file and Ram_Ip.h file are of the same Autosar version */
#if ((RAM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != RAM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != RAM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RAM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RAM_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ram_Ip_PBcfg.c and Ram_Ip.h are different"
#endif
/* Check if source file and Ram_Ip.h file are of the same Software version */
#if ((RAM_IP_PBCFG_SW_MAJOR_VERSION_C != RAM_IP_SW_MAJOR_VERSION) || \
     (RAM_IP_PBCFG_SW_MINOR_VERSION_C != RAM_IP_SW_MINOR_VERSION) || \
     (RAM_IP_PBCFG_SW_PATCH_VERSION_C != RAM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ram_Ip_PBcfg.c and Ram_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h file are of the same Autosar version */
#if ((RAM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Ram_Ip_PBcfg.c and Std_Types.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#ifndef MCU_MAX_NORAMCONFIGS
/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitRamSection() API.
*
*/
const Ram_Ip_RamConfigType Mcu_aRamConfigPB[1] =
{
     {
         /* The ID for Ram Sector configuration. */
         (Ram_Ip_RamSectionType)0U,

         /* RAM section base address: Start of Mcu_aRamConfig[0]*/
         (uint8 (*)[1U])0x20400000U,
         /* RAM section size: Section base address (must be aligned to 4 bytes). */
         (Ram_Ip_RamSizeType *)0x50000U,
         /* RAM default value. */
         (uint8)0x0U,
         /* RAM section write size (maximum allowed: 8). */
         (Ram_Ip_RamWriteSizeType)8U
     }, /* End of Mcu_aRamConfigPB[0]. */
};
#endif /* ifndef MCU_MAX_NORAMCONFIGS */

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

