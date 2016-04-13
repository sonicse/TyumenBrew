#ifndef BASE_H
#define BASE_H

class Base
{
  public:
  virtual ~Base() {};
  
  virtual void Setup() {};
  virtual void Loop() {};
};

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

#endif
