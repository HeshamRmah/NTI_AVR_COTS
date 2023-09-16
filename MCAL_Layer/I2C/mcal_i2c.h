/* 
 * File:   mcal_i2c.h
 * Author: Hesham
 *
 * Created on August 6, 2023, 8:27 PM
 */

#ifndef MCAL_I2C_H
#define	MCAL_I2C_H

/* ----------------- Includes -----------------*/
#include "i2c_reg_cfg.h"
#include "../mcal_std_types.h"
#include "../Interrupt/interrupt_config.h"
#include "../DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/


/* ----------------- Macro Functions Declarations -----------------*/
#define  I2C_INTERRUPT_CLEAR_FALGE()                       (TWCRbits.TWINT_bit = 1)
#define  I2C_GET_INTERRUPT_FALGE()                         (TWCRbits.TWINT_bit)

#define  I2C_START_CONDITION_ENABLE()                      (TWCRbits.TWSTA_bit = 1)
#define  I2C_START_CONDITION_DISABLE()                     (TWCRbits.TWSTA_bit = 0)

#define  I2C_SEND_STOP_CONDITION()                         (TWCRbits.TWSTO_bit = 1)

#define  I2C_ENABLE()                                      (TWCRbits.TWEN_bit = 1)
#define  I2C_DISABLE()                                     (TWCRbits.TWEN_bit = 0)

#define  I2C_INTERRUPT_ENABLE()                            (TWCRbits.TWIE_bit = 1)
#define  I2C_INTERRUPT_DISABLE()                           (TWCRbits.TWIE_bit = 0)

#define  I2C_GENERAL_CALL_RECOGNITION_ENABLE()             (TWARbits.TWGCE_bit = 1)
#define  I2C_GENERAL_CALL_RECOGNITION_DISABLE()            (TWARbits.TWGCE_bit = 0)

//#define  I2C_COLLISION_CLEAR_FLAG()                      (TWCRbits.TWWC_bit = 1)
#define  I2C_GET_COLLISION_FLAG_STATUS()                   (TWCRbits.TWWC_bit)

#define  I2C_ACKNOWLEDGE_BIT_ENABLE()                      (TWCRbits.TWEA_bit = 1)
#define  I2C_ACKNOWLEDGE_BIT_DISABLE()                     (TWCRbits.TWEA_bit = 0)

#define  I2C_GET_STATUS_CODE()                             (TWSRbits.TWS_bits)

/* ----------------- Data Type Declarations -----------------*/

typedef enum{
    I2C_PRESCALER_DIV_BY_1 = 0,
    I2C_PRESCALER_DIV_BY_4,
    I2C_PRESCALER_DIV_BY_16, 
    I2C_PRESCALER_DIV_BY_64
}i2c_bit_rate_prescaler_t;

typedef enum{
    I2C_POLLING_CHECK = 0,
    I2C_INTERRUPT_CHECK,
}i2c_alert_mode_t;

typedef enum{
    MASTER_TRANSMITTER_START_CONDITION_TRANSMITTED = 1,
    MASTER_TRANSMITTER_REPEATED_START_CONDITION_TRANSMITTED,
    MASTER_TRANSMITTER_CONTROL_WRITE_BYTE_TRANSMITTED_ACK_RECEIVED,
    MASTER_TRANSMITTER_CONTROL_WRITE_BYTE_TRANSMITTED_NOT_ACK_RECEIVED,
    MASTER_TRANSMITTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED,
    MASTER_TRANSMITTER_DATA_BYTE_TRANSMITTED_NOT_ACK_RECEIVED,
    MASTER_TRANSMITTER_ARBITRATION_LOST_IN_CONTROL_WRITE_BYTE_OR_DATA_BYTE,
}i2c_status_codes_master_transmitter_mode_t;

