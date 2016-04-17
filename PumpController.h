#ifndef PUMPCONTROLLER_H
#define PUMPCONTROLLER_H

class PumpController : public Base, public State
{
public:
  PumpController(Pin &pump, Pin &heater_big, Pin &heater_small);
  
  void Prepare();
  unsigned long GetTime() const;
  
  /*Base*/
  virtual void Setup();
  virtual void Loop();
  
private:
  virtual void OnStateChanged();
  
  Pin &pump_;
  Pin &heater_big_;
  Pin &heater_small_;
  
  unsigned long time_start_;
};

#endif
