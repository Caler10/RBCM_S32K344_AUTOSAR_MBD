/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Flexio_Mcl_Ip_Irq.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Flexio Common Irq source file.
*   @details
*
*   @addtogroup FLEXIO_IP_IRQ_DRIVER FLEXIO IP IRQ Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Mcl_Ip.h"
#include "Flexio_Mcl_Ip_Cfg_DeviceRegisters.h"
#include "Mcal.h"

#ifdef USE_LIN_MODULE
    #include "Flexio_Lin_Ip_Irq.h"
#endif

#ifdef USE_SPI_MODULE
    #include "Flexio_Spi_Ip_Irq.h"
#endif

#ifdef USE_I2C_MODULE
    #include "Flexio_I2c_Ip_Irq.h"
#endif

#ifdef USE_I2S_MODULE
    #include "Flexio_I2s_Ip_Irq.h"
#endif

#ifdef USE_SENT_MODULE
    #include "Flexio_Sent_Ip_Irq.h"
#endif

#ifdef USE_UART_MODULE
      #include "Flexio_Uart_Ip_Irq.h"
#endif

#ifdef USE_PWM_MODULE
    #include "Flexio_Pwm_Ip_Irq.h"

    #define FLEXIO_IP_PIN_ISR_USED (STD_ON)

    #ifdef PWM_CHANNEL_0_USED
        #define PWM_CHANNEL_0_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_0_PINMASK
    #endif
    #ifdef PWM_CHANNEL_1_USED
        #define PWM_CHANNEL_1_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_1_PINMASK
    #endif
    #ifdef PWM_CHANNEL_2_USED
        #define PWM_CHANNEL_2_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_2_PINMASK
    #endif
    #ifdef PWM_CHANNEL_3_USED
        #define PWM_CHANNEL_3_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_3_PINMASK
    #endif
    #ifdef PWM_CHANNEL_4_USED
        #define PWM_CHANNEL_4_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_4_PINMASK
    #endif
    #ifdef PWM_CHANNEL_5_USED
        #define PWM_CHANNEL_5_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_5_PINMASK
    #endif
    #ifdef PWM_CHANNEL_6_USED
        #define PWM_CHANNEL_6_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_6_PINMASK
    #endif
    #ifdef PWM_CHANNEL_7_USED
        #define PWM_CHANNEL_7_PIN_ISR_MASK FLEXIO_PWM_IP_CHANNEL_7_PINMASK
    #endif
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_IRQ_VENDOR_ID_C                      43
#define FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_MCL_IP_IRQ_SW_MAJOR_VERSION_C               5
#define FLEXIO_MCL_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXIO_MCL_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Mcl_Ip.h file are of the same vendor */
#if (FLEXIO_MCL_IP_IRQ_VENDOR_ID_C != FLEXIO_MCL_IP_VENDOR_ID)
    #error "Flexio_Mcl_Ip_Irq.c and Flexio_Mcl_Ip.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Mcl_Ip.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_MCL_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_MCL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Mcl_Ip.h are different"
#endif

/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Mcl_Ip.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_MCL_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_MCL_IP_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_MCL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Mcl_Ip.h are different"
#endif

/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same vendor */
#if (FLEXIO_MCL_IP_IRQ_VENDOR_ID_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Flexio_Mcl_Ip_Irq.c and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Flexio_Mcl_Ip_Irq.c file and Mcal header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Mcal.h are different"
#endif

#ifdef USE_LIN_MODULE
/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Lin_Ip_Irq header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_LIN_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_LIN_IP_IRQ_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Lin_Ip_Irq.h are different"
#endif
#endif /* USE_LIN_MODULE */

#ifdef USE_SPI_MODULE
/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Spi_Ip_Irq header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_SPI_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_SPI_IP_IRQ_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Spi_Ip_Irq.h are different"
#endif
#endif /* USE_SPI_MODULE */

#ifdef USE_I2C_MODULE
/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_I2c_Ip_Irq header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_I2c_Ip_Irq.h are different"
#endif
#endif /* USE_I2C_MODULE */

#ifdef USE_UART_MODULE
/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Uart_Ip_Irq header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Uart_Ip_Irq.h are different"
#endif
#endif /* USE_UART_MODULE */

