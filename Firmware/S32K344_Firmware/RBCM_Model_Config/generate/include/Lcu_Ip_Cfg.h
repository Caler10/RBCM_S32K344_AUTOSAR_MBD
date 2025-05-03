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
#ifndef LCU_IP_CFG_H_
#define LCU_IP_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Included files
 ******************************************************************************/

#include "Lcu_Ip_MBDT_PBcfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_CFG_VENDOR_ID                       43
#define LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_CFG_SW_MAJOR_VERSION                5
#define LCU_IP_CFG_SW_MINOR_VERSION                0
#define LCU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip_MBDT_PBcfg.h file are of the same vendor */
#if (LCU_IP_CFG_VENDOR_ID != LCU_IP_MBDT_PBCFG_VENDOR_ID)
    #error "Lcu_Ip_Cfg.h and Lcu_Ip_MBDT_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_MBDT_PBcfg.h file are of the same Autosar version */
#if ((LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION != LCU_IP_MBDT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_CFG_AR_RELEASE_MINOR_VERSION != LCU_IP_MBDT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_CFG_AR_RELEASE_REVISION_VERSION != LCU_IP_MBDT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg.h and Lcu_Ip_MBDT_PBcfg.h are different"
#endif

/* Check if header file and Lcu_Ip_MBDT_PBcfg.h file are of the same Software version */
#if ((LCU_IP_CFG_SW_MAJOR_VERSION != LCU_IP_MBDT_PBCFG_SW_MAJOR_VERSION) || \
     (LCU_IP_CFG_SW_MINOR_VERSION != LCU_IP_MBDT_PBCFG_SW_MINOR_VERSION) || \
     (LCU_IP_CFG_SW_PATCH_VERSION != LCU_IP_MBDT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Cfg.h and Lcu_Ip_MBDT_PBcfg.h are different"
#endif
    
/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

/* Number Of Configured Logic Instances */
#define LCU_IP_NOF_CFG_LOGIC_INSTANCES    ((uint32)1U)

/* Logic Instance 0 */
#define LCU_LOGIC_INSTANCE_0              ((uint32)0U)


/* Number Of Configured Logic Inputs */
#define LCU_IP_NOF_CFG_LOGIC_INPUTS       ((uint32)1U)

/* Logic Instance 0 */
#define LCU_LOGIC_INPUT_0                 ((uint32)0U)


/* Number Of Configured Logic Outputs */
#define LCU_IP_NOF_CFG_LOGIC_OUTPUTS      ((uint32)1U)

/* Logic Instance 0 */
#define LCU_LOGIC_OUTPUT_0                ((uint32)0U)

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"


extern const Lcu_Ip_InitType Lcu_Ip_xLcuInitPB_MBDT;

/* LCU Input De-Initialization Structure */
extern const Lcu_Ip_LogicInputConfigType Lcu_Ip_xLogicInputResetConfig;

/* LCU Output De-Initialization Structure */
extern const Lcu_Ip_LogicOutputConfigType Lcu_Ip_xLogicOutputResetConfig;

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

ISR(Lcu0_Ip_IRQHandler);

ISR(Lcu1_Ip_IRQHandler);

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif  /* #ifndef LCU_IP_CFG_H_ */

