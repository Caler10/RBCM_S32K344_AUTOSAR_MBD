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

#ifndef MSCM_IP_CFG_DEFINES_H
#define MSCM_IP_CFG_DEFINES_H

/**
*   @file Mscm_Ip_Cfg_Defines.h
*
*   @addtogroup MSCM_IP MSCM IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/**
 * Include specific header file
 */
#include "Std_Types.h" 
#include "S32K344_MSCM.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_CFG_DEFINES_VENDOR_ID                          43
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
#define RM_MSCM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   5
#define RM_MSCM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define RM_MSCM_IP_CFG_DEFINES_SW_PATCH_VERSION                   0

/*==================================================================================================
*                                   FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against Std_Types.h */
#if ((RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mscm_Ip_Cfg_Defines.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief    Core Mask to write MSCM Register */
#define MSCM_IP_CORE_MASK                           (1U)
/** @brief    Development error checking */
#define MSCM_IP_DEV_ERROR_DETECT                    (STD_ON)
/** @brief        Last implemented interrupt routing */
#define MSCM_IP_SPI_MAX                             (217U)
/** @brief        Number of SPI Routing Support */
#define MSCM_IP_SPI_COUNT                           (150U)

/** @brief        SPI Number Configuration */
#define MSCM_CPU_TO_CPU_INT0                            (0U)
#define MSCM_CPU_TO_CPU_INT1                            (1U)
#define MSCM_CPU_TO_CPU_INT2                            (2U)
#define MSCM_CPU_TO_CPU_INT3                            (3U)
#define MSCM_DMA_TCD_0                                  (4U)
#define MSCM_DMA_TCD_1                                  (5U)
#define MSCM_DMA_TCD_2                                  (6U)
#define MSCM_DMA_TCD_3                                  (7U)
#define MSCM_DMA_TCD_4                                  (8U)
#define MSCM_DMA_TCD_5                                  (9U)
#define MSCM_DMA_TCD_6                                  (10U)
#define MSCM_DMA_TCD_7                                  (11U)
#define MSCM_DMA_TCD_8                                  (12U)
#define MSCM_DMA_TCD_9                                  (13U)
#define MSCM_DMA_TCD_10                                 (14U)
#define MSCM_DMA_TCD_11                                 (15U)
#define MSCM_DMA_TCD_12                                 (16U)
#define MSCM_DMA_TCD_13                                 (17U)
#define MSCM_DMA_TCD_14                                 (18U)
#define MSCM_DMA_TCD_15                                 (19U)
#define MSCM_DMA_TCD_16                                 (20U)
#define MSCM_DMA_TCD_17                                 (21U)
#define MSCM_DMA_TCD_18                                 (22U)
#define MSCM_DMA_TCD_19                                 (23U)
#define MSCM_DMA_TCD_20                                 (24U)
#define MSCM_DMA_TCD_21                                 (25U)
#define MSCM_DMA_TCD_22                                 (26U)
#define MSCM_DMA_TCD_23                                 (27U)
#define MSCM_DMA_TCD_24                                 (28U)
#define MSCM_DMA_TCD_25                                 (29U)
#define MSCM_DMA_TCD_26                                 (30U)
#define MSCM_DMA_TCD_27                                 (31U)
#define MSCM_DMA_TCD_28                                 (32U)
#define MSCM_DMA_TCD_29                                 (33U)
#define MSCM_DMA_TCD_30                                 (34U)
#define MSCM_DMA_TCD_31                                 (35U)
#define MSCM_ERROR_REPORTING_SINGLE_BIT_ECC             (36U)
#define MSCM_ERROR_REPORTING_MULTI_BIT_ECC              (37U)
#define MSCM_MCM                                        (38U)
#define MSCM_SYSTEM_TIMER_MODULE_0                      (39U)
#define MSCM_SYSTEM_TIMER_MODULE_1                      (40U)
#define MSCM_WATCHDOG_0                                 (42U)
#define MSCM_CTI_INTERRUPT_0                            (45U)
#define MSCM_CTI_INTERRUPT_1                            (46U)
#define MSCM_FLASH_PROGRAM_OR_ERASE_COMPLETED           (48U)
#define MSCM_FLASH_MAIN_WATCHDOG_TIMEOUT_INTERRUPT      (49U)
#define MSCM_FLASH_ALTERNATE_WATCHDOG_TIMEOUT_INTERRUPT (50U)
#define MSCM_RESET_GENERATION_MODULE                    (51U)
#define MSCM_PMC                                        (52U)
#define MSCM_SIUL_IRQ0                                  (53U)
#define MSCM_SIUL_IRQ1                                  (54U)
#define MSCM_SIUL_IRQ2                                  (55U)
#define MSCM_SIUL_IRQ3                                  (56U)
#define MSCM_EMIOS_0_INTERRUPT_REQUEST_23               (61U)
#define MSCM_EMIOS_0_INTERRUPT_REQUEST_19               (62U)
#define MSCM_EMIOS_0_INTERRUPT_REQUEST_15               (63U)
#define MSCM_EMIOS_0_INTERRUPT_REQUEST_11               (64U)
#define MSCM_EMIOS_0_INTERRUPT_REQUEST_7                (65U)
#define MSCM_EMIOS_0_INTERRUPT_REQUEST_3                (66U)
#define MSCM_EMIOS_1_INTERRUPT_REQUEST_23               (69U)
#define MSCM_EMIOS_1_INTERRUPT_REQUEST_19               (70U)
#define MSCM_EMIOS_1_INTERRUPT_REQUEST_15               (71U)
#define MSCM_EMIOS_1_INTERRUPT_REQUEST_11               (72U)
#define MSCM_EMIOS_1_INTERRUPT_REQUEST_7                (73U)
#define MSCM_EMIOS_1_INTERRUPT_REQUEST_3                (74U)
#define MSCM_EMIOS_2_INTERRUPT_REQUEST_23               (77U)
#define MSCM_EMIOS_2_INTERRUPT_REQUEST_19               (78U)
#define MSCM_EMIOS_2_INTERRUPT_REQUEST_15               (79U)
#define MSCM_EMIOS_2_INTERRUPT_REQUEST_11               (80U)
#define MSCM_EMIOS_2_INTERRUPT_REQUEST_7                (81U)
#define MSCM_EMIOS_2_INTERRUPT_REQUEST_3                (82U)
#define MSCM_WAKEUP_UNIT                                (83U)
#define MSCM_CMU_0                                      (84U)
#define MSCM_CMU_1                                      (85U)
#define MSCM_CMU_2                                      (86U)
#define MSCM_BODY_CROSS_TRIGGERING_UNIT                 (87U)
#define MSCM_LOGIC_CONTROL_UNIT_0                       (92U)
#define MSCM_LOGIC_CONTROL_UNIT_1                       (93U)
#define MSCM_PIT_0                                      (96U)
#define MSCM_PIT_1                                      (97U)
#define MSCM_PIT_2                                      (98U)
#define MSCM_RTC                                        (102U)
#define MSCM_EMAC_0                                     (105U)
#define MSCM_EMAC_1                                     (106U)
#define MSCM_EMAC_2                                     (107U)
#define MSCM_EMAC_3                                     (108U)
#define MSCM_FLEXCAN0_0                                 (109U)
#define MSCM_FLEXCAN0_1                                 (110U)
#define MSCM_FLEXCAN0_2                                 (111U)
#define MSCM_FLEXCAN0_3                                 (112U)
#define MSCM_FLEXCAN1_0                                 (113U)
#define MSCM_FLEXCAN1_1                                 (114U)
#define MSCM_FLEXCAN1_2                                 (115U)
#define MSCM_FLEXCAN2_0                                 (116U)
#define MSCM_FLEXCAN2_1                                 (117U)
#define MSCM_FLEXCAN2_2                                 (118U)
#define MSCM_FLEXCAN3_0                                 (119U)
#define MSCM_FLEXCAN3_1                                 (120U)
#define MSCM_FLEXCAN4_0                                 (121U)
#define MSCM_FLEXCAN4_1                                 (122U)
#define MSCM_FLEXCAN5_0                                 (123U)
#define MSCM_FLEXCAN5_1                                 (124U)
#define MSCM_FLEXIBLE_IO                                (139U)
#define MSCM_LPUART_0                                   (141U)
#define MSCM_LPUART_1                                   (142U)
#define MSCM_LPUART_2                                   (143U)
#define MSCM_LPUART_3                                   (144U)
#define MSCM_LPUART_4                                   (145U)
#define MSCM_LPUART_5                                   (146U)
#define MSCM_LPUART_6                                   (147U)
#define MSCM_LPUART_7                                   (148U)
#define MSCM_LPUART_8                                   (149U)
#define MSCM_LPUART_9                                   (150U)
#define MSCM_LPUART_10                                  (151U)
#define MSCM_LPUART_11                                  (152U)
#define MSCM_LPUART_12                                  (153U)
#define MSCM_LPUART_13                                  (154U)
#define MSCM_LPUART_14                                  (155U)
#define MSCM_LPUART_15                                  (156U)
#define MSCM_LPI2C_0_MASTER_INTERRUPT                   (161U)
#define MSCM_LPI2C_1_MASTER_INTERRUPT                   (162U)
#define MSCM_LPSPI_0                                    (165U)
#define MSCM_LPSPI_1                                    (166U)
#define MSCM_LPSPI_2                                    (167U)
#define MSCM_LPSPI_3                                    (168U)
#define MSCM_LPSPI_4                                    (169U)
#define MSCM_LPSPI_5                                    (170U)
#define MSCM_QSPI                                       (173U)
#define MSCM_SYNCHRONOUS_AUDIO_INTERFACE_0              (174U)
#define MSCM_SYNCHRONOUS_AUDIO_INTERFACE_1              (175U)
#define MSCM_JDC_JTAG                                   (178U)
#define MSCM_ADC_0                                      (180U)
#define MSCM_ADC_1                                      (181U)
#define MSCM_ADC_2                                      (182U)
#define MSCM_LOW_POWER_COMPARATOR_0                     (183U)
#define MSCM_LOW_POWER_COMPARATOR_1                     (184U)
#define MSCM_LOW_POWER_COMPARATOR_2                     (185U)
#define MSCM_FAULT_COLLECTION_CONTROL_UNIT_0            (189U)
#define MSCM_FAULT_COLLECTION_CONTROL_UNIT_1            (190U)
#define MSCM_SELF_TEST_CONTROL_UNIT                     (191U)
#define MSCM_MU_0_MUB_EXCEPTION_0                       (192U)
#define MSCM_MU_0_MUB_EXCEPTION_1                       (193U)
#define MSCM_MU_0_MUB_EXCEPTION_2                       (194U)
#define MSCM_MU_1_MUB_EXCEPTION_0                       (195U)
#define MSCM_MU_1_MUB_EXCEPTION_1                       (196U)
#define MSCM_MU_1_MUB_EXCEPTION_2                       (197U)
#define MSCM_SOC_PLL_LOL_INTERRUPT                      (212U)
#define MSCM_SOC_CORE_CLK_FAIL_REACT_INT                (213U)
#define MSCM_SOC_AIPS_PLAT_CLK_FAIL_REACT_INT           (215U)
#define MSCM_SOC_HSE_B_CLK_FAIL_REACT_INT               (217U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MSCM_IP_CFG_DEFINES_H */