typedef enum{
    MASTER_RECEIVER_START_CONDITION_TRANSMITTED = 1,
    MASTER_RECEIVER_REPEATED_START_CONDITION_TRANSMITTED,
    MASTER_RECEIVER_ARBITRATION_LOST_IN_CONTROL_READ_BYTE_OR_NOT_ACK = 7,
    MASTER_RECEIVER_CONTROL_READ_BYTE_TRANSMITTED_ACK_RECEIVED,   
    MASTER_RECEIVER_CONTROL_READ_BYTE_TRANSMITTED_NOT_ACK_RECEIVED,        
    MASTER_RECEIVER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED,
    MASTER_RECEIVER_DATA_BYTE_TRANSMITTED_NOT_ACK_RECEIVED
}i2c_status_codes_master_receiver_mode_t;


typedef enum{
    SLAVE_RECEIVER_CONTROL_WRITE_BYTE_RECEIVED_ACK_TRANSMITTED = 12,
    SLAVE_RECEIVER_ARBITRATION_LOST_IN_CONTROL_BYTE_OR_ACK_TRANSMITTED,
    SLAVE_RECEIVER_GENERAL_CALL_ADDRESS_RECEIVED_ACK_RECEIVED,
    SLAVE_RECEIVER_ARBITRATION_LOST_GENERAL_CALL_ADDRESS_RECEIVED_ACK_RECEIVED,
    SLAVE_RECEIVER_PREVIOUSLY_ADDRESSED_WITH_CONTROL_BYTE_RECEIVED_ACK_RECEIVED,
    SLAVE_RECEIVER_PREVIOUSLY_ADDRESSED_WITH_CONTROL_BYTE_RECEIVED_NOT_ACK_RECEIVED,
    SLAVE_RECEIVER_PREVIOUSLY_ADDRESSED_WITH_GENERAL_CALL_DATA_RECEIVED_ACK_RECEIVED,
    SLAVE_RECEIVER_PREVIOUSLY_ADDRESSED_WITH_GENERAL_CALL_DATA_RECEIVED_NOT_ACK_RECEIVED,
    SLAVE_RECEIVER_STOP_CONDITION_OR_REPEATED_START_CONDITION_RECEIVED,
}i2c_status_codes_slave_receiver_mode_t;

typedef enum{
    SLAVE_TRANSMITTER_Q = 0,
    SLAVE_TRANSMITTER_,
}i2c_status_codes_slave_transmitter_mode_t;



typedef struct{
    void (*I2C_InterruptHandler)(void);
    i2c_alert_mode_t alert_mode;
    i2c_bit_rate_prescaler_t prescaler;
    uint8 bit_rate_factor;
    uint8 adress;
    uint8 status_code;
}i2c_t;


/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType I2C_Master_Init(const i2c_t *i2c_obj);
Std_ReturnType I2C_Slave_Init(const i2c_t *i2c_obj);
Std_ReturnType I2C_DeInit(const i2c_t *i2c_obj);

Std_ReturnType I2C_Master_Send_Start(i2c_t *i2c_obj);
Std_ReturnType I2C_Master_Send_Repeated_Start(i2c_t *i2c_obj);
Std_ReturnType I2C_Master_Send_Stop(const i2c_t *i2c_obj);

Std_ReturnType I2C_Master_Write_Polling(i2c_t *i2c_obj, uint8 i2c_data);
Std_ReturnType I2C_Slave_Write_Polling(i2c_t *i2c_obj, uint8 i2c_data);
Std_ReturnType I2C_Master_Read_Polling(i2c_t *i2c_obj, uint8 *i2c_data);
Std_ReturnType I2C_Slave_Read_Polling(i2c_t *i2c_obj, uint8 *i2c_data);

Std_ReturnType I2C_Master_Write_Interrupt(const i2c_t *i2c_obj, uint8 i2c_data);
Std_ReturnType I2C_Master_Read_Interrupt(const i2c_t *i2c_obj, uint8 *i2c_data);


#endif	/* MCAL_I2C_H */

