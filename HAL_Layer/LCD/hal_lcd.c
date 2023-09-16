/* 
 * File:   kal_lcd.c
 * Author: Hesham
 *
 * Created on July 23, 2023, 11:37 AM
 */

#include "hal_lcd.h"


static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8 _data_command);
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coulmn);

/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType lcd_4bit_intialize(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK;
    uint8 data_pins_counter = ZERO_INIT;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = dio_pin_intialize(&(lcd->lcd_rs));
        ret = dio_pin_intialize(&(lcd->lcd_en));
        for(data_pins_counter= ZERO_INIT; data_pins_counter<4; data_pins_counter++){
            ret = dio_pin_intialize(&(lcd->lcd_data[data_pins_counter]));
        }
        _delay_ms(20);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        //ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        //ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        ret = dio_pin_write_logic(&(lcd->lcd_rs), DIO_LOW);
        /* Send the Command through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, command >> 4);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
        /* Send the Command through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, command);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType lcd_4bit_clear_command(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_set_cursor(lcd, 1, 1);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8 data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
        ret = dio_pin_write_logic(&(lcd->lcd_rs), DIO_HIGH);
        /* Send the Data through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, data >> 4);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
        /* Send the Data through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, data);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_4bit_set_cursor(lcd, row, column);
        ret = lcd_4bit_send_char_data(lcd, data);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        while(*str){
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return 
 */
Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{ 
        ret = lcd_4bit_set_cursor(lcd, row, column);
        while(*str){
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param number
 * @return 
 */
Std_ReturnType lcd_4bit_send_uint32(const chr_lcd_4bit_t *lcd, uint32 number){
    Std_ReturnType ret = E_OK;
    uint32 counter = 0;
    uint8 flag = 0;
    uint8 digit[10];
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{ 
        for(counter = 10; counter > 0; counter--){
            digit[counter - 1] = number % 10;
            number /= 10;
            }
        for(counter = 0; counter < 10; counter++){
            if((digit[counter] != 0) || flag){
                flag = 1;
                ret = lcd_4bit_send_char_data(lcd, (digit[counter] + 0x30));
            }
            else {/* DO NOTHING */}
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param number
 * @return 
 */
Std_ReturnType lcd_4bit_send_uint32_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint32 number){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{ 
        ret = lcd_4bit_set_cursor(lcd, row, column);
        ret |= lcd_4bit_send_uint32(lcd, number);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return 
 */
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos){
    Std_ReturnType ret = E_OK;
    uint8 lcd_counter = ZERO_INIT;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_4bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
        for(lcd_counter = ZERO_INIT; lcd_counter <= 7; ++lcd_counter){
            ret = lcd_4bit_send_char_data(lcd, _chr[lcd_counter]);
        }
        ret = lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);
    }
    return ret;
}

/**
 * 
 * @param value
 * @param str
 * @return 
 */
Std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str){
    Std_ReturnType ret = E_OK;
    uint32 divider = 1000000000;
	uint8 _digit_number = 0;
    //uint8 flag = 1;
    if(NULL == str){
        ret = E_NOT_OK;
    }
    else{    
        for(divider = 1000000000; divider >= 10; (divider/=10)){
            if((value / divider) < 0){
                continue;
            }
            else if(((value / divider) > 0) ){
                //flag = 0;
                str[_digit_number++] = (value / divider) + 0x30;
                
                if((value % divider) < (divider/10)){
                 str[_digit_number++] = 0x30;
                }
                value %= divider;

                if(divider == 10){
                str[_digit_number++] = (value % 10) + 0x30;
                str[_digit_number] = '\0';
                }
            }
            else if(value < 10){
                str[_digit_number++] = value + 0x30;
                str[_digit_number] = '\0';
                break;
            }
        }
    }
    return ret;
}

/**
 * 
 * @param str
 * @param value
 * @return 
 */
Std_ReturnType convert_string_to_uint32(uint8 *str, uint32 *value){
    Std_ReturnType ret = E_OK;
    if((NULL == str) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{  
        *value = 0;
        while(*str != '\0'){
            *value = ((*value) * 10) + ((*str++) - 0x30);
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param _data_command
 * @return 
 */
static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8 _data_command){
    Std_ReturnType ret = E_OK;
    ret = dio_pin_write_logic(&(lcd->lcd_data[0]), (_data_command >> 0) & (uint8)0x01);
    ret = dio_pin_write_logic(&(lcd->lcd_data[1]), (_data_command >> 1) & (uint8)0x01);
    ret = dio_pin_write_logic(&(lcd->lcd_data[2]), (_data_command >> 2) & (uint8)0x01);
    ret = dio_pin_write_logic(&(lcd->lcd_data[3]), (_data_command >> 3) & (uint8)0x01);
    return ret;
}

/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK;
    ret = dio_pin_write_logic(&(lcd->lcd_en), DIO_HIGH);
    _delay_us(5);
    ret = dio_pin_write_logic(&(lcd->lcd_en), DIO_LOW);
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param coulmn
 * @return 
 */
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coulmn){
    Std_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_4bit_send_command(lcd, (0x80 + coulmn)); break;
        case ROW2 : ret = lcd_4bit_send_command(lcd, (0xc0 + coulmn)); break;
        case ROW3 : ret = lcd_4bit_send_command(lcd, (0x94 + coulmn)); break;
        case ROW4 : ret = lcd_4bit_send_command(lcd, (0xd4 + coulmn)); break;
        default : ;
    }
    return ret;
}

