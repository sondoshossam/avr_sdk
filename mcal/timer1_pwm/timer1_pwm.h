/*
 * timer1_pwm.h
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_TIMER1_PWM_TIMER1_PWM_H_
#define MCAL_TIMER1_PWM_TIMER1_PWM_H_
typedef enum
{
	enable_oc1a,
	enable_oc1b,
	enable_both
}pwm_opm_t;
typedef enum
{
	oc1a_ch,
	oc1b_ch
}pwm_channel_t;
typedef enum
{
	pulse_inverted,
	pulse_noninverted
}pwm_invM_t;
/*
 * initialize pwm
 * @pram frequencey min 30HZ and the maximum is 7KHZ
 *
 * */
void init_pwm(u16_t frequencey , pwm_opm_t config_ch_option , pwm_invM_t inv_op);
/*
 * map dc from 0 to Period
 * */
void pwm_change_duty(pwm_channel_t channel , u16_t dc);

#endif /* MCAL_TIMER1_PWM_TIMER1_PWM_H_ */
