/*
* Copyright (c) 2020 NXP.
* All rights reserved.
*/

#include "mbdt_lpuart.h"

/**
 * @internal
 * @brief Sets the LPUART baud rate.
 *
 * @details This function sets the LPUART baud rate.
 *
 *
 * @param[in] base LPUART base pointer.
 * @param[in] baudRate The baud rate
 * 
 * @return void
 * 
 * 
 */
void LPUART_Uart_SetBaudRate(uint32 instance, uint32 desiredBaudRate)
{
    uint16 sbr, sbrTemp, i;
    uint32 osr, tempDiff, calculatedBaud, baudDiff, maxOsr;
    uint32 lpuartSourceClock;
    const Clock_Ip_NameType instanceClkName = Lpuart_clkNames[instance];
    const LPUART_Type * base = Lpuart_apBases[instance];
    
    /* Get the LPUART clock as configured in the clock manager */
    lpuartSourceClock = Clock_Ip_GetClockFrequency(instanceClkName);

    /* Check if current instance is clock gated off. */
    LPUART_UART_DEV_ASSERT(lpuartSourceClock > 0U);
    /* Check if the desired baud rate can be configured with the current protocol clock. */
    LPUART_UART_DEV_ASSERT(lpuartSourceClock >= (desiredBaudRate * 4U));

    /* This lpuart instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, osr is typically hard-set to 16 in other lpuart instantiations
     * First calculate the baud rate using the minimum OSR possible (4) */
    osr = 4;
    sbr = (uint16_t)(lpuartSourceClock / (desiredBaudRate * osr));
    calculatedBaud = (lpuartSourceClock / (osr * sbr));
    if (calculatedBaud > desiredBaudRate)
    {
        baudDiff = calculatedBaud - desiredBaudRate;
    }
    else
    {
        baudDiff = desiredBaudRate - calculatedBaud;
    }
    /* find maximum osr */
    maxOsr = lpuartSourceClock / desiredBaudRate;
    if (maxOsr > 32U)
    {
        maxOsr = 32U;
    }
    /* loop to find the best osr value possible, one that generates minimum baudDiff
     * iterate through the rest of the supported values of osr */
    if (maxOsr >= 5U)
    {
        for (i = 5U; i <= maxOsr; i++)
        {
            /* calculate the temporary sbr value   */
            sbrTemp = (uint16_t)(lpuartSourceClock / (desiredBaudRate * i));
            /* calculate the baud rate based on the temporary osr and sbr values */
            calculatedBaud = (lpuartSourceClock / (i * sbrTemp));

            if (calculatedBaud > desiredBaudRate)
            {
                tempDiff = calculatedBaud - desiredBaudRate;
            }
            else
            {
                tempDiff = desiredBaudRate - calculatedBaud;
            }

            if (tempDiff <= baudDiff)
            {
                baudDiff = tempDiff;
                osr = i;  /* update and store the best osr value calculated */
                sbr = sbrTemp;  /* update store the best sbr value calculated */
            }
        }
    }
    /* Check if osr is between 4x and 7x oversampling.
     * If so, then "BOTHEDGE" sampling must be turned on */
    if (osr < 8U)
    {
    	Lpuart_Uart_Ip_EnableBothEdgeSamplingCmd(base);
    }

    /* program the osr value (bit value is one less than actual value) */
    Lpuart_Uart_Ip_SetOversamplingRatio(base, (osr - 1U));

    /* write the sbr value to the BAUD registers */
    Lpuart_Uart_Ip_SetBaudRateDivisor(base, sbr);
}
