/* 
 * File:   hal_seven_segment.h
 * Author: Hesham
 *
 * Created on July 22, 2023, 1:42 PM
 */


#include "hal_seven_segment.h"

/**
 * 
 * @param seg
 * @return 
 */
Std_ReturnType hal_seven_segement_intialize(const segment_t *seg){
    Std_ReturnType ret = E_OK;
    if(NULL == seg){
        ret = E_NOT_OK;
    }
    else{    
        ret  = dio_pin_intialize(&(seg->segment_active_pins0));
        ret |= dio_pin_intialize(&(seg->segment_active_pins1));
        ret |= dio_pin_intialize(&(seg->segment_active_pins2));
        ret |= dio_pin_intialize(&(seg->segment_active_pins3));
        
        ret |= dio_pin_intialize(&(seg->segment_data_pins0));
        ret |= dio_pin_intialize(&(seg->segment_data_pins1));
        ret |= dio_pin_intialize(&(seg->segment_data_pins2));
        ret |= dio_pin_intialize(&(seg->segment_data_pins3));
    }
    return ret;
}

/**
 * 
 * @param seg
 * @param number
 * @return 
 */
Std_ReturnType hal_seven_segement_write_one_digit(const segment_t *seg, uint8 number){
    Std_ReturnType ret = E_OK;
    if((NULL == seg) && (number > 9)){
        ret = E_NOT_OK;
    }
    else{
        ret  = dio_pin_write_logic(&(seg->segment_active_pins0), DIO_LOW);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins1), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins2), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins3), DIO_HIGH);
        
        ret |= dio_pin_write_logic(&(seg->segment_data_pins0), number & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins1), (number>>1) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins2), (number>>2) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins3), (number>>3) & 0x01);
    }
    return ret;
}

Std_ReturnType hal_seven_segement_write_two_digit(const segment_t *seg, uint8 number){
    Std_ReturnType ret = E_OK;
    uint8 temp = 0;
    if((NULL == seg) && (number > 99)){
        ret = E_NOT_OK;
    }
    else{
        ret  = dio_pin_write_logic(&(seg->segment_active_pins0), DIO_LOW);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins1), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins2), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins3), DIO_HIGH);
        temp = number % 10;
        ret |= dio_pin_write_logic(&(seg->segment_data_pins0), temp & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins1), (temp>>1) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins2), (temp>>2) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins3), (temp>>3) & 0x01);
        _delay_ms(5);
        ret  = dio_pin_write_logic(&(seg->segment_active_pins0), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins1), DIO_LOW);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins2), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins3), DIO_HIGH);
        temp = number / 10;
        ret |= dio_pin_write_logic(&(seg->segment_data_pins0), temp & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins1), (temp>>1) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins2), (temp>>2) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins3), (temp>>3) & 0x01);
        _delay_ms(5);
        
    }
    return ret;
}

Std_ReturnType hal_seven_segement_write_three_digit(const segment_t *seg, uint8 number){
    Std_ReturnType ret = E_OK;
    if((NULL == seg) && (number > 9)){
        ret = E_NOT_OK;
    }
    else{
        ret  = dio_pin_write_logic(&(seg->segment_active_pins0), DIO_LOW);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins1), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins2), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins3), DIO_HIGH);
        
        ret |= dio_pin_write_logic(&(seg->segment_data_pins0), number & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins1), (number>>1) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins2), (number>>2) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins3), (number>>3) & 0x01);
    }
    return ret;
}

Std_ReturnType hal_seven_segement_write_four_digit(const segment_t *seg, uint8 number){
    Std_ReturnType ret = E_OK;
    if((NULL == seg) && (number > 9)){
        ret = E_NOT_OK;
    }
    else{
        ret  = dio_pin_write_logic(&(seg->segment_active_pins0), DIO_LOW);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins1), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins2), DIO_HIGH);
        ret |= dio_pin_write_logic(&(seg->segment_active_pins3), DIO_HIGH);
        
        ret |= dio_pin_write_logic(&(seg->segment_data_pins0), number & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins1), (number>>1) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins2), (number>>2) & 0x01);
        ret |= dio_pin_write_logic(&(seg->segment_data_pins3), (number>>3) & 0x01);
    }
    return ret;
}


