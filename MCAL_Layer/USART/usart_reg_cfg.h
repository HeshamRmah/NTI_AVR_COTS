/* 
 * File:   usart_reg_cfg.h
 * Author: Hesham
 *
 * Created on August 2, 2023, 8:53 PM
 */

#ifndef USART_REG_CFG_H
#define	USART_REG_CFG_H


#define UDRbits      (*((volatile uint8 *) 0x2C))
    
 
typedef struct {
        unsigned MPCM_bit              :1;
        unsigned U2X_bit               :1;
        unsigned PE_bit                :1;
        unsigned DOR_bit               :1;
        unsigned FE_bit                :1;
        unsigned UDRE_bit              :1;
        unsigned TXC_bit               :1;
        unsigned RXC_bit               :1;
    }UCSRAbits_t;

#define UCSRAbits      (*((volatile UCSRAbits_t *) 0x2B))
 
     
typedef struct {
        unsigned TXB8_bit              :1;
        unsigned RXB8_bit              :1;
        unsigned UCSZ2_bit             :1;
        unsigned TXEN_bit              :1;
        unsigned RXEN_bit              :1;
        unsigned UDRIE_bit             :1;
        unsigned TXCIE_bit             :1;
        unsigned RXCIE_bit             :1;
    }UCSRBbits_t;

#define UCSRBbits      (*((volatile UCSRBbits_t *) 0x2A))
    
    
typedef struct {
        unsigned UCPOL_bit             :1;
        unsigned UCSZ_bits             :2;
        unsigned USBS_bit              :1;
        unsigned UPM_bits              :2;
        unsigned UMSEL_bit             :1;
        unsigned URSEL_bit             :1;
    }UCSRCbits_t;

#define UCSRCbits      (*((volatile UCSRCbits_t *) 0x40))


#define UBRRLbits      (*((volatile uint8 *) 0x29))    
#define UBRRHbits      (*((volatile uint8 *) 0x40))      

typedef struct {
        unsigned UBRR_bits             :4;
        unsigned                       :3;
        unsigned URSEL_bit             :1;
    }UBRRHbits_t;

//#define UBRRHbits      (*((volatile UBRRHbits_t *) 0x40))    


#endif	/* USART_REG_CFG_H */

