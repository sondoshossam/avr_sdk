/*
 * adc.c
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#include "../../utils/bit_operations.h"
#include "adc.h"
#include "adc_atmega328p_registers.h"
#define VREF  5.0
#define RES_DIV 1024.0  // 2^n
void init_adc(void)
{
    //turn the adc on
    SET_BIT(ADCSRA , ADEN);
	//select the frequency
    // the selected fre = 16000000/128 = 125K
    SET_BIT(ADCSRA , ADPS2);
    SET_BIT(ADCSRA , ADPS1);
    SET_BIT(ADCSRA , ADPS0);
	//choose Reference
    //select the avcc ref
    CLR_BIT(ADMUX , REFS1);
    SET_BIT(ADMUX , REFS0);
	//choose result justification
    CLR_BIT(ADMUX , ADLAR);

}
u16_t adc_channel_read(adc_channel_t channel)
{
    u8_t low_value;
    u16_t digital_value;
    //select channel
	ADMUX = (ADMUX & 0XF0) | channel;
	//start measurement
     SET_BIT(ADCSRA, ADSC);
	//while conversion in progress
    while(READ_BIT(ADCSRA, ADSC))
    {
        // do nothing
    }
	//return the conversion result
    low_value = ADCL;
    digital_value = ADCH;
    digital_value = digital_value<<8;
    digital_value = digital_value | low_value;
    return digital_value;
}
float get_analog_value(adc_channel_t channel)
{
	u8_t low_value =0;
	u16_t digital_value = 0;
	float voltage = 0;
	//select channel
	ADMUX = (ADMUX & 0XF0) | channel;
	//start measurement
	 SET_BIT(ADCSRA, ADSC);
	//while conversion in progress
	while(READ_BIT(ADCSRA, ADSC))
	{
		// do nothing
	}
	//return the conversion result
	low_value = ADCL;
	digital_value = ADCH;
	digital_value = digital_value<<8;
	digital_value = digital_value | low_value;
	//map reading to voltage by multiplying it by resolution
	voltage = digital_value*(VREF/RES_DIV);
	return voltage;
}
