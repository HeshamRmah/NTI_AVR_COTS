/* 
 * File:   hal_button.h
 * Author: Hesham
 *
 * Created on July 22, 2023, 1:21 PM
 */

#include "hal_button.h"

/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType hal_button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;
    if(NULL == btn){
        ret = E_NOT_OK;
    }
    else{
        ret = dio_pin_direction_intialize(&(btn->button_pin));
    }
    return ret;
}

/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
Std_ReturnType hal_button_read_state(const button_t *btn, button_state_t *btn_state){
    Std_ReturnType ret = E_NOT_OK;
    logic_t Pin_Logic_Status = DIO_LOW;
    if((NULL == btn) || (NULL == btn_state)){
        ret = E_NOT_OK;
    }
    else{
        dio_pin_read_logic(&(btn->button_pin), &Pin_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            if(DIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection){
            if(DIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else { /* Nothing */ }
        ret = E_OK;
    }
    return ret;
}