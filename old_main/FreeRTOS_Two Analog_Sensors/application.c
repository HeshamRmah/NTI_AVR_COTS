/* 
 * File:   application.c
 * Author: Hesham
 *
 * Created on July 21, 2023, 6:56 PM
 */

#include "application.h"

void vTaskCode( void * pvParameters );
void vTaskCode2( void * pvParameters );
void vTaskCode3( void * pvParameters );
void vTaskCode4( void * pvParameters );
void vTaskCode5( void * pvParameters );
void vOtherFunction( void );
TaskHandle_t xHandle_1 = NULL;
TaskHandle_t xHandle_2 = NULL;
TaskHandle_t xHandle_3 = NULL;
TaskHandle_t xHandle_EMPTY = NULL;
TaskHandle_t xHandle_4 = NULL;
TaskHandle_t xHandle_5 = NULL;
TaskHandle_t xHandle_6 = NULL;

SemaphoreHandle_t LCD_Semaphore;
QueueHandle_t xQueue1, xQueue2;
//void lcd_print_story (void);
//void calculator_program(void);
//void calculator_program_one_operation(void);


//extern led_t led1;
//extern segment_t segment;
//extern chr_lcd_4bit_t lcd;
//extern keypad_t keypad;

Std_ReturnType ret = E_OK;
volatile uint16 adc_value_Interrupt = 0;
uint16 ICR_value = 0;

//static uint16 icu_counter = 0;
//static uint16 temp1;
//static uint16 temp2;
//static uint16 temp3;
volatile uint8 flag = 0;
uint8 send_i2c = 0x8;
uint8 reci_i2c = 0x00;


int main() {
    
    //float TimerClock = (float)(8/(float)8000000) ; /*Tick Time*/
	//uint16 Duty_cycle ;
	//uint16 Period;
	//uint16 Onperiod;
	//uint16 Freq = 0;
    //uint8 str_freq[] = "Freq =";
    //uint8 str_duty[] = "Duty Cycle =";
    
    //Std_ReturnType ret = E_OK;
    //uint8 get_keypad = 'A', old_get_keypad = 0;
    //uint8 str[]= "1230456";
    //uint8 str2[11];
    //uint32 value = 1230456;
    //uint16 adc_value = 0;
    //uint8 timer0_value = 0;
            
    application_initialize();
    //ret |= hal_led_turn_on(&led1);
    //ret |= hal_led_turn_on(&led2);
    //ret |= hal_led_turn_on(&led3);
    //uint8 str_1[] = "AAAAAAAAAAAA";
    //lcd_4bit_send_string_pos(&lcd, 2, 1, str_1);
    
    vOtherFunction();
    vTaskStartScheduler();
    
    //lcd_print_story();
    
    //calculator_program();
    
    //lcd_4bit_send_char_data_pos(&lcd, 2, 1, 'A');
    //lcd_4bit_send_uint32(&lcd, 654708);
    //convert_string_to_uint32(str, &value);
    //convert_uint32_to_string(value, str2);
    //lcd_4bit_send_string_pos(&lcd, 1, 1, str);
    //lcd_4bit_send_char_data(&lcd, 'V');
    //lcd_4bit_set_cursor(&lcd, 2, 1);
    //lcd_4bit_send_uint32(&lcd, 654708);
    
    //lcd_4bit_send_uint32_pos(&lcd, 2, 1, 123400578);
    
    //lcd_4bit_send_uint32(&lcd, 987654321);
    //lcd_4bit_send_string_pos(&lcd, 4, 1, str);
    
    //ADC_voidEnable();
    //USART_Transmit(get_keypad);
    //lcd_4bit_send_string_pos(&lcd, 3, 1, str);
    
    //TCCR1A = (1<<COM1A1) + (1<<WGM11); 
  //TCCR1B = (1<<WGM13) + (1<<CS10); // prescaler = none; 
  //ICR1 = 15999;
  //OCR1A = 3999;
  //DDRD |= (1<<PB5);
    /*
    while(flag!=3);

		Period = temp2 - temp1;

		Onperiod = temp3 - temp2;

		Duty_cycle = ((Onperiod*100)/Period);

		Freq = (1 / ( Period * TimerClock ));
        
        
        lcd_4bit_send_string_pos(&lcd, 2, 1, str_freq);
        lcd_4bit_send_uint32(&lcd, (uint32)Freq);
        
        lcd_4bit_send_string_pos(&lcd, 3, 1, str_duty);
		lcd_4bit_send_uint32(&lcd, (uint32)Duty_cycle);
        lcd_4bit_send_char_data(&lcd, '%');
        */
    /*
    ret = I2C_Master_Send_Start(&I2C);
    ret = I2C_Master_Write_Polling(&I2C, ((0x50 << 1) + 0));
    ret = I2C_Master_Write_Polling(&I2C, send_i2c++);
    ret = I2C_Master_Send_Stop(&I2C);
    
    _delay_ms(1000);
    
    ret = I2C_Master_Send_Start(&I2C);
    ret = I2C_Master_Write_Polling(&I2C, ((0x50 << 1) + 1));
    ret = I2C_Master_Read_Polling(&I2C, &reci_i2c);
    ret = I2C_Master_Send_Stop(&I2C);
    
     _delay_ms(2000);
    
    ret = I2C_Master_Send_Start(&I2C);
    ret = I2C_Master_Write_Polling(&I2C, ((0x50 << 1) + 0));
    ret = I2C_Master_Write_Polling(&I2C, send_i2c++);
    ret = I2C_Master_Send_Stop(&I2C);
    
    _delay_ms(1000);
    */
    //_delay_ms(2000);
    //ret = I2C_Master_Send_Start(&I2C);
    //ret = I2C_Master_Write_Polling(&I2C, ((0x50 << 1) + 1));
    //ret = I2C_Master_Read_Polling(&I2C, &reci_i2c);
    //ret = I2C_Master_Send_Stop(&I2C);
    
    while(1){
        
        
        
        //_delay_ms(1000);
        
        
        
        
        
        
        
        //Timer0_Read_Value(&Timer0, &timer0_value);
        //lcd_4bit_send_uint32_pos(&lcd, 2, 1, (uint32)timer0_value);
        
        //ADC_GetConversion_Polling(&adc_obj, &adc_value);
        //ADC_StartConversion_Interrupt(&adc_obj);
        //lcd_4bit_send_uint32_pos(&lcd, 3, 1, (uint32)adc_value);
        
        //SPI_Send_Byte_Interrupt(&SPI_obj, '0');
        //_delay_ms(1000);
        //SPI_Send_Byte_Interrupt(&SPI_obj, '1');
        //_delay_ms(1000);
        //SPI_Send_Byte_Interrupt(&SPI_obj, '2');
        //_delay_ms(1000);
        //SPI_Send_Byte_Interrupt(&SPI_obj, '3');
        //_delay_ms(1000);
        //SPI_Send_Byte_Interrupt(&SPI_obj, '4');
        //_delay_ms(1000);
        //SPI_Send_Byte_Interrupt(&SPI_obj, '5');
        //_delay_ms(1000);
        //lcd_4bit_clear_command(&lcd);
        
        
        //lcd_4bit_send_command(&lcd, _LCD_CLEAR);
        //get_keypad++;
        //USART_Transmit(get_keypad);
        //_delay_ms(500);
        //old_get_keypad = USART_Receive();
        
        //lcd_4bit_send_char_data(&lcd, old_get_keypad);
        
        /*
        keypad_get_value(&keypad, &get_keypad);
        
        if(old_get_keypad != get_keypad){
            lcd_4bit_send_char_data(&lcd, get_keypad);
            old_get_keypad = get_keypad;
        }*/
        
    }
    
    return (EXIT_SUCCESS);
}


