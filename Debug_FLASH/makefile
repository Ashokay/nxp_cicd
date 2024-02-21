################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
eg_M7_0.siz \

# Define the name for the hex file
HEX_FILE := eg_M7_0.hex

# All Target
all: eg_M7_0.elf $(HEX_FILE) secondary-outputs

dependents:
	-cd /app/eg_M7_1/Debug_FLASH && $(MAKE) all

# Tool invocations
eg_M7_0.elf: $(OBJS) /app/Project_Settings/Linker_Files/linker_flash_c0_s32k324.ld $(USER_OBJS) /app/Debug_FLASH/eg_M7_1.elf
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "eg_M7_0.elf" "@eg_M7_0.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

eg_M7_0.siz: eg_M7_0.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley eg_M7_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Rule to generate the hex file from the elf file
$(HEX_FILE): eg_M7_0.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O ihex eg_M7_0.elf $(HEX_FILE)
	@echo 'Finished building: $@'
	@echo ' '


# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents
/app/Debug_FLASH/eg_M7_1.elf:

-include ../makefile.targets
