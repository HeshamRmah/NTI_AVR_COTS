/* 
 * File:   mcal_dio.c
 * Author: Hesham
 *
 * Created on July 21, 2023, 7:22 PM
 */

#include "mcal_dio.h"

/* Array of Pointer to the Data Direction Registers */
volatile uint8 *ddr_registers[] = {&DDRA, &DDRB, &DDRC, &DDRD};
/* Array of Pointer to the Port Output Register */
volatile uint8 *port_registers[]  = {&PORTA , &PORTB , &PORTC , &PORTD};
/* Array of Pointer to the Port Input Register  */
volatile uint8 *pin_registers[] = {&PINA, &PINB, &PINC, &PIND};


/**
 * 
 * @param pin_config
 * @return 
 */
Std_ReturnType dio_set_pin_pull_up(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1) || (pin_config->direction == DIO_DIRECTION_OUTPUT)){
        ret = E_NOT_OK;
    }
    else{
        switch (pin_config->pullup){
            case PULL_UP_DISABLE:
                CLEAR_BIT(*port_registers[pin_config->port], pin_config->pin);
                break;
            case PULL_UP_ENABLE:
                SET_BIT(*port_registers[pin_config->port], pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
    }
    
    return ret;
}

/**
 * 
 * @param pin_config
 * @return 
 */
Std_ReturnType dio_pin_direction_intialize(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        ret = E_NOT_OK;
    }
    else{
        switch (pin_config->direction){
            case DIO_DIRECTION_INPUT:
                CLEAR_BIT(*ddr_registers[pin_config->port], pin_config->pin);
                dio_set_pin_pull_up(pin_config);
                break;
            case DIO_DIRECTION_OUTPUT:
                SET_BIT(*ddr_registers[pin_config->port], pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
    }
    
    return ret;
}

/**
 * 
 * @param pin_config
 * @param direction_status
 * @return 
 */
Std_ReturnType dio_pin_get_direction_status(const pin_config_t *pin_config, direction_t *direction_status){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (NULL == direction_status) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = GET_BIT(*ddr_registers[pin_config->port], pin_config->pin);
    }
    
    return ret;
    
}

/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
Std_ReturnType dio_pin_write_logic(const pin_config_t *pin_config, logic_t logic){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        ret = E_NOT_OK;
    }
    else{
        switch (logic){
            case DIO_HIGH :
                SET_BIT(*port_registers[pin_config->port], pin_config->pin);
                break;
            case DIO_LOW :
                CLEAR_BIT(*port_registers[pin_config->port], pin_config->pin);
                break;
            default : ret = E_NOT_OK;
        }
        
    }
    
    return ret;
    
}

/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
Std_ReturnType dio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (NULL == logic) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        ret = E_NOT_OK;
    }
    else{
        *logic = GET_BIT(*pin_registers[pin_config->port], pin_config->pin);
    }
    
    return ret;
    
}

/**
 * 
 * @param pin_config
 * @return 
 */
Std_ReturnType dio_pin_toggle_logic(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*port_registers[pin_config->port], pin_config->pin);
    }
    
    return ret;
    
}

/**
 * 
 * @param pin_config
 * @return 
 */
Std_ReturnType dio_pin_intialize(const pin_config_t *pin_config){
    Std_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        ret = E_NOT_OK;
    }
    else{
        ret = dio_pin_direction_intialize(pin_config);
        ret |= dio_pin_write_logic(pin_config, pin_config->logic);
    }
    
    return ret;
}

/**
 * 
 * @param pin_config
 * @return 
 */
Std_ReturnType dio_set_port_pull_up(port_index_t port){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1){
        ret = E_NOT_OK;
    }
    else{
        *port_registers[port] = 0xFF;
    }
    
    return ret;
}

/**
 * 
 * @param port
 * @param direction
 * @return 
 */
Std_ReturnType dio_port_direction_intialize(port_index_t port, uint8 direction){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1){
        ret = E_NOT_OK;
    }
    else{
        *ddr_registers[port] = direction;
    }
    
    return ret;
}

/**
 * 
 * @param port
 * @param direction_status
 * @return 
 */
Std_ReturnType dio_port_get_direction_status(port_index_t port, uint8 *direction_status){
    Std_ReturnType ret = E_OK;
    if ((port > PORT_MAX_NUMBER - 1) || (NULL == direction_status)){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = *ddr_registers[port];
    }
    
    return ret;
}

/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType dio_port_write_logic(port_index_t port, uint8 logic){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1){
        ret = E_NOT_OK;
    }
    else{
        *port_registers[port] = logic;
    }
    
    return ret;
}

/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType dio_port_read_logic(port_index_t port, uint8 *logic){
    Std_ReturnType ret = E_OK;
    if ((port > PORT_MAX_NUMBER - 1) || (NULL == logic) ){
        ret = E_NOT_OK;
    }
    else{
        *logic = *pin_registers[port];
    }
    
    return ret;
}

/**
 * 
 * @param port
 * @return 
 */
Std_ReturnType dio_port_toggle_logic(port_index_t port){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1){
        ret = E_NOT_OK;
    }
    else{
       *port_registers[port] = ~(*pin_registers[port]);
    }
    
    return ret;
}





