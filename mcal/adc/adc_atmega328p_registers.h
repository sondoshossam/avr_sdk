/*
 * adc_atmega328p_registers.h
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_ADC_ADC_ATMEGA328P_REGISTERS_H_
#define MCAL_ADC_ADC_ATMEGA328P_REGISTERS_H_
/*ADC Multiplexer Selection Register
 * 1- to select the conversion ref
 * 2- to select the channel
 * */
#define ADMUX  (*(volatile u8_t*) 0x7C)
/*ADC Control and Status Register A
 * 1- to enable the module
 * 2- to start conversion
 * 3- to choose Clk Prescaler
 * */
#define ADCSRA (*(volatile u8_t*) 0x7A)

/* store conversion value*/
#define ADCH  (*(volatile u8_t*) 0x79)
#define ADCL  (*(volatile u8_t*) 0x78)
/*
 * ADC Control and Status Register B
 * */
#define ADCSRB (*(volatile u8_t*) 0x7B)
/*
 * Digital Input Disable Register 0
 * ADC5D..ADC0D: ADC5..0 Digital Input Disable
 * */
#define DIDR0 (*(volatile u8_t*) 0x7E)

#endif /* MCAL_ADC_ADC_ATMEGA328P_REGISTERS_H_ */
