#include "Pin.h"

Pin::Pin(unsigned char pin) : pin_(pin)
{
}

void Pin::Setup()
{
  pinMode(pin_, OUTPUT);
}

void Pin::OnStateChanged()
{
  if (GetState()) {
    digitalWrite(pin_, HIGH);
  }
  else {
    digitalWrite(pin_, LOW);
  }
}

PinLed::PinLed(unsigned char pin, Led *led /*= NULL*/)
:Pin(pin)
,led_(led)
{
}

void PinLed::SetLed(Led *led)
{
  led_ = led;
  
  if (led_) led_->SetState(GetState());
}

void PinLed::OnStateChanged()
{
  Pin::OnStateChanged();
  
  if (led_) led_->SetState(GetState());
}
