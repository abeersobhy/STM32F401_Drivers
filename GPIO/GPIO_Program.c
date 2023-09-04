/***********************************************************************
*Author    	 : Abeer Sobhy
*File Name 	 : GPIO_Program.c
*Description : This file consists of the implementation of all APIs
               needed to use the GPIO in ARM Cortex M4
************************************************************************/
/*****************************************************Include Section************************************************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "GPIO_Interface.h"

/********************************************************************************************************************************/
/************************************************Functions Implementation Section************************************************/
/************************************************************************
* Function Name  	: MGPIO_vSetPinDirection
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Set the direction of a specific pin.
************************************************************************/
GPIO_ReturnType MGPIO_vSetPinDirection (GPIO_PIN_Config_t* GPIO_PinConfig)
{
	GPIO_ReturnType returnType = GPIO_OK;
	switch(GPIO_PinConfig->portNumber)
	{
		case PORTA:
		     GPIOA->MODER &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected 2 bits is equal to zero before starting write.*/
			 GPIOA->MODER |= ((GPIO_PinConfig->pinDirection) << (2*(GPIO_PinConfig->pinNumber))); /*INPUT/ OUTPUT/ ANALOG/ ALTERNATE FUNCTION Selection.*/
			 switch(GPIO_PinConfig->pinDirection)
		     {
		          case INPUT:
		  		       GPIOA->PUPDR &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected 2 bits is equal to zero before starting write.*/
		               GPIOA->PUPDR |= ((GPIO_PinConfig->pinInputType) << (2*(GPIO_PinConfig->pinNumber))); /*Pull up or pull down or not selection.*/
		          break;
		          case OUTPUT:
		       		   GPIOA->OTYPER &= (~(0x1 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
		               GPIOA->OTYPER |= ((GPIO_PinConfig->pinOutputType) << (GPIO_PinConfig->pinNumber));/*Push pull or open drain selection.*/

		               GPIOA->OSPEEDR &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
		               GPIOA->OSPEEDR |= ((GPIO_PinConfig->pinSpeed) << (2*(GPIO_PinConfig->pinNumber))); /*Speed selection.*/
		          break;
		          case ALT_FUNC:
		               GPIOA->OTYPER &= (~(0x1 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
		               GPIOA->OTYPER |= ((GPIO_PinConfig->pinOutputType) << (GPIO_PinConfig->pinNumber));/*Push pull or open drain selection.*/
		          break;
		          case ANALOG:
		          break;
		          default:
		               returnType = GPIO_NOT_OK; /*Invalid Input.*/
		          break;
		     }
		break;
	    case PORTB:
			 GPIOB->MODER &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber))));
		     GPIOB->MODER = ((GPIO_PinConfig->pinDirection) << (2*(GPIO_PinConfig->pinNumber))); /*Set the selected mode (2 bits) to the selected pin */
		     switch(GPIO_PinConfig->pinDirection)
			 {
		       	 case INPUT:
		              GPIOB->PUPDR &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber))));
		              GPIOB->PUPDR |= ((GPIO_PinConfig->pinInputType) << (2*(GPIO_PinConfig->pinNumber))); /*Pull up or pull down or not selection.*/
			     break;
				 case OUTPUT:
				      GPIOB->OTYPER &= (~(0x1 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
				      GPIOB->OTYPER |= ((GPIO_PinConfig->pinOutputType) << (GPIO_PinConfig->pinNumber));/*Push pull or open drain selection.*/

				      GPIOB->OSPEEDR &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
				      GPIOB->OSPEEDR |= ((GPIO_PinConfig->pinSpeed) << (2*(GPIO_PinConfig->pinNumber))); /*Speed selection.*/
			     break;
				 case ALT_FUNC:
					  GPIOB->OTYPER &= (~(0x1 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
					  GPIOB->OTYPER |= ((GPIO_PinConfig->pinOutputType) << (GPIO_PinConfig->pinNumber));/*Push pull or open drain selection.*/
			     break;
				 case ANALOG:
				 break;
				 default:
					  returnType = GPIO_NOT_OK;
				 break;
		      }
		break;
	    case PORTC:
			 GPIOC->MODER &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber))));
			 GPIOC->MODER = ((GPIO_PinConfig->pinDirection) << (2*(GPIO_PinConfig->pinNumber))); /*Set the selected mode (2 bits) to the selected pin */
			 switch(GPIO_PinConfig->pinDirection)
			 {
			 	 case INPUT:
	 	              GPIOC->PUPDR &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber))));
			          GPIOC->PUPDR |= ((GPIO_PinConfig->pinInputType) << (2*(GPIO_PinConfig->pinNumber))); /*Pull up or pull down or not selection.*/
				 break;
				 case OUTPUT:
		        	  GPIOC->OTYPER &= (~(0x1 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
					  GPIOC->OTYPER |= ((GPIO_PinConfig->pinOutputType) << (GPIO_PinConfig->pinNumber));/*Push pull or open drain selection.*/

					  GPIOC->OSPEEDR &= (~(0x3 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
					  GPIOC->OSPEEDR |= ((GPIO_PinConfig->pinSpeed) << (2*(GPIO_PinConfig->pinNumber))); /*Speed selection.*/
				 break;
				 case ALT_FUNC:
					  GPIOC->OTYPER &= (~(0x1 << (2*(GPIO_PinConfig->pinNumber)))); /*Make sure that the selected bit is equal to zero before starting write.*/
					  GPIOC->OTYPER |= ((GPIO_PinConfig->pinOutputType) << (GPIO_PinConfig->pinNumber));/*Push pull or open drain selection.*/
				 break;
				 case ANALOG:
				 break;
				 default:
					  returnType = GPIO_NOT_OK;
				 break;
			  }
		break;
		default:
		returnType = GPIO_NOT_OK;
		break;
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: MGPIO_vGetPinDirection
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Get the direction of a specific pin.
*******************************************************************/
GPIO_ReturnType MGPIO_vGetPinDirection (GPIO_PIN_Config_t* GPIO_PinConfig , uint32_t* pinDir)
{
	GPIO_ReturnType returnType = GPIO_OK;
	switch(GPIO_PinConfig->portNumber) /*Check the number of the PORT.*/
	{
		case PORTA:
			*pinDir = (((GPIOA->MODER) >> (2*(GPIO_PinConfig->pinNumber))) & 3); /*Read 2 bit of direction.*/
		break;
		case PORTB:
			*pinDir = (((GPIOB->MODER) >> (2*(GPIO_PinConfig->pinNumber))) & 3); /*Read 2 bit of direction.*/
		break;
		case PORTC:
			*pinDir = (((GPIOC->MODER) >> (2*(GPIO_PinConfig->pinNumber))) & 3); /*Read 2 bit of direction.*/
		break;
		default:
			returnType = GPIO_NOT_OK;
		break;
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: MGPIO_vSetPinVal
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Set the value of a specific pin (HIGH OR LOW).
*******************************************************************/
GPIO_ReturnType MGPIO_vSetPinVal (GPIO_PIN_Config_t* GPIO_PinConfig , uint32_t pinVal)
{
	GPIO_ReturnType returnType = GPIO_OK;
	switch(GPIO_PinConfig->portNumber)
	{
		case PORTA:
			switch(pinVal) /*Check the passed value.*/
			{
				case PIN_LOW:
					CLR_BIT(GPIOA->ODR , GPIO_PinConfig->pinNumber); /*LOW OUTPUT.*/
				break;
				case PIN_HIGH:
					SET_BIT(GPIOA->ODR , GPIO_PinConfig->pinNumber); /*HIGH OUTPUT.*/
				break;
				default:
					returnType = GPIO_NOT_OK;
				break;
			}
		break;
		case PORTB:
			switch(pinVal) /*Check the passed value.*/
			{
				case PIN_LOW:
					CLR_BIT(GPIOB->ODR , GPIO_PinConfig->pinNumber); /*LOW OUTPUT.*/
				break;
				case PIN_HIGH:
					SET_BIT(GPIOB->ODR , GPIO_PinConfig->pinNumber); /*HIGH OUTPUT.*/
				break;
				default:
					returnType = GPIO_NOT_OK;
				break;
			}
		break;
		case PORTC:
			switch(pinVal) /*Check the passed value.*/
			{
				case PIN_LOW:
					CLR_BIT(GPIOC->ODR , GPIO_PinConfig->pinNumber); /*LOW OUTPUT.*/
				break;
				case PIN_HIGH:
					SET_BIT(GPIOC->ODR , GPIO_PinConfig->pinNumber); /*HIGH OUTPUT.*/
				break;
				default:
					returnType = GPIO_NOT_OK;
				break;
			}
		break;
		default:
			returnType = GPIO_NOT_OK;
		break;
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: MGPIO_vGetPinVal
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Read the value written to a specific pin (HIGH OR LOW).
*******************************************************************/
GPIO_ReturnType MGPIO_vGetPinVal (GPIO_PIN_Config_t* GPIO_PinConfig, uint32_t* pinVal)
{
	GPIO_ReturnType returnType = GPIO_OK;
	switch(GPIO_PinConfig->portNumber)
	{
		case PORTA:
			*pinVal = READ_BIT(GPIOA->IDR , GPIO_PinConfig->pinNumber);
		break;
		case PORTB:
			*pinVal = READ_BIT(GPIOB->IDR , GPIO_PinConfig->pinNumber);
		break;
		case PORTC:
			*pinVal = READ_BIT(GPIOC->IDR , GPIO_PinConfig->pinNumber);
		break;
		default:
		break;
		}
	return returnType;
}
/*******************************************************************
* Function Name  	: MGPIO_vTogPin
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Toggle a specific pin (HIGH if it is LOW) & (LOW if it is HIGH).
*******************************************************************/
GPIO_ReturnType MGPIO_vTogPin(GPIO_PIN_Config_t* GPIO_PinConfig)
{
	GPIO_ReturnType returnType = GPIO_OK;
	switch(GPIO_PinConfig->portNumber)
	{
		case PORTA:
			TOG_BIT(GPIOA->ODR , GPIO_PinConfig->pinNumber); /*Toggle bit.*/
		break;
		case PORTB:
			TOG_BIT(GPIOB->ODR , GPIO_PinConfig->pinNumber); /*Toggle bit.*/
		break;
		case PORTC:
			TOG_BIT(GPIOC->ODR , GPIO_PinConfig->pinNumber); /*Toggle bit.*/
		break;
		default:
		break;
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: MGPIO_vAltFuncPin
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Select an alternate function to a specific pin (HIGH if it is LOW) & (LOW if it is HIGH).
*******************************************************************/
GPIO_ReturnType MGPIO_vAltFuncPin(GPIO_PIN_Config_t* GPIO_PinConfig)
{
	GPIO_ReturnType returnType = GPIO_OK;
	switch(GPIO_PinConfig->portNumber)
	{
		case PORTA:
			if(GPIO_PinConfig->pinNumber < HALF_PORT_PIN) /*AFR Low register.*/
			{
				GPIOA->AFRL &= (((uint32_t)~15) << (4*GPIO_PinConfig->pinNumber)); /*Make sure that the selected bits are zeros before writing. */
				GPIOA->AFRL |= ((GPIO_PinConfig->AltFuncMode) << (4*GPIO_PinConfig->pinNumber));  /*Set the selected AFR value to a specific pin.*/
			}
			else if((GPIO_PinConfig->pinNumber >= HALF_PORT_PIN) && (GPIO_PinConfig->pinNumber < ALL_PORT_PIN)) /*AFR HIGH register.*/
			{
				GPIOA->AFRH &= (((uint32_t)~15) << (4*(GPIO_PinConfig->pinNumber%8))); /*Make sure that the selected bits are zeros before writing. */
				GPIOA->AFRH |= ((GPIO_PinConfig->AltFuncMode) << (4*(GPIO_PinConfig->pinNumber%8)));   /*Set the selected AFR value to a specific pin.*/
			}
			else
			{
				returnType = GPIO_NOT_OK; /*Invalid input parameter.*/
			}
		break;
		case PORTB:
			if(GPIO_PinConfig->pinNumber < HALF_PORT_PIN) /*AFR Low register.*/
			{
				GPIOB->AFRL &= (((uint32_t)~15) << (4*GPIO_PinConfig->pinNumber)); /*Make sure that the selected bits are zeros before writing. */
				GPIOB->AFRL |= ((GPIO_PinConfig->AltFuncMode) << (4*GPIO_PinConfig->pinNumber));  /*Set the selected AFR value to a specific pin.*/
			}
			else if((GPIO_PinConfig->pinNumber >= HALF_PORT_PIN) && (GPIO_PinConfig->pinNumber < ALL_PORT_PIN)) /*AFR HIGH register.*/
			{
				GPIOB->AFRH &= (((uint32_t)~15) << (4*(GPIO_PinConfig->pinNumber%8))); /*Make sure that the selected bits are zeros before writing. */
				GPIOB->AFRH |= ((GPIO_PinConfig->AltFuncMode) << (4*(GPIO_PinConfig->pinNumber%8)));   /*Set the selected AFR value to a specific pin.*/
			}
			else
			{
				returnType = GPIO_NOT_OK; /*Invalid input parameter.*/
			}
		break;
		case PORTC:
			if(GPIO_PinConfig->pinNumber < HALF_PORT_PIN) /*AFR Low register.*/
			{
				GPIOC->AFRL &= (((uint32_t)~15) << (4*GPIO_PinConfig->pinNumber)); /*Make sure that the selected bits are zeros before writing. */
				GPIOC->AFRL |= ((GPIO_PinConfig->AltFuncMode) << (4*GPIO_PinConfig->pinNumber));  /*Set the selected AFR value to a specific pin.*/
			}
			else if((GPIO_PinConfig->pinNumber >= HALF_PORT_PIN) && (GPIO_PinConfig->pinNumber < ALL_PORT_PIN)) /*AFR HIGH register.*/
			{
				GPIOC->AFRH &= (((uint32_t)~15) << (4*(GPIO_PinConfig->pinNumber%8))); /*Make sure that the selected bits are zeros before writing. */
				GPIOC->AFRH |= ((GPIO_PinConfig->AltFuncMode) << (4*(GPIO_PinConfig->pinNumber%8)));   /*Set the selected AFR value to a specific pin.*/
			}
			else
			{
				returnType = GPIO_NOT_OK; /*Invalid input parameter.*/
			}
		break;
		default:
			returnType = GPIO_NOT_OK;
		break;
	}
	return returnType;
}
/*******************************************************************
* Function Name  	: MGPIO_vGetPortVal
* Input Parameter	: Port number & address of variable to store the port value
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Read the value of a specific port.
*******************************************************************/
GPIO_ReturnType MGPIO_vGetPortVal(uint8_t portNumber, uint16_t* portVal)
{
	GPIO_ReturnType returnType = GPIO_OK;
    switch(portNumber)
	{
    	case PORTA:
    	     *portVal = (uint16_t)(GPIOA->IDR);
    	break;
    	case PORTB:
    		 *portVal = (uint16_t)(GPIOB->IDR);
    	break;
    	case PORTC:
    		 *portVal = (uint16_t)(GPIOC->IDR);
    	break;
    	default:
    		returnType = GPIO_NOT_OK;
    	break;
	}
	return returnType;
}
/*******************************************************************************************************************************************************/
