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
*   @file
*
*   @addtogroup Mscm_Ip Mscm IPV Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Mscm_Ip.h"

#ifdef MSCM_IP_DEV_ERROR_DETECT
#if(MSCM_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_VENDOR_ID_C                      43
#define RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_MSCM_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RM_MSCM_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RM_MSCM_IP_SW_MAJOR_VERSION_C               5
#define RM_MSCM_IP_SW_MINOR_VERSION_C               0
#define RM_MSCM_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mscm_Ip.h */
#if (RM_MSCM_IP_VENDOR_ID_C != RM_MSCM_IP_VENDOR_ID)
    #error "Mscm_Ip.c and Mscm_Ip.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION_C    !=  RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_AR_RELEASE_MINOR_VERSION_C    !=  RM_MSCM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_AR_RELEASE_REVISION_VERSION_C !=  RM_MSCM_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip.c and Mscm_Ip.h are different"
#endif
#if ((RM_MSCM_IP_SW_MAJOR_VERSION_C != RM_MSCM_IP_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_SW_MINOR_VERSION_C != RM_MSCM_IP_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_SW_PATCH_VERSION_C != RM_MSCM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip.c and Mscm_Ip.h are different"
#endif

#ifdef RM_IP_ENABLE_MSCM
#if (RM_IP_ENABLE_MSCM == STD_ON)

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

void Mscm_Ip_InitPrivileged(Mscm_Ip_ConfigType const *pMscmConfig);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
/**
 * @brief         Initializes the configured Mscm.
 */
void Mscm_Ip_Init(const Mscm_Ip_ConfigType *pMscmConfig)
{
#ifdef MSCM_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Mscm_Ip_InitPrivileged,pMscmConfig);
#else
    Mscm_Ip_InitPrivileged(pMscmConfig);
#endif
}
/**
 * @internal
 * @brief         Initializes the configured routing interrupts.
 */
void Mscm_Ip_InitPrivileged(Mscm_Ip_ConfigType const * pMscmConfig)
{
    uint16 spiIdx;
    uint16 u16TargetCores;
    uint16 u16SPINumber;

#if (MSCM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(pMscmConfig != NULL_PTR);
    DevAssert(pMscmConfig->u32GlobalRouteConfigCount <= MSCM_IP_SPI_COUNT);
#endif
    for (spiIdx = 0; spiIdx < pMscmConfig->u32GlobalRouteConfigCount; spiIdx++)
    {
        u16TargetCores = pMscmConfig->aGlobalRouteConfig[spiIdx].u16TargetCores;
        u16SPINumber   = (uint16)(pMscmConfig->aGlobalRouteConfig[spiIdx].u16IrqNumber);

#if (MSCM_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check IRQ number */
        DevAssert((u16SPINumber) <= MSCM_IP_SPI_MAX);

        /* Check interrupt routing is not locked for this IRQ */
        DevAssert((IP_MSCM->IRSPRC[u16SPINumber] & (uint16)(MSCM_IRSPRC_LOCK_MASK)) == (uint16)MSCM_IRSPRC_LOCK(0));
        DevAssert(((uint16)u16TargetCores) <= (uint16)MSCM_IP_CORE_MASK);
#endif
        /* Configure routing */
        IP_MSCM->IRSPRC[u16SPINumber] = (uint16)u16TargetCores & (uint16)MSCM_IP_CORE_MASK;
    }
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* if (RM_IP_ENABLE_MSCM == STD_ON) */
#endif /* ifdef RM_IP_ENABLE_MSCM */


/** @} */
