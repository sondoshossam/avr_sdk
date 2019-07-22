/*
 * keypad_app.c
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#ifdef KEYPAD_APP
#define F_CPU 16000000UL
#include "../hal/lcd/lcd.h"
#include <util/delay.h>
#include "../hal/keypad/keypad.h"
int keypad_app(void)
{
	init_keypad();
	init_lcd();
	lcd_write_char(' ',
					1,
					1
					);
	while(1)
	{
		lcd_write_char_cp(get_key_pressed());
		_delay_ms(1000);
	}
	return 0;
}
#endif
