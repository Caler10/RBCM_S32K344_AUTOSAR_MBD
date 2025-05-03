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

#ifndef CDD_I2C_TYPES_H
#define CDD_I2C_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @implements CDD_I2c_Types.h_Artifact
*/
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "CDD_I2c_Ipw_Types.h"
#include "CDD_I2c_CfgDefines.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_I2C_TYPES_VENDOR_ID                         43
#define CDD_I2C_TYPES_MODULE_ID                         255
#define CDD_I2C_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define CDD_I2C_TYPES_AR_RELEASE_MINOR_VERSION          7
#define CDD_I2C_TYPES_AR_RELEASE_REVISION_VERSION       0
#define CDD_I2C_TYPES_SW_MAJOR_VERSION                  5
#define CDD_I2C_TYPES_SW_MINOR_VERSION                  0
#define CDD_I2C_TYPES_SW_PATCH_VERSION                  0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2c_Ipw_Types.h header file are of the same vendor */
#if (CDD_I2C_TYPES_VENDOR_ID != CDD_I2C_IPW_TYPES_VENDOR_ID)
    #error "CDD_I2c_Types.h and CDD_I2c_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_Ipw_Types.h header file are of the same Autosar version */
#if ((CDD_I2C_TYPES_AR_RELEASE_MAJOR_VERSION != CDD_I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (CDD_I2C_TYPES_AR_RELEASE_MINOR_VERSION != CDD_I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (CDD_I2C_TYPES_AR_RELEASE_REVISION_VERSION != CDD_I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Types.h and CDD_I2c_Ipw_Types.h are different"
#endif
/* Check if current file and CDD_I2c_Ipw_Types.h header file are of the same Software version */
#if ((CDD_I2C_TYPES_SW_MAJOR_VERSION != CDD_I2C_IPW_TYPES_SW_MAJOR_VERSION) || \
     (CDD_I2C_TYPES_SW_MINOR_VERSION != CDD_I2C_IPW_TYPES_SW_MINOR_VERSION) || \
     (CDD_I2C_TYPES_SW_PATCH_VERSION != CDD_I2C_IPW_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_I2c_Types.h and CDD_I2c_Ipw_Types.h are different"
#endif

/* Check if current file and CDD_I2c_CfgDefines.h header file are of the same vendor */
#if (CDD_I2C_TYPES_VENDOR_ID != CDD_I2C_VENDOR_ID_CFGDEFINES)
    #error "CDD_I2c_Types.h and CDD_I2c_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_CfgDefines.h header file are of the same Autosar version */
#if ((CDD_I2C_TYPES_AR_RELEASE_MAJOR_VERSION    != CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) ||    \
     (CDD_I2C_TYPES_AR_RELEASE_MINOR_VERSION    != CDD_I2C_AR_RELEASE_MINOR_VERSION_CFGDEFINES) ||    \
     (CDD_I2C_TYPES_AR_RELEASE_REVISION_VERSION != CDD_I2C_AR_RELEASE_REVISION_VERSION_CFGDEFINES)    \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Types.h and CDD_I2c_CfgDefines.h are different"
#endif
/* Check if current file and CDD_I2c_CfgDefines.h header file are of the same Software version */
#if ((CDD_I2C_TYPES_SW_MAJOR_VERSION != CDD_I2C_SW_MAJOR_VERSION_CFGDEFINES) || \
     (CDD_I2C_TYPES_SW_MINOR_VERSION != CDD_I2C_SW_MINOR_VERSION_CFGDEFINES) || \
     (CDD_I2C_TYPES_SW_PATCH_VERSION != CDD_I2C_SW_PATCH_VERSION_CFGDEFINES)    \
    )
    #error "Software Version Numbers of CDD_I2c_Types.h and CDD_I2c_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((CDD_I2C_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_I2C_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_I2c_Types.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief          API functions service IDs.
* @details        Service IDs of the I2C API.
*/
typedef enum
{

    I2C_INIT_ID               =   (uint8)0x00U, /**< @brief I2c_Init() ID.*/
    I2C_DEINIT_ID             =   (uint8)0x01U, /**< @brief I2c_DeInit() ID.*/
    I2C_SYNCTRANSMIT_ID       =   (uint8)0x02U, /**< @brief I2c_SyncTransmit() ID.*/
    I2C_ASYNCTRANSMIT_ID      =   (uint8)0x03U, /**< @brief I2c_AsyncTransmit() ID.*/
    I2C_GETSTATUS_ID          =   (uint8)0x04U, /**< @brief I2c_GetStatus() ID.*/
    I2C_PREPARESLAVEBUFFER_ID =   (uint8)0x05U, /**< @brief I2c_PrepareSlaveBuffer() ID.*/
    I2C_STARTLISTENING_ID     =   (uint8)0x06U, /**< @brief I2c_StartListening() ID.*/
    I2C_GETVERSIONINFO_ID     =   (uint8)0x0AU  /**< @brief I2c_GetVersionInfo() ID.*/
} I2c_ApiFunctionIdType;

/**
 * @brief Definition for different state and errors of Operation Status
 *
 *
 * @implements I2c_StatusType_enum
*/
typedef enum
{
    I2C_CH_IDLE          = 0U,  /**< @brief Status Indication I2C channel is idle */
    I2C_CH_SEND,                /**< @brief Status Indication send operation is ongoing */
    I2C_CH_RECEIVE,             /**< @brief Status Indication receiving operation is ongoing */
    I2C_CH_FINISHED,            /**< @brief Status Indication operation is finished */
    I2C_CH_ERROR_PRESENT        /**< @brief Status Indication an error is present */

} I2c_StatusType;

