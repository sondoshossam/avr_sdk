/*
 * adc_app.c
 *
 *  Created on: Jul 18, 2019
 *      Author: mohamed
 */
#ifdef ADC_APP
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include "../utils/custom_types.h"
#include "../hal/lcd/lcd.h"
#include "../mcal/adc/adc.h"
#include "../mcal/DIO/Dio.h"
#define INC_BTN Dio_channel_d0
#define DEC_BTN Dio_channel_d1
#define HEATER_PIN Dio_channel_d2
#define FAN_PIN Dio_channel_d3
void init_system(void);
void turn_fan_on(void);
void turn_heater_on(void);
void switch_off_all(void);
void adc_app(void)
{
	float voltage = 0;
	u8_t temp;
	char mystr[10];
	u8_t set_point = 18;
	init_system();
	lcd_write_text("temprture:" , 1 , 1);
	itoa(temp, mystr, 10);
	lcd_write_text_cp(mystr);
	lcd_write_text("set p:" , 2 , 1);
	itoa(set_point, mystr, 10);
	lcd_write_text_cp(mystr);
	while(1)
	{
		//read temprture
		voltage = get_analog_value(ADC_CH0);
		temp = 100 * voltage;
		itoa(temp, mystr, 10);
		lcd_write_text("temprture:" , 1 , 1);
		lcd_write_text_cp(mystr);
		if(temp > set_point)
		{
			turn_fan_on();
		}
		else if(temp < set_point)
		{
			turn_heater_on();
		}
		else
		{
			switch_off_all();
		}
		if(dio_channel_read(INC_BTN) == low)
		{
			set_point++;
			lcd_write_text("set p:" , 2 , 1);
			itoa(set_point, mystr, 10);
			lcd_write_text_cp(mystr);
			while(dio_channel_read(INC_BTN) == low);
		}
		if(dio_channel_read(DEC_BTN) == low )
		{
			set_point--;
			lcd_write_text("set p:" , 2 , 1);
			itoa(set_point, mystr, 10);
			lcd_write_text_cp(mystr);
			while(dio_channel_read(DEC_BTN) == low);
		}
		_delay_ms(100);
	}
}
void init_system(void)
{
	_delay_ms(100);
	init_lcd();
	init_adc();
	dio_channel_config(INC_BTN , input_pullup);
	dio_channel_config(DEC_BTN , input_pullup);
	dio_channel_config(HEATER_PIN , output);
	dio_channel_config(FAN_PIN , output);
	dio_channel_set(HEATER_PIN , low);
	dio_channel_set(FAN_PIN , low);

}
void turn_fan_on(void)
{
	dio_channel_set(HEATER_PIN , low);
	dio_channel_set(FAN_PIN , high);
}
void turn_heater_on(void)
{
	dio_channel_set(HEATER_PIN , high);
	dio_channel_set(FAN_PIN , low);
}
void switch_off_all(void)
{
	dio_channel_set(HEATER_PIN , low);
	dio_channel_set(FAN_PIN , low);
}
#endif
