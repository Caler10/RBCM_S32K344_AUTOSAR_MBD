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

/* Prevention from multiple including the same header */
#ifndef DMA_IP_HWV3_ACCESSINLINE_H_
#define DMA_IP_HWV3_ACCESSINLINE_H_

/**
*   @file    Dma_Ip_Hwv3_AccessInline.h
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
#include "Dma_Ip.h"
#include "Dma_Ip_Devassert.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID                       43
#define DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION                5
#define DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION                0
#define DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal header file are of the same Autosar version */
#if ((DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Hwv3_AccessInline.h and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Dma_Ip.h file are of the same vendor */
#if (DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID != DMA_IP_VENDOR_ID)
    #error "DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip.h file are of the same Autosar version */
#if ((DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION != DMA_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip.h file are of the same Software version */
#if ((DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION != DMA_IP_SW_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION != DMA_IP_SW_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION != DMA_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip.h are different"
#endif

/* Check if header file and Dma_Ip_Devassert.h file are of the same vendor */
#if (DMA_IP_HWV3_ACCESSINLINE_VENDOR_ID != DMA_IP_DEVASSERT_VENDOR_ID)
    #error "DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip_Devassert.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Devassert.h file are of the same Autosar version */
#if ((DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MAJOR_VERSION != DMA_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_MINOR_VERSION != DMA_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_AR_RELEASE_REVISION_VERSION != DMA_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip_Devassert.h are different"
#endif

/* Check if header file and Dma_Ip_Devassert.h file are of the same Software version */
#if ((DMA_IP_HWV3_ACCESSINLINE_SW_MAJOR_VERSION != DMA_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_MINOR_VERSION != DMA_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (DMA_IP_HWV3_ACCESSINLINE_SW_PATCH_VERSION != DMA_IP_DEVASSERT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of DMA_IP_HWV3_ACCESSINLINE.h and Dma_Ip_Devassert.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)

#if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DMA_IP_HWV3_DOES_NOT_SUPPORT    (uint8)0xFFU

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
 * DMA INSTANCE CONFIGURATION FUNCTION - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaInst_SetConfig(Dma_Ip_Hwv3InstRegType * const ptInst, const Dma_Ip_LogicInstanceConfigType * const pxConfig)
{
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_EDBG_MASK))) | (DMA_IP_MP_CSR_EDBG(pxConfig->EnDebug ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_ERCA_MASK))) | (DMA_IP_MP_CSR_ERCA(pxConfig->EnRoundRobin ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_HAE_MASK)))  | (DMA_IP_MP_CSR_HAE(pxConfig->EnHaltAfterError ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_GCLC_MASK))) | (DMA_IP_MP_CSR_GCLC(pxConfig->EnChLinking ? TRUE : FALSE)));
    reg = ((reg & (~(DMA_IP_MP_CSR_GMRC_MASK))) | (DMA_IP_MP_CSR_GMRC(pxConfig->EnGlMasterIdReplication ? TRUE : FALSE)));
    ptInst->reg_CSR = reg;
}


/*==================================================================================================
 * DMA INSTANCE CMD FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaInst_CmdCancelTransfer(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_CX register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_CX_MASK))) | (DMA_IP_MP_CSR_CX(TRUE)));
    ptInst->reg_CSR = reg;
}
static inline void hwv3AccInlineDmaInst_CmdCancelTransferWithError(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_ECX register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_ECX_MASK))) | (DMA_IP_MP_CSR_ECX(TRUE)));
    ptInst->reg_CSR = reg;
}
static inline void hwv3AccInlineDmaInst_CmdHalt(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_HALT register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_HALT_MASK))) | (DMA_IP_MP_CSR_HALT(TRUE)));
    ptInst->reg_CSR = reg;
}
static inline void hwv3AccInlineDmaInst_CmdResume(Dma_Ip_Hwv3InstRegType * const ptInst)
{
    /* Access DMA_IP_MP_CSR_HALT register */
    uint32 reg = ptInst->reg_CSR;
    reg = ((reg & (~(DMA_IP_MP_CSR_HALT_MASK))) | (DMA_IP_MP_CSR_HALT(FALSE)));
    ptInst->reg_CSR = reg;
}

