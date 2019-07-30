/*
 * spi_test_transmition.c
 *
 *  Created on: Jul 29, 2019
 *      Author: mohamed
 */
#define F_CPU  16000000UL
#include <util/delay.h>
#include "../mcal/spi/spi.h"
#include "../mcal/DIO/Dio.h"
void test_SPI_sending(void)
{
	_delay_ms(100);
	dio_channel_config(Dio_channel_b0 , output);
	init_spi(SPI_MASTER_OSC_DIV128 , SPI_CLK_IDLE_LOW , SPI_SAMPLE_RAISING_EDGE);
	while(1)
	{
		dio_channel_set(Dio_channel_b0 , toggle);
		spi_write(0x50);
		_delay_ms(1000);
	}
}
