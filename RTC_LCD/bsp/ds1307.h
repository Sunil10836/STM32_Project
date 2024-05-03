/*
 * ds1307.h
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */

#ifndef DS1307_H_
#define DS1307_H_

#include "stm32f446xx.h"

/*
 * Application Configurable Items
 */
#define RTC_DS1307_I2C				I2C1

#define RTC_DS1307_I2C_GPIO_PORT	GPIOB
#define RTC_DS1307_I2C_SDA_PIN		GPIO_PIN_7
#define RTC_DS1307_I2C_SCL_PIN		GPIO_PIN_6

#define RTC_DS1307_I2C_SPEED		I2C_SCL_SPEED_SM
#define RTC_DS1307_I2C_PUPD			GPIO_PIN_PU					//GPIO_NO_PUPD		//No internal Pull-up/Pull-down : External Pullups is used

/*
 * DS1307 RTC Register Address
 */
#define RTC_DS1307_ADDR_SEC			0x00
#define RTC_DS1307_ADDR_MIN			0x01
#define RTC_DS1307_ADDR_HRS			0x02
#define RTC_DS1307_ADDR_DAY			0x03
#define RTC_DS1307_ADDR_DATE		0x04
#define RTC_DS1307_ADDR_MONTH		0x05
#define RTC_DS1307_ADDR_YEAR		0x06

/*
 * DS1307 RTC Time Format
 */
#define TIME_FORMAT_12HRS_AM		0
#define TIME_FORMAT_12HRS_PM		1
#define TIME_FORMAT_24HRS			2

/*
 * DS1307 RTC I2C Slave Address
 */
#define RTC_DS1307_I2C_ADDRESS		0x68

/*
 * DS1307 RTC Day Information
 */
#define SUNDAY			1
#define MONDAY			2
#define TUESDAY			3
#define WEDNESDAY		4
#define THURDAY			5
#define FRIDAY			6
#define SATDAY			7

/*
 * DS1307 RTC Date Structure
 */

typedef struct
{
	uint8_t date;
	uint8_t month;
	uint8_t year;
	uint8_t day;

}RTC_date_t;

/*
 * DS1307 RTC Time Structure
 */

typedef struct
{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t time_format;

}RTC_time_t;


/********************* RTC Function Prototypes ******************************/

uint8_t RTC_DS1307_Init();

void RTC_DS1307_Set_Current_Time(RTC_time_t *rtc_time);
void RTC_DS1307_Get_Current_Time(RTC_time_t *rtc_time);




void RTC_DS1307_Set_Current_Date(RTC_date_t *rtc_date);
void RTC_DS1307_Get_Current_Date(RTC_date_t *rtc_date);


#endif /* DS1307_H_ */
