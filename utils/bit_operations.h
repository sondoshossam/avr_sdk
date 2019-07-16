/*
 * bit_operations.h
 *
 *  Created on: Jul 2, 2019
 *      Author: mohamed
 */

#ifndef UTILS_BIT_OPERATIONS_H_
#define UTILS_BIT_OPERATIONS_H_
#define SET_BIT(REG,BIT_NO) (REG |=(1<<BIT_NO) )
#define TOGGLE_BIT(REG,BIT_NO) (REG ^=(1<<BIT_NO))
#define CLR_BIT(REG,BIT_NO) (REG &=(~(1<<BIT_NO)))
#define READ_BIT(REG,BIT_NO) ((REG &(1<<BIT_NO))>>BIT_NO)
#endif /* UTILS_BIT_OPERATIONS_H_ */
