/* 
 * File:   hal_usart.c
 * Author: Hesham
 *
 * Created on August 2, 2023, 8:51 PM
 */

#include "hal_usart.h"

static void (*USART_TxCompleteInterruptHandler)(void) = NULL;
static void (*USART_RxCompleteInterruptHandler)(void) = NULL;
static void (*USART_DataRegisterEmptyInterruptHandler)(void) = NULL;

static void USART_Baud_Rate_Configration(const usart_t *_usart);
static void USART_Transmission_Speed_Configration(const usart_t *_usart);
static void USART_Multi_processor_Communication_Configration(const usart_t *_usart);
static void USART_Data_Size_Configration(const usart_t *_usart);
static void USART_Operation_Mode_Configration(const usart_t *_usart);
static void USART_Parity_Mode_Configration(const usart_t *_usart);
static void USART_Stop_Bit_Configration(const usart_t *_usart);


Std_ReturnType EUSART_ASYNC_Init(const usart_t *_usart){
   Std_ReturnType ret = E_OK;
    if(NULL == _usart){
        ret = E_NOT_OK;
    }
    else{
        USART_RECEIVER_DISABLE();
        USART_TRANSMITTER_DISABLE();
        
        USART_Baud_Rate_Configration(_usart);
        
        USART_Transmission_Speed_Configration(_usart);
        
        USART_Multi_processor_Communication_Configration(_usart);
        
        USART_Data_Size_Configration(_usart);
        
        USART_Operation_Mode_Configration(_usart);
        
        USART_Parity_Mode_Configration(_usart);
        
        USART_Stop_Bit_Configration(_usart);
        
        
        USART_RECEIVER_ENABLE();
        USART_TRANSMITTER_ENABLE();
    } 
   return ret;
}

Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_usart){
   Std_ReturnType ret = E_OK;
    if(NULL == _usart){
        ret = E_NOT_OK;
    }
    else{
        
    } 
   return ret;
}

Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data){
   Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        
    } 
   return ret;
}
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data){
   Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        
    } 
   return ret;
}
Std_ReturnType EUSART_ASYNC_RX_Restart(void){
   Std_ReturnType ret = E_OK;
    
   
   return ret;
}

Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data){
   Std_ReturnType ret = E_OK;
    
   
   return ret;
}
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len){
   Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        
    } 
   return ret;
}
Std_ReturnType EUSART_ASYNC_WriteByteNonBlocking(uint8 _data){
   Std_ReturnType ret = E_OK;
    
   
   return ret;
}
Std_ReturnType EUSART_ASYNC_WriteStringNonBlocking(uint8 *_data, uint16 str_len){
   Std_ReturnType ret = E_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        
    } 
   return ret;
}

static void USART_Baud_Rate_Configration(const usart_t *_usart){
    //UCSRCbits.URSEL_bit = 0;
    UBRRHbits = (1 << 7) + (_usart->baud_rate >> 8);
    UBRRLbits = (uint8)_usart->baud_rate;
}

static void USART_Transmission_Speed_Configration(const usart_t *_usart){
    if(USART_ASYNCHRONOUS_MODE == _usart->operation_mode){
      switch(_usart->asynchronous_transmission_speed){
          case USART_NORMALTRANSMISSION_SPEED:
              USART_NORMAL_ASYNCHRONOUS_TRANSMISSION_SPEED();
              break;
          case USART_DOUBLETRANSMISSION_SPEED:
              USART_DOUBLE_ASYNCHRONOUS_TRANSMISSION_SPEED();
              break;
          default:
              USART_NORMAL_ASYNCHRONOUS_TRANSMISSION_SPEED();
        }  
    }
    else{/* DO NOTHING */}
    
}

static void USART_Multi_processor_Communication_Configration(const usart_t *_usart){
    switch(_usart->processor_communication){
          case USART_SINGLE_PROCESSOR_COMMUNICATION:
              USART_MULTI_PROCESSOR_COMMUNICATION_DISABLE();
              break;
          case USART_MULTI_PROCESSOR_COMMUNICATION:
              USART_MULTI_PROCESSOR_COMMUNICATION_ENABLE();
              break;
          default:
              USART_MULTI_PROCESSOR_COMMUNICATION_DISABLE();
    }  
}

static void USART_Data_Size_Configration(const usart_t *_usart){
    switch(_usart->data_size){
          case USART_DATA_FIVE_BITS:
              UCSRCbits.UCSZ_bits = USART_DATA_FIVE_BITS;
              UCSRBbits.UCSZ2_bit = 0;
              break;
          case USART_DATA_SIX_BITS:
              UCSRCbits.UCSZ_bits = USART_DATA_SIX_BITS;
              UCSRBbits.UCSZ2_bit = 0;
              break;
          case USART_DATA_SEVEN_BITS:
              UCSRCbits.UCSZ_bits = USART_DATA_SEVEN_BITS;
              UCSRBbits.UCSZ2_bit = 0;
              break;
          case USART_DATA_EIGHT_BITS:
              UCSRCbits.UCSZ_bits = USART_DATA_EIGHT_BITS;
              UCSRBbits.UCSZ2_bit = 0;
              break;
          case USART_DATA_NINE_BITS:
              UCSRCbits.UCSZ_bits = 3;
              UCSRBbits.UCSZ2_bit = 1;
              break;
          default:
              UCSRCbits.UCSZ_bits = USART_DATA_EIGHT_BITS;
              UCSRBbits.UCSZ2_bit = 0;
    }  
}

static void USART_Operation_Mode_Configration(const usart_t *_usart){
    switch(_usart->operation_mode){
          case USART_ASYNCHRONOUS_MODE:
              USART_ASYNCHRONOUS_OPERATION_MODE();
              break;
          case USART_SYNCHRONOUS_MODE:
              USART_SYNCHRONOUS_OPERATION_MODE();
              break;
          default:
              USART_ASYNCHRONOUS_OPERATION_MODE();
    }
}

static void USART_Parity_Mode_Configration(const usart_t *_usart){
    switch(_usart->parity_mode){
          case USART_PARITY_DIABLE:
              UCSRCbits.UPM_bits = USART_PARITY_DIABLE;
              break;
          case USART_EVEN_PARITY_MOOD:
              UCSRCbits.UPM_bits = USART_EVEN_PARITY_MOOD;
              break;
          case USART_ODD_PARITY_MOOD:
              UCSRCbits.UPM_bits = USART_ODD_PARITY_MOOD;
              break;
          default:
              UCSRCbits.UPM_bits = USART_PARITY_DIABLE;
    }
}

static void USART_Stop_Bit_Configration(const usart_t *_usart){
    switch(_usart->stop_bit_select){
          case USART_ONE_STOP_BIT_MODE:
              UCSRCbits.USBS_bit = USART_ONE_STOP_BIT_MODE;
              break;
          case USART_TWO_STOP_BIT_MODE:
              UCSRCbits.USBS_bit = USART_TWO_STOP_BIT_MODE;
              break;
          default:
              UCSRCbits.USBS_bit = USART_ONE_STOP_BIT_MODE;
    }
}