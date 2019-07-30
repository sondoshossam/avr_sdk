/*
 * timer1_pwm_atmega328p_reg.h
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_TIMER1_PWM_TIMER1_PWM_ATMEGA328P_REG_H_
#define MCAL_TIMER1_PWM_TIMER1_PWM_ATMEGA328P_REG_H_
#define TCCR1A  (*(volatile u8_t*) 0x80)
#define ICNC1 0x07
#define ICES1 0x06
/**/
#define WGM13 0x04
#define WGM12 0x03
#define CS12  0x02
#define CS11  0x01
#define CS10  0x00
#define TCCR1B  (*(volatile u8_t*) 0x81)
#define TCCR1C  (*(volatile u8_t*) 0x82)

/* timer hold bottom value */
#define TCNT1L  (*(volatile u8_t*) 0x84)
#define TCNT1H  (*(volatile u8_t*) 0x85)
/*compare registers*/
#define OCR1AL  (*(volatile u8_t*) 0x88)
#define OCR1AH  (*(volatile u8_t*) 0x89)

#define OCR1BL  (*(volatile u8_t*) 0x8A)
#define OCR1BH  (*(volatile u8_t*) 0x8B)
/* top registers */
#define ICR1L  (*(volatile u8_t*) 0x86)
#define ICR1H  (*(volatile u8_t*) 0x87)




#endif /* MCAL_TIMER1_PWM_TIMER1_PWM_ATMEGA328P_REG_H_ */
