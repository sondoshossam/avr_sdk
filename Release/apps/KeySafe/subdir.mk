################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../apps/KeySafe/keysafe_app.c 

OBJS += \
./apps/KeySafe/keysafe_app.o 

C_DEPS += \
./apps/KeySafe/keysafe_app.d 


# Each subdirectory must supply rules for building sources it contributes
apps/KeySafe/%.o: ../apps/KeySafe/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -DKEYSAFE_APP=1 -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


