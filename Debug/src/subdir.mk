################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graphics.cpp \
../src/s2nTest.cpp 

OBJS += \
./src/Graphics.o \
./src/s2nTest.o 

CPP_DEPS += \
./src/Graphics.d \
./src/s2nTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++  -o   "$@" "$<" -I/usr/include/glib-2.0 -I/usr/include/gtk-2.0 -I/home/wangyuchen/softwares/s2n-master -I/usr/include/gdk-pixbuf-2.0 -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config --cflags --libs gtk+-2.0` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"
	@echo 'Finished building: $<'
	@echo ' '


