################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SOURCE/subdir.mk
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
Glucose-Monitoring-System.lss \

FLASH_IMAGE += \
Glucose-Monitoring-System.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Glucose-Monitoring-System.elf secondary-outputs

# Tool invocations
Glucose-Monitoring-System.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Glucose-Monitoring-System.map -mmcu=atmega16 -o "Glucose-Monitoring-System.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Glucose-Monitoring-System.lss: Glucose-Monitoring-System.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Glucose-Monitoring-System.elf  >"Glucose-Monitoring-System.lss"
	@echo 'Finished building: $@'
	@echo ' '

Glucose-Monitoring-System.hex: Glucose-Monitoring-System.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Glucose-Monitoring-System.elf  "Glucose-Monitoring-System.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Glucose-Monitoring-System.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Glucose-Monitoring-System.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Glucose-Monitoring-System.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
