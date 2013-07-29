################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/anonimous/bugurtos/arch/cm3/gcc/bugurt_kernel.c 

OBJS += \
./src/bugurtos/cm3/bugurt_kernel.o 

C_DEPS += \
./src/bugurtos/cm3/bugurt_kernel.d 


# Each subdirectory must supply rules for building sources it contributes
src/bugurtos/cm3/bugurt_kernel.o: /home/anonimous/bugurtos/arch/cm3/gcc/bugurt_kernel.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


