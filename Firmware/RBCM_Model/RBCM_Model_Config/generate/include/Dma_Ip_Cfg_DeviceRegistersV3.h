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
#ifndef DMA_IP_CFG_DEVICE_REGISTERS_V3_H_
#define DMA_IP_CFG_DEVICE_REGISTERS_V3_H_

/**
*   @file    Dma_Ip_Cfg_DeviceRegistersV3.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip Cfg Device Register V3 header file.
*   @details Contains common register information and specific register information for
*            DMA Hardware Version 3.
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

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
#include "Mcal.h"

#include "S32K344_DMA.h"
#include "S32K344_DMA_TCD.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_DEVICEREGISTERSV3_VENDOR_ID                       43
#define DMA_IP_CFG_DEVICEREGISTERSV3_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_DEVICEREGISTERSV3_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_CFG_DEVICEREGISTERSV3_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_DEVICEREGISTERSV3_SW_MAJOR_VERSION                5
#define DMA_IP_CFG_DEVICEREGISTERSV3_SW_MINOR_VERSION                0
#define DMA_IP_CFG_DEVICEREGISTERSV3_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal header file are of the same Autosar version */
#if ((DMA_IP_CFG_DEVICEREGISTERSV3_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_DEVICEREGISTERSV3_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Cfg_DeviceRegisters.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
                                            DEFINES
==================================================================================================*/
/*-----------------------------------------------/
/  DMA HWV3 INSTANCES                            /
/-----------------------------------------------*/
#define DMA_IP_BASE                         (0x4020C000U)
#define DMA_IP_PTR                          ((Dma_Ip_Hwv3InstRegType *)DMA_IP_BASE)
#define DMA_IP_DMA_BASE_PTRS                { DMA_IP_PTR }
#define DMA_IP_DMA_MP_GRPRI_COUNT           DMA_IP_MP_GRPRI_COUNT
#define DMA_IP_MP_GRPRI_COUNT               ((uint32)32U)
#define DMA_IP_DMA_NOF_HWV3_INST            ((uint32)1U)        /* Total number of hardware instances */
/*-----------------------------------------------/
/  DMA HWV3 CHANNELS                             /
/-----------------------------------------------*/
#define DMA_IP_TCD_BASE                     (0x40210000U)
#define DMA_IP_TCD_PTR                      ((Dma_Ip_Hwv3TcdArrayType *)DMA_IP_TCD_BASE)
#define DMA_IP_TCD_BASE_PTRS                { DMA_IP_TCD_PTR }
#define DMA_IP_TCD_RESERVED                 (16320U)           /* Reserved space between hardware TCDs */

#define DMA_IP_TCD_NOF_HWV3_CH              ((uint32)32U)      /* Number of hardware channels */

#define DMA_IP_TCD_NOF_HWV3_CH_INST         DMA_TCD_INSTANCE_COUNT       /* Number of hardware TCD instances */

/*-----------------------------------------------/
/  DMA HWV3 TOTAL CHANNELS                       /
/-----------------------------------------------*/
#define DMA_IP_NOF_HWV3_CH                  (DMA_IP_TCD_NOF_HWV3_CH_INST * DMA_IP_TCD_NOF_HWV3_CH)  /* Total number of hardware channels of all instances */

/*-----------------------------------------------/
/  DMA HWV3 INSTANCE ES MASK                     /
/-----------------------------------------------*/
#define DMA_IP_MP_ES_MASK                   (DMA_IP_MP_ES_DBE_MASK | DMA_IP_MP_ES_SBE_MASK |\
                                             DMA_IP_MP_ES_SGE_MASK | DMA_IP_MP_ES_NCE_MASK |\
                                             DMA_IP_MP_ES_DOE_MASK | DMA_IP_MP_ES_DAE_MASK |\
                                             DMA_IP_MP_ES_SOE_MASK | DMA_IP_MP_ES_SAE_MASK |\
                                             DMA_IP_MP_ES_ECX_MASK | DMA_IP_MP_ES_UCE_MASK |\
                                             DMA_IP_MP_ES_ERRCHN_MASK | DMA_IP_MP_ES_VLD_MASK)

/*-----------------------------------------------/
/  DMA HWV3 CHANNEL ES MASK                      /
/-----------------------------------------------*/
#define DMA_IP_TCD_CH_ES_MASK               (DMA_IP_TCD_CH_ES_DBE_MASK | DMA_IP_TCD_CH_ES_SBE_MASK |\
                                             DMA_IP_TCD_CH_ES_SGE_MASK | DMA_IP_TCD_CH_ES_NCE_MASK |\
                                             DMA_IP_TCD_CH_ES_DOE_MASK | DMA_IP_TCD_CH_ES_DAE_MASK |\
                                             DMA_IP_TCD_CH_ES_SOE_MASK | DMA_IP_TCD_CH_ES_SAE_MASK |\
                                             DMA_IP_TCD_CH_ES_ERR_MASK)

/*==================================================================================================
                                       DMA TCD NOT ALIGNED
==================================================================================================*/
#define DMA_IP_TCD_NOT_ALIGNED               STD_ON

/** TCD array pointer initialization: */
    #define DMA_IP_TCD_PTR_ARRAY                 {{((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(0U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(1U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(3U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(4U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(5U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(6U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(7U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(8U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(9U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(10U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(11U * 16384U))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (0U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (1U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (2U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (3U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (4U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (5U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (6U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (7U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (8U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (9U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (10U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (11U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (12U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (13U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (14U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (15U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (16U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (17U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (18U * 16384U)))),\
                                                 ((Dma_Ip_Hwv3ChTcdRegType *)((uint32)DMA_IP_TCD_BASE + (uint32)(2097152U + (19U * 16384U))))}}
