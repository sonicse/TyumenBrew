#ifndef PUMPCONTROLLER_H
#define PUMPCONTROLLER_H

#include "Pump.h"

class Heater;

class PumpController : public Base
{
public:
  PumpController(Pump &pump, Heater *heater = NULL);
  
  void On();
  void Off();
  void Toggle();

  /*Base*/
  virtual void Setup();
  virtual void Loop();
  
private:
  void Process(){};
  
  Pump &pump_;
  Heater *heater_;
  boolean state_;
};

#endif
