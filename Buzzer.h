#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
public:
  Buzzer(unsigned char pin) :pin_(pin) {};
  
  void Setup();
  void Buzz(unsigned char beep_count, int time);
  void Click();
  
  void Test();
  
private:
  unsigned char pin_;
};

#endif //BUZZER_H
