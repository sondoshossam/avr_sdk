/*
 * usart.h
 *
 *  Created on: Jul 21, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_
void init_usart(u32_t baud_rate);
void usart_write_char(u8_t chr);
void usart_write_text(u8_t* txt);
u8_t usart_read_char(void);
bool_t usart_data_available(void);
#endif /* MCAL_USART_USART_H_ */
