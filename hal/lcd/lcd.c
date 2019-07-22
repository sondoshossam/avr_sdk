/*
 * lcd_new.c
 *
 *  Created on: Jul 13, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../mcal/DIO/Dio.h"
#include "../../utils/bit_operations.h"
#include "../../utils/custom_types.h"
#include "lcd.h"
#include "lcd_config.h"

static void send_instruction_4bit(u8_t instruction);
static void send_instruction_8bit(u8_t instruction);
static void send_data_8bit(u8_t data);
static void set_xy_cursor_pos(u8_t row , u8_t col);
void init_lcd(void)
{
	dio_channel_config(LCD_RS,output);
	dio_channel_config(LCD_EN,output);
	dio_channel_config(LCD_B4,output);
	dio_channel_config(LCD_B5,output);
	dio_channel_config(LCD_B6,output);
	dio_channel_config(LCD_B7,output);
	dio_channel_set(LCD_EN , low);
	_delay_ms(20); // wait more than 15ms
	send_instruction_4bit(0x03);
	_delay_ms(5); // wait more than 4.1
	send_instruction_4bit(0x03);
	_delay_us(200); //wait more than 100us
	send_instruction_4bit(0x03);
	send_instruction_4bit(0x02);
	send_instruction_8bit(0x28);
	_delay_us(50);
	send_instruction_8bit(LCD_CMD_DISPLAY_OFF);
	send_instruction_8bit(LCD_CMD_CLEAR);
	send_instruction_8bit(0x06);
	_delay_ms(10);
	send_instruction_8bit(LCD_CMD_DISPLAY_ON);
}
static void send_instruction_4bit(u8_t instruction)
{
	dio_channel_set(LCD_RS , low);
	dio_channel_set(LCD_B4 , READ_BIT(instruction ,0));
	dio_channel_set(LCD_B5 , READ_BIT(instruction ,1));
	dio_channel_set(LCD_B6 , READ_BIT(instruction ,2));
	dio_channel_set(LCD_B7 , READ_BIT(instruction ,3));
	dio_channel_set(LCD_EN,high);
	_delay_us(0.5); // enable pulse must be >450ns
	dio_channel_set(LCD_EN,low);
	_delay_us(100);  // > 37us to settle
}
static void send_instruction_8bit(u8_t instruction)
{
	dio_channel_set(LCD_RS , low);
	dio_channel_set(LCD_B4 , READ_BIT(instruction ,4));
	dio_channel_set(LCD_B5 , READ_BIT(instruction ,5));
	dio_channel_set(LCD_B6 , READ_BIT(instruction ,6));
	dio_channel_set(LCD_B7 , READ_BIT(instruction ,7));
	dio_channel_set(LCD_EN,high);
	_delay_us(0.5); // enable pulse must be >450ns
	dio_channel_set(LCD_EN,low);
	_delay_us(100);  // > 37us to settle
	dio_channel_set(LCD_B4 , READ_BIT(instruction ,0));
	dio_channel_set(LCD_B5 , READ_BIT(instruction ,1));
	dio_channel_set(LCD_B6 , READ_BIT(instruction ,2));
	dio_channel_set(LCD_B7 , READ_BIT(instruction ,3));
	dio_channel_set(LCD_EN,high);
	_delay_us(0.5); // enable pulse must be >450ns
	dio_channel_set(LCD_EN,low);
	_delay_us(100);  // > 37us to settle
}
static void send_data_8bit(u8_t data)
{
	dio_channel_set(LCD_RS , high);
	dio_channel_set(LCD_B4 , READ_BIT(data ,4));
	dio_channel_set(LCD_B5 , READ_BIT(data ,5));
	dio_channel_set(LCD_B6 , READ_BIT(data ,6));
	dio_channel_set(LCD_B7 , READ_BIT(data ,7));
	dio_channel_set(LCD_EN,high);
	_delay_us(0.5); // enable pulse must be >450ns
	dio_channel_set(LCD_EN,low);
	_delay_us(100);  // > 37us to settle
	dio_channel_set(LCD_B4 , READ_BIT(data ,0));
	dio_channel_set(LCD_B5 , READ_BIT(data ,1));
	dio_channel_set(LCD_B6 , READ_BIT(data ,2));
	dio_channel_set(LCD_B7 , READ_BIT(data ,3));
	dio_channel_set(LCD_EN,high);
	_delay_us(0.5); // enable pulse must be >450ns
	dio_channel_set(LCD_EN,low);
	_delay_us(100);  // > 37us to settle
}
static void set_xy_cursor_pos(u8_t row , u8_t col)
{
	u8_t ddram_add;
	ddram_add = 0x40 * (row - 1) + (col -1);
	SET_BIT(ddram_add,7);
	send_instruction_8bit(ddram_add);
	_delay_us(100);
}
void lcd_write_text(char *str , u8_t row ,  u8_t col)
{
	u8_t i =0;
	set_xy_cursor_pos(row , col);
	while(str[i] !=0)
	{
		send_data_8bit(str[i]);
		i++;
	}
}
void lcd_write_char(u8_t chr , u8_t row ,  u8_t col)
{
	set_xy_cursor_pos(row , col);
	send_data_8bit(chr);
}
void lcd_write_char_cp(u8_t chr)
{
	send_data_8bit(chr);
}
void lcd_write_text_cp(char* str)
{
	u8_t i =0;
	while(str[i] !=0)
	{
		send_data_8bit(str[i]);
		i++;
	}
}
void lcd_clear(void)
{
	send_instruction_8bit(LCD_CMD_CLEAR);
	_delay_ms(2);
}

