/*
 * NVIC_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: user
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

typedef struct
{
	volatile uint32_t NVIC_ISER[32];
	volatile uint32_t NVIC_ICER[32];
	volatile uint32_t NVIC_ISPR[32];
	volatile uint32_t NVIC_ICPR[32];
	volatile uint32_t NVIC_IABR[64];
	volatile uint32_t NVIC_IPR[90];
}NVIC_MemMap_t;

/*System control block configuration.*/
typedef struct
{
	volatile uint32_t SCB_ACTLR[415];
	volatile uint32_t SCB_CPUID;
	volatile uint32_t SCB_ICSR;
	volatile uint32_t SCB_VTOR;
	volatile uint32_t SCB_AIRCR;
	volatile uint32_t SCB_SCR;
	volatile uint32_t SCB_CCR;
	volatile uint32_t SCB_SHPR1;
	volatile uint32_t SCB_SHPR2;
	volatile uint32_t SCB_SHPR3;
	volatile uint32_t SCB_SHCSR;
	volatile uint32_t SCB_CFSR;
	volatile uint32_t SCB_MMSR;
	volatile uint32_t SCB_BFSR;
	volatile uint32_t SCB_UFSR;
	volatile uint32_t SCB_HFSR[2];
	volatile uint32_t SCB_MMAR;
	volatile uint32_t SCB_BFAR;
	volatile uint32_t SCB_AFSR;
}SCB_MemMap_t;
/*******************************MACROs section***************************************/
/*NVIC BASE ADDRESS.*/
#define NVIC_BASE_ADDRESS 0xE000E100
/*NVIC Pointer to the NVIC stack.*/
#define NVIC ((NVIC_MemMap_t*)(NVIC_BASE_ADDRESS))

/*STIR Register.*/
#define NVIC_STIR		*(volatile uint32_t*)(NVIC_BASE_ADDRESS+0xD00)

/*Vector password key.*/
#define VECT_KEY 0xFA05
/*System control block BASE ADDRESS.*/
#define SCB_BASE_ADDRESS 0xE000E008
/*SCB AIRCRX Register.*/
#define SCB_AIRCRX		*(volatile uint32_t*)(SCB_BASE_ADDRESS +0x0c)
/************************************************************************************/
#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
