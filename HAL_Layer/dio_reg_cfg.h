/* 
 * File:   dio_reg_cfg.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 7:50 PM
 */

#ifndef DIO_REG_CFG_H
#define	DIO_REG_CFG_H

#define PORTA      *((volatile uint8 *) 0x3B)

typedef struct {
        unsigned PORTA0                  :1;
        unsigned PORTA1                  :1;
        unsigned PORTA2                  :1;
        unsigned PORTA3                  :1;
        unsigned PORTA4                  :1;
        unsigned PORTA5                  :1;
        unsigned PORTA6                  :1;
        unsigned PORTA7                  :1;
    }PORTAbits_t;

#define PORTB      *((volatile uint8 *) 0x38)

typedef struct {
        unsigned PORTB0                  :1;
        unsigned PORTB1                  :1;
        unsigned PORTB2                  :1;
        unsigned PORTB3                  :1;
        unsigned PORTB4                  :1;
        unsigned PORTB5                  :1;
        unsigned PORTB6                  :1;
        unsigned PORTB7                  :1;
    }PORTBbits_t;
    
#define PORTC      *((volatile uint8 *) 0x35)

typedef struct {
        unsigned PORTC0                  :1;
        unsigned PORTC1                  :1;
        unsigned PORTC2                  :1;
        unsigned PORTC3                  :1;
        unsigned PORTC4                  :1;
        unsigned PORTC5                  :1;
        unsigned PORTC6                  :1;
        unsigned PORTC7                  :1;
    }PORTCbits_t;
    
 #define PORTD      *((volatile uint8 *) 0x32)

typedef struct {
        unsigned PORTD0                  :1;
        unsigned PORTD1                  :1;
        unsigned PORTD2                  :1;
        unsigned PORTD3                  :1;
        unsigned PORTD4                  :1;
        unsigned PORTD5                  :1;
        unsigned PORTD6                  :1;
        unsigned PORTD7                  :1;
    }PORTDbits_t;

    
 #define DDRA      *((volatile uint8 *) 0x3A)

typedef struct {
        unsigned DDRA0                  :1;
        unsigned DRRA1                  :1;
        unsigned DDRA2                  :1;
        unsigned DDRA3                  :1;
        unsigned DDRA4                  :1;
        unsigned DDRA5                  :1;
        unsigned DDRA6                  :1;
        unsigned DDRA7                  :1;
    }DDRAbits_t;    
    
#define DDRB      *((volatile uint8 *) 0x37)

typedef struct {
        unsigned DDRB0                  :1;
        unsigned DRRB1                  :1;
        unsigned DDRB2                  :1;
        unsigned DDRB3                  :1;
        unsigned DDRB4                  :1;
        unsigned DDRB5                  :1;
        unsigned DDRB6                  :1;
        unsigned DDRB7                  :1;
    }DDRBbits_t;   
    
#define DDRC      *((volatile uint8 *) 0x34)

typedef struct {
        unsigned DDRC0                  :1;
        unsigned DRRC1                  :1;
        unsigned DDRC2                  :1;
        unsigned DDRC3                  :1;
        unsigned DDRC4                  :1;
        unsigned DDRC5                  :1;
        unsigned DDRC6                  :1;
        unsigned DDRC7                  :1;
    }DDRCbits_t;    
    
 
#define DDRD      *((volatile uint8 *) 0x31)

typedef struct {
        unsigned DDRD0                  :1;
        unsigned DRRD1                  :1;
        unsigned DDRD2                  :1;
        unsigned DDRD3                  :1;
        unsigned DDRD4                  :1;
        unsigned DDRD5                  :1;
        unsigned DDRD6                  :1;
        unsigned DDRD7                  :1;
    }DDRDbits_t;    
    
#define PINA      *((volatile uint8 *) 0x39)

typedef struct {
        unsigned PINA0                  :1;
        unsigned PINA1                  :1;
        unsigned PINA2                  :1;
        unsigned PINA3                  :1;
        unsigned PINA4                  :1;
        unsigned PINA5                  :1;
        unsigned PINA6                  :1;
        unsigned PINA7                  :1;
    }PINAbits_t; 

#define PINB      *((volatile uint8 *) 0x36)

typedef struct {
        unsigned PINB0                  :1;
        unsigned PINB1                  :1;
        unsigned PINB2                  :1;
        unsigned PINB3                  :1;
        unsigned PINB4                  :1;
        unsigned PINB5                  :1;
        unsigned PINB6                  :1;
        unsigned PINB7                  :1;
    }PINBbits_t; 

#define PINC      *((volatile uint8 *) 0x33)

typedef struct {
        unsigned PINC0                  :1;
        unsigned PINC1                  :1;
        unsigned PINC2                  :1;
        unsigned PINC3                  :1;
        unsigned PINC4                  :1;
        unsigned PINC5                  :1;
        unsigned PINC6                  :1;
        unsigned PINC7                  :1;
    }PINCbits_t; 
   
#define PIND      *((volatile uint8 *) 0x30)

typedef struct {
        unsigned PIND0                  :1;
        unsigned PIND1                  :1;
        unsigned PIND2                  :1;
        unsigned PIND3                  :1;
        unsigned PIND4                  :1;
        unsigned PIND5                  :1;
        unsigned PIND6                  :1;
        unsigned PIND7                  :1;
    }PINDbits_t;   
    
    
#endif	/* DIO_REG_CFG_H */

