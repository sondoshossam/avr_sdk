/*
 * eeprom_app.c
 *
 *  Created on: Jul 13, 2019
 *      Author: mohamed
 */
#ifdef EEPROM_APP
#include "../mcal/EEPROM/eeprom.h"
int eeprom_app(void)
{
	EEPROM_write(1000  , 0X0e);
	while(1);
}
#endif

