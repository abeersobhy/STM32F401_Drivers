/****************************************************************
* Auther         : Abeer Sobhy
* File Name      : GPIO_Driver_Interface FILE
* Description    : All declarations of all APIs needed to use GPIO and Interface MACROs are here
****************************************************************/
/*File Guard*/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/******************Include Section******************************/
#include "../../LIB/std_types.h"
#include "GPIO_Private.h"
/****************************************************************/
#define NULL 0L
#define HALF_PORT_PIN  8
#define ALL_PORT_PIN   16
/**********************Struct section****************************/
/****************************************************************/
/*************************Enums Section**************************/
/*GPIO_POERTs*/
typedef enum
{
	PORTA,
	PORTB,
	PORTC
}GPIO_PORTs;
/*GPIO_PINs*/
typedef enum
{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16,
}GPIO_PINs;
/*PIN Speed.*/
typedef enum
{
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED,
    VERY_HIGH_SPEED
}GPIO_SPEED;
/*PIN MODE*/
typedef enum
{
	INPUT,
	OUTPUT,
	ALT_FUNC,
	ANALOG
}GPIO_PIN_MODEs;
/*Input states*/
typedef enum
{
	FLOATING,
	NO_PULL_UP_DOWN = 0,
	PULL_UP,
	PULL_DOWN,
}GPIO_INPUT_STATES;
/*OUTPUT_TYPE*/
typedef enum
{
	PUSH_PULL,
	OPEN_DRAIN
}GPIO_PIN_OUTPUT_TYPEs;
/*GPIO PIN STATE*/
typedef enum
{
	PIN_LOW,
	PIN_HIGH
}GPIO_PIN_VAL;
/*AFR Alternate Function selection.*/
typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}GPIO_ALT_FUNC_SELECT;
/*Return Type of Function.*/
typedef enum
{
	GPIO_OK,
	GPIO_NOT_OK
}GPIO_ReturnType;

/*******************************************************************/
/**************************Functions Declaration Section************/
/*******************************************************************
* Function Name  	: MGPIO_vSetPinDirection
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Set the direction of a specific pin.
*******************************************************************/
GPIO_ReturnType MGPIO_vSetPinDirection (GPIO_PIN_Config_t* GPIO_PinConfig);
/*******************************************************************
* Function Name  	: MGPIO_vGetPinDirection
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Get the direction of a specific pin.
*******************************************************************/
GPIO_ReturnType MGPIO_vGetPinDirection (GPIO_PIN_Config_t* GPIO_PinConfig , uint32_t* pinDir);
/*******************************************************************
* Function Name  	: MGPIO_vSetPinVal
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Set the value of a specific pin (HIGH OR LOW).
*******************************************************************/
GPIO_ReturnType MGPIO_vSetPinVal       (GPIO_PIN_Config_t* GPIO_PinConfig , uint32_t pinVal);
/*******************************************************************
* Function Name  	: MGPIO_vGetPinVal
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Read the value written to a specific pin (HIGH OR LOW).
*******************************************************************/
GPIO_ReturnType MGPIO_vGetPinVal       (GPIO_PIN_Config_t* GPIO_PinConfig, uint32_t* pinVal);
/*******************************************************************
* Function Name  	: MGPIO_vTogPin
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Toggle a specific pin (HIGH OR LOW).
*******************************************************************/
GPIO_ReturnType MGPIO_vTogPin(GPIO_PIN_Config_t* GPIO_PinConfig);
/*******************************************************************/
/*******************************************************************
* Function Name  	: MGPIO_vAltFuncPin
* Input Parameter	: Pointer to GPIO_PIN_Config_t struct of Pin configuration.
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Select an alternate function to a specific pin (HIGH if it is LOW) & (LOW if it is HIGH).
*******************************************************************/
GPIO_ReturnType MGPIO_vAltFuncPin(GPIO_PIN_Config_t* GPIO_PinConfig);
/*******************************************************************
* Function Name  	: MGPIO_vGetPortVal
* Input Parameter	: Port number & address of variable to store the port value
* Return Parameter  : GPIO_ReturnType (OK or NOT_OK)
* Description       : Read the value of a specific port.
*******************************************************************/
GPIO_ReturnType MGPIO_vGetPortVal(uint8_t portNumber, uint16_t* portVal);
#endif
