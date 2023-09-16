/* 
 * File:   mcal_i2c.c
 * Author: Hesham
 *
 * Created on August 6, 2023, 8:27 PM
 */


#include "mcal_i2c.h"

static void (*I2C_InterruptHandler)(void) = NULL;

static inline void I2C_Interrupt_Configurations(const i2c_t *i2c_obj);
static inline void I2C_Prescaler_Configurations(const i2c_t *i2c_obj);
static inline void I2C_Bit_Rate_Configurations(const i2c_t *i2c_obj);
static inline void I2C_Adress_Configurations(const i2c_t *i2c_obj);




Std_ReturnType I2C_Master_Init(const i2c_t *i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_DISABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        //I2C_GET_COLLISION_FLAG_STATUS();
        
        I2C_ACKNOWLEDGE_BIT_ENABLE();
        
        I2C_Interrupt_Configurations(i2c_obj);
        I2C_Prescaler_Configurations(i2c_obj);
        I2C_Bit_Rate_Configurations(i2c_obj);
        I2C_Adress_Configurations(i2c_obj);
        
        
        I2C_ENABLE();
        
    }
    return ret;
}

Std_ReturnType I2C_Slave_Init(const i2c_t *i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_DISABLE();
        
        I2C_Adress_Configurations(i2c_obj);
        
        I2C_ENABLE();
        
        I2C_ACKNOWLEDGE_BIT_ENABLE();

        I2C_INTERRUPT_CLEAR_FALGE();
        
    }
    return ret;
}

Std_ReturnType I2C_DeInit(const i2c_t *i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_DISABLE();
        I2C_INTERRUPT_DISABLE();
    }
    return ret;
}



Std_ReturnType I2C_Master_Send_Start(i2c_t *i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_START_CONDITION_ENABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        while(!I2C_GET_INTERRUPT_FALGE());
        if(MASTER_TRANSMITTER_START_CONDITION_TRANSMITTED == I2C_GET_STATUS_CODE()){
            i2c_obj->status_code = MASTER_TRANSMITTER_START_CONDITION_TRANSMITTED;
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
}


Std_ReturnType I2C_Master_Send_Repeated_Start(i2c_t *i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_START_CONDITION_ENABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        while(!I2C_GET_INTERRUPT_FALGE());
        if(MASTER_TRANSMITTER_REPEATED_START_CONDITION_TRANSMITTED == I2C_GET_STATUS_CODE()){
            i2c_obj->status_code = MASTER_TRANSMITTER_REPEATED_START_CONDITION_TRANSMITTED;
        }
        else{
            i2c_obj->status_code = I2C_GET_STATUS_CODE();
            ret = E_NOT_OK;
        }
    }
    return ret;
}


Std_ReturnType I2C_Master_Send_Stop(const i2c_t *i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_SEND_STOP_CONDITION();
        I2C_INTERRUPT_CLEAR_FALGE();
    }
    return ret;
}



Std_ReturnType I2C_Master_Write_Polling(i2c_t *i2c_obj, uint8 i2c_data){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        TWDRbits = i2c_data;
        I2C_START_CONDITION_DISABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        while(!I2C_GET_INTERRUPT_FALGE());
        if(MASTER_TRANSMITTER_CONTROL_WRITE_BYTE_TRANSMITTED_ACK_RECEIVED == I2C_GET_STATUS_CODE()){
            i2c_obj->status_code = MASTER_TRANSMITTER_CONTROL_WRITE_BYTE_TRANSMITTED_ACK_RECEIVED;
        }
        else if(MASTER_TRANSMITTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED == I2C_GET_STATUS_CODE()){
            i2c_obj->status_code = MASTER_TRANSMITTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED;
        }
        else{
            i2c_obj->status_code = I2C_GET_STATUS_CODE();
            ret = E_NOT_OK;
        }
        
    }
    return ret;
}

