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

/**
*   @file 
*
*   @addtogroup I2C_DRIVER I2c Driver
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
#include "CDD_I2c.h"
#include "CDD_I2c_Ipw.h"

#if (I2C_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

#include "SchM_I2c.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_I2C_VENDOR_ID_C                      43
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_I2C_AR_RELEASE_MINOR_VERSION_C       7
#define CDD_I2C_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_I2C_SW_MAJOR_VERSION_C               5
#define CDD_I2C_SW_MINOR_VERSION_C               0
#define CDD_I2C_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2c.h header file are of the same vendor */
#if (CDD_I2C_VENDOR_ID_C != CDD_I2C_VENDOR_ID)
     #error "CDD_I2c.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Autosar version */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_C    != CDD_I2C_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_MINOR_VERSION_C    != CDD_I2C_AR_RELEASE_MINOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION_C != CDD_I2C_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_I2c.c and CDD_I2c.h are different"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Software version */
#if ((CDD_I2C_SW_MAJOR_VERSION_C != CDD_I2C_SW_MAJOR_VERSION) || \
     (CDD_I2C_SW_MINOR_VERSION_C != CDD_I2C_SW_MINOR_VERSION) || \
     (CDD_I2C_SW_PATCH_VERSION_C != CDD_I2C_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_I2c.c and CDD_I2c.h are different"
#endif

/* Check if current file and CDD_I2c_Ipw.h header file are of the same vendor */
#if (CDD_I2C_VENDOR_ID_C != CDD_I2C_IPW_VENDOR_ID)
    #error "CDD_I2c.c and CDD_I2c_Ipw.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_Ipw.h header file are of the same Autosar version */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_C    != CDD_I2C_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_MINOR_VERSION_C    != CDD_I2C_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION_C != CDD_I2C_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_I2c.c and CDD_I2c_Ipw.h are different"
#endif
/* Check if current file and CDD_I2c_Ipw.h header file are of the same Software version */
#if ((CDD_I2C_SW_MAJOR_VERSION_C != CDD_I2C_IPW_SW_MAJOR_VERSION) || \
     (CDD_I2C_SW_MINOR_VERSION_C != CDD_I2C_IPW_SW_MINOR_VERSION) || \
     (CDD_I2C_SW_PATCH_VERSION_C != CDD_I2C_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_I2c.c and CDD_I2c_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if the source file and Dem header file are of the same version */
        #if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (CDD_I2C_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of CDD_I2c.c and Dem.h are different"
        #endif
    #endif /* I2C_DISABLE_DEM_REPORT_ERROR_STATUS */

    #if (I2C_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CDD_I2C_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of CDD_I2c.c and Det.h are different"
        #endif
    #endif /* I2C_DEV_ERROR_DETECT */

    /* Check if the source file and SchM_I2c header file are of the same Autosar version */
    #if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_C != SCHM_I2C_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_I2C_AR_RELEASE_MINOR_VERSION_C != SCHM_I2C_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_I2c.c and SchM_I2c.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE

#include "I2c_MemMap.h"


#if (I2C_DEV_ERROR_DETECT == STD_ON)
/**
* @brief          I2C driver status variable.
* @details        I2C driver state machine.
*/
static uint8 I2c_au8DriverStatus[I2C_MAX_PARTITION_ID] = I2C_UNINIT_PARTITION;
#endif

#define I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE

#include "I2c_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "I2c_MemMap.h"

#if (I2C_PRECOMPILE_SUPPORT == STD_ON)
/**
* @brief   Export Pre-Compile configurations.
*/
extern const I2c_ConfigType * const I2c_PBCfgVariantPredefined[I2C_MAX_PARTITION_ID];
#endif /* (I2C_PRECOMPILE_SUPPORT == STD_ON) */

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "I2c_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/* put all I2c variables into defined section */
#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/**
* @brief          I2C channel status array.
* @details        The status of the I2C channels.
*/
volatile I2c_StatusType I2c_aeChannelStatus[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/* put all I2c variables into defined section */
#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
const I2c_ConfigType * I2c_apConfig[I2C_MAX_PARTITION_ID];

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief          DEM errors configuration pointer.
* @details        This is used to report DEM errors in the I2c driver.
*/
const I2c_DemConfigType * I2c_apDemCfg[I2C_MAX_PARTITION_ID] = I2C_NULL_PTR;
#endif

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "I2c_MemMap.h"

/**
* @brief          I2c channel hardware map variable.
* @details        I2c channel hardware map.
*/
uint8 I2c_as8ChannelHardwareMap[I2C_HW_MAX_MODULES] = I2C_HW_MAP_INIT;

/**
* @brief          I2C partition hardware map variable.
* @details        I2C partition hardware map.
*/
uint8 I2c_as8PartitionHardwareMap[I2C_HW_MAX_MODULES] = I2C_HW_MAP_INIT;

#define I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "I2c_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @note put all I2C code into defined section
*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief   This function checks parameters for initialization of I2c driver.
* @details This function checks parameters for initialization of I2c driver.
*
* @param[in]     Config       Specifies the pointer to the configuration set
* @param[in]     PartitionId      Specifies the partition Id of current execution
* @param[out]    CheckStatus      Specifies status of checking
*               - E_OK: The parameters are valid
*               - E_NOT_OK: The parameters are invalid
*
*/
static inline Std_ReturnType I2c_CheckInit(const I2c_ConfigType *Config,
                                           uint8 PartitionId)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_UNINIT state */
    if (I2C_UNINIT != I2c_au8DriverStatus[PartitionId])
    {
        /* I2C driver has been already initialized */
        (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_ALREADY_INITIALIZED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

#if (I2C_PRECOMPILE_SUPPORT != STD_ON)
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
        /* Check Config for not being a null pointer */
        if (NULL_PTR == Config)
        {
            /* SWS_CDD_I2C_00004: Invalid pointer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_INVALID_POINTER);
            CheckStatus = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if (PartitionId != Config->I2c_UserId)
            {
                /* Invalid PartitionId */
                (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_PARAM_CONFIG);
                CheckStatus = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
    #endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                I2c_apConfig[PartitionId] = Config;
#else /* I2C_PRECOMPILE_SUPPORT == STD_ON */
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR != Config)
        {
            /* SWS_CDD_I2C_00004: Invalid pointer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_INVALID_POINTER);
            CheckStatus = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if ((NULL_PTR == I2c_PBCfgVariantPredefined[PartitionId]) || (PartitionId != I2c_PBCfgVariantPredefined[PartitionId]->I2c_UserId))
            {
                /* Invalid PartitionId */
                (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_PARAM_CONFIG);
                CheckStatus = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
    #endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                I2c_apConfig[PartitionId] = I2c_PBCfgVariantPredefined[PartitionId];
                (void)Config;    
#endif /* I2C_PRECOMPILE_SUPPORT == STD_ON */
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            /* Update I2C driver status to I2C_INIT */
                I2c_au8DriverStatus[PartitionId] = I2C_INIT;
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return CheckStatus;
}

/**
* @brief   This function checks parameters for transmit function of I2c driver.
* @details This function checks parameters for transmit function of I2c driver.
*
* @param[in]     Channel       Specifies the index of channel
* @param[in]     RequestPtr     Specifies the pointer to user transmit request
* @param[in]     PartitionId        Specifies the partition Id of current execution
* @param[in]     I2cApiId      Specifies what api call this function
* @param[out]    CheckStatus     Specifies status of checking
*               - E_OK: The parameters are valid
*               - E_NOT_OK: The parameters are invalid
*
*/
static inline Std_ReturnType I2c_CheckMasterTransmit(uint8 Channel,
                                                     const I2c_RequestType * RequestPtr,
                                                     uint8 PartitionId,
                                                     uint8 I2cApiId)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_NOT_OK;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_au8DriverStatus[PartitionId])
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2cApiId, (uint8)I2C_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_HW_MAX_CONFIG)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2cApiId, (uint8)I2C_E_INVALID_CHANNEL);
        }
        else
        {
            /* Check RequestPtr for not being a null pointer */
            if (NULL_PTR == RequestPtr)
            {
                /* Invalid pointer */
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2cApiId, (uint8)I2C_E_INVALID_POINTER);
            }
            else
            {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                if (PartitionId != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_UserId)
                {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
                    /* Invalid Channel is not allocated for this partition */
                    (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2cApiId, (uint8)I2C_E_PARAM_CONFIG);
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    CheckStatus = (Std_ReturnType)E_OK;
                }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    (void)RequestPtr;
    (void)I2cApiId;

    return CheckStatus;
}

/**
* @brief   This function checks parameters for transmit function of I2c driver.
* @details This function checks parameters for transmit function of I2c driver.
*
* @param[in]     Channel       Specifies the index of channel
* @param[in]     DataBuffer     Specifies the pointer to check
* @param[in]     PartitionId        Specifies the partition Id of current execution
* @param[in]     I2cApiId      Specifies what api call this function
* @param[out]    CheckStatus     Specifies status of checking
*               - E_OK: The parameters are valid
*               - E_NOT_OK: The parameters are invalid
*
*/
static inline Std_ReturnType I2c_CheckSlaveApi(uint8 Channel,
                                               const I2c_DataType * DataBuffer,
                                               uint8 PartitionId,
                                               uint8 I2cApiId)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_NOT_OK;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_au8DriverStatus[PartitionId])
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2cApiId, (uint8)I2C_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_HW_MAX_CONFIG)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2cApiId, (uint8)I2C_E_INVALID_CHANNEL);
        }
        else
        {
            /* Check DataBuffer for not being a null pointer */
            if ((NULL_PTR == DataBuffer) && ((uint8)I2C_PREPARESLAVEBUFFER_ID == I2cApiId))
            {
                /* Invalid pointer */
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2cApiId, (uint8)I2C_E_INVALID_POINTER);
            }
            else
            {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                if (PartitionId != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_UserId)
                {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
                    /* Invalid Channel is not allocated for this partition */
                    (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2cApiId, (uint8)I2C_E_PARAM_CONFIG);
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    CheckStatus = (Std_ReturnType)E_OK;
                }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    (void)I2cApiId;
    (void)DataBuffer;
    
    return CheckStatus;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Init
 * Description   : This function performs software initialization of I2C driver.
 * Implements    : I2c_Init_Activity
 *
 *END**************************************************************************/
void I2c_Init(const I2c_ConfigType * Config)
{
    uint8 ChLoop;
    uint8 PartitionId;
    Std_ReturnType CheckStatus;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();
    CheckStatus = I2c_CheckInit(Config, PartitionId);
    
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Get a local copy of the DEM error reporting structure. */
        I2c_apDemCfg[PartitionId] = I2c_apConfig[PartitionId]->I2c_DemConfig;
#endif /* (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

        for (ChLoop=(uint8)0U; ChLoop < I2C_HW_MAX_CONFIG; ChLoop++)
        {
            if (PartitionId == (*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_UserId)
            {
                I2c_aeChannelStatus[ChLoop] = I2C_CH_IDLE;
                /* Map configured hardware channel to logical channel */
                I2c_as8ChannelHardwareMap[(*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_HwUnit] = (uint8)ChLoop;
                /* Map configured hardware channel to partition ID */
                I2c_as8PartitionHardwareMap[(*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_HwUnit] = (uint8)PartitionId;
                /* initialization channel */

                I2c_Ipw_InitChannel((*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop]);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_DeInit
 * Description   : DeInitializes the I2C module.
 * Implements    : I2c_DeInit_Activity
 *
 *END**************************************************************************/
void I2c_DeInit(void)
{
    uint8 ChLoop;
    uint8 PartitionId;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();

    /* Check whether the I2C driver is in I2C_UNINIT state */
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    if (I2C_INIT != I2c_au8DriverStatus[PartitionId])
    {
        /* I2C driver has been already initialized */
        (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_DEINIT_ID, (uint8)I2C_E_UNINIT);
    }
    else
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

        for (ChLoop=(uint8)0U; ChLoop < I2C_HW_MAX_CONFIG; ChLoop++)
        {
            if (PartitionId == (*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_UserId)
            {
                /* Reset I2c_as8ChannelHardwareMap */
                I2c_as8ChannelHardwareMap[(*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_HwUnit] = 0xFFU;
                /* Reset I2c_as8PartitionHardwareMap */
                I2c_as8PartitionHardwareMap[(*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_HwUnit] = 0xFFU;
                /* Set channel status to I2C_CH_IDLE */
                I2c_aeChannelStatus[ChLoop] = I2C_CH_IDLE;
                /* deinit channel */
                I2c_Ipw_DeInitChannel((*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[ChLoop]);
            }
        }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Update I2C driver status to I2C_UNINIT */
    I2c_au8DriverStatus[PartitionId] = I2C_UNINIT;
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_PrepareSlaveBuffer
 * Description   : Prepare the RX or TX buffer for a slave channel.
 * Implements    : I2c_PrepareSlaveBuffer_Activity
 *
 *END**************************************************************************/
Std_ReturnType I2c_PrepareSlaveBuffer(uint8 Channel,
                                      uint8 NumberOfBytes,
                                      I2c_DataType * DataBuffer)
{
    Std_ReturnType TempReturn = (Std_ReturnType)E_NOT_OK;
    Std_ReturnType CheckStatus;
    I2c_StatusType TempChannelStatus;
    uint8 PartitionId;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();

    CheckStatus = I2c_CheckSlaveApi(Channel, DataBuffer, PartitionId, (uint8)I2C_PREPARESLAVEBUFFER_ID);
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
        /* Check whether the I2C channel is a slave or master/slave channel */
        if (I2C_MASTER_MODE != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].MasterSlaveConfig )
        {
            TempChannelStatus = I2c_Ipw_GetStatus((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]);
            if ((I2C_CH_SEND != TempChannelStatus) && (I2C_CH_RECEIVE != TempChannelStatus))
            {
                I2c_Ipw_PrepareSlaveBuffer((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, NumberOfBytes, DataBuffer);
                TempReturn = (Std_ReturnType)E_OK;
            }
        }
        else
        {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2C_PREPARESLAVEBUFFER_ID, (uint8)I2C_E_INVALID_CHANNEL);
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
        }
    }
                    
    return TempReturn;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_SyncTransmit
 * Description   : Sends or receives an I2C message blocking.
 * Implements    : I2c_SyncTransmit_Activity
 *
 *END**************************************************************************/
Std_ReturnType I2c_SyncTransmit(uint8 Channel,
                                const I2c_RequestType * RequestPtr)
{
    Std_ReturnType TempReturn = (Std_ReturnType)E_NOT_OK;
    Std_ReturnType CheckStatus;
    I2c_StatusType TempChannelStatus;
    uint8 PartitionId;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();
    CheckStatus = I2c_CheckMasterTransmit(Channel, RequestPtr, PartitionId, (uint8)I2C_SYNCTRANSMIT_ID);

    if ((Std_ReturnType)E_OK == CheckStatus)
    {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        /* Check whether the I2C channel is a master or master/slave channel */
        if (I2C_SLAVE_MODE != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].MasterSlaveConfig )
        {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

            /* Enter critical section */
            SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_00();

            /* Check whether the I2C channel is in busy state */
            TempChannelStatus = I2c_Ipw_GetStatus((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]);
            if ((I2C_CH_SEND != TempChannelStatus) && (I2C_CH_RECEIVE != TempChannelStatus))
            {
                if (I2C_SEND_DATA == RequestPtr->DataDirection)
                {
                    I2c_aeChannelStatus[Channel] = I2C_CH_SEND;
                }
                else
                {
                    I2c_aeChannelStatus[Channel] = I2C_CH_RECEIVE;
                }

                /* Exit critical section */
                SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_00();

                TempReturn = (uint8)I2c_Ipw_SyncTransmit((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, RequestPtr, &((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]));
            }
            else
            {
                /* Exit critical section */
                SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_00();                            
            }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2C_SYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_CHANNEL);
        }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    }
    return TempReturn;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_AsyncTransmit
 * Description   : Sends or receives an I2C message non-blocking
 * Implements    : I2c_AsyncTransmit_Activity
 *
 *END**************************************************************************/
Std_ReturnType I2c_AsyncTransmit(uint8 Channel,
                                 const I2c_RequestType * RequestPtr)
{
    Std_ReturnType TempReturn = (Std_ReturnType)E_NOT_OK;
    Std_ReturnType CheckStatus;
    I2c_StatusType TempChannelStatus;
    uint8 PartitionId;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();
    CheckStatus = I2c_CheckMasterTransmit(Channel, RequestPtr, PartitionId, (uint8)I2C_ASYNCTRANSMIT_ID);
    
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        /* Check whether the I2C channel is a master or master/slave channel */
        if (I2C_SLAVE_MODE != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].MasterSlaveConfig )
        {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
            /* Enter critical section */
            SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_01();

            /* Check whether the I2C channel is in busy state */
            TempChannelStatus = I2c_Ipw_GetStatus((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]);
            if ((I2C_CH_SEND != TempChannelStatus) && (I2C_CH_RECEIVE != TempChannelStatus))
            {
                if (I2C_SEND_DATA == RequestPtr->DataDirection)
                {
                    I2c_aeChannelStatus[Channel] = I2C_CH_SEND;
                }
                else
                {
                    I2c_aeChannelStatus[Channel] = I2C_CH_RECEIVE;
                }

                /* Exit critical section */
                SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_01();

                TempReturn = (uint8)I2c_Ipw_AsyncTransmit((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, RequestPtr, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]);
            }
            else
            {
                /* Exit critical section */
                SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_01();
            }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2C_ASYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_CHANNEL);
        }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    }

    return TempReturn;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_StartListening
 * Description   : Makes a slave channel available for processing requests (addressings)
 * Implements    : I2c_StartListening_Activity
 *
 *END**************************************************************************/
Std_ReturnType  I2c_StartListening(uint8 Channel)
{
    Std_ReturnType TempReturn = (uint8)E_NOT_OK;
    Std_ReturnType CheckStatus;
    I2c_StatusType TempChannelStatus;
    uint8 PartitionId;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();
    
    CheckStatus = I2c_CheckSlaveApi(Channel, (I2c_DataType*)NULL_PTR, PartitionId, (uint8)I2C_STARTLISTENING_ID);
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
        /* Check whether the I2C channel is a slave or master/slave channel */
        if (I2C_MASTER_MODE != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].MasterSlaveConfig )
        {
            TempChannelStatus = I2c_Ipw_GetStatus((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]);
            if ((I2C_CH_SEND != TempChannelStatus) && (I2C_CH_RECEIVE != TempChannelStatus))
            {
                I2c_Ipw_StartListening((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit);

                TempReturn = (Std_ReturnType)E_OK;
            }
        }
        else
        {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2C_STARTLISTENING_ID, (uint8)I2C_E_INVALID_CHANNEL);
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
        }
    }

    return TempReturn;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_GetStatus
 * Description   : Gets the status of an I2C channel.
 * Implements    : I2c_GetStatus_Activity
 *
 *END**************************************************************************/
I2c_StatusType I2c_GetStatus(uint8 Channel)
{
    I2c_StatusType ChannelStatus = I2C_CH_IDLE;
    uint8 PartitionId;

    /* Get partition ID of current processor */
    PartitionId = (uint8) I2c_GetUserID();
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_au8DriverStatus[PartitionId])
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_GETSTATUS_ID, (uint8)I2C_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (Channel >= I2C_HW_MAX_CONFIG)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID,(uint8)0,(uint8)I2C_GETSTATUS_ID, (uint8)I2C_E_INVALID_CHANNEL);
        }
        else
        {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
            if (PartitionId != (*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_UserId)
            {
                #if (I2C_DEV_ERROR_DETECT == STD_ON)
                /* Invalid Channel is not allocated for this partition */
                (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_GETSTATUS_ID, (uint8)I2C_E_PARAM_CONFIG);
                #endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                ChannelStatus = I2c_Ipw_GetStatus((*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel].I2c_HwUnit, &(*I2c_apConfig[PartitionId]->I2c_HwConfig)[Channel]);
            }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    return ChannelStatus;
}

#if (I2C_VERSION_INFO_API == STD_ON)

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_GetVersionInfo
 * Description   : Gets the version information of this module.
 * Implements    : I2c_GetVersionInfo_Activity
 *
 *END**************************************************************************/
void I2c_GetVersionInfo (Std_VersionInfoType * VersionInfo)
{
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)CDD_I2C_MODULE_ID, (uint8)0, (uint8)I2C_GETVERSIONINFO_ID, (uint8) I2C_E_INVALID_POINTER);
    }
    else
    {
#endif /* I2C_DEV_ERROR_DETECT == STD_ON */
        (VersionInfo)->vendorID = (uint16) CDD_I2C_VENDOR_ID;
        (VersionInfo)->moduleID = (uint16) CDD_I2C_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8) CDD_I2C_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8) CDD_I2C_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8) CDD_I2C_SW_PATCH_VERSION;
#if (I2C_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* I2C_DEV_ERROR_DETECT == STD_ON */
}
#endif /* I2C_VERSION_INFO_API == STD_ON */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

