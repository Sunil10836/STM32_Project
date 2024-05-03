/*
 * lcd.c
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */


#include "lcd.h"

void LCD_GPIO_Pin_Config();
static void LCD_Write_4bits(uint8_t value);
static void LCD_Enable(void);
static void delay_ms(uint32_t cnt);
static void delay_us(uint32_t cnt);

void LCD_Init(void)
{
	//1. Configure GPIO Pins which are used for LCD Connection
	LCD_GPIO_Pin_Config();

	//2. LCD Initialization
	delay_ms(40);

	/*RS=0 for LCD Command */
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_RESET);

	/*R/nW=0 for LCD Write */
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);

	LCD_Write_4bits(0x3);
	delay_ms(5);

	LCD_Write_4bits(0x3);
	delay_us(150);

	LCD_Write_4bits(0x3);
	LCD_Write_4bits(0x2);

	//Function Set Command
	LCD_Send_Command(LCD_CMD_4DL_2N_5X8F);

	//Display ON/OFF Control
	LCD_Send_Command(LCD_CMD_DON_CURON);

	//Display Clear Command
	LCD_Display_Clear();

	//Entry mode set
	LCD_Send_Command(LCD_CMD_INCADD);

}

void LCD_GPIO_Pin_Config()
{
	GPIO_Handle_t lcd_signal;

	lcd_signal.pGPIOx = LCD_GPIO_PORT;
	lcd_signal.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	lcd_signal.GPIO_PinConfig.GPIO_PinOType = GPIO_OP_TYPE_PP;
	lcd_signal.GPIO_PinConfig.GPIO_PuPdControl = GPIO_NO_PUPD;
	lcd_signal.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_RS;
	GPIO_Init(&lcd_signal);

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_RW;
	GPIO_Init(&lcd_signal);

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_EN;
	GPIO_Init(&lcd_signal);

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_D4;
	GPIO_Init(&lcd_signal);

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_D5;
	GPIO_Init(&lcd_signal);

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_D6;
	GPIO_Init(&lcd_signal);

	lcd_signal.GPIO_PinConfig.GPIO_PinNumber = LCD_GPIO_D7;
	GPIO_Init(&lcd_signal);

	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_EN, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D4, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D5, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D6, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D7, GPIO_PIN_RESET);

}

/* Writes 4 bits of data/command on tp  D4 D5 D6 D7 lines*/
//Shift data to LSB position
static void LCD_Write_4bits(uint8_t value)
{
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D4, ((value >> 0) & 0x1));
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D5, ((value >> 1) & 0x1));
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D6, ((value >> 2) & 0x1));
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_D7, ((value >> 3) & 0x1));

	LCD_Enable();
}

void LCD_Send_Command(uint8_t cmd)
{
	/*RS=0 for LCD Command */
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_RESET);

	/*R/nW=0 for LCD Write */
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);

	LCD_Write_4bits(cmd >> 4);		//Send Higher Nibble
	LCD_Write_4bits(cmd & 0x0F);	//Send Lower Nibble

}

void LCD_Send_Data(uint8_t data)
{
	/*RS=1 for LCD User Data */
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_SET);

	/*R/nW=0 for LCD Write */
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);

	LCD_Write_4bits(data >> 4);		//Send Higher Nibble
	LCD_Write_4bits(data & 0x0F);	//Send Lower Nibble

}

void LCD_Send_String(char *str)
{
	while(*str != '\0')
	{
		LCD_Send_Data((uint8_t)*str++);
	}
}

static void LCD_Enable(void)
{
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_EN, GPIO_PIN_SET);
	delay_us(10);
	GPIO_WriteToOutputPin(LCD_GPIO_PORT, LCD_GPIO_EN, GPIO_PIN_RESET);
	delay_us(100);
}

void LCD_Display_Clear(void)
{
	//Display Clear Command
	LCD_Send_Command(LCD_CMD_DIS_CLEAR);
	delay_ms(2);
}

void LCD_Display_Resturn_Home(void)
{
	//Display Clear Command
	LCD_Send_Command(LCD_CMD_DIS_RETURN_HOME);
	delay_ms(2);
}

void LCD_Set_Cursor(uint8_t row, uint8_t col)
{
	col--;
	switch(row)
	{
		case 1:
			//Set the Cursor to the 1st row address and add index
			col |= 0x80;	//First Row Address : 0X80
			break;
		case 2:
			//Set the Cursor to the 2nd row address and add index
			col |= 0xC0;
			break;
		default:
			break;
	}
	LCD_Send_Command(col);
}

static void delay_ms(uint32_t cnt)
{
	for(uint32_t i=0; i < (cnt * 1000); i++);
}

static void delay_us(uint32_t cnt)
{
	for(uint32_t i=0; i < (cnt * 1); i++);
}
