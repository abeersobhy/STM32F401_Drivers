/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 15, 2023
 *   Author: user
 */
#ifndef MCAL_EXTI_EXIT_INTERFACE_H_
#define MCAL_EXTI_EXIT_INTERFACE_H_


#define EXTI_REQ                    1
#define EXTI_NOT_REQ                0
#define EXIT_INTERRUPT_MASKED   	0
#define EXIT_INTERRUPT_UNMASKED  	1

#define RISING_ENABLE    			0
#define FALLING_ENABLE   			1
#define EXIT_ON_CHANGE   			2

#define MAX_INTERRUPT_NUM           22

#define EXTI_PORTA 0
#define EXTI_PORTB 1
#define EXTI_PORTC 2

#define NULL_PTR       0L

typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,
	EXTI16,
	EXTI17,
	EXTI18,
	EXTI19,
	EXTI20,
	EXTI21,
	EXTI22,
}EXTI_Handler;
typedef enum
{
	EXTI_OK,
	EXTI_NOT_OK
}EXIT_ReturnType;

/*******************************************************************************************************************************
* Function Name  	: MEXIT_setInterruptStatus
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - InterruptState (State of the interrupt masked or not)
* Return Parameter  : EXIT_ReturnType
* Description       : Set the interrupt state of the selection line (masked or not masked).
*********************************************************************************************************************************/
EXIT_ReturnType MEXIT_setInterruptStatus     (uint8_t uint8_tEXTI_Number, uint8_t InterruptState);
/****************************************************************
* Function Name  	: MEXIT_setInterruptEdge
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - InterruptState (State of the interrupt rising - falling or on change)
* Return Parameter  : EXIT_ReturnType
* Description       : Set the interrupt edge state of the selection line (rising edge, falling edge & no change).
****************************************************************/
EXIT_ReturnType MEXIT_setInterruptEdge       (uint8_t uint8_tEXTI_Number, uint8_t EdgeState);
/****************************************************************
* Function Name  	: MEXIT_ClearInterruptPending
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt)
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Used to clear the pending flag.
****************************************************************/
EXIT_ReturnType MEXIT_ClearInterruptPending  (uint8_t uint8_tEXTI_Number);
/****************************************************************
* Function Name  	: MEXIT_voidSWInterrupt
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - InterruptState (State of the interrupt rising - falling or on change)
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Used to set the software interrupt.
****************************************************************/
EXIT_ReturnType MEXIT_voidSWInterrupt		  (uint8_t uint8_tEXTI_Number);
/****************************************************************
* Function Name  	: MEXIT_GetInterruptPending
* Input Parameter	: uint8_tEXTI_Number (Number of the interrupt) - State of pending flag (Cleared or not).
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Used to Clear the PR for each line of EXTI.
****************************************************************/
EXIT_ReturnType MEXIT_GetInterruptPending      (uint8_t uint8_tEXTI_Number, uint8_t* PendingState);
/****************************************************************
* Function Name  	: EXTI_SetInterruptCallBack
* Input Parameter	: uint8_tEXTI_Number - pointer to void function that will be called when the interrupt occur.
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Set the interrupt function
****************************************************************/
EXIT_ReturnType EXTI_SetInterruptCallBack (uint8_t uint8_tEXTI_Number, void (*ptrFunc)(void));
/****************************************************************
* Function Name  	: EXTI_ChangeExternalSource
* Input Parameter	: uint8_tEXTI_Number - Source line number.
* Return Parameter  : EXIT_ReturnType (OK or NOT_OK)
* Description       : Select the source line & port of the the interrupt.
****************************************************************/
EXIT_ReturnType EXTI_ChangeExternalSource (uint8_t uint8_tPortNumber, uint8_t uint8_tEXTI_LineNumber);

#endif /* MCAL_EXTI_EXIT_INTERFACE_H_ */
