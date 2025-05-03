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

#ifndef LPUART_LIN_IP_HW_ACCESS_H
#define LPUART_LIN_IP_HW_ACCESS_H


/**
*   @file
*   @internal
*   @defgroup lpuart_lin_ip Lpuart Lin IPL
*   @addtogroup  lpuart_lin_ip Lpuart Lin IPL
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
#include "Lpuart_Lin_Ip_Types.h"
#include "OsIf.h"
#include "SchM_Lin_43_LPUART_FLEXIO.h"

#if (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif /* (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_HW_ACCESS_VENDOR_ID                    43
#define LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION     4
#define LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION     7
#define LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION  0
#define LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION             5
#define LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION             0
#define LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if (LPUART_LIN_IP_HW_ACCESS_VENDOR_ID != LPUART_LIN_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Lin_Ip_Hw_Access.h and Lpuart_Lin_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Autosar version */
#if ((LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != LPUART_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != LPUART_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != LPUART_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_Hw_Access.c and Lpuart_Lin_Ip_Types.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Types header file are of the same Software version */
#if ((LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION != LPUART_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION != LPUART_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION != LPUART_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_Hw_Access.h and Lpuart_Lin_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpuart_Lin_Ip_Hw_Access.h and OsIf.h are different"
    #endif
    /* Check if current file and SchM_Lin_43_LPUART_FLEXIO.h header file are of the same Autosar version */
    #if ((LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != SCHM_LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
         (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != SCHM_LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpuart_Lin_Ip_Hw_Access.h and SchM_Lin_43_LPUART_FLEXIO.h are different"
    #endif

#if (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT)
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ((LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lpuart_Lin_Ip_Hw_Access.h and Devassert.h are different"
    #endif
#endif /* (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT) */
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#if (LPUART_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    #define LPUART_LIN_IP_DEV_ASSERT(x)      DevAssert(x)
#endif

/**
* @brief          Mask used to verify the DATA registers content.
*/

#define LPUART_LIN_IP_DATA_MASK_U32   ((uint32)0x000000FFUL)

/**
 * @internal
 * @brief Lpuart shift using for read/write 16 bits of a register.
 *
 *
 */
#define LPUART_LIN_IP_SHIFT (16U)

/**
 * @internal
 * @brief Macro indicating BAUD register.
 *
 *
 */
#define LPUART_LIN_IP_BAUD_REG_ID (1U)

/**
 * @internal
 * @brief Macro indicating STAT register.
 *
 *
 */
#define LPUART_LIN_IP_STAT_REG_ID (2U)

/**
 * @internal
 * @brief Macro indicating CTRL register.
 *
 *
 */
#define LPUART_LIN_IP_CTRL_REG_ID (3U)

/**
 * @internal
 * @brief Macro indicating DATA register.
 *
 *
 */
#define LPUART_LIN_IP_DATA_REG_ID (4U)

/**
 * @internal
 * @brief Flag clearance mask for STAT register.
 *
 *
 */
#define LPUART_LIN_IP_STAT_REG_FLAGS_MASK (0xC01FC000U)

/**
 * @internal
 * @brief Default oversampling ratio.
 *
 *
 */
#define LPUART_LIN_IP_DEFAULT_OSR (0x0FUL)

/**
 * @internal
 * @brief Default baud rate modulo divisor.
 *
 *
 */
#define LPUART_LIN_IP_DEFAULT_SBR (0x04UL)

/**
 * @internal
 * @brief Has extended Data register ED.
 *
 *
 */
#define LPUART_LIN_IP_HAS_EXTENDED_DATA_REGISTER_FLAGS (1U)

/**
 * @internal
 * @brief Mask for all used interrupt flags.
 *
 *
 */
#define LPUART_LIN_IP_STAT_ALL_INT_FLAGS_MASK_U32      ((uint32)LPUART_STAT_LBKDIF_MASK \
                                                        | (uint32)LPUART_STAT_RXEDGIF_MASK \
                                                        | (uint32)LPUART_STAT_IDLE_MASK \
                                                        | (uint32)LPUART_STAT_OR_MASK \
                                                        | (uint32)LPUART_STAT_NF_MASK \
                                                        | (uint32)LPUART_STAT_FE_MASK \
                                                        | (uint32)LPUART_STAT_PF_MASK \
                                                       )

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
 *  @internal
 *  @brief LPUART number of bits in a character
 *
 *
 */
typedef enum
{
    LPUART_LIN_IP_8_BITS_PER_CHAR  = 0x0U, /**< 8-bit Data characters */
    LPUART_LIN_IP_9_BITS_PER_CHAR  = 0x1U, /**< 9-bit Data characters */
    LPUART_LIN_IP_10_BITS_PER_CHAR = 0x2U  /**< 10-bit Data characters */
} Lpuart_Lin_Ip_BitCountPerCharType;

/**
 * @internal
 * @brief LPUART parity mode
 *
 *
 */
typedef enum
{
    LPUART_LIN_IP_PARITY_DISABLED = 0x0U, /**< parity disabled */
    LPUART_LIN_IP_PARITY_EVEN     = 0x2U, /**< parity Enabled, type even, bit setting: PE|PT = 10 */
    LPUART_LIN_IP_PARITY_ODD      = 0x3U  /**< parity Enabled, type odd,  bit setting: PE|PT = 11 */
} Lpuart_Lin_Ip_ParityModeType;

/**
 * @internal
 * @brief LPUART stop bits
 *
 *
 */
typedef enum
{
    LPUART_LIN_IP_ONE_STOP_BIT = 0x0U, /**< one stop bit */
    LPUART_LIN_IP_TWO_STOP_BIT = 0x1U  /**< two stop bits */
} Lpuart_Lin_Ip_StopBitCountType;

/**
 * @internal
 * @brief LPUART status flags.
 * @details This provides constants for the LPUART status flags for use in the UART functions.
 *
 *
 */
typedef enum
{
    LPUART_LIN_IP_ALL_INT_FLAGS              = ((uint32)0x00U), \
                                        /**< All status flag */
    LPUART_LIN_IP_TX_DATA_REG_EMPTY          = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_TDRE_SHIFT), \
                                        /**< Tx Data register empty flag, sets when Tx buffer is empty */
    LPUART_LIN_IP_TX_COMPLETE                = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_TC_SHIFT), \
                                        /**< Transmission complete flag, sets when transmission activity complete */
    LPUART_LIN_IP_RX_DATA_REG_FULL           = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_RDRF_SHIFT), \
                                        /**< Rx Data register full flag, sets when the receive Data buffer is full */
    LPUART_LIN_IP_IDLE_LINE_DETECT           = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_IDLE_SHIFT), \
                                        /**< Idle line detect flag, sets when idle line detected */
    LPUART_LIN_IP_RX_OVERRUN                 = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_OR_SHIFT), \
                                        /**< Rx Overrun sets if new Data is received before Data is read */
    LPUART_LIN_IP_NOISE_DETECT               = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_NF_SHIFT), \
                                        /**< Rx takes 3 samples of each received bit. If these differ, the flag sets */
    LPUART_LIN_IP_FRAME_ERR                  = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_FE_SHIFT), \
                                        /**< Frame error flag, sets if logic 0 was detected where stop bit expected */
    LPUART_LIN_IP_PARITY_ERR                 = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_PF_SHIFT), \
                                        /**< If parity Enabled, sets upon parity error detection */
    LPUART_LIN_IP_BREAK_DETECT           = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_LBKDIF_SHIFT), \
                                        /**< LIN break detect interrupt flag, sets when LIN break char detected */
    LPUART_LIN_IP_RX_ACTIVE_EDGE_DETECT      = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_RXEDGIF_SHIFT), \
                                        /**< Rx pin active edge interrupt flag, sets when active edge detected */
    LPUART_LIN_IP_RX_ACTIVE                  = (((uint32)LPUART_LIN_IP_STAT_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_STAT_RAF_SHIFT), \
                                        /**< Receiver Active Flag (RAF), sets at beginning of valid start bit */
    LPUART_LIN_IP_NOISE_IN_CURRENT_WORD      = (((uint32)LPUART_LIN_IP_DATA_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_DATA_NOISY_SHIFT), \
                                        /**< NOISY bit, sets if noise detected in current Data word */
    LPUART_LIN_IP_PARITY_ERR_IN_CURRENT_WORD = (((uint32)LPUART_LIN_IP_DATA_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                        | (uint32)LPUART_DATA_PARITYE_SHIFT), \
                                        /**< PARITYE bit, sets if noise detected in current Data word */
} Lpuart_Lin_Ip_StatusFlagType;

/**
 * @internal
 * @brief LPUART interrupt configuration structure, default settings are 0 (disabled)
 *
 *
 * */
typedef enum
{
    LPUART_LIN_IP_INT_BREAK_DETECT  = (((uint32)LPUART_LIN_IP_BAUD_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_BAUD_LBKDIE_SHIFT),  /**< LIN break detect. */
    LPUART_LIN_IP_INT_RX_ACTIVE_EDGE    = (((uint32)LPUART_LIN_IP_BAUD_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_BAUD_RXEDGIE_SHIFT), /**< RX Active Edge. */
    LPUART_LIN_IP_INT_TX_DATA_REG_EMPTY = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_TIE_SHIFT),     /**< Transmit Data register empty. */
    LPUART_LIN_IP_INT_TX_COMPLETE       = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_TCIE_SHIFT),    /**< Transmission complete. */
    LPUART_LIN_IP_INT_RX_DATA_REG_FULL  = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_RIE_SHIFT),     /**< Receiver Data register full. */
    LPUART_LIN_IP_INT_IDLE_LINE         = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_ILIE_SHIFT),    /**< Idle line. */
    LPUART_LIN_IP_INT_RX_OVERRUN        = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_ORIE_SHIFT),    /**< Receiver Overrun. */
    LPUART_LIN_IP_INT_NOISE_ERR_FLAG    = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_NEIE_SHIFT),    /**< Noise error flag. */
    LPUART_LIN_IP_INT_FRAME_ERR_FLAG    = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_FEIE_SHIFT),    /**< Framing error flag. */
    LPUART_LIN_IP_INT_PARITY_ERR_FLAG   = (((uint32)LPUART_LIN_IP_CTRL_REG_ID << (uint32)LPUART_LIN_IP_SHIFT) \
                                   | (uint32)LPUART_CTRL_PEIE_SHIFT),    /**< Parity error flag. */
} Lpuart_Lin_Ip_InterruptType;

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
 * @internal
 * @brief  Lpuart_Lin_Ip_StartTimeout
 *
 * @details Checks for timeout condition
 *
 * @param[in] StartTimeOut Current time counter (in microseconds)
 * @param[in] TimeoutTicksOut Time counter in ticks
 * @param[in] TimeoutUs LPUART Timeout value to check (in microseconds)
 * @param[in] OsifCounter Type of counter used by Osif

 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter);

