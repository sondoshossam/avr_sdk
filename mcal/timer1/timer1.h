/*
 * timer0.h
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_
void init_timer1(void);
void start_timer1(void);
void stop_timer1(void);
u16_t get_timer1_counts(void);
void reset_timer1(void);
#endif /* MCAL_TIMER0_TIMER0_H_ */
