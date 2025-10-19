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

#ifndef CDD_I2C_H
#define CDD_I2C_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @implements CDD_I2c.h_Artifact
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c_Types.h"
#include "CDD_I2c_Cfg.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_I2C_VENDOR_ID                      43
#define CDD_I2C_MODULE_ID                      255
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION       4
#define CDD_I2C_AR_RELEASE_MINOR_VERSION       7
#define CDD_I2C_AR_RELEASE_REVISION_VERSION    0
#define CDD_I2C_SW_MAJOR_VERSION               5
#define CDD_I2C_SW_MINOR_VERSION               0
#define CDD_I2C_SW_PATCH_VERSION               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2c_Types.h header file are of the same vendor */
#if (CDD_I2C_VENDOR_ID != CDD_I2C_TYPES_VENDOR_ID)
    #error "CDD_I2c.h and CDD_I2c_Types.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_Types.h header file are of the same Autosar version */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION    != CDD_I2C_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_MINOR_VERSION    != CDD_I2C_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION != CDD_I2C_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c.h and CDD_I2c_Types.h are different"
#endif
/* Check if current file and CDD_I2c_Types.h header file are of the same Software version */
#if ((CDD_I2C_SW_MAJOR_VERSION != CDD_I2C_TYPES_SW_MAJOR_VERSION) || \
     (CDD_I2C_SW_MINOR_VERSION != CDD_I2C_TYPES_SW_MINOR_VERSION) || \
     (CDD_I2C_SW_PATCH_VERSION != CDD_I2C_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_I2c.h and CDD_I2c_Types.h are different"
#endif

/* Check if current file and CDD_I2c_Cfg.h header file are of the same vendor */
#if (CDD_I2C_VENDOR_ID != CDD_I2C_VENDOR_ID_CFG)
    #error "CDD_I2c.h and CDD_I2c_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_Cfg.h header file are of the same Autosar version */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION    != CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDD_I2C_AR_RELEASE_MINOR_VERSION    != CDD_I2C_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION != CDD_I2C_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of CDD_I2c.h and CDD_I2c_Cfg.h are different"
#endif
/* Check if current file and CDD_I2c_Cfg.h header file are of the same Software version */
#if ((CDD_I2C_SW_MAJOR_VERSION != CDD_I2C_SW_MAJOR_VERSION_CFG) || \
     (CDD_I2C_SW_MINOR_VERSION != CDD_I2C_SW_MINOR_VERSION_CFG) || \
     (CDD_I2C_SW_PATCH_VERSION != CDD_I2C_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of CDD_I2c.h and CDD_I2c_Cfg.h are different"
#endif

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
      /* Check if the source file and Dem header file are of the same version */
      #if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (CDD_I2C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION)    \
          )
          #error "AutoSar Version Numbers of CDD_I2c.h and Dem.h are different"
      #endif
  #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* I2C_DISABLE_DEM_REPORT_ERROR_STATUS */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#if (I2C_DEV_ERROR_DETECT == STD_ON)

/**
* @brief            API service used without module initialization
* @details          The I2C Driver module shall report the development error "I2C_E_UNINIT (0x01)",
*                   when the API Service is used without module initialization.
*
* @api
*/
#define I2C_E_UNINIT            ((uint8)0x01U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The I2C Driver module shall report the development error
*                   "I2C_E_INVALID_CHANNEL (0x02)", when API Service used with
*                   an invalid or inactive channel parameter.
*
* @api
*/
#define I2C_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The I2C Driver module shall report the development error
*                   "I2C_E_INVALID_POINTER (0x03)", when API Service is called
*                   with invalid configuration pointer.
*
* @api
*/
#define I2C_E_INVALID_POINTER   ((uint8)0x03U)

/**
* @brief            Initialization called when already initialized
* @details          The I2C Driver module shall report the development error
*                   "I2C_E_ALREADY_INITIALIZED (0x04)", when initialization is called
*                   when the driver is already initialized.
*
* @api
*/
#define I2C_E_ALREADY_INITIALIZED  ((uint8)0x04U)

/**
* @brief            Number of bytes is exceeded, if a limit exists for the channel
* @details          The I2C Driver module shall report the development error
*                   "I2C_E_INVALID_BUFFER_SIZE (0x05)", when I2c_SyncTransmit or
*                   I2c_AsyncTransmit are called with a number of bytes that exceed the
*                   maximum number of bytes supported for that channel.
*
* @api
*/
#define I2C_E_INVALID_BUFFER_SIZE  ((uint8)0x05U)

/**
* @brief            I2C driver states
* @details          The state I2C_UNINIT means that the I2C module has not
*                   been initialized yet and cannot be used.
*
* @api
*/
#define I2C_UNINIT              (0x01U)

/**
* @brief            I2C driver states
* @details          The I2C_INIT state indicates that the I2C driver has been
*                   initialized, making each available channel ready for service.
*
* @api
*/
#define I2C_INIT                (0x02U)

/**
* @brief             API service called with wrong assigned resource.
* @details          The I2C Driver module shall report the development error
*                   "I2C_E_PARAM_CONFIG (0x06)" when the core ID of the currently executing
*                   core does not match with the partition id stored in the configuration.
*
*/

#define I2C_E_PARAM_CONFIG        ((uint8)0x0FU)

/**
* @brief            API service called with invalid init configuration pointer
* @details          The I2C Driver module shall report the development error
*                   "I2C_E_INIT_FAILED (0x06)", when API Service is called
*                   with invalid init configuration pointer.
*
* @api
*/
#define I2C_E_INIT_FAILED   ((uint8)0x06U)

#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

#if (I2C_PRECOMPILE_SUPPORT == STD_OFF)
/**
* @brief   Export Post-Build configurations.
*/
I2C_CONFIG_EXT
#endif /* (I2C_PRECOMPILE_SUPPORT == STD_OFF) */

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "I2c_MemMap.h"

extern uint8 I2c_as8ChannelHardwareMap[I2C_HW_MAX_MODULES];

extern uint8 I2c_as8PartitionHardwareMap[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/** @violates @ref I2c_h_REF_4  This is incorrectly reported by the PCLint tool. */
extern const I2c_DemConfigType * I2c_apDemCfg[I2C_MAX_PARTITION_ID];
#endif

extern const I2c_ConfigType * I2c_apConfig[I2C_MAX_PARTITION_ID];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

extern volatile I2c_StatusType I2c_aeChannelStatus[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief   Initializes the I2C module.
* @details This function performs software initialization of I2C
*          driver:
*          - Maps logical channels to hardware channels
*          - Initializes all channels
*          - Sets driver state machine to I2C_INIT.
*
* @param[in] pConfig        Pointer to I2C driver configuration set.
*
* @return  void
*
* @api
*
*
* @note    Service ID: 0x00.
* @note    Synchronous, non re-entrant function.
*
*/

/* @implements I2c_Init_Activity */
void I2c_Init(const I2c_ConfigType * Config);

/**
* @brief   DeInitializes the I2C module.
* @details This function performs software de initialization of I2C modules to reset values.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of I2c_Init()
*          The driver needs to be initialized before calling I2c_DeInit(). Otherwise, the
*          function I2c_DeInit shall raise the development error I2C_E_UNINIT and leave the desired
*          de initialization functionality without any action.
*
* @param[in] void
*
* @return  void
*
* @api
*
*
* @note    Service ID: 0x01.
* @note    Synchronous, non re-entrant function.
*
*/

/* @implements I2c_DeInit_Activity */
void I2c_DeInit(void);

/**
* @brief   Sends or receives an I2C message blocking.
* @details Sends the slave address and based on the direction of the message it sends
*          or receives data by using a blocking mechanism.
*
* @param[in] u8Channel     I2C channel to be addressed.
* @param[in] pRequestPtr   Pointer to data information to be used
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or
*                          I2C driver is not initialized or
*                          pRequestPtr is NULL or
*                          I2C Channel is in busy state.
* @retval E_OK             Otherwise.
*
* @api
*
*
* @note    Service ID: 0x02.
* @note    Synchronous, non reentrant function.
*
*/

/* @implements I2c_SyncTransmit_Activity */
Std_ReturnType I2c_SyncTransmit(uint8 Channel,
                                const I2c_RequestType * RequestPtr);

/**
* @brief   Starts an asynchronous transmission on the I2C bus.
* @details Sends the slave address and enables the interrupts that will send
*          or receive data depending on the direction of the message.
*
* @param[in] u8Channel     I2C channel to be addressed.
* @param[in] pRequestPtr   Pointer to data information to be used
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or
*                          I2C driver is not initialized or
*                          pRequestPtr is NULL or
*                          I2C Channel is in busy state.
* @retval E_OK             Otherwise.
*
* @api
*
*
* @note    Service ID: 0x03.
* @note    Synchronous, non reentrant function.
*
*/

/* @implements I2c_AsyncTransmit_Activity */
Std_ReturnType I2c_AsyncTransmit(uint8 Channel,
                                 const I2c_RequestType * RequestPtr);

/**
* @brief   Gets the status of an I2C channel.
* @details Gets the status of an I2C channel and checks for errors.
*
* @param[in] u8Channel     I2C channel to be addressed.
*
* @return                  I2C_StatusType.
* @retval I2C_CH_IDLE           If the I2C Channel is in default state.
* @retval I2C_CH_SEND           If the I2C Channel is busy sending data.
* @retval I2C_CH_RECEIVE        If the I2C Channel is busy receiving data.
* @retval I2C_CH_FINISHED       If the I2C Channel finished the last transmission (sending
*                               or receiving data) successfully with no errors.
* @retval I2C_CH_ERROR_PRESENT  If the I2C Channel encountered an error during the last transmission.
*
* @api
*
*
* @note    Service ID: 0x04.
* @note    Synchronous, non re-entrant function.
*
*/

/* @implements I2c_GetStatus_Activity */
I2c_StatusType I2c_GetStatus(uint8 Channel);

/**
* @brief   Prepare the RX or TX buffer for a slave channel.
* @details Prepares a RX or TX buffer that will be used to receive data or send data when requested by the master.
*
* @param[in] Channel       I2C channel to be addressed.
* @param[in] NumberOfBytes Maximum number of bytes to be sent or received.
* @param[in] DataBuffer     Pointer to data buffer
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or I2C driver is not initialized or DataBuffer is NULL or
*                          I2C Channel is a master channel.
* @retval E_OK             Otherwise.
*
* @api
*
* @note    Service ID: 0x05.
* @note    Synchronous, non reentrant function.
*
*/

/* @implements I2c_PrepareSlaveBuffer_Activity */
Std_ReturnType I2c_PrepareSlaveBuffer(uint8 Channel,
                                      uint8 NumberOfBytes,
                                      I2c_DataType * DataBuffer);

/**
* @brief   Makes a slave channel available for processing requests (addressings).
* @details When called, the slave channel becomes available for starting incoming or outgoing transfers.
*
* @param[in] u8Channel     I2C channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or I2C driver is not initialized or I2C Channel is a
*                          master channel.
* @retval E_OK             Otherwise.
*
* @api
*
* @note    Service ID: 0x06.
* @note    Synchronous, non reentrant function.
*
*/

/* @implements I2c_StartListening_Activity */
Std_ReturnType I2c_StartListening(uint8 Channel);

#if (I2C_VERSION_INFO_API == STD_ON)
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
* @param[in,out] pVersionInfo   Pointer for storing the version information
*                               of this module.
*
* @return                  void.
*
* @api
*
*
* @pre            Preconditions as text description. Optional tag.
*
* @note    Service ID: 0x0A.
* @note    Synchronous, non re-entrant function.
*
*/

/* @implements I2c_GetVersionInfo_Activity */
void I2c_GetVersionInfo (Std_VersionInfoType * VersionInfo);
#endif  /* #if I2C_VERSION_INFO_API == STD_ON */

#define I2C_STOP_SEC_CODE

#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CDD_I2C_H */

/** @} */

