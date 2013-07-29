################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/anonimous/bugurtos/kernel/crit_sec.c \
/home/anonimous/bugurtos/kernel/index.c \
/home/anonimous/bugurtos/kernel/ipc.c \
/home/anonimous/bugurtos/kernel/item.c \
/home/anonimous/bugurtos/kernel/kernel.c \
/home/anonimous/bugurtos/kernel/mutex.c \
/home/anonimous/bugurtos/kernel/pcounter.c \
/home/anonimous/bugurtos/kernel/pitem.c \
/home/anonimous/bugurtos/kernel/proc.c \
/home/anonimous/bugurtos/kernel/sched.c \
/home/anonimous/bugurtos/kernel/sem.c \
/home/anonimous/bugurtos/kernel/sig.c \
/home/anonimous/bugurtos/kernel/syscall.c \
/home/anonimous/bugurtos/kernel/timer.c \
/home/anonimous/bugurtos/kernel/xlist.c 

OBJS += \
./src/bugurtos/kernel/crit_sec.o \
./src/bugurtos/kernel/index.o \
./src/bugurtos/kernel/ipc.o \
./src/bugurtos/kernel/item.o \
./src/bugurtos/kernel/kernel.o \
./src/bugurtos/kernel/mutex.o \
./src/bugurtos/kernel/pcounter.o \
./src/bugurtos/kernel/pitem.o \
./src/bugurtos/kernel/proc.o \
./src/bugurtos/kernel/sched.o \
./src/bugurtos/kernel/sem.o \
./src/bugurtos/kernel/sig.o \
./src/bugurtos/kernel/syscall.o \
./src/bugurtos/kernel/timer.o \
./src/bugurtos/kernel/xlist.o 

C_DEPS += \
./src/bugurtos/kernel/crit_sec.d \
./src/bugurtos/kernel/index.d \
./src/bugurtos/kernel/ipc.d \
./src/bugurtos/kernel/item.d \
./src/bugurtos/kernel/kernel.d \
./src/bugurtos/kernel/mutex.d \
./src/bugurtos/kernel/pcounter.d \
./src/bugurtos/kernel/pitem.d \
./src/bugurtos/kernel/proc.d \
./src/bugurtos/kernel/sched.d \
./src/bugurtos/kernel/sem.d \
./src/bugurtos/kernel/sig.d \
./src/bugurtos/kernel/syscall.d \
./src/bugurtos/kernel/timer.d \
./src/bugurtos/kernel/xlist.d 


# Each subdirectory must supply rules for building sources it contributes
src/bugurtos/kernel/crit_sec.o: /home/anonimous/bugurtos/kernel/crit_sec.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/index.o: /home/anonimous/bugurtos/kernel/index.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/ipc.o: /home/anonimous/bugurtos/kernel/ipc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/item.o: /home/anonimous/bugurtos/kernel/item.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/kernel.o: /home/anonimous/bugurtos/kernel/kernel.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/mutex.o: /home/anonimous/bugurtos/kernel/mutex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/pcounter.o: /home/anonimous/bugurtos/kernel/pcounter.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/pitem.o: /home/anonimous/bugurtos/kernel/pitem.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/proc.o: /home/anonimous/bugurtos/kernel/proc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/sched.o: /home/anonimous/bugurtos/kernel/sched.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/sem.o: /home/anonimous/bugurtos/kernel/sem.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/sig.o: /home/anonimous/bugurtos/kernel/sig.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/syscall.o: /home/anonimous/bugurtos/kernel/syscall.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/timer.o: /home/anonimous/bugurtos/kernel/timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bugurtos/kernel/xlist.o: /home/anonimous/bugurtos/kernel/xlist.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC17xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/home/anonimous/bugurtos/tests/arch/cm3/CMSISv2p00_LPC17xx/inc" -I"/home/anonimous/bugurtos/tests/arch/cm3" -I"/home/anonimous/bugurtos/tests/arch/cm3"/../../../include -include"/home/anonimous/bugurtos/tests/arch/cm3"/config.h -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


