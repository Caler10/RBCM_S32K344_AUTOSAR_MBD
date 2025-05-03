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

#ifndef C40_IP_H
#define C40_IP_H

/**
 * @file       C40_Ip.h
 *
 * @defgroup   C40_IP C40 IP Driver
 * implement   C40_Ip.h_Artifact
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
#include "Mcal.h"
#include "C40_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_VENDOR_ID_H                       43
#define C40_IP_AR_RELEASE_MAJOR_VERSION_H        4
#define C40_IP_AR_RELEASE_MINOR_VERSION_H        7
#define C40_IP_AR_RELEASE_REVISION_VERSION_H     0
#define C40_IP_SW_MAJOR_VERSION_H                5
#define C40_IP_SW_MINOR_VERSION_H                0
#define C40_IP_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((C40_IP_AR_RELEASE_MAJOR_VERSION_H != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (C40_IP_AR_RELEASE_MINOR_VERSION_H != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of C40_Ip.h and Mcal.h are different"
    #endif
#endif

/* Check if current file and C40_Ip_Cfg header file are of the same vendor */
#if (C40_IP_VENDOR_ID_H != C40_IP_VENDOR_ID_CFG)
    #error "C40_Ip.h and C40_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Cfg header file are of the same Autosar version */
#if ((C40_IP_AR_RELEASE_MAJOR_VERSION_H    != C40_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_MINOR_VERSION_H    != C40_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_REVISION_VERSION_H != C40_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of C40_Ip.h and C40_Ip_Cfg.h are different"
#endif
/* Check if current file and C40_Ip_Cfg header file are of the same Software version */
#if ((C40_IP_SW_MAJOR_VERSION_H != C40_IP_SW_MAJOR_VERSION_CFG) || \
     (C40_IP_SW_MINOR_VERSION_H != C40_IP_SW_MINOR_VERSION_CFG) || \
     (C40_IP_SW_PATCH_VERSION_H != C40_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of C40_Ip.h and C40_Ip_Cfg.h are different"
#endif


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if (STD_ON == C40_IP_ENABLE_USER_MODE_SUPPORT)
/** @brief The protection size of the IP with main interface */
#if (STD_ON == C40_IP_MAIN_INTERFACE_ENABLED)
    #define C40_IP_MAIN_INTERFACE_REG_PROT_SIZE             4U
#endif
#endif /* STD_ON == C40_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

/* Base address for FLASH instance */
extern FLASH_Type * const C40_Ip_pFlashBaseAddress;

#define MEM_43_INFLS_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


#define MEM_43_INFLS_START_SEC_VAR_CLEARED_32
#include "Mem_43_INFLS_MemMap.h"

#if (STD_ON == C40_IP_TIMEOUT_SUPERVISION_ENABLED)
extern uint32 C40_Ip_u32ElapsedTicks;
extern uint32 C40_Ip_u32TimeoutTicks;
extern uint32 C40_Ip_u32CurrentTicks;
#endif

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_INFLS_MemMap.h"


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

#if (STD_ON == C40_IP_MAIN_INTERFACE_ENABLED)
/**
 * @brief    Set synch/Asynch at IP layer base on the bAsynch of HLD
 *
 * @details  This function will change C55_Ip_bAsync value at IP layer. Its param base on the bAsynch of HLD.
 *           Thanks for this param, writing and erasing will operate at synch or Asynch mode.
 *
 * @pre     The module has to be initialized
 *
 */
void C40_Ip_SetAsyncMode(const boolean Async);
#endif

#if (STD_ON == C40_IP_SECTOR_SET_LOCK_API)
/**
 * @brief        Locks the selected sector
 *
 * @details      Locks the selected sector for the requesting core if possible.
 *               This function shall cover all the address spaces available.
 *
 * @param[in]    VirtualSector     Sector to be locked.
 * @param[in]    DomainIdValue     ID for the core that requests sector lock.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS  Sector was locked successfully
 * @retval       C40_IP_STATUS_ERROR    The requested sector was locked by another core
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
C40_Ip_StatusType C40_Ip_SetLock(C40_Ip_VirtualSectorsType VirtualSector,
                                 uint8 DomainIdValue
                                );
#endif /* STD_ON == C40_IP_SECTOR_SET_LOCK_API */

/**
 * @brief        Returns the locking status of the selected sector
 *
 * @details      Returns the locking status of the selected sector.
 *               This function shall cover all the address spaces available.
 *
 * @param[in]    VirtualSector   Sector to be checked for locking.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SECTOR_UNPROTECTED   Sector was not locked
 * @retval       C40_IP_STATUS_SECTOR_PROTECTED     Sector was locked
 * @retval       C40_IP_STATUS_ERROR                The requested sector is invalid
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
C40_Ip_StatusType C40_Ip_GetLock(C40_Ip_VirtualSectorsType VirtualSector);

/**
 * @brief        Unlocks the selected sector for the requesting core if possible
 *
 * @details      Unlocks the selected sector for the requesting core if possible.
 *               This function shall cover all the address spaces available.
 *
 * @param[in]    VirtualSector     Sector to be unlocked.
 * @param[in]    DomainIdValue     ID for the core that requests sector lock
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS  Sector was unlocked successfully
 * @retval       C40_IP_STATUS_ERROR    The requested sector was unlocked by another core or the sector input is out of range
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
C40_Ip_StatusType C40_Ip_ClearLock(C40_Ip_VirtualSectorsType VirtualSector,
                                   uint8 DomainIdValue
                                  );

/**
 * @brief        Get sector number from specified address.
 *
 * @details      Get sector number from specified address.
 *
 * @param[in]    TargetAddress   target address
 *
 * @return       C40_Ip_VirtualSectorsType
 * @retval       Address of sector
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
C40_Ip_VirtualSectorsType C40_Ip_GetSectorNumberFromAddress(uint32 TargetAddress);

/**
 * @brief        Get block number from target address
 *
 * @details      Get block number from target address
 *
 * @param[in]    TargetAddress   target address
 *
 * @return       C40_Ip_GetBlockNumberFromAddress
 * @retval       The block number which contains the target address.
 *
 */
C40_Ip_FlashBlocksNumberType C40_Ip_GetBlockNumberFromAddress(uint32 TargetAddress);

/**
 * @brief        Initializes the C40 module
 *
 * @details      This function will initialize c40 module and clear all error flags.
 *
 * @param[in]    InitConfig   Pointer to the driver configuration structure.
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS          Initialization is success
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT    Errors Timeout because wait for the Done bit long time
 *
 */
C40_Ip_StatusType C40_Ip_Init(const C40_Ip_ConfigType * InitConfig);

/*!
 * @brief        Abort a program or erase operation
 *
 * @details      This function will abort a program or erase operation in user
 *               mode and clear all PGM, APGM, ERS, AERS, EHV, AEHV bits in MCR,AMCRS registers
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS         The operation is successful.
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT   the operation error because wait for the Done bit long time
 *
 */
C40_Ip_StatusType C40_Ip_Abort(void);

/**
 * @brief        This function fills data to DestAddressPtr
 *
 * @details      This function fills data to DestAddressPtr with data from the specified address
 *
 * @param[in]    LogicalAddress   The start address of the area to be read.
 * @param[in]    Length           Read size
 * @param[in]    DestAddressPtr   Pointer to the destination of the read.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS             Read performed successfully.
 * @retval       C40_IP_STATUS_ERROR_INPUT_PARAM   Input parameters are invalid.
 * @retval       C40_IP_STATUS_ERROR               There was an error while reading.
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
C40_Ip_StatusType C40_Ip_Read(uint32 LogicalAddress,
                              uint32 Length,
                              uint8 *DestAddressPtr
                             );

/**
 * @brief        Checks that there is the desired data at the specified address
 *
 * @details      Checks that there is the desired data at the specified address.
 *               If the compare is intended to be a blank check, the SourceAddressPtr should be NULL.
 *
 * @param[in]    LogicalAddress     The start address of the area to be checked.
 * @param[in]    Length             Check size
 * @param[in]    SourceAddressPtr   Pointer to the data expected to be read.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS               Read performed successfully.
 * @retval       C40_IP_STATUS_ERROR_INPUT_PARAM     Input parameters are invalid.
 * @retval       C40_IP_STATUS_ERROR                 There was an error while reading.
 * @retval       C40_IP_STATUS_ERROR_PROGRAM_VERIFY  The expected data was not found completely at the specified address
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
C40_Ip_StatusType C40_Ip_Compare(uint32 LogicalAddress,
                                 uint32 Length,
                                 const uint8 *SourceAddressPtr
                                );


#if (STD_ON == C40_IP_MAIN_INTERFACE_ENABLED)
/**
 * @brief        Checks the status of the hardware current.
 *
 * @details      Checks the status of the hardware current.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS                Program performed successfully
 * @retval       C40_IP_STATUS_BUSY                   Hardware program is still in progress
 * @retval       C40_IP_STATUS_ERROR                  There was an error during the hardware program.
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT          The program operation exceeded the timeout - Status value available only if the timeout feature is enabled.
 * @retval       C40_IP_STATUS_ERROR_PROGRAM_VERIFY   The data was not written correctly into the memory - Status available only of program verify feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
C40_Ip_StatusType C40_Ip_MainInterfaceHVJobStatus(void);

/**
 * @brief         Accepts an erase job over one of the sectors through the main interface if possible
 *
 * @details       Accepts an erase job over one of the sectors through the main interface if possible.
 *                Starts the high voltage erase and then exits. The status of the hardware erase must
 *                be verified by calling asynchronously the C40_Ip_MainInterfaceSectorEraseStatus function.
 *                The C40_Ip_MainInterfaceSectorErase function shall cover all the available sectors.
 *
 * @param[in]    VirtualSector     Sector to be erased.
 * @param[in]    DomainIdValue     ID for the core that requests sector lock
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS             Hardware erase started successfully
 * @retval       C40_IP_STATUS_ERROR_INPUT_PARAM   The selected sector is out of bound
 * @retval       C40_IP_STATUS_ERROR               There is another job configured or in progress or
 *                                                 @p The sector is locked by another core or couldn't be unlocked.
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT       The erase operation exceeded the timeout - Status value available only if the timeout feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
C40_Ip_StatusType C40_Ip_MainInterfaceSectorErase(C40_Ip_VirtualSectorsType VirtualSector,
                                                  uint8 DomainIdValue
                                                 );

/**
 * @brief         Checks the status of the hardware erase started by the C40_Ip_MainInterfaceSectorErase function.
 *
 * @details       Checks the status of the hardware erase started by the C40_Ip_MainInterfaceSectorErase function.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS             Erase performed successfully
 * @retval       C40_IP_STATUS_BUSY                Hardware erase is still in progress
 * @retval       C40_IP_STATUS_ERROR               There was an error during the hardware erase.
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT       The erase operation exceeded the timeout - Status value available only if the timeout feature is enabled.
 * @retval       C40_IP_STATUS_ERROR_BLANK_CHECK   The sector was not erased correctly - Status value available only if the blank check feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
C40_Ip_StatusType C40_Ip_MainInterfaceSectorEraseStatus(void);

/**
 * @brief        Writes data into the memory array using the main interface. Initiates the hardware write and then exits.
 *
 * @details      Writes data into the memory array using the main interface. Initiates the hardware write and then exits.
 *               The status of the hardware write must be verified by calling asynchronously the C40_Ip_MainInterfaceWriteStatus function.
 *               Up to 128 bytes can be programmed at one on a quad-page boundary.
 *               All data bytes must fall within the same quad-page. If the data crosses the quad-page boundary, the error C40_IP_STATUS_ERROR_INPUT_PARAM will be returned.
 *               Please refer to the section Program in C40 chapter in the reference manual for more information.
 *
 * @param[in]    LogicalAddress     The start address of the write, must be aligned with 8 bytes.
 * @param[in]    Length             Size in bytes of the flash region to be programed, must be aligned with 8 bytes and the maximum value is 128 bytes.
 * @param[in]    SourceAddressPtr   Source program buffer address.
 * @param[in]    DomainIdValue      ID for the core that requests sector lock.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS             Program performed successfully
 * @retval       C40_IP_STATUS_ERROR_INPUT_PARAM   The input parameters are invalid.
 * @retval       C40_IP_STATUS_ERROR               There is another job configured or in progress or
 *                                                 @p The sector is locked by another core or couldn't be unlocked.
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT       The write operation exceeded the timeout - Status value available only if the timeout feature is enabled
 * @retval       C40_IP_STATUS_ERROR_BLANK_CHECK   The sector has not been completely erased, its contents are not in erased state (available only if the erase verification feature is enabled)
 *
 * @pre          The module has to be initialized.
 *
 */
C40_Ip_StatusType C40_Ip_MainInterfaceWrite(uint32 LogicalAddress,
                                            uint32 Length,
                                            const uint8 *SourceAddressPtr,
                                            uint8 DomainIdValue
                                           );

/**
 * @brief         Checks the status of the hardware program started by the C40_IP_MainInterfaceWrite function.
 *
 * @details       Checks the status of the hardware program started by the C40_IP_MainInterfaceWrite function.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS                Program performed successfully
 * @retval       C40_IP_STATUS_BUSY                   Hardware program is still in progress
 * @retval       C40_IP_STATUS_ERROR                  There was an error during the hardware program.
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT          The program operation exceeded the timeout - Status value available only if the timeout feature is enabled.
 * @retval       C40_IP_STATUS_ERROR_PROGRAM_VERIFY   The data was not written correctly into the memory - Status available only of program verify feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
C40_Ip_StatusType C40_Ip_MainInterfaceWriteStatus(void);
#endif /* (STD_ON == C40_IP_MAIN_INTERFACE_ENABLED) */

#if (STD_ON == C40_IP_UTEST_MODE_API)
/**
 * @brief    Check the operation in user test mode
 *
 * @details  This function will check the status array integrity check
 *           in user test mode.
 *
 * @param[in]      MisrExpectedValues The MISR values calculated by the user to do comparison with MISR values generated by hardware.
 * @param[out]     TestResult The value return the state of flash.
 *
 * @return         C40_Ip_StatusType
 * @retval         C40_IP_STATUS_SUCCESS            The operation is successful
 * @retval         C40_IP_STATUS_ERROR              Operation failure status
 * @retval         C40_IP_STATUS_BUSY               In progress status
 * @retval         C40_IP_STATUS_ERROR_INPUT_PARAM  input parameters is invalid
 *
 * @pre            The module has to be initialized
 *
 */
C40_Ip_StatusType C40_Ip_CheckUserTestStatus(const C40_Ip_MisrType *MisrExpectedValues,
                                             C40_Ip_UtestStateType *TestResult
                                            );

/**
 * @brief    Check the array integrity of the flash memory
 *
 * @details  This function will check the array integrity of the flash via
 *           main interface. The user specified address sequence is used for array integrity
 *           reads and the operation is done on the specified blocks. The MISR values calculated
 *           by the hardware is compared to the values passed by the user, if they are not
 *           the same, then an error code is returned.
 *           User should call C40_Ip_CheckUserTestStatus to check the on-going status of this function.
 *           And once finish, it will do comparison between MISR values provided by user which
 *           is currently stored in 'pMisrExpectedValues' and MISR values generated by hardware
 *           and return an appropriate code according to this compared result.
 *
 * @param[in]       SelectBlock     Select the block base address for checking.
 * @param[in]       AddressSequence Determine the address sequence to be used during array integrity checks.
 * @param[in]       BreakPoints     Specify an option to allow stopping the operation on errors.
 * @param[in]       MisrSeedValues  Value to be written in the MISR registers prior to the check
 * @param[in]       DomainIdValue   ID for the core that requests program sequence.
 *
 * @return          C40_Ip_StatusTypes
 * @retval          C40_IP_STATUS_SUCCESS            The operation is successful.
 * @retval          C40_IP_STATUS_BUSY               New operation cannot be performed while previous high voltage operation in progress.
 * @retval          C40_IP_STATUS_ERROR_INPUT_PARAM  Input parameters are invalid.
 * @retval          C40_IP_STATUS_ERROR              It's impossible to enable an operation
 * @retval          C40_IP_STATUS_ERROR_TIMEOUT      Errors Timeout because wait for the Done bit long time
 *
 * @pre             The module has to be initialized
 *
 */
C40_Ip_StatusType C40_Ip_ArrayIntegrityCheck(uint32 SelectBlock,
                                             C40_Ip_ArrayIntegritySequenceType AddressSequence,
                                             C40_Ip_FlashBreakPointsType BreakPoints,
                                             const C40_Ip_MisrType *MisrSeedValues,
                                             uint8 DomainIdValue
                                            );

/**
 * @brief   Suspend an on-going array integrity check
 *
 * @details This function will check if there is an on-going array integrity
 *          check of the flash and suspend it via main interface.
 *
 * @return    C40_Ip_StatusType
 * @retval    C40_IP_STATUS_SUCCESS  array integrity check suspending was successful.
 * @retval    C40_IP_STATUS_ERROR    there is no suspended array integrity check or not successfully resumed.
 *
 * @pre       The module has to be initialized
 *
 */
C40_Ip_StatusType C40_Ip_ArrayIntegrityCheckSuspend(void);

/**
 * @brief      Resume the previous suspend operation
 *
 * @details    This function will check if there is an on-going array integrity
 *             check of the flash being suspended and resume it via main interface.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS  array integrity check resuming was successful.
 * @retval       C40_IP_STATUS_ERROR    there is no suspended array integrity check or not successfully resumed.
 *
 * @pre       The module has to be initialized
 *
 */
C40_Ip_StatusType C40_Ip_ArrayIntegrityCheckResume(void);

/**
 *
 * @brief     Check the user margin read of the flash memory
 *
 * @details   This function will check the user margin reads of the flash
 *            via main interface. The user specified margin level is used for reads and the
 *            operation is done on the specified blocks. The MISR values calculated by
 *            the hardware are compared to the values passed by the user, if they are not
 *            the same, then an error code is returned.
 *            User should call C40_Ip_CheckUserTestStatus to check the on-going status
 *            of this function. And once finish, it will do comparison between MISR values
 *            provided by user which are currently stored in 'pMisrExpectedValues,' and MISR values
 *            generated by hardware and return an appropriate code according to this compared result.
 *
 * @param[in] SelectBlock           Select the block base address for checking.
 * @param[in] BreakPoints           An option to allow stopping the operation on errors.
 * @param[in] MarginLevel           The margin level to be used during margin read checks.
 * @param[in] MisrSeedValues        Value to be written in the MISR registers prior to the check
 * @param[in] DomainIdValue         ID for the core that requests program sequence.
 *
 * @return       C40_Ip_StatusType
 * @retval       C40_IP_STATUS_SUCCESS            The operation is successful.
 * @retval       C40_IP_STATUS_BUSY               New operation cannot be performed while previous high voltage operation in progress.
 * @retval       C40_IP_STATUS_ERROR_INPUT_PARAM  Input parameters are invalid.
 * @retval       C40_IP_STATUS_ERROR              It's impossible to enable an operation
 * @retval       C40_IP_STATUS_ERROR_TIMEOUT      Errors Timeout because wait for the Done bit long time
 *
 * @pre          The module has to be initialized
 *
 */
C40_Ip_StatusType C40_Ip_UserMarginReadCheck(uint32 SelectBlock,
                                             C40_Ip_FlashBreakPointsType BreakPoints,
                                             C40_Ip_MarginOptionType MarginLevel,
                                             const C40_Ip_MisrType *MisrSeedValues,
                                             uint8 DomainIdValue
                                            );


/**
 * @brief     ECC Logic Check of the Flash.
 *
 * @details   The API will simulate single bit errors (auto correct) or double bit errors
 *
 * @param[in] AddressCheck              An address to simulate ECC Logic Check
 * @param[in] DataValue                 The 64 bits granularity of ECC Data
 * @param[in] EccValue                  ECC Check Bits. The corresponding ECC value of DataValue
 *
 * @return    C40_Ip_StatusType
 */
C40_Ip_StatusType C40_Ip_EccLogicCheck(const uint32  AddressCheck,
                                       const uint32 *DataValue,
                                       const uint8   EccValue
                                      );

/**
 * @brief     EDC after ECC Logic Check of the Flash.
 *
 * @details   The API will simulate double bit fault
 *
 * @param[in] AddressCheck              An address to simulate EDC after ECC Logic Check
 * @param[in] DataValue                 The 64 bits granularity of ECC Data
 * @param[in] EccValue                  ECC Check Bits. The corresponding ECC value of DataValue
 *
 *
 * @return    C40_Ip_StatusType
 */
C40_Ip_StatusType C40_Ip_EdcAfterEccLogicCheck(const uint32  AddressCheck,
                                               const uint32 *DataValue,
                                               const uint8   EccValue
                                               );

/**
 * @brief     Address Encode Logic Check of the Flash.
 *
 * @details   This API will test the 'Address Encode Logic Check' of the Flash in the UTest mode
 *
 * @param[in] AddressCheck              An address to simulate Address Encode Logic Check
 * @param[in] InvertBits                address bits to be inverted into the address encode compare logic (52 bits)
 *
 * @return    C40_Ip_StatusType
 */
C40_Ip_StatusType C40_Ip_AddressEncodeLogicCheck(const uint32  AddressCheck,
                                                 const uint32 *InvertBits
                                                );

#endif /* (STD_ON == C40_IP_UTEST_MODE_API) */


#if ((C40_IP_ECC_CHECK == STD_ON) || (C40_IP_ECC_CHECK_BY_AUTOSAR_OS == STD_ON))
/**
 * @brief Report Ecc UnCorrected Error for IP layer
 *
 */
void C40_Ip_ReportEccUnCorrectedError(void);
#endif

/**
 * @brief    Get the failing address in memory
 *
 * @details  This function will get the failing address in the event of ECC
 *           event error, Single Bit Correction, as well as providing the address of a
 *           failure that may have occurred in a program/erase operation.
 *
 * @return  uint32
 * @retval  Return the address is failed in the event or single bit correction.
 *
 * @pre     The module has to be initialized
 *
 */
uint32 C40_Ip_GetFailedAddress(void);


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* C40_IP_H */
