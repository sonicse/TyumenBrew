#ifndef BASE_H
#define BASE_H

class Base
{
  public:
  virtual ~Base() {};
  
  virtual void Setup() {};
  virtual void Loop() {};
};

class State
{
public:
  State(boolean state = false);
  virtual ~State() {};

  boolean GetState() const;
  void SetState(boolean state);

  void On();
  void Off();
  void Toggle();
  
protected:
  virtual void OnStateChanged() {};

  boolean state_;
};



#endif
