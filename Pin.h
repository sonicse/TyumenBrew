#ifndef PIN_H
#define PIN_H

#include "Base.h"

class Led;

class Pin : public Base, public State
{
public:
  Pin(unsigned char pin);
  
  //Base
  virtual void Setup();
  
protected:
  unsigned char pin_;
  
  //State
  virtual void OnStateChanged();
};

class PinLed : public Pin
{
public:
  PinLed(unsigned char pin, Led *led = NULL);

  void SetLed(Led *led);

protected:
  virtual void OnStateChanged();
  
  Led *led_;
};

#endif //PIN_H
