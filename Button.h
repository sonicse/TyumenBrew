#ifndef BUTTON_H
#define BUTTON_H
 
class Button
{
public:
  Button(unsigned char pin) :pin_(pin) {};

  void Setup();
  bool IsPressed (int time);
  
private:
  unsigned char pin_;
};

#endif //BUTTON_H
