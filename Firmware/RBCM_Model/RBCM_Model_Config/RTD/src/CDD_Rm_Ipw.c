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

/**
*   @file CDD_Rm_Ipw.c
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
#include "CDD_Rm_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_VENDOR_ID_C                      43
#define RM_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define RM_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define RM_IPW_SW_MAJOR_VERSION_C               5
#define RM_IPW_SW_MINOR_VERSION_C               0
#define RM_IPW_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Ipw.h */
#if (RM_IPW_VENDOR_ID_C != RM_IPW_VENDOR_ID)
    #error "CDD_Rm_Ipw.c and CDD_Rm_Ipw.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION_C    != RM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION_C    != RM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION_C != RM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.c and CDD_Rm_Ipw.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION_C != RM_IPW_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION_C != RM_IPW_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION_C != RM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.c and CDD_Rm_Ipw.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_ON == RM_IPW_ENABLE_SEMA42)
#define RM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Rm_MemMap.h"
/**
* @brief          Global variable (pointer) used for storing the Sema42 logical channel configuration data.
*/
static const Rm_Ipw_Sema42_LogicChannelConfigType *Rm_Ipw_pSema42LogicChannelConfig = NULL_PTR;

#define RM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Rm_MemMap.h"
#endif
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

#if (RM_IPW_ENABLE_XRDC == STD_ON)
/**
* @brief        Rm_Ipw_Xrdc_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xrdc_Init(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Xrdc_Ip_Init(pIpwConfig->Rm_Ipw_pXrdcConfig);
}

/**
* @brief        Rm_Ipw_Xrdc_InstanceInit
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xrdc_InstanceInit(Rm_XrdcInstanceConfigType const * pXrdcInstanceConfig)
{
    Xrdc_Ip_InstanceInit(pXrdcInstanceConfig);
}

/**
* @brief        Rm_Ipw_Xrdc_SetProcessID
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xrdc_SetProcessID(Rm_XrdcMasterCoreType MasterCore,
                              uint8 u8Pid,
                              Rm_XrdcSecureAttributeType SecureAttr)
{
    Xrdc_Ip_SetProcessID(MasterCore, u8Pid, SecureAttr);
}

/**
* @brief        Rm_Ipw_Xrdc_GetDomainIDErrorStatus
* @details
*
* @param[in]    u32Instance                  Instance number
*
* @param[out]   pXrdcDomainIDErrorStatus    Pointer get error status
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xrdc_GetDomainIDErrorStatus(uint32 u32Instance,
                                        Rm_XrdcDomainIDErrStatusType *pXrdcDomainIDErrorStatus)
{
    Xrdc_Ip_GetDomainIDErrorStatus(u32Instance, pXrdcDomainIDErrorStatus);
}

/**
* @brief        Rm_Ipw_Xrdc_GetDomainID
* @details
*
* @param[in]    u32Instance     Instance number
*
* @param[out]
*
* @return       uint32          Current Domain ID or RM_XRDC_UNKNOWN_DOMAIN (0xFF) if the Domain ID is not in supported range.
*
* @api
*
*/
uint32 Rm_Ipw_Xrdc_GetDomainID(uint32 u32Instance)
{
    return Xrdc_Ip_GetDomainID(u32Instance);
}
#endif /* if (RM_IPW_ENABLE_XRDC == STD_ON) */

