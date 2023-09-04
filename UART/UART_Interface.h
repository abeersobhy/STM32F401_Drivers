/*
 * UART_Interface.h
 * Author: Abeer Sobhy
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define UART_NULL 0L
typedef enum
{
	PE,
	FE,
	NF,
	ORE,
	IDLE,
	RXNE,
	TC,
	TXE,
	LBD,
	CTS,
}USART_SR_BITS;

 typedef enum
 {
	 SBK,
	 RWU,
	 RE,
	 TE,
	 IDLEIE,
	 RXNEIE,
	 TCIE,
	 TXEIE,
	 PEIE,
	 PS,
	 PCE,
	 WAKE,
	 M,
	 UE,
	 U_RES,
	 OVER8,
 }USART_CR1_BITS;

typedef enum
{
	ADD0,
	ADD1,
	ADD2,
	ADD3,
	URES1,
	LBDL,
	LBDIE,
	URES2,
	LBCL,
	CPHA,
	CPOL,
	CLKEN,
	STOP0,
	STOP1,
	LINEN,
}USART_CR2_BITS;

typedef enum
{
	EIE,
	IREN,
	IRLP,
	HDSEL,
	NACK,
	SCEN,
	DMAR,
	DMAT,
	RTSE,
	CTSE,
	CTSIE,
	ONEBIT,
}USART_CR3_BITS;


/**************************************************************************
 * Function Name    	: UART_Init
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Initialize the UART Prepheral.
 * **************************************************************************/
void UART_Init();
/**************************************************************************
 * Function Name    	: UART_SendData
 * Function Input   	: copyUint8_tData to be sent, length of this data.
 * Function Return  	: void
 * Function Description : Send 8 bit data to another MC.
 * **************************************************************************/
void UART_SendByte(uint8_t copyUint8_tData);
/**************************************************************************
 * Function Name    	: UART_ReceiveByte
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
void UART_ReceiveByte(uint8_t* copyUint8_tData);
/**************************************************************************
 * Function Name    	: UART_transmit_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
void UART_transmit_string(uint8_t *data);
/**************************************************************************
 * Function Name    	: UART_receive_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive string of data from another MC.
 * **************************************************************************/
void UART_receive_string(uint8_t* arrChar, uint8_t length);


#endif /* MCAL_UART_UART_INTERFACE_H_ */
