/* 
 * File:   mcal_external_interrupt.h
 * Author: Hesham
 *
 * Created on July 28, 2023, 12:37 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* ----------------- Includes -----------------*/
#include "interrupt_reg_cfg.h"
/**/
#include "interrupt_config.h"
/**/
#include "../mcal_std_types.h"
/**/
#include "../std_libraries.h"
/**/
#include "../DIO/mcal_dio.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/

/* This routine clears the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptDisable()         (GICRbits.INT0_bit = 0)
//#define EXT_INT0_InterruptDisable()         CLEAR_BIT(GICR, INT0)
/* This routine sets the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptEnable()          (GICRbits.INT0_bit = 1)
//#define EXT_INT0_InterruptEnable()          SET_BIT(GICR, INT0)
/* This routine Clear the interrupt Flag for the external interrupt, INT0 */
#define EXT_INT0_CLEAR_FLAG()                (GIFRbits.INTF0_bit = 1)
//#define EXT_INT0_CLEAR_FLAG()               SET_BIT(GIFR, INTF0)

/* This routine clears the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptDisable()         (GICRbits.INT1_bit = 0)
//#define EXT_INT1_InterruptDisable()         CLEAR_BIT(GICR, INT1)
/* This routine sets the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptEnable()          (GICRbits.INT1_bit = 1)
//#define EXT_INT1_InterruptEnable()          SET_BIT(GICR, INT1)
/* This routine Clear the interrupt Flag for the external interrupt, INT1 */
#define EXT_INT1_CLEAR_FLAG()               (GIFRbits.INTF1_bit = 1)
//#define EXT_INT1_CLEAR_FLAG()               SET_BIT(GIFR, INTF1)

/* This routine clears the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptDisable()         (GICRbits.INT2_bit = 0)
//#define EXT_INT2_InterruptDisable()         CLEAR_BIT(GICR, INT2)
/* This routine sets the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptEnable()          (GICRbits.INT0_bit = 1)
//#define EXT_INT2_InterruptEnable()          SET_BIT(GICR, INT2)
/* This routine Clear the interrupt Flag for the external interrupt, INT2 */
#define EXT_INT2_CLEAR_FLAG()               (GIFRbits.INTF2_bit = 1)
//#define EXT_INT2_CLEAR_FLAG()               SET_BIT(GIFR, INTF2)

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    LOW_LEVEL = 0,
    LOGICAL_CHANGE,
    FALLING_EDGE,
    RISING_EDGE,
}int0_mode_t;

typedef enum{
    INT0_LOW_LEVEL = 0,
    INT0_LOGICAL_CHANGE,
    INT0_FALLING_EDGE,
    INT0_RISING_EDGE,
            
    INT1_LOW_LEVEL,
    INT1_LOGICAL_CHANGE,
    INT1_FALLING_EDGE,
    INT1_RISING_EDGE,
    
    INT2_FALLING_EDGE,
    INT2_RISING_EDGE,
            
}interrupt_INTx_Mode;

typedef enum{
    INTERRUPT_EXTERNAL_INT0 =  0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
}interrupt_INTx_src;


typedef struct{
    void (* EXT_InterruptHandler)(void);
    pin_config_t pin_obj;
    interrupt_INTx_src source;
    interrupt_INTx_Mode mode;
}interrupt_INTx_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);




#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

