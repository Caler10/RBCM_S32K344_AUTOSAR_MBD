/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

#ifndef BCTU_IP_H
#define BCTU_IP_H

/**
*   @file
*
*   @addtogroup bctu_ip
*   @{
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
#include "Bctu_Ip_Types.h"
#include "Bctu_Ip_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BCTU_IP_VENDOR_ID                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION    0
#define BCTU_IP_SW_MAJOR_VERSION               5
#define BCTU_IP_SW_MINOR_VERSION               0
#define BCTU_IP_SW_PATCH_VERSION               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip.h file and Bctu_Ip_Types.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID != BCTU_IP_VENDOR_ID_TYPES)
    #error "Bctu_Ip.h and Bctu_Ip_Types.h have different vendor ids"
#endif

/* Check if Bctu_Ip.h file and Bctu_Ip_Types.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION != BCTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION != BCTU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION != BCTU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.h and Bctu_Ip_Types.h are different"
#endif

/* Check if Bctu_Ip.h file and Bctu_Ip_Types.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION != BCTU_IP_SW_MAJOR_VERSION_TYPES) || \
     (BCTU_IP_SW_MINOR_VERSION != BCTU_IP_SW_MINOR_VERSION_TYPES) || \
     (BCTU_IP_SW_PATCH_VERSION != BCTU_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Bctu_Ip.h and Bctu_Ip_Types.h are different"
#endif

/* Check if Bctu_Ip.h file and Bctu_Ip_Cfg.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID != BCTU_IP_VENDOR_ID_CFG)
    #error "Bctu_Ip.h and Bctu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Bctu_Ip.h file and Bctu_Ip_Cfg.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION != BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION != BCTU_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION != BCTU_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip.h and Bctu_Ip_Cfg.h are different"
#endif

/* Check if Bctu_Ip.h file and Bctu_Ip_Cfg.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION != BCTU_IP_SW_MAJOR_VERSION_CFG) || \
     (BCTU_IP_SW_MINOR_VERSION != BCTU_IP_SW_MINOR_VERSION_CFG) || \
     (BCTU_IP_SW_PATCH_VERSION != BCTU_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of Bctu_Ip.h and Bctu_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/
/*!
 * @brief Macros for notification flags
 *
 * Define bit masks to check for enabling and disabling notification.
 *
 */
#define BCTU_IP_NOTIF_FIFO1                 ((uint32)1U << 0U) /* This notification (.._FIFOn) affects FIFO notification */
#define BCTU_IP_NOTIF_FIFO2                 (BCTU_IP_NOTIF_FIFO1 << 1U)

#if (BCTU_IP_FIFO_COUNT > 2U)
/* FIFO3 is available, define its notif flags */
#define BCTU_IP_NOTIF_FIFO3                 (BCTU_IP_NOTIF_FIFO1 << 2U)
#else
/* FIFO3 is not available, just define dummy flags */
#define BCTU_IP_NOTIF_FIFO3                 ((uint32)0U)
#endif /* (BCTU_IP_FIFO_COUNT > 2U) */

#define BCTU_IP_NOTIF_ADC0                  ((uint32)1U << 3U) /* These notifications (.._ADCn) affect DATAOVR and NDATA notifications */
#define BCTU_IP_NOTIF_ADC1                  (BCTU_IP_NOTIF_ADC0 << 1U)
#define BCTU_IP_NOTIF_ADC2                  (BCTU_IP_NOTIF_ADC0 << 2U)
#define BCTU_IP_NOTIF_ADC3                  (BCTU_IP_NOTIF_ADC0 << 3U)

#define BCTU_IP_NOTIF_LIST                  ((uint32)1U << 7U) /* This notification affects all ADC instances LIST_LAST notification */

#define BCTU_IP_NOTIF_TRG                   ((uint32)1U << 8U)

/*!
 * @brief Macros for status flags
 *
 * These flags map to internal hardware flags in different registers, but are
 * grouped together for convenience.
 *
 */

/* Bit [0]: Trigger flag */
#define BCTU_IP_STATUS_TRG                  ((uint32)1U << 0U)

