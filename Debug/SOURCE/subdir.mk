################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SOURCE/ADC_PROGRAM.c \
../SOURCE/BUZZER_PROGRAM.c \
../SOURCE/DIO_PROGRAM.c \
../SOURCE/GLUCOSE_SENSOR_PROGRAM.c \
../SOURCE/LCD_PROGRAM.c 

OBJS += \
./SOURCE/ADC_PROGRAM.o \
./SOURCE/BUZZER_PROGRAM.o \
./SOURCE/DIO_PROGRAM.o \
./SOURCE/GLUCOSE_SENSOR_PROGRAM.o \
./SOURCE/LCD_PROGRAM.o 

C_DEPS += \
./SOURCE/ADC_PROGRAM.d \
./SOURCE/BUZZER_PROGRAM.d \
./SOURCE/DIO_PROGRAM.d \
./SOURCE/GLUCOSE_SENSOR_PROGRAM.d \
./SOURCE/LCD_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
SOURCE/%.o: ../SOURCE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


