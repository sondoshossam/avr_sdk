################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/h_bridge/h_bridge.c 

OBJS += \
./hal/h_bridge/h_bridge.o 

C_DEPS += \
./hal/h_bridge/h_bridge.d 


# Each subdirectory must supply rules for building sources it contributes
hal/h_bridge/%.o: ../hal/h_bridge/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -DKEYSAFE_APP=1 -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


