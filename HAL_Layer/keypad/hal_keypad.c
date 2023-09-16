/* 
 * File:   hal_keypad.c
 * Author: Hesham
 *
 * Created on July 24, 2023, 10:33 AM
 */


#include "hal_keypad.h"


static const uint8 btn_values[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'#', '0', '=', '+'}
                                                                     };

/**
 * 
 * @param _keypad_obj
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj){
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
    if(NULL == _keypad_obj){
        ret = E_NOT_OK;
    }
    else{    
        for(rows_counter = ZERO_INIT; rows_counter < KEYPAD_ROWS; rows_counter++){
            ret = dio_pin_intialize(&(_keypad_obj->keypad_row_pins[rows_counter]));
        }
        for(columns_counter = ZERO_INIT; columns_counter < KEYPAD_COLUMNS; columns_counter++){
            ret = dio_pin_direction_intialize(&(_keypad_obj->keypad_columns_pins[columns_counter]));
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad_obj
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT;
    uint8 columns_counter = ZERO_INIT;
    uint8 counter = ZERO_INIT;
    uint8 column_logic = ZERO_INIT;
    *value = NO_KEY;
    //uint8 debouncing_check = ZERO_INIT;
    if((NULL == _keypad_obj) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{    
        for(rows_counter=ZERO_INIT; rows_counter<KEYPAD_ROWS; rows_counter++){
            for(counter=ZERO_INIT; counter<KEYPAD_ROWS; counter++){
                ret = dio_pin_write_logic(&(_keypad_obj->keypad_row_pins[counter]), DIO_HIGH);
            }
            ret = dio_pin_write_logic(&(_keypad_obj->keypad_row_pins[rows_counter]), DIO_LOW);
            //_delay_ms(10);
            for(columns_counter=ZERO_INIT; columns_counter<KEYPAD_COLUMNS; columns_counter++){
                ret = dio_pin_read_logic(&(_keypad_obj->keypad_columns_pins[columns_counter]), &column_logic);
                if(DIO_LOW == column_logic){
                    while (DIO_LOW == column_logic){
                        ret = dio_pin_read_logic(&(_keypad_obj->keypad_columns_pins[columns_counter]), &column_logic);
                    }
                    *value = btn_values[rows_counter][columns_counter];
                }
                else{
                    
                }
            }
        }
          
    }
    return ret;
}
    