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
#if !defined(LPI2C_IP_HWACCESS_H)
#define LPI2C_IP_HWACCESS_H

/**
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpi2c_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_HWACCESS_VENDOR_ID                      43
#define LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION       4
#define LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION       7
#define LPI2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION    0
#define LPI2C_IP_HWACCESS_SW_MAJOR_VERSION               5
#define LPI2C_IP_HWACCESS_SW_MINOR_VERSION               0
#define LPI2C_IP_HWACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lpi2c_Ip_Types.h header file are of the same vendor. */
#if ( LPI2C_IP_HWACCESS_VENDOR_ID != LPI2C_IP_TYPES_VENDOR_ID)
    #error "Lpi2c_Ip_HwAccess.h and Lpi2c_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Lpi2c_Ip_Types.h header file are of the same Autosar version */
#if (( LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_HwAccess.h and Lpi2c_Ip_Types.h are different"
#endif
/* Check if current file and Lpi2c_Ip_Types.h header file are of the same Software version */
#if (( LPI2C_IP_HWACCESS_SW_MAJOR_VERSION != LPI2C_IP_TYPES_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_SW_MINOR_VERSION != LPI2C_IP_TYPES_SW_MINOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_SW_PATCH_VERSION != LPI2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_HwAccess.h and Lpi2c_Ip_Types.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
 * LPI2C master interrupts
 */
#ifdef LPI2C_IP_FEATURE_DETECT_START_CONDITION
#define   LPI2C_IP_MASTER_START_DETECT_INT         0x8000U   /**< START Detect Interrupt     */
#endif
#define   LPI2C_IP_MASTER_DATA_MATCH_INT           0x4000U   /**< Data Match Interrupt       */
#define   LPI2C_IP_MASTER_PIN_LOW_TIMEOUT_INT      0x2000U   /**< Pin Low Timeout Interrupt  */
#define   LPI2C_IP_MASTER_FIFO_ERROR_INT           0x1000U   /**< FIFO Error Interrupt       */
#define   LPI2C_IP_MASTER_ARBITRATION_LOST_INT      0x800U   /**< Arbitration Lost Interrupt */
#define   LPI2C_IP_MASTER_NACK_DETECT_INT           0x400U   /**< NACK Detect Interrupt      */
#define   LPI2C_IP_MASTER_STOP_DETECT_INT           0x200U   /**< STOP Detect Interrupt      */
#define   LPI2C_IP_MASTER_END_PACKET_INT            0x100U   /**< End Packet Interrupt       */
#define   LPI2C_IP_MASTER_RECEIVE_DATA_INT            0x2U   /**< Receive Data Interrupt     */
#define   LPI2C_IP_MASTER_TRANSMIT_DATA_INT           0x1U   /**< Transmit Data Interrupt    */

/**
 * LPI2C slave interrupts
 */
#define   LPI2C_IP_SLAVE_SMBUS_ALERT_RESPONSE_INT  0x8000U   /**< SMBus Alert Response Interrupt */
#define   LPI2C_IP_SLAVE_GENERAL_CALL_INT          0x4000U   /**< General Call Interrupt         */
#define   LPI2C_IP_SLAVE_ADDRESS_MATCH_1_INT       0x2000U   /**< Address Match 1 Interrupt      */
#define   LPI2C_IP_SLAVE_ADDRESS_MATCH_0_INT       0x1000U   /**< Address Match 0 Interrupt      */
#define   LPI2C_IP_SLAVE_FIFO_ERROR_INT             0x800U   /**< FIFO Error Interrupt           */
#define   LPI2C_IP_SLAVE_BIT_ERROR_INT              0x400U   /**< Bit Error Interrupt            */
#define   LPI2C_IP_SLAVE_STOP_DETECT_INT            0x200U   /**< STOP Detect Interrupt          */
#define   LPI2C_IP_SLAVE_REPEATED_START_INT         0x100U   /**< Repeated Start Interrupt       */
#define   LPI2C_IP_SLAVE_TRANSMIT_ACK_INT             0x8U   /**< Transmit ACK Interrupt         */
#define   LPI2C_IP_SLAVE_ADDRESS_VALID_INT            0x4U   /**< Address Valid Interrupt        */
#define   LPI2C_IP_SLAVE_RECEIVE_DATA_INT             0x2U   /**< Receive Data Interrupt         */
#define   LPI2C_IP_SLAVE_TRANSMIT_DATA_INT            0x1U   /**< Transmit Data Interrupt        */

#ifdef LPI2C_IP_FEATURE_DETECT_START_CONDITION
/*!
 * @brief Macros for MCFGR1 registers
 *
 * These macros help decode and compose bit mask for detect Start condition functionality.
 *
 */
#define   LPI2C_IP_START_CONFIGURATION           (LPI2C_MCFGR1_STARTCFG_MASK)      /**< Start Configuration */
#endif /* LPI2C_IP_FEATURE_DETECT_START_CONDITION */

#define ENABLE_BIT(x)                            ((uint32)((x == TRUE)?1U:0U))

/** @brief Pin Configuration selection
 */
typedef enum
{
    LPI2C_CFG_2PIN_OPEN_DRAIN             = 0U,  /**< 2-pin open drain mode */
    LPI2C_CFG_2PIN_OUTPUT_ONLY            = 1U,  /**< 2-pin output only mode (ultra-fast mode) */
    LPI2C_CFG_2PIN_PUSH_PULL              = 2U,  /**< 2-pin push-pull mode */
    LPI2C_CFG_4PIN_PUSH_PULL              = 3U,  /**< 4-pin push-pull mode */
    LPI2C_CFG_2PIN_OPEN_DRAIN_SLAVE       = 4U,  /**< 2-pin open drain mode with separate LPI2C slave */
    LPI2C_CFG_2PIN_OUTPUT_ONLY_SLAVE      = 5U,  /**< 2-pin output only mode (ultra-fast mode) with separate LPI2C slave */
    LPI2C_CFG_2PIN_PUSH_PULL_SLAVE        = 6U,  /**< 2-pin push-pull mode with separate LPI2C slave */
    LPI2C_CFG_4PIN_PUSH_PULL_INVERTED     = 7U,  /**< 4-pin push-pull mode (inverted outputs) */
} Lpi2c_Ip_PinConfigType;

/** @brief Master NACK reaction configuration
 */
typedef enum
{
    LPI2C_NACK_RECEIVE    = 0U,  /**< Receive ACK and NACK normally */
    LPI2C_NACK_IGNORE     = 1U,  /**< Treat a received NACK as if it was an ACK */
} Lpi2c_Ip_NackConfigType;

/** @brief Slave address configuration
 */
typedef enum
{
    LPI2C_SLAVE_ADDR_MATCH_0_7BIT              = 0U,  /**< Address match 0 (7-bit) */
    LPI2C_SLAVE_ADDR_MATCH_0_10BIT             = 1U,  /**< Address match 0 (10-bit) */
    LPI2C_SLAVE_ADDR_MATCH_0_7BIT_OR_1_7BIT    = 2U,  /**< Address match 0 (7-bit) or Address match 1 (7-bit) */
    LPI2C_SLAVE_ADDR_MATCH_0_10BIT_OR_1_10BIT  = 3U,  /**< Address match 0 (10-bit) or Address match 1 (10-bit) */
    LPI2C_SLAVE_ADDR_MATCH_0_7BIT_OR_1_10BIT   = 4U,  /**< Address match 0 (7-bit) or Address match 1 (10-bit) */
    LPI2C_SLAVE_ADDR_MATCH_0_10BIT_OR_1_7BIT   = 5U,  /**< Address match 0 (10-bit) or Address match 1 (7-bit) */
    LPI2C_SLAVE_ADDR_MATCH_RANGE_7BIT          = 6U,  /**< From Address match 0 (7-bit) to Address match 1 (7-bit) */
    LPI2C_SLAVE_ADDR_MATCH_RANGE_10BIT         = 7U,  /**< From Address match 0 (10-bit) to Address match 1 (10-bit) */
} Lpi2c_Ip_SlaveAddressConfigType;

