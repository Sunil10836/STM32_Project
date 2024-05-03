/*
 * ds1307.c
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */
#include <stdint.h>
#include <string.h>
#include "ds1307.h"

static void RTC_DS1307_I2C_Pin_Config(void);
static void RTC_DS1307_I2C_Config(void);

static void RTC_DS1307_Write(uint8_t value, uint8_t reg_addr);
static uint8_t RTC_DS1307_Read(uint8_t reg_addr);

static uint8_t BCD_to_Binary(uint8_t value);
static uint8_t Binary_to_BCD(uint8_t value);

I2C_Handle_t RTC_I2CHandle;

/*
 * RTC_DS1307_Init
 * returns 1 : CH = 1 : Init Failed
 * returns 0 : CH = 0 : Init Sucess
 */
uint8_t RTC_DS1307_Init()
{
	//1. Initialize the I2C Pins
	RTC_DS1307_I2C_Pin_Config();

	//2. Initialize I2C Peripheral
	RTC_DS1307_I2C_Config();

	//3. Enable I2C Peripheral
	I2C_PeripheralControl(RTC_DS1307_I2C, ENABLE);

	//4. Make Clock Halt zero(CH=0)
	RTC_DS1307_Write(0x00, RTC_DS1307_ADDR_SEC);

	//5.Read Back Clock Halt bit
	uint8_t clock_state = RTC_DS1307_Read(RTC_DS1307_ADDR_SEC);

	return ((clock_state >> 7) & 0x01);

}

void RTC_DS1307_Set_Current_Time(RTC_time_t *rtc_time)
{
	uint8_t seconds, minutes, hours;

	//Set seconds Register
	seconds = Binary_to_BCD(rtc_time->seconds);
	seconds &= (1 << 7);	//Make Clock Halt CH=0 (Bit 7)
	RTC_DS1307_Write(seconds, RTC_DS1307_ADDR_SEC);

	//Set Minute Register
	minutes = Binary_to_BCD(rtc_time->minutes);
	RTC_DS1307_Write(minutes, RTC_DS1307_ADDR_MIN);

	//Set Hour Register
	hours = Binary_to_BCD(rtc_time->hours);

	if(rtc_time->time_format == TIME_FORMAT_24HRS)
	{
		//24 Hour Time Format
		//Bit 6 of Hours register is zero
		hours &= ~(1 << 6);
	}
	else
	{
		//12 Hour Time Format
		//Bit 6 of Hours register is 1
		hours |= (1 << 6);

		//Check AM or PM time format
		if(rtc_time->time_format == TIME_FORMAT_12HRS_PM)
		{
			//12 Hours PM Format
			//Set bit 5 of hour register(bit 5 = 1)
			hours |= (1 << 5);
		}
		else
		{
			//12 Hours AM Format
			//Clear bit 5 of hour register(bit 5 = 0)
			hours &= ~(1 << 5);
		}
	}

	RTC_DS1307_Write(hours, RTC_DS1307_ADDR_HRS);
}

void RTC_DS1307_Get_Current_Time(RTC_time_t *rtc_time)
{
	uint8_t seconds, minutes, hours;

	//Get Seconds
	seconds = RTC_DS1307_Read(RTC_DS1307_ADDR_SEC);
	seconds &= ~(1 << 7);	//Clock Halt : CH=0
	rtc_time->seconds = BCD_to_Binary(seconds);

	//Get Minutes
	minutes = RTC_DS1307_Read(RTC_DS1307_ADDR_MIN);
	rtc_time->minutes = BCD_to_Binary(minutes);

	//Get Hour
	hours = RTC_DS1307_Read(RTC_DS1307_ADDR_HRS);

	//Check Time Format : Bit 6 of Hour Register
	if(hours & (1 << 6))
	{
		//12 Hour Format
		//Check AM or PM : Bit 5 of Hour Register
		if(hours & (1 << 5))
		{
			//12 Hours time format : PM
			rtc_time->time_format = TIME_FORMAT_12HRS_PM;
			hours &= ~(1 << 5);
			hours &= ~(1 << 6);
		}
		else
		{
			//12 Hours time format : AM
			rtc_time->time_format = TIME_FORMAT_12HRS_AM;
			hours &= ~(1 << 5);
			hours &= ~(1 << 6);
		}
	}
	else
	{
		//24 Hour Format
		rtc_time->time_format = TIME_FORMAT_24HRS;
	}

	rtc_time->hours = BCD_to_Binary(hours);

}

