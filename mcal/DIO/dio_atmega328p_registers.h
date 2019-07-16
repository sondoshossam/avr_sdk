/*
 * dio_atmega328p_registers.h
 *
 *  Created on: Jul 2, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_DIO_DIO_ATMEGA328P_REGISTERS_H_
#define MCAL_DIO_DIO_ATMEGA328P_REGISTERS_H_
//port b
#define DDRB  (*(volatile u8_t*) 0x24)
#define PORTB (*(volatile u8_t*) 0x25)
#define PINB  (*(volatile u8_t*) 0x23)
//port c
#define DDRC  (*(volatile u8_t*) 0x27)
#define PORTC (*(volatile u8_t*) 0x28)
#define PINC  (*(volatile u8_t*) 0x26)

//port d
#define DDRD  (*(volatile u8_t*) 0x2A)
#define PORTD (*(volatile u8_t*) 0x2B)
#define PIND  (*(volatile u8_t*) 0x29)

#endif /* MCAL_DIO_DIO_ATMEGA328P_REGISTERS_H_ */