/** @brief Slave NACK reaction configuration
 */
typedef enum
{
    LPI2C_SLAVE_NACK_END_TRANSFER       = 0U,  /**< Slave will end transfer when NACK detected */
    LPI2C_SLAVE_NACK_CONTINUE_TRANSFER  = 1U,  /**< Slave will not end transfer when NACK detected */
} Lpi2c_Ip_SlaveNackConfigType;

/** @brief Slave ACK transmission options
 */
typedef enum
{
    LPI2C_SLAVE_TRANSMIT_ACK   = 0U,  /**< Transmit ACK for received word  */
    LPI2C_SLAVE_TRANSMIT_NACK  = 1U,  /**< Transmit NACK for received word */
} Lpi2c_Ip_SlaveNackTransmitType;

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @name Configuration
 * @{
 */

/**
 * @brief Get the size of the Master Receive FIFO
 *
 * @details This function returns the size of the Master Receive FIFO, always a power of 2.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  Master Receive FIFO Size
 */
static inline uint16  LPI2C_Get_MasterRxFIFOSize(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->PARAM;

    Tmp = (Tmp & LPI2C_PARAM_MRXFIFO_MASK) >> LPI2C_PARAM_MRXFIFO_SHIFT;
    Tmp = 1UL << Tmp;     /* RX FIFO size = 2^MRXFIFO */
    return (uint16)Tmp;
}


/**
 * @brief Get the size of the Master Transmit FIFO
 *
 * @details This function returns the size of the Master Transmit FIFO, always a power of 2.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  Master Transmit FIFO Size
 */
static inline uint16 LPI2C_Get_MasterTxFIFOSize(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->PARAM;

    Tmp = (Tmp & LPI2C_PARAM_MTXFIFO_MASK) >> LPI2C_PARAM_MTXFIFO_SHIFT;
    Tmp = 1UL << Tmp;      /* TX FIFO size = 2^MTXFIFO */
    return (uint16)Tmp;
}


/**
 * @brief Reset the master receive FIFO
 *
 * @details This function empties the receive FIFO of the LPI2C master.
 *
 * @param BaseAddr[in]  base address of the LPI2C module
 */
static inline void LPI2C_Reset_MasterRxFIFOCmd(LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MCR;
    RegValue &= (~(LPI2C_MCR_RRF_MASK));
    RegValue |= LPI2C_MCR_RRF(1u);
    BaseAddr->MCR = (uint32)RegValue;
}

/**
 * @brief Reset the master transmit FIFO
 *
 * @details This function empties the transmit FIFO of the LPI2C master.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Reset_MasterTxFIFOCmd(LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MCR;
    RegValue &= (~(LPI2C_MCR_RTF_MASK));
    RegValue |= LPI2C_MCR_RTF(1u);
    BaseAddr->MCR = (uint32)RegValue;
}

/**
 * @brief Set/clear the master reset command
 *
 * @details Calling this function with enable parameter set to true resets all internal
 * master logic and registers, except the Master Control Register. The reset state
 * persists until this function is called with enable parameter set to false.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies the reset state of the LPI2C master logic
 */
static inline void LPI2C_Set_MasterSoftwareReset(LPI2C_Type *BaseAddr,
                                                 boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->MCR;
    RegValue &= (~(LPI2C_MCR_RST_MASK));
    RegValue |= LPI2C_MCR_RST(ENABLE_BIT(Enable));
    BaseAddr->MCR = (uint32)RegValue;
}

/**
 * @brief Enable or disable the LPI2C master
 *
 * @details This function enables or disables the LPI2C module in master mode. If the module
 * is enabled, the transmit FIFO  is not empty and the I2C bus is idle, then
 * the LPI2C master will immediately initiate a transfer on the I2C bus.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies whether to enable or disable the LPI2C master
 */
static inline void LPI2C_Set_MasterEnable(LPI2C_Type *BaseAddr, boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->MCR;
    RegValue &= (~(LPI2C_MCR_MEN_MASK));
    RegValue |= LPI2C_MCR_MEN(ENABLE_BIT(Enable));
    BaseAddr->MCR = (uint32)RegValue;
}

/**
 * @brief Indicate the availability of receive data
 *
 * @details This function returns true when the number of words in the receive FIFO is greater
 * than the receive FIFO watermark. See function LPI2C_MasterSetRxFIFOWatermark()
 * for configuring the receive FIFO watermark.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  receive Data ready/not ready
 */
static inline boolean LPI2C_Get_MasterReceiveDataReadyEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_RDF_MASK) >> LPI2C_MSR_RDF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Indicate if the LPI2C master requests more data
 *
 * @details This function returns true when the number of words in the transmit FIFO is equal
 * or less than the transmit FIFO watermark. See function LPI2C_Set_MasterTxFIFOWatermark()
 * for configuring the transmit FIFO watermark.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  transmit data requested/not requested
 */
static inline boolean LPI2C_Get_MasterTransmitDataRequestEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_TDF_MASK) >> LPI2C_MSR_TDF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the occurrence of a FIFO error event
 *
 * @details This function returns true if the LPI2C master detects an attempt to send or
 * receive data without first generating a (repeated) START condition. This can
 * occur if the transmit FIFO underflows when the AUTOSTOP bit is set. When this
 * flag is set, the LPI2C master will send a STOP condition (if busy) and will
 * not initiate a new START condition until this flag has been cleared.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of a FIFO error event
 */
static inline boolean LPI2C_Get_MasterFIFOErrorEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_FEF_MASK) >> LPI2C_MSR_FEF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the occurrence of an arbitration lost event
 *
 * @details This function returns true if the LPI2C master detects an arbitration lost
 * condition, as defined by the I2C standard. When this flag sets, the LPI2C
 * master will release the bus (go idle) and will not initiate a new START
 * condition until this flag has been cleared.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of an arbitration lost event
 */
static inline boolean LPI2C_Get_MasterArbitrationLostEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_ALF_MASK) >> LPI2C_MSR_ALF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the occurrence of an unexpected NACK event
 *
 * @details This function returns true if the LPI2C master detects a NACK when
 * transmitting an address or data. If a NACK is expected for a given address
 * (as configured by the command word) then the flag will set if a NACK is not
 * generated. When set, the master will transmit a STOP condition and will not
 * initiate a new START condition until this flag has been cleared.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of an unexpected NACK event
 */
static inline boolean Lpi2c_Ip_Get_MasterNACKDetectEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_NDF_MASK) >> LPI2C_MSR_NDF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the occurrence of an pin low timeout event
 *
 * @details This function returns true if the LPI2C master detects a
 * pin low timeout event. The Pin Low Timeout Flag will set
 * when SCL and/or SDA input is low for more than PINLOW Cycles.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of an pin low timeout event
 */
static inline boolean LPI2C_Get_MasterPinLowTimeoutEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_PLTF_MASK) >> LPI2C_MSR_PLTF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Clear the FIFO error event flag
 *
 * @details This function clears the FIFO error event. This event must be cleared before
 * the LPI2C master can initiate a START condition.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_MasterFIFOErrorEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->MSR = ((uint32)1U << LPI2C_MSR_FEF_SHIFT);
}

