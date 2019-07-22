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
 * 2- to choose result justification
 * */
#define ADMUX  (*(volatile u8_t*) 0x7C)
/* to select ref
 * REFS1 REFS0
 *  0     0          EXternal
 *  0     1          AVCC
 *  1     1          1.1 internal ref
 * */
#define REFS1 7
#define REFS0 6
/* result justification we set it to one if we want to read the
 * Hi register only and skip the two least significant bits*/
#define ADLAR 5
/*
 * to select the channel
 * */
#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0
/*ADC Control and Status Register A
 * 1- to enable the module
 * 2- to start conversion
 * 3- to choose Clk Prescaler
 * */
#define ADCSRA (*(volatile u8_t*) 0x7A)
#define ADEN   7 /* to enable adc 1 means turn on */
#define ADSC   6 /* put 1 to start the conversion  this bit cleared by th adc after the conversion */
#define ADATE  5
#define ADIF   4
#define ADIE   3
/*to divide the main clk by factor
 * By default, the successive approximation circuitry requires an input clock frequency between 50
kHz and 200 kHz to get maximum resolution. If a lower resolution than 10 bits is needed, the
input clock frequency to the ADC can be higher than 200 kHz to get a higher sample rate.
 * */
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0
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
