/* 
 * File:   hal_adc.h
 * Author: Hesham
 *
 * Created on August 1, 2023, 9:10 PM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* ----------------- Includes -----------------*/
#include "adc_reg_cfg.h"
#include "../mcal_std_types.h"
#include "../DIO/mcal_dio.h"
/***/
#include "../../MCAL_Layer/Interrupt/interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/
#define ADC_Enable()                        (ADCSRAbits.ADEN_bit = 1)
#define ADC_Disable()                       (ADCSRAbits.ADEN_bit = 0)

#define ADC_Start_Conversion()              (ADCSRAbits.ADSC_bit = 1)

#define ADC_Auto_Trigger_Enable()           (ADCSRAbits.ADATE_bit = 1)
#define ADC_Auto_Trigger_Disable()          (ADCSRAbits.ADATE_bit = 0)

#define ADC_INTERRUPT_CLEAR_FLAG()          (ADCSRAbits.ADIF_bit = 1)
#define ADC_Get_INTERRUPT_FLAG()            (ADCSRAbits.ADIF_bit)
#define ADC_Get_Conversion_Status()         (ADCSRAbits.ADIF_bit)

#define ADC_INTERRUPT_ENABLE()              (ADCSRAbits.ADIE_bit = 1)
#define ADC_INTERRUPT_DISABLE()             (ADCSRAbits.ADIE_bit = 0)

#define ADC_SET_RESULT_LEFT_ADJUST()        (ADMUXbits.ADLAR_bit = 1)
#define ADC_SET_RESULT_RIGHT_ADJUST()       (ADMUXbits.ADLAR_bit = 0)


/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    AREF_EXTERNAL_REFERENCE_VOLTAGE = 0,
    AVCC_WITH_EXTERNAL_CAPACITOR  = 1,
    INTERNAL_VOLTAGE_REFERENCE = 3
}reference_selection_t;

typedef enum{
    ADC_RESULT_RIGHT_ADJUST = 0,
    ADC_RESULT_LEFT_ADJUST
}result_adjust_t;

typedef enum{
    ADC_INPUT_ADC0 = 0,
    ADC_INPUT_ADC1,
    ADC_INPUT_ADC2,
    ADC_INPUT_ADC3,
    ADC_INPUT_ADC4,
    ADC_INPUT_ADC5,
    ADC_INPUT_ADC6,
    ADC_INPUT_ADC7,
    ADC_DIFFERENTIAL_ADC0_ADC0_10X,
    ADC_DIFFERENTIAL_ADC1_ADC0_10X,
    ADC_DIFFERENTIAL_ADC0_ADC0_200X,        
    ADC_DIFFERENTIAL_ADC1_ADC0_200X,  
    ADC_DIFFERENTIAL_ADC2_ADC2_10X,        
    ADC_DIFFERENTIAL_ADC3_ADC2_10X,         
    ADC_DIFFERENTIAL_ADC2_ADC2_200X,        
    ADC_DIFFERENTIAL_ADC3_ADC2_200X,        
    ADC_DIFFERENTIAL_ADC0_ADC1_1X, 
    ADC_DIFFERENTIAL_ADC1_ADC1_1X,         
    ADC_DIFFERENTIAL_ADC2_ADC1_1X,         
    ADC_DIFFERENTIAL_ADC3_ADC1_1X,         
    ADC_DIFFERENTIAL_ADC4_ADC1_1X,         
    ADC_DIFFERENTIAL_ADC5_ADC1_1X,         
    ADC_DIFFERENTIAL_ADC6_ADC1_1X,         
    ADC_DIFFERENTIAL_ADC7_ADC1_1X,                 
    ADC_DIFFERENTIAL_ADC0_ADC2_1X,         
    ADC_DIFFERENTIAL_ADC1_ADC2_1X,         
    ADC_DIFFERENTIAL_ADC2_ADC2_1X, 
    ADC_DIFFERENTIAL_ADC3_ADC2_1X,         
    ADC_DIFFERENTIAL_ADC4_ADC2_1X,        
    ADC_DIFFERENTIAL_ADC5_ADC2_1X, 
    ADC_VGB,        
    ADC_GROUND      
}input_Channel_and_gain_selections_t;

typedef enum{
    ADC_PRESCALER_DIV_2 = 1,
    ADC_PRESCALER_DIV_4,        
    ADC_PRESCALER_DIV_8,        
    ADC_PRESCALER_DIV_16,        
    ADC_PRESCALER_DIV_32,        
    ADC_PRESCALER_DIV_64,        
    ADC_PRESCALER_DIV_128,        
}adc_prescaler_select_t;


typedef enum{
    FREE_RUNNING_MODE = 0,
    ANALOG_COMPARATOR,        
    EXTERNAL_INTERRUPT_INT0,        
    TIMER0_COMPARE_MATCH,        
    TIMER0_COMPARE_OVERFLOW,         
    TIMER1_COMPARE_MATCH,        
    TIMER1_COMPARE_OVERFLOW,
    TIMER1_CAPTURE_EVENT,
    DISABLE_AUTO_TRIGGER
}adc_auto_trigger_source_t;

typedef enum{
    ADC_CONVERSTION_COMPLETE_POLLING = 0,
    ADC_CONVERSTION_COMPLETE_INTERRUPT
}adc_converstion_alert_t;

typedef struct{
    void (* ADC_InterruptHandler)(void);
    pin_config_t pin_obj;
    reference_selection_t reference;
    input_Channel_and_gain_selections_t channel_gain;
    adc_prescaler_select_t prescaler;
    result_adjust_t result_adjust;
    adc_auto_trigger_source_t trigger_scr;
    adc_converstion_alert_t convertion_alert;
}adc_t;

typedef uint16 adc_result_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType ADC_Init(const adc_t *_adc);
Std_ReturnType ADC_DeInit(const adc_t *_adc);
Std_ReturnType ADC_StartConversion(const adc_t *_adc);
Std_ReturnType ADC_IsConversionDone(const adc_t *_adc, uint8 *conversion_status);
Std_ReturnType ADC_GetConversionResult(const adc_t *_adc, adc_result_t *conversion_result);
Std_ReturnType ADC_GetConversion_Polling(const adc_t *_adc, adc_result_t *conversion_result);
Std_ReturnType ADC_StartConversion_Interrupt(const adc_t *_adc);


#endif	/* HAL_ADC_H */