#if (RM_IPW_ENABLE_SEMA42 == STD_ON)
/**
* @brief        Rm_Ipw_Sema4_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Sema4_Init(Rm_Ipw_ConfigType const *pIpwConfig)
{
    uint8 instanceId = (uint8)0UL;

    Rm_Ipw_pSema42LogicChannelConfig = pIpwConfig->Rm_Ipw_pSema42Config->pLogicChannelArray;
    for (instanceId = (uint8)0UL; instanceId < SEMA42_IP_INSTANCE_COUNT; instanceId++)
    {
        Sema42_Ip_Init(instanceId);
    }
}

/**
* @brief        Rm_Ipw_Sema4_LockGate
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
Std_ReturnType Rm_Ipw_Sema4_LockGate(const uint8 u8LogicChannel,
                                     uint8 u8DomainId)
{
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;
    uint32 HardwareInstance = 0U;
    uint8 HardwareChannel = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u32HardwareInstance;
    /* Get hardware channel */
    HardwareChannel = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u8HardwareChannel;
    if ((Rm_Sema42_StatusType)SEMA42_IP_SUCCESS == (Rm_Sema42_StatusType)Sema42_Ip_LockGate(HardwareInstance, HardwareChannel, u8DomainId))
    {
        retVal = (Std_ReturnType)E_OK;
    }
    else
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }

    return retVal;
}

/**
* @brief        Rm_Ipw_Sema4_UnlockGate
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
Std_ReturnType Rm_Ipw_Sema4_UnlockGate(const uint8 u8LogicChannel)
{
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;
    uint32 HardwareInstance = 0U;
    uint8 HardwareChannel = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u32HardwareInstance;
    /* Get hardware channel */
    HardwareChannel = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u8HardwareChannel;
    if ((Rm_Sema42_StatusType)SEMA42_IP_SUCCESS == (Rm_Sema42_StatusType)Sema42_Ip_UnlockGate(HardwareInstance, HardwareChannel))
    {
        retVal = (Std_ReturnType)E_OK;
    }
    else
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }

    return retVal;
}

/**
* @brief        Rm_Ipw_Sema4_ResetGate
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Sema4_ResetGate(const uint8 u8LogicChannel)
{
    uint32 HardwareInstance = 0U;
    uint8 HardwareChannel = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u32HardwareInstance;
    /* Get hardware channel */
    HardwareChannel = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u8HardwareChannel;
    Sema42_Ip_ResetGate(HardwareInstance, HardwareChannel);
}

/**
* @brief        Rm_Ipw_Sema4_ResetAllGates
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Sema4_ResetAllGates(void)
{
    uint8 instanceId = (uint8)0UL;

    for (instanceId = (uint8)0UL; instanceId < SEMA42_IP_INSTANCE_COUNT; instanceId++)
    {
        Sema42_Ip_Init(instanceId);
    }
}

/**
* @brief        Get status of gate
* @details      Get status of gate
*
* @param[in]    u8Instance      Instance of gate want to check
* @param[in]    u8GateIndex     Gate want to check
*
* @return       gateLocker
* @retval       uint8           Index of the semaphore owner,
*                               or RM_SEMAPHORE_FREE (0xFF) if the gate is not locked,
*                               or RM_SEMAPHORE_UNKNOWN_DOMAINID (0xF0) if unknown domain ID that owns Sema42.
*
* @api
*
*/
uint8 Rm_Ipw_Sema4_GetGateLocker(const uint8 u8LogicChannel)
{
    uint8 gateLocker;
    uint32 HardwareInstance = 0U;
    uint8 HardwareChannel = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u32HardwareInstance;
    /* Get hardware channel */
    HardwareChannel = Rm_Ipw_pSema42LogicChannelConfig[u8LogicChannel].u8HardwareChannel;
    /* Get gate locker */
    gateLocker = Sema42_Ip_GetGateLocker(HardwareInstance, HardwareChannel);

    return gateLocker;
}

/**
* @brief          Get DomainId from Sema42 logic channel
* @details        This function is called to get DomainID.

* @param[in]      ChannelNumber       Logic channel want to use
*
* @return         uint32              DomainID
*
* @api
*
* @note
*/
Rm_DomainIdType Rm_Ipw_SemaphoreGetDomainID(Rm_Sema42_ChannelType ChannelNumber)
{
    Rm_DomainIdType retVal;
    uint32 HardwareInstance = 0U; 

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[ChannelNumber].u32HardwareInstance;
    /* Get DomainId */
    retVal = Rm_Ipw_Xrdc_GetDomainID(HardwareInstance);

    return retVal;
}