/*-----------------------------------------------/
/  DMA REGISTER PROTECTION SIZE                  /
/-----------------------------------------------*/
#define DMA_IP_REG_PROT_SIZE               ((uint32)0x4U)

/*-----------------------------------------------/
/  DMA BASE REGISTER ADDRESS                     /
/-----------------------------------------------*/
#define DMA_IP_BASE_ADDR(instIdx)           ((uint32)DMA_IP_BASE)
#define DMA_IP_CSR_BASE_ADDR(instIdx) \
        ((uint32)(DMA_IP_BASE_ADDR(instIdx)))

/*-----------------------------------------------/

/  DMA TOTAL NUMBER OF HARDWARE INSTANCE         /

/-----------------------------------------------*/
#define DMA_IP_DMA_TOTAL_NOF_INST             ((uint32)1U)

/*==================================================================================================
                                       DMA REGISTER MASKS
==================================================================================================*/
/*! reg_CSR - Management Page Control */
/*! @{ */
#define DMA_IP_MP_CSR_EDBG_MASK                  (0x2U)
#define DMA_IP_MP_CSR_EDBG_SHIFT                 (1U)
#define DMA_IP_MP_CSR_EDBG(x)                    (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_EDBG_SHIFT)) & DMA_IP_MP_CSR_EDBG_MASK)
#define DMA_IP_MP_CSR_ERCA_MASK                  (0x4U)
#define DMA_IP_MP_CSR_ERCA_SHIFT                 (2U)
#define DMA_IP_MP_CSR_ERCA(x)                    (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_ERCA_SHIFT)) & DMA_IP_MP_CSR_ERCA_MASK)
#define DMA_IP_MP_CSR_HAE_MASK                   (0x10U)
#define DMA_IP_MP_CSR_HAE_SHIFT                  (4U)
#define DMA_IP_MP_CSR_HAE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_HAE_SHIFT)) & DMA_IP_MP_CSR_HAE_MASK)
#define DMA_IP_MP_CSR_HALT_MASK                  (0x20U)
#define DMA_IP_MP_CSR_HALT_SHIFT                 (5U)
#define DMA_IP_MP_CSR_HALT(x)                    (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_HALT_SHIFT)) & DMA_IP_MP_CSR_HALT_MASK)
#define DMA_IP_MP_CSR_GCLC_MASK                  (0x40U)
#define DMA_IP_MP_CSR_GCLC_SHIFT                 (6U)
#define DMA_IP_MP_CSR_GCLC(x)                    (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_GCLC_SHIFT)) & DMA_IP_MP_CSR_GCLC_MASK)
#define DMA_IP_MP_CSR_GMRC_MASK                  (0x80U)
#define DMA_IP_MP_CSR_GMRC_SHIFT                 (7U)
#define DMA_IP_MP_CSR_GMRC(x)                    (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_GMRC_SHIFT)) & DMA_IP_MP_CSR_GMRC_MASK)
#define DMA_IP_MP_CSR_ECX_MASK                   (0x100U)
#define DMA_IP_MP_CSR_ECX_SHIFT                  (8U)
#define DMA_IP_MP_CSR_ECX(x)                     (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_ECX_SHIFT)) & DMA_IP_MP_CSR_ECX_MASK)
#define DMA_IP_MP_CSR_CX_MASK                    (0x200U)
#define DMA_IP_MP_CSR_CX_SHIFT                   (9U)
#define DMA_IP_MP_CSR_CX(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_CX_SHIFT)) & DMA_IP_MP_CSR_CX_MASK)
#define DMA_IP_MP_CSR_ACTIVE_ID_MASK             (0x1F000000U)
#define DMA_IP_MP_CSR_ACTIVE_ID_SHIFT            (24U)
#define DMA_IP_MP_CSR_ACTIVE_ID(x)               (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_ACTIVE_ID_SHIFT)) & DMA_IP_MP_CSR_ACTIVE_ID_MASK)
#define DMA_IP_MP_CSR_ACTIVE_MASK                (0x80000000U)
#define DMA_IP_MP_CSR_ACTIVE_SHIFT               (31U)
#define DMA_IP_MP_CSR_ACTIVE(x)                  (((uint32)(((uint32)(x)) << DMA_IP_MP_CSR_ACTIVE_SHIFT)) & DMA_IP_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! reg_ES - Management Page Error Status */
/*! @{ */
#define DMA_IP_MP_ES_DBE_MASK                    (0x1U)
#define DMA_IP_MP_ES_DBE_SHIFT                   (0U)
#define DMA_IP_MP_ES_DBE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_DBE_SHIFT)) & DMA_IP_MP_ES_DBE_MASK)
#define DMA_IP_MP_ES_SBE_MASK                    (0x2U)
#define DMA_IP_MP_ES_SBE_SHIFT                   (1U)
#define DMA_IP_MP_ES_SBE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_SBE_SHIFT)) & DMA_IP_MP_ES_SBE_MASK)
#define DMA_IP_MP_ES_SGE_MASK                    (0x4U)
#define DMA_IP_MP_ES_SGE_SHIFT                   (2U)
#define DMA_IP_MP_ES_SGE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_SGE_SHIFT)) & DMA_IP_MP_ES_SGE_MASK)
#define DMA_IP_MP_ES_NCE_MASK                    (0x8U)
#define DMA_IP_MP_ES_NCE_SHIFT                   (3U)
#define DMA_IP_MP_ES_NCE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_NCE_SHIFT)) & DMA_IP_MP_ES_NCE_MASK)
#define DMA_IP_MP_ES_DOE_MASK                    (0x10U)
#define DMA_IP_MP_ES_DOE_SHIFT                   (4U)
#define DMA_IP_MP_ES_DOE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_DOE_SHIFT)) & DMA_IP_MP_ES_DOE_MASK)
#define DMA_IP_MP_ES_DAE_MASK                    (0x20U)
#define DMA_IP_MP_ES_DAE_SHIFT                   (5U)
#define DMA_IP_MP_ES_DAE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_DAE_SHIFT)) & DMA_IP_MP_ES_DAE_MASK)
#define DMA_IP_MP_ES_SOE_MASK                    (0x40U)
#define DMA_IP_MP_ES_SOE_SHIFT                   (6U)
#define DMA_IP_MP_ES_SOE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_SOE_SHIFT)) & DMA_IP_MP_ES_SOE_MASK)
#define DMA_IP_MP_ES_SAE_MASK                    (0x80U)
#define DMA_IP_MP_ES_SAE_SHIFT                   (7U)
#define DMA_IP_MP_ES_SAE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_SAE_SHIFT)) & DMA_IP_MP_ES_SAE_MASK)
#define DMA_IP_MP_ES_ECX_MASK                    (0x100U)
#define DMA_IP_MP_ES_ECX_SHIFT                   (8U)
#define DMA_IP_MP_ES_ECX(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_ECX_SHIFT)) & DMA_IP_MP_ES_ECX_MASK)
#define DMA_IP_MP_ES_UCE_MASK                    (0x200U)
#define DMA_IP_MP_ES_UCE_SHIFT                   (9U)
#define DMA_IP_MP_ES_UCE(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_UCE_SHIFT)) & DMA_IP_MP_ES_UCE_MASK)
#define DMA_IP_MP_ES_ERRCHN_MASK                 (0x1F000000U)
#define DMA_IP_MP_ES_ERRCHN_SHIFT                (24U)
#define DMA_IP_MP_ES_ERRCHN(x)                   (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_ERRCHN_SHIFT)) & DMA_IP_MP_ES_ERRCHN_MASK)
#define DMA_IP_MP_ES_VLD_MASK                    (0x80000000U)
#define DMA_IP_MP_ES_VLD_SHIFT                   (31U)
#define DMA_IP_MP_ES_VLD(x)                      (((uint32)(((uint32)(x)) << DMA_IP_MP_ES_VLD_SHIFT)) & DMA_IP_MP_ES_VLD_MASK)
/*! @} */