/*==================================================================================================
 * DMA INSTANCE STATUS FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaInst_GetErrorStatus(const Dma_Ip_Hwv3InstRegType * const ptInst, uint32 * const pValue)
{
    /* Get ES register */
    *pValue = (ptInst->reg_ES & DMA_IP_MP_ES_MASK);
}
static inline void hwv3AccInlineDmaInst_GetActiveIdStatus(const Dma_Ip_Hwv3InstRegType * const ptInst, uint8 * const pValue)
{
    /* Get CSR register */
    *pValue = (uint8)((ptInst->reg_CSR & DMA_IP_MP_CSR_ACTIVE_ID_MASK) >> DMA_IP_MP_CSR_ACTIVE_ID_SHIFT);
}
static inline void hwv3AccInlineDmaInst_GetActiveStatus(const Dma_Ip_Hwv3InstRegType * const ptInst, boolean * const pBool)
{
    /* Get CSR register */
    *pBool = (((ptInst->reg_CSR & DMA_IP_MP_CSR_ACTIVE_MASK) >> DMA_IP_MP_CSR_ACTIVE_SHIFT) == 0U) ? FALSE : TRUE;
}
static inline void hwv3AccInlineDmaInst_GetEdmaVersion(const Dma_Ip_Hwv3InstRegType * const ptInst, uint8 * const pValue)
{
    /* Hardware version 3 doesn't support get EDMA version */
    (void)ptInst;
    *pValue = DMA_IP_HWV3_DOES_NOT_SUPPORT;
}

/*==================================================================================================
 * DMA CHANNEL CMD FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_CmdSetRequest(Dma_Ip_ChRegType * ptCh)
{
    /* Access DMA_IP_TCD_CH_CSR_ERQ register */
    uint32 reg = ptCh->reg_CH_CSR;
    reg = ((reg & (~(DMA_IP_TCD_CH_CSR_ERQ_MASK))) | (DMA_IP_TCD_CH_CSR_ERQ(TRUE)));
    ptCh->reg_CH_CSR = reg;
}
static inline void hwv3AccInlineDmaCh_CmdClearRequest(Dma_Ip_ChRegType * ptCh)
{
    /* Access DMA_IP_TCD_CH_CSR_ERQ register */
    uint32 reg = ptCh->reg_CH_CSR;
    reg = ((reg & (~(DMA_IP_TCD_CH_CSR_ERQ_MASK))) | (DMA_IP_TCD_CH_CSR_ERQ(FALSE)));
    ptCh->reg_CH_CSR = reg;
}
static inline void hwv3AccInlineDmaCh_CmdSwReqStart(Dma_Ip_TcdRegType * ptTcd)
{
    /* Access DMA_IP_TCD_CSR_START register */
    uint16 reg = ptTcd->reg_CSR;
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START(1U)));
    ptTcd->reg_CSR = reg;
}
static inline void hwv3AccInlineDmaCh_CmdClearDone(Dma_Ip_ChRegType * ptCh)
{
    /* Access CH_CSR register */
    uint32 reg = ptCh->reg_CH_CSR;
    reg = (reg | DMA_IP_TCD_CH_CSR_DONE_MASK);
    ptCh->reg_CH_CSR = reg;
}
static inline void hwv3AccInlineDmaCh_CmdClearError(Dma_Ip_ChRegType * ptCh)
{
    /* Access CH_ES register */
    uint32 reg = ptCh->reg_CH_ES;
    reg = (reg | DMA_IP_TCD_CH_ES_ERR_MASK);
    ptCh->reg_CH_ES = reg;
}
static inline void hwv3AccInlineDmaCh_CmdClearInterruptStatus(Dma_Ip_ChRegType * ptCh)
{
    /* Access CH_INT register */
    uint32 reg = ptCh->reg_CH_INT;
    reg = (reg | DMA_IP_TCD_CH_INT_INT_MASK);
    ptCh->reg_CH_INT = reg;
}
/*==================================================================================================
 * DMA CHANNEL STATUS FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_GetErrorStatus(const Dma_Ip_ChRegType * ptCh, uint32 * const pValue)
{
    /* Get CH_ES register */
    *pValue = (ptCh->reg_CH_ES & DMA_IP_TCD_CH_ES_MASK);
}
static inline void hwv3AccInlineDmaCh_GetActiveStatus(const Dma_Ip_ChRegType * ptCh, boolean * const pBool)
{
    /* Get CH_CSR register */
    *pBool = (((ptCh->reg_CH_CSR & DMA_IP_TCD_CH_CSR_ACTIVE_MASK) >> DMA_IP_TCD_CH_CSR_ACTIVE_SHIFT) == 0U) ? FALSE : TRUE;
}
static inline void hwv3AccInlineDmaCh_GetDoneStatus(const Dma_Ip_ChRegType * ptCh, boolean * const pBool)
{
    /* Get CH_CSR register */
    *pBool = (((ptCh->reg_CH_CSR & DMA_IP_TCD_CH_CSR_DONE_MASK) >> DMA_IP_TCD_CH_CSR_DONE_SHIFT) == 0U) ? FALSE : TRUE;
}

