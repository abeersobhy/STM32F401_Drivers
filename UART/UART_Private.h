/*
 * UART_Private.h
 * Author: Abeer Sobhy
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}UART_MemMap_t;

#define USART1_BASE_ADDRESS 0x40011000
#define USART2_BASE_ADDRESS 0x40014400
#define USART6_BASE_ADDRESS 0x40011400


#define USART1	((volatile UART_MemMap_t*)(USART1_BASE_ADDRESS))
#define USART2  ((volatile UART_MemMap_t*)(USART2_BASE_ADDRESS))
#define USART6  ((volatile UART_MemMap_t*)(USART6_BASE_ADDRESS))


#endif /* MCAL_UART_UART_PRIVATE_H_ */
