/*
 * iic_atmega328p_reg.h
 *
 *  Created on: Jul 29, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"

#ifndef MCAL_IIC_IIC_ATMEGA328P_REG_H_
#define MCAL_IIC_IIC_ATMEGA328P_REG_H_
/*TWDR – TWI Data Register*/
#define TWDR      		*((volatile u8_t*)0xBB)
/*TWAR – TWI (Slave) Address Register*/
#define TWAR			*((volatile u8_t*)0xBA)
/*TWI Control Register*/
#define TWINT  0x07
#define TWEA   0x06
#define TWSTA  0x05
#define TWSTO  0x04
#define TWWC   0x03
#define TWEN   0x02

#define TWIE   0x00

#define TWCR			*((volatile u8_t*)0xBC)
/*TWI Status Register*/
#define TWSR			*((volatile u8_t*)0xB9)
/*TWI Bit Rate Register*/
#define TWBR			*((volatile u8_t*)0xB8)
#endif /* MCAL_IIC_IIC_ATMEGA328P_REG_H_ */
