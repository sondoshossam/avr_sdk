/*
 * timer0_test.c
 *
 *  Created on: Jul 30, 2019
 *      Author: mohamed
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../mcal/timer0/timer0.h"
#include "../mcal/DIO/Dio.h"
#include "../utils/custom_types.h"
#include "../utils/bit_operations.h"
volatile u16_t counts = 0;
#define SREG (*(volatile u8_t*) 0x5F)

void timer0_test(void)
{
	// prescaller = 64
    dio_channel_config(Dio_channel_b0 , output);
    SET_BIT(TIMSK0 , 0); //enable timer 0 over flow interrrupt
	TCCR0B = (TCCR0B & 0xf8) | 0x03;
    SET_BIT(SREG , 7); //enable golabe interrupt
	while(1)
	{

	}


}


ISR(TIMER0_OVF_vect)
{
	counts++;
	if(counts>=1000)
	{
		dio_channel_set(Dio_channel_b0 , toggle);
		counts = 0;

	}
}