#ifdef USE_PWM_MODULE
/* Check if Flexio_Mcl_Ip_Irq.c file and Flexio_Pwm_Ip_Irq header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different"
#endif
#endif /* USE_PWM_MODULE */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define FLEXIO_CHANNEL_0_MASK ((uint8)0x01U)
#define FLEXIO_CHANNEL_1_MASK ((uint8)0x02U)
#define FLEXIO_CHANNEL_2_MASK ((uint8)0x04U)
#define FLEXIO_CHANNEL_3_MASK ((uint8)0x08U)
#define FLEXIO_CHANNEL_4_MASK ((uint8)0x10U)
#define FLEXIO_CHANNEL_5_MASK ((uint8)0x20U)
#define FLEXIO_CHANNEL_6_MASK ((uint8)0x40U)
#define FLEXIO_CHANNEL_7_MASK ((uint8)0x80U)
#define FLEXIO_CHANNEL_0 ((uint8)0U)
#define FLEXIO_CHANNEL_1 ((uint8)1U)
#define FLEXIO_CHANNEL_2 ((uint8)2U)
#define FLEXIO_CHANNEL_3 ((uint8)3U)
#define FLEXIO_CHANNEL_4 ((uint8)4U)
#define FLEXIO_CHANNEL_5 ((uint8)5U)
#define FLEXIO_CHANNEL_6 ((uint8)6U)
#define FLEXIO_CHANNEL_7 ((uint8)7U)
#define FLEXIO_INSTANCE_NO ((uint8)0U)

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
#ifdef USE_PWM_MODULE
#if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
extern void Flexio_Pwm_Ip_IrqHandler (uint8 channelId, uint8 timerFlags, uint32 pinFlags);
#else
extern void Flexio_Pwm_Ip_IrqHandler (uint8 channelId, uint8 timerFlags);
#endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
#endif
#ifdef USE_UART_MODULE
extern void Flexio_Uart_Ip_IrqHandler(uint8 u8Channel, uint8 u8ShifterMaskFlag, uint8 u8ShifterErrorMaskFlag, uint8 u8TimerMaskFlag);
#endif
#ifdef USE_I2C_MODULE
extern void Flexio_I2c_Ip_IrqHandler (uint8 u8Channel, uint8 u8ShifterMaskFlag, uint8 u8ShifterErrorMaskFlag, uint8 u8TimerMaskFlag);
#endif
#ifdef USE_I2S_MODULE
extern void Flexio_I2s_Ip_IrqHandler (uint8 u8Channel, uint8 u8ShifterMaskFlag, uint8 u8ShifterErrorMaskFlag, uint8 u8TimerMaskFlag);
#endif
#ifdef USE_LIN_MODULE
extern void Flexio_Lin_Ip_IrqHandler (uint8 u8Channel, uint8 u8ShifterMaskFlag, uint8 u8ShifterErrorMaskFlag);
#endif
#ifdef USE_SPI_MODULE
extern void Flexio_Spi_Ip_IrqHandler (uint8 u8Channel, uint8 u8ShifterMaskFlag, uint8 u8ShifterErrorMaskFlag);
#endif
#ifdef USE_SENT_MODULE
extern void Flexio_Sent_Ip_IrqHandler(uint8 u8Channel, uint8 u8TimerMaskFlag);
#endif
static void Flexio_Mcl_Ip_CommonIrq(void);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

