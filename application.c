/* 
 * File:   application.c
 * Author: Hesham
 *
 * Created on July 21, 2023, 6:56 PM
 */

#include "application.h"

void Calculator_voidGetString(void);
void Calculator_voidAnalysisString(void);
void Calculator_voidCalculate(void);
void Calculator_voidRunable(void);

uint8 str[40];
uint8 str_count;
uint8 eq_flag;
sint32 numbers_arr[20];
uint8 operations_arr[20];
uint8 numbers_arr_count ;
uint8 operations_arr_count ;
sint32 result;
uint8 clear_flag;



volatile uint16 _time = 0;
uint16 distance = 0;

Std_ReturnType ret = E_OK;

int main() {
    
    application_initialize();

    while(1){
        dio_pin_write_logic(&Pin_D5, DIO_HIGH);
        _delay_us(10);
        dio_pin_write_logic(&Pin_D5, DIO_LOW);
        distance = _time / 57;
        lcd_4bit_send_uint32_pos(&lcd, 2, 1, (uint32)distance);
        _delay_ms(50);
            
    }
    
    return (EXIT_SUCCESS);
}

Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    
    //INTERRUPT_GlobalInterruptEnable();
    
    ret |= hal_led_initialize(&led1); 
    
    //ret |= hal_led_initialize(&led2); 
    //ret |= hal_led_initialize(&led3); 
    ret |= lcd_4bit_intialize(&lcd);
    ret |= keypad_initialize(&keypad);
    //ret |= ADC_Init(&adc_obj);
    //ret |= ADC_Init(&adc_obj_2);
    //ret |= hal_button_initialize(&button);
    //ret |= hal_button_initialize(&button_T0);
    //ret |= hal_seven_segement_intialize(&segment);
    //ret |= Interrupt_INTx_Init(&int1_obj);
    //ret |= SPI_Init(&SPI_obj);
    //ret |= Timer0_Init(&Timer0);
    //ret |= dio_pin_intialize(&OC0);
    ret |= dio_pin_intialize(&ICP1);
    ret |= dio_pin_intialize(&Pin_D5);
    //ret |= dio_pin_intialize(&OC1A);
    //ret |= dio_pin_intialize(&OC1B);
    ret |= Timer1_Init(&Timer1);
    //ret |= I2C_Master_Init(&I2C);
    //ret |= dio_pin_intialize(&SCL);
    //ret |= dio_pin_intialize(&SDA);
    
    //USART_Init();
    
    return ret;
}


void Timer1_APP_ISR(void){
    static uint8 mode = 0;
    static uint16 start_time = 0;
    static uint16 end_time = 0;
    
    if(mode == 0){
       Timer1_Read_Input_Capture_Unit_Value(&Timer1, &start_time);
       //lcd_4bit_send_uint32_pos(&lcd, 3, 1, start_time);
       Timer1_Input_capture_Change_Sense_Edge(&Timer1, INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_FALLING_EDGE);
       Timer1_Write_Value(&Timer1, 0);
       mode = 1;
       
    }
    else if(mode == 1){
        
        Timer1_Read_Input_Capture_Unit_Value(&Timer1, &end_time);
        //lcd_4bit_send_uint32_pos(&lcd, 4, 1, end_time);
        Timer1_Input_capture_Change_Sense_Edge(&Timer1, INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_RISING_EDGE);
        _time = end_time + start_time;
        Timer1_Write_Value(&Timer1, 0);
        end_time = 11;
        start_time = 0;
        mode = 0;
        //lcd_4bit_send_uint32(&lcd, 2);
    }
    else{
        //lcd_4bit_send_uint32(&lcd, 3);
    }
    
}







