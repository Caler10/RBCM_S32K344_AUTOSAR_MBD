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

#ifndef XRDC_IP_TYPES_H
#define XRDC_IP_TYPES_H

/**
*   @file Xrdc_Ip_Types.h
*
*   @addtogroup XRDC_IP XRDC IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Mcal.h"
#include "Xrdc_Ip_Cfg_Defines.h"

/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define RM_XRDC_IP_TYPES_VENDOR_ID                      43
#define RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define RM_XRDC_IP_TYPES_SW_MAJOR_VERSION               5
#define RM_XRDC_IP_TYPES_SW_MINOR_VERSION               0
#define RM_XRDC_IP_TYPES_SW_PATCH_VERSION               0

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Xrdc_Ip_Types.h and Mcal.h are different"
    #endif
#endif

/* Checks against Xrdc_Ip_Cfg_Defines.h */
#if (RM_XRDC_IP_TYPES_VENDOR_ID != RM_XRDC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Xrdc_Ip_Types.h and Xrdc_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_Types.h and Xrdc_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_XRDC_IP_TYPES_SW_MAJOR_VERSION != RM_XRDC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_TYPES_SW_MINOR_VERSION != RM_XRDC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_TYPES_SW_PATCH_VERSION != RM_XRDC_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xrdc_Ip_Types.h and Xrdc_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define XRDC_WORD0            ((uint32)0UL)
#define XRDC_WORD1            ((uint32)1UL)
#define XRDC_WORD2            ((uint32)2UL)
#define XRDC_WORD3            ((uint32)3UL)
#define XRDC_WORD4            ((uint32)4UL)
#define XRDC_WORD5            ((uint32)5UL)
#define XRDC_WORD6            ((uint32)6UL)
#define XRDC_WORD7            ((uint32)7UL)
#define XRDC_WORD8            ((uint32)8UL)
#define XRDC_WORD9            ((uint32)9UL)
#define XRDC_WORD10           ((uint32)10UL)
#define XRDC_WORD11           ((uint32)11UL)
#define XRDC_WORD12           ((uint32)12UL)
#define XRDC_WORD13           ((uint32)13UL)
#define XRDC_WORD14           ((uint32)14UL)
#define XRDC_WORD15           ((uint32)15UL)

#define XRDC_INSTANCE0        ((uint32)0UL)
#define XRDC_INSTANCE1        ((uint32)1UL)
#define XRDC_INSTANCE2        ((uint32)2UL)
#define XRDC_INSTANCE3A       ((uint32)3UL)
#define XRDC_INSTANCE3B       ((uint32)4UL)
#define XRDC_INSTANCE4        ((uint32)5UL)
#define XRDC_INSTANCE5        ((uint32)6UL)
#define XRDC_SMU_INSTANCE0    ((uint32)7UL)
#define XRDC_RTU_INSTANCE0    ((uint32)8UL)
#define XRDC_RTU_INSTANCE1    ((uint32)9UL)
#define XRDC_CE_INSTANCE0     ((uint32)10UL)

#define XRDC_A_INSTANCE       ((uint32)0UL)
#define XRDC_B_INSTANCE       ((uint32)1UL)
#define XRDC_C_INSTANCE       ((uint32)2UL)
#define XRDC_CPE_INSTANCE     ((uint32)3UL)
#define XRDC_LPE_INSTANCE     ((uint32)4UL)

