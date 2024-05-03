/*
 * lcd.h
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f446xx.h"

/*************** Application Configurable Items ***********/

#define LCD_GPIO_PORT		GPIOD

#define LCD_GPIO_RS			GPIO_PIN_0
#define LCD_GPIO_RW			GPIO_PIN_1
#define LCD_GPIO_EN			GPIO_PIN_2
#define LCD_GPIO_D4			GPIO_PIN_3
#define LCD_GPIO_D5			GPIO_PIN_4
#define LCD_GPIO_D6			GPIO_PIN_5
#define LCD_GPIO_D7			GPIO_PIN_6

/******************* LCD Commands *************************/

#define LCD_CMD_4DL_2N_5X8F			0x28		/* Function Set : 4bit DL, 2 Lines, 5*8 dots */
#define LCD_CMD_DIS_CLEAR			0x01		/* Display Clear */
#define LCD_CMD_DON_CURON			0x0E		/* Display ON/OFF Control */
#define LCD_CMD_DIS_RETURN_HOME		0x02		/* Return Home */
#define LCD_CMD_INCADD				0x06		/* Entry Set Mode Command */


/******************** LCD API Prototype *******************/

void LCD_Init(void);
void LCD_Send_Command(uint8_t cmd);
void LCD_Send_Data(uint8_t data);
void LCD_Send_String(char *str);
void LCD_Display_Clear(void);
void LCD_Display_Resturn_Home(void);
void LCD_Set_Cursor(uint8_t row, uint8_t col);

#endif /* LCD_H_ */
