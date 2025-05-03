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
*   @file CDD_Rm.c
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
 *  1) system and project includes
 *  2) needed interfaces from external units
 *  3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rm.h"
#include "Mcal.h"

#if (RM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
 *                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VENDOR_ID_C                      43

#define RM_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_AR_RELEASE_MINOR_VERSION_C       7
#define RM_AR_RELEASE_REVISION_VERSION_C    0
#define RM_SW_MAJOR_VERSION_C               5
#define RM_SW_MINOR_VERSION_C               0
#define RM_SW_PATCH_VERSION_C               0

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm.h */
#if (RM_VENDOR_ID_C != RM_VENDOR_ID)
    #error "CDD_Rm.c and CDD_Rm.h have different vendor ids"
#endif
#if ((RM_AR_RELEASE_MAJOR_VERSION_C    != RM_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AR_RELEASE_MINOR_VERSION_C    != RM_AR_RELEASE_MINOR_VERSION) || \
     (RM_AR_RELEASE_REVISION_VERSION_C != RM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm.c and CDD_Rm.h are different"
#endif
#if ((RM_SW_MAJOR_VERSION_C != RM_SW_MAJOR_VERSION) || \
     (RM_SW_MINOR_VERSION_C != RM_SW_MINOR_VERSION) || \
     (RM_SW_PATCH_VERSION_C != RM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm.c and CDD_Rm.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of CDD_Rm.c and Mcal.h are different"
    #endif

    #if (RM_DEV_ERROR_DETECT == STD_ON)
        /* Checks against Det.h */
        #if ((RM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (RM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of CDD_Rm.c and Det.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (RM_DEV_ERROR_DETECT == STD_ON)
#define RM_MODULES_INITIALIZED 10U
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
#if (RM_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Rm_ValidateGlobalCall(uint8 u8ServiceId,
                                            Rm_Init_Type eInit_Type);
static Std_ReturnType Rm_ValidatePtrInit(Rm_ConfigType const * ConfigPtr);
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief Init function for Group 1 Ip: Mscm, Dmamux, Canhub and Pflash
 * 
 * @param ConfigPtr Pointer to a selected configuration structure.
 * @return void
 */
static void Rm_InitGroup1(Rm_ConfigType const *ConfigPtr);
#endif /* STD_ON == RM_ENABLE_GLOBAL_INIT */

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief Init function for Group 2 Ip: Axbs and Xbic
 * 
 * @param ConfigPtr Pointer to a selected configuration structure.
 * @return void
 */
static void Rm_InitGroup2(Rm_ConfigType const *ConfigPtr);
#endif /* STD_ON == RM_ENABLE_GLOBAL_INIT */

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief Init function for Group 3 Ip: Xrdc, Sema42 and Virtual Wrapper
 * 
 * @param ConfigPtr Pointer to a selected configuration structure.
 * @return void
 */
static void Rm_InitGroup3(Rm_ConfigType const *ConfigPtr);
#endif /* STD_ON == RM_ENABLE_GLOBAL_INIT */

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Rm_MemMap.h"
/**
* @brief          Global variable (pointer) used for storing the Rm driver configuration data.
*/
static Rm_ConfigType const *Rm_pConfig  = NULL_PTR;

#if (RM_DEV_ERROR_DETECT == STD_ON)
static boolean Rm_abInitializedModules[RM_MODULES_INITIALIZED] = {(boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE};
#endif

#define RM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Rm_MemMap.h"

/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == RM_ENABLE_SEMA42)
#if (RM_DEV_ERROR_DETECT == STD_ON)
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"
static Std_ReturnType Rm_ValidateSemaphoreChannelCall(Rm_Sema42_ChannelType ChannelNumber,
                                                      uint8 u8ServiceId);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"
#endif
#endif
/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

#if (RM_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for Rm_Init.
 *
 * @param[in]  u8ServiceId The service id of the caller function
 *
 * @return          The validity of the function call
 * @retval          E_OK      The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 * @implements
 * */
static Std_ReturnType Rm_ValidateGlobalCall(uint8 u8ServiceId,
                                            Rm_Init_Type eInit_Type)
{
    Std_ReturnType valid = (Std_ReturnType)E_NOT_OK;

    if (TRUE == Rm_abInitializedModules[eInit_Type]) /* Check if already initialized */
    {
        if (RM_INIT_ID_U8 == u8ServiceId) /* If caller is the initialization function, error */
        {
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)u8ServiceId, RM_E_ALREADY_INITIALIZED_U8);
        }
        else
        {
            valid = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        if (RM_INIT_ID_U8 == u8ServiceId) /* If caller is the initialization function, ok */
        {
            valid = (Std_ReturnType)E_OK;
        }
        else
        {
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)u8ServiceId, RM_E_UNINIT_U8);
        }
    }

    return valid;
}

