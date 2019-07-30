/*
 * external_dac.c
 *
 *  Created on: Jul 29, 2019
 *      Author: mohamed
 */
#define F_CPU  16000000UL
#include <util/delay.h>
#include "../utils/custom_types.h"
#include "../mcal/spi/spi.h"
#include "../mcal/DIO/Dio.h"
void dac_output(u16_t val);
void external_dac()
{
	_delay_ms(100);
	dio_channel_config(Dio_channel_b0 , output);
	dio_channel_set(Dio_channel_b0 , high);
	init_spi(SPI_MASTER_OSC_DIV128 , SPI_CLK_IDLE_LOW , SPI_SAMPLE_RAISING_EDGE);
	dac_output(1024);
}
void dac_output(u16_t val) {

  u8_t tmp;
  dio_channel_set(Dio_channel_b0 , low);
  // Send High Byte
  tmp = (val >> 8) & 0x0F;
  tmp |= 0x30;
  spi_write(tmp);
  tmp = (u8_t)(val & 255);
  spi_write(tmp);
  dio_channel_set(Dio_channel_b0 , high);
}

