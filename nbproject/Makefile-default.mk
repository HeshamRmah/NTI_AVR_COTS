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
FINAL_IMAGE=${DISTDIR}/COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=HAL_Layer/LED/hal_led.c MCAL_Layer/DIO/mcal_dio.c application.c HAL_Layer/button/hal_button.c HAL_Layer/7_Segment/hal_seven_segment.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/application.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o
POSSIBLE_DEPFILES=${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d ${OBJECTDIR}/application.o.d ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/HAL_Layer/LED/hal_led.o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o ${OBJECTDIR}/application.o ${OBJECTDIR}/HAL_Layer/button/hal_button.o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o

# Source Files
SOURCEFILES=HAL_Layer/LED/hal_led.c MCAL_Layer/DIO/mcal_dio.c application.c HAL_Layer/button/hal_button.c HAL_Layer/7_Segment/hal_seven_segment.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/HAL_Layer/LED/hal_led.o: HAL_Layer/LED/hal_led.c  .generated_files/flags/default/6a1018a51c75aefdcb24f88e311a81feae08033a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT ${OBJECTDIR}/HAL_Layer/LED/hal_led.o -o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o HAL_Layer/LED/hal_led.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/a5f0339975c5ec7adaf4c7b7978a436ff5cda704 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/aaeb730984e3eddf7edb8b72a4a34c79d7f1ddad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
${OBJECTDIR}/HAL_Layer/button/hal_button.o: HAL_Layer/button/hal_button.c  .generated_files/flags/default/cb9522acf088be6e5e146c8a2b10722ca339d931 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/button" 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT ${OBJECTDIR}/HAL_Layer/button/hal_button.o -o ${OBJECTDIR}/HAL_Layer/button/hal_button.o HAL_Layer/button/hal_button.c 
	
${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o: HAL_Layer/7_Segment/hal_seven_segment.c  .generated_files/flags/default/5417eb94d82a095430b1ee4c1fce0cd7296bf3a2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/7_Segment" 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o -o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o HAL_Layer/7_Segment/hal_seven_segment.c 
	
else
${OBJECTDIR}/HAL_Layer/LED/hal_led.o: HAL_Layer/LED/hal_led.c  .generated_files/flags/default/bff3688105c36acf77824a2bb84a8006d54798d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/LED" 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/LED/hal_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT "${OBJECTDIR}/HAL_Layer/LED/hal_led.o.d" -MT ${OBJECTDIR}/HAL_Layer/LED/hal_led.o -o ${OBJECTDIR}/HAL_Layer/LED/hal_led.o HAL_Layer/LED/hal_led.c 
	
${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o: MCAL_Layer/DIO/mcal_dio.c  .generated_files/flags/default/9e592d9331773c08a7fc3fe9c3d896f231f720a0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT "${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o.d" -MT ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o -o ${OBJECTDIR}/MCAL_Layer/DIO/mcal_dio.o MCAL_Layer/DIO/mcal_dio.c 
	
${OBJECTDIR}/application.o: application.c  .generated_files/flags/default/3f01d4b6c3f5fb2eda4d793c404040a135a23d46 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.o.d 
	@${RM} ${OBJECTDIR}/application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/application.o.d" -MT "${OBJECTDIR}/application.o.d" -MT ${OBJECTDIR}/application.o -o ${OBJECTDIR}/application.o application.c 
	
${OBJECTDIR}/HAL_Layer/button/hal_button.o: HAL_Layer/button/hal_button.c  .generated_files/flags/default/e3455a6a29c7d1a7b30b0663edd0b34acab52234 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/button" 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/button/hal_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT "${OBJECTDIR}/HAL_Layer/button/hal_button.o.d" -MT ${OBJECTDIR}/HAL_Layer/button/hal_button.o -o ${OBJECTDIR}/HAL_Layer/button/hal_button.o HAL_Layer/button/hal_button.c 
	
${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o: HAL_Layer/7_Segment/hal_seven_segment.c  .generated_files/flags/default/6827300fd92cad7aad0c2deecdda4613df80ef3b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/HAL_Layer/7_Segment" 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d 
	@${RM} ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT "${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o.d" -MT ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o -o ${OBJECTDIR}/HAL_Layer/7_Segment/hal_seven_segment.o HAL_Layer/7_Segment/hal_seven_segment.c 
	
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
${DISTDIR}/COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/COST.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/COST.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/COST.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/COST.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mconst-data-in-progmem -mno-const-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/COST.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/COST.${IMAGE_TYPE}.hex"
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
