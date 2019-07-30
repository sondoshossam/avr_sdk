/*
 * spi_atmega328p_reg.h
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_SPI_SPI_ATMEGA328P_REG_H_
#define MCAL_SPI_SPI_ATMEGA328P_REG_H_
/*
 *spi control register
 *
 * */
#define SPIE  0x07 //SPIE: SPI Interrupt Enable
#define SPE   0x06 //SPI Enable
/*Data Order
 * 1 the LSB of the data word is transmitted first.
 * 0 the MSB of the data word is transmitted first.
 * */
#define DORD  0x05
/*
 * 1 Master SPI mode
 * 0 Slave
 * */
#define MSTR  0x04
/*
 * Clock Polarity
 * 0 Rising
 * 1 Faling
 * */
#define CPOL  0x03
/*
 * Clock Phase
 * */
#define CPHA  0x02
/*
 * SPI Clock Rate
 * */
#define SPR1  0x01
#define SPR0  0x00
#define SPCR  (*(volatile u8_t*) 0x4c)

#define SPIF  0x07
#define WCOL  0x06
#define SPI2X  0x00
#define SPSR (*(volatile u8_t*) 0x4D)


#define SPDR (*(volatile u8_t*) 0x4E) // data register
#endif /* MCAL_SPI_SPI_ATMEGA328P_REG_H_ */