/**
 * @brief              This function validate the initialization pointer.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 *
 * */
static Std_ReturnType Rm_ValidatePtrInit(Rm_ConfigType const * ConfigPtr)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    #if (RM_DEV_ERROR_DETECT == STD_ON)
        #if (RM_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == ConfigPtr)
        {
            valid = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_INIT_ID_U8, (uint8)RM_E_INIT_FAILED_U8);
        }
        else
        {
            /** do nothing */
        }
        #elif (RM_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != ConfigPtr)
        {
            valid = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_INIT_ID_U8, (uint8)RM_E_INIT_FAILED_U8);
        }
        else
        {
            /** do nothing */
        }
        #endif /*(RM_PRECOMPILE_SUPPORT == STD_OFF)*/
    #endif /*(RM_DEV_ERROR_DETECT == STD_ON)*/

    return valid;
}

#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

#ifdef RM_ENABLE_SEMA42
#if (STD_ON == RM_ENABLE_SEMA42)
#if (RM_DEV_ERROR_DETECT == STD_ON)
/**
* @brief          Validate the call of a semaphore API regarding the channelNumber parameter
* @details        Before execution, this function is called to check that the channel used exists on the hardware

* @param[in]      ChannelId       Id of the channel the caller tries to update
* @param[in]      ServiceId       Id of the service calling this function
*
* @return         Std_ReturnType  Call is valid or not
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
* @api
*
* @note
* @implements     Rm_ValidateSemaphoreChannelCall_Activity
*/
static Std_ReturnType Rm_ValidateSemaphoreChannelCall(Rm_Sema42_ChannelType ChannelNumber,
                                                      uint8 u8ServiceId)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType retVal = E_NOT_OK;
    /* Check that the channel is in valid range */
    if (ChannelNumber >= RM_SEMAPHORE_CHANNEL_COUNT)
    {
        (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)u8ServiceId, RM_E_INVALID_SEMA4_CHANNEL_U8);
    }
    else
    {
        /* Driver is initialized and channel is valid */
        retVal = (Std_ReturnType)E_OK;
    }

    return retVal;
}
#endif /* if (RM_DEV_ERROR_DETECT == STD_ON) */
#endif /* if (STD_ON == RM_ENABLE_SEMA42) */
#endif /* ifdef RM_ENABLE_SEMA42 */

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief Init function for Group 1 Ip: Mscm, Dmamux and Canhub
 * 
 * @param ConfigPtr Pointer to a selected configuration structure.
 * @return void
 */
static void Rm_InitGroup1(Rm_ConfigType const *ConfigPtr)
{
#if (RM_ENABLE_DMA_MUX == STD_ON)
    Rm_Ipw_Dma_Mux_Init(ConfigPtr->Rm_pIpwConfig);
#endif
#if (RM_ENABLE_MSCM == STD_ON)
    Rm_Ipw_Mscm_Init(ConfigPtr->Rm_pIpwConfig);
#endif
#if (RM_ENABLE_PFLASH == STD_ON)
    Rm_Ipw_Pflash_Init(ConfigPtr->Rm_pIpwConfig);
#endif
    (void)ConfigPtr;
}
#endif /* STD_ON == RM_ENABLE_GLOBAL_INIT */

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief Init function for Group 2 Ip: Axbs and Xbic
 * 
 * @param ConfigPtr Pointer to a selected configuration structure.
 * @return void
 */
