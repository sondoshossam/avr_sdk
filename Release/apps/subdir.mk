################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../apps/adc_app.c \
../apps/eeprom_app.c \
../apps/external_dac.c \
../apps/fire_sensor.c \
../apps/i2c_app.c \
../apps/input_output_task.c \
../apps/keypad_app.c \
../apps/lcd_app.c \
../apps/pwm_app.c \
../apps/robot_movement.c \
../apps/sevensegment_app.c \
../apps/spi_test_transmition.c \
../apps/timer0_test.c \
../apps/ultra_sonic.c 

OBJS += \
./apps/adc_app.o \
./apps/eeprom_app.o \
./apps/external_dac.o \
./apps/fire_sensor.o \
./apps/i2c_app.o \
./apps/input_output_task.o \
./apps/keypad_app.o \
./apps/lcd_app.o \
./apps/pwm_app.o \
./apps/robot_movement.o \
./apps/sevensegment_app.o \
./apps/spi_test_transmition.o \
./apps/timer0_test.o \
./apps/ultra_sonic.o 

C_DEPS += \
./apps/adc_app.d \
./apps/eeprom_app.d \
./apps/external_dac.d \
./apps/fire_sensor.d \
./apps/i2c_app.d \
./apps/input_output_task.d \
./apps/keypad_app.d \
./apps/lcd_app.d \
./apps/pwm_app.d \
./apps/robot_movement.d \
./apps/sevensegment_app.d \
./apps/spi_test_transmition.d \
./apps/timer0_test.d \
./apps/ultra_sonic.d 


# Each subdirectory must supply rules for building sources it contributes
apps/%.o: ../apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -DKEYSAFE_APP=1 -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


