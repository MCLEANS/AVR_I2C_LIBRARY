#ifndef _I2C_H
#define  _I2C_H

#define  F_CPU 16000000L
#define BDIV (F_CPU / 100000 - 16)/ 2 + 1

#include <avr/io.h>
#include <util/delay.h>
#include <util/twi.h>

class TWI{
	
	private:
	private:
		
	public:
	public:
		TWI();
		void init();
		void start(uint8_t addres);
		void stop();
		void write(uint8_t data);
		uint8_t readACK();
		uint8_t readNACK();
		uint8_t BCD_to_decimal(uint8_t val);
		uint8_t decimal_to_BCD(uint8_t val);
	
	
	};


#endif //_I2C_H