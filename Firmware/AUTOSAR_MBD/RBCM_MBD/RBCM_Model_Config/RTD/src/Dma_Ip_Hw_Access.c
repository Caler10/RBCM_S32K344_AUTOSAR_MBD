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
*   @file    Dma_Ip_Hw_Access.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver source file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Dma_Ip_Hw_Access.h"

#if (STD_ON == DMA_IP_IS_AVAILABLE)

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
#include "Dma_Ip_Hwv3_AccessInline.h"
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_HW_ACCESS_VENDOR_ID_C                       43
#define DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C        4
#define DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C        7
#define DMA_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C     0
#define DMA_IP_HW_ACCESS_SW_MAJOR_VERSION_C                5
#define DMA_IP_HW_ACCESS_SW_MINOR_VERSION_C                0
#define DMA_IP_HW_ACCESS_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Dma_Ip_Hw_Access.c file and Mcal header file are of the same Autosar version */
#if ((DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Hw_Access.c and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Dma_Ip_Hw_Access.c file and Dma_Ip_Hw_Access.h file are of the same vendor */
#if (DMA_IP_HW_ACCESS_VENDOR_ID_C != DMA_IP_HW_ACCESS_VENDOR_ID)
    #error "Dma_Ip_Hw_Access.c and Dma_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if Dma_Ip_Hw_Access.c file and Dma_Ip_Hw_Access.h file are of the same Autosar version */
#if ((DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Hw_Access.c and Dma_Ip_Hw_Access.h are different"
#endif

/* Check if Dma_Ip_Hw_Access.c file and Dma_Ip_Hw_Access.h file are of the same Software version */
#if ((DMA_IP_HW_ACCESS_SW_MAJOR_VERSION_C != DMA_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (DMA_IP_HW_ACCESS_SW_MINOR_VERSION_C != DMA_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (DMA_IP_HW_ACCESS_SW_PATCH_VERSION_C != DMA_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Hw_Access.c and Dma_Ip_Hw_Access.h are different"
#endif


#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
/* Check if Dma_Ip_Hw_Access.c file and Dma_Ip_Hwv3_AccessInline.h file are of the same vendor */
#if (DMA_IP_HW_ACCESS_VENDOR_ID_C != DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID)
    #error "Dma_Ip_Hw_Access.c and Dma_Ip_Hwv3_AccessInline.h have different vendor ids"
#endif

/* Check if Dma_Ip_Hw_Access.c file and Dma_Ip_Hwv3_AccessInline.h file are of the same Autosar version */
#if ((DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C != DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Hw_Access.c and Dma_Ip_Hwv3_AccessInline.h are different"
#endif