Std_ReturnType I2C_Slave_Write_Polling(i2c_t *i2c_obj, uint8 i2c_data){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        I2C_START_CONDITION_DISABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        
    }
    return ret;
}

Std_ReturnType I2C_Master_Read_Polling(i2c_t *i2c_obj, uint8 *i2c_data){
    Std_ReturnType ret = E_OK;
    if((NULL == i2c_obj) || (NULL == i2c_data)){
        ret = E_NOT_OK;
    }
    else{
        /*
        I2C_ENABLE();
        I2C_START_CONDITION_ENABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        while(!I2C_GET_INTERRUPT_FALGE());
        */
        I2C_INTERRUPT_CLEAR_FALGE();
        while(!I2C_GET_INTERRUPT_FALGE());
        *i2c_data = TWDRbits;
        if(MASTER_RECEIVER_CONTROL_READ_BYTE_TRANSMITTED_ACK_RECEIVED == I2C_GET_STATUS_CODE()){
            i2c_obj->status_code = MASTER_RECEIVER_CONTROL_READ_BYTE_TRANSMITTED_ACK_RECEIVED;
        }
        else{
            i2c_obj->status_code = I2C_GET_STATUS_CODE();
            ret = E_NOT_OK;
        }
        
        
    }
    return ret;
}

Std_ReturnType I2C_Slave_Read_Polling(i2c_t *i2c_obj, uint8 *i2c_data){
    Std_ReturnType ret = E_OK;
    if((NULL == i2c_obj) || (NULL == i2c_data)){
        ret = E_NOT_OK;
    }
    else{
        I2C_ENABLE();
        I2C_INTERRUPT_CLEAR_FALGE();
        while(!I2C_GET_INTERRUPT_FALGE());
        *i2c_data = TWDRbits;
        if(SLAVE_RECEIVER_CONTROL_WRITE_BYTE_RECEIVED_ACK_TRANSMITTED == I2C_GET_STATUS_CODE()){
            i2c_obj->status_code = SLAVE_RECEIVER_CONTROL_WRITE_BYTE_RECEIVED_ACK_TRANSMITTED;
        }
        else{
            i2c_obj->status_code = I2C_GET_STATUS_CODE();
            ret = E_NOT_OK;
        }
        
    }
    return ret;
}


Std_ReturnType I2C_Master_Write_Interrupt(const i2c_t *i2c_obj, uint8 i2c_data){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }
    else{
        
    }
    return ret;
}


Std_ReturnType I2C_Master_Read_Interrupt(const i2c_t *i2c_obj, uint8 *i2c_data){
    Std_ReturnType ret = E_OK;
    if((NULL == i2c_obj) || (NULL == i2c_data)){
        ret = E_NOT_OK;
    }
    else{
        
    }
    return ret;
}


static inline void I2C_Interrupt_Configurations(const i2c_t *i2c_obj){
    switch(i2c_obj->alert_mode){
        case I2C_POLLING_CHECK:
            I2C_INTERRUPT_DISABLE();
            break;
        case I2C_INTERRUPT_CHECK:
            if(i2c_obj->I2C_InterruptHandler){
                INTERRUPT_GlobalInterruptEnable();
                I2C_INTERRUPT_ENABLE();
                I2C_InterruptHandler = i2c_obj->I2C_InterruptHandler;
            }
            else { /* DO NOTHING */}
            break;
        default:
            I2C_INTERRUPT_DISABLE();
    }
}

static inline void I2C_Prescaler_Configurations(const i2c_t *i2c_obj){
    TWSRbits.TWPS_bits = i2c_obj->prescaler;
}

static inline void I2C_Bit_Rate_Configurations(const i2c_t *i2c_obj){
    TWBRbits = i2c_obj->bit_rate_factor;
}

static inline void I2C_Adress_Configurations(const i2c_t *i2c_obj){
    TWARbits.TWA_bits = i2c_obj->adress;
}










