/*
 * h_bridge.c
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#include "../../mcal/DIO/Dio.h"
#include "h_bridge.h"
#include "h_bridge_config.h"
void init_motors(void)
{
	dio_channel_config(IN1_PIN , output);
	dio_channel_config(IN2_PIN , output);
	dio_channel_config(IN3_PIN , output);
	dio_channel_config(IN4_PIN , output);
	dio_channel_set(IN1_PIN , low);
	dio_channel_set(IN2_PIN , low);
	dio_channel_set(IN3_PIN , low);
	dio_channel_set(IN4_PIN , low);
}
void motors_forward(void)
{
	//h bridge 1 motor 1 forward
	dio_channel_set(IN1_PIN , low);
	dio_channel_set(IN2_PIN , high);
	//h bridge 2 motor 2 forward
	dio_channel_set(IN3_PIN , low);
	dio_channel_set(IN4_PIN , high);
}
void motors_backward(void)
{
	//h bridge 1 motor 1 backward
	dio_channel_set(IN1_PIN , high);
	dio_channel_set(IN2_PIN , low);
	//h bridge 2 motor 2 backward
	dio_channel_set(IN3_PIN , high);
	dio_channel_set(IN4_PIN , low);
}
void motors_rotate_cw(void)
{
	//h bridge 1 motor 1 backward
	dio_channel_set(IN1_PIN , high);
	dio_channel_set(IN2_PIN , low);
	//h bridge 2 motor 2 forward
	dio_channel_set(IN3_PIN , low);
	dio_channel_set(IN4_PIN , high);
}
void motors_rotate_acw(void)
{
	//h bridge 1 motor 1 forward
	dio_channel_set(IN1_PIN , low);
	dio_channel_set(IN2_PIN , high);
	//h bridge 2 motor 2 backward
	dio_channel_set(IN3_PIN , high);
	dio_channel_set(IN4_PIN , low);
}
void motors_hold(void)
{
	dio_channel_set(IN1_PIN , low);
	dio_channel_set(IN2_PIN , low);
	dio_channel_set(IN3_PIN , low);
	dio_channel_set(IN4_PIN , low);
}
