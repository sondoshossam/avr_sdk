/*
 * eeprom_reg.h
 *
 *  Created on: Jul 13, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_EEPROM_EEPROM_REG_H_
#define MCAL_EEPROM_EEPROM_REG_H_
#define EEPM1 5
#define EEPM0 4
#define EERIE 3
#define EEMPE 2
#define EEPE  1
#define EERE  0
#define EEDR  (*(volatile u8_t*) 0x40) //eeprom data reg
#define EECR  (*(volatile u8_t*) 0x3F) //control
#define EEARH (*(volatile u8_t*) 0x42) // address high
#define EEARL (*(volatile u8_t*) 0x41) // address LOW
#endif /* MCAL_EEPROM_EEPROM_REG_H_ */
