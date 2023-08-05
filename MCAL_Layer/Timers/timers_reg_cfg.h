/* 
 * File:   timers_reg_cfg.h
 * Author: Hesham
 *
 * Created on August 4, 2023, 10:51 AM
 */

#ifndef TIMERS_REG_CFG_H
#define	TIMERS_REG_CFG_H

typedef struct {
        unsigned CS_bits               :3;
        unsigned WGM01_bit             :1;
        unsigned COM_bits              :2;
        unsigned WGM00_bit             :1;
        unsigned FOC0_bit              :1;
    }TCCR0bits_t;

#define TCCR0bits      (*((volatile TCCR0bits_t *) 0x53))  


#define TCNT0bits      (*((volatile uint8 *) 0x52)) 
    
#define OCR0bits       (*((volatile uint8 *) 0x5C))     
    
    
typedef struct {
        unsigned TOIE0_bit             :1;
        unsigned OCIE0_bit             :1;
        unsigned                       :6;
    }TIMSKbits_t;

#define TIMSKbits      (*((volatile TIMSKbits_t *) 0x59))      
    
    
typedef struct {
        unsigned TOV0_bit             :1;
        unsigned OCF0_bit             :1;
        unsigned                      :6;
    }TIFRbits_t;

#define TIFRbits      (*((volatile TIFRbits_t *) 0x58))      
    
    



#endif	/* TIMERS_REG_CFG_H */

