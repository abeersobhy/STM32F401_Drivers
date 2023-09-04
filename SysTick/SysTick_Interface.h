/*
 * SysTick_Interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: user
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_


typedef enum
{
	SYS_TICK_OK,
	SYS_TICK_NOT_OK,
}SYS_TICK_RETURN_TYPES;

/******************************Declaration Section****************/
/****************************************************************
* Function Name  	: mSysTick_Init
* Input Parameter	: void
* Return Parameter  : SYS_TICK_RETURN_TYPES (OK or NOT)
* Description       : Initialize the SysTick timer
****************************************************************/
SYS_TICK_RETURN_TYPES mSysTick_Init(void);
/****************************************************************
* Function Name  	: mSysTick_Disable
* Input Parameter	: void
* Return Parameter  : void
* Description       : Disable the SysTick timer
****************************************************************/
void mSysTick_Disable(void);
/****************************************************************
* Function Name  	: mSysTick_delay
* Input Parameter	: uint32_t needed delay in Ms.
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : delay time for ms
****************************************************************/
SYS_TICK_RETURN_TYPES mSysTick_BusyWait(uint32_t NumOfCount);
/****************************************************************
* Function Name  	: mSTK_SetIntervalSingle
* Input Parameter	: CopyNoCounts - ptrFunc pointer to function
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : Set single interval
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_SetIntervalSingle(uint32_t CopyNoCounts, void (*ptrFunc)(void));
/****************************************************************
* Function Name  	: mSTK_SetIntervalPeriodic
* Input Parameter	: pointer to remainingTime variable to carry the remaining value
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : Set the periodic interval option
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_SetIntervalPeriodic(uint32_t CopyNoCounts, void (*ptrFunc)(void));
/****************************************************************
* Function Name  	: mSTK_GetRemainingTime
* Input Parameter	: pointer to remainingTime variable to carry the remaining value
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : Get the remaining time
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_GetRemainingTime(uint32_t* remainingTime);
/****************************************************************
* Function Name  	: mSTK_GetElapsedTime
* Input Parameter	: pointer to elapsedTime variable to set the elpased value
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : get the elpased time value.
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_GetElapsedTime(uint32_t* elapsedTime);
/******************************************************************/
#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
