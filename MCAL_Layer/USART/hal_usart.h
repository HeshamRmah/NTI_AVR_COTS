/* 
 * File:   hal_usart.h
 * Author: Hesham
 *
 * Created on August 2, 2023, 8:51 PM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H

/* ----------------- Includes -----------------*/
#include "usart_reg_cfg.h"
#include "../mcal_std_types.h"
#include "../Interrupt/interrupt_config.h"
#include "../DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/
#define USART_ASYNCHRONOUS_MODE           0
#define USART_SYNCHRONOUS_MODE            1

#define USART_NORMALTRANSMISSION_SPEED    0
#define USART_DOUBLETRANSMISSION_SPEED    1

#define USART_SINGLE_PROCESSOR_COMMUNICATION     0
#define USART_MULTI_PROCESSOR_COMMUNICATION      1

#define USART_ONE_STOP_BIT_MODE                  0
#define USART_TWO_STOP_BIT_MODE                  1

/* ----------------- Macro Functions Declarations -----------------*/

#define USART_MULTI_PROCESSOR_COMMUNICATION_DISABLE()    (UCSRAbits.MPCM_bit = 0)
#define USART_MULTI_PROCESSOR_COMMUNICATION_ENABLE()     (UCSRAbits.MPCM_bit = 1)

#define USART_NORMAL_ASYNCHRONOUS_TRANSMISSION_SPEED()   (UCSRAbits.U2X_bit = 0)
#define USART_DOUBLE_ASYNCHRONOUS_TRANSMISSION_SPEED()   (UCSRAbits.U2X_bit = 1)

#define USART_RX_COMPLETE_INTERRUPT_ENABLE()             (UCSRBbits.RXCIE_bit = 1)
#define USART_RX_COMPLETE_INTERRUPT_DIABLE()             (UCSRBbits.RXCIE_bit = 0)

#define USART_TX_COMPLETE_INTERRUPT_ENABLE()             (UCSRBbits.TXCIE_bit = 1)
#define USART_TX_COMPLETE_INTERRUPT_DIABLE()             (UCSRBbits.TXCIE_bit = 0)

#define USART_DATA_REGISTER_EMPTY_INTERRUPT_ENABLE()     (UCSRBbits.UDRIE_bit = 1)
#define USART_DATA_REGISTER_EMPTY_INTERRUPT_DIABLE()     (UCSRBbits.UDRIE_bit = 0)

#define USART_RECEIVER_ENABLE()                          (UCSRBbits.RXEN_bit = 1)
#define USART_RECEIVER_DISABLE()                         (UCSRBbits.RXEN_bit = 0)

#define USART_TRANSMITTER_ENABLE()                       (UCSRBbits.TXEN_bit = 1)
#define USART_TRANSMITTER_DISABLE()                      (UCSRBbits.TXEN_bit = 0)

#define USART_ASYNCHRONOUS_OPERATION_MODE()              (UCSRCbits.UMSEL_bit = 0)
#define USART_SYNCHRONOUS_OPERATION_MODE()               (UCSRCbits.UMSEL_bit = 1)

#define USART_ONE_STOP_BIT()                             (UCSRCbits.USBS_bit = 0)
#define USART_TWO_STOP_BIT()                             (UCSRCbits.USBS_bit = 1)

#define USART_CLOCK_POLARITY_TRANSMISSION_RISING_EDGE()  (UCSRCbits.UCPOL_bit = 0)
#define USART_CLOCK_POLARITY_TRANSMISSION_FALLING_EDGE() (UCSRCbits.UCPOL_bit = 1)

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    USART_PARITY_DIABLE = 0,
    USART_EVEN_PARITY_MOOD = 2,
    USART_ODD_PARITY_MOOD = 3,
}usart_parity_mode_t;

typedef enum{
    USART_DATA_FIVE_BITS = 0,
    USART_DATA_SIX_BITS,
    USART_DATA_SEVEN_BITS,
    USART_DATA_EIGHT_BITS,
    USART_DATA_NINE_BITS,        
}usart_data_size_t;

typedef struct{
    uint16 baud_rate;
    uint8 operation_mode;
    uint8 asynchronous_transmission_speed;
    uint8 processor_communication;
    uint8 stop_bit_select;
    uint8 clock_polarity;
    usart_parity_mode_t parity_mode;
    usart_data_size_t data_size;
    void (*USART_TxCompleteInterruptHandler)(void);
    void (*USART_RxCompleteInterruptHandler)(void);
    void (*USART_DataRegisterEmptyInterruptHandler)(void);
}usart_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType EUSART_ASYNC_Init(const usart_t *_usart);
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_usart);

Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_RX_Restart(void);

Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len);
Std_ReturnType EUSART_ASYNC_WriteByteNonBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringNonBlocking(uint8 *_data, uint16 str_len);

#endif	/* HAL_USART_H */