/*! reg_INT - Management Page Interrupt Request Status */
/*! @{ */
#define DMA_IP_MP_INT_INT_MASK                   (0xFFFFFFFFU)
#define DMA_IP_MP_INT_INT_SHIFT                  (0U)
#define DMA_IP_MP_INT_INT(x)                     (((uint32)(((uint32)(x)) << DMA_IP_MP_INT_INT_SHIFT)) & DMA_IP_MP_INT_INT_MASK)
/*! @} */

/*! reg_HRS - Management Page Hardware Request Status */
/*! @{ */
#define DMA_IP_MP_HRS_HRS_MASK                   (0xFFFFFFFFU)
#define DMA_IP_MP_HRS_HRS_SHIFT                  (0U)
#define DMA_IP_MP_HRS_HRS(x)                     (((uint32)(((uint32)(x)) << DMA_IP_MP_HRS_HRS_SHIFT)) & DMA_IP_MP_HRS_HRS_MASK)
/*! @} */

/*! reg_CH_GRPRI - Channel Arbitration Group */
/*! @{ */
#define DMA_IP_MP_CH_GRPRI_GRPRI_MASK                  (0x1FU)
#define DMA_IP_MP_CH_GRPRI_GRPRI_SHIFT                 (0U)
#define DMA_IP_MP_CH_GRPRI_GRPRI(x)                    (((uint32)(((uint32)(x)) << DMA_IP_MP_CH_GRPRI_GRPRI_SHIFT)) & DMA_IP_MP_CH_GRPRI_GRPRI_MASK)
/*! @} */

/*==================================================================================================
                                     DMA TCD REGISTER MASKS
==================================================================================================*/
/*! reg_CH_CSR - Channel Control and Status */
/*! @{ */
#define DMA_IP_TCD_CH_CSR_ERQ_MASK                  (0x1U)
#define DMA_IP_TCD_CH_CSR_ERQ_SHIFT                 (0U)
#define DMA_IP_TCD_CH_CSR_ERQ_WIDTH                 (1U)
#define DMA_IP_TCD_CH_CSR_ERQ(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_CSR_ERQ_SHIFT)) & DMA_IP_TCD_CH_CSR_ERQ_MASK)
#define DMA_IP_TCD_CH_CSR_EARQ_MASK                 (0x2U)
#define DMA_IP_TCD_CH_CSR_EARQ_SHIFT                (1U)
#define DMA_IP_TCD_CH_CSR_EARQ_WIDTH                (1U)
#define DMA_IP_TCD_CH_CSR_EARQ(x)                   (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_CSR_EARQ_SHIFT)) & DMA_IP_TCD_CH_CSR_EARQ_MASK)
#define DMA_IP_TCD_CH_CSR_EEI_MASK                  (0x4U)
#define DMA_IP_TCD_CH_CSR_EEI_SHIFT                 (2U)
#define DMA_IP_TCD_CH_CSR_EEI_WIDTH                 (1U)
#define DMA_IP_TCD_CH_CSR_EEI(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_CSR_EEI_SHIFT)) & DMA_IP_TCD_CH_CSR_EEI_MASK)
#define DMA_IP_TCD_CH_CSR_EBW_MASK                  (0x8U)
#define DMA_IP_TCD_CH_CSR_EBW_SHIFT                 (3U)
#define DMA_IP_TCD_CH_CSR_EBW_WIDTH                 (1U)
#define DMA_IP_TCD_CH_CSR_EBW(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_CSR_EBW_SHIFT)) & DMA_IP_TCD_CH_CSR_EBW_MASK)
#define DMA_IP_TCD_CH_CSR_DONE_MASK                 (0x40000000U)
#define DMA_IP_TCD_CH_CSR_DONE_SHIFT                (30U)
#define DMA_IP_TCD_CH_CSR_DONE_WIDTH                (1U)
#define DMA_IP_TCD_CH_CSR_DONE(x)                   (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_CSR_DONE_SHIFT)) & DMA_IP_TCD_CH_CSR_DONE_MASK)
#define DMA_IP_TCD_CH_CSR_ACTIVE_MASK               (0x80000000U)
#define DMA_IP_TCD_CH_CSR_ACTIVE_SHIFT              (31U)
#define DMA_IP_TCD_CH_CSR_ACTIVE_WIDTH              (1U)
#define DMA_IP_TCD_CH_CSR_ACTIVE(x)                 (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_CSR_ACTIVE_SHIFT)) & DMA_IP_TCD_CH_CSR_ACTIVE_MASK)
/*! @} */

