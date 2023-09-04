/****************************************************************
* Auther         : Abeer Sobhy
* File Name      : RCC_Driver_Private FILE
* Description    : All Registers' MACROs needed to use RCC unit are here
****************************************************************/
/*File Gard*/
#ifndef  RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
/******************Include Section******************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
/**************************************************************/
/*
typedef struct
{
	volatile uint32_t RCC_CR         ;
	volatile uint32_t RCC_PLLCFGR    ;
	volatile uint32_t RCC_CFGR       ;
	volatile uint32_t RCC_CIR        ;
	volatile uint32_t RCC_AHB1RSTR   ;
	volatile uint32_t RCC_AHB2RSTR   ;
	uint32_t RCC_RESERVED0   		 ;
	uint32_t RCC_RESERVED1  		 ;
	volatile uint32_t RCC_APB1RSTR   ;
	volatile uint32_t RCC_APB2RSTR   ;
	uint32_t RCC_RESERVED2  		 ;
	uint32_t RCC_RESERVED3  		 ;
	volatile uint32_t RCC_AHB1ENR    ;
	volatile uint32_t RCC_AHB2ENR    ;
	uint32_t RCC_RESERVED4  		 ;
	uint32_t RCC_RESERVED5  		 ;
	volatile uint32_t RCC_APB1ENR    ;
	volatile uint32_t RCC_APB2ENR    ;
	uint32_t RCC_RESERVED6  		 ;
	uint32_t RCC_RESERVED7  		 ;
	volatile uint32_t RCCAHB1LPENR   ;
	volatile uint32_t RCCAHB2LPENR   ;
	uint32_t RCC_RESERVED8  		 ;
	uint32_t RCC_RESERVED9  		 ;
	volatile uint32_t RCC_APB1LPENR  ;
	volatile uint32_t RCC_APB2LPENR  ;
	uint32_t RCC_RESERVED10 		 ;
	uint32_t RCC_RESERVED11 		 ;
	volatile uint32_t RCC_BDCR       ;
	volatile uint32_t RCC_CSR        ;
	uint32_t RCC_RESERVED12 		 ;
	uint32_t RCC_RESERVED13 		 ;
	volatile uint32_t RCC_SSCGR      ;
	volatile uint32_t RCC_PLLI2SCFGR ;
	uint32_t RCC_RESERVED14 		 ;
	volatile uint32_t RCC_DCKCFGR    ;

}RCC_MemMap_t;*/
/*****************MACROs Section*******************************/

#define RCC_CR  		    	*((volatile uint32_t*)0x40023800)
#define RCC_PLLCFGR  			*((volatile uint32_t*)0x40023804)
#define RCC_CFGR  			    *((volatile uint32_t*)0x40023808)
#define RCC_AHB1ENR  			*((volatile uint32_t*)0x40023830)
#define RCC_AHB2ENR  			*((volatile uint32_t*)0x40023834)
#define RCC_APB1ENR  			*((volatile uint32_t*)0x40023840)
#define RCC_APB2ENR  			*((volatile uint32_t*)0x40023844)
/*Base address of RCC is 0X40023800.*/
#define RCC_ADDRESS_BASE *((volatile uint32_t*)0x40023800)

/*RCC points to the base address.*/
#define RCC ((volatile RCC_MemMap_t*)(RCC_ADDRESS_BASE))
/*******************************************************************/
#endif
