/* 
 * File:   application.c
 * Author: Hesham
 *
 * Created on July 21, 2023, 6:56 PM
 */

#include "application.h"

#define PASSWORD        "12345" 
#define PASS_COMPLETE	( 1 << 0 )
#define PASS_CORRECT	( 1 << 1 )
#define EQU_COMPLETE	( 1 << 2 )
#define EQU_REQUEST	    ( 1 << 3 )

//void vTaskCode( void * pvParameters );
void vTaskGetPass( void * pvParameters );
void vTaskCheckPass( void * pvParameters );
void vTaskGetEq( void * pvParameters );
void vTaskCalcEq( void * pvParameters );
void vOtherFunction( void );
TaskHandle_t xHandle_1 = NULL;
TaskHandle_t xHandle_2 = NULL;
TaskHandle_t xHandle_3 = NULL;
TaskHandle_t xHandle_4 = NULL;
//TaskHandle_t xHandle_EMPTY = NULL;
//TaskHandle_t xHandle_5 = NULL;
//TaskHandle_t xHandle_6 = NULL;

SemaphoreHandle_t LCD_Semaphore, Pass_Mutex;
QueueHandle_t xQueuePass, xQueueOperand, xQueueOperation;
EventGroupHandle_t xEventGroup;
EventBits_t uxBits;

void calculator_program(void);
void get_operand(uint32 *operand, uint8 *operation);
void calculator_program_one_operation(void);
void drop_array_uint32_ele(uint32 *ptr, uint8 ele_index, uint8 array_max_index);
void drop_array_uint8_ele(uint8 *ptr, uint8 ele_index, uint8 array_max_index);

Std_ReturnType ret = E_OK;
volatile uint16 adc_value_Interrupt = 0;
uint16 ICR_value = 0;

volatile uint8 flag = 0;
uint8 send_i2c = 0x8;
uint8 reci_i2c = 0x00;

int main() {
    application_initialize();

    vOtherFunction(); 
    vTaskStartScheduler();

    while(1){
            
    }
    
    return (EXIT_SUCCESS);
}

/* Task to be created. */
/*
void vTaskCode( void * pvParameters )
{
    for( ;; )
    {
        vTaskDelay(2000);
    }
}
*/
void vTaskGetPass( void * pvParameters )
{
    uint8 value = NO_KEY, num = 0;
    uint8 str[] = "Enter Pass";
    //lcd_4bit_send_uint32_pos(&lcd, 1, 5, 1); 
    for( ;; )
    {
        vTaskSuspend( xHandle_3 );
        vTaskSuspend( xHandle_4 );
        uxBits = xEventGroupGetBits( xEventGroup );
        if(( uxBits & ( PASS_COMPLETE ) ) != ( PASS_COMPLETE )){
            if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15)){
                lcd_4bit_send_string_pos(&lcd, 2, 1, str);
                xSemaphoreGive(LCD_Semaphore);
            }
            keypad_get_value(&keypad, &value);
            if (value != NO_KEY){
                if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15)){
                    lcd_4bit_send_char_data_pos(&lcd, 2, (num+12), value);
                    xSemaphoreGive(LCD_Semaphore);
                }
                xQueueSend( xQueuePass, &value,( TickType_t ) 10 );
                num++;
            }
            if(num == 5){
                uxBits = xEventGroupSetBits(
                            xEventGroup,    /* The event group being updated. */
                            PASS_COMPLETE );/* The bits being set. */
            }  
        }
          
        vTaskDelay(50);
    }
}