/*! reg_CH_ES - Channel Error Status */
/*! @{ */
#define DMA_IP_TCD_CH_ES_DBE_MASK                   (0x1U)
#define DMA_IP_TCD_CH_ES_DBE_SHIFT                  (0U)
#define DMA_IP_TCD_CH_ES_DBE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_DBE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_DBE_SHIFT)) & DMA_IP_TCD_CH_ES_DBE_MASK)
#define DMA_IP_TCD_CH_ES_SBE_MASK                   (0x2U)
#define DMA_IP_TCD_CH_ES_SBE_SHIFT                  (1U)
#define DMA_IP_TCD_CH_ES_SBE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_SBE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_SBE_SHIFT)) & DMA_IP_TCD_CH_ES_SBE_MASK)
#define DMA_IP_TCD_CH_ES_SGE_MASK                   (0x4U)
#define DMA_IP_TCD_CH_ES_SGE_SHIFT                  (2U)
#define DMA_IP_TCD_CH_ES_SGE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_SGE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_SGE_SHIFT)) & DMA_IP_TCD_CH_ES_SGE_MASK)
#define DMA_IP_TCD_CH_ES_NCE_MASK                   (0x8U)
#define DMA_IP_TCD_CH_ES_NCE_SHIFT                  (3U)
#define DMA_IP_TCD_CH_ES_NCE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_NCE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_NCE_SHIFT)) & DMA_IP_TCD_CH_ES_NCE_MASK)
#define DMA_IP_TCD_CH_ES_DOE_MASK                   (0x10U)
#define DMA_IP_TCD_CH_ES_DOE_SHIFT                  (4U)
#define DMA_IP_TCD_CH_ES_DOE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_DOE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_DOE_SHIFT)) & DMA_IP_TCD_CH_ES_DOE_MASK)
#define DMA_IP_TCD_CH_ES_DAE_MASK                   (0x20U)
#define DMA_IP_TCD_CH_ES_DAE_SHIFT                  (5U)
#define DMA_IP_TCD_CH_ES_DAE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_DAE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_DAE_SHIFT)) & DMA_IP_TCD_CH_ES_DAE_MASK)
#define DMA_IP_TCD_CH_ES_SOE_MASK                   (0x40U)
#define DMA_IP_TCD_CH_ES_SOE_SHIFT                  (6U)
#define DMA_IP_TCD_CH_ES_SOE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_SOE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_SOE_SHIFT)) & DMA_IP_TCD_CH_ES_SOE_MASK)
#define DMA_IP_TCD_CH_ES_SAE_MASK                   (0x80U)
#define DMA_IP_TCD_CH_ES_SAE_SHIFT                  (7U)
#define DMA_IP_TCD_CH_ES_SAE_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_SAE(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_SAE_SHIFT)) & DMA_IP_TCD_CH_ES_SAE_MASK)
#define DMA_IP_TCD_CH_ES_ERR_MASK                   (0x80000000U)
#define DMA_IP_TCD_CH_ES_ERR_SHIFT                  (31U)
#define DMA_IP_TCD_CH_ES_ERR_WIDTH                  (1U)
#define DMA_IP_TCD_CH_ES_ERR(x)                     (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_ES_ERR_SHIFT)) & DMA_IP_TCD_CH_ES_ERR_MASK)
/*! @} */

/*! reg_CH_INT - Channel Interrupt Status */
/*! @{ */
#define DMA_IP_TCD_CH_INT_INT_MASK                  (0x1U)
#define DMA_IP_TCD_CH_INT_INT_SHIFT                 (0U)
#define DMA_IP_TCD_CH_INT_INT_WIDTH                 (1U)
#define DMA_IP_TCD_CH_INT_INT(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_INT_INT_SHIFT)) & DMA_IP_TCD_CH_INT_INT_MASK)
/*! @} */

/*! reg_CH_SBR - Channel System Bus */
/*! @{ */
#define DMA_IP_TCD_CH_SBR_MID_MASK                  (0x3FU)
#define DMA_IP_TCD_CH_SBR_MID_SHIFT                 (0U)
#define DMA_IP_TCD_CH_SBR_MID_WIDTH                 (6U)
#define DMA_IP_TCD_CH_SBR_MID(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_SBR_MID_SHIFT)) & DMA_IP_TCD_CH_SBR_MID_MASK)
#define DMA_IP_TCD_CH_SBR_PAL_MASK                  (0x8000U)
#define DMA_IP_TCD_CH_SBR_PAL_SHIFT                 (15U)
#define DMA_IP_TCD_CH_SBR_PAL_WIDTH                 (1U)
#define DMA_IP_TCD_CH_SBR_PAL(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_SBR_PAL_SHIFT)) & DMA_IP_TCD_CH_SBR_PAL_MASK)
#define DMA_IP_TCD_CH_SBR_EMI_MASK                  (0x10000U)
#define DMA_IP_TCD_CH_SBR_EMI_SHIFT                 (16U)
#define DMA_IP_TCD_CH_SBR_EMI_WIDTH                 (1U)
#define DMA_IP_TCD_CH_SBR_EMI(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_SBR_EMI_SHIFT)) & DMA_IP_TCD_CH_SBR_EMI_MASK)
#define DMA_IP_TCD_CH_SBR_ATTR_MASK                 (0xE0000U)
#define DMA_IP_TCD_CH_SBR_ATTR_SHIFT                (17U)
#define DMA_IP_TCD_CH_SBR_ATTR_WIDTH                (3U)
#define DMA_IP_TCD_CH_SBR_ATTR(x)                   (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_SBR_ATTR_SHIFT)) & DMA_IP_TCD_CH_SBR_ATTR_MASK)
/*! @} */

