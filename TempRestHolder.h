#ifndef TEMPRESTHOLDER_H
#define TEMPRESTHOLDER_H

#include "Base.h"

class Thermometer;
class Heater;

class TempRestHolder : public Base
{
public:
  TempRestHolder(Thermometer *thermometer, Heater *heater);
  
  void SetTemperature(float temperature);
  void SetDelta(float delta);
  
  void On();
  void Off();
  void Toggle();
  
  boolean GetState() const;
  
  /*Base*/
  virtual void Setup();
  virtual void Loop();
  
protected:
  virtual void Process();
  void HeaterToggle(boolean flag);
  
  Thermometer *thermometer_;
  Heater *heater_;
  
  double temperature_;
  float delta_;
  boolean state_;
};

#endif
