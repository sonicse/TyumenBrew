#include "Thermometer.h"

#include <EEPROM.h>

Thermometer::Thermometer(unsigned char pin) :ds_(pin), Conv_start(false), TemperatureNow(0.0), ScaleTemp(0)
{
    ScaleTemp = EEPROM.read(15);
}

void Thermometer::Setup()
{
}

void Thermometer::Loop()
{
//  Temperature();
}

// reads the DS18B20 temerature probe
// return always gTemperatureNow
float Thermometer::Temperature()
{ 
  ds_.reset();
  ds_.skip();

  // start conversion and return
  if (!Conv_start)
  {
    ds_.write(0x44, 0);
    Conv_start = true;
    return TemperatureNow;
  }
  
  if (Conv_start)
  {// check for conversion if it isn't complete return if it is then convert to decimal
    unsigned char busy = ds_.read_bit();
  
    if (busy == 0) {
      return TemperatureNow;
    }

    ds_.reset();
    ds_.skip();
    ds_.write(0xBE);
    
    for ( unsigned char i = 0; i < 9; ++i) {           // with crc we need 9 bytes
      data_[i] = ds_.read();
    }
    
    //* add this routine for crc version 
    if ( OneWire::crc8(data_, 8) != data_[8])
    {  //if checksum fails start a new conversion right away
      ds_.reset();
      ds_.skip();
      ds_.write(0x44,0);
      Conv_start = true;
      return TemperatureNow;
      //*Fine Routine crc
    }

    unsigned int raw = (data_[1] << 8) + data_[0];
    
    if (ScaleTemp == 0) {
      TemperatureNow = (raw & 0xFFFC) * 0.0625;
    }
    else {
      TemperatureNow = ((raw & 0xFFFC) * 0.0625) * 1.8 + 32.0;
    }

    unsigned char correction = word(EEPROM.read(9), EEPROM.read(10));
    TemperatureNow = TemperatureNow + (correction/10.0);

    Conv_start = false;
    return TemperatureNow;
  } 
}
