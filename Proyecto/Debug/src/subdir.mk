################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Barrio.cpp \
../src/Barrios.cpp \
../src/Distrito.cpp \
../src/Distritos.cpp \
../src/Farola.cpp \
../src/OpenDataCc.cpp \
../src/PruebasDeModulosProyecto.cpp \
../src/Via.cpp \
../src/Vias.cpp \
../src/coords.cpp \
../src/timer.cpp \
../src/ui.cpp 

OBJS += \
./src/Barrio.o \
./src/Barrios.o \
./src/Distrito.o \
./src/Distritos.o \
./src/Farola.o \
./src/OpenDataCc.o \
./src/PruebasDeModulosProyecto.o \
./src/Via.o \
./src/Vias.o \
./src/coords.o \
./src/timer.o \
./src/ui.o 

CPP_DEPS += \
./src/Barrio.d \
./src/Barrios.d \
./src/Distrito.d \
./src/Distritos.d \
./src/Farola.d \
./src/OpenDataCc.d \
./src/PruebasDeModulosProyecto.d \
./src/Via.d \
./src/Vias.d \
./src/coords.d \
./src/timer.d \
./src/ui.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


