/*
 * fire_sensor.c
 *
 *  Created on: Jul 23, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../hal/h_bridge/h_bridge.h"
#include "../utils/custom_types.h"
#include "../mcal/DIO/Dio.h"
#include "../mcal/usart/usart.h"
#include "../mcal/adc/adc.h"
void fire_app(void)
{
	u16_t received_measure;
	u8_t text[10];
	dio_channel_config(Dio_channel_d1 , output); // tx output
	dio_channel_config(Dio_channel_d0 , input); // rx output
	init_adc();
	init_usart(9600);
	while(1)
	{
		received_measure = adc_channel_read(ADC_CH0);
		itoa(received_measure ,text ,10);
		usart_write_text(text);
		usart_write_text("\n\r"); // new line
		_delay_ms(1000);
	}
}
