/*
 * EXTI_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: user
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "EXIT_Private.h"
#include "EXIT_Interface.h"


static uint8_t pendingFlag[16] = {0};
static void (*EXTI_CallBack[16] ) (void) = {'\0'} ;
/*******************************************************************************************************************************
* Function Name  	: MEXIT_setInterruptStatus
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - InterruptState (State of the interrupt masked or not)
* Return Parameter  : EXIT_ReturnType
* Description       : Set the interrupt state of the selection line (masked or not masked).
*********************************************************************************************************************************/
EXIT_ReturnType MEXIT_setInterruptStatus(uint8_t uint8_tEXTI_Number, uint8_t InterruptState)
{
	EXIT_ReturnType rt = EXTI_OK;
	if(uint8_tEXTI_Number > MAX_INTERRUPT_NUM || (InterruptState > EXIT_INTERRUPT_UNMASKED))
	{
		return EXTI_NOT_OK; /*Invalid input.*/
	}
	else
	{
		switch(InterruptState)
		{
			case EXIT_INTERRUPT_MASKED: /*Selected line enabled.*/
				CLR_BIT(EXTI->IMR , uint8_tEXTI_Number);
			break;
			case EXIT_INTERRUPT_UNMASKED: /*Selected line disabled.*/
				 SET_BIT(EXTI->IMR , uint8_tEXTI_Number);
			break;
			default:
				rt = EXTI_NOT_OK; /*Invalid input*/
			break;
		}
	}
	return rt;
}
/****************************************************************
* Function Name  	: MEXIT_setInterruptEdge
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - InterruptState (State of the interrupt rising - falling or on change)
* Return Parameter  : EXIT_ReturnType
* Description       : Set the interrupt edge state of the selection line (rising edge, falling edge & no change).
****************************************************************/
EXIT_ReturnType MEXIT_setInterruptEdge (uint8_t uint8_tEXTI_Number, uint8_t EdgeState)
{
    	EXIT_ReturnType rt = EXTI_OK;
		if(uint8_tEXTI_Number > MAX_INTERRUPT_NUM) /*Invalid number of interrupts.*/
		{
			return EXTI_NOT_OK;
		}
		else
		{
			switch(EdgeState) /*Check the selected adge.*/
			{
				case RISING_ENABLE: /*Interrupt with rising edge.*/
					SET_BIT(EXTI->RSTR , uint8_tEXTI_Number);
					CLR_BIT(EXTI->FTSR , uint8_tEXTI_Number);
				break;
				case FALLING_ENABLE: /*Interrupt with falling edge.*/
					 SET_BIT(EXTI->FTSR , uint8_tEXTI_Number);
					 CLR_BIT(EXTI->RSTR , uint8_tEXTI_Number);
			  	break;
				case EXIT_ON_CHANGE: /*Interrupt with any logic change.*/
					SET_BIT(EXTI->RSTR , uint8_tEXTI_Number);
					SET_BIT(EXTI->FTSR , uint8_tEXTI_Number);
				break;
				default:
					rt = EXTI_NOT_OK;
				break;
			}
		}
		return rt;
}
/****************************************************************
* Function Name  	: MEXIT_voidClearPR
* Input Parameter	: uint8_tEXTI_Number
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Used to Clear the PR for each line of EXTI.
****************************************************************/
EXIT_ReturnType MEXIT_ClearInterruptPending(uint8_t uint8_tEXTI_Number)
{
	EXIT_ReturnType rt = EXTI_OK;
	if(uint8_tEXTI_Number > MAX_INTERRUPT_NUM) /*Invalid number of interrupts.*/
	{
		return EXTI_NOT_OK;
	}
	else
	{
		SET_BIT(EXTI->PR, uint8_tEXTI_Number); /*Clear the pending flag by sit it to one.*/
	}
	return rt;
}
/****************************************************************
* Function Name  	: MEXIT_GetInterruptPending
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - State of pending flag (Cleared or not).
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Used to Clear the PR for each line of EXTI.
****************************************************************/
EXIT_ReturnType MEXIT_GetInterruptPending(uint8_t uint8_tEXTI_Number, uint8_t* PendingState)
{
	EXIT_ReturnType rt = EXTI_OK;
	if(uint8_tEXTI_Number > MAX_INTERRUPT_NUM || (PendingState == NULL_PTR)) /*Invalid number of interrupts.*/
	{
		return EXTI_NOT_OK;
	}
	else
	{
		*PendingState = READ_BIT(EXTI->PR, uint8_tEXTI_Number); /*Read the pending flag.*/
	}
	return rt;
}
/****************************************************************
* Function Name  	: MEXIT_voidSWInterrupt
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - InterruptState (State of the interrupt rising - falling or on change)
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Used to set the software interrupt.
****************************************************************/
EXIT_ReturnType MEXIT_voidSWInterrupt(uint8_t uint8_tEXTI_Number)
{
    EXIT_ReturnType returnType = EXTI_OK;
	if(uint8_tEXTI_Number <= EXTI15)
	{
	    SET_BIT(EXTI->SWIER , uint8_tEXTI_Number);  //ENABLE SoftWare Interrupt.
	}
	else
	{
		returnType = EXTI_NOT_OK;
	}
	return returnType;
}
/****************************************************************
* Function Name  	: EXTI_SetInterruptCallBack
* Input Parameter	: uint8_tEXTI_Number - pointer to void function that will be called when the interrupt occur.
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Set the interrupt function
****************************************************************/
EXIT_ReturnType EXTI_SetInterruptCallBack (uint8_t uint8_tEXTI_Number, void (*ptrFunc)(void))
{
	EXIT_ReturnType ReturnType = EXTI_OK;
	if((uint8_tEXTI_Number <= EXTI22) && (ptrFunc != NULL_PTR))
	{
		EXTI_CallBack[uint8_tEXTI_Number] = ptrFunc ; /*Set the address of the function to execute it when the interrupt happen.*/
	}
	else
	{
		ReturnType = EXTI_NOT_OK;
	}
	return ReturnType;
}
/****************************************************************
* Function Name  	: EXTI_ChangeExternalSource
* Input Parameter	: uint8_tEXTI_Number - Source line number.
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Select the source line & port of the the interrupt.
****************************************************************/
EXIT_ReturnType EXTI_ChangeExternalSource (uint8_t uint8_tPortNumber, uint8_t uint8_tEXTI_LineNumber)
{
	EXIT_ReturnType ReturnType = EXTI_OK;
//	if((uint8_tPortNumber > EXTI_PORTC) || uint8_tEXTI_LineNumber > EXTI15)
//	{
//		ReturnType = EXTI_NOT_OK;
//	}
//	else
//	{
		if(uint8_tEXTI_LineNumber < EXTI4)
		{
			MODIFY_REG(SYSCFG_EXTICR1,(uint8_tPortNumber%4<<uint8_tEXTI_LineNumber),(0b1111<<uint8_tEXTI_LineNumber%4));
		/*	SYSCFG_EXTICR1 &= ((~(uint32_t)0xF) << (4*uint8_tEXTI_LineNumber));*/ /*Make sure that the selected bits is zeros.*/
		/*	SYSCFG_EXTICR1 |= (uint8_tPortNumber << (4*uint8_tEXTI_LineNumber));*/
		}
		else if(uint8_tEXTI_LineNumber >= EXTI4 && uint8_tEXTI_LineNumber < EXTI8)
		{
			MODIFY_REG(SYSCFG_EXTICR2,(uint8_tPortNumber%4<<uint8_tEXTI_LineNumber),(0b1111<<uint8_tEXTI_LineNumber%4));
		/*	SYSCFG_EXTICR2 &= ((~(uint32_t)0xF) << (4*uint8_tEXTI_LineNumber));*/ /*Make sure that the selected bits is zeros.*/
		/*	SYSCFG_EXTICR2 |= (uint8_tPortNumber << (4*uint8_tEXTI_LineNumber)); */
		}
		else if(uint8_tEXTI_LineNumber >= EXTI8 && uint8_tEXTI_LineNumber < EXTI12)
		{
			MODIFY_REG(SYSCFG_EXTICR3,(uint8_tPortNumber%4<<uint8_tEXTI_LineNumber),(0b1111<<uint8_tEXTI_LineNumber%4));
		/*	SYSCFG_EXTICR3 &= ((~(uint32_t)0xF) << (4*uint8_tEXTI_LineNumber));*/ /*Make sure that the selected bits is zeros.*/
		/*	SYSCFG_EXTICR3 |= (uint8_tPortNumber << (4*uint8_tEXTI_LineNumber));*/
		}
		else if(uint8_tEXTI_LineNumber >= EXTI12 && uint8_tEXTI_LineNumber < EXTI16)
		{
			MODIFY_REG(SYSCFG_EXTICR4,(uint8_tPortNumber%4<<uint8_tEXTI_LineNumber),(0b1111<<uint8_tEXTI_LineNumber%4));
		/*	SYSCFG_EXTICR4 &= ((~(uint32_t)0xF) << (4*uint8_tEXTI_LineNumber));*/ /*Make sure that the selected bits is zeros.*/
	    /*	SYSCFG_EXTICR4 |= (uint8_tPortNumber << (4*uint8_tEXTI_LineNumber));*/
		}
		else
		{
			ReturnType = EXTI_NOT_OK;
		}
//	}
	return ReturnType;
}

