/*
 * EXTI_private.h
 *
 *  Created on: Jul 26, 2021
 *      Author: Alahram
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_t;
/**/
#define EXTI_BASE_ADDRESS 0x40013C00
#define EXTI ((volatile EXTI_t *) EXTI_BASE_ADDRESS)
/**/
#define SYSCFG_BASE_ADDRESS 0x40013800

#define SYSCFG_EXTICR1 (*((volatile uint32_t*)SYSCFG_BASE_ADDRESS+0x8))
#define SYSCFG_EXTICR2 (*((volatile uint32_t*)SYSCFG_BASE_ADDRESS+0xc))
#define SYSCFG_EXTICR3 (*((volatile uint32_t*)SYSCFG_BASE_ADDRESS+0x10))
#define SYSCFG_EXTICR4 (*((volatile uint32_t*)SYSCFG_BASE_ADDRESS+0x14))
#endif /* EXTI_PRIVATE_H_ */
