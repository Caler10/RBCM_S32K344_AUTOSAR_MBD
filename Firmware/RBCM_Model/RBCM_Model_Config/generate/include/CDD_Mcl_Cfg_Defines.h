/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_MCL_CFG_DEFINES_H_
#define CDD_MCL_CFG_DEFINES_H_

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
#include "Dma_Ip_Cfg_Defines.h"
#include "Cache_Ip_Cfg_Defines.h"
#include "Trgmux_Ip_Cfg_Defines.h"
#include "Lcu_Ip_Cfg_Defines.h"
#include "Emios_Mcl_Ip_Cfg.h"
#include "Flexio_Mcl_Ip_Cfg_Defines.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCL_CFG_DEFINES_VENDOR_ID                       43
#define CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION                5
#define CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION                0
#define CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != DMA_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Dma_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Dma_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != DMA_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != DMA_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Dma_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != CACHE_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Cache_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Cache_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != CACHE_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Cache_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != TRGMUX_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Trgmux_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Lcu_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != LCU_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Lcu_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != LCU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Lcu_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Lcu_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != LCU_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != LCU_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != LCU_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Lcu_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != EMIOS_MCL_IP_CFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Emios_Mcl_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Emios_Mcl_Ip_Cfg.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != EMIOS_MCL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != EMIOS_MCL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Emios_Mcl_Ip_Cfg.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != FLEXIO_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Flexio_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/*-----------------------------------------------/
/  DMA                                           /
/-----------------------------------------------*/
#define MCL_DMA_IS_AVAILABLE                       DMA_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  CACHE                                         /
/-----------------------------------------------*/
#define MCL_CACHE_IS_AVAILABLE                     CACHE_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  TRGMUX                                        /
/-----------------------------------------------*/
#define MCL_TRGMUX_IS_AVAILABLE                    TRGMUX_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  EMIOS                                         /
/-----------------------------------------------*/
#define MCL_EMIOS_IS_AVAILABLE                     EMIOS_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  LCU                                           /
/-----------------------------------------------*/
#define MCL_LCU_IS_AVAILABLE                       LCU_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  FLEXIO                                        /
/-----------------------------------------------*/
#define MCL_FLEXIO_IS_AVAILABLE                    FLEXIO_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  FTM                                           /
/-----------------------------------------------*/
#define MCL_COMMON_TIMEBASE_IS_AVAILABLE           STD_OFF

/*-----------------------------------------------/
/  ETIMER                                         /
/-----------------------------------------------*/
#define MCL_ETIMER_IS_AVAILABLE                    STD_OFF

/*-----------------------------------------------/
/  LLC                                           /
/-----------------------------------------------*/
#define MCL_LLC_IS_AVAILABLE                       STD_OFF

/*-----------------------------------------------/
/  SPFU                                          /
/-----------------------------------------------*/
#define MCL_SPFU_IS_AVAILABLE                      STD_OFF

/*-----------------------------------------------/
/  MULTICORE                                     /
/-----------------------------------------------*/
#define MCL_MULTICORE_IS_AVAILABLE                 STD_OFF

#if (STD_ON == MCL_MULTICORE_IS_AVAILABLE)
    #define Mcl_GetUserID                   ((uint32)OsIf_GetUserId())
#else
    #define MCL_SPURIOUS_USER_ID_U32        ((uint32)0UL)
    #define Mcl_GetUserID                   MCL_SPURIOUS_USER_ID_U32
#endif

/**
* @brief Total number of partitions configured in Ecu.
*/
#define MCL_MAX_PARTITIONS             (1U)


/*-----------------------------------------------/
/  VERSION INFO API                              /
/-----------------------------------------------*/
#define MCL_VERSION_INFO_API_IS_AVAILABLE          STD_ON

#ifdef __cplusplus
}
#endif

#endif /* CDD_MCL_CFG_DEFINES_H */