/**
 * @brief Clear the arbitration lost event flag
 *
 * @details This function clears the arbitration lost event. This event must be cleared
 * before the LPI2C master can initiate a START condition.
 *
 * @param BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_MasterArbitrationLostEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->MSR = ((uint32)1U << LPI2C_MSR_ALF_SHIFT);
}

/**
 * @brief Clear the unexpected NACK event flag
 *
 * @details This function clears the unexpected NACK event. This event must be cleared
 * before the LPI2C master can initiate a START condition.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_MasterNACKDetectEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->MSR = ((uint32)1U << LPI2C_MSR_NDF_SHIFT);
}


/**
 * @brief Clear the pin low timeout event flag
 *
 * @details This function clears the pin low timeout event. This event must be cleared
 * before the LPI2C master can initiate a START condition.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_MasterPinLowTimeoutEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->MSR = ((uint32)1U << LPI2C_MSR_PLTF_SHIFT);
}


/**
 * @brief Enable/disable receive data DMA requests
 *
 * @details This function enables or disables generation of Rx DMA requests when Data
 * can be read from the receive FIFO, as configured by the receive FIFO watermark.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies whether to enable or disable DMA requests
 */
static inline void LPI2C_Set_MasterRxDMA(LPI2C_Type *BaseAddr,
                                         boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->MDER;
    RegValue &= (~(LPI2C_MDER_RDDE_MASK));
    RegValue |= LPI2C_MDER_RDDE(ENABLE_BIT(Enable));
    BaseAddr->MDER = (uint32)RegValue;
}

/**
 * @brief Enable/disable transmit data DMA requests
 *
 * @details This function enables or disables generation of Tx DMA requests when Data
 * can be written to the transmit FIFO, as configured by the transmit FIFO watermark.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies whether to enable or disable DMA requests
 */
static inline void LPI2C_Set_MasterTxDMA(LPI2C_Type *BaseAddr,
                                         boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->MDER;
    RegValue &= (~(LPI2C_MDER_TDDE_MASK));
    RegValue |= LPI2C_MDER_TDDE(ENABLE_BIT(Enable));
    BaseAddr->MDER = (uint32)RegValue;
}

/**
 * @brief Enable or disable specified LPI2C master interrupts
 *
 * @details This function can enable or disable one or more master interrupt sources
 * specified by the interrupts parameter.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Interrupts  interrupts to be enabled or disabled;
 *  must be a bitwise or between one or more of the following constants:
 *  - LPI2C_IP_MASTER_DATA_MATCH_INT          - Data Match Interrupt
 *  - LPI2C_IP_MASTER_PIN_LOW_TIMEOUT_INT     - Pin Low Timeout Interrupt
 *  - LPI2C_IP_MASTER_FIFO_ERROR_INT          - FIFO Error Interrupt
 *  - LPI2C_IP_MASTER_ARBITRATION_LOST_INT    - Arbitration Lost Interrupt
 *  - LPI2C_IP_MASTER_NACK_DETECT_INT         - NACK Detect Interrupt
 *  - LPI2C_IP_MASTER_START_DETECT_INT        - START Detect Interrupt
 *  - LPI2C_IP_MASTER_STOP_DETECT_INT         - STOP Detect Interrupt
 *  - LPI2C_IP_MASTER_END_PACKET_INT          - End Packet Interrupt
 *  - LPI2C_IP_MASTER_RECEIVE_DATA_INT        - Receive Data Interrupt
 *  - LPI2C_IP_MASTER_TRANSMIT_DATA_INT       - Transmit Data Interrupt
 * @param Enable  specifies whether to enable or disable specified interrupts
 */
static inline void LPI2C_Set_MasterInt(LPI2C_Type *BaseAddr,
                                       uint32 Interrupts,
                                       boolean Enable)
{
    uint32 Tmp = BaseAddr->MIER;

    if (Enable == TRUE)
    {
        Tmp |= Interrupts;
    }
    else
    {
        Tmp &= ~Interrupts;
    }
    BaseAddr->MIER = Tmp;
}

/**
 * @brief Set the pin mode of the module
 *
 * @details This function sets the pin mode of the module. See type Lpi2c_Ip_PinConfigType for
 * a description of available modes.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration  pin mode of the module
 */
static inline void LPI2C_Set_MasterPinConfig(LPI2C_Type *BaseAddr,
                                             Lpi2c_Ip_PinConfigType Configuration)
{
    uint32 Tmp = BaseAddr->MCFGR1;

    Tmp &= ~(LPI2C_MCFGR1_PINCFG_MASK);
    Tmp |= LPI2C_MCFGR1_PINCFG(Configuration);
    BaseAddr->MCFGR1 = (uint32)Tmp;
}

/**
 * @brief Set the master glitch filter for SDA
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration  pin mode of the module
 */
static inline void LPI2C_Set_MasterGlitchFilterSDA(LPI2C_Type *BaseAddr,
                                                   uint32 Cycles)
{
    uint32 Tmp = BaseAddr->MCFGR2;

    Tmp &= ~(LPI2C_MCFGR2_FILTSDA_MASK);
    Tmp |= LPI2C_MCFGR2_FILTSDA(Cycles);
    BaseAddr->MCFGR2 = (uint32)Tmp;
}

/**
 * @brief Set the master glitch filter for SCL
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration  pin mode of the module
 */
static inline void LPI2C_Set_MasterGlitchFilterSCL(LPI2C_Type *BaseAddr,
                                                   uint32 Cycles)
{
    uint32 Tmp = BaseAddr->MCFGR2;

    Tmp &= ~(LPI2C_MCFGR2_FILTSCL_MASK);
    Tmp |= LPI2C_MCFGR2_FILTSCL(Cycles);
    BaseAddr->MCFGR2 = (uint32)Tmp;
}

/**
 * @brief Set the slave glitch filter for SDA
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration  pin mode of the module
 */
static inline void LPI2C_Set_SlaveGlitchFilterSDA(LPI2C_Type *BaseAddr,
                                                  uint32 Cycles)
{
    uint32 Tmp = BaseAddr->SCFGR2;

    Tmp &= ~(LPI2C_SCFGR2_FILTSDA_MASK);
    Tmp |= LPI2C_SCFGR2_FILTSDA(Cycles);
    BaseAddr->SCFGR2 = (uint32)Tmp;
}

/**
 * @brief Set the slave glitch filter for SCL
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration  pin mode of the module
 */
static inline void LPI2C_Set_SlaveGlitchFilterSCL(LPI2C_Type *BaseAddr,
                                                  uint32 Cycles)
{
    uint32 Tmp = BaseAddr->SCFGR2;

    Tmp &= ~(LPI2C_SCFGR2_FILTSCL_MASK);
    Tmp |= LPI2C_SCFGR2_FILTSCL(Cycles);
    BaseAddr->SCFGR2 = (uint32)Tmp;
}


/**
 * @brief Set the pin low timeout
 *
 * @details This function configures the pin low timeout
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Timeout timeout period in clock cycles
 */
static inline void LPI2C_Set_MasterPinLowTimeout(LPI2C_Type *BaseAddr,
                                                 uint32 Timeout)
{
    uint32 Tmp = BaseAddr->MCFGR3;

    Tmp &= ~(LPI2C_MCFGR3_PINLOW_MASK);
    Tmp |= LPI2C_MCFGR3_PINLOW(Timeout);
    BaseAddr->MCFGR3 = (uint32)Tmp;
}

/**
 * @brief Set pin low timeout for SDA or SCL
 *
 * @details This function configures the pin low timeout only for SCL or, for SCL or SDA.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration "0" - Pin Low Timeout Flag will set only for SCL, "1" - Pin Low Timeout Flag
                             will set if either SCL or SDA is low longer than the configured timeout.
 */
