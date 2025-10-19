/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Std_Types.h"
#include "Siul2_Dio_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define DIO_VENDOR_ID_CFG_H                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_H    7
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_H 0
#define DIO_SW_MAJOR_VERSION_CFG_H            5
#define DIO_SW_MINOR_VERSION_CFG_H            0
#define DIO_SW_PATCH_VERSION_CFG_H            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Dio_Cfg.h and Std_Types.h file are of the same Autosar version */
    #if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) ||   \
        (DIO_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION)       \
        )
        #error "AUTOSAR Version Numbers of Dio_Cfg.h and Std_Types.h are different"
    #endif
#endif

/* Check if Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h files are of the same vendor.*/
#if (DIO_VENDOR_ID_CFG_H != SIUL2_DIO_IP_VENDOR_ID_CFG_H)
    #error "Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h files are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    != SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (DIO_AR_RELEASE_MINOR_VERSION_CFG_H    != SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (DIO_AR_RELEASE_REVISION_VERSION_CFG_H != SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h are different"
#endif
/* Check if Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h files are of the same Software version.*/
#if ((DIO_SW_MAJOR_VERSION_CFG_H != SIUL2_DIO_IP_SW_MAJOR_VERSION_CFG_H) || \
     (DIO_SW_MINOR_VERSION_CFG_H != SIUL2_DIO_IP_SW_MINOR_VERSION_CFG_H) || \
     (DIO_SW_PATCH_VERSION_CFG_H != SIUL2_DIO_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/**
* @brief      Dio driver Channel Groups configuration switch.
*/
/**
* @brief          Enable or Disable Development Error Detection.
*
* @implements     DIO_DEV_ERROR_DETECT_define
*/
#define DIO_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief          Function @p Dio_GetVersionInfo() enable switch.
*
* @implements     DIO_VERSION_INFO_API_define
*/
#define DIO_VERSION_INFO_API           (STD_ON)

/**
* @brief          Function @p Dio_FlipChannel() enable switch.
*/
#define DIO_FLIP_CHANNEL_API           (STD_ON)

/**
* @brief          Function @p Dio_MaskedWritePort() enable switch.
*/
#define DIO_MASKEDWRITEPORT_API           (STD_ON)
/**
* @brief          Platform specific define stating if mapping of port bits over port pins is reversed.
*/
#define DIO_REVERSED_MAPPING_OF_PORT_BITS_OVER_PORT_PINS    (STD_ON)

/**
* @brief          Reversed port functionality enable switch.
*
* @implements DIO_REVERSEPORTBITS_define
*/
#define DIO_REVERSEPORTBITS           (STD_ON)

/**
* @brief          Undefined pins masking enable switch.
*/
#define DIO_READZERO_UNDEFINEDPORTS           (STD_OFF)
/**
* @brief Enable/Disable MultiPartition function from the driver
*/
#define DIO_MULTIPARTITION_ENABLED          (STD_OFF)

/**
* @brief          Number of implemented ports.
*
* @note           Used for channel, port and channel group validation.
*/
#define DIO_NUM_PORTS_U16               ((uint16)0xe)

/**
* @brief          The number of partition on the port
*
* @note           Used for port validation.
*/
#define DIO_PORT_PARTITION_U16          ((uint16)14U)

/**
* @brief          Number of channels in a port.
*
* @note           Used for channel, port and channel group validation.
*/
#define DIO_NUM_CHANNELS_PER_PORT_U16   ((uint16)((uint16)sizeof(Dio_PortLevelType) * 0x8U))

/**
* @brief          Number of channels available on the implemented ports.
*
* @note           Used for channel validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NUM_CHANNELS_U16            ((uint16)154U)
#endif


/**
* @brief The number of partition on the channel.
*
* @note           Used for channel validation.
*/
#define DIO_CHANNEL_PARTITION_U16           ((uint16)155U)

/**
* @brief          Mask representing no available channels on a port.
*
* @note           Used for channel validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NO_AVAILABLE_CHANNELS_U16   ((Dio_PortLevelType)0x0U)
#endif

/**
* @brief          Mask representing the maximum valid offset for a channel group.
*
* @note           Used for channel group validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_MAX_VALID_OFFSET_U8         ((uint8)0xFU)
#endif

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*   @note    Currently, no register protection mechanism is used for Dio driver.
*/
#define DIO_USER_MODE_SOFT_LOCKING      (STD_OFF)

/**
* @brief          Dio driver Pre-Compile configuration switch.
*/
#define DIO_PRECOMPILE_SUPPORT

/**
* @brief Support for User mode.
*        If this parameter has been configured to STD_ON, the Dio driver code can be executed from both supervisor and user mode.
*/

#define DIO_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/**
* @brief Support for REG_PROT in SIUL2 IP.
*        If the current platform implements REG_PROT for SIUL2 IP, this parameter will be defined, and will enable REG_PROT configuration for SIUL2 IP in DIO drvier
*/
#define DIO_SIUL2_REG_PROT_AVAILABLE    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef DIO_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Dio in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef DIO_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief Number of SIUL2 instances on the platform.
*/
#define DIO_NUM_SIUL2_INSTANCES_U8      ((uint8)1)

/**
* @brief List of identifiers for each of the SIUL2 instances on the platform
*/
#define DIO_SIUL2_0_U8        ((uint8)0)

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief          Symbolic name for the configuration Dio_ConfigPC.
*/
#define Dio_ConfigPC    (Dio_Config)

/* ========== DioConfig ========== */

/* ---------- PTA_L ---------- */

/**
* @brief          Symbolic name for the port PTA_L.
*/
#define DioConf_DioPort_PTA_L  ((uint8)0x00U)
/**
* @brief          Symbolic name for the channel lpHSD3_IN0_PTA0.
*
*/
#define DioConf_DioChannel_lpHSD3_IN0_PTA0  ((uint16)0x0000U)
/**
* @brief          Symbolic name for the channel lpHSD4_IN3_PTA1.
*
*/
#define DioConf_DioChannel_lpHSD4_IN3_PTA1  ((uint16)0x0001U)
/**
* @brief          Symbolic name for the channel lpHSD5_IN1_PTA2.
*
*/
#define DioConf_DioChannel_lpHSD5_IN1_PTA2  ((uint16)0x0002U)
/**
* @brief          Symbolic name for the channel lpHSD5_DSEL0_PTA3.
*
*/
#define DioConf_DioChannel_lpHSD5_DSEL0_PTA3  ((uint16)0x0003U)
/**
* @brief          Symbolic name for the channel ESP32S3_EN.
*
*/
#define DioConf_DioChannel_ESP32S3_EN  ((uint16)0x0008U)
/**
* @brief          Symbolic name for the channel ESP32S3_EN_RESET.
*
*/
#define DioConf_DioChannel_ESP32S3_EN_RESET  ((uint16)0x0009U)
/**
* @brief          Symbolic name for the channel hpHSD6_IN0_PTA12.
*
*/
#define DioConf_DioChannel_hpHSD6_IN0_PTA12  ((uint16)0x000bU)
/* ---------- PTA_H ---------- */

/**
* @brief          Symbolic name for the port PTA_H.
*/
#define DioConf_DioPort_PTA_H  ((uint8)0x01U)
/**
* @brief          Symbolic name for the channel hpHSD2_IN0_PTA17.
*
*/
#define DioConf_DioChannel_hpHSD2_IN0_PTA17  ((uint16)0x0011U)
/**
* @brief          Symbolic name for the channel hpHSD6_IN1_PTA18.
*
*/
#define DioConf_DioChannel_hpHSD6_IN1_PTA18  ((uint16)0x0012U)
/**
* @brief          Symbolic name for the channel hpHSD5_IN0_PTA19.
*
*/
#define DioConf_DioChannel_hpHSD5_IN0_PTA19  ((uint16)0x0013U)
/**
* @brief          Symbolic name for the channel hpHSD4_DSEL_PTA20.
*
*/
#define DioConf_DioChannel_hpHSD4_DSEL_PTA20  ((uint16)0x0014U)
/**
* @brief          Symbolic name for the channel hpHSD5_IN1_PTA21.
*
*/
#define DioConf_DioChannel_hpHSD5_IN1_PTA21  ((uint16)0x0015U)
/**
* @brief          Symbolic name for the channel hpHSD3_IN1_PTA27.
*
*/
#define DioConf_DioChannel_hpHSD3_IN1_PTA27  ((uint16)0x001bU)
/**
* @brief          Symbolic name for the channel Vvar4_Ctrl_PTA28.
*
*/
#define DioConf_DioChannel_Vvar4_Ctrl_PTA28  ((uint16)0x001cU)
/**
* @brief          Symbolic name for the channel RGBLED0_RED.
*
*/
#define DioConf_DioChannel_RGBLED0_RED  ((uint16)0x001dU)
/**
* @brief          Symbolic name for the channel RGBLED0_GREEN.
*
*/
#define DioConf_DioChannel_RGBLED0_GREEN  ((uint16)0x001eU)
/**
* @brief          Symbolic name for the channel RGBLED0_BLUE.
*
*/
#define DioConf_DioChannel_RGBLED0_BLUE  ((uint16)0x001fU)
/* ---------- PTB_L ---------- */

/**
* @brief          Symbolic name for the port PTB_L.
*/
#define DioConf_DioPort_PTB_L  ((uint8)0x02U)
/**
* @brief          Symbolic name for the channel lpHSD2_IN3_PTB2.
*
*/
#define DioConf_DioChannel_lpHSD2_IN3_PTB2  ((uint16)0x0022U)
/**
* @brief          Symbolic name for the channel lpHSD2_IN1_PTB3.
*
*/
#define DioConf_DioChannel_lpHSD2_IN1_PTB3  ((uint16)0x0023U)
/**
* @brief          Symbolic name for the channel Vvar2_Ctrl_PTB4.
*
*/
#define DioConf_DioChannel_Vvar2_Ctrl_PTB4  ((uint16)0x0024U)
/**
* @brief          Symbolic name for the channel OE1_PTB5.
*
*/
#define DioConf_DioChannel_OE1_PTB5  ((uint16)0x0025U)
/**
* @brief          Symbolic name for the channel lpHSD4_IN2_PTB8.
*
*/
#define DioConf_DioChannel_lpHSD4_IN2_PTB8  ((uint16)0x0028U)
/**
* @brief          Symbolic name for the channel lpHSD4_IN0_PTB9.
*
*/
#define DioConf_DioChannel_lpHSD4_IN0_PTB9  ((uint16)0x0029U)
/**
* @brief          Symbolic name for the channel lpHSD5_DSEL1_PTB10.
*
*/
#define DioConf_DioChannel_lpHSD5_DSEL1_PTB10  ((uint16)0x002aU)
/**
* @brief          Symbolic name for the channel hpHSD1_IN1_PTB11.
*
*/
#define DioConf_DioChannel_hpHSD1_IN1_PTB11  ((uint16)0x002bU)
/**
* @brief          Symbolic name for the channel hpHSD1_IN0_PTB12.
*
*/
#define DioConf_DioChannel_hpHSD1_IN0_PTB12  ((uint16)0x002cU)
/**
* @brief          Symbolic name for the channel hpHSD2_IN1_PTB13.
*
*/
#define DioConf_DioChannel_hpHSD2_IN1_PTB13  ((uint16)0x002dU)
/**
* @brief          Symbolic name for the channel LED_PTB14.
*
*/
#define DioConf_DioChannel_LED_PTB14  ((uint16)0x002eU)
/* ---------- PTB_H ---------- */

/**
* @brief          Symbolic name for the port PTB_H.
*/
#define DioConf_DioPort_PTB_H  ((uint8)0x03U)
/**
* @brief          Symbolic name for the channel USER_SW1.
*
*/
#define DioConf_DioChannel_USER_SW1  ((uint16)0x0033U)
/**
* @brief          Symbolic name for the channel CAN1_STB.
*
*/
#define DioConf_DioChannel_CAN1_STB  ((uint16)0x0038U)
/**
* @brief          Symbolic name for the channel lpHSD2_IN0_PTB25.
*
*/
#define DioConf_DioChannel_lpHSD2_IN0_PTB25  ((uint16)0x0039U)
/**
* @brief          Symbolic name for the channel USER_SW0.
*
*/
#define DioConf_DioChannel_USER_SW0  ((uint16)0x003aU)
/**
* @brief          Symbolic name for the channel lpHSD2_DSEL0_PTB27.
*
*/
#define DioConf_DioChannel_lpHSD2_DSEL0_PTB27  ((uint16)0x003bU)
/**
* @brief          Symbolic name for the channel lpHSD2_IN2_PTB28.
*
*/
#define DioConf_DioChannel_lpHSD2_IN2_PTB28  ((uint16)0x003cU)
/**
* @brief          Symbolic name for the channel lpHSD2_DSEL1_PTB29.
*
*/
#define DioConf_DioChannel_lpHSD2_DSEL1_PTB29  ((uint16)0x003dU)
/* ---------- PTC_L ---------- */

/**
* @brief          Symbolic name for the port PTC_L.
*/
#define DioConf_DioPort_PTC_L  ((uint8)0x04U)
/**
* @brief          Symbolic name for the channel DS18B20_DQ1_PTC0.
*
*/
#define DioConf_DioChannel_DS18B20_DQ1_PTC0  ((uint16)0x0040U)
/**
* @brief          Symbolic name for the channel DS18B20_DQ2_PTC1.
*
*/
#define DioConf_DioChannel_DS18B20_DQ2_PTC1  ((uint16)0x0041U)
/**
* @brief          Symbolic name for the channel lpHSD1_DSEL0_PTC12.
*
*/
#define DioConf_DioChannel_lpHSD1_DSEL0_PTC12  ((uint16)0x004cU)
/**
* @brief          Symbolic name for the channel lpHSD1_IN0_PTC13.
*
*/
#define DioConf_DioChannel_lpHSD1_IN0_PTC13  ((uint16)0x004dU)
/**
* @brief          Symbolic name for the channel AutoActiveSig_PTC14.
*
*/
#define DioConf_DioChannel_AutoActiveSig_PTC14  ((uint16)0x004eU)
/**
* @brief          Symbolic name for the channel CAN2_STB.
*
*/
#define DioConf_DioChannel_CAN2_STB  ((uint16)0x004fU)
/* ---------- PTC_H ---------- */

/**
* @brief          Symbolic name for the port PTC_H.
*/
#define DioConf_DioPort_PTC_H  ((uint8)0x05U)
/**
* @brief          Symbolic name for the channel lpHSD1_IN1_PTC18.
*
*/
#define DioConf_DioChannel_lpHSD1_IN1_PTC18  ((uint16)0x0052U)
/**
* @brief          Symbolic name for the channel lpHSD1_IN2_PTC19.
*
*/
#define DioConf_DioChannel_lpHSD1_IN2_PTC19  ((uint16)0x0053U)
/**
* @brief          Symbolic name for the channel lpHSD1_IN3_PTC20.
*
*/
#define DioConf_DioChannel_lpHSD1_IN3_PTC20  ((uint16)0x0054U)
/**
* @brief          Symbolic name for the channel lpHSD1_DSEL1_PTC21.
*
*/
#define DioConf_DioChannel_lpHSD1_DSEL1_PTC21  ((uint16)0x0055U)
/**
* @brief          Symbolic name for the channel CAN0_STB.
*
*/
#define DioConf_DioChannel_CAN0_STB  ((uint16)0x005eU)
/**
* @brief          Symbolic name for the channel OE6_PTC31.
*
*/
#define DioConf_DioChannel_OE6_PTC31  ((uint16)0x005fU)
/* ---------- PTD_L ---------- */

/**
* @brief          Symbolic name for the port PTD_L.
*/
#define DioConf_DioPort_PTD_L  ((uint8)0x06U)
/**
* @brief          Symbolic name for the channel hpHSD5_DSEL_PTD1.
*
*/
#define DioConf_DioChannel_hpHSD5_DSEL_PTD1  ((uint16)0x0061U)
/**
* @brief          Symbolic name for the channel lpHSD5_IN3_PTD2.
*
*/
#define DioConf_DioChannel_lpHSD5_IN3_PTD2  ((uint16)0x0062U)
/**
* @brief          Symbolic name for the channel hpHSD1_DSEL_PTD4.
*
*/
#define DioConf_DioChannel_hpHSD1_DSEL_PTD4  ((uint16)0x0064U)
/**
* @brief          Symbolic name for the channel DCDC_Ctrl_PTD8.
*
*/
#define DioConf_DioChannel_DCDC_Ctrl_PTD8  ((uint16)0x0068U)
/**
* @brief          Symbolic name for the channel LED0_PTD10.
*
*/
#define DioConf_DioChannel_LED0_PTD10  ((uint16)0x006aU)
/**
* @brief          Symbolic name for the channel OE2_PTD15.
*
*/
#define DioConf_DioChannel_OE2_PTD15  ((uint16)0x006fU)
/* ---------- PTD_H ---------- */

/**
* @brief          Symbolic name for the port PTD_H.
*/
#define DioConf_DioPort_PTD_H  ((uint8)0x07U)
/**
* @brief          Symbolic name for the channel Vvar3_Ctrl_PTD16.
*
*/
#define DioConf_DioChannel_Vvar3_Ctrl_PTD16  ((uint16)0x0070U)
/**
* @brief          Symbolic name for the channel OE3_PTD17.
*
*/
#define DioConf_DioChannel_OE3_PTD17  ((uint16)0x0071U)
/**
* @brief          Symbolic name for the channel hpHSD2_DSEL_PTD21.
*
*/
#define DioConf_DioChannel_hpHSD2_DSEL_PTD21  ((uint16)0x0075U)
/**
* @brief          Symbolic name for the channel lpHSD5_IN2_PTD23.
*
*/
#define DioConf_DioChannel_lpHSD5_IN2_PTD23  ((uint16)0x0077U)
/**
* @brief          Symbolic name for the channel lpHSD5_IN0_PTD24.
*
*/
#define DioConf_DioChannel_lpHSD5_IN0_PTD24  ((uint16)0x0078U)
/**
* @brief          Symbolic name for the channel lpHSD4_IN1_PTD26.
*
*/
#define DioConf_DioChannel_lpHSD4_IN1_PTD26  ((uint16)0x007aU)
/**
* @brief          Symbolic name for the channel lpHSD4_DSEL0_PTD27.
*
*/
#define DioConf_DioChannel_lpHSD4_DSEL0_PTD27  ((uint16)0x007bU)
/**
* @brief          Symbolic name for the channel lpHSD4_DSEL1_PTD29.
*
*/
#define DioConf_DioChannel_lpHSD4_DSEL1_PTD29  ((uint16)0x007dU)
/**
* @brief          Symbolic name for the channel lpHSD3_IN1_PTD30.
*
*/
#define DioConf_DioChannel_lpHSD3_IN1_PTD30  ((uint16)0x007eU)
/* ---------- PTE_L ---------- */

/**
* @brief          Symbolic name for the port PTE_L.
*/
#define DioConf_DioPort_PTE_L  ((uint8)0x08U)
/**
* @brief          Symbolic name for the channel ESP32S3_EN_SET.
*
*/
#define DioConf_DioChannel_ESP32S3_EN_SET  ((uint16)0x0080U)
/**
* @brief          Symbolic name for the channel lpHSD3_DSEL1_PTE2.
*
*/
#define DioConf_DioChannel_lpHSD3_DSEL1_PTE2  ((uint16)0x0082U)
/**
* @brief          Symbolic name for the channel Vvar5_Ctrl_PTE3.
*
*/
#define DioConf_DioChannel_Vvar5_Ctrl_PTE3  ((uint16)0x0083U)
/**
* @brief          Symbolic name for the channel hpHSD3_DSEL_PTE4.
*
*/
#define DioConf_DioChannel_hpHSD3_DSEL_PTE4  ((uint16)0x0084U)
/**
* @brief          Symbolic name for the channel lpHSD3_IN3_PTE6.
*
*/
#define DioConf_DioChannel_lpHSD3_IN3_PTE6  ((uint16)0x0086U)
/**
* @brief          Symbolic name for the channel Vvar6_Ctrl_PTE7.
*
*/
#define DioConf_DioChannel_Vvar6_Ctrl_PTE7  ((uint16)0x0087U)
/**
* @brief          Symbolic name for the channel Vvar1_Ctrl_PTE8.
*
*/
#define DioConf_DioChannel_Vvar1_Ctrl_PTE8  ((uint16)0x0088U)
/**
* @brief          Symbolic name for the channel hpHSD3_IN0_PTE10.
*
*/
#define DioConf_DioChannel_hpHSD3_IN0_PTE10  ((uint16)0x008aU)
/**
* @brief          Symbolic name for the channel hpHSD4_IN1_PTE11.
*
*/
#define DioConf_DioChannel_hpHSD4_IN1_PTE11  ((uint16)0x008bU)
/**
* @brief          Symbolic name for the channel OE4_PTE12.
*
*/
#define DioConf_DioChannel_OE4_PTE12  ((uint16)0x008cU)
/**
* @brief          Symbolic name for the channel OE5_PTE14.
*
*/
#define DioConf_DioChannel_OE5_PTE14  ((uint16)0x008eU)
/**
* @brief          Symbolic name for the channel hpHSD4_IN0_PTE15.
*
*/
#define DioConf_DioChannel_hpHSD4_IN0_PTE15  ((uint16)0x008fU)
/* ---------- PTE_H ---------- */

/**
* @brief          Symbolic name for the port PTE_H.
*/
#define DioConf_DioPort_PTE_H  ((uint8)0x09U)
/**
* @brief          Symbolic name for the channel lpHSD3_DSEL0_PTE17.
*
*/
#define DioConf_DioChannel_lpHSD3_DSEL0_PTE17  ((uint16)0x0091U)
/**
* @brief          Symbolic name for the channel lpHSD3_IN2_PTE18.
*
*/
#define DioConf_DioChannel_lpHSD3_IN2_PTE18  ((uint16)0x0092U)
/**
* @brief          Symbolic name for the channel hpHSD6_DSEL_PTE26.
*
*/
#define DioConf_DioChannel_hpHSD6_DSEL_PTE26  ((uint16)0x009aU)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief          Type of a DIO port representation.
*
* @implements     Dio_PortType_typedef
*/
typedef uint8 Dio_PortType;

/**
* @brief          Type of a DIO channel representation.
*
* @implements     Dio_ChannelType_typedef
*/
typedef uint16 Dio_ChannelType;

/**
* @brief          Type of a DIO port levels representation.
*
* @implements     Dio_PortLevelType_typedef
*/
typedef uint16 Dio_PortLevelType;

/**
* @brief          Type of a DIO channel levels representation.
*
* @implements     Dio_LevelType_typedef
*/
typedef uint8 Dio_LevelType;

/**
* @brief          Type of a DIO channel group representation.
*
* @implements     Dio_ChannelGroupType_struct
*/
typedef struct
{
    Dio_PortType      port;             /**< @brief Port identifier.  */
    uint8             u8offset;         /**< @brief Bit offset within the port. */
    Dio_PortLevelType mask;             /**< @brief Group mask. */
} Dio_ChannelGroupType;

/**
* @brief          Type of a DIO configuration structure.
*
* @note           In this implementation there is no need for a configuration
*                 structure there is only a dummy field, it is recommended
*                 to initialize this field to zero.
*
* @implements     Dio_ConfigType_struct
*/
typedef struct
{
    uint8 u8NumChannelGroups; /**< @brief Number of channel groups in configuration */
    const Dio_ChannelGroupType * pChannelGroupList;     /**< @brief
                                               Pointer to list of channel groups in configuration */
    const uint32 * pau32Dio_ChannelToPartitionMap;      /**< @brief Pointer to channel to partition mapping */
    const uint32 * pau32Dio_PortToPartitionMap;         /**< @brief Pointer to port to partition mapping */
} Dio_ConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#define DIO_START_SEC_CONST_8
#include "Dio_MemMap.h"

/**
* @brief Array of values storing the SIUL2 instance each port on the platform belongs to
*/
extern const uint8 Dio_au8PortSiul2Instance[DIO_NUM_PORTS_U16];

/**
* @brief Array of values storing the offset PORT0 has inside the SIUL2 instance it
*        belongs to
*/
extern const uint8 Dio_au8Port0OffsetInSiul2Instance[DIO_NUM_SIUL2_INSTANCES_U8];

#define DIO_STOP_SEC_CONST_8
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONST_16
#include "Dio_MemMap.h"

/**
* @brief Array of bitmaps of output pins available per port
*/
extern const Dio_PortLevelType Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16];

/**
* @brief Array of bitmaps of input pins available per port
*/
extern const Dio_PortLevelType Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16];

#define DIO_STOP_SEC_CONST_16
#include "Dio_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} */

