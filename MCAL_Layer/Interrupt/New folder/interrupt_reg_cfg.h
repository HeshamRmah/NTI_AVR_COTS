/* 
 * File:   interrupt_reg_cfg.h
 * Author: Hesham
 *
 * Created on July 28, 2023, 12:18 PM
 */

#ifndef INTERRUPT_REG_CFG_H
#define	INTERRUPT_REG_CFG_H





typedef struct {
        unsigned C_bit                  :1;
        unsigned Z_bit                  :1;
        unsigned N_bit                  :1;
        unsigned V_bit                  :1;
        unsigned S_bit                  :1;
        unsigned H_bit                  :1;
        unsigned T_bit                  :1;
        unsigned I_bit                  :1;
    }SREGbits_t;
    
#define SREG_      *((volatile uint8 *)(0x5F))
//extern volatile SREGbits_t SREGbits _SFR_IO8(0x2F);
SREGbits_t SREGbits;
//volatile SREGbits_t SREGbits __at(0x2F);




typedef struct {
        unsigned ISC00_bit                :1;
        unsigned ISC01_bit                :1;
        unsigned ISC10_bit                :1;
        unsigned ISC11_bit                :1;
        unsigned SM0_bit                  :1;
        unsigned SM1_bit                  :1;
        unsigned SM2_bit                  :1;
        unsigned SE_bit                   :1;
    }MCUCRbits_t;

#define MCUCR_      *((volatile uint8 *) (0x55))   
MCUCRbits_t MCUCRbits;



typedef struct {
        unsigned PORF_bit                  :1;
        unsigned EXTRF_bit                 :1;
        unsigned BORF_bit                  :1;
        unsigned WDRF_bit                  :1;
        unsigned JTRF_bit                  :1;
        unsigned                           :1;
        unsigned ISC2_bit                  :1;
        unsigned JTD_bit                   :1;
    }MCUCSRbits_t;

#define MCUCSR_      *((volatile uint8 *) (0x54))
MCUCSRbits_t MCUCSRbits;





typedef struct {
        unsigned IVCE_bit              :1;
        unsigned IVSEL_bit             :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned INT2_bit              :1;
        unsigned INT0_bit              :1;
        unsigned INT1_bit              :1;
    }GICRbits_t;

#define GICR_      *((volatile uint8 *) 0x5B)
GICRbits_t GICRbits;








#endif	/* INTERRUPT_REG_CFG_H */