static void Flexio_Mcl_Ip_CommonIrq(void)
{
    FLEXIO_Type *BaseAddr;
    BaseAddr                       = Flexio_Ip_paxBase[FLEXIO_INSTANCE_NO];

#if defined(USE_UART_MODULE) || defined(USE_LIN_MODULE) || defined(USE_I2C_MODULE) || defined(USE_I2S_MODULE) || defined(USE_SPI_MODULE)
    uint8 u8ShifterMaskFlag        = (uint8)Flexio_Mcl_Ip_GetAllShifterStatus(BaseAddr);
    uint8 u8ShifterEnabledIrq      = (uint8)Flexio_Mcl_Ip_GetAllShifterInterrupt(BaseAddr);
    uint8 u8ShifterErrEnabledIrq   = (uint8)Flexio_Mcl_Ip_GetAllShifterErrorInterrupt(BaseAddr);
#endif

    uint8 u8ShifterErrMaskFlag     = (uint8)Flexio_Mcl_Ip_GetAllShifterErrorStatus(BaseAddr);

    uint8 u8TimerMaskFlag          = (uint8)Flexio_Mcl_Ip_GetAllTimerStatus(BaseAddr);
#if defined(USE_UART_MODULE) || defined(USE_I2C_MODULE) || defined(USE_I2S_MODULE) || defined(USE_PWM_MODULE) || defined(USE_SENT_MODULE)
    uint8 u8TimerEnabledIrq        = (uint8)Flexio_Mcl_Ip_GetAllTimerInterrupt(BaseAddr);
#endif

#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
#ifdef FLEXIO_IP_PIN_ISR_USED
    uint32 u32PinMaskFlag          = Flexio_Mcl_Ip_GetAllPinsStatus(BaseAddr);
    uint32 u32PinEnabledIrq        = Flexio_Mcl_Ip_GetAllPinsInterrupt(BaseAddr);
#endif
#endif /* STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE */

    if (Flexio_Ip_baIpIsInitialized[FLEXIO_INSTANCE_NO])
    {
#if defined(USE_UART_MODULE) || defined(USE_LIN_MODULE) || defined(USE_I2C_MODULE) || defined(USE_I2S_MODULE) || defined(USE_SPI_MODULE)

        /* Clear the flags - care must be taken, not to accidentally clear other flags */
        /* Shifter Error Register (SHIFTERR) has W1C access type */
        BaseAddr->SHIFTERR      = (uint32) (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq);
#endif
#if defined(USE_UART_MODULE) || defined(USE_I2C_MODULE) || defined(USE_I2S_MODULE) || defined(USE_PWM_MODULE) || defined(USE_SENT_MODULE)

        /* Clear the flags - care must be taken, not to accidentally clear other flags */
        /* Timer Status Register (TIMSTAT) has W1C access type */
        BaseAddr->TIMSTAT       = (uint32) (u8TimerMaskFlag & u8TimerEnabledIrq);
#endif
#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
#ifdef FLEXIO_IP_PIN_ISR_USED

        /* Clear the flags - care must be taken, not to accidentally clear other flags */
        /* Pin Status Register (PINSTAT) has W1C access type */
        BaseAddr->PINSTAT       = u32PinMaskFlag & u32PinEnabledIrq;
#endif
#endif /* STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE */

#ifdef FLEXIO_0_CH_0_USED
    #if defined(UART_CHANNEL_0_USED) || defined(I2C_CHANNEL_0_USED) || defined(I2S_CHANNEL_0_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_0_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_0_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_0_MASK))
            )
        {
#ifdef UART_CHANNEL_0_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_0_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_0_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_0_USED) || defined(LIN_CHANNEL_0_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_0_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_0_MASK))
            )
        {
#ifdef SPI_CHANNEL_0_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_0_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_0_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_0_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8TimerMaskFlag);
        }

    #elif defined(PWM_CHANNEL_0_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_0_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_0_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_0_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_0, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /* if defined(UART_CHANNEL_0_USED) || defined(I2C_CHANNEL_0_USED) || defined(I2S_CHANNEL_0_USED) */
#endif /*ifdef FLEXIO_0_CH_0_USED*/

#ifdef FLEXIO_0_CH_1_USED
    #if defined(UART_CHANNEL_1_USED) || defined(I2C_CHANNEL_1_USED) || defined(I2S_CHANNEL_1_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_1_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_1_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_1_MASK))
            )
        {
#ifdef UART_CHANNEL_1_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_1_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_1_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_1_USED) || defined(LIN_CHANNEL_1_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_1_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_1_MASK))
            )
        {
#ifdef SPI_CHANNEL_1_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_1_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_1_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_1_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8TimerMaskFlag);
        }

    #elif defined(PWM_CHANNEL_1_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_1_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_1_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_1_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_1, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /*if defined(UART_CHANNEL_1_USED) || defined(I2C_CHANNEL_1_USED) || defined(I2S_CHANNEL_1_USED) */
