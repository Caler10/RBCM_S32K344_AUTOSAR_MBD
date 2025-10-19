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
#ifndef DMA_IP_CFG_DEFINES_H_
#define DMA_IP_CFG_DEFINES_H_

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
#include "Std_Types.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_DEFINES_VENDOR_ID                       43
#define DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION                5
#define DMA_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define DMA_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types header file are of the same Autosar version */
#if ((DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Cfg_Defines.h and Std_Types.h are different"
#endif
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/*------------------------------------------------------/
/         DMA IP USER MODE SUPPORT                      /
/------------------------------------------------------*/

#define DMA_IP_USER_MODE_SUPPORT_IS_AVAILABLE    STD_OFF

#define DMA_IP_REG_PROT_AVAILABLE                STD_OFF

#define DMA_IP_MP_REG_PROT_AVAILABLE             STD_ON

#define DMA_IP_TCD_REG_PROT_AVAILABLE            STD_ON
/*-----------------------------------------------/
/  DMA IP SUPPORT                                /
/-----------------------------------------------*/
#define DMA_IP_IS_AVAILABLE           STD_ON
#define DMA_IP_DMACRC_IS_AVAILABLE    STD_OFF

#define DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE      STD_OFF

#define DMA_IP_MULTICORE_IS_AVAILABLE STD_OFF
#define DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE  STD_ON

#define DMA_IP_BUFFERED_WRITES_IS_AVAILABLE        STD_ON

#define DMA_IP_STORE_DST_ADDR_IS_AVAILABLE         STD_ON

#define DMA_IP_PREEMPTION_IS_AVAILABLE             STD_ON

#define DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE        STD_ON

#define DMA_IP_GROUP_PRIORITY_IS_AVAILABLE         STD_ON

#define DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE      STD_OFF

#define DMA_IP_SECURITY_LEVEL_IS_AVAILABLE         STD_OFF

#define DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE       STD_OFF

#define DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE      STD_ON

#define DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE  STD_OFF

#define DMA_IP_SWAP_SIZE_IS_AVAILABLE              STD_OFF
#define DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE          STD_ON
#define DMA_IP_IRQ_DISPATCHER_IS_AVAILABLE          STD_OFF
/*-----------------------------------------------/
/  DMA IP DEV ERROR DETECT SUPPORT               /
/-----------------------------------------------*/
#define DMA_IP_DEV_ERROR_DETECT                 STD_OFF

/*-----------------------------------------------/
/  DMA HARDWARE VERSION                          /
/-----------------------------------------------*/
#define DMA_IP_HWV2_IS_AVAILABLE                   STD_OFF
#define DMA_IP_HARDWARE_VERSION_2                  ((uint8)2U)
#define DMA_IP_HWV3_IS_AVAILABLE                   STD_ON
#define DMA_IP_HARDWARE_VERSION_3                  ((uint8)3U)
#define DMA_IP_HWV4_IS_AVAILABLE                   STD_OFF
#define DMA_IP_HARDWARE_VERSION_4                  ((uint8)4U)
#define DMA_IP_HWV5_IS_AVAILABLE                   STD_OFF
#define DMA_IP_HARDWARE_VERSION_5                  ((uint8)5U)

/*-------------------------------------------------------/
/  DMA PARAM LIST DIMENASION RELATED TO HARDWARE VERSION /
/-------------------------------------------------------*/
#define DMA_IP_HWV3_LOC_GLOBAL_PARAM_LIST_DIMENSION    ((uint32)11U)
#define DMA_IP_DMA_TOTAL_NOF_LOGIC_INST             ((uint32)1U)
#define DMA_IP_DMA_TOTAL_NOF_LOGIC_CHANNEL          ((uint32)3U)

/*-----------------------------------------------/
/  DMA HARDWARE INSTANCES                        /
/-----------------------------------------------*/
#define DMA_IP_HW_INST_0                        ((uint8)(0U))

/*-----------------------------------------------/
/  DMA HARDWARE CHANNELS                         /
/-----------------------------------------------*/
#define DMA_IP_HW_CH_0                          ((uint8)(0U))
#define DMA_IP_HW_CH_1                          ((uint8)(1U))
#define DMA_IP_HW_CH_2                          ((uint8)(2U))
#define DMA_IP_HW_CH_3                          ((uint8)(3U))
#define DMA_IP_HW_CH_4                          ((uint8)(4U))
#define DMA_IP_HW_CH_5                          ((uint8)(5U))
#define DMA_IP_HW_CH_6                          ((uint8)(6U))
#define DMA_IP_HW_CH_7                          ((uint8)(7U))
#define DMA_IP_HW_CH_8                          ((uint8)(8U))
#define DMA_IP_HW_CH_9                          ((uint8)(9U))
#define DMA_IP_HW_CH_10                         ((uint8)(10U))
#define DMA_IP_HW_CH_11                         ((uint8)(11U))
#define DMA_IP_HW_CH_12                         ((uint8)(12U))
#define DMA_IP_HW_CH_13                         ((uint8)(13U))
#define DMA_IP_HW_CH_14                         ((uint8)(14U))
#define DMA_IP_HW_CH_15                         ((uint8)(15U))
#define DMA_IP_HW_CH_16                         ((uint8)(16U))
#define DMA_IP_HW_CH_17                         ((uint8)(17U))
#define DMA_IP_HW_CH_18                         ((uint8)(18U))
#define DMA_IP_HW_CH_19                         ((uint8)(19U))
#define DMA_IP_HW_CH_20                         ((uint8)(20U))
#define DMA_IP_HW_CH_21                         ((uint8)(21U))
#define DMA_IP_HW_CH_22                         ((uint8)(22U))
#define DMA_IP_HW_CH_23                         ((uint8)(23U))
#define DMA_IP_HW_CH_24                         ((uint8)(24U))
#define DMA_IP_HW_CH_25                         ((uint8)(25U))
#define DMA_IP_HW_CH_26                         ((uint8)(26U))
#define DMA_IP_HW_CH_27                         ((uint8)(27U))
#define DMA_IP_HW_CH_28                         ((uint8)(28U))
#define DMA_IP_HW_CH_29                         ((uint8)(29U))
#define DMA_IP_HW_CH_30                         ((uint8)(30U))
#define DMA_IP_HW_CH_31                         ((uint8)(31U))

