/* 
 * File:   interrupt_reg_cfg.h
 * Author: Hesham
 *
 * Created on August 1, 2023, 9:28 PM
 */

#ifndef INTERRUPT_REG_CFG_H
#define	INTERRUPT_REG_CFG_H

typedef struct {
        unsigned MUX_bits              :5;
        unsigned ADLAR_bit             :1;
        unsigned REFS_bits             :2;
    }ADMUXbits_t;

#define ADMUXbits      (*((volatile ADMUXbits_t *) 0x27))
 
    
typedef struct {
        unsigned ADPS_bits             :3;
        unsigned ADIE_bit              :1;
        unsigned ADIF_bit              :1;
        unsigned ADATE_bit             :1;
        unsigned ADSC_bit              :1;
        unsigned ADEN_bit              :1;
    }ADCSRAbits_t;

#define ADCSRAbits      (*((volatile ADCSRAbits_t *) 0x26))    



#define ADCLbits      (*((volatile uint8 *) 0x24)) 

#define ADCHbits      (*((volatile uint8 *) 0x25)) 


typedef struct {
        unsigned PSR10_bit             :1;
        unsigned PSR2_bit              :1;
        unsigned PUD_bit               :1;
        unsigned ACME_bit              :1;
        unsigned                       :1;
        unsigned ADTS_bits             :3;
    }SFIORbits_t;

#define SFIORbits      (*((volatile SFIORbits_t *) 0x50))  
    
    
  
#endif	/* INTERRUPT_REG_CFG_H */