/*==================================================================================================
 * DMA CHANNEL GLOBAL FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_SetControl_EnMasterIdReplication(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_SBR_EMI register */
    uint32 reg = ptCh->reg_CH_SBR;
    ptCh->reg_CH_SBR = ((reg & (~(DMA_IP_TCD_CH_SBR_EMI_MASK))) | (DMA_IP_TCD_CH_SBR_EMI(Value)));
}
#endif
#if (STD_ON == DMA_IP_BUFFERED_WRITES_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_SetControl_EnBufferedWrites(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_CSR_EBW register */
    uint32 reg = ptCh->reg_CH_CSR;
    ptCh->reg_CH_CSR = ((reg & (~(DMA_IP_TCD_CH_CSR_EBW_MASK))) | (DMA_IP_TCD_CH_CSR_EBW(Value)));
}
#endif

static inline void hwv3AccInlineDmaCh_SetRequest_EnHwRequest(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_CSR_ERQ register */
    uint32 reg = ptCh->reg_CH_CSR;
    ptCh->reg_CH_CSR = ((reg & (~(DMA_IP_TCD_CH_CSR_ERQ_MASK))) | (DMA_IP_TCD_CH_CSR_ERQ(Value)));
}
static inline void hwv3AccInlineDmaCh_SetInterrupt_EnError(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_CSR_EEI register */
    uint32 reg = ptCh->reg_CH_CSR;
    ptCh->reg_CH_CSR = ((reg & (~(DMA_IP_TCD_CH_CSR_EEI_MASK))) | (DMA_IP_TCD_CH_CSR_EEI(Value)));
}
static inline void hwv3AccInlineDmaCh_SetPriority_Group(volatile uint32 * const pGrpri, uint32 Value)
{
    /* Access DMA_IP_MP_CH_GRPRI_GRPRI register */
    uint32 reg = *pGrpri;
    *pGrpri = ((reg & (~(DMA_IP_MP_CH_GRPRI_GRPRI_MASK))) | (DMA_IP_MP_CH_GRPRI_GRPRI(Value)));
}
static inline void hwv3AccInlineDmaCh_SetPriority_Level(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_PRI_APL register */
    uint32 reg = ptCh->reg_CH_PRI;
    ptCh->reg_CH_PRI = ((reg & (~(DMA_IP_TCD_CH_PRI_APL_MASK))) | (DMA_IP_TCD_CH_PRI_APL(Value)));
}
#if (STD_ON == DMA_IP_PREEMPTION_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_SetPriority_EnPreemption(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_PRI_ECP register */
    uint32 reg = ptCh->reg_CH_PRI;
    ptCh->reg_CH_PRI = ((reg & (~(DMA_IP_TCD_CH_PRI_ECP_MASK))) | (DMA_IP_TCD_CH_PRI_ECP(Value)));
}
#endif
#if (STD_ON == DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_SetPriority_DisPreempt(Dma_Ip_ChRegType * ptCh, uint32 Value)
{
    /* Access DMA_IP_TCD_CH_PRI_DPA register */
    uint32 reg = ptCh->reg_CH_PRI;
    ptCh->reg_CH_PRI = ((reg & (~(DMA_IP_TCD_CH_PRI_DPA_MASK))) | (DMA_IP_TCD_CH_PRI_DPA(Value)));
}
#endif

