/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef C40_IP_CFG_H
#define C40_IP_CFG_H

/**
 * @file       C40_Ip_Cfg.h
 *
 * @addtogroup C40_IP
 * implement   C40_Ip_Cfg.h_Artifact
 *
 * @{
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
#include "OsIf.h"
#include "C40_Ip_Types.h"
#include "S32K344_PFLASH.h"
#include "S32K344_FLASH.h"

#include "Devassert.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_VENDOR_ID_CFG                          43
#define C40_IP_AR_RELEASE_MAJOR_VERSION_CFG           4
#define C40_IP_AR_RELEASE_MINOR_VERSION_CFG           7
#define C40_IP_AR_RELEASE_REVISION_VERSION_CFG        0
#define C40_IP_SW_MAJOR_VERSION_CFG                   4
#define C40_IP_SW_MINOR_VERSION_CFG                   0
#define C40_IP_SW_PATCH_VERSION_CFG                   0

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (C40_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of C40_Ip_Cfg.h and OsIf.h are different"
    #endif
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (C40_IP_AR_RELEASE_MINOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of C40_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif

/* Check if current file and C40_Ip_Types header file are of the same vendor */
#if (C40_IP_VENDOR_ID_CFG != C40_IP_TYPES_VENDOR_ID_CFG)
    #error "C40_Ip_Cfg.h and C40_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Types header file are of the same Autosar version */
