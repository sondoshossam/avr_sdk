/*
 * keypad.c
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */

#include "../../mcal/DIO/Dio.h"
#include "../../utils/bit_operations.h"
#include "../../utils/custom_types.h"
#include "keypad.h"
#include "keypad_config.h"
const s8_t SCAN_PATTERN[5] = {0b00001110 ,0b00001101 , 0b00001011 , 0b00000111 , 0x0F};
const s8_t MAPPEDCHARS[16] = {'1' , '2' , '3' , 'A',\
		                      '4' , '5' , '6' , 'B',\
							  '7' , '8' , '9' , 'C',\
							  '*' , '0' , '#' , 'D'};

static s8_t scan(void);
static void output_scan_pattern(u8_t pattern);
static s8_t read_row_status();
void init_keypad()
{
	dio_channel_config(KP_R1 , input_pullup);
	dio_channel_config(KP_R2 , input_pullup);
	dio_channel_config(KP_R3 , input_pullup);
	dio_channel_config(KP_R4 , input_pullup);

	dio_channel_config(KP_C1 , output);;
	dio_channel_config(KP_C2 , output);
	dio_channel_config(KP_C3 , output);
	dio_channel_config(KP_C4 , output);
	output_scan_pattern(0x0f);//1111

}
u8_t get_key_clicked()  //blocking
{
	s8_t pressed_key  , maped_key;
     // wait untill key pressed
	do
	{
		pressed_key = scan();
	}while(pressed_key == -1);
	maped_key = MAPPEDCHARS[pressed_key];
	//wait until key released -1
	do
	{
		pressed_key = scan();
	}while(pressed_key != -1);
	return maped_key;
}
s8_t get_key_pressed() //non blocking
{
	s8_t pressed_key ;
	pressed_key = scan();
	if(pressed_key != -1)
	{
        return MAPPEDCHARS[pressed_key];
	}
	return '+';
}

static s8_t scan(void)
{
	s8_t col_index , row_index , pressed_key=-1;
	for(col_index=0 ; col_index<4 ; col_index++)
	{
		output_scan_pattern(SCAN_PATTERN[col_index]);
		row_index=read_row_status();
		if(row_index != -1)
		{
			pressed_key = (row_index*4) + col_index;
			break;
		}
	}
	return pressed_key;
}
static void output_scan_pattern(u8_t pattern)
{
	dio_channel_set(KP_C1 , READ_BIT(pattern , 0));
	dio_channel_set(KP_C2 , READ_BIT(pattern , 1));
	dio_channel_set(KP_C3 , READ_BIT(pattern , 2));
	dio_channel_set(KP_C4 , READ_BIT(pattern , 3));
}
static s8_t read_row_status()
{
	s8_t row_index = -1;
	if(dio_channel_read(KP_R1) == low)
	{
		row_index = 0;
	}
	else if(dio_channel_read(KP_R2) == low)
	{
		row_index = 1;
	}
	else if(dio_channel_read(KP_R3) == low)
	{
		row_index = 2;
	}
	else if(dio_channel_read(KP_R4) == low)
	{
		row_index = 3;
	}
	return row_index;

}
