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
*   @file Virt_Wrapper_Ip.c
*
*   @addtogroup Virt_Wrapper_Ip Virt Wrapper IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Virt_Wrapper_Ip.h"

#ifdef VIRT_WRAPPER_IP_DEV_ERROR_DETECT
#if (VIRT_WRAPPER_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef VIRT_WRAPPER_IP_ENABLE_USER_MODE_SUPPORT
        #ifndef USER_MODE_REG_PROT_ENABLED
        #define USER_MODE_REG_PROT_ENABLED (STD_ON)
        #include "RegLockMacros.h"
        #endif
    #endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VIRT_WRAPPER_IP_VENDOR_ID_C                      43
#define RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION_C               5
#define RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION_C               0
#define RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against VIRT_WRAPPER_Ip.h */
#if (RM_VIRT_WRAPPER_IP_VENDOR_ID_C !=  RM_VIRT_WRAPPER_IP_VENDOR_ID)
    #error "Virt_Wrapper_Ip.c and Virt_Wrapper_Ip.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION_C    != RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION_C    != RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION_C != RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip.c and Virt_Wrapper_Ip.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION_C != RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION_C != RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION_C != RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Virt_Wrapper_Ip.c and Virt_Wrapper_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef VIRT_WRAPPER_IP_DEV_ERROR_DETECT
    #if (VIRT_WRAPPER_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if the files Virt_Wrapper_Ip.c and Devassert.h are of the same version */
        #if ((RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip.c and Devassert.h are different"
        #endif
    #endif
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef RM_IP_ENABLE_VIRT_WRAPPER
#if (RM_IP_ENABLE_VIRT_WRAPPER == STD_ON)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
static RM_VIRT_WRAPPER_Type * aVirtWrapperBasePtrs[VIRT_WRAPPER_BASE_WITH_GAP_CNT] = VIRT_WRAPPER_BASE_WITH_GAP;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

void Virt_Wrapper_Ip_Init_Privileged(const Virt_Wrapper_Ip_ConfigType *pVirt_WrapperConfig);

void Virt_Wrapper_Ip_SetRegAccessProtection(uint32 u32Instance,
                                            Virt_Wrapper_Ip_AccessType eMirror,
                                            uint32 u32Pin,
                                            Virt_Wrapper_Ip_SlotType eSlotType);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief         Virt_Wrapper_Ip_SetMscrAccessProtection 
 *
 * @details       This function is Reentrant
 *
 * @param[in]     pVirt_WrapperConfig: Pointer point the configuration of pads (Suil2 registers) will be protected by Virtual Wrapper
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
void Virt_Wrapper_Ip_Init(const Virt_Wrapper_Ip_ConfigType *pVirt_WrapperConfig)
{
#ifdef VIRT_WRAPPER_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Virt_Wrapper_Ip_Init_Privileged, pVirt_WrapperConfig);
#else
    Virt_Wrapper_Ip_Init_Privileged(pVirt_WrapperConfig);
#endif
}

/**
 * @brief         Virt_Wrapper_Ip_SetMscrAccessProtection
 *
 * @details       This function is Reentrant
 *
 * @param[in]     pVirt_WrapperConfig: Pointer point the configuration of pads (Suil2 registers) will be protected by Virtual Wrapper
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */
void Virt_Wrapper_Ip_Init_Privileged(const Virt_Wrapper_Ip_ConfigType *pVirt_WrapperConfig)
{
    uint32 u32Counter = 0U;
    const Virt_Wrapper_Ip_RegConfigType *pTemp;

#if (VIRT_WRAPPER_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(pVirt_WrapperConfig != NULL_PTR);
#endif

    for (u32Counter = 0U; u32Counter < pVirt_WrapperConfig->u32ConfigCount; u32Counter++)
    {
        pTemp = &pVirt_WrapperConfig->aRegConfig[u32Counter];
        /* Set Access protection for each Registers */
        Virt_Wrapper_Ip_SetRegAccessProtection(pTemp->u32Virt_Wrapper_Instance,
                                               pTemp->Virt_Wrapper_Access,
                                               pTemp->u32Virt_Wrapper_Pin,
                                               pTemp->Virt_Wrapper_Slot);
    }
}