void EXIT0_IRQHandler()
{
	MEXIT_ClearInterruptPending(EXTI0); /*Clear the interrupt pending flag.*/
	if(EXTI_CallBack[EXTI0] != NULL_PTR)
	{
		EXTI_CallBack[EXTI0](); /*Call the function to execute it.*/
	}
	else
	{}
}
void EXIT1_IRQHandler()
{
	MEXIT_ClearInterruptPending(EXTI1); /*Clear the interrupt pending flag.*/
	if(EXTI_CallBack[EXTI1] != NULL_PTR)
	{
		EXTI_CallBack[EXTI1](); /*Call the function to execute it.*/
	}
	else
	{}
}
void EXIT2_IRQHandler()
{
	MEXIT_ClearInterruptPending(EXTI2); /*Clear the interrupt pending flag.*/
	if(EXTI_CallBack[EXTI2] != NULL_PTR)
	{
		EXTI_CallBack[EXTI2](); /*Call the function to execute it.*/
	}
	else
	{}
}
void EXIT3_IRQHandler()
{
	MEXIT_ClearInterruptPending(EXTI3); /*Clear the interrupt pending flag.*/
	if(EXTI_CallBack[EXTI3] != NULL_PTR)
	{
		EXTI_CallBack[EXTI3](); /*Call the function to execute it.*/
	}
	else
	{}
}
void EXIT4_IRQHandler()
{
	MEXIT_ClearInterruptPending(EXTI4); /*Clear the interrupt pending flag.*/
	if(EXTI_CallBack[EXTI4] != NULL_PTR)
	{
		EXTI_CallBack[EXTI4](); /*Call the function to execute it.*/
	}
	else
	{}
}
void EXIT9_5_IRQHandler()
{
	MEXIT_GetInterruptPending(EXTI5, &pendingFlag[EXTI5]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI6, &pendingFlag[EXTI6]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI7, &pendingFlag[EXTI7]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI8, &pendingFlag[EXTI8]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI9, &pendingFlag[EXTI9]); /*Get Interrupt pending flag state.*/
	if(pendingFlag[EXTI5] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI5); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI5] != NULL_PTR)
		{
			EXTI_CallBack[EXTI5](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI6] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI6); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI6] != NULL_PTR)
		{
			EXTI_CallBack[EXTI6](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI7] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI7); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI7] != NULL_PTR)
		{
			EXTI_CallBack[EXTI7](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI8] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI8); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI8] != NULL_PTR)
		{
			EXTI_CallBack[EXTI8](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI9] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI9); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI9] != NULL_PTR)
		{
			EXTI_CallBack[EXTI9](); /*Call the function to execute it.*/
		}
		else
		{}
	}
}
void EXIT10_15_IRQHandler()
{
	MEXIT_GetInterruptPending(EXTI10, &pendingFlag[EXTI10]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI11, &pendingFlag[EXTI11]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI12, &pendingFlag[EXTI12]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI13, &pendingFlag[EXTI13]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI14, &pendingFlag[EXTI14]); /*Get Interrupt pending flag state.*/
	MEXIT_GetInterruptPending(EXTI15, &pendingFlag[EXTI15]); /*Get Interrupt pending flag state.*/
	if(pendingFlag[EXTI10] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI10); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI10] != NULL_PTR)
		{
			EXTI_CallBack[EXTI10](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI11] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI11); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI11] != NULL_PTR)
		{
			EXTI_CallBack[EXTI11](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI12] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI12); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI12] != NULL_PTR)
		{
			EXTI_CallBack[EXTI12](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI13] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI13); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI13] != NULL_PTR)
		{
			EXTI_CallBack[EXTI13](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI14] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI14); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI14] != NULL_PTR)
		{
			EXTI_CallBack[EXTI14](); /*Call the function to execute it.*/
		}
		else
		{}
	}
	if(pendingFlag[EXTI15] == EXTI_REQ) /*Interrupt request.*/
	{
		MEXIT_ClearInterruptPending(EXTI15); /*Clear the interrupt pending flag.*/
		if(EXTI_CallBack[EXTI15] != NULL_PTR)
		{
			EXTI_CallBack[EXTI15](); /*Call the function to execute it.*/
		}
		else
		{}
	}
}
