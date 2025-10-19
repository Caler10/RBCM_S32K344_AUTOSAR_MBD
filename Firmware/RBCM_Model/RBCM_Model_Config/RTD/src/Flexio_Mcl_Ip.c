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
*   @file    Flexio_Mcl_Ip.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Flexio Common driver source file.
*   @details
*
*   @addtogroup FLEXIO_IP_DRIVER FLEXIO IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Mcl_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_VENDOR_ID_C                      43
#define FLEXIO_MCL_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_MCL_IP_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_MCL_IP_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_MCL_IP_SW_MAJOR_VERSION_C               5
#define FLEXIO_MCL_IP_SW_MINOR_VERSION_C               0
#define FLEXIO_MCL_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Flexio_Mcl_Ip.c file and Flexio_Mcl_Ip.h file are of the same vendor */
#if (FLEXIO_MCL_IP_VENDOR_ID_C != FLEXIO_MCL_IP_VENDOR_ID)
    #error "Flexio_Mcl_Ip.c and Flexio_Mcl_Ip.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip.c file and Flexio_Mcl_Ip.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_AR_RELEASE_MINOR_VERSION_C != FLEXIO_MCL_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_MCL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip.c and Flexio_Mcl_Ip.h are different"
#endif

/* Check if Flexio_Mcl_Ip.c file and Flexio_Mcl_Ip.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_SW_MAJOR_VERSION_C != FLEXIO_MCL_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_SW_MINOR_VERSION_C != FLEXIO_MCL_IP_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_SW_PATCH_VERSION_C != FLEXIO_MCL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip.c and Flexio_Mcl_Ip.h are different"
#endif

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

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

/* Table of base addresses for FLEXIO instances. */
FLEXIO_Type * const Flexio_Ip_paxBase[FLEXIO_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"


#define MCL_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "Mcl_MemMap.h"

/* Table of base addresses for FLEXIO instances. */
boolean Flexio_Ip_baIpIsInitialized[FLEXIO_INSTANCE_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "Mcl_MemMap.h"

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

Flexio_Ip_CommonStatusType Flexio_Mcl_Ip_InitDevice(const Flexio_Ip_InstanceConfigType * const pFlexioInitType)
{
    FLEXIO_Type *BaseAddr;
    Flexio_Ip_CommonStatusType Status = FLEXIO_IP_COMMON_STATUS_SUCCESS;
    uint8 LocInstance =  pFlexioInitType->instance;
    boolean LocDebugEnable = pFlexioInitType->debugEnable;

    BaseAddr = Flexio_Ip_paxBase[LocInstance];

    if(Flexio_Ip_baIpIsInitialized[LocInstance] == TRUE)
    {
        Status = FLEXIO_IP_COMMON_STATUS_FAIL;
    }
    /* Reset FlexIO module */
    Flexio_Mcl_Ip_Init(BaseAddr);
    /* Enable module */
    Flexio_Mcl_Ip_SetEnable(BaseAddr, TRUE);

    Flexio_Mcl_Ip_SetDebugEnable(BaseAddr, LocDebugEnable);

    Flexio_Ip_baIpIsInitialized[LocInstance] = TRUE;

    (void)Status;
    return Status;
}


/*
 * Function Name : FLEXIO_DRV_DeinitDevice
 * Description   : De-initializes the FlexIO device
*/
void Flexio_Mcl_Ip_DeinitDevice(uint32 instance)
{
    FLEXIO_Type *BaseAddr;

    BaseAddr = Flexio_Ip_paxBase[instance];
    /* Reset FlexIO module */
    Flexio_Mcl_Ip_Init(BaseAddr);
    Flexio_Ip_baIpIsInitialized[instance] = FALSE;
}


#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
