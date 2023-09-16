#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=FreeRTOS/croutine.c FreeRTOS/event_groups.c FreeRTOS/heap_1.c FreeRTOS/list.c FreeRTOS/mpu_wrappers.c FreeRTOS/port.c FreeRTOS/queue.c FreeRTOS/regtest.c FreeRTOS/stream_buffer.c FreeRTOS/tasks.c FreeRTOS/timers.c HAL_Layer/7_Segment/hal_seven_segment.c HAL_Layer/button/hal_button.c HAL_Layer/keypad/hal_keypad.c HAL_Layer/LCD/hal_lcd.c HAL_Layer/LED/hal_led.c MCAL_Layer/ADC/hal_adc.c MCAL_Layer/DIO/mcal_dio.c MCAL_Layer/I2C/mcal_i2c.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/SPI/mcal_spi.c MCAL_Layer/Timers/mcal_timer0.c MCAL_Layer/Timers/mcal_timer1.c MCAL_Layer/USART/uart_prog.c MCAL_Layer/USART/hal_usart.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/FreeRTOS/croutine.o ${OBJECTDIR}/FreeRTOS/event_groups.o ${OBJECTDIR}/FreeRTOS/heap_1.o ${OBJECTDIR}/FreeRTOS/list.o ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o ${OBJECTDIR}/FreeRTOS/port.o ${OBJECTDIR}/FreeRTOS/queue.o ${OBJECTDIR}/FreeRTOS/regtest.o ${OBJECTDIR}/FreeRTOS/stream_buffer.o ${OBJECTDIR}/FreeRTOS/tasks.o ${OBJECTDIR}/FreeRTOS/timers.o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o ${OBJECTDIR}/application.o
POSSIBLE_DEPFILES=${OBJECTDIR}/FreeRTOS/croutine.o.d ${OBJECTDIR}/FreeRTOS/event_groups.o.d ${OBJECTDIR}/FreeRTOS/heap_1.o.d ${OBJECTDIR}/FreeRTOS/list.o.d ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d ${OBJECTDIR}/FreeRTOS/port.o.d ${OBJECTDIR}/FreeRTOS/queue.o.d ${OBJECTDIR}/FreeRTOS/regtest.o.d ${OBJECTDIR}/FreeRTOS/stream_buffer.o.d ${OBJECTDIR}/FreeRTOS/tasks.o.d ${OBJECTDIR}/FreeRTOS/timers.o.d ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d ${OBJECTDIR}/application.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/FreeRTOS/croutine.o ${OBJECTDIR}/FreeRTOS/event_groups.o ${OBJECTDIR}/FreeRTOS/heap_1.o ${OBJECTDIR}/FreeRTOS/list.o ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o ${OBJECTDIR}/FreeRTOS/port.o ${OBJECTDIR}/FreeRTOS/queue.o ${OBJECTDIR}/FreeRTOS/regtest.o ${OBJECTDIR}/FreeRTOS/stream_buffer.o ${OBJECTDIR}/FreeRTOS/tasks.o ${OBJECTDIR}/FreeRTOS/timers.o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o ${OBJECTDIR}/application.o

# Source Files
SOURCEFILES=FreeRTOS/croutine.c FreeRTOS/event_groups.c FreeRTOS/heap_1.c FreeRTOS/list.c FreeRTOS/mpu_wrappers.c FreeRTOS/port.c FreeRTOS/queue.c FreeRTOS/regtest.c FreeRTOS/stream_buffer.c FreeRTOS/tasks.c FreeRTOS/timers.c HAL_Layer/7_Segment/hal_seven_segment.c HAL_Layer/button/hal_button.c HAL_Layer/keypad/hal_keypad.c HAL_Layer/LCD/hal_lcd.c HAL_Layer/LED/hal_led.c MCAL_Layer/ADC/hal_adc.c MCAL_Layer/DIO/mcal_dio.c MCAL_Layer/I2C/mcal_i2c.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/SPI/mcal_spi.c MCAL_Layer/Timers/mcal_timer0.c MCAL_Layer/Timers/mcal_timer1.c MCAL_Layer/USART/uart_prog.c MCAL_Layer/USART/hal_usart.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/FreeRTOS/croutine.o: FreeRTOS/croutine.c  .generated_files/flags/default/e53a3a8e7c327b15eae868e81077af3f8cb0689b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/croutine.o.d" -MT "${OBJECTDIR}/FreeRTOS/croutine.o.d" -MT ${OBJECTDIR}/FreeRTOS/croutine.o -o ${OBJECTDIR}/FreeRTOS/croutine.o FreeRTOS/croutine.c 
	