/**
 * @internal
 * @brief  Lpuart_Lin_Ip_TimeoutExpired
 *
 * @details Checks for timeout expiration condition
 *
 * @param[in] StartTime Pointer to current time counter (in microseconds)
 * @param[in] ElapsedTicks Pointer to current elapsed ticks
 * @param[in] TimeoutTicks Time counter in ticks
 * @param[in] OsifCounter Type of counter used by Osif

 *
 * @return boolean
 * @retval true : Timeout expired.
 * @retval false : Timeout didn't expire.
 *
 *
 */
boolean Lpuart_Lin_Ip_TimeoutExpired(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks,  OsIf_CounterType OsifCounter);

/**
 * @internal
 * @brief Initializes the LPUART controller.
 * @details This function Initializes the LPUART controller to known state.
 *
 * @param[in] Base LPUART base pointer.
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwInit(LPUART_Type * Base);

/**
 * @internal
 * @brief Enable/Disable the LPUART transmitter.
 *
 * @details This function Enables or disables the LPUART transmitter, Based on the
 * parameter received.
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] Enable Enable(true) or disable(false) transmitter.
 *
 * @return boolean
 * @retval true : Timeout occured.
 * @retval false : Timeout didn'occur.
 *
 *
 *
 */
boolean Lpuart_Lin_Ip_HwSetTransmitterCmd(LPUART_Type * Base, boolean Enable);