static void Rm_InitGroup2(Rm_ConfigType const *ConfigPtr)
{
#if (RM_ENABLE_AXBS == STD_ON)
    Rm_Ipw_Axbs_Init(ConfigPtr->Rm_pIpwConfig);
#endif
#if (RM_ENABLE_XBIC == STD_ON)
    Rm_Ipw_Xbic_Init(ConfigPtr->Rm_pIpwConfig);
#endif
    (void)ConfigPtr;
}
#endif /* STD_ON == RM_ENABLE_GLOBAL_INIT */

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief Init function for Group 3 Ip: Xrdc, Sema42 and Virtual Wrapper
 * 
 * @param ConfigPtr Pointer to a selected configuration structure.
 * @return void
 */
static void Rm_InitGroup3(Rm_ConfigType const *ConfigPtr)
{
#if (RM_ENABLE_SEMA42 == STD_ON)
    Rm_Ipw_Sema4_Init(ConfigPtr->Rm_pIpwConfig);
#endif
#if (RM_ENABLE_VIRT_WRAPPER == STD_ON)
    Rm_Ipw_Virt_Wrapper_Init(ConfigPtr->Rm_pIpwConfig);
#endif
#if (RM_ENABLE_XRDC == STD_ON)
    Rm_Ipw_Xrdc_Init(ConfigPtr->Rm_pIpwConfig);
#endif
    (void)ConfigPtr;
}
#endif /* STD_ON == RM_ENABLE_GLOBAL_INIT */

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"
/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

#if (STD_ON == RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          This function initializes the RM hardware components.
 * @details        This service is a non reentrant function used for driver initialization.
 *        The  Initialization function  shall initialize  all relevant  registers of  the configured
 *        hardware with the  values of the  structure referenced by  the parameter ConfigPtr.
 *        If  the  hardware  allows  for   only  one  usage   of  the  register,   the  driver module
 *        implementing that functionality is responsible for initializing the register.
 *        The initialization function of this module shall always have a pointer as a parameter, even
 *        though for Variant PC no configuration set shall be given.
 *        Instead a NULL pointer shall be passed to the initialization function.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return             void
 * @api
 *
 *
 */
/* @implements         Rm_Init_Activity */
void Rm_Init(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_GLOBAL_INIT);
    Rm_abInitializedModules[RM_GLOBAL_INIT] = TRUE;
    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

#if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
#else
            Rm_pConfig = ConfigPtr;
#endif

            /* Initialize Group1 IP */
            Rm_InitGroup1(Rm_pConfig);

            /* Initialize Group2 IP */
            Rm_InitGroup2(Rm_pConfig);

            /* Initialize Group3 IP */
            Rm_InitGroup3(Rm_pConfig);
#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON == RM_ENABLE_GLOBAL_INIT)*/


#if (RM_ENABLE_XRDC == STD_ON)

/**
* @brief        Write process ID for specific master core
* @details
*
* @param[in]    Rm_XrdcMasterCoreType MasterCore                      - master core instance
* @param[in]    uint8 u8PID                             - processor ID
* @param[in]    Rm_XrdcSecureAttributeType SecureAttr   - XRDC_SECURE
*                                                       - XRDC_NON_SECURE
*
* @param[out]   none
*
* @return       none
*
* @api
*
*/
/* @implements         Rm_XrdcSetProcessID_Activity */
void Rm_XrdcSetProcessID(Rm_XrdcMasterCoreType MasterCore,
                         uint8 u8PID,
                         Rm_XrdcSecureAttributeType SecureAttr)
{
    Rm_Ipw_Xrdc_SetProcessID(MasterCore, u8PID, SecureAttr);
}