${OBJECTDIR}/FreeRTOS/event_groups.o: FreeRTOS/event_groups.c  .generated_files/flags/default/fd5e7919c17e81c219f50a0f02f056cc8e414261 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/event_groups.o.d" -MT "${OBJECTDIR}/FreeRTOS/event_groups.o.d" -MT ${OBJECTDIR}/FreeRTOS/event_groups.o -o ${OBJECTDIR}/FreeRTOS/event_groups.o FreeRTOS/event_groups.c 
	
${OBJECTDIR}/FreeRTOS/heap_1.o: FreeRTOS/heap_1.c  .generated_files/flags/default/b4daafe3f96f51840e66783ea4defabbdd2d77ae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/heap_1.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/heap_1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/heap_1.o.d" -MT "${OBJECTDIR}/FreeRTOS/heap_1.o.d" -MT ${OBJECTDIR}/FreeRTOS/heap_1.o -o ${OBJECTDIR}/FreeRTOS/heap_1.o FreeRTOS/heap_1.c 
	
${OBJECTDIR}/FreeRTOS/list.o: FreeRTOS/list.c  .generated_files/flags/default/bf7906fb0871d4101a4b6744f2b0a70f3eca345f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/list.o.d" -MT "${OBJECTDIR}/FreeRTOS/list.o.d" -MT ${OBJECTDIR}/FreeRTOS/list.o -o ${OBJECTDIR}/FreeRTOS/list.o FreeRTOS/list.c 
	
