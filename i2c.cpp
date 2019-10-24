#include "i2c.h"

TWI::TWI(){
	
}

void TWI::init(){
	TWSR = 0; //Set a prescaler of 1
	TWBR = BDIV ; //set a i2c frequency of 100KHz
}

void TWI::start(uint8_t addres){
	
	TWCR = (1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
	
	while(!(TWCR & (1 << TWINT)));
	
	if((TWSR & 0xF8) != TW_START); //ERROR CONDITION
	
	TWDR = addres ; 
	TWCR = (1<<TWINT)|(1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));
	if((TWSR & 0xF8) != TW_MT_SLA_ACK); //ERROR CONDITION
}

void TWI::stop(){
	TWCR = (1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
}

void TWI::write(uint8_t data){
	TWDR = data;
	
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	
	if((TWSR & 0xF8) != TW_MT_DATA_ACK) ; //ERROR
}

uint8_t TWI::readACK(){
		TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
		while(!(TWCR & (1<<TWINT)));
		uint8_t reeived_data = TWDR;
		return reeived_data;
}

uint8_t TWI::readNACK(){
		TWCR = (1<<TWEN)|(1<<TWINT);
		while(!(TWCR & (1<<TWINT)));
		uint8_t reeived_data = TWDR;
		return reeived_data;
}

uint8_t TWI::BCD_to_decimal(uint8_t val){
	return((val /16 * 10) + (val %16));
}

uint8_t TWI::decimal_to_BCD(uint8_t val){
	return((val /10 * 16) + (val %10));
}