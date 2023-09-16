/* 
 * File:   mcal_timer1.h
 * Author: Hesham
 *
 * Created on August 5, 2023, 9:18 AM
 */

#ifndef MCAL_TIMER1_H
#define	MCAL_TIMER1_H

/* ----------------- Includes -----------------*/
#include "timers_reg_cfg.h"
#include "../mcal_std_types.h"
#include "../Interrupt/interrupt_config.h"
#include "../DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/


/* ----------------- Macro Functions Declarations -----------------*/
#define  TIMER1_OVERFLOW_INTERRUPT_ENABLE()                 (TIMSKbits.TOIE1_bit = 1)
#define  TIMER1_OVERFLOW_INTERRUPT_DISABLE()                (TIMSKbits.TOIE1_bit = 0)

#define  TIMER1_COMPARE_MATCH_UNIT_A_INTERRUPT_ENABLE()     (TIMSKbits.OCIE1A_bit = 1)
#define  TIMER1_COMPARE_MATCH_UNIT_A_INTERRUPT_DISABLE()    (TIMSKbits.OCIE1A_bit = 0)

#define  TIMER1_COMPARE_MATCH_UNIT_B_INTERRUPT_ENABLE()     (TIMSKbits.OCIE1B_bit = 1)
#define  TIMER1_COMPARE_MATCH_UNIT_B_INTERRUPT_DISABLE()    (TIMSKbits.OCIE1B_bit = 0)

#define  TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE()            (TIMSKbits.TICIE1_bit = 1)
#define  TIMER1_INPUT_CAPTURE_INTERRUPT_DISABLE()           (TIMSKbits.TICIE1_bit = 0)

#define  TIMER1_DIABLE()                                    (TCCR1Bbits.CS_bits = 0)

#define  TIMER1_OVERFLOW_INTERRUPT_CLEAR_FALGE()             (TIFRbits.TOV1_bit = 1)
#define  TIMER1_COMPARE_MATCH_UNIT_A_INTERRUPT_CLEAR_FALGE() (TIFRbits.OCF1A_bit = 1)
#define  TIMER1_COMPARE_MATCH_UNIT_B_INTERRUPT_CLEAR_FALGE() (TIFRbits.OCF1B_bit = 1)
#define  TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE()        (TIFRbits.ICF1_bit = 1)

#define  Force_Output_Compare_For_Compare_Unit_A()          (TCCR1Abits.FOC1A_bit = 1)
#define  Force_Output_Compare_For_Compare_Unit_B()          (TCCR1Abits.FOC1A_bit = 1)

#define  INPUT_CAPTURE_NOISE_CANCELER_ENABLE()              (TCCR1Bbits.ICNC1_bit = 1)
#define  INPUT_CAPTURE_NOISE_CANCELER_DISABLE()             (TCCR1Bbits.ICNC1_bit = 0)

#define  INPUT_CAPTURE_SENSE_RISING_EDGE()                  (TCCR1Bbits.ICES1_bit = 1)
#define  INPUT_CAPTURE_SENSE_FALLING_EDGE()                 (TCCR1Bbits.ICES1_bit = 0)






/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    TIMER1_NORMAL_PORT_OPERATION = 0,
    TIMER1_TOGGLE_OC1_ON_COMPARE_MATCH,
    TIMER1_CLEAR_OC1_ON_COMPARE_MATCH, 
    TIMER1_SET_OC1_ON_COMPARE_MATCH
}timer1_compare_output_mode_t;

typedef enum{
    TIMER1_NORMAL_MODE = 0,
    TIMER1_PWM_PHASE_CORRECT_8_BIT,
    TIMER1_PWM_PHASE_CORRECT_9_BIT,   
    TIMER1_PWM_PHASE_CORRECT_10_BIT,        
    TIMER1_CTC_TOP_OCR1A,        
    TIMER1_FAST_PWM_8_BIT,        
    TIMER1_FAST_PWM_9_BIT,        
    TIMER1_FAST_PWM_10_BIT,        
    TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_ICR1,        
    TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_OCR1A,        
    TIMER1_PWM_PHASE_CORRECT_TOP_ICR1,
    TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A,        
    TIMER1_CTC_TOP_ICR1,
    TIMER1_FAST_PWM_TOP_ICR1 = 14,        
    TIMER1_FAST_PWM_TOP_OCR1A = 15
}timer1_waveform_generation_mode_t;


typedef enum{
    TIMER1_NO_CLOCK_SOURCE = 0,
    TIMER1_CLOCK_DIV_BY_1,
    TIMER1_CLOCK_DIV_BY_8, 
    TIMER1_CLOCK_DIV_BY_64,
    TIMER1_CLOCK_DIV_BY_256,
    TIMER1_CLOCK_DIV_BY_1024,
    TIMER1_EXTERNAL_CLOCK_FALLING_EDGE,        
    TIMER1_EXTERNAL_CLOCK_RISING_EDGE       
}timer1_clock_select_t;

typedef enum{
    INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_FALLING_EDGE = 0,
    INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_RISING_EDGE,        
    INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_FALLING_EDGE,
    INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_RISING_EDGE
}timer1_input_capture_t;

typedef struct{
    void (* TMR1_Over_FlowInterruptHandler)(void);
    void (* TMR1_Compare_Match_Unit_A_InterruptHandler)(void);
    void (* TMR1_Compare_Match_Unit_B_InterruptHandler)(void);
    void (* TMR1_Input_Capture_InterruptHandler)(void);
    uint16 preload;
    uint16 ocr_A;
    uint16 ocr_B;
    uint16 icr;
    timer1_compare_output_mode_t compare_output_uintA_mode;
    timer1_compare_output_mode_t compare_output_uintB_mode;
    timer1_waveform_generation_mode_t waveform_generation_mode;
    timer1_clock_select_t clock_select;
    timer1_input_capture_t input_capture_mode;
}timer1_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType Timer1_Init(const timer1_t *_timer);
Std_ReturnType Timer1_DeInit(const timer1_t *_timer);
Std_ReturnType Timer1_Write_Value(const timer1_t *_timer, uint16 _value);
Std_ReturnType Timer1_Read_Value(const timer1_t *_timer, uint16 *_value);
Std_ReturnType Timer1_Read_Input_Capture_Unit_Value(const timer1_t *_timer, uint16 *_value);
Std_ReturnType Timer1_Input_capture_Change_Sense_Edge(timer1_t *_timer, timer1_input_capture_t _icu_mode);


#endif	/* MCAL_TIMER1_H */

