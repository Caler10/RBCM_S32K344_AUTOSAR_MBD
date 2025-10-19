/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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

#ifndef C40_IP_TRUSTEDFUNCTIONS_H
#define C40_IP_TRUSTEDFUNCTIONS_H

/**
 * @file       C40_Ip_TrustedFunctions.h
 *
 * @addtogroup C40_IP
 * implement   C40_Ip_TrustedFunctions.h_Artifact
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
#include "C40_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define C40_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define C40_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define C40_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define C40_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                5
#define C40_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define C40_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and C40_Ip_Cfg header file are of the same vendor */
#if (C40_IP_VENDOR_ID_CFG != C40_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "C40_Ip_TrustedFunctions.h and C40_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Cfg header file are of the same Autosar version */
#if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG    != C40_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (C40_IP_AR_RELEASE_MINOR_VERSION_CFG    != C40_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (C40_IP_AR_RELEASE_REVISION_VERSION_CFG != C40_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of C40_Ip_TrustedFunctions.h and C40_Ip_Cfg.h are different"
#endif
/* Check if current file and C40_Ip_Cfg header file are of the same Software version */
#if ((C40_IP_SW_MAJOR_VERSION_CFG != C40_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (C40_IP_SW_MINOR_VERSION_CFG != C40_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (C40_IP_SW_PATCH_VERSION_CFG != C40_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of C40_Ip_TrustedFunctions.h and C40_Ip_Cfg.h are different"
#endif


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#if (STD_ON == C40_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief        Enable user mode support to access c40asf and PFLASH registers
*
* @details      Set UAA bit in FLASH_REG_PROT_GCR to allow user access locked registers in c40asf and PFLASH module
*
* @param        none
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void C40_Ip_SetUserAccessAllowed(void);
#endif


#if (STD_ON == C40_IP_BLOCK_4_PIPE_SELECTABLE)
/**
 * @brief        Selects the active pipe for flash memory block 4 access
 *
 * @param        none
 * @return       none
 *
 */
extern void C40_Ip_Block4PipeSelect(void);
#endif


/**
 * @brief        Setup the ECC error handling on data flash block
 *
 * @param        none
 * @return       none
 *
 */
extern void C40_Ip_EccDataErrorSuppression(void);


#if ((C40_IP_ECC_CHECK == STD_ON) || (C40_IP_ECC_CHECK_BY_AUTOSAR_OS == STD_ON))
/**
 * @brief        Read DERR_SUP bit to get the data error suppression status
 *
 * @param        none
 * @return       uint32    The bit mask value of the data error suppression status
 *
 */
extern uint32 C40_Ip_GetPflashDataErrorSuppressionStatus(void);
#endif


#if (STD_ON == C40_IP_MAIN_INTERFACE_ENABLED)
/**
 * @brief        Write the program erase address using logical address registers located in the Platform Flash Controller
 *
 * @param[in]    Address   The logical address to be written or erased
 * @return       none
 *
 */
extern void C40_Ip_MainInterfaceWriteLogicalAddress(uint32 Address);
#endif


/**
 * @brief        Read lock bit status of flash sectors
 *
 * @param[in]    VirtualSector   Sector to be checked
 * @return       uint32              Lock bit status value
 *
 */
extern uint32 C40_Ip_GetLockProtect(C40_Ip_VirtualSectorsType VirtualSector);


/**
 * @brief        Locks the selected sector for the requesting core
 *
 * @param[in]    VirtualSector   Sector to be locked
 * @return       none
 *
 */
extern void C40_Ip_SetLockProtect(C40_Ip_VirtualSectorsType VirtualSector);


/**
 * @brief        Unlocks the selected sector for the requesting core
 *
 * @param[in]    VirtualSector   Sector to be unlocked
 * @retval       none
 *
 */
extern void C40_Ip_ClearLockProtect(C40_Ip_VirtualSectorsType VirtualSector);


/**
 * @brief        Read and check the lock domain ID for flash sectors
 *
 * @param[in]    VirtualSector            Sector to be checked
 * @param[inout] CheckRegister            Lock status value of the sector
 * @param[inout] TempLockMasterRegister   The address of the register that contain domain ID
 *                                        of the master currently acquiring the lock bit.
 * @return       none
 *
 */
extern void C40_Ip_CheckLockDomainID_CheckRegister(C40_Ip_VirtualSectorsType VirtualSector,
                                            uint32 *CheckRegister,
                                            uint32 *TempLockMasterRegister
                                           );


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* C40_IP_TRUSTEDFUNCTIONS_H */
