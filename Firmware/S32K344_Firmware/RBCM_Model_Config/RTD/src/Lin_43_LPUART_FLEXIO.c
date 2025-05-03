/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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
*   @file   Lin.c
*   @implements Lin.c_Artifact
*
*   @addtogroup LIN
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Lin_43_LPUART_FLEXIO.h"
#include "LinIf.h"

#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_VENDOR_ID_C                      43
#define LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION_C       7
#define LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION_C    0
#define LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION_C               5
#define LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION_C               0
#define LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin_43_LPUART_FLEXIO header file are of the same Autosar version */
#if (LIN_43_LPUART_FLEXIO_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO.c and Lin_43_LPUART_FLEXIO.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.c and Lin_43_LPUART_FLEXIO.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO.c and Lin_43_LPUART_FLEXIO.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if the source file and Dem header file are of the same version */
        #if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.c and Dem.h are different"
        #endif
    #endif

    #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.c and Det.h are different"
        #endif
    #endif

    /* Check if current file and LinIf header file are of the same Autosar version */
    #if ((LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != LINIF_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != LINIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO.c and LinIf.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"


#if (LIN_43_LPUART_FLEXIO_PRECOMPILE_SUPPORT == STD_ON)
extern const Lin_43_LPUART_FLEXIO_ConfigType * const Lin_43_LPUART_FLEXIO_apxPBCfgVariantPredefined[LIN_43_LPUART_FLEXIO_MAX_PARTITIONS];
#endif

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
const Lin_43_LPUART_FLEXIO_ConfigType * Lin_43_LPUART_FLEXIO_apxConfigPtr[LIN_43_LPUART_FLEXIO_MAX_PARTITIONS];

/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
const Lin_43_LPUART_FLEXIO_ChannelConfigType *Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"


#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief          LIN driver status variable.
* @details        LIN driver state machine.
*/
uint8 Lin_43_LPUART_FLEXIO_au8LinDrvStatus[LIN_43_LPUART_FLEXIO_MAX_PARTITIONS] = LIN_43_LPUART_FLEXIO_UNINIT_ARRAY;

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#define LIN_43_LPUART_FLEXIO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @brief          LIN channel state variable.
* @details        LIN channel state machine.
*/
uint8 Lin_43_LPUART_FLEXIO_au8LinChStatus[LIN_43_LPUART_FLEXIO_HW_MAX_MODULES];

#define LIN_43_LPUART_FLEXIO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
* @note put all LIN code into defined section
*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Lin_43_LPUART_FLEXIO_InitImplementation(void);

static Std_ReturnType Lin_43_LPUART_FLEXIO_CommonCheckingChannel(const uint8 Channel, const uint8 FunctionalId);

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
static Std_ReturnType Lin_43_LPUART_FLEXIO_ChkParamFuncSendFrame(const uint8 Channel, const Lin_PduType * const PduInfoPtr);
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @internal
* @brief   Initializes all LIN channels configured.
* @details This function performs software initialization for Lin channles configured
*          - Sets all the available channels to sleep mode and configures
*            their state machine to LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE.
*
* @param   void
*
* @return  void
*/
static void  Lin_43_LPUART_FLEXIO_InitImplementation(void)
{
    uint8 Lin_ChLoop;
    uint32 PartitionID = Lin_43_LPUART_FLEXIO_GetUserID();

    for (Lin_ChLoop = (uint8)0U; Lin_ChLoop < LIN_43_LPUART_FLEXIO_HW_MAX_MODULES; Lin_ChLoop++)
    {
        if ((TRUE == Lin_43_LPUART_FLEXIO_apxConfigPtr[PartitionID]->Lin_43_LPUART_FLEXIO_ChannelPtr[Lin_ChLoop]->AllocatedPartition) &&
            (PartitionID == Lin_43_LPUART_FLEXIO_apxConfigPtr[PartitionID]->Lin_43_LPUART_FLEXIO_ChannelPtr[Lin_ChLoop]->ChannelPartitionID)
           )
        {
            Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Lin_ChLoop] = (Lin_43_LPUART_FLEXIO_apxConfigPtr[PartitionID]->Lin_43_LPUART_FLEXIO_ChannelPtr)[Lin_ChLoop];
            Lin_43_LPUART_FLEXIO_Ipw_InitChannel(Lin_ChLoop, Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Lin_ChLoop]->ChannelConfigPtr);
            /* Set LIN channel state machine to LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE */
            Lin_43_LPUART_FLEXIO_au8LinChStatus[Lin_ChLoop] = LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE;
        }
    }
}

