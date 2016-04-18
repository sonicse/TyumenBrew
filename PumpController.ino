#include "PumpController.h"

PumpController::PumpController(Pin &pump, Pin &heater_big, Pin &heater_small)
:pump_(pump)
,heater_big_(heater_big)
,heater_small_(heater_small)
,time_start_(0)
{
}
  
void PumpController::Setup()
{
  pump_.Setup();
  heater_big_.Setup();
  heater_small_.Setup();
}

void PumpController::Loop()
{
  //Process();
}

void PumpController::Prepare()
{
  for(byte i = 1; i < 6; ++i)
  {
    pump_.On();
    delay(750 + i*250);
    pump_.Off();
    delay(350);
  }
}

void PumpController::OnStateChanged()
{
  time_start_ = millis();
  
  boolean state = GetState();
  
  pump_.SetState(state);
}

unsigned long PumpController::GetTime() const
{
  return millis() - time_start_;
}
