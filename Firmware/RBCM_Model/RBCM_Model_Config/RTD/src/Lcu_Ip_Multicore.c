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

/**
*   @file    Lcu_Ip_Multicore.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Lcu Ip driver source file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Lcu_Ip_Multicore.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_MULTICORE_VENDOR_ID_C                       43
#define LCU_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION_C        4
#define LCU_IP_MULTICORE_AR_RELEASE_MINOR_VERSION_C        7
#define LCU_IP_MULTICORE_AR_RELEASE_REVISION_VERSION_C     0
#define LCU_IP_MULTICORE_SW_MAJOR_VERSION_C                5
#define LCU_IP_MULTICORE_SW_MINOR_VERSION_C                0
#define LCU_IP_MULTICORE_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lcu_Ip_Multicore.c file and Lcu_Ip_Multicore.h file are of the same vendor */
#if (LCU_IP_MULTICORE_VENDOR_ID_C != LCU_IP_MULTICORE_VENDOR_ID)
    #error "Lcu_Ip_Multicore.c and Lcu_Ip_Multicore.h have different vendor ids"
#endif

/* Check if Lcu_Ip_Multicore.c file and Lcu_Ip_Multicore.h file are of the same Autosar version */
#if ((LCU_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_MULTICORE_AR_RELEASE_MINOR_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_MULTICORE_AR_RELEASE_REVISION_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Multicore.c and Lcu_Ip_Multicore.h are different"
#endif

/* Check if Lcu_Ip_Multicore.c file and Lcu_Ip_Multicore.h file are of the same Software version */
#if ((LCU_IP_MULTICORE_SW_MAJOR_VERSION_C != LCU_IP_MULTICORE_SW_MAJOR_VERSION) || \
     (LCU_IP_MULTICORE_SW_MINOR_VERSION_C != LCU_IP_MULTICORE_SW_MINOR_VERSION) || \
     (LCU_IP_MULTICORE_SW_PATCH_VERSION_C != LCU_IP_MULTICORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Multicore.c and Lcu_Ip_Multicore.h are different"
#endif

#if (STD_ON == LCU_IP_IS_AVAILABLE)

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mcl_MemMap.h"

static uint8 Lcu_Ip_au8CoreRef[LCU_INSTANCE_COUNT][LCU_LC_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

void Lcu_Ip_SetCoreRef(uint8 LcuId, uint8 LcId, uint8 CoreRef)
{
    /* Set core ref */
    Lcu_Ip_au8CoreRef[LcuId][LcId] = CoreRef;
}

Lcu_Ip_ReturnType Lcu_Ip_ValidateCore(uint8 LcuId, uint8 LcId)
{
    Lcu_Ip_ReturnType ReturnValue = LCU_IP_STATUS_WRONG_CORE;
    uint8 CurrentUserId = (uint8)OsIf_GetUserId();
    uint8 LcCoreRef = Lcu_Ip_au8CoreRef[LcuId][LcId];

    if (CurrentUserId == LcCoreRef)
    {
        ReturnValue = LCU_IP_STATUS_SUCCESS;
    }
    else
    {
        /* Do Nothing */
    }
    return ReturnValue;
}

Lcu_Ip_ReturnType Lcu_Ip_InputValidateCore(uint8 LcuId, uint8 HwLcInputId)
{
    uint8 LcId = LCU_IP_MAPPING_INPUT_TO_LC(HwLcInputId);
    /* Validate core */
    return Lcu_Ip_ValidateCore(LcuId, LcId);
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#endif /* #if (STD_ON == LCU_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
