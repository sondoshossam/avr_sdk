/*
 * lcd_app.c
 *
 *  Created on: Jul 11, 2019
 *      Author: mohamed
 */
#ifdef LCD_APP
#define F_CPU 16000000UL
#include <stdlib.h>
#include <util/delay.h>
#include "../utils/custom_types.h"
#include "../hal/lcd/lcd.h"
#include "../mcal/DIO/Dio.h"
char* int_str(char* str , u16_t num , u8_t size);
int lcd_app(void)
{
	u16_t num_of_cars = 0 ;
	char* mystr[10];
	dio_channel_config(Dio_channel_d0 , input_pullup);
	dio_channel_config(Dio_channel_d1 , input_pullup);
	init_lcd();

	while(1)
	{
		//itoa(val, mystr, 10);
		if(dio_channel_read(Dio_channel_d0) == low)
		{
			num_of_cars++;
			while(dio_channel_read(Dio_channel_d0) == low);
		}
		if(dio_channel_read(Dio_channel_d1) == low && num_of_cars>0)
		{
			num_of_cars--;
			while(dio_channel_read(Dio_channel_d1) == low);
		}

		lcd_write_char(num_of_cars/10 +48 , 1 , 1);
		lcd_write_char_cp(num_of_cars%10 +48);
		_delay_ms(100);
	}
	return 0;
}
char* int_str(char* str , u16_t num , u8_t size )
{
	size--;
	str[size] = 0;
	while(num!=0)
	{
		size--;
		str[size] = (num%10)+48;
		num= num /10;
	}
	return &str[size];
}
#endif
