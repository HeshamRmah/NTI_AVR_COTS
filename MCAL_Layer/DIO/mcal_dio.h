/* 
 * File:   mcal_dio.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 7:22 PM
 */

#ifndef MCAL_DIO_H
#define	MCAL_DIO_H

/* Section : Includes */
#include "../mcal_std_types.h"
#include "../std_libraries.h"

/* Section: Macro Declarations */
#define BIT_MASK  (uint8)1
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      4

/* Section: Macro Functions Declarations */
#define SET_BIT(REG, BIT_POSN)     (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)   (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)  (REG ^= (BIT_MASK << BIT_POSN))
#define GET_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)

/* Section: Data Type Declarations */

typedef enum{
    DIO_LOW = 0,
    DIO_HIGH
}logic_t;

typedef enum{
    DIO_DIRECTION_OUTPUT = 0,
    DIO_DIRECTION_INPUT
}direction_t;

typedef enum{
    DIO_PIN0 = 0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
}port_index_t;

typedef enum{
    PULL_UP_DISABLE = 0,
    PULL_UP_ENABLE,
}pull_up_t;

typedef struct{
    uint8 port : 2;
    uint8 pin : 3;
    uint8 direction : 1;
    uint8 logic : 1;
    uint8 pullup :1;
}pin_config_t;

/* Section: Function Declarations */
Std_ReturnType dio_set_pin_pull_up(const pin_config_t *pin_config);
Std_ReturnType dio_pin_direction_intialize(const pin_config_t *pin_config);
Std_ReturnType dio_pin_get_direction_status(const pin_config_t *pin_config, direction_t *direction_status);
Std_ReturnType dio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);
Std_ReturnType dio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);
Std_ReturnType dio_pin_toggle_logic(const pin_config_t *pin_config);
Std_ReturnType dio_pin_intialize(const pin_config_t *pin_config);

Std_ReturnType dio_set_port_pull_up(port_index_t port);
Std_ReturnType dio_port_direction_intialize(port_index_t port, uint8 direction);
Std_ReturnType dio_port_get_direction_status(port_index_t port, uint8 *direction_status);
Std_ReturnType dio_port_write_logic(port_index_t port, uint8 logic);
Std_ReturnType dio_port_read_logic(port_index_t port, uint8 *logic);
Std_ReturnType dio_port_toggle_logic(port_index_t port);

#endif	/* MCAL_DIO_H */

