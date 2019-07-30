/*
 * iic.h
 *
 *  Created on: Jul 29, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_IIC_IIC_H_
#define MCAL_IIC_IIC_H_
void init_i2c(u32_t bit_rate);
bool_t i2c_start(u8_t address);
bool_t i2c_write(u8_t data);
bool_t i2c_read_ack(void);
bool_t i2c_read_nack(void);
bool_t i2c_transmit(u8_t address, u8_t* data, u8_t length);
bool_t i2c_receive(u8_t address, u8_t* data, u8_t length);
void i2c_stop(void);
#endif /* MCAL_IIC_IIC_H_ */