#define XRDC_MRC0             ((uint32)0UL)
#define XRDC_MRC1             ((uint32)1UL)
#define XRDC_MRC2             ((uint32)2UL)
#define XRDC_MRC3             ((uint32)3UL)
#define XRDC_MRC4             ((uint32)4UL)
#define XRDC_MRC5             ((uint32)5UL)
#define XRDC_MRC6             ((uint32)6UL)
#define XRDC_MRC7             ((uint32)7UL)
#define XRDC_MRC8             ((uint32)8UL)
#define XRDC_MRC9             ((uint32)9UL)
#define XRDC_MRC10            ((uint32)10UL)
#define XRDC_MRC11            ((uint32)11UL)
#define XRDC_MRC12            ((uint32)12UL)
#define XRDC_MRC13            ((uint32)13UL)
#define XRDC_MRC14            ((uint32)14UL)
#define XRDC_MRC15            ((uint32)15UL)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief              Enumeration listing MDAC instances
* */
typedef enum
{
    XRDC_MDAC0=0,
    XRDC_MDAC1,
    XRDC_MDAC2,
    XRDC_MDAC3,
    XRDC_MDAC4,
    XRDC_MDAC5,
    XRDC_MDAC6,
    XRDC_MDAC7,
    XRDC_MDAC8,
    XRDC_MDAC9,
    XRDC_MDAC10,
    XRDC_MDAC11,
    XRDC_MDAC12,
    XRDC_MDAC13,
    XRDC_MDAC14,
    XRDC_MDAC15,
    XRDC_MDAC16,
    XRDC_MDAC17,
    XRDC_MDAC18,
    XRDC_MDAC19,
    XRDC_MDAC20,
    XRDC_MDAC21,
    XRDC_MDAC22,
    XRDC_MDAC23
} Xrdc_Ip_MDACInstanceType;

/**
* @brief              Enumeration listing secure attributes of a XRDC master
* */
typedef enum
{
    XRDC_SECURE = 0,
    XRDC_NON_SECURE,
    XRDC_INPUT_FROM_BUS_MASTER
} Xrdc_Ip_SecureAttributeType;

/**
* @brief              Enumeration listing priviledge attributes of a XRDC master
* */
typedef enum
{
    XRDC_USER_MODE = 0,
    XRDC_PRIVILEDGE_MODE,
    XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
} Xrdc_Ip_PriviledgedAttributeType;

/**
* @brief              Enumeration listing of a PID lock registers
* */
typedef enum
{
    XRDC_PID_UNLOCKED = 0,
    XRDC_PID_ALLOW_ACCESS_FROM_MASTER = 2,
    XRDC_PID_FULLY_LOCKED
} Xrdc_Ip_PIDLockBit;

/**
* @brief              Enumeration listing XRDC domain IDs
* */
typedef enum
{
    XRDC_DOMAIN0 = 0,
    XRDC_DOMAIN1 = 1,
    XRDC_DOMAIN2 = 2,
    XRDC_DOMAIN3 = 3,
    XRDC_DOMAIN4 = 4,
    XRDC_DOMAIN5 = 5,
    XRDC_DOMAIN6 = 6,
    XRDC_DOMAIN7 = 7,
    XRDC_DOMAIN8 = 8,
    XRDC_DOMAIN9 = 9,
    XRDC_DOMAIN10 = 10,
    XRDC_DOMAIN11 = 11,
    XRDC_DOMAIN12 = 12,
    XRDC_DOMAIN13 = 13,
    XRDC_DOMAIN14 = 14,
    XRDC_DOMAIN15 = 15,
    XRDC_UNKNOWN_DOMAIN = 255
} Xrdc_Ip_DomainIDType;

/**
* @brief              Enumeration listing XRDC master core
* @details            most significant byte is XRDC instance.
*                     least significant byte is Master core number.
*                     Ex: 0x110 - XRDC instance 1, Master core number 16.
**/
typedef enum
{
    XRDC_CORE_M7_0         = 0x00U,
    XRDC_CORE_HSE          = 0x03U,
    XRDC_CORE_M7_1         = 0x04U
} Xrdc_Ip_MasterCoreType;
/**
* @brief              Enumeration listing XRDC masters type
* */
typedef enum
{
    XRDC_CORE_MASTER = 0,
    XRDC_NONCORE_MASTER = 1,
    XRDC_RESERVE
} Xrdc_Ip_MasterType;