void vTaskCheckPass( void * pvParameters )
{
    uint8 password[] = PASSWORD;
    uint8 str_correct[] = "Correct password";
    uint8 str_wrong[]   = "Wrong password !";
    uint8 itr = 0;
    uint8 correct = 0;
    uint8 value;
    uint8 check = 1;
    //lcd_4bit_send_uint32_pos(&lcd, 1, 6, 2); 
    for( ;; ){
        
        if( ( uxBits & ( PASS_COMPLETE ) ) == ( PASS_COMPLETE ) ){
            /* Both bit 0 and bit 4 remained set when the function returned. */
            xQueueReceive( xQueuePass, &( value ), ( TickType_t ) 10 );
            if (value == password[itr]){
              correct++;  
            }
            else{
                check = 0;
                correct = 0; 
                //uxBits = xEventGroupClearBits(
                //              xEventGroup,    /* The event group being updated. */
                //              PASS_CORRECT );/* The bits being set. */
            }
            
            itr++;
 
        }
        else
        {
            /* Neither bit 0 nor bit 4 remained set.  It might be that a task
            was waiting for both of the bits to be set, and the bits were cleared
            as the task left the Blocked state. */
        }
        if(correct == 5){
            if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15)){
                lcd_4bit_send_string_pos(&lcd, 3, 1, str_correct);
                xSemaphoreGive(LCD_Semaphore);
            }
            correct = 0;    
                uxBits = xEventGroupSetBits(
                              xEventGroup,    /* The event group being updated. */
                              PASS_CORRECT );/* The bits being set. */
                uxBits = xEventGroupSetBits(
                              xEventGroup,    /* The event group being updated. */
                              PASS_COMPLETE );/* The bits being set. */
                uxBits = xEventGroupSetBits(
                              xEventGroup,    /* The event group being updated. */
                              EQU_REQUEST );/* The bits being set. */
                vTaskResume( xHandle_3 );
                vTaskSuspend( xHandle_1 );
                vTaskSuspend( xHandle_2 );
        }
        else if ((check == 0)){
        //else if ((check == 0) && (itr == 5)){
            if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15)){
                lcd_4bit_send_string_pos(&lcd, 3, 1, str_wrong);
                xSemaphoreGive(LCD_Semaphore);
            }
            uxBits = xEventGroupClearBits(
                    xEventGroup,    /* The event group being updated. */
                    PASS_CORRECT );/* The bits being set. */
            vTaskSuspend( xHandle_2 );
        }
    }
        
        vTaskDelay(50);
    
}

void vTaskGetEq( void * pvParameters )
{
    uint32 operands;
    uint8 operations;
    uint8 counter = 0;
    uint8 str_enterEq[]   = "Enter Equation";
    uint8 str_startEq[]   = "";
    uint8 str_space[]   = "                    ";
    for( ;; )
    {
        
        if(( uxBits & ( PASS_CORRECT ) ) == ( PASS_CORRECT )){
            //lcd_4bit_send_uint32_pos(&lcd, 4, 1, 1);
            if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15)){
                //if(( uxBits & ( EQU_REQUEST ) ) == ( EQU_REQUEST )){
                if(( counter ) == ( 0 )){    
                    lcd_4bit_send_string_pos(&lcd, 2, 1, str_space);
                    lcd_4bit_send_string_pos(&lcd, 3, 1, str_space);
                    lcd_4bit_send_string_pos(&lcd, 4, 1, str_space);
                    lcd_4bit_send_string_pos(&lcd, 1, 1, str_enterEq);
                    lcd_4bit_send_string_pos(&lcd, 2, 1, str_startEq);
                    uxBits = xEventGroupClearBits(
                                xEventGroup,    /* The event group being updated. */
                                EQU_REQUEST );/* The bits being set. */                    
                }
                
                //calculator_program_one_operation();
                //calculator_program();
                
                get_operand(&operands, &operations);
                xSemaphoreGive(LCD_Semaphore);
            }

            xQueueSend( xQueueOperand, &operands,( TickType_t ) 10 );
            xQueueSend( xQueueOperation, &operations,( TickType_t ) 10 );
            if((operations == '=') || (counter >= 8)){
                //operands = '#';
                //operations = '#';
                //xQueueSend( xQueueOperand, &operands,( TickType_t ) 10 );
                //xQueueSend( xQueueOperation, &operations,( TickType_t ) 10 );
                counter = 0;
                uxBits = xEventGroupSetBits(
                              xEventGroup,    /* The event group being updated. */
                              EQU_COMPLETE );/* The bits being set. */
                vTaskResume( xHandle_4 );
                vTaskSuspend( xHandle_3 );
            }
            else {counter++;}

        }
        vTaskDelay(50);
    }
}