/**
 * @internal
 * @brief Enable/Disable the LPUART receiver.
 *
 * @details This function Enables or disables the LPUART receiver, Based on the
 * parameter received.
 *
 * @param[in] Base LPUART base pointer
 * @param[in] Enable Enable(true) or disable(false) receiver.
 *
 * @return boolean
 * @retval true : Timeout occured.
 * @retval false : Timeout didn'occur.
 *
 *
 */
boolean Lpuart_Lin_Ip_HwSetReceiverCmd(LPUART_Type * Base, boolean Enable);

/**
 * @internal
 * @brief  LPUART break character detect length configuration
 *
 * @details This function sets the LPUART detectable break character length.
 *
 *
 * @param[in] Base LPUART base pointer
 * @param[in] Length  LPUART break character length setting: 0 - minimum 10-bit times (default),
 *                  1 - minimum 13-bit times
 *
 * @return void
 *
 */
void Lpuart_Lin_Ip_HwSetBreakCharDetectLength(LPUART_Type * Base, uint8 Length);

/**
 * @internal
 * @brief Sets whether the recevie Data is inverted or not.
 *
 * @details This function sets the polarity of the receive Data.
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] Polarity  Rx Data Polarity; true: inverted, false: not inverted.
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwSetRxDataPolarity(LPUART_Type * Base, boolean Polarity);

/**
 * @internal
 * @brief Sets the LPUART baud rate modulo divisor.
 *
 * @details This function sets the LPUART baud rate modulo divisor.
 *
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] BaudRateDivisor The baud rate modulo division "SBR"
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwSetBaudRateDivisor(LPUART_Type * Base, uint32 BaudRateDivisor);

/**
 * @internal
 * @brief Configures the number of stop bits in the LPUART controller.
 *
 * @details This function configures the number of stop bits in the LPUART controller.
 * In some LPUART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all LPUARTs to ensure safe operation.
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] StopBitCount Number of stop bits (1 or 2 - see Lpuart_Lin_Ip_StopBitCountType struct)
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwSetStopBitCount(LPUART_Type * Base, Lpuart_Lin_Ip_StopBitCountType StopBitCount);

/**
 * @internal
 * @brief Gets the LPUART baud rate modulo divisor.
 *
 * @details This function gets the LPUART baud rate modulo divisor.
 *
 * @param[in] Base LPUART base pointer.
 *
 * @return The baud rate modulo division "SBR"
 *
 *
 */
