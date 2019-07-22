/*
 * h_bridge.h
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */

#ifndef HAL_H_BRIDGE_H_BRIDGE_H_
#define HAL_H_BRIDGE_H_BRIDGE_H_
void init_motors(void);
void motors_forward(void);
void motors_backward(void);
void motors_rotate_cw(void);
void motors_rotate_acw(void);
void motors_hold(void);
#endif /* HAL_H_BRIDGE_H_BRIDGE_H_ */