#endif /*ifdef FLEXIO_0_CH_1_USED*/

#ifdef FLEXIO_0_CH_2_USED
    #if defined(UART_CHANNEL_2_USED) || defined(I2C_CHANNEL_2_USED) || defined(I2S_CHANNEL_2_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_2_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_2_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_2_MASK))
            )
        {
#ifdef UART_CHANNEL_2_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_2_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_2_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_2_USED) || defined(LIN_CHANNEL_2_USED) 
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_2_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_2_MASK))
            )
        {
#ifdef SPI_CHANNEL_2_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_2_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_2_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_2_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8TimerMaskFlag);
        }
    #elif defined(PWM_CHANNEL_2_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_2_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_2_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_2_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_2, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /*if defined(UART_CHANNEL_2_USED) || defined(I2C_CHANNEL_2_USED) || defined(I2S_CHANNEL_2_USED) */
#endif /*ifdef FLEXIO_0_CH_2_USED*/

#ifdef FLEXIO_0_CH_3_USED
    #if defined(UART_CHANNEL_3_USED) || defined(I2C_CHANNEL_3_USED) || defined(I2S_CHANNEL_3_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_3_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_3_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_3_MASK))
            )
        {
#ifdef UART_CHANNEL_3_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_3_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_3_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_3_USED) || defined(LIN_CHANNEL_3_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_3_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_3_MASK))
            )
        {
#ifdef SPI_CHANNEL_3_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_3_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_3_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_3_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8TimerMaskFlag);
        }
    #elif defined(PWM_CHANNEL_3_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_3_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_3_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_3_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_3, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /* defined(UART_CHANNEL_3_USED) || defined(I2C_CHANNEL_3_USED) || defined(I2S_CHANNEL_3_USED) */
#endif /*ifdef FLEXIO_0_CH_3_USED*/

#ifdef FLEXIO_0_CH_4_USED
    #if defined(UART_CHANNEL_4_USED) || defined(I2C_CHANNEL_4_USED) || defined(I2S_CHANNEL_4_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_4_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_4_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_4_MASK))
            )
        {
#ifdef UART_CHANNEL_4_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_4_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_4_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_4_USED) || defined(LIN_CHANNEL_4_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_4_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_4_MASK))
            )
        {
#ifdef SPI_CHANNEL_4_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_4_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_4_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_4_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8TimerMaskFlag);
        }

    #elif defined(PWM_CHANNEL_4_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_4_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_4_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_4_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_4, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /*if defined(UART_CHANNEL_4_USED) || defined(I2C_CHANNEL_4_USED) || defined(I2S_CHANNEL_4_USED) */
#endif /*ifdef FLEXIO_0_CH_4_USED*/

#ifdef FLEXIO_0_CH_5_USED
    #if defined(UART_CHANNEL_5_USED) || defined(I2C_CHANNEL_5_USED) || defined(I2S_CHANNEL_5_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_5_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_5_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_5_MASK))
            )
        {
#ifdef UART_CHANNEL_5_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_5_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_5_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_5_USED) || defined(LIN_CHANNEL_5_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_5_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_5_MASK))
            )
        {
#ifdef SPI_CHANNEL_5_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_5_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_5_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_5_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8TimerMaskFlag);
        }

    #elif defined(PWM_CHANNEL_5_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_5_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_5_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_5_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_5, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /*if defined(UART_CHANNEL_5_USED) || defined(I2C_CHANNEL_5_USED) || defined(I2S_CHANNEL_5_USED) */
#endif /*ifdef FLEXIO_0_CH_5_USED*/

#ifdef FLEXIO_0_CH_6_USED
    #if defined(UART_CHANNEL_6_USED) || defined(I2C_CHANNEL_6_USED) || defined(I2S_CHANNEL_6_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_6_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_6_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_6_MASK))
            )
        {
#ifdef UART_CHANNEL_6_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_6_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_6_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_6_USED) || defined(LIN_CHANNEL_6_USED) 
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_6_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_6_MASK))
            )
        {
#ifdef SPI_CHANNEL_6_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_6_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_6_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_6_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8TimerMaskFlag);
        }

    #elif defined(PWM_CHANNEL_6_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_6_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_6_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_6_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_6, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }

    #endif /*if defined(UART_CHANNEL_6_USED) || defined(I2C_CHANNEL_6_USED) || defined(I2S_CHANNEL_6_USED) */
