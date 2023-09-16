/* 
 * File:   i2c_reg_cfg.h
 * Author: Hesham
 *
 * Created on August 6, 2023, 8:20 PM
 */

#ifndef I2C_REG_CFG_H
#define	I2C_REG_CFG_H

#define TWBRbits      (*((volatile uint8 *) 0x20))  


typedef struct {
        unsigned TWIE_bit             :1;
        unsigned                      :1;
        unsigned TWEN_bit             :1;
        unsigned TWWC_bit             :1;
        unsigned TWSTO_bit            :1;
        unsigned TWSTA_bit            :1;
        unsigned TWEA_bit             :1;
        unsigned TWINT_bit            :1;
    }TWCRbits_t;

#define TWCRbits      (*((volatile TWCRbits_t *) 0x56))  

    
typedef struct {
        unsigned TWPS_bits             :2;
        unsigned                       :1;
        unsigned TWS_bits              :5;
    }TWSRbits_t;
    
#define TWSRbits      (*((volatile TWSRbits_t *) 0x21))     
    

    
    
#define TWDRbits      (*((volatile uint8 *) 0x23))  

    
    
    
    
    
typedef struct {
        unsigned TWGCE_bit             :1;
        unsigned TWA_bits              :7;
    }TWARbits_t;

#define TWARbits      (*((volatile TWARbits_t *) 0x22))  



#endif	/* I2C_REG_CFG_H */

