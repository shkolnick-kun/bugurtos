################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/anonimous/bugurtos/tests/arch/cm3/cr_startup_lpc176x.c \
/home/anonimous/bugurtos/tests/main/sched/main.c \
/home/anonimous/bugurtos/tests/arch/cm3/test_func.c 

OBJS += \
./src/cr_startup_lpc176x.o \
./src/main.o \
./src/test_func.o 

C_DEPS += \
./src/cr_startup_lpc176x.d \
./src/main.d \
./src/test_func.d 


# Each subdirectory must supply rules for building sources it contributes
src/cr_startup_lpc176x.o: /home/anonimous/bugurtos/tests/arch/cm3/cr_startup_lpc176x.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__NEWLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: /home/anonimous/bugurtos/tests/main/sched/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__NEWLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/test_func.o: /home/anonimous/bugurtos/tests/arch/cm3/test_func.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__NEWLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