void vTaskCalcEq( void * pvParameters )
{
    uint32 operands[9];
    uint8 operations[9];
    uint8 counter = 0;
    uint8 value = 0;
    uint8 counter_logic = 0;
    uint8 done_operation = 0;
    uint8 done[] = "Done";
    for( ;; )
    {
        
        if(( uxBits & ( PASS_CORRECT | EQU_COMPLETE ) ) == ( PASS_CORRECT | EQU_COMPLETE)){
            
            for(counter = 0; counter < 8; counter++){
                //lcd_4bit_send_uint32_pos(&lcd, 4, 1, counter);
                xQueueReceive( xQueueOperand, &(operands[counter]),( TickType_t ) 10 );
                xQueueReceive( xQueueOperation, &(operations[counter]),( TickType_t ) 10 );
                if(operations[counter]== '='){
                    operands[counter+1] = '#';
                    operations[counter+1] = '#';
                    done_operation = 0;
                    break;
                }
                else { }
            }

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

            if (pdTRUE == xSemaphoreTake(LCD_Semaphore,15)){
                lcd_4bit_send_uint32(&lcd, operands[0]);
                lcd_4bit_send_string_pos(&lcd, 3, 1, done);
                xSemaphoreGive(LCD_Semaphore);
            }
            
            while( '#' != value){
                keypad_get_value(&keypad, &value);
            }
            value = 0;
            uxBits = xEventGroupClearBits(
                              xEventGroup,    /* The event group being updated. */
                              EQU_COMPLETE );/* The bits being set. */
            //uxBits = xEventGroupSetBits(
            //                  xEventGroup,    /* The event group being updated. */
            //                  EQU_REQUEST );/* The bits being set. */
            vTaskResume( xHandle_3 );
            vTaskSuspend( xHandle_4 );
        }
        
        vTaskDelay(200);
    }
}

/* Function that creates a task. */
void vOtherFunction( void )
{
BaseType_t xReturned;

    /* Create the task, storing the handle. */

    xReturned = xTaskCreate(
                    vTaskGetPass,       /* Function that implements the task. */
                    "Task 1",        /* Text name for the task. */
                    250,             /* Stack size in words, not bytes. */
                    NULL,    /* Parameter passed into the task. */
                    9,               /* Priority at which the task is created. */
                    &xHandle_1 );      /* Used to pass out the created task's handle. */
    
    xReturned = xTaskCreate(
                    vTaskCheckPass,       /* Function that implements the task. */
                    "Task 2",        /* Text name for the task. */
                    250,             /* Stack size in words, not bytes. */
                    NULL,    /* Parameter passed into the task. */
                    8,               /* Priority at which the task is created. */
                    &xHandle_2 );      /* Used to pass out the created task's handle. */
    
    xReturned = xTaskCreate(
                    vTaskGetEq,       /* Function that implements the task. */
                    "Task 3",        /* Text name for the task. */
                    200,             /* Stack size in words, not bytes. */
                    NULL,    /* Parameter passed into the task. */
                    7,               /* Priority at which the task is created. */
                    &xHandle_3 );      /* Used to pass out the created task's handle. */

    xReturned = xTaskCreate(
                    vTaskCalcEq,       /* Function that implements the task. */
                    "Task 4",        /* Text name for the task. */
                    250,             /* Stack size in words, not bytes. */
                    NULL,    /* Parameter passed into the task. */
                    6,               /* Priority at which the task is created. */
                    &xHandle_4 );      /* Used to pass out the created task's handle. */
  
    LCD_Semaphore = xSemaphoreCreateMutex();
    Pass_Mutex = xSemaphoreCreateMutex();
    xQueuePass = xQueueCreate( 5, sizeof( unsigned char ) );
    xQueueOperand = xQueueCreate( 8, sizeof( uint32 ) );
    xQueueOperation = xQueueCreate( 8, sizeof( uint8 ) );
    xEventGroup = xEventGroupCreate();
}

