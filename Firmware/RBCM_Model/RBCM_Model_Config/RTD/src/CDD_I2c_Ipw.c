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
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c_Ipw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_I2C_IPW_VENDOR_ID_C                    43
#define CDD_I2C_IPW_MODULE_ID_C                    255
#define CDD_I2C_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define CDD_I2C_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define CDD_I2C_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define CDD_I2C_IPW_SW_MAJOR_VERSION_C             5
#define CDD_I2C_IPW_SW_MINOR_VERSION_C             0
#define CDD_I2C_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2c_Ipw.h header file are of the same vendor */
#if (CDD_I2C_IPW_VENDOR_ID_C != CDD_I2C_IPW_VENDOR_ID)
    #error "CDD_I2c_Ipw.c and CDD_I2c_Ipw.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_Ipw.h header file are of the same module */
#if (CDD_I2C_IPW_MODULE_ID_C != CDD_I2C_IPW_MODULE_ID)
    #error "CDD_I2c_Ipw.c and CDD_I2c_Ipw.h have different module ids"
#endif
/* Check if current file and CDD_I2c_Ipw.h header file are of the same Autosar version */
#if ( (CDD_I2C_IPW_AR_RELEASE_MAJOR_VERSION_C     != CDD_I2C_IPW_AR_RELEASE_MAJOR_VERSION)   || \
      (CDD_I2C_IPW_AR_RELEASE_MINOR_VERSION_C     != CDD_I2C_IPW_AR_RELEASE_MINOR_VERSION)   || \
      (CDD_I2C_IPW_AR_RELEASE_REVISION_VERSION_C  != CDD_I2C_IPW_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Ipw.c and CDD_I2c_Ipw.h are different"
#endif
/* Check if current file and CDD_I2c_Ipw.h header file are of the same Software version */
#if ( (CDD_I2C_IPW_SW_MAJOR_VERSION_C != CDD_I2C_IPW_SW_MAJOR_VERSION) || \
      (CDD_I2C_IPW_SW_MINOR_VERSION_C != CDD_I2C_IPW_SW_MINOR_VERSION) || \
      (CDD_I2C_IPW_SW_PATCH_VERSION_C != CDD_I2C_IPW_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of CDD_I2c_Ipw.c and CDD_I2c_Ipw.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define I2C_START_SEC_CODE

#include "I2c_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_SlaveCallback
 * Description   : Ipw slave callback
 * Implements    : I2c_Ipw_SlaveCallback_Activity
 *
 *END**************************************************************************/
static void I2c_Ipw_SlaveCallback(Lpi2c_Ip_SlaveEventType Event,
                                  uint8 UserData)
{
    uint8  Channel;

    Channel = (uint8) UserData;

    switch (Event)
    {
        case I2C_SLAVE_EVENT_TX_REQ:
        {
            I2c_aeChannelStatus[Channel] = I2C_CH_SEND;
            break;
        }
        case I2C_SLAVE_EVENT_RX_REQ:
        {
            I2c_aeChannelStatus[Channel] = I2C_CH_RECEIVE;
            break;
        }
        default:
        {
            /* no action  */
            break;
        }
    }

#ifdef I2C_ERROR_CALLBACK
    if((I2C_SLAVE_EVENT_UNDERRUN == Event) || (I2C_SLAVE_EVENT_OVERRUN == Event) || (I2C_SLAVE_EVENT_DMA_TRANSFER_ERROR == Event))
    {

        I2C_ERROR_CALLBACK((uint8)Event, (uint8)Channel);

    }
    else /* No error Event has occurred */
    {
#ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
#endif /* I2C_MODULE_CALLBACK */
    }
#else /* I2C_ERROR_CALLBACK */
#ifdef I2C_MODULE_CALLBACK
    I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
#endif /* I2C_MODULE_CALLBACK */
#endif /* I2C_ERROR_CALLBACK */

    /* Cast to void to avoid compiler warnings */
    (void) Channel;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_MasterCallback
 * Description   : Ipw master callback 
 * Implements    : I2c_Ipw_MasterCallback_Activity
 *
 *END**************************************************************************/
static void I2c_Ipw_MasterCallback(Lpi2c_Ip_MasterEventType Event,
                                   uint8 UserData)
{
    uint32 Channel;
    Channel = (uint32) UserData;

#ifdef I2C_ERROR_CALLBACK
    if((I2C_MASTER_EVENT_NACK == Event) || (I2C_MASTER_EVENT_ARBITRATION_LOST == Event) || (I2C_MASTER_EVENT_DMA_TRANSFER_ERROR == Event))
    {

        I2C_ERROR_CALLBACK((uint8)Event, (uint8)Channel);

    }
    else /* No error event has occurred */
    {
#ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
#endif /* I2C_MODULE_CALLBACK */
    }
#else /* I2C_ERROR_CALLBACK */
    #ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
    #endif /* I2C_MODULE_CALLBACK */
#endif /* I2C_ERROR_CALLBACK */

    /* Cast to void to avoid compiler warnings */
    (void) Event;
    (void) Channel;
}

#if (STD_ON == I2C_FLEXIO_USED)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_FlexioI2cMasterCallback
 * Description   : Ipw flexio i2c master callback
 *
 *END**************************************************************************/
static void I2c_Ipw_FlexioI2cMasterCallback(Flexio_I2c_Ip_MasterEventType Event,
                                            uint8 UserData)
{
    uint32  Channel;

    Channel = (uint32)UserData;

#ifdef I2C_ERROR_CALLBACK
    if((Event == FLEXIO_I2C_MASTER_EVENT_NACK) || (Event == FLEXIO_I2C_MASTER_EVENT_ARBITRATION_LOST) || (Event == FLEXIO_I2C_MASTER_EVENT_DMA_TRANSFER_ERROR))
    {

        I2C_ERROR_CALLBACK((uint8)Event, (uint8)Channel);

    }
    else /* No error event has occurred */
    {
#ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
#endif /* I2C_MODULE_CALLBACK */
    }
#else /* I2C_ERROR_CALLBACK */
    #ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
    #endif /* I2C_MODULE_CALLBACK */
#endif /* I2C_ERROR_CALLBACK */

    /* Cast to void to avoid compiler warnings */
    (void) Event;
    (void) Channel;
}
#endif /* STD_ON == I2C_FLEXIO_USED */
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_InitChannel
 * Description   : This function checks what IP is used and initiate the 
                   module in master or slave mode.
 *
 *END**************************************************************************/
void I2c_Ipw_InitChannel(const uint8 Channel,
                         const I2c_HwUnitConfigType * ConfigPtr)
{
#if (STD_ON == I2C_FLEXIO_USED)
    if (I2C_FLEXIO_CHANNEL == (ConfigPtr->I2c_Ipw_ChannelType))
    {
        (void) Flexio_I2c_Ip_MasterInit(ConfigPtr->HwChannelConfig.I2c_Ipw_FlexioHwConfig->Instance, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), ConfigPtr->HwChannelConfig.I2c_Ipw_FlexioHwConfig);
        Flexio_I2c_Ip_SetMasterCallback(ConfigPtr->HwChannelConfig.I2c_Ipw_FlexioHwConfig->Instance,(uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), &I2c_Ipw_FlexioI2cMasterCallback);
    }
    else
#endif /*I2C_FLEXIO_USED*/
    {
        if (I2C_SLAVE_MODE != ConfigPtr->MasterSlaveConfig)
        {
            Lpi2c_Ip_MasterInit(Channel, ConfigPtr->HwChannelConfig.I2c_Ipw_Lpi2cHwConfig->Master);
            Lpi2c_Ip_SetMasterCallback(Channel, &I2c_Ipw_MasterCallback);
        }
        else
        {
            Lpi2c_Ip_SlaveInit(Channel, ConfigPtr->HwChannelConfig.I2c_Ipw_Lpi2cHwConfig->Slave);
            Lpi2c_Ip_SetSlaveCallback(Channel, &I2c_Ipw_SlaveCallback);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_StartListening
 * Description   : Makes a slave channel available for processing requests
 * Implements    : I2c_Ipw_StartListening_Activity
 *
 *END**************************************************************************/
void I2c_Ipw_StartListening(uint8 Channel)
{
    /* Update slave status */
    I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[Channel]]= I2C_CH_IDLE;
    Lpi2c_Ip_StartListening(Channel);
}

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_ReportDemTimeoutError
 * Description   : Reports timeout error to DEM.
 *
 *END**************************************************************************/
static void I2c_Ipw_ReportDemTimeoutError(void)
{
    /* Partition ID */
    uint8 PartitionId;

    /* Get PartitionId */
    PartitionId = (uint8) I2c_GetUserID();

    if ((uint32)STD_ON == I2c_apDemCfg[PartitionId]->I2c_E_TimeoutFailureCfg.state)
    {
        (void)Dem_SetEventStatus((Dem_EventIdType)I2c_apDemCfg[PartitionId]->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
    }
 }
#endif /* I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_DeInitChannel
 * Description   : This function checks what IP is used and de-initiate the i2c module.
 *
 *END**************************************************************************/
void I2c_Ipw_DeInitChannel(const uint8 Channel,
                           const I2c_HwUnitConfigType * ConfigPtr)
{
#if (STD_ON == I2C_FLEXIO_USED)
    /* Use the Channel variable to switch between IPV levels : LPI2C or FLEXIO, similar to using HwConfigType */
    if (Channel >= I2C_FLEXIO_FIRST_CHANNEL_U8)
    {
        (void)Flexio_I2c_Ip_MasterDeinit(ConfigPtr->HwChannelConfig.I2c_Ipw_FlexioHwConfig->Instance, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8));
    }
    else
#endif
    {
        if(I2C_SLAVE_MODE != ConfigPtr->MasterSlaveConfig)
        {
            Lpi2c_Ip_MasterDeinit(Channel);
        }
        else
        {
            Lpi2c_Ip_SlaveDeinit(Channel);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_SyncTransmit
 * Description   : This function starts a synchronous receive or send transfer.
 *
 *END**************************************************************************/
Std_ReturnType I2c_Ipw_SyncTransmit(uint8 Channel,
                                    const I2c_RequestType * Request,
                                    const I2c_HwUnitConfigType * HwConfigType)
{
    Std_ReturnType TmpReturn;
#if (STD_ON == I2C_FLEXIO_USED)
    /* Use the Channel variable to switch between IPV levels : LPI2C or FLEXIO, similar to using HwConfigType */
    if (Channel >= I2C_FLEXIO_FIRST_CHANNEL_U8)
    {
        (void)Flexio_I2c_Ip_MasterSetSlaveAddr(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), Request->SlaveAddress);

        if(I2C_SEND_DATA == Request->DataDirection)
        {
            TmpReturn = (Std_ReturnType) Flexio_I2c_Ip_MasterSendDataBlocking(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart), I2C_TIMEOUT);
        }
        else
        {
            TmpReturn = (Std_ReturnType) Flexio_I2c_Ip_MasterReceiveDataBlocking(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart), I2C_TIMEOUT);
        }
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if((Std_ReturnType)FLEXIO_I2C_IP_TIMEOUT_STATUS == TmpReturn)
        {
            I2c_Ipw_ReportDemTimeoutError();
        }
#endif
    }
    else
#endif /* STD_ON == I2C_FLEXIO_USED */
    {
        /* Set slave address */
        Lpi2c_Ip_MasterSetSlaveAddr(Channel, Request->SlaveAddress, Request->BitsSlaveAddressSize);

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
        /* Enable/disable high speed mode */
        Lpi2c_Ip_SetMasterHighSpeedMode(Channel, Request->HighSpeedMode);
#endif
        if(I2C_SEND_DATA == Request->DataDirection)
        {
            TmpReturn = (Std_ReturnType) Lpi2c_Ip_MasterSendDataBlocking(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart), I2C_TIMEOUT);
        }
        else
        {
            TmpReturn = (Std_ReturnType) Lpi2c_Ip_MasterReceiveDataBlocking(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart), I2C_TIMEOUT);
        }

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if((Std_ReturnType)LPI2C_IP_TIMEOUT_STATUS == TmpReturn)
        {
            I2c_Ipw_ReportDemTimeoutError();
        }
#endif
    }
    /* SWS_CDD_I2C_00012 */
    if ((Std_ReturnType)E_OK != TmpReturn)
    {
        TmpReturn = (Std_ReturnType)E_NOT_OK;
    }

    (void) HwConfigType;
    return TmpReturn;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_AsyncTransmit
 * Description   : This function starts an asynchronous receive or send transfer. 
 *
 *END**************************************************************************/
Std_ReturnType I2c_Ipw_AsyncTransmit(uint8 Channel,
                                     const I2c_RequestType * Request,
                                     const I2c_HwUnitConfigType * HwConfigType)
{
    Std_ReturnType TmpReturn;
#if (STD_ON == I2C_FLEXIO_USED)
    /* Use the Channel variable to switch between IPV levels : LPI2C or FLEXIO, similar to using HwConfigType */
    if (Channel >= I2C_FLEXIO_FIRST_CHANNEL_U8)
    {
        /* Set slave address */
        (void) Flexio_I2c_Ip_MasterSetSlaveAddr(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), Request->SlaveAddress);

        if(I2C_SEND_DATA == Request->DataDirection)
        {
            TmpReturn = (Std_ReturnType) Flexio_I2c_Ip_MasterSendData(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart));
        }
        else
        {
            TmpReturn = (Std_ReturnType) Flexio_I2c_Ip_MasterReceiveData(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart));
        }
    }
    else
#endif  /* STD_ON == I2C_FLEXIO_USED */
    {
         /* Set slave address */
        Lpi2c_Ip_MasterSetSlaveAddr(Channel, Request->SlaveAddress, Request->BitsSlaveAddressSize);

#if (STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)
        /* Enable/disable high speed mode */
        Lpi2c_Ip_SetMasterHighSpeedMode(Channel, Request->HighSpeedMode);
#endif

        if(I2C_SEND_DATA == Request->DataDirection)
        {
            TmpReturn = (Std_ReturnType) Lpi2c_Ip_MasterSendData(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart));
        }
        else
        {
            TmpReturn = (Std_ReturnType) Lpi2c_Ip_MasterReceiveData(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart));
        }
    }
    if((Std_ReturnType)E_OK != TmpReturn)
    {
        TmpReturn = E_NOT_OK;
    }

    (void) HwConfigType;
    return TmpReturn;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_PrepareSlaveBuffer
 * Description   : Prepares a TX or RX buffer for slave module. 
 *
 *END**************************************************************************/
