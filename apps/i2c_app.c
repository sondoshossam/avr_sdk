/*
 * i2c_app.c
 *
 *  Created on: Jul 30, 2019
 *      Author: mohamed
 */
#define F_CPU  16000000UL
#include <util/delay.h>
#include "../mcal/iic/iic.h"
#include "../mcal/DIO/Dio.h"
void test_iic(void)
{
	u8_t value_to_be_store = 0xAA;
	dio_channel_config(Dio_channel_c4 , output);
	dio_channel_config(Dio_channel_c5 , output);
	init_i2c(100000UL);//10us
    _delay_ms(300);
    i2c_start(0xA2);
    i2c_write(0x02);
    i2c_write(0xAA);
    i2c_stop();
	_delay_ms(100);
	i2c_start(0xA0);
	i2c_write(0x02);
	i2c_write(0xAA);
	i2c_stop();
}

