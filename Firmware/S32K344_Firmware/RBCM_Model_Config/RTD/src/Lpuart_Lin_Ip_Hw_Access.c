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
*   @file   Lpuart_Lin_Ip_Hw_Access.c
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

#include "Lpuart_Lin_Ip_Hw_Access.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPUART_LIN_IP_HW_ACCESS_VENDOR_ID_C                      43
#define LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION_C               5
#define LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION_C               0
#define LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (LPUART_LIN_IP_HW_ACCESS_VENDOR_ID_C != LPUART_LIN_IP_HW_ACCESS_VENDOR_ID)
    #error "Lpuart_Lin_Ip_Hw_Access.c and Lpuart_Lin_Ip_Hw_Access.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same Autosar version */
#if ((LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_Hw_Access.c and Lpuart_Lin_Ip_Hw_Access.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same Software version */
#if ((LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION_C != LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION_C != LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION_C != LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip_Hw_Access.c and Lpuart_Lin_Ip_Hw_Access.h are different"
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

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwInit
 * Description   : Initializes the LPUART controller to known state, using
 *                 register reset values defined in the reference manual.
 *END**************************************************************************/
void Lpuart_Lin_Ip_HwInit(LPUART_Type * Base)
{
    /* Set the default oversampling ratio (16) and baud-rate divider (4) */
    Base->BAUD = ((uint32)((LPUART_LIN_IP_DEFAULT_OSR << LPUART_BAUD_OSR_SHIFT) | \
                 (LPUART_LIN_IP_DEFAULT_SBR << LPUART_BAUD_SBR_SHIFT)));
    /* Clear the error/interrupt flags */
    Base->STAT = LPUART_LIN_IP_STAT_REG_FLAGS_MASK;
    /* Reset all features/interrupts by default */
    Base->CTRL = 0x00000000;
    /* Reset match addresses */
    Base->MATCH = 0x00000000;
}

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
void Lpuart_Lin_Ip_HwSetBreakCharDetectLength(LPUART_Type * Base, uint8 Length)
{
    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_25();
    {
        Base->STAT = (Base->STAT
                & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK & ~LPUART_STAT_LBKDE_MASK))
                | ((uint32) Length << LPUART_STAT_LBKDE_SHIFT);
    }
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_25();
}
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
void Lpuart_Lin_Ip_HwSetRxDataPolarity(LPUART_Type * Base, boolean Polarity)
{
    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_24();
    Base->STAT = (Base->STAT
            & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK & ~LPUART_STAT_RXINV_MASK))
            | ((Polarity ? 1UL : 0UL) << LPUART_STAT_RXINV_SHIFT);
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_24();
}

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
void Lpuart_Lin_Ip_HwSetBaudRateDivisor(LPUART_Type * Base, uint32 BaudRateDivisor)
{
    uint32 BaudRegValTemp;

#if (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT)
    LPUART_LIN_IP_DEV_ASSERT((0x1FFFU >= BaudRateDivisor) && (1U <= BaudRateDivisor));
#endif /* (STD_ON == LPUART_LIN_IP_DEV_ERROR_DETECT) */
    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_22();
    BaudRegValTemp = Base->BAUD;
    BaudRegValTemp &= ~(LPUART_BAUD_SBR_MASK);
    /* Removed the shift operation as the SBR field position is zero; shifting with 0 violates MISRA */
    BaudRegValTemp |= BaudRateDivisor & LPUART_BAUD_SBR_MASK;
    Base->BAUD = BaudRegValTemp;
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_22();
}
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
void Lpuart_Lin_Ip_HwSetStopBitCount(LPUART_Type * Base, Lpuart_Lin_Ip_StopBitCountType StopBitCount)
{
    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_23();
    Base->BAUD = (Base->BAUD & ~LPUART_BAUD_SBNS_MASK) | ((uint32)StopBitCount << LPUART_BAUD_SBNS_SHIFT);
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_23();
}
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
boolean Lpuart_Lin_Ip_HwSetTransmitterCmd(LPUART_Type * Base, boolean Enable)
{
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    boolean TimeoutOccured = TRUE;

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_20();
    Base->CTRL = (Base->CTRL & ~LPUART_CTRL_TE_MASK) | ((Enable ? 1UL : 0UL) << LPUART_CTRL_TE_SHIFT);
    Lpuart_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, LPUART_LIN_IP_TIMEOUT_VALUE_US, LPUART_LIN_IP_TIMEOUT_TYPE);

    /*Add label Fault Injecton */
    MCAL_FAULT_INJECTION_POINT(LPUART_FIP_1_T_TIME_OUT_2);

    do
    {
        /* Check if register write operation is completed */
        if ((boolean)((Base->CTRL & LPUART_CTRL_TE_MASK) != 0U) == Enable)
        {
            TimeoutOccured = FALSE;
            break;
        }
    }
    while (!Lpuart_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, LPUART_LIN_IP_TIMEOUT_TYPE));
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_20();

    return TimeoutOccured;
}

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
boolean Lpuart_Lin_Ip_HwSetReceiverCmd(LPUART_Type * Base, boolean Enable)
{
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    boolean TimeoutOccured = TRUE;

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_21();
    Base->CTRL = (Base->CTRL & ~LPUART_CTRL_RE_MASK) | ((Enable ? 1UL : 0UL) << LPUART_CTRL_RE_SHIFT);
    Lpuart_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, LPUART_LIN_IP_TIMEOUT_VALUE_US, LPUART_LIN_IP_TIMEOUT_TYPE);
    /*Add label Fault Injecton */
    MCAL_FAULT_INJECTION_POINT(LPUART_FIP_1_T_TIME_OUT_3);
    do
    {
        /* Check if register write operation is completed */
        if ((boolean)((Base->CTRL & LPUART_CTRL_RE_MASK) != 0U) == Enable)
        {
            TimeoutOccured = FALSE;
            break;
        }
    }
    while (!Lpuart_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, LPUART_LIN_IP_TIMEOUT_TYPE));
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_21();

    return TimeoutOccured;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwSetBitCountPerChar
 * Description   : Configures the number of bits per char in LPUART controller.
 * In some LPUART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all LPUARTs to ensure safe operation.
 *END**************************************************************************/
