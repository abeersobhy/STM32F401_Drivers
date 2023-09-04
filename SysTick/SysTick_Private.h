/*
 * SysTick_Private.h
 *
 *  Created on: Aug 19, 2023
 *      Author: user
 */
#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_
/*******************************************************************/
typedef struct
{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;
}SysTick_MemMap_t;

typedef enum
{
	SYS_ENABLE,
	TICKINT,
	CLKSOURCE,
	RES = 15,
	COUNTFLAG,
}STK_CTRL_BITs;

/*****************SysTick control and status register**************/

#define SYS_TICK_BASE_ADDRESS 0xE000E010
#define SYS_TICK ((volatile SysTick_MemMap_t*)(SYS_TICK_BASE_ADDRESS))

#define AHB_DIVE_BY_8 0
#define AHB           1

#define MAX_NUM_OF_COUNT 16777215
#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