void RTC_DS1307_Set_Current_Date(RTC_date_t *rtc_date)
{
	uint8_t day, date, month, year;

	//Set Date Register
	date = Binary_to_BCD(rtc_date->date);
	RTC_DS1307_Write(date, RTC_DS1307_ADDR_DATE);

	//Set Month Register
	month = Binary_to_BCD(rtc_date->month);
	RTC_DS1307_Write(month, RTC_DS1307_ADDR_MONTH);

	//Set Year Register
	year = Binary_to_BCD(rtc_date->year);
	RTC_DS1307_Write(year, RTC_DS1307_ADDR_YEAR);

	//Set Day Register
	day = Binary_to_BCD(rtc_date->day);
	RTC_DS1307_Write(day, RTC_DS1307_ADDR_DAY);

}

void RTC_DS1307_Get_Current_Date(RTC_date_t *rtc_date)
{
	uint8_t day, date, month, year;

	//Get Date
	date = RTC_DS1307_Read(RTC_DS1307_ADDR_DATE);
	rtc_date->date = BCD_to_Binary(date);

	//Get Month
	month = RTC_DS1307_Read(RTC_DS1307_ADDR_MONTH);
	rtc_date->month = BCD_to_Binary(month);

	//Get Year
	year = RTC_DS1307_Read(RTC_DS1307_ADDR_YEAR);
	rtc_date->year = BCD_to_Binary(year);

	//Get Day
	day = RTC_DS1307_Read(RTC_DS1307_ADDR_DAY);
	rtc_date->day = BCD_to_Binary(day);

}

static void RTC_DS1307_I2C_Pin_Config(void)
{
	GPIO_Handle_t i2c_sda, i2c_scl;

	memset(&i2c_scl, 0, sizeof(i2c_scl));
	memset(&i2c_scl, 0, sizeof(i2c_scl));

	/*
	 * I2C_SCL	=> PB6
	 * i2c_scl	=> PB7
	 */
	i2c_sda.pGPIOx = RTC_DS1307_I2C_GPIO_PORT;	//GPIOB
	i2c_sda.GPIO_PinConfig.GPIO_PinNumber = RTC_DS1307_I2C_SDA_PIN;
	i2c_sda.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALT_FN;
	i2c_sda.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
	i2c_sda.GPIO_PinConfig.GPIO_PinOType = GPIO_OP_TYPE_OD;
	i2c_sda.GPIO_PinConfig.GPIO_PuPdControl = GPIO_PIN_PU;
	i2c_sda.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&i2c_sda);

	i2c_scl.pGPIOx = RTC_DS1307_I2C_GPIO_PORT;	//GPIOB
	i2c_scl.GPIO_PinConfig.GPIO_PinNumber = RTC_DS1307_I2C_SCL_PIN;
	i2c_scl.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALT_FN;
	i2c_scl.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
	i2c_scl.GPIO_PinConfig.GPIO_PinOType = GPIO_OP_TYPE_OD;
	i2c_scl.GPIO_PinConfig.GPIO_PuPdControl = GPIO_PIN_PU;
	i2c_scl.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&i2c_scl);
}

static void RTC_DS1307_I2C_Config(void)
{
	RTC_I2CHandle.pI2Cx = RTC_DS1307_I2C;	//I2C1
	RTC_I2CHandle.I2C_Config.I2C_ACKControl = I2C_ACK_ENABLE;
	RTC_I2CHandle.I2C_Config.I2C_SCLSpeed = RTC_DS1307_I2C_SPEED;

	I2C_Init(&RTC_I2CHandle);
}

static void RTC_DS1307_Write(uint8_t value, uint8_t reg_addr)
{
	uint8_t tx[2];
	tx[0] = reg_addr;
	tx[1] = value;
	I2C_MasterSendData(&RTC_I2CHandle, tx, 2, RTC_DS1307_I2C_ADDRESS, 0);
}

static uint8_t RTC_DS1307_Read(uint8_t reg_addr)
{
	uint8_t data;
	I2C_MasterSendData(&RTC_I2CHandle, &reg_addr, 1, RTC_DS1307_I2C_ADDRESS, 0);
	I2C_MasterReceiveData(&RTC_I2CHandle, &data, 1, RTC_DS1307_I2C_ADDRESS, 0);
	return data;
}

static uint8_t Binary_to_BCD(uint8_t value)
{
	uint8_t m, n, bcd;

	bcd = value;		//If value < 10 then bcd = value

	if(value >= 10)
	{
		m = value / 10;
		n = value % 10;
		bcd = (uint8_t)((m << 4) | n);
	}

	return bcd;
}

static uint8_t BCD_to_Binary(uint8_t value)
{
	uint8_t m, n, binary;

	m = (uint8_t) ((value >> 4) * 10);
	n = value & (uint8_t)0x0F;
	binary = m + n;

	return binary;
}

