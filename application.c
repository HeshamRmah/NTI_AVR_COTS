/* 
 * File:   application.c
 * Author: Hesham
 *
 * Created on July 21, 2023, 6:56 PM
 */

#include "application.h"


void lcd_print_story (void);
void calculator_program(void);
void calculator_program_one_operation(void);


extern led_t led1;
extern segment_t segment;
extern chr_lcd_4bit_t lcd;
extern keypad_t keypad;

int main() {
    
    //Std_ReturnType ret = E_OK;
    //uint8 get_keypad = 0, old_get_keypad = 0;
    //uint8 str[]= "513452";
    //uint8 str2[11];
    //uint32 value = 0;
    
    application_initialize();
    hal_led_turn_on(&led1);
    
    //lcd_print_story();
    calculator_program();
    
    //convert_string_to_uint32(str, &value);
    //convert_uint32_to_string(value, str2);
    //lcd_4bit_send_string_pos(&lcd, 1, 1, str2);
    
    while(1){
        
        
        
        
        
        /*
        keypad_get_value(&keypad, &get_keypad);
        
        if(old_get_keypad != get_keypad){
            lcd_4bit_send_char_data(&lcd, get_keypad);
            old_get_keypad = get_keypad;
        }*/
        
        
    }
    
    return (EXIT_SUCCESS);
}


Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    
    ret  = hal_led_initialize(&led1); 
    ret |= lcd_4bit_intialize(&lcd);
    ret |= hal_seven_segement_intialize(&segment);
    ret |= keypad_initialize(&keypad);
    
    return ret;
}

void get_operand(uint32 *operand, uint8 *operation){
    uint8 get_keypad = 0;
    uint8 counter = 0;
    uint8 arr[10];
    uint8 condition = 1;
    while(condition){
       keypad_get_value(&keypad, &get_keypad);
       _delay_ms(60);
       switch(get_keypad){
           case 0:
               break;
           case '#':
               condition = 0;
               *operation = '#';
               break;
            case '=':
               condition = 0;
               *operation = '=';
               break;
            case '*':
               condition = 0;
               *operation = '*';
               break;
            case '/':
               condition = 0;
               *operation = '/';
               break;
            case '+':
               condition = 0;
               *operation = '+';
               break;
            case '-':
               condition = 0;
               *operation = '-';
               break;
           default: 
                    lcd_4bit_send_char_data(&lcd, get_keypad);
                    arr[counter++] = get_keypad;  
                    get_keypad = 0;
               
       }
    }
    lcd_4bit_send_char_data(&lcd, get_keypad);
    convert_string_to_uint32(arr, operand);
}

void drop_array_uint8_ele(uint8 *ptr, uint8 ele_index, uint8 array_max_index){
    uint8 index = 0;
    for(index = ele_index; index <= array_max_index; index++){
        ptr[index] = ptr[index+1];
    }
    ptr[array_max_index] = '#';
}

void drop_array_uint32_ele(uint32 *ptr, uint8 ele_index, uint8 array_max_index){
    uint8 index = 0;
    for(index = ele_index; index <= array_max_index; index++){
        ptr[index] = ptr[index+1];
    }
    ptr[array_max_index] = '#';
}

void calculator_program(void){
    uint32 operands[7];
    uint8 operations[7];
    uint8 counter = 0;
    uint8 counter_logic = 0;
    uint8 done_operation = 0;
    uint8 str[10];
    //uint8 clac[] = " Calc:  ";
    //uint8 res[] = "Result: ";
    //lcd_4bit_send_command(&lcd, _LCD_CLEAR);
    //lcd_4bit_send_string_pos(&lcd, 1, 1, clac);
    for(counter = 0; counter < 6; counter++){
        get_operand(&(operands[counter]), &(operations[counter]));
        if(operations[counter]== '='){
            operands[counter+1] = '#';
            operations[counter+1] = '#';
            break;
        }
        else {/* DO NOTHING */}
    }

    /* first round to perform (*) or (/)*/
    for(counter_logic = 0; counter_logic <= counter; counter_logic++){
        switch(operations[counter_logic]){
        case '*':
            operands[counter_logic + 1] = operands[counter_logic] * operands[counter_logic + 1];
            drop_array_uint8_ele(operations, counter_logic, counter);
            drop_array_uint32_ele(operands, counter_logic, counter);
            done_operation++;
            counter_logic--;
            break;
        case '/':
            operands[counter_logic + 1] = operands[counter_logic] / operands[counter_logic + 1];
            drop_array_uint8_ele(operations, counter_logic, counter);
            drop_array_uint32_ele(operands, counter_logic, counter);
            done_operation++;
            counter_logic--;
            break;
        default:
            break;
    }
    
    }
    counter -= done_operation;
    /* second round to perform (+) or (-)*/
    for(counter_logic = 0; counter_logic <= counter; counter_logic++){
        
        switch(operations[counter_logic]){
        case '+':
            operands[counter_logic + 1] = operands[counter_logic] + operands[counter_logic + 1];
            drop_array_uint8_ele(operations, counter_logic, counter);
            drop_array_uint32_ele(operands, counter_logic, counter);
            counter_logic--;
            break;
        case '-':
            operands[counter_logic + 1] = operands[counter_logic] - operands[counter_logic + 1];
            drop_array_uint8_ele(operations, counter_logic, counter);
            drop_array_uint32_ele(operands, counter_logic, counter);
            counter_logic--;
            break;
        default:
            break;
    }
    
    }
    
    //lcd_4bit_send_string_pos(&lcd, 2, 1, res);
    convert_uint32_to_string(operands[0], str);
    lcd_4bit_send_string(&lcd, str);
    //lcd_4bit_send_string_pos(&lcd, 2, 1, str);
    uint8 done[] = "Done";
    lcd_4bit_send_string_pos(&lcd, 2, 1, done);
    _delay_ms(3000);
}

