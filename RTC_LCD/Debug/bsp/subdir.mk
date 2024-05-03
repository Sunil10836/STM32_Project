################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp/ds1307.c \
../bsp/lcd.c 

OBJS += \
./bsp/ds1307.o \
./bsp/lcd.o 

C_DEPS += \
./bsp/ds1307.d \
./bsp/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/%.o: ../bsp/%.c bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/Renu Electronics/3_STM32_Udemy_FastBit_EBA/001_STM32_MCU1/My_Codes_MCU1_V2/RTC_LCD/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

