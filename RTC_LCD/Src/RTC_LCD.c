/*
 * RTC_LCD.c
 *
 *  Created on: Apr 28, 2024
 *      Author: Sunil
 */

#include <stdio.h>
#include "../Inc/RTC_LCD.h"

int main()
{
	printf("RTC Test\n");

	if(RTC_DS1307_Init())
	{
		printf("RTC Init Failed\n");
		while(1);
	}

	systick_timer_init(1);

	LCD_Init();

	LCD_Send_String("RTC Test...");
	delay_ms(2000);

	LCD_Display_Clear();
	LCD_Display_Resturn_Home();

	RTC_Set_Time();

	RTC_Set_Date();

	RTC_Print_Time();

	RTC_Print_Date();

	return 0;
}

void systick_timer_init(uint32_t tick_hz)
{
	uint32_t *pSRVR = (uint32_t*)0xE000E014;
	uint32_t *pSCSR = (uint32_t*)0xE000E010;

    /* calculation of reload value */
    uint32_t count_value = (SYSTICK_TIM_CLK/tick_hz)-1;

    //Clear the value of SVR
    *pSRVR &= ~(0x00FFFFFFFF);

    //load the value in to SVR
    *pSRVR |= count_value;

    //do some settings
    *pSCSR |= ( 1 << 1); //Enables SysTick exception request:
    *pSCSR |= ( 1 << 2);  //Indicates the clock source, processor clock source

    //enable the systick
    *pSCSR |= ( 1 << 0); //enables the counter

}

void SysTick_Handler(void)
{
	LCD_Set_Cursor(1, 1);

	RTC_Print_Time();

	RTC_Print_Date();

}

void RTC_Set_Time(void)
{
	RTC_time_t current_time;

	current_time.hours = 2;
	current_time.minutes = 44;
	current_time.seconds = 30;
	current_time.time_format = TIME_FORMAT_12HRS_PM;

	RTC_DS1307_Set_Current_Time(&current_time);
}

void RTC_Set_Date(void)
{
	RTC_date_t current_date;

	current_date.day = MONDAY;
	current_date.date = 29;
	current_date.month = 4;
	current_date.year = 24;

	RTC_DS1307_Set_Current_Date(&current_date);
}

void RTC_Print_Date(void)
{
	RTC_date_t current_date;

	RTC_DS1307_Get_Current_Date(&current_date);

	//Print Date => 29/04/24 <MONDAY>
	//printf("Current Date : %s <%s>\n", date_to_string(&current_date), get_day_of_week(current_date.day));
	LCD_Set_Cursor(2, 1);
	LCD_Send_String(date_to_string(&current_date));
	LCD_Send_Data('<');
	LCD_Send_String(get_day_of_week(current_date.day));
	LCD_Send_Data('>');
}

void RTC_Print_Time(void)
{
	RTC_time_t current_time;

	RTC_DS1307_Get_Current_Time(&current_time);

	char *am_pm;
	if(current_time.time_format != TIME_FORMAT_24HRS)
	{
		//12 Hour Format
		if(current_time.time_format == TIME_FORMAT_12HRS_PM)
		{
			am_pm = "PM";
		}
		else
		{
			am_pm = "AM";
		}
		//printf("Current Time : %s %s\n",time_to_string(&current_time), am_pm);	//02:44:30 PM
		LCD_Send_String(time_to_string(&current_time));
		LCD_Send_String(am_pm);
	}
	else
	{
		//24 Hour format
		//printf("Current Time : %s\n",time_to_string(&current_time));	//02:44:30
		LCD_Send_String(time_to_string(&current_time));
	}
}

char* get_day_of_week(uint8_t i)
{
	char* days[] = {"SUN", "MON","TUES","WED","THU","FRI","SAT"};
	return days[i-1];
}

void number_to_string(uint8_t num, char* buf)
{
	if(num < 10)
	{
		buf[0] = '0';
		buf[1] = num + 48;			//ASCII Value
	}
	else if(num >= 10 && num < 99)
	{
		buf[0] = (num / 10) + 48;
		buf[1] = (num % 10) + 48;
	}
}

//TIME => HH:MM:SS
char* time_to_string(RTC_time_t *rtc_time)
{
	static char buf[9];

	buf[2] = ':';
	buf[5] = ':';

	number_to_string(rtc_time->hours, buf);   //buf = buf[0]
	number_to_string(rtc_time->hours, &buf[3]);
	number_to_string(rtc_time->hours, &buf[6]);
	buf[8] = '\0';

	return buf;
}

//DATE => DD/MM/YY
char* date_to_string(RTC_date_t *rtc_date)
{
	static char buf[9];

	buf[2] = '/';
	buf[5] = '/';

	number_to_string(rtc_date->date, buf);  	 //buf = &buf[0]
	number_to_string(rtc_date->month, &buf[3]);
	number_to_string(rtc_date->year, &buf[6]);

	buf[8] = '\0';

	return buf;
}

static void delay_ms(uint32_t cnt)
{
	for(uint32_t i=0; i < (cnt * 1000); i++);
}


