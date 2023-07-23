/* 
 * File:   hal_led.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 10:02 PM
 */

#ifndef HAL_LED_H
#define	HAL_LED_H

/* Section : Includes */
#include "../../MCAL_Layer/DIO/mcal_dio.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

typedef enum{
    LED_OFF = 0,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port       : 2;
    uint8 pin        : 3;
    uint8 led_status : 1;
    uint8            : 2;
}led_t;

/* Section: Function Declarations */

Std_ReturnType hal_led_initialize(const led_t *led);
Std_ReturnType hal_led_turn_on(const led_t *led);
Std_ReturnType hal_led_turn_off(const led_t *led);
Std_ReturnType hal_led_turn_toggle(const led_t *led);

#endif	/* HAL_LED_H */

