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
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file Dma_Mux_Ip.c
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Dma_Mux_Ip.h"
#if (DMA_MUX_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_VENDOR_ID_C                      43
#define RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RM_DMA_MUX_IP_SW_MAJOR_VERSION_C               5
#define RM_DMA_MUX_IP_SW_MINOR_VERSION_C               0
#define RM_DMA_MUX_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Dma_Mux_Ip.h */
#if (RM_DMA_MUX_IP_VENDOR_ID_C !=  RM_DMA_MUX_IP_VENDOR_ID)
    #error "Dma_Mux_Ip.c and Dma_Mux_Ip.h have different vendor ids"
#endif
#if (( RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION_C    !=  RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION_C    !=  RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION_C !=  RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip.c and Dma_Mux_Ip.h are different"
#endif
#if (( RM_DMA_MUX_IP_SW_MAJOR_VERSION_C !=  RM_DMA_MUX_IP_SW_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_SW_MINOR_VERSION_C !=  RM_DMA_MUX_IP_SW_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_SW_PATCH_VERSION_C !=  RM_DMA_MUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip.c and Dma_Mux_Ip.h are different"
#endif

#if (DMA_MUX_IP_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /*  Check if current file and Devassert.h are of the same version */
        #if ((RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of Dma_Mux_Ip.c and Devassert.h are different"
        #endif
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#if (RM_IP_ENABLE_DMA_MUX == STD_ON)
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_CONST_UNSPECIFIED
#include "Rm_MemMap.h"
static DMAMUX_Type * const Dma_Mux_Ip_BasePointer[DMA_MUX_IP_INSTANCE_COUNT] = DMA_MUX_IP_INSTANCE_BASE_PTRS;

#define RM_STOP_SEC_CONST_UNSPECIFIED
#include "Rm_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief         Initializes the DMA_MUX instance and memory regions configured
 */
void Dma_Mux_Ip_Init_Privileged(const Dma_Mux_Ip_ConfigType *pConfig);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief         Initializes the Dma Mux
 *
 * @details       This function is non-reentrant
 *
 * @param[in]     pConfig: pointer to configuration structure for DMA_MUX.
 * @return        void
 *
 * @pre           None
 *
 *
 **/
void Dma_Mux_Ip_Init_Privileged(const Dma_Mux_Ip_ConfigType *pConfig)
{
    uint8 ChannelCount  = 0;
    uint8 Instance      = 0;
    uint8 RegisterIndex = 0;

#if (DMA_MUX_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(pConfig != NULL_PTR);
#endif

    for (ChannelCount = 0; ChannelCount < pConfig->ChannelConfigCnt; ChannelCount++)
    {
        Instance       = pConfig->pChannelConfigArr[ChannelCount].Instance;
        /*Get register index from channel number*/
        RegisterIndex  = DMA_MUX_IP_GATE_OFFSET((pConfig->pChannelConfigArr[ChannelCount].Channel));
        /*Configure for the dma mux channel*/
        Dma_Mux_Ip_BasePointer[Instance]->CHCFG[RegisterIndex] = pConfig->pChannelConfigArr[ChannelCount].ConfigValue;
    }
}

/**
 * @brief         Initializes the DMA_MUX instance and memory regions configured
 */
void Dma_Mux_Ip_Init(const Dma_Mux_Ip_ConfigType *pConfig)
{
#ifdef DMA_MUX_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Dma_Mux_Ip_Init_Privileged, pConfig);
#else
    Dma_Mux_Ip_Init_Privileged(pConfig);
#endif
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif   /*(RM_IP_ENABLE_DMA_MUX == STD_ON)*/

#ifdef __cplusplus
}
#endif

/** @} */
