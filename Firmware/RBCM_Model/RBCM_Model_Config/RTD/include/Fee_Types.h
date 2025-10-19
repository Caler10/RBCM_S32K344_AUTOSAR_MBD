/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : none
* Dependencies         : MemAcc
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 5.0.0
* Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
* in accordance with the applicable license terms.  By expressly accepting
* such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain,
* install, activate or otherwise use the software.
*
==================================================================================================*/
#ifndef FEE_TYPES_H
#define FEE_TYPES_H

/**
*   @file
*
*   @addtogroup FEE
*   @implements Fee_Types.h_Artifact
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Features.h"
#include "MemIf_Types.h"
#include "MemAcc.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_TYPES_VENDOR_ID                    43
#define FEE_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FEE_TYPES_AR_RELEASE_MINOR_VERSION     7
#define FEE_TYPES_AR_RELEASE_REVISION_VERSION  0
#define FEE_TYPES_SW_MAJOR_VERSION             5
#define FEE_TYPES_SW_MINOR_VERSION             0
#define FEE_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemAcc header file are of the same version */
    #if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != MEMACC_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_TYPES_AR_RELEASE_MINOR_VERSION != MEMACC_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fee_Types.h and MemAcc.h are different"
    #endif
    /* Check if this file and MemIf_Types.h header file are of the same AUTOSAR version */
    #if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_TYPES_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR version numbers of Fee_Types.h and MemIf_Types.h are different"
    #endif
#endif

/* Check if this file and Fee_Features.h header file are of the same vendor */
#if (FEE_TYPES_VENDOR_ID != FEE_FEATURES_VENDOR_ID)
    #error "Fee_Types.h and Fee_Features.h have different vendor IDs"
#endif

/* Check if this file and Fee_Features.h header file are of the same AUTOSAR version */
#if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != FEE_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_TYPES_AR_RELEASE_MINOR_VERSION != FEE_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_TYPES_AR_RELEASE_REVISION_VERSION != FEE_FEATURES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR version numbers of Fee_Types.h and Fee_Features.h are different"
#endif

