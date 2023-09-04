/****************************************************************
*Author    	 : Abeer Sobhy
*File Name 	 : RCC_Program.c
*Description : This file consists of the implementation of all APIs
               needed to use the RCC unit in ARM Cortex M4
*****************************************************************/
/********************Include Section****************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
/****************************************************************
* Function Name  	: RCC_voidInitSysClc
* Input Parameter	: void
* Return Parameter  : void
* Description       : Initialize the RCC system clock
****************************************************************/
void RCC_voidInitSysClc(void)
{
    #if RCC_CLK_SRC == HSE
        #if(RCC_HSE_MODE == HSE_CRYSTAL)
			CLR_BIT((RCC_CR),HSEBYP); /*HSE CRYSTAL on.*/
	    #elif(RCC_HSE_MODE == HSE_BYBASS)
			SET_BIT((RCC->RCC_CR),HSEBYP);
		#else
			#error "Invalid HSE Mode"
		#endif
			SET_BIT(RCC_CR , HSEON); /*HSEON Enabled*/
			while (READ_BIT((RCC_CR),HSERDY) == 0); /*Wait until External high-speed clock ready.*/
			RCC_CFGR &= (~0x3); /*Make the first two bits equal to zero.*/
			RCC_CFGR |= HSE; /*: HSE oscillator selected as system clock*/
    #elif RCC_CLK_SRC == HSI

	    RCC->RCC_CFGR &= (~0x3); /*Make the first two bits equal to zero.*/
	    RCC->RCC_CFGR |= HSI; /*: HSI oscillator selected as system clock*/
	    SET_BIT(RCC->RCC_CR , HSION); /*HSION Enabled*/
		while (READ_BIT((RCC->RCC_CR),HSIRDY) == 0); /*Wait until Internal high-speed clock ready.*/

	#elif (RCC_CLK_SRC == PLL)
		RCC->RCC_CFGR &= (~0x3); /*Make the first two bits equal to zero.*/
	    RCC->RCC_CFGR |= PLL; /*: PLL selected as system clock*/
		SET_BIT(RCC->RCC_CR , PLLON); /*PLLON Enabled*/

	#else
		#error "Configuration parameters is not supported"

    #endif
}
/****************************************************************
* Function Name  	: RCC_voidEnablePrepheralCLK
* Input Parameter	: Copy_u8BusID (ID of the BUS) & Copy_u8PeripheralID (ID of the Peripheral)
* Return Parameter  : RCC_ReturnType OK or NOT_OK
* Description       : Function to Enable the Peripheral clock
****************************************************************/
RCC_ReturnType RCC_voidEnablePrepheralCLK   (uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID)
{
	RCC_ReturnType ReturnType = RCC_OK; /*Every thing is OK.*/
    if((Copy_u8BusID > APB2) || (Copy_u8PeripheralID > MAX_PeripheralID))
	{
		ReturnType = RCC_NOT_OK; /*Unavailable behavior*/
	}
	else
	{
		switch(Copy_u8BusID)
		{
			case AHB1:
				SET_BIT(RCC_AHB1ENR ,Copy_u8PeripheralID); /*Enable the selected peripheral.*/
			break;
			case AHB2:
				if(Copy_u8PeripheralID != OTGFSEN)
				{
					ReturnType = RCC_NOT_OK; /*Unavailable behavior*/
				}
				else
				{
					SET_BIT(RCC_AHB2ENR ,Copy_u8PeripheralID); /*USB OTG FS clock enabled.*/
				}
			break;
			case APB1:
				SET_BIT(RCC_APB1ENR ,Copy_u8PeripheralID); /*Enable the selected peripheral.*/
			break;
			case APB2:
				SET_BIT(RCC_APB2ENR ,Copy_u8PeripheralID); /*Enable the selected peripheral.*/
			break;
			default:
			ReturnType = RCC_NOT_OK; /*Unavailable behavior*/
			break;

		}
	}
    return ReturnType;
}
/****************************************************************
* Function Name  	: RCC_voidDisablePrepheralCLK
* Input Parameter	: Copy_u8BusID (ID of the BUS) & Copy_u8PeripheralID (ID of the Peripheral)
* Return Parameter  : RCC_ReturnType OK or NOT_OK
* Description       : Function to Disable the Peripheral clock
****************************************************************/
RCC_ReturnType RCC_voidDisablePrepheralCLK   (uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID)
{
	RCC_ReturnType ReturnType = RCC_OK; /*Every thing is OK.*/
    if((Copy_u8BusID > APB2) || (Copy_u8PeripheralID > MAX_PeripheralID))
	{
		ReturnType = RCC_NOT_OK; /*Unavailable behavior*/
	}
	else
	{
		switch(Copy_u8BusID)
		{
			case AHB1:
				CLR_BIT(RCC_AHB1ENR ,Copy_u8PeripheralID); /*Disable the selected peripheral.*/
			break;

			case AHB2:
				if(Copy_u8PeripheralID != OTGFSEN)
				{
					ReturnType = RCC_NOT_OK; /*Unavailable behavior*/
				}
				else
				{
					CLR_BIT(RCC_AHB2ENR ,Copy_u8PeripheralID); /*USB OTG FS clock Disabled.*/
				}
			break;

			case APB1:
				CLR_BIT(RCC_APB1ENR ,Copy_u8PeripheralID); /*Disable the selected peripheral.*/
			break;

			case APB2:
				CLR_BIT(RCC_APB2ENR ,Copy_u8PeripheralID); /*Disable the selected peripheral.*/
			break;

			default:
			ReturnType = RCC_NOT_OK; /*Unavailable behavior*/
			break;

		}
	}
    return ReturnType;
}
