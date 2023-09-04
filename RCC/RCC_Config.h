/****************************************************************
* Auther         : Abeer Sobhy
* File Name      : RCC_Config FILE
* Description    : All MACROs used to configure the RCC unit are here
****************************************************************/
/*File Gard.*/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/********************Include Section****************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"

/*Select the RCC Clock Source.*/
#define RCC_CLK_SRC   HSE

/*HSE Mode*/
#define RCC_HSE_MODE HSE_CRYSTAL

#endif
