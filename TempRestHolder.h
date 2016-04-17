#ifndef TEMPRESTHOLDER_H
#define TEMPRESTHOLDER_H

#include "Base.h"

namespace {
  const float kDeltaPidDefault = 5.0;
  const unsigned int kWindowSizeDefault = 6000;
}

class Thermometer;
class Heater;

class TempRestHolder : public Base
{
public:
  TempRestHolder(Thermometer *thermometer, Pin *heater);

  float GetTemperature() const;  
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
  Pin *heater_;
  
  double temperature_;
  float delta_;
  boolean state_;
};

class PidTempHolder : public TempRestHolder
{
public:
  PidTempHolder(Thermometer *thermometer, Pin *heater)
  :TempRestHolder(thermometer, heater)
  ,auto_mode_(true)
  ,delta_pid_(kDeltaPidDefault)
  ,window_size_(kWindowSizeDefault)
  ,current_temperature_(0.0)
  ,output_(0.0)
  ,pid_(&current_temperature_, &output_, &temperature_, 100.0, 20.0, 5.0, DIRECT)
  {}
  
  void SetAuto(boolean mode)
  {
    auto_mode_ = mode;
  }
  
private:
  void Process()
  {
    if (!state_) return;
    
    if (auto_mode_)
    {
      float temperature = (thermometer_) ? thermometer_->Temperature() : 0.0;
      
      if ((temperature_ - temperature) < delta_pid_ * 1.2)
      {
        pid_.Compute();
        char tmp[128];
        sprintf(tmp, "pid.Compute - %0.2f", output_);
        Serial.println(tmp);
      }
      else if ((temperature_ - temperature) > delta_pid_)
      {
        output_ = 100;
      }
    }

    unsigned long now = millis();
    
    if (now - start_time_ > window_size_)
    {
      start_time_ += window_size_; //time to shift the Relay Window
    }
    
    HeaterToggle((output_ * (window_size_ / 100)) > now - start_time_);
  }
  
  boolean auto_mode_;
  float delta_pid_;
  unsigned int window_size_;
  double current_temperature_;
  double output_;
  PID pid_;
  unsigned long start_time_;
};

#endif