/**
* @internal
* @brief   Check invalid of channel.
* @details This function performs development error detection of the Lin channel and provide the error:
*          - The Lin module has yet initialized.
*          - Input channel index is out of range.
*          - Incorrect in configuration.
*
* @param[in] Channel - the Lin channel index.
* @param[in] FunctionalId - the functional index would be provided if any errors appeared.
*
* @return  Std_ReturnType
* @retval  E_NOT_OK   In case of at least a error occurred.
* @retval  E_OK       No error occurred.
*
**/
static Std_ReturnType Lin_43_LPUART_FLEXIO_CommonCheckingChannel(const uint8 Channel, const uint8 FunctionalId)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint32 PartitionID = Lin_43_LPUART_FLEXIO_GetUserID();

    /* Check whether the LIN driver is in LIN_43_LPUART_FLEXIO_INIT state */
    if (LIN_43_LPUART_FLEXIO_INIT != Lin_43_LPUART_FLEXIO_au8LinDrvStatus[PartitionID])
    {
        /* LIN driver has not been initialized yet */
    #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                              LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                              FunctionalId, \
                              (uint8)LIN_43_LPUART_FLEXIO_E_UNINIT \
                             );
    #else
        /* Casting to avoid misra and compiler warning */
        (void)FunctionalId;
    #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /* Check for invalid channel */
        if (LIN_43_LPUART_FLEXIO_HW_MAX_MODULES <= Channel)
        {
            /* Invalid channel */
        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  FunctionalId, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_INVALID_CHANNEL \
                                 );
        #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        }
        else if ((FALSE == Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->AllocatedPartition) ||
                 (PartitionID != Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelPartitionID)
                )
        {
            /* Invalid requested resource */
        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  FunctionalId, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_PARAM_CONFIG \
                                 );
        #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            /* Channel is valid after general check */
            TempReturn = (uint8)E_OK;
        }
    }

    return TempReturn;
}

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
/**
* @internal
* @brief   Check input parameters of the SendFrame function.
* @details This function performs development error detection of input parameters of the SendFrame function and provide the error:
*          - Invalid the parameter Channel.
*          - Invalid the parameter PduInfoPtr.
*
* @param[in] Channel - the Lin channel index.
* @param[in] PduInfoPtr - pointer to PDU containing the PID,
*                         Checksum model, Response type, Dl and SDU
*                         data pointer.
*
* @return  Std_ReturnType
* @retval  E_NOT_OK   In case of at least a error occurred.
* @retval  E_OK       No error occurred.
*
**/
static Std_ReturnType Lin_43_LPUART_FLEXIO_ChkParamFuncSendFrame(const uint8 Channel, const Lin_PduType * const PduInfoPtr)
{
    Std_ReturnType TempReturn;

    TempReturn = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_SENDFRAME_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check PduInfoPtr for not being a null pointer */
        if (NULL_PTR == PduInfoPtr)
        {
            /* Invalid pointer */
        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_SENDFRAME_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_PARAM_POINTER \
                                 );
        #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check whether the LIN channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE state */
            if (LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE == Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel])
            {
                /* LIN channel is in sleep mode */
            #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                      LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                      (uint8)LIN_43_LPUART_FLEXIO_SENDFRAME_ID, \
                                      (uint8)LIN_43_LPUART_FLEXIO_E_STATE_TRANSITION \
                                     );
            #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                TempReturn = (uint8)E_NOT_OK;
            }
        }
    }

    return TempReturn;
}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Initializes the LIN module.
* @details This function performs software initialization of LIN
*          driver:
*          - Clears the shadow buffer of all available Lin channels
*          - Sets all the available channels to sleep mode and configures
*            their state machine to LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE.
*          - Set driver state machine to LIN_43_LPUART_FLEXIO_INIT.
*
* @param[in] Config - Pointer to LIN driver configuration set.
*
* @return  void
*
* @implements Lin_Init_Activity
**/
void Lin_43_LPUART_FLEXIO_Init(const Lin_43_LPUART_FLEXIO_ConfigType * Config)
{
    uint32 PartitionID = Lin_43_LPUART_FLEXIO_GetUserID();

#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the LIN driver is in LIN_43_LPUART_FLEXIO_UNINIT state */
    if (LIN_43_LPUART_FLEXIO_UNINIT != Lin_43_LPUART_FLEXIO_au8LinDrvStatus[PartitionID])
    {

       /* LIN driver has been already initialized */
       (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                             LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                             (uint8)LIN_43_LPUART_FLEXIO_INIT_ID, \
                             (uint8)LIN_43_LPUART_FLEXIO_E_STATE_TRANSITION \
                            );
    }
    else
    {
#endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */

    #if (LIN_43_LPUART_FLEXIO_PRECOMPILE_SUPPORT != STD_ON)
        /* Check Config for not being a null pointer */
        if (NULL_PTR == Config)
        {
            #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_INIT_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_INIT_FAILED \
                                 );
            #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        }
        else if (Config->PartitionId != PartitionID)
        {
            #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Invalid requested resource */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_INIT_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_PARAM_CONFIG \
                                 );
            #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            Lin_43_LPUART_FLEXIO_apxConfigPtr[PartitionID] = Config;
    #else /* LIN_43_LPUART_FLEXIO_PRECOMPILE_SUPPORT == STD_ON */
        if (NULL_PTR != Config)
        {
            #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                    LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                    (uint8)LIN_43_LPUART_FLEXIO_INIT_ID, \
                                    (uint8)LIN_43_LPUART_FLEXIO_E_INIT_FAILED \
                                 );
            #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        }
        else if ((NULL_PTR == Lin_43_LPUART_FLEXIO_apxPBCfgVariantPredefined[PartitionID]) || (Lin_43_LPUART_FLEXIO_apxPBCfgVariantPredefined[PartitionID]->PartitionId != PartitionID))
        {
            #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Invalid requested resource */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_INIT_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_PARAM_CONFIG \
                                 );
            #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            Lin_43_LPUART_FLEXIO_apxConfigPtr[PartitionID] = Lin_43_LPUART_FLEXIO_apxPBCfgVariantPredefined[PartitionID];
    #endif /* LIN_43_LPUART_FLEXIO_PRECOMPILE_SUPPORT */

            Lin_43_LPUART_FLEXIO_InitImplementation();

            /* Update LIN driver status to LIN_43_LPUART_FLEXIO_INIT */
            Lin_43_LPUART_FLEXIO_au8LinDrvStatus[PartitionID] = LIN_43_LPUART_FLEXIO_INIT;
        }

#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */

}
/**
* @brief   Validates for upper layers the wake up of LIN channel.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up signal.
*
* @param[in] uint8 - channel index.
*
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          the addressed LIN Channel is not
*                          in sleep state.
* @retval E_OK             Otherwise.
*
* @implements Lin_CheckWakeup_Activity
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_CheckWakeup(uint8 Channel)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_CHECKWAKEUP_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        TempReturn = (uint8)E_OK;

        /* Check if the addressed LIN channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE or LIN_43_LPUART_FLEXIO_CH_SLEEP_PENDING state*/
        if ((LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE == Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel]) || (LIN_43_LPUART_FLEXIO_CH_SLEEP_PENDING == Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel]))
        {
            /* Lin channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE state */
            /* Check if Lin channel has detected a wake-up */
            if ((uint8)E_OK == Lin_43_LPUART_FLEXIO_Ipw_CheckWakeup(Channel))
            {
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)
                if (TRUE == Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->LinChannelWakeupSupport)
                {
                    /* Indicates a valid timer wakeup event to ECU State Manager */
                    EcuM_SetWakeupEvent(Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->LinChannelEcuMWakeupSource);
                    /* report the wakeup source after the successful wakeup to LinInterface */
                    LinIf_WakeupConfirmation(Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->LinChannelEcuMWakeupSource);
                }
#endif
            }
        }
        else
        {
            /* In the case of ASR4.3, nothing need to do */
        }
    }

    return TempReturn;
}

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
/**
* @brief   Gets the status of the LIN driver when Channel is operating.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in]   Channel LIN channel to be addressed
* @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LIN Hardware receive buffer where the current SDU is
*              stored
* @return                  Lin_StatusType.
* @retval  LIN_NOT_OK       Development or production error rised
*                          none of the below conditions.
* @retval  LIN_TX_OK        Successful transmission.
* @retval  LIN_TX_BUSY      Ongoing transmission of header or response.
* @retval  LIN_TX_HEADER_ERROR Error occurred during header
*                          transmission.
* @retval  LIN_TX_ERROR     Error occurred during response
*                          transmission.
* @retval  LIN_RX_OK        Reception of correct response.
* @retval  LIN_RX_BUSY      Ongoing reception where at least one byte
*                          has been received.
* @retval  LIN_RX_ERROR     Error occurred during reception.
* @retval  LIN_RX_NO_REPONSE No data byte has been received yet.
* @retval  LIN_OPERATIONAL  Channel is ready for next header.
*                          transmission and no data are available.
*
* @pre: This API is available only if at least one node is configured as MASTER.
*
* @implements Lin_GetStatus_Activity
**/
Lin_StatusType Lin_43_LPUART_FLEXIO_GetStatus(uint8 Channel, const uint8 ** Lin_43_LPUART_FLEXIO_SduPtr)
{
    Std_ReturnType CheckChannel;
    Lin_StatusType TempReturn = LIN_NOT_OK;
    uint8 Lin_43_LPUART_FLEXIO_ChannelState;

    /* General channel checking */
    CheckChannel = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_GETSTATUS_ID);

    if ((uint8)E_NOT_OK == CheckChannel)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check PduInfoPtr for not being a null pointer */
        if (NULL_PTR == Lin_43_LPUART_FLEXIO_SduPtr)
        {
            /* Invalid pointer */
#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_GETSTATUS_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_PARAM_POINTER \
                                 );
#endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = LIN_NOT_OK;
        }
        else
        {
            Lin_43_LPUART_FLEXIO_ChannelState = Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel];

            /* LIN channel state */
            switch (Lin_43_LPUART_FLEXIO_ChannelState)
            {
                case LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE:
                    TempReturn = LIN_CH_SLEEP;
                    break;
                case LIN_43_LPUART_FLEXIO_CH_SLEEP_PENDING:
                    Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel] = LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE;
                    TempReturn = LIN_CH_SLEEP;
                    break;
                case LIN_43_LPUART_FLEXIO_CH_OPERATIONAL:
                    /* LIN Channel frame state */
                    /* Initialize the pointer to return with */
                    TempReturn = Lin_43_LPUART_FLEXIO_Ipw_HardwareGetStatus(Channel, Lin_43_LPUART_FLEXIO_SduPtr);
                    break;
                default :
                    TempReturn = LIN_NOT_OK;
                    break;
            }
        }
    }

    return TempReturn;
}

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return  Std_ReturnType.
* @retval  E_NOT_OK   In case of a timeout situation only.
* @retval  E_OK       Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*          This API is available only if at least one node is configured as MASTER.
*
* @implements Lin_GoToSleep_Activity
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_GoToSleep(uint8 Channel)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_GOTOSLEEP_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check whether the LIN channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE state */
        if (LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE == Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel])
        {
            /* do nothing */
        }
        else
        {
            TempReturn = Lin_43_LPUART_FLEXIO_Ipw_GoToSleep(Channel);
            /* Lin_43_LPUART_FLEXIO_Ipw_GoToSleep can return E_NOT_OK or LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR, So check TempReturn != E_OK */
            if ((uint8)E_OK != TempReturn)
            {
                if ((uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR == TempReturn)
                {
                    /* Report Production error */
                    #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.id, \
                                                 DEM_EVENT_STATUS_FAILED \
                                                );
                    }
                    else
                    {
                        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                              LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                              (uint8)LIN_43_LPUART_FLEXIO_GOTOSLEEP_ID, \
                                              (uint8)LIN_43_LPUART_FLEXIO_E_TIMEOUT \
                                             );
                        #endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                    }
                    #else
                        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                              LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                              (uint8)LIN_43_LPUART_FLEXIO_GOTOSLEEP_ID, \
                                              (uint8)LIN_43_LPUART_FLEXIO_E_TIMEOUT \
                                             );
                        #endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                    #endif  /* (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                }

                TempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Report Production error */
                #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if ((uint32)STD_ON == Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.id, \
                                             DEM_EVENT_STATUS_PASSED \
                                            );
                }
                #endif
            }
            /* Set Channel state to LIN_43_LPUART_FLEXIO_CH_SLEEP_PENDING state */
            Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel] = LIN_43_LPUART_FLEXIO_CH_SLEEP_PENDING;
        }
    }

    return TempReturn;
}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