/* Task to be created. */
/*
void vTaskCode( void * pvParameters )
{

    for( ;; )
    {
        hal_led_turn_toggle((led_t *)pvParameters);
        vTaskDelay(2000);
    }
}
*/
void vTaskCode2( void * pvParameters )
{
    //uint8 Temp_1 = 50;
    uint16 read;
    for( ;; )
    {
        ADC_GetConversion_Polling(&adc_obj, &read);
        xQueueOverwrite( xQueue1, &read);
        if(read > 500){
          //hal_led_turn_on((led_t *)pvParameters);  
            hal_led_turn_on(&led3);
        }
        else{
           hal_led_turn_off(&led3);  
        }
        //Temp_1++;
        lcd_4bit_send_uint32_pos(&lcd, 4, 1, 4);
        vTaskDelay(1500);
    }
}

void vTaskCode3( void * pvParameters )
{
    //uint8 Temp_2 = 40;
    uint16 read_2;
    for( ;; )
    {
        ADC_GetConversion_Polling(&adc_obj_2, &read_2);
        xQueueOverwrite( xQueue2, &read_2);
        if(read_2 > 1000){
          hal_led_turn_on(&led2);  
        }
        else{
           hal_led_turn_off(&led2);  
        }
        lcd_4bit_send_uint32_pos(&lcd, 4, 1, 3);
        //Temp_2++;
        vTaskDelay(1800);
    }
}

void vTaskCode4( void * pvParameters )
{
    uint8 str_1[] = "Sensor 1 = ";
    uint8 space[] = "   ";
    uint16 value;
    for( ;; )
    {
        
        if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15))
		{
			xQueuePeek( xQueue1, &( value ), ( TickType_t ) 10 );
			lcd_4bit_send_string_pos(&lcd, 2, 1, str_1);
			lcd_4bit_send_uint32_pos(&lcd, 2, 12, value);
            lcd_4bit_send_string(&lcd, space);
			lcd_4bit_send_uint32_pos(&lcd, 4, 1, 1);
			xSemaphoreGive(LCD_Semaphore);
			
		}
        vTaskDelay(900);
    }
}

