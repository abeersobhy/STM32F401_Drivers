/*
 * SPI_Private.h
 * Author: Abeer Sobhy
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPI_MemMap_t;


#define SPI1_BASE_ADDRESS 0x40013000
#define SPI2_BASE_ADDRESS 0x40003800
#define SPI3_BASE_ADDRESS 0x40003c00
#define SPI4_BASE_ADDRESS 0x40013400


#define SPI1 ((volatile SPI_MemMap_t*)(SPI1_BASE_ADDRESS))
#define SPI2 ((volatile SPI_MemMap_t*)(SPI2_BASE_ADDRESS))
#define SPI3 ((volatile SPI_MemMap_t*)(SPI3_BASE_ADDRESS))
#define SPI4 ((volatile SPI_MemMap_t*)(SPI4_BASE_ADDRESS))


#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