/**
* @brief   Same function as Lin_43_LPUART_FLEXIO_Ipw_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return  Std_ReturnType.
* @retval  E_NOT_OK   In case of a timeout situation only.
* @retval  E_OK       Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*
* @implements Lin_GoToSleepInternal_Activity
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_GoToSleepInternal(uint8 Channel)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_GOTOSLEEPINTERNAL_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check whether the LIN channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE state */
        if (LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE == Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel])
        {
            /* do nothing */
        }
        else
        {
            /* Call LLD function */
            TempReturn = Lin_43_LPUART_FLEXIO_Ipw_GoToSleepInternal(Channel);
            /* Lin_43_LPUART_FLEXIO_Ipw_GoToSleepInternal can return E_NOT_OK or LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR, So check TempReturn != E_OK */
            if ((uint8)E_OK != TempReturn)
            {
                if ((uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR == TempReturn)
                {
                    /* Report Production error */
                    #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.id, \
                                                  DEM_EVENT_STATUS_FAILED \
                                                );
                    }
                    else
                    {
                    #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                              LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                              (uint8)LIN_43_LPUART_FLEXIO_GOTOSLEEPINTERNAL_ID, \
                                              (uint8)LIN_43_LPUART_FLEXIO_E_TIMEOUT \
                                             );
                    #endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                    }
                    #else
                        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                            /* Report error to development error tracer */
                            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                                  (uint8)LIN_43_LPUART_FLEXIO_GOTOSLEEPINTERNAL_ID, \
                                                  (uint8)LIN_43_LPUART_FLEXIO_E_TIMEOUT \
                                                 );
                        #endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                    #endif  /* (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                }

                TempReturn = (uint8)E_NOT_OK;
            }
            else
            {
            /* Report Production Error */
            #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF )
                if ((uint32)STD_ON == Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.id, \
                                             DEM_EVENT_STATUS_PASSED \
                                            );
                }
            #endif /* LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */

                /* Update LIN channel status to LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE */
                Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel] = LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE;
            }
        }
    }

    return TempReturn;
}

