/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _USART_INT_H
#define _USART_INT_H


/****************************************************************/	
/** !comment : SPEED_OPERATION							   		*/
/****************************************************************/
#define DOUBLE_SPEED_MODE			0
#define NORMAL_SPEED_MODE			3

#include "../mcal_std_types.h"
#include "../DIO/mcal_dio.h"
/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void USART_Init(void);


/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit( uint8 data );


/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
uint8 USART_Receive(void);


#endif	/** !comment  :  End of guard                          **/