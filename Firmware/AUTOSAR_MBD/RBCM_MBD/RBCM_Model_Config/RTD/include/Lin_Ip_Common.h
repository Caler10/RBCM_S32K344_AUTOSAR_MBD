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

#ifndef LIN_IP_COMMON_H
#define LIN_IP_COMMON_H

/**
*   @file
*
*   @internal
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_IP_COMMON_VENDOR_ID                    43
#define LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION     4
#define LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION     7
#define LIN_IP_COMMON_AR_RELEASE_REVISION_VERSION  0
#define LIN_IP_COMMON_SW_MAJOR_VERSION             5
#define LIN_IP_COMMON_SW_MINOR_VERSION             0
#define LIN_IP_COMMON_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Ip_Common.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Mask of Id field
*/
#define LIN_IP_ID_MASK_U8      ((uint8)(0x3FU))
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief Enum containing parity type actions
 *
 * @details This enum defines types for an enumerating parity type actions.
 *
 * @implements Lin_Ip_ParityActionType_enum
 *
 *
 */
typedef enum
{
    LIN_IP_CHECK_PARITY = 0x00U, /*!< Checking parity action */
    LIN_IP_MAKE_PARITY = 0x01U, /*!< Computing parity action */
} Lin_Ip_ParityActionType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/**
 * @brief Makes or checks parity bits.
 *
 * @details This function shall compute or check the parity bits. If action is checking parity, the function
 * returns ID value if parity bits are correct or 0xFF if parity bits are incorrect. If action
 * is making parity bits, then from input value of ID, the function returns PID.
 * This is not a public API as it is called by other API functions.
 *
 * @param[in] PID PID byte in case of checking parity bits or ID byte in case of making parity bits.
 * @param[in] typeAction: 1 for Checking parity bits, 0 for making parity bits
 *
 * @return uint8 - Value has 8 bit:
 * @retval 0xFF : Parity bits are incorrect,
 * @retval ID   : Checking parity bits are correct.
 * @retval PID  : typeAction is making parity bits.
 *
 *
 */
uint8 Lin_Ip_ProcessParity(const uint8 Pid, const Lin_Ip_ParityActionType TypeAction);

/**
 * @brief Makes the checksum byte for a frame.
 *
 * @details This function shall compute the checksum byte for a frame. For PID of identifiers,
 * if PID is 0x3C (ID 0x3C) or 0x7D (ID 0x3D) or 0xFE (ID 0x3E) or 0xBF (ID 0x3F)
 * apply classic checksum and apply enhanced checksum for other PID.
 * In case user want to calculate classic checksum please set PID to zero.
 *
 * @param[in] buffer Pointer to Tx buffer
 * @param[in] sizeBuffer Number of bytes that are contained in the buffer.
 * @param[in] PID Protected Identifier byte.
 *
 * @return uint8 - The checksum byte.
 *
 *
 */
uint8 Lin_Ip_MakeChecksumByte(const uint8 *BufferPtr, const uint8 SizeBuffer, const uint8 Pid);

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_IP_COMMON_H */
