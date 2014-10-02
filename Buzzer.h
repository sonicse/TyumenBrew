#ifndef BUZZER_H
#define BUZZER_H

#include "Pin.h"

class Buzzer : public Pin
{
public:
  Buzzer(unsigned char pin) : Pin(pin) {};
  
  void Buzz(unsigned char beep_count, int time);
  void Click();
  
  void Test();
  
private:
};

#endif //BUZZER_H
