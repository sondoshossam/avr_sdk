/*
 * seven_seg_config.h
 *
 *  Created on: Jul 9, 2019
 *      Author: mohamed
 */
#include "../../mcal/DIO/Dio.h"
#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEG_CONFIG_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEG_CONFIG_H_
#define COMMON_ANODE 0
#define COMMON_CATHOD 1

#define CURRENT_SEGMENT COMMON_CATHOD
#define SEG_PINA Dio_channel_d0
#define SEG_PINB Dio_channel_d1
#define SEG_PINC Dio_channel_d2
#define SEG_PIND Dio_channel_d3
#define SEG_PINE Dio_channel_d4
#define SEG_PINF Dio_channel_d5
#define SEG_PING Dio_channel_d6
#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEG_CONFIG_H_ */