#endif /*ifdef FLEXIO_0_CH_6_USED*/

#ifdef FLEXIO_0_CH_7_USED
    #if defined(UART_CHANNEL_7_USED) || defined(I2C_CHANNEL_7_USED) || defined(I2S_CHANNEL_7_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_7_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_7_MASK)) ||
              ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_7_MASK))
            )
        {
#ifdef UART_CHANNEL_7_USED
            Flexio_Uart_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2C_CHANNEL_7_USED
            Flexio_I2c_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
#ifdef I2S_CHANNEL_7_USED
            Flexio_I2s_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8ShifterMaskFlag, u8ShifterErrMaskFlag, u8TimerMaskFlag);
#endif
        }
    #elif defined(SPI_CHANNEL_7_USED) || defined(LIN_CHANNEL_7_USED)
        if  (((uint8)0U != (u8ShifterMaskFlag & u8ShifterEnabledIrq & FLEXIO_CHANNEL_7_MASK)) ||
              ((uint8)0U != (u8ShifterErrMaskFlag & u8ShifterErrEnabledIrq & FLEXIO_CHANNEL_7_MASK))
            )
        {
#ifdef SPI_CHANNEL_7_USED
            Flexio_Spi_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
#ifdef LIN_CHANNEL_7_USED
            Flexio_Lin_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8ShifterMaskFlag, u8ShifterErrMaskFlag);
#endif
        }
    #elif defined(SENT_CHANNEL_7_USED)

        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_7_MASK))
        {
            Flexio_Sent_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8TimerMaskFlag);
        }

    #elif defined(PWM_CHANNEL_7_USED)

    #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE))
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_7_MASK) ||
            (uint8)0U != (u32PinMaskFlag & u32PinEnabledIrq & PWM_CHANNEL_7_PIN_ISR_MASK)
           )
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8TimerMaskFlag, u32PinMaskFlag);
    #else
        if ((uint8)0U != (u8TimerMaskFlag & u8TimerEnabledIrq & FLEXIO_CHANNEL_7_MASK))
        {
            Flexio_Pwm_Ip_IrqHandler(FLEXIO_CHANNEL_7, u8TimerMaskFlag);
    #endif /* #if (defined(FLEXIO_PWM_IP_HAS_PIN_OVERRIDE) && (STD_ON == FLEXIO_PWM_IP_HAS_PIN_OVERRIDE)) */
        }
    #endif /*if defined(UART_CHANNEL_7_USED) || defined(I2C_CHANNEL_7_USED) || defined(I2S_CHANNEL_7_USED) */
#endif /*ifdef FLEXIO_0_CH_7_USED*/

    }
    else /* Flexio_Ip_baIpIsInitialized[FLEXIO_INSTANCE_NO] */
    {
       /* Clear ALL the flags in case of the uninitialized driver
       The status flag can also be cleared by writing a logic one to the flag for all modes except Match Continuous/ State /Logic.
       */
       /* Shifter Error Register (SHIFTERR) has W1C access type */
       BaseAddr->SHIFTERR  |=  (uint32) u8ShifterErrMaskFlag ;
       /* Timer Status Register (TIMSTAT) has W1C access type */
       BaseAddr->TIMSTAT   |=  (uint32) u8TimerMaskFlag ;
#if (STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE)
#ifdef FLEXIO_IP_PIN_ISR_USED
       /* Pin Status Register (PINSTAT) has W1C access type */
       BaseAddr->PINSTAT   |=  (uint32) u32PinMaskFlag;
#endif
#endif /* STD_ON == FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE */

    }
}

ISR(MCL_FLEXIO_ISR)
{
    /* Flexio common IRQ */
    Flexio_Mcl_Ip_CommonIrq();
    EXIT_INTERRUPT();
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