/* Bit [1-3]: Fifo full flags, bit index 3 for FIFO3 */
#define BCTU_IP_STATUS_FIFO1_FULL           ((uint32)1U << 1U)
#define BCTU_IP_STATUS_FIFO2_FULL           (BCTU_IP_STATUS_FIFO1_FULL     << 1U)

/* Bit [4-6]: Fifo watermark flags, bit index 6 for FIFO3 */
#define BCTU_IP_STATUS_FIFO1_WM_INT         ((uint32)1U << 4U)
#define BCTU_IP_STATUS_FIFO2_WM_INT         (BCTU_IP_STATUS_FIFO1_WM_INT   << 1U)

/* Bit [7-9]: Fifo overrun error flags, bit index 9 for FIFO3 */
#define BCTU_IP_STATUS_FIFO1_OVR_ERR        ((uint32)1U << 7U)
#define BCTU_IP_STATUS_FIFO2_OVR_ERR        (BCTU_IP_STATUS_FIFO1_OVR_ERR  << 1U)

/* Bit [10-12]: Fifo full flags, bit index 12 for FIFO3 */
#define BCTU_IP_STATUS_FIFO1_UNDR_ERR       ((uint32)1U << 10U)
#define BCTU_IP_STATUS_FIFO2_UNDR_ERR       (BCTU_IP_STATUS_FIFO1_UNDR_ERR << 1U)

#if (BCTU_IP_FIFO_COUNT > 2U)
/* FIFO3 is available, define its status flags */
#define BCTU_IP_STATUS_FIFO3_FULL           (BCTU_IP_STATUS_FIFO1_FULL     << 2U)
#define BCTU_IP_STATUS_FIFO3_WM_INT         (BCTU_IP_STATUS_FIFO1_WM_INT   << 2U)
#define BCTU_IP_STATUS_FIFO3_OVR_ERR        (BCTU_IP_STATUS_FIFO1_OVR_ERR  << 2U)
#define BCTU_IP_STATUS_FIFO3_UNDR_ERR       (BCTU_IP_STATUS_FIFO1_UNDR_ERR << 2U)
#else
/* FIFO3 is not available, just define dummy flags */
#define BCTU_IP_STATUS_FIFO3_FULL           ((uint32)0U)
#define BCTU_IP_STATUS_FIFO3_WM_INT         ((uint32)0U)
#define BCTU_IP_STATUS_FIFO3_OVR_ERR        ((uint32)0U)
#define BCTU_IP_STATUS_FIFO3_UNDR_ERR       ((uint32)0U)
#endif /* (BCTU_IP_FIFO_COUNT > 2U) */

/* Bit [13-16]: New data flags */
#define BCTU_IP_STATUS_ADC0_NDATA           ((uint32)1U << 13U)
#define BCTU_IP_STATUS_ADC1_NDATA           (BCTU_IP_STATUS_ADC0_NDATA << 1U)
#define BCTU_IP_STATUS_ADC2_NDATA           (BCTU_IP_STATUS_ADC0_NDATA << 2U)
#define BCTU_IP_STATUS_ADC3_NDATA           (BCTU_IP_STATUS_ADC0_NDATA << 3U)

/* Bit [17-20]: Data overrun flags */
#define BCTU_IP_STATUS_ADC0_DATAOVR         ((uint32)1U << 17U)
#define BCTU_IP_STATUS_ADC1_DATAOVR         (BCTU_IP_STATUS_ADC0_DATAOVR << 1U)
#define BCTU_IP_STATUS_ADC2_DATAOVR         (BCTU_IP_STATUS_ADC0_DATAOVR << 2U)
#define BCTU_IP_STATUS_ADC3_DATAOVR         (BCTU_IP_STATUS_ADC0_DATAOVR << 3U)

/* Bit [21-24]: Last conversion flags */
#define BCTU_IP_STATUS_ADC0_LAST            ((uint32)1U << 21U)
#define BCTU_IP_STATUS_ADC1_LAST            (BCTU_IP_STATUS_ADC0_LAST << 1U)
#define BCTU_IP_STATUS_ADC2_LAST            (BCTU_IP_STATUS_ADC0_LAST << 2U)
#define BCTU_IP_STATUS_ADC3_LAST            (BCTU_IP_STATUS_ADC0_LAST << 3U)

