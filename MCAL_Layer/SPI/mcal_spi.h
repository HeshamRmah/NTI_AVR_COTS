/* 
 * File:   mcal_spi.h
 * Author: Hesham
 *
 * Created on August 3, 2023, 11:42 AM
 */

#ifndef MCAL_SPI_H
#define	MCAL_SPI_H

/* ----------------- Includes -----------------*/
#include "spi_reg_cfg.h"
#include "../mcal_std_types.h"
#include "../Interrupt/interrupt_config.h"
#include "../DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/

#define  SPI_DATA_ORDER_LSB_FIRST               1
#define  SPI_DATA_ORDER_MSB_FIRST               0

#define  SPI_MASTER_MODE                        1
#define  SPI_SLAVE_MODE                         0

//#define  SPI_CLOCK_POLARITY_RISING_FALLING_MODE        0
//#define  SPI_CLOCK_POLARITY_FALLING_RISING_MODE        1

//#define  SPI_CLOCK_PHASE_SAMPLE_SETUP_MODE             0
//#define  SPI_CLOCK_PHASE_SETUP_SAMPLE_MODE             1

#define  SPI_NORMAL_SPI_SPEED_BIT_MODE                 0
#define  SPI_DOUBLE_SPI_SPEED_BIT_MODE                 1

#define  SPI_COMLETE_CHECK_POLLING                    0
#define  SPI_COMLETE_CHECK_ITERRUPT                   1


/* ----------------- Macro Functions Declarations -----------------*/
#define  SPI_INTERRUPT_ENABLE()                     (SPCRbits.SPIE_bit = 1)
#define  SPI_INTERRUPT_DISABLE()                    (SPCRbits.SPIE_bit = 0)

#define  SPI_ENABLE()                               (SPCRbits.SPE_bit = 1)
#define  SPI_DISABLE()                              (SPCRbits.SPE_bit = 0)

#define  SPI_DATA_ORDER_LSB()                       (SPCRbits.DORD_bit = 1)
#define  SPI_DATA_ORDER_MSB()                       (SPCRbits.DORD_bit = 0)

#define  SPI_MASTER_MODE_SELECT()                   (SPCRbits.MSTR_bit = 1)
#define  SPI_SLAVE_MODE_SELECT()                    (SPCRbits.MSTR_bit = 0)

//#define  SPI_CLOCK_POLARITY_RISING_FALLING()        (SPCRbits.CPOL_bit = 0)
//#define  SPI_CLOCK_POLARITY_FALLING_RISING()        (SPCRbits.CPOL_bit = 1)

//#define  SPI_CLOCK_PHASE_SAMPLE_SETUP()             (SPCRbits.CPHA_bit = 0)
//#define  SPI_CLOCK_PHASE_SETUP_SAMPLE()             (SPCRbits.CPHA_bit = 1)

#define  SPI_DOUBLE_SPI_SPEED_BIT_ENABLE()          (SPSRbits.SPI2X_bit = 1)
#define  SPI_DOUBLE_SPI_SPEED_BIT_DISABLE()         (SPSRbits.SPI2X_bit = 0)



/* ----------------- Data Type Declarations -----------------*/

typedef enum{
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_4 = 0,
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_16,
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_64,        
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_128,
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_2,
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_8,
    SCK_EQUAL_OSCILLATOR_FREQUENCY_DIV_BY_32,
}spi_sck_clk_t;

typedef enum{
    SPI_SAMPLE_RISING_SETUP_FALLING = 0,
    SPI_SETUP_RISING_SAMPLE_FALLING,
    SPI_SAMPLE_FALLING_SETUP_RISING, 
    SPI_SETUP_FALLING_SAMPLE_RISING
}spi_mode_t;

typedef struct{
    pin_config_t MOSI;
    pin_config_t MISO;
    pin_config_t SCK;
    pin_config_t SS;
    void (* SPI_InterruptHandler)(void);
    spi_sck_clk_t SCK_Frequency;
    spi_mode_t SPI_Mode;
    uint8 Operation_mode;
    uint8 Complete_check;
    uint8 Data_order;
    
}SPI_Config;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType SPI_Init(const SPI_Config *Config);
Std_ReturnType SPI_DeInit(const SPI_Config *Config);
Std_ReturnType SPI_Send_Byte_POLLING(const SPI_Config *Config, const uint8 _data);
Std_ReturnType SPI_Read_Byte_POLLING(const SPI_Config *Config, uint8 *_data);
Std_ReturnType SPI_Send_Byte_Interrupt(const SPI_Config *Config, const uint8 _data);
Std_ReturnType SPI_Read_Byte_Interrupt(const SPI_Config *Config, uint8 *_data);



#endif	/* MCAL_SPI_H */

