#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <OneWire.h>

#include "Base.h"

class Thermometer : public Base
{
public:
  Thermometer(unsigned char pin);

  virtual void Setup();
  virtual void Loop();
  
  float Temperature();
  
private:
  OneWire ds_;
  boolean conv_start_;
  float temperature_;
  byte scale_temp_;
  unsigned char data_[9]; // Sensor Temp with crc version
};

#endif //THERMOMETER_H
