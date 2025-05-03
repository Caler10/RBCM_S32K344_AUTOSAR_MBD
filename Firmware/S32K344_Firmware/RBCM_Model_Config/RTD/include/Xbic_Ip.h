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

#ifndef XBIC_IP_H
#define XBIC_IP_H

/**
*   @file Xbic_Ip.h
*
*   @addtogroup XBIC_IP XBIC IPV Driver
*   @{
*/

#if defined(__cplusplus)
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "SchM_Rm.h"
#include "Xbic_Ip_Cfg.h"
#include "Xbic_Ip_Device_Registers.h"

#ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XBIC_IP_VENDOR_ID                      43
#define RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION       4
#define RM_XBIC_IP_AR_RELEASE_MINOR_VERSION       7
#define RM_XBIC_IP_AR_RELEASE_REVISION_VERSION    0
#define RM_XBIC_IP_SW_MAJOR_VERSION               5
#define RM_XBIC_IP_SW_MINOR_VERSION               0
#define RM_XBIC_IP_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xbic_Ip_Cfg.h */
#if (RM_XBIC_IP_VENDOR_ID != RM_XBIC_IP_CFG_VENDOR_ID)
    #error "Xbic_Ip.h and Xbic_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip.h and Xbic_Ip_Cfg.h are different"
#endif
#if ((RM_XBIC_IP_SW_MAJOR_VERSION != RM_XBIC_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_SW_MINOR_VERSION != RM_XBIC_IP_CFG_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_SW_PATCH_VERSION != RM_XBIC_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip.h and Xbic_Ip_Cfg.h are different"
#endif

/* Checks against Xbic_Ip_Device_Registers.h */
#if (RM_XBIC_IP_VENDOR_ID != RM_XBIC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Xbic_Ip.h and Xbic_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip.h and Xbic_Ip_Device_Registers.h are different"
#endif
#if ((RM_XBIC_IP_SW_MAJOR_VERSION != RM_XBIC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_SW_MINOR_VERSION != RM_XBIC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_SW_PATCH_VERSION != RM_XBIC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip.h and Xbic_Ip_Device_Registers.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef XBIC_IP_ENABLE_USER_MODE_SUPPORT
        /* Checks against OsIf.h */
        #if ((RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (RM_XBIC_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Xbic_Ip.h and OsIf.h are different"
        #endif
    #endif
    /* Checks against SchM_Rm.h */
    #if ((RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION != SCHM_RM_AR_RELEASE_MAJOR_VERSION) || \
        (RM_XBIC_IP_AR_RELEASE_MINOR_VERSION != SCHM_RM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of XBIC_Ip.h and SchM_Rm.h are different"
    #endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/**
* @brief   Export XBIC configurations.
*/
XBIC_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief         Initialize Xbic with configuration of integrity checking for all of master/slave ports.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     pXbicConfig         : Pointer point to configuration of integrity checking for all of master/slave port.
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_Init(const Xbic_Ip_ConfigType *pXbicConfig);

/**
 * @brief         Enable/Disable feedback integrity checking for a specific master port.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     masterPort           : Master port number
 * @param[in]     bFeedbackCheckEnable : Specifies wheter the feedback integrity checking for the master port is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_EnableMasterFeedbackCheck(uint32 xbicInstance,
                                       uint8 masterPort,
                                       boolean bFeedbackCheckEnable);

/**
 * @brief         Enable/Disable attribute integrity checking for a specific slave port.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slavePort            : Slave port number
 * @param[in]     bEDCCheckEnable      : Specifies wheter the attribute integrity checking for the slave port is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_EnableSlaveEDCCheck(uint32 xbicInstance,
                                 uint8 slavePort,
                                 boolean bEDCCheckEnable);


/**
 * @brief         Disable all of feedback integrity checking for the master ports and attribute integrity checking for slave ports.
 *
 * @details       This function is Reentrant.
 *
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_FeedbackCheckAndEDCCheckDisable(void);

/**
 * @brief         Get error status of a Xbic instance.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     pErrorStatus         : Pointer points to the memory area containing the XBIC reports error information
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_IntegrityCheckerGetErrorStatus(uint32 xbicInstance,
                                            Xbic_Ip_ErrorStatusType *pErrorStatus);

/**
 * @brief         Inject an error into a master, a slave of a Xbic instance with a specific error code.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     slaveTarget          : Slave port number injected error
 * @param[in]     masterTargetID       : Master tagget ID number injected error
 * @param[in]     synDecode            : Error Syndrome injected
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_IntegrityErrorInjectionConfig(uint32 xbicInstance,
                                           uint8 slaveTarget,
                                           uint8 masterTargetID,
                                           uint8 synDecode);

/**
 * @brief         Disable Inject error a specific Xbic instance.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Xbic_Ip_IntegrityErrorInjectionDisable(uint32 xbicInstance);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* if (RM_IP_ENABLE_XBIC == STD_ON) */
#endif /* ifdef RM_IP_ENABLE_XBIC */

#if defined(__cplusplus)
}
#endif

/** @} */

#endif  /* XBIC_IP_H */
