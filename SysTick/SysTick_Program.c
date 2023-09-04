/*
 * SysTick_Program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: user
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"
#include "SysTick_Interface.h"

void (*SysTickPtrFuncPeriodicInterval)(void) = 0L;
/****************************************************************
* Function Name  	: mSysTick_Init
* Input Parameter	: void
* Return Parameter  : SYS_TICK_RETURN_TYPES (OK or NOT)
* Description       : Initialize the SysTick timer
****************************************************************/
SYS_TICK_RETURN_TYPES mSysTick_Init(void)
{
	SYS_TICK_RETURN_TYPES returnType = SYS_TICK_OK;
    /*Select the clock source.*/
	#if  CLK_SOURCE == AHB_DIVE_BY_8
	CLR_BIT(SYS_TICK->STK_CTRL, CLKSOURCE);
	#elif CLK_SOURCE == AHB
	SET_BIT(SYS_TICK->STK_CTRL, CLKSOURCE);
	#else
	returnType = SYS_TICK_NOT_OK;
	#endif
	SYS_TICK->STK_LOAD = 0; /*Clear the load register.*/
	SYS_TICK->STK_VAL = 0;  /*Clear the val register.*/
	CLR_BIT(SYS_TICK->STK_CTRL, SYS_ENABLE); /*Disable the counter.*/
	CLR_BIT(SYS_TICK->STK_CTRL, TICKINT); /*Exception not assert.*/

	return returnType;
}
/****************************************************************
* Function Name  	: mSysTick_Disable
* Input Parameter	: void
* Return Parameter  : void
* Description       : Disable the SysTick timer
****************************************************************/
void mSysTick_Disable(void)
{
	SYS_TICK->STK_LOAD = 0; /*Clear the load register.*/
	SYS_TICK->STK_VAL = 0;  /*Clear the val register.*/
	CLR_BIT(SYS_TICK->STK_CTRL, SYS_ENABLE); /*Disable the counter.*/
	CLR_BIT(SYS_TICK->STK_CTRL, TICKINT); /*Exception not assert.*/
}
/****************************************************************
* Function Name  	: mSysTick_BusyWait
* Input Parameter	: uint32_t NumOfCount needed.
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : busy wait waiting for specific number of ticks.
****************************************************************/
SYS_TICK_RETURN_TYPES mSysTick_BusyWait(uint32_t NumOfCount)
{
	SYS_TICK_RETURN_TYPES returnType = SYS_TICK_OK;
	if(NumOfCount <= MAX_NUM_OF_COUNT)
	{
		SYS_TICK->STK_LOAD = NumOfCount;
		SET_BIT(SYS_TICK->STK_CTRL, SYS_ENABLE); /*Start counting down.*/
		while(READ_BIT(SYS_TICK->STK_CTRL, COUNTFLAG) == 0); /*WAIT until the count flag raised.*/
		CLR_BIT(SYS_TICK->STK_CTRL, TICKINT); /*Exception request is not assert*/
	}
	else
	{
		returnType = SYS_TICK_NOT_OK;
	}
    return returnType;
}
/****************************************************************
* Function Name  	: mSTK_SetIntervalPeriodic
* Input Parameter	: pointer to remainingTime variable to carry the remaining value
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : Set the periodic interval option
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_SetIntervalPeriodic(uint32_t CopyNoCounts, void (*ptrFunc)(void))
{
	SYS_TICK_RETURN_TYPES returnType = SYS_TICK_OK;
	if((CopyNoCounts <= MAX_NUM_OF_COUNT) && (ptrFunc != 0L))
	{
		SysTickPtrFuncPeriodicInterval = ptrFunc;
		SYS_TICK->STK_LOAD = CopyNoCounts;
		SET_BIT(SYS_TICK->STK_CTRL, TICKINT); /*SysTick timer exception assert*/
		SET_BIT(SYS_TICK->STK_CTRL, SYS_ENABLE); /*Start counting down.*/
	}
	else
	{
		returnType = SYS_TICK_NOT_OK;
	}
	return returnType;
}
/****************************************************************
* Function Name  	: mSTK_GetRemainingTime
* Input Parameter	: pointer to remainingTime variable to carry the remaining value
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : Get the remaining time
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_GetRemainingTime(uint32_t* remainingTime)
{
	SYS_TICK_RETURN_TYPES returnType = SYS_TICK_OK;
	if(remainingTime != 0L)
	{
		*remainingTime = SYS_TICK->STK_VAL;
	}
	else
	{
		 returnType = SYS_TICK_NOT_OK;
	}
	return  returnType;
}
/****************************************************************
* Function Name  	: mSTK_GetElapsedTime
* Input Parameter	: pointer to elapsedTime variable to set the elpased value
* Return Parameter  : SYS_TICK_RETURN_TYPES
* Description       : get the elpased time value.
****************************************************************/
SYS_TICK_RETURN_TYPES mSTK_GetElapsedTime(uint32_t* elapsedTime)
{
	SYS_TICK_RETURN_TYPES returnType = SYS_TICK_OK;
	if(elapsedTime != 0L)
	{
		*elapsedTime = (SYS_TICK->STK_LOAD)-(SYS_TICK->STK_VAL);
	}
	else
	{
		 returnType = SYS_TICK_NOT_OK;
	}
	return  returnType;
}
/********SysTick interrupt handler *********/
void SysTick_Handler(void)
{
	mSysTick_Disable();
	if(SysTickPtrFuncPeriodicInterval != 0)
	{
		SysTickPtrFuncPeriodicInterval();
	}
	CLR_BIT(SYS_TICK->STK_CTRL, COUNTFLAG);
}

