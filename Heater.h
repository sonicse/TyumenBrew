#ifndef HEATER_H
#define HEATER_H

#include "Pin.h"

class Led;

class Heater : public Pin
{
public:
  Heater(unsigned char pin, Led *led = NULL);
  
  void SetLed(Led *led);
  
  void On();
  void Off();
  
private:
  Led *led_;
};

#endif
