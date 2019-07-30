/*
 * iic.c
 *
 *  Created on: Jul 29, 2019
 *      Author: mohamed
 */
#include "iic_atmega328p_reg.h"
#include "iic.h"
#include "../../utils/bit_operations.h"
typedef enum
{
	Start_Condition_Transmitted = 0x08,
	Repeat_Start_Condition_Transmitted = 0x10,
	Arbitration_Lost = 0x38,
	MasterTx_SLA_W_ACK_REC = 0x18,
	MasterTx_SLA_W_NACK_REC = 0x20,
	MasterTx_DATA_TRANS_ACK_REC = 0x28,
	MasterTx_DATA_TRANS_NACK_REC = 0x30,

	MasterRx_SLA_R_ACK_REC = 0x40,
	MasterRx_SLA_R_NACK_REC = 0x48,
	MasterRx_DATA_REC_ACK_TRANS = 0x50,
	MasterRx_DATA_REC_NACK_TRANS = 0x58
}iic_status_t;
#define CLK_PRE_MASk 0xFC
#define PRESCALLER 1.0
void init_i2c(u32_t bit_rate)
{
	u8_t TWBR_val;
	// set clk prescaller to 16
	TWSR = (TWSR & CLK_PRE_MASk) | 0x00; // prescaller = 1
	TWBR_val = ((F_CPU / bit_rate) - 16 ) / (2* PRESCALLER);
	TWBR = 72;
	SET_BIT(TWCR , TWEN);

}
bool_t i2c_start(u8_t address)
{
	iic_status_t status;
	// transmit START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while(READ_BIT(TWCR , TWINT) == 0);
	// check if the start condition was successfully transmitted
	status = TWSR & 0xF8;
	if(status != Start_Condition_Transmitted)
	{
		return false; // can't transmit now
	}

	// load slave address into data register
	TWDR = address;
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while(READ_BIT(TWCR , TWINT) == 0);
	// check if the device has acknowledged the READ / WRITE mode
	status = TWSR & 0xF8;
	if(status != MasterTx_SLA_W_ACK_REC &&  status != MasterRx_SLA_R_ACK_REC)
	{
		return false; // slave not existed
	}
	return true;
}
bool_t i2c_write(u8_t data)
{
	iic_status_t status;
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	status = TWSR & 0xF8;
   return status == MasterTx_SLA_W_ACK_REC;
}
u8_t i2c_read_ack(void)
{
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	return TWDR;
}
u8_t i2c_read_nack(void)
{
	// start receiving without acknowledging reception
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	return TWDR;
}
bool_t i2c_transmit(u8_t address, u8_t* data, u8_t length)
{
	u8_t i = 0;
	bool_t error_flag = false; //no  error
	if (i2c_start(address<<1) == true)
	{
		for ( i = 0; i < length; i++)
		{
			if (i2c_write(data[i]) != true)
			{
			   error_flag = true;
			   break;
			}
		}
		i2c_stop();
	}
	else
	{
		error_flag = true;
	}


	return error_flag == false; // no error
}
bool_t i2c_receive(u8_t address, u8_t* data, u8_t length)
{
	u8_t i = 0;
	bool_t error_flag = false; //no  error
	if (i2c_start((address<<1)|0x01) == true)
	{
		for ( i = 0; i < (length-1); i++)
		{
			data[i] = i2c_read_ack();
		}
		data[i] = i2c_read_nack();
		i2c_stop();
	}
	else
	{
		error_flag = true;
	}

	return error_flag == false; // no error
}

void i2c_stop(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

