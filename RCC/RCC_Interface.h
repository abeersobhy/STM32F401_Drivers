/****************************************************************
* Auther         : Abeer Sobhy
* File Name      : RCC_Driver_Interface FILE
* Description    : All declarations of all APIs needed to use RCC unit and Interface MACROs are here
****************************************************************/
/*File Guard*/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
/******************Include Section******************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
/************************************************************/
/*Maximum available ID for selected pripheral.*/
#define MAX_PeripheralID 31
/*OTGFSEN MACRO in RCC_AHB2ENR Register.*/
#define OTGFSEN 7
/****************************************************************/
/**************************************************Enums Section**********************************************/
/*Enum to select the clock source*/
typedef enum
{
	HSE_PYBASS,
	HSE_CRYSTAL,
}RCC_HSE_MODE;

typedef enum
{
	HSI,
	HSE,
	PLL
}ClockSource;

/*RCC_CFGR_BITs*/
typedef enum
{
	SW0			,
	SW1			,
	SWS0		,
	SWS1		,
	HPRE0		,
	HPRE1		,
	HPRE2		,
	HPRE3		,
	RES0		,
	RES1		,
	PPRE1_0		,
	PPRE1_1		,
	PPRE1_2		,
	PPRE2_0		,
	PPRE2_1		,
	PPRE2_2		,
	RTCPRE0		,
	RTCPRE1		,
	RTCPRE2		,
	RTCPRE3		,
	RTCPRE4		,
	MCO1_0		,
	MCO1_1		,
	I2SSRC		,
	MCO1PRE0	,
	MCO1PRE1	,
	MCO1PRE2	,
	MCO2PRE0	,
	MCO2PRE1	,
	MCO2PRE2    ,
	MCO2_0      ,
	MCO2_1
}RCC_CFGR_BITs;
/*RCC_CR_BITs*/
typedef enum
{
	HSION      ,
	HSIRDY     ,
	RES2       ,
	HSITRIM0   ,
	HSITRIM1   ,
	HSITRIM2   ,
	HSITRIM3   ,
	HSITRIM4   ,
	HSICAL0    ,
	HSICAL1    ,
	HSICAL2    ,
	HSICAL3    ,
	HSICAL4    ,
	HSICAL5    ,
	HSICAL6    ,
	HSICAL7    ,
	HSEON      ,
	HSERDY     ,
	HSEBYP     ,
	CSSON      ,
	RES3       ,
	RES4       ,
	RES5       ,
	RES6       ,
	PLLON      ,
	PLLRDY     ,
	PLLI2SON   ,
	PLLI2SRDY  ,
	RES7       ,
	RES8       ,
	RES9       ,
	RES10       ,
}RCC_CR_BITs;

/*RCC_AHB1ENR_BITs*/
typedef enum
{
	GPIOAEN,
	GPIOBEN,
	GPIOCEN,
	GPIODEN,
	GPIOEEN,
	RES11,
	RES12,
	GPIOHEN,
	RES13,
	RES14,
	RES15,
	RES16,
	CRCEN,
	RES17,
	RES18,
	RES19,
	RES20,
	RES21,
	RES22,
	RES23,
	RES24,
	DMA1EN,
	DMA2EN,
	RES25,
	RES26,
	RES27,
	RES28,
	RES29,
	RES30,
	RES31,
	RES32,
	RES33
}RCC_AHB1ENR_BITs;

/*RCC_APB1ENR_BITs*/
typedef enum
{
	TIM2EN,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	RES34,
	RES35,
	RES36,
	RES37,
	RES38,
	RES39,
	RES40,
	WWDGEN,
	RES41,
	RES42,
	SPI2EN,
	SPI3EN,
	RES43,
	USART2EN,
	RES44,
	RES45,
	RES46,
	I2C1EN,
	I2C2EN,
	I2C3EN,
	RES47,
	RES48,
	RES49,
	RES50,
	PWREN,
	RES51,
	RES52,
	RES53
}RCC_APB1ENR_BITs;
/*RCC APB2ENR BITs*/
typedef enum
{
	TIM1EN,
	RES54,
	RES55,
	RES56,
	USART1EN,
	USART6EN,
	RES57,
	RES58,
	ADC1EN,
	RES59,
	RES60,
	SDIOEN,
	SPI1EN,
	SPI4EN,
	SYSCFGEN,
	RES61,
	TIM9EN,
	TIM10EN,
	TIM11EN
}RCC_APB2ENR_BITs;
/*Bus Interface MACROs.*/
typedef enum
{
	AHB1,
	AHB2,
	APB1,
	APB2
}Interface_t;

/*Retuen status of Enabe selected prephiral.*/
typedef enum
{
	RCC_OK,
	RCC_NOT_OK
}RCC_ReturnType;
/*************************************************************************************************************/
/*************************************Function Declaration Section********************************************/
/****************************************************************
* Function Name  	: RCC_voidInitSysClc
* Input Parameter	: void
* Return Parameter  : void
* Description       : Initialize the RCC system clock
****************************************************************/
void RCC_voidInitSysClc           (void);
/****************************************************************
* Function Name  	: RCC_voidEnablePrepheralCLK
* Input Parameter	: Copy_u8BusID (ID of the BUS) & Copy_u8PeripheralID (ID of the Peripheral)
* Return Parameter  : RCC_ReturnType
* Description       : Function to Enable the Peripheral clock
****************************************************************/
RCC_ReturnType RCC_voidEnablePrepheralCLK   (uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID);
/****************************************************************
* Function Name  	: RCC_voidDisablePrepheralCLK
* Input Parameter	: Copy_u8BusID (ID of the BUS) & Copy_u8PeripheralID (ID of the Peripheral)
* Return Parameter  : RCC_ReturnType
* Description       : Function to Disable the Peripheral clock
****************************************************************/
RCC_ReturnType RCC_voidDisablePrepheralCLK  (uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID);
/*************************************************************************************************************/
#endif