/**
* @brief              Enumeration listing states of access violations
* */
typedef enum
{
    XRDC_IP_NO_ACCESS              = 0,
    XRDC_IP_SINGLE_ACCESS          = 1,
    XRDC_IP_MULTIPLE_ACCESS        = 2
} Xrdc_Ip_ErrorStateType;

/**
* @brief              Enumeration listing errors occurred on a read or write access.
* */
typedef enum
{
    XRDC_IP_NOERR_ACCESS           = 0,
    XRDC_IP_READ_ACCESS            = 1,
    XRDC_IP_WRITE_ACCESS           = 2
} Xrdc_Ip_ErrorAccessType;

/**
* @brief              Enumeration listing error attributes of access violations.
* */
typedef enum
{
    XRDC_IP_NO_ERRATTRIBUTE        = 0,
    XRDC_IP_SECUUSER_INST          = 1,
    XRDC_IP_SECUUSER_DATA          = 2,
    XRDC_IP_SECUPRIV_INST_ACCESS   = 3,
    XRDC_IP_SECUPRIV_DATA_ACCESS   = 4,
    XRDC_IP_NONSECUUSER_INST       = 5,
    XRDC_IP_NONSECUUSER_DATA       = 6,
    XRDC_IP_NONSECUREPRIV_INST     = 7,
    XRDC_IP_NONSECUREPRIV_DATA     = 8
} Xrdc_Ip_ErrorAttributeType;
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief               Configuration structure containing XRDC memory region configuration
* */
typedef struct
{
    const uint32 u32XrdcMrcInstance;               /**< @brief Corresponding MRC instance of current memory region*/
    const uint32 u32XrdcMrcRegionDescriptor;       /**< @brief Selection of descriptor for current memory region*/
    const uint32 u32XrdcStartAddress;              /**< @brief Start address of current memory region*/
    const uint32 u32XrdcEndAddress;                /**< @brief End address of current memory region*/
    const uint32 u32XrdcSema4Enable;               /**< @brief Enable or disable Semaphore support*/
    const uint32 u32XrdcSema4Number;               /**< @brief Semaphore number used in access evaluation*/
    const uint32 u32XrdcMRGDLockBit;               /**< @brief Enable or disable MRGD bit lock*/
    const uint32 u32XrdcMemPolicy;                 /**< @brief Access policy of current memory region*/
    const uint32 u32XrdcMemPolicy1;
} Xrdc_Ip_MemConfigType;

/**
* @brief               Configuration structure containing XRDC peripheral slot configuration
* */
typedef struct
{
    const uint32 u32XrdcPdacInstance;              /**< @brief Corresponding PDAC instance of current peripheral slot*/
    const uint32 u32XrdcSema4Enable;               /**< @brief Enable or disable Semaphore support*/
    const uint32 u32XrdcSema4Number;               /**< @brief Semaphore number used in access evaluation*/
    const uint32 u32XrdcPDACLockBit;               /**< @brief Enable or disable PDAC bit lock*/
    const uint32 u32XrdcPerPolicy;                 /**< @brief Access policy of current peripheral slot*/
    const uint32 u32XrdcPerPolicy1;
} Xrdc_Ip_PeripheralConfigType;

/**
* @brief              Structure used to retrieve violation details.
* */
typedef struct
{
    uint32 u32AddError;                         /**< @brief Address of an access violation */
    uint32 u32AddErrorRemain;
    Xrdc_Ip_ErrorStateType ErrState;            /**< @brief State of access violations*/
    uint32 u32ErrPort;                          /**< @brief Port number of the MRC that detected the access violation*/
    Xrdc_Ip_ErrorAccessType ErrAccess;          /**< @brief Whether the captured access violation occurred on a read or write access*/
    Xrdc_Ip_ErrorAttributeType ErrAttribute;    /**< @brief Attributes of the access violation.*/
}Xrdc_Ip_ErrorStatusType;