void calculator_program_one_operation(void){
    uint32 first_operand = 0;
    uint8 first_operation = 0;
    get_operand(&first_operand, &first_operation);
    uint32 second_operand = 0;
    uint8 second_operation = 0;
    get_operand(&second_operand, &second_operation);
    uint32 result = 0;
    uint8 str[10];
    
    switch(first_operation){
        case '*':
            result = first_operand * second_operand;
            convert_uint32_to_string(result, str);
            if(second_operation == '='){
                lcd_4bit_send_string_pos(&lcd, 2, 1, str);
            }
            break;
        case '/':
            result = (uint32)first_operand / (uint32)second_operand;
            convert_uint32_to_string((uint32)result, str);
            if(second_operation == '='){
                lcd_4bit_send_string_pos(&lcd, 2, 1, str);
            }
            break;
        case '+':
            result = first_operand + second_operand;
            convert_uint32_to_string(result, str);
            if(second_operation == '='){
                lcd_4bit_send_string_pos(&lcd, 2, 1, str);
            }
            break;
        case '-':
            result = first_operand - second_operand;
            convert_uint32_to_string(result, str);
            if(second_operation == '='){
                lcd_4bit_send_string_pos(&lcd, 2, 1, str);
            }
            break;
        default:
            break;
    }
    
}




void print_name_in_arabic(void){
/* hesham*/
    uint8 customha[] = {0x0F,0x09,0x0F,0x09,0x1F,0x00,0x00,0x00};
    uint8 customsh[] = {0x04,0x0A,0x00,0x15,0x1F,0x00,0x00,0x00};
    uint8 customaa[] = {0x08,0x08,0x08,0x08,0x0F,0x00,0x00,0x00};
    uint8 custommme[] = {0x00,0x0E,0x02,0x0E,0x08,0x08,0x08,0x08};
    uint8 custommms[] = {0x00,0x00,0x07,0x05,0x1F,0x00,0x00,0x00};
    uint8 customha7[] = {0x00,0x00,0x0E,0x02,0x1F,0x00,0x00,0x00};
    uint8 custommmb[] = {0x00,0x00,0x0E,0x0A,0x1F,0x00,0x00,0x00};
    uint8 customdd[] = {0x00,0x00,0x0E,0x02,0x0F,0x00,0x00,0x00};

    lcd_4bit_send_custom_char(&lcd, 1, 18,customha, 0);
        lcd_4bit_send_custom_char(&lcd, 1, 17,customsh, 1);
        lcd_4bit_send_custom_char(&lcd, 1, 16,customaa, 2);
        lcd_4bit_send_custom_char(&lcd, 1, 15,custommme, 3);
        lcd_4bit_send_char_data_pos(&lcd, 1, 14, ' ');
        lcd_4bit_send_custom_char(&lcd, 1, 13,custommms, 4);
        lcd_4bit_send_custom_char(&lcd, 1, 12,customha7, 5);
        lcd_4bit_send_custom_char(&lcd, 1, 11,custommmb, 6);
        lcd_4bit_send_custom_char(&lcd, 1, 10,customdd, 7);
}

void lcd_print_hamoksa(void){
    uint8 custom1[] = {0x04,0x0E,0x04,0x0E,0x15,0x04,0x0A,0x00};
    uint8 custom2[] = {0x04,0x0E,0x05,0x0E,0x14,0x04,0x0A,0x00};   
    uint8 custom3[] = {0x04,0x0E,0x15,0x0E,0x04,0x04,0x0A,0x00};     
    uint8 custom4[] = {0x04,0x0E,0x05,0x0E,0x14,0x04,0x0A,0x00};
   
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom1, 1);
    _delay_ms(500);
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom2, 1);
    _delay_ms(500);
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom3, 1);
    _delay_ms(500);
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom4, 1);
    _delay_ms(500);
}


void lcd_print_story(void){
    uint8 custom1[] = {0x04,0x0E,0x04,0x0E,0x15,0x04,0x0A,0x00};
    uint8 custom2[] = {0x04,0x0E,0x05,0x0E,0x14,0x04,0x0A,0x00};   
    uint8 custom3[] = {0x04,0x0E,0x15,0x0E,0x04,0x04,0x0A,0x00};     
    uint8 custom4[] = {0x04,0x0E,0x05,0x0E,0x14,0x04,0x0A,0x00};
   
    uint8 str_1[] = " Hello This is Story"; 
    uint8 str_2[] = "My Name is Hesham";
    
    lcd_4bit_send_string_pos(&lcd, 2, 1, str_1);
    lcd_4bit_send_string_pos(&lcd, 4, 1, str_2);
    
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom1, 1);
    _delay_ms(250);
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom2, 1);
    _delay_ms(250);
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom3, 1);
    _delay_ms(250);
    lcd_4bit_send_custom_char(&lcd, 1, 1,custom4, 1);
    _delay_ms(250);
    
    
    
    
}