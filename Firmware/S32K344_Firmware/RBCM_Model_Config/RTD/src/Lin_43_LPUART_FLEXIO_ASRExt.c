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
*   @file Lin_ASRExt.c
*
*   @internal
*   @addtogroup LIN_IPW
*   @{
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
#include "Lin_43_LPUART_FLEXIO.h"
#include "Lin_43_LPUART_FLEXIO_ASRExt.h"
#include "Lpuart_Lin_Ip_Hw_Access.h"
#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID_C                      43
#define LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION_C       7
#define LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION_C    0
#define LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION_C               5
#define LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION_C               0
#define LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin_43_LPUART_FLEXIO_ASRExt header file are of the same vendor id */
#if (LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_ASRExt.c and Lin_43_LPUART_FLEXIO.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Lin_43_LPUART_FLEXIO.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Lin_43_LPUART_FLEXIO.h are different"
#endif

/* Check if current file and Lin_43_LPUART_FLEXIO_ASRExt header file are of the same vendor id */
#if (LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_ASRExt.c and Lin_43_LPUART_FLEXIO_ASRExt.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_ASRExt header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Lin_43_LPUART_FLEXIO_ASRExt.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_ASRExt header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Lin_43_LPUART_FLEXIO_ASRExt.h are different"
#endif

/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same vendor id */
#if (LIN_43_LPUART_FLEXIO_ASREXT_VENDOR_ID_C != LPUART_LIN_IP_HW_ACCESS_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_ASRExt.c and Lpuart_Lin_Ip_Hw_Access.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION_C    != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION_C    != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_REVISION_VERSION_C != LPUART_LIN_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Lpuart_Lin_Ip_Hw_Access.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Hw_Access header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_ASREXT_SW_MAJOR_VERSION_C != LPUART_LIN_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_MINOR_VERSION_C != LPUART_LIN_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_ASREXT_SW_PATCH_VERSION_C != LPUART_LIN_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Lpuart_Lin_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_43_LPUART_FLEXIO_ASREXT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_ASRExt.c and Det.h are different"
        #endif
    #endif
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

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE)
static void Lin_SetChannelClockMode(const uint8 Channel, const Lin_43_LPUART_FLEXIO_ClockModesType ClockMode);
#endif /* (STD_ON == LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE)
static void Lin_SetChannelClockMode(const uint8 Channel, const Lin_43_LPUART_FLEXIO_ClockModesType ClockMode)
{
    LPUART_Type* Base;
    uint8 HwChannel;
    Lin_43_LPUART_FLEXIO_Ipw_HwChannelType ChannelType;
    LPUART_Type * const LpuartBasesArr[LPUART_INSTANCE_COUNT] = IP_LPUART_BASE_PTRS;
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    FLEXIO_Type *FlexioBase;
    FLEXIO_Type * const FlexioBasesArr[FLEXIO_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;
    const Flexio_Lin_Ip_UserConfigType *UserConfig = Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->IpConfig.FlexioConfigPtr;
    uint32 TempRegVal = 0UL;
#endif

    /* Get the hardware Lin channel from logical channel */
    HwChannel = Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->LinHwChannel;
    Base = LpuartBasesArr[HwChannel];
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
    /* Get Base address of the FLEXIO Channel. */
    FlexioBase = FlexioBasesArr[HwChannel];
#endif
    ChannelType = Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->LinIpType;

    /* Set the Baudrate */
    if (LIN_43_LPUART_FLEXIO_NORMAL == ClockMode)
    {
        if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == ChannelType)
        {
            Lpuart_Lin_Ip_HwSetBaudRateDivisor(Base, Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->IpConfig.LpuartConfigPtr->BaudRateDivisor);
        }
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
        else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == ChannelType)
        {
            /* Configure the Tx Timer to generate shift clock for 8 bits each frame */
            FlexioBase->TIMCMP[UserConfig->TxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(UserConfig->Baudratedivider) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U))); /* Tx Timer */
            /* Configure the Rx Timer to generate shift clock for receiving frame 8 bits */
            FlexioBase->TIMCMP[UserConfig->RxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(UserConfig->Baudratedivider) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U))); /* Rx Timer */

            TempRegVal = FlexioBase->TIMCFG[UserConfig->RxTimerId];
            TempRegVal |= (FLEXIO_TIMCFG_TIMDEC(UserConfig->TimerClkSrc));              /* Timer decrement counter on FlexIO clock */
            FlexioBase->TIMCFG[UserConfig->RxTimerId] = TempRegVal;

            TempRegVal = FlexioBase->TIMCFG[UserConfig->TxTimerId];
            TempRegVal |= (FLEXIO_TIMCFG_TIMDEC(UserConfig->TimerClkSrc));                /* Timer decrement counter on FlexIO clock */
            FlexioBase->TIMCFG[UserConfig->TxTimerId] = TempRegVal;
        }
