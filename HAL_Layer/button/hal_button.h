/* 
 * File:   hal_button.h
 * Author: Hesham
 *
 * Created on July 22, 2023, 1:21 PM
 */

#ifndef HAL_BUTTON_H
#define	HAL_BUTTON_H

/* Section : Includes */

#include "../../MCAL_Layer/DIO/mcal_dio.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/* Section: Function Declarations */

/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType hal_button_initialize(const button_t *btn);

/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
Std_ReturnType hal_button_read_state(const button_t *btn, button_state_t *btn_state);


#endif	/* HAL_BUTTON_H */

