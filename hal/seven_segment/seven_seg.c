/*
 * seven_seg.c
 *
 *  Created on: Jul 9, 2019
 *      Author: mohamed
 */
#include "seven_seg.h"
#include "seven_seg_config.h"
#include "../../mcal/DIO/Dio.h"
#include "../../utils/custom_types.h"
#include "../../utils/bit_operations.h"
//private variable
const u8_t segDataCathod[]={63,6,91,79,102,109,125,7,127,111};

//function declaration
void display_digit_private(u8_t digit);

void init_seven_segment()
{
    dio_channel_config(SEG_PINA , output);
    dio_channel_config(SEG_PINB , output);
    dio_channel_config(SEG_PINC , output);
    dio_channel_config(SEG_PIND , output);
    dio_channel_config(SEG_PINE , output);
    dio_channel_config(SEG_PINF , output);
    dio_channel_config(SEG_PING , output);
#if CURRENT_SEGMENT == COMMON_CATHOD
    display_digit_private(0);
#elif CURRENT_SEGMENT == COMMON_ANODE
    display_digit_private(255);
#else
  # warning "you have to choose segment type first"
#endif

}
void display_digit(u8_t digit)
{
     if(digit<10)
     {
          #if CURRENT_SEGMENT == COMMON_CATHOD
    	      display_digit_private(segDataCathod[digit]);
          #else
    	      display_digit_private(~segDataCathod[digit]);
          #endif
     }
}
//function definition
void display_digit_private(u8_t digit)
{
	dio_channel_set(SEG_PINA , READ_BIT(digit , 0));
	dio_channel_set(SEG_PINB , READ_BIT(digit , 1));
	dio_channel_set(SEG_PINC , READ_BIT(digit , 2));
	dio_channel_set(SEG_PIND , READ_BIT(digit , 3));
	dio_channel_set(SEG_PINE , READ_BIT(digit , 4));
	dio_channel_set(SEG_PINF , READ_BIT(digit , 5));
	dio_channel_set(SEG_PING , READ_BIT(digit , 6));
}

