/*
 * eeprom.c
 *
 *  Created on: Jul 13, 2019
 *      Author: mohamed
 */
#include "eeprom_reg.h"
#include "../../utils/bit_operations.h"
#include "../../utils/custom_types.h"
void EEPROM_write(u16_t uiAddress, u8_t ucData)
{
   /* Wait for completion of previous write */
   while(READ_BIT(EECR , EEPE));
	/* Set up address and Data Registers */
	EEARH = (u8_t)(uiAddress>>8);
	EEARL = (u8_t)uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMPE */
	SET_BIT(EECR , EEMPE);
	/* Start eeprom write by setting EEPE */
	SET_BIT(EECR , EEPE);
}
u8_t EEPROM_read(u16_t uiAddress)
{
	/* Wait for completion of previous write */
	while(READ_BIT(EECR , EEPE));
	/* Set up address register */
	EEARH = (u8_t)(uiAddress>>8);
	EEARL = (u8_t)uiAddress;
	/* Start eeprom read by writing EERE */
	SET_BIT(EECR , EERE);
	/* Return data from Data Register */
	return EEDR;
}