/*==================================================================================================
 * DMA CHANNEL TRANSFER FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_SetSource_Address(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SADDR_SADDR register */
    ptTcd->reg_SADDR = DMA_IP_TCD_SADDR_SADDR(Value);
}
static inline void hwv3AccInlineDmaCh_SetSource_SignedOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SOFF_SOFF register */
    uint32 reg = ptTcd->reg_SOFF;
    ptTcd->reg_SOFF = ((uint16)(reg & (~(DMA_IP_TCD_SOFF_SOFF_MASK))) | (DMA_IP_TCD_SOFF_SOFF(Value)));
}
static inline void hwv3AccInlineDmaCh_SetSource_SignedLastAddrAdj(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SLAST_SDA_SLAST_SDA register */
    ptTcd->reg_SLAST_SDA = DMA_IP_TCD_SLAST_SDA_SLAST_SDA(Value);
}
static inline void hwv3AccInlineDmaCh_SetSource_TransferSize(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_SSIZE register */
    uint32 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SSIZE_MASK))) | (DMA_IP_TCD_ATTR_SSIZE(Value)));
}
static inline void hwv3AccInlineDmaCh_SetSource_Modulo(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_SMOD register */
    uint32 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SMOD_MASK))) | (DMA_IP_TCD_ATTR_SMOD(Value)));
}
static inline void hwv3AccInlineDmaCh_SetDestination_Address(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DADDR_DADDR register */
    ptTcd->reg_DADDR = DMA_IP_TCD_DADDR_DADDR(Value);
}
static inline void hwv3AccInlineDmaCh_SetDestination_SignedOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DOFF_DOFF register */
    uint16 reg = ptTcd->reg_DOFF;
    ptTcd->reg_DOFF = ((uint16)(reg & (~(DMA_IP_TCD_DOFF_DOFF_MASK))) | (DMA_IP_TCD_DOFF_DOFF(Value)));
}
static inline void hwv3AccInlineDmaCh_SetDestination_LastAddrAdj(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DLAST_SGA_DLAST_SGA register */
    ptTcd->reg_DLAST_SGA = DMA_IP_TCD_DLAST_SGA_DLAST_SGA(Value);
}
static inline void hwv3AccInlineDmaCh_SetDestination_TransferSize(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_DSIZE register */
    uint16 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DSIZE_MASK))) | (DMA_IP_TCD_ATTR_DSIZE(Value)));
}
static inline void hwv3AccInlineDmaCh_SetDestination_Modulo(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_ATTR_DMOD register */
    uint16 reg = ptTcd->reg_ATTR;
    ptTcd->reg_ATTR = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DMOD_MASK))) | (DMA_IP_TCD_ATTR_DMOD(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMinorLoop_enSrcOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    ptTcd->reg_NBYTES.reg_MLOFFYES = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMinorLoop_enDstOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    ptTcd->reg_NBYTES.reg_MLOFFYES = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMinorLoop_SignedOffset(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    ptTcd->reg_NBYTES.reg_MLOFFYES = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMinorLoop_EnLink(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CITER_ELINKYES_ELINK register */
    uint16 reg = ptTcd->reg_BITER.reg_ELINKYES;
    ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_ELINK(Value)));
    reg = ptTcd->reg_CITER.reg_ELINKYES;
    ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_ELINK(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMinorLoop_LinkCh(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CITER_ELINKYES_LINKCH register */
    uint16 reg = ptTcd->reg_BITER.reg_ELINKYES;
    ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKYES_LINKCH_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_LINKCH(Value)));
    reg = ptTcd->reg_CITER.reg_ELINKYES;
    ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKYES_LINKCH_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_LINKCH(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMinorLoop_Size(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES register */
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFNO;
    if(0U != (reg & (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK | DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK)))
    {
        ptTcd->reg_NBYTES.reg_MLOFFNO = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES(Value)));
    }
    else
    {
        ptTcd->reg_NBYTES.reg_MLOFFNO = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES(Value)));
    }
}
static inline void hwv3AccInlineDmaCh_SetMajorLoop_EnLink(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_MAJORELINK register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_MAJORELINK_MASK))) | (DMA_IP_TCD_CSR_MAJORELINK(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMajorLoop_LinkCh(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_MAJORLINKCH register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_MAJORLINKCH_MASK))) | (DMA_IP_TCD_CSR_MAJORLINKCH(Value)));
}
static inline void hwv3AccInlineDmaCh_SetMajorLoop_Count(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CITER_ELINKYES_CITER register */
    uint16 reg = (ptTcd->reg_BITER.reg_ELINKYES & (DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK)) |
                 (ptTcd->reg_CITER.reg_ELINKYES & (DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK));
    if(0U != reg)
    {
        reg = ptTcd->reg_BITER.reg_ELINKYES;
        ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKYES_BITER_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_BITER(Value)));
        reg = ptTcd->reg_CITER.reg_ELINKYES;
        ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKYES_CITER_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_CITER(Value)));
    }
    else
    {
        reg = ptTcd->reg_BITER.reg_ELINKNO;
        ptTcd->reg_BITER.reg_ELINKNO = ((uint16)(reg & (~(DMA_IP_TCD_BITER_ELINKNO_BITER_MASK))) | (DMA_IP_TCD_BITER_ELINKNO_BITER(Value)));
        reg = ptTcd->reg_CITER.reg_ELINKNO;
        ptTcd->reg_CITER.reg_ELINKNO = ((uint16)(reg & (~(DMA_IP_TCD_CITER_ELINKNO_CITER_MASK))) | (DMA_IP_TCD_CITER_ELINKNO_CITER(Value)));
    }
}
static inline void hwv3AccInlineDmaCh_SetControl_ScatterGatherAddress(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_DLAST_SGA_DLAST_SGA register */
    ptTcd->reg_DLAST_SGA = DMA_IP_TCD_DLAST_SGA_DLAST_SGA(Value);
}
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_SetControl_StoreDestinationAddress(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_SLAST_SDA_SLAST_SDA register */
    ptTcd->reg_SLAST_SDA = DMA_IP_TCD_SLAST_SDA_SLAST_SDA(Value);
}
#endif
static inline void hwv3AccInlineDmaCh_SetControl_EnStart(Dma_Ip_TcdRegType * ptTcd, const boolean Value)
{
    /* Access DMA_IP_TCD_CSR_START register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START((Value == TRUE) ? 1U: 0U)));
}
static inline void hwv3AccInlineDmaCh_SetControl_EnMajor(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_INTMAJOR register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTMAJOR_MASK))) | (DMA_IP_TCD_CSR_INTMAJOR(Value)));
}
static inline void hwv3AccInlineDmaCh_SetControl_EnHalfMajor(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_INTHALF register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTHALF_MASK))) | (DMA_IP_TCD_CSR_INTHALF(Value)));
}
static inline void hwv3AccInlineDmaCh_SetControl_DisAutoHwRequest(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_DREQ register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_DREQ_MASK))) | (DMA_IP_TCD_CSR_DREQ(Value)));
}
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_SetControl_EnEndOfPacketSignal(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_EEOP register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_EEOP_MASK))) | (DMA_IP_TCD_CSR_EEOP(Value)));
}
#endif
static inline void hwv3AccInlineDmaCh_SetControl_BandwidthControl(Dma_Ip_TcdRegType * ptTcd, const uint32 Value)
{
    /* Access DMA_IP_TCD_CSR_BWC register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_BWC_MASK))) | (DMA_IP_TCD_CSR_BWC(Value)));
}
static inline void hwv3AccInlineDmaCh_SetTCDParams(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather, const uint32 ElementId)
{
    uint16 reg16;
    uint32 reg32;
    uint32 hwLinkCh;

    /* Control and Status */
    /* Set value for TCD_CSR register*/
    reg16 = ptTcd->reg_CSR;
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START(pxLocScatterGather->TransferConfig->Control.EnStart ? 1U : 0U)));
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_INTMAJOR_MASK))) | (DMA_IP_TCD_CSR_INTMAJOR(pxLocScatterGather->TransferConfig->Control.EnMajorInt ? 1U : 0U)));
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_INTHALF_MASK))) | (DMA_IP_TCD_CSR_INTHALF(pxLocScatterGather->TransferConfig->Control.EnHalfMajorInt ? 1U : 0U)));
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_DREQ_MASK))) | (DMA_IP_TCD_CSR_DREQ(pxLocScatterGather->TransferConfig->Control.DisAutoHwRequest ? 1U : 0U)));
    #if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_EEOP_MASK))) | (DMA_IP_TCD_CSR_EEOP(pxLocScatterGather->TransferConfig->Control.EnEndOfPacketSignal ? 1U : 0U)));
    #endif
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_BWC_MASK))) | (DMA_IP_TCD_CSR_BWC(pxLocScatterGather->TransferConfig->Control.BandwidthControl)));
    /* At initialization, Store Destination Address can't be set. */
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_ESDA_MASK))) | (DMA_IP_TCD_CSR_ESDA(0U)));
    ptTcd->reg_CSR= reg16;

    /* Source */
    /* Access DMA_IP_TCD_SADDR_SADDR register */
    ptTcd->reg_SADDR = DMA_IP_TCD_SADDR_SADDR(pxLocScatterGather->TransferConfig->Source.Addr);
    /* Access DMA_IP_TCD_SOFF_SOFF register */
    reg32 = ptTcd->reg_SOFF;
    ptTcd->reg_SOFF = ((uint16)(reg32 & (~(DMA_IP_TCD_SOFF_SOFF_MASK))) | (DMA_IP_TCD_SOFF_SOFF((uint32)pxLocScatterGather->TransferConfig->Source.SignedOffset)));

    /* Destination */
    /* Access DMA_IP_TCD_DADDR_DADDR register */
    ptTcd->reg_DADDR = DMA_IP_TCD_DADDR_DADDR(pxLocScatterGather->TransferConfig->Destination.Addr);
    /* Access DMA_IP_TCD_DOFF_DOFF register */
    reg16 = ptTcd->reg_DOFF;
    ptTcd->reg_DOFF = ((uint16)(reg16 & (~(DMA_IP_TCD_DOFF_DOFF_MASK))) | (DMA_IP_TCD_DOFF_DOFF((uint32)pxLocScatterGather->TransferConfig->Destination.SignedOffset)));
    /* Transfer Attributes */
    /* Set value for TCD_ATTR register*/
    reg16 = ptTcd->reg_ATTR;
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_ATTR_SSIZE_MASK))) | (DMA_IP_TCD_ATTR_SSIZE(pxLocScatterGather->TransferConfig->Source.TransferSize)));
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_ATTR_SMOD_MASK))) | (DMA_IP_TCD_ATTR_SMOD(pxLocScatterGather->TransferConfig->Source.Modulo)));
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_ATTR_DSIZE_MASK))) | (DMA_IP_TCD_ATTR_DSIZE(pxLocScatterGather->TransferConfig->Destination.TransferSize)));
    reg16 = ((uint16)(reg16 & (~(DMA_IP_TCD_ATTR_DMOD_MASK))) | (DMA_IP_TCD_ATTR_DMOD(pxLocScatterGather->TransferConfig->Destination.Modulo)));
    ptTcd->reg_ATTR= reg16;
    /* Signed Minor Loop Offset */
    /* Set value for TCD_NBYTES_MLOFFYES register*/
    reg32 = ptTcd->reg_NBYTES.reg_MLOFFYES;
    reg32 = ((reg32 & (~(DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE(pxLocScatterGather->TransferConfig->MinorLoop.EnSrcOffset ? 1U : 0U)));
    reg32 = ((reg32 & (~(DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE(pxLocScatterGather->TransferConfig->MinorLoop.EnDstOffset ? 1U : 0U)));
    reg32 = ((reg32 & (~(DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF((uint32)pxLocScatterGather->TransferConfig->MinorLoop.Offset)));
    ptTcd->reg_NBYTES.reg_MLOFFYES= reg32;
    /* MinorLoop */
    /* Access DMA_IP_TCD_CITER_ELINKYES_ELINK register */
    reg16 = ptTcd->reg_BITER.reg_ELINKYES;
    ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg16 & (~(DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_ELINK((pxLocScatterGather->TransferConfig->MinorLoop.EnLink == TRUE) ? 1U : 0U)));
    reg16 = ptTcd->reg_CITER.reg_ELINKYES;
    ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg16 & (~(DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_ELINK((pxLocScatterGather->TransferConfig->MinorLoop.EnLink == TRUE) ? 1U : 0U)));
    hwLinkCh = Dma_Ip_ConvertLogicChToHwCh(pxLocScatterGather->TransferConfig->MinorLoop.LogicLinkCh);
    /* Access DMA_IP_TCD_CITER_ELINKYES_LINKCH register */
    reg16 = ptTcd->reg_BITER.reg_ELINKYES;
    ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg16 & (~(DMA_IP_TCD_BITER_ELINKYES_LINKCH_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_LINKCH(hwLinkCh)));
    reg16 = ptTcd->reg_CITER.reg_ELINKYES;
    ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg16 & (~(DMA_IP_TCD_CITER_ELINKYES_LINKCH_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_LINKCH(hwLinkCh)));
    /* Access DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES register */
    reg32 = ptTcd->reg_NBYTES.reg_MLOFFNO;
    if(0U != (reg32 & (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK | DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK)))
    {
        ptTcd->reg_NBYTES.reg_MLOFFNO = ((reg32 & (~(DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES(pxLocScatterGather->TransferConfig->MinorLoop.Size)));
    }
    else
    {
        ptTcd->reg_NBYTES.reg_MLOFFNO = ((reg32 & (~(DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES(pxLocScatterGather->TransferConfig->MinorLoop.Size)));
    }
    /* MajorLoop */
    if(TRUE == pxLocScatterGather->TransferConfig->MajorLoop.EnLink)
    {
        /* Access DMA_IP_TCD_CSR_MAJORELINK register */
        reg16 = ptTcd->reg_CSR;
        ptTcd->reg_CSR = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_MAJORELINK_MASK))) | (DMA_IP_TCD_CSR_MAJORELINK(1U)));
        hwLinkCh = Dma_Ip_ConvertLogicChToHwCh(pxLocScatterGather->TransferConfig->MajorLoop.LogicLinkCh);
        /* Access DMA_IP_TCD_CSR_MAJORLINKCH register */
        reg16 = ptTcd->reg_CSR;
        ptTcd->reg_CSR = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_MAJORLINKCH_MASK))) | (DMA_IP_TCD_CSR_MAJORLINKCH(hwLinkCh)));
    }
    else
    {
        /* Access DMA_IP_TCD_CSR_MAJORELINK register */
        reg16 = ptTcd->reg_CSR;
        ptTcd->reg_CSR = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_MAJORELINK_MASK))) | (DMA_IP_TCD_CSR_MAJORELINK(0U)));
        /* Access DMA_IP_TCD_CSR_MAJORLINKCH register */
        reg16 = ptTcd->reg_CSR;
        ptTcd->reg_CSR = ((uint16)(reg16 & (~(DMA_IP_TCD_CSR_MAJORLINKCH_MASK))) | (DMA_IP_TCD_CSR_MAJORLINKCH(ElementId)));
    }

    /* Access DMA_IP_TCD_CITER_ELINKYES_CITER register */
    reg16 = (ptTcd->reg_BITER.reg_ELINKYES & (DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK)) |
                 (ptTcd->reg_CITER.reg_ELINKYES & (DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK));
    if(0U != reg16)
    {
        reg16 = ptTcd->reg_BITER.reg_ELINKYES;
        ptTcd->reg_BITER.reg_ELINKYES = ((uint16)(reg16 & (~(DMA_IP_TCD_BITER_ELINKYES_BITER_MASK))) | (DMA_IP_TCD_BITER_ELINKYES_BITER(pxLocScatterGather->TransferConfig->MajorLoop.Count)));
        reg16 = ptTcd->reg_CITER.reg_ELINKYES;
        ptTcd->reg_CITER.reg_ELINKYES = ((uint16)(reg16 & (~(DMA_IP_TCD_CITER_ELINKYES_CITER_MASK))) | (DMA_IP_TCD_CITER_ELINKYES_CITER(pxLocScatterGather->TransferConfig->MajorLoop.Count)));
    }
    else
    {
        reg16 = ptTcd->reg_BITER.reg_ELINKNO;
        ptTcd->reg_BITER.reg_ELINKNO = ((uint16)(reg16 & (~(DMA_IP_TCD_BITER_ELINKNO_BITER_MASK))) | (DMA_IP_TCD_BITER_ELINKNO_BITER(pxLocScatterGather->TransferConfig->MajorLoop.Count)));
        reg16 = ptTcd->reg_CITER.reg_ELINKNO;
        ptTcd->reg_CITER.reg_ELINKNO = ((uint16)(reg16 & (~(DMA_IP_TCD_CITER_ELINKNO_CITER_MASK))) | (DMA_IP_TCD_CITER_ELINKNO_CITER(pxLocScatterGather->TransferConfig->MajorLoop.Count)));
    }
    /* Access DMA_IP_TCD_SLAST_SDA_SLAST_SDA register */
    ptTcd->reg_SLAST_SDA =DMA_IP_TCD_SLAST_SDA_SLAST_SDA((uint32)pxLocScatterGather->TransferConfig->Source.LastAddrAdj);
}