/**
* @brief              Structure used to retrieve information violation details and the domain ID where violation occured.
* */
typedef struct
{
    Xrdc_Ip_DomainIDType DomainIDAccessError;                            /**< @brief Domain ID of the access violation*/
    Xrdc_Ip_ErrorStatusType ErrorStatus[XRDC_MAX_OF_ERROR_RECORDED];     /**< @brief Error status of the access violation*/
}Xrdc_Ip_DomainIDErrStatusType;

/**
* @brief               Configuration structure containing XRDC domain configuration
* */
typedef struct
{

    Xrdc_Ip_DomainIDType u32XrdcDomainID;           /**< @brief XRDC domain ID*/
    Xrdc_Ip_MDACInstanceType XrdcMdacInstance;      /**< @brief Corresponding MDA instance of current master */
    Xrdc_Ip_MasterType XrdcCoreMdacInstance;        /**< @brief Core or noncore attribute of current master*/
    /*  core_master */
    const uint32 u32XrdcProcessID;                             /**< @brief PID value of curent domain ID*/
    const uint32 u32XrdcProcessIDMask;                         /**< @brief PIDM value of current domain ID*/
    const uint32 u32XrdcProcessIDEnable;                       /**< @brief Enable or disable PID support */
    const uint32 u32XrdcThreeStateModel;                       /**< @brief If core master support three-state model or not */
    const uint32 u32XrdcWordDescriptor;                        /**< @brief Selection of descriptor for current core master*/
    /* non_core_master */
    const uint32 u32XrdcDIDBypassDisable;                      /**< @brief Enable or disable DID bypass */
    const uint32 u32XrdcMDADFMTLockBit;                        /**< @brief Enable or disable MDA_DFMT bit lock*/
    Xrdc_Ip_SecureAttributeType eXrdcSecureOutput;             /**< @brief Secure attribute of current master*/
    Xrdc_Ip_PriviledgedAttributeType eXrdcPriviledgeOutput;    /**< @brief Priviledged attribute of current master*/
} Xrdc_Ip_DomainConfigType;

/**
* @brief              IP configuration structure
* */
typedef struct
{
    const uint32 u32XrdcInstance;                                       /**< @brief XRDC instance */
    const Xrdc_Ip_DomainConfigType *pDomainConfig;                      /**< @brief Pointer to a list of configured domains*/
    const uint32 u32DomainConfigCnt;                                    /**< @brief Number of configured domains*/
    const Xrdc_Ip_MemConfigType *pMemoryDesConfig;                      /**< @brief Pointer to a list of configured memory regions*/
    const uint32 u32MemoryConfigCnt;                                    /**< @brief Number of configured memory regions*/
    const Xrdc_Ip_PeripheralConfigType *pPeripheralDescriptorConfig;    /**< @brief Pointer to a list of configured peripheral slots */
    const uint32 u32PeripheralConfigCnt;                                /**< @brief Number of configured peripheral slots*/
    const uint32 u32XrdcCRLockBit;                                      /**< @brief Enable or disable CR bit lock*/
    Xrdc_Ip_PIDLockBit XrdcPIDLockBit;                                  /**< @brief Enable or disable CR bit lock*/
} Xrdc_Ip_InstanceConfigType;

/**
* @brief              IP configuration structure
* */
typedef struct
{
    const Xrdc_Ip_InstanceConfigType * const * const pInstanceConfig;    /**< @brief Pointer to a list of configured instances */
    const uint32 u32InstanceConfigCnt;                                   /**< @brief Number of configured instances */
    const uint32 * const pInstanceInUsed;                                /**< @brief Pointer to a list of configured XRDC instances*/
    const uint32 u32InstanceInUsedCnt;                                   /**< @brief Number of configured XRDC instances*/
} Xrdc_Ip_ConfigType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XRDC_IP_TYPES_H */
