#include "TempRestHolder.h"

#include "Thermometer.h"
#include "Eep.h"

namespace {
 const float kDefaultDelta = 0.5;
 const int kEepAddr = 0; //float
}

TempRestHolder::TempRestHolder(Thermometer *thermometer, Pin *heater)
:thermometer_(thermometer)
,heater_(heater)
,temperature_(67.0)
,delta_(kDefaultDelta)
,state_(false)
{
  EepRead(kEepAddr, temperature_);
}

float TempRestHolder::GetTemperature() const
{
  return temperature_;
}

void TempRestHolder::SetTemperature(float temperature)
{
  temperature_ = temperature;
  
  EepWrite(kEepAddr, temperature_);
  Process();
}

void TempRestHolder::SetDelta(float delta)
{
  delta_ = delta;
  
  Process();
}
  
void TempRestHolder::On()
{
  Serial.println("TempRestHolder::On");
  state_ = true;
  
  Process();
}

void TempRestHolder::Off()
{
  Serial.println("TempRestHolder::Off");
  state_ = false;
  
  HeaterToggle(false);
}

void TempRestHolder::Toggle()
{
  state_ = !state_;
  
  if (state_) {
    On();
  }
  else {
    Off();
  }
}
  
boolean TempRestHolder::GetState() const
{
  return state_;
}

void TempRestHolder::Setup()
{
  if (thermometer_) thermometer_->Setup();
  if (heater_) heater_->Setup();
}

void TempRestHolder::Loop()
{
  Process();
}

void TempRestHolder::Process()
{
  if (!state_) return;
  
  float temperature = (thermometer_) ? thermometer_->Temperature() : 0.0;
  
  HeaterToggle(temperature < (temperature_ - delta_));
}

void TempRestHolder::HeaterToggle(boolean flag)
{
  if (flag)
  {
    if (heater_ && !heater_->GetState()) heater_->On();
  }
  else
  {
    if (heater_ && heater_->GetState()) heater_->Off();
  }
}
