/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*================================================================================================
*   @file    sys_init.c
*   @version 5.0.0
*
*   @brief   AUTOSAR Platform - RTD auxiliary APIs used for RTD testing
*   @details RTD auxiliary APIs used for RTD testing
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup PLATFORM
*   @{
*
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "sys_init.h"
#include "Mcal.h"

#include "nvic.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/*Partition 0 */
#if defined(S32K312)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x000133CFU)
#elif defined(S32K342) || defined(S32K341)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x000133CFU)
#elif defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
/* workaround for K396 : PRTN0_COFB1_CLKEN register is available on hardware. This workaround will be updated after confirm with header team */
#define MC_ME_PRTN0_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN0_PUPD_PCUD_SHIFT              (0U)
#define MC_ME_PRTN0_PUPD_PCUD_WIDTH              (1U)
#define MC_ME_PRTN0_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_PUPD_PCUD_SHIFT)) & MC_ME_PRTN0_PUPD_PCUD_MASK)

#define PRTN0_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x001FFFF8U)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x0003FFC7U)
#elif defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358)
#define PRTN0_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x00000008U)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x0000F7DFU)
#elif defined(S32K388)
#define PRTN0_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x1000000CU)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x001EF7DFU)
#elif defined(S32K311) || defined(S32K310)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x000033CFU)
#elif defined(S32M276) || defined(S32M274)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x400033CFU)
#else
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x0000F7DFU)
#endif
/*Partition 1*/
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xFFBFFFFFU)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xFDF4AFFFU)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0xB3F03E7EU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x00005FEFU)
#elif defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xFFBFFFFFU)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xFFFEAFFFU)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0xBBF3FFFEU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x00005FEFU)
#elif defined(S32K342) || defined(S32K341)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xF1C0FFF8U)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x812AA407U)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0xBBF03E1EU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x00000001U)
#elif defined(S32K388)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xFFBFFFFFU)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xFFFEAFFFU)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0xBBFFFFFFU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0xFFFF5FEFU)
#elif defined(S32K311) || defined(S32K310)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xFFFFFFFAU)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x1DF6ACFFU)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0x93F03E0EU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x000001BBU)
#elif defined(S32M276) || defined(S32M274)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xFFFFFFFAU)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x1DF6ACFFU)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0x93E03E0EU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x00000FFFU)
#elif defined(S32K312)
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xF1C0FFF8U)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x1DFEACFFU)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0xB3F3FE7EU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x00000001U)
#else
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xF1C0FFF8U)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0x812AA407U)
#define PRTN1_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0xBBF3FE7EU)
#define PRTN1_COFB3_CLKEN_REQ_MASK_U32      ((uint32)0x00000001U)
#endif
/*Partition 2*/

#if defined(S32K342) || defined(S32K341)
#define PRTN2_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x29FFFFF0U)
#define PRTN2_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xC8880001U)
#elif defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358)
/* 
    S32K358 contains SWT2 instance. But in RM, PRTN2_COFB0_CLKEN[REQ28] is reserved.
    May be this information is wrong.
*/
#define PRTN2_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x7FFFFFF7U)
#define PRTN2_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xCE8987FAU)
#define PRTN2_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0x00000039U)
#elif defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
#define PRTN2_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x7BFFFFF3U)
#define PRTN2_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xF8098001U)
#define PRTN2_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0x00000FFFU)
#elif defined(S32K388)
#define PRTN2_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0xFFFFFFFFU)
#define PRTN2_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xCC8987FEU)
#define PRTN2_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0x0FFFFF7BU)
#else
#define PRTN2_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x29FFFFF0U)
#define PRTN2_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xCC8987F9U)
#endif

/*Partition 3*/
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
#define PRTN3_COFB0_CLKEN_REQ_MASK_U32      ((uint32)0x6000FFFFU)
#define PRTN3_COFB1_CLKEN_REQ_MASK_U32      ((uint32)0xEFFFD33DU)
#define PRTN3_COFB2_CLKEN_REQ_MASK_U32      ((uint32)0x00000003U)
#endif

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/* static uint32 firc_clk_freq = 0U; */

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

