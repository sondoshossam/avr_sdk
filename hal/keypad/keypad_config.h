/*
 * keypad_config.h
 *
 *  Created on: Jul 16, 2019
 *      Author: mohamed
 */
#include "../../mcal/DIO/Dio.h"
#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_
/*keypad rows*/
#define KP_R1 Dio_channel_d0
#define KP_R2 Dio_channel_d1
#define KP_R3 Dio_channel_d2
#define KP_R4 Dio_channel_d3
/*keypad cols*/
#define KP_C1 Dio_channel_d4
#define KP_C2 Dio_channel_d5
#define KP_C3 Dio_channel_d6
#define KP_C4 Dio_channel_d7

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