/**
 * @brief         Virt_Wrapper_Ip_SetRegAccessProtection
 *
 * @details       This function write the configuration to Virt_Wrapper register.
 *
 * @param[in]     u32Instance: index of SIUL2 instance
 * @param[in]     eMirror: Virtual wrapper PDAC protection
 * @param[in]     u32Pin: protected pin
 * @param[in]     eSlotType: Slot type of register
 * @return        void
 *
 * @api
 *
 * @pre
 *
 */

void Virt_Wrapper_Ip_SetRegAccessProtection(uint32 u32Instance,
                                            Virt_Wrapper_Ip_AccessType eMirror,
                                            uint32 u32Pin,
                                            Virt_Wrapper_Ip_SlotType eSlotType)
{
    uint32 regOffset;
    uint32 regShift;

#if (VIRT_WRAPPER_IP_DEV_ERROR_DETECT == STD_ON)
    /*check the input parameter*/
    DevAssert(u32Instance < (uint32)VIRT_WRAPPER_BASE_WITH_GAP_CNT);
    DevAssert(aVirtWrapperBasePtrs[u32Instance] != NULL_PTR);
#endif

    /* Calculate register offset and bit shift for given pin */
    regOffset = u32Pin / VIRT_WRAPPER_IP_NUM_OF_SLOT;
    regShift = (u32Pin % VIRT_WRAPPER_IP_NUM_OF_SLOT) * VIRT_WRAPPER_IP_NUM_OF_BIT_SHIFT;

    if (eSlotType == VIRT_WRAPPER_REG_TYPE_A)
    {
        aVirtWrapperBasePtrs[u32Instance]->REG_A[regOffset] &= (uint32)(~(VIRT_WRAPPER_IP_PAD_MASK << regShift));
        aVirtWrapperBasePtrs[u32Instance]->REG_A[regOffset] |= (uint32)((uint32)eMirror << regShift);
    }
    else if (eSlotType == VIRT_WRAPPER_REG_TYPE_B)
    {
        aVirtWrapperBasePtrs[u32Instance]->REG_B[regOffset] &= (uint32)(~(VIRT_WRAPPER_IP_PAD_MASK << regShift));
        aVirtWrapperBasePtrs[u32Instance]->REG_B[regOffset] |= ((uint32)eMirror << regShift);
    }
    else if (eSlotType == VIRT_WRAPPER_REG_TYPE_C)
    {
        aVirtWrapperBasePtrs[u32Instance]->REG_C[regOffset] &= (uint32)(~(VIRT_WRAPPER_IP_PAD_MASK << regShift));
        aVirtWrapperBasePtrs[u32Instance]->REG_C[regOffset] |= ((uint32)eMirror << regShift);
    }

#if RM_VIRT_WRAPPER_REG_D_COUNT > 0U
    else if (eSlotType == VIRT_WRAPPER_REG_TYPE_D)
    {
        aVirtWrapperBasePtrs[u32Instance]->REG_D[regOffset] &= (uint32)(~(VIRT_WRAPPER_IP_PAD_MASK << regShift));
        aVirtWrapperBasePtrs[u32Instance]->REG_D[regOffset] |= ((uint32)eMirror << regShift);
    }
#endif    /** RM_VIRT_WRAPPER_REG_D_COUNT */
    else
    {
        /* Do nothing */
    }
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* RM_IP_ENABLE_VIRT_WRAPPER == STD_ON */
#endif /* RM_IP_ENABLE_VIRT_WRAPPER */

#ifdef __cplusplus
}
#endif

/** @} */
