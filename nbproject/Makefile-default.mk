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
SOURCEFILES_QUOTED_IF_SPACED=HAL_Layer/7_Segment/hal_seven_segment.c HAL_Layer/button/hal_button.c HAL_Layer/keypad/hal_keypad.c HAL_Layer/LCD/hal_lcd.c HAL_Layer/LED/hal_led.c MCAL_Layer/ADC/ADC.c MCAL_Layer/DIO/mcal_dio.c application.c MCAL_Layer/Interrupt/mcal_external_interrupt.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/application.o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o
POSSIBLE_DEPFILES=${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o.d ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o.d ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d ${OBJECTDIR}/application.o.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/keypad/hal_keypad.o ${OBJECTDIR}/HAL_Layer/LCD/hal_lcd.o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/application.o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o

# Source Files
SOURCEFILES=HAL_Layer/7_Segment/hal_seven_segment.c HAL_Layer/button/hal_button.c HAL_Layer/keypad/hal_keypad.c HAL_Layer/LCD/hal_lcd.c HAL_Layer/LED/hal_led.c MCAL_Layer/ADC/ADC.c MCAL_Layer/DIO/mcal_dio.c application.c MCAL_Layer/Interrupt/mcal_external_interrupt.c



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
	
${OBJECTDIR}/MCAL_Layer/ADC/ADC.o: MCAL_Layer/ADC/ADC.c  .generated_files/flags/default/602830e338a314a34bb6ad12c4b44d1c4bf860db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d" -MT "${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d" -MT ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o -o ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o MCAL_Layer/ADC/ADC.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/38ddbcbf6123315db843c54991be54a921a24f8a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/e70c1c726d612c757eb61d9c5f6a068bb608c40 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o: MCAL_Layer/Interrupt/mcal_external_interrupt.c  .generated_files/flags/default/3c9b5919aebb014b22df3ba25db2c7c156d57f5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	
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
	
${OBJECTDIR}/MCAL_Layer/ADC/ADC.o: MCAL_Layer/ADC/ADC.c  .generated_files/flags/default/ae982a324365f0849ce4156ad16894069c474d1e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d" -MT "${OBJECTDIR}/MCAL_Layer/ADC/ADC.o.d" -MT ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o -o ${OBJECTDIR}/MCAL_Layer/ADC/ADC.o MCAL_Layer/ADC/ADC.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/977b1e8fb7030ce2c0577e8ae7a542a509257f7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/e291df2ff9b69363845abc43805eec9b44854efc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o: MCAL_Layer/Interrupt/mcal_external_interrupt.c  .generated_files/flags/default/7d32e59435e5db5d3acb41743d938f8b2dee6058 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT "${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o.d" -MT ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.o MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	
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
