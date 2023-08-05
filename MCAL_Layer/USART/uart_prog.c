/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

//#include "Std_types.h"
//#include "Bit_Math.h"
//#include "Lbt_int.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "uart_int.h"
#include "uart_config.h"
#include "uart_priv.h" 


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void USART_Init(void)
{
/* Set baud rate */
//UBRRH = (unsigned char)(BAUD_RATE>>8);
//UBRRL = 51;

/* Enable receiver and transmitter */
//UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
//UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
/*
SET_BIT(UCSRB,4);
SET_BIT(UCSRB,3);
SET_BIT(UCSRC,7);
SET_BIT(UCSRC,1);
SET_BIT(UCSRC,2);
SET_BIT(UCSRC,3);
*/

uint8 Local_u8UCSRCValue = 0b10000000;
	uint16 Local_u16BaudRateValue = 51;
	
	/*BaudRate = 9600*/
	UBRRL = (uint8)Local_u16BaudRateValue;
	UBRRH = (uint8)(Local_u16BaudRateValue>>8);
	
	/*Normal Speed*/
	CLEAR_BIT(UCSRA,1);

	/*Disable MultiProcessor Mood*/
	CLEAR_BIT(UCSRA,0);
	
	/*Enable Tx*/
	SET_BIT(UCSRB,3);

	/*Enable Rx*/
	SET_BIT(UCSRB,4);

	/*Select 8 BIT Data*/
	CLEAR_BIT(UCSRB,2);	
	SET_BIT(Local_u8UCSRCValue,2);
	SET_BIT(Local_u8UCSRCValue,1);

	/*Select Asynch Mood*/
	CLEAR_BIT(Local_u8UCSRCValue,6);

	/*No Parity Bit*/
	CLEAR_BIT(Local_u8UCSRCValue,5);
	CLEAR_BIT(Local_u8UCSRCValue,4);

	/*Enable Two Stop Bits*/
	SET_BIT(Local_u8UCSRCValue,3);
	
	/*Update UCSRC_REG*/ 
	UCSRC = Local_u8UCSRCValue;
}


/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit(uint8 data )
{
    
	/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<5)) );
/* Put data into buffer, sends the data */
UDR = data;
}

/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
uint8 USART_Receive(void){
    /* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
    return UDR;
}