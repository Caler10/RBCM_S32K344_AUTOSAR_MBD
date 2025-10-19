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

#ifndef DMA_MUX_IP_CFG_DEFINES_H
#define DMA_MUX_IP_CFG_DEFINES_H

/**
*   @file Dma_Mux_Ip_CfgDefines.h
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
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
#include "S32K344_DMAMUX.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_MAJOR_VERSION             5
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against Std_Types.h */
#if ((RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Mux_Ip_Cfg_Defines.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define RM_IP_ENABLE_DMA_MUX                (STD_ON)
/** @brief    Development error checking */
#define DMA_MUX_IP_DEV_ERROR_DETECT         (STD_ON)

#define DMA_MUX_IP_INSTANCE_COUNT            (2UL)
#define DMA_MUX_IP_INSTANCE_BASE_PTRS        {IP_DMAMUX_0, IP_DMAMUX_1}
#define DMA_MUX_IP_GATE_OFFSET(x)           ((x) ^ ((uint8)3UL))

/* Define the DMA_MUX instance by index number in the DMA_MUX instance list*/
#define DMA_MUX_INSTANCE_0                 (0U)
#define DMA_MUX_INSTANCE_1                 (1U)


/* Sources of DMA_MUX_INSTANCE_0 */
#define DMA_MUX_0_REQ_DISABLED                                        (0U)
#define DMA_MUX_0_SIUL2_0                                             (1U)
#define DMA_MUX_0_SIUL2_1                                             (2U)
#define DMA_MUX_0_SIUL2_2                                             (3U)
#define DMA_MUX_0_SIUL2_3                                             (4U)
#define DMA_MUX_0_SIUL2_4                                             (5U)
#define DMA_MUX_0_SIUL2_5                                             (6U)
#define DMA_MUX_0_SIUL2_6                                             (7U)
#define DMA_MUX_0_SIUL2_7                                             (8U)
#define DMA_MUX_0_BCTU_FIFO1_REQUEST                                  (9U)
#define DMA_MUX_0_BCTU_0                                              (10U)
#define DMA_MUX_0_BCTU_1                                              (11U)
#define DMA_MUX_0_EMIOS_0_0                                           (12U)
#define DMA_MUX_0_EMIOS_0_1                                           (13U)
#define DMA_MUX_0_EMIOS_0_9                                           (14U)
#define DMA_MUX_0_EMIOS_0_10                                          (15U)
#define DMA_MUX_0_EMIOS_1_0                                           (16U)
#define DMA_MUX_0_EMIOS_1_1                                           (17U)
#define DMA_MUX_0_EMIOS_1_9                                           (18U)
#define DMA_MUX_0_EMIOS_1_10                                          (19U)
#define DMA_MUX_0_EMIOS_2_0                                           (20U)
#define DMA_MUX_0_EMIOS_2_1                                           (21U)
#define DMA_MUX_0_EMIOS_2_9                                           (22U)
#define DMA_MUX_0_EMIOS_2_10                                          (23U)
#define DMA_MUX_0_LCU_0_0                                             (24U)
#define DMA_MUX_0_LCU_1_0                                             (25U)
#define DMA_MUX_0_FLEXCAN_0_REQUEST                                   (29U)
#define DMA_MUX_0_FLEXCAN_1_REQUEST                                   (30U)
#define DMA_MUX_0_FLEXCAN_2_REQUEST                                   (31U)
#define DMA_MUX_0_FLEXCAN_3_REQUEST                                   (32U)
#define DMA_MUX_0_FLEXIO_SHIFTER0                                     (33U)
#define DMA_MUX_0_FLEXIO_TIMER0                                       (33U)
#define DMA_MUX_0_FLEXIO_SHIFTER1                                     (34U)
#define DMA_MUX_0_FLEXIO_TIMER1                                       (34U)
#define DMA_MUX_0_FLEXIO_SHIFTER2                                     (35U)
#define DMA_MUX_0_FLEXIO_TIMER2                                       (35U)
#define DMA_MUX_0_FLEXIO_SHIFTER3                                     (36U)
#define DMA_MUX_0_FLEXIO_TIMER3                                       (36U)
#define DMA_MUX_0_LPUART_0_TRANSMIT                                   (37U)
#define DMA_MUX_0_LPUART_8_TRANSMIT                                   (37U)
#define DMA_MUX_0_LPUART_0_RECEIVE                                    (38U)
#define DMA_MUX_0_LPUART_8_RECEIVE                                    (38U)
#define DMA_MUX_0_LPUART_1_TRANSMIT                                   (39U)
#define DMA_MUX_0_LPUART_9_TRANSMIT                                   (39U)
#define DMA_MUX_0_LPUART_1_RECEIVE                                    (40U)
#define DMA_MUX_0_LPUART_9_RECEIVE                                    (40U)
#define DMA_MUX_0_LPI2C0_RX_REQUEST                                   (41U)
#define DMA_MUX_0_LPI2C0_RX_SLAVE_REQUEST                             (41U)
#define DMA_MUX_0_LPI2C0_TX_REQUEST                                   (42U)
#define DMA_MUX_0_LPI2C0_TX_SLAVE_REQUEST                             (42U)
#define DMA_MUX_0_LPSPI_0_TX_REQUEST                                  (43U)
#define DMA_MUX_0_LPSPI_0_RX_REQUEST                                  (44U)
#define DMA_MUX_0_LPSPI_1_TX_REQUEST                                  (45U)
#define DMA_MUX_0_LPSPI_1_RX_REQUEST                                  (46U)
#define DMA_MUX_0_LPSPI_2_TX_REQUEST                                  (47U)
#define DMA_MUX_0_LPSPI_2_RX_REQUEST                                  (48U)
#define DMA_MUX_0_LPSPI_3_TX_REQUEST                                  (49U)
#define DMA_MUX_0_LPSPI_3_RX_REQUEST                                  (50U)
#define DMA_MUX_0_QSPI_RX_BUFFER_DRAIN                                (53U)
#define DMA_MUX_0_QSPI_TX_BUFFER_FILL                                 (54U)
#define DMA_MUX_0_SAI_0_RECEIVE_REQUEST                               (55U)
#define DMA_MUX_0_SAI_0_TRANSMIT_REQUEST                              (56U)
#define DMA_MUX_0_ADC_0_REQUEST                                       (58U)
#define DMA_MUX_0_ADC_1_REQUEST                                       (59U)
#define DMA_MUX_0_ADC_2_REQUEST                                       (60U)
#define DMA_MUX_0_LPCMP_0_COUT_REQUEST                                (61U)
#define DMA_MUX_0_REQ_ALWAYS_ON_0                                     (62U)
#define DMA_MUX_0_REQ_ALWAYS_ON_1                                     (63U)