/*! reg_CH_PRI - Channel Priority */
/*! @{ */
#define DMA_IP_TCD_CH_PRI_APL_MASK                  (0x7U)
#define DMA_IP_TCD_CH_PRI_APL_SHIFT                 (0U)
#define DMA_IP_TCD_CH_PRI_APL_WIDTH                 (3U)
#define DMA_IP_TCD_CH_PRI_APL(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_PRI_APL_SHIFT)) & DMA_IP_TCD_CH_PRI_APL_MASK)
#define DMA_IP_TCD_CH_PRI_DPA_MASK                  (0x40000000U)
#define DMA_IP_TCD_CH_PRI_DPA_SHIFT                 (30U)
#define DMA_IP_TCD_CH_PRI_DPA_WIDTH                 (1U)
#define DMA_IP_TCD_CH_PRI_DPA(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_PRI_DPA_SHIFT)) & DMA_IP_TCD_CH_PRI_DPA_MASK)
#define DMA_IP_TCD_CH_PRI_ECP_MASK                  (0x80000000U)
#define DMA_IP_TCD_CH_PRI_ECP_SHIFT                 (31U)
#define DMA_IP_TCD_CH_PRI_ECP_WIDTH                 (1U)
#define DMA_IP_TCD_CH_PRI_ECP(x)                    (((uint32)(((uint32)(x)) << DMA_IP_TCD_CH_PRI_ECP_SHIFT)) & DMA_IP_TCD_CH_PRI_ECP_MASK)
/*! @} */

/*! reg_SADDR - TCD Source Address */
/*! @{ */
#define DMA_IP_TCD_SADDR_SADDR_MASK                 (0xFFFFFFFFU)
#define DMA_IP_TCD_SADDR_SADDR_SHIFT                (0U)
#define DMA_IP_TCD_SADDR_SADDR_WIDTH                (32U)
#define DMA_IP_TCD_SADDR_SADDR(x)                   (((uint32)(((uint32)(x)) << DMA_IP_TCD_SADDR_SADDR_SHIFT)) & DMA_IP_TCD_SADDR_SADDR_MASK)
/*! @} */

/*! reg_SOFF - TCD Signed Source Address Offset */
/*! @{ */
#define DMA_IP_TCD_SOFF_SOFF_MASK                   (0xFFFFU)
#define DMA_IP_TCD_SOFF_SOFF_SHIFT                  (0U)
#define DMA_IP_TCD_SOFF_SOFF_WIDTH                  (16U)
#define DMA_IP_TCD_SOFF_SOFF(x)                     (((uint16)(((uint16)(x)) << DMA_IP_TCD_SOFF_SOFF_SHIFT)) & DMA_IP_TCD_SOFF_SOFF_MASK)
/*! @} */

/*! reg_ATTR - TCD Transfer Attributes */
/*! @{ */
#define DMA_IP_TCD_ATTR_DSIZE_MASK                  (0x7U)
#define DMA_IP_TCD_ATTR_DSIZE_SHIFT                 (0U)
#define DMA_IP_TCD_ATTR_DSIZE_WIDTH                 (3U)
#define DMA_IP_TCD_ATTR_DSIZE(x)                    (((uint16)(((uint16)(x)) << DMA_IP_TCD_ATTR_DSIZE_SHIFT)) & DMA_IP_TCD_ATTR_DSIZE_MASK)
#define DMA_IP_TCD_ATTR_DMOD_MASK                   (0xF8U)
#define DMA_IP_TCD_ATTR_DMOD_SHIFT                  (3U)
#define DMA_IP_TCD_ATTR_DMOD_WIDTH                  (5U)
#define DMA_IP_TCD_ATTR_DMOD(x)                     (((uint16)(((uint16)(x)) << DMA_IP_TCD_ATTR_DMOD_SHIFT)) & DMA_IP_TCD_ATTR_DMOD_MASK)
#define DMA_IP_TCD_ATTR_SSIZE_MASK                  (0x700U)
#define DMA_IP_TCD_ATTR_SSIZE_SHIFT                 (8U)
#define DMA_IP_TCD_ATTR_SSIZE_WIDTH                 (3U)
#define DMA_IP_TCD_ATTR_SSIZE(x)                    (((uint16)(((uint16)(x)) << DMA_IP_TCD_ATTR_SSIZE_SHIFT)) & DMA_IP_TCD_ATTR_SSIZE_MASK)
#define DMA_IP_TCD_ATTR_SMOD_MASK                   (0xF800U)
#define DMA_IP_TCD_ATTR_SMOD_SHIFT                  (11U)
#define DMA_IP_TCD_ATTR_SMOD_WIDTH                  (5U)
#define DMA_IP_TCD_ATTR_SMOD(x)                     (((uint16)(((uint16)(x)) << DMA_IP_TCD_ATTR_SMOD_SHIFT)) & DMA_IP_TCD_ATTR_SMOD_MASK)
/*! @} */

