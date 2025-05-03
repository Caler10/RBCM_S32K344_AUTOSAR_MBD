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

#ifndef SDADC_IP_H
#define SDADC_IP_H

/**
*   @file Sdadc_Ip.h
*
*   @addtogroup sd_adc_ip Sd Adc IPL
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
#include "Sdadc_Ip_Types.h"
#include "Sdadc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SDADC_IP_VENDOR_ID                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION    0
#define SDADC_IP_SW_MAJOR_VERSION               5
#define SDADC_IP_SW_MINOR_VERSION               0
#define SDADC_IP_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if SDADC_Ip.h file and SDADC_Ip_Types.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID != SDADC_IP_VENDOR_ID_TYPES)
    #error "SDADC_Ip.h and SDADC_Ip_Types.h have different vendor ids"
#endif

/* Check if SDADC_Ip.h file and SDADC_Ip_Types.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION != SDADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION != SDADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION != SDADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip.h and SDADC_Ip_Types.h are different"
#endif

/* Check if SDADC_Ip.h file and SDADC_Ip_Types.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION != SDADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (SDADC_IP_SW_MINOR_VERSION != SDADC_IP_SW_MINOR_VERSION_TYPES) || \
     (SDADC_IP_SW_PATCH_VERSION != SDADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of SDADC_Ip.h and SDADC_Ip_Types.h are different"
#endif

/* Check if SDADC_Ip.h file and SDADC_Ip_Cfg.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID != SDADC_IP_VENDOR_ID_CFG)
    #error "SDADC_Ip.h and SDADC_Ip_Cfg.h have different vendor ids"
#endif

/* Check if SDADC_Ip.h file and SDADC_Ip_Cfg.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION != SDADC_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION != SDADC_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION != SDADC_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip.h and SDADC_Ip_Cfg.h are different"
#endif

/* Check if SDADC_Ip.h file and SDADC_Ip_Cfg.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION != SDADC_IP_SW_MAJOR_VERSION_CFG) || \
     (SDADC_IP_SW_MINOR_VERSION != SDADC_IP_SW_MINOR_VERSION_CFG) || \
     (SDADC_IP_SW_PATCH_VERSION != SDADC_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of SDADC_Ip.h and SDADC_Ip_Cfg.h are different"
#endif

#ifdef FEATURE_ADC_HAS_SDADC


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"


/*!
 * @brief Configures the hardware instance with the given configuration structure
 *
 * This function configures the SDADC hardware instance with the options
 * provided in the structure. Module does not start by default after calling this function.
 * The Sdadc_Ip_ReloadConversion() or Sdadc_Ip_SwTriggerConversion() function must be called to start conversions.
 * The maximum input clock frequency for the SDADC is 40 MHz
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] Config Configuration structure pointer
 * @return the initialization result
 *  - SDADC_IP_STATUS_SUCCESS: initialization successful
 *  - SDADC_IP_STATUS_TIMEOUT: initialization timed out
 *  - SDADC_IP_STATUS_ERROR: initialization failed
 */
Sdadc_Ip_StatusType Sdadc_Ip_Init(const uint32 Instance,
                                  const Sdadc_Ip_ConfigType * const Config);


/*!
 * @brief Deinitialize SDADC module
 *
 * This function returns the SDADC internal registers to their reset values.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_Deinit(const uint32 Instance);


/*!
 * @brief Power up the SDADC
 *
 * This function enables the SDADC block.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_Powerup(const uint32 Instance);


/*!
 * @brief Power down the SDADC
 *
 * This function disables the SDADC, SDADC internal modulator placed in low consumption mode.
 * Note: This function also clears RSER[DFFDIRE] to ensure safe operation.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_Powerdown(const uint32 Instance);


/*!
 * @brief Reload SDADC conversion
 *
 * This function resets SDADC internal modulator to start a fresh conversion.
 * When the input trigger is disabled, this function must be call after changing converter configuration(gain, input channel, trigger, watchdog...).
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_ReloadConversion(const uint32 Instance);


/*!
 * @brief Generate software trigger
 *
 * This function generates the trigger event output which can be used for triggering conversions.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_SwTriggerConversion(const uint32 Instance);


/*!
 * @brief Configure watchdog threshold register
 *
 * This function configures the High/Low thresholds for the Watchdog monitor.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] UpperThreshold Watchdog upper threshold value
 * @param[in] LowerThreshold Watchdog lower threshold value
 */
void Sdadc_Ip_SetWdgThreshold(const uint32 Instance,
                              const uint16 UpperThreshold,
                              const uint16 LowerThreshold);


