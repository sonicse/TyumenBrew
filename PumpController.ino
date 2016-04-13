#include "PumpController.h"

#include "Heater.h"

PumpController::PumpController(Pump &pump, Heater *heater)
:pump_(pump)
,heater_(heater)
,state_(false)
{}

void PumpController::On()
{
  Serial.println("PumpController::On");
  state_ = true;
  
  Process();
}

void PumpController::Off()
{
  Serial.println("PumpController::Off");
  state_ = false;
  
  Process();
}

void PumpController::Toggle()
{
  state_ = !state_;
  
  if (state_) {
    On();
  }
  else {
    Off();
  }
}
  
void PumpController::Setup()
{
  pump_.Setup();
  
  if (heater_) heater_->Setup();
}

void PumpController::Loop()
{
  Process();
}

