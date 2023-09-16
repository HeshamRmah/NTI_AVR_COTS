/* 
 * File:   mcal_timer1.c
 * Author: Hesham
 *
 * Created on August 5, 2023, 9:18 AM
 */


#include "mcal_timer1.h"


static void (* TMR1_Over_FlowInterruptHandler)(void) = NULL;
static void (* TMR1_Compare_Match_Unit_A_InterruptHandler)(void) = NULL;
static void (* TMR1_Compare_Match_Unit_B_InterruptHandler)(void) = NULL;
static void (* TMR1_Input_Capture_InterruptHandler)(void) = NULL;

static volatile uint16 timer1_preload = ZERO_INIT;

static inline void Timer1_Clock_Config(const timer1_t *_timer);
static inline void Timer1_Compare_Output_Unit_A_Config(const timer1_t *_timer);
static inline void Timer1_Compare_Output_Unit_B_Config(const timer1_t *_timer);
static inline void Timer1_Set_Interrupt_Handler(const timer1_t *_timer);
static inline void Timer1_Waveform_Generation_Config(const timer1_t *_timer);
static inline void Timer1_Preload_Config(const timer1_t *_timer);
static inline void Timer1_OCR_A_Config(const timer1_t *_timer);
static inline void Timer1_OCR_B_Config(const timer1_t *_timer);
static inline void Timer1_Input_Capture_Config(const timer1_t *_timer);
static inline void Timer1_ICR1_Config(const timer1_t *_timer);


void __vector_6(void) __attribute__((signal , used));
void __vector_7(void) __attribute__((signal , used));
void __vector_8(void) __attribute__((signal , used));
void __vector_9(void) __attribute__((signal , used));

void __vector_6(void){
    /* Clear Interrupt Flag */
    TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE();
    if(TMR1_Input_Capture_InterruptHandler){ TMR1_Input_Capture_InterruptHandler(); }
    else{ /* Nothing */ }   
    
}
/*
void __vector_7(void){
    //Clear Interrupt Flag
    TIMER1_COMPARE_MATCH_UNIT_A_INTERRUPT_CLEAR_FALGE();
    if(TMR1_Compare_Match_Unit_A_InterruptHandler){ TMR1_Compare_Match_Unit_A_InterruptHandler(); }
    else{ }   
    
}
*/
void __vector_8(void){
    /* Clear Interrupt Flag */
    TIMER1_COMPARE_MATCH_UNIT_B_INTERRUPT_CLEAR_FALGE();
    if(TMR1_Compare_Match_Unit_B_InterruptHandler){ TMR1_Compare_Match_Unit_B_InterruptHandler(); }
    else{ /* Nothing */ }   
    
}

