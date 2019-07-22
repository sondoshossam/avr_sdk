/*
 * robot_movement.c
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../hal/h_bridge/h_bridge.h"
#include "../utils/custom_types.h"
#include "../mcal/DIO/Dio.h"
#include "../mcal/usart/usart.h"
void robot_app(void)
{
	u8_t received_char;
	dio_channel_config(Dio_channel_d3 , input_pullup);
	dio_channel_config(Dio_channel_d1 , output); // tx output
	dio_channel_config(Dio_channel_d0 , input); // rx output
	init_usart(9600);
	_delay_ms(5000);
	init_motors();
	while(1)
	{
		//if(dio_channel_read(Dio_channel_d3) == high)
		if(usart_data_available())
		{
			received_char = usart_read_char();
			switch (received_char) {
				case 'F':
					motors_forward();
					break;
				case 'B':
					motors_backward();
					break;
				case 'L':
					motors_rotate_acw();
					break;
				case 'R':
					motors_rotate_cw();
					break;
				case 'S':
					motors_hold();
					break;
				default:
					break;
			}
		}
	}
}
