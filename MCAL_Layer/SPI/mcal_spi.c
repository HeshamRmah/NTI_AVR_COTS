/* 
 * File:   mcal_spi.c
 * Author: Hesham
 *
 * Created on August 3, 2023, 11:42 AM
 */

#include "mcal_spi.h"

static void (* SPI_InterruptHandler)(void) = NULL;

static void SPI_Set_Mode(const SPI_Config *Config);
static void SPI_Set_SCK_CLK(const SPI_Config *Config);
static void SPI_Set_Operation_Mode(const SPI_Config *Config);
static void SPI_Complete_check_Configration(const SPI_Config *Config);
static void SPI_Set_Data_Order(const SPI_Config *Config);
static void SPI_Set_Interrupt_Handler(const SPI_Config *Config);
static void SPI_DIO_Pins_Configration(const SPI_Config *Config);

void __vector_12(void) __attribute__((signal , used));

void __vector_12(void){
    /* Clear Interrupt Flag */
    if(SPI_InterruptHandler){ SPI_InterruptHandler(); }
    else{ /* Nothing */ }
}

Std_ReturnType SPI_Init(const SPI_Config *Config){
    Std_ReturnType ret = E_OK;
    if(NULL == Config){
        ret = E_NOT_OK;
    }
    else{
        SPI_DISABLE();
        
        SPI_INTERRUPT_DISABLE();
        
        SPI_Set_Mode(Config);
        
        SPI_Set_SCK_CLK(Config);
        
        SPI_Set_Operation_Mode(Config);
        
        SPI_Complete_check_Configration(Config);
        
        SPI_Set_Data_Order(Config);
        
        SPI_Set_Interrupt_Handler(Config);
        
        SPI_DIO_Pins_Configration(Config);       
        
        SPI_ENABLE();        
    }
    return ret;
}

Std_ReturnType SPI_DeInit(const SPI_Config *Config){
    Std_ReturnType ret = E_OK;
    if(NULL == Config){
        ret = E_NOT_OK;
    }
    else{
        SPI_DISABLE();
        SPI_INTERRUPT_DISABLE();
    }
    return ret;
}

Std_ReturnType SPI_Send_Byte_POLLING(const SPI_Config *Config, const uint8 _data){
    Std_ReturnType ret = E_OK;
    if(NULL == Config){
        ret = E_NOT_OK;
    }
    else{
        SPDRbits = _data;
        while(!(SPSRbits.SPIF_bit)); /* Waiting to transmit */
        //SPSRbits.SPIF_bit.SSPIF = 0;
    }
    return ret;
}

Std_ReturnType SPI_Read_Byte_POLLING(const SPI_Config *Config, uint8 *_data){
    Std_ReturnType ret = E_OK;
    if(NULL == Config){
        ret = E_NOT_OK;
    }
    else{
        while(!(SPSRbits.SPIF_bit)); /* Receive not complete, SSPBUF is empty */
        *_data = SPDRbits;
    }
    return ret;
}

Std_ReturnType SPI_Send_Byte_Interrupt(const SPI_Config *Config, const uint8 _data){
    Std_ReturnType ret = E_OK;
    if(NULL == Config){
        ret = E_NOT_OK;
    }
    else{
        SPDRbits = _data;
    }
    return ret;
}

Std_ReturnType SPI_Read_Byte_Interrupt(const SPI_Config *Config, uint8 *_data){
    Std_ReturnType ret = E_OK;
    if(NULL == Config){
        ret = E_NOT_OK;
    }
    else{
        *_data = SPDRbits;
    }
    return ret;
}


static void SPI_Set_Mode(const SPI_Config *Config){
    SPCRbits.CPHA_CPOL_bits = Config->SPI_Mode;
}

static void SPI_Set_SCK_CLK(const SPI_Config *Config){
    switch(Config->SCK_Frequency){
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_4:
            SPCRbits.SPR0_bit = 0;
            SPCRbits.SPR0_bit = 0;
            SPSRbits.SPI2X_bit = 0;
            break;
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_16:
            SPCRbits.SPR0_bit = 1;
            SPCRbits.SPR0_bit = 0;
            SPSRbits.SPI2X_bit = 0;
            break;    
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_64:
            SPCRbits.SPR0_bit = 0;
            SPCRbits.SPR0_bit = 1;
            SPSRbits.SPI2X_bit = 0;
            break;    
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_128:
            SPCRbits.SPR0_bit = 1;
            SPCRbits.SPR0_bit = 1;
            SPSRbits.SPI2X_bit = 0;
            break;    
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_2:
            SPCRbits.SPR0_bit = 0;
            SPCRbits.SPR0_bit = 0;
            SPSRbits.SPI2X_bit = 1;
            break;    
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_8:
            SPCRbits.SPR0_bit = 1;
            SPCRbits.SPR0_bit = 0;
            SPSRbits.SPI2X_bit = 1;
            break;    
        case SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_32:
            SPCRbits.SPR0_bit = 0;
            SPCRbits.SPR0_bit = 1;
            SPSRbits.SPI2X_bit = 1;
            break;    
        default:
            SPCRbits.SPR0_bit = 0;
            SPCRbits.SPR0_bit = 0;
            SPSRbits.SPI2X_bit = 0;

    }
}

static void SPI_Set_Operation_Mode(const SPI_Config *Config){
    switch(Config->Operation_mode){
        case SPI_MASTER_MODE:
            SPI_MASTER_MODE_SELECT();
            break;
        case SPI_SLAVE_MODE:
            SPI_SLAVE_MODE_SELECT();
            break;
        default:
            SPI_MASTER_MODE_SELECT();
    }
        
}

static void SPI_Complete_check_Configration(const SPI_Config *Config){
    if(SPI_COMLETE_CHECK_ITERRUPT == Config->Complete_check){
        INTERRUPT_GlobalInterruptEnable();
        SPI_INTERRUPT_ENABLE();
    }
    else if(SPI_COMLETE_CHECK_POLLING == Config->Complete_check){
        SPI_INTERRUPT_DISABLE();
    }
    else{ /* DO NOTHING */}
}


static void SPI_Set_Data_Order(const SPI_Config *Config){
    if(SPI_DATA_ORDER_LSB_FIRST == Config->Data_order){
        SPI_DATA_ORDER_LSB();
    }
    else if(SPI_DATA_ORDER_MSB_FIRST == Config->Data_order){
        SPI_DATA_ORDER_MSB();
    }
    else{ /* DO NOTHING */}
}

static void SPI_Set_Interrupt_Handler(const SPI_Config *Config){
    if(Config->SPI_InterruptHandler){
        SPI_InterruptHandler = Config->SPI_InterruptHandler;
    }
    else { /* DO NOTHING */}
}


static void SPI_DIO_Pins_Configration(const SPI_Config *Config){
    switch(Config->Operation_mode){
        case SPI_MASTER_MODE:
            dio_pin_intialize(&(Config->MOSI));
            dio_pin_intialize(&(Config->SCK));
            dio_pin_intialize(&(Config->SS));
            break;
        case SPI_SLAVE_MODE:
            dio_pin_intialize(&(Config->MISO));
            break;
        default:
            dio_pin_intialize(&(Config->MOSI));
            dio_pin_intialize(&(Config->SCK));
            dio_pin_intialize(&(Config->SS));
    }
}