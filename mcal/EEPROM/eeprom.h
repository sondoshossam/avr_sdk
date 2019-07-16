/*
 * eeprom.h
 *
 *  Created on: Jul 13, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_EEPROM_EEPROM_H_
#define MCAL_EEPROM_EEPROM_H_
void EEPROM_write(u16_t uiAddress, u8_t ucData);
u8_t EEPROM_read(u16_t uiAddress);
#endif /* MCAL_EEPROM_EEPROM_H_ */
