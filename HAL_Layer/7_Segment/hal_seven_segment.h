/* 
 * File:   hal_seven_segment.h
 * Author: Hesham
 *
 * Created on July 22, 2023, 1:42 PM
 */

#ifndef HAL_SEVEN_SEGMENT_H
#define	HAL_SEVEN_SEGMENT_H

/* Section : Includes */
#include "../../MCAL_Layer/DIO/mcal_dio.h"

/* Section: Macro Declarations */
#define SEGEMENT_ACTIVE_PIN0 0
#define SEGEMENT_ACTIVE_PIN1 1
#define SEGEMENT_ACTIVE_PIN2 2
#define SEGEMENT_ACTIVE_PIN3 3

#define SEGEMENT_DATA_PIN0 0
#define SEGEMENT_DATA_PIN1 1
#define SEGEMENT_DATA_PIN2 2
#define SEGEMENT_DATA_PIN3 3

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef enum{
    SEGMENT_OFF         = 0xF,
    SEGMENT_ONE_DIGIT   = 0xE,
    SEGMENT_TWO_DIGIT   = 0xC,
    SEGMENT_THREE_DIGIT = 0x8,
    SEGMENT_FOUR_DIGIT  = 0x0
}segment_active_pins_t;

typedef struct{
    pin_config_t segment_active_pins0;
    pin_config_t segment_active_pins1;
    pin_config_t segment_active_pins2;
    pin_config_t segment_active_pins3;
    pin_config_t segment_data_pins0;
    pin_config_t segment_data_pins1;
    pin_config_t segment_data_pins2;
    pin_config_t segment_data_pins3;
    //segment_type_t segment_type;
}segment_t;

/* Section: Function Declarations */
Std_ReturnType hal_seven_segement_intialize(const segment_t *seg);
Std_ReturnType hal_seven_segement_write_one_digit(const segment_t *seg, uint8 number);
Std_ReturnType hal_seven_segement_write_two_digit(const segment_t *seg, uint8 number);
Std_ReturnType hal_seven_segement_write_three_digit(const segment_t *seg, uint8 number);
Std_ReturnType hal_seven_segement_write_four_digit(const segment_t *seg, uint8 number);



#endif	/* HAL_SEVEN_SEGMENT_H */

