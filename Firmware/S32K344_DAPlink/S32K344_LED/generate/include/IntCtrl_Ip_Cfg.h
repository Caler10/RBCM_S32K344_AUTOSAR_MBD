/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef INTCTRL_IP_CFG_H_
#define INTCTRL_IP_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_TypesDef.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION        0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION                   4
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION                   0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/* Declaration of the configuration structure for Interrupt Controller (core related) */
extern const IntCtrl_Ip_CtrlConfigType intCtrlConfig;
/* Declaration of the ISR Handlers */
extern void undefined_handler(void);
extern void SIUL2_EXT_IRQ_8_15_ISR(void);
extern void EMIOS0_1_IRQ(void);
extern void EMIOS0_3_IRQ(void);
extern void EMIOS0_5_IRQ(void);
extern void EMIOS1_0_IRQ(void);
extern void EMIOS1_1_IRQ(void);
extern void EMIOS1_5_IRQ(void);
extern void EMIOS2_5_IRQ(void);
extern void Bctu_0_Isr(void);
extern void PIT_0_ISR(void);
extern void CAN0_ORED_IRQHandler(void);
extern void CAN0_ORED_0_31_MB_IRQHandler(void);
extern void CAN0_ORED_32_63_MB_IRQHandler(void);
extern void CAN0_ORED_64_95_MB_IRQHandler(void);
extern void CAN4_ORED_IRQHandler(void);
extern void CAN4_ORED_0_31_MB_IRQHandler(void);
extern void MCL_FLEXIO_ISR(void);
extern void LPUART5_LIN_IP_RxTx_IRQHandler(void);
extern void LPUART_UART_IP_6_IRQHandler(void);
extern void LPI2C0_Master_Slave_IRQHandler(void);
extern void LPI2C1_Master_Slave_IRQHandler(void);
extern void Lpspi_Ip_LPSPI_1_IRQHandler(void);
extern void Lpspi_Ip_LPSPI_2_IRQHandler(void);
extern void Adc_Sar_0_Isr(void);
extern void Adc_Sar_1_Isr(void);
extern void Adc_Sar_2_Isr(void);

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#endif /* INTCTRL_IP_CFG_H_ */