#define BCTU_IP_NOTIF_ALL                   (BCTU_IP_NOTIF_FIFO1 | \
                                             BCTU_IP_NOTIF_FIFO2 | \
                                             BCTU_IP_NOTIF_FIFO3 | \
                                             BCTU_IP_NOTIF_ADC0 | \
                                             BCTU_IP_NOTIF_ADC1 | \
                                             BCTU_IP_NOTIF_ADC2 | \
                                             BCTU_IP_NOTIF_ADC3 | \
                                             BCTU_IP_NOTIF_TRG | \
                                             BCTU_IP_NOTIF_LIST \
                                             )

#define BCTU_IP_STATUS_ALL                  (BCTU_IP_STATUS_TRG | \
                                             BCTU_IP_STATUS_FIFO1_WM_INT | \
                                             BCTU_IP_STATUS_FIFO2_WM_INT | \
                                             BCTU_IP_STATUS_FIFO3_WM_INT | \
                                             BCTU_IP_STATUS_FIFO1_OVR_ERR | \
                                             BCTU_IP_STATUS_FIFO2_OVR_ERR | \
                                             BCTU_IP_STATUS_FIFO3_OVR_ERR | \
                                             BCTU_IP_STATUS_FIFO1_UNDR_ERR | \
                                             BCTU_IP_STATUS_FIFO2_UNDR_ERR | \
                                             BCTU_IP_STATUS_FIFO3_UNDR_ERR | \
                                             BCTU_IP_STATUS_ADC0_NDATA | \
                                             BCTU_IP_STATUS_ADC1_NDATA | \
                                             BCTU_IP_STATUS_ADC2_NDATA | \
                                             BCTU_IP_STATUS_ADC3_NDATA | \
                                             BCTU_IP_STATUS_ADC0_DATAOVR | \
                                             BCTU_IP_STATUS_ADC1_DATAOVR | \
                                             BCTU_IP_STATUS_ADC2_DATAOVR | \
                                             BCTU_IP_STATUS_ADC3_DATAOVR | \
                                             BCTU_IP_STATUS_ADC0_LAST | \
                                             BCTU_IP_STATUS_ADC1_LAST | \
                                             BCTU_IP_STATUS_ADC2_LAST |\
                                             BCTU_IP_STATUS_ADC3_LAST \
                                             )

#define BCTU_IP_MCR_NOTIF_ALL_MASK          (BCTU_MCR_IEN0_MASK | \
                                             BCTU_MCR_IEN1_MASK | \
                                             BCTU_MCR_IEN2_MASK | \
                                             BCTU_MCR_IEN3_MASK | \
                                             BCTU_MCR_LIST_IEN_MASK | \
                                             BCTU_MCR_TRGEN_MASK \
                                             )

#define BCTU_IP_FIFOCR_NOTIF_ALL_MASK       (BCTU_FIFOCR_IEN_FIFO1_MASK | \
                                             BCTU_FIFOCR_IEN_FIFO2_MASK | \
                                             BCTU_FIFOCR_IEN_FIFO3_MASK \
                                             )

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/*!
 * @brief Configure global functionalities of a BCTU instance.
 *
 * This function configures the global functionalities of a BCTU instance.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] pConfig - pointer to the input configuration structure
 * @return void
 */
void Bctu_Ip_Init(const uint32 u32Instance,
                  const Bctu_Ip_ConfigType * const pConfig);

/*!
 * @brief Reset the BCTU registers to default values.
 *
 * This function attempts to reset the BCTU registers to default values,
 * in the given timeout interval.
 * Trigger config registers cannot be modified while there is an ongoing conversion,
 * so the function waits for the conversion(s) to finish and returns an error code
 * if timeout occurres.
 * It globally disables all triggers, leaving the BCTU in configuration mode.
 *
 * @param[in] u32Instance - BCTU instance number
 * @return status:
 * \n - BCTU_IP_STATUS_SUCCESS: reset succeeded
 * \n - BCTU_IP_STATUS_TIMEOUT: reset did not complete because an active conversion
 * did not finish execution within the provided timeout interval
 */
