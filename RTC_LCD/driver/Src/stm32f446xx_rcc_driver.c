/*
 * stm32f446xx_rcc_driver.c
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */

#include "stm32f446xx_rcc_driver.h"

uint16_t AHB_PreScalar[9] = {2,4,8,16,32,64,128,256,512};

uint16_t APB1_PreScalar[4] = {2,4,8,16};

/*********************************************************************
 * @fn      		  - RCC_GetPCLK1Value
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t pclk1, SystemClk;

	uint8_t clksrc, temp, ahbpr, apb1pr;
	//RCC_CFGR_SWS :  Clk Source
	clksrc = (RCC->CFGR >> 2) & 0x03;
	if(clksrc == 0)
	{
		SystemClk = 16000000;	//HSI
	}
	else if(clksrc == 1)
	{
		SystemClk = 8000000;	//HSE
	}
	else if(clksrc == 2)
	{
		SystemClk = RCC_GetPLLOutputClock();		//PLL
	}

	//RCC_CFGR_HPRE : AHB Prescaler
	temp = (RCC->CFGR >> 4) & 0x0F;
	if(temp < 8)
	{
		ahbpr = 1;
	}
	else
	{
		ahbpr = AHB_PreScalar[temp - 8];
	}

	//RCC_CFGR_PPRE1 : APB1 Prescaler
	temp = (RCC->CFGR >> 10) & 0x07;
	if(temp < 4)
	{
		apb1pr = 1;
	}
	else
	{
		apb1pr = APB1_PreScalar[temp - 4];
	}

	pclk1 = ( (SystemClk / ahbpr) / apb1pr);

	return pclk1;
}


/*********************************************************************
 * @fn      		  - RCC_GetPCLK2Value
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint32_t RCC_GetPCLK2Value(void)
{
	uint32_t SystemClock=0,tmp,pclk2;
	uint8_t clk_src = ( RCC->CFGR >> 2) & 0X3;

	uint8_t ahbp,apb2p;

	if(clk_src == 0)
	{
		SystemClock = 16000000;
	}else
	{
		SystemClock = 8000000;
	}
	tmp = (RCC->CFGR >> 4 ) & 0xF;

	if(tmp < 0x08)
	{
		ahbp = 1;
	}else
	{
       ahbp = AHB_PreScalar[tmp-8];
	}

	tmp = (RCC->CFGR >> 13 ) & 0x7;
	if(tmp < 0x04)
	{
		apb2p = 1;
	}else
	{
		apb2p = APB1_PreScalar[tmp-4];
	}

	pclk2 = (SystemClock / ahbp )/ apb2p;

	return pclk2;
}


uint32_t RCC_GetPLLOutputClock()
{
	uint32_t pllclk = 0;
	//TODO
	return pllclk;
}

