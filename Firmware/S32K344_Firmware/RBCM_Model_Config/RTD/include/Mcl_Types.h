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

#ifndef MCL_TYPES_H_
#define MCL_TYPES_H_

/**
*   @file Mcl_Types.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details
*
*   @addtogroup MCL_DRIVER MCL Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif
/**
* @page misra_violations MISRA-C:2012 violations
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg_Defines.h"
#if (STD_ON == MCL_DMA_IS_AVAILABLE)
#include "Dma_Ip.h"
#endif /* STD_ON == MCL_DMA_IS_AVAILABLE */
#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
#include "Cache_Ip.h"
#endif /* STD_ON == MCL_CACHE_IS_AVAILABLE */
#if (STD_ON == MCL_LCU_IS_AVAILABLE)
#include "Lcu_Ip.h"
#endif /* STD_ON == MCL_LCU_IS_AVAILABLE */
#if (STD_ON == MCL_TRGMUX_IS_AVAILABLE)
#include "Trgmux_Ip.h"
#endif /* STD_ON == MCL_TRGMUX_IS_AVAILABLE */
#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)
#include "Emios_Mcl_Ip.h"
#endif /* STD_ON == MCL_EMIOS_IS_AVAILABLE */
#if (STD_ON == MCL_FLEXIO_IS_AVAILABLE)
#include "Flexio_Mcl_Ip.h"
#endif /* STD_ON == MCL_FLEXIO_IS_AVAILABLE */
#if (STD_ON == MCL_LLC_IS_AVAILABLE)
#include "Llc_Ip.h"
#endif /* STD_ON == MCL_LLC_IS_AVAILABLE */
#if (STD_ON == MCL_SPFU_IS_AVAILABLE)
#include "Spfu_Ip.h"
#endif /* STD_ON == MCL_SPFU_IS_AVAILABLE */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_TYPES_VENDOR_ID                       43
#define MCL_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCL_TYPES_AR_RELEASE_MINOR_VERSION        7
#define MCL_TYPES_AR_RELEASE_REVISION_VERSION     0
#define MCL_TYPES_SW_MAJOR_VERSION                5
#define MCL_TYPES_SW_MINOR_VERSION                0
#define MCL_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and CDD_Mcl_Cfg_Defines.h file are of the same vendor */
#if (MCL_TYPES_VENDOR_ID != CDD_MCL_CFG_DEFINES_VENDOR_ID)
    #error "Mcl_Types.h and CDD_Mcl_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and CDD_Mcl_Cfg_Defines.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and CDD_Mcl_Cfg_Defines.h are different"
#endif

/* Check if header file and CDD_Mcl_Cfg_Defines.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and CDD_Mcl_Cfg_Defines.h are different"
#endif

#if (STD_ON == MCL_DMA_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != DMA_IP_VENDOR_ID)
    #error "Mcl_Types.h and Dma_Ip.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != DMA_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != DMA_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != DMA_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != DMA_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Dma_Ip.h are different"
#endif
#endif /* STD_ON == MCL_DMA_IS_AVAILABLE */

#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != CACHE_IP_VENDOR_ID)
    #error "Mcl_Types.h and Cache_Ip.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != CACHE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != CACHE_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != CACHE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Cache_Ip.h are different"
#endif

/* Check if header file and Cache_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != CACHE_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != CACHE_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != CACHE_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Cache_Ip.h are different"
#endif
#endif /* STD_ON == MCL_CACHE_IS_AVAILABLE */

#if (STD_ON == MCL_LCU_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != LCU_IP_VENDOR_ID)
    #error "Mcl_Types.h and Lcu_Ip.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != LCU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != LCU_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != LCU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Lcu_Ip.h are different"
#endif

/* Check if header file and Lcu_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != LCU_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != LCU_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != LCU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Lcu_Ip.h are different"
#endif
#endif /* STD_ON == MCL_LCU_IS_AVAILABLE */

#if (STD_ON == MCL_TRGMUX_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != TRGMUX_IP_VENDOR_ID)
    #error "Mcl_Types.h and Trgmux_Ip.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Trgmux_Ip.h are different"
#endif

/* Check if header file and Trgmux_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != TRGMUX_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != TRGMUX_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != TRGMUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Trgmux_Ip.h are different"
#endif
#endif /* STD_ON == MCL_TRGMUX_IS_AVAILABLE */

#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)

#if (MCL_TYPES_VENDOR_ID != EMIOS_MCL_IP_VENDOR_ID)
    #error "Mcl_Types.h and Emios_Mcl_Ip.h have different vendor ids"