/*==================================================================================================
 * DMA CHANNEL GET PARAMETER - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_GetSourceAddress(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_SADDR register */
    *retValue = (uint32)ptTcd->reg_SADDR;
}
static inline void hwv3AccInlineDmaCh_GetDestinationAddress(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_DADDR register */
    *retValue = (uint32)ptTcd->reg_DADDR;
}
static inline void hwv3AccInlineDmaCh_GetBeginIterCount(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_BITER register */
    uint16 reg = ptTcd->reg_BITER.reg_ELINKYES & (DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK);
    if(0U != reg)
    {
        *retValue = (uint32)((ptTcd->reg_BITER.reg_ELINKYES & (uint32)DMA_IP_TCD_BITER_ELINKYES_BITER_MASK) >> DMA_IP_TCD_BITER_ELINKYES_BITER_SHIFT);
    }
    else
    {
        *retValue = (uint32)((ptTcd->reg_BITER.reg_ELINKYES & (uint32)DMA_IP_TCD_BITER_ELINKNO_BITER_MASK) >> DMA_IP_TCD_BITER_ELINKNO_BITER_SHIFT);
    }
}
static inline void hwv3AccInlineDmaCh_GetCurrentIterCount(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_CITER register */
    uint16 reg = (ptTcd->reg_CITER.reg_ELINKYES & (DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK));
    if(0U != reg)
    {
        *retValue = (uint32)((ptTcd->reg_CITER.reg_ELINKYES & (uint32)DMA_IP_TCD_CITER_ELINKYES_CITER_MASK) >> DMA_IP_TCD_CITER_ELINKYES_CITER_SHIFT);
    }
    else
    {
        *retValue = (uint32)((ptTcd->reg_CITER.reg_ELINKNO & (uint32)DMA_IP_TCD_CITER_ELINKNO_CITER_MASK) >> DMA_IP_TCD_CITER_ELINKNO_CITER_SHIFT);
    }
}
#if (STD_ON == DMA_IP_STORE_DST_ADDR_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_GetStoreDstAddress(const Dma_Ip_TcdRegType * ptTcd, Dma_Ip_uintPtrType * const retValue)
{
    /* Access reg_SLAST_SDA register */
    *retValue = (uint32)(ptTcd->reg_SLAST_SDA);
}
#endif
#if (STD_ON == DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_GetMasterId(const Dma_Ip_ChRegType * ptCh, uint32 * const retValue)
{
    /* Access reg_CH_SBR register */
    *retValue = (uint32)((ptCh->reg_CH_SBR & DMA_IP_TCD_CH_SBR_MID_MASK) >> DMA_IP_TCD_CH_SBR_MID_SHIFT);
}
#endif
static inline void hwv3AccInlineDmaCh_GetIntMajor(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_CSR register */
    *retValue = (uint32)((ptTcd->reg_CSR & (uint32)DMA_IP_TCD_CSR_INTMAJOR_MASK) >> DMA_IP_TCD_CSR_INTMAJOR_SHIFT);
}
static inline void hwv3AccInlineDmaCh_GetIntHalfMajor(const Dma_Ip_TcdRegType * ptTcd, uint32 * const retValue)
{
    /* Access reg_CSR register */
    *retValue = (uint32)((ptTcd->reg_CSR & (uint32)DMA_IP_TCD_CSR_INTHALF_MASK) >> DMA_IP_TCD_CSR_INTHALF_SHIFT);
}