/*!
 * @brief Enables the watchdog monitor
 *
 * This function enables the Watchdog monitor.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_EnableWatchdog(const uint32 Instance);


/*!
 * @brief Disables the watchdog monitor
 *
 * This function disables the Watchdog monitor.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_DisableWatchdog(const uint32 Instance);


/*!
 * @brief Enable Wrap Around mode
 *
 * This function enables the wraparound mechanism for conversion.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_EnableWraparound(const uint32 Instance);


/*!
 * @brief Disable Wrap Around mode
 *
 * This function disables the wraparound mechanism for conversion.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_DisableWraparound(const uint32 Instance);


/*!
 * @brief Select input analog channel
 *
 * This function configures the connectivity of analog inputs to either positive or negative polarity
 * terminals of the SDADC. If wraparound mode is enabled, this function supports to configure
 * initial entry value for the first loop of the wraparound sequence.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] Channel The input channel selection
 */
void Sdadc_Ip_SetInputChannel(const uint32 Instance,
                              const Sdadc_Ip_ChannelType Channel);


/*!
 * @brief Flush data FIFO
 *
 * This function flushes data FIFO, all data in the FIFO will be erased.
 *
 * Note:
 *   - With DSPSS disabled: SDADC FIFO will be flushed.
 *   - With DSPSS enabled : DSPSS output buffer will be flushed.
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_FlushFifo(const uint32 Instance);


/*!
 * @brief Gets the conversion data.
 *
 * This function retrieves the converted data and writes it in the given data array.
 * The data will be consecutive popped out the FIFO until the FIFO is empty or the data array is full,
 * so the data array length should be big enough to contain all data.
 *
 * Note:
 *   - With DSPSS disabled: The data will be read from the SDADC hardware FIFO and they are calibrated automatically.
 *                          In this case, please use the Sdadc_Ip_GetRawConvDataFifo function to get raw data (uncalibrated data).
 *
 *   - With DSPSS enabled : The data will be read from the DSP core buffer located in XMEM.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] Length The length of data array
 * @param[out] Data The data array which contains the converted data
 * @return The actual number of read values
 */
uint32 Sdadc_Ip_GetConvData(const uint32 Instance,
                            const uint32 Length,
                            sint16 * const Data);


/*!
 * @brief Gets the raw conversion data in FIFO.
 *
 * This function retrieves the raw (uncalibrated) converted data and writes it in the given data array.
 * The data will be consecutive popped out the FIFO until the FIFO is empty or the data array is full,
 * so the data array length should be big enough to contain all data.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] Length The length of data array
 * @param[out] Data The data array which contains the converted data
 * @return The actual number of values read from the FIFO
 */
uint32 Sdadc_Ip_GetRawConvDataFifo(const uint32 Instance,
                                   const uint32 Length,
                                   sint16 * const Data);


/*!
 * @brief Get the status flags
 *
 * This function returns the status flags of the SDADC.
 * Bitwise AND the returned value with the SDADC_IP_FLAG_ defines to get a specific status flag.
 *
 * @param[in] Instance The SDADC instance number
 * @return The status flags
 */
uint32 Sdadc_Ip_GetStatusFlags(const uint32 Instance);


/*!
 * @brief Clear the status flags
 *
 * This function clears the status flags that are set to '1' in the mask.
 * The mask input parameter can be set using SDADC_IP_FLAG_ defines.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] Mask Bit-mask of flags to clear
 *  - For example:
 *       - With mask = SDADC_IP_FLAG_DATA_FIFO_FULL to clear Data FIFO Full Flag(DFFF).
 *       - With mask = (SDADC_IP_FLAG_DATA_FIFO_FULL | SDADC_IP_FLAG_DATA_FIFO_OVERRUN)
 *                      to clear Data FIFO Full Flag(DFFF) and Data FIFO Overrun Flag(DFORF).
 */
void Sdadc_Ip_ClearStatusFlags(const uint32 Instance,
                               const uint32 Mask);


/*!
 * @brief Enables SDADC DMA request generation
 *
 * This function enables SDADC DMA requests that are set to '1' in the EventsMask.
 * The EventsMask input parameter can be set using SDADC_IP_EVENT_ defines. Bitwise OR the macro defines
 * to enable multiple DMA requests.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] EventsMask The bit-mask of SDADC events to enable DMA request generation
 *
 * - For example: To enable DMA request generation of Data FIFO Full Event, the mask must be
 *              "SDADC_IP_EVENT_FIFO_FULL".
 */
void Sdadc_Ip_EnableDmaEvents(const uint32 Instance,
                              const uint32 EventsMask);


/*!
 * @brief Enables SDADC interrupt request generation
 *
 * This function enables SDADC interrupt requests that are set to '1' in the EventsMask.
 * The EventsMask input parameter can be set using SDADC_IP_EVENT_ defines. Bitwise OR the macro defines
 * to enable multiple interrupt requests.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] EventsMask The bit-mask of SDADC events to enable interrupt request generation
 *
 * - For example: To enable interrupt request generation of Data FIFO Full Event, the mask must be "SDADC_IP_EVENT_FIFO_FULL".
 */
