/*
 * timer0_atmega328p_regs.h
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */

#ifndef MCAL_TIMER0_TIMER0_ATMEGA328P_REGS_H_
#define MCAL_TIMER0_TIMER0_ATMEGA328P_REGS_H_
/* control register a
 * 1- mode (normal / compare ....)
 *
 *
 * */
#define TCCR0A  (*(volatile u8_t*) 0x44)
#define TCCR0B  (*(volatile u8_t*) 0x45)
/* timer hold bottom value */
#define TCNT0  (*(volatile u8_t*) 0x46)
/*compare registers*/
#define OCR0A  (*(volatile u8_t*) 0x47)
#define OCR0B  (*(volatile u8_t*) 0x48)

#define TIMSK0 (*(volatile u8_t*) 0x6E)
#define TIFR0  (*(volatile u8_t*) 0x35)
#endif /* MCAL_TIMER0_TIMER0_ATMEGA328P_REGS_H_ */