void I2c_Ipw_PrepareSlaveBuffer(uint8 Channel,
                                uint8 NumberOfBytes,
                                I2c_DataType * DataBuffer)
{
    /* Only LPI2C can be configured as a SLAVE channel */
    (void)Lpi2c_Ip_SlaveSetBuffer(Channel, DataBuffer, NumberOfBytes);
}


static I2c_StatusType I2c_Ipw_ConvertStatus(const uint8 Channel,
                                            const uint32 Status)
{

    I2c_StatusType RetStatus;

    switch (Status)
    {
        case 0U: /* STATUS_SUCCESS */
        {
            if(I2C_CH_IDLE == I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[Channel]])
            {
                RetStatus = I2C_CH_IDLE;
            }
            else
            {
                RetStatus = I2C_CH_FINISHED;
            }

            break;
        }
        case 2U: /* STATUS_BUSY */
        {
            if(I2C_CH_SEND == I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[Channel]])
            {
                RetStatus = I2C_CH_SEND;
            }
            else
            {
                RetStatus = I2C_CH_RECEIVE;
            }

            break;
        }
        default:
        {
            RetStatus = I2C_CH_ERROR_PRESENT;
            break;
        }
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_GetStatus
 * Description   : Returns the current status of the i2c module.
 *
 *END**************************************************************************/