void Sdadc_Ip_EnableInterruptEvents(const uint32 Instance,
                                    const uint32 EventsMask);


/*!
 * @brief Disable SDADC DMA and interrupt request generation
 *
 * This function disable SDADC DMA and interrupt requests that are set to '1' in the EventsMask.
 * The EventsMask input parameter can be set using SDADC_IP_EVENT_ defines. Bitwise OR the macro defines
 * to disable multiple interrupt/DMA requests.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] EventsMask The bit-mask of SDADC event to disable DMA and interrupt request generation
 *
 * - For example: To disable DMA and interrupt request generation of Data FIFO Full Event, the mask must be "SDADC_IP_EVENT_FIFO_FULL".
 */
void Sdadc_Ip_DisableInterruptEvents(const uint32 Instance,
                                     const uint32 EventsMask);


/*!
 * @brief Perform Calibration of the SDADC
 *
 * This function performs a offset and gain calibration of the SDADC.
 * Calibration should be done before using the SDADC module or after the operating conditions
 * (particularly Vref, input gain) change significantly.
 * The measured offset is going be used to nullify the offset error in the data conversion.
 * The offset calibration must be performed for each input gain changing since it is expected to
 * vary with input gain configuration of SDADC.
 * The measured gain value is going be used to nullify the gain errors in the data conversion.
 *
 * @param[in] Instance The SDADC instance number
 * @return the calibration result
 *  - SDADC_IP_STATUS_SUCCESS: calibration successful
 *  - SDADC_IP_STATUS_TIMEOUT: calibration step timed out
 *  - SDADC_IP_STATUS_ERROR: calibration failed
 */
Sdadc_Ip_StatusType Sdadc_Ip_DoCalibration(const uint32 Instance);


/*!
 * @brief Calibrate the converted data of the SDADC
 *
 * This function applies calibration to the uncalibrated converted data acquired by DMA or Sdadc_Ip_GetRawConvDataFifo function.
 * In the case uncalibrated converted data gathered by DMA, this function should be called in the DMA callback.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] BufferLength The number of entries in the uncalibrated data buffer.
 * @param[in] UncalibratedBuffer The pointer to the converted data array which contains uncalibrated data.
 * @param[out] CalibratedBuffer The pointer to the data array where the calibrated data will be stored.
 */
void Sdadc_Ip_ApplyCalibration(const uint32 Instance,
                               const uint32 BufferLength,
                               const sint16 * const UncalibratedBuffer,
                               sint16 * const CalibratedBuffer);

/*!
 * @brief Set user gain and offset
 *
 * This function applies user gain and offset
 *   - With DSPSS disabled: set SDADC gain and offset which are Sdadc_Ip_as32GainErr and Sdadc_Ip_as16OffsetErr.
 *   - With DSPSS enabled : set DSPSS thread gain and offset.
 *        - Users can disable the thread calibration by setting both Gain and Offset to 0.
 *
 * @param[in] Instance The SDADC instance number.
 * @param[in] Gain Gain value.
 * @param[in] Offset Offset value.
 */
void Sdadc_Ip_SetUserGainAndOffset(const uint32 Instance,
                                   const sint32 Gain,
                                   const sint32 Offset);

/*!
 * @brief Enable the hardware trigger
 *
 * This function enables the hardware trigger functionality
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_EnableHwTrigger(const uint32 Instance);


/*!
 * @brief Disable the hardware trigger
 *
 * This function disables the hardware trigger functionality
 *
 * @param[in] Instance The SDADC instance number
 */
void Sdadc_Ip_DisableHwTrigger(const uint32 Instance);


/*!
 * @brief Setting the input hardware trigger
 *
 * This function configures the input used for hardware-triggered conversions.
 *
 * @param[in] Instance The SDADC instance number
 * @param[in] TriggerEdge The edge of the hardware trigger signal
 * @param[in] TriggerSrc The hardware trigger source to be selected
 */
void Sdadc_Ip_SetHwTrigger(const uint32 Instance,
                           const Sdadc_Ip_TriggerEdgeType TriggerEdge,
                           const Sdadc_Ip_TriggerSelectType TriggerSrc);


/*!
 * @brief Return the address of the converted data.
 *
 * This function returns the address of the converted data which is used to configure DMA transfer.
 *   - With DSPSS disabled: returns the address of SDADC FIFO.
 *   - With DSPSS enabled : returns the address of DSPSS output buffer.
 *
 * @param[in] Instance The SDADC instance number
 * @return The address where the converted data will be stored.
 */
uint32 Sdadc_Ip_GetDataAddress(const uint32 Instance);


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


#endif /* FEATURE_ADC_HAS_SDADC */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SDADC_IP_H */