Bctu_Ip_StatusType Bctu_Ip_Deinit(const uint32 u32Instance);

/*!
 * @brief Set the state of the Global Trigger Enable flag.
 *
 * This function sets the state of the Global Trigger Enable flag.
 * When triggers are disabled globally, the BCTU is in configuration mode, which allows configuring
 * the trigger config registers freely, without generating any spurious ADC conversion triggers.
 * Enabling the flag will move BCTU out of configuration mode and will enable all trigger inputs which are
 * already individually enabled from the trigger config registers.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] bState - true: globally enable triggers \n
 *                    false: globally disable triggers - enter configuration mode
 * @return void
 */
void Bctu_Ip_SetGlobalTriggerEn(const uint32 u32Instance,
                                const boolean bState);

/*!
 * @brief Set the BCTU operating mode: normal or low power.
 *
 * This function sets the BCTU operating mode: normal or low power.
 * In low power mode all trigger inputs are ignored and any pending triggers remain active.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] bState - true: enable low power mode \n
 *                    false: enable normal mode
 * @return void
 */
void Bctu_Ip_SetLowPowerMode(const uint32 u32Instance,
                             const boolean bState);

/*!
 * @brief Get the value of all BCTU status flags.
 *
 * This function returns the value of all BCTU status flags.
 *
 * @param[in] u32Instance - BCTU instance number
 * @return state of the selected flags
 */
uint32 Bctu_Ip_GetStatusFlags(const uint32 u32Instance);

/*!
 * @brief Clear selected BCTU status flags.
 *
 * This function clears selected BCTU status flags.
 * The mask parameter should be set using BCTU_IP_STATUS_... defines.
 *
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u32Mask - selected flags mask
 * @return void
 */
void Bctu_Ip_ClearStatusFlags(const uint32 u32Instance,
                              const uint32 u32Mask);

/*!
 * @brief Configures a trigger configuration register for an individual (non-list) conversion.
 *
 * This function attempts to configure a trigger configuration register for an individual (non-list) conversion.
 * If there is an on-going conversion started via target trigger, it only disables the trigger
 * (will ignore any new triggers) and returns error code. \n
 * If succeeds, implicitly clears any pending previous input trigger event. \n
 *
 * Note: when executing a list, the conversion is considered active until the conversion
 * marked as "last" completes.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] pTrigConfig - BCTU trigger configuration
 * @return status:
 * \n - BCTU_IP_STATUS_SUCCESS: configured successfully
 * \n - BCTU_IP_STATUS_BUSY: configuration was not written because there is a triggered active conversion
 */
Bctu_Ip_StatusType Bctu_Ip_ConfigTrigger(const uint32 u32Instance,
                                         const Bctu_Ip_TrigConfigType * const pTrigConfig);

/*!
 * @brief Configures trigger resolution and either the channel or first address of the command list associated with the trigger.
 *
 * This function attempts to configure trigger resolution and the register for either the channel or
 * the first address of the command list associated with the trigger.
 * If there is an on-going conversion started via target trigger, it only disables the trigger
 * (will ignore any new triggers) and returns error code. \n
 * If succeeds, implicitly clears any pending previous input trigger event. \n
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8TrigIdx - index of the trigger register
 * @param[in] bList - value of trigger resolution register: false for single conversion and true for conversion list
 * @param[in] u8ChnOrListAddr - channel index if bList is false or conversion list start address if bList is true
 * @return status:
 * \n - BCTU_IP_STATUS_SUCCESS: configured successfully
 * \n - BCTU_IP_STATUS_BUSY: configuration was not written because there is a triggered active conversion
 */
Bctu_Ip_StatusType Bctu_Ip_SetTriggerChnListAddr(const uint32 u32Instance,
                                                 const uint8 u8TrigIdx,
                                                 const boolean bList,
                                                 const uint8 u8ChnOrListAddr);

