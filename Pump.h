#ifndef PUMP_H
#define PUMP_H

class Led;

class Pump : public Pin
{
public:
  Pump(unsigned char pin, Led *led = NULL);
  
  void SetLed(Led *led);
  
  void On();
  void Off();
  
private:
  Led *led_;
};

#endif
