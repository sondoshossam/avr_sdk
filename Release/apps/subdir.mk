################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../apps/eeprom_app.c \
../apps/input_output_task.c \
../apps/lcd_app.c \
../apps/sevensegment_app.c 

OBJS += \
./apps/eeprom_app.o \
./apps/input_output_task.o \
./apps/lcd_app.o \
./apps/sevensegment_app.o 

C_DEPS += \
./apps/eeprom_app.d \
./apps/input_output_task.d \
./apps/lcd_app.d \
./apps/sevensegment_app.d 


# Each subdirectory must supply rules for building sources it contributes
apps/%.o: ../apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