/**
 * @brief          Retrieve domain ID error list
 * @details
 *
 * @param[in]       uint32 u32Instance                                      - XRDC instance
 * @param[in]       Rm_XrdcDomainIDErrStatusType * pXrdcDomainIDErrorStatus - uint32 DomainIDAccessError
 *                                                                          - Xrdc_Ip_ErrorStatusType ErrorStatus[20]
 * @param[out]      none
 *
 * @return          none
 *
 * @api
 */
/* @implements         Rm_XrdcGetDomainIDErrorStatus_Activity */
void Rm_XrdcGetDomainIDErrorStatus(uint32 u32Instance,
                                   Rm_XrdcDomainIDErrStatusType * pXrdcDomainIDErrorStatus)
{
    Rm_Ipw_Xrdc_GetDomainIDErrorStatus(u32Instance, pXrdcDomainIDErrorStatus);
}

/**
* @brief        Retrieves current domain ID
* @details
*
* @param[in]    uint32 u32Instance - XRDC instance
*
* @param[out]   none
*
* @return       Rm_DomainIdType  - Current Domain ID or RM_XRDC_UNKNOWN_DOMAIN (0xFF) if the Domain ID is not in supported range.
*
* @api
*
*/
/* @implements         Rm_XrdcGetDomainID_Activity */
Rm_DomainIdType Rm_XrdcGetDomainID(uint32 u32Instance)
{
    Rm_DomainIdType u32DomainId;

    u32DomainId = Rm_Ipw_Xrdc_GetDomainID(u32Instance);
#if (RM_DEV_ERROR_DETECT == STD_ON)
    if (u32DomainId == (Rm_DomainIdType)RM_XRDC_UNKNOWN_DOMAIN)
    {
        (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_XRDC_GET_DOMAIN_ID_U8, (uint8)RM_E_XRDC_UNKNOWN_DOMAINID_U8);
    }
#endif

    return u32DomainId;
}

/**
 * @brief          Initialize XRDC instance
 * @details
 *
 * @param[in]       uint32 pXrdcInstanceConfig                                      - XRDC instance configuration
 * @param[out]      none
 *
 * @return          none
 *
 * @api
 */
/* @implements         Rm_XrdcInstanceInit_Activity  */
void Rm_XrdcInstanceInit(Rm_XrdcInstanceConfigType const *pXrdcInstanceConfig)
{
    Rm_Ipw_Xrdc_InstanceInit(pXrdcInstanceConfig);
}

