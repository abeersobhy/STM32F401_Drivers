/*
 * SPI_Interface.h

 * Author: Abeer Sobhy
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

typedef enum
{
	SPI1,
	SPI2,
	SPI3,
	SPI4,
}SPI_Config_t;

typedef enum
{
	MASTER_MODE,
	SLAVE_MODE,
}SPI_Mode_t;

typedef enum
{
	SPI_OK,
	SPI_NOT_OK,
}SPI_ReturnType;

typedef enum
{
	CPHA,
	CPOL,
	MSTR,
	BR0,
	BR1,
	BR2,
	SPE,
	LSBFIRST,
	SSI,
	SSM,
	RXONLY,
	DFF,
	CRCNEXT,
	CR1_CRCEN,
	BIDIOE,
	BIDIMODE,
}SPI_CR1_BITs;

typedef enum
{
	RXDMAEN,
	TXDMAEN,
	SSOE,
	Res1,
	FRF,
	ERRIE,
	RXNEIE,
	TXEIE,
}SPI_CR2_BITs;

typedef enum
{
	RXNE,
	TXE,
	CHSIDE,
	UDR,
	CRC_ERR,
	MODF,
	OVR,
	BSY,
	FRE,
}SPI_SR_BITs;

typedef enum
{
	CHLEN,
	DATLEN0,
	DATLEN1,
	CKPOL,
	I2SSTD0,
	I2SSTD1,
	Res0,
	PCMSYNC,
	I2SCFG0,
	I2SCFG1,
	I2SE,
	I2SMOD,
}SPI_I2SCFGR_BITs;

typedef enum
{
	FREQ_DIV_BY_2,
	FREQ_DIV_BY_4,
	FREQ_DIV_BY_8,
	FREQ_DIV_BY_16,
	FREQ_DIV_BY_32,
	FREQ_DIV_BY_64,
	FREQ_DIV_BY_128,
	FREQ_DIV_BY_256,
}BAUDRATE_CONTROL;

#define SLAVE  0
#define MASTER 1
#define MSB 0
#define LSB 1

/**************************************************************************
 * Function Name    	: SPI_Init
 * Function Input   	: void
 * Function Return  	: void
 * Function Description : Initialize the SPI Prepheral.
 * **************************************************************************/
SPI_ReturnType SPI_Init(void);
/**************************************************************************
 * Function Name    	: SPI_SendByte
 * Function Input   	: copyUint8_tData to be sent.
 * Function Return  	: void
 * Function Description : Send 8 bit data to another MC.
 * **************************************************************************/
SPI_ReturnType SPI_SendByte(uint8_t* uint8_tData);
/**************************************************************************
 * Function Name    	: SPI_ReceiveByte
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
SPI_ReturnType SPI_ReceiveByte(uint8_t* uint8_tData);
/**************************************************************************
 * Function Name    	: SPI_transmit_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive 8 bit data from another MC.
 * **************************************************************************/
SPI_ReturnType SPI_transmit_string(uint8_t *data);
/**************************************************************************
 * Function Name    	: SPI_receive_string
 * Function Input   	: address of copyUint8_tData variable to be received.
 * Function Return  	: void
 * Function Description : Receive string of data from another MC.
 * **************************************************************************/
SPI_ReturnType SPI_receive_string(uint8_t* arrChar, uint8_t length);



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