Std_ReturnType application_initialize(void){
    Std_ReturnType ret = E_OK;
    //INTERRUPT_GlobalInterruptEnable();
    //ret |= hal_led_initialize(&led1); 
    //ret |= hal_led_initialize(&led2); 
    //ret |= hal_led_initialize(&led3); 
    ret |= lcd_4bit_intialize(&lcd);
    //ret |= ADC_Init(&adc_obj);
    //ret |= ADC_Init(&adc_obj_2);
    ret |= keypad_initialize(&keypad);
    //ret |= hal_button_initialize(&button);
    //ret |= hal_button_initialize(&button_T0);
    //ret |= hal_seven_segement_intialize(&segment);
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

void get_operand(uint32 *operand, uint8 *operation){
    uint8 get_keypad = NO_KEY;
    uint8 counter = 0;
    uint8 arr[10];
    uint8 condition = 1;
    while(condition){
       keypad_get_value(&keypad, &get_keypad);
       if (get_keypad != NO_KEY){
           lcd_4bit_send_char_data(&lcd, get_keypad); 
            switch(get_keypad){
                case NO_KEY:
                    break;
                case '#':
                    condition = 0;
                    arr[counter++] = '\0';
                    *operation = '#';
                    break;
                 case '=':
                    condition = 0;
                    arr[counter++] = '\0';
                    *operation = '=';
                    break;
                 case '*':
                    condition = 0;
                    arr[counter++] = '\0';
                    *operation = '*';
                    break;
                 case '/':
                    condition = 0;
                    arr[counter++] = '\0';
                    *operation = '/';
                    break;
                 case '+':
                    condition = 0;
                    arr[counter++] = '\0';
                    *operation = '+';
                    break;
                 case '-':
                    condition = 0;
                    arr[counter++] = '\0';
                    *operation = '-';
                    break;
                default:
                    arr[counter++] = get_keypad;  
                    get_keypad = NO_KEY;
            }
       
       }
    }
    convert_string_to_uint32(arr, operand);
}

void drop_array_uint8_ele(uint8 *ptr, uint8 ele_index, uint8 array_max_index){
    uint8 index = 0;
    for(index = ele_index; index <= array_max_index; index++){
        ptr[index] = ptr[index+1];
    }
    //ptr[array_max_index] = '#';
}

void drop_array_uint32_ele(uint32 *ptr, uint8 ele_index, uint8 array_max_index){
    uint8 index = 0;
    for(index = ele_index; index <= array_max_index; index++){
        ptr[index] = ptr[index+1];
    }
    //ptr[array_max_index] = '#';
}

void calculator_program(void){
    uint32 operands[9];
    uint8 operations[9];
    uint8 counter = 0;
    uint8 counter_logic = 0;
    uint8 done_operation = 0;
    uint8 done[] = "Done";
    //uint8 str[10];
    //uint8 clac[] = " Calc:  ";
    //uint8 res[] = "Result: ";
    //lcd_4bit_send_command(&lcd, _LCD_CLEAR);
    //lcd_4bit_send_string_pos(&lcd, 1, 1, clac);
    for(counter = 0; counter < 8; counter++){
        get_operand(&(operands[counter]), &(operations[counter]));
        //lcd_4bit_send_uint32_pos(&lcd, 4, 1, operands[counter]);
        if(operations[counter]== '='){
            operands[counter+1] = '#';
            operations[counter+1] = '#';
            break;
        }
        else {/* DO NOTHING */}
    }
    //lcd_4bit_send_uint32_pos(&lcd, 4, 1, operands[0]);
    //lcd_4bit_send_uint32_pos(&lcd, 4, 6, operands[1]);
    //lcd_4bit_send_uint32_pos(&lcd, 4, 11, operands[2]);
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
    //convert_uint32_to_string(operands[0], str);
    //lcd_4bit_send_string(&lcd, str);
    //lcd_4bit_send_string_pos(&lcd, 2, 1, str);
    
    lcd_4bit_send_uint32(&lcd, operands[0]);
    lcd_4bit_send_string_pos(&lcd, 3, 1, done);
    _delay_ms(2000);
}

void calculator_program_one_operation(void){
    uint32 first_operand = 0;
    uint8 first_operation = 0;
    get_operand(&first_operand, &first_operation);
    uint32 second_operand = 0;
    uint8 second_operation = 0;
    get_operand(&second_operand, &second_operation);
    uint32 result = 0;
    //uint8 str[10];
    
    switch(first_operation){
        case '*':
            result = first_operand * second_operand;
            //convert_uint32_to_string(result, str);
            if(second_operation == '='){
                //lcd_4bit_send_string_pos(&lcd, 2, 1, str);
                lcd_4bit_send_uint32(&lcd,result);
            }
            break;
        case '/':
            result = (uint32)first_operand / (uint32)second_operand;
            //convert_uint32_to_string((uint32)result, str);
            if(second_operation == '='){
                //lcd_4bit_send_string_pos(&lcd, 2, 1, str);
                lcd_4bit_send_uint32(&lcd,result);
            }
            break;
        case '+':
            result = first_operand + second_operand;
            //convert_uint32_to_string(result, str);
            if(second_operation == '='){
                //lcd_4bit_send_string_pos(&lcd, 2, 1, str);
                lcd_4bit_send_uint32(&lcd,result);
            }
            break;
        case '-':
            result = first_operand - second_operand;
            //convert_uint32_to_string(result, str);
            if(second_operation == '='){
                //lcd_4bit_send_string_pos(&lcd, 2, 1, str);
                lcd_4bit_send_uint32(&lcd,result);
            }
            break;
        default:
            break;
    }
    _delay_ms(1000);
}
