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

#ifndef XBIC_IP_TRUSTEDFUNCTIONS_H
#define XBIC_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Xbic_Ip_TrustedFunctions.h
*
*   @addtogroup XBIC_IP XBIC IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Xbic_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             5
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define RM_XBIC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xbic_Ip_Cfg.h header file are of the same vendor */
#if (RM_XBIC_IP_CFG_VENDOR_ID != RM_XBIC_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Xbic_Ip_TrustedFunctions.h and Xbic_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Xbic_Ip_Cfg.h header file are of the same Autosar version */
#if ((RM_XBIC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xbic_Ip_TrustedFunctions.h and Xbic_Ip_Cfg.h are different"
#endif
/* Check if current file and Xbic_Ip_Cfg.h header file are of the same Software version */
#if ((RM_XBIC_IP_CFG_SW_MAJOR_VERSION != RM_XBIC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_CFG_SW_MINOR_VERSION != RM_XBIC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_CFG_SW_PATCH_VERSION != RM_XBIC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xbic_Ip_TrustedFunctions.h and Xbic_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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
#ifdef RM_IP_ENABLE_XBIC
#if (RM_IP_ENABLE_XBIC == STD_ON)

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief        This function write into the register.
 *
 * @param[in]    address   The register address.
 * @param[in]    value     The value will be written.
 *
 * */
extern void Xbic_Ip_WriteRegister(uint32 address,
                                  uint32 value);

/**
 * @brief        This function return the value of register.
 *
 * @param[in]    address   The register address.
 *
 * @return       uint32    The value of register.
 *
 * */
extern uint32 Xbic_Ip_ReadRegister(uint32 address);

/**
 * @brief         Enable/Disable feedback integrity checking for a specific master port.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     masterPort           : Master port number
 * @param[in]     bFeedbackCheckEnable : Specifies wheter the feedback integrity checking for the master port is enabled or disabled
 * @return        void
 *
 * */
extern void Xbic_Ip_MasterFeedbackCheck(uint32 xbicInstance,
                                        uint8 masterPort,
                                        boolean bFeedbackCheckEnable);

/**
 * @brief         Enable/Disable attribute integrity checking for a specific slave port.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slavePort            : Slave port number
 * @param[in]     bEDCCheckEnable      : Specifies wheter the attribute integrity checking for the slave port is enabled or disabled
 * @return        void
 *
 * */
extern void Xbic_Ip_SlaveEDCCheck(uint32 xbicInstance,
                                  uint8 slavePort,
                                  boolean bEDCCheckEnable);

/**
 * @brief         Inject an error into a master, a slave of a Xbic instance with a specific error code.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slaveTarget          : Slave port number injected error
 * @param[in]     masterTargetID       : Master tagget ID number injected error
 * @param[in]     synDecode            : Error Syndrome injected
 * @return        void
 *
 * */
extern void Xbic_Ip_LLD_IntegrityErrorInjectionConfig(uint32 xbicInstance,
                                                      uint8 slaveTarget,
                                                      uint8 masterTargetID,
                                                      uint8 synDecode);

/**
 * @brief         Disable Inject error a specific Xbic instance.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
extern void Xbic_Ip_LLD_IntegrityErrorInjectionDisable(uint32 xbicInstance);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* (RM_IP_ENABLE_XBIC == STD_ON) */
#endif /* RM_IP_ENABLE_XBIC */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XBIC_IP_TRUSTEDFUNCTIONS_H */