/* Sources of DMA_MUX_INSTANCE_1 */
#define DMA_MUX_1_REQ_DISABLED                                        (0U)
#define DMA_MUX_1_SIUL2_8                                             (1U)
#define DMA_MUX_1_SIUL2_9                                             (2U)
#define DMA_MUX_1_SIUL2_10                                            (3U)
#define DMA_MUX_1_SIUL2_11                                            (4U)
#define DMA_MUX_1_SIUL2_12                                            (5U)
#define DMA_MUX_1_SIUL2_13                                            (6U)
#define DMA_MUX_1_SIUL2_14                                            (7U)
#define DMA_MUX_1_SIUL2_15                                            (8U)
#define DMA_MUX_1_BCTU_FIFO2_REQUEST                                  (9U)
#define DMA_MUX_1_BCTU_2                                              (10U)
#define DMA_MUX_1_EMIOS_0_16                                          (11U)
#define DMA_MUX_1_EMIOS_0_17                                          (12U)
#define DMA_MUX_1_EMIOS_0_18                                          (13U)
#define DMA_MUX_1_EMIOS_0_19                                          (14U)
#define DMA_MUX_1_EMIOS_1_16                                          (15U)
#define DMA_MUX_1_EMIOS_1_17                                          (16U)
#define DMA_MUX_1_EMIOS_1_18                                          (17U)
#define DMA_MUX_1_EMIOS_1_19                                          (18U)
#define DMA_MUX_1_EMIOS_2_16                                          (19U)
#define DMA_MUX_1_EMIOS_2_17                                          (20U)
#define DMA_MUX_1_EMIOS_2_18                                          (21U)
#define DMA_MUX_1_EMIOS_2_19                                          (22U)
#define DMA_MUX_1_LCU_0_1                                             (23U)
#define DMA_MUX_1_LCU_0_2                                             (24U)
#define DMA_MUX_1_LCU_1_1                                             (25U)
#define DMA_MUX_1_LCU_1_2                                             (26U)
#define DMA_MUX_1_EMAC_PTP_TIMER_CH0                                  (27U)
#define DMA_MUX_1_EMAC_PTP_TIMER_CH1                                  (27U)
#define DMA_MUX_1_EMAC_PTP_TIMER_CH2                                  (27U)
#define DMA_MUX_1_EMAC_PTP_TIMER_CH3                                  (27U)
#define DMA_MUX_1_FLEXCAN_4_REQUEST                                   (30U)
#define DMA_MUX_1_FLEXCAN_5_REQUEST                                   (31U)
#define DMA_MUX_1_FLEXIO_SHIFTER4                                     (34U)
#define DMA_MUX_1_FLEXIO_TIMER4                                       (34U)
#define DMA_MUX_1_FLEXIO_SHIFTER5                                     (35U)
#define DMA_MUX_1_FLEXIO_TIMER5                                       (35U)
#define DMA_MUX_1_FLEXIO_SHIFTER6                                     (36U)
#define DMA_MUX_1_FLEXIO_TIMER6                                       (36U)
#define DMA_MUX_1_FLEXIO_SHIFTER7                                     (37U)
#define DMA_MUX_1_FLEXIO_TIMER7                                       (37U)
#define DMA_MUX_1_LPUART_2_TRANSMIT                                   (38U)
#define DMA_MUX_1_LPUART_10_TRANSMIT                                  (38U)
#define DMA_MUX_1_LPUART_2_RECEIVE                                    (39U)
#define DMA_MUX_1_LPUART_10_RECEIVE                                   (39U)
#define DMA_MUX_1_LPUART_3_TRANSMIT                                   (40U)
#define DMA_MUX_1_LPUART_11_TRANSMIT                                  (40U)
#define DMA_MUX_1_LPUART_3_RECEIVE                                    (41U)
#define DMA_MUX_1_LPUART_11_RECEIVE                                   (41U)
#define DMA_MUX_1_LPUART_4_TRANSMIT                                   (42U)
#define DMA_MUX_1_LPUART_12_TRANSMIT                                  (42U)
#define DMA_MUX_1_LPUART_4_RECEIVE                                    (43U)
#define DMA_MUX_1_LPUART_12_RECEIVE                                   (43U)
#define DMA_MUX_1_LPUART_5_TRANSMIT                                   (44U)
#define DMA_MUX_1_LPUART_13_TRANSMIT                                  (44U)
#define DMA_MUX_1_LPUART_5_RECEIVE                                    (45U)
#define DMA_MUX_1_LPUART_13_RECEIVE                                   (45U)
#define DMA_MUX_1_LPUART_6_TRANSMIT                                   (46U)
#define DMA_MUX_1_LPUART_14_TRANSMIT                                  (46U)
#define DMA_MUX_1_LPUART_6_RECEIVE                                    (47U)
#define DMA_MUX_1_LPUART_14_RECEIVE                                   (47U)
#define DMA_MUX_1_LPUART_7_TRANSMIT                                   (48U)
#define DMA_MUX_1_LPUART_15_TRANSMIT                                  (48U)
#define DMA_MUX_1_LPUART_7_RECEIVE                                    (49U)
#define DMA_MUX_1_LPUART_15_RECEIVE                                   (49U)
#define DMA_MUX_1_LPI2C1_RX_REQUEST                                   (50U)
#define DMA_MUX_1_LPI2C1_RX_SLAVE_REQUEST                             (50U)
#define DMA_MUX_1_LPI2C1_TX_REQUEST                                   (51U)
#define DMA_MUX_1_LPI2C1_TX_SLAVE_REQUEST                             (51U)
#define DMA_MUX_1_LPSPI_4_TX_REQUEST                                  (52U)
#define DMA_MUX_1_LPSPI_4_RX_REQUEST                                  (53U)
#define DMA_MUX_1_LPSPI_5_TX_REQUEST                                  (54U)
#define DMA_MUX_1_LPSPI_5_RX_REQUEST                                  (55U)
#define DMA_MUX_1_SAI_1_RECEIVE_REQUEST                               (56U)
#define DMA_MUX_1_SAI_1_TRANSMIT_REQUEST                              (57U)
#define DMA_MUX_1_LPCMP_1_COUT_REQUEST                                (60U)
#define DMA_MUX_1_LPCMP_2_COUT_REQUEST                                (61U)
#define DMA_MUX_1_REQ_ALWAYS_ON_0                                     (62U)
#define DMA_MUX_1_REQ_ALWAYS_ON_1                                     (63U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_MUX_IP_CFG_DEFINES_H */

