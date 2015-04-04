################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../assets/images \
../cmsis/ \
../cmsis/linkerScripts/ \
../cmsis/src/ \
../lib \
../lib/driver/ \
../lib/driver/parameter/ \
../lib/display \
../assets


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../cmsis/src/startup_sam3xa.c \
../cmsis/src/system_sam3xa.c \
../DueRev1.cpp \
../lib/Display.cpp \
../lib/display/Bitmap.cpp \
../lib/driver/Encoders.cpp \
../lib/driver/parameter/SSD1305Params.cpp \
../lib/driver/ShiftRegisters.cpp \
../lib/driver/SPI.cpp \
../lib/driver/SSD1305.cpp \
../lib/Reporting.cpp \
../main.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
cmsis/src/startup_sam3xa.o \
cmsis/src/system_sam3xa.o \
DueRev1.o \
lib/Display.o \
lib/display/Bitmap.o \
lib/driver/Encoders.o \
lib/driver/parameter/SSD1305Params.o \
lib/driver/ShiftRegisters.o \
lib/driver/SPI.o \
lib/driver/SSD1305.o \
lib/Reporting.o \
main.o

OBJS_AS_ARGS +=  \
cmsis/src/startup_sam3xa.o \
cmsis/src/system_sam3xa.o \
DueRev1.o \
lib/Display.o \
lib/display/Bitmap.o \
lib/driver/Encoders.o \
lib/driver/parameter/SSD1305Params.o \
lib/driver/ShiftRegisters.o \
lib/driver/SPI.o \
lib/driver/SSD1305.o \
lib/Reporting.o \
main.o

C_DEPS +=  \
cmsis/src/startup_sam3xa.d \
cmsis/src/system_sam3xa.d \
DueRev1.d \
lib/Display.d \
lib/display/Bitmap.d \
lib/driver/Encoders.d \
lib/driver/parameter/SSD1305Params.d \
lib/driver/ShiftRegisters.d \
lib/driver/SPI.d \
lib/driver/SSD1305.d \
lib/Reporting.d \
main.d

C_DEPS_AS_ARGS +=  \
cmsis/src/startup_sam3xa.d \
cmsis/src/system_sam3xa.d \
DueRev1.d \
lib/Display.d \
lib/display/Bitmap.d \
lib/driver/Encoders.d \
lib/driver/parameter/SSD1305Params.d \
lib/driver/ShiftRegisters.d \
lib/driver/SPI.d \
lib/driver/SSD1305.d \
lib/Reporting.d \
main.d

OUTPUT_FILE_PATH +=OshStep.elf

OUTPUT_FILE_PATH_AS_ARGS +=OshStep.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+=  \
../cmsis/linkerScripts/sam3x8e_flash.ld \
../cmsis/linkerScripts/sam3x8e_sram.ld \
../cmsis/linkerScripts/sam3xa_flash.ld \
../cmsis/linkerScripts/sam3xa_sram.ld


# AVR32/GNU C Compiler

























cmsis/src/%.o: ../cmsis/src/%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM3X8E__ -DF_CPU=84000000L -DARDUINO=157 -DDEBUG -DDUEREV1  -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL\sam3xa\include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\CMSIS\Include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL" -I"../../../../arduinoCore" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/cores/arduino" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/variants/arduino_due_x"  -Os -fdata-sections -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m3 -c -std=gnu99 -fno-exceptions -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAM3X8E__ -DDEBUG -DDUEREV1  -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL\sam3xa\include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\CMSIS\Include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL" -I"../../../../arduinoCore" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/cores/arduino" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/variants/arduino_due_x" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/system/libsam"  -Os -fdata-sections -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m3 -c -fno-exceptions -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

lib/%.o: ../lib/%.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAM3X8E__ -DDEBUG -DDUEREV1  -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL\sam3xa\include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\CMSIS\Include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL" -I"../../../../arduinoCore" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/cores/arduino" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/variants/arduino_due_x" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/system/libsam"  -Os -fdata-sections -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m3 -c -fno-exceptions -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

lib/display/%.o: ../lib/display/%.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAM3X8E__ -DDEBUG -DDUEREV1  -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL\sam3xa\include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\CMSIS\Include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL" -I"../../../../arduinoCore" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/cores/arduino" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/variants/arduino_due_x" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/system/libsam"  -Os -fdata-sections -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m3 -c -fno-exceptions -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

lib/driver/%.o: ../lib/driver/%.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAM3X8E__ -DDEBUG -DDUEREV1  -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL\sam3xa\include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\CMSIS\Include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL" -I"../../../../arduinoCore" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/cores/arduino" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/variants/arduino_due_x" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/system/libsam"  -Os -fdata-sections -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m3 -c -fno-exceptions -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

lib/driver/parameter/%.o: ../lib/driver/parameter/%.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAM3X8E__ -DDEBUG -DDUEREV1  -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL\sam3xa\include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\CMSIS\Include" -I"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\..\..\CMSIS_Atmel\Device\ATMEL" -I"../../../../arduinoCore" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/cores/arduino" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/variants/arduino_due_x" -I"../../../../../../../../Program Files (x86)/Arduino/hardware/arduino/sam/system/libsam"  -Os -fdata-sections -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m3 -c -fno-exceptions -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker : 4.8.4
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mthumb -Wl,-Map="OshStep.map" --specs=nano.specs --specs=nosys.specs -Wl,--start-group -lm -lcore  -Wl,--end-group -L"../cmsis/linkerScripts" -L"../../../../arduinoCore"  -Wl,--gc-sections -mcpu=cortex-m3 -Tsam3x8e_flash.ld --verbose -Wl,--defsym=HEAP_SIZE=0x2000,--defsym=STACK_SIZE=0x9000  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O binary "OshStep.elf" "OshStep.bin"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "OshStep.elf" "OshStep.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O binary "OshStep.elf" "OshStep.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-objdump.exe" -h -S "OshStep.elf" > "OshStep.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "OshStep.elf" "OshStep.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\ARM GCC\Native\4.8.1443\arm-gnu-toolchain\bin\arm-none-eabi-size.exe" "OshStep.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "OshStep.elf" "OshStep.a" "OshStep.hex" "OshStep.bin" "OshStep.lss" "OshStep.eep" "OshStep.map" "OshStep.srec"
	