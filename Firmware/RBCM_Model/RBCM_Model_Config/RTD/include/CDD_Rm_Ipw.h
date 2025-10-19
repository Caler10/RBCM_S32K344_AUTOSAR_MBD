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
#ifndef CDD_RM_IPW_H
#define CDD_RM_IPW_H

/**
*   @file CDD_Rm_Ipw.h
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rm_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_VENDOR_ID                      43
#define RM_IPW_AR_RELEASE_MAJOR_VERSION       4
#define RM_IPW_AR_RELEASE_MINOR_VERSION       7
#define RM_IPW_AR_RELEASE_REVISION_VERSION    0
#define RM_IPW_SW_MAJOR_VERSION               5
#define RM_IPW_SW_MINOR_VERSION               0
#define RM_IPW_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_IPW_VENDOR_ID != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#if (RM_IPW_ENABLE_XRDC == STD_ON)
#define RM_XRDC_UNKNOWN_DOMAIN           (XRDC_UNKNOWN_DOMAIN)

#endif

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
#define RM_SEMAPHORE_FREE                (SEMA42_IP_UNLOCKED_GATE)

#define RM_SEMAPHORE_UNKNOWN_DOMAINID    (SEMA42_IP_UNKNOWN_DOMAINID)
#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (RM_IPW_ENABLE_XRDC == STD_ON)
/** Enumeration listing secure attributes of a XRDC master */
typedef Xrdc_Ip_SecureAttributeType Rm_XrdcSecureAttributeType;

/** Structure used to retrieve information violation details and the domain ID where violation occured. */
typedef Xrdc_Ip_DomainIDErrStatusType Rm_XrdcDomainIDErrStatusType;

/** Master core type, use for PID feature*/
typedef Xrdc_Ip_MasterCoreType Rm_XrdcMasterCoreType;

/** Domain ID */
typedef uint32 Rm_DomainIdType;

typedef Xrdc_Ip_InstanceConfigType Rm_XrdcInstanceConfigType;
#endif /* if (RM_IPW_ENABLE_XRDC == STD_ON) */

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
/** Channel Type for Sema42 */
typedef uint8 Rm_Sema42_ChannelType;

/** Status Type for Sema42 */
typedef Sema42_Ip_StatusType Rm_Sema42_StatusType;
#endif

#if (RM_IPW_ENABLE_PFLASH == STD_ON)
/** Pflash Type for Master */
typedef Pflash_Ip_MasterType Rm_Pflash_MasterType;

/** Pflash Type for Access Right */
typedef Pflash_Ip_MasterAccessType Rm_Pflash_MasterAccessType;
#endif

#if (RM_IPW_ENABLE_XBIC == STD_ON)
/** Structure for error informations of Xbic Ip. */
typedef Xbic_Ip_ErrorStatusType Rm_Xbic_ErrorStatusType;
#endif
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

#if (RM_IPW_ENABLE_XRDC == STD_ON)
void Rm_Ipw_Xrdc_Init(Rm_Ipw_ConfigType const *pIpwConfig);

void Rm_Ipw_Xrdc_InstanceInit(Rm_XrdcInstanceConfigType const *pXrdcInstanceConfig);

void Rm_Ipw_Xrdc_SetProcessID(Rm_XrdcMasterCoreType MasterCore,
                              uint8 u8Pid,
                              Rm_XrdcSecureAttributeType SecureAttr);

void Rm_Ipw_Xrdc_GetDomainIDErrorStatus(uint32 u32Instance,
                                        Rm_XrdcDomainIDErrStatusType * pXrdcDomainIDErrorStatus);

uint32 Rm_Ipw_Xrdc_GetDomainID(uint32 u32Instance);

#endif /* if (RM_IPW_ENABLE_XRDC == STD_ON) */

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)

void Rm_Ipw_Sema4_Init(Rm_Ipw_ConfigType const *pIpwConfig);

Std_ReturnType Rm_Ipw_Sema4_LockGate(const uint8 u8LogicChannel,
                                     uint8 u8DomainId);

Std_ReturnType Rm_Ipw_Sema4_UnlockGate(const uint8 u8LogicChannel);

void Rm_Ipw_Sema4_ResetGate(const uint8 u8LogicChannel);

void Rm_Ipw_Sema4_ResetAllGates(void);

uint8 Rm_Ipw_Sema4_GetGateLocker(const uint8 u8LogicChannel);

Rm_DomainIdType Rm_Ipw_SemaphoreGetDomainID(Rm_Sema42_ChannelType ChannelNumber);

Rm_DomainIdType Rm_Ipw_Sema4_GetResetGateDomainId(Rm_Sema42_ChannelType ChannelNumber);

boolean Rm_Ipw_Sema4_IsResetGateStateIdle(Rm_Sema42_ChannelType ChannelNumber);

Rm_Sema42_ChannelType Rm_Ipw_Sema4_GetResetedGate(Rm_Sema42_ChannelType ChannelNumber);
#endif /* if (RM_IPW_ENABLE_SEMA42 == STD_ON) */

#if (RM_IPW_ENABLE_PFLASH == STD_ON)
void Rm_Ipw_Pflash_Init(Rm_Ipw_ConfigType const *pIpwConfig);

void Rm_Ipw_Pflash_SetAccessProtection(Rm_Pflash_MasterType eMaster,
                                       Rm_Pflash_MasterAccessType eAccess);

#endif

#if (RM_IPW_ENABLE_AXBS == STD_ON)
void Rm_Ipw_Axbs_Init(Rm_Ipw_ConfigType const *pIpwConfig);

void Rm_Ipw_Axbs_DeInit(Rm_Ipw_ConfigType const *pIpwConfig);

#endif

#if (RM_IPW_ENABLE_VIRT_WRAPPER == STD_ON)
void Rm_Ipw_Virt_Wrapper_Init(Rm_Ipw_ConfigType const *pIpwConfig);

#endif

#if (RM_IPW_ENABLE_XBIC == STD_ON)
void Rm_Ipw_Xbic_Init(Rm_Ipw_ConfigType const *pIpwConfig);

void Rm_Ipw_Xbic_EnableMasterFeedbackCheck(uint32 xbicInstance,
                                           uint8 masterPort,
                                           boolean bFeedbackCheckEnable);

void Rm_Ipw_Xbic_EnableSlaveEDCCheck(uint32 xbicInstance,
                                     uint8 slavePort,
                                     boolean bEDCCheckEnable);

void Rm_Ipw_Xbic_FeedbackCheckAndEDCCheckDisable(void);

void Rm_Ipw_Xbic_GetErrorStatus(uint32 xbicInstance,
                                Rm_Xbic_ErrorStatusType *pErrorStatus);

void Rm_Ipw_Xbic_ErrorInjection(uint32 xbicInstance,
                                uint8 slaveTarget,
                                uint8 masterTargetID,
                                uint8 synDecode);

void Rm_Ipw_Xbic_ErrorInjectionDisable(uint32 xbicInstance);
#endif

#if (RM_IPW_ENABLE_MSCM == STD_ON)
void Rm_Ipw_Mscm_Init(Rm_Ipw_ConfigType const * pIpwConfig);

#endif

#if (RM_IPW_ENABLE_DMA_MUX == STD_ON)
void Rm_Ipw_Dma_Mux_Init(Rm_Ipw_ConfigType const * pIpwConfig);

#endif
#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_RM_IPW_H */