static inline void LPI2C_Set_MasterPinLowTimeoutConfiguration(LPI2C_Type *BaseAddr,
                                                              boolean Configuration)
{
    uint32 Tmp = BaseAddr->MCFGR1;

    Tmp &= ~(LPI2C_MCFGR1_TIMECFG_MASK);
    Tmp |= LPI2C_MCFGR1_TIMECFG(ENABLE_BIT(Configuration));
    BaseAddr->MCFGR1 = (uint32)Tmp;
}

/**
 * @brief Set the bus idle timeout
 *
 * @details This function configures the bus idle timeout
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Timeout  timeout period in clock cycles
 */
static inline void LPI2C_Set_MasterBusIdleTimeout(LPI2C_Type *BaseAddr,
                                                  uint32 Timeout)
{
    uint32 Tmp = BaseAddr->MCFGR2;

    Tmp &= ~(LPI2C_MCFGR2_BUSIDLE_MASK);
    Tmp |= LPI2C_MCFGR2_BUSIDLE(Timeout);
    BaseAddr->MCFGR2 = Tmp;
}

/**
 * @brief Configure the reaction of the module on NACK reception
 *
 * @details This function configures how the LPI2C master reacts when receiving a NACK. NACK responses can
 * be treated normally or ignored. In Ultra-Fast mode it is necessary to configure the module to
 * ignore NACK responses.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Configuration  set reaction of the module on NACK reception
 */
static inline void LPI2C_Set_MasterNACKConfig(LPI2C_Type *BaseAddr,
                                              Lpi2c_Ip_NackConfigType Configuration)
{
    uint32 RegValue = (uint32)BaseAddr->MCFGR1;
    RegValue &= (~(LPI2C_MCFGR1_IGNACK_MASK));
    RegValue |= LPI2C_MCFGR1_IGNACK(Configuration);
    BaseAddr->MCFGR1 = (uint32)RegValue;
}

/**
 * @brief Configure the LPI2C master prescaler
 *
 * @details This function configures the clock prescaler used for all LPI2C master logic,
 * except the digital glitch filters.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Prescaler  LPI2C master prescaler
 */
static inline void LPI2C_Set_MasterPrescaler(LPI2C_Type *BaseAddr,
                                             Lpi2c_Ip_MasterPrescalerType Prescaler)
{
    uint32 Tmp = BaseAddr->MCFGR1;

    Tmp &= ~(LPI2C_MCFGR1_PRESCALE_MASK);
    Tmp |= LPI2C_MCFGR1_PRESCALE(Prescaler);
    BaseAddr->MCFGR1 = Tmp;
}

/**
 * @brief Return the LPI2C master prescaler
 *
 * @details This function returns the currently configured clock prescaler.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  LPI2C master prescaler
 */
static inline uint32 LPI2C_Get_MasterPrescaler(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MCFGR1;

    Tmp = (Tmp & LPI2C_MCFGR1_PRESCALE_MASK) >> LPI2C_MCFGR1_PRESCALE_SHIFT;
    return Tmp;
}

/**
 * @brief Return the configured minimum clock high period
 *
 * @details This function returns the currently configured value for clock high period.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  minimum clock high period
 */
static inline uint8 LPI2C_Get_MasterClockHighPeriod(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MCCR0;

    Tmp = (Tmp & LPI2C_MCCR0_CLKHI_MASK) >> LPI2C_MCCR0_CLKHI_SHIFT;
    return (uint8)Tmp;
}

/**
 * @brief Set the minimum clock high period
 *
 * @details This function configures the minimum number of cycles (minus one) that the
 * SCL clock is driven high by the master. The SCL high time is extended by the
 * time it takes to detect a rising edge on the external SCL pin. Ignoring any
 * additional board delay due to external loading, this is equal to
 * (2 + FILTSCL) / 2^PRESCALE cycles.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param Value  minimum clock high period
 */
static inline void LPI2C_Set_MasterClockHighPeriod(LPI2C_Type *BaseAddr,
                                                   uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR0;

    Tmp &= ~(LPI2C_MCCR0_CLKHI_MASK);
    Tmp |= LPI2C_MCCR0_CLKHI(Value);
    BaseAddr->MCCR0 = Tmp;
}

/**
 * @brief Set the Data hold time for SDA
 *
 * @details  This function sets the minimum number of cycles (minus one) that is used as the
 * Data hold time for SDA. Must be configured less than the minimum SCL low period.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  Value of the data hold time for SDA
 */
static inline void LPI2C_Set_MasterDataValidDelay(LPI2C_Type *BaseAddr,
                                                  uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR0;

    Tmp &= ~(LPI2C_MCCR0_DATAVD_MASK);
    Tmp |= LPI2C_MCCR0_DATAVD(Value);
    BaseAddr->MCCR0 = Tmp;
}

/**
 * @brief Set the setup and hold delay for a START / STOP condition
 *
 * @details This function configures the Minimum number of cycles (minus one) that is used
 * by the master as the setup and hold time for a (repeated) START condition and setup
 * time for a STOP condition. The setup time is extended by the time it takes to detect
 * a rising edge on the external SCL pin. Ignoring any additional board delay due to
 * external loading, this is equal to (2 + FILTSCL) / 2^PRESCALE cycles.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  setup and hold time for a START / STOP condition
 */
static inline void LPI2C_Set_MasterSetupHoldDelay(LPI2C_Type *BaseAddr,
                                                  uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR0;

    Tmp &= ~(LPI2C_MCCR0_SETHOLD_MASK);
    Tmp |= LPI2C_MCCR0_SETHOLD(Value);
    BaseAddr->MCCR0 = Tmp;
}

/**
 * @brief Set the minimum clock low period
 *
 * @details This function configures the minimum number of cycles (minus one) that the
 * SCL clock is driven low by the master. This value is also used for the
 * minimum bus free time between a STOP and a START condition.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  minimum clock low period
 */
static inline void LPI2C_Set_MasterClockLowPeriod(LPI2C_Type *BaseAddr,
                                                  uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR0;

    Tmp &= ~(LPI2C_MCCR0_CLKLO_MASK);
    Tmp |= LPI2C_MCCR0_CLKLO(Value);
    BaseAddr->MCCR0 = Tmp;
}

/**
 * @brief Return the configured minimum clock low period
 *
 * @details This function returns the currently configured value for clock low period.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  minimum clock low period
 */
static inline uint8 LPI2C_Get_MasterClockLowPeriod(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MCCR0;

    Tmp = (Tmp & LPI2C_MCCR0_CLKLO_MASK) >> LPI2C_MCCR0_CLKLO_SHIFT;
    return (uint8)Tmp;
}

/**
 * @brief Set the Data hold time for SDA in high-speed mode
 *
 * @details This function sets the minimum number of cycles (minus one) that is used as the
 * Data hold time for SDA in High-Speed mode. Must be configured less than the
 * minimum SCL low period.
 * This setting only has effect during High-Speed mode transfers.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  Value of the data hold time for SDA
 */
static inline void LPI2C_Set_MasterDataValidDelayHS(LPI2C_Type *BaseAddr,
                                                    uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR1;

    Tmp &= ~(LPI2C_MCCR1_DATAVD_MASK);
    Tmp |= LPI2C_MCCR1_DATAVD(Value);
    BaseAddr->MCCR1 = Tmp;
}


