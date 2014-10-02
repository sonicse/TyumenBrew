#include "Pin.h"

Pin::Pin(unsigned char pin) : pin_(pin), state_(false)
{
}

void Pin::Setup()
{
  pinMode(pin_, OUTPUT);
}

void Pin::On()
{
  digitalWrite(pin_, HIGH);
  
  state_ = true;
}

void Pin::Off()
{
  digitalWrite(pin_, LOW);
  
  state_ = false;
}

void Pin::Toggle()
{
  if (state_) {
    On();
  }
  else {
    Off();
  }
}