/* Check if Dma_Ip_Hw_Access.c file and Dma_Ip_Hwv3_AccessInline.h file are of the same Software version */
#if ((DMA_IP_HW_ACCESS_SW_MAJOR_VERSION_C != DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION) || \
     (DMA_IP_HW_ACCESS_SW_MINOR_VERSION_C != DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION) || \
     (DMA_IP_HW_ACCESS_SW_PATCH_VERSION_C != DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Hw_Access.c and Dma_Ip_Hwv3_AccessInline.h are different"
#endif
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */



#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#define DMA_IP_AE_START_ADDRESS            ((uint32)0x0U)

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
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    #if (STD_ON == DMA_IP_TCD_NOT_ALIGNED)
        Dma_Ip_Hwv3ChTcdRegType      * const g_ptHwChTcdPtrArray[DMA_IP_TCD_NOF_HWV3_CH_INST][DMA_IP_TCD_NOF_HWV3_CH] = DMA_IP_TCD_PTR_ARRAY;
    #else
        Dma_Ip_Hwv3TcdArrayType      * const g_ptHwv3BaseTcdPtrArray[DMA_IP_TCD_NOF_HWV3_CH_INST] = DMA_IP_TCD_BASE_PTRS;
    #endif
static Dma_Ip_Hwv3InstRegType  * const Dma_Ip_paxHwv3BaseInst[DMA_IP_DMA_NOF_HWV3_INST] = DMA_IP_DMA_BASE_PTRS;
#endif /* STD_ON == DMA_IP_HWV3_IS_AVAILABLE */


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if ((DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_BUFFERED_WRITES_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_PREEMPTION_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_SWAP_SIZE_IS_AVAILABLE == STD_OFF))
static void HwAccDmaCh_SetGlobalDummyFunction(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
#endif
#if ((DMA_IP_STORE_DST_ADDR_IS_AVAILABLE == STD_OFF) || (DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE == STD_OFF) || (DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE == STD_OFF))
static void HwAccDmaCh_SetTransferDummyFunction(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#endif
#if (DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE == STD_OFF) 
static void HwAccDmaCh_BandwithControlrDummyFunction(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#endif
#if ((DMA_IP_STORE_DST_ADDR_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_DMACRC_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_SECURITY_LEVEL_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE == STD_OFF))
static void HwAccDmaCh_GetParamDummyFunction(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#endif

static void hwAccDmaInst_CmdCancelTransfer(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst);
static void hwAccDmaInst_CmdCancelTransferWithError(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst);
static void hwAccDmaInst_CmdHalt(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst);
static void hwAccDmaInst_CmdResume(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst);

static void HwAccDmaCh_CmdSetHwRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void HwAccDmaCh_CmdClearHwRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void HwAccDmaCh_CmdSetSwRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void HwAccDmaCh_CmdClearDone(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void HwAccDmaCh_CmdClearError(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);
static void HwAccDmaCh_CmdClearInterruptStatus(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh);

#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_EnMasterIdReplication(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
#endif /* STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE */
#if (STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_EnBufferedWrites(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
#endif /* STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE */
static void HwAccDmaCh_SetRequest_EnRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
static void HwAccDmaCh_SetInterrupt_EnError(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
#if (STD_ON == DMA_IP_SWAP_SIZE_IS_AVAILABLE)
static void HwAccDmaCh_SetSwapSize(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
#endif
#if (STD_ON == DMA_IP_GROUP_PRIORITY_IS_AVAILABLE)
static void HwAccDmaCh_SetPriority_Group(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
#endif /* STD_ON == DMA_IP_GROUP_PRIORITY_IS_AVAILABLE */
static void HwAccDmaCh_SetPriority_Level(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
static void HwAccDmaCh_SetPriority_EnPreemption(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
static void HwAccDmaCh_SetPriority_DisPreempt(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue);
static void HwAccDmaCh_SetSource_Address(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetSource_SignedOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetSource_LastAddrAdj(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetSource_TransferSize(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetSource_Modulo(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetDestination_Address(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetDestination_SignedOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetDestination_LastAddrAdj(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetDestination_TransferSize(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetDestination_Modulo(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMinorLoop_enSrcOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMinorLoop_enDstOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMinorLoop_Offset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMinorLoop_EnLink(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMinorLoop_LogicLinkCh(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMinorLoop_Size(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMajorLoop_EnLink(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMajorLoop_LogicLinkCh(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetMajorLoop_Count(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_StoreDestinationAddress(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#endif
static void HwAccDmaCh_SetControl_EnStart(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetControl_EnMajor(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetControl_EnHalfMajor(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
static void HwAccDmaCh_SetControl_DisAutoHwRequest(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_EnEndOfPacketSignal(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#endif
#if (STD_ON == DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_BandwidthControl(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#endif
#if (STD_ON == DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_TransferModeControl(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue);
#endif /* (STD_ON == DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE) */

static void HwAccDmaCh_GetSourceAddress(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
static void HwAccDmaCh_GetDestinationAddress(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
static void HwAccDmaCh_GetBeginIterCount(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
static void HwAccDmaCh_GetCurrentIterCount(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
static void HwAccDmaCh_GetStoreDstAddress(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#endif /* STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE */
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
static void HwAccDmaCh_GetMasterId(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#endif /* STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE */
static void HwAccDmaCh_GetIntMajor(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
static void HwAccDmaCh_GetIntHalfMajor(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#if (STD_ON == DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE)
void HwAccDmaCh_GetTransactionsType(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#endif /* STD_ON == DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE */
#if (STD_ON == DMA_IP_SECURITY_LEVEL_IS_AVAILABLE)
void HwAccDmaCh_GetSecurityLevel(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#endif /* STD_ON == DMA_IP_SECURITY_LEVEL_IS_AVAILABLE */
#if (STD_ON == DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE)
void HwAccDmaCh_GetProtectionLevel(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue);
#endif /* STD_ON == DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE */

/*==================================================================================================
 *  VIRTUAL ADDRESS MAPPING FUNCTIONS
==================================================================================================*/
#if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
static uint32 HwAccDma_SetVirtualToPhysicalAddress(const uint32 VirtualAddr);
static uint32 HwAccDma_SetPhysicalToVirtualAddress(const uint32 PhysicalAddr);
#endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
 * SET PARAM DUMMY FUNCTION
==================================================================================================*/
#if ((DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_BUFFERED_WRITES_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_PREEMPTION_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_SWAP_SIZE_IS_AVAILABLE == STD_OFF))
static void HwAccDmaCh_SetGlobalDummyFunction(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    /* Set global dummy function */
    (void)LocHwVers;
    (void)LocHwInst;
    (void)LocHwCh;
    (void)LocValue;
    DMA_IP_DEV_ASSERT(FALSE);
}
#endif

#if ((DMA_IP_STORE_DST_ADDR_IS_AVAILABLE == STD_OFF) || (DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE == STD_OFF) || (DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE == STD_OFF))
static void HwAccDmaCh_SetTransferDummyFunction(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    /* Set transfer dummy function */
    (void)LocHwVers;
    (void)LocValue;
    DMA_IP_DEV_ASSERT(FALSE);
    /*The bellow code line (pxLocTcd->reg_CSR = (uint16)0U;)is only to avoid Misra rule 8.13. It will be not implemented in runtime of program
     *because a failure assert will be raised by above code line (DMA_IP_DEV_ASSERT(FALSE);)*/
    pxLocTcd->reg_CSR = (uint16)0U;
}
#endif

#if (DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE == STD_OFF) 
static void HwAccDmaCh_BandwithControlrDummyFunction(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    /* Set transfer dummy function */
    (void)LocHwVers;
    (void)LocValue;
    DMA_IP_DEV_ASSERT(FALSE);
    /*The bellow code line (pxLocTcd->reg_CSR = (uint16)0U;)is only to avoid Misra rule 8.13. It will be not implemented in runtime of program
     *because a failure assert will be raised by above code line (DMA_IP_DEV_ASSERT(FALSE);)*/
    pxLocTcd->reg_CSR = (uint16)0U;
}
#endif

/*==================================================================================================
 * GET PARAM DUMMY FUNCTION
==================================================================================================*/
#if ((DMA_IP_STORE_DST_ADDR_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_DMACRC_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_SECURITY_LEVEL_IS_AVAILABLE == STD_OFF) || \
     (DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE == STD_OFF))
static void HwAccDmaCh_GetParamDummyFunction(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    /* Get parameter dummy function */
    (void)LocHwVers;
    (void)LocHwInst;
    (void)LocHwCh;
    DMA_IP_DEV_ASSERT(FALSE);
    /*The bellow code line (*retValue = 0U;)is only to avoid Misra rule 8.13. It will be not implemented in runtime of program
     *because a failure assert will be raised by above code line (DMA_IP_DEV_ASSERT(FALSE);)*/
    *retValue = 0U;
}
#endif

/*==================================================================================================
 * DMA INSTANCE CONFIG FUNCTIONS
==================================================================================================*/
void HwAccDmaInst_SetConfig(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst, const Dma_Ip_LogicInstanceConfigType * const pxLocInstConfig)
{
    uint32 LocHwVers = pxLocLogicInst->HwVersId;
    uint32 LocHwInst = pxLocLogicInst->HwInstId;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaInst_SetConfig(Dma_Ip_paxHwv3BaseInst[LocHwInst], pxLocInstConfig);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}


/*==================================================================================================
 * DMA INSTANCE CMD FUNCTIONS
==================================================================================================*/
static void hwAccDmaInst_CmdCancelTransfer(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst)
{
    uint32 LocHwVers = pxLocLogicInst->HwVersId;
    uint32 LocHwInst = pxLocLogicInst->HwInstId;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaInst_CmdCancelTransfer(Dma_Ip_paxHwv3BaseInst[LocHwInst]);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void hwAccDmaInst_CmdCancelTransferWithError(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst)
{
    uint32 LocHwVers = pxLocLogicInst->HwVersId;
    uint32 LocHwInst = pxLocLogicInst->HwInstId;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaInst_CmdCancelTransferWithError(Dma_Ip_paxHwv3BaseInst[LocHwInst]);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void hwAccDmaInst_CmdHalt(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst)
{
    uint32 LocHwVers = pxLocLogicInst->HwVersId;
    uint32 LocHwInst = pxLocLogicInst->HwInstId;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaInst_CmdHalt(Dma_Ip_paxHwv3BaseInst[LocHwInst]);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void hwAccDmaInst_CmdResume(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst)
{
    uint32 LocHwVers = pxLocLogicInst->HwVersId;
    uint32 LocHwInst = pxLocLogicInst->HwInstId;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaInst_CmdResume(Dma_Ip_paxHwv3BaseInst[LocHwInst]);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

/*==================================================================================================
 * DMA INSTANCE CMD - FUNCTION POINTER
==================================================================================================*/
void HwAccDmaInst_SetCommand(const uint32 Command, const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst)
{
    static void (* const fpHwAcc_DmaInst_Command[])(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst) =
    {
        &hwAccDmaInst_CmdCancelTransfer,
        &hwAccDmaInst_CmdCancelTransferWithError,
        &hwAccDmaInst_CmdHalt,
        &hwAccDmaInst_CmdResume,
    };
    fpHwAcc_DmaInst_Command[Command](pxLocLogicInst);
}

/*==================================================================================================
 * DMA INSTANCE STATUS FUNCTION
==================================================================================================*/
void HwAccDmaInst_GetStatus(const Dma_Ip_LogicInstanceIdType * const pxLocLogicInst, Dma_Ip_LogicInstanceStatusType * const Status)
{
    uint32 LocHwVers = pxLocLogicInst->HwVersId;
    uint32 LocHwInst = pxLocLogicInst->HwInstId;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            MCAL_FAULT_INJECTION_POINT(MCL_GET_INSTANCE_HWV3_ERROR_FAULT_INJECTION);
            hwv3AccInlineDmaInst_GetErrorStatus(Dma_Ip_paxHwv3BaseInst[LocHwInst], &Status->Errors);
            hwv3AccInlineDmaInst_GetActiveIdStatus(Dma_Ip_paxHwv3BaseInst[LocHwInst], &Status->ActiveId);
            hwv3AccInlineDmaInst_GetActiveStatus(Dma_Ip_paxHwv3BaseInst[LocHwInst], &Status->Active);
            hwv3AccInlineDmaInst_GetEdmaVersion(Dma_Ip_paxHwv3BaseInst[LocHwInst], &Status->Version);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

/*==================================================================================================
 * DMA CHANNEL CMD FUNCTIONS
==================================================================================================*/
static void HwAccDmaCh_CmdSetHwRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdSetRequest(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_CmdClearHwRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdClearRequest(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_CmdSetSwRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdSwReqStart(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_CmdClearDone(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdClearDone(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_CmdClearError(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdClearError(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_CmdClearInterruptStatus(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdClearInterruptStatus(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

/*==================================================================================================
 * DMA CHANNEL CMD - FUNCTION POINTER
==================================================================================================*/
void HwAccDmaCh_SetCommand(const uint32 Command, const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh)
{
    static void (* const fpHwAcc_DmaCh_Command[])(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh) =
    {
        &HwAccDmaCh_CmdSetHwRequest,
        &HwAccDmaCh_CmdClearHwRequest,
        &HwAccDmaCh_CmdSetSwRequest,
        &HwAccDmaCh_CmdClearDone,
        &HwAccDmaCh_CmdClearError,
        &HwAccDmaCh_CmdClearInterruptStatus,
    };
    fpHwAcc_DmaCh_Command[Command](LocHwVers, LocHwInst, LocHwCh);
}

/*==================================================================================================
 * DMA CHANNEL STATUS FUNCTIONS
==================================================================================================*/
void HwAccDmaCh_GetStatus(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, Dma_Ip_LogicChannelStatusType * const pChStatus)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetActiveStatus(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), &pChStatus->Active);
            hwv3AccInlineDmaCh_GetDoneStatus(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), &pChStatus->Done);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

void HwAccDmaCh_GetStatus_Error(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const pLocError)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            MCAL_FAULT_INJECTION_POINT(MCL_GET_CHANNEL_HWV3_ERROR_FAULT_INJECTION);
            hwv3AccInlineDmaCh_GetErrorStatus(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), pLocError);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

/*==================================================================================================
 * DMA CHANNEL GLOBAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_EnMasterIdReplication(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_EnMasterIdReplication(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif /* STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE */

#if (STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_EnBufferedWrites(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_EnBufferedWrites(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif /* STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE */

static void HwAccDmaCh_SetRequest_EnRequest(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetRequest_EnHwRequest(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetInterrupt_EnError(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_CmdClearError(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
            hwv3AccInlineDmaCh_SetInterrupt_EnError(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

#if (STD_ON == DMA_IP_SWAP_SIZE_IS_AVAILABLE)
static void HwAccDmaCh_SetSwapSize(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
           DMA_IP_DEV_ASSERT(FALSE);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

#if (STD_ON == DMA_IP_GROUP_PRIORITY_IS_AVAILABLE)
static void HwAccDmaCh_SetPriority_Group(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetPriority_Group((volatile uint32 *)&Dma_Ip_paxHwv3BaseInst[LocHwInst]->reg_CH_GRPRI[LocHwCh], LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif /* STD_ON == DMA_IP_GROUP_PRIORITY_IS_AVAILABLE */

static void HwAccDmaCh_SetPriority_Level(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetPriority_Level(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

#if (STD_ON == DMA_IP_PREEMPTION_IS_AVAILABLE)
static void HwAccDmaCh_SetPriority_EnPreemption(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetPriority_EnPreemption(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif /* #if (STD_ON == DMA_IP_PREEMPTION_IS_AVAILABLE) */

#if (STD_ON == DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE)
static void HwAccDmaCh_SetPriority_DisPreempt(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetPriority_DisPreempt(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif /* #if (STD_ON == DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE) */

/*==================================================================================================
 * DMA CHANNEL SET GLOBAL PARAMETER - FUNCTION POINTER
==================================================================================================*/
void HwAccDmaCh_SetGlobalParam(const uint32 Parameter, const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue)
{
    static void (* const fpHwAcc_DmaCh_SetGlobalParam[])(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, const uint32 LocValue) =
    {
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
        &HwAccDmaCh_SetControl_EnMasterIdReplication,
#else
        &HwAccDmaCh_SetGlobalDummyFunction,
#endif
#if (STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE)
        &HwAccDmaCh_SetControl_EnBufferedWrites,
#else
        &HwAccDmaCh_SetGlobalDummyFunction,
#endif
        &HwAccDmaCh_SetRequest_EnRequest,
        &HwAccDmaCh_SetInterrupt_EnError,
#if (STD_ON == DMA_IP_GROUP_PRIORITY_IS_AVAILABLE)
        &HwAccDmaCh_SetPriority_Group,
#else
        &HwAccDmaCh_SetGlobalDummyFunction,
#endif /* STD_ON == DMA_IP_GROUP_PRIORITY_IS_AVAILABLE */
        &HwAccDmaCh_SetPriority_Level,
#if (STD_ON == DMA_IP_PREEMPTION_IS_AVAILABLE)
        &HwAccDmaCh_SetPriority_EnPreemption,
#else
        &HwAccDmaCh_SetGlobalDummyFunction,
#endif
#if (STD_ON == DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE)
        &HwAccDmaCh_SetPriority_DisPreempt,
#else
        &HwAccDmaCh_SetGlobalDummyFunction,
#endif
#if (STD_ON == DMA_IP_SWAP_SIZE_IS_AVAILABLE)
        &HwAccDmaCh_SetSwapSize,
#else
        &HwAccDmaCh_SetGlobalDummyFunction,
#endif /* #if (STD_ON == DMA_IP_SWAP_SIZE_IS_AVAILABLE) */
    };
    fpHwAcc_DmaCh_SetGlobalParam[Parameter](LocHwVers, LocHwInst, LocHwCh, LocValue);
}

/*==================================================================================================
 * DMA CHANNEL TRANSFER FUNCTIONS
==================================================================================================*/
static void HwAccDmaCh_SetSource_Address(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
        #if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
            hwv3AccInlineDmaCh_SetSource_Address(pxLocTcd, HwAccDma_SetVirtualToPhysicalAddress(LocValue));
        #else
            hwv3AccInlineDmaCh_SetSource_Address(pxLocTcd, LocValue);
        #endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetSource_SignedOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
    #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetSource_SignedOffset(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetSource_LastAddrAdj(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetAuxiliary_EnDestinationStoreAddress(pxLocTcd, FALSE);
            hwv3AccInlineDmaCh_SetSource_SignedLastAddrAdj(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}


static void HwAccDmaCh_SetSource_TransferSize(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetSource_TransferSize(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetSource_Modulo(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetSource_Modulo(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetDestination_Address(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
        #if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
            hwv3AccInlineDmaCh_SetDestination_Address(pxLocTcd, HwAccDma_SetVirtualToPhysicalAddress(LocValue));
        #else
            hwv3AccInlineDmaCh_SetDestination_Address(pxLocTcd, LocValue);
        #endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}


static void HwAccDmaCh_SetDestination_SignedOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetDestination_SignedOffset(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetDestination_LastAddrAdj(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetDestination_LastAddrAdj(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}


static void HwAccDmaCh_SetDestination_TransferSize(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetDestination_TransferSize(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetDestination_Modulo(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetDestination_Modulo(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMinorLoop_enSrcOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMinorLoop_enSrcOffset(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMinorLoop_enDstOffset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMinorLoop_enDstOffset(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
static void HwAccDmaCh_SetMinorLoop_Offset(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMinorLoop_SignedOffset(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMinorLoop_EnLink(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMinorLoop_EnLink(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMinorLoop_LogicLinkCh(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    uint32 hwLinkCh = Dma_Ip_ConvertLogicChToHwCh(LocValue);

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMinorLoop_LinkCh(pxLocTcd, hwLinkCh);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMinorLoop_Size(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMinorLoop_Size(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMajorLoop_EnLink(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMajorLoop_EnLink(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMajorLoop_LogicLinkCh(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)      
{
    uint32 hwLinkCh = Dma_Ip_ConvertLogicChToHwCh(LocValue);

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMajorLoop_LinkCh(pxLocTcd, hwLinkCh);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetMajorLoop_Count(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetMajorLoop_Count(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_StoreDestinationAddress(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
        #if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
            hwv3AccInlineDmaCh_SetControl_StoreDestinationAddress(pxLocTcd, HwAccDma_SetVirtualToPhysicalAddress(LocValue));
        #else
            hwv3AccInlineDmaCh_SetControl_StoreDestinationAddress(pxLocTcd, LocValue);
        #endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
            hwv3AccInlineDmaCh_SetAuxiliary_EnDestinationStoreAddress(pxLocTcd, TRUE);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

static void HwAccDmaCh_SetControl_EnStart(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_EnStart(pxLocTcd, ((LocValue != 0U) ? TRUE : FALSE));
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetControl_EnMajor(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_EnMajor(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetControl_EnHalfMajor(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_EnHalfMajor(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_SetControl_DisAutoHwRequest(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_DisAutoHwRequest(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_EnEndOfPacketSignal(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_EnEndOfPacketSignal(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

#if (STD_ON == DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_BandwidthControl(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_BandwidthControl(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

#if (STD_ON == DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE)
static void HwAccDmaCh_SetControl_TransferModeControl(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif /* (STD_ON == DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE) */

/*==================================================================================================
 * DMA CHANNEL SET TRANSFER PARAMETER - FUNCTION POINTER
==================================================================================================*/
void HwAccDmaCh_SetTransferParam(const uint32 Parameter, const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue)
{
    static void (* const fpHwAcc_DmaCh_SetTransferParam[])(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, const uint32 LocValue) =       
    {
        &HwAccDmaCh_SetSource_Address,
        &HwAccDmaCh_SetSource_SignedOffset,
        &HwAccDmaCh_SetSource_LastAddrAdj,
        &HwAccDmaCh_SetSource_TransferSize,
        &HwAccDmaCh_SetSource_Modulo,
        &HwAccDmaCh_SetDestination_Address,
        &HwAccDmaCh_SetDestination_SignedOffset,
        &HwAccDmaCh_SetDestination_LastAddrAdj,
        &HwAccDmaCh_SetDestination_TransferSize,
        &HwAccDmaCh_SetDestination_Modulo,
        &HwAccDmaCh_SetMinorLoop_enSrcOffset,
        &HwAccDmaCh_SetMinorLoop_enDstOffset,
        &HwAccDmaCh_SetMinorLoop_Offset,
        &HwAccDmaCh_SetMinorLoop_EnLink,
        &HwAccDmaCh_SetMinorLoop_LogicLinkCh,
        &HwAccDmaCh_SetMinorLoop_Size,
        &HwAccDmaCh_SetMajorLoop_EnLink,
        &HwAccDmaCh_SetMajorLoop_LogicLinkCh,
        &HwAccDmaCh_SetMajorLoop_Count,
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
        &HwAccDmaCh_SetControl_StoreDestinationAddress,
#else
        &HwAccDmaCh_SetTransferDummyFunction,
#endif
        &HwAccDmaCh_SetControl_EnStart,
        &HwAccDmaCh_SetControl_EnMajor,
        &HwAccDmaCh_SetControl_EnHalfMajor,
        &HwAccDmaCh_SetControl_DisAutoHwRequest,
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
        &HwAccDmaCh_SetControl_EnEndOfPacketSignal,
#else
        &HwAccDmaCh_SetTransferDummyFunction,
#endif
#if (STD_ON == DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE)
        &HwAccDmaCh_SetControl_BandwidthControl,
#else
        &HwAccDmaCh_BandwithControlrDummyFunction,
#endif
#if (STD_ON == DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE)
        &HwAccDmaCh_SetControl_TransferModeControl,
#else
        &HwAccDmaCh_SetTransferDummyFunction,
#endif
    };
    fpHwAcc_DmaCh_SetTransferParam[Parameter](LocHwVers, pxLocTcd, LocValue);
}


/*==================================================================================================
 * DMA CHANNEL GET PARAMETER
==================================================================================================*/
static void HwAccDmaCh_GetSourceAddress(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    uint32 LocPhysicalAddress;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetSourceAddress(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), &LocPhysicalAddress);
        #if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
            *retValue = HwAccDma_SetPhysicalToVirtualAddress(LocPhysicalAddress);
        #else
            *retValue = LocPhysicalAddress;
        #endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_GetDestinationAddress(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    uint32 LocPhysicalAddress;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetDestinationAddress(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), &LocPhysicalAddress);
        #if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
            *retValue = HwAccDma_SetPhysicalToVirtualAddress(LocPhysicalAddress);
        #else
            *retValue = LocPhysicalAddress;
        #endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_GetBeginIterCount(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetBeginIterCount(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), retValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_GetCurrentIterCount(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetCurrentIterCount(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), retValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
static void HwAccDmaCh_GetStoreDstAddress(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    Dma_Ip_uintPtrType LocPhysicalAddress;

    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetStoreDstAddress(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), &LocPhysicalAddress);
        #if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
            *retValue = *((Dma_Ip_uintPtrType*)((Dma_Ip_uintPtrType)HwAccDma_SetPhysicalToVirtualAddress(LocPhysicalAddress)));
        #else
            *retValue = *((Dma_Ip_uintPtrType*)LocPhysicalAddress);
        #endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
static void HwAccDmaCh_GetMasterId(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetMasterId(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), retValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

static void HwAccDmaCh_GetIntMajor(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetIntMajor(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), retValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

static void HwAccDmaCh_GetIntHalfMajor(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetIntHalfMajor(&DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh), retValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}


#if (STD_ON == DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE)
void HwAccDmaCh_GetTransactionsType(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

#if (STD_ON == DMA_IP_SECURITY_LEVEL_IS_AVAILABLE)
void HwAccDmaCh_GetSecurityLevel(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

#if (STD_ON == DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE)
void HwAccDmaCh_GetProtectionLevel(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_GetProtectionLevel(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh), retValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}
#endif

/*==================================================================================================
 * DMA CHANNEL GET PARAMETER - FUNCTION POINTER
==================================================================================================*/
void HwAccDmaCh_GetParam(const uint32 Parameter, const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue)
{
    static void (* const fpHwAcc_DmaCh_GetParam[])(const uint32 LocHwVers, const uint32 LocHwInst, const uint32 LocHwCh, uint32 * const retValue) =
    {
        &HwAccDmaCh_GetSourceAddress,
        &HwAccDmaCh_GetDestinationAddress,
        &HwAccDmaCh_GetBeginIterCount,
        &HwAccDmaCh_GetCurrentIterCount,
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
        &HwAccDmaCh_GetStoreDstAddress,
#else
        &HwAccDmaCh_GetParamDummyFunction,
#endif
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
        &HwAccDmaCh_GetMasterId,
#else
        &HwAccDmaCh_GetParamDummyFunction,
#endif
        &HwAccDmaCh_GetIntMajor,
        &HwAccDmaCh_GetIntHalfMajor,
        &HwAccDmaCh_GetParamDummyFunction,
#if (STD_ON == DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE)
        &HwAccDmaCh_GetTransactionsType,
#else
        &HwAccDmaCh_GetParamDummyFunction,
#endif
#if (STD_ON == DMA_IP_SECURITY_LEVEL_IS_AVAILABLE)
        &HwAccDmaCh_GetSecurityLevel,
#else
        &HwAccDmaCh_GetParamDummyFunction,
#endif
#if (STD_ON == DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE)
        &HwAccDmaCh_GetProtectionLevel,
#else
        &HwAccDmaCh_GetParamDummyFunction,
#endif
    };
    fpHwAcc_DmaCh_GetParam[Parameter](LocHwVers, LocHwInst, LocHwCh, retValue);
}

/*==================================================================================================
 *  DMA LOGIC CHANNEL SOFTWARE TCD -> LOAD WITH CONFIGURATION
==================================================================================================*/
void HwAccDmaCh_LoadConfigIntoSoftwareTcd(uint32 HwVersId, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather, const uint32 ElementId, const boolean NotLastElement)
{
#if (STD_ON == DMA_IP_HWV2_IS_AVAILABLE)
    uint32 hwLinkCh;
#endif /* STD_ON == DMA_IP_HWV2_IS_AVAILABLE */

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == HwVersId)
    {
        /* Enable SGA bit and set SGA next software TCD address */
        if(TRUE == NotLastElement)
        {
            hwv3AccInlineDmaCh_SetControl_ScatterGatherAddress(pxLocScatterGather->Stcd, (Dma_Ip_uintPtrType)pxLocScatterGather->NextConfig->Stcd);
        }
        else
        {
             hwv3AccInlineDmaCh_SetControl_ScatterGatherAddress(pxLocScatterGather->Stcd, (uint32)0U);
        }
        hwv3AccInlineDmaCh_SetAuxiliary_EnScatterGatherProcessing(pxLocScatterGather->Stcd, NotLastElement);
        if(NULL_PTR != pxLocScatterGather->TransferConfig)
        {
            hwv3AccInlineDmaCh_SetTCDParams(pxLocScatterGather->Stcd, pxLocScatterGather, ElementId);
        }
    }
    else
    {
        /* Do Nothing */
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

/*==================================================================================================
 *  DMA LOGIC CHANNEL HARDWARE TCD -> LOAD WITH SOFTWARE TCD
==================================================================================================*/
void HwAccDmaCh_LoadSoftwareTcdIntoHardwareTcd(const Dma_Ip_LogicChannelIdType * const pxLocLogicCh, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    uint32 LocHwVers = pxLocLogicCh->HwVersId;
    uint32 LocHwInst = pxLocLogicCh->HwInstId;
    uint32 LocHwCh   = pxLocLogicCh->HwChId;

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
    if(DMA_IP_HARDWARE_VERSION_3 == LocHwVers)
    {
        /* Force channel to retire: Clear DONE bit in order to write the ESG bit */
        hwv3AccInlineDmaCh_CmdClearDone(&DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh));
        /* Update Hardware TCD */
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_SADDR = pxLocScatterGather->Stcd->reg_SADDR;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_SOFF = pxLocScatterGather->Stcd->reg_SOFF;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_ATTR = pxLocScatterGather->Stcd->reg_ATTR;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_NBYTES.reg_MLOFFYES = pxLocScatterGather->Stcd->reg_NBYTES.reg_MLOFFYES;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_SLAST_SDA = pxLocScatterGather->Stcd->reg_SLAST_SDA;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_DADDR = pxLocScatterGather->Stcd->reg_DADDR;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_DOFF = pxLocScatterGather->Stcd->reg_DOFF;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_CITER.reg_ELINKYES = pxLocScatterGather->Stcd->reg_CITER.reg_ELINKYES;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_DLAST_SGA = pxLocScatterGather->Stcd->reg_DLAST_SGA;
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_BITER.reg_ELINKYES = pxLocScatterGather->Stcd->reg_BITER.reg_ELINKYES;
        /* CSR shall be loaded last due to Start bit */
        DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_CSR = pxLocScatterGather->Stcd->reg_CSR;
    }
    else
    {
        /* Do Nothing */
    }
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

}

/*==================================================================================================
 *  IP INTERNAL FUNCTIONS
==================================================================================================*/
void HwAccDmaCh_SetControl_ScatterGatherAddress(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, uint32 LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetControl_ScatterGatherAddress(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}

void HwAccDmaCh_SetControl_EnScatterGatherProcessing(const uint32 LocHwVers, Dma_Ip_TcdRegType * pxLocTcd, boolean LocValue)
{
    switch (LocHwVers)
    {
#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
        case DMA_IP_HARDWARE_VERSION_3:
            hwv3AccInlineDmaCh_SetAuxiliary_EnScatterGatherProcessing(pxLocTcd, LocValue);
        break;
#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */

        default:
            DMA_IP_DEV_ASSERT(FALSE);
        break;
    }
}


/*==================================================================================================
 *  VIRTUAL ADDRESS MAPPING FUNCTIONS
==================================================================================================*/
#if (STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE)
static uint32 HwAccDma_SetVirtualToPhysicalAddress(const uint32 VirtualAddr)
{
    uint32 PhysicAddr = VirtualAddr;
    uint8 SectionIdx;
    const Dma_Ip_InitType * ConfigPtr;

    /* Get the initial pointer */
    ConfigPtr = Dma_Ip_GetInitPtr();
    for(SectionIdx = 0; SectionIdx < ConfigPtr->pxVirtualMemoryConfig->NumOfSection; SectionIdx++)
    {
        if((VirtualAddr >= (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].VirtualAddrStart) && (VirtualAddr < (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].VirtualAddrEnd))
        {
            /* Convert from Virtual address to Physical address */
            PhysicAddr = (VirtualAddr - (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].VirtualAddrStart) + (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].PhysicalAddrStart;
        }
    }
    return PhysicAddr;
}

static uint32 HwAccDma_SetPhysicalToVirtualAddress(const uint32 PhysicalAddr)
{
    uint32 VirtualAddr = PhysicalAddr;
    uint8 SectionIdx;
    const Dma_Ip_InitType * ConfigPtr;

    /* Get the initial pointer */
    ConfigPtr = Dma_Ip_GetInitPtr();
    for(SectionIdx = 0; SectionIdx < ConfigPtr->pxVirtualMemoryConfig->NumOfSection; SectionIdx++)
    {
        if((PhysicalAddr >= (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].PhysicalAddrStart) && (PhysicalAddr < (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].PhysicalAddrEnd))
        {
            /* Convert from Physical address to Virtual address */
            VirtualAddr = (PhysicalAddr - (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].PhysicalAddrStart) + (*(ConfigPtr->pxVirtualMemoryConfig->pSectionConfig))[SectionIdx].VirtualAddrStart;
        }
    }
    return VirtualAddr;
}
#endif /* STD_ON == DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE */

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

