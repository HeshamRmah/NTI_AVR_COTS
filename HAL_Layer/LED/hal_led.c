/* 
 * File:   hal_led.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 10:02 PM
 */

/* Section : Includes */
#include "hal_led.h"

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType hal_led_initialize(const led_t *led){
    Std_ReturnType ret = E_OK;
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {.port = led->port, 
                                .pin = led->pin, 
                                .direction = DIO_DIRECTION_OUTPUT, 
                                .logic = led->led_status, 
                                .pullup = PULL_UP_DISABLE};
        dio_pin_intialize(&pin_obj);
    }
    
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType hal_led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK;
     if(NULL == led){
         ret = E_NOT_OK;
     }
     else{
         pin_config_t pin_obj = { .port = led->port, .pin = led->pin, 
                                  .direction = DIO_DIRECTION_OUTPUT,.logic = led->led_status, 
                                   .pullup = PULL_UP_DISABLE };
         dio_pin_write_logic(&pin_obj, DIO_HIGH);
     }
    return ret;
    
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType hal_led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK;
     if(NULL == led){
         ret = E_NOT_OK;
     }
     else{
         pin_config_t pin_obj = { .port = led->port, .pin = led->pin, 
                                  .direction = DIO_DIRECTION_OUTPUT,.logic = led->led_status, 
                                   .pullup = PULL_UP_DISABLE};
         dio_pin_write_logic(&pin_obj, DIO_LOW);
     }
    return ret;
    
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType hal_led_turn_toggle(const led_t *led){
    Std_ReturnType ret = E_OK;
     if(NULL == led){
         ret = E_NOT_OK;
     }
     else{
         pin_config_t pin_obj = { .port = led->port, .pin = led->pin, 
                                  .direction = DIO_DIRECTION_OUTPUT,.logic = led->led_status, 
                                   .pullup = PULL_UP_DISABLE };
         dio_pin_toggle_logic(&pin_obj);
     }
    return ret;
    
}