#if (STD_ON == DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE)
static inline void hwv3AccInlineDmaCh_GetProtectionLevel(const Dma_Ip_ChRegType * ptCh, uint32 * const retValue)
{
    /* Access reg_CH_SBR register */
    *retValue = (uint32)((ptCh->reg_CH_SBR & DMA_IP_TCD_CH_SBR_PAL_MASK) >> DMA_IP_TCD_CH_SBR_PAL_SHIFT);
}
#endif

/*==================================================================================================
 * DMA CHANNEL AUXILIARY FUNCTIONS - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_SetAuxiliary_EnScatterGatherProcessing(Dma_Ip_TcdRegType * ptTcd, boolean Value)
{
    /* Access DMA_IP_TCD_CSR_ESG register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_ESG_MASK))) | (DMA_IP_TCD_CSR_ESG((Value == TRUE) ? 1U: 0U)));
}
static inline void hwv3AccInlineDmaCh_SetAuxiliary_EnDestinationStoreAddress(Dma_Ip_TcdRegType * ptTcd, boolean Value)
{
    /* Access DMA_IP_TCD_CSR_ESDA register */
    uint16 reg = ptTcd->reg_CSR;
    ptTcd->reg_CSR = ((uint16)(reg & (~(DMA_IP_TCD_CSR_ESDA_MASK))) | (DMA_IP_TCD_CSR_ESDA((Value == TRUE) ? 1U: 0U)));
}

