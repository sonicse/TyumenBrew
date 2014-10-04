#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <OneWire.h>

#include "Base.h"

class Thermometer : public Base
{
public:
  Thermometer(unsigned char pin);

  virtual void Setup();
  float Temperature();
  
private:
  OneWire ds_;
  boolean Conv_start;
  float TemperatureNow;
  byte ScaleTemp;
  unsigned char data_[9]; // Sensor Temp with crc version
};

#endif //THERMOMETER_H
