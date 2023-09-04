/****************************************************************
* Aouther        : Abeer Sobhy
* File Name      : GPIO_Driver_Private FILE
* Description    : All Registers' MACROs needed to use GPIO peripheral are here
****************************************************************/
/*File Guard.*/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
/******************Include Section******************************/
#include "../../LIB/std_types.h"
/**************************************************************/
/*************************Structs Section**************************/
/*GPIO Registers Struct.*/
typedef struct
{
	volatile uint32_t MODER    ; /*00*/
	volatile uint32_t OTYPER   ; /*04*/
	volatile uint32_t OSPEEDR  ; /*08*/
	volatile uint32_t PUPDR    ; /*0C*/
	volatile uint32_t IDR      ; /*10*/
	volatile uint32_t ODR      ; /*14*/
	volatile uint32_t BSRR     ; /*18*/
	volatile uint32_t LCKR     ; /*1C*/
	volatile uint32_t AFRL     ; /*20*/
	volatile uint32_t AFRH     ; /*24*/
}GPIO_MemMap_t;

/*Pin Configuration struct.*/
typedef struct
{
	uint8_t pinNumber      ;
	uint8_t portNumber     ;
	uint8_t pinDirection   ;
	uint8_t pinValue       ;
	uint8_t pinOutputType  ;
	uint8_t pinInputType   ;
	uint8_t pinSpeed       ;
	uint8_t AltFuncMode    ;
}GPIO_PIN_Config_t;

/*******************************************************************/
/*****************MACROs Section************************************/
/*PORTs Base Address.*/
#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

/*MACROs to Pointers to GPIO struct.*/

#define GPIOA ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC ((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDRESS))

/******************************************************************/
#endif
