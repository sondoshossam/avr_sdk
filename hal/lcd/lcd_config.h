/*
 * lcd_config.h
 *
 *  Created on: Jul 11, 2019
 *      Author: mohamed
 */
#include "../../mcal/DIO/Dio.h"
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#define LCD_MODE MODE_4
#define LCD_RS Dio_channel_b0
#define LCD_EN Dio_channel_b1
#if  LCD_MODE == MODE_8
	#define LCD_B0 Dio_channel_d0
	#define LCD_B1 Dio_channel_d1
	#define LCD_B2 Dio_channel_d2
	#define LCD_B3 Dio_channel_d3
#endif
#define LCD_B4 Dio_channel_b2
#define LCD_B5 Dio_channel_b3
#define LCD_B6 Dio_channel_b4
#define LCD_B7 Dio_channel_b5

#endif /* HAL_LCD_LCD_CONFIG_H_ */