/*!
 * @brief Clears any eventual pending hw input signals already
 * occurred on the selected trigger and enables new occurrences of the hw input signals
 * to start new conversions.
 *
 * This function clears any eventual pending hw input signals already
 * occurred on the selected trigger and enables new occurrences of the hw input signals
 * to start new conversions.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8TrigIdx - index of the trigger register
 * @return void
 *
 */
void Bctu_Ip_EnableHwTrigger(const uint32 u32Instance,
                             const uint8 u8TrigIdx);

/*!
 * @brief Prevent the selected BCTU trigger to start
 * new conversions on the occurrence of an external input signal or new conversions
 * in an on-going conversion loop (loop flag enabled).
 *
 * This function prevents the selected BCTU trigger to start
 * new conversions on the occurrence of an hw input signal or new conversions
 * in an on-going conversion loop (loop flag enabled).
 * After calling this function, new conversions may still be started by BCTU software trigger.
 * Note: the function does NOT stop an on-going conversion.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8TrigIdx - index of the trigger register
 * @return void
 *
 */
void Bctu_Ip_DisableHwTrigger(const uint32 u32Instance,
                              const uint8 u8TrigIdx);

/*!
 * @brief Stop a series of loop conversions initiated by
 * the selected BCTU trigger.
 *
 * This function stops a series of loop conversions initiated by
 * the selected BCTU trigger.
 * Note0: the function does NOT stop an on-going conversion.
 * Note1: the function assumes that no HW trigger occurs on the selected trigger
 * during its execution - the reset & restore operation on the LOOP flag is not atomic!
 * Occurrence of a HW trigger may start a new conversion with an inconsistent value
 * for the LOOP flag.
 * For stopping HW triggered loops of conversions consider also using Bctu_Ip_DisableHwTrigger.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8TrigIdx - index of the trigger register
 * @return void
 *
 */
void Bctu_Ip_StopLoopConversions(const uint32 u32Instance,
                                 const uint8 u8TrigIdx);

/*!
 * @brief Set an array of ADC channel structures in the conversion list.
 *
 * This function sets the conversion list using an array of ListItemType structures.
 * Also marks the element corresponding to the last channel in the array, as last element in the list.
 * Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8StartListElemIdx - index in the list corresponding to the first element in the array
 * @param[in] pConvListItems - pointer to the first element in the ADC channel structure input array
 * @param[in] u8NumItems - number of elements in the ADC channel numbers input array (required to be >0)
 * @return void
 */
void Bctu_Ip_ConfigChanList(const uint32 u32Instance,
                            const uint8 u8StartListElemIdx,
                            const Bctu_Ip_ListItemType * const pConvListItems,
                            const uint8 u8NumItems);

/*!
 * @brief Set an array of ADC channel numbers in the conversion list.
 *
 * This function sets an array of ADC channel numbers in the conversion list and
 * marks the element corresponding to the last channel in the array, as last element in the list.
 * Other configurable fields of a conversion element, like NEXT_CH_WAIT_ON_TRIG_y is set to false/0.
 * Implicitly wrap-around of the array onto the list, if (listSize - startElemIdx) < numArrayElems.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8StartListElemIdx - index in the list corresponding to the first element in the array
 * @param[in] pConvListItems - pointer to the first element in the ADC channel array
 * @param[in] u8NumItems - number of elements in the ADC channel numbers input array (required to be >0)
 * @return void
 */
void Bctu_Ip_ConfigChanListSimple(const uint32 u32Instance,
                                  const uint8 u8StartListElemIdx,
                                  const uint8 * const pConvListItems,
                                  const uint8 u8NumItems);

/*!
 * @brief Triggers a conversion or list of conversions associated with a trigger index,
 * if write protection is disabled.
 *
 * This function triggers a conversion or list of conversions associated with a trigger index, if write protection is disabled.
 * If write protection is enabled, the function will not trigger the conversion.\n
 * It is recommended that this function is used with HW triggers disabled for the target trigger index,
 * to avoid ambiguity regarding source of trigger (hw or sw) for conversion results.\n
 *
 * The BCTU HW will ignore attempts to trigger a new conversion or list, while there is a pending conversion or,
 * in case of an active conversion list, before the last conversion is started.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8TrigIdx - index of the trigger register
 * @return void
 */