/*! NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */
#define DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_MASK       (0x3FFFFFFFU)
#define DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT      (0U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_WIDTH      (30U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES(x)         (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFNO_NBYTES_MASK)
#define DMA_IP_TCD_NBYTES_MLOFFNO_DMLOE_MASK        (0x40000000U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT       (30U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_DMLOE_WIDTH       (1U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_DMLOE(x)          (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFNO_DMLOE_MASK)
#define DMA_IP_TCD_NBYTES_MLOFFNO_SMLOE_MASK        (0x80000000U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT       (31U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_SMLOE_WIDTH       (1U)
#define DMA_IP_TCD_NBYTES_MLOFFNO_SMLOE(x)          (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */
#define DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_MASK      (0x3FFU)
#define DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT     (0U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_WIDTH     (10U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES(x)        (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFYES_NBYTES_MASK)
#define DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK       (0x3FFFFC00U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT      (10U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_WIDTH      (20U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF(x)         (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK       (0x40000000U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT      (30U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_WIDTH      (1U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE(x)         (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFYES_DMLOE_MASK)
#define DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK       (0x80000000U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT      (31U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_WIDTH      (1U)
#define DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE(x)         (((uint32)(((uint32)(x)) << DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_IP_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! reg_SLAST_SDA - TCD Last Source Address Adjustment / Store reg_DADDR Address */
/*! @{ */
#define DMA_IP_TCD_SLAST_SDA_SLAST_SDA_MASK         (0xFFFFFFFFU)
#define DMA_IP_TCD_SLAST_SDA_SLAST_SDA_SHIFT        (0U)
#define DMA_IP_TCD_SLAST_SDA_SLAST_SDA_WIDTH        (32U)
#define DMA_IP_TCD_SLAST_SDA_SLAST_SDA(x)           (((uint32)(((uint32)(x)) << DMA_IP_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_IP_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! reg_DADDR - TCD Destination Address */
/*! @{ */
#define DMA_IP_TCD_DADDR_DADDR_MASK                 (0xFFFFFFFFU)
#define DMA_IP_TCD_DADDR_DADDR_SHIFT                (0U)
#define DMA_IP_TCD_DADDR_DADDR_WIDTH                (32U)
#define DMA_IP_TCD_DADDR_DADDR(x)                   (((uint32)(((uint32)(x)) << DMA_IP_TCD_DADDR_DADDR_SHIFT)) & DMA_IP_TCD_DADDR_DADDR_MASK)
/*! @} */

/*! reg_DOFF - TCD Signed Destination Address Offset */
/*! @{ */
#define DMA_IP_TCD_DOFF_DOFF_MASK                   (0xFFFFU)
#define DMA_IP_TCD_DOFF_DOFF_SHIFT                  (0U)
#define DMA_IP_TCD_DOFF_DOFF_WIDTH                  (16U)
#define DMA_IP_TCD_DOFF_DOFF(x)                     (((uint16)(((uint16)(x)) << DMA_IP_TCD_DOFF_DOFF_SHIFT)) & DMA_IP_TCD_DOFF_DOFF_MASK)
/*! @} */

