/*
 * ultra_sonic.c
 *
 *  Created on: Jul 23, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../mcal/DIO/Dio.h"
#include "../mcal/usart/usart.h"
#include "../mcal/timer1/timer1.h"
#define TRIG_PIN Dio_channel_d7
#define ECHO_PIN Dio_channel_d6
void ultra_sonic_app(void)
{
	u16_t el_time_us = 0;
	u16_t distance_cm = 0;
	u8_t dis_as_str[7];
	_delay_ms(100);
	dio_channel_config(TRIG_PIN , output);
	dio_channel_config(ECHO_PIN , input);
	dio_channel_set(TRIG_PIN , low);
	init_usart(9600);
	init_timer1();
	_delay_ms(100);
	while(1)
	{
		// send trig pulse
		dio_channel_set(TRIG_PIN , high);
		_delay_us(10);
		dio_channel_set(TRIG_PIN , low);
		reset_timer1();
		// wait for echo
		while(dio_channel_read(ECHO_PIN) == low);
		start_timer1();
		while(dio_channel_read(ECHO_PIN) == high);
		stop_timer1();
		// convert to distance

		el_time_us = get_timer1_counts()>>2; // divide by 4

        distance_cm = 0.0331 * el_time_us ; // 331 m/s * 10**-6 * 100*time_us
		// convert distance to string
        utoa(distance_cm ,dis_as_str,10);
		// send string through uart to pc
        usart_write_text(dis_as_str);
        usart_write_char('\n');
        usart_write_char('\r');
		// wait for 3 seconds
        _delay_ms(3000);
	}

}