/**
* @brief          Get DomainId from Sema42 logic channel
* @details        This function is called to get DomainID.
*
* @param[in]      ChannelNumber       Logic channel want to get DomainID.
*
* @return         uint32              DomainID
*
* @api
*
* @note
*/
Rm_DomainIdType Rm_Ipw_Sema4_GetResetGateDomainId(Rm_Sema42_ChannelType ChannelNumber)
{
    uint32 retVal;
    uint32 HardwareInstance = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[ChannelNumber].u32HardwareInstance;
    /* Get DomainId */
    retVal = (uint32)Sema42_Ip_GetResetGateBusMaster(HardwareInstance);

    return retVal;
}

/**
* @brief          Check the reset gate state machine is idle.
* @details        Check if the current state of the reset gate state machine is idle on the instance of the semaphore channel.
*
* @param[in]      ChannelNumber       Logic channel on the instance want to check.
*
* @return         uint32              DomainID
*
* @api
*
* @note
*/
boolean Rm_Ipw_Sema4_IsResetGateStateIdle(Rm_Sema42_ChannelType ChannelNumber)
{
    boolean retVal;
    uint32 HardwareInstance = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[ChannelNumber].u32HardwareInstance;

    retVal = Sema42_Ip_IsResetGateStateIdle(HardwareInstance);

    return retVal;
}

/**
* @brief          Get the semaphore channel is targetted reset.
* @details        Get the logical channel which targetted by the most recent reset attempt on the instance of a semaphore channel.
*
* @param[in]      ChannelNumber       Logic channel on the instance want to check.
*
* @return         ChannelNumber       The semaphore channel is targetted reset.
*
* @api
*
* @note
*/
Rm_Sema42_ChannelType Rm_Ipw_Sema4_GetResetedGate(Rm_Sema42_ChannelType ChannelNumber)
{
    uint32 HardwareInstance = 0U;
    uint8 LogicChannel = 0U;
    uint8 ResetedChannel = 0U;

    /* Get hardware instance */
    HardwareInstance = Rm_Ipw_pSema42LogicChannelConfig[ChannelNumber].u32HardwareInstance;
    /* Get reseted channel*/
    ResetedChannel = Sema42_Ip_GetResetGateIndex(HardwareInstance);

    /* Look up logical channel.*/
    for (LogicChannel = 0 ; LogicChannel < RM_SEMAPHORE_CHANNEL_COUNT; LogicChannel++)
    {
        if (ResetedChannel == Rm_Ipw_pSema42LogicChannelConfig[LogicChannel].u8HardwareChannel)
        {
            if (HardwareInstance == Rm_Ipw_pSema42LogicChannelConfig[LogicChannel].u32HardwareInstance)
            {
                break;
            }
        }
    }
    if (LogicChannel >= RM_SEMAPHORE_CHANNEL_COUNT)
    {
        LogicChannel = RM_SEMA42_LOGIC_CH_UNUSED;
    }

    return LogicChannel;
}

#endif /* if (RM_IPW_ENABLE_SEMA42 == STD_ON) */

#if (RM_IPW_ENABLE_PFLASH == STD_ON)
/**
* @brief        Rm_Ipw_Pflash_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Pflash_Init(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Pflash_Ip_Init(pIpwConfig->Rm_Ipw_pPflashConfig);
}

/**
* @brief        Rm_Ipw_Pflash_SetAccessProtection
* @details      
*
* @param[in]    
*
* @param[out]   
*
* @return       
*
* @api
*
*/
void Rm_Ipw_Pflash_SetAccessProtection(Rm_Pflash_MasterType eMaster,
                                       Rm_Pflash_MasterAccessType eAccess)
{
    Pflash_Ip_SetAccessProtection(eMaster, eAccess);
}
#endif /* if (RM_IPW_ENABLE_PFLASH == STD_ON) */