I2c_StatusType I2c_Ipw_GetStatus(const uint8 Channel,
                                 const I2c_HwUnitConfigType * HwConfigType)
{
    uint32 RetStatus;
#if (STD_ON == I2C_FLEXIO_USED)
    /* Use the Channel variable to switch between IPV levels : LPI2C or FLEXIO, similar to using HwConfigType */
    if (Channel >= I2C_FLEXIO_FIRST_CHANNEL_U8)
    {
        RetStatus = (uint32)Flexio_I2c_Ip_MasterGetStatus(0U, (uint8)(Channel - I2C_FLEXIO_FIRST_CHANNEL_U8), NULL_PTR);
    }
    else
#endif
    {
        if(I2C_SLAVE_MODE != HwConfigType->MasterSlaveConfig)
        {
            RetStatus = (uint32)Lpi2c_Ip_MasterGetTransferStatus(Channel, NULL_PTR);
        }
        else
        {
            RetStatus = (uint32)Lpi2c_Ip_SlaveGetTransferStatus(Channel, NULL_PTR);
        }
    }
    (void) HwConfigType;
    /* Convert status */
    return I2c_Ipw_ConvertStatus(Channel, RetStatus);

}


#define I2C_STOP_SEC_CODE
/** 
* @violates @ref I2c_Ipw_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_Ipw_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

/*******************************************************************************
 * EOF
 ******************************************************************************/
