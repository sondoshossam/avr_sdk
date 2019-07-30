/*
 * pwm_app.c
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 *      20ms 50HZ
 *
 */
#define F_CPU 16000000UL
#include "util/delay.h"
#include "../utils/bit_operations.h"
#include "../mcal/timer1_pwm/timer1_pwm.h"
void test_pwm(void)
{
	u8_t i = 0;
    init_pwm(50 , enable_both ,  pulse_noninverted);

    	// 18 angle 0  ->>>8
    	//62 angle 180 ->> 31
    for(i = 18 ; i < 63 ; i++ )
    {
    	pwm_change_duty(oc1a_ch , i);
    	_delay_ms(1000);
    }


}