static inline uint16 Lpuart_Lin_Ip_HwGetBaudRateDivisor(const LPUART_Type * Base)
{
    return ((uint16)((Base->BAUD & LPUART_BAUD_SBR_MASK) >> LPUART_BAUD_SBR_SHIFT));
}

/**
 * @internal
 * @brief Sets the LPUART baud rate oversampling ratio
 *
 * @details This function sets the LPUART baud rate oversampling ratio.
 * (Note: Feature available on select LPUART instances used together with baud rate programming)
 * The oversampling ratio should be set between 4x (00011) and 32x (11111). Writing
 * an invalid oversampling ratio results in an error and is set to a default
 * 16x (01111) oversampling ratio.
 * Disable the transmitter/receiver before calling this function.
 *
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] OverSamplingRatio The oversampling ratio "OSR"
 *
 * @return void
 *
 *
 */
static inline void Lpuart_Lin_Ip_HwSetOversamplingRatio(LPUART_Type * Base, uint32 OverSamplingRatio)
{
    uint32 BaudRegValTemp;

#if (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT)
    LPUART_LIN_IP_DEV_ASSERT(OverSamplingRatio <= 0x1FU);
#endif /* (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT) */

    BaudRegValTemp = Base->BAUD;
    BaudRegValTemp &= ~(LPUART_BAUD_OSR_MASK);
    BaudRegValTemp |= LPUART_BAUD_OSR(OverSamplingRatio);
    Base->BAUD = BaudRegValTemp;
}