/*==================================================================================================
 * TCD CONTROL AND STATUS (TCD_CSR) - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_SetControlAndStatus(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    /* Set value for TCD_CSR register*/
    uint16 reg = ptTcd->reg_CSR;
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_START_MASK))) | (DMA_IP_TCD_CSR_START(pxLocScatterGather->TransferConfig->Control.EnStart ? 1U : 0U)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTMAJOR_MASK))) | (DMA_IP_TCD_CSR_INTMAJOR(pxLocScatterGather->TransferConfig->Control.EnMajorInt ? 1U : 0U)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_INTHALF_MASK))) | (DMA_IP_TCD_CSR_INTHALF(pxLocScatterGather->TransferConfig->Control.EnHalfMajorInt ? 1U : 0U)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_DREQ_MASK))) | (DMA_IP_TCD_CSR_DREQ(pxLocScatterGather->TransferConfig->Control.DisAutoHwRequest ? 1U : 0U)));
#if (STD_ON == DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE)
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_EEOP_MASK))) | (DMA_IP_TCD_CSR_EEOP(pxLocScatterGather->TransferConfig->Control.EnEndOfPacketSignal ? 1U : 0U)));
#endif
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_BWC_MASK))) | (DMA_IP_TCD_CSR_BWC(pxLocScatterGather->TransferConfig->Control.BandwidthControl)));
    /* At initialization, Store Destination Address can't be set. */
    reg = ((uint16)(reg & (~(DMA_IP_TCD_CSR_ESDA_MASK))) | (DMA_IP_TCD_CSR_ESDA(0U)));
    ptTcd->reg_CSR= reg;
}

