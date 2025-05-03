/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
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

#ifndef OS_VERSION_H
#define OS_VERSION_H

/**
*   @file Os_version.h
*
*   @addtogroup [OS]
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

#define OS_VENDOR_ID                    43    /* Freescale AUTOSAR Vendor ID  */
#define OS_MODULE_ID                    0x01   /* OS Module ID                 */

#define OS_AR_RELEASE_MAJOR_VERSION     4   /* Major version number of AUTOSAR specification       */
#define OS_AR_RELEASE_MINOR_VERSION     7   /* Minor version number of AUTOSAR specification       */
#define OS_AR_RELEASE_REVISION_VERSION  0   /* Patch level version number of AUTOSAR specification */

#define OS_SW_MAJOR_VERSION             5   /* Major version number of the implementation   */
#define OS_SW_MINOR_VERSION             0   /* Minor version number of the implementation   */
#define OS_SW_PATCH_VERSION             0    /* Patch level version number of the implementation */



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OS_VERSION_H */
