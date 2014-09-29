#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <OneWire.h>

//#include "Eep.h"

class Thermometer
{
public:
  Thermometer(unsigned char pin);

  void Setup();
  float Temperature();
  
private:
  OneWire ds_;
  boolean Conv_start;
  float TemperatureNow;
  byte ScaleTemp;
  unsigned char data_[9]; // Sensor Temp with crc version
};

#endif //THERMOMETER_H
