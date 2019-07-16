################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mcal/EEPROM/subdir.mk
-include mcal/DIO/subdir.mk
-include hal/seven_segment/subdir.mk
-include hal/lcd/subdir.mk
-include apps/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
avr_sdk.lss \

FLASH_IMAGE += \
avr_sdk.hex \

EEPROM_IMAGE += \
avr_sdk.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: avr_sdk.elf secondary-outputs

# Tool invocations
avr_sdk.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,avr_sdk.map -mmcu=atmega328p -o "avr_sdk.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

avr_sdk.lss: avr_sdk.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S avr_sdk.elf  >"avr_sdk.lss"
	@echo 'Finished building: $@'
	@echo ' '

avr_sdk.hex: avr_sdk.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex avr_sdk.elf  "avr_sdk.hex"
	@echo 'Finished building: $@'
	@echo ' '

avr_sdk.eep: avr_sdk.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex avr_sdk.elf  "avr_sdk.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: avr_sdk.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p avr_sdk.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) avr_sdk.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
