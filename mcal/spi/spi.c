/*
 * spi.c
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#include "../../mcal/DIO/Dio.h"
#include "../../utils/bit_operations.h"
#include "spi_atmega328p_reg.h"
#include "spi.h"
#define SPEED_MASK 0xFC
#define SS_PIN   Dio_channel_b2 // slave select(SS)
#define MOSI_PIN Dio_channel_b3 // master out slave in(SDO)
#define MISO_PIN Dio_channel_b4 // master in slave out(SDi)
#define CLK_PIN Dio_channel_b5
void init_spi(spi_mode_t mode, spi_transmit_edge_t transmit_edge, spi_clock_idle_t clock_idle)
{

	// select idel level
	if(clock_idle == SPI_CLK_IDLE_LOW)
	{
		CLR_BIT( SPCR , CPOL);
	}
	else
	{
		SET_BIT( SPCR , CPOL);
	}
	// sample edge
	if(transmit_edge == SPI_SAMPLE_RAISING_EDGE)
	{
		CLR_BIT( SPCR , MSTR);
	}
	else
	{
		SET_BIT( SPCR , MSTR);
	}
	// select mode
	if (mode == SPI_SLAVE)
	{
		dio_channel_config(MOSI_PIN , input);
		dio_channel_config(CLK_PIN  , input);
		dio_channel_config(SS_PIN , input);
		dio_channel_config(MISO_PIN , output);
		CLR_BIT(SPCR , MSTR); // select slave mode

	}
	else
	{
		dio_channel_config(MOSI_PIN , output);
		dio_channel_config(CLK_PIN  , output);
		dio_channel_config(MISO_PIN , input);
		SET_BIT(SPCR , MSTR); // select master mode
        if(mode < SPI_MASTER_OSC_DIV2)
        {
        	CLR_BIT(SPSR , SPI2X); // half speed mode
        	SPCR = (SPCR & SPEED_MASK) | mode;
        }
        else
        {
        	SET_BIT(SPSR , SPI2X); // full speed mode
        	SPCR = (SPCR & SPEED_MASK) | (mode&SPEED_MASK);
        }

	}
	//enable spi
	SET_BIT( SPCR , SPE);
}
void spi_write(u8_t cData)
{
	u8_t tmp;
	SPDR = cData;
	/* Wait for transmission complete */
	while(READ_BIT(SPSR , SPIF) == 0);
	tmp = SPDR; // dummy read
}
u8_t spi_read(u8_t dummy_byte)
{
	/* Wait for reception complete */
	SPDR = dummy_byte;
	while(READ_BIT(SPSR , SPIF) == 0);
	return SPDR;
}