static int Init_FIRC(void);
static int Init_FXOSC(void);
static int Init_PMC(void);
static int Init_PLL(void);
static int Init_MC_CGM(void);
static int Switch_Core_FIRC(void);
static int Init_MC_ME(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief sys_enableAllInterrupts
* @details function used to enable all interrupts
*/
/*================================================================================================*/
void sys_enableAllInterrupts(void)
{
    OsIf_ResumeAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_disableAllInterrupts
* @details function used to disable all interrupts
*/
/*================================================================================================*/
void sys_disableAllInterrupts(void)
{
    OsIf_SuspendAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_disableIsrSource
* @details function used to disable the interrupt number id
*/
/*================================================================================================*/
void sys_disableIsrSource(uint8 id)
{
    NVIC_DisableIRQ(id);
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to enable the interrupt number id and set up the priority
*/
/*================================================================================================*/
void sys_enableIsrSource(uint8 id, uint8 prio)
{
    NVIC_SetPriority(id, prio);
    NVIC_EnableIRQ(id);
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to register the interrupt handler in the interrupt vector
*/
/*================================================================================================*/
void sys_registerIsrHandler(uint8 irq_id, int_function_t isr_handler)
{
    OsIf_SuspendAllInterrupts();
    *(volatile uint32*)((*(volatile uint32*)(0xE000ED08)) + ((16 + irq_id) << 2)) = (uint32)isr_handler;
    OsIf_ResumeAllInterrupts();
}

/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
 */

/*-----------------------------------------------------------------------*/
/* Initialize & Start FIRC = 48MHz                                       */
/*-----------------------------------------------------------------------*/
static int Init_FIRC(void)
{
    volatile uint32 timeout = 0xFFFF;
    volatile int result = 0;
#if !defined(S32K396) && !defined(S32M276) && !defined(S32K394) && !defined(S32M274) && !defined(S32K376) && !defined(S32K374) && !defined(S32K364) && !defined(S32K366)
    /* Header bug: CONFIG_REG_GPR is actually RW. We'll manually cast-away the const */
    volatile uint32 *io_config_reg_gpr = (volatile uint32*) &IP_CONFIGURATION_GPR->CONFIG_REG_GPR;

    /* Check if application cores have access to FIRC_DIV_SEL */
    if (((IP_CONFIGURATION_GPR->CONFIG_REG_GPR & CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_MASK) >> CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT) == 5)
    {
        *io_config_reg_gpr = CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC(0x5) | CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL(3);
        /* firc_clk_freq = 48000000; */
    }
    else
    {
        /* switch (((IP_CONFIGURATION_GPR->CONFIG_REG_GPR & CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK) >> CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_SHIFT))
        {
            case 0:
            case 1:  { firc_clk_freq = 24000000U;   break; }
            case 2:  { firc_clk_freq = 3000000U;    break; }
            case 3:  { firc_clk_freq = 48000000U;   break; }
            default: { firc_clk_freq = 0xFFFFFFFFU; break; }
        } */
    }
#endif

    while ((((IP_FIRC->STATUS_REGISTER & FIRC_STATUS_REGISTER_STATUS_MASK) >> FIRC_STATUS_REGISTER_STATUS_SHIFT) != 1) && (timeout--)) {}
    if (timeout == 0)
    {
        result = 1; /* FIRC_TIMEOUT */
    }
    else
    {
    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize & Start FXOSC = 16MHz (CVB-257BGA DC)                      */
/*-----------------------------------------------------------------------*/
static int Init_FXOSC(void)
{
    volatile uint32 timeout = 0xFFFF;
    volatile int result = 0;

    /* Set "Crystal Mode" */
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_EOCV_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_EOCV(0x9D);
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_GM_SEL_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_GM_SEL(0xC);
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_OSC_BYP_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_OSC_BYP(0);
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_COMP_EN_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_COMP_EN(1);
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_OSCON_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_OSCON(1);
    while ((((IP_FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) >> FXOSC_STAT_OSC_STAT_SHIFT) != 1) && (timeout--)) {}
    if(timeout == 0)
    {
        result = 1;/* FXOSC_TIMEOUT */
    }
    else
    {

    }

    return result; /*Success*/
}

/*-----------------------------------------------------------------------*/
/* Initialize PMC (CVB-257BGA DC)                                        */
/*-----------------------------------------------------------------------*/
static int Init_PMC(void)
{
    volatile uint32 timeout = 0xFFFF;
    volatile int result = 0;

    /* Clear LVSC flags after the initial power ramp-up */
    IP_PMC->LVSC = 0xFFFFFFFFU;

#if defined(S32K388)
        /* Disable SMPS regulator */
        IP_PMC->CONFIG &= ~PMC_CONFIG_LMSMPSEN_MASK;
#endif
    /* Check if Last Mile Regulator is available */
    if ( ((IP_PMC->VERID & PMC_VERID_LMFEAT_MASK) >> PMC_VERID_LMFEAT_SHIFT) == 1)
    {
#if !defined(S32K388) && !defined(S32K396) && !defined(S32K394) && !defined(S32K376) && !defined(S32K374) && !defined(S32K364) && !defined(S32K366)
        /* Set slow recovery from LPM to avoid high-current demand */
        IP_PMC->CONFIG &= ~PMC_CONFIG_FASTREC_MASK;
        IP_PMC->CONFIG |= PMC_CONFIG_FASTREC(0);
#endif
        /* External BJT between VDD_HD_A and V15 on PCB => Enable Last Mile Regulator Base Control */
#if !defined(S32K311) && !defined(S32K312) && !defined(S32K396) && !defined(S32K358) && !defined(S32K388) \
    && !defined(S32K328) && !defined(S32K338) && !defined(S32K348) && !defined(S32M276) && !defined(S32K394) \
    && !defined(S32K310) && !defined(S32M274) && !defined(S32K376) && !defined(S32K374) && !defined(S32K364) && !defined(S32K366)
        IP_PMC->CONFIG &= ~PMC_CONFIG_LMBCTLEN_MASK;
        IP_PMC->CONFIG |= PMC_CONFIG_LMBCTLEN(1);
#endif

        /* Wait for soft start time of the V15 regulator (>50us) */
        while (timeout--) {}
        timeout = 0xFFFF;

#if !defined(S32K311) && !defined(S32K312) && !defined(S32K396) && !defined(S32K358) && !defined(S32K388) \
    && !defined(S32K328) && !defined(S32K338) && !defined(S32K348) && !defined(S32M276) && !defined(S32K394) \
    && !defined(S32K310) && !defined(S32M274) && !defined(S32K376) && !defined(S32K374) && !defined(S32K364) && !defined(S32K366)
        /* Start polling the status of the V15 regulator */
        while ((((IP_PMC->LVSC & PMC_LVSC_LVD15S_MASK) >> PMC_LVSC_LVD15S_SHIFT) != 0) && (timeout--)) {}
        if (timeout > 0)
        {
            timeout = 0xFFFF;
            /* Set automatic Last Mile turn-over */
            IP_PMC->CONFIG &= ~PMC_CONFIG_LMAUTOEN_MASK;
            IP_PMC->CONFIG |= PMC_CONFIG_LMAUTOEN(1);

            /* Wait for the PMC to switch from Boot Regulator to Last Mile regulator */
            while ((((IP_PMC->CONFIG & PMC_CONFIG_LMSTAT_MASK) >> PMC_CONFIG_LMSTAT_SHIFT) != 1) && (timeout--)) {}
            if (timeout == 0)
            {
                result = 1;/* LMSTAT_TIMEOUT */
            }
            else
            {

            }
        }
        else
        {
            result = 1;/* LVDV15S_TIMEOUT */
        }

#endif
    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize PLL                                                        */
/* FXOSC = 16MHz, VCO = 480MHz, PHI0 = 160MHz, PHI1 = 240MHz             */
/* lcm(160, 240) = 2^5 * 3 * 5 = 480 => VCO = 480MHz                     */
/*-----------------------------------------------------------------------*/
static int Init_PLL(void)
{
    volatile uint32 timeout = 0xFFFF;
    volatile int result = 0;

    /* Analog PLL for Core
     * <SDMEN=0, SSCGBYP=1 => PLL in integer-only mode>
     * Fvco = Fref x (PLLDV[MFI] / PLLDV[RDIV])
     * Fclkout = Fvco / (PLLODIV_n[DIV] + 1)
     * Fvco(PLL) = 480MHz
     * f(pll_ref) = 16d (16Mhz)
     * PLLDV[RDIV] = 1
     * PLLDV[MFI] = 30d (0x1E)
     */

    IP_PLL->PLLODIV[0] &= ~PLL_PLLODIV_DE_MASK;
    IP_PLL->PLLODIV[0] |= PLL_PLLODIV_DE(0);                   /* Disable PHI0 output */
    IP_PLL->PLLODIV[1] &= ~PLL_PLLODIV_DE_MASK;
    IP_PLL->PLLODIV[1] |= PLL_PLLODIV_DE(0);                   /* Disable PHI1 output */

    IP_PLL->PLLCR &= ~PLL_PLLCR_PLLPD_MASK;
    IP_PLL->PLLCR |= PLL_PLLCR_PLLPD(1);                       /* Disable PLL */

    IP_PLL->PLLDV &= ~PLL_PLLDV_ODIV2_MASK;
    IP_PLL->PLLDV |= PLL_PLLDV_ODIV2(0);
    IP_PLL->PLLDV &= ~PLL_PLLDV_RDIV_MASK;
    IP_PLL->PLLDV |= PLL_PLLDV_RDIV(1);                        /* FXOSC = 16MHz / 1 = 16MHz input frequency */
                                                               /* For S32K39x: FXOSC = 40MHz / 1 = 40MHz input frequency */
    IP_PLL->PLLDV &= ~PLL_PLLDV_MFI_MASK;
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_PLL->PLLDV |= PLL_PLLDV_MFI(12);                        /* For S32K39x: FXOSC = 40MHz * 12 = 480MHz VCO frequency */
#else
    IP_PLL->PLLDV |= PLL_PLLDV_MFI(30);                        /* FXOSC = 16MHz * 30 = 480MHz VCO frequency */
#endif
    IP_PLL->PLLFD &= ~PLL_PLLFD_SDMEN_MASK;
    IP_PLL->PLLFD |= PLL_PLLFD_SDMEN(0);                       /* Disable Frac-N mode */
    IP_PLL->PLLFD &= ~PLL_PLLFD_SDM2_MASK;
    IP_PLL->PLLFD |= PLL_PLLFD_SDM2(1);                        /* Enable 2-order SDM */
    IP_PLL->PLLFD &= ~PLL_PLLFD_SDM3_MASK;
    IP_PLL->PLLFD |= PLL_PLLFD_SDM3(1);                        /* Enable 3-order SDM */
    IP_PLL->PLLFD &= ~PLL_PLLFD_MFN_MASK;
    IP_PLL->PLLFD |= PLL_PLLFD_MFN(0);                         /* No fractional divider */

    IP_PLL->PLLFM &= ~PLL_PLLFM_SSCGBYP_MASK;
    IP_PLL->PLLFM |= PLL_PLLFM_SSCGBYP(1);                     /* Bypass modulation */
    IP_PLL->PLLFM &= ~PLL_PLLFM_STEPNO_MASK;
    IP_PLL->PLLFM |= PLL_PLLFM_STEPNO(0);
    IP_PLL->PLLFM &= ~PLL_PLLFM_SPREADCTL_MASK;
    IP_PLL->PLLFM |= PLL_PLLFM_SPREADCTL(1);                   /* Only down-spread modulation supported */
    IP_PLL->PLLFM &= ~PLL_PLLFM_STEPSIZE_MASK;
    IP_PLL->PLLFM |= PLL_PLLFM_STEPSIZE(0);

if ( ((IP_PLL->PLLFM & PLL_PLLFM_SSCGBYP_MASK) >> PLL_PLLFM_SSCGBYP_SHIFT) == 1 ) {
    IP_PLL->PLLCAL2 &= ~PLL_PLLCAL2_ULKCTL_MASK;
    IP_PLL->PLLCAL2 |= PLL_PLLCAL2_ULKCTL(0);                  /* Set lock accuracy to PLLDV[MFI] +/- 9 */
} else {
    IP_PLL->PLLCAL2 &= ~PLL_PLLCAL2_ULKCTL_MASK;
    IP_PLL->PLLCAL2 |= PLL_PLLCAL2_ULKCTL(1);                  /* Set lock accuracy to PLLDV[MFI] +/- 17 */
}

    IP_PLL->PLLODIV[0] &= ~PLL_PLLODIV_DIV_MASK;

    IP_PLL->PLLODIV[0] |= PLL_PLLODIV_DIV(2);                  /* PHI0 = VCO / (ODIV_0 + 1) = 480 / 3 = 160MHz */

    IP_PLL->PLLODIV[1] &= ~PLL_PLLODIV_DIV_MASK;
    IP_PLL->PLLODIV[1] |= PLL_PLLODIV_DIV(1);                  /* PHI1 = VCO / (ODIV_1 + 1) = 480 / 2 = 240MHz */

    IP_PLL->PLLCR &= ~PLL_PLLCR_PLLPD_MASK;
    IP_PLL->PLLCR |= PLL_PLLCR_PLLPD(0);                       /* Enable PLL */

    /* Wait for PLL lock */
    while((((IP_PLL->PLLSR & PLL_PLLSR_LOCK_MASK) >> PLL_PLLSR_LOCK_SHIFT) != 1) && (timeout--)) {}
    if(timeout == 0)
    {
        result = 1;/* PLL_TIMEOUT */
    }
    else
    {

    }

    IP_PLL->PLLODIV[0] &= ~PLL_PLLODIV_DE_MASK;
    IP_PLL->PLLODIV[0] |= PLL_PLLODIV_DE(1);                   /* Enable PHI0 output */
    IP_PLL->PLLODIV[1] &= ~PLL_PLLODIV_DE_MASK;
    IP_PLL->PLLODIV[1] |= PLL_PLLODIV_DE(1);                   /* Enable PHI1 output */

    return result;
}


/*-----------------------------------------------------------------------*/
/* Initialize MC_CGM                                                     */
/*-----------------------------------------------------------------------*/
/* Table 23.4.2 MC_CGM clock source mapping
*       Clock selector index    Clock source
*       0                       FIRC_CLK
*       1                       SIRC_CLK
*       2                       FXOSC_CLK
*       4                       SXOSC_CLK
*       8                       PLL_PHI0_CLK
*       9                       PLL_PHI1_CLK
*       16                      CORE_CLK
*       19                      HSE_CLK
*       22                      AIPS_PLAT_CLK
*       23                      AIPS_SLOW_CLK
*       24                      EMAC_RMII_TX_CLK
*       25                      EMAC_RX_CLK
*/

/* Summary:
*  Option F - Operation in 1:1 mode with CORE_CLK and AXBS_CLK at same speed
*  SysClk_Source            = PLL_PHI0_CLK, CORE_CLK = 80MHz, AIPS_PLAT_CLK = 80MHz, AIPS_SLOW_CLK = 40MHz, HSE_CLK = 80MHz, DCM_CLK = 40MHz, LBIST = 40MHz, QSPI_MEM_CLK = 160MHz
*  STM0_CLK_Source          = AIPS_PLAT_CLK, STM0_CLK = 80MHz
*  STM1_CLK_Source          = AIPS_PLAT_CLK, STM1_CLK = 80MHz
*  STM2_CLK_Source          = AIPS_PLAT_CLK, STM1_CLK = 80MHz
*  FLEXCAN0-2_PE_CLK_Source = AIPS_SLOW_CLK, FLEXCAN0-2_PE_CLK = 40 MHz
*  FLEXCAN3-5_PE_CLK_Source = AIPS_SLOW_CLK, FLEXCAN3-5_PE_CLK = 40 MHz
*  CLKOUT_STANDBY           = Disabled
*  CLKOUT_RUN               = Disabled
*  EMAC_CLK_RX_Source       = EMAC_MII_RMII_TX_CLK, EMAC_CLK_RX = 50MHz
*  EMAC_CLK_TX_Source       = EMAC_MII_RMII_TX_CLK, EMAC_CLK_TX = 50MHz
*  EMAC_CLK_TS_Source       = EMAC_MII_RMII_TX_CLK, EMAC_CLK_TS = 50MHz
*  QSPI_SFCK_Source         = PLL_PHI1_CLK, QSPI_SFCK = 80MHz
*  TRACE_CLK_Source         = Default value
*/
static int Init_MC_CGM(void)
{
    /* Configure MC_CGM Dividers */
    /* Update dividers alignment policy */
    IP_MC_CGM->MUX_0_DIV_TRIG_CTRL &= ~MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_MASK;
    IP_MC_CGM->MUX_0_DIV_TRIG_CTRL |= MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN(1U);
    IP_MC_CGM->MUX_0_DIV_TRIG_CTRL &= ~MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK;
    IP_MC_CGM->MUX_0_DIV_TRIG_CTRL |= MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL(1U);

    /* Option F (Can be changed to Option A by simply setting DC_0_DIV = 0) */
    IP_MC_CGM->MUX_0_DC_0 &= ~MC_CGM_MUX_0_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_0 |= MC_CGM_MUX_0_DC_0_DIV(1U);    /* CORE_CLK */
    IP_MC_CGM->MUX_0_DC_1 &= ~MC_CGM_MUX_0_DC_1_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_1 |= MC_CGM_MUX_0_DC_1_DIV(1U);    /* AIPS_PLAT_CLK */
    IP_MC_CGM->MUX_0_DC_2 &= ~MC_CGM_MUX_0_DC_2_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_2 |= MC_CGM_MUX_0_DC_2_DIV(3U);    /* AIPS_SLOW_CLK 40Mhz */
    IP_MC_CGM->MUX_0_DC_3 &= ~MC_CGM_MUX_0_DC_3_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_3 |= MC_CGM_MUX_0_DC_3_DIV(1U);    /* HSE_CLK */
    IP_MC_CGM->MUX_0_DC_4 &= ~MC_CGM_MUX_0_DC_4_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_4 |= MC_CGM_MUX_0_DC_4_DIV(3U);    /* DCM_CLK */
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_0_DC_5 &= ~MC_CGM_MUX_0_DC_5_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_5 |= MC_CGM_MUX_0_DC_5_DIV(3U);    /* LBIST_CLK */
    IP_MC_CGM->MUX_0_DC_6 &= ~MC_CGM_MUX_0_DC_6_DIV_MASK;
    IP_MC_CGM->MUX_0_DC_6 |= MC_CGM_MUX_0_DC_6_DIV(0U);    /* QSPI_MEM_CLK */
#endif
    /* Trigger dividers update */
    IP_MC_CGM->MUX_0_DIV_TRIG = 0xFFFFFFFFU;

    IP_MC_CGM->MUX_1_DC_0  &= ~MC_CGM_MUX_1_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_1_DC_0  |= MC_CGM_MUX_1_DC_0_DIV(0U);    /* STM0_CLK */
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_2_DC_0  &= ~MC_CGM_MUX_2_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_2_DC_0  |= MC_CGM_MUX_2_DC_0_DIV(0U);    /* STM1_CLK */
#endif

#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_CGM->MUX_13_DC_0  &= ~MC_CGM_MUX_13_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_13_DC_0  |= MC_CGM_MUX_13_DC_0_DIV(0U);    /* STM2_CLK */
#endif
    IP_MC_CGM->MUX_3_DC_0  &= ~MC_CGM_MUX_3_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_3_DC_0  |= MC_CGM_MUX_3_DC_0_DIV(0U);    /* FLEXCAN0-2_PE_CLK */
#if !defined(S32K311) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_4_DC_0  &= ~MC_CGM_MUX_4_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_4_DC_0  |= MC_CGM_MUX_4_DC_0_DIV(0U);    /* FLEXCAN3-5_PE_CLK */
#endif
    IP_MC_CGM->MUX_5_DC_0  &= ~MC_CGM_MUX_5_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_5_DC_0  |= MC_CGM_MUX_5_DC_0_DIV(0U);    /* CLKOUT_STANDBY */
    IP_MC_CGM->MUX_6_DC_0  &= ~MC_CGM_MUX_6_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_6_DC_0  |= MC_CGM_MUX_6_DC_0_DIV(0U);    /* CLKOUT_RUN */
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_7_DC_0  &= ~MC_CGM_MUX_7_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_7_DC_0  |= MC_CGM_MUX_7_DC_0_DIV(1U);    /* EMAC_RX_CLK */
    IP_MC_CGM->MUX_8_DC_0  &= ~MC_CGM_MUX_8_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_8_DC_0  |= MC_CGM_MUX_8_DC_0_DIV(1U);    /* EMAC_TX_CLK */
    IP_MC_CGM->MUX_9_DC_0  &= ~MC_CGM_MUX_9_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_9_DC_0  |= MC_CGM_MUX_9_DC_0_DIV(0U);    /* EMAC_TS_CLK */
    IP_MC_CGM->MUX_10_DC_0 &= ~MC_CGM_MUX_10_DC_0_DIV_MASK;
    IP_MC_CGM->MUX_10_DC_0 |= MC_CGM_MUX_10_DC_0_DIV(2U);   /* QUADSPI_SFCK */
#endif

    /* Wait until divider configuration update has finished */
    while (1U == ((IP_MC_CGM->MUX_0_DIV_UPD_STAT  & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_1_DIV_UPD_STAT  & MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (1U == ((IP_MC_CGM->MUX_2_DIV_UPD_STAT  & MC_CGM_MUX_2_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_2_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
#endif
    while (1U == ((IP_MC_CGM->MUX_3_DIV_UPD_STAT  & MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
#if !defined(S32K311) &&  !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (1U == ((IP_MC_CGM->MUX_4_DIV_UPD_STAT  & MC_CGM_MUX_4_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_4_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
#endif
    while (1U == ((IP_MC_CGM->MUX_5_DIV_UPD_STAT  & MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_6_DIV_UPD_STAT  & MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
#if !defined(S32K311) && !defined(S32K312) &&  !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (1U == ((IP_MC_CGM->MUX_7_DIV_UPD_STAT  & MC_CGM_MUX_7_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_7_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_8_DIV_UPD_STAT  & MC_CGM_MUX_8_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_8_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_9_DIV_UPD_STAT  & MC_CGM_MUX_9_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_9_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_10_DIV_UPD_STAT & MC_CGM_MUX_10_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_10_DIV_UPD_STAT_DIV_STAT_SHIFT)) {}
#endif
#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    while (1U == ((IP_MC_CGM->MUX_13_DIV_UPD_STAT  & MC_CGM_MUX_13_DIV_UPD_STAT_DIV_STAT_MASK)  >> MC_CGM_MUX_13_DIV_UPD_STAT_DIV_STAT_SHIFT))  {}
#endif
    /* Switch MC_CGM Dividers */
    IP_MC_CGM->MUX_0_DC_0 &= ~MC_CGM_MUX_0_DC_0_DE_MASK;
    IP_MC_CGM->MUX_0_DC_0 |= MC_CGM_MUX_0_DC_0_DE(1U);     /* CORE_CLK */
    IP_MC_CGM->MUX_0_DC_1 &= ~MC_CGM_MUX_0_DC_1_DE_MASK;
    IP_MC_CGM->MUX_0_DC_1 |= MC_CGM_MUX_0_DC_1_DE(1U);     /* AIPS_PLAT_CLK */
    IP_MC_CGM->MUX_0_DC_2 &= ~MC_CGM_MUX_0_DC_2_DE_MASK;
    IP_MC_CGM->MUX_0_DC_2 |= MC_CGM_MUX_0_DC_2_DE(1U);     /* AIPS_SLOW_CLK */
    IP_MC_CGM->MUX_0_DC_3 &= ~MC_CGM_MUX_0_DC_3_DE_MASK;
    IP_MC_CGM->MUX_0_DC_3 |= MC_CGM_MUX_0_DC_3_DE(1U);     /* HSE_CLK */
    IP_MC_CGM->MUX_0_DC_4 &= ~MC_CGM_MUX_0_DC_4_DE_MASK;
    IP_MC_CGM->MUX_0_DC_4 |= MC_CGM_MUX_0_DC_4_DE(1U);     /* DCM_CLK */
#if !defined(S32K311) && !defined(S32K312) &&  !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_0_DC_5 &= ~MC_CGM_MUX_0_DC_5_DE_MASK;
    IP_MC_CGM->MUX_0_DC_5 |= MC_CGM_MUX_0_DC_5_DE(1U);     /* LBIST_CLK */
    IP_MC_CGM->MUX_0_DC_6 &= ~MC_CGM_MUX_0_DC_6_DE_MASK;
    IP_MC_CGM->MUX_0_DC_6 |= MC_CGM_MUX_0_DC_6_DE(1U);     /* QSPI_MEM_CLK */
#endif
    IP_MC_CGM->MUX_1_DC_0  &= ~MC_CGM_MUX_1_DC_0_DE_MASK;
    IP_MC_CGM->MUX_1_DC_0  |= MC_CGM_MUX_1_DC_0_DE(1U);    /* STM0_CLK */
#if !defined(S32K311) && !defined(S32K312) &&  !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_2_DC_0  &= ~MC_CGM_MUX_2_DC_0_DE_MASK;
    IP_MC_CGM->MUX_2_DC_0  |= MC_CGM_MUX_2_DC_0_DE(1U);    /* STM1_CLK */
#endif
#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_CGM->MUX_13_DC_0  &= ~MC_CGM_MUX_13_DC_0_DE_MASK;
    IP_MC_CGM->MUX_13_DC_0  |= MC_CGM_MUX_13_DC_0_DE(1U);    /* STM2_CLK */
#endif
    IP_MC_CGM->MUX_3_DC_0  &= ~MC_CGM_MUX_3_DC_0_DE_MASK;
    IP_MC_CGM->MUX_3_DC_0  |= MC_CGM_MUX_3_DC_0_DE(1U);    /* FLEXCAN0-2_PE_CLK */
#if !defined(S32K311) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_4_DC_0  &= ~MC_CGM_MUX_4_DC_0_DE_MASK;
    IP_MC_CGM->MUX_4_DC_0  |= MC_CGM_MUX_4_DC_0_DE(1U);    /* FLEXCAN3-5_PE_CLK */
#endif
    IP_MC_CGM->MUX_5_DC_0  &= ~MC_CGM_MUX_5_DC_0_DE_MASK;
    IP_MC_CGM->MUX_5_DC_0  |= MC_CGM_MUX_5_DC_0_DE(0U);    /* CLKOUT_STANDBY */
    IP_MC_CGM->MUX_6_DC_0  &= ~MC_CGM_MUX_6_DC_0_DE_MASK;
    IP_MC_CGM->MUX_6_DC_0  |= MC_CGM_MUX_6_DC_0_DE(0U);    /* CLKOUT_RUN */
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_7_DC_0  &= ~MC_CGM_MUX_7_DC_0_DE_MASK;
    IP_MC_CGM->MUX_7_DC_0  |= MC_CGM_MUX_7_DC_0_DE(1U);    /* EMAC_RX_CLK */
    IP_MC_CGM->MUX_8_DC_0  &= ~MC_CGM_MUX_8_DC_0_DE_MASK;
    IP_MC_CGM->MUX_8_DC_0  |= MC_CGM_MUX_8_DC_0_DE(1U);    /* EMAC_TX_CLK */
    IP_MC_CGM->MUX_9_DC_0  &= ~MC_CGM_MUX_9_DC_0_DE_MASK;
    IP_MC_CGM->MUX_9_DC_0  |= MC_CGM_MUX_9_DC_0_DE(1U);    /* EMAC_TS_CLK */
    IP_MC_CGM->MUX_10_DC_0 &= ~MC_CGM_MUX_10_DC_0_DE_MASK;
    IP_MC_CGM->MUX_10_DC_0 |= MC_CGM_MUX_10_DC_0_DE(1U);   /* QUADSPI_SFCK */
#endif
#if defined(S32K388)
    IP_MC_CGM->MUX_18_DC_0  &= ~MC_CGM_MUX_18_DC_0_DE_MASK;
    IP_MC_CGM->MUX_18_DC_0  |= MC_CGM_MUX_18_DC_0_DE(1U);    
    IP_MC_CGM->MUX_19_DC_0 &= ~MC_CGM_MUX_19_DC_0_DE_MASK;
    IP_MC_CGM->MUX_19_DC_0 |= MC_CGM_MUX_19_DC_0_DE(1U);   
#endif
    /* Select MC_CGM sources */
    IP_MC_CGM->MUX_0_CSC  &= ~MC_CGM_MUX_0_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_0_CSC  |= MC_CGM_MUX_0_CSC_SELCTL(8);        /* Select PLL_PHI0_CLK (OUT: SYS_CLK) */
    IP_MC_CGM->MUX_1_CSC  &= ~MC_CGM_MUX_1_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_1_CSC  |= MC_CGM_MUX_1_CSC_SELCTL(22);        /* Select AIPS_PLAT_CLK (OUT: STM0_CLK) */
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_2_CSC  &= ~MC_CGM_MUX_2_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_2_CSC  |= MC_CGM_MUX_2_CSC_SELCTL(22);        /* Select AIPS_PLAT_CLK (OUT: STM1_CLK) */
#endif
#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_CGM->MUX_13_CSC  &= ~MC_CGM_MUX_13_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_13_CSC  |= MC_CGM_MUX_13_CSC_SELCTL(22);        /* Select AIPS_PLAT_CLK (OUT: STM2_CLK) */
#endif
    IP_MC_CGM->MUX_3_CSC  &= ~MC_CGM_MUX_3_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_3_CSC  |= MC_CGM_MUX_3_CSC_SELCTL(22);        /* Select AIPS_PLAT_CLK (OUT: FLEXCAN0-2_PE_CLK) */
#if !defined(S32K311) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_4_CSC  &= ~MC_CGM_MUX_4_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_4_CSC  |= MC_CGM_MUX_4_CSC_SELCTL(22);        /* Select AIPS_PLAT_CLK (OUT: FLEXCAN3-5_PE_CLK) */
#endif
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_7_CSC  &= ~MC_CGM_MUX_7_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_7_CSC  |= MC_CGM_MUX_7_CSC_SELCTL(24);        /* Select EMAC_MII_RMII_TX_CLK (OUT: EMAC_RX_CLK) */
    IP_MC_CGM->MUX_8_CSC  &= ~MC_CGM_MUX_8_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_8_CSC  |= MC_CGM_MUX_8_CSC_SELCTL(24);        /* Select EMAC_MII_RMII_TX_CLK (OUT: EMAC_TX_CLK) */
    IP_MC_CGM->MUX_9_CSC  &= ~MC_CGM_MUX_9_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_9_CSC  |= MC_CGM_MUX_9_CSC_SELCTL(24);        /* Select EMAC_MII_RMII_TX_CLK (OUT: EMAC_TS_CLK) */
    IP_MC_CGM->MUX_10_CSC &= ~MC_CGM_MUX_10_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_10_CSC |= MC_CGM_MUX_10_CSC_SELCTL(9);        /* Select PLL_PHI1_CLK (OUT: QUADSPI_SFCK) */
#endif
#if defined(S32K388)
    IP_MC_CGM->MUX_18_CSC &= ~MC_CGM_MUX_18_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_18_CSC |= MC_CGM_MUX_18_CSC_SELCTL(0);        /* Select FIRC_CLK */
    IP_MC_CGM->MUX_19_CSC &= ~MC_CGM_MUX_19_CSC_SELCTL_MASK;
    IP_MC_CGM->MUX_19_CSC |= MC_CGM_MUX_19_CSC_SELCTL(0);        /* Select FIRC_CLK */
#endif
    /* Switch MC_CGM sources */
    IP_MC_CGM->MUX_0_CSC  &= ~MC_CGM_MUX_0_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_0_CSC  |= MC_CGM_MUX_0_CSC_CLK_SW(1) | MC_CGM_MUX_0_CSC_RAMPUP(1) | MC_CGM_MUX_0_CSC_RAMPDOWN(1);
    IP_MC_CGM->MUX_1_CSC  &= ~MC_CGM_MUX_1_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_1_CSC  |= MC_CGM_MUX_1_CSC_CLK_SW(1);
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_2_CSC  &= ~MC_CGM_MUX_2_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_2_CSC  |= MC_CGM_MUX_2_CSC_CLK_SW(1);
#endif
    IP_MC_CGM->MUX_3_CSC  &= ~MC_CGM_MUX_3_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_3_CSC  |= MC_CGM_MUX_3_CSC_CLK_SW(1);
#if !defined(S32K311) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_4_CSC  &= ~MC_CGM_MUX_4_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_4_CSC  |= MC_CGM_MUX_4_CSC_CLK_SW(1);
#endif
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_CGM->MUX_7_CSC  &= ~MC_CGM_MUX_7_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_7_CSC  |= MC_CGM_MUX_7_CSC_CLK_SW(1);
    IP_MC_CGM->MUX_8_CSC  &= ~MC_CGM_MUX_8_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_8_CSC  |= MC_CGM_MUX_8_CSC_CLK_SW(1);
    IP_MC_CGM->MUX_9_CSC  &= ~MC_CGM_MUX_9_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_9_CSC  |= MC_CGM_MUX_9_CSC_CLK_SW(1);
    IP_MC_CGM->MUX_10_CSC &= ~MC_CGM_MUX_10_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_10_CSC |= MC_CGM_MUX_10_CSC_CLK_SW(1);
#endif
#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_CGM->MUX_13_CSC  &= ~MC_CGM_MUX_13_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_13_CSC  |= MC_CGM_MUX_13_CSC_CLK_SW(1);
#endif
#if defined(S32K388)
    IP_MC_CGM->MUX_18_CSC  &= ~MC_CGM_MUX_18_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_18_CSC  |= MC_CGM_MUX_18_CSC_CLK_SW(1);
    IP_MC_CGM->MUX_19_CSC  &= ~MC_CGM_MUX_19_CSC_CLK_SW_MASK;
    IP_MC_CGM->MUX_19_CSC  |= MC_CGM_MUX_19_CSC_CLK_SW(1);
#endif
    /* Wait for configuration bits to auto-clear */
    while (0U == ((IP_MC_CGM->MUX_0_CSS  & MC_CGM_MUX_0_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_0_CSS_CLK_SW_SHIFT))  {}
    while (0U == ((IP_MC_CGM->MUX_1_CSS  & MC_CGM_MUX_1_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_1_CSS_CLK_SW_SHIFT))  {}
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (0U == ((IP_MC_CGM->MUX_2_CSS  & MC_CGM_MUX_2_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_2_CSS_CLK_SW_SHIFT))  {}
#endif
    while (0U == ((IP_MC_CGM->MUX_3_CSS  & MC_CGM_MUX_3_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_3_CSS_CLK_SW_SHIFT))  {}
#if !defined(S32K311) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (0U == ((IP_MC_CGM->MUX_4_CSS  & MC_CGM_MUX_4_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_4_CSS_CLK_SW_SHIFT))  {}
#endif
#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    while (0U == ((IP_MC_CGM->MUX_13_CSS  & MC_CGM_MUX_13_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_13_CSS_CLK_SW_SHIFT))  {}
#endif
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (0U == ((IP_MC_CGM->MUX_7_CSS  & MC_CGM_MUX_7_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_7_CSS_CLK_SW_SHIFT))  {}
    while (0U == ((IP_MC_CGM->MUX_8_CSS  & MC_CGM_MUX_8_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_8_CSS_CLK_SW_SHIFT))  {}
    while (0U == ((IP_MC_CGM->MUX_9_CSS  & MC_CGM_MUX_9_CSS_CLK_SW_MASK)  >> MC_CGM_MUX_9_CSS_CLK_SW_SHIFT))  {}
    while (0U == ((IP_MC_CGM->MUX_10_CSS & MC_CGM_MUX_10_CSS_CLK_SW_MASK) >> MC_CGM_MUX_10_CSS_CLK_SW_SHIFT)) {}
#endif
    /* Wait for the clock switch to complete */
    while (1U == ((IP_MC_CGM->MUX_0_CSS  & MC_CGM_MUX_0_CSS_SWIP_MASK)  >> MC_CGM_MUX_0_CSS_SWIP_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_1_CSS  & MC_CGM_MUX_1_CSS_SWIP_MASK)  >> MC_CGM_MUX_1_CSS_SWIP_SHIFT))  {}
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (1U == ((IP_MC_CGM->MUX_2_CSS  & MC_CGM_MUX_2_CSS_SWIP_MASK)  >> MC_CGM_MUX_2_CSS_SWIP_SHIFT))  {}
#endif
    while (1U == ((IP_MC_CGM->MUX_3_CSS  & MC_CGM_MUX_3_CSS_SWIP_MASK)  >> MC_CGM_MUX_3_CSS_SWIP_SHIFT))  {}
#if !defined(S32K311) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (1U == ((IP_MC_CGM->MUX_4_CSS  & MC_CGM_MUX_4_CSS_SWIP_MASK)  >> MC_CGM_MUX_4_CSS_SWIP_SHIFT))  {}
#endif

#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (1U == ((IP_MC_CGM->MUX_7_CSS  & MC_CGM_MUX_7_CSS_SWIP_MASK)  >> MC_CGM_MUX_7_CSS_SWIP_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_8_CSS  & MC_CGM_MUX_8_CSS_SWIP_MASK)  >> MC_CGM_MUX_8_CSS_SWIP_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_9_CSS  & MC_CGM_MUX_9_CSS_SWIP_MASK)  >> MC_CGM_MUX_9_CSS_SWIP_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_10_CSS & MC_CGM_MUX_10_CSS_SWIP_MASK) >> MC_CGM_MUX_10_CSS_SWIP_SHIFT)) {}
#endif
#if defined(S32K396) || defined(S32K358) || defined(S32K394) || defined(S32K328) || defined(S32K338) || defined(S32K348) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    while (1U == ((IP_MC_CGM->MUX_13_CSS  & MC_CGM_MUX_13_CSS_SWIP_MASK)  >> MC_CGM_MUX_13_CSS_SWIP_SHIFT))  {}
#endif
#if defined(S32K388)
    while (1U == ((IP_MC_CGM->MUX_18_CSS  & MC_CGM_MUX_18_CSS_SWIP_MASK)  >> MC_CGM_MUX_18_CSS_SWIP_SHIFT))  {}
    while (1U == ((IP_MC_CGM->MUX_19_CSS  & MC_CGM_MUX_19_CSS_SWIP_MASK)  >> MC_CGM_MUX_19_CSS_SWIP_SHIFT))  {}
#endif


    return 0; /*Success*/
}

static int Switch_Core_FIRC(void)
{
    volatile uint32 timeout = 0xFFFF;
    volatile int result = 0;

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) >> MC_CGM_MUX_0_CSS_SWIP_SHIFT) != 0) {}
    /* Safe clock switch request to FIRC_CLK */
    IP_MC_CGM->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SAFE_SW(1) | MC_CGM_MUX_0_CSC_RAMPUP(1) | MC_CGM_MUX_0_CSC_RAMPDOWN(1);

    /* Wait for acknowledge to be cleared */
    while (((IP_MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSC_SAFE_SW_MASK) >> MC_CGM_MUX_0_CSC_SAFE_SW_SHIFT) != 1) {}

    /* Verify that clock switch completed */
    while ((((IP_MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) >> MC_CGM_MUX_0_CSS_SWIP_SHIFT) != 0) && (timeout--)) {}
    if(timeout == 0)
    {
        result = 1;/* MC_CGM_CLK_SWITCH_TIMEOUT */
    }
    else
    {

    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize MC_ME                                                      */
/*-----------------------------------------------------------------------*/
static int Init_MC_ME(void)
{
/* Enable partitions */
#if !defined(S32K394) && !defined(S32K396) && !defined(S32K374) && !defined(S32K376) && !defined(S32K364) && !defined(S32K366)
    IP_MC_ME->PRTN0_PCONF |= MC_ME_PRTN0_PCONF_PCE_MASK;
#else   /* workaround for K396 : PRTN0_PCONF register is available on hardware. This workaround will be updated after confirm with header team */
    *((volatile uint32 *)(0x402DC100)) |= MC_ME_PRTN0_PCONF_PCE_MASK;
#endif
    IP_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE_MASK;
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_ME->PRTN2_PCONF |= MC_ME_PRTN2_PCONF_PCE_MASK;
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_ME->PRTN3_PCONF |= MC_ME_PRTN3_PCONF_PCE_MASK;
#endif
    /* Prepare partition update */
#if !defined(S32K394) && !defined(S32K396) && !defined(S32K374) && !defined(S32K376) && !defined(S32K364) && !defined(S32K366)
    IP_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;
#else   /* workaround for K396 : PRTN0_PUPD register is available on hardware. This workaround will be updated after confirm with header team */
    *((volatile uint32 *)(0x402DC104)) |= MC_ME_PRTN0_PUPD_PCUD_MASK;
#endif
    IP_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_ME->PRTN2_PUPD  |= MC_ME_PRTN2_PUPD_PCUD_MASK;
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_ME->PRTN3_PUPD  |= MC_ME_PRTN3_PUPD_PCUD_MASK;
#endif
    /* Trigger partition update by writing CTL_KEYs */
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
#if !defined(S32K394) && !defined(S32K396) && !defined(S32K374) && !defined(S32K376) && !defined(S32K364) && !defined(S32K366)
    while (((IP_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
#else   /* workaround for K396 : PRTN0_PUPD register is available on hardware. This workaround will be updated after confirm with header team */
    while (((*((volatile uint32 *)(0x402DC104)) & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
#endif
    while (((IP_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK) >> MC_ME_PRTN1_PUPD_PCUD_SHIFT) != 0) {}
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (((IP_MC_ME->PRTN2_PUPD & MC_ME_PRTN2_PUPD_PCUD_MASK) >> MC_ME_PRTN2_PUPD_PCUD_SHIFT) != 0) {}
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    while (((IP_MC_ME->PRTN3_PUPD & MC_ME_PRTN3_PUPD_PCUD_MASK) >> MC_ME_PRTN3_PUPD_PCUD_SHIFT) != 0) {}
#endif
    /* Check partition clocks' statuses */
    while (((IP_MC_ME->PRTN0_PCONF & MC_ME_PRTN0_PCONF_PCE_MASK) >> MC_ME_PRTN0_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_MC_ME->PRTN1_PCONF & MC_ME_PRTN1_PCONF_PCE_MASK) >> MC_ME_PRTN1_PCONF_PCE_SHIFT) != 1) {}
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (((IP_MC_ME->PRTN2_PCONF & MC_ME_PRTN2_PCONF_PCE_MASK) >> MC_ME_PRTN2_PCONF_PCE_SHIFT) != 1) {}
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    while (((IP_MC_ME->PRTN3_PCONF & MC_ME_PRTN3_PCONF_PCE_MASK) >> MC_ME_PRTN3_PCONF_PCE_SHIFT) != 1) {}
#endif

    /* Enable peripheral clocks */
#if defined(S32K358) || defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K388)
    IP_MC_ME->PRTN0_COFB0_CLKEN |= PRTN0_COFB0_CLKEN_REQ_MASK_U32;
#endif

/* workaround for K396 : PRTN0_COFB1_CLKEN register is available on hardware. This workaround will be updated after confirm with header team */
#if defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376) || defined(S32K364) || defined(S32K366)
    *((volatile uint32 *)(0x402DC130)) |= PRTN0_COFB0_CLKEN_REQ_MASK_U32;
#endif
#if !defined(S32K394) && !defined(S32K396) && !defined(S32K374) && !defined(S32K376) && !defined(S32K364) && !defined(S32K366)
    IP_MC_ME->PRTN0_COFB1_CLKEN |= PRTN0_COFB1_CLKEN_REQ_MASK_U32;
#else   /* workaround for K396 : PRTN0_COFB1_CLKEN register is available on hardware. This workaround will be updated after confirm with header team */
    *((volatile uint32 *)(0x402DC134)) |= PRTN0_COFB1_CLKEN_REQ_MASK_U32;
#endif

    IP_MC_ME->PRTN1_COFB0_CLKEN |= PRTN1_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN1_COFB1_CLKEN |= PRTN1_COFB1_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN1_COFB2_CLKEN |= PRTN1_COFB2_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN1_COFB3_CLKEN |= PRTN1_COFB3_CLKEN_REQ_MASK_U32;
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_ME->PRTN2_COFB0_CLKEN |= PRTN2_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN2_COFB1_CLKEN |= PRTN2_COFB1_CLKEN_REQ_MASK_U32;
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K358) || defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K388) \
    || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_ME->PRTN2_COFB2_CLKEN |= PRTN2_COFB2_CLKEN_REQ_MASK_U32;
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_ME->PRTN3_COFB0_CLKEN |= PRTN3_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN3_COFB1_CLKEN |= PRTN3_COFB1_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN3_COFB2_CLKEN |= PRTN3_COFB2_CLKEN_REQ_MASK_U32;
#endif

    /* Prepare partition update */
#if !defined(S32K394) && !defined(S32K396) && !defined(S32K376) && !defined(S32K374) && !defined(S32K364) && !defined(S32K366)
    IP_MC_ME->PRTN0_PUPD |= MC_ME_PRTN0_PUPD_PCUD_MASK;
#else   /* workaround for K396 : PRTN0_PUPD register is available on hardware. This workaround will be updated after confirm with header team */
    *((volatile uint32 *)(0x402DC104)) |= MC_ME_PRTN0_PUPD_PCUD_MASK;
#endif
    IP_MC_ME->PRTN1_PUPD |= MC_ME_PRTN1_PUPD_PCUD_MASK;
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    IP_MC_ME->PRTN2_PUPD |= MC_ME_PRTN2_PUPD_PCUD_MASK;
#endif
#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    IP_MC_ME->PRTN3_PUPD |= MC_ME_PRTN3_PUPD_PCUD_MASK;
#endif
    /* Trigger partition update by writing CTL_KEYs */
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;

#ifndef SIM_TYPE_VDK
    /* Poll partition update statuses */
#if !defined(S32K394) && !defined(S32K396) && !defined(S32K374) && !defined(S32K376) && !defined(S32K364) && !defined(S32K366)
    while (((IP_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
#else   /* workaround for K396 : PRTN0_PUPD register is available on hardware. This workaround will be updated after confirm with header team */
    while (((*((volatile uint32 *)(0x402DC104)) & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
#endif
    while (((IP_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK) >> MC_ME_PRTN1_PUPD_PCUD_SHIFT) != 0) {}
#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while (((IP_MC_ME->PRTN2_PUPD & MC_ME_PRTN2_PUPD_PCUD_MASK) >> MC_ME_PRTN2_PUPD_PCUD_SHIFT) != 0) {}
#endif

#if defined(S32K358) || defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K388)
    while ((IP_MC_ME->PRTN0_COFB0_STAT & PRTN0_COFB0_CLKEN_REQ_MASK_U32) != PRTN0_COFB0_CLKEN_REQ_MASK_U32) {}
#endif
/* workaround for K396 : PRTN0_COFB1_CLKEN register is available on hardware. This workaround will be updated after confirm with header team */
#if defined(S32K394) || defined(S32K396) || defined(S32K374) || defined(S32K376) || defined(S32K364) || defined(S32K366)
    while ((*((volatile uint32 *)(0x402DC110)) & PRTN0_COFB0_CLKEN_REQ_MASK_U32) != PRTN0_COFB0_CLKEN_REQ_MASK_U32) {}
#endif

#if !defined(S32K394) && !defined(S32K396) && !defined(S32K374) && !defined(S32K376) && !defined(S32K364) && !defined(S32K366)
    while ((IP_MC_ME->PRTN0_COFB1_STAT & PRTN0_COFB1_CLKEN_REQ_MASK_U32) != PRTN0_COFB1_CLKEN_REQ_MASK_U32) {}
#else   /* workaround for K396 : PRTN0_COFB1_STAT register is available on hardware. This workaround will be updated after confirm with header team */
    while ((*((volatile uint32 *)(0x402DC114)) & PRTN0_COFB1_CLKEN_REQ_MASK_U32) != PRTN0_COFB1_CLKEN_REQ_MASK_U32) {}
#endif
    /* Check peripheral clocks statuses */
    while ((IP_MC_ME->PRTN1_COFB0_STAT & PRTN1_COFB0_CLKEN_REQ_MASK_U32) != PRTN1_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN1_COFB1_STAT & PRTN1_COFB1_CLKEN_REQ_MASK_U32) != PRTN1_COFB1_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN1_COFB2_STAT & PRTN1_COFB2_CLKEN_REQ_MASK_U32) != PRTN1_COFB2_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN1_COFB3_STAT & PRTN1_COFB3_CLKEN_REQ_MASK_U32) != PRTN1_COFB3_CLKEN_REQ_MASK_U32) {}

#if !defined(S32K311) && !defined(S32K312) && !defined(S32M276) && !defined(S32K310) && !defined(S32M274)
    while ((IP_MC_ME->PRTN2_COFB0_STAT & PRTN2_COFB0_CLKEN_REQ_MASK_U32) != PRTN2_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN2_COFB1_STAT & PRTN2_COFB1_CLKEN_REQ_MASK_U32) != PRTN2_COFB1_CLKEN_REQ_MASK_U32) {}
#endif
#ifdef S32K388
    while ((IP_MC_ME->PRTN2_COFB2_STAT & PRTN2_COFB2_CLKEN_REQ_MASK_U32) != PRTN2_COFB2_CLKEN_REQ_MASK_U32) {}
#endif

#if defined(S32K396) || defined(S32K394) || defined(S32K376) || defined(S32K374) || defined(S32K364) || defined(S32K366)
    while ((IP_MC_ME->PRTN3_COFB0_STAT & PRTN3_COFB0_CLKEN_REQ_MASK_U32) != PRTN3_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN3_COFB1_STAT & PRTN3_COFB1_CLKEN_REQ_MASK_U32) != PRTN3_COFB1_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN3_COFB2_STAT & PRTN3_COFB2_CLKEN_REQ_MASK_U32) != PRTN3_COFB2_CLKEN_REQ_MASK_U32) {}
#endif
#endif
    return 0;
}

/**
* @brief sys_init
* @details function used to initiatialize clocks
* @return E_NOT_OK/E_OK
*/
/*================================================================================================*/
Std_ReturnType sys_init(void)
{
    volatile uint32 status = 0UL;

    status += Init_MC_ME();

    status += Init_FIRC();

    status += Switch_Core_FIRC();

    status += Init_FXOSC();

    status += Init_PLL();

    /* Update code to other module can run the test without stuck runtime. Because having issue about Init_PMC() */
    status += Init_PMC();

    status += Init_MC_CGM();

    return E_OK;
}

/*================================================================================================*/
/**
* @brief sys_halt
* @details function used to enter halt mode
*/
/*================================================================================================*/
void sys_halt(void)
{

    EXECUTE_WAIT();
}

/*================================================================================================*/
/**
* @brief sys_stop
* @details function used to enter stop mode
*/
/*================================================================================================*/
void sys_stop(void)
{
    EXECUTE_WAIT();
}

uint8 EUnit_GetCoreID(void)
{
    return OsIf_GetCoreID();
}


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
