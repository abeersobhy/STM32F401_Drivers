/*
 * SPI_Program.c
 * Author: user
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../SysTick/SysTick_Interface.h"
#include "../RCC/RCC_Interface.h"
#include "../GPIO/GPIO_Interface.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

/**************************************************************************
 * Function Name    	: SPI_Init
 * Function Input   	: void
 * Function Return  	: SPI_ReturnType
 * Function Description : Initialize the SPI Prepheral.
 * **************************************************************************/
SPI_ReturnType SPI_Init()
{
	SPI_ReturnType returnType = SPI_OK;
	switch(SPI_MODE)
	{
		case MASTER:
			 SET_BIT(SPI1->SPI_CR1, CPHA); /*The first clock transition is the first data capture edge.*/
			 SET_BIT(SPI1->SPI_CR1, CPOL); /*Clock to 1 when idle*/

			 SET_BIT(SPI1->SPI_CR1, MSTR); /*Master configuration.*/

			 SPI1->SPI_CR1 &= (0b000 << 3); /*Make sure that the 3 bits are zero.*/
			 SPI1->SPI_CR1 |= (SPI_FREQ << 3); /*Baud Rate control.*/

			 SPI1->SPI_CR1 &= (0b0 << LSBFIRST); /*Make sure that the bit is zero.*/
			 SPI1->SPI_CR1 |= (SPI_FRAME_FORMAT << LSBFIRST);

			 CLR_BIT(SPI1->SPI_CR1, RXONLY); /*Receive and Send Mode.*/
			 CLR_BIT(SPI1->SPI_CR1,DFF); /*8 bit data frame format.*/

			 SET_BIT(SPI1->SPI_CR1,SSM); /* Software slave management*/
			 SET_BIT(SPI1->SPI_CR1,SSI); /* Internal slave select*/

			 SET_BIT(SPI1->SPI_CR1,SPE); /*SPI ENABLE*/
		break;
		case SLAVE:
			SET_BIT(SPI1->SPI_CR1, CPHA); /*The first clock transition is the first data capture edge.*/
			SET_BIT(SPI1->SPI_CR1, CPOL); /*Clock to 1 when idle*/

			CLR_BIT(SPI1->SPI_CR1, MSTR); /*Slave configuration.*/

			SPI1->SPI_CR1 &= (0b000 << 3); /*Make sure that the 3 bits are zero.*/
			SPI1->SPI_CR1 |= (SPI_FREQ << 3); /*Baud Rate control.*/

			SPI1->SPI_CR1 &= (0b0 << LSBFIRST); /*Make sure that the bit is zero.*/
			SPI1->SPI_CR1 |= (SPI_FRAME_FORMAT << LSBFIRST);

			CLR_BIT(SPI1->SPI_CR1, RXONLY); /*Receive and Send Mode.*/

			CLR_BIT(SPI1->SPI_CR1,DFF); /*8 bit data frame format.*/

			SET_BIT(SPI1->SPI_CR1,SPE); /*SPI ENABLE*/

		break;
		default:
			returnType = SPI_NOT_OK;
		break;
	}
	return returnType;
}
/**************************************************************************
 * Function Name    	: SPI_SendByte
 * Function Input   	: copyUint8_tData to be sent.
 * Function Return  	: SPI_ReturnType
 * Function Description : Send 8 bit data to another MC.
 * **************************************************************************/
SPI_ReturnType SPI_SendByte(uint8_t* uint8_tData)
{
	SPI_ReturnType returnType = SPI_OK;
	if(uint8_tData != NULL)
	{
		returnType = SPI_OK;
		while(READ_BIT(SPI1->SPI_SR, TXE) == 0);
		SPI1->SPI_DR = *uint8_tData;
	}
	else
	{
		returnType = SPI_NOT_OK;
	}
	return returnType;
}
/**************************************************************************
 * Function Name    	: SPI_ReceiveByte
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: SPI_ReturnType
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
SPI_ReturnType SPI_ReceiveByte(uint8_t* uint8_tData)
{
	SPI_ReturnType returnType = SPI_OK;
	if(uint8_tData != NULL)
	{
		returnType = SPI_OK;
		while(READ_BIT(SPI1->SPI_SR, RXNE) == 0);
		*uint8_tData = (uint8_t)SPI1->SPI_DR;
	}
	else
	{
		returnType = SPI_NOT_OK;
	}
	return returnType;
}
/**************************************************************************
 * Function Name    	: SPI_transmit_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: SPI_ReturnType
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
SPI_ReturnType SPI_transmit_string(uint8_t *data)
{
	SPI_ReturnType returnType = SPI_OK;
	if(data != NULL)
	{
	     uint8_t i = 0;
	     while(data[i] != NULL)
	     {
	    	 SPI_SendByte(&data[i]);
	    	 i++;
	     }
	}
	else
	{
		returnType = SPI_NOT_OK;
	}
	return returnType;
}
/**************************************************************************
 * Function Name    	: SPI_receive_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: SPI_ReturnType
 * Function Description : Receive string of data from another MC.
 * **************************************************************************/
SPI_ReturnType SPI_receive_string(uint8_t* arrChar, uint8_t length)
{
	SPI_ReturnType returnType = SPI_OK;
	if(arrChar != NULL)
	{
		uint8_t i = 0;
		while(i != length)
		{
			SPI_ReceiveByte(&arrChar[i]);
			i++;
		}
	}
	else
	{
		returnType = SPI_NOT_OK;
	}
	return returnType;
}