/**
 * @brief Set the setup and hold time for a START / STOP condition in high-speed mode
 *
 * @details This function configures the Minimum number of cycles (minus one) that is used
 * by the master as the setup and hold time for a (repeated) START condition and setup
 * time for a STOP condition. The setup time is extended by the time it takes to detect
 * a rising edge on the external SCL pin. Ignoring any additional board delay due to
 * external loading, this is equal to (2 + FILTSCL) / 2^PRESCALE cycles.
 * This setting only has effect during High-Speed mode transfers.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  setup and hold time for a START / STOP condition
 */
static inline void LPI2C_Set_MasterSetupHoldDelayHS(LPI2C_Type *BaseAddr,
                                                    uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR1;

    Tmp &= ~(LPI2C_MCCR1_SETHOLD_MASK);
    Tmp |= LPI2C_MCCR1_SETHOLD(Value);
    BaseAddr->MCCR1 = Tmp;
}


/**
 * @brief Set the minimum clock high period in high-speed mode
 *
 * @details This function configures the minimum number of cycles (minus one) that the
 * SCL clock is driven high by the master. The SCL high time is extended by the
 * time it takes to detect a rising edge on the external SCL pin. Ignoring any
 * additional board delay due to external loading, this is equal to
 * (2 + FILTSCL) / 2^PRESCALE cycles.
 * This setting only has effect during High-Speed mode transfers.
 *
 * @param BaseAddr  base address of the LPI2C module
 * @param Value  minimum clock high period
 */
static inline void LPI2C_Set_MasterClockHighPeriodHS(LPI2C_Type *BaseAddr,
                                                     uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR1;

    Tmp &= ~(LPI2C_MCCR1_CLKHI_MASK);
    Tmp |= LPI2C_MCCR1_CLKHI(Value);
    BaseAddr->MCCR1 = Tmp;
}

/**
 * @brief Return the configured minimum clock high period in high-speed mode
 *
 * @details This function returns the currently configured value for clock high period
 * in high-speed mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  minimum clock high period
 */
static inline uint8 LPI2C_Get_MasterClockHighPeriodHS(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MCCR1;

    Tmp = (Tmp & LPI2C_MCCR1_CLKHI_MASK) >> LPI2C_MCCR1_CLKHI_SHIFT;
    return (uint8)Tmp;
}

/**
 * @brief Set the minimum clock low period in high-speed mode
 *
 * @details This function configures the minimum number of cycles (minus one) that the
 * SCL clock is driven low by the master. This value is also used for the
 * minimum bus free time between a STOP and a START condition.
 * This setting only has effect during High-Speed mode transfers.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  minimum clock low period
 */
static inline void LPI2C_Set_MasterClockLowPeriodHS(LPI2C_Type *BaseAddr,
                                                    uint8 Value)
{
    uint32 Tmp = BaseAddr->MCCR1;

    Tmp &= ~(LPI2C_MCCR1_CLKLO_MASK);
    Tmp |= LPI2C_MCCR1_CLKLO(Value);
    BaseAddr->MCCR1 = Tmp;
}

/**
 * @brief Return the configured minimum clock low period in high-speed mode
 *
 * @details This function returns the currently configured value for clock low period
 * in high-speed mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  minimum clock low period
 */
static inline uint8 LPI2C_Get_MasterClockLowPeriodHS(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MCCR1;

    Tmp = (Tmp & LPI2C_MCCR1_CLKLO_MASK) >> LPI2C_MCCR1_CLKLO_SHIFT;
    return (uint8)Tmp;
}

/**
 * @brief Set the receive FIFO watermark
 *
 * @details This function configures the receive FIFO watermark. Whenever the number of words in the receive
 * FIFO is greater than the receive FIFO watermark, a receive data ready event is generated.
 * Writing a value equal or greater than the FIFO size will be truncated.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  number of words in the receive FIFO that will cause the receive Data flag to be set
 */
static inline void LPI2C_Set_MasterRxFIFOWatermark(LPI2C_Type *BaseAddr,
                                                   uint16 Value)
{
    uint32 Tmp = BaseAddr->MFCR;

    Tmp &= ~(LPI2C_MFCR_RXWATER_MASK);
    Tmp |= LPI2C_MFCR_RXWATER(Value);
    BaseAddr->MFCR = Tmp;
}

/**
 * @brief Return the configured receive FIFO watermark
 *
 * @details This function returns the currently configured value for receive FIFO watermark
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  number of words in the receive FIFO that will cause the receive data flag to be set
 */
static inline uint16 LPI2C_Get_MasterRxFIFOWatermark(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MFCR;

    Tmp = (Tmp & LPI2C_MFCR_RXWATER_MASK) >> LPI2C_MFCR_RXWATER_SHIFT;
    return (uint16)Tmp;
}

/**
 * @brief Set the transmit FIFO watermark
 *
 * @details This function configures the transmit FIFO watermark. Whenever the number of words in the transmit
 * FIFO is greater than the transmit FIFO watermark, a transmit data request event is generated.
 * Writing a value equal or greater than the FIFO size will be truncated.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Value  number of words in the transmit FIFO that will cause the transmit Data flag to be set
 */
static inline void LPI2C_Set_MasterTxFIFOWatermark(LPI2C_Type *BaseAddr,
                                                   uint16 Value)
{
    uint32 Tmp = BaseAddr->MFCR;

    Tmp &= ~(LPI2C_MFCR_TXWATER_MASK);
    Tmp |= LPI2C_MFCR_TXWATER(Value);
    BaseAddr->MFCR = Tmp;
}

/**
 * @brief Return the number of words in the receive FIFO
 *
 * @details This function returns the number of words currently available in the receive FIFO.
 *
 * @param BaseAddr  base address of the LPI2C module
 * @return  the number of words in the receive FIFO
 */
static inline uint16 LPI2C_Get_MasterRxFIFOCount(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MFSR;

    Tmp = (Tmp & LPI2C_MFSR_RXCOUNT_MASK) >> LPI2C_MFSR_RXCOUNT_SHIFT;
    return (uint16)Tmp;
}

/**
 * @brief Return the number of words in the transmit FIFO
 *
 * @details This function returns the number of words currently available in the transmit FIFO.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  the number of words in the transmit FIFO
 */
static inline uint16 LPI2C_Get_MasterTxFIFOCount(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MFSR;

    Tmp = (Tmp & LPI2C_MFSR_TXCOUNT_MASK) >> LPI2C_MFSR_TXCOUNT_SHIFT;
    return (uint16)Tmp;
}

/**
 * @brief Provide commands and data for the LPI2C master
 *
 * @details This function stores commands and data in the transmit FIFO and increments the FIFO
 * write pointer.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Cmd  command for the LPI2C master
 * @param[in] Data  data for the LPI2C master
 */
static inline void LPI2C_Cmd_MasterTransmit(LPI2C_Type *BaseAddr,
                                            Lpi2c_Ip_MasterCommandType Cmd,
                                            uint8 Data)
{
    BaseAddr->MTDR = ((uint32)Cmd << 8U) + (uint32)Data;
}

/**
 * @brief Return the received data
 *
 * @details This function returns data received by the I2C master that has not been discarded
 * due to data match settings or active command, and increments the FIFO read pointer.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  Data received by the LPI2C master
 */
static inline uint8 LPI2C_Get_MasterRxData(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->MRDR;

    Tmp = (Tmp & LPI2C_MRDR_DATA_MASK) >> LPI2C_MRDR_DATA_SHIFT;
    return (uint8)Tmp;
}

/**
 * @brief Enable or disable the LPI2C slave
 *
 * @details  This function enables or disables the LPI2C module in slave mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies whether to enable or disable the LPI2C slave
 */
