/* 
 * File:   spi_reg_cfg.h
 * Author: Hesham
 *
 * Created on August 3, 2023, 11:40 AM
 */

#ifndef SPI_REG_CFG_H
#define	SPI_REG_CFG_H

typedef struct {
        unsigned SPR0_bit                :1;
        unsigned SPR1_bit                :1;
        unsigned CPHA_CPOL_bits          :2;
        unsigned MSTR_bit                :1;
        unsigned DORD_bit                :1;
        unsigned SPE_bit                 :1;
        unsigned SPIE_bit                :1;
    }SPCRbits_t;

#define SPCRbits      (*((volatile SPCRbits_t *) 0x2D))
    
    
    
typedef struct {
        unsigned SPI2X_bit             :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned                       :1;
        unsigned WCOL_bit              :1;
        unsigned SPIF_bit              :1;
    }SPSRbits_t;

#define SPSRbits      (*((volatile SPSRbits_t *) 0x2E))

    

#define SPDRbits      (*((volatile uint8 *) 0x2F))
    



#endif	/* SPI_REG_CFG_H */