#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize XRDC module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_XrdcInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_XRDC_INIT);
    Rm_abInitializedModules[RM_XRDC_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Xrdc_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif /*(RM_ENABLE_XRDC == STD_ON)*/

#if (STD_ON == RM_ENABLE_SEMA42)
/**
* @brief        Rm_SemaphoreGetStatus
* @details      This function returns the status of the selected Semaphore.
*               The return is either the number of the domain ID that keeps it locked,
*               or RM_SEMAPHORE_FREE (0xFF) if the Semaphore is free, or RM_SEMAPHORE_UNKNOWN_DOMAINID if domain ID is unknown.
*
* @param[in]    ChannelNumber          Semaphore channel
*
* @return       Rm_DomainIdType        Index of the semaphore owner if the semaphore is locked,
*                                      or RM_SEMAPHORE_FREE (0xFF) if the gate is not locked,
*                                      or RM_SEMAPHORE_UNKNOWN_DOMAINID (0xF0) if unknown domain ID that owns Sema42.
*
*/
/* @implements     Rm_SemaphoreGetStatus_Activity */
Rm_DomainIdType Rm_SemaphoreGetStatus(Rm_Sema42_ChannelType ChannelNumber)
{
    Rm_DomainIdType retVal = 0U;

#if (RM_DEV_ERROR_DETECT == STD_ON)
    /* validate that API is called after RM was initialized */
    if ((Std_ReturnType)E_OK == Rm_ValidateSemaphoreChannelCall(ChannelNumber, RM_GET_GATE_ID_U8))
    {
#endif
        retVal = Rm_Ipw_Sema4_GetGateLocker(ChannelNumber);
#if (RM_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return retVal;
}
/**
* @brief        Rm_SemaphoreLockGate
* @details      This function locks a Semaphore from a given core, in order to guard
*               a critical section
*
* @param[in]    ChannelNumber   Semaphore channel
*
* @return       Std_ReturnType
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*/
/* @implements         Rm_SemaphoreLockGate_Activity */
Std_ReturnType Rm_SemaphoreLockGate(Rm_Sema42_ChannelType ChannelNumber)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;
    uint8 u8GateLocker;
    uint32 u32DomainId;

#if (RM_DEV_ERROR_DETECT == STD_ON)
    /* validate that API is called after RM was initialized */
    if ((Std_ReturnType)E_OK == Rm_ValidateSemaphoreChannelCall(ChannelNumber, RM_LOCK_ID_U8))
    {
#endif
        u8GateLocker = Rm_Ipw_Sema4_GetGateLocker(ChannelNumber);
        u32DomainId = Rm_Ipw_SemaphoreGetDomainID(ChannelNumber);
        if (u32DomainId == (uint32) RM_XRDC_UNKNOWN_DOMAIN)
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (u8GateLocker == RM_SEMAPHORE_FREE)
        {
            retVal = Rm_Ipw_Sema4_LockGate(ChannelNumber, (uint8)u32DomainId);
        }
        else if (u8GateLocker == (uint8) RM_SEMAPHORE_UNKNOWN_DOMAINID)
        {
#if (RM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_LOCK_ID_U8, (uint8)RM_E_SEMAPHORE_UNKNOWN_DOMAINID_U8);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else if ((uint32)u8GateLocker == u32DomainId)
        {
#if (RM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_LOCK_ID_U8, (uint8)RM_E_ALREADY_LOCKED_U8);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#if (RM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_LOCK_ID_U8, (uint8)RM_E_LOCKED_BY_OTHER_CORE_U8);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
        }
#if (RM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
#endif
    return retVal;
}

/**
* @brief        Rm_SemaphoreUnlockGate
* @details      This function unlocks a Semaphore from a given core, in order to mark the end of
*               a critical section
*
* @param[in]    ChannelNumber   Semaphore channel
*
* @return       Std_ReturnType
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
*/
/* @implements         Rm_SemaphoreUnlockGate_Activity */
Std_ReturnType Rm_SemaphoreUnlockGate(Rm_Sema42_ChannelType ChannelNumber)
{
    Std_ReturnType retVal;
    uint32 u32DomainId;
    uint8 u8GateLocker;

#if (RM_DEV_ERROR_DETECT == STD_ON)
    /* validate that API is called after RM was initialized */
    if ((Std_ReturnType)E_OK == Rm_ValidateSemaphoreChannelCall(ChannelNumber, RM_UNLOCK_ID_U8))
    {
#endif
        u8GateLocker = Rm_Ipw_Sema4_GetGateLocker(ChannelNumber);
        u32DomainId = Rm_Ipw_SemaphoreGetDomainID(ChannelNumber);
        if (u32DomainId == (uint32) RM_XRDC_UNKNOWN_DOMAIN)
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (u8GateLocker == (uint8) RM_SEMAPHORE_FREE)
        {
#if (RM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_UNLOCK_ID_U8, (uint8)RM_E_ALREADY_UNLOCKED_U8);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (u8GateLocker == (uint8) RM_SEMAPHORE_UNKNOWN_DOMAINID)
        {
#if (RM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_UNLOCK_ID_U8, (uint8)RM_E_SEMAPHORE_UNKNOWN_DOMAINID_U8);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else if ((uint32) u8GateLocker != u32DomainId)
        {
#if (RM_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, (uint8)RM_UNLOCK_ID_U8, (uint8)RM_E_LOCKED_BY_OTHER_CORE_U8);
#endif
            retVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            retVal = Rm_Ipw_Sema4_UnlockGate(ChannelNumber);
        }
#if (RM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
#endif
    return retVal;
}

/**
* @brief        Rm_SemaphoreResetGate
* @details      This function Resets the status of all Semaphores configured by the RM driver
*               The API is not part of the standard semaphore usage, it should only
*               be used in case of faults in the hardware or a deadlock.
*
* @param[in]    ChannelNumber   Semaphore channel
*
*/
/* @implements         Rm_SemaphoreResetGate_Activity */
void Rm_SemaphoreResetGate(Rm_Sema42_ChannelType ChannelNumber)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    /* validate that API is called after RM was initialized */
    if ((Std_ReturnType)E_OK == Rm_ValidateSemaphoreChannelCall(ChannelNumber, RM_RESET_GATE_ID_U8))
    {
#endif
        Rm_Ipw_Sema4_ResetGate(ChannelNumber);

#if (RM_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
* @brief        Rm_SemaphoreResetAllGates
* @details      This function Resets the status of all Semaphores configured by the RM driver.
*               The API is not part of the standard semaphore usage, it should only
*               be used in case of faults in the hardware or a deadlock.
*
* @param[in]    NA
*
*/
/* @implements         Rm_SemaphoreResetAllGates_Activity */
void Rm_SemaphoreResetAllGates(void)

{
    Rm_Ipw_Sema4_ResetAllGates();
}

/**
* @brief        Rm_SemaphoreGetResetGateDomainId
* @details      This function get the Domain which initiated the most recent write operation on the reset register on the instance of the semaphore channel.
*
* @param[in]    ChannelNumber   Semaphore channel
*
*/
/* @implements         Rm_SemaphoreGetResetGateDomainId_Activity */
Rm_DomainIdType Rm_SemaphoreGetResetGateDomainId(Rm_Sema42_ChannelType ChannelNumber)
{
    return Rm_Ipw_Sema4_GetResetGateDomainId(ChannelNumber);
}

/**
* @brief        Rm_SemaphoreIsResetGateStateIdle
* @details      This function check if the current state of the reset gate state machine is idle on the instance of the semaphore channel.
*
* @param[in]    ChannelNumber   Semaphore channel
* @return       boolean
* @retval       TRUE        if the reset gate is idle
* @retval       FALSE       if the reset gate is waiting for the second write or if it is actively resseting a gate
*
*/
/* @implements         Rm_SemaphoreIsResetGateStateIdle_Activity */
boolean Rm_SemaphoreIsResetGateStateIdle(Rm_Sema42_ChannelType ChannelNumber)
{
    return Rm_Ipw_Sema4_IsResetGateStateIdle(ChannelNumber);
}

/**
* @brief        Rm_SemaphoreGetResetedGate
* @details      This function get the logical channel which targetted by the most recent reset attempt on the instance of a semaphore channel.
*
* @param[in]    ChannelNumber   Semaphore channel
* @return       Rm_Sema42_ChannelType
* @retval       Logical semaphore channel.
*
*/
/* @implements         Rm_SemaphoreGetResetedGate_Activity */
Rm_Sema42_ChannelType Rm_SemaphoreGetResetedGate(Rm_Sema42_ChannelType ChannelNumber)
{
    return Rm_Ipw_Sema4_GetResetedGate(ChannelNumber);
}

#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize Semaphore module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_Sema42Init(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_SEMA42_INIT);
    Rm_abInitializedModules[RM_SEMA42_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Sema4_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif /* #if (STD_ON == RM_ENABLE_SEMA42)  */

#if (RM_ENABLE_AXBS == STD_ON)
void Rm_AxbsDeInit(void)
{
    /* Check for uninitialized RM */
    if (NULL_PTR != Rm_pConfig)
    {
        Rm_Ipw_Axbs_DeInit(Rm_pConfig->Rm_pIpwConfig);
    }
}

#endif /* #if (STD_ON == RM_ENABLE_AXBS)  */

#if (RM_ENABLE_XBIC == STD_ON)
/*================================================================================================*/
/**
 * @brief         Enable/Disable feedback integrity checking for a specific master port.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     u32XbicInstance        : Xbic instance number
 * @param[in]     u8MasterPort           : Master port number
 * @param[in]     bFeedbackCheckEnable   : Specifies wheter the feedback integrity checking for the master port is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Rm_XbicEnableMasterFeedbackCheck_Activity */
void Rm_XbicEnableMasterFeedbackCheck(uint32 u32XbicInstance,
                                      uint8 u8MasterPort,
                                      boolean bFeedbackCheckEnable)
{
    Rm_Ipw_Xbic_EnableMasterFeedbackCheck(u32XbicInstance, u8MasterPort, bFeedbackCheckEnable);
}

/**
 * @brief         Enable/Disable attribute integrity checking for a specific slave port.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     u32XbicInstance       : Xbic instance number
 * @param[in]     u8SlavePort           : Slave port number
 * @param[in]     bEDCCheckEnable       : Specifies wheter the attribute integrity checking for the slave port is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Rm_XbicEnableSlaveEDCCheck_Activity */
void Rm_XbicEnableSlaveEDCCheck(uint32 u32XbicInstance,
                                uint8 u8SlavePort,
                                boolean bEDCCheckEnable)
{
    Rm_Ipw_Xbic_EnableSlaveEDCCheck(u32XbicInstance, u8SlavePort, bEDCCheckEnable);
}

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
/* @implements         Rm_XbicFeedbackCheckAndEDCCheckDisable_Activity */
void Rm_XbicFeedbackCheckAndEDCCheckDisable(void)
{
    Rm_Ipw_Xbic_FeedbackCheckAndEDCCheckDisable();
}

/**
 * @brief         Get error status of a Xbic instance.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     xbicInstance         : Xbic instance number
 * @param[in]     pErrorStatus           : Pointer points to the memory area containing the XBIC reports error information
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Rm_XbicGetErrorStatus_Activity */
void Rm_XbicGetErrorStatus(uint32 u32XbicInstance,
                           Rm_Xbic_ErrorStatusType *pErrorStatus)
{
    Rm_Ipw_Xbic_GetErrorStatus(u32XbicInstance,pErrorStatus);
}

/**
 * @brief         Inject an error into a master, a slave of a Xbic instance with a specific error code.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     u32XbicInstance       : Xbic instance number
 * @param[in]     u8SlaveTarget        : Slave port number injected error
 * @param[in]     u8MasterTarget       : Master tagget ID number injected error
 * @param[in]     u8SynDecode          : Error Syndrome injected
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Rm_XbicErrorInjection_Activity */
void Rm_XbicErrorInjection(uint32 u32XbicInstance,
                           uint8 u8SlaveTarget,
                           uint8 u8MasterTarget,
                           uint8 u8SynDecode)
{
    Rm_Ipw_Xbic_ErrorInjection(u32XbicInstance, u8SlaveTarget, u8MasterTarget, u8SynDecode);
}

/**
 * @brief         Get error status of a Xbic instance.
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
/* @implements         Rm_XbicErrorInjectionDisable_Activity */
void Rm_XbicErrorInjectionDisable(uint32 u32XbicInstance)
{
    Rm_Ipw_Xbic_ErrorInjectionDisable(u32XbicInstance);
}

#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize Xbic module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_XbicInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_XBIC_INIT);
    Rm_abInitializedModules[RM_XBIC_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Xbic_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif/*#if (RM_ENABLE_XBIC == STD_ON)*/


#if (RM_ENABLE_MSCM == STD_ON)
#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize Mscm module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_MscmInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_MSCM_INIT);
    Rm_abInitializedModules[RM_MSCM_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Mscm_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif/*#if (RM_ENABLE_MSCM == STD_ON)*/

#if (RM_ENABLE_PFLASH == STD_ON)
/**
 * @brief         Get error status of a Xbic instance.
 *
 * @details       This function is Reentrant.
 *
 * @param[in]     eMaster         : Pflash Master Number
 * @param[in]     eAccess         : Pflash Master Access Right
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Rm_PflashSetAccessProtection */
void Rm_PflashSetAccessProtection(Rm_Pflash_MasterType eMaster,
                                  Rm_Pflash_MasterAccessType eAccess)
{
    Rm_Ipw_Pflash_SetAccessProtection(eMaster, eAccess);
}

#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize Pflash module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_PflashInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_PFLASH_INIT);
    Rm_abInitializedModules[RM_PFLASH_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Pflash_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif /*#if (RM_ENABLE_PFLASH == STD_ON)*/

#if (RM_ENABLE_AXBS == STD_ON)

#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize Axbs module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_AxbsInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_AXBS_INIT);
    Rm_abInitializedModules[RM_AXBS_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Axbs_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif /*#if (RM_ENABLE_AXBS == STD_ON)*/

#if (RM_ENABLE_VIRT_WRAPPER == STD_ON)
#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize Virtual Wrapper module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_VirtualWrapperInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_VIRT_WRAPPER_INIT);
    Rm_abInitializedModules[RM_VIRT_WRAPPER_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Virt_Wrapper_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif /*#if (RM_ENABLE_VIRT_WRAPPER == STD_ON)*/


#if (RM_ENABLE_DMA_MUX == STD_ON)
#if (STD_ON != RM_ENABLE_GLOBAL_INIT)
/**
 * @brief          Initialize DmaMux module
 * @details
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 * @param[out]      none
 *
 * @return          void
 *
 * @api
 */
void Rm_DmaMuxInit(Rm_ConfigType const *ConfigPtr)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType valid;

    valid = Rm_ValidateGlobalCall(RM_INIT_ID_U8, RM_DMA_MUX_INIT);
    Rm_abInitializedModules[RM_DMA_MUX_INIT] = TRUE;

    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Rm_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/

    if (NULL_PTR == Rm_pConfig)
    {
        #if (RM_PRECOMPILE_SUPPORT == STD_ON)
            Rm_pConfig = &Rm_Config;
            (void)ConfigPtr;
        #else
            Rm_pConfig = ConfigPtr;
        #endif
    }

    Rm_Ipw_Dma_Mux_Init(Rm_pConfig->Rm_pIpwConfig);

#if (RM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*#if (RM_DEV_ERROR_DETECT == STD_ON)*/
}
#endif/*#if (STD_ON != RM_ENABLE_GLOBAL_INIT) */
#endif /*#if (RM_ENABLE_DMA_MUX == STD_ON)*/

#if (RM_GET_VERSION_INFO_API == STD_ON)
/**
 * @brief   This service returns the version information of this module.
 * @details This  service is Non reentrant and returns the version information of this module.
 *          The version information includes:
 *          - Module Id
 *          - Vendor Id
 *          - Vendor specific version numbers
 *          If source code for caller and callee of this function is available this function should
 *          be realized as a macro. The macro should be defined in the modules header file.
 *
 * @param[out]    versioninfo      Pointer to location to store version info
 *
 * @return void
 *
 * @api
 *
 * */
/* @implements         Rm_GetVersionInfo_Activity */
void Rm_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (RM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)RM_MODULE_ID, 0U, RM_GETVERSIONINFO_ID, RM_E_PARAM_POINTER);
    }
    else
#endif /* (RM_DEV_ERROR_DETECT == STD_ON) */
    {
        (versioninfo)->vendorID         = (uint16)RM_VENDOR_ID;
        (versioninfo)->moduleID         = (uint8)RM_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)RM_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)RM_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)RM_SW_PATCH_VERSION;
    }
}

#endif  /* RM_GET_VERSION_INFO_API == STD_ON */

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
