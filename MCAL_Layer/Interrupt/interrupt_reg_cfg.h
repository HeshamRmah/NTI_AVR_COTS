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
     
#define SREGbits      (*((volatile SREGbits_t *)(0x5F)))
//volatile SREGbits_t *SREGbits = ((volatile SREGbits_t *)(0x5F));


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

#define MCUCRbits      (*((volatile MCUCRbits_t *) (0x55)))   
//volatile MCUCRbits_t *MCUCRbits = ((volatile MCUCRbits_t *)(0x55));


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

#define MCUCSRbits      (*((volatile MCUCSRbits_t *) (0x54)))
//volatile MCUCSRbits_t *MCUCSRbits = ((volatile MCUCSRbits_t *)(0x54));




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

#define GICRbits      (*((volatile GICRbits_t *) 0x5B))
//volatile GICRbits_t *GICRbits = ((volatile GICRbits_t *)(0x5B));



    
    
    typedef struct {
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned INTF2_bit              :1;
        unsigned INTF0_bit              :1;
        unsigned INTF1_bit              :1;
    }GIFRbits_t;

#define GIFRbits      (*((volatile GIFRbits_t *) 0x5A))




#endif	/* INTERRUPT_REG_CFG_H */

