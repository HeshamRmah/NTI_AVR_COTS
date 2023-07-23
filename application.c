/* 
 * File:   application.c
 * Author: Hesham
 *
 * Created on July 21, 2023, 6:56 PM
 */


#include "application.h"
#include "HAL_Layer/button/hal_button.h"

segment_t segment = {
.segment_active_pins0 = {.port = PORTA_INDEX, .pin = DIO_PIN3, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_active_pins1 = {.port = PORTA_INDEX, .pin = DIO_PIN2, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_active_pins2 = {.port = PORTB_INDEX, .pin = DIO_PIN5, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_active_pins3 = {.port = PORTB_INDEX, .pin = DIO_PIN6, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_data_pins0 = {.port = PORTB_INDEX, .pin = DIO_PIN0, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE},
.segment_data_pins1 = {.port = PORTB_INDEX, .pin = DIO_PIN1, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE},
.segment_data_pins2 = {.port = PORTB_INDEX, .pin = DIO_PIN2, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE},
.segment_data_pins3 = {.port = PORTB_INDEX, .pin = DIO_PIN3, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE}
};

int main() {
    
    //Std_ReturnType ret = E_OK;
    application_initialize();
    
    while(1){
        
        hal_seven_segement_write_one_digit(&segment, 1);
        //hal_seven_segement_write_two_digit(&segment, 11);
    }
    
    return (EXIT_SUCCESS);
}


Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    
    ret = hal_seven_segement_intialize(&segment);
    
    return ret;
}

