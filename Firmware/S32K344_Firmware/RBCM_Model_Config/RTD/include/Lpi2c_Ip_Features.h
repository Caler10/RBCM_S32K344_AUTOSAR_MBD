/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
*   only be used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef LPI2C_IP_FEATURES_H
#define LPI2C_IP_FEATURES_H

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_FEATURES_VENDOR_ID                      43
#define LPI2C_IP_FEATURES_AR_RELEASE_MAJOR_VERSION       4
#define LPI2C_IP_FEATURES_AR_RELEASE_MINOR_VERSION       7
#define LPI2C_IP_FEATURES_AR_RELEASE_REVISION_VERSION    0
#define LPI2C_IP_FEATURES_SW_MAJOR_VERSION               5
#define LPI2C_IP_FEATURES_SW_MINOR_VERSION               0
#define LPI2C_IP_FEATURES_SW_PATCH_VERSION               0

/* @brief E10792: LPI2C: Slave Transmit Data Flag may incorrectly read as one when TXCFG is zero.
 * Interrupts for transfer data should be enabled after the address valid event is detected and
 * disabled at the end of the transfer. */
#define ERRATA_E10792

/* LPI2C module features */

/* @brief Disable high-speed and ultra-fast operating modes for S32K14x. */
#define LPI2C_IP_HAS_FAST_PLUS_MODE (0U)
#define LPI2C_IP_HAS_HIGH_SPEED_MODE (0U)
#define LPI2C_IP_HAS_ULTRA_FAST_MODE (0U)

/* @brief DMA instance used for LPI2C module */
#define LPI2C_IP_DMA_INSTANCE 0U

#ifdef __cplusplus
}
#endif
/** @}*/

#endif /* LPI2C_IP_FEATURES_H */

