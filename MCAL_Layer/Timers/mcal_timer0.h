/* 
 * File:   mcal_timer0.h
 * Author: Hesham
 *
 * Created on August 4, 2023, 10:54 AM
 */

#ifndef MCAL_TIMER0_H
#define	MCAL_TIMER0_H

/* ----------------- Includes -----------------*/
#include "timers_reg_cfg.h"
#include "../mcal_std_types.h"
#include "../Interrupt/interrupt_config.h"
#include "../DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/
#define  TIMER0_OVERFLOW_INTERRUPT_ENABLE()                 (TIMSKbits.TOIE0_bit = 1)
#define  TIMER0_OVERFLOW_INTERRUPT_DISABLE()                (TIMSKbits.TOIE0_bit = 0)

#define  TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE()            (TIMSKbits.OCIE0_bit = 1)
#define  TIMER0_COMPARE_MATCH_INTERRUPT_DISABLE()           (TIMSKbits.OCIE0_bit = 0)

#define TIMER0_DIABLE()                                     (TCCR0bits.CS_bits = 0)

#define  TIMER0_OVERFLOW_INTERRUPT_CLEAR_FALGE()            (TIFRbits.TOV0_bit = 1)
#define  TIMER0_COMPARE_MATCH_INTERRUPT_CLEAR_FALGE()       (TIFRbits.OCF0_bit = 1)

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    NORMAL_MODE = 0,
    PWM_PHASE_CORRECT_MODE,
    CTC_MODE, 
    FAST_PWM
}waveform_generation_mode_t;

typedef enum{
    NORMAL_PORT_OPERATION = 0,
    TOGGLE_OC0_ON_COMPARE_MATCH,
    CLEAR_OC0_ON_COMPARE_MATCH, 
    SET_OC0_ON_COMPARE_MATCH
}compare_output_mode_t;

typedef enum{
    NO_CLOCK_SOURCE = 0,
    CLOCK_DIV_BY_1,
    CLOCK_DIV_BY_8, 
    CLOCK_DIV_BY_64,
    CLOCK_DIV_BY_256,
    CLOCK_DIV_BY_1024,
    EXTERNAL_CLOCK_FALLING_EDGE,        
    EXTERNAL_CLOCK_RISING_EDGE       
}clock_select_t;


typedef struct{
    void (* TMR0_Over_FlowInterruptHandler)(void);
    void (*TMR0_Compare_Match_InterruptHandler)(void);
    waveform_generation_mode_t waveform_generation_mode;
    compare_output_mode_t compare_output_mode;
    clock_select_t clock_select;
    uint8 preload;
    uint8 ocr;
}timer0_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType Timer0_Init(const timer0_t *_timer);
Std_ReturnType Timer0_DeInit(const timer0_t *_timer);
Std_ReturnType Timer0_Write_Value(const timer0_t *_timer, uint8 _value);
Std_ReturnType Timer0_Read_Value(const timer0_t *_timer, uint8 *_value);

#endif	/* MCAL_TIMER0_H */