/**
 * @internal
 * @brief Gets the LPUART baud rate oversampling ratio
 *
 * @details This function gets the LPUART baud rate oversampling ratio.
 * (Note: Feature available on select LPUART instances used together with baud rate programming)
 *
 * @param[in] Base LPUART base pointer.
 *
 * @return The oversampling ratio "OSR"
 *
 *
 */
static inline uint8 Lpuart_Lin_Ip_HwGetOversamplingRatio(const LPUART_Type * Base)
{
    return ((uint8)((Base->BAUD & LPUART_BAUD_OSR_MASK) >> LPUART_BAUD_OSR_SHIFT));
}

/**
 * @internal
 * @brief Configures the LPUART baud rate both edge sampling
 *
 * @details This function configures the LPUART baud rate both edge sampling.
 * (Note: Feature available on select LPUART instances used with baud rate programming)
 * When Enabled, the received Data is sampled on both edges of the baud rate clock.
 * This must be set when the oversampling ratio is between 4x and 7x.
 * @details This function should only be called when the receiver is disabled.
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] Enable   Enable (1) or Disable (0) Both Edge Sampling
 *
 * @return void
 */
static inline void Lpuart_Lin_Ip_HwEnableBothEdgeSamplingCmd(LPUART_Type * Base)
{
    Base->BAUD |= LPUART_BAUD_BOTHEDGE_MASK;
}

/**
 * @internal
 * @brief Configures the number of bits per character in the LPUART controller.
 *
 * @details This function configures the number of bits per character in the LPUART controller.
 * In some LPUART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all LPUARTs to ensure safe operation.
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] BitCountPerChar  Number of bits per char (8, 9, or 10, depending on the LPUART instance)
 * @param[in] Parity  Specifies whether parity bit is Enabled
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwSetBitCountPerChar(LPUART_Type * Base, Lpuart_Lin_Ip_BitCountPerCharType BitCountPerChar, boolean Parity);

/**
 * @internal
 * @brief Configures parity mode in the LPUART controller.
 *
 * @details This function configures parity mode in the LPUART controller.
 * In some LPUART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all LPUARTs to ensure safe operation.
 *
 * @param[in] Base LPUART base pointer.
 * @param[in] ParityModeType  Parity mode (Enabled, disable, odd, even - see parity_mode_t struct)
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwSetParityMode(LPUART_Type * Base, Lpuart_Lin_Ip_ParityModeType ParityModeType);

/**
 * @internal
 * @brief Configures the LPUART module interrupts.
 *
 * @details This function configures the LPUART module interrupts to enable/disable various interrupt sources.
 *
 *
 * @param[in]   Base LPUART module base pointer.
 * @param[in]   IntSrc LPUART interrupt configuration Data.
 * @param[in]   Enable   true: enable, false: disable.
 *
 * @return void
 *
 *
 */
void Lpuart_Lin_Ip_HwSetIntMode(LPUART_Type * Base, Lpuart_Lin_Ip_InterruptType IntSrc, boolean Enable);

/**
 * @internal
 * @brief Returns LPUART module interrupts state.
 *
 * @details This function returns whether a certain LPUART module interrupt is Enabled or disabled.
 *
 *
 * @param[in]   Base LPUART module base pointer.
 * @param[in]   IntSrc LPUART interrupt configuration Data.
 *
 * @return  true: Enable, false: disable.
 *
 *
 */
boolean Lpuart_Lin_Ip_HwGetIntMode(const LPUART_Type * Base, Lpuart_Lin_Ip_InterruptType IntSrc);

