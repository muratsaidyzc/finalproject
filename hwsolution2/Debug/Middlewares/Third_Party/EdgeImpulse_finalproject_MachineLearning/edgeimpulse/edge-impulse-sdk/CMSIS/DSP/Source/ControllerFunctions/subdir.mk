################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.c \
../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.c 

C_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.d \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.d 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.o \
./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/%.o Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/%.su: ../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/%.c Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_finalproject_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-DSP-2f-Source-2f-ControllerFunctions

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_finalproject_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-DSP-2f-Source-2f-ControllerFunctions:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.su ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.d ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.o ./Middlewares/Third_Party/EdgeImpulse_finalproject_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_finalproject_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-DSP-2f-Source-2f-ControllerFunctions

