################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UI_gLCD/ui_gLCD.c 

OBJS += \
./UI_gLCD/ui_gLCD.o 

C_DEPS += \
./UI_gLCD/ui_gLCD.d 


# Each subdirectory must supply rules for building sources it contributes
UI_gLCD/ui_gLCD.o: ../UI_gLCD/ui_gLCD.c UI_gLCD/subdir.mk
<<<<<<< HEAD
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/_Project/LVTN/main_LVTN_03/Source_rc522" -I"D:/_Project/LVTN/main_LVTN_03/Source_gLCD" -I"D:/_Project/LVTN/main_LVTN_03/MLX90614BAA" -I"D:/_Project/LVTN/main_LVTN_03/Src_HX711" -I"D:/_Project/LVTN/main_LVTN_03/util" -I"D:/_Project/LVTN/main_LVTN_03/UI_gLCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"UI_gLCD/ui_gLCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
=======
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/_Project/LVTN/main_LVTN_03/Source_rc522" -I"D:/_Project/LVTN/main_LVTN_03/Source_gLCD" -I"D:/_Project/LVTN/main_LVTN_03/MLX90614BAA" -I"D:/_Project/LVTN/main_LVTN_03/Src_HX711" -I"D:/_Project/LVTN/main_LVTN_03/util" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"UI_gLCD/ui_gLCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
>>>>>>> hx711

