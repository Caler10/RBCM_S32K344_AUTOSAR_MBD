/*
 * Copyright 2020-2024 NXP
 *
 * NXP Confidential and Proprietary. This software is owned or controlled 
 * by NXP and may only be used strictly in accordance with the applicable 
 * license terms. By expressly accepting such terms or by downloading, 
 * installing, activating and/or otherwise using the software, you are 
 * agreeing that you have read, and that you agree to comply with and  
 * are bound by, such license terms. If you do not agree to be bound  
 * by the applicable license terms, then you may not retain, install, 
 * activate or otherwise use the software.
 */
#include "Clock_Ip.h"
#ifdef STEP_GPT_CHANNEL
#include "Gpt.h"
#endif

#if defined S32K376 || defined S32K374
#include "S32K37.h"
#define CORE_CLK CM7_CORE_CLK
#endif

#if defined S32K396 || defined S32K394 || defined S32K364 || defined S32K366
#include "S32K39.h"
#define CORE_CLK CM7_CORE_CLK
#endif

#if defined S32K358 || defined S32K328 || defined S32K338 || defined S32K348
#include "S32K358.h"
#endif

#if defined S32K311 || defined S32K310
#include "S32K311.h"
#endif

#ifdef S32K344
#include "S32K344.h"
#endif

#ifdef S32K342
#include "S32K342.h"
#endif

#ifdef S32K341
#include "S32K341.h"
#endif

#ifdef S32K312
#include "S32K312.h"
#endif

#ifdef S32K324
#include "S32K324.h"
#endif

#ifdef S32K314
#include "S32K314.h"
#endif

#ifdef S32K322
#include "S32K322.h"
#endif

#ifdef S32K388
#include "S32K388.h"
#define CORE_CLK CM7_CORE_CLK
#endif

#include "MW_target_hardware_resources.h"

unsigned long schdl_counter;
unsigned long schdl_counter_max;
float gModelBaseRate;

extern void rt_OneStep(void);

#ifdef STEP_GPT_CHANNEL
#define MAX_RELOAD_VALUE STEP_GPT_CHANNEL_VALUE_MAX-1

void MBDT_Step_Handler(void)
{
	if (schdl_counter >= schdl_counter_max) {
		schdl_counter = 0;
	}
	
    if (0 == schdl_counter++) {  /* Compare with zero before increament */
        rt_OneStep();
	}
}

void s32k3_trigger_config(float modelBaseRate)
{
	/* GPT Scheduler is selected */
	unsigned long tick_counter, reload_value;

    gModelBaseRate = modelBaseRate;

	tick_counter = (unsigned long)(STEP_GPT_CHANNEL_FREQ * modelBaseRate);
    
	if (tick_counter > MAX_RELOAD_VALUE) {
		schdl_counter_max = (unsigned long)((float)tick_counter / (float)MAX_RELOAD_VALUE) + 1;
        reload_value = tick_counter/schdl_counter_max;
	} else {
		schdl_counter_max = 0;
        reload_value = tick_counter;
	}
	
	schdl_counter = 0;
	
	/* Set the SysTick priority */
	#ifdef MW_SCHEDULER_PRIORITY
	#endif

    Gpt_StartTimer(STEP_GPT_CHANNEL, reload_value);
    Gpt_EnableNotification(STEP_GPT_CHANNEL);
}

#else
#define MAX_RELOAD_VALUE S32_SysTick_RVR_RELOAD_MASK

void SysTick_Handler(void)
{
	if (schdl_counter >= schdl_counter_max) {
		schdl_counter = 0;
	}
	
    if (0 == schdl_counter++) {  /* Compare with zero before increament */
        rt_OneStep();
	}
}

void s32k3_trigger_config(float modelBaseRate)
{
	/* SysTick Scheduler is selected */
	unsigned long tick_counter, reload_value;
    
    gModelBaseRate = modelBaseRate;

    tick_counter = (unsigned long)(Clock_Ip_GetClockFrequency(CORE_CLK) * modelBaseRate);
    
	if (tick_counter > MAX_RELOAD_VALUE) {
		schdl_counter_max = (unsigned long)((float)tick_counter / (float)MAX_RELOAD_VALUE) + 1;
        reload_value = tick_counter/schdl_counter_max;
	} else {
		schdl_counter_max = 0;
        reload_value = tick_counter;
	}
	
	schdl_counter = 0;
    
	/* Set the SysTick priority */
	#ifdef MW_SCHEDULER_PRIORITY
		NVIC_SetPriority(SysTick_IRQn, MW_SCHEDULER_PRIORITY);
	#endif
    
    /* Disable the SysTick */
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(0u);
    S32_SysTick->CVR = S32_SysTick_CVR_CURRENT(0U);
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD(reload_value);
    /* Enable the SysTick and the SysTick interrupt */
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_CLKSOURCE(1u);
}
#endif
