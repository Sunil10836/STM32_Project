/*
 * RTC_LCD.h
 *
 *  Created on: Apr 30, 2024
 *      Author: Sunil
 */

#ifndef RTC_LCD_H_
#define RTC_LCD_H_

#include "../bsp/ds1307.h"
#include "../bsp/lcd.h"

#define SYSTICK_TIM_CLK		16000000UL

void RTC_Set_Time(void);
void RTC_Set_Date(void);

void RTC_Print_Time(void);
void RTC_Print_Date(void);

char* get_day_of_week(uint8_t i);
char* date_to_string(RTC_date_t *rtc_date);
char* time_to_string(RTC_time_t *rtc_time);
void number_to_string(uint8_t num, char* buf);
static void delay_ms(uint32_t cnt);
void systick_timer_init(uint32_t tick_hz);

#endif /* RTC_LCD_H_ */