#endif

/* Check if header file and Emios_Mcl_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Emios_Mcl_Ip.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != EMIOS_MCL_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != EMIOS_MCL_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != EMIOS_MCL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Emios_Mcl_Ip.h are different"
#endif
#endif /* STD_ON == MCL_EMIOS_IS_AVAILABLE */

#if (STD_ON == MCL_FLEXIO_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != FLEXIO_MCL_IP_VENDOR_ID)
    #error "Mcl_Types.h and Flexio_Mcl_Ip.h have different vendor ids"
#endif

/* Check if header file and Flexio_Mcl_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Flexio_Mcl_Ip.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != FLEXIO_MCL_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != FLEXIO_MCL_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != FLEXIO_MCL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Flexio_Mcl_Ip.h are different"
#endif
#endif /* STD_ON == MCL_FLEXIO_IS_AVAILABLE */

#if (STD_ON == MCL_LLC_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != LLC_IP_VENDOR_ID)
    #error "Mcl_Types.h and Llc_Ip.h have different vendor ids"
#endif

/* Check if header file and Llc_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != LLC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != LLC_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != LLC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Llc_Ip.h are different"
#endif

/* Check if header file and Llc_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != LLC_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != LLC_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != LLC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Llc_Ip.h are different"
#endif
#endif /* STD_ON == MCL_LLC_IS_AVAILABLE */

#if (STD_ON == MCL_SPFU_IS_AVAILABLE)
#if (MCL_TYPES_VENDOR_ID != SPFU_IP_VENDOR_ID)
    #error "Mcl_Types.h and Spfu_Ip.h have different vendor ids"
#endif

/* Check if header file and Spfu_Ip.h file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != SPFU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != SPFU_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != SPFU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcl_Types.h and Spfu_Ip.h are different"
#endif

/* Check if header file and Spfu_Ip.h file are of the same Software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != SPFU_IP_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != SPFU_IP_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != SPFU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcl_Types.h and Spfu_Ip.h are different"
#endif
#endif /* STD_ON == MCL_SPFU_IS_AVAILABLE */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief This type contains the Mcl Return Type.
 * @details The Return Type give information for the execution of interfaces.
 *
 * */
typedef enum{
    MCL_STATUS_SUCCESS     = E_OK,
    MCL_STATUS_ERROR       = E_NOT_OK
}Mcl_ReturnType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)
typedef struct
{
    const uint8                   instance;
    const Emios_Mcl_Ip_ConfigType *emiosInstanceConfig;
} Mcl_EmiosInstanceConfigType;

typedef struct
{
    const uint8                       MclEmiosNumInstances;
    const Mcl_EmiosInstanceConfigType (*pMclEmiosInstanceConfig)[];
} Mcl_EmiosInitConfigType;

#endif /* STD_ON == MCL_EMIOS_IS_AVAILABLE */

/**
 * @brief This type contains the Mcl Configuration.
 * @details The Mcl Configuration structure contains pointers to the Ip's configuration
 *          structure. Based on the available support, specific configurations shall be
 *          stored.
 *
 * */
typedef struct{
#if (STD_ON == MCL_DMA_IS_AVAILABLE)
    const Dma_Ip_InitType * const pxDmaInitType;
#else
    const uint8 * const DummyDmaPtr;
#endif /* STD_ON == MCL_DMA_IS_AVAILABLE */
#if (STD_ON == MCL_TRGMUX_IS_AVAILABLE)
    const Trgmux_Ip_InitType * const pxTrgmuxInitType;
#else
    const uint8 * const DummyTrgmuxPtr;
#endif /* STD_ON == MCL_TRGMUX_IS_AVAILABLE */
#if (STD_ON == MCL_LCU_IS_AVAILABLE)
    const Lcu_Ip_InitType * const pxLcuInitType;
#else
    const uint8 * const DummyLcuPtr;
#endif /* STD_ON == MCL_LCU_IS_AVAILABLE */
#if (STD_ON == MCL_EMIOS_IS_AVAILABLE)
    const Mcl_EmiosInitConfigType * const pEmiosInitType;
#else
    const uint8 * const DummyEmiosPtr;
#endif /* STD_ON == MCL_EMIOS_IS_AVAILABLE */
#if (STD_ON == MCL_FLEXIO_IS_AVAILABLE)
    const Flexio_Ip_InstanceConfigType * const pFlexioInitType;
#else
    const uint8 * const DummyFlexioPtr;
#endif /* STD_ON == MCL_FLEXIO_IS_AVAILABLE */
}Mcl_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* MCL_TYPES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

