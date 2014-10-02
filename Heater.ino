#include "Heater.h"

#include "Led.h"

Heater::Heater(unsigned char pin, Led *led /*= NULL*/) : Pin(pin), led_(led)
{
}

void Heater::SetLed(Led *led)
{
  led_ = led;
}

void Heater::On()
{
  Pin::On();
  
  if (led_) led_->On();
}

void Heater::Off()
{
  Pin::Off();
  
  if (led_) led_->Off();
}