/*==================================================================================================
 * TCD TRANSFER ATTRIBUTES (TCD_ATTR) - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_SetTransferAttributes(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    /* Set value for TCD_ATTR register*/
    uint16 reg = ptTcd->reg_ATTR;
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SSIZE_MASK))) | (DMA_IP_TCD_ATTR_SSIZE(pxLocScatterGather->TransferConfig->Source.TransferSize)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_SMOD_MASK))) | (DMA_IP_TCD_ATTR_SMOD(pxLocScatterGather->TransferConfig->Source.Modulo)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DSIZE_MASK))) | (DMA_IP_TCD_ATTR_DSIZE(pxLocScatterGather->TransferConfig->Destination.TransferSize)));
    reg = ((uint16)(reg & (~(DMA_IP_TCD_ATTR_DMOD_MASK))) | (DMA_IP_TCD_ATTR_DMOD(pxLocScatterGather->TransferConfig->Destination.Modulo)));
    ptTcd->reg_ATTR= reg;
}

/*==================================================================================================
 * TCD SIGNED MINOR LOOP OFFSET (TCD_NBYTES_MLOFFYES) - REGISTER ACCESS
==================================================================================================*/
static inline void hwv3AccInlineDmaCh_SetSignedMinorLoopOffset(Dma_Ip_TcdRegType * ptTcd, const Dma_Ip_ScatterGatherConfigType * const pxLocScatterGather)
{
    /* Set value for TCD_NBYTES_MLOFFYES register*/
    uint32 reg = ptTcd->reg_NBYTES.reg_MLOFFYES;
    reg = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE(pxLocScatterGather->TransferConfig->MinorLoop.EnSrcOffset ? 1U : 0U)));
    reg = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE(pxLocScatterGather->TransferConfig->MinorLoop.EnDstOffset ? 1U : 0U)));
    reg = ((reg & (~(DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK))) | (DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF((uint32)pxLocScatterGather->TransferConfig->MinorLoop.Offset)));
    ptTcd->reg_NBYTES.reg_MLOFFYES= reg;
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_HWV3_IS_AVAILABLE) */
#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef DMA_IP_HWV3_ACCESSINLINE_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

