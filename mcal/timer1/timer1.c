/*
 * timer0.c
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#include "../../utils/bit_operations.h"
#include "timer1_atmega328p_regs.h"
#include "time.h"
#define CLK_SELECTION_MASK 0xF8
#define NO_CLK       0x00
#define CLK_DIV_1    0x01
#define CLK_DIV_8    0x02
#define CLK_DIV_64   0x03
#define CLK_DIV_256  0x04
#define CLK_DIV_1024 0x05
#define CLK_EXT_FALL 0x06
#define CLK_EXT_RAIS 0x07

void init_timer1(void)
{
    //set mode normal
	TCCR1A = 0x00;
	CLR_BIT(TCCR1B , WGM13);
	CLR_BIT(TCCR1B , WGM12);
	//select clock source
	TCCR1B = (TCCR1B & CLK_SELECTION_MASK)|NO_CLK;  //stop timer
}
void start_timer1(void)
{
	TCCR1B |= (TCCR1B & CLK_SELECTION_MASK)|CLK_DIV_8; //count every 0.5us
}
void stop_timer1(void)
{
	TCCR1B = (TCCR1B & CLK_SELECTION_MASK)|NO_CLK;
}
u16_t get_timer1_counts(void)
{
   u16_t timer1_val = 0;
   u8_t lower_register=0;
   lower_register = TCNT1L;
   timer1_val = TCNT1H;
   timer1_val = timer1_val<<8;
   timer1_val |= lower_register;
   return timer1_val;
}
void reset_timer1(void)
{
	TCNT1H = 0x00;
	TCNT1L = 0x00;
}
