/*
 * UART_Program.c
 * Author: Abeer Sobhy
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "UART_Private.h"
#include "UART_Interface.h"


/**************************************************************************
 * Function Name    	: UART_Init
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Initialize the UART Prepheral.
 ***************************************************************************/
void UART_Init()
{
	SET_BIT(USART1->USART_CR1, TE); 	/*Transmitter Enabled.*/
	SET_BIT(USART1->USART_CR1, RE); 	/*Receiver Enabled.*/
	CLR_BIT(USART1->USART_CR1, M); 		/*Eight bit word length.*/
	CLR_BIT(USART1->USART_CR1, OVER8);  /*Over Sampling 16.*/
	/***************************************************************/
	CLR_BIT(USART1->USART_CR2, STOP0);  /*1 STOP BIT.*/
	CLR_BIT(USART1->USART_CR2, STOP1);  /*1 STOP BIT.*/
	/***************************************************************/
	USART1->USART_BRR = (104 << 4) | 3;	/*Set baud rate with 9600.*/
	/***************************************************************/
	SET_BIT(USART1->USART_CR1, UE); /*UART Enabled.*/
}
/**************************************************************************
 * Function Name    	: UART_SendData
 * Function Input   	: copyUint8_tData to be sent, length of this data.
 * Function Return  	: void
 * Function Description : Send 8 bit data to another MC.
 * **************************************************************************/
void UART_SendByte(uint8_t copyUint8_tData)
{
	while(READ_BIT((USART1->USART_SR),TC) == 0); /*Wait until the previous transmation complete.*/
	USART1->USART_DR = copyUint8_tData;
}
/**************************************************************************
 * Function Name    	: UART_ReceiveByte
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
void UART_ReceiveByte(uint8_t* copyUint8_tData)
{
	while(READ_BIT((USART1->USART_SR), RXNE) == 0); /*Wait until the previous received data id completed.*/
	*copyUint8_tData = USART1->USART_DR;
}
/**************************************************************************
 * Function Name    	: UART_transmit_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
void UART_transmit_string(uint8_t *data)
{
     uint8_t i = 0;
     while(data[i] != UART_NULL)
     {
    	 UART_SendByte(data[i]);

    	 i++;
     }
}
/**************************************************************************
 * Function Name    	: UART_receive_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive string of data from another MC.
 * **************************************************************************/
void UART_receive_string(uint8_t* arrChar, uint8_t length)
{
	uint8_t i = 0;
	while(i != length)
	{
		UART_ReceiveByte(&arrChar[i]);
		i++;
	}
}
