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
FINAL_IMAGE=${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=HAL_Layer/7_Segment/hal_seven_segment.c HAL_Layer/button/hal_button.c HAL_Layer/keypad/hal_keypad.c HAL_Layer/LCD/hal_lcd.c HAL_Layer/LED/hal_led.c MCAL_Layer/ADC/hal_adc.c MCAL_Layer/DIO/mcal_dio.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/SPI/mcal_spi.c MCAL_Layer/Timers/mcal_timer0.c MCAL_Layer/USART/uart_prog.c MCAL_Layer/USART/hal_usart.c application.c MCAL_Layer/Timers/mcal_timer1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o ${OBJECTDIR}/application.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d ${OBJECTDIR}/application.o.d ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o ${OBJECTDIR}/application.o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o

# Source Files
SOURCEFILES=HAL_Layer/7_Segment/hal_seven_segment.c HAL_Layer/button/hal_button.c HAL_Layer/keypad/hal_keypad.c HAL_Layer/LCD/hal_lcd.c HAL_Layer/LED/hal_led.c MCAL_Layer/ADC/hal_adc.c MCAL_Layer/DIO/mcal_dio.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/SPI/mcal_spi.c MCAL_Layer/Timers/mcal_timer0.c MCAL_Layer/USART/uart_prog.c MCAL_Layer/USART/hal_usart.c application.c MCAL_Layer/Timers/mcal_timer1.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o: HAL_Layer/7_Segment/hal_seven_segment.c  .generated_files/flags/default/3683835c64a6d6ebd720922a6016fe2825afd490 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/7_Segment" 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o -o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o HAL_Layer/7_Segment/hal_seven_segment.c 
	
${OBJECTDIR}/HAL_Layer/button/hal_button.o: HAL_Layer/button/hal_button.c  .generated_files/flags/default/46ef54f53079f3669b7f4be5d6fb6d7b76783c04 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/button" 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT ${OBJECTDIR}/HAL_Layer/button/hal_button.o -o ${OBJECTDIR}/HAL_Layer/button/hal_button.o HAL_Layer/button/hal_button.c 
	
${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o: HAL_Layer/keypad/hal_keypad.c  .generated_files/flags/default/a50df21a9ed3ab2120a861a55f6276c214444a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/keypad" 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o -o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o HAL_Layer/keypad/hal_keypad.c 
	
${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o: HAL_Layer/LCD/hal_lcd.c  .generated_files/flags/default/fa2fba1fe4c89653f36f2d481873207b14b1c699 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LCD" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o -o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o HAL_Layer/LCD/hal_lcd.c 
	
${OBJECTDIR}/HAL_Layer/LED/hal_led.o: HAL_Layer/LED/hal_led.c  .generated_files/flags/default/3390988fbf0534e38ec1fd25f1260f550d823fee .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT ${OBJECTDIR}/HAL_Layer/LED/hal_led.o -o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o HAL_Layer/LED/hal_led.c 
	
${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o: MCAL_Layer/ADC/hal_adc.c  .generated_files/flags/default/f79829d7bb383641b4495e38a169310b46f72b03 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o -o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o MCAL_Layer/ADC/hal_adc.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/38ddbcbf6123315db843c54991be54a921a24f8a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o: MCAL_Layer/Interrupt/mcal_external_interrupt.c  .generated_files/flags/default/3c9b5919aebb014b22df3ba25db2c7c156d57f5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o: MCAL_Layer/SPI/mcal_spi.c  .generated_files/flags/default/8f34a4558e9f2178938648a2beab876868d06d4d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o -o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o MCAL_Layer/SPI/mcal_spi.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o: MCAL_Layer/Timers/mcal_timer0.c  .generated_files/flags/default/35d098178fbabd734e6e297b759f02abea62d6ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o MCAL_Layer/Timers/mcal_timer0.c 
	
${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o: MCAL_Layer/USART/uart_prog.c  .generated_files/flags/default/e0e56348212e185265408e332eeba04445de6ce7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o -o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o MCAL_Layer/USART/uart_prog.c 
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o: MCAL_Layer/USART/hal_usart.c  .generated_files/flags/default/7d4056f8de6d4612d8b6e7928fe284c525205057 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o MCAL_Layer/USART/hal_usart.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/e70c1c726d612c757eb61d9c5f6a068bb608c40 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o: MCAL_Layer/Timers/mcal_timer1.c  .generated_files/flags/default/a62c3616cd008f4ccb36a5d5a79f429f9f58f983 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o MCAL_Layer/Timers/mcal_timer1.c 
	
else
${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o: HAL_Layer/7_Segment/hal_seven_segment.c  .generated_files/flags/default/10d6ef2414687b7efbf19aeb6b592682ead76022 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/7_Segment" 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o -o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o HAL_Layer/7_Segment/hal_seven_segment.c 
	
${OBJECTDIR}/HAL_Layer/button/hal_button.o: HAL_Layer/button/hal_button.c  .generated_files/flags/default/f9cff961f91f1f443794ef32b770d9665f05cf32 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/button" 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT ${OBJECTDIR}/HAL_Layer/button/hal_button.o -o ${OBJECTDIR}/HAL_Layer/button/hal_button.o HAL_Layer/button/hal_button.c 
	
${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o: HAL_Layer/keypad/hal_keypad.c  .generated_files/flags/default/d514f8de42309b023649553ce2b0b427caf2310f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/keypad" 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT "${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d" -MT ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o -o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o HAL_Layer/keypad/hal_keypad.c 
	
${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o: HAL_Layer/LCD/hal_lcd.c  .generated_files/flags/default/b5bf867e5aa577b6b5d128196295cf2193dd8e19 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LCD" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT "${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d" -MT ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o -o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o HAL_Layer/LCD/hal_lcd.c 
	
${OBJECTDIR}/HAL_Layer/LED/hal_led.o: HAL_Layer/LED/hal_led.c  .generated_files/flags/default/479ce8788829f141289e1b76f09945f6842bdd36 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT ${OBJECTDIR}/HAL_Layer/LED/hal_led.o -o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o HAL_Layer/LED/hal_led.c 
	
${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o: MCAL_Layer/ADC/hal_adc.c  .generated_files/flags/default/a6d0b4627eff5d5f14669b79ebd5fe00bd75c49 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT "${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o.d" -MT ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o -o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.o MCAL_Layer/ADC/hal_adc.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/977b1e8fb7030ce2c0577e8ae7a542a509257f7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o: MCAL_Layer/Interrupt/mcal_external_interrupt.c  .generated_files/flags/default/7d32e59435e5db5d3acb41743d938f8b2dee6058 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	
${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o: MCAL_Layer/SPI/mcal_spi.c  .generated_files/flags/default/61386ed9048f798f8e17989c46712d37973fc3c5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT "${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o.d" -MT ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o -o ${OBJECTDIR}/MCAL_Layer/SPI/mcal_spi.o MCAL_Layer/SPI/mcal_spi.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o: MCAL_Layer/Timers/mcal_timer0.c  .generated_files/flags/default/ada5784bf972db662c4cd6a9725eb8e5989308be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer0.o MCAL_Layer/Timers/mcal_timer0.c 
	
${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o: MCAL_Layer/USART/uart_prog.c  .generated_files/flags/default/34bcf296931ee1dc1d681766ed1ff826387be1a0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o -o ${OBJECTDIR}/MCAL_Layer/USART/uart_prog.o MCAL_Layer/USART/uart_prog.c 
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o: MCAL_Layer/USART/hal_usart.c  .generated_files/flags/default/b4538e0b6b50082c01c4256c6a07608aa9f1009c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT "${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o.d" -MT ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.o MCAL_Layer/USART/hal_usart.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/e291df2ff9b69363845abc43805eec9b44854efc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o: MCAL_Layer/Timers/mcal_timer1.c  .generated_files/flags/default/eda86470450d1bcd7b454a86448a4b55b752f97 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timers" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o -o ${OBJECTDIR}/MCAL_Layer/Timers/mcal_timer1.o MCAL_Layer/Timers/mcal_timer1.c 
	
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
${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/NTI_AVR_COST.${IMAGE_TYPE}.hex"
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
