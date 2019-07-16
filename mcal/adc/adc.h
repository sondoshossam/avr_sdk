/*
 * adc.h
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
void init_adc(void);
u16_t adc_channel_read(u8_t channel);
float get_analog_value(u8_t channel);
#endif /* MCAL_ADC_ADC_H_ */
