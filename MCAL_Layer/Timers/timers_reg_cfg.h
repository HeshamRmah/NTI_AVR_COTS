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
        unsigned TOIE1_bit             :1;
        unsigned OCIE1B_bit            :1;
        unsigned OCIE1A_bit            :1;
        unsigned TICIE1_bit            :1;
        unsigned                       :2;
    }TIMSKbits_t;

#define TIMSKbits      (*((volatile TIMSKbits_t *) 0x59))  
      
    
typedef struct {
        unsigned TOV0_bit              :1;
        unsigned OCF0_bit              :1;
        unsigned TOV1_bit              :1;
        unsigned OCF1B_bit             :1;
        unsigned OCF1A_bit             :1;
        unsigned ICF1_bit              :1;
        unsigned                       :2;
    }TIFRbits_t;

#define TIFRbits      (*((volatile TIFRbits_t *) 0x58)) 
    
/**************************************************************************************/    
    
    
typedef struct {
        unsigned WGM10_bit             :1;
        unsigned WGM11_bit             :1;
        unsigned FOC1B_bit             :1;
        unsigned FOC1A_bit             :1;
        unsigned COM1B_bits            :2;
        unsigned COM1A_bits            :2;
    }TCCR1Abits_t;

#define TCCR1Abits      (*((volatile TCCR1Abits_t *) 0x4F))     
    
    
typedef struct {
        unsigned CS_bits               :3;
        unsigned WGM12_bit             :1;
        unsigned WGM13_bit             :1;
        unsigned                       :1;
        unsigned ICES1_bit             :1;
        unsigned ICNC1_bit             :1;
    }TCCR1Bbits_t;

#define TCCR1Bbits      (*((volatile TCCR1Bbits_t *) 0x4E))   




#define TCNT1bits      (*((volatile uint16 *) 0x4C))   
    
    
#define OCR1Abits      (*((volatile uint16 *) 0x4A))       

    
#define OCR1Bbits      (*((volatile uint16 *) 0x48))   
    
    
#define ICR1bits      (*((volatile uint16 *) 0x46))  
   


#endif	/* TIMERS_REG_CFG_H */

