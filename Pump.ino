#include "Pump.h"

#include "Led.h"

Pump::Pump(unsigned char pin, Led *led /*= NULL*/) : Pin(pin), led_(led)
{
}

void Pump::SetLed(Led *led)
{
  led_ = led;
}

void Pump::On()
{
  Pin::On();
  
  if (led_) led_->On();
}

void Pump::Off()
{
  Pin::Off();
  
  if (led_) led_->Off();
}
