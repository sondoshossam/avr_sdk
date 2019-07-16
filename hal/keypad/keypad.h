/*
 * keypad.h
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

void init_keypad();
u8_t get_key_clicked();  //blocking
s8_t get_key_pressed(); //non blocking
#endif /* HAL_KEYPAD_KEYPAD_H_ */