#if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG    != C40_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_MINOR_VERSION_CFG    != C40_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_REVISION_VERSION_CFG != C40_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of C40_Ip_Cfg.h and C40_Ip_Types.h are different"
#endif
/* Check if current file and C40_Ip_Types header file are of the same Software version */
#if ((C40_IP_SW_MAJOR_VERSION_CFG != C40_IP_TYPES_SW_MAJOR_VERSION_CFG) || \
     (C40_IP_SW_MINOR_VERSION_CFG != C40_IP_TYPES_SW_MINOR_VERSION_CFG) || \
     (C40_IP_SW_PATCH_VERSION_CFG != C40_IP_TYPES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of C40_Ip_Cfg.h and C40_Ip_Types.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*! Enable development error check */
#define C40_IP_DEV_ASSERT(x)                   DevAssert((x))

#define C40_IP_UTEST_MODE_API                  (STD_OFF)
#define C40_IP_SECTOR_SET_LOCK_API             (STD_ON)

#define C40_IP_ERASE_VERIFICATION_ENABLED      (STD_ON)
#define C40_IP_PROGRAM_VERIFICATION_ENABLED    (STD_ON)

#define C40_IP_TIMEOUT_SUPERVISION_ENABLED     (STD_OFF)
#if (STD_ON == C40_IP_TIMEOUT_SUPERVISION_ENABLED)
#define C40_IP_TIMEOUT_TYPE                    (OSIF_COUNTER_DUMMY)
#define C40_IP_ERASE_TIMEOUT                   (0U)
#define C40_IP_WRITE_TIMEOUT                   (0U)
#define C40_IP_ABORT_TIMEOUT                   (0U)
#endif  /*(STD_ON == C40_IP_TIMEOUT_SUPERVISION_ENABLED)*/

#define C40_IP_MAIN_INTERFACE_ENABLED          (STD_ON)

/* Enable Multi-Core support when using MemAcc*/
#define C40_IP_MULTICORE_ENABLED               (STD_OFF)

#define C40_IP_ENABLE_USER_MODE_SUPPORT        (STD_OFF)
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == C40_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running driver in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

/* Enable the use of cache invalidate */
#define C40_IP_SYNCRONIZE_CACHE                (STD_ON)

#define C40_IP_ECC_DATA_ERROR_SUPPRESSION      (STD_ON)

#define C40_IP_BLOCK_4_PIPE_SELECTABLE         (STD_ON)
#if (STD_ON == C40_IP_BLOCK_4_PIPE_SELECTABLE)
#define C40_IP_BLOCK4_PIPE_SELECT              (0x00U)
#endif


#define C40_IP_ERASED_VALUE_32                 (0xffffffffU)
#define C40_IP_ERASED_VALUE_16                 (C40_IP_ERASED_VALUE_32 & 0xFFFFU)
#define C40_IP_ERASED_VALUE_8                  (C40_IP_ERASED_VALUE_32 & 0xFFU)

#define C40_IP_ECC_CHECK                       (STD_ON)
#define C40_IP_ECC_CHECK_BY_AUTOSAR_OS         (STD_ON)
#if ( (C40_IP_ECC_CHECK == STD_ON) || (C40_IP_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) )
    #define C40_IP_ECC_VALUE                   (0x55155515U)
#endif


#define C40_IP_MAX_DATA_SECTOR                 (16U)
#define C40_IP_NUM_OF_SECTOR_PER_BLOCK         (128U)
#define C40_IP_NUM_OF_SUPPER_SECTOR_PER_BLOCK  (12U)

/* Code block 0 addresses */
#define C40_IP_CODE_BLOCK_0_BASE_ADDR          (0x00400000U)
#define C40_IP_CODE_BLOCK_0_END_ADDR           (0x004FFFFFU)

/* Code block 1 addresses */
#define C40_IP_CODE_BLOCK_1_BASE_ADDR          (0x00500000U)
#define C40_IP_CODE_BLOCK_1_END_ADDR           (0x005FFFFFU)

/* Code block 2 addresses */
#define C40_IP_CODE_BLOCK_2_BASE_ADDR          (0x00600000U)
#define C40_IP_CODE_BLOCK_2_END_ADDR           (0x006FFFFFU)

/* Code block 3 addresses */
#define C40_IP_CODE_BLOCK_3_BASE_ADDR          (0x00700000U)
#define C40_IP_CODE_BLOCK_3_END_ADDR           (0x007FFFFFU)

/* Data block addresses */
#define C40_IP_DATA_BLOCK_BASE_ADDR            (0x10000000U)
#define C40_IP_DATA_BLOCK_END_ADDR             (0x1001FFFFU)

/* Utest block addresses */
#define C40_IP_UTEST_BLOCK_BASE_ADDR           (0x1B000000U)
#define C40_IP_UTEST_BLOCK_END_ADDR            (0x1B001FFFU)

/* Memory flash sector characteristics */
#define C40_IP_MAX_VIRTUAL_SECTOR              (527U)

#define C40_IP_CODE_BLOCK_SIZE                 (0x400000U)
#define C40_IP_CODE_BLOCK_END_ADDR             (C40_IP_CODE_BLOCK_0_BASE_ADDR + C40_IP_CODE_BLOCK_SIZE - 1U)

/* Failing address based on the flash memory addressing scheme */
#define C40_IP_REGION_0_ADDR                   (C40_IP_CODE_BLOCK_0_BASE_ADDR)
#define C40_IP_REGION_1_ADDR                   (C40_IP_CODE_BLOCK_1_BASE_ADDR)
#define C40_IP_REGION_2_ADDR                   (C40_IP_CODE_BLOCK_2_BASE_ADDR)
#define C40_IP_REGION_3_ADDR                   (C40_IP_CODE_BLOCK_3_BASE_ADDR)
#define C40_IP_REGION_4_ADDR                   (C40_IP_DATA_BLOCK_BASE_ADDR)
#define C40_IP_REGION_5_ADDR                   (C40_IP_INVALID_ADDR)

#define C40_IP_INVALID_ADDR                    (0xFFFFFFFFU)


/** @brief  PFlash register base address of PFlash */
#define PFLASH_BASEADDR                             (IP_PFLASH_BASE)
#define PFLASH_PFCBLK_DATA_ORDER                    (PFLASH_PFCBLKI_SPELOCK_COUNT - 1U)

/** @brief  Order of data flash PFCBLK Registers Arrays */
#define PFLASH_PFCBLK_DATA_LOCKMASTER_S0_ADDR32     ((uint32)&(IP_PFLASH->PFCBLK_LOCKMASTER_S[PFLASH_PFCBLKI_LOCKMASTER_S_COUNT - 1U][0U]))
/** @brief  Block a Lock Master Sector */
#define PFLASH_PFCBLK0_LOCKMASTER_S0_ADDR32         ((uint32)&(IP_PFLASH->PFCBLK_LOCKMASTER_S[0U][0U]))
/** @brief   Block UTEST Lock Master Sector */
#define PFLASH_PFCBLKU_LOCKMASTER_S_ADDR32          ((uint32)&(IP_PFLASH->PFCBLKU_LOCKMASTER_S[0U]))
/** @brief   Block a Lock Master Super Sector */
#define PFLASH_PFCBLK0_LOCKMASTER_SS0_ADDR32        ((uint32)(PFLASH_BASEADDR + (uint32)0x484UL))

/*==================================================================================================
                                 ENUM TYPEDEFS
==================================================================================================*/

typedef uint32 C40_Ip_VirtualSectorsType;

/**
    For flash area : Code flash : Start 0040_0000h -> 0x007F_E000h and Data Flash: 1000_0000h -> 1003_FFFFh and Utest Flash :  1B00_0000h -> 1B00_1FFFh
*/
#define C40_DATA_ARRAY_0_BLOCK_4_S000       (0U)    /* 0x10000000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S001       (1U)    /* 0x10002000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S002       (2U)    /* 0x10004000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S003       (3U)    /* 0x10006000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S004       (4U)    /* 0x10008000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S005       (5U)    /* 0x1000A000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S006       (6U)    /* 0x1000C000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S007       (7U)    /* 0x1000E000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S008       (8U)    /* 0x10010000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S009       (9U)    /* 0x10012000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S010       (10U)    /* 0x10014000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S011       (11U)    /* 0x10016000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S012       (12U)    /* 0x10018000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S013       (13U)    /* 0x1001A000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S014       (14U)    /* 0x1001C000 */
#define C40_DATA_ARRAY_0_BLOCK_4_S015       (15U)    /* 0x1001E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S000       (16U)    /* 0x00400000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S001       (17U)    /* 0x00402000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S002       (18U)    /* 0x00404000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S003       (19U)    /* 0x00406000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S004       (20U)    /* 0x00408000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S005       (21U)    /* 0x0040A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S006       (22U)    /* 0x0040C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S007       (23U)    /* 0x0040E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S008       (24U)    /* 0x00410000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S009       (25U)    /* 0x00412000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S010       (26U)    /* 0x00414000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S011       (27U)    /* 0x00416000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S012       (28U)    /* 0x00418000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S013       (29U)    /* 0x0041A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S014       (30U)    /* 0x0041C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S015       (31U)    /* 0x0041E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S016       (32U)    /* 0x00420000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S017       (33U)    /* 0x00422000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S018       (34U)    /* 0x00424000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S019       (35U)    /* 0x00426000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S020       (36U)    /* 0x00428000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S021       (37U)    /* 0x0042A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S022       (38U)    /* 0x0042C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S023       (39U)    /* 0x0042E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S024       (40U)    /* 0x00430000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S025       (41U)    /* 0x00432000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S026       (42U)    /* 0x00434000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S027       (43U)    /* 0x00436000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S028       (44U)    /* 0x00438000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S029       (45U)    /* 0x0043A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S030       (46U)    /* 0x0043C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S031       (47U)    /* 0x0043E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S032       (48U)    /* 0x00440000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S033       (49U)    /* 0x00442000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S034       (50U)    /* 0x00444000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S035       (51U)    /* 0x00446000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S036       (52U)    /* 0x00448000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S037       (53U)    /* 0x0044A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S038       (54U)    /* 0x0044C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S039       (55U)    /* 0x0044E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S040       (56U)    /* 0x00450000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S041       (57U)    /* 0x00452000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S042       (58U)    /* 0x00454000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S043       (59U)    /* 0x00456000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S044       (60U)    /* 0x00458000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S045       (61U)    /* 0x0045A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S046       (62U)    /* 0x0045C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S047       (63U)    /* 0x0045E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S048       (64U)    /* 0x00460000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S049       (65U)    /* 0x00462000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S050       (66U)    /* 0x00464000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S051       (67U)    /* 0x00466000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S052       (68U)    /* 0x00468000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S053       (69U)    /* 0x0046A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S054       (70U)    /* 0x0046C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S055       (71U)    /* 0x0046E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S056       (72U)    /* 0x00470000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S057       (73U)    /* 0x00472000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S058       (74U)    /* 0x00474000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S059       (75U)    /* 0x00476000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S060       (76U)    /* 0x00478000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S061       (77U)    /* 0x0047A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S062       (78U)    /* 0x0047C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S063       (79U)    /* 0x0047E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S064       (80U)    /* 0x00480000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S065       (81U)    /* 0x00482000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S066       (82U)    /* 0x00484000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S067       (83U)    /* 0x00486000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S068       (84U)    /* 0x00488000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S069       (85U)    /* 0x0048A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S070       (86U)    /* 0x0048C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S071       (87U)    /* 0x0048E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S072       (88U)    /* 0x00490000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S073       (89U)    /* 0x00492000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S074       (90U)    /* 0x00494000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S075       (91U)    /* 0x00496000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S076       (92U)    /* 0x00498000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S077       (93U)    /* 0x0049A000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S078       (94U)    /* 0x0049C000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S079       (95U)    /* 0x0049E000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S080       (96U)    /* 0x004A0000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S081       (97U)    /* 0x004A2000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S082       (98U)    /* 0x004A4000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S083       (99U)    /* 0x004A6000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S084       (100U)    /* 0x004A8000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S085       (101U)    /* 0x004AA000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S086       (102U)    /* 0x004AC000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S087       (103U)    /* 0x004AE000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S088       (104U)    /* 0x004B0000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S089       (105U)    /* 0x004B2000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S090       (106U)    /* 0x004B4000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S091       (107U)    /* 0x004B6000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S092       (108U)    /* 0x004B8000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S093       (109U)    /* 0x004BA000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S094       (110U)    /* 0x004BC000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S095       (111U)    /* 0x004BE000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S096       (112U)    /* 0x004C0000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S097       (113U)    /* 0x004C2000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S098       (114U)    /* 0x004C4000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S099       (115U)    /* 0x004C6000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S100       (116U)    /* 0x004C8000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S101       (117U)    /* 0x004CA000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S102       (118U)    /* 0x004CC000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S103       (119U)    /* 0x004CE000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S104       (120U)    /* 0x004D0000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S105       (121U)    /* 0x004D2000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S106       (122U)    /* 0x004D4000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S107       (123U)    /* 0x004D6000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S108       (124U)    /* 0x004D8000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S109       (125U)    /* 0x004DA000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S110       (126U)    /* 0x004DC000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S111       (127U)    /* 0x004DE000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S112       (128U)    /* 0x004E0000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S113       (129U)    /* 0x004E2000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S114       (130U)    /* 0x004E4000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S115       (131U)    /* 0x004E6000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S116       (132U)    /* 0x004E8000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S117       (133U)    /* 0x004EA000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S118       (134U)    /* 0x004EC000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S119       (135U)    /* 0x004EE000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S120       (136U)    /* 0x004F0000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S121       (137U)    /* 0x004F2000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S122       (138U)    /* 0x004F4000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S123       (139U)    /* 0x004F6000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S124       (140U)    /* 0x004F8000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S125       (141U)    /* 0x004FA000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S126       (142U)    /* 0x004FC000 */
#define C40_CODE_ARRAY_0_BLOCK_0_S127       (143U)    /* 0x004FE000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S128       (144U)    /* 0x00500000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S129       (145U)    /* 0x00502000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S130       (146U)    /* 0x00504000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S131       (147U)    /* 0x00506000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S132       (148U)    /* 0x00508000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S133       (149U)    /* 0x0050A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S134       (150U)    /* 0x0050C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S135       (151U)    /* 0x0050E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S136       (152U)    /* 0x00510000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S137       (153U)    /* 0x00512000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S138       (154U)    /* 0x00514000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S139       (155U)    /* 0x00516000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S140       (156U)    /* 0x00518000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S141       (157U)    /* 0x0051A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S142       (158U)    /* 0x0051C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S143       (159U)    /* 0x0051E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S144       (160U)    /* 0x00520000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S145       (161U)    /* 0x00522000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S146       (162U)    /* 0x00524000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S147       (163U)    /* 0x00526000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S148       (164U)    /* 0x00528000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S149       (165U)    /* 0x0052A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S150       (166U)    /* 0x0052C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S151       (167U)    /* 0x0052E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S152       (168U)    /* 0x00530000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S153       (169U)    /* 0x00532000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S154       (170U)    /* 0x00534000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S155       (171U)    /* 0x00536000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S156       (172U)    /* 0x00538000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S157       (173U)    /* 0x0053A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S158       (174U)    /* 0x0053C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S159       (175U)    /* 0x0053E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S160       (176U)    /* 0x00540000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S161       (177U)    /* 0x00542000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S162       (178U)    /* 0x00544000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S163       (179U)    /* 0x00546000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S164       (180U)    /* 0x00548000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S165       (181U)    /* 0x0054A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S166       (182U)    /* 0x0054C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S167       (183U)    /* 0x0054E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S168       (184U)    /* 0x00550000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S169       (185U)    /* 0x00552000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S170       (186U)    /* 0x00554000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S171       (187U)    /* 0x00556000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S172       (188U)    /* 0x00558000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S173       (189U)    /* 0x0055A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S174       (190U)    /* 0x0055C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S175       (191U)    /* 0x0055E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S176       (192U)    /* 0x00560000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S177       (193U)    /* 0x00562000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S178       (194U)    /* 0x00564000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S179       (195U)    /* 0x00566000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S180       (196U)    /* 0x00568000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S181       (197U)    /* 0x0056A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S182       (198U)    /* 0x0056C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S183       (199U)    /* 0x0056E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S184       (200U)    /* 0x00570000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S185       (201U)    /* 0x00572000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S186       (202U)    /* 0x00574000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S187       (203U)    /* 0x00576000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S188       (204U)    /* 0x00578000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S189       (205U)    /* 0x0057A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S190       (206U)    /* 0x0057C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S191       (207U)    /* 0x0057E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S192       (208U)    /* 0x00580000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S193       (209U)    /* 0x00582000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S194       (210U)    /* 0x00584000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S195       (211U)    /* 0x00586000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S196       (212U)    /* 0x00588000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S197       (213U)    /* 0x0058A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S198       (214U)    /* 0x0058C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S199       (215U)    /* 0x0058E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S200       (216U)    /* 0x00590000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S201       (217U)    /* 0x00592000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S202       (218U)    /* 0x00594000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S203       (219U)    /* 0x00596000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S204       (220U)    /* 0x00598000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S205       (221U)    /* 0x0059A000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S206       (222U)    /* 0x0059C000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S207       (223U)    /* 0x0059E000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S208       (224U)    /* 0x005A0000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S209       (225U)    /* 0x005A2000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S210       (226U)    /* 0x005A4000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S211       (227U)    /* 0x005A6000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S212       (228U)    /* 0x005A8000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S213       (229U)    /* 0x005AA000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S214       (230U)    /* 0x005AC000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S215       (231U)    /* 0x005AE000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S216       (232U)    /* 0x005B0000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S217       (233U)    /* 0x005B2000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S218       (234U)    /* 0x005B4000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S219       (235U)    /* 0x005B6000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S220       (236U)    /* 0x005B8000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S221       (237U)    /* 0x005BA000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S222       (238U)    /* 0x005BC000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S223       (239U)    /* 0x005BE000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S224       (240U)    /* 0x005C0000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S225       (241U)    /* 0x005C2000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S226       (242U)    /* 0x005C4000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S227       (243U)    /* 0x005C6000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S228       (244U)    /* 0x005C8000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S229       (245U)    /* 0x005CA000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S230       (246U)    /* 0x005CC000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S231       (247U)    /* 0x005CE000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S232       (248U)    /* 0x005D0000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S233       (249U)    /* 0x005D2000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S234       (250U)    /* 0x005D4000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S235       (251U)    /* 0x005D6000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S236       (252U)    /* 0x005D8000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S237       (253U)    /* 0x005DA000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S238       (254U)    /* 0x005DC000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S239       (255U)    /* 0x005DE000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S240       (256U)    /* 0x005E0000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S241       (257U)    /* 0x005E2000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S242       (258U)    /* 0x005E4000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S243       (259U)    /* 0x005E6000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S244       (260U)    /* 0x005E8000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S245       (261U)    /* 0x005EA000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S246       (262U)    /* 0x005EC000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S247       (263U)    /* 0x005EE000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S248       (264U)    /* 0x005F0000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S249       (265U)    /* 0x005F2000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S250       (266U)    /* 0x005F4000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S251       (267U)    /* 0x005F6000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S252       (268U)    /* 0x005F8000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S253       (269U)    /* 0x005FA000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S254       (270U)    /* 0x005FC000 */
#define C40_CODE_ARRAY_0_BLOCK_1_S255       (271U)    /* 0x005FE000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S256       (272U)    /* 0x00600000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S257       (273U)    /* 0x00602000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S258       (274U)    /* 0x00604000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S259       (275U)    /* 0x00606000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S260       (276U)    /* 0x00608000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S261       (277U)    /* 0x0060A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S262       (278U)    /* 0x0060C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S263       (279U)    /* 0x0060E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S264       (280U)    /* 0x00610000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S265       (281U)    /* 0x00612000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S266       (282U)    /* 0x00614000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S267       (283U)    /* 0x00616000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S268       (284U)    /* 0x00618000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S269       (285U)    /* 0x0061A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S270       (286U)    /* 0x0061C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S271       (287U)    /* 0x0061E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S272       (288U)    /* 0x00620000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S273       (289U)    /* 0x00622000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S274       (290U)    /* 0x00624000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S275       (291U)    /* 0x00626000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S276       (292U)    /* 0x00628000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S277       (293U)    /* 0x0062A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S278       (294U)    /* 0x0062C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S279       (295U)    /* 0x0062E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S280       (296U)    /* 0x00630000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S281       (297U)    /* 0x00632000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S282       (298U)    /* 0x00634000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S283       (299U)    /* 0x00636000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S284       (300U)    /* 0x00638000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S285       (301U)    /* 0x0063A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S286       (302U)    /* 0x0063C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S287       (303U)    /* 0x0063E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S288       (304U)    /* 0x00640000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S289       (305U)    /* 0x00642000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S290       (306U)    /* 0x00644000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S291       (307U)    /* 0x00646000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S292       (308U)    /* 0x00648000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S293       (309U)    /* 0x0064A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S294       (310U)    /* 0x0064C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S295       (311U)    /* 0x0064E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S296       (312U)    /* 0x00650000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S297       (313U)    /* 0x00652000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S298       (314U)    /* 0x00654000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S299       (315U)    /* 0x00656000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S300       (316U)    /* 0x00658000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S301       (317U)    /* 0x0065A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S302       (318U)    /* 0x0065C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S303       (319U)    /* 0x0065E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S304       (320U)    /* 0x00660000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S305       (321U)    /* 0x00662000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S306       (322U)    /* 0x00664000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S307       (323U)    /* 0x00666000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S308       (324U)    /* 0x00668000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S309       (325U)    /* 0x0066A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S310       (326U)    /* 0x0066C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S311       (327U)    /* 0x0066E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S312       (328U)    /* 0x00670000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S313       (329U)    /* 0x00672000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S314       (330U)    /* 0x00674000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S315       (331U)    /* 0x00676000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S316       (332U)    /* 0x00678000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S317       (333U)    /* 0x0067A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S318       (334U)    /* 0x0067C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S319       (335U)    /* 0x0067E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S320       (336U)    /* 0x00680000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S321       (337U)    /* 0x00682000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S322       (338U)    /* 0x00684000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S323       (339U)    /* 0x00686000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S324       (340U)    /* 0x00688000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S325       (341U)    /* 0x0068A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S326       (342U)    /* 0x0068C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S327       (343U)    /* 0x0068E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S328       (344U)    /* 0x00690000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S329       (345U)    /* 0x00692000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S330       (346U)    /* 0x00694000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S331       (347U)    /* 0x00696000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S332       (348U)    /* 0x00698000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S333       (349U)    /* 0x0069A000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S334       (350U)    /* 0x0069C000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S335       (351U)    /* 0x0069E000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S336       (352U)    /* 0x006A0000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S337       (353U)    /* 0x006A2000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S338       (354U)    /* 0x006A4000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S339       (355U)    /* 0x006A6000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S340       (356U)    /* 0x006A8000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S341       (357U)    /* 0x006AA000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S342       (358U)    /* 0x006AC000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S343       (359U)    /* 0x006AE000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S344       (360U)    /* 0x006B0000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S345       (361U)    /* 0x006B2000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S346       (362U)    /* 0x006B4000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S347       (363U)    /* 0x006B6000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S348       (364U)    /* 0x006B8000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S349       (365U)    /* 0x006BA000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S350       (366U)    /* 0x006BC000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S351       (367U)    /* 0x006BE000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S352       (368U)    /* 0x006C0000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S353       (369U)    /* 0x006C2000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S354       (370U)    /* 0x006C4000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S355       (371U)    /* 0x006C6000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S356       (372U)    /* 0x006C8000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S357       (373U)    /* 0x006CA000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S358       (374U)    /* 0x006CC000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S359       (375U)    /* 0x006CE000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S360       (376U)    /* 0x006D0000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S361       (377U)    /* 0x006D2000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S362       (378U)    /* 0x006D4000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S363       (379U)    /* 0x006D6000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S364       (380U)    /* 0x006D8000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S365       (381U)    /* 0x006DA000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S366       (382U)    /* 0x006DC000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S367       (383U)    /* 0x006DE000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S368       (384U)    /* 0x006E0000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S369       (385U)    /* 0x006E2000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S370       (386U)    /* 0x006E4000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S371       (387U)    /* 0x006E6000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S372       (388U)    /* 0x006E8000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S373       (389U)    /* 0x006EA000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S374       (390U)    /* 0x006EC000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S375       (391U)    /* 0x006EE000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S376       (392U)    /* 0x006F0000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S377       (393U)    /* 0x006F2000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S378       (394U)    /* 0x006F4000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S379       (395U)    /* 0x006F6000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S380       (396U)    /* 0x006F8000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S381       (397U)    /* 0x006FA000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S382       (398U)    /* 0x006FC000 */
#define C40_CODE_ARRAY_0_BLOCK_2_S383       (399U)    /* 0x006FE000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S384       (400U)    /* 0x00700000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S385       (401U)    /* 0x00702000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S386       (402U)    /* 0x00704000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S387       (403U)    /* 0x00706000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S388       (404U)    /* 0x00708000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S389       (405U)    /* 0x0070A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S390       (406U)    /* 0x0070C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S391       (407U)    /* 0x0070E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S392       (408U)    /* 0x00710000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S393       (409U)    /* 0x00712000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S394       (410U)    /* 0x00714000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S395       (411U)    /* 0x00716000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S396       (412U)    /* 0x00718000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S397       (413U)    /* 0x0071A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S398       (414U)    /* 0x0071C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S399       (415U)    /* 0x0071E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S400       (416U)    /* 0x00720000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S401       (417U)    /* 0x00722000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S402       (418U)    /* 0x00724000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S403       (419U)    /* 0x00726000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S404       (420U)    /* 0x00728000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S405       (421U)    /* 0x0072A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S406       (422U)    /* 0x0072C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S407       (423U)    /* 0x0072E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S408       (424U)    /* 0x00730000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S409       (425U)    /* 0x00732000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S410       (426U)    /* 0x00734000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S411       (427U)    /* 0x00736000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S412       (428U)    /* 0x00738000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S413       (429U)    /* 0x0073A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S414       (430U)    /* 0x0073C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S415       (431U)    /* 0x0073E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S416       (432U)    /* 0x00740000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S417       (433U)    /* 0x00742000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S418       (434U)    /* 0x00744000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S419       (435U)    /* 0x00746000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S420       (436U)    /* 0x00748000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S421       (437U)    /* 0x0074A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S422       (438U)    /* 0x0074C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S423       (439U)    /* 0x0074E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S424       (440U)    /* 0x00750000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S425       (441U)    /* 0x00752000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S426       (442U)    /* 0x00754000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S427       (443U)    /* 0x00756000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S428       (444U)    /* 0x00758000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S429       (445U)    /* 0x0075A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S430       (446U)    /* 0x0075C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S431       (447U)    /* 0x0075E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S432       (448U)    /* 0x00760000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S433       (449U)    /* 0x00762000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S434       (450U)    /* 0x00764000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S435       (451U)    /* 0x00766000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S436       (452U)    /* 0x00768000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S437       (453U)    /* 0x0076A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S438       (454U)    /* 0x0076C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S439       (455U)    /* 0x0076E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S440       (456U)    /* 0x00770000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S441       (457U)    /* 0x00772000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S442       (458U)    /* 0x00774000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S443       (459U)    /* 0x00776000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S444       (460U)    /* 0x00778000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S445       (461U)    /* 0x0077A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S446       (462U)    /* 0x0077C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S447       (463U)    /* 0x0077E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S448       (464U)    /* 0x00780000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S449       (465U)    /* 0x00782000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S450       (466U)    /* 0x00784000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S451       (467U)    /* 0x00786000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S452       (468U)    /* 0x00788000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S453       (469U)    /* 0x0078A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S454       (470U)    /* 0x0078C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S455       (471U)    /* 0x0078E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S456       (472U)    /* 0x00790000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S457       (473U)    /* 0x00792000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S458       (474U)    /* 0x00794000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S459       (475U)    /* 0x00796000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S460       (476U)    /* 0x00798000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S461       (477U)    /* 0x0079A000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S462       (478U)    /* 0x0079C000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S463       (479U)    /* 0x0079E000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S464       (480U)    /* 0x007A0000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S465       (481U)    /* 0x007A2000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S466       (482U)    /* 0x007A4000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S467       (483U)    /* 0x007A6000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S468       (484U)    /* 0x007A8000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S469       (485U)    /* 0x007AA000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S470       (486U)    /* 0x007AC000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S471       (487U)    /* 0x007AE000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S472       (488U)    /* 0x007B0000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S473       (489U)    /* 0x007B2000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S474       (490U)    /* 0x007B4000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S475       (491U)    /* 0x007B6000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S476       (492U)    /* 0x007B8000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S477       (493U)    /* 0x007BA000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S478       (494U)    /* 0x007BC000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S479       (495U)    /* 0x007BE000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S480       (496U)    /* 0x007C0000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S481       (497U)    /* 0x007C2000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S482       (498U)    /* 0x007C4000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S483       (499U)    /* 0x007C6000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S484       (500U)    /* 0x007C8000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S485       (501U)    /* 0x007CA000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S486       (502U)    /* 0x007CC000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S487       (503U)    /* 0x007CE000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S488       (504U)    /* 0x007D0000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S489       (505U)    /* 0x007D2000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S490       (506U)    /* 0x007D4000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S491       (507U)    /* 0x007D6000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S492       (508U)    /* 0x007D8000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S493       (509U)    /* 0x007DA000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S494       (510U)    /* 0x007DC000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S495       (511U)    /* 0x007DE000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S496       (512U)    /* 0x007E0000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S497       (513U)    /* 0x007E2000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S498       (514U)    /* 0x007E4000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S499       (515U)    /* 0x007E6000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S500       (516U)    /* 0x007E8000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S501       (517U)    /* 0x007EA000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S502       (518U)    /* 0x007EC000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S503       (519U)    /* 0x007EE000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S504       (520U)    /* 0x007F0000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S505       (521U)    /* 0x007F2000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S506       (522U)    /* 0x007F4000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S507       (523U)    /* 0x007F6000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S508       (524U)    /* 0x007F8000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S509       (525U)    /* 0x007FA000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S510       (526U)    /* 0x007FC000 */
#define C40_CODE_ARRAY_0_BLOCK_3_S511       (527U)    /* 0x007FE000 */
#define C40_UTEST_ARRAY_0_S000              (528U)    /* 0x1B000000 */
#define C40_IP_SECTOR_ERROR                 (529U)    /* default and error return value */


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

extern const C40_Ip_ConfigType C40_Ip_InitCfg;

#define MEM_43_INFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* C40_IP_CFG_H */