void vTaskCode5( void * pvParameters )
{
    uint8 str_2[] = "Sensor 2 = ";
    uint8 space[] = "   ";
    uint16 value_2;
    for( ;; )
    {
        
        if (xSemaphoreTake(LCD_Semaphore,10)== pdTRUE)
		{
			xQueuePeek( xQueue2, &( value_2 ), ( TickType_t ) 10);
			lcd_4bit_send_string_pos(&lcd, 2, 1, str_2);
			lcd_4bit_send_uint32_pos(&lcd, 2, 12, value_2);
            lcd_4bit_send_string(&lcd, space);
			lcd_4bit_send_uint32_pos(&lcd, 4, 1, 2);
			xSemaphoreGive(LCD_Semaphore);

		}
        
        vTaskDelay(800);
    }
}

/* Function that creates a task. */
void vOtherFunction( void )
{
BaseType_t xReturned;

    /* Create the task, storing the handle. */

    xReturned = xTaskCreate(
                    vTaskCode2,       /* Function that implements the task. */
                    "Task 1",        /* Text name for the task. */
                    180,             /* Stack size in words, not bytes. */
                    &led2,    /* Parameter passed into the task. */
                    3,               /* Priority at which the task is created. */
                    &xHandle_1 );      /* Used to pass out the created task's handle. */
    
    xReturned = xTaskCreate(
                    vTaskCode3,       /* Function that implements the task. */
                    "Task 2",        /* Text name for the task. */
                    180,             /* Stack size in words, not bytes. */
                    &led3,    /* Parameter passed into the task. */
                    2,               /* Priority at which the task is created. */
                    &xHandle_2 );      /* Used to pass out the created task's handle. */
    
    xReturned = xTaskCreate(
                    vTaskCode4,       /* Function that implements the task. */
                    "Task 3",        /* Text name for the task. */
                    180,             /* Stack size in words, not bytes. */
                    &lcd,    /* Parameter passed into the task. */
                    9,               /* Priority at which the task is created. */
                    &xHandle_3 );      /* Used to pass out the created task's handle. */

    xReturned = xTaskCreate(
                    vTaskCode5,       /* Function that implements the task. */
                    "Task 4",        /* Text name for the task. */
                    180,             /* Stack size in words, not bytes. */
                    &lcd,    /* Parameter passed into the task. */
                    8,               /* Priority at which the task is created. */
                    &xHandle_4 );      /* Used to pass out the created task's handle. */
    
    LCD_Semaphore = xSemaphoreCreateMutex();
    xQueue1 = xQueueCreate( 1, sizeof( unsigned short ) );
    xQueue2 = xQueueCreate( 1, sizeof( unsigned short ) );
}

Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    //INTERRUPT_GlobalInterruptEnable();
    ret |= hal_led_initialize(&led1); 
    ret |= hal_led_initialize(&led2); 
    ret |= hal_led_initialize(&led3); 
    ret |= lcd_4bit_intialize(&lcd);
    ret |= ADC_Init(&adc_obj);
    ret |= ADC_Init(&adc_obj_2);
    //ret |= hal_button_initialize(&button);
    //ret |= hal_button_initialize(&button_T0);
    //ret |= hal_seven_segement_intialize(&segment);
    //ret |= keypad_initialize(&keypad);
    //ret |= Interrupt_INTx_Init(&int1_obj);
    //ret |= SPI_Init(&SPI_obj);
    //ret |= Timer0_Init(&Timer0);
    //ret |= dio_pin_intialize(&OC0);
    //ret |= dio_pin_intialize(&ICP1);
    //ret |= dio_pin_intialize(&OC1A);
    //ret |= dio_pin_intialize(&OC1B);
    //ret |= Timer1_Init(&Timer1);
    //ret |= I2C_Master_Init(&I2C);
    //ret |= dio_pin_intialize(&SCL);
    //ret |= dio_pin_intialize(&SDA);
    
    //USART_Init();
    
    return ret;
}
/*
void Int1_APP_ISR(void){
    hal_led_turn_toggle(&led1);
    _delay_ms(25);
}

void ADC_APP_ISR(void){
    adc_value_Interrupt++;
    _delay_ms(1000);
}

void SPI_APP_ISR(void){
    hal_led_turn_toggle(&led1);
}
void Timer0_APP_ISR(void){
    hal_led_turn_toggle(&led1);
}
void Timer0_APP_CTC_ISR(void){
    hal_led_turn_toggle(&led1);
}

void Timer1_APP_ISR(void){
    if(flag == 0)
	{
        Timer1_Read_Input_Capture_Unit_Value(&Timer1, &temp1);
        //temp1 = ICR1bits;
		flag = 1;
	}
	else if(flag == 1)
	{
        Timer1_Input_capture_Change_Sense_Edge(&Timer1, INPUT_CAPTURE_UNIT_WITH_NOISE_CANCELER_SENSE_FALLING_EDGE);
		Timer1_Read_Input_Capture_Unit_Value(&Timer1, &temp2);
        //temp2 = ICR1bits;
		flag = 2;
	}
	else if(flag == 2)
	{
		Timer1_Read_Input_Capture_Unit_Value(&Timer1, &temp3);
        //temp3 = ICR1bits;
		flag = 3;
	}
	else{}
}
*/
#if 0
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
#endif