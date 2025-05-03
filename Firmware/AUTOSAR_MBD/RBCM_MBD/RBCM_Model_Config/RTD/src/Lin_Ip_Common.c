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

/**
*   @file
*
*   @addtogroup LPUART_LIN_IP
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

#include "Lin_Ip_Common.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_IP_COMMON_VENDOR_ID_C                      43
#define LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION_C       7
#define LIN_IP_COMMON_AR_RELEASE_REVISION_VERSION_C    0
#define LIN_IP_COMMON_SW_MAJOR_VERSION_C               5
#define LIN_IP_COMMON_SW_MINOR_VERSION_C               0
#define LIN_IP_COMMON_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_Ip_Common.h */
#if (LIN_IP_COMMON_VENDOR_ID_C != LIN_IP_COMMON_VENDOR_ID)
    #error "Lin_Ip_Common.c and Lin_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Lin_Ip_Common header file are of the same Autosar version */
#if ((LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION_C    != LIN_IP_COMMON_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION_C    != LIN_IP_COMMON_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IP_COMMON_AR_RELEASE_REVISION_VERSION_C != LIN_IP_COMMON_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Ip_Common.c and Lin_Ip_Common.h are different"
#endif
/* Check if current file and Lin_Ip_Common header file are of the same Software version */
#if ((LIN_IP_COMMON_SW_MAJOR_VERSION_C != LIN_IP_COMMON_SW_MAJOR_VERSION) || \
     (LIN_IP_COMMON_SW_MINOR_VERSION_C != LIN_IP_COMMON_SW_MINOR_VERSION) || \
     (LIN_IP_COMMON_SW_PATCH_VERSION_C != LIN_IP_COMMON_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ip_Common.c and Lin_Ip_Common.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

static inline uint8 BIT(uint8 A, uint8 B);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @internal
 * @brief Return bit B in byte A
 *
 * @param[in] A - The byte
 * @param[in] B - The bit
 *
 * @return The bit
 *
 *
 */
static inline uint8 BIT(uint8 A,
                          uint8 B)
{
    return (uint8)((A >> B) & 0x01U);
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/*FUNCTION**********************************************************************
 *
 * Function Name : Lin_Ip_ProcessParity
 * Description   : This function performs two type of actions depeding on
 * the second parameter (TypeAction). It checkes the parity bits or computes the parity bits.
 *
 * Implements    : Lin_Ip_ProcessParity_Activity
 *END**************************************************************************/
uint8 Lin_Ip_ProcessParity(const uint8 Pid, const Lin_Ip_ParityActionType TypeAction)
{
    uint8 CalPid = Pid & LIN_IP_ID_MASK_U8;
    uint8 RetVal = 0xFFu;

    CalPid |= (uint8)((0xFFU & ((BIT(Pid, 0U) ^ BIT(Pid, 1U) ^ BIT(Pid, 2U) ^ BIT(Pid, 4U)) << 6U)) | \
                       (0xFFU & ((0x01U ^ ((BIT(Pid, 1U) ^ BIT(Pid, 3U) ^ BIT(Pid, 4U) ^ BIT(Pid, 5U)) & 0x01U)) << 7U)) \
                     );

    /* Check if action is checking parity bits */
    if (LIN_IP_CHECK_PARITY == TypeAction)
    {
        /* If parity bits are incorrect */
        if (Pid != CalPid)
        {
            /* Return 0xFF if parity bits are incorrect */
            RetVal = 0xFFU;
        }
        /* If parity bits are correct */
        else
        {
            /* Return ID if parity bits are correct */
            RetVal = (uint8)(Pid & LIN_IP_ID_MASK_U8);
        }
    }
    /* If action is making parity bits */
    else if (LIN_IP_MAKE_PARITY == TypeAction)
    {
        /* Return PID in case of making parity bits */
        RetVal = CalPid;
    }
    else
    {
        /* Should not enter here */
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lin_Ip_MakeChecksumByte
 * Description   : This function makes the checksum byte for a frame. For PID of identifiers,
 * if PID is 0x3C (ID 0x3C) or 0x7D (ID 0x3D) or 0xFE (ID 0x3E) or 0xBF (ID 0x3F) apply classic checksum
 * and apply enhanced checksum for other PID. In case user want to calculate classic checksum  PID is set to zero.
 *
 * Implements    : Lin_Ip_ProcessParity_Activity
 *END**************************************************************************/
uint8 Lin_Ip_MakeChecksumByte(const uint8 * BufferPtr, const uint8 SizeBuffer, const uint8 Pid)
{
    uint8 Length;
    uint16 CheckSum = 0U;

    /* For PID is 0x3C (ID 0x3C) or 0x7D (ID 0x3D) or 0xFE (ID 0x3E) or 0xBF (ID 0x3F)
     * apply classic checksum and apply enhanced checksum for other PID */
    if ((0x3CU != Pid) && (0x7DU != Pid) && (0xFEU != Pid) && (0xBFU != Pid))
    {
        /* For PID other than 0x3C, 0x7D, 0xFE and 0xBF: Add PID in checksum calculation */
        CheckSum = Pid;
    }
    else
    {
        /* For 0x3C, 0x7D, 0xFE and 0xBF: Do not add PID in checksum calculation */
        CheckSum = 0U;
    }

    for (Length = 0U; Length < SizeBuffer; Length++)
    {
        CheckSum += BufferPtr[Length];
        /* Deal with the carry */
        if (CheckSum > 0xFFU)
        {
            CheckSum -= 0xFFU;
        }
    }

    /* Return reversed checksum */
    return (uint8)(~CheckSum);
}

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
