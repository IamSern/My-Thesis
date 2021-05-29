################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MLX90614BAA/MLX90614.c 

OBJS += \
./MLX90614BAA/MLX90614.o 

C_DEPS += \
./MLX90614BAA/MLX90614.d 


# Each subdirectory must supply rules for building sources it contributes
MLX90614BAA/MLX90614.o: ../MLX90614BAA/MLX90614.c MLX90614BAA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/_Project/LVTN/main_LVTN_03/Source_rc522" -I"D:/_Project/LVTN/main_LVTN_03/Source_gLCD" -I"D:/_Project/LVTN/main_LVTN_03/MLX90614BAA" -I"D:/_Project/LVTN/main_LVTN_03/Src_HX711" -I"D:/_Project/LVTN/main_LVTN_03/util" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MLX90614BAA/MLX90614.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

