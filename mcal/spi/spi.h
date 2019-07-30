/*
 * spi.h
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_
typedef enum
{
	SPI_MASTER_OSC_DIV4,
	SPI_MASTER_OSC_DIV16,
	SPI_MASTER_OSC_DIV64,
	SPI_MASTER_OSC_DIV128,
	SPI_MASTER_OSC_DIV2,
	SPI_MASTER_OSC_DIV8,
	SPI_MASTER_OSC_DIV32,
	SPI_SLAVE
}spi_mode_t;
typedef enum
{
	SPI_CLK_IDLE_LOW,
	SPI_CLK_IDLE_HIGH
}spi_clock_idle_t;
typedef enum
{
	SPI_SAMPLE_RAISING_EDGE,
	SPI_SAMPLE_FALING_EDGE
}spi_transmit_edge_t;
void init_spi(spi_mode_t mode, spi_transmit_edge_t transmit_edge, spi_clock_idle_t clock_idle);
void spi_write(u8_t cData);
u8_t spi_read(u8_t dummy_byte);
#endif /* MCAL_SPI_SPI_H_ */
