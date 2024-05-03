/*
 * stm32f446xx_rcc_driver.h
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */

#ifndef INC_STM32F446XX_RCC_DRIVER_H_
#define INC_STM32F446XX_RCC_DRIVER_H_

#include "stm32f446xx.h"

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);
uint32_t RCC_GetPCLK2Value(void);

uint32_t RCC_GetPLLOutputClock();

#endif /* INC_STM32F446XX_RCC_DRIVER_H_ */
