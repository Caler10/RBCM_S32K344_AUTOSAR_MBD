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
#ifndef LCU_IP_TYPES_SOC_H_
#define LCU_IP_TYPES_SOC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
*   @file    Lcu_Ip_Regs.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - LCU IP driver header file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
*   @{
*/

#include "Lcu_Ip_Features.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_REGS_VENDOR_ID                       43
#define LCU_IP_REGS_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_REGS_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_REGS_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_REGS_SW_MAJOR_VERSION                5
#define LCU_IP_REGS_SW_MINOR_VERSION                0
#define LCU_IP_REGS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip_Features.h file are of the same vendor */
#if (LCU_IP_REGS_VENDOR_ID != LCU_IP_FEATURES_VENDOR_ID)
    #error "Lcu_Ip_Regs.h and Lcu_Ip_Features.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same Autosar version */
#if ((LCU_IP_REGS_AR_RELEASE_MAJOR_VERSION != LCU_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_REGS_AR_RELEASE_MINOR_VERSION != LCU_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_REGS_AR_RELEASE_REVISION_VERSION != LCU_IP_FEATURES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Regs.h and Lcu_Ip_Features.h are different"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same Software version */
#if ((LCU_IP_REGS_SW_MAJOR_VERSION != LCU_IP_FEATURES_SW_MAJOR_VERSION) || \
     (LCU_IP_REGS_SW_MINOR_VERSION != LCU_IP_FEATURES_SW_MINOR_VERSION) || \
     (LCU_IP_REGS_SW_PATCH_VERSION != LCU_IP_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Regs.h and Lcu_Ip_Features.h are different"
#endif

/*==================================================================================================
                                        LCU STRUCTURE
==================================================================================================*/

/*! @} */

#define LCU_FCTRL_FORCE_SENSE_COMMON_MASK           (0xFU)
#define LCU_FCTRL_FORCE_MODE_COMMON_MASK            (0x30U)
#define LCU_FCTRL_SYNC_SEL_COMMON_MASK              (0xC0U)

/*! @name FCTRL */
/*! @{ */
#define LCU_FCTRL_FORCE_SENSE_MASK(ID)              ((uint32)(LCU_FCTRL_FORCE_SENSE_COMMON_MASK) << ((uint32)(ID)*8U))
#define LCU_FCTRL_FORCE_SENSE_SHIFT(ID)             ((uint32)(ID)*8U)
#define LCU_FCTRL_FORCE_SENSE_WIDTH                 (4U)
#define LCU_FCTRL_FORCE_SENSE(ID,x)                 (((uint32)(((uint32)(x)) << (uint32)LCU_FCTRL_FORCE_SENSE_SHIFT(ID))) & (uint32)LCU_FCTRL_FORCE_SENSE_MASK(ID))
#define LCU_FCTRL_FORCE_MODE_MASK(ID)               ((uint32)(LCU_FCTRL_FORCE_MODE_COMMON_MASK) << ((uint32)(ID)*8U))
#define LCU_FCTRL_FORCE_MODE_SHIFT(ID)              (4U + ((uint32)(ID)*8U))
#define LCU_FCTRL_FORCE_MODE_WIDTH                  (2U)
#define LCU_FCTRL_FORCE_MODE(ID,x)                  (((uint32)(((uint32)(x)) << (uint32)LCU_FCTRL_FORCE_MODE_SHIFT(ID))) & (uint32)LCU_FCTRL_FORCE_MODE_MASK(ID))
#define LCU_FCTRL_SYNC_SEL_MASK(ID)                 ((uint32)(LCU_FCTRL_SYNC_SEL_COMMON_MASK) << ((uint32)(ID)*8U))
#define LCU_FCTRL_SYNC_SEL_SHIFT(ID)                (6U + ((uint32)(ID)*8U))
#define LCU_FCTRL_SYNC_SEL_WIDTH                    (2U)
#define LCU_FCTRL_SYNC_SEL(ID,x)                    (((uint32)(((uint32)(x)) << (uint32)LCU_FCTRL_SYNC_SEL_SHIFT(ID))) & (uint32)LCU_FCTRL_SYNC_SEL_MASK(ID))

/* LCU mapping inputID to position in register */
#define LCU_IP_MAPPING_INPUT_TO_LC(HwLcInputId)         (uint8)((uint8)(HwLcInputId) / LCU_NUM_INPUT_PER_LC)
#define LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId)       (uint8)((uint8)(HwLcOutputId) / LCU_NUM_OUTPUT_PER_LC)
/* LCU mapping outputID to position in register */
#define LCU_IP_MAPPING_INTPUT_ID_TO_HW_INPUT(HwLcInputId)              ((uint8)((uint8)(HwLcInputId) % LCU_NUM_INPUT_PER_LC))
#define LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId)            ((uint8)((uint8)(HwLcOutputId) % LCU_NUM_OUTPUT_PER_LC))
/** @} */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef LCU_IP_TYPES_SOC_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

