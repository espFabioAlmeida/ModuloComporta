################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/subrotinas/SubrotinasCAN.c \
../Core/Src/subrotinas/SubrotinasEntradasDigitais.c \
../Core/Src/subrotinas/SubrotinasMotor.c 

OBJS += \
./Core/Src/subrotinas/SubrotinasCAN.o \
./Core/Src/subrotinas/SubrotinasEntradasDigitais.o \
./Core/Src/subrotinas/SubrotinasMotor.o 

C_DEPS += \
./Core/Src/subrotinas/SubrotinasCAN.d \
./Core/Src/subrotinas/SubrotinasEntradasDigitais.d \
./Core/Src/subrotinas/SubrotinasMotor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/subrotinas/%.o Core/Src/subrotinas/%.su Core/Src/subrotinas/%.cyclo: ../Core/Src/subrotinas/%.c Core/Src/subrotinas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-subrotinas

clean-Core-2f-Src-2f-subrotinas:
	-$(RM) ./Core/Src/subrotinas/SubrotinasCAN.cyclo ./Core/Src/subrotinas/SubrotinasCAN.d ./Core/Src/subrotinas/SubrotinasCAN.o ./Core/Src/subrotinas/SubrotinasCAN.su ./Core/Src/subrotinas/SubrotinasEntradasDigitais.cyclo ./Core/Src/subrotinas/SubrotinasEntradasDigitais.d ./Core/Src/subrotinas/SubrotinasEntradasDigitais.o ./Core/Src/subrotinas/SubrotinasEntradasDigitais.su ./Core/Src/subrotinas/SubrotinasMotor.cyclo ./Core/Src/subrotinas/SubrotinasMotor.d ./Core/Src/subrotinas/SubrotinasMotor.o ./Core/Src/subrotinas/SubrotinasMotor.su

.PHONY: clean-Core-2f-Src-2f-subrotinas

