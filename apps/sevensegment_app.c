/*
 * sevensegment_app.c
 *
 *  Created on: Jul 9, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL // crystal speed
#include <util/delay.h>
#include "../hal/seven_segment/seven_seg.h"
#include "../mcal/DIO/Dio.h"
#define BUTTON Dio_channel_b0
#define ACTIVE_HIGH
#ifdef ACTIVE_LOW
	#define PRESSED low
	#define RELEASED high
#else
	#define PRESSED high
	#define RELEASED low
#endif

int seven_segment_app(void)
{
	int no_of_cars = 0;
	int sw1_flag = 0;
	dio_channel_config(BUTTON , input);
	init_seven_segment();
	display_digit(no_of_cars);

	while(1)
	{
		if(dio_channel_read(BUTTON) == PRESSED && sw1_flag==0)
		{
			_delay_ms(10); //mechanical bounce protection
			if(dio_channel_read(BUTTON) == PRESSED)
			{
				no_of_cars++;
				display_digit(no_of_cars);
				sw1_flag = 1;

			}
		}
		else if(dio_channel_read(BUTTON) == RELEASED)
		{
			_delay_ms(10); //mechanical bounce protection
			if(dio_channel_read(BUTTON) == RELEASED)
			{
				sw1_flag = 0;
			}

		}
	}
	return 0;
}