#endif
        else
        {
            /* Impossible */
        }
    }
    /* Set alternate clock */
    else
    {
        if (LIN_43_LPUART_FLEXIO_LPUART_CHANNEL == ChannelType)
        {
            /* write the sbr value to the BAUD registers */
            Lpuart_Lin_Ip_HwSetBaudRateDivisor(Base, Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->BaudrateRegValueAlternate);
        }
#if (STD_ON == LIN_43_LPUART_FLEXIO_FLEXIO_USED)
        else if (LIN_43_LPUART_FLEXIO_FLEXIO_CHANNEL == ChannelType)
        {
            /* Configure the Tx Timer to generate shift clock for 8 bits each frame */
            FlexioBase->TIMCMP[UserConfig->TxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->BaudrateRegValueAlternate) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U))); /* Tx Timer */
            /* Configure the Rx Timer to generate shift clock for receiving frame 8 bits */
            FlexioBase->TIMCMP[UserConfig->RxTimerId] = FLEXIO_TIMCMP_CMP(FLEXIO_LIN_IP_TIMCMP_CMP_0_7_VALUE_U16(Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->BaudrateRegValueAlternate) | (FLEXIO_LIN_IP_TIMCMP_BITS_VALUE_U32(8U))); /* Rx Timer */

            TempRegVal = FlexioBase->TIMCFG[UserConfig->RxTimerId];
            TempRegVal |= (FLEXIO_TIMCFG_TIMDEC(Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->TimerClkSrcAlternate));              /* Timer decrement counter on FlexIO clock */
            FlexioBase->TIMCFG[UserConfig->RxTimerId] = TempRegVal;

            TempRegVal = FlexioBase->TIMCFG[UserConfig->TxTimerId];
            TempRegVal |= (FLEXIO_TIMCFG_TIMDEC(Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[Channel]->ChannelConfigPtr->TimerClkSrcAlternate));                /* Timer decrement counter on FlexIO clock */
            FlexioBase->TIMCFG[UserConfig->TxTimerId] = TempRegVal;
        }
#endif
        else
        {
            /* Impossible */
        }
    }
}
#endif /* (STD_ON == LIN_DUAL_CLOCK_MODE) */
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE)

/**
* @brief          Lin_SetClockMode.
* @details        Switch the clock mode to the alternate clock mode on
*                 all the Lin Channels.
*
* @param[in]      ClockMode   New clock mode.
*
* @return                     The result of the switching clock operation.
* @retval E_OK                The switching operation was OK.
* @retval E_NOT_OK            The switching operation has failed caused by the
*                             wrong driver state.
*
* @api            Switch the clock mode to the alternate clock mode on all
*                 the Lin Channels.
*
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @note           Switch the clock mode to the alternate clock mode on
*                 all the Lin Channels.
*/
/**
* @implements     Lin_SetClockMode_Activity
*/
Std_ReturnType Lin_43_LPUART_FLEXIO_SetClockMode(Lin_43_LPUART_FLEXIO_ClockModesType ClockMode)
{
    Std_ReturnType TempReturn = (uint8)E_OK;
    uint8 ChLoop;
    uint32 PartitionID;

    PartitionID = (uint32)Lin_43_LPUART_FLEXIO_GetUserID();

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_43_LPUART_FLEXIO_INIT != Lin_43_LPUART_FLEXIO_au8LinDrvStatus[PartitionID])
    {
        /* LIN driver has not been initialized yet */
#if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_43_LPUART_FLEXIO_MODULE_ID, \
                              (uint8)0u, \
                              (uint8)LIN_43_LPUART_FLEXIO_SETCLOCKMODE_ID, \
                              (uint8)LIN_43_LPUART_FLEXIO_E_UNINIT \
                             );
#endif /* (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON) */
        TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        for (ChLoop = 0U; ChLoop < LIN_43_LPUART_FLEXIO_HW_MAX_MODULES; ChLoop++)
        {
            if (Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[ChLoop] != NULL_PTR)
            {
                if ((TRUE == Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[ChLoop]->AllocatedPartition) &&
                    (PartitionID == Lin_43_LPUART_FLEXIO_apxChannelConfigPtr[ChLoop]->ChannelPartitionID)
                   )
                {
                    Lin_SetChannelClockMode(ChLoop, ClockMode);
                }
            }
        }
    }

    return TempReturn;
}

#endif /* STD_ON == LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE */

#define LIN_43_LPUART_FLEXIO_STOP_SEC_CODE
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