#if (RM_IPW_ENABLE_AXBS == STD_ON)
/**
* @brief        Rm_Ipw_Axbs_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Axbs_Init(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Axbs_Ip_Init(pIpwConfig->Rm_Ipw_pAxbsConfig);
}

/**
* @brief        Rm_Ipw_Axbs_DeInit
* @details      Reset Axbs register to default value
*
* @param[in]    None
*
* @param[out]   None
*
* @return       None
*
* @api
*
*/
void Rm_Ipw_Axbs_DeInit(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Axbs_Ip_DeInit(pIpwConfig->Rm_Ipw_pAxbsConfig);
}
#endif /* if (RM_IPW_ENABLE_AXBS == STD_ON) */

#if (RM_IPW_ENABLE_VIRT_WRAPPER == STD_ON)
/**
* @brief        Rm_Ipw_Virt_Wrapper_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Virt_Wrapper_Init(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Virt_Wrapper_Ip_Init(pIpwConfig->Rm_Ipw_pVirt_WrapperConfig);
}

#endif

#if (RM_IPW_ENABLE_XBIC == STD_ON)
/**
* @brief        Rm_Ipw_Xbic_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_Init(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Xbic_Ip_Init(pIpwConfig->Rm_Ipw_pXbicConfig);
}

/**
* @brief        Rm_Ipw_Xbic_EnableMasterFeedbackCheck
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_EnableMasterFeedbackCheck(uint32 xbicInstance,
                                           uint8 masterPort,
                                           boolean bFeedbackCheckEnable)
{
    Xbic_Ip_EnableMasterFeedbackCheck(xbicInstance, masterPort, bFeedbackCheckEnable);
}

/**
* @brief        Rm_Ipw_Xbic_EnableSlaveEDCCheck
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_EnableSlaveEDCCheck(uint32 xbicInstance,
                                     uint8 slavePort,
                                     boolean bEDCCheckEnable)
{
    Xbic_Ip_EnableSlaveEDCCheck(xbicInstance, slavePort, bEDCCheckEnable);
}

/**
* @brief        Rm_Ipw_Xbic_FeedbackCheckAndEDCCheckDisable
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_FeedbackCheckAndEDCCheckDisable(void)
{
    Xbic_Ip_FeedbackCheckAndEDCCheckDisable();
}

/**
* @brief        Rm_Ipw_Xbic_GetErrorStatus
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_GetErrorStatus(uint32 xbicInstance,
                                Rm_Xbic_ErrorStatusType *pErrorStatus)
{
    Xbic_Ip_IntegrityCheckerGetErrorStatus(xbicInstance, pErrorStatus);
}

/**
* @brief        Rm_Ipw_Xbic_ErrorInjection
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_ErrorInjection(uint32 xbicInstance,
                                uint8 slaveTarget,
                                uint8 masterTargetID,
                                uint8 synDecode)
{
    Xbic_Ip_IntegrityErrorInjectionConfig(xbicInstance, slaveTarget, masterTargetID, synDecode);
}

/**
* @brief        Rm_Ipw_Xbic_ErrorInjectionDisable
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Xbic_ErrorInjectionDisable(uint32 xbicInstance)
{
    Xbic_Ip_IntegrityErrorInjectionDisable(xbicInstance);
}

#endif /* if (RM_IPW_ENABLE_XBIC == STD_ON) */

#if (RM_IPW_ENABLE_DMA_MUX == STD_ON)
/**
* @brief        Rm_Ipw_Dma_Mux_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Dma_Mux_Init(Rm_Ipw_ConfigType const * pIpwConfig)
{
    Dma_Mux_Ip_Init(pIpwConfig->Rm_Ipw_pDma_MuxConfig);
}

#endif

#if (RM_IPW_ENABLE_MSCM == STD_ON)
/**
* @brief        Rm_Ipw_Mscm_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Rm_Ipw_Mscm_Init(Rm_Ipw_ConfigType const *pIpwConfig)
{
    Mscm_Ip_Init(pIpwConfig->Rm_Ipw_pMscmConfig);
}

#endif

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
