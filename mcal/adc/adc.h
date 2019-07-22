/*
 * adc.h
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
typedef enum
{
	ADC_CH0 = 0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4
}adc_channel_t;
void init_adc(void);
u16_t adc_channel_read(adc_channel_t channel);
float get_analog_value(adc_channel_t channel);
#endif /* MCAL_ADC_ADC_H_ */
