/*
 * input_output_task.c
 *
 *  Created on: Jul 9, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL // crystal speed
#include <util/delay.h>
#include "../mcal/DIO/Dio.h"
#define BUZZER Dio_channel_b0 //8
#define BUTTON Dio_channel_b1 //9
#define PRESSED high
#define NOT_PRESSED low
int io_task(void)
{
	// direction pins
    dio_channel_config(BUZZER , output);
    dio_channel_config(BUTTON , input);
    //initial values
    dio_channel_set(BUZZER , low);

    while(1) //super
    {
    	if(dio_channel_read(BUTTON) == PRESSED)
    	{
    		dio_channel_set(BUZZER , high);
    	}else
    	{
    		dio_channel_set(BUZZER , low);
    	}
    }
	return 0;
}


