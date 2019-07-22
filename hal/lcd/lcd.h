/*
 * lcd.h
 *
 *  Created on: Jul 11, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#define LCD_CMD_CLEAR		(u8_t)0x01
#define LCD_CMD_DISPLAY_ON	(u8_t)0x0C
#define LCD_CMD_DISPLAY_OFF (u8_t)0x08

void init_lcd(void);
void lcd_write_text(char *str , u8_t row ,  u8_t col);
void lcd_write_char(u8_t chr , u8_t row ,  u8_t col);
void lcd_write_char_cp(u8_t chr);
void lcd_write_text_cp(char *str);
void lcd_clear(void);
#endif /* HAL_LCD_LCD_H_ */
