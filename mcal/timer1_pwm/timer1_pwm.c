/*
 * timer1_pwm.c
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */

#include "../DIO/Dio.h"
#include "../../utils/custom_types.h"
#include "timer1_pwm_atmega328p_reg.h"
#include "timer1_pwm.h"
#define CLK_SELECTION_MASK 0xF8
#define NO_CLK       0x00
#define CLK_DIV_1    0x01
#define CLK_DIV_8    0x02
#define CLK_DIV_64   0x03
#define CLK_DIV_256  0x04
#define CLK_DIV_1024 0x05
#define CLK_EXT_FALL 0x06
#define CLK_EXT_RAIS 0x07

#define COMA_DISCONECTED      0x00
#define COMA_TOGGEL           0x40
#define COMA_NON_INVERTING    0x80 // 1000 0000
#define COMA_INVERTING        0xC0 // 1100 0000

#define COMB_DISCONECTED      0x00
#define COMB_TOGGEL           0x10
#define COMB_NON_INVERTING    0x20 // 0010 0000
#define COMB_INVERTING        0x30 // 0011 0000

#define COMA_MASK            0x3F  //0011 1111
#define COMB_MASK            0xCF
// 1 1 1 0
// 4  3  1  0
#define MODE_LO_MASk         0xFC //11111100
#define MODE_HI_MASk         0xE7 //1110 0111
#define MODE_LO_VALUE        0x02  //0b0000010
#define MODE_HI_VALUE        0x18  //0b00011000
#define MIN_FREQ 31
#define MAX_FREQ 4000
static u16_t frequencey_config = 0;
static u16_t top_value = 0;

void init_pwm(u16_t frequencey , pwm_opm_t config_ch_option , pwm_invM_t inv_op)
{
      if(frequencey < MIN_FREQ)
      {
    	  frequencey_config = MIN_FREQ;
      }
      else if (frequencey > MAX_FREQ)
      {
    	  frequencey_config = MAX_FREQ;
      }else
      {
    	  frequencey_config = frequencey;
      }

      if(config_ch_option == enable_oc1a)
      {
    	  dio_channel_config(Dio_channel_b1 , output);
    	  if(inv_op == pulse_inverted)
    	  {
    		  TCCR1A = (TCCR1A & COMA_MASK) | COMA_INVERTING;
    	  }
    	  else
    	  {
    		  TCCR1A = (TCCR1A & COMA_MASK) | COMA_NON_INVERTING;
    	  }
    	  TCCR1A = (TCCR1A & COMB_MASK) | COMB_DISCONECTED;
      }
      if(config_ch_option == enable_oc1b)
		{
		  dio_channel_config(Dio_channel_b2 , output);
		  if(inv_op == pulse_inverted)
		  {
			  TCCR1A = (TCCR1A & COMB_MASK) | COMB_INVERTING;
		  }
		  else
		  {
			  TCCR1A = (TCCR1A & COMB_MASK) | COMB_NON_INVERTING;
		  }
		  TCCR1A = (TCCR1A & COMA_MASK) | COMA_DISCONECTED;
		}
      else
      {
    	  dio_channel_config(Dio_channel_b2 , output);
    	  dio_channel_config(Dio_channel_b1 , output);
    	  if(inv_op == pulse_inverted)
		  {
			  TCCR1A = (TCCR1A & COMB_MASK) | COMB_INVERTING;
			  TCCR1A = (TCCR1A & COMA_MASK) | COMA_INVERTING;
		  }
		  else
		  {
			  TCCR1A = (TCCR1A & COMB_MASK) | COMB_NON_INVERTING;
			  TCCR1A = (TCCR1A & COMA_MASK) | COMA_NON_INVERTING;
		  }
      }
      // select pwm mode
	  TCCR1A = (TCCR1A & MODE_LO_MASk) | MODE_LO_VALUE ;
	  TCCR1B = (TCCR1B & MODE_HI_MASk) | MODE_HI_VALUE;
      // wanted_fre = 1000
      // wanted_period = 1/wanted_fre = 1ms
      // N * t_count = wanted_period
      // top = wanted_period/t_count = (1/wanted_fre ) / (prescaller/f_cpu)
      // top = (f_cpu)/(prescaller *wanted_fre)
	  top_value = (F_CPU/frequencey_config)/8.0;
	  ICR1H = (u8_t)(top_value>>8);
	  ICR1L = (u8_t)top_value;
	  TCCR1B = (TCCR1B & CLK_SELECTION_MASK)|CLK_DIV_8;
}
void pwm_change_duty(pwm_channel_t channel , u16_t dc)
{
	u16_t update_value = 0;
	update_value = (top_value/512.0)*dc;
	if(channel == oc1a_ch)
	{
		OCR1AH = (u8_t)(update_value>>8);
	    OCR1AL =  update_value;
	}
	else if(channel == oc1b_ch)
	{
		OCR1BH = (u8_t)(update_value>>8);
	    OCR1BL =  update_value;
	}
}