/*-----------------------------------------------/
/  DMA GROUP PRIORITY                            /
/-----------------------------------------------*/
#define DMA_IP_GROUP_PRIO0                      ((uint8)(0U))
#define DMA_IP_GROUP_PRIO1                      ((uint8)(1U))
#define DMA_IP_GROUP_PRIO2                      ((uint8)(2U))
#define DMA_IP_GROUP_PRIO3                      ((uint8)(3U))
#define DMA_IP_GROUP_PRIO4                      ((uint8)(4U))
#define DMA_IP_GROUP_PRIO5                      ((uint8)(5U))
#define DMA_IP_GROUP_PRIO6                      ((uint8)(6U))
#define DMA_IP_GROUP_PRIO7                      ((uint8)(7U))
#define DMA_IP_GROUP_PRIO8                      ((uint8)(8U))
#define DMA_IP_GROUP_PRIO9                      ((uint8)(9U))
#define DMA_IP_GROUP_PRIO10                     ((uint8)(10U))
#define DMA_IP_GROUP_PRIO11                     ((uint8)(11U))
#define DMA_IP_GROUP_PRIO12                     ((uint8)(12U))
#define DMA_IP_GROUP_PRIO13                     ((uint8)(13U))
#define DMA_IP_GROUP_PRIO14                     ((uint8)(14U))
#define DMA_IP_GROUP_PRIO15                     ((uint8)(15U))
#define DMA_IP_GROUP_PRIO16                     ((uint8)(16U))
#define DMA_IP_GROUP_PRIO17                     ((uint8)(17U))
#define DMA_IP_GROUP_PRIO18                     ((uint8)(18U))
#define DMA_IP_GROUP_PRIO19                     ((uint8)(19U))
#define DMA_IP_GROUP_PRIO20                     ((uint8)(20U))
#define DMA_IP_GROUP_PRIO21                     ((uint8)(21U))
#define DMA_IP_GROUP_PRIO22                     ((uint8)(22U))
#define DMA_IP_GROUP_PRIO23                     ((uint8)(23U))
#define DMA_IP_GROUP_PRIO24                     ((uint8)(24U))
#define DMA_IP_GROUP_PRIO25                     ((uint8)(25U))
#define DMA_IP_GROUP_PRIO26                     ((uint8)(26U))
#define DMA_IP_GROUP_PRIO27                     ((uint8)(27U))
#define DMA_IP_GROUP_PRIO28                     ((uint8)(28U))
#define DMA_IP_GROUP_PRIO29                     ((uint8)(29U))
#define DMA_IP_GROUP_PRIO30                     ((uint8)(30U))
#define DMA_IP_GROUP_PRIO31                     ((uint8)(31U))

/*-----------------------------------------------/
/  DMA CHANNEL PRIORITY                          /
/-----------------------------------------------*/
#define DMA_IP_LEVEL_PRIO0                      ((uint8)(0U))
#define DMA_IP_LEVEL_PRIO1                      ((uint8)(1U))
#define DMA_IP_LEVEL_PRIO2                      ((uint8)(2U))
#define DMA_IP_LEVEL_PRIO3                      ((uint8)(3U))
#define DMA_IP_LEVEL_PRIO4                      ((uint8)(4U))
#define DMA_IP_LEVEL_PRIO5                      ((uint8)(5U))
#define DMA_IP_LEVEL_PRIO6                      ((uint8)(6U))
#define DMA_IP_LEVEL_PRIO7                      ((uint8)(7U))

/*-----------------------------------------------/
/  DMA TRANSFER SIZE                             /
/-----------------------------------------------*/
#define DMA_IP_TRANSFER_SIZE_1_BYTE             ((uint8)(0U))
#define DMA_IP_TRANSFER_SIZE_2_BYTE             ((uint8)(1U))
#define DMA_IP_TRANSFER_SIZE_4_BYTE             ((uint8)(2U))
#define DMA_IP_TRANSFER_SIZE_8_BYTE             ((uint8)(3U))
#define DMA_IP_TRANSFER_SIZE_16_BYTE            ((uint8)(4U))
#define DMA_IP_TRANSFER_SIZE_32_BYTE            ((uint8)(5U))
#define DMA_IP_TRANSFER_SIZE_64_BYTE            ((uint8)(6U))

/*-----------------------------------------------/
/  DMA BANDWIDTH CONTROL                         /
/-----------------------------------------------*/
#define DMA_IP_BWC_ENGINE_NO_STALL              ((uint8)(0U))
#define DMA_IP_BWC_ENGINE_HPE                   ((uint8)(1U))
#define DMA_IP_BWC_ENGINE_4CYCLE_STALL          ((uint8)(2U))
#define DMA_IP_BWC_ENGINE_8CYCLE_STALL          ((uint8)(3U))

/*-----------------------------------------------/
/  DMA CONVERT DCHPRI                            /
/-----------------------------------------------*/
#define DMA_CHN_TO_DCHPRI_INDEX(x)               (x)


#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DMA_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