/**
 * @internal
 * @brief Sends the LPUART 8-bit character.
 *
 * @details This functions sends an 8-bit character.
 *
 * @param[in] Base LPUART Instance
 * @param[in] Data Data to send (8-bit)
 *
 * @return void
 *
 *
 */
static inline void Lpuart_Lin_Ip_HwPutchar(LPUART_Type * Base, uint8 Data)
{
    volatile uint8 * DataRegBytes = (volatile uint8 *)(&(Base->DATA));
    DataRegBytes[0] = Data;
}

/**
 * @internal
 * @brief Gets the LPUART 8-bit character.
 *
 * @details This functions receives an 8-bit character.
 *
 *
 * @param[in] Base LPUART base pointer
 * @param[in] ReadData Data read from receive (8-bit)
 *
 * @return void
 *
 *
 */
static inline void Lpuart_Lin_Ip_HwGetchar(const LPUART_Type * Base, uint8 *ReadData)
{
#if (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT)
    LPUART_LIN_IP_DEV_ASSERT(NULL_PTR != ReadData);
#endif /* (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT) */

    *ReadData = (uint8)(Base->DATA & LPUART_LIN_IP_DATA_MASK_U32);
}

/**
 * @internal
 * @brief  LPUART get status flag
 *
 * @details This function returns the state of a status flag.
 *
 *
 * @param[in] Base LPUART base pointer
 * @param[in] StatusFlag  The status flag to query
 *
 * @return Whether the current status flag is set(true) or not(false).
 *
 *
 */
boolean Lpuart_Lin_Ip_HwGetStatusFlag(const LPUART_Type * Base, Lpuart_Lin_Ip_StatusFlagType StatusFlag);

/**
 * @internal
 * @brief LPUART clears an individual status flag.
 *
 * @details This function clears an individual status flag (see Lpuart_Lin_Ip_StatusFlagType for list of status bits).
 *
 *
 * @param[in] Base LPUART base pointer
 * @param[in] StatusFlag  Desired LPUART status flag to clear
 *
 * @return STATUS_SUCCESS if successful or STATUS_ERROR if an error occured
 *
 *
 */
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_HwClearStatusFlag(LPUART_Type * Base, Lpuart_Lin_Ip_StatusFlagType StatusFlag);

/**
 * @internal
 * @brief Returns whether the receive Data is inverted or not.
 *
 * @details This function returns the Polarity of the receive Data.
 *
 * @param[in] Base LPUART base pointer.
 *
 * @return Rx Data Polarity; true: inverted, false: not inverted.
 *
 *
 */
static inline boolean Lpuart_Lin_Ip_HwGetRxDataPolarity(const LPUART_Type * Base)
{
    return (((Base->STAT >> LPUART_STAT_RXINV_SHIFT) & 1U) > 0U);
}

/**
 * @internal
 * @brief  LPUART break character transmit length configuration
 *
 * @details This function configures the break char length.
 * In some LPUART instances, the user should disable the transmitter before calling
 * this function. Generally, this may be applied to all LPUARTs to ensure safe operation.
 *
 * @param[in] Base LPUART base pointer
 * @param[in] Length   LPUART break character length setting: 0 - minimum 10-bit times (default),
 *                   1 - minimum 13-bit times
 *
 * @return void
 *
 *
 */
static inline void Lpuart_Lin_Ip_HwSetBreakCharTransmitLength(LPUART_Type * Base, uint8 Length)
{
    Base->STAT = (Base->STAT
            & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK & ~LPUART_STAT_BRK13_MASK))
            | ((uint32) Length << LPUART_STAT_BRK13_SHIFT);
}

/**
 * @internal
 * @brief  LPUART transmit sends break character configuration.
 *
 * @details This function sets break character transmission in queue mode.
 *
 * @param[in] Base LPUART base pointer
 *
 * @return void
 *
 *
 */
static inline void Lpuart_Lin_Ip_HwQueueBreakField(LPUART_Type * Base)
{
    Base->DATA = LPUART_DATA_FRETSC(1U);
}

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* LPUART_LIN_IP_HW_ACCESS_H */
