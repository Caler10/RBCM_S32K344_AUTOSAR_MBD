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

#ifndef XRDC_IP_TRUSTEDFUNCTIONS_H
#define XRDC_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Xrdc_Ip_TrustedFunctions.h
*
*   @addtogroup XRDC_IP XRDC IPV Driver
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
#include "Xrdc_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               5
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define RM_XRDC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xrdc_Ip_Cfg.h header file are of the same vendor */
#if (RM_XRDC_IP_CFG_VENDOR_ID != RM_XRDC_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Xrdc_Ip_TrustedFunctions.h and Xrdc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Xrdc_Ip_Cfg.h header file are of the same Autosar version */
#if ((RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xrdc_Ip_TrustedFunctions.h and Xrdc_Ip_Cfg.h are different"
#endif
/* Check if current file and Xrdc_Ip_Cfg.h header file are of the same Software version */
#if ((RM_XRDC_IP_CFG_SW_MAJOR_VERSION != RM_XRDC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_MINOR_VERSION != RM_XRDC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_PATCH_VERSION != RM_XRDC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_TrustedFunctions.h and Xrdc_Ip_Cfg.h are different"
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
#ifdef RM_IP_ENABLE_XRDC
#if (RM_IP_ENABLE_XRDC == STD_ON)

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
* @brief        Initializes Extended Resource Domain Controller parameters
*
* @details
*
* @param[in]    pXrdcConfig:     Pointer for configuration Xrdc
*
* @return       void
*
* @api
*
*/
extern void Xrdc_Ip_Init_Privileged(Xrdc_Ip_ConfigType const *pXrdcConfig);

/**
 * @brief         Get domain ID of the current bus master making the transaction request
 *
 * @details
 *
 * @param[in]     u32Instance:     XRDC Instance number
 * @return        uint32
 * @retval        DID of the bus master making the current transaction request
 *
 * @api
 *
 * @pre
 *
 */
extern uint32 Xrdc_Ip_GetDomainID_Privileged(uint32 u32Instance);

/**
* @brief        Retrieve error details
* @details      This function implement errata workaround for safety measure of all platform
*
* @param[in]    u8Instance:                 XRDC Instance number
* @param[out]   pXrdcDomainIDErrorStatus:   Pointer getting error status
*
* @param[out]
*
* @return       void
*
* @api
*
*/
extern void Xrdc_Ip_GetDomainIDErrorStatus_Privileged(uint32 u32Instance,
                                                      Xrdc_Ip_DomainIDErrStatusType *pXrdcDomainIDErrorStatus);

/**
* @brief        Initializes Extended Resource Domain Controller Instance parameters
*
* @details
*
* @param[in]    pXrdcConfig:     Pointer for configuration Xrdc
*
* @return       void
*
* @api
*
*/

extern void Xrdc_Ip_InstanceInit_Privileged(Xrdc_Ip_InstanceConfigType const *pXrdcConfig);

/**
* @brief         Assign Process ID value to a core master
* @details
*
* @param[in]     MasterCore:        Index of configured core master
* @param[in]     u8Pid:             Process ID value
* @param[in]     eSecureAttr:       Secure attribute of configured core master
*
* @return        void
*
* @api
*
*/
extern void Xrdc_Ip_SetProcessID_Privileged(Xrdc_Ip_MasterCoreType MasterCore,
                                            uint8 u8Pid,
                                            Xrdc_Ip_SecureAttributeType eSecureAttr);


#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* (RM_IP_ENABLE_XRDC == STD_ON) */
#endif /* ifdef RM_IP_ENABLE_XRDC */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XRDC_IP_TRUSTEDFUNCTIONS_H */