void Bctu_Ip_SwTriggerConversion(const uint32 u32Instance,
                                 const uint8 u8TrigIdx);

/*!
 * @brief Return the current conversion result data corresponding to an ADC instance.
 *
 * This function returns the current conversion result data corresponding to an ADC instance.
 * Note: In order to return the result with the correct resolution, the
 * ADC_SAR instance used must still be initialized when calling this function.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8AdcIdx - index of the target ADC module
 * @return uint16 - conversion result
 */
uint16 Bctu_Ip_GetConvData(const uint32 u32Instance,
                           const uint8 u8AdcIdx);

/*!
 * @brief Return the full conversion result information corresponding to an ADC instance.
 *
 * This function returns the full conversion result information corresponding to an ADC instance.
 * Note: In order to return the result with the correct resolution, the
 * ADC_SAR instance used must still be initialized when calling this function.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8AdcIdx - index of the target ADC module
 * @param[out] pResult - pointer to the structure to be populated with the conversion result info
 * @return void
 */
void Bctu_Ip_GetConvResult(const uint32 u32Instance,
                           const uint8 u8AdcIdx,
                           Bctu_Ip_ResultType * const pResult);

/*!
 * @brief Return the conversion result data stored in the index in a FIFO.
 *
 * This function returns the conversion result data that is stored in the BCTU
 * result FIFO at the given index.
 * Note: In order to return the result with the correct resolution, the
 * ADC_SAR instance used must still be initialized when calling this function.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8FifoIdx - index of the selected FIFO
 * @return uint16 - FIFO content
 */
uint16 Bctu_Ip_GetFifoData(const uint32 u32Instance,
                           const uint8 u8FifoIdx);

/*!
 * @brief Return the full conversion result information stored in a FIFO.
 *
 * This function returns the full conversion result information that is stored
 * in the BCTU result FIFO at the given index.
 * Note: In order to return the result with the correct resolution, the
 * ADC_SAR instance used must still be initialized when calling this function.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8FifoIdx - index of the selected FIFO
 * @param[out] pResult - pointer to the structure to be populated with the FIFO result info
 * @return void
 */
void Bctu_Ip_GetFifoResult(const uint32 u32Instance,
                           const uint8 u8FifoIdx,
                           Bctu_Ip_FifoResultType * const pResult);

/*!
 * @brief Enables notifications.
 *
 * This function enables notifications selected by the given mask on the selected BCTU instance.
 * The notifications mask parameter should be set using BCTU_IP_NOTIF_... defines.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u32NotificationMask - mask selecting targeted events
 * @return void
 */
void Bctu_Ip_EnableNotifications(const uint32 u32Instance,
                                 const uint32 u32NotificationMask);

/*!
 * @brief Disables notifications.
 *
 * This function disables notifications selected by the given mask on the selected BCTU instance.
 * The notifications mask parameter should be set using BCTU_IP_NOTIF_... defines.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u32NotificationMask - mask selecting targeted events
 * @return void
 */
void Bctu_Ip_DisableNotifications(const uint32 u32Instance,
                                  const uint32 u32NotificationMask);

/*!
 * @brief Sets watermark value for the selected FIFO.
 *
 * This function sets the watermark value for the selected FIFO.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8FifoIdx - index of the selected FIFO
 * @param[in] u8Watermark - watermark value
 * @return void
 */
void Bctu_Ip_SetFifoWatermark(const uint32 u32Instance,
                              const uint8 u8FifoIdx,
                              const uint8 u8Watermark);

/*!
 * @brief Get the counter value of the given FIFO.
 *
 * This function gets the counter value of the given FIFO.
 *
 * @param[in] u32Instance - BCTU instance number
 * @param[in] u8FifoIdx - index of the selected FIFO
 * @return uint8 - FIFO counter value
 */
uint8 Bctu_Ip_GetFifoCount(const uint32 u32Instance,
                           const uint8 u8FifoIdx);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* BCTU_IP_H */