/*! CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */
#define DMA_IP_TCD_CITER_ELINKNO_CITER_MASK         (0x7FFFU)
#define DMA_IP_TCD_CITER_ELINKNO_CITER_SHIFT        (0U)
#define DMA_IP_TCD_CITER_ELINKNO_CITER_WIDTH        (15U)
#define DMA_IP_TCD_CITER_ELINKNO_CITER(x)           (((uint16)(((uint16)(x)) << DMA_IP_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA_IP_TCD_CITER_ELINKNO_CITER_MASK)
#define DMA_IP_TCD_CITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_IP_TCD_CITER_ELINKNO_ELINK_SHIFT        (15U)
#define DMA_IP_TCD_CITER_ELINKNO_ELINK_WIDTH        (1U)
#define DMA_IP_TCD_CITER_ELINKNO_ELINK(x)           (((uint16)(((uint16)(x)) << DMA_IP_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA_IP_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */
#define DMA_IP_TCD_CITER_ELINKYES_CITER_MASK        (0x1FFU)
#define DMA_IP_TCD_CITER_ELINKYES_CITER_SHIFT       (0U)
#define DMA_IP_TCD_CITER_ELINKYES_CITER_WIDTH       (9U)
#define DMA_IP_TCD_CITER_ELINKYES_CITER(x)          (((uint16)(((uint16)(x)) << DMA_IP_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA_IP_TCD_CITER_ELINKYES_CITER_MASK)
#define DMA_IP_TCD_CITER_ELINKYES_LINKCH_MASK       (0x3E00U)
#define DMA_IP_TCD_CITER_ELINKYES_LINKCH_SHIFT      (9U)
#define DMA_IP_TCD_CITER_ELINKYES_LINKCH_WIDTH      (5U)
#define DMA_IP_TCD_CITER_ELINKYES_LINKCH(x)         (((uint16)(((uint16)(x)) << DMA_IP_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_IP_TCD_CITER_ELINKYES_LINKCH_MASK)
#define DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_IP_TCD_CITER_ELINKYES_ELINK_SHIFT       (15U)
#define DMA_IP_TCD_CITER_ELINKYES_ELINK_WIDTH       (1U)
#define DMA_IP_TCD_CITER_ELINKYES_ELINK(x)          (((uint16)(((uint16)(x)) << DMA_IP_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA_IP_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! reg_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */
#define DMA_IP_TCD_DLAST_SGA_DLAST_SGA_MASK         (0xFFFFFFFFU)
#define DMA_IP_TCD_DLAST_SGA_DLAST_SGA_SHIFT        (0U)
#define DMA_IP_TCD_DLAST_SGA_DLAST_SGA_WIDTH        (32U)
#define DMA_IP_TCD_DLAST_SGA_DLAST_SGA(x)           (((uint32)(((uint32)(x)) << DMA_IP_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_IP_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! reg_CSR - TCD Control and Status */
/*! @{ */
#define DMA_IP_TCD_CSR_START_MASK                   (0x1U)
#define DMA_IP_TCD_CSR_START_SHIFT                  (0U)
#define DMA_IP_TCD_CSR_START_WIDTH                  (1U)
#define DMA_IP_TCD_CSR_START(x)                     (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_START_SHIFT)) & DMA_IP_TCD_CSR_START_MASK)
#define DMA_IP_TCD_CSR_INTMAJOR_MASK                (0x2U)
#define DMA_IP_TCD_CSR_INTMAJOR_SHIFT               (1U)
#define DMA_IP_TCD_CSR_INTMAJOR_WIDTH               (1U)
#define DMA_IP_TCD_CSR_INTMAJOR(x)                  (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_INTMAJOR_SHIFT)) & DMA_IP_TCD_CSR_INTMAJOR_MASK)
#define DMA_IP_TCD_CSR_INTHALF_MASK                 (0x4U)
#define DMA_IP_TCD_CSR_INTHALF_SHIFT                (2U)
#define DMA_IP_TCD_CSR_INTHALF_WIDTH                (1U)
#define DMA_IP_TCD_CSR_INTHALF(x)                   (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_INTHALF_SHIFT)) & DMA_IP_TCD_CSR_INTHALF_MASK)
#define DMA_IP_TCD_CSR_DREQ_MASK                    (0x8U)
#define DMA_IP_TCD_CSR_DREQ_SHIFT                   (3U)
#define DMA_IP_TCD_CSR_DREQ_WIDTH                   (1U)
#define DMA_IP_TCD_CSR_DREQ(x)                      (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_DREQ_SHIFT)) & DMA_IP_TCD_CSR_DREQ_MASK)
#define DMA_IP_TCD_CSR_ESG_MASK                     (0x10U)
#define DMA_IP_TCD_CSR_ESG_SHIFT                    (4U)
#define DMA_IP_TCD_CSR_ESG_WIDTH                    (1U)
#define DMA_IP_TCD_CSR_ESG(x)                       (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_ESG_SHIFT)) & DMA_IP_TCD_CSR_ESG_MASK)
#define DMA_IP_TCD_CSR_MAJORELINK_MASK              (0x20U)
#define DMA_IP_TCD_CSR_MAJORELINK_SHIFT             (5U)
#define DMA_IP_TCD_CSR_MAJORELINK_WIDTH             (1U)
#define DMA_IP_TCD_CSR_MAJORELINK(x)                (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_MAJORELINK_SHIFT)) & DMA_IP_TCD_CSR_MAJORELINK_MASK)
#define DMA_IP_TCD_CSR_EEOP_MASK                    (0x40U)
#define DMA_IP_TCD_CSR_EEOP_SHIFT                   (6U)
#define DMA_IP_TCD_CSR_EEOP_WIDTH                   (1U)
#define DMA_IP_TCD_CSR_EEOP(x)                      (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_EEOP_SHIFT)) & DMA_IP_TCD_CSR_EEOP_MASK)
#define DMA_IP_TCD_CSR_ESDA_MASK                    (0x80U)
#define DMA_IP_TCD_CSR_ESDA_SHIFT                   (7U)
#define DMA_IP_TCD_CSR_ESDA_WIDTH                   (1U)
#define DMA_IP_TCD_CSR_ESDA(x)                      (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_ESDA_SHIFT)) & DMA_IP_TCD_CSR_ESDA_MASK)
#define DMA_IP_TCD_CSR_MAJORLINKCH_MASK             (0x1F00U)
#define DMA_IP_TCD_CSR_MAJORLINKCH_SHIFT            (8U)
#define DMA_IP_TCD_CSR_MAJORLINKCH_WIDTH            (5U)
#define DMA_IP_TCD_CSR_MAJORLINKCH(x)               (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA_IP_TCD_CSR_MAJORLINKCH_MASK)
#define DMA_IP_TCD_CSR_BWC_MASK                     (0xC000U)
#define DMA_IP_TCD_CSR_BWC_SHIFT                    (14U)
#define DMA_IP_TCD_CSR_BWC_WIDTH                    (2U)
#define DMA_IP_TCD_CSR_BWC(x)                       (((uint16)(((uint16)(x)) << DMA_IP_TCD_CSR_BWC_SHIFT)) & DMA_IP_TCD_CSR_BWC_MASK)
/*! @} */

/*! BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */
#define DMA_IP_TCD_BITER_ELINKNO_BITER_MASK         (0x7FFFU)
#define DMA_IP_TCD_BITER_ELINKNO_BITER_SHIFT        (0U)
#define DMA_IP_TCD_BITER_ELINKNO_BITER_WIDTH        (15U)
#define DMA_IP_TCD_BITER_ELINKNO_BITER(x)           (((uint16)(((uint16)(x)) << DMA_IP_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA_IP_TCD_BITER_ELINKNO_BITER_MASK)
#define DMA_IP_TCD_BITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_IP_TCD_BITER_ELINKNO_ELINK_SHIFT        (15U)
#define DMA_IP_TCD_BITER_ELINKNO_ELINK_WIDTH        (1U)
#define DMA_IP_TCD_BITER_ELINKNO_ELINK(x)           (((uint16)(((uint16)(x)) << DMA_IP_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA_IP_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */
#define DMA_IP_TCD_BITER_ELINKYES_BITER_MASK        (0x1FFU)
#define DMA_IP_TCD_BITER_ELINKYES_BITER_SHIFT       (0U)
#define DMA_IP_TCD_BITER_ELINKYES_BITER_WIDTH       (9U)
#define DMA_IP_TCD_BITER_ELINKYES_BITER(x)          (((uint16)(((uint16)(x)) << DMA_IP_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA_IP_TCD_BITER_ELINKYES_BITER_MASK)
#define DMA_IP_TCD_BITER_ELINKYES_LINKCH_MASK       (0x3E00U)
#define DMA_IP_TCD_BITER_ELINKYES_LINKCH_SHIFT      (9U)
#define DMA_IP_TCD_BITER_ELINKYES_LINKCH_WIDTH      (5U)
#define DMA_IP_TCD_BITER_ELINKYES_LINKCH(x)         (((uint16)(((uint16)(x)) << DMA_IP_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_IP_TCD_BITER_ELINKYES_LINKCH_MASK)
#define DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_IP_TCD_BITER_ELINKYES_ELINK_SHIFT       (15U)
#define DMA_IP_TCD_BITER_ELINKYES_ELINK_WIDTH       (1U)
#define DMA_IP_TCD_BITER_ELINKYES_ELINK(x)          (((uint16)(((uint16)(x)) << DMA_IP_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA_IP_TCD_BITER_ELINKYES_ELINK_MASK)

