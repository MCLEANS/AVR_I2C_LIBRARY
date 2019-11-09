# AVR_I2C_LIBRARY
A library for i2c communication using AVR micro-controller

## TWI-AVR  COMMUNICATION
This is a library to help in communication between an AVR microcontroller and peripherals that communicate using the i2c protocol

            The I²C (Inter-Integrated Circuit) protocol, referred to as I-squared-C, I-two-C, or IIC) is two wire serial communication protocol for connecting low speed peripherals to a micrcontroller or computer motherboard.
            The I²C simply require only two wires for communication. One is called the Serial Data (SDA) and the other is Serial Clock (SCL) as shown.
            There are various modes and configurations in which it can be used. Let us start simply with a single master and a single slave.
            The Master generates the clock for serial communication(SCL). A stream of data bits(B1 to BN) is transferred between the start and the stop bits.
            
            
 ![circuit diagram](http://www.ermicro.com/blog/wp-content/uploads/2009/02/i2c_00.jpg)
 
## INITIALIZATION
First we initialize the system by setting a prescaller and the i2c frequency.
            
     void TWI::init();
                  
## START
To send the start bit we enable the TWI and then send a start bit, here in the same function we send the (slave_address + R/W)  to show which device we wish to start communication with and whether we  wish to read from or write to them.

    void TWI::start(uint8_t addres);
          
##  READACK
This is used to read data from the device into the AVR TWI data register and send an acknowledgement showing we wish to get more data
    
    void uint8_t TWI::readACK();
    
## READNACK
Also used to read data from device into the AVR TWI data register and send a NACK to mean we wish to stop the reading process

    void uint8_t TWI::readNACK();
    
## WRITE
To write to another device this method enables the transfer of data from the data register into the specified register int the peripheral device
  
    void TWI::write(uint8_t data);
    
## DECIMAL TO BCD
Data in this protocol is stored in the data register in BCD format but humans are used to the decimal system, this method enables the conversion of the decimal data we provide into BCD before storing into the data register
  
    uint8_t TWI::decimal_to_BCD(uint8_t val);
    
## BCD TO DECIMAL
  Data in the TWI data register is stored in BCD, this method enable its conversion to decimal before it is used by an application
    
    uint8_t TWI::BCD_to_decimal(uint8_t val);
    
 ## STOP 
 This stops the TWI communication.
    
    void TWI::stop();
      
           
