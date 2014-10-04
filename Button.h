#ifndef BUTTON_H
#define BUTTON_H

#include "Base.h"

class Button : public Base
{
public:
  Button(unsigned char pin) :pin_(pin) {};

  void Setup();
  bool IsPressed (int time);
  
private:
  unsigned char pin_;
};

#endif //BUTTON_H