#if (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON)
/**
* @brief   Sends a LIN frame.
* @details Sends a LIN header and a LIN response, if necessary. The
*          direction of the frame response (master response, slave
*          response, slave-to-slave communication) is provided by
*          the PduInfoPtr.
*
* @param[in] Channel       LIN channel to be addressed.
* @param[in] PduInfoPtr    pointer to PDU containing the PID,
*                          Checksum model, Response type, Dl and SDU
*                          data pointer.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          PduInfoPtr is NULL or
*                          a timeout occurs or
*                          LIN Channel is in sleep state.
* @retval E_OK             Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*          This API is available only if at least one node is configured as MASTER.
*
* @implements Lin_SendFrame_Activity
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_SendFrame(uint8 Channel, const Lin_PduType * PduInfoPtr)
{
    Std_ReturnType TempReturn;

    /* Check SendFrame functional input parameters */
    TempReturn = Lin_43_LPUART_FLEXIO_ChkParamFuncSendFrame(Channel, PduInfoPtr);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Lin Master Device will send the frame first */
        TempReturn = Lin_43_LPUART_FLEXIO_Ipw_SendFrame(Channel, PduInfoPtr);
        /* Lin_43_LPUART_FLEXIO_Ipw_SendFrame can return E_NOT_OK or LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR, So check TempReturn != E_OK */
        if ((uint8)E_OK != TempReturn)
        {
            if ((uint8)LIN_43_LPUART_FLEXIO_TIMEOUT_ERROR == TempReturn)
            {
                /* Report Production error */
                #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if ((uint32)STD_ON == Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.id, \
                                              DEM_EVENT_STATUS_FAILED \
                                            );
                }
                else
                {
                    #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                          LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                          (uint8)LIN_43_LPUART_FLEXIO_SENDFRAME_ID, \
                                          (uint8)LIN_43_LPUART_FLEXIO_E_TIMEOUT \
                                         );
                    #endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                }
                #else
                    #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                          LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                          (uint8)LIN_43_LPUART_FLEXIO_SENDFRAME_ID, \
                                          (uint8)LIN_43_LPUART_FLEXIO_E_TIMEOUT \
                                         );
                    #endif  /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
                #endif  /* (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            }

            TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Report Production error */
            #if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LPUART_FLEXIO_xE_TimeoutCfg.id, \
                                          DEM_EVENT_STATUS_PASSED \
                                        );
            }
            #endif /* (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
        }
    }

    return TempReturn;

}
#endif /* (LIN_43_LPUART_FLEXIO_MASTER_NODE_USED == STD_ON) */

