###########################################################################
## Makefile generated for component 'RBCM_Model'. 
## 
## Makefile     : RBCM_Model.mk
## Generated on : Tue Jun 17 18:00:34 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/RBCM_Model.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = RBCM_Model
MAKEFILE                  = RBCM_Model.mk
MATLAB_ROOT               = D:/AppGallery/Software/MATLAB/R2023b
MATLAB_BIN                = D:/AppGallery/Software/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = E:/Myworkspace/RBCM_S32K344_AUTOSAR_MBD/Firmware/AUTOSAR_MBD/RBCM_MBD
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
EXTRA_ASFLAGS             = -DGCC -DS32K3XX -DS32K344 -DCPU_S32K344 -DENABLE_FPU -DMPU_ENABLE -specs=nano.specs -specs=nosys.specs --sysroot="E:\MATLABAddOns\Toolboxes\NXP_MBDToolbox_S32K3\tools\build_tools\gcc_v10.2\gcc-10.2-arm32-eabi\arm-none-eabi\newlib"
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          S32DS GCC
# Supported Version(s):    1
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GCC Assembler
AS = arm-none-eabi-gcc

# C Compiler: GCC C Compiler
CC = arm-none-eabi-gcc

# Linker: GCC Linker
LD = arm-none-eabi-gcc

# Archiver: GCC Archiver
AR = arm-none-eabi-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Code Size: Code Size
CODE_SIZE = arm-none-eabi-size

