#ifndef PIDTEMPHOLDER_H
#define PIDTEMPHOLDER_H

#include "TempRestHolder.h"

namespace {
const float kDeltaPidDefault = 5.0;
const unsigned int kWindowSizeDefault = 6000;
}

class PidTempHolder : public TempRestHolder
{
public:
  PidTempHolder(Thermometer *thermometer, Heater *heater)
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
    if (auto_mode_)
    {
      float temperature = (thermometer_) ? thermometer_->Temperature() : 0.0;
      
      if ((temperature_ - temperature) < delta_pid_ * 1.2)
      {
        pid_.Compute();
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
