#include <Mcu.h>
#include <OsIf.h>
#include <Port.h>
#include <Gpt.h>
#include <Adc.h>
#include <Can_43_FLEXCAN.h>
#include <Spi.h>
#include <Mcl.h>
#include <Pwm.h>
#include <Icu.h>
#include <CDD_Uart.h>
#include <CDD_I2c.h>
#include <Mem_43_INFLS.h>
#include <MemAcc.h>
#include <Schm_MemAcc.h>
#include <Fee.h>
#include <Schm_Fee.h>
#include <CDD_Rm.h>
#include <Lin_43_LPUART_FLEXIO.h>
#include <LinIf.h>
#include <Platform.h>

/* Define Default project Callbacks as weak to not throw a build error for
 * projects which are not using the the following callbacks */
__attribute__((weak))void Gpt_PitNotification(void) {}

__attribute__((weak))void MBDT_Step_Handler(void) {}

__attribute__((weak))void Adc_Adc0Group0Notification(void) {}

__attribute__((weak))void Adc_Adc0Group1Notification(void) {}

__attribute__((weak))void Adc_Adc1Group0Notification(void) {}

__attribute__((weak))void Adc_Adc1Group1Notification(void) {}

__attribute__((weak))void Adc_Adc2Group0Notification(void) {}

__attribute__((weak))void Adc_Adc2Group1Notification(void) {}

__attribute__((weak))void Adc_Adc1WdogNotification(void) {}

__attribute__((weak))void Adc0_CtuNewDataNotification(void) {}

__attribute__((weak))void Adc1_CtuNewDataNotification(void) {}

__attribute__((weak))void Adc0_CtuDataOverrunNotification(void) {}

__attribute__((weak))void Adc1_CtuDataOverrunNotification(void) {}

__attribute__((weak))void Adc0_CtuListLastNotification(void) {}

__attribute__((weak))void Adc1_ListLastNotification(void) {}

__attribute__((weak))void Adc_Fifo1_UnderrunNotification(void) {}

__attribute__((weak))void Adc_Fifo1_WaterMarkNotification(void) {}

__attribute__((weak))void Adc_Fifo1_OverrunNotification(void) {}

__attribute__((weak))void CanIf_ControllerBusOff(uint8 ControllerId) {}

__attribute__((weak))void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode) {}

__attribute__((weak))void CanIf_TxConfirmation(PduIdType CanTxPduId) {}

__attribute__((weak))void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr) {}

__attribute__((weak))void MBDT_FlexCAN0_FifoOverflowNotif(void) {}

__attribute__((weak))void MBDT_SPI_end_sequence1_callback(void) {}

__attribute__((weak))void MBDT_SPI_end_job0_callback(void) {}

__attribute__((weak))void Lpuart_3_Uart_Ip_DmaRxCompleteCallback(void) {}

__attribute__((weak))void Lpuart_3_Uart_Ip_DmaTxCompleteCallback(void) {}

__attribute__((weak))void MBDT_DmaCh0_Callback(void) {}

__attribute__((weak))void PwmChannel_0_Callback(void) {}

__attribute__((weak))void PwmChannel_1_Callback(void) {}

__attribute__((weak))void PwmChannel_2_Callback(void) {}

__attribute__((weak))void PwmChannel_3_Callback(void) {}

__attribute__((weak))void PwmChannel_4_Callback(void) {}

__attribute__((weak))void PwmChannel_5_Callback(void) {}

__attribute__((weak))void PwmChannel_6_Callback(void) {}

__attribute__((weak))void PwmChannel_7_Callback(void) {}

__attribute__((weak))void PwmChannel_8_Callback(void) {}

__attribute__((weak))void MBDT_ICU_OverflowNotif(void) {}

__attribute__((weak))void MBDT_USER_SW0_callback(void) {}

__attribute__((weak))void MBDT_ICU_Timestamp_Callback(void) {}

__attribute__((weak))void MBDT_Uart_Callback(uint8 Channel, Uart_EventType Event) {}

__attribute__((weak))void MBDT_I2c_Callback(uint8 Event, uint8 Channel) {}

__attribute__((weak))void MBDT_Mem_AccessCode_Callback(void) {}

__attribute__((weak))void MBDT_Mem_StartFlashAccess_Notification(void) {}

__attribute__((weak))void MBDT_Mem_FinishedFlashAccess_Notification(void) {}

__attribute__((weak))void MBDT_Fee_NvmJobEnd_Notification(void) {}

__attribute__((weak))void MBDT_Fee_NvmJobError_Notification(void) {}

__attribute__((weak))void MBDT_Fee_ClusterFormatDuringInit_Notification(void) {}

__attribute__((weak))Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource) {}

__attribute__((weak))void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource) {}

__attribute__((weak))Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType * PduPtr) {}

__attribute__((weak))void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr) {}

__attribute__((weak))void LinIf_TxConfirmation(NetworkHandleType Channel) {}

__attribute__((weak))void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus) {}


void board_init(void)
{
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
    #if (MCU_NO_PLL==STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* wait until all enabled PLLs are locked */
    }
    /* switch system clock tree to PLL */
    Mcu_DistributePllClock();
    #endif
    Mcu_SetMode(McuModeSettingConf_0);
    OsIf_Init(NULL_PTR);
    Port_Init(&Port_Config_MBDT);
    Gpt_Init(&Gpt_Config_MBDT);
    Adc_Init(&Adc_Config_MBDT);
    Can_43_FLEXCAN_Init(&Can_43_FLEXCAN_Config_MBDT);
    Spi_Init(&Spi_Config_MBDT);
    Mcl_Init(&Mcl_Config_MBDT);
    Pwm_Init(&Pwm_Config_MBDT);
    Icu_Init(&Icu_Config_MBDT);
    Uart_Init(&Uart_xConfig_MBDT);
    I2c_Init(&I2c_Config_MBDT);
    Mem_43_INFLS_Init(NULL_PTR);
    MemAcc_Init(NULL_PTR);
    MemIf_StatusType status = MEMIF_IDLE;
    Fee_Init(NULL_PTR);
    do
    {
        Fee_MainFunction();
        MemAcc_MainFunction();
        status = Fee_GetStatus();
    } while (status != MEMIF_IDLE);
    Rm_Init(&Rm_Config_MBDT);
    Lin_43_LPUART_FLEXIO_Init(&Lin_43_LPUART_FLEXIO_xConfig_MBDT);
    Platform_Init(NULL_PTR);
}
