################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/EEPROM/eeprom.c 

OBJS += \
./mcal/EEPROM/eeprom.o 

C_DEPS += \
./mcal/EEPROM/eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/EEPROM/%.o: ../mcal/EEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -DKEYSAFE_APP=1 -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


