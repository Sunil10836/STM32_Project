################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/RTC_LCD.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/RTC_LCD.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/RTC_LCD.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/Renu Electronics/3_STM32_Udemy_FastBit_EBA/001_STM32_MCU1/My_Codes_MCU1_V2/RTC_LCD/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