/**
  * @brief Asynchronous method used
  *
  * @implements I2c_AsynchronousMethodType_enum
  */
typedef enum
{
    I2C_INTERRUPT_MODE = 0x0U,      /**< @brief Asynchronous Mechanism using interrupts */
    I2C_DMA_MODE       = 0x1U       /**< @brief Asynchronous Mechanism using DMA */
} I2c_AsynchronousMethodType;

/**
 * @brief Definition of the master/slave mode of an I2C hw unit
  */
typedef enum
{
    /* The channel is an I2C master */
    I2C_MASTER_MODE = 0x0U,
    /* The channel is an I2C slave */
    I2C_SLAVE_MODE  = 0x1U,
    /* The channel is both I2C master and I2C slave */
    I2C_MASTER_SLAVE_MODE  = 0x2U
} I2c_MasterSlaveModeType;

/**
 * @brief Definition of the type of activation or procession mechanism of an I2C hw unit
 * @implements     I2c_DataDirectionType_enum
 */
typedef enum
{
    I2C_SEND_DATA       = 0x0U, /**< @brief Used to send data to a slave */
    I2C_RECEIVE_DATA    = 0x1U  /**< @brief Used to receive data from a slave */
} I2c_DataDirectionType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief          This gives the numeric ID (hardware number) of an I2C hw Unit
 *
 * @implements     I2c_HwUnitType_typedef
 *
 */
typedef uint8                          I2c_HwUnitType;

/**
 * @brief          This gives the numeric ID (paritition number) of an I2C hw Unit
 *
 */
typedef uint8                          I2c_PartCoreType;

/**
 * @brief          Type Address Value of Device and its register value
 *
 * @implements     I2c_AddressType_typedef
 *
 */
typedef uint16                         I2c_AddressType;

/**
 * @brief          Type Data to be sent or received
 *
 * @implements     I2c_DataType_typedef
 *
 */
typedef uint8                          I2c_DataType;

/**
 * @brief    Structure that contains I2C Hw configuration.
 * @details  It contains the information specific to one I2C Hw unit
 *
 * @implements  I2c_HwUnitConfigType_struct
 */
typedef struct
{
    /**< @brief Numeric instance value of I2C Hw Unit */
    const I2c_HwUnitType                              I2c_HwUnit;

    /**< @brief Numeric Partition Id */
    const  I2c_PartCoreType                           I2c_UserId;

    /**< @brief Master/slave mode configuration of the I2C Hw Unit */
    const I2c_MasterSlaveModeType                     MasterSlaveConfig;

    /**< @brief Hardware channel type */
    const I2c_Ipw_HwChannelType                       I2c_Ipw_ChannelType;

    /**< @brief Structure containing the hardware specific configuration for the channel. */
    const I2c_Ipw_HwChannelConfigType                 HwChannelConfig;

}I2c_HwUnitConfigType;

/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    Mcal_DemErrorType I2c_E_TimeoutFailureCfg;

} I2c_DemConfigType;

/**
 * @brief This type contains initialization data.
 * @details This contains initialization data for the I2C driver. It shall contain:
 *         - The number of I2C modules to be configured
 *         - Dem error reporting configuration
 *         - I2C dependent properties for used HW units
 * @implements     I2c_ConfigType_struct
*/
typedef struct
{
    /**< @brief Numeric Partition Id */
    const  I2c_PartCoreType I2c_UserId;

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /**< @brief DEM error reporting configuration. */
    const I2c_DemConfigType * I2c_DemConfig;
#endif

    /**< @brief Pointer to I2c hardware unit configuration */
    const I2c_HwUnitConfigType (*I2c_HwConfig)[];
} I2c_ConfigType;

/**
 * @brief Definition for Request Buffer. This is the structure which is passed to I2c_SyncTransmit or I2c_AsyncTransmit
 * function. This holds the necessary information required for the communication of I2C Hw with the Slave
 * device
 *
 * @implements     I2c_RequestType_struct
*/
typedef struct
{
    /**< @brief Slave Device Address */
    I2c_AddressType                  SlaveAddress;

    /**< @brief This is true when the slave address is 10 bits, when false the address is on 7 bits. */
    boolean                          BitsSlaveAddressSize;
#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
    /**< @brief If this is true the data will be sent with high speed enabled (if hardware support exists). */
    boolean                          HighSpeedMode;
#endif
    /**< @brief When this is true, NACK will be ignored during the address cycle. */
    boolean                          ExpectNack;

    /**< @brief When this is true, a repeated start (Sr) will be issued on the bus instead of a STOP at the end of the transfer. */
    boolean                          RepeatedStart;

    /**< @brief Buffer Size : The number of bytes for reading or writing.*/
    uint16                           BufferSize;

    /**< @brief Direction of the data. Can be either Send or Receive. */
    I2c_DataDirectionType            DataDirection;

    /**< @brief Buffer to Store or to transmit Serial data */
    I2c_DataType *    DataBuffer;

} I2c_RequestType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

extern const I2c_DemConfigType I2c_DemConfig;

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /*CDD_I2C_TYPES_H*/

/** @} */

