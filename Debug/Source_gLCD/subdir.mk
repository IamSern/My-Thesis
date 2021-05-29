################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source_gLCD/ST7565.c \
../Source_gLCD/fonts.c 

OBJS += \
./Source_gLCD/ST7565.o \
./Source_gLCD/fonts.o 

C_DEPS += \
./Source_gLCD/ST7565.d \
./Source_gLCD/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
Source_gLCD/ST7565.o: ../Source_gLCD/ST7565.c Source_gLCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/_Project/LVTN/main_LVTN_03/Source_rc522" -I"D:/_Project/LVTN/main_LVTN_03/Source_gLCD" -I"D:/_Project/LVTN/main_LVTN_03/MLX90614BAA" -I"D:/_Project/LVTN/main_LVTN_03/Src_HX711" -I"D:/_Project/LVTN/main_LVTN_03/util" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Source_gLCD/ST7565.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Source_gLCD/fonts.o: ../Source_gLCD/fonts.c Source_gLCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/_Project/LVTN/main_LVTN_03/Source_rc522" -I"D:/_Project/LVTN/main_LVTN_03/Source_gLCD" -I"D:/_Project/LVTN/main_LVTN_03/MLX90614BAA" -I"D:/_Project/LVTN/main_LVTN_03/Src_HX711" -I"D:/_Project/LVTN/main_LVTN_03/util" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Source_gLCD/fonts.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