/**
* @brief   Generates a wake up pulse.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_43_LPUART_FLEXIO_CH_OPERATIONAL state.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*
* @implements Lin_Wakeup_Activity
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_Wakeup(uint8 Channel)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_WAKEUP_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check whether the LIN channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE state */
        if (LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE != Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel])
        {
            /* LIN channel is not in sleep mode */
        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_WAKEUP_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_STATE_TRANSITION \
                                 );
        #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Call LLD function */
            Lin_43_LPUART_FLEXIO_Ipw_WakeUp(Channel);
            /* Update LIN channel status to LIN_43_LPUART_FLEXIO_CH_OPERATIONAL */
            Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel] = LIN_43_LPUART_FLEXIO_CH_OPERATIONAL;
            TempReturn = (uint8)E_OK;
        }
    }

    return TempReturn;
}

/**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_43_LPUART_FLEXIO_CH_OPERATIONAL state without sending a
*          wake up signal to the LIN bus
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @pre:    Lin_43_LPUART_FLEXIO_Init function must be called before this API.
*
* @implements Lin_WakeupInternal_Activity
*
**/
Std_ReturnType Lin_43_LPUART_FLEXIO_WakeupInternal(uint8 Channel)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = Lin_43_LPUART_FLEXIO_CommonCheckingChannel(Channel, LIN_43_LPUART_FLEXIO_WAKEUPINTERNAL_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check whether the LIN channel is in LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE state */
        if (LIN_43_LPUART_FLEXIO_CH_SLEEP_STATE != Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel])
        {
            /* LIN channel is not in sleep mode */
        #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                                  LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                                  (uint8)LIN_43_LPUART_FLEXIO_WAKEUPINTERNAL_ID, \
                                  (uint8)LIN_43_LPUART_FLEXIO_E_STATE_TRANSITION \
                                 );
        #endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Call LLD function */
            Lin_43_LPUART_FLEXIO_Ipw_WakeUpInternal(Channel);
            /* Update LIN channel status to LIN_43_LPUART_FLEXIO_CH_OPERATIONAL */
            Lin_43_LPUART_FLEXIO_au8LinChStatus[Channel] = LIN_43_LPUART_FLEXIO_CH_OPERATIONAL;

            TempReturn = (uint8)E_OK;
        }
    }

    return TempReturn;
}

#if (LIN_43_LPUART_FLEXIO_VERSION_INFO_API == STD_ON)

/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return void.
*
* @implements Lin_GetVersionInfo_Activity
*
**/
void Lin_43_LPUART_FLEXIO_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                              LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE, \
                              (uint8)LIN_43_LPUART_FLEXIO_GETVERSIONINFO_ID, \
                              (uint8)LIN_43_LPUART_FLEXIO_E_PARAM_POINTER \
                             );
    }
    else
    {
#endif /* LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON */
        (versioninfo)->vendorID = (uint16) LIN_43_LPUART_FLEXIO_VENDOR_ID;
        (versioninfo)->moduleID = (uint16) LIN_43_LPUART_FLEXIO_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8) LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8) LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8) LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION;
#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LIN_43_LPUART_FLEXIO_VERSION_INFO_API == STD_ON */

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