static inline void LPI2C_Set_SlaveEnable(LPI2C_Type *BaseAddr,
                                         boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCR;

    RegValue &= (~(LPI2C_SCR_SEN_MASK));
    RegValue |= LPI2C_SCR_SEN((uint32)((Enable == TRUE)?1U:0U));
    BaseAddr->SCR = (uint32)RegValue;
}

/**
 * @brief Set/clear the slave reset command
 *
 * @details Calling this function with enable parameter set to true will perform a software
 * reset of the LPI2C slave.
 *
 * @param BaseAddr  base address of the LPI2C module
 * @param Enable  specifies the reset state of the LPI2C slave logic
 */
static inline void LPI2C_Set_SlaveSoftwareReset(LPI2C_Type *BaseAddr,
                                                boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCR;
    RegValue &= (~(LPI2C_SCR_RST_MASK));
    RegValue |= LPI2C_SCR_RST(ENABLE_BIT(Enable));
    BaseAddr->SCR = (uint32)RegValue;
}

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
/**
 * @brief Check the detection of a FIFO overflow or underflow
 *
 * @details This function checks for the occurrence of a slave FIFO overflow or underflow.
 * This event can only occur if clock stretching is disabled.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of a FIFO overflow or underflow
 */
static inline boolean LPI2C_Get_SlaveFIFOErrorEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_FEF_MASK) >> LPI2C_SSR_FEF_SHIFT;
    return (boolean)RegValue;
}
#endif

/**
 * @brief Check the detection of a bit error
 *
 * @details This function checks for the occurrence of a bit error event. This event occurs
 * if the LPI2C slave transmits a logic one and detects a logic zero on the I2C bus. The
 * slave will ignore the rest of the transfer until the next (repeated) START condition.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of a bit error
 */
static inline boolean LPI2C_Get_SlaveBitErrorEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_BEF_MASK) >> LPI2C_SSR_BEF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the detection of a STOP condition
 *
 * @details This function checks for the detection of a STOP condition, after the LPI2C slave
 * matched the last address byte.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of a STOP condition
 */
static inline boolean LPI2C_Get_SlaveSTOPDetectEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_SDF_MASK) >> LPI2C_SSR_SDF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

#ifdef LPI2C_IP_FEATURE_DETECT_START_CONDITION
/**
 * @brief This function sets the configuration for detect start condiontion.
 *
 * @details This function sets the STARTCFG bit for MCFGR1 register.
 *
 * @param[in] BaseAddr  Base address of the LPI2C module
 * @param[in] MasterEnable  Mask of the STARTCFG bit to be enabled/disabled
 */
static inline void LPI2C_Set_MasterDetectStartEvent(LPI2C_Type *BaseAddr,
                                                    uint32 MasterEnable)
{
    uint32 Temp = (uint32)BaseAddr->MCFGR1;

    Temp |= MasterEnable;

    BaseAddr->MCFGR1 = (uint32)Temp;
}

/**
 * @brief This function clear bit Start Flag
 *
 * @details This function clears the bit Start Flag event.
 *
 * @param[in] BaseAddr  Base address of the LPI2C module
 */
static inline void LPI2C_Clear_MasterStartEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->MSR = ((uint32)1U << LPI2C_MSR_STF_SHIFT);
}

/**
 * @brief Check the occurrence of an Start event
 *
 * @details This function returns true if the LPI2C master detects a Start event.
 *
 * @param[in] BaseAddr  Base address of the LPI2C module
 * @return  Indication of Start event
 */
static inline boolean LPI2C_Get_MasterStartEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MSR;

    RegValue = (RegValue & LPI2C_MSR_STF_MASK) >> LPI2C_MSR_STF_SHIFT;
    return (boolean)( (RegValue == 1U) ? TRUE:FALSE );
}
#endif /* LPI2C_IP_FEATURE_DETECT_START_CONDITION */

/**
 * @brief Check the detection of a repeated START condition
 *
 * @details This function checks for the detection of a repeated START condition, after
 * the LPI2C slave matched the last address byte. This event does not occur
 * when the slave first detects a START condition.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of a repeated START condition
 */
static inline boolean LPI2C_Get_SlaveRepeatedStartEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_RSF_MASK) >> LPI2C_SSR_RSF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the validity of the Address Status Register
 *
 * @details This function checks for the detection of a valid address. The event is
 * cleared by reading the address - see function LPI2C_Get_SlaveReceivedAddr().
 * It can also be cleared by reading the data register, when data register has
 * been configured to allow address reads.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of the validity of the Address Status Register
 */
static inline boolean LPI2C_Get_SlaveAddressValidEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_AVF_MASK) >> LPI2C_SSR_AVF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check the availability of receive data
 *
 * @details This function checks for the availability of data received by the I2C slave.
 * The event is cleared by reading the received data - see function
 * LPI2C_Get_SlaveData(). The event is not cleared by calling
 * LPI2C_Get_SlaveData() if the data register is configured to allow address
 * reads and an address valid event is active.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of receive data availability
 */
static inline boolean LPI2C_Get_SlaveReceiveDataEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_RDF_MASK) >> LPI2C_SSR_RDF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

/**
 * @brief Check if transmit data is requested
 *
 * @details This function checks if the LPI2C slave requests data to transmit. The
 * event is cleared by providing transmit data - see function
 * LPI2C_Transmit_SlaveData(). The event can also be automatically cleared
 * if the LPI2C module detects a NACK or a repeated START or STOP condition
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  indication of a transmit data request
 */
static inline boolean LPI2C_Get_SlaveTransmitDataEvent(const LPI2C_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SSR;

    RegValue = (RegValue & LPI2C_SSR_TDF_MASK) >> LPI2C_SSR_TDF_SHIFT;
    return (boolean)((RegValue == 1U)?TRUE:FALSE);
}

#if (LPI2C_IP_HAS_ULTRA_FAST_MODE)
/**
 * @brief Clear the FIFO overflow or underflow flag
 *
 * @details This function clears the FIFO overflow or underflow event.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_SlaveFIFOErrorEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->SSR = ((uint32)1U << LPI2C_SSR_FEF_SHIFT);
}
#endif

/**
 * @brief Clear bit error flag
 *
 * @details This function clears the bit error event.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_SlaveBitErrorEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->SSR = ((uint32)1U << LPI2C_SSR_BEF_SHIFT);
}

/**
 * @brief Clear the STOP detect flag
 *
 * @details This function clears the STOP detect event.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_SlaveSTOPDetectEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->SSR = ((uint32)1U << LPI2C_SSR_SDF_SHIFT);
}

/**
 * @brief Clear the repeated START detect flag
 *
 * @details This function clears the repeated START detect event.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void LPI2C_Clear_SlaveRepeatedStartEvent(LPI2C_Type *BaseAddr)
{
    BaseAddr->SSR = ((uint32)1U << LPI2C_SSR_RSF_SHIFT);
}

/**
 * @brief Enable or disable specified LPI2C slave interrupts
 *
 * @details This function can enable or disable one or more slave interrupt sources
 * specified by the interrupts parameter.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Interrupts  interrupts to be enabled or disabled;
 *  must be a bitwise or between one or more of the following constants:
 *  - LPI2C_SLAVE_SMBUS_ALERT_RESPONSE  - SMBus Alert Response Interrupt
 *  - LPI2C_SLAVE_GENERAL_CALL          - General Call Interrupt
 *  - LPI2C_SLAVE_ADDRESS_MATCH_1       - Address Match 1 Interrupt
 *  - LPI2C_SLAVE_ADDRESS_MATCH_0       - Address Match 0 Interrupt
 *  - LPI2C_SLAVE_FIFO_ERROR            - FIFO Error Interrupt
 *  - LPI2C_SLAVE_BIT_ERROR             - Bit Error Interrupt
 *  - LPI2C_SLAVE_STOP_DETECT           - STOP Detect Interrupt
 *  - LPI2C_SLAVE_REPEATED_START        - Repeated Start Interrupt
 *  - LPI2C_SLAVE_TRANSMIT_ACK          - Transmit ACK Interrupt
 *  - LPI2C_SLAVE_ADDRESS_VALID         - Address Valid Interrupt
 *  - LPI2C_SLAVE_RECEIVE_DATA          - Receive Data Interrupt
 *  - LPI2C_SLAVE_TRANSMIT_DATA         - Transmit Data Interrupt
 * @param[in] Enable  specifies whether to enable or disable specified interrupts
 */
