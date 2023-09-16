/* 
 * File:   hal_keypad.h
 * Author: Hesham
 *
 * Created on July 24, 2023, 10:33 AM
 */

#ifndef HAL_KEYPAD_H
#define	HAL_KEYPAD_H

/* ----------------- Includes -----------------*/

#include "../../MCAL_Layer/DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/
#define KEYPAD_ROWS    4
#define KEYPAD_COLUMNS 4
#define NO_KEY         127

/* ----------------- Macro Functions Declarations -----------------*/

typedef struct{
    pin_config_t keypad_row_pins[KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[KEYPAD_COLUMNS];
}keypad_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);

#endif	/* HAL_KEYPAD_H */