/* Check if this file and Fee_Features.h header file are of the same software version */
#if ((FEE_TYPES_SW_MAJOR_VERSION != FEE_FEATURES_SW_MAJOR_VERSION) || \
     (FEE_TYPES_SW_MINOR_VERSION != FEE_FEATURES_SW_MINOR_VERSION) || \
     (FEE_TYPES_SW_PATCH_VERSION != FEE_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee_Types.h and Fee_Features.h are different"
#endif

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
/**
* @brief        Fee subAddressAreas run-time status
* @api
*/
typedef struct
{
    uint32        SubAddressAreaAddr;           /**< @brief Logical address of subAddressArea on MemAcc */
    uint32        SubAddressAreaSize;           /**< @brief Size of subAddressArea in bytes */
} Fee_SubAddressAreaRuntimeInfoType;

/**
* @brief        Fee clusters run-time status
* @api
*/
typedef struct
{
    uint32                     Length;             /**< @brief Size of Fee cluster in bytes */
    uint16                     SubAddressAreaCount;        /**< @brief Number of subAddressArea in cluster */
    Fee_SubAddressAreaRuntimeInfoType *SubAddressAreaList;         /**< @brief Pointer to array of subAddressArea configurations */
} Fee_ClusterRuntimeInfoType;

#if (FEE_NUMBER_OF_SUBADDRESSAREAS_TO_RECOVER > 0U)
/**
* @brief        Fee subAddressArea to recover configuration structure
* @api
*/
typedef struct
{
    Fee_SubAddressAreaRuntimeInfoType  *SubAddressAreaToRecover;   /**< @brief Position of subAddressArea configuration */
    uint32              SubAddressAreaSize;        /**< @brief Size of subAddressArea in bytes */
} Fee_SubAddressAreaToRecoverType;
#endif

#endif /* (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON) */

/**
* @brief        Fee cluster group run-time Information
* @api
*/
typedef struct
{
    uint32           ClusterTotalSpace;    /**< @brief Total space in the selected cluster group */
    uint32           ClusterFreeSpace;     /**< @brief Free space in the selected cluster group */
    uint16           BlockHeaderOverhead; /**< @brief Block Overhead (header valid and inval flag)*/
    uint16           VirtualPageSize;     /**< @brief Fee Virtual Page Size */
    uint32           NumberOfSwap;         /**< @brief Number of cluster swap performed in the
                                                      selected cluster group */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    Fee_SubAddressAreaRuntimeInfoType *SubAddressAreaInfo; /**< @brief Pointer to the subAddressArea runtime information data structure */
#endif
} Fee_ClusterGroupRuntimeInfoType;

/**
* @brief Fee block assignment type
* @api
*/
typedef enum
{
    FEE_PROJECT_SHARED          = 0x01,     /**< block is used for all the projects */
    FEE_PROJECT_APPLICATION     = 0x02,     /**< block is used for the application project */
    FEE_PROJECT_BOOTLOADER      = 0x03,     /**< block is used for the bootloader project */
    FEE_PROJECT_RESERVED        = 0xFF      /**< the value is reserved */
} Fee_BlockAssignmentType;

/**
* @brief        Fee block configuration structure
* @api
* @implements   FeeBlockConfiguration_Object
*/
typedef struct
{
    /** @implements   FeeBlockNumber_Object */
    uint16 BlockNumber;                         /**< @brief Fee block number */

    /** @implements   FeeBlockSize_Object */
    uint16 BlockSize;                           /**< @brief Size of Fee block in bytes */
    uint8 ClrGrp;                               /**< @brief  Index of cluster group the Fee block belongs to */

    /** @implements   FeeImmediateData_Object */
    boolean ImmediateData;                      /**< @brief TRUE if immediate data block */
    Fee_BlockAssignmentType BlockAssignment;    /**< @brief specifies which project uses this block */
} Fee_BlockConfigType;

/**
* @brief Fee cluster configuration structure
* @api
*/
typedef struct
{
    uint32 StartAddr;   /**< @brief Address of Fee cluster in flash */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_OFF)
    uint32 Length;       /**< @brief Size of Fee cluster in bytes */
#endif
} Fee_ClusterType;

/**
* @brief Fee cluster group configuration structure
* @api
* @implements   Fee_ClusterGroupType_struct
*/
typedef struct
{
    const Fee_ClusterType *const ClrPtr;  /**< @brief Pointer to array of Fee cluster configurations */
    uint32 ClrCount;                      /**< @brief Number of clusters in cluster group */
    uint32 ReservedSize;          /**< @brief Size of reserved area in the given cluster group (memory occupied by immediate blocks) */
} Fee_ClusterGroupType;

/**
* @brief        Fee Configuration type is a stub type, not used, but required by ASR 4.2.2.
* @api
* @implements Fee_ConfigType_struct
*/
typedef Fee_BlockConfigType Fee_ConfigType;

/**
* @brief        Fee block header configuration structure. This consists of block number and length of block and Type of Fee block
* @api
*/
typedef struct
{
    uint16  BlockNumber;     /**< @brief Number of block */
    uint16  Length;          /**< @brief Length of block */
    boolean ImmediateBlock;  /**< @brief Type of Fee block. Set to TRUE for immediate block */
} Fee_BlockType;

/**
* @brief        Fee cluster header configuration structure.
* @api
*/
typedef struct
{
    uint32                           ClrID;              /**< @brief 32-bit cluster ID */
    uint32               StartAddr;          /**< @brief Start address of Fee cluster in MemAcc address space */
    uint32                Length;             /**< @brief Length of Fee cluster in bytes */
#if (FEE_SUBADDRESSAREA_RETIREMENT == STD_ON)
    Fee_ClusterRuntimeInfoType      *ClrInfo;            /**< @brief Pointer to the cluster runtime information */
#endif
} Fee_ClusterHeaderType;

#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 Fee_UintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 Fee_UintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* FEE_TYPES_H */