void Calculator_voidGetString(void)
{
	static uint8 op_flag = 0;
	static uint8 sign_flag = 0;
	uint8 key;
    uint8 str_space[] = "                    ";
    uint8 str_enter[] = "Enter your Equation:";
    uint8 str_start[] = "";
    
    lcd_4bit_send_string_pos(&lcd, 1, 1, str_enter);
    lcd_4bit_send_string_pos(&lcd, 2, 1, str_start);
    keypad_get_value(&keypad, &key);
    
	if(key != NO_KEY)
	{
		if(clear_flag == 1)
		{
			clear_flag = 0;
			numbers_arr_count = 0;
			operations_arr_count = 0;
			str_count = 0;
			result = 0;
            
			for(int i = 0; str[i]; i++)
			{
				str[i] = 0;
			}
			for (int i = 0; i < 20; i++)
			{
				numbers_arr[i] = 0;
				operations_arr[i] = 0;
			}
            lcd_4bit_send_string_pos(&lcd, 1, 1, str_space);
			lcd_4bit_send_string_pos(&lcd, 2, 1, str_space);
            lcd_4bit_send_string_pos(&lcd, 3, 1, str_space);
            lcd_4bit_send_string_pos(&lcd, 4, 1, str_space);
            lcd_4bit_send_string_pos(&lcd, 1, 1, str_enter);
            lcd_4bit_send_string_pos(&lcd, 2, 1, str_start);
		}
        
		if (str_count == 0)
		{
			if ((key >= '0') && (key <= '9'))
			{
				str[str_count] = key;
				str_count++;
			}
			else if (key == '-')
			{
				str[str_count] = key;
				str_count++;
				sign_flag = 1;
			}
		}
        
		else if(str_count > 0)
		{
			if ((key >= '0') && (key<='9'))
			{
				str[str_count] = key;
				str_count++;
                // **************************************
				sign_flag = 1;
				op_flag = 0;
			}
			else if ( ( (key == '/')|| (key=='*') || (key=='-') || (key=='+') ) && (op_flag == 0) )
			{
				str[str_count] = key;
				str_count++;
				op_flag = 1;
				sign_flag = 0;
			}
			else if( (sign_flag == 0) && (key == '-') && (op_flag == 1) )
			{
				str[str_count] = key;
				str_count++;
				sign_flag = 1;
			}
			else if ( ((key == '/') || (key == '*') || (key == '-') || (key == '+'))  && (op_flag == 1) && (sign_flag == 0) )
			{
				str_count--;
				str[str_count] = key;
				str_count++;
			}
			else if (key == '#')
			{
                
				str_count--;
				str[str_count] = 0;
				if((str[str_count-2] == '*' || str[str_count-2] == '/' || str[str_count-2] == '-' || str[str_count-2] == '+') && str[str_count-1] == '-')
				{
					sign_flag = 1;
					op_flag = 1;
				}
				else if(str[str_count-1] == '*' || str[str_count-1] == '/' || str[str_count-1] == '-' || str[str_count-1] == '+')
				{
					sign_flag = 0;
					op_flag = 1;
				}
                
			}
			
		}
        
		if( (str_count == 40) || (key == '='))
		{
			eq_flag = 1;
		}
		
	}
}

void Calculator_voidAnalysisString(void)
{
	uint8 sign_flag = 0;
	for (int i = 0; i < str_count; i++)
	{
		if(str[i] == '-' && i==0)
		{
			sign_flag = 1;
		}
        
		else if ((str[i] == '-') && (str[i-1] == '*' || str[i-1] == '/' || str[i-1] == '-' || str[i-1] == '+'))
		{
			sign_flag = 1;
		}
        
		else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			operations_arr[operations_arr_count] = str[i];
			if (sign_flag == 1)
			{
				numbers_arr[numbers_arr_count] = numbers_arr[numbers_arr_count] * (-1);
				sign_flag = 0;
			}
			operations_arr_count++;
			numbers_arr_count++;
		}
        
		else if ( (str[i] >= '0') && (str[i] <= '9') )
		{
			numbers_arr[numbers_arr_count] = ( ( ((sint32)numbers_arr[numbers_arr_count]) * (sint32)10 ) + ( (sint32)(str[i] - '0') ) );
		}

	}
    
	if (sign_flag == 1)
	{
		numbers_arr[numbers_arr_count] = numbers_arr[numbers_arr_count] * (-1);
		sign_flag = 0;
	}
		
}

void Calculator_voidCalculate(void)
{
	sint8 index = -1;
	uint8 switch_flag = 0;
	while(operations_arr_count != 0)
	{
		if (switch_flag == 0)
		{
			for (uint8 i = 0; i < operations_arr_count; i++)
			{
				switch_flag = 1;
				if(operations_arr[i] == '*')
				{
					numbers_arr[i] = numbers_arr[i] * numbers_arr[i+1];
					index = i;
					operations_arr_count--;
					switch_flag = 0;
					break;
				}
                
				else if(operations_arr[i] == '/')
				{
					numbers_arr[i] = numbers_arr[i] / numbers_arr[i+1];
					index = i;
					operations_arr_count--;
					switch_flag = 0;
					break;
				}
			}
		}
		else
		{
			for (uint8 i = 0; i < operations_arr_count; i++)
			{
				switch_flag = 1;
				if(operations_arr[i] == '+')
				{
					numbers_arr[i] = numbers_arr[i] + numbers_arr[i+1];
					index = i;
					operations_arr_count--;
					switch_flag = 0;
					break;
				}
				else if(operations_arr[i] == '-')
				{
					numbers_arr[i] = numbers_arr[i] - numbers_arr[i+1];
					index = i;
					operations_arr_count--;
					switch_flag = 0;
					break;
				}
			}
		}
		
		if(index != (-1))
		{
			for (uint8 i = index; i < operations_arr_count; i++)
			{
				operations_arr[i] = operations_arr[i+1];
			}
			for(uint8 i = index + 1; i <= operations_arr_count; i++)
			{
				numbers_arr[i] = numbers_arr[i+1];
			}
			index = -1;
		}
	}
	result = numbers_arr[0];
	
}
void Calculator_voidRunable(void)
{
	Calculator_voidGetString();
    lcd_4bit_send_string_pos(&lcd, 2, 1, str);
	if (eq_flag == 1)
	{
		Calculator_voidAnalysisString();
		Calculator_voidCalculate();
        lcd_4bit_send_char_data_pos(&lcd,3, 1, '=');
        lcd_4bit_send_uint32(&lcd, result);
		clear_flag = 1;
		eq_flag = 0;
	}
	
}