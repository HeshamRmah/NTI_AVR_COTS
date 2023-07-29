/* 
 * File:   interrupt_config.h
 * Author: Hesham
 *
 * Created on July 28, 2023, 2:00 PM
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H

/* ----------------- Includes -----------------*/
#include "interrupt_reg_cfg.h"
/***/
#include "../mcal_std_types.h"

/* ----------------- Macro Declarations -----------------*/
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCCUR     1
#define INTERRUPT_NOT_OCCUR 0
#define INTERRUPT_PRIORITY_ENABLE    1
#define INTERRUPT_PRIORITY_DISABLE   0

/* ----------------- Macro Functions Declarations -----------------*/
/* This macro will enable global interrupts. */
#define INTERRUPT_GlobalInterruptEnable()  (SREGbits->I_bit = 1)
/* This macro will disable global interrupts. */
#define INTERRUPT_GlobalInterruptDisable() (SREGbits->I_bit = 0)

/* ----------------- Data Type Declarations -----------------*/


/* ----------------- Software Interfaces Declarations -----------------*/

#endif	/* INTERRUPT_CONFIG_H */