void Lpuart_Lin_Ip_HwSetBitCountPerChar(LPUART_Type * Base, Lpuart_Lin_Ip_BitCountPerCharType BitCountPerChar, boolean Parity)
{
    uint32 TmpBitCountPerChar = (uint32)BitCountPerChar;

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_27();
    if (Parity)
    {
        TmpBitCountPerChar += 1U;
    }

    if ((uint32)LPUART_LIN_IP_10_BITS_PER_CHAR == TmpBitCountPerChar)
    {
        Base->BAUD = (Base->BAUD & ~LPUART_BAUD_M10_MASK) | ((uint32)1U << LPUART_BAUD_M10_SHIFT);
    }
    else
    {
        /* config 8-bit (M=0) or 9-bits (M=1) */
        Base->CTRL = (Base->CTRL & ~LPUART_CTRL_M_MASK) | (TmpBitCountPerChar << LPUART_CTRL_M_SHIFT);
        /* clear M10 to make sure not 10-bit mode */
        Base->BAUD &= ~LPUART_BAUD_M10_MASK;
    }
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_27();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwSetParityMode
 * Description   : Configures parity mode in the LPUART controller.
 * In some LPUART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all LPUARTs to ensure safe operation.
 *END**************************************************************************/
void Lpuart_Lin_Ip_HwSetParityMode(LPUART_Type * Base, Lpuart_Lin_Ip_ParityModeType ParityModeType)
{
    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_08();
    Base->CTRL = (Base->CTRL & ~LPUART_CTRL_PE_MASK) | (((uint32)ParityModeType >> 1U) << LPUART_CTRL_PE_SHIFT);
    Base->CTRL = (Base->CTRL & ~LPUART_CTRL_PT_MASK) | (((uint32)ParityModeType & 1U) << LPUART_CTRL_PT_SHIFT);
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_08();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwSetIntMode
 * Description   : Configures the LPUART module interrupts to enable/disable
 * various interrupt sources.
 *END**************************************************************************/
void Lpuart_Lin_Ip_HwSetIntMode(LPUART_Type * Base, Lpuart_Lin_Ip_InterruptType IntSrc, boolean Enable)
{
    uint32 Reg = (uint32)(IntSrc) >> LPUART_LIN_IP_SHIFT;
    uint32 IntRegOffset = (uint16)(IntSrc);

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_09();
    {
        switch (Reg)
        {
            case LPUART_LIN_IP_BAUD_REG_ID:
                Base->BAUD = (Base->BAUD & ~(1UL << IntRegOffset)) | ((Enable ? 1U : 0U) << IntRegOffset);
                break;
            case LPUART_LIN_IP_CTRL_REG_ID:
                Base->CTRL = (Base->CTRL & ~(1UL << IntRegOffset)) | ((Enable ? 1U : 0U) << IntRegOffset);
                break;
            default :
                /* Invalid parameter: return */
                break;
        }
    }
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_09();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwGetIntMode
 * Description   : Returns whether LPUART module interrupt is enabled/disabled.
 *END**************************************************************************/
boolean Lpuart_Lin_Ip_HwGetIntMode(const LPUART_Type * Base, Lpuart_Lin_Ip_InterruptType IntSrc)
{
    uint32 Reg = (uint32)(IntSrc) >> LPUART_LIN_IP_SHIFT;
    boolean RetVal = FALSE;
    uint8 IntRegOffset = (uint8)(IntSrc);

    switch (Reg)
    {
        case LPUART_LIN_IP_BAUD_REG_ID:
            RetVal = (((Base->BAUD >> IntRegOffset) & 1U) > 0U);
            break;
        case LPUART_LIN_IP_CTRL_REG_ID:
            RetVal = (((Base->CTRL >> IntRegOffset) & 1U) > 0U);
            break;
        default :
            /* Invalid parameter: return */
            break;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwGetStatusFlag
 * Description   : LPUART get status flag by passing flag enum.
 *END**************************************************************************/
boolean Lpuart_Lin_Ip_HwGetStatusFlag(const LPUART_Type * Base, Lpuart_Lin_Ip_StatusFlagType StatusFlag)
{
    uint32 Reg = (uint32)(StatusFlag) >> LPUART_LIN_IP_SHIFT;
    boolean RetVal = FALSE;

    switch (Reg)
    {
        case LPUART_LIN_IP_STAT_REG_ID:
            RetVal = (((Base->STAT >> (uint16)(StatusFlag)) & 1U) > 0U);
            break;
        case LPUART_LIN_IP_DATA_REG_ID:
            RetVal = (((Base->DATA >> (uint16)(StatusFlag)) & 1U) > 0U);
            break;
        default:
            /* Invalid parameter: return */
            break;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_HwClearStatusFlag
 * Description   : LPUART clears an individual status flag
 * (see Lpuart_Lin_Ip_StatusFlagType for list of status bits).
 *END**************************************************************************/
Lpuart_Lin_Ip_StatusType Lpuart_Lin_Ip_HwClearStatusFlag(LPUART_Type * Base,
                                    Lpuart_Lin_Ip_StatusFlagType StatusFlag)
{
    Lpuart_Lin_Ip_StatusType ReturnCode = LPUART_LIN_IP_STATUS_SUCCESS;

    SchM_Enter_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_10();
    switch(StatusFlag)
    {
        /* These flags are cleared automatically by other lpuart operations
         * and cannot be manually cleared, return error code */
        case LPUART_LIN_IP_TX_DATA_REG_EMPTY:
            /* Fall-through */
        case LPUART_LIN_IP_TX_COMPLETE:
            /* Fall-through */
        case LPUART_LIN_IP_RX_DATA_REG_FULL:
            /* Fall-through */
        case LPUART_LIN_IP_RX_ACTIVE:
            /* Fall-through */
#if LPUART_LIN_IP_HAS_EXTENDED_DATA_REGISTER_FLAGS
        case LPUART_LIN_IP_NOISE_IN_CURRENT_WORD:
            /* Fall-through */
        case LPUART_LIN_IP_PARITY_ERR_IN_CURRENT_WORD:
#endif
            ReturnCode = LPUART_LIN_IP_STATUS_ERROR;
            break;

        case LPUART_LIN_IP_IDLE_LINE_DETECT:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_IDLE_MASK;
            break;

        case LPUART_LIN_IP_RX_OVERRUN:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_OR_MASK;
            break;

        case LPUART_LIN_IP_NOISE_DETECT:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_NF_MASK;
            break;

        case LPUART_LIN_IP_FRAME_ERR:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_FE_MASK;
            break;

        case LPUART_LIN_IP_PARITY_ERR:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_PF_MASK;
            break;

        case LPUART_LIN_IP_BREAK_DETECT:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_LBKDIF_MASK;
            break;

        case LPUART_LIN_IP_RX_ACTIVE_EDGE_DETECT:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_STAT_RXEDGIF_MASK;
            break;

        case LPUART_LIN_IP_ALL_INT_FLAGS:
            Base->STAT = (Base->STAT & (~LPUART_LIN_IP_STAT_REG_FLAGS_MASK)) | LPUART_LIN_IP_STAT_ALL_INT_FLAGS_MASK_U32;
            break;

        default:
            ReturnCode = LPUART_LIN_IP_STATUS_ERROR;
            break;
    }
    SchM_Exit_Lin_43_LPUART_FLEXIO_LIN_EXCLUSIVE_AREA_10();

    return (ReturnCode);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void Lpuart_Lin_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter)
{
    *StartTimeOut    = OsIf_GetCounter(OsifCounter);
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, OsifCounter);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpuart_Lin_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean Lpuart_Lin_Ip_TimeoutExpired(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter)
{
    boolean RetVal = FALSE;
    uint32 CurrentElapsedTicks = OsIf_GetElapsed(StartTime, OsifCounter);

    *ElapsedTicks += CurrentElapsedTicks;
    if (*ElapsedTicks >= TimeoutTicks)
    {
        RetVal = TRUE;
    }

    return RetVal;
}

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
