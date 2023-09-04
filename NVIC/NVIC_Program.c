/*
.ll1. * NVIC_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: user
 */
#include "../../LIB/std_types.h"
#include "../RCC/RCC_Interface.h"
#include "../GPIO/GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"


static uint8_t priorityConfig;
/*******************************************************************
* Function Name  	: NVIC_EnableInterrupt
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Enable the interrupt.
*******************************************************************/
NVIC_ReturnType NVIC_EnableInterrupt(uint8_t uint8_tInterruptNum)
{
	NVIC_ReturnType returnType = NVIC_OK;
	if(uint8_tInterruptNum > 239)
	{
		returnType = NVIC_NOT_OK;
	}
	else
	{
		SET_BIT((NVIC->NVIC_ISER[uint8_tInterruptNum/32]), (uint8_tInterruptNum%32));
	}
    return returnType;
}
/*******************************************************************
* Function Name  	: NVIC_DisableInterrupt
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Disable the interrupt.
*******************************************************************/
NVIC_ReturnType NVIC_DisableInterrupt(uint8_t uint8_tInterruptNum)
{
	NVIC_ReturnType returnType = NVIC_OK;
	if(uint8_tInterruptNum > 239)
	{
		returnType = NVIC_NOT_OK;
	}
	else
	{
		SET_BIT((NVIC->NVIC_ICER[uint8_tInterruptNum/32]), (uint8_tInterruptNum%32));
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: NVIC_voidSetPendingFlag
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Set the pending flag.
*******************************************************************/
NVIC_ReturnType NVIC_SetPendingFlag(uint8_t uint8_tInterruptNum)
{
	NVIC_ReturnType returnType = NVIC_OK;
	if(uint8_tInterruptNum > 239)
	{
		returnType = NVIC_NOT_OK;
	}
	else
	{
		SET_BIT((NVIC->NVIC_ISPR[uint8_tInterruptNum/32]), (uint8_tInterruptNum%32));
	}
    return returnType;
}
/*******************************************************************
* Function Name  	: NVIC_ClearPendingFlag
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Clear the pending flag.
*******************************************************************/
NVIC_ReturnType NVIC_ClearPendingFlag(uint8_t uint8_tInterruptNum)
{
	NVIC_ReturnType returnType = NVIC_OK;
	if(uint8_tInterruptNum > 239)
	{
		returnType = NVIC_NOT_OK;
	}
	else
	{
		SET_BIT((NVIC->NVIC_ICPR[uint8_tInterruptNum/32]), uint8_tInterruptNum%32);
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: NVICGetInterruptState
* Input Parameter	: uint8_t variable to the interrupt number, an address of variable to carry the state.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Get the state of an interrupt.
*******************************************************************/
NVIC_ReturnType NVICGetInterruptState(uint8_t uint8_tInterruptNum , uint8_t* interruptStat)
{
	NVIC_ReturnType returnType = NVIC_OK;
	if(uint8_tInterruptNum > 239)
	{
		returnType = NVIC_NOT_OK;
	}
	else
	{
		*interruptStat = READ_BIT((NVIC->NVIC_IABR[uint8_tInterruptNum/32]), (uint8_tInterruptNum % 32));
	}
    return returnType;
}
/*******************************************************************
* Function Name  	: NVIC_SetInterrupptPriority
* Input Parameter	: uint8_t variable to the interrupt number, group id and subgroup id.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Set the interrupt priority.
*******************************************************************/
NVIC_ReturnType NVIC_SetInterrupptPriority(uint8_t uint8_tInterruptNum, uint8_t uint8_tGroupId ,uint8_t uint8_tSubGroupId )
{
	NVIC_ReturnType returnType = NVIC_OK;
	if(uint8_tInterruptNum > 239)
	{
		returnType = NVIC_NOT_OK;
	}
	else
	{
		switch(priorityConfig)
		{
			case NVIC_GROUP_4_BITS_SUB_0_BITS:
				 NVIC->NVIC_IPR[uint8_tInterruptNum] = (uint8_tGroupId << 4);
			break;
			case NVIC_GROUP_3_BITS_SUB_1_BITS:
				 NVIC->NVIC_IPR[uint8_tInterruptNum] = ((uint8_tGroupId & 0b111) << 5)| ((uint8_tSubGroupId & 0b1) << 4);
			break;
			case NVIC_GROUP_2_BITS_SUB_2_BITS:
				 NVIC->NVIC_IPR[uint8_tInterruptNum] = ((uint8_tGroupId & 0b11) << 6)| ((uint8_tSubGroupId & 0b11) << 4);
			break;
			case NVIC_GROUP_1_BITS_SUB_3_BITS:
				 NVIC->NVIC_IPR[uint8_tInterruptNum] = ((uint8_tGroupId & 0b111) << 7)|((uint8_tSubGroupId & 0b111) << 4) ;
			break;
			case NVIC_GROUP_0_BITS_SUB_4_BITS:
				 NVIC->NVIC_IPR[uint8_tInterruptNum] = ((uint8_tSubGroupId & 0b1111) << 4);
			break;
			default:
				 returnType = NVIC_NOT_OK;
			break;
		}
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: NVIC_SetPriorityConfig
* Input Parameter	: uint8_tPriorityGrouping (uint8_t) variable to the priority group of the interrupt.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Set the interrupt priority configuration.
*******************************************************************/
NVIC_ReturnType NVIC_SetPriorityConfig(uint8_t uint8_tPriority)
{
	NVIC_ReturnType returnType = NVIC_OK;
	uint32_t regValue = ((VECT_KEY << 16) | (uint8_tPriority << 8)); /*Set the Vector key and the priority of the interrupt grouping field.*/

	SCB_AIRCRX &= ((VECT_KEY << 16) |((~((uint32_t)0b111)) << 8)); /*Make sure that the selected 3 bit of priority are zeros.*/
	SCB_AIRCRX |= regValue; /*Set the register Value to the SCB_AIRCR register.*/
	priorityConfig = uint8_tPriority;
	return returnType;
}



