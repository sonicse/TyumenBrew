#ifndef PIN_H
#define PIN_H

#include "Base.h"

class Pin : public Base
{
public:
  Pin(unsigned char pin);
  
  //Base
  virtual void Setup();
  
  virtual void On();
  virtual void Off();
  virtual void Toggle();
  
  boolean GetState() const;
  
protected:
  unsigned char pin_;
  boolean state_;
};

#endif //PIN_H
