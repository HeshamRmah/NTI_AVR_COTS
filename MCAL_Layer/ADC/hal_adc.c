/* 
 * File:   hal_adc.c
 * Author: Hesham
 *
 * Created on August 1, 2023, 9:10 PM
 */

#include "hal_adc.h"

static void (*ADC_InterruptHandler)(void) = NULL;

static inline void adc_input_channel_and_gain_selections_config(const adc_t *_adc);
static inline void select_result_format(const adc_t *_adc);
static inline void configure_voltage_reference(const adc_t *_adc);
static inline void configure_adc_prescaler(const adc_t *_adc);
static inline void configure_adc_auto_trigger(const adc_t *_adc);
static inline void configure_adc_converstion_alert(const adc_t *_adc);
static inline void configure_adc_interrupt_call_back(const adc_t *_adc);

void ADC_ISR(void);


void __vector_16(void) __attribute__((signal , used));

void __vector_16(void){
    ADC_INTERRUPT_CLEAR_FLAG();
    if(ADC_InterruptHandler){ ADC_InterruptHandler(); }
    else{ /* Nothing */ }
}

/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_Init(const adc_t *_adc){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        /*  */
        ADC_Disable();
        /*  */
        adc_input_channel_and_gain_selections_config(_adc);
        
        /*  */
        select_result_format(_adc);
        
        /*  */
        configure_voltage_reference(_adc);
        
        /*   */
        configure_adc_prescaler(_adc);
                
        /*  */
        configure_adc_auto_trigger(_adc);
        
        /*   */
        configure_adc_converstion_alert(_adc);
        /*  */
        configure_adc_interrupt_call_back(_adc);
        /*  */
        ADC_INTERRUPT_CLEAR_FLAG();
        
        /*  */
        ADC_Enable();        
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_DeInit(const adc_t *_adc){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        ADC_Disable();
        
        ADC_INTERRUPT_DISABLE();
    }
    return ret;
}