${OBJECTDIR}/FreeRTOS/mpu_wrappers.o: FreeRTOS/mpu_wrappers.c  .generated_files/flags/default/bcf54d82e39b5918348c8b8c4191abeed8a9f274 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d" -MT "${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d" -MT ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o -o ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o FreeRTOS/mpu_wrappers.c 
	
${OBJECTDIR}/FreeRTOS/port.o: FreeRTOS/port.c  .generated_files/flags/default/fb17c023665450b8555ecbb30dc1c67d0891d71 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/port.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/port.o.d" -MT "${OBJECTDIR}/FreeRTOS/port.o.d" -MT ${OBJECTDIR}/FreeRTOS/port.o -o ${OBJECTDIR}/FreeRTOS/port.o FreeRTOS/port.c 
	
${OBJECTDIR}/FreeRTOS/queue.o: FreeRTOS/queue.c  .generated_files/flags/default/fec0ae2f589b2d099d53117c4cb12de19c0110b9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/queue.o.d" -MT "${OBJECTDIR}/FreeRTOS/queue.o.d" -MT ${OBJECTDIR}/FreeRTOS/queue.o -o ${OBJECTDIR}/FreeRTOS/queue.o FreeRTOS/queue.c 
	
${OBJECTDIR}/FreeRTOS/regtest.o: FreeRTOS/regtest.c  .generated_files/flags/default/a08f8d8a1189579de2c9d92a30f5bafc5fcde1bb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/regtest.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/regtest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/regtest.o.d" -MT "${OBJECTDIR}/FreeRTOS/regtest.o.d" -MT ${OBJECTDIR}/FreeRTOS/regtest.o -o ${OBJECTDIR}/FreeRTOS/regtest.o FreeRTOS/regtest.c 
	
${OBJECTDIR}/FreeRTOS/stream_buffer.o: FreeRTOS/stream_buffer.c  .generated_files/flags/default/8cca094661ee34d3c58f1dd1af40279c29d7b75c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/stream_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/stream_buffer.o.d" -MT "${OBJECTDIR}/FreeRTOS/stream_buffer.o.d" -MT ${OBJECTDIR}/FreeRTOS/stream_buffer.o -o ${OBJECTDIR}/FreeRTOS/stream_buffer.o FreeRTOS/stream_buffer.c 
	
${OBJECTDIR}/FreeRTOS/tasks.o: FreeRTOS/tasks.c  .generated_files/flags/default/955d88a1a4a922175ac186c0cb74d372243eb520 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/tasks.o.d" -MT "${OBJECTDIR}/FreeRTOS/tasks.o.d" -MT ${OBJECTDIR}/FreeRTOS/tasks.o -o ${OBJECTDIR}/FreeRTOS/tasks.o FreeRTOS/tasks.c 
	
${OBJECTDIR}/FreeRTOS/timers.o: FreeRTOS/timers.c  .generated_files/flags/default/4599f30a82ad5523d9df2f6ef201da929cd5ffe7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/timers.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/timers.o.d" -MT "${OBJECTDIR}/FreeRTOS/timers.o.d" -MT ${OBJECTDIR}/FreeRTOS/timers.o -o ${OBJECTDIR}/FreeRTOS/timers.o FreeRTOS/timers.c 
	
${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o: HAL_Layer/7_Segment/hal_seven_segment.c  .generated_files/flags/default/f9899f3badd9e4e4ed75734d49fc71ca5bd1c153 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/7_Segment" 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o -o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o HAL_Layer/7_Segment/hal_seven_segment.c 
	
${OBJECTDIR}/HAL_Layer/button/hal_button.o: HAL_Layer/button/hal_button.c  .generated_files/flags/default/3a47609ab79168deb23635bf4ec65ca93fc95927 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/button" 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT ${OBJECTDIR}/HAL_Layer/button/hal_button.o -o ${OBJECTDIR}/HAL_Layer/button/hal_button.o HAL_Layer/button/hal_button.c 
	
${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o: HAL_Layer/keypad/hal_keypad.c  .generated_files/flags/default/b3e8f20772389e0ed71ce215f054e0e84cf2d744 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/keypad" 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o -o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o HAL_Layer/keypad/hal_keypad.c 
	
${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o: HAL_Layer/LCD/hal_lcd.c  .generated_files/flags/default/a601258fab71f94c6c8af8ffde0648367f465d62 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LCD" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o -o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o HAL_Layer/LCD/hal_lcd.c 
	
${OBJECTDIR}/HAL_Layer/LED/hal_led.o: HAL_Layer/LED/hal_led.c  .generated_files/flags/default/72a08926c5ea00fb14e97ee0487bb73799aae953 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT ${OBJECTDIR}/HAL_Layer/LED/hal_led.o -o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o HAL_Layer/LED/hal_led.c 
	
${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o: MCAL_Layer/ADC/hal_adc.c  .generated_files/flags/default/7a2f3b17fb0cd2681db3c42c38053cc0943b2fec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o -o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o MCAL_Layer/ADC/hal_adc.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/bbccb14f4f1b8932d0792faad81c13aa34754c58 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o: MCAL_Layer/I2C/mcal_i2c.c  .generated_files/flags/default/af68ca23862f012da9af9ba1f3a7b0d105c0fc31 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d" -MT "${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d" -MT ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o -o ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o MCAL_Layer/I2C/mcal_i2c.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o: MCAL_Layer/Interrupt/mcal_external_interrupt.c  .generated_files/flags/default/e98dbf423f2f0ca527d2408af0f488eaa3c9d44f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o: MCAL_Layer/SPI/mcal_spi.c  .generated_files/flags/default/cf149c933eb056e14c8635e6a4beddc950e0422e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o -o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o MCAL_Layer/SPI/mcal_spi.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o: MCAL_Layer/Timers/mcal_timer0.c  .generated_files/flags/default/da241865dc53d407c3fbe8acfe2a479e3763c81 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o MCAL_Layer/Timers/mcal_timer0.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o: MCAL_Layer/Timers/mcal_timer1.c  .generated_files/flags/default/1f71a4f1ab5b02ba615694e492e0a18bb80a2780 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o MCAL_Layer/Timers/mcal_timer1.c 
	
${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o: MCAL_Layer/USART/uart_prog.c  .generated_files/flags/default/7f8f09e9e6d293a9a39f4dfd27b830f73697c937 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o -o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o MCAL_Layer/USART/uart_prog.c 
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o: MCAL_Layer/USART/hal_usart.c  .generated_files/flags/default/3a645fb9ab6d78d35e4d88494d13d6a3315d6b11 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o MCAL_Layer/USART/hal_usart.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/1f9ff3b7f3f3e6cdecf3ef2720ff7481d6c985af .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
else
${OBJECTDIR}/FreeRTOS/croutine.o: FreeRTOS/croutine.c  .generated_files/flags/default/ab0338fee49af98a92a344892122d96164f4ef90 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/croutine.o.d" -MT "${OBJECTDIR}/FreeRTOS/croutine.o.d" -MT ${OBJECTDIR}/FreeRTOS/croutine.o -o ${OBJECTDIR}/FreeRTOS/croutine.o FreeRTOS/croutine.c 
	
${OBJECTDIR}/FreeRTOS/event_groups.o: FreeRTOS/event_groups.c  .generated_files/flags/default/4f0ba42b430b2fed8c40eb29f1a98bceb67d248f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/event_groups.o.d" -MT "${OBJECTDIR}/FreeRTOS/event_groups.o.d" -MT ${OBJECTDIR}/FreeRTOS/event_groups.o -o ${OBJECTDIR}/FreeRTOS/event_groups.o FreeRTOS/event_groups.c 
	
${OBJECTDIR}/FreeRTOS/heap_1.o: FreeRTOS/heap_1.c  .generated_files/flags/default/a7b82399266485a9e0d14c3c3396a91f88cfc70f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/heap_1.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/heap_1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/heap_1.o.d" -MT "${OBJECTDIR}/FreeRTOS/heap_1.o.d" -MT ${OBJECTDIR}/FreeRTOS/heap_1.o -o ${OBJECTDIR}/FreeRTOS/heap_1.o FreeRTOS/heap_1.c 
	
${OBJECTDIR}/FreeRTOS/list.o: FreeRTOS/list.c  .generated_files/flags/default/dd81d82a292a0167cdad7ba36d22dc83d16750cf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/list.o.d" -MT "${OBJECTDIR}/FreeRTOS/list.o.d" -MT ${OBJECTDIR}/FreeRTOS/list.o -o ${OBJECTDIR}/FreeRTOS/list.o FreeRTOS/list.c 
	
${OBJECTDIR}/FreeRTOS/mpu_wrappers.o: FreeRTOS/mpu_wrappers.c  .generated_files/flags/default/5c822e7243178e01bd1b128822754b25cd4f1db1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d" -MT "${OBJECTDIR}/FreeRTOS/mpu_wrappers.o.d" -MT ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o -o ${OBJECTDIR}/FreeRTOS/mpu_wrappers.o FreeRTOS/mpu_wrappers.c 
	
${OBJECTDIR}/FreeRTOS/port.o: FreeRTOS/port.c  .generated_files/flags/default/519d8194fb15b578b071ec6e7232c439f7a8b704 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/port.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/port.o.d" -MT "${OBJECTDIR}/FreeRTOS/port.o.d" -MT ${OBJECTDIR}/FreeRTOS/port.o -o ${OBJECTDIR}/FreeRTOS/port.o FreeRTOS/port.c 
	
${OBJECTDIR}/FreeRTOS/queue.o: FreeRTOS/queue.c  .generated_files/flags/default/3b704b64af5ae1a38fe4a8241a93a4caaf087e63 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/queue.o.d" -MT "${OBJECTDIR}/FreeRTOS/queue.o.d" -MT ${OBJECTDIR}/FreeRTOS/queue.o -o ${OBJECTDIR}/FreeRTOS/queue.o FreeRTOS/queue.c 
	
${OBJECTDIR}/FreeRTOS/regtest.o: FreeRTOS/regtest.c  .generated_files/flags/default/c2e7110e5acae606f284b1fa3c6b42fc6de114c2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/regtest.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/regtest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/regtest.o.d" -MT "${OBJECTDIR}/FreeRTOS/regtest.o.d" -MT ${OBJECTDIR}/FreeRTOS/regtest.o -o ${OBJECTDIR}/FreeRTOS/regtest.o FreeRTOS/regtest.c 
	
${OBJECTDIR}/FreeRTOS/stream_buffer.o: FreeRTOS/stream_buffer.c  .generated_files/flags/default/54b68bed53009202a5474d1d3c3d1bbbbe9e4e08 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/stream_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/stream_buffer.o.d" -MT "${OBJECTDIR}/FreeRTOS/stream_buffer.o.d" -MT ${OBJECTDIR}/FreeRTOS/stream_buffer.o -o ${OBJECTDIR}/FreeRTOS/stream_buffer.o FreeRTOS/stream_buffer.c 
	
${OBJECTDIR}/FreeRTOS/tasks.o: FreeRTOS/tasks.c  .generated_files/flags/default/e3cfdd13ecfb74d9ccb41e807b57233d56385192 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/tasks.o.d" -MT "${OBJECTDIR}/FreeRTOS/tasks.o.d" -MT ${OBJECTDIR}/FreeRTOS/tasks.o -o ${OBJECTDIR}/FreeRTOS/tasks.o FreeRTOS/tasks.c 
	
${OBJECTDIR}/FreeRTOS/timers.o: FreeRTOS/timers.c  .generated_files/flags/default/d36dde2a93b1a68fd9d8ef71f9493041f85c9e99 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/timers.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/FreeRTOS/timers.o.d" -MT "${OBJECTDIR}/FreeRTOS/timers.o.d" -MT ${OBJECTDIR}/FreeRTOS/timers.o -o ${OBJECTDIR}/FreeRTOS/timers.o FreeRTOS/timers.c 
	
${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o: HAL_Layer/7_Segment/hal_seven_segment.c  .generated_files/flags/default/98110f8f773fab6e28fecd19bc3a00ddc4235326 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/7_Segment" 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o -o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o HAL_Layer/7_Segment/hal_seven_segment.c 
	
${OBJECTDIR}/HAL_Layer/button/hal_button.o: HAL_Layer/button/hal_button.c  .generated_files/flags/default/12af59add9192f381f600f61849cc6c0f67f9b65 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/button" 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT ${OBJECTDIR}/HAL_Layer/button/hal_button.o -o ${OBJECTDIR}/HAL_Layer/button/hal_button.o HAL_Layer/button/hal_button.c 
	
${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o: HAL_Layer/keypad/hal_keypad.c  .generated_files/flags/default/59767c73c498991c333429691889b06882d22bc2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/keypad" 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o -o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o HAL_Layer/keypad/hal_keypad.c 
	
${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o: HAL_Layer/LCD/hal_lcd.c  .generated_files/flags/default/80968bada9bdfbd5e76ba174de03fd5995f153be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LCD" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o -o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o HAL_Layer/LCD/hal_lcd.c 
	
${OBJECTDIR}/HAL_Layer/LED/hal_led.o: HAL_Layer/LED/hal_led.c  .generated_files/flags/default/f028a8e8c0997a5a0f7afb8b3fa9bf5b16991a58 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT ${OBJECTDIR}/HAL_Layer/LED/hal_led.o -o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o HAL_Layer/LED/hal_led.c 
	
${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o: MCAL_Layer/ADC/hal_adc.c  .generated_files/flags/default/92bc95895026e31951a2495fde42daffa1349171 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o -o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o MCAL_Layer/ADC/hal_adc.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/e5e93cdd52fc6a76908e42017b2d6014ef4a3248 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o: MCAL_Layer/I2C/mcal_i2c.c  .generated_files/flags/default/d5bb33c2b1377a29e40285d87ab549bfb9ce9b99 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d" -MT "${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o.d" -MT ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o -o ${OBJECTDIR}/MCAL_Layer/I2C/mcal_i2c.o MCAL_Layer/I2C/mcal_i2c.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o: MCAL_Layer/Interrupt/mcal_external_interrupt.c  .generated_files/flags/default/aba8664f8254e9d9ad75bbc22cf9d8b77cc66541 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o: MCAL_Layer/SPI/mcal_spi.c  .generated_files/flags/default/c8200af5031f79176cbcc61ea562717fffc2ae88 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o -o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o MCAL_Layer/SPI/mcal_spi.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o: MCAL_Layer/Timers/mcal_timer0.c  .generated_files/flags/default/847657865b3c559800f27be4ec49f9a5c1c4111e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o MCAL_Layer/Timers/mcal_timer0.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o: MCAL_Layer/Timers/mcal_timer1.c  .generated_files/flags/default/ea1cec035ed9f38dbdfe4d7e98aa6495874e04d0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o MCAL_Layer/Timers/mcal_timer1.c 
	
${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o: MCAL_Layer/USART/uart_prog.c  .generated_files/flags/default/89e30b315e810955fe89867df1bd034a119a74e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o -o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o MCAL_Layer/USART/uart_prog.c 
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o: MCAL_Layer/USART/hal_usart.c  .generated_files/flags/default/b43eb23b81843d0b431f0f4156f6777f321c52ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o MCAL_Layer/USART/hal_usart.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/e7e318b0cfd1b30820a499a35417dd6f57ea25b5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/NTI_AVR_COTS.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
