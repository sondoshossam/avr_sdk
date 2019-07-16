/*
 * Dio.c
 *
 *  Created on: Jul 2, 2019
 *      Author: mohamed
 */
#include "dio_atmega328p_registers.h"
#include "Dio.h"
#include "../../utils/bit_operations.h"
#include "../../utils/custom_types.h"
#define PORT_WIDE 8
void dio_channel_config(Dio_channel_t channel , Dio_ch_dir_t dir)
{
	/*to get the bit position in the register*/
	u8_t bit_number = channel%PORT_WIDE;
     Dio_port_t port_number = channel/PORT_WIDE;
     switch (port_number) {
		case Dio_portb:
			if(dir == output )
			{
                 SET_BIT(DDRB , bit_number);
			}
			else if (dir == input )
			{
				CLR_BIT(DDRB , bit_number);
			}
			else if (dir == input_pullup )
			{
				CLR_BIT(DDRB , bit_number);
				SET_BIT(PORTB , bit_number);
			}
			break;
		case Dio_portc:
			if(dir == output )
			{
				 SET_BIT(DDRC , bit_number);
			}
			else if (dir == input )
			{
				CLR_BIT(DDRC , bit_number);
			}
			else if (dir == input_pullup )
			{
				CLR_BIT(DDRC , bit_number);
				SET_BIT(PORTC , bit_number);
			}
			break;
		case Dio_portd:
			if(dir == output )
			{
				 SET_BIT(DDRD , bit_number);
			}
			else if (dir == input )
			{
				CLR_BIT(DDRD , bit_number);
			}
			else if (dir == input_pullup )
			{
				CLR_BIT(DDRD , bit_number);
				SET_BIT(PORTD , bit_number);
			}
			break;
		default:
			break;
	}
}
void dio_channel_set(Dio_channel_t channel , Dio_ch_state_t state)
{
	u8_t bit_number = channel%PORT_WIDE;
	Dio_port_t port_number = channel/PORT_WIDE;
	switch (port_number) {
		case Dio_portb:
			if(state == high )
			{
				 SET_BIT(PORTB , bit_number);
			}
			else if (state == low )
			{
				CLR_BIT(PORTB , bit_number);
			}
			else if (state == toggle )
			{
				TOGGLE_BIT(PORTB , bit_number);
			}
			break;
		case Dio_portc:
			if(state == high )
			{
				 SET_BIT(PORTC , bit_number);
			}
			else if (state == low )
			{
				CLR_BIT(PORTC , bit_number);
			}
			else if (state == toggle )
			{
				TOGGLE_BIT(PORTC , bit_number);
			}
			break;
		case Dio_portd:
			if(state == high )
			{
				 SET_BIT(PORTD , bit_number);
			}
			else if (state == low )
			{
				CLR_BIT(PORTD , bit_number);
			}
			else if (state == toggle )
			{
				TOGGLE_BIT(PORTD , bit_number);
			}
			break;
		default:
			break;
	}
}
Dio_ch_state_t dio_channel_read(Dio_channel_t channel)
{
	u8_t bit_number = channel%PORT_WIDE;
     Dio_port_t port_number = channel/PORT_WIDE;
     Dio_ch_state_t channel_state = low; // can carry high or low or toggle
     switch (port_number) {
		case Dio_portb:
			channel_state = READ_BIT(PINB , bit_number);
			break;
		case Dio_portc:
			channel_state = READ_BIT(PINC , bit_number);
			break;
		case Dio_portd:
			channel_state = READ_BIT(PIND , bit_number);
			break;
		default:
			break;
	}
    return channel_state;
}

void dio_port_config(Dio_port_t port , u8_t dir)
{
	switch (port) {
		case Dio_portb:
			DDRB = dir;
			break;
		case Dio_portc:
			DDRC = dir;
			break;
		case Dio_portd:
			DDRD = dir;
			break;
		default:
			break;
	}
}
void dio_port_set(Dio_port_t port , u8_t state)
{
	switch (port) {
		case Dio_portb:
			PORTB = state;
			break;
		case Dio_portc:
			PORTC = state;
			break;
		case Dio_portd:
			PORTD = state;
			break;
		default:
			break;
	}
}
