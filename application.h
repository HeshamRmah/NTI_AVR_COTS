/* 
 * File:   application.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 7:18 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "MCAL_Layer/std_libraries.h"
#include "MCAL_Layer/DIO/mcal_dio.h"
#include "HAL_Layer/LED/hal_led.h"
#include "HAL_Layer/button/hal_button.h"
#include "HAL_Layer/7_Segment/hal_seven_segment.h"
#include "HAL_Layer/LCD/hal_lcd.h"
#include "HAL_Layer/keypad/hal_keypad.h"
//#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include "MCAL_Layer/ADC/ADC.h"


Std_ReturnType application_initialize(void);

chr_lcd_4bit_t lcd = {
    .lcd_rs.port = PORTA_INDEX,
    .lcd_rs.pin = DIO_PIN3,
    .lcd_rs.direction = DIO_DIRECTION_OUTPUT,
    .lcd_rs.logic = DIO_LOW,
    .lcd_rs.pullup = PULL_UP_DISABLE,
    
    .lcd_en.port = PORTA_INDEX,
    .lcd_en.pin = DIO_PIN2,
    .lcd_en.direction = DIO_DIRECTION_OUTPUT,
    .lcd_en.logic = DIO_LOW,
    .lcd_en.pullup = PULL_UP_DISABLE,
    
    .lcd_data[0].port = PORTB_INDEX,
    .lcd_data[0].pin = DIO_PIN0,
    .lcd_data[0].direction = DIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = DIO_LOW,
    .lcd_data[0].pullup = PULL_UP_DISABLE,
    
    .lcd_data[1].port = PORTB_INDEX,
    .lcd_data[1].pin = DIO_PIN1,
    .lcd_data[1].direction = DIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = DIO_LOW,
    .lcd_data[1].pullup = PULL_UP_DISABLE,
    
    .lcd_data[2].port = PORTB_INDEX,
    .lcd_data[2].pin = DIO_PIN2,
    .lcd_data[2].direction = DIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = DIO_LOW,
    .lcd_data[2].pullup = PULL_UP_DISABLE,
    
    .lcd_data[3].port = PORTB_INDEX,
    .lcd_data[3].pin = DIO_PIN4,
    .lcd_data[3].direction = DIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = DIO_LOW,
    .lcd_data[3].pullup = PULL_UP_DISABLE,
    
};

led_t led1 = {
    .port = PORTA_INDEX,
    .pin = DIO_PIN5,
    .led_status = DIO_LOW
};

segment_t segment = {
.segment_active_pins0 = {.port = PORTA_INDEX, .pin = DIO_PIN3, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_active_pins1 = {.port = PORTA_INDEX, .pin = DIO_PIN2, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_active_pins2 = {.port = PORTB_INDEX, .pin = DIO_PIN5, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_active_pins3 = {.port = PORTB_INDEX, .pin = DIO_PIN6, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_HIGH, .pullup = PULL_UP_DISABLE},
.segment_data_pins0 = {.port = PORTB_INDEX, .pin = DIO_PIN0, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE},
.segment_data_pins1 = {.port = PORTB_INDEX, .pin = DIO_PIN1, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE},
.segment_data_pins2 = {.port = PORTB_INDEX, .pin = DIO_PIN2, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE},
.segment_data_pins3 = {.port = PORTB_INDEX, .pin = DIO_PIN4, .direction = DIO_DIRECTION_OUTPUT, .logic = DIO_LOW, .pullup = PULL_UP_DISABLE}
};


keypad_t keypad = {
    
    .keypad_row_pins[0].port = PORTC_INDEX,
    .keypad_row_pins[0].pin = DIO_PIN5,
    .keypad_row_pins[0].direction = DIO_DIRECTION_OUTPUT,
    .keypad_row_pins[0].logic = DIO_HIGH,
    .keypad_row_pins[0].pullup = PULL_UP_DISABLE,
    
    .keypad_row_pins[1].port = PORTC_INDEX,
    .keypad_row_pins[1].pin = DIO_PIN4,
    .keypad_row_pins[1].direction = DIO_DIRECTION_OUTPUT,
    .keypad_row_pins[1].logic = DIO_HIGH,
    .keypad_row_pins[1].pullup = PULL_UP_DISABLE,
    
    .keypad_row_pins[2].port = PORTC_INDEX,
    .keypad_row_pins[2].pin = DIO_PIN3,
    .keypad_row_pins[2].direction = DIO_DIRECTION_OUTPUT,
    .keypad_row_pins[2].logic = DIO_HIGH,
    .keypad_row_pins[2].pullup = PULL_UP_DISABLE,
    
    .keypad_row_pins[3].port = PORTC_INDEX,
    .keypad_row_pins[3].pin = DIO_PIN2,
    .keypad_row_pins[3].direction = DIO_DIRECTION_OUTPUT,
    .keypad_row_pins[3].logic = DIO_HIGH,
    .keypad_row_pins[3].pullup = PULL_UP_DISABLE,
    
    
    .keypad_columns_pins[0].port = PORTD_INDEX,
    .keypad_columns_pins[0].pin = DIO_PIN7,
    .keypad_columns_pins[0].direction = DIO_DIRECTION_INPUT,
    .keypad_columns_pins[0].logic = DIO_LOW,
    .keypad_columns_pins[0].pullup = PULL_UP_ENABLE,
    
    .keypad_columns_pins[1].port = PORTD_INDEX,
    .keypad_columns_pins[1].pin = DIO_PIN6,
    .keypad_columns_pins[1].direction = DIO_DIRECTION_INPUT,
    .keypad_columns_pins[1].logic = DIO_LOW,
    .keypad_columns_pins[1].pullup = PULL_UP_ENABLE,
    
    .keypad_columns_pins[2].port = PORTD_INDEX,
    .keypad_columns_pins[2].pin = DIO_PIN5,
    .keypad_columns_pins[2].direction = DIO_DIRECTION_INPUT,
    .keypad_columns_pins[2].logic = DIO_LOW,
    .keypad_columns_pins[2].pullup = PULL_UP_ENABLE,
    
    .keypad_columns_pins[3].port = PORTD_INDEX,
    .keypad_columns_pins[3].pin = DIO_PIN3,
    .keypad_columns_pins[3].direction = DIO_DIRECTION_INPUT,
    .keypad_columns_pins[3].logic = DIO_LOW,
    .keypad_columns_pins[3].pullup = PULL_UP_ENABLE,
    
};

pin_config_t adc1 = {
    .port = PORTA_INDEX,
    .pin = DIO_PIN1, 
    .direction = DIO_DIRECTION_INPUT,
    .logic = DIO_LOW,
    .pullup = PULL_UP_ENABLE
};


/*
void Int1_APP_ISR(void){
    hal_led_turn_toggle(&led1);
}

interrupt_INTx_t int1_obj = {
  .EXT_InterruptHandler =  Int1_APP_ISR,
  .source = INTERRUPT_EXTERNAL_INT1,
  .pin_obj.port = PORTD_INDEX,
  .pin_obj.pin = DIO_PIN3,
  .pin_obj.direction = DIO_DIRECTION_INPUT,
  .pin_obj.pullup = PULL_UP_ENABLE,
  .pin_obj.logic = DIO_LOW,
  .mode = INT1_FALLING_EDGE,
};
*/

#endif	/* APPLICATION_H */