static inline void LPI2C_Set_SlaveInt(LPI2C_Type *BaseAddr,
                                      uint32 Interrupts,
                                      boolean Enable)
{
    uint32 Tmp = BaseAddr->SIER;

    if (Enable == TRUE)
    {
        Tmp |= Interrupts;
    }
    else
    {
        Tmp &= ~Interrupts;
    }
    BaseAddr->SIER = Tmp;
}

/**
 * @brief Return the state of the specified LPI2C slave interrupt
 *
 * @details This function returns the enabled/disabled state of the slave interrupt
 * source specified by the interrupt parameter.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Interrupts  interrupt for which the check is made;
 *  must be one of the following constants:
 *  - LPI2C_SLAVE_SMBUS_ALERT_RESPONSE  - SMBus Alert Response Interrupt
 *  - LPI2C_SLAVE_GENERAL_CALL          - General Call Interrupt
 *  - LPI2C_SLAVE_ADDRESS_MATCH_1       - Address Match 1 Interrupt
 *  - LPI2C_SLAVE_ADDRESS_MATCH_0       - Address Match 0 Interrupt
 *  - LPI2C_SLAVE_FIFO_ERROR            - FIFO Error Interrupt
 *  - LPI2C_SLAVE_BIT_ERROR             - Bit Error Interrupt
 *  - LPI2C_SLAVE_STOP_DETECT           - STOP Detect Interrupt
 *  - LPI2C_SLAVE_REPEATED_START        - Repeated Start Interrupt
 *  - LPI2C_SLAVE_TRANSMIT_ACK          - Transmit ACK Interrupt
 *  - LPI2C_SLAVE_ADDRESS_VALID         - Address Valid Interrupt
 *  - LPI2C_SLAVE_RECEIVE_DATA          - Receive Data Interrupt
 *  - LPI2C_SLAVE_TRANSMIT_DATA         - Transmit Data Interrupt
 * @return  enable/disable state of specified interrupt
 */
static inline boolean LPI2C_Get_SlaveInt(const LPI2C_Type *BaseAddr,
                                         uint32 Interrupts)
{
    uint32 Tmp = BaseAddr->SIER;
    boolean HasInterrupts;

    if ((Tmp & Interrupts) != (uint32)0U)
    {
        HasInterrupts = TRUE;
    }
    else
    {
        HasInterrupts = FALSE;
    }

    return HasInterrupts;
}

/**
 * @brief Enable/disable slave receive data DMA requests
 *
 * @details This function enables or disables generation of Rx DMA requests when received
 * Data is available.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies whether to enable or disable receive data DMA requests
 */
static inline void LPI2C_Set_SlaveRxDMA(LPI2C_Type *BaseAddr,
                                        boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SDER;
    RegValue &= (~(LPI2C_SDER_RDDE_MASK));
    RegValue |= LPI2C_SDER_RDDE(ENABLE_BIT(Enable));
    BaseAddr->SDER = (uint32)RegValue;
}

/**
 * @brief Enable/disable slave transmit data DMA requests
 *
 * @details This function enables or disables generation of Tx DMA requests when the module
 * requires more data to transmit.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  specifies whether to enable or disable transmit data DMA requests
 */
static inline void LPI2C_Set_SlaveTxDMA(LPI2C_Type *BaseAddr,
                                        boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SDER;
    RegValue &= (~(LPI2C_SDER_TDDE_MASK));
    RegValue |= LPI2C_SDER_TDDE(ENABLE_BIT(Enable));
    BaseAddr->SDER = (uint32)RegValue;
}

/**
 * @brief Control address match configuration
 *
 * @details This function configures the condition that will cause an address match to
 * occur. See type Lpi2c_Ip_SlaveAddressConfigType for a description of available options.
 *
 * @param BaseAddr  base address of the LPI2C module
 * @param Configuration  configures the condition that will cause an address to match
 */
static inline void LPI2C_Set_SlaveAddrConfig(LPI2C_Type *BaseAddr,
                                             Lpi2c_Ip_SlaveAddressConfigType Configuration)
{
    uint32 Tmp = BaseAddr->SCFGR1;

    Tmp &= ~(LPI2C_SCFGR1_ADDRCFG_MASK);
    Tmp |= LPI2C_SCFGR1_ADDRCFG(Configuration);
    BaseAddr->SCFGR1 = Tmp;
}

/**
 * @brief Control detection of the High-speed Mode master code
 *
 * @details This function enables or disables the detection of the High-speed Mode
 * master code of slave address 0000_1XX, but does not cause an address match
 * on this code. When set and any Hs-mode master code is detected, the slave
 * filter and ACK stalls are disabled until the next STOP condition is detected.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  enable/disable the detection of the High-speed Mode master code
 */
static inline void LPI2C_Set_SlaveHighSpeedModeDetect(LPI2C_Type *BaseAddr,
                                                      boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCFGR1;
    RegValue &= (~(LPI2C_SCFGR1_HSMEN_MASK));
    RegValue |= LPI2C_SCFGR1_HSMEN(ENABLE_BIT(Enable));
    BaseAddr->SCFGR1 = (uint32)RegValue;
}

/**
 * @brief Control slave behaviour when NACK is detected
 *
 * @details This function controls the option to ignore received NACKs. When enabled, the
 * LPI2C slave will continue transfers after a NACK is detected. This option is needed
 * for Ultra-Fast mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] NackConfig  slave behaviour when NACK is detected
 */
static inline void LPI2C_Set_SlaveIgnoreNACK(LPI2C_Type *BaseAddr,
                                             Lpi2c_Ip_SlaveNackConfigType NackConfig)
{
    uint32 RegValue = (uint32)BaseAddr->SCFGR1;
    RegValue &= (~(LPI2C_SCFGR1_IGNACK_MASK));
    RegValue |= LPI2C_SCFGR1_IGNACK(NackConfig);
    BaseAddr->SCFGR1 = (uint32)RegValue;
}

/**
 * @brief Enable or disable clock stretching for the sending of the ACK bit
 *
 * @details This function enables or disables SCL clock stretching during slave-transmit address
 * byte(s) and slave-receiver address and data byte(s) to allow software to write the
 * Transmit ACK Register before the ACK or NACK is transmitted. Clock stretching occurs
 * when transmitting the 9th bit and is therefore not compatible with high speed mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  enable or disable clock stretching
 */
static inline void LPI2C_Set_SlaveACKStall(LPI2C_Type *BaseAddr,
                                           boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCFGR1;
    RegValue &= (~(LPI2C_SCFGR1_ACKSTALL_MASK));
    RegValue |= LPI2C_SCFGR1_ACKSTALL(ENABLE_BIT(Enable));
    BaseAddr->SCFGR1 = (uint32)RegValue;
}

/**
 * @brief Enable or disable clock stretching for data transmission
 *
 * @details This function enables or disables SCL clock stretching when the transmit Data
 * flag is set during a slave-transmit transfer. Clock stretching occurs following
 * the 9th bit and is therefore compatible with high speed mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  enable or disable clock stretching
 */
