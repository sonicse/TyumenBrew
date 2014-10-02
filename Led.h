#ifndef LED_H
#define LED_H

#include "Pin.h"

class Led : public Pin
{
public:
  Led(unsigned char pin) : Pin(pin) {};
  
  //void Blink();
  
private:
};

#endif //LED_H