void __vector_9(void){
    /* Clear Interrupt Flag */
    TIMER1_OVERFLOW_INTERRUPT_CLEAR_FALGE();
    if(TMR1_Over_FlowInterruptHandler){ TMR1_Over_FlowInterruptHandler(); }
    else{ /* Nothing */ }   
    
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer1_Init(const timer1_t *_timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER1_DIABLE();
        
        Timer1_Waveform_Generation_Config(_timer);
        
        Timer1_Compare_Output_Unit_A_Config(_timer);
        
        Timer1_Compare_Output_Unit_B_Config(_timer);
        
        Timer1_Set_Interrupt_Handler(_timer);
        
        Timer1_Preload_Config(_timer);
        
        Timer1_OCR_A_Config(_timer);
        
        Timer1_OCR_B_Config(_timer);
        
        Timer1_ICR1_Config(_timer);
        
        Timer1_Input_Capture_Config(_timer);
        
        Timer1_Clock_Config(_timer);
        
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer1_DeInit(const timer1_t *_timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER1_DIABLE();
        TIMER1_OVERFLOW_INTERRUPT_DISABLE();
        TIMER1_COMPARE_MATCH_UNIT_A_INTERRUPT_DISABLE();
        TIMER1_COMPARE_MATCH_UNIT_B_INTERRUPT_DISABLE();
        TIMER1_INPUT_CAPTURE_INTERRUPT_DISABLE();
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer1_Write_Value(const timer1_t *_timer, uint16 _value){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TCNT1bits = _value;
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer1_Read_Value(const timer1_t *_timer, uint16 *_value){
    Std_ReturnType ret = E_OK;
    if((NULL == _timer) || (NULL == _value)){
        ret = E_NOT_OK;
    }
    else{
        *_value = TCNT1bits;
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer1_Read_Input_Capture_Unit_Value(const timer1_t *_timer, uint16 *_value){
    Std_ReturnType ret = E_OK;
    if((NULL == _timer) || (NULL == _value)){
        ret = E_NOT_OK;
    }
    else{
        *_value = ICR1bits;
    }
    return ret;
}

/**
 * 
 * @param _timer
 * @param _icu_mode
 * @return 
 */
Std_ReturnType Timer1_Input_capture_Change_Sense_Edge(timer1_t *_timer, timer1_input_capture_t _icu_mode){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        switch(_icu_mode){
        case INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_FALLING_EDGE:
            TCCR1Bbits.ICNC1_bit = 1;
            TCCR1Bbits.ICES1_bit = 0;
            TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE();
            _timer->input_capture_mode = INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_FALLING_EDGE;
            break;
        case INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_RISING_EDGE:
            TCCR1Bbits.ICNC1_bit = 1;
            TCCR1Bbits.ICES1_bit = 1;
            TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE();
            _timer->input_capture_mode = INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_RISING_EDGE;
            break;    
        case INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_FALLING_EDGE:
            TCCR1Bbits.ICNC1_bit = 0;
            TCCR1Bbits.ICES1_bit = 0;
            TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE();
            _timer->input_capture_mode = INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_FALLING_EDGE;
            break;    
        case INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_RISING_EDGE:
            TCCR1Bbits.ICNC1_bit = 0;
            TCCR1Bbits.ICES1_bit = 1;
            TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE();
            _timer->input_capture_mode = INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_RISING_EDGE;
            break;
        default:
            TCCR1Bbits.ICNC1_bit = 0;
            TCCR1Bbits.ICES1_bit = 0; 
            TIMER1_INPUT_CAPTURE_INTERRUPT_CLEAR_FALGE();
            _timer->input_capture_mode = INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_FALLING_EDGE;
        }
    }
    return ret;
}


static inline void Timer1_Clock_Config(const timer1_t *_timer){
    TCCR1Bbits.CS_bits = _timer->clock_select;
}

static inline void Timer1_Compare_Output_Unit_A_Config(const timer1_t *_timer){
    switch(_timer->waveform_generation_mode){
        case TIMER1_NORMAL_MODE:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;
        case TIMER1_PWM_PHASE_CORRECT_8_BIT:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_9_BIT:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_10_BIT:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;
        case TIMER1_CTC_TOP_OCR1A:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_FAST_PWM_8_BIT:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_FAST_PWM_9_BIT:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_FAST_PWM_10_BIT:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_ICR1:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_OCR1A:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_TOP_ICR1:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_CTC_TOP_ICR1:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;    
        case TIMER1_FAST_PWM_TOP_ICR1:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break;        
        case TIMER1_FAST_PWM_TOP_OCR1A:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;
            break; 
        default:
            TCCR1Abits.COM1A_bits = _timer->compare_output_uintA_mode;     
    }
}

static inline void Timer1_Compare_Output_Unit_B_Config(const timer1_t *_timer){
    switch(_timer->waveform_generation_mode){
        case TIMER1_NORMAL_MODE:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;
        case TIMER1_PWM_PHASE_CORRECT_8_BIT:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_9_BIT:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_10_BIT:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;
        case TIMER1_CTC_TOP_OCR1A:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_FAST_PWM_8_BIT:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_FAST_PWM_9_BIT:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_FAST_PWM_10_BIT:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_ICR1:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_OCR1A:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_TOP_ICR1:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_CTC_TOP_ICR1:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;    
        case TIMER1_FAST_PWM_TOP_ICR1:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break;        
        case TIMER1_FAST_PWM_TOP_OCR1A:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;
            break; 
        default:
            TCCR1Abits.COM1B_bits = _timer->compare_output_uintB_mode;     
    }
}

static inline void Timer1_Set_Interrupt_Handler(const timer1_t *_timer){
    if(_timer->TMR1_Over_FlowInterruptHandler){
        INTERRUPT_GlobalInterruptEnable();
        TIMER1_OVERFLOW_INTERRUPT_ENABLE();
        TMR1_Over_FlowInterruptHandler = _timer->TMR1_Over_FlowInterruptHandler;
    }
    else { /* DO NOTHING */}
    
    if(_timer->TMR1_Compare_Match_Unit_A_InterruptHandler){
        INTERRUPT_GlobalInterruptEnable();
        TIMER1_COMPARE_MATCH_UNIT_A_INTERRUPT_ENABLE();
        TMR1_Compare_Match_Unit_A_InterruptHandler = _timer->TMR1_Compare_Match_Unit_A_InterruptHandler;
    }
    else { /* DO NOTHING */}
    
    if(_timer->TMR1_Compare_Match_Unit_B_InterruptHandler){
        INTERRUPT_GlobalInterruptEnable();
        TIMER1_COMPARE_MATCH_UNIT_B_INTERRUPT_ENABLE();
        TMR1_Compare_Match_Unit_B_InterruptHandler = _timer->TMR1_Compare_Match_Unit_B_InterruptHandler;
    }
    else { /* DO NOTHING */}
    
    if(_timer->TMR1_Input_Capture_InterruptHandler){
        INTERRUPT_GlobalInterruptEnable();
        TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE();
        TMR1_Input_Capture_InterruptHandler = _timer->TMR1_Input_Capture_InterruptHandler;
    }
    else { /* DO NOTHING */}
}

static inline void Timer1_Waveform_Generation_Config(const timer1_t *_timer){
    switch(_timer->waveform_generation_mode){
        case TIMER1_NORMAL_MODE:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 0;
            break;
        case TIMER1_PWM_PHASE_CORRECT_8_BIT:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 0;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_9_BIT:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 0;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_10_BIT:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 0;
            break;
        case TIMER1_CTC_TOP_OCR1A:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 0;
            break;    
        case TIMER1_FAST_PWM_8_BIT:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 0;
            break;    
        case TIMER1_FAST_PWM_9_BIT:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 0;
            break;    
        case TIMER1_FAST_PWM_10_BIT:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 0;
            break;    
        case TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_ICR1:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 1;
            break;    
        case TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_OCR1A:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 1;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_TOP_ICR1:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 1;
            break;    
        case TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 1;
            break;    
        case TIMER1_CTC_TOP_ICR1:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 1;
            break;    
        case TIMER1_FAST_PWM_TOP_ICR1:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 1;
            break;        
        case TIMER1_FAST_PWM_TOP_OCR1A:
            TCCR1Abits.WGM10_bit = 1;
            TCCR1Abits.WGM11_bit = 1;
            TCCR1Bbits.WGM12_bit = 1;
            TCCR1Bbits.WGM13_bit = 1;
            break; 
        default:
            TCCR1Abits.WGM10_bit = 0;
            TCCR1Abits.WGM11_bit = 0;
            TCCR1Bbits.WGM12_bit = 0;
            TCCR1Bbits.WGM13_bit = 0; 
    }
}

static inline void Timer1_Preload_Config(const timer1_t *_timer){
    timer1_preload = _timer->preload;
}

static inline void Timer1_OCR_A_Config(const timer1_t *_timer){
    OCR1Abits = _timer->ocr_A;
}

static inline void Timer1_OCR_B_Config(const timer1_t *_timer){
    OCR1Bbits = _timer->ocr_B;
}

static inline void Timer1_ICR1_Config(const timer1_t *_timer){
    ICR1bits = _timer->icr;
}

static inline void Timer1_Input_Capture_Config(const timer1_t *_timer){
    switch(_timer->input_capture_mode){
        case INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_FALLING_EDGE:
            TCCR1Bbits.ICNC1_bit = 1;
            TCCR1Bbits.ICES1_bit = 0;
            break;
        case INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_RISING_EDGE:
            TCCR1Bbits.ICNC1_bit = 1;
            TCCR1Bbits.ICES1_bit = 1;
            break;    
        case INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_FALLING_EDGE:
            TCCR1Bbits.ICNC1_bit = 0;
            TCCR1Bbits.ICES1_bit = 0;
            break;    
        case INPUT_CAPTURE_UNIT_WITHOUT_NOISE_CANCELER_SENSE_RISING_EDGE:
            TCCR1Bbits.ICNC1_bit = 0;
            TCCR1Bbits.ICES1_bit = 1;
            break;
        default:
            TCCR1Bbits.ICNC1_bit = 0;
            TCCR1Bbits.ICES1_bit = 0;    
    }
}