/*==================================================================================================
                                        DMA MP STRUCTURE
==================================================================================================*/
typedef struct {
  __IO uint32 reg_CSR;                               /**< @brief Management Page Control, offset: 0x0 */
  __I  uint32 reg_ES;                                /**< @brief Management Page Error Status, offset: 0x4 */
  __I  uint32 reg_INT;                               /**< @brief Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32 reg_HRS;                               /**< @brief Management Page Hardware Request Status, offset: 0xC */
  uint8 Reserved[240];
  __IO uint32 reg_CH_GRPRI[DMA_IP_DMA_MP_GRPRI_COUNT];   /**< @brief Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
}Dma_Ip_Hwv3InstRegType;

/*==================================================================================================
                                         TCD STRUCTURE
==================================================================================================*/
typedef struct{
    uint32 reg_CH_CSR;                      /**< @brief Channel Control and Status, array offset: 0x0, array step: 0x1000 */
    uint32 reg_CH_ES;                       /**< @brief Channel Error Status, array offset: 0x4, array step: 0x1000 */
    uint32 reg_CH_INT;                      /**< @brief Channel Interrupt Status, array offset: 0x8, array step: 0x1000 */
    uint32 reg_CH_SBR;                      /**< @brief Channel System Bus, array offset: 0xC, array step: 0x1000 */
    uint32 reg_CH_PRI;                      /**< @brief Channel Priority, array offset: 0x10, array step: 0x1000 */
}Dma_Ip_ChRegType;

typedef struct {
    uint32 reg_SADDR;                       /**< @brief TCD Source Address, array offset: 0x20, array step: 0x1000 */
    uint16 reg_SOFF;                        /**< @brief TCD Signed Source Address Offset, array offset: 0x24, array step: 0x1000 */
    uint16 reg_ATTR;                        /**< @brief TCD Transfer Attributes, array offset: 0x26, array step: 0x1000 */
    union {                             /* offset: 0x28, array step: 0x1000 */
        uint32 reg_MLOFFNO;                 /**< @brief TCD Transfer Size without Minor Loop Offsets Register, array offset: 0x28, array step: 0x1000 */
        uint32 reg_MLOFFYES;                /**< @brief TCD Transfer Size with Minor Loop Offsets Register, array offset: 0x28, array step: 0x1000 */
    } reg_NBYTES;
    uint32 reg_SLAST_SDA;                   /**< @brief TCD Last Source Address Adjustment / Store reg_DADDR Address Register, array offset: 0x2C, array step: 0x1000 */
    uint32 reg_DADDR;                       /**< @brief TCD Destination Address, array offset: 0x30, array step: 0x1000 */
    uint16 reg_DOFF;                        /**< @brief TCD Signed Destination Address Offset, array offset: 0x34, array step: 0x1000 */
    union {                             /* offset: 0x36, array step: 0x1000 */
        uint16 reg_ELINKNO;                 /**< @brief TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x36, array step: 0x1000 */
        uint16 reg_ELINKYES;                /**< @brief TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x36, array step: 0x1000 */
    } reg_CITER;
    uint32 reg_DLAST_SGA;                   /**< @brief TCD Last Destination Address Adjustment / Scatter Gather Address Register, array offset: 0x38, array step: 0x1000 */
    uint16 reg_CSR;                         /**< @brief TCD Control and Status Register, array offset: 0x3C, array step: 0x1000 */
    union {                             /* offset: 0x3E, array step: 0x1000 */
        uint16 reg_ELINKNO;                 /**< @brief TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x3E, array step: 0x1000 */
        uint16 reg_ELINKYES;                /**< @brief TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x3E, array step: 0x1000 */
    } reg_BITER;
} Dma_Ip_TcdRegType, Dma_Ip_SwTcdRegType;

typedef struct {
    Dma_Ip_ChRegType tChReg;
    uint8 Reserved[12];
    Dma_Ip_TcdRegType tTcdReg;
} Dma_Ip_Hwv3ChTcdRegType;

#if (DMA_IP_TCD_NOT_ALIGNED == STD_OFF)
typedef struct {
    struct {
        Dma_Ip_Hwv3ChTcdRegType tChTcdReg;
        uint8 Reserved[DMA_IP_TCD_RESERVED];
    } TCD_RSV[DMA_IP_TCD_NOF_HWV3_CH];
} Dma_Ip_Hwv3TcdArrayType;
#endif

/*==================================================================================================
                                        DMA CRC STRUCTURE
==================================================================================================*/
#if (STD_ON == DMA_IP_DMACRC_IS_AVAILABLE)
typedef struct{
    uint32 reg_GEC;
}Dma_Ip_HwCrcGlobalType;

typedef struct{
    uint32 reg_CTL;
    uint32 reg_ICRC;
    uint32 reg_FCRC;
}Dma_Ip_HwCrcCtrlType;
#endif

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* #ifndef DMA_IP_CFG_DEVICE_REGISTERS_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

