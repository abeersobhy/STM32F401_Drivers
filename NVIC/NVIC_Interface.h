/*
 * NVIC_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: user
 */
/*File guard.*/
#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

typedef enum
{
	NVIC_OK,
	NVIC_NOT_OK
}NVIC_ReturnType;

#define NVIC_GROUP_0_BITS_SUB_4_BITS  0b111
#define NVIC_GROUP_1_BITS_SUB_3_BITS  0b110
#define NVIC_GROUP_2_BITS_SUB_2_BITS  0b101
#define NVIC_GROUP_3_BITS_SUB_1_BITS  0b100
#define NVIC_GROUP_4_BITS_SUB_0_BITS  0b011
/*******************************************************************
* Function Name  	: NVIC_EnableInterrupt
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Enable the interrupt.
*******************************************************************/
NVIC_ReturnType NVIC_EnableInterrupt(uint8_t uint8_tInterruptNum);
/*******************************************************************
* Function Name  	: NVIC_DisableInterrupt
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Disable the interrupt.
*******************************************************************/
NVIC_ReturnType NVIC_DisableInterrupt(uint8_t uint8_tInterruptNum);
/*******************************************************************
* Function Name  	: NVIC_voidSetPendingFlag
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Set the pending flag.
*******************************************************************/
NVIC_ReturnType NVIC_SetPendingFlag(uint8_t uint8_tInterruptNum);
/*******************************************************************
* Function Name  	: NVIC_ClearPendingFlag
* Input Parameter	: uint8_t variable to the interrupt number.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Clear the pending flag.
*******************************************************************/
NVIC_ReturnType NVIC_ClearPendingFlag(uint8_t uint8_tInterruptNum);
/*******************************************************************
* Function Name  	: NVICGetInterruptState
* Input Parameter	: uint8_t variable to the interrupt number, an address of variable to carry the state.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Get the state of an interrupt.
*******************************************************************/
NVIC_ReturnType NVICGetInterruptState(uint8_t uint8_tInterruptNum , uint8_t* interruptStat);
/*******************************************************************
* Function Name  	: NVIC_SetInterrupptPriority
* Input Parameter	: uint8_t variable to the interrupt number, group id and subgroup id.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Set the interrupt priority.
*******************************************************************/
NVIC_ReturnType NVIC_SetInterrupptPriority(uint8_t uint8_tInterruptNum, uint8_t uint8_tGroupId ,uint8_t uint8_tSubGroupId );
/*******************************************************************
* Function Name  	: NVIC_SetPriorityConfig
* Input Parameter	: uint8_t variable to the priority of the interrupt.
* Return Parameter  : NVIC_ReturnType (OK or NOT_OK)
* Description       : Set the interrupt priority configuration.
*******************************************************************/
NVIC_ReturnType NVIC_SetPriorityConfig(uint8_t uint8_tPriorityGrouping);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