static inline void LPI2C_Set_SlaveTXDStall(LPI2C_Type *BaseAddr,
                                           boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCFGR1;
    RegValue &= (~(LPI2C_SCFGR1_TXDSTALL_MASK));
    RegValue |= LPI2C_SCFGR1_TXDSTALL(ENABLE_BIT(Enable));
    BaseAddr->SCFGR1 = (uint32)RegValue;
}

/**
 * @brief Enable or disable clock stretching for data reception
 *
 * @details This function enables or disables SCL clock stretching when receive Data flag
 * is set during a slave-receive transfer. Clock stretching occurs following the 9th
 * bit and is therefore compatible with high speed mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  enable or disable clock stretching
 */
static inline void LPI2C_Set_SlaveRXStall(LPI2C_Type *BaseAddr,
                                          boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCFGR1;
    RegValue &= (~(LPI2C_SCFGR1_RXSTALL_MASK));
    RegValue |= LPI2C_SCFGR1_RXSTALL(ENABLE_BIT(Enable));
    BaseAddr->SCFGR1 = (uint32)RegValue;
}

/**
 * @brief Enable or disable clock stretching for valid address reception
 *
 * @details This function enables or disables SCL clock stretching when the address valid
 * flag is asserted. Clock stretching only occurs following the 9th bit and is
 * therefore compatible with high speed mode.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable  enable or disable clock stretching
 */
static inline void LPI2C_Set_SlaveAddrStall(LPI2C_Type *BaseAddr,
                                            boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->SCFGR1;
    RegValue &= (~(LPI2C_SCFGR1_ADRSTALL_MASK));    
    RegValue |= LPI2C_SCFGR1_ADRSTALL(ENABLE_BIT(Enable));
    BaseAddr->SCFGR1 = (uint32)RegValue;
}

/**
 * @brief Configure the ADDR0 address for slave address match
 *
 * @details This function configures the ADDR0 value which is used to validate the received
 * slave address. In 10-bit mode, the first address byte is compared to
 * { 11110, ADDR0[10:9] } and the second address byte is compared to ADDR0[8:1].
 * In 7-bit mode, the address is compared to ADDR0[7:1]
 * The formula used for address validation is configured with function
 * LPI2C_Set_SlaveAddrConfig().
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Addr  ADDR0 address for slave address match
 */
static inline void LPI2C_Set_SlaveAddr0(LPI2C_Type *BaseAddr,
                                        uint16 Addr)
{
    uint32 Tmp = BaseAddr->SAMR;

    Tmp &= ~(LPI2C_SAMR_ADDR0_MASK);
    Tmp |= LPI2C_SAMR_ADDR0(Addr);
    BaseAddr->SAMR = Tmp;
}

/**
 * @brief Return the received slave address
 *
 * @details This function returns the received slave address. Reading the address clears
 * the address valid event. The address can be 7-bit or 10-bit (10-bit addresses
 * are prefixed by 11110) and includes the R/W bit in the least significant position.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  received address
 */
static inline uint16 LPI2C_Get_SlaveReceivedAddr(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->SASR;

    Tmp = (Tmp & LPI2C_SASR_RADDR_MASK) >> LPI2C_SASR_RADDR_SHIFT;
    return (uint16)Tmp;
}

/**
 * @brief Configure the ACK/NACK transmission after a received byte
 *
 * @details This function can be used to instruct the LPI2C slave whether to send an ACK or
 * a NACK after receiving a byte. When ACK stall is enabled this function must be
 * called after each matching address and after each received data byte. It can also
 * be called when LPI2C Slave is disabled or idle to configure the default ACK/NACK.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Nack  specifies whether to transmit ACK or NACK
 */
static inline void LPI2C_Set_SlaveTransmitNACK(LPI2C_Type *BaseAddr,
                                               Lpi2c_Ip_SlaveNackTransmitType Nack)
{
    uint32 RegValue = (uint32)BaseAddr->STAR;
    RegValue &= (~(LPI2C_STAR_TXNACK_MASK));
    RegValue |= LPI2C_STAR_TXNACK(Nack);
    BaseAddr->STAR = (uint32)RegValue;
}

/**
 * @brief Provide Data for the LPI2C slave transmitter
 *
 * @details This function provides one byte of data for the LPI2C slave to transmit.
 * Calling this function clears the transmit data event.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Data  data for the LPI2C slave transmitter
 */
static inline void LPI2C_Transmit_SlaveData(LPI2C_Type *BaseAddr,
                                            uint8 Data)
{
    BaseAddr->STDR = (uint32)Data;
}

/**
 * @brief Return the Data received by the LPI2C slave receiver
 *
 * @details This function returns the data received by the I2C slave.
 * Calling this function clears the receive data event.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @return  Data received by the LPI2C slave receiver
 */
static inline uint8 LPI2C_Get_SlaveData(const LPI2C_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->SRDR;

    Tmp = (Tmp & LPI2C_SRDR_DATA_MASK) >> LPI2C_SRDR_DATA_SHIFT;
    return (uint8)Tmp;
}

#ifdef LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE
/**
 * @brief Enable/disable transfer data with relax mode
 *
 * @details This function enables or disables relax mode .
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 * @param[in] Enable    specifies whether to enable or disable relax mode
 */
static inline void LPI2C_Set_RelaxMode(LPI2C_Type *BaseAddr,
                                       boolean Enable)
{
    uint32 RegValue = (uint32)BaseAddr->MCFGR0;
    RegValue &= (~(LPI2C_MCFGR0_RELAX_MASK));
    RegValue |= LPI2C_MCFGR0_RELAX(ENABLE_BIT(Enable));
    BaseAddr->MCFGR0 = (uint32)RegValue;
}
#endif /* LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE */

/**
* @brief      Clear the I2c master flags status.
* @details    Clear the I2c master flags status.
*
* @param[in]  BaseAddr      Table of base addresses for I2c instances
* @param[in]  MasterFlags   Mask of the master flag to be cleared
*
*/
static inline void LPI2C_Clear_MasterStatusFlags(LPI2C_Type * const BaseAddr,
                                                 uint32 MasterFlags)
{
    BaseAddr->MSR = MasterFlags;
}

/**
* @brief      Clear the I2c slave flags status.
* @details    Clear the I2c slave flags status.
*
* @param[in]  BaseAddr      Table of base addresses for I2c instances
* @param[in]  SlaveFlags    Mask of the slave flag to be cleared
*
*/
static inline void LPI2C_Clear_SlaveStatusFlags(LPI2C_Type * const BaseAddr,
                                                uint32 SlaveFlags)
{
    BaseAddr->SSR = SlaveFlags;
}

/**
 * @brief Initializes the LPI2C module to a known state.
 *
 * @details This function initializes all the registers of the LPI2C module to
 * their reset value.
 *
 * @param[in] BaseAddr  base address of the LPI2C module
 */
static inline void Lpi2c_Ip_Init(LPI2C_Type *BaseAddr)
{
    /*
     * The MCR[RST] will reset all master logic and registers to their default state,
     * except for the MCR itself. The SCR[RST] will reset all slave logic and registers
     * to their default state, except for the SCR itself. So we must reset the control
     * registers manually;
     */
    LPI2C_Set_MasterSoftwareReset(BaseAddr, TRUE);
    LPI2C_Set_SlaveSoftwareReset(BaseAddr, TRUE);

    BaseAddr->MCR = 0x0U;
    BaseAddr->SCR = 0x0U;
}


#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @}*/

#endif /* LPI2C_HW_ACCESS_H*/

