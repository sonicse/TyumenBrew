#ifndef PIN_H
#define PIN_H

class Pin
{
public:
  Pin(unsigned char pin);
  virtual ~Pin() {};
  
  virtual void Setup();
  
  virtual void On();
  virtual void Off();
  virtual void Toggle();
  
protected:
  unsigned char pin_;
  boolean state_;
};

#endif //PIN_H