# ELF To Binary Converter: ELF To Binary Converter
ELF_TO_BIN = arm-none-eabi-objcopy

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g3
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g3
C_OUTPUT_FLAG       = -o
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              =  -r
ASFLAGS              =  -c -x assembler-with-cpp -g -mcpu=cortex-m7 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DD_CACHE_ENABLE -DI_CACHE_ENABLE $(EXTRA_ASFLAGS)
CFLAGS               = -O2 -c -std=c99 -fshort-enums -funsigned-char -fstack-usage -ffunction-sections -fdata-sections -g -pedantic -Wall -Wextra -fmessage-length=0 -funsigned-bitfields -fno-common -Wunused -Wstrict-prototypes -Wsign-compare -Werror=implicit-function-declaration -mcpu=cortex-m7 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DD_CACHE_ENABLE -DI_CACHE_ENABLE
CODESIZE_FLAGS       = --format=berkeley $(PRODUCT)
DOWNLOAD_FLAGS       =
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT:.elf=.bin)
EXECUTE_FLAGS        =
LDFLAGS              =  -nostartfiles -Xlinker -Map="$(PRODUCT_NAME).map" -Xlinker --gc-sections -n -mcpu=cortex-m7 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE) -j
SHAREDLIB_LDFLAGS    =  -nostartfiles -Xlinker -Map="$(PRODUCT_NAME).map" -Xlinker --gc-sections -n -mcpu=cortex-m7 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/RBCM_Model.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/RBCM_Model_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/RBCM_Model_Config/Debug -I$(START_DIR)/RBCM_Model_Config/Project_Settings -I$(START_DIR)/RBCM_Model_Config/RTD -I$(START_DIR)/RBCM_Model_Config/generate -I$(START_DIR)/RBCM_Model_Config/src -I$(START_DIR)/RBCM_Model_Config/Debug/Project_Settings -I$(START_DIR)/RBCM_Model_Config/Debug/RBCM_Model_ert_rtw -I$(START_DIR)/RBCM_Model_Config/Debug/RTD -I$(START_DIR)/RBCM_Model_Config/Debug/generate -I$(START_DIR)/RBCM_Model_Config/Debug/src -I$(START_DIR)/RBCM_Model_Config/Debug/Project_Settings/Startup_Code -I$(START_DIR)/RBCM_Model_Config/Debug/RTD/src -I$(START_DIR)/RBCM_Model_Config/Debug/generate/src -I$(START_DIR)/RBCM_Model_Config/Project_Settings/Debugger -I$(START_DIR)/RBCM_Model_Config/Project_Settings/Linker_Files -I$(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code -I$(START_DIR)/RBCM_Model_Config/RTD/include -I$(START_DIR)/RBCM_Model_Config/RTD/src -I$(START_DIR)/RBCM_Model_Config/generate/include -I$(START_DIR)/RBCM_Model_Config/generate/src

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DGCC -DS32K3XX -DS32K344 -DCPU_S32K344 -DENABLE_FPU -DMPU_ENABLE -DMBDT_INIT
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=RBCM_Model -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/RBCM_Model_ert_rtw/Adc_Params.c $(START_DIR)/RBCM_Model_ert_rtw/RBCM_Model.c $(START_DIR)/RBCM_Model_ert_rtw/RBCM_Model_data.c $(START_DIR)/RBCM_Model_Config/src/freemaster_appcmd.c $(START_DIR)/RBCM_Model_Config/src/freemaster_pipes.c $(START_DIR)/RBCM_Model_Config/src/freemaster_protocol.c $(START_DIR)/RBCM_Model_Config/src/freemaster_rec.c $(START_DIR)/RBCM_Model_Config/src/freemaster_s32k3xx_lpuart.c $(START_DIR)/RBCM_Model_Config/src/freemaster_scope.c $(START_DIR)/RBCM_Model_Config/src/freemaster_serial.c $(START_DIR)/RBCM_Model_Config/src/freemaster_tsa.c $(START_DIR)/RBCM_Model_Config/src/freemaster_ures.c $(START_DIR)/RBCM_Model_Config/src/freemaster_utils.c $(START_DIR)/RBCM_Model_Config/src/mbdt_board_init.c $(START_DIR)/RBCM_Model_Config/src/mbdt_lpuart.c $(START_DIR)/RBCM_Model_Config/src/s32k3_trigger_config.c $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/exceptions.c $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/nvic.c $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/startup.c $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/sys_init.c $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/system.c $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/Vector_Table.s $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/startup_cm7.s $(START_DIR)/RBCM_Model_Config/RTD/src/Adc.c $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Ipw_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Sar_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Sar_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Axbs_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Bctu_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Bctu_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/C40_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/C40_Ip_Ac.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_I2c.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_I2c_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Mcl.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Mcl_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Rm.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Rm_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Uart.c $(START_DIR)/RBCM_Model_Config/RTD/src/Cache_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Cache_Ip_HwAcc_ArmCoreMx.c $(START_DIR)/RBCM_Model_Config/RTD/src/Can_43_FLEXCAN.c $(START_DIR)/RBCM_Model_Config/RTD/src/Can_43_FLEXCAN_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Can_43_FLEXCAN_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Data.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Divider.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_DividerTrigger.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_ExtOsc.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_FracDiv.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Frequency.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Gate.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_IntOsc.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Monitor.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Pll.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_ProgFreqSwitch.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Selector.c $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Specific.c $(START_DIR)/RBCM_Model_Config/RTD/src/Cmp_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/DSPSS_Api.c $(START_DIR)/RBCM_Model_Config/RTD/src/Det.c $(START_DIR)/RBCM_Model_Config/RTD/src/Det_stub.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dio.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dio_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Driver_State.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Hw_Access.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Multicore.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Mux_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dspi_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Dspi_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/EcuM.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Gpt_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Icu_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Icu_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Mcl_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Mcl_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Pwm_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Pwm_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Etpu_Pwm_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Etpu_Pwm_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Fee.c $(START_DIR)/RBCM_Model_Config/RTD/src/FlexCAN_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/FlexCAN_Ip_HwAccess.c $(START_DIR)/RBCM_Model_Config/RTD/src/FlexCAN_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/FlexPwm_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/FlexPwm_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_I2c_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Lin_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Mcl_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Mcl_Ip_HwAccess.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Mcl_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Pwm_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Pwm_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Spi_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Spi_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Uart_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Uart_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Gpt.c $(START_DIR)/RBCM_Model_Config/RTD/src/Gpt_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Icu.c $(START_DIR)/RBCM_Model_Config/RTD/src/Icu_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Igf_Port_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/IntCtrl_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip_Hw_Access.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip_Multicore.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_43_LPUART_FLEXIO.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_43_LPUART_FLEXIO_ASRExt.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_43_LPUART_FLEXIO_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_Ip_Common.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpi2c_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpi2c_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpspi_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpspi_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Lin_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Lin_Ip_Hw_Access.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Lin_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Uart_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Uart_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mcu.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mcu_Dem_Wrapper.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mcu_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/MemAcc.c $(START_DIR)/RBCM_Model_Config/RTD/src/MemAcc_Sema4.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mem_43_INFLS.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mem_43_INFLS_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mem_43_INFLS_Software_Semaphore.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mpu_M7_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Mscm_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Interrupts.c $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Timer.c $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Timer_System.c $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Timer_System_Internal_Systick.c $(START_DIR)/RBCM_Model_Config/RTD/src/Os_counter_api.c $(START_DIR)/RBCM_Model_Config/RTD/src/Os_event.c $(START_DIR)/RBCM_Model_Config/RTD/src/Os_isr.c $(START_DIR)/RBCM_Model_Config/RTD/src/Os_multicore.c $(START_DIR)/RBCM_Model_Config/RTD/src/Os_scheduler.c $(START_DIR)/RBCM_Model_Config/RTD/src/Osif_Software_Semaphore.c $(START_DIR)/RBCM_Model_Config/RTD/src/Pflash_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Pit_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Platform.c $(START_DIR)/RBCM_Model_Config/RTD/src/Platform_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Port.c $(START_DIR)/RBCM_Model_Config/RTD/src/Port_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_AEC.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_CortexM7.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_DCM_GPR.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_FLASH.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_MC_ME.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_MC_RGM.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_MC_RGM_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_PMC.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_PMC_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_Private.c $(START_DIR)/RBCM_Model_Config/RTD/src/Pwm.c $(START_DIR)/RBCM_Model_Config/RTD/src/Pwm_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Pwm_Ipw_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Ram_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Rtc_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Adc.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ae.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Can.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_CanTrcv_43_AE.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_CanTrcv_43_fs23.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_CanTrcv_43_fs65.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Can_43_FLEXCAN.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crc.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crypto.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crypto_43_ACE.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crypto_43_HSE.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Dio.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Dpga.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Eep.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Eth.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_EthSwt_43_SJA11XX.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_EthTrcv_43_PHY.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Eth_43_GMAC.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Etpu.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Fee.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Fls.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Gd3162.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Gdu.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Gpt.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_I2c.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_I2s.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Icu.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ipcf.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Iseled.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_LinTrcv_43_fs23.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_LinTrcv_43_fs65.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Lin_43_LPUART_FLEXIO.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mc12xs6.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mcl.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mcu.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_MemAcc.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mem_43_EEP.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mem_43_EXFLS.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mem_43_INFLS.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Motor_control.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Nvm.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ocotp.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ocu.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Platform.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Port.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Pwm.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Pwm_etpu.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Rdc_checker.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Rm.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sbc_fs23.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sbc_fs26.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sbc_fs65.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sent.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Spi.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Uart.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg_43_fs23.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg_43_fs26.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg_43_fs65.c $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Zipwire.c $(START_DIR)/RBCM_Model_Config/RTD/src/Sdadc_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Sdadc_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Sema42_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Dio_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Icu_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Icu_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Port_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Spi.c $(START_DIR)/RBCM_Model_Config/RTD/src/Spi_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Stm_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/System_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Trgmux_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Trgmux_Ip_HwAcc.c $(START_DIR)/RBCM_Model_Config/RTD/src/Tspc_Port_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Uart_Ipw.c $(START_DIR)/RBCM_Model_Config/RTD/src/Virt_Wrapper_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Wkpu_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Wkpu_Ip_Irq.c $(START_DIR)/RBCM_Model_Config/RTD/src/Xbic_Ip.c $(START_DIR)/RBCM_Model_Config/RTD/src/Xrdc_Ip.c $(START_DIR)/RBCM_Model_Config/generate/src/Adc_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Adc_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Adc_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Adc_Sar_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Axbs_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Bctu_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/C40_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_I2c_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_I2c_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_I2c_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Mcl_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Mcl_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Rm_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Rm_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Rm_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Uart_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CanIf_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/CanIf_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Can_43_FLEXCAN_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Can_43_FLEXCAN_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Clock_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Clock_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Cmp_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Dio_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Dma_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Dma_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Dma_Mux_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Dspi_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Gpt_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Icu_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Mcl_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Pwm_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Etpu_Pwm_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Fee_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/FlexCAN_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/FlexPwm_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_I2c_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Lin_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Mcl_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Pwm_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Spi_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Uart_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Gpt_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Gpt_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Gpt_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Icu_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Icu_DmaNotification.c $(START_DIR)/RBCM_Model_Config/generate/src/Icu_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Icu_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Igf_Port_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/IntCtrl_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lcu_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lcu_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lin_43_LPUART_FLEXIO_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lin_43_LPUART_FLEXIO_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lpi2c_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lpspi_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lpuart_Lin_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Lpuart_Uart_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Mcu_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Mcu_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/MemAcc_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/MemAcc_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Mem_43_INFLS_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Mpu_M7_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Mscm_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/OsIf_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Pflash_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Pflash_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Pit_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Platform_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Platform_Ipw_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Port_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Port_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Power_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Power_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Pwm_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Ram_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Ram_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Rtc_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Sdadc_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Siul2_Icu_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Siul2_Port_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Siul2_Port_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Spi_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Spi_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Stm_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Trgmux_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Trgmux_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Tspc_Port_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Tspc_Port_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Uart_Ipw_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Virt_Wrapper_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Wkpu_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Xbic_Ip_MBDT_PBcfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Xrdc_Ip_Cfg.c $(START_DIR)/RBCM_Model_Config/generate/src/Xrdc_Ip_MBDT_PBcfg.c

MAIN_SRC = $(START_DIR)/RBCM_Model_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Adc_Params.o RBCM_Model.o RBCM_Model_data.o freemaster_appcmd.o freemaster_pipes.o freemaster_protocol.o freemaster_rec.o freemaster_s32k3xx_lpuart.o freemaster_scope.o freemaster_serial.o freemaster_tsa.o freemaster_ures.o freemaster_utils.o mbdt_board_init.o mbdt_lpuart.o s32k3_trigger_config.o exceptions.o nvic.o startup.o sys_init.o system.o Vector_Table.o startup_cm7.o Adc.o Adc_Ipw.o Adc_Ipw_Irq.o Adc_Sar_Ip.o Adc_Sar_Ip_Irq.o Axbs_Ip.o Bctu_Ip.o Bctu_Ip_Irq.o C40_Ip.o C40_Ip_Ac.o CDD_I2c.o CDD_I2c_Ipw.o CDD_Mcl.o CDD_Mcl_Ipw.o CDD_Rm.o CDD_Rm_Ipw.o CDD_Uart.o Cache_Ip.o Cache_Ip_HwAcc_ArmCoreMx.o Can_43_FLEXCAN.o Can_43_FLEXCAN_Ipw.o Can_43_FLEXCAN_Irq.o Clock_Ip.o Clock_Ip_Data.o Clock_Ip_Divider.o Clock_Ip_DividerTrigger.o Clock_Ip_ExtOsc.o Clock_Ip_FracDiv.o Clock_Ip_Frequency.o Clock_Ip_Gate.o Clock_Ip_IntOsc.o Clock_Ip_Irq.o Clock_Ip_Monitor.o Clock_Ip_Pll.o Clock_Ip_ProgFreqSwitch.o Clock_Ip_Selector.o Clock_Ip_Specific.o Cmp_Ip.o DSPSS_Api.o Det.o Det_stub.o Dio.o Dio_Ipw.o Dma_Ip.o Dma_Ip_Driver_State.o Dma_Ip_Hw_Access.o Dma_Ip_Irq.o Dma_Ip_Multicore.o Dma_Mux_Ip.o Dspi_Ip.o Dspi_Ip_Irq.o EcuM.o Emios_Gpt_Ip.o Emios_Icu_Ip.o Emios_Icu_Ip_Irq.o Emios_Mcl_Ip.o Emios_Mcl_Ip_Irq.o Emios_Pwm_Ip.o Emios_Pwm_Ip_Irq.o Etpu_Pwm_Ip.o Etpu_Pwm_Ip_Irq.o Fee.o FlexCAN_Ip.o FlexCAN_Ip_HwAccess.o FlexCAN_Ip_Irq.o FlexPwm_Ip.o FlexPwm_Ip_Irq.o Flexio_I2c_Ip.o Flexio_Lin_Ip.o Flexio_Mcl_Ip.o Flexio_Mcl_Ip_HwAccess.o Flexio_Mcl_Ip_Irq.o Flexio_Pwm_Ip.o Flexio_Pwm_Ip_Irq.o Flexio_Spi_Ip.o Flexio_Spi_Ip_Irq.o Flexio_Uart_Ip.o Flexio_Uart_Ip_Irq.o Gpt.o Gpt_Ipw.o Icu.o Icu_Ipw.o Igf_Port_Ip.o IntCtrl_Ip.o Lcu_Ip.o Lcu_Ip_Hw_Access.o Lcu_Ip_Irq.o Lcu_Ip_Multicore.o Lin_43_LPUART_FLEXIO.o Lin_43_LPUART_FLEXIO_ASRExt.o Lin_43_LPUART_FLEXIO_Ipw.o Lin_Ip_Common.o Lpi2c_Ip.o Lpi2c_Ip_Irq.o Lpspi_Ip.o Lpspi_Ip_Irq.o Lpuart_Lin_Ip.o Lpuart_Lin_Ip_Hw_Access.o Lpuart_Lin_Ip_Irq.o Lpuart_Uart_Ip.o Lpuart_Uart_Ip_Irq.o Mcu.o Mcu_Dem_Wrapper.o Mcu_Ipw.o MemAcc.o MemAcc_Sema4.o Mem_43_INFLS.o Mem_43_INFLS_Ipw.o Mem_43_INFLS_Software_Semaphore.o Mpu_M7_Ip.o Mscm_Ip.o OsIf_Interrupts.o OsIf_Timer.o OsIf_Timer_System.o OsIf_Timer_System_Internal_Systick.o Os_counter_api.o Os_event.o Os_isr.o Os_multicore.o Os_scheduler.o Osif_Software_Semaphore.o Pflash_Ip.o Pit_Ip.o Platform.o Platform_Ipw.o Port.o Port_Ipw.o Power_Ip.o Power_Ip_AEC.o Power_Ip_CortexM7.o Power_Ip_DCM_GPR.o Power_Ip_FLASH.o Power_Ip_MC_ME.o Power_Ip_MC_RGM.o Power_Ip_MC_RGM_Irq.o Power_Ip_PMC.o Power_Ip_PMC_Irq.o Power_Ip_Private.o Pwm.o Pwm_Ipw.o Pwm_Ipw_Irq.o Ram_Ip.o Rtc_Ip.o SchM_Adc.o SchM_Ae.o SchM_Can.o SchM_CanTrcv_43_AE.o SchM_CanTrcv_43_fs23.o SchM_CanTrcv_43_fs65.o SchM_Can_43_FLEXCAN.o SchM_Crc.o SchM_Crypto.o SchM_Crypto_43_ACE.o SchM_Crypto_43_HSE.o SchM_Dio.o SchM_Dpga.o SchM_Eep.o SchM_Eth.o SchM_EthSwt_43_SJA11XX.o SchM_EthTrcv_43_PHY.o SchM_Eth_43_GMAC.o SchM_Etpu.o SchM_Fee.o SchM_Fls.o SchM_Gd3162.o SchM_Gdu.o SchM_Gpt.o SchM_I2c.o SchM_I2s.o SchM_Icu.o SchM_Ipcf.o SchM_Iseled.o SchM_LinTrcv_43_fs23.o SchM_LinTrcv_43_fs65.o SchM_Lin_43_LPUART_FLEXIO.o SchM_Mc12xs6.o SchM_Mcl.o SchM_Mcu.o SchM_MemAcc.o SchM_Mem_43_EEP.o SchM_Mem_43_EXFLS.o SchM_Mem_43_INFLS.o SchM_Motor_control.o SchM_Nvm.o SchM_Ocotp.o SchM_Ocu.o SchM_Platform.o SchM_Port.o SchM_Pwm.o SchM_Pwm_etpu.o SchM_Rdc_checker.o SchM_Rm.o SchM_Sbc_fs23.o SchM_Sbc_fs26.o SchM_Sbc_fs65.o SchM_Sent.o SchM_Spi.o SchM_Uart.o SchM_Wdg.o SchM_Wdg_43_fs23.o SchM_Wdg_43_fs26.o SchM_Wdg_43_fs65.o SchM_Zipwire.o Sdadc_Ip.o Sdadc_Ip_Irq.o Sema42_Ip.o Siul2_Dio_Ip.o Siul2_Icu_Ip.o Siul2_Icu_Ip_Irq.o Siul2_Port_Ip.o Spi.o Spi_Ipw.o Stm_Ip.o System_Ip.o Trgmux_Ip.o Trgmux_Ip_HwAcc.o Tspc_Port_Ip.o Uart_Ipw.o Virt_Wrapper_Ip.o Wkpu_Ip.o Wkpu_Ip_Irq.o Xbic_Ip.o Xrdc_Ip.o Adc_Cfg.o Adc_Ipw_MBDT_PBcfg.o Adc_MBDT_PBcfg.o Adc_Sar_Ip_MBDT_PBcfg.o Axbs_Ip_MBDT_PBcfg.o Bctu_Ip_MBDT_PBcfg.o C40_Ip_Cfg.o CDD_I2c_Cfg.o CDD_I2c_Ipw_MBDT_PBcfg.o CDD_I2c_MBDT_PBcfg.o CDD_Mcl_Cfg.o CDD_Mcl_MBDT_PBcfg.o CDD_Rm_Cfg.o CDD_Rm_Ipw_MBDT_PBcfg.o CDD_Rm_MBDT_PBcfg.o CDD_Uart_MBDT_PBcfg.o CanIf_Cfg.o CanIf_MBDT_PBcfg.o Can_43_FLEXCAN_Ipw_MBDT_PBcfg.o Can_43_FLEXCAN_MBDT_PBcfg.o Clock_Ip_Cfg.o Clock_Ip_MBDT_PBcfg.o Cmp_Ip_MBDT_PBcfg.o Dio_Cfg.o Dma_Ip_Cfg.o Dma_Ip_MBDT_PBcfg.o Dma_Mux_Ip_MBDT_PBcfg.o Dspi_Ip_MBDT_PBcfg.o Emios_Gpt_Ip_MBDT_PBcfg.o Emios_Icu_Ip_MBDT_PBcfg.o Emios_Mcl_Ip_MBDT_PBcfg.o Emios_Pwm_Ip_MBDT_PBcfg.o Etpu_Pwm_Ip_MBDT_PBcfg.o Fee_Cfg.o FlexCAN_Ip_MBDT_PBcfg.o FlexPwm_Ip_MBDT_PBcfg.o Flexio_I2c_Ip_MBDT_PBcfg.o Flexio_Lin_Ip_MBDT_PBcfg.o Flexio_Mcl_Ip_MBDT_PBcfg.o Flexio_Pwm_Ip_MBDT_PBcfg.o Flexio_Spi_Ip_MBDT_PBcfg.o Flexio_Uart_Ip_MBDT_PBcfg.o Gpt_Cfg.o Gpt_Ipw_MBDT_PBcfg.o Gpt_MBDT_PBcfg.o Icu_Cfg.o Icu_DmaNotification.o Icu_Ipw_MBDT_PBcfg.o Icu_MBDT_PBcfg.o Igf_Port_Ip_MBDT_PBcfg.o IntCtrl_Ip_Cfg.o Lcu_Ip_Cfg.o Lcu_Ip_MBDT_PBcfg.o Lin_43_LPUART_FLEXIO_Cfg.o Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.o Lin_43_LPUART_FLEXIO_MBDT_PBcfg.o Lpi2c_Ip_MBDT_PBcfg.o Lpspi_Ip_MBDT_PBcfg.o Lpuart_Lin_Ip_MBDT_PBcfg.o Lpuart_Uart_Ip_MBDT_PBcfg.o Mcu_Cfg.o Mcu_MBDT_PBcfg.o MemAcc_Cfg.o MemAcc_MBDT_PBcfg.o Mem_43_INFLS_Cfg.o Mpu_M7_Ip_Cfg.o Mscm_Ip_MBDT_PBcfg.o OsIf_Cfg.o Pflash_Ip_Cfg.o Pflash_Ip_MBDT_PBcfg.o Pit_Ip_MBDT_PBcfg.o Platform_Cfg.o Platform_Ipw_Cfg.o Port_Cfg.o Port_MBDT_PBcfg.o Power_Ip_Cfg.o Power_Ip_MBDT_PBcfg.o Pwm_MBDT_PBcfg.o Ram_Ip_Cfg.o Ram_Ip_MBDT_PBcfg.o Rtc_Ip_MBDT_PBcfg.o Sdadc_Ip_MBDT_PBcfg.o Siul2_Icu_Ip_MBDT_PBcfg.o Siul2_Port_Ip_Cfg.o Siul2_Port_Ip_MBDT_PBcfg.o Spi_Ipw_MBDT_PBcfg.o Spi_MBDT_PBcfg.o Stm_Ip_MBDT_PBcfg.o Trgmux_Ip_Cfg.o Trgmux_Ip_MBDT_PBcfg.o Tspc_Port_Ip_Cfg.o Tspc_Port_Ip_MBDT_PBcfg.o Uart_Ipw_MBDT_PBcfg.o Virt_Wrapper_Ip_MBDT_PBcfg.o Wkpu_Ip_MBDT_PBcfg.o Xbic_Ip_MBDT_PBcfg.o Xrdc_Ip_Cfg.o Xrdc_Ip_MBDT_PBcfg.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ =  -DSTEP_GPT_TIMER -DSTEP_GPT_CHANNEL=GptConf_GptChannelConfiguration_StepTimer -DSTEP_GPT_CHANNEL_FREQ=40000000 -DSTEP_GPT_CHANNEL_VALUE_MAX=4294967295 -DAUTOSAR_OS_NOT_USED -specs=nano.specs -specs=nosys.specs --sysroot="E:\MATLABAddOns\Toolboxes\NXP_MBDToolbox_S32K3\tools\build_tools\gcc_v10.2\gcc-10.2-arm32-eabi\arm-none-eabi\newlib"
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_ = -specs=nano.specs -specs=nosys.specs --sysroot="E:\MATLABAddOns\Toolboxes\NXP_MBDToolbox_S32K3\tools\build_tools\gcc_v10.2\gcc-10.2-arm32-eabi\arm-none-eabi\newlib" -T "E:\Myworkspace\RBCM_S32K344_AUTOSAR_MBD\Firmware\AUTOSAR_MBD\RBCM_MBD\RBCM_Model_Config\Project_Settings\Linker_Files\linker_flash_s32k344.ld"

LDFLAGS += $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -specs=nano.specs -specs=nosys.specs --sysroot="E:\MATLABAddOns\Toolboxes\NXP_MBDToolbox_S32K3\tools\build_tools\gcc_v10.2\gcc-10.2-arm32-eabi\arm-none-eabi\newlib" -T "E:\Myworkspace\RBCM_S32K344_AUTOSAR_MBD\Firmware\AUTOSAR_MBD\RBCM_MBD\RBCM_Model_Config\Project_Settings\Linker_Files\linker_flash_s32k344.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Code Size" ..."
	$(CODE_SIZE) $(CODESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "ELF To Binary Converter" ..."
	$(ELF_TO_BIN) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o$(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/RBCM_Model_ert_rtw/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/RBCM_Model_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


Adc_Params.o : $(START_DIR)/RBCM_Model_ert_rtw/Adc_Params.c
	$(CC) $(CFLAGS) -o"$@" "$<"


RBCM_Model.o : $(START_DIR)/RBCM_Model_ert_rtw/RBCM_Model.c
	$(CC) $(CFLAGS) -o"$@" "$<"


RBCM_Model_data.o : $(START_DIR)/RBCM_Model_ert_rtw/RBCM_Model_data.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ert_main.o : $(START_DIR)/RBCM_Model_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_appcmd.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_appcmd.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_pipes.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_pipes.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_protocol.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_protocol.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_rec.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_rec.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_s32k3xx_lpuart.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_s32k3xx_lpuart.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_scope.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_scope.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_serial.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_serial.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_tsa.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_tsa.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_ures.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_ures.c
	$(CC) $(CFLAGS) -o"$@" "$<"


freemaster_utils.o : $(START_DIR)/RBCM_Model_Config/src/freemaster_utils.c
	$(CC) $(CFLAGS) -o"$@" "$<"


mbdt_board_init.o : $(START_DIR)/RBCM_Model_Config/src/mbdt_board_init.c
	$(CC) $(CFLAGS) -o"$@" "$<"


mbdt_lpuart.o : $(START_DIR)/RBCM_Model_Config/src/mbdt_lpuart.c
	$(CC) $(CFLAGS) -o"$@" "$<"


s32k3_trigger_config.o : $(START_DIR)/RBCM_Model_Config/src/s32k3_trigger_config.c
	$(CC) $(CFLAGS) -o"$@" "$<"


exceptions.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/exceptions.c
	$(CC) $(CFLAGS) -o"$@" "$<"


nvic.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/nvic.c
	$(CC) $(CFLAGS) -o"$@" "$<"


startup.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/startup.c
	$(CC) $(CFLAGS) -o"$@" "$<"


sys_init.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/sys_init.c
	$(CC) $(CFLAGS) -o"$@" "$<"


system.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/system.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Vector_Table.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/Vector_Table.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


startup_cm7.o : $(START_DIR)/RBCM_Model_Config/Project_Settings/Startup_Code/startup_cm7.s
	$(AS) $(ASFLAGS) -o"$@" "$<"


Adc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Adc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Ipw_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Ipw_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Sar_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Sar_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Sar_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Adc_Sar_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Axbs_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Axbs_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Bctu_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Bctu_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Bctu_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Bctu_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


C40_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/C40_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


C40_Ip_Ac.o : $(START_DIR)/RBCM_Model_Config/RTD/src/C40_Ip_Ac.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_I2c.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_I2c.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_I2c_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_I2c_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Mcl.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Mcl.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Mcl_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Mcl_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Rm.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Rm.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Rm_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Rm_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Uart.o : $(START_DIR)/RBCM_Model_Config/RTD/src/CDD_Uart.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Cache_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Cache_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Cache_Ip_HwAcc_ArmCoreMx.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Cache_Ip_HwAcc_ArmCoreMx.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Can_43_FLEXCAN.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Can_43_FLEXCAN.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Can_43_FLEXCAN_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Can_43_FLEXCAN_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Can_43_FLEXCAN_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Can_43_FLEXCAN_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Data.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Data.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Divider.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Divider.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_DividerTrigger.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_DividerTrigger.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_ExtOsc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_ExtOsc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_FracDiv.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_FracDiv.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Frequency.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Frequency.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Gate.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Gate.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_IntOsc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_IntOsc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Monitor.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Monitor.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Pll.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Pll.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_ProgFreqSwitch.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_ProgFreqSwitch.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Selector.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Selector.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Specific.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Clock_Ip_Specific.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Cmp_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Cmp_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


DSPSS_Api.o : $(START_DIR)/RBCM_Model_Config/RTD/src/DSPSS_Api.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Det.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Det.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Det_stub.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Det_stub.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dio.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dio.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dio_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dio_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip_Driver_State.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Driver_State.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip_Hw_Access.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Hw_Access.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip_Multicore.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Ip_Multicore.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Mux_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dma_Mux_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dspi_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dspi_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dspi_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Dspi_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


EcuM.o : $(START_DIR)/RBCM_Model_Config/RTD/src/EcuM.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Gpt_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Gpt_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Icu_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Icu_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Icu_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Icu_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Mcl_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Mcl_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Mcl_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Mcl_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Pwm_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Pwm_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Pwm_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Emios_Pwm_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Etpu_Pwm_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Etpu_Pwm_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Etpu_Pwm_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Etpu_Pwm_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Fee.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Fee.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexCAN_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/FlexCAN_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexCAN_Ip_HwAccess.o : $(START_DIR)/RBCM_Model_Config/RTD/src/FlexCAN_Ip_HwAccess.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexCAN_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/FlexCAN_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexPwm_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/FlexPwm_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexPwm_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/FlexPwm_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_I2c_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_I2c_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Lin_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Lin_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Mcl_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Mcl_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Mcl_Ip_HwAccess.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Mcl_Ip_HwAccess.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Mcl_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Mcl_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Pwm_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Pwm_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Pwm_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Pwm_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Spi_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Spi_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Spi_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Spi_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Uart_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Uart_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Uart_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Flexio_Uart_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Gpt.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Gpt.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Gpt_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Gpt_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Icu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Icu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Icu_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Icu_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Igf_Port_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Igf_Port_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


IntCtrl_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/IntCtrl_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lcu_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lcu_Ip_Hw_Access.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip_Hw_Access.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lcu_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lcu_Ip_Multicore.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lcu_Ip_Multicore.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_43_LPUART_FLEXIO.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_43_LPUART_FLEXIO.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_43_LPUART_FLEXIO_ASRExt.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_43_LPUART_FLEXIO_ASRExt.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_43_LPUART_FLEXIO_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_43_LPUART_FLEXIO_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_Ip_Common.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lin_Ip_Common.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpi2c_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpi2c_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpi2c_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpi2c_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpspi_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpspi_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpspi_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpspi_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Lin_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Lin_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Lin_Ip_Hw_Access.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Lin_Ip_Hw_Access.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Lin_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Lin_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Uart_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Uart_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Uart_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Lpuart_Uart_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mcu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mcu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mcu_Dem_Wrapper.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mcu_Dem_Wrapper.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mcu_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mcu_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


MemAcc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/MemAcc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


MemAcc_Sema4.o : $(START_DIR)/RBCM_Model_Config/RTD/src/MemAcc_Sema4.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mem_43_INFLS.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mem_43_INFLS.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mem_43_INFLS_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mem_43_INFLS_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mem_43_INFLS_Software_Semaphore.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mem_43_INFLS_Software_Semaphore.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mpu_M7_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mpu_M7_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mscm_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Mscm_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


OsIf_Interrupts.o : $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Interrupts.c
	$(CC) $(CFLAGS) -o"$@" "$<"


OsIf_Timer.o : $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Timer.c
	$(CC) $(CFLAGS) -o"$@" "$<"


OsIf_Timer_System.o : $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Timer_System.c
	$(CC) $(CFLAGS) -o"$@" "$<"


OsIf_Timer_System_Internal_Systick.o : $(START_DIR)/RBCM_Model_Config/RTD/src/OsIf_Timer_System_Internal_Systick.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Os_counter_api.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Os_counter_api.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Os_event.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Os_event.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Os_isr.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Os_isr.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Os_multicore.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Os_multicore.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Os_scheduler.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Os_scheduler.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Osif_Software_Semaphore.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Osif_Software_Semaphore.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pflash_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Pflash_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pit_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Pit_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Platform.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Platform.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Platform_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Platform_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Port.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Port.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Port_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Port_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_AEC.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_AEC.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_CortexM7.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_CortexM7.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_DCM_GPR.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_DCM_GPR.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_FLASH.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_FLASH.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_MC_ME.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_MC_ME.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_MC_RGM.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_MC_RGM.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_MC_RGM_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_MC_RGM_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_PMC.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_PMC.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_PMC_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_PMC_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_Private.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Power_Ip_Private.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pwm.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Pwm.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pwm_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Pwm_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pwm_Ipw_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Pwm_Ipw_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Ram_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Ram_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Rtc_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Rtc_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Adc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Adc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Ae.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ae.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Can.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Can.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_CanTrcv_43_AE.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_CanTrcv_43_AE.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_CanTrcv_43_fs23.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_CanTrcv_43_fs23.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_CanTrcv_43_fs65.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_CanTrcv_43_fs65.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Can_43_FLEXCAN.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Can_43_FLEXCAN.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Crc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Crypto.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crypto.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Crypto_43_ACE.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crypto_43_ACE.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Crypto_43_HSE.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Crypto_43_HSE.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Dio.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Dio.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Dpga.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Dpga.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Eep.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Eep.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Eth.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Eth.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_EthSwt_43_SJA11XX.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_EthSwt_43_SJA11XX.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_EthTrcv_43_PHY.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_EthTrcv_43_PHY.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Eth_43_GMAC.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Eth_43_GMAC.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Etpu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Etpu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Fee.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Fee.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Fls.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Fls.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Gd3162.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Gd3162.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Gdu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Gdu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Gpt.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Gpt.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_I2c.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_I2c.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_I2s.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_I2s.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Icu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Icu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Ipcf.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ipcf.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Iseled.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Iseled.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_LinTrcv_43_fs23.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_LinTrcv_43_fs23.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_LinTrcv_43_fs65.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_LinTrcv_43_fs65.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Lin_43_LPUART_FLEXIO.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Lin_43_LPUART_FLEXIO.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Mc12xs6.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mc12xs6.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Mcl.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mcl.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Mcu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mcu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_MemAcc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_MemAcc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Mem_43_EEP.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mem_43_EEP.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Mem_43_EXFLS.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mem_43_EXFLS.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Mem_43_INFLS.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Mem_43_INFLS.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Motor_control.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Motor_control.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Nvm.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Nvm.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Ocotp.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ocotp.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Ocu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Ocu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Platform.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Platform.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Port.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Port.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Pwm.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Pwm.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Pwm_etpu.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Pwm_etpu.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Rdc_checker.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Rdc_checker.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Rm.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Rm.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Sbc_fs23.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sbc_fs23.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Sbc_fs26.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sbc_fs26.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Sbc_fs65.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sbc_fs65.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Sent.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Sent.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Spi.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Spi.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Uart.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Uart.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Wdg.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Wdg_43_fs23.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg_43_fs23.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Wdg_43_fs26.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg_43_fs26.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Wdg_43_fs65.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Wdg_43_fs65.c
	$(CC) $(CFLAGS) -o"$@" "$<"


SchM_Zipwire.o : $(START_DIR)/RBCM_Model_Config/RTD/src/SchM_Zipwire.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Sdadc_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Sdadc_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Sdadc_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Sdadc_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Sema42_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Sema42_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Dio_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Dio_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Icu_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Icu_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Icu_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Icu_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Port_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Siul2_Port_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Spi.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Spi.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Spi_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Spi_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Stm_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Stm_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


System_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/System_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Trgmux_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Trgmux_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Trgmux_Ip_HwAcc.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Trgmux_Ip_HwAcc.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Tspc_Port_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Tspc_Port_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Uart_Ipw.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Uart_Ipw.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Virt_Wrapper_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Virt_Wrapper_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Wkpu_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Wkpu_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Wkpu_Ip_Irq.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Wkpu_Ip_Irq.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Xbic_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Xbic_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Xrdc_Ip.o : $(START_DIR)/RBCM_Model_Config/RTD/src/Xrdc_Ip.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Adc_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Adc_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Adc_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Adc_Sar_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Adc_Sar_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Axbs_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Axbs_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Bctu_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Bctu_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


C40_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/C40_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_I2c_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_I2c_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_I2c_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_I2c_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_I2c_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_I2c_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Mcl_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Mcl_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Mcl_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Mcl_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Rm_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Rm_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Rm_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Rm_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Rm_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Rm_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CDD_Uart_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CDD_Uart_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CanIf_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CanIf_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


CanIf_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/CanIf_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Can_43_FLEXCAN_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Can_43_FLEXCAN_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Can_43_FLEXCAN_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Can_43_FLEXCAN_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Clock_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Clock_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Clock_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Cmp_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Cmp_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dio_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Dio_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Dma_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Dma_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dma_Mux_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Dma_Mux_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Dspi_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Dspi_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Gpt_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Gpt_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Icu_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Icu_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Mcl_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Mcl_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Emios_Pwm_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Emios_Pwm_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Etpu_Pwm_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Etpu_Pwm_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Fee_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Fee_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexCAN_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/FlexCAN_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


FlexPwm_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/FlexPwm_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_I2c_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_I2c_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Lin_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Lin_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Mcl_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Mcl_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Pwm_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Pwm_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Spi_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Spi_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Flexio_Uart_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Flexio_Uart_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Gpt_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Gpt_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Gpt_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Gpt_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Gpt_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Gpt_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Icu_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Icu_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Icu_DmaNotification.o : $(START_DIR)/RBCM_Model_Config/generate/src/Icu_DmaNotification.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Icu_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Icu_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Icu_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Icu_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Igf_Port_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Igf_Port_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


IntCtrl_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/IntCtrl_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lcu_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lcu_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lcu_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lcu_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_43_LPUART_FLEXIO_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lin_43_LPUART_FLEXIO_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lin_43_LPUART_FLEXIO_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lin_43_LPUART_FLEXIO_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lin_43_LPUART_FLEXIO_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpi2c_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lpi2c_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpspi_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lpspi_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Lin_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lpuart_Lin_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Lpuart_Uart_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Lpuart_Uart_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mcu_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Mcu_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mcu_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Mcu_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


MemAcc_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/MemAcc_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


MemAcc_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/MemAcc_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mem_43_INFLS_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Mem_43_INFLS_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mpu_M7_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Mpu_M7_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Mscm_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Mscm_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


OsIf_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/OsIf_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pflash_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Pflash_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pflash_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Pflash_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pit_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Pit_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Platform_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Platform_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Platform_Ipw_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Platform_Ipw_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Port_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Port_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Port_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Port_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Power_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Power_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Power_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Pwm_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Pwm_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Ram_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Ram_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Ram_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Ram_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Rtc_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Rtc_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Sdadc_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Sdadc_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Icu_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Siul2_Icu_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Port_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Siul2_Port_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Siul2_Port_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Siul2_Port_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Spi_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Spi_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Spi_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Spi_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Stm_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Stm_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Trgmux_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Trgmux_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Trgmux_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Trgmux_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Tspc_Port_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Tspc_Port_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Tspc_Port_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Tspc_Port_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Uart_Ipw_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Uart_Ipw_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Virt_Wrapper_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Virt_Wrapper_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Wkpu_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Wkpu_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Xbic_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Xbic_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Xrdc_Ip_Cfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Xrdc_Ip_Cfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Xrdc_Ip_MBDT_PBcfg.o : $(START_DIR)/RBCM_Model_Config/generate/src/Xrdc_Ip_MBDT_PBcfg.c
	$(CC) $(CFLAGS) -o"$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### CODESIZE_FLAGS = $(CODESIZE_FLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