/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_StartConversion(const adc_t *_adc){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        ADC_Start_Conversion();
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param conversion_status
 * @return 
 */
Std_ReturnType ADC_IsConversionDone(const adc_t *_adc, uint8 *conversion_status){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        *conversion_status = ADC_Get_Conversion_Status();
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param conversion_result
 * @return 
 */
Std_ReturnType ADC_GetConversionResult(const adc_t *_adc, adc_result_t *conversion_result){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        switch(_adc->result_adjust){
            case ADC_RESULT_RIGHT_ADJUST:
                *conversion_result = (adc_result_t)(ADCLbits + (ADCHbits << 8));
                break;
            case ADC_RESULT_LEFT_ADJUST:
                *conversion_result = (adc_result_t)((ADCLbits >> 6) + (ADCHbits << 2));
                break;
            default:
                *conversion_result = (adc_result_t)((ADCHbits << 8) + ADCLbits);
        }
        
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @param conversion_result
 * @return 
 */
Std_ReturnType ADC_GetConversion_Polling(const adc_t *_adc, adc_result_t *conversion_result){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        adc_input_channel_and_gain_selections_config(_adc);
        ret = ADC_StartConversion(_adc);
        while(!ADC_Get_Conversion_Status());
        ret = ADC_GetConversionResult(_adc, conversion_result);
        ADC_INTERRUPT_CLEAR_FLAG();
    }
    return ret;
}

/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_StartConversion_Interrupt(const adc_t *_adc){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else{
        ADC_INTERRUPT_CLEAR_FLAG();
        
        ret = ADC_StartConversion(_adc);
    }
    return ret;
}


static inline void adc_input_channel_and_gain_selections_config(const adc_t *_adc){
    switch(_adc->channel_gain){
        case ADC_INPUT_ADC0 : ADMUXbits.MUX_bits = ADC_INPUT_ADC0; break;
        case ADC_INPUT_ADC1 : ADMUXbits.MUX_bits = ADC_INPUT_ADC1; break;
        case ADC_INPUT_ADC2 : ADMUXbits.MUX_bits = ADC_INPUT_ADC2; break;
        case ADC_INPUT_ADC3 : ADMUXbits.MUX_bits = ADC_INPUT_ADC3; break;
        case ADC_INPUT_ADC4 : ADMUXbits.MUX_bits = ADC_INPUT_ADC4; break;
        case ADC_INPUT_ADC5 : ADMUXbits.MUX_bits = ADC_INPUT_ADC5; break;
        case ADC_INPUT_ADC6 : ADMUXbits.MUX_bits = ADC_INPUT_ADC6; break;
        case ADC_INPUT_ADC7 : ADMUXbits.MUX_bits = ADC_INPUT_ADC7; break;
        case ADC_DIFFERENTIAL_ADC0_ADC0_10X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC0_ADC0_10X; break;
        case ADC_DIFFERENTIAL_ADC1_ADC0_10X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC1_ADC0_10X; break;
        case ADC_DIFFERENTIAL_ADC0_ADC0_200X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC0_ADC0_200X; break;
        case ADC_DIFFERENTIAL_ADC1_ADC0_200X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC1_ADC0_200X; break;
        case ADC_DIFFERENTIAL_ADC2_ADC2_10X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC2_ADC2_10X; break;
        case ADC_DIFFERENTIAL_ADC3_ADC2_10X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC3_ADC2_10X; break;
        case ADC_DIFFERENTIAL_ADC2_ADC2_200X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC2_ADC2_200X; break;
        case ADC_DIFFERENTIAL_ADC3_ADC2_200X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC3_ADC2_200X; break;
        case ADC_DIFFERENTIAL_ADC0_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC0_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC1_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC1_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC2_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC2_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC3_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC3_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC4_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC4_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC5_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC5_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC6_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC6_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC7_ADC1_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC7_ADC1_1X; break;
        case ADC_DIFFERENTIAL_ADC0_ADC2_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC0_ADC2_1X; break;
        case ADC_DIFFERENTIAL_ADC1_ADC2_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC1_ADC2_1X; break;
        case ADC_DIFFERENTIAL_ADC2_ADC2_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC2_ADC2_1X; break;
        case ADC_DIFFERENTIAL_ADC3_ADC2_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC3_ADC2_1X; break;
        case ADC_DIFFERENTIAL_ADC4_ADC2_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC4_ADC2_1X; break;
        case ADC_DIFFERENTIAL_ADC5_ADC2_1X : ADMUXbits.MUX_bits = ADC_DIFFERENTIAL_ADC5_ADC2_1X; break;
        case ADC_VGB : ADMUXbits.MUX_bits = ADC_VGB; break;
        case ADC_GROUND : ADMUXbits.MUX_bits = ADC_GROUND; break;
        default : /* Nothing */;
    }
}

static inline void select_result_format(const adc_t *_adc){
    if(ADC_RESULT_RIGHT_ADJUST == _adc->result_adjust){
        ADC_SET_RESULT_RIGHT_ADJUST();
    }
    else if(ADC_RESULT_LEFT_ADJUST == _adc->result_adjust){
        ADC_SET_RESULT_LEFT_ADJUST();
    }
    else{
        ADC_SET_RESULT_RIGHT_ADJUST();
    }
}


static inline void configure_voltage_reference(const adc_t *_adc){
    switch(_adc->reference){
        case AREF_EXTERNAL_REFERENCE_VOLTAGE:
            ADMUXbits.REFS_bits = AREF_EXTERNAL_REFERENCE_VOLTAGE;
            break;
        case AVCC_WITH_EXTERNAL_CAPACITOR:
            ADMUXbits.REFS_bits = AVCC_WITH_EXTERNAL_CAPACITOR;
            break;
        case INTERNAL_VOLTAGE_REFERENCE:
            ADMUXbits.REFS_bits = INTERNAL_VOLTAGE_REFERENCE;
            break;
        default:
            ADMUXbits.REFS_bits = AREF_EXTERNAL_REFERENCE_VOLTAGE;
    }
}

/**
 * 
 * @param _adc
 */
static inline void configure_adc_prescaler(const adc_t *_adc){
    switch(_adc->prescaler){
        case ADC_PRESCALER_DIV_2:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_2; break;
        case ADC_PRESCALER_DIV_4:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_4; break;
        case ADC_PRESCALER_DIV_8:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_8; break;
        case ADC_PRESCALER_DIV_16:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_16; break;
        case ADC_PRESCALER_DIV_32:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_32; break;
        case ADC_PRESCALER_DIV_64:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_64; break;
        case ADC_PRESCALER_DIV_128:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_128; break;
        default:
            ADCSRAbits.ADPS_bits = ADC_PRESCALER_DIV_2;
    }
}


/**
 * 
 * @param _adc
 */
static inline void configure_adc_auto_trigger(const adc_t *_adc){
    switch(_adc->trigger_scr){
        case DISABLE_AUTO_TRIGGER:
            ADC_Auto_Trigger_Disable(); 
            break;
        case FREE_RUNNING_MODE:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = FREE_RUNNING_MODE; 
            break;
        case ANALOG_COMPARATOR:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = ANALOG_COMPARATOR; 
            break;    
        case EXTERNAL_INTERRUPT_INT0:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = EXTERNAL_INTERRUPT_INT0; 
            break;    
        case TIMER0_COMPARE_MATCH:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = TIMER0_COMPARE_MATCH; 
            break;    
        case TIMER0_COMPARE_OVERFLOW:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = TIMER0_COMPARE_OVERFLOW; 
            break;    
        case TIMER1_COMPARE_MATCH:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = TIMER1_COMPARE_MATCH; 
            break;    
        case TIMER1_COMPARE_OVERFLOW:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = TIMER1_COMPARE_OVERFLOW; 
            break; 
        case TIMER1_CAPTURE_EVENT:
            ADC_Auto_Trigger_Enable();
            SFIORbits.ADTS_bits = TIMER1_CAPTURE_EVENT; 
            break;          
        default:
            ADC_Auto_Trigger_Disable();
    }
}

/**
 * 
 * @param _adc
 */
static inline void configure_adc_converstion_alert(const adc_t *_adc){
    switch(_adc->convertion_alert){
        case ADC_CONVERSTION_COMPLETE_POLLING:
            ADC_INTERRUPT_DISABLE();
            break;
        case ADC_CONVERSTION_COMPLETE_INTERRUPT:
            //INTERRUPT_GlobalInterruptEnable();
            ADC_INTERRUPT_ENABLE();
            break;
        default:
            ADC_INTERRUPT_DISABLE();
    }
}

static inline void configure_adc_interrupt_call_back(const adc_t *_adc){
   ADC_InterruptHandler = _adc->ADC_InterruptHandler;
}