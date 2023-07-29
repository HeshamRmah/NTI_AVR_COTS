
#include <stdio.h>

#include "ADC.h"
#include "ADC_config.h"
#include "ADC_priv.h"
#include "../mcal_std_types.h"
#include "../DIO/mcal_dio.h"





void ADC_voidInit (void){

    /*set AVCC with external capacitor at AREF pin*/
    SET_BIT(ADMUX, 6);
    CLEAR_BIT(ADMUX, 7);
    
    /*Analog Channel and Gain Selection Bits*/
    SET_BIT(ADMUX, 0);
    CLEAR_BIT(ADMUX, 1);
    CLEAR_BIT(ADMUX, 2);
    CLEAR_BIT(ADMUX, 3);
    CLEAR_BIT(ADMUX, 4);
    
    /*LEFT_ADJUSTMENT*/
    CLEAR_BIT(ADMUX, 5);
    
    ADC_voidDisable();
    
    /*disable ADC Auto Trigger*/
    CLEAR_BIT(ADCSRA, 5);
    
    /** ADC Interrupt Flag ( Conversion Complete ) cleared by SW **/
    CLEAR_BIT(ADCSRA, 4);
    
    /** ADC Interrupt Enable is cleared in initialization	   **/
    CLEAR_BIT(ADCSRA, 3);
    
    
    //ADC_PRESCALLER
    CLEAR_BIT(ADCSRA, 0);
    SET_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 2);
    
}


void ADC_voidEnable(){
    SET_BIT(ADCSRA, 7);
    
}

void ADC_voidDisable(){
    CLEAR_BIT(ADCSRA, 7);
}

void ADC_voidStartConversion(){
    SET_BIT(ADCSRA ,6);
}

void ADC_voidInterrputEnable(){
    SET_BIT(ADCSRA ,3);
}

void ADC_voidAutoTrigger(){
    SET_BIT(ADCSRA ,5);
}

uint16 ADC_u16ReadADCInMV(){
    uint16 value = 0;
    ADC_voidStartConversion();
    
    while(GET_BIT(ADCSRA, 4) != 1){
        
    }
    value = ADC_u16_ADC_REG;
    SET_BIT(ADCSRA, 4);
    
    return value; 
}