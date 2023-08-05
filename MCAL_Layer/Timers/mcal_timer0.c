/* 
 * File:   mcal_timer0.c
 * Author: Hesham
 *
 * Created on August 4, 2023, 10:54 AM
 */


#include "mcal_timer0.h"

static void (*TMR0_Over_FlowInterruptHandler)(void) = NULL;
static void (*TMR0_Compare_Match_InterruptHandler)(void) = NULL;

static uint8 timer0_preload = ZERO_INIT;
//static uint8 timer0_ocr = ZERO_INIT;
volatile uint16 counter = 0;

static inline void Timer0_Clock_Config(const timer0_t *_timer);
static inline void Timer0_Compare_Output_Config(const timer0_t *_timer);
static inline void Timer0_Set_Interrupt_Handler(const timer0_t *_timer);
static inline void Timer0_Waveform_Generation_Config(const timer0_t *_timer);
static inline void Timer0_Preload_Config(const timer0_t *_timer);
static inline void Timer0_OCR_Config(const timer0_t *_timer);

void __vector_10(void) __attribute__((signal , used));
void __vector_11(void) __attribute__((signal , used));

void __vector_10(void){
    /* Clear Interrupt Flag */
    TIMER0_COMPARE_MATCH_INTERRUPT_CLEAR_FALGE();
    counter++;
    if(counter == 4000){
        counter = 0;
        if(TMR0_Compare_Match_InterruptHandler){ TMR0_Compare_Match_InterruptHandler(); }
    }
    else{ /* Nothing */ }   
    
}

void __vector_11(void){
    /* Clear Interrupt Flag */
    TIMER0_OVERFLOW_INTERRUPT_CLEAR_FALGE();
    counter++;
    if(counter == 4000){
        counter = 0;
        TCNT0bits = timer0_preload;
        if(TMR0_Over_FlowInterruptHandler){ TMR0_Over_FlowInterruptHandler(); }
    }    
    else{ /* Nothing */ }
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer0_Init(const timer0_t *_timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_DIABLE();
        
        Timer0_Compare_Output_Config(_timer);
        
        Timer0_Set_Interrupt_Handler(_timer);
        
        Timer0_Waveform_Generation_Config(_timer);
        
        Timer0_Preload_Config(_timer);
        
        Timer0_OCR_Config(_timer);
        
        Timer0_Clock_Config(_timer);
        
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer0_DeInit(const timer0_t *_timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_DIABLE();
        TIMER0_OVERFLOW_INTERRUPT_DISABLE();
        TIMER0_COMPARE_MATCH_INTERRUPT_DISABLE();
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer0_Write_Value(const timer0_t *_timer, uint8 _value){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TCNT0bits = _value;
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer0_Read_Value(const timer0_t *_timer, uint8 *_value){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        *_value = TCNT0bits;
    }
    return ret;
}

static inline void Timer0_Clock_Config(const timer0_t *_timer){
    TCCR0bits.CS_bits = _timer->clock_select;
}

static inline void Timer0_Compare_Output_Config(const timer0_t *_timer){
    switch(_timer->waveform_generation_mode){
        case NORMAL_MODE:
            TCCR0bits.COM_bits = _timer->compare_output_mode;
            break;
        case PWM_PHASE_CORRECT_MODE:
            TCCR0bits.COM_bits = _timer->compare_output_mode;
            break;    
        case CTC_MODE:
            TCCR0bits.COM_bits = _timer->compare_output_mode;
            break;    
        case FAST_PWM:
            TCCR0bits.COM_bits = _timer->compare_output_mode;
            break;
        default:
            TCCR0bits.COM_bits = _timer->compare_output_mode;     
    }
}

static inline void Timer0_Set_Interrupt_Handler(const timer0_t *_timer){
    if(_timer->TMR0_Over_FlowInterruptHandler){
        INTERRUPT_GlobalInterruptEnable();
        TIMER0_OVERFLOW_INTERRUPT_ENABLE();
        TMR0_Over_FlowInterruptHandler = _timer->TMR0_Over_FlowInterruptHandler;
    }
    else if(_timer->TMR0_Compare_Match_InterruptHandler){
        INTERRUPT_GlobalInterruptEnable();
        TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE();
        TMR0_Compare_Match_InterruptHandler = _timer->TMR0_Compare_Match_InterruptHandler;
    }
    else { /* DO NOTHING */}
}

static inline void Timer0_Waveform_Generation_Config(const timer0_t *_timer){
    switch(_timer->waveform_generation_mode){
        case NORMAL_MODE:
            TCCR0bits.WGM00_bit = 0;
            TCCR0bits.WGM01_bit = 0;
            break;
        case PWM_PHASE_CORRECT_MODE:
            TCCR0bits.WGM00_bit = 1;
            TCCR0bits.WGM01_bit = 0;
            break;    
        case CTC_MODE:
            TCCR0bits.WGM00_bit = 0;
            TCCR0bits.WGM01_bit = 1;
            break;    
        case FAST_PWM:
            TCCR0bits.WGM00_bit = 1;
            TCCR0bits.WGM01_bit = 1;
            break;
        default:
            TCCR0bits.WGM00_bit = 0;
            TCCR0bits.WGM01_bit = 0;    
    }
}

static inline void Timer0_Preload_Config(const timer0_t *_timer){
    timer0_preload = _timer->preload;
}

static inline void Timer0_OCR_Config(const timer0_t *_timer){
    OCR0bits = _timer->ocr;
}
