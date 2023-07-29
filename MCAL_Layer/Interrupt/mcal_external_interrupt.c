/* 
 * File:   mcal_external_interrupt.c
 * Author: Hesham
 *
 * Created on July 28, 2023, 12:37 PM
 */

#include "mcal_external_interrupt.h"

static void (*INT0_InterruptHandler)(void) = NULL;
static void (*INT1_InterruptHandler)(void) = NULL;
static void (*INT2_InterruptHandler)(void) = NULL;

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_SetInterruptMode(const interrupt_INTx_t *int_obj);

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);


void __vector_2(void) __attribute__((signal , used));

void INT0_ISR(void){
    if(INT0_InterruptHandler){ INT0_InterruptHandler(); }
    else{ /* Nothing */ }
}

void INT1_ISR(void){
    if(INT1_InterruptHandler){ INT1_InterruptHandler(); }
    else{ /* Nothing */ }
}

void INT2_ISR(void){
    if(INT2_InterruptHandler){ INT2_InterruptHandler(); }
    else{ /* Nothing */ }
}


Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        ret = Interrupt_INTx_Disable(int_obj);
        
        ret |= Interrupt_INTx_SetInterruptMode(int_obj);
        
        /* Set the DIO Pins */
        ret |= dio_pin_intialize(&(int_obj->pin_obj));
        
        /* set function callback */
        ret |= Interrupt_INTx_SetInterruptHandler(int_obj);
        
        ret |= Interrupt_INTx_Enable(int_obj);
        
    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                INTERRUPT_GlobalInterruptEnable();
                EXT_INT0_InterruptEnable(); 
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                INTERRUPT_GlobalInterruptEnable();
                EXT_INT1_InterruptEnable(); 
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                INTERRUPT_GlobalInterruptEnable();
                EXT_INT2_InterruptEnable(); 
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_InterruptDisable();
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_InterruptDisable();
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_InterruptDisable();
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                INT0_InterruptHandler = int_obj->EXT_InterruptHandler;
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                INT1_InterruptHandler = int_obj->EXT_InterruptHandler;
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                INT2_InterruptHandler = int_obj->EXT_InterruptHandler;
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_SetInterruptMode(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->mode){
            case INT0_LOW_LEVEL:
                MCUCRbits->ISC00_bit = 0;
                MCUCRbits->ISC01_bit = 0;
                break;
            case INT0_LOGICAL_CHANGE:
                MCUCRbits->ISC00_bit = 1;
                MCUCRbits->ISC01_bit = 0;
                break;
            case INT0_FALLING_EDGE:
                MCUCRbits->ISC00_bit = 0;
                MCUCRbits->ISC01_bit = 1;
                break;
            case INT0_RISING_EDGE:
                MCUCRbits->ISC00_bit = 1;
                MCUCRbits->ISC01_bit = 1;
                break;
            
            case INT1_LOW_LEVEL:
                MCUCRbits->ISC10_bit = 0;
                MCUCRbits->ISC11_bit = 0;
                break;
            case INT1_LOGICAL_CHANGE:
                MCUCRbits->ISC10_bit = 1;
                MCUCRbits->ISC11_bit = 0;
                break;
            case INT1_FALLING_EDGE:
                MCUCRbits->ISC10_bit = 0;
                MCUCRbits->ISC11_bit = 1;
                break;
            case INT1_RISING_EDGE:
                MCUCRbits->ISC10_bit = 1;
                MCUCRbits->ISC11_bit = 1;
                break;
            
            case INT2_FALLING_EDGE:
                MCUCSRbits->ISC2_bit = 0;
                break;
            case INT2_RISING_EDGE:
                MCUCSRbits->ISC2_bit = 1;
                break;
        }
    }
    return ret;
}