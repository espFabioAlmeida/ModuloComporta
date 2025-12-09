################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/subrotinas/SubrotinasControlePosicao.c \
../Core/Src/subrotinas/SubrotinasEntradasDigitais.c 

OBJS += \
./Core/Src/subrotinas/SubrotinasControlePosicao.o \
./Core/Src/subrotinas/SubrotinasEntradasDigitais.o 

C_DEPS += \
./Core/Src/subrotinas/SubrotinasControlePosicao.d \
./Core/Src/subrotinas/SubrotinasEntradasDigitais.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/subrotinas/%.o Core/Src/subrotinas/%.su Core/Src/subrotinas/%.cyclo: ../Core/Src/subrotinas/%.c Core/Src/subrotinas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-subrotinas

clean-Core-2f-Src-2f-subrotinas:
	-$(RM) ./Core/Src/subrotinas/SubrotinasControlePosicao.cyclo ./Core/Src/subrotinas/SubrotinasControlePosicao.d ./Core/Src/subrotinas/SubrotinasControlePosicao.o ./Core/Src/subrotinas/SubrotinasControlePosicao.su ./Core/Src/subrotinas/SubrotinasEntradasDigitais.cyclo ./Core/Src/subrotinas/SubrotinasEntradasDigitais.d ./Core/Src/subrotinas/SubrotinasEntradasDigitais.o ./Core/Src/subrotinas/SubrotinasEntradasDigitais.su

.PHONY: clean-Core-2f-Src-2f-subrotinas

