################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Src/stm32f446xx_gpio_driver.c \
../driver/Src/stm32f446xx_i2c_driver.c \
../driver/Src/stm32f446xx_rcc_driver.c 

OBJS += \
./driver/Src/stm32f446xx_gpio_driver.o \
./driver/Src/stm32f446xx_i2c_driver.o \
./driver/Src/stm32f446xx_rcc_driver.o 

C_DEPS += \
./driver/Src/stm32f446xx_gpio_driver.d \
./driver/Src/stm32f446xx_i2c_driver.d \
./driver/Src/stm32f446xx_rcc_driver.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/%.o: ../driver/Src/%.c driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/Renu Electronics/3_STM32_Udemy_FastBit_EBA/001_STM32_MCU1/My_Codes_MCU1_V2/RTC_LCD/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